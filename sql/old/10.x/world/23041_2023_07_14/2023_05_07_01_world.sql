-- Monk stats
DELETE FROM `player_classlevelstats` WHERE (`class`=10 AND `level` IN (61,62,63,64,65,66,67,68,69,70));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(10, 61, 288, 670, 741, 670, 48966), -- VoidElf Monk recalculated
(10, 62, 328, 764, 891, 764, 48966), -- VoidElf Monk recalculated
(10, 63, 374, 870, 1068, 870, 48966), -- VoidElf Monk recalculated
(10, 64, 426, 992, 1278, 992, 48966), -- VoidElf Monk recalculated
(10, 65, 486, 1130, 1526, 1130, 48966), -- VoidElf Monk recalculated
(10, 66, 553, 1287, 1817, 1287, 48966), -- VoidElf Monk recalculated
(10, 67, 631, 1466, 2161, 1466, 48966), -- VoidElf Monk recalculated
(10, 68, 718, 1671, 2564, 1671, 48966), -- VoidElf Monk recalculated
(10, 69, 819, 1903, 3038, 1903, 48966), -- VoidElf Monk recalculated
(10, 70, 898, 2089, 3848, 2089, 49444); -- VoidElf Monk recalculated

UPDATE `player_classlevelstats` SET `str`=8, `sta`=18, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=1); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `agi`=20, `sta`=20, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=2); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `agi`=22, `sta`=22, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=3); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=10, `agi`=24, `sta`=24, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=4); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=11, `agi`=26, `sta`=26, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=5); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=12, `agi`=28, `sta`=28, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=6); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `agi`=29, `sta`=29, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=7); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `agi`=31, `sta`=31, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=8); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=14, `agi`=32, `sta`=33, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=9); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=15, `agi`=35, `sta`=35, `VerifiedBuild`=48526 WHERE (`class`=10 AND `level`=10); -- Human Monk recalculated
UPDATE `player_classlevelstats` SET `str`=48, `agi`=112, `sta`=103, `inte`=112, `VerifiedBuild`=48966 WHERE (`class`=10 AND `level`=35); -- VoidElf Monk recalculated
