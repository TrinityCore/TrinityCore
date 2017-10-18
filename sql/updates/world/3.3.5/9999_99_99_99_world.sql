-- Adds damage to pet_levelstats and fills it with correct damage and stats for every level for every pet

ALTER TABLE `pet_levelstats`
  ADD COLUMN `min_dmg` smallint(5) UNSIGNED NOT NULL default 0 AFTER `spi`,
  ADD COLUMN `max_dmg` smallint(5) UNSIGNED NOT NULL default 0 AFTER `min_dmg`;

-- IMP
UPDATE `pet_levelstats` SET `str`= 20, `agi`= 20, `sta`= 20, `inte`= 24, `spi`= 23, `armor`=   20, `min_dmg`=  1, `max_dmg`=  2 WHERE `creature_entry`= 416 AND `level`= 1;
UPDATE `pet_levelstats` SET `str`= 21, `agi`= 20, `sta`= 20, `inte`= 25, `spi`= 24, `armor`=   24, `min_dmg`=  2, `max_dmg`=  3 WHERE `creature_entry`= 416 AND `level`= 2;
UPDATE `pet_levelstats` SET `str`= 22, `agi`= 20, `sta`= 21, `inte`= 26, `spi`= 25, `armor`=   28, `min_dmg`=  3, `max_dmg`=  5 WHERE `creature_entry`= 416 AND `level`= 3;
UPDATE `pet_levelstats` SET `str`= 23, `agi`= 21, `sta`= 21, `inte`= 27, `spi`= 26, `armor`=   33, `min_dmg`=  4, `max_dmg`=  6 WHERE `creature_entry`= 416 AND `level`= 4;
UPDATE `pet_levelstats` SET `str`= 23, `agi`= 21, `sta`= 22, `inte`= 28, `spi`= 27, `armor`=   49, `min_dmg`=  5, `max_dmg`=  8 WHERE `creature_entry`= 416 AND `level`= 5;
UPDATE `pet_levelstats` SET `str`= 24, `agi`= 21, `sta`= 22, `inte`= 29, `spi`= 27, `armor`=   68, `min_dmg`=  6, `max_dmg`=  9 WHERE `creature_entry`= 416 AND `level`= 6;
UPDATE `pet_levelstats` SET `str`= 25, `agi`= 21, `sta`= 23, `inte`= 30, `spi`= 28, `armor`=   92, `min_dmg`=  7, `max_dmg`= 12 WHERE `creature_entry`= 416 AND `level`= 7;
UPDATE `pet_levelstats` SET `str`= 26, `agi`= 21, `sta`= 23, `inte`= 31, `spi`= 29, `armor`=  117, `min_dmg`=  8, `max_dmg`= 13 WHERE `creature_entry`= 416 AND `level`= 8;
UPDATE `pet_levelstats` SET `str`= 27, `agi`= 21, `sta`= 23, `inte`= 32, `spi`= 30, `armor`=  147, `min_dmg`=  9, `max_dmg`= 14 WHERE `creature_entry`= 416 AND `level`= 9;
UPDATE `pet_levelstats` SET `str`= 27, `agi`= 22, `sta`= 24, `inte`= 33, `spi`= 31, `armor`=  180, `min_dmg`=  9, `max_dmg`= 15 WHERE `creature_entry`= 416 AND `level`=10;
UPDATE `pet_levelstats` SET `str`= 28, `agi`= 22, `sta`= 24, `inte`= 37, `spi`= 35, `armor`=  190, `min_dmg`= 10, `max_dmg`= 16 WHERE `creature_entry`= 416 AND `level`=11;
UPDATE `pet_levelstats` SET `str`= 29, `agi`= 22, `sta`= 26, `inte`= 41, `spi`= 39, `armor`=  203, `min_dmg`= 11, `max_dmg`= 17 WHERE `creature_entry`= 416 AND `level`=12;
UPDATE `pet_levelstats` SET `str`= 30, `agi`= 22, `sta`= 26, `inte`= 44, `spi`= 43, `armor`=  215, `min_dmg`= 11, `max_dmg`= 18 WHERE `creature_entry`= 416 AND `level`=13;
UPDATE `pet_levelstats` SET `str`= 31, `agi`= 22, `sta`= 28, `inte`= 50, `spi`= 47, `armor`=  228, `min_dmg`= 11, `max_dmg`= 19 WHERE `creature_entry`= 416 AND `level`=14;
UPDATE `pet_levelstats` SET `str`= 32, `agi`= 23, `sta`= 29, `inte`= 54, `spi`= 52, `armor`=  240, `min_dmg`= 12, `max_dmg`= 20 WHERE `creature_entry`= 416 AND `level`=15;
UPDATE `pet_levelstats` SET `str`= 34, `agi`= 23, `sta`= 30, `inte`= 57, `spi`= 56, `armor`=  253, `min_dmg`= 13, `max_dmg`= 21 WHERE `creature_entry`= 416 AND `level`=16;
UPDATE `pet_levelstats` SET `str`= 36, `agi`= 23, `sta`= 31, `inte`= 61, `spi`= 60, `armor`=  265, `min_dmg`= 14, `max_dmg`= 22 WHERE `creature_entry`= 416 AND `level`=17;
UPDATE `pet_levelstats` SET `str`= 37, `agi`= 23, `sta`= 32, `inte`= 65, `spi`= 65, `armor`=  278, `min_dmg`= 15, `max_dmg`= 24 WHERE `creature_entry`= 416 AND `level`=18;
UPDATE `pet_levelstats` SET `str`= 38, `agi`= 23, `sta`= 33, `inte`= 70, `spi`= 69, `armor`=  291, `min_dmg`= 15, `max_dmg`= 25 WHERE `creature_entry`= 416 AND `level`=19;
UPDATE `pet_levelstats` SET `str`= 40, `agi`= 24, `sta`= 35, `inte`= 74, `spi`= 74, `armor`=  303, `min_dmg`= 16, `max_dmg`= 26 WHERE `creature_entry`= 416 AND `level`=20;
UPDATE `pet_levelstats` SET `str`= 42, `agi`= 24, `sta`= 44, `inte`= 87, `spi`= 64, `armor`=  320, `min_dmg`= 17, `max_dmg`= 27 WHERE `creature_entry`= 416 AND `level`=21;
UPDATE `pet_levelstats` SET `str`= 44, `agi`= 24, `sta`= 46, `inte`= 91, `spi`= 67, `armor`=  346, `min_dmg`= 18, `max_dmg`= 28 WHERE `creature_entry`= 416 AND `level`=22;
UPDATE `pet_levelstats` SET `str`= 45, `agi`= 24, `sta`= 47, `inte`= 95, `spi`= 69, `armor`=  360, `min_dmg`= 18, `max_dmg`= 29 WHERE `creature_entry`= 416 AND `level`=23;
UPDATE `pet_levelstats` SET `str`= 46, `agi`= 25, `sta`= 49, `inte`= 99, `spi`= 73, `armor`=  373, `min_dmg`= 19, `max_dmg`= 30 WHERE `creature_entry`= 416 AND `level`=24;
UPDATE `pet_levelstats` SET `str`= 47, `agi`= 25, `sta`= 50, `inte`=104, `spi`= 75, `armor`=  386, `min_dmg`= 20, `max_dmg`= 31 WHERE `creature_entry`= 416 AND `level`=25;
UPDATE `pet_levelstats` SET `str`= 49, `agi`= 25, `sta`= 51, `inte`=107, `spi`= 78, `armor`=  399, `min_dmg`= 21, `max_dmg`= 32 WHERE `creature_entry`= 416 AND `level`=26;
UPDATE `pet_levelstats` SET `str`= 50, `agi`= 25, `sta`= 53, `inte`=111, `spi`= 81, `armor`=  411, `min_dmg`= 22, `max_dmg`= 34 WHERE `creature_entry`= 416 AND `level`=27;
UPDATE `pet_levelstats` SET `str`= 52, `agi`= 25, `sta`= 54, `inte`=118, `spi`= 86, `armor`=  424, `min_dmg`= 22, `max_dmg`= 34 WHERE `creature_entry`= 416 AND `level`=28;
UPDATE `pet_levelstats` SET `str`= 54, `agi`= 26, `sta`= 56, `inte`=122, `spi`= 89, `armor`=  436, `min_dmg`= 23, `max_dmg`= 35 WHERE `creature_entry`= 416 AND `level`=29;
UPDATE `pet_levelstats` SET `str`= 54, `agi`= 26, `sta`= 57, `inte`=128, `spi`= 92, `armor`=  449, `min_dmg`= 24, `max_dmg`= 37 WHERE `creature_entry`= 416 AND `level`=30;
UPDATE `pet_levelstats` SET `str`= 56, `agi`= 26, `sta`= 59, `inte`=131, `spi`= 95, `armor`=  462, `min_dmg`= 24, `max_dmg`= 38 WHERE `creature_entry`= 416 AND `level`=31;
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 26, `sta`= 61, `inte`=136, `spi`= 98, `armor`=  476, `min_dmg`= 25, `max_dmg`= 39 WHERE `creature_entry`= 416 AND `level`=32;
UPDATE `pet_levelstats` SET `str`= 59, `agi`= 27, `sta`= 61, `inte`=139, `spi`=101, `armor`=  488, `min_dmg`= 25, `max_dmg`= 39 WHERE `creature_entry`= 416 AND `level`=33;
UPDATE `pet_levelstats` SET `str`= 60, `agi`= 27, `sta`= 63, `inte`=143, `spi`=104, `armor`=  501, `min_dmg`= 26, `max_dmg`= 40 WHERE `creature_entry`= 416 AND `level`=34;
UPDATE `pet_levelstats` SET `str`= 62, `agi`= 27, `sta`= 62, `inte`=145, `spi`=107, `armor`=  532, `min_dmg`= 27, `max_dmg`= 41 WHERE `creature_entry`= 416 AND `level`=35;
UPDATE `pet_levelstats` SET `str`= 64, `agi`= 27, `sta`= 62, `inte`=147, `spi`=110, `armor`=  564, `min_dmg`= 28, `max_dmg`= 43 WHERE `creature_entry`= 416 AND `level`=36;
UPDATE `pet_levelstats` SET `str`= 66, `agi`= 27, `sta`= 62, `inte`=149, `spi`=114, `armor`=  596, `min_dmg`= 29, `max_dmg`= 44 WHERE `creature_entry`= 416 AND `level`=37;
UPDATE `pet_levelstats` SET `str`= 68, `agi`= 28, `sta`= 62, `inte`=151, `spi`=117, `armor`=  628, `min_dmg`= 30, `max_dmg`= 46 WHERE `creature_entry`= 416 AND `level`=38;
UPDATE `pet_levelstats` SET `str`= 70, `agi`= 28, `sta`= 61, `inte`=153, `spi`=120, `armor`=  660, `min_dmg`= 31, `max_dmg`= 47 WHERE `creature_entry`= 416 AND `level`=39;
UPDATE `pet_levelstats` SET `str`= 72, `agi`= 28, `sta`= 61, `inte`=155, `spi`=124, `armor`=  692, `min_dmg`= 32, `max_dmg`= 49 WHERE `creature_entry`= 416 AND `level`=40;
UPDATE `pet_levelstats` SET `str`= 74, `agi`= 28, `sta`= 61, `inte`=157, `spi`=127, `armor`=  724, `min_dmg`= 33, `max_dmg`= 50 WHERE `creature_entry`= 416 AND `level`=41;
UPDATE `pet_levelstats` SET `str`= 77, `agi`= 29, `sta`= 61, `inte`=159, `spi`=131, `armor`=  756, `min_dmg`= 35, `max_dmg`= 52 WHERE `creature_entry`= 416 AND `level`=42;
UPDATE `pet_levelstats` SET `str`= 81, `agi`= 29, `sta`= 62, `inte`=163, `spi`=134, `armor`=  794, `min_dmg`= 36, `max_dmg`= 54 WHERE `creature_entry`= 416 AND `level`=43;
UPDATE `pet_levelstats` SET `str`= 85, `agi`= 29, `sta`= 63, `inte`=167, `spi`=137, `armor`=  833, `min_dmg`= 38, `max_dmg`= 57 WHERE `creature_entry`= 416 AND `level`=44;
UPDATE `pet_levelstats` SET `str`= 89, `agi`= 29, `sta`= 64, `inte`=171, `spi`=140, `armor`=  871, `min_dmg`= 40, `max_dmg`= 60 WHERE `creature_entry`= 416 AND `level`=45;
UPDATE `pet_levelstats` SET `str`= 93, `agi`= 30, `sta`= 66, `inte`=175, `spi`=144, `armor`=  910, `min_dmg`= 42, `max_dmg`= 63 WHERE `creature_entry`= 416 AND `level`=46;
UPDATE `pet_levelstats` SET `str`= 95, `agi`= 31, `sta`= 68, `inte`=180, `spi`=148, `armor`=  928, `min_dmg`= 44, `max_dmg`= 65 WHERE `creature_entry`= 416 AND `level`=47;
UPDATE `pet_levelstats` SET `str`= 97, `agi`= 31, `sta`= 68, `inte`=184, `spi`=151, `armor`=  946, `min_dmg`= 46, `max_dmg`= 68 WHERE `creature_entry`= 416 AND `level`=48;
UPDATE `pet_levelstats` SET `str`= 99, `agi`= 31, `sta`= 70, `inte`=188, `spi`=155, `armor`=  964, `min_dmg`= 48, `max_dmg`= 71 WHERE `creature_entry`= 416 AND `level`=49;
UPDATE `pet_levelstats` SET `str`=101, `agi`= 32, `sta`= 72, `inte`=192, `spi`=158, `armor`=  983, `min_dmg`= 50, `max_dmg`= 74 WHERE `creature_entry`= 416 AND `level`=50;
UPDATE `pet_levelstats` SET `str`=103, `agi`= 32, `sta`= 73, `inte`=196, `spi`=161, `armor`= 1001, `min_dmg`= 50, `max_dmg`= 75 WHERE `creature_entry`= 416 AND `level`=51;
UPDATE `pet_levelstats` SET `str`=105, `agi`= 32, `sta`= 74, `inte`=200, `spi`=165, `armor`= 1019, `min_dmg`= 51, `max_dmg`= 76 WHERE `creature_entry`= 416 AND `level`=52;
UPDATE `pet_levelstats` SET `str`=107, `agi`= 32, `sta`= 75, `inte`=204, `spi`=168, `armor`= 1037, `min_dmg`= 51, `max_dmg`= 77 WHERE `creature_entry`= 416 AND `level`=53;
UPDATE `pet_levelstats` SET `str`=109, `agi`= 33, `sta`= 77, `inte`=209, `spi`=172, `armor`= 1055, `min_dmg`= 52, `max_dmg`= 79 WHERE `creature_entry`= 416 AND `level`=54;
UPDATE `pet_levelstats` SET `str`=111, `agi`= 33, `sta`= 78, `inte`=215, `spi`=176, `armor`= 1073, `min_dmg`= 53, `max_dmg`= 80 WHERE `creature_entry`= 416 AND `level`=55;
UPDATE `pet_levelstats` SET `str`=114, `agi`= 34, `sta`= 80, `inte`=221, `spi`=181, `armor`= 1091, `min_dmg`= 55, `max_dmg`= 82 WHERE `creature_entry`= 416 AND `level`=56;
UPDATE `pet_levelstats` SET `str`=116, `agi`= 34, `sta`= 81, `inte`=231, `spi`=200, `armor`= 1109, `min_dmg`= 59, `max_dmg`= 88 WHERE `creature_entry`= 416 AND `level`=57;
UPDATE `pet_levelstats` SET `str`=118, `agi`= 34, `sta`= 83, `inte`=242, `spi`=220, `armor`= 1127, `min_dmg`= 63, `max_dmg`= 94 WHERE `creature_entry`= 416 AND `level`=58;
UPDATE `pet_levelstats` SET `str`=120, `agi`= 34, `sta`= 84, `inte`=253, `spi`=240, `armor`= 1145, `min_dmg`= 67, `max_dmg`=100 WHERE `creature_entry`= 416 AND `level`=59;
UPDATE `pet_levelstats` SET `str`=122, `agi`= 35, `sta`= 86, `inte`=264, `spi`=260, `armor`= 1163, `min_dmg`= 72, `max_dmg`=107 WHERE `creature_entry`= 416 AND `level`=60;
UPDATE `pet_levelstats` SET `str`=124, `agi`= 35, `sta`= 94, `inte`=296, `spi`=236, `armor`= 1985, `min_dmg`=109, `max_dmg`=136 WHERE `creature_entry`= 416 AND `level`=61;
UPDATE `pet_levelstats` SET `str`=126, `agi`= 35, `sta`=102, `inte`=328, `spi`=212, `armor`= 2807, `min_dmg`=146, `max_dmg`=166 WHERE `creature_entry`= 416 AND `level`=62;
UPDATE `pet_levelstats` SET `str`=128, `agi`= 35, `sta`=101, `inte`=327, `spi`=218, `armor`= 2999, `min_dmg`=154, `max_dmg`=182 WHERE `creature_entry`= 416 AND `level`=63;
UPDATE `pet_levelstats` SET `str`=130, `agi`= 36, `sta`=101, `inte`=327, `spi`=224, `armor`= 3192, `min_dmg`=163, `max_dmg`=198 WHERE `creature_entry`= 416 AND `level`=64;
UPDATE `pet_levelstats` SET `str`=133, `agi`= 36, `sta`=101, `inte`=327, `spi`=231, `armor`= 3384, `min_dmg`=172, `max_dmg`=214 WHERE `creature_entry`= 416 AND `level`=65;
UPDATE `pet_levelstats` SET `str`=135, `agi`= 37, `sta`=101, `inte`=327, `spi`=237, `armor`= 3577, `min_dmg`=181, `max_dmg`=230 WHERE `creature_entry`= 416 AND `level`=66;
UPDATE `pet_levelstats` SET `str`=137, `agi`= 37, `sta`=101, `inte`=327, `spi`=243, `armor`= 3769, `min_dmg`=190, `max_dmg`=247 WHERE `creature_entry`= 416 AND `level`=67;
UPDATE `pet_levelstats` SET `str`=140, `agi`= 38, `sta`=101, `inte`=327, `spi`=250, `armor`= 3962, `min_dmg`=199, `max_dmg`=263 WHERE `creature_entry`= 416 AND `level`=68;
UPDATE `pet_levelstats` SET `str`=142, `agi`= 38, `sta`=101, `inte`=327, `spi`=256, `armor`= 4154, `min_dmg`=207, `max_dmg`=279 WHERE `creature_entry`= 416 AND `level`=69;
UPDATE `pet_levelstats` SET `str`=145, `agi`= 39, `sta`=101, `inte`=327, `spi`=263, `armor`= 4347, `min_dmg`=216, `max_dmg`=295 WHERE `creature_entry`= 416 AND `level`=70;
UPDATE `pet_levelstats` SET `str`=160, `agi`= 43, `sta`=102, `inte`=331, `spi`=273, `armor`= 4540, `min_dmg`=225, `max_dmg`=312 WHERE `creature_entry`= 416 AND `level`=71;
UPDATE `pet_levelstats` SET `str`=175, `agi`= 47, `sta`=104, `inte`=335, `spi`=283, `armor`= 4732, `min_dmg`=234, `max_dmg`=328 WHERE `creature_entry`= 416 AND `level`=72;
UPDATE `pet_levelstats` SET `str`=190, `agi`= 51, `sta`=106, `inte`=339, `spi`=294, `armor`= 4925, `min_dmg`=243, `max_dmg`=344 WHERE `creature_entry`= 416 AND `level`=73;
UPDATE `pet_levelstats` SET `str`=205, `agi`= 55, `sta`=107, `inte`=343, `spi`=304, `armor`= 5117, `min_dmg`=252, `max_dmg`=360 WHERE `creature_entry`= 416 AND `level`=74;
UPDATE `pet_levelstats` SET `str`=221, `agi`= 59, `sta`=109, `inte`=348, `spi`=315, `armor`= 5310, `min_dmg`=260, `max_dmg`=376 WHERE `creature_entry`= 416 AND `level`=75;
UPDATE `pet_levelstats` SET `str`=236, `agi`= 63, `sta`=111, `inte`=352, `spi`=325, `armor`= 5502, `min_dmg`=269, `max_dmg`=393 WHERE `creature_entry`= 416 AND `level`=76;
UPDATE `pet_levelstats` SET `str`=251, `agi`= 67, `sta`=112, `inte`=356, `spi`=335, `armor`= 5695, `min_dmg`=278, `max_dmg`=409 WHERE `creature_entry`= 416 AND `level`=77;
UPDATE `pet_levelstats` SET `str`=266, `agi`= 71, `sta`=114, `inte`=360, `spi`=346, `armor`= 5887, `min_dmg`=287, `max_dmg`=425 WHERE `creature_entry`= 416 AND `level`=78;
UPDATE `pet_levelstats` SET `str`=281, `agi`= 75, `sta`=116, `inte`=364, `spi`=356, `armor`= 6080, `min_dmg`=296, `max_dmg`=441 WHERE `creature_entry`= 416 AND `level`=79;
UPDATE `pet_levelstats` SET `str`=297, `agi`= 79, `sta`=118, `inte`=369, `spi`=367, `armor`= 6273, `min_dmg`=305, `max_dmg`=458 WHERE `creature_entry`= 416 AND `level`=80;
-- VOIDWALKER
UPDATE `pet_levelstats` SET `str`= 29, `agi`= 10, `sta`= 29, `inte`= 25, `spi`= 27, `armor`=  831, `min_dmg`=  8, `max_dmg`= 14 WHERE `creature_entry`=1860 AND `level`=10;
UPDATE `pet_levelstats` SET `str`= 30, `agi`= 10, `sta`= 32, `inte`= 26, `spi`= 28, `armor`=  875, `min_dmg`=  9, `max_dmg`= 15 WHERE `creature_entry`=1860 AND `level`=11;
UPDATE `pet_levelstats` SET `str`= 31, `agi`= 26, `sta`= 36, `inte`= 24, `spi`= 31, `armor`=  876, `min_dmg`= 10, `max_dmg`= 16 WHERE `creature_entry`=1860 AND `level`=12;
UPDATE `pet_levelstats` SET `str`= 32, `agi`= 28, `sta`= 43, `inte`= 26, `spi`= 32, `armor`=  877, `min_dmg`= 11, `max_dmg`= 17 WHERE `creature_entry`=1860 AND `level`=13;
UPDATE `pet_levelstats` SET `str`= 33, `agi`= 28, `sta`= 44, `inte`= 25, `spi`= 35, `armor`=  878, `min_dmg`= 12, `max_dmg`= 19 WHERE `creature_entry`=1860 AND `level`=14;
UPDATE `pet_levelstats` SET `str`= 34, `agi`= 30, `sta`= 48, `inte`= 26, `spi`= 37, `armor`=  925, `min_dmg`= 13, `max_dmg`= 20 WHERE `creature_entry`=1860 AND `level`=15;
UPDATE `pet_levelstats` SET `str`= 36, `agi`= 30, `sta`= 52, `inte`= 27, `spi`= 39, `armor`=  975, `min_dmg`= 14, `max_dmg`= 22 WHERE `creature_entry`=1860 AND `level`=16;
UPDATE `pet_levelstats` SET `str`= 38, `agi`= 31, `sta`= 55, `inte`= 28, `spi`= 42, `armor`= 1022, `min_dmg`= 15, `max_dmg`= 23 WHERE `creature_entry`=1860 AND `level`=17;
UPDATE `pet_levelstats` SET `str`= 39, `agi`= 33, `sta`= 59, `inte`= 28, `spi`= 44, `armor`= 1068, `min_dmg`= 16, `max_dmg`= 25 WHERE `creature_entry`=1860 AND `level`=18;
UPDATE `pet_levelstats` SET `str`= 40, `agi`= 33, `sta`= 63, `inte`= 30, `spi`= 46, `armor`= 1120, `min_dmg`= 17, `max_dmg`= 26 WHERE `creature_entry`=1860 AND `level`=19;
UPDATE `pet_levelstats` SET `str`= 42, `agi`= 35, `sta`= 67, `inte`= 31, `spi`= 49, `armor`= 1165, `min_dmg`= 18, `max_dmg`= 28 WHERE `creature_entry`=1860 AND `level`=20;
UPDATE `pet_levelstats` SET `str`= 44, `agi`= 36, `sta`= 80, `inte`= 53, `spi`= 39, `armor`= 1232, `min_dmg`= 19, `max_dmg`= 29 WHERE `creature_entry`=1860 AND `level`=21;
UPDATE `pet_levelstats` SET `str`= 46, `agi`= 36, `sta`= 84, `inte`= 54, `spi`= 41, `armor`= 1282, `min_dmg`= 20, `max_dmg`= 31 WHERE `creature_entry`=1860 AND `level`=22;
UPDATE `pet_levelstats` SET `str`= 47, `agi`= 38, `sta`= 89, `inte`= 56, `spi`= 42, `armor`= 1330, `min_dmg`= 21, `max_dmg`= 32 WHERE `creature_entry`=1860 AND `level`=23;
UPDATE `pet_levelstats` SET `str`= 49, `agi`= 39, `sta`= 93, `inte`= 57, `spi`= 43, `armor`= 1378, `min_dmg`= 22, `max_dmg`= 33 WHERE `creature_entry`=1860 AND `level`=24;
UPDATE `pet_levelstats` SET `str`= 50, `agi`= 40, `sta`= 97, `inte`= 60, `spi`= 44, `armor`= 1427, `min_dmg`= 23, `max_dmg`= 35 WHERE `creature_entry`=1860 AND `level`=25;
UPDATE `pet_levelstats` SET `str`= 52, `agi`= 41, `sta`=101, `inte`= 62, `spi`= 46, `armor`= 1474, `min_dmg`= 24, `max_dmg`= 36 WHERE `creature_entry`=1860 AND `level`=26;
UPDATE `pet_levelstats` SET `str`= 53, `agi`= 42, `sta`=105, `inte`= 63, `spi`= 47, `armor`= 1524, `min_dmg`= 25, `max_dmg`= 38 WHERE `creature_entry`=1860 AND `level`=27;
UPDATE `pet_levelstats` SET `str`= 55, `agi`= 43, `sta`=110, `inte`= 65, `spi`= 48, `armor`= 1572, `min_dmg`= 26, `max_dmg`= 39 WHERE `creature_entry`=1860 AND `level`=28;
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 44, `sta`=114, `inte`= 67, `spi`= 49, `armor`= 1619, `min_dmg`= 27, `max_dmg`= 41 WHERE `creature_entry`=1860 AND `level`=29;
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 46, `sta`=118, `inte`= 69, `spi`= 51, `armor`= 1667, `min_dmg`= 28, `max_dmg`= 42 WHERE `creature_entry`=1860 AND `level`=30;
UPDATE `pet_levelstats` SET `str`= 59, `agi`= 47, `sta`=123, `inte`= 71, `spi`= 52, `armor`= 1715, `min_dmg`= 29, `max_dmg`= 44 WHERE `creature_entry`=1860 AND `level`=31;
UPDATE `pet_levelstats` SET `str`= 60, `agi`= 47, `sta`=127, `inte`= 73, `spi`= 53, `armor`= 1766, `min_dmg`= 30, `max_dmg`= 45 WHERE `creature_entry`=1860 AND `level`=32;
UPDATE `pet_levelstats` SET `str`= 62, `agi`= 49, `sta`=131, `inte`= 74, `spi`= 54, `armor`= 1812, `min_dmg`= 31, `max_dmg`= 47 WHERE `creature_entry`=1860 AND `level`=33;
UPDATE `pet_levelstats` SET `str`= 63, `agi`= 50, `sta`=135, `inte`= 76, `spi`= 56, `armor`= 1861, `min_dmg`= 32, `max_dmg`= 48 WHERE `creature_entry`=1860 AND `level`=34;
UPDATE `pet_levelstats` SET `str`= 65, `agi`= 51, `sta`=146, `inte`= 62, `spi`= 57, `armor`= 2238, `min_dmg`= 34, `max_dmg`= 50 WHERE `creature_entry`=1860 AND `level`=35;
UPDATE `pet_levelstats` SET `str`= 66, `agi`= 52, `sta`=150, `inte`= 63, `spi`= 59, `armor`= 2415, `min_dmg`= 34, `max_dmg`= 51 WHERE `creature_entry`=1860 AND `level`=36;
UPDATE `pet_levelstats` SET `str`= 68, `agi`= 53, `sta`=155, `inte`= 64, `spi`= 60, `armor`= 2602, `min_dmg`= 35, `max_dmg`= 54 WHERE `creature_entry`=1860 AND `level`=37;
UPDATE `pet_levelstats` SET `str`= 70, `agi`= 55, `sta`=159, `inte`= 66, `spi`= 62, `armor`= 2795, `min_dmg`= 36, `max_dmg`= 55 WHERE `creature_entry`=1860 AND `level`=38;
UPDATE `pet_levelstats` SET `str`= 72, `agi`= 56, `sta`=164, `inte`= 67, `spi`= 63, `armor`= 3002, `min_dmg`= 37, `max_dmg`= 57 WHERE `creature_entry`=1860 AND `level`=39;
UPDATE `pet_levelstats` SET `str`= 74, `agi`= 57, `sta`=170, `inte`= 70, `spi`= 65, `armor`= 3219, `min_dmg`= 38, `max_dmg`= 58 WHERE `creature_entry`=1860 AND `level`=40;
UPDATE `pet_levelstats` SET `str`= 77, `agi`= 58, `sta`=163, `inte`= 70, `spi`= 66, `armor`= 3222, `min_dmg`= 43, `max_dmg`= 65 WHERE `creature_entry`=1860 AND `level`=41;
UPDATE `pet_levelstats` SET `str`= 81, `agi`= 59, `sta`=156, `inte`= 70, `spi`= 67, `armor`= 3225, `min_dmg`= 48, `max_dmg`= 73 WHERE `creature_entry`=1860 AND `level`=42;
UPDATE `pet_levelstats` SET `str`= 86, `agi`= 61, `sta`=169, `inte`= 72, `spi`= 69, `armor`= 3228, `min_dmg`= 53, `max_dmg`= 81 WHERE `creature_entry`=1860 AND `level`=43;
UPDATE `pet_levelstats` SET `str`= 91, `agi`= 62, `sta`=169, `inte`= 69, `spi`= 70, `armor`= 3392, `min_dmg`= 59, `max_dmg`= 88 WHERE `creature_entry`=1860 AND `level`=44;
UPDATE `pet_levelstats` SET `str`= 96, `agi`= 64, `sta`=169, `inte`= 67, `spi`= 72, `armor`= 3557, `min_dmg`= 64, `max_dmg`= 96 WHERE `creature_entry`=1860 AND `level`=45;
UPDATE `pet_levelstats` SET `str`= 98, `agi`= 65, `sta`=173, `inte`= 77, `spi`= 73, `armor`= 3722, `min_dmg`= 69, `max_dmg`=104 WHERE `creature_entry`=1860 AND `level`=46;
UPDATE `pet_levelstats` SET `str`=100, `agi`= 66, `sta`=177, `inte`= 78, `spi`= 75, `armor`= 3796, `min_dmg`= 75, `max_dmg`=112 WHERE `creature_entry`=1860 AND `level`=47;
UPDATE `pet_levelstats` SET `str`=102, `agi`= 68, `sta`=181, `inte`= 80, `spi`= 76, `armor`= 3868, `min_dmg`= 80, `max_dmg`=119 WHERE `creature_entry`=1860 AND `level`=48;
UPDATE `pet_levelstats` SET `str`=104, `agi`= 69, `sta`=186, `inte`= 82, `spi`= 78, `armor`= 3943, `min_dmg`= 85, `max_dmg`=127 WHERE `creature_entry`=1860 AND `level`=49;
UPDATE `pet_levelstats` SET `str`=107, `agi`= 71, `sta`=190, `inte`= 84, `spi`= 80, `armor`= 4013, `min_dmg`= 91, `max_dmg`=135 WHERE `creature_entry`=1860 AND `level`=50;
UPDATE `pet_levelstats` SET `str`=109, `agi`= 72, `sta`=223, `inte`= 97, `spi`= 81, `armor`= 4086, `min_dmg`= 96, `max_dmg`=143 WHERE `creature_entry`=1860 AND `level`=51;
UPDATE `pet_levelstats` SET `str`=111, `agi`= 73, `sta`=228, `inte`=100, `spi`= 82, `armor`= 4160, `min_dmg`=101, `max_dmg`=150 WHERE `creature_entry`=1860 AND `level`=52;
UPDATE `pet_levelstats` SET `str`=113, `agi`= 75, `sta`=233, `inte`=102, `spi`= 84, `armor`= 4233, `min_dmg`=107, `max_dmg`=158 WHERE `creature_entry`=1860 AND `level`=53;
UPDATE `pet_levelstats` SET `str`=115, `agi`= 76, `sta`=207, `inte`= 90, `spi`= 85, `armor`= 4307, `min_dmg`=112, `max_dmg`=166 WHERE `creature_entry`=1860 AND `level`=54;
UPDATE `pet_levelstats` SET `str`=117, `agi`= 77, `sta`=227, `inte`= 99, `spi`= 87, `armor`= 4380, `min_dmg`=117, `max_dmg`=173 WHERE `creature_entry`=1860 AND `level`=55;
UPDATE `pet_levelstats` SET `str`=120, `agi`= 79, `sta`=248, `inte`=108, `spi`= 89, `armor`= 4453, `min_dmg`=123, `max_dmg`=181 WHERE `creature_entry`=1860 AND `level`=56;
UPDATE `pet_levelstats` SET `str`=122, `agi`= 80, `sta`=242, `inte`= 95, `spi`=108, `armor`= 4526, `min_dmg`=128, `max_dmg`=189 WHERE `creature_entry`=1860 AND `level`=57;
UPDATE `pet_levelstats` SET `str`=124, `agi`= 81, `sta`=236, `inte`= 82, `spi`=127, `armor`= 4599, `min_dmg`=133, `max_dmg`=197 WHERE `creature_entry`=1860 AND `level`=58;
UPDATE `pet_levelstats` SET `str`=127, `agi`= 83, `sta`=230, `inte`= 69, `spi`=147, `armor`= 4673, `min_dmg`=139, `max_dmg`=204 WHERE `creature_entry`=1860 AND `level`=59;
UPDATE `pet_levelstats` SET `str`=129, `agi`= 85, `sta`=249, `inte`= 70, `spi`=150, `armor`= 4745, `min_dmg`=144, `max_dmg`=212 WHERE `creature_entry`=1860 AND `level`=60;
UPDATE `pet_levelstats` SET `str`=131, `agi`= 60, `sta`=264, `inte`= 97, `spi`=126, `armor`= 5984, `min_dmg`=149, `max_dmg`=220 WHERE `creature_entry`=1860 AND `level`=61;
UPDATE `pet_levelstats` SET `str`=133, `agi`= 36, `sta`=279, `inte`=124, `spi`=102, `armor`= 7223, `min_dmg`=155, `max_dmg`=228 WHERE `creature_entry`=1860 AND `level`=62;
UPDATE `pet_levelstats` SET `str`=135, `agi`= 45, `sta`=279, `inte`=125, `spi`=104, `armor`= 7453, `min_dmg`=161, `max_dmg`=238 WHERE `creature_entry`=1860 AND `level`=63;
UPDATE `pet_levelstats` SET `str`=138, `agi`= 54, `sta`=279, `inte`=126, `spi`=107, `armor`= 7684, `min_dmg`=167, `max_dmg`=248 WHERE `creature_entry`=1860 AND `level`=64;
UPDATE `pet_levelstats` SET `str`=140, `agi`= 63, `sta`=279, `inte`=127, `spi`=109, `armor`= 7915, `min_dmg`=174, `max_dmg`=258 WHERE `creature_entry`=1860 AND `level`=65;
UPDATE `pet_levelstats` SET `str`=143, `agi`= 72, `sta`=279, `inte`=128, `spi`=112, `armor`= 8146, `min_dmg`=180, `max_dmg`=269 WHERE `creature_entry`=1860 AND `level`=66;
UPDATE `pet_levelstats` SET `str`=145, `agi`= 81, `sta`=279, `inte`=129, `spi`=114, `armor`= 8377, `min_dmg`=187, `max_dmg`=279 WHERE `creature_entry`=1860 AND `level`=67;
UPDATE `pet_levelstats` SET `str`=148, `agi`= 90, `sta`=279, `inte`=130, `spi`=117, `armor`= 8608, `min_dmg`=193, `max_dmg`=289 WHERE `creature_entry`=1860 AND `level`=68;
UPDATE `pet_levelstats` SET `str`=150, `agi`= 99, `sta`=279, `inte`=131, `spi`=119, `armor`= 8839, `min_dmg`=200, `max_dmg`=300 WHERE `creature_entry`=1860 AND `level`=69;
UPDATE `pet_levelstats` SET `str`=153, `agi`=109, `sta`=280, `inte`=133, `spi`=122, `armor`= 9070, `min_dmg`=206, `max_dmg`=310 WHERE `creature_entry`=1860 AND `level`=70;
UPDATE `pet_levelstats` SET `str`=163, `agi`=102, `sta`=284, `inte`=134, `spi`=134, `armor`= 9917, `min_dmg`=212, `max_dmg`=320 WHERE `creature_entry`=1860 AND `level`=71;
UPDATE `pet_levelstats` SET `str`=173, `agi`= 95, `sta`=289, `inte`=136, `spi`=146, `armor`=10765, `min_dmg`=219, `max_dmg`=330 WHERE `creature_entry`=1860 AND `level`=72;
UPDATE `pet_levelstats` SET `str`=183, `agi`= 88, `sta`=294, `inte`=138, `spi`=159, `armor`=11612, `min_dmg`=225, `max_dmg`=341 WHERE `creature_entry`=1860 AND `level`=73;
UPDATE `pet_levelstats` SET `str`=193, `agi`= 81, `sta`=299, `inte`=139, `spi`=171, `armor`=12460, `min_dmg`=232, `max_dmg`=351 WHERE `creature_entry`=1860 AND `level`=74;
UPDATE `pet_levelstats` SET `str`=203, `agi`= 74, `sta`=304, `inte`=141, `spi`=183, `armor`=13307, `min_dmg`=238, `max_dmg`=361 WHERE `creature_entry`=1860 AND `level`=75;
UPDATE `pet_levelstats` SET `str`=214, `agi`= 67, `sta`=309, `inte`=143, `spi`=196, `armor`=14155, `min_dmg`=245, `max_dmg`=372 WHERE `creature_entry`=1860 AND `level`=76;
UPDATE `pet_levelstats` SET `str`=236, `agi`= 72, `sta`=314, `inte`=144, `spi`=200, `armor`=14652, `min_dmg`=251, `max_dmg`=382 WHERE `creature_entry`=1860 AND `level`=77;
UPDATE `pet_levelstats` SET `str`=262, `agi`= 78, `sta`=318, `inte`=146, `spi`=203, `armor`=15150, `min_dmg`=258, `max_dmg`=393 WHERE `creature_entry`=1860 AND `level`=78;
UPDATE `pet_levelstats` SET `str`=288, `agi`= 84, `sta`=323, `inte`=148, `spi`=206, `armor`=15649, `min_dmg`=265, `max_dmg`=404 WHERE `creature_entry`=1860 AND `level`=79;
UPDATE `pet_levelstats` SET `str`=314, `agi`= 90, `sta`=328, `inte`=150, `spi`=209, `armor`=16148, `min_dmg`=272, `max_dmg`=415 WHERE `creature_entry`=1860 AND `level`=80;
-- SUCCUBUS
UPDATE `pet_levelstats` SET `str`= 42, `agi`= 35, `sta`= 67, `inte`= 31, `spi`= 49, `armor`=  563, `min_dmg`= 20, `max_dmg`= 30 WHERE `creature_entry`=1863 AND `level`=20;
UPDATE `pet_levelstats` SET `str`= 44, `agi`= 36, `sta`= 80, `inte`= 53, `spi`= 39, `armor`=  604, `min_dmg`= 20, `max_dmg`= 31 WHERE `creature_entry`=1863 AND `level`=21;
UPDATE `pet_levelstats` SET `str`= 46, `agi`= 36, `sta`= 84, `inte`= 54, `spi`= 41, `armor`=  628, `min_dmg`= 21, `max_dmg`= 32 WHERE `creature_entry`=1863 AND `level`=22;
UPDATE `pet_levelstats` SET `str`= 47, `agi`= 38, `sta`= 89, `inte`= 56, `spi`= 42, `armor`=  652, `min_dmg`= 22, `max_dmg`= 33 WHERE `creature_entry`=1863 AND `level`=23;
UPDATE `pet_levelstats` SET `str`= 49, `agi`= 39, `sta`= 93, `inte`= 57, `spi`= 43, `armor`=  675, `min_dmg`= 22, `max_dmg`= 34 WHERE `creature_entry`=1863 AND `level`=24;
UPDATE `pet_levelstats` SET `str`= 50, `agi`= 40, `sta`= 97, `inte`= 60, `spi`= 44, `armor`=  699, `min_dmg`= 23, `max_dmg`= 36 WHERE `creature_entry`=1863 AND `level`=25;
UPDATE `pet_levelstats` SET `str`= 52, `agi`= 41, `sta`=101, `inte`= 62, `spi`= 46, `armor`=  721, `min_dmg`= 24, `max_dmg`= 37 WHERE `creature_entry`=1863 AND `level`=26;
UPDATE `pet_levelstats` SET `str`= 53, `agi`= 42, `sta`=105, `inte`= 63, `spi`= 47, `armor`=  745, `min_dmg`= 25, `max_dmg`= 38 WHERE `creature_entry`=1863 AND `level`=27;
UPDATE `pet_levelstats` SET `str`= 55, `agi`= 43, `sta`=110, `inte`= 65, `spi`= 48, `armor`=  768, `min_dmg`= 26, `max_dmg`= 40 WHERE `creature_entry`=1863 AND `level`=28;
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 44, `sta`=114, `inte`= 67, `spi`= 49, `armor`=  791, `min_dmg`= 27, `max_dmg`= 41 WHERE `creature_entry`=1863 AND `level`=29;
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 46, `sta`=118, `inte`= 69, `spi`= 51, `armor`=  815, `min_dmg`= 28, `max_dmg`= 43 WHERE `creature_entry`=1863 AND `level`=30;
UPDATE `pet_levelstats` SET `str`= 59, `agi`= 47, `sta`=123, `inte`= 71, `spi`= 52, `armor`=  838, `min_dmg`= 28, `max_dmg`= 44 WHERE `creature_entry`=1863 AND `level`=31;
UPDATE `pet_levelstats` SET `str`= 60, `agi`= 47, `sta`=127, `inte`= 73, `spi`= 53, `armor`=  862, `min_dmg`= 29, `max_dmg`= 45 WHERE `creature_entry`=1863 AND `level`=32;
UPDATE `pet_levelstats` SET `str`= 62, `agi`= 49, `sta`=131, `inte`= 74, `spi`= 54, `armor`=  884, `min_dmg`= 30, `max_dmg`= 46 WHERE `creature_entry`=1863 AND `level`=33;
UPDATE `pet_levelstats` SET `str`= 63, `agi`= 50, `sta`=135, `inte`= 76, `spi`= 56, `armor`=  908, `min_dmg`= 31, `max_dmg`= 47 WHERE `creature_entry`=1863 AND `level`=34;
UPDATE `pet_levelstats` SET `str`= 65, `agi`= 51, `sta`=146, `inte`= 62, `spi`= 57, `armor`=  950, `min_dmg`= 32, `max_dmg`= 54 WHERE `creature_entry`=1863 AND `level`=35;
UPDATE `pet_levelstats` SET `str`= 66, `agi`= 52, `sta`=150, `inte`= 63, `spi`= 59, `armor`=  990, `min_dmg`= 33, `max_dmg`= 56 WHERE `creature_entry`=1863 AND `level`=36;
UPDATE `pet_levelstats` SET `str`= 68, `agi`= 53, `sta`=155, `inte`= 64, `spi`= 60, `armor`= 1038, `min_dmg`= 34, `max_dmg`= 59 WHERE `creature_entry`=1863 AND `level`=37;
UPDATE `pet_levelstats` SET `str`= 70, `agi`= 55, `sta`=159, `inte`= 66, `spi`= 62, `armor`= 1095, `min_dmg`= 36, `max_dmg`= 61 WHERE `creature_entry`=1863 AND `level`=38;
UPDATE `pet_levelstats` SET `str`= 72, `agi`= 56, `sta`=164, `inte`= 67, `spi`= 63, `armor`= 1163, `min_dmg`= 38, `max_dmg`= 64 WHERE `creature_entry`=1863 AND `level`=39;
UPDATE `pet_levelstats` SET `str`= 74, `agi`= 57, `sta`=170, `inte`= 70, `spi`= 65, `armor`= 1244, `min_dmg`= 41, `max_dmg`= 66 WHERE `creature_entry`=1863 AND `level`=40;
UPDATE `pet_levelstats` SET `str`= 77, `agi`= 58, `sta`=163, `inte`= 70, `spi`= 66, `armor`= 1338, `min_dmg`= 43, `max_dmg`= 67 WHERE `creature_entry`=1863 AND `level`=41;
UPDATE `pet_levelstats` SET `str`= 81, `agi`= 59, `sta`=156, `inte`= 70, `spi`= 67, `armor`= 1448, `min_dmg`= 46, `max_dmg`= 69 WHERE `creature_entry`=1863 AND `level`=42;
UPDATE `pet_levelstats` SET `str`= 86, `agi`= 61, `sta`=169, `inte`= 72, `spi`= 69, `armor`= 1544, `min_dmg`= 48, `max_dmg`= 72 WHERE `creature_entry`=1863 AND `level`=43;
UPDATE `pet_levelstats` SET `str`= 91, `agi`= 62, `sta`=169, `inte`= 69, `spi`= 70, `armor`= 1641, `min_dmg`= 51, `max_dmg`= 76 WHERE `creature_entry`=1863 AND `level`=44;
UPDATE `pet_levelstats` SET `str`= 96, `agi`= 64, `sta`=169, `inte`= 67, `spi`= 72, `armor`= 1738, `min_dmg`= 53, `max_dmg`= 79 WHERE `creature_entry`=1863 AND `level`=45;
UPDATE `pet_levelstats` SET `str`= 98, `agi`= 65, `sta`=173, `inte`= 77, `spi`= 73, `armor`= 1773, `min_dmg`= 56, `max_dmg`= 83 WHERE `creature_entry`=1863 AND `level`=46;
UPDATE `pet_levelstats` SET `str`=100, `agi`= 66, `sta`=177, `inte`= 78, `spi`= 75, `armor`= 1808, `min_dmg`= 59, `max_dmg`= 86 WHERE `creature_entry`=1863 AND `level`=47;
UPDATE `pet_levelstats` SET `str`=102, `agi`= 68, `sta`=181, `inte`= 80, `spi`= 76, `armor`= 1843, `min_dmg`= 61, `max_dmg`= 90 WHERE `creature_entry`=1863 AND `level`=48;
UPDATE `pet_levelstats` SET `str`=104, `agi`= 69, `sta`=186, `inte`= 82, `spi`= 78, `armor`= 1878, `min_dmg`= 64, `max_dmg`= 93 WHERE `creature_entry`=1863 AND `level`=49;
UPDATE `pet_levelstats` SET `str`=107, `agi`= 71, `sta`=190, `inte`= 84, `spi`= 80, `armor`= 1912, `min_dmg`= 67, `max_dmg`= 97 WHERE `creature_entry`=1863 AND `level`=50;
UPDATE `pet_levelstats` SET `str`=109, `agi`= 72, `sta`=223, `inte`= 97, `spi`= 81, `armor`= 2114, `min_dmg`= 77, `max_dmg`=112 WHERE `creature_entry`=1863 AND `level`=51;
UPDATE `pet_levelstats` SET `str`=111, `agi`= 73, `sta`=228, `inte`=100, `spi`= 82, `armor`= 2316, `min_dmg`= 88, `max_dmg`=128 WHERE `creature_entry`=1863 AND `level`=52;
UPDATE `pet_levelstats` SET `str`=113, `agi`= 75, `sta`=233, `inte`=102, `spi`= 84, `armor`= 2519, `min_dmg`= 98, `max_dmg`=143 WHERE `creature_entry`=1863 AND `level`=53;
UPDATE `pet_levelstats` SET `str`=115, `agi`= 76, `sta`=207, `inte`= 90, `spi`= 85, `armor`= 2721, `min_dmg`=109, `max_dmg`=159 WHERE `creature_entry`=1863 AND `level`=54;
UPDATE `pet_levelstats` SET `str`=117, `agi`= 77, `sta`=227, `inte`= 99, `spi`= 87, `armor`= 2923, `min_dmg`=119, `max_dmg`=174 WHERE `creature_entry`=1863 AND `level`=55;
UPDATE `pet_levelstats` SET `str`=120, `agi`= 79, `sta`=248, `inte`=108, `spi`= 89, `armor`= 3126, `min_dmg`=130, `max_dmg`=190 WHERE `creature_entry`=1863 AND `level`=56;
UPDATE `pet_levelstats` SET `str`=122, `agi`= 80, `sta`=242, `inte`= 95, `spi`=108, `armor`= 3328, `min_dmg`=141, `max_dmg`=206 WHERE `creature_entry`=1863 AND `level`=57;
UPDATE `pet_levelstats` SET `str`=124, `agi`= 81, `sta`=236, `inte`= 82, `spi`=127, `armor`= 3530, `min_dmg`=151, `max_dmg`=221 WHERE `creature_entry`=1863 AND `level`=58;
UPDATE `pet_levelstats` SET `str`=127, `agi`= 83, `sta`=230, `inte`= 69, `spi`=147, `armor`= 3733, `min_dmg`=162, `max_dmg`=237 WHERE `creature_entry`=1863 AND `level`=59;
UPDATE `pet_levelstats` SET `str`=129, `agi`= 85, `sta`=249, `inte`= 70, `spi`=150, `armor`= 3935, `min_dmg`=172, `max_dmg`=252 WHERE `creature_entry`=1863 AND `level`=60;
UPDATE `pet_levelstats` SET `str`=131, `agi`= 60, `sta`=264, `inte`= 97, `spi`=126, `armor`= 4137, `min_dmg`=183, `max_dmg`=268 WHERE `creature_entry`=1863 AND `level`=61;
UPDATE `pet_levelstats` SET `str`=133, `agi`= 36, `sta`=279, `inte`=124, `spi`=102, `armor`= 4340, `min_dmg`=194, `max_dmg`=284 WHERE `creature_entry`=1863 AND `level`=62;
UPDATE `pet_levelstats` SET `str`=135, `agi`= 45, `sta`=279, `inte`=125, `spi`=104, `armor`= 4638, `min_dmg`=204, `max_dmg`=298 WHERE `creature_entry`=1863 AND `level`=63;
UPDATE `pet_levelstats` SET `str`=138, `agi`= 54, `sta`=279, `inte`=126, `spi`=107, `armor`= 4936, `min_dmg`=214, `max_dmg`=313 WHERE `creature_entry`=1863 AND `level`=64;
UPDATE `pet_levelstats` SET `str`=140, `agi`= 63, `sta`=279, `inte`=127, `spi`=109, `armor`= 5234, `min_dmg`=224, `max_dmg`=328 WHERE `creature_entry`=1863 AND `level`=65;
UPDATE `pet_levelstats` SET `str`=143, `agi`= 72, `sta`=279, `inte`=128, `spi`=112, `armor`= 5532, `min_dmg`=234, `max_dmg`=342 WHERE `creature_entry`=1863 AND `level`=66;
UPDATE `pet_levelstats` SET `str`=145, `agi`= 81, `sta`=279, `inte`=129, `spi`=114, `armor`= 5830, `min_dmg`=244, `max_dmg`=357 WHERE `creature_entry`=1863 AND `level`=67;
UPDATE `pet_levelstats` SET `str`=148, `agi`= 90, `sta`=279, `inte`=130, `spi`=117, `armor`= 6128, `min_dmg`=254, `max_dmg`=372 WHERE `creature_entry`=1863 AND `level`=68;
UPDATE `pet_levelstats` SET `str`=150, `agi`= 99, `sta`=279, `inte`=131, `spi`=119, `armor`= 6426, `min_dmg`=264, `max_dmg`=387 WHERE `creature_entry`=1863 AND `level`=69;
UPDATE `pet_levelstats` SET `str`=153, `agi`=109, `sta`=280, `inte`=133, `spi`=122, `armor`= 6724, `min_dmg`=274, `max_dmg`=401 WHERE `creature_entry`=1863 AND `level`=70;
UPDATE `pet_levelstats` SET `str`=163, `agi`=102, `sta`=284, `inte`=134, `spi`=134, `armor`= 7023, `min_dmg`=284, `max_dmg`=416 WHERE `creature_entry`=1863 AND `level`=71;
UPDATE `pet_levelstats` SET `str`=173, `agi`= 95, `sta`=289, `inte`=136, `spi`=146, `armor`= 7321, `min_dmg`=294, `max_dmg`=431 WHERE `creature_entry`=1863 AND `level`=72;
UPDATE `pet_levelstats` SET `str`=183, `agi`= 88, `sta`=294, `inte`=138, `spi`=159, `armor`= 7619, `min_dmg`=304, `max_dmg`=445 WHERE `creature_entry`=1863 AND `level`=73;
UPDATE `pet_levelstats` SET `str`=193, `agi`= 81, `sta`=299, `inte`=139, `spi`=171, `armor`= 7917, `min_dmg`=314, `max_dmg`=460 WHERE `creature_entry`=1863 AND `level`=74;
UPDATE `pet_levelstats` SET `str`=203, `agi`= 74, `sta`=304, `inte`=141, `spi`=183, `armor`= 8215, `min_dmg`=324, `max_dmg`=475 WHERE `creature_entry`=1863 AND `level`=75;
UPDATE `pet_levelstats` SET `str`=214, `agi`= 67, `sta`=309, `inte`=143, `spi`=196, `armor`= 8513, `min_dmg`=334, `max_dmg`=490 WHERE `creature_entry`=1863 AND `level`=76;
UPDATE `pet_levelstats` SET `str`=236, `agi`= 72, `sta`=314, `inte`=144, `spi`=200, `armor`= 8811, `min_dmg`=344, `max_dmg`=504 WHERE `creature_entry`=1863 AND `level`=77;
UPDATE `pet_levelstats` SET `str`=262, `agi`= 78, `sta`=318, `inte`=146, `spi`=203, `armor`= 9109, `min_dmg`=354, `max_dmg`=519 WHERE `creature_entry`=1863 AND `level`=78;
UPDATE `pet_levelstats` SET `str`=288, `agi`= 84, `sta`=323, `inte`=148, `spi`=206, `armor`= 9407, `min_dmg`=364, `max_dmg`=534 WHERE `creature_entry`=1863 AND `level`=79;
UPDATE `pet_levelstats` SET `str`=314, `agi`= 90, `sta`=328, `inte`=150, `spi`=209, `armor`= 9706, `min_dmg`=375, `max_dmg`=549 WHERE `creature_entry`=1863 AND `level`=80;
-- FELHUNTER
UPDATE `pet_levelstats` SET `str`= 57, `agi`= 46, `sta`=118, `inte`= 69, `spi`= 51, `armor`=  834, `min_dmg`= 18, `max_dmg`= 29 WHERE `creature_entry`= 417 AND `level`=30;
UPDATE `pet_levelstats` SET `str`= 59, `agi`= 47, `sta`=123, `inte`= 71, `spi`= 52, `armor`=  857, `min_dmg`= 18, `max_dmg`= 30 WHERE `creature_entry`= 417 AND `level`=31;
UPDATE `pet_levelstats` SET `str`= 60, `agi`= 47, `sta`=127, `inte`= 73, `spi`= 53, `armor`=  882, `min_dmg`= 19, `max_dmg`= 31 WHERE `creature_entry`= 417 AND `level`=32;
UPDATE `pet_levelstats` SET `str`= 62, `agi`= 49, `sta`=131, `inte`= 74, `spi`= 54, `armor`=  905, `min_dmg`= 20, `max_dmg`= 32 WHERE `creature_entry`= 417 AND `level`=33;
UPDATE `pet_levelstats` SET `str`= 63, `agi`= 50, `sta`=135, `inte`= 76, `spi`= 56, `armor`=  929, `min_dmg`= 20, `max_dmg`= 33 WHERE `creature_entry`= 417 AND `level`=34;
UPDATE `pet_levelstats` SET `str`= 65, `agi`= 51, `sta`=146, `inte`= 62, `spi`= 57, `armor`=  998, `min_dmg`= 21, `max_dmg`= 34 WHERE `creature_entry`= 417 AND `level`=35;
UPDATE `pet_levelstats` SET `str`= 66, `agi`= 52, `sta`=150, `inte`= 63, `spi`= 59, `armor`= 1067, `min_dmg`= 22, `max_dmg`= 36 WHERE `creature_entry`= 417 AND `level`=36;
UPDATE `pet_levelstats` SET `str`= 68, `agi`= 53, `sta`=155, `inte`= 64, `spi`= 60, `armor`= 1137, `min_dmg`= 23, `max_dmg`= 37 WHERE `creature_entry`= 417 AND `level`=37;
UPDATE `pet_levelstats` SET `str`= 70, `agi`= 55, `sta`=159, `inte`= 66, `spi`= 62, `armor`= 1206, `min_dmg`= 24, `max_dmg`= 38 WHERE `creature_entry`= 417 AND `level`=38;
UPDATE `pet_levelstats` SET `str`= 72, `agi`= 56, `sta`=164, `inte`= 67, `spi`= 63, `armor`= 1275, `min_dmg`= 25, `max_dmg`= 40 WHERE `creature_entry`= 417 AND `level`=39;
UPDATE `pet_levelstats` SET `str`= 74, `agi`= 57, `sta`=170, `inte`= 70, `spi`= 65, `armor`= 1345, `min_dmg`= 26, `max_dmg`= 41 WHERE `creature_entry`= 417 AND `level`=40;
UPDATE `pet_levelstats` SET `str`= 77, `agi`= 58, `sta`=163, `inte`= 70, `spi`= 66, `armor`= 1414, `min_dmg`= 27, `max_dmg`= 42 WHERE `creature_entry`= 417 AND `level`=41;
UPDATE `pet_levelstats` SET `str`= 81, `agi`= 59, `sta`=156, `inte`= 70, `spi`= 67, `armor`= 1484, `min_dmg`= 28, `max_dmg`= 44 WHERE `creature_entry`= 417 AND `level`=42;
UPDATE `pet_levelstats` SET `str`= 86, `agi`= 61, `sta`=169, `inte`= 72, `spi`= 69, `armor`= 1709, `min_dmg`= 32, `max_dmg`= 50 WHERE `creature_entry`= 417 AND `level`=43;
UPDATE `pet_levelstats` SET `str`= 91, `agi`= 62, `sta`=169, `inte`= 69, `spi`= 70, `armor`= 1934, `min_dmg`= 37, `max_dmg`= 56 WHERE `creature_entry`= 417 AND `level`=44;
UPDATE `pet_levelstats` SET `str`= 96, `agi`= 64, `sta`=169, `inte`= 67, `spi`= 72, `armor`= 2159, `min_dmg`= 42, `max_dmg`= 63 WHERE `creature_entry`= 417 AND `level`=45;
UPDATE `pet_levelstats` SET `str`= 98, `agi`= 65, `sta`=173, `inte`= 77, `spi`= 73, `armor`= 2236, `min_dmg`= 47, `max_dmg`= 71 WHERE `creature_entry`= 417 AND `level`=46;
UPDATE `pet_levelstats` SET `str`=100, `agi`= 66, `sta`=177, `inte`= 78, `spi`= 75, `armor`= 2314, `min_dmg`= 53, `max_dmg`= 80 WHERE `creature_entry`= 417 AND `level`=47;
UPDATE `pet_levelstats` SET `str`=102, `agi`= 68, `sta`=181, `inte`= 80, `spi`= 76, `armor`= 2391, `min_dmg`= 59, `max_dmg`= 88 WHERE `creature_entry`= 417 AND `level`=48;
UPDATE `pet_levelstats` SET `str`=104, `agi`= 69, `sta`=186, `inte`= 82, `spi`= 78, `armor`= 2469, `min_dmg`= 65, `max_dmg`= 97 WHERE `creature_entry`= 417 AND `level`=49;
UPDATE `pet_levelstats` SET `str`=107, `agi`= 71, `sta`=190, `inte`= 84, `spi`= 80, `armor`= 2547, `min_dmg`= 70, `max_dmg`=105 WHERE `creature_entry`= 417 AND `level`=50;
UPDATE `pet_levelstats` SET `str`=109, `agi`= 72, `sta`=223, `inte`= 97, `spi`= 81, `armor`= 2624, `min_dmg`= 76, `max_dmg`=114 WHERE `creature_entry`= 417 AND `level`=51;
UPDATE `pet_levelstats` SET `str`=111, `agi`= 73, `sta`=228, `inte`=100, `spi`= 82, `armor`= 2702, `min_dmg`= 82, `max_dmg`=122 WHERE `creature_entry`= 417 AND `level`=52;
UPDATE `pet_levelstats` SET `str`=113, `agi`= 75, `sta`=233, `inte`=102, `spi`= 84, `armor`= 2780, `min_dmg`= 88, `max_dmg`=131 WHERE `creature_entry`= 417 AND `level`=53;
UPDATE `pet_levelstats` SET `str`=115, `agi`= 76, `sta`=207, `inte`= 90, `spi`= 85, `armor`= 2857, `min_dmg`= 93, `max_dmg`=139 WHERE `creature_entry`= 417 AND `level`=54;
UPDATE `pet_levelstats` SET `str`=117, `agi`= 77, `sta`=227, `inte`= 99, `spi`= 87, `armor`= 2935, `min_dmg`= 99, `max_dmg`=148 WHERE `creature_entry`= 417 AND `level`=55;
UPDATE `pet_levelstats` SET `str`=120, `agi`= 79, `sta`=248, `inte`=108, `spi`= 89, `armor`= 3013, `min_dmg`=105, `max_dmg`=156 WHERE `creature_entry`= 417 AND `level`=56;
UPDATE `pet_levelstats` SET `str`=122, `agi`= 80, `sta`=242, `inte`= 95, `spi`=108, `armor`= 3090, `min_dmg`=111, `max_dmg`=165 WHERE `creature_entry`= 417 AND `level`=57;
UPDATE `pet_levelstats` SET `str`=124, `agi`= 81, `sta`=236, `inte`= 82, `spi`=127, `armor`= 3168, `min_dmg`=116, `max_dmg`=173 WHERE `creature_entry`= 417 AND `level`=58;
UPDATE `pet_levelstats` SET `str`=127, `agi`= 83, `sta`=230, `inte`= 69, `spi`=147, `armor`= 3246, `min_dmg`=122, `max_dmg`=182 WHERE `creature_entry`= 417 AND `level`=59;
UPDATE `pet_levelstats` SET `str`=129, `agi`= 85, `sta`=249, `inte`= 70, `spi`=150, `armor`= 3323, `min_dmg`=128, `max_dmg`=190 WHERE `creature_entry`= 417 AND `level`=60;
UPDATE `pet_levelstats` SET `str`=131, `agi`= 60, `sta`=264, `inte`= 97, `spi`=126, `armor`= 3401, `min_dmg`=134, `max_dmg`=199 WHERE `creature_entry`= 417 AND `level`=61;
UPDATE `pet_levelstats` SET `str`=133, `agi`= 36, `sta`=279, `inte`=124, `spi`=102, `armor`= 3479, `min_dmg`=140, `max_dmg`=208 WHERE `creature_entry`= 417 AND `level`=62;
UPDATE `pet_levelstats` SET `str`=135, `agi`= 45, `sta`=279, `inte`=125, `spi`=104, `armor`= 3594, `min_dmg`=145, `max_dmg`=217 WHERE `creature_entry`= 417 AND `level`=63;
UPDATE `pet_levelstats` SET `str`=138, `agi`= 54, `sta`=279, `inte`=126, `spi`=107, `armor`= 3709, `min_dmg`=151, `max_dmg`=227 WHERE `creature_entry`= 417 AND `level`=64;
UPDATE `pet_levelstats` SET `str`=140, `agi`= 63, `sta`=279, `inte`=127, `spi`=109, `armor`= 3824, `min_dmg`=157, `max_dmg`=236 WHERE `creature_entry`= 417 AND `level`=65;
UPDATE `pet_levelstats` SET `str`=143, `agi`= 72, `sta`=279, `inte`=128, `spi`=112, `armor`= 3939, `min_dmg`=163, `max_dmg`=246 WHERE `creature_entry`= 417 AND `level`=66;
UPDATE `pet_levelstats` SET `str`=145, `agi`= 81, `sta`=279, `inte`=129, `spi`=114, `armor`= 4054, `min_dmg`=169, `max_dmg`=255 WHERE `creature_entry`= 417 AND `level`=67;
UPDATE `pet_levelstats` SET `str`=148, `agi`= 90, `sta`=279, `inte`=130, `spi`=117, `armor`= 4169, `min_dmg`=175, `max_dmg`=265 WHERE `creature_entry`= 417 AND `level`=68;
UPDATE `pet_levelstats` SET `str`=150, `agi`= 99, `sta`=279, `inte`=131, `spi`=119, `armor`= 4284, `min_dmg`=181, `max_dmg`=274 WHERE `creature_entry`= 417 AND `level`=69;
UPDATE `pet_levelstats` SET `str`=153, `agi`=109, `sta`=280, `inte`=133, `spi`=122, `armor`= 4400, `min_dmg`=187, `max_dmg`=284 WHERE `creature_entry`= 417 AND `level`=70;
UPDATE `pet_levelstats` SET `str`=163, `agi`=102, `sta`=284, `inte`=134, `spi`=134, `armor`= 4779, `min_dmg`=193, `max_dmg`=293 WHERE `creature_entry`= 417 AND `level`=71;
UPDATE `pet_levelstats` SET `str`=173, `agi`= 95, `sta`=289, `inte`=136, `spi`=146, `armor`= 5158, `min_dmg`=199, `max_dmg`=303 WHERE `creature_entry`= 417 AND `level`=72;
UPDATE `pet_levelstats` SET `str`=183, `agi`= 88, `sta`=294, `inte`=138, `spi`=159, `armor`= 5538, `min_dmg`=205, `max_dmg`=312 WHERE `creature_entry`= 417 AND `level`=73;
UPDATE `pet_levelstats` SET `str`=193, `agi`= 81, `sta`=299, `inte`=139, `spi`=171, `armor`= 5917, `min_dmg`=211, `max_dmg`=322 WHERE `creature_entry`= 417 AND `level`=74;
UPDATE `pet_levelstats` SET `str`=203, `agi`= 74, `sta`=304, `inte`=141, `spi`=183, `armor`= 6297, `min_dmg`=217, `max_dmg`=331 WHERE `creature_entry`= 417 AND `level`=75;
UPDATE `pet_levelstats` SET `str`=214, `agi`= 67, `sta`=309, `inte`=143, `spi`=196, `armor`= 6676, `min_dmg`=223, `max_dmg`=341 WHERE `creature_entry`= 417 AND `level`=76;
UPDATE `pet_levelstats` SET `str`=236, `agi`= 72, `sta`=314, `inte`=144, `spi`=200, `armor`= 7056, `min_dmg`=229, `max_dmg`=351 WHERE `creature_entry`= 417 AND `level`=77;
UPDATE `pet_levelstats` SET `str`=262, `agi`= 78, `sta`=318, `inte`=146, `spi`=203, `armor`= 7298, `min_dmg`=235, `max_dmg`=360 WHERE `creature_entry`= 417 AND `level`=78;
UPDATE `pet_levelstats` SET `str`=288, `agi`= 84, `sta`=323, `inte`=148, `spi`=206, `armor`= 7540, `min_dmg`=241, `max_dmg`=370 WHERE `creature_entry`= 417 AND `level`=79;
UPDATE `pet_levelstats` SET `str`=314, `agi`= 90, `sta`=328, `inte`=150, `spi`=209, `armor`= 7782, `min_dmg`=247, `max_dmg`=380 WHERE `creature_entry`= 417 AND `level`=80;
-- FELGUARD
UPDATE `pet_levelstats` SET `str`=107, `agi`= 71, `sta`=190, `inte`= 84, `spi`= 80, `armor`= 3494, `min_dmg`=113, `max_dmg`=149 WHERE `creature_entry`=17252 AND `level`=50;
UPDATE `pet_levelstats` SET `str`=109, `agi`= 72, `sta`=223, `inte`= 97, `spi`= 81, `armor`= 3559, `min_dmg`=122, `max_dmg`=160 WHERE `creature_entry`=17252 AND `level`=51;
UPDATE `pet_levelstats` SET `str`=111, `agi`= 73, `sta`=228, `inte`=100, `spi`= 82, `armor`= 3624, `min_dmg`=127, `max_dmg`=167 WHERE `creature_entry`=17252 AND `level`=52;
UPDATE `pet_levelstats` SET `str`=113, `agi`= 75, `sta`=233, `inte`=102, `spi`= 84, `armor`= 3686, `min_dmg`=129, `max_dmg`=169 WHERE `creature_entry`=17252 AND `level`=53;
UPDATE `pet_levelstats` SET `str`=115, `agi`= 76, `sta`=207, `inte`= 90, `spi`= 85, `armor`= 3750, `min_dmg`=131, `max_dmg`=171 WHERE `creature_entry`=17252 AND `level`=54;
UPDATE `pet_levelstats` SET `str`=117, `agi`= 77, `sta`=227, `inte`= 99, `spi`= 87, `armor`= 3814, `min_dmg`=133, `max_dmg`=173 WHERE `creature_entry`=17252 AND `level`=55;
UPDATE `pet_levelstats` SET `str`=120, `agi`= 79, `sta`=248, `inte`=108, `spi`= 89, `armor`= 3878, `min_dmg`=135, `max_dmg`=176 WHERE `creature_entry`=17252 AND `level`=56;
UPDATE `pet_levelstats` SET `str`=122, `agi`= 80, `sta`=242, `inte`= 95, `spi`=108, `armor`= 4277, `min_dmg`=152, `max_dmg`=201 WHERE `creature_entry`=17252 AND `level`=57;
UPDATE `pet_levelstats` SET `str`=124, `agi`= 81, `sta`=236, `inte`= 82, `spi`=127, `armor`= 4677, `min_dmg`=170, `max_dmg`=227 WHERE `creature_entry`=17252 AND `level`=58;
UPDATE `pet_levelstats` SET `str`=127, `agi`= 83, `sta`=230, `inte`= 69, `spi`=147, `armor`= 5077, `min_dmg`=187, `max_dmg`=252 WHERE `creature_entry`=17252 AND `level`=59;
UPDATE `pet_levelstats` SET `str`=129, `agi`= 85, `sta`=249, `inte`= 70, `spi`=150, `armor`= 5476, `min_dmg`=205, `max_dmg`=278 WHERE `creature_entry`=17252 AND `level`=60;
UPDATE `pet_levelstats` SET `str`=131, `agi`= 60, `sta`=264, `inte`= 97, `spi`=126, `armor`= 5876, `min_dmg`=222, `max_dmg`=303 WHERE `creature_entry`=17252 AND `level`=61;
UPDATE `pet_levelstats` SET `str`=133, `agi`= 36, `sta`=279, `inte`=124, `spi`=102, `armor`= 6276, `min_dmg`=240, `max_dmg`=329 WHERE `creature_entry`=17252 AND `level`=62;
UPDATE `pet_levelstats` SET `str`=135, `agi`= 45, `sta`=279, `inte`=125, `spi`=104, `armor`= 6482, `min_dmg`=244, `max_dmg`=338 WHERE `creature_entry`=17252 AND `level`=63;
UPDATE `pet_levelstats` SET `str`=138, `agi`= 54, `sta`=279, `inte`=126, `spi`=107, `armor`= 6688, `min_dmg`=249, `max_dmg`=347 WHERE `creature_entry`=17252 AND `level`=64;
UPDATE `pet_levelstats` SET `str`=140, `agi`= 63, `sta`=279, `inte`=127, `spi`=109, `armor`= 6895, `min_dmg`=254, `max_dmg`=356 WHERE `creature_entry`=17252 AND `level`=65;
UPDATE `pet_levelstats` SET `str`=143, `agi`= 72, `sta`=279, `inte`=128, `spi`=112, `armor`= 7101, `min_dmg`=259, `max_dmg`=365 WHERE `creature_entry`=17252 AND `level`=66;
UPDATE `pet_levelstats` SET `str`=145, `agi`= 81, `sta`=279, `inte`=129, `spi`=114, `armor`= 7307, `min_dmg`=264, `max_dmg`=375 WHERE `creature_entry`=17252 AND `level`=67;
UPDATE `pet_levelstats` SET `str`=148, `agi`= 90, `sta`=279, `inte`=130, `spi`=117, `armor`= 7514, `min_dmg`=269, `max_dmg`=384 WHERE `creature_entry`=17252 AND `level`=68;
UPDATE `pet_levelstats` SET `str`=150, `agi`= 99, `sta`=279, `inte`=131, `spi`=119, `armor`= 7720, `min_dmg`=274, `max_dmg`=393 WHERE `creature_entry`=17252 AND `level`=69;
UPDATE `pet_levelstats` SET `str`=153, `agi`=109, `sta`=280, `inte`=133, `spi`=122, `armor`= 7927, `min_dmg`=279, `max_dmg`=402 WHERE `creature_entry`=17252 AND `level`=70;
UPDATE `pet_levelstats` SET `str`=163, `agi`=102, `sta`=284, `inte`=134, `spi`=134, `armor`= 8537, `min_dmg`=284, `max_dmg`=412 WHERE `creature_entry`=17252 AND `level`=71;
UPDATE `pet_levelstats` SET `str`=173, `agi`= 95, `sta`=289, `inte`=136, `spi`=146, `armor`= 9148, `min_dmg`=289, `max_dmg`=421 WHERE `creature_entry`=17252 AND `level`=72;
UPDATE `pet_levelstats` SET `str`=183, `agi`= 88, `sta`=294, `inte`=138, `spi`=159, `armor`= 9758, `min_dmg`=294, `max_dmg`=430 WHERE `creature_entry`=17252 AND `level`=73;
UPDATE `pet_levelstats` SET `str`=193, `agi`= 81, `sta`=299, `inte`=139, `spi`=171, `armor`=10369, `min_dmg`=299, `max_dmg`=439 WHERE `creature_entry`=17252 AND `level`=74;
UPDATE `pet_levelstats` SET `str`=203, `agi`= 74, `sta`=304, `inte`=141, `spi`=183, `armor`=10980, `min_dmg`=304, `max_dmg`=448 WHERE `creature_entry`=17252 AND `level`=75;
UPDATE `pet_levelstats` SET `str`=214, `agi`= 67, `sta`=309, `inte`=143, `spi`=196, `armor`=11590, `min_dmg`=309, `max_dmg`=458 WHERE `creature_entry`=17252 AND `level`=76;
UPDATE `pet_levelstats` SET `str`=236, `agi`= 72, `sta`=314, `inte`=144, `spi`=200, `armor`=12201, `min_dmg`=314, `max_dmg`=467 WHERE `creature_entry`=17252 AND `level`=77;
UPDATE `pet_levelstats` SET `str`=262, `agi`= 78, `sta`=318, `inte`=146, `spi`=203, `armor`=12811, `min_dmg`=319, `max_dmg`=476 WHERE `creature_entry`=17252 AND `level`=78;
UPDATE `pet_levelstats` SET `str`=288, `agi`= 84, `sta`=323, `inte`=148, `spi`=206, `armor`=13422, `min_dmg`=324, `max_dmg`=485 WHERE `creature_entry`=17252 AND `level`=79;
UPDATE `pet_levelstats` SET `str`=314, `agi`= 90, `sta`=328, `inte`=150, `spi`=209, `armor`=14033, `min_dmg`=329, `max_dmg`=495 WHERE `creature_entry`=17252 AND `level`=80;

-- This change is needed otherwise Infernal gains hp, armor and damage from creature_classlevelstats where class = 1 and level = 68, as he is a guardian and not pet proper.
UPDATE `creature_template` SET `speed_walk`='1.0', `speed_run`='1.14286', `HealthModifier`='0', `ManaModifier`='0', `ArmorModifier`='0', `DamageModifier`='0', `ExperienceModifier`='0' WHERE `entry`='89';

-- Immolation and Avoidance
UPDATE `creature_template_addon` SET `auras`='19483 32233' WHERE `entry`='89';

-- Infernal stats
DELETE FROM `pet_levelstats` WHERE `creature_entry`=89;
INSERT INTO `pet_levelstats` ( `creature_entry`, `level`, `hp`, `mana`, `armor`, `str`, `agi`, `sta`, `inte`, `spi`, `min_dmg`, `max_dmg`) VALUES
(89,  1,    40, 0,     0,   0,   0,   0,   0,   0,    0,    0),
(89,  2,   301, 0,     0,   3,   1,   3,   2,   3,   10,   15),
(89,  3,   563, 0,     0,   6,   2,   6,   5,   6,   20,   30),
(89,  4,   825, 0,     0,   9,   3,   9,   8,   9,   30,   45),
(89,  5,  1087, 0,     0,  12,   4,  12,  11,  12,   40,   60),
(89,  6,  1349, 0,     0,  16,   5,  16,  13,  15,   50,   76),
(89,  7,  1611, 0,     0,  19,   6,  19,  16,  18,   60,   91),
(89,  8,  1873, 0,     0,  22,   7,  22,  19,  21,   71,  106),
(89,  9,  2135, 0,     0,  25,   8,  25,  22,  24,   81,  121),
(89, 10,  2397, 0,   831,  29,  10,  29,  25,  27,   91,  136),
(89, 11,  2658, 0,   875,  30,  10,  32,  26,  28,  101,  152),
(89, 12,  2920, 0,   876,  31,  26,  36,  24,  31,  111,  167),
(89, 13,  3182, 0,   877,  32,  28,  43,  26,  32,  121,  182),
(89, 14,  3444, 0,   878,  33,  28,  44,  25,  35,  131,  197),
(89, 15,  3706, 0,   925,  34,  30,  48,  26,  37,  142,  212),
(89, 16,  3968, 0,   975,  36,  30,  52,  27,  39,  152,  228),
(89, 17,  4230, 0,  1022,  38,  31,  55,  28,  42,  162,  243),
(89, 18,  4492, 0,  1068,  39,  33,  59,  28,  44,  172,  258),
(89, 19,  4754, 0,  1120,  40,  33,  63,  30,  46,  182,  273),
(89, 20,  5016, 0,  1165,  42,  35,  67,  31,  49,  192,  288),
(89, 21,  5277, 0,  1232,  44,  36,  80,  53,  39,  202,  304),
(89, 22,  5539, 0,  1282,  46,  36,  84,  54,  41,  213,  319),
(89, 23,  5801, 0,  1330,  47,  38,  89,  56,  42,  223,  334),
(89, 24,  6063, 0,  1378,  49,  39,  93,  57,  43,  233,  349),
(89, 25,  6325, 0,  1427,  50,  40,  97,  60,  44,  243,  364),
(89, 26,  6587, 0,  1474,  52,  41, 101,  62,  46,  253,  380),
(89, 27,  6849, 0,  1524,  53,  42, 105,  63,  47,  263,  395),
(89, 28,  7111, 0,  1572,  55,  43, 110,  65,  48,  273,  410),
(89, 29,  7373, 0,  1619,  57,  44, 114,  67,  49,  284,  425),
(89, 30,  7635, 0,  1667,  57,  46, 118,  69,  51,  294,  440),
(89, 31,  7896, 0,  1715,  59,  47, 123,  71,  52,  304,  456),
(89, 32,  8158, 0,  1766,  60,  47, 127,  73,  53,  314,  471),
(89, 33,  8420, 0,  1812,  62,  49, 131,  74,  54,  324,  486),
(89, 34,  8682, 0,  1861,  63,  50, 135,  76,  56,  334,  501),
(89, 35,  8944, 0,  2238,  65,  51, 146,  62,  57,  344,  516),
(89, 36,  9206, 0,  2415,  66,  52, 150,  63,  59,  355,  532),
(89, 37,  9468, 0,  2602,  68,  53, 155,  64,  60,  365,  547),
(89, 38,  9730, 0,  2795,  70,  55, 159,  66,  62,  375,  562),
(89, 39,  9992, 0,  3002,  72,  56, 164,  67,  63,  385,  577),
(89, 40, 10254, 0,  3219,  74,  57, 170,  70,  65,  395,  592),
(89, 41, 10515, 0,  3222,  77,  58, 163,  70,  66,  405,  608),
(89, 42, 10777, 0,  3225,  81,  59, 156,  70,  67,  415,  623),
(89, 43, 11039, 0,  3228,  86,  61, 169,  72,  69,  426,  638),
(89, 44, 11301, 0,  3392,  91,  62, 169,  69,  70,  436,  653),
(89, 45, 11563, 0,  3557,  96,  64, 169,  67,  72,  446,  668),
(89, 46, 11825, 0,  3722,  98,  65, 173,  77,  73,  456,  684),
(89, 47, 12087, 0,  3796, 100,  66, 177,  78,  75,  466,  699),
(89, 48, 12349, 0,  3868, 102,  68, 181,  80,  76,  476,  714),
(89, 49, 12611, 0,  3943, 104,  69, 186,  82,  78,  486,  729),
(89, 50, 12873, 0,  4013, 107,  71, 190,  84,  80,  497,  745),
(89, 51, 13042, 0,  4086, 109,  72, 223,  97,  81,  525,  788),
(89, 52, 13556, 0,  4160, 111,  73, 228, 100,  82,  552,  827),
(89, 53, 14045, 0,  4233, 113,  75, 233, 102,  84,  582,  873),
(89, 54, 14468, 0,  4307, 115,  76, 207,  90,  85,  611,  916),
(89, 55, 14651, 0,  4380, 117,  77, 227,  99,  87,  637,  956),
(89, 56, 15314, 0,  4453, 120,  79, 248, 108,  89,  668, 1002),
(89, 57, 15843, 0,  4526, 122,  80, 242,  95, 108,  697, 1045),
(89, 58, 16414, 0,  4599, 124,  81, 236,  82, 127,  725, 1088),
(89, 59, 16903, 0,  4673, 127,  83, 230,  69, 147,  754, 1130),
(89, 60, 17418, 0,  4745, 129,  85, 249,  70, 150,  782, 1173),
(89, 61, 17942, 0,  5984, 131,  60, 264,  97, 126,  811, 1216),
(89, 62, 18477, 0,  7223, 133,  36, 279, 124, 102,  842, 1262),
(89, 63, 18982, 0,  7453, 135,  45, 279, 125, 104,  877, 1315),
(89, 64, 19511, 0,  7684, 138,  54, 279, 126, 107,  912, 1368),
(89, 65, 20041, 0,  7915, 140,  63, 279, 127, 109,  949, 1424),
(89, 66, 21116, 0,  8146, 143,  72, 279, 128, 112,  987, 1480),
(89, 67, 22013, 0,  8377, 145,  81, 279, 129, 114, 1024, 1536),
(89, 68, 23072, 0,  8608, 148,  90, 279, 130, 117, 1059, 1589),
(89, 69, 24270, 0,  8839, 150,  99, 279, 131, 119, 1099, 1648),
(89, 70, 24759, 0,  9070, 153, 109, 280, 133, 122, 1134, 1701),
(89, 71, 25523, 0,  9917, 163, 102, 284, 134, 134, 1169, 1753),
(89, 72, 26292, 0, 10765, 173,  95, 289, 136, 146, 1206, 1809),
(89, 73, 27066, 0, 11612, 183,  88, 294, 138, 159, 1244, 1865),
(89, 74, 27846, 0, 12460, 193,  81, 299, 139, 171, 1281, 1921),
(89, 75, 28630, 0, 13307, 203,  74, 304, 141, 183, 1316, 1974),
(89, 76, 29420, 0, 14155, 214,  67, 309, 143, 196, 1356, 2034),
(89, 77, 30210, 0, 14652, 236,  72, 314, 144, 200, 1391, 2086),
(89, 78, 31004, 0, 15150, 262,  78, 318, 146, 203, 1430, 2146),
(89, 79, 31804, 0, 15649, 288,  84, 323, 148, 206, 1470, 2205),
(89, 80, 32609, 0, 16148, 314,  90, 328, 150, 209, 1509, 2264);

