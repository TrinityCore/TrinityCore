-- Darnell SAI
SET @ENTRY := 49141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,@ENTRY*100+04) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Just Summoned - Run Script"),
(@ENTRY,0,1,0,40,0,100,512,4,0,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,512,8,0,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,512,9,0,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,512,10,0,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 10 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,13,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 13 Reached - Say Line 10"),
(@ENTRY,0,6,0,40,0,100,512,17,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 17 Reached - Despawn Instant"),
(@ENTRY,0,7,0,54,0,100,512,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Just Summoned - Set Reactstate Passive"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 0"),
(@ENTRY*100+00,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 1"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,53,1,49141,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Start Waypoint"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 2"),
(@ENTRY*100+02,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+02,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 3"),
(@ENTRY*100+03,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+03,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 4"),
(@ENTRY*100+03,9,2,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 5"),
(@ENTRY*100+03,9,3,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 6"),
(@ENTRY*100+03,9,4,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 7"),
(@ENTRY*100+04,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+04,9,1,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 8"),
(@ENTRY*100+04,9,2,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 9");
