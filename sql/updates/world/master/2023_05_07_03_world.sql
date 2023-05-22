-- Paladin stats
DELETE FROM `player_classlevelstats` WHERE (`class`=2 AND `level` IN (63,64,65,66,67,68,69,70));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(2, 63, 870, 305, 1068, 870, 48865), -- LightforgedDraenei Paladin recalculated
(2, 64, 992, 347, 1278, 992, 48865), -- LightforgedDraenei Paladin recalculated
(2, 65, 1130, 395, 1526, 1130, 48865), -- LightforgedDraenei Paladin recalculated
(2, 66, 1287, 450, 1817, 1287, 48865), -- LightforgedDraenei Paladin recalculated
(2, 67, 1466, 513, 2161, 1466, 48865), -- LightforgedDraenei Paladin recalculated
(2, 68, 1671, 585, 2564, 1671, 48892), -- LightforgedDraenei Paladin recalculated
(2, 69, 1903, 666, 3038, 1903, 48892), -- LightforgedDraenei Paladin recalculated
(2, 70, 2089, 731, 3848, 2089, 49444); -- LightforgedDraenei Paladin recalculated

UPDATE `player_classlevelstats` SET `str`=112, `agi`=39, `sta`=103, `inte`=112, `VerifiedBuild`=48865 WHERE (`class`=2 AND `level`=35); -- LightforgedDraenei Paladin recalculated
