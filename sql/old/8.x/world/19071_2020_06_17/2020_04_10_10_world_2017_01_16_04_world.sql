-- Initiate Vernon SAI
SET @ENTRY := 27300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Vernon - On Data Set 1 1 - Set Rooted On"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Vernon - On Data Set 1 1 - Set Emote State 0"),
(@ENTRY,0,2,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,10,111281,27299,0,0,0,0,0,"Initiate Vernon - On Data Set 2 2 - Set Orientation Closest Creature 'Initiate Greer'"),
(@ENTRY,0,3,0,38,0,100,0,3,3,0,0,11,48254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Vernon - On Data Set 3 3 - Cast 'Prototype Neural Needle Impact'"),
(@ENTRY,0,4,0,38,0,100,0,4,4,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Vernon - On Data Set 4 4 - Set Rooted Off");

SET @MAXGUID := 915; 
SET @SCRIPTID := 11130700; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 2, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 17, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 111307;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`) VALUES
(@PATH, 1, 3647.87, 5909.61, 174.578, 21000, @SCRIPTID, 1.26067),
(@PATH, 2, 3640.9, 5911.28, 174.579, 21000, @SCRIPTID, 1.26067);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- Initiate Greer SAI
SET @ENTRY := 27299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,27299,1,0,0,1,1,0,0,0,0,0,0,0,"Initiate Greer - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,5,27299,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,3,0,61,0,100,0,5,27299,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.76692,"Initiate Greer - On Waypoint 5 Reached - Set Orientation 2,76692"),
(@ENTRY,0,4,5,40,0,100,0,11,27299,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,5,0,61,0,100,0,11,27299,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.84897,"Initiate Greer - On Waypoint 11 Reached - Set Orientation 5,84897");

-- Actionlist SAI
SET @ENTRY := 2729900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,55000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Active On"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,45,3,3,0,0,0,0,10,111307,27300,0,0,0,0,0,"Initiate Greer - On Script - Set Data 3 3"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,111307,27300,0,0,0,0,0,"Initiate Greer - On Script - Set Data 1 1"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,4000,4000,0,0,45,2,2,0,0,0,0,10,111307,27300,0,0,0,0,0,"Initiate Greer - On Script - Set Data 2 2"),
(@ENTRY,9,9,0,0,0,100,0,2000,2000,0,0,1,0,6000,0,0,0,0,10,111307,27300,0,0,0,0,0,"Initiate Greer - On Script - Say Line 0"),
(@ENTRY,9,10,0,0,0,100,0,14000,14000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Say Line 2"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,111307,27300,0,0,0,0,0,"Initiate Greer - On Script - Set Data 4 4"),
(@ENTRY,9,12,0,0,0,100,0,2000,2000,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Active Off");

-- Actionlist SAI
SET @ENTRY := 2729901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,70000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Active On"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,64000,64000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Initiate Greer - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID` IN (27299, 27300);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(27299, 0, 0, 'Tell me if this hurts.', 12, 0, 100, 0, 0, 0, 26296, 'Initiate Greer'),
(27299, 0, 1, 'Let''s try this one out...', 12, 0, 100, 0, 0, 0, 26298, 'Initiate Greer'),
(27299, 0, 2, 'I think I''ve got it this time..', 12, 0, 100, 0, 0, 0, 26297, 'Initiate Greer'),
(27299, 1, 0, 'How''d that feel?', 12, 0, 100, 0, 0, 0, 26299, 'Initiate Greer'),
(27299, 1, 1, 'Was that potent enough?', 12, 0, 100, 0, 0, 0, 26302, 'Initiate Greer'),
(27299, 1, 2, 'Do you think that will get some answers?', 12, 0, 100, 0, 0, 0, 26300, 'Initiate Greer'),
(27299, 2, 0, 'Hmm...', 12, 0, 100, 0, 0, 0, 26304, 'Initiate Greer'),
(27299, 2, 1, 'True, our enemies would show us no mercy.', 12, 0, 100, 0, 0, 0, 26320, 'Initiate Greer'),
(27299, 2, 2, 'True, but how far should we push?  At what point are we no better than our enemies?', 12, 0, 100, 0, 0, 0, 26319, 'Initiate Greer'),
(27300, 0, 0, 'You need more bite.  Do not show our enemies any mercy.', 12, 0, 100, 0, 0, 0, 26305, 'Initiate Vernon'),
(27300, 0, 1, 'The more pain we can inflict, the quicker we can get our answers.', 12, 0, 100, 0, 0, 0, 26306, 'Initiate Vernon');

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=111281;
DELETE FROM `waypoints` WHERE `entry`=27299;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27299, 1, 3640.38, 5908, 174.576, 'Initiate Greer'),
(27299, 2, 3642.54, 5905.63, 174.572, 'Initiate Greer'),
(27299, 3, 3645.93, 5904.91, 174.571, 'Initiate Greer'),
(27299, 4, 3647.52, 5906.78, 174.576, 'Initiate Greer'),
(27299, 5, 3646.7, 5907.29, 174.578, 'Initiate Greer'),
(27299, 6, 3647.49, 5906.69, 174.578, 'Initiate Greer'),
(27299, 7, 3646.49, 5905.07, 174.576, 'Initiate Greer'),
(27299, 8, 3643.7, 5905.04, 174.568, 'Initiate Greer'),
(27299, 9, 3641.21, 5906.38, 174.577, 'Initiate Greer'),
(27299, 10, 3640.11, 5908.16, 174.577, 'Initiate Greer'),
(27299, 11, 3641.55, 5908.3, 174.577, 'Initiate Greer');
