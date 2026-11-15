-- Update Mage stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 8 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(8, 71, 1139, 1760, 9512, 2589, 0),
(8, 72, 1411, 2181, 12221, 3207, 0),
(8, 73, 1749, 2702, 15683, 3974, 0),
(8, 74, 2166, 3348, 20101, 4924, 0),
(8, 75, 2684, 4148, 25735, 6101, 0),
(8, 76, 3326, 5140, 32915, 7559, 0),
(8, 77, 4121, 6368, 42055, 9365, 0),
(8, 78, 5105, 7890, 53685, 11603, 0),
(8, 79, 6326, 9776, 68472, 14376, 0),
(8, 80, 7765, 12000, 86452, 17647, 0);

UPDATE `player_classlevelstats` SET `str` = 7, `agi` = 12, `sta` = 50, `inte` = 20 WHERE `class` = 8 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 8, `agi` = 13, `sta` = 56, `inte` = 22 WHERE `class` = 8 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 9, `agi` = 15, `sta` = 62, `inte` = 24 WHERE `class` = 8 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 10, `agi` = 16, `sta` = 68, `inte` = 26 WHERE `class` = 8 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 17, `sta` = 74, `inte` = 28 WHERE `class` = 8 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 18, `sta` = 80, `inte` = 30 WHERE `class` = 8 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 12, `agi` = 19, `sta` = 87, `inte` = 32 WHERE `class` = 8 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 20, `sta` = 93, `inte` = 34 WHERE `class` = 8 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 21, `sta` = 100, `inte` = 36 WHERE `class` = 8 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 15, `agi` = 23, `sta` = 107, `inte` = 38 WHERE `class` = 8 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 16, `agi` = 24, `sta` = 113, `inte` = 40 WHERE `class` = 8 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 26, `sta` = 120, `inte` = 42 WHERE `class` = 8 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 29, `sta` = 128, `inte` = 44 WHERE `class` = 8 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 20, `agi` = 31, `sta` = 135, `inte` = 46 WHERE `class` = 8 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 33, `sta` = 142, `inte` = 48 WHERE `class` = 8 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 34, `sta` = 150, `inte` = 50 WHERE `class` = 8 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 23, `agi` = 35, `sta` = 157, `inte` = 52 WHERE `class` = 8 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 37, `sta` = 165, `inte` = 54 WHERE `class` = 8 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 25, `agi` = 38, `sta` = 173, `inte` = 56 WHERE `class` = 8 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 26, `agi` = 39, `sta` = 181, `inte` = 58 WHERE `class` = 8 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 27, `agi` = 41, `sta` = 188, `inte` = 60 WHERE `class` = 8 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 43, `sta` = 197, `inte` = 63 WHERE `class` = 8 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 45, `sta` = 206, `inte` = 66 WHERE `class` = 8 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 30, `agi` = 47, `sta` = 215, `inte` = 69 WHERE `class` = 8 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 32, `agi` = 49, `sta` = 226, `inte` = 73 WHERE `class` = 8 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 34, `agi` = 52, `sta` = 238, `inte` = 76 WHERE `class` = 8 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 55, `sta` = 251, `inte` = 80 WHERE `class` = 8 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 37, `agi` = 58, `sta` = 264, `inte` = 85 WHERE `class` = 8 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 39, `agi` = 61, `sta` = 280, `inte` = 90 WHERE `class` = 8 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 65, `sta` = 296, `inte` = 95 WHERE `class` = 8 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 44, `agi` = 69, `sta` = 314, `inte` = 101 WHERE `class` = 8 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 47, `agi` = 73, `sta` = 334, `inte` = 107 WHERE `class` = 8 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 50, `agi` = 78, `sta` = 356, `inte` = 114 WHERE `class` = 8 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 54, `agi` = 83, `sta` = 380, `inte` = 122 WHERE `class` = 8 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 57, `agi` = 89, `sta` = 406, `inte` = 130 WHERE `class` = 8 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 61, `agi` = 95, `sta` = 435, `inte` = 139 WHERE `class` = 8 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 66, `agi` = 102, `sta` = 466, `inte` = 150 WHERE `class` = 8 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 71, `agi` = 109, `sta` = 501, `inte` = 161 WHERE `class` = 8 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 76, `agi` = 118, `sta` = 540, `inte` = 173 WHERE `class` = 8 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 82, `agi` = 127, `sta` = 582, `inte` = 187 WHERE `class` = 8 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 89, `agi` = 137, `sta` = 629, `inte` = 202 WHERE `class` = 8 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 96, `agi` = 149, `sta` = 681, `inte` = 218 WHERE `class` = 8 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 104, `agi` = 161, `sta` = 738, `inte` = 237 WHERE `class` = 8 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 113, `agi` = 175, `sta` = 802, `inte` = 257 WHERE `class` = 8 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 123, `agi` = 190, `sta` = 873, `inte` = 280 WHERE `class` = 8 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 134, `agi` = 208, `sta` = 952, `inte` = 305 WHERE `class` = 8 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 147, `agi` = 227, `sta` = 1039, `inte` = 333 WHERE `class` = 8 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 160, `agi` = 248, `sta` = 1137, `inte` = 365 WHERE `class` = 8 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 176, `agi` = 272, `sta` = 1246, `inte` = 400 WHERE `class` = 8 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 193, `agi` = 298, `sta` = 1368, `inte` = 439 WHERE `class` = 8 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 212, `agi` = 328, `sta` = 1505, `inte` = 483 WHERE `class` = 8 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 234, `agi` = 362, `sta` = 1658, `inte` = 532 WHERE `class` = 8 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 258, `agi` = 399, `sta` = 1830, `inte` = 587 WHERE `class` = 8 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 286, `agi` = 441, `sta` = 2023, `inte` = 649 WHERE `class` = 8 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 316, `agi` = 489, `sta` = 2240, `inte` = 719 WHERE `class` = 8 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 351, `agi` = 542, `sta` = 2486, `inte` = 797 WHERE `class` = 8 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 390, `agi` = 603, `sta` = 2763, `inte` = 886 WHERE `class` = 8 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 434, `agi` = 671, `sta` = 3076, `inte` = 987 WHERE `class` = 8 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 484, `agi` = 748, `sta` = 3430, `inte` = 1100 WHERE `class` = 8 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 541, `agi` = 836, `sta` = 4024, `inte` = 1229 WHERE `class` = 8 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 570, `agi` = 881, `sta` = 4255, `inte` = 1296 WHERE `class` = 8 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 601, `agi` = 930, `sta` = 4500, `inte` = 1367 WHERE `class` = 8 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 634, `agi` = 980, `sta` = 4758, `inte` = 1441 WHERE `class` = 8 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 669, `agi` = 1034, `sta` = 5032, `inte` = 1520 WHERE `class` = 8 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 705, `agi` = 1090, `sta` = 5321, `inte` = 1603 WHERE `class` = 8 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 744, `agi` = 1149, `sta` = 5627, `inte` = 1690 WHERE `class` = 8 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 784, `agi` = 1212, `sta` = 5951, `inte` = 1782 WHERE `class` = 8 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 827, `agi` = 1278, `sta` = 6293, `inte` = 1879 WHERE `class` = 8 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 872, `agi` = 1347, `sta` = 6655, `inte` = 1981 WHERE `class` = 8 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 919, `agi` = 1421, `sta` = 6397, `inte` = 2089 WHERE `class` = 8 AND `Level` = 70;