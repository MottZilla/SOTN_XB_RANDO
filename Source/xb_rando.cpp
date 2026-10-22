// Castlevania: SotN Xbox 360 Randomizer
// By: MottZilla
// xb_rando.cpp
//
// All randomizer functions run through here.
// TODO: Plenty of old commented out code to remove at some point.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <process.h>
#include <windows.h>
#include <time.h>

#include "xb_offsets.h"

// Note: Glitch uses these Items for Progression:
// Heart Refresh 1, Heart Refresh 2, Shield Rod, Fire Boomerang 2 (FB1 is prologue reward), Diamond, Toadstool, Thrust Sword.
// Location Requirements are very very different ofcourse.
//
// Idea for getting around Heart Refresh always spawning when replacing a non-equipment location.
// Change another item into Heart Refresh but with a different Palette or Name to have HR1 and HR2. They would be Non-Consumables
// An active Alucard Frame Update Function would be needed similar to Bat Master to prevent the player from having more than one of each HR, checking if either hand has HR#, and if it does then setting the count in inventory to zero.
// If neither hand has HR#, then it takes that HR# inventory count and ANDs it with 1 to limit it to 1 HR.
// The alternative to this would be to take over Equipment Slots which also would be a pain.

char XB_RandoTitle[64] = "Rando By MottZilla";
char XB_RandoVersion[64] = "V 2026.10.21";			// !! Don't forget to update this !!
char XB_PresetName[64] = "";
char XB_LocationSet[64] = "";

// Log Function
void DoMessages();
void LogMsg(char *sMsg);
void LogScratch();
void KickProgress(int Command);

extern char sSeedName[256];
int SeedName_Index = 0;
int XB_InverseSeedNumber = 0;

// OG Entity Data
unsigned char OG_HOLYGLASSES[10] = 	{ 0x01,0x80,0x02,0x58,0x00,0x17,0x00,0x89,0x00,0x00 };
unsigned char OG_SILVERRING[10] = 	{ 0x00,0xB4,0x00,0xA4,0x00,0x0C,0x01,0x10,0x00,0x02 };
unsigned char OG_GOLDRING[10] = 	{ 0x00,0xB0,0x00,0xA8,0x00,0x5F,0x00,0x10,0x00,0x00 };
unsigned char OG_SPIKEBREAKER[10] = { 0x00,0x2F,0x00,0x99,0x00,0x0C,0x00,0x08,0x00,0x10 };

// Patch Data
unsigned char XB_PATCHCLOCKROOMOPEN[0x38] = { 0x3D,0x60,0x83,0x17,0x39,0x6B,0x49,0x40,0x89,0x4B,0x01,0x17,0x60,0x00,0x00,0x00,0x2B,0x0A,0x00,0x00,0x41,0x9A,0x07,0x9C,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x89,0x6B,0x01,0x18,0x60,0x00,0x00,0x00,0x2B,0x0B,0x00,0x00,0x41,0x9A,0x07,0x84,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00 };

// Location Stuff
typedef enum { 
	RID_NULL, RID_SoulOfBat, RID_EchoOfBat, RID_SoulOfWolf, RID_PowerOfWolf, RID_SkillOfWolf, RID_FormOfMist, RID_PowerOfMist, RID_CubeOfZoe, RID_GravityBoots, RID_LeapStone, RID_HolySymbol, RID_JewelOfOpen, RID_MermanStatue, RID_DemonCard, RID_GoldRing, RID_SilverRing, RID_Spikebreaker, RID_HolyGlasses,
	RID_HeartOfVlad, RID_ToothOfVlad, RID_RibOfVlad, RID_RingOfVlad, RID_EyeOfVlad, RID_Thrust, RID_HR1, RID_HR2, RID_ShieldRod, RID_FB, RID_Toadstool, RID_Diamond, RID_SwordCard, RID_BatCard, RID_GhostCard, RID_FaerieCard, RID_Arcana, RID_Varda,
	RID_Terminate = 0xFF
} XB_ProgressionRelicIDs;

char RID_Strings[][32] = { "None", "Soul of Bat", "Echo of Bat", "Soul of Wolf", "Power of Wolf", "Skill of Wolf", "Form of Mist", "Power of Mist", "Cube of Zoe", "Gravity Boots", "Leap Stone", "Holy Symbol", "Jewel of Open", "Merman Statue", "Demon Card", "Gold Ring", "Silver Ring", "Spikebreaker", "Holy Glasses",
							"Heart of Vlad", "Tooth of Vlad", "Rib of Vlad", "Ring of Vlad", "Eye of Vlad", "Thrust Sword", "Heart Refresh 1", "Heart Refresh 2", "Shield Rod", "Fire Boomerang", "Toadstool", "Diamond", "Sword Card", "Bat Card", "Ghost Card", "Faerie Card", "Ring of Arcana", "Ring of Varda", "Terminate" };

char XB_ItemNames[][32] = { "Empty Hand","Monster Vial 1","Monster Vial 2","Monster Vial 3","Shield Rod","Leather Shield","Knight Shield","Iron Shield","AxeLord Shield","Herald Shield","Dark Shield","Goddess Shield","Shaman Shield","Medusa Shield","Skull Shield","Fire Shield","Alucard Shield","Sword of Dawn","Basilard","Short Sword","Combat Knife","Nunchaku","Were Bane","Rapier","Karma Coin","Magic Missile","Red Rust","Takemitsu","Shotel","Orange","Apple","Banana","Grapes","Strawberry","Pineapple","Peanuts","Toadstool","Shiitake","Cheesecake","Shortcake","Tart","Parfait","Pudding","Ice cream","Frankfurter","Hamburger","Pizza","Cheese","Ham and eggs","Omelette","Morning set","Lunch A","Lunch B","Curry rice","Gyros plate","Spaghetti","Grape juice","Barley tea","Green tea","Natou","Ramen","Miso soup","Sushi","Pork bun","Red bean bun","Chinese bun","Dim Sum set","Pot roast","Sirlion","Turkey","Meal ticket","Neutron bomb","Power of sire","Pentagram","Bat pentagram","Shuriken","Cross shuriken","Buffalo star","Flame star","TNT","Bwaka knife","Boomerang","Javelin","Tyrfing","Namakura","Knuckle duster","Gladius","Scimitar","Cutlass","Saber","Falchion","Broadsword","Bekatowa","Damascus sword","Hunter sword","Estoc","Bastard sword","Jewel knuckles","Claymore","Talwar","Katana","Flamberge","Iron Fist","Zwei hander","Sword of Hador","Luminus","Harper","Obsidian sword","Gram","Jewel sword","Mormegil","Firebrand","Thunderbrand","Icebrand","Stone Sword","Holy Sword","Terminus Est","Marsil","Dark Blade","Heaven Sword","Fist of Tulkas","Gurthang","Mourneblade","Alucard sword","Mablung Sword","Badelaire","Sword Familiar","Great Sword","Mace","Morningstar","Holy Rod","Star Flail","Moon Rod","Chakram","Fire Boomerang","Iron Ball","Holbein dagger","Blue Knuckles","Dynamite","Osafune Katana","Masamune","Muramasa","Heart Refresh","Runesword","Antivenom","Uncurse","Life Apple","Hammer","Str. Potion","Luck Potion","Smart Potion","Attack Potion","Shield Potion","Resist Fire","Resist Thunder","Resist Ice","Resist Stone","Resist Holy","Resist Dark","Potion","High Potion","Elixir","Manna Prism","Vorpal Blade","Crissaegrim","Yasutsuna","Library card","Alucart shield","Alucart sword","No Armor","Cloth tunic","Hide cuirass","Bronze cuirass","Iron cuirass","Steel cuirass","Silver Plate","Gold Plate","Platinum mail","Diamond Plate","Fire mail","Lightning mail","Ice Mail","Mirror cuirass","Spike Breaker","Alucard mail","Dark armor","Healing mail","Holy mail","Walk armor","Brilliant mail","Mojo mail","Fury plate","Dracula tunic","God's Garb","Axe Lord Armor","Empty Head","Sunglasses","Ballroom mask","Bandanna","Felt Hat","Velvet Hat","Goggles","Leather Hat","Holy Glasses","Steel Helm","Stone Mask","Circlet","Gold Circlet","Ruby Circlet","Opal Circlet","Topaz Circlet","Beryl Circlet","Cat-eye Circlet","Coral Circlet","Dragon Helm","Silver Crown","Wizard Hat","No Cape","Cloth Cape","Reverse Cloak","Elven Cloak","Crystal Cloak","Royal Cloak","Blood Cloak","Joseph's Cloak","Twilight Cloak","No Accessory","Moonstone","Sunstone","Bloodstone","Staurolite","Ring of Pales","Zircon","Aquamarine","Turquoise","Onyx","Garnet","Opal","Diamond","Lapis lazuli","Ring of Ares","Gold Ring","Silver Ring","Ring of Varda","Ring of Arcana","Mystic pendant","Heart broach","Necklace of J","Gauntlet","Ankh of Life","Ring of Feanor","Medal","Talisman","Duplicator","King's stone","Covenant stone","Nauglamir","Secret boots","Alucart Mail","Life Max","Heart Max" };

char XB_RelicNames[][14] = { // 1234567890123",
								"Soul of Bat",
								"Fire of Bat",
								"Echo of Bat",
								"Force of Echo",
								"Soul of Wolf",
								"Power of Wolf",
								"Skill of Wolf",
								"Form of Mist",
								"Power of Mist",
								"Gas Cloud",
								"Cube of Zoe",
								"Spirit Orb",
								"Gravity Boots",
								"Leap Stone",
								"Holy Symbol",
								"Faerie Scroll",
								"Jewel of Open",
								"Merman Statue",
								"Bat Card",
								"Ghost Card",
								"Faerie Card",
								"Demon Card",
								"Sword Card",
								"Sprite Card",
								"NosedevilCard",
								"Heart of Vlad",
								"Tooth of Vlad",
								"Rib of Vlad",
								"Ring of Vlad",
								"Eye of Vlad"
								};

#define MAX_LOCKS 64

struct XB_GameLocation {
	int EntityOffsetX,EntityOffsetY;
	char Name[32],Contents[32];
	unsigned char Requirements[MAX_LOCKS][32];
	void (*Function)();
	int Equipment;		// If True, this location is an equipment piece and if the location is empty then don't put an empty hand there.
	int EQ_List_Ofs;	// Offset to Equipment List Entry in XEX
};

#define MAX_LOC 256
XB_GameLocation XB_RelicChecks[MAX_LOC];

struct XB_Candle {
	int OffsetX,OffsetY;	// XEX Offsets for Entity List Entry
	int ZoneID;				// Zone Candle is included in
	int OriginalContents;	// What was originally in this candle
	int Contents;			// What we want to place in the candle after randomizing
};
#define MAX_CANDLES 2048
XB_Candle XB_CastleCandles[MAX_CANDLES];

// Variables
int XB_ThreadStatus = 0;
int XB_AbortSignal = 0;
int XB_Character = 0;
int XB_MinimumComplexity = 0;
int XB_GeneratedSeedComplexity = 0;
int XB_RandomizeRelicLocations = 0;
int XB_RandomizeEquipment = 0;
int XB_RandomizeDrops = 0;
int XB_RandomizeShop = 0;
int XB_BoostDropRates = 0;
int XB_ClockStatue = 0;
int XB_UseRandomStartingGear = 0;
int XB_FastWarps = 0;
int XB_AntiFreeze = 0;
int XB_CandleRando = 1;
int XB_EnableMapTracker = 0;
int XB_ForceNoComplexity = 0;
int XB_ChosenComplexity = 1;
int XB_PoolMode = 0;
int XB_ItemCount[512];		// How many items are left in the pool of items.
int XB_ItemDeployCount = 0;

int XB_StartingGearSword = 0x7B;
int XB_StartingGearShield = 0x10;
int XB_StartingGearHead = 0x2D;
int XB_StartingGearBody = 0xF;
int XB_StartingGearCape = 0x38;
int XB_StartingGearAccessory = 0x4E;

int XB_Glitch_ExcludeShieldRod = 0;
int XB_NoEquipment = 0;			// Used to turn off Stage Found Equipment. For Bounty Hunter.
int XB_NoShopEquipment = 0;
int XB_BountyHunterDropRate = 16;

FILE *fXEX = NULL;

// Function Prototypes
void XB_SetStartingRH(int ID);
void XB_SetStartingLH(int ID);
void XB_SetStartingHelm(int ID);
void XB_SetStartingArmor(int ID);
void XB_SetStartingCape(int ID);
void XB_SetStartingAcc(int ID);
int XB_FindItem(char *Name);
void XB_PrintLocations();
void XB_ApplyReverseLibraryCardPatch();
unsigned int XB_CalcBranch(int SrcAddress,int DestAddress);

// File Writing Helpers
void XB_Write_u16_be(int Data)
{	fputc(Data>>8,fXEX);	fputc(Data,fXEX);	}

void XB_Write_u32_be(int Data)
{	fputc(Data>>24,fXEX);	fputc(Data>>16,fXEX);	fputc(Data>>8,fXEX);	fputc(Data,fXEX);	}

int XB_Read_u16_be()
{
	int tu16 = fgetc(fXEX)<<8;
	tu16 |= fgetc(fXEX);
	return tu16;
}

void XB_Write_Entity(int PosX,int PosY,int Type,int Slot,int Init)
{	XB_Write_u16_be(PosX);XB_Write_u16_be(PosY);XB_Write_u16_be(Type);XB_Write_u16_be(Slot);XB_Write_u16_be(Init);	}

void XB_WritePatch(int offset,unsigned char *data,int size)
{
	fseek(fXEX,offset,SEEK_SET);
	for(int i=0;i<size;i++) {	fputc(data[i],fXEX);	}
}

void XB_CandleReset()
{
	for(int i=0;i<MAX_CANDLES;i++)
	{
		XB_CastleCandles[i].OffsetX = XB_CastleCandles[i].OffsetY = XB_CastleCandles[i].ZoneID = XB_CastleCandles[i].OriginalContents = 0;
		XB_CastleCandles[i].Contents = 0xFFFF;
	}
}

void XB_CandleAdd(int Zone,int OfsX,int OfsY)
{
	int n = 0;
	while(XB_CastleCandles[n].OffsetX)
	{
		n++;
		if(n>=MAX_CANDLES)
		{
			printf("Exceeded candle limit.\n");
			return;
		}
	}
	XB_CastleCandles[n].OffsetX = OfsX;
	XB_CastleCandles[n].OffsetY = OfsY;
	XB_CastleCandles[n].ZoneID = Zone;
}

int XB_CandleCount()
{
	int Count = 0;
	while(1)
	{
		if(XB_CastleCandles[Count].OffsetX)
		{
			Count++;
		}
		else
		{
			break;
		}
	}
	Count++;
	return Count;
}

void XB_ReadCandleContents()
{
	int CandleN = 0;
	int Offset;
	
	while(1)
	{
		Offset = XB_CastleCandles[CandleN].OffsetX;
		if(Offset == 0) break;
		
		fseek(fXEX,Offset + 8,SEEK_SET);
		XB_CastleCandles[CandleN].OriginalContents = XB_Read_u16_be();
		//XB_CastleCandles[CandleN].OriginalContents = XB_CastleCandles[CandleN].OriginalContents & 0xFF;
		CandleN++;
		if(CandleN>=MAX_CANDLES) break;
	}
}

int XB_CandleCountItem(int ItemId)
{
	int Count = 0;
	int CandleN = 0;
	while(1)
	{
		if(XB_CastleCandles[CandleN].OffsetX == 0) break;
		if( (XB_CastleCandles[CandleN].OriginalContents&0x1FF) == ItemId)
			Count++;
		CandleN++;
	}
	return Count;
}

void XB_CandleDebug(int ItemId)
{
	int CandleN = 0;
	int Offset;
	int CandleUpperBits;
	
	LogMsg("CANDLE DEBUG IS ENABLED!");
	
	while(1)
	{
		Offset = XB_CastleCandles[CandleN].OffsetX;
		if(Offset == 0) break;
		CandleUpperBits = XB_CastleCandles[CandleN].OriginalContents&0xFE00;
		fseek(fXEX,Offset + 8,SEEK_SET);
		XB_Write_u16_be(CandleUpperBits | ItemId);
		Offset = XB_CastleCandles[CandleN].OffsetY;
		fseek(fXEX,Offset + 8,SEEK_SET);
		XB_Write_u16_be(CandleUpperBits | ItemId);
		CandleN++;
	}
}

void XB_CandlePlaceItemAtRandom(int ItemId)
{
	int CandleN = 0;
	int Offset;
	int CandleUpperBits;
	
	CandleN = rand() % 1326;	// Find a random Candle
		
	while(1)
	{
		if(XB_CastleCandles[CandleN].Contents == 0xFFFF)	// 0xFFFF Contents means we have not placed anything in this candle yet.
			break;
			
		CandleN++;			// If already placed, try the one after it.
		if(CandleN>1325)
			CandleN = 0;
			
		if(XB_CastleCandles[CandleN].Contents == 0xFFFF)
			break;
		
		// Roll Again
		CandleN = rand() % 1326;
	}
	
	
	Offset = XB_CastleCandles[CandleN].OffsetX;
	if(Offset)
	{
		CandleUpperBits = XB_CastleCandles[CandleN].OriginalContents&0xFE00;
		fseek(fXEX,Offset + 8,SEEK_SET);
		XB_Write_u16_be(CandleUpperBits | ItemId);
		Offset = XB_CastleCandles[CandleN].OffsetY;
		fseek(fXEX,Offset + 8,SEEK_SET);
		XB_Write_u16_be(CandleUpperBits | ItemId);
		XB_CastleCandles[CandleN].Contents = ItemId;	// marks candle as having its new random item.		
	}
}

void XB_CandleFillRemaining()
{
	int CandleN = 0;
	int Offset;
	int CandleUpperBits;
	int ItemId = 0;

	while(1)
	{
		if(XB_CastleCandles[CandleN].OffsetX == 0)
			break;
		
		if(XB_CastleCandles[CandleN].Contents == 0xFFFF)
		{
			Offset = XB_CastleCandles[CandleN].OffsetX;
			if(Offset)
			{
				CandleUpperBits = XB_CastleCandles[CandleN].OriginalContents&0xFE00;
				fseek(fXEX,Offset + 8,SEEK_SET);
				XB_Write_u16_be(CandleUpperBits | ItemId);
				Offset = XB_CastleCandles[CandleN].OffsetY;
				fseek(fXEX,Offset + 8,SEEK_SET);
				XB_Write_u16_be(CandleUpperBits | ItemId);
				XB_CastleCandles[CandleN].Contents = ItemId;	// marks candle as having its new random item.				
			}			
		}
		
		CandleN++;
	}
}

// Contains XB_CandleSetup()
#include "xb_candlesetup.h"

void XB_ApplyDeathOnVacation()
{
	// Death on Vacation
	fseek(fXEX,0xD3CE7C + 4,SEEK_SET);
	XB_Write_u16_be(0);
	fseek(fXEX,0xD3D704 + 4,SEEK_SET);
	XB_Write_u16_be(0);
	fseek(fXEX,0xD3CEAE + 4,SEEK_SET);
	XB_Write_u16_be(0);
	fseek(fXEX,0xD3D70E + 4,SEEK_SET);
	XB_Write_u16_be(0);
}

void XB_FixOuterWallElevator()
{
	fseek(fXEX,0x3CFD5E,SEEK_SET);
	fputc(0xFF,fXEX);
}

void XB_FixScyllaSoftlock()
{
	fseek(fXEX,0x42CAE8,SEEK_SET);
	XB_Write_u32_be(0x714AFFFE);
	fseek(fXEX,0x42F76B,SEEK_SET);
	fputc(0xCE,fXEX);
}

void XB_RemoveMariaAlchemyMeeting()
{
	// Old Method
	//fseek(fXEX,0xD4D634,SEEK_SET);
	//XB_Write_u32_be(0x00000000);XB_Write_u32_be(0x00000000);	// Zero their Function Pointers in the Table of Entity Func Pointers for Alchemy Lab.
	
	fseek(fXEX,0xD4AB10 + 2,SEEK_SET);
	XB_Write_u16_be(1);	XB_Write_u16_be(1);
	fseek(fXEX,0xD4B5B8 + 2,SEEK_SET);
	XB_Write_u16_be(1); XB_Write_u16_be(1);
}

unsigned int WS_COLORS[8] = { 0xEC1F,0xE00C,0x8318,0x801F,0xFC00,0x83E0,0x829F,0x80CC };
void XB_RandomizeWingSmashTrail()
{
	int RColor = rand()%8;
	fseek(fXEX,0xDEB73C,SEEK_SET);
	XB_Write_u16_be(WS_COLORS[RColor]);
}

void XB_RandomizeAlchemyVats()
{
	const int Vat_Ofs_X = 0xD4ACC2;
	int VatContents[5];
	int WeaponUsed[9];
	int WeaponId;
	
	for(int w=0;w<9;w++)
	{
		WeaponUsed[w] = 0;
	}
	
	for(int i=0;i<5;i++)
	{
		while(1)
		{
			WeaponId = rand()%9;			// Select RandomWeapon
			if(WeaponUsed[WeaponId] == 0)	// If not used we break out.
				break;
				
			WeaponId++;
			if(WeaponId>8)
				WeaponId = 0;
				
			if(WeaponUsed[WeaponId] == 0)	// If not used we break out.
				break;
				
			WeaponId++;
			if(WeaponId>8)
				WeaponId = 0;
				
			if(WeaponUsed[WeaponId] == 0)	// If not used we break out.
				break;
		}
		
		WeaponUsed[WeaponId] = 1;	// Mark Used
		VatContents[i] = WeaponId;	// Put in Vat
	}
	
	
	for(int i=0;i<5;i++)
	{
		fseek(fXEX,Vat_Ofs_X + 8 + (i*10),SEEK_SET);
		XB_Write_u16_be(VatContents[i]);
	}
}

// Relic Rando Functions
void XB_PlaceRelic(char *Name);
int XB_RelicNameToNumber(char *Name);

void XB_AddLocationLocks(int Loc, int LockCount, ...)
{
	va_list arglist;
	
	int LockSet = 0;
	int LockPos = 0;
	int arg;
	
	// Find next set of Lock Parameters
	while(1)
	{
		if(XB_RelicChecks[Loc].Requirements[LockSet][0] == 0)
			break;
		LockSet++;
		if(LockSet >= MAX_LOCKS)
		{
			printf("Too many lock sets for location: %s\n",XB_RelicChecks[Loc].Name);
			return;
		}
	}
	
	va_start(arglist,LockCount);	// Get extended arguments.
	while(1)
	{
		arg = va_arg(arglist,int);
		if(arg == 0 || LockPos>=LockCount)
			break;
		XB_RelicChecks[Loc].Requirements[LockSet][LockPos] = arg;
		LockPos++;
	}
	//printf("I received %d arguments.\n",LockCount);
	va_end(arglist);
}

void XB_EndLocationLocks(int Loc)
{
	int LockSet = 0;
	
	// Find next set of Lock Parameters
	while(1)
	{
		if(XB_RelicChecks[Loc].Requirements[LockSet][0] == 0)
			break;
		LockSet++;
		if(LockSet >= MAX_LOCKS)
		{
			printf("Too many lock sets for location: %s\n",XB_RelicChecks[Loc].Name);
			return;
		}
	}
	XB_RelicChecks[Loc].Requirements[LockSet][0] = RID_Terminate;
}

int XB_FindLocation(char *Name)
{
	int i;
	for(i=0;i<MAX_LOC;i++)
	{
		if(strcmp(XB_RelicChecks[i].Name,Name) == 0)
			break;
	}
	if(i == MAX_LOC)
	{
		printf("XB_FindLocation() Error! Couldn't find: %s\n",Name);
		return -1;
	}
	return i;
}

int XB_AddLocation(char *Name, int OffsetX, int OffsetY)
{
	int i = 0;
	while(1)	// Find Empty Location Slot
	{
		if(XB_RelicChecks[i].Name[0] == 0)	break;
		i++;
		if(i>=MAX_LOC)	return 0;	// Error Handling
	}
	//printf("%s = Location %d\n",Name,i);	// DEBUG
	
	strcpy(XB_RelicChecks[i].Name,Name);
	XB_RelicChecks[i].EntityOffsetX = OffsetX;
	XB_RelicChecks[i].EntityOffsetY = OffsetY;
	XB_RelicChecks[i].Equipment = 0;	// Default to not an Equipment Location.
	
	return i;
}

void XB_RemoveLocation(char *Name)
{
	int LocNum = XB_FindLocation(Name);
	if(LocNum == MAX_LOC) printf("Error in RemoveLocation()");
	memset(&XB_RelicChecks[LocNum],0,sizeof(XB_GameLocation));
}

void XB_ClearRelicChecks()
{
	for(int i=0;i<MAX_LOC;i++)	{	memset(&XB_RelicChecks[i],0,sizeof(XB_GameLocation));	}	// Zero Memory
}

void XB_EmptyRelicChecks()
{
	for(int i=0;i<MAX_LOC;i++)	{	XB_RelicChecks[i].Contents[0] = 0;	}		// Remove Contents
}

void XB_AddLocationFunction(int LocationNumber, void (*FunctionPointer)() )
{
	XB_RelicChecks[LocationNumber].Function = FunctionPointer;
}

// Declare any custom Relic Location Functions
void XB_SetSkillOfWolf()
{
	int Loc = XB_FindLocation("Skill of Wolf");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int ItemNumber;
	int ofs;
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20)
	{
		fseek(fXEX,OFS_SKILLOFWOLF_RELICNUMBER+1,SEEK_SET);
		fputc(RelicNumber,fXEX);
	}
	if(RelicNumber > 0x20)
	{
		ItemNumber = RelicNumber;
		if(ItemNumber == 0x80) ItemNumber = 0;
		
		ofs = OFS_X_SKILLOFWOLF + 5;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(0xA,fXEX);
		ofs = OFS_X_SKILLOFWOLF + 9;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(ItemNumber,fXEX);
		ofs = OFS_Y_SKILLOFWOLF + 5;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(0xA,fXEX);
		ofs = OFS_Y_SKILLOFWOLF + 9;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(ItemNumber,fXEX);
	}
}
void XB_SetBatCard()
{
	int Loc = XB_FindLocation("Bat Card");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int ItemNumber;
	int ofs;
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20)
	{
		fseek(fXEX,OFS_BATCARD_RELICNUMBER+1,SEEK_SET);
		fputc(RelicNumber,fXEX);
	}
	if(RelicNumber > 0x20)
	{
		ItemNumber = RelicNumber;
		if(ItemNumber == 0x80) ItemNumber = 0;
		
		ofs = OFS_X_BATCARD + 5;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(0xA,fXEX);
		ofs = OFS_X_BATCARD + 9;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(ItemNumber,fXEX);
		ofs = OFS_Y_BATCARD + 5;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(0xA,fXEX);
		ofs = OFS_Y_BATCARD + 9;	// Entity Type
		fseek(fXEX,ofs,SEEK_SET);
		fputc(ItemNumber,fXEX);
	}
}

void XB_SetJewelOfOpen()
{
	int Loc = XB_FindLocation("Jewel of Open");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int ItemNumber;
	int ofs;
	int MemoryOffset;
	int s;
	int ItemType = 0;
	
	if(Loc < 0) return;
	
	// FIX Jewel of Open having NON WEARABLE ITEMS.
	if(RelicNumber < 0x20)
	{
		fseek(fXEX,OFS_JEWELOFOPEN_RELICNUMBER+1,SEEK_SET);
		fputc(RelicNumber,fXEX);
		
		/*
		MemoryOffset = 0xF400 + RelicNumber;
		fseek(fXEX,OFS_JEWELOFOPEN_MEMCHECK,SEEK_SET);
		fputc(MemoryOffset,fXEX);
		fputc(MemoryOffset>>8,fXEX);
		*/
		
		// Relic Name String goes at 0x2FBD373C
		ofs = OFS_JEWELOFOPEN_RELICSTRING;
		fseek(fXEX,ofs,SEEK_SET);
		s = 0;
		while(1)
		{
			if(XB_RelicNames[RelicNumber][s] == 0)
			{
				fputc(0xFF,fXEX);fputc(0x00,fXEX);
				break;
			}
			fputc(XB_RelicNames[RelicNumber][s] - 0x20,fXEX);
			s++;
			if(s>16) break;
		}
	}
	if(RelicNumber > 0x20)	// is Item
	{
		ItemNumber = RelicNumber;
		
		if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0) {	RelicNumber = 0x20; ItemNumber = 4; 	}	// Shield Rod Special Case 
		
		ItemType = 1;	// Wearable is Default
		
		if(ItemNumber == 0x80)
		{
			ItemType = 0;
			ItemNumber = 0;
		}
		// Claymore, Heart Refresh, Shield Rod, Fire Boomerang, Toadstool, Library Card
		if(ItemNumber == 0x62 || ItemNumber == 0x8E || ItemNumber == 0x04 || ItemNumber == 0x86 || ItemNumber == 0x24 || ItemNumber == 0xA6)
			ItemType = 0;
		
		// For Wearables
		if(ItemType>0) ItemNumber = ItemNumber - 169;	// Adjust Indexing
		
		ofs = OFS_JEWELOFOPEN_SHOPENTRY;
		fseek(fXEX,ofs,SEEK_SET);
		fputc(ItemType,fXEX);
		fputc(0xFF,fXEX);
		
		fputc(0,fXEX);
		fputc(ItemNumber,fXEX);
		/*
		MemoryOffset = 0xF426 + ItemNumber + 169;
		fseek(fXEX,OFS_JEWELOFOPEN_MEMCHECK,SEEK_SET);
		fputc(MemoryOffset,fXEX);
		fputc(MemoryOffset>>8,fXEX);
		*/
	}
}

void XB_SetHeartOfVlad()
{
	int Loc = XB_FindLocation("Heart of Vlad");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	
	// Blue Swirl after Defeat
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;
	
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4332cc + 3,SEEK_SET);		// Instruction Byte
		fputc(0x0B,fXEX);						// Swirl Index
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xB*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4332cc + 3,SEEK_SET);
		fputc(0x11,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x11*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}
	
	// Regular Entity
	fseek(fXEX,OFS_X_HEARTOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_HEARTOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	
	fseek(fXEX,OFS_X_HEARTOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_HEARTOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
}

void XB_SetToothOfVlad()
{
	// Based on Heart code above
	int Loc = XB_FindLocation("Tooth of Vlad");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	
	// Blue Swirl after Defeat
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;
	
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x44fda4 + 3,SEEK_SET);		// Instruction Byte
		fputc(0x0C,fXEX);						// Swirl Index
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xC*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x44fda4 + 3,SEEK_SET);
		fputc(0x12,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x12*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}
	
	// Regular Entity
	fseek(fXEX,OFS_X_TOOTHOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_TOOTHOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	
	fseek(fXEX,OFS_X_TOOTHOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_TOOTHOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
}

void XB_SetRibOfVlad()
{
	// Based on Tooth which was based on Heart
	int Loc = XB_FindLocation("Rib of Vlad");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	
	// Blue Swirl after Defeat
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;
	
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x47593c + 3,SEEK_SET);		// Instruction Byte
		fputc(0x0D,fXEX);						// Swirl Index
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xD*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x47593c + 3,SEEK_SET);
		fputc(0x13,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x13*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}
	
	// Regular Entity
	fseek(fXEX,OFS_X_RIBOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_RIBOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	
	fseek(fXEX,OFS_X_RIBOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_RIBOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
}

void XB_SetRingOfVlad()
{
	int Loc = XB_FindLocation("Ring of Vlad");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	
	// Blue Swirl after Defeat
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;
	
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4a57a4 + 3,SEEK_SET);		// Instruction Byte
		fputc(0x0E,fXEX);						// Swirl Index
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xE*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4a57a4 + 3,SEEK_SET);
		fputc(0x14,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x14*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}
	
	// Entity if Darkwing is defeated
	if(EntityType == 0xA)	
	{
		fseek(fXEX,0x4A548F,SEEK_SET);fputc(0x0A,fXEX);	// Change Entity ID to 0A. Normally 0B
		fseek(fXEX,0x4A5492,SEEK_SET);XB_Write_u16_be(0x3678);	// Change Entity Func Ptr to Item.
		fseek(fXEX,0x4A549E,SEEK_SET);XB_Write_u16_be(EquipmentNumber);	// Set Item Number
	}
	if(EntityType == 0xB)	
	{
		fseek(fXEX,0x4A549E,SEEK_SET);XB_Write_u16_be(RelicNumber);	// Set Relic Number
	}

	
	/*
	if(EntityType == 0xA)	
	{
		EquipmentNumber = RelicNumber;
		if(EquipmentNumber == 0x80) EquipmentNumber = 0;
		
		fseek(fXEX,OFS_RINGOFVLAD_SPAWN_RELICNUMBER,SEEK_SET);
		fputc(0x17,fXEX);
		
		fseek(fXEX,OFS_X_RINGOFVLAD + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		
		fseek(fXEX,OFS_X_RINGOFVLAD + 9,SEEK_SET);
		fputc(EquipmentNumber,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 9,SEEK_SET);
		fputc(EquipmentNumber,fXEX);
	}
	if(EntityType == 0xB)	
	{
		fseek(fXEX,OFS_RINGOFVLAD_SPAWN_RELICNUMBER,SEEK_SET);
		fputc(0x17,fXEX);
		
		fseek(fXEX,OFS_X_RINGOFVLAD + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		
		fseek(fXEX,OFS_X_RINGOFVLAD + 9,SEEK_SET);
		fputc(RelicNumber,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 9,SEEK_SET);
		fputc(RelicNumber,fXEX);
	}

	// Slot Change
		fseek(fXEX,OFS_X_RINGOFVLAD + 7,SEEK_SET);
		fputc(0x12,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 7,SEEK_SET);
		fputc(0x12,fXEX);
	*/
	
	// Adjust Height (may break things?)
	/*
		fseek(fXEX,OFS_X_RINGOFVLAD + 2,SEEK_SET);
		fputc(0x7C,fXEX);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 2,SEEK_SET);
		fputc(0x7C,fXEX);
	*/
		
	/*
	// Move DW Entity Vertical
		fseek(fXEX,OFS_X_RINGOFVLAD + 10 + 2,SEEK_SET);
		XB_Write_u16_be(0x8);
		fseek(fXEX,OFS_Y_RINGOFVLAD + 10 + 2,SEEK_SET);
		XB_Write_u16_be(0x8);
	*/	

}

void XB_SetEyeOfVlad()
{
	// Based on Tooth
	int Loc = XB_FindLocation("Eye of Vlad");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	

	// Blue Swirl after Defeat
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;
	
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4491cc + 3,SEEK_SET);		// Instruction Byte
		fputc(0x0F,fXEX);						// Swirl Index
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xF*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x4491cc + 3,SEEK_SET);
		fputc(0x15,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x15*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}	

	// Regular Entity
	fseek(fXEX,OFS_X_EYEOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_EYEOFVLAD + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	
	// Raise Height for Item to Spawn
	fseek(fXEX,OFS_X_EYEOFVLAD + 3,SEEK_SET);
	fputc(0x7C,fXEX);
	fseek(fXEX,OFS_Y_EYEOFVLAD + 3,SEEK_SET);
	fputc(0x7C,fXEX);	
	
	fseek(fXEX,OFS_X_EYEOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_EYEOFVLAD + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
}

void XB_SetGoldRing()
{
	int Loc = XB_FindLocation("Gold Ring");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	if(Loc < 0) return;
	

	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xC;
	
	// Key Item
	if(EntityType == 0xC)
	{
		fseek(fXEX,OFS_GOLDRING_EQLIST,SEEK_SET);
		EquipmentNumber = 0x80;
		if(RelicNumber > 0x80)
			EquipmentNumber = RelicNumber + 0x80;
		XB_Write_u16_be(EquipmentNumber);
	}	
	
	// Relic
	if(EntityType == 0xB)
	{
		fseek(fXEX,OFS_GOLDRING_SUBTYPE,SEEK_SET);
		fputc(RelicNumber,fXEX);
	}
	
	fseek(fXEX,OFS_GOLDRING_TYPE,SEEK_SET);
	fputc(EntityType,fXEX);

	
	
	
	
	/* Old Junk?
	fseek(fXEX,OFS_X_GOLDRING + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_GOLDRING + 5,SEEK_SET);
	fputc(EntityType,fXEX);	
	
	fseek(fXEX,OFS_X_GOLDRING + 9,SEEK_SET);
	fputc(RelicNumber,fXEX);
	fseek(fXEX,OFS_Y_GOLDRING + 9,SEEK_SET);
	fputc(RelicNumber,fXEX);
	
	fseek(fXEX,OFS_X_GOLDRING + 7,SEEK_SET);
	fputc(0x10,fXEX);
	fseek(fXEX,OFS_Y_GOLDRING + 7,SEEK_SET);
	fputc(0x10,fXEX);
	*/
	
}

void XB_SetTrio()
{
	// Based on Tooth
	int Loc = XB_FindLocation("Trio");
	int RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	int EntityType;
	int ofs;
	int EquipmentNumber;
	
	
	if(Loc < 0) return;
	
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;

	// This part Not Used Currently
	/*	
	// Item or Empty (Blue Swirl)
	if(EntityType == 0xA)
	{
		EquipmentNumber = RelicNumber;
		if(EquipmentNumber == 0x80) EquipmentNumber = 0;
		
		// Blue Swirl
		fseek(fXEX,OFS_TRIO_RELICNUMBER,SEEK_SET);
		fputc(EquipmentNumber,fXEX);
		
		fseek(fXEX,OFS_TRIO_FUNCTIONHIGH,SEEK_SET);
		XB_WriteShort(0x0925);
		fseek(fXEX,OFS_TRIO_FUNCTIONLOW,SEEK_SET);
		XB_WriteShort(0x8F40);
	}
	// Relic (Blue Swirl)
	if(EntityType == 0xB)
	{
		// Blue Swirl
		fseek(fXEX,OFS_TRIO_RELICNUMBER,SEEK_SET);
		fputc(RelicNumber,fXEX);
		
		fseek(fXEX,OFS_TRIO_FUNCTIONHIGH,SEEK_SET);
		XB_WriteShort(0x0925);
		fseek(fXEX,OFS_TRIO_FUNCTIONLOW,SEEK_SET);
		XB_WriteShort(0x9798);
	}
	
	// Regular Entity
	fseek(fXEX,OFS_X_TRIO + 4,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 4,SEEK_SET);
	fputc(EntityType,fXEX);
	
	fseek(fXEX,OFS_X_TRIO + 8,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 8,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	
	// Fix Slot Number
	fseek(fXEX,OFS_X_TRIO + 6,SEEK_SET);
	fputc(0x10,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 6,SEEK_SET);
	fputc(0x10,fXEX);
	*/

	// Setup Room Revisit Entity
	EquipmentNumber = RelicNumber;
	if(EquipmentNumber == 0x80) EquipmentNumber = 0;

	// Set Relic or Item Number
	fseek(fXEX,OFS_X_TRIO + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 9,SEEK_SET);
	if(RelicNumber < 0x20) fputc(RelicNumber,fXEX);
	if(RelicNumber > 0x20) fputc(EquipmentNumber,fXEX);

	// Set Entity Type for Relic or Item
	fseek(fXEX,OFS_X_TRIO + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	
	// Fix Slot
	fseek(fXEX,OFS_X_TRIO + 7,SEEK_SET);
	fputc(0x10,fXEX);
	fseek(fXEX,OFS_Y_TRIO + 7,SEEK_SET);
	fputc(0x10,fXEX);	
	
	// Move to Center of Room
	fseek(fXEX,OFS_X_TRIO,SEEK_SET);
	XB_Write_u16_be(0x100);
	fseek(fXEX,OFS_Y_TRIO,SEEK_SET);
	XB_Write_u16_be(0x100);	
	
	// Make Blue Swirl Index 0x10 a Relic so Trio can have a Relic.
	fseek(fXEX,0x30E84C + 3,SEEK_SET);
	fputc(0x0F,fXEX);
	
	// Blue Swirl after Defeat
	if(EntityType == 0xA)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x47cc90 + 3,SEEK_SET);
		fputc(0x0A,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0xA*2),SEEK_SET);
		if(EquipmentNumber)
			XB_Write_u16_be(EquipmentNumber+0x80);	// Item
		else
			XB_Write_u16_be(0x17);					// Life Max
	}
	if(EntityType == 0xB)	// Set Blue Swirl Index
	{
		fseek(fXEX,0x47cc90 + 3,SEEK_SET);
		fputc(0x10,fXEX);
		fseek(fXEX,OFS_BLUESWIRL_TABLE + (0x10*2),SEEK_SET);
		XB_Write_u16_be(RelicNumber);
	}
}

// Add some blocks to be able to exit from Catacombs without any relics. This allows entry via Wolf + Power of Wolf to not get stuck.
void XB_PatchMines()
{
	fseek(fXEX,0x8578A,SEEK_SET);
	XB_Write_u16_be(0x342);
	XB_Write_u16_be(0x343);
	
	fseek(fXEX,0x8556A,SEEK_SET);
	XB_Write_u16_be(0x342);
	
	fseek(fXEX,0x85454,SEEK_SET);
	XB_Write_u16_be(0x342);
	XB_Write_u16_be(0x343);
	
	fseek(fXEX,0x85274,SEEK_SET);
	XB_Write_u16_be(0x342);
	XB_Write_u16_be(0x343);	
}

// Make Bridge Destruct with Player 1 pressing down + Y
void XB_PatchBridgeInput()
{
	fseek(fXEX,0x4DF49C,SEEK_SET);		// RAM 824db49c
	XB_Write_u32_be(0xA16B0000);		// lhz r11, 0(r11)
	XB_Write_u32_be(0x60000000);		// nop
	XB_Write_u32_be(0x2B0B4010);		// cmplwi cr6, r11, 0x4010
	XB_Write_u32_be(0x409A003C);		// bne cr6, 0x48
}

void XB_PatchClearFile()
{
	fseek(fXEX,0x399914,SEEK_SET);
	XB_Write_u32_be(0x60000000);	// NOP
}

// Include directly here. Do not build as separate object.
#include "xb_relic_locations.cpp"

void XB_SetupLocations()
{
	int Loc;
	
	XB_ClearRelicChecks();		// Clear out any old data.

	if(strcmp(XB_PresetName,"Standard") == 0)
	{
		XB_MinimumComplexity = XB_ChosenComplexity;
		XB_SetupLocations_Guarded();
	}

	if(strcmp(XB_PresetName,"Casual") == 0)		// replaced by Standard
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_Guarded();
	}
	if(strcmp(XB_PresetName,"Safe (8)") == 0)	// replaced by Standard
	{
		XB_MinimumComplexity = 8;
		XB_SetupLocations_Guarded();
	}
	
	if(strcmp(XB_PresetName,"Lycanthrope") == 0)
	{
		XB_MinimumComplexity = 8;
		XB_SetupLocations_Guarded();
	}
	if(strcmp(XB_PresetName,"Nimble") == 0)
	{
		XB_MinimumComplexity = 6;
		XB_SetupLocations_Guarded();
	}
	if(strcmp(XB_PresetName,"Warlock") == 0)
	{
		XB_MinimumComplexity = 6;
		XB_SetupLocations_Guarded();
	}
	
	if(strcmp(XB_PresetName,"Bat Master") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_Guarded();
		XB_SetupLocations_Spread();
	}

	if(strcmp(XB_PresetName,"LegDay") == 0)
	{
		XB_MinimumComplexity = 7;
		XB_SetupLocations_LegDay();
		if(XB_ChosenComplexity>7)
			XB_ChosenComplexity = 7;
	}
	
	if(strcmp(XB_PresetName,"O.G.") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_OG();
	}
	if(strcmp(XB_PresetName,"Guarded O.G.") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_Guarded();		
	}
	
	if(strcmp(XB_PresetName,"Adventure") == 0)
	{
		XB_MinimumComplexity = XB_ChosenComplexity;
		//XB_MinimumComplexity = 8;
		XB_SetupLocations_Adventure();
	}
	if(strcmp(XB_PresetName,"Expedition") == 0)
	{
		XB_MinimumComplexity = 7;
		XB_SetupLocations_Adventure();
	}
	
	if(strcmp(XB_PresetName,"Glitch") == 0)
	{
		XB_MinimumComplexity = 5;
		XB_SetupLocations_Glitch();
	}
	
	if(strcmp(XB_PresetName,"NoLogic") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_NoLogic(0);
	}
	if(strcmp(XB_PresetName,"NoLogicEq") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_NoLogic(1);
	}

	if(strcmp(XB_PresetName,"Bounty Hunter") == 0)
	{
		XB_MinimumComplexity = 5;
		XB_SetupLocations_Guarded();
	}
	if(strcmp(XB_PresetName,"Hitman") == 0)
	{
		XB_MinimumComplexity = 1;
		XB_SetupLocations_Guarded();
	}
	if(strcmp(XB_PresetName,"Richter Rando") == 0)
	{
		XB_MinimumComplexity = XB_ChosenComplexity;
		if(XB_MinimumComplexity>6) XB_MinimumComplexity = 6;
		XB_SetupLocations_Guarded();
	}
	
	if(XB_ForceNoComplexity)
	{
		LogMsg("Forcing No Minimum Complexity!");
		XB_MinimumComplexity = 1;
	}
}

int XB_RelicNameToNumber(char *Name)
{
	if(strcmp(Name,"Soul of Bat") == 0) {	return 0x00; }
	if(strcmp(Name,"Fire of Bat") == 0) {	return 0x01; }
	if(strcmp(Name,"Echo of Bat") == 0) {	return 0x02; }
	if(strcmp(Name,"Force of Echo") == 0) {	return 0x03; }
	
	if(strcmp(Name,"Soul of Wolf") == 0) {	return 0x04; }
	if(strcmp(Name,"Power of Wolf") == 0) {	return 0x05; }
	if(strcmp(Name,"Skill of Wolf") == 0){	return 0x06; }
	
	if(strcmp(Name,"Form of Mist") == 0) {	return 0x07; }
	if(strcmp(Name,"Power of Mist") == 0) {	return 0x08; }
	if(strcmp(Name,"Gas Cloud") == 0)	 {	return 0x09; }
	
	if(strcmp(Name,"Cube of Zoe") == 0) {	return 0x0A; }	
	if(strcmp(Name,"Spirit Orb") == 0) {	return 0x0B; }
	if(strcmp(Name,"Gravity Boots") == 0) {	return 0x0C; }
	if(strcmp(Name,"Leap Stone") == 0) {	return 0x0D; }
	if(strcmp(Name,"Holy Symbol") == 0) {	return 0x0E; }
	if(strcmp(Name,"Faerie Scroll") == 0) {	return 0x0F; }
	if(strcmp(Name,"Jewel of Open") == 0) {	return 0x10; }
	if(strcmp(Name,"Merman Statue") == 0) {	return 0x11; }
	
	if(strcmp(Name,"Bat Card") == 0) {		return 0x12; }
	if(strcmp(Name,"Ghost Card") == 0) {	return 0x13; }
	if(strcmp(Name,"Faerie Card") == 0) {	return 0x14; }
	if(strcmp(Name,"Demon Card") == 0) {	return 0x15; }
	if(strcmp(Name,"Sword Card") == 0) {	return 0x16; }
	if(strcmp(Name,"Sprite Card") == 0) {	return 0x17; }
	if(strcmp(Name,"Nosedevil Card") == 0) {return 0x18; }
	
	if(strcmp(Name,"Heart of Vlad") == 0) {	return 0x19; }
	if(strcmp(Name,"Tooth of Vlad") == 0) {	return 0x1A; }
	if(strcmp(Name,"Rib of Vlad") == 0) {	return 0x1B; }
	if(strcmp(Name,"Ring of Vlad") == 0) {	return 0x1C; }
	if(strcmp(Name,"Eye of Vlad") == 0) {	return 0x1D; }
	
	if(strcmp(Name,"Spikebreaker") == 0) {	return 0xB7; }
	if(strcmp(Name,"Holy Glasses") == 0) {	return 0xCB; }
	if(strcmp(Name,"Gold Ring") == 0) 	{	return 0xF1; }			// These are the Item Numbers for a Entity Type 0xA
	if(strcmp(Name,"Silver Ring") == 0) {	return 0xF2; }
	
	if(strcmp(Name,"Thrust Sword") == 0) {		return 0x62; }			// Claymore
	if(strcmp(Name,"Heart Refresh 1") == 0) {	return 0x8E; }
	if(strcmp(Name,"Heart Refresh 2") == 0) {	return 0x8E; }
	if(strcmp(Name,"Shield Rod") == 0) {		return 0x7C; }			// Using Mablung's ID#
	if(strcmp(Name,"Fire Boomerang") == 0) {	return 0x86; }
	if(strcmp(Name,"Toadstool") == 0) {			return 0x24; }
	if(strcmp(Name,"Diamond") == 0) {			return 0xEE; }
	
	if(strcmp(Name,"Ring of Arcana") == 0) {	return 0xF4; }
	if(strcmp(Name,"Ring of Varda") == 0) {		return 0xF3; }
	
	if(strcmp(Name,"Library Card")==0) {		return 0xA6; }
	
	if(strcmp(Name,"") == 0) {	return 0x80; }	// Empty
	
	for(int i=32;i<257;i++)
	{
		if(strcmp(Name,XB_ItemNames[i])==0)
		{
			return i;
		}
	}
	
	printf("Error getting RelicNameToNumber!!\nName: %s",Name);
	return 0x0;
}

int XB_RelicNameToRID(char *Name)
{
	if(strcmp(Name,"Soul of Bat") == 0) {	return RID_SoulOfBat; }
	if(strcmp(Name,"Echo of Bat") == 0) {	return RID_EchoOfBat; }
	if(strcmp(Name,"Soul of Wolf") == 0) {	return RID_SoulOfWolf; }
	if(strcmp(Name,"Power of Wolf") == 0) {	return RID_PowerOfWolf; }
	if(strcmp(Name,"Skill of Wolf") == 0){	return RID_SkillOfWolf; }
	if(strcmp(Name,"Form of Mist") == 0) {	return RID_FormOfMist; }
	if(strcmp(Name,"Power of Mist") == 0) {	return RID_PowerOfMist; }
	if(strcmp(Name,"Cube of Zoe") == 0) {	return RID_CubeOfZoe; }	
	if(strcmp(Name,"Gravity Boots") == 0) {	return RID_GravityBoots; }
	if(strcmp(Name,"Leap Stone") == 0) {	return RID_LeapStone; }
	if(strcmp(Name,"Holy Symbol") == 0) {	return RID_HolySymbol; }
	if(strcmp(Name,"Jewel of Open") == 0) {	return RID_JewelOfOpen; }
	if(strcmp(Name,"Merman Statue") == 0) {	return RID_MermanStatue; }
	if(strcmp(Name,"Demon Card") == 0) {	return RID_DemonCard; }
	if(strcmp(Name,"Spikebreaker") == 0) {	return RID_Spikebreaker; }
	if(strcmp(Name,"Holy Glasses") == 0) {	return RID_HolyGlasses; }
	if(strcmp(Name,"Gold Ring") == 0) 	{	return RID_GoldRing; }			// These are the Item Numbers for a Entity Type 0xA
	if(strcmp(Name,"Silver Ring") == 0) {	return RID_SilverRing; }
	if(strcmp(Name,"Heart of Vlad") == 0) {	return RID_HeartOfVlad; }
	if(strcmp(Name,"Tooth of Vlad") == 0) {	return RID_ToothOfVlad; }
	if(strcmp(Name,"Rib of Vlad") == 0) {	return RID_RibOfVlad; }
	if(strcmp(Name,"Ring of Vlad") == 0) {	return RID_RingOfVlad; }
	if(strcmp(Name,"Eye of Vlad") == 0) {	return RID_EyeOfVlad; }
	
	if(strcmp(Name,"Thrust Sword") == 0) {		return RID_Thrust; }
	if(strcmp(Name,"Heart Refresh 1") == 0) {	return RID_HR1; }
	if(strcmp(Name,"Heart Refresh 2") == 0) {	return RID_HR2; }
	if(strcmp(Name,"Shield Rod") == 0) {		return RID_ShieldRod; }
	if(strcmp(Name,"Fire Boomerang") == 0) {	return RID_FB; }
	if(strcmp(Name,"Toadstool") == 0) {			return RID_Toadstool; }
	if(strcmp(Name,"Diamond") == 0) {			return RID_Diamond; }
	if(strcmp(Name,"Sword Card") == 0) {		return RID_SwordCard; }
	if(strcmp(Name,"Bat Card") == 0) {			return RID_BatCard; }
	if(strcmp(Name,"Ghost Card") == 0) {		return RID_GhostCard; }
	if(strcmp(Name,"Faerie Card") == 0) {		return RID_FaerieCard; }
	
	if(strcmp(Name,"Ring of Arcana") == 0) {		return RID_Arcana; }	// These aren't really needed as we don't care if the player ever obtains them.
	if(strcmp(Name,"Ring of Varda") == 0) {			return RID_Varda; }

	return 0;
	// Not Used Current As Progression
	/*
	if(strcmp(Name,"Fire of Bat") == 0) {	return 0; }
	if(strcmp(Name,"Force of Echo") == 0) {	return 0; }
	if(strcmp(Name,"Gas Cloud") == 0)	 {	return 0; }
	if(strcmp(Name,"Spirit Orb") == 0) {	return 0; }
	if(strcmp(Name,"Faerie Scroll") == 0) {	return 0; }
	if(strcmp(Name,"Sprite Card") == 0) {	return 0; }
	if(strcmp(Name,"Nosedevil Card") == 0) {return 0; }
	*/


	return 0x0;
}


#define InvSize 64
unsigned char XB_CurInv[InvSize];
unsigned char XB_NewInv[InvSize];
unsigned char XB_StepInv[16][InvSize];

int XB_CheckRequirementLine(int Loc,int Line)
{
	int RelicID;
	int Column = 0;
	
	while(1)
	{
		RelicID = XB_RelicChecks[Loc].Requirements[Line][Column];
		if(RelicID == 0)
			return 1;
		if(XB_CurInv[RelicID] == 0)
			return 0;
		Column++;
		if(Column > 7)	// Should never happen.
		{
			printf("Error in CheckRequirementLine.\n");
			return 0;
		}
	}
}

int XB_CheckRequirements(int Loc)
{
	int Line = 0;

	if(XB_RelicChecks[Loc].Requirements[0][0] == 0) return 1;	// No Requirements then we met the requirements for this check.
	
	while(1)
	{
		if(XB_CheckRequirementLine(Loc,Line) == 1)
			return 1;
		Line++;
		if(XB_RelicChecks[Loc].Requirements[Line][0] == 0xFF)	// End of Requirement lines reached without meeting any. 
			return 0;
	}
}

int XB_CheckEscape(int Loc)
{
	unsigned char TempInv[InvSize];
	int Flight = 0;
	
	if(strcmp(XB_PresetName,"Glitch")==0) return 1;	// Permanent Library Card, can always escape.
	if(strcmp(XB_PresetName,"NoLogic")==0 || strcmp(XB_PresetName,"NoLogicEq")==0) return 1;	// Permanent Library Card, can always escape.
	
	if(strcmp(XB_RelicChecks[Loc].Name,"Holy Glasses") == 0)
	{
		memcpy(&TempInv[0],&XB_CurInv[0],InvSize);							// Copy Inventory
		TempInv[ XB_RelicNameToRID(XB_RelicChecks[Loc].Contents) ] = 1;	// Add Item at the location to Inventoru
		if(TempInv[RID_SoulOfBat]) Flight = 1;
		if(TempInv[RID_FormOfMist] && TempInv[RID_PowerOfMist]) Flight = 1;
		if(TempInv[RID_GravityBoots] && TempInv[RID_LeapStone]) Flight = 1;
		return Flight;
	}
	
	// For All other locations, no Escape Reqs so return 1.
	return 1;
}

int XB_CheckAllVlads()
{
	int Vlads = 0;
	
	if(XB_CurInv[RID_HeartOfVlad] == 1) Vlads++;
	if(XB_CurInv[RID_ToothOfVlad] == 1) Vlads++;
	if(XB_CurInv[RID_RibOfVlad] == 1) Vlads++;
	if(XB_CurInv[RID_RingOfVlad] == 1) Vlads++;
	if(XB_CurInv[RID_EyeOfVlad] == 1) Vlads++;
	
	if(Vlads == 5) return 1;
	return 0;
}

int XB_CheckHasFlight()
{
	if(XB_CurInv[RID_GravityBoots] == 1 && XB_CurInv[RID_LeapStone] == 1) return 1;
	if(XB_CurInv[RID_FormOfMist] == 1 && XB_CurInv[RID_PowerOfMist] == 1) return 1;
	if(XB_CurInv[RID_SoulOfBat] == 1) return 1;
	return 0;
}

void XB_PrintSteps()
{
	int Step = 1;
	
	while(1)
	{
		printf("Step %d\n",Step);
		for(int i=0;i<InvSize;i++)
		{
			if(XB_StepInv[Step][i] == 1)
			{
				printf("%s\n",RID_Strings[i]);
			}
		}
		printf("\n");
		Step++;
		if(Step > XB_GeneratedSeedComplexity)
			break;
	}
}

// Simulate playing the seed to see if it can be completed and in how many steps.
int XB_VerifySeed()
{
	int Steps = 0;
	int RID;
	
	for(int s=0;s<15;s++)
	{
		for(int i=0;i<InvSize;i++)	{	XB_CurInv[i] = 0; XB_StepInv[s][i] = 0; XB_NewInv[i] = 0;	}	// Clear Inventory Status
	}
	
	if(strcmp(XB_PresetName,"Hitman")==0)
	{
		XB_CurInv[RID_BatCard] = XB_CurInv[RID_GhostCard] = XB_CurInv[RID_FaerieCard] = XB_CurInv[RID_DemonCard] = XB_CurInv[RID_SwordCard] = 1;
	}
	
	if(strcmp(XB_PresetName,"Nimble") == 0 || strcmp(XB_PresetName,"Expedition") == 0)	// Setup Nimble & Expedition Starting Relics
	{
		XB_CurInv[RID_SoulOfBat] = 1;
		XB_CurInv[RID_GravityBoots] = 1;
		XB_CurInv[RID_LeapStone] = 1;
	}

	if(strcmp(XB_PresetName,"LegDay") == 0)	// Setup Starting Relics
	{
		XB_CurInv[RID_GravityBoots] = 1;	// This is so it knows we have Flight.
		XB_CurInv[RID_LeapStone] = 1;
	}
	
	if(strcmp(XB_PresetName,"Richter Rando") == 0)	// Setup Richter Starting Relics
	{
		XB_CurInv[RID_SoulOfBat] = 1;
		XB_CurInv[RID_GravityBoots] = 1;
		XB_CurInv[RID_LeapStone] = 1;
	}
	
	if(strcmp(XB_PresetName,"Warlock") == 0)	// Setup Warlock Starting Relics
	{
		XB_CurInv[RID_FormOfMist] = 1;
	}
	
	if(strcmp(XB_PresetName,"Lycanthrope") == 0)	// Setup Warlock Starting Relics
	{
		XB_CurInv[RID_SoulOfWolf] = XB_CurInv[RID_PowerOfWolf] = XB_CurInv[RID_SkillOfWolf] = 1;
	}
	
	if(XB_Character)	// If Richter or Maria they effectively start with these relics.
	{
		if(XB_MinimumComplexity > 7) XB_MinimumComplexity = 7;	// Complexity Cap. Higher may not be possible.
		XB_CurInv[RID_SoulOfBat] = 1;
		XB_CurInv[RID_GravityBoots] = 1;
		XB_CurInv[RID_LeapStone] = 1;	
	}
	
	while(Steps < 15)
	{
		for(int Loc=0;Loc<MAX_LOC;Loc++)		// For Each Location
		{
			if(XB_RelicChecks[Loc].Name[0])	// If Location Exists
			{
				if(XB_CheckRequirements(Loc) == 1)	// If we meet the requirements
				{
					// Check Escape Reqs
					if(XB_CheckEscape(Loc) == 0)
					{
						Steps = 14;	// Reject Seed if we were able to reach the location but were unable to escape.	
						/*
						printf("Unable to Escape!\n");
						XB_PrintSteps();
						XB_PrintLocations();
						*/
					}

					
					RID = XB_RelicNameToRID(XB_RelicChecks[Loc].Contents);	// Convert Contents to RID number
					if(XB_CurInv[ RID ] == 0 && RID > 0)	// If we don't have this Relic yet..
					{
						XB_NewInv[ RID ] = 1;	// Give Player Relic
						//printf("Step: %d Player Found %s\n",Steps+1,XB_RelicChecks[Loc].Contents);
					}
						
				}
				
			}
		}
		
		Steps++;
		memcpy(&XB_StepInv[Steps][0],XB_NewInv,InvSize);	// All New Stuff is Assigned to this Step.
		for(int i=0;i<InvSize;i++)	{	XB_CurInv[i] = XB_CurInv[i] | XB_NewInv[i];	}	// Copy New Stuff into Current Inventory
		memset(&XB_NewInv,0,InvSize);										// Reset New Stuff
		
		// Glitch Goal Check
		if(strcmp(XB_PresetName,"Glitch")==0)
		{
			// Multiple Win Conditions
			
			// Bat + Heart Refresh
			if(XB_CurInv[RID_SoulOfBat] && (XB_CurInv[RID_HR1] == 1 || XB_CurInv[RID_HR2] == 1) )
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Bat + HR\n");
				break;
			}
			
			// Mist + PoM + Heart Refresh
			if(XB_CurInv[RID_FormOfMist] && XB_CurInv[RID_PowerOfMist] && (XB_CurInv[RID_HR1] == 1 || XB_CurInv[RID_HR2] == 1) )
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Mist + PoM + HR\n");
				break;
			}

			// Bat + Shield Rod + Leap Stone
			if(XB_CurInv[RID_SoulOfBat] && XB_CurInv[RID_ShieldRod] && XB_CurInv[RID_LeapStone])
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Bat + Shield Rod + Leap Stone\n");
				break;
			}
			
			// Bat + Shield Rod + Thrust Sword
			if(XB_CurInv[RID_SoulOfBat] && XB_CurInv[RID_ShieldRod] && XB_CurInv[RID_Thrust])
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Bat + Shield Rod + Thrust Sword\n");
				break;
			}
			
			// Mist + PoM + Shield Rod + Leap Stone
			if(XB_CurInv[RID_FormOfMist] && XB_CurInv[RID_PowerOfMist] && XB_CurInv[RID_ShieldRod] && XB_CurInv[RID_LeapStone])
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Mist + Power of Mist + Shield Rod + Leap Stone\n");
				break;
			}
			
			// Mist + PoM + Shield Rod + Thrust Sword
			if(XB_CurInv[RID_FormOfMist] && XB_CurInv[RID_PowerOfMist] && XB_CurInv[RID_ShieldRod] && XB_CurInv[RID_Thrust])
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Mist + Power of Mist + Shield Rod + Thrust Sword\n");
				break;
			}
			
			// HR x2 + Gravity + (Leap || Wolf || Mist)
			if(XB_CurInv[RID_HR1] && XB_CurInv[RID_HR2] && XB_CurInv[RID_GravityBoots] && (XB_CurInv[RID_LeapStone] || XB_CurInv[RID_SoulOfWolf] || XB_CurInv[RID_FormOfMist]) )
			{
				if(Steps>= XB_MinimumComplexity)
					printf("\nGlitch Goal: Heart Refresh x2 + Gravity Boots + (Leap or Wolf or Mist)\n");
				break;
			}

		}
		
		// Bounty Hunter Goal Check
		if(strcmp(XB_PresetName,"Bounty Hunter")==0)
		{
			if(XB_CurInv[RID_HolyGlasses] && XB_CurInv[RID_BatCard] && XB_CurInv[RID_GhostCard] && XB_CurInv[RID_FaerieCard] && XB_CurInv[RID_DemonCard] && XB_CurInv[RID_SwordCard] && XB_CheckHasFlight())
				break;
		}
		if(strcmp(XB_PresetName,"Hitman")==0)
		{
			if(XB_CurInv[RID_HolyGlasses] && XB_CheckHasFlight())
				break;
		}
				
		// Check if we have achieved Goal status.
		if(XB_CurInv[RID_HolyGlasses] == 1 && XB_CheckAllVlads() == 1 && XB_CheckHasFlight() == 1 )
		{
			//printf("We have 5 Vlads, HG, and Flight! Steps = %d\n",Steps);
			//printf("RID_HolyGlasses = %d",RID_HolyGlasses);
			break;
			
		}
	}
	
	//printf("VerifySeed() Returns: %d\n",Steps);
	return Steps;
	
	// TODO:
	// Verify Seed Logic
	// Do Escape Reqs?
	// Demon Card, Holy Glasses, and Mormegil are the 3 locations where you can get stuck potentially. two require atleast leap or gravity to get one and HG requires Flight.
	// If Requirements are met for a location but Escape Requirements are not then the seed is Soft-Lock-Able and should be tossed?
	//return 1;
	//return 99;
}

char XB_RelicPool[64][32];

void XB_ClearRelicPool()
{
	for(int i=0;i<64;i++)
	{
		XB_RelicPool[i][0] = 0;
	}
}

void XB_AddRelicToPool(char *Name)
{
	int RandomSlot;
	while(1)
	{
		RandomSlot = rand()%64;
		if(XB_RelicPool[RandomSlot][0] == 0)
			break;
		RandomSlot++;RandomSlot&=0x3F;

		if(XB_RelicPool[RandomSlot][0] == 0)
			break;
		RandomSlot++;RandomSlot&=0x3F;
	}
	strcpy(XB_RelicPool[RandomSlot],Name);
}

int XB_GetRelicFromPool()
{
	int RandomSlot;
	while(1)
	{
		RandomSlot = rand()%64;
		if(XB_RelicPool[RandomSlot][0] != 0)
			break;
		RandomSlot++;RandomSlot&=0x3F;

		if(XB_RelicPool[RandomSlot][0] != 0)
			break;
		RandomSlot++;RandomSlot&=0x3F;
	}
	return RandomSlot;
}

int XB_RelicPoolCount()
{
	int RCount = 0;
	for(int i=0;i<64;i++)
	{
		if(XB_RelicPool[i][0])
			RCount++;
	}
	return RCount;
}

// Uses list of allowed locations
int XB_RelicLocationFilter(char *RelicName,char *List)
{
	int Loc;
	char *result;
	
	Loc = XB_FindItem(RelicName);				// Find The Location With the Relic
	if(Loc < 0) return 0;
	result = strstr(List,XB_RelicChecks[Loc].Name);		// Search the List String for the Location name where we found the relic.
	if(result == NULL)
	{
		XB_RelicChecks[Loc].Contents[0] = 0;	// Remove Item from Location
		return 0;								// Return 0, Not at an allowed Location
	}
	return 1;
}

// Uses list of BANNED locations
int XB_RelicLocationFilterBanned(char *RelicName,char *List)
{
	int Loc;
	char *result;
	
	Loc = XB_FindItem(RelicName);				// Find The Location With the Relic
	if(Loc < 0) return 0;
	result = strstr(List,XB_RelicChecks[Loc].Name);		// Search the List String for the Location name where we found the relic.
	if(result != NULL)
	{
		XB_RelicChecks[Loc].Contents[0] = 0;	// Remove Item from Location
		return 0;								// Return 0, Not at an allowed Location
	}
	return 1;
}


void XB_HighComplexitySeedRelics()
{
	int FirstRelic = rand();
	
	switch(FirstRelic&3)
	{
		case 0:
		case 3:
			// Jewel of Open
			while(XB_RelicLocationFilter("Jewel of Open","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Jewel of Open");}
			while(XB_RelicLocationFilterBanned("Gravity Boots","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Gravity Boots");}
			while(XB_RelicLocationFilterBanned("Leap Stone","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Leap Stone");}			
			break;
		case 1:
			// Gravity
			while(XB_RelicLocationFilter("Gravity Boots","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Gravity Boots");}	
			while(XB_RelicLocationFilterBanned("Jewel of Open","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Jewel of Open");}
			while(XB_RelicLocationFilterBanned("Leap Stone","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Leap Stone");}	
			break;
		case 2:
			// Leap
			while(XB_RelicLocationFilter("Leap Stone","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Leap Stone");}
			while(XB_RelicLocationFilterBanned("Jewel of Open","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Jewel of Open");}
			while(XB_RelicLocationFilterBanned("Gravity Boots","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf") == 0)
			{	XB_PlaceRelic("Gravity Boots");}
			break;
	}
}

void XB_LegDaySeedRelics()
{
	int Castle = 0;
	int Loc;
	
	// Place Spikebreaker anywhere in 1st Castle.
	while(1)
	{
		XB_PlaceRelic("Spikebreaker");									// Place it randomly
		Loc = XB_FindItem("Spikebreaker");								// Find the location it ended up at

		Castle = 1;
		for(int i = 0;i<31;i++)					// Search Location Lock Requirements for Holy Glasses to determine Castle 1 or 2. We only need to check Line 0.
		{
			if(XB_RelicChecks[Loc].Requirements[0][i] == RID_HolyGlasses) Castle = 2;
		}
		if(Castle == 1) break;
		
		XB_RelicChecks[Loc].Contents[0] = 0;							// Otherwise we remove SB from this location and try again.
	}
	
	// Place Holy Glasses anywhere in 1st Castle.
	while(1)
	{
		XB_PlaceRelic("Holy Glasses");									// Place it randomly
		Loc = XB_FindItem("Holy Glasses");								// Find the location it ended up at

		Castle = 1;
		for(int i = 0;i<31;i++)					// Search Location Lock Requirements for Holy Glasses to determine Castle 1 or 2. We only need to check Line 0.
		{
			if(XB_RelicChecks[Loc].Requirements[0][i] == RID_HolyGlasses) Castle = 2;
		}
		if(Castle == 1) break;
		
		XB_RelicChecks[Loc].Contents[0] = 0;							// Otherwise we remove SB from this location and try again.
	}

	while(1)	// Place Item at Location where it may only be claimed once.
	{
		XB_PlaceRelic("Covenant stone");
		if(XB_RelicLocationFilterBanned("Covenant stone","Heart of Vlad,Tooth of Vlad,Rib of Vlad,Ring of Vlad,Eye of Vlad,Trio,Jewel of Open"))
			break;
	}
	
	while(1)	// Place Item at Location where it may only be claimed once.
	{
		XB_PlaceRelic("Ring of Ares");
		if(XB_RelicLocationFilterBanned("Ring of Ares","Heart of Vlad,Tooth of Vlad,Rib of Vlad,Ring of Vlad,Eye of Vlad,Trio,Jewel of Open"))
			break;
	}

	while(1)	// Place Item at Location where it may only be claimed once.
	{
		XB_PlaceRelic("King's stone");
		if(XB_RelicLocationFilterBanned("King's stone","Heart of Vlad,Tooth of Vlad,Rib of Vlad,Ring of Vlad,Eye of Vlad,Trio,Jewel of Open"))
			break;
	}

	XB_PlaceRelic("Jewel of Open");

	XB_PlaceRelic("Form of Mist");

	XB_PlaceRelic("Merman Statue");
	
	XB_PlaceRelic("Gold Ring");
	XB_PlaceRelic("Silver Ring");
	XB_PlaceRelic("Holy Glasses");
	XB_PlaceRelic("Spikebreaker");			

	XB_PlaceRelic("Soul of Wolf");

	XB_PlaceRelic("Heart of Vlad");
	XB_PlaceRelic("Tooth of Vlad");
	XB_PlaceRelic("Rib of Vlad");
	XB_PlaceRelic("Ring of Vlad");
	XB_PlaceRelic("Eye of Vlad");

	XB_PlaceRelic("Cube of Zoe");
	XB_PlaceRelic("Demon Card");

	XB_PlaceRelic("Gas Cloud");
	XB_PlaceRelic("Spirit Orb");
	XB_PlaceRelic("Holy Symbol");
	XB_PlaceRelic("Faerie Scroll");
	XB_PlaceRelic("Bat Card");
	XB_PlaceRelic("Ghost Card");
	XB_PlaceRelic("Faerie Card");
	XB_PlaceRelic("Sword Card");
	
	XB_PlaceRelic("Str. Potion A");
	XB_PlaceRelic("Str. Potion B");

	Loc = XB_FindItem("Str. Potion A");
	if(Loc>0)
		strcpy(XB_RelicChecks[Loc].Contents,"Str. Potion");
	Loc = XB_FindItem("Str. Potion B");
	if(Loc>0)
		strcpy(XB_RelicChecks[Loc].Contents,"Str. Potion");
		
	//XB_PlaceRelic("Soul of Bat");
	//XB_PlaceRelic("Power of Mist");
	//XB_PlaceRelic("Gravity Boots");
	//XB_PlaceRelic("Leap Stone");
	//XB_PlaceRelic("Echo of Bat");
	//XB_PlaceRelic("Fire of Bat");
	//XB_PlaceRelic("Force of Echo");
	//XB_PlaceRelic("Power of Wolf");
	//XB_PlaceRelic("Skill of Wolf");
}

void XB_BatMasterSeedRelics()
{
	int Loc;
	int JewelCastle = 1;
	
	/*
	while(1)	// Place Soul of Bat. It must end up at one of these locations.
	{
		XB_PlaceRelic("Soul of Bat");	// Place it.
		Loc = XB_FindItem("Soul of Bat");	// Find where it is.
		if( strcmp(XB_RelicChecks[Loc].Name,"Cube of Zoe")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Spirit Orb")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Jewel of Open")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Faerie Scroll")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Soul of Wolf")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Leap Stone")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Crystal Cloak")==0 ||
			strcmp(XB_RelicChecks[Loc].Name,"Merman Statue")==0
			)
			{
				break;	// If it is at an acceptable location we're done.
			}
		XB_RelicChecks[Loc].Contents[0] = 0;	// If Not remove it from whereever it is and try again.
	}*/

	while(XB_RelicLocationFilter("Soul of Bat","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Crystal Cloak,Merman Statue") == 0)
	{	XB_PlaceRelic("Soul of Bat");}
	
	// Place Jewel Next so we know where in 1st we can place the other 3 Bat Relics
	XB_PlaceRelic("Jewel of Open");
	
	if( strcmp(XB_RelicChecks[XB_FindLocation("Soul of Bat")].Contents,"Jewel of Open") == 0)	// If Jewel was placed at Soul of Bat consider Jewel to be in 2nd Castle.
	{
		JewelCastle = 2;;
	}
	
	Loc = XB_FindItem("Jewel of Open");		// Get the Location for Jewel
	for(int i = 0;i<31;i++)					// Search Location Lock Requirements for Holy Glasses to determine Castle 1 or 2. We only need to check Line 0.
	{
		if(XB_RelicChecks[Loc].Requirements[0][i] == RID_HolyGlasses)	JewelCastle = 2;
	}
	
	if(JewelCastle == 1)
	{
		while(XB_RelicLocationFilter("Fire of Bat","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Crystal Cloak,Merman Statue,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Demon Card,Sword Card") == 0)
		{	XB_PlaceRelic("Fire of Bat");}	
		while(XB_RelicLocationFilter("Echo of Bat","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Crystal Cloak,Merman Statue,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Demon Card,Sword Card") == 0)
		{	XB_PlaceRelic("Echo of Bat");}
		while(XB_RelicLocationFilter("Force of Echo","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Crystal Cloak,Merman Statue,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Demon Card,Sword Card") == 0)
		{	XB_PlaceRelic("Force of Echo");}
		while(XB_RelicLocationFilter("Bat Card","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Crystal Cloak,Merman Statue,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Demon Card,Sword Card") == 0)
		{	XB_PlaceRelic("Bat Card");}		
	}
	else
	{
		while(XB_RelicLocationFilter("Fire of Bat","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Sword Card") == 0)
		{	XB_PlaceRelic("Fire of Bat");}	
		while(XB_RelicLocationFilter("Echo of Bat","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Sword Card") == 0)
		{	XB_PlaceRelic("Echo of Bat");}
		while(XB_RelicLocationFilter("Force of Echo","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Sword Card") == 0)
		{	XB_PlaceRelic("Force of Echo");}
		while(XB_RelicLocationFilter("Bat Card","Cube of Zoe,Spirit Orb,Jewel of Open,Faerie Scroll,Soul of Wolf,Leap Stone,Fire of Bat,Echo of Bat,Power of Wolf,Skill of Wolf,Form of Mist,Power of Mist,Gravity Boots,Bat Card,Ghost Card,Faerie Card,Sword Card") == 0)
		{	XB_PlaceRelic("Bat Card");}			
	}

}

void XB_RandomizeRelics(void *pMyID)
{
	int SeedComplexity = 99;
	int rpi;
	int Attempts = 0;
	int SeedOffset = 0;
	int OG_MODE = 0;
	int Loc;
	int LocAlt;
	
	if(strcmp(XB_PresetName,"O.G.")==0 || strcmp(XB_PresetName,"Guarded O.G.")==0)
		OG_MODE = 1;
		
	if(strcmp(XB_PresetName,"Bingo")==0)
	{
		LogMsg("Bingo Mode. Vanilla Relic Placement.");
		XB_ThreadStatus = 0;
		return;
	}	
	
	printf("XB_RandomizeRelics()\n");
	
	XB_SetupLocations();
	XB_EmptyRelicChecks();
	
	printf("Randoming Relic Loop Starting..\n");
	KickProgress(1);	// Show GUI Object
	//while(SeedComplexity > 12 || SeedComplexity < XB_MinimumComplexity)
	while(1)
	{	
		if(XB_AbortSignal)
		{
			XB_GeneratedSeedComplexity = 99;
			XB_ThreadStatus = 0;
			return;
		}
		
		// Generate a new setting.
		XB_EmptyRelicChecks();
		
		// Debug, Force Item at a Location
		//strcpy( XB_RelicChecks[XB_FindLocation("Gold Ring")].Contents,"Silver Ring");
		
		
		// Experimental
		/*
		XB_ClearRelicPool();
		XB_AddRelicToPool("Jewel of Open");
		XB_AddRelicToPool("Soul of Bat");
		XB_AddRelicToPool("Gravity Boots");
		XB_AddRelicToPool("Leap Stone");
		XB_AddRelicToPool("Form of Mist");
		XB_AddRelicToPool("Power of Mist");
		XB_AddRelicToPool("Merman Statue");
		XB_AddRelicToPool("Gold Ring");
		XB_AddRelicToPool("Silver Ring");
		XB_AddRelicToPool("Holy Glasses");
		XB_AddRelicToPool("Spikebreaker");
		XB_AddRelicToPool("Soul of Wolf");
		XB_AddRelicToPool("Echo of Bat");
		XB_AddRelicToPool("Heart of Vlad");
		XB_AddRelicToPool("Tooth of Vlad");
		XB_AddRelicToPool("Rib of Vlad");
		XB_AddRelicToPool("Ring of Vlad");
		XB_AddRelicToPool("Eye of Vlad");
		XB_AddRelicToPool("Cube of Zoe");
		XB_AddRelicToPool("Demon Card");
		XB_AddRelicToPool("Fire of Bat");
		XB_AddRelicToPool("Force of Echo");
		XB_AddRelicToPool("Power of Wolf");
		XB_AddRelicToPool("Skill of Wolf");
		XB_AddRelicToPool("Gas Cloud");
		XB_AddRelicToPool("Spirit Orb");
		XB_AddRelicToPool("Holy Symbol");
		XB_AddRelicToPool("Faerie Scroll");
		XB_AddRelicToPool("Bat Card");
		XB_AddRelicToPool("Ghost Card");
		XB_AddRelicToPool("Faerie Card");
		XB_AddRelicToPool("Sword Card");
		XB_AddRelicToPool("Sprite Card");
		XB_AddRelicToPool("Nosedevil Card");
		
		while(XB_RelicPoolCount())
		{
			rpi = XB_GetRelicFromPool();
			XB_PlaceRelic(XB_RelicPool[rpi]);
			XB_RelicPool[rpi][0] = 0;
		}
		*/
		if(strcmp(XB_PresetName,"Bounty Hunter")==0 || strcmp(XB_PresetName,"Hitman")==0)
		{
			// Place Varda somewhere it won't respawn infinitely.
			while(XB_RelicLocationFilterBanned("Ring of Varda","Heart of Vlad,Tooth of Vlad,Rib of Vlad,Ring of Vlad,Eye of Vlad,Trio,Jewel of Open") == 0)
			{	XB_PlaceRelic("Ring of Varda");}			
			
			XB_PlaceRelic("Jewel of Open");
			XB_PlaceRelic("Soul of Bat");
			XB_PlaceRelic("Gravity Boots");
			XB_PlaceRelic("Leap Stone");
			XB_PlaceRelic("Form of Mist");
			XB_PlaceRelic("Power of Mist");
			XB_PlaceRelic("Merman Statue");
			
			XB_PlaceRelic("Gold Ring");
			XB_PlaceRelic("Silver Ring");
			XB_PlaceRelic("Holy Glasses");
			XB_PlaceRelic("Spikebreaker");	
	
			XB_PlaceRelic("Soul of Wolf");
			XB_PlaceRelic("Echo of Bat");
			
			XB_PlaceRelic("Cube of Zoe");
			XB_PlaceRelic("Demon Card");
			XB_PlaceRelic("Fire of Bat");
			XB_PlaceRelic("Force of Echo");
			XB_PlaceRelic("Power of Wolf");
			XB_PlaceRelic("Skill of Wolf");
			XB_PlaceRelic("Gas Cloud");
			XB_PlaceRelic("Spirit Orb");
			XB_PlaceRelic("Holy Symbol");
			XB_PlaceRelic("Faerie Scroll");
			XB_PlaceRelic("Bat Card");
			XB_PlaceRelic("Ghost Card");
			XB_PlaceRelic("Faerie Card");
			XB_PlaceRelic("Sword Card");
			
			XB_PlaceRelic("Ring of Arcana");
			
			// Place these with Unique Names, or else it'll only place one of them.
			XB_PlaceRelic("Library Card 1");
			XB_PlaceRelic("Library Card 2");
			XB_PlaceRelic("Library Card 3");
			XB_PlaceRelic("Library Card 4");
			XB_PlaceRelic("Library Card 5");
			
			// Next, Trim Number off Each Card so it will be identified correctly as Library Card.
			Loc = XB_FindItem("Library Card 1");
			if(Loc>0)
				strcpy(XB_RelicChecks[Loc].Contents,"Library Card");
			Loc = XB_FindItem("Library Card 2");
			if(Loc>0)
				strcpy(XB_RelicChecks[Loc].Contents,"Library Card");
			Loc = XB_FindItem("Library Card 3");
			if(Loc>0)
				strcpy(XB_RelicChecks[Loc].Contents,"Library Card");
			Loc = XB_FindItem("Library Card 4");
			if(Loc>0)
				strcpy(XB_RelicChecks[Loc].Contents,"Library Card");
			Loc = XB_FindItem("Library Card 5");
			if(Loc>0)
				strcpy(XB_RelicChecks[Loc].Contents,"Library Card");
			
			// Remove Library Cards from locations where they could be infinitely obtained.
			Loc = XB_FindLocation("Heart of Vlad")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Tooth of Vlad")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Rib of Vlad")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Ring of Vlad")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Eye of Vlad")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Trio")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindLocation("Jewel of Open")	;
			if(strcmp(XB_RelicChecks[Loc].Contents,"Library Card")==0)
				XB_RelicChecks[Loc].Contents[0] = 0;
			
			
			//XB_PlaceRelic("Sprite Card");
			//XB_PlaceRelic("Nosedevil Card");
			goto DONE_PLACING_RELICS;
		}
		
		if(strcmp(XB_PresetName,"Glitch")==0)
		{
			XB_PlaceRelic("Thrust Sword");
			XB_PlaceRelic("Heart Refresh 1");
			XB_PlaceRelic("Heart Refresh 2");
			if(XB_Glitch_ExcludeShieldRod == 0)
				XB_PlaceRelic("Shield Rod");
			XB_PlaceRelic("Fire Boomerang");
			XB_PlaceRelic("Toadstool");
			XB_PlaceRelic("Diamond");
			
			XB_PlaceRelic("Jewel of Open");
			XB_PlaceRelic("Soul of Bat");
			XB_PlaceRelic("Gravity Boots");
			XB_PlaceRelic("Leap Stone");
			XB_PlaceRelic("Form of Mist");
			XB_PlaceRelic("Power of Mist");
			XB_PlaceRelic("Merman Statue");

			XB_PlaceRelic("Gold Ring");
			XB_PlaceRelic("Silver Ring");
			XB_PlaceRelic("Holy Glasses");
			XB_PlaceRelic("Spikebreaker");
			
			XB_PlaceRelic("Soul of Wolf");
			XB_PlaceRelic("Echo of Bat");
			/*
			XB_PlaceRelic("Heart of Vlad");
			XB_PlaceRelic("Tooth of Vlad");
			XB_PlaceRelic("Rib of Vlad");
			XB_PlaceRelic("Ring of Vlad");
			XB_PlaceRelic("Eye of Vlad");
			*/
			XB_PlaceRelic("Cube of Zoe");
			XB_PlaceRelic("Demon Card");
			XB_PlaceRelic("Fire of Bat");
			XB_PlaceRelic("Force of Echo");
			XB_PlaceRelic("Power of Wolf");
			XB_PlaceRelic("Skill of Wolf");
			XB_PlaceRelic("Gas Cloud");
			XB_PlaceRelic("Spirit Orb");
			XB_PlaceRelic("Holy Symbol");
			XB_PlaceRelic("Faerie Scroll");
			XB_PlaceRelic("Bat Card");
			XB_PlaceRelic("Ghost Card");
			XB_PlaceRelic("Faerie Card");
			XB_PlaceRelic("Sword Card");
			
			XB_PlaceRelic("Sprite Card");
			XB_PlaceRelic("Nosedevil Card");
			goto DONE_PLACING_RELICS;
		}
		
		
		if( strcmp(XB_PresetName,"Safe (8)")==0 || strcmp(XB_PresetName,"Lycanthrope")==0 )
		{
			XB_HighComplexitySeedRelics();
		}
		
		// Bat Master Relic Seeding
		if(strcmp(XB_PresetName,"Bat Master")==0)
		{
			XB_BatMasterSeedRelics();
		}
		
		// Leg Day Relic Seeding
		if(strcmp(XB_PresetName,"LegDay")==0)
		{
			XB_LegDaySeedRelics();
			goto DONE_PLACING_RELICS;
		}
		
		if(OG_MODE)	// O.G. Has Vanilla Key Items, so we must place them first.
		{
			strcpy(XB_RelicChecks[XB_FindLocation("Gold Ring")].Contents,"Gold Ring");
			strcpy(XB_RelicChecks[XB_FindLocation("Silver Ring")].Contents,"Silver Ring");
			strcpy(XB_RelicChecks[XB_FindLocation("Spikebreaker")].Contents,"Spikebreaker");
			strcpy(XB_RelicChecks[XB_FindLocation("Holy Glasses")].Contents,"Holy Glasses");
		}
		
		// Standard Relic Seeding starts here.
		
		XB_PlaceRelic("Jewel of Open");
		XB_PlaceRelic("Soul of Bat");
		XB_PlaceRelic("Gravity Boots");
		XB_PlaceRelic("Leap Stone");
		XB_PlaceRelic("Form of Mist");
		XB_PlaceRelic("Power of Mist");
		XB_PlaceRelic("Merman Statue");
		
		if(!OG_MODE)	// If Not O.G. then these are placed randomly.
		{
			XB_PlaceRelic("Gold Ring");
			XB_PlaceRelic("Silver Ring");
			XB_PlaceRelic("Holy Glasses");
			XB_PlaceRelic("Spikebreaker");			
		}

		XB_PlaceRelic("Soul of Wolf");
		XB_PlaceRelic("Echo of Bat");
		XB_PlaceRelic("Heart of Vlad");
		XB_PlaceRelic("Tooth of Vlad");
		XB_PlaceRelic("Rib of Vlad");
		XB_PlaceRelic("Ring of Vlad");
		XB_PlaceRelic("Eye of Vlad");
		XB_PlaceRelic("Cube of Zoe");
		XB_PlaceRelic("Demon Card");
		XB_PlaceRelic("Fire of Bat");
		XB_PlaceRelic("Force of Echo");
		XB_PlaceRelic("Power of Wolf");
		XB_PlaceRelic("Skill of Wolf");
		XB_PlaceRelic("Gas Cloud");
		XB_PlaceRelic("Spirit Orb");
		XB_PlaceRelic("Holy Symbol");
		XB_PlaceRelic("Faerie Scroll");
		XB_PlaceRelic("Bat Card");
		XB_PlaceRelic("Ghost Card");
		XB_PlaceRelic("Faerie Card");
		XB_PlaceRelic("Sword Card");
		
		XB_PlaceRelic("Sprite Card");
		XB_PlaceRelic("Nosedevil Card");
		
		// Glitch Preset, Remove all Vlads. Has multiple other goals.
		// NOTE: This should be redundent now as the goto DONE_PLACING_RELICS should stop these being placed now.
		if(strcmp(XB_PresetName,"Glitch")==0)
		{
			Loc = XB_FindItem("Heart of Vlad");
			if(Loc >= 0) XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindItem("Tooth of Vlad");
			if(Loc >= 0) XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindItem("Rib of Vlad");
			if(Loc >= 0) XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindItem("Ring of Vlad");
			if(Loc >= 0) XB_RelicChecks[Loc].Contents[0] = 0;
			Loc = XB_FindItem("Eye of Vlad");
			if(Loc >= 0) XB_RelicChecks[Loc].Contents[0] = 0;			
		}
		
DONE_PLACING_RELICS:
			
		
		// Check if Seed meets requirements and Exit Loop if it does.
		SeedComplexity = XB_VerifySeed();
		if(SeedComplexity >= XB_MinimumComplexity && SeedComplexity < 12)
			break;
			
		Attempts++;
		
		// If it's taking awhile we kick the Seed and reset the RNG.
		if(Attempts%50000 == 0)
		{
			SeedOffset+=7;
			srand( (XB_InverseSeedNumber ^ 0xFFFFFFFF) - SeedOffset );
			//LogMsg("..");
			KickProgress(2);
		}
		
	}
	
	printf("Attempts until success was:%d\n",Attempts);
	XB_GeneratedSeedComplexity = SeedComplexity;	// Save to Global for later.
	printf("Randoming Relic Loop Complete.\n");

	XB_ThreadStatus = 0;
	KickProgress(0);	// Hide GUi Object
	// Debug
	//strcpy( XB_RelicChecks[XB_FindLocation("Jewel of Open")].Contents, "Holy Glasses");

}

void XB_SaveSpoilers()
{
	char sOut[256];
	char sBuf[256];
	FILE *fOut = fopen("spoilers.txt","wb");
	if(fOut==NULL) return;
	
	fputs("Seed Name: ",fOut);fputs(sSeedName,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
	fputs("Preset: ",fOut);fputs(XB_PresetName,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
	itoa(XB_InverseSeedNumber ^ 0xFFFFFFFF,sBuf,16);
	fputs("Seed Number: ",fOut);fputs(sBuf,fOut);fputc(0xD,fOut);fputc(0xA,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
	
	for(int i=0;i<MAX_LOC;i++)
	{
		if(XB_RelicChecks[i].Name[0])
		{
			strcpy(sOut,"");
			while(strlen(sOut)<32 - (strlen(XB_RelicChecks[i].Name))) { strcat(sOut," ");	}
			strcat(sOut,XB_RelicChecks[i].Name);
			strcat(sOut," has ");
			strcat(sOut,XB_RelicChecks[i].Contents);
			fputs(sOut,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
		}
	}
	fputc(0xD,fOut);fputc(0xA,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
	itoa(XB_GeneratedSeedComplexity,sBuf,10);
	strcpy(sOut,"Complexity: ");strcat(sOut,sBuf);
	fputs(sOut,fOut);fputc(0xD,fOut);fputc(0xA,fOut);
	fputc(0xD,fOut);fputc(0xA,fOut);

	int Step = 1;
	
	while(1)
	{
		strcpy(sOut,"Step  ");itoa(Step,sBuf,10);strcat(sOut,sBuf);
		fputs(sOut,fOut);fputc(0xD,fOut);fputc(0xA,fOut);

		for(int i=0;i<InvSize;i++)
		{
			if(XB_StepInv[Step][i] == 1)
			{
				fputs(RID_Strings[i],fOut);fputc(0xD,fOut);fputc(0xA,fOut);
			}
		}
		fputc(0xD,fOut);fputc(0xA,fOut);
		Step++;
		if(Step > XB_GeneratedSeedComplexity)
			break;
	}
	
	fclose(fOut);
}

void XB_PrintLocations()
{
	for(int i=0;i<MAX_LOC;i++)
	{
		if(XB_RelicChecks[i].Name[0])
		{
			printf("%32s has %s\n",XB_RelicChecks[i].Name,XB_RelicChecks[i].Contents);
		}
	}
	printf("\nComplexity: %d\n\n",XB_GeneratedSeedComplexity);
}

// Takes a Location Name with it's Entity X and Y List offsets, Equipment List and EQ List Offset
// If The location has an item, it replaces the Relic Entity with the Equipment Entity set to the Equipment Index specified and sets that entry in EQ list to the correct Item number.
void XB_ARAI(char *LocName, int OfsX, int OfsY, int OfsEQ, int EQ_Index)
{
	int Loc;
	int RelicNumber;
	int ItemNumber;
	int EntityType;
	
	Loc = XB_FindLocation(LocName);
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	ItemNumber = RelicNumber;
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0) {	ItemNumber = 4; EntityType = 0xA;	}	// Shield Rod Special Case
	
	if(EntityType == 0xA && ItemNumber != 0x80)
	{
		printf("\n%s has %s. Using Entity 0xC\n",XB_RelicChecks[Loc].Name,XB_RelicChecks[Loc].Contents);
		EntityType = 0xC;
		// Change Entity Type to 0xC and Init to 0x0. Then set Equipment List Entry to Item Number
		fseek(fXEX,OfsX + 4,SEEK_SET);	// Write Entity Type 0xC
		XB_Write_u16_be(EntityType);
		fseek(fXEX,OfsY + 4,SEEK_SET);
		XB_Write_u16_be(EntityType);
		fseek(fXEX,OfsX + 8,SEEK_SET);	// Write Item Index
		XB_Write_u16_be(EQ_Index);
		fseek(fXEX,OfsY + 8,SEEK_SET);
		XB_Write_u16_be(EQ_Index);
		
		fseek(fXEX,OfsEQ + (EQ_Index * 2),SEEK_SET);	// Update EQ List at Item Idex
		XB_Write_u16_be(ItemNumber + 0x80);
	}
}

// Simply return if a location has an Item. Returns 1 if Item, 0 if Relic
int XB_LocHasItem(char *LocName)
{
	int Loc;
	int RelicNumber;
	int EntityType;
	
	Loc = XB_FindLocation(LocName);
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);

	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0) { EntityType = 0xA;	}	// Shield Rod Special Case
	
	if(EntityType == 0xA)
		return 1;
	return 0;
}

// Set an Entity Entry to be an Empty Hand. Used to delete an entity. Maybe we can set Entity Type 0x00? Dunno.
void XB_SetEntityToEmptyHand(int OfsX, int OfsY)
{
	fseek(fXEX,OfsX + 4,SEEK_SET);
	XB_Write_u16_be(0xA);
	fseek(fXEX,OfsX + 8,SEEK_SET);
	XB_Write_u16_be(0x0);
	fseek(fXEX,OfsY + 4,SEEK_SET);
	XB_Write_u16_be(0xA);
	fseek(fXEX,OfsY + 8,SEEK_SET);
	XB_Write_u16_be(0x0);
}

// This will steal an equipment slot for various Relics if they have an Item at the location so it can only be picked up once.
void XB_AdjustRelicsAsItems()
{
	int Loc;
	int RelicNumber;
	int ItemNumber;
	int EntityType;
	int EQ_Index;
	
	/*
	Loc = XB_FindLocation("Soul of Bat");
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	ItemNumber = RelicNumber;
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0) {	ItemNumber = 4; EntityType = 0xA;	}	// Shield Rod Special Case
	
	if(EntityType == 0xA)
	{
		EQ_Index = 0;
		EntityType = 0xC;
		// Change Entity Type to 0xC and Init to 0x0. Then set Equipment List Entry to Item Number
		fseek(fXEX,OFS_X_SOULOFBAT + 4,SEEK_SET);	// Write Entity Type 0xC
		XB_Write_u16_be(EntityType);
		fseek(fXEX,OFS_Y_SOULOFBAT + 4,SEEK_SET);
		XB_Write_u16_be(EntityType);
		fseek(fXEX,OFS_X_SOULOFBAT + 8,SEEK_SET);	// Write Item Index
		XB_Write_u16_be(EQ_Index);
		fseek(fXEX,OFS_Y_SOULOFBAT + 8,SEEK_SET);
		XB_Write_u16_be(EQ_Index);
		
		fseek(fXEX,EQ_LIB + (EQ_Index * 2),SEEK_SET);	// Update EQ List at Item Idex
		XB_Write_u16_be(ItemNumber + 0x80);
	}
	*/
	
	XB_ARAI("Soul of Bat",OFS_X_SOULOFBAT,OFS_Y_SOULOFBAT,EQ_LIB,0x00);
	XB_ARAI("Fire of Bat",OFS_X_FIREOFBAT,OFS_Y_FIREOFBAT,EQ_CT,0x02);
	XB_ARAI("Echo of Bat",OFS_X_ECHOOFBAT,OFS_Y_ECHOOFBAT,EQ_OQ,0x02);
	XB_ARAI("Force of Echo",OFS_X_FORCEOFECHO,OFS_Y_FORCEOFECHO,EQ_RUC,0x1B);
	XB_ARAI("Soul of Wolf",OFS_X_SOULOFWOLF,OFS_Y_SOULOFWOLF,EQ_OW,0x02);
	if(XB_LocHasItem("Soul of Wolf")) {	XB_SetEntityToEmptyHand(0xD4F3DE,0xD4FBAE);	}	// Replace Heart Max by Elevator Switch
	XB_ARAI("Power of Wolf",OFS_X_POWEROFWOLF,OFS_Y_POWEROFWOLF,EQ_CE,0x08);
	XB_ARAI("Power of Wolf",OFS_X_POWEROFWOLF_NP3,OFS_Y_POWEROFWOLF_NP3,EQ_CE,0x08);
	if(XB_LocHasItem("Power of Wolf"))	// If Power of Wolf has Item, Remove the Life Max we are stealing it's slot from in the Equipment List.
	{
		XB_SetEntityToEmptyHand(0xD26C64,0xD273F4);
		XB_SetEntityToEmptyHand(0xD3C9AE,0xD3D1DC);
	}
	XB_ARAI("Skill of Wolf",OFS_X_SKILLOFWOLF,OFS_Y_SKILLOFWOLF,EQ_AL,0x05);
	XB_ARAI("Form of Mist",OFS_X_FORMOFMIST,OFS_Y_FORMOFMIST,EQ_CO,0x02);
	XB_ARAI("Power of Mist",OFS_X_POWEROFMIST,OFS_Y_POWEROFMIST,EQ_CK,0x0D);
	if(XB_LocHasItem("Power of Mist"))	{	XB_SetEntityToEmptyHand(0xCF7224,0xCF787C);	}	// Replaces Life Max in Ghost Card Room
	XB_ARAI("Gas Cloud",OFS_X_GASCLOUD,OFS_Y_GASCLOUD,EQ_RCC,0x11);
	if(XB_LocHasItem("Gas Cloud"))	{	XB_SetEntityToEmptyHand(0xCF1E70,0xCF2A8C);	}	// Replace Ruby Circlet in same room.
	XB_ARAI("Cube of Zoe",OFS_X_CUBEOFZOE,OFS_Y_CUBEOFZOE,EQ_CE,0x03);
	XB_ARAI("Cube of Zoe",OFS_X_CUBEOFZOE_NP3,OFS_Y_CUBEOFZOE_NP3,EQ_CE,0x03);	
	XB_ARAI("Spirit Orb",OFS_X_SPIRITORB,OFS_Y_SPIRITORB,EQ_MG,0x03);
	if(XB_LocHasItem("Spirit Orb"))	{	XB_SetEntityToEmptyHand(0xD5798A,0xD5887C);	}	// Replace Life Apple on left of Gravity Boots Room.
	XB_ARAI("Gravity Boots",OFS_X_GRAVITYBOOTS,OFS_Y_GRAVITYBOOTS,EQ_MG,0x04);
	if(XB_LocHasItem("Gravity Boots"))	{	XB_SetEntityToEmptyHand(0xD57994,0xD58886);	}	// Replace Hammer on left of Gravity Boots Room.	
	XB_ARAI("Leap Stone",OFS_X_LEAPSTONE,OFS_Y_LEAPSTONE,EQ_CK,0x11);
	XB_ARAI("Holy Symbol",OFS_X_HOLYSYMBOL,OFS_Y_HOLYSYMBOL,EQ_UC,0x19);
	if(XB_LocHasItem("Holy Symbol"))	{	XB_SetEntityToEmptyHand(0xCDC31E,0xCDD4A4);	}	// Replace Elixir right before it.
	XB_ARAI("Faerie Scroll",OFS_X_FAERIESCROLL,OFS_Y_FAERIESCROLL,EQ_LIB,0x09);
	if(XB_LocHasItem("Faerie Scroll"))	{	XB_SetEntityToEmptyHand(0xD40BE6,0xD41386);	}	// Replaces Antivenom in Faerie Card Room.
	XB_ARAI("Merman Statue",OFS_X_MERMANSTATUE,OFS_Y_MERMANSTATUE,EQ_UC,0x00);
	if(XB_LocHasItem("Merman Statue"))	{	XB_SetEntityToEmptyHand(0xCDC37A,0xCDD71C);XB_SetEntityToEmptyHand(0xCDC5FC,0xCDD764);	}	// Replaces Heart Max in water right before Relic and in room before Bandanna
	XB_ARAI("Bat Card",OFS_X_BATCARD,OFS_Y_BATCARD,EQ_AL,0x04);
	XB_ARAI("Ghost Card",OFS_X_GHOSTCARD,OFS_Y_GHOSTCARD,EQ_CK,0x0E);
	if(XB_LocHasItem("Ghost Card"))	{	XB_SetEntityToEmptyHand(0xCF7238,0xCF7890);	}	// Replaces Life Max in Ghost Card Room
	XB_ARAI("Faerie Card",OFS_X_FAERIECARD,OFS_Y_FAERIECARD,EQ_LIB,0x08);
	if(XB_LocHasItem("Faerie Card"))	{	XB_SetEntityToEmptyHand(0xD40BDC,0xD4137C);	}	// Replaces Potion in Faerie Card Room.
	XB_ARAI("Demon Card",OFS_X_DEMONCARD,OFS_Y_DEMONCARD,EQ_AM,0x02);
	XB_ARAI("Sword Card",OFS_X_SWORDCARD,OFS_Y_SWORDCARD,EQ_OQ,0x03);
	
	// Locations that still use 0xA
	// Vlad Relic Drops
	// Trio
}

// This adjusts the positioning of some relics to make them look nicer.
void XB_AdjustRelicPositions()
{
	int Loc;
	int RelicNumber;
	int ItemNumber;
	int EntityType;
	
	// Dark Blade
	Loc = XB_FindLocation("Dark Blade");
	if(Loc>=0)
	{
		RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
		if(RelicNumber < 0x20) EntityType = 0xB;
		if(RelicNumber > 0x20) EntityType = 0xA;
		
		if(EntityType == 0xB)	// If Relic, Move this Up off the Ground.
		{
			// X-Sorted
			fseek(fXEX,OFS_X_DARKBLADE + 3,SEEK_SET);
			fputc(0x80,fXEX);
	
			// Y-Sorted
			fseek(fXEX,OFS_Y_DARKBLADE + 3,SEEK_SET);
			fputc(0x80,fXEX);		
		}
	}
	
	// Osafune Katana (Equipment)
	Loc = XB_FindLocation("Osafune Katana");
	if(Loc>=0)
	{
		RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
		if(RelicNumber < 0x20) EntityType = 0xB;
		if(RelicNumber > 0x20) EntityType = 0xA;
		
		if(EntityType == 0xB)	// Move Relic Up
		{
			fseek(fXEX,OFS_X_OSAFUNEKATANA+2,SEEK_SET);
			XB_Write_u16_be(0x89);
			fseek(fXEX,OFS_Y_OSAFUNEKATANA+2,SEEK_SET);
			XB_Write_u16_be(0x89);
		}
		if(EntityType == 0xA)	// Move Item Up and Left
		{
			fseek(fXEX,OFS_X_OSAFUNEKATANA+2,SEEK_SET);
			XB_Write_u16_be(0x52);
			fseek(fXEX,OFS_Y_OSAFUNEKATANA+2,SEEK_SET);
			XB_Write_u16_be(0x89);
		}	
	}

	// TODO: ???

}

// This Copies Relics that appear in more than one Zone/Stage so it appears properly in both.
void XB_WriteExtraRelics()
{
	int Loc;
	int RelicNumber;
	int ItemNumber;
	int EntityType;
	int Temp;
	
	// Copy Power of Wolf to NP3 Stage
	Loc = XB_FindLocation("Power of Wolf");
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	ItemNumber = RelicNumber;
	if(ItemNumber == 0x80) ItemNumber = 0;
	// X-Sorted
	fseek(fXEX,OFS_X_POWEROFWOLF_NP3 + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_X_POWEROFWOLF_NP3 + 9,SEEK_SET);
	if(EntityType == 0xB) fputc(RelicNumber,fXEX);
	if(EntityType == 0xA) fputc(ItemNumber,fXEX);
	// Y-Sorted
	fseek(fXEX,OFS_Y_POWEROFWOLF_NP3 + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_POWEROFWOLF_NP3 + 9,SEEK_SET);
	if(EntityType == 0xB) fputc(RelicNumber,fXEX);
	if(EntityType == 0xA) fputc(ItemNumber,fXEX);
	
	// Copy Cube of Zoe
	Loc = XB_FindLocation("Cube of Zoe");
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	ItemNumber = RelicNumber;
	if(ItemNumber == 0x80) ItemNumber = 0;
	// X-Sorted
	fseek(fXEX,OFS_X_CUBEOFZOE_NP3 + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_X_CUBEOFZOE_NP3 + 9,SEEK_SET);
	if(EntityType == 0xB) fputc(RelicNumber,fXEX);
	if(EntityType == 0xA) fputc(ItemNumber,fXEX);
	// Y-Sorted
	fseek(fXEX,OFS_Y_CUBEOFZOE_NP3 + 5,SEEK_SET);
	fputc(EntityType,fXEX);
	fseek(fXEX,OFS_Y_CUBEOFZOE_NP3 + 9,SEEK_SET);
	if(EntityType == 0xB) fputc(RelicNumber,fXEX);
	if(EntityType == 0xA) fputc(ItemNumber,fXEX);
	
	// Copy Crystal Cloak
	Loc = XB_FindLocation("Crystal Cloak");
	RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
	if(RelicNumber < 0x20) EntityType = 0xB;
	if(RelicNumber > 0x20) EntityType = 0xA;
	ItemNumber = RelicNumber;
	if(ItemNumber == 0x80) ItemNumber = 0;
	
	if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0)	// Correction for Shield Rod.
	{
		RelicNumber = 0x20;
		ItemNumber = 4;
		EntityType = 0xA;
	}
	
	if(EntityType == 0xB)	// Only Update Entity if Location has Relic. If it's an item the EQ List has already been updated.
	{
		// X-Sorted
		fseek(fXEX,OFS_X_CRYSTALCLOAK_BOSS + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		fseek(fXEX,OFS_X_CRYSTALCLOAK_BOSS + 9,SEEK_SET);
		if(EntityType == 0xB) fputc(RelicNumber,fXEX);
		if(EntityType == 0xA) fputc(ItemNumber,fXEX);
		// Y-Sorted
		fseek(fXEX,OFS_Y_CRYSTALCLOAK_BOSS + 5,SEEK_SET);
		fputc(EntityType,fXEX);
		fseek(fXEX,OFS_Y_CRYSTALCLOAK_BOSS + 9,SEEK_SET);
		if(EntityType == 0xB) fputc(RelicNumber,fXEX);
		if(EntityType == 0xA) fputc(ItemNumber,fXEX);		
	}

	
	// Fix Holy Glasses Item/Relic Slot
	fseek(fXEX,OFS_X_HOLYGLASSES+7,SEEK_SET);fputc(0x10,fXEX);
	fseek(fXEX,OFS_Y_HOLYGLASSES+7,SEEK_SET);fputc(0x10,fXEX);
	
	// Extensions
	
	// Copy Holy Mail to NP3 Stage
	Loc = XB_FindLocation("Holy Mail");
	if(Loc >= 0)
	{
		RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
		if(RelicNumber < 0x20) EntityType = 0xB;
		if(RelicNumber > 0x20) EntityType = 0xA;
		ItemNumber = RelicNumber;
		if(ItemNumber == 0x80) ItemNumber = 0;
		
		if( (EntityType == 0xA) == false)	// Only Update Entity if it's not placing an Item.
		{
			// X-Sorted
			fseek(fXEX,OFS_X_HOLYMAIL_NP3 + 5,SEEK_SET);
			fputc(EntityType,fXEX);
			fseek(fXEX,OFS_X_HOLYMAIL_NP3 + 9,SEEK_SET);
			if(EntityType == 0xB) fputc(RelicNumber,fXEX);
			if(EntityType == 0xA) fputc(ItemNumber,fXEX);
			// Y-Sorted
			fseek(fXEX,OFS_Y_HOLYMAIL_NP3 + 5,SEEK_SET);
			fputc(EntityType,fXEX);
			fseek(fXEX,OFS_Y_HOLYMAIL_NP3 + 9,SEEK_SET);
			if(EntityType == 0xB) fputc(RelicNumber,fXEX);
			if(EntityType == 0xA) fputc(ItemNumber,fXEX);		
		}		
	}
	
	
	// Copy Jewel Sword to NO3 Stage, Replaces Life Apple as Jewel Sword doesn't exist in NO3
	Loc = XB_FindLocation("Jewel Sword");
	if(Loc >= 0)
	{
		RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
		if(RelicNumber < 0x20) EntityType = 0xB;
		if(RelicNumber > 0x20) EntityType = 0xA;
		ItemNumber = RelicNumber;
		if(ItemNumber == 0x80) ItemNumber = 0;
		
		if( (EntityType == 0xA && ItemNumber == 0) == false)	// Only Update Entity if it's not placing an Empty Hand.
		{
			// X-Sorted
			fseek(fXEX,OFS_X_JEWELSWORD_NO3 + 5,SEEK_SET);
			fputc(EntityType,fXEX);
			fseek(fXEX,OFS_X_JEWELSWORD_NO3 + 9,SEEK_SET);
			if(EntityType == 0xB) fputc(RelicNumber,fXEX);
			if(EntityType == 0xA) fputc(ItemNumber,fXEX);
			// Y-Sorted
			fseek(fXEX,OFS_Y_JEWELSWORD_NO3 + 5,SEEK_SET);
			fputc(EntityType,fXEX);
			fseek(fXEX,OFS_Y_JEWELSWORD_NO3 + 9,SEEK_SET);
			if(EntityType == 0xB) fputc(RelicNumber,fXEX);
			if(EntityType == 0xA) fputc(ItemNumber,fXEX);		
		}	
	}
	
	// For Glitch, Copy Bat Card Entity to secondary room incase of RSL
	Loc = XB_FindLocation("Bat Card");
	if(Loc >= 0)
	{
		fseek(fXEX,OFS_X_BATCARD+4,SEEK_SET);
		Temp = XB_Read_u16_be();
		fseek(fXEX,OFS_X_BATCARD_ALT+4,SEEK_SET);
		XB_Write_u16_be(Temp);
		fseek(fXEX,OFS_X_BATCARD+8,SEEK_SET);
		Temp = XB_Read_u16_be();
		fseek(fXEX,OFS_X_BATCARD_ALT+8,SEEK_SET);
		XB_Write_u16_be(Temp);
	}
}

void XB_WriteRelics()
{
	int ofs;
	int EntityType;
	int RelicNumber;
	int ItemNumber;
	
	if(strcmp(XB_PresetName,"Bingo")==0) return;
	
	for(int Loc=0;Loc<MAX_LOC;Loc++)
	{
		if(XB_RelicChecks[Loc].Name[0])
		{
			if(XB_RelicChecks[Loc].Function != NULL)
			{
				XB_RelicChecks[Loc].Function();
			}
			else
			{
				if(XB_RelicChecks[Loc].EntityOffsetX == 0) printf("Bad offset! %s\n",XB_RelicChecks[Loc].Name);
				// Standard Relic Entity Location
				RelicNumber = XB_RelicNameToNumber(XB_RelicChecks[Loc].Contents);
				ItemNumber = RelicNumber;
				
				// Special Case Shield Rod:
				if(strcmp(XB_RelicChecks[Loc].Contents,"Shield Rod")==0)
				{
					RelicNumber = 0x20;
					ItemNumber = 4;
				}
				
				if(ItemNumber == 0x80) ItemNumber = 0;
				if(RelicNumber < 0x20)	{	EntityType = 0xB;	}	else	{	EntityType = 0xA;	}
				
				// If Location is already an Equipment Entity and this location contains an item we just change the Item Number.
				if(EntityType == 0xA && ItemNumber > 0 && XB_RelicChecks[Loc].EQ_List_Ofs>0)
				{
					ofs = fseek(fXEX,XB_RelicChecks[Loc].EQ_List_Ofs,SEEK_SET);
					XB_Write_u16_be(ItemNumber + 0x80);
					printf("writing eq list instead of entity for: %s\n",XB_RelicChecks[Loc].Name);
					continue;
				}
				
				// If this location is empty and it is an equipment location, don't place empty hand there, let it remain an equipment pickup.
				if(EntityType == 0xA && ItemNumber == 0 && XB_RelicChecks[Loc].Equipment)
				{
					//printf("%s has nothing. Not writing over equipment entity.\n",XB_RelicChecks[Loc].Name);
					continue;
				}

				// Write Entity
				// X-Sorted
				ofs = XB_RelicChecks[Loc].EntityOffsetX + 4;	// Entity Type
				fseek(fXEX,ofs,SEEK_SET);
				XB_Write_u16_be(EntityType);
				ofs = XB_RelicChecks[Loc].EntityOffsetX + 8;	// Entity Sub-Type
				fseek(fXEX,ofs,SEEK_SET);
				if(EntityType == 0xB)	XB_Write_u16_be(RelicNumber);
				if(EntityType == 0xA)	XB_Write_u16_be(ItemNumber);
				// Y-Sorted
				ofs = XB_RelicChecks[Loc].EntityOffsetY + 4;	// Entity Type
				fseek(fXEX,ofs,SEEK_SET);
				XB_Write_u16_be(EntityType);
				ofs = XB_RelicChecks[Loc].EntityOffsetY + 8;	// Entity Sub-Type
				fseek(fXEX,ofs,SEEK_SET);
				if(EntityType == 0xB)	XB_Write_u16_be(RelicNumber);
				if(EntityType == 0xA)	XB_Write_u16_be(ItemNumber);
				
			}
		}
	}
	
	XB_WriteExtraRelics();
	XB_AdjustRelicsAsItems();
	XB_AdjustRelicPositions();
}

int XB_FindItem(char *Name)
{
	int i;
	for(i=0;i<MAX_LOC;i++)
	{
		if(XB_RelicChecks[i].Name[0] && strcmp(XB_RelicChecks[i].Contents,Name) == 0)
			return i;
	}
	return -1;
}

int XB_FilterRelicLocation(char *RelicName,char *LocationName)
{
	if(strcmp(RelicName,"Holy Glasses") == 0)
	{
		if(strcmp(LocationName,"Force of Echo") == 0)
			return 1;
		if(strcmp(LocationName,"Gas Cloud") == 0)
			return 1;
		if(strcmp(LocationName,"Heart of Vlad") == 0)
			return 1;
		if(strcmp(LocationName,"Tooth of Vlad") == 0)
			return 1;
		if(strcmp(LocationName,"Rib of Vlad") == 0)
			return 1;
		if(strcmp(LocationName,"Ring of Vlad") == 0)
			return 1;
		if(strcmp(LocationName,"Eye of Vlad") == 0)
			return 1;
		if(strcmp(LocationName,"Trio") == 0)
			return 1;
		if(strcmp(LocationName,"Ring of Arcana") == 0)
			return 1;
		if(strcmp(LocationName,"Dark Blade") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Gold Ring") == 0)
	{
		if(strcmp(LocationName,"Holy Glasses") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Silver Ring") == 0)
	{
		if(strcmp(LocationName,"Holy Glasses") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Form of Mist") == 0)
	{
		if(strcmp(LocationName,"Soul of Bat") == 0)
			return 1;
		if(strcmp(LocationName,"Silver Ring") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Echo of Bat") == 0)
	{
		if(strcmp(LocationName,"Spikebreaker") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Soul of Bat") == 0)
	{
		if(strcmp(LocationName,"Spikebreaker") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Merman Statue") == 0)
	{
		if(strcmp(LocationName,"Holy Symbol") == 0)
			return 1;
	}
	if(strcmp(RelicName,"Jewel of Open") == 0)
	{
		if(strcmp(LocationName,"Gold Ring") == 0)
			return 1;
		if(strcmp(LocationName,"Crystal Cloak") == 0)
			return 1;
		if(strcmp(LocationName,"Holy Symbol") == 0)
			return 1;
		if(strcmp(LocationName,"Merman Statue") == 0)
			return 1;
		if(strcmp(LocationName,"Demon Card") == 0)
			return 1;
		if(strcmp(LocationName,"Spikebreaker") == 0)
			return 1;
		if(strcmp(LocationName,"Mormegil") == 0)
			return 1;
	}
	return 0;
}

void XB_BurnRandom()
{
	
	time_t t;
	//int BurnCount = time(&t)&0x3f;	// More Random
	//int BurnCount = rand()&0x3f;		// For Reproducable Seed with same Seed Number. But not random enough.
	
	int BurnCount = sSeedName[SeedName_Index];	// This Helps Seed Variety and is reproducible.
	SeedName_Index++;
	if(sSeedName[SeedName_Index] == 0) SeedName_Index = 0;
	while(BurnCount)
	{
		rand();
		BurnCount--;
	}
	
}

int XB_CountEmptyLocations()
{
	int Count = 0;
	for(int i=0;i<MAX_LOC;i++)	{	if(XB_RelicChecks[i].Name[0] && XB_RelicChecks[i].Contents[0]==0) Count++;	}	return Count;
}

void XB_PlaceRelic(char *Name)
{
	int RandomLoc;
	//printf("Placing Relic: %s\n",Name);
	if(XB_CountEmptyLocations()==0) return;		// Don't get stuck in infinite loop.
	
	while(XB_FindItem(Name) < 0)
	{
		XB_BurnRandom();
		RandomLoc = rand()&0xFF;	// Pick Random Slot
		
		while(XB_RelicChecks[RandomLoc].Name[0] == 0)
		{
			RandomLoc = RandomLoc + (rand()%64);
			RandomLoc = RandomLoc&0xFF;
		}
		
		if(XB_RelicChecks[RandomLoc].Name[0] && XB_RelicChecks[RandomLoc].Contents[0] == 0)
		{
			if(XB_FilterRelicLocation(Name,XB_RelicChecks[RandomLoc].Name) == 0)
				strcpy(XB_RelicChecks[RandomLoc].Contents,Name);
		}
	}
}

// Replaces text on main menu with Randomizer title and version.
void XB_AddRandoString()
{
	strcpy(XB_RandoVersion,__DATE__);	// Just use this. Then I don't have to update it.
	
	int s = 0;
	char tmp = 1;
	char seednumber_buf[40];
	itoa(XB_InverseSeedNumber ^ 0xFFFFFFFF,seednumber_buf,16);
	
	fseek(fXEX,0x215DC0,SEEK_SET);	// Copy Title String
	while(tmp!=0)	{	tmp = XB_RandoTitle[s];	fputc(tmp,fXEX);	s++;	}
	
	s = 0; tmp = 1;
	fseek(fXEX,0x215DD8,SEEK_SET);
	while(tmp!=0)
	{
		tmp = XB_RandoVersion[s];

		if(tmp>=0x2E && tmp<0x3A)
		{
			if(tmp>=0x2E && tmp<0x30)	{	fputc(0x81,fXEX);fputc(0x44,fXEX);	}
			else	{	fputc(0x82,fXEX);	fputc(tmp + 0x1F,fXEX);	}
		}
		else
		{	fputc(tmp,fXEX);	}
		s++;
	}
	
	// Then again for Input Richter String, but do Preset Name & seed number
	s = 0;tmp = 1;
	fseek(fXEX,0x215E9C,SEEK_SET);	// Copy Title String
	while(tmp!=0)	{	tmp = XB_PresetName[s];	fputc(tmp,fXEX);	s++;	}
		
	s = 0; tmp = 1;
	fseek(fXEX,0x215EBC,SEEK_SET);
	while(tmp!=0)
	{
		//tmp = XB_RandoVersion[s];
		tmp = seednumber_buf[s];

		if(tmp>=0x2E && tmp<0x3A)
		{
			if(tmp>=0x2E && tmp<0x30)	{	fputc(0x81,fXEX);fputc(0x44,fXEX);	}
			else	{	fputc(0x82,fXEX);	fputc(tmp + 0x1F,fXEX);	}
		}
		else
		{	fputc(tmp,fXEX);	}
		s++;
	}
	
	// Then again for select new game to start from beginning String
	s = 0;tmp = 1;
	fseek(fXEX,0x215E70,SEEK_SET);	// Copy Title String
	while(tmp!=0)	{	tmp = XB_PresetName[s];	fputc(tmp,fXEX);	s++;	}
	
	s = 0; tmp = 1;
	fseek(fXEX,0x215E80,SEEK_SET);
	while(tmp!=0)
	{
		//tmp = XB_RandoVersion[s];
		tmp = seednumber_buf[s];

		if(tmp>=0x2E && tmp<0x3A)
		{
			if(tmp>=0x2E && tmp<0x30)	{	fputc(0x81,fXEX);fputc(0x44,fXEX);	}
			else	{	fputc(0x82,fXEX);	fputc(tmp + 0x1F,fXEX);	}
		}
		else
		{	fputc(tmp,fXEX);	}
		s++;
	}
	
	// Change Safe (8)'s name string in Game so it displays just as Safe.
	if(strcmp(XB_PresetName,"Safe (8)")==0)
	{
		fseek(fXEX,0x215EA0,SEEK_SET);fputc(0x00,fXEX);
		fseek(fXEX,0x215E74,SEEK_SET);fputc(0x00,fXEX);
	}
		
}

void XB_InitializeItemPool(int Mode)
{
	// Zero
	for(int n=0;n<512;n++)	{	XB_ItemCount[n] = 0;	}
	
	// Add 2 of Everything to Pool By Default. Tweak from there.
	if(Mode == 0) 
	{
		for(int n=0;n<260;n++)	{	XB_ItemCount[n] = 2;	}
		XB_ItemCount[259] = 25;	// Life Max
		XB_ItemCount[260] = 25;	// Heart Max
		XB_ItemCount[232] = 8;	// Zircons
		XB_ItemCount[233] = 3;	// Aquamarines
		XB_ItemCount[234] = 2;	// Turquoise
		XB_ItemCount[235] = 2;	// Onyx
		XB_ItemCount[236] = 5;	// Garnet
		XB_ItemCount[237] = 5;	// Opal
		XB_ItemCount[238] = 4;	// Diamonds
		
		//for(int n=29;n<70;n++)	{	if(n&1) XB_ItemCount[n] = 1;	}	// Food Items. Every other one has only 1.
	}
	
	// Only 1 of Each Item for Enemy Drops Assignment
	if(Mode == 1) 
	{
		for(int n=0;n<260;n++)
		{
			XB_ItemCount[n] = 1;
		}
		if(strcmp(XB_PresetName,"Bingo")==0)	
		{
			XB_ItemCount[166] = 0;	// No LBC Drops
			XB_ItemCount[253] = 0;	// No Dupe Drops
		}
	}

	// Remove Special Items
	XB_ItemCount[0] = XB_ItemCount[126] = XB_ItemCount[169] = XB_ItemCount[183] = XB_ItemCount[195] = XB_ItemCount[203] = XB_ItemCount[217] = XB_ItemCount[226] = XB_ItemCount[241] = XB_ItemCount[242] = 0;
	
	// Glitch Item Restrictions
	if(strcmp(XB_PresetName,"Glitch")==0)
	{
		XB_ItemCount[4]   = 0;	// Shield Rod
		XB_ItemCount[36]  = 0;	// Toadstool
		XB_ItemCount[70]  = 0;	// Meal Ticket
		XB_ItemCount[124] = 0;	// Mablung Sword
		XB_ItemCount[134] = 0;	// Fire Boomerang
		XB_ItemCount[142] = 0;	// Heart Refresh
		XB_ItemCount[238] = 0;	// Diamond
		
		XB_ItemCount[95]  = 0;	// Estoc
		XB_ItemCount[98]  = 0;	// Claymore
		XB_ItemCount[101] = 0;	// Flamberge
		XB_ItemCount[103] = 0;	// Zwei hander
		XB_ItemCount[107] = 0;	// Obsidian	
	}
	
	// Bounty Hunter Item Restrictions
	if(strcmp(XB_PresetName,"Bounty Hunter")==0 || strcmp(XB_PresetName,"Hitman")==0)
	{
		for(int f=29;f<59;f++)	// Food Items Tied to Relics can not be placed Randomly.
		{
			XB_ItemCount[f] = 0;
		}
	}	
}

int XB_GetRandomItem(int Mode)
{
	int ItemsRemaining;
	int RandomNumber = 0;
	XB_ItemDeployCount++;
	
	// Count Items Left in Pool
	ItemsRemaining = 0;
	for(int i=0;i<261;i++)
	{
		ItemsRemaining = ItemsRemaining + XB_ItemCount[i];
	}
	//printf("ItemsRemaining = %d\n",ItemsRemaining);
	if(ItemsRemaining == 0) XB_ItemCount[ (rand()%40) + 29] = 1;	// Fail safe. Adds a random food item. Prevents generation from getting stuck.
	
	XB_BurnRandom();
	
	// Just a Random Number (Can't be Unarmed, No Head, No Body, No Cape, No Accessory, or Spikebreaker, Holy Glasses, Gold&Silver Rings. Or Sword Familiar (126)
	while(RandomNumber == 0 || RandomNumber == 126 || RandomNumber == 169 || RandomNumber == 183 || RandomNumber == 195 || RandomNumber == 203 || RandomNumber == 217 || RandomNumber == 226 || RandomNumber == 241 || RandomNumber == 242)	// 259 and 260 will be Life and Heart Maxes
	{
		RandomNumber = rand()%261;
		
		if(XB_ItemCount[RandomNumber] > 0)
		{
			XB_ItemCount[RandomNumber]--;			
		}
		else
		{
			RandomNumber = 0;
			XB_BurnRandom();
		}
	}
	
	// Return Number for Stage Equipment or EnemyDrops
	if(Mode == 0)
	{
		if(XB_NoEquipment)
		{
			return 0x00;
		}
		
		//if(RandomNumber>=259) printf("XB_GetRandomItem: %s  * Remaining %d\n",XB_ItemNames[RandomNumber],XB_ItemCount[RandomNumber]);
		if(RandomNumber == 259) return 0x17;	// Life Max
		if(RandomNumber == 260) return 0x0C;	// Heart Refresh
		
		RandomNumber = RandomNumber + 0x80;
		//printf("XB_GetRandomItem: %s  * Remaining %d\n",XB_ItemNames[RandomNumber - 0x80],XB_ItemCount[RandomNumber - 0x80]);
		return RandomNumber;
	}
	
	// Return just an Item Number
	if(Mode == 1)
	{
		if(RandomNumber>=259)
			RandomNumber = (rand()%168) + 1;	
		//printf("XB_GetRandomItem: %s  * Remaining %d\n",XB_ItemNames[RandomNumber],XB_ItemCount[RandomNumber]);
		return RandomNumber;
	}
	
	// This should never happen
	return 0;
}

void XB_RandoEquipmentZone(int Offset,int Length)
{
	int Counter = 0;
	fseek(fXEX,Offset,SEEK_SET);
	//printf("Offset:%X\nLength:%X\n",Offset,Length);
	while(Counter<Length)
	{
		// Skip Gold Ring EQ Slot.
		if(ftell(fXEX) == OFS_GOLDRING_EQLIST)
		{
			fseek(fXEX,2,SEEK_CUR);
			Counter++;
		}
		XB_Write_u16_be(XB_GetRandomItem(0));
		Counter++;
	}
}

void XB_RandoEquipmentFixKeyItems()
{
	if(strcmp(XB_PresetName,"O.G.")==0 || strcmp(XB_PresetName,"Guarded O.G.")==0)
	{
		fseek(fXEX,EQ_SILVERRING,SEEK_SET);XB_Write_u16_be(0x172);
		fseek(fXEX,EQ_GOLDRING,SEEK_SET);XB_Write_u16_be(0x171);
		fseek(fXEX,EQ_SPIKEBREAKER,SEEK_SET);XB_Write_u16_be(0x137);
	}
}

void XB_RandoEquipmentClockTowerBreakables()
{
	int RandomItem;
	//printf("ClockTower Breakables\n");
	fseek(fXEX,EQ_CTBREAK,SEEK_SET);
	for(int n=0;n<4;n++)	{	RandomItem = XB_GetRandomItem(1);	XB_Write_u32_be(RandomItem);	}
	fseek(fXEX,EQ_RCTBREAK,SEEK_SET);
	for(int n=0;n<4;n++)	{	RandomItem = XB_GetRandomItem(1);	XB_Write_u32_be(RandomItem);	}
}

void XB_RandoEquipmentVarious()
{
	int RandomItem;

	fseek(fXEX,0x352376,SEEK_SET);RandomItem = XB_GetRandomItem(1);	XB_Write_u16_be(RandomItem);		// Bone Scimitar Short Sword
	fseek(fXEX,0x35237E,SEEK_SET);RandomItem = XB_GetRandomItem(1);	XB_Write_u16_be(RandomItem);		// Bone Scimitar Red Rust
	
	fseek(fXEX,0x412066,SEEK_SET);RandomItem = XB_GetRandomItem(1);	XB_Write_u16_be(RandomItem);		// Entrance Pot Roast
	fseek(fXEX,0x412A32,SEEK_SET);RandomItem = XB_GetRandomItem(1);	XB_Write_u16_be(RandomItem);		// Entrance Turkey
	
}

void XB_RemoveClockStatue()
{
	fseek(fXEX,0x31623C,SEEK_SET);XB_Write_u32_be(0x60000000);
	fseek(fXEX,0x318EEC,SEEK_SET);XB_Write_u32_be(0x60000000);
}

void XB_DoEquipmentRando()
{
	int Index = 0;

	XB_RandoEquipmentVarious();
	
	while(EquipmentLists[Index]!=0)
	{
		//printf("%s\n",sEquipmentZone[Index]);
		XB_RandoEquipmentZone(EquipmentLists[Index],EquipmentListsLength[Index]);
		Index++;
	}
	XB_RandoEquipmentFixKeyItems();
	XB_RandoEquipmentClockTowerBreakables();
	LogMsg("Equipment Randomized!");
}

void XB_DoDropsRando()
{
	int RareDrop,UncommonDrop;
	int Index = 0;
	
	fseek(fXEX,OFS_ENEMYDEFS,SEEK_SET);
	
	printf("Enemy Drops:\n");
	
	while(Index<398)
	{
		// Read Previous Item Drops
		fseek(fXEX,OFS_ENEMYDEFS + (Index*0x24) + 0x16,SEEK_SET);
		RareDrop = XB_Read_u16_be();
		UncommonDrop = XB_Read_u16_be();
		
		// If Item Drops Exist, Apply Random
		fseek(fXEX,OFS_ENEMYDEFS + (Index*0x24) + 0x16,SEEK_SET);
		if(RareDrop)	XB_Write_u16_be(XB_GetRandomItem(0));
		fseek(fXEX,OFS_ENEMYDEFS + (Index*0x24) + 0x18,SEEK_SET);
		if(UncommonDrop)	XB_Write_u16_be(XB_GetRandomItem(0));
		
		if(XB_BoostDropRates)
		{
			fseek(fXEX,OFS_ENEMYDEFS + (Index*0x24) + 0x1A,SEEK_SET);
			XB_Write_u16_be(16);XB_Write_u16_be(32);		
		}
		
		// For Testing, Very High Drop Rates
		//fseek(fXEX,OFS_ENEMYDEFS + (Index*0x24) + 0x1A,SEEK_SET);
		//XB_Write_u16_be(32);XB_Write_u16_be(64);	
			
		Index++;
	}
	
	// Axe Knight Sub Weapon
	Index = (rand()%10) + 0xE;
	fseek(fXEX,OFS_ENEMYDEFS + (6 * 0x24) + 0x18,SEEK_SET);	XB_Write_u16_be(Index);
	fseek(fXEX,OFS_ENEMYDEFS + (246 * 0x24) + 0x18,SEEK_SET);	XB_Write_u16_be(Index);
	
	LogMsg("Drops Randomized!");
	if(XB_BoostDropRates) LogMsg("Drop Rates Boosted!");
}

void XB_WriteEntity(int offsetx, int offsety, unsigned char *data)
{
	fseek(fXEX,offsetx,SEEK_SET);	for(int i=0;i<10;i++)	{	fputc(data[i],fXEX);	}
	fseek(fXEX,offsety,SEEK_SET);	for(int i=0;i<10;i++)	{	fputc(data[i],fXEX);	}
}

int BH_HintOfs[5] = { 0x2057C0, 0x205798, 0x205770, 0x205748, 0x205720 };
int BH_CardTitleOfs[5] = { 0x2057DC, 0x2057B4, 0x20578C, 0x205764, 0x20573C };
char BH_CardTitles[5][20] = { "Heart Card", "Tooth Card", "Rib Card", "Ring Card", "Eye Card" };
int BH_BaseTargets[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x01,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x01,0x00,0x01,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x01,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x01,0x01,0x00,0x01,0x01,0x01,0x01,0x00,0x01,0x00,0x01,0x01,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x01,0x00,0x01,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
char BH_EnemyNames[400][20] = { "Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","AXE KNIGHT","Unnamed","Unnamed","SWORD LORD","Unnamed","SKELERANG","Unnamed","BLOODY ZOMBIE","FLYING ZOMBIE","FLYING ZOMBIE","DIPLOCEPHALUS","Unnamed","Unnamed","Unnamed","OWL KNIGHT","Unnamed","OWL","LESSER DEMON","Unnamed","Unnamed","Unnamed","MERMAN","Unnamed","MERMAN","Unnamed","GORGON","Unnamed","Unnamed","ARMOR LORD","Unnamed","Unnamed","BLACK PANTHER","DARK OCTOPUS","Unnamed","FLEA MAN","FLEA ARMOR","Unnamed","WHITE DRAGON","Unnamed","BONE ARK","BONE ARK","Unnamed","FLEA RIDER","MARIONETTE","OLROX","Unnamed","Unnamed","Unnamed","Unnamed","OLROX","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","WERESKELETON","Unnamed","Unnamed","BAT","LARGE SLIME","SLIME","PHANTOM SKULL","FLAIL GUARD","Unnamed","BLOOD SKELETON","HELLFIRE BEAST","Unnamed","Unnamed","Unnamed","SKELETON","Unnamed","DISCUS LORD","DISCUS LORD","FIRE DEMON","Unnamed","SPITTLE BONE","Unnamed","SKELETON APE","Unnamed","STONE ROSE","Unnamed","Unnamed","ECTOPLASM","Unnamed","BONE PILLAR","Unnamed","Unnamed","SPEAR GUARD","Unnamed","Unnamed","Unnamed","PLATE LORD","Unnamed","FROZEN SHADE","Unnamed","Unnamed","BONE MUSKET","Unnamed","DODO BIRD","BONE SCIMITAR","TOAD","FROG","BONE ARCHER","Unnamed","ZOMBIE","GRAVE KEEPER","Unnamed","TOMBSTONE","BLUE RAVEN","BLACK CROW","JACK O'BONES","Unnamed","BONE HALBERD","Unnamed","YORICK","SKULL","BLADE MASTER","Unnamed","BLADE SOLDIER","Unnamed","NOVA SKELETON","Unnamed","WINGED GUARD","SPECTRAL SWORD","POLTERGEIST","LOSSOTH","Unnamed","VALHALLA KNIGHT","Unnamed","Unnamed","SPECTRAL SWORD ","PUPPET SWORD","SPECTRAL SWORD","SPEAR","SHIELD","OROBOUROUS","ORUBUROS","ORUBUROS RIDER","DRAGON RIDER","DRAGON RIDER","DHURON","Unnamed","FIRE WARG","Unnamed","Unnamed","WARG RIDER","Unnamed","CAVE TROLL","Unnamed","Unnamed","GHOST","THORNWEED","CORPSEWEED","CORPSEWEED","Unnamed","VENUS WEED","VENUS WEED","Unnamed","Unnamed","BOMB KNIGHT","Unnamed","ROCK KNIGHT","Unnamed","DRACULA","Unnamed","Unnamed","GREATER DEMON","Unnamed","Unnamed","WARG","Unnamed","Unnamed","SLINGER","Unnamed","CORNER GUARD","Unnamed","BITTERFLY","BONE PILLAR","Unnamed","SPIKED BALL","HAMMER","Unnamed","GURKHA","Unnamed","BLADE","Unnamed","Unnamed","OUIJA TABLE","Unnamed","SNIPER OF GOTH","Unnamed","Unnamed","GALAMOTH","GALAMOTH","Unnamed","Unnamed","Unnamed","MINOTAURUS","Unnamed","Unnamed","WEREWOLF","Unnamed","Unnamed","Unnamed","Unnamed","PARANTHROPUS","Unnamed","Unnamed","MUDMAN","Unnamed","GHOST DANCER","FROZEN HALF","Unnamed","Unnamed","Unnamed","SALEM WITCH","Unnamed","Unnamed","AZAGHAL","GREMLIN","Unnamed","HUNTING GIRL","VANDAL SWORD","SALOME","Unnamed","Unnamed","Unnamed","CTULHU","Unnamed","Unnamed","MALACHI","Unnamed","Unnamed","HARPY","Unnamed","Unnamed","Unnamed","SLOGRA","Unnamed","Unnamed","AXE KNIGHT","SPELLBOOK","Unnamed","MAGIC TOME","Unnamed","MAGIC TOME","Unnamed","DOPPLEGANGER10","GAIBON","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","SKULL LORD","LION","Unnamed","TIN MAN","Unnamed","Unnamed","AKMODAN II","Unnamed","Unnamed","Unnamed","CLOAKED KNIGHT","Unnamed","DARKWING BAT","Unnamed","Unnamed","Unnamed","FISHHEAD","Unnamed","Unnamed","KARASUMAN","Unnamed","Unnamed","Unnamed","IMP","BALLOON POD","Unnamed","SCYLLA","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","SCYLLA WYRM","GRANFALOON","GRANFALOON","Unnamed","Unnamed","Unnamed","HIPPOGRYPH","Unnamed","Unnamed","MEDUSA HEAD","MEDUSA HEAD","ARCHER","Unnamed","RICHTER BELMONT","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","SCARECROW","SCHMOO","BEEZELBUB","Unnamed","Unnamed","Unnamed","FAKE TREVOR","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","FAKE GRANT","Unnamed","Unnamed","FAKE SYPHA","Unnamed","Unnamed","Unnamed","Unnamed","SUCCUBUS","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","KILLER FISH","SHAFT","Unnamed","Unnamed","Unnamed","Unnamed","DEATH","Unnamed","Unnamed","Unnamed","Unnamed","DEATH","Unnamed","CERBEROS","Unnamed","Unnamed","MEDUSA","Unnamed","Unnamed","Unnamed","THE CREATURE","Unnamed","DOPPLEGANGER40","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","Unnamed","DRACULA","Unnamed","Unnamed","Unnamed","Unnamed","STONE SKULL","Unnamed","MINOTAUR","Unnamed","Unnamed","WEREWOLF","Unnamed","Unnamed","BLUE VENUS WEED","BLUE VENUS WEED","Unnamed","Unnamed","GUARDIAN","Unnamed","Unnamed","Unnamed" };
int BH_TargetValid[512];
int BH_TargetID[5];

void BH_InitTargetPool()
{
	for(int i=0;i<512;i++)	{	BH_TargetValid[i] = 0;	}	// Initial Wipe
	for(int i=0;i<sizeof(BH_BaseTargets);i++)	{	BH_TargetValid[i] = BH_BaseTargets[i];	}
	
	// Invalid Targets that have Rare Drop assigned.
	BH_TargetValid[89] = 0;	// Unnamed Medusa Head Enemy?
	BH_TargetValid[125] = 0;	// Unnamed with rare drop
	BH_TargetValid[177] = 0;	// Unnamed with rare drop
	
	// Target Dupes handled by special case.
	BH_TargetValid[246] = 0;	// Axe Knight Dupe
	BH_TargetValid[15] = 0;	// Flying Zombie Dupe
	BH_TargetValid[29] = 0;	// Merman Dupe
	BH_TargetValid[159] = 0;	// Corpseweed Dupe
	BH_TargetValid[162] = 0;	// Venus Weed Dupe
	BH_TargetValid[304] = 0;	// Medusa Head Dupe
	BH_TargetValid[393] = 0; 	// Blue Venus Weed
	
	BH_TargetValid[136] = 0;	// Spectral Sword
	BH_TargetValid[138] = 0;	// Spectral Sword
	
	BH_TargetValid[228] = 0;	// Vandal Sword (Not in unpatched XBLA version)
}

void BH_PickTargets()
{
	int rndId = 0;
	int ShowTargets = 1;
	
	BH_InitTargetPool();			// Initialize Target Pool	
	LogMsg("Selecting Targets..");

	for(int i=0;i<5;i++)
	{
		while( BH_TargetValid[rndId] == 0)
		{
			rndId = rand()%512;		// Generate Random IDs until we get a Valid Target.
		}
		
		BH_TargetID[i] = rndId;		// Set Target 'i' to Random ID.
		BH_TargetValid[rndId] = 0;		// Remove from Pool so it can't be selected again.
		rndId = rand()%512;			// Roll another Random ID

	}
	
	// Shows Targets in Console Output
	if(ShowTargets)
		printf("Targets:\n\n%s\n%s\n%s\n%s\n%s\n\n",BH_EnemyNames[BH_TargetID[0]],BH_EnemyNames[BH_TargetID[1]],BH_EnemyNames[BH_TargetID[2]],BH_EnemyNames[BH_TargetID[3]],BH_EnemyNames[BH_TargetID[4]]);

	if(strcmp(XB_PresetName,"Hitman")==0)
	{
		LogMsg("Hitman Targets:");
		for(int i=0;i<5;i++)
		{
			LogMsg(BH_EnemyNames[BH_TargetID[i]]);
		}
	}
}

void BH_ApplyTargets()
{
	int Offset;
	int EnemyId;
	int FoodVladId;
	const int RareIdOffset = 0x16;
	const int RareDropRateOffset = 0x1A;
	const int EnemyDefSize = 0x24;
	char HintText[32];
	
	for(int i=0;i<5;i++)
	{
		FoodVladId = 54 + i;		// 54 is Heart of Vlad
		EnemyId = BH_TargetID[i];
		printf("%s At Offset: %x\n",BH_EnemyNames[BH_TargetID[i]],OFS_ENEMYDEFS + (EnemyId * EnemyDefSize));	// debug
		Offset = OFS_ENEMYDEFS + (EnemyId * EnemyDefSize) + RareIdOffset;
		fseek(fXEX,Offset,SEEK_SET);
		XB_Write_u16_be(FoodVladId + 0x80);
		Offset = OFS_ENEMYDEFS + (EnemyId * EnemyDefSize) + RareDropRateOffset;
		fseek(fXEX,Offset,SEEK_SET);
		XB_Write_u16_be(XB_BountyHunterDropRate);
		
		// If Target Confirmed Mode, Turn off Drops on Target, Write Ptr and Restore Value to Code Patch Offsets.
		
		// Card Title
		Offset = BH_CardTitleOfs[i];
		fseek(fXEX,Offset,SEEK_SET);
		fputs(BH_CardTitles[i],fXEX);
		fputc(0,fXEX);
		
		// Hint Text on Card
		strcpy(HintText,"Target ");
		strcat(HintText,BH_EnemyNames[BH_TargetID[i]]);
		Offset = BH_HintOfs[i];
		fseek(fXEX,Offset,SEEK_SET);
		fputs(HintText,fXEX);
		fputc(0,fXEX);
	}
}

void BH_CopyEnemyRares(int SourceId, int DestId)
{
	const int RareIdOffset = 0x16;
	const int RareDropRateOffset = 0x1A;
	const int EnemyDefSize = 0x24;
	int RareId;
	int RareIdDropRate;
	int Offset;
	
	Offset = OFS_ENEMYDEFS + (SourceId * EnemyDefSize) + RareIdOffset;
	fseek(fXEX,Offset,SEEK_SET);
	RareId = XB_Read_u16_be();
	Offset = OFS_ENEMYDEFS + (SourceId * EnemyDefSize) + RareDropRateOffset;
	fseek(fXEX,Offset,SEEK_SET);
	RareIdDropRate = XB_Read_u16_be();
	
	Offset = OFS_ENEMYDEFS + (DestId * EnemyDefSize) + RareIdOffset;
	fseek(fXEX,Offset,SEEK_SET);
	XB_Write_u16_be(RareId);
	Offset = OFS_ENEMYDEFS + (SourceId * EnemyDefSize) + RareDropRateOffset;
	fseek(fXEX,Offset,SEEK_SET);
	XB_Write_u16_be(RareIdDropRate);
}

void BH_HandleTargetDupes()
{
	for(int i=0;i<5;i++)
	{
		if(BH_TargetID[i] == 6)	// Axe Knight
		{
			BH_CopyEnemyRares(6,246);
		}
		if(BH_TargetID[i] == 14)	// Flying Zombie
		{
			BH_CopyEnemyRares(14,15);
		}
		if(BH_TargetID[i] == 27)	// Merman
		{
			BH_CopyEnemyRares(27,29);
		}
		if(BH_TargetID[i] == 129)	// Spectral Sword
		{
			BH_CopyEnemyRares(129,136);
			BH_CopyEnemyRares(129,138);
		}
		if(BH_TargetID[i] == 158)	// Corpseweed
		{
			BH_CopyEnemyRares(158,159);
		}
		if(BH_TargetID[i] == 161)	// Venus Weed
		{
			BH_CopyEnemyRares(161,162);
		}
		if(BH_TargetID[i] == 303)	// Medusa Head
		{
			BH_CopyEnemyRares(303,304);
		}
		if(BH_TargetID[i] == 392)	// Blue Venus Weed
		{
			BH_CopyEnemyRares(392,393);
		}
		if(BH_TargetID[i] == 45)	// Bone Ark
		{
			BH_CopyEnemyRares(45,46);
		}
		if(BH_TargetID[i] == 141)	// OROBOUROUS
		{
			BH_CopyEnemyRares(141,142);
			BH_CopyEnemyRares(141,143);
		}
	}
}

unsigned char BountyHunter_CodeBlock[] = { 0x48,0x00,0x00,0x08,0x48,0x00,0x00,0x04,0x2B,0x1F,0x00,0x9C,0x40,0x99,0x00,0x70,0x2B,0x1F,0x00,0xBB,0x40,0x98,0x00,0x68,0x3D,0x40,0x83,0x15,0x61,0x4A,0x4E,0xC0,0x39,0x60,0x00,0x00,0x2B,0x0B,0x00,0x7F,0x41,0x9A,0x00,0x44,0x39,0x4A,0x00,0xC0,0x39,0x6B,0x00,0x01,0x80,0x6A,0x00,0x30,0x2B,0x03,0x00,0x00,0x40,0x9A,0xFF,0xE8,0x3D,0x60,0x83,0x14,0x61,0x6B,0xEE,0xC0,0x80,0x6B,0x00,0x00,0x90,0x6A,0x00,0x00,0x80,0x6B,0x00,0x04,0x90,0x6A,0x00,0x04,0x3C,0x60,0x82,0x34,0x60,0x63,0x54,0xE8,0x90,0x6A,0x00,0x2C,0x3B,0xFF,0xFF,0x63,0xB3,0xEA,0x00,0x34,0x38,0x60,0x00,0x40,0x3B,0xE0,0x00,0x00,0x4B,0xAC,0xEE,0xFC,0x60,0x00,0x00,0x00,0x4B,0xAC,0xEE,0xC0,0x60,0x00,0x00,0x00 };
unsigned int BountyHunter_CodeBlock_Ofs = 0x879A00 + 0x4000;

void XB_ApplyBountyHunterPatches()
{
	XB_ApplyReverseLibraryCardPatch();
	
	// Write Main Code Block
	fseek(fXEX,BountyHunter_CodeBlock_Ofs,SEEK_SET);
	fwrite(&BountyHunter_CodeBlock[0],sizeof(BountyHunter_CodeBlock),1,fXEX);
	
	fseek(fXEX,0x34891c + 0x4000,SEEK_SET);		// Hook at 8234891c for BountyHunterItemDrop
	XB_Write_u32_be(0x485310E4);		// Branch 82879A00
	XB_Write_u32_be(0x60000000);		// NOP
		
	BH_PickTargets();
	BH_ApplyTargets();
	BH_HandleTargetDupes();
	
	// Code Patch to give Faerie Scroll and 99 Luck. Code Base Address: 0x8225b200
	fseek(fXEX,0x25F200,SEEK_SET);
	XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
	XB_Write_u32_be(0x38800003);	// li  r4, 3
	XB_Write_u32_be(0x988B494F);	// stb r4, 0x494F(r11)
	XB_Write_u32_be(0x38800063);	// li  r4, 0x63
	XB_Write_u32_be(0x988B4BA3);	// stb r4, 0x4BA3(r11)
	XB_Write_u32_be(0x60000000);	// nop
	XB_Write_u32_be(0x60000000);	// nop
	XB_Write_u32_be(0x60000000);	// nop
	XB_Write_u32_be(0x60000000);	// nop
	
	if(strcmp(XB_PresetName,"Hitman")==0)
	{
		// Code Patch to give Faerie Scroll and 99 Luck. Code Base Address: 0x8225b200
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
		XB_Write_u32_be(0x38800061);	// li  r4, 97
		XB_Write_u32_be(0x988B4BA3);	// stb r4, 0x4BA3(r11)  Luck Stat
		XB_Write_u32_be(0x988B494F);	// stb r4, 0x494F(r11)	Faerie Scroll
		XB_Write_u32_be(0x988B4952);	// stb r4, 0x4952(r11)	Bat Card
		XB_Write_u32_be(0x988B4953);	// stb r4, 0x4953(r11)	Ghost Card
		XB_Write_u32_be(0x988B4954);	// stb r4, 0x4954(r11)	Faerie Card
		XB_Write_u32_be(0x988B4955);	// stb r4, 0x4955(r11)	Demon Card
		XB_Write_u32_be(0x988B4956);	// stb r4, 0x4956(r11)	Sword Card
	}
	
	// Open Demon Card Switch Door
	fseek(fXEX,0xCE3A8C + 4,SEEK_SET);
	XB_Write_u16_be(0);	// Delete Door Entity
	fseek(fXEX,0xCE3E6E + 4,SEEK_SET);
	XB_Write_u16_be(0);	// Delete Door Entity
	fseek(fXEX,0xCE3A82 + 4,SEEK_SET);
	XB_Write_u16_be(0);	// Delete Switch Entity
	fseek(fXEX,0xCE3E64 + 4,SEEK_SET);
	XB_Write_u16_be(0);	// Delete Switch Entity
	
	XB_ApplyDeathOnVacation();
}

// Original code Block, no Air Brake.
unsigned char BatMaster_CodeBlock[] = { 0x48,0x00,0x00,0x0C,0x48,0x00,0x00,0xFC,0x48,0x00,0x01,0x24,0x3E,0x40,0x83,0x17,0x8A,0x72,0x3B,0x3A,0x8A,0xB2,0x3B,0x3B,0x2F,0x15,0x00,0x10,0x41,0x9A,0x00,0xE0,0xA2,0xBF,0x00,0x32,0x2F,0x15,0x00,0x02,0x40,0x9A,0x00,0xD4,0x2F,0x13,0x00,0x10,0x40,0x9A,0x00,0x10,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x40,0x00,0x92,0x9F,0x00,0x0C,0x2F,0x13,0x00,0x30,0x40,0x9A,0x00,0x1C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x20,0x40,0x9A,0x00,0x10,0x3E,0x80,0x00,0x02,0x62,0x94,0xC0,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x60,0x40,0x9A,0x00,0x1C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x40,0x40,0x9A,0x00,0x10,0x3E,0x80,0x00,0x02,0x62,0x94,0xC0,0x00,0x92,0x9F,0x00,0x0C,0x2F,0x13,0x00,0xC0,0x40,0x9A,0x00,0x1C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x80,0x40,0x9A,0x00,0x10,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x40,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x90,0x40,0x9A,0x00,0x1C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x4B,0xD6,0x8B,0x84,0x39,0x6B,0xFF,0xFC,0xB1,0x7F,0x00,0x04,0x3C,0x40,0x83,0x17,0x60,0x42,0x4B,0xC7,0x89,0x62,0x00,0x00,0x1D,0x6B,0x00,0x03,0x39,0x6B,0x00,0x0A,0x3C,0x40,0x82,0xE4,0x60,0x42,0x06,0x44,0xB1,0x62,0x00,0x00,0x4B,0xA5,0xDA,0xCC,0x48,0x00,0x00,0x00 };
unsigned int BatMaster_CodeBlock_Ofs = 0x879A00 + 0x4000;

// Test Version with Air Brakes.
unsigned char BatMaster_CodeBlock_AirBrake[] = { 0x48,0x00,0x00,0x0C,0x48,0x00,0x01,0x14,0x48,0x00,0x01,0x3C,0x3E,0x40,0x83,0x17,0x8A,0x72,0x3B,0x3A,0x8A,0xB2,0x3B,0x3B,0x2F,0x15,0x00,0x10,0x40,0x9A,0x00,0x1C,0xA2,0xBF,0x00,0x32,0x2F,0x15,0x00,0x03,0x40,0x9A,0x00,0x0C,0x3A,0xA0,0x00,0x02,0xB2,0xBF,0x00,0x32,0x48,0x00,0x00,0xE0,0xA2,0xBF,0x00,0x32,0x2F,0x15,0x00,0x02,0x40,0x9A,0x00,0xD4,0x2F,0x13,0x00,0x10,0x40,0x9A,0x00,0x10,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x40,0x00,0x92,0x9F,0x00,0x0C,0x2F,0x13,0x00,0x30,0x40,0x9A,0x00,0x1C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x20,0x40,0x9A,0x00,0x10,0x3E,0x80,0x00,0x02,0x62,0x94,0xC0,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x60,0x40,0x9A,0x00,0x1C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x40,0x40,0x9A,0x00,0x10,0x3E,0x80,0x00,0x02,0x62,0x94,0xC0,0x00,0x92,0x9F,0x00,0x0C,0x2F,0x13,0x00,0xC0,0x40,0x9A,0x00,0x1C,0x3E,0x80,0x00,0x02,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x80,0x40,0x9A,0x00,0x10,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x40,0x00,0x92,0x9F,0x00,0x08,0x2F,0x13,0x00,0x90,0x40,0x9A,0x00,0x1C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x0C,0x3E,0x80,0xFF,0xFD,0x62,0x94,0x80,0x00,0x92,0x9F,0x00,0x08,0x4B,0xD6,0x8B,0x6C,0x39,0x6B,0xFF,0xFC,0xB1,0x7F,0x00,0x04,0x3C,0x40,0x83,0x17,0x60,0x42,0x4B,0xC7,0x89,0x62,0x00,0x00,0x1D,0x6B,0x00,0x03,0x39,0x6B,0x00,0x0A,0x3C,0x40,0x82,0xE4,0x60,0x42,0x06,0x44,0xB1,0x62,0x00,0x00,0x4B,0xA5,0xDA,0xB4,0x48,0x00,0x00,0x00 };

void XB_ApplyBatMasterPatches()
{
	// Write Main Code Block
	fseek(fXEX,BatMaster_CodeBlock_Ofs,SEEK_SET);
	fwrite(&BatMaster_CodeBlock_AirBrake[0],sizeof(BatMaster_CodeBlock_AirBrake),1,fXEX);
	
	fseek(fXEX,0x2D1B2C,SEEK_SET);		// Hook at 822cdb2c for BatFrameUpdate
	XB_Write_u32_be(0x485ABED4);		// Branch 82879A00
	fseek(fXEX,0x2db5f0,SEEK_SET);		// Hook at 822d75f0 for BatFireDamage
	XB_Write_u32_be(0x485A2414);		// Branch 82879A04
	XB_Write_u32_be(0x60000000);		// NOP
	
	fseek(fXEX,0xE44638,SEEK_SET);	fputc(0x03,fXEX);	// Fire of Bat MP Cost is 3 MP
	fseek(fXEX,0xE445FC,SEEK_SET);	fputc(0x06,fXEX);	// Wing Smash MP Cost is 6 MP
	
	fseek(fXEX,0x2D1988,SEEK_SET);	XB_Write_u32_be(0x60000000);	// Fire of Bat startup delay remove
	fseek(fXEX,0x2D1AB8,SEEK_SET);	XB_Write_u32_be(0x60000000);	// Fire of Bat ending delay remove
	
	fseek(fXEX,0x2D0BC4,SEEK_SET);	XB_Write_u16_be(0x7FFF);	// Wing Smash lasts 9 Minutes
	
	fseek(fXEX,0x23ed33,SEEK_SET);	fputc(0xFE,fXEX);	// Echo of Bat Hitbox is Huge pt1
	fseek(fXEX,0x23ed37,SEEK_SET);	fputc(0xFE,fXEX);	// Echo of Bat Hitbox is Huge pt2
	
	fseek(fXEX,0x2D0AAF,SEEK_SET);	fputc(0xC2,fXEX);	// Wings flap during Wing Smash
	
	fseek(fXEX,0x2D06F2,SEEK_SET);	XB_Write_u16_be(0x0000);	// Bat Form costs 0 MP.
	
	// Bat Opens Doors
	fseek(fXEX,0x321163,SEEK_SET);	fputc(0x05,fXEX);	// Standard Red
	fseek(fXEX,0x321173,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x3CD5D3,SEEK_SET);	fputc(0x05,fXEX);	// Outer Wall
	fseek(fXEX,0x3CD5E3,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x3AFA57,SEEK_SET);	fputc(0x05,fXEX);	// Olrox
	fseek(fXEX,0x3AFA67,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x351097,SEEK_SET);	fputc(0x05,fXEX);	// Jewel Door
	fseek(fXEX,0x3510A7,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x48EA5B,SEEK_SET);	fputc(0x05,fXEX);	// Reverse Outer Wall Door
	fseek(fXEX,0x48EA6B,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x49323B,SEEK_SET);	fputc(0x05,fXEX);	// Reverse Olrox Door
	fseek(fXEX,0x49324B,SEEK_SET);	fputc(0x01,fXEX);
}

// Leg Day
unsigned char LegDay_CodeBlock[] = { 0x48,0x00,0x00,0x64,0x48,0x00,0x00,0x10,0x48,0x00,0x00,0x20,0x48,0x00,0x00,0x30,0x48,0x00,0x00,0x40,0x2F,0x0B,0x00,0x00,0x40,0x9A,0x00,0x0C,0xA1,0x7E,0x00,0x32,0x2F,0x0B,0x00,0x03,0x4B,0xAA,0x37,0x40,0x2F,0x0B,0x00,0x00,0x40,0x9A,0x00,0x0C,0xA1,0x7C,0x00,0x32,0x2F,0x0B,0x00,0x03,0x4B,0xB4,0xFB,0x9C,0x2F,0x0B,0x00,0x00,0x40,0x9A,0x00,0x0C,0xA1,0x7F,0x00,0x32,0x2F,0x0B,0x00,0x03,0x4B,0xB3,0x20,0x0C,0x2F,0x0B,0x00,0x00,0x40,0x9A,0x00,0x0C,0xA1,0x7C,0x00,0x32,0x2F,0x0B,0x00,0x03,0x4B,0xAD,0x36,0x38,0x3C,0x80,0x83,0x17,0x38,0x60,0x00,0x03,0x98,0x64,0x49,0x4D,0x3D,0x60,0x83,0x17,0xA0,0x8B,0x3B,0xB4,0x88,0x6B,0x3B,0x3A,0x70,0x63,0x00,0x40,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x0C,0x60,0x84,0x00,0x01,0x48,0x00,0x00,0x08,0x70,0x84,0x00,0xFE,0xB0,0x8B,0x3B,0xB4,0x3D,0x00,0x83,0x15,0x39,0x08,0xEE,0xC0,0xA0,0x68,0x00,0x30,0xA0,0x88,0x00,0x32,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x3C,0x2F,0x04,0x00,0x03,0x40,0x9A,0x00,0x34,0x88,0x68,0x00,0x0A,0x2F,0x03,0x00,0x80,0x40,0x9A,0x00,0x28,0xA0,0x68,0x00,0x08,0x2F,0x03,0x00,0x03,0x41,0x9A,0x00,0x14,0x70,0x63,0x00,0xFC,0x2F,0x03,0x00,0xFC,0x41,0x9A,0x00,0x08,0x48,0x00,0x00,0x0C,0x38,0x60,0x00,0x3C,0x98,0x6B,0x49,0x5D,0x88,0x6B,0x49,0x5D,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0xC0,0x38,0x63,0xFF,0xFF,0x98,0x6B,0x49,0x5D,0x80,0x68,0x00,0x30,0x2F,0x03,0x00,0x03,0x40,0x9A,0x00,0x60,0xA0,0x68,0x00,0x5A,0x2F,0x03,0x00,0x47,0x40,0x9A,0x00,0x1C,0x38,0x60,0x00,0x45,0xB0,0x68,0x00,0x5A,0x38,0x60,0x00,0x04,0xB0,0x68,0x00,0x54,0x38,0x60,0x00,0x03,0xB0,0x68,0x00,0x56,0x88,0x6B,0x49,0x5D,0x2F,0x03,0x00,0x37,0x41,0x98,0x00,0x08,0x48,0x00,0x00,0x0C,0x38,0x60,0x00,0x02,0xB0,0x6B,0x3B,0x6C,0x88,0x68,0x00,0x09,0x2F,0x03,0x00,0x03,0x41,0x9A,0x00,0x0C,0x3C,0x60,0xFF,0xFC,0x48,0x00,0x00,0x08,0x3C,0x60,0x00,0x04,0x90,0x68,0x00,0x08,0x48,0x00,0x00,0x50,0xA0,0x68,0x00,0x30,0x2F,0x03,0x00,0x04,0x40,0x9A,0x00,0x2C,0x88,0x68,0x00,0x15,0x2F,0x03,0x00,0x01,0x41,0x9A,0x00,0x10,0x3C,0x60,0xFF,0xFC,0x90,0x68,0x00,0x08,0x48,0x00,0x00,0x0C,0x3C,0x60,0x00,0x04,0x90,0x68,0x00,0x08,0x38,0x60,0x00,0x00,0x98,0x6B,0x49,0x5D,0x88,0x6B,0x49,0x5D,0x2F,0x03,0x00,0x06,0x41,0x99,0x00,0x08,0x48,0x00,0x00,0x0C,0x38,0x60,0x00,0x06,0x98,0x6B,0x49,0x5D,0x3D,0x60,0x83,0x15,0x4B,0xA4,0xA1,0xB4,0x60,0x00,0x00,0x00 };
unsigned int LegDay_CodeBlock_Ofs = 0x879A00 + 0x4000;

void XB_ApplyLegDayPatches()
{
	// Write Main Code Block
	fseek(fXEX,LegDay_CodeBlock_Ofs,SEEK_SET);
	fwrite(&LegDay_CodeBlock[0],sizeof(LegDay_CodeBlock),1,fXEX);

	fseek(fXEX,0x2c3d64 + 0x4000,SEEK_SET);	// AlucardEntity FrameUpdate Hook
	XB_Write_u32_be( XB_CalcBranch(0x2c3d64,0x879A00 + 0) );	// Jump to Jump Table Entry 0x00.
	
	fseek(fXEX,0x2523B7,SEEK_SET);	fputc(0x00,fXEX);			// CD Room Input Override Patch
	
	// Alternate State Opens Doors
	
	// Standard Red
	fseek(fXEX,0x321158,SEEK_SET);	XB_Write_u32_be(0x60000000);											// Allow any Direction Facing
	fseek(fXEX,0x31d160 + 0x4000,SEEK_SET);		XB_Write_u32_be( XB_CalcBranch(0x31d160,0x879A00 + 4) );	// RedDoor Backdash Hook, Jump Table Entry 0x01
	fseek(fXEX,0x321173,SEEK_SET);	fputc(0x01,fXEX);														// Allow 2nd Step Check for Alucard
	
	// TODO: Debug these Doors, they don't work like red door for some reason.
	/*
	// Outer Wall
	fseek(fXEX,0x3c95c8 + 0x4000,SEEK_SET);	XB_Write_u32_be(0x60000000);									// Allow any Direction Facing
	fseek(fXEX,0x3c95d0 + 0x4000,SEEK_SET);		XB_Write_u32_be( XB_CalcBranch(0x3c95d0,0x879A00 + 8) );	// Outerwall RedDoor Backdash Hook, Jump Table Entry 0x02
	fseek(fXEX,0x3c95e3,SEEK_SET);	fputc(0x01,fXEX);														// Allow 2nd Step Check for Alucard	
	
	// Olrox Door
	fseek(fXEX,0x3aba4c + 0x4000,SEEK_SET);	XB_Write_u32_be(0x60000000);									// Allow any Direction Facing
	fseek(fXEX,0x3aba54 + 0x4000,SEEK_SET);		XB_Write_u32_be( XB_CalcBranch(0x3aba54,0x879A00 + 12) );	// olrox Door Backdash Hook, Jump Table Entry 0x03
	fseek(fXEX,0x3aba67,SEEK_SET);	fputc(0x01,fXEX);														// Allow 2nd Step Check for Alucard	
	
	// Jewel Door
	fseek(fXEX,0x34d08c + 0x4000,SEEK_SET);	XB_Write_u32_be(0x60000000);									// Allow any Direction Facing
	fseek(fXEX,0x34d094 + 0x4000,SEEK_SET);		XB_Write_u32_be( XB_CalcBranch(0x34d094,0x879A00 + 16) );	// Jewel Door Backdash Hook, Jump Table Entry 0x03
	fseek(fXEX,0x34d0a7,SEEK_SET);	fputc(0x01,fXEX);														// Allow 2nd Step Check for Alucard	
	*/
	
	/*
	fseek(fXEX,0x3CD5D3,SEEK_SET);	fputc(0x05,fXEX);	// Outer Wall
	fseek(fXEX,0x3CD5E3,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x3AFA57,SEEK_SET);	fputc(0x05,fXEX);	// Olrox
	fseek(fXEX,0x3AFA67,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x351097,SEEK_SET);	fputc(0x05,fXEX);	// Jewel Door
	fseek(fXEX,0x3510A7,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x48EA5B,SEEK_SET);	fputc(0x05,fXEX);	// Reverse Outer Wall Door
	fseek(fXEX,0x48EA6B,SEEK_SET);	fputc(0x01,fXEX);
	fseek(fXEX,0x49323B,SEEK_SET);	fputc(0x05,fXEX);	// Reverse Olrox Door
	fseek(fXEX,0x49324B,SEEK_SET);	fputc(0x01,fXEX);
	*/
}


unsigned char Richter_CodeBlock[] = { 0x48,0x00,0x00,0x84,0x48,0x00,0x00,0x08,0x48,0x00,0x00,0x40,0x3C,0x60,0x83,0x17,0x80,0x63,0x3B,0x3C,0x70,0x63,0x00,0x20,0x2F,0x03,0x00,0x20,0x40,0x9A,0x00,0x24,0x3C,0x60,0x83,0x17,0x80,0x63,0x3B,0x38,0x70,0x63,0x10,0x0C,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x10,0x38,0x60,0x00,0x03,0xB0,0x6B,0x00,0x00,0xB0,0x6B,0x00,0x02,0xA1,0x4B,0x00,0x00,0x4B,0xA3,0x19,0xBC,0x3C,0x60,0x83,0x17,0x80,0x63,0x3B,0x3C,0x70,0x63,0x00,0x20,0x2F,0x03,0x00,0x20,0x40,0x9A,0x00,0x24,0x3C,0x60,0x83,0x17,0x80,0x63,0x3B,0x38,0x70,0x63,0x10,0x00,0x2F,0x03,0x10,0x00,0x40,0x9A,0x00,0x10,0x38,0x60,0x00,0x02,0xB0,0x7F,0x00,0x04,0xB0,0x7F,0x00,0x06,0xA1,0x7F,0x00,0x04,0x4B,0xA3,0x1A,0xC4,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x47,0x70,0x63,0x00,0x01,0x2F,0x03,0x00,0x01,0x40,0x9A,0x00,0x68,0x3D,0x40,0x82,0xA3,0xA0,0x6A,0x0D,0xC2,0xB0,0x6A,0x0D,0xC0,0xA0,0x6A,0x0E,0x62,0xB0,0x6A,0x0E,0x60,0xA0,0x6A,0x0F,0x02,0xB0,0x6A,0x0F,0x00,0xA0,0x6A,0x0F,0xA2,0xB0,0x6A,0x0F,0xA0,0x3D,0x40,0x82,0xA3,0x39,0x4A,0x7F,0x10,0x38,0x60,0x00,0x00,0xB0,0x6A,0x00,0x00,0xB0,0x6A,0x00,0xA0,0xB0,0x6A,0x01,0x40,0xB0,0x6A,0x01,0xE0,0x3D,0x40,0x82,0xA7,0x39,0x4A,0xF7,0x60,0x38,0x60,0x01,0xBC,0xB0,0x6A,0x00,0x00,0x38,0x60,0x03,0x06,0xB0,0x6A,0x00,0xA0,0x38,0x60,0x02,0x66,0xB0,0x6A,0x01,0x40,0x48,0x00,0x00,0x70,0x3D,0x40,0x82,0xA3,0x38,0x60,0x04,0x58,0xB0,0x6A,0x0D,0xC0,0x38,0x63,0x00,0x01,0xB0,0x6A,0x0E,0x60,0x38,0x63,0x00,0x01,0xB0,0x6A,0x0F,0x00,0x38,0x63,0x00,0x01,0xB0,0x6A,0x0F,0xA0,0x3D,0x40,0x82,0xA3,0x39,0x4A,0x7F,0x10,0x38,0x60,0x00,0x1A,0xB0,0x6A,0x00,0x00,0x38,0x63,0x00,0x01,0xB0,0x6A,0x00,0xA0,0x38,0x63,0x00,0x01,0xB0,0x6A,0x01,0x40,0x38,0x63,0x00,0x01,0xB0,0x6A,0x01,0xE0,0x3D,0x40,0x82,0xA7,0x39,0x4A,0xF7,0x60,0x38,0x60,0x03,0x1E,0xB0,0x6A,0x00,0x00,0x38,0x60,0x03,0x20,0xB0,0x6A,0x00,0xA0,0x38,0x60,0x03,0x21,0xB0,0x6A,0x01,0x40,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x42,0x70,0x63,0x00,0x01,0x2F,0x03,0x00,0x01,0x40,0x9A,0x00,0x40,0x3D,0x60,0x83,0x13,0x81,0x6B,0x3A,0xEC,0x2F,0x0B,0x00,0x03,0x40,0x9A,0x00,0x30,0x3D,0x60,0x83,0x18,0x39,0x6B,0x6E,0x08,0x80,0x6B,0x00,0x00,0x2F,0x03,0x00,0x29,0x40,0x9A,0x00,0x1C,0x80,0x6B,0x00,0x04,0x2F,0x03,0x00,0x32,0x40,0x9A,0x00,0x10,0x3D,0x60,0x83,0x15,0x38,0x60,0x00,0x02,0xB0,0x6B,0x36,0xF0,0x3D,0x60,0x83,0x17,0x38,0x60,0x00,0x01,0x98,0x6B,0x46,0x82,0x3D,0x60,0x83,0x17,0x88,0x6B,0x4A,0x1D,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x0C,0x38,0x60,0x00,0x0E,0x90,0x6B,0x4B,0xE8,0x3D,0x60,0x83,0x17,0x88,0x6B,0x4A,0x31,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x24,0x3D,0x60,0x82,0x8B,0x39,0x6B,0x61,0x22,0x38,0x60,0x00,0x02,0xB0,0x6B,0x00,0x00,0xB0,0x6B,0x02,0x00,0xB0,0x6B,0x01,0x00,0xB0,0x6B,0x03,0x00,0x48,0x00,0x00,0x24,0x3D,0x60,0x82,0x8B,0x39,0x6B,0x61,0x22,0x38,0x60,0x05,0x2D,0xB0,0x6B,0x00,0x00,0xB0,0x6B,0x02,0x00,0x38,0x63,0x00,0x02,0xB0,0x6B,0x01,0x00,0xB0,0x6B,0x03,0x00,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x4F,0x2F,0x03,0x00,0x00,0x41,0x99,0x00,0x10,0x88,0x6B,0x4A,0x0C,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0xA8,0x80,0x6B,0x3B,0x38,0x70,0x63,0x00,0x0C,0x2F,0x03,0x00,0x0C,0x40,0x9A,0x00,0x98,0x80,0x6B,0x3B,0x3C,0x70,0x63,0x00,0x20,0x2F,0x03,0x00,0x20,0x40,0x9A,0x00,0x88,0x3D,0x60,0x83,0x15,0x39,0x6B,0x12,0xC0,0xA0,0x6B,0x00,0x28,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x74,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x60,0x3D,0x60,0x83,0x15,0x39,0x6B,0x12,0xC0,0x38,0x60,0x00,0x42,0xB0,0x6B,0x00,0x28,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x4F,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x10,0x88,0x6B,0x4A,0x0C,0x38,0x63,0xFF,0xFF,0x98,0x6B,0x4A,0x0C,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0x3C,0x60,0x82,0xDF,0x38,0x63,0xE2,0xD0,0x90,0x6B,0x00,0x50,0x38,0x60,0x00,0x00,0x90,0x6B,0x00,0x54,0x38,0x60,0x00,0xFF,0xB0,0x6B,0x00,0x30,0x3D,0x60,0x83,0x17,0x38,0x60,0x01,0xE0,0xB0,0x6B,0x3B,0x6C,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0xFF,0x40,0x9A,0x00,0x24,0x3D,0x60,0x83,0x17,0xA0,0x6B,0x3B,0x6C,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x14,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0x38,0x60,0x00,0x00,0xB0,0x6B,0x00,0x30,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x48,0x70,0x63,0x00,0x01,0x2F,0x03,0x00,0x01,0x40,0x9A,0x00,0x24,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x0A,0x40,0x9A,0x00,0x10,0x3D,0x60,0x83,0x17,0x38,0x60,0x00,0x20,0xB0,0x6B,0x3B,0x6C,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x45,0x70,0x63,0x00,0x01,0x2F,0x03,0x00,0x01,0x40,0x9A,0x00,0x30,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x18,0x40,0x9A,0x00,0x1C,0xA0,0x6B,0x00,0x54,0x2F,0x03,0x00,0x11,0x40,0x9A,0x00,0x10,0x3D,0x60,0x83,0x17,0x38,0x60,0x00,0x10,0xB0,0x6B,0x3B,0x6C,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x46,0x70,0x63,0x00,0x01,0x2F,0x03,0x00,0x01,0x40,0x9A,0x00,0x2C,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x18,0x40,0x9A,0x00,0x18,0xA0,0x6B,0x00,0x54,0x2F,0x03,0x00,0x12,0x40,0x9A,0x00,0x0C,0x38,0x60,0x00,0x18,0xB0,0x6B,0x00,0x54,0x3D,0x60,0x83,0x17,0x89,0x4B,0x49,0x67,0x39,0x4A,0x00,0x01,0x2F,0x0A,0x00,0x2A,0x41,0x98,0x00,0x08,0x39,0x40,0x00,0x01,0x99,0x4B,0x49,0x67,0x39,0x6B,0x49,0x83,0x88,0x6B,0x00,0x00,0x7D,0x6B,0x52,0x14,0x88,0x8B,0x00,0x00,0x7C,0x63,0x22,0x14,0x38,0x80,0x00,0x00,0x98,0x8B,0x00,0x00,0x3D,0x60,0x83,0x17,0x39,0x6B,0x49,0x83,0x2F,0x03,0x01,0x00,0x41,0x98,0x00,0x08,0x38,0x60,0x00,0xFF,0x98,0x6B,0x00,0x00,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x10,0x41,0x9A,0x00,0xD0,0x2F,0x03,0x00,0x16,0x41,0x9A,0x00,0xC8,0x3D,0x60,0x83,0x17,0x80,0x6B,0x3B,0x38,0x70,0x63,0x10,0x00,0x2F,0x03,0x10,0x00,0x40,0x9A,0x00,0xB4,0x80,0x6B,0x3B,0x3C,0x70,0x63,0x00,0x02,0x2F,0x03,0x00,0x02,0x40,0x9A,0x00,0xA4,0x80,0x6B,0x4B,0x7C,0x80,0x8B,0x4B,0x80,0x7F,0x04,0x18,0x00,0x41,0x9A,0x00,0x94,0x3D,0x60,0x83,0x17,0x88,0x6B,0x49,0x83,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x84,0x38,0x63,0xFF,0xFF,0x98,0x6B,0x49,0x83,0x80,0x6B,0x4B,0x7C,0x38,0x63,0x00,0x0A,0x80,0x8B,0x4B,0x80,0x7F,0x04,0x18,0x00,0x41,0x99,0x00,0x08,0x7C,0x83,0x23,0x78,0x90,0x6B,0x4B,0x7C,0x38,0x80,0x00,0x00,0x3D,0x60,0x83,0x15,0x39,0x6B,0x4E,0xC0,0x80,0x6B,0x00,0x2C,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x18,0x39,0x6B,0x00,0xC0,0x38,0x84,0x00,0x01,0x2F,0x04,0x00,0x7E,0x41,0x9A,0x00,0x38,0x4B,0xFF,0xFF,0xE4,0x3D,0x40,0x82,0x2E,0x39,0x4A,0xC2,0x60,0x91,0x4B,0x00,0x2C,0x3D,0x40,0x00,0x01,0x39,0x4A,0x00,0x0A,0x91,0x4B,0x00,0x84,0x3D,0x40,0x83,0x15,0x39,0x4A,0xEE,0xC0,0x80,0x6A,0x00,0x00,0x90,0x6B,0x00,0x00,0x80,0x6A,0x00,0x04,0x90,0x6B,0x00,0x04,0x3D,0x60,0x83,0x17,0x89,0x4B,0x49,0x54,0x88,0x8B,0x49,0x57,0x7D,0x4A,0x23,0x78,0x2F,0x0A,0x00,0x00,0x41,0x9A,0x00,0xB0,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0xA0,0x6B,0x00,0x30,0x2F,0x03,0x00,0x10,0x40,0x9A,0x00,0x9C,0xA0,0x6B,0x00,0x32,0x2F,0x03,0x00,0x02,0x40,0x9A,0x00,0x90,0x3D,0x40,0x83,0x17,0x88,0x6A,0x49,0xF8,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x80,0x38,0x63,0xFF,0xFF,0x98,0x6A,0x49,0xF8,0x38,0x60,0x00,0x16,0xB0,0x6B,0x00,0x30,0x38,0x60,0x00,0x01,0xB0,0x6B,0x00,0x32,0x38,0x60,0x00,0x00,0x90,0x6B,0x00,0x08,0x90,0x6B,0x00,0x0C,0x38,0x80,0x00,0x00,0x3D,0x60,0x83,0x15,0x39,0x6B,0xEE,0xC0,0x39,0x6B,0x0C,0x00,0x80,0x6B,0x00,0x2C,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x2C,0x39,0x6B,0x00,0xC0,0x38,0x84,0x00,0x01,0x2F,0x04,0x00,0x3E,0x41,0x9A,0x00,0x08,0x4B,0xFF,0xFF,0xE4,0x3D,0x40,0x83,0x17,0x88,0x6A,0x49,0xF8,0x38,0x63,0x00,0x01,0x98,0x6A,0x49,0xF8,0x48,0x00,0x00,0x18,0x39,0x40,0x00,0x1B,0xB1,0x4B,0x00,0x28,0x3D,0x40,0x83,0x17,0x38,0x60,0x00,0x40,0x98,0x6A,0x49,0x68,0x3D,0x60,0x83,0x17,0x88,0x6B,0x3B,0x6B,0x2F,0x03,0x00,0x03,0x40,0x9A,0x00,0x24,0x3D,0x40,0x83,0x17,0x88,0x6A,0x49,0x68,0x38,0x63,0xFF,0xFF,0x98,0x6A,0x49,0x68,0x2F,0x03,0x00,0x00,0x40,0x9A,0x00,0x0C,0x38,0x60,0x00,0x00,0x98,0x6B,0x3B,0x6B,0x3D,0x60,0x83,0x17,0x39,0x6B,0x46,0x40,0x38,0x60,0x00,0x01,0x98,0x6B,0x00,0x72,0xA1,0x7E,0x00,0x30,0x4B,0xA3,0x1A,0xD4 };
unsigned int Richter_CodeBlock_Ofs = 0x879A00 + 0x4000;

unsigned char Richter_PAL_Green[] = 		{ 0x00,0x00,0x80,0x00,0xB1,0x85,0xC2,0x10,0xD2,0x94,0xF3,0x9C,0xAA,0x80,0x80,0x80,0x80,0xAC,0x95,0x56,0xB2,0x1C,0xC2,0x9C,0xD3,0x3C,0x81,0x94,0x81,0x80,0xFC,0x1F };
unsigned char Richter_PAL_unk[] = 	{ 0x00,0x00,0x80,0x13,0x81,0xBF,0x82,0x5F,0x97,0x5F,0xD7,0xFF,0x81,0xDF,0x98,0xCF,0x80,0x17,0x81,0x9F,0x82,0x1F,0x83,0x7F,0xA6,0xDF,0x81,0x9F,0x80,0x1F,0x80,0x00 };

unsigned char Richter_PAL_Bad[] = 	{ 0x00,0x00,0x80,0xff,0xff,0xfF,0x82,0x5F,0x97,0x5F,0xD7,0xFF,0x81,0xff,0x98,0xCF,0xff,0xff,0xff,0xff,0xff,0x1F,0x83,0x7F,0xA6,0xDF,0x81,0xfF,0xff,0xfF,0x8f,0xff };

void XB_RichterPalette()
{
	// Richter Palette may be in f_game2.bin inside of fonts.zip
	// If this is true that makes patching it very annoying.
	/*
	fseek(fXEX,0xDEBC08,SEEK_SET);
	fwrite(&Richter_PAL_Green[0],0x20,1,fXEX);
	
	fseek(fXEX,0xDEBC28,SEEK_SET);
	fwrite(&Richter_PAL_Green[0],0x20,1,fXEX);
	
	fseek(fXEX,0xCCB120,SEEK_SET);
	fwrite(&Richter_PAL_Green[0],0x20,1,fXEX);

	fseek(fXEX,0xDEBD68,SEEK_SET);
	fwrite(&Richter_PAL_Green[0],0x20,1,fXEX);	
	
	fseek(fXEX,0xDEBE88,SEEK_SET);
	fwrite(&Richter_PAL_Green[0],0x20,1,fXEX);
	*/	
	
	
	//LogMsg("Ric Pal Green");
}

void XB_ApplyRichterPatches()
{
	// Write Main Code Block
	fseek(fXEX,Richter_CodeBlock_Ofs,SEEK_SET);
	fwrite(&Richter_CodeBlock[0],sizeof(Richter_CodeBlock),1,fXEX);
	
	fseek(fXEX,0x2ab3fc + 0x4000,SEEK_SET);	// Blade Dash Input Hook
	XB_Write_u32_be( XB_CalcBranch(0x2ab3fc,0x879A00 + 4) );	// Jump to Jump Table Entry 0x01.
	
	fseek(fXEX,0x2ab540 + 0x4000,SEEK_SET);	// Blade Dash Input Hook
	XB_Write_u32_be( XB_CalcBranch(0x2ab540,0x879A00 + 8) );	// Jump to Jump Table Entry 0x02.
	
	fseek(fXEX,0x2ABAD8 + 0x4000,SEEK_SET);	// Frame Update Hook
	XB_Write_u32_be( XB_CalcBranch(0x2ABAD8,0x879A00 + 0) );	// Jump to Jump Table Entry 0x00.
	
	
	fseek(fXEX,0x39994B,SEEK_SET);
	fputc(0x01,fXEX);					// Force Richter as Character
	fseek(fXEX,0x25F8F4,SEEK_SET);
	XB_Write_u32_be(0x60000000);		// Don't Give all Relics
	fseek(fXEX,0x25F934,SEEK_SET);
	XB_Write_u32_be(0x60000000);		// Don't turn on Faerie Scroll
	fseek(fXEX,0x25F93C,SEEK_SET);
	XB_Write_u32_be(0x60000000);		// Don't turn on Jewel of Open
	fseek(fXEX,0x34772C,SEEK_SET);
	XB_Write_u32_be(0x39600000);		// Spawn Items from Enemys and Throughout Castle
	
	fseek(fXEX,0x2AF514,SEEK_SET);
	XB_Write_u32_be(0x716B00A0);		// Blade Dash with X or B
	fseek(fXEX,0x2AF58C,SEEK_SET);
	XB_Write_u32_be(0x716B0060);		// High Jump with A or B
	
	fseek(fXEX,0x40A048,SEEK_SET);
	XB_Write_u16_be(0x4800);			// Richter can use Shop
	
	fseek(fXEX,0x25FAC8,SEEK_SET);XB_Write_u32_be(0x60000000);		// Succubus Time Attack
	fseek(fXEX,0x25FAF8,SEEK_SET);XB_Write_u32_be(0x60000000);		// Minotaur & Werewolf Time Attack
	fseek(fXEX,0x25FB58,SEEK_SET);XB_Write_u32_be(0x60000000);		// Death Time Attack
	
	fseek(fXEX,0x46BC04,SEEK_SET);XB_Write_u32_be(0x39400004);		// True Dracula does Richter Ending
	fseek(fXEX,0x4C1ABC,SEEK_SET);XB_Write_u16_be(0x4800);			// Go to True Dracula after killing Shaft
	
	fseek(fXEX,0x30E868,SEEK_SET);XB_Write_u16_be(0x4800);			// Vlads drop from Blue Swirl for Richter too. aka Blue Swirl behaves like you're Alucard.
	fseek(fXEX,0x4386FC,SEEK_SET);XB_Write_u16_be(0x4800);			// Succubus Dialog Skip

	fseek(fXEX,0xD8D96C,SEEK_SET);XB_Write_u32_be(0x82D72698);		// Fix Iced Richter Frame for Ending
	
	
	XB_RichterPalette();	// May require editing fonts.zip?
	
	// TODO:
	// Does Echo Work to Escape Spikebreaker?
	// Maybe alter Heart Count Display to be able to display Food Count? Or Vlad Count?
	// Or look into Drawing Primitive Allocation to be able to draw shit ourselves?
}

void XB_PresetWrites()
{
	strcpy(XB_LocationSet,"Guarded");
	
	// New Code Patch Area for Player Init
	// XEX 0x25F4C8, RAM 8225b4c8
	// Size available is 0xD4 or 53 Words.
	// This would allow for much more instructions for setup of the seed.
	// This Code is the Code that checks for entering of the [ x-x!v''q ] code for Luck Mode and then [ axearmor ]
	// By overwriting this you can't play Luck Mode or get AxeArmor but I think that's ok.
	
	if(strcmp(XB_PresetName,"Bingo")==0)
	{
		LogMsg("Vanilla Clock Door for Bingo.");
	}
	else
	{
		XB_WritePatch(0x3163BC,&XB_PATCHCLOCKROOMOPEN[0],sizeof(XB_PATCHCLOCKROOMOPEN));	// Gold Ring & Silver Ring in Inventory, not equipped, to open door. Prevents opening with two of the same ring.
		fseek(fXEX,0x347AD0,SEEK_SET);	XB_Write_u32_be(0x60000000);							// Entity 0xA doesn't expire. To prevent key items from despawning such as at spirit orb.		
	}

	
	fseek(fXEX,OFS_SHOPLIST + 6,SEEK_SET); XB_Write_u16_be(0);	// Shop Relic Free.
	
	if(strcmp(XB_PresetName,"O.G.")==0 || strcmp(XB_PresetName,"Guarded O.G.")==0)	// Restore Entities
	{
		XB_WriteEntity(OFS_X_HOLYGLASSES,OFS_Y_HOLYGLASSES,&OG_HOLYGLASSES[0]);
		XB_WriteEntity(OFS_X_GOLDRING,OFS_Y_GOLDRING,&OG_GOLDRING[0]);
		XB_WriteEntity(OFS_X_SILVERRING,OFS_Y_SILVERRING,&OG_SILVERRING[0]);
		XB_WriteEntity(OFS_X_SPIKEBREAKER,OFS_Y_SPIKEBREAKER,&OG_SPIKEBREAKER[0]);
	}

	if(strcmp(XB_PresetName,"Bounty Hunter")==0 || strcmp(XB_PresetName,"Hitman")==0)
	{
		// TODO: Remove Marble Gallery Jewel Door for Hitman.
		XB_BountyHunterDropRate = 16;
		if(strcmp(XB_PresetName,"Hitman")==0)
		{
			fseek(fXEX,0xE44281,SEEK_SET);		// Ring of Arcana +30 Luck Boost
			fputc(0x1E,fXEX);
			
			XB_BountyHunterDropRate = 0x3FFF;
		}

		
		XB_ApplyBountyHunterPatches();
		XB_SetStartingRH(168);		// Alucart Sword
		XB_SetStartingLH(167);		// Alucart Shield
		XB_SetStartingHelm(214);	// Dragon Helm
		XB_SetStartingArmor(258);	// Alucard Mail
		XB_SetStartingCape(225);	// Twilight Cloak
		XB_SetStartingAcc(244);		// Ring of Arcana
		
		fseek(fXEX,OFS_PROLOGUEREWARD_NEUTRONBOMB,SEEK_SET);
		XB_Write_u16_be(166);	// Library Card
	}
	
	if(strcmp(XB_PresetName,"Bat Master")==0)
	{
		strcpy(XB_LocationSet,"Spread");
		XB_MinimumComplexity = 1;
		XB_ApplyBatMasterPatches();
	}
	
	if(strcmp(XB_PresetName,"LegDay")==0)
	{
		XB_MinimumComplexity = 1;
		XB_ApplyLegDayPatches();
	}
	
	// We can write maybe 7 entities, skip one, then write two more.. <-- Old Entity Method note, now we use a code stub in character init function.
	if(strcmp(XB_PresetName,"Nimble")==0 || strcmp(XB_PresetName,"Expedition")==0)
	{
		XB_MinimumComplexity = 6;	// <-- this isn't where we set complexity anymore.
		
		if(strcmp(XB_PresetName,"Expedition")==0)
		{
			XB_ApplyReverseLibraryCardPatch();
			XB_MinimumComplexity = 7;
		}
			
		
		XB_SetStartingRH(162);		// Manna Prism
		XB_SetStartingLH(77);		// Buffalo Star
		XB_SetStartingHelm(214);	// Dragon Helm
		XB_SetStartingArmor(184);	// Alucard Mail
		XB_SetStartingCape(225);	// Twilight Cloak
		XB_SetStartingAcc(253);		// Duplicator
		
		// Create Entities to give stuff OLD
		/*
		fseek(fXEX,OFS_BONUSSTUFF,SEEK_SET);
		XB_Write_Entity(0x80,0x290,0xA,0x10,253);	// Dupe
		XB_Write_Entity(0x100,0x290,0xA,0x11,77);	// Buffalo
		XB_Write_Entity(0x110,0x290,0xA,0x12,162);	// Manna Prism
		XB_Write_Entity(0x120,0x290,0xB,0x13,0);	// Soul of Bat
		XB_Write_Entity(0x120,0x290,0xB,0x14,0xC);	// Gravity
		XB_Write_Entity(0x120,0x290,0xB,0x15,0xD);	// Leap
		*/
		// Code Patch to give Soul of Bat, Gravity Boots, and Leap Stone. Code Base Address: 0x8225b200
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
		XB_Write_u32_be(0x38800003);	// li  r4, 3
		XB_Write_u32_be(0x988B4940);	// stb r4, 0x4940(r11)
		XB_Write_u32_be(0x988B494C);	// stb r4, 0x494c(r11)
		XB_Write_u32_be(0x988B494D);	// stb r4, 0x494d(r11)
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
	}

	if(strcmp(XB_PresetName,"Glitch")==0)
	{
		strcpy(XB_LocationSet,"Equipment");
		// Glitch TODO:
		// Sync Bat Card Room Entity and the Bigger Room that includes it but isn't normally accessible.
		// This is important for the RSL glitch into Bat Card.
		// ^ Done I think.
		
		// Place Stopwatch in Clock Room
		fseek(fXEX,0xD575BA + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		fseek(fXEX,0xD58492 + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		
		// Prologue Rewards
		fseek(fXEX,OFS_PROLOGUEREWARD_HEARTREFRESH,SEEK_SET);
		XB_Write_u16_be(134);	// Fire Boomerang
		fseek(fXEX,OFS_PROLOGUEREWARD_NEUTRONBOMB,SEEK_SET);
		XB_Write_u16_be(166);	// Library Card
		
		// Prologue Reward Requirements don't matter
		fseek(fXEX,0x25F2A4,SEEK_SET);	// Heart Refresh
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		fseek(fXEX,0x25F2FC,SEEK_SET);	// Neutron Bomb
		XB_Write_u32_be(0x60000000);	// nop
		
		// Addition Adds, using Maria Potion Instruction Space. This is just adding Axe Lord Armor right now.
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x60000000);	// nop					* li r4,x (type)
		XB_Write_u32_be(0x60000000);	// nop					* li r3,x (id #)
		XB_Write_u32_be(0x60000000);	// nop					* If Desired, we can call the AddItem Function here with a write of 0x4BFFB529 ( bl 0x82256730 )
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x38800002);	// lis r4, 0x02
		XB_Write_u32_be(0x38600019);	// li  r3, 0x19
		XB_Write_u32_be(0x4BFFB519);	// bl    0x82256730
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop

		
		// Infinite Usage
		fseek(fXEX,0xE43351,SEEK_SET);fputc(0,fXEX);	// Library Card
		fseek(fXEX,0xE42F31,SEEK_SET);fputc(0,fXEX);	// Heart Refresh
		fseek(fXEX,0xE42F89,SEEK_SET);fputc(0,fXEX);	// Antivenom
		fseek(fXEX,0xE42DD1,SEEK_SET);fputc(0,fXEX);	// Fire Boomerangs
		fseek(fXEX,0xE41CF9,SEEK_SET);fputc(0,fXEX);	// Toadstool
		
		// Remove Silver Ring Maria Cutscene
		fseek(fXEX,0xCE0596,SEEK_SET);
		XB_Write_u16_be(0x0008);	// Y-Pos
		XB_Write_u16_be(0x0001);	// ID
		
		// Shop Relic is 500k
		fseek(fXEX,OFS_JEWELOFOPEN_SHOPENTRY + 4,SEEK_SET);
		XB_Write_u32_be(500000);
		
		if(XB_StartingGearSword == 124 || XB_StartingGearSword == 4)	// Can't Start with Mablung or Shield Rod in Glitch
		{
			XB_StartingGearSword = 118;
			XB_SetStartingRH(XB_StartingGearSword);
		}
	}
	
	if(strcmp(XB_PresetName,"NoLogic")==0 || strcmp(XB_PresetName,"NoLogicEq")==0)
	{
		if(strcmp(XB_PresetName,"NoLogicEq")==0)
			strcpy(XB_LocationSet,"Equipment");
		
		// Place Stopwatch in Clock Room
		fseek(fXEX,0xD575BA + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		fseek(fXEX,0xD58492 + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		
		// Prologue Rewards
		fseek(fXEX,OFS_PROLOGUEREWARD_HEARTREFRESH,SEEK_SET);
		XB_Write_u16_be(162);	// Manna Prism
		fseek(fXEX,OFS_PROLOGUEREWARD_NEUTRONBOMB,SEEK_SET);
		XB_Write_u16_be(166);	// Library Card
		
		// Prologue Reward Requirements don't matter
		fseek(fXEX,0x25F2A4,SEEK_SET);	// Heart Refresh
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		fseek(fXEX,0x25F2FC,SEEK_SET);	// Neutron Bomb
		XB_Write_u32_be(0x60000000);	// nop
		
		// Code Patch to give Soul of Wolf, Leap Stone and set Item Counts of Claymore, Axe Armor, Fire Boomerangs Code Base Address: 0x8225b200
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
		XB_Write_u32_be(0x38800001);	// li  r4, 1
		XB_Write_u32_be(0x988B49C8);	// stb r4, 0x49c8(r11)		// Claymore
		XB_Write_u32_be(0x988B4A28);	// stb r4, 0x4a28(r11)		// Axe Lord Armor
		XB_Write_u32_be(0x38840001);	// addi r4,r4,1
		XB_Write_u32_be(0x988B49EC);	// stb r4, 0x49ec(r11)		// Fire Boomerang
		XB_Write_u32_be(0x38840001);	// addi r4,r4,1	
		XB_Write_u32_be(0x988B494D);	// stb r4, 0x494d(r11)		// Leap Stone
		XB_Write_u32_be(0x988B4944);	// stb r4, 0x4944(r11)		// Soul of Wolf
		
		// Infinite Usage
		fseek(fXEX,0xE43351,SEEK_SET);fputc(0,fXEX);	// Library Card
		fseek(fXEX,0xE42F31,SEEK_SET);fputc(0,fXEX);	// Heart Refresh
		fseek(fXEX,0xE42F89,SEEK_SET);fputc(0,fXEX);	// Antivenom
		fseek(fXEX,0xE42DD1,SEEK_SET);fputc(0,fXEX);	// Fire Boomerangs
		fseek(fXEX,0xE41CF9,SEEK_SET);fputc(0,fXEX);	// Toadstool
		
		// Remove Silver Ring Maria Cutscene
		fseek(fXEX,0xCE0596,SEEK_SET);
		XB_Write_u16_be(0x0008);	// Y-Pos
		XB_Write_u16_be(0x0001);	// ID
		
		/*
		// Shop Relic is 500k
		fseek(fXEX,OFS_JEWELOFOPEN_SHOPENTRY + 4,SEEK_SET);
		XB_Write_u32_be(500000);
		*/
		
		XB_SetStartingRH(4);		// Shield Rod
		XB_SetStartingLH(12);		// Shaman Shield
		XB_SetStartingHelm(214);	// Dragon Helm
		XB_SetStartingArmor(184);	// Alucard Mail
		XB_SetStartingCape(225);	// Twilight Cloak
		XB_SetStartingAcc(253);		// Duplicator
	}
	
	if(strcmp(XB_PresetName,"Bingo")==0)
	{		
		// Addition Adds, using Maria Potion Instruction Space. This is just adding Holy Glasses
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x60000000);	// nop					* li r4,x (type)
		XB_Write_u32_be(0x60000000);	// nop					* li r3,x (id #)
		XB_Write_u32_be(0x60000000);	// nop					* If Desired, we can call the AddItem Function here with a write of 0x4BFFB529 ( bl 0x82256730 )
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x38800002);	// lis r4, 0x02
		XB_Write_u32_be(0x38600022);	// li  r3, 0x22
		XB_Write_u32_be(0x4BFFB519);	// bl    0x82256730
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
	}

	if(strcmp(XB_PresetName,"Adventure")==0)
	{
		strcpy(XB_LocationSet,"Equipment");
		// Place Stopwatch in Clock Room
		fseek(fXEX,0xD575BA + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		fseek(fXEX,0xD58492 + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
	}
	
	if(strcmp(XB_PresetName,"Expedition")==0)
	{
		strcpy(XB_LocationSet,"Equipment");
		// Place Stopwatch in Clock Room
		fseek(fXEX,0xD575BA + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		fseek(fXEX,0xD58492 + 8,SEEK_SET);
		XB_Write_u16_be(0x8012);
		
		// Place Library Card at Reverse Entrance Hammer (Castle Gate Room)
		fseek(fXEX,EQ_RCE,SEEK_SET);
		XB_Write_u16_be(166 + 128);
	}
	
	if(strcmp(XB_PresetName,"Warlock")==0)
	{
		XB_MinimumComplexity = 6;
		
		// Warlock reduced MP Costs
		fseek(fXEX,0xE445E8,SEEK_SET);	fputc(0x04,fXEX);	// Reduce Soul Steal MP Cost to 4.
		fseek(fXEX,0xE44598,SEEK_SET);	fputc(0x01,fXEX);	// Reduce Summon Spirit MP Cost to 1.
		fseek(fXEX,0xE445AC,SEEK_SET);	fputc(0x02,fXEX);	// Reduce HellFire MP Cost to 2.
		fseek(fXEX,0xE445C0,SEEK_SET);	fputc(0x03,fXEX);	// Reduce Tetra Spirit MP Cost to 3.
		fseek(fXEX,0xE44584,SEEK_SET);	fputc(0x02,fXEX);	// Reduce Dark Metamorph MP Cost to 2.
		fseek(fXEX,0x2D219A,SEEK_SET);	XB_Write_u16_be(0);	// Mist with PoM is Free
		fseek(fXEX,0x2D2166,SEEK_SET);	XB_Write_u16_be(0);	// Mist without PoM is Free
		
		// Code Patch to give Form of Mist. Code Base Address: 0x8225b200
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
		XB_Write_u32_be(0x38800003);	// li  r4, 3
		XB_Write_u32_be(0x988B4947);	// stb r4, 0x4947(r11)
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
			
		// Stats Patch. Uses Logic block for beating prologue under 60 seconds. We NOP the branch so we can always set the stats.
		fseek(fXEX,0x25F3E4,SEEK_SET);XB_Write_u32_be(0x60000000);	// nop						Instruction RAM Address 0x8225b3e4
		fseek(fXEX,0x25F400,SEEK_SET);XB_Write_u32_be(0x39200001);	// li r9, 1 for STR			Instruction RAM Address 0x8225b400
		fseek(fXEX,0x25F40C,SEEK_SET);XB_Write_u32_be(0x39200001);	// li r9, 1 for CON
		fseek(fXEX,0x25F418,SEEK_SET);XB_Write_u32_be(0x39200063);	// li r9, 99 for INT
		fseek(fXEX,0x25F424,SEEK_SET);XB_Write_u32_be(0x39200001);	// li r9, 1 for LCK
		
		XB_SetStartingHelm(216);	// Start with Wizard Hat
	}
	
	if(strcmp(XB_PresetName,"Lycanthrope")==0)
	{
		XB_MinimumComplexity = 8;	// this was moved elsewhere.
		
		XB_SetStartingRH(4);
		XB_SetStartingLH(12);
		XB_SetStartingHelm(215);
		XB_SetStartingArmor(189);
		XB_SetStartingCape(223);
		XB_SetStartingAcc(245);
		
		// Create Entities to give stuff (OLD)
		/*
		fseek(fXEX,OFS_BONUSSTUFF,SEEK_SET);
		XB_Write_Entity(0x80,0x290,0xA,0x10,245);	// Mystic Pendant
		XB_Write_Entity(0x100,0x290,0xA,0x11,4);	// Shield Rod
		XB_Write_Entity(0x110,0x290,0xA,0x12,12);	// Shaman Shield
		XB_Write_Entity(0x120,0x290,0xB,0x13,4);	// Soul of Wolf
		XB_Write_Entity(0x120,0x290,0xB,0x14,5);	// Power
		XB_Write_Entity(0x120,0x290,0xB,0x15,6);	// Skill
		*/
		// Code Patch to give Wolf Relics. Code Base Address: 0x8225b200
		fseek(fXEX,0x25F200,SEEK_SET);
		XB_Write_u32_be(0x3D608317);	// lis r11, 0x8317
		XB_Write_u32_be(0x38800003);	// li  r4, 3
		XB_Write_u32_be(0x988B4944);	// stb r4, 0x4944(r11)
		XB_Write_u32_be(0x988B4945);	// stb r4, 0x4945(r11)
		XB_Write_u32_be(0x988B4946);	// stb r4, 0x4946(r11)
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		XB_Write_u32_be(0x60000000);	// nop
		
		fseek(fXEX,0xE44688,SEEK_SET);	fputc(0x01,fXEX);	// Reduce Wolf Run Enemy Hit MP Cost to 1. Normally 5MP.
		fseek(fXEX,0x2EC142,SEEK_SET);	XB_Write_u16_be(0);	// Wolf form doesn't consume MP.
	}
	
	if(strcmp(XB_PresetName,"Richter Rando")==0)
	{
		XB_ApplyRichterPatches();
	}
}

void XB_SetStartingRH(int ID)
{
	XB_StartingGearSword = ID;
	// Starting Status
	fseek(fXEX,0x25F492,SEEK_SET);XB_Write_u16_be(ID);
	// Death Takes away
	fseek(fXEX,0x25EF1E,SEEK_SET);XB_Write_u16_be(ID);
	fseek(fXEX,0x25EF4A,SEEK_SET);XB_Write_u16_be(ID);
	fseek(fXEX,0x25EF5E,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25EF6E,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2E8,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_SetStartingLH(int ID)
{
	XB_StartingGearShield = ID;
	// Starting Status
	fseek(fXEX,0x25F49A,SEEK_SET);XB_Write_u16_be(ID);
	// Death Takes away
	fseek(fXEX,0x25EF32,SEEK_SET);XB_Write_u16_be(ID);
	fseek(fXEX,0x25EF72,SEEK_SET);XB_Write_u16_be(ID);
	fseek(fXEX,0x25EF86,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25EF96,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2EA,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_SetStartingHelm(int ID)
{
	XB_StartingGearHead = ID;
	int wornID = ID - 169;
	// Starting Status
	fseek(fXEX,0x25F4A2,SEEK_SET);XB_Write_u16_be(wornID);
	// Death Takes away
	fseek(fXEX,0x25EF9E,SEEK_SET);XB_Write_u16_be(wornID);
	fseek(fXEX,0x25EFB2,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25EFC2,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2EC,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_SetStartingArmor(int ID)
{
	XB_StartingGearBody = ID;
	int wornID = ID - 169;
	// Starting Status
	fseek(fXEX,0x25F4AA,SEEK_SET);XB_Write_u16_be(wornID);
	// Death Takes away
	fseek(fXEX,0x25EFCA,SEEK_SET);XB_Write_u16_be(wornID);
	fseek(fXEX,0x25EFDE,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25EFEE,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2EE,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_SetStartingCape(int ID)
{
	XB_StartingGearCape = ID;
	int wornID = ID - 169;
	// Starting Status
	fseek(fXEX,0x25F4B2,SEEK_SET);XB_Write_u16_be(wornID);
	// Death Takes away
	fseek(fXEX,0x25EFF6,SEEK_SET);XB_Write_u16_be(wornID);
	fseek(fXEX,0x25F00E,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25F01E,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2F0,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_SetStartingAcc(int ID)
{
	XB_StartingGearAccessory = ID;
	int wornID = ID - 169;
	// Starting Status
	fseek(fXEX,0x25F4BA,SEEK_SET);XB_Write_u16_be(wornID);
	// Death Takes away
	fseek(fXEX,0x25F026,SEEK_SET);XB_Write_u16_be(wornID);
	fseek(fXEX,0x25F04E,SEEK_SET);XB_Write_u16_be(wornID);
	fseek(fXEX,0x25F072,SEEK_SET);XB_Write_u16_be(ID+0x26);
	fseek(fXEX,0x25F082,SEEK_SET);XB_Write_u16_be(ID+0x26);
	// Death take away Sprite ID
	fseek(fXEX,0xD3F2F2,SEEK_SET);XB_Write_u16_be(ID);
}

void XB_ApplyFastWarps()
{
	if(XB_FastWarps == 0) return;
	fseek(fXEX,0x4B63BF,SEEK_SET);fputc(0x02,fXEX);
	fseek(fXEX,0x4AD1A7,SEEK_SET);fputc(0x02,fXEX);
}

void XB_ApplyAntiFreeze()
{
	if(XB_AntiFreeze == 0) return;
	fseek(fXEX,0x2E8FBB,SEEK_SET);fputc(0x00,fXEX);
}

unsigned char RLBC_CodeBlock[] = { 0x3C,0x80,0x83,0x17,0x3C,0x60,0x83,0x17,0x80,0x63,0x3C,0x68,0x2F,0x03,0x00,0x00,0x41,0x9A,0x00,0x20,0x3C,0x60,0x83,0x1C,0xA0,0x63,0x6C,0x60,0x2F,0x03,0x40,0x00,0x40,0x9A,0x00,0x10,0x38,0x60,0x00,0x22,0x98,0x64,0x49,0x66,0x4E,0x80,0x00,0x20,0x38,0x60,0x00,0x02,0x98,0x64,0x49,0x66,0x4E,0x80,0x00,0x20,0x3D,0x60,0x83,0x17,0x81,0x6B,0x3C,0x68,0x2F,0x0B,0x00,0x00,0x41,0x9A,0x00,0x1C,0x3D,0x60,0x83,0x17,0x89,0x6B,0x49,0x66,0x2F,0x0B,0x00,0x02,0x40,0x9A,0x00,0x0C,0x39,0x60,0x00,0x02,0x48,0x00,0x00,0x08,0x39,0x60,0x00,0x22,0x91,0x6A,0x3A,0xEC,0x4B,0x9B,0xFC,0x88 };
int RLBC_CodeBlock_Ofs = 0x883F90;	// RAM Address 0x8287FF90

void XB_ApplyReverseLibraryCardPatch()
{
	fseek(fXEX,RLBC_CodeBlock_Ofs,SEEK_SET);
	fwrite(&RLBC_CodeBlock[0],sizeof(RLBC_CodeBlock),1,fXEX);
	fseek(fXEX,0x23dc14 + 0x4000,SEEK_SET);
	XB_Write_u32_be(0x4864237C);			// Code Hook for Zone Change
	fseek(fXEX,0x23fc80 + 0x4000,SEEK_SET);
	XB_Write_u32_be(0x4864034C);			// Code Hook for Map Change
}

unsigned char MapTracker_CodeBlock[] = { 0x3D,0x40,0x83,0x13,0x81,0x4A,0x3A,0xEC,0x71,0x4A,0x00,0x20,0x2F,0x0A,0x00,0x20,0x41,0x9A,0x00,0x10,0x3D,0x40,0x82,0x88,0x39,0x4A,0xFD,0x70,0x48,0x00,0x00,0x0C,0x3D,0x40,0x82,0x88,0x39,0x4A,0xFD,0xF4,0x38,0xE0,0x00,0x00,0x88,0x8A,0x00,0x01,0x2F,0x04,0x00,0x00,0x41,0x9A,0x00,0xCC,0x2F,0x07,0x00,0x02,0x41,0x9A,0x00,0x10,0x2F,0x07,0x00,0x03,0x41,0x9A,0x00,0x08,0x48,0x00,0x00,0x08,0x38,0x84,0x00,0x01,0x3C,0xA0,0x40,0x49,0x38,0xA5,0xA6,0xB4,0x54,0x84,0x58,0x28,0x7C,0xA5,0x22,0x14,0x88,0xCA,0x00,0x00,0x2F,0x07,0x00,0x01,0x41,0x9A,0x00,0x10,0x2F,0x07,0x00,0x03,0x41,0x9A,0x00,0x08,0x48,0x00,0x00,0x08,0x38,0xC6,0x00,0x01,0x38,0x80,0x00,0x00,0x7C,0x84,0x32,0x14,0x70,0xC6,0x00,0x03,0x54,0x84,0xF0,0xBE,0x54,0x84,0x08,0x3C,0x7C,0xA5,0x22,0x14,0xA0,0x85,0x00,0x00,0x2F,0x06,0x00,0x00,0x41,0x9A,0x00,0x1C,0x2F,0x06,0x00,0x01,0x41,0x9A,0x00,0x20,0x2F,0x06,0x00,0x02,0x41,0x9A,0x00,0x24,0x2F,0x06,0x00,0x03,0x41,0x9A,0x00,0x28,0x70,0x84,0xFF,0xF0,0x60,0x84,0x00,0x07,0x48,0x00,0x00,0x24,0x70,0x84,0xFF,0x0F,0x60,0x84,0x00,0x70,0x48,0x00,0x00,0x18,0x70,0x84,0xF0,0xFF,0x60,0x84,0x07,0x00,0x48,0x00,0x00,0x0C,0x70,0x84,0x0F,0xFF,0x60,0x84,0x70,0x00,0xB0,0x85,0x00,0x00,0x38,0xE7,0x00,0x01,0x2F,0x07,0x00,0x04,0x40,0x9A,0xFF,0x3C,0x39,0x4A,0x00,0x02,0x38,0xE0,0x00,0x00,0x4B,0xFF,0xFF,0x30,0x39,0x40,0x00,0x14,0x4B,0x9C,0x03,0xEC };
int MapTracker_CodeBlock_Ofs = 0x87FE70 + 0x4000;	// RAM Address + XEX Header Offset.
int MapTracker_LocData_Ofs = 0x87FD70 + 0x4000;
int MapTracker_Castle1Terminate_Ofs = (27*2);
int MapTracker_Castle2Terminate_Ofs = (76*2);
int MapTracker_Castle2TerminateSpread_Ofs = (78*2);

unsigned char MapTracker_LocData[256] = {	// at 27 * 2 from start is Holy Mail. Zero out if not Equipment Preset. Must Calculate for 2nd. 76 * 2 from start is Badelaire. Zero out if not Equipment
	193,65,	// Soul of Bat
	238,25,	// Fire of Bat
	66,45,	// Echo of Bat
	246,53,	// Soul of Wolf
	10,133,	// Power of Wolf
	62,113,	// Skill of Wolf
	86,69,	// Form of Mist
	125,17,	// Power of Mist
	75,125,	// Cube of Zoe
	101,110,// Spirit Orb
	138,73,	// Gravity Boots
	125,26,	// Leap Stone
	222,145,// Holy Symbol
	238,53,	// Faerie Scroll
	197,61,	// Jewel of Open
	33,149,	// Merman Statue
	54,89,	// Bat Card
	158,10,	// Ghost Card
	209,53,	// Faerie Card
	117,157,// Demon Card
	82,53,	// Sword Card
	182,113,// Gold Ring
	33,41,	// Silver Ring
	130,106,// Holy Glasses
	165,185,// Spikebreaker
	70,181,	// Mormegil
	162,133,// Crystal Cloak
	21,133,	// Holy Mail
	41,145,	// Jewel Sword
	41,97,	// Cloth Cape
	65,105,	// Sunglasses
	237,73,	// Gladius
	197,65,	// Bronze Cuirass
	202,53,	// Holy Rod
	186,65,	// Library Onyx
	158,13,	// Falchion
	23,77,	// Ankh of Life (verify)
	36,65,	// Morningstar
	109,21,	// Cutlass
	130,69,	// Olrox Onyx
	121,41,	// Estoc
	134,53,	// Olrox Garnet
	53,77,	// Shield Rod
	81,77,	// Blood Cloak
	77,61,	// Holy Sword
	57,69,	// Knight Shield
	141,89,	// Bandanna
	98,137,	// Secret Boots (Verify Height)
	161,150,// Knuckle Duster
	183,145,// Caverns Onyx
	125,173,// Combat Knife
	114,181,// Bloodstone (may need tweak)
	97,181,	// Icebrand
	94,181,	// Walk Armor
	66,117,	// Basilard
	138,81,	// Alucart Sword
	237,90,	// Jewel Knuckles
	224,33,	// Bekatowa (Check and adjust)
	197,37,	// Gold Plate
	142,5,	// Platinum Mail
	15,85,	// Mystic Pendant (check)
	42,61,	// Goggles
	57,29,	// Silver Plate
	153,133,// Nunchaku
	150,146,// Ring of Ares (check)
	0,0,	// Castle 1 End
	222,145,// Force of Echo
	70,181,	// Gas Cloud
	96,33,	// Heart of Vlad
	232,73,	// Tooth of Vlad
	80,45,	// Rib of Vlad
	161,21,	// Ring of Vlad
	123,141,// Eye of Vlad
	162,133,// Dark Blade
	80,69,	// Trio
	54,89,	// Ring of Arcana
	202,53,	// Badelaire
	198,62,	// Reverse Library Opal
	133,5,	// Bastard Sword
	142,5,	// Royal Cloak
	125,26,	// Sword of Dawn aka Reverse Keep Garnet
	158,25,	// Lightning Mail
	238,25,	// Dragon Helm
	197,37,	// Sunstone (reverse clock puzzle)
	77,25,	// Talwar
	134,53,	// Alucard Mail
	130,69,	// Sword of Hador
	77,61,	// Fury Plate
	65,105,	// Goddess Shield
	237,89,	// Shotel
	141,89,	// Reverse Caverns Diamond
	89,129,	// Reverse Caverns Garnet
	33,149,	// Alucard Shield
	117,157,// Alucard Sword
	97,181,	// Necklace of J
	94,181,	// Reverse Catacombs Diamond
	82,130,	// Talisman
	194,66,	// Staurolite
	169,26,	// Moon Rod
	224,33,	// Luminus (ok)
	33,41,	// Twilight Cloak
	81,77,	// Gram
	50,126,	// Katana
	149,109,// R. Caverns Opal
	102,149,// Osafune Katana
	41,145,	// Beryl Circlet		
	0,0		// Castle 2 End
	};

void XB_ApplyMapTrackerPatch()
{
	if(XB_EnableMapTracker == 0)
		return;

	fseek(fXEX,MapTracker_CodeBlock_Ofs,SEEK_SET);
	fwrite(&MapTracker_CodeBlock[0],sizeof(MapTracker_CodeBlock),1,fXEX);
	fseek(fXEX,0x24035C + 0x4000,SEEK_SET);
	XB_Write_u32_be( XB_CalcBranch(0x24035C,0x87FE70) );			// Code Hook
	
	fseek(fXEX,MapTracker_LocData_Ofs,SEEK_SET);
	fwrite(&MapTracker_LocData[0],sizeof(MapTracker_LocData),1,fXEX);
	
	LogMsg("Map Tracker patch applied.");
	
	if(strcmp(XB_LocationSet,"Equipment")==0)
		return;
		
	if(strcmp(XB_LocationSet,"Spread")==0)
	{
		fseek(fXEX,MapTracker_LocData_Ofs + MapTracker_Castle1Terminate_Ofs,SEEK_SET);
		XB_Write_u16_be(0);
		fseek(fXEX,MapTracker_LocData_Ofs + MapTracker_Castle2TerminateSpread_Ofs,SEEK_SET);
		XB_Write_u16_be(0);		
		return;
	}
	
	// If Not Equipment Set, Terminate Lists to not draw those checks.
	fseek(fXEX,MapTracker_LocData_Ofs + MapTracker_Castle1Terminate_Ofs,SEEK_SET);
	XB_Write_u16_be(0);
	fseek(fXEX,MapTracker_LocData_Ofs + MapTracker_Castle2Terminate_Ofs,SEEK_SET);
	XB_Write_u16_be(0);
}

unsigned int XB_CalcBranch(int SrcAddress,int DestAddress)
{
	SrcAddress &= 0xFFFFFF;
	DestAddress &= 0xFFFFFF;
	if(SrcAddress<DestAddress)
	{
		return 0x48000000 | (DestAddress - SrcAddress);
	}
	return 0x4B000000 | (0x1000000 - (SrcAddress - DestAddress));
}

// Shop Rando Stuff
struct XB_PoolItem {
	char Name[32];
	int Category;
	int ID;
};

#define SHOP_POOL_SIZE 128
XB_PoolItem XB_ShopPool[SHOP_POOL_SIZE];

void XB_ClearItemPool(XB_PoolItem *Pool, int PoolSize)
{
	int i = 0;
	while(1)
	{
		Pool[i].Name[0] = 0;
		i++;
		if(i>=PoolSize)
			break;
	}
}

void XB_AddItemToPool(XB_PoolItem *Pool, int PoolSize, char *Name, int Cat, int ID)
{
	int RandomSlot;
	
	//printf("Adding to Pool: %s\n",Name);
	
	while(1)	// Find a Random Free Space in the Pool
	{
		RandomSlot = rand()%PoolSize;
		if(Pool[RandomSlot].Name[0] == 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] == 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] == 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] == 0)
			break;
	}
	
	Pool[RandomSlot].Category = Cat;
	Pool[RandomSlot].ID = ID;
	strcpy(Pool[RandomSlot].Name,Name);
}

int XB_GetItemFromPool(XB_PoolItem *Pool, int PoolSize)
{
	int RandomSlot;
	
	XB_BurnRandom();
	
	while(1)	// Find a Random Free Space in the Pool
	{
		RandomSlot = rand()%PoolSize;
		if(Pool[RandomSlot].Name[0] > 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] > 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] > 0)
			break;
		RandomSlot = (RandomSlot + 1)&(PoolSize-1);
		if(Pool[RandomSlot].Name[0] > 0)
			break;
	}
	
	Pool[RandomSlot].Name[0] = 0;
	return RandomSlot;
}

void XB_DeleteItemFromPool(XB_PoolItem *Pool,int PoolSize,int Category, int ID)
{
	for(int i=0;i<PoolSize;i++)
	{
		if(Pool[i].Name[0])
		{
			if(Pool[i].Category == Category && Pool[i].ID == ID)
			{
				Pool[i].Name[0] = 0;
				Pool[i].Category = 0;
				Pool[i].ID = 0;
			}
		}
	}
}


int XB_ConsumableList[] = { 1, 2, 3, 24, 25, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 134, 135, 138, 142, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 166, 0 };
int XB_WeaponList[] = { 4, 18, 19, 20, 21, 22, 23, 26, 27, 28, 83, 84, 85, 86, 87 ,88, 89, 90, 91 , 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 
						 118, 119, 120, 121, 122, 123, 124, 125, 127, 128, 129, 130, 131, 132, 133, 136, 137, 139, 140, 141, 143, 163, 164, 165, 168, 0 };
int XB_ShieldList[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 167, 0 };
int XB_HeadList[] = { 27, 28, 29, 30, 31, 32, 33, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 0 };
int XB_BodyList[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 89, 0 };
int XB_CapeList[] = { 49, 50, 51, 52, 53, 54, 55, 56, 0 };
int XB_AccessoryList[] = { 58, 59, 60, 61, 62, 70, 71, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 0 };

int XB_PrologueList[] = { 1, 2, 3, 24, 25, 71, 72, 73, 74, 77, 78, 142, 144, 145, 146, 148, 149, 150, 151, 152, 159, 160, 161, 162, 166, 0 };


int XB_Glitch_ConsumableList[] = { 1, 2, 3, 24, 25, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 135, 138, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 166, 0 };
int XB_Glitch_WeaponList[] = { 18, 19, 20, 21, 22, 23, 26, 27, 28, 83, 84, 85, 86, 87 ,88, 89, 90, 91 , 92, 93, 94, 96, 97, 99, 100, 102, 104, 105, 106, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 
						 118, 119, 120, 121, 122, 123, 125, 127, 128, 129, 130, 131, 132, 133, 136, 137, 139, 140, 141, 143, 163, 164, 165, 168, 0 };


void XB_PopulateShopPool(int *ItemList,int Category)
{
	int i = 0;
	int ItemNumber;
	int ItemNameNumber;
	
	XB_ClearItemPool(&XB_ShopPool[0],SHOP_POOL_SIZE);
	
	while(1)
	{
		ItemNumber = ItemList[i];
		ItemNameNumber = ItemNumber;
		if(ItemNumber == 0) break;
		if(Category) ItemNameNumber += 169;
		XB_AddItemToPool(&XB_ShopPool[0],SHOP_POOL_SIZE,XB_ItemNames[ItemNameNumber],Category,ItemNumber);
		i++;
	}
}

void XB_AddShopItem(int ShopIndex,int Category,int ID)
{
	int ofs = OFS_SHOPLIST + (ShopIndex * 8);
	int IDName = ID;
	if(Category) IDName = IDName + 169;

	fseek(fXEX,ofs,SEEK_SET);
	fputc(Category,fXEX);
	fputc(0x00,fXEX);	// Unlock Level
	XB_Write_u16_be(ID);

	if(Category > 0) ID = ID + 169;
	//printf("ShopItem Added Slot %d: %s\n",ShopIndex,XB_ItemNames[IDName]);	
	
}

void XB_AddRandomShopItem(int ShopIndex)
{
	int PoolIndex = XB_GetItemFromPool(&XB_ShopPool[0],SHOP_POOL_SIZE);
	
	XB_AddShopItem(ShopIndex,XB_ShopPool[PoolIndex].Category,XB_ShopPool[PoolIndex].ID);
}

void XB_RandomizeShopItems()
{
	int ofs = OFS_SHOPLIST + 8;
	int PoolIndex;
	
	// Make Shop Relic Free
	fseek(fXEX,OFS_SHOPLIST + 4,SEEK_SET);
	XB_Write_u32_be(0x00000000);
	
	//printf("\n\nShop Rando:\n\n");
	
	// Glitch has separate Shop Items Allowed
	if(strcmp(XB_PresetName,"Glitch")== 0)
	{
		XB_PopulateShopPool(&XB_Glitch_ConsumableList[0],0);
	}
	else
	{
		XB_PopulateShopPool(&XB_ConsumableList[0],0);
	}
	
	// Add Consumables to Shop List
	for(int i=1;i<19;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	// Glitch has separate Shop Items Allowed
	if(strcmp(XB_PresetName,"Glitch")== 0)
	{
		XB_PopulateShopPool(&XB_Glitch_WeaponList[0],0);
	}
	else
	{
		XB_PopulateShopPool(&XB_WeaponList[0],0);
	}
	
	// Add Weapons to Shop List
	for(int i=19;i<26;i++)
	{
		XB_AddRandomShopItem(i);
	}

	XB_PopulateShopPool(&XB_ShieldList[0],0);
	for(int i=26;i<28;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	XB_PopulateShopPool(&XB_HeadList[0],1);
	for(int i=28;i<32;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	XB_PopulateShopPool(&XB_BodyList[0],2);
	for(int i=32;i<35;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	XB_PopulateShopPool(&XB_CapeList[0],3);
	for(int i=35;i<38;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	XB_PopulateShopPool(&XB_AccessoryList[0],4);
	for(int i=38;i<42;i++)
	{
		XB_AddRandomShopItem(i);
	}
	
	if(XB_NoShopEquipment)
	{
		for(int i=1;i<42;i++)
		{
			XB_AddShopItem(i,0,0);
		}
	}
	
	// Change 500K Slot price to be lower.
	fseek(fXEX,0xD42234,SEEK_SET);
	XB_Write_u32_be(15000);
	
}

// Randomize Starting Gear
XB_PoolItem XB_StartingGearPool[128];

int XB_OneHandedList[] = { 18, 19, 20, 22, 23, 28, 83, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 96, 97, 99, 102, 104, 105, 106, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 128, 129, 130, 131, 132, 133, 136, 137, 143, 163, 164, 168, 0 };

// Add All Weapons from list above. List zero terminated.
void XB_SetupStartingSwords()
{
	int ID;
	int i = 0;
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	while(1)
	{
		if(XB_OneHandedList[i])
		{
			ID = XB_OneHandedList[i];
			XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[ ID ],0, ID);
		}
		else	{	break;	}
		i++;
	}
}

void XB_SetupStartingShields()
{
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	for(int i=5;i<17;i++)
	{
		XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[i],0,i);
	}
	XB_AddItemToPool(&XB_StartingGearPool[0],128,"Alucart Shield",0,167);
}

void XB_SetupStartingHeads()
{
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	for(int i=27;i<48;i++)
	{
		XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[169 + i],1,i);
	}
	XB_DeleteItemFromPool(&XB_StartingGearPool[0],128,1,34);	// Remove Holy Glasses
}

void XB_SetupStartingBodys()
{
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	for(int i=1;i<26;i++)
	{
		XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[169 + i],2,i);
	}
	XB_DeleteItemFromPool(&XB_StartingGearPool[0],128,2,14);	// Remove Spikebreaker
}

void XB_SetupStartingCapes()
{
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	for(int i=49;i<57;i++)
	{
		XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[169 + i],3,i);
	}
}

void XB_SetupStartingAccessories()
{
	XB_ClearItemPool(&XB_StartingGearPool[0],128);
	for(int i=58;i<89;i++)
	{
		XB_AddItemToPool(&XB_StartingGearPool[0],128,XB_ItemNames[169 + i],4,i);
	}
	XB_DeleteItemFromPool(&XB_StartingGearPool[0],128,4,72);	// Remove Gold Ring
	XB_DeleteItemFromPool(&XB_StartingGearPool[0],128,4,73);	// Remove Silver Ring
}

void XB_RandomizeStartingGear()
{
	if(XB_UseRandomStartingGear == 0) return;
	printf("RandomizeStartingGear()\n");
	
	XB_SetupStartingSwords();
	XB_StartingGearSword = XB_GetItemFromPool(&XB_StartingGearPool[0],128);	// Get Pool Slot Number
	XB_StartingGearSword = XB_StartingGearPool[XB_StartingGearSword].ID;		// Get ID Number
	XB_SetupStartingShields();
	XB_StartingGearShield = XB_GetItemFromPool(&XB_StartingGearPool[0],128);
	XB_StartingGearShield = XB_StartingGearPool[XB_StartingGearShield].ID;
	XB_SetupStartingHeads();
	XB_StartingGearHead = XB_GetItemFromPool(&XB_StartingGearPool[0],128);
	XB_StartingGearHead = XB_StartingGearPool[XB_StartingGearHead].ID + 169;
	XB_SetupStartingBodys();
	XB_StartingGearBody = XB_GetItemFromPool(&XB_StartingGearPool[0],128);
	XB_StartingGearBody = XB_StartingGearPool[XB_StartingGearBody].ID + 169;
	XB_SetupStartingCapes();
	XB_StartingGearCape = XB_GetItemFromPool(&XB_StartingGearPool[0],128);
	XB_StartingGearCape = XB_StartingGearPool[XB_StartingGearCape].ID + 169;
	XB_SetupStartingAccessories();
	XB_StartingGearAccessory = XB_GetItemFromPool(&XB_StartingGearPool[0],128);
	XB_StartingGearAccessory = XB_StartingGearPool[XB_StartingGearAccessory].ID + 169;
	
	//printf("Starting Gear:\n\n%s\n%s\n%s\n%s\n%s\n%s\n",XB_ItemNames[XB_StartingGearSword],XB_ItemNames[XB_StartingGearShield],XB_ItemNames[XB_StartingGearHead+169],XB_ItemNames[XB_StartingGearBody+169],XB_ItemNames[XB_StartingGearCape+169],XB_ItemNames[XB_StartingGearAccessory+169]);
	
	XB_SetStartingRH(XB_StartingGearSword);
	XB_SetStartingLH(XB_StartingGearShield);
	XB_SetStartingHelm(XB_StartingGearHead);
	XB_SetStartingArmor(XB_StartingGearBody);
	XB_SetStartingCape(XB_StartingGearCape);
	XB_SetStartingAcc(XB_StartingGearAccessory);	
}

void XB_RandomizePrologueRewards()
{
	int PoolIndex;
	int ItemNumber;
	
	XB_PopulateShopPool(&XB_PrologueList[0],0);

	PoolIndex = XB_GetItemFromPool(&XB_ShopPool[0],SHOP_POOL_SIZE);
	ItemNumber = XB_ShopPool[PoolIndex].ID;
	fseek(fXEX,OFS_PROLOGUEREWARD_HEARTREFRESH,SEEK_SET);
	XB_Write_u16_be(ItemNumber);
	printf("Heart Refresh Reward: %s\n",XB_ItemNames[ItemNumber]);

	PoolIndex = XB_GetItemFromPool(&XB_ShopPool[0],SHOP_POOL_SIZE);
	ItemNumber = XB_ShopPool[PoolIndex].ID;
	fseek(fXEX,OFS_PROLOGUEREWARD_NEUTRONBOMB,SEEK_SET);
	XB_Write_u16_be(ItemNumber);
	printf("Neutron Bomb Reward: %s\n",XB_ItemNames[ItemNumber]);

	PoolIndex = XB_GetItemFromPool(&XB_ShopPool[0],SHOP_POOL_SIZE);
	ItemNumber = XB_ShopPool[PoolIndex].ID;
	//fseek(fXEX,OFS_PROLOGUEREWARD_POTION,SEEK_SET);
	//XB_Write_u16_be(ItemNumber);
	
	if(strcmp(XB_PresetName,"Glitch")==0)	printf("Note: Glitch overrides random Rewards.\n");
}

void XB_PrintStartingGear()
{
	printf("Starting Gear:\n\n%s\n%s\n%s\n%s\n%s\n%s\n",XB_ItemNames[XB_StartingGearSword],XB_ItemNames[XB_StartingGearShield],XB_ItemNames[XB_StartingGearHead],XB_ItemNames[XB_StartingGearBody],XB_ItemNames[XB_StartingGearCape],XB_ItemNames[XB_StartingGearAccessory]);
}

void XB_TestFunc()
{
	int Loc = 0;
	int HG_Count = 0;
	int NHG_Count = 0;
	int Has_HG;
	
	while(Loc<MAX_LOC)
	{
		if(XB_RelicChecks[Loc].Name[0])
		{
			Has_HG = 0;
			for(int l=0;l<32;l++)
			{
				if(XB_RelicChecks[Loc].Requirements[0][l] == RID_HolyGlasses)
					Has_HG = 1;
			}
			
			if(Has_HG)
			{
				HG_Count++;
			}
			else
			{
				NHG_Count++;
			}
			
		}
		Loc++;
	}
	printf("Locations that require Holy Glasses: %d\nLocations that DON'T require Holy Glasses: %d\n",HG_Count,NHG_Count);
}

// Main Rando Function
int XB_Randomize(char *XEX_Path,unsigned int InitialSeed)
{
	LogMsg("XB_Randomize() Startup..");
	
	fXEX = fopen(XEX_Path,"r+b");
	if(fXEX==NULL)
	{
		// Failure LogMsg happens after this, where it was called from.
		return 0;	// Failure
	}
	
	// LogMsg("Opened XEX File for Read&Write");	// Kind of pointless.
	
	(InitialSeed);
	SeedName_Index = 0;
	XB_InverseSeedNumber = InitialSeed ^ 0xFFFFFFFF;
	
	XB_AddRandoString();

	if(XB_RandomizeRelicLocations)
	{
		LogMsg("Randomizing Relics..");
		XB_AbortSignal = 0;	// Pull Abort Signal Low
		XB_ThreadStatus = 1;	// Set Thread Status to Active
				
		(HANDLE)_beginthread(XB_RandomizeRelics, 0, (void*)(uintptr_t)1);	// Start Randomizer Thread

		while(XB_ThreadStatus)
		{
			DoMessages();	// Respond to Messages while Randomizer thread is processing. This allows us to Abort if there is a problem.
		}
		
		XB_PrintLocations();
		XB_PrintSteps();
		
		if(XB_GeneratedSeedComplexity>15)	// Handle Abort or Error
		{
			LogMsg("Seed generation error or operation aborted!");
			return 1;
		}
		
		// Patch Shop Relic Check
		fseek(fXEX,0x40652E,SEEK_SET);XB_Write_u16_be(0x4920);		// This Changes from checking Jewel of Open status to unused zero memory so the first item always shows.
		
		//XB_WriteRelics();	// Moved to happen after Equipment List Rando so Relic Rando can override lists.
		LogScratch();
		LogMsg("Randomizing Relics Complete!");
	}
	
	XB_NoEquipment = XB_NoShopEquipment = 0;
	if(strcmp(XB_PresetName,"Bounty Hunter")==0 || strcmp(XB_PresetName,"Hitman")==0)
	{
		XB_NoEquipment = XB_NoShopEquipment = 1;
	}
	
	
	XB_InitializeItemPool(0);
	
	XB_ItemDeployCount = 0;
	if(XB_RandomizeEquipment)
		XB_DoEquipmentRando();
	//printf("Equipment ItemDeployCount: %d\n",XB_ItemDeployCount);	// Should be around 475
	
	if(XB_RandomizeRelicLocations)	// Moved here so Relic Rando has priority over Equipment Rando for EQ Lists
		XB_WriteRelics();
	
	//XB_TestFunc();
	
	if(strcmp(XB_PresetName,"Bounty Hunter")==0 || strcmp(XB_PresetName,"Hitman")==0)	// Turn back on for Enemy Drops
		XB_NoEquipment = 0;
	
	XB_ItemDeployCount = 0;
	if(XB_RandomizeDrops)
	{
		XB_InitializeItemPool(1);
		XB_DoDropsRando();
	}
	//printf("Drops ItemDeployCount: %d\n",XB_ItemDeployCount);		// Should be around 241
		
	if(XB_RandomizeShop)
		XB_RandomizeShopItems();
		
	XB_RandomizeStartingGear();
		
	if(XB_UseRandomStartingGear)
		XB_RandomizePrologueRewards();

	XB_PresetWrites();		// Do Preset Specific Writes and logic Last.
	
	XB_PrintStartingGear();

	if(XB_ClockStatue)
		XB_RemoveClockStatue();
		
	XB_RandomizeWingSmashTrail();
	XB_RandomizeAlchemyVats();
	XB_FixOuterWallElevator();
	XB_FixScyllaSoftlock();
	XB_RemoveMariaAlchemyMeeting();
	XB_ApplyFastWarps();
	XB_ApplyAntiFreeze();
	XB_ApplyMapTrackerPatch();	// Must happen after PresetWrites.
	
	XB_PatchMines();	// So you can Escape if you get in without Leap, Grav, or Flight.
	XB_PatchBridgeInput();
	XB_PatchClearFile();
	
	if(XB_CandleRando)
	{
		XB_CandleSetup();
	}
	
	fclose(fXEX);
	
	XB_SaveSpoilers();
	
	return 1;	// Success
}
