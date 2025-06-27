--

/*
If creature wasn't sniffed, in most cases its attack time and speed were changed to default and common values. Personally I think
in TBC time someone used random number generator to fill those fields and it's way much easier to change them all to default,
however some of them may be valid(definitely not in this case). Other stats were taken from CreatureDifficulty

List of not sniffed, excluding upgraded units(only one of them was sniffed, seems like they just takes all basic stats
from default unit. Anyway it's hard to sniff all of them):
(603,10991,11998,13088,13098,13161,13178,13256,13316,13419,13440,13441,13446,13449,13524,13528,13576,13618,13676,13959,13616,14285,14943,14944,14945,14946,14947,14948)

All (probably, not sure) creatures:
(603,2225,3343,3625,4255,4257,5134,5135,5139,10364,10367,10981,10982,10983,10984,10986,10987,10990,10991,11600,11602,11603,11604,11605,11657,11675,11677,11678,11679,11837,11838,11839,11840,11946,11947,11948,11949,11997,11998,12047,12048,12050,12051,12052,12053,12096,12097,12121,12122,12127,12156,12157,12158,12159,13078,13079,13080,13081,13086,13087,13088,13089,13096,13097,13098,13099,13116,13117,13137,13138,13139,13140,13143,13144,13145,13146,13147,13149,13150,13151,13152,13153,13154,13155,13161,13176,13178,13179,13180,13181,13216,13217,13218,13219,13221,13236,13256,13257,13284,13296,13297,13298,13299,13300,13316,13317,13318,13319,13320,13324,13325,13326,13327,13328,13329,13330,13331,13332,13333,13334,13335,13336,13337,13356,13357,13358,13359,13377,13378,13396,13397,13416,13419,13421,13422,13424,13425,13426,13427,13428,13437,13438,13439,13440,13441,13442,13443,13446,13447,13448,13449,13524,13525,13526,13527,13528,13529,13530,13531,13534,13535,13536,13537,13538,13539,13540,13541,13542,13543,13544,13545,13546,13547,13548,13549,13550,13551,13552,13553,13554,13555,13556,13557,13576,13577,13597,13598,13616,13617,13618,13676,13776,13777,13797,13798,13816,13817,13840,13841,13956,13957,13958,13959,14021,14026,14027,14028,14029,14030,14031,14185,14186,14187,14188,14282,14283,14284,14285,14762,14763,14764,14765,14766,14767,14768,14769,14770,14771,14772,14773,14774,14775,14776,14777,14848,14943,14944,14945,14946,14947,14948,15103,15106,10985,10989,11606,11676,13281,13496,13516,13517,13518,13519,13520,13521,13522,13523,13977,14016,14017,14018,14019,14141,14142,14274,14643,14644,14719,14746,15139,11599,11601,

22525,22526,22527,22528,22529,22530,22531,22532,22533,22534,22535,22536,22537,22538,22539,22540,22541,22542,22543,22544,22545,22546,22547,22548,22549,22550,22551,22552,22553,22554,22555,22556,22557,22558,22559,22560,22561,22562,22563,22564,22565,22566,22567,22568,22569,22570,22571,22572,22573,22574,22575,22576,22577,22578,22579,22580,22581,22582,22583,22584,22585,22586,22587,22588,22589,22590,22591,22592,22593,22594,22595,22596,22597,22598,22599,22600,22601,22602,22603,22604,22605,22606,22607,22608,22609,22610,22611,22612,22613,22614,22615,22616,22617,22618,22619,22620,22621,22622,22623,22624,22625,22626,22627,22628,22629,22630,22631,22632,22633,22634,22635,22636,22637,22638,22639,22640,22641,22642,22643,22644,22645,22646,22647,22648,22649,22650,22651,22652,22653,22654,22655,22656,22657,22658,22659,22660,22661,22662,22663,22664,22665,22666,22667,22668,22669,22670,22671,22672,22673,22674,22675,22676,22677,22678,22679,22680,22681,22682,22683,22684,22685,22686,22687,22688,22689,22690,22691,22692,22693,22694,22695,22696,22697,22698,22699,22700,22701,22702,22703,22704,22705,22706,22707,22708,22709,22710,22711,22712,22713,22714,22715,22716,22717,22718,22719,22720,22721,22722,22723,22724,22725,22726,22727,22728,22729,22730,22731,22732,22733,22734,22735,22736,22737,22738,22739,22740,22741,22742,22743,22744,22745,22746,22747,22748,22749,22750,22751,22752,22753,22754,22755,22756,22757,22758,22759,22760,22761,22762,22763,22764,22765,22766,22767,22768,22769,22770,22771,22772,22773,22774,22775,22776,22777,22778,22779,22780,22781,22782,22783,22784,22785,22786,22787,22788,22789,22790,22791,22792,22793,22794,22795,22796,22797,

31055,31818,31819,31820,31821,31822,31823,31824,31825,31826,31828,31829,31903,31904,31905,31906,31907,31908,31909,31917,31918,31919,31920,31921,31922,31923,31924,31925,31926,31927,31928,31929,31930,31931,31932,31933,31934,31935,31936,31937,31938,31939,31940,31941,31942,31943,31944,31945,31946,31947,31948,31949,31950,31951,31952,31953,31954,31955,31956,31957,31958,31959,31960,31961,31962,31963,31964,31965,31966,31968,31969,31970,31971,31972,31973,31974,31975,31976,31977,31978,31979,31980,31981,31982,31983,31984,31985,31986,31987,31988,31989,31990,31991,31992,31993,31994,31995,31996,31997,31998,31999,32000,32001,32002,32003,32004,32005,32006,32007,32008,32009,32010,32011,32012,32013,32014,32015,32016,32017,32018,32019,32020,32021,32022,32023,32024,32025,32026,32027,32028,32029,32030,32031,32032,32033,32034,32035,32036,32037,32038,32039,32040,32041,32042,32043,32044,32045,32046,32048,32049,32050,32051,32052,32053,32054,32055,32056,32057,32058,32059,32060,32061,32062,32063,32064,32065,32066,32067,32068,32069,32070,32071,32072,32073,32074,32075,32077,32078,32080,32081,32082,32083,32086,32087,32088,32089,32090,32091,32092,32093,32094,32095,32096,32097,32098,32099,32100,32101,32102,32103,32104,32105,32106,32107,32108,32109,32110,32111,32112,32113,32114,32115,32116,32117,32118,32119,32120,32121,32122,32123,32124,32125,32126,32127,32128,32129,32130,32131,32132,32133,32134,32135,32136,32137,32138,32139,32140,32141,32142,32143,32144,32145,32146,32147,32148,32764,32765,32766,

37233,37234,37235,37236,37237,37238,37239,37240,37241,37242,37243,37244,37245,37246,37247,37248,37249,37250,37251,37252,37253,37254,37255,37256,37257,37258,37259,37260,37261,37262,37263,37264,37265,37266,37267,37268,37269,37270,37271,37272,37273,37274,37275,37276,37277,37278,37279,37280,37281,37282,37283,37284,37285,37287,37288,37289,37290,37291,37292,37293,37294,37295,37296,37297,37298,37299,37300,37301,37302,37303,37304,37305,37306,37307,37308,37309,37310,37311,37312,37313,37314,37315,37316,37317,37318,37319,37320,37321,37322,37323,37324,37325,37326,37327,37328,37329,37330,37331,37332,37333,37334,37335,37336,37337,37338,37339,37340,37341,37342,37343,37344,37345,37346,37347,37348,37349,37350,37351,37352,37353,37354,37355,37356,37357,37358,37359,37360,37361,37362,37363,37364,37365,37366,37367,37369,37370,37371,37372,37373,37374,37375,37376,37377,37378,37379,37380,37381,37382,37383,37384,37385,37386,37387,37388,37389,37390,37391,37392,37393,37394,37395,37396,37398,37399,37401,37402,37403,37404,37407,37408,37409,37410,37411,37412,37413,37414,37415,37416,37417,37418,37419,37420,37421,37422,37423,37424,37425,37426,37427,37428,37429,37430,37431,37432,37433,37434,37435,37436,37437,37438,37439,37440,37441,37442,37443,37444,37445,37446,37447,37448,37449,37450,37451,37452,37453,37454,37455,37456,37457,37458,37459,37460,37461,37462,37463,37464,37465,37466,37467,37468,37469,37470,37471,37472,37473,37474,37475,37476,37477,37478,37479,37480,37481,37482,37483,37484,37485,37486)
*/

-- Grimtooth (not sniffed)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 603;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22555;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32000;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37319;
-- Zora Guthrek
-- 2225
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22661;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32764;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37486;
-- Grelkor
-- 3343
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22650;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31999;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37318;
-- Rarck
UPDATE `creature_template` SET `npcflag` = `npcflag` |256 WHERE `entry` = 3625;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22654;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32052;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37373;
-- Brogus Thunderbrew
UPDATE `creature_template` SET `npcflag` = `npcflag` |512 WHERE `entry` = 4255;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22646;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31926;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37242;
-- Lana Thunderbrew
-- 4257
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22653;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32029;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37349;
-- Jonivera Farmountain
UPDATE `creature_template` SET `npcflag` = `npcflag` |256 WHERE `entry` = 5134;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22651;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32024;
UPDATE `creature_template` SET `npcflag` = `npcflag` |256, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37344;
-- Svalbrad Farmountain
-- 5135
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22659;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32106;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37427;
-- Kurdrum Barleybeard
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048 WHERE `entry` = 5139;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22652;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32028;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37348;
-- Yaelika Farclaw
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048 WHERE `entry` = 10364;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22660;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32765;
UPDATE `creature_template` SET `npcflag` = `npcflag` |1024|2048, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37485;
-- Shrye Ragefist
UPDATE `creature_template` SET `npcflag` = `npcflag` |512 WHERE `entry` = 10367;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22655;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32078;
UPDATE `creature_template` SET `npcflag` = `npcflag` |512, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37399;
-- Frostwolf
-- 10981
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 22737;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31975;
UPDATE `creature_template` SET `exp` = 2, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37294;
-- Whitewhisker Vermin
-- 10982
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22782;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32143;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37473;
-- Winterax Troll (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 10983;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22794;
-- Winterax Berserker (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 10984;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22725;
-- Ice Giant (unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1 WHERE `entry` = 10985;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22626;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32005;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37324;
-- Snowblind Harpy
-- 10986
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889 WHERE `entry` = 22762;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889 WHERE `entry` = 32082;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37403;
-- Irondeep Trogg
-- 10987
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22750;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32021;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37340;
-- Blizzard Elemental (unused)
UPDATE `creature_template` SET `minlevel` = 56, `maxlevel` = 58, `speed_walk` = 1 WHERE `entry` = 10989;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22728;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31925;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37241;
-- Alterac Ram
UPDATE `creature_template` SET `difficulty_entry_1` = 22727, `minlevel` = 50, `maxlevel` = 51 WHERE `entry` = 10990;
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 61, `exp` = 2, `speed_walk` = 1, `speed_run` = 1.38571 WHERE `entry` = 22727;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1, `speed_run` = 1.38571 WHERE `entry` = 31921;
UPDATE `creature_template` SET `exp` = 2, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37237;
-- Wildpaw Gnoll (not sniffed)
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 10991;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048, `BaseAttackTime` = 2000 WHERE `entry` = 22785;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 32146;
UPDATE `creature_template` SET `exp` = 1, `speed_run` = 1.19048 WHERE `entry` = 37476;
-- Irondeep Geomancer UNUSED
-- 11599
-- Irondeep Shaman
UPDATE `creature_template` SET `minlevel` = 53, `maxlevel` = 54 WHERE `entry` = 11600;
UPDATE `creature_template` SET `minlevel` = 63, `maxlevel` = 64, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22747;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32018;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 74, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37337;
-- Irondeep Cave Lurker UNUSED
-- 11601
-- Irondeep Skullthumper
-- 11602
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22748;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32019;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37338;
-- Whitewhisker Digger
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 11603;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22778;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32139;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37469;
-- Whitewhisker Geomancer
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 11604;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22779;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32140;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 74, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37470;
-- Whitewhisker Overseer
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 11605;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22780;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32141;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37471;
-- Whitewhisker Tunnel Rat (unused \ removed)
UPDATE `creature_template` SET `minlevel` = 52, `maxlevel` = 53, `speed_walk` = 1 WHERE `entry` = 11606;
UPDATE `creature_template` SET `minlevel` = 62, `maxlevel` = 63, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22781;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1 WHERE `entry` = 32142;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1 WHERE `entry` = 37472;
-- Morloch
UPDATE `creature_template` SET `exp` = 0 WHERE `entry` = 11657;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22685;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 32045;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37366;
-- Snowblind Windcaller
-- 11675
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889 WHERE `entry` = 22763;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889 WHERE `entry` = 32083;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 74, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37404;
-- Fjordune the Greater (unused)
UPDATE `creature_template` SET `minlevel` = 62, `maxlevel` = 62, `speed_walk` = 1 WHERE `entry` = 11676;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22642;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 1 WHERE `entry` = 31974;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 1 WHERE `entry` = 37293;
-- Taskmaster Snivvle (4xx sniffs only, level 57 so probably already scaled and not static)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 11677;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22694;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32110;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37431;
-- Snowblind Ambusher
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 11678;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889, `BaseAttackTime` = 1700 WHERE `entry` = 22761;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1.38889, `BaseAttackTime` = 1700 WHERE `entry` = 32081;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `BaseAttackTime` = 1700, `RangeAttackTime` = 2000 WHERE `entry` = 37402;
-- Winterax Witch Doctor (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 11679;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22796;
-- Wildpaw Shaman
-- 11837
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 22787;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 32148;
UPDATE `creature_template` SET `exp` = 1, `speed_run` = 1.19048 WHERE `entry` = 37478;
-- Wildpaw Mystic
-- 11838
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 22786;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 32147;
UPDATE `creature_template` SET `exp` = 1, `speed_run` = 1.19048 WHERE `entry` = 37477;
-- Wildpaw Brute
-- 11839
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 22784;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 32145;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37475;
-- Wildpaw Alpha
-- 11840
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 22783;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 1.19048 WHERE `entry` = 32144;
UPDATE `creature_template` SET `exp` = 1, `speed_run` = 1.19048 WHERE `entry` = 37474;
-- Drek'Thar
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `BaseAttackTime` = 2000 WHERE `entry` = 11946;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22641;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31819;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82 WHERE `entry` = 37283;
-- Captain Galvangar
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60 WHERE `entry` = 11947;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22606;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31055;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81 WHERE `entry` = 37244;
-- Vanndar Stormpike
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `exp` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 11948;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22644;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31818;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82 WHERE `entry` = 37444;
-- Captain Balinda Stonehearth
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `BaseAttackTime` = 2000 WHERE `entry` = 11949;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22605;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31820;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81 WHERE `entry` = 37243;
-- Stormpike Herald
-- 11997
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22574;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32095;
UPDATE `creature_template` SET `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37416;
-- Frostwolf Herald (not sniffed)
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 11998;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22549;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31982;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37301;
-- Stormpike Mountaineer (not sniffed, spawns only in Dun Morogh)
-- 12047
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `exp` = 1 WHERE `entry` = 22657;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 32097;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 37418;
-- Alliance Sentinel (no longer used)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 12048;
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22645;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 31919;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 37235;
-- Stormpike Defender
-- 12050
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22690;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32091;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37412;
-- Frostwolf Legionnaire
-- 12051
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22665;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31983;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37302;
-- Frostwolf Warrior (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 12052;
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22649;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 31992;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 37311;
-- Frostwolf Guardian
-- 12053
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22674;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31981;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37300;
-- Stormpike Quartermaster
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512 WHERE `entry` = 12096;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22658;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32099;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37420;
-- Frostwolf Quartermaster
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512 WHERE `entry` = 12097;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22648;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31986;
UPDATE `creature_template` SET `npcflag` = `npcflag` |2048|1024|512, `minlevel` = 75, `maxlevel` = 75, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37305;
-- Drakan
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.14286, `BaseAttackTime` = 2000 WHERE `entry` = 12121;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22540;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31964;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37282;
-- Duros
-- 12122
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22546;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31970;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37289;
-- Stormpike Guardsman
-- 12127
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22666;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32094;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37415;
-- Winterax Axe Thrower (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 59, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 12156;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22788;
-- Winterax Shadow Hunter (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 12157;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22792;
-- Winterax Hunter (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 12158;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22789;
-- Korrak the Bloodrager (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 12159;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 22643;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 32027;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37347;
-- Umi Thorson
-- 13078
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22696;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32119;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37442;
-- Keetar
UPDATE `creature_template` SET `npcflag` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 13079;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22683;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `speed_walk` = 1 WHERE `entry` = 32026;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37346;
-- Irondeep Guard
-- 13080
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22743;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32014;
UPDATE `creature_template` SET `minlevel` = 74, `maxlevel` = 75, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37333;
-- Irondeep Raider
UPDATE `creature_template` SET `npcflag` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 13081;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22746;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `speed_walk` = 1 WHERE `entry` = 32017;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0 WHERE `entry` = 37336;
-- Aggi Rumblestomp (4xx sniffs only) (expansion 0?)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13086;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22670;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 31918;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37234;
-- Coldmine Invader (4xx sniffs only, without level)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13087;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22731;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31948;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37266;
-- Masha Swiftcut (not sniffed)
UPDATE `creature_template` SET `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13088;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22684;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0 WHERE `entry` = 32043;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37364;
-- Coldmine Guard
UPDATE `creature_template` SET `npcflag` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 13089;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 22730;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 31947;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 37265;
-- Coldmine Explorer (not sniffed)
-- 13096
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 22729;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31946;
UPDATE `creature_template` SET `minlevel` = 74, `maxlevel` = 75, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37264;
-- Coldmine Surveyor
UPDATE `creature_template` SET `npcflag` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 13097;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22734;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0 WHERE `entry` = 31951;
UPDATE `creature_template` SET `minlevel` = 74, `maxlevel` = 75, `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37269;
-- Irondeep Surveyor (not sniffed)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13098;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22749;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32020;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37339;
-- Irondeep Explorer
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 13099;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22741;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32012;
UPDATE `creature_template` SET `minlevel` = 74, `maxlevel` = 75, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37331;
-- Alliance Spirit Guide
-- 13116
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 22526;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31920;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 37236;
-- Horde Spirit Guide
-- 13117
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 22558;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32004;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 37323;
-- Lieutenant Rugba (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13137;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22707;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32038;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37358;
-- Lieutenant Spencer (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13138;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22708;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32039;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37359;
-- Commander Randolph (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13139;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22620;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31959;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37277;
-- Commander Dardosh <old> (removed in 2.3.0, re-added in 8.1.5)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13140;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22613;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31952;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37270;
-- Lieutenant Stronghoof (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13143;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22710;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32041;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37361;
-- Lieutenant Vol'talar (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13144;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22711;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32042;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37362;
-- Lieutenant Grummus (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13145;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22701;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32031;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37351;
-- Lieutenant Murp <old> (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13146;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22706;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32037;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37357;
-- Lieutenant Lewis (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13147;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22703;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32034;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37354;
-- Syndicate Brigand (removed in 1.8.0)
UPDATE `creature_template` SET `minlevel` = 55, `maxlevel` = 56, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13149;
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22769;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 76, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 32108;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 76, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37429;
-- Syndicate Agent (removed in 1.8.0)
UPDATE `creature_template` SET `minlevel` = 57, `maxlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13150;
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22768;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 78, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 32107;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 78, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37428;
-- Syndicate Master Ryson (removed in 1.8.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13151;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22578;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 32109;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37430;
-- Commander Malgor (removed in 2.3.0, re-added in 8.1.5)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13152;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22617;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31956;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37274;
-- Commander Mulfort (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13153;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22619;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31958;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37276;
-- Commander Louis Philips (removed in 2.3.0, re-added in 8.1.5)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13154;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22616;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31955;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37273;
-- Deathstalker Agent (never used)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13155;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22539;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 31962;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37280;
-- Aerie Gryphon (not sniffed)
UPDATE `creature_template` SET `minlevel` = 50, `maxlevel` = 50, `unit_flags` = 512 WHERE `entry` = 13161;
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `unit_flags` = 512 WHERE `entry` = 22525;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `unit_flags` = 512 WHERE `entry` = 31917;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `unit_flags` = 512 WHERE `entry` = 37233;
-- Smith Regzar
-- 13176
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22571;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32080;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37401;
-- War Rider (not sniffed)
UPDATE `creature_template` SET `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 13178;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22594;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 32138;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 37466;
-- Wing Commander Guse
-- 13179
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22721;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31828;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |256|64 WHERE `entry` = 37479;
-- Wing Commander Jeztor
UPDATE `creature_template` SET `npcflag` = 3, `unit_flags` = `unit_flags` |512|256 WHERE `entry` = 13180;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 3, `speed_walk` = 1, `unit_flags` = `unit_flags` |512|256 WHERE `entry` = 22697;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 3, `speed_walk` = 1, `unit_flags` = `unit_flags` |512|256 WHERE `entry` = 31826;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `npcflag` = 3, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |512|256|64 WHERE `entry` = 37481;
-- Wing Commander Mulverick
-- 13181
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22598;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31825;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = `unit_flags` |512|256|64 WHERE `entry` = 37482;
-- Gaelden Hammersmith
-- 13216
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22680;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31996;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37315;
-- Thanthaldis Snowgleam (not sniffed(spawned outside only))
-- 13217
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22695;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 32112;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37433;
-- Grunnda Wolfheart
-- 13218
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22681;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32001;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37320;
-- Jekyll Flandring (not sniffed(spawned outside only))
-- 13219
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22682;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 32022;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37342;
-- Ryson's Eye in the Sky (removed in 1.8.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 768 WHERE `entry` = 13221;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 768 WHERE `entry` = 22686;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `unit_flags` = 768 WHERE `entry` = 32056;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `unit_flags` = 768 WHERE `entry` = 37377;
-- Primalist Thurloga
-- 13236;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 2 WHERE `entry` = 22568;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `speed_run` = 2 WHERE `entry` = 32050;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37371;
-- Lokholar the Ice Lord (not sniffed)
UPDATE `creature_template` SET `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 13256;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22629;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 31822;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 37363;
-- Murgot Deepforge
-- 13257
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22567;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32048;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37369;
-- Furis (something unused / someone's mount)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1, `unit_flags` = 768 WHERE `entry` = 13281;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `unit_flags` = 768 WHERE `entry` = 22553;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 768 WHERE `entry` = 31995;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 768 WHERE `entry` = 37314;
-- Frostwolf Shaman
-- 13284
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22678;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31989;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37308;
-- Lieutenant Largent (removed in 2.3.0)
UPDATE `creature_template` SET `exp` = 0, `speed_walk` = 1 WHERE `entry` = 13296;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22702;
-- Lieutenant Stouthandle (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13297;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22709;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32040;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37360;
-- Lieutenant Greywand (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13298;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22700;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32030;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37350;
-- Lieutenant Lonadin (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13299;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22704;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32035;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37355;
-- Lieutenant Mancuso (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13300;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22705;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32036;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37356;
-- Coldmine Peon (not sniffed)
UPDATE `creature_template` SET `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13316;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22733;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0 WHERE `entry` = 31950;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37268;
-- Coldmine Miner (4xx sniffs only)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13317;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22732;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31949;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37267;
-- Commander Mortimer (removed in 2.3.0, re-added in 8.1.5)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13318;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22618;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31957;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37275;
-- Commander Duffy (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13319;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22614;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31953;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37271;
-- Commander Karl Philips (removed in 2.3.0, re-added in 8.1.5)
UPDATE `creature_template` SET `exp` = 0, `speed_walk` = 1 WHERE `entry` = 13320;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22615;
-- Seasoned Guardsman (not sniffed) > Stormpike Guardsman
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13324;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22687;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32064;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37385;
-- Seasoned Mountaineer (not sniffed) > Stormpike Mountaineer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13325;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22662;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 32070;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 37391;
-- Seasoned Defender > Stormpike Defender
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 13326;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22714;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32062;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37383;
-- Seasoned Sentinel (not sniffed) > Alliance Sentinel (no longer used)
UPDATE `creature_template` SET `minlevel` = 56, `maxlevel` = 56, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13327;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22663;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 32074;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 37395;
-- Seasoned Guardian (not sniffed) > Frostwolf Guardian
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13328;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22715;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32063;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37384;
-- Seasoned Legionnaire (not sniffed) > Frostwolf Legionnaire
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13329;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22688;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32069;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37390;
-- Seasoned Warrior (not sniffed) > Frostwolf Warrior
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13330;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22664;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 32075;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76, `exp` = 1 WHERE `entry` = 37396;
-- Veteran Defender (not sniffed) > Stormpike Defender
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13331;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22588;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32125;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37450;
-- Veteran Guardian (not sniffed) > Frostwolf Guardian
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13332;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22589;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32126;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37451;
-- Veteran Guardsman (not sniffed) > Stormpike Guardsman
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13333;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22719;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32127;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37452;
-- Veteran Legionnaire (not sniffed) > Frostwolf Legionnaire
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13334;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22720;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32132;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37457;
-- Veteran Mountaineer (not sniffed) > Stormpike Mountaineer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13335;
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22667;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 32133;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 37458;
-- Veteran Sentinel (not sniffed) > Alliance Sentinel (no longer used)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13336;
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22668;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 32134;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 37462;
-- Veteran Warrior (not sniffed) > Frostwolf Warrior
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13337;
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22669;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 32135;
UPDATE `creature_template` SET `minlevel` = 77, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 37463;
-- Stormpike Mine Layer (removed in 1.8.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13356;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22635;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32096;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37417;
-- Frostwolf Mine Layer (removed in 1.8.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13357;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22624;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 31984;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37303;
-- Stormpike Bowman
-- 13358
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22766;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32089;
UPDATE `creature_template` SET `minlevel` = 79, `exp` = 1 WHERE `entry` = 37410;
-- Frostwolf Bowman
-- 13359
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22739;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31978;
UPDATE `creature_template` SET `minlevel` = 79, `exp` = 1 WHERE `entry` = 37297;
-- Master Engineer Zinfizzlex (removed in 1.10.0, re-added in 8.1.5)
UPDATE `creature_template` SET `npcflag` = 3, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 768 WHERE `entry` = 13377;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `npcflag` = 3, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 768 WHERE `entry` = 22565;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 3, `unit_flags` = 768 WHERE `entry` = 32044;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 3, `unit_flags` = 768 WHERE `entry` = 37365;
-- Frostwolf Shredder Unit (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13378;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22550;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 31990;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 37309;
-- Irondeep Miner
-- 13396
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 0.666668 WHERE `entry` = 22744;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 0.666668 WHERE `entry` = 32015;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `speed_walk` = 0.666668, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37334;
-- Irondeep Peon
UPDATE `creature_template` SET `npcflag` = 0, `RangeAttackTime` = 2000 WHERE `entry` = 13397;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22745;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0 WHERE `entry` = 32016;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 73, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37335;
-- Stormpike Shredder Unit (removed in 1.10.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13416;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22576;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 32104;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 37425;
-- Ivus the Forest Lord (not sniffed)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 13419;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22627;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 512 WHERE `entry` = 31821;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37341;
-- Champion Guardian (not sniffed) > Frostwolf Guardian
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13421;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22609;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31933;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37251;
-- Champion Defender (not sniffed) > Stormpike Defender
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13422;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22608;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31932;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37250;
-- Champion Guardsman (not sniffed) > Stormpike Guardsman
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13424;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22533;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31934;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37252;
-- Champion Legionnaire (not sniffed) > Frostwolf Legionnaire
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13425;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22538;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31939;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37257;
-- Champion Mountaineer (not sniffed) > Stormpike Mountaineer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13426;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22671;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31940;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37258;
-- Champion Sentinel (not sniffed) > Alliance Sentinel (no longer used)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13427;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22672;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31944;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37262;
-- Champion Warrior (not sniffed) > Frostwolf Warrior
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13428;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22673;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31945;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37263;
-- Wing Commander Ichman
UPDATE `creature_template` SET `gossip_menu_id` = 5146 WHERE `entry` = 13437;
UPDATE `creature_template` SET `gossip_menu_id` = 5146, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22597;
UPDATE `creature_template` SET `gossip_menu_id` = 5146, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32766;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37480;
-- Wing Commander Slidore
UPDATE `creature_template` SET `unit_flags` = `unit_flags`|512|256|64 WHERE `entry` = 13438;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `unit_flags` = `unit_flags`|512|256|64 WHERE `entry` = 22698;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `unit_flags` = `unit_flags`|512|256|64 WHERE `entry` = 31824;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags`|512|256|64 WHERE `entry` = 37483;
-- Wing Commander Vipore
UPDATE `creature_template` SET `gossip_menu_id` = 5147 WHERE `entry` = 13439;
UPDATE `creature_template` SET `gossip_menu_id` = 5147, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22722;
UPDATE `creature_template` SET `gossip_menu_id` = 5147, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31823;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags`|256|64 WHERE `entry` = 37484;
-- Frostwolf Wolf Rider (not sniffed)(spawns only after specific event?)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13440;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22679;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31993;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37312;
-- Frostwolf Wolf Rider Commander (not sniffed)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13441;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22552;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31994;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37313;
-- Arch Druid Renferal
-- 13442
UPDATE `creature_template` SET `gossip_menu_id` = 5142, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22527;
UPDATE `creature_template` SET `gossip_menu_id` = 5142, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31923;
UPDATE `creature_template` SET `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37239;
-- Druid of the Grove
-- 13443
UPDATE `creature_template` SET `gossip_menu_id` = 5141, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22541;
UPDATE `creature_template` SET `gossip_menu_id` = 5141, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31965;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37284;
-- Field Marshal Teravaine (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13446;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22621;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 31973;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37292;
-- Corporal Noreg Stormpike
-- 13447
UPDATE `creature_template` SET `gossip_menu_id` = 5081, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22735;
UPDATE `creature_template` SET `gossip_menu_id` = 5081, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31960;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37278;
-- Sergeant Yazra Bloodsnarl
-- 13448
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22760;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32077;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37398;
-- Warmaster Garrick (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13449;
UPDATE `creature_template` SET `minlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22639;
-- Risen Ancient (looks unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1 WHERE `entry` = 13496;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22632;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32055;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37376;
-- Frostwolf Outrunner (looks unused)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1 WHERE `entry` = 13516;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22675;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31985;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37304;
-- Seasoned Outrunner > Frostwolf Outrunner (looks unused)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13517;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22716;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32071;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37392;
-- Veteran Outrunner > Frostwolf Outrunner (looks unused) (exp looks incorrect)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13518;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22590;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 31906;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37459;
-- Champion Outrunner > Frostwolf Outrunner (looks unused)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13519;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22610;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 31941;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37259;
-- Stormpike Ranger (looks unused)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1 WHERE `entry` = 13520;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22692;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 32102;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37423;
-- Seasoned Ranger > Stormpike Ranger (looks unused)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13521;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22717;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32072;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37393;
-- Veteran Ranger > Stormpike Ranger (looks unused) (exp looks incorrect)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 13522;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22591;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 31905;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37460;
-- Champion Ranger > Stormpike Ranger (looks unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1 WHERE `entry` = 13523;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22611;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 31942;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37260;
-- Stormpike Commando (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13524;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22689;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 32090;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37411;
-- Seasoned Commando > Stormpike Commando (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13525;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22713;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 32061;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 37382;
-- Veteran Commando (exp looks incorrect) > Stormpike Commando (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13526;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22587;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2 WHERE `entry` = 31907;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2 WHERE `entry` = 37449;
-- Champion Commando > Stormpike Commando (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13527;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22607;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 31931;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37249;
-- Frostwolf Reaver (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13528;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22676;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31987;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37306;
-- Seasoned Reaver > Frostwolf Reaver (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13529;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22718;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 32073;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 37394;
-- Veteran Reaver (exp looks incorrect) > Frostwolf Reaver (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13530;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22592;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 31904;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37461;
-- Champion Reaver > Frostwolf Reaver (not sniffed, spawns after specific event)
UPDATE `creature_template` SET `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13531;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `npcflag` = 0, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22612;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `npcflag` = 0 WHERE `entry` = 31943;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37261;
-- Seasoned Coldmine Guard > Coldmine Guard
UPDATE `creature_template` SET `npcflag` = 0, `BaseAttackTime` = 2800, `RangeAttackTime` = 2000 WHERE `entry` = 13534;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 22752;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 32058;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 37379;
-- Veteran Coldmine Guard > Coldmine Guard
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800, `RangeAttackTime` = 2000 WHERE `entry` = 13535;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 22771;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 32122;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 37446;
-- Champion Coldmine Guard > Coldmine Guard
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800, `RangeAttackTime` = 2000 WHERE `entry` = 13536;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 22530;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 31928;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0, `BaseAttackTime` = 2800 WHERE `entry` = 37246;
-- Seasoned Coldmine Surveyor > Coldmine Surveyor
UPDATE `creature_template` SET `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13537;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22754;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1, `npcflag` = 0 WHERE `entry` = 32060;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37381;
-- Veteran Coldmine Surveyor > Coldmine Surveyor
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13538;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22773;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `npcflag` = 0 WHERE `entry` = 32124;
UPDATE `creature_template` SET `exp` = 1, `npcflag` = 0 WHERE `entry` = 37448;
-- Champion Coldmine Surveyor > Coldmine Surveyor
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13539;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22532;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 31930;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37248;
-- Seasoned Irondeep Explorer > Irondeep Explorer
UPDATE `creature_template` SET `minlevel` = 56, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13540;
UPDATE `creature_template` SET `minlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22755;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32065;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1 WHERE `entry` = 37386;
-- Veteran Irondeep Explorer > Irondeep Explorer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13541;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22774;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 32128;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 37453;
-- Champion Irondeep Explorer > Irondeep Explorer
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13542;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22534;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 31935;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37253;
-- Seasoned Irondeep Raider > Irondeep Raider
UPDATE `creature_template` SET `minlevel` = 56, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13543;
UPDATE `creature_template` SET `minlevel` = 66, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22757;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32067;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1 WHERE `entry` = 37388;
-- Veteran Irondeep Raider > Irondeep Raider
UPDATE `creature_template` SET `minlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13544;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22776;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1 WHERE `entry` = 32130;
UPDATE `creature_template` SET `minlevel` = 78, `exp` = 1 WHERE `entry` = 37455;
-- Champion Irondeep Raider > Irondeep Raider
UPDATE `creature_template` SET `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13545;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `npcflag` = 0, `BaseAttackTime` = 2000 WHERE `entry` = 22536;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 31937;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `npcflag` = 0 WHERE `entry` = 37255;
-- Seasoned Coldmine Explorer > Coldmine Explorer
UPDATE `creature_template` SET `minlevel` = 56 WHERE `entry` = 13546;
UPDATE `creature_template` SET `minlevel` = 66, `exp` = 1 WHERE `entry` = 22751;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1 WHERE `entry` = 32057;
UPDATE `creature_template` SET `minlevel` = 76, `exp` = 1 WHERE `entry` = 37378;
-- Veteran Coldmine Explorer > Coldmine Explorer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13547;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22770;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32121;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37445;
-- Champion Coldmine Explorer > Coldmine Explorer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13548;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22529;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31927;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37245;
-- Seasoned Coldmine Invader > Coldmine Invader
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13549;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22753;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32059;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37380;
-- Veteran Coldmine Invader > Coldmine Invader
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13550;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22772;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32123;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37447;
-- Champion Coldmine Invader > Coldmine Invader
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13551;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22531;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31929;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37247;
-- Seasoned Irondeep Guard > Irondeep Guard
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13552;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22756;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32066;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37387;
-- Veteran Irondeep Guard > Irondeep Guard
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13553;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22775;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32129;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37454;
-- Champion Irondeep Guard > Irondeep Guard
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13554;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22535;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 31936;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 37254;
-- Seasoned Irondeep Surveyor > Irondeep Surveyor
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13555;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22758;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32068;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37389;
-- Veteran Irondeep Surveyor > Irondeep Surveyor
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13556;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22777;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32131;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37456;
-- Champion Irondeep Surveyor > Irondeep Surveyor
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13557;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22537;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 31938;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1 WHERE `entry` = 37256;
-- Stormpike Ram Rider (not sniffed)(spawns only after specific event?)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13576;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22691;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 32100;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37421;
-- Stormpike Ram Rider Commander
-- 13577
UPDATE `creature_template` SET `gossip_menu_id` = 5281, `exp` = 1, `speed_walk` = 1, `speed_run` = 1.38571 WHERE `entry` = 22575;
UPDATE `creature_template` SET `gossip_menu_id` = 5281, `exp` = 1, `speed_walk` = 1, `speed_run` = 1.38571 WHERE `entry` = 32101;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37422;
-- Frostwolf Explosives Expert (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13597;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22623;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 31980;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37299;
-- Stormpike Explosives Expert (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13598;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22634;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32093;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37414;
-- Frostwolf Stable Master (not sniffed)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13616;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22551;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31991;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37310;
-- Stormpike Stable Master
-- 13617
UPDATE `creature_template` SET /*`gossip_menu_id` = 5283,*/ `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22577;
UPDATE `creature_template` SET /*`gossip_menu_id` = 5283,*/ `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32105;
UPDATE `creature_template` SET /*`gossip_menu_id` = 5283,*/ `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37426;
-- Stabled Frostwolf (not sniffed)
UPDATE `creature_template` SET `difficulty_entry_2` = 32085, `difficulty_entry_3` = 37406, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13618;
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 61, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22765;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `exp` = 1, `faction` = 1214 WHERE `entry` = 32085;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `exp` = 1, `faction` = 1214 WHERE `entry` = 37406;
-- Stabled Alterac Ram (not sniffed)
UPDATE `creature_template` SET `difficulty_entry_2` = 32084, `difficulty_entry_3` = 37405, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13676;
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 61, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22764;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `exp` = 1, `faction` = 1217 WHERE `entry` = 32084;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 71, `exp` = 1, `faction` = 1217 WHERE `entry` = 37405;
-- Corporal Teeka Bloodsnarl (not sniffed, spawned outside)
-- 13776
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22736;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 31961;
UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 77, `exp` = 1 WHERE `entry` = 37279;
-- Sergeant Durgen Stormpike (not sniffed, spawned outside)
UPDATE `creature_template` SET `difficulty_entry_2` = 32076, `difficulty_entry_3` = 37397 WHERE `entry` = 13777;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22759;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1, `faction` = 1216 WHERE `entry` = 32076;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 79, `exp` = 1, `faction` = 1216 WHERE `entry` = 37397;
-- Mountaineer Boombellow
UPDATE `creature_template` SET `maxlevel` = 61, `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 13797;
UPDATE `creature_template` SET `minlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 22724;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `unit_flags` = 64 WHERE `entry` = 32046;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 37367;
-- Jotek
-- 13798
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22723;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32025;
UPDATE `creature_template` SET `minlevel` = 80, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` |64 WHERE `entry` = 37345;
-- Prospector Stonehewer
-- 13816
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22630;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32051;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37372;
-- Voggah Deathgrip (not sniffed, spawned outside)
-- 13817
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22638;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32137;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37465;
-- Warmaster Laggrond (not sniffed, spawned outside)
-- 13840
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22640;
-- Lieutenant Haggerdin (not sniffed, spawned outside)
-- 13841
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22628;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32032;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37352;
-- Winterax Mystic (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 57, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13956;
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22790;
-- Winterax Warrior (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 59, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13957;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22795;
-- Winterax Seer (removed in 1.10.0)
UPDATE `creature_template` SET `minlevel` = 58, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 13958;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22791;
-- Alterac Yeti (not sniffed)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 13959;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 22604;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31922;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37238;
-- Gash'nak the Cannibal (unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 13977;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 22625;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 31998;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37317;
-- Ushalac the Gloomdweller (unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 14016;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 22637;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 32120;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37443;
-- Withered Troll (unused)
UPDATE `creature_template` SET `minlevel` = 59, `maxlevel` = 60, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 14017;
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 22797;
-- Rezrelek (unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 14018;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 22631;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 32054;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1, `unit_flags` = 32768 WHERE `entry` = 37375;
-- Tatterhide (unused)
UPDATE `creature_template` SET `minlevel` = 61, `maxlevel` = 61, `speed_walk` = 1 WHERE `entry` = 14019;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22636;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 32111;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `exp` = 1 WHERE `entry` = 37432;
-- Winterax Sentry (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33554432+512+256 WHERE `entry` = 14021;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 33554432+512+256 WHERE `entry` = 22599;
-- Trigger Guse
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14026;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22581;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32113;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37436;
-- Trigger Mulverick
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14027;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22584;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32116;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37439;
-- Trigger Jeztor
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14028;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22583;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32115;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37438;
-- Trigger Ichman
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14029;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22582;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32114;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37437;
-- Trigger Slidore
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14030;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22585;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32117;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37440;
-- Trigger Vipore
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `exp` = 0 WHERE `entry` = 14031;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22586;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 32118;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `unit_flags` = 33555264 WHERE `entry` = 37441;
-- Stormpike Reclaimer (unused)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1 WHERE `entry` = 14141;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22693;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 32103;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37424;
-- Frostwolf Reclaimer (unused)
UPDATE `creature_template` SET `minlevel` = 58, `maxlevel` = 58, `speed_walk` = 1 WHERE `entry` = 14142;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 68, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22677;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 31988;
UPDATE `creature_template` SET `minlevel` = 78, `maxlevel` = 78, `exp` = 1 WHERE `entry` = 37307;
-- Najak Hexxen
-- 14185
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22712;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32049;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37370;
-- Ravak Grimtotem
-- 14186
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22569;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32053;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 37374;
-- Athramanis
-- 14187
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22528;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31924;
UPDATE `creature_template` SET `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37240;
-- Dirk Swindle
-- 14188
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22699;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31963;
UPDATE `creature_template` SET `minlevel` = 79, `maxlevel` = 79, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37281;
-- Winterax Tracker (unused)
UPDATE `creature_template` SET `minlevel` = 56, `maxlevel` = 57, `speed_walk` = 1 WHERE `entry` = 14274;
UPDATE `creature_template` SET `minlevel` = 66, `maxlevel` = 67, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22793;
-- Frostwolf Bloodhound
-- 14282
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22738;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31977;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 74, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37296;
-- Stormpike Owl
-- 14283
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22767;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32098;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 74, `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37419;
-- Stormpike Battleguard
-- 14284
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22633;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 32088;
UPDATE `creature_template` SET `exp` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37409;
-- Frostwolf Battleguard (not sniffed)
-- 14285
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22622;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 31976;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = `unit_flags` |512 WHERE `entry` = 37295;
-- [PH] Alliance Herald (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1 WHERE `entry` = 14643;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22600;
-- [PH] Horde Herald (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1 WHERE `entry` = 14644;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22602;
-- [PH] Alliance Tower Lieutenant (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1 WHERE `entry` = 14719;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22601;
-- [PH] Horde Tower Lieutenant (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1 WHERE `entry` = 14746;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22603;
-- Dun Baldar North Marshal
-- 14762
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22542;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31966;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37285;
-- Dun Baldar South Marshal
-- 14763
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22544;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31968;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 37287;
-- Icewing Marshal
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 14764;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22561;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 32008;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 37327;
-- Stonehearth Marshal
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 14765;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22572;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 32086;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 37407;
-- Iceblood Marshal (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 14766;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` = 22559;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 32006;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 37325;
-- Tower Point Marshal (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 14767;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22579;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 31908;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 37434;
-- East Frostwolf Marshal (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 14768;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 22547;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 31971;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 37290;
-- West Frostwolf Marshal (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 14769;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22595;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 31903;
UPDATE `creature_template` SET `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 37467;
-- Dun Baldar North Warmaster (removed in 2.3.0)
UPDATE `creature_template` SET `difficulty_entry_2` = 31967, `difficulty_entry_3` = 37286, `speed_walk` = 1 WHERE `entry` = 14770;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22543;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `faction` = 1214 WHERE `entry` = 31967;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `faction` = 1214 WHERE `entry` = 37286;
-- Dun Baldar South Warmaster (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 14771;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22545;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 31969;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37288;
-- East Frostwolf Warmaster
-- 14772
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22548;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31972;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80 WHERE `entry` = 37291;
-- Iceblood Warmaster
-- 14773
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22560;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 32007;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80 WHERE `entry` = 37326;
-- Icewing Warmaster (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 14774;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22562;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 32009;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37328;
-- Stonehearth Warmaster (removed in 2.3.0)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 14775;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22573;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 32087;
UPDATE `creature_template` SET `exp` = 2 WHERE `entry` = 37408;
-- Tower Point Warmaster
-- 14776
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22580;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31909;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80 WHERE `entry` = 37435;
-- West Frostwolf Warmaster
-- 14777
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22596;
UPDATE `creature_template` SET `exp` = 2, `speed_walk` = 1 WHERE `entry` = 31829;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80 WHERE `entry` = 37468;
-- Herald
UPDATE `creature_equip_template` SET `ItemID1` = 2714, `VerifiedBuild` = 12340 WHERE `CreatureID` = 14848;
UPDATE `creature_template` SET `exp` = 1 WHERE `entry` = 22557;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = `unit_flags` |33555200 WHERE `entry` = 32003;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = `unit_flags` |33555200 WHERE `entry` = 37322;
-- Guse's War Rider (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14943;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22556;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 32002;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37321;
-- Jeztor's War Rider (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14944;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22564;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 32023;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37343;
-- Mulverick's War Rider (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `difficulty_entry_2` = 32047, `difficulty_entry_3` = 37368, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14945;
UPDATE `creature_template` SET `minlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22566;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `faction` = 1214, `unit_flags` = 512 WHERE `entry` = 32047;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `faction` = 1214, `unit_flags` = 512 WHERE `entry` = 37368;
-- Slidore's Gryphon (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `difficulty_entry_2` = 32079, `difficulty_entry_3` = 37400, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14946;
UPDATE `creature_template` SET `minlevel` = 70, `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22570;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `faction` = 1216, `unit_flags` = 512 WHERE `entry` = 32079;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `faction` = 1216, `unit_flags` = 512 WHERE `entry` = 37400;
-- Ichman's Gryphon (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14947;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22563;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 32010;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37329;
-- Vipore's Gryphon (not sniffed, spawns only after specific event)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 14948;
UPDATE `creature_template` SET `exp` = 1, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 22593;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 32136;
UPDATE `creature_template` SET `exp` = 1, `unit_flags` = 512 WHERE `entry` = 37464;
-- Stormpike Emissary (spawns outside only)
-- 15103
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22656;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 32092;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 37413;
-- Frostwolf Emissary (spawns outside only)
-- 15106
UPDATE `creature_template` SET `minlevel` = 65, `maxlevel` = 65, `exp` = 1, `speed_walk` = 1 WHERE `entry` = 22647;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 31979;
UPDATE `creature_template` SET `minlevel` = 75, `maxlevel` = 75, `exp` = 1 WHERE `entry` = 37298;
-- Gahz'ranka Herald (unused)
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1, `unit_flags` = 33554432+512+256 WHERE `entry` = 15139;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `exp` = 1, `speed_walk` = 1, `unit_flags` = 33554432+512+256 WHERE `entry` = 22554;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 33554432+512+256 WHERE `entry` = 31997;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 1, `unit_flags` = 33554432+512+256 WHERE `entry` = 37316;
