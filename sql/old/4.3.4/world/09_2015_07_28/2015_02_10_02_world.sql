-- Kvaldir Mist Lord SAI
SET @GUID := -110298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25496;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,2549600,1,0,0,2,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,2,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 2 Reached - Run Script"),
(@GUID,0,2,0,40,0,100,0,4,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 4 Reached - Run Script"),
(@GUID,0,3,0,40,0,100,0,6,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 6 Reached - Run Script"),
(@GUID,0,4,0,40,0,100,0,8,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 8 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2549600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,10,110382,25242,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Set Orientation Closest Creature 'Warsong Battleguard'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Play Emote 53"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,11,45667,0,0,0,0,0,19,25244,50,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Cast 'Torch Corpse'");

DELETE FROM `waypoints` WHERE `entry`=2549600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2549600, 1, 2943.3, 6805.71, 6.86362, 'Kvaldir Mist Lord'),
(2549600, 2, 2946.38, 6808.99, 6.89997, 'Kvaldir Mist Lord'),
(2549600, 3, 2952.22, 6815.03, 5.49191, 'Kvaldir Mist Lord'),
(2549600, 4, 2956.26, 6811.33, 5.7004, 'Kvaldir Mist Lord'),
(2549600, 5, 2959.27, 6809.55, 5.73998, 'Kvaldir Mist Lord'),
(2549600, 6, 2958.56, 6804.6, 6.10027, 'Kvaldir Mist Lord'),
(2549600, 7, 2958.36, 6799.58, 6.55177, 'Kvaldir Mist Lord'),
(2549600, 8, 2953.32, 6798.66, 6.69609, 'Kvaldir Mist Lord');

DELETE FROM `creature_text` WHERE `entry`=25496;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25496, 0, 0, 'You are dismissed, $n.', 12, 0, 100, 113, 0, 0, 1242, 0, 'Marshal McBride');

DELETE FROM `creature_text` WHERE `entry`=25496;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(25496, 0, 0, 'Become ashes in the mist!', 12, 0, 50, 53, 0, 0, 24719, 'Kvaldir Mist Lord'),
(25496, 0, 1, 'The subjugation of these people has only just begun... so much time for fun and games.', 12, 0, 50, 53, 0, 0, 24718, 'Kvaldir Mist Lord'),
(25496, 0, 2, 'Burn, land dweller! BURN!', 12, 0, 50, 53, 0, 0, 24717, 'Kvaldir Mist Lord');
