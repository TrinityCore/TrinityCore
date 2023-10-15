-- Warrior stats
DELETE FROM `player_classlevelstats` WHERE (`class`=1 AND `level` IN (61,62,63,64,65,66,67,68,69,70));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(1, 61, 773, 463, 741, 456, 48676), -- NightElf Warrior recalculated
(1, 62, 893, 527, 891, 519, 48676), -- NightElf Warrior recalculated
(1, 63, 870, 600, 1068, 592, 48676), -- NightElf Warrior recalculated
(1, 64, 992, 684, 1278, 674, 48676), -- NightElf Warrior recalculated
(1, 65, 1130, 779, 1526, 768, 48676), -- NightElf Warrior recalculated
(1, 66, 1287, 888, 1817, 875, 48676), -- NightElf Warrior recalculated
(1, 67, 1669, 1012, 2161, 997, 48676), -- NightElf Warrior recalculated
(1, 68, 1879, 1153, 2564, 1136, 48676), -- NightElf Warrior recalculated
(1, 69, 1903, 1313, 3038, 1294, 48676), -- NightElf Warrior recalculated
(1, 70, 2089, 1442, 3463, 1421, 48749); -- NightElf Warrior recalculated

UPDATE `player_classlevelstats` SET `str`=37, `agi`=26, `sta`=40, `VerifiedBuild`=47187 WHERE (`class`=1 AND `level`=11); -- Human Warrior recalculated
UPDATE `player_classlevelstats` SET `sta`=46, `VerifiedBuild`=47871 WHERE (`class`=1 AND `level`=15); -- DarkIronDwarf Warrior recalculated
UPDATE `player_classlevelstats` SET `sta`=48, `VerifiedBuild`=47871 WHERE (`class`=1 AND `level`=16); -- DarkIronDwarf Warrior recalculated
