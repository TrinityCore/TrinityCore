-- Update Warlock stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 9 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(9, 71, 984,  1994,  9512, 2589, 0),
(9, 72, 1219, 2469, 12221, 3207, 0),
(9, 73, 1510, 3060, 15683, 3974, 0),
(9, 74, 1871, 3791, 20101, 4924, 0),
(9, 75, 2318, 4698, 25735, 6101, 0),
(9, 76, 2872, 5820, 32915, 7559, 0),
(9, 77, 3559, 7211, 42055, 9365, 0),
(9, 78, 4409, 8934, 53685, 11603, 0),
(9, 79, 5463, 11070, 68472, 14376, 0),
(9, 80, 6706, 13588, 86452, 17647, 0);

UPDATE `player_classlevelstats` SET `str` = 6, `agi` = 13, `sta` = 74, `inte` = 20 WHERE `class` = 9 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 7, `agi` = 15, `sta` = 81, `inte` = 22 WHERE `class` = 9 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 8, `agi` = 17, `sta` = 88, `inte` = 24 WHERE `class` = 9 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 9, `agi` = 18, `sta` = 94, `inte` = 26 WHERE `class` = 9 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 9, `agi` = 19, `sta` = 100, `inte` = 28 WHERE `class` = 9 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 10, `agi` = 21, `sta` = 107, `inte` = 30 WHERE `class` = 9 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 22, `sta` = 113, `inte` = 32 WHERE `class` = 9 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 23, `sta` = 119, `inte` = 34 WHERE `class` = 9 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 12, `agi` = 24, `sta` = 125, `inte` = 36 WHERE `class` = 9 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 26, `sta` = 130, `inte` = 38 WHERE `class` = 9 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 27, `sta` = 136, `inte` = 40 WHERE `class` = 9 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 15, `agi` = 30, `sta` = 141, `inte` = 42 WHERE `class` = 9 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 16, `agi` = 33, `sta` = 147, `inte` = 44 WHERE `class` = 9 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 35, `sta` = 152, `inte` = 46 WHERE `class` = 9 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 18, `agi` = 37, `sta` = 157, `inte` = 48 WHERE `class` = 9 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 39, `sta` = 162, `inte` = 50 WHERE `class` = 9 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 20, `agi` = 40, `sta` = 167, `inte` = 52 WHERE `class` = 9 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 42, `sta` = 172, `inte` = 54 WHERE `class` = 9 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 43, `sta` = 176, `inte` = 56 WHERE `class` = 9 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 45, `sta` = 181, `inte` = 58 WHERE `class` = 9 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 23, `agi` = 47, `sta` = 188, `inte` = 60 WHERE `class` = 9 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 49, `sta` = 197, `inte` = 63 WHERE `class` = 9 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 25, `agi` = 51, `sta` = 206, `inte` = 66 WHERE `class` = 9 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 26, `agi` = 53, `sta` = 215, `inte` = 69 WHERE `class` = 9 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 56, `sta` = 226, `inte` = 73 WHERE `class` = 9 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 59, `sta` = 238, `inte` = 76 WHERE `class` = 9 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 62, `sta` = 251, `inte` = 80 WHERE `class` = 9 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 32, `agi` = 65, `sta` = 264, `inte` = 85 WHERE `class` = 9 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 34, `agi` = 69, `sta` = 280, `inte` = 90 WHERE `class` = 9 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 36, `agi` = 73, `sta` = 296, `inte` = 95 WHERE `class` = 9 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 38, `agi` = 78, `sta` = 314, `inte` = 101 WHERE `class` = 9 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 41, `agi` = 83, `sta` = 334, `inte` = 107 WHERE `class` = 9 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 43, `agi` = 88, `sta` = 356, `inte` = 114 WHERE `class` = 9 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 46, `agi` = 94, `sta` = 380, `inte` = 122 WHERE `class` = 9 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 49, `agi` = 100, `sta` = 406, `inte` = 130 WHERE `class` = 9 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 53, `agi` = 107, `sta` = 435, `inte` = 139 WHERE `class` = 9 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 57, `agi` = 115, `sta` = 466, `inte` = 150 WHERE `class` = 9 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 61, `agi` = 124, `sta` = 501, `inte` = 161 WHERE `class` = 9 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 66, `agi` = 133, `sta` = 540, `inte` = 173 WHERE `class` = 9 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 71, `agi` = 144, `sta` = 582, `inte` = 187 WHERE `class` = 9 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 77, `agi` = 155, `sta` = 629, `inte` = 202 WHERE `class` = 9 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 83, `agi` = 168, `sta` = 681, `inte` = 218 WHERE `class` = 9 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 90, `agi` = 182, `sta` = 738, `inte` = 237 WHERE `class` = 9 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 98, `agi` = 198, `sta` = 802, `inte` = 257 WHERE `class` = 9 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 106, `agi` = 216, `sta` = 873, `inte` = 280 WHERE `class` = 9 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 116, `agi` = 235, `sta` = 952, `inte` = 305 WHERE `class` = 9 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 127, `agi` = 257, `sta` = 1039, `inte` = 333 WHERE `class` = 9 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 139, `agi` = 281, `sta` = 1137, `inte` = 365 WHERE `class` = 9 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 152, `agi` = 308, `sta` = 1246, `inte` = 400 WHERE `class` = 9 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 167, `agi` = 338, `sta` = 1368, `inte` = 439 WHERE `class` = 9 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 183, `agi` = 372, `sta` = 1505, `inte` = 483 WHERE `class` = 9 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 202, `agi` = 409, `sta` = 1658, `inte` = 532 WHERE `class` = 9 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 223, `agi` = 452, `sta` = 1830, `inte` = 587 WHERE `class` = 9 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 247, `agi` = 500, `sta` = 2023, `inte` = 649 WHERE `class` = 9 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 273, `agi` = 553, `sta` = 2240, `inte` = 719 WHERE `class` = 9 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 303, `agi` = 614, `sta` = 2486, `inte` = 797 WHERE `class` = 9 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 337, `agi` = 682, `sta` = 2763, `inte` = 886 WHERE `class` = 9 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 375, `agi` = 760, `sta` = 3076, `inte` = 987 WHERE `class` = 9 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 418, `agi` = 847, `sta` = 3430, `inte` = 1100 WHERE `class` = 9 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 467, `agi` = 947, `sta` = 4024, `inte` = 1229 WHERE `class` = 9 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 493, `agi` = 998, `sta` = 4255, `inte` = 1296 WHERE `class` = 9 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 519, `agi` = 1053, `sta` = 4500, `inte` = 1367 WHERE `class` = 9 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 548, `agi` = 1110, `sta` = 4758, `inte` = 1441 WHERE `class` = 9 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 578, `agi` = 1170, `sta` = 5032, `inte` = 1520 WHERE `class` = 9 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 609, `agi` = 1234, `sta` = 5321, `inte` = 1603 WHERE `class` = 9 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 642, `agi` = 1301, `sta` = 5627, `inte` = 1690 WHERE `class` = 9 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 677, `agi` = 1372, `sta` = 5951, `inte` = 1782 WHERE `class` = 9 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 714, `agi` = 1447, `sta` = 6293, `inte` = 1879 WHERE `class` = 9 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 753, `agi` = 1526, `sta` = 6655, `inte` = 1981 WHERE `class` = 9 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 794, `agi` = 1609, `sta` = 6397, `inte` = 2089 WHERE `class` = 9 AND `Level` = 70;
