-- Update Rogue stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 4 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(4, 71, 2149, 2589, 9512, 1761, 0),
(4, 72, 2662, 3207, 12221, 2181, 0),
(4, 73, 3298, 3974, 15683, 2702, 0),
(4, 74, 4087, 4924, 20101, 3348, 0),
(4, 75, 5064, 6101, 25735, 4149, 0),
(4, 76, 6274, 7559, 32915, 5140, 0),
(4, 77, 7773, 9365, 42055, 6368, 0),
(4, 78, 9630, 11603, 53685, 7890, 0),
(4, 79, 11932, 14376, 68472, 9776, 0),
(4, 80, 14647, 17647, 86452, 12000, 0);

UPDATE `player_classlevelstats` SET `str` = 14, `agi` = 17, `sta` = 62, `inte` = 14 WHERE `class` = 4 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 16, `agi` = 19, `sta` = 69, `inte` = 15 WHERE `class` = 4 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 21, `sta` = 75, `inte` = 16 WHERE `class` = 4 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 23, `sta` = 81, `inte` = 18 WHERE `class` = 4 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 20, `agi` = 25, `sta` = 87, `inte` = 19 WHERE `class` = 4 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 27, `sta` = 94, `inte` = 20 WHERE `class` = 4 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 23, `agi` = 29, `sta` = 100, `inte` = 22 WHERE `class` = 4 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 30, `sta` = 106, `inte` = 23 WHERE `class` = 4 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 25, `agi` = 31, `sta` = 112, `inte` = 24 WHERE `class` = 4 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 27, `agi` = 33, `sta` = 118, `inte` = 26 WHERE `class` = 4 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 36, `sta` = 125, `inte` = 27 WHERE `class` = 4 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 32, `agi` = 39, `sta` = 131, `inte` = 29 WHERE `class` = 4 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 43, `sta` = 137, `inte` = 30 WHERE `class` = 4 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 38, `agi` = 46, `sta` = 143, `inte` = 31 WHERE `class` = 4 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 40, `agi` = 48, `sta` = 150, `inte` = 33 WHERE `class` = 4 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 50, `sta` = 156, `inte` = 34 WHERE `class` = 4 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 43, `agi` = 52, `sta` = 162, `inte` = 35 WHERE `class` = 4 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 45, `agi` = 54, `sta` = 168, `inte` = 37 WHERE `class` = 4 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 46, `agi` = 56, `sta` = 175, `inte` = 38 WHERE `class` = 4 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 48, `agi` = 58, `sta` = 181, `inte` = 39 WHERE `class` = 4 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 50, `agi` = 60, `sta` = 188, `inte` = 41 WHERE `class` = 4 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 63, `sta` = 197, `inte` = 43 WHERE `class` = 4 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 55, `agi` = 66, `sta` = 206, `inte` = 45 WHERE `class` = 4 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 57, `agi` = 69, `sta` = 215, `inte` = 47 WHERE `class` = 4 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 60, `agi` = 73, `sta` = 226, `inte` = 49 WHERE `class` = 4 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 63, `agi` = 76, `sta` = 238, `inte` = 52 WHERE `class` = 4 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 67, `agi` = 80, `sta` = 251, `inte` = 55 WHERE `class` = 4 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 70, `agi` = 85, `sta` = 264, `inte` = 58 WHERE `class` = 4 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 74, `agi` = 90, `sta` = 280, `inte` = 61 WHERE `class` = 4 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 79, `agi` = 95, `sta` = 296, `inte` = 65 WHERE `class` = 4 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 84, `agi` = 101, `sta` = 314, `inte` = 69 WHERE `class` = 4 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 89, `agi` = 107, `sta` = 334, `inte` = 73 WHERE `class` = 4 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 95, `agi` = 114, `sta` = 356, `inte` = 78 WHERE `class` = 4 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 101, `agi` = 122, `sta` = 380, `inte` = 83 WHERE `class` = 4 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 108, `agi` = 130, `sta` = 406, `inte` = 89 WHERE `class` = 4 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 116, `agi` = 139, `sta` = 435, `inte` = 95 WHERE `class` = 4 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 124, `agi` = 150, `sta` = 466, `inte` = 102 WHERE `class` = 4 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 133, `agi` = 161, `sta` = 501, `inte` = 109 WHERE `class` = 4 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 144, `agi` = 173, `sta` = 540, `inte` = 118 WHERE `class` = 4 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 155, `agi` = 187, `sta` = 582, `inte` = 127 WHERE `class` = 4 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 167, `agi` = 202, `sta` = 629, `inte` = 137 WHERE `class` = 4 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 181, `agi` = 218, `sta` = 681, `inte` = 149 WHERE `class` = 4 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 197, `agi` = 237, `sta` = 738, `inte` = 161 WHERE `class` = 4 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 214, `agi` = 257, `sta` = 802, `inte` = 175 WHERE `class` = 4 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 232, `agi` = 280, `sta` = 873, `inte` = 190 WHERE `class` = 4 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 253, `agi` = 305, `sta` = 952, `inte` = 208 WHERE `class` = 4 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 277, `agi` = 333, `sta` = 1039, `inte` = 227 WHERE `class` = 4 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 303, `agi` = 365, `sta` = 1137, `inte` = 248 WHERE `class` = 4 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 332, `agi` = 400, `sta` = 1246, `inte` = 272 WHERE `class` = 4 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 364, `agi` = 439, `sta` = 1368, `inte` = 298 WHERE `class` = 4 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 401, `agi` = 483, `sta` = 1505, `inte` = 328 WHERE `class` = 4 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 441, `agi` = 532, `sta` = 1658, `inte` = 362 WHERE `class` = 4 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 487, `agi` = 587, `sta` = 1830, `inte` = 399 WHERE `class` = 4 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 539, `agi` = 649, `sta` = 2023, `inte` = 441 WHERE `class` = 4 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 597, `agi` = 719, `sta` = 2240, `inte` = 489 WHERE `class` = 4 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 662, `agi` = 797, `sta` = 2486, `inte` = 542 WHERE `class` = 4 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 736, `agi` = 886, `sta` = 2763, `inte` = 603 WHERE `class` = 4 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 819, `agi` = 987, `sta` = 3076, `inte` = 671 WHERE `class` = 4 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 913, `agi` = 1100, `sta` = 3430, `inte` = 748 WHERE `class` = 4 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 1020, `agi` = 1229, `sta` = 4024, `inte` = 836 WHERE `class` = 4 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 1076, `agi` = 1296, `sta` = 4255, `inte` = 881 WHERE `class` = 4 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 1135, `agi` = 1367, `sta` = 4500, `inte` = 930 WHERE `class` = 4 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 1196, `agi` = 1441, `sta` = 4758, `inte` = 980 WHERE `class` = 4 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 1262, `agi` = 1520, `sta` = 5032, `inte` = 1034 WHERE `class` = 4 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 1330, `agi` = 1603, `sta` = 5321, `inte` = 1090 WHERE `class` = 4 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 1403, `agi` = 1690, `sta` = 5627, `inte` = 1149 WHERE `class` = 4 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 1479, `agi` = 1782, `sta` = 5951, `inte` = 1212 WHERE `class` = 4 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 1560, `agi` = 1879, `sta` = 6293, `inte` = 1278 WHERE `class` = 4 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 1645, `agi` = 1981, `sta` = 6655, `inte` = 1347 WHERE `class` = 4 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 1734, `agi` = 2089, `sta` = 6397, `inte` = 1421 WHERE `class` = 4 AND `Level` = 70;