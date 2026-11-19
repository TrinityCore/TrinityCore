--
-- [Q] Reclaiming the Charred Vale -- http://wotlk.openwow.com/quest=1059
-- Falfindel Waywarder SAI
SET @ENTRY := 4048;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,1059,0,0,0,53,0,4048,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Quest 'Reclaiming the Charred Vale' Finished - Start Waypoint"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Quest 'Reclaiming the Charred Vale' Finished - Set Active On"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Quest 'Reclaiming the Charred Vale' Finished - Say Line 0"),
(@ENTRY,0,3,4,40,0,100,0,5,4048,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,4,0,61,0,100,0,5,4048,0,0,54,27000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Waypoint 5 Reached - Pause Waypoint");

DELETE FROM `waypoints` WHERE `entry`=4048;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4048, 1, -4524.24, -782.628, -41.5763, 'Falfindel Waywarder'),
(4048, 2, -4520.69, -775.438, -41.0733, 'Falfindel Waywarder'),
(4048, 3, -4514.55, -770.937, -40.0658, 'Falfindel Waywarder'),
(4048, 4, -4503.63, -774.032, -40.224, 'Falfindel Waywarder'),
(4048, 5, -4488.25, -767.98, -36.61, 'Falfindel Waywarder'),
(4048, 6, -4499.17, -773.174, -39.449, 'Falfindel Waywarder'),
(4048, 7, -4514.09, -771.136, -40.0971, 'Falfindel Waywarder'),
(4048, 8, -4520.48, -775.049, -41.0191, 'Falfindel Waywarder'),
(4048, 9, -4524.16, -782.978, -41.2406, 'Falfindel Waywarder'),
(4048, 10, -4524.12, -788.099, -41.6929, 'Falfindel Waywarder'),
(4048, 11, -4524.12, -788.099, -41.6929, 'Falfindel Waywarder');

DELETE FROM `creature_text` WHERE `CreatureID`=4048;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(4048, 0, 0, 'We must hurry.', 12, 0, 100, 1, 0, 0, 1397, 'Falfindel Waywarder'),
(4048, 1, 0, 'Spirits of the forest come forth and heed nature''s call!', 12, 0, 100, 1, 0, 0, 1398, 'Falfindel Waywarder'),
(4048, 2, 0, 'Spirits of the forest, you are needed! Make haste to the Charred Vale!', 12, 0, 100, 25, 0, 0, 1400, 'Falfindel Waywarder');

-- Actionlist SAI
SET @ENTRY := 404800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,6537,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Script - Cast 'Call of the Forest'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4479.45,-768.01,-37.36,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4486.55,-769.8,-37.23,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4484.95,-767.87,-36.61,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4484.9,-770.79,-37.62,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4484.07,-765.04,-35.74,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,12,4059,3,50000,0,0,0,8,0,0,0,-4485.88,-764.05,-35.19,0,"Falfindel Waywarder - On Script - Summon Creature 'Forest Spirit'"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Script - Say Line 2"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,28,6537,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falfindel Waywarder - On Script - Remove Aura 'Call of the Forest'");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=4059;

-- Forest Spirit SAI
SET @ENTRY := 4059;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Forest Spirit - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 405900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,7000,7000,0,0,53,1,4059,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=4059;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4059, 1, -4484.5, -759, -33.57, 'Forest Spirit'),
(4059, 2, -4484.5, -759, -33.57, 'Forest Spirit'),
(4059, 3, -4483, -755.56, -31.94, 'Forest Spirit'),
(4059, 4, -4481, -686.51, -14.39, 'Forest Spirit'),
(4059, 5, -4472, -571.90, 5.91, 'Forest Spirit');
