-- Update Priest stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 5 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(5, 71, 1502, 2149, 9512, 2589, 0),
(5, 72, 1860, 2662, 12221, 3207, 0),
(5, 73, 2305, 3298, 15683, 3974, 0),
(5, 74, 2856, 4087, 20101, 4924, 0),
(5, 75, 3539, 5064, 25735, 6101, 0),
(5, 76, 4384, 6274, 32915, 7559, 0),
(5, 77, 5432, 7773, 42055, 9365, 0),
(5, 78, 6730, 9630, 53685, 11603, 0),
(5, 79, 8338, 11932, 68472, 14376, 0),
(5, 80, 10235, 14647, 86452, 17647, 0);

UPDATE `player_classlevelstats` SET `str` = 10, `agi` = 14, `sta` = 62, `inte` = 20 WHERE `class` = 5 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 16, `sta` = 69, `inte` = 22 WHERE `class` = 5 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 12, `agi` = 18, `sta` = 75, `inte` = 24 WHERE `class` = 5 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 19, `sta` = 81, `inte` = 26 WHERE `class` = 5 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 14, `agi` = 21, `sta` = 87, `inte` = 28 WHERE `class` = 5 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 15, `agi` = 22, `sta` = 94, `inte` = 30 WHERE `class` = 5 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 16, `agi` = 24, `sta` = 100, `inte` = 32 WHERE `class` = 5 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 25, `sta` = 106, `inte` = 34 WHERE `class` = 5 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 18, `agi` = 26, `sta` = 112, `inte` = 36 WHERE `class` = 5 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 28, `sta` = 118, `inte` = 38 WHERE `class` = 5 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 20, `agi` = 30, `sta` = 125, `inte` = 40 WHERE `class` = 5 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 32, `sta` = 131, `inte` = 42 WHERE `class` = 5 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 25, `agi` = 35, `sta` = 137, `inte` = 44 WHERE `class` = 5 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 27, `agi` = 38, `sta` = 143, `inte` = 46 WHERE `class` = 5 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 40, `sta` = 150, `inte` = 48 WHERE `class` = 5 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 42, `sta` = 156, `inte` = 50 WHERE `class` = 5 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 30, `agi` = 43, `sta` = 162, `inte` = 52 WHERE `class` = 5 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 45, `sta` = 168, `inte` = 54 WHERE `class` = 5 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 32, `agi` = 46, `sta` = 175, `inte` = 56 WHERE `class` = 5 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 34, `agi` = 48, `sta` = 181, `inte` = 58 WHERE `class` = 5 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 50, `sta` = 188, `inte` = 60 WHERE `class` = 5 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 37, `agi` = 52, `sta` = 197, `inte` = 63 WHERE `class` = 5 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 38, `agi` = 55, `sta` = 206, `inte` = 66 WHERE `class` = 5 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 40, `agi` = 57, `sta` = 215, `inte` = 69 WHERE `class` = 5 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 60, `sta` = 226, `inte` = 73 WHERE `class` = 5 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 44, `agi` = 63, `sta` = 238, `inte` = 76 WHERE `class` = 5 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 47, `agi` = 67, `sta` = 251, `inte` = 80 WHERE `class` = 5 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 49, `agi` = 70, `sta` = 264, `inte` = 85 WHERE `class` = 5 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 74, `sta` = 280, `inte` = 90 WHERE `class` = 5 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 55, `agi` = 79, `sta` = 296, `inte` = 95 WHERE `class` = 5 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 58, `agi` = 84, `sta` = 314, `inte` = 101 WHERE `class` = 5 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 62, `agi` = 89, `sta` = 334, `inte` = 107 WHERE `class` = 5 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 67, `agi` = 95, `sta` = 356, `inte` = 114 WHERE `class` = 5 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 72, `agi` = 101, `sta` = 380, `inte` = 122 WHERE `class` = 5 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 76, `agi` = 108, `sta` = 406, `inte` = 130 WHERE `class` = 5 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 81, `agi` = 116, `sta` = 435, `inte` = 139 WHERE `class` = 5 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 87, `agi` = 124, `sta` = 466, `inte` = 150 WHERE `class` = 5 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 93, `agi` = 133, `sta` = 501, `inte` = 161 WHERE `class` = 5 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 100, `agi` = 144, `sta` = 540, `inte` = 173 WHERE `class` = 5 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 108, `agi` = 155, `sta` = 582, `inte` = 187 WHERE `class` = 5 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 117, `agi` = 167, `sta` = 629, `inte` = 202 WHERE `class` = 5 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 127, `agi` = 181, `sta` = 681, `inte` = 218 WHERE `class` = 5 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 137, `agi` = 197, `sta` = 738, `inte` = 237 WHERE `class` = 5 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 149, `agi` = 214, `sta` = 802, `inte` = 257 WHERE `class` = 5 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 162, `agi` = 232, `sta` = 873, `inte` = 280 WHERE `class` = 5 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 177, `agi` = 253, `sta` = 952, `inte` = 305 WHERE `class` = 5 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 193, `agi` = 277, `sta` = 1039, `inte` = 333 WHERE `class` = 5 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 212, `agi` = 303, `sta` = 1137, `inte` = 365 WHERE `class` = 5 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 232, `agi` = 332, `sta` = 1246, `inte` = 400 WHERE `class` = 5 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 255, `agi` = 364, `sta` = 1368, `inte` = 439 WHERE `class` = 5 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 280, `agi` = 401, `sta` = 1505, `inte` = 483 WHERE `class` = 5 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 308, `agi` = 441, `sta` = 1658, `inte` = 532 WHERE `class` = 5 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 340, `agi` = 487, `sta` = 1830, `inte` = 587 WHERE `class` = 5 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 376, `agi` = 539, `sta` = 2023, `inte` = 649 WHERE `class` = 5 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 417, `agi` = 597, `sta` = 2240, `inte` = 719 WHERE `class` = 5 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 462, `agi` = 662, `sta` = 2486, `inte` = 797 WHERE `class` = 5 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 514, `agi` = 736, `sta` = 2763, `inte` = 886 WHERE `class` = 5 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 572, `agi` = 819, `sta` = 3076, `inte` = 987 WHERE `class` = 5 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 638, `agi` = 913, `sta` = 3430, `inte` = 1100 WHERE `class` = 5 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 713, `agi` = 1020, `sta` = 4024, `inte` = 1229 WHERE `class` = 5 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 752, `agi` = 1076, `sta` = 4255, `inte` = 1296 WHERE `class` = 5 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 793, `agi` = 1135, `sta` = 4500, `inte` = 1367 WHERE `class` = 5 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 836, `agi` = 1196, `sta` = 4758, `inte` = 1441 WHERE `class` = 5 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 882, `agi` = 1262, `sta` = 5032, `inte` = 1520 WHERE `class` = 5 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 930, `agi` = 1330, `sta` = 5321, `inte` = 1603 WHERE `class` = 5 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 980, `agi` = 1403, `sta` = 5627, `inte` = 1690 WHERE `class` = 5 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 1034, `agi` = 1479, `sta` = 5951, `inte` = 1782 WHERE `class` = 5 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 1090, `agi` = 1560, `sta` = 6293, `inte` = 1879 WHERE `class` = 5 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 1149, `agi` = 1645, `sta` = 6655, `inte` = 1981 WHERE `class` = 5 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 1212, `agi` = 1734, `sta` = 6397, `inte` = 2089 WHERE `class` = 5 AND `Level` = 70;