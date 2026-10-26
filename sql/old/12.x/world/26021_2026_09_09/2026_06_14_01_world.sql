SET @OGUID := 167114;
SET @POOLID := 3000024;

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 1731, 0, 40, 2, '0', 0, 0, -10814.400390625, 2051.760009765625, 13.5177001953125, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+1, 1731, 0, 40, 2, '0', 0, 0, -10622, 2026.8900146484375, 21.35239982604980468, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+2, 1731, 0, 40, 2, '0', 0, 0, -10716.7998046875, 2007.4100341796875, 16.44650077819824218, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+3, 1731, 0, 40, 0, '0', 0, 0, -10981.599609375, 1982.4200439453125, 35.53820037841796875, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+4, 1731, 0, 40, 0, '0', 0, 0, -10837.2001953125, 1807.81005859375, 40.1593017578125, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+5, 1731, 0, 40, 0, '0', 0, 0, -10897.7001953125, 1908.780029296875, 53.01430130004882812, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+6, 1731, 0, 40, 2, '0', 0, 0, -11236.7998046875, 1950.3699951171875, 14.38290023803710937, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+7, 1731, 0, 40, 2, '0', 0, 0, -11303.900390625, 1884.56005859375, 19.65250015258789062, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+8, 1731, 0, 40, 920, '0', 0, 0, -11125, 1488.09033203125, 49.82100296020507812, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: The Dagger Hills - Difficulty: 0) CreateObject2
(@OGUID+9, 1731, 0, 40, 20, '0', 0, 0, -11053.701171875, 1278.7899169921875, 45.26115798950195312, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Moonbrook - Difficulty: 0) CreateObject2
(@OGUID+10, 1731, 0, 40, 20, '0', 0, 0, -11121.3994140625, 1421.220458984375, 47.39907455444335937, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: Moonbrook - Difficulty: 0) CreateObject2
(@OGUID+11, 1731, 0, 40, 922, '0', 0, 0, -11162.7001953125, 954.77398681640625, 43.94029998779296875, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: The Dust Plains - Difficulty: 0) CreateObject2
(@OGUID+12, 1731, 0, 40, 922, '0', 0, 0, -11205.7001953125, 1049.050048828125, 55.48479843139648437, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: The Dust Plains - Difficulty: 0) CreateObject2
(@OGUID+13, 1731, 0, 40, 922, '0', 0, 0, -11236, 805.41497802734375, 49.08729934692382812, 0, 0, 0, 0, 1, 120, 255, 1, 67823), -- Copper Vein (Area: The Dust Plains - Difficulty: 0) CreateObject2
(@OGUID+14, 1731, 0, 40, 922, '0', 0, 0, -11174.2001953125, 608.25701904296875, 35.86100006103515625, 0, 0, 0, 0, 1, 120, 255, 1, 67823); -- Copper Vein (Area: The Dust Plains - Difficulty: 0) CreateObject2

-- Pool
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+5;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Westfall - Beach 4 - Copper Vein Group'),
(@POOLID+1, 1, 'Westfall - Hill 2 - Copper Vein Group'),
(@POOLID+2, 1, 'Westfall - Beach 5 - Copper Vein Group'),
(@POOLID+3, 1, 'Westfall - The Dagger Hills - Copper Vein Group'),
(@POOLID+4, 1, 'Westfall - The Dust Plains 1 - Copper Vein Group'),
(@POOLID+5, 1, 'Westfall - The Dust Plains 2 - Copper Vein Group');

DELETE FROM `pool_members` WHERE (`type` = 1 AND `spawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11,@OGUID+12,@OGUID+13,@OGUID+14,208271,208218,208102,208172,208103,208106));
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOLID+0, 0, 'Westfall - Beach 4 - Node 1'),
(1, @OGUID+1, @POOLID+0, 0, 'Westfall - Beach 4 - Node 2'),
(1, @OGUID+2, @POOLID+0, 0, 'Westfall - Beach 4 - Node 3'),
(1, 208271, @POOLID+0, 0, 'Westfall - Beach 4 - Node 4'),
(1, @OGUID+3, @POOLID+1, 0, 'Westfall - Hill 2 - Node 1'),
(1, @OGUID+4, @POOLID+1, 0, 'Westfall - Hill 2 - Node 2'),
(1, @OGUID+5, @POOLID+1, 0, 'Westfall - Hill 2 - Node 3'),
(1, 208218, @POOLID+1, 0, 'Westfall - Hill 2 - Node 4'),
(1, @OGUID+6, @POOLID+2, 0, 'Westfall - Beach 5 - Node 1'),
(1, @OGUID+7, @POOLID+2, 0, 'Westfall - Beach 5 - Node 2'),
(1, 208102, @POOLID+2, 0, 'Westfall - Beach 5 - Node 3'),
(1, @OGUID+8, @POOLID+3, 0, 'Westfall - The Dagger Hills - Node 1'),
(1, @OGUID+9, @POOLID+3, 0, 'Westfall - The Dagger Hills - Node 2'),
(1, @OGUID+10, @POOLID+3, 0, 'Westfall - The Dagger Hills - Node 3'),
(1, 208172, @POOLID+3, 0, 'Westfall - The Dagger Hills - Node 4'),
(1, @OGUID+11, @POOLID+4, 0, 'Westfall - The Dust Plains 1 - Node 1'),
(1, @OGUID+12, @POOLID+4, 0, 'Westfall - The Dust Plains 1 - Node 2'),
(1, 208103, @POOLID+4, 0, 'Westfall - The Dust Plains 1 - Node 3'),
(1, @OGUID+13, @POOLID+5, 0, 'Westfall - The Dust Plains 2 - Node 1'),
(1, @OGUID+14, @POOLID+5, 0, 'Westfall - The Dust Plains 2 - Node 2'),
(1, 208106, @POOLID+5, 0, 'Westfall - The Dust Plains 2 - Node 3');
