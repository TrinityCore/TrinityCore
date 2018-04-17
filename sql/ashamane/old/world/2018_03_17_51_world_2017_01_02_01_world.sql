-- Rahein <Blade Vendor>
DELETE FROM `waypoints` WHERE `entry`=16678;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16678, 1, 9630.69, -7032.97, 15.2687),
(16678, 2, 9636.05, -7031.66, 15.2674),
(16678, 3, 9630.66, -7032.19, 15.2674),
(16678, 4, 9627.83, -7031.5, 15.2674),
(16678, 5, 9630.69, -7032.97, 15.2687),
(16678, 6, 9630.69, -7032.97, 15.2687);

-- Rahein SAI
SET @ENTRY := 16678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16678,1,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,4,16678,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1667800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,35000,35000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Feledis <Axe Vendor>
DELETE FROM `waypoints` WHERE `entry`=16666;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16666, 1, 9644.87, -7037.51, 15.2466),
(16666, 2, 9649.12, -7037.71, 15.247),
(16666, 3, 9649.12, -7037.71, 15.247),
(16666, 4, 9649.84, -7036.01, 15.2545),
(16666, 5, 9650.34, -7034.34, 15.2614),
(16666, 6, 9647.34, -7032.51, 15.2673),
(16666, 7, 9647.34, -7032.51, 15.2673),
(16666, 8, 9644.26, -7032.12, 15.2673),
(16666, 9, 9643.18, -7034.19, 15.2648),
(16666, 10, 9643.12, -7036.25, 15.254),
(16666, 11, 9644.87, -7037.51, 15.2466),
(16666, 12, 9644.87, -7037.51, 15.2466);

-- Feledis SAI
SET @ENTRY := 16666;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16666,1,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,4,16666,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1666600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,41000,41000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");
