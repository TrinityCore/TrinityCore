--
DELETE FROM `skill_fishing_base_level` WHERE `entry`=4710;
INSERT INTO `skill_fishing_base_level` (`entry`, `skill`) VALUES
(4710, 480);
-- Fel Portal Alarm SAI
SET @ENTRY := 23310;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,46907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On Respawn - Cast 'Boss Fel Portal State' (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On Data Set 1 1 - Increment Phase"),
(@ENTRY,0,2,3,1,32,100,0,1000,1000,0,0,12,25003,5,120000,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - Out of Combat - Summon Creature 'Emissary of Hate' (Phase 32)"),
(@ENTRY,0,3,0,61,32,100,0,1000,1000,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - Out of Combat - Set Event Phase 0 (Phase 32)");

DELETE FROM `creature` WHERE `id`=25003;

-- Irespeaker SAI
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,3000,10000,15000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,13000,16000,20000,35000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Irespeaker - On Just Died - Quest Credit 'Kanrethad's Quest' (No Repeat)"),
(@ENTRY,0,3,0,6,0,100,0,5000,5000,10000,10000,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Irespeaker - On Just Died - Set Data 1 1");

-- Unleashed Hellion SAI
SET @ENTRY := 25002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,33,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unleashed Hellion - On Just Died - Quest Credit 'Kanrethad's Quest' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,18000,35000,11,11876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast 'War Stomp'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12600,16000,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast 'Rain of Fire'"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Unleashed Hellion - On Just Died - Set Data 1 1");

-- Emissary of Hate SAI
SET @ENTRY := 25003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,15000,20000,11,25003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast 'Mortar'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,15000,20000,11,38611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast 'Flame Wave'"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary of Hate - On Just Summoned - Start Random Movement");
-- Master Gadrin SAI
SET @ENTRY := 3188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,808,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Master Gadrin - On Quest 'Minshina's Skull' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 318800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,12,3289,5,14000,0,0,0,8,0,0,0,-822.91,-4923.33,19.6365,3.41642,"Master Gadrin - On Script - Summon Creature 'Spirit of Minshina'"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Master Gadrin - On Script - Set Orientation Closest Player"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Master Gadrin - On Script - Say Line 0");

-- Spirit of Minshina SAI
SET @ENTRY := 3289;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Minshina - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 328900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Spirit of Minshina - On Script - Set Orientation Closest Player"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,2,0,0,0,0,0,1,2000,2000,0,0,0,0,0,"Spirit of Minshina - On Script - Play Emote 2"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Minshina - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=3188;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(3188, 0, 0, 'I thank you, $n.  And my brother thanks you.', 12, 0, 100, 0, 0, 0, 'Master Gadrin', 983);
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
-- Areatrigger SAI
SET @ENTRY := 1447;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,81519,8127,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1");

-- Antu'sul SAI
SET @ENTRY := 8127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,50,2,11600,11600,13300,21700,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Earthgrab Totem' (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,50,3,11600,11600,13300,21700,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Healing Ward' (Normal Dungeon)"),
(@ENTRY,0,2,6,4,0,100,3,0,0,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - On Aggro - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,20,0,0,11,11895,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-20% Health - Cast 'Healing Wave of Antu'sul' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,25,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-25% Health - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,3,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-25% Health - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - On Aggro - Say Line 1 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,7,8,2,0,100,3,0,75,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-75% Health - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,8,0,61,0,100,3,0,75,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-75% Health - Say Line 2 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,100,2,5000,5000,12000,14000,11,16006,0,0,0,0,0,5,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,3000,3000,9000,11000,11,15501,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Earth Shock' (Normal Dungeon)"),
(@ENTRY,0,11,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Antu'sul - On Data Set 1 1 - Start Attacking");

SET @ENTRY := 8127;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY,0,0, 'The children of Sul will protect their master. Rise once more Sul\'lithuz!',14,0,100,0,0,0, 4178, 0, 'Antu\'sul'),
(@ENTRY,1,0, 'Lunch has arrived, my beautiful children. Tear them to pieces!',14,0,100,0,0,0, 4166, 0, 'Antu\'sul'),
(@ENTRY,2,0, 'Rise and defend your master!',14,0,100,0,0,0, 4177, 0, 'Antu\'sul');
-- Commander Hogarth SAI
SET @ENTRY := 19937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Hogarth - On Respawn - Cast 'Shroud of Death' (No Repeat)"),
(@ENTRY,0,1,2,20,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1186.95,2608.81,27.702,5.38523,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,2,3,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1192.14,2602.7,29.2625,0.0820243,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,3,4,61,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1181.95,2611.13,27.3004,4.61566,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,4,5,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1183.65,2603.66,29.4927,6.09219,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,5,6,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1184.48,2609.26,27.7192,5.01103,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,6,7,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1175.39,2607.4,28.853,3.63473,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,7,8,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1178.36,2609.96,27.8814,4.12375,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,8,9,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1182.51,2608.35,28.1201,4.67383,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,9,10,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1189.12,2601.88,29.6988,0.242659,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,10,11,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1179.46,2606.03,29.0216,3.81031,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,11,12,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1180.6,2598.15,35.2317,1.94692,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,12,13,61,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1190.87,2607.06,27.9991,5.86898,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,13,14,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1179.81,2603.43,29.8027,3.12637,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,14,15,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1184.47,2606.9,28.4442,5.18881,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,15,16,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1186.63,2605.58,28.7169,5.79079,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,16,17,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1189.03,2604.6,28.8694,6.10697,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,17,18,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1185.68,2603.39,29.4476,5.18881,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,18,0,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1181.97,2605.76,28.9476,4.40683,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'");

DELETE FROM `creature_template_addon` WHERE `entry` IN (20117, 19863);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(20117, 0, 0, 0, 0, 0, '33900'),
(19863, 0, 0, 0, 0, 0, '33900');

-- Vengeful Unyielding Knight SAI
SET @ENTRY := 20117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding Knight - On Just Summoned - Despawn In 15000 ms"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding Knight - On Just Summoned - Play Emote 2");

-- Vengeful Unyielding SAI
SET @ENTRY := 19863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding - On Just Summoned - Despawn In 15000 ms"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding - On Just Summoned - Play Emote 2");
--
UPDATE `creature_questender` SET `id` =38017 WHERE `quest` =24880;
-- Tiny Snowman SAI
SET @ENTRY := 15710;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,34,0,0,0,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tiny Snowman - Received Emote 34 - Play Emote 94");
--
DELETE FROM `smart_scripts` WHERE `entryorguid`=20206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20206, 0, 0, 0, 20, 0, 100, 0, 10919, 0, 0, 0, 53, 0, 20206, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On Quest \'Fei Fei\'s Treat\' Finished - Start Waypoint (Phase 1) (No Repeat)');
--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (4131, 4133);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4131, 0, 0, 0, 0, 0, 100, 1, 4000, 7000, 22000, 25000, 11, 6016, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - IC - Cast Pierce Armor'),
(4131, 0, 1, 0, 0, 0, 100, 1, 10000, 16000, 0, 0, 11, 8137, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - IC - Cast Pierce Armor'),
(4131, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 39, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - on hp below 15 % - call for help');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4133 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4133, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 39, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silithid Hive Drone - on hp below 15 % - call for help');
--
UPDATE creature_template SET mechanic_immune_mask = mechanic_immune_mask | 0x20 WHERE entry = 31464;
--
DELETE FROM `disables` WHERE `entry` IN (649,650) AND `sourceType` = 7;
DELETE FROM `disables` WHERE `entry` = 650 AND `sourceType` = 2;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(7, 649, 0, '', '', 'Disable mmaps - Trial of the Crusader'),
(7, 650, 0, '', '', 'Disable mmaps - Trial of the Champion'),
(2, 650, 3, '', '', 'Disable Trial of the Champion, broken instance');
--
UPDATE `gameobject_template` SET `flags`=32 WHERE `entry` IN (175611,175612,175613,175614);
-- A Friendly Chat... (24576, 24657)
-- Snivel Rustrocket set gossip flag
UPDATE `creature_template` SET `npcflag` = 1, `AIName`='SmartAI' WHERE `entry` = 37715;

-- Quest credit SAI
DELETE FROM `smart_scripts` WHERE (`entryorguid`=37715 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37715,0,0,0,62,0,100,0,10946,0,0,0,11,70646,2,0,0,0,0,7,0,0,0,0,0,0,0, "Snivel Rustrocket - on gosip 10947 - cast Love - Create Snivel's Ledger");

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=10929);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10929,0,0,9,24576,0,0,0,'','Show gossip only if plaer have A Friendly Chat... Horde quest'),
(15,10929,0,1,9,24657,0,0,0,'','Show gossip only if plaer have A Friendly Chat... Alliance quest');
-- Irespeaker SAI
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,3000,10000,15000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,13000,16000,20000,35000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Irespeaker - On Just Died - Quest Credit 'Kanrethad's Quest' (No Repeat)"),
(@ENTRY,0,3,0,6,0,100,0,5000,5000,10000,10000,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Irespeaker - On Just Died - Set Data 1 1"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,11,45023,0,0,0,0,0,19,25953,13,0,0,0,0,0,"Irespeaker - On Reset - Cast 'Fel Consumption'");
--
UPDATE `creature_text` SET `type`=14 WHERE `entry`=20977;
--
UPDATE `creature` SET `position_x`=1772.803833, `position_y`=848.654846, `position_z`=123.192604, `orientation`=1.649258 WHERE  `guid`=127067;
UPDATE `creature` SET `position_x`=1772.699585, `position_y`=852.786560, `position_z`=123.192734, `orientation`=4.675874 WHERE  `guid`=127068;

DELETE FROM `creature_addon` WHERE `guid` IN (127051, 127062, 127065, 127059, 127047);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127051, 0, 0, 0, 1, 4, ''),
(127062, 0, 0, 0, 1, 4, ''),
(127065, 0, 0, 0, 1, 4, ''),
(127059, 0, 0, 0, 1, 4, ''),
(127047, 0, 0, 0, 1, 4, '');

DELETE FROM `creature_addon` WHERE `guid` IN (127067, 127068);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127067, 0, 0, 0, 1, 36, ''),
(127068, 0, 0, 0, 1, 36, '');

UPDATE `creature_addon` SET `emote`=20 WHERE  `guid`=127043;

/* emotes for these creatures. http://pokit.org/get/?2ee8b0b514852adc528b2543f704fdcd.jpg*/

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127079;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1580.776,`position_y`=726.0986,`position_z`=143.0329 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1580.776,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,2,1601.526,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,3,1580.776,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,4,1601.526,726.0986,143.0329,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE0002D7B1EE .go 1580.776 726.0986 143.0329

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127077;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1634.252,`position_y`=750.1481,`position_z`=143.0402 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1634.252,750.1481,143.0402,0,0,0,0,100,0),
(@PATH,2,1645.534,749.2593,143.062,0,0,0,0,100,0),
(@PATH,3,1646.846,740.0786,143.036,0,0,0,0,100,0),
(@PATH,4,1643.028,738.3261,143.0428,0,0,0,0,100,0),
(@PATH,5,1634.346,729.3132,143.0253,0,0,0,0,100,0),
(@PATH,6,1629.24,728.4056,143.036,0,0,0,0,100,0),
(@PATH,7,1625.434,724.1005,143.033,0,0,0,0,100,0),
(@PATH,8,1625.066,724.9523,143.0346,0,0,0,0,100,0),
(@PATH,9,1633.39,728.2556,143.0207,0,0,0,0,100,0),
(@PATH,10,1634.352,731.7579,143.036,0,0,0,0,100,0),
(@PATH,11,1642.503,738.0968,143.036,0,0,0,0,100,0),
(@PATH,12,1646.744,748.6193,143.0608,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE0003D7B1EE .go 1634.252 750.1481 143.0402

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127078;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1624.936,`position_y`=762.2312,`position_z`=143.0362 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1624.936,762.2312,143.0362,0,0,0,0,100,0),
(@PATH,2,1624.857,762.3463,143.0362,0,0,0,0,100,0),
(@PATH,3,1616.904,760.4952,143.0778,0,0,0,0,100,0),
(@PATH,4,1616.059,757.1263,143.036,0,0,0,0,100,0),
(@PATH,5,1615.883,751.8171,143.036,0,0,0,0,100,0),
(@PATH,6,1612.587,742.8907,143.036,0,0,0,0,100,0),
(@PATH,7,1615.973,735.1326,143.036,0,0,0,0,100,0),
(@PATH,8,1616.567,728.8411,143.0389,0,0,0,0,100,0),
(@PATH,9,1616.565,728.8934,143.0389,0,0,0,0,100,0),
(@PATH,10,1616.015,735.0688,143.036,0,0,0,0,100,0),
(@PATH,11,1612.599,741.9441,143.036,0,0,0,0,100,0),
(@PATH,12,1612.643,745.9359,143.036,0,0,0,0,100,0),
(@PATH,13,1615.984,759.0609,143.0375,0,0,0,0,100,0),
(@PATH,14,1620.861,760.4977,143.036,0,0,0,0,100,0),
(@PATH,15,1624.961,762.2328,143.0362,0,0,0,0,100,0),
(@PATH,16,1624.857,762.3463,143.0362,0,0,0,0,100,0),
(@PATH,17,1616.904,760.5043,143.0776,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE000357B1EE .go 1624.936 762.2312 143.0362

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid` IN (29774, 29820) AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Pathing for  Entry: 29774 'TDB FORMAT' 
SET @NPC := 127023;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1642.346,`position_y`=653.1481,`position_z`=125.2523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1642.346,653.1481,125.2523,0,0,0,0,100,0),
(@PATH,2,1639.856,642.3232,125.6559,0,0,0,0,100,0),
(@PATH,3,1642.258,637.7573,126.032,0,0,0,0,100,0),
(@PATH,4,1647.147,632.4925,126.6323,0,0,0,0,100,0),
(@PATH,5,1657.781,625.1252,128.0753,0,0,0,0,100,0),
(@PATH,6,1664.838,624.4281,127.6226,0,0,0,0,100,0),
(@PATH,7,1669.714,625.9705,127.4224,0,0,0,0,100,0),
(@PATH,8,1674.736,633.4069,127.3273,0,0,0,0,100,0),
(@PATH,9,1673.877,644.5715,126.3829,0,0,0,0,100,0),
(@PATH,10,1668.756,649.8423,126.1618,0,0,0,0,100,0),
(@PATH,11,1662.11,654.2892,125.6076,0,0,0,0,100,0),
(@PATH,12,1655.857,656.4763,125.5904,0,0,0,0,100,0),
(@PATH,13,1645.618,656.3919,125.2844,0,0,0,0,100,0),
(@PATH,14,1642.373,653.2665,125.2903,0,0,0,0,100,0);
-- 0x1C3AE04B801D1380006CCE0000D7B1EE .go 1642.346 653.1481 125.2523

DELETE FROM `creature_formations` WHERE `leaderGUID`=127023;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127023, 127023, 0, 0, 2, 0, 0),
(127023, 127013, 4, 50, 2, 0, 0),
(127023, 127024, 4, 310, 2, 0, 0);

-- Pathing for  Entry: 29829 'TDB FORMAT' 
SET @NPC := 127069;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1592.818,`position_y`=817.3067,`position_z`=149.783 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1592.818,817.3067,149.783,0,0,0,0,100,0),
(@PATH,2,1601.493,805.8055,146.3105,0,0,0,0,100,0),
(@PATH,3,1609.685,802.7231,145.2017,0,0,0,0,100,0),
(@PATH,4,1623.651,794.6301,143.8499,0,0,0,0,100,0),
(@PATH,5,1615.21,801.1007,144.687,0,0,0,0,100,0),
(@PATH,6,1605.104,803.2402,145.5161,0,0,0,0,100,0),
(@PATH,7,1597.137,810.431,147.7381,0,0,0,0,100,0),
(@PATH,8,1591.998,822.5156,150.5477,0,0,0,0,100,0),
(@PATH,9,1586.166,840.6243,153.7294,0,0,0,0,100,0),
(@PATH,10,1584.692,843.8578,154.2673,0,0,0,0,100,0),
(@PATH,11,1584.178,844.4227,154.4869,0,0,0,0,100,0),
(@PATH,12,1590.102,830.2843,152.1621,0,0,0,0,100,0);
-- 0x1C3AE04B801D2140006CCE0000D7B1EE .go 1592.818 817.3067 149.783

-- Pathing for  Entry: 29829 'TDB FORMAT' 
SET @NPC := 127070;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1706.755,`position_y`=857.1785,`position_z`=129.9813 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1706.755,857.1785,129.9813,0,0,0,0,100,0),
(@PATH,2,1707.281,867.1033,130.2534,0,0,0,0,100,0),
(@PATH,3,1704.177,879.5166,130.7884,0,0,0,0,100,0),
(@PATH,4,1691.342,892.488,132.9258,0,0,0,0,100,0),
(@PATH,5,1679.412,891.944,134.244,0,0,0,0,100,0),
(@PATH,6,1668.286,882.3208,137.746,0,0,0,0,100,0),
(@PATH,7,1673.63,888.4031,136.1639,0,0,0,0,100,0),
(@PATH,8,1687.955,893.6246,133.4256,0,0,0,0,100,0),
(@PATH,9,1701.138,885.8834,131.8191,0,0,0,0,100,0),
(@PATH,10,1706.935,871.8005,130.679,0,0,0,0,100,0);
-- 0x1C3AE04B801D2140006CCE000057B1EE .go 1706.755 857.1785 129.9813

-- Pathing for  Entry: 29820 'TDB FORMAT' 
SET @NPC := 127054;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1627.05,`position_y`=895.2917,`position_z`=145.9627 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1627.05,895.2917,145.9627,0,0,0,0,100,0),
(@PATH,2,1641.819,895.4995,144.4391,0,0,0,0,100,0),
(@PATH,3,1646.381,886.3206,142.0332,0,0,0,0,100,0),
(@PATH,4,1648.376,877.1378,140.8607,0,0,0,0,100,0),
(@PATH,5,1651.261,870.6509,139.9442,0,0,0,0,100,0),
(@PATH,6,1648.879,874.7926,140.348,0,0,0,0,100,0),
(@PATH,7,1648.431,879.759,140.6906,0,0,0,0,100,0),
(@PATH,8,1643.23,894.2725,143.7524,0,0,0,0,100,0),
(@PATH,9,1633.633,896.613,144.9795,0,0,0,0,100,0),
(@PATH,10,1628.168,895.5144,145.8911,0,0,0,0,100,0),
(@PATH,11,1608.678,886.468,148.1761,0,0,0,0,100,0),
(@PATH,12,1600.244,880.922,149.9891,0,0,0,0,100,0),
(@PATH,13,1583.596,870.7088,152.9289,0,0,0,0,100,0),
(@PATH,14,1593.538,876.7352,151.3219,0,0,0,0,100,0),
(@PATH,15,1606.508,885.0313,148.7535,0,0,0,0,100,0),
(@PATH,16,1616.299,891.1467,147.5494,0,0,0,0,100,0),
(@PATH,17,1627.23,895.3035,145.926,0,0,0,0,100,0),
(@PATH,18,1641.784,895.3555,144.6143,0,0,0,0,100,0);
-- 0x1C3AE04B801D1F00006CCE000257B1EE .go 1627.05 895.2917 145.9627

DELETE FROM `creature_formations` WHERE `leaderGUID`=127054;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127054, 127054, 0, 0, 2, 0, 0),
(127054, 127064, 4, 90, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (127057, 127053, 127063, 127052, 127060, 127055, 127066, 127048, 127049, 127061, 127056, 127050);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127057, 0, 0, 0, 1, 1, ''),
(127053, 0, 0, 0, 1, 1, ''),
(127063, 0, 0, 0, 1, 1, ''),
(127052, 0, 0, 0, 1, 1, ''),
(127060, 0, 0, 0, 1, 1, ''),
(127055, 0, 0, 0, 1, 1, ''),
(127066, 0, 0, 0, 1, 1, ''),
(127048, 0, 0, 0, 1, 1, ''),
(127049, 0, 0, 0, 1, 1, ''),
(127061, 0, 0, 0, 1, 1, ''),
(127056, 0, 0, 0, 1, 1, ''),
(127050, 0, 0, 0, 1, 1, '');
--
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=27963 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `creature_formations` WHERE `leaderGUID`=126709;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126709, 126709, 0, 0, 2, 0, 0),
(126709, 126692, 4, 50, 2, 0, 0),
(126709, 126693, 4, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126687;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126687, 126687, 0, 0, 2, 0, 0),
(126687, 126705, 3, 50, 2, 0, 0),
(126687, 126700, 3, 310, 2, 0, 0);

UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid` IN (126711, 126701, 126703);
DELETE FROM `creature_formations` WHERE `leaderGUID`=126690;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126690, 126690, 0, 0, 2, 0, 0),
(126690, 126707, 3, 50, 2, 0, 0),
(126690, 126701, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126691;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126691, 126691, 0, 0, 2, 0, 0),
(126691, 126708, 3, 50, 2, 0, 0),
(126691, 126702, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126695;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126695, 126695, 0, 0, 2, 0, 0),
(126695, 126713, 3, 50, 2, 0, 0),
(126695, 126703, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126696;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126696, 126696, 0, 0, 2, 0, 0),
(126696, 126714, 3, 50, 2, 0, 0),
(126696, 126704, 3, 310, 2, 0, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126696; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1266960, 1, 1180.73, 659.129, 196.233, 0, 0, 0, 0, 100, 3108493),
(1266960, 2, 1181.3, 667.947, 196.233, 0, 0, 0, 0, 100, 3108495),
(1266960, 3, 1180.7, 675.583, 196.235, 0, 0, 0, 0, 100, 3108497),
(1266960, 4, 1177.06, 683.484, 196.235, 0, 0, 0, 0, 100, 3108499),
(1266960, 7, 1180.73, 659.129, 196.233, 0, 0, 0, 0, 100, 3108493),
(1266960, 6, 1181.3, 667.947, 196.233, 0, 0, 0, 0, 100, 3108495),
(1266960, 5, 1180.7, 675.583, 196.235, 0, 0, 0, 0, 100, 3108497),
(1266960, 8, 1177.75, 651.607, 196.235, 0, 0, 0, 0, 100, 3108501);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126715;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126715, 126715, 0, 0, 2, 0, 0),
(126715, 126716, 5, 270, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126694;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126694, 126694, 0, 0, 2, 0, 0),
(126694, 126711, 3, 50, 2, 0, 0),
(126694, 126712, 3, 310, 2, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=28055;
-- Dark Rune Shaper SAI
SET @ENTRY := 27965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=14;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,14,0,1,0,100,0,2000,2000,4000,4000,11,50563,0,0,0,0,0,19,28055,50,0,0,0,0,0,"Dark Rune Shaper - On Reset - Cast 'Carve Stone'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=50563;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 50563, 0, 0, 31, 0, 3, 28055, 0, 0, 0, 0, '', 'Carve Stone - only targets Dummy');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=50563;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 50563, 64, '', '', 'Ignore LOS for Carve Stone');

UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `guid` IN (126738, 126745, 126739, 126744);
-- Scourge Reanimator SAI
SET @GUID := -127410;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,127435,26635,0,0,0,0,0,"Scourge Reanimator - On Just Died - Set Data 1 1"),
(@GUID,0,1,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,10,127426,26635,0,0,0,0,0,"Scourge Reanimator - On Just Died - Set Data 1 2");


-- Risen Drakkari Warrior SAI
SET @ENTRY := 26635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,9500,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Ghost Strike' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,7250,10000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Crush Armor' (Dungeon)"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Just Summoned - Start Random Movement"),
(@ENTRY,0,3,7,38,0,100,0,1,1,0,0,53,1,@ENTRY*100+00,0,0,0,2,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,4,8,38,0,100,0,1,2,0,0,53,1,@ENTRY*100+01,0,0,0,2,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 2 - Start Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,9,@ENTRY*100+00,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-358.38,-592.396,4.37907,3.71398,"Risen Drakkari Warrior - On Waypoint 9 Reached - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,0,6,0,40,0,100,0,9,@ENTRY*100+01,0,0,12,26636,3,600000,0,0,0,8,0,0,0,-362.385162,-609.420288,2.467764,2.788083,"Risen Drakkari Warrior - On Waypoint 9 Reached - Summon Creature 'Risen Drakkari Soulmage'"),
(@ENTRY,0,7,0,61,0,100,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 1 - Say Line 0"),
(@ENTRY,0,8,0,61,0,100,0,1,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 2 - Say Line 1");

DELETE FROM `waypoints` WHERE `entry`=2663500;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2663500, 1, -358.149, -591.396, 4.8929, 'Risen Drakkari Warrior'),
(2663500, 2, -355.111, -588.661, 7.43521, 'Risen Drakkari Warrior'),
(2663500, 3, -351.322, -585.026, 10.995, 'Risen Drakkari Warrior'),
(2663500, 4, -345.376, -579.253, 11.012, 'Risen Drakkari Warrior'),
(2663500, 5, -343.792, -579.642, 11.012, 'Risen Drakkari Warrior'),
(2663500, 6, -346.169, -582.965, 11.012, 'Risen Drakkari Warrior'),
(2663500, 7, -350.619, -586.543, 10.6995, 'Risen Drakkari Warrior'),
(2663500, 8, -356.449, -591.583, 5.55874, 'Risen Drakkari Warrior'),
(2663500, 9, -363.399, -595.822, 2.26113, 'Risen Drakkari Warrior');

DELETE FROM `waypoints` WHERE `entry`=2663501;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2663501, 1, -361.498, -611.317, 2.82481, 'Risen Drakkari Warrior'),
(2663501, 2, -358.749, -613.483, 4.91993, 'Risen Drakkari Warrior'),
(2663501, 3, -351.531, -619.59, 11.0096, 'Risen Drakkari Warrior'),
(2663501, 4, -349.112, -623.42, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 5, -347.686, -624.43, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 6, -346.433, -620.963, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 7, -350.655, -617.858, 10.8491, 'Risen Drakkari Warrior'),
(2663501, 8, -356.367, -613.813, 6.09785, 'Risen Drakkari Warrior'),
(2663501, 9, -366.529, -607.86, 2.26056, 'Risen Drakkari Warrior');

DELETE FROM `creature_text` WHERE `entry`=26635;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26635, 0, 0, 'Help mon! There''s too many of dem!', 14, 0, 100, 0, 0, 0, 26538, 0, 'Risen Drakkari Warrior'),
(26635, 1, 0, 'Backup! We need backup!', 14, 0, 100, 0, 0, 0, 26537, 0, 'Risen Drakkari Warrior');
--
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid` IN (26626, 26637) AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (26636 ,26625);
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `guid`=127430; /*31261 */

UPDATE `creature_addon` SET `auras`='31261 49852' WHERE  `guid` IN (127571, 127569, 127568, 127583, 127567, 127570, 127584);

DELETE FROM `creature_template_addon` WHERE `entry`=26621;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(26621, 0, 0, 0, 1, 418, '');


-- Pathing for  Entry: 26624 'TDB FORMAT' 
SET @NPC := 127403;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-321.1793,`position_y`=-660.2445,`position_z`=10.63094 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-321.1793,-660.2445,10.63094,0,0,0,0,100,0),
(@PATH,2,-314.265,-658.299,10.85989,0,0,0,0,100,0),
(@PATH,3,-308.3121,-663.0262,10.8531,0,0,0,0,100,0),
(@PATH,4,-312.3275,-667.5159,10.43025,0,0,0,0,100,0),
(@PATH,5,-323.8721,-672.2502,11.15234,0,0,0,0,100,0),
(@PATH,6,-325.2265,-672.576,11.07057,0,0,0,0,100,0),
(@PATH,7,-324.1945,-665.3568,10.65234,0,0,0,0,100,0),
(@PATH,8,-321.2054,-660.1317,10.51689,0,0,0,0,100,0),
(@PATH,9,-314.2662,-658.2737,10.85989,0,0,0,0,100,0),
(@PATH,10,-308.2971,-663.0308,10.85604,0,0,0,0,100,0),
(@PATH,11,-312.3167,-667.5278,10.43211,0,0,0,0,100,0),
(@PATH,12,-323.8912,-672.2682,11.15234,0,0,0,0,100,0),
(@PATH,13,-325.2353,-672.5774,11.0714,0,0,0,0,100,0),
(@PATH,14,-324.1946,-665.3556,10.65234,0,0,0,0,100,0),
(@PATH,15,-321.2102,-660.1342,10.51981,0,0,0,0,100,0),
(@PATH,16,-314.2662,-658.2732,10.85989,0,0,0,0,100,0),
(@PATH,17,-308.2755,-663.0374,10.86023,0,0,0,0,100,0),
(@PATH,18,-312.2948,-667.5519,10.43588,0,0,0,0,100,0),
(@PATH,19,-323.9076,-672.2837,11.15234,0,0,0,0,100,0),
(@PATH,20,-325.265,-672.582,11.07419,0,0,0,0,100,0);
-- 0x1C16DC4B001A0000005B0C0000578386 .go -321.1793 -660.2445 10.63094

-- Pathing for  Entry: 26624 'TDB FORMAT' 
SET @NPC := 127404;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-318.1556,`position_y`=-640.515,`position_z`=11.95144 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-318.1556,-640.515,11.95144,0,0,0,0,100,0),
(@PATH,2,-311.1296,-643.6861,11.3687,0,0,0,0,100,0),
(@PATH,3,-306.9548,-646.1841,10.92374,0,0,0,0,100,0),
(@PATH,4,-300.4054,-650.3721,11.09798,0,0,0,0,100,0),
(@PATH,5,-298.4008,-658.082,10.63272,0,0,0,0,100,0),
(@PATH,6,-298.8151,-659.7013,10.62173,0,0,0,0,100,0),
(@PATH,7,-310.1207,-661.3427,10.63743,0,0,0,0,100,0),
(@PATH,8,-314.2844,-659.1246,10.57358,0,0,0,0,100,0),
(@PATH,9,-316.9409,-657.6439,10.68161,0,0,0,0,100,0),
(@PATH,10,-325.1304,-655.4464,10.74956,0,0,0,0,100,0),
(@PATH,11,-329.8129,-650.3148,12.10803,0,0,0,0,100,0),
(@PATH,12,-329.9256,-647.5079,12.01005,0,0,0,0,100,0),
(@PATH,13,-328.6924,-642.873,12.058,0,0,0,0,100,0);
-- 0x1C16DC4B001A0000005B0C0000D78386 .go -318.1556 -640.515 11.95144

-- Pathing for  Entry: 26637 'TDB FORMAT' 
SET @NPC := 127444;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-466.2595,`position_y`=-652.3038,`position_z`=28.78722 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6469,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-466.2595,-652.3038,28.78722,0,0,0,0,100,0),
(@PATH,2,-478.2595,-652.0538,28.78722,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=127444;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127444, 127444, 0, 0, 2, 0, 0),
(127444, 127456, 4, 90, 2, 0, 0),
(127444, 127457, 4, 270, 2, 0, 0);

-- Pathing for  Entry: 26637 'TDB FORMAT' 
SET @NPC := 127442;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-499.8308,`position_y`=-705.9434,`position_z`=30.6214 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6469,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-499.8308,-705.9434,30.6214,0,0,0,0,100,0),
(@PATH,2,-502.4009,-683.0112,30.58796,0,0,0,0,100,0),
(@PATH,3,-502.3382,-683.26,30.3714,0,0,0,0,100,0),
(@PATH,4,-502.022,-683.1946,30.61549,0,0,0,0,100,0),
(@PATH,5,-499.6927,-706.1716,30.6214,0,0,0,0,100,0),
(@PATH,6,-496.0414,-714.49,30.6214,0,0,0,0,100,0),
(@PATH,7,-496.3022,-714.5132,30.3714,0,0,0,0,100,0),
(@PATH,8,-496.2182,-714.349,30.6214,0,0,0,0,100,0),
(@PATH,9,-499.8963,-705.8741,30.6214,0,0,0,0,100,0);
-- 0x1C16DC4B001A0340005B0C0000578386 .go -499.8308 -705.9434 30.6214

DELETE FROM `creature_formations` WHERE `leaderGUID`=127442;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127442, 127442, 0, 0, 2, 0, 0),
(127442, 127443, 4, 90, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (127617, 127589, 127438, 127590, 127428, 127427, 127580, 127579, 127432, 127578, 127433);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127427, 0, 0, 0, 1, 36, ''),
(127428, 0, 0, 0, 1, 36, ''),
(127432, 0, 0, 0, 1, 36, ''),
(127433, 0, 0, 0, 1, 36, ''),
(127578, 0, 0, 0, 1, 36, ''),
(127579, 0, 0, 0, 1, 36, ''),
(127580, 0, 0, 0, 1, 36, ''),
(127589, 0, 0, 0, 1, 36, ''),
(127590, 0, 0, 0, 1, 36, ''),
(127617, 0, 0, 0, 1, 36, '');

-- Pathing for  Entry: 26637 'TDB FORMAT'   
SET @NPC := 127446;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-458.184,`position_y`=-595.712,`position_z`=93.7567 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,26751,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -431.004, -599.244, 96.6243, 0, 0, 1, 0, 100, 0),
(@PATH, 2, -397.542, -607.933, 89.8221, 0, 0, 1, 0, 100, 0),
(@PATH, 3, -380.795, -608.944, 84.5094, 0, 0, 1, 0, 100, 0),
(@PATH, 4, -366.926, -609.622, 86.2929, 0, 0, 1, 0, 100, 0),
(@PATH, 5, -335.819, -610.248, 92.769, 0, 0, 1, 0, 100, 0),
(@PATH, 6, -324.31, -610.248, 94.3711, 0, 0, 1, 0, 100, 0),
(@PATH, 7, -313.428, -610.467, 95.2595, 0, 0, 1, 0, 100, 0),
(@PATH, 8, -331.964, -610.102, 92.3899, 0, 0, 1, 0, 100, 0),
(@PATH, 9, -343.592, -609.99, 90.6398, 0, 0, 1, 0, 100, 0),
(@PATH, 10, -367.122, -609.527, 87.0978, 0, 0, 1, 0, 100, 0),
(@PATH, 11, -381.21, -609.16, 84.9903, 0, 0, 1, 0, 100, 0),
(@PATH, 12, -399.507, -608.891, 89.1199, 0, 0, 1, 0, 100, 0),
(@PATH, 13, -428.922, -609.198, 91.8185, 0, 0, 1, 0, 100, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry` IN (26638, 31351);

-- Pathing for  Entry: 29237 'TDB FORMAT' 
SET @NPC := 203549;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6709.566,`position_y`=-4355.494,`position_z`=440.7194 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6709.566,-4355.494,440.7194,0,0,0,0,100,0),
(@PATH,2,6711.722,-4357.65,440.7194,0,0,0,0,100,0),
(@PATH,3,6713.885,-4359.814,440.7194,0,0,0,0,100,0),
(@PATH,4,6716.069,-4361.999,440.7194,0,0,0,0,100,0),
(@PATH,5,6718.223,-4364.154,440.7194,0,0,0,0,100,0),
(@PATH,6,6720.4,-4366.332,440.7194,0,0,0,0,100,0),
(@PATH,7,6722.556,-4368.488,440.7025,0,0,0,0,100,0),
(@PATH,8,6724.659,-4370.592,440.7025,0,0,0,0,100,0),
(@PATH,9,6726.705,-4372.757,440.7025,0,0,0,0,100,0),
(@PATH,10,6728.782,-4374.959,440.7025,0,0,0,0,100,0),
(@PATH,11,6730.868,-4377.171,440.7025,0,0,0,0,100,0),
(@PATH,12,6732.948,-4379.376,440.7025,0,0,0,0,100,0),
(@PATH,13,6735.021,-4381.573,440.6158,0,0,0,0,100,0),
(@PATH,14,6737.099,-4383.777,440.6158,0,0,0,0,100,0),
(@PATH,15,6738.558,-4385.286,440.6158,0,0,0,0,100,0),
(@PATH,16,6740.794,-4387.498,440.6158,0,0,0,0,100,0),
(@PATH,17,6743.027,-4389.707,440.6158,0,0,0,0,100,0),
(@PATH,18,6745.267,-4391.922,440.6158,0,0,0,0,100,0),
(@PATH,19,6747.505,-4394.136,440.6158,0,0,0,0,100,0),
(@PATH,20,6749.747,-4396.354,440.6158,0,0,0,0,100,0),
(@PATH,21,6752.003,-4398.586,440.6158,0,0,0,0,100,0),
(@PATH,22,6754.265,-4400.824,440.6158,0,0,0,0,100,0),
(@PATH,23,6756.507,-4403.042,440.6158,0,0,0,0,100,0),
(@PATH,24,6758.502,-4405.03,440.6158,0,0,0,0,100,0),
(@PATH,25,6760.651,-4407.223,440.6158,0,0,0,0,100,0),
(@PATH,26,6762.793,-4409.409,440.6158,0,0,0,0,100,0),
(@PATH,27,6764.924,-4411.583,440.6158,0,0,0,0,100,0),
(@PATH,28,6767.083,-4413.788,440.7194,0,0,0,0,100,0),
(@PATH,29,6769.217,-4415.966,440.7194,0,0,0,0,100,0),
(@PATH,30,6771.352,-4418.145,440.7194,0,0,0,0,100,0),
(@PATH,31,6773.472,-4420.309,440.7194,0,0,0,0,100,0),
(@PATH,32,6775.598,-4422.479,440.7194,0,0,0,0,100,0),
(@PATH,33,6776.916,-4423.868,440.7194,0,0,0,0,100,0),
(@PATH,34,6779.079,-4426.187,440.7194,0,0,0,0,100,0),
(@PATH,35,6781.248,-4428.51,440.7194,0,0,0,0,100,0),
(@PATH,36,6783.421,-4430.838,440.7194,0,0,0,0,100,0),
(@PATH,37,6785.586,-4433.158,440.7194,0,0,0,0,100,0),
(@PATH,38,6787.766,-4435.493,440.7009,0,0,0,0,100,0),
(@PATH,39,6789.926,-4437.807,440.7009,0,0,0,0,100,0),
(@PATH,40,6791.934,-4439.958,440.7009,0,0,0,0,100,0),
(@PATH,41,6794.533,-4442.054,440.7009,0,0,0,0,100,0),
(@PATH,42,6796.933,-4443.941,440.7009,0,0,0,0,100,0),
(@PATH,43,6799.326,-4445.824,440.7009,0,0,0,0,100,0),
(@PATH,44,6801.72,-4447.708,440.7194,0,0,0,0,100,0),
(@PATH,45,6804.107,-4449.586,440.7194,0,0,0,0,100,0),
(@PATH,46,6805.872,-4450.974,440.7194,0,0,0,0,100,0),
(@PATH,47,6805.872,-4450.974,440.7194,0,0,0,0,100,0),
(@PATH,48,6802.628,-4448.422,440.7194,0,0,0,0,100,0),
(@PATH,49,6801.03,-4447.165,440.7194,0,0,0,0,100,0),
(@PATH,50,6798.649,-4445.292,440.7009,0,0,0,0,100,0),
(@PATH,51,6796.252,-4443.406,440.7009,0,0,0,0,100,0),
(@PATH,52,6793.855,-4441.521,440.7009,0,0,0,0,100,0),
(@PATH,53,6791.484,-4439.477,440.7009,0,0,0,0,100,0),
(@PATH,54,6789.404,-4437.248,440.7009,0,0,0,0,100,0),
(@PATH,55,6787.313,-4435.008,440.7009,0,0,0,0,100,0),
(@PATH,56,6785.237,-4432.784,440.7194,0,0,0,0,100,0),
(@PATH,57,6783.164,-4430.563,440.7194,0,0,0,0,100,0),
(@PATH,58,6781.085,-4428.335,440.7194,0,0,0,0,100,0),
(@PATH,59,6778.998,-4426.099,440.7194,0,0,0,0,100,0),
(@PATH,60,6776.91,-4423.862,440.7194,0,0,0,0,100,0),
(@PATH,61,6775.327,-4422.202,440.7194,0,0,0,0,100,0),
(@PATH,62,6773.147,-4419.977,440.7194,0,0,0,0,100,0),
(@PATH,63,6770.978,-4417.763,440.7194,0,0,0,0,100,0),
(@PATH,64,6768.798,-4415.538,440.7194,0,0,0,0,100,0),
(@PATH,65,6766.607,-4413.302,440.6158,0,0,0,0,100,0),
(@PATH,66,6764.424,-4411.074,440.6158,0,0,0,0,100,0),
(@PATH,67,6762.253,-4408.858,440.6158,0,0,0,0,100,0),
(@PATH,68,6760.07,-4406.629,440.6158,0,0,0,0,100,0),
(@PATH,69,6757.998,-4404.517,440.6158,0,0,0,0,100,0),
(@PATH,70,6755.836,-4402.378,440.6158,0,0,0,0,100,0),
(@PATH,71,6753.682,-4400.247,440.6158,0,0,0,0,100,0),
(@PATH,72,6751.511,-4398.099,440.6158,0,0,0,0,100,0),
(@PATH,73,6749.368,-4395.979,440.6158,0,0,0,0,100,0),
(@PATH,74,6747.188,-4393.823,440.6158,0,0,0,0,100,0),
(@PATH,75,6745.053,-4391.711,440.6158,0,0,0,0,100,0),
(@PATH,76,6742.909,-4389.59,440.6158,0,0,0,0,100,0),
(@PATH,77,6740.754,-4387.458,440.6158,0,0,0,0,100,0),
(@PATH,78,6738.592,-4385.319,440.6158,0,0,0,0,100,0),
(@PATH,79,6736.751,-4383.408,440.6158,0,0,0,0,100,0),
(@PATH,80,6734.615,-4381.143,440.6158,0,0,0,0,100,0),
(@PATH,81,6732.473,-4378.873,440.7025,0,0,0,0,100,0),
(@PATH,82,6730.346,-4376.617,440.7025,0,0,0,0,100,0),
(@PATH,83,6728.218,-4374.362,440.7025,0,0,0,0,100,0),
(@PATH,84,6729.046,-4370.898,440.9525,0,0,0,0,100,0),
(@PATH,85,6724.064,-4369.998,440.7025,0,0,0,0,100,0),
(@PATH,86,6721.935,-4367.867,440.7025,0,0,0,0,100,0),
(@PATH,87,6719.804,-4365.736,440.7194,0,0,0,0,100,0),
(@PATH,88,6717.628,-4363.559,440.7194,0,0,0,0,100,0),
(@PATH,89,6715.489,-4361.419,440.7194,0,0,0,0,100,0),
(@PATH,90,6713.351,-4359.279,440.7194,0,0,0,0,100,0),
(@PATH,91,6711.217,-4357.145,440.7194,0,0,0,0,100,0),
(@PATH,92,6709.114,-4355.041,440.7194,0,0,0,0,100,0),
(@PATH,93,6706.909,-4353.476,440.7194,0,0,0,0,100,0),
(@PATH,94,6704.445,-4351.718,440.7194,0,0,0,0,100,0),
(@PATH,95,6701.982,-4349.961,440.7194,0,0,0,0,100,0),
(@PATH,96,6699.487,-4348.182,440.7194,0,0,0,0,100,0),
(@PATH,97,6697.032,-4346.43,440.7194,0,0,0,0,100,0),
(@PATH,98,6696.491,-4345.139,440.7194,0,0,0,0,100,0),
(@PATH,99,6693.5,-4346.004,440.7194,0,0,0,0,100,0),
(@PATH,100,6690.534,-4346.862,440.7194,0,0,0,0,100,0),
(@PATH,101,6687.572,-4347.719,440.7582,0,0,0,0,100,0),
(@PATH,102,6684.732,-4348.541,440.7194,0,0,0,0,100,0),
(@PATH,103,6683.093,-4349.978,440.7194,0,0,0,0,100,0),
(@PATH,104,6680.785,-4351.966,440.7194,0,0,0,0,100,0),
(@PATH,105,6678.49,-4353.942,440.7194,0,0,0,0,100,0),
(@PATH,106,6676.195,-4355.919,440.7194,0,0,0,0,100,0),
(@PATH,107,6673.887,-4357.907,440.7194,0,0,0,0,100,0),
(@PATH,108,6672.325,-4359.7,440.7194,0,0,0,0,100,0),
(@PATH,109,6670.341,-4362.154,440.7194,0,0,0,0,100,0),
(@PATH,110,6668.408,-4364.545,440.7194,0,0,0,0,100,0),
(@PATH,111,6666.455,-4366.962,440.8546,0,0,0,0,100,0),
(@PATH,112,6664.507,-4369.371,440.9098,0,0,0,0,100,0),
(@PATH,113,6663.903,-4370.801,441.0089,0,0,0,0,100,0),
(@PATH,114,6663.605,-4373.883,440.7194,0,0,0,0,100,0),
(@PATH,115,6663.312,-4376.927,440.7194,0,0,0,0,100,0),
(@PATH,116,6663.017,-4379.976,440.7194,0,0,0,0,100,0),
(@PATH,117,6663.048,-4380.506,440.7194,0,0,0,0,100,0),
(@PATH,118,6665.024,-4382.971,440.7194,0,0,0,0,100,0),
(@PATH,119,6667.013,-4385.452,440.7194,0,0,0,0,100,0),
(@PATH,120,6669.01,-4387.943,440.7194,0,0,0,0,100,0),
(@PATH,121,6670.983,-4390.403,440.7194,0,0,0,0,100,0),
(@PATH,122,6672.976,-4392.888,440.7194,0,0,0,0,100,0),
(@PATH,123,6674.643,-4394.981,440.7194,0,0,0,0,100,0),
(@PATH,124,6676.801,-4397.127,440.7194,0,0,0,0,100,0),
(@PATH,125,6678.959,-4399.274,440.7194,0,0,0,0,100,0),
(@PATH,126,6681.114,-4401.417,440.7194,0,0,0,0,100,0),
(@PATH,127,6683.27,-4403.563,440.7194,0,0,0,0,100,0),
(@PATH,128,6685.439,-4405.72,440.7194,0,0,0,0,100,0),
(@PATH,129,6687.588,-4407.858,440.7194,0,0,0,0,100,0),
(@PATH,130,6689.752,-4410.01,440.7194,0,0,0,0,100,0),
(@PATH,131,6691.524,-4411.785,440.7194,0,0,0,0,100,0),
(@PATH,132,6693.658,-4414.005,440.7194,0,0,0,0,100,0),
(@PATH,133,6695.81,-4416.244,440.7194,0,0,0,0,100,0),
(@PATH,134,6697.947,-4418.468,440.7194,0,0,0,0,100,0),
(@PATH,135,6700.072,-4420.679,440.6158,0,0,0,0,100,0),
(@PATH,136,6702.215,-4422.909,440.6158,0,0,0,0,100,0),
(@PATH,137,6704.354,-4425.135,440.6158,0,0,0,0,100,0),
(@PATH,138,6706.516,-4427.385,440.6158,0,0,0,0,100,0),
(@PATH,139,6708.664,-4429.62,440.6158,0,0,0,0,100,0),
(@PATH,140,6710.82,-4431.864,440.6158,0,0,0,0,100,0),
(@PATH,141,6713.229,-4433.922,440.7194,0,0,0,0,100,0),
(@PATH,142,6715.676,-4436.133,440.7194,0,0,0,0,100,0),
(@PATH,143,6718.125,-4438.346,440.7194,0,0,0,0,100,0),
(@PATH,144,6720.556,-4440.542,440.7194,0,0,0,0,100,0),
(@PATH,145,6722.997,-4442.747,440.7194,0,0,0,0,100,0),
(@PATH,146,6725.418,-4444.934,440.7194,0,0,0,0,100,0),
(@PATH,147,6727.87,-4447.148,440.7194,0,0,0,0,100,0),
(@PATH,148,6730.146,-4449.292,440.7194,0,0,0,0,100,0),
(@PATH,149,6730.788,-4452.639,440.7194,0,0,0,0,100,0),
(@PATH,150,6731.166,-4454.971,440.7194,0,0,0,0,100,0),
(@PATH,151,6731.166,-4457.63,440.7194,0,0,0,0,100,0),
(@PATH,152,6732.197,-4457.931,440.7194,0,0,0,0,100,0),
(@PATH,153,6734.809,-4459.646,440.7194,0,0,0,0,100,0),
(@PATH,154,6737.403,-4461.349,440.7194,0,0,0,0,100,0),
(@PATH,155,6740.015,-4463.064,440.7194,0,0,0,0,100,0),
(@PATH,156,6742.618,-4464.773,440.7194,0,0,0,0,100,0),
(@PATH,157,6745.232,-4466.489,440.7194,0,0,0,0,100,0),
(@PATH,158,6747.178,-4467.969,440.7194,0,0,0,0,100,0),
(@PATH,159,6749.505,-4470.075,440.7194,0,0,0,0,100,0),
(@PATH,160,6751.848,-4472.194,440.7194,0,0,0,0,100,0),
(@PATH,161,6754.179,-4474.303,440.7194,0,0,0,0,100,0),
(@PATH,162,6756.502,-4476.405,440.7194,0,0,0,0,100,0),
(@PATH,163,6758.849,-4478.528,440.7194,0,0,0,0,100,0),
(@PATH,164,6761.196,-4480.651,440.7194,0,0,0,0,100,0),
(@PATH,165,6763.529,-4482.762,440.7194,0,0,0,0,100,0),
(@PATH,166,6765.672,-4484.701,440.7194,0,0,0,0,100,0),
(@PATH,167,6765.672,-4484.701,440.7194,0,0,0,0,100,0),
(@PATH,168,6762.613,-4481.934,440.7194,0,0,0,0,100,0),
(@PATH,169,6761.11,-4480.573,440.7194,0,0,0,0,100,0),
(@PATH,170,6758.854,-4478.532,440.7194,0,0,0,0,100,0),
(@PATH,171,6756.6,-4476.493,440.7194,0,0,0,0,100,0),
(@PATH,172,6754.358,-4474.465,440.7194,0,0,0,0,100,0),
(@PATH,173,6752.123,-4472.442,440.7194,0,0,0,0,100,0),
(@PATH,174,6749.883,-4470.417,440.7194,0,0,0,0,100,0),
(@PATH,175,6747.618,-4468.367,440.7194,0,0,0,0,100,0),
(@PATH,176,6747.454,-4468.149,440.7194,0,0,0,0,100,0),
(@PATH,177,6745.778,-4463.783,440.7194,0,0,0,0,100,0),
(@PATH,178,6743.626,-4461.631,440.7194,0,0,0,0,100,0),
(@PATH,179,6741.465,-4459.471,440.7194,0,0,0,0,100,0),
(@PATH,180,6739.305,-4457.311,440.7194,0,0,0,0,100,0),
(@PATH,181,6737.125,-4455.129,440.7194,0,0,0,0,100,0),
(@PATH,182,6734.964,-4452.969,440.7194,0,0,0,0,100,0),
(@PATH,183,6731.37,-4451.403,440.7194,0,0,0,0,100,0);
-- 0x1C091047601C8D4000000B0000572225 .go 6709.566 -4355.494 440.7194

DELETE FROM `creature_formations` WHERE `leaderGUID`=203549;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(203549, 203549, 0, 0, 2, 0, 0),
(203549, 203562, 3, 270, 2, 0, 0);
-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126942; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269420, 1, 1336.35, 97.1842, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 2, 1337.76, 97.2226, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 3, 1339.43, 101.827, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 4, 1337.51, 102.338, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 5, 1337.45, 101.881, 40.1805, 0, 4000, 0, 0, 100, 0),
(1269420, 6, 1327.41, 101.553, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 7, 1327.35, 100.975, 40.1805, 0, 4000, 0, 0, 100, 0),
(1269420, 8, 1325.64, 100.623, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 9, 1325.01, 96.4632, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 10, 1327.11, 96.4808, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 11, 1327.07, 96.8291, 40.1805, 0, 4000, 0, 0, 100, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (28582, 30974);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(28582, 0, 0, 0, 0, 69, ''),
(30974, 0, 0, 0, 0, 69, '');

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126926; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269260, 1, 1377.28, 64.533, 48.8931, 0, 0, 0, 0, 100, 0),
(1269260, 2, 1377.69, 64.9436, 48.8931, 0, 6000, 0, 0, 100, 0),
(1269260, 3, 1359.25, 81.9585, 41.0455, 0, 0, 0, 0, 100, 0),
(1269260, 4, 1359.68, 82.5069, 41.0204, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126915; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269150, 1, 1393.45, 47.8648, 50.0383, 0, 6000, 0, 0, 100, 0),
(1269150, 2, 1401.61, 46.3271, 50.0383, 0, 0, 0, 0, 100, 0),
(1269150, 3, 1401.81, 45.7834, 50.0383, 0, 6000, 0, 0, 100, 0),
(1269150, 4, 1394.37, 48.5111, 50.0383, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126925; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269250, 1, 1414.64, 32.7402, 50.2271, 0, 0, 0, 0, 100, 0),
(1269250, 2, 1419.4, 32.7552, 53.1143, 0, 0, 0, 0, 100, 0),
(1269250, 3, 1429.45, 32.845, 58.7644, 0, 0, 0, 0, 100, 0),
(1269250, 4, 1433.53, 32.8176, 58.7671, 0, 0, 0, 0, 100, 0),
(1269250, 5, 1434.02, 32.0269, 58.7671, 0, 6000, 0, 0, 100, 0),
(1269250, 6, 1430.18, 32.2594, 58.7671, 0, 0, 0, 0, 100, 0),
(1269250, 7, 1422.24, 32.287, 54.8356, 0, 0, 0, 0, 100, 0),
(1269250, 8, 1414.43, 32.6758, 50.0945, 0, 0, 0, 0, 100, 0),
(1269250, 9, 1407.78, 32.7916, 50.0383, 0, 0, 0, 0, 100, 0),
(1269250, 10, 1406.76, 32.718, 50.0383, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126924; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269240, 1, 1358.66, -8.12641, 41.1612, 0, 0, 0, 0, 100, 0),
(1269240, 2, 1359.22, -8.72624, 41.1518, 0, 6000, 0, 0, 100, 0),
(1269240, 3, 1376.27, 9.68446, 48.9541, 0, 0, 0, 0, 100, 0),
(1269240, 4, 1376.68, 9.25245, 48.95, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126933; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269330, 1, 1353.19, 3.42894, 42.4993, 0, 0, 0, 0, 100, 0),
(1269330, 2, 1352.77, 3.83879, 42.4978, 0, 6000, 0, 0, 100, 0),
(1269330, 3, 1368.11, 18.3238, 49.0597, 0, 0, 0, 0, 100, 0),
(1269330, 4, 1367.63, 18.8363, 49.0662, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126939; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269390, 1, 1324.11, -36.4178, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 2, 1320.59, -33.3142, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 3, 1322.34, -31.4373, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 4, 1323.13, -32.1258, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 5, 1321.68, -35.1774, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 6, 1324.78, -37.6497, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 7, 1340.48, -36.3091, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 8, 1341.82, -34.5498, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 9, 1342.51, -31.7143, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 10, 1343.71, -26.8389, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 11, 1343.06, -26.1627, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 12, 1341.99, -31.7877, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 13, 1341.6, -32.2199, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 14, 1341.2, -36.4011, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 15, 1325.72, -38.8983, 40.1806, 0, 0, 0, 0, 100, 0);


-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126941; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269410, 1, 1267.08, -35.0841, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 2, 1253.98, -31.204, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 3, 1252.76, -28.9487, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 4, 1255.2, -33.8478, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 5, 1256.82, -34.5311, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 6, 1256.49, -38.1348, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 7, 1259.85, -39.4856, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 8, 1264.16, -36.9788, 33.5057, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126917; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269170, 1, 1268.62, 32.3739, 33.5057, 0, 0, 0, 0, 100, 0),
(1269170, 2, 1270.03, 32.3423, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269170, 3, 1269.46, 0.489199, 33.5057, 0, 0, 0, 0, 100, 0),
(1269170, 4, 1269.81, 0.525176, 33.5057, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126940; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269400, 1, 1269.07, 39.2463, 33.5055, 0, 0, 0, 0, 100, 0),
(1269400, 2, 1269.94, 39.279, 33.5055, 0, 6000, 0, 0, 100, 0),
(1269400, 3, 1269, 68.7823, 33.5055, 0, 0, 0, 0, 100, 0),
(1269400, 4, 1269.8, 68.7924, 33.5055, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126919; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269190, 1, 1254.43, 38.9632, 33.5056, 0, 0, 0, 0, 100, 0),
(1269190, 2, 1254.33, 32.6571, 35.0186, 0, 0, 0, 0, 100, 0),
(1269190, 3, 1254.73, 9.53858, 33.5056, 0, 0, 0, 0, 100, 0),
(1269190, 4, 1254.26, 9.55597, 33.5056, 0, 6000, 0, 0, 100, 0),
(1269190, 5, 1254.61, 28.5055, 33.8212, 0, 0, 0, 0, 100, 0),
(1269190, 6, 1254.59, 33.0582, 35.0141, 0, 0, 0, 0, 100, 0),
(1269190, 7, 1254.56, 55.7588, 33.5058, 0, 0, 0, 0, 100, 0),
(1269190, 8, 1254.14, 55.7403, 33.5058, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126918; 
SET @PATH := 1269180;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269180, 1, 1252.42, 106.457, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 2, 1249.45, 101.782, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 3, 1250.39, 100.591, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 4, 1251.37, 101.803, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 5, 1250.43, 104.446, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 6, 1259.91, 113.097, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 7, 1265.25, 112.968, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 8, 1273.82, 106.516, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 9, 1274.95, 101.531, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 10, 1272.59, 100.018, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 11, 1272.4, 100.808, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 12, 1275.02, 103.29, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 13, 1273.92, 106.241, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 14, 1267.23, 108.337, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 15, 1264.99, 108.96, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 16, 1263.4, 112.342, 33.5057, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id`=28585;
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (28825, 28547, 28584, 28583);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 126954;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1311.234,`position_y`=-158.9818,`position_z`=52.27496 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1311.234,-158.9818,52.27496,0,0,0,0,100,0),
(@PATH,2,1312.317,-174.7872,52.27221,0,0,0,0,100,0),
(@PATH,3,1328.705,-186.7419,52.27302,0,0,0,0,100,0),
(@PATH,4,1341.044,-184.8856,52.27322,0,0,0,0,100,0),
(@PATH,5,1354.387,-173.1809,52.27328,0,0,0,0,100,0),
(@PATH,6,1354.742,-169.7169,52.27325,0,0,0,0,100,0),
(@PATH,7,1348.927,-148.5091,52.27411,0,0,0,0,100,0),
(@PATH,8,1335.543,-142.5214,52.27379,0,0,0,0,100,0),
(@PATH,9,1318.144,-146.4185,52.31124,0,0,0,0,100,0),
(@PATH,10,1311.167,-158.8409,52.27437,0,0,0,0,100,0);
-- 0x1C307C4B401BE9C000021700025672BB .go 1311.234 -158.9818 52.27496

DELETE FROM `creature_formations` WHERE `leaderGUID`=126954;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126954, 126954, 0, 0, 2, 0, 0),
(126954, 126955, 3, 0, 2, 0, 0);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 76296;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(762960, 1, 1176.14, -298.09, 52.3436, 0, 0, 0, 0, 100, 0),
(762960, 2, 1176.3, -246.576, 52.3528, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 76297;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(762970, 1, 1180.57, -315.473, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 2, 1171.95, -315.333, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 3, 1171.02, -327.394, 52.6927, 0, 0, 0, 0, 100, 0),
(762970, 4, 1183.75, -330.38, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 5, 1183.62, -317.868, 52.3378, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `guid`=76298;
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=28547 AND `source_type`=0 AND `id`=0 AND `link`=0;

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 126874;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(1268740, 1, 1118.22, -248.207, 56.8882, 0, 0, 1, 0, 100, 0),
(1268740, 2, 1118.62, -274.988, 56.8831, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');

DELETE FROM `creature_addon` WHERE `guid` IN (126904, 126921, 126903, 126911, 126928, 126929, 126930, 126931, 126912);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(126911, 0, 0, 0, 1, 69, ''),
(126928, 0, 0, 0, 1, 69, ''),
(126929, 0, 0, 0, 1, 69, ''),
(126930, 0, 0, 0, 1, 69, ''),
(126931, 0, 0, 0, 1, 69, ''),
(126912, 0, 0, 0, 1, 69, ''),
(126903, 0, 0, 0, 1, 69, ''),
(126921, 0, 0, 0, 1, 69, ''),
(126904, 0, 0, 0, 1, 69, '');


UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=28838 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Pathing for  Entry: 28838 'TDB FORMAT' 
SET @NPC := 126938;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1096.845,`position_y`=-166.1139,`position_z`=58.68692 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1096.845,-166.1139,58.68692,0,0,0,0,100,0),
(@PATH,2,1091.599,-152.8187,61.33255,0,0,0,0,100,0),
(@PATH,3,1076.235,-141.8798,61.18824,0,0,0,0,100,0),
(@PATH,4,1060.763,-145.9723,61.39173,0,0,0,0,100,0),
(@PATH,5,1049.471,-171.0271,58.53773,0,0,0,0,100,0),
(@PATH,6,1055.509,-189.0143,58.94555,0,0,0,0,100,0),
(@PATH,7,1073.278,-198.3343,59.91864,0,0,0,0,100,0),
(@PATH,8,1091.632,-153.0076,61.24912,0,0,0,0,100,0),
(@PATH,9,1076.185,-141.7971,61.18842,0,0,0,0,100,0),
(@PATH,10,1060.682,-145.9083,61.35257,0,0,0,0,100,0),
(@PATH,11,1049.497,-171.1528,58.5324,0,0,0,0,100,0),
(@PATH,12,1055.636,-188.8313,58.83115,0,0,0,0,100,0),
(@PATH,13,1073.335,-198.4241,59.88276,0,0,0,0,100,0),
(@PATH,14,1083.434,-195.9087,59.84556,0,0,0,0,100,0),
(@PATH,15,1095.76,-180.6208,58.73315,0,0,0,0,100,0),
(@PATH,16,1096.683,-166.0892,58.71755,0,0,0,0,100,0),
(@PATH,17,1091.595,-152.9597,61.3679,0,0,0,0,100,0),
(@PATH,18,1076.179,-141.7626,61.18819,0,0,0,0,100,0),
(@PATH,19,1060.637,-145.9161,61.39425,0,0,0,0,100,0),
(@PATH,20,1049.585,-171.0794,58.53699,0,0,0,0,100,0),
(@PATH,21,1055.467,-188.91,58.98404,0,0,0,0,100,0),
(@PATH,22,1073.328,-198.439,59.93514,0,0,0,0,100,0),
(@PATH,23,1083.423,-195.8686,59.93195,0,0,0,0,100,0),
(@PATH,24,1095.775,-180.6299,58.52916,0,0,0,0,100,0),
(@PATH,25,1096.451,-166.0939,58.80622,0,0,0,0,100,0),
(@PATH,26,1091.409,-152.9162,61.46411,0,0,0,0,100,0),
(@PATH,27,1076.1,-141.8916,61.18857,0,0,0,0,100,0),
(@PATH,28,1060.651,-145.9504,61.40473,0,0,0,0,100,0),
(@PATH,29,1049.581,-171.0241,58.53423,0,0,0,0,100,0),
(@PATH,30,1055.498,-188.95,59.02743,0,0,0,0,100,0),
(@PATH,31,1073.29,-198.3899,60.07246,0,0,0,0,100,0),
(@PATH,32,1083.527,-195.7341,59.79642,0,0,0,0,100,0),
(@PATH,33,1095.63,-180.5483,58.69926,0,0,0,0,100,0),
(@PATH,34,1096.488,-165.9498,58.67723,0,0,0,0,100,0),
(@PATH,35,1091.622,-152.8619,61.2616,0,0,0,0,100,0),
(@PATH,36,1076.115,-141.9001,61.18835,0,0,0,0,100,0),
(@PATH,37,1060.789,-145.8449,61.36668,0,0,0,0,100,0),
(@PATH,38,1049.622,-171.201,58.53172,0,0,0,0,100,0),
(@PATH,39,1055.608,-188.9287,58.85689,0,0,0,0,100,0),
(@PATH,40,1073.355,-198.4655,59.88638,0,0,0,0,100,0),
(@PATH,41,1083.45,-195.9156,59.8475,0,0,0,0,100,0),
(@PATH,42,1095.778,-180.6123,58.73478,0,0,0,0,100,0),
(@PATH,43,1096.679,-166.0957,58.71638,0,0,0,0,100,0),
(@PATH,44,1091.597,-152.9846,61.35995,0,0,0,0,100,0),
(@PATH,45,1076.191,-141.7885,61.1882,0,0,0,0,100,0),
(@PATH,46,1060.679,-145.9348,61.39341,0,0,0,0,100,0),
(@PATH,47,1049.618,-171.0668,58.53717,0,0,0,0,100,0),
(@PATH,48,1055.49,-188.8295,58.96278,0,0,0,0,100,0),
(@PATH,49,1073.294,-198.3665,59.92146,0,0,0,0,100,0),
(@PATH,50,1083.419,-195.9023,59.84375,0,0,0,0,100,0),
(@PATH,51,1095.709,-180.6607,58.52328,0,0,0,0,100,0),
(@PATH,52,1096.673,-166.108,58.71417,0,0,0,0,100,0),
(@PATH,53,1091.596,-152.9702,61.36453,0,0,0,0,100,0),
(@PATH,54,1076.134,-141.7107,61.1886,0,0,0,0,100,0),
(@PATH,55,1060.718,-145.7299,61.40303,0,0,0,0,100,0),
(@PATH,56,1049.66,-170.9935,58.53466,0,0,0,0,100,0),
(@PATH,57,1055.598,-189.0659,59.09127,0,0,0,0,100,0),
(@PATH,58,1073.295,-198.3694,59.92171,0,0,0,0,100,0),
(@PATH,59,1083.648,-195.8578,59.9237,0,0,0,0,100,0),
(@PATH,60,1095.808,-180.5819,58.69283,0,0,0,0,100,0),
(@PATH,61,1096.681,-166.0555,58.68321,0,0,0,0,100,0),
(@PATH,62,1091.416,-153.0063,61.45639,0,0,0,0,100,0),
(@PATH,63,1076.171,-141.768,61.18841,0,0,0,0,100,0),
(@PATH,64,1060.65,-145.894,61.35575,0,0,0,0,100,0),
(@PATH,65,1049.462,-171.1664,58.5322,0,0,0,0,100,0),
(@PATH,66,1055.634,-188.8381,58.83295,0,0,0,0,100,0),
(@PATH,67,1073.464,-198.508,59.93453,0,0,0,0,100,0),
(@PATH,68,1083.448,-195.6998,59.78678,0,0,0,0,100,0),
(@PATH,69,1095.786,-180.5919,58.69092,0,0,0,0,100,0),
(@PATH,70,1096.673,-166.0698,58.68402,0,0,0,0,100,0),
(@PATH,71,1091.631,-152.9937,61.25031,0,0,0,0,100,0),
(@PATH,72,1076.178,-141.7825,61.18841,0,0,0,0,100,0),
(@PATH,73,1060.676,-145.9058,61.35313,0,0,0,0,100,0),
(@PATH,74,1049.458,-171.1682,58.53218,0,0,0,0,100,0),
(@PATH,75,1055.627,-188.8615,58.83912,0,0,0,0,100,0),
(@PATH,76,1070.503,-200.296,61.23225,0,0,0,0,100,0);
-- 0x1C16DC4B401C2980000A1E0001563CBC .go 1096.845 -166.1139 58.68692

DELETE FROM `creature_formations` WHERE `leaderGUID`=126938;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126938, 126938, 0, 0, 2, 0, 0),
(126938, 126937, 5, 90, 2, 0, 0);

-- Pathing for  Entry: 28838 'TDB FORMAT' 
SET @NPC := 126935;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1049.899,`position_y`=-99.5955,`position_z`=59.38226 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1049.899,-99.5955,59.38226,0,0,0,0,100,0),
(@PATH,2,1050.742,-83.34245,58.92643,0,0,0,0,100,0),
(@PATH,3,1055.898,-75.28898,59.04939,0,0,0,0,100,0),
(@PATH,4,1066.186,-64.55377,61.31993,0,0,0,0,100,0),
(@PATH,5,1083.335,-68.16859,59.77402,0,0,0,0,100,0),
(@PATH,6,1095.981,-92.44127,57.85799,0,0,0,0,100,0),
(@PATH,7,1097.756,-106.9242,61.43462,0,0,0,0,100,0),
(@PATH,8,1097.813,-109.0895,61.5177,0,0,0,0,100,0),
(@PATH,9,1073.511,-124.8458,61.22898,0,0,0,0,100,0),
(@PATH,10,1063.165,-119.7333,61.23046,0,0,0,0,100,0),
(@PATH,11,1052.941,-108.3153,61.3854,0,0,0,0,100,0);
-- 0x1C307C4B401C29800002170000D672BB .go 1049.899 -99.5955 59.38226

DELETE FROM `creature_formations` WHERE `leaderGUID`=126935;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126935, 126935, 0, 0, 2, 0, 0),
(126935, 126936, 5, 270, 2, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=29048;
UPDATE `creature` SET `spawndist`=40 WHERE `id`=29048;

-- Pathing for  Entry: 28835 'TDB FORMAT' 
SET @NPC := 126892;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1053.155,`position_y`=78.30748,`position_z`=61.44365 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1053.155,78.30748,61.44365,0,0,0,0,100,0),
(@PATH,2,1050.469,75.66108,61.44365,0,0,0,0,100,0),
(@PATH,3,1034.158,48.75368,59.26595,0,0,0,0,100,0),
(@PATH,4,1033.885,12.18762,61.27556,0,0,0,0,100,0),
(@PATH,5,1041.208,0.1274123,61.39244,0,0,0,0,100,0),
(@PATH,6,1052.702,-9.815857,61.43917,0,0,0,0,100,0),
(@PATH,7,1053.008,-10.01389,61.44186,0,0,0,0,100,0),
(@PATH,8,1041.027,0.347192,61.39876,0,0,0,0,100,0),
(@PATH,9,1032.457,20.25849,58.73366,0,0,0,0,100,0),
(@PATH,10,1050.469,75.66108,61.44365,0,0,0,0,100,0),
(@PATH,11,1034.158,48.75368,59.26595,0,0,0,0,100,0);
-- 0x1C307C4B401C28C000021700015672BB .go 1053.155 78.30748 61.44365

-- Pathing for  Entry: 28920 'TDB FORMAT' 
SET @NPC := 126984;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1098.968,`position_y`=19.55447,`position_z`=53.64101 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1098.968,19.55447,53.64101,0,0,0,0,100,0),
(@PATH,2,1080.878,7.88341,53.63377,0,0,0,0,100,0),
(@PATH,3,1066.863,12.70812,53.63047,0,0,0,0,100,0),
(@PATH,4,1078.049,8.259874,53.6311,0,0,0,0,100,0),
(@PATH,5,1091.877,12.4073,53.63206,0,0,0,0,100,0);
-- 0x1C307C4B401C3E0000021700005672BB .go 1098.968 19.55447 53.64101

-- Pathing for  Entry: 28920 'TDB FORMAT' 
SET @NPC := 126983;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1098.049,`position_y`=54.05235,`position_z`=53.65234 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1098.049,54.05235,53.65234,0,0,0,0,100,0),
(@PATH,2,1085.831,60.05393,53.65328,0,0,0,0,100,0),
(@PATH,3,1067.126,53.06633,53.64429,0,0,0,0,100,0),
(@PATH,4,1068.714,55.26102,53.64336,0,0,0,0,100,0),
(@PATH,5,1090.947,60.23857,53.65356,0,0,0,0,100,0),
(@PATH,6,1100.346,51.25973,53.65813,0,0,0,0,100,0);
-- 0x1C307C4B401C3E000002170000D672BB .go 1098.049 54.05235 53.65234
--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (21440, 21438, 21437, 21436, 21439);
-- Update rotation of Ru'zah
UPDATE `creature` SET `orientation`=5.026751 WHERE `guid`=74329;
--
/* SAI for Burning Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2760;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2760;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2760, 0, 0, 0, 8, 0, 100, 0, 4130, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Burning Exile - on spellhit - Despawn');

/* SAI for Cresting Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2761;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2761;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2761, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 1800000, 1800000, 11, 12544, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - Out Of Combat - Cast Frost Armor'),
(2761, 0, 1, 0, 0, 0, 100, 0, 1400, 7300, 25600, 32300, 11, 865, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - In Combat - Cast Frost Nova'),
(2761, 0, 2, 0, 8, 0, 100, 0, 4131, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - on spellhit - Despawn');

/* SAI for Thundering Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2762;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2762;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2762, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - Out Of Combat - Allow Combat Movement'),
(2762, 0, 1, 2, 4, 0, 100, 0, 0, 0, 0, 0, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - On Aggro - Cast Lightning Bolt'),
(2762, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - On Aggro - Increment Phase'),
(2762, 0, 3, 0, 9, 0, 100, 0, 0, 40, 3300, 6600, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 0 - 40 Range - Cast Lightning Bolt'),
(2762, 0, 4, 5, 3, 0, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 15% Mana - Allow Combat Movement'),
(2762, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 15% Mana - Increment Phase'),
(2762, 0, 6, 0, 9, 0, 100, 1, 35, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 35 - 80 Range - Allow Combat Movement'),
(2762, 0, 7, 0, 9, 0, 100, 1, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 0 - 5 Range - Allow Combat Movement'),
(2762, 0, 8, 0, 9, 0, 100, 0, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 5 - 15 Range - Allow Combat Movement'),
(2762, 0, 9, 10, 3, 0, 100, 0, 30, 100, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 100% Mana - Allow Combat Movement'),
(2762, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 100% Mana - Increment Phase'),
(2762, 0, 11, 0, 0, 0, 100, 0, 1600, 15100, 18900, 25400, 11, 11824, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - In Combat - Cast Shock'),
(2762, 0, 12, 0, 8, 0, 100, 0, 4132, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - on spellhit - Despawn');
-- Theradrim Shardling SAI
SET @ENTRY := 11783;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,50,0,0,5,7000,11000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theradrim Shardling - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,29,2,90,0,0,0,0,19,11784,10,0,0,0,0,0,"Theradrim Shardling - On Just Summoned - Start Follow Closest Creature 'Theradrim Guardian'");

-- Theradrim Guardian SAI
SET @ENTRY := 11784;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,12000,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theradrim Guardian - Within 0-5 Range - Cast 'Knockdown' (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,21057,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theradrim Guardian - Out of Combat - Cast 'Summon Theradrim Shardling' (No Repeat) (Normal Dungeon)");

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55465;
DELETE FROM `creature_addon` WHERE `guid`=55465;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55465, 554650, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=554650;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(554650, 1, 248.538, -93.024, -129.62, 0, 0, 0, 0, 100, 0),
(554650, 2, 219.021, -92.1171, -129.607, 0, 0, 0, 0, 100, 0),
(554650, 3, 258.14, -97.1733, -129.619, 0, 0, 0, 0, 100, 0),
(554650, 4, 246.967, -145.304, -130.844, 0, 0, 0, 0, 100, 0),
(554650, 5, 213.934, -199.873, -131.159, 0, 0, 0, 0, 100, 0),
(554650, 6, 248.627, -140.739, -131.005, 0, 0, 0, 0, 100, 0),
(554650, 7, 259.8, -98.2245, -129.619, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature` WHERE `guid` IN (55466, 56518, 56516, 56517, 56504, 56502, 56505, 56503, 56488, 56487, 56486, 88993, 88991, 88990, 88992, 56343, 56341, 55472);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55471;
DELETE FROM `creature_addon` WHERE `guid`=55471;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55471, 554710, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=554710;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(554710, 1, 200.354, -133.505, -101.058, 0, 0, 0, 0, 100, 0),
(554710, 2, 230.841, -109.688, -88.8687, 0, 0, 0, 0, 100, 0),
(554710, 3, 278.173, -121.002, -83.4807, 0, 0, 0, 0, 100, 0),
(554710, 4, 300.187, -149.075, -69.7502, 0, 0, 0, 0, 100, 0),
(554710, 5, 298.76, -178.312, -59.8991, 0, 0, 0, 0, 100, 0),
(554710, 6, 299.577, -148.794, -69.9433, 0, 0, 0, 0, 100, 0),
(554710, 7, 276.408, -121.048, -83.6496, 0, 0, 0, 0, 100, 0),
(554710, 8, 226.955, -112.811, -89.7437, 0, 0, 0, 0, 100, 0),
(554710, 9, 199.686, -134.684, -101.541, 0, 0, 0, 0, 100, 0),
(554710, 10, 183.329, -185.544, -111.375, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=88989;
DELETE FROM `creature_addon` WHERE `guid`=88989;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(88989, 889890, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=889890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(889890, 1, 109.037, -268.553, -108.677, 0, 0, 0, 0, 100, 0),
(889890, 2, 151.884, -275.712, -108.677, 0, 0, 0, 0, 100, 0),
(889890, 3, 143.666, -231.173, -108.852, 0, 0, 0, 0, 100, 0),
(889890, 4, 156.17, -275.286, -108.676, 0, 0, 0, 0, 100, 0),
(889890, 5, 138.876, -278.577, -108.676, 0, 0, 0, 0, 100, 0),
(889890, 6, 79.5604, -259.988, -108.678, 0, 0, 0, 0, 100, 0),
(889890, 7, 62.416, -207.188, -109.659, 0, 0, 0, 0, 100, 0),
(889890, 8, 8.187, -127.348, -123.845, 0, 0, 0, 0, 100, 0),
(889890, 9, 28.705, -38.025, -128.761, 0, 0, 0, 0, 100, 0),
(889890, 10, 8.187, -127.348, -123.845, 0, 0, 0, 0, 100, 0),
(889890, 11, 62.416, -207.188, -109.659, 0, 0, 0, 0, 100, 0),
(889890, 12, 79.0383, -255.555, -108.677, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56485;
DELETE FROM `creature_addon` WHERE `guid`=56485;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56485, 564850, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=564850;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(564850, 1, 150.49, -193.898, -171.747, 0, 0, 0, 0, 100, 0),
(564850, 2, 152.233, -231.891, -170.382, 0, 0, 0, 0, 100, 0),
(564850, 3, 125.841, -257.66, -168.113, 0, 0, 0, 0, 100, 0),
(564850, 4, 155.987, -284.034, -168.989, 0, 0, 0, 0, 100, 0),
(564850, 5, 148.455, -238.759, -169.543, 0, 0, 0, 0, 100, 0),
(564850, 6, 155.062, -199.53, -171.957, 0, 0, 0, 0, 100, 0),
(564850, 7, 104.937, -185.658, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 8, 100.198, -176.082, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 9, 111.893, -160.596, -167.328, 0, 0, 0, 0, 100, 0),
(564850, 10, 121.304, -176.939, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 11, 128.284, -191.12, -168.26, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56501;
DELETE FROM `creature_addon` WHERE `guid`=56501;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56501, 565010, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=565010;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(565010, 1, 177.079, -304.031, -172.328, 0, 0, 0, 0, 100, 0),
(565010, 2, 146.519, -316.403, -174.591, 0, 0, 0, 0, 100, 0),
(565010, 3, 153.733, -376.576, -175.003, 0, 0, 0, 0, 100, 0),
(565010, 4, 211.381, -381.672, -160.691, 0, 0, 0, 0, 100, 0),
(565010, 5, 156.615, -376.11, -175.002, 0, 0, 0, 0, 100, 0),
(565010, 6, 148.461, -317.13, -174.589, 0, 0, 0, 0, 100, 0);


UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56515;
DELETE FROM `creature_addon` WHERE `guid`=56515;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56515, 565150, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=565150;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(565150, 1, 312.737, -343.241, -117.348, 0, 0, 0, 0, 100, 0),
(565150, 2, 328.91, -288.013, -118.069, 0, 0, 0, 0, 100, 0),
(565150, 3, 320.637, -268.75, -117.912, 0, 0, 0, 0, 100, 0),
(565150, 4, 337.697, -262.309, -118.049, 0, 0, 0, 0, 100, 0),
(565150, 5, 345.634, -276.933, -117.941, 0, 0, 0, 0, 100, 0),
(565150, 6, 331.665, -290.395, -118.061, 0, 0, 0, 0, 100, 0),
(565150, 7, 317.848, -331.827, -116.777, 0, 0, 0, 0, 100, 0),
(565150, 8, 325.14, -394.223, -124.867, 0, 0, 0, 0, 100, 0),
(565150, 9, 250.345, -396.668, -139.555, 0, 0, 0, 0, 100, 0),
(565150, 10, 256.965, -328.427, -140.451, 0, 0, 0, 0, 100, 0),
(565150, 11, 251.778, -396.72, -139.555, 0, 0, 0, 0, 100, 0),
(565150, 12, 319.125, -403.751, -124.866, 0, 0, 0, 0, 100, 0);

SET @GUID := 160506;
SET @ENTRY := 1211;
-- Placed NPC 12237 (Meshlok the Harvester) into a pool with its placeholder
DELETE FROM `pool_creature` WHERE `guid` IN (@GUID, @GUID +3, 54652);
INSERT INTO `pool_creature` VALUES
(@GUID, @ENTRY, 30, 'Meshlok the Harvester (Maraudon)'),
(@GUID + 3, @ENTRY, 0, 'Meshlok the Harvester placeholder (Maraudon)'),
(54652, @ENTRY, 0, 'Meshlok the Harvester placeholder (Maraudon)');

DELETE FROM `pool_template` WHERE `entry` = @ENTRY;
INSERT INTO `pool_template` VALUES
(@ENTRY, 1, 'Meshlok the Harvester (Maraudon)');

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID + 7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@GUID, 12237, 349, 0, 0, 1, 1, 0, 1, 632.101, -92.409, -57.4999, 3.49563, 7200, 0, 0, 5757, 0, 0, 0, 0, 0, 0),
(@GUID + 1, 12224, 349, 0, 0, 1, 1, 0, 1, 748.725, -81.8362, -57.4696, 0.620471, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 2, 12224, 349, 0, 0, 1, 1, 0, 1, 632.101, -92.409, -57.4999, 3.49563, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 3, 12224, 349, 0, 0, 1, 1, 0, 1, 818.573, -215.097, -77.1489, 4.14281, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 4, 12224, 349, 0, 0, 1, 1, 0, 1, 813.453, -370.449, -59.2094, 6.02488, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 5, 12224, 349, 0, 0, 1, 1, 0, 1, 719.899, -83.8715, -57.2155, 3.48941, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 1;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+1, (@GUID+1) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+1) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+1) * 10, 1, 747.806, -79.9688, -57.4744, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 2, 750.866, -86.8807, -57.4595, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 3, 741.016, -94.8653, -57.4978, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 4, 745.803, -84.0748, -57.4833, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 5, 738.607, -70.5452, -57.4977, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 6, 751.253, -70.6902, -57.3912, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 7, 744.367, -78.7708, -57.4887, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 8, 756.588, -80.4979, -57.3727, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 9, 736.461, -89.3428, -57.4996, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 10, 734.7, -80.3283, -57.4996, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 11, 744.209, -79.5844, -57.4915, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 12, 734.044, -71.701, -57.4977, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 2;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+2, (@GUID+2) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+2) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+2) * 10, 1, 632.101, -92.409, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 2, 642.895, -89.225, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 3, 654.193, -88.5337, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 4, 666.728, -91.7718, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 5, 675.549, -93.9197, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 6, 690.764, -89.7546, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 7, 702.83, -84.753, -57.4631, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 8, 715.159, -83.791, -57.1193, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 9, 708.503, -83.9885, -57.2554, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 10, 699.353, -86.647, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 11, 681.834, -93.4817, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 12, 674.938, -93.0037, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 13, 665.508, -90.6338, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 14, 652.935, -87.6942, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 15, 634.167, -92.0013, -57.5, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 3;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+3, (@GUID+3) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+3) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+3) * 10, 1, 818.873, -216.343, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 2, 813.487, -210.328, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 3, 806.875, -204.634, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 4, 804.811, -193.5, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 5, 806.356, -184.124, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 6, 813.319, -173.6, -77.2995, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 7, 808.847, -175.006, -77.3074, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 8, 805.501, -182.277, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 9, 804.538, -193.051, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 10, 807.906, -203.501, -77.1489, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=203506;
DELETE FROM `creature_addon` WHERE `guid`=203506;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(203506, 203506 * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=203506 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(203506 * 10, 1, 632.101, -92.409, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 2, 642.895, -89.225, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 3, 654.193, -88.5337, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 4, 666.728, -91.7718, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 5, 675.549, -93.9197, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 6, 690.764, -89.7546, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 7, 702.83, -84.753, -57.4631, 0, 0, 0, 0, 100, 0),
(203506 * 10, 8, 715.159, -83.791, -57.1193, 0, 0, 0, 0, 100, 0),
(203506 * 10, 9, 708.503, -83.9885, -57.2554, 0, 0, 0, 0, 100, 0),
(203506 * 10, 10, 699.353, -86.647, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 11, 681.834, -93.4817, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 12, 674.938, -93.0037, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 13, 665.508, -90.6338, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 14, 652.935, -87.6942, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 15, 634.167, -92.0013, -57.5, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template` SET `speed_walk`=0.3, `speed_run`=0.4 WHERE  `entry`=12222;

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55118;
DELETE FROM `creature_addon` WHERE `guid`=55118;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55118, 55118 * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=55118 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(55118 * 10, 1, 560.44, 74.1416, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 2, 556.001, 97.5598, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 3, 562.821, 116.938, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 4, 558.737, 80.2023, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 5, 567.894, 47.7771, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 6, 573.623, 24.1758, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 7, 583.107, 6.90322, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 8, 597.509, 5.07898, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 9, 600.013, 21.6183, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 10, 575.202, 46.2133, -96.3128, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=55118;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(55118, 55118, 0, 0, 2, 0, 0),
(55118, 55115, 3, 0, 2, 0, 0),
(55118, 55116, 3, 70, 2, 0, 0),
(55118, 55117, 3, 290, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=54579;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(54579, 54579, 0, 0, 2, 0, 0),
(54579, 54675, 16, 270, 2, 0, 0),
(54579, 54676, 16, 90, 2, 0, 0);
--
DELETE FROM `creature` WHERE guid=85587 AND `id`=17318;
--
UPDATE `creature_template` SET `unit_flags`=0, `flags_extra`=0, `npcflag`=0 WHERE  `entry`=17587;
-- Timberstrider Fledgling SAI
SET @ENTRY := 17372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,17587,10,0,0,0,0,0,"Timberstrider Fledgling - On Just Died - Set Data 1 1");

-- Draenei Youngling SAI
SET @ENTRY := 17587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,1,0,100,0,60000,60000,60000,60000,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - Out of Combat - Set Event Phase 0"),
(@ENTRY,0,1,0,8,0,100,0,28880,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,2,0,38,1,100,0,1,1,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Data Set 1 1 - Set Npc Flag Questgiver (Phase 1)"),
(@ENTRY,0,3,0,61,0,100,0,60000,60000,60000,60000,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - Out of Combat - Set Npc Flag "),
(@ENTRY,0,5,0,8,0,100,0,59547,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,6,0,8,0,100,0,59545,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,7,0,8,0,100,0,59544,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,8,0,8,0,100,0,59542,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,9,0,8,0,100,0,59548,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,10,0,8,0,100,0,59543,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `entry`IN (17587);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(17587,0,0, 'Help! I think this creature might be too tough for me to handle alone.',12,35,100,0,0,0, '17587',14167), -- player IC_LOS
(17587,0,1, 'Can anyone hear me? I need help! This creature is going to kill me!',12,35,100,0,0,0, '17587',14168), -- player IC_LOS
(17587,0,2, 'I can''t hold it off any longer! Tell the exarch that I gave it my best.',12,35,100,0,0,0, '17587',14169), -- player IC_LOS
(17587,1,0, 'Thanks again!',12,35,100,0,0,0, '17587',14170), -- heal received
(17587,1,1, 'Thanks for the heal, $n!',12,35,100,0,0,0, '17587',14166), -- heal received
(17587,2,0, 'Another victory for the Draenei!',12,35,100,0,0,0, '17587',14171), -- target dies
(17587,2,1, 'Another infected beast destroyed!',12,35,100,0,0,0, '17587',14172), -- target dies
(17587,2,2, 'Hah! This is easy.',12,35,100,0,0,0, '17587',14174), -- target dies
(17587,2,3, 'How could you think yourself a match for the draenei champion!',12,35,100,0,0,0, '17587',14173), -- target dies
(17587,3,0, 'Kill as many infected nightstalkers as I can find... This should be easy.',12,35,100,0,0,0, '17587',14165), -- random ooc
(17587,3,1, 'I''m supposed to be hunting infected nightstalkers... This should be easy.',12,35,100,0,0,0, '17587',14175), -- random ooc
(17587,3,2, 'Where in the nether are these damnable lashers??',12,35,100,0,0,0, '17587',14176), -- random ooc
(17587,3,3, 'Hrm, azure snapdragons? Where do they come up with these names? Daedal has gone mad!',12,35,100,0,0,0, '17587',14177), -- random ooc
(17587,3,4, 'These stags look nothing like talbuks.',12,35,100,0,0,0, '17587',14178), -- random ooc
(17587,3,5, 'I wonder what that little purple creature at the village is... It''s certainly beautiful.',12,35,100,0,0,0, '17587',14179), -- random ooc
(17587,4,0, 'Time to meet your maker, $n!',12,35,100,0,0,0, '17587',14180); -- on aggro
--
DELETE FROM `skill_discovery_template` WHERE  `spellId`=54020 AND `reqSpell`=60893;
-- Magmoth Shaman SAI
SET @ENTRY := 25428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Shaman - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magmoth Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,11,45575,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Shaman - On Reset - Cast 'Magmoth Fire Totem'");

-- Magmoth Fire Totem SAI
SET @ENTRY := 25444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Fire Totem - On Just Summoned - Enable Combat Movement"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,4000,4000,11,45580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magmoth Fire Totem - In Combat - Cast 'Fireball'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,20000,20000,11,45576,0,0,0,0,0,19,24021,30,0,0,0,0,0,"Magmoth Fire Totem - Out of Combat - Cast 'Cosmetic - New Fire Beam Channel (Mouth)'"),
(@ENTRY,0,3,0,7,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Fire Totem - On Evade - Despawn Instant");
--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=45465;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45465, 0, 0, 31, 0, 3, 24862, 0, 0, 0, 0, '', 'Mage Hunter Channel - targets Bunny');

-- Beryl Treasure Hunter SAI
SET @ENTRY := 25353;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,12500,15500,11,50658,0,0,0,0,0,2,0,0,0,0,0,0,0,"Beryl Treasure Hunter - In Combat - Cast 'Focus Beam'"),
(@ENTRY,0,1,0,1,0,100,0,5000,5000,15000,15000,11,45465,0,0,0,0,0,19,24862,60,0,0,0,0,0,"Beryl Treasure Hunter - Out of Combat - Cast 'Mage Hunter Channel'");
-- Kvaldir Mist Lord SAI
SET @GUID := -110298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25496;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,2549600,1,0,0,2,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,2,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 2 Reached - Run Script"),
(@GUID,0,2,0,40,0,100,0,4,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 4 Reached - Run Script"),
(@GUID,0,3,0,40,0,100,0,6,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 6 Reached - Run Script"),
(@GUID,0,4,0,40,0,100,0,8,2549600,0,0,80,2549600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Waypoint 8 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2549600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,10,110382,25242,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Set Orientation Closest Creature 'Warsong Battleguard'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Play Emote 53"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,11,45667,0,0,0,0,0,19,25244,50,0,0,0,0,0,"Kvaldir Mist Lord - On Script - Cast 'Torch Corpse'");

DELETE FROM `waypoints` WHERE `entry`=2549600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2549600, 1, 2943.3, 6805.71, 6.86362, 'Kvaldir Mist Lord'),
(2549600, 2, 2946.38, 6808.99, 6.89997, 'Kvaldir Mist Lord'),
(2549600, 3, 2952.22, 6815.03, 5.49191, 'Kvaldir Mist Lord'),
(2549600, 4, 2956.26, 6811.33, 5.7004, 'Kvaldir Mist Lord'),
(2549600, 5, 2959.27, 6809.55, 5.73998, 'Kvaldir Mist Lord'),
(2549600, 6, 2958.56, 6804.6, 6.10027, 'Kvaldir Mist Lord'),
(2549600, 7, 2958.36, 6799.58, 6.55177, 'Kvaldir Mist Lord'),
(2549600, 8, 2953.32, 6798.66, 6.69609, 'Kvaldir Mist Lord');

DELETE FROM `creature_text` WHERE `entry`=25496;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25496, 0, 0, 'You are dismissed, $n.', 12, 0, 100, 113, 0, 0, 1242, 0, 'Marshal McBride');

DELETE FROM `creature_text` WHERE `entry`=25496;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(25496, 0, 0, 'Become ashes in the mist!', 12, 0, 50, 53, 0, 0, 24719, 'Kvaldir Mist Lord'),
(25496, 0, 1, 'The subjugation of these people has only just begun... so much time for fun and games.', 12, 0, 50, 53, 0, 0, 24718, 'Kvaldir Mist Lord'),
(25496, 0, 2, 'Burn, land dweller! BURN!', 12, 0, 50, 53, 0, 0, 24717, 'Kvaldir Mist Lord');
-- Fireguard Destroyer SAI
SET @ENTRY := 8911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,9000,11000,11,15243,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fireguard Destroyer - Within 0-30 Range - Cast 'Fireball Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,5000,8000,11,16788,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fireguard Destroyer - In Combat - Cast 'Fireball'");
--
UPDATE `conditions` SET `ConditionValue1`=11332 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9546 AND `SourceEntry`=1 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=12298 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `gossip_menu_option` SET `npc_option_npcflag`=8195 WHERE `menu_id`=9546 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23859;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23859, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 80, 2385900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On aggro - Run Script'),
(23859, 0, 1, 0, 62, 0, 100, 0, 9546, 1, 0, 0, 56, 33634, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip option select - give player 10 Orehammer\'s Precision Bombs'),
(23859, 0, 2, 0, 62, 0, 100, 0, 9546, 1, 0, 0, 52, 745, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip option select - Plague This Taxi Start');

-- New Agamand Plague Tank Bunny SAI
SET @ENTRY := 24290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,43404,0,0,0,33,24290,0,0,0,0,0,7,0,0,0,0,0,0,0,"New Agamand Plague Tank Bunny - On Spellhit 'Mission: Plague This!: Orehammer's Precision Bombs Dummy' - Quest Credit 'Mission: Plague This!'");
-- Pathing for  Entry: 25979 'TDB FORMAT' 
SET @NPC := 107300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3289.213,`position_y`=5620.369,`position_z`=51.0953 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3289.213,5620.369,51.0953,0,0,0,0,100,0),
(@PATH,2,3289.156,5612.807,51.6523,0,0,0,0,100,0),
(@PATH,3,3285.626,5645.205,51.53279,0,0,0,0,100,0),
(@PATH,4,3283.541,5652.846,52.70237,0,0,0,0,100,0),
(@PATH,5,3280.611,5683.929,54.8549,0,0,0,0,100,0),
(@PATH,6,3303.37,5707.606,60.20351,0,0,0,0,100,0),
(@PATH,7,3282.027,5687.42,56.04992,0,0,0,0,100,0),
(@PATH,8,3279.962,5672.618,53.23326,0,0,0,0,100,0),
(@PATH,9,3284.723,5649.133,52.33985,0,0,0,0,100,0);
-- 0x1C09144760195EC000000C0000579A79 .go 3289.213 5620.369 51.0953
-- Inquisitor Salrand SAI
SET @ENTRY := 25584;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,1,0,100,0,5000,5000,10000,10000,11,45777,0,0,0,0,0,10,119586,25594,0,0,0,0,0,"Inquisitor Salrand - Out of Combat - Cast 'Salrand's Beam'");

-- Pathing for  Entry: 25217 'TDB FORMAT' 
SET @NPC := 122872;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4113.013,`position_y`=6276.871,`position_z`=25.68058 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4113.013,6276.871,25.68058,0,0,0,0,100,0),
(@PATH,2,4090.676,6280.604,27.56935,0,0,0,0,100,0),
(@PATH,3,4074.31,6276.669,26.26191,0,0,0,0,100,0),
(@PATH,4,4063.338,6284.883,23.54415,0,0,0,0,100,0),
(@PATH,5,4060.495,6308.033,24.63371,0,0,0,0,100,0),
(@PATH,6,4064.796,6325.54,25.33357,0,0,0,0,100,0),
(@PATH,7,4062.167,6349.621,24.96839,0,0,0,0,100,0),
(@PATH,8,4055.423,6363.151,27.49203,0,0,0,0,100,0),
(@PATH,9,4061.251,6351.451,25.36894,0,0,0,0,100,0),
(@PATH,10,4064.368,6335.375,25.38478,0,0,0,0,100,0),
(@PATH,11,4061.08,6310.811,24.90634,0,0,0,0,100,0),
(@PATH,12,4059.284,6298.654,24.53846,0,0,0,0,100,0),
(@PATH,13,4069.346,6279.003,24.92667,0,0,0,0,100,0),
(@PATH,14,4084.886,6280.17,27.70065,0,0,0,0,100,0),
(@PATH,15,4107.833,6280.248,25.45559,0,0,0,0,100,0);
-- 0x1C0914476018A04000000C000057EEC0 .go 4113.013 6276.871 25.68058

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 57031;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2797.154,`position_y`=6620.249,`position_z`=48.24942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2797.154,6620.249,48.24942,0,0,0,0,100,0),
(@PATH,2,2807.472,6623.047,46.9419,0,0,0,0,100,0),
(@PATH,3,2822.777,6620.003,48.07745,0,0,0,0,100,0),
(@PATH,4,2828.091,6608.199,49.87174,0,0,0,0,100,0),
(@PATH,5,2829.904,6600.112,50.43536,0,0,0,0,100,0),
(@PATH,6,2825.405,6583.044,51.32146,0,0,0,0,100,0),
(@PATH,7,2812.032,6576.637,50.3959,0,0,0,0,100,0),
(@PATH,8,2808.558,6575.663,49.55042,0,0,0,0,100,0),
(@PATH,9,2791.914,6578.114,49.39709,0,0,0,0,100,0),
(@PATH,10,2790.871,6579.394,49.35609,0,0,0,0,100,0),
(@PATH,11,2793.273,6598.499,49.21821,0,0,0,0,100,0),
(@PATH,12,2797.287,6620.314,48.24408,0,0,0,0,100,0);
-- 0x1C091447601902C000000C0000588B21 .go 2797.154 6620.249 48.24942

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97489;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2755.648,`position_y`=6516.167,`position_z`=52.22083 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2755.648,6516.167,52.22083,0,0,0,0,100,0),
(@PATH,2,2739.121,6534.617,51.25744,0,0,0,0,100,0),
(@PATH,3,2736.37,6540.505,50.52654,0,0,0,0,100,0),
(@PATH,4,2736.999,6568.931,49.45178,0,0,0,0,100,0),
(@PATH,5,2745.165,6582.929,49.87815,0,0,0,0,100,0),
(@PATH,6,2749.685,6588.33,49.43536,0,0,0,0,100,0),
(@PATH,7,2764.539,6590.529,49.07096,0,0,0,0,100,0),
(@PATH,8,2783.451,6578.873,49.38116,0,0,0,0,100,0),
(@PATH,9,2790.408,6542.078,51.47867,0,0,0,0,100,0),
(@PATH,10,2781.756,6526.21,53.26818,0,0,0,0,100,0),
(@PATH,11,2759.35,6514.721,52.89858,0,0,0,0,100,0);
-- 0x1C091447601902C000000C0001588AE6 .go 2755.648 6516.167 52.22083

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97486;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2959.18,`position_y`=6518.749,`position_z`=72.95694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2959.18,6518.749,72.95694,0,0,0,0,100,0),
(@PATH,2,2943.816,6531.531,70.15851,0,0,0,0,100,0),
(@PATH,3,2922.839,6548.202,66.36589,0,0,0,0,100,0),
(@PATH,4,2905.143,6556.469,64.68446,0,0,0,0,100,0),
(@PATH,5,2886.449,6562.177,61.95524,0,0,0,0,100,0),
(@PATH,6,2870.039,6568.242,58.85592,0,0,0,0,100,0),
(@PATH,7,2849.421,6573.922,54.75926,0,0,0,0,100,0),
(@PATH,8,2864.578,6570.402,57.7508,0,0,0,0,100,0),
(@PATH,9,2880.555,6564.39,60.65393,0,0,0,0,100,0),
(@PATH,10,2900.065,6558.482,64.16826,0,0,0,0,100,0),
(@PATH,11,2916.618,6552.232,65.66638,0,0,0,0,100,0),
(@PATH,12,2939.966,6534.6,69.45979,0,0,0,0,100,0),
(@PATH,13,2950.899,6526.294,71.31409,0,0,0,0,100,0),
(@PATH,14,2978.666,6499.601,75.67303,0,0,0,0,100,0),
(@PATH,15,2959.18,6518.749,72.95694,0,0,0,0,100,0);
-- 0x1C091447601902C000000C00005893B1 .go 2959.18 6518.749 72.95694

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97472;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3132.141,`position_y`=6364.85,`position_z`=87.00642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3132.141,6364.85,87.00642,0,0,0,0,100,0),
(@PATH,2,3145.254,6377.429,86.04013,0,0,0,0,100,0),
(@PATH,3,3150.995,6384.529,85.66245,0,0,0,0,100,0),
(@PATH,4,3150.954,6413.424,86.59067,0,0,0,0,100,0),
(@PATH,5,3148.383,6418.564,87.16897,0,0,0,0,100,0),
(@PATH,6,3127.888,6445.25,85.42545,0,0,0,0,100,0),
(@PATH,7,3125.299,6448.726,84.63122,0,0,0,0,100,0),
(@PATH,8,3098.482,6453.096,86.2816,0,0,0,0,100,0),
(@PATH,9,3092.813,6430.465,86.18443,0,0,0,0,100,0),
(@PATH,10,3092.439,6429.254,86.16457,0,0,0,0,100,0),
(@PATH,11,3090.803,6416.944,86.47922,0,0,0,0,100,0),
(@PATH,12,3080.703,6420.038,86.92494,0,0,0,0,100,0),
(@PATH,13,3066.926,6403.042,89.00624,0,0,0,0,100,0),
(@PATH,14,3071.34,6388.575,89.95999,0,0,0,0,100,0),
(@PATH,15,3071.793,6387.598,89.86023,0,0,0,0,100,0),
(@PATH,16,3092.656,6366.145,89.73042,0,0,0,0,100,0),
(@PATH,17,3109.781,6356.525,88.38365,0,0,0,0,100,0),
(@PATH,18,3114.204,6357.174,87.74312,0,0,0,0,100,0),
(@PATH,19,3132.181,6364.944,87.00461,0,0,0,0,100,0);
-- 0x1C091447601902C000000A000058AB81 .go 3132.141 6364.85 87.00642

-- Pathing for  Entry: 25475 'TDB FORMAT' 
SET @NPC := 107800;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2814.188,`position_y`=6720.133,`position_z`=9.794792 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2814.188,6720.133,9.794792,0,0,0,0,100,0),
(@PATH,2,2810.317,6723.547,9.082146,0,0,0,0,100,0);
-- 0x1C0914476018E0C000000C00005660EE .go 2814.188 6720.133 9.794792

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 110300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3067.602,`position_y`=6705.609,`position_z`=6.230121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3067.602,6705.609,6.230121,0,0,0,0,100,0),
(@PATH,2,3051.766,6718.588,6.615577,0,0,0,0,100,0),
(@PATH,3,3024.569,6720.975,9.706598,0,0,0,0,100,0),
(@PATH,4,3031.904,6726.806,7.207738,0,0,0,0,100,0),
(@PATH,5,3033.154,6727.66,6.58389,0,0,0,0,100,0),
(@PATH,6,3068.976,6704.811,5.953619,0,0,0,0,100,0),
(@PATH,7,3095.539,6680.229,6.846659,0,0,0,0,100,0),
(@PATH,8,3095.83,6662.607,9.923321,0,0,0,0,100,0),
(@PATH,9,3099.785,6674.892,7.75151,0,0,0,0,100,0),
(@PATH,10,3090.089,6685.671,6.213068,0,0,0,0,100,0),
(@PATH,11,3067.523,6705.942,6.221252,0,0,0,0,100,0);
-- 0x1C0914476018E60000000C000058AEB8 .go 3067.602 6705.609 6.230121

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `id` IN (25244);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=57067;

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 57066;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2431.173,`position_y`=6827.691,`position_z`=4.434509 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2431.173,6827.691,4.434509,0,0,0,0,100,0),
(@PATH,2,2417.92,6818.268,3.808835,0,0,0,0,100,0),
(@PATH,3,2401.83,6806.687,1.444491,0,0,0,0,100,0),
(@PATH,4,2397.053,6803.022,1.261812,0,0,0,0,100,0),
(@PATH,5,2415.603,6771.807,2.460288,0,0,0,0,100,0),
(@PATH,6,2444.461,6781.449,6.446399,0,0,0,0,100,0),
(@PATH,7,2448.987,6792.239,6.01413,0,0,0,0,100,0),
(@PATH,8,2466.415,6808.424,4.947993,0,0,0,0,100,0),
(@PATH,9,2479.129,6823.808,2.68948,0,0,0,0,100,0),
(@PATH,10,2480.822,6831.567,1.405943,0,0,0,0,100,0),
(@PATH,11,2481.074,6846.526,1.077314,0,0,0,0,100,0),
(@PATH,12,2453.165,6857.935,1.077329,0,0,0,0,100,0),
(@PATH,13,2438.796,6843.509,1.671256,0,0,0,0,100,0);
-- 0x1C0914476018E60000000A0000586C4C .go 2431.173 6827.691 4.434509

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 57059;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2414.351,`position_y`=6738.811,`position_z`=2.7648 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2414.351,6738.811,2.7648,0,0,0,0,100,0),
(@PATH,2,2411.604,6704.709,6.068311,0,0,0,0,100,0),
(@PATH,3,2411.347,6702.018,6.760894,0,0,0,0,100,0),
(@PATH,4,2452.357,6721.351,6.010249,0,0,0,0,100,0),
(@PATH,5,2466.691,6738.082,6.927616,0,0,0,0,100,0),
(@PATH,6,2495.109,6765.589,6.517776,0,0,0,0,100,0),
(@PATH,7,2513.06,6790.916,4.482207,0,0,0,0,100,0),
(@PATH,8,2523.949,6806.354,1.703682,0,0,0,0,100,0),
(@PATH,9,2532.222,6817.983,1.145756,0,0,0,0,100,0),
(@PATH,10,2546.355,6838.362,1.049538,0,0,0,0,100,0),
(@PATH,11,2548.539,6846.931,0.8498411,0,0,0,0,100,0),
(@PATH,12,2506.485,6784.912,5.38059,0,0,0,0,100,0),
(@PATH,13,2483.945,6763.865,6.803366,0,0,0,0,100,0),
(@PATH,14,2480.173,6760.685,6.7745,0,0,0,0,100,0),
(@PATH,15,2419.531,6764.058,3.010518,0,0,0,0,100,0),
(@PATH,16,2414.283,6738.649,2.879114,0,0,0,0,100,0);
-- 0x1C0914476018E60000000C0000587988 .go 2414.351 6738.811 2.7648

DELETE FROM `creature_addon` WHERE `guid` IN (110289,57070,57063, 57065, 57067,57064,57062,57068,57060,57058,57057, 57056,57061,110291,110301,110290,110285,57072);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(57063, 0, 0, 0, 0, 69, ''),
(57065, 0, 0, 0, 0, 234, ''),
(57067, 0, 0, 0, 0, 234, ''),
(57064, 0, 0, 0, 0, 234, ''),
(57062, 0, 0, 0, 0, 69, ''),
(57068, 0, 0, 0, 0, 234, ''),
(57060, 0, 0, 0, 0, 234, ''),
(57058, 0, 0, 0, 0, 234, ''),
(57057, 0, 0, 0, 0, 234, ''),
(57056, 0, 0, 0, 0, 234, ''),
(57061, 0, 0, 0, 0, 27, ''),
(110291, 0, 0, 0, 0, 27, ''),
(110301, 0, 0, 0, 0, 69, ''),
(110290, 0, 0, 0, 0, 27, ''),
(110285, 0, 0, 0, 0, 27, ''),
(57072, 0, 0, 0, 0, 69, ''),
(110289, 0, 0, 0, 0, 27, ''),
(57070, 0, 0, 0, 0, 27, '');

DELETE FROM `creature_addon` WHERE `guid` IN (112665,112663,112662,112660,112659,112666,112679,112673,112678,112671,112667,112672,56752,112741,56327,112661,112658,56325, 112668, 112670, 112669, 56322);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56325, 0, 0, 0, 0, 4, ''),
(112668, 0, 0, 0, 0, 4, ''),
(112670, 0, 0, 0, 0, 4, ''),
(112669, 0, 0, 0, 0, 4, ''),
(56322, 0, 0, 0, 0, 4, ''),
(112661, 0, 0, 0, 0, 234, ''),
(112658, 0, 0, 0, 0, 234, ''),
(56327, 0, 0, 0, 0, 234, ''),
(112741, 0, 0, 0, 0, 27, ''),
(56752, 0, 0, 0, 0, 27, ''),
(112672, 0, 0, 1, 0, 0, ''),
-- 
(112678, 0, 0, 0, 0, 4, ''),
(112671, 0, 0, 0, 0, 4, ''),
(112667, 0, 0, 0, 0, 4, ''),
-- 
(112673, 0, 0, 1, 0, 0, ''),
(112679, 0, 0, 1, 0, 0, ''),
(112666, 0, 0, 0, 0, 234, ''),
(112665, 0, 0, 0, 0, 234, ''),
(112659, 0, 0, 0, 0, 234, ''),
(112660, 0, 0, 0, 0, 234, ''),
(112663, 0, 0, 0, 0, 234, ''),
(112662, 0, 0, 0, 0, 234, '');

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112755;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1863.071,`position_y`=5721.263,`position_z`=0.5444731 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,2,1871.592,5727.264,0.5210824,0,0,0,0,100,0),
(@PATH,3,1865.804,5766.675,0.8066133,0,0,0,0,100,0),
(@PATH,4,1861.19,5769.085,0.636929,0,0,0,0,100,0),
(@PATH,5,1853.291,5777.555,0.8031902,0,0,0,0,100,0),
(@PATH,6,1838.134,5783.222,0.6275423,0,0,0,0,100,0),
(@PATH,7,1838.138,5783.196,0.5076787,0,0,0,0,100,0),
(@PATH,8,1838.279,5783.279,0.609849,0,0,0,0,100,0),
(@PATH,9,1853.601,5777.178,0.8158144,0,0,0,0,100,0),
(@PATH,10,1872.918,5754.421,0.8373558,0,0,0,0,100,0),
(@PATH,11,1873.445,5750.554,0.7919877,0,0,0,0,100,0),
(@PATH,12,1857.673,5717.76,0.05196175,0,0,0,0,100,0),
(@PATH,13,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,14,1871.617,5727.281,0.5215871,0,0,0,0,100,0),
(@PATH,15,1865.804,5766.67,0.806583,0,0,0,0,100,0),
(@PATH,16,1861.121,5769.259,0.6014363,0,0,0,0,100,0),
(@PATH,17,1853.309,5777.537,0.8029698,0,0,0,0,100,0),
(@PATH,18,1838.146,5783.217,0.6276386,0,0,0,0,100,0),
(@PATH,19,1838.138,5783.196,0.5076787,0,0,0,0,100,0),
(@PATH,20,1838.511,5783.279,0.6102685,0,0,0,0,100,0),
(@PATH,21,1853.596,5777.181,0.8157681,0,0,0,0,100,0),
(@PATH,22,1872.897,5754.442,0.837615,0,0,0,0,100,0),
(@PATH,23,1873.44,5750.595,0.7921225,0,0,0,0,100,0),
(@PATH,24,1857.677,5717.557,0.05224757,0,0,0,0,100,0),
(@PATH,25,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,26,1871.631,5727.291,0.5218816,0,0,0,0,100,0),
(@PATH,27,1865.809,5766.73,0.8069472,0,0,0,0,100,0),
(@PATH,28,1861.136,5769.112,0.6354876,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0000D90C39 .go 1863.071 5721.263 0.5444731

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1853.63,`position_y`=5846.966,`position_z`=2.740726 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1853.63,5846.966,2.740726,0,0,0,0,100,0),
(@PATH,2,1874.7,5836.919,4.813838,0,0,0,0,100,0),
(@PATH,3,1876.592,5812.892,4.801723,0,0,0,0,100,0),
(@PATH,4,1872.844,5797.556,3.118221,0,0,0,0,100,0),
(@PATH,5,1875.815,5806.438,3.974422,0,0,0,0,100,0),
(@PATH,6,1876.563,5816.451,5.334268,0,0,0,0,100,0),
(@PATH,7,1877.032,5828.594,4.914,0,0,0,0,100,0),
(@PATH,8,1862.273,5842.986,4.152772,0,0,0,0,100,0),
(@PATH,9,1853.646,5846.958,2.74155,0,0,0,0,100,0),
(@PATH,10,1849.364,5848.809,2.105818,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0000D90AF7 .go 1853.63 5846.966 2.740726


-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112766;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1821.645,`position_y`=5874.956,`position_z`=2.705887 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1821.645,5874.956,2.705887,0,0,0,0,100,0),
(@PATH,2,1824.808,5874.413,2.800447,0,0,0,0,100,0),
(@PATH,3,1827.45,5854.379,1.631521,0,0,0,0,100,0),
(@PATH,4,1822.537,5840.488,1.119883,0,0,0,0,100,0),
(@PATH,5,1819.79,5826.655,0.8782115,0,0,0,0,100,0),
(@PATH,6,1816.417,5813.835,0.7204496,0,0,0,0,100,0),
(@PATH,7,1816.219,5813.744,0.5043496,0,0,0,0,100,0),
(@PATH,8,1816.581,5813.962,0.5907121,0,0,0,0,100,0),
(@PATH,9,1820.05,5826.836,0.8006111,0,0,0,0,100,0),
(@PATH,10,1828.175,5856.271,1.831071,0,0,0,0,100,0),
(@PATH,11,1828.932,5859.332,2.491501,0,0,0,0,100,0),
(@PATH,12,1816.584,5895.463,0.9250998,0,0,0,0,100,0),
(@PATH,13,1821.645,5874.956,2.705887,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B000159120F .go 1821.645 5874.956 2.705887

UPDATE `creature` SET `spawndist`=10 WHERE  `guid` IN (112682, 112762);

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112761;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1869.091,`position_y`=5953.953,`position_z`=6.38201 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1869.091,5953.953,6.38201,0,0,0,0,100,0),
(@PATH,2,1879.48,5943.066,7.114405,0,0,0,0,100,0),
(@PATH,3,1905.42,5926.519,12.31866,0,0,0,0,100,0),
(@PATH,4,1907.966,5924.864,12.90823,0,0,0,0,100,0),
(@PATH,5,1907.694,5924.906,12.73229,0,0,0,0,100,0),
(@PATH,6,1888.924,5936.15,8.416003,0,0,0,0,100,0),
(@PATH,7,1885.86,5938.519,7.107553,0,0,0,0,100,0),
(@PATH,8,1879.301,5943.302,7.06257,0,0,0,0,100,0),
(@PATH,9,1863.642,5963.351,5.116355,0,0,0,0,100,0),
(@PATH,10,1848.166,5986.37,2.711081,0,0,0,0,100,0),
(@PATH,11,1856.702,5973.741,4.321182,0,0,0,0,100,0),
(@PATH,12,1868.008,5955.694,6.300377,0,0,0,0,100,0),
(@PATH,13,1869.092,5953.951,6.382379,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B00005916B8 .go 1869.091 5953.953 6.38201

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1949.82,`position_y`=5779.809,`position_z`=10.0687 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1949.82,5779.809,10.0687,0,0,0,0,100,0),
(@PATH,2,1949.888,5780.269,10.04539,0,0,0,0,100,0),
(@PATH,3,1959.407,5805.928,11.8103,0,0,0,0,100,0),
(@PATH,4,1955.581,5821.07,13.57725,0,0,0,0,100,0),
(@PATH,5,1949.136,5832.18,12.86915,0,0,0,0,100,0),
(@PATH,6,1947.718,5833.966,12.66496,0,0,0,0,100,0),
(@PATH,7,1944.919,5838.312,12.17096,0,0,0,0,100,0),
(@PATH,8,1945.014,5838.031,12.05043,0,0,0,0,100,0),
(@PATH,9,1945.333,5838.103,12.31259,0,0,0,0,100,0),
(@PATH,10,1950.632,5829.593,14.2812,0,0,0,0,100,0),
(@PATH,11,1959.209,5813.076,12.95494,0,0,0,0,100,0),
(@PATH,12,1958.309,5800.833,11.20766,0,0,0,0,100,0),
(@PATH,13,1953.69,5789.138,10.24553,0,0,0,0,100,0),
(@PATH,14,1952.009,5763.52,9.059128,0,0,0,0,100,0),
(@PATH,15,1949.82,5779.809,10.0687,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0001D91590 .go 1949.82 5779.809 10.0687

-- Pathing for  Entry: 25464 'TDB FORMAT' 
SET @NPC := 132708;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2822.261,`position_y`=5519.366,`position_z`=53.74162 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2822.261,5519.366,53.74162,0,0,0,0,100,0),
(@PATH,2,2823.339,5522.105,53.3661,0,0,0,0,100,0),
(@PATH,3,2816.756,5522.176,52.7483,0,0,0,0,100,0),
(@PATH,4,2815.625,5523.958,52.19855,0,0,0,0,100,0),
(@PATH,5,2815.16,5520.309,52.78535,0,0,0,0,100,0),
(@PATH,6,2820.333,5521.584,53.39899,0,0,0,0,100,0),
(@PATH,7,2824.778,5510.136,55.34394,0,0,0,0,100,0),
(@PATH,8,2815.103,5518.417,53.53315,0,0,0,0,100,0),
(@PATH,9,2819.598,5522.154,52.91368,0,0,0,0,100,0),
(@PATH,10,2822.082,5521.53,53.60404,0,0,0,0,100,0),
(@PATH,11,2818.371,5523.108,52.66743,0,0,0,0,100,0),
(@PATH,12,2819.409,5516.978,53.96194,0,0,0,0,100,0),
(@PATH,13,2823.384,5522.104,53.37409,0,0,0,0,100,0),
(@PATH,14,2825.392,5523.739,52.87629,0,0,0,0,100,0),
(@PATH,15,2815.691,5521.912,52.45197,0,0,0,0,100,0),
(@PATH,16,2814.33,5518.599,52.92414,0,0,0,0,100,0),
(@PATH,17,2815.653,5522.167,52.41706,0,0,0,0,100,0),
(@PATH,18,2821.683,5522.525,53.24909,0,0,0,0,100,0),
(@PATH,19,2822.436,5520.497,53.40412,0,0,0,0,100,0),
(@PATH,20,2822.451,5523.602,53.0274,0,0,0,0,100,0),
(@PATH,21,2815.243,5522.016,52.44831,0,0,0,0,100,0),
(@PATH,22,2818.638,5521.292,53.17999,0,0,0,0,100,0),
(@PATH,23,2822.181,5517.789,54.00129,0,0,0,0,100,0),
(@PATH,24,2822.296,5519.241,53.7021,0,0,0,0,100,0),
(@PATH,25,2816.71,5523.35,52.70033,0,0,0,0,100,0),
(@PATH,26,2819.778,5520.425,53.55138,0,0,0,0,100,0),
(@PATH,27,2824.004,5522.665,53.19855,0,0,0,0,100,0),
(@PATH,28,2822.11,5517.678,54.01472,0,0,0,0,100,0),
(@PATH,29,2823.61,5518.823,53.80622,0,0,0,0,100,0),
(@PATH,30,2824.499,5512.02,55.12739,0,0,0,0,100,0),
(@PATH,31,2824.968,5518.775,54.21228,0,0,0,0,100,0),
(@PATH,32,2822.294,5517.814,53.99824,0,0,0,0,100,0),
(@PATH,33,2818.368,5520.58,53.24421,0,0,0,0,100,0),
(@PATH,34,2822.198,5523.147,52.89338,0,0,0,0,100,0),
(@PATH,35,2819.597,5521.721,53.0246,0,0,0,0,100,0),
(@PATH,36,2822.367,5519.021,53.98109,0,0,0,0,100,0),
(@PATH,37,2826.401,5522.089,53.23542,0,0,0,0,100,0),
(@PATH,38,2816.553,5521.619,52.96187,0,0,0,0,100,0),
(@PATH,39,2825.091,5521.14,53.50007,0,0,0,0,100,0),
(@PATH,40,2822.17,5524.09,52.63996,0,0,0,0,100,0),
(@PATH,41,2823.85,5520.973,53.41511,0,0,0,0,100,0),
(@PATH,42,2823.884,5524.132,52.88813,0,0,0,0,100,0),
(@PATH,43,2823.595,5521.119,53.4554,0,0,0,0,100,0),
(@PATH,44,2822.149,5521.591,53.26643,0,0,0,0,100,0),
(@PATH,45,2825.091,5523.302,52.98078,0,0,0,0,100,0);
-- 0x1C0914476018DE0000000B00005919F4 .go 2822.261 5519.366 53.74162

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122683;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3856.668,`position_y`=6592.438,`position_z`=165.8591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.668,6592.438,165.8591,0,0,0,0,100,0),
(@PATH,2,3845.146,6580.313,167.2839,0,0,0,0,100,0),
(@PATH,3,3819.979,6552.679,171.2212,0,0,0,0,100,0),
(@PATH,4,3834.785,6568.925,168.5641,0,0,0,0,100,0),
(@PATH,5,3856.229,6592.091,166.1844,0,0,0,0,100,0),
(@PATH,6,3856.884,6592.668,166.1273,0,0,0,0,100,0),
(@PATH,7,3856.668,6592.438,165.8591,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923F6 .go 3856.668 6592.438 165.8591

DELETE FROM `creature_formations` WHERE `leaderGUID`=122683;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122683, 122683, 0, 0, 2, 0, 0),
(122683, 122668, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122679;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3877.737,`position_y`=6617.055,`position_z`=165.4812 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3877.737,6617.055,165.4812,0,0,0,0,100,0),
(@PATH,2,3876.591,6615.319,165.2154,0,0,0,0,100,0),
(@PATH,3,3876.513,6615.291,165.0491,0,0,0,0,100,0),
(@PATH,4,3881.765,6622.608,165.9126,0,0,0,0,100,0),
(@PATH,5,3887.004,6630.904,166.6272,0,0,0,0,100,0),
(@PATH,6,3890.648,6642.739,166.3096,0,0,0,0,100,0),
(@PATH,7,3895.043,6655.15,167.9105,0,0,0,0,100,0),
(@PATH,8,3892.582,6650.448,166.6568,0,0,0,0,100,0),
(@PATH,9,3890.725,6641.271,166.7931,0,0,0,0,100,0),
(@PATH,10,3886.259,6630.026,166.4984,0,0,0,0,100,0),
(@PATH,11,3877.767,6616.941,165.558,0,0,0,0,100,0),
(@PATH,12,3876.568,6615.188,165.1826,0,0,0,0,100,0),
(@PATH,13,3876.513,6615.291,165.0491,0,0,0,0,100,0),
(@PATH,14,3881.689,6622.583,165.9073,0,0,0,0,100,0),
(@PATH,15,3886.83,6631.109,166.6665,0,0,0,0,100,0),
(@PATH,16,3890.699,6642.743,166.3585,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923E0 .go 3877.737 6617.055 165.4812

DELETE FROM `creature_formations` WHERE `leaderGUID`=122679;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122679, 122679, 0, 0, 2, 0, 0),
(122679, 122664, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122682;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3802.633,`position_y`=6610.85,`position_z`=160.9254 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3802.633,6610.85,160.9254,0,0,0,0,100,0),
(@PATH,2,3814.249,6608.161,162.6728,0,0,0,0,100,0),
(@PATH,3,3817.92,6607.578,162.962,0,0,0,0,100,0),
(@PATH,4,3817.757,6607.444,162.8091,0,0,0,0,100,0),
(@PATH,5,3809.16,6609.176,161.7681,0,0,0,0,100,0),
(@PATH,6,3794.561,6613.893,159.8145,0,0,0,0,100,0),
(@PATH,7,3787.977,6622.479,157.1806,0,0,0,0,100,0),
(@PATH,8,3777.748,6635.708,153.5259,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C000059215B .go 3802.633 6610.85 160.9254

DELETE FROM `creature_formations` WHERE `leaderGUID`=122682;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122682, 122682, 0, 0, 2, 0, 0),
(122682, 122667, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3876.684,`position_y`=6542.924,`position_z`=175.354 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3876.684,6542.924,175.354,0,0,0,0,100,0),
(@PATH,2,3865.112,6532.595,176.6299,0,0,0,0,100,0),
(@PATH,3,3868.344,6534.336,176.2356,0,0,0,0,100,0),
(@PATH,4,3880.712,6554.647,173.5269,0,0,0,0,100,0),
(@PATH,5,3880.566,6581.678,168.6076,0,0,0,0,100,0),
(@PATH,6,3881.85,6561.938,171.8416,0,0,0,0,100,0),
(@PATH,7,3876.725,6542.939,175.2055,0,0,0,0,100,0),
(@PATH,8,3864.951,6532.556,176.746,0,0,0,0,100,0),
(@PATH,9,3868.344,6534.336,176.2356,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592014 .go 3876.684 6542.924 175.354

DELETE FROM `creature_formations` WHERE `leaderGUID`=122671;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122671, 122671, 0, 0, 2, 0, 0),
(122671, 122660, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122681;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3856.668,`position_y`=6592.438,`position_z`=165.8591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.668,6592.438,165.8591,0,0,0,0,100,0),
(@PATH,2,3845.146,6580.313,167.2839,0,0,0,0,100,0),
(@PATH,3,3819.979,6552.679,171.2212,0,0,0,0,100,0),
(@PATH,4,3834.785,6568.925,168.5641,0,0,0,0,100,0),
(@PATH,5,3856.229,6592.091,166.1844,0,0,0,0,100,0),
(@PATH,6,3856.884,6592.668,166.1273,0,0,0,0,100,0),
(@PATH,7,3856.668,6592.438,165.8591,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923F6 .go 3856.668 6592.438 165.8591

DELETE FROM `creature_formations` WHERE `leaderGUID`=122681;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122681, 122681, 0, 0, 2, 0, 0),
(122681, 122666, 4, 0, 2, 0, 0);

UPDATE `creature` SET `spawndist`=15 WHERE  `guid`=122549;
UPDATE `creature` SET `spawndist`=20 WHERE  `guid`=122548;

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3772.382,`position_y`=6700.643,`position_z`=150.745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3772.382,6700.643,150.745,0,0,0,0,100,0),
(@PATH,2,3765.955,6706.445,152.0959,0,0,0,0,100,0),
(@PATH,3,3760.302,6711.588,152.1358,0,0,0,0,100,0),
(@PATH,4,3750.747,6726.564,151.7103,0,0,0,0,100,0),
(@PATH,5,3749.879,6729.181,151.658,0,0,0,0,100,0),
(@PATH,6,3750.81,6726.225,151.6613,0,0,0,0,100,0),
(@PATH,7,3771.484,6701.582,151.0565,0,0,0,0,100,0),
(@PATH,8,3772.745,6700.572,150.9297,0,0,0,0,100,0),
(@PATH,9,3772.382,6700.643,150.745,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592493 .go 3772.382 6700.643 150.745

DELETE FROM `creature_formations` WHERE `leaderGUID`=122675;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122675, 122675, 0, 0, 2, 0, 0),
(122675, 122661, 4, 0, 2, 0, 0);


-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122678;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3765.189,`position_y`=6646.188,`position_z`=152.2007 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3765.189,6646.188,152.2007,0,0,0,0,100,0),
(@PATH,2,3761.339,6649.458,151.591,0,0,0,0,100,0),
(@PATH,3,3761.412,6649.275,151.5081,0,0,0,0,100,0),
(@PATH,4,3775.332,6638.132,152.7523,0,0,0,0,100,0),
(@PATH,5,3784.681,6626.98,155.8878,0,0,0,0,100,0),
(@PATH,6,3791.935,6616.86,158.9415,0,0,0,0,100,0),
(@PATH,7,3802.772,6610.692,160.7068,0,0,0,0,100,0),
(@PATH,8,3814.205,6608.264,162.5391,0,0,0,0,100,0),
(@PATH,9,3817.96,6607.651,162.9075,0,0,0,0,100,0),
(@PATH,10,3817.757,6607.444,162.8091,0,0,0,0,100,0),
(@PATH,11,3809.104,6609.054,161.8425,0,0,0,0,100,0),
(@PATH,12,3794.503,6613.823,159.8757,0,0,0,0,100,0),
(@PATH,13,3788.144,6622.311,157.2462,0,0,0,0,100,0),
(@PATH,14,3777.916,6635.792,153.5504,0,0,0,0,100,0),
(@PATH,15,3765.363,6646.322,152.2002,0,0,0,0,100,0),
(@PATH,16,3761.535,6649.459,151.5641,0,0,0,0,100,0),
(@PATH,17,3761.412,6649.275,151.5081,0,0,0,0,100,0),
(@PATH,18,3775.165,6638.005,152.7578,0,0,0,0,100,0),
(@PATH,19,3784.59,6626.891,155.6862,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592B08 .go 3765.189 6646.188 152.2007

DELETE FROM `creature_formations` WHERE `leaderGUID`=122678;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122678, 122678, 0, 0, 2, 0, 0),
(122678, 122663, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122684;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3726.047,`position_y`=6604.721,`position_z`=171.6309 WHERE `guid` IN (@NPC, 122669);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3726.047,6604.721,171.6309,0,0,0,0,100,0),
(@PATH,2,3737.404,6582.727,172.9987,0,0,0,0,100,0),
(@PATH,3,3752.602,6559.511,175.07,0,0,0,0,100,0),
(@PATH,4,3757.825,6548.518,176.1503,0,0,0,0,100,0),
(@PATH,5,3741.299,6576.517,173.8608,0,0,0,0,100,0),
(@PATH,6,3731.644,6593.12,172.3642,0,0,0,0,100,0),
(@PATH,7,3725.372,6606.514,171.4347,0,0,0,0,100,0),
(@PATH,8,3726.047,6604.721,171.6309,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592BE0 .go 3726.047 6604.721 171.6309

DELETE FROM `creature_formations` WHERE `leaderGUID`=122684;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122684, 122684, 0, 0, 2, 0, 0),
(122684, 122669, 4, 0, 2, 0, 0);

-- Coldarra Spellweaver SAI
SET @ENTRY := 25722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,600,5300,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellweaver - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Out of Combat - Cast 'Arcane Channeling'");

-- Coldarra Spellbinder SAI
SET @ENTRY := 25719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3900,5800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,1700,13500,172100,172100,11,50583,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 'Summon Frozen Spheres'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Out of Combat - Cast 'Arcane Channeling'");

-- Inquisitor Caleras SAI
SET @ENTRY := 25720;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,6200,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,9800,21300,18400,18400,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Out of Combat - Cast 'Arcane Channeling'");

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122676;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3839.049,`position_y`=6746.131,`position_z`=150.8772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3839.049,6746.131,150.8772,0,0,0,0,100,0),
(@PATH,2,3838.777,6746.075,150.6292,0,0,0,0,100,0),
(@PATH,3,3838.793,6746.344,150.9143,0,0,0,0,100,0),
(@PATH,4,3826.649,6753.63,150.9941,0,0,0,0,100,0),
(@PATH,5,3811.169,6750.051,150.4951,0,0,0,0,100,0),
(@PATH,6,3811.172,6750.112,150.299,0,0,0,0,100,0),
(@PATH,7,3811.489,6750.411,150.5408,0,0,0,0,100,0),
(@PATH,8,3826.923,6753.677,150.8951,0,0,0,0,100,0),
(@PATH,9,3839.046,6746.012,150.8834,0,0,0,0,100,0),
(@PATH,10,3838.777,6746.075,150.6292,0,0,0,0,100,0),
(@PATH,11,3838.828,6746.229,150.9149,0,0,0,0,100,0),
(@PATH,12,3826.723,6753.648,150.7468,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005924AC .go 3839.049 6746.131 150.8772

DELETE FROM `creature_formations` WHERE `leaderGUID`=122676;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122676, 122676, 0, 0, 2, 0, 0),
(122676, 122662, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122680;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3863.127,`position_y`=6753.518,`position_z`=150.5189 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3863.127,6753.518,150.5189,0,0,0,0,100,0),
(@PATH,2,3860.453,6741.29,150.7381,0,0,0,0,100,0),
(@PATH,3,3875.973,6736.009,151.0474,0,0,0,0,100,0),
(@PATH,4,3886.431,6727.403,151.3167,0,0,0,0,100,0),
(@PATH,5,3886.167,6727.198,151.1895,0,0,0,0,100,0),
(@PATH,6,3886.265,6727.485,151.3074,0,0,0,0,100,0),
(@PATH,7,3875.836,6736.28,151.0612,0,0,0,0,100,0),
(@PATH,8,3860.38,6741.66,150.7448,0,0,0,0,100,0),
(@PATH,9,3862.974,6753.514,150.6811,0,0,0,0,100,0),
(@PATH,10,3867.98,6753.716,150.6562,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005924B3 .go 3863.127 6753.518 150.5189

DELETE FROM `creature_formations` WHERE `leaderGUID`=122680;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122680, 122680, 0, 0, 2, 0, 0),
(122680, 122665, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122685;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3908.275,`position_y`=6757.146,`position_z`=150.8441 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3908.275,6757.146,150.8441,0,0,0,0,100,0),
(@PATH,2,3893.045,6770.693,150.8547,0,0,0,0,100,0),
(@PATH,3,3880.528,6782.54,150.7091,0,0,0,0,100,0),
(@PATH,4,3880.478,6782.537,150.6073,0,0,0,0,100,0),
(@PATH,5,3880.76,6782.527,150.8653,0,0,0,0,100,0),
(@PATH,6,3893.34,6770.562,150.8441,0,0,0,0,100,0),
(@PATH,7,3908.603,6756.879,150.896,0,0,0,0,100,0),
(@PATH,8,3925.911,6721.284,153.766,0,0,0,0,100,0),
(@PATH,9,3920.531,6713.925,153.515,0,0,0,0,100,0),
(@PATH,10,3906.757,6706.551,151.9455,0,0,0,0,100,0),
(@PATH,11,3894.688,6701.577,151.5052,0,0,0,0,100,0),
(@PATH,12,3894.756,6701.676,151.4043,0,0,0,0,100,0),
(@PATH,13,3916.371,6709.826,152.6267,0,0,0,0,100,0),
(@PATH,14,3921.297,6714.496,153.5745,0,0,0,0,100,0),
(@PATH,15,3929.399,6745.379,151.6542,0,0,0,0,100,0),
(@PATH,16,3919.581,6752.038,150.9705,0,0,0,0,100,0),
(@PATH,17,3908.269,6757.149,150.8441,0,0,0,0,100,0),
(@PATH,18,3893.047,6770.691,150.8547,0,0,0,0,100,0),
(@PATH,19,3880.51,6782.556,150.7091,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005932EB .go 3908.275 6757.146 150.8441

DELETE FROM `creature_formations` WHERE `leaderGUID`=122685;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122685, 122685, 0, 0, 2, 0, 0),
(122685, 122670, 4, 0, 2, 0, 0);

UPDATE `creature` SET `spawndist`=20 WHERE  `guid`=122550;

UPDATE `creature` SET `spawndist`=15 WHERE `id`=25721;

-- Pathing for  Entry: 25717 'TDB FORMAT' 
SET @NPC := 122652;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4071.958,`position_y`=7059.748,`position_z`=166.7365 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4071.958,7059.748,166.7365,0,0,0,0,100,0),
(@PATH,2,4072.932,7060.661,166.5419,0,0,0,0,100,0),
(@PATH,3,4087.155,7066.582,166.7904,0,0,0,0,100,0),
(@PATH,4,4086.809,7066.466,166.6568,0,0,0,0,100,0),
(@PATH,5,4086.776,7066.416,166.7174,0,0,0,0,100,0),
(@PATH,6,4062.645,7049.889,167.7236,0,0,0,0,100,0),
(@PATH,7,4054.082,7027.509,166.672,0,0,0,0,100,0),
(@PATH,8,4059.144,7041.778,167.9961,0,0,0,0,100,0),
(@PATH,9,4071.981,7059.813,166.7345,0,0,0,0,100,0);
-- 0x1C09144760191D4000000C00005932C9 .go 4071.958 7059.748 166.7365

-- General Cerulean SAI
SET @ENTRY := 25716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10200,13600,10000,12000,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Cerulean - In Combat - Cast 'Frost Shock'"),
(@ENTRY,0,1,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Cerulean - Out of Combat - Cast 'Arcane Channeling'");

UPDATE `creature` SET `spawndist`=20 WHERE  `guid` IN (122547, 122551);

-- Pathing for  Entry: 25713 'TDB FORMAT' 
SET @NPC := 122611;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3820.672,`position_y`=7153.959,`position_z`=163.4258 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3820.672,7153.959,163.4258,0,0,0,0,100,0),
(@PATH,2,3816.873,7173.65,161.3409,0,0,0,0,100,0),
(@PATH,3,3819.527,7160.829,162.4046,0,0,0,0,100,0),
(@PATH,4,3821.152,7145.412,164.2622,0,0,0,0,100,0),
(@PATH,5,3820.075,7133.457,165.5549,0,0,0,0,100,0),
(@PATH,6,3819.108,7129.334,166.0357,0,0,0,0,100,0),
(@PATH,7,3819.164,7129.457,165.8505,0,0,0,0,100,0),
(@PATH,8,3820.722,7140.354,165.1108,0,0,0,0,100,0),
(@PATH,9,3820.762,7154.072,163.3669,0,0,0,0,100,0),
(@PATH,10,3816.832,7173.758,161.5131,0,0,0,0,100,0);
-- 0x1C09144760191C4000000C0000590957 .go 3820.672 7153.959 163.4258

-- Pathing for  Entry: 25713 'TDB FORMAT' 
SET @NPC := 122643;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3715.234,`position_y`=7159.224,`position_z`=160.5815 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3715.234,7159.224,160.5815,0,0,0,0,100,0),
(@PATH,2,3712.465,7168.071,160.3927,0,0,0,0,100,0),
(@PATH,3,3711.697,7180.112,160.1553,0,0,0,0,100,0),
(@PATH,4,3712.53,7195.874,160.5102,0,0,0,0,100,0),
(@PATH,5,3712.202,7195.61,160.2491,0,0,0,0,100,0),
(@PATH,6,3712.354,7195.505,160.5099,0,0,0,0,100,0),
(@PATH,7,3711.637,7179.952,160.1052,0,0,0,0,100,0),
(@PATH,8,3712.478,7167.976,160.2884,0,0,0,0,100,0),
(@PATH,9,3715.501,7158.848,160.5296,0,0,0,0,100,0),
(@PATH,10,3715.303,7158.94,160.4226,0,0,0,0,100,0),
(@PATH,11,3715.255,7159.067,160.5904,0,0,0,0,100,0),
(@PATH,12,3712.359,7168.119,160.3639,0,0,0,0,100,0),
(@PATH,13,3711.62,7180.215,160.1398,0,0,0,0,100,0),
(@PATH,14,3712.332,7195.925,160.5264,0,0,0,0,100,0);
-- 0x1C09144760191C4000000C0000592DB7 .go 3715.234 7159.224 160.5815

-- Warbringer Goredrak SAI
SET @ENTRY := 25712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,200,16900,21200,11,50534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 'Power Sap'"),
(@ENTRY,0,1,0,0,0,100,0,5900,6700,16800,21200,11,50545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 'Arcane Blast'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warbringer Goredrak - Out of Combat - Cast 'Arcane Channeling'");

UPDATE `creature` SET `spawndist`=10 WHERE  `guid`=122806;
UPDATE `creature` SET `spawndist`=15 WHERE  `guid` IN (122824, 122545);
-- Pathing for  Entry: 25709 'TDB FORMAT' 
SET @NPC := 122562;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3821.72,`position_y`=7226.874,`position_z`=165.7941 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3821.72,7226.874,165.7941,0,0,0,0,100,0),
(@PATH,2,3840.45,7225.532,167.5351,0,0,0,0,100,0),
(@PATH,3,3854.693,7219.692,168.801,0,0,0,0,100,0),
(@PATH,4,3872.789,7201.074,168.0432,0,0,0,0,100,0),
(@PATH,5,3877.849,7192.911,167.4686,0,0,0,0,100,0),
(@PATH,6,3853.227,7162.686,166.2984,0,0,0,0,100,0),
(@PATH,7,3831.403,7190.82,162.3192,0,0,0,0,100,0),
(@PATH,8,3821.685,7226.815,165.7664,0,0,0,0,100,0);
-- 0x1C09144760191B4000000C00005929B2 .go 3821.72 7226.874 165.7941

-- Pathing for  Entry: 25717 'TDB FORMAT' 
SET @NPC := 122655;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4158.797,`position_y`=7025.598,`position_z`=165.7506 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4158.797,7025.598,165.7506,0,0,0,0,100,0),
(@PATH,2,4158.771,7025.846,166.0288,0,0,0,0,100,0),
(@PATH,3,4149.362,7040.18,166.0216,0,0,0,0,100,0),
(@PATH,4,4141.375,7046.86,165.9186,0,0,0,0,100,0),
(@PATH,5,4128.7,7050.973,165.6986,0,0,0,0,100,0),
(@PATH,6,4128.795,7050.833,165.5718,0,0,0,0,100,0),
(@PATH,7,4129.043,7050.743,165.6772,0,0,0,0,100,0),
(@PATH,8,4141.438,7046.565,166.0175,0,0,0,0,100,0),
(@PATH,9,4149.486,7040.006,166.0294,0,0,0,0,100,0),
(@PATH,10,4159.022,7025.654,165.9743,0,0,0,0,100,0);
-- 0x1C09144760191D4000000C000059272B .go 4158.797 7025.598 165.7506
--
SET @NPC:= 25968;
UPDATE `creature_template` SET `VehicleId`=30 WHERE `entry`=@NPC;
DELETE FROM `vehicle_template_accessory` where `entry` in (@NPC) AND `accessory_entry` IN (25801);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@NPC,25801,0,0,'Lunchbox',8,0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = @NPC;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@NPC, 46598, 1, 0);

-- Nedar, Lord of Rhinos SAI
SET @ENTRY := 25801;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Say Line 0 (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,4,1,100,1,0,0,0,0,11,41440,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Cast 'Shoot' (Phase 1) (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,5,30,3500,4100,11,41440,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 5-30 Range - Cast 'Shoot' (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 30-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 9-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 5-30 Range - Disable Combat Movement (Phase 1)");
-- Complete the Broadcast_text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@ENTRY, 0, 0, 'Your impetuousness will be your end!', 12, 0, 100, 0, 0, 0, 'Nedar', 25103),
(@ENTRY, 0, 1, 'You dare challenge Nedar, lord of the tundral!?', 12, 0, 100, 0, 0, 0, 'Nedar', 25102),
(@ENTRY, 0, 2, 'You don''t stand a chance!', 12, 0, 100, 0, 0, 0, 'Nedar', 25104);

-- Pathing for  Entry: 25968 'TDB FORMAT' 
SET @NPC := 106302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3170.232,`position_y`=5968.757,`position_z`=96.36165 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3170.232,5968.757,96.36165,0,0,0,0,100,0),
(@PATH,2,3159.33,5950.815,95.96857,0,0,0,0,100,0),
(@PATH,3,3162.685,5902.838,96.0918,0,0,0,0,100,0),
(@PATH,4,3169.452,5888.983,97.71611,0,0,0,0,100,0),
(@PATH,5,3204.079,5874.618,97.02065,0,0,0,0,100,0),
(@PATH,6,3238.726,5868.98,94.07452,0,0,0,0,100,0),
(@PATH,7,3266.804,5867.507,86.87187,0,0,0,0,100,0),
(@PATH,8,3300.308,5874.12,83.72194,0,0,0,0,100,0),
(@PATH,9,3328.993,5853.078,78.86817,0,0,0,0,100,0),
(@PATH,10,3344.677,5812.18,67.82541,0,0,0,0,100,0),
(@PATH,11,3341.184,5774.667,61.2993,0,0,0,0,100,0),
(@PATH,12,3357.205,5767.466,65.42284,0,0,0,0,100,0),
(@PATH,13,3357.227,5799.264,67.74834,0,0,0,0,100,0),
(@PATH,14,3359.967,5824.072,71.90356,0,0,0,0,100,0),
(@PATH,15,3354.479,5873.997,76.9686,0,0,0,0,100,0),
(@PATH,16,3341.863,5907.724,79.92758,0,0,0,0,100,0),
(@PATH,17,3316.034,5925.089,85.70946,0,0,0,0,100,0),
(@PATH,18,3293.812,5947.116,82.76896,0,0,0,0,100,0);
-- 0x2009144760195C0000000C000057E949 .go 3170.232 5968.757 96.36165
--
UPDATE `creature` SET `MovementType`=0 WHERE  `guid` IN (126701,126703,126711);
UPDATE `creature` SET `equipment_id`=0 WHERE `id` IN (12237,  12224);
--
UPDATE `creature` SET `MovementType`=0 WHERE `guid` = 58021;
UPDATE `creature` SET `MovementType`=1 WHERE `guid` IN (122545, 122824);
--
UPDATE `creature_template` SET `unit_class`=4 WHERE  `entry`=32535;
UPDATE `creature_template_addon` SET`auras`="" WHERE`entry` IN (26608, 31306); -- vehicle auras appear only when the npc ride a vehicle or when he's mounted
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=35427;
--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=49947;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 49947, 0, 0, 31, 0, 3, 19871, 0, 0, 0, 0, '', 'Laser - only targets Bunny');

-- Scavenge-bot 004-A8 SAI
SET @ENTRY := 25752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` >=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,1,0,100,0,5000,5000,15000,20000,11,49947,0,0,0,0,0,19,19871,25,0,0,0,0,0,"Scavenge-bot 004-A8 - Out of Combat - Cast 'Cutting Laser'"),
(@ENTRY,0,4,0,1,0,100,0,20000,25000,35000,40000,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scavenge-bot 004-A8 - Out of Combat - Play Emote 35");
-- Pathing for Stonebreaker Grunt Entry: 18973 'TDB FORMAT' 
SET @NPC := 68131;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2562.284,`position_y`=4397.473,`position_z`=58.68661 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2562.284,4397.473,58.68661,0,0,0,0,100,0),
(@PATH,2,-2551.224,4407.652,53.44283,0,0,0,0,100,0),
(@PATH,3,-2547.335,4405.842,52.35535,0,0,0,0,100,0),
(@PATH,4,-2543.202,4397.742,52.17545,0,0,0,0,100,0),
(@PATH,5,-2547.734,4388.876,52.18408,0,0,0,0,100,0),
(@PATH,6,-2556.611,4386.977,52.1886,0,0,0,0,100,0),
(@PATH,7,-2556.627,4386.753,51.9386,0,0,0,0,100,0),
(@PATH,8,-2556.481,4387.06,52.1886,0,0,0,0,100,0),
(@PATH,9,-2543.486,4397,52.17455,0,0,0,0,100,0),
(@PATH,10,-2547.152,4405.732,52.17457,0,0,0,0,100,0),
(@PATH,11,-2558.628,4405.742,57.89645,0,0,0,0,100,0),
(@PATH,12,-2562.429,4397.533,58.73559,0,0,0,0,100,0),
(@PATH,13,-2562.816,4394.701,58.72124,0,0,0,0,100,0),
(@PATH,14,-2547.645,4388.162,58.39926,0,0,0,0,100,0),
(@PATH,15,-2545.306,4391.472,58.38942,0,0,0,0,100,0),
(@PATH,16,-2543.268,4397.77,58.69866,0,0,0,0,100,0),
(@PATH,17,-2543.174,4397.481,58.44216,0,0,0,0,100,0),
(@PATH,18,-2545.374,4391.247,58.40757,0,0,0,0,100,0),
(@PATH,19,-2554.22,4387.671,58.65759,0,0,0,0,100,0),
(@PATH,20,-2562.223,4394.01,58.45053,0,0,0,0,100,0),
(@PATH,21,-2562.396,4397.497,58.69535,0,0,0,0,100,0),
(@PATH,22,-2551.103,4407.721,53.44612,0,0,0,0,100,0),
(@PATH,23,-2547.447,4405.818,52.24909,0,0,0,0,100,0),
(@PATH,24,-2543.19,4397.657,52.17642,0,0,0,0,100,0),
(@PATH,25,-2547.777,4388.548,52.18584,0,0,0,0,100,0),
(@PATH,26,-2556.725,4387.103,52.1886,0,0,0,0,100,0),
(@PATH,27,-2556.627,4386.753,51.9386,0,0,0,0,100,0),
(@PATH,28,-2556.351,4386.949,52.1886,0,0,0,0,100,0),
(@PATH,29,-2543.485,4397.102,52.17455,0,0,0,0,100,0),
(@PATH,30,-2547.133,4405.784,52.17457,0,0,0,0,100,0),
(@PATH,31,-2558.618,4405.514,57.89614,0,0,0,0,100,0),
(@PATH,32,-2562.308,4397.42,58.72334,0,0,0,0,100,0),
(@PATH,33,-2562.909,4394.518,58.71896,0,0,0,0,100,0),
(@PATH,34,-2547.697,4388.187,58.39987,0,0,0,0,100,0),
(@PATH,35,-2545.525,4391.353,58.41209,0,0,0,0,100,0),
(@PATH,36,-2543.177,4397.777,58.7028,0,0,0,0,100,0),
(@PATH,37,-2543.174,4397.481,58.44216,0,0,0,0,100,0),
(@PATH,38,-2545.295,4391.392,58.40459,0,0,0,0,100,0),
(@PATH,39,-2554.367,4387.682,58.65977,0,0,0,0,100,0),
(@PATH,40,-2562.382,4393.967,58.45837,0,0,0,0,100,0);
-- 0x1C3930424012874000002C0003BF2EBC .go -2562.284 4397.473 58.68661

-- Pathing for Stonebreaker Grunt Entry: 18973 'TDB FORMAT' 
SET @NPC := 68132;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2582.699,`position_y`=4367.507,`position_z`=27.14433 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2582.699,4367.507,27.14433,240000,0,0,0,100,0),
(@PATH,2,-2595.828,4382.915,29.9575,0,0,0,0,100,0),
(@PATH,3,-2613.849,4391.314,33.12907,0,0,0,0,100,0),
(@PATH,4,-2632.729,4386.462,35.28672,0,0,0,0,100,0),
(@PATH,5,-2636.813,4385.448,35.57519,0,0,0,0,100,0),
(@PATH,6,-2667.237,4407.722,35.60794,0,0,0,0,100,0),
(@PATH,7,-2701.92,4386.847,28.3668,0,0,0,0,100,0),
(@PATH,8,-2708.737,4383.311,26.62656,0,0,0,0,100,0),
(@PATH,9,-2671.687,4406.917,35.27893,0,0,0,0,100,0),
(@PATH,10,-2638.984,4412.332,35.20811,0,0,0,0,100,0),
(@PATH,11,-2613.415,4394.945,33.2278,0,0,0,0,100,0),
(@PATH,12,-2591.59,4381.07,29.3395,0,0,0,0,100,0);
-- 0x1C3930424012874000002C00023F2EBA .go -2582.699 4367.507 27.14433

-- Pathing for Stonebreaker Peon Entry: 19048 'TDB FORMAT' 
SET @NPC := 68353;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2607.763,`position_y`=4381.312,`position_z`=33.58602 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2607.763,4381.312,33.58602,0,0,0,0,100,0),
(@PATH,2,-2633.11,4379.769,35.77549,0,0,0,0,100,0),
(@PATH,3,-2634.318,4379.514,35.83887,0,0,0,0,100,0),
(@PATH,4,-2647.237,4382.08,36.08328,0,240000,0,0,100,0),
(@PATH,5,-2642.319,4381.9,35.72264,0,0,0,0,100,0),
(@PATH,6,-2642.08,4381.872,35.9688,0,0,0,0,100,0),
(@PATH,7,-2607.333,4387.602,31.9885,0,0,0,0,100,0),
(@PATH,8,-2603.056,4389.318,31.18134,0,0,0,0,100,0),
(@PATH,9,-2598.985,4391.519,30.64458,0,240000,0,0,100,0),
(@PATH,10,-2592.19,4391.983,30.50177,0,240000,0,0,100,0),
(@PATH,11,-2568.814,4388.118,33.5708,0,0,0,0,100,0),
(@PATH,12,-2567.081,4387.359,34.20564,0,240000,0,0,100,0);
-- 0x1C39304240129A0000002C00023F2EBC .go -2607.763 4381.312 33.58602

-- Update Keb'ezil's movement, he should be running around as an imp.
UPDATE `creature` SET `MovementType`=1 WHERE `guid`=66944;
UPDATE `creature` SET `spawndist`=5 WHERE `guid`=66944;

-- Update coordinates of Ru'zah
UPDATE `creature` SET `position_x`=-2627.9, `position_y`=4486.034, `position_z`=36.21471 WHERE `guid`=74329;
-- Urdak SAI
SET @ENTRY := 18541;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Power of Kran'aish' (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - On Aggro - Cast 'Lightning Bolt' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - Within 0-40 Range - Cast 'Lightning Bolt' (No Repeat)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,12000,16000,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Arakkoa Blast' (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,10000,14000,18000,25000,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Enveloping Winds' (Phase 1) (No Repeat)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Pathing for Urdak Entry: 18541 'TDB FORMAT' 
SET @NPC := 66701;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2531.757,`position_y`=5367.723,`position_z`=27.48038 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2531.757,5367.723,27.48038,0,0,0,0,100,0),
(@PATH,2,-2522.244,5363.866,27.5043,0,0,0,0,100,0),
(@PATH,3,-2511.568,5370.136,27.19551,0,0,0,0,100,0),
(@PATH,4,-2509.842,5376.426,27.17996,0,0,0,0,100,0),
(@PATH,5,-2514.843,5388.665,27.42471,0,0,0,0,100,0),
(@PATH,6,-2525.896,5389.706,27.21724,0,0,0,0,100,0),
(@PATH,7,-2531.956,5386.355,27.44649,0,0,0,0,100,0),
(@PATH,8,-2535.825,5377.078,27.48491,0,0,0,0,100,0);
-- 0x1C39304240121B400000D00000395D5F .go -2531.757 5367.723 27.48038

DELETE FROM `creature_formations` WHERE `leaderGUID`=66960;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(66960, 66960, 0, 0, 2),
(66960, 57334, 3, 270, 2);

-- Pathing for Shadowy Hunter Entry: 18718 'TDB FORMAT' 
SET @NPC := 66960;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2399.251,`position_y`=4948.647,`position_z`=33.51818 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2399.251,4948.647,33.51818,0,0,0,0,100,0),
(@PATH,2,-2382.013,4957.111,36.26661,0,0,0,0,100,0),
(@PATH,3,-2386.387,4964.082,33.5477,0,0,0,0,100,0),
(@PATH,4,-2396.421,4967.332,32.63216,0,0,0,0,100,0),
(@PATH,5,-2404.207,4968.344,32.13279,0,0,0,0,100,0),
(@PATH,6,-2411.476,4973.782,31.9511,0,0,0,0,100,0),
(@PATH,7,-2419.75,5004.045,29.51139,0,0,0,0,100,0),
(@PATH,8,-2423.043,5009.497,29.88427,0,0,0,0,100,0),
(@PATH,9,-2425.305,5012.542,29.87346,0,0,0,0,100,0),
(@PATH,10,-2452.268,5014.185,28.21556,0,0,0,0,100,0),
(@PATH,11,-2455.99,5026.977,25.38416,0,0,0,0,100,0),
(@PATH,12,-2461.66,5046.541,20.78516,0,0,0,0,100,0),
(@PATH,13,-2468.601,5062.008,17.91999,0,0,0,0,100,0),
(@PATH,14,-2471.484,5074.755,15.08363,0,0,0,0,100,0),
(@PATH,15,-2462.648,5034.314,23.94722,0,0,0,0,100,0),
(@PATH,16,-2458.38,5013.544,27.85468,0,0,0,0,100,0),
(@PATH,17,-2460.833,5004.856,28.65945,0,0,0,0,100,0),
(@PATH,18,-2468.316,4978.999,31.72539,0,0,0,0,100,0),
(@PATH,19,-2469.694,4960.631,33.31852,0,0,0,0,100,0),
(@PATH,20,-2466.243,4944.808,34.89827,0,0,0,0,100,0),
(@PATH,21,-2466.676,4930.218,36.72472,0,0,0,0,100,0),
(@PATH,22,-2473.81,4922.928,38.69386,0,0,0,0,100,0),
(@PATH,23,-2476.339,4921.196,39.03951,0,0,0,0,100,0),
(@PATH,24,-2486.696,4911.087,38.99028,0,0,0,0,100,0),
(@PATH,25,-2488.085,4899.312,39.16518,0,0,0,0,100,0),
(@PATH,26,-2466.59,4887.837,36.24532,0,0,0,0,100,0),
(@PATH,27,-2459.039,4893.131,34.30416,0,0,0,0,100,0),
(@PATH,28,-2456.6,4895.325,33.89172,0,0,0,0,100,0),
(@PATH,29,-2455.763,4912.572,33.6131,0,0,0,0,100,0),
(@PATH,30,-2459.973,4922.549,33.84817,0,0,0,0,100,0),
(@PATH,31,-2454.409,4941.216,34.89568,0,0,0,0,100,0),
(@PATH,32,-2453.032,4942.258,34.88249,0,0,0,0,100,0),
(@PATH,33,-2441.288,4944.204,34.91498,0,0,0,0,100,0),
(@PATH,34,-2424.706,4957.187,34.11639,0,0,0,0,100,0),
(@PATH,35,-2420.334,4960.088,33.7532,0,0,0,0,100,0),
(@PATH,36,-2399.827,4949.04,33.55933,0,0,0,0,100,0);
-- 0x1C393042401247800000D80000395139 .go -2399.251 4948.647 33.51818

DELETE FROM `creature_formations` WHERE `leaderGUID`=66959;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(66959, 66959, 0, 0, 2),
(66959, 57324, 3, 270, 2);

-- Pathing for Shadowy Hunter Entry: 18718 'TDB FORMAT' 
SET @NPC := 66959;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2458.59,`position_y`=4883.933,`position_z`=34.63649 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2458.59,4883.933,34.63649,0,0,0,0,100,0),
(@PATH,2,-2454.139,4881.942,34.18031,0,0,0,0,100,0),
(@PATH,3,-2441.338,4867.939,34.96668,0,0,0,0,100,0),
(@PATH,4,-2447.259,4881.18,33.54724,0,0,0,0,100,0),
(@PATH,5,-2454.204,4888.805,33.82166,0,0,0,0,100,0),
(@PATH,6,-2455.784,4897.667,33.77719,0,0,0,0,100,0),
(@PATH,7,-2455.145,4910.682,33.57897,0,0,0,0,100,0),
(@PATH,8,-2459.188,4921.684,33.73078,0,0,0,0,100,0),
(@PATH,9,-2455.591,4939.817,34.61909,0,0,0,0,100,0),
(@PATH,10,-2453.116,4941.684,35.0243,0,0,0,0,100,0),
(@PATH,11,-2443.437,4943.616,34.76263,0,0,0,0,100,0),
(@PATH,12,-2431.095,4940.732,36.18304,0,0,0,0,100,0),
(@PATH,13,-2422.104,4931.316,35.36322,0,0,0,0,100,0),
(@PATH,14,-2418.187,4924.916,36.3769,0,0,0,0,100,0),
(@PATH,15,-2425.994,4937.722,36.55001,0,0,0,0,100,0),
(@PATH,16,-2430.061,4945.802,35.26893,0,0,0,0,100,0),
(@PATH,17,-2429.3,4947.917,34.86908,0,0,0,0,100,0),
(@PATH,18,-2424.078,4963.271,33.09982,0,0,0,0,100,0),
(@PATH,19,-2421.393,4974.704,31.43381,0,0,0,0,100,0),
(@PATH,20,-2421.332,4975.644,31.21901,0,0,0,0,100,0),
(@PATH,21,-2418.137,5000.565,30.00104,0,0,0,0,100,0),
(@PATH,22,-2417.527,5002.019,29.37036,0,0,0,0,100,0),
(@PATH,23,-2416.402,5010.205,29.2325,0,0,0,0,100,0),
(@PATH,24,-2417.669,5014.722,28.97691,0,0,0,0,100,0),
(@PATH,25,-2428.226,5012.224,29.9898,0,0,0,0,100,0),
(@PATH,26,-2444.966,5008.044,29.51899,0,0,0,0,100,0),
(@PATH,27,-2453.993,5013.485,28.19345,0,0,0,0,100,0),
(@PATH,28,-2456.664,5023.554,26.07574,0,0,0,0,100,0),
(@PATH,29,-2459.761,5038.568,22.79576,0,0,0,0,100,0),
(@PATH,30,-2465.731,5053.402,19.17121,0,0,0,0,100,0),
(@PATH,31,-2467.348,5032.213,24.09672,0,0,0,0,100,0),
(@PATH,32,-2467.405,5023.126,25.73068,0,0,0,0,100,0),
(@PATH,33,-2467.814,5012.714,28.07976,0,0,0,0,100,0),
(@PATH,34,-2470.525,4997.041,29.28029,0,0,0,0,100,0),
(@PATH,35,-2471.126,4980.461,31.38793,0,0,0,0,100,0),
(@PATH,36,-2477.811,4974.808,32.3695,0,0,0,0,100,0),
(@PATH,37,-2497.777,4966.848,35.28411,0,0,0,0,100,0),
(@PATH,38,-2506.064,4953.317,38.70324,0,0,0,0,100,0),
(@PATH,39,-2510.001,4942.142,39.95487,0,0,0,0,100,0),
(@PATH,40,-2510.834,4938.938,40.30884,0,0,0,0,100,0),
(@PATH,41,-2510.035,4921.547,39.56293,0,0,0,0,100,0),
(@PATH,42,-2510.577,4918.453,39.31087,0,0,0,0,100,0),
(@PATH,43,-2507.691,4905.567,39.31522,0,0,0,0,100,0),
(@PATH,44,-2500.221,4899.546,39.09933,0,0,0,0,100,0),
(@PATH,45,-2490.795,4896.659,39.47167,0,0,0,0,100,0);
-- 0x1C393042401247800000D800003955BB .go -2458.59 4883.933 34.63649

-- Remove 1 too many 'Shadowy Executioner'
DELETE FROM `creature` WHERE `guid`=57323;
--
DELETE FROM `disables` WHERE `sourceType` =0 AND `entry` IN (71599, 71024) AND `flags`=64;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 71599, 64, '', '', 'Ignore LOS for Cosmetic - Explosion (Chemical Wagon)'),
(0, 71024, 64, '', '', 'Ignore LOS for Throw Bomb');
--
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=26191;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(26191, 46978, 2, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=26191 AND `SourceEntry`=46978;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 26191, 46978, 0, 0, 9, 0, 11956, 0, 0, 0, 0, 0, '', 'Required quest ''Finding the Phylactery'' active for spellclick');

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `rank`=3, `speed_walk`=2.5, `speed_run`=2.5 WHERE `entry`=28182;

-- Dusk SAI
SET @ENTRY := 28182;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,28182,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,21,28182,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Waypoint 21 Reached - Despawn Instant"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Just Summoned - Set Reactstate Passive"),
(@ENTRY,0,3,0,28,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Passenger Removed - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=28182;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(28182, 1,3137.103,3835.605,23.80482, 'Dusk'),
(28182, 2,3151.105,3841.837,26.15598, 'Dusk'),
(28182, 3,3190.882,3844.668,28.8679, 'Dusk'),
(28182, 4,3232.1,3838.992,27.33721, 'Dusk'),
(28182, 5,3282.762,3832.855,27.20968, 'Dusk'),
(28182, 6,3307.908,3829.667,28.43119, 'Dusk'),
(28182, 7,3340.627,3826.012,25.35527, 'Dusk'),
(28182, 8,3352.079,3823.348,27.22523, 'Dusk'),
(28182, 9,3399.218,3818.613,27.66385, 'Dusk'),
(28182, 10,3439.386,3828.509,27.79152, 'Dusk'),
(28182, 11,3456.517,3835.027,29.58427, 'Dusk'),
(28182, 12,3482.749,3841.445,32.40864, 'Dusk'),
(28182, 13,3531.002,3843.39,33.53048, 'Dusk'),
(28182, 14,3549.508,3830.051,39.22393, 'Dusk'),
(28182, 15,3561.163,3818.268,40.28746, 'Dusk'),
(28182, 16,3573.922,3785.856,36.752, 'Dusk'),
(28182, 17,3574.622,3781.316,36.74898, 'Dusk'),
(28182, 18,3583.712,3758.963,36.55262, 'Dusk'),
(28182, 19,3603.148,3712.664,36.74012, 'Dusk'),
(28182, 20,3605.655,3702.697,36.80239, 'Dusk'),
(28182, 21,3618.601,3670.745,35.97186, 'Dusk');
--
UPDATE `smart_scripts` SET `target_type`=2 WHERE `entryorguid`=28557 AND `source_type`=0 AND `id`=0;
-- Fix 'Teleport to Lake Wintergrasp'
DELETE FROM `spell_scripts` WHERE `id`=58622;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(58622, 0, 1, 6, 571, 0, 0, 5386.05, 2840.97, 418.675, 3.14159);
-- Magnataur Huntress SAI
SET @ENTRY := 24469;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,8,0,100,0,46012,0,0,0,36,25788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Huntress - On Spellhit 'Bloodspore Poison' - Update Template To 'Weakened Magnataur Huntress'");
-- Festering Corpse SAI
SET @ENTRY := 31130;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,58641,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Spellhit 'Olakin's Torch' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3113000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,59216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Script - Cast 'Burning Corpse'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,33,31130,0,0,0,0,0,7,0,0,0,0,0,0,0,"Festering Corpse - On Script - Quest Credit 'By Fire Be Purged'"),
(@ENTRY,9,2,0,0,0,100,0,6000,9000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Script - Despawn Instant");
--
DELETE FROM `event_scripts` WHERE `id` = 14394;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(14394,0,8,22395,0,0,0,0,0,0);
--
UPDATE `creature_template` SET `npcflag`=16777217, `InhabitType`=4 WHERE  `entry`=27923;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27923;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(27923,46598,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9045 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=8 AND `ConditionTarget`=0 AND `ConditionValue1`=11509 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9045 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=28 AND `ConditionTarget`=0 AND `ConditionValue1`=11509 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9045, 0, 0, 0, 8, 0, 11509, 0, 0, 0, 0, 0, '', 'Lou the Cabin Boy - Show gossip option only if player has taken quest 11509');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9045, 0, 0, 1, 28, 0, 11509, 0, 0, 0, 0, 0, '', 'Lou the Cabin Boy - Show gossip option only if player has taken quest 11509');

-- Lou the Cabin Boy SAI
SET @ENTRY := 27923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,27923,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,28,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Passenger Removed - Despawn Instant"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Just Summoned - Set Reactstate Passive"),
(@ENTRY,0,3,0,40,0,100,0,13,27923,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lou the Cabin Boy - On Waypoint 13 Reached - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=27923;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27923, 1, 556.8802, -2811.598, -0.076807, 'Lou'),
(27923, 2, 482.0306, -2834.213, -0.049029, 'Lou'),
(27923, 3, 454.4951, -2891.859, -0.049029, 'Lou'),
(27923, 4, 335.4129, -2946.441, -0.049029, 'Lou'),
(27923, 5, 262.8804, -3016.949, -0.021251, 'Lou'),
(27923, 6, 147.2193, -3176.037, -0.049029, 'Lou'),
(27923, 7, 86.28928, -3239.844, -0.021251, 'Lou'),
(27923, 8, -22.49794, -3241.448, -0.076807, 'Lou'),
(27923, 9, -151.2886, -3296.966, 0.006526, 'Lou'),
(27923, 10, -195.9667, -3366.19, -0.132362, 'Lou'),
(27923, 11, -255.5049, -3519.14, -0.021251, 'Lou'),
(27923, 12, -217.6928, -3555.593, -0.076807, 'Lou'),
(27923, 13, -201.783, -3548.484, -0.021251, 'Lou');
-- Dawnblade Marksman SAI
SET @ENTRY := 24979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,7000,13000,11,45101,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Marksman - Within 0-70 Range Out of Combat LoS - Cast 'Flaming Arrow'"),
(@ENTRY,0,1,0,1,0,100,0,3000,3000,5000,5000,11,45101,0,0,0,0,0,19,5202,26,0,0,0,0,0,"Dawnblade Marksman - Out of Combat - Cast 'Flaming Arrow'");

-- Pathing for  Entry: 25001 'TDB FORMAT' 
SET @NPC := 93967;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=12616.02,`position_y`=-6826.477,`position_z`=13.30631 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,2,12615.95,-6826.547,13.58466,0,0,0,0,100,0),
(@PATH,3,12607.38,-6830.652,13.76608,0,0,0,0,100,0),
(@PATH,4,12591.51,-6834.896,13.87594,0,0,0,0,100,0),
(@PATH,5,12566.56,-6827.448,16.54662,0,0,0,0,100,0),
(@PATH,6,12579.94,-6832.642,14.98803,0,0,0,0,100,0),
(@PATH,7,12584.21,-6834.116,14.20888,0,0,0,0,100,0),
(@PATH,8,12591.75,-6834.886,13.74139,0,0,0,0,100,0),
(@PATH,9,12607.81,-6830.203,13.69277,0,0,0,0,100,0),
(@PATH,10,12616.39,-6826.547,13.49831,0,0,0,0,100,0),
(@PATH,11,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,12,12615.95,-6826.547,13.5846,0,0,0,0,100,0),
(@PATH,13,12607.6,-6830.664,13.76679,0,0,0,0,100,0),
(@PATH,14,12591.65,-6834.927,13.87652,0,0,0,0,100,0),
(@PATH,15,12566.47,-6827.438,16.55291,0,0,0,0,100,0),
(@PATH,16,12579.94,-6832.642,14.98803,0,0,0,0,100,0),
(@PATH,17,12584.21,-6834.114,14.20937,0,0,0,0,100,0),
(@PATH,18,12591.73,-6834.884,13.74244,0,0,0,0,100,0),
(@PATH,19,12607.78,-6830.21,13.69292,0,0,0,0,100,0),
(@PATH,20,12616.38,-6826.549,13.49841,0,0,0,0,100,0),
(@PATH,21,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,22,12615.95,-6826.547,13.58466,0,0,0,0,100,0),
(@PATH,23,12607.59,-6830.418,13.76704,0,0,0,0,100,0);
-- 0x1C09084240186A4000002E000055E86A .go 12616.02 -6826.477 13.30631

-- Pathing for  Entry: 25001 'TDB FORMAT' 
SET @NPC := 93966;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=12488.71,`position_y`=-6887.34,`position_z`=16.40788 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,12488.71,-6887.34,16.40788,0,0,0,0,100,0),
(@PATH,2,12495.96,-6887.744,16.62086,0,0,0,0,100,0),
(@PATH,3,12491.32,-6874.924,17.07642,0,0,0,0,100,0);
-- 0x1C09084240186A4000002E0000558FDB .go 12488.71 -6887.34 16.40788
--
SET @Ameer  :=20482; -- Image of Commander Ameer
SET @SpellSummon:=35679; -- Summons Protectorate. 
SET @Protectorate:=20802; -- Protectorate Demolitionist
SET @Cleave :=30619; -- Protectorate Demolitionist's Cleave
SET @Hamstring  :=31553; -- Protectorate Demolitionist's Hamstring 
SET @Strike :=16856; -- Protectorate Demolitionist's Mortal Striket
SET @Stalker    :=20474; -- Ethereum Nexus-Stalker
SET @Sshadowtouched:=36515; -- Ethereum Nexus-Stalker's Shadowtouched
SET @Sshadowsurge:=36517; -- Ethereum Nexus-Stalker's Shadowsurge

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Ameer,@Protectorate,@Stalker);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @Ameer AND id IN (5,6);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Protectorate,@Stalker);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@Protectorate*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ameer,0,5,0,19,0,100,0,10406,0,0,0,85,@SpellSummon,2,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Commander Ameer - On Quest 10406 accepted - Cast Summon Protectorate Demolitionist'),
(@Ameer,0,6,0,20,0,100,0,10406,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Commander Ameer - On Quest 10406 accepted - Cast Summon Protectorate Demolitionist'),
(@Protectorate,0,0,0,54,0,100,0,0,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Just Summoned - Say 0'),
(@Protectorate,0,1,0,52,0,100,0,0,@Protectorate,0,0,53,0,@Protectorate,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - Start Wp'),
(@Protectorate,0,2,3,40,0,100,0,3,@Protectorate,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 3 - Pause Wp'),
(@Protectorate,0,3,0,61,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link Event - Say 1'),
(@Protectorate,0,4,5,40,0,100,0,5,@Protectorate,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 5 - Pause Wp'),
(@Protectorate,0,5,0,61,0,100,0,0,0,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link Event - Say 2'),
(@Protectorate,0,6,7,40,0,100,0,7,@Protectorate,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 7 - Pause Wp'),
(@Protectorate*100,9,0,0,0,0,100,0,0,0,0,0,1,3,14000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Say 3'),
(@Protectorate*100,9,1,0,0,0,100,0,500,500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Emote Work'),
(@Protectorate*100,9,2,0,0,0,100,0,3500,3500,0,0,12,@Stalker,2,30000,1,0,0,8,0,0,0,3866.837402,2321.753418,113.736206,0.120686,'Protectorate Demolitionist - Script - Summon Nexus-Stalker'),
(@Protectorate*100,9,3,0,0,0,100,0,0,0,0,0,12,@Stalker,2,30000,1,0,0,8,0,0,0,3879.268799,2321.939209,115.065338,3.137270,'Protectorate Demolitionist - Script - Summon Nexus-Stalker'),
(@Protectorate*100,9,4,0,0,0,100,0,6000,6000,0,0,1,4,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Say 4'),
(@Protectorate*100,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Run'),
(@Protectorate*100,9,6,0,0,0,100,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Resume WP'),
(@Protectorate*100,9,7,0,0,0,100,0,0,0,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Emote Work'),
(@Protectorate,0,7,0,61,0,100,0,0,0,0,0,80,@Protectorate*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Start Script'),
(@Protectorate,0,8,9,40,0,100,0,8,@Protectorate,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 8 - Pause Wp'),
(@Protectorate,0,9,10,61,0,100,0,0,0,0,0,1,5,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Say 5'),
(@Protectorate,0,10,0,61,0,100,0,0,0,0,0,15,10406,0,0,0,0,0,21,15,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Complete Quest'),
(@Protectorate,0,11,12,52,0,100,0,5,@Protectorate,0,0,11,35517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - cast teleportaion visual'),
(@Protectorate,0,12,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - despawn'),
(@Protectorate,0,13,0,4,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - On aggro - talk'),
(@Stalker,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker - On respawn - Say 0'),
(@Stalker,0,1,0,0,0,100,0,200,200,5000,5000,11,@Sshadowtouched,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker - IC - Cast Shadowtouched'),
(@Stalker,0,2,0,0,0,100,0,500,2000,10000,12000,11,@Sshadowsurge,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker -IC - Cast Shadowsurge');

DELETE FROM `creature_text` WHERE `entry` IN (@Protectorate,@Stalker, @Ameer);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@Protectorate,0,0,'Let''s do this... Just keep me covered and I''ll deliver the package.',12,0,100,0,0,0,'Protectorate Demolitionist - Comienza escort', 18432),
(@Protectorate,1,0,'By the second sun of K''aresh, look at this place! I can only imagine what Salhadaar is planning. Come on, let''s keep going.',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 1', 18433),
(@Protectorate,2,0,'Look there, fleshling! Salhadaar''s conduits! He''s keeping well fed...',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 4', 18435),
(@Protectorate,3,0,'Alright, keep me protected while I plant this disruptor. This shouldn''t take very long..',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 6', 18436),
(@Protectorate,4,0,'Done! Back up! Back up!',12,0,100,0,0,0,'Protectorate Demolitionist - Disruptor', 18437),
(@Protectorate,5,0,'Looks like my work here is done. Report to the holo-image of Ameer over at the transporter.',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 7', 18442),
(@Protectorate,6,0,'I''m under attack! I repeat, I am under attack!',12,0,100,0,0,0,'Protectorate Demolitionist - Being attacked', 18439),
(@Protectorate,6,1,'Keep these things off me!',12,0,100,0,0,0,'Protectorate Demolitionist - Being attacked', 18438),
(@Stalker,0,0,'Protect the conduit! Stop the intruders!',12,0,100,0,0,0,'Ethereum Nexus-Stalker - Protect Conduct',18441),
(@Ameer,0,0,'Hostiles detected. Ending transmission.',12,0,100,15,0,0,'Image of Commander Ameer - On aggro', 18190),
(@Ameer,1,0,'Protectorate transmission complete.',12,0,100,0,0,0,'Ameer - Quest rewarded',18191);

DELETE FROM `waypoints` WHERE `entry`=@Protectorate;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Protectorate,1,4006.368652,2323.582520,111.407501,'Protectorate Demolitionist'),
(@Protectorate,2,3946.502441,2329.601074,113.647179,'Protectorate Demolitionist'),
(@Protectorate,3,3934.442383,2333.215088,110.971733,'Protectorate Demolitionist'),
(@Protectorate,4,3912.811035,2339.968018,113.876434,'Protectorate Demolitionist'),
(@Protectorate,5,3887.416748,2408.539063,113.081406,'Protectorate Demolitionist'),
(@Protectorate,6,3863.596191,2348.160645,115.446754,'Protectorate Demolitionist'),
(@Protectorate,7,3872.944580,2321.384766,114.501541,'Protectorate Demolitionist'),
(@Protectorate,8,3859.826416,2360.402588,114.603340,'Protectorate Demolitionist');
--
UPDATE creature_template SET npcflag=0 WHERE entry=6776;
SET @NPC_BLACK_KNIGHT := 33785;
SET @NPC_CAVIN := 33522;
SET @SPELL_CHARGE := 63003;
SET @SPELL_SHIELD_BREAKER := 65147;
SET @SPELL_DARK_SHIELD := 64505;
SET @SPELL_BLACK_NIGHT_TRANSFORM := 64490; -- Apply Aura: Change Model (34104)
SET @SPELL_BLACK_NIGHT_TRANSFORM_2 := 64498; -- Apply Aura: Increase Max Health
SET @SPELL_FULL_HEAL := 25840;
SET @GOSSIP := 10383;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_BLACK_KNIGHT, @NPC_CAVIN);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_BLACK_KNIGHT;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_BLACK_KNIGHT*100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_BLACK_KNIGHT*100+1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_CAVIN;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_CAVIN*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_CAVIN,0,0,1,62,0,100,0,@GOSSIP,0,0,0,80,@NPC_CAVIN*100,0,2,0,0,0,1,0,0,0,0,0,0,0,'Cavin - On gossip option select - Run script'),
(@NPC_CAVIN,0,1,2,61,0,100,0,0,0,0,0,12,@NPC_BLACK_KNIGHT,1,120000,0,0,0,8,0,0,0,8482.370117, 964.506653, 547.292908, 3.253865,'Cavin - On gossip option select - Summon the Black Knight'),
(@NPC_CAVIN,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On gossip option select - Close gossip'),
(@NPC_CAVIN*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cavin - On Script - Turn off Gossip & Gossip flags'),
(@NPC_CAVIN*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On Script - Say text 0'),
(@NPC_CAVIN*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On Script - Say text 1'),
(@NPC_BLACK_KNIGHT,0,0,0,54,0,100,1,0,0,0,0,80,@NPC_BLACK_KNIGHT*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - Just Summoned - Mount to entry'),
(@NPC_BLACK_KNIGHT*100+1,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,8426.153320, 962.307861, 544.675293, 6.273711,'Blackknight - On Script - MOVE TO POS'),
(@NPC_BLACK_KNIGHT*100+1,9,1,0,0,0,100,0,10000,10000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - REMOVE IMMUNE TO PC'),
(@NPC_BLACK_KNIGHT*100+1,9,2,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - REMOVE IMMUNE TO PC'),
(@NPC_BLACK_KNIGHT*100+1,9,3,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,33782,25,0,0,0,0,0,'Blackknight - On Script - attack'),
(@NPC_BLACK_KNIGHT,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - On Aggro - Cast Charge'),
(@NPC_BLACK_KNIGHT,0,2,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Aggro - Set Phase 1'),
(@NPC_BLACK_KNIGHT,0,3,0,0,1,100,0,10000,10000,15000,15000,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - In Phase 1 - Flee for assist'),
(@NPC_BLACK_KNIGHT,0,4,0,9,1,100,0,5,30,1000,1000,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - In Phase 1& On Range - Cast Charge'),
(@NPC_BLACK_KNIGHT,0,5,0,9,1,100,0,3,30,1500,2000,11,@SPELL_SHIELD_BREAKER,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - In Phase 1 & On Range - Cast Shield Breaker'),
(@NPC_BLACK_KNIGHT,0,6,0,6,0,100,0,0,0,0,0,81,1,0,0,0,0,0,10,85140,@NPC_CAVIN,0,0,0,0,0,'Blackknight - On Death - Turn on Gossip & Gossip flags on Cavin'),
(@NPC_BLACK_KNIGHT,0,7,8,1,0,100,0,20000,20000,20000,20000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - Out Of Combat after 20s - Despawn'),
(@NPC_BLACK_KNIGHT,0,8,0,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,10,85140,@NPC_CAVIN,0,0,0,0,0,'Blackknight - Out Of Combat after 20s - Turn on Gossip & Gossip flags on Cavin'),
(@NPC_BLACK_KNIGHT,0,9,0,2,1,100,1,0,25,0,0,80,@NPC_BLACK_KNIGHT*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On 25% health - Run script'),
(@NPC_BLACK_KNIGHT*100,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - State passive'),
(@NPC_BLACK_KNIGHT*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Say text 0'),
(@NPC_BLACK_KNIGHT*100,9,2,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Unmount'),
(@NPC_BLACK_KNIGHT*100,9,3,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,33782,30,0,0,0,0,0,'Blackknight - On Script - Unmount player'),
(@NPC_BLACK_KNIGHT*100,9,4,0,0,0,100,0,0,0,0,0,11,@SPELL_DARK_SHIELD,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Cast Dark Shield'),
(@NPC_BLACK_KNIGHT*100,9,5,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Aggro - Set Phase 0'),
(@NPC_BLACK_KNIGHT*100,9,6,0,0,0,100,0,6000,6000,0,0,11,@SPELL_BLACK_NIGHT_TRANSFORM,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Apply Aura'),
(@NPC_BLACK_KNIGHT*100,9,7,0,0,0,100,0,0,0,0,0,11,@SPELL_FULL_HEAL,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Full hp'),
(@NPC_BLACK_KNIGHT*100,9,8,0,0,0,100,0,1000,1000,0,0,11,@SPELL_BLACK_NIGHT_TRANSFORM_2,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Increase Max Health'),
(@NPC_BLACK_KNIGHT*100,9,9,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - State Aggresive'),
(@NPC_BLACK_KNIGHT*100,9,10,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Say text 1'),
(@NPC_BLACK_KNIGHT*100,9,11,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,15,0,0,0,0,0,0,'Blackknight - On Script - Start Attack');

DELETE FROM `creature_text` WHERE `entry`IN (@NPC_BLACK_KNIGHT, @NPC_CAVIN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@NPC_BLACK_KNIGHT,0,0,'Get off that horse and fight me man-to-man!',14,0,100,0,0,0,'yell',34169),
(@NPC_BLACK_KNIGHT,1,0,'I will not fail you, master!',14,0,100,0,0,0,'yell',34185),
(@NPC_CAVIN,0,0,'$N challenges the Black Knight to trial by combat!',14,0,100,0,0,0,'yell',33803),
(@NPC_CAVIN,1,0,'Good luck, $N.',12,0,100,0,0,0,'say',33804);

UPDATE `conditions` SET `ConditionValue2`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10383 AND `SourceEntry`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionValue1`=63663;
--
SET @KC_FIRST_PROPHECY                  := 22798;
SET @KC_SECOND_PROPHECY                 := 22799;
SET @KC_THIRD_PROPHECY                  := 22800;
SET @KC_FOURTH_PROPHECY                 := 22801;
SET @QUEST_WHISPERS_RAVEN_GOD           := 10607;
SET @NPC_VISION_RAVEN_GOD               := 21861;
SET @SPELL_UNDERSTANDING_RAVENSPEECH    := 37466;
SET @AURA_UNDERSTANDING_RAVENSPEECH     := 37642;
SET @Falconwing                         := 19988;
SET @Harbinger                          := 19989;
SET @Scorncrow                          := 19990;

UPDATE `creature_template` SET `exp`='1', `minlevel`='67', `maxlevel`='67', `unit_flags`='768', `type`='7' WHERE `entry`=@NPC_VISION_RAVEN_GOD;

DELETE FROM `creature_text` WHERE `entry`=@NPC_VISION_RAVEN_GOD;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(@NPC_VISION_RAVEN_GOD,0,0,'From the darkest night shall rise again the raven, shall take flight in the shadows, shall reveal the nature of its kind. Prepare yourself for its coming, for the faithful shall be elevated to take flight with the raven, the rest be forgotten to walk upon the ground, clipped wings and shame.',15,0,100,0,0,0,'The Voice of the Raven God - The First Prophecy', 19475),
(@NPC_VISION_RAVEN_GOD,1,0,'Steel your minds and guard your thoughts. The dark wings will cloud and consume the minds of the weak, a flock of thralls whose feet may never leave the ground.', 15,0,100,0,0,0,'The Voice of the Raven God - The Second Prophecy', 19476),
(@NPC_VISION_RAVEN_GOD,2,0,'The Old blood will flow once again with the coming of the raven, the return of the darkness in the skies. Scarlet night, and the rise of the old.', 15,0,100,0,0,0,'The Voice of the Raven God - The Third Prophecy', 19477),
(@NPC_VISION_RAVEN_GOD,3,0,'The raven was struck down once for flying too high, unready. The eons have prepared the Dark Watcher for its ascent, to draw the dark cloak across the horizon.', 15,0,100,0,0,0,'The Voice of the Raven God - The Fourth Prophecy', 19478);

UPDATE creature_template SET AIName="SmartAI" WHERE entry IN (@Falconwing, @Harbinger, @Scorncrow,@NPC_VISION_RAVEN_GOD);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (184950,184967,184968,184969);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Falconwing, @Harbinger, @Scorncrow,@NPC_VISION_RAVEN_GOD) AND `source_type`=0; -- Npcs
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (184950,184967,184968,184969) AND `source_type`=1; -- Gameobjects (totems)
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- Npcs a matar para que te den el buff
(@Falconwing,0,0,0,0,0,100,0,2500,5500,10000,11000,11,37587,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Falconwing - In Combat - Cast Bestial Wrath"),
(@Falconwing,0,1,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Falconwing - On Death - Cast Understanding Ravenspeech"),
(@Harbinger,0,0,0,0,0,100,0,2500,5500,20000,21000,11,37589,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbinger - In Combat - Cast Shriveling Gaze"),
(@Harbinger,0,1,0,0,0,100,0,1000,6000,10000,15000,11,9532,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbinger - In Combat - Cast Lightning Bolt"),
(@Harbinger,0,2,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbringer - On Death - Cast Understanding Ravenspeech"),
(@Scorncrow,0,0,0,0,0,100,0,2500,5500,10000,11000,11,35321,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Scorncrow - In Combat - Cast Gushing Wound"),
(@Scorncrow,0,1,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Scorncrow - On Death - Cast Understanding Ravenspeech"),
-- Vision Of Raven God
(@NPC_VISION_RAVEN_GOD,0,0,1,38,0,100,0,1,1,0,0,33,@KC_FIRST_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 0"),
(@NPC_VISION_RAVEN_GOD,0,2,3,38,0,100,0,1,2,0,0,33,@KC_SECOND_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 1"),
(@NPC_VISION_RAVEN_GOD,0,4,5,38,0,100,0,1,3,0,0,33,@KC_THIRD_PROPHECY ,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 2"),
(@NPC_VISION_RAVEN_GOD,0,6,7,38,0,100,0,1,4,0,0,33,@KC_FOURTH_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 3"),
-- GOB Totems
(184950,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3779.987061,6729.603027,180.498413,5.71490,"First Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184950,1,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"First Prophecy - Link - Set Data 1 to Raven God"),
(184967,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3629.285889,6542.140137,155.004669,2.56267,"Second Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184967,1,1,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Second Prophecy - Link - Set Data 2 to Raven God"),
(184968,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3736.950439,6640.749023,133.674530,3.33629,"Third Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184968,1,1,0,61,0,100,0,0,0,0,0,45,1,3,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Third Prophecy - Link - Set Data 3 to Raven God"),
(184969,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3572.574219,6669.196289,128.455444,5.62290,"Four Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184969,1,1,0,61,0,100,0,0,0,0,0,45,1,4,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Fourth Prophecy - Link - Set Data 4 to Raven God");

DELETE FROM `conditions` WHERE `ConditionValue1`=@AURA_UNDERSTANDING_RAVENSPEECH AND `sourcetypeorreferenceid`=22;
DELETE FROM `conditions` WHERE `ConditionValue1`=@NPC_VISION_RAVEN_GOD AND `sourcetypeorreferenceid`=22;
DELETE FROM `conditions` WHERE `SourceEntry`=@NPC_VISION_RAVEN_GOD AND `sourcetypeorreferenceid`=22;
INSERT INTO `conditions` (SourceTypeOrReferenceId,SourceGroup,SourceEntry,SourceId,ElseGroup,ConditionTypeOrReference,ConditionTarget,ConditionValue1,ConditionValue2,ConditionValue3,NegativeCondition,ErrorType,ErrorTextId,ScriptName,`Comment`) VALUES
(22,1,184950,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb First Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184950,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb First Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184967,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Second Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184967,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Second Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184968,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Third Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184968,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Third Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184969,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Fourth Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184969,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Fourth Prophecy - SAI 1, only if Raven God is not near');
--
DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN ('at_twiggy_flathead','at_madrigosa','at_eye_of_eternity_improvised_floor');

UPDATE `gameobject_template` SET `ScriptName`='' WHERE `ScriptName` IN ('go_defias_cannon','go_door_lever_dm','go_kael_orb','go_movie_orb');

UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName` IN ('do_nothing','npc_aran_blizzard','npc_bladespire_ogre','npc_blaze','npc_crystalline_tangler','npc_demon_fire','npc_flame_crash','npc_generic_harpoon_cannon','npc_homunculus','npc_invis_legion_teleporter','npc_magnetic_core','npc_mindless_skeleton','npc_nether_vapor','npc_novos_minion','npc_sliver','npc_thuzadin_acolyte','npc_tracy_proudwell','npc_vereth_the_cunning','npc_void_zone','npc_yauj_brood');

DELETE FROM `spell_script_names` WHERE `scriptname` IN ('spell_ex_463', 'spell_ex_5581', 'spell_ex_66244', 'spell_ex_absorb_aura', 'spell_mimiron_flame_suppressant');

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=37120 AND `source_type`=0 AND `id`=3 AND `link`=7;

-- Grand Necrolord Antiok SAI
SET @ENTRY := 28006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,18000,18000,11,32863,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Seed of Corruption'"),
(@ENTRY,0,1,0,0,0,100,0,1100,1100,20000,20000,11,50455,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,1,0,100,0,10000,10000,40000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Out of Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,11,50497,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Between 0-25% Health - Cast 'Scream of Chaos' (No Repeat)"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,11,50472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Just Died - Cast 'Drop Scythe of Antiok'"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Say Line 0"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,11,55984,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,7,8,4,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,27996,20,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Kill Target"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,28,50494,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Remove Aura 'Shroud of Lightning'");

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=27987 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`=11 WHERE  `entryorguid`=27788 AND `source_type`=0 AND `id`=2 AND `link`=12;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=26701 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=24035 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Ara Technician SAI
SET @ENTRY := 20438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,4,4,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Data Set 4 4 - Set Reactstate Defensive"),
(@ENTRY,0,1,0,61,0,100,0,4,4,0,0,87,2043900,2043901,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Data Set 4 4 - Run Random Script"),
(@ENTRY,0,2,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,184312,0,0,0,0,0,0,"Ara Technician - Out of Combat - Set Data 1 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,3,4,40,0,100,0,1,0,0,0,11,35176,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Waypoint 1 Reached - Cast 'Interrupt Shutdown'"),
(@ENTRY,0,4,0,61,0,100,0,1,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Waypoint 1 Reached - Set Event Phase 1"),
(@ENTRY,0,5,6,4,0,100,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Set Event Phase 0"),
(@ENTRY,0,6,7,61,0,100,0,1,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Set Reactstate Aggressive"),
(@ENTRY,0,7,8,61,0,100,0,1,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Start Attacking"),
(@ENTRY,0,8,0,61,0,100,0,1,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Enable Combat Movement"),
(@ENTRY,0,9,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184312,0,0,0,0,0,0,"Ara Technician - On Evade - Set Data 1 1");

-- Audrid SAI
SET @ENTRY := 18903;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,18903,1,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Respawn - Start Waypoint"),
(@ENTRY,0,1,11,40,0,100,0,4,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,2,12,40,0,100,0,9,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 9 Reached - Pause Waypoint"),
(@ENTRY,0,3,13,40,0,100,0,11,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 11 Reached - Pause Waypoint"),
(@ENTRY,0,4,14,40,0,100,0,12,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 12 Reached - Pause Waypoint"),
(@ENTRY,0,5,15,40,0,100,0,13,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 13 Reached - Pause Waypoint"),
(@ENTRY,0,6,16,40,0,100,0,14,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 14 Reached - Pause Waypoint"),
(@ENTRY,0,7,17,40,0,100,0,17,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 17 Reached - Pause Waypoint"),
(@ENTRY,0,8,18,40,0,100,0,22,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 22 Reached - Pause Waypoint"),
(@ENTRY,0,9,19,40,0,100,0,25,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 25 Reached - Pause Waypoint"),
(@ENTRY,0,10,20,40,0,100,0,28,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 28 Reached - Pause Waypoint"),
(@ENTRY,0,11,21,61,0,100,0,4,18903,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,12,22,61,0,100,0,9,18903,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,13,22,61,0,100,0,11,18903,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,14,23,61,0,100,0,12,18903,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,15,21,61,0,100,0,13,18903,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,16,24,61,0,100,0,14,18903,0,0,80,@ENTRY*100+05,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 14 Reached - Run Script"),
(@ENTRY,0,17,22,61,0,100,0,17,18903,0,0,80,@ENTRY*100+06,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 17 Reached - Run Script"),
(@ENTRY,0,18,21,61,0,100,0,22,18903,0,0,80,@ENTRY*100+07,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 22 Reached - Run Script"),
(@ENTRY,0,19,21,61,0,100,0,25,18903,0,0,80,@ENTRY*100+08,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 25 Reached - Run Script"),
(@ENTRY,0,20,21,61,0,100,0,28,18903,0,0,80,@ENTRY*100+09,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 28 Reached - Run Script"),
(@ENTRY,0,21,0,61,0,100,0,4,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.5,"Audrid - On Waypoint 4 Reached - Set Orientation 1,5"),
(@ENTRY,0,22,0,61,0,100,0,9,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3,"Audrid - On Waypoint 9 Reached - Set Orientation 3"),
(@ENTRY,0,23,0,61,0,100,0,12,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.5,"Audrid - On Waypoint 12 Reached - Set Orientation 4,5"),
(@ENTRY,0,24,0,61,0,100,0,14,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6,"Audrid - On Waypoint 14 Reached - Set Orientation 6");

UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26670 AND `source_type`=0 AND `id`=19 AND `link`=20;
UPDATE `smart_scripts` SET `link`=20 WHERE  `entryorguid`=17892 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `link`=7 WHERE  `entryorguid`=17892 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=37952 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=26787 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Mad Voidwalker SAI
SET @ENTRY := 15146;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Voidwalker - On Respawn - Start Random Movement"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,11000,13000,11,24614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Voidwalker - In Combat - Cast 'Consuming Shadows' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,3000,4000,8000,8000,11,24616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Voidwalker - In Combat - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,1,0,100,0,0,0,0,0,41,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Voidwalker - Out of Combat - Despawn In 180000 ms");

UPDATE `smart_scripts` SET `link`=9 WHERE  `entryorguid`=12236 AND `source_type`=0 AND `id`=8 AND `link`=0;
UPDATE `smart_scripts` SET `link`=9 WHERE  `entryorguid`=13196 AND `source_type`=0 AND `id`=8 AND `link`=0;

-- Scarlet Curate SAI
SET @ENTRY := 9450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,3400,4800,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Curate - Within 0-40 Range - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,15,0,100,1,0,0,30,0,11,17201,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Crowd Controlled - Cast 'Dispel Magic' (No Repeat)"),
(@ENTRY,0,2,0,74,0,100,0,0,40,25000,35000,11,17201,1,0,0,0,0,9,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Between 0-40% Health - Cast 'Dispel Magic'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `smart_scripts` SET `link`=25 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=24 AND `link`=26;
UPDATE `smart_scripts` SET `link`=22, `event_type`=61 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=21 AND `link`=0;
UPDATE `smart_scripts` SET `link`=16 WHERE  `entryorguid`=31279 AND `source_type`=0 AND `id`=15 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=1535 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2719 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=4484 AND `source_type`=0 AND `id`=24 AND `link`=25;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=13601 AND `source_type`=0 AND `id`=2 AND `link`=0;

-- Short John Mithril SAI
SET @ENTRY := 14508;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,68,0,100,0,16,0,0,0,53,0,14508,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Game Event 16 Started - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,14508,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,3,40,0,100,0,16,14508,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Say Line 1"),
(@ENTRY,0,3,0,61,0,100,0,16,14508,0,0,11,23176,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Cast 'Summon Pirate Booty (DND)'"),
(@ENTRY,0,4,0,40,0,100,0,33,14508,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.41568,"Short John Mithril - On Waypoint 33 Reached - Set Orientation 4,41568");

UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=15324 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=15526 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=17397 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=9 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=13 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18938 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5 WHERE  `entryorguid`=19354 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=23669 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=24198 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=55036 WHERE  `entryorguid`=29903 AND `source_type`=0 AND `id`=6 AND `link`=7;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=58190 WHERE  `entryorguid`=30894 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=30945 AND `source_type`=0 AND `id`=9 AND `link`=0;

UPDATE `creature_template_addon` SET`auras`="" WHERE`entry` IN (26608, 31306); -- vehicle auras appear only when the npc ride a vehicle or when he's mounted
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=35427;
--
UPDATE `smart_scripts` SET `target_o`=0 WHERE `entryorguid`=177490 AND `source_type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `target_o`=0 WHERE `entryorguid`=177490 AND `source_type`=1 AND `id`=2;
UPDATE `smart_scripts` SET `target_o`=0 WHERE `entryorguid`=2749200 AND `source_type`=9 AND `id`=5;
-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=23616;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=24762;
DELETE FROM `creature_addon` WHERE  `guid`=24762;
DELETE FROM `waypoint_data` WHERE `id`=247620; 
DELETE FROM `waypoints` WHERE `entry`=23616;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(23616, 1, -2454.94, -482.136, -8.97948, 'Kyle'),
(23616, 2, -2445.34, -476.395, -8.92086, 'Kyle'),
(23616, 3, -2433.79, -468.785, -9.20522, 'Kyle'),
(23616, 4, -2422.01, -460.858, -9.1759, 'Kyle'),
(23616, 5, -2407.47, -451.07, -8.70993, 'Kyle'),
(23616, 6, -2395.98, -443.42, -8.42222, 'Kyle'),
(23616, 7, -2383.8, -436.212, -8.78844, 'Kyle'),
(23616, 8, -2367.83, -425.967, -9.38671, 'Kyle'),
(23616, 9, -2355.15, -413.835, -9.75652, 'Kyle'),
(23616, 10, -2345.39, -403.032, -8.87064, 'Kyle'),
(23616, 11, -2338.73, -387.213, -7.97681, 'Kyle'),
(23616, 12, -2330.27, -374.08, -8.37519, 'Kyle'),
(23616, 13, -2314.64, -365.663, -9.41672, 'Kyle'),
(23616, 14, -2295.45, -360.874, -9.42468, 'Kyle'),
(23616, 15, -2279.85, -357.148, -9.42468, 'Kyle'),
(23616, 16, -2263.83, -363.376, -9.42468, 'Kyle'),
(23616, 17, -2248.52, -370.238, -9.42468, 'Kyle'),
(23616, 18, -2226.43, -386.156, -9.42468, 'Kyle'),
(23616, 19, -2232.14, -416.578, -9.42205, 'Kyle'),
(23616, 20, -2247.29, -439.615, -9.42475, 'Kyle'),
(23616, 21, -2252.91, -448.416, -9.09973, 'Kyle'),
(23616, 22, -2257.71, -455.921, -8.15442, 'Kyle'),
(23616, 23, -2271.66, -475.713, -7.80418, 'Kyle'),
(23616, 24, -2293.85, -483.264, -7.86093, 'Kyle'),
(23616, 25, -2302.71, -490.694, -7.92982, 'Kyle'),
(23616, 26, -2306.74, -494.585, -8.44247, 'Kyle'),
(23616, 27, -2324.17, -516.494, -9.32393, 'Kyle'),
(23616, 28, -2340.11, -535.209, -9.2326, 'Kyle'),
(23616, 29, -2357.69, -538.25, -9.158, 'Kyle'),
(23616, 30, -2372.68, -528.41, -9.15687, 'Kyle'),
(23616, 31, -2391.28, -518.477, -8.4459, 'Kyle'),
(23616, 32, -2404.81, -514.866, -7.4283, 'Kyle'),
(23616, 33, -2418.06, -510.431, -6.09458, 'Kyle'),
(23616, 34, -2431.22, -505.672, -6.06301, 'Kyle'),
(23616, 35, -2443.9, -499.738, -7.60161, 'Kyle'),
(23616, 36, -2462.4, -488.247, -9.27003, 'Kyle');

SET @ENTRY := 23616;
SET @Friendly:= 23622;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`IN (@ENTRY, @Friendly);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Friendly AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Friendly*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,1,23616,1,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Reset - Start Waypoint"),
(@ENTRY,0,1,2,8,0,100,0,42222,0,55000,55000,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kyle the Frenzied - On Spellhit 'Lunch for Kyle' - Store Targetlist"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Spellhit 'Lunch for Kyle' - Run Script");

-- Actionlist SAI
SET @ENTRY := 2361600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,55000,0,0,0,0,0,1,186265,50,0,0,0,0,0,"Kyle the Frenzied - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Say Line 0 (No Repeat)"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,17,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Set Emote State 393"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,20,186265,50,0,0,0,0,0,"Kyle the Frenzied - On Script - Move To Closest Gameobject 'Kyle's Lunch'"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Set Emote State 69"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,12,@Friendly,8,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Summon Kyle the Friendly"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn"),

(@Friendly,0,0,0,25,0,100,0,0,0,0,0,80,@Friendly*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Reset - Run Script"),
(@Friendly*100,9,0,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Script - Say Line 2"),
(@Friendly*100,9,1,0,0,0,100,0,0,0,0,0,17,400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Script - Set Emote State 400"),
(@Friendly*100,9,2,0,0,0,100,0,0,0,0,0,33,23616,0,0,0,0,0,21,10,0,0,0,0,0,0,"Kyle the Friendly - On Script - Quest Credit 'Kyle's Gone Missing!'"),
(@Friendly*100,9,3,0,0,0,100,0,30000,30000,0,0,70,0,0,0,0,0,0,10,24762,23616,0,0,0,0,0,"Kyle the Friendly - On Script - respawn Kyle the Frenzied"),
(@Friendly*100,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly -On Script - Despawn");
--
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=34935;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(34935,43671,1,0); -- Horde Gunship Cannon - Ride Vehicle

SET @NPC_VISION_RAVEN_GOD           := 21861;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_VISION_RAVEN_GOD) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC_VISION_RAVEN_GOD,0,0,1,38,0,100,0,1,1,0,0,11,39426,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 0"),
(@NPC_VISION_RAVEN_GOD,0,2,3,38,0,100,0,1,2,0,0,11,39428,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 1"),
(@NPC_VISION_RAVEN_GOD,0,4,5,38,0,100,0,1,3,0,0,11,39430,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 2"),
(@NPC_VISION_RAVEN_GOD,0,6,7,38,0,100,0,1,4,0,0,11,39431,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 3");

SET @ENTRY := 24290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,43404,0,0,0,11,43419,0,0,0,0,0,7,0,0,0,0,0,0,0,"New Agamand Plague Tank Bunny - On Spellhit 'Mission: Plague This!: Orehammer's Precision Bombs Dummy' - Quest Credit 'Mission: Plague This!'");

UPDATE `smart_scripts` SET `action_param1`=25068 WHERE  `entryorguid`=24999 AND `source_type`=0 AND `id`=2 AND `link`=0;
--
SET @Zuluhed                   := 11980;
SET @Portal                    := 22336;
SET @Arcubus                   := 22338;
SET @Infusion                  := 38853;
SET @SummonPortal              := 38876;
SET @Rain                      := 19717;
SET @SummonArcubus             := 38877;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Zuluhed, @Portal, @Arcubus);

DELETE FROM `creature_text` WHERE `entry`=@Zuluhed;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(@Zuluhed,0,0,'Indeed, the time has come to end this charade.',14,0,100,0,0,0,'Zuluhed the Whacked', 20128),
(@Zuluhed,1,0,'Destroy them! Destroy them all!', 14,0,100,0,0,0,'Zuluhed the Whacked', 20129),
(@Zuluhed,2,0,'Foolish mortals. Did you think that I would not strike you down for your transgressions?', 14,0,100,0,0,0,'Zuluhed the Whacked', 20127),
(@Zuluhed,3,0,'Lord Illidan, bless me with the power of the flight!', 14,0,100,0,0,0,'Zuluhed the Whacked', 20126);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Zuluhed, @Portal, @Arcubus) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Zuluhed*100, @Zuluhed*100+1, @Portal*100)  AND `source_type`=9; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@Zuluhed,0,0,0,54,0,100,0,0,0,0,0,80,@Zuluhed*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - Just Summoned - action list"),
(@Zuluhed*100,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed*100,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed,0,1,0,0,0,100,0,12000,12000,12000,12000,11,@Rain,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - IC - Cast rain"),
(@Zuluhed,0,2,0,0,0,100,0,30000,30000,60000,60000,11,@SummonPortal,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - IC - Summon portal"),
(@Zuluhed,0,3,0,2,0,100,1,0,25,0,0,80,@Zuluhed*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - On 25% health - ActionList'),
(@Zuluhed*100+1,9,0,0,0,0,100,0,0,0,0,0,11,@Infusion,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - ActionList - Cast Infusion'),
(@Zuluhed*100+1,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - ActionList - Text'),
(@Arcubus,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - Just Summoned - Attack player on 10 yards"),
(@Portal,0,0,0,54,0,100,1,0,0,0,0,80,@Portal*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Portal - Just Summoned - action list"), 
(@Portal*100,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal - ActionList - SET_ROOT'),
(@Portal*100,9,1,0,0,0,100,0,15000,15000,0,0,11,@SummonArcubus,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal - ActionList - Cast SummonArcubus');
--
UPDATE `smart_scripts` SET `action_param1`=25068 WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=35427;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(35427,43671,1,0);

UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=38162 WHERE  `entryorguid`=19937 AND `source_type`=0 AND `id` IN (1, 3, 12);
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=70606 WHERE  `entryorguid`=37826 AND `source_type`=0 AND `id` = 0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=25359 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=6 WHERE  `entryorguid`=25335 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `link`=10 WHERE  `entryorguid`=25335 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `event_type`=61, `link`=0 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=21;
UPDATE `smart_scripts` SET `event_param1`=0 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=23;
UPDATE `smart_scripts` SET `link`=16 WHERE  `entryorguid`=28122 AND `source_type`=0 AND `id`=15;
--
UPDATE `conditions` SET `ConditionValue3`=0 WHERE  `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=48363 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=29 AND `ConditionTarget`=0 AND `ConditionValue1`=27315 AND `ConditionValue2`=5 AND `ConditionValue3`=1;
UPDATE `conditions` SET `ConditionValue3`=0 WHERE  `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=48363 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=29 AND `ConditionTarget`=0 AND `ConditionValue1`=27336 AND `ConditionValue2`=5 AND `ConditionValue3`=1;
UPDATE `conditions` SET `ConditionValue3`=0 WHERE  `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=48397 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=29 AND `ConditionTarget`=0 AND `ConditionValue1`=27315 AND `ConditionValue2`=5 AND `ConditionValue3`=1;
UPDATE `conditions` SET `ConditionValue3`=0 WHERE  `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=48397 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=29 AND `ConditionTarget`=0 AND `ConditionValue1`=27336 AND `ConditionValue2`=5 AND `ConditionValue3`=1;
UPDATE `conditions` SET `ConditionTypeOrReference`=29, `ConditionValue1`=37852, `ConditionValue2`=10 WHERE  `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=70586 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=18 AND `ConditionTarget`=0 AND `ConditionValue1`=1 AND `ConditionValue2`=37852 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue2`=0 WHERE  `SourceTypeOrReferenceId`=1 AND `SourceGroup`=23286 AND `SourceEntry`=32726 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=11081 AND `ConditionValue2`=1 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue2`=0 WHERE  `SourceTypeOrReferenceId`=1 AND `SourceGroup`=23324 AND `SourceEntry`=32726 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=11081 AND `ConditionValue2`=1 AND `ConditionValue3`=0;
--
DELETE FROM `creature_formations` WHERE `leaderGUID`=57528;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57528, 57528, 0, 0, 2),
(57528, 57527, 3, 90, 2);

-- Pathing for Thrallmar Grunt Entry: 16580 'TDB FORMAT' 
SET @NPC := 57528;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=132.3433,`position_y`=2762.987,`position_z`=102.3826 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,132.3433,2762.987,102.3826,0,0,0,0,100,0),
(@PATH,2,121.0521,2749.356,98.25848,0,0,0,0,100,0),
(@PATH,3,109.0274,2741.556,94.49025,0,0,0,0,100,0),
(@PATH,4,95.7988,2726.423,89.95798,0,0,0,0,100,0),
(@PATH,5,83.33932,2712.466,86.36182,0,0,0,0,100,0),
(@PATH,6,75.62203,2702.179,84.19798,0,0,0,0,100,0),
(@PATH,7,68.19456,2688.539,81.85039,0,0,0,0,100,0),
(@PATH,8,66.99038,2685.902,81.33047,0,0,0,0,100,0),
(@PATH,9,82.17162,2678.548,81.62874,0,0,0,0,100,0),
(@PATH,10,96.37463,2678.292,82.75209,0,0,0,0,100,0),
(@PATH,11,112.1558,2676.275,83.38298,0,0,0,0,100,0),
(@PATH,12,119.6769,2675.056,83.7209,0,0,0,0,100,0),
(@PATH,13,111.278,2648.706,80.93124,0,0,0,0,100,0),
(@PATH,14,109.0044,2646.347,80.20769,0,0,0,0,100,0),
(@PATH,15,116.2792,2653.762,81.89182,0,0,0,0,100,0),
(@PATH,16,122.4159,2660.933,84.18261,0,0,0,0,100,0),
(@PATH,17,123.3134,2662.276,84.17096,0,0,0,0,100,0),
(@PATH,18,103.6847,2670.964,83.00417,0,0,0,0,100,0),
(@PATH,19,80.54628,2673.75,81.59075,0,0,0,0,100,0),
(@PATH,20,73.74189,2676.277,80.69298,0,0,0,0,100,0),
(@PATH,21,69.13676,2697.863,83.02922,0,0,0,0,100,0),
(@PATH,22,75.02055,2712.901,85.39117,0,0,0,0,100,0),
(@PATH,23,87.82365,2724.378,88.41669,0,0,0,0,100,0),
(@PATH,24,104.5768,2742.848,93.40324,0,0,0,0,100,0),
(@PATH,25,117.3608,2752.192,97.77188,0,0,0,0,100,0),
(@PATH,26,129.486,2763.919,102.3025,0,0,0,0,100,0);
-- 0x1C09E4424010310000002C00015AED53 .go 132.3433 2762.987 102.3826

DELETE FROM `creature_formations` WHERE `leaderGUID`=57506;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57506, 57506, 0, 0, 2),
(57506, 57507, 3, 90, 2);

-- Pathing for Thrallmar Grunt Entry: 16580 'TDB FORMAT' 
SET @NPC := 57506;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=160.0679,`position_y`=2783.137,`position_z`=111.3373 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,160.0679,2783.137,111.3373,0,0,0,0,100,0),
(@PATH,2,162.4358,2778.617,110.5461,0,0,0,0,100,0),
(@PATH,3,172.7094,2774.508,110.6423,0,0,0,0,100,0),
(@PATH,4,186.6513,2777.03,113.5835,0,0,0,0,100,0),
(@PATH,5,200.0523,2782.693,116.7996,0,0,0,0,100,0),
(@PATH,6,209.4241,2784.837,118.5891,0,0,0,0,100,0),
(@PATH,7,222.8512,2785.429,121.0061,0,0,0,0,100,0),
(@PATH,8,233.1155,2787.613,123.6816,0,0,0,0,100,0),
(@PATH,9,237.861,2791.877,125.6136,0,0,0,0,100,0),
(@PATH,10,239.1323,2799.748,127.3235,0,0,0,0,100,0),
(@PATH,11,239.1207,2795.199,126.621,0,0,0,0,100,0),
(@PATH,12,235.6156,2789.706,124.6459,0,0,0,0,100,0),
(@PATH,13,227.0757,2786.192,122.1876,0,0,0,0,100,0),
(@PATH,14,212.622,2785.389,119.2345,0,0,0,0,100,0),
(@PATH,15,205.132,2784.269,117.806,0,0,0,0,100,0),
(@PATH,16,188.0606,2777.626,114.1675,0,0,0,0,100,0),
(@PATH,17,175.7908,2774.627,111.4541,0,0,0,0,100,0),
(@PATH,18,168.39,2775.401,110.4383,0,0,0,0,100,0),
(@PATH,19,160.1083,2782.976,111.366,0,0,0,0,100,0);
-- 0x1C09E4424010310000002C00015AED54 .go 160.0679 2783.137 111.3373

DELETE FROM `creature_formations` WHERE `leaderGUID`=57965;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57594, 57594, 0, 0, 2),
(57594, 57595, 5, 0, 2),
(57594, 57596, 10, 0, 2),
(57594, 57597, 15, 0, 2);

-- Pathing for Thrallmar Wolf Rider Entry: 16599 'TDB FORMAT' 
SET @NPC := 57594;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=196.28,`position_y`=2781.241,`position_z`=115.9637 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14334,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,196.28,2781.241,115.9637,0,0,1,0,100,0),
(@PATH,2,173.7009,2773.865,111.0617,0,0,1,0,100,0),
(@PATH,3,144.2007,2764.989,105.126,0,0,1,0,100,0),
(@PATH,4,113.7401,2748.569,96.21298,0,0,1,0,100,0),
(@PATH,5,94.41273,2728.12,89.81252,0,0,1,0,100,0),
(@PATH,6,65.77112,2693.39,82.38187,0,0,1,0,100,0),
(@PATH,7,36.76459,2661.932,76.78915,0,0,1,0,100,0),
(@PATH,8,17.91903,2638.404,72.61198,0,0,1,0,100,0),
(@PATH,9,5.355525,2605.847,68.47747,0,0,1,0,100,0),
(@PATH,10,8.97837,2575.031,65.2146,0,0,1,0,100,0),
(@PATH,11,18.05011,2542.307,61.65181,0,0,1,0,100,0),
(@PATH,12,20.63871,2501.002,57.12801,0,0,1,0,100,0),
(@PATH,13,14.14331,2460.918,53.1017,0,0,1,0,100,0),
(@PATH,14,7.45386,2419.164,52.73537,0,0,1,0,100,0),
(@PATH,15,-14.25867,2395.82,52.69493,0,0,1,0,100,0),
(@PATH,16,-31.19849,2384.302,53.77038,0,0,1,0,100,0),
(@PATH,17,0.05626106,2409.986,52.19868,0,0,1,0,100,0),
(@PATH,18,13.30882,2456.084,52.34318,0,0,1,0,100,0),
(@PATH,19,20.00414,2492.995,56.18382,0,0,1,0,100,0),
(@PATH,20,19.18841,2536.792,60.81985,0,0,1,0,100,0),
(@PATH,21,11.05238,2567.616,64.15677,0,0,1,0,100,0),
(@PATH,22,4.750309,2601.44,67.78731,0,0,1,0,100,0),
(@PATH,23,13.32799,2630.8,71.16357,0,0,1,0,100,0),
(@PATH,24,32.40791,2656.75,75.65665,0,0,1,0,100,0),
(@PATH,25,62.52131,2689.98,81.53972,0,0,1,0,100,0),
(@PATH,26,92.98247,2726.685,89.31989,0,0,1,0,100,0),
(@PATH,27,109.4178,2744.999,94.76643,0,0,1,0,100,0),
(@PATH,28,142.0419,2764.24,104.1994,0,0,1,0,100,0),
(@PATH,29,171.1686,2772.708,110.2985,0,0,1,0,100,0);
-- 0x1C09E442401035C000002C00005AED54 .go 196.28 2781.241 115.9637

-- Pathing for Thrallmar Peon Entry: 16591 'TDB FORMAT' 
SET @NPC := 57575;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=55.27306,`position_y`=2654.043,`position_z`=78.42071 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,55.27306,2654.043,78.42071,0,0,0,0,100,0),
(@PATH,2,60.95808,2657.462,79.7836,0,0,0,0,100,0),
(@PATH,3,64.60378,2660.895,80.497,0,0,0,0,100,0),
(@PATH,4,66.75615,2663.12,80.74207,0,0,0,0,100,0),
(@PATH,5,65.12799,2682.579,80.74263,0,0,0,0,100,0),
(@PATH,6,65.82681,2693.285,82.36795,0,0,0,0,100,0),
(@PATH,7,75.21483,2707.858,84.6664,0,0,0,0,100,0),
(@PATH,8,84.96182,2718.535,87.05235,0,0,0,0,100,0),
(@PATH,9,95.03929,2728.742,90.13913,0,0,0,0,100,0),
(@PATH,10,106.4619,2744.316,94.00992,0,0,0,0,100,0),
(@PATH,11,123.8118,2755.292,99.37874,0,0,0,0,100,0),
(@PATH,12,135.8948,2760.833,102.7533,0,0,0,0,100,0),
(@PATH,13,155.0525,2769.579,107.7352,0,0,0,0,100,0),
(@PATH,14,158.3794,2773.243,108.8904,0,0,0,0,100,0),
(@PATH,15,159.9402,2783.268,111.4848,0,0,0,0,100,0),
(@PATH,16,161.3573,2786.643,112.5604,0,0,0,0,100,0),
(@PATH,17,165.1619,2790.098,113.5347,0,120000,0,0,100,0),
(@PATH,18,165.2408,2775.052,109.6661,3,0,0,0,100,0),
(@PATH,19,161.6743,2781.431,111.1523,0,0,0,0,100,0),
(@PATH,20,161.0955,2772.586,109.2963,0,0,0,0,100,0),
(@PATH,21,143.7382,2764.468,104.6033,0,0,0,0,100,0),
(@PATH,22,122.8,2754.483,99.03847,0,0,0,0,100,0),
(@PATH,23,109.0177,2745.05,94.75985,0,0,0,0,100,0),
(@PATH,24,96.74924,2729.785,90.4996,0,0,0,0,100,0),
(@PATH,25,83.87657,2715.537,86.72665,0,0,0,0,100,0),
(@PATH,26,75.78943,2705.43,84.61099,0,0,0,0,100,0),
(@PATH,27,64.73528,2690.525,81.81812,0,0,0,0,100,0),
(@PATH,28,62.68444,2679.1,80.26672,0,0,0,0,100,0),
(@PATH,29,62.20171,2674.227,80.11406,0,0,0,0,100,0),
(@PATH,30,62.53893,2659.067,79.85791,0,0,0,0,100,0),
(@PATH,31,53.87121,2650.147,77.64667,0,0,0,0,100,0),
(@PATH,32,52.78874,2648.066,76.98107,0,120000,0,0,100,0);
-- 0x1C09E442401033C000002C00005AED55 .go 55.27306 2654.043 78.42071
-- Shakes O'Breen SAI
SET @ENTRY := 2610;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', ScriptName='' WHERE `entry`=113531;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 113531  AND `source_type` = 1;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,19,0,100,0,667,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Quest 'Death From Below' Taken - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,6,667,0,0,0,0,0,18,30,0,0,0,0,0,0,"Shakes O'Breen - On Just Died - Fail Quest 'Death From Below'"),
(@ENTRY,0,2,0,11,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Respawn - Add Npc Flag Questgiver"),
(@ENTRY,0,3,4,61,0,100,0,667,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Quest 'Death From Below' Taken - Remove Npc Flag Questgiver"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Just Created - react agressive"),
(113531,1,0,0,64,0,100,0,0,0,0,0,51,0,0,0,0,0,0,11,2775,50,0,0,0,0,0,"Shakes O'Breen - On gossip hello - kill");

-- Actionlist SAI
SET @ENTRY := 261000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,106,4,0,0,0,0,0,14,210721,113531,0,0,0,0,0,"Shakes O'Breen - On Script - remove flag from gob "),
(@ENTRY,9,2,0,0,0,100,0,9000,9000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.246582, -1965.681763, 15.063377, 5.600158,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.358643, -1971.417480, 15.596241, 4.967206,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,6,0,0,0,100,0,20000,20000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.246582, -1965.681763, 15.063377, 5.600158,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Say Line 1"),
(@ENTRY,9,10,0,0,0,100,0,15000,15000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,105,4,0,0,0,0,0,14,210721,113531,0,0,0,0,0,"Shakes O'Breen - On Script - Add  Flag to gob "),
(@ENTRY,9,13,0,0,0,100,0,30000,30000,0,0,15,667,0,0,0,0,0,17,0,100,0,0,0,0,0,"Shakes O'Breen - On Script - Quest Credit 'Death From Below'"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Add Npc Flag ");

-- Daggerspine Marauder SAI
SET @ENTRY := 2775;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Marauder - On Just Created - Say Line 0"),
(@ENTRY,0,1,0,63,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-2086.070068, -2028.859985, 3.220880, 2.670350,"Daggerspine Marauder - On Just Created - go to pos"),
(@ENTRY,0,2,0,63,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Marauder - On Just Created - react agressive"),
(@ENTRY,0,3,0,10,0,100,0,0,30,3000,3000,49,0,0,0,0,0,0,19,2610,30,0,0,0,0,0,"Daggerspine Marauder - OOCLOS - Attack start");

DELETE FROM `creature_text` WHERE `entry` IN (2775, 2610);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(2775, 0, 0, 'Nothing will stop us! You will die!', 14, 0, 100, 0, 0, 0, 855, 0, 'Daggerspine Marauder'),
(2775, 0, 1, 'You''ve plundered our treasures too long.  Prepare to meet your watery grave!', 14, 0, 100, 0, 0, 0, 854, 0, 'Daggerspine Marauder'),
(2610, 0, 0, 'All hands to battle stations! Naga incoming!', 14, 0, 100, 0, 0, 0, 6372, 0, 'Shakes Breen'),
(2610, 1, 0, 'If we can just hold them now, I am sure we will be in the clear.', 12, 0, 100, 0, 0, 0, 863, 0, 'Shakes Breen');
--
UPDATE `creature_template` SET `vehicleId`=196 WHERE `entry`=30108;
DELETE FROM `vehicle_template_accessory` WHERE `entry`=30108 AND `accessory_entry` IN (30401);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(30108,30401,1,1,'Stormcrest Eagle',8,0);

UPDATE `creature_template` SET `ScriptName` = 'npc_stormcrest_eagle' WHERE `entry` = 30108;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9891 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(9891, 0, 0, 'King Stormheart sent me to be tested as a frostborn would. I am ready for my test, Fjorlin', 32929, 1, 1, 0, 0, 0, 0, '',0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceEntry`=0 AND `SourceGroup`=9891;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`elseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,9891,0,9,0,12874,0,0,0,'show gossip on quest 12874 taken');

-- Fjorlin Frostbrow SAI
SET @ENTRY := 29732;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9891,1,0,0,11,56411,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 1 Selected - Cast 'Forcecast Summon Scripted Eagle'"),
(@ENTRY,0,1,0,61,0,100,0,9891,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 1 Selected - Close Gossip"),
(@ENTRY,0,2,3,62,0,100,0,9891,0,0,0,85,55942,2,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 0 Selected - Invoker Cast 'Summon Battle Eagle'"),
(@ENTRY,0,3,0,61,0,100,0,9891,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=30108;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(30108,46598,1,0);

UPDATE `creature_template` SET `ScriptName`='', `InhabitType`=4 WHERE  `entry`=30108;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30108;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 30108, 0, 0, 9, 0, 12874, 0, 0, 0, 0, 0, '', 'SAI triggers only if player on quest 12874');

DELETE FROM `creature_text` WHERE `entry`=30401;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextId`) VALUES
(30401, 0, 0, 'King Stormheart is putting you to the test, eh? He must see something in you to begin with or I doubt he''d put you through such a sacred ritual.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30942),
(30401, 1, 0, 'I know you''re new to our kind, so I''ll catch you up a bit while we''re on our way over.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30943),
(30401, 2, 0, 'Years back, my father and several other frostborn were returning from a trek across Dragonblight. There was a heavy blizzard... far worse than we''ve ever seen since.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30944),
(30401, 3, 0, 'They crossed a trail of blood-soaked snow and followed it to find a dwarf wandering and speaking in a dialect they couldn''t make out... and not a dwarf of our kind mind you, but a mountain dwarf - something our kind had never seen before.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30945),
(30401, 4, 0, 'The dwarf seemed lost, having no memory of where he came from, or even of his own name. Not being the kind to leave a dwarven cousin to die in the snow, my father''s party took him in and continued back towards Frosthold.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30946),
(30401, 5, 0, 'Not long later, out of nowhere, the snow burst before them and a jormungar the size of Veranus herself came down upon their party... one of them was swallowed whole before they even had time to react.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30947),
(30401, 6, 0, 'My father thought they were all doomed... but behind him, a furious roar rumbled across the snow, and he turned to see the mountain dwarf growing in size, his skin taking on a stone-like texture, and his hands sizzling with lightning.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30948),
(30401, 7, 0, 'The dwarf barreled forward with a sound like rolling thunder and hurled a shining metal hammer, lightning coursing over its surface, directly into the jormungar''s throat.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30949),
(30401, 8, 0, 'The jormungar collapsed instantly, its head barely still attached to its convulsing body. My father turned to the dwarf in awe and raised a fist in praise...', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30950),
(30401, 9, 0, 'The stranger having no name of his own, my father deemed \"Yorg,\" a name reserved for champions of legend. Years later, he now stands before us as Yorg Stormheart, King of the Frostborn.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30952),
(30401, 10, 0, 'King Stormheart has trained us well... turned us into even more fearsome warriors than we could have boasted during the time of our war with the Frost Giants.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30953),
(30401, 11, 0, 'And as one of the fiercest tests put upon a warrior of the frostborn, we are made to face a creature far larger than ourselves--giants, dragons, jormungar--as a testament to the fact that size will never be our weakness.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30955),
(30401, 12, 0, 'This is the test put before you this day. Return to us only once The Iron Watcher is dead, and be revered as a warrior of the frostborn.', 14, 0, 100, 0, 0, 0, 'Velog Icebellow',30956),
(30401, 13, 0, 'He is slow from the rust of the ages... be quick on your feet and he will not best you. You have King Stormheart''s favor - do not disappoint.', 14, 0, 100, 0, 0, 0, 'Velog Icebellow',31343);

DELETE FROM `creature_template_addon` WHERE `entry`=30108;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30108,0,0,0,1,0,'52211'); -- Flight Aura

DELETE FROM `spell_target_position` WHERE id=55942;
INSERT INTO `spell_target_position` (`ID`,`MapID`,`PositionX`,`PositionY`,`PositionZ`) VALUES
(55942, 571, 6610.838379, -280.558685, 984.428772);

-- Stormcrest Eagle SAI
SET @ENTRY := 30108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,53,1,30108,0,0,0,0,1,0,0,0,0,0,0,0,"Stormcrest Eagle - On Passenger Boarded - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,30108,0,0,1,0,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,0,40,0,100,0,2,30108,0,0,1,1,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 2 Reached - Say Line 1"),
(@ENTRY,0,3,0,40,0,100,0,4,30108,0,0,1,2,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 4 Reached - Say Line 2"),
(@ENTRY,0,4,0,40,0,100,0,6,30108,0,0,1,3,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 6 Reached - Say Line 3"),
(@ENTRY,0,5,0,40,0,100,0,8,30108,0,0,1,4,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 8 Reached - Say Line 4"),
(@ENTRY,0,6,0,40,0,100,0,10,30108,0,0,1,5,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 10 Reached - Say Line 5"),
(@ENTRY,0,7,0,40,0,100,0,12,30108,0,0,1,6,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 12 Reached - Say Line 6"),
(@ENTRY,0,8,0,40,0,100,0,14,30108,0,0,1,7,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 14 Reached - Say Line 7"),
(@ENTRY,0,9,0,40,0,100,0,16,30108,0,0,1,8,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 16 Reached - Say Line 8"),
(@ENTRY,0,10,0,40,0,100,0,18,30108,0,0,1,9,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 18 Reached - Say Line 9"),
(@ENTRY,0,12,0,40,0,100,0,22,30108,0,0,1,10,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 22 Reached - Say Line 10"),
(@ENTRY,0,13,0,40,0,100,0,24,30108,0,0,1,11,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 24 Reached - Say Line 11"),
(@ENTRY,0,14,0,40,0,100,0,25,30108,0,0,1,12,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 25 Reached - Say Line 12"),
(@ENTRY,0,15,0,40,0,100,0,26,30108,0,0,1,13,0,0,0,0,0,19,30401,10,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 26 Reached - Say Line 13"),
(@ENTRY,0,16,0,40,0,100,0,28,30108,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormcrest Eagle - On Waypoint 28 Reached - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=30108;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(30108, 1, 6586.2, -294.997, 989.82, 'Eagle'),
(30108, 2, 6519.83, -384.722, 994.117, 'Eagle'),
(30108, 3, 6519.97, -524.613, 986.315, 'Eagle'),
(30108, 4, 6582.99, -676.868, 973.055, 'Eagle'),
(30108, 5, 6687.48, -733.39, 964.698, 'Eagle'),
(30108, 6, 6855.16, -744.853, 961.192, 'Eagle'),
(30108, 7, 6994.31, -760.115, 959.543, 'Eagle'),
(30108, 8, 7119.54, -785.058, 970.552, 'Eagle'),
(30108, 9, 7245.46, -832.456, 982.112, 'Eagle'),
(30108, 10, 7372.43, -884.75, 992.92, 'Eagle'),
(30108, 11, 7451.38, -912.608, 999.791, 'Eagle'),
(30108, 12, 7550.54, -946.482, 1008.39, 'Eagle'),
(30108, 13, 7627.06, -969.296, 1025.31, 'Eagle'),
(30108, 14, 7701.49, -991.429, 1041.78, 'Eagle'),
(30108, 15, 7767.2, -1011.33, 1056.82, 'Eagle'),
(30108, 16, 7837.09, -1032.49, 1072.82, 'Eagle'),
(30108, 17, 7898.99, -1053.29, 1090.37, 'Eagle'),
(30108, 18, 7944.64, -1070.18, 1112.88, 'Eagle'),
(30108, 19, 7995.38, -1111.07, 1138.38, 'Eagle'),
(30108, 20, 8075.38, -1184.51, 1180.87, 'Eagle'),
(30108, 21, 8133, -1259.6, 1214.29, 'Eagle'),
(30108, 22, 8221.79, -1381.51, 1271, 'Eagle'),
(30108, 23, 8300.22, -1485.87, 1321.57, 'Eagle'),
(30108, 24, 8367.07, -1592.58, 1382.36, 'Eagle'),
(30108, 25, 8414.48, -1701.68, 1449.03, 'Eagle'),
(30108, 26, 8456.78, -1783.6, 1462.78, 'Eagle'),
(30108, 27, 8482.2, -1838.47, 1470, 'Eagle'),
(30108, 28, 8526.7, -1956.21, 1473.59, 'Eagle');
-- Fix up formation from last commit
-- https://github.com/TrinityCore/TrinityCore/commit/bbcf8f58e69d361c3df1c37fa79d1efa3e52bc54
DELETE FROM `creature_formations` WHERE `leaderGUID`=57594;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57594, 57594, 0, 0, 2),
(57594, 57595, 5, 0, 2),
(57594, 57596, 10, 0, 2),
(57594, 57597, 15, 0, 2);

DELETE FROM `creature_formations` WHERE `leaderGUID`=57965;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57965, 57965, 0, 0, 2),
(57965, 57966, 5, 0, 2),
(57965, 57967, 10, 0, 2),
(57965, 57968, 15, 0, 2);

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58706;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-372.7111,`position_y`=2839.348,`position_z`=3.085857 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-372.7111,2839.348,3.085857,0,0,0,0,100,0),
(@PATH,2,-369.1973,2833.291,3.833567,0,0,0,0,100,0),
(@PATH,3,-366.1855,2828.1,4.404455,0,0,0,0,100,0),
(@PATH,4,-364.1777,2824.639,5.029455,0,0,0,0,100,0),
(@PATH,5,-363.1738,2822.908,5.654455,0,0,0,0,100,0),
(@PATH,6,-361.668,2820.313,6.279455,0,0,0,0,100,0),
(@PATH,7,-360.6641,2818.582,7.029455,0,0,0,0,100,0),
(@PATH,8,-357.6523,2813.391,7.904455,0,0,0,0,100,0),
(@PATH,9,-354.6406,2808.199,8.654455,0,0,0,0,100,0),
(@PATH,10,-352.1309,2803.873,9.279455,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C0000212A8F .go -372.7111 2839.348 3.085857

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58710;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-173.5004,`position_y`=2340.303,`position_z`=60.07005 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-173.5004,2340.303,60.07005,0,0,0,0,100,0),
(@PATH,2,-167.5776,2345.781,59.66853,0,0,0,0,100,0),
(@PATH,3,-168.3658,2358.138,57.73066,0,0,0,0,100,0),
(@PATH,4,-170.6648,2371.729,55.37167,0,0,0,0,100,0),
(@PATH,5,-176.5131,2386.787,51.77451,0,0,0,0,100,0),
(@PATH,6,-179.7427,2391.649,50.90343,0,0,0,0,100,0),
(@PATH,7,-179.451,2411.232,48.48401,0,0,0,0,100,0),
(@PATH,8,-181.9889,2397.549,50.08649,0,0,0,0,100,0),
(@PATH,9,-179.687,2391.666,50.90021,0,0,0,0,100,0),
(@PATH,10,-172.3989,2376.937,54.03761,0,0,0,0,100,0),
(@PATH,11,-168.9601,2362.579,56.66465,0,0,0,0,100,0),
(@PATH,12,-167.4705,2349.302,59.07915,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C000021381E .go -173.5004 2340.303 60.07005

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58709;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-280.5386,`position_y`=2385.487,`position_z`=49.5167 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-280.5386,2385.487,49.5167,0,0,0,0,100,0),
(@PATH,2,-274.4911,2399.897,49.77866,0,0,0,0,100,0),
(@PATH,3,-282.391,2415.943,47.12805,0,0,0,0,100,0),
(@PATH,4,-292.0588,2418.96,45.69984,0,0,0,0,100,0),
(@PATH,5,-296.9233,2425.813,44.45638,0,0,0,0,100,0),
(@PATH,6,-288.1144,2443.262,43.60903,0,0,0,0,100,0),
(@PATH,7,-293.5082,2451.608,42.39658,0,0,0,0,100,0),
(@PATH,8,-297.1542,2466.072,41.27671,0,0,0,0,100,0),
(@PATH,9,-296.9443,2470.941,40.92609,0,0,0,0,100,0),
(@PATH,10,-284.6176,2477.495,40.50471,0,0,0,0,100,0),
(@PATH,11,-290.6595,2483.031,40.95429,0,0,0,0,100,0),
(@PATH,12,-284.6285,2477.351,40.70044,0,0,0,0,100,0),
(@PATH,13,-297.5089,2457.768,41.62237,0,0,0,0,100,0),
(@PATH,14,-289.9194,2446.963,43.04158,0,0,0,0,100,0),
(@PATH,15,-287.7819,2443.668,43.38817,0,0,0,0,100,0),
(@PATH,16,-296.9543,2424.329,44.54842,0,0,0,0,100,0),
(@PATH,17,-284.9567,2418.073,46.32718,0,0,0,0,100,0),
(@PATH,18,-276.5181,2404.314,49.4864,0,0,0,0,100,0),
(@PATH,19,-280.4977,2385.4,49.48282,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C0000213910 .go -280.5386 2385.487 49.5167

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58708;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-314.1599,`position_y`=2611.343,`position_z`=41.12054 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-314.1599,2611.343,41.12054,0,0,0,0,100,0),
(@PATH,2,-302.6028,2572.273,41.00031,0,0,0,0,100,0),
(@PATH,3,-297.84,2550.173,41.36596,0,0,0,0,100,0),
(@PATH,4,-303.8246,2525.236,42.58739,0,0,0,0,100,0),
(@PATH,5,-297.9362,2545.895,41.70477,0,0,0,0,100,0),
(@PATH,6,-300.882,2566.604,41.32217,0,0,0,0,100,0),
(@PATH,7,-306.6208,2578.347,41.52526,0,0,0,0,100,0),
(@PATH,8,-312.7142,2588.381,41.36144,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C00002139B5 .go -314.1599 2611.343 41.12054

-- Add missing Bonechewer Raider
DELETE FROM `creature` WHERE `guid`=29980;
INSERT INTO `creature` (`guid`, `id`, `map`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `MovementType`) VALUES 
(29980, 16925, 530, 1, -354.3998, 2663.006, 41.72623, 0, 300, 3989, 2);

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 29980;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-354.3998,`position_y`=2663.006,`position_z`=41.72623 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-354.3998,2663.006,41.72623,0,0,0,0,100,0),
(@PATH,2,-346.7007,2672.114,38.15508,0,0,0,0,100,0),
(@PATH,3,-332.8381,2681.229,34.02082,0,0,0,0,100,0),
(@PATH,4,-319.6889,2687.015,31.10067,0,0,0,0,100,0),
(@PATH,5,-318.0042,2694.25,29.72155,0,0,0,0,100,0),
(@PATH,6,-324.0378,2716.413,25.33266,0,0,0,0,100,0),
(@PATH,7,-319.7849,2729.284,23.22117,0,0,0,0,100,0),
(@PATH,8,-322.0183,2746.254,18.96142,0,0,0,0,100,0),
(@PATH,9,-322.4724,2747.062,18.86184,0,0,0,0,100,0),
(@PATH,10,-322.3822,2746.857,18.3417,0,0,0,0,100,0),
(@PATH,11,-319.7568,2733.282,22.47406,0,0,0,0,100,0),
(@PATH,12,-323.8112,2718.555,24.77036,0,0,0,0,100,0),
(@PATH,13,-317.9898,2696.302,28.92368,0,0,0,0,100,0),
(@PATH,14,-318.5087,2690.603,30.36932,0,0,0,0,100,0),
(@PATH,15,-329.6577,2682.807,32.7053,0,0,0,0,100,0),
(@PATH,16,-344.2849,2674.339,36.96185,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C0000213896 .go -354.3998 2663.006 41.72623

-- Only one Tagar Spinebreaker should be spawned
DELETE FROM `creature` WHERE `guid`=85990;

-- Pathing for Tagar Spinebreaker Entry: 19443 'TDB FORMAT' 
SET @NPC := 85987;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-179.7917,`position_y`=2839.993,`position_z`=23.64687 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-179.7917,2839.993,23.64687,0,0,0,0,100,0),
(@PATH,2,-168.0662,2837.727,26.36559,0,0,0,0,100,0),
(@PATH,3,-149.3422,2826.91,33.67762,0,0,0,0,100,0),
(@PATH,4,-149.3403,2813.561,35.25396,0,0,0,0,100,0),
(@PATH,5,-160.4427,2807.621,32.6923,0,0,0,0,100,0),
(@PATH,6,-172.6706,2803.528,29.62396,0,0,0,0,100,0),
(@PATH,7,-185.5681,2808.792,25.53679,0,0,0,0,100,0),
(@PATH,8,-186.3388,2797.655,26.33011,0,0,0,0,100,0),
(@PATH,9,-153.882,2788.701,36.85746,0,0,0,0,100,0),
(@PATH,10,-134.5498,2778.104,41.05849,0,0,0,0,100,0),
(@PATH,11,-120.4556,2753.937,49.37396,0,0,0,0,100,0),
(@PATH,12,-110.122,2737.952,52.16914,0,0,0,0,100,0),
(@PATH,13,-108.798,2709.016,51.00445,0,0,0,0,100,0),
(@PATH,14,-125.7525,2695.987,46.92542,0,0,0,0,100,0),
(@PATH,15,-165.7749,2686.863,43.39313,0,0,0,0,100,0),
(@PATH,16,-166.924,2686.502,43.27299,0,0,0,0,100,0),
(@PATH,17,-170.6192,2661.56,42.24799,0,0,0,0,100,0),
(@PATH,18,-166.9141,2633.801,41.55241,0,0,0,0,100,0),
(@PATH,19,-165.2749,2618.521,40.12231,0,0,0,0,100,0),
(@PATH,20,-164.5241,2612.235,40.08208,0,0,0,0,100,0),
(@PATH,21,-162.7764,2603.097,40.06981,0,0,0,0,100,0),
(@PATH,22,-165.0483,2590.722,39.90811,0,0,0,0,100,0),
(@PATH,23,-144.7979,2569.513,41.10892,0,0,0,0,100,0),
(@PATH,24,-146.1405,2544.73,40.98074,0,0,0,0,100,0),
(@PATH,25,-156.8518,2539.49,42.95174,0,0,0,0,100,0),
(@PATH,26,-170.4912,2527.817,41.62189,0,0,0,0,100,0),
(@PATH,27,-177.3363,2516.895,41.11181,0,0,0,0,100,0),
(@PATH,28,-176.3846,2510.593,41.94983,0,0,0,0,100,0),
(@PATH,29,-168.8438,2501.025,43.79488,0,0,0,0,100,0),
(@PATH,30,-145.8467,2499.76,45.61186,0,0,0,0,100,0),
(@PATH,31,-131.4405,2495.996,46.55548,0,0,0,0,100,0),
(@PATH,32,-124.8685,2492.812,46.93701,0,0,0,0,100,0),
(@PATH,33,-118.3926,2470.393,46.95731,0,0,0,0,100,0),
(@PATH,34,-134.5914,2450.625,46.18983,0,0,0,0,100,0),
(@PATH,35,-139.636,2439.596,48.65514,0,0,0,0,100,0),
(@PATH,36,-153.0726,2420.765,44.33873,0,0,0,0,100,0),
(@PATH,37,-164.3153,2415.917,48.36614,0,0,0,0,100,0),
(@PATH,38,-176.0278,2408.138,48.95763,0,0,0,0,100,0),
(@PATH,39,-181.3092,2397.231,50.16575,0,0,0,0,100,0),
(@PATH,40,-174.2651,2386.537,51.88837,0,0,0,0,100,0),
(@PATH,41,-171.3092,2382.064,53.20797,0,0,0,0,100,0),
(@PATH,42,-168.7256,2366.751,56.15277,0,0,0,0,100,0),
(@PATH,43,-168.0793,2352.929,58.49963,0,0,0,0,100,0),
(@PATH,44,-168.3409,2341.554,60.14597,0,0,0,0,100,0),
(@PATH,45,-175.721,2327.79,62.15151,0,0,0,0,100,0),
(@PATH,46,-193.0925,2317.189,56.10988,0,0,0,0,100,0),
(@PATH,47,-211.1901,2312.889,49.67965,0,0,0,0,100,0),
(@PATH,48,-243.0014,2311.802,51.36759,0,0,0,0,100,0),
(@PATH,49,-257.705,2324.297,56.98617,0,0,0,0,100,0),
(@PATH,50,-267.8463,2334.503,54.92202,0,0,0,0,100,0),
(@PATH,51,-284.0244,2347.267,51.85397,0,0,0,0,100,0),
(@PATH,52,-285.5917,2348.854,51.30281,0,0,0,0,100,0),
(@PATH,53,-277.6388,2384.371,49.04704,0,0,0,0,100,0),
(@PATH,54,-277.4207,2389,49.55646,0,0,0,0,100,0),
(@PATH,55,-282.4726,2415.647,47.11025,0,0,0,0,100,0),
(@PATH,56,-290.6383,2417.861,45.76169,0,0,0,0,100,0),
(@PATH,57,-296.9912,2425.083,44.68782,0,0,0,0,100,0),
(@PATH,58,-297.4091,2429.13,44.28957,0,0,0,0,100,0),
(@PATH,59,-292.8183,2446.393,42.99865,0,0,0,0,100,0),
(@PATH,60,-297.4739,2458.016,41.8229,0,0,0,0,100,0),
(@PATH,61,-299.0847,2461.294,41.30234,0,0,0,0,100,0),
(@PATH,62,-291.5309,2472.148,40.82636,0,0,0,0,100,0),
(@PATH,63,-315.7325,2479.059,38.88892,0,0,0,0,100,0),
(@PATH,64,-333.1553,2479.061,30.43475,0,0,0,0,100,0),
(@PATH,65,-362.027,2481.302,26.76814,0,0,0,0,100,0),
(@PATH,66,-381.832,2489.02,35.44767,0,0,0,0,100,0),
(@PATH,67,-383.683,2499.09,43.07095,0,0,0,0,100,0),
(@PATH,68,-373.0249,2518.307,44.52934,0,0,0,0,100,0),
(@PATH,69,-356.4537,2524.72,43.92796,0,0,0,0,100,0),
(@PATH,70,-341.8646,2517.716,42.69872,0,0,0,0,100,0),
(@PATH,71,-325.4874,2514.352,39.74596,0,0,0,0,100,0),
(@PATH,72,-317.6911,2517.743,42.27646,0,0,0,0,100,0),
(@PATH,73,-307.9288,2522.574,42.47154,0,0,0,0,100,0),
(@PATH,74,-303.3547,2545.351,42.88755,0,0,0,0,100,0),
(@PATH,75,-313.6268,2562.334,44.01721,0,0,0,0,100,0),
(@PATH,76,-319.8146,2564.861,44.6563,0,0,0,0,100,0),
(@PATH,77,-315.3898,2592.442,41.60535,0,0,0,0,100,0),
(@PATH,78,-315.032,2593.062,41.37146,0,0,0,0,100,0),
(@PATH,79,-333.1518,2616.684,42.40425,0,0,0,0,100,0),
(@PATH,80,-352.777,2633.742,40.45049,0,0,0,0,100,0),
(@PATH,81,-360.1994,2656.165,43.72129,0,0,0,0,100,0),
(@PATH,82,-344.7037,2680.905,36.1579,0,0,0,0,100,0),
(@PATH,83,-334.6349,2700.036,30.34241,0,0,0,0,100,0),
(@PATH,84,-324.9058,2712.125,26.43651,0,0,0,0,100,0),
(@PATH,85,-322.9779,2724.364,23.96236,0,0,0,0,100,0),
(@PATH,86,-326.3518,2734.545,22.44383,0,0,0,0,100,0),
(@PATH,87,-342.5912,2742.288,22.4451,0,0,0,0,100,0),
(@PATH,88,-368.7488,2739.919,27.63747,0,0,0,0,100,0),
(@PATH,89,-392.2097,2734.005,34.55191,0,0,0,0,100,0),
(@PATH,90,-414.4307,2741.14,39.55831,0,0,0,0,100,0),
(@PATH,91,-436.1942,2742.233,45.3562,0,0,0,0,100,0),
(@PATH,92,-462.9823,2756.808,49.85812,0,0,0,0,100,0),
(@PATH,93,-480.5942,2778.588,50.47923,0,0,0,0,100,0),
(@PATH,94,-476.0007,2799.573,45.95654,0,0,0,0,100,0),
(@PATH,95,-458.507,2835.351,35.33127,0,0,0,0,100,0),
(@PATH,96,-431.757,2863.309,23.74757,0,0,0,0,100,0),
(@PATH,97,-413.4223,2892.728,17.20714,0,0,0,0,100,0),
(@PATH,98,-419.2291,2905.467,19.51181,0,0,0,0,100,0),
(@PATH,99,-443.1462,2933.887,17.85199,0,0,0,0,100,0),
(@PATH,100,-438.8401,2966.167,8.723536,0,0,0,0,100,0),
(@PATH,101,-444.0433,2936.331,17.40722,0,0,0,0,100,0),
(@PATH,102,-432.5814,2918.56,19.31524,0,0,0,0,100,0),
(@PATH,103,-411.3571,2898.61,17.23361,0,0,0,0,100,0),
(@PATH,104,-429.0982,2867.209,22.665,0,0,0,0,100,0),
(@PATH,105,-457.4272,2836.473,34.75057,0,0,0,0,100,0),
(@PATH,106,-474.1913,2804.114,44.81591,0,0,0,0,100,0),
(@PATH,107,-481.0764,2783.36,50.09081,0,0,0,0,100,0),
(@PATH,108,-465.5521,2759.48,50.03743,0,0,0,0,100,0),
(@PATH,109,-440.5409,2744.546,46.12499,0,0,0,0,100,0),
(@PATH,110,-420.0836,2742.421,41.1034,0,0,0,0,100,0),
(@PATH,111,-397.9436,2734.918,35.90202,0,0,0,0,100,0),
(@PATH,112,-372.9858,2738.609,28.64789,0,0,0,0,100,0),
(@PATH,113,-348.4457,2742.212,23.42384,0,0,0,0,100,0),
(@PATH,114,-333.7679,2740.035,21.81408,0,0,0,0,100,0),
(@PATH,115,-324.9037,2731.125,22.83686,0,0,0,0,100,0),
(@PATH,116,-323.9969,2714.816,25.20854,0,0,0,0,100,0),
(@PATH,117,-332.7059,2702.867,29.4334,0,0,0,0,100,0),
(@PATH,118,-343.4227,2683.021,35.1899,0,0,0,0,100,0),
(@PATH,119,-359.6221,2658.229,43.55175,0,0,0,0,100,0),
(@PATH,120,-353.887,2635.825,39.48611,0,0,0,0,100,0),
(@PATH,121,-344.0572,2624.184,43.10011,0,0,0,0,100,0),
(@PATH,122,-325.4768,2613.256,41.99747,0,0,0,0,100,0),
(@PATH,123,-315.0096,2608.486,41.19632,0,0,0,0,100,0),
(@PATH,124,-325.0719,2578.15,44.60706,0,0,0,0,100,0),
(@PATH,125,-325.6835,2576.813,44.85286,0,0,0,0,100,0),
(@PATH,126,-313.8424,2562.751,43.86629,0,0,0,0,100,0),
(@PATH,127,-306.6296,2559.59,43.31482,0,0,0,0,100,0),
(@PATH,128,-303.079,2544.062,42.30245,0,0,0,0,100,0),
(@PATH,129,-324.1274,2514.437,40.29177,0,0,0,0,100,0),
(@PATH,130,-333.2019,2515.876,41.902,0,0,0,0,100,0),
(@PATH,131,-354.4488,2524.19,43.33042,0,0,0,0,100,0),
(@PATH,132,-359.7796,2523.489,44.53107,0,0,0,0,100,0),
(@PATH,133,-378.1317,2510.007,43.7447,0,0,0,0,100,0),
(@PATH,134,-382.583,2491,37.3352,0,0,0,0,100,0),
(@PATH,135,-368.7838,2483.057,28.09278,0,0,0,0,100,0),
(@PATH,136,-337.7688,2479.346,28.95182,0,0,0,0,100,0),
(@PATH,137,-318.8761,2478.915,37.70119,0,0,0,0,100,0),
(@PATH,138,-301.9458,2480.981,40.5145,0,0,0,0,100,0),
(@PATH,139,-300.0336,2481.129,40.53691,0,0,0,0,100,0),
(@PATH,140,-291.6542,2471.877,40.91128,0,0,0,0,100,0),
(@PATH,141,-295.2729,2454.313,42.07068,0,0,0,0,100,0),
(@PATH,142,-291.9165,2442.606,43.58534,0,0,0,0,100,0),
(@PATH,143,-290.83,2436.461,44.0534,0,0,0,0,100,0),
(@PATH,144,-296.628,2422.13,44.75555,0,0,0,0,100,0),
(@PATH,145,-284.9365,2416.829,46.52535,0,0,0,0,100,0),
(@PATH,146,-277.901,2404.396,49.46965,0,0,0,0,100,0),
(@PATH,147,-276.7875,2401.742,49.57491,0,0,0,0,100,0),
(@PATH,148,-275.867,2368.15,50.02176,0,0,0,0,100,0),
(@PATH,149,-280.12,2358.433,51.42045,0,0,0,0,100,0),
(@PATH,150,-271.6628,2337.664,53.90419,0,0,0,0,100,0),
(@PATH,151,-260.8519,2327.604,56.16253,0,0,0,0,100,0),
(@PATH,152,-246.7255,2313.879,53.0292,0,0,0,0,100,0),
(@PATH,153,-233.4331,2311.107,50.28912,0,0,0,0,100,0),
(@PATH,154,-194.8462,2316.223,54.13938,0,0,0,0,100,0),
(@PATH,155,-184.3219,2321.592,61.90179,0,0,0,0,100,0),
(@PATH,156,-169.6792,2336.901,61.27917,0,0,0,0,100,0),
(@PATH,157,-167.8382,2348.53,59.15134,0,0,0,0,100,0),
(@PATH,158,-168.2972,2362.321,57.01959,0,0,0,0,100,0),
(@PATH,159,-169.3826,2376.633,54.4596,0,0,0,0,100,0),
(@PATH,160,-171.8145,2382.753,52.97548,0,0,0,0,100,0),
(@PATH,161,-180.183,2392.34,51.01487,0,0,0,0,100,0),
(@PATH,162,-181.2741,2398.439,49.99238,0,0,0,0,100,0),
(@PATH,163,-175.461,2408.534,48.88574,0,0,0,0,100,0),
(@PATH,164,-157.5141,2417.718,45.03862,0,0,0,0,100,0),
(@PATH,165,-146.3332,2426.921,48.30313,0,0,0,0,100,0),
(@PATH,166,-137.9598,2445.376,46.12595,0,0,0,0,100,0),
(@PATH,167,-118.3926,2470.393,46.95731,0,0,0,0,100,0),
(@PATH,168,-124.8685,2492.812,46.93701,0,0,0,0,100,0),
(@PATH,169,-131.4405,2495.996,46.55548,0,0,0,0,100,0),
(@PATH,170,-145.8467,2499.76,45.61186,0,0,0,0,100,0),
(@PATH,171,-168.8438,2501.025,43.79488,0,0,0,0,100,0),
(@PATH,172,-176.3846,2510.593,41.94983,0,0,0,0,100,0),
(@PATH,173,-177.3363,2516.895,41.11181,0,0,0,0,100,0),
(@PATH,174,-170.4912,2527.817,41.62189,0,0,0,0,100,0),
(@PATH,175,-156.8518,2539.49,42.95174,0,0,0,0,100,0),
(@PATH,176,-146.1405,2544.73,40.98074,0,0,0,0,100,0),
(@PATH,177,-144.7979,2569.513,41.10892,0,0,0,0,100,0),
(@PATH,178,-165.0483,2590.722,39.90811,0,0,0,0,100,0),
(@PATH,179,-162.7764,2603.097,40.06981,0,0,0,0,100,0),
(@PATH,180,-164.5241,2612.235,40.08208,0,0,0,0,100,0),
(@PATH,181,-165.2749,2618.521,40.12231,0,0,0,0,100,0),
(@PATH,182,-166.9141,2633.801,41.55241,0,0,0,0,100,0),
(@PATH,183,-170.6192,2661.56,42.24799,0,0,0,0,100,0),
(@PATH,184,-166.924,2686.502,43.27299,0,0,0,0,100,0),
(@PATH,185,-165.7749,2686.863,43.39313,0,0,0,0,100,0),
(@PATH,186,-125.7525,2695.987,46.92542,0,0,0,0,100,0),
(@PATH,187,-108.798,2709.016,51.00445,0,0,0,0,100,0),
(@PATH,188,-110.122,2737.952,52.16914,0,0,0,0,100,0),
(@PATH,189,-120.4556,2753.937,49.37396,0,0,0,0,100,0),
(@PATH,190,-134.5498,2778.104,41.05849,0,0,0,0,100,0),
(@PATH,191,-153.882,2788.701,36.85746,0,0,0,0,100,0),
(@PATH,192,-186.3388,2797.655,26.33011,0,0,0,0,100,0),
(@PATH,193,-185.5681,2808.792,25.53679,0,0,0,0,100,0),
(@PATH,194,-172.6706,2803.528,29.62396,0,0,0,0,100,0),
(@PATH,195,-160.4427,2807.621,32.6923,0,0,0,0,100,0),
(@PATH,196,-149.3403,2813.561,35.25396,0,0,0,0,100,0),
(@PATH,197,-149.3422,2826.91,33.67762,0,0,0,0,100,0),
(@PATH,198,-168.0662,2837.727,26.36559,0,0,0,0,100,0),
(@PATH,199,-179.7917,2839.993,23.64687,0,0,0,0,100,0);
-- 0x1C09E4424012FCC000002C00005FBF34 .go -179.7917 2839.993 23.64687

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58704;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-404.7873,`position_y`=2895.921,`position_z`=13.85265 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-404.7873,2895.921,13.85265,0,0,0,0,100,0),
(@PATH,2,-404.2322,2900.299,14.15039,0,0,0,0,100,0),
(@PATH,3,-428.3772,2914.106,19.38362,0,0,0,0,100,0),
(@PATH,4,-439.7838,2928.416,18.55647,0,0,0,0,100,0),
(@PATH,5,-445.6255,2946.441,15.33809,0,0,0,0,100,0),
(@PATH,6,-439.2244,2964.096,9.26938,0,0,0,0,100,0),
(@PATH,7,-454.467,2971.035,9.009753,0,0,0,0,100,0),
(@PATH,8,-467.3622,2966.943,12.50773,0,0,0,0,100,0),
(@PATH,9,-482.1766,2976.099,11.32469,0,0,0,0,100,0),
(@PATH,10,-471.1085,2966.682,13.06236,0,0,0,0,100,0),
(@PATH,11,-456.4288,2970.18,9.417983,0,0,0,0,100,0),
(@PATH,12,-450.4304,2969.706,9.393501,0,0,0,0,100,0),
(@PATH,13,-446.038,2951.119,14.24401,0,0,0,0,100,0),
(@PATH,14,-442.8287,2934.824,17.44841,0,0,0,0,100,0),
(@PATH,15,-435.4904,2921.99,19.82334,0,0,0,0,100,0),
(@PATH,16,-404.6763,2913.004,15.59055,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C00005FACA1 .go -404.7873 2895.921 13.85265

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58705;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-394.2339,`position_y`=2891.354,`position_z`=8.341909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-394.2339,2891.354,8.341909,0,0,0,0,100,0),
(@PATH,2,-404.354,2907.934,14.82262,0,0,0,0,100,0),
(@PATH,3,-420.1548,2911.418,19.02849,0,0,0,0,100,0),
(@PATH,4,-434.6948,2920.658,19.59609,0,0,0,0,100,0),
(@PATH,5,-443.507,2937.645,16.52073,0,0,0,0,100,0),
(@PATH,6,-438.1014,2952.321,11.34356,0,0,0,0,100,0),
(@PATH,7,-445.5783,2967.97,9.331216,0,0,0,0,100,0),
(@PATH,8,-438.8247,2958.072,10.36737,0,0,0,0,100,0),
(@PATH,9,-442.9203,2943.862,15.03016,0,0,0,0,100,0),
(@PATH,10,-440.1529,2925.814,19.82526,0,0,0,0,100,0),
(@PATH,11,-430.9389,2917.94,18.84661,0,0,0,0,100,0),
(@PATH,12,-407.8214,2910.193,16.49719,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C00005FACD2 .go -394.2339 2891.354 8.341909

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58703;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-173.0258,`position_y`=2784.179,`position_z`=31.73058 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-184.2477,2841.474,22.17058,0,0,0,0,100,0),
(@PATH,2,-186.5912,2837.849,21.70995,0,0,0,0,100,0),
(@PATH,3,-186.0354,2821.816,23.10514,0,0,0,0,100,0),
(@PATH,4,-190.4859,2804.101,24.46144,0,0,0,0,100,0),
(@PATH,5,-190.1222,2800.265,25.05125,0,0,0,0,100,0),
(@PATH,6,-185.8087,2784.323,28.49104,0,0,0,0,100,0),
(@PATH,7,-173.0258,2784.179,31.73058,0,0,0,0,100,0),
(@PATH,8,-153.8195,2788.142,37.07464,0,0,0,0,100,0),
(@PATH,9,-146.762,2781.243,39.44977,0,0,0,0,100,0),
(@PATH,10,-150.9473,2773.002,39.19555,0,0,0,0,100,0),
(@PATH,11,-165.231,2763.583,36.20363,0,0,0,0,100,0),
(@PATH,12,-181.1507,2755.388,30.1041,0,0,0,0,100,0),
(@PATH,13,-168.6309,2761.67,34.94637,0,0,0,0,100,0),
(@PATH,14,-157.0087,2768.504,38.33034,0,0,0,0,100,0),
(@PATH,15,-147.9143,2776.101,39.64468,0,0,0,0,100,0),
(@PATH,16,-148.772,2785.843,38.60817,0,0,0,0,100,0),
(@PATH,17,-167.8991,2784.874,33.46256,0,0,0,0,100,0),
(@PATH,18,-185.8087,2784.323,28.49104,0,0,0,0,100,0),
(@PATH,19,-190.1222,2800.265,25.05125,0,0,0,0,100,0),
(@PATH,20,-190.4859,2804.101,24.46144,0,0,0,0,100,0),
(@PATH,21,-186.0354,2821.816,23.10514,0,0,0,0,100,0),
(@PATH,22,-186.5912,2837.849,21.70995,0,0,0,0,100,0),
(@PATH,23,-184.2477,2841.474,22.17058,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C00005FBE47 .go -173.0258 2784.179 31.73058

-- Pathing for Bonechewer Raider Entry: 16925 'TDB FORMAT' 
SET @NPC := 58707;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-180.3116,`position_y`=2686.223,`position_z`=40.81258 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17408,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-180.3116,2686.223,40.81258,0,0,0,0,100,0),
(@PATH,2,-175.7397,2679.259,42.18403,0,0,0,0,100,0),
(@PATH,3,-171.9714,2660.608,42.08878,0,0,0,0,100,0),
(@PATH,4,-170.7084,2658.794,42.01125,0,0,0,0,100,0),
(@PATH,5,-171.3484,2640.479,41.27383,0,0,0,0,100,0),
(@PATH,6,-171.948,2638.051,41.02221,0,0,0,0,100,0),
(@PATH,7,-165.7785,2619.644,40.29411,0,0,0,0,100,0),
(@PATH,8,-166.9228,2612.098,39.69428,0,0,0,0,100,0),
(@PATH,9,-169.5662,2594.979,39.33304,0,0,0,0,100,0),
(@PATH,10,-170.6965,2594.06,39.20753,0,0,0,0,100,0),
(@PATH,11,-170.8916,2594.003,38.98936,0,0,0,0,100,0),
(@PATH,12,-166.2133,2597.965,39.64554,0,0,0,0,100,0),
(@PATH,13,-163.8443,2600.274,39.8479,0,0,0,0,100,0),
(@PATH,14,-165.4025,2621.016,40.56765,0,0,0,0,100,0),
(@PATH,15,-164.8262,2624.799,41.17817,0,0,0,0,100,0),
(@PATH,16,-170.1738,2643.713,41.53741,0,0,0,0,100,0),
(@PATH,17,-169.1673,2647.221,41.99223,0,0,0,0,100,0),
(@PATH,18,-171.7151,2670.958,42.49662,0,0,0,0,100,0);
-- 0x1C09E4424010874000002C00005FBFA9 .go -180.3116 2686.223 40.81258
-- Darnassian Scout SAI
SET @ENTRY := 15968;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,75,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Scout - On Reset - Cast 'Stealth'"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,28,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Scout - On Aggro - Remove Aura 'Stealth'");
-- Nexus-King Salhadaar SAI
SET @ENTRY := 20454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,3,100,1,1000,1000,1000,1000,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Remove Flag Not Selectable (Phase 4) (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,1000,1000,1000,1000,2,1796,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Set Faction 1796 (Phase 4) (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Say Line 0 (Phase 4)"),
(@ENTRY,0,3,0,0,0,100,0,5000,10000,15000,25000,11,36533,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - In Combat - Cast 'Gravity Flux'"),
(@ENTRY,0,4,5,2,0,100,1,5,25,0,0,11,36848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Between 5-25% Health - Cast 'Mirror Image' (No Repeat)"),
(@ENTRY,0,5,0,61,0,100,0,5,25,0,0,11,36847,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Between 5-25% Health - Cast 'Mirror Image' (No Repeat)"),
(@ENTRY,0,6,0,0,0,100,0,15000,25000,10000,30000,11,36527,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus-King Salhadaar - In Combat - Cast 'Stasis'"),
(@ENTRY,0,7,8,7,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Faction 35"),
(@ENTRY,0,8,10,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,21425,20,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Data 1 1"),
(@ENTRY,0,9,0,38,0,100,0,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Data Set 1 1 - Increment Phase"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Event Phase 0");

-- Nexus-King Salhadaar SAI
SET @ENTRY := 21425;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Nexus-King Salhadaar - On Just Summoned - Start Attacking"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Data Set 1 1 - Despawn Instant");

-- remove randmmovement
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (73277, 73278, 73279);

-- Salaadin's Energy Ball SAI
SET @ENTRY := 20769;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salaadin's Energy Ball - On Respawn - Cast 'Purple Banish State' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,5000,5000,0,0,11,35515,0,0,0,0,0,9,20454,0,200,0,0,0,0,"Salaadin's Energy Ball - Out of Combat - Cast 'Salaadin's Tesla'"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salaadin's Energy Ball - On Data Set 1 1 - Despawn In 100 ms");

-- Protectorate Disruptor SAI
SET @ENTRY := 184561;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,1,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,20769,10,0,0,0,0,0,"Protectorate Disruptor - Out of Combat - Set Data 1 1 (No Repeat)"),
(@ENTRY,1,1,0,1,0,100,1,1000,1000,0,0,45,1,1,0,0,0,0,10,72462,20454,0,0,0,0,0,"Protectorate Disruptor - Out of Combat - Set Data 1 1 (No Repeat)");

DELETE FROM `creature_text` WHERE `entry` = 20454 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`, `BroadcastTextId`) VALUES
(20454, 0, 0, "Prepare to enter oblivion, meddlers. You have unleashed a god!", 14, 0, 100, "Nexus-King Salhadaar", 18443);

DELETE FROM `creature_text` WHERE `entry` = 20454 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`, `BroadcastTextID`) VALUES
(20454, 0, 0, "Prepare to enter oblivion, meddlers. You have unleashed a god!", 14, 0, 100, "Nexus-King Salhadaar", 18443);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=35515;
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,35515,64,'Ignore LOS on Salaadin\'s Tesla');
-- Plagueborn Horror SAI
SET @ENTRY := 36879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,69581,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Pustulant Flesh' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,10000,10000,11,70273,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Pustulant Flesh' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,8000,8000,8000,8000,11,70274,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plagueborn Horror - In Combat - Cast 'Toxic Waste' (Dungeon)"),
(@ENTRY,0,3,0,2,0,100,6,15,15,0,0,11,69582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - Between 15-15% Health - Cast 'Blight Bomb' (Dungeon)"),
(@ENTRY,0,4,5,1,0,100,0,0,0,120000,120000,11,58051,2,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - Out of Combat - Cast 'Summon Scourge Package'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,120000,120000,11,69702,2,0,0,0,0,9,30887,0,4,0,0,0,0,"Plagueborn Horror - Out of Combat - Cast 'Rope'"),
(@ENTRY,0,6,0,4,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,30887,0,10,0,0,0,0,"Plagueborn Horror - On Aggro - Set Data 1 1"),
(@ENTRY,0,7,8,25,0,100,0,0,0,0,0,11,58051,2,0,0,0,0,1,0,0,0,0,0,0,0,"Plagueborn Horror - On Reset - Cast 'Summon Scourge Package'"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,63413,2,0,0,0,0,9,30887,0,5,0,0,0,0,"Plagueborn Horror - On Reset - Cast 'Rope Beam'");

UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid` IN (201981,  201833, 202236, 201903);

-- Scourge Package SAI
SET @ENTRY := 30887;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,29,3,40,0,0,0,0,7,0,0,0,0,0,0,0,"Scourge Package - On Just Summoned - Start Follow Invoker"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Just Summoned - Run Random Script"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Data Set 1 1 - Despawn In 1000 ms");

-- Actionlist SAI
SET @ENTRY := 3088700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58016,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58022,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58020,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");

-- Actionlist SAI
SET @ENTRY := 3088703;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58023,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Scourge Package Visual'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Package - On Script - Set Faction 35");
-- Volcor SAI
SET @ENTRY := 3692;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,994,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest 'Escape Through Force' Taken - Run Script"),
(@ENTRY,0,1,0,19,0,100,0,995,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest 'Escape Through Stealth' Taken - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,15,3692,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Waypoint 15 Reached - Despawn Instant"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Aggro - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 369200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,53,0,3692,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,110000,110000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,15,994,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit 'Escape Through Force'");

-- Actionlist SAI
SET @ENTRY := 369201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,3,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,53,0,3692,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,110000,110000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 3"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,15,995,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit 'Escape Through Stealth'");
--
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4479;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4479, 'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4479 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4479, 2, 0, 0, 46, 0, 100, 0, 4479, 0, 0, 0, 85, 33728, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast Teleport Shattrath');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4479 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4479, 2, 0, 28, 0, 10280, 0, 0, 0, 0, '', 'Teleport only on Quest "Special Delivery to Shattrath City"');
--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=24 AND `SourceEntry`=522;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(14, 24, 522, 0, 0, 8, 0, 770, 0, 0, 1, 0, 0, 'Show gossip text if player do not has quest 770 completed');
-- Infiltrator Marksen SAI
SET @ENTRY := 5416;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,1391,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Quest 'Nothing But The Truth' Finished - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Just Died - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 541600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 3"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,3,0,10973,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Morph To Model 10973"),
(@ENTRY,9,5,0,0,0,100,0,100,100,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Start Random Movement"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Kill Self");

DELETE FROM `creature_text` WHERE `entry`=5416;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(5416, 0, 0, '%s takes a big swig of ale.', 16, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019),
(5416, 1, 0, 'That was refreshing. Now there\'s information that needs to be told...', 12, 0, 100, 1, 0, 0, 'Infiltrator Marksen',18019),
(5416, 2, 0, 'I believe the Forsaken are misleading the allies of the Horde.... wait... I feel so... dizzy...', 12, 0, 100, 1, 0, 0, 'Infiltrator Marksen',18019),
(5416, 3, 0, '%s writhes in pain.', 16, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019),
(5416, 4, 0, 'AAAAAAAAAAAAAAAAARGH!', 12, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019);
--
DELETE FROM `gossip_menu` WHERE `entry`=40060;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(40060, 2494),
(40060, 2493);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=40060 AND `SourceEntry` IN (2494, 2493);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(14, 40060, 2494, 0, 0, 8, 0, 4023, 0, 0, 1, 0, 0, 'Show gossip text if player do not has quest 4023 completed'),
(14, 40060, 2493, 0, 1, 8, 0, 4022, 0, 0, 1, 0, 0, 'Show gossip text if player do not has quest 4022 completed');
--
SET @newestguid := 45208;
DELETE FROM `creature` WHERE `guid`=@newestguid AND `id`=25654;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@newestguid, 25654, 571, 1, 1, 0, 0, 4207.15, 4057.02, 91.6273, 1.38362, 300, 0, 0, 42, 0, 0, 0, 0, 0);
--
SET @CGUID := 45212;
DELETE FROM `creature` WHERE `guid` IN (@CGUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 30082, 571, 1, 4, 7271.656, -878.8148, 926.0092, 5.532694, 600, 0, 0);

DELETE FROM `spell_area` WHERE `spell`=55783 AND `area`=4432;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(55783, 4432, 12879, 12973, 0, 0, 2, 1, 66, 1);
--
SET @CGUID := 45761;

DELETE FROM `creature` WHERE `id`=26265;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID, 26265, 571, 0, 0, 1, 1, 0, 0, 4031.15, 7326.39, 635.972, 4.26247, 300, 0, 0, 1, 0, 0, 0, 0, 0,0);

UPDATE `creature_template` SET  `ScriptName`='', `npcflag`=`npcflag`|1 WHERE `entry`=26206;
-- Keristrasza SAI
SET @ENTRY := 26206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9262,0,0,0,11,46772,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Cast 'Teleport'"),
(@ENTRY,0,1,0,61,0,100,0,9262,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,3,62,0,100,0,9262,1,0,0,11,46824,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Cast 'Teleport'"),
(@ENTRY,0,3,0,61,0,100,0,9262,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9262 AND `SourceEntry` IN (0, 1);
INSERT INTO `conditions` VALUES
(15, 9262, 0, 0, 0, 9, 0, 11957, 0, 0, 0, 0, 0, '', 'Only show gossip if player has quest 11957'),
(15, 9262, 1, 0, 0, 2, 0, 35709, 1, 0, 0, 0, 0, '', 'Only show gossip if player has item 35709');

-- Saragosa's End Invisman SAI
SET @ENTRY := 26265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,46793,0,0,0,12,26231,5,0,0,0,0,8,0,0,0,4050.19,7329.25,635.97,3.34,"Saragosa's End Invisman - On Spellhit 'Activate Power Focus' - Summon Creature 'Saragosa'"),
(@ENTRY,0,1,0,61,0,100,0,46793,0,0,0,11,46789,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa's End Invisman - On Spellhit 'Activate Power Focus' - Cast 'Blue Power Focus'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=26265;
INSERT INTO `conditions` VALUES
(22, 1, 26265, 0, 0, 29, 0, 26231, 40, 0, 1, 0, 0, '', 'Only summon Saragosa if there is not already one in range'),
(22, 1, 26265, 0, 0, 29, 0, 26232, 40, 0, 1, 0, 0, '', 'Only summon Saragosa if there is not already one in range');

-- Activate Power Focus (46793)
DELETE FROM `event_scripts` WHERE `id`=17452;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46793;
INSERT INTO `conditions` VALUES
(13, 1, 46793, 0, 0, 31, 0, 3, 26265, 0, 0, 0, 0, '', 'Target needs to be Saragosa''s End Invisman');

UPDATE `creature_template` SET  `ScriptName`='', `unit_flags`=`unit_flags`|768, `flags_extra`=`flags_extra`|2 WHERE `entry`=26231;
-- Saragosa SAI
SET @ENTRY := 26231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,0,0,28,46789,0,0,0,0,0,19,26265,40,0,0,0,0,0,"Saragosa - Out of Combat - Remove Aura 'Blue Power Focus' (No Repeat)"),
(@ENTRY,0,1,2,1,0,100,1,12000,12000,0,0,12,26232,1,120000,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Out of Combat - Summon Creature 'Saragosa' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Out of Combat - Despawn Instant (No Repeat)");

UPDATE `creature_template` SET  `ScriptName`='', `flags_extra`=`flags_extra`|2 WHERE `entry`=26232;
-- Saragosa SAI
SET @ENTRY := 26232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,40,3400,6200,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 'Frostfire Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8500,17500,20100,40100,11,15063,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 'Frost Nova'");
--
SET @CGUID := 56502; -- needs 3
DELETE FROM `creature` WHERE `guid` IN (@CGUID+0, @CGUID+1, @CGUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 26620, 600, 3, 1, -522.7039, -605.9083, 1.299988, 2.6529, 7200, 0, 0), -- 26620 (Area: 4196) (Auras: 47503 - 47503)
(@CGUID+1, 26620, 600, 3, 1, -518.0062, -599.1102, 1.10835, 3.054326, 7200, 0, 0), -- 26620 (Area: 4196) (Auras: 47503 - 47503)
(@CGUID+2, 26626, 600, 3, 1, -511.0887, -602.5585, 2.56744, 3.193953, 7200, 0, 0); -- 26626 (Area: 4196)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0, 0, 0, '47503'),
(@CGUID+1, 0, 0, 0, 0, 0, '47503');

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=26626 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Scourge Reanimator SAI
SET @GUID := -@CGUID+2;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,2,25,0,100,1,0,0,0,0,80,2662600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Reset - Run Script (No Repeat)"),
(@GUID,0,1,0,40,0,100,0,1,2662600,0,0,80,2662601,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Waypoint 1 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2662600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,53,1,2662600,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 2662601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Set Data 1 1"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID+1,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,11,48597,0,0,0,0,0,10,@CGUID+1,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-536.830505,-578.793091,1.91333,1.774444,"Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,11,48597,0,0,0,0,0,10,@CGUID,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,11,47506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Teleport'"),
(@ENTRY,9,8,0,0,0,100,0,1500,1500,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=2662600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2662600, 1, -533.262695, -591.052856, 2.484161, 'Scourge Reanimator');

-- Drakkari Guardian SAI
SET @GUID := -@CGUID; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Drakkari Guardian SAI   
SET @GUID := -@CGUID+1; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-536.830505,-578.793091,1.913330,1.774444,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Risen Drakkari Warrior SAI
SET @ENTRY := 26635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,9500,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Ghost Strike' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,7250,10000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Crush Armor' (Dungeon)"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Just Summoned - Start Random Movement");

DELETE FROM `creature_text` WHERE `entry`=26626;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26626, 0, 0, 'Don''t be so quick to escape! I have a parting gift....', 14, 0, 100, 0, 0, 0, 26474, 0, 'Scourge Reanimator'),
(26626, 1, 0, 'Rise my warriors and fight for your new liege!', 14, 0, 100, 0, 0, 0, 26464, 0, 'Scourge Reanimator'),
(26626, 2, 0, 'Please enjoy their company, the Lich King sends his regards!', 14, 0, 100, 0, 0, 0, 26473, 0, 'Scourge Reanimator');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=48597;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48597, 0, 0, 31, 0, 3, 26620, 0, 0, 0, 0, '', 'Raise Dead - only targets Drakkari Guardian');

DELETE FROM `creature` WHERE `guid` IN (127436, 127437);
-- 
DELETE FROM `creature_addon` WHERE `guid` IN (127436, 127437);
DELETE FROM `linked_respawn` WHERE `guid` IN (127436, 127437);
DELETE FROM `spell_script_names` WHERE  `spell_id`=8283 AND `ScriptName`='spell_snufflenose_command';
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=26206;
-- 
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=2 AND `link`=0;
--
DELETE FROM `spell_target_position` WHERE `id` in (50859);
--
DELETE FROM `gameobject_template` WHERE `entry` IN (193977,193978);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(193977, 22, 8532, 'Bottle of Peaked Dalaran Red', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 61064, 5, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', -18019),
(193978, 22, 8531, 'Cask of Peaked Dalaran Red', '', '', '', 0, 0, 0.8, 0, 0, 0, 0, 0, 0, 61064, 25, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', -18019);
-- 
SET @CGUID := 56502; 

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=11789;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=-56500 AND `source_type`=0 AND `id`=0 AND `link`=2;

-- Scourge Reanimator SAI
SET @GUID := -(@CGUID+2);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,1,0,0,0,0,80,2662600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Reset - Run Script (No Repeat)"),
(@GUID,0,1,0,40,0,100,0,1,2662600,0,0,80,2662601,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Waypoint 1 Reached - Run Script");

-- Drakkari Guardian SAI
SET @GUID := -(@CGUID); 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Drakkari Guardian SAI   
SET @GUID := -(@CGUID+1);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-536.830505,-578.793091,1.913330,1.774444,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");
-- 
-- Tome of Mel'Thandris SAI
SET @ENTRY := 19027;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,12,3946,2,40000,0,0,0,8,0,0,0,3169.15,-1211.71,216.95,4.59,"Tome of Mel'Thandris - On Gameobject State Changed - Summon Creature 'Velinde Starsong'");

UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=11789;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-56500;
-- 
-- King Mrgl-Mrgl SAI
SET @ENTRY := 25197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,19,0,100,0,11571,0,0,0,11,45328,0,0,0,0,0,7,0,0,0,0,0,0,0,"King Mrgl-Mrgl - On Quest 'Learning to Communicate' Taken - Cast 'Water Breathing'");

DELETE FROM `creature_text` WHERE `entry` IN(18927,19171,19175,19177,19173,19172,19176,19148,19178,19169,20102) AND `groupid`=0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19178, 0, 0, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 0, 1, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 0, 2, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 0, 3, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 396, 0, 0, 24333, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 0, 4, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 0, 5, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 6, 0, 0, 24332, 'Forsaken Commoner to Forsaken Commoner'),
(19169, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 2, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 3, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 4, 'The festival of the moon was ever more important to the kaldorei. The great festival of the druids is surely in full swing.', 12, 1, 100, 0, 0, 0, 16171, 'Blood Elf Commoner to Blood Elf Commoner'),
(19176, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Tauren Commoner to Tauren Commoner'),
(19176, 0, 1, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Tauren Commoner to Tauren Commoner'),
(19176, 0, 2, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Tauren Commoner to Tauren Commoner'),
(19176, 0, 3, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Tauren Commoner to Tauren Commoner'),
(19175, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Orc Commoner to Orc Commoner'),
(19175, 0, 1, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Orc Commoner to Orc Commoner'),
(19175, 0, 2, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Orc Commoner to Orc Commoner'),
(19175, 0, 3, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 274, 0, 0, 24334, 'Orc Commoner to Orc Commoner'),
(19175, 0, 4, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 274, 0, 0, 24335, 'Orc Commoner to Orc Commoner'),
(19177, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Troll Commoner to Troll Commoner'),
(19177, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Troll Commoner to Troll Commoner'),
(19177, 0, 2, 'We should go to Moonglade to see the druids'' great festival of the moon.', 12, 1, 100, 0, 0, 0, 0, 'Troll Commoner to Troll Commoner'),
(19177, 0, 3, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Troll Commoner to Troll Commoner'),
(19172, 0, 0, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 0, 0, 0, 24351, 'Gnome Commoner to Gnome Commoner'),
(19172, 0, 1, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 0, 0, 0, 24350, 'Gnome Commoner to Gnome Commoner'),
(19172, 0, 2, 'Lunar Festival is the best time of year for fireworks!', 12, 7, 100, 0, 0, 0, 0, 'Gnome Commoner to Gnome Commoner'),
(19172, 0, 3, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 0, 0, 0, 24352, 'Gnome Commoner to Gnome Commoner'),
(19171, 0, 0, 'It is no surprise that the people of this land hold a great festival of the moon. I should very much like to go to Moonglade to attend it.', 12, 7, 100, 6, 0, 0, 17428, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 274, 0, 0, 24351, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 2, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 0, 0, 0, 24351, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 3, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 0, 0, 0, 24352, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 4, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 273, 0, 0, 24351, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 5, 'It is no surprise that the people of this land hold a great festival of the moon. I should very much like to go to Moonglade to attend it.', 12, 7, 100, 273, 0, 0, 17428, 'Draenei Commoner to Draenei Commoner'),
(19171, 0, 6, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 0, 0, 0, 24350, 'Draenei Commoner to Draenei Commoner'),
(19173, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 0, 0, 0, 24350, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 0, 0, 0, 24351, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 0, 2, 'The Lunar Festival holds special meaning for the night elves. We seek out the wisdom of our elders across the world.', 12, 7, 100, 396, 0, 0, 16156, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 0, 3, 'The Lunar Festival holds special meaning for the night elves. We seek out the wisdom of our elders across the world.', 12, 7, 100, 0, 0, 0, 16156, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 0, 4, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 7, 100, 0, 0, 0, 24349, 'Night Elf Commoner to Night Elf Commoner'),
(18927, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 7, 100, 0, 0, 0, 24349, 'Human Commoner to Human Commoner'),
(18927, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 0, 0, 0, 24351, 'Human Commoner to Human Commoner'),
(18927, 0, 2, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 0, 0, 0, 24352, 'Human Commoner to Human Commoner'),
(18927, 0, 3, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 7, 100, 274, 0, 0, 24349, 'Human Commoner to Human Commoner'),
(18927, 0, 4, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 274, 0, 0, 24352, 'Human Commoner to Human Commoner'),
(18927, 0, 5, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 0, 0, 0, 24350, 'Human Commoner to Human Commoner'),
(19148, 0, 0, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 396, 0, 0, 24352, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 1, 'The Lunar Festival is a special time for us. We seek out our ancient elders, the Earthen, and pay homage to them.', 12, 7, 100, 396, 0, 0, 16153, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 2, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 7, 100, 0, 0, 0, 0, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 3, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 7, 100, 0, 0, 0, 24349, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 4, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 7, 100, 0, 0, 0, 24352, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 5, 'The Lunar Festival is a special time for us. We seek out our ancient elders, the Earthen, and pay homage to them.', 12, 7, 100, 0, 0, 0, 16153, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 0, 6, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 0, 0, 0, 24350, 'Dwarf Commoner to Dwarf Commoner'),
(20102, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 0, 100, 0, 0, 0, 16466, 'Goblin Commoner to Goblin Commoner'),
(20102, 0, 1, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 0, 100, 0, 0, 0, 16465, 'Goblin Commoner to Goblin Commoner'),
(20102, 0, 2, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 0, 100, 0, 0, 0, 16467, 'Goblin Commoner to Goblin Commoner'),
(20102, 0, 3, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 0, 100, 0, 0, 0, 16468, 'Goblin Commoner to Goblin Commoner');


DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18927,19171,19175,19177,19173,19172,19176,19148,19169,19178,20102) AND `source_type`=0 AND `id`IN(0,10);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18927,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19171,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dreani Commoner - OOC - Say'),
(19175,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19177,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Troll Commoner - OOC - Say'),
(19173,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Night Elf Commoner - OOC - Say'),
(19172,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnome Commoner - OOC - Say'),
(19176,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tauren Commoner - OOC - Say'),
(19148,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dwarf Commoner - OOC - Say'),
(20102,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(19178,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Commoner - OOC - Say'),
(19169,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),

(18927,0,10,0,64,0,100,0,0,0,0,0,98,7898, 9662,0,0,0,0,7,0,0,0,0,0,0,0,'Human Commoner - On Gossip Hello - Send Gossip Menu'),
(19148,0,10,0,64,0,100,0,0,0,0,0,98,7923, 9688,0,0,0,0,7,0,0,0,0,0,0,0,'Dwarf Commoner - On Gossip Hello - Send Gossip Menu'),
(19169,0,10,0,64,0,100,0,0,0,0,0,98,7921, 9700,0,0,0,0,7,0,0,0,0,0,0,0,'Blood Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19171,0,10,0,64,0,100,0,0,0,0,0,98,7922, 9696,0,0,0,0,7,0,0,0,0,0,0,0,'Draeni Commoner - On Gossip Hello - Send Gossip Menu'),
(19172,0,10,0,64,0,100,0,0,0,0,0,98,7931, 1915,0,0,0,0,7,0,0,0,0,0,0,0,'Gnome Commoner - On Gossip Hello - Send Gossip Menu'),
(19173,0,10,0,64,0,100,0,0,0,0,0,98,7924, 9692,0,0,0,0,7,0,0,0,0,0,0,0,'Night Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19175,0,10,0,64,0,100,0,0,0,0,0,98,7925, 9704,0,0,0,0,7,0,0,0,0,0,0,0,'Orc Commoner - On Gossip Hello - Send Gossip Menu'),
(19176,0,10,0,64,0,100,0,0,0,0,0,98,7926, 9708,0,0,0,0,7,0,0,0,0,0,0,0,'Tauren Commoner - On Gossip Hello - Send Gossip Menu'),
(19177,0,10,0,64,0,100,0,0,0,0,0,98,7935, 9716,0,0,0,0,7,0,0,0,0,0,0,0,'Troll Commoner - On Gossip Hello - Send Gossip Menu'),
(19178,0,10,0,64,0,100,0,0,0,0,0,98,7927, 9712,0,0,0,0,7,0,0,0,0,0,0,0,'Forsaken Commoner - On Gossip Hello - Send Gossip Menu'),
(20102,0,10,0,64,0,100,0,0,0,0,0,98,8064, 9964,0,0,0,0,7,0,0,0,0,0,0,0,'Goblin Commoner - On Gossip Hello - Send Gossip Menu');



DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(18927,19171,19175,19177,19173,19172,19176,19148,19169,19178,20102) AND `SourceGroup` IN(1,11);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 18927, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19148, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19169, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19171, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19172, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19173, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19175, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19176, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19177, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19178, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 20102, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),

(22, 11, 18927, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19148, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19169, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19171, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19172, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19173, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19175, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19176, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19177, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 19178, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 11, 20102, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active');

DELETE FROM `gossip_menu` WHERE `entry` IN(7931,7926,7925,7924,7898,7923,7921,7927,7935,7922,8064);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7931, 1915), -- 19172
(7926, 9708), -- 19176
(7925, 9704), -- 19175*
(7924, 9692), -- 19173*
(7898, 9662), -- 18927*
(7923, 9688), -- 19148*
(7921, 9700), -- 19169*
(7927, 9712), -- 19178*
(7935, 9716), -- 19177*
(7922, 9696), -- 19171*
(8064, 9964); -- 20102*

DELETE FROM `npc_text` WHERE `ID` IN(9715,9708);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `VerifiedBuild`) VALUES 
(9715, 'Go to Ironforge''s Mystic Ward and speak with the night elf druids there. They can transport you to Moonglade to join in the Lunar Festival celebration.', 'Go to Ironforge''s Mystic Ward and speak with the night elf druids there. They can transport you to Moonglade to join in the Lunar Festival celebration.', 16214, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9708, 'The largest celebration of the Lunar Festival takes place in Moonglade. Druids will transport you there from the Elder Rise of Thunder Bluff.', 'The largest celebration of the Lunar Festival takes place in Moonglade. Druids will transport you there from the Elder Rise of Thunder Bluff.', 16201, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2248200,2203800) AND `source_type`=9 AND `id` IN (2, 3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2248200, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Set Agressive'),
(2248200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Remove UnitFlag'),
(2248200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Root'),
(2203800, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Set Agressive'),
(2203800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Remove UnitFlag'),
(2203800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Root');

DELETE FROM `smart_scripts` WHERE `entryorguid`=16968 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16968,0,0,1,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - On Aggro - Remove UNIT_FLAG_NOT_SELECTABLE'),
(16968,0,1,2,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Remove Tunnel Bore Passive'),
(16968,0,2,3,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Cast Stand'),
(16968,0,3,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Root'),
(16968,0,4,5,25,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Spawn/Respawn/OOC - Cast Tunnel Bore Passive'),
(16968,0,5,6,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous Set UNIT_FLAG_NOT_SELECTABLE'),
(16968,0,6,0,61,0,100,0,0,0,0,0,11,37751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Cast Submerge'),
(16968,0,7,0,0,0,100,0,1000,1000,2100,4500,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tunneler - In Combat - Cast Poison'),
(16968,0,8,0,0,0,100,0,10400,10400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tunneler - In Combat - Cast Bore'),
(16968,0,9,0,2,0,100,0,0,30,8000,8000,11,32714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tunneler - Between 0-30% Health - Cast 8599");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21849;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21849 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21849,0,0,1,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - On Aggro - Remove UNIT_FLAG_NOT_SELECTABLE'),
(21849,0,1,2,61,0,100,0,0,0,0,0,28,38885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Remove Tunnel Bore Passive'),
(21849,0,2,3,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Cast Stand'),
(21849,0,3,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Root'),
(21849,0,4,5,25,0,100,0,0,0,0,0,11,38885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Spawn/Respawn/OOC - Cast Tunnel Bore Passive'),
(21849,0,5,6,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous Set UNIT_FLAG_NOT_SELECTABLE'),
(21849,0,6,0,61,0,100,0,0,0,0,0,11,37751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Cast Submerge'),
(21849,0,7,0,0,0,100,0,1000,1000,2100,4500,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bone Crawler - In Combat - Cast Poison'),
(21849,0,8,0,0,0,100,0,10400,10400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bone Crawler - In Combat - Cast Bore');
-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=-56501;
--
SET @CGUID := 49137;
DELETE FROM `creature` WHERE `guid` IN (@CGUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 30142, 571, 1, 1, 8392.7, -1970.14, 1461.84, 0.0948219, 600, 0, 0);

SET @OGUID := 5501;
DELETE FROM `gameobject` WHERE `guid`= @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `rotation2`, `rotation3`, `animprogress`, `state`) VALUES
(@OGUID, 192243, 571, 1, 1, 8531.9, -1971.44, 1467.57, -0.837757, 300, -0.406736, 0.913546, 100, 1);

UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=29730;
--
SET @CGUID :=    49141;

SET @Loken  :=    30396;
SET @Thorim :=    30399;
SET @Veranus:=    30420;
SET @Servant:=    30429;

UPDATE `creature_template` SET `gossip_menu_id`=9928, `minlevel`=82, `maxlevel`=82, `npcflag`=1, `speed_walk`=4.8, `speed_run`=3.142857, `rank`=3, `unit_flags`=320, `unit_flags2`=2099200, `AIName`='SmartAI', `type_flags`=0 WHERE  `entry`=@Thorim; -- thorim
UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.6, `speed_run`=1.857143, `unit_flags`=320, `unit_flags2`=2099200, `AIName`='SmartAI' WHERE  `entry`=@Loken; -- loken
UPDATE `creature_template` SET `speed_walk`=3.2, `speed_run`=1.428571, `unit_flags`=33088, `unit_flags2`=2099200, `AIName`='SmartAI', `HoverHeight`=2.1, `InhabitType`=4 WHERE  `entry`=@Veranus;
UPDATE `creature_template` SET `faction`=2102, `unit_flags`=320,`AIName`='SmartAI' WHERE  `entry`=@Servant;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@Thorim*100,@Loken*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(@Thorim,@Loken,@Veranus,@Servant) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Loken,0,0,1,38,0,100,0,1,1,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - On Data Set 1 1 - Set Bytes 1"),
(@Loken,0,1,0,61,0,100,0,0,0,0,0,80,@Loken*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - On Data Set 1 1 - Run Script"),
(@Veranus,0,0,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,8609.171875, -636.665955, 967.317383, 2.124008,"Veranus - On Data Set 1 1 - move to pos"),
(@Veranus,0,1,2,38,0,100,0,2,2,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veranus - On Data Set 2 2 - Cast Ethereal Teleport"),
(@Veranus,0,2,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veranus - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Veranus,0,3,0,1,0,100,0,160000,160000,160000,160000,70,0,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Veranus - Ooc - respawn target"),
(@Servant,0,0,1,38,0,100,0,2,2,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Cast Ethereal Teleport"),
(@Servant,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Servant,0,2,3,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Servant,0,3,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Thorim,0,0,1,62,0,100,0,9928,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Store Targetlist"),
(@Thorim,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Close Gossip"), 
(@Thorim,0,2,3,61,0,100,0,0,0,0,0,28,54503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - remove aura"),
(@Thorim,0,3,0,61,0,100,0,0,0,0,0,80,@Thorim*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Run Script"),
(@Thorim,0,4,0,40,0,100,0,2,@Thorim,0,0,1,1,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - On Reached WP2 - Say Line 2"),
(@Thorim,0,5,0,40,0,100,0,3,@Thorim,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Reached WP3 - Set Home Position"),
(@Thorim,0,6,0,8,0,100,0,56696,0,0,0,100,1,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - On Spellhit (Loken - Defeat Thorim) - Send Target List to Loken"),
(@Thorim,0,7,0,9,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Spawn - Set Invincibility hp"),
(@Thorim,0,8,0,25,0,100,0,1,1,0,0,75,54503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Reset - Add aura"),
(@Loken*100,9,0,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Set Run On"),
(@Loken*100,9,1,0,0,0,100,0,0,0,0,0,17,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - set stand none"),
(@Loken*100,9,2,0,0,0,100,0,2000,2000,0,0,11,56677,0,0,0,0,0,19,@Thorim,30,0,0,0,0,0,"Loken - Script - Cast Loken's Knockback"),
(@Loken*100,9,3,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,8591.518555, -610.456604, 925.558228, 5.241327,"Loken - Script - Say Line 1"),
(@Loken*100,9,5,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 1"),
(@Loken*100,9,6,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Play emote 25"),
(@Loken*100,9,7,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,8577.214844, -596.050659, 925.558289, 5.372476,"Loken - Script - Say Line 1"),
(@Loken*100,9,8,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 2"),
(@Loken*100,9,9,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 3"),
(@Loken*100,9,10,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 4"),
(@Loken*100,9,11,0,0,0,100,0,1000,1000,0,0,75,56696,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Cast Loken - Defeat Thorim"),
(@Loken*100,9,12,0,0,0,100,0,0,0,0,0,11,46846,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Cast Loken - Defeat Thorim"),
(@Loken*100,9,13,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,@CGUID+1,@Veranus,0,0,0,0,0,"Loken - Script - Set Data 1 1 to Veranus"), 
(@Loken*100,9,14,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 5"),
(@Loken*100,9,15,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 6"),
(@Loken*100,9,16,0,0,0,100,0,0,0,0,0,12,@Servant,1,60000,0,0,0,8,0,0,0,8622.837,-605.7887,926.2864,4.433136,"Loken - Script - Spawn Runeforged Servant <Servant of Loken>"),
(@Loken*100,9,17,0,0,0,100,0,0,0,0,0,12,@Servant,1,60000,0,0,0,8,0,0,0,8586.867,-564.764,925.6412,5.166174,"Loken - Script - Spawn Runeforged Servant <Servant of Loken>"),
(@Loken*100,9,18,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,21,50,0,0,0,0,0,0,"Loken - Script - Say Line 7"),
(@Loken*100,9,19,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,21,50,0,0,0,0,0,0,"Loken - Script - Say Line 8"),
(@Loken*100,9,20,0,0,0,100,0,0,0,0,0,28,46846,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Say Line 1"),
(@Loken*100,9,21,0,0,0,100,0,5000,5000,0,0,11,56941,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Cast Witness the Reckoning"),
(@Loken*100,9,22,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,@CGUID+1,@Veranus,0,0,0,0,0,"Loken - Script - Set Data 2 2 to Veranus"),
(@Loken*100,9,23,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,30429,0,200,0,0,0,0,"Loken - Script - Set Data 2 2 to Runeforged Servant <Servant of Loken>"), 
(@Thorim*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set NPC Flags"),
(@Thorim*100,9,1,0,0,0,100,0,0,0,0,0,12,@Loken,1,180000,0,0,0,8,0,0,0,8564.411,-580.366,925.6412,5.5676,"Thorim - Script - Spawn Loken"),
(@Thorim*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - Script - Say Line 1"),
(@Thorim*100,9,3,0,0,0,100,0,3000,3000,0,0,53,0,@Thorim,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Start WP"),
(@Thorim*100,9,4,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 3"),
(@Thorim*100,9,5,0,0,0,100,0,2000,2000,0,0,5,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Play Emote 333"),
(@Thorim*100,9,6,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Set Data 1 1 to Loken"),
(@Thorim*100,9,7,0,0,0,100,0,6000,6000,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set Run On"),
(@Thorim*100,9,8,0,0,0,100,0,0,0,0,0,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Cast Move to Loken"),
(@Thorim*100,9,9,0,0,0,100,0,6000,6000,0,0,11,56688,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Knockback"),
(@Thorim*100,9,10,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 4"),
(@Thorim*100,9,11,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 5"),
(@Thorim*100,9,12,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 6"),
(@Thorim*100,9,13,0,0,0,100,0,1000,1000,0,0,11,56694,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Lightning Fury"),
(@Thorim*100,9,14,0,0,0,100,0,3000,3000,0,0,11,56695,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Hammer");

DELETE FROM `spell_area` WHERE `spell`=54504 AND `area` IN(4543,4445);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(54504, 4543, 13047, 13047, 0, 0, 2, 1, 8, 11),
(54504, 4445, 13047, 13047, 0, 0, 2, 1, 8, 11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9928;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9928, 0, 0, 0, 9, 0, 13047, 0, 0, 0, 0, 0, '', 'Gossip option requires the reckoning taken');

DELETE from `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56677;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56677, 0, 31, 3, @Thorim, 0, 0, '', 'Loken''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56688;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56688, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56694;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 56694, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56695;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56695, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s hammer');

DELETE FROM `creature_text` WHERE `entry` IN(@Thorim,@Loken);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(@Thorim, 0, 0, 'It is time I put an end to my brother''s madness.', 12, 0, 100, 0, 0, 0, 'Thorim', 31078),
(@Thorim, 1, 0, 'Loken!!', 14, 0, 100, 15, 0, 0, 'Thorim', 31079),
(@Thorim, 2, 0, 'Stand up and fight me, you worthless traitor!  ', 14, 0, 100, 53, 0, 0, 'Thorim', 31080),
(@Thorim, 3, 0, 'Do not dare...', 12, 0, 100, 0, 0, 0, 'Thorim', 31083),
(@Thorim, 4, 0, 'Speak...', 12, 0, 100, 0, 0, 0, 'Thorim', 31116),
(@Thorim, 5, 0, 'Her name!!', 12, 0, 100, 0, 0, 0, 'Thorim', 31117),
(@Loken, 0, 0, 'You seem eager to join your beloved Sif, brother.', 12, 0, 100, 0, 0, 0, 'Loken', 31082),
(@Loken, 1, 0, 'ENOUGH!', 14, 0, 100, 15, 0, 0, 'Loken', 31126),
(@Loken, 2, 0, 'Looks like you can still best me in a fair fight, little brother.', 12, 0, 100, 1, 0, 0, 'Loken', 31110),
(@Loken, 3, 0, 'Unfortunately for you.... this fight is anything but fair!', 12, 0, 100, 1, 0, 0, 'Loken', 31111),
(@Loken, 4, 0, 'Thanks to your little friend, you''ve left the Temple of Storms, where you were at your strongest.  Instead we fight closer to my master''s power.', 12, 0, 100, 0, 0, 0, 'Loken', 31112),
(@Loken, 5, 0, 'Minions!  Take my brother and his drake to their new dwellings.  Make sure the beast makes it alive.  I have special plans for the broodmother.', 12, 0, 100, 0, 0, 0, 'Loken', 31128),
(@Loken, 6, 0, 'As for your life, mortal.  I will be generous.  After all... why would I destroy my most useful servant?  I waited for you for weeks inside that Hyldnir mine.', 12, 0, 100, 0, 0, 0, 'Loken', 31127),
(@Loken, 7, 0, 'The shape wasn''t mine, of course.  And had you not been so reckless, you would''ve seen past my illusion.  But you came through for me, and for that... I must thank you!', 12, 0, 100, 0, 0, 0, 'Loken', 31133);

DELETE FROM `creature_template_addon` WHERE `entry` IN(@Thorim,@Loken,@Veranus);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@Thorim, 0, 0x10000, 0x1, '54503'), -- 30399 - 54503
(@Loken, 0, 0x1, 0x1, ''), -- 30396
(@Veranus, 0, 0x3010000, 0x1, '54503'); -- 30420 - 54503

DELETE FROM `creature` WHERE `id` IN(@Thorim,@Veranus);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @Thorim, 571, 1, 1,  8703.806, -714.0443, 934.9764, 2.321288, 120, 0, 0), -- 30399 (Area: 67)
(@CGUID+1, @Veranus, 571, 1, 1,  8711.395, -754.7941, 955.1224, 2.338741, 120, 0, 0); -- 30420 (Area: 67)

DELETE FROM `gossip_menu` WHERE `entry`=9928;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(9928, 13800); -- 30399

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9928;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9928, 0, 0, 'I''m with you, Thorim.', 0, 1, 1, 0, 0, 0, 0, '', 31225);

DELETE FROM `waypoints` WHERE `entry` IN(@Thorim);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Thorim, 1,8695.301, -703.0229, 933.7817, 'Thorim'),
(@Thorim, 2,8665.801, -675.7729, 927.5317, 'Thorim'),
(@Thorim, 3,8573.930664, -591.286133, 925.558167 , 'Thorim');

UPDATE creature_template SET InhabitType=4 WHERE entry IN (29747, 29790);
UPDATE `gossip_menu` SET `text_id`=9715 WHERE  `entry`=7931 AND `text_id`=1915;
-- Mug'gok SAI
SET @ENTRY := 18475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,18475,1,0,0,2,1,0,0,0,0,0,0,0,"Mug'gok - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,18475,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,1,18475,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY*100+00,9,0,0,0,0,100,0,2000,2000,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 0"),
(@ENTRY*100+00,9,1,0,0,0,100,0,2000,2000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 1"),
(@ENTRY*100+00,9,3,0,0,0,100,0,2000,2000,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 2");

-- Add text
DELETE FROM `creature_text` WHERE `entry`=18475;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(18475, 0, 0, 'Come out, little birdies! Mug''gok want to play!', 14, 0, 100, 0, 0, 0, 'Muggok', 15463),
(18475, 1, 0, 'No hurt Mug''gok''s feelings, bird-men!', 14, 0, 100, 0, 0, 0, 'Muggok', 15464),
(18475, 2, 0, 'Fine! Birdies be dat way! Mug''gok find new friends!', 14, 0, 100, 14, 0, 0, 'Muggok', 15465);

-- Add waypoints
DELETE FROM `waypoints` WHERE `entry`=18475;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(18475, 1, -3586.119,5789.734,-4.249763, 'Muggok'),
(18475, 2, -3607.362,5802.457,-4.015522, 'Muggok'),
(18475, 3, -3611.601,5813.162,-4.286913, 'Muggok'),
(18475, 4, -3620.696,5832.479,0.1701524, 'Muggok'),
(18475, 5, -3632.274,5845.131,-0.2069848, 'Muggok'),
(18475, 6, -3644.935,5868.452,-4.990351, 'Muggok'),
(18475, 7, -3637.306,5910.221,-21.84441, 'Muggok'),
(18475, 8, -3641.046,5941.752,-30.85709, 'Muggok'),
(18475, 9, -3638.008,5970.188,-22.30242, 'Muggok'),
(18475, 10, -3625.294,5984.689,-19.98056, 'Muggok'),
(18475, 11, -3593.81,5984.915,-30.74051, 'Muggok'),
(18475, 12, -3560.429,5994.253,-34.44781, 'Muggok'),
(18475, 13, -3533.398,6024.583,-24.52451, 'Muggok'),
(18475, 14, -3525.008,6048.768,-20.22229, 'Muggok'),
(18475, 15, -3509.135,6060.514,-15.46761, 'Muggok'),
(18475, 16, -3465.905,6061.523,-15.65, 'Muggok'),
(18475, 17, -3455.743,6054.097,-12.08964, 'Muggok'),
(18475, 18, -3452,6032.292,-14.2308, 'Muggok'),
(18475, 19, -3449.686,6012.386,-17.47238, 'Muggok'),
(18475, 20, -3443.185,5993.315,-23.15056, 'Muggok'),
(18475, 21, -3440.388,5986.851,-24.24662, 'Muggok'),
(18475, 22, -3435.465,5956.201,-24.91395, 'Muggok'),
(18475, 23, -3446.49,5924.918,-33.08622, 'Muggok'),
(18475, 24, -3466.203,5894.721,-28.9427, 'Muggok'),
(18475, 25, -3483.424,5870.367,-23.49757, 'Muggok'),
(18475, 26, -3495.208,5849.559,-15.93699, 'Muggok'),
(18475, 27, -3507.46,5820.458,-12.90878, 'Muggok'),
(18475, 28, -3519.906,5799.604,-7.427849, 'Muggok'),
(18475, 29, -3532.312,5789.58,-6.70218, 'Muggok'),
(18475, 30, -3553.792,5784.59,-4.330991, 'Muggok'),
(18475, 31, -3562.554,5785.313,-1.650567, 'Muggok');
--
SET @ENTRY := 178905;
SET @Scion:= 13696;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Scion);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Scion AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,0,0,0,0,0,12,13696,2,60000,0,0,0,1,0,0,0,0,0,0,0,"Vylestem Vine - On Gossip Hello - Summon Creature 'Noxxious Scion'"),
(@Scion,0,0,0,4,0,100,1,0,0,0,0,11,21883,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxxious Scion - On Aggro -Cast 21883"),
(@Scion,0,1,0,63,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Noxxious Scion - On Just created - Attack");
--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (31198, 31150);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31198, 31150) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(31150,0,0,0,0,0,100,0,2000,8000,12000,15000,11,60678,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Plagued Fiend - IC - Plague Bite"),
(31198,0,0,0,0,0,100,0,2000,2000,15000,20000,11,38971,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Coprous the Defiled - IC - Cast Acid Geyser"),
(31198,0,1,0,0,0,100,0,5000,5000,10000,10000,11,5164,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Coprous the Defiled - IC - Cast Knockdown");
-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (25760, 25622, 25615);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(25760, 0, 0, 0, 0, 45, NULL),
(25622, 0, 0, 0, 0, 173, NULL),
(25615, 0, 0, 0, 0, 0, '45797');

UPDATE `creature_addon` SET `emote`=36 WHERE  `guid`=102838;

UPDATE `creature` SET `spawndist`=9, `MovementType`=1 WHERE  `id` IN (26202, 25715, 25668, 25791, 25792);

UPDATE `creature` SET `spawndist`=9, `MovementType`=1 WHERE  `id` IN (26126);

UPDATE `creature` SET `spawndist`=13, `MovementType`=1 WHERE  `id` IN (25452, 25615);

UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=122669;

DELETE FROM `creature_formations` WHERE `leaderGUID`=111466;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(111466, 111466, 0, 0, 0, 0, 0),
(111466, 111467, 5, 10, 0, 0, 0);

-- Pathing for  Entry: 26790 'TDB FORMAT' 
SET @NPC := 111466;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3269.226,`position_y`=4429.583,`position_z`=25.58942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3269.226,4429.583,25.58942,0,0,0,0,100,0),
(@PATH,2,3267.759,4388,25.7008,0,0,0,0,100,0),
(@PATH,3,3267.792,4381.39,25.73712,0,0,0,0,100,0),
(@PATH,4,3278.066,4307.007,24.88556,0,0,0,0,100,0),
(@PATH,5,3279.909,4296.206,24.66411,0,0,0,0,100,0),
(@PATH,6,3295.526,4235.11,26.38262,0,0,0,0,100,0),
(@PATH,7,3300.244,4216.931,27.75196,0,0,0,0,100,0),
(@PATH,8,3318.573,4152.362,27.67955,0,0,0,0,100,0),
(@PATH,9,3325.382,4131.279,26.32579,0,0,0,0,100,0),
(@PATH,10,3332.996,4089.244,27.17685,0,0,0,0,100,0),
(@PATH,11,3343.786,4049.672,25.98749,0,0,0,0,100,0),
(@PATH,12,3363.78,4008.359,26.03116,0,0,0,0,100,0),
(@PATH,13,3366.464,4003.271,25.94505,0,0,0,0,100,0),
(@PATH,14,3425.143,4003.964,27.52853,0,0,0,0,100,0),
(@PATH,15,3476.093,4013.513,26.82531,0,0,0,0,100,0),
(@PATH,16,3515.465,4026.42,22.9796,0,0,0,0,100,0),
(@PATH,17,3530.343,4051.534,21.97854,0,0,0,0,100,0),
(@PATH,18,3552.293,4122.889,21.95212,0,0,0,0,100,0),
(@PATH,19,3590.191,4148.155,21.84193,0,0,0,0,100,0),
(@PATH,20,3620.669,4159.591,25.41138,0,0,0,0,100,0),
(@PATH,21,3659.4,4169.95,25.3229,0,0,0,0,100,0),
(@PATH,22,3700.533,4186.467,24.96351,0,0,0,0,100,0),
(@PATH,23,3743.046,4216.556,24.08723,0,0,0,0,100,0),
(@PATH,24,3771.806,4239.74,25.29598,0,0,0,0,100,0),
(@PATH,25,3820.626,4241.001,27.25442,0,0,0,0,100,0),
(@PATH,26,3848.42,4209.31,28.84864,0,0,0,0,100,0),
(@PATH,27,3840.634,4170.563,28.2758,0,0,0,0,100,0),
(@PATH,28,3804.119,4155.879,27.68908,0,0,0,0,100,0),
(@PATH,29,3767.293,4171.405,26.47837,0,0,0,0,100,0),
(@PATH,30,3739.984,4183.705,24.70092,0,0,0,0,100,0),
(@PATH,31,3695.544,4177.419,25.40162,0,0,0,0,100,0),
(@PATH,32,3690.549,4175.297,25.46773,0,0,0,0,100,0),
(@PATH,33,3664.658,4165.97,25.39618,0,0,0,0,100,0),
(@PATH,34,3608.881,4156.498,24.01619,0,0,0,0,100,0),
(@PATH,35,3562.48,4159.697,23.3773,0,0,0,0,100,0),
(@PATH,36,3545.413,4159.953,22.43779,0,0,0,0,100,0),
(@PATH,37,3526.568,4167.223,15.17734,0,0,0,0,100,0),
(@PATH,38,3522.761,4171.347,12.94395,0,0,0,0,100,0),
(@PATH,39,3513.761,4183.413,12.85036,0,0,0,0,100,0),
(@PATH,40,3521.258,4190.762,12.85036,0,0,0,0,100,0),
(@PATH,41,3529.055,4194.656,12.85036,0,0,0,0,100,0),
(@PATH,42,3537.065,4186.435,12.85036,0,0,0,0,100,0),
(@PATH,43,3549.637,4182.573,12.84298,0,0,0,0,100,0),
(@PATH,44,3560.2,4184.638,12.84456,0,0,0,0,100,0),
(@PATH,45,3551.881,4191.742,12.85036,0,0,0,0,100,0),
(@PATH,46,3552.376,4284.875,12.60797,0,0,0,0,100,0),
(@PATH,47,3537.689,4185.746,12.85036,0,0,0,0,100,0),
(@PATH,48,3535.854,4184.324,12.85036,0,0,0,0,100,0),
(@PATH,49,3526.616,4197.904,12.85036,0,0,0,0,100,0),
(@PATH,50,3514.75,4185.95,12.85036,0,0,0,0,100,0),
(@PATH,51,3487.793,4170.192,17.39668,0,0,0,0,100,0),
(@PATH,52,3474.217,4172.794,17.44868,0,0,0,0,100,0),
(@PATH,53,3466.45,4161.327,17.44301,0,0,0,0,100,0),
(@PATH,54,3463.186,4144.002,17.44657,0,0,0,0,100,0),
(@PATH,55,3461.733,4133.489,15.50942,0,0,0,0,100,0),
(@PATH,56,3461.425,4131.252,15.57042,0,0,0,0,100,0),
(@PATH,57,3440.413,4107.955,16.253,0,0,0,0,100,0),
(@PATH,58,3439.38,4106.382,16.33916,0,0,0,0,100,0),
(@PATH,59,3384.195,4062.901,19.78522,0,0,0,0,100,0),
(@PATH,60,3350.907,4085.523,26.59955,0,0,0,0,100,0),
(@PATH,61,3336.268,4101.299,25.10432,0,0,0,0,100,0),
(@PATH,62,3313.968,4123.463,25.70841,0,0,0,0,100,0),
(@PATH,63,3298.833,4136.27,25.76038,0,0,0,0,100,0),
(@PATH,64,3284.301,4171.881,25.73615,0,0,0,0,100,0),
(@PATH,65,3260.152,4249.911,26.19264,0,0,0,0,100,0),
(@PATH,66,3265.231,4272.233,25.12194,0,0,0,0,100,0),
(@PATH,67,3267.608,4324.161,25.83903,0,0,0,0,100,0),
(@PATH,68,3266.102,4333.994,26.12407,0,0,0,0,100,0),
(@PATH,69,3269.841,4402.301,25.18758,0,0,0,0,100,0),
(@PATH,70,3287.93,4442.964,24.90842,0,0,0,0,100,0),
(@PATH,71,3330.486,4488.953,25.63785,0,0,0,0,100,0),
(@PATH,72,3346.958,4513.736,25.21837,0,0,0,0,100,0),
(@PATH,73,3370.701,4574.729,28.1356,0,0,0,0,100,0),
(@PATH,74,3329.835,4909.289,31.98566,0,0,0,0,100,0),
(@PATH,75,3260.729,4889.575,31.59256,0,0,0,0,100,0),
(@PATH,76,3254.577,4883.116,30.8572,0,0,0,0,100,0),
(@PATH,77,3244.599,4836.884,30.49381,0,0,0,0,100,0),
(@PATH,78,3274.862,4794.816,31.06407,0,0,0,0,100,0),
(@PATH,79,3312.659,4774.863,32.49248,0,0,0,0,100,0),
(@PATH,80,3349.351,4758.671,31.47926,0,0,0,0,100,0),
(@PATH,81,3287.93,4442.964,24.90842,0,0,0,0,100,0),
(@PATH,82,3330.486,4488.953,25.63785,0,0,0,0,100,0),
(@PATH,83,3346.958,4513.736,25.21837,0,0,0,0,100,0),
(@PATH,84,3370.701,4574.729,28.1356,0,0,0,0,100,0);
-- 0x1C39AC47601A298000000B00005AED7E .go 3269.226 4429.583 25.58942

-- Pathing for  Entry: 25793 'TDB FORMAT' 
SET @NPC := 57171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3561.628,`position_y`=5005.68,`position_z`=-1.416187 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3561.628,5005.68,-1.416187,0,0,0,0,100,0),
(@PATH,2,3561.647,5005.603,-1.154766,0,0,0,0,100,0),
(@PATH,3,3548.455,4987.43,-1.165261,0,0,0,0,100,0),
(@PATH,4,3548.445,4987.507,-1.393345,0,0,0,0,100,0),
(@PATH,5,3548.703,4987.758,-1.156939,0,0,0,0,100,0),
(@PATH,6,3561.752,5006.026,-1.164443,0,0,0,0,100,0),
(@PATH,7,3561.628,5005.68,-1.416187,0,0,0,0,100,0);
-- 0x1C39AC47601930400000A3000065B380 .go 3561.628 5005.68 -1.416187

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC :=  57156;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3653.617,`position_y`=4706.431,`position_z`=-12.93513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3653.617,4706.431,-12.93513,0,0,0,0,100,0),
(@PATH,2,3644.772,4705.505,-13.09717,0,0,0,0,100,0),
(@PATH,3,3650.718,4705.053,-12.68797,0,0,0,0,100,0),
(@PATH,4,3657.83,4709.773,-12.6719,0,0,0,0,100,0),
(@PATH,5,3662.773,4713.923,-12.66263,0,0,0,0,100,0),
(@PATH,6,3683.912,4744.512,-13.18753,0,0,0,0,100,0),
(@PATH,7,3684.609,4746.4,-13.26137,0,0,0,0,100,0),
(@PATH,8,3681.26,4750.936,-12.83029,0,0,0,0,100,0),
(@PATH,9,3677.817,4771.657,-12.96236,0,0,0,0,100,0),
(@PATH,10,3677.802,4771.346,-13.06311,0,0,0,0,100,0),
(@PATH,11,3678.06,4771.458,-12.99139,0,0,0,0,100,0),
(@PATH,12,3683.749,4747.838,-13.2233,0,0,0,0,100,0),
(@PATH,13,3683.588,4743.549,-12.92916,0,0,0,0,100,0),
(@PATH,14,3676.425,4727.065,-12.68113,0,0,0,0,100,0),
(@PATH,15,3653.484,4706.284,-12.93378,0,0,0,0,100,0),
(@PATH,16,3644.924,4705.583,-13.21565,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C00006399A7 .go 3653.617 4706.431 -12.93513

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57154;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3668.695,`position_y`=4852.459,`position_z`=-12.74998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3668.695,4852.459,-12.74998,0,0,0,0,100,0),
(@PATH,2,3664.671,4872.002,-12.99413,0,0,0,0,100,0),
(@PATH,3,3664.699,4871.859,-13.07822,0,0,0,0,100,0),
(@PATH,4,3665.02,4871.801,-13.02737,0,0,0,0,100,0),
(@PATH,5,3675.036,4847.65,-13.24574,0,0,0,0,100,0),
(@PATH,6,3689.288,4839.663,-12.73423,0,0,0,0,100,0),
(@PATH,7,3700.295,4827.3,-13.29157,0,0,0,0,100,0),
(@PATH,8,3702.61,4824.848,-13.29076,0,0,0,0,100,0),
(@PATH,9,3702.303,4824.782,-13.54672,0,0,0,0,100,0),
(@PATH,10,3696.016,4832.376,-12.71317,0,0,0,0,100,0),
(@PATH,11,3684.51,4841.927,-13.23423,0,0,0,0,100,0),
(@PATH,12,3671.438,4849.996,-12.73423,0,0,0,0,100,0),
(@PATH,13,3668.495,4852.239,-12.74998,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C00006398F7 .go 3668.695 4852.459 -12.74998

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 97940;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3580.309,`position_y`=4549.389,`position_z`=-11.17193 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3580.309,4549.389,-11.17193,0,0,0,0,100,0),
(@PATH,2,3578.376,4553.744,-12.42194,0,0,0,0,100,0),
(@PATH,3,3568.719,4586.03,-13.21303,0,0,0,0,100,0),
(@PATH,4,3580.922,4608.78,-13.29673,0,0,0,0,100,0),
(@PATH,5,3569.915,4581.717,-12.73434,0,0,0,0,100,0),
(@PATH,6,3580.182,4549.349,-11.17194,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C0000635FEA .go 3580.309 4549.389 -11.17193

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 97945;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3638.907,`position_y`=4590.849,`position_z`=-12.90129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3638.907,4590.849,-12.90129,0,0,0,0,100,0),
(@PATH,2,3639.077,4591.158,-12.65275,0,0,0,0,100,0),
(@PATH,3,3657.039,4597.404,-12.65622,0,0,0,0,100,0),
(@PATH,4,3674.552,4584.037,-12.69051,0,0,0,0,100,0),
(@PATH,5,3691.104,4575.537,-12.92792,0,0,0,0,100,0),
(@PATH,6,3700.628,4561.468,-12.65065,0,0,0,0,100,0),
(@PATH,7,3700.406,4561.409,-12.89539,0,0,0,0,100,0),
(@PATH,8,3700.436,4561.741,-12.6833,0,0,0,0,100,0),
(@PATH,9,3690.878,4575.947,-12.68227,0,0,0,0,100,0),
(@PATH,10,3674.272,4584.251,-12.66346,0,0,0,0,100,0),
(@PATH,11,3656.891,4597.556,-12.65173,0,0,0,0,100,0),
(@PATH,12,3638.816,4591.054,-12.67964,0,0,0,0,100,0),
(@PATH,13,3638.907,4590.849,-12.90129,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C000063960F .go 3638.907 4590.849 -12.90129

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57150;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3540.325,`position_y`=4553.921,`position_z`=-11.9877 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3540.325,4553.921,-11.9877,0,0,0,0,100,0),
(@PATH,2,3551.097,4546.824,-12.09515,0,0,0,0,100,0),
(@PATH,3,3556.957,4542.564,-12.71872,0,0,0,0,100,0),
(@PATH,4,3572.592,4519.032,-12.57456,0,0,0,0,100,0),
(@PATH,5,3611.974,4514.621,-11.45239,0,0,0,0,100,0),
(@PATH,6,3596.514,4512.68,-11.4117,0,0,0,0,100,0),
(@PATH,7,3591.572,4513.184,-12.59506,0,0,0,0,100,0),
(@PATH,8,3572.187,4519.236,-12.62936,0,0,0,0,100,0),
(@PATH,9,3542.318,4553.094,-11.18209,0,0,0,0,100,0),
(@PATH,10,3538.412,4553.636,-12.23789,0,0,0,0,100,0),
(@PATH,11,3540.325,4553.921,-11.9877,0,0,0,0,100,0),
(@PATH,12,3551.078,4546.787,-12.28936,0,0,0,0,100,0);
-- 0x1C39AC47601904C00000A30000661A2D .go 3540.325 4553.921 -11.9877


-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57149;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3440.258,`position_y`=4514.217,`position_z`=-12.88582 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3440.258,4514.217,-12.88582,2,0,0,0,100,0),
(@PATH,2,3440.258,4514.217,-12.88582,2,0,0,0,100,0),
(@PATH,3,3440.896,4516.193,-12.89167,3,0,0,0,100,0),
(@PATH,4,3442.607,4496.93,-12.91095,0,0,0,0,100,0),
(@PATH,5,3447.15,4488.138,-12.65823,0,0,0,0,100,0),
(@PATH,6,3452.752,4476.723,-12.68911,0,0,0,0,100,0),
(@PATH,7,3476.311,4474.729,-12.71476,0,0,0,0,100,0),
(@PATH,8,3494.302,4476.382,-12.71264,0,0,0,0,100,0),
(@PATH,9,3494.728,4476.228,-12.96695,3,0,0,0,100,0),
(@PATH,10,3511.506,4473.141,-12.958,0,0,0,0,100,0),
(@PATH,11,3494.125,4476.339,-12.96727,0,0,0,0,100,0),
(@PATH,12,3494.088,4476.244,-12.71688,0,0,0,0,100,0),
(@PATH,13,3476.16,4474.544,-12.68911,0,0,0,0,100,0),
(@PATH,14,3444.08,4494.611,-12.66572,0,0,0,0,100,0),
(@PATH,15,3442.532,4497.133,-12.64838,0,0,0,0,100,0),
(@PATH,16,3440.716,4522.266,-12.63575,0,0,0,0,100,0),
(@PATH,17,3440.376,4522.044,-12.88582,0,0,0,0,100,0),
(@PATH,18,3440.543,4522.067,-12.6481,0,0,0,0,100,0),
(@PATH,19,3447.229,4487.997,-12.65975,0,0,0,0,100,0),
(@PATH,20,3452.721,4477.046,-12.68911,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000A000063A957 .go 3440.258 4514.217 -12.88582

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104890;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3649.046,`position_y`=3947.566,`position_z`=25.10987 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3649.046,3947.566,25.10987,0,0,0,0,100,0),
(@PATH,2,3670.215,3953.261,27.32766,0,0,0,0,100,0),
(@PATH,3,3661.302,3951.949,25.85034,0,0,0,0,100,0),
(@PATH,4,3647.474,3946.993,24.98032,0,0,0,0,100,0),
(@PATH,5,3631.758,3945.262,25.08576,0,0,0,0,100,0),
(@PATH,6,3635.313,3944.982,24.81682,0,0,0,0,100,0),
(@PATH,7,3649.313,3947.802,25.10083,0,0,0,0,100,0),
(@PATH,8,3670.304,3953.393,27.30864,0,0,0,0,100,0);
-- 0x1C39AC47601919000000A3000065CBC5 .go 3649.046 3947.566 25.10987

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3612.053,`position_y`=3969.457,`position_z`=25.79908 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3612.053,3969.457,25.79908,0,0,0,0,100,0),
(@PATH,2,3612.913,3949.386,26.9285,0,0,0,0,100,0),
(@PATH,3,3606.506,3943.484,27.81473,0,0,0,0,100,0),
(@PATH,4,3599.383,3941.598,27.42816,0,0,0,0,100,0),
(@PATH,5,3613.519,3957.487,25.68642,0,0,0,0,100,0),
(@PATH,6,3610.85,3975.829,26.71345,0,0,0,0,100,0),
(@PATH,7,3610.689,3977.498,26.90823,0,0,0,0,100,0);
-- 0x1C39AC47601919000000A3000065CBB6 .go 3612.053 3969.457 25.79908

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104885;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3547.306,`position_y`=3938.455,`position_z`=28.18571 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3547.306,3938.455,28.18571,0,0,0,0,100,0),
(@PATH,2,3547.207,3940.361,28.20439,0,0,0,0,100,0),
(@PATH,3,3549.885,3950.133,28.27749,0,0,0,0,100,0),
(@PATH,4,3547.638,3926.375,28.40306,0,0,0,0,100,0),
(@PATH,5,3546.562,3908.686,26.7371,0,0,0,0,100,0);
-- 0x1C39AC47601919000000990000649C8A .go 3547.306 3938.455 28.18571

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104894;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3778.342,`position_y`=3912.803,`position_z`=29.24027 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3778.342,3912.803,29.24027,0,0,0,0,100,0),
(@PATH,2,3759.181,3931.342,27.90885,0,0,0,0,100,0),
(@PATH,3,3753.393,3933.303,27.37968,0,0,0,0,100,0),
(@PATH,4,3753.327,3933.25,27.1396,0,0,0,0,100,0),
(@PATH,5,3770.313,3927.754,29.42538,0,0,0,0,100,0),
(@PATH,6,3771.412,3927.011,29.40953,0,0,0,0,100,0),
(@PATH,7,3778.897,3901.917,30.91071,0,0,0,0,100,0);
-- 0x1C39AC476019190000000A00005F9DDF .go 3778.342 3912.803 29.24027


-- Pathing for  Entry: 25615 'TDB FORMAT' 
SET @NPC := 97719;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3952.9,`position_y`=3970.767,`position_z`=60.06356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '45797');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3952.9,3970.767,60.06356,0,0,0,0,100,0),
(@PATH,2,3978.35,3999.136,62.92397,0,0,0,0,100,0),
(@PATH,3,4018.881,4028.354,68.87595,0,0,0,0,100,0),
(@PATH,4,4054.792,4041.589,78.42586,0,0,0,0,100,0),
(@PATH,5,4079.642,4057.923,86.41113,0,0,0,0,100,0),
(@PATH,6,4109.986,4083.86,91.92527,0,0,0,0,100,0),
(@PATH,7,4146.447,4095.262,94.97155,0,0,0,0,100,0),
(@PATH,8,4116.737,4088.786,92.95302,0,0,0,0,100,0),
(@PATH,9,4085.337,4060.936,87.70323,0,0,0,0,100,0),
(@PATH,10,4058.099,4043.569,79.66705,0,0,0,0,100,0),
(@PATH,11,4020.782,4029.594,69.42237,0,0,0,0,100,0),
(@PATH,12,3994.482,4012.06,64.00913,0,0,0,0,100,0),
(@PATH,13,3968.87,3988.12,59.70909,0,0,0,0,100,0),
(@PATH,14,3929.95,3947.708,63.23425,0,0,0,0,100,0),
(@PATH,15,3911.141,3924.254,62.15401,0,0,0,0,100,0),
(@PATH,16,3873.239,3894.211,53.25244,0,0,0,0,100,0),
(@PATH,17,3906.264,3919.628,61.43396,0,0,0,0,100,0),
(@PATH,18,3928.859,3946.259,63.19824,0,0,0,0,100,0),
(@PATH,19,3952.789,3970.748,60.02489,0,0,0,0,100,0);
-- 0x1C39AC47601903C00000FB00006640F7 .go 3952.9 3970.767 60.06356

-- Pathing for  Entry: 25684 'TDB FORMAT' 
SET @NPC := 103453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4426.675,`position_y`=4548.689,`position_z`=105.0451 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4426.675,4548.689,105.0451,0,0,0,0,100,0),
(@PATH,2,4426.097,4567.237,105.0696,0,0,0,0,100,0),
(@PATH,3,4427.304,4550.866,105.1948,0,0,0,0,100,0),
(@PATH,4,4424.215,4542.484,104.0657,0,0,0,0,100,0),
(@PATH,5,4408.765,4527.845,109.2442,0,0,0,0,100,0),
(@PATH,6,4417.008,4531.223,106.1703,0,0,0,0,100,0),
(@PATH,7,4426.797,4548.548,105.0981,0,0,0,0,100,0),
(@PATH,8,4426.019,4567.411,105.0588,0,0,0,0,100,0);
-- 0x1C39AC47601915000000F80000663747 .go 4426.675 4548.689 105.0451

-- Cult Plaguebringer SAI
SET @ENTRY := 24957;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,900000,500000,700000,11,45850,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cult Plaguebringer - Out of Combat - Cast 'Ghoul Summons'"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,"Cult Plaguebringer - On Respawn - Cast 'Plague Cauldron Beam'"),
(@ENTRY,0,2,0,0,0,30,0,1100,6300,8800,13800,11,50356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cult Plaguebringer - In Combat - Cast 'Inject Plague'"),
(@ENTRY,0,3,0,21,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,"Cult Plaguebringer - On Reached Home - Cast 'Plague Cauldron Beam'"),
(@ENTRY,0,4,0,1,0,100,0,5000,10000,10000,15000,11,45864,0,0,0,0,0,19,23837,20,0,0,0,0,0,"Cult Plaguebringer - Out of Combat - Cast 'Soul Missile'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=45864;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45864, 0, 0, 31, 0, 3, 23837, 0, 0, 0, 0, '', 'Visual - ony targets Dummy');

DELETE FROM `waypoints` WHERE `entry`=965560;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(965560, 1,3882.081,3605.613,47.20867, 'Darkfallen Bloodbearer'),
(965560, 2,3880.675,3604.947,46.98143, 'Darkfallen Bloodbearer'),
(965560, 3,3873.556,3605.217,47.1648, 'Darkfallen Bloodbearer'),
(965560, 4,3864.232,3594.599,46.89387, 'Darkfallen Bloodbearer'),
(965560, 5,3863.215,3593.009,46.80249, 'Darkfallen Bloodbearer'),
(965560, 6,3857.541,3589.546,46.89201, 'Darkfallen Bloodbearer'),
(965560, 7,3849.738,3589.315,47.19809, 'Darkfallen Bloodbearer'),
(965560, 8,3841.684,3593.68,47.05273, 'Darkfallen Bloodbearer'),
(965560, 9,3835.923,3599.622,47.26691, 'Darkfallen Bloodbearer'),
(965560, 10,3828.859,3599.792,47.14082, 'Darkfallen Bloodbearer'),
(965560, 11,3821.26,3598.35,46.8344, 'Darkfallen Bloodbearer'),
(965560, 12,3806.117,3590.271,48.67004, 'Darkfallen Bloodbearer'),
(965560, 13,3801.333,3586.158,49.71964, 'Darkfallen Bloodbearer');

-- Darkfallen Bloodbearer SAI
SET @GUID := -96556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,965560,0,0,0,0,1,0,0,0,0,0,0,0,"Darkfallen Bloodbearer - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,13,965560,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkfallen Bloodbearer - On Waypoint 13 Reached - Despawn In 2000 ms");
--
DELETE FROM `conditions` WHERE `SourceEntry`=56727;
DELETE FROM `conditions` WHERE `SourceEntry`=36546 AND `SourceGroup`=1;
DELETE FROM `conditions` WHERE `SourceEntry`=58118;
DELETE FROM `conditions` WHERE `SourceEntry`=48397 AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`= 44997 AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`= 70529;
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceEntry`=70471;
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceEntry`=71310;
UPDATE `smart_scripts` SET `action_param2`=9715 WHERE  `entryorguid`=19172 AND `source_type`=0 AND `id`=10 AND `link`=0;
--
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=17587;
SET @ENTRY := 17587;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` IN (11, 12, 13, 14, 15, 16);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 11, 0, 26, 0, 100, 0, 1, 15, 60000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - IC_LOS - TALK'),
(@ENTRY, 0, 12, 0, 53, 0, 100, 0, 1, 200000, 20000, 20000, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - RECEIVE_HEAL - TALK'),
(@ENTRY, 0, 13, 0, 5, 0, 100, 0, 30000, 30000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - KILL - TALK'),
(@ENTRY, 0, 14, 0, 1, 0, 100, 0, 60000, 60000, 60000, 60000, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - OOC - TALK'),
(@ENTRY, 0, 15, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - AGGRO - TALK'),
(@ENTRY,0,16,0,11,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Respawn ' Remove npcflag");
DELETE FROM  smart_scripts  WHERE `entryorguid`=24178 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24178,0,3,0,8,0,0,0,43209,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shatterhorn - On Place Meat spellhit remove unit flags');
-- 
-- Keritose Bloodblade SAI
SET @ENTRY := 30946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,10110,0,0,0,85,58698,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keritose Bloodblade - On Gossip Option 0 Selected - Invoker Cast 'Possessed Skeletal Assault Gryphon'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceEntry`=0 AND `SourceGroup`=10110;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`elseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,10110,0,9,0,13172,0,0,0,'show gossip on quest 13172 taken');

-- Restless Lookout SAI
SET @ENTRY := 30951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,45254,0,0,0,33,30951,0,0,0,0,0,21,50,0,0,0,0,0,0,"Restless Lookout - On Spellhit 'Suicide' - Quest Credit 'Honor is for the Weak'"),
(@ENTRY,0,2,0,8,0,100,0,59234,0,0,0,33,31555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Restless Lookout - On Spellhit 'Firebomb' - Quest Credit 'Seeds of Chaos'");

-- Risen Laborer SAI
SET @ENTRY := 30949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,59234,0,0,0,33,31555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Risen Laborer - On Spellhit 'Firebomb' - Quest Credit 'Seeds of Chaos'");

/* gryphon */
DELETE FROM `creature_template_addon` WHERE `entry`=31157;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(31157, 0, 0, 33554432, 0, 0, '55971');
UPDATE `creature_template` SET `InhabitType`=4, `spell1`= 59234 WHERE `entry`=31157;

-- Skeletal Assault Gryphon SAI
SET @ENTRY := 31157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,31157,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,35,31157,0,0,11,50630,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Waypoint 35 Reached - Cast 'Eject All Passengers'"),
(@ENTRY,0,2,0,61,0,100,0,36,31157,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Waypoint 36 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=31157;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(31157, 1, 8397.621, 2683.953, 657.3679, 'Skeletal Assault Gryphon'),
(31157, 2, 8370.314, 2727.218, 664.7281, 'Skeletal Assault Gryphon'),
(31157, 3, 8335.474, 2760.751, 670.5891, 'Skeletal Assault Gryphon'),
(31157, 4, 8289.219, 2785.704, 674.7277, 'Skeletal Assault Gryphon'),
(31157, 5, 8212.881, 2826.851, 661.2293, 'Skeletal Assault Gryphon'),
(31157, 6, 8070.518, 2879.992, 614.7838, 'Skeletal Assault Gryphon'),
(31157, 7, 7950.946, 2893.043, 570.5617, 'Skeletal Assault Gryphon'),
(31157, 8, 7859.049, 2925.734, 547.0621, 'Skeletal Assault Gryphon'),
(31157, 9, 7804.694, 2973.792, 558.8955, 'Skeletal Assault Gryphon'),
(31157, 10, 7725.221, 3051.099, 570.2289, 'Skeletal Assault Gryphon'),
(31157, 11, 7658.346, 3084.103, 576.8101, 'Skeletal Assault Gryphon'),
(31157, 12, 7591.941, 3146.263, 587.5597, 'Skeletal Assault Gryphon'),
(31157, 13, 7576.145, 3203.526, 598.5592, 'Skeletal Assault Gryphon'),
(31157, 14, 7622.536, 3240.809, 611.8931, 'Skeletal Assault Gryphon'),
(31157, 15, 7703.133, 3210.107, 613.2822, 'Skeletal Assault Gryphon'),
(31157, 16, 7796.588, 3149.966, 615.9203, 'Skeletal Assault Gryphon'),
(31157, 17, 7889.656, 3088.229, 614.7259, 'Skeletal Assault Gryphon'),
(31157, 18, 7983.687, 3018.498, 597.3369, 'Skeletal Assault Gryphon'),
(31157, 19, 8053.703, 2943.441, 588.1163, 'Skeletal Assault Gryphon'),
(31157, 20, 8076.742, 2864.08, 582.1427, 'Skeletal Assault Gryphon'),
(31157, 21, 8005.022, 2790.798, 556.4193, 'Skeletal Assault Gryphon'),
(31157, 22, 7897.278, 2831.605, 550.6705, 'Skeletal Assault Gryphon'),
(31157, 23, 7847.702, 2963.348, 561.8926, 'Skeletal Assault Gryphon'),
(31157, 24, 7792.906, 3089.349, 590.8646, 'Skeletal Assault Gryphon'),
(31157, 25, 7735.124, 3173.07, 604.7814, 'Skeletal Assault Gryphon'),
(31157, 26, 7620.355, 3179.519, 599.2814, 'Skeletal Assault Gryphon'),
(31157, 27, 7590.6, 3106.805, 591.0317, 'Skeletal Assault Gryphon'),
(31157, 28, 7650.019, 3055.191, 581.8378, 'Skeletal Assault Gryphon'),
(31157, 29, 7734.892, 3021.323, 573.1149, 'Skeletal Assault Gryphon'),
(31157, 30, 7862.496, 2979.27, 572.5039, 'Skeletal Assault Gryphon'),
(31157, 31, 7956.528, 2972.131, 575.9482, 'Skeletal Assault Gryphon'),
(31157, 32, 8039.022, 2947.35, 576.0869, 'Skeletal Assault Gryphon'),
(31157, 33, 8155.893, 2883.776, 606.1532, 'Skeletal Assault Gryphon'),
(31157, 34, 8239.198, 2805.797, 654.0699, 'Skeletal Assault Gryphon'),
(31157, 35, 8290.536, 2766.505, 682.2192, 'Skeletal Assault Gryphon'),
(31157, 36, 8353.981, 2708.914, 714.5253, 'Skeletal Assault Gryphon');
--
DELETE FROM `creature` WHERE `id` = 29498;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (29500) AND `accessory_entry` IN (29498);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(29500,29498,0,1,'Brunnhildar Warbear',8,0);

DELETE FROM `creature` WHERE `id` = 30175;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (30174) AND `accessory_entry` IN (30175);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(30174,30175,0,1,'Hyldsmeet Warbear',8,0);
-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132553;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3852.509,`position_y`=3183.065,`position_z`=439.9884 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3852.509,3183.065,439.9884,0,0,0,0,100,0),
(@PATH,2,-3819.889,3184.794,439.9884,0,0,0,0,100,0),
(@PATH,3,-3782.827,3181.228,439.9884,0,0,0,0,100,0),
(@PATH,4,-3750.342,3182.072,439.9884,0,0,0,0,100,0),
(@PATH,5,-3722.763,3185.583,439.9884,0,0,0,0,100,0),
(@PATH,6,-3686.632,3214.135,439.9884,0,0,0,0,100,0),
(@PATH,7,-3656.386,3240.646,439.9884,0,0,0,0,100,0),
(@PATH,8,-3626.851,3272.052,439.9884,0,0,0,0,100,0),
(@PATH,9,-3614.448,3315.655,439.9884,0,0,0,0,100,0),
(@PATH,10,-3607.889,3352.559,439.9884,0,0,0,0,100,0),
(@PATH,11,-3585.032,3376.603,439.9884,0,0,0,0,100,0),
(@PATH,12,-3587.389,3402.663,439.9884,0,0,0,0,100,0),
(@PATH,13,-3579.043,3438.117,439.9884,0,0,0,0,100,0),
(@PATH,14,-3548.228,3462.314,439.9884,0,0,0,0,100,0),
(@PATH,15,-3537.522,3491.375,439.9884,0,0,0,0,100,0),
(@PATH,16,-3536.816,3529.879,439.9884,0,0,0,0,100,0),
(@PATH,17,-3531.781,3565.558,439.9884,0,0,0,0,100,0),
(@PATH,18,-3534.733,3584.761,439.9884,0,0,0,0,100,0),
(@PATH,19,-3540.309,3619.033,439.9884,0,0,0,0,100,0),
(@PATH,20,-3548.71,3648.066,439.9884,0,0,0,0,100,0),
(@PATH,21,-3565.15,3673.789,439.9884,0,0,0,0,100,0),
(@PATH,22,-3593.257,3700.032,439.9884,0,0,0,0,100,0),
(@PATH,23,-3629.609,3714.834,439.9884,0,0,0,0,100,0),
(@PATH,24,-3663.73,3728.198,439.9884,0,0,0,0,100,0),
(@PATH,25,-3699.584,3743.161,439.9884,0,0,0,0,100,0),
(@PATH,26,-3730.971,3758.693,439.9884,0,0,0,0,100,0),
(@PATH,27,-3763.805,3764.051,439.9884,0,0,0,0,100,0),
(@PATH,28,-3796.277,3791.6,439.9884,0,0,0,0,100,0),
(@PATH,29,-3829.475,3825.91,439.9884,0,0,0,0,100,0),
(@PATH,30,-3866.195,3833.057,439.9884,0,0,0,0,100,0),
(@PATH,31,-3901.688,3854.476,439.9884,0,0,0,0,100,0),
(@PATH,32,-3932.767,3851.711,439.9884,0,0,0,0,100,0),
(@PATH,33,-3965.585,3849.424,439.9884,0,0,0,0,100,0),
(@PATH,34,-3999.315,3846.842,439.9884,0,0,0,0,100,0),
(@PATH,35,-4034.047,3812.782,439.9884,0,0,0,0,100,0),
(@PATH,36,-4053.754,3766.908,439.9884,0,0,0,0,100,0),
(@PATH,37,-4065.977,3737.402,439.9884,0,0,0,0,100,0),
(@PATH,38,-4097.885,3717.781,439.9884,0,0,0,0,100,0),
(@PATH,39,-4102.042,3680.511,439.9884,0,0,0,0,100,0),
(@PATH,40,-4104.036,3655.926,439.9884,0,0,0,0,100,0),
(@PATH,41,-4101.168,3611.585,439.9884,0,0,0,0,100,0),
(@PATH,42,-4102.894,3574.591,439.9884,0,0,0,0,100,0),
(@PATH,43,-4103.932,3544.913,439.9884,0,0,0,0,100,0),
(@PATH,44,-4104.642,3508.564,439.9884,0,0,0,0,100,0),
(@PATH,45,-4106.799,3476.665,439.9884,0,0,0,0,100,0),
(@PATH,46,-4107.433,3449.932,439.9884,0,0,0,0,100,0),
(@PATH,47,-4104.114,3418.243,439.9884,0,0,0,0,100,0),
(@PATH,48,-4089.375,3376.191,439.9884,0,0,0,0,100,0),
(@PATH,49,-4055.623,3343.717,446.405,0,0,0,0,100,0),
(@PATH,50,-4011.469,3341.788,448.6551,0,0,0,0,100,0),
(@PATH,51,-3975.74,3311.974,446.6827,0,0,0,0,100,0),
(@PATH,52,-3947.277,3278.158,445.544,0,0,0,0,100,0),
(@PATH,53,-3922.814,3246.151,445.7939,0,0,0,0,100,0),
(@PATH,54,-3886.357,3212.919,439.9884,0,0,0,0,100,0);
-- 0x1C393042401682C000002B0003B619B4 .go -3852.509 3183.065 439.9884

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3844.01,`position_y`=3755.452,`position_z`=357.5598 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3844.01,3755.452,357.5598,0,0,0,0,100,0),
(@PATH,2,-3852.51,3791.215,357.0599,0,0,0,0,100,0),
(@PATH,3,-3890.182,3810.264,355.8931,0,0,0,0,100,0),
(@PATH,4,-3916.092,3784.685,356.5043,0,0,0,0,100,0),
(@PATH,5,-3923.033,3754.531,361.0602,0,0,0,0,100,0),
(@PATH,6,-3922.995,3732.825,381.1874,0,0,0,0,100,0),
(@PATH,7,-3926.192,3702.992,389.9645,0,0,0,0,100,0),
(@PATH,8,-3920.217,3670.407,389.9645,0,0,0,0,100,0),
(@PATH,9,-3902.139,3652.927,389.9645,0,0,0,0,100,0),
(@PATH,10,-3881.576,3654.323,389.9645,0,0,0,0,100,0),
(@PATH,11,-3865.405,3672.89,381.4647,0,0,0,0,100,0),
(@PATH,12,-3862.587,3682.567,374.4212,0,0,0,0,100,0),
(@PATH,13,-3856.335,3709.221,366.0322,0,0,0,0,100,0);
-- 0x1C393042401682C000002C00003804ED .go -3844.01 3755.452 357.5598

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 79017;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3712.47,`position_y`=3449.822,`position_z`=329.5283 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3712.47,3449.822,329.5283,0,0,0,0,100,0),
(@PATH,2,-3692.213,3483.701,323.2226,0,0,0,0,100,0),
(@PATH,3,-3682.306,3518.447,319.0838,0,0,0,0,100,0),
(@PATH,4,-3686.292,3551.121,328.0282,0,0,0,0,100,0),
(@PATH,5,-3704.019,3589.462,327.0838,0,0,0,0,100,0),
(@PATH,6,-3720.923,3618.094,323.1671,0,0,0,0,100,0),
(@PATH,7,-3746.331,3629.958,322.9449,0,0,0,0,100,0),
(@PATH,8,-3788.036,3651.199,328.056,0,0,0,0,100,0),
(@PATH,9,-3829.155,3656.951,343.6671,0,0,0,0,100,0),
(@PATH,10,-3864.913,3641.72,343.6671,0,0,0,0,100,0),
(@PATH,11,-3899.767,3634.007,334.5004,0,0,0,0,100,0),
(@PATH,12,-3932.793,3625.805,327.7227,0,0,0,0,100,0),
(@PATH,13,-3965.984,3604.831,323.5561,0,0,0,0,100,0),
(@PATH,14,-3994.316,3568.82,324.0004,0,0,0,0,100,0),
(@PATH,15,-4020.807,3533.474,321.6671,0,0,0,0,100,0),
(@PATH,16,-4017.46,3505.427,320.4171,0,0,0,0,100,0),
(@PATH,17,-4012.915,3469.437,318.2504,0,0,0,0,100,0),
(@PATH,18,-4008.829,3443.473,322.9727,0,0,0,0,100,0),
(@PATH,19,-3987.128,3409.836,320.0283,0,0,0,0,100,0),
(@PATH,20,-3956.549,3381.68,323.2782,0,0,0,0,100,0),
(@PATH,21,-3917.093,3373.904,324.1949,0,0,0,0,100,0),
(@PATH,22,-3879.394,3373.863,331.1393,0,0,0,0,100,0),
(@PATH,23,-3846.889,3379.781,335.556,0,0,0,0,100,0),
(@PATH,24,-3815.72,3383.242,336.0282,0,0,0,0,100,0),
(@PATH,25,-3785.73,3387.147,333.7504,0,0,0,0,100,0),
(@PATH,26,-3745.971,3412.045,331.7226,0,0,0,0,100,0);
-- 0x1C393042401682C00000D80000384658 .go -3712.47 3449.822 329.5283

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132567;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3800.044,`position_y`=3329.872,`position_z`=342.0992 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3800.044,3329.872,342.0992,0,0,0,0,100,0),
(@PATH,2,-3820.034,3366.339,344.5435,0,0,0,0,100,0),
(@PATH,3,-3848.72,3382.158,349.6544,0,0,0,0,100,0),
(@PATH,4,-3866.445,3399.19,356.9323,0,0,0,0,100,0),
(@PATH,5,-3892.608,3428.64,364.4878,0,0,0,0,100,0),
(@PATH,6,-3875.494,3457.741,364.4878,0,0,0,0,100,0),
(@PATH,7,-3846.305,3462.793,364.4878,0,0,0,0,100,0),
(@PATH,8,-3835.524,3455.278,363.4879,0,0,0,0,100,0),
(@PATH,9,-3826.342,3432.901,363.4879,0,0,0,0,100,0),
(@PATH,10,-3833.529,3403.362,349.9602,0,0,0,0,100,0),
(@PATH,11,-3849.905,3384.756,348.2379,0,0,0,0,100,0),
(@PATH,12,-3869.018,3342.68,345.9046,0,0,0,0,100,0),
(@PATH,13,-3866.873,3308.942,344.5435,0,0,0,0,100,0),
(@PATH,14,-3833.351,3299.779,344.5435,0,0,0,0,100,0);
-- 0x1C393042401682C00000D80000389A53 .go -3800.044 3329.872 342.0992

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4027.127,`position_y`=3236.136,`position_z`=342.3879 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4027.127,3236.136,342.3879,0,0,0,0,100,0),
(@PATH,2,-4050.725,3247.826,342.3879,0,0,0,0,100,0),
(@PATH,3,-4074.902,3254.402,339.4433,0,0,0,0,100,0),
(@PATH,4,-4099.817,3279.177,340.388,0,0,0,0,100,0),
(@PATH,5,-4090.614,3300.566,342.3879,0,0,0,0,100,0),
(@PATH,6,-4066.256,3322.034,342.3879,0,0,0,0,100,0),
(@PATH,7,-4034.025,3315.976,340.4436,0,0,0,0,100,0),
(@PATH,8,-4000.627,3300.234,340.7216,0,0,0,0,100,0),
(@PATH,9,-3962.779,3269.458,342.3879,0,0,0,0,100,0),
(@PATH,10,-3932.333,3241.691,350.61,0,0,0,0,100,0),
(@PATH,11,-3924.384,3214.195,353.11,0,0,0,0,100,0),
(@PATH,12,-3948.188,3192.575,352.915,0,0,0,0,100,0),
(@PATH,13,-3975.502,3190.098,351.4991,0,0,0,0,100,0),
(@PATH,14,-4002.08,3217.684,348.0821,0,0,0,0,100,0);
-- 0x1C393042401682C00000D800003947B4 .go -4027.127 3236.136 342.3879

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86099;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3617.656,`position_y`=3768.498,`position_z`=321.4414 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3617.656,3768.498,321.4414,0,0,0,0,100,0),
(@PATH,2,-3621.72,3753.039,319.025,0,0,0,0,100,0),
(@PATH,3,-3619.644,3727.897,309.8305,0,0,0,0,100,0),
(@PATH,4,-3627.178,3681.108,308.5527,0,0,0,0,100,0),
(@PATH,5,-3656.429,3650.599,304.2195,0,0,0,0,100,0),
(@PATH,6,-3696.808,3638.603,303.0528,0,0,0,0,100,0),
(@PATH,7,-3734.566,3654.597,302.6361,0,0,0,0,100,0),
(@PATH,8,-3766.324,3670.245,301.1362,0,0,0,0,100,0),
(@PATH,9,-3799.271,3684.971,303.1361,0,0,0,0,100,0),
(@PATH,10,-3832.15,3705.031,308.4691,0,0,0,0,100,0),
(@PATH,11,-3868.131,3721.502,318.4415,0,0,0,0,100,0),
(@PATH,12,-3909.399,3735.214,328.5527,0,0,0,0,100,0),
(@PATH,13,-3931.017,3766.784,334.3581,0,0,0,0,100,0),
(@PATH,14,-3917.445,3807.967,334.4695,0,0,0,0,100,0),
(@PATH,15,-3890.349,3823.759,327.1638,0,0,0,0,100,0),
(@PATH,16,-3849.03,3819.391,319.025,0,0,0,0,100,0),
(@PATH,17,-3822.998,3781.306,314.3583,0,0,0,0,100,0),
(@PATH,18,-3792.191,3762.3,302.9972,0,0,0,0,100,0),
(@PATH,19,-3753.88,3777.921,300.1917,0,0,0,0,100,0),
(@PATH,20,-3738.559,3813.297,304.1084,0,0,0,0,100,0),
(@PATH,21,-3707.912,3826.754,304.9972,0,0,0,0,100,0),
(@PATH,22,-3666.76,3801.158,304.9972,0,0,0,0,100,0),
(@PATH,23,-3632.452,3787.691,313.8025,0,0,0,0,100,0);
-- 0x1C393042401682C00000D800003950AB .go -3617.656 3768.498 321.4414

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132562;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3740.354,`position_y`=3781.2,`position_z`=318.1236 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3740.354,3781.2,318.1236,0,0,0,0,100,0),
(@PATH,2,-3733.342,3800.063,318.5958,0,0,0,0,100,0),
(@PATH,3,-3700.761,3815.838,314.9293,0,0,0,0,100,0),
(@PATH,4,-3684.377,3790.57,311.3183,0,0,0,0,100,0),
(@PATH,5,-3673.302,3755.679,311.3183,0,0,0,0,100,0),
(@PATH,6,-3654.191,3733.858,317.7345,0,0,0,0,100,0),
(@PATH,7,-3627.812,3735.349,321.0125,0,0,0,0,100,0),
(@PATH,8,-3620.85,3745.508,318.7352,0,0,0,0,100,0),
(@PATH,9,-3616.733,3766.586,318.0404,0,0,0,0,100,0),
(@PATH,10,-3633.59,3782.3,318.1792,0,0,0,0,100,0),
(@PATH,11,-3666.707,3773.215,316.2348,0,0,0,0,100,0),
(@PATH,12,-3699.968,3755.006,317.2626,0,0,0,0,100,0),
(@PATH,13,-3728.831,3766.574,318.1514,0,0,0,0,100,0);
-- 0x1C393042401682C00000D800003955EA .go -3740.354 3781.2 318.1236

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132558;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3889.631,`position_y`=3647.446,`position_z`=379.841 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3889.631,3647.446,379.841,0,0,0,0,100,0),
(@PATH,2,-3867.698,3661.597,374.2303,0,0,0,0,100,0),
(@PATH,3,-3829.105,3657.187,352.5638,0,0,0,0,100,0),
(@PATH,4,-3781.735,3660.671,339.2026,0,0,0,0,100,0),
(@PATH,5,-3733.907,3659.38,326.0082,0,0,0,0,100,0),
(@PATH,6,-3700.169,3654.304,306.0638,0,0,0,0,100,0),
(@PATH,7,-3666.533,3646.272,305.6747,0,0,0,0,100,0),
(@PATH,8,-3633.503,3666.819,305.6747,0,0,0,0,100,0),
(@PATH,9,-3615.833,3700.001,308.675,0,0,0,0,100,0),
(@PATH,10,-3612.93,3733.396,310.8136,0,0,0,0,100,0),
(@PATH,11,-3620.4,3766.181,312.2859,0,0,0,0,100,0),
(@PATH,12,-3633.891,3791.979,308.6469,0,0,0,0,100,0),
(@PATH,13,-3672.738,3787.063,303.5358,0,0,0,0,100,0),
(@PATH,14,-3699.661,3766.161,308.3416,0,0,0,0,100,0),
(@PATH,15,-3722.004,3734.262,307.3692,0,0,0,0,100,0),
(@PATH,16,-3758.981,3700.716,303.9804,0,0,0,0,100,0),
(@PATH,17,-3780.951,3669.244,307.3969,0,0,0,0,100,0),
(@PATH,18,-3823.718,3662.368,306.5638,0,0,0,0,100,0),
(@PATH,19,-3855.767,3696.363,309.2023,0,0,0,0,100,0),
(@PATH,20,-3888.813,3716.222,313.5079,0,0,0,0,100,0),
(@PATH,21,-3922.735,3736.949,316.8968,0,0,0,0,100,0),
(@PATH,22,-3932.095,3764.875,321.5081,0,0,0,0,100,0),
(@PATH,23,-3910.485,3799.088,334.758,0,0,0,0,100,0),
(@PATH,24,-3868.099,3812.761,342.1745,0,0,0,0,100,0),
(@PATH,25,-3842.411,3793.997,354.0078,0,0,0,0,100,0),
(@PATH,26,-3820.221,3754.304,346.8967,0,0,0,0,100,0),
(@PATH,27,-3833.732,3709.265,337.0357,0,0,0,0,100,0),
(@PATH,28,-3851.1,3670.116,337.0357,0,0,0,0,100,0),
(@PATH,29,-3880.107,3634.346,337.0357,0,0,0,0,100,0),
(@PATH,30,-3922.091,3616.533,325.3135,0,0,0,0,100,0),
(@PATH,31,-3965.485,3605.971,311.0912,0,0,0,0,100,0),
(@PATH,32,-3990.204,3580.163,305.9802,0,0,0,0,100,0),
(@PATH,33,-4011.796,3540.719,305.9802,0,0,0,0,100,0),
(@PATH,34,-4011.68,3508.126,305.9802,0,0,0,0,100,0),
(@PATH,35,-3987.115,3486.282,305.9802,0,0,0,0,100,0),
(@PATH,36,-3945.38,3469.3,318.369,0,0,0,0,100,0),
(@PATH,37,-3915.382,3492.937,334.7857,0,0,0,0,100,0),
(@PATH,38,-3903.774,3531.629,345.4246,0,0,0,0,100,0),
(@PATH,39,-3920.156,3565.949,365.369,0,0,0,0,100,0),
(@PATH,40,-3933.356,3594.115,376.4244,0,0,0,0,100,0),
(@PATH,41,-3912.393,3631.522,376.4244,0,0,0,0,100,0);
-- 0x1C393042401682C00000D8000039560D .go -3889.631 3647.446 379.841

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86116;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3876.833,`position_y`=3314.512,`position_z`=379.5609 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3876.833,3314.512,379.5609,0,0,0,0,100,0),
(@PATH,2,-3886.097,3325.345,379.5609,0,0,0,0,100,0),
(@PATH,3,-3911.672,3347.092,379.5609,0,0,0,0,100,0),
(@PATH,4,-3945.02,3355.806,379.5609,0,0,0,0,100,0),
(@PATH,5,-3972.972,3374.654,379.5609,0,0,0,0,100,0),
(@PATH,6,-4009.497,3393.97,379.5609,0,0,0,0,100,0),
(@PATH,7,-4038.995,3394.833,379.5609,0,0,0,0,100,0),
(@PATH,8,-4084.306,3383.78,379.5609,0,0,0,0,100,0),
(@PATH,9,-4114.101,3348.398,379.5609,0,0,0,0,100,0),
(@PATH,10,-4121.285,3315.157,359.6998,0,0,0,0,100,0),
(@PATH,11,-4133.357,3269.041,344.6721,0,0,0,0,100,0),
(@PATH,12,-4127.872,3224.243,336.2553,0,0,0,0,100,0),
(@PATH,13,-4088.58,3195.296,338.8943,0,0,0,0,100,0),
(@PATH,14,-4068.468,3153.282,341.0054,0,0,0,0,100,0),
(@PATH,15,-4070.876,3123.454,342.6997,0,0,0,0,100,0),
(@PATH,16,-4097.591,3094.782,347.3387,0,0,0,0,100,0),
(@PATH,17,-4122.666,3063.981,348.1721,0,0,0,0,100,0),
(@PATH,18,-4162.276,3056.197,349.6165,0,0,0,0,100,0),
(@PATH,19,-4202.113,3083.117,358.5054,0,0,0,0,100,0),
(@PATH,20,-4214.216,3116.871,357.2553,0,0,0,0,100,0),
(@PATH,21,-4193.599,3157.323,355.2832,0,0,0,0,100,0),
(@PATH,22,-4155.592,3185.045,347.0332,0,0,0,0,100,0),
(@PATH,23,-4111.882,3181.491,345.0887,0,0,0,0,100,0),
(@PATH,24,-4062.104,3179.68,348.9498,0,0,0,0,100,0),
(@PATH,25,-4020.427,3179.234,361.4219,0,0,0,0,100,0),
(@PATH,26,-3982.672,3180.415,363.0051,0,0,0,0,100,0),
(@PATH,27,-3951.448,3159.866,363.561,0,0,0,0,100,0),
(@PATH,28,-3937.524,3133.349,370.6444,0,0,0,0,100,0),
(@PATH,29,-3931.404,3105.327,376.0884,0,0,0,0,100,0),
(@PATH,30,-3933.873,3066.744,379.5609,0,0,0,0,100,0),
(@PATH,31,-3940.64,3017.597,385.5607,0,0,0,0,100,0),
(@PATH,32,-3962.612,2986.642,387.3109,0,0,0,0,100,0),
(@PATH,33,-3987.704,2976.624,388.1721,0,0,0,0,100,0),
(@PATH,34,-4028.228,2974.074,379.5609,0,0,0,0,100,0),
(@PATH,35,-4068.643,2997.102,369.2554,0,0,0,0,100,0),
(@PATH,36,-4093.04,3026.769,367.2279,0,0,0,0,100,0),
(@PATH,37,-4081.151,3058.765,357.4498,0,0,0,0,100,0),
(@PATH,38,-4050.25,3086.566,362.8388,0,0,0,0,100,0),
(@PATH,39,-4009.628,3109.691,361.9498,0,0,0,0,100,0),
(@PATH,40,-3962.259,3115.2,365.2273,0,0,0,0,100,0),
(@PATH,41,-3931.493,3131.271,371.1159,0,0,0,0,100,0),
(@PATH,42,-3901.853,3157.168,376.1166,0,0,0,0,100,0),
(@PATH,43,-3882.195,3190.008,374.5609,0,0,0,0,100,0),
(@PATH,44,-3907.507,3233.704,369.0056,0,0,0,0,100,0),
(@PATH,45,-3930.386,3264.117,346.8111,0,0,0,0,100,0),
(@PATH,46,-3952.398,3305.412,329.4775,0,0,0,0,100,0),
(@PATH,47,-3949.958,3344.656,317.033,0,0,0,0,100,0),
(@PATH,48,-3933.078,3390.3,316.2833,0,0,0,0,100,0),
(@PATH,49,-3924.384,3438.506,320.0887,0,0,0,0,100,0),
(@PATH,50,-3908.001,3480.083,321.7832,0,0,0,0,100,0),
(@PATH,51,-3881.964,3513.231,323.2551,0,0,0,0,100,0),
(@PATH,52,-3844.591,3536.472,335.8942,0,0,0,0,100,0),
(@PATH,53,-3822.905,3535.266,339.8388,0,0,0,0,100,0),
(@PATH,54,-3792.544,3507.122,337.1997,0,0,0,0,100,0),
(@PATH,55,-3760.572,3487.132,351.5052,0,0,0,0,100,0),
(@PATH,56,-3744.966,3453.418,364.5887,0,0,0,0,100,0),
(@PATH,57,-3744.307,3416.908,367.4221,0,0,0,0,100,0),
(@PATH,58,-3740.536,3368.536,367.0887,0,0,0,0,100,0),
(@PATH,59,-3734.622,3321.623,379.5609,0,0,0,0,100,0),
(@PATH,60,-3731.181,3282.171,379.5609,0,0,0,0,100,0),
(@PATH,61,-3694.877,3249.842,379.5609,0,0,0,0,100,0),
(@PATH,62,-3655.565,3261.063,379.5609,0,0,0,0,100,0),
(@PATH,63,-3641.669,3284.071,367.7832,0,0,0,0,100,0),
(@PATH,64,-3641.303,3315.587,364.9221,0,0,0,0,100,0),
(@PATH,65,-3654.031,3343.666,369.4221,0,0,0,0,100,0),
(@PATH,66,-3680.551,3352.762,367.6165,0,0,0,0,100,0),
(@PATH,67,-3714.793,3358.927,363.9776,0,0,0,0,100,0),
(@PATH,68,-3753.792,3357.834,379.5609,0,0,0,0,100,0),
(@PATH,69,-3787.513,3323.292,384.7554,0,0,0,0,100,0),
(@PATH,70,-3817.402,3284.448,390.9497,0,0,0,0,100,0),
(@PATH,71,-3855.805,3289.496,379.5609,0,0,0,0,100,0);
-- 0x1C393042401682C00000D80000395FE7 .go -3876.833 3314.512 379.5609

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132564;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3811.575,`position_y`=3318.012,`position_z`=350.0489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3811.575,3318.012,350.0489,0,0,0,0,100,0),
(@PATH,2,-3839.544,3360.737,346.5213,0,0,0,0,100,0),
(@PATH,3,-3844.532,3382.859,327.4657,0,0,0,0,100,0),
(@PATH,4,-3824.744,3421.51,330.4099,0,0,0,0,100,0),
(@PATH,5,-3815.863,3458.307,331.2989,0,0,0,0,100,0),
(@PATH,6,-3810.683,3497.717,331.2989,0,0,0,0,100,0),
(@PATH,7,-3813.658,3530.778,320.3824,0,0,0,0,100,0),
(@PATH,8,-3816.187,3562.303,309.2156,0,0,0,0,100,0),
(@PATH,9,-3807.29,3592.113,304.2435,0,0,0,0,100,0),
(@PATH,10,-3785.319,3618.569,304.2435,0,0,0,0,100,0),
(@PATH,11,-3745.147,3632.447,304.2435,0,0,0,0,100,0),
(@PATH,12,-3709.023,3627.542,304.2435,0,0,0,0,100,0),
(@PATH,13,-3675.768,3604.466,304.2435,0,0,0,0,100,0),
(@PATH,14,-3671.146,3576.667,304.2435,0,0,0,0,100,0),
(@PATH,15,-3681.459,3543.929,304.2435,0,0,0,0,100,0),
(@PATH,16,-3683.946,3516.303,304.2435,0,0,0,0,100,0),
(@PATH,17,-3690.97,3482.81,304.2435,0,0,0,0,100,0),
(@PATH,18,-3718.609,3446.152,304.2435,0,0,0,0,100,0),
(@PATH,19,-3752.872,3415.494,304.2435,0,0,0,0,100,0),
(@PATH,20,-3787.441,3393.248,306.6046,0,0,0,0,100,0),
(@PATH,21,-3819.708,3391.489,304.2435,0,0,0,0,100,0),
(@PATH,22,-3843.183,3389.003,306.9379,0,0,0,0,100,0),
(@PATH,23,-3878.647,3381.219,308.4658,0,0,0,0,100,0),
(@PATH,24,-3917.604,3385.046,313.9101,0,0,0,0,100,0),
(@PATH,25,-3948.888,3388.875,314.6601,0,0,0,0,100,0),
(@PATH,26,-3981.859,3411.407,311.4101,0,0,0,0,100,0),
(@PATH,27,-4006.548,3451.265,312.8823,0,0,0,0,100,0),
(@PATH,28,-4013.026,3483.869,313.6044,0,0,0,0,100,0),
(@PATH,29,-4007.704,3522.086,312.9934,0,0,0,0,100,0),
(@PATH,30,-3979.958,3551.535,309.1602,0,0,0,0,100,0),
(@PATH,31,-3949.836,3557.036,311.2711,0,0,0,0,100,0),
(@PATH,32,-3916.583,3556.782,310.1602,0,0,0,0,100,0),
(@PATH,33,-3878.491,3547.684,308.91,0,0,0,0,100,0),
(@PATH,34,-3848.358,3529.306,308.3823,0,0,0,0,100,0),
(@PATH,35,-3810.661,3519.969,310.9657,0,0,0,0,100,0),
(@PATH,36,-3788.128,3509.623,314.0764,0,0,0,0,100,0),
(@PATH,37,-3746.377,3484.105,314.4373,0,0,0,0,100,0),
(@PATH,38,-3720.415,3453.266,311.1879,0,0,0,0,100,0),
(@PATH,39,-3711.39,3414.835,316.1873,0,0,0,0,100,0),
(@PATH,40,-3695.241,3382.754,310.2711,0,0,0,0,100,0),
(@PATH,41,-3690.628,3349.262,309.5486,0,0,0,0,100,0),
(@PATH,42,-3707.501,3320.029,317.0488,0,0,0,0,100,0),
(@PATH,43,-3743.783,3305.247,330.9655,0,0,0,0,100,0),
(@PATH,44,-3787.108,3314.23,339.9933,0,0,0,0,100,0);
-- 0x1C393042401682C00000D80000397863 .go -3811.575 3318.012 350.0489

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132554;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4096.788,`position_y`=3033.959,`position_z`=360.6063 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4096.788,3033.959,360.6063,0,0,0,0,100,0),
(@PATH,2,-4104.214,3041.3,359.5785,0,0,0,0,100,0),
(@PATH,3,-4125.444,3052.258,358.9676,0,0,0,0,100,0),
(@PATH,4,-4159.867,3033.596,358.9952,0,0,0,0,100,0),
(@PATH,5,-4186.089,3020.478,361.662,0,0,0,0,100,0),
(@PATH,6,-4216.206,3023.308,363.8009,0,0,0,0,100,0),
(@PATH,7,-4219.776,3049.481,362.9398,0,0,0,0,100,0),
(@PATH,8,-4205.974,3076.206,360.8285,0,0,0,0,100,0),
(@PATH,9,-4175.602,3071.705,356.4121,0,0,0,0,100,0),
(@PATH,10,-4149.558,3039.067,356.4121,0,0,0,0,100,0),
(@PATH,11,-4139.287,3016.167,361.1343,0,0,0,0,100,0),
(@PATH,12,-4115.834,2995.427,363.3842,0,0,0,0,100,0),
(@PATH,13,-4089.456,3009.014,362.3842,0,0,0,0,100,0);
-- 0x1C393042401682C00000D80000397B33 .go -4096.788 3033.959 360.6063

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 83238;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3740.354,`position_y`=3781.2,`position_z`=318.1236 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3740.354,3781.2,318.1236,0,0,0,0,100,0),
(@PATH,2,-3733.342,3800.063,318.5958,0,0,0,0,100,0),
(@PATH,3,-3700.761,3815.838,314.9293,0,0,0,0,100,0),
(@PATH,4,-3684.377,3790.57,311.3183,0,0,0,0,100,0),
(@PATH,5,-3673.302,3755.679,311.3183,0,0,0,0,100,0),
(@PATH,6,-3654.191,3733.858,317.7345,0,0,0,0,100,0),
(@PATH,7,-3627.812,3735.349,321.0125,0,0,0,0,100,0),
(@PATH,8,-3620.85,3745.508,318.7352,0,0,0,0,100,0),
(@PATH,9,-3616.733,3766.586,318.0404,0,0,0,0,100,0),
(@PATH,10,-3633.59,3782.3,318.1792,0,0,0,0,100,0),
(@PATH,11,-3666.707,3773.215,316.2348,0,0,0,0,100,0),
(@PATH,12,-3699.968,3755.006,317.2626,0,0,0,0,100,0),
(@PATH,13,-3728.831,3766.574,318.1514,0,0,0,0,100,0);
-- 0x1C393042401682C00000D800003989DF .go -3740.354 3781.2 318.1236

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132566;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3671.494,`position_y`=3402.642,`position_z`=324.4617 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3671.494,3402.642,324.4617,0,0,0,0,100,0),
(@PATH,2,-3675.101,3400.796,324.5731,0,0,0,0,100,0),
(@PATH,3,-3695.996,3378.851,323.7954,0,0,0,0,100,0),
(@PATH,4,-3677.757,3333.374,329.4622,0,0,0,0,100,0),
(@PATH,5,-3671.793,3306.185,341.9066,0,0,0,0,100,0),
(@PATH,6,-3691.331,3277.393,341.9066,0,0,0,0,100,0),
(@PATH,7,-3714.71,3287.554,341.9066,0,0,0,0,100,0),
(@PATH,8,-3715.633,3314.267,336.4897,0,0,0,0,100,0),
(@PATH,9,-3681.489,3340.859,327.934,0,0,0,0,100,0),
(@PATH,10,-3648.484,3360.056,326.1562,0,0,0,0,100,0),
(@PATH,11,-3641.23,3384.09,325.4897,0,0,0,0,100,0),
(@PATH,12,-3655.433,3406.725,325.0451,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE000039182E .go -3671.494 3402.642 324.4617

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132556;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4209.313,`position_y`=3165.873,`position_z`=345.6776 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4209.313,3165.873,345.6776,0,0,0,0,100,0),
(@PATH,2,-4209.917,3166.669,345.6776,0,0,0,0,100,0),
(@PATH,3,-4214.472,3180.67,347.2502,0,0,0,0,100,0),
(@PATH,4,-4216.52,3213.613,345.6775,0,0,0,0,100,0),
(@PATH,5,-4208.682,3255.884,339.0109,0,0,0,0,100,0),
(@PATH,6,-4189.062,3300.134,333.0109,0,0,0,0,100,0),
(@PATH,7,-4149.259,3324.875,328.7887,0,0,0,0,100,0),
(@PATH,8,-4108.452,3350.17,317.011,0,0,0,0,100,0),
(@PATH,9,-4062.702,3352.578,312.0665,0,0,0,0,100,0),
(@PATH,10,-4014.43,3348.026,315.1498,0,0,0,0,100,0),
(@PATH,11,-3986.476,3375.022,322.1496,0,0,0,0,100,0),
(@PATH,12,-3981.146,3423.131,315.4276,0,0,0,0,100,0),
(@PATH,13,-3984.354,3463.035,318.9552,0,0,0,0,100,0),
(@PATH,14,-3983.076,3512.558,312.2053,0,0,0,0,100,0),
(@PATH,15,-3966.213,3540.754,323.3442,0,0,0,0,100,0),
(@PATH,16,-3949.22,3584.559,328.372,0,0,0,0,100,0),
(@PATH,17,-3913.326,3616.715,336.8163,0,0,0,0,100,0),
(@PATH,18,-3871.808,3634.682,342.0666,0,0,0,0,100,0),
(@PATH,19,-3845.71,3666.634,355.0107,0,0,0,0,100,0),
(@PATH,20,-3851.377,3715.548,351.7607,0,0,0,0,100,0),
(@PATH,21,-3821.307,3750.763,351.2052,0,0,0,0,100,0),
(@PATH,22,-3795.161,3777.228,334.7328,0,0,0,0,100,0),
(@PATH,23,-3763.429,3800.694,324.3996,0,0,0,0,100,0),
(@PATH,24,-3732.729,3778.102,316.9553,0,0,0,0,100,0),
(@PATH,25,-3699.662,3753.815,315.6498,0,0,0,0,100,0),
(@PATH,26,-3666.87,3741.209,315.7607,0,0,0,0,100,0),
(@PATH,27,-3634.06,3717.237,319.2329,0,0,0,0,100,0),
(@PATH,28,-3613.867,3678.084,317.8165,0,0,0,0,100,0),
(@PATH,29,-3622.779,3632.821,322.9277,0,0,0,0,100,0),
(@PATH,30,-3620.368,3590.816,320.0942,0,0,0,0,100,0),
(@PATH,31,-3625.737,3551.353,323.3442,0,0,0,0,100,0),
(@PATH,32,-3626.56,3508.485,328.3718,0,0,0,0,100,0),
(@PATH,33,-3652.823,3477.152,326.2332,0,0,0,0,100,0),
(@PATH,34,-3666.577,3433.208,328.844,0,0,0,0,100,0),
(@PATH,35,-3689.016,3394.729,323.7608,0,0,0,0,100,0),
(@PATH,36,-3716.738,3363.748,323.2885,0,0,0,0,100,0),
(@PATH,37,-3754.879,3351.833,332.8161,0,0,0,0,100,0),
(@PATH,38,-3795.422,3366.06,336.0938,0,0,0,0,100,0),
(@PATH,39,-3839.274,3378.524,336.0663,0,0,0,0,100,0),
(@PATH,40,-3884.272,3383.12,331.8162,0,0,0,0,100,0),
(@PATH,41,-3923.974,3361.845,329.0664,0,0,0,0,100,0),
(@PATH,42,-3938.367,3317.121,327.0108,0,0,0,0,100,0),
(@PATH,43,-3970.304,3289.182,332.4276,0,0,0,0,100,0),
(@PATH,44,-4001.49,3256,340.0942,0,0,0,0,100,0),
(@PATH,45,-4017.281,3211.053,337.8997,0,0,0,0,100,0),
(@PATH,46,-4034.001,3168.051,336.3162,0,0,0,0,100,0),
(@PATH,47,-4060.109,3128.304,345.6775,0,0,0,0,100,0),
(@PATH,48,-4089.788,3088.067,342.4553,0,0,0,0,100,0),
(@PATH,49,-4130.021,3082.164,339.8998,0,0,0,0,100,0),
(@PATH,50,-4161.369,3103.56,345.6775,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE0000391BB1 .go -4209.313 3165.873 345.6776

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132565;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3700.187,`position_y`=3268.531,`position_z`=332.5694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3700.187,3268.531,332.5694,0,0,0,0,100,0),
(@PATH,2,-3712.445,3309.058,332.5694,0,0,0,0,100,0),
(@PATH,3,-3731.05,3347.229,317.6805,0,0,0,0,100,0),
(@PATH,4,-3716.804,3386.164,312.5971,0,0,0,0,100,0),
(@PATH,5,-3714.796,3416.085,310.3194,0,0,0,0,100,0),
(@PATH,6,-3726.431,3460.464,311.0414,0,0,0,0,100,0),
(@PATH,7,-3753.865,3482.538,314.9584,0,0,0,0,100,0),
(@PATH,8,-3788.998,3508.942,314.9305,0,0,0,0,100,0),
(@PATH,9,-3824.704,3524.107,309.9028,0,0,0,0,100,0),
(@PATH,10,-3848.736,3512.536,316.0972,0,0,0,0,100,0),
(@PATH,11,-3888.76,3485.173,326.2916,0,0,0,0,100,0),
(@PATH,12,-3912.334,3450.138,334.236,0,0,0,0,100,0),
(@PATH,13,-3915.319,3410.722,336.7916,0,0,0,0,100,0),
(@PATH,14,-3881.387,3385.134,337.5138,0,0,0,0,100,0),
(@PATH,15,-3847.486,3374.93,332.5694,0,0,0,0,100,0),
(@PATH,16,-3805.386,3361.039,326.6804,0,0,0,0,100,0),
(@PATH,17,-3773.776,3364.174,321.6806,0,0,0,0,100,0),
(@PATH,18,-3746.576,3378.93,320.8195,0,0,0,0,100,0),
(@PATH,19,-3711.678,3399.851,324.7638,0,0,0,0,100,0),
(@PATH,20,-3677.318,3417.94,324.6248,0,0,0,0,100,0),
(@PATH,21,-3633.113,3400.247,323.4301,0,0,0,0,100,0),
(@PATH,22,-3626.553,3376.975,323.0689,0,0,0,0,100,0),
(@PATH,23,-3616.881,3334.872,332.5694,0,0,0,0,100,0),
(@PATH,24,-3627.39,3296.557,332.5694,0,0,0,0,100,0),
(@PATH,25,-3664.143,3265.263,332.5694,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE0000391D86 .go -3700.187 3268.531 332.5694

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132555;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3910.414,`position_y`=2965.875,`position_z`=390.4576 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3910.414,2965.875,390.4576,0,0,0,0,100,0),
(@PATH,2,-3933.329,2966.657,390.4576,0,0,0,0,100,0),
(@PATH,3,-3954.885,2975.502,382.291,0,0,0,0,100,0),
(@PATH,4,-3963.788,3013.65,381.3741,0,0,0,0,100,0),
(@PATH,5,-3969.197,3050.419,375.9853,0,0,0,0,100,0),
(@PATH,6,-3984.531,3090.169,372.0131,0,0,0,0,100,0),
(@PATH,7,-3972.277,3135.571,367.5407,0,0,0,0,100,0),
(@PATH,8,-3947.474,3178.757,362.0132,0,0,0,0,100,0),
(@PATH,9,-3930.654,3222.331,346.0132,0,0,0,0,100,0),
(@PATH,10,-3944.785,3269.054,337.6526,0,0,0,0,100,0),
(@PATH,11,-3988.984,3283.474,328.0133,0,0,0,0,100,0),
(@PATH,12,-4020.175,3305.831,332.7634,0,0,0,0,100,0),
(@PATH,13,-4043.304,3338.783,339.9855,0,0,0,0,100,0),
(@PATH,14,-4076.572,3375.872,343.2631,0,0,0,0,100,0),
(@PATH,15,-4067.485,3424.765,347.1243,0,0,0,0,100,0),
(@PATH,16,-4037.804,3458.173,351.3187,0,0,0,0,100,0),
(@PATH,17,-4007.092,3452.119,341.2909,0,0,0,0,100,0),
(@PATH,18,-3969.205,3437.343,334.1797,0,0,0,0,100,0),
(@PATH,19,-3932.203,3431.731,332.2077,0,0,0,0,100,0),
(@PATH,20,-3896.705,3421.381,327.7629,0,0,0,0,100,0),
(@PATH,21,-3871.978,3389.38,331.041,0,0,0,0,100,0),
(@PATH,22,-3827.513,3390.714,332.2075,0,0,0,0,100,0),
(@PATH,23,-3802.128,3368.306,336.7633,0,0,0,0,100,0),
(@PATH,24,-3790.874,3332.89,343.6242,0,0,0,0,100,0),
(@PATH,25,-3808.656,3291.044,352.0409,0,0,0,0,100,0),
(@PATH,26,-3817.205,3243.875,361.9853,0,0,0,0,100,0),
(@PATH,27,-3841.924,3206.913,365.2077,0,0,0,0,100,0),
(@PATH,28,-3882.906,3183.564,363.3185,0,0,0,0,100,0),
(@PATH,29,-3903.045,3142.097,372.3742,0,0,0,0,100,0),
(@PATH,30,-3883.694,3111.339,382.5131,0,0,0,0,100,0),
(@PATH,31,-3856.857,3076.734,390.4576,0,0,0,0,100,0),
(@PATH,32,-3843.808,3035.878,390.4576,0,0,0,0,100,0),
(@PATH,33,-3833.452,2993.256,390.4576,0,0,0,0,100,0),
(@PATH,34,-3866.545,2965.673,390.4576,0,0,0,0,100,0),
(@PATH,35,-3910.414,2965.875,390.4576,0,0,0,0,100,0),
(@PATH,36,-3933.329,2966.657,390.4576,0,0,0,0,100,0),
(@PATH,37,-3954.885,2975.502,382.291,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE0000393AF6 .go -3910.414 2965.875 390.4576

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 132560;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4210.051,`position_y`=3036.035,`position_z`=359.2715 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4210.051,3036.035,359.2715,0,0,0,0,100,0),
(@PATH,2,-4197.814,3024.344,366.188,0,0,0,0,100,0),
(@PATH,3,-4166.595,3015.782,353.327,0,0,0,0,100,0),
(@PATH,4,-4119.361,3000.518,350.3828,0,0,0,0,100,0),
(@PATH,5,-4078.058,3004.437,346.7713,0,0,0,0,100,0),
(@PATH,6,-4047.495,3033.212,346.8269,0,0,0,0,100,0),
(@PATH,7,-4037.817,3075.937,350.9382,0,0,0,0,100,0),
(@PATH,8,-4037.221,3122.487,345.1326,0,0,0,0,100,0),
(@PATH,9,-4020.077,3150.257,329.8825,0,0,0,0,100,0),
(@PATH,10,-3983.114,3172.777,330.1326,0,0,0,0,100,0),
(@PATH,11,-3945.796,3163.176,338.4935,0,0,0,0,100,0),
(@PATH,12,-3906.744,3138.077,347.0493,0,0,0,0,100,0),
(@PATH,13,-3872.958,3116.541,357.4377,0,0,0,0,100,0),
(@PATH,14,-3857.695,3086.127,367.6046,0,0,0,0,100,0),
(@PATH,15,-3866.051,3043.046,372.1045,0,0,0,0,100,0),
(@PATH,16,-3902.363,3025,374.7159,0,0,0,0,100,0),
(@PATH,17,-3939.945,3047.438,368.138,0,0,0,0,100,0),
(@PATH,18,-3976.81,3075.321,357.9659,0,0,0,0,100,0),
(@PATH,19,-4015.781,3101.057,352.3272,0,0,0,0,100,0),
(@PATH,20,-4057.297,3120.64,344.0215,0,0,0,0,100,0),
(@PATH,21,-4093.992,3151.9,340.0216,0,0,0,0,100,0),
(@PATH,22,-4133.575,3148.626,338.077,0,0,0,0,100,0),
(@PATH,23,-4161.596,3113.013,348.6326,0,0,0,0,100,0),
(@PATH,24,-4193.336,3081.118,359.2715,0,0,0,0,100,0),
(@PATH,25,-4214.105,3060.078,359.2715,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE0000393F44 .go -4210.051 3036.035 359.2715

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3894.564,`position_y`=3430.655,`position_z`=372.4708 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3894.564,3430.655,372.4708,0,0,0,0,100,0),
(@PATH,2,-3857.21,3447.031,372.4708,0,0,0,0,100,0),
(@PATH,3,-3823.56,3471.693,372.4708,0,0,0,0,100,0),
(@PATH,4,-3784.599,3479.697,372.4708,0,0,0,0,100,0),
(@PATH,5,-3742.468,3490.947,353.0265,0,0,0,0,100,0),
(@PATH,6,-3709.652,3520.501,345.0263,0,0,0,0,100,0),
(@PATH,7,-3664.314,3533.171,334.0263,0,0,0,0,100,0),
(@PATH,8,-3616.403,3539.115,323.9706,0,0,0,0,100,0),
(@PATH,9,-3582.801,3553.028,325.193,0,0,0,0,100,0),
(@PATH,10,-3589.008,3587.388,329.9429,0,0,0,0,100,0),
(@PATH,11,-3636.932,3603.025,325.1376,0,0,0,0,100,0),
(@PATH,12,-3663.247,3624.526,321.2208,0,0,0,0,100,0),
(@PATH,13,-3704.071,3625.825,318.6652,0,0,0,0,100,0),
(@PATH,14,-3750.566,3629.281,322.7488,0,0,0,0,100,0),
(@PATH,15,-3785.251,3646.629,322.5265,0,0,0,0,100,0),
(@PATH,16,-3821.648,3660.992,332.4431,0,0,0,0,100,0),
(@PATH,17,-3844.523,3693.082,347.1931,0,0,0,0,100,0),
(@PATH,18,-3873.079,3712.225,349.1932,0,0,0,0,100,0),
(@PATH,19,-3903.724,3693.448,347.4153,0,0,0,0,100,0),
(@PATH,20,-3935.185,3680.15,346.9429,0,0,0,0,100,0),
(@PATH,21,-3961.531,3655.501,345.2486,0,0,0,0,100,0),
(@PATH,22,-3966.79,3606.822,348.2763,0,0,0,0,100,0),
(@PATH,23,-3973.929,3571.161,341.0261,0,0,0,0,100,0),
(@PATH,24,-3980.9,3522.605,335.8875,0,0,0,0,100,0),
(@PATH,25,-4004.451,3487.919,317.9431,0,0,0,0,100,0),
(@PATH,26,-4001.448,3441.261,334.3042,0,0,0,0,100,0),
(@PATH,27,-3966.929,3406.75,330.5819,0,0,0,0,100,0),
(@PATH,28,-3922.993,3396.193,351.9707,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE00003946C7 .go -3894.564 3430.655 372.4708

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86131;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3884.442,`position_y`=3113.831,`position_z`=389.185 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3884.442,3113.831,389.185,0,0,0,0,100,0),
(@PATH,2,-3869.677,3093.181,392.3522,0,0,0,0,100,0),
(@PATH,3,-3876.115,3078.8,392.3522,0,0,0,0,100,0),
(@PATH,4,-3900.006,3066.922,392.3522,0,0,0,0,100,0),
(@PATH,5,-3934.172,3083.277,392.3522,0,0,0,0,100,0),
(@PATH,6,-3942.406,3108.275,392.3522,0,0,0,0,100,0),
(@PATH,7,-3955.406,3132.591,392.3522,0,0,0,0,100,0),
(@PATH,8,-3983.802,3151.235,400.1577,0,0,0,0,100,0),
(@PATH,9,-4018.729,3167.318,408.8244,0,0,0,0,100,0),
(@PATH,10,-4048.56,3146.723,397.5466,0,0,0,0,100,0),
(@PATH,11,-4034.677,3106.917,375.3246,0,0,0,0,100,0),
(@PATH,12,-3999.241,3105.82,364.3524,0,0,0,0,100,0),
(@PATH,13,-3976.743,3112.321,363.4634,0,0,0,0,100,0),
(@PATH,14,-3934.065,3120.998,373.4079,0,0,0,0,100,0),
(@PATH,15,-3904.763,3124.439,386.7683,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE0000394785 .go -3884.442 3113.831 389.185

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 83237;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3620.779,`position_y`=3761.98,`position_z`=319.1757 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3620.779,3761.98,319.1757,0,0,0,0,100,0),
(@PATH,2,-3621.137,3762.914,319.1757,0,0,0,0,100,0),
(@PATH,3,-3621.72,3753.039,319.025,0,0,0,0,100,0),
(@PATH,4,-3619.644,3727.897,309.8305,0,0,0,0,100,0),
(@PATH,5,-3627.178,3681.108,308.5527,0,0,0,0,100,0),
(@PATH,6,-3656.429,3650.599,304.2195,0,0,0,0,100,0),
(@PATH,7,-3696.808,3638.603,303.0528,0,0,0,0,100,0),
(@PATH,8,-3734.566,3654.597,302.6361,0,0,0,0,100,0),
(@PATH,9,-3766.324,3670.245,301.1362,0,0,0,0,100,0),
(@PATH,10,-3799.271,3684.971,303.1361,0,0,0,0,100,0),
(@PATH,11,-3832.15,3705.031,308.4691,0,0,0,0,100,0),
(@PATH,12,-3868.131,3721.502,318.4415,0,0,0,0,100,0),
(@PATH,13,-3909.399,3735.214,328.5527,0,0,0,0,100,0),
(@PATH,14,-3931.017,3766.784,334.3581,0,0,0,0,100,0),
(@PATH,15,-3917.445,3807.967,334.4695,0,0,0,0,100,0),
(@PATH,16,-3890.349,3823.759,327.1638,0,0,0,0,100,0),
(@PATH,17,-3849.03,3819.391,319.025,0,0,0,0,100,0),
(@PATH,18,-3822.998,3781.306,314.3583,0,0,0,0,100,0),
(@PATH,19,-3792.191,3762.3,302.9972,0,0,0,0,100,0),
(@PATH,20,-3753.88,3777.921,300.1917,0,0,0,0,100,0),
(@PATH,21,-3738.559,3813.297,304.1084,0,0,0,0,100,0),
(@PATH,22,-3707.912,3826.754,304.9972,0,0,0,0,100,0),
(@PATH,23,-3666.76,3801.158,304.9972,0,0,0,0,100,0),
(@PATH,24,-3632.452,3787.691,313.8025,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE00003981C1 .go -3620.779 3761.98 319.1757

-- Pathing for Monstrous Kaliri Entry: 23051 'TDB FORMAT' 
SET @NPC := 86133;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4210.051,`position_y`=3036.035,`position_z`=359.2715 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4210.051,3036.035,359.2715,0,0,0,0,100,0),
(@PATH,2,-4197.814,3024.344,366.188,0,0,0,0,100,0),
(@PATH,3,-4166.595,3015.782,353.327,0,0,0,0,100,0),
(@PATH,4,-4119.361,3000.518,350.3828,0,0,0,0,100,0),
(@PATH,5,-4078.058,3004.437,346.7713,0,0,0,0,100,0),
(@PATH,6,-4047.495,3033.212,346.8269,0,0,0,0,100,0),
(@PATH,7,-4037.817,3075.937,350.9382,0,0,0,0,100,0),
(@PATH,8,-4037.221,3122.487,345.1326,0,0,0,0,100,0),
(@PATH,9,-4020.077,3150.257,329.8825,0,0,0,0,100,0),
(@PATH,10,-3983.114,3172.777,330.1326,0,0,0,0,100,0),
(@PATH,11,-3945.796,3163.176,338.4935,0,0,0,0,100,0),
(@PATH,12,-3906.744,3138.077,347.0493,0,0,0,0,100,0),
(@PATH,13,-3872.958,3116.541,357.4377,0,0,0,0,100,0),
(@PATH,14,-3857.695,3086.127,367.6046,0,0,0,0,100,0),
(@PATH,15,-3866.051,3043.046,372.1045,0,0,0,0,100,0),
(@PATH,16,-3902.363,3025,374.7159,0,0,0,0,100,0),
(@PATH,17,-3939.945,3047.438,368.138,0,0,0,0,100,0),
(@PATH,18,-3976.81,3075.321,357.9659,0,0,0,0,100,0),
(@PATH,19,-4015.781,3101.057,352.3272,0,0,0,0,100,0),
(@PATH,20,-4057.297,3120.64,344.0215,0,0,0,0,100,0),
(@PATH,21,-4093.992,3151.9,340.0216,0,0,0,0,100,0),
(@PATH,22,-4133.575,3148.626,338.077,0,0,0,0,100,0),
(@PATH,23,-4161.596,3113.013,348.6326,0,0,0,0,100,0),
(@PATH,24,-4193.336,3081.118,359.2715,0,0,0,0,100,0),
(@PATH,25,-4214.105,3060.078,359.2715,0,0,0,0,100,0);
-- 0x1C393042401682C00000DE00003985F0 .go -4210.051 3036.035 359.2715

UPDATE `waypoint_data` SET `move_type`=1 WHERE  `id` IN (132553 * 10, 86115 * 10, 79017 * 10, 132567 * 10, 132557 * 10, 86099 * 10, 132562 * 10, 132558 * 10, 86116 * 10, 132564 * 10, 132554 * 10, 83238 * 10, 132566 * 10, 132556 * 10, 132565 * 10, 132555 * 10, 132560 * 10, 86117 * 10, 86131 * 10, 83237 * 10, 86133 * 10);

-- Pathing for Bonechewer Devastator Entry: 16772 'TDB FORMAT' 
SET @NPC := 57784;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2979.448,`position_y`=3526.724,`position_z`=-5.101617 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2979.448,3526.724,-5.101617,0,0,0,0,100,0),
(@PATH,2,-2986.465,3536.819,-4.151853,0,0,0,0,100,0),
(@PATH,3,-2999.478,3533.506,-2.088938,0,0,0,0,100,0),
(@PATH,4,-3001.169,3532.58,-1.651159,0,0,0,0,100,0),
(@PATH,5,-3001.333,3532.634,-1.814128,0,0,0,0,100,0),
(@PATH,6,-2988.259,3537.786,-3.722197,0,0,0,0,100,0),
(@PATH,7,-2983.174,3532.755,-5.044437,0,0,0,0,100,0),
(@PATH,8,-2984.85,3516.351,-3.515834,0,0,0,0,100,0);
-- 0x1C393042401061000000DE0000397551 .go -2979.448 3526.724 -5.101617
DELETE FROM `spell_proc_event` WHERE `entry` IN (33953);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(33953, 0x00, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00004400, 0x00000000, 0, 0, 45);
-- Actionlist SAI
SET @ENTRY := 6192700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,60000,60000,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4988.25,568.897,3.15542,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4994.69,573.448,2.4842,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,4,0,0,0,100,0,60000,60000,0,0,12,2205,3,120000,0,0,0,8,0,0,0,4988.25,568.897,3.15542,5,"Bonfire - On Script - Summon Creature 'Greymist Warrior'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,2205,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Warrior'"),
(@ENTRY,9,6,0,0,0,100,0,60000,60000,0,0,12,2206,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Hunter'"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,10323,3,120000,0,0,0,8,0,0,0,4994.69,573.448,2.4842,5,"Bonfire - On Script - Summon Creature 'Murkdeep'");

-- Bonfire SAI
SET @ENTRY := 61927;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,0,0,1,0,0,80,6192700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonfire - On Data Set 0 1 - Run Script");

-- Greymist Hunter SAI
SET @GUID := -37989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,1,0,0,45,0,1,0,0,0,0,14,48515,61927,0,0,0,0,0,"Greymist Hunter - On Just Died -Set Data 0 1");
DELETE FROM `spell_group` WHERE `id`=1 AND `spell_id`=63729;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES 
(1, 63729);
-- Delete wrong data for achiev Flirt With Disaster
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id`=1280 AND `horde_id`=1279;
SET @gob:=192492;
SET @spell:=56649;
SET @Veranus:=30393;
SET @Thorim:= 30390;
SET @Jokkum:=30331;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Veranus, @Thorim, @Jokkum);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Veranus, @Thorim, @Jokkum);
UPDATE `creature_template` SET `ScriptName`="", `MovementType`=2 WHERE `entry`=@Jokkum;

DELETE FROM `creature_template_addon` WHERE `entry`=@Veranus;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@Veranus, 0, 0, 33554432, 0, 0, '55971');

DELETE FROM `vehicle_template_accessory` where `entry` IN (@Veranus) AND `accessory_entry` in (@Thorim);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(@Veranus,@Thorim,0,0,'Veranus',8,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@Veranus);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Veranus, 46598, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9900,0,0,0,9,0,13010,0,0,0,0,'','Show gossip if player has quest completed'),
(15,9900,0,0,0,5,0,1119,704,0,0,0,'','Show gossip if player is at least friendly');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Jokkum AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Veranus AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Jokkum*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100+2 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Jokkum, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Jokkum*100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Start WP'),
(@Jokkum, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Talk1'),
(@Jokkum, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Add unit flag'),
(@Jokkum, 0, 3, 0, 40, 0, 100, 0, 22, @Jokkum*100, 0, 0, 80, @Jokkum*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - On way pont 22 - Actionlist'),
(@Jokkum*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @spell, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast spell to summon'),
(@Jokkum*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Root'),
(@Jokkum*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Talk2'),
(@Jokkum*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Emote'),
(@Jokkum*100, 9, 4, 0, 0, 0, 100, 0, 24000, 24000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 8, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 68442, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - remove kneel'),
(@Jokkum*100, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 80, @Thorim*100+1, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Actionlist'),
(@Jokkum*100, 9, 13, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 15, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'), 
(@Jokkum*100, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56545, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast credit'),
(@Jokkum*100, 9, 18, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast eject passenger'),
(@Jokkum*100, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - remove root'),
(@Jokkum*100, 9, 20, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 1, @Jokkum*100+1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Start WP2'),
(@Thorim*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, @gob, 400000, 0, 0, 0, 0, 8, 0, 0, 0, 7867.189453, -3255.752930, 853.379700, 2.321934, 'Thorim - ActionList - Spawn gob'),
(@Thorim*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 188142, 400000, 0, 0, 0, 0, 8, 0, 0, 0, 7867.189453, -3255.752930, 850.467590, 2.321934, 'Thorim - ActionList - Spawn gob'),
(@Thorim, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Thorim*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - Just created - actionlist'),
(@Thorim*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - set run ON'),
(@Thorim*100, 9, 1, 0, 0, 0, 100, 0, 18000, 18000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7886.027344, -3239.358887, 849.435791, 3.769581, 'Thorim - ActionList - go to pos'), 
(@Thorim*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 75, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Thorim*100, 9, 3, 0, 0, 0, 100, 0, 460000, 460000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Thorim, 0, 1, 0, 19, 0, 100, 0, 13057, 0, 0, 0, 80, @Thorim*100+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - Just created - actionlist'),
(@Thorim*100+2, 9, 0, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Veranus, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Veranus*100, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - JustSummoned - Start WP'),
(@Veranus, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - JustSummoned - Set unit_flag not selectable'),
(@Veranus, 0, 2, 0, 40, 0, 100, 0, 2, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On waypoint 2 - Eject passenger');

DELETE FROM `waypoint_data` WHERE `id` IN (2072200, 2072201);

DELETE FROM `waypoints` WHERE `entry`IN (@Jokkum*100+1, @Jokkum*100, @Veranus*100);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Jokkum*100+1,1,7837.09, -3235.54, 853.878, '@Jokkum'),
(@Jokkum*100+1,2,7828.62, -3230.38, 855.915, '@Jokkum'),
(@Jokkum*100+1,3,7793.78, -3219.74, 861.146, '@Jokkum'),
(@Jokkum*100+1,4,7765.22, -3225.37, 864.083, '@Jokkum'),
(@Jokkum*100+1,5,7736.73, -3226.5, 861.458, '@Jokkum'),
(@Jokkum*100,1,7357.09,-2865.4,803.501, '@Jokkum'),
(@Jokkum*100,2,7355.18,-2904.32,821.008, '@Jokkum'),
(@Jokkum*100,3,7355.47,-2946.65,833.092, '@Jokkum'),
(@Jokkum*100,4,7358.79,-2974.21,845.018, '@Jokkum'),
(@Jokkum*100,5,7360.87,-2994.78,845.989, '@Jokkum'),
(@Jokkum*100,6,7378.76,-3035.89,840.6, '@Jokkum'),
(@Jokkum*100,7,7411.66,-3072.21,837.577, '@Jokkum'),
(@Jokkum*100,8,7454,-3088.7,837.577, '@Jokkum'),
(@Jokkum*100,9,7496.08,-3113.92,837.583, '@Jokkum'),
(@Jokkum*100,10,7536.84,-3136.49,837.581, '@Jokkum'),
(@Jokkum*100,11,7564.74,-3145.14,844.831, '@Jokkum'),
(@Jokkum*100,12,7604.36,-3171.26,850.887, '@Jokkum'),
(@Jokkum*100,13,7635.47,-3207.21,857.19, '@Jokkum'),
(@Jokkum*100,14,7657.86,-3219.26,863.19, '@Jokkum'),
(@Jokkum*100,15,7685.42,-3218.98,867.141, '@Jokkum'),
(@Jokkum*100,16,7706.54,-3219.74,864.333, '@Jokkum'),
(@Jokkum*100,17,7747.33,-3226.99,862.458, '@Jokkum'),
(@Jokkum*100,18,7796.66,-3221.78,860.646, '@Jokkum'),
(@Jokkum*100,19,7827.6, -3229.27,856.415, '@Jokkum'),
(@Jokkum*100,20,7846.17,-3253.24,852.128, '@Jokkum'),
(@Jokkum*100,21,7849.41,-3270.86,854.538, '@Jokkum'),
(@Jokkum*100,22,7853.12,-3268.03,853.50, '@Jokkum'),
(@Veranus*100,1, 7915.017578, -3202.903076, 899.580872, '@Veranus'),
(@Veranus*100,2, 7889.363770, -3236.394043, 899.580872, '@Veranus'),  
(@Veranus*100,3, 7865.838867, -3266.453369, 899.580872, '@Veranus'),
(@Veranus*100,4, 7929.517578, -3369.971191, 899.580872, '@Veranus');
UPDATE `spell_area` SET `quest_end`='13157', `quest_end_status`='1' WHERE `spell`='57674' and`area`='4504' and`quest_start`='13086' and`aura_spell`='0' and`racemask`='0' and`gender`='2';
-- North Sea Kraken SAI
SET @ENTRY := 34925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,7000,9000,11,66514,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - IC - Cast Frost Breath'),
(@ENTRY,0, 1,0,8,0,25,0,66588,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - On Spell hit Flaming Sphere - actionList'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,11,66717,0,0,0,0,0,7,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Cast 66717'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,11,50142,2,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Cast 50142'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Turn Invisible'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Evade'),
(@ENTRY, 0, 2, 0, 1, 0, 100, 0, 30000, 30000, 30000, 30000, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - OOC - Make Visible'),
(@ENTRY, 0, 3, 4, 2, 0, 100, 1, 1, 6, 0, 0, 11, 66994, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - On Between 1 and 6% HP - Cast Kraken Tooth Explosion'),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 66717, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - Linked with previous event - Give quest credit'),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - Linked With Previous Event die'),
(@ENTRY, 0, 6, 0, 1, 0, 100, 0, 30000, 30000, 30000, 30000, 11, 68909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - OOC - Cast Submerge '),
(@ENTRY, 0, 7, 0, 0, 0, 100, 0, 15000, 20000, 15000, 20000, 11, 66511, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - IC - Whirl');
DELETE FROM `spell_scripts` WHERE `id`= 66477;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(66477, 0, 0, 15, 66622, 2, 1, 0, 0, 0, 0),
(66477, 0, 0, 15, 66478, 2, 1, 0, 0, 0, 0),
(66477, 0, 0, 15, 66041, 2, 1, 0, 0, 0, 0);
-- A Distraction For Akama
SET @Maiev          := 22989; -- Maev
SET @Akama          := 22990; -- Akama
SET @Vagath         := 23152; -- Vagath 
SET @IllidariShadow := 22988; -- IllidariShadow
SET @Ashtongue      := 21701; -- Ashtongue
SET @FanOfBlades    := 39954; -- Maev spell
SET @Stealth        := 34189; -- Maev spell
SET @ChainLightning := 39945; -- Akama spell 
SET @Xiri           := 18528; -- XI'RI
SET @IllidariRavag  := 22857; -- Illidari Ravager
SET @LightOfTheNaa1 := 39829; -- XI'RI spell
SET @LightOfTheNaa2 := 39831; -- XI'RI spell
SET @FyraDawnstar   := 22864; -- FyraDawnstar
SET @Caalen         := 22862; -- Anachorete Caalen
SET @Lightsworn     := 22861; -- Lightsworn Vindicator
SET @Magister       := 22863; -- Seasoned Magister
SET @ID             := 8650;  -- Gossip Menu

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (22989, 22990, 23152, 22988, 21701, 18528, 22857, 22864, 22863, 22862, 22861);
UPDATE `creature_template` SET `npcflag`=0 where `entry`=22990;
DELETE FROM creature_summon_groups WHERE summonerid=@Xiri;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@Xiri,0,0,@Akama,-3557.775635,624.185852,6.244853,4.687259,3,300000),
(@Xiri,0,0,@Maiev,-3563.998047,623.326050,6.134195,4.687259,3,300000),  
(@Xiri,0,0,@Ashtongue,-3568.963867,627.467407,5.477327,4.742220,3,300000), 
(@Xiri,0,0,@Ashtongue,-3565.453125,627.804199,5.458982,4.801125,3,300000),
(@Xiri,0,0,@Ashtongue,-3561.734375,628.002930,5.536494,4.76578,3,300000),
(@Xiri,0,0,@Ashtongue,-3557.638428,628.221863,5.681130,4.76578,3,300000),
(@Xiri,0,0,@Ashtongue,-3554.038574,628.414246,5.853768,4.76578,3,300000), 
(@Xiri,0,0,@Ashtongue,-3557.367188,632.975952,5.016828,4.830713,3,300000), 
(@Xiri,0,0,@Ashtongue,-3561.433350,632.492554,4.889128,4.830713,3,300000), 
(@Xiri,0,0,@Ashtongue,-3565.568848,632.000916,4.862391,4.830713,3,300000),
(@Xiri,0,0,@Vagath,-3564.023438,406.373199,29.640791,1.577282,3,300000),
(@Xiri,0,0,@IllidariRavag,-3570.985840,408.893219,29.715797,1.529191,3,300000),
(@Xiri,0,0,@IllidariRavag,-3556.721924,409.166534,29.495508,1.599877,3,300000),
(@Xiri,0,0,@IllidariShadow,-3571.129395,418.261780,28.846333,1.556680,3,300000),
(@Xiri,0,0,@IllidariShadow,-3581.750977,417.807861,30.357321,1.560607,3,300000),
(@Xiri,0,0,@IllidariShadow,-3576.343506,424.403748,28.781679,1.482065,3,300000),
(@Xiri,0,0,@IllidariShadow,-3568.493652,427.238312,28.031080,1.609870,3,300000),
(@Xiri,0,0,@IllidariShadow,-3559.938232,428.418793,27.697611,1.641286,3,300000),
(@Xiri,0,0,@IllidariShadow,-3564.919678,432.020447,27.485765,1.633432,3,300000);

DELETE FROM `creature_text` WHERE `entry` IN (@Akama, @FyraDawnstar, @Caalen, @Vagath, @Maiev, @Xiri) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(@FyraDawnstar, 0, 0, 'Onward, Scryers! Show Illidan''s lackeys the temper of our steel!', 14, 0, 100, 0, 0, 0, 'Fyra Downstar', 20696),
(@Caalen, 0, 0, 'Come closer, demon! Death awaits!', 12, 0, 100, 0, 0, 0, 'Caalen', 20670),
(@Caalen, 0, 1, 'Illidan''s lapdogs! Destroy them all!', 12, 0, 100, 0, 0, 0, 'Caalen', 20669),
(@Caalen, 0, 2, 'I''ve a message for your master, scum!', 12, 0, 100, 0, 0, 0, 'Caalen', 20672),
(@Caalen, 0, 3, 'Pathetic worm... your master''s days are over!', 12, 0, 100, 0, 0, 0, 'Caalen', 20671),
(@Caalen, 0, 4, 'For Xi''ri!  For the Sha''tar!', 12, 0, 100, 0, 0, 0, 'Caalen', 20667),
(@Caalen, 0, 5, 'Your end is at hand, Illidari!', 12, 0, 100, 0, 0, 0, 'Caalen', 20668),
(@Vagath, 0, 0, 'Pitiful wretches. You dared invade Illidan''s temple? Very well, I shall make it your death bed!', 14, 0, 100, 0, 0, 0, 'Vagath', 20719),
(@Akama, 0, 0, 'Now is the time, Maiev! Unleash your wrath!', 14, 0, 100, 0, 0, 0, 'Akama', 20742),
(@Maiev, 0, 0, 'I''ve waited for this moment for years. Illidan and his lapdogs will be destroyed!', 14, 0, 100, 0, 0, 0, 'Maiev', 20743),
(@Akama, 1, 0, 'Slay all who see us! Word must not get back to Illidan.', 14, 0, 100, 0, 0, 0, 'Akama', 20744),
(@Maiev, 1, 0, 'Meet your end, demon!', 12, 0, 100, 0, 0, 0, 'Maiev', 0),
(@Vagath, 1, 0, 'You''ve sealed you fate, Akama. The Master will learn from your betrayal!', 14, 0, 100, 0, 0, 0, 'Vagath', 20745),
(@Akama, 2, 0, 'Akama has no master, not anymore.', 12, 0, 100, 0, 0, 0, 'Akama', 20746),
(@Akama, 3, 0, 'Our plans are in danger already. It appears Maiev''s decided to do things her own way.', 12, 0, 100, 0, 0, 0, 'Akama', 20748),
(@Akama, 4, 0, '%s''s attention shifts to a crack along the temple''s southern wall.', 16, 0, 100, 0, 0, 0, 'Akama', 20749),
(@Akama, 5, 0, 'We must carry on with or without Maiev. Inside! Quickly!', 12, 0, 100, 0, 0, 0, 'Akama', 20750),
(@Xiri, 0, 0, '%s falls silent and a quiet tension falls over nearby Sha''tar forces as Xi''ri makes his decision.', 16, 0, 100, 0, 0, 0, 'Xiri', 20737),
(@Xiri, 1, 0, '%s begins channeling the powers of the light.', 16, 0, 100, 0, 0, 0, 'Xiri', 20693);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8650 AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `OptionBroadcastTextID`) VALUES 
(8650,0,0, 'I am ready to join you for the battle, Xi''ri.',1,1,0,0,0,0, '', 21003);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@ID,0,0,9,10985,0,0,0,'','Show gossip menu if player accept the quest A distraction for Akama');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Akama AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Akama*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Maiev AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Maiev*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100+2 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Ashtongue AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Vagath AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lightsworn AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Magister AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Xiri, 0, 0, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - ActionList'),
(@Xiri*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Close gossip'),
(@Xiri*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Remove npcflag'),
(@Xiri*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Talk'),
(@Xiri*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Talk'),
(@Xiri*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 39828, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Cast'),
(@Xiri*100, 9, 5, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Summon Group'),
(@Xiri*100, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Caalen, 60, 0, 0, 0, 0, 0, 'Caalen - On Gossip use - Talk'),
(@Xiri*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @FyraDawnstar, 60, 0, 0, 0, 0, 0, 'Caalen - On Gossip use - Talk'),
(@Xiri*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 39831, 0, 0, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 'Xiri - ActionList - Cast'),
(@Xiri*100, 9, 9, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Add npcflag'),
(@Akama, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Akama, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Gossip use - Start Waypoint'),
(@Ashtongue, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Ashtongue, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue - On Gossip use - Start Waypoint'),
(@Maiev, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Maiev, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue - On Gossip use - Start Waypoint'),
(@Xiri, 0, 1, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100+1, 2, 0, 0, 0, 0, 11, @Lightsworn, 80, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri*100+1, 9, 0, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 53, 1, @Lightsworn, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri, 0, 2, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100+2, 2, 0, 0, 0, 0, 11, @Magister, 80, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri*100+2, 9, 0, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 53, 1, @Magister, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Maiev, 0, 1, 0, 40, 0, 100, 0, 1, 0, 0, 0, 80, @Maiev*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On waypoint1 - Start Script'),
(@Maiev*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Vagath, 80, 0, 0, 0, 0, 0, 'Vagath - On Script - Talk1'),
(@Maiev*100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Script - Talk1'),
(@Maiev*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Talk1'),
(@Maiev*100, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Script - Talk2'),
(@Maiev*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Talk2'),
(@Maiev*100, 9, 5, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Set React Passive'),
(@Maiev*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Set Immune To NPC'),
(@Maiev*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - evade'),
(@Maiev*100, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 34189, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Stealth'),
(@Vagath, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 14000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On aggro - Talk2'),
(@Vagath, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 2, 14000, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Vagath death - Talk3'),
(@Akama, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, @Akama*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint2 - Start Script'),
(@Akama*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 12000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - pause Waypoint'),
(@Akama*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk4'),
(@Akama*100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk5'),
(@Akama*100, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk6'),
(@Ashtongue, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 54, 23000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint2 - event'),
(@Akama, 0, 2, 0, 40, 0, 100, 0, 6, 0, 0, 0, 11, 39932, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint3 - Cast Spell'),
(@Akama, 0, 3, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, @ChainLightning, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Maiev, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 3000, 3000, 11, @FanOfBlades, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Maiev - IC - Cast Spell'),
(@Magister, 0, 0, 0, 75, 0, 100, 0, 0, @IllidariRavag, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariRavag, 10, 0, 0, 0, 0, 0, 'Magister - On los ooc - Attack'),
(@Lightsworn, 0, 0, 0, 75, 0, 100, 0, 0, @IllidariRavag, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariRavag, 10, 0, 0, 0, 0, 0, 'Lightsworn - On los ooc - Attacka'), 
(@Magister, 0, 1, 0, 75, 0, 100, 0, 0, @IllidariShadow, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariShadow, 10, 0, 0, 0, 0, 0, 'Magister - On los ooc - Attack'),
(@Lightsworn, 0, 1, 0, 75, 0, 100, 0, 0, @IllidariShadow, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariShadow, 10, 0, 0, 0, 0, 0, 'Lightsworn - On los ooc - Attacka'),
(@Magister, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 33632, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 10000, 10000, 11, 13005, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 4, 0, 0, 0, 100, 0, 3000, 8000, 5000, 8000, 11, 13952, 0, 0, 0, 0, 0, 26, 10, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell');

DELETE FROM `waypoints` WHERE entry in (@Akama, @Maiev, @Ashtongue, @Lightsworn, @Magister);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Akama,1,-3562.123291, 486.208344, 22.091547,'Akama1'),
(@Akama,2,-3569.400879, 408.074738, 29.698217,'Akama2'),  
(@Akama,3,-3578.632568, 353.128601, 35.888973,'Ashtongue3'),
(@Akama,4,-3600.931885, 322.053955, 39.085770,'Ashtongue3'),
(@Akama,5,-3617.203125, 320.658691, 39.697262,'Ashtongue3'),
(@Akama,6,-3651.692627, 317.280975, 35.914421,'Akama3'),
(@Maiev,1,-3567.418457, 485.073334, 22.376778,'Maiev1'),
(@Maiev,2,-3567.913086, 400.602386, 30.253670,'Maiev2'), 
(@Maiev,3,-3567.458740, 371.282898, 32.955494,'Maiev3'),
(@Maiev,4,-3651.692627, 317.280975, 35.914421,'Maiev4'),
(@Lightsworn,1,-3562.123291, 486.208344, 22.091547,'Lightsworn1'),
(@Lightsworn,2,-3569.400879, 408.074738, 29.698217,'Lightsworn2'),
(@Magister,1,-3562.123291, 486.208344, 22.091547,'Magister1'),
(@Magister,2,-3569.400879, 408.074738, 29.698217,'Magister2'),
(@Ashtongue,1,-3562.123291, 486.208344, 22.091547,'Ashtongue1'),
(@Ashtongue,2,-3569.400879, 408.074738, 29.698217,'Ashtongue2'),
(@Ashtongue,3,-3578.632568, 353.128601, 35.888973,'Ashtongue3'),
(@Ashtongue,4,-3600.931885, 322.053955, 39.085770,'Ashtongue3'),
(@Ashtongue,5,-3617.203125, 320.658691, 39.697262,'Ashtongue3'),   
(@Ashtongue,6,-3651.692627, 317.280975, 35.914421,'Ashtongue3');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39831;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 39831, 0, 31, 3, @Ashtongue, 0, 0, '', NULL),
(13, 3, 39831, 1, 31, 3, @Akama, 0, 0, '', NULL),
(13, 3, 39831, 2, 31, 3, @Maiev, 0, 0, '', NULL),
(13, 3, 39831, 3, 31, 3, @Lightsworn, 0, 0, '', NULL),
(13, 3, 39831, 4, 31, 3, @Magister, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39832;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 39832, 0, 31, 3, @Ashtongue, 0, 0, '', NULL),
(13, 3, 39832, 1, 31, 3, @Akama, 0, 0, '', NULL),
(13, 3, 39832, 2, 31, 3, @Maiev, 0, 0, '', NULL),
(13, 3, 39832, 3, 31, 3, @Lightsworn, 0, 0, '', NULL),
(13, 3, 39832, 4, 31, 3, @Magister, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39932;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 39932, 0, 8, 13429 , 0, 0, 0, '', 'Eye of the Witness Distraction for Akama');
--
DELETE FROM `gossip_menu` WHERE `entry`=9821 AND `text_id`=13557; 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9821,13557);
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=9977;

DELETE FROM `gossip_menu` WHERE `entry`=4841 AND `text_id`=5894;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4841,5894);
UPDATE `creature_template` SET `gossip_menu_id`=4841 WHERE `entry`=12997;

DELETE FROM `gossip_menu` WHERE `entry`=4845 AND `text_id`=5920;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4845,5920);
UPDATE `creature_template` SET `gossip_menu_id`=4845 WHERE `entry`=13018;

DELETE FROM `gossip_menu` WHERE `entry`=10631 AND `text_id`=14724;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10631,14724);
UPDATE `creature_template` SET `gossip_menu_id`=10631 WHERE `entry`=35073;

DELETE FROM `gossip_menu` WHERE `entry`=3501 AND `text_id`=4253; 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3501,4253);
UPDATE `creature_template` SET `gossip_menu_id`=3501 WHERE `entry`=1694;

UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=13076;

DELETE FROM `gossip_menu` WHERE `entry`=9027 AND `text_id` IN (12198); 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9027,12198);
--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9900,0,0,0,9,0,13010,0,0,0,0,'','Show gossip if player has quest completed'),
(15,9900,0,0,0,5,0,1119,240,0,0,0,'','Show gossip if player is at least friendly');
--
Update `smart_scripts` SET `action_type`=85, `target_type`=7 WHERE `entryorguid`= 3177300 AND `source_type`=9 AND `id`=0;
Update `smart_scripts` SET `action_type`=85, `target_type`=7 WHERE `entryorguid`= 3244200 AND `source_type`=9 AND `id`=0;
--
UPDATE `smart_scripts` SET `action_type`=85 WHERE `entryorguid`=28298 AND `source_type`=0 AND `id` =0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry`=13308;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 13308, 0, 0, 8, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Rewarded or'),
(20, 0, 13308, 0, 0, 8, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Rewarded or'),
(19, 0, 13308, 0, 1, 9, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Taken or'),
(20, 0, 13308, 0, 1, 9, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Taken or'),
(19, 0, 13308, 0, 2, 28, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Complete or'),
(20, 0, 13308, 0, 2, 28, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Complete or'),
(19, 0, 13308, 0, 3, 8, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Rewarded or'),
(20, 0, 13308, 0, 3, 8, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Rewarded or'),
(19, 0, 13308, 0, 4, 9, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Taken or'),
(20, 0, 13308, 0, 4, 9, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Taken or'),
(19, 0, 13308, 0, 5, 28, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Complete or'),
(20, 0, 13308, 0, 5, 28, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Complete or');
--
UPDATE `gameobject` SET `position_z`=402.410004 WHERE `guid`=99956;
--
UPDATE `creature_template` SET `faction`=2007 WHERE `entry` IN (35496,35498);
UPDATE `creature` SET `position_x`=5957.267, `position_y`=566.4926 WHERE `guid`=116668 AND `id` = 29657;
--
UPDATE `quest_template` SET `FlagsEx`=2 WHERE  `Id`=1560;
--
SET @Geant:=24385;
SET @Megalithe:=24381; 

UPDATE `event_scripts` SET `x`=2406.492188 , `y`=-5738.995605, `z`=274.020172 , `o`=0.703918 WHERE `id`=15939;
UPDATE `creature_template` SET `unit_flags`=33600, `AIName`='SmartAI' WHERE `entry` IN (@Geant,@Megalithe);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Geant,@Megalithe);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@Geant*100,@Megalithe*100);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Megalithe, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Megalithe*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - On Just summoned - action list'),
(@Megalithe*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2410.138184, -5727.264648, 270.985870, 4.287692, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2414.860596, -5729.499512, 272.095459, 3.982957, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2417.339844, -5733.230957, 273.028992, 3.603609, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2419.397705, -5738.032227, 274.121246, 3.241538, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 80, @Geant*100, 0, 0, 0, 0, 0, 11, @Geant, 30, 0, 0, 0, 0, 0, 'Megalithe - action liste - Action List'),
(@Megalithe*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43693, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Cast Credit Quest'),
(@Megalithe*100, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Geant*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geant - action liste - Run off'),
(@Geant*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2515.453369, -5670.358398, 298.778076, 0.618311, 'Geant - action liste - Gotopos'), 
(@Geant*100, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geant - action liste - Despawnn');

DELETE FROM `creature_text` WHERE `entry` IN (@Megalithe);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Megalithe, 0, 0, 'Arise from the earth, my brothers!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23311),
(@Megalithe, 1, 0, 'Our iron masters have a mission for us!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23312),
(@Megalithe, 2, 0, 'Follow me into the mountains to carry out the plan of the masters!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23315),
(@Megalithe, 3, 0, 'We will not fail!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23332);
--
DELETE FROM `smart_scripts` WHERE `entryorguid`=20234 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20234,0,3,0,19,0,100,0,10344,0,0,0,11,35237,0,0,0,0,0,7,0,0,0,0,0,0,0,"Runetog Wildhammer - On Quest accept - Cast spell");
--
DELETE FROM `smart_scripts` WHERE `entryorguid`= 39712 AND `source_type`=0 AND `id` IN (6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39712, 0, 6, 7, 63, 0, 100, 0, 0, 0, 0, 0, 11, 74206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Tinker Mekkatorque - Just created - cast spell'),
(39712, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 44816, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Tinker Mekkatorque - Just created - cast spell');
--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (4331, 4329);
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4328 AND `source_type`=0 AND `id` IN (3);
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4331 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4329 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4328, 0, 3, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scalebane - On spell hit  - Despawn'),
(4331, 0, 0, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - On spell hit  - Despawn'),
(4331, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 6000, 8000, 11, 11969, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - Icc  - Cast Fire Nova'),
(4331, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 18968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - On aggr  - cast Fire Shield'),
(4329, 0, 0, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scout - On spell hit  - Despawn'),
(4329, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 18968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scout - On aggr  - cast Fire Shield');
-- Add missing gossip for entry 7766
DELETE FROM `gossip_menu` WHERE `entry`=1761;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1761,2393),(1761,2394);
UPDATE `creature_template` SET `gossip_menu_id`=1761 WHERE entry=7766;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1761,2394,0,9,434,0,0,0,0,'','Show gossip menu text if quest 434 is taken');
--
UPDATE creature_template SET InhabitType=4, unit_flags=64 WHERE Entry=17592;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17592 AND `source_type`=0 AND `id`IN(5, 6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17592, 0, 5, 6, 40, 0, 100, 0, 10, 17592, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Waypoint 10 Reached - Set Home Position'),
(17592, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Waypoint 10 Reached - Set Agressive'),
(17592, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Respawn - Add unit_flag');
-- Anton waypoints

DELETE FROM `creature_addon` WHERE `guid`=117689;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(117689, 1176890, 0, 131072, 1, 0, "");
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=117689;
DELETE FROM `waypoint_data` WHERE `id`=1176890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1176890, 1, 153.249817, -4549.366211, 261.364685, 0, 0, 0, 0, 100, 0),
(1176890, 2, 156.098114, -4532.821289, 258.803101, 0, 0, 0, 0, 100, 0),
(1176890, 3, 156.068008, -4517.755371, 257.193939, 0, 0, 0, 0, 100, 0),
(1176890, 4, 144.178497, -4462.812500, 253.617325, 0, 0, 0, 0, 100, 0),
(1176890, 5, 141.329361, -4455.471191, 253.578766, 0, 0, 0, 0, 100, 0),
(1176890, 6, 125.436966, -4434.860840, 254.323639, 0, 0, 0, 0, 100, 0),
(1176890, 7, 122.155800, -4418.455566, 255.509537, 0, 0, 0, 0, 100, 0),
(1176890, 8, 121.316132, -4389.046387, 257.141205, 0, 0, 0, 0, 100, 0),
(1176890, 9, 124.869438, -4371.796875, 258.335938, 0, 0, 0, 0, 100, 0),
(1176890, 10, 128.642212, -4362.238281, 258.747375, 0, 0, 0, 0, 100, 0),
(1176890, 11, 141.832169, -4345.334473, 257.867676, 0, 0, 0, 0, 100, 0),
(1176890, 12, 150.246857, -4335.993652, 257.498810, 0, 0, 0, 0, 100, 0),
(1176890, 13, 160.376022, -4316.970703, 256.535919, 0, 0, 0, 0, 100, 0),
(1176890, 14, 168.596313, -4308.797363, 254.645386, 0, 0, 0, 0, 100, 0),
(1176890, 15, 178.860077, -4304.438477, 252.472916, 0, 0, 0, 0, 100, 0),
(1176890, 16, 195.836517, -4286.464355, 248.749603, 0, 0, 0, 0, 100, 0),
(1176890, 17, 213.626450, -4276.384766, 248.502441, 0, 0, 0, 0, 100, 0),
(1176890, 18, 238.895004, -4276.655762, 248.606018, 0, 0, 0, 0, 100, 0),
(1176890, 19, 245.764877, -4272.171387, 248.920975, 0, 0, 0, 0, 100, 0),
(1176890, 20, 264.235840, -4250.840332, 250.916733, 0, 0, 0, 0, 100, 0),
(1176890, 21, 282.604492, -4236.683594, 252.033737, 0, 0, 0, 0, 100, 0),
(1176890, 22, 288.971344, -4223.116211, 252.916443, 0, 0, 0, 0, 100, 0),
(1176890, 23, 291.303375, -4196.310547, 254.307571, 0, 0, 0, 0, 100, 0),
(1176890, 24, 294.156342, -4189.324707, 254.992859, 0, 0, 0, 0, 100, 0),
(1176890, 25, 291.303375, -4196.310547, 254.307571, 0, 0, 0, 0, 100, 0),
(1176890, 26, 288.971344, -4223.116211, 252.916443, 0, 0, 0, 0, 100, 0),
(1176890, 27, 282.604492, -4236.683594, 252.033737, 0, 0, 0, 0, 100, 0),
(1176890, 28, 264.235840, -4250.840332, 250.916733, 0, 0, 0, 0, 100, 0),
(1176890, 29, 245.764877, -4272.171387, 248.920975, 0, 0, 0, 0, 100, 0),
(1176890, 30, 238.895004, -4276.655762, 248.606018, 0, 0, 0, 0, 100, 0),
(1176890, 31, 213.626450, -4276.384766, 248.502441, 0, 0, 0, 0, 100, 0),
(1176890, 32, 195.836517, -4286.464355, 248.749603, 0, 0, 0, 0, 100, 0),
(1176890, 33, 178.860077, -4304.438477, 252.472916, 0, 0, 0, 0, 100, 0),
(1176890, 34, 168.596313, -4308.797363, 254.645386, 0, 0, 0, 0, 100, 0),
(1176890, 35, 160.376022, -4316.970703, 256.535919, 0, 0, 0, 0, 100, 0),
(1176890, 36, 150.246857, -4335.993652, 257.498810, 0, 0, 0, 0, 100, 0),
(1176890, 37, 141.832169, -4345.334473, 257.867676, 0, 0, 0, 0, 100, 0),
(1176890, 38, 128.642212, -4362.238281, 258.747375, 0, 0, 0, 0, 100, 0),
(1176890, 39, 124.869438, -4371.796875, 258.335938, 0, 0, 0, 0, 100, 0),
(1176890, 40, 121.316132, -4389.046387, 257.141205, 0, 0, 0, 0, 100, 0),
(1176890, 41, 122.155800, -4418.455566, 255.509537, 0, 0, 0, 0, 100, 0),
(1176890, 42, 125.436966, -4434.860840, 254.323639, 0, 0, 0, 0, 100, 0),
(1176890, 43, 141.329361, -4455.471191, 253.578766, 0, 0, 0, 0, 100, 0),
(1176890, 44, 144.178497, -4462.812500, 253.617325, 0, 0, 0, 0, 100, 0),
(1176890, 45, 156.068008, -4517.755371, 257.193939, 0, 0, 0, 0, 100, 0),
(1176890, 46, 156.098114, -4532.821289, 258.803101, 0, 0, 0, 0, 100, 0),
(1176890, 47, 153.249817, -4549.366211, 261.364685, 0, 0, 0, 0, 100, 0);
-- 
-- William Pestle SAI
SET @ENTRY := 253;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,112,0,0,0,80,@ENTRY*100+00,0,2,0,0,0,1,0,0,0,0,0,0,0,"William Pestle - On Quest 'Collecting Kelp' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 25300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Pestle - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.45219,"William Pestle - On Script - Set Orientation 1,45219"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,5,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Pestle - On Script - Play Emote 69"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,21,10,0,0,0,0,0,0,"William Pestle - On Script - Set Orientation Closest Player"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Pestle - On Script - Say Line 1");

-- Maybell Maclure SAI
SET @ENTRY := 251;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,114,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Maybell Maclure - On Quest 'The Escape' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 25100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.39307,"On Script - Set Orientation 5,39307"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 7"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=251;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(251, 0, 0, 'Here goes nothing...', 12, 0, 100, 0, 0, 0, 1862, 0, 'Maybell Maclure');
-- 
-- Tortured Skeleton SAI
SET @ENTRY := 18797;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Skeleton - On Aggro - Remove Flag Standstate Dead");
-- Dread Tactician
-- Pathing for  Entry: 16959 'TDB FORMAT' 
SET @NPC := 59170;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-306.8688,`position_y`=1556.233,`position_z`=41.73843 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-306.8688,1556.233,41.73843,0,0,0,0,100,0),
(@PATH,2,-303.8688,1555.983,40.73843,0,0,0,0,100,0),
(@PATH,3,-299.8688,1555.483,40.23843,0,0,0,0,100,0),
(@PATH,4,-297.8688,1555.233,39.48843,0,0,0,0,100,0),
(@PATH,5,-295.1188,1554.983,38.73843,0,0,0,0,100,0),
(@PATH,6,-292.1188,1554.483,38.48843,0,0,0,0,100,0),
(@PATH,7,-289.1188,1554.233,37.73843,0,0,0,0,100,0),
(@PATH,8,-287.1188,1553.983,37.23843,0,0,0,0,100,0),
(@PATH,9,-284.1188,1553.983,36.48843,0,0,0,0,100,0),
(@PATH,10,-283.8904,1553.79,36.20832,0,0,0,0,100,0),
(@PATH,11,-281.8904,1553.54,35.95832,0,0,0,0,100,0),
(@PATH,12,-275.6404,1556.04,35.70832,0,0,0,0,100,0),
(@PATH,13,-269.0029,1558.513,35.23201,0,0,0,0,100,0),
(@PATH,14,-270.5029,1562.263,35.98201,0,0,0,0,100,0),
(@PATH,15,-271.7529,1565.013,36.48201,0,0,0,0,100,0),
(@PATH,16,-272.7529,1567.513,36.98201,0,0,0,0,100,0),
(@PATH,17,-274.0029,1570.263,37.73201,0,0,0,0,100,0),
(@PATH,18,-275.0029,1573.013,38.48201,0,0,0,0,100,0),
(@PATH,19,-276.4716,1576.198,39.42199,0,0,0,0,100,0),
(@PATH,20,-278.2216,1576.948,39.92199,0,0,0,0,100,0),
(@PATH,21,-280.9716,1578.448,40.92199,0,0,0,0,100,0),
(@PATH,22,-283.7216,1579.698,41.67199,0,0,0,0,100,0),
(@PATH,23,-285.4716,1580.448,42.17199,0,0,0,0,100,0),
(@PATH,24,-287.9716,1581.698,42.92199,0,0,0,0,100,0),
(@PATH,25,-289.7216,1582.448,43.67199,0,0,0,0,100,0),
(@PATH,26,-291.4716,1583.448,44.42199,0,0,0,0,100,0),
(@PATH,27,-294.2216,1584.698,45.17199,0,0,0,0,100,0),
(@PATH,28,-294.3971,1584.785,45.42167,0,0,0,0,100,0),
(@PATH,29,-295.1471,1585.035,45.42167,0,0,0,0,100,0),
(@PATH,30,-304.3971,1576.535,45.92167,0,0,0,0,100,0),
(@PATH,31,-312.2731,1568.967,46.45709,0,0,0,0,100,0),
(@PATH,32,-318.7731,1561.467,45.70709,0,0,0,0,100,0),
(@PATH,33,-333.8887,1543.732,45.3224,0,0,0,0,100,0),
(@PATH,34,-333.6387,1540.732,44.5724,0,0,0,0,100,0),
(@PATH,35,-333.3887,1538.732,43.8224,0,0,0,0,100,0),
(@PATH,36,-333.3887,1536.732,43.3224,0,0,0,0,100,0),
(@PATH,37,-333.1387,1533.732,42.5724,0,0,0,0,100,0),
(@PATH,38,-332.8887,1531.732,41.8224,0,0,0,0,100,0),
(@PATH,39,-332.8887,1529.732,41.0724,0,0,0,0,100,0),
(@PATH,40,-332.6387,1527.732,40.5724,0,0,0,0,100,0),
(@PATH,41,-332.3887,1525.732,39.8224,0,0,0,0,100,0),
(@PATH,42,-332.3887,1523.732,39.3224,0,0,0,0,100,0),
(@PATH,43,-332.1387,1521.982,38.8224,0,0,0,0,100,0),
(@PATH,44,-331.8887,1518.982,38.3224,0,0,0,0,100,0),
(@PATH,45,-331.8887,1516.982,37.5724,0,0,0,0,100,0),
(@PATH,46,-331.8887,1513.982,36.8224,0,0,0,0,100,0),
(@PATH,47,-331.6387,1510.982,36.3224,0,0,0,0,100,0),
(@PATH,48,-331.3887,1508.232,35.5724,0,0,0,0,100,0),
(@PATH,49,-331.1387,1505.232,34.8224,0,0,0,0,100,0),
(@PATH,50,-330.8887,1502.232,34.3224,0,0,0,0,100,0),
(@PATH,51,-330.4729,1499.82,33.45189,0,0,0,0,100,0),
(@PATH,52,-325.4729,1496.82,32.70189,0,0,0,0,100,0),
(@PATH,53,-320.9729,1494.32,31.95189,0,0,0,0,100,0),
(@PATH,54,-316.2229,1491.57,31.45189,0,0,0,0,100,0),
(@PATH,55,-311.7229,1489.07,30.95189,0,0,0,0,100,0),
(@PATH,56,-307.4729,1486.57,30.20189,0,0,0,0,100,0),
(@PATH,57,-307.3154,1486.395,29.88731,0,0,0,0,100,0),
(@PATH,58,-305.8154,1485.645,29.63731,0,0,0,0,100,0),
(@PATH,59,-299.8154,1485.645,28.88731,0,0,0,0,100,0),
(@PATH,60,-294.0654,1485.395,28.38731,0,0,0,0,100,0),
(@PATH,61,-287.0654,1485.395,27.88731,0,0,0,0,100,0),
(@PATH,62,-281.0654,1485.395,27.38731,0,0,0,0,100,0),
(@PATH,63,-280.6106,1485.449,27.23963,0,0,0,0,100,0),
(@PATH,64,-278.6106,1485.199,27.23963,0,0,0,0,100,0),
(@PATH,65,-270.6106,1498.699,27.48963,0,0,0,0,100,0),
(@PATH,66,-268.6106,1502.199,27.98963,0,0,0,0,100,0),
(@PATH,67,-268.5272,1502.318,28.20654,0,0,0,0,100,0),
(@PATH,68,-267.5272,1503.818,28.20654,0,0,0,0,100,0),
(@PATH,69,-270.5272,1504.568,28.70654,0,0,0,0,100,0),
(@PATH,70,-274.2772,1505.568,29.20654,0,0,0,0,100,0),
(@PATH,71,-278.5582,1506.635,29.73862,0,0,0,0,100,0),
(@PATH,72,-290.8082,1500.885,30.23862,0,0,0,0,100,0),
(@PATH,73,-296.4533,1498.203,30.9129,0,0,0,0,100,0),
(@PATH,74,-300.2033,1498.953,31.4129,0,0,0,0,100,0),
(@PATH,75,-304.2033,1499.703,31.9129,0,0,0,0,100,0),
(@PATH,76,-307.9533,1500.453,32.4129,0,0,0,0,100,0),
(@PATH,77,-313.7033,1501.203,33.1629,0,0,0,0,100,0),
(@PATH,78,-317.4067,1502.011,33.47455,0,0,0,0,100,0),
(@PATH,79,-319.6567,1504.011,33.97455,0,0,0,0,100,0),
(@PATH,80,-322.1567,1506.511,34.47455,0,0,0,0,100,0),
(@PATH,81,-325.2614,1509.541,35.46749,0,0,0,0,100,0),
(@PATH,82,-325.7614,1512.541,35.96749,0,0,0,0,100,0),
(@PATH,83,-326.0114,1515.541,36.71749,0,0,0,0,100,0),
(@PATH,84,-326.2614,1517.541,37.21749,0,0,0,0,100,0),
(@PATH,85,-326.2614,1520.541,38.21749,0,0,0,0,100,0),
(@PATH,86,-326.5114,1522.541,38.71749,0,0,0,0,100,0),
(@PATH,87,-326.7614,1525.291,39.46749,0,0,0,0,100,0),
(@PATH,88,-327.0114,1527.291,39.96749,0,0,0,0,100,0),
(@PATH,89,-327.2614,1529.291,40.71749,0,0,0,0,100,0),
(@PATH,90,-327.7614,1533.291,41.46749,0,0,0,0,100,0),
(@PATH,91,-328.0114,1535.041,41.96749,0,0,0,0,100,0),
(@PATH,92,-328.2614,1538.041,42.71749,0,0,0,0,100,0);
-- 0x1C39AC4240108FC00000210000037184 .go -306.8688 1556.233 41.73843


-- Pathing for  Entry: 16959 'TDB FORMAT' 
SET @NPC := 59171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-110.5204,`position_y`=1566.893,`position_z`=42.31397 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-110.5204,1566.893,42.31397,0,0,0,0,100,0),
(@PATH,2,-120.2704,1568.393,41.81397,0,0,0,0,100,0),
(@PATH,3,-127.0204,1569.893,41.31397,0,0,0,0,100,0),
(@PATH,4,-134.6927,1571.43,40.71382,0,0,0,0,100,0),
(@PATH,5,-139.6927,1571.68,40.21382,0,0,0,0,100,0),
(@PATH,6,-144.6927,1571.93,39.46382,0,0,0,0,100,0),
(@PATH,7,-149.4427,1572.18,38.71382,0,0,0,0,100,0),
(@PATH,8,-152.4427,1572.43,38.21382,0,0,0,0,100,0),
(@PATH,9,-155.4427,1572.68,37.71382,0,0,0,0,100,0),
(@PATH,10,-158.4427,1572.68,36.96382,0,0,0,0,100,0),
(@PATH,11,-161.4427,1572.93,36.46382,0,0,0,0,100,0),
(@PATH,12,-163.4427,1573.18,35.71382,0,0,0,0,100,0),
(@PATH,13,-163.4854,1573.449,35.89986,0,0,0,0,100,0),
(@PATH,14,-164.2354,1573.449,35.64986,0,0,0,0,100,0),
(@PATH,15,-163.9854,1576.449,36.39986,0,0,0,0,100,0),
(@PATH,16,-163.7824,1580.185,36.84877,0,0,0,0,100,0),
(@PATH,17,-161.7824,1580.435,37.59877,0,0,0,0,100,0),
(@PATH,18,-159.0324,1580.935,38.34877,0,0,0,0,100,0),
(@PATH,19,-155.0324,1581.935,38.84877,0,0,0,0,100,0),
(@PATH,20,-152.2824,1582.685,39.59877,0,0,0,0,100,0),
(@PATH,21,-148.5324,1583.435,40.34877,0,0,0,0,100,0),
(@PATH,22,-145.5324,1584.185,41.09877,0,0,0,0,100,0),
(@PATH,23,-145.3761,1584.15,41.32778,0,0,0,0,100,0),
(@PATH,24,-144.1261,1584.4,41.57778,0,0,0,0,100,0),
(@PATH,25,-139.1261,1583.9,42.32778,0,0,0,0,100,0),
(@PATH,26,-135.1261,1583.65,43.07778,0,0,0,0,100,0),
(@PATH,27,-130.1261,1583.15,43.57778,0,0,0,0,100,0),
(@PATH,28,-126.3761,1582.65,44.07778,0,0,0,0,100,0),
(@PATH,29,-123.3761,1582.4,44.82778,0,0,0,0,100,0),
(@PATH,30,-117.3761,1582.15,45.32778,0,0,0,0,100,0),
(@PATH,31,-113.3761,1581.65,46.07778,0,0,0,0,100,0),
(@PATH,32,-109.0603,1580.944,46.36949,0,0,0,0,100,0),
(@PATH,33,-84.0918,1569.51,46.44577,0,0,0,0,100,0),
(@PATH,34,-82.3418,1566.01,45.44577,0,0,0,0,100,0),
(@PATH,35,-81.3418,1564.26,44.94577,0,0,0,0,100,0),
(@PATH,36,-80.0918,1561.51,44.19577,0,0,0,0,100,0),
(@PATH,37,-79.0918,1559.76,43.69577,0,0,0,0,100,0),
(@PATH,38,-78.0918,1558.01,42.94577,0,0,0,0,100,0),
(@PATH,39,-76.5918,1554.76,42.19577,0,0,0,0,100,0),
(@PATH,40,-75.8418,1553.01,41.69577,0,0,0,0,100,0),
(@PATH,41,-74.8418,1551.26,41.19577,0,0,0,0,100,0),
(@PATH,42,-73.3418,1548.51,40.44577,0,0,0,0,100,0),
(@PATH,43,-72.5918,1546.76,39.94577,0,0,0,0,100,0),
(@PATH,44,-71.5918,1545.01,39.19577,0,0,0,0,100,0),
(@PATH,45,-70.3418,1542.26,38.69577,0,0,0,0,100,0),
(@PATH,46,-70.29829,1541.94,38.42153,0,0,0,0,100,0),
(@PATH,47,-69.29829,1540.19,37.67153,0,0,0,0,100,0),
(@PATH,48,-69.54829,1538.19,37.17153,0,0,0,0,100,0),
(@PATH,49,-70.04829,1535.19,36.17153,0,0,0,0,100,0),
(@PATH,50,-70.04829,1533.44,35.67153,0,0,0,0,100,0),
(@PATH,51,-70.54829,1529.44,35.17153,0,0,0,0,100,0),
(@PATH,52,-71.04829,1525.69,34.42153,0,0,0,0,100,0),
(@PATH,53,-71.54829,1521.69,33.92153,0,0,0,0,100,0),
(@PATH,54,-71.54829,1518.69,33.17153,0,0,0,0,100,0),
(@PATH,55,-72.10271,1515.561,32.53027,0,0,0,0,100,0),
(@PATH,56,-73.35271,1512.811,31.53027,0,0,0,0,100,0),
(@PATH,57,-74.35271,1511.061,30.78027,0,0,0,0,100,0),
(@PATH,58,-75.10271,1509.311,30.28027,0,0,0,0,100,0),
(@PATH,59,-76.35271,1506.561,29.78027,0,0,0,0,100,0),
(@PATH,60,-78.10271,1502.811,29.03027,0,0,0,0,100,0),
(@PATH,61,-79.10271,1500.311,30.03027,0,0,0,0,100,0),
(@PATH,62,-82.35271,1493.061,29.28027,0,0,0,0,100,0),
(@PATH,63,-84.10271,1489.561,28.53027,0,0,0,0,100,0),
(@PATH,64,-84.42598,1489.16,28.3833,0,0,0,0,100,0),
(@PATH,65,-85.17598,1487.41,28.1333,0,0,0,0,100,0),
(@PATH,66,-102.3677,1477.751,27.65215,0,0,0,0,100,0),
(@PATH,67,-123.1177,1477.501,26.90215,0,0,0,0,100,0),
(@PATH,68,-137.5984,1477.31,26.80837,0,0,0,0,100,0),
(@PATH,69,-145.5984,1482.56,27.05837,0,0,0,0,100,0),
(@PATH,70,-153.8199,1488.331,27.38618,0,0,0,0,100,0),
(@PATH,71,-178.7361,1511.036,27.3082,0,0,0,0,100,0),
(@PATH,72,-185.2269,1510.27,27.05297,0,0,0,0,100,0),
(@PATH,73,-182.9769,1508.27,27.05297,0,0,0,0,100,0),
(@PATH,74,-172.9769,1500.02,26.80297,0,0,0,0,100,0),
(@PATH,75,-170.7269,1498.27,27.05297,0,0,0,0,100,0),
(@PATH,76,-169.2269,1496.02,27.05297,0,0,0,0,100,0),
(@PATH,77,-167.7269,1494.02,26.80297,0,0,0,0,100,0),
(@PATH,78,-167.7269,1492.02,26.80297,0,0,0,0,100,0),
(@PATH,79,-167.7269,1489.77,26.80297,0,0,0,0,100,0),
(@PATH,80,-167.4919,1489.571,26.64043,0,0,0,0,100,0),
(@PATH,81,-168.4919,1488.071,26.64043,0,0,0,0,100,0),
(@PATH,82,-158.2419,1482.071,26.14043,0,0,0,0,100,0),
(@PATH,83,-147.591,1475.386,26.25293,0,0,0,0,100,0),
(@PATH,84,-139.841,1477.636,27.00293,0,0,0,0,100,0),
(@PATH,85,-132.341,1479.636,27.25293,0,0,0,0,100,0),
(@PATH,86,-125.591,1481.386,28.00293,0,0,0,0,100,0),
(@PATH,87,-121.841,1482.636,28.50293,0,0,0,0,100,0),
(@PATH,88,-120.2695,1483.081,29.04744,0,0,0,0,100,0),
(@PATH,89,-118.5195,1484.081,29.54744,0,0,0,0,100,0),
(@PATH,90,-115.7695,1485.331,30.29744,0,0,0,0,100,0),
(@PATH,91,-115.0195,1485.831,31.04744,0,0,0,0,100,0),
(@PATH,92,-113.0195,1486.831,32.04744,0,0,0,0,100,0),
(@PATH,93,-107.0195,1489.581,31.29744,0,0,0,0,100,0),
(@PATH,94,-95.5195,1495.331,30.79744,0,0,0,0,100,0),
(@PATH,95,-95.16714,1495.663,31.08524,0,0,0,0,100,0),
(@PATH,96,-94.66714,1495.913,31.08524,0,0,0,0,100,0),
(@PATH,97,-93.66714,1499.913,31.33524,0,0,0,0,100,0),
(@PATH,98,-92.16714,1506.413,31.83524,0,0,0,0,100,0),
(@PATH,99,-90.66714,1512.163,32.58524,0,0,0,0,100,0),
(@PATH,100,-89.91714,1514.913,31.83524,0,0,0,0,100,0),
(@PATH,101,-89.75613,1515.401,32.07003,0,0,0,0,100,0),
(@PATH,102,-89.25613,1516.401,31.82003,0,0,0,0,100,0),
(@PATH,103,-89.25613,1523.401,32.57003,0,0,0,0,100,0),
(@PATH,104,-89.25613,1524.401,33.32003,0,0,0,0,100,0),
(@PATH,105,-89.25613,1525.401,34.07003,0,0,0,0,100,0),
(@PATH,106,-89.00613,1526.401,34.57003,0,0,0,0,100,0),
(@PATH,107,-89.00613,1528.401,35.82003,0,0,0,0,100,0),
(@PATH,108,-89.00613,1529.401,36.07003,0,0,0,0,100,0),
(@PATH,109,-88.75613,1533.151,36.82003,0,0,0,0,100,0),
(@PATH,110,-88.75613,1535.151,37.32003,0,0,0,0,100,0),
(@PATH,111,-88.50613,1538.151,38.07003,0,0,0,0,100,0),
(@PATH,112,-88.50613,1541.151,38.82003,0,0,0,0,100,0),
(@PATH,113,-88.25613,1544.151,39.57003,0,0,0,0,100,0),
(@PATH,114,-88.1545,1544.429,39.72079,0,0,0,0,100,0),
(@PATH,115,-88.1545,1545.429,39.97079,0,0,0,0,100,0),
(@PATH,116,-91.1545,1548.179,40.47079,0,0,0,0,100,0),
(@PATH,117,-94.6545,1551.679,40.97079,0,0,0,0,100,0),
(@PATH,118,-99.4045,1556.429,41.72079,0,0,0,0,100,0),
(@PATH,119,-110.481,1566.873,42.2832,0,0,0,0,100,0),
(@PATH,120,-120.231,1568.623,41.7832,0,0,0,0,100,0),
(@PATH,121,-126.981,1569.873,41.2832,0,0,0,0,100,0);
-- 0x1C39AC4240108FC000002100007FC923 .go -110.5204 1566.893 42.31397
-- 
-- Portal Burn Action
-- Portal Kruul SAI
SET @ENTRY := 184289;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,50,183816,30,0,0,0,0,8,0,0,0,147.0184, 1717.341, 37.46404,0,"Portal Kruul - On Gameobject State Changed - Summon Gameobject 'Hellfire Fire'");

-- Portal Xilus SAI
SET @ENTRY := 184290;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,50,183816,30,0,0,0,0,8,0,0,0,-84.5415, 1881.739, 73.82645,5.782852,"Portal Xilus - On Gameobject State Changed - Summon Gameobject 'Hellfire Fire'");

-- Portal Grimh SAI
SET @ENTRY := 184414;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,50,183816,30,0,0,0,0,8,0,0,0,-418.627, 1847.49, 80.7808,0,"Portal Grimh - On Gameobject State Changed - Summon Gameobject 'Hellfire Fire'");

-- Portal Kaalez SAI
SET @ENTRY := 184415;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,50,183816,30,0,0,0,0,8,0,0,0,-545.2587, 1781.167, 56.22634,0,"Portal Kaalez - On Gameobject State Changed - Summon Gameobject 'Hellfire Fire'");
-- 
-- Pathing for  Entry: 22410 'TDB FORMAT' 
SET @NPC := 78754;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3009.127,`position_y`=5920.842,`position_z`=130.9854 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14332,0,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3009.127,5920.842,130.9854,0,0,1,0,100,0),
(@PATH,2,3018.56,5944.067,131.0012,0,0,1,0,100,0),
(@PATH,3,3028.687,5971.723,131.0047,0,0,1,0,100,0),
(@PATH,4,3039.209,5998.325,130.9491,0,0,1,0,100,0),
(@PATH,5,3041.459,6004.325,130.9491,0,0,1,0,100,0),
(@PATH,6,3042.709,6007.575,130.9491,0,0,1,0,100,0),
(@PATH,7,3043.459,6009.825,130.9491,0,0,1,0,100,0),
(@PATH,8,3048.21,6021.786,130.8358,0,0,1,0,100,0),
(@PATH,9,3058.211,6046.689,130.7168,0,0,1,0,100,0),
(@PATH,10,3065.155,6064.995,130.614,0,0,1,0,100,0),
(@PATH,11,3078.91,6073.112,130.3709,0,0,1,0,100,0),
(@PATH,12,3084.571,6056.194,130.4195,0,0,1,0,100,0),
(@PATH,13,3079.821,6040.444,130.6695,0,0,1,0,100,0),
(@PATH,14,3079.655,6040.126,130.764,0,0,1,0,100,0),
(@PATH,15,3079.405,6039.626,130.764,0,0,1,0,100,0),
(@PATH,16,3078.905,6038.126,130.764,0,0,1,0,100,0),
(@PATH,17,3069.25,6014.667,130.9082,0,0,1,0,100,0),
(@PATH,18,3064,6000.667,130.9082,0,0,1,0,100,0),
(@PATH,19,3060.452,5991.971,130.99,0,0,1,0,100,0),
(@PATH,20,3050.27,5967.535,130.9908,0,0,1,0,100,0),
(@PATH,21,3045.52,5954.535,130.9908,0,0,1,0,100,0),
(@PATH,22,3039.294,5938.282,130.9514,0,0,1,0,100,0),
(@PATH,23,3028.456,5913.517,130.8795,0,0,1,0,100,0),
(@PATH,24,3019.764,5891.665,130.7868,0,0,1,0,100,0),
(@PATH,25,3016.764,5884.415,130.7868,0,0,1,0,100,0),
(@PATH,26,3012.264,5873.915,130.7868,0,0,1,0,100,0),
(@PATH,27,3009.264,5866.915,130.7868,0,0,1,0,100,0),
(@PATH,28,3012.196,5873.788,130.7515,0,0,1,0,100,0),
(@PATH,29,3008.946,5866.788,130.7515,0,0,1,0,100,0),
(@PATH,30,3008.446,5865.038,130.7515,0,0,1,0,100,0),
(@PATH,31,2995.446,5836.038,130.5015,0,0,1,0,100,0),
(@PATH,32,2995.104,5835.657,130.3808,0,0,1,0,100,0),
(@PATH,33,2991.854,5828.407,130.6308,0,0,1,0,100,0),
(@PATH,34,2990.604,5827.907,130.3808,0,0,1,0,100,0),
(@PATH,35,2976.186,5821.571,130.1743,0,0,1,0,100,0),
(@PATH,36,2970.518,5837.316,130.481,0,0,1,0,100,0),
(@PATH,37,2971.768,5840.066,130.481,0,0,1,0,100,0),
(@PATH,38,2980.487,5859.262,131.0515,0,0,1,0,100,0),
(@PATH,39,2983.987,5866.762,131.0515,0,0,1,0,100,0),
(@PATH,40,2989.237,5876.512,131.3015,0,0,1,0,100,0);
-- 0x1C3998424015E28000002300007FC920 .go 3009.127 5920.842 130.9854

DELETE FROM `creature_formations` WHERE `leaderGUID`=78754;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(78754, 78754, 0, 0, 2, 0, 0),
(78754, 78755, 7, 0, 0, 0, 0);

-- Expedition Warden SAI
SET @GUID := -63549;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17855;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,100,200,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Warden - Out of Combat - Play Emote 1");

-- Expedition Warden SAI
SET @GUID := -63548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17855;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,100,200,10000,40000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Warden - Out of Combat - Play Emote 1");

-- Pathing for  Entry: 17855 'TDB FORMAT' 
SET @NPC := 63550;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3022.651,`position_y`=5963.609,`position_z`=130.7766 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3022.651,5963.609,130.7766,0,6000,0,0,100,0),
(@PATH,2,3032.096,5959.558,130.6869,0,6000,0,0,100,0);
-- 0x1C39984240116FC000002300027FC920 .go 3022.651 5963.609 130.7766
-- 
-- Pathing for  Entry: 2802 'TDB FORMAT' 
SET @NPC := 38101;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1442.487,`position_y`=36.32697,`position_z`=-62.02626 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1442.487,36.32697,-62.02626,0,0,0,0,100,0),
(@PATH,2,1435.487,32.07697,-62.02626,0,0,0,0,100,0),
(@PATH,3,1416.445,21.46703,-62.02588,0,0,0,0,100,0),
(@PATH,4,1405.551,23.91475,-62.0261,0,0,0,0,100,0),
(@PATH,5,1402.301,26.41475,-62.0261,0,0,0,0,100,0),
(@PATH,6,1387.127,36.88569,-62.02647,0,0,0,0,100,0),
(@PATH,7,1381.627,49.88569,-62.02647,0,0,0,0,100,0),
(@PATH,8,1379.005,56.32278,-62.02669,0,0,0,0,100,0),
(@PATH,9,1379.755,60.82278,-62.02669,0,0,0,0,100,0),
(@PATH,10,1383.399,83.51677,-62.03289,0,0,0,0,100,0),
(@PATH,11,1388.399,87.51677,-62.03289,0,0,0,0,100,0),
(@PATH,12,1395.899,94.01677,-62.28289,0,0,0,0,100,0),
(@PATH,13,1400.163,97.49232,-62.05746,0,0,0,0,100,0),
(@PATH,14,1412.663,127.9923,-62.05746,0,0,0,0,100,0),
(@PATH,15,1413.663,130.2423,-62.05746,0,0,0,0,100,0),
(@PATH,16,1415.163,134.2423,-62.05746,0,0,0,0,100,0),
(@PATH,17,1418.154,141.2391,-62.04066,0,0,0,0,100,0),
(@PATH,18,1423.404,143.7391,-62.04066,0,0,0,0,100,0),
(@PATH,19,1434.169,149.9652,-62.03992,0,0,0,0,100,0),
(@PATH,20,1435.669,148.4652,-62.03992,0,0,0,0,100,0),
(@PATH,21,1445.419,139.4652,-62.03992,0,0,0,0,100,0),
(@PATH,22,1447.836,137.2073,-61.75176,0,0,0,0,100,0),
(@PATH,23,1450.836,133.7073,-61.75176,0,0,0,0,100,0),
(@PATH,24,1452.086,132.4573,-61.75176,0,0,0,0,100,0),
(@PATH,25,1453.836,130.4573,-60.00176,0,0,0,0,100,0),
(@PATH,26,1456.336,127.4573,-60.00176,0,0,0,0,100,0),
(@PATH,27,1462.008,120.8724,-59.94119,0,0,0,0,100,0),
(@PATH,28,1465.152,111.2505,-59.94151,0,0,0,0,100,0),
(@PATH,29,1471.402,105.7505,-59.94151,0,0,0,0,100,0),
(@PATH,30,1479.847,98.11646,-59.9706,0,0,0,0,100,0),
(@PATH,31,1480.847,97.36646,-59.9706,0,0,0,0,100,0),
(@PATH,32,1482.847,96.11646,-61.4706,0,0,0,0,100,0),
(@PATH,33,1484.347,95.11646,-61.7206,0,0,0,0,100,0),
(@PATH,34,1483.158,95.78064,-61.62843,0,0,0,0,100,0),
(@PATH,35,1484.658,94.78064,-61.87843,0,0,0,0,100,0),
(@PATH,36,1485.158,94.53064,-61.87843,0,0,0,0,100,0),
(@PATH,37,1489.658,90.78064,-61.87843,0,0,0,0,100,0),
(@PATH,38,1499.658,82.28064,-61.87843,0,0,0,0,100,0),
(@PATH,39,1499.686,82.06802,-62.047,0,0,0,0,100,0),
(@PATH,40,1500.436,81.31802,-62.047,0,0,0,0,100,0),
(@PATH,41,1494.936,71.31802,-62.047,0,0,0,0,100,0),
(@PATH,42,1481.826,47.66472,-62.03592,0,0,0,0,100,0),
(@PATH,43,1469.576,44.16472,-62.03592,0,0,0,0,100,0),
(@PATH,44,1466.576,43.41472,-62.03592,0,0,0,0,100,0),
(@PATH,45,1464.826,42.91472,-62.03592,0,0,0,0,100,0),
(@PATH,46,1452.326,39.16472,-62.03592,0,0,0,0,100,0),
(@PATH,47,1442.51,36.29097,-62.02619,0,0,0,0,100,0),
(@PATH,48,1435.51,32.29097,-62.02619,0,0,0,0,100,0),
(@PATH,49,1416.5,21.42531,-62.02593,0,0,0,0,100,0);
-- 0x1C191C000002BC80000028000002D330 .go 1442.487 36.32697 -62.02626
-- 
DELETE FROM `gossip_menu` WHERE `entry`=5004;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (5004, 6062);
-- 
-- Scarlet Initiate SAI
SET @ENTRY := 1507;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,7,0,0,0,100,0,0,0,3500,5000,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Initiate - In Combat - Cast 'Fireball'"),
(@ENTRY,0,10,0,23,0,100,0,12544,0,5000,10000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Initiate - On Has Aura 'Frost Armor' - Cast 'Frost Armor'");
-- Portal Kruul SAI
SET @ENTRY := 184289;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,11,34386,0,0,0,0,0,19,19652,10,0,0,0,0,0,"Portal Kruul - On Gameobject State Changed - Cast spell 'Hellfire Fire'");
-- Portal Xilus SAI
SET @ENTRY := 184290;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,11,34386,0,0,0,0,0,19,19717,10,0,0,0,0,0,"Portal Xilus - On Gameobject State Changed - Cast spell 'Hellfire Fire'");
-- Portal Grimh SAI
SET @ENTRY := 184414;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,11,34386,0,0,0,0,0,19,19652,10,0,0,0,0,0,"Portal Grimh - On Gameobject State Changed - Cast spell 'Hellfire Fire'");
-- Portal Kaalez SAI
SET @ENTRY := 184415;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,11,34386,0,0,0,0,0,19,19717,10,0,0,0,0,0,"Portal Kaalez - On Gameobject State Changed - Cast spell 'Hellfire Fire'");
-- Azure Spellweaver SAI
SET @ENTRY := 31403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellweaver - Combat CMC - Cast 'Arcane Missiles'");

-- Gatekeeper Melindra SAI
SET @ENTRY := 32373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,19000,25000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - In Combat - Cast 'Amplify Damage'");

-- Syreian the Bonecarver SAI
SET @ENTRY := 32438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,4,0,100,1,0,0,0,0,11,38952,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - On Aggro CMC - Cast 'Frost Arrow' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2300,3900,2300,3900,11,50092,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,11000,14000,11,38952,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - In Combat - Cast 'Frost Arrow'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,12000,16000,11,47168,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Within 0-5 Range - Cast 'Improved Wing Clip'");

-- Unbound Seer SAI
SET @ENTRY := 33422;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,38204,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Seer - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,15000,11,58667,33,0,0,0,0,5,0,0,0,0,0,0,0,"Unbound Seer - In Combat - Cast 'Ley Curse'");

-- Mistcaller Yngvar SAI
SET @ENTRY := 34965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,45658,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Out of Combat - Cast 'Call of the Mist'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mistcaller Yngvar - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12000,17000,11,49816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mistcaller Yngvar - Combat - Cast 'Mist of Strangulation'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,120000,120000,11,49871,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - 0-30% Health - Cast 'Rune of Retribution'");

-- Drottinn Hrothgar SAI
SET @ENTRY := 34980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,66625,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out of Combat - Cast 'Cloud Aura' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out of Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drottinn Hrothgar - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,3,0,0,0,100,0,12000,16000,15000,21000,11,67038,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - In Combat - Cast 'Smash'");

-- Ornolf the Scarred SAI
SET @ENTRY := 35012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - Within 0-5 Range - Cast 'Chop'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,8000,11000,11,67037,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - Combat - Cast 'Whirlwind'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,40000,40000,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - 0-30% Health - Cast 'Frenzy'");

-- Kul the Reckless SAI
SET @ENTRY := 34956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,66531,0,0,0,80,3495600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kul the Reckless - On Spellhit 'Open Black Cage' - Run Script");

-- Kvaldir Harpooner SAI
SET @ENTRY := 34907;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,66489,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Harpooner - Combat CMC - Cast 'Spear Throw'");

-- Deep Jormungar SAI
SET @ENTRY := 34920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out of Combat - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out of Combat - Set Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 'Submerge' (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Cast 'Stand' (No Repeat)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,7,0,0,0,100,0,1000,1000,3000,5000,11,61597,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat CMC - Cast 'Acid Spit'"),
(@ENTRY,0,8,0,0,0,100,0,11000,16000,15000,20000,11,61598,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 'Sweep'"),
(@ENTRY,0,9,0,0,0,100,0,10000,20000,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 'Bore'"),
(@ENTRY,0,10,11,9,0,100,1,30,60,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 30-60 Range - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 30-60 Range - Cast 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,12,13,9,0,100,1,0,8,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Aura 'Submerge' (No Repeat)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Aura 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Cast 'Stand' (No Repeat)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,17,18,7,0,100,1,0,0,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set All Threat 0-100 (No Repeat)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Flags Not Attackable & Not Selectable (No Repeat)");
-- Gnarlhide SAI
SET @ENTRY := 30003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,38391,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlhide - Combat CMC - Cast 'Scorch'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,20000,25000,11,60290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Blast Wave'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,19000,24000,11,35250,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Dragon's Breath'"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,9000,12000,11,20832,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Fire Blast'");

-- Yulda the Stormspeaker SAI
SET @ENTRY := 30046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,32018,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Combat CMC - Cast 'Call Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,15000,18000,11,55087,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Combat - Cast 'Typhoon'");

-- Sigrid Iceborn SAI
SET @ENTRY := 30086;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sigrid Iceborn - Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sigrid Iceborn - Combat - Cast 'Impale'"),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,"Sigrid Iceborn - Target Casting - Cast 'Disengage'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Out of Combat - Cast 'Frostbite Weapon'"),
(@ENTRY,0,4,5,62,0,100,0,9870,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Set Invincibility Hp 1"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Remove Flags Immune To Players & Immune To NPC's"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Say Line 0"),
(@ENTRY,0,9,10,2,0,100,0,0,1,0,0,33,30086,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Quest Credit 'Eliminate the Competition'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Set Faction 0"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Say Line 1"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Evade");

-- Twilight Worshipper SAI
SET @ENTRY := 30111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worshipper - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,8000,11,61567,64,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat CMC - Cast 'Fireball' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,14000,17000,11,56858,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,14000,17000,11,61568,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat - Cast 'Flamestrike' (Heroic Dungeon)");

-- Onu'zun SAI
SET @ENTRY := 30180;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onu'zun - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,14500,17800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onu'zun - Combat - Cast 'Cone of Cold'"),
(@ENTRY,0,3,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,"Onu'zun - Target Casting - Cast 'Counterspell'"),
(@ENTRY,0,4,5,62,0,100,0,9878,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Set Invincibility Hp 1"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Remove Flags Immune To Players & Immune To NPC's"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Say Line 0"),
(@ENTRY,0,9,10,2,0,100,0,0,1,0,0,33,30180,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Quest Credit 'Eliminate the Competition'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Set Faction 0"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Evade");

-- Sunreaver Scout SAI
SET @ENTRY := 30233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Within 5-30 Range - Cast 'Multi-Shot'");

-- Silver Covenant Scout SAI
SET @ENTRY := 30238;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Within 5-30 Range - Cast 'Multi-Shot'");

-- Silver Covenant Horseman SAI
SET @ENTRY := 30263;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Within 5-30 Range - Cast 'Multi-Shot'");

-- Sunreaver Hawkrider SAI
SET @ENTRY := 30265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Within 5-30 Range - Cast 'Multi-Shot'");

-- Ahn'kahar Spell Flinger SAI
SET @ENTRY := 30278;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,23000,27000,11,56698,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Blast' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,23000,27000,11,59102,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Blast' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,14000,13000,16000,11,56702,65,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Sickle' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,10000,14000,13000,16000,11,59103,65,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Sickle' (Heroic Dungeon)");

-- Eye of Taldaram SAI
SET @ENTRY := 30285;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,17439,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat CMC - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,17289,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat CMC - Cast 'Shadow Shock' (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,56730,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - Target Casting - Cast 'Dark Counterspell' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,100,5,0,0,0,0,11,59111,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - Target Casting - Cast 'Dark Counterspell' (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,15000,19000,23000,27000,11,56728,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat - Cast 'Eyes in the Dark' (Dungeon)"),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,11,56733,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Just Died - Cast 'Shadowfury' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,5,0,0,0,0,11,61463,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Just Died - Cast 'Shadowfury' (No Repeat) (Heroic Dungeon)");

-- Frostbringer SAI
SET @ENTRY := 30286;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,57825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,61461,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,18000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,15000,18000,11,61462,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Combat - Cast 'Frost Nova' (Heroic Dungeon)"),
(@ENTRY,0,4,0,2,0,100,6,0,30,120000,130000,11,56716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - 0-30% Health - Cast 'Icy Winds' (Dungeon)");

-- Stormforged Amplifier SAI
SET @ENTRY := 30591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Amplifier - Combat CMC - Cast 'Lightning Bolt'");

-- Veteran Mage Hunter SAI
SET @ENTRY := 30665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Out of Combat - Cast 'Destroy Door Seal' (Dungeon)"),
(@ENTRY,0,1,0,4,0,100,6,0,0,0,0,30,1,2,3,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Aggro - Set Random Phase(1, 2, 3) (Dungeon)"),
(@ENTRY,0,2,0,0,1,100,2,0,0,2400,3800,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Frostbolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,1,100,4,0,0,2400,3800,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Frostbolt' (Phase 1) (Heroic Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Fireball' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,5,0,9,2,100,4,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Fireball' (Phase 2) (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,4,100,2,0,0,2400,3800,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Arcane Bolt' (Phase 3) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,4,100,4,0,0,2400,3800,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Arcane Bolt' (Phase 3) (Heroic Dungeon)"),
(@ENTRY,0,8,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)");

-- Portal Keeper SAI
SET @ENTRY := 30695;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,6000,8000,11,58531,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,6000,8000,11,61593,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Missiles' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,8,13000,19000,11,58532,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - 0-8 Range - Cast 'Frostbolt Volley' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,8,13000,19000,11,61594,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - 0-8 Range - Cast 'Frostbolt Volley' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,0,8,9000,14000,11,58534,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - Combat - Cast 'Deep Freeze' (Dungeon)");

-- Nesingwary Game Warden SAI
SET @ENTRY := 30737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,8000,10000,11,31942,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nesingwary Game Warden - 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,3,0,9,0,100,0,0,45,7000,9000,11,23337,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nesingwary Game Warden - 0-45 Range - Cast 'Shoot'");

-- Unbound Dryad SAI
SET @ENTRY := 30860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,55217,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - Combat CMC - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,13000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - In Combat - Cast 'Strike'");

-- Shandaral Hunter Spirit SAI
SET @ENTRY := 30864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,9000,14000,11,54615,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat - Cast 'Aimed Shot'"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,15000,22000,11,47168,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat - Cast 'Improved Wing Clip'");

-- Unbound Corrupter SAI
SET @ENTRY := 30868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,5400,11,38204,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,20000,30000,45000,60000,11,58667,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - Combat - Cast 'Ley Curse'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,30000,35000,11,58270,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - 0-30% Health - Cast 'Transferred Power'");

-- Portal Keeper SAI
SET @ENTRY := 30893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,45,6000,8000,11,58536,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,45,6000,8000,11,61591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Volley' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,45,13000,19000,11,58535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - 0-45 Range - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,45,13000,19000,11,61590,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - 0-45 Range - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,0,8,9000,14000,11,58537,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - Combat - Cast 'Polymorph' (Dungeon)");

-- Azure Binder SAI
SET @ENTRY := 31007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4800,11,58456,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - Combat CMC - Cast 'Arcane Barrage' (Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,8,9000,15000,11,58455,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - 0-8 Range - Cast 'Arcane Explosion' (Normal Dungeon)"),
(@ENTRY,0,2,0,9,0,100,4,0,8,9000,15000,11,59257,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - 0-8 Range - Cast 'Arcane Blast' (Heroic Dungeon)");
-- Spirit of Koosu SAI
SET @ENTRY := 29034;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,21971,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit of Koosu - Combat CMC - Cast 'Poison Bolt'");

-- Anub'ar Necromancer SAI
SET @ENTRY := 29064;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,4000,6000,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,14000,17000,23000,27000,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat - Cast 'Animate Bones' (Dungeon)");

-- Anub'ar Necromancer SAI
SET @ENTRY := 29098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,4000,6000,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,14000,17000,23000,27000,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat - Cast 'Animate Bones' (Dungeon)");


-- Anub'ar Prime Guard SAI
SET @ENTRY := 29128;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,10000,13000,11,54309,64,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Combat CMC - Cast 'Mark of Darkness' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,10000,13000,11,59352,64,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Combat CMC - Cast 'Mark of Darkness' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,7,0,5,0,0,11,54314,33,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - 0-5 Range - Cast 'Drain Power' (No Repeat) (Dungeon)");


-- Lost Drakkari Spirit SAI
SET @ENTRY := 29129;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,17327,0,2000,2000,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Drakkari Spirit - On Has Aura 'Spirit Particles' - Cast 'Spirit Particles'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,1500,1500,11,37361,65,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Drakkari Spirit - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,10000,16000,15000,18000,11,24050,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Drakkari Spirit - In Combat - Cast 'Spirit Burst'");

-- Onslaught Harbor Guard SAI
SET @ENTRY := 29330;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Harbor Guard - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,12000,14000,11,50750,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Harbor Guard - Combat - Cast 'Raven Heal'");

-- Sifreldar Runekeeper SAI
SET @ENTRY := 29331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,15000,22000,11,52714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - 0-30% Health - Cast 'Revitalizing Rune' (No Repeat)");

-- Onslaught Raven Bishop SAI
SET @ENTRY := 29338;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Bishop - Combat CMC - Cast 'Raven Flock'"),
(@ENTRY,0,1,0,2,0,100,1,10,50,2000,8000,11,50750,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Bishop - 10-50% Health - Cast 'Raven Heal'  (No Repeat)");

-- Savage Hill Scavenger SAI
SET @ENTRY := 29404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,8000,11,50403,64,0,0,0,0,5,0,0,0,0,0,0,0,"Savage Hill Scavenger - Combat CMC - Cast 'Bone Toss'");

-- Savage Hill Mystic SAI
SET @ENTRY := 29622;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4400,5800,11,50273,64,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Hill Mystic - Combat CMC - Cast 'Arcane Barrage'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - 0-15% Health - Flee For Assist");

-- Stormforged Tracker SAI
SET @ENTRY := 29652;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Tracker - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,12000,11,46982,1,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Tracker - Combat - Cast 'Lightning Gun Shot'");

-- Spitting Cobra SAI
SET @ENTRY := 29774;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,12000,15000,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,12000,15000,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,10000,17000,20000,11,55703,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Cobra Strike' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,5000,10000,17000,20000,11,59020,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Cobra Strike' (Heroic Dungeon)");

-- Drakkari God Hunter SAI
SET @ENTRY := 29820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,35946,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,59146,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,12000,15000,11,55624,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Arcane Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,7000,10000,12000,15000,11,58973,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Arcane Shot' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,3000,5000,33000,37000,11,55798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Flare' (Dungeon)"),
(@ENTRY,0,5,0,0,0,100,6,18000,21000,19000,23000,11,55625,0,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Tranquillizing Shot' (Dungeon)"),
(@ENTRY,0,6,0,2,0,100,6,0,30,12000,15000,11,31567,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - 0-30% Health - Cast 'Deterrence' (Dungeon)");

-- Drakkari Fire Weaver SAI
SET @ENTRY := 29822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,8000,9000,11,55659,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Lava Burst' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,8000,9000,11,58972,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Lava Burst' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,12000,15000,11,55613,65,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Flame Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,10000,14000,11,58971,65,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Flame Shock' (Heroic Dungeon)"),
(@ENTRY,0,4,0,9,0,100,6,0,5,10000,16000,11,61362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - 0-5 Range - Cast 'Blast Wave' (Dungeon)");

-- Drakkari Battle Rider SAI
SET @ENTRY := 29836;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,55348,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,58966,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat CMC - Cast 'Throw' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,16000,22000,11,55521,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat - Cast 'Poisoned Spear' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,12000,15000,16000,22000,11,58967,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat - Cast 'Poisoned Spear' (Heroic Dungeon)");

-- Mildred the Cruel SAI
SET @ENTRY := 29885;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,30,3400,4800,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mildred the Cruel - Combat CMC - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,12000,15000,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mildred the Cruel - Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,2,0,100,0,0,15,10000,15000,11,47697,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mildred the Cruel - 0-15% Health - Cast 'Shadow Word: Death'");

-- K3 Bruiser SAI
SET @ENTRY := 29910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Within 0-20 Range - Cast 'Net' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Combat CMC - Cast 'Shoot'");

-- Earthen Stoneguard SAI
SET @ENTRY := 29960;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Within 0-20 Range - Cast 'Net' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Combat CMC - Cast 'Shoot'");

-- Iron Dwarf Magus SAI
SET @ENTRY := 29979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,30,3400,4800,11,12058,64,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Dwarf Magus - Combat CMC - Cast 'Chain Lightning'");
-- Wastes Scavenger SAI
SET @ENTRY := 28005;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,5000,11,50403,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Scavenger - Combat CMC - Cast 'Bone Toss'"),
(@ENTRY,0,1,0,8,0,100,0,50430,0,0,0,80,2800500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - On spellhit Devour Ghoul - Run script");

-- Emperor Cobra SAI
SET @ENTRY := 28011;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,32093,32,0,0,0,0,2,0,0,0,0,0,0,0,"Emperor Cobra - Combat CMC - Cast 'Poison Spit'");

-- Rainspeaker Oracle SAI
SET @ENTRY := 28025;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,6000,8000,11,15305,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rainspeaker Oracle - Combat CMC - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,12000,15000,11,54919,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rainspeaker Oracle - Combat - Cast 'Warped Armor'");

-- Frenzyheart Tracker SAI
SET @ENTRY := 28077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Set Orientation"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Say Line 1"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Despawn After 8 seconds"),
(@ENTRY,0,3,0,0,0,100,0,0,0,3000,5000,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Tracker - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,4,0,0,0,100,0,10000,14000,60000,65000,11,53432,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Combat - Cast 'Bear Trap'");

-- Frenzyheart Hunter SAI
SET @ENTRY := 28079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Hunter - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,12000,15000,11,52270,1,0,0,0,0,5,0,0,0,0,0,0,0,"Frenzyheart Hunter - Combat - Cast 'Multi-Shot'");

-- Frenzyheart Scavenger SAI
SET @ENTRY := 28081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,54617,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Combat CMC - Cast 'Throw Spear'");

-- Sparktouched Oracle SAI
SET @ENTRY := 28112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,54916,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Combat CMC - Cast 'Lightning Burst'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,9000,12000,11,12549,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Within 0-30 Range - Cast 'Forked Lightning'");

-- Don Carlos SAI
SET @ENTRY := 28132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,50736,1,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Out of Combat - Cast 'Summon Guerrero' (No Repeat) (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,0,0,2300,5000,11,16496,64,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9000,14000,22000,26000,11,12024,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 'Net' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,9000,14000,22000,26000,11,50762,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 'Net' (Heroic Dungeon)");

-- Snowflake SAI
SET @ENTRY := 28153;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,50721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,59280,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,7,5000,9000,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - In Combat - Cast 'Enchantment of Spell Haste' (No Repeat) (Dungeon)");

-- Dark Necromancer SAI
SET @ENTRY := 28200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,61558,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,21000,25000,11,20812,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Cripple' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,7000,11000,21000,25000,11,52498,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Cripple' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,14000,18000,15000,21000,11,58772,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Drain Mana' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,14000,18000,15000,21000,11,58770,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Drain Mana' (Heroic Dungeon)");

-- Drakkari Water Binder SAI
SET @ENTRY := 28303;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,16000,25000,30000,11,54399,1,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - Combat - Cast 'Water Bubble'");

-- Ymirjar Necromancer SAI
SET @ENTRY := 28368;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,51432,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,59254,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,18000,22000,11,49205,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat - Cast 'Shadow Bolt Volley' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,14000,18000,22000,11,59255,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat - Cast 'Shadow Bolt Volley' (Heroic Dungeon)");

-- Har'koan Subduer SAI
SET @ENTRY := 28403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,20000,40000,60000,80,2840300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koan Subduer - Out of Combat - Run Script"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2800,3500,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Har'koan Subduer - Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koan Subduer - 0-15% Health - Flee For Assist (No Repeat)");

-- Dragonflayer Spiritualist SAI
SET @ENTRY := 28410;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2400,3800,11,51587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Combat CMC - Cast 'Lightning Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1500,4000,8000,10000,11,51588,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Combat - Cast 'Flame Shock' (Dungeon)"),
(@ENTRY,0,2,0,14,0,100,6,7000,100,7000,7000,11,51586,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Friendly At 7000 Health - Cast 'Healing Wave' (Dungeon)");

-- Hath'ar Broodmaster SAI
SET @ENTRY := 28412;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hath'ar Broodmaster - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,25000,11,54453,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hath'ar Broodmaster - Combat - Cast 'Web Wrap'");

-- Hemet Nesingwary SAI
SET @ENTRY := 28451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,51742,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - Combat CMC - Cast 'Arcane Shot'");

-- Storming Vortex SAI
SET @ENTRY := 28547;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,53044,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,59169,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Combat CMC - Cast 'Lightning Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,6,0,5,9000,18000,11,60236,0,0,0,0,0,6,0,0,0,0,0,0,0,"Storming Vortex - Within 0-5 Range - Cast 'Cyclone' (Dungeon)");

-- Hardened Steel Skycaller SAI
SET @ENTRY := 28580;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,61515,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,20000,11,52754,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,18000,11,52775,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,9000,12000,15000,20000,11,59148,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Shot' (Heroic Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,7000,12000,12000,18000,11,59147,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Multi-Shot' (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,0,100,6,0,5,6000,9000,11,61507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - 0-5 Range - Cast 'Disengage' (Dungeon)");

-- Titanium Vanguard SAI
SET @ENTRY := 28838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 'Poison Tipped Spear' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,14000,21000,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Within 5-30 Range - Cast 'Poison Tipped Spear' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,5,0,0,0,0,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 'Poison Tipped Spear' (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,5,30,14000,21000,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Within 5-30 Range - Cast 'Poison Tipped Spear' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,7,4000,6000,0,0,11,58619,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 'Charge' (No Repeat) (Dungeon)"),
(@ENTRY,0,5,0,0,0,100,6,12000,15000,12000,15000,11,58619,0,0,0,0,0,6,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 'Charge' (Dungeon)");
-- Prince Raze SAI
SET @ENTRY := 10647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4700,5800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,40,13000,16000,11,16570,1,0,0,0,0,5,0,0,0,0,0,0,0,"Prince Raze - 0-40 Range - Cast 'Charged Arcane Bolt'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,12000,18000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,3,4,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)");

-- Summoned Blackhand Dreadweaver SAI
SET @ENTRY := 10680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out of Combat - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,6400,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,14500,19200,27600,39600,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Combat - Cast 'Veil of Shadow' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out of Combat - Kill Self (No Repeat) (Normal Dungeon)");

-- Duggan Wildhammer SAI
SET @ENTRY := 10817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - 0-15% Health - Flee For Assist");

-- Death-Hunter Hawkspear SAI
SET @ENTRY := 10824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,2300,3900,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,9000,11,11978,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - 0-5 Range - Cast 'Kick'");

-- Deathspeaker Selendre SAI
SET @ENTRY := 10827;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,5000,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,18000,11,12889,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - Combat - Cast 'Curse of Tongues'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,12000,19000,11,17238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - 0-30% Health - Cast 'Drain Life'");

-- Risen Rifleman SAI
SET @ENTRY := 11054;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,17353,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Rifleman - Combat CMC - Cast 'Shoot' (Normal Dungeon)");

-- Ragefire Shaman SAI
SET @ENTRY := 11319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Shaman - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,74,0,100,3,0,40,30000,35000,11,11986,1,0,0,0,0,9,0,0,0,0,0,0,0,"Ragefire Shaman - On Friendly Between 0-40% Health - Cast 'Healing Wave' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Searing Blade Warlock SAI
SET @ENTRY := 11324;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Out of Combat - Cast 'Summon Voidwalker' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,6500,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Warlock - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Gordok Ogre-Mage SAI
SET @ENTRY := 11443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat - Cast 'Bloodlust'"),
(@ENTRY,0,3,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat - Cast 'Bloodlust' (Normal Dungeon)");

-- Gordok Mage-Lord SAI
SET @ENTRY := 11444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Mage-Lord - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,15530,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,14000,12000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Fire Blast' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,17000,19000,25000,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,7000,9000,16000,20000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Polymorph' (Normal Dungeon)"),
(@ENTRY,0,5,6,2,0,100,3,0,30,0,0,11,16170,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Cast 'Bloodlust' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,3,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Say Line 1 (No Repeat) (Normal Dungeon)");

-- Gordok Warlock SAI
SET @ENTRY := 11448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out of Combat - Cast 'Demon Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,3000,3000,0,0,11,22865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out of Combat - Cast 'Summon Doomguard' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,0,0,2400,3800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,9000,15000,26000,30000,11,17883,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Immolate' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,5000,9000,20000,25000,11,13338,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Curse of Tongues' (Normal Dungeon)"),
(@ENTRY,0,6,0,0,0,100,2,7000,15000,20000,26000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Banish' (Normal Dungeon)");

-- Wildspawn Betrayer SAI
SET @ENTRY := 11454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,7800,11400,11,18649,40,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 5-30 Range - Cast 'Shadow Shot' (Normal Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,5,30,9900,13600,11,7896,40,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 5-30 Range - Cast 'Exploding Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,2,0,5,6000,11000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 0-5 Range - Cast 'Knockdown' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Betrayer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Wildspawn Felsworn SAI
SET @ENTRY := 11455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Felsworn - Out of Combat - Cast 'Fear' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,38000,45000,11,22417,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Shadow Shield' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,1,100,2,11000,17000,23000,30000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,6000,10000,10000,15000,11,12542,1,0,0,0,0,5,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Fear' (Normal Dungeon)");

-- Wildspawn Hellcaller SAI
SET @ENTRY := 11457;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Hellcaller - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,14000,18000,25000,11,20754,3,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Hellcaller - Combat - Cast 'Rain of Fire' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Hellcaller - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Highborne Summoner SAI
SET @ENTRY := 11466;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Summoner - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,9000,12000,11,13341,0,0,0,0,0,5,0,0,0,0,0,0,0,"Highborne Summoner - Combat - Cast 'Fire Blast' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,16000,18000,22000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Combat - Cast 'Frost Nova' (Normal Dungeon)");

-- Eldreth Apparition SAI
SET @ENTRY := 11471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,18100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,16799,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,20000,27500,11,22744,1,0,0,0,0,6,0,0,0,0,0,0,0,"Eldreth Apparition - Combat - Cast 'Chains of Ice' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,11000,14000,20000,30000,11,15244,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - Combat - Cast 'Cone of Cold' (Normal Dungeon)");

-- Irondeep Shaman SAI
SET @ENTRY := 11600;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Shaman - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,55000,65000,11,15786,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Combat - Cast 'Earthbind Totem' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,15000,20000,11,12492,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - 0-50% Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Whitewhisker Geomancer SAI
SET @ENTRY := 11604;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,500,1000,600000,600000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Combat - Cast 'Fire Shield' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Morloch SAI
SET @ENTRY := 11657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,120000,130000,11,12741,1,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat - Cast 'Curse of Weakness' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,11000,14000,9000,15000,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat - Cast 'Shadow Bolt Volley' (Normal Dungeon)");

-- Snowblind Windcaller SAI
SET @ENTRY := 11675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Windcaller - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,12000,16000,11,9532,1,0,0,0,0,6,0,0,0,0,0,0,0,"Snowblind Windcaller - Combat - Cast 'Lightning Bolt' (Normal Dungeon)");

-- Horde Scout SAI
SET @ENTRY := 11680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Horde Scout - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,18545,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Within 5-30 Range - Cast 'Scorpid Sting'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Shaman SAI
SET @ENTRY := 11683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - 0-30% Health - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - 0-15% Health - Flee For Assist (No Repeat)");

-- Wildpaw Mystic SAI
SET @ENTRY := 11838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,37361,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,16000,19000,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,12000,16000,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - 0-50% Health - Cast 'Healing Wave' (Normal Dungeon)");

-- Nathanos Blightcaller SAI
SET @ENTRY := 11878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,8000,11000,11,18651,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nathanos Blightcaller - Combat - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7000,9000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - 0-5 Range - Cast 'Backhand'"),
(@ENTRY,0,3,0,15,0,100,1,0,0,10,0,11,13704,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - Friendly Crowd Controlled - Cast 'Psychic Scream'");

-- Lord Vyletongue SAI
SET @ENTRY := 12236;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,2,5,30,7000,9500,11,21390,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,0,0,100,2,20000,30000,20000,30000,11,21655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Combat - Cast 'Blink'"),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,14000,18000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Combat - Cast 'Smoke Bomb'");

-- Quel'Lithien Protector SAI
SET @ENTRY := 12322;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,13000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-5 Range - Cast 'Kick'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-15% Health - Flee For Assist (No Repeat)");

-- Damned Soul SAI
SET @ENTRY := 12378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,7000,9000,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - Combat - Cast 'Arcane Bolt'");

-- Mastok Wrilehiss SAI
SET @ENTRY := 12737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,14000,18000,11,23600,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Combat - Cast 'Piercing Howl'"),
(@ENTRY,0,3,4,2,0,100,0,0,30,120000,130000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-30% Health - Cast 'Enrage'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-30% Health - Say 0");

DELETE FROM `creature_text` WHERE `entry` IN (12737);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`comment`) VALUES
(12737,0,0,'$s becomes enraged!',16,0,100,0,0,0,24144,'Mastok Wrilehiss enrage at 30%');

-- Ashenvale Outrunner SAI
SET @ENTRY := 12856;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Within 5-30 Range - Cast 'Scorpid Sting'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7100,15300,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Within 0-5 Range - Cast 'Snap Kick'");

-- Warsong Scout SAI
SET @ENTRY := 12862;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Runner SAI
SET @ENTRY := 12863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Runner - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Outrider SAI
SET @ENTRY := 12864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Within 5-30 Range - Cast 'Scorpid Sting'");

-- Ambassador Malcin SAI
SET @ENTRY := 12865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,15000,25000,11,8282,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - Combat - Cast 'Curse of Blood'");

-- Silverwing Sentinel SAI
SET @ENTRY := 12896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Sentinel - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - 0-15% Health - Flee For Assist (No Repeat)");

-- Lorgus Jett SAI
SET @ENTRY := 12902;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Out of Combat - Cast 'Lightning Shield' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lorgus Jett - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)");

-- Mounted Ironforge Mountaineer SAI
SET @ENTRY := 12996;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - 0-15% Health - Flee For Assist (No Repeat)");

-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=2983;
-- The Plains Vision SAI
SET @ENTRY := 2983;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,2983,0,0,0,0,1,0,0,0,0,0,0,0,"The Plains Vision - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,50,2983,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Plains Vision - On Waypoint 50 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@ENTRY, 1, -2226.32, -408.095, -9.36235, 'The Plains Vision'), 
(@ENTRY, 2, -2203.04, -437.212, -5.72498, 'The Plains Vision'),  
(@ENTRY, 3, -2163.91, -457.851, -7.09049, 'The Plains Vision'),
(@ENTRY, 4, -2123.87, -448.137, -9.29591, 'The Plains Vision'),    
(@ENTRY, 5, -2104.66, -427.166, -6.49513, 'The Plains Vision'),  
(@ENTRY, 6, -2101.48, -422.826, -5.3567, 'The Plains Vision'),   
(@ENTRY, 7, -2097.56, -417.083, -7.16716, 'The Plains Vision'),   
(@ENTRY, 8, -2084.87, -398.626, -9.88973, 'The Plains Vision'),
(@ENTRY, 9, -2072.71, -382.324, -10.2488, 'The Plains Vision'),  
(@ENTRY, 10, -2054.05, -356.728, -6.22468, 'The Plains Vision'),
(@ENTRY, 11, -2051.8, -353.645, -5.35791, 'The Plains Vision'), 
(@ENTRY, 12, -2049.08, -349.912, -6.15723, 'The Plains Vision'), 
(@ENTRY, 13, -2030.6, -310.724, -9.59302, 'The Plains Vision'),    
(@ENTRY, 14, -2002.15, -249.308, -10.8124, 'The Plains Vision'), 
(@ENTRY, 15, -1972.85, -195.811, -10.6316, 'The Plains Vision'),
(@ENTRY, 16, -1940.93, -147.652, -11.7055, 'The Plains Vision'),
(@ENTRY, 17, -1888.06, -81.943, -11.4404, 'The Plains Vision'), 
(@ENTRY, 18, -1837.05, -34.0109, -12.258, 'The Plains Vision'), 
(@ENTRY, 19, -1796.12, -14.6462, -10.3581, 'The Plains Vision'), 
(@ENTRY, 20, -1732.61, -4.27746, -10.0213, 'The Plains Vision'), 
(@ENTRY, 21, -1688.94, -0.829945, -11.7103, 'The Plains Vision'), 
(@ENTRY, 22, -1681.32, 13.0313, -9.48056, 'The Plains Vision'), 
(@ENTRY, 23, -1677.04, 36.8349, -7.10318, 'The Plains Vision'), 
(@ENTRY, 24, -1675.2, 68.559, -8.95384, 'The Plains Vision'),
(@ENTRY, 25, -1676.57, 89.023, -9.65104, 'The Plains Vision'), 
(@ENTRY, 26, -1678.16, 110.939, -10.1782, 'The Plains Vision'), 
(@ENTRY, 27, -1677.86, 128.681, -5.73869, 'The Plains Vision'), 
(@ENTRY, 28, -1675.27, 144.324, -3.47916, 'The Plains Vision'), 
(@ENTRY, 29, -1671.7, 163.169, -1.23098, 'The Plains Vision'),
(@ENTRY, 30, -1666.61, 181.584, 5.26145, 'The Plains Vision'), 
(@ENTRY, 31, -1661.51, 196.154,  8.95252, 'The Plains Vision'), 
(@ENTRY, 32, -1655.47, 210.811, 8.38727, 'The Plains Vision'), 
(@ENTRY, 33, -1647.07, 226.947, 5.27755, 'The Plains Vision'), 
(@ENTRY, 34, -1621.65, 232.91, 2.69579, 'The Plains Vision'), 
(@ENTRY, 35, -1600.23, 237.641, 2.98539, 'The Plains Vision'),
(@ENTRY, 36, -1576.07, 242.546, 4.66541, 'The Plains Vision'),
(@ENTRY, 37, -1554.57, 248.494, 6.60377, 'The Plains Vision'), 
(@ENTRY, 38, -1547.53, 259.302, 10.6741, 'The Plains Vision'),
(@ENTRY, 39, -1541.7, 269.847, 16.4418, 'The Plains Vision'), 
(@ENTRY, 40, -1539.83, 278.989, 21.0597, 'The Plains Vision'),
(@ENTRY, 41, -1540.16, 290.219, 27.8247, 'The Plains Vision'), 
(@ENTRY, 42, -1538.99, 298.983, 34.0032, 'The Plains Vision'),
(@ENTRY, 43, -1540.38, 307.337, 41.3557, 'The Plains Vision'), 
(@ENTRY, 44, -1536.61, 314.884, 48.0179, 'The Plains Vision'),
(@ENTRY, 45, -1532.42, 323.277, 55.6667, 'The Plains Vision'),
(@ENTRY, 46, -1528.77, 329.774, 61.1525, 'The Plains Vision'), 
(@ENTRY, 47, -1525.65, 333.18, 63.2161, 'The Plains Vision'),  
(@ENTRY, 48, -1517.01, 350.713, 62.4286, 'The Plains Vision'), 
(@ENTRY, 49, -1511.39, 362.537, 62.4539, 'The Plains Vision'), 
(@ENTRY, 50, -1508.68, 366.822, 62.733, 'The Plains Vision');  

-- 
DELETE FROM `creature_addon` WHERE `guid` IN (127436, 127437);
DELETE FROM `linked_respawn` WHERE `guid` IN (127436, 127437);
DELETE FROM `spell_script_names` WHERE  `spell_id`=8283 AND `ScriptName`='spell_snufflenose_command';
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=26206;
