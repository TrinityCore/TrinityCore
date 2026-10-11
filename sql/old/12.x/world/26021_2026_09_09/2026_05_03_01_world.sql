SET @CGUID := 11000808;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -27.2621536254882812, -2171.12841796875, 1174.1876220703125, 5.686717987060546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+1, 249690, 2694, 15355, 15922, '0', 0, 0, 0, 0, -31.6458339691162109, -2152.125, 1181.4559326171875, 4.539616107940673828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Root-darting Firefly (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+2, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -14.140625, -2139.923583984375, 1175.286865234375, 3.034853219985961914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+3, 253251, 2694, 15355, 15922, '0', 0, 0, 0, 0, -63.1024322509765625, -2180.23779296875, 1176.5260009765625, 3.88161635398864746, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Lashroom Bud (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+4, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, 10.40277767181396484, -2108.3125, 1167.3509521484375, 3.034853219985961914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+5, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -17.6944446563720703, -2113.826416015625, 1193.98193359375, 3.24378204345703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+6, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, 12.00173664093017578, -2009.28125, 1153.1044921875, 3.598376035690307617, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+7, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -19.0625, -2088.9619140625, 1167.46533203125, 0.211842939257621765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+8, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -32.5434036254882812, -2175.65625, 1174.4580078125, 6.183427333831787109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+9, 237204, 2694, 15355, 15922, '0', 0, 0, 0, 0, 3.012152910232543945, -2055.607666015625, 1161.37646484375, 4.408668041229248046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Surly Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+10, 249690, 2694, 15355, 15922, '0', 0, 0, 0, 0, -51.4861106872558593, -2105.15283203125, 1185.603515625, 1.620810747146606445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Root-darting Firefly (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 237204, 2694, 15355, 15922, '0', 0, 0, 0, 0, -44.7621536254882812, -2113.09033203125, 1171.0224609375, 3.767470598220825195, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Surly Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+12, 241751, 2694, 15355, 15922, '0', 0, 0, 0, 0, -29.7378482818603515, -2181.140625, 1174.427978515625, 2.481104135513305664, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314), -- Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+13, 241751, 2694, 15355, 15922, '0', 0, 0, 0, 0, -118.631942749023437, -2065.354248046875, 1154.4388427734375, 2.687990188598632812, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314), -- Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+14, 246467, 2694, 15355, 15922, '0', 0, 0, 0, 0, 8.954861640930175781, -2107.892333984375, 1167.3173828125, 5.798959255218505859, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314), -- Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+15, 241751, 2694, 15355, 15922, '0', 0, 0, 0, 0, -19.1336803436279296, -2176.9375, 1175.447265625, 0, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314), -- Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+16, 251982, 2694, 15355, 15922, '0', 0, 0, 0, 0, -153.178817749023437, -2130.763916015625, 1175.458740234375, 5.437462806701660156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Plodding Potadling (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+17, 249690, 2694, 15355, 15922, '0', 0, 0, 0, 0, -129.960067749023437, -2167.05908203125, 1189.1146240234375, 2.040605545043945312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Root-darting Firefly (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+18, 249690, 2694, 15355, 15922, '0', 0, 0, 0, 0, -136.201385498046875, -2083.788330078125, 1178.3690185546875, 0.109118066728115081, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Root-darting Firefly (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+19, 251982, 2694, 15355, 15922, '0', 0, 0, 0, 0, -189.723953247070312, -2081.671875, 1161.7314453125, 3.975203514099121093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Plodding Potadling (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+20, 251982, 2694, 15355, 15922, '0', 0, 0, 0, 0, -182.461807250976562, -2093.96533203125, 1160.112548828125, 1.652510285377502441, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Plodding Potadling (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+21, 251982, 2694, 15355, 15922, '0', 0, 0, 0, 0, -179.072921752929687, -2097.192626953125, 1160.6962890625, 2.047296524047851562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Plodding Potadling (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+22, 256534, 2694, 15355, 15922, '0', 0, 0, 0, 0, -152.585067749023437, -2141.296875, 1209.685791015625, 0.789195179939270019, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 67314); -- Spore-dusted Moth (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Agitated Thorntalon
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Agitated Thorntalon
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Agitated Thorntalon
(@CGUID+12, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Thorntalon
(@CGUID+13, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Thorntalon
(@CGUID+14, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Potatoad
(@CGUID+15, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Thorntalon
(@CGUID+22, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Spore-dusted Moth

-- Template
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0xC1000000 WHERE `entry`=241751; -- Thorntalon

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x20000100, `StaticFlags5`=0x1, `VerifiedBuild`=67314 WHERE (`Entry`=241751 AND `DifficultyID`=0); -- 241751 (Thorntalon) - Sessile, Floating - UntargetableByClient
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x20000100, `StaticFlags5`=0x1, `VerifiedBuild`=67314 WHERE (`Entry`=246467 AND `DifficultyID`=0); -- 246467 (Potatoad) - Sessile, Floating - UntargetableByClient

-- Difficulty override
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` = (@CGUID+5);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
((@CGUID+5), 0, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Path for Glimmering Petalwing
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 253881;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Glimmering Petalwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -32.92191, -2115.388, 1193.9819, NULL, 0),
(@PATH, 1, -44.79361, -2105.7249, 1193.9819, NULL, 0),
(@PATH, 2, -46.355247, -2090.4973, 1193.9819, NULL, 0),
(@PATH, 3, -36.692047, -2078.6257, 1193.9819, NULL, 0),
(@PATH, 4, -21.464573, -2077.064, 1193.9819, NULL, 0),
(@PATH, 5, -9.59288, -2086.7273, 1193.9819, NULL, 0),
(@PATH, 6, -8.031242, -2101.9548, 1193.9819, NULL, 0),
(@PATH, 7, -17.694447, -2113.8264, 1193.9819, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Glimmering Petalwing

-- Path for Root-darting Firefly
SET @MOVERGUID := @CGUID+10;
SET @ENTRY := 249690;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Root-darting Firefly - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -52.06006, -2093.6868, 1185.6035, NULL, 0),
(@PATH, 1, -44.358112, -2085.173, 1185.6035, NULL, 0),
(@PATH, 2, -32.89196, -2084.599, 1185.6035, NULL, 0),
(@PATH, 3, -24.37833, -2092.301, 1185.6035, NULL, 0),
(@PATH, 4, -23.804382, -2103.767, 1185.6035, NULL, 0),
(@PATH, 5, -31.506332, -2112.2808, 1185.6035, NULL, 0),
(@PATH, 6, -42.97248, -2112.8547, 1185.6035, NULL, 0),
(@PATH, 7, -51.486115, -2105.1528, 1185.6035, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Root-darting Firefly
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 249690;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Root-darting Firefly - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -33.6195, -2163.4346, 1181.4559, NULL, 0),
(@PATH, 1, -43.01217, -2170.0361, 1181.4559, NULL, 0),
(@PATH, 2, -54.321747, -2168.0625, 1181.4559, NULL, 0),
(@PATH, 3, -60.92324, -2158.6697, 1181.4559, NULL, 0),
(@PATH, 4, -58.949577, -2147.36, 1181.4559, NULL, 0),
(@PATH, 5, -49.5569, -2140.7585, 1181.4559, NULL, 0),
(@PATH, 6, -38.247322, -2142.7324, 1181.4559, NULL, 0),
(@PATH, 7, -31.645834, -2152.125, 1181.4559, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Root-darting Firefly
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 249690;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Root-darting Firefly - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -135.15744, -2156.8225, 1189.1146, NULL, 0),
(@PATH, 1, -131.59413, -2145.909, 1189.1146, NULL, 0),
(@PATH, 2, -121.35747, -2140.7114, 1189.1146, NULL, 0),
(@PATH, 3, -110.443954, -2144.275, 1189.1146, NULL, 0),
(@PATH, 4, -105.24658, -2154.5115, 1189.1146, NULL, 0),
(@PATH, 5, -108.8099, -2165.425, 1189.1146, NULL, 0),
(@PATH, 6, -119.046555, -2170.6223, 1189.1146, NULL, 0),
(@PATH, 7, -129.96007, -2167.059, 1189.1146, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Root-darting Firefly
SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 249690;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Root-darting Firefly - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -124.78918, -2082.538, 1178.369, NULL, 0),
(@PATH, 1, -115.83541, -2089.7236, 1178.369, NULL, 0),
(@PATH, 2, -114.58509, -2101.1357, 1178.369, NULL, 0),
(@PATH, 3, -121.77063, -2110.0896, 1178.369, NULL, 0),
(@PATH, 4, -133.18285, -2111.3398, 1178.369, NULL, 0),
(@PATH, 5, -142.13661, -2104.1543, 1178.369, NULL, 0),
(@PATH, 6, -143.38693, -2092.7422, 1178.369, NULL, 0),
(@PATH, 7, -136.20139, -2083.7883, 1178.369, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);
