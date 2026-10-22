// xb_relic_locations.cpp
// This contains the setup for relic location checks for each preset.
// Exclude this from Build, it is included into xb_rando.cpp
// This is just to keep xb_rando.cpp less cluttered.

void XB_SetupLocations_Guarded()
{	
	int Loc;
	
	Loc = XB_AddLocation("Soul of Bat", OFS_X_SOULOFBAT,OFS_Y_SOULOFBAT);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Fire of Bat", OFS_X_FIREOFBAT,OFS_Y_FIREOFBAT);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Echo of Bat", OFS_X_ECHOOFBAT,OFS_Y_ECHOOFBAT);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Force of Echo", OFS_X_FORCEOFECHO,OFS_Y_FORCEOFECHO);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Soul of Wolf", OFS_X_SOULOFWOLF,OFS_Y_SOULOFWOLF);

	Loc = XB_AddLocation("Power of Wolf", OFS_X_POWEROFWOLF,OFS_Y_POWEROFWOLF);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Skill of Wolf", OFS_X_SKILLOFWOLF,OFS_Y_SKILLOFWOLF);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetSkillOfWolf);
	
	
	Loc = XB_AddLocation("Form of Mist", OFS_X_FORMOFMIST,OFS_Y_FORMOFMIST);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Power of Mist", OFS_X_POWEROFMIST,OFS_Y_POWEROFMIST);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Gas Cloud", OFS_X_GASCLOUD,OFS_Y_GASCLOUD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Cube of Zoe", OFS_X_CUBEOFZOE,OFS_Y_CUBEOFZOE);
	
	XB_AddLocation("Spirit Orb", OFS_X_SPIRITORB,OFS_Y_SPIRITORB);
	
	Loc = XB_AddLocation("Gravity Boots", OFS_X_GRAVITYBOOTS,OFS_Y_GRAVITYBOOTS);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Leap Stone", OFS_X_LEAPSTONE,OFS_Y_LEAPSTONE);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Symbol", OFS_X_HOLYSYMBOL,OFS_Y_HOLYSYMBOL);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_MermanStatue);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Faerie Scroll", OFS_X_FAERIESCROLL,OFS_Y_FAERIESCROLL);
	
	Loc = XB_AddLocation("Jewel of Open", OFS_X_JEWELOFOPEN,OFS_Y_JEWELOFOPEN);
	XB_AddLocationFunction(Loc,&XB_SetJewelOfOpen);
	
	Loc = XB_AddLocation("Merman Statue", OFS_X_MERMANSTATUE,OFS_Y_MERMANSTATUE);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bat Card", OFS_X_BATCARD,OFS_Y_BATCARD);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetBatCard);

	Loc = XB_AddLocation("Ghost Card", OFS_X_GHOSTCARD,OFS_Y_GHOSTCARD);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Faerie Card", OFS_X_FAERIECARD,OFS_Y_FAERIECARD);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Demon Card", OFS_X_DEMONCARD,OFS_Y_DEMONCARD);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);	
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);	// This requires escape reqs or PatchMines()
	XB_EndLocationLocks(Loc);


	Loc = XB_AddLocation("Sword Card", OFS_X_SWORDCARD,OFS_Y_SWORDCARD);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Heart of Vlad", OFS_X_HEARTOFVLAD,OFS_X_HEARTOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetHeartOfVlad);
	
	Loc = XB_AddLocation("Tooth of Vlad", OFS_X_TOOTHOFVLAD,OFS_X_TOOTHOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetToothOfVlad);

	Loc = XB_AddLocation("Rib of Vlad", OFS_X_RIBOFVLAD,OFS_X_RIBOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRibOfVlad);
	
	Loc = XB_AddLocation("Ring of Vlad", 0, 0);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRingOfVlad);
	
	Loc = XB_AddLocation("Eye of Vlad", OFS_X_EYEOFVLAD, OFS_Y_EYEOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetEyeOfVlad);
	
	Loc = XB_AddLocation("Gold Ring", OFS_X_GOLDRING, OFS_Y_GOLDRING);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	// add wolf + skill (psx doesn't include this)
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetGoldRing);
	
	Loc = XB_AddLocation("Silver Ring", OFS_X_SILVERRING, OFS_Y_SILVERRING);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x2 * 2);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_Spikebreaker);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Glasses", OFS_X_HOLYGLASSES, OFS_Y_HOLYGLASSES);
	XB_AddLocationLocks(Loc,2,RID_GoldRing,RID_SilverRing);	// escape reqs needed if we go with just this, or we dont put one ring at flight locked
	XB_EndLocationLocks(Loc);
	//XB_AddLocationFunction(Loc,&XB_SetHolyGlasses);
	
	Loc = XB_AddLocation("Spikebreaker", OFS_X_SPIKEBREAKER, OFS_Y_SPIKEBREAKER);	
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x10 * 2);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfBat,RID_EchoOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Crystal Cloak", OFS_X_CRYSTALCLOAK,OFS_Y_CRYSTALCLOAK);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Mormegil", OFS_X_MORMEGIL,OFS_Y_MORMEGIL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x3 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);	// This requires escape reqs or PatchMines()
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Trio", OFS_X_TRIO, OFS_Y_TRIO);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetTrio);
	
	Loc = XB_AddLocation("Ring of Arcana", OFS_X_RINGOFARCANA, OFS_Y_RINGOFARCANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x8 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Dark Blade", OFS_X_DARKBLADE, OFS_Y_DARKBLADE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x17 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
}

// Based on Guarded
void XB_SetupLocations_OG()
{
	XB_SetupLocations_Guarded();
	XB_RemoveLocation("Crystal Cloak");
	XB_RemoveLocation("Mormegil");
	XB_RemoveLocation("Trio");
	XB_RemoveLocation("Ring of Arcana");
	XB_RemoveLocation("Dark Blade");
}

// Based on Guarded
void XB_SetupLocations_Adventure()
{
	int Loc;
	
	XB_SetupLocations_Guarded();
	Loc = XB_AddLocation("Holy Mail",OFS_X_HOLYMAIL,OFS_Y_HOLYMAIL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CE + (0x5 * 2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Jewel Sword",OFS_X_JEWELSWORD,OFS_Y_JEWELSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CE + (0x9 * 2);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Cloth Cape",OFS_X_CLOTHCAPE,OFS_Y_CLOTHCAPE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x2 * 2);
	
	Loc = XB_AddLocation("Sunglasses",OFS_X_SUNGLASSES,OFS_Y_SUNGLASSES);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x6 * 2);
	
	Loc = XB_AddLocation("Gladius",OFS_X_GLADIUS,OFS_Y_GLADIUS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OW + (0x4 * 2);
	
	Loc = XB_AddLocation("Bronze Cuirass",OFS_X_BRONZECUIRASS,OFS_Y_BRONZECUIRASS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x4 * 2);
	
	Loc = XB_AddLocation("Holy Rod",OFS_X_HOLYROD,OFS_Y_HOLYROD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Library Onyx",OFS_X_LIBRARYONYX,OFS_Y_LIBRARYONYX);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x6 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Falchion",OFS_X_FALCHION,OFS_Y_FALCHION);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CK + (0xC * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Ankh Of Life",OFS_X_ANKHOFLIFE,OFS_Y_ANKHOFLIFE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x0 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Morningstar",OFS_X_MORNINGSTAR,OFS_Y_MORNINGSTAR);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Cutlass",OFS_X_CUTLASS,OFS_Y_CUTLASS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0xE * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Broadsword",OFS_X_BROADSWORD,OFS_Y_BROADSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Estoc",OFS_X_ESTOC,OFS_Y_ESTOC);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0xA * 2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Olrox Garnet",OFS_X_OLROXGARNET,OFS_Y_OLROXGARNET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0xC * 2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Shield Rod",OFS_X_SHIELDROD,OFS_Y_SHIELDROD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Blood Cloak",OFS_X_BLOODCLOAK,OFS_Y_BLOODCLOAK);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x3 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Sword",OFS_X_HOLYSWORD,OFS_Y_HOLYSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Knight Shield",OFS_X_KNIGHTSHIELD,OFS_Y_KNIGHTSHIELD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bandanna", OFS_X_BANDANNA,OFS_Y_BANDANNA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0xB * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Secret Boots", OFS_X_SECRETBOOTS,OFS_Y_SECRETBOOTS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x1F * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Knuckle Duster", OFS_X_KNUCKLEDUSTER,OFS_Y_KNUCKLEDUSTER);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x17 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Caverns Onyx", OFS_X_CAVERNSONYX,OFS_Y_CAVERNSONYX);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x16 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_MermanStatue);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_HolySymbol,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Combat Knife", OFS_X_COMBATKNIFE,OFS_Y_COMBATKNIFE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AM + (0x5 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bloodstone", OFS_X_BLOODSTONE,OFS_Y_BLOODSTONE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x8 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Icebrand", OFS_X_ICEBRAND,OFS_Y_ICEBRAND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x1 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Walk Armor", OFS_X_WALKARMOR,OFS_Y_WALKARMOR);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x2 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Basilard", OFS_X_BASILARD,OFS_Y_BASILARD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x9 * 2);
	
	Loc = XB_AddLocation("Alucart Sword",OFS_X_ALUCARTSWORD,OFS_Y_ALUCARTSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_MG + (0x7 * 2);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_CubeOfZoe,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Jewel Knuckles", OFS_X_JEWELKNUCKLES,OFS_Y_JEWELKNUCKLES);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OW + (0x0 * 2);
	
	Loc = XB_AddLocation("Bekatowa",OFS_X_BEKATOWA,OFS_Y_BEKATOWA);		// Clock Tower 3 Pillars
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CT + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Gold Plate",OFS_X_GOLDPLATE,OFS_Y_GOLDPLATE);		// Clock Tower Puzzle
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CT + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Platinum Mail",OFS_X_PLATINUMMAIL,OFS_Y_PLATINUMMAIL);	// Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CK + (0xB * 2);
	XB_AddLocationLocks(Loc,2,RID_LeapStone,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Mystic Pendant",OFS_X_MYSTICPENDANT,OFS_Y_MYSTICPENDANT);	// Chapel
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Goggles",OFS_X_GOGGLES,OFS_Y_GOGGLES);	// Chapel
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x9 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Silver Plate",OFS_X_SILVERPLATE,OFS_Y_SILVERPLATE);	// Top of Chapel West Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0xA * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Nunchaku",OFS_X_NUNCHAKU,OFS_Y_NUNCHAKU);	// Caverns
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x24 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_HolySymbol);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Ring of Ares",OFS_X_RINGOFARES,OFS_Y_RINGOFARES);	// Mines behind Demon Switch
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AM + (0x4 * 2);
	XB_AddLocationLocks(Loc,3,RID_DemonCard,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,4,RID_DemonCard,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,3,RID_DemonCard,RID_JewelOfOpen,RID_SoulOfBat);	
	XB_AddLocationLocks(Loc,4,RID_DemonCard,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);	// This would require adding Escape Requirements or Blocks to get back to Warp	
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("Bastard Sword",OFS_X_BASTARDSWORD,OFS_Y_BASTARDSWORD);	// Reverse Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x4 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Royal Cloak",OFS_X_ROYALCLOAK,OFS_Y_ROYALCLOAK);	// Reverse Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0xB * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sword of Dawn",OFS_X_SWORDOFDAWN,OFS_Y_SWORDOFDAWN);	// Reverse Keep, actually is the Garnet.
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x16 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Lightning Mail",OFS_X_LIGHTNINGMAIL,OFS_Y_LIGHTNINGMAIL);	// Reverse Keep
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x17 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Dragon Helm",OFS_X_DRAGONHELM,OFS_Y_DRAGONHELM);	// Reverse Clock Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x5 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sun Stone",OFS_X_SUNSTONE,OFS_Y_SUNSTONE);	// Reverse Clock Tower Puzzle
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x8 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Talwar",OFS_X_TALWAR,OFS_Y_TALWAR);	// Reverse Chapel Middle Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RRC + (0xD * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Mail",OFS_X_ALUCARDMAIL,OFS_Y_ALUCARDMAIL);	// Reverse Olrox
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROQ + (0x7 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sword Of Hador",OFS_X_SWORDOFHADOR,OFS_Y_SWORDOFHADOR);	// Reverse Olrox
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROQ + (0x1 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Fury Plate",OFS_X_FURYPLATE,OFS_Y_FURYPLATE);	// Reverse Colosseum (holy sword)
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCO + (0x0 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Goddess Shield",OFS_X_GODDESSSHIELD,OFS_Y_GODDESSSHIELD);	// Reverse Alchemy (sunglasses)
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x3 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Shotel",OFS_X_SHOTEL,OFS_Y_SHOTEL);	// Reverse Outer Wall
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROW + (0x1 * 2);
	XB_AddLocationLocks(Loc,4,RID_FormOfMist,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	

	Loc = XB_AddLocation("R.Caverns Diamond",OFS_X_RCAVERNSDIAMOND,OFS_Y_RCAVERNSDIAMOND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0xD * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("R.Caverns Garnet",OFS_X_RCAVERNSGARNET,OFS_Y_RCAVERNSGARNET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x4 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Shield",OFS_X_ALUCARDSHIELD,OFS_Y_ALUCARDSHIELD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x0 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Sword",OFS_X_ALUCARDSWORD,OFS_Y_ALUCARDSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAM + (0x2 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Necklace Of J",OFS_X_NECKLACEOFJ,OFS_Y_NECKLACEOFJ);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCC + (0xD * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("R.Catacombs Diamond",OFS_X_RCATACOMBSDIAMOND,OFS_Y_RCATACOMBSDIAMOND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCC + (0xE * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Talisman",OFS_X_TALISMAN,OFS_Y_TALISMAN);		// Reverse Castle Entrance (Across from Save Room near Cube of Zoe)
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCE + (0x9 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Staurolite",OFS_X_STAUROLITE,OFS_Y_STAUROLITE);	// Reverse Library Mist Gate
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x8 * 2);
	XB_AddLocationLocks(Loc,4,RID_FormOfMist,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Moon Rod",OFS_X_MOONROD,OFS_Y_MOONROD);		// Reverse Clock Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0xB * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Luminus",OFS_X_LUMINUS,OFS_Y_LUMINUS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x3 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);			
	
	Loc = XB_AddLocation("Twilight Cloak",OFS_X_TWILIGHTCLOAK,OFS_Y_TWILIGHTCLOAK);	// Reverse Chapel Mist Gate
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RRC + (0x10 * 2);
	XB_AddLocationLocks(Loc,4,RID_FormOfMist,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Gram",OFS_X_GRAM,OFS_Y_GRAM);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCO + (0x3 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Katana",OFS_X_KATANA,OFS_Y_KATANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x5 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("R.Caverns Opal",OFS_X_RCAVERNSOPAL,OFS_Y_RCAVERNSOPAL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0xB * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Osafune Katana",OFS_X_OSAFUNEKATANA,OFS_Y_OSAFUNEKATANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x1A * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Beryl Circlet",OFS_X_BERYLCIRCLET,OFS_Y_BERYLCIRCLET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCE + (0x6 * 2);
	XB_AddLocationLocks(Loc,3,RID_SoulOfBat,RID_SoulOfWolf,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("F.Library Opal", OFS_X_FLIB_OPAL, OFS_Y_FLIB_OPAL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x1 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Badelaire", OFS_X_BADELAIRE, OFS_Y_BADELAIRE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x7 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
}

// Based on Guarded
void XB_SetupLocations_Spread()
{
	int Loc;
	
	XB_SetupLocations_Guarded();
	Loc = XB_AddLocation("F.Library Opal", OFS_X_FLIB_OPAL, OFS_Y_FLIB_OPAL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x1 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Badelaire", OFS_X_BADELAIRE, OFS_Y_BADELAIRE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x7 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
}

// Glitch is not based on any other setup function.
void XB_SetupLocations_Glitch()
{
	int Loc;
	
	Loc = XB_AddLocation("Soul of Bat", OFS_X_SOULOFBAT,OFS_Y_SOULOFBAT);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,3,RID_SoulOfBat,RID_HR1,RID_HR2);
	XB_AddLocationLocks(Loc,3,RID_LeapStone,RID_HR1,RID_HR2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_HR1,RID_HR2);
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_HR1,RID_HR2);
	XB_AddLocationLocks(Loc,3,RID_Thrust,RID_HR1,RID_HR2);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Fire of Bat", OFS_X_FIREOFBAT,OFS_Y_FIREOFBAT);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,4,RID_LeapStone,RID_SoulOfWolf,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_LeapStone,RID_SoulOfWolf,RID_FB,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Echo of Bat", OFS_X_ECHOOFBAT,OFS_Y_ECHOOFBAT);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_HR1,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_HR2,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_ShieldRod,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_HR1,RID_FB,RID_Thrust);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_HR2,RID_FB,RID_Thrust);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_ShieldRod,RID_FB,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Force of Echo", OFS_X_FORCEOFECHO,OFS_Y_FORCEOFECHO);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Soul of Wolf", OFS_X_SOULOFWOLF,OFS_Y_SOULOFWOLF);

	Loc = XB_AddLocation("Power of Wolf", OFS_X_POWEROFWOLF,OFS_Y_POWEROFWOLF);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,4,RID_LeapStone,RID_SoulOfWolf,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_LeapStone,RID_SoulOfWolf,RID_FB,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Skill of Wolf", OFS_X_SKILLOFWOLF,OFS_Y_SKILLOFWOLF);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetSkillOfWolf);
	
	
	Loc = XB_AddLocation("Form of Mist", OFS_X_FORMOFMIST,OFS_Y_FORMOFMIST);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_Toadstool);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Power of Mist", OFS_X_POWEROFMIST,OFS_Y_POWEROFMIST);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Gas Cloud", OFS_X_GASCLOUD,OFS_Y_GASCLOUD);	// This is based on Force of Echo, Which has the Fire Boomerang Jumping in, But Gas Cloud does not. Why? who knows.
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Cube of Zoe", OFS_X_CUBEOFZOE,OFS_Y_CUBEOFZOE);
	
	XB_AddLocation("Spirit Orb", OFS_X_SPIRITORB,OFS_Y_SPIRITORB);
	
	Loc = XB_AddLocation("Gravity Boots", OFS_X_GRAVITYBOOTS,OFS_Y_GRAVITYBOOTS);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FB,RID_FormOfMist);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FB,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Leap Stone", OFS_X_LEAPSTONE,OFS_Y_LEAPSTONE);
	
	Loc = XB_AddLocation("Holy Symbol", OFS_X_HOLYSYMBOL,OFS_Y_HOLYSYMBOL);
	XB_AddLocationLocks(Loc,2,RID_MermanStatue,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,2,RID_MermanStatue,RID_HR1);
	XB_AddLocationLocks(Loc,2,RID_MermanStatue,RID_HR2);
	XB_AddLocationLocks(Loc,3,RID_MermanStatue,RID_ShieldRod,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_MermanStatue,RID_ShieldRod,RID_Thrust);
	XB_AddLocationLocks(Loc,4,RID_MermanStatue,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Faerie Scroll", OFS_X_FAERIESCROLL,OFS_Y_FAERIESCROLL);
	
	Loc = XB_AddLocation("Jewel of Open", OFS_X_JEWELOFOPEN,OFS_Y_JEWELOFOPEN);		// Namakura Diamond Plate521 		demon card at jewel for glitch
	XB_AddLocationLocks(Loc,2,RID_SwordCard,RID_Diamond);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetJewelOfOpen);
	
	Loc = XB_AddLocation("Merman Statue", OFS_X_MERMANSTATUE,OFS_Y_MERMANSTATUE);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);
	XB_AddLocationLocks(Loc,1,RID_HR2);
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bat Card", OFS_X_BATCARD,OFS_Y_BATCARD);
	XB_AddLocationLocks(Loc,1,RID_HR1);
	XB_AddLocationLocks(Loc,1,RID_HR2);
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetBatCard);

	Loc = XB_AddLocation("Ghost Card", OFS_X_GHOSTCARD,OFS_Y_GHOSTCARD);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Faerie Card", OFS_X_FAERIECARD,OFS_Y_FAERIECARD);	// PSX has this layer 0, no locks.
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Demon Card", OFS_X_DEMONCARD,OFS_Y_DEMONCARD);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);									// Normal
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);	// Wolf Stair Clip
	XB_AddLocationLocks(Loc,1,RID_HR1);											// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);											// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);						// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);						// RSL
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("Sword Card", OFS_X_SWORDCARD,OFS_Y_SWORDCARD);
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_ShieldRod);			// Wolf + Thrust Rise + RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_HR1);
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_HR2);
	
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_HR1);							// Mist Rise + RSL
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_HR2);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_ShieldRod);
	
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_ShieldRod);					// Gravity + RSL
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HR1);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HR2);
	
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);						// Fake Flight
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Heart of Vlad", OFS_X_HEARTOFVLAD,OFS_X_HEARTOFVLAD);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetHeartOfVlad);
	
	Loc = XB_AddLocation("Tooth of Vlad", OFS_X_TOOTHOFVLAD,OFS_X_TOOTHOFVLAD);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetToothOfVlad);

	Loc = XB_AddLocation("Rib of Vlad", OFS_X_RIBOFVLAD,OFS_X_RIBOFVLAD);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRibOfVlad);
	
	Loc = XB_AddLocation("Ring of Vlad", 0, 0);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRingOfVlad);
	
	Loc = XB_AddLocation("Eye of Vlad", OFS_X_EYEOFVLAD, OFS_Y_EYEOFVLAD);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetEyeOfVlad);
	
	Loc = XB_AddLocation("Gold Ring", OFS_X_GOLDRING, OFS_Y_GOLDRING);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_LeapStone);		// Jewel + Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_LeapStone);		// Jewel + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_LeapStone);		// Jewel + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_SoulOfWolf);		// Jewel + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_FormOfMist);		// Jewel + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_Thrust);			// Jewel + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);		// Jewel + Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_Thrust);			// Jewel + Mist + Thrust
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_SoulOfWolf);		// Jewel + Wolf Mist Rise
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);						// Jewel + Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_SkillOfWolf);		// Jewel + Wolf + Skill
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_FB);				// Jewel + Wolf + FB
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_Thrust);			// Jewel + Wolf + Thrust
	
	// Jewel Sub HR
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_LeapStone);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_LeapStone);		// HR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_FormOfMist,RID_LeapStone);		// HR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_SoulOfWolf);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_Thrust);			// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_FormOfMist,RID_PowerOfMist);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_FormOfMist,RID_Thrust);			// HR + Mist + Thrust
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_FormOfMist,RID_SoulOfWolf);		// HR + Wolf Mist Rise
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_SoulOfBat);						// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_SkillOfWolf);		// HR + Wolf + Skill
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_FB);				// HR + Wolf + FB
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_Thrust);			// HR + Wolf + Thrust
	// Jewel Sub HR2
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_LeapStone);		// HR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_FormOfMist,RID_LeapStone);		// HR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_SoulOfWolf);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_Thrust);			// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_FormOfMist,RID_PowerOfMist);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_FormOfMist,RID_Thrust);			// HR + Mist + Thrust
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_FormOfMist,RID_SoulOfWolf);		// HR + Wolf Mist Rise
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_SoulOfBat);						// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_SkillOfWolf);		// HR + Wolf + Skill
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_FB);				// HR + Wolf + FB
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_Thrust);			// HR + Wolf + Thrust
	// Jewel Sub SR + Leap or Thrust
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_LeapStone);	// SR + Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_SoulOfWolf,RID_LeapStone);		// SR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_FormOfMist,RID_LeapStone);		// SR + Leap + Transform
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_Thrust);		// SR + Thrust + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_SoulOfWolf,RID_Thrust);			// SR + Thrust + Wolf Thrust Rise
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_FormOfMist,RID_Thrust);			// SR + Thrust + Mist Rise
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_SoulOfBat,RID_Thrust);			// SR + Thrust + Bat
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_SoulOfBat,RID_LeapStone);			// SR + Leap + Bat
	
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetGoldRing);
	
	//----------------------------
	
	Loc = XB_AddLocation("Silver Ring", OFS_X_SILVERRING, OFS_Y_SILVERRING);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_FormOfMist);
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_LeapStone);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_Thrust);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_Thrust);		// HR + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_Thrust);		// HR + Wolf Thrust Rise
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_Thrust);		// HR + Wolf Thrust Rise
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_FB);		// HR + Wolf + Fire Boomerang
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_FB);		// HR + Wolf + Fire Boomerang
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_SoulOfBat);		// HR + Bat
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_SoulOfBat);		// HR + Bat
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_FormOfMist,RID_PowerOfMist);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_FormOfMist,RID_PowerOfMist);		// HR + Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_LeapStone,RID_GravityBoots);		// SR + Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_FormOfMist,RID_PowerOfMist);		// SR + Flight
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_SoulOfBat);							// SR + Bat
	XB_AddLocationLocks(Loc,4,RID_ShieldRod,RID_LeapStone,RID_SoulOfWolf,RID_FB);		// SR + Fire Boomerang Jumps
	XB_AddLocationLocks(Loc,4,RID_ShieldRod,RID_LeapStone,RID_SoulOfWolf,RID_Thrust);		// SR + Wolf Thrust Rise
	XB_AddLocationLocks(Loc,4,RID_ShieldRod,RID_LeapStone,RID_SoulOfWolf,RID_FormOfMist);		// SR + Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_ShieldRod,RID_LeapStone,RID_Thrust,RID_FormOfMist);		// SR + Thrust Mist Rise
	// Scr Freeze + Get Over Hill, way to get on top or way to get in + Jewel
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Glasses", OFS_X_HOLYGLASSES, OFS_Y_HOLYGLASSES);	// Will need to look into speeding up HR for these.
	XB_AddLocationLocks(Loc,2,RID_GoldRing,RID_SilverRing);	// escape reqs needed if we go with just this, or we dont put one ring at flight locked
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);	// Wolf Stair Clip and go Left.
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_SoulOfWolf);	// 2x HR + Transform
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_FormOfMist);	// 2x HR + Transform
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_SoulOfBat);	// 2x HR + Transform
	//XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_GravityBoots);	// 2x HR + Gravity Boots (Drop in from up top?)
	XB_EndLocationLocks(Loc);
	//XB_AddLocationFunction(Loc,&XB_SetHolyGlasses);
	
	Loc = XB_AddLocation("Spikebreaker", OFS_X_SPIKEBREAKER, OFS_Y_SPIKEBREAKER);	// 
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);										// Jewel + Blind Bat
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone,RID_Spikebreaker);						// Jewel + Leap Stone + SB
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_Spikebreaker);					// Jewel + Grav + SB
	XB_AddLocationLocks(Loc,4,RID_JewelOfOpen,RID_SoulOfWolf,RID_FB,RID_Spikebreaker);				// Jewel + Wolf Fire Boomerang Jump + SB
	XB_AddLocationLocks(Loc,4,RID_JewelOfOpen,RID_SoulOfWolf,RID_Thrust,RID_Spikebreaker);			// Jewel + Wolf Thrust Rise + SB
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone,RID_ShieldRod);							// Jewel + Leap Stone + Shield Rod
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_ShieldRod);						// Jewel + Grav + Shield Rod
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);						// Jewel + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_Spikebreaker);						// Jewel + Mist Rise + SB
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);						// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_LeapStone);												// HR + Leap (RSL)
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_LeapStone);												// HR + Leap (RSL)
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_GravityBoots);											// HR + Grav (RSL)
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_GravityBoots);											// HR + Grav (RSL)
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_FB);										// HR + Wolf Fire Boomerang Jump (RSL)
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_FB);										// HR + Wolf Fire Boomerang Jump (RSL)
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_FormOfMist);												// HR + Mist Rise (RSL)
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_FormOfMist);												// HR + Mist Rise (RSL)
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_Thrust);									// HR + Wolf Thrust Rise (RSL)
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_Thrust);									// HR + Wolf Thrust Rise (RSL)
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);											// SR + Leap (RSL)
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_GravityBoots);							// SR + Thrust + Grav (RSL)
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_SoulOfWolf);								// SR + Thrust + Wolf (RSL)
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_FormOfMist);								// SR + Thrust + Mist (RSL)	
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Crystal Cloak", OFS_X_CRYSTALCLOAK,OFS_Y_CRYSTALCLOAK);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Mormegil", OFS_X_MORMEGIL,OFS_Y_MORMEGIL);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Trio", OFS_X_TRIO, OFS_Y_TRIO);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetTrio);
	
	Loc = XB_AddLocation("Ring of Arcana", OFS_X_RINGOFARCANA, OFS_Y_RINGOFARCANA);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Dark Blade", OFS_X_DARKBLADE, OFS_Y_DARKBLADE);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Mail",OFS_X_HOLYMAIL,OFS_Y_HOLYMAIL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CE + (0x5 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Jewel Sword",OFS_X_JEWELSWORD,OFS_Y_JEWELSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CE + (0x9 * 2);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_Thrust,RID_HR1,RID_HR2,RID_FormOfMist);		// Shift Line?
	XB_AddLocationLocks(Loc,2,RID_LeapStone,RID_HR1,RID_HR2,RID_FormOfMist);			// Shift Line?
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Cloth Cape",OFS_X_CLOTHCAPE,OFS_Y_CLOTHCAPE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x2 * 2);
	
	Loc = XB_AddLocation("Sunglasses",OFS_X_SUNGLASSES,OFS_Y_SUNGLASSES);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x6 * 2);
	
	Loc = XB_AddLocation("Gladius",OFS_X_GLADIUS,OFS_Y_GLADIUS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OW + (0x4 * 2);
	
	Loc = XB_AddLocation("Bronze Cuirass",OFS_X_BRONZECUIRASS,OFS_Y_BRONZECUIRASS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x4 * 2);
	
	Loc = XB_AddLocation("Holy Rod",OFS_X_HOLYROD,OFS_Y_HOLYROD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Library Onyx",OFS_X_LIBRARYONYX,OFS_Y_LIBRARYONYX);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_LIB + (0x6 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Falchion",OFS_X_FALCHION,OFS_Y_FALCHION);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CK + (0xC * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_FB);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Ankh Of Life",OFS_X_ANKHOFLIFE,OFS_Y_ANKHOFLIFE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x0 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_Thrust,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Morningstar",OFS_X_MORNINGSTAR,OFS_Y_MORNINGSTAR);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_FB);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_PowerOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Cutlass",OFS_X_CUTLASS,OFS_Y_CUTLASS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0xE * 2);
	
	Loc = XB_AddLocation("Broadsword",OFS_X_BROADSWORD,OFS_Y_BROADSWORD);	// Olrox 3 Vase Room behind Breakable Wall
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_Toadstool);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Estoc",OFS_X_ESTOC,OFS_Y_ESTOC);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0xA * 2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);					// Flight
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);					// Fake Flight
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);					// Flight
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);									// Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_HR1);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_HR2);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_Thrust,RID_HR1);		// Glitch in through Chapel Connection, then FB Jump and Wolf Thrust Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_Thrust,RID_HR2);		// Glitch in through Chapel Connection, then FB Jump and Wolf Thrust Rise	
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_ShieldRod);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_Thrust,RID_ShieldRod);		// Glitch in through Chapel Connection, then FB Jump and Wolf Thrust Rise
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Olrox Garnet",OFS_X_OLROXGARNET,OFS_Y_OLROXGARNET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OQ + (0xC * 2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_SoulOfWolf);					// Fake Flight
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_HR1);		// Glitch in through Chapel Connection, then Wolf Thrust Rise	
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_HR2);		// Glitch in through Chapel Connection, then Wolf Thrust Rise	
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_Thrust,RID_ShieldRod);		// Glitch in through Chapel Connection, then Wolf Thrust Rise
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HR1);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HR2);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_ShieldRod);
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_HR1);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_HR2);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_FB,RID_FormOfMist,RID_ShieldRod);	// Glitch in through Chapel Connection, then FB Jump and Wolf Mist Rise
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Shield Rod",OFS_X_SHIELDROD,OFS_Y_SHIELDROD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_Toadstool);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Blood Cloak",OFS_X_BLOODCLOAK,OFS_Y_BLOODCLOAK);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x3 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_Toadstool);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Sword",OFS_X_HOLYSWORD,OFS_Y_HOLYSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_LeapStone,RID_CubeOfZoe);
	XB_AddLocationLocks(Loc,2,RID_Thrust,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_Thrust,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Knight Shield",OFS_X_KNIGHTSHIELD,OFS_Y_KNIGHTSHIELD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CO + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,1,RID_Toadstool);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bandanna", OFS_X_BANDANNA,OFS_Y_BANDANNA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0xB * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Secret Boots", OFS_X_SECRETBOOTS,OFS_Y_SECRETBOOTS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x1F * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Knuckle Duster", OFS_X_KNUCKLEDUSTER,OFS_Y_KNUCKLEDUSTER);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x17 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Caverns Onyx", OFS_X_CAVERNSONYX,OFS_Y_CAVERNSONYX);		// Must be able to get up to ledge
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x16 * 2);
	
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_MermanStatue);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_MermanStatue);												// RSL
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_MermanStatue);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);												// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_MermanStatue);								// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);							// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);							// Wolf Clip + Mist
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_LeapStone);												// RSL
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_LeapStone);												// RSL
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_GravityBoots);												// RSL
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_GravityBoots);												// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_GravityBoots);								// RSL	
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_FormOfMist);								// RSL	
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_SoulOfBat);								// RSL	
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_FormOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Combat Knife", OFS_X_COMBATKNIFE,OFS_Y_COMBATKNIFE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AM + (0x5 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bloodstone", OFS_X_BLOODSTONE,OFS_Y_BLOODSTONE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x8 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Icebrand", OFS_X_ICEBRAND,OFS_Y_ICEBRAND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x1 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_FormOfMist);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_FB);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_HR1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_HR2,RID_FormOfMist);
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_FB);
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_FB);
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_SoulOfWolf);				// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_FormOfMist);				// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_GravityBoots);			// RSL
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_Thrust,RID_SoulOfBat);				// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Walk Armor", OFS_X_WALKARMOR,OFS_Y_WALKARMOR);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Basilard", OFS_X_BASILARD,OFS_Y_BASILARD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AL + (0x9 * 2);
	
	Loc = XB_AddLocation("Alucart Sword",OFS_X_ALUCARTSWORD,OFS_Y_ALUCARTSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_MG + (0x7 * 2);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_CubeOfZoe,RID_Toadstool);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Jewel Knuckles", OFS_X_JEWELKNUCKLES,OFS_Y_JEWELKNUCKLES);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_OW + (0x0 * 2);
	
	Loc = XB_AddLocation("Bekatowa",OFS_X_BEKATOWA,OFS_Y_BEKATOWA);		// Clock Tower 3 Pillars
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CT + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,1,RID_FormOfMist);
	XB_AddLocationLocks(Loc,1,RID_Thrust);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Gold Plate",OFS_X_GOLDPLATE,OFS_Y_GOLDPLATE);		// Clock Tower Puzzle
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CT + (0x4 * 2);
	
	Loc = XB_AddLocation("Platinum Mail",OFS_X_PLATINUMMAIL,OFS_Y_PLATINUMMAIL);	// Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CK + (0xB * 2);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	//XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_LeapStone,RID_FB);		// Extremely Annoying
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Mystic Pendant",OFS_X_MYSTICPENDANT,OFS_Y_MYSTICPENDANT);	// Chapel
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,2,RID_Thrust,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Goggles",OFS_X_GOGGLES,OFS_Y_GOGGLES);	// Chapel
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x9 * 2);
	
	Loc = XB_AddLocation("Silver Plate",OFS_X_SILVERPLATE,OFS_Y_SILVERPLATE);	// Top of Chapel West Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0xA * 2);
	
	Loc = XB_AddLocation("Nunchaku",OFS_X_NUNCHAKU,OFS_Y_NUNCHAKU);	// Caverns
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x24 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_PowerOfWolf,RID_FormOfMist);		// Wolf Clip + Mist
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Ring of Ares",OFS_X_RINGOFARES,OFS_Y_RINGOFARES);	// Mines behind Demon Switch
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_AM + (0x4 * 2);
	XB_AddLocationLocks(Loc,2,RID_DemonCard,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,4,RID_DemonCard,RID_SoulOfWolf,RID_PowerOfWolf,RID_SoulOfBat);		// Wolf Clip + Flight
	XB_AddLocationLocks(Loc,1,RID_HR1);												// RSL
	XB_AddLocationLocks(Loc,1,RID_HR2);												// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_LeapStone);							// RSL
	XB_AddLocationLocks(Loc,2,RID_ShieldRod,RID_Thrust);							// RSL
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("Bastard Sword",OFS_X_BASTARDSWORD,OFS_Y_BASTARDSWORD);	// Reverse Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x4 * 2);
	// standardish Castle 2
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	// unique
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_PowerOfWolf);
	//XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_LeapStone,RID_FB);		// Extremely Annoying
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_GravityBoots);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Royal Cloak",OFS_X_ROYALCLOAK,OFS_Y_ROYALCLOAK);	// Reverse Keep Attic
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0xB * 2);
	// standardish Castle 2
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	// unique
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_Thrust);
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_PowerOfWolf);
	//XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_LeapStone,RID_FB);		// Extremely Annoying
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_HR2,RID_GravityBoots);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sword of Dawn",OFS_X_SWORDOFDAWN,OFS_Y_SWORDOFDAWN);	// Reverse Keep, actually is the Garnet.
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x16 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Lightning Mail",OFS_X_LIGHTNINGMAIL,OFS_Y_LIGHTNINGMAIL);	// Reverse Keep
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCK + (0x17 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Dragon Helm",OFS_X_DRAGONHELM,OFS_Y_DRAGONHELM);	// Reverse Clock Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x5 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sun Stone",OFS_X_SUNSTONE,OFS_Y_SUNSTONE);	// Reverse Clock Tower Puzzle
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x8 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Talwar",OFS_X_TALWAR,OFS_Y_TALWAR);	// Reverse Chapel Middle Tower
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RRC + (0xD * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Mail",OFS_X_ALUCARDMAIL,OFS_Y_ALUCARDMAIL);	// Reverse Olrox
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROQ + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Sword Of Hador",OFS_X_SWORDOFHADOR,OFS_Y_SWORDOFHADOR);	// Reverse Olrox
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROQ + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Fury Plate",OFS_X_FURYPLATE,OFS_Y_FURYPLATE);	// Reverse Colosseum (holy sword)
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCO + (0x0 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Goddess Shield",OFS_X_GODDESSSHIELD,OFS_Y_GODDESSSHIELD);	// Reverse Alchemy (sunglasses)
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x3 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Shotel",OFS_X_SHOTEL,OFS_Y_SHOTEL);	// Reverse Outer Wall
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_ROW + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	

	Loc = XB_AddLocation("R.Caverns Diamond",OFS_X_RCAVERNSDIAMOND,OFS_Y_RCAVERNSDIAMOND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0xD * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("R.Caverns Garnet",OFS_X_RCAVERNSGARNET,OFS_Y_RCAVERNSGARNET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x4 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Shield",OFS_X_ALUCARDSHIELD,OFS_Y_ALUCARDSHIELD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x0 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Alucard Sword",OFS_X_ALUCARDSWORD,OFS_Y_ALUCARDSWORD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAM + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Necklace Of J",OFS_X_NECKLACEOFJ,OFS_Y_NECKLACEOFJ);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCC + (0xD * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("R.Catacombs Diamond",OFS_X_RCATACOMBSDIAMOND,OFS_Y_RCATACOMBSDIAMOND);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCC + (0xE * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Talisman",OFS_X_TALISMAN,OFS_Y_TALISMAN);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCE + (0x9 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Staurolite",OFS_X_STAUROLITE,OFS_Y_STAUROLITE);	// Reverse Library Mist Gate
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x8 * 2);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_FormOfMist);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_GravityBoots,RID_FormOfMist);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,5,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB,RID_FormOfMist);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,4,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses,RID_FormOfMist);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,5,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone,RID_FormOfMist);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Moon Rod",OFS_X_MOONROD,OFS_Y_MOONROD);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0xB * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Luminus",OFS_X_LUMINUS,OFS_Y_LUMINUS);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCT + (0x3 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);			
	
	Loc = XB_AddLocation("Twilight Cloak",OFS_X_TWILIGHTCLOAK,OFS_Y_TWILIGHTCLOAK);	// Reverse Chapel Mist Gate
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RRC + (0x10 * 2);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_FormOfMist);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_GravityBoots,RID_FormOfMist);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,5,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB,RID_FormOfMist);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,4,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses,RID_FormOfMist);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,5,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone,RID_FormOfMist);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);	
	
	Loc = XB_AddLocation("Gram",OFS_X_GRAM,OFS_Y_GRAM);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCO + (0x3 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Katana",OFS_X_KATANA,OFS_Y_KATANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x5 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);

	Loc = XB_AddLocation("R.Caverns Opal",OFS_X_RCAVERNSOPAL,OFS_Y_RCAVERNSOPAL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0xB * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Osafune Katana",OFS_X_OSAFUNEKATANA,OFS_Y_OSAFUNEKATANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x1A * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Beryl Circlet",OFS_X_BERYLCIRCLET,OFS_Y_BERYLCIRCLET);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RCE + (0x6 * 2);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_SoulOfWolf);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("F.Library Opal", OFS_X_FLIB_OPAL, OFS_Y_FLIB_OPAL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x1 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Badelaire", OFS_X_BADELAIRE, OFS_Y_BADELAIRE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RLIB + (0x7 * 2);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);										// Bat RS
	XB_AddLocationLocks(Loc,3,RID_SoulOfWolf,RID_FormOfMist,RID_PowerOfMist);		// Wolf RS + PoM Flight
	XB_AddLocationLocks(Loc,2,RID_SoulOfWolf,RID_GravityBoots);						// Wolf RS + Fake Flight
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_FormOfMist,RID_FB);	// Wolf RS + Fire Boomerang + Mist Rising
	XB_AddLocationLocks(Loc,4,RID_SoulOfWolf,RID_LeapStone,RID_Thrust,RID_FB);		// Wolf RS + Fire Boomerang + Thrust Rising
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);		// Normal
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_FormOfMist,RID_HolyGlasses);		// HG + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_GravityBoots,RID_FormOfMist);		// SR + Mist Ric Skip + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_ShieldRod,RID_PowerOfMist,RID_FormOfMist);		// SR + Mist Ric Skip + Mist Flight
	XB_AddLocationLocks(Loc,4,RID_HR1,RID_HR2,RID_GravityBoots,RID_LeapStone);		// HR x2 Ric Skip + Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_GravityBoots,RID_FormOfMist);				// HR + Mist RS + Fake Flight
	XB_AddLocationLocks(Loc,3,RID_HR1,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_AddLocationLocks(Loc,3,RID_HR2,RID_PowerOfMist,RID_FormOfMist);				// HR + Mist RS + Mist Flight
	XB_EndLocationLocks(Loc);
}

void XB_SetupLocations_NoLogic(int LocSet)
{
	int Loc;
	
	XB_SetupLocations_Guarded();
	if(LocSet)
		XB_SetupLocations_Adventure();
	
	for(Loc = 0;Loc<MAX_LOC;Loc++)
	{
		XB_RelicChecks[Loc].Requirements[0][0] = 0;
	}
}

// Leg Day
// Based on Guarded
// So far, changed Spikebreaker location to require jewel + sb
void XB_SetupLocations_LegDay()
{	
	int Loc;
	
	Loc = XB_AddLocation("Soul of Bat", OFS_X_SOULOFBAT,OFS_Y_SOULOFBAT);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Fire of Bat", OFS_X_FIREOFBAT,OFS_Y_FIREOFBAT);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Echo of Bat", OFS_X_ECHOOFBAT,OFS_Y_ECHOOFBAT);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_SoulOfWolf);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_FormOfMist);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Force of Echo", OFS_X_FORCEOFECHO,OFS_Y_FORCEOFECHO);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Soul of Wolf", OFS_X_SOULOFWOLF,OFS_Y_SOULOFWOLF);

	Loc = XB_AddLocation("Power of Wolf", OFS_X_POWEROFWOLF,OFS_Y_POWEROFWOLF);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Skill of Wolf", OFS_X_SKILLOFWOLF,OFS_Y_SKILLOFWOLF);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetSkillOfWolf);
	
	
	Loc = XB_AddLocation("Form of Mist", OFS_X_FORMOFMIST,OFS_Y_FORMOFMIST);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Power of Mist", OFS_X_POWEROFMIST,OFS_Y_POWEROFMIST);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Gas Cloud", OFS_X_GASCLOUD,OFS_Y_GASCLOUD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Cube of Zoe", OFS_X_CUBEOFZOE,OFS_Y_CUBEOFZOE);
	
	XB_AddLocation("Spirit Orb", OFS_X_SPIRITORB,OFS_Y_SPIRITORB);
	
	Loc = XB_AddLocation("Gravity Boots", OFS_X_GRAVITYBOOTS,OFS_Y_GRAVITYBOOTS);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Leap Stone", OFS_X_LEAPSTONE,OFS_Y_LEAPSTONE);
	XB_AddLocationLocks(Loc,1,RID_LeapStone);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Symbol", OFS_X_HOLYSYMBOL,OFS_Y_HOLYSYMBOL);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_MermanStatue);
	XB_EndLocationLocks(Loc);
	
	XB_AddLocation("Faerie Scroll", OFS_X_FAERIESCROLL,OFS_Y_FAERIESCROLL);
	
	Loc = XB_AddLocation("Jewel of Open", OFS_X_JEWELOFOPEN,OFS_Y_JEWELOFOPEN);
	XB_AddLocationFunction(Loc,&XB_SetJewelOfOpen);
	
	Loc = XB_AddLocation("Merman Statue", OFS_X_MERMANSTATUE,OFS_Y_MERMANSTATUE);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Bat Card", OFS_X_BATCARD,OFS_Y_BATCARD);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetBatCard);

	Loc = XB_AddLocation("Ghost Card", OFS_X_GHOSTCARD,OFS_Y_GHOSTCARD);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Faerie Card", OFS_X_FAERIECARD,OFS_Y_FAERIECARD);
	XB_AddLocationLocks(Loc,1,RID_GravityBoots);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Demon Card", OFS_X_DEMONCARD,OFS_Y_DEMONCARD);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);	
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);	// This requires escape reqs or PatchMines()
	XB_EndLocationLocks(Loc);


	Loc = XB_AddLocation("Sword Card", OFS_X_SWORDCARD,OFS_Y_SWORDCARD);
	XB_AddLocationLocks(Loc,2,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,2,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,1,RID_SoulOfBat);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Heart of Vlad", OFS_X_HEARTOFVLAD,OFS_X_HEARTOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetHeartOfVlad);
	
	Loc = XB_AddLocation("Tooth of Vlad", OFS_X_TOOTHOFVLAD,OFS_X_TOOTHOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetToothOfVlad);

	Loc = XB_AddLocation("Rib of Vlad", OFS_X_RIBOFVLAD,OFS_X_RIBOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRibOfVlad);
	
	Loc = XB_AddLocation("Ring of Vlad", 0, 0);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetRingOfVlad);
	
	Loc = XB_AddLocation("Eye of Vlad", OFS_X_EYEOFVLAD, OFS_Y_EYEOFVLAD);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetEyeOfVlad);
	
	Loc = XB_AddLocation("Gold Ring", OFS_X_GOLDRING, OFS_Y_GOLDRING);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_GravityBoots,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	// add wolf + skill (psx doesn't include this)
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetGoldRing);
	
	Loc = XB_AddLocation("Silver Ring", OFS_X_SILVERRING, OFS_Y_SILVERRING);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RC + (0x2 * 2);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_Spikebreaker);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Holy Glasses", OFS_X_HOLYGLASSES, OFS_Y_HOLYGLASSES);
	XB_AddLocationLocks(Loc,2,RID_GoldRing,RID_SilverRing);	// escape reqs needed if we go with just this, or we dont put one ring at flight locked
	XB_EndLocationLocks(Loc);
	//XB_AddLocationFunction(Loc,&XB_SetHolyGlasses);
	
	Loc = XB_AddLocation("Spikebreaker", OFS_X_SPIKEBREAKER, OFS_Y_SPIKEBREAKER);	
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x10 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_Spikebreaker);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Crystal Cloak", OFS_X_CRYSTALCLOAK,OFS_Y_CRYSTALCLOAK);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_UC + (0x2 * 2);
	XB_AddLocationLocks(Loc,1,RID_JewelOfOpen);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Mormegil", OFS_X_MORMEGIL,OFS_Y_MORMEGIL);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_CC + (0x3 * 2);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_LeapStone);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_FormOfMist,RID_PowerOfMist);
	XB_AddLocationLocks(Loc,2,RID_JewelOfOpen,RID_SoulOfBat);
	XB_AddLocationLocks(Loc,3,RID_JewelOfOpen,RID_SoulOfWolf,RID_PowerOfWolf);	// This requires escape reqs or PatchMines()
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Trio", OFS_X_TRIO, OFS_Y_TRIO);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	XB_AddLocationFunction(Loc,&XB_SetTrio);
	
	Loc = XB_AddLocation("Ring of Arcana", OFS_X_RINGOFARCANA, OFS_Y_RINGOFARCANA);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RAL + (0x8 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
	
	Loc = XB_AddLocation("Dark Blade", OFS_X_DARKBLADE, OFS_Y_DARKBLADE);
	XB_RelicChecks[Loc].Equipment = 1;
	XB_RelicChecks[Loc].EQ_List_Ofs = EQ_RUC + (0x17 * 2);
	XB_AddLocationLocks(Loc,3,RID_GravityBoots,RID_LeapStone,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,3,RID_FormOfMist,RID_PowerOfMist,RID_HolyGlasses);
	XB_AddLocationLocks(Loc,2,RID_SoulOfBat,RID_HolyGlasses);
	XB_EndLocationLocks(Loc);
}
