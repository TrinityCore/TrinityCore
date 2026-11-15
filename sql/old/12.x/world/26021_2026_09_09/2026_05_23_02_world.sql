SET @OGUID := 167087;
SET @POOLID := 3000015;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 1731, 0, 40, 40, '0', 0, 0, -9959.7607421875, 942.342041015625, 33.25298309326171875, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Westfall - Difficulty: 0) CreateObject2
(@OGUID+1, 1731, 0, 40, 40, '0', 0, 0, -9942.2314453125, 875.8507080078125, 32.7149505615234375, 0, 0, 0, 0, 1, 120, 255, 1, 67602); -- Copper Vein (Area: Westfall - Difficulty: 0) CreateObject2

DELETE FROM `pool_template` WHERE `entry` = @POOLID+0;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Westfall - Hill - Copper Vein Group');

DELETE FROM `pool_members` WHERE (`type` = 1 AND `spawnId` IN (@OGUID+0,@OGUID+1,208341));
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOLID+0, 0, 'Westfall - Hill - Node 1'),
(1, @OGUID+1, @POOLID+0, 0, 'Westfall - Hill - Node 2'),
(1, 208341, @POOLID+0, 0, 'Westfall - Hill - Node 3');
