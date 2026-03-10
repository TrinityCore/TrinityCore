SET @OGUID := 167083;
SET @POOLID := 3000001;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 1731, 0, 40, 111, '0', 0, 0, -9928.349609375, 1434.800048828125, 39.02470016479492187, 0, 0, 0, 0, 1, 120, 255, 1, 63305), -- Copper Vein (Area: Jangolode Mine - Difficulty: 0) CreateObject2
(@OGUID+1, 1731, 0, 40, 111, '0', 0, 0, -9941.16015625, 1481.1400146484375, 40.5045013427734375, 0, 0, 0, 0, 1, 120, 255, 1, 63305), -- Copper Vein (Area: Jangolode Mine - Difficulty: 0) CreateObject2
(@OGUID+2, 1731, 0, 40, 111, '0', 0, 0, -9833.990234375, 1395.949951171875, 39.22349929809570312, 0, 0, 0, 0, 1, 120, 255, 1, 63305), -- Copper Vein (Area: Jangolode Mine - Difficulty: 0) CreateObject2
(@OGUID+3, 1731, 0, 40, 111, '0', 0, 0, -9870, 1425.6300048828125, 44.792999267578125, 0, 0, 0, 0, 1, 120, 255, 1, 63305); -- Copper Vein (Area: Jangolode Mine - Difficulty: 0) CreateObject2

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+1;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Westfall - Jangolode Mine - Copper Vein Group 1'),
(@POOLID+1, 1, 'Westfall - Jangolode Mine - Copper Vein Group 2');

DELETE FROM `pool_members` WHERE (`type` = 1 AND `spawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,208359,208382));
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOLID+0, 0, 'Westfall - Jangolode Mine - Node 1'),
(1, @OGUID+1, @POOLID+0, 0, 'Westfall - Jangolode Mine - Node 2'),
(1, 208359, @POOLID+0, 0, 'Westfall - Jangolode Mine - Node 3'),
(1, @OGUID+3, @POOLID+1, 0, 'Westfall - Jangolode Mine - Node 1'),
(1, @OGUID+2, @POOLID+1, 0, 'Westfall - Jangolode Mine - Node 2'),
(1, 208382, @POOLID+1, 0, 'Westfall - Jangolode Mine - Node 3');
