SET @OGUID := 167089;
SET @POOLID := 3000016;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 1731, 0, 40, 2, '0', 0, 0, -9670.3505859375, 1187.3697509765625, 14.96470832824707031, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+1, 1731, 0, 40, 2, '0', 0, 0, -9665.861328125, 1042.310791015625, 19.21788978576660156, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+2, 1731, 0, 40, 2, '0', 0, 0, -10050.2001953125, 1899.4100341796875, 15.33469963073730468, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+3, 1731, 0, 40, 2, '0', 0, 0, -10136.400390625, 1939.3499755859375, 17.62779998779296875, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+4, 1731, 0, 40, 2, '0', 0, 0, -9960.849609375, 1835.030029296875, 18.21800041198730468, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+5, 1731, 0, 40, 2, '0', 0, 0, -10315.7001953125, 2005.969970703125, 18.7154998779296875, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+6, 1731, 0, 40, 113, '0', 0, 0, -10226.400390625, 2045.699951171875, 8.463399887084960937, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+7, 1731, 0, 40, 2, '0', 0, 0, -10169, 2039.0799560546875, 6.377749919891357421, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Longshore - Difficulty: 0) CreateObject2
(@OGUID+8, 1731, 0, 40, 113, '0', 0, 0, -10595.765625, 1991.4791259765625, -4.40479898452758789, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+9, 1731, 0, 40, 113, '0', 0, 0, -10509.7626953125, 1948.857666015625, 6.023728847503662109, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+10, 1731, 0, 40, 113, '0', 0, 0, -10543.4619140625, 1943.9947509765625, 1.93717360496520996, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+11, 1731, 0, 40, 113, '0', 0, 0, -10545.7998046875, 2011.449951171875, -7.60355997085571289, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+12, 1731, 0, 40, 113, '0', 0, 0, -10468.7138671875, 1999.8524169921875, 8.843868255615234375, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+13, 1731, 0, 40, 113, '0', 0, 0, -10460.978515625, 1962.6475830078125, 8.691979408264160156, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+14, 1731, 0, 40, 113, '0', 0, 0, -10452.75390625, 1922.142333984375, 10.66243457794189453, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+15, 1731, 0, 40, 113, '0', 0, 0, -10478.123046875, 1930.748291015625, 7.9247283935546875, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Gold Coast Quarry - Difficulty: 0) CreateObject2
(@OGUID+16, 1731, 0, 40, 5290, '0', 0, 0, -10405.8994140625, 1868.390625, 11.06051921844482421, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+17, 1731, 0, 40, 5290, '0', 0, 0, -10350.5, 1796.1500244140625, 22.73110008239746093, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+18, 1731, 0, 40, 5290, '0', 0, 0, -10400.599609375, 1755.949951171875, -18.0284004211425781, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+19, 1731, 0, 40, 5290, '0', 0, 0, -10255.2998046875, 1677.1800537109375, 25.50550079345703125, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+20, 1731, 0, 40, 5290, '0', 0, 0, -10317.7001953125, 1525.9000244140625, 31.68210029602050781, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+21, 1731, 0, 40, 5290, '0', 0, 0, -10274.099609375, 1602.81005859375, 12.45919990539550781, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: The Raging Chasm - Difficulty: 0) CreateObject2
(@OGUID+22, 1731, 0, 40, 219, '0', 0, 0, -10462.7998046875, 1555.050048828125, 15.09270000457763671, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Alexston Farmstead - Difficulty: 0) CreateObject2
(@OGUID+23, 1731, 0, 40, 219, '0', 0, 0, -10506.2001953125, 1566.5799560546875, 28.02580070495605468, 0, 0, 0, 0, 1, 120, 255, 1, 67602), -- Copper Vein (Area: Alexston Farmstead - Difficulty: 0) CreateObject2
(@OGUID+24, 1731, 0, 40, 219, '0', 0, 0, -10565.099609375, 1727.6300048828125, 34.85540008544921875, 0, 0, 0, 0, 1, 120, 255, 1, 67602); -- Copper Vein (Area: Alexston Farmstead - Difficulty: 0) CreateObject2

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+7;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Westfall - Beach 1 - Copper Vein Group'),
(@POOLID+1, 1, 'Westfall - Beach 2 - Copper Vein Group'),
(@POOLID+2, 1, 'Westfall - Beach 3 - Copper Vein Group'),
(@POOLID+3, 1, 'Westfall - Gold Coast Quarry Cave 1 - Copper Vein Group'),
(@POOLID+4, 1, 'Westfall - Gold Coast Quarry Cave 2 - Copper Vein Group'),
(@POOLID+5, 1, 'Westfall - The Raging Chasm 1 - Copper Vein Group'),
(@POOLID+6, 1, 'Westfall - The Raging Chasm 2 - Copper Vein Group'),
(@POOLID+7, 1, 'Westfall - The Raging Chasm 3 - Copper Vein Group');

DELETE FROM `pool_members` WHERE (`type` = 1 AND `spawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11,@OGUID+12,@OGUID+13,@OGUID+14,@OGUID+15,@OGUID+16,@OGUID+17,@OGUID+18,@OGUID+19,@OGUID+20,@OGUID+21,@OGUID+22,@OGUID+23,@OGUID+24,208416,208385,208280,208270,208275,208276,208282,208260));
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOLID+0, 0, 'Westfall - Beach 1 - Node 1'),
(1, @OGUID+1, @POOLID+0, 0, 'Westfall - Beach 1 - Node 2'),
(1, 208416, @POOLID+0, 0, 'Westfall - Beach 1 - Node 3'),
(1, @OGUID+2, @POOLID+1, 0, 'Westfall - Beach 2 - Node 1'),
(1, @OGUID+3, @POOLID+1, 0, 'Westfall - Beach 2 - Node 2'),
(1, @OGUID+4, @POOLID+1, 0, 'Westfall - Beach 2 - Node 3'),
(1, 208385, @POOLID+1, 0, 'Westfall - Beach 2 - Node 4'),
(1, @OGUID+5, @POOLID+2, 0, 'Westfall - Beach 3 - Node 1'),
(1, @OGUID+6, @POOLID+2, 0, 'Westfall - Beach 3 - Node 2'),
(1, @OGUID+7, @POOLID+2, 0, 'Westfall - Beach 3 - Node 3'),
(1, 208280, @POOLID+2, 0, 'Westfall - Beach 3 - Node 4'),
(1, @OGUID+8, @POOLID+3, 0, 'Gold Coast Quarry Cave 1 - Node 1'),
(1, @OGUID+9, @POOLID+3, 0, 'Gold Coast Quarry Cave 1 - Node 2'),
(1, @OGUID+10, @POOLID+3, 0, 'Gold Coast Quarry Cave 1 - Node 3'),
(1, @OGUID+11, @POOLID+3, 0, 'Gold Coast Quarry Cave 1 - Node 4'),
(1, 208270, @POOLID+3, 0, 'Gold Coast Quarry Cave 1 - Node 5'),
(1, @OGUID+12, @POOLID+4, 0, 'Gold Coast Quarry Cave 2 - Node 1'),
(1, @OGUID+13, @POOLID+4, 0, 'Gold Coast Quarry Cave 2 - Node 2'),
(1, @OGUID+14, @POOLID+4, 0, 'Gold Coast Quarry Cave 2 - Node 3'),
(1, @OGUID+15, @POOLID+4, 0, 'Gold Coast Quarry Cave 2 - Node 4'),
(1, 208275, @POOLID+4, 0, 'Gold Coast Quarry Cave 2 - Node 5'),
(1, @OGUID+16, @POOLID+5, 0, 'The Raging Chasm 1 - Node 1'),
(1, @OGUID+17, @POOLID+5, 0, 'The Raging Chasm 1 - Node 2'),
(1, @OGUID+18, @POOLID+5, 0, 'The Raging Chasm 1 - Node 3'),
(1, 208276, @POOLID+5, 0, 'The Raging Chasm 1 - Node 4'),
(1, @OGUID+19, @POOLID+6, 0, 'The Raging Chasm 2 - Node 1'),
(1, @OGUID+20, @POOLID+6, 0, 'The Raging Chasm 2 - Node 2'),
(1, @OGUID+21, @POOLID+6, 0, 'The Raging Chasm 2 - Node 3'),
(1, 208282, @POOLID+6, 0, 'The Raging Chasm 2 - Node 4'),
(1, @OGUID+22, @POOLID+7, 0, 'The Raging Chasm 3 - Node 1'),
(1, @OGUID+23, @POOLID+7, 0, 'The Raging Chasm 3 - Node 2'),
(1, @OGUID+24, @POOLID+7, 0, 'The Raging Chasm 3 - Node 3'),
(1, 208260, @POOLID+7, 0, 'The Raging Chasm 3 - Node 4');
