-- DB/Quest: The Collapse
DELETE FROM `event_scripts` WHERE `id`=16929;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(16929, 10, 8, 25742, 0, 0, 0, 0, 0, 0),
(16929, 3, 10, 25742, 360000, 0, 3517.290039, 4538.782715, -12.983689, 4.428759),
(16929, 7, 10, 25629, 360000, 0, 3492.105469, 4478.011719, -12.997340, 0.210166),
(16929, 7, 10, 25652, 360000, 0, 3507.666260, 4509.300293, -14.792936, 0.945820),
(16929, 7, 10, 25652, 360000, 0, 3505.954834, 4506.928223, -14.817587, 0.945820),
(16929, 7, 10, 25652, 360000, 0, 3505.296631, 4506.016113, -14.837238, 0.945820),
(16929, 7, 10, 25652, 360000, 0, 3504.330322, 4504.676758, -14.837238, 0.945820);

-- Alluvius SAI
SET @ENTRY := 25742;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,25742,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvius - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,25742,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvius - On Waypoint 1 Reached - Run Script");

DELETE FROM `waypoints` WHERE `entry`=25742;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25742, 1, 3511.336426, 4519.295898, -11.937509, 'Alluvius');

-- Actionlist SAI
SET @ENTRY := 2574200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,5000,5000,5000,5000,45,1,1,0,0,0,0,9,25652,0,25,0,0,0,0,"Alluvius - On Script - Set Data 1 1"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvius - On Script - Play Emote 36"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,10000,10000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvius - On Script - Despawn Instant");

-- Nerub'ar Scarab SAI
SET @ENTRY := 25652;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,53,0,25652,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Scarab - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,6,25652,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Scarab - On Waypoint 6 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=25652;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25652, 1, 3509.71, 4510.5, -14.6752, 'Nerub\'ar Scarab'),
(25652, 2, 3515.16, 4512.57, -13.4052, 'Nerub\'ar Scarab'),
(25652, 3, 3520.58, 4511.77, -12.5632, 'Nerub\'ar Scarab'),
(25652, 4, 3530.14, 4507.88, -12.9948, 'Nerub\'ar Scarab'),
(25652, 5, 3536.34, 4508.6, -12.9948, 'Nerub\'ar Scarab'),
(25652, 6, 3553.48, 4510.25, -12.9948, 'Nerub\'ar Scarab');

-- Lord Kryxix SAI
SET @ENTRY := 25629;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,53,1,25629,0,0,0,2,1,0,0,0,0,0,0,0,"Lord Kryxix - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Kryxix - On Just Summoned - Say Line 0"),
(@ENTRY,0,2,0,40,0,100,0,4,25629,0,0,49,0,0,0,0,0,0,21,80,0,0,0,0,0,0,"Lord Kryxix - On Waypoint 4 Reached - Start Attacking");

DELETE FROM `waypoints` WHERE `entry`=25629;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25629, 1, 3529.33, 4490.55, -12.9951, 'Lord Kryxix'),
(25629, 2, 3534.51, 4509.94, -12.9951, 'Lord Kryxix'),
(25629, 3, 3533.52, 4527.86, -12.9951, 'Lord Kryxix'),
(25629, 4, 3512.91, 4539.59, -12.987, 'Lord Kryxix');

DELETE FROM `creature_text` WHERE `entry`=25629;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(25629, 0, 0, 'Foolish elemental slave! You an your master will pay for your medding!', 14, 0, 100, 0, 0, 0, 'Lord Kryxix', 24956);
