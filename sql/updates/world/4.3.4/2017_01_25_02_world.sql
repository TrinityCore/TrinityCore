--
-- Fix Teegan Holloway Location
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7184.158,`position_y`=-738.4661,`position_z`=72.3762 WHERE `guid`=315915;

-- Teegan Holloway SAI
SET @ENTRY := 34033;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,1,1,0,0,0,0,0,0,0,"Teegan Holloway - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,3,@ENTRY,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,4,@ENTRY,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,7,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,10,@ENTRY,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Waypoint 10 Reached - Pause Waypoint"),
(@ENTRY,0,5,6,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Aggro - Cast 'Shadow Charge' (No Repeat)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,7,0,0,0,100,0,2000,4500,12000,14000,11,38926,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teegan Holloway - In Combat - Cast 'Dark Strike'");

-- Teegan Holloway Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Script - Pause Waypoint"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8552113,"Teegan Holloway - On Script - Turn to"),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teegan Holloway - On Script - Say Line 1");

-- Teegan Holloway Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY,1,7184.158,-738.4661,72.3762, 'Teegan Holloway'),
(@ENTRY,2,7185.904,-733.903,72.29668, 'Teegan Holloway'),
(@ENTRY,3,7194.483,-739.7288,69.60533, 'Teegan Holloway'),
(@ENTRY,4,7184.901,-733.1005,72.29668, 'Teegan Holloway'),
(@ENTRY,5,7184.333,-741.9072,73.01316, 'Teegan Holloway'),
(@ENTRY,6,7185.539,-745.4558,74.32065, 'Teegan Holloway'),
(@ENTRY,7,7187.721,-747.9215,75.44964, 'Teegan Holloway'),
(@ENTRY,8,7195.899,-751.89,78.19501, 'Teegan Holloway'),
(@ENTRY,9,7201.903,-751.1608,78.89608, 'Teegan Holloway'),
(@ENTRY,10,7205.028,-747.9453,78.96334, 'Teegan Holloway'),
(@ENTRY,11,7196.893,-751.6824,78.40195, 'Teegan Holloway'),
(@ENTRY,12,7192.063,-751.0992,77.03501, 'Teegan Holloway'),
(@ENTRY,13,7186.836,-747.7456,75.217, 'Teegan Holloway'),
(@ENTRY,14,7184.707,-743.697,73.66603, 'Teegan Holloway');

-- Fix Teegan Holloway Text
UPDATE `creature_text` SET `emote`=15, `comment`= 'Teegan Holloway Aggro' WHERE `entry`=34033 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `emote`=5, `comment`= 'Teegan Holloway Script' WHERE `entry`=34033 AND `groupid`=1 AND `id`=0;
DELETE FROM `creature_text` WHERE `entry`=34033 AND `groupid`=1 AND `id`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34033, 1, 1, 'Leave no stone unturned. I mean that literally, you heaps of decay! Tear this place apart if you have to.', 12, 0, 100, 5, 0, 0, 34168, 'Teegan Holloway Script');
--
