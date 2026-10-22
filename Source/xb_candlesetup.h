// xb_candlesetup.h

#ifndef CandleContents
char CandleContents[128][32] = { "Small Heart", "Big Heart", "$1", "$25", "$50", "$100", "$250", "$400", "$700", "$1000", "$2000", "$5000", "Heart Max", "Turkey", "Knife", "Axe", "Cross", "Holy Water", "Stopwatch", "Bible", "Rebound Stone", "Vibhuti", "Agunea","Life Max"};
#endif

void XB_CandleSetup()
{
	const int DebugToConsole = 0;
	int ItemN;
	
	XB_CandleReset();
	
	// Marble Gallery
	// #1
	XB_CandleAdd(0x0,0xd56de4,0xd57e42);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56dee,0xd57e38);	// Candle: Holy Water
	XB_CandleAdd(0x0,0xd56e20,0xd57e2e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e2a,0xd57e24);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e34,0xd57d20);	// Candle: $1
	XB_CandleAdd(0x0,0xd56e3e,0xd57e1a);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56e48,0xd57cee);	// Candle: $25
	XB_CandleAdd(0x0,0xd56e52,0xd57d2a);	// Candle: $1
	XB_CandleAdd(0x0,0xd56e5c,0xd57e10);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e66,0xd57ce4);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e70,0xd57e06);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e7a,0xd57d34);	// Candle: $1
	XB_CandleAdd(0x0,0xd56e84,0xd57cda);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56e8e,0xd57d3e);	// Candle: $1
	XB_CandleAdd(0x0,0xd56eac,0xd57dfc);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56eb6,0xd57cd0);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56ec0,0xd57d48);	// Candle: $250
	XB_CandleAdd(0x0,0xd56eca,0xd57df2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56ed4,0xd57de8);	// Candle: $25
	XB_CandleAdd(0x0,0xd56ede,0xd57d52);	// Candle: $1
	XB_CandleAdd(0x0,0xd56ee8,0xd57cc6);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56ef2,0xd57dde);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56efc,0xd57cbc);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56f06,0xd57d5c);	// Candle: $1
	XB_CandleAdd(0x0,0xd56f10,0xd57dd4);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56f1a,0xd57dca);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56f24,0xd57d66);	// Candle: $1
	XB_CandleAdd(0x0,0xd56f2e,0xd57dc0);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56f56,0xd57c9e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56f60,0xd57d98);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56f6a,0xd57da2);	// Candle: Knife
	XB_CandleAdd(0x0,0xd56f74,0xd57c94);	// Candle: Small Heart
	// #2
	XB_CandleAdd(0x0,0xd56fa2,0xd57e84);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56fac,0xd57e98);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56fb6,0xd57eac);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56fc0,0xd57ec0);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd56fca,0xd57e7a);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56fd4,0xd57e8e);	// Candle: $100
	XB_CandleAdd(0x0,0xd56fde,0xd57ea2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd56fe8,0xd57eb6);	// Candle: Small Heart
	// #3
	XB_CandleAdd(0x0,0xd5702e,0xd57fb0);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57038,0xd57fce);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57056,0xd57ef2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57074,0xd57efc);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57088,0xd57f4c);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57092,0xd57f56);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5709c,0xd57f92);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570a6,0xd57fe2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570b0,0xd57f06);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570ba,0xd57f60);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd570c4,0xd57f74);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570ce,0xd57f10);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570d8,0xd57f7e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570ec,0xd57f9c);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd570f6,0xd57fec);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57114,0xd57f1a);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57128,0xd57f24);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57150,0xd57f6a);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5715a,0xd57f88);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57164,0xd58000);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x0,0xd57182,0xd5805a);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5718c,0xd58064);	// Candle: Knife
	XB_CandleAdd(0x0,0xd571a0,0xd5806e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd571aa,0xd58078);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x0,0xd571ca,0xd580a2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd571d4,0xd580ac);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd571de,0xd580b6);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd571e8,0xd580c0);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd571fc,0xd580ca);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57206,0xd580d4);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5721a,0xd580de);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57224,0xd580e8);	// Candle: $25
	// #7
	XB_CandleAdd(0x0,0xd5724c,0xd58124);	// Candle: Holy Water
	XB_CandleAdd(0x0,0xd57256,0xd5812e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57288,0xd58138);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57292,0xd58142);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x0,0xd572b2,0xd581bc);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd572bc,0xd58202);	// Candle: Rebound Stone
	XB_CandleAdd(0x0,0xd572c6,0xd5819e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd572d0,0xd581c6);	// Candle: $50
	XB_CandleAdd(0x0,0xd572da,0xd5820c);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57302,0xd5818a);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd5730c,0xd581f8);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57320,0xd581d0);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd5732a,0xd58194);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57334,0xd581e4);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0x0,0xd57362,0xd5823a);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5736c,0xd58244);	// Candle: Stopwatch
	XB_CandleAdd(0x0,0xd57380,0xd58262);	// Candle: Bible
	XB_CandleAdd(0x0,0xd573a8,0xd5824e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd573b2,0xd58258);	// Candle: Big Heart
	// #10
	XB_CandleAdd(0x0,0xd573dc,0xd582e6);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd573e6,0xd582b4);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd573f0,0xd582dc);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd573fa,0xd582fa);	// Candle: $25
	XB_CandleAdd(0x0,0xd57404,0xd582aa);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5740e,0xd58304);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57436,0xd5830e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5744a,0xd582be);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0x0,0xd5747e,0xd5837e);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57488,0xd58388);	// Candle: $25
	XB_CandleAdd(0x0,0xd5749c,0xd58392);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd574a6,0xd5839c);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd574b0,0xd583a6);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd574c4,0xd583b0);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd574ce,0xd583ba);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd574ec,0xd5834c);	// Candle: $250
	XB_CandleAdd(0x0,0xd57500,0xd583c4);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5750a,0xd583ce);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5751e,0xd583d8);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57528,0xd583e2);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57532,0xd583ec);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57546,0xd583f6);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57550,0xd58400);	// Candle: Axe
	// #15
	XB_CandleAdd(0x0,0xd5777e,0xd58656);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57792,0xd58660);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x0,0xd57942,0xd58848);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57956,0xd5882a);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd5796a,0xd58834);	// Candle: Big Heart
	// #23
	XB_CandleAdd(0x0,0xd57a74,0xd58952);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57a7e,0xd58970);	// Candle: Small Heart
	XB_CandleAdd(0x0,0xd57a88,0xd5895c);	// Candle: Big Heart
	XB_CandleAdd(0x0,0xd57a92,0xd58966);	// Candle: $25
	
	// Outer Wall
	// #1
	XB_CandleAdd(0x1,0xd4edde,0xd4f68a);	// Candle: Bible
	// #2
	XB_CandleAdd(0x1,0xd4ee1c,0xd4f6be);	// Candle: Small Heart
	// #3
	XB_CandleAdd(0x1,0xd4ee80,0xd4f72c);	// Candle: Big Heart
	XB_CandleAdd(0x1,0xd4ee9e,0xd4f736);	// Candle: $50
	// #4
	XB_CandleAdd(0x1,0xd4eee6,0xd4f7f6);	// Candle: Knife
	XB_CandleAdd(0x1,0xd4ef54,0xd4f79c);	// Candle: Big Heart
	XB_CandleAdd(0x1,0xd4ef5e,0xd4f85a);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4ef68,0xd4f850);	// Candle: $100
	XB_CandleAdd(0x1,0xd4ef72,0xd4f7a6);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4ef7c,0xd4f864);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4efe0,0xd4f7ec);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0x1,0xd4f10a,0xd4f9de);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4f11e,0xd4f9d4);	// Candle: $25
	XB_CandleAdd(0x1,0xd4f128,0xd4f9ca);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x1,0xd4f16e,0xd4fa2e);	// Candle: Big Heart
	XB_CandleAdd(0x1,0xd4f1aa,0xd4fa4c);	// Candle: Big Heart
	// #14
	XB_CandleAdd(0x1,0xd4f2ee,0xd4fd7a);	// Candle: $25
	XB_CandleAdd(0x1,0xd4f320,0xd4fc62);	// Candle: $100
	XB_CandleAdd(0x1,0xd4f3de,0xd4fbae);	// Candle: Heart Max
	XB_CandleAdd(0x1,0xd4f3f2,0xd4fc58);	// Candle: Big Heart
	XB_CandleAdd(0x1,0xd4f406,0xd4fd98);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4f410,0xd4fd3e);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4f41a,0xd4fcd0);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4f4ec,0xd4fcb2);	// Candle: $25
	XB_CandleAdd(0x1,0xd4f500,0xd4fc44);	// Candle: Small Heart
	XB_CandleAdd(0x1,0xd4f514,0xd4fc26);	// Candle: Small Heart
	
	// Long Library
	// #1
	XB_CandleAdd(0x2,0xd40872,0xd41120);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd4087c,0xd41012);	// Candle: $100
	XB_CandleAdd(0x2,0xd40886,0xd4112a);	// Candle: Stopwatch
	XB_CandleAdd(0x2,0xd4089a,0xd41008);	// Candle: Big Heart
	XB_CandleAdd(0x2,0xd408b8,0xd41044);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd408c2,0xd41080);	// Candle: Big Heart
	XB_CandleAdd(0x2,0xd408f4,0xd40ffe);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd4093a,0xd4104e);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40944,0xd41076);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40962,0xd41058);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd4096c,0xd41116);	// Candle: $250
	XB_CandleAdd(0x2,0xd40980,0xd40ff4);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd409bc,0xd40fea);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x2,0xd40a86,0xd41212);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40ac2,0xd4121c);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x2,0xd40b5a,0xd412fa);	// Candle: $25
	XB_CandleAdd(0x2,0xd40b64,0xd41304);	// Candle: Small Heart
	// #7
	XB_CandleAdd(0x2,0xd40b82,0xd41322);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40baa,0xd4132c);	// Candle: $1
	// #10
	XB_CandleAdd(0x2,0xd40c8a,0xd41448);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40c9e,0xd414e8);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40cbc,0xd4143e);	// Candle: $25
	XB_CandleAdd(0x2,0xd40cc6,0xd414f2);	// Candle: Big Heart
	//XB_CandleAdd(0x2,0xd40cee,0xd414fc);	// Candle: Uncurse
	XB_CandleAdd(0x2,0xd40cf8,0xd4147a);	// Candle: Big Heart
	XB_CandleAdd(0x2,0xd40d0c,0xd413da);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40d2a,0xd41470);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40d3e,0xd41506);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40d5c,0xd413e4);	// Candle: $100
	XB_CandleAdd(0x2,0xd40d7a,0xd41466);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40d8e,0xd41510);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0x2,0xd40dfc,0xd41592);	// Candle: Small Heart
	XB_CandleAdd(0x2,0xd40e24,0xd4159c);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x2,0xd40e52,0xd41606);	// Candle: $25
	//XB_CandleAdd(0x2,0xd40e70,0xd415fc);	// Candle: Uncurse
	XB_CandleAdd(0x2,0xd40e84,0xd415f2);	// Candle: Small Heart
	
	// Catacombs
	// #1
	XB_CandleAdd(0x3,0xd2bdf6,0xd2c802);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2be00,0xd2c82a);	// Candle: $100
	XB_CandleAdd(0x3,0xd2be1e,0xd2c816);	// Candle: Big Heart
	// #5
	XB_CandleAdd(0x3,0xd2bebe,0xd2c8de);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bec8,0xd2c8e8);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x3,0xd2bee6,0xd2c906);	// Candle: $1
	// #7
	XB_CandleAdd(0x3,0xd2bf14,0xd2c934);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bf28,0xd2c92a);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bf46,0xd2c952);	// Candle: Big Heart
	// #8
	XB_CandleAdd(0x3,0xd2bf6a,0xd2c9bc);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bf74,0xd2c9c6);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bf88,0xd2c98a);	// Candle: $50
	XB_CandleAdd(0x3,0xd2bf92,0xd2c994);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2bfa6,0xd2c9da);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bfb0,0xd2c9d0);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2bfba,0xd2c99e);	// Candle: Rebound Stone
	// #12
	XB_CandleAdd(0x3,0xd2c0fc,0xd2cafe);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c106,0xd2cb08);	// Candle: Big Heart
	// #15
	XB_CandleAdd(0x3,0xd2c20e,0xd2cc38);	// Candle: $25
	XB_CandleAdd(0x3,0xd2c218,0xd2cc2e);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x3,0xd2c274,0xd2cca6);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c288,0xd2cc9c);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c29c,0xd2ccd8);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c2a6,0xd2ccce);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2c2b0,0xd2ccc4);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c2c4,0xd2ccba);	// Candle: $100
	XB_CandleAdd(0x3,0xd2c2d8,0xd2ccb0);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c2e2,0xd2cc92);	// Candle: $1
	// #18
	XB_CandleAdd(0x3,0xd2c316,0xd2cc6a);	// Candle: Axe
	XB_CandleAdd(0x3,0xd2c320,0xd2cc74);	// Candle: Big Heart
	// #19
	XB_CandleAdd(0x3,0xd2c352,0xd2cd56);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c35c,0xd2cd60);	// Candle: $50
	XB_CandleAdd(0x3,0xd2c37a,0xd2cd42);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c384,0xd2cd4c);	// Candle: Big Heart
	// #22
	XB_CandleAdd(0x3,0xd2c462,0xd2ce42);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c46c,0xd2ce6a);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c480,0xd2ce7e);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2c494,0xd2ce88);	// Candle: Stopwatch
	XB_CandleAdd(0x3,0xd2c4a8,0xd2ce74);	// Candle: $25
	XB_CandleAdd(0x3,0xd2c4b2,0xd2ce4c);	// Candle: $100
	// #23
	XB_CandleAdd(0x3,0xd2c4d2,0xd2ceb2);	// Candle: Rebound Stone
	XB_CandleAdd(0x3,0xd2c4dc,0xd2cebc);	// Candle: Bible
	// #24
	XB_CandleAdd(0x3,0xd2c4fa,0xd2cef8);	// Candle: $250
	XB_CandleAdd(0x3,0xd2c504,0xd2cf5c);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c50e,0xd2ceda);	// Candle: $1
	XB_CandleAdd(0x3,0xd2c518,0xd2cf66);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c522,0xd2cf2a);	// Candle: $25
	XB_CandleAdd(0x3,0xd2c540,0xd2cf70);	// Candle: $25
	XB_CandleAdd(0x3,0xd2c54a,0xd2cf20);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c554,0xd2cf8e);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c572,0xd2cf98);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2c586,0xd2cf16);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2c590,0xd2cf7a);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c59a,0xd2cee4);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c5b8,0xd2cf0c);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c5c2,0xd2cf84);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c5cc,0xd2cf48);	// Candle: Vibhuti
	// #26
	XB_CandleAdd(0x3,0xd2c67e,0xd2d068);	// Candle: Big Heart
	XB_CandleAdd(0x3,0xd2c688,0xd2d05e);	// Candle: Small Heart
	XB_CandleAdd(0x3,0xd2c692,0xd2d054);	// Candle: Small Heart

	// Olrox's Quarters
	// #1
	XB_CandleAdd(0x4,0xd54fbe,0xd557f2);	// Candle: Big Heart
	// #3
	XB_CandleAdd(0x4,0xd55014,0xd558e8);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5501e,0xd55852);	// Candle: $50
	XB_CandleAdd(0x4,0xd55046,0xd5585c);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd55050,0xd558de);	// Candle: Stopwatch
	XB_CandleAdd(0x4,0xd55082,0xd55866);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5508c,0xd55870);	// Candle: $1
	XB_CandleAdd(0x4,0xd55096,0xd558ca);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd550be,0xd558d4);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x4,0xd5512c,0xd5597e);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55140,0xd55988);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5514a,0xd55992);	// Candle: $100
	XB_CandleAdd(0x4,0xd55154,0xd5599c);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd55168,0xd559a6);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x4,0xd55216,0xd55a54);	// Candle: Knife
	XB_CandleAdd(0x4,0xd55220,0xd55a4a);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55234,0xd55a40);	// Candle: $50
	XB_CandleAdd(0x4,0xd55248,0xd55a36);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5525c,0xd55a2c);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55284,0xd55a22);	// Candle: Big Heart
	// #9
	XB_CandleAdd(0x4,0xd55310,0xd55ac2);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd55324,0xd55bf8);	// Candle: $1
	XB_CandleAdd(0x4,0xd5532e,0xd55b26);	// Candle: Bible
	XB_CandleAdd(0x4,0xd55342,0xd55c02);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd55356,0xd55b94);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55374,0xd55b9e);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5537e,0xd55b1c);	// Candle: $100
	XB_CandleAdd(0x4,0xd55392,0xd55c0c);	// Candle: $100
	XB_CandleAdd(0x4,0xd553a6,0xd55b12);	// Candle: $25
	XB_CandleAdd(0x4,0xd553b0,0xd55aea);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd553c4,0xd55c16);	// Candle: Axe
	XB_CandleAdd(0x4,0xd553d8,0xd55ba8);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd553e2,0xd55b08);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55400,0xd55bb2);	// Candle: $50
	XB_CandleAdd(0x4,0xd55414,0xd55c20);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5541e,0xd55afe);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55428,0xd55af4);	// Candle: $50
	XB_CandleAdd(0x4,0xd5543c,0xd55c2a);	// Candle: Big Heart
	// #10
	XB_CandleAdd(0x4,0xd554b4,0xd55cb6);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd554c8,0xd55cc0);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd554d2,0xd55cca);	// Candle: $25
	// #14
	XB_CandleAdd(0x4,0xd5554c,0xd55d58);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55560,0xd55d62);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x4,0xd555c6,0xd55dfa);	// Candle: $25
	XB_CandleAdd(0x4,0xd555d0,0xd55e04);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd555ee,0xd55dd2);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd555f8,0xd55dc8);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd55602,0xd55dbe);	// Candle: Holy Water
	XB_CandleAdd(0x4,0xd55616,0xd55e36);	// Candle: Big Heart
	XB_CandleAdd(0x4,0xd55634,0xd55e2c);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5563e,0xd55e22);	// Candle: Small Heart
	XB_CandleAdd(0x4,0xd5565c,0xd55e18);	// Candle: $25
	XB_CandleAdd(0x4,0xd55670,0xd55e0e);	// Candle: Small Heart

	// Abandon Mine
	// #1
	XB_CandleAdd(0x5,0xce3952,0xce3db8);	// Candle: Big Heart
	XB_CandleAdd(0x5,0xce395c,0xce3dc2);	// Candle: Small Heart
	XB_CandleAdd(0x5,0xce3966,0xce3dcc);	// Candle: Holy Water
	XB_CandleAdd(0x5,0xce3970,0xce3dd6);	// Candle: $25
	XB_CandleAdd(0x5,0xce397a,0xce3de0);	// Candle: Small Heart
	XB_CandleAdd(0x5,0xce3984,0xce3dae);	// Candle: $50
	// #2
	XB_CandleAdd(0x5,0xce39ea,0xce3e26);	// Candle: Small Heart
	XB_CandleAdd(0x5,0xce39f4,0xce3e12);	// Candle: Big Heart
	XB_CandleAdd(0x5,0xce39fe,0xce3e30);	// Candle: $1
	XB_CandleAdd(0x5,0xce3a08,0xce3e1c);	// Candle: Big Heart
	XB_CandleAdd(0x5,0xce3a12,0xce3e3a);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x5,0xce3a32,0xce3e8c);	// Candle: Big Heart
	XB_CandleAdd(0x5,0xce3a3c,0xce3eaa);	// Candle: Rebound Stone
	XB_CandleAdd(0x5,0xce3a6e,0xce3e78);	// Candle: Axe
	XB_CandleAdd(0x5,0xce3a78,0xce3e96);	// Candle: $100
	// #6
	XB_CandleAdd(0x5,0xce39c0,0xce3f42);	// Candle: $25

	// Royal Chapel
	// #3
	XB_CandleAdd(0x6,0xce0686,0xce1168);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce069a,0xce1172);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce06b8,0xce117c);	// Candle: $25
	XB_CandleAdd(0x6,0xce06cc,0xce1186);	// Candle: Bible
	XB_CandleAdd(0x6,0xce06fe,0xce1190);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x6,0xce0762,0xce1230);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce078a,0xce123a);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce079e,0xce1244);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x6,0xce0836,0xce1336);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce085e,0xce1340);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce0886,0xce134a);	// Candle: $25
	// #7
	XB_CandleAdd(0x6,0xce08ec,0xce0d30);	// Candle: Big Heart
	// #9
	XB_CandleAdd(0x6,0xce098e,0xce1400);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce0998,0xce140a);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce09a2,0xce1414);	// Candle: Big Heart
	// #11
	XB_CandleAdd(0x6,0xce09ca,0xce1432);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce09d4,0xce143c);	// Candle: Big Heart
	// #12
	XB_CandleAdd(0x6,0xce09fc,0xce1522);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce0a4c,0xce14e6);	// Candle: $25
	XB_CandleAdd(0x6,0xce0a92,0xce1496);	// Candle: Small Heart
	// #24
	XB_CandleAdd(0x6,0xce0b5a,0xce1670);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce0b64,0xce16b6);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce0b6e,0xce16de);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce0c2c,0xce1706);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce0c36,0xce16d4);	// Candle: $100
	XB_CandleAdd(0x6,0xce0c40,0xce16ac);	// Candle: Big Heart
	XB_CandleAdd(0x6,0xce0c4a,0xce1652);	// Candle: $250
	XB_CandleAdd(0x6,0xce0cb8,0xce16e8);	// Candle: Small Heart
	XB_CandleAdd(0x6,0xce0cc2,0xce1724);	// Candle: Small Heart
	// #25
	XB_CandleAdd(0x6,0xce0d82,0xce17ec);	// Candle: $50
	XB_CandleAdd(0x6,0xce0ddc,0xce183c);	// Candle: Vibhuti
	// #26
	XB_CandleAdd(0x6,0xce0ea4,0xce18d2);	// Candle: Small Heart

	// Castle Entrance
	// #1
	XB_CandleAdd(0x7,0xd26bf6,0xd27408);	// Candle: $400
	XB_CandleAdd(0x7,0xd26c00,0xd27412);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26c0a,0xd2741c);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26c6e,0xd273fe);	// Candle: Cross
	// #3
	XB_CandleAdd(0x7,0xd26d10,0xd27506);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26d1a,0xd27510);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26d2e,0xd2751a);	// Candle: $100
	XB_CandleAdd(0x7,0xd26d56,0xd27524);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26d6a,0xd2752e);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26d88,0xd27538);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x7,0xd26bb8,0xd274c8);	// Candle: Knife
	XB_CandleAdd(0x7,0xd26bc2,0xd274d2);	// Candle: Big Heart
	// #5
	XB_CandleAdd(0x7,0xd26dca,0xd275f2);	// Candle: $1
	XB_CandleAdd(0x7,0xd26dd4,0xd275d4);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26dde,0xd275ca);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26de8,0xd275e8);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26df2,0xd275de);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x7,0xd26e12,0xd27612);	// Candle: Holy Water
	XB_CandleAdd(0x7,0xd26e1c,0xd27644);	// Candle: $25
	XB_CandleAdd(0x7,0xd26e30,0xd2763a);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26e3a,0xd27630);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26e44,0xd27626);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26e58,0xd2761c);	// Candle: Small Heart
	// #7
	XB_CandleAdd(0x7,0xd26e76,0xd27676);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x7,0xd26ec2,0xd27730);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26ee0,0xd276c2);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26efe,0xd2771c);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd26f58,0xd27712);	// Candle: Stopwatch
	XB_CandleAdd(0x7,0xd26f76,0xd276cc);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd26f8a,0xd27726);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x7,0xd27016,0xd27816);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd2702a,0xd27820);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd27034,0xd2782a);	// Candle: $25
	XB_CandleAdd(0x7,0xd2703e,0xd27852);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd27048,0xd2785c);	// Candle: Axe
	XB_CandleAdd(0x7,0xd27052,0xd27834);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd2705c,0xd2783e);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd27070,0xd27848);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x7,0xd27176,0xd27976);	// Candle: $50
	// #16
	XB_CandleAdd(0x7,0xd271e4,0xd27a5c);	// Candle: $1
	XB_CandleAdd(0x7,0xd271ee,0xd279da);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd27220,0xd27a52);	// Candle: Small Heart
	XB_CandleAdd(0x7,0xd2722a,0xd27a0c);	// Candle: Big Heart
	XB_CandleAdd(0x7,0xd27248,0xd27a48);	// Candle: Small Heart

	// Caverns
	// #1
	XB_CandleAdd(0x9,0xcdb672,0xcdc88e);	// Candle: $100
	XB_CandleAdd(0x9,0xcdb67c,0xcdc898);	// Candle: $400
	XB_CandleAdd(0x9,0xcdb686,0xcdc848);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb6a4,0xcdc866);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb6c2,0xcdc852);	// Candle: $50
	XB_CandleAdd(0x9,0xcdb6cc,0xcdc87a);	// Candle: Big Heart
	// #2
	XB_CandleAdd(0x9,0xcdb744,0xcdc8f2);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb74e,0xcdc910);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdb758,0xcdc906);	// Candle: $25
	XB_CandleAdd(0x9,0xcdb762,0xcdc8fc);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb76c,0xcdc91a);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x9,0xcdb7da,0xcdc988);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdb7e4,0xcdc9e2);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdb816,0xcdca3c);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb82a,0xcdc9a6);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb834,0xcdc9f6);	// Candle: Axe
	XB_CandleAdd(0x9,0xcdb83e,0xcdc9ba);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb852,0xcdca1e);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb884,0xcdc96a);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb88e,0xcdc97e);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb898,0xcdc9ce);	// Candle: $250
	// #5
	XB_CandleAdd(0x9,0xcdb9da,0xcdca84);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb9e4,0xcdca7a);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x9,0xcdb6fe,0xcdc80c);	// Candle: Knife
	XB_CandleAdd(0x9,0xcdb708,0xcdc7ee);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdb712,0xcdc802);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdb71c,0xcdc7f8);	// Candle: Small Heart
	// #7
	XB_CandleAdd(0x9,0xcdba02,0xcdcbd8);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdba0c,0xcdcbe2);	// Candle: $1
	XB_CandleAdd(0x9,0xcdba16,0xcdcbec);	// Candle: $1
	XB_CandleAdd(0x9,0xcdba20,0xcdcbce);	// Candle: $1
	XB_CandleAdd(0x9,0xcdba2a,0xcdcbc4);	// Candle: $1
	XB_CandleAdd(0x9,0xcdba34,0xcdcbf6);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdba3e,0xcdcc00);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x9,0xcdbbea,0xcdcd9a);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbbf4,0xcdcda4);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbbfe,0xcdcdae);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdbc44,0xcdcdb8);	// Candle: $25
	XB_CandleAdd(0x9,0xcdbc4e,0xcdcdc2);	// Candle: Small Heart
	// #15
	XB_CandleAdd(0x9,0xcdbc72,0xcdce22);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x9,0xcdbd30,0xcdce9a);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbd44,0xcdcea4);	// Candle: $25
	XB_CandleAdd(0x9,0xcdbdb2,0xcdceae);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbdc6,0xcdceb8);	// Candle: Small Heart
	// #20
	XB_CandleAdd(0x9,0xcdbeba,0xcdcd70);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbece,0xcdcd66);	// Candle: $1
	// #21
	XB_CandleAdd(0x9,0xcdbef8,0xcdd074);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdbf02,0xcdd07e);	// Candle: Big Heart
	// #23
	XB_CandleAdd(0x9,0xcdbfae,0xcdd114);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc030,0xcdd11e);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdc044,0xcdd10a);	// Candle: $50
	XB_CandleAdd(0x9,0xcdc06c,0xcdd0ec);	// Candle: $100
	XB_CandleAdd(0x9,0xcdc08a,0xcdd0f6);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc094,0xcdd128);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc0ee,0xcdd0e2);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdc116,0xcdd22c);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc13e,0xcdd222);	// Candle: Small Heart
	// #24
	XB_CandleAdd(0x9,0xcdc26a,0xcdd35a);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc332,0xcdd378);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc33c,0xcdd382);	// Candle: Small Heart
	// #26
	XB_CandleAdd(0x9,0xcdc410,0xcdd514);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc41a,0xcdd50a);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc44c,0xcdd532);	// Candle: $2000
	XB_CandleAdd(0x9,0xcdc49c,0xcdd500);	// Candle: $250
	XB_CandleAdd(0x9,0xcdc4a6,0xcdd62c);	// Candle: Small Heart
	// #29
	XB_CandleAdd(0x9,0xcdc61a,0xcdd796);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc62e,0xcdd78c);	// Candle: Holy Water
	XB_CandleAdd(0x9,0xcdc642,0xcdd782);	// Candle: Small Heart
	// #30
	XB_CandleAdd(0x9,0xcdc662,0xcdd7ca);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc66c,0xcdd7de);	// Candle: Stopwatch
	XB_CandleAdd(0x9,0xcdc676,0xcdd7e8);	// Candle: Small Heart
	XB_CandleAdd(0x9,0xcdc680,0xcdd7f2);	// Candle: Big Heart
	XB_CandleAdd(0x9,0xcdc68a,0xcdd7fc);	// Candle: $50
	XB_CandleAdd(0x9,0xcdc694,0xcdd7d4);	// Candle: Small Heart

	// Colosseum
	// #3
	XB_CandleAdd(0xa,0xd5274a,0xd52eea);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd5275e,0xd52ef4);	// Candle: Big Heart
	XB_CandleAdd(0xa,0xd5277c,0xd52efe);	// Candle: $50
	XB_CandleAdd(0xa,0xd52786,0xd52f08);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd527a4,0xd52f12);	// Candle: $25
	XB_CandleAdd(0xa,0xd527ae,0xd52f1c);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0xa,0xd52832,0xd52fa0);	// Candle: Agunea
	XB_CandleAdd(0xa,0xd5283c,0xd52faa);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52846,0xd52fb4);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52850,0xd52fc8);	// Candle: $50
	// #7
	XB_CandleAdd(0xa,0xd5294c,0xd530d2);	// Candle: Big Heart
	XB_CandleAdd(0xa,0xd52956,0xd530c8);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd5296a,0xd530be);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd5297e,0xd530b4);	// Candle: $50
	XB_CandleAdd(0xa,0xd52988,0xd530aa);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd5299c,0xd530a0);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0xa,0xd52a06,0xd53146);	// Candle: $25
	XB_CandleAdd(0xa,0xd52a10,0xd531dc);	// Candle: Big Heart
	XB_CandleAdd(0xa,0xd52a24,0xd531e6);	// Candle: $100
	XB_CandleAdd(0xa,0xd52a2e,0xd53150);	// Candle: Big Heart
	XB_CandleAdd(0xa,0xd52a7e,0xd531f0);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52a92,0xd5315a);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0xa,0xd52ab2,0xd5324c);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52ac6,0xd53256);	// Candle: $25
	XB_CandleAdd(0xa,0xd52ae4,0xd53260);	// Candle: $25
	XB_CandleAdd(0xa,0xd52b02,0xd5326a);	// Candle: Small Heart
	// #12
	XB_CandleAdd(0xa,0xd52b9c,0xd5330e);	// Candle: Big Heart
	XB_CandleAdd(0xa,0xd52ba6,0xd53386);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52bc4,0xd53304);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52bce,0xd5337c);	// Candle: $100
	XB_CandleAdd(0xa,0xd52bec,0xd532fa);	// Candle: $25
	XB_CandleAdd(0xa,0xd52c00,0xd53372);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52c1e,0xd532f0);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0xa,0xd52c64,0xd533fe);	// Candle: $1000
	XB_CandleAdd(0xa,0xd52c82,0xd533f4);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52c96,0xd533ea);	// Candle: Small Heart
	XB_CandleAdd(0xa,0xd52cb4,0xd533e0);	// Candle: Big Heart
	// #14
	XB_CandleAdd(0xa,0xd52ce2,0xd53454);	// Candle: Axe
	XB_CandleAdd(0xa,0xd52d0a,0xd5345e);	// Candle: Rebound Stone
	XB_CandleAdd(0xa,0xd52d32,0xd53468);	// Candle: Holy Water
	XB_CandleAdd(0xa,0xd52d5a,0xd53472);	// Candle: Knife
	
	// Castle Keep
	// #1
	XB_CandleAdd(0xb,0xcf6f66,0xcf77b2);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf6fac,0xcf77bc);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf6fca,0xcf77c6);	// Candle: Big Heart
	XB_CandleAdd(0xb,0xcf6fde,0xcf77d0);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf6fe8,0xcf77da);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf6ff2,0xcf765e);	// Candle: Holy Water
	XB_CandleAdd(0xb,0xcf7006,0xcf7668);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf701a,0xcf77e4);	// Candle: Rebound Stone
	XB_CandleAdd(0xb,0xcf7042,0xcf7672);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf704c,0xcf77ee);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf7060,0xcf767c);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf7074,0xcf77f8);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf707e,0xcf7802);	// Candle: $100
	XB_CandleAdd(0xb,0xcf7088,0xcf7686);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf709c,0xcf780c);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf70ba,0xcf7816);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf70c4,0xcf76d6);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf70ce,0xcf7690);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf710a,0xcf7820);	// Candle: Big Heart
	XB_CandleAdd(0xb,0xcf711e,0xcf782a);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf7128,0xcf764a);	// Candle: Cross
	XB_CandleAdd(0xb,0xcf7150,0xcf776c);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf716e,0xcf75aa);	// Candle: $400
	XB_CandleAdd(0xb,0xcf7178,0xcf7762);	// Candle: Big Heart
	XB_CandleAdd(0xb,0xcf7182,0xcf75a0);	// Candle: Big Heart
	XB_CandleAdd(0xb,0xcf718c,0xcf7582);	// Candle: Axe
	XB_CandleAdd(0xb,0xcf71f0,0xcf7758);	// Candle: Small Heart
	XB_CandleAdd(0xb,0xcf71fa,0xcf76cc);	// Candle: $400
	// #4
	XB_CandleAdd(0xb,0xcf6a1e,0xcf78d6);	// Candle: Big Heart
	// #9
	XB_CandleAdd(0xb,0xcf73ba,0xcf7a4c);	// Candle: Big Heart
	
	// Alchemy Lab
	// #2
	XB_CandleAdd(0xc,0xd4ab6a,0xd4b61c);	// Candle: Big Heart
	XB_CandleAdd(0xc,0xd4ab74,0xd4b612);	// Candle: Holy Water
	XB_CandleAdd(0xc,0xd4ab88,0xd4b608);	// Candle: $50
	XB_CandleAdd(0xc,0xd4ab92,0xd4b5ea);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ab9c,0xd4b5fe);	// Candle: Small Heart
	// #3
	XB_CandleAdd(0xc,0xd4abc4,0xd4b66c);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4abd8,0xd4b64e);	// Candle: $25
	XB_CandleAdd(0xc,0xd4abe2,0xd4b63a);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4abec,0xd4b658);	// Candle: $100
	XB_CandleAdd(0xc,0xd4ac00,0xd4b676);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ac0a,0xd4b680);	// Candle: Big Heart
	XB_CandleAdd(0xc,0xd4ac1e,0xd4b662);	// Candle: Rebound Stone
	XB_CandleAdd(0xc,0xd4ac28,0xd4b644);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0xc,0xd4ac84,0xd4b6e4);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4aca2,0xd4b6da);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0xc,0xd4ac50,0xd4b0e8);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ac5a,0xd4b0f2);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0xc,0xd4ad14,0xd4b774);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ad32,0xd4b76a);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0xc,0xd4ad5c,0xd4b7bc);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ad7a,0xd4b7b2);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0xc,0xd4adae,0xd4b84a);	// Candle: $25
	XB_CandleAdd(0xc,0xd4adb8,0xd4b80e);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4adea,0xd4b836);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0xc,0xd4ae6c,0xd4b8ac);	// Candle: Axe
	XB_CandleAdd(0xc,0xd4ae76,0xd4b8c0);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4ae80,0xd4b8ca);	// Candle: $50
	XB_CandleAdd(0xc,0xd4ae8a,0xd4b8f2);	// Candle: Small Heart
	// #12
	XB_CandleAdd(0xc,0xd4aebe,0xd4b91c);	// Candle: Big Heart
	XB_CandleAdd(0xc,0xd4aec8,0xd4b926);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4aed2,0xd4b930);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0xc,0xd4af1a,0xd4b964);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4af24,0xd4b96e);	// Candle: $25
	// #14
	XB_CandleAdd(0xc,0xd4af74,0xd4b9b4);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4af7e,0xd4b9be);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4af88,0xd4b9d2);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4af92,0xd4b9dc);	// Candle: Knife
	// #15
	XB_CandleAdd(0xc,0xd4afbc,0xd4ba42);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4afda,0xd4ba24);	// Candle: Big Heart
	XB_CandleAdd(0xc,0xd4afe4,0xd4ba2e);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4aff8,0xd4ba38);	// Candle: $50
	// #18
	XB_CandleAdd(0xc,0xd4b112,0xd4bb46);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b130,0xd4bb96);	// Candle: $1
	XB_CandleAdd(0xc,0xd4b13a,0xd4bb50);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b144,0xd4bba0);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b176,0xd4bb32);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b180,0xd4bb3c);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b1a8,0xd4bb5a);	// Candle: Big Heart
	// #19
	XB_CandleAdd(0xc,0xd4b1da,0xd4bc2c);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b202,0xd4bc22);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b23e,0xd4bc68);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b248,0xd4bc5e);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b252,0xd4bc54);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b25c,0xd4bc0e);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b266,0xd4bc04);	// Candle: Big Heart
	// #20
	XB_CandleAdd(0xc,0xd4b2b0,0xd4bd3e);	// Candle: $100
	XB_CandleAdd(0xc,0xd4b2ba,0xd4bce4);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b2c4,0xd4bcd0);	// Candle: $50
	XB_CandleAdd(0xc,0xd4b314,0xd4bcf8);	// Candle: $1
	XB_CandleAdd(0xc,0xd4b31e,0xd4bd0c);	// Candle: Big Heart
	XB_CandleAdd(0xc,0xd4b328,0xd4bd20);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b332,0xd4bd34);	// Candle: $25
	XB_CandleAdd(0xc,0xd4b33c,0xd4bd48);	// Candle: Vibhuti
	// #22
	XB_CandleAdd(0xc,0xd4b36a,0xd4bd94);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b374,0xd4bd8a);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b37e,0xd4bd9e);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b388,0xd4bda8);	// Candle: $50
	XB_CandleAdd(0xc,0xd4b392,0xd4bdb2);	// Candle: Small Heart
	// #24
	XB_CandleAdd(0xc,0xd4b40c,0xd4be2c);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b42a,0xd4be22);	// Candle: Small Heart
	// #27
	XB_CandleAdd(0xc,0xd4b44a,0xd4be74);	// Candle: Small Heart
	XB_CandleAdd(0xc,0xd4b468,0xd4be6a);	// Candle: $25

	// Clock Tower
	// #2
	XB_CandleAdd(0xd,0xd39402,0xd39f48);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39416,0xd39f3e);	// Candle: $25
	XB_CandleAdd(0xd,0xd39420,0xd39f0c);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39434,0xd39f02);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd3943e,0xd39f34);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39452,0xd39f2a);	// Candle: $1
	// #3
	XB_CandleAdd(0xd,0xd39472,0xd39f72);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39486,0xd39f7c);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0xd,0xd394b4,0xd3a036);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd394dc,0xd3a0c2);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd394e6,0xd3a022);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd39504,0xd3a018);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd3950e,0xd3a0b8);	// Candle: $25
	XB_CandleAdd(0xd,0xd39518,0xd3a0ae);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd3952c,0xd39fb4);	// Candle: $50
	XB_CandleAdd(0xd,0xd3954a,0xd3a0a4);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd3955e,0xd3a09a);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd39568,0xd3a090);	// Candle: $50
	XB_CandleAdd(0xd,0xd39572,0xd39fe6);	// Candle: $100
	XB_CandleAdd(0xd,0xd3957c,0xd3a086);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39590,0xd3a07c);	// Candle: Knife
	XB_CandleAdd(0xd,0xd3959a,0xd3a072);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd395b8,0xd3a068);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd395cc,0xd39faa);	// Candle: $100
	XB_CandleAdd(0xd,0xd395d6,0xd3a05e);	// Candle: $25
	XB_CandleAdd(0xd,0xd395e0,0xd3a00e);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd395ea,0xd39fbe);	// Candle: Big Heart
	// #6
	XB_CandleAdd(0xd,0xd396fc,0xd3a1c0);	// Candle: $250
	XB_CandleAdd(0xd,0xd39706,0xd3a1e8);	// Candle: Big Heart
	// #8
	XB_CandleAdd(0xd,0xd397a8,0xd3a316);	// Candle: Vibhuti
	XB_CandleAdd(0xd,0xd397d0,0xd3a352);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd397da,0xd3a3ac);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39834,0xd3a28a);	// Candle: Holy Water
	// #9
	XB_CandleAdd(0xd,0xd398ca,0xd3a690);	// Candle: Axe
	XB_CandleAdd(0xd,0xd398d4,0xd3a546);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd398de,0xd3a410);	// Candle: Rebound Stone
	XB_CandleAdd(0xd,0xd39974,0xd3a5fa);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd3997e,0xd3a640);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39992,0xd3a5f0);	// Candle: $50
	XB_CandleAdd(0xd,0xd3999c,0xd3a47e);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd399b0,0xd3a4a6);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd399ba,0xd3a514);	// Candle: $25
	XB_CandleAdd(0xd,0xd399ec,0xd3a636);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd399f6,0xd3a474);	// Candle: $1
	XB_CandleAdd(0xd,0xd39a14,0xd3a49c);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39a3c,0xd3a46a);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39a46,0xd3a50a);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39a5a,0xd3a492);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd39a6e,0xd3a62c);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39a82,0xd3a500);	// Candle: $25
	XB_CandleAdd(0xd,0xd39a8c,0xd3a460);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39aa0,0xd3a488);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39aaa,0xd3a4f6);	// Candle: Big Heart
	XB_CandleAdd(0xd,0xd39b90,0xd3a4b0);	// Candle: Cross
	// #15
	XB_CandleAdd(0xd,0xd39c08,0xd3a77a);	// Candle: Holy Water
	XB_CandleAdd(0xd,0xd39c12,0xd3a784);	// Candle: Vibhuti
	XB_CandleAdd(0xd,0xd39c94,0xd3a7c0);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39cda,0xd3a72a);	// Candle: Vibhuti
	XB_CandleAdd(0xd,0xd39ce4,0xd3a752);	// Candle: Holy Water
	// #16
	XB_CandleAdd(0xd,0xd39d22,0xd3a876);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39d2c,0xd3a862);	// Candle: Small Heart
	XB_CandleAdd(0xd,0xd39d4a,0xd3a812);	// Candle: Knife
	XB_CandleAdd(0xd,0xd39db8,0xd3a86c);	// Candle: Big Heart
	
	// Reverse Marble Gallery
	// #1
	XB_CandleAdd(0x20,0xd19324,0xd1a680);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1932e,0xd1a5c2);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19338,0xd1a54a);	// Candle: Knife
	XB_CandleAdd(0x20,0xd1934c,0xd1a68a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19360,0xd1a4b4);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19374,0xd1a612);	// Candle: $1
	XB_CandleAdd(0x20,0xd19388,0xd1a4be);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd193ba,0xd1a608);	// Candle: $1
	XB_CandleAdd(0x20,0xd193c4,0xd1a61c);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd193ce,0xd1a4c8);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd193e2,0xd1a626);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd193ec,0xd1a4d2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19400,0xd1a5fe);	// Candle: $1
	XB_CandleAdd(0x20,0xd19414,0xd1a4dc);	// Candle: $50
	XB_CandleAdd(0x20,0xd1943c,0xd1a5f4);	// Candle: $250
	XB_CandleAdd(0x20,0xd19446,0xd1a4e6);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19464,0xd1a4f0);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19482,0xd1a5ea);	// Candle: $1
	XB_CandleAdd(0x20,0xd1948c,0xd1a63a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd194aa,0xd1a630);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd194b4,0xd1a5e0);	// Candle: $1
	XB_CandleAdd(0x20,0xd194dc,0xd1a644);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd194e6,0xd1a4fa);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1950e,0xd1a5d6);	// Candle: $1
	XB_CandleAdd(0x20,0xd19518,0xd1a64e);	// Candle: $100
	XB_CandleAdd(0x20,0xd19522,0xd1a504);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1954a,0xd1a50e);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd1955e,0xd1a5cc);	// Candle: $1
	XB_CandleAdd(0x20,0xd19572,0xd1a518);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19586,0xd1a522);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19590,0xd1a52c);	// Candle: Holy Water
	// #2
	XB_CandleAdd(0x20,0xd1960a,0xd1a7f4);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19614,0xd1a7d6);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1961e,0xd1a7c2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19628,0xd1a7ae);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19646,0xd1a7e0);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19650,0xd1a7cc);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1965a,0xd1a7b8);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19664,0xd1a7a4);	// Candle: Big Heart
	// #3
	XB_CandleAdd(0x20,0xd19682,0xd1a89e);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1968c,0xd1a86c);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19696,0xd1a81c);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd196a0,0xd1a8f8);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd196c8,0xd1a8ee);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd196dc,0xd1a862);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd196e6,0xd1a830);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd196f0,0xd1a880);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd196fa,0xd1a8e4);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19704,0xd1a88a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1970e,0xd1a8da);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19718,0xd1a894);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd1972c,0xd1a8a8);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19736,0xd1a858);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19740,0xd1a826);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19754,0xd1a8b2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1975e,0xd1a8d0);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1977c,0xd1a8c6);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19790,0xd1a84e);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1979a,0xd1a83a);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x20,0xd192de,0xd1a120);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd192e8,0xd1a116);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd192f2,0xd1a134);	// Candle: $250
	XB_CandleAdd(0x20,0xd192fc,0xd1a12a);	// Candle: $250
	// #6
	XB_CandleAdd(0x20,0xd197ba,0xd1a99a);	// Candle: $25
	XB_CandleAdd(0x20,0xd197d8,0xd1a986);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd197e2,0xd1a990);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd197f6,0xd1a97c);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19828,0xd1a972);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1983c,0xd1a968);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19846,0xd1a95e);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19850,0xd1a954);	// Candle: Small Heart
	// #7
	XB_CandleAdd(0x20,0xd198a2,0xd1aa58);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd198ac,0xd1aa4e);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd198d4,0xd1aa44);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd198de,0xd1aa3a);	// Candle: Holy Water
	// #8
	XB_CandleAdd(0x20,0xd1992e,0xd1ab24);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19938,0xd1aab6);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1994c,0xd1aac0);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19956,0xd1ab1a);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19960,0xd1aa8e);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd199b0,0xd1aad4);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd199ba,0xd1aa84);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd199c4,0xd1ab10);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd199e2,0xd1aafc);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd199ec,0xd1aa7a);	// Candle: Rebound Stone
	// #9
	XB_CandleAdd(0x20,0xd19a34,0xd1abbc);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19a3e,0xd1abb2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19a70,0xd1ab94);	// Candle: Bible
	XB_CandleAdd(0x20,0xd19aac,0xd1aba8);	// Candle: Stopwatch
	XB_CandleAdd(0x20,0xd19ab6,0xd1ab9e);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x20,0xd19b06,0xd1ac6a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b1a,0xd1aca6);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b2e,0xd1ac60);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b60,0xd1ac56);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b6a,0xd1acb0);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b74,0xd1ac4c);	// Candle: $25
	XB_CandleAdd(0x20,0xd19b92,0xd1ac92);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19b9c,0xd1ac9c);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19bb0,0xd1ac74);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0x20,0xd19bee,0xd1ad34);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19c02,0xd1ad3e);	// Candle: $25
	XB_CandleAdd(0x20,0xd19c16,0xd1ad48);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19c2a,0xd1ad52);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19c3e,0xd1ad5c);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19c52,0xd1ad66);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19c66,0xd1ad70);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19c84,0xd1add4);	// Candle: $25
	XB_CandleAdd(0x20,0xd19cac,0xd1ad7a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19cb6,0xd1ad84);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19cd4,0xd1ad8e);	// Candle: Big Heart
	XB_CandleAdd(0x20,0xd19cf2,0xd1ad98);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19d10,0xd1ada2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19d24,0xd1adac);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd19d42,0xd1adb6);	// Candle: Axe
	// #15
	XB_CandleAdd(0x20,0xd195d6,0xd1a48a);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd195ea,0xd1a480);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x20,0xd1a152,0xd1b27e);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1a166,0xd1b288);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1a184,0xd1b274);	// Candle: Small Heart
	// #23
	XB_CandleAdd(0x20,0xd1a2a2,0xd1b3d8);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1a2ac,0xd1b3ce);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1a2b6,0xd1b3e2);	// Candle: Small Heart
	XB_CandleAdd(0x20,0xd1a2c0,0xd1b3c4);	// Candle: Small Heart

	// Reverse Outer Wall
	// #2
	XB_CandleAdd(0x21,0xd118ce,0xd1208a);	// Candle: Bible
	// #3
	XB_CandleAdd(0x21,0xd11946,0xd12134);	// Candle: $100
	XB_CandleAdd(0x21,0xd11950,0xd1212a);	// Candle: Big Heart
	// #4
	XB_CandleAdd(0x21,0xd119be,0xd12210);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd119e6,0xd1226a);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd119f0,0xd12184);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd119fa,0xd121ac);	// Candle: $100
	XB_CandleAdd(0x21,0xd11a5e,0xd12260);	// Candle: Big Heart
	XB_CandleAdd(0x21,0xd11a68,0xd1217a);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11a90,0xd121f2);	// Candle: Knife
	// #9
	XB_CandleAdd(0x21,0xd11b86,0xd1234c);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11b9a,0xd12356);	// Candle: $25
	XB_CandleAdd(0x21,0xd11bae,0xd12360);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x21,0xd11bfa,0xd123d4);	// Candle: Big Heart
	XB_CandleAdd(0x21,0xd11c2c,0xd123f2);	// Candle: Big Heart
	// #14
	XB_CandleAdd(0x21,0xd11d3e,0xd1269e);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11d48,0xd12662);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11d5c,0xd12612);	// Candle: $25
	XB_CandleAdd(0x21,0xd11dc0,0xd12518);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11dca,0xd1257c);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11dd4,0xd125d6);	// Candle: Small Heart
	XB_CandleAdd(0x21,0xd11e42,0xd12630);	// Candle: Big Heart
	XB_CandleAdd(0x21,0xd11eec,0xd1263a);	// Candle: $100
	XB_CandleAdd(0x21,0xd11f00,0xd1252c);	// Candle: $50
	
	// Reverse Library
	// #1
	XB_CandleAdd(0x22,0xce75d2,0xce7d7c);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7618,0xce7d86);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7622,0xce7c82);	// Candle: $250
	XB_CandleAdd(0x22,0xce762c,0xce7d22);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce764a,0xce7d0e);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7654,0xce7cdc);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7672,0xce7d5e);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce769a,0xce7d18);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce76a4,0xce7ce6);	// Candle: Big Heart
	XB_CandleAdd(0x22,0xce76cc,0xce7d68);	// Candle: Big Heart
	XB_CandleAdd(0x22,0xce76e0,0xce7c64);	// Candle: Stopwatch
	XB_CandleAdd(0x22,0xce76f4,0xce7d72);	// Candle: $100
	XB_CandleAdd(0x22,0xce7708,0xce7c5a);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x22,0xce77d6,0xce7e68);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce77e0,0xce7e5e);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x22,0xce77fe,0xce7e90);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7808,0xce7e86);	// Candle: $50
	// #7
	XB_CandleAdd(0x22,0xce7864,0xce7f28);	// Candle: $1
	XB_CandleAdd(0x22,0xce788c,0xce7f1e);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x22,0xce78f0,0xce7fc2);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7922,0xce8012);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7936,0xce808a);	// Candle: $100
	XB_CandleAdd(0x22,0xce794a,0xce7fb8);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7954,0xce801c);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7968,0xce8080);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7990,0xce8026);	// Candle: Big Heart
	XB_CandleAdd(0x22,0xce79a4,0xce7fa4);	// Candle: Big Heart
	XB_CandleAdd(0x22,0xce79cc,0xce8062);	// Candle: $25
	XB_CandleAdd(0x22,0xce79d6,0xce7f9a);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7a12,0xce806c);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0x22,0xce7a44,0xce80e4);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7a62,0xce80da);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x22,0xce7aa4,0xce8130);	// Candle: Small Heart
	XB_CandleAdd(0x22,0xce7acc,0xce8144);	// Candle: $25
	
	// Reverse Catacombs
	// #1
	XB_CandleAdd(0x23,0xcf1e32,0xcf2a58);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf1e3c,0xcf2a62);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf1e46,0xcf2a4e);	// Candle: $25
	// #5
	XB_CandleAdd(0x23,0xcf1eca,0xcf2af0);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf1ed4,0xcf2ae6);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x23,0xcf1ef2,0xcf2b0e);	// Candle: $1
	// #7
	XB_CandleAdd(0x23,0xcf1f12,0xcf2b2e);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf1f1c,0xcf2b38);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf1f26,0xcf2b42);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x23,0xcf1f72,0xcf2bc6);	// Candle: Rebound Stone
	XB_CandleAdd(0x23,0xcf1f7c,0xcf2b9e);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf1f9a,0xcf2ba8);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf1fa4,0xcf2bda);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf1fae,0xcf2bd0);	// Candle: $50
	XB_CandleAdd(0x23,0xcf1fd6,0xcf2b94);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf1fe0,0xcf2b8a);	// Candle: Small Heart
	// #12
	XB_CandleAdd(0x23,0xcf20ec,0xcf2d40);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf20f6,0xcf2d36);	// Candle: Small Heart
	// #15
	XB_CandleAdd(0x23,0xcf21fa,0xcf2e12);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2204,0xcf2e1c);	// Candle: $25
	// #16
	XB_CandleAdd(0x23,0xcf222c,0xcf2e8a);	// Candle: $1
	XB_CandleAdd(0x23,0xcf2236,0xcf2e44);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf225e,0xcf2e4e);	// Candle: $100
	XB_CandleAdd(0x23,0xcf229a,0xcf2e58);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf22ea,0xcf2e62);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf2326,0xcf2e6c);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2380,0xcf2e76);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf23e4,0xcf2e80);	// Candle: Small Heart
	// #18
	XB_CandleAdd(0x23,0xcf2488,0xcf3096);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf2492,0xcf30aa);	// Candle: Axe
	// #19
	XB_CandleAdd(0x23,0xcf24bc,0xcf3106);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf24c6,0xcf30fc);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf24e4,0xcf30f2);	// Candle: $50
	XB_CandleAdd(0x23,0xcf24ee,0xcf30e8);	// Candle: Small Heart
	// #22
	XB_CandleAdd(0x23,0xcf2664,0xcf3384);	// Candle: $50
	XB_CandleAdd(0x23,0xcf266e,0xcf32ee);	// Candle: $25
	XB_CandleAdd(0x23,0xcf26be,0xcf32e4);	// Candle: Stopwatch
	XB_CandleAdd(0x23,0xcf2704,0xcf32da);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf275e,0xcf32f8);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2768,0xcf337a);	// Candle: Small Heart
	// #23
	XB_CandleAdd(0x23,0xcf279a,0xcf33ac);	// Candle: Bible
	XB_CandleAdd(0x23,0xcf27a4,0xcf33a2);	// Candle: Rebound Stone
	// #24
	XB_CandleAdd(0x23,0xcf27cc,0xcf3410);	// Candle: Vibhuti
	XB_CandleAdd(0x23,0xcf27d6,0xcf3406);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf27e0,0xcf3438);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf27ea,0xcf3474);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf27f4,0xcf33fc);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf27fe,0xcf3442);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf2812,0xcf33d4);	// Candle: Big Heart
	XB_CandleAdd(0x23,0xcf2826,0xcf33ca);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2830,0xcf33f2);	// Candle: $25
	XB_CandleAdd(0x23,0xcf283a,0xcf344c);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2844,0xcf33e8);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf284e,0xcf3456);	// Candle: $25
	XB_CandleAdd(0x23,0xcf2858,0xcf33de);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf2862,0xcf346a);	// Candle: $1
	XB_CandleAdd(0x23,0xcf286c,0xcf3460);	// Candle: $250
	// #26
	XB_CandleAdd(0x23,0xcf28ea,0xcf34f2);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf28f4,0xcf34fc);	// Candle: Small Heart
	XB_CandleAdd(0x23,0xcf28fe,0xcf3506);	// Candle: Big Heart
	
	// Reverse Olrox's Quarters
	// #1
	XB_CandleAdd(0x24,0xd0ec6c,0xd0f598);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ec76,0xd0f5a2);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0ec80,0xd0f58e);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ec8a,0xd0f584);	// Candle: $50
	// #3
	XB_CandleAdd(0x24,0xd0ecb4,0xd0f5e0);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ecc8,0xd0f5d6);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ecd2,0xd0f644);	// Candle: $1
	XB_CandleAdd(0x24,0xd0ecdc,0xd0f63a);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ecfa,0xd0f5ea);	// Candle: Stopwatch
	XB_CandleAdd(0x24,0xd0ed04,0xd0f630);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0ed18,0xd0f626);	// Candle: $250
	XB_CandleAdd(0x24,0xd0ed22,0xd0f5f4);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x24,0xd0edbe,0xd0f6ea);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0edd2,0xd0f6e0);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0ede6,0xd0f6d6);	// Candle: $100
	XB_CandleAdd(0x24,0xd0edf0,0xd0f6cc);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ee0e,0xd0f6c2);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x24,0xd0eebc,0xd0f77a);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0eed0,0xd0f784);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0eee4,0xd0f78e);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0eeee,0xd0f798);	// Candle: $50
	XB_CandleAdd(0x24,0xd0ef0c,0xd0f7a2);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0ef16,0xd0f7ac);	// Candle: Knife
	// #9
	XB_CandleAdd(0x24,0xd0ef68,0xd0f88a);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0efb8,0xd0fa1a);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0efc2,0xd0fa4c);	// Candle: $100
	XB_CandleAdd(0x24,0xd0efcc,0xd0f880);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0effe,0xd0f8da);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f012,0xd0f8d0);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f026,0xd0fa24);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f03a,0xd0f876);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f076,0xd0fa2e);	// Candle: $25
	XB_CandleAdd(0x24,0xd0f080,0xd0fa56);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f0b2,0xd0f86c);	// Candle: Axe
	XB_CandleAdd(0x24,0xd0f0c6,0xd0f8c6);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f0da,0xd0fa38);	// Candle: $50
	XB_CandleAdd(0x24,0xd0f0e4,0xd0f8bc);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f116,0xd0f862);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f166,0xd0fa42);	// Candle: Bible
	XB_CandleAdd(0x24,0xd0f17a,0xd0f858);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f18e,0xd0fa60);	// Candle: Big Heart
	// #10
	XB_CandleAdd(0x24,0xd0f1e4,0xd0fab6);	// Candle: $25
	XB_CandleAdd(0x24,0xd0f1ee,0xd0faac);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f1f8,0xd0faa2);	// Candle: Small Heart
	// #14
	XB_CandleAdd(0x24,0xd0f294,0xd0fb5c);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f2a8,0xd0fb52);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x24,0xd0f306,0xd0fbc4);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f324,0xd0fbce);	// Candle: $25
	XB_CandleAdd(0x24,0xd0f356,0xd0fbd8);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f360,0xd0fbe2);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f37e,0xd0fbec);	// Candle: Big Heart
	XB_CandleAdd(0x24,0xd0f39c,0xd0fc1e);	// Candle: Holy Water
	XB_CandleAdd(0x24,0xd0f3c4,0xd0fc28);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f3d8,0xd0fc32);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f3ec,0xd0fc00);	// Candle: Small Heart
	XB_CandleAdd(0x24,0xd0f3f6,0xd0fbf6);	// Candle: $50

	// Reverse Mines
	// #1
	XB_CandleAdd(0x25,0xcec90c,0xcecedc);	// Candle: $50
	XB_CandleAdd(0x25,0xcec916,0xcece8c);	// Candle: Small Heart
	XB_CandleAdd(0x25,0xcec948,0xcece82);	// Candle: $25
	XB_CandleAdd(0x25,0xcec952,0xcecec8);	// Candle: Big Heart
	XB_CandleAdd(0x25,0xcec95c,0xceceb4);	// Candle: Small Heart
	XB_CandleAdd(0x25,0xcec966,0xcecea0);	// Candle: Holy Water
	// #2
	XB_CandleAdd(0x25,0xcec98a,0xcecf0a);	// Candle: Small Heart
	XB_CandleAdd(0x25,0xcec99e,0xcecf28);	// Candle: Big Heart
	XB_CandleAdd(0x25,0xcec9a8,0xcecf14);	// Candle: $1
	XB_CandleAdd(0x25,0xcec9bc,0xcecf32);	// Candle: Big Heart
	XB_CandleAdd(0x25,0xcec9c6,0xcecf1e);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x25,0xceca14,0xced084);	// Candle: Axe
	XB_CandleAdd(0x25,0xceca28,0xcecfc6);	// Candle: Big Heart
	XB_CandleAdd(0x25,0xcecb0e,0xcecf8a);	// Candle: Rebound Stone
	XB_CandleAdd(0x25,0xcecb18,0xced034);	// Candle: $100
	// #6
	XB_CandleAdd(0x25,0xcecb6a,0xced0ca);	// Candle: $50
	
	// Reverse Chapel
	// #3
	XB_CandleAdd(0x26,0xcea1c8,0xceaca6);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea1e6,0xceac9c);	// Candle: Bible
	XB_CandleAdd(0x26,0xcea1fa,0xceac92);	// Candle: $50
	XB_CandleAdd(0x26,0xcea218,0xceac88);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea236,0xceac7e);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x26,0xcea2a0,0xcead60);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea2b4,0xcead56);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea2c8,0xcead4c);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x26,0xcea3a2,0xceae58);	// Candle: $25
	XB_CandleAdd(0x26,0xcea3b6,0xceae4e);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea3ca,0xceae44);	// Candle: Big Heart
	// #7
	XB_CandleAdd(0x26,0xcea408,0xceaea0);	// Candle: Big Heart
	// #9
	XB_CandleAdd(0x26,0xcea44e,0xceaeea);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea458,0xceaecc);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea462,0xceaec2);	// Candle: Big Heart
	// #11
	XB_CandleAdd(0x26,0xcea4be,0xceaf14);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea4c8,0xceaf0a);	// Candle: Big Heart
	// #12
	XB_CandleAdd(0x26,0xcea590,0xceb0b8);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea626,0xceafa0);	// Candle: $50
	XB_CandleAdd(0x26,0xcea676,0xceaf50);	// Candle: Big Heart
	// #24
	XB_CandleAdd(0x26,0xcea740,0xceb1d0);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea74a,0xceb176);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea812,0xceb180);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea81c,0xceb1da);	// Candle: $250
	XB_CandleAdd(0x26,0xcea826,0xceb22a);	// Candle: Big Heart
	XB_CandleAdd(0x26,0xcea830,0xceb27a);	// Candle: $400
	XB_CandleAdd(0x26,0xcea8bc,0xceb270);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea8c6,0xceb220);	// Candle: Small Heart
	XB_CandleAdd(0x26,0xcea8d0,0xceb1c6);	// Candle: Small Heart
	// #25
	XB_CandleAdd(0x26,0xcea92a,0xceb31a);	// Candle: Vibhuti
	XB_CandleAdd(0x26,0xcea95c,0xceb34c);	// Candle: $100
	// #26
	XB_CandleAdd(0x26,0xcea9e8,0xceb3f6);	// Candle: Small Heart
	
	// Reverse Entrance
	// #1
	XB_CandleAdd(0x27,0xd0bdfa,0xd0c600);	// Candle: Cross
	XB_CandleAdd(0x27,0xd0be5e,0xd0c5f6);	// Candle: $400
	XB_CandleAdd(0x27,0xd0be68,0xd0c5ec);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0be72,0xd0c5e2);	// Candle: Big Heart
	// #3
	XB_CandleAdd(0x27,0xd0bece,0xd0c6ac);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bef6,0xd0c6a2);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0bf1e,0xd0c698);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bf5a,0xd0c68e);	// Candle: $100
	XB_CandleAdd(0x27,0xd0bf82,0xd0c684);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bf96,0xd0c67a);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x27,0xd0bdc6,0xd0c76c);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0bdda,0xd0c762);	// Candle: Knife
	// #5
	XB_CandleAdd(0x27,0xd0bfca,0xd0c79a);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bfd4,0xd0c7ae);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bfde,0xd0c7c2);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0bfe8,0xd0c7a4);	// Candle: $1
	XB_CandleAdd(0x27,0xd0bff2,0xd0c7b8);	// Candle: Big Heart
	// #6
	XB_CandleAdd(0x27,0xd0c01c,0xd0c7e2);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c030,0xd0c7ec);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c044,0xd0c7f6);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0c062,0xd0c800);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c076,0xd0c80a);	// Candle: $25
	XB_CandleAdd(0x27,0xd0c0a8,0xd0c814);	// Candle: Holy Water
	// #7
	XB_CandleAdd(0x27,0xd0c0c6,0xd0c896);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x27,0xd0c0fe,0xd0c8ec);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c108,0xd0c932);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c112,0xd0c8f6);	// Candle: Stopwatch
	XB_CandleAdd(0x27,0xd0c130,0xd0c8e2);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0c13a,0xd0c928);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c144,0xd0c8d8);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x27,0xd0c1ce,0xd0c9e4);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c1ec,0xd0c9da);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c21e,0xd0c9d0);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c228,0xd0c9a8);	// Candle: Axe
	XB_CandleAdd(0x27,0xd0c23c,0xd0c9c6);	// Candle: $100
	XB_CandleAdd(0x27,0xd0c250,0xd0c9bc);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c264,0xd0c9b2);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x27,0xd0c30a,0xd0cada);	// Candle: $50
	XB_CandleAdd(0x27,0xd0c314,0xd0cae4);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c31e,0xd0caee);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c328,0xd0caf8);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x27,0xd0c394,0xd0cb64);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c3a8,0xd0cbaa);	// Candle: Big Heart
	XB_CandleAdd(0x27,0xd0c3b2,0xd0cb6e);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c3ee,0xd0cbbe);	// Candle: Small Heart
	XB_CandleAdd(0x27,0xd0c3f8,0xd0cb5a);	// Candle: $1
	
	// Reverse Caverns
	// #1
	XB_CandleAdd(0x29,0xd07fa4,0xd08fce);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd07fae,0xd08fe2);	// Candle: $50
	XB_CandleAdd(0x29,0xd07fb8,0xd08fd8);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd07fcc,0xd08fec);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd07fd6,0xd08fc4);	// Candle: $100
	XB_CandleAdd(0x29,0xd07fe0,0xd08fba);	// Candle: $400
	// #2
	XB_CandleAdd(0x29,0xd08032,0xd09078);	// Candle: $25
	XB_CandleAdd(0x29,0xd0803c,0xd0908c);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08046,0xd09064);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08050,0xd09082);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0805a,0xd0906e);	// Candle: Big Heart
	// #4
	XB_CandleAdd(0x29,0xd08082,0xd0914a);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0808c,0xd0910e);	// Candle: $250
	XB_CandleAdd(0x29,0xd08096,0xd090dc);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd080dc,0xd09136);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd080e6,0xd090f0);	// Candle: Axe
	XB_CandleAdd(0x29,0xd080fa,0xd09122);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08122,0xd090c8);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0812c,0xd09154);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd08136,0xd090fa);	// Candle: Big Heart
	// #5
	XB_CandleAdd(0x29,0xd0815a,0xd0927c);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08164,0xd09272);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x29,0xd08272,0xd092c2);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0827c,0xd092ae);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd08290,0xd092b8);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0829a,0xd0929a);	// Candle: Knife
	// #7
	XB_CandleAdd(0x29,0xd082c4,0xd092f6);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd082ce,0xd092ec);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd082d8,0xd09332);	// Candle: $1
	XB_CandleAdd(0x29,0xd082f6,0xd0933c);	// Candle: $1
	XB_CandleAdd(0x29,0xd0830a,0xd09314);	// Candle: $1
	XB_CandleAdd(0x29,0xd0831e,0xd0931e);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd08328,0xd0930a);	// Candle: $1
	// #13
	XB_CandleAdd(0x29,0xd0853a,0xd095a8);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08544,0xd0959e);	// Candle: $25
	XB_CandleAdd(0x29,0xd0858a,0xd095c6);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd08594,0xd095bc);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0859e,0xd095b2);	// Candle: Small Heart
	// #16
	XB_CandleAdd(0x29,0xd08682,0xd0972c);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08696,0xd09722);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd086c8,0xd09718);	// Candle: $25
	XB_CandleAdd(0x29,0xd086f0,0xd0970e);	// Candle: Small Heart
	// #20
	XB_CandleAdd(0x29,0xd08346,0xd097ee);	// Candle: $1
	XB_CandleAdd(0x29,0xd0835a,0xd097e4);	// Candle: Small Heart
	// #21
	XB_CandleAdd(0x29,0xd087bc,0xd09822);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd087c6,0xd09818);	// Candle: Small Heart
	// #23
	XB_CandleAdd(0x29,0xd08884,0xd09914);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08898,0xd0990a);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd088ac,0xd099fa);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd088de,0xd099be);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd088fc,0xd099dc);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd0891a,0xd099d2);	// Candle: $100
	XB_CandleAdd(0x29,0xd0894c,0xd099c8);	// Candle: $50
	XB_CandleAdd(0x29,0xd08956,0xd099b4);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd089b0,0xd099aa);	// Candle: Small Heart
	// #24
	XB_CandleAdd(0x29,0xd089e2,0xd09b30);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd089f6,0xd09b26);	// Candle: Small Heart
	// #26
	XB_CandleAdd(0x29,0xd08c06,0xd09c1e);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08c10,0xd09d5e);	// Candle: $250
	XB_CandleAdd(0x29,0xd08c60,0xd09d18);	// Candle: $2000
	XB_CandleAdd(0x29,0xd08c9c,0xd09d68);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08cb0,0xd09d72);	// Candle: Small Heart
	// #29
	XB_CandleAdd(0x29,0xd08d92,0xd09dfa);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08da6,0xd09e04);	// Candle: Cross
	XB_CandleAdd(0x29,0xd08dc4,0xd09e0e);	// Candle: Small Heart
	// #30
	XB_CandleAdd(0x29,0xd08de2,0xd09e90);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08df6,0xd09e68);	// Candle: $50
	XB_CandleAdd(0x29,0xd08e0a,0xd09e5e);	// Candle: Big Heart
	XB_CandleAdd(0x29,0xd08e1e,0xd09e54);	// Candle: Small Heart
	XB_CandleAdd(0x29,0xd08e32,0xd09e4a);	// Candle: Cross
	XB_CandleAdd(0x29,0xd08e3c,0xd09e86);	// Candle: Small Heart
	
	// Reverse Colosseum
	// #3
	XB_CandleAdd(0x2a,0xce550a,0xce5bc4);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce551e,0xce5bba);	// Candle: $50
	XB_CandleAdd(0x2a,0xce5532,0xce5bb0);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce5546,0xce5ba6);	// Candle: $100
	XB_CandleAdd(0x2a,0xce5550,0xce5b9c);	// Candle: Big Heart
	XB_CandleAdd(0x2a,0xce5564,0xce5b92);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x2a,0xce5582,0xce5c0a);	// Candle: $50
	XB_CandleAdd(0x2a,0xce558c,0xce5c28);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce5596,0xce5c1e);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce55be,0xce5c14);	// Candle: Agunea
	// #7
	XB_CandleAdd(0x2a,0xce5664,0xce5cda);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce566e,0xce5ce4);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce56a0,0xce5cee);	// Candle: $50
	XB_CandleAdd(0x2a,0xce56b4,0xce5cf8);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce56be,0xce5d02);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce56c8,0xce5d0c);	// Candle: Big Heart
	// #8
	XB_CandleAdd(0x2a,0xce56f2,0xce5e30);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce56fc,0xce5d86);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce574c,0xce5e26);	// Candle: Big Heart
	XB_CandleAdd(0x2a,0xce5756,0xce5d7c);	// Candle: $100
	XB_CandleAdd(0x2a,0xce5760,0xce5e1c);	// Candle: $25
	XB_CandleAdd(0x2a,0xce576a,0xce5d72);	// Candle: Big Heart
	// #9
	XB_CandleAdd(0x2a,0xce57da,0xce5e78);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce57ee,0xce5e6e);	// Candle: $25
	XB_CandleAdd(0x2a,0xce5816,0xce5e64);	// Candle: $25
	XB_CandleAdd(0x2a,0xce5834,0xce5e5a);	// Candle: Small Heart
	// #12
	XB_CandleAdd(0x2a,0xce58cc,0xce5f9c);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce58f4,0xce5f24);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce5908,0xce5fa6);	// Candle: $25
	XB_CandleAdd(0x2a,0xce5912,0xce5f2e);	// Candle: $100
	XB_CandleAdd(0x2a,0xce591c,0xce5fb0);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce5926,0xce5fba);	// Candle: Big Heart
	XB_CandleAdd(0x2a,0xce5930,0xce5f38);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x2a,0xce597a,0xce5ffa);	// Candle: Big Heart
	XB_CandleAdd(0x2a,0xce598e,0xce6004);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce59a2,0xce600e);	// Candle: Small Heart
	XB_CandleAdd(0x2a,0xce59b6,0xce6018);	// Candle: $1000
	// #14
	XB_CandleAdd(0x2a,0xce59fe,0xce6088);	// Candle: Knife
	XB_CandleAdd(0x2a,0xce5a12,0xce607e);	// Candle: Holy Water
	XB_CandleAdd(0x2a,0xce5a26,0xce6074);	// Candle: Rebound Stone
	XB_CandleAdd(0x2a,0xce5a30,0xce606a);	// Candle: Axe
	
	// Reverse Keep
	// #1
	XB_CandleAdd(0x2b,0xcfe4ba,0xcfea52);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe4ce,0xcfea48);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe4d8,0xcfea3e);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe4ec,0xcfea34);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe500,0xcfeb60);	// Candle: Cross
	XB_CandleAdd(0x2b,0xcfe50a,0xcfea2a);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe532,0xcfea20);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe56e,0xcfeb24);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe578,0xcfea16);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe58c,0xcfea0c);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5a0,0xcfeb1a);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5aa,0xcfea02);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5b4,0xcfe9f8);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5c8,0xcfeb10);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5d2,0xcfe9ee);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5e6,0xcfeb06);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe5f0,0xcfe9e4);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe604,0xcfeafc);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe60e,0xcfeaf2);	// Candle: Holy Water
	XB_CandleAdd(0x2b,0xcfe618,0xcfe9da);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe622,0xcfe9d0);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe62c,0xcfe9c6);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe64a,0xcfe9bc);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe686,0xcfe9b2);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe690,0xcfe9a8);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe69a,0xcfe99e);	// Candle: Small Heart
	XB_CandleAdd(0x2b,0xcfe6b8,0xcfe994);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0x2b,0xcfe7f4,0xcfed1a);	// Candle: Big Heart
	
	// Reverse Alchemy Lab
	// #2
	XB_CandleAdd(0x2c,0xd03f5a,0xd049c8);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd03f64,0xd049dc);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd03f6e,0xd049d2);	// Candle: $25
	XB_CandleAdd(0x2c,0xd03f82,0xd049b4);	// Candle: Holy Water
	XB_CandleAdd(0x2c,0xd03f8c,0xd049be);	// Candle: Big Heart
	// #3
	XB_CandleAdd(0x2c,0xd03faa,0xd04a54);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd03fb4,0xd04a40);	// Candle: Rebound Stone
	XB_CandleAdd(0x2c,0xd03fbe,0xd04a18);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd03fd2,0xd04a0e);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd03fdc,0xd04a36);	// Candle: $250
	XB_CandleAdd(0x2c,0xd03fe6,0xd04a4a);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd03ffa,0xd04a2c);	// Candle: $25
	XB_CandleAdd(0x2c,0xd04004,0xd04a04);	// Candle: Small Heart
	// #5
	XB_CandleAdd(0x2c,0xd0404c,0xd04aba);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0406a,0xd04ab0);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x2c,0xd0408a,0xd043f0);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04094,0xd043fa);	// Candle: Small Heart
	// #8
	XB_CandleAdd(0x2c,0xd040ec,0xd04b22);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0410a,0xd04b18);	// Candle: Small Heart
	// #9
	XB_CandleAdd(0x2c,0xd04134,0xd04b6a);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04152,0xd04b60);	// Candle: Small Heart
	// #10
	XB_CandleAdd(0x2c,0xd04190,0xd04b9e);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd041ae,0xd04b8a);	// Candle: $50
	XB_CandleAdd(0x2c,0xd041b8,0xd04bb2);	// Candle: Small Heart
	// #11
	XB_CandleAdd(0x2c,0xd04200,0xd04c40);	// Candle: Axe
	XB_CandleAdd(0x2c,0xd0420a,0xd04c2c);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04214,0xd04c22);	// Candle: $50
	XB_CandleAdd(0x2c,0xd0421e,0xd04bfa);	// Candle: Small Heart
	// #12
	XB_CandleAdd(0x2c,0xd04266,0xd04c88);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd04270,0xd04c7e);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0427a,0xd04c74);	// Candle: Small Heart
	// #13
	XB_CandleAdd(0x2c,0xd042ae,0xd04582);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd042b8,0xd04578);	// Candle: $50
	// #14
	XB_CandleAdd(0x2c,0xd04326,0xd04d20);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04330,0xd04d0c);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0433a,0xd04ce4);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04344,0xd04cda);	// Candle: Knife
	// #15
	XB_CandleAdd(0x2c,0xd0438c,0xd04d72);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd043a0,0xd04d86);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd043aa,0xd04d7c);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd043c8,0xd04d68);	// Candle: $50
	// #18
	XB_CandleAdd(0x2c,0xd044ba,0xd04e8e);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd044ce,0xd04ea2);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd044e2,0xd04e98);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04500,0xd04e66);	// Candle: $100
	XB_CandleAdd(0x2c,0xd0451e,0xd04eb6);	// Candle: $50
	XB_CandleAdd(0x2c,0xd04532,0xd04e5c);	// Candle: $1
	XB_CandleAdd(0x2c,0xd04550,0xd04eac);	// Candle: Small Heart
	// #19
	XB_CandleAdd(0x2c,0xd045aa,0xd04f1c);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd045b4,0xd04f26);	// Candle: $50
	XB_CandleAdd(0x2c,0xd045be,0xd04f30);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd045c8,0xd04f76);	// Candle: $50
	XB_CandleAdd(0x2c,0xd045d2,0xd04f80);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd045fa,0xd04f58);	// Candle: $25
	XB_CandleAdd(0x2c,0xd04618,0xd04f62);	// Candle: Small Heart
	// #20
	XB_CandleAdd(0x2c,0xd0464c,0xd05018);	// Candle: $1
	XB_CandleAdd(0x2c,0xd04656,0xd0500e);	// Candle: Big Heart
	XB_CandleAdd(0x2c,0xd04660,0xd04ff0);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0466a,0xd04fe6);	// Candle: $100
	XB_CandleAdd(0x2c,0xd04674,0xd04fd2);	// Candle: Vibhuti
	XB_CandleAdd(0x2c,0xd046ba,0xd04fc8);	// Candle: $400
	XB_CandleAdd(0x2c,0xd046c4,0xd05022);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd046ce,0xd05040);	// Candle: $50
	// #22
	XB_CandleAdd(0x2c,0xd04702,0xd0507e);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0470c,0xd05074);	// Candle: $50
	XB_CandleAdd(0x2c,0xd04720,0xd05092);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd0472a,0xd0509c);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04734,0xd05088);	// Candle: Small Heart
	// #24
	XB_CandleAdd(0x2c,0xd047e4,0xd05160);	// Candle: Small Heart
	XB_CandleAdd(0x2c,0xd04802,0xd0516a);	// Candle: Small Heart
	// #27
	XB_CandleAdd(0x2c,0xd04822,0xd051a8);	// Candle: $25
	XB_CandleAdd(0x2c,0xd04840,0xd051b2);	// Candle: Small Heart

	// Reverse Clock Tower
	// #2
	XB_CandleAdd(0x2d,0xd00afa,0xd01464);	// Candle: $1
	XB_CandleAdd(0x2d,0xd00b0e,0xd0146e);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00b18,0xd014a0);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00b2c,0xd014aa);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00b36,0xd01478);	// Candle: $100
	XB_CandleAdd(0x2d,0xd00b4a,0xd01482);	// Candle: Small Heart
	// #3
	XB_CandleAdd(0x2d,0xd00b6a,0xd014d4);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00b7e,0xd014ca);	// Candle: Small Heart
	// #4
	XB_CandleAdd(0x2d,0xd00ba2,0xd0162e);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd00bac,0xd01548);	// Candle: $25
	XB_CandleAdd(0x2d,0xd00bb6,0xd015d4);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00bc0,0xd01656);	// Candle: $100
	XB_CandleAdd(0x2d,0xd00bca,0xd01552);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00c06,0xd0155c);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd00c10,0xd01566);	// Candle: Knife
	XB_CandleAdd(0x2d,0xd00c4c,0xd01570);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00c56,0xd0161a);	// Candle: $100
	XB_CandleAdd(0x2d,0xd00c6a,0xd0157a);	// Candle: $50
	XB_CandleAdd(0x2d,0xd00c74,0xd01584);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd00c92,0xd0158e);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00c9c,0xd01638);	// Candle: $50
	XB_CandleAdd(0x2d,0xd00ca6,0xd01598);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00cce,0xd015a2);	// Candle: $25
	XB_CandleAdd(0x2d,0xd00cd8,0xd015de);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00ce2,0xd015ac);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00cec,0xd015e8);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd00d00,0xd015c0);	// Candle: Small Heart
	// #6
	XB_CandleAdd(0x2d,0xd00d7a,0xd016de);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd00d84,0xd016e8);	// Candle: $250
	// #8
	XB_CandleAdd(0x2d,0xd00f34,0xd018f2);	// Candle: Holy Water
	XB_CandleAdd(0x2d,0xd00f52,0xd017b2);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00f7a,0xd0180c);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd00f84,0xd0185c);	// Candle: Vibhuti
	// #9
	XB_CandleAdd(0x2d,0xd00fc2,0xd019e4);	// Candle: Axe
	XB_CandleAdd(0x2d,0xd00fcc,0xd01944);	// Candle: Rebound Stone
	XB_CandleAdd(0x2d,0xd00ffe,0xd019da);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd01008,0xd0196c);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd0101c,0xd01976);	// Candle: $25
	XB_CandleAdd(0x2d,0xd01026,0xd019d0);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd01030,0xd01980);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd0106c,0xd019c6);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd01080,0xd0198a);	// Candle: $25
	XB_CandleAdd(0x2d,0xd0108a,0xd01926);	// Candle: $50
	XB_CandleAdd(0x2d,0xd01094,0xd01930);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd010bc,0xd01958);	// Candle: Small Heart
	// #15
	XB_CandleAdd(0x2d,0xd01152,0xd01b60);	// Candle: Vibhuti
	XB_CandleAdd(0x2d,0xd0115c,0xd01b42);	// Candle: Holy Water
	XB_CandleAdd(0x2d,0xd011e8,0xd01aac);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd0122e,0xd01b06);	// Candle: Holy Water
	XB_CandleAdd(0x2d,0xd01238,0xd01af2);	// Candle: Vibhuti
	// #16
	XB_CandleAdd(0x2d,0xd0127a,0xd01c06);	// Candle: Big Heart
	XB_CandleAdd(0x2d,0xd012e8,0xd01c60);	// Candle: Knife
	XB_CandleAdd(0x2d,0xd01306,0xd01bfc);	// Candle: Small Heart
	XB_CandleAdd(0x2d,0xd01310,0xd01c10);	// Candle: Small Heart
	
	// Clock Room 1st Castle
	// XB_CandleAdd(0x00,0xD5759C,0xD58488);
	// XB_CandleAdd(0x00,0xD575BA,0xD58492);
	// Clock Room 2nd Castle

	if(DebugToConsole)
		printf("Candles in Database: %d\n",XB_CandleCount());
	
	XB_ReadCandleContents();
	//printf("Candles with Small Heart: %d\n",XB_CandleCountItem(0));
	//printf("Candles with Big Heart: %d\n",XB_CandleCountItem(1));
	
	if(DebugToConsole)
	{
		ItemN = 0;
		while(1)
		{
			printf("Candles with %s: %d\n",CandleContents[ItemN],XB_CandleCountItem(ItemN));
			ItemN++;
			if(ItemN == 0xC) ItemN = 0xE;	// skip these.
			if(ItemN>=0x17) break;
		}		
	}
	
	// Debug! Sets all Candles to $5000
	//XB_CandleDebug(0xB);
	
	/*
	Candles in Database: 1326
	Candles with Small Heart: 713
	Candles with Big Heart: 226
	Candles with $1: 49
	Candles with $25: 84
	Candles with $50: 58
	Candles with $100: 46
	Candles with $250: 19
	Candles with $400: 8
	Candles with $700: 0
	Candles with $1000: 2
	Candles with $2000: 2
	Candles with $5000: 0
	Candles with Knife: 19
	Candles with Axe: 19
	Candles with Cross: 7
	Candles with Holy Water: 23
	Candles with Stopwatch: 11
	Candles with Bible: 10
	Candles with Rebound Stone: 15
	Candles with Vibhuti: 12
	Candles with Agunea: 2	
	*/


	
	for(int c=0;c<2;c++)	{	XB_CandlePlaceItemAtRandom(0x16);	}		// Agunea
	for(int c=0;c<12;c++)	{	XB_CandlePlaceItemAtRandom(0x15);	}		// Vibhuti
	for(int c=0;c<15;c++)	{	XB_CandlePlaceItemAtRandom(0x14);	}		// Rebound Stone
	for(int c=0;c<10;c++)	{	XB_CandlePlaceItemAtRandom(0x13);	}		// Bible
	for(int c=0;c<11;c++)	{	XB_CandlePlaceItemAtRandom(0x12);	}		// Stopwatch
	for(int c=0;c<23;c++)	{	XB_CandlePlaceItemAtRandom(0x11);	}		// Holy Water
	for(int c=0;c<7;c++)	{	XB_CandlePlaceItemAtRandom(0x10);	}		// Cross
	for(int c=0;c<19;c++)	{	XB_CandlePlaceItemAtRandom(0x0F);	}		// Axe
	for(int c=0;c<19;c++)	{	XB_CandlePlaceItemAtRandom(0x0E);	}		// Knife
	for(int c=0;c<2;c++)	{	XB_CandlePlaceItemAtRandom(0x0A);	}		// $2000
	for(int c=0;c<2;c++)	{	XB_CandlePlaceItemAtRandom(0x09);	}		// $1000
	for(int c=0;c<8;c++)	{	XB_CandlePlaceItemAtRandom(0x07);	}		// $400
	for(int c=0;c<19;c++)	{	XB_CandlePlaceItemAtRandom(0x06);	}		// $250
	for(int c=0;c<46;c++)	{	XB_CandlePlaceItemAtRandom(0x05);	}		// $100
	for(int c=0;c<58;c++)	{	XB_CandlePlaceItemAtRandom(0x04);	}		// $50
	for(int c=0;c<84;c++)	{	XB_CandlePlaceItemAtRandom(0x03);	}		// $25
	for(int c=0;c<49;c++)	{	XB_CandlePlaceItemAtRandom(0x02);	}		// $1
	for(int c=0;c<226;c++)	{	XB_CandlePlaceItemAtRandom(0x01);	}		// Big Hearts
	//for(int c=0;c<713;c++)	{	XB_CandlePlaceItemAtRandom(0x00);	}
	XB_CandleFillRemaining();
	LogMsg("Candle Rando Applied!");
}























