-- Gurrag -- http://wotlk.openwow.com/npc=17520
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `Entry` = 17520;
-- Gurrag SAI
SET @ENTRY := 17520;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,17520,1,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,17520,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,5,17520,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,6,17520,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,7,17520,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,5,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1752000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.74215,"Gurrag - On Script - Set Orientation 1.74215"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,57000,57000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Remove Flag Standstate Kneel");

-- Actionlist SAI
SET @ENTRY := 1752001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.38812,"Gurrag - On Script - Set Orientation 0.38812"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,11,32991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Cast 'Nature Cast Visual'"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67170,18814,0,0,0,0,0,"Gurrag - On Script - Set Data 1 1 Exodar Invisible Stalker");

-- Actionlist SAI
SET @ENTRY := 1752002;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.21458,"Gurrag - On Script - Set Orientation 4.21458"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,90,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gurrag - On Script - Set Flag Standstate Sit Down"),
(@ENTRY,9,3,0,0,0,100,0,57000,57000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Remove Flag Standstate Sit Down");

-- Actionlist SAI
SET @ENTRY := 1752003;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.31923,"Gurrag - On Script - Set Orientation 3.31923"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,11,32991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurrag - On Script - Cast 'Nature Cast Visual'"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67169,18814,0,0,0,0,0,"Gurrag - On Script - Set Data 1 1 Exodar Invisible Stalker'");

-- Exodar Invisible Stalker SAI
SET @GUID := -67170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18814;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,11,32994,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Rejuvenation Impact Visual'");

-- Exodar Invisible Stalker SAI
SET @GUID := -67169;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18814;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,11,32994,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Rejuvenation Impact Visual'");

SET @PATH := 17520;
DELETE FROM `waypoints` WHERE `entry`=17520;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@PATH,1,-3889.26,-11323,-126.291, 'Gurrag'),
(@PATH,2,-3886.08,-11331,-126.283, 'Gurrag'),
(@PATH,3,-3883.83,-11333.7,-126.268, 'Gurrag'),
(@PATH,4,-3879.58,-11333,-126.214, 'Gurrag'),
(@PATH,5,-3878.4,-11331.9,-126.197, 'Gurrag'),
(@PATH,6,-3885.76,-11338.8,-126.31, 'Gurrag'),
(@PATH,7,-3892.54,-11336,-126.379, 'Gurrag'),
(@PATH,8,-3889.65,-11334.5,-126.339, 'Gurrag'),
(@PATH,9,-3887.65,-11331,-126.302, 'Gurrag'),
(@PATH,10,-3889.26,-11323,-126.291, 'Gurrag');
