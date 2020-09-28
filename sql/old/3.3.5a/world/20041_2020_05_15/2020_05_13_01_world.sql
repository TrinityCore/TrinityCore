SET @OGUID:=  18017;
SET @POOL :=  762;

DELETE FROM `pool_members` WHERE `poolSpawnId`=@POOL;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES 
(1, 50417, @POOL, 0, "Netherwing Egg"),
(1, 50418, @POOL, 0, "Netherwing Egg"),
(1, 50419, @POOL, 0, "Netherwing Egg"),
(1, 50420, @POOL, 0, "Netherwing Egg"),
(1, 50421, @POOL, 0, "Netherwing Egg"),
(1, 50422, @POOL, 0, "Netherwing Egg"),
(1, 50423, @POOL, 0, "Netherwing Egg"),
(1, 50424, @POOL, 0, "Netherwing Egg"),
(1, 50425, @POOL, 0, "Netherwing Egg"),
(1, 151889, @POOL, 0, "Netherwing Egg"),
(1, 151890, @POOL, 0, "Netherwing Egg"),
(1, 151891, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+0, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+1, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+2, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+3, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+4, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+5, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+6, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+7, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+8, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+9, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+10, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+11, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+12, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+13, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+14, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+15, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+16, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+17, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+18, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+19, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+20, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+21, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+22, @POOL, 0, "Netherwing Egg"),
(1, @OGUID+23, @POOL, 0, "Netherwing Egg");

DELETE FROM `pool_template` WHERE `entry` =@POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@POOL, 10, 'Netherwing Egg 6 of 36');

UPDATE `gameobject` SET `spawntimesecs`=3600 WHERE  `id`=185915;
DELETE FROM `gameobject` WHERE `id`=185915 AND `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 185915, 530, 3520, 3965, 1, 1, -5116.493, 673.1073, 37.64555, 2.967041, 0, 0, 0.9961939, 0.08716504, 3600, 255, 1, 15595), -- 185915 (Area: 3965 - Difficulty: 0)
(@OGUID+1, 185915, 530, 3520, 3965, 1, 1, -4867.7, 531.2372, -1.91996, 1.134463, 0, 0, 0.5372992, 0.8433917, 3600, 255, 1, 15595), -- 185915 (Area: 3965 - Difficulty: 0)
(@OGUID+2, 185915, 530, 3520, 3759, 1, 1, -5034.838, 612.646, 184.4103, 2.984498, 0, 0, 0.9969168, 0.07846643, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+3, 185915, 530, 3520, 3759, 1, 1, -5040.481, 393.2956, 170.8373, 5.98648, 0, 0, -0.147809, 0.9890159, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+4, 185915, 530, 3520, 3759, 1, 1, -5117.958, 89.7627, -12.05266, 5.323256, 0, 0, -0.4617481, 0.8870111, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+5, 185915, 530, 3520, 3759, 1, 1, -5088.855, 23.24989, 81.81818, 0.1396245, 0, 0, 0.06975555, 0.9975641, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+6, 185915, 530, 3520, 3759, 1, 1, -5031.912, 289.6906, 4.984869, 0.5410506, 0, 0, 0.2672377, 0.9636307, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+7, 185915, 530, 3520, 3759, 1, 1, -5282.702, 654.8848, 40.72212, -1.378809, 0, 0, -0.6360779, 0.7716249, 3600, 255, 1, 13623), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+8, 185915, 530, 3520, 3759, 1, 1, -5341.819, -43.58724, 90.34805, -2.984498, 0, 0, -0.9969168, 0.07846643, 3600, 255, 1, 13623), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+9, 185915, 530, 3520, 3759, 1, 1, -5003.992, -113.3952, -4.667536, 0.2443456, 0, 0, 0.1218691, 0.9925462, 3600, 255, 1, 13623), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+10, 185915, 530, 4815, 5012, 1, 1, -4234.241, 526.788, 78.41892, -2.426003, 0, 0, -0.9366713, 0.3502098, 3600, 255, 1, 14007), -- 185915 (Area: 5012 - Difficulty: 0)
(@OGUID+11, 185915, 530, 4815, 5012, 1, 1, -4689.656, 771.3027, 25.21626, -2.268925, 0, 0, -0.9063072, 0.4226195, 3600, 255, 1, 14007), -- 185915 (Area: 5012 - Difficulty: 0)
(@OGUID+12, 185915, 530, 4815, 5012, 1, 1, -4931.305, 426.1053, 0.003176, 1.431168, 0, 0, 0.6560583, 0.7547102, 3600, 255, 1, 14007), -- 185915 (Area: 5012 - Difficulty: 0)
(@OGUID+13, 185915, 530, 3520, 3759, 1, 1, -4934.188, 323.5568, 138.5504, 4.188792, 0, 0, -0.866025, 0.5000008, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+14, 185915, 530, 3520, 3759, 1, 1, -5096.626, 151.4355, -11.33789, 1.099556, 0, 0, 0.5224981, 0.8526405, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+15, 185915, 530, 3520, 3759, 1, 1, -5143.51, 190.4579, 150.3326, 0.7504908, 0, 0, 0.3665009, 0.9304177, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+16, 185915, 530, 3520, 3965, 1, 1, -4987.638, 451.117, 6.23003, 5.288348, 0, 0, -0.4771585, 0.8788173, 3600, 255, 1, 15595), -- 185915 (Area: 3965 - Difficulty: 0)
(@OGUID+17, 185915, 530, 3520, 3965, 1, 1, -5025.026, 359.934, 1.24235, 1.448622, 0, 0, 0.6626196, 0.7489561, 3600, 255, 1, 15595), -- 185915 (Area: 3965 - Difficulty: 0)
(@OGUID+18, 185915, 530, 3520, 3759, 1, 1, -5170.725, 251.7406, -32.01391, 2.879789, 0, 0, 0.9914446, 0.1305283, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+19, 185915, 530, 3520, 3759, 1, 1, -5260.721, 186.911, 128.8412, 5.201083, 0, 0, -0.5150375, 0.8571676, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+20, 185915, 530, 3520, 3759, 1, 1, -5004.113, 14.80371, 76.3614, 4.677484, 0, 0, -0.7193394, 0.6946588, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+21, 185915, 530, 3520, 3759, 1, 1, -4901.969, 597.2923, 4.663516, 0.4188786, 0, 0, 0.2079115, 0.9781476, 3600, 255, 1, 15595), -- 185915 (Area: 3759 - Difficulty: 0)
(@OGUID+22, 185915, 530, 210, 4666, 1, 1, -4286.163, 408.8362, 129.7793, 1.361356, 0, 0, 0.6293201, 0.7771462, 3600, 255, 1, 14007), -- 185915 (Area: 4666 - Difficulty: 0)
(@OGUID+23, 185915, 530, 3520, 3966, 1, 1,  -5199.026, 624.2134, 45.12667, 0.5061446, 0, 0, 0.2503796, 0.9681478, 3600, 255, 1, 15595); -- 185915 (Area: 3966 - Difficulty: 0)
