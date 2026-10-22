// Castlevania: SotN Xbox 360 Randomizer
// By: MottZilla
// xb_rando.h

extern int XB_RandomizeRelicLocations;
extern int XB_RandomizeEquipment;
extern int XB_RandomizeDrops;
extern int XB_RandomizeShop;
extern int XB_BoostDropRates;
extern int XB_ClockStatue;
extern int XB_UseRandomStartingGear;
extern int XB_FastWarps;
extern int XB_AntiFreeze;
extern int XB_CandleRando;
extern int XB_EnableMapTracker;
extern int XB_ForceNoComplexity;
extern int XB_ChosenComplexity;
extern int XB_AbortSignal;
extern int XB_ThreadStatus;
extern char XB_PresetName[64];
extern char XB_ItemNames[][32];

int XB_Randomize(char *XEX_Path,unsigned int InitialSeed);
