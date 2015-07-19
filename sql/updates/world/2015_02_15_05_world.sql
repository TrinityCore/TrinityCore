-- Volcor SAI
SET @ENTRY := 3692;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,994,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest 'Escape Through Force' Taken - Run Script"),
(@ENTRY,0,1,0,19,0,100,0,995,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest 'Escape Through Stealth' Taken - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,15,3692,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Waypoint 15 Reached - Despawn Instant"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Aggro - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 369200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,53,0,3692,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,110000,110000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,15,994,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit 'Escape Through Force'");

-- Actionlist SAI
SET @ENTRY := 369201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,3,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,53,0,3692,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,110000,110000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 3"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,15,995,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit 'Escape Through Stealth'");
