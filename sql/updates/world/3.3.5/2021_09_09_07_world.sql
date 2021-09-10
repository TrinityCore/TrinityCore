-- Script & waypoints should be updated from sniffs
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27923 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2792300,2792301) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27923,0,0,0,11,0,100,512,0,0,0,0,0,80,2792300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Spawn - Run Script"),
(27923,0,1,0,40,0,100,512,13,27923,0,0,0,80,2792301,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Waypoint 13 Reached - Run Script"),

(2792300,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Script - Say Line 0"),
(2792300,9,1,0,0,0,100,0,2000,2000,0,0,0,53,1,27923,0,0,0,3,1,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Script - Start Waypoint"),

(2792301,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Script - Say Line 1"),
(2792301,9,1,0,0,0,100,0,2000,2000,0,0,0,28,46598,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Script - Remove Aura 'Ride Vehicle Hardcoded'");

-- Grezzix Spindlesnap's crew
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 24767;
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 24897;
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 24896;

UPDATE `creature` SET `position_x` = 590.604736328125, `position_y` = -2793.393798828125, `position_z` = 0.170127332210540771, `orientation` = 3.630284786224365234 WHERE `id` = 24643;
UPDATE `creature` SET `position_x` = 592.10223388671875, `position_y` = -2792.1259765625, `position_z` = 3.50811171531677246, `orientation` = 3.630284786224365234 WHERE `id` = 24897;
UPDATE `creature` SET `position_x` = 594.01678466796875, `position_y` = -2794.661865234375, `position_z` = 0.185591340065002441, `orientation` = 3.787364482879638671 WHERE `id` = 24896;

DELETE FROM `creature_template_addon` WHERE `entry` IN (24896,24897);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(24896,0,0,1,1,0,0,''),
(24897,0,0,1,1,0,0,'');
