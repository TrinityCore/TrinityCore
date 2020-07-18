--
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 24396;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24396 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2439600 AND 2439612 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Mojo
-- Change % to 10 for tests
(24396,0,0,0,8,0,1,1,43732,0,0,0,0,80,2439612,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Spellhit 'Remove Amani Curse' - Run Script (No Repeat)"),
-- Vendor 24408
(24396,0,1,0,8,0,10,1,43732,0,0,0,0,80,2439610,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Spellhit 'Remove Amani Curse' - Run Script (No Repeat)"),
-- Vendor 24409
(24396,0,2,0,8,0,10,1,43732,0,0,0,0,80,2439611,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Spellhit 'Remove Amani Curse' - Run Script (No Repeat)"),
-- 24397,24403,24404,24405,24406,24407,24445,24448,24453,24455
(24396,0,3,0,8,0,100,1,43732,0,0,0,0,88,2439600,2439609,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Spellhit 'Remove Amani Curse' - Run Random Script (No Repeat)"),
-- Unable to make NPC move to second and third NPC or it'll be hardcoded
(24396,0,4,0,34,0,100,0,8,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Reached Point 1 - Despawn (0)"),
-- Mojo case
(24396,0,5,6,34,0,100,0,8,5,0,0,0,11,43923,2,0,0,0,0,12,1,0,0,0,0,0,0,0,"Forest Frog - On Reached Point 5 - Cast 'Push Mojo'"),
(24396,0,6,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Reached Point 5 - Despawn (0)"),
-- Vendors case
(24396,0,7,0,34,0,100,0,8,6,0,0,0,62,568,0,0,0,0,0,1,0,0,0,0,125.395790,1303.903564,-15.350780,3.925826,"Forest Frog - On Reached Point 6 - Teleport To Position"),
(24396,0,8,0,34,0,100,0,8,7,0,0,0,62,568,0,0,0,0,0,1,0,0,0,0,107.455498,1304.178955,-15.350780,5.512331,"Forest Frog - On Reached Point 7 - Teleport To Position"),

-- 24397,24403,24404,24445,24448,24453,24455 are similar
-- 24405 is unique, she's a rogue and casts Stealth, but basically similar to ^
-- 24406,24407 summons money bag
-- 24408,24409 are vendors
-- 24480 is Mojo, unuqie

-- 24397 Mannuth
(2439600,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439600,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439600,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439600,9,3,0,0,0,100,0,0,0,0,0,0,36,24397,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Mannuth'"),
(2439600,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439600,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439600,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439600,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439600,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439600,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439600,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439600,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24403 Deez
(2439601,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439601,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439601,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439601,9,3,0,0,0,100,0,0,0,0,0,0,36,24403,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Deez'"),
(2439601,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439601,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439601,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439601,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439601,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439601,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439601,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439601,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24404 Galathryn
(2439602,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439602,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439602,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439602,9,3,0,0,0,100,0,0,0,0,0,0,36,24404,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Galathryn'"),
(2439602,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439602,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439602,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439602,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439602,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439602,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439602,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439602,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24405 Adarrah
(2439603,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439603,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439603,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439603,9,3,0,0,0,100,0,0,0,0,0,0,36,24405,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Adarrah'"),
(2439603,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439603,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439603,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439603,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439603,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439603,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439603,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439603,9,11,0,0,0,100,0,2000,2000,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Stealth'"),
(2439603,9,12,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24406 Fudgerick
-- Summons Money Bag
(2439604,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439604,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439604,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439604,9,3,0,0,0,100,0,0,0,0,0,0,36,24406,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Fudgerick'"),
(2439604,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439604,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43774,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Money Bag'"),
(2439604,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439604,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439604,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439604,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439604,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439604,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24407 Darwen
-- Summons Money Bag
(2439605,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439605,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439605,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439605,9,3,0,0,0,100,0,0,0,0,0,0,36,24407,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Darwen'"),
(2439605,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439605,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43774,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Money Bag'"),
(2439605,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439605,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439605,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439605,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439605,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439605,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- Kids
-- 24445 Mitzi
(2439606,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439606,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439606,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439606,9,3,0,0,0,100,0,0,0,0,0,0,36,24445,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Mitzi'"),
(2439606,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439606,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439606,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439606,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439606,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439606,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439606,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439606,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24448 Christian
(2439607,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439607,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439607,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439607,9,3,0,0,0,100,0,0,0,0,0,0,36,24448,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Christian'"),
(2439607,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439607,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439607,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439607,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439607,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439607,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439607,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439607,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24453 Brennan
(2439608,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439608,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439608,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439608,9,3,0,0,0,100,0,0,0,0,0,0,36,24453,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Brennan'"),
(2439608,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439608,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439608,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439608,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439608,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439608,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439608,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439608,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24455 Hollee
(2439609,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439609,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439609,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439609,9,3,0,0,0,100,0,0,0,0,0,0,36,24455,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Hollee'"),
(2439609,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439609,9,5,0,0,0,100,0,5000,5000,0,0,0,11,43825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Cast 'Summon Amani Charm Chest'"),
(2439609,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439609,9,7,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Flag Standstate Kneel"),
(2439609,9,8,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Remove Flag Standstate Kneel"),
(2439609,9,9,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439609,9,10,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439609,9,11,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- Vendors
-- 24408 Gunter
(2439610,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439610,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439610,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439610,9,3,0,0,0,100,0,0,0,0,0,0,34,9,3,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Instance Data 9 to 3"),
(2439610,9,4,0,0,0,100,0,0,0,0,0,0,36,24408,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Gunter'"),
(2439610,9,5,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439610,9,6,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439610,9,7,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439610,9,8,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439610,9,9,0,0,0,100,0,2000,2000,0,0,0,69,6,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- 24409 Kyren
(2439611,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Stop Random Movement"),
(2439611,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Run Off"),
(2439611,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Orientation Invoker"),
(2439611,9,3,0,0,0,100,0,0,0,0,0,0,34,10,3,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Set Instance Data 10 to 3"),
(2439611,9,4,0,0,0,100,0,0,0,0,0,0,36,24409,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Kyren'"),
(2439611,9,5,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 0"),
(2439611,9,6,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439611,9,7,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 2"),
(2439611,9,8,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 3"),
(2439611,9,9,0,0,0,100,0,2000,2000,0,0,0,69,7,0,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Closest Creature 'Zul'Aman Exterior InvisMan'"),
-- Mojo 24480
(2439612,9,0,0,0,0,100,0,0,0,0,0,0,36,24480,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Update Template To 'Mojo'"),
(2439612,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Say Line 1"),
(2439612,9,2,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Store Targetlist"),
(2439612,9,3,0,0,0,100,0,1000,1000,0,0,0,69,5,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forest Frog - On Script - Move To Invoker");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 24396 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,24396,0,0,13,0,9,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if Random Vendor 1 is not done"),
(22,3,24396,0,0,13,0,10,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if Random Vendor 2 is not done");

-- Keep order
UPDATE `smart_scripts` SET `action_param1` = 4, `comment` = "Adarrah - On Script - Say Line 4" WHERE `entryorguid` = 2440500 AND `source_type` = 9 AND `id` = 1;

DELETE FROM `creature_text` WHERE `CreatureID` IN (24397,24403,24404,24405,24406,24407,24408,24409,24445,24448,24453,24455,24480);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- Source: wmo8mLyTbI4 58 & Wowhead(NPC 52920) It appears we can use quotes from new NPCs for old NPCs
(24397,0,0,"Greetings, kind stranger, and thank you for your selfless act.",12,0,100,0,0,0,23346,0,"Mannuth"),
(24397,1,0,"These heathens have robbed me of my belongings, but I can offer you this charm I took from my captors.",12,0,100,0,0,0,23347,0,"Mannuth"),
(24397,2,0,"May it serve you well, $n.",12,0,100,0,0,0,23369,0,"Mannuth"),
(24397,3,0,"Farewell.",12,0,100,0,0,0,23348,0,"Mannuth"),
-- Source: wmo8mLyTbI4 42 & Wowhead(NPC 52918) It appears we can use quotes from new NPCs for old NPCs
(24403,0,0,"Hmm, thank you stranger.",12,0,100,0,0,0,23373,0,"Deez"),
(24403,1,0,"I fear I have nothing but this old chest I discovered here. You're welcome to it.",12,0,100,0,0,0,23374,0,"Deez"),
(24403,2,0,"I hope you find its contents... useful.",12,0,100,0,0,0,23375,0,"Deez"),
(24403,3,0,"Until we next meet....",12,0,100,0,0,0,23376,0,"Deez"),
-- Source: wmo8mLyTbI4 19 & Wowhead(NPC 52916) It appears we can use quotes from new NPCs for old NPCs
(24404,0,0,"Oooh! It's about time someone rescued me....",12,0,100,0,0,0,23379,0,"Galathryn"),
(24404,1,0,"I suppose I should be grateful. Please, take this. I want nothing to remind me of this place.",12,0,100,0,0,0,23380,0,"Galathryn"),
(24404,2,0,"I took it from one of these trolls as I was captured. Maybe you can find a way to use it against them.",12,0,100,0,0,0,23381,0,"Galathryn"),
(24404,3,0,"I've had quite enough of this place. Goodbye.",12,0,100,0,0,0,23382,0,"Galathryn"),
-- Source: VuAPaoSavu0 58 wmo8mLyTbI4 39 & Wowhead(NPC 52947) It appears we can use quotes from new NPCs for old NPCs
(24405,0,0,"Ahhh, finally!",12,0,100,0,0,0,23383,0,"Adarrah"),
(24405,1,0,"Say, I found this charm just before they caught me. Maybe it'll do you some good here....",12,0,100,0,0,0,23384,0,"Adarrah"),
(24405,2,0,"I hope it helps. These vile beasts simply must be stopped!",12,0,100,0,0,0,23385,0,"Adarrah"),
(24405,3,0,"Good luck to you!",12,0,100,0,0,0,23386,0,"Adarrah"),
(24405,4,0,"Thank you!",12,0,100,17,0,0,37237,0,"Adarrah"),
-- Source: wmo8mLyTbI4 42 HUtjrgMA0mQ & Wowhead(NPC 52917) It appears we can use quotes from new NPCs for old NPCs
(24406,0,0,"Woohoo! I'm saved! I thank you, $n.",12,0,100,0,0,0,23391,0,"Fudgerick"),
(24406,1,0,"Oh, my. What IS that smell - oh wait, heh, whoops! Guess my senses will take a little time to get readjusted.",12,0,100,0,0,0,23392,0,"Fudgerick"),
(24406,2,0,"My apologies, friends. Here, now. This should help to cover the expenses involved in my rescue.",12,0,100,0,0,0,23393,0,"Fudgerick"),
(24406,3,0,"See ya later!",12,0,100,0,0,0,23394,0,"Fudgerick"),
-- Source: VuAPaoSavu0 146 wmo8mLyTbI4 24 & Wowhead(NPC 52919) It appears we can use quotes from new NPCs for old NPCs
(24407,0,0,"Well, now. What a pleasant turn of events.",12,0,100,0,0,0,23387,0,"Darwen"),
(24407,1,0,"It's most fortunate for you that you rescued me, and not one of these other poor sots.",12,0,100,0,0,0,23388,0,"Darwen"),
(24407,2,0,"Please accept this payment, as well as my gratitude, for your trouble.",12,0,100,0,0,0,23389,0,"Darwen"),
(24407,3,0,"Be well, $n.",12,0,100,0,0,0,23390,0,"Darwen"),
-- Source: VuAPaoSavu0 20 wmo8mLyTbI4 45 & Wowhead(NPC 52915) It appears we can use quotes from new NPCs for old NPCs
(24408,0,0,"Oh, can it be? I... I'm free of that hideous curse? ",12,0,100,0,0,0,23401,0,"Gunter"),
(24408,1,0,"Words cannot express my gratitude, $n. Thank you for your kindness.",12,0,100,0,0,0,23402,0,"Gunter"),
(24408,2,0,"As you can see, I have but little after these savages got hold of me, but you're welcome to what I have. Come, have a look.",12,0,100,0,0,0,23403,0,"Gunter"),
(24408,3,0,"I must go now, before I get myself caught again. If you need anything, I won't be far.",12,0,100,0,0,0,23404,0,"Gunter"),
-- Source: VuAPaoSavu0 95 wmo8mLyTbI4 50 & Wowhead(NPC 52914) It appears we can use quotes from new NPCs for old NPCs
(24409,0,0,"Mmmm, flies! Even better now that I can taste them.",12,0,100,0,0,0,23405,0,"Kyren"),
(24409,1,0,"Nice to be back among the unliving, thanks to you.",12,0,100,0,0,0,23406,0,"Kyren"),
(24409,2,0,"Perhaps I am able to offer something of interest to you? Come, see if there's anything you like.",12,0,100,0,0,0,23407,0,"Kyren"),
(24409,3,0,"I must be off now, $n. See you around.",12,0,100,0,0,0,23408,0,"Kyren"),
-- Source: VuAPaoSavu0 30 & Wowhead(NPC 52905) It appears we can use quotes from new NPCs for old NPCs
(24445,0,0,"Weee! I'm a girl again!",12,0,100,0,0,0,23411,0,"Mitzi"),
(24445,1,0,"Thank you for rescuing me. I simply hate being a yucky frog!",12,0,100,0,0,0,23412,0,"Mitzi"),
(24445,2,0,"I'm really not supposed to talk to strangers, but you've been so nice to me. Here's a special something I found just before I was kidnapped.",12,0,100,0,0,0,23413,0,"Mitzi"),
(24445,3,0,"I should go now. Be careful!",12,0,100,0,0,0,23414,0,"Mitzi"),
-- Source: VuAPaoSavu0 119 wmo8mLyTbI4 28 & Wowhead(NPC 52910) It appears we can use quotes from new NPCs for old NPCs
(24448,0,0,"Aww, nuts! You've ruined everything!",12,0,100,0,0,0,23417,0,"Christian"),
(24448,1,0,"Do you have any idea how neat it is to hop that far?",12,0,100,0,0,0,23418,0,"Christian"),
(24448,2,0,"Oh well, I was starting to miss my pals anyway - they're not gunna believe this! Oh, here - you can have this, I found it playin' hide and seek.",12,0,100,0,0,0,23419,0,"Christian"),
(24448,3,0,"Let's see if I can still make that sound....",12,0,100,0,0,0,23420,0,"Christian"),
-- Source: Wowhead(NPC 52909) It appears we can use quotes from new NPCs for old NPCs
(24453,0,0,"Hrmmph. Thanks all the same, but I didn't need any help.",12,0,100,0,0,0,23421,0,"Brennan"),
(24453,1,0,"I was working on a cantrip that would counteract my predicament and I was very close to finding a <CROOAAK>... Oh my!",12,0,100,0,0,0,23422,0,"Brennan"),
(24453,2,0,"Well, I suppose I do owe you a little something - here, take one of these. I've got lots.",12,0,100,0,0,0,23423,0,"Brennan"),
(24453,3,0,"You may want to consider leaving this place. I think being transformed into a frog is one of the better things that can happen to one here.",12,0,100,0,0,0,23424,0,"Brennan"),
-- Source: VuAPaoSavu0 TbFKKJZXHo0 & Wowhead(NPC 52912) It appears we can use quotes from new NPCs for old NPCs
(24455,0,0,"Oh! Back to my beautiful self? How lovely! I thought I would be a frog forever.",12,0,100,0,0,0,23425,0,"Hollee"),
(24455,1,0,"It was just terrible. I was all slimy, and I kept licking my eyes!",12,0,100,0,0,0,23426,0,"Hollee"),
(24455,2,0,"Thank goodness you came along when you did. Please, take one of these troll boxes to remember me by.",12,0,100,0,0,0,23427,0,"Hollee"),
(24455,3,0,"I never want to see this nasty pond again. Thank you, $n. I'll never forget you!",12,0,100,0,0,0,23428,0,"Hollee"),
-- Source: VuAPaoSavu0
(24480,0,0,"I thought you'd never ask!",15,0,100,0,0,0,23477,0,"Mojo"),
(24480,0,1,"Now that's what I call froggy-style!",15,0,100,0,0,0,23478,0,"Mojo"),
(24480,0,2,"This won't take long, did it?",15,0,100,0,0,0,23479,0,"Mojo"),
(24480,0,3,"I promise not to give you warts...",15,0,100,0,0,0,23480,0,"Mojo"),
(24480,0,4,"There's just never enough Mojo to go around...",15,0,100,0,0,0,23481,0,"Mojo"),
(24480,0,5,"Listen, $n, I know of a little swamp not too far from here....",15,0,100,0,0,0,23482,0,"Mojo"),
(24480,0,6,"Your lily pad or mine?",15,0,100,0,0,0,23483,0,"Mojo"),
(24480,0,7,"Feelin' a little froggy, are ya?",15,0,100,0,0,0,23484,0,"Mojo"),
(24480,1,0,"Mojo leaps into $n's pocket!",16,0,100,0,0,0,23485,0,"Mojo");

UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 24396;
DELETE FROM `npc_vendor` WHERE `entry` = 24396;
DELETE FROM `npc_vendor` WHERE `entry` IN (24408,24409) AND `item` IN (27657,27666,27667,33926,22829,22832,33928);
INSERT INTO `npc_vendor` (`entry`,`item`,`maxcount`,`incrtime`) VALUES
(24408,27657,12,7200),
(24408,27666,12,7200),
(24408,27667,12,7200),
(24408,33926,1,604800),
(24409,22829,5,7200),
(24409,22832,5,7200),
(24409,33928,1,604800);

UPDATE `gameobject_template_addon` SET `mingold` = 11 * 100 * 100, `maxgold` = 19 * 100 * 100 WHERE `entry` = 186736;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 43732;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,43732,0,0,31,1,3,24396,0,0,0,0,"","Spell 'Remove Amani Curse' targets 'Forest Frog'");

DELETE FROM `creature` WHERE `guid`=89279 AND `id`=24396;
