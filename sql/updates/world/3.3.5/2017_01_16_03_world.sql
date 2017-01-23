-- Librarian Hamilton -- http://www.wowhead.com/npc=27141/librarian-hamilton
-- Librarian Hamilton SAI
SET @ENTRY := 27141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,27141,1,0,0,1,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,27141,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,2,27141,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,3,27141,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,5,6,40,0,100,0,4,27141,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,6,0,61,0,100,0,4,27141,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.15815,"Librarian Hamilton - On Waypoint 4 Reached - Set Orientation 3,15815");

-- Actionlist SAI
SET @ENTRY := 2714100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Librarian Hamilton - On Script - Remove Flag Standstate Kneel");

DELETE FROM `waypoints` WHERE `entry`=27141;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27141, 1, 3595.1, 5959.01, 136.328, 'Librarian Hamilton'),
(27141, 2, 3590.25, 5953.57, 136.203, 'Librarian Hamilton'),
(27141, 3, 3595.1, 5959.01, 136.328, 'Librarian Hamilton'),
(27141, 4, 3593.01, 5963.17, 136.328, 'Librarian Hamilton');
