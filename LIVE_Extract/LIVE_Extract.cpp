// main.cpp
// LIVE Extract
// Program to Extract Files from a Xbox 360 LIVE Container
// By: MottZilla
/*
	This was created to extract the files from Castlevania: Symphony of the Night for use with the Randomizer I created.
	The program should handle the container for SotN but may not do well with other games as that was not the point of this program.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LIVE_File {
	char Name[32];
	int Offset;
	int BlockNum;
	int Size;
	int Folder;
};

#define LIVE_FILEMAX 1024

// Globals
FILE *fLIVE;
LIVE_File FileTree[LIVE_FILEMAX];
char InputPath[2048];

// For Castlevania SotN XEX Decryption
unsigned char SOTN_XEX[0xE84000];
unsigned char SOTN_XOR[0xE84000];

// Function Prototypes
void LIVE_InitializeFileTree();
void LIVE_ReadFileList();
void LIVE_ExtractFile(int FN);
void LIVE_ExtractFiles();
int LIVE_HeaderCheck();
void LIVE_PrintTitle();
unsigned int LIVE_Read_u16_be();
unsigned int LIVE_Read_u32_be();
unsigned int LIVE_Read_u32_le();
int LIVE_GetBlockOffset(int BlockNumber,int ID);

// This function detects the SotN XEX File and will decrypt it using XOR Table.
void SOTN_Decrypt()
{
	char FullPath[4096];
	char OpenPath[4096];
	FILE *fSOTN_XEX;
	FILE *fSOTN_XOR;
	int FileSize;
	int Temp;
	unsigned int Checksum = 0;
	unsigned int *CSData = (unsigned int *)&SOTN_XEX[0];
	
	const unsigned int CS_SOTN_FULL = 0xAEC1F617;		// 32-bit Add Checksums
	const unsigned int CS_SOTN_HALFA = 0x08E03DB7;
	const unsigned int CS_SOTN_HALFB = 0xA5E1B860;
	
	//printf("SotN Decrypt Start..\n");	// DEBUG

	// Path Building
	strcpy(FullPath,InputPath);
	Temp = strlen(FullPath) - 1;
	
	while(Temp>0)
	{
		if(FullPath[Temp] == 0x5C)
		{
			FullPath[Temp+1] = 0;
			break;
		}
		Temp--;
	}
	
	// Open the default.xex we have extracted.
	strcpy(OpenPath,FullPath);
	strcat(OpenPath,"default.xex");
	
	fSOTN_XEX = fopen(OpenPath,"rb");
	if(fSOTN_XEX == NULL)
	{
		//printf("Couldn't open %s\n",OpenPath);
		return;
	}
	
	//printf("Opened %s\n",OpenPath);	// DEBUG
	
	// File Size Check
	fseek(fSOTN_XEX,0,SEEK_END);	FileSize = ftell(fSOTN_XEX);	fseek(fSOTN_XEX,0,SEEK_SET);
	if(FileSize != 0xE84000)
	{
		//printf("File Size wrong!\n");
		fclose(fSOTN_XEX);
		return;
	}
	
	fread(&SOTN_XEX[0],0xE84000,1,fSOTN_XEX);		// Read File into Memory
	fclose(fSOTN_XEX);
	
	//printf("XEX is loaded into Memory.\n",OpenPath);	// DEBUG
	
	for(int i=0;i<0x3A1000;i++)		// Calculate FULL Checksum
	{
		Checksum = Checksum + CSData[i];
	}
	
	Checksum &= 0xFFFFFFFF;	// Mask for 32-bit Size.
	if(Checksum != CS_SOTN_FULL) return;	// If Checksum doesn't match we're done.
	
	Checksum = 0;
	for(int i=0;i<0x1D0800;i++)
	{
		Checksum = Checksum + CSData[i];
	}
	
	Checksum &= 0xFFFFFFFF;	// Mask for 32-bit Size.
	if(Checksum != CS_SOTN_HALFA) return;	// If Checksum doesn't match we're done.
	
	Checksum = 0;
	for(int i=0;i<0x1D0800;i++)
	{
		Checksum = Checksum + CSData[0x1D0800+i];
	}
	
	Checksum &= 0xFFFFFFFF;	// Mask for 32-bit Size.
	if(Checksum != CS_SOTN_HALFB) return;	// If Checksum doesn't match we're done.
	
	//printf("All Checksums OK!\n");	// DEBUG
	printf("\nSotN XEX Detected..\n");	// DEBUG
	
	// If all 3 Checksums matched..
	strcpy(OpenPath,FullPath);
	strcat(OpenPath,"decrypt.xor");
	
	fSOTN_XOR = fopen(OpenPath,"rb");
	if(fSOTN_XOR == NULL)
	{
		printf("Decryption Table [decrypt.xor] couldn't be opened.\nCan't decrypt XEX. Place decrypt.xor in same folder as this program.\n");
		return;	// If Decryption Table not available we're done.
	}
	fread(&SOTN_XOR[0],0xE84000,1,fSOTN_XOR);	// Load Table
	fclose(fSOTN_XOR);
	
	//printf("Opened %s\n",OpenPath);	// DEBUG
	
	// Save Encrypted Default.xex to file.
	strcpy(OpenPath,FullPath);
	strcat(OpenPath,"encrypted_default.xex");
	
	fSOTN_XEX = fopen(OpenPath,"wb");
	fwrite(&SOTN_XEX[0],0xE84000,1,fSOTN_XEX);
	fclose(fSOTN_XEX);
	
	printf("Saved original encrypted XEX to: %s\n",OpenPath);	// DEBUG
	
	for(int i=0;i<0xE84000;i++)
	{
		SOTN_XEX[i] = SOTN_XEX[i] ^ SOTN_XOR[i];
	}
	
	// Save Decrypted Default.xex to file.
	strcpy(OpenPath,FullPath);
	strcat(OpenPath,"default.xex");
	
	fSOTN_XEX = fopen("default.xex","wb");
	fwrite(&SOTN_XEX[0],0xE84000,1,fSOTN_XEX);
	fclose(fSOTN_XEX);
	
	printf("Saved decrypted XEX to: %s\n",OpenPath);	// DEBUG
}

int main(int argc, char **argv)
{
	if(argc>1)	{	printf("LIVE Extract by: MottZilla\n\n",argv[1]);		}
	else		{	printf("You must specify input file. Either drag and drop or type Live_Extract inputfilename\n\n",argv[1]);	return 0;}
	
	fLIVE = fopen(argv[1],"rb");
	if(fLIVE == NULL)	{	printf("Error opening file: %s\n",argv[1]);	return 0;}
	
	if(LIVE_HeaderCheck() == 0) {	printf("Error! %s doesn't appear to be a LIVE container file.'\n\n",argv[1]);	fclose(fLIVE); return 0;	}
	
	strcpy(InputPath,argv[1]);
	
	LIVE_PrintTitle();
	LIVE_InitializeFileTree();
	LIVE_ReadFileList();
	LIVE_ExtractFiles();
	SOTN_Decrypt();
	
	fclose(fLIVE);
	
	printf("\nOperations Complete.\n\n");
	system("pause");
}

int LIVE_GetBlockOffset(int BlockNumber,int ID)
{
	int block_adjust = 0;
	int tblshift = ((ID + 0xFFF) & 0xF000) >> 0xC;
	if(tblshift==0xB)
		tblshift = 1;
	else
		tblshift = 0;
	if(BlockNumber >=0xAA)
		block_adjust = (BlockNumber / 0xAA) + (1<<tblshift);
		
	return ((BlockNumber+block_adjust)*0x1000)+0xC000;
}

void LIVE_ExtractFile(int FN)
{
	char FileSavePath[2048];
	char SubPath[2048];
	char TempPath[2048];
	char TempPathB[2048];
	int Folder;
	FILE *fOut;
	int BytesWritten;
	int CurrentBlock;
	int BlockPos;
	unsigned char TempByte;
	

	if(FileTree[FN].Size == 0)
	{
		return;	// Folder
	}
	
	strcpy(FileSavePath,InputPath);
	strcat(FileSavePath,"\\");
	strcpy(SubPath,"");
	
	Folder = FileTree[FN].Folder;
	while(Folder!=0xFFFF)
	{
		strcpy(TempPath,FileTree[Folder].Name);	// Grab Folder name for this file.
		strcat(TempPath,"\\");
		
		strcpy(TempPathB,SubPath);	// Copy Current Full Path to TPB.
		strcpy(SubPath,TempPath);	// Copy this Folder Path to the Left Side
		strcat(SubPath,TempPathB);	// Add the Right Side on
		
		Folder = FileTree[Folder].Folder;	// Find Next Folder, we are heading to the root!
	}
	
	//printf("%s%s\n",SubPath,FileTree[FN].Name);
	strcpy(FileSavePath,SubPath);
	strcat(FileSavePath,FileTree[FN].Name);
	
	
	// Actually Extract.
	
	fOut = fopen(FileSavePath,"wb");
	if(fOut==NULL)	{	printf("Error writing file: %s\n",FileSavePath); return;	}
	
	BytesWritten = 0;
	CurrentBlock = FileTree[FN].BlockNum;
	while(BytesWritten<FileTree[FN].Size)
	{
		fseek(fLIVE,LIVE_GetBlockOffset(CurrentBlock,FN),SEEK_SET);	// Seek to Start of Block
		BlockPos = 0;
		
		while(BlockPos<0x1000)		// Block Read/Write Loop
		{
			if(BytesWritten<FileTree[FN].Size)	// Stop Reading and writing when end of file is reached.
			{
				TempByte = fgetc(fLIVE);
				fputc(TempByte,fOut);				
			}
			BytesWritten++;
			BlockPos++;		
		}
		
		CurrentBlock++;
	}
	fclose(fOut);
}

void LIVE_CreateFolders(int FN)
{
	char FileSavePath[2048];
	char SubPath[2048];
	char TempPath[2048];
	char TempPathB[2048];
	int Folder;
	int SearchN;
	FILE *fOut;
	unsigned char *DataBlock;
	
	if(FileTree[FN].Size > 0)	{	return;	}	// Ignore if Not Folder

	strcpy(FileSavePath,InputPath);
	strcat(FileSavePath,"\\");
	strcpy(SubPath,"");
	
	Folder = FileTree[FN].Folder;
	while(Folder!=0xFFFF)
	{
		strcpy(TempPath,FileTree[Folder].Name);	// Grab Folder name for this file.
		strcat(TempPath,"\\");
		
		strcpy(TempPathB,SubPath);	// Copy Current Full Path to TPB.
		strcpy(SubPath,TempPath);	// Copy this Folder Path to the Left Side
		strcat(SubPath,TempPathB);	// Add the Right Side on
		
		Folder = FileTree[Folder].Folder;	// Find Next Folder, we are heading to the root!
	}
	
	//printf("%s%s\n",SubPath,FileTree[FN].Name);
	strcpy(FileSavePath,SubPath);
	strcat(FileSavePath,FileTree[FN].Name);
		
	strcpy(TempPath,"mkdir ");
	strcat(TempPath,FileSavePath);
	system(TempPath);
	
	
}

void LIVE_ExtractFiles()
{
	int Folder = 0xFFFF;
	char syscmd[2048];
	
	// Create Folders
	for(int i=0;i<LIVE_FILEMAX;i++)
	{
		if(FileTree[i].Name[0])
			LIVE_CreateFolders(i);		
	}	
	
	// Extract Files
	
	for(int i=0;i<LIVE_FILEMAX;i++)
	{
		if(FileTree[i].Name[0])
			LIVE_ExtractFile(i);		
	}
	

}

void LIVE_ReadFileList()
{
	int FIndex = 0;
	
	while(1)
	{
		fseek(fLIVE,0xC000 + (FIndex * 64),SEEK_SET);
		if(fgetc(fLIVE) == 0) break;
		
		fseek(fLIVE,0xC000 + (FIndex * 64),SEEK_SET);
		fgets(FileTree[FIndex].Name,31,fLIVE);
		fseek(fLIVE,0xC000 + (FIndex * 64) + 0x2F,SEEK_SET);
		FileTree[FIndex].BlockNum = LIVE_Read_u32_le();
		FileTree[FIndex].BlockNum &= 0xFFFFFF;	// actually 24bit.
		//FileTree[FIndex].Offset = 0xC000 + (FileTree[FIndex].Offset<<12);
		//FileTree[FIndex].Offset = 0xC000+(FileTree[FIndex].Offset*0x1000);
		FileTree[FIndex].Offset = LIVE_GetBlockOffset(FileTree[FIndex].BlockNum,FIndex);
		fseek(fLIVE,0xC000 + (FIndex * 64) + 0x32,SEEK_SET);
		FileTree[FIndex].Folder = LIVE_Read_u16_be();
		fseek(fLIVE,0xC000 + (FIndex * 64) + 0x34,SEEK_SET);
		FileTree[FIndex].Size = LIVE_Read_u32_be();
		
		FIndex++;
	}
	
	FIndex = 0;
	while(1)
	{
		//printf("%s Offset: %X\n",FileTree[FIndex].Name,FileTree[FIndex].Offset);
		printf("%24s %16d bytes\n",FileTree[FIndex].Name,FileTree[FIndex].Size);
		FIndex++;
		if(FileTree[FIndex].Offset == 0) break;
	}
}

void LIVE_InitializeFileTree()
{
	for(int i=0;i<LIVE_FILEMAX;i++)	{	FileTree[i].Name[0] = FileTree[i].Offset = FileTree[i].Size = FileTree[i].Folder = 0; }
}

unsigned int LIVE_Read_u32_le()
{
	unsigned int Ret;
	fread(&Ret,1,4,fLIVE);
	return Ret;
}

unsigned int LIVE_Read_u32_be()
{
	unsigned int Ret;
	Ret = (fgetc(fLIVE)<<24);
	Ret = Ret + (fgetc(fLIVE)<<16);
	Ret = Ret + (fgetc(fLIVE)<<8);
	Ret = Ret + fgetc(fLIVE);
	return Ret;
}

unsigned int LIVE_Read_u16_be()
{
	unsigned int Ret;
	Ret = (fgetc(fLIVE)<<8);
	Ret = Ret + fgetc(fLIVE);
	return Ret;
}

void LIVE_PrintTitle()
{
	int ZeroCount = 0;
	char Title[256];
	int TIndex = 0;
	unsigned char RB;
	
	fseek(fLIVE,0x410,SEEK_SET);
	strcpy(Title,"");
	
	while(ZeroCount < 3)
	{
		RB = fgetc(fLIVE);
		if(RB == 0)
		{	ZeroCount++;	}
		else
		{	Title[TIndex] = RB;	TIndex++;	ZeroCount = 0;	}
	}
	Title[TIndex] = 0;	// Terminate String
	printf("Title: %s \n\n",Title);
}

int LIVE_HeaderCheck()	// Check for LIVE text at start of file.
{
	fseek(fLIVE,0,SEEK_SET);
	if(LIVE_Read_u32_le() != 0x4556494C) return 0;
	return 1;
}


