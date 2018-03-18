-- Silvermoon City - Trainer Scripts
DELETE FROM `waypoints` WHERE `entry`=16671;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16671, 1, 9859.67, -7361.79, 18.5932),
(16671, 2, 9858.73, -7363.12, 18.5903),
(16671, 3, 9859.67, -7361.79, 18.5932),
(16671, 4, 9859.67, -7361.79, 18.5932);

-- Mirvedon SAI
SET @ENTRY := 16671;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16671,1,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,16671,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,2,16671,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,2,16671,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,4,16671,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,64,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1667100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Script - Set Emote State 173"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirvedon - On Script - Set Emote State 0");

DELETE FROM `waypoints` WHERE `entry`=16667;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16667, 1, 9822.16, -7333.16, 26.3),
(16667, 2, 9822.35, -7331.03, 26.2814),
(16667, 3, 9820.39, -7329.52, 26.2814),
(16667, 4, 9819.43, -7330.37, 26.2814),
(16667, 5, 9820.59, -7329.88, 26.2814),
(16667, 6, 9821.49, -7331.48, 26.2814),
(16667, 7, 9821.25, -7331.97, 26.2814),
(16667, 8, 9822.16, -7333.16, 26.3),
(16667, 9, 9822.16, -7333.16, 26.3);

-- Danwe SAI
SET @ENTRY := 16667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16667,1,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Reset - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,4,16667,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,4,16667,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,4,40,0,100,0,7,16667,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Waypoint 7 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,7,16667,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,5,0,64,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1666700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,1,0,0,0,100,0,26000,26000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Danwe - On Script - Remove Aura 'Kneel'");

-- Actionlist SAI
SET @ENTRY := 1666701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,26000,26000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

SET @NPC := 57637;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 10013.3, -7214.86, 32.0748),
(@PATH, 2, 10013.5, -7217.56, 32.0748),
(@PATH, 3, 10016.2, -7218.02, 32.0748),
(@PATH, 4, 10014.7, -7217.3, 32.0764),
(@PATH, 5, 10017.5, -7213.64, 32.0764),
(@PATH, 6, 10017.7, -7210.42, 32.0756),
(@PATH, 7, 10017.5, -7213.48, 32.0764),
(@PATH, 8, 10013.3, -7214.86, 32.0748),
(@PATH, 9, 10013.3, -7214.86, 32.0748);
