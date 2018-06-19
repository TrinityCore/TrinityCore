--
-- [Q] The Knife Revealed -- http://wotlk.openwow.com/quest=4129
-- Quintis Jonespyre SAI
SET @ENTRY := 7879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,4129,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Quintis Jonespyre - On Quest 'The Knife Revealed' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 787900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,11,15050,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Psychometry'"),
(@ENTRY,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=7879;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(7879, 0, 0, 'I will need to focus my energies onto this knife.  By doing so, I should catch some of the stronger psychic impressions associated with it.', 12, 0, 100, 0, 0, 0, 5148, 'Quintis Jonespyre'),
(7879, 1, 0, 'I... I''ve seen enough I think... so very draining...', 12, 0, 100, 462, 0, 0, 5149, 'Quintis Jonespyre');

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

-- 
-- [Q] The Ward of Wakening -- http://wotlk.openwow.com/quest=10961
-- Morthis Whisperwing SAI
SET @ENTRY := 22832;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,10961,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Quest 'The Ward of Wakening' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,10961,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Morthis Whisperwing - On Quest 'The Ward of Wakening' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 2283200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,90,8,0,0,0,0,0,0,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,91,8,0,0,0,0,0,0,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Set Remove Standstate Kneel"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,3,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 3"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=22832;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(22832, 0, 0, 'There are few left in the world who can prepare the Ward of Waking, $N. We are fortunate that I am among them.', 12, 0, 100, 1, 0, 0, 20516, 'Morthis Whisperwing'),
(22832, 1, 0, '%s kneels, filling the vial with water from the moonwell.', 16, 0, 100, 0, 0, 0, 20512, 'Morthis Whisperwing'),
(22832, 2, 0, '%s combines the herbs with the moonwell water to create the Ward of Waking', 16, 0, 100, 0, 0, 0, 20517, 'Morthis Whisperwing'),
(22832, 3, 0, 'The potion is finished. I can only hope Clintar forgives us for interrupting his sojourn in the Emerald Dream.', 12, 0, 100, 1, 0, 0, 20513, 'Morthis Whisperwing');

-- 
-- [Q] To Catch A Sparrowhawk -- http://wotlk.openwow.com/quest=10987
-- Watcher Elaira SAI
SET @ENTRY := 22981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,10987,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Watcher Elaira - On Quest 'To Catch A Sparrowhawk' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,10987,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Watcher Elaira - On Quest 'To Catch A Sparrowhawk' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 2298100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,12,23036,1,17000,0,0,0,8,0,0,0,-1272.48,9164.06,217.776,4.20625,"Watcher Elaira - On Script - Summon Creature 'Captive Sparrowhawk'"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,3000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,23036,60,0,0,0,0,0,"Watcher Elaira - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,4000,0,0,0,0,19,23036,30,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,1,1,4000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,1,2,1000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,19,23036,60,0,0,0,0,0,"Watcher Elaira - On Script - Set Data 2 2");

-- Captive Sparrowhawk SAI
SET @ENTRY := 23036;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Sparrowhawk - On Data Set 1 1 - Set Run Off"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,-1273.05,9161.96,217.298,4.34369,"Captive Sparrowhawk - On Data Set 1 1 - Move To Position"),
(@ENTRY,0,2,3,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Sparrowhawk - On Data Set 2 2 - Set Run On"),
(@ENTRY,0,3,0,61,0,100,0,2,2,0,0,69,0,0,0,0,0,0,8,0,0,0,-1335.43,9128.58,251.388,3.6604,"Captive Sparrowhawk - On Data Set 2 2 - Move To Position");

DELETE FROM `creature_text` WHERE `CreatureID` IN (22981, 23036);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(22981, 0, 0, 'Come closer, young one. There\'s nothing to fear from me or $n.', 12, 0, 100, 1, 0, 0, 20738, 'Watcher Elaira'),
(23036, 0, 0, '%s cautiously approaches Wather Elaira.', 16, 0, 100, 0, 0, 0, 20739, 'Captive Sparrowhawk'),
(22981, 1, 0, 'I\'m going to train you to help $N with very important task. After that, I promose you\'ll be free to return home.', 12, 0, 100, 1, 0, 0, 20740, 'Watcher Elaira'),
(22981, 2, 0, 'You will hear the call when you are needed. Fly east, to Skettis, and wait there for $N\'s signal.', 12, 0, 100, 1, 0, 0, 20751, 'Watcher Elaira');