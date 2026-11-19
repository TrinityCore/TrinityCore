SET @CGUID := 6001052;
SET @OGUID := 6000601;

SET @NPCTEXTID := 560009;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8223.3056640625, 737.59552001953125, 74.54803466796875, 3.687657356262207031, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 16908, 0, 1519, 5316, '0', 0, 0, 0, 0, -8258.591796875, 657.30902099609375, 93.00539398193359375, 5.141171932220458984, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Arielle Snapflash (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: 258389 - Photographer State)
(@CGUID+2, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8167.203125, 795.4774169921875, 74.46102142333984375, 3.801042079925537109, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8175.07666015625, 803.56597900390625, 74.1561126708984375, 4.07372903823852539, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8211.08203125, 759.59503173828125, 72.89377593994140625, 0.833769798278808593, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+5, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8180.49169921875, 763.4365234375, 71.92041778564453125, 5.810785770416259765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+6, 133675, 0, 1519, 5316, '0', 0, 0, 0, 0, -8273.1923828125, 735.61285400390625, 78.48775482177734375, 5.304184913635253906, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Peasant Worker (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@CGUID+7, 133675, 0, 1519, 5316, '0', 0, 0, 0, 1, -8263.7294921875, 731.09552001953125, 78.45843505859375, 3.823138713836669921, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Peasant Worker (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@CGUID+8, 19269, 0, 1519, 5316, '0', 0, 0, 0, 0, -8259.66796875, 656.43756103515625, 93.0065460205078125, 4.108332157135009765, 120, 2, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Shutterbug (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 133675, 0, 1519, 5316, '0', 0, 0, 0, 1, -8239.50390625, 712.86285400390625, 77.01202392578125, 3.41656351089477539, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Peasant Worker (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@CGUID+10, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8257.6220703125, 761.40972900390625, 79.53528594970703125, 0.789030730724334716, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8232.40625, 748.013916015625, 74.309295654296875, 4.028546810150146484, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+12, 44395, 0, 1519, 5316, '0', 0, 0, 0, 1, -8284.138671875, 724.4132080078125, 79.99713897705078125, 0.562285959720611572, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Celestine of the Harvest (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@CGUID+13, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8210.1943359375, 801.638916015625, 70.34906005859375, 0.369651556015014648, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+14, 68, 0, 1519, 9171, '0', 0, 0, 0, 1, -8154.38037109375, 838.404541015625, 74.29506683349609375, 2.348163366317749023, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Stormwind Embassy - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 68, 0, 1519, 9171, '0', 0, 0, 0, 1, -8131.37841796875, 815.201416015625, 73.996673583984375, 5.414008617401123046, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Stormwind Embassy - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+16, 68, 0, 1519, 5316, '0', 0, 0, 0, 1, -8291.30859375, 619.75225830078125, 94.01540374755859375, 1.932029128074645996, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+17, 68, 0, 1519, 9171, '0', 0, 0, 0, 1, -8132.67236328125, 846.6009521484375, 75.0034637451171875, 3.431411504745483398, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Stormwind City Guard (Area: Stormwind Embassy - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+18, 68, 0, 1519, 9171, '0', 0, 0, 0, 1, -8141.84033203125, 858.125, 75.83577728271484375, 3.661317110061645507, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261); -- Stormwind City Guard (Area: Stormwind Embassy - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- Peasant Worker
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 15024, 0, 0, 0, ''), -- Peasant Worker
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 415, 0, 0, 0, 0, ''); -- Stormwind City Guard

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 281304, 0, 1519, 5316, '0', 0, 0, -8268.5400390625, 726.38714599609375, 78.07082366943359375, 2.438763141632080078, 0, 0, 0.938886642456054687, 0.34422650933265686, 120, 255, 1, 55261), -- Heavy Logs (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+1, 281304, 0, 1519, 5316, '0', 0, 0, -8264.3193359375, 730.4461669921875, 78.6899261474609375, 5.337895393371582031, 0.782235622406005859, -0.3968353271484375, -0.22313117980957031, 0.425254762172698974, 120, 255, 1, 55261), -- Heavy Logs (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+2, 281304, 0, 1519, 5316, '0', 0, 0, -8273.4912109375, 732.451416015625, 78.08438873291015625, 0.599288463592529296, 0, 0, 0.295180320739746093, 0.955441534519195556, 120, 255, 1, 55261), -- Heavy Logs (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+3, 231870, 0, 1519, 5316, '0', 0, 0, -8268.0908203125, 739.046875, 78.3805389404296875, 0.758019685745239257, -0.0019698143005371, 0.006880760192871093, 0.369986534118652343, 0.929009556770324707, 120, 255, 1, 55261); -- Lumber (Area: Olivia's Pond - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = (16908 /*16908 (Arielle Snapflash) - Photographer State*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(16908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '258389'); -- 16908 (Arielle Snapflash) - Photographer State

-- Gossip
UPDATE `creature_template_gossip` SET `VerifiedBuild`=55261 WHERE (`CreatureID`=16908 AND `MenuID`=21896);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 141834, 0, 0, 0, 0, 0, 0, 0, 55261); -- 16908 (Arielle Snapflash)

DELETE FROM `gossip_menu` WHERE (`MenuID`=21898 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21898, @NPCTEXTID+0, 55261); -- 16908 (Arielle Snapflash)

DELETE FROM `gossip_menu` WHERE (`MenuID`=21897 AND `TextID`=33468);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21897, 33468, 55261); -- 16908 (Arielle Snapflash)

UPDATE `gossip_menu_option` SET `GossipOptionID`=48098, `ActionMenuID`=21898, `VerifiedBuild`=55261 WHERE (`MenuID`=21896 AND `OptionID`=2);
UPDATE `gossip_menu_option` SET `GossipOptionID`=48096, `ActionMenuID`=21897, `VerifiedBuild`=55261 WHERE (`MenuID`=21896 AND `OptionID`=0);

-- Path for Stormwind City Guard
SET @ENTRY := 68;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Stormwind City Guard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8275.764, 583.2049, 106.7072, NULL, 0),
(@PATH, 1, -8279.741, 592.9045, 102.313, NULL, 0),
(@PATH, 2, -8284.179, 602.6858, 99.55208, NULL, 0),
(@PATH, 3, -8288.979, 613.5608, 96.47079, NULL, 0),
(@PATH, 4, -8291.721, 620.8438, 93.61145, NULL, 0),
(@PATH, 5, -8295.143, 626.2239, 91.91206, NULL, 0),
(@PATH, 6, -8299.415, 631.5816, 92.14259, NULL, 0),
(@PATH, 7, -8302.382, 635.0521, 92.14259, NULL, 5693),
(@PATH, 8, -8299.415, 631.5816, 92.14259, NULL, 0),
(@PATH, 9, -8295.143, 626.2239, 91.91206, NULL, 0),
(@PATH, 10, -8291.721, 620.8438, 93.61145, NULL, 0),
(@PATH, 11, -8288.979, 613.5608, 96.47079, NULL, 0),
(@PATH, 12, -8284.179, 602.6858, 99.55208, NULL, 0),
(@PATH, 13, -8279.741, 592.9045, 102.313, NULL, 0),
(@PATH, 14, -8275.764, 583.2049, 106.7072, NULL, 0),
(@PATH, 15, -8274.021, 575.0851, 111.3611, NULL, 0),
(@PATH, 16, -8272.524, 567.7448, 115.3792, NULL, 0),
(@PATH, 17, -8272.408, 563.0035, 116.4623, NULL, 0),
(@PATH, 18, -8271.732, 556.5104, 117.4161, NULL, 5705),
(@PATH, 19, -8272.408, 563.0035, 116.4623, NULL, 0),
(@PATH, 20, -8272.524, 567.7448, 115.3792, NULL, 0),
(@PATH, 21, -8274.021, 575.0851, 111.3611, NULL, 0);

UPDATE `creature` SET `position_x`= -8275.764, `position_y`= 583.2049, `position_z`= 106.7072, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+16, @PATH, 1);

-- Path for Stormwind City Guard
SET @ENTRY := 68;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Stormwind City Guard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8227.866, 743.2621, 73.81104, NULL, 0),
(@PATH, 1, -8220.775, 750.3027, 73.46011, NULL, 0),
(@PATH, 2, -8211.764, 758.8438, 72.91174, NULL, 0),
(@PATH, 3, -8201.335, 770.3195, 72.51305, NULL, 5148),
(@PATH, 4, -8211.764, 758.8438, 72.91174, NULL, 0),
(@PATH, 5, -8220.705, 750.368, 73.48283, NULL, 0),
(@PATH, 6, -8227.866, 743.2621, 73.81104, NULL, 0),
(@PATH, 7, -8239.181, 732.4219, 74.42826, NULL, 0),
(@PATH, 8, -8246.879, 722.7899, 76.25071, NULL, 0),
(@PATH, 9, -8253.113, 714.3281, 77.88731, NULL, 0),
(@PATH, 10, -8261.564, 704.1511, 79.80952, NULL, 0),
(@PATH, 11, -8270.486, 697.7361, 82.16895, NULL, 0),
(@PATH, 12, -8279.255, 691.382, 84.48003, NULL, 0),
(@PATH, 13, -8287.52, 684.9566, 86.71638, NULL, 0),
(@PATH, 14, -8292.708, 680.368, 87.31591, NULL, 6104),
(@PATH, 15, -8287.52, 684.9566, 86.71638, NULL, 0),
(@PATH, 16, -8279.255, 691.382, 84.48003, NULL, 0),
(@PATH, 17, -8270.486, 697.7361, 82.16895, NULL, 0),
(@PATH, 18, -8261.564, 704.1511, 79.80952, NULL, 0),
(@PATH, 19, -8253.113, 714.3281, 77.88731, NULL, 0),
(@PATH, 20, -8246.879, 722.7899, 76.25071, NULL, 0),
(@PATH, 21, -8239.181, 732.4219, 74.42826, NULL, 0);

UPDATE `creature` SET `position_x`= -8227.866, `position_y`= 743.2621, `position_z`= 73.81104, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+4, @PATH, 1);

-- Path for Stormwind City Guard
SET @ENTRY := 68;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Stormwind City Guard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8202.014, 793.2118, 71.56516, NULL, 0),
(@PATH, 1, -8200.861, 786.1805, 72.43179, NULL, 0),
(@PATH, 2, -8197.779, 778.5469, 72.43179, NULL, 0),
(@PATH, 3, -8194.969, 773.9132, 72.43184, NULL, 0),
(@PATH, 4, -8189.84, 769.3403, 72.38821, NULL, 0),
(@PATH, 5, -8185.043, 765.6893, 72.07549, NULL, 0),
(@PATH, 6, -8171.463, 758.5364, 71.90871, NULL, 0),
(@PATH, 7, -8160.479, 757.8715, 71.34776, NULL, 0),
(@PATH, 8, -8152.073, 758.4705, 71.90298, NULL, 0),
(@PATH, 9, -8143.925, 760.559, 70.3463, NULL, 0),
(@PATH, 10, -8138.712, 763.25, 68.64584, NULL, 0),
(@PATH, 11, -8130.672, 768.2327, 67.60023, NULL, 0),
(@PATH, 12, -8120.094, 778.6146, 67.83028, NULL, 0),
(@PATH, 13, -8115.304, 783.3559, 67.87724, NULL, 0),
(@PATH, 14, -8109.165, 789.7274, 67.37494, NULL, 0),
(@PATH, 15, -8104.455, 794.6823, 67.89471, NULL, 0),
(@PATH, 16, -8099.837, 800.7101, 68.05727, NULL, 0),
(@PATH, 17, -8095.335, 807.7882, 69.25739, NULL, 0),
(@PATH, 18, -8093.356, 813.691, 70.05808, NULL, 0),
(@PATH, 19, -8093.306, 820.2118, 70.10638, NULL, 0),
(@PATH, 20, -8094.741, 828.132, 70.05286, NULL, 0),
(@PATH, 21, -8097.566, 836.5643, 70.05286, NULL, 0),
(@PATH, 22, -8101.535, 841.9184, 70.8119, NULL, 0),
(@PATH, 23, -8105.8, 845.5156, 72.00533, NULL, 0),
(@PATH, 24, -8110.396, 846.7934, 73.04762, NULL, 0),
(@PATH, 25, -8115.587, 847.868, 74.20078, NULL, 0),
(@PATH, 26, -8120.559, 848.4102, 75.03396, NULL, 0),
(@PATH, 27, -8124.399, 848.4514, 75.46967, NULL, 0),
(@PATH, 28, -8128.837, 847.7448, 75.34218, NULL, 0),
(@PATH, 29, -8133.653, 846.3073, 74.95817, NULL, 0),
(@PATH, 30, -8139.639, 847.4583, 75.17739, NULL, 0),
(@PATH, 31, -8144.391, 849.6927, 75.39097, NULL, 0),
(@PATH, 32, -8150.736, 852.2413, 75.03195, NULL, 0),
(@PATH, 33, -8156.207, 853.7639, 74.01491, NULL, 0),
(@PATH, 34, -8161.844, 853.0938, 72.29739, NULL, 0),
(@PATH, 35, -8169.999, 849.5764, 70.54916, NULL, 0),
(@PATH, 36, -8176.272, 844.7864, 70.06846, NULL, 0),
(@PATH, 37, -8180.471, 839.9184, 70.06846, NULL, 0),
(@PATH, 38, -8183.74, 836.0278, 70.1051, NULL, 0),
(@PATH, 39, -8189.064, 829.0816, 70.11334, NULL, 0),
(@PATH, 40, -8191.901, 824.5486, 70.04467, NULL, 0),
(@PATH, 41, -8195.717, 817.8108, 70.04467, NULL, 0),
(@PATH, 42, -8199.051, 810.1927, 70.2079, NULL, 0),
(@PATH, 43, -8201.641, 798.9861, 70.74409, NULL, 0);

UPDATE `creature` SET `position_x`= -8202.014, `position_y`= 793.2118, `position_z`= 71.56516, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Path for Stormwind City Guard
SET @ENTRY := 68;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Stormwind City Guard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8119.018, 825.3455, 74.83813, NULL, 5684),
(@PATH, 1, -8124.037, 826.3507, 74.05501, NULL, 0),
(@PATH, 2, -8129.217, 830.5452, 73.93543, NULL, 0),
(@PATH, 3, -8134.293, 835.7274, 74.09576, NULL, 0),
(@PATH, 4, -8138.397, 840.0643, 74.22985, NULL, 0),
(@PATH, 5, -8141.396, 845.8906, 74.76312, NULL, 6828),
(@PATH, 6, -8138.397, 840.0643, 74.22985, NULL, 0),
(@PATH, 7, -8134.293, 835.7274, 74.09576, NULL, 0),
(@PATH, 8, -8129.217, 830.5452, 73.93543, NULL, 0),
(@PATH, 9, -8124.037, 826.3507, 74.05501, NULL, 0);

UPDATE `creature` SET `position_x`= -8119.018, `position_y`= 825.3455, `position_z`= 74.83813, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+17;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+17;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+17, @PATH, 1);
