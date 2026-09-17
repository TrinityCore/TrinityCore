DELETE FROM `player_classlevelstats` WHERE `class` = 12 AND `level` BETWEEN 1 AND 7;
DELETE FROM `player_classlevelstats` WHERE `class` = 13 AND `level` BETWEEN 1 AND 9;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `spi`, `VerifiedBuild`) VALUES
-- Update demon hunter (class 12) stats for levels 1-7
(12, 1, 14, 18, 292, 20, 0, -1),
(12, 2, 15, 19, 321, 22, 0, -1),
(12, 3, 17, 21, 351, 24, 0, -1),
(12, 4, 18, 23, 380, 26, 0, -1),
(12, 5, 20, 24, 409, 28, 0, -1),
(12, 6, 21, 26, 438, 30, 0, -1),
(12, 7, 22, 27, 468, 32, 0, -1),
-- Update evoker (class 13) stats for levels 1-9
(13, 1, 7, 12, 292, 20, 0, -1),
(13, 2, 8, 13, 321, 22, 0, -1),
(13, 3, 9, 14, 351, 24, 0, -1),
(13, 4, 10, 15, 380, 26, 0, -1),
(13, 5, 10, 17, 409, 28, 0, -1),
(13, 6, 11, 18, 438, 30, 0, -1),
(13, 7, 12, 19, 468, 32, 0, -1),
(13, 8, 12, 19, 497, 34, 0, -1),
(13, 9, 13, 21, 526, 36, 0, -1);
