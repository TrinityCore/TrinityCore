-- Fruits of Our Labor - http://wotlk.openwow.com/quest=11904
-- Cart Release SAI
SET @ENTRY := 188104;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,25986,20,0,0,0,0,0,"Cart Release - On Gameobject State Changed - Set Data 1 1");

DELETE FROM `creature_text` WHERE `CreatureID`=25986;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(25986, 0, 0, 'The Ore Cart squeaks against the rails as it is released.', 16, 0, 100, 0, 0, 0, 25416, 'Ore Cart');

UPDATE `creature` SET `spawntimesecs`=1 WHERE  `guid`=132773;

-- Ore Cart SAI
SET @ENTRY := 25986;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,1,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ore Cart - On Data Set 1 1 - Set Active On (No Repeat)"),
(@ENTRY,0,1,3,61,0,100,0,1,1,0,0,53,0,25986,0,0,0,0,1,0,0,0,0,0,0,0,"Ore Cart - On Data Set 1 1 - Start Waypoint (No Repeat)"),
(@ENTRY,0,2,4,40,0,100,0,15,25986,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ore Cart - On Waypoint 15 Reached - Despawn In 100 ms"),
(@ENTRY,0,3,0,61,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ore Cart - On Data Set 1 1 - Say Line 0 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,0,15,25986,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ore Cart - On Waypoint 15 Reached - Set Active Off");

DELETE FROM `waypoints` WHERE `entry`=25986;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25986,1,2797.49,5277.37,22.0435, 'Ore Cart'),
(25986,2,2794.32,5281.92,22.4205, 'Ore Cart'),
(25986,3,2790.66,5285.51,21.9443, 'Ore Cart'),
(25986,4,2783.22,5291.11,22.7502, 'Ore Cart'),
(25986,5,2776.37,5297,24.6788, 'Ore Cart'),
(25986,6,2772.41,5299.31,25.5129, 'Ore Cart'),
(25986,7,2767.82,5300.13,26.1103, 'Ore Cart'),
(25986,8,2764.16,5299.4,26.2145, 'Ore Cart'),
(25986,9,2760.57,5297.91,26.187, 'Ore Cart'),
(25986,10,2757.37,5295.31,25.8549, 'Ore Cart'),
(25986,11,2755.49,5291.84,25.142, 'Ore Cart'),
(25986,12,2752.95,5288.89,24.7977, 'Ore Cart'),
(25986,13,2748.91,5286.94,24.7359, 'Ore Cart'),
(25986,14,2746.13,5285.9,24.8515, 'Ore Cart'),
(25986,15,2733.06,5284.92,27.2962, 'Ore Cart');
