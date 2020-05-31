-- Gothik the Harvester
UPDATE `creature_template` SET `Speed_Walk` = 1.6, `Speed_Run` = 1.714286 WHERE `entry` = 28890;
UPDATE `creature` SET `position_x` = 2107.563721, `position_y` = -5742.198730, `position_z` = 99.855499, `orientation` = 1.374185 WHERE `guid` = 130121;
SET @NPC := 130121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`) VALUES
(@PATH, 1, 2109.85, -5727.25, 100.257, 0.413397, 0),
(@PATH, 2, 2156.03, -5712.91, 102.291, 6.15937, 0),
(@PATH, 3, 2177.85, -5738.68, 101.921, 5.56012, 0),
(@PATH, 4, 2188.7, -5759.94, 101.649, 5.14936, 10000),
(@PATH, 5, 2225.29, -5781.82, 101.775, 5.67557, 0),
(@PATH, 6, 2252.21, -5806.7, 100.959, 5.36848, 0),
(@PATH, 7, 2265.43, -5827.23, 100.945, 5.03548, 0),
(@PATH, 8, 2267.51, -5839.93, 100.944, 5.03941, 0),
(@PATH, 9, 2284.81, -5845.79, 100.935, 5.98189, 10000),
(@PATH, 10, 2259.68, -5866.16, 101.605, 3.82989, 0),
(@PATH, 11, 2241.44, -5886.94, 100.764, 4.04195, 0),
(@PATH, 12, 2228.81, -5899.27, 100.89, 3.64925, 0),
(@PATH, 13, 2201.1, -5902.2, 100.88, 3.12696, 0),
(@PATH, 14, 2179.59, -5890.74, 101.109, 2.15307, 0),
(@PATH, 15, 2181.51, -5888.24, 100.93, 0.693798, 10000),
(@PATH, 16, 2165.13, -5866.72, 101.331, 2.28265, 0),
(@PATH, 17, 2143.17, -5825.25, 101.125, 1.94886, 0),
(@PATH, 18, 2130.2, -5789.78, 98.9462, 1.48547, 10000),
(@PATH, 19, 2115.31, -5769.12, 98.1968, 1.93551, 0),
(@PATH, 20, 2107.57, -5742.3, 99.8496, 1.70931, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=28890;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(28890, 0, 0, 'Rise, minion. Rise and fly for the Scourge!', 12, 0, 100, 5, 0, 0, 29045, 'Gothik the Harvester'),
(28890, 0, 1, 'You will fly again, beast...', 12, 0, 100, 5, 0, 0, 29043, 'Gothik the Harvester'),
(28890, 1, 0, 'Surprise, surprise! Another ghoul!', 12, 0, 100, 5, 0, 0, 29038, 'Gothik the Harvester'),
(28890, 1, 1, 'Is Gothik the Harvester going to have to choke a geist?', 12, 0, 100, 5, 0, 0, 29037, 'Gothik the Harvester'),
(28890, 2, 0, 'Death is the only escape!', 12, 0, 100, 5, 0, 0, 29039, 'Gothik the Harvester');

-- Gothik the Harvester SAI
SET @ENTRY := 28890;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,34,0,100,0,2,3,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Reached Point 3 - Run Script"),
(@ENTRY,0,1,0,34,0,100,0,2,8,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Reached Point 8 - Run Script"),
(@ENTRY,0,2,0,34,0,100,0,2,14,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Reached Point 14 - Run Script"),
(@ENTRY,0,3,0,34,0,100,0,2,17,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Reached Point 17 - Run Script"),
(@ENTRY,0,4,0,25,0,100,1,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Reset - Set Active On (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 2889000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,52685,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Gryphon'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,19,28893,10,0,0,0,0,0,"Gothik the Harvester - On Script - Despawn Instant"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,28906,20,0,0,0,0,0,"On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 2889001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,52685,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Gryphon'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,19,28893,10,0,0,0,0,0,"Gothik the Harvester - On Script - Despawn Instant"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,19,28906,20,0,0,0,0,0,"On Script - Set Data 2 2");

-- Actionlist SAI
SET @ENTRY := 2889002;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,52683,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Cast 'Scarlet Ghoul'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,19,28896,10,0,0,0,0,0,"Gothik the Harvester - On Script - Despawn Instant"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,28897,20,0,0,0,0,0,"Gothik the Harvester - On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 2889003;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,52683,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Cast 'Scarlet Ghoul'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,19,28898,10,0,0,0,0,0,"Gothik the Harvester - On Script - Despawn Instant"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,11,52672,0,0,0,0,0,10,130312,28905,0,0,0,0,0,"Gothik the Harvester - On Script - Cast 'Ghoulplosion'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,28897,20,0,0,0,0,0,"Gothik the Harvester - On Script - Set Data 1 1");


-- Scourge Gryphon
UPDATE `creature_template` SET `MovementType` = 0, `InhabitType` = 4, `Speed_Walk` = 2.4, `Speed_Run` = 2.57143 WHERE `entry` = 28906;

-- Scarlet Gryphon SAI
SET @ENTRY := 28893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,52685,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Gryphon - On Spellhit 'Scourge Gryphon' - Despawn Instant");

-- Scourge Gryphon SAI
SET @ENTRY := 28906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Gryphon - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,69,1,0,0,0,0,0,8,0,0,0,1781.18,-5818.34,114.383,0,"Scourge Gryphon - On Data Set 1 1 - Move To Position"),
(@ENTRY,0,2,0,34,0,100,0,8,1,0,0,49,0,0,0,0,0,0,19,28610,100,0,0,0,0,0,"Scourge Gryphon - On Reached Point 1 - Start Attacking"),
(@ENTRY,0,3,4,38,0,100,0,2,2,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Gryphon - On Data Set 2 2 - Set Active On"),
(@ENTRY,0,4,0,61,0,100,0,2,2,0,0,69,2,0,0,0,0,0,8,0,0,0,1818.18,-5930.02,113.669,0,"Scourge Gryphon - On Data Set 2 2 - Move To Position"),
(@ENTRY,0,5,0,34,0,100,0,8,2,0,0,49,0,0,0,0,0,0,19,28610,100,0,0,0,0,0,"Scourge Gryphon - On Reached Point 2 - Start Attacking"),
(@ENTRY,0,6,0,63,0,100,0,0,0,0,0,41,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Gryphon - On Just Created - Despawn In 300000 ms");

-- Scarlet Infantryman SAI
SET @ENTRY := 28896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,52683,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Infantryman - On Spellhit 'Scarlet Ghoul' - Despawn Instant");

-- Scarlet Captain SAI
SET @ENTRY := 28898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,52683,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Captain - On Spellhit 'Scarlet Ghoul' - Despawn Instant");

-- Scarlet Ghoul SAI
SET @ENTRY := 28897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Ghoul - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,53,1,28897,0,0,0,2,8,0,0,0,1783.51,-5818.18,113.877,3.19587,"Scarlet Ghoul - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,2,3,63,0,100,0,0,0,0,0,41,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Ghoul - On Just Created - Despawn In 300000 ms"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Ghoul - On Just Created - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=28897;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(28897, 0, 0, 'So hungry...', 12, 0, 100, 0, 0, 0, 28955, 'Scarlet Ghoul'),
(28897, 0, 1, 'Must feed...', 12, 0, 100, 0, 0, 0, 28956, 'Scarlet Ghoul'),
(28897, 0, 2, 'Smell flesh... close...', 12, 0, 100, 0, 0, 0, 28958, 'Scarlet Ghoul');

UPDATE `creature_template` SET `MovementType` = 0, `InhabitType` = 3 WHERE `entry` = 28897;
DELETE FROM `waypoints` WHERE `entry`=28897;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(28897, 1, 2143.13, -5845.46, 101.335, 'Scarlet Ghoul'),
(28897, 2, 2112.23, -5869.67, 102.671, 'Scarlet Ghoul'),
(28897, 3, 2075.06, -5888.31, 104.169, 'Scarlet Ghoul'),
(28897, 4, 2047.48, -5901.68, 105.289, 'Scarlet Ghoul'),
(28897, 5, 2017.32, -5907.23, 104.617, 'Scarlet Ghoul'),
(28897, 6, 1962.61, -5905.59, 102.366, 'Scarlet Ghoul'),
(28897, 7, 1925.94, -5911, 101.514, 'Scarlet Ghoul'),
(28897, 8, 1884.37, -5910.29, 103.345, 'Scarlet Ghoul'),
(28897, 9, 1858.9, -5916.94, 104.525, 'Scarlet Ghoul'),
(28897, 10, 1840.21, -5923.29, 107.843, 'Scarlet Ghoul'),
(28897, 11, 1819.53, -5930.31, 113.439, 'Scarlet Ghoul'),
(28897, 12, 1800.91, -5936.87, 115.947, 'Scarlet Ghoul');

UPDATE `creature` SET `spawntimesecs`=30 WHERE  `id` IN (28893, 28896, 28898);
UPDATE `creature` SET `spawntimesecs`=30 WHERE  `guid`=130312;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry` IN (52685, 52683);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 52685, 0, 0, 31, 0, 3, 28893, 0, 0, 0, 0, '', 'Scourge Gryphon only targets Scarlet Gryphon'),
(13, 1, 52683, 0, 0, 31, 0, 3, 28896, 0, 0, 0, 0, '', 'Scarlet Ghoul only targets Scarlet Infantryman'),
(13, 1, 52683, 0, 1, 31, 0, 3, 28898, 0, 0, 0, 0, '', 'Scarlet Ghoul only targets Scarlet Captain'),
(13, 1, 52683, 0, 2, 31, 0, 3, 28892, 0, 0, 0, 0, '', 'Scarlet Ghoul only targets Scarlet Peasant'),
(13, 1, 52683, 0, 3, 31, 0, 3, 28897, 0, 0, 0, 0, '', 'Scarlet Ghoul only targets Scarlet Ghoul'),
(13, 1, 52683, 0, 4, 31, 0, 3, 28886, 0, 0, 0, 0, '', 'Scarlet Ghoul only targets Scarlet Fleet Defender');
