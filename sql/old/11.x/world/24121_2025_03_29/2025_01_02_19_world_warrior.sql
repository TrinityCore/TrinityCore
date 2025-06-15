-- Update Warrior stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 1 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(1, 71, 2589, 1786, 9512, 1761, 0),
(1, 72, 3207, 2213, 12221, 2181, 0),
(1, 73, 3974, 2742, 15683, 2702, 0),
(1, 74, 4924, 3398, 20101, 3348, 0),
(1, 75, 6101, 4210, 25735, 4149, 0),
(1, 76, 7559, 5216, 32915, 5140, 0),
(1, 77, 9365, 6462, 42055, 6368, 0),
(1, 78, 11603, 8006, 53685, 7890, 0),
(1, 79, 14376, 9919, 68472, 9776, 0),
(1, 80, 17647, 12176, 86452, 12000, 0);

UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 12, `sta` = 74, `inte` = 14 WHERE `class` = 1 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 13, `sta` = 81, `inte` = 15 WHERE `class` = 1 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 15, `sta` = 88, `inte` = 16 WHERE `class` = 1 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 16, `sta` = 96, `inte` = 18 WHERE `class` = 1 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 17, `sta` = 100, `inte` = 19 WHERE `class` = 1 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 26, `agi` = 18, `sta` = 107, `inte` = 20 WHERE `class` = 1 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 20, `sta` = 113, `inte` = 22 WHERE `class` = 1 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 21, `sta` = 119, `inte` = 23 WHERE `class` = 1 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 21, `sta` = 125, `inte` = 24 WHERE `class` = 1 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 33, `agi` = 23, `sta` = 130, `inte` = 26 WHERE `class` = 1 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 25, `sta` = 136, `inte` = 27 WHERE `class` = 1 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 39, `agi` = 27, `sta` = 141, `inte` = 29 WHERE `class` = 1 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 29, `sta` = 147, `inte` = 30 WHERE `class` = 1 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 46, `agi` = 32, `sta` = 152, `inte` = 31 WHERE `class` = 1 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 48, `agi` = 33, `sta` = 157, `inte` = 33 WHERE `class` = 1 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 50, `agi` = 35, `sta` = 162, `inte` = 34 WHERE `class` = 1 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 36, `sta` = 167, `inte` = 35 WHERE `class` = 1 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 54, `agi` = 37, `sta` = 172, `inte` = 37 WHERE `class` = 1 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 56, `agi` = 39, `sta` = 176, `inte` = 38 WHERE `class` = 1 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 58, `agi` = 40, `sta` = 181, `inte` = 39 WHERE `class` = 1 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 60, `agi` = 42, `sta` = 188, `inte` = 41 WHERE `class` = 1 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 63, `agi` = 44, `sta` = 197, `inte` = 43 WHERE `class` = 1 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 66, `agi` = 46, `sta` = 206, `inte` = 45 WHERE `class` = 1 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 69, `agi` = 48, `sta` = 215, `inte` = 47 WHERE `class` = 1 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 73, `agi` = 50, `sta` = 226, `inte` = 49 WHERE `class` = 1 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 76, `agi` = 53, `sta` = 238, `inte` = 52 WHERE `class` = 1 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 80, `agi` = 55, `sta` = 251, `inte` = 55 WHERE `class` = 1 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 85, `agi` = 59, `sta` = 264, `inte` = 58 WHERE `class` = 1 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 90, `agi` = 62, `sta` = 280, `inte` = 61 WHERE `class` = 1 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 95, `agi` = 66, `sta` = 296, `inte` = 65 WHERE `class` = 1 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 101, `agi` = 70, `sta` = 314, `inte` = 69 WHERE `class` = 1 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 107, `agi` = 74, `sta` = 334, `inte` = 73 WHERE `class` = 1 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 114, `agi` = 79, `sta` = 356, `inte` = 78 WHERE `class` = 1 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 122, `agi` = 84, `sta` = 380, `inte` = 83 WHERE `class` = 1 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 130, `agi` = 90, `sta` = 406, `inte` = 89 WHERE `class` = 1 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 139, `agi` = 96, `sta` = 435, `inte` = 95 WHERE `class` = 1 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 150, `agi` = 103, `sta` = 466, `inte` = 102 WHERE `class` = 1 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 161, `agi` = 111, `sta` = 501, `inte` = 109 WHERE `class` = 1 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 173, `agi` = 119, `sta` = 540, `inte` = 118 WHERE `class` = 1 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 187, `agi` = 129, `sta` = 582, `inte` = 127 WHERE `class` = 1 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 202, `agi` = 139, `sta` = 629, `inte` = 137 WHERE `class` = 1 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 218, `agi` = 151, `sta` = 681, `inte` = 149 WHERE `class` = 1 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 237, `agi` = 163, `sta` = 738, `inte` = 161 WHERE `class` = 1 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 257, `agi` = 178, `sta` = 802, `inte` = 175 WHERE `class` = 1 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 280, `agi` = 193, `sta` = 873, `inte` = 190 WHERE `class` = 1 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 305, `agi` = 211, `sta` = 952, `inte` = 208 WHERE `class` = 1 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 333, `agi` = 230, `sta` = 1039, `inte` = 227 WHERE `class` = 1 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 365, `agi` = 252, `sta` = 1137, `inte` = 248 WHERE `class` = 1 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 400, `agi` = 276, `sta` = 1246, `inte` = 272 WHERE `class` = 1 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 439, `agi` = 303, `sta` = 1368, `inte` = 298 WHERE `class` = 1 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 483, `agi` = 333, `sta` = 1505, `inte` = 328 WHERE `class` = 1 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 532, `agi` = 367, `sta` = 1658, `inte` = 362 WHERE `class` = 1 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 587, `agi` = 405, `sta` = 1830, `inte` = 399 WHERE `class` = 1 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 649, `agi` = 448, `sta` = 2023, `inte` = 441 WHERE `class` = 1 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 719, `agi` = 496, `sta` = 2240, `inte` = 489 WHERE `class` = 1 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 797, `agi` = 550, `sta` = 2486, `inte` = 542 WHERE `class` = 1 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 886, `agi` = 611, `sta` = 2763, `inte` = 603 WHERE `class` = 1 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 987, `agi` = 681, `sta` = 3076, `inte` = 671 WHERE `class` = 1 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 1100, `agi` = 759, `sta` = 3430, `inte` = 748 WHERE `class` = 1 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 1229, `agi` = 848, `sta` = 4024, `inte` = 836 WHERE `class` = 1 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 1296, `agi` = 894, `sta` = 4255, `inte` = 881 WHERE `class` = 1 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 1367, `agi` = 943, `sta` = 4500, `inte` = 930 WHERE `class` = 1 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 1441, `agi` = 995, `sta` = 4758, `inte` = 980 WHERE `class` = 1 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 1520, `agi` = 1049, `sta` = 5032, `inte` = 1034 WHERE `class` = 1 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 1603, `agi` = 1106, `sta` = 5321, `inte` = 1090 WHERE `class` = 1 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 1690, `agi` = 1166, `sta` = 5627, `inte` = 1149 WHERE `class` = 1 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 1782, `agi` = 1230, `sta` = 5951, `inte` = 1212 WHERE `class` = 1 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 1879, `agi` = 1297, `sta` = 6293, `inte` = 1278 WHERE `class` = 1 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 1981, `agi` = 1367, `sta` = 6655, `inte` = 1347 WHERE `class` = 1 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 2089, `agi` = 1442, `sta` = 6397, `inte` = 1421 WHERE `class` = 1 AND `Level` = 70;