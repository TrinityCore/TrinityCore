-- Update Paladin stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 2 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(2, 71, 2589, 906, 9512, 2589, 0),
(2, 72, 3207, 1122, 12221, 3207, 0),
(2, 73, 3974, 1391, 15683, 3974, 0),
(2, 74, 4924, 1723, 20101, 4924, 0),
(2, 75, 6101, 2135, 25735, 6101, 0),
(2, 76, 7559, 2646, 32915, 7559, 0),
(2, 77, 9365, 3278, 42055, 9365, 0),
(2, 78, 11603, 4061, 53685, 11603, 0),
(2, 79, 14376, 5032, 68472, 14376, 0),
(2, 80, 17647, 6176, 86452, 17647, 0);

UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 6, `sta` = 62, `inte` = 20 WHERE `class` = 2 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 7, `sta` = 69, `inte` = 22 WHERE `class` = 2 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 8, `sta` = 75, `inte` = 24 WHERE `class` = 2 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 22, `agi` = 8, `sta` = 81, `inte` = 26 WHERE `class` = 2 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 9, `sta` = 87, `inte` = 28 WHERE `class` = 2 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 26, `agi` = 9, `sta` = 94, `inte` = 30 WHERE `class` = 2 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 10, `sta` = 100, `inte` = 32 WHERE `class` = 2 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 10, `sta` = 106, `inte` = 34 WHERE `class` = 2 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 11, `sta` = 112, `inte` = 36 WHERE `class` = 2 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 33, `agi` = 12, `sta` = 118, `inte` = 38 WHERE `class` = 2 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 12, `sta` = 125, `inte` = 40 WHERE `class` = 2 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 39, `agi` = 14, `sta` = 131, `inte` = 42 WHERE `class` = 2 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 15, `sta` = 137, `inte` = 44 WHERE `class` = 2 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 46, `agi` = 16, `sta` = 143, `inte` = 46 WHERE `class` = 2 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 48, `agi` = 17, `sta` = 150, `inte` = 48 WHERE `class` = 2 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 50, `agi` = 18, `sta` = 156, `inte` = 50 WHERE `class` = 2 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 18, `sta` = 162, `inte` = 52 WHERE `class` = 2 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 54, `agi` = 19, `sta` = 168, `inte` = 54 WHERE `class` = 2 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 56, `agi` = 20, `sta` = 175, `inte` = 56 WHERE `class` = 2 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 58, `agi` = 20, `sta` = 181, `inte` = 58 WHERE `class` = 2 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 60, `agi` = 21, `sta` = 188, `inte` = 60 WHERE `class` = 2 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 63, `agi` = 22, `sta` = 197, `inte` = 63 WHERE `class` = 2 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 66, `agi` = 23, `sta` = 206, `inte` = 66 WHERE `class` = 2 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 69, `agi` = 24, `sta` = 215, `inte` = 69 WHERE `class` = 2 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 73, `agi` = 25, `sta` = 226, `inte` = 73 WHERE `class` = 2 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 76, `agi` = 26, `sta` = 238, `inte` = 76 WHERE `class` = 2 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 80, `agi` = 28, `sta` = 251, `inte` = 80 WHERE `class` = 2 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 85, `agi` = 30, `sta` = 264, `inte` = 85 WHERE `class` = 2 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 90, `agi` = 31, `sta` = 280, `inte` = 90 WHERE `class` = 2 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 95, `agi` = 33, `sta` = 296, `inte` = 95 WHERE `class` = 2 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 101, `agi` = 35, `sta` = 314, `inte` = 101 WHERE `class` = 2 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 107, `agi` = 38, `sta` = 334, `inte` = 107 WHERE `class` = 2 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 114, `agi` = 40, `sta` = 356, `inte` = 114 WHERE `class` = 2 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 122, `agi` = 43, `sta` = 380, `inte` = 122 WHERE `class` = 2 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 130, `agi` = 46, `sta` = 406, `inte` = 130 WHERE `class` = 2 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 139, `agi` = 49, `sta` = 435, `inte` = 139 WHERE `class` = 2 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 150, `agi` = 52, `sta` = 466, `inte` = 150 WHERE `class` = 2 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 161, `agi` = 56, `sta` = 501, `inte` = 161 WHERE `class` = 2 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 173, `agi` = 61, `sta` = 540, `inte` = 173 WHERE `class` = 2 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 187, `agi` = 65, `sta` = 582, `inte` = 187 WHERE `class` = 2 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 202, `agi` = 71, `sta` = 629, `inte` = 202 WHERE `class` = 2 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 218, `agi` = 76, `sta` = 681, `inte` = 218 WHERE `class` = 2 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 237, `agi` = 83, `sta` = 738, `inte` = 237 WHERE `class` = 2 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 257, `agi` = 90, `sta` = 802, `inte` = 257 WHERE `class` = 2 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 280, `agi` = 98, `sta` = 873, `inte` = 280 WHERE `class` = 2 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 305, `agi` = 107, `sta` = 952, `inte` = 305 WHERE `class` = 2 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 333, `agi` = 117, `sta` = 1039, `inte` = 333 WHERE `class` = 2 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 365, `agi` = 128, `sta` = 1137, `inte` = 365 WHERE `class` = 2 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 400, `agi` = 140, `sta` = 1246, `inte` = 400 WHERE `class` = 2 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 439, `agi` = 154, `sta` = 1368, `inte` = 439 WHERE `class` = 2 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 483, `agi` = 169, `sta` = 1505, `inte` = 483 WHERE `class` = 2 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 532, `agi` = 186, `sta` = 1658, `inte` = 532 WHERE `class` = 2 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 587, `agi` = 205, `sta` = 1830, `inte` = 587 WHERE `class` = 2 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 649, `agi` = 227, `sta` = 2023, `inte` = 649 WHERE `class` = 2 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 719, `agi` = 252, `sta` = 2240, `inte` = 719 WHERE `class` = 2 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 797, `agi` = 279, `sta` = 2486, `inte` = 797 WHERE `class` = 2 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 886, `agi` = 310, `sta` = 2763, `inte` = 886 WHERE `class` = 2 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 987, `agi` = 345, `sta` = 3076, `inte` = 987 WHERE `class` = 2 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 1100, `agi` = 385, `sta` = 3430, `inte` = 1100 WHERE `class` = 2 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 1229, `agi` = 430, `sta` = 4024, `inte` = 1229 WHERE `class` = 2 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 1296, `agi` = 454, `sta` = 4255, `inte` = 1296 WHERE `class` = 2 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 1367, `agi` = 478, `sta` = 4500, `inte` = 1367 WHERE `class` = 2 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 1441, `agi` = 504, `sta` = 4758, `inte` = 1441 WHERE `class` = 2 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 1520, `agi` = 532, `sta` = 5032, `inte` = 1520 WHERE `class` = 2 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 1603, `agi` = 561, `sta` = 5321, `inte` = 1603 WHERE `class` = 2 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 1690, `agi` = 592, `sta` = 5627, `inte` = 1690 WHERE `class` = 2 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 1782, `agi` = 624, `sta` = 5951, `inte` = 1782 WHERE `class` = 2 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 1879, `agi` = 658, `sta` = 6293, `inte` = 1879 WHERE `class` = 2 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 1981, `agi` = 694, `sta` = 6655, `inte` = 1981 WHERE `class` = 2 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 2089, `agi` = 731, `sta` = 6397, `inte` = 2089 WHERE `class` = 2 AND `Level` = 70;