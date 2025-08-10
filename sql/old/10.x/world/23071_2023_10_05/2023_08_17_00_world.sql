--
DELETE FROM `player_classlevelstats` WHERE `class`=3 AND `level` BETWEEN 61 AND 70;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `inte`, `sta`, `VerifiedBuild`) VALUES
(3, 61, 409, 670, 550, 1235, 0), -- Vulpera Hunter
(3, 62, 466, 764, 626, 1407, 0), -- Vulpera Hunter
(3, 63, 531, 870, 714, 1603, 0), -- Vulpera Hunter
(3, 64, 605, 992, 813, 1826, 0), -- Vulpera Hunter
(3, 65, 689, 1130, 926, 2081, 0), -- Vulpera Hunter
(3, 66, 785, 1287, 1055, 2370, 0), -- Vulpera Hunter
(3, 67, 894, 1466, 1202, 2701, 0), -- Vulpera Hunter
(3, 68, 1019, 1671, 1370, 3077, 0), -- Vulpera Hunter
(3, 69, 1161, 1903, 1561, 3506, 0), -- Vulpera Hunter
(3, 70, 1275, 2089, 1713, 3848, 0); -- Vulpera Hunter
