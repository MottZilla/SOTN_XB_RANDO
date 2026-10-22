// Castlevania: SotN Xbox 360 Randomizer
// By: MottZilla
// main.cpp
//
// This is the Windows Main & GUI module
// Note: Link "/lib32/libcomdlg32.a"
/*

You may not use this code for any commercial purposes or for any monetary gain. 
You must provide source code for any project that includes this code or any derivative of this code.
You must link back to the repo at https://github.com/MottZilla/SOTN_XB_RANDO in your program or documentation for the program.
Or is the repo becomes unavailable mentioning me (MottZilla) in your program or documentation to give credit for the code.
Thank you.

*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "xb_rando.h"

//#define SHOW_CONSOLE 1

extern void XB_CreatePPF(char *FilePath,char *OrgFileName);

char sEXEPath[4096];
char sHelpText[] = "https://github.com/MottZilla/SOTN_XB_RANDO\n\nUse decrypted/decompressed XEX file. English/North American Version and unpatched.";
char sXEXFilePath[4096];
char sXEXFilePathOutput[4096];
char sLog[0x8000] = "";
char sSeedName[256] = "";
int SeedNumber;
int PostGenPPF = 0;

char sLastPresetDesc[64];	// Buffer for knowing when the Log should be updated with new Preset Description.

HWND PrimaryHwnd;
HWND bt_XEX,bt_Randomize,bt_Help,bt_Abort;
HWND bt_PPF,bt_Equipment,bt_Drops,bt_DropRates,bt_Relics,bt_Shop,bt_ClockStatue,bt_StartingGear,bt_FastWarps,bt_AntiFreeze,bt_CandleRando,bt_MapTracker,bt_ForceNoComp;
HWND tb_FilePath,tb_Log,tb_SeedName;
HWND st_Version,st_Help,st_SeedName,st_Complexity,st_Preset;
HWND cb_Preset,cb_Complexity;
HWND pb_InProgress;
int ProgressTicker = 0;

#define MAX_GUI_OPTIONS 64
HWND GUI_Options[MAX_GUI_OPTIONS];	// Used for sorting buttons.


typedef enum { 
	IDC_XEX = 1500,IDC_FILEPATH,IDC_HELPBUTTON,IDC_HELPTEXT,IDC_VERSIONTEXT,IDC_LOGTEXT,IDC_RANDOMIZE,IDC_FILEPATHOUTPUT_BT,IDC_FILEPATHOUTPUT_TB,IDC_ABORT,
	IDC_PPF,IDC_RELICS,IDC_EQUIPMENT,IDC_DROPS,IDC_DROPRATES,IDC_SHOP,IDC_CLOCKSTATUE,IDC_STARTINGGEAR,IDC_FASTWARPS,IDC_ANTIFREEZE,IDC_CANDLERANDO,IDC_MAPTRACKER,IDC_FORCENOCOMP,
	IDC_COMPLEXITY,
	IDC_PRESET,IDC_NONE
} IDCs;


void SaveConfig()
{
	char FullPath[2048];
	strcpy(FullPath,sEXEPath);strcat(FullPath,"XB.CFG");
	
	int PresetIndex = PresetIndex = SendMessage(cb_Preset,CB_GETCURSEL,0,0);
	FILE *fConfig = fopen(FullPath,"wb");
	printf("Saving %s\n",FullPath);
	if(fConfig == NULL) return;
	
	fputc(PresetIndex,fConfig);
	fputc(XB_RandomizeRelicLocations,fConfig);
	fputc(XB_UseRandomStartingGear,fConfig);
	fputc(XB_RandomizeEquipment,fConfig);
	fputc(XB_RandomizeDrops,fConfig);
	fputc(XB_BoostDropRates,fConfig);
	fputc(XB_RandomizeShop,fConfig);
	fputc(XB_ClockStatue,fConfig);
	fputc(PostGenPPF,fConfig);
	fputc(XB_FastWarps,fConfig);
	fputc(XB_AntiFreeze,fConfig);	
	fputc(XB_CandleRando,fConfig);	
	fputc(XB_EnableMapTracker,fConfig);	
	fputc(XB_ForceNoComplexity,fConfig);	
	
	fclose(fConfig);
}

void LoadConfig()
{
	char FullPath[2048];
	strcpy(FullPath,sEXEPath);strcat(FullPath,"XB.CFG");
		
	int PresetIndex;
	FILE *fConfig = fopen(FullPath,"rb");
	printf("Loading %s\n",FullPath);
	if(fConfig == NULL) return;
	
	PresetIndex = fgetc(fConfig);
	XB_RandomizeRelicLocations = fgetc(fConfig);
	XB_UseRandomStartingGear = fgetc(fConfig);
	XB_RandomizeEquipment = fgetc(fConfig);
	XB_RandomizeDrops = fgetc(fConfig);
	XB_BoostDropRates = fgetc(fConfig);
	XB_RandomizeShop = fgetc(fConfig);
	XB_ClockStatue = fgetc(fConfig);
	PostGenPPF = fgetc(fConfig);
	XB_FastWarps = fgetc(fConfig);
	XB_AntiFreeze = fgetc(fConfig);
	XB_CandleRando = fgetc(fConfig);
	XB_EnableMapTracker = fgetc(fConfig);
	XB_ForceNoComplexity = fgetc(fConfig);
	
	fclose(fConfig);
	
	SendMessage(cb_Preset,CB_SETCURSEL,PresetIndex,0);
	SendMessage(bt_Relics,BM_SETCHECK,XB_RandomizeRelicLocations,0);
	SendMessage(bt_StartingGear,BM_SETCHECK,XB_UseRandomStartingGear,0);
	SendMessage(bt_Equipment,BM_SETCHECK,XB_RandomizeEquipment,0);
	SendMessage(bt_Drops,BM_SETCHECK,XB_RandomizeDrops,0);
	SendMessage(bt_DropRates,BM_SETCHECK,XB_BoostDropRates,0);
	SendMessage(bt_Shop,BM_SETCHECK,XB_RandomizeShop,0);
	SendMessage(bt_ClockStatue,BM_SETCHECK,XB_ClockStatue,0);
	SendMessage(bt_PPF,BM_SETCHECK,PostGenPPF,0);
	SendMessage(bt_FastWarps,BM_SETCHECK,XB_FastWarps,0);
	SendMessage(bt_AntiFreeze,BM_SETCHECK,XB_AntiFreeze,0);
	SendMessage(bt_CandleRando,BM_SETCHECK,XB_CandleRando,0);
	SendMessage(bt_MapTracker,BM_SETCHECK,XB_EnableMapTracker,0);
	SendMessage(bt_ForceNoComp,BM_SETCHECK,XB_ForceNoComplexity,0);
}

// Remove Last Message From Log
void LogScratch()
{
	int t = strlen(sLog) - 3;
	
	while(t>0)
	{
		if(sLog[t] == 0xA) {
			sLog[t+1] = 0;
			sLog[t+2] = 0;
			break;
		}
		t--;
	}
}

void LogMsg(char *sMsg)
{
	strcat(sLog,sMsg);
	strcat(sLog,"\r\n");
	SetWindowText(tb_Log,sLog);
	SendMessage(tb_Log,WM_VSCROLL,SB_BOTTOM,NULL);	// Do this to Scroll to End of String.
}

// Bundle all error output stuff together
void ThrowError(char *ErrorString,int Outputs)
{
	if(Outputs&1)	{	printf(ErrorString);printf("\n");	}
	if(Outputs&2)	{	LogMsg(ErrorString);	}
	if(Outputs&4)	{	MessageBox(NULL, ErrorString,"Error!",MB_ICONEXCLAMATION|MB_OK);	}
}

void RandomSeedName()
{
	time_t t;
	char WordA[64],WordB[64],WordC[64];
	char NameOut[255];
	char sNumber[10];
	
	srand(time(&t));
	
	strcpy(NameOut,XB_ItemNames[rand()%256]);
	strcat(NameOut," ");
	strcat(NameOut,XB_ItemNames[rand()%256]);
	itoa(rand()%1000,sNumber,10);strcat(NameOut,sNumber);
	
	SetWindowText(tb_SeedName,NameOut);
}

void SeedStringToNumber()
{
	int Col,Pos;
	GetWindowText(tb_SeedName,sSeedName,255);
	
	Col = Pos = SeedNumber = 0;
	while(Pos<strlen(sSeedName))
	{
		SeedNumber = SeedNumber + (sSeedName[Pos] << ((Col&3)*8) );
		Pos++;Col++;
	}
	// Debug Force Seed Number
	// SeedNumber = 0x385d774d;
	printf("Seed Name:%s\nSeed Number:%X\n",sSeedName,SeedNumber);
}

int CopyXEX()
{
	FILE *fIn;
	FILE *fOut;
	int FileSize;
	unsigned char *DataChunk;
	
	// Allocate some memory.
	DataChunk = (unsigned char*)malloc(0x4000);
	if(DataChunk==NULL)
	{
		ThrowError("Couldn't allocate memory!",7);
		return 0;
	}
	
	// Open the Vanilla XEX
	fIn = fopen(sXEXFilePath,"rb");
	if(fIn==NULL)
	{
		ThrowError("Couldn't open XEX for reading!",7);
		free(DataChunk);
		return 0;
	}
	
	// Open file handle for Rando.XEX
	fOut = fopen(sXEXFilePathOutput,"w+b");
	if(fOut==NULL)
	{
		ThrowError("Couldn't open Rando.XEX for writing!",7);
		free(DataChunk);
		fclose(fIn);
		return 0;
	}
	
	// Memory is allocated, both file handles are open. Time to copy.
	fseek(fIn,0,SEEK_END);	FileSize = ftell(fIn);	fseek(fIn,0,SEEK_SET);	// Get File Size (should be 0xE84000)
	
	while(ftell(fOut)<FileSize)
	{
		fread(DataChunk,0x4000,1,fIn);
		fwrite(DataChunk,0x4000,1,fOut);
	}
	
	fclose(fIn);
	fclose(fOut);
	
	ThrowError("Vanilla XEX copied to Rando.XEX successfully.",3);
	return 1;
}

void SetOutputPath()
{
	int str_s;
	
	strcpy(sXEXFilePathOutput,sXEXFilePath);
	str_s = strlen(sXEXFilePathOutput);str_s--;
	while(1)
	{
		if(sXEXFilePathOutput[str_s] == '\\')
		{
			sXEXFilePathOutput[str_s+1] = 0;
			break;
		}
		str_s--;
		if(str_s<1)
			break;
	}
	strcat(sXEXFilePathOutput,"Rando.xex");
}

void GetEXEPath()
{
	int str_s;
	
	strcpy(sXEXFilePath,"");strcpy(sXEXFilePathOutput,"");
	GetModuleFileName(NULL, sEXEPath, MAX_PATH);	// Get the path to the EXE.
	str_s = strlen(sEXEPath);str_s--;
	while(1)
	{
		if(sEXEPath[str_s] == '\\')
		{
			sEXEPath[str_s+1] = 0;
			break;
		}
		str_s--;
		if(str_s<1)
			break;
	}	
}

void SelectXEX()
{
	OPENFILENAME ofn;
	ZeroMemory( &sXEXFilePath, sizeof( sXEXFilePath ) );
	ZeroMemory( &ofn,      sizeof( ofn ) );
	ofn.lStructSize  = sizeof( ofn );
	ofn.hwndOwner    = NULL;  // If you have a window to center over, put its HANDLE here
	ofn.lpstrFilter  = "XEX\0*.XEX\0Any File\0*.*\0";
	ofn.lpstrFile    = sXEXFilePath;
	ofn.nMaxFile     = MAX_PATH;

	ofn.lpstrTitle   = "Select original AKA vanilla default & decrypted XEX file..";

	ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
		
	GetOpenFileNameA( &ofn );
}

unsigned int Read_u32_be(FILE *fIn)
{
	unsigned int tu32 = 0;
	
	tu32 |= (fgetc(fIn)<<24);
	tu32 |= (fgetc(fIn)<<16);
	tu32 |= (fgetc(fIn)<<8);
	tu32 |= (fgetc(fIn));
	return tu32;
}

int VerifyXEX()
{
	FILE *fIn = fopen(sXEXFilePath,"rb");
	unsigned int TWord;
	
	if(fIn==NULL)
	{
		MessageBox(NULL, "Could not open file for reading!","Error!",MB_ICONEXCLAMATION|MB_OK);
		printf("Could not open file for reading!\n");
		LogMsg("Could not open file for reading!");
		return 0;
	}

	// Header Check
	TWord = Read_u32_be(fIn);
	
	if(TWord!=0x58455832)
	{
		fclose(fIn);
		MessageBox(NULL, "Invalid XEX File!","Error!",MB_ICONEXCLAMATION|MB_OK);
		printf("Invalid XEX File!\n%X\n",TWord);
		LogMsg("Invalid XEX File!");
		return 0;
	}

	// Decrypted Check
	fseek(fIn,0x4000,SEEK_SET);	TWord = Read_u32_be(fIn);
	if(TWord!=0x4D5A9000)
	{
		MessageBox(NULL, "XEX File probably needs to be decrypted!","Error!",MB_ICONEXCLAMATION|MB_OK);
		printf("XEX File probably needs to be decrypted!\n");
		LogMsg("XEX File probably needs to be decrypted!");	
		fclose(fIn);
		return 0;	
	}
	
	// Magic Word Check
	fseek(fIn,0x112,SEEK_SET);
	TWord = Read_u32_be(fIn);
	
	if(TWord!=0x1C9C0121)
	{
		MessageBox(NULL, "XEX File doesn't appear to be correct version. Use decrypted unpatched english version. CRC32: F9B37FB1","Error!",MB_ICONEXCLAMATION|MB_OK);
		printf("XEX File doesn't appear to be correct version. Use decrypted USA XBLA version. CRC32: F9B37FB1\n");
		LogMsg("XEX File doesn't appear to be correct version. Use decrypted unpatched english version. CRC32: F9B37FB1");
		fclose(fIn);
		return 0;
	}
	
	// Check PE Header TimeDate Stamp Value
	fseek(fIn,0x4110,SEEK_SET);
	TWord = Read_u32_be(fIn);
	
	if(TWord!=0x5DAEED45)
	{
		MessageBox(NULL, "XEX File doesn't appear to be correct version. Use decrypted unpatched english version. CRC32: F9B37FB1","Error!",MB_ICONEXCLAMATION|MB_OK);
		printf("XEX File doesn't appear to be correct version. Use decrypted USA XBLA version. CRC32: F9B37FB1\n");
		LogMsg("XEX File doesn't appear to be correct version. Use decrypted unpatched english version. CRC32: F9B37FB1");
		fclose(fIn);
		return 0;
	}

	
	LogMsg("XEX Verify passed!");
	fclose(fIn);
	SetOutputPath();
	return 1;
}

void DoMessages()
{
	MSG msg;
	int LC = 4;
	while(LC > 0) { // If no error is received... //
		//GetMessage(&msg, NULL, 0, 0);					// This function is blocking.
		if(PeekMessage(&msg, NULL, 0, 0,PM_REMOVE) > 0)
		{
			TranslateMessage(&msg); // Translate key codes to chars if present //
			DispatchMessage(&msg); // Send it to WndProc //			
		}

		LC--;
	}
}

void SyncGUI_OptionsToXB()
{
	int PresetIndex;
	char PresetNameBuffer[64];
	// Init Options to Zero
	PostGenPPF = XB_RandomizeRelicLocations = XB_RandomizeEquipment = XB_RandomizeDrops = XB_BoostDropRates = XB_RandomizeShop = XB_ClockStatue = XB_UseRandomStartingGear = XB_FastWarps = XB_AntiFreeze = XB_CandleRando = XB_EnableMapTracker = XB_ForceNoComplexity = 0;
	
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_PPF)==BST_CHECKED) PostGenPPF = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_RELICS)==BST_CHECKED) XB_RandomizeRelicLocations = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_EQUIPMENT)==BST_CHECKED) XB_RandomizeEquipment = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_DROPS)==BST_CHECKED) XB_RandomizeDrops = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_DROPRATES)==BST_CHECKED) XB_BoostDropRates = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_SHOP)==BST_CHECKED) XB_RandomizeShop = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_CLOCKSTATUE)==BST_CHECKED) XB_ClockStatue = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_STARTINGGEAR)==BST_CHECKED) XB_UseRandomStartingGear = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_FASTWARPS)==BST_CHECKED) XB_FastWarps = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_ANTIFREEZE)==BST_CHECKED) XB_AntiFreeze = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_CANDLERANDO)==BST_CHECKED) XB_CandleRando = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_MAPTRACKER)==BST_CHECKED) XB_EnableMapTracker = 1;
	if(IsDlgButtonChecked(PrimaryHwnd,IDC_FORCENOCOMP)==BST_CHECKED) XB_ForceNoComplexity = 1;

	XB_ChosenComplexity = SendMessage(cb_Complexity,CB_GETCURSEL,0,0);	XB_ChosenComplexity++;
	PresetIndex = SendMessage(cb_Preset,CB_GETCURSEL,0,0);
	SendMessage(cb_Preset,CB_GETLBTEXT,PresetIndex,(LPARAM)PresetNameBuffer);
	strcpy(XB_PresetName,PresetNameBuffer);	
}

void ClearGUIButtonList()
{
	for(int i=0;i<MAX_GUI_OPTIONS;i++)
	{
		GUI_Options[i] = NULL;
	}
}

void AddGUIButtonToList(HWND Handle)
{
	int i = 0;
	
	while(1)
	{
		if(GUI_Options[i] == NULL)
			break;
		if(i>=MAX_GUI_OPTIONS)
		{
			printf("GUI Button Sorting Array is full!\n");
			return;
			break;	
		}
		i++;
	}
	GUI_Options[i] = Handle;
}

void PopulateGUIButtonList(int Mode)
{
    AddGUIButtonToList(bt_PPF);
    if(Mode == 0)
    {
	    AddGUIButtonToList(bt_Relics);
	    AddGUIButtonToList(bt_StartingGear);
	    AddGUIButtonToList(bt_Equipment);
	    AddGUIButtonToList(bt_Shop);
		AddGUIButtonToList(bt_Drops);
	    AddGUIButtonToList(bt_CandleRando);    	
	}

    AddGUIButtonToList(bt_ForceNoComp);
    AddGUIButtonToList(bt_MapTracker);
    
    AddGUIButtonToList(bt_ClockStatue);
    AddGUIButtonToList(bt_DropRates);
    AddGUIButtonToList(bt_FastWarps);
    AddGUIButtonToList(bt_AntiFreeze);
}

void ShowMinimumComplexity(int Mode)
{
	int ModeSet;
	
	if(Mode == 0)
		ModeSet = SW_HIDE;
	if(Mode == 1)
		ModeSet = SW_SHOW;
		
	ShowWindow(cb_Complexity,ModeSet);
	ShowWindow(st_Complexity,ModeSet);
}

void HideGUIOptions()
{
	int Option = 0;
	
	while(1)
	{
		if(GUI_Options[Option] == NULL || Option >= MAX_GUI_OPTIONS)
			break;
		MoveWindow(GUI_Options[Option],1200,0,230,30,true);
		Option++;
	}
}

void SortGUIOptions()
{
	int Option = 0;
	const int BaseX = 10;
	const int BaseY = 132;
	const int ButtonsPerCol = 7;
	int DX,DY;
	const int VerticalCutOff = BaseY + (ButtonsPerCol * 32) - 10;
	const int ButtonWidth = 230;
	
	DX = BaseX;
	DY = BaseY;
	
	while(1)
	{
		if(GUI_Options[Option] == NULL || Option >= MAX_GUI_OPTIONS)
			break;
		MoveWindow(GUI_Options[Option],DX,DY,ButtonWidth,30,true);
		
		DY = DY + 32;
		if(DY > VerticalCutOff)
		{
			DY = BaseY;
			DX = DX + ButtonWidth + 2;
		}
		Option++;
	}
}

void KickProgress(int Command)
{
	const char ProgressMessages[4][16] = { "Processing |","Processing /","Processing -","Processing \\" };
	switch(Command)
	{
		case 0:
			ShowWindow(pb_InProgress,SW_HIDE);
			break;
		case 1:
			ShowWindow(pb_InProgress,SW_SHOW);
			break;
		default:
			ProgressTicker++;
			
			SendMessage(pb_InProgress,WM_SETTEXT,0,LPARAM(ProgressMessages[ProgressTicker&3]));
			break;
	}
}

void CreateGUIControls()
{
	HWND hwnd = PrimaryHwnd;
	char sVersion[128];
	int TempX;
	int TempY;

	pb_InProgress = CreateWindow("EDIT",
						"Processing",
						WS_CHILD,
						264, 472, 500, 20,
						hwnd, (HMENU) IDC_NONE, NULL, NULL);

	
	bt_XEX = CreateWindow("BUTTON",
						"Input XEX",
						WS_BORDER | WS_CHILD | WS_VISIBLE,
						10, 0, 100, 30,
						hwnd, (HMENU) IDC_XEX, NULL, NULL);
						
					
	bt_Randomize = CreateWindow("BUTTON",
						"Randomize!",
						WS_BORDER | WS_CHILD | WS_VISIBLE,
						10, 464, 120, 30,
						hwnd, (HMENU) IDC_RANDOMIZE, NULL, NULL);
						

	tb_FilePath = CreateWindow("EDIT",
							"",
							WS_BORDER | WS_CHILD | WS_VISIBLE | ES_READONLY | ES_AUTOHSCROLL,
							10, 34, 610, 24,
							hwnd, (HMENU) IDC_FILEPATH, NULL, NULL);
	
	SetWindowText(tb_FilePath,sEXEPath);
	
	tb_SeedName = CreateWindow("EDIT",
							"Enter Seed Name",
							WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
							94, 65, 300, 24,
							hwnd, (HMENU) IDC_FILEPATH, NULL, NULL);
	
	RandomSeedName();


			
	bt_Help = CreateWindow("BUTTON",
                            "Show Help",
                            WS_BORDER | WS_CHILD | WS_VISIBLE,
                            520, 0, 100, 30,
                            hwnd, (HMENU) IDC_HELPBUTTON, NULL, NULL);
                            
	bt_Abort = CreateWindow("BUTTON",
                            "Abort",
                            WS_BORDER | WS_CHILD | WS_VISIBLE | WS_DISABLED,
                            140, 464, 100, 30,
                            hwnd, (HMENU) IDC_ABORT, NULL, NULL);

	// Unused
	st_Help = CreateWindow("EDIT",
				sHelpText,
				WS_BORDER | WS_CHILD | WS_VSCROLL | ES_READONLY | ES_MULTILINE,
				4,32,622,730,
				hwnd, (HMENU) IDC_HELPTEXT, NULL, NULL);

	st_SeedName = CreateWindow("EDIT",
				"Seed Name",
				WS_BORDER | WS_CHILD | ES_READONLY | WS_VISIBLE,
				10,65,80,24,
				hwnd, (HMENU) IDC_NONE, NULL, NULL);

	st_Preset = CreateWindow("EDIT",
				"Preset / Mode",
				WS_BORDER | WS_CHILD | ES_READONLY | WS_VISIBLE,
				10,100,100,24,
				hwnd, (HMENU) IDC_NONE, NULL, NULL);
				
	st_Complexity = CreateWindow("EDIT",
				"Minimum Complexity",
				WS_BORDER | WS_CHILD | ES_READONLY | WS_VISIBLE,
				270,100,150,24,
				hwnd, (HMENU) IDC_NONE, NULL, NULL);

	strcpy(sVersion,"Build:  ");
#ifdef BETAVERSION
strcpy(sVersion,"BETA:  ");
#endif
	strcat(sVersion,__DATE__);strcat(sVersion," - ");strcat(sVersion,__TIME__);
	st_Version = CreateWindow("STATIC",
				sVersion,
				WS_CHILD | WS_VISIBLE | SS_SUNKEN,
				150,4,220,18,
				hwnd, (HMENU) IDC_VERSIONTEXT, NULL, NULL);

	// Text Box multi-line for showing a log of actions.
    tb_Log = CreateWindow("EDIT",
							"",
							WS_BORDER | WS_VSCROLL | WS_CHILD | WS_VISIBLE | ES_READONLY | ES_MULTILINE | ES_AUTOVSCROLL,
							10, 500, 610, 260,
							hwnd, (HMENU) IDC_LOGTEXT, NULL, NULL);			

	cb_Complexity = CreateWindow("COMBOBOX",
                            "",
                            CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE | WS_VSCROLL,
                            425, 100, 40, 250,
                            hwnd, (HMENU) IDC_COMPLEXITY, NULL, NULL);
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"1");
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"2");
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"3");
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"4"); 
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"5");
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"6");
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"7"); 
    SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"8");
    //SendMessage(cb_Complexity,CB_ADDSTRING,NULL,(LPARAM)"9");
    SendMessage(cb_Complexity,CB_SETCURSEL,0,NULL);
    
	TempY = 2100;
	TempX = 10;
	cb_Preset = CreateWindow("COMBOBOX",
                            "",
                            CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE | WS_VSCROLL,
                            10 + 104, 100, 150, 250,
                            hwnd, (HMENU) IDC_PRESET, NULL, NULL);
    //SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Casual");
    //SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Safe (8)");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Standard");	// Replaces Casual and Safe as they are the same thing with different Min Comp.
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"O.G."); 
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Guarded O.G.");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Lycanthrope");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Nimble"); 
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Warlock");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Bat Master");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Adventure");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Expedition");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Bounty Hunter");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Hitman");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Richter Rando");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Glitch");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"NoLogic");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"NoLogicEq");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"Bingo");
    SendMessage(cb_Preset,CB_ADDSTRING,NULL,(LPARAM)"LegDay");	// Beta
    SendMessage(cb_Preset,CB_SETCURSEL,0,NULL);
    TempY+=32;

	bt_PPF = CreateWindow("BUTTON",
                            "Create PPF",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_PPF, NULL, NULL);
    TempY+=32;
    
	bt_Relics = CreateWindow("BUTTON",
                            "Randomize Relics",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_RELICS, NULL, NULL);
    TempY+=32;

	bt_StartingGear = CreateWindow("BUTTON",
                            "Randomize Starting Gear",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_STARTINGGEAR, NULL, NULL);
    TempY+=32;
    
	bt_Equipment = CreateWindow("BUTTON",
                            "Randomize Equipment Pickups",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_EQUIPMENT, NULL, NULL);
    TempY+=32;
    
	bt_Drops = CreateWindow("BUTTON",
                            "Randomize Enemy Drops",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_DROPS, NULL, NULL);
    TempY+=32;
    
	bt_DropRates = CreateWindow("BUTTON",
                            "Boost Enemy Drops",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_DROPRATES, NULL, NULL);
    TempY+=32;
    
	bt_Shop = CreateWindow("BUTTON",
                            "Randomize Shop Items",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_SHOP, NULL, NULL);
    TempY+=32;
    
	bt_ClockStatue = CreateWindow("BUTTON",
                            "Remove Clock Statue",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_CLOCKSTATUE, NULL, NULL);
    TempY+=32;
    
	bt_FastWarps = CreateWindow("BUTTON",
                            "Fast Warps",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_FASTWARPS, NULL, NULL);
    TempY+=32;
    
	bt_AntiFreeze = CreateWindow("BUTTON",
                            "Anti-Freeze",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_ANTIFREEZE, NULL, NULL);
    TempY+=32;

	bt_CandleRando = CreateWindow("BUTTON",
                            "Randomize Candles",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_CANDLERANDO, NULL, NULL);
                            
	bt_MapTracker = CreateWindow("BUTTON",
                            "Map Tracker (In-Game Show Loc)",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_MAPTRACKER, NULL, NULL);
                            
	bt_ForceNoComp = CreateWindow("BUTTON",
                            "Force No Minimum Complexity",
                            WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX | BS_LEFT,
                            TempX, TempY, 230, 30,
                            hwnd, (HMENU) IDC_FORCENOCOMP, NULL, NULL);
 
    ClearGUIButtonList();
    PopulateGUIButtonList(1);
    SortGUIOptions();
    
    // Debug
    //MoveWindow(bt_PPF,100,100,230,30,true);

	LoadConfig();
	
}

void RefreshGUIOptions(int Mode)
{
    ClearGUIButtonList();
    PopulateGUIButtonList(Mode);
    SortGUIOptions();	
}

void SetNormalPresetOptions()
{
	SendMessage(bt_Relics,BM_SETCHECK,1,0);
	SendMessage(bt_StartingGear,BM_SETCHECK,1,0);
	SendMessage(bt_Equipment,BM_SETCHECK,1,0);
	SendMessage(bt_Drops,BM_SETCHECK,1,0);
	SendMessage(bt_Shop,BM_SETCHECK,1,0);
	SendMessage(bt_CandleRando,BM_SETCHECK,1,0);
}

void Show_Preset_Description()
{
	char sCompare[64];
	char sFirstLine[64];
	int PresetIndex;
	
	PresetIndex = SendMessage(cb_Preset,CB_GETCURSEL,0,0);
	SendMessage(cb_Preset,CB_GETLBTEXT,PresetIndex,(LPARAM)sCompare);
	
	if(strcmp(sCompare,sLastPresetDesc)==0)	return;
	
	strcpy(sLastPresetDesc,sCompare);
	strcpy(sLog,"");

	strcpy(sFirstLine,sCompare);
	strcat(sFirstLine," Details:");
	LogMsg(sFirstLine);
	// TODO: Clean this up, make it more structured

	if(strcmp(sLastPresetDesc,"Standard")==0)
	{
		RefreshGUIOptions(0);
		ShowMinimumComplexity(1);
		SendMessage(cb_Complexity,CB_SETCURSEL,5,0);
		LogMsg("Minimum Complexity = User Choice");
		LogMsg("Basic Randomizer.");
		LogMsg("Note: Complexity is not difficulty. It's progression chain length.");
	}

	/*
	if(strcmp(sLastPresetDesc,"Casual")==0)
	{
		RefreshGUIOptions(0);
		ShowMinimumComplexity(1);
		LogMsg("Minimum Complexity = 1");
		LogMsg("Basic Randomizer.");
	}
	
	if(strcmp(sLastPresetDesc,"Safe (8)")==0)
	{
		RefreshGUIOptions(0);
		ShowMinimumComplexity(1);
		LogMsg("Minimum Complexity = 8");
		LogMsg("Basic Randomizer.");
	}
	*/
	
	if(strcmp(sLastPresetDesc,"Lycanthrope")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 8");
		LogMsg("Start with all Wolf Relics. Reduced MP cost for Wolf.");
		LogMsg("Starting Gear: Shield Rod, Shaman Shield, Silver Crown, Brilliant Mail, Blood Cloak, and Mystic Pendant.");
	}
	
	if(strcmp(sLastPresetDesc,"Nimble")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 6");
		LogMsg("Start with Soul of Bat, Gravity Boots, and Leap Stone.");
		LogMsg("Starting Gear: Mana Prism, Buffalo Star, Dragon Helm, Alucard Mail, Twilight Cloak, and Duplicator.");
	}
	
	if(strcmp(sLastPresetDesc,"Warlock")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 6");
		LogMsg("Start with Form of Mist and 99 INT. Spell MP cost greatly reduced.");
		LogMsg("Starting Gear: Wizard Hat, the rest random.");
	}
	
	if(strcmp(sLastPresetDesc,"Bat Master")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("All Bat Abilities upgraded. Bat form can open doors. Pressing Y Cancels Wing Smash. Holding Y moves bat at normal speed.");
		LogMsg("Starting Gear: Random.");
		LogMsg("Designed by: MT_Fun & MottZilla");
	}
	
	if(strcmp(sLastPresetDesc,"LegDay")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 7");
		LogMsg("Infinite Leap Stone jumping. Super Backdash.");
		LogMsg("BETA VERSION! Door behavior incomplete!");
		LogMsg("Starting Gear: Random.");
		LogMsg("Designed by: MT_Fun & MottZilla");
	}
	
	if(strcmp(sLastPresetDesc,"O.G.")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("Basic Randomizer. Gold & Silver Rings, Holy Glasses, and Spikebreaker are in original locations. Relic locations only.");
		LogMsg("Starting Gear: Random.");
	}
	
	if(strcmp(sLastPresetDesc,"Guarded O.G.")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("Basic Randomizer. Gold & Silver Rings, Holy Glasses, and Spikebreaker are in original locations.");
		LogMsg("Starting Gear: Random.");
	}
	
	if(strcmp(sLastPresetDesc,"Adventure")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(1);
		SendMessage(cb_Complexity,CB_SETCURSEL,7,0);
		LogMsg("Minimum Complexity = User Choice. 8 Default.");
		LogMsg("Normal Randomizer with Equipment Location checks. Takes longer to complete.");
		LogMsg("Starting Gear: Random.");
	}
	
	if(strcmp(sLastPresetDesc,"Expedition")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 7");
		LogMsg("Start with Soul of Bat, Gravity Boots, and Leap Stone.");
		LogMsg("Starting Gear: Mana Prism, Buffalo Star, Dragon Helm, Alucard Mail, Twilight Cloak, and Duplicator.");
		LogMsg("Equipment Location checks!");
	}
	
	if(strcmp(sLastPresetDesc,"Glitch")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 5");
		LogMsg("This preset requires the use of different Glitches to complete. This includes Shift Lines, Reverse Shift Lines, Fire Boomerang Jumps, and more. The logic is similar to the current PSX randomizer's Glitch preset.");
		LogMsg("Starting Gear: Random + Fire Boomerang & Library Card.");
		LogMsg("Equipment Location checks!");
	}
	
	if(strcmp(sLastPresetDesc,"NoLogic")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("Another glitch preset. In this preset you start with Soul of Wolf, Leap Stone, Fire Boomerangs, Axe Lord Armor, Duplicator, Manna Prism, Shield Rod, and Shaman Shield. Relics can be anywhere as there is no location logic.");
		LogMsg("Guarded Location checks!");
	}
	
	if(strcmp(sLastPresetDesc,"NoLogicEq")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("Another glitch preset. In this preset you start with Soul of Wolf, Leap Stone, Fire Boomerangs, Axe Lord Armor, Duplicator, Manna Prism, Shield Rod, and Shaman Shield. Relics can be anywhere as there is no location logic.");
		LogMsg("Equipment Location checks!");
	}
	
	if(strcmp(sLastPresetDesc,"Bingo")==0)
	{
		RefreshGUIOptions(0);
		ShowMinimumComplexity(0);
		LogMsg("Vanilla Relics, start with Holy Glasses, no random Library Card or Duplicator drops from enemies. Be aware all check box options other than Randomize Relics still work for Bingo.");
		LogMsg("For Bingo Board Play Only.");
	}

	if(strcmp(sLastPresetDesc,"Bounty Hunter")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 5");
		LogMsg("The 5 Vlad relics are dropped from 5 randomly picked enemies. You must find the 5 Familiar Cards to find out which 5 enemies you need to defeat to get each Vlad relic.");
		LogMsg("Starting Gear: Alucart Sword, Shield, Mail, Dragon Helm, Twilight Cloak, Ring of Arcana");
	}
	
	if(strcmp(sLastPresetDesc,"Hitman")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(0);
		SetNormalPresetOptions();
		LogMsg("Minimum Complexity = 1");
		LogMsg("This is mostly the same as Bounty Hunter except you start with all 5 cards and the drop rate on the Vlad relics is increased. When generating these seeds you will see the names of the 5 targets as well.");
		LogMsg("Starting Gear: Alucart Sword, Shield, Mail, Dragon Helm, Twilight Cloak, Ring of Arcana");
	}

	if(strcmp(sLastPresetDesc,"Richter Rando")==0)
	{
		RefreshGUIOptions(1);
		ShowMinimumComplexity(1);
		//SetNormalPresetOptions();
		SendMessage(cb_Complexity,CB_SETCURSEL,5,0);
		LogMsg("Minimum Complexity = User Choice. 6 Default & Max.");
		LogMsg("Play randomizer as Richter. You must find Holy Glasses and all 5 Vlads to reach the end. Richter can make use of certain relics to progress or power up. He can also use Food, Library Cards, and Life Apples.");
		LogMsg("Quick Tips:");
		LogMsg("Library Card Teleport with Faerie Scroll or Library Card.");
		LogMsg("Hold LB+RB and Press B.");
		LogMsg("Use Food by holding Up and Pressing RT.");
		LogMsg("See READTHIS.TXT for more info.");
	}
		
	LogMsg("---");	
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {	
	switch(Message) {
		
	    case WM_CREATE:
	        break;
		
		case WM_COMMAND: {
			if(LOWORD(wParam) == IDC_HELPBUTTON) {
				MessageBox(NULL, sHelpText,"SotN Xbox Randomizer By: MottZilla",MB_ICONEXCLAMATION|MB_OK);
			}

			if(LOWORD(wParam) == IDC_PRESET) {
				Show_Preset_Description();
			}
			
			if(LOWORD(wParam) == IDC_XEX) {
				SelectXEX();
				VerifyXEX();
				SetWindowText(tb_FilePath,sXEXFilePath);
				SendMessage(tb_FilePath,EM_SETSEL,strlen(sXEXFilePath),strlen(sXEXFilePath));
			}

			if(LOWORD(wParam) == IDC_ABORT) {
				XB_AbortSignal = 1;
			}
			
			if(LOWORD(wParam) == IDC_RANDOMIZE) {
				if(XB_ThreadStatus == 0 && CopyXEX())
				{
					SeedStringToNumber();
					SyncGUI_OptionsToXB();
					SaveConfig();
					EnableWindow(bt_Abort,1);
					if(XB_Randomize(sXEXFilePathOutput,SeedNumber))
					{
						LogMsg("XB_Randomize() completed successfully.");
						if(PostGenPPF)
						{
							//printf("%s\n%s\n",sXEXFilePathOutput,sXEXFilePath);
							XB_CreatePPF(sXEXFilePathOutput,sXEXFilePath);
						}
					}
					else
					{
						LogMsg("XB_Randomize() Error! =(");
					}
					EnableWindow(bt_Abort,0);
				}
			}

			break;
		}


		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			XB_AbortSignal = 1;
#ifdef SHOW_CONSOLE
			FreeConsole();
#endif
			PostQuitMessage(0);
			break;
		}

        // Process other messages.
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	
	// Create Console Window
#ifdef SHOW_CONSOLE
	if(AllocConsole() == 0)
	{
			MessageBox(NULL, "Console Create Failed","Error!",MB_ICONEXCLAMATION|MB_OK);
	}

	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stderr);
	freopen("CONOUT$", "w", stdout);
#endif

	// End of Console Creation for Private Builds

	GetEXEPath();

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","SotN Xbox Randomizer - By MottZilla",WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE,//|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		800, /* height */
		NULL,NULL,hInstance,NULL);


	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	PrimaryHwnd = hwnd;
	
	// Create All Window Controls.
	CreateGUIControls();

	// For Preset Description Updating
	strcpy(sLastPresetDesc,"");

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

