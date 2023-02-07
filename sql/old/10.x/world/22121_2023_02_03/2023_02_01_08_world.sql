-- 
DELETE FROM `player_classlevelstats` WHERE `class`=4 AND `level` BETWEEN 61 AND 70;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `inte`, `sta`, `VerifiedBuild`) VALUES
(4, 61, 556, 670, 456, 741, 0), -- Vulpera Rogue
(4, 62, 634, 764, 519, 891, 0), -- Vulpera Rogue
(4, 63, 722, 870, 592, 1068, 0), -- Vulpera Rogue
(4, 64, 823, 992, 674, 1278, 0), -- Vulpera Rogue
(4, 65, 938, 1130, 768, 1526, 0), -- Vulpera Rogue
(4, 66, 1068, 1287, 875, 1817, 0), -- Vulpera Rogue
(4, 67, 1217, 1466, 997, 2161, 0), -- Vulpera Rogue
(4, 68, 1387, 1671, 1136, 2564, 0), -- Vulpera Rogue
(4, 69, 1580, 1903, 1294, 3038, 0), -- Vulpera Rogue
(4, 70, 1734, 2089, 1421, 3463, 0); -- Vulpera Rogue
