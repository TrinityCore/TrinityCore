-- Update Hunter stats with simc
DELETE FROM `player_classlevelstats` WHERE `class` = 3 AND `level` BETWEEN 71 AND 80;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(3, 71, 1579, 2589,  9512, 2123, 0),
(3, 72, 1957, 3207, 12221, 2630, 0),
(3, 73, 2424, 3974, 15683, 3259, 0),
(3, 74, 3004, 4924, 20101, 4037, 0),
(3, 75, 3721, 6101, 25735, 5002, 0),
(3, 76, 4611, 7559, 32915, 6198, 0),
(3, 77, 5713, 9365, 42055, 7679, 0),
(3, 78, 7078, 11603, 53685, 9515, 0),
(3, 79, 8770, 14376, 68472, 11789, 0),
(3, 80, 10765, 17647, 86452, 14471, 0);

UPDATE `player_classlevelstats` SET `str` = 10, `agi` = 17, `sta` = 62, `inte` = 16 WHERE `class` = 3 AND `Level` = 1;
UPDATE `player_classlevelstats` SET `str` = 11, `agi` = 19, `sta` = 69, `inte` = 18 WHERE `class` = 3 AND `Level` = 2;
UPDATE `player_classlevelstats` SET `str` = 13, `agi` = 21, `sta` = 75, `inte` = 20 WHERE `class` = 3 AND `Level` = 3;
UPDATE `player_classlevelstats` SET `str` = 14, `agi` = 23, `sta` = 81, `inte` = 21 WHERE `class` = 3 AND `Level` = 4;
UPDATE `player_classlevelstats` SET `str` = 15, `agi` = 25, `sta` = 87, `inte` = 23 WHERE `class` = 3 AND `Level` = 5;
UPDATE `player_classlevelstats` SET `str` = 16, `agi` = 27, `sta` = 94, `inte` = 25 WHERE `class` = 3 AND `Level` = 6;
UPDATE `player_classlevelstats` SET `str` = 17, `agi` = 29, `sta` = 100, `inte` = 26 WHERE `class` = 3 AND `Level` = 7;
UPDATE `player_classlevelstats` SET `str` = 18, `agi` = 30, `sta` = 106, `inte` = 28 WHERE `class` = 3 AND `Level` = 8;
UPDATE `player_classlevelstats` SET `str` = 19, `agi` = 31, `sta` = 112, `inte` = 30 WHERE `class` = 3 AND `Level` = 9;
UPDATE `player_classlevelstats` SET `str` = 20, `agi` = 33, `sta` = 118, `inte` = 31 WHERE `class` = 3 AND `Level` = 10;
UPDATE `player_classlevelstats` SET `str` = 21, `agi` = 36, `sta` = 125, `inte` = 33 WHERE `class` = 3 AND `Level` = 11;
UPDATE `player_classlevelstats` SET `str` = 24, `agi` = 39, `sta` = 131, `inte` = 34 WHERE `class` = 3 AND `Level` = 12;
UPDATE `player_classlevelstats` SET `str` = 26, `agi` = 43, `sta` = 137, `inte` = 36 WHERE `class` = 3 AND `Level` = 13;
UPDATE `player_classlevelstats` SET `str` = 28, `agi` = 46, `sta` = 143, `inte` = 38 WHERE `class` = 3 AND `Level` = 14;
UPDATE `player_classlevelstats` SET `str` = 29, `agi` = 48, `sta` = 150, `inte` = 39 WHERE `class` = 3 AND `Level` = 15;
UPDATE `player_classlevelstats` SET `str` = 31, `agi` = 50, `sta` = 156, `inte` = 41 WHERE `class` = 3 AND `Level` = 16;
UPDATE `player_classlevelstats` SET `str` = 32, `agi` = 52, `sta` = 162, `inte` = 43 WHERE `class` = 3 AND `Level` = 17;
UPDATE `player_classlevelstats` SET `str` = 33, `agi` = 54, `sta` = 168, `inte` = 44 WHERE `class` = 3 AND `Level` = 18;
UPDATE `player_classlevelstats` SET `str` = 34, `agi` = 56, `sta` = 175, `inte` = 46 WHERE `class` = 3 AND `Level` = 19;
UPDATE `player_classlevelstats` SET `str` = 35, `agi` = 58, `sta` = 181, `inte` = 48 WHERE `class` = 3 AND `Level` = 20;
UPDATE `player_classlevelstats` SET `str` = 37, `agi` = 60, `sta` = 188, `inte` = 50 WHERE `class` = 3 AND `Level` = 21;
UPDATE `player_classlevelstats` SET `str` = 38, `agi` = 63, `sta` = 197, `inte` = 52 WHERE `class` = 3 AND `Level` = 22;
UPDATE `player_classlevelstats` SET `str` = 40, `agi` = 66, `sta` = 206, `inte` = 54 WHERE `class` = 3 AND `Level` = 23;
UPDATE `player_classlevelstats` SET `str` = 42, `agi` = 69, `sta` = 215, `inte` = 57 WHERE `class` = 3 AND `Level` = 24;
UPDATE `player_classlevelstats` SET `str` = 44, `agi` = 73, `sta` = 226, `inte` = 59 WHERE `class` = 3 AND `Level` = 25;
UPDATE `player_classlevelstats` SET `str` = 47, `agi` = 76, `sta` = 238, `inte` = 62 WHERE `class` = 3 AND `Level` = 26;
UPDATE `player_classlevelstats` SET `str` = 49, `agi` = 80, `sta` = 251, `inte` = 66 WHERE `class` = 3 AND `Level` = 27;
UPDATE `player_classlevelstats` SET `str` = 52, `agi` = 85, `sta` = 264, `inte` = 70 WHERE `class` = 3 AND `Level` = 28;
UPDATE `player_classlevelstats` SET `str` = 55, `agi` = 90, `sta` = 280, `inte` = 74 WHERE `class` = 3 AND `Level` = 29;
UPDATE `player_classlevelstats` SET `str` = 58, `agi` = 95, `sta` = 296, `inte` = 78 WHERE `class` = 3 AND `Level` = 30;
UPDATE `player_classlevelstats` SET `str` = 62, `agi` = 101, `sta` = 314, `inte` = 83 WHERE `class` = 3 AND `Level` = 31;
UPDATE `player_classlevelstats` SET `str` = 65, `agi` = 107, `sta` = 334, `inte` = 88 WHERE `class` = 3 AND `Level` = 32;
UPDATE `player_classlevelstats` SET `str` = 70, `agi` = 114, `sta` = 356, `inte` = 94 WHERE `class` = 3 AND `Level` = 33;
UPDATE `player_classlevelstats` SET `str` = 74, `agi` = 122, `sta` = 380, `inte` = 100 WHERE `class` = 3 AND `Level` = 34;
UPDATE `player_classlevelstats` SET `str` = 79, `agi` = 130, `sta` = 406, `inte` = 107 WHERE `class` = 3 AND `Level` = 35;
UPDATE `player_classlevelstats` SET `str` = 85, `agi` = 139, `sta` = 435, `inte` = 114 WHERE `class` = 3 AND `Level` = 36;
UPDATE `player_classlevelstats` SET `str` = 91, `agi` = 150, `sta` = 466, `inte` = 123 WHERE `class` = 3 AND `Level` = 37;
UPDATE `player_classlevelstats` SET `str` = 98, `agi` = 161, `sta` = 501, `inte` = 132 WHERE `class` = 3 AND `Level` = 38;
UPDATE `player_classlevelstats` SET `str` = 106, `agi` = 173, `sta` = 540, `inte` = 142 WHERE `class` = 3 AND `Level` = 39;
UPDATE `player_classlevelstats` SET `str` = 114, `agi` = 187, `sta` = 582, `inte` = 153 WHERE `class` = 3 AND `Level` = 40;
UPDATE `player_classlevelstats` SET `str` = 123, `agi` = 202, `sta` = 629, `inte` = 166 WHERE `class` = 3 AND `Level` = 41;
UPDATE `player_classlevelstats` SET `str` = 133, `agi` = 218, `sta` = 681, `inte` = 179 WHERE `class` = 3 AND `Level` = 42;
UPDATE `player_classlevelstats` SET `str` = 144, `agi` = 237, `sta` = 738, `inte` = 194 WHERE `class` = 3 AND `Level` = 43;
UPDATE `player_classlevelstats` SET `str` = 157, `agi` = 257, `sta` = 802, `inte` = 211 WHERE `class` = 3 AND `Level` = 44;
UPDATE `player_classlevelstats` SET `str` = 171, `agi` = 280, `sta` = 873, `inte` = 230 WHERE `class` = 3 AND `Level` = 45;
UPDATE `player_classlevelstats` SET `str` = 186, `agi` = 305, `sta` = 952, `inte` = 250 WHERE `class` = 3 AND `Level` = 46;
UPDATE `player_classlevelstats` SET `str` = 203, `agi` = 333, `sta` = 1039, `inte` = 273 WHERE `class` = 3 AND `Level` = 47;
UPDATE `player_classlevelstats` SET `str` = 222, `agi` = 365, `sta` = 1137, `inte` = 299 WHERE `class` = 3 AND `Level` = 48;
UPDATE `player_classlevelstats` SET `str` = 244, `agi` = 400, `sta` = 1246, `inte` = 328 WHERE `class` = 3 AND `Level` = 49;
UPDATE `player_classlevelstats` SET `str` = 268, `agi` = 439, `sta` = 1368, `inte` = 360 WHERE `class` = 3 AND `Level` = 50;
UPDATE `player_classlevelstats` SET `str` = 294, `agi` = 483, `sta` = 1505, `inte` = 396 WHERE `class` = 3 AND `Level` = 51;
UPDATE `player_classlevelstats` SET `str` = 324, `agi` = 532, `sta` = 1658, `inte` = 436 WHERE `class` = 3 AND `Level` = 52;
UPDATE `player_classlevelstats` SET `str` = 358, `agi` = 587, `sta` = 1830, `inte` = 481 WHERE `class` = 3 AND `Level` = 53;
UPDATE `player_classlevelstats` SET `str` = 396, `agi` = 649, `sta` = 2023, `inte` = 532 WHERE `class` = 3 AND `Level` = 54;
UPDATE `player_classlevelstats` SET `str` = 438, `agi` = 719, `sta` = 2240, `inte` = 589 WHERE `class` = 3 AND `Level` = 55;
UPDATE `player_classlevelstats` SET `str` = 486, `agi` = 797, `sta` = 2486, `inte` = 654 WHERE `class` = 3 AND `Level` = 56;
UPDATE `player_classlevelstats` SET `str` = 541, `agi` = 886, `sta` = 2763, `inte` = 727 WHERE `class` = 3 AND `Level` = 57;
UPDATE `player_classlevelstats` SET `str` = 602, `agi` = 987, `sta` = 3076, `inte` = 809 WHERE `class` = 3 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 671, `agi` = 1100, `sta` = 3430, `inte` = 902 WHERE `class` = 3 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 750, `agi` = 1229, `sta` = 4024, `inte` = 1008 WHERE `class` = 3 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 791, `agi` = 1296, `sta` = 4255, `inte` = 1063 WHERE `class` = 3 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 834, `agi` = 1367, `sta` = 4500, `inte` = 1121 WHERE `class` = 3 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 879, `agi` = 1441, `sta` = 4758, `inte` = 1182 WHERE `class` = 3 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 927, `agi` = 1520, `sta` = 5032, `inte` = 1295 WHERE `class` = 3 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 978, `agi` = 1603, `sta` = 5321, `inte` = 1314 WHERE `class` = 3 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 1031, `agi` = 1690, `sta` = 5627, `inte` = 1386 WHERE `class` = 3 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 1087, `agi` = 1782, `sta` = 5951, `inte` = 1461 WHERE `class` = 3 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 1146, `agi` = 1879, `sta` = 6293, `inte` = 1541 WHERE `class` = 3 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 1209, `agi` = 1981, `sta` = 6655, `inte` = 1625 WHERE `class` = 3 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 1275, `agi` = 2089, `sta` = 6397, `inte` = 1713 WHERE `class` = 3 AND `Level` = 70;