DELETE FROM `player_classlevelstats` WHERE `class`=12 AND `level` IN (1, 2, 3, 4, 5, 6, 7);
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`) VALUES
(12, 1, 14, 18, 19, 14),
(12, 2, 15, 19, 21, 15),
(12, 3, 17, 21, 23, 16),
(12, 4, 18, 22, 25, 18),
(12, 5, 20, 24, 27, 19),
(12, 6, 21, 26, 29, 20),
(12, 7, 23, 28, 30, 22);
