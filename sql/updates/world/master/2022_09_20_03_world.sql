SET @CGUID := 395602;
SET @OGUID := 239576;

--
-- Forsaken High Command (Introduction)

DELETE FROM `phase_area` WHERE `AreaId`=5369 AND `PhaseId`=264;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(5369, 264, 'Forsaken High Command Intro if 26965 IS NOT rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=264 AND `SourceEntry`=5369 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=26965 AND `ConditionValue2`=64 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 264, 5369, 0, 0, 47, 0, 26965, 64, 0, 1, 0, 0, '', 'Forsaken High Command - Add phase 264 if 26965 IS NOT rewarded');

DELETE FROM `gossip_menu` WHERE (`MenuID`=11823 AND `TextID`=16575);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11823, 16575, 45338); -- 44365 (Lady Sylvanas Windrunner)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1373.3499755859375, 1031.5799560546875, 50.61893081665039062, 0.959931075572967529, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+1, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1374.1400146484375, 1036.3499755859375, 50.92173385620117187, 5.532693862915039062, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+2, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1341.6600341796875, 1020.96002197265625, 54.34383392333984375, 0.48869219422340393, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+3, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1341.199951171875, 1009.04998779296875, 54.68253326416015625, 3.193952560424804687, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+4, 44615, 0, 130, 5369, '0', 264, 0, 0, 0, 1383, 1038.6300048828125, 54.40053176879882812, 3.909537553787231445, 120, 0, 0, 8020, 12780, 0, 0, 0, 0, 45338), -- Grand Executor Mortuus (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+5, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1372.97998046875, 1041.06005859375, 51.38103103637695312, 0.226892799139022827, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+6, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1372.0799560546875, 1034.97998046875, 50.84893035888671875, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+7, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1352.725, 1059.25, 53.049904, 3.361215591430664062, 120, 10, 0, 3208, 0, 2, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1400.9300537109375, 1003.3800048828125, 53.03673171997070312, 2.094395160675048828, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+9, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1375.4200439453125, 1033.81005859375, 50.65223312377929687, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+10, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1345.6600341796875, 1010.6400146484375, 54.39243316650390625, 0.349065840244293212, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+11, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1369.6500244140625, 1033.6700439453125, 50.96683120727539062, 0.698131680488586425, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+12, 44365, 0, 130, 5369, '0', 264, 0, 0, 1, 1381.3499755859375, 1040.72998046875, 54.40043258666992187, 3.909537553787231445, 120, 0, 0, 641600, 17040, 0, 1, 0, 0, 45338), -- Lady Sylvanas Windrunner (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+13, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1389.5400390625, 1047.81005859375, 53.04053115844726562, 3.577924966812133789, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+14, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1378.1600341796875, 1031.7099609375, 51.37173080444335937, 0.767944872379302978, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+15, 44608, 0, 130, 5369, '0', 264, 0, 0, 0, 1364.02001953125, 1028.5400390625, 58.13195419311523437, 0.715584993362426757, 120, 0, 0, 48120, 17040, 0, 0, 0, 0, 45338), -- Agatha (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+16, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1370.6600341796875, 1030.8199462890625, 51.134033203125, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+17, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1369.5699462890625, 1036.9000244140625, 50.9980316162109375, 0.209439516067504882, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+18, 44825, 0, 130, 5369, '0', 264, 0, 0, 1, 1422.9305419921875, 1017.77081298828125, 52.64933395385742187, 2.862339973449707031, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45338), -- Bat Handler Maggotbreath (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+19, 44610, 0, 130, 5369, '0', 264, 0, 0, 0, 1360.81005859375, 1030.5699462890625, 56.87403106689453125, 0.645771801471710205, 120, 0, 0, 48120, 17040, 0, 0, 0, 0, 45338), -- Arthura (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+20, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1376, 1029.6099853515625, 50.93743133544921875, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+21, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1369.7099609375, 1040.18994140625, 51.02123260498046875, 5.585053443908691406, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+22, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1367.1700439453125, 1082.1300048828125, 52.50803375244140625, 4.97418832778930664, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+23, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1367.3299560546875, 1035.3800048828125, 51.3040313720703125, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+24, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1372.5799560546875, 1038.0699462890625, 50.96663284301757812, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+25, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1430.030029296875, 1022.59002685546875, 52.49113082885742187, 3.281219005584716796, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+26, 44609, 0, 130, 5369, '0', 264, 0, 0, 0, 1365.72998046875, 1024.97998046875, 57.02443313598632812, 1.134464025497436523, 120, 0, 0, 48120, 17040, 0, 0, 0, 0, 45338), -- Daschla (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+27, 44592, 0, 130, 5369, '0', 264, 0, 0, 0, 1377.300048828125, 1035.9300537109375, 51.09613037109375, 3.141592741012573242, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+28, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1337.1400146484375, 1018.3900146484375, 54.7498321533203125, 3.59537816047668457, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+29, 44593, 0, 130, 5369, '0', 264, 0, 0, 0, 1375.199951171875, 1038.5799560546875, 51.2451324462890625, 4.555309295654296875, 1, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+30, 44632, 0, 130, 5369, '0', 264, 0, 0, 1, 1438.05, 1068.76, 60.7803, 5.5573577880859375, 120, 10, 0, 3208, 0, 2, 0, 0, 0, 45338); -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+12, 0, 29257, 0, 1, 0, 0, 0, 0, 3, ''); -- Lady Sylvanas Windrunner

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 20655, 0, 130, 5369, '0', 264, 0, 1544.2362060546875, 240.7725677490234375, -40.7835426330566406, 6.274459362030029296, 0, 0, -0.00436305999755859, 0.999990463256835937, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+1, 176594, 0, 130, 5369, '0', 264, 0, 2389.09716796875, 337.902069091796875, 40.01292037963867187, 2.242745637893676757, 0, 0, 0.900697708129882812, 0.434446364641189575, 120, 255, 1, 45338), -- Doors (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+2, 20656, 0, 130, 5369, '0', 264, 0, 1553.2982177734375, 240.6560211181640625, 55.39519119262695312, 6.274459362030029296, 0, 0, -0.00436305999755859, 0.999990463256835937, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+3, 20650, 0, 130, 5369, '0', 264, 0, 1596.037353515625, 282.7376708984375, 55.39520263671875, 4.703663349151611328, 0, 0, -0.71018505096435546, 0.704015016555786132, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+4, 20654, 0, 130, 5369, '0', 264, 0, 1595.212158203125, 178.6932373046875, -40.5222587585449218, 4.703663349151611328, 0, 0, -0.71018505096435546, 0.704015016555786132, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+5, 20652, 0, 130, 5369, '0', 264, 0, 1595.261474609375, 188.644378662109375, -40.7835426330566406, 1.562067151069641113, 0, 0, 0.704013824462890625, 0.710186243057250976, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+6, 20651, 0, 130, 5369, '0', 264, 0, 1596.208984375, 302.400634765625, -40.6645088195800781, 1.562069892883300781, 0, 0, 0.704014778137207031, 0.71018528938293457, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+7, 20657, 0, 130, 5369, '0', 264, 0, 1533.87841796875, 240.82550048828125, -32.3473320007324218, 3.132858037948608398, 0, 0, 0.999990463256835937, 0.004367320332676172, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+8, 20649, 0, 130, 5369, '0', 264, 0, 1596.1539306640625, 291.79974365234375, 14.68224334716796875, 4.703663349151611328, 0, 0, -0.71018505096435546, 0.704015016555786132, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+9, 20653, 0, 130, 5369, '0', 264, 0, 1595.3780517578125, 197.706451416015625, 55.39519119262695312, 1.562067151069641113, 0, 0, 0.704013824462890625, 0.710186243057250976, 120, 255, 24, 45338), -- 0 (Area: Forsaken High Command - Difficulty: 0)
(@OGUID+10, 176594, 0, 130, 5369, '0', 264, 0, 2389.09716796875, 337.902069091796875, 40.01292037963867187, 2.242745637893676757, 0, 0, 0.900697708129882812, 0.434446364641189575, 120, 255, 1, 45338); -- Doors (Area: Forsaken High Command - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+1, 0, 0, 0.900698184967041015, 0.434445321559906005, 0, 0), -- Doors
(@OGUID+2, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+3, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+4, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+5, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+6, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+7, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+8, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+9, 0, 0, -0.00436319690197706, 0.999990463256835937, 0, 0), -- 0
(@OGUID+10, 0, 0, 0.900698184967041015, 0.434445321559906005, 0, 0); -- Doors

 -- Dark Ranger
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=44632; -- Dark Ranger
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=44632; -- 44632 (Dark Ranger)

SET @PATH := @CGUID+7 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1352.725, 1059.25, 53.049904, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1360.8423, 1063.4806, 53.141506, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1369.0923, 1071.7306, 53.391506, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1371.5746, 1074.4009, 53.789463, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1373.5746, 1076.4009, 53.289463, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1375.8246, 1078.6509, 53.039463, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1382.3246, 1085.6509, 53.289463, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1383.8246, 1086.9009, 53.539463, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1384.5746, 1087.6509, 53.789463, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1386.8806, 1090.0674, 54.586235, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1388.1306, 1091.5674, 54.836235, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1388.8806, 1092.3174, 55.086235, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1388.8806, 1092.3174, 55.336235, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1390.8806, 1092.5674, 55.836235, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1393.6306, 1093.0674, 57.086235, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1394.6306, 1093.3174, 57.336235, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 1396.3806, 1093.8174, 58.336235, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 1399.3806, 1094.3174, 59.586235, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 1400.3806, 1094.5674, 59.836235, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 1402.1306, 1095.0674, 60.336235, NULL, 0, 0, 0, 0, 0),
(@PATH, 21, 1403.1306, 1095.3174, 60.586235, NULL, 0, 0, 0, 0, 0),
(@PATH, 22, 1406.7034, 1095.9951, 60.7336, NULL, 0, 0, 0, 0, 0),
(@PATH, 23, 1415.4838, 1085.996, 60.7336, NULL, 0, 0, 0, 0, 0),
(@PATH, 24, 1419.93, 1084.92, 60.4786, NULL, 0, 0, 0, 0, 0),
(@PATH, 25, 1415.3938, 1086.3098, 60.7336, NULL, 0, 0, 0, 0, 0),
(@PATH, 26, 1406.312, 1096.0481, 60.624386, NULL, 0, 0, 0, 0, 0),
(@PATH, 27, 1402.562, 1095.0481, 60.374386, NULL, 0, 0, 0, 0, 0),
(@PATH, 28, 1400.562, 1094.5481, 59.874386, NULL, 0, 0, 0, 0, 0),
(@PATH, 29, 1397.812, 1094.0481, 58.624386, NULL, 0, 0, 0, 0, 0),
(@PATH, 30, 1396.812, 1093.7981, 58.374386, NULL, 0, 0, 0, 0, 0),
(@PATH, 31, 1394.812, 1093.2981, 57.624386, NULL, 0, 0, 0, 0, 0),
(@PATH, 32, 1394.062, 1093.0481, 57.124386, NULL, 0, 0, 0, 0, 0),
(@PATH, 33, 1392.062, 1093.0481, 56.624386, NULL, 0, 0, 0, 0, 0),
(@PATH, 34, 1371.224, 1074.0079, 53.60165, NULL, 0, 0, 0, 0, 0),
(@PATH, 35, 1366.474, 1069.2579, 53.35165, NULL, 0, 0, 0, 0, 0),
(@PATH, 36, 1360.3677, 1063.3889, 53.05648, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+7, @PATH, 0, 0, 0, 258, 0, 0, 0, 0, 0, NULL);

SET @PATH := @CGUID+30 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1438.05, 1068.76, 60.7803, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1442.28, 1059.43, 60.7893, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1441.53, 1056.43, 60.5393, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1441.03, 1054.43, 60.2893, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1440.53, 1052.93, 59.7893, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1440.03, 1050.93, 59.2893, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1439.78, 1049.93, 59.0393, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1427.56, 1030.52, 52.9738, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1426.56, 1029.52, 52.9738, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1415.81, 1025.27, 53.2238, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1413.73, 1024.23, 53.1286, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1407.48, 1021.98, 53.3786, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1400.1, 1019.1, 53.3104, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1387.85, 1009.35, 53.0604, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1392.1951, 1012.625, 53.310387, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1400.496, 1019.28534, 53.38082, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 1413.4482, 1024.3733, 53.147682, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 1413.9482, 1024.6233, 53.147682, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 1420.1982, 1026.8733, 52.897682, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 1426.802, 1029.8049, 53.151054, NULL, 0, 0, 0, 0, 0),
(@PATH, 21, 1428.552, 1032.0549, 53.401054, NULL, 0, 0, 0, 0, 0),
(@PATH, 22, 1429.802, 1033.8049, 53.901054, NULL, 0, 0, 0, 0, 0),
(@PATH, 23, 1430.802, 1035.3049, 54.151054, NULL, 0, 0, 0, 0, 0),
(@PATH, 24, 1432.052, 1036.8049, 54.651054, NULL, 0, 0, 0, 0, 0),
(@PATH, 25, 1432.552, 1037.5549, 54.901054, NULL, 0, 0, 0, 0, 0),
(@PATH, 26, 1433.802, 1039.0549, 55.151054, NULL, 0, 0, 0, 0, 0),
(@PATH, 27, 1434.302, 1040.0549, 55.401054, NULL, 0, 0, 0, 0, 0),
(@PATH, 28, 1435.052, 1040.8049, 55.651054, NULL, 0, 0, 0, 0, 0),
(@PATH, 29, 1436.052, 1042.3049, 56.151054, NULL, 0, 0, 0, 0, 0),
(@PATH, 30, 1437.0781, 1043.4365, 56.76165, NULL, 0, 0, 0, 0, 0),
(@PATH, 31, 1437.5781, 1044.1865, 57.26165, NULL, 0, 0, 0, 0, 0),
(@PATH, 32, 1438.8281, 1045.9365, 57.76165, NULL, 0, 0, 0, 0, 0),
(@PATH, 33, 1438.8281, 1046.1865, 58.01165, NULL, 0, 0, 0, 0, 0),
(@PATH, 34, 1438.8281, 1046.1865, 58.26165, NULL, 0, 0, 0, 0, 0),
(@PATH, 35, 1439.3281, 1047.9365, 58.26165, NULL, 0, 0, 0, 0, 0),
(@PATH, 36, 1439.8281, 1049.9365, 59.01165, NULL, 0, 0, 0, 0, 0),
(@PATH, 37, 1440.3281, 1051.6865, 59.51165, NULL, 0, 0, 0, 0, 0),
(@PATH, 38, 1440.8281, 1053.6865, 60.01165, NULL, 0, 0, 0, 0, 0),
(@PATH, 39, 1441.3281, 1055.4365, 60.26165, NULL, 0, 0, 0, 0, 0),
(@PATH, 40, 1441.8103, 1057.7498, 60.610058, NULL, 0, 0, 0, 0, 0),
(@PATH, 41, 1442.3103, 1059.4998, 60.610058, NULL, 0, 0, 0, 0, 0),
(@PATH, 42, 1437.824, 1068.9791, 60.76616, NULL, 0, 0, 0, 0, 0),
(@PATH, 43, 1429.38, 1076.24, 60.4836, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+30, @PATH, 0, 0, 0, 258, 0, 0, 0, 0, 0, NULL);

 -- Bat Handler Maggotbreath
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=44825; -- Bat Handler Maggotbreath

DELETE FROM `creature_template_addon` WHERE `entry` = 44825;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44825, 0, 0, 0, 257, 0, 0, 0, 0, 0, '');
 
 -- Grand Executor Mortuus
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=44615; -- Grand Executor Mortuus

UPDATE `creature_template_addon` SET `visibilityDistanceType`=3, `bytes2`=257 WHERE `entry`=44615; -- 44615 (Grand Executor Mortuus)

 -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1, `unit_flags2`=2099200 WHERE `entry`=44365; -- Lady Sylvanas Windrunner

DELETE FROM `creature_template_addon` WHERE `entry` = 44365;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44365, 0, 29257, 0, 1, 0, 0, 0, 0, 3, '');

 -- Agatha
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=44608; -- Agatha

DELETE FROM `creature_template_addon` WHERE `entry` = 44608;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44608, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- 44608 (Agatha)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44608;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44608, NULL, NULL, 1, NULL, NULL, NULL, NULL);

 -- Arthura
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags2`=2099200, `HoverHeight`=2.799999952316284179 WHERE `entry`=44610; -- Arthura

DELETE FROM `creature_template_addon` WHERE `entry` = 44610;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44610, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- 44610 (Arthura)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44610;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44610, NULL, NULL, 1, NULL, NULL, NULL, NULL);

 -- Daschla
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags2`=2099200, `HoverHeight`=2.799999952316284179 WHERE `entry`=44609; -- Daschla

DELETE FROM `creature_template_addon` WHERE `entry` = 44609;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44609, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- 44609 (Daschla)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44609;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44609, NULL, NULL, 1, NULL, NULL, NULL, NULL);

 -- Fallen Human
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry` IN (44593, 44592); -- Fallen Human

DELETE FROM `creature_template_addon` WHERE `entry` IN (44593, 44592);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44593, 0, 0, 0, 1, 0, 0, 0, 0, 3, '80636'),
(44592, 0, 0, 0, 1, 0, 0, 0, 0, 3, '80636');

DELETE FROM `spell_script_names` WHERE `spell_id`=80636 AND `ScriptName`='spell_gen_feign_death_no_prevent_emotes';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(80636, 'spell_gen_feign_death_no_prevent_emotes');
