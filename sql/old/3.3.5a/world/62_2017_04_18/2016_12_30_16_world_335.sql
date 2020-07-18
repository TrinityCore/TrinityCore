-- Silvermoon City Trainer - updates #2
-- Winthren <Shield Merchant>
UPDATE `creature` SET position_x = 9451.738, position_y = -7122.863, position_z = 16.14618, orientation = 6.128479, Spawndist = 0, MovementType = 2 WHERE guid = 57682;
DELETE FROM `waypoints` WHERE `entry`=16693;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16693, 1, 9451.74, -7122.86, 16.1462),
(16693, 2, 9452.37, -7125.35, 16.1465),
(16693, 3, 9451.99, -7128.64, 16.1465),
(16693, 4, 9451.74, -7122.86, 16.1462),
(16693, 5, 9451.74, -7122.86, 16.1462);

-- Winthren SAI
SET @ENTRY := 16693;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16693,1,0,0,0,1,0,0,0,0,0,0,0,"Winthren - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,16693,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winthren - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,3,16693,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winthren - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,1,16693,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winthren - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,5,16693,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winthren - On Waypoint 5 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1669300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,26000,26000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Tynna <Plate Armor Merchant>
UPDATE `creature` SET position_x = 9453.12, position_y = -7138.64, position_z = 16.1464, orientation = 0.186189, Spawndist = 0, MovementType = 0 WHERE guid = 57621;
DELETE FROM `waypoints` WHERE `entry`=16626;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16626, 1, 9453.12, -7138.64, 16.1464),
(16626, 2, 9455.66, -7135.42, 16.1352),
(16626, 3, 9453.97, -7134.69, 16.1431),
(16626, 4, 9451.15, -7138.66, 16.1464),
(16626, 5, 9453.12, -7138.64, 16.1464);

-- Tynna SAI
SET @ENTRY := 16626;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16626,1,0,0,0,1,0,0,0,0,0,0,0,"Tynna - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,16626,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tynna - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,3,16626,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tynna - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,4,16626,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tynna - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,5,16626,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tynna - On Waypoint 5 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1662600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,26000,26000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Zalle
DELETE FROM `waypoints` WHERE `entry`=16611;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16611, 1, 9572.41, -7060.69, 18.6436),
(16611, 2, 9581.56, -7062.5, 18.6436),
(16611, 3, 9590.1, -7060.46, 18.6436),
(16611, 4, 9587.3, -7060.51, 18.6436),
(16611, 5, 9586.82, -7062.25, 18.6436),
(16611, 6, 9581.68, -7062.86, 18.6436),
(16611, 7, 9571.29, -7061.17, 18.6436),
(16611, 8, 9572.41, -7060.69, 18.6436);

-- Zalle SAI
SET @ENTRY := 16611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16611,1,0,0,0,1,0,0,0,0,0,0,0,"Zalle - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,16611,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zalle - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,3,16611,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zalle - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,8,16611,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zalle - On Waypoint 8 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1661100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,26000,26000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");
