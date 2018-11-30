-- Apprentice Trotter -- http://www.wowhead.com/npc=27301
-- Apprentice Trotter SAI
SET @ENTRY := 27301;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,27301,1,0,0,1,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,3,27301,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,61,0,100,0,3,27301,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.20907,"Apprentice Trotter - On Waypoint 3 Reached - Set Orientation 5,20907"),
(@ENTRY,0,4,5,40,0,100,0,5,27301,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,5,0,61,0,100,0,5,27301,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.1162,"Apprentice Trotter - On Waypoint 5 Reached - Set Orientation 6,1162"),
(@ENTRY,0,6,7,40,0,100,0,8,27301,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,7,0,61,0,100,0,8,27301,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.10835,"Apprentice Trotter - On Waypoint 8 Reached - Set Orientation 6,10835");

-- Actionlist SAI
SET @ENTRY := 2730100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Script - Set Emote State 133"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Trotter - On Script - Set Emote State 0");

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=111400;
DELETE FROM `waypoints` WHERE `entry`=27301;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27301, 1, 3655.39, 5880.89, 174.576, 'Apprentice Trotter'),
(27301, 2, 3648.21, 5875.72, 174.554, 'Apprentice Trotter'),
(27301, 3, 3649.17, 5874.43, 174.578, 'Apprentice Trotter'),
(27301, 4, 3656.08, 5881.3, 174.577, 'Apprentice Trotter'),
(27301, 5, 3659.29, 5880.93, 174.577, 'Apprentice Trotter'),
(27301, 6, 3658.57, 5882.95, 174.577, 'Apprentice Trotter'),
(27301, 7, 3659.6, 5887.87, 174.577, 'Apprentice Trotter'),
(27301, 8, 3661.47, 5888.53, 174.577, 'Apprentice Trotter'),
(27301, 9, 3659.61, 5887.48, 174.576, 'Apprentice Trotter');
