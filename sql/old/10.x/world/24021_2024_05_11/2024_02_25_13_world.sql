-- Merchant Square Gilnean City Guard and Panicked Citizens at gate

-- Gilnean City Guard SAI
SET @NPC := 376310;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34864;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 10000, 50000, 50000, 50000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 50 - 50 seconds (10 - 50s initially) (OOC) - Self: Talk 0 to invoker');

-- Panicked Citizen SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=44086;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (44086) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(44086, 0, 0, 0, '', 1, 0, 100, 0, 1000, 6000, 6000, 9000, 10, 1, 5, 18, 20, 430, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 9 seconds (1 - 6s initially) (OOC) - Self: Play random emote: ONESHOT_TALK(DNR) (1), ONESHOT_EXCLAMATION(DNR) (5), ONESHOT_CRY (18), ONESHOT_BEG (20), ONESHOT_COWER(DNR) (430),');

-- Panicked Citizen SAI
SET @NPC := 376285;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 1000, 6000, 6000, 9000, 10, 1, 5, 18, 20, 430, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 9 seconds (1 - 6s initially) (OOC) - Self: Play random emote: ONESHOT_TALK(DNR) (1), ONESHOT_EXCLAMATION(DNR) (5), ONESHOT_CRY (18), ONESHOT_BEG (20), ONESHOT_COWER(DNR) (430),'),
(-@NPC, 0, 1, 0, '', 1, 0, 100, 0, 45000, 55000, 45000, 55000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 45 - 55 seconds (OOC) - Self: Talk 0 to invoker');

DELETE FROM `creature_text` WHERE `CreatureID` IN (34864,44086);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34864, 0, 0, 'No one\'s allowed to leave. Prince Liam\'s orders.', 12, 0, 100, 1, 0, 0, 44373, 0, 'Gilneas City Guard'),
(34864, 0, 1, 'It isn\'t safe to leave, there\'s something lurking out there in the woods.', 12, 0, 100, 1, 0, 0, 44374, 0, 'Gilneas City Guard'),
(34864, 0, 2, 'Stay calm. We have everything under control.', 12, 0, 100, 1, 0, 0, 44375, 0, 'Gilneas City Guard'),
(44086, 0, 0, 'You can\'t do this to us!', 12, 0, 100, 5, 0, 0, 44377, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 0, 1, 'My children are in Stormglen alone! I have to get to them!', 12, 0, 100, 1, 0, 0, 44378, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 0, 2, 'What\'s going on? I thought I saw something on the rooftops.', 12, 0, 100, 5, 0, 0, 44379, 0, 'Panicked Citizen to Gilneas City Guard');

-- Paniced Citizens Overspawns
DELETE FROM `creature` WHERE `guid` IN (376293,376343,376347,376372);
DELETE FROM `creature_addon` WHERE `guid` IN (376293,376343,376347,376372);

-- Static Paniced Citizens in Merchant Square missing emotestate
DELETE FROM `creature_addon` WHERE `guid` IN (376247,376249,376341,376354,376355,376313,376333,376252);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(376247, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376249, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376341, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376354, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376355, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376313, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376333, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385'),
(376252, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '52385');

-- Shadowy Figures Missing scripting
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34867;

SET @NPC := 376319;
UPDATE `creature` SET `Position_x`=-1420.2126,`Position_y`=1428.7153,`Position_z`=72.53332 WHERE `guid`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 9000, 9000, 18000, 18000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1420.96, 1408.97, 63.7833, 0, 'Every 18 seconds (9s initially) (OOC) - (0, 0, 0): Jump to pos (-1420.96, 1408.97, 63.7833, 0) with speed XY 16 and speed Z 19'),
(-@NPC, 0, 1, 0, '', 1, 0, 100, 0, 18000, 18000, 18000, 18000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1420.21, 1428.72, 72.5333, 0, 'Every 18 seconds (OOC) - (0, 0, 0): Jump to pos (-1420.21, 1428.72, 72.5333, 0) with speed XY 16 and speed Z 19');

SET @NPC := 376334;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 10000, 10000, 20000, 20000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1506.57, 1451.03, 71.1976, 0, 'Every 20 seconds (10s initially) (OOC) - (0, 0, 0): Jump to pos (-1506.57, 1451.03, 71.1976, 0) with speed XY 16 and speed Z 19'),
(-@NPC, 0, 1, 0, '', 1, 0, 100, 0, 20000, 20000, 20000, 20000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1464.9, 1450.8, 71.7703, 0, 'Every 20 seconds (OOC) - (0, 0, 0): Jump to pos (-1464.9, 1450.8, 71.7703, 0) with speed XY 16 and speed Z 19');

SET @NPC := 376306;
UPDATE `creature` SET `position_x`=-1513.757,`position_y`=1319.5868,`position_z`=72.689926 WHERE `guid`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 10000, 10000, 20000, 20000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1488.44, 1327.37, 71.0626, 0, 'Every 20 seconds (10s initially) (OOC) - (0, 0, 0): Jump to pos (-1488.44, 1327.37, 71.0626, 0) with speed XY 16 and speed Z 19'),
(-@NPC, 0, 1, 0, '', 1, 0, 100, 0, 20000, 20000, 20000, 20000, 97, 16, 19, 0, 0, 0, 0, 8, 0, 0, 0, -1513.76, 1319.59, 72.6899, 0, 'Every 20 seconds (OOC) - (0, 0, 0): Jump to pos (-1513.76, 1319.59, 72.6899, 0) with speed XY 16 and speed Z 19');

SET @NPC := 376323;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 10000, 11000, 10000, 11000, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 11 seconds (OOC) - Self: Play emote ONESHOT_ROAR(DNR) (15)');

SET @NPC := 376284;
SET @SCRIPT := 3486700;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SCRIPT) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@NPC, 0, 0, 0, '', 1, 0, 100, 0, 2000, 5000, 20000, 20000, 80, @SCRIPT, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 20 - 20 seconds (2 - 5s initially) (OOC) - Self: Start timed action list id #Waypoint (Only GM can see it) #0 (100) (update out of combat) // -inline'),
(@SCRIPT, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove stand state KNEEL'),
(@SCRIPT, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set walk'),
(@SCRIPT, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -1421.68, 1391.15, 71.27, 0, 'After 0 seconds - Self: Move to position (-1421.68, 1391.15, 71.27, 0)'),
(@SCRIPT, 9, 3, 0, '', 0, 0, 100, 0, 2500, 2500, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.5 seconds - Self: Set stand state to KNEEL'),
(@SCRIPT, 9, 4, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Self: Remove stand state KNEEL'),
(@SCRIPT, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -1421.56, 1386.36, 71.8755, 0, 'After 0 seconds - Self: Move to position (-1421.56, 1386.36, 71.8755, 0)'),
(@SCRIPT, 9, 6, 0, '', 0, 0, 100, 0, 2500, 2500, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.5 seconds - Self: Set stand state to KNEEL');

-- Pathing for Rat Entry: 4075
SET @CGUID := 376325;
SET @PATH := 4075 * 100 + 0;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-1585.2135,`position_y`=1365.3403,`position_z`=35.70951 WHERE `guid`=@CGUID;
DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES 
(@CGUID,@PATH,0,0,1,0,0, '');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Rat - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1566.3524,1366.9497,35.890343,NULL,0),
(@PATH,2,-1555.7535,1370.8646,35.769573,NULL,0),
(@PATH,3,-1542.4653,1384.8073,35.995403,NULL,0),
(@PATH,4,-1542.0885,1408.8611,35.555916,NULL,0),
(@PATH,5,-1533.2067,1420.9827,35.555916,NULL,0),
(@PATH,6,-1528.0087,1414.783,35.55326,NULL,0),
(@PATH,7,-1539.75,1416.8438,35.555916,NULL,0),
(@PATH,8,-1542.4653,1384.8073,35.995403,NULL,0),
(@PATH,9,-1555.7535,1370.8646,35.769573,NULL,0),
(@PATH,10,-1566.3524,1366.9497,35.890343,NULL,0),
(@PATH,11,-1585.2135,1365.3403,35.70951,NULL,0);

-- Pathing for Rat Entry: 4075
SET @CGUID := 376346;
SET @PATH := 4075 * 100 + 1;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-1573.1423,`position_y`=1401.1389,`position_z`=36.61908 WHERE `guid`=@CGUID;
DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES 
(@CGUID,@PATH,0,0,1,0,0, '');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Rat - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1569.6528,1401.1285,36.551193,NULL,0),
(@PATH,2,-1561.1267,1401.0504,36.159172,NULL,0),
(@PATH,3,-1559.4462,1404.783,36.093582,NULL,0),
(@PATH,4,-1559.8577,1411.4166,35.921894,NULL,0),
(@PATH,5,-1559.9688,1422.2848,35.718807,NULL,0),
(@PATH,6,-1555.533,1433.9219,35.80991,NULL,0),
(@PATH,7,-1547.9861,1438.7673,35.901875,NULL,0),
(@PATH,8,-1538.7466,1441.5243,35.983093,NULL,0),
(@PATH,9,-1529.4966,1441.5243,35.98047,NULL,0),
(@PATH,10,-1524.8594,1436.375,35.767334,NULL,0),
(@PATH,11,-1518.118,1436.0156,35.748398,NULL,0),
(@PATH,12,-1507.276,1435.7622,35.748604,NULL,0),
(@PATH,13,-1498.2188,1436.4271,35.785713,NULL,0),
(@PATH,14,-1492.8298,1437.6615,35.844475,NULL,0),
(@PATH,15,-1480.974,1437.4757,35.85198,NULL,0),
(@PATH,16,-1474.7587,1439.9584,35.9649,NULL,0),
(@PATH,17,-1468.632,1440.2535,35.967777,NULL,0),
(@PATH,18,-1454.4827,1437.776,35.877106,NULL,0),
(@PATH,19,-1449.7743,1439.8195,35.96333,NULL,0),
(@PATH,20,-1439.4323,1437.2396,35.862946,NULL,0),
(@PATH,21,-1449.7743,1439.8195,35.96333,NULL,0),
(@PATH,22,-1454.4827,1437.776,35.877106,NULL,0),
(@PATH,23,-1468.632,1440.2535,35.967777,NULL,0),
(@PATH,24,-1474.7587,1439.9584,35.9649,NULL,0),
(@PATH,25,-1480.974,1437.4757,35.85198,NULL,0),
(@PATH,26,-1492.8298,1437.6615,35.844475,NULL,0),
(@PATH,27,-1498.2188,1436.4271,35.785713,NULL,0),
(@PATH,28,-1507.276,1435.7622,35.748604,NULL,0),
(@PATH,29,-1518.118,1436.0156,35.748398,NULL,0),
(@PATH,30,-1524.8594,1436.375,35.767334,NULL,0),
(@PATH,31,-1529.4966,1441.5243,35.98047,NULL,0),
(@PATH,32,-1538.7466,1441.5243,35.983093,NULL,0),
(@PATH,33,-1547.9861,1438.7673,35.901875,NULL,0),
(@PATH,34,-1555.533,1433.9219,35.80991,NULL,0),
(@PATH,35,-1559.9688,1422.2848,35.718807,NULL,0),
(@PATH,36,-1559.8577,1411.4166,35.921894,NULL,0),
(@PATH,37,-1559.4462,1404.783,36.093582,NULL,0),
(@PATH,38,-1561.1267,1401.0504,36.159172,NULL,0),
(@PATH,39,-1569.6528,1401.1285,36.551193,NULL,0),
(@PATH,40,-1573.1423,1401.1389,36.61908,NULL,0);

-- Pathing for Rat Entry: 4075
SET @CGUID := 376254;
SET @PATH := 4075 * 100 + 2;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-1402.6649,`position_y`=1413.4149,`position_z`=35.555923 WHERE `guid`=@CGUID;
DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(@CGUID,@PATH,0,0,1,0,0, '');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Rat - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1408.7899,1421.2882,35.555923,NULL,0),
(@PATH,2,-1416.5017,1420.4392,35.555935,NULL,0),
(@PATH,3,-1435.3524,1423.6875,35.555935,NULL,0),
(@PATH,4,-1448.5435,1425.0348,35.55591,NULL,0),
(@PATH,5,-1465.6476,1425.0591,35.55591,NULL,0),
(@PATH,6,-1489.217,1426.3611,35.55591,NULL,0),
(@PATH,7,-1492.6337,1419.5573,35.55591,NULL,0),
(@PATH,8,-1495.2692,1408.132,35.555904,NULL,0),
(@PATH,9,-1496.3125,1402.4879,35.55591,NULL,0),
(@PATH,10,-1502.3004,1380.5538,35.555916,NULL,0),
(@PATH,11,-1500.2084,1350.625,35.555935,NULL,0),
(@PATH,12,-1490.9879,1347.6216,35.555935,NULL,0),
(@PATH,13,-1461.7327,1354.5173,35.555935,NULL,0),
(@PATH,14,-1433.2223,1362.0764,35.555935,NULL,0),
(@PATH,15,-1401.5416,1368.2882,35.555935,NULL,0),
(@PATH,16,-1402.9827,1385.6476,35.555923,NULL,0),
(@PATH,17,-1402.6649,1413.4149,35.555923,NULL,0);

-- Pathing for Rat Entry: 4075
SET @NPC := 376364;
SET @PATH := 4075 * 100 + 3;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-1527.6719,`position_y`=1362.6615,`position_z`=35.995403 WHERE `guid`=@CGUID;
DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES 
(@CGUID,@PATH,0,0,1,0,0, '');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Rat - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1534.3351,1354.1875,35.992195,NULL,0),
(@PATH,2,-1544.6024,1334.2274,35.555923,NULL,0),
(@PATH,3,-1561.4098,1319.868,35.555923,NULL,0),
(@PATH,4,-1598.5608,1310.0973,20.93024,NULL,0),
(@PATH,5,-1633.0781,1304.0295,19.662966,NULL,0),
(@PATH,6,-1666.2552,1304.8733,19.782318,NULL,0),
(@PATH,7,-1633.0781,1304.0295,19.662966,NULL,0),
(@PATH,8,-1598.5608,1310.0973,20.93024,NULL,0),
(@PATH,9,-1561.4098,1319.868,35.555923,NULL,0),
(@PATH,10,-1544.6024,1334.2274,35.555923,NULL,0),
(@PATH,11,-1534.3351,1354.1875,35.992195,NULL,0),
(@PATH,12,-1527.6719,1362.6615,35.995403,NULL,0);
