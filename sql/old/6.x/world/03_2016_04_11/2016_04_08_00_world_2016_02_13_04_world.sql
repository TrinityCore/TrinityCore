-- 
-- Arred
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 63008;
UPDATE `creature_template` SET `MovementType` = 0 WHERE `Entry` = 17512;
-- Arred SAI
SET @ENTRY := 17512;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,17512,1,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,17512,0,0,54,90000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,3,17512,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,7,17512,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,8,17512,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,9,17512,0,0,54,210000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arred - On Waypoint 9 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1751200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,90000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,88000,88000,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 3");

-- Actionlist SAI
SET @ENTRY := 1751201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,2,0,0,0,100,0,115000,115000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Flag Standstate Kneel");

-- Actionlist SAI
SET @ENTRY := 1751202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 25"),
(@ENTRY,9,2,0,0,0,100,0,12000,12000,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 273");

DELETE FROM `waypoints` WHERE `entry`=17512;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17512,1,-3788.04,-11547.3,-134.842, 'Arred'),
(17512,2,-3789.79,-11543.9,-134.849, 'Arred'),
(17512,3,-3793.72,-11542.8,-134.892, 'Arred'),
(17512,4,-3789.94,-11543.8,-134.851, 'Arred'),
(17512,5,-3787.24,-11546.9,-134.831, 'Arred'),
(17512,6,-3786.81,-11549.6,-134.836, 'Arred'),
(17512,7,-3787.67,-11551.3,-134.853, 'Arred'),
(17512,8,-3784.96,-11550.9,-134.819, 'Arred'),
(17512,9,-3788.04,-11547.3,-134.842, 'Arred');
