--
DELETE FROM `waypoints` WHERE `entry`=16856;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16856, 1,-807.327,2739.82,115.447, 'Caretaker Dilandrus'),
(16856, 2,-798.86,2719.21,111.628, 'Caretaker Dilandrus'),
(16856, 3,-785.502,2706.21,107.293, 'Caretaker Dilandrus'),
(16856, 4,-785.546,2702.16,106.208, 'Caretaker Dilandrus'),
(16856, 5,-787.652,2700.58,105.792, 'Caretaker Dilandrus'),
(16856, 6,-791.771,2694.26,104.589, 'Caretaker Dilandrus'),
(16856, 7,-793.482,2693.76,104.592, 'Caretaker Dilandrus'),
(16856, 8,-794.696,2691.44,104.35, 'Caretaker Dilandrus'),
(16856, 9,-797.951,2691.02,104.535, 'Caretaker Dilandrus'),
(16856, 10,-798.984,2693.63,104.891, 'Caretaker Dilandrus'),
(16856, 11,-797.778,2697.53,105.43, 'Caretaker Dilandrus'),
(16856, 12,-792.678,2705.64,106.948, 'Caretaker Dilandrus'),
(16856, 13,-792.409,2708.46,107.754, 'Caretaker Dilandrus'),
(16856, 14,-794.25,2710.38,108.384, 'Caretaker Dilandrus'),
(16856, 15,-799.924,2706.66,107.387, 'Caretaker Dilandrus'),
(16856, 16,-807.92,2692.9,104.856, 'Caretaker Dilandrus'),
(16856, 17,-811.612,2690.9,104.36, 'Caretaker Dilandrus'),
(16856, 18,-814.837,2692.26,104.736, 'Caretaker Dilandrus'),
(16856, 19,-814.33,2696.03,105.773, 'Caretaker Dilandrus'),
(16856, 20,-809.779,2704.45,107.63, 'Caretaker Dilandrus'),
(16856, 21,-801.425,2715.06,109.679, 'Caretaker Dilandrus'),
(16856, 22,-801.359,2718.11,110.676, 'Caretaker Dilandrus'),
(16856, 23,-804.433,2720.69,111.13, 'Caretaker Dilandrus'),
(16856, 24,-810.324,2717.67,110.329, 'Caretaker Dilandrus'),
(16856, 25,-814.433,2712.14,109.487, 'Caretaker Dilandrus'),
(16856, 26,-820.17,2701.35,107.506, 'Caretaker Dilandrus'),
(16856, 27,-823.067,2699.77,107.458, 'Caretaker Dilandrus'),
(16856, 28,-824.921,2701.38,107.939, 'Caretaker Dilandrus'),
(16856, 29,-824.739,2706.05,108.591, 'Caretaker Dilandrus'),
(16856, 30,-820.185,2714.8,110.056, 'Caretaker Dilandrus'),
(16856, 31,-814.476,2725.61,111.567, 'Caretaker Dilandrus'),
(16856, 32,-807.327,2739.82,115.447, 'Caretaker Dilandrus'),
(16856, 33,-807.327,2739.82,115.447, 'Caretaker Dilandrus');

UPDATE `creature` SET `position_x`=-807.327, `position_y`=2739.82, `position_z`=115.447, `orientation`=2.611, `MovementType`=2 WHERE  `guid`=58021;

-- Caretaker Dilandrus SAI
SET @ENTRY := 16856;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16856,1,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,5,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,7,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,11,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,15,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 15 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,20,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 20 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,24,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 24 Reached - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,30,16856,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 30 Reached - Run Script"),
(@ENTRY,0,8,0,40,0,100,0,33,16856,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Waypoint 33 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1685601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,2.75976,"Caretaker Dilandrus - On Script - Set Orientation Home Position"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Script - Play Emote 66"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,5,68,0,0,0,0,0,0,0,0,0,0,0,0,0,"Caretaker Dilandrus - On Script - Play Emote 68");
