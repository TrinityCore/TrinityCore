-- Market Square Crows

-- Allow Gilnean Crows to fly
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (50260);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(50260,1,0,1,0,0,0,0); -- Gilnean Crow

-- Add SAI to Gilnean Crows
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=50260;

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=93275 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 93275, 0, 0, 31, 0, 3, 50260, 0, 0, 0, 0, '', 'Spell Ping Gilnean Crow (effect 0) hits unit Gilnean Crow.');

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376332;
SET @PATH := 50260 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1404.2437,1418.7346,50.610405,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,1,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376302;
SET @PATH := 50260 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1411.3611,1447.3994,44.51103,NULL,0),
(@PATH,2,-1409.412,1440.6023,51.582096,NULL,0),
(@PATH,3,-1404.8746,1419.8765,54.30849,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,3,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376292;
SET @PATH := 50260 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1409.4534,1447.9543,42.710323,NULL,0),
(@PATH,2,-1404.4095,1419.5221,52.40137,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,2,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376314;
SET @PATH := 50260 * 100 + 3;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1401.4825,1451.0591,42.710323,NULL,0),
(@PATH,2,-1408.1272,1448.6406,49.78139,NULL,0),
(@PATH,3,-1404.1223,1419.9825,54.10521,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,3,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376322;
SET @PATH := 50260 * 100 + 4;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1404.2437,1418.7346,50.610405,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,1,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376294;
SET @PATH := 50260 * 100 + 5;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1409.4534,1447.9543,42.710323,NULL,0),
(@PATH,2,-1404.4095,1419.5221,52.40137,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,2,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376309;
SET @PATH := 50260 * 100 + 6;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1401.4825,1451.0591,42.710323,NULL,0),
(@PATH,2,-1408.1272,1448.6406,49.78139,NULL,0),
(@PATH,3,-1404.1223,1419.9825,54.10521,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,3,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));

-- Pathing for Gilnean Crow Entry: 50260
SET @NPC := 376298;
SET @PATH := 50260 * 100 + 7;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Gilnean Crow - Market Square');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1411.1156,1439.1777,42.710323,NULL,0),
(@PATH,2,-1405.3027,1419.025,51.658836,NULL,0);
-- Gilnean Crow SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@NPC,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On spell  Ping Gilnean Crow (93275) hit - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@NPC,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On spell  Ping Gilnean Crow (93275) hit - Self: Remove stand state SIT'),
(-@NPC,0,2,0,58,0,100,0,2,@PATH,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 1 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 30 seconds'));
