-- Archavon Warder, for some reason Shield Crush doesn't appear in sniffs
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 32353;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32353 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32353,0,0,0,0,0,100,2,20000,20000,20000,20000,0,11,60897,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Shield Crush' (Normal Dungeon)"),
(32353,0,1,0,0,0,100,4,20000,20000,20000,20000,0,11,60899,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Shield Crush' (Heroic Dungeon)"),
(32353,0,2,0,0,0,100,2,11000,13000,15000,15000,0,11,60902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Whirl' (Normal Dungeon)"),
(32353,0,3,0,0,0,100,4,11000,13000,15000,15000,0,11,60916,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Whirl' (Heroic Dungeon)"),
(32353,0,4,0,0,0,100,2,15000,19000,25000,30000,0,11,60919,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Rock Shower' (Normal Dungeon)"),
(32353,0,5,0,0,0,100,4,15000,19000,25000,30000,0,11,60923,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Archavon Warder - In Combat - Cast 'Rock Shower' (Heroic Dungeon)");

-- Flame Warder (https://youtu.be/8hpdbio-n-Y?t=56)
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 35143;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35143 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35143,0,0,0,0,0,100,2,10000,15000,35000,35000,0,11,66808,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flame Warder - In Combat - Cast 'Meteor Fists' (Normal Dungeon)"),
(35143,0,1,0,0,0,100,4,10000,15000,35000,35000,0,11,68160,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flame Warder - In Combat - Cast 'Meteor Fists' (Heroic Dungeon)"),
(35143,0,2,0,0,0,100,2,5000,5000,15000,15000,0,11,66813,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Flame Warder - In Combat - Cast 'Lava Burst' (Normal Dungeon)"),
(35143,0,3,0,0,0,100,4,5000,5000,15000,15000,0,11,67330,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Flame Warder - In Combat - Cast 'Lava Burst' (Heroic Dungeon)");

-- Frost Warder (3.3.5 Sniffs Normal & Heroic)
UPDATE `creature_template_addon` SET `auras` = "72122" WHERE `entry` = 38482;
UPDATE `creature_template_addon` SET `auras` = "71993" WHERE `entry` = 38483;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 38482;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38482 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38482,0,0,0,0,0,100,2,5000,5000,5000,9000,0,11,72123,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Frost Warder - In Combat - Cast 'Frost Blast' (Normal Dungeon)"),
(38482,0,1,0,0,0,100,4,5000,5000,5000,9000,0,11,72124,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Frost Warder - In Combat - Cast 'Frost Blast' (Heroic Dungeon)");

-- Tempest Warder (https://youtu.be/8hpdbio-n-Y?t=454)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 34015;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34015 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34015,0,0,0,0,0,100,0,5000,8000,4000,7000,0,11,64363,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Tempest Warder - In Combat - Cast 'Shock'"),
(34015,0,1,2,2,0,100,1,0,40,0,0,0,11,64379,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tempest Warder - Between 0-40% Health - Cast 'Overcharge' (No Repeat)"),
(34015,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tempest Warder - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 34015;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(34015,0,0,"%s crackles and surges with raw energy!",41,0,100,0,0,0,34085,0,"Tempest Warder");

-- Add waypoints from sniffs
DELETE FROM `creature_addon` WHERE `guid` IN (202595,202598);
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES
(202595,2025950),
(202598,2025980);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (202595,202598);

DELETE FROM `waypoint_data` WHERE `id` IN (2025950,2025980);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(2025950, 1, -218.85168, -200.84744, 97.592926),
(2025950, 2, -218.84631, -185.63348, 97.592926),
(2025950, 3, -218.7963, -176.4833, 97.592926),
(2025950, 4, -218.86719, -166.53061, 97.592926),
(2025950, 5, -218.83926, -153.72055, 101.95123),
(2025950, 6, -218.86719, -166.53061, 97.592926),
(2025950, 7, -218.7963, -176.4833, 97.592926),
(2025950, 8, -218.84631, -185.63348, 97.592926),
(2025950, 9, -218.85168, -200.84744, 97.592926),
(2025950, 10, -218.9047, -211.1511, 97.592926),
(2025980, 1, -218.625, 2.2204819, 97.593),
(2025980, 2, -218.63019, -37.989586, 97.593);

-- Fix amount of gold from Flame Warder in heroic
UPDATE `creature_template` SET `mingold` = 8112, `maxgold` = 13520 WHERE `entry` = 35359;

-- Meteor Fists for heroic mode
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 66809;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(66809,66809,67331,0,0);
