-- Update death knight (class 6) stats for levels 1-7
DELETE FROM `player_classlevelstats` WHERE `class` = 6 AND `level` BETWEEN 1 AND 7;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `spi`, `VerifiedBuild`) VALUES
(6, 1, 12, 10, 292, 11, 0, -1),
(6, 2, 14, 12, 321, 12, 0, -1),
(6, 3, 16, 14, 350, 13, 0, -1),
(6, 4, 19, 16, 380, 14, 0, -1),
(6, 5, 21, 18, 409, 15, 0, -1),
(6, 6, 23, 20, 438, 16, 0, -1),
(6, 7, 26, 22, 467, 17, 0, -1);
