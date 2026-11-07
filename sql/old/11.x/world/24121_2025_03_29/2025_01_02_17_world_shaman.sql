-- Update Shaman stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 7 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(7, 71, 1113, 2589, 9512, 2589, 0),
(7, 72, 1379, 3207, 12221, 3207, 0),
(7, 73, 1709, 3974, 15683, 3974, 0),
(7, 74, 2117, 4924, 20101, 4924, 0),
(7, 75, 2623, 6101, 25735, 6101, 0),
(7, 76, 3250, 7559, 32915, 7559, 0),
(7, 77, 4027, 9365, 42055, 9365, 0),
(7, 78, 4989, 11603, 53685, 11603, 0),
(7, 79, 6182, 14376, 68472, 14376, 0),
(7, 80, 7588, 17647, 86452, 17647, 0);

UPDATE `player_classlevelstats` SET `str` =  7, `agi` = 17, `sta` = 50, `inte` = 20 WHERE `class` = 7 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` =  8, `agi` = 19, `sta` = 56, `inte` = 22 WHERE `class` = 7 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` =  9, `agi` = 21, `sta` = 62, `inte` = 24 WHERE `class` = 7 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` =  10, `agi` = 23, `sta` = 68, `inte` = 26 WHERE `class` = 7 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` =  11, `agi` = 25, `sta` = 74, `inte` = 28 WHERE `class` = 7 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` =  11, `agi` = 27, `sta` = 80, `inte` = 30 WHERE `class` = 7 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` =  12, `agi` = 29, `sta` = 87, `inte` = 32 WHERE `class` = 7 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` =  13, `agi` = 30, `sta` = 93, `inte` = 34 WHERE `class` = 7 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` =  13, `agi` = 31, `sta` = 100, `inte` = 36 WHERE `class` = 7 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` =  14, `agi` = 33, `sta` = 107, `inte` = 38 WHERE `class` = 7 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` =  15, `agi` = 36, `sta` = 113, `inte` = 40 WHERE `class` = 7 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` =  17, `agi` = 39, `sta` = 120, `inte` = 42 WHERE `class` = 7 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` =  18, `agi` = 43, `sta` = 128, `inte` = 44 WHERE `class` = 7 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` =  20, `agi` = 46, `sta` = 135, `inte` = 46 WHERE `class` = 7 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` =  21, `agi` = 48, `sta` = 142, `inte` = 48 WHERE `class` = 7 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` =  22, `agi` = 50, `sta` = 150, `inte` = 50 WHERE `class` = 7 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` =  22, `agi` = 52, `sta` = 157, `inte` = 52 WHERE `class` = 7 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` =  23, `agi` = 54, `sta` = 165, `inte` = 54 WHERE `class` = 7 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` =  24, `agi` = 56, `sta` = 173, `inte` = 56 WHERE `class` = 7 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` =  25, `agi` = 58, `sta` = 181, `inte` = 58 WHERE `class` = 7 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` =  26, `agi` = 60, `sta` = 188, `inte` = 60 WHERE `class` = 7 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` =  27, `agi` = 63, `sta` = 197, `inte` = 63 WHERE `class` = 7 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` =  28, `agi` = 66, `sta` = 206, `inte` = 66 WHERE `class` = 7 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` =  30, `agi` = 69, `sta` = 215, `inte` = 69 WHERE `class` = 7 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` =  31, `agi` = 73, `sta` = 226, `inte` = 73 WHERE `class` = 7 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` =  33, `agi` = 76, `sta` = 238, `inte` = 76 WHERE `class` = 7 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` =  35, `agi` = 80, `sta` = 251, `inte` = 80 WHERE `class` = 7 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` =  36, `agi` = 85, `sta` = 264, `inte` = 85 WHERE `class` = 7 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` =  39, `agi` = 90, `sta` = 280, `inte` = 90 WHERE `class` = 7 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` =  41, `agi` = 95, `sta` = 296, `inte` = 95 WHERE `class` = 7 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` =  43, `agi` = 101, `sta` = 314, `inte` = 101 WHERE `class` = 7 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` =  46, `agi` = 107, `sta` = 334, `inte` = 107 WHERE `class` = 7 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` =  49, `agi` = 114, `sta` = 356, `inte` = 114 WHERE `class` = 7 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` =  52, `agi` = 122, `sta` = 380, `inte` = 122 WHERE `class` = 7 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` =  56, `agi` = 130, `sta` = 406, `inte` = 130 WHERE `class` = 7 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` =  60, `agi` = 139, `sta` = 435, `inte` = 139 WHERE `class` = 7 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` =  65, `agi` = 150, `sta` = 466, `inte` = 150 WHERE `class` = 7 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` =  69, `agi` = 161, `sta` = 501, `inte` = 161 WHERE `class` = 7 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` =  74, `agi` = 173, `sta` = 540, `inte` = 173 WHERE `class` = 7 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` =  80, `agi` = 187, `sta` = 582, `inte` = 187 WHERE `class` = 7 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` =  87, `agi` = 202, `sta` = 629, `inte` = 202 WHERE `class` = 7 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` =  94, `agi` = 218, `sta` = 681, `inte` = 218 WHERE `class` = 7 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` =  102, `agi` = 237, `sta` = 738, `inte` = 237 WHERE `class` = 7 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` =  111, `agi` = 257, `sta` = 802, `inte` = 257 WHERE `class` = 7 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` =  120, `agi` = 280, `sta` = 873, `inte` = 280 WHERE `class` = 7 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` =  131, `agi` = 305, `sta` = 952, `inte` = 305 WHERE `class` = 7 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` =  143, `agi` = 333, `sta` = 1039, `inte` = 333 WHERE `class` = 7 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` =  157, `agi` = 365, `sta` = 1137, `inte` = 365 WHERE `class` = 7 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` =  172, `agi` = 400, `sta` = 1246, `inte` = 400 WHERE `class` = 7 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` =  189, `agi` = 439, `sta` = 1368, `inte` = 439 WHERE `class` = 7 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` =  208, `agi` = 483, `sta` = 1505, `inte` = 483 WHERE `class` = 7 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` =  229, `agi` = 532, `sta` = 1658, `inte` = 532 WHERE `class` = 7 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` =  252, `agi` = 587, `sta` = 1830, `inte` = 587 WHERE `class` = 7 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` =  279, `agi` = 649, `sta` = 2023, `inte` = 649 WHERE `class` = 7 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` =  309, `agi` = 719, `sta` = 2240, `inte` = 719 WHERE `class` = 7 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` =  343, `agi` = 797, `sta` = 2486, `inte` = 797 WHERE `class` = 7 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` =  381, `agi` = 886, `sta` = 2763, `inte` = 886 WHERE `class` = 7 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` =  424, `agi` = 987, `sta` = 3076, `inte` = 987 WHERE `class` = 7 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` =  473, `agi` = 1100, `sta` = 3430, `inte` = 1100 WHERE `class` = 7 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` =  529, `agi` = 1229, `sta` = 4024, `inte` = 1229 WHERE `class` = 7 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` =  557, `agi` = 1296, `sta` = 4255, `inte` = 1296 WHERE `class` = 7 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` =  588, `agi` = 1367, `sta` = 4500, `inte` = 1367 WHERE `class` = 7 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` =  620, `agi` = 1441, `sta` = 4758, `inte` = 1441 WHERE `class` = 7 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` =  654, `agi` = 1520, `sta` = 5032, `inte` = 1520 WHERE `class` = 7 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` =  689, `agi` = 1603, `sta` = 5321, `inte` = 1603 WHERE `class` = 7 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` =  727, `agi` = 1690, `sta` = 5627, `inte` = 1690 WHERE `class` = 7 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` =  766, `agi` = 1782, `sta` = 5951, `inte` = 1782 WHERE `class` = 7 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` =  808, `agi` = 1879, `sta` = 6293, `inte` = 1879 WHERE `class` = 7 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` =  852, `agi` = 1981, `sta` = 6655, `inte` = 1981 WHERE `class` = 7 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` =  898, `agi` = 2089, `sta` = 6397, `inte` = 2089 WHERE `class` = 7 AND `Level` = 70;
