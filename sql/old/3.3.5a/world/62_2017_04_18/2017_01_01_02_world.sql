-- Razia SAI -- http://www.wowhead.com/npc=16643/razia
SET @ENTRY := 16643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16643,1,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,16643,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,3,16643,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,6,16643,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,9,16643,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Waypoint 9 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,64,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1664300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Script - Play Emote 25");

-- Actionlist SAI
SET @ENTRY := 1664301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razia - On Script - Play Emote 1");

DELETE FROM `waypoints` WHERE `entry`=16643;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16643, 1, 10013.3, -7214.86, 32.0748, 'Razia'),
(16643, 2, 10013.5, -7217.56, 32.0748, 'Razia'),
(16643, 3, 10016.2, -7218.02, 32.0748, 'Razia'),
(16643, 4, 10014.7, -7217.3, 32.0764,  'Razia'),
(16643, 5, 10017.5, -7213.64, 32.0764, 'Razia'),
(16643, 6, 10017.7, -7210.42, 32.0756, 'Razia'),
(16643, 7, 10017.5, -7213.48, 32.0764, 'Razia'),
(16643, 8, 10013.3, -7214.86, 32.0748, 'Razia'),
(16643, 9, 10013.3, -7214.86, 32.0748, 'Razia');

UPDATE `creature` SET `Spawndist` = 0, `MovementType` = 0 WHERE `guid` IN (57682, 57621);
