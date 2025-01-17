-- Update Death Knight stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 6 AND `level` BETWEEN 61 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(6, 61, 1296, 1076, 4255, 700, 0),
(6, 62, 1367, 1135, 4500, 738, 0),
(6, 63, 1441, 1196, 4758, 778, 0),
(6, 64, 1520, 1262, 5032, 821, 0),
(6, 65, 1603, 1330, 5321, 865, 0),
(6, 66, 1690, 1403, 5627, 913, 0),
(6, 67, 1782, 1479, 5951, 962, 0),
(6, 68, 1879, 1560, 6293, 1015, 0),
(6, 69, 1981, 1645, 6655, 1070, 0),
(6, 70, 2089, 1734, 6397, 1128, 0),
(6, 71, 2589, 2149, 9512, 1398, 0),
(6, 72, 3207, 2662, 12221, 1732, 0),
(6, 73, 3974, 3298, 15683, 2146, 0),
(6, 74, 4924, 4087, 20101, 2659, 0),
(6, 75, 6101, 5064, 25735, 3295, 0),
(6, 76, 7559, 6274, 32915, 4082, 0),
(6, 77, 9365, 7773, 42055, 5057, 0),
(6, 78, 11603, 9630, 53685, 6266, 0),
(6, 79, 14376, 11932, 68472, 7763, 0),
(6, 80, 17647, 14647, 86452, 9529, 0);

UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 25, `sta` = 119, `inte` = 18 WHERE `class` = 6 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 26, `sta` = 125, `inte` = 19 WHERE `class` = 6 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 33, `agi` = 28, `sta` = 130, `inte` = 21 WHERE `class` = 6 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 30, `sta` = 136, `inte` = 22 WHERE `class` = 6 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 39, `agi` = 32, `sta` = 141, `inte` = 23 WHERE `class` = 6 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 35, `sta` = 147, `inte` = 24 WHERE `class` = 6 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 46, `agi` = 38, `sta` = 152, `inte` = 25 WHERE `class` = 6 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 48, `agi` = 40, `sta` = 157, `inte` = 26 WHERE `class` = 6 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 50, `agi` = 42, `sta` = 162, `inte` = 27 WHERE `class` = 6 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 43, `sta` = 167, `inte` = 28 WHERE `class` = 6 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 54, `agi` = 45, `sta` = 172, `inte` = 29 WHERE `class` = 6 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 56, `agi` = 46, `sta` = 176, `inte` = 31 WHERE `class` = 6 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 58, `agi` = 48, `sta` = 181, `inte` = 32 WHERE `class` = 6 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 60, `agi` = 50, `sta` = 188, `inte` = 33 WHERE `class` = 6 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 63, `agi` = 52, `sta` = 197, `inte` = 34 WHERE `class` = 6 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 66, `agi` = 55, `sta` = 206, `inte` = 36 WHERE `class` = 6 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 69, `agi` = 57, `sta` = 215, `inte` = 37 WHERE `class` = 6 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 73, `agi` = 60, `sta` = 226, `inte` = 39 WHERE `class` = 6 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 76, `agi` = 63, `sta` = 238, `inte` = 41 WHERE `class` = 6 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 80, `agi` = 67, `sta` = 251, `inte` = 43 WHERE `class` = 6 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 85, `agi` = 70, `sta` = 264, `inte` = 46 WHERE `class` = 6 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 90, `agi` = 74, `sta` = 280, `inte` = 48 WHERE `class` = 6 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 95, `agi` = 79, `sta` = 296, `inte` = 51 WHERE `class` = 6 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 101, `agi` = 84, `sta` = 314, `inte` = 54 WHERE `class` = 6 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 107, `agi` = 89, `sta` = 334, `inte` = 58 WHERE `class` = 6 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 114, `agi` = 95, `sta` = 356, `inte` = 62 WHERE `class` = 6 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 122, `agi` = 101, `sta` = 380, `inte` = 66 WHERE `class` = 6 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 130, `agi` = 108, `sta` = 406, `inte` = 70 WHERE `class` = 6 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 139, `agi` = 116, `sta` = 435, `inte` = 78 WHERE `class` = 6 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 150, `agi` = 124, `sta` = 466, `inte` = 81 WHERE `class` = 6 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 161, `agi` = 133, `sta` = 501, `inte` = 87 WHERE `class` = 6 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 173, `agi` = 144, `sta` = 540, `inte` = 93 WHERE `class` = 6 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 187, `agi` = 155, `sta` = 582, `inte` = 101 WHERE `class` = 6 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 202, `agi` = 167, `sta` = 629, `inte` = 109 WHERE `class` = 6 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 218, `agi` = 181, `sta` = 681, `inte` = 118 WHERE `class` = 6 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 237, `agi` = 197, `sta` = 738, `inte` = 128 WHERE `class` = 6 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 257, `agi` = 214, `sta` = 802, `inte` = 139 WHERE `class` = 6 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 280, `agi` = 232, `sta` = 873, `inte` = 151 WHERE `class` = 6 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 305, `agi` = 253, `sta` = 952, `inte` = 165 WHERE `class` = 6 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 333, `agi` = 277, `sta` = 1039, `inte` = 180 WHERE `class` = 6 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 365, `agi` = 303, `sta` = 1137, `inte` = 197 WHERE `class` = 6 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 400, `agi` = 332, `sta` = 1246, `inte` = 216 WHERE `class` = 6 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 439, `agi` = 364, `sta` = 1368, `inte` = 237 WHERE `class` = 6 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 483, `agi` = 401, `sta` = 1505, `inte` = 261 WHERE `class` = 6 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 532, `agi` = 441, `sta` = 1658, `inte` = 287 WHERE `class` = 6 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 587, `agi` = 487, `sta` = 1830, `inte` = 317 WHERE `class` = 6 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 649, `agi` = 539, `sta` = 2023, `inte` = 350 WHERE `class` = 6 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 719, `agi` = 597, `sta` = 2240, `inte` = 388 WHERE `class` = 6 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 797, `agi` = 662, `sta` = 2486, `inte` = 431 WHERE `class` = 6 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 886, `agi` = 736, `sta` = 2763, `inte` = 479 WHERE `class` = 6 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 987, `agi` = 819, `sta` = 3076, `inte` = 533 WHERE `class` = 6 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 1100, `agi` = 913, `sta` = 3430, `inte` = 594 WHERE `class` = 6 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 1229, `agi` = 1020, `sta` = 4024, `inte` = 664 WHERE `class` = 6 AND `Level` = 60;
