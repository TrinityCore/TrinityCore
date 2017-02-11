-- Exodar Worker SAI
SET @ENTRY := 18800;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,120000,120000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1880000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 233"),
(@ENTRY,9,1,0,0,0,100,0,59000,59000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,50000,50000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Flag Standstate Kneel");

-- Worker SAI
SET @GUID := -67155;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,67155,1,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,6,67155,0,0,80,6715500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Waypoint 6 Reached - Run Script"),
(@GUID,0,2,0,40,0,100,0,22,67155,0,0,80,6715501,2,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Waypoint 22 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 6715500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 6"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 1");

-- Actionlist SAI
SET @ENTRY := 6715501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Script - Play Emote 1"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,5,1,0,0,0,0,0,19,16731,50,0,0,0,0,0,"Worker - On Script - Play Emote 1"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,273,0,0,0,0,0,19,16731,50,0,0,0,0,0,"Worker - On Script - Play Emote 273"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worker - On Script - Play Emote 1");


DELETE FROM `waypoints` WHERE `entry`=67155;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(67155,1,-4039.73,-11519.2,-141.385,   'Worker'),
(67155,2,-4043.24,-11529.9,-138.291,   'Worker'),
(67155,3,-4030.91,-11548.1,-138.214,   'Worker'),
(67155,4,-4030.44,-11553.5,-138.23,   'Worker'),
(67155,5,-4037.56,-11565.6,-138.359,  'Worker'),
(67155,6,-4045.63,-11567,-138.459,    'Worker'),
(67155,7,-4037.56,-11565.6,-138.36,   'Worker'),
(67155,8,-4030.32,-11553.4,-138.229,  'Worker'),
(67155,9,-4030.84,-11547.6,-138.211,  'Worker'),
(67155,10,-4043.02,-11530,-138.288,   'Worker'),
(67155,11,-4039.7,-11519.4,-141.384,  'Worker'),
(67155,12,-4020.26,-11485.7,-141.031, 'Worker'),
(67155,13,-4013.84,-11480.3,-137.389, 'Worker'),
(67155,14,-3964.9,-11439.4,-136.703,  'Worker'),
(67155,15,-3944,-11437.5,-135.611,    'Worker'),
(67155,16,-3915.15,-11435.8,-132.892, 'Worker'),
(67155,17,-3876.07,-11444.9,-132.561, 'Worker'),
(67155,18,-3840.76,-11457.2,-132.186, 'Worker'),
(67155,19,-3829.7,-11460.8,-138.548,  'Worker'),
(67155,20,-3796,-11472,-138.189,      'Worker'),
(67155,21,-3788.55,-11474.4,-134.564, 'Worker'),
(67155,22,-3769.14,-11480.8,-134.369, 'Worker'),
(67155,23,-3788.23,-11474.6,-134.559, 'Worker'),
(67155,24,-3795.97,-11472,-138.19,    'Worker'),
(67155,25,-3829.94,-11460.8,-138.48,  'Worker'),
(67155,26,-3840.59,-11457.3,-132.185, 'Worker'),
(67155,27,-3875.72,-11445,-132.556,   'Worker'),
(67155,28,-3915.23,-11436,-132.892,   'Worker'),
(67155,29,-3943.23,-11437.5,-135.509, 'Worker'),
(67155,30,-3964.67,-11439.3,-136.699, 'Worker'),
(67155,31,-4013.47,-11480,-137.383,   'Worker'),
(67155,32,-4021.21,-11486.8,-141.045, 'Worker');

-- Actionlist SAI
SET @ENTRY := 1672700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Padaar - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Padaar - On Script - Set Emote State 233"),
(@ENTRY,9,2,0,0,0,100,0,85000,85000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Padaar - On Script - Set Emote State 0");
