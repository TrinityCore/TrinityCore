-- [Q] Suspicious Hoofprints -- http://wotlk.openwow.com/quest=1268
-- Krog SAI
SET @ENTRY := 4926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,1268,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Krog - On Quest 'Suspicious Hoofprints' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 492600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,4972,5,0,0,0,0,8,0,0,0,-3136.897,-2894.5666,34.5287,2.5493,"Krog - On Script - Summon Creature 'Kagoro'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krog - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krog - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,4972,20,0,0,0,0,0,"Krog - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,85,6245,2,0,0,0,0,19,4972,20,0,0,0,0,0,"Krog - On Script - Invoker Cast 'Force Target - Salute'");

-- Kagoro SAI
SET @ENTRY := 4972;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,53,1,4972,0,0,0,0,1,0,0,0,0,0,0,0,"Kagoro - On Just Created - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,4972,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kagoro - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,8,4972,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kagoro - On Waypoint 8 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=4972;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4972, 1, -3141.51, -2889.5, 34.1959,  'Kagoro'),
(4972, 2, -3146.74, -2887.85, 34.1221, 'Kagoro'),
(4972, 3, -3144.92, -2882.28, 34.0017, 'Kagoro'),
(4972, 4, -3141.55, -2871.59, 34.6909, 'Kagoro'),
(4972, 5, -3142.67, -2863.14, 34.5384, 'Kagoro'),
(4972, 6, -3154.45, -2860.24, 34.3526, 'Kagoro'),
(4972, 7, -3168.05, -2856.89, 34.0434, 'Kagoro'),
(4972, 8, -3175.28, -2848.33, 34.4749, 'Kagoro');

DELETE FROM `creature_text` WHERE `CreatureID` IN (4926, 4972);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(4926, 0, 0, 'Kagoro, I require your presence!', 12, 0, 100, 0, 0, 0, 1755, 'Krog'),
(4926, 1, 0, 'Go to the Shady Rest Inn and follow the tracks. See where they lead and report back to me.', 12, 0, 100, 1, 0, 0, 1648, 'Krog'),
(4972, 0, 0, 'Understood. I will return shortly.', 12, 0, 100, 1, 0, 0, 1649, 'Kagoro');
