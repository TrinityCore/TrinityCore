-- Brother Daniels SAI -- http://www.wowhead.com/npc=19447/brother-daniels
SET @ENTRY := 19447;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,19447,1,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,19447,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,3,19447,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,5,19447,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Waypoint 5 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1944700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,155000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.47099,"Brother Daniels - On Script - Set Orientation 4.47099"),
(@ENTRY,9,2,0,0,0,100,0,15000,15000,0,0,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,15000,15000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,119000,119000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Remove Flag Standstate Stand Up");

-- Actionlist SAI
SET @ENTRY := 1944701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,155000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00368,"Brother Daniels - On Script - Set Orientation 4.00368"),
(@ENTRY,9,2,0,0,0,100,0,15000,15000,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,15000,15000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Say Line 3"),
(@ENTRY,9,5,0,0,0,100,0,119000,119000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Daniels - On Script - Remove Flag Standstate Stand Up");

DELETE FROM `creature_text` WHERE `CreatureID`=19447;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(19447, 0, 0, 'Light, lead the fallen from untruth to truth, from darkness to Light and from death to immortality.', 12, 0, 100, 0, 0, 0, 16769, 'Brother Daniels'),
(19447, 1, 0, 'Light be with you now and forever.', 12, 0, 100, 0, 0, 0, 16770, 'Brother Daniels'),
(19447, 2, 0, 'Light, give me strength.', 12, 0, 100, 0, 0, 0, 16767, 'Brother Daniels'),
(19447, 3, 0, 'The priest kneels in silent prayer.', 16, 0, 100, 0, 0, 0, 16772, 'Brother Daniels');

DELETE FROM `waypoints` WHERE `entry`=19447;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19447, 1, -365.8, 980.679, 54.1955,   'Brother Daniels'),
(19447, 2, -354.904, 978.248, 54.2496, 'Brother Daniels'),
(19447, 3, -354.904, 978.248, 54.2496, 'Brother Daniels'),
(19447, 4, -366.477, 980.557, 54.1895, 'Brother Daniels'),
(19447, 5, -369.43, 977.106, 54.1679,  'Brother Daniels');
