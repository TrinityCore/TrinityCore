-- 
DELETE FROM `player_classlevelstats` WHERE (`class`=9 AND `level` BETWEEN 60 AND 70);
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `inte`, `sta`, `VerifiedBuild`) VALUES
(9, 60, 171, 346, 450, 455, 0), -- BloodElf Warlock
(9, 61, 255, 516, 670, 815, 0), -- BloodElf Warlock
(9, 62, 290, 588, 764, 980, 0), -- BloodElf Warlock
(9, 63, 331, 670, 870, 1174, 0), -- BloodElf Warlock
(9, 64, 377, 763, 992, 1405, 0), -- BloodElf Warlock
(9, 65, 429, 870, 1130, 1678, 0), -- BloodElf Warlock
(9, 66, 489, 991, 1287, 1998, 0), -- BloodElf Warlock
(9, 67, 557, 1129, 1466, 2377, 0), -- BloodElf Warlock
(9, 68, 635, 1286, 1671, 2820, 0), -- BloodElf Warlock
(9, 69, 723, 1466, 1903, 3341, 0), -- BloodElf Warlock
(9, 70, 794, 1609, 2089, 3809, 0); -- BloodElf Warlock
