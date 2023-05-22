-- Fix scripted npcs at Falconwing Square

-- Novice Ranger scripting missing
-- Wretched Captive scripting incorrect
-- Sergeant Kan'ren scripting incorrect
-- Sleyin scripting incorrect
-- Kyrenna scripting incorrect

-- Novice Ranger SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16923;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16923) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16923,0,0,0,1,0,100,0,215000,225000,215000,225000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Novice Ranger - OOC - Say text 0');

-- Wretched Captive SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16916;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16916) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16916,0,0,0,1,0,100,0,6000,18000,18000,18000,0,5,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Wretched Captive - OOC - Play Emote 20 "Beg"');

-- Fix Wretched Captive text
UPDATE `creature_text` SET `Emote`=18, `Duration`=0 WHERE `CreatureID`=16916;

-- Sergeant Kan'ren SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16924;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16924 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=169240 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1692400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16924,0,0,0,1,0,100,0,5000,255000,255000,255000,0,80,169240,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sergeant Kan''ren - OOC - Run script'),
(169240,9,0,0,0,0,100,0,0,0,0,0,0,53,0,16924,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sergeant Kan''ren - Script - Load path'),
(169240,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sergeant Kan''ren - Script - Say text 0'),
(169240,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.04719758,'Sergeant Kan''ren - Script - Set Orientation'),
(169240,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,16916,10,0,0,0,0,0,0,'Sergeant Kan''ren - Script - Wretched Captive Say text 0'),
(169240,9,4,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sergeant Kan''ren - Script - Say text 1');

-- SAI Path for Kan'ren
DELETE FROM `waypoints` WHERE `entry`=16924;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(16924,1,9513.46,-6840.1626,16.743443,0,0, 'Kan''ren'),
(16924,2,9514.46,-6839.1626,16.743443,0,0, 'Kan''ren'),
(16924,3,9514.46,-6837.6626,16.743443,0,0, 'Kan''ren'),
(16924,4,9513.21,-6836.9126,16.743443,0,0, 'Kan''ren'),
(16924,5,9512.21,-6837.6626,16.743443,0,0, 'Kan''ren'),
(16924,6,9511.96,-6839.1626,16.743443,0,0, 'Kan''ren'),
(16924,7,9512.21,-6840.1626,16.493443,0,0, 'Kan''ren');

-- Fix Kan'ren sheath
UPDATE `creature_addon` SET `bytes2`=1 WHERE `guid`=58702;

-- Fix Kan'ren text
UPDATE `creature_text` SET `Emote`=0, `Duration`=0 WHERE `CreatureID`=16924;

-- Sleyin SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=18926;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18926 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=189260 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1892900,1892901) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18926,0,0,0,1,0,100,0,102000,102000,204000,204000,0,80,189260,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - OOC - Run script'),
(189260,9,0,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - Script - Set run off'),
(189260,9,1,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9486.051,-6807.0537,16.575666,0,'Sleyin - Script - Move to'),
(189260,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - Script - Say text 0'),
(189260,9,3,0,0,0,100,0,6000,6000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9482.344,-6805.512,16.575666,0,'Sleyin - Script - Move to'),
(189260,9,4,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.7504915595,'Sleyin - Script - Set Orientation'),
(189260,9,5,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - Script - Say text 1'),
(189260,9,6,0,0,0,100,0,92000,92000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9486.051,-6807.0537,16.575666,0,'Sleyin - Script - Move to'),
(189260,9,7,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - Script - Say text 0'),
(189260,9,8,0,0,0,100,0,6000,6000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9482.344,-6805.512,16.575666,0,'Sleyin - Script - Move to'),
(189260,9,9,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.7504915595,'Sleyin - Script - Set Orientation'),
(189260,9,10,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sleyin - Script - Say text 1');

-- Fix Sleyin text
UPDATE `creature_text` SET `Emote`=22 WHERE `CreatureID`=18926 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=274 WHERE `CreatureID`=18926 AND `GroupID`=2;

-- Remove Sleyin path
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (67954);
UPDATE `creature_addon` SET `path_id`=0,`bytes2`=1 WHERE `guid` IN (67954);
DELETE FROM `waypoint_data` WHERE `id`=679540;
DELETE FROM `waypoint_scripts` WHERE `id`=160;

-- Kyrenna SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=18929;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18929) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (189290) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1892900,1892902) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18929,0,0,0,1,0,100,0,60000,60000,558000,558000,0,80,189290,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - OOC - Run script'),
(189290,9,0,0,0,0,100,0,0,0,0,0,0,53,0,189290,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Move path'),
(189290,9,1,0,0,0,100,0,7000,7000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 0'),
(189290,9,2,0,0,0,100,0,8000,8000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 1'),
(189290,9,3,0,0,0,100,0,8000,8000,0,0,0,53,0,189291,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Move path'),
(189290,9,4,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.51327419,'Kyrenna - Script - Set Orientation'),
(189290,9,5,0,0,0,100,0,204000,204000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 2'),
(189290,9,6,0,0,0,100,0,7000,7000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 3'),
(189290,9,7,0,0,0,100,0,201000,201000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 4'),
(189290,9,8,0,0,0,100,0,7000,7000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kyrenna - Script - Say text 5');

-- SAI Path for Kyrenna
DELETE FROM `waypoints` WHERE `entry` IN (189290,189291);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(189290,1,9548.289,-6828.249,16.763393,0,0, 'Kyrenna'),
(189290,2,9551.43,-6836.5903,16.611946,0,0, 'Kyrenna'),
(189291,1,9548.289,-6828.249,16.763393,0,0, 'Kyrenna'),
(189291,2,9552.018,-6825.113,16.513393,0,0, 'Kyrenna');

-- Fix text for Kyrenna
DELETE FROM `creature_text` WHERE `CreatureID`=18929;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18929,0,0,'If only I had some wine to go with my cheese...',12,0,100,18,0,0,16093,0,'Kyrenna'),
(18929,1,0,'The hours would pass so much more sweetly.',12,0,100,0,0,0,16096,0,'Kyrenna'),
(18929,2,0,'Ooh what a dreadful job!',12,0,100,1,0,0,16094,0,'Kyrenna'),
(18929,3,0,'All day, surrounded by the stench of bad feet.',12,0,100,0,0,0,16095,0,'Kyrenna'),
(18929,4,0,'Why couldn''t mother have chosen something else to dedicate herself to?',12,0,100,1,0,0,16097,0,'Kyrenna'),
(18929,5,0,'Cakes, pastries, even bread - anything but cheese!',12,0,100,0,0,0,16098,0,'Kyrenna');
