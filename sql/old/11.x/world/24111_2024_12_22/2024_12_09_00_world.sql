SET @CGUID := 10004706;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 516.14239501953125, -1191.5538330078125, 3.036458253860473632, 5.637444019317626953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+1, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 539.0555419921875, -1205.84033203125, 3.69051527976989746, 0.731023848056793212, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+2, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 579.779541015625, -1162.0833740234375, 1.973518252372741699, 3.870385169982910156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject
(@CGUID+3, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 597.1492919921875, -1152.4288330078125, 2.725077152252197265, 0.746696650981903076, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+4, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 557.7430419921875, -1277.8228759765625, 84.33486175537109375, 5.328208446502685546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 502.6475830078125, -1305.5521240234375, 66.0788726806640625, 6.167536735534667968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 498.87847900390625, -1305.1614990234375, 65.6339263916015625, 2.597638607025146484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 435.354156494140625, -1383.107666015625, 59.3994598388671875, 4.610696792602539062, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+8, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 450.59375, -1364.6024169921875, 53.02747344970703125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+9, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 456.873260498046875, -1301.78125, 38.88599395751953125, 0.463679462671279907, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+10, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 442.454864501953125, -1385.8316650390625, 60.90817642211914062, 3.812271595001220703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+11, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 479.21527099609375, -1418.3992919921875, 95.029052734375, 0.568114817142486572, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+12, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 457.2725830078125, -1445.373291015625, 88.80190277099609375, 0.171635612845420837, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+13, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 442.53472900390625, -1468.9305419921875, 104.7057342529296875, 1.178098559379577636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+14, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 438.635406494140625, -1404.111083984375, 88.50864410400390625, 1.178098559379577636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+15, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 384.729156494140625, -1505.8524169921875, 58.93576431274414062, 5.959266185760498046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+16, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 426.935760498046875, -1565.548583984375, 120.7727432250976562, 6.040287017822265625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+17, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 427.8125, -1620.3785400390625, 145.583831787109375, 1.133505821228027343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+18, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 591.22393798828125, -1436.99658203125, 176.356842041015625, 2.102684497833251953, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+19, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 557.77606201171875, -1491.954833984375, 201.1458892822265625, 2.842222213745117187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+20, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 603.388916015625, -1435.329833984375, 174.74652099609375, 0.576585173606872558, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+21, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 545.43402099609375, -1573.0416259765625, 241.912384033203125, 4.568681716918945312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+22, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 527.90972900390625, -1497.1163330078125, 208.8530731201171875, 1.178098559379577636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+23, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 557.0382080078125, -1511.40283203125, 213.7317352294921875, 5.828877925872802734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+24, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 665.13018798828125, -1411.7274169921875, 190.0673065185546875, 1.465811133384704589, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+25, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 680.40972900390625, -1457.3072509765625, 174.386138916015625, 1.946326971054077148, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+26, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 648.68402099609375, -1309.6805419921875, 164.9678497314453125, 2.791551113128662109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+27, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 636.467041015625, -1400.876708984375, 183.41650390625, 4.371973514556884765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+28, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 672.92364501953125, -1427.37158203125, 175.9813690185546875, 4.100412368774414062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+29, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 684.029541015625, -1330.5382080078125, 154.8737030029296875, 5.338091373443603515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+30, 222347, 2552, 14717, 0, '0', 0, 0, 0, 0, 740.20831298828125, -1175.9410400390625, 67.09136962890625, 2.988850593566894531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Gnashing Rockwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+31, 222347, 2552, 14717, 0, '0', 0, 0, 0, 0, 825.2257080078125, -1258.87158203125, 83.503173828125, 0.45583614706993103, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689); -- Gnashing Rockwing (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 223657;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(223657, 0, 223891, 60, 1, 1, 0, 1, 1, 'Igneous Core');

UPDATE `creature_template_difficulty` SET `LootID` = 223657 WHERE `Entry` = 223657;

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=223924 AND `quest` = 82466);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(223924, 82466, 57689); -- What We Do For Gems ended by Natalia Pearce

-- Path for Sharptalon Kestral
SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 227638;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8684, 'Sharptalon Kestral - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 447.221, -1457.6168, 104.705734, NULL, 0),
(@PATH, 1, 458.53473, -1452.9305, 104.705734, NULL, 0),
(@PATH, 2, 469.84845, -1457.6168, 104.705734, NULL, 0),
(@PATH, 3, 474.53473, -1468.9305, 104.705734, NULL, 0),
(@PATH, 4, 469.84845, -1480.2443, 104.705734, NULL, 0),
(@PATH, 5, 458.53473, -1484.9305, 104.705734, NULL, 0),
(@PATH, 6, 447.221, -1480.2443, 104.705734, NULL, 0),
(@PATH, 7, 442.53473, -1468.9305, 104.705734, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharptalon Kestral
SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 227638;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8684, 'Sharptalon Kestral - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 443.3217, -1392.7974, 88.508644, NULL, 0),
(@PATH, 1, 454.6354, -1388.1111, 88.508644, NULL, 0),
(@PATH, 2, 465.94913, -1392.7974, 88.508644, NULL, 0),
(@PATH, 3, 470.6354, -1404.1111, 88.508644, NULL, 0),
(@PATH, 4, 465.9491, -1415.4248, 88.508644, NULL, 0),
(@PATH, 5, 454.6354, -1420.1111, 88.508644, NULL, 0),
(@PATH, 6, 443.3217, -1415.4248, 88.508644, NULL, 0),
(@PATH, 7, 438.6354, -1404.1111, 88.508644, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharptalon Kestral
SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 227638;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8684, 'Sharptalon Kestral - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 532.596, -1485.8026, 208.85307, NULL, 0),
(@PATH, 1, 543.9097, -1481.1163, 208.85307, NULL, 0),
(@PATH, 2, 555.22345, -1485.8026, 208.85307, NULL, 0),
(@PATH, 3, 559.9097, -1497.1163, 208.85307, NULL, 0),
(@PATH, 4, 555.22345, -1508.43, 208.85307, NULL, 0),
(@PATH, 5, 543.9097, -1513.1163, 208.85307, NULL, 0),
(@PATH, 6, 532.596, -1508.43, 208.85307, NULL, 0),
(@PATH, 7, 527.9097, -1497.1163, 208.85307, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
