// ppf.c
// Simple PPF Patch Creation
// by: MottZilla

// PPF Patch Generation. Originally from BountyHunter Tool Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void LogMsg(char *sMsg);

struct DIFF {
	unsigned int Offset;	// PPF3 allows for 64-bit Offsets
	unsigned int Length;
	unsigned char *Data;
};

#define MAX_PATCH 1000000
DIFF Patch[MAX_PATCH];	// 1 Million Patches Max

void AddDiff(unsigned int Offset, unsigned int Length, unsigned char *Data)
{
	unsigned int PatchEntry = 0;
	
	// Get a free patch slot.
	while(1)
	{
		if(Patch[PatchEntry].Length == 0)
			break;
		PatchEntry++;
		if(PatchEntry >= MAX_PATCH-1)
		{
			printf("Error! Too many DIFFs! DIFF Count Greater than %d\n",MAX_PATCH);
			break;
		}
	}
	
	Patch[PatchEntry].Offset = Offset;								// Set DIFF Offset in BIN file.
	Patch[PatchEntry].Length = Length;								// Set DIFF Length
	Patch[PatchEntry].Data = (unsigned char *)malloc(Length);		// Allocate Memory for DIFF data.
	for(int i=0;i<Length;i++)
	{
		Patch[PatchEntry].Data[i] = Data[i];
	}
	
	// Debug
	//printf("Offset: %X\n",Offset);
}

void ClearPatchData()
{
	for(int i=0;i<MAX_PATCH;i++)
	{
		if(Patch[i].Data)
		{
			free(Patch[i].Data);			
		}
		
		Patch[i].Data = NULL;
		Patch[i].Length = 0;
		Patch[i].Offset = 0;
	}
}

// Create PPF XBox XEX
void XB_CreatePPF(char *FilePath,char *OrgFileName)
{
	char OrgPath[4096];
	char PPFPath[4096];
	char tbuf[4096];
	unsigned char OrgSector[0x930];
	unsigned char NewSector[0x930];
	FILE *fOrg;
	FILE *fNew;
	FILE *fPPF;
	unsigned int CurrentSector = 0;
	int Diffs;
	int SectorPos;
	int DiffStart;
	int DiffIndex;
	int SectorStop = 0x800;
	
	ClearPatchData();
	
	strcpy(OrgPath,OrgFileName);	

	// Open Original Track 1 BIN
	fOrg = fopen(OrgPath,"rb");
	if(fOrg == NULL)
	{
		printf("Error opening Org: %s\nCreatePPF() Failed.\n",OrgPath);
		LogMsg("Create PPF Failed.");
		return;
	}
	
	// Open Patched Track 1 BIN
	fNew = fopen(FilePath,"rb");
	if(fNew == NULL)
	{
		fclose(fOrg);
		printf("Error opening Rando: %s\nCreatePPF() Failed.\n",FilePath);
		LogMsg("Create PPF Failed.");
		return;
	}
	
	while(1)
	{
		// Read One Raw Sector from both Images
		fread(&OrgSector[0],0x800,1,fOrg);
		fread(&NewSector[0],0x800,1,fNew);
		//printf("Reading Sector %d\n",CurrentSector);
		
		SectorPos = 0x0;	// UMD Sector Start
		Diffs = 0;
		DiffStart = 0;
		while(1)
		{
			// Difference Found.
			if(OrgSector[SectorPos] != NewSector[SectorPos])
			{
				DiffStart = SectorPos;	// Record the Start Point of the Diff.
				Diffs = 0;
				// Find how long the difference is.
				while(1)
				{
					// If Byte is Different Add one to Diff Count and Advance SectorPos
					if(OrgSector[SectorPos] != NewSector[SectorPos])
					{
						Diffs++;
					}
					if(OrgSector[SectorPos] == NewSector[SectorPos] || SectorPos>=SectorStop || Diffs>=255)	// Maximum Length 255.
					{
						AddDiff( (CurrentSector*0x800) + DiffStart, Diffs, &NewSector[DiffStart] );
						break;
					}
					SectorPos++;
					if(SectorPos >= SectorStop)
					{
						AddDiff( (CurrentSector*0x800) + DiffStart, Diffs, &NewSector[DiffStart] );
						break;
					}
				}
			}
			
			SectorPos++;
			if(SectorPos>=SectorStop)
				break;
		}
		
		CurrentSector++;
		//if(CurrentSector>47503)
		if(CurrentSector>0x1D07)	// Changed for Xbox
			break;
		
	}
	
	//printf("PPF Done at CurrentSector: %d\n\n%X\n\n",CurrentSector,CurrentSector*0x930);
	
	fclose(fOrg);
	fclose(fNew);
	
	// Time to Write the PPF File.
	
	// Generate File Path for PPF.
	strcpy(PPFPath,FilePath);
	PPFPath[strlen(PPFPath)-4] = 0;
	strcat(PPFPath,".PPF");
	
	fPPF = fopen(PPFPath,"wb");
	fputs("PPF30",fPPF);
	fputc(0x02,fPPF);
	fputs("SotN Rando                                       ",fPPF);
	fputc(0x00,fPPF);
	
	fputc(0x00,fPPF);	// image type
	fputc(0x00,fPPF);	// Patch validation
	fputc(0x00,fPPF);	// undo data
	fputc(0x00,fPPF);	// reserved
	
	DiffIndex = 0;
	while(1)
	{
		if(Patch[DiffIndex].Length == 0)
			break;
			
		fputc(Patch[DiffIndex].Offset,fPPF);
		fputc(Patch[DiffIndex].Offset>>8,fPPF);
		fputc(Patch[DiffIndex].Offset>>16,fPPF);
		fputc(Patch[DiffIndex].Offset>>24,fPPF);
		fputc(0x00,fPPF);	// Upper 32bits Ignored
		fputc(0x00,fPPF);	// Upper 32bits Ignored
		fputc(0x00,fPPF);	// Upper 32bits Ignored
		fputc(0x00,fPPF);	// Upper 32bits Ignored
		
		fputc(Patch[DiffIndex].Length,fPPF);
		
		for(int i=0;i<Patch[DiffIndex].Length;i++)
		{
			fputc(Patch[DiffIndex].Data[i],fPPF);
		}
		
		DiffIndex++;
	}
	
	fclose(fPPF);
	printf("PPf Generation Complete!\n");
	strcpy(tbuf,"PPF Saved to: ");
	strcat(tbuf,PPFPath);
	LogMsg(tbuf);
	
}
