-- Replace guessed waypoint with sniffed
UPDATE `waypoint_data` SET `position_x` = -242.57414, `position_y` = 300.84528, `position_z` = 26.730623 WHERE `id` = 832570 AND `point` = 11;

-- Add missing Invisibility and Stealth Detection aura to Syth
UPDATE `creature_template_addon` SET `auras` = "18950" WHERE `entry` IN (18472,20690);
-- Fix sheath
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (21931,18473,20706,18472,20690);
UPDATE `creature_addon` SET `bytes2` = 1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (18322,18323,19428,19429,21904));
-- Empty addon
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 18956);

-- Add on-spawn & on-death serverside spells to Syth's elementals
-- For some reason spell 'Syth D Dummy' (33613) wasn't shown in sniff (assumedly used by 19205)
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19203,19204,19205,19206) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19203,0,0,0,54,0,100,0,0,0,0,0,11,33610,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Fire Elemental - On Just Summoned - Cast 'Syth A Dummy'"),
(19203,0,1,0,0,0,100,2,1600,7600,8400,18100,11,33526,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Fire Elemental - In Combat - Cast 'Flame Buffet' (Normal Dungeon)"),
(19203,0,2,0,0,0,100,4,1200,3600,6000,7200,11,38141,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Fire Elemental - In Combat - Cast 'Flame Buffet' (Heroic Dungeon)"),
(19203,0,3,0,6,0,100,0,0,0,0,0,11,33621,2,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Fire Elemental - On Death - Cast 'Syth Dummy'"),

(19204,0,0,0,54,0,100,0,0,0,0,0,11,33611,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Frost Elemental - On Just Summoned - Cast 'Syth B Dummy'"),
(19204,0,1,0,0,0,100,2,1600,7600,8400,18100,11,33528,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Frost Elemental - In Combat - Cast 'Frost Buffet' (Normal Dungeon)"),
(19204,0,2,0,0,0,100,4,1200,3600,6000,7200,11,38142,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Frost Elemental - In Combat - Cast 'Frost Buffet' (Heroic Dungeon)"),
(19204,0,3,0,6,0,100,0,0,0,0,0,11,33621,2,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Frost Elemental - On Death - Cast 'Syth Dummy'"),

(19205,0,0,0,0,0,100,2,1600,7600,8400,18100,11,33527,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Arcane Elemental - In Combat - Cast 'Arcane Buffet' (Normal Dungeon)"),
(19205,0,1,0,0,0,100,4,1200,3600,6000,7200,11,38138,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Arcane Elemental - In Combat - Cast 'Arcane Buffet' (Heroic Dungeon)"),
(19205,0,2,0,6,0,100,0,0,0,0,0,11,33621,2,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Arcane Elemental - On Death - Cast 'Syth Dummy'"),

(19206,0,0,0,54,0,100,0,0,0,0,0,11,33612,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Shadow Elemental - On Just Summoned - Cast 'Syth C Dummy'"),
(19206,0,1,0,0,0,100,2,1600,7600,8400,18100,11,33529,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Shadow Elemental - In Combat - Cast 'Shadow Buffet' (Normal Dungeon)"),
(19206,0,2,0,0,0,100,4,1200,3600,6000,7200,11,38143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syth Shadow Elemental - In Combat - Cast 'Shadow Buffet' (Heroic Dungeon)"),
(19206,0,3,0,6,0,100,0,0,0,0,0,11,33621,2,0,0,0,0,1,0,0,0,0,0,0,0,"Syth Shadow Elemental - On Death - Cast 'Syth Dummy'");

-- Improve Lakka's script
UPDATE `smart_scripts` SET `event_flags` = 1, `comment` = "Lakka - On Gossip Option 0 Selected - Run Script (No Repeat)" WHERE `entryorguid` = 18956 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1895600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1895600,9,0,0,0,0,100,0,0,0,0,0,0,33,18956,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Lakka - On Script - Quest Credit 'Brother Against Brother'"),
(1895600,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lakka - On Script - Say Line 0"),
(1895600,9,2,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakka - On Script - Remove NPC Flag Gossip"),
(1895600,9,3,0,0,0,100,0,1500,1500,0,0,0,9,0,0,0,0,0,0,20,183051,5,0,0,0,0,0,0,"Lakka - On Script - Activate Closest Gameobject 'Sethekk Cage'"),
(1895600,9,4,0,0,0,100,0,1000,1000,0,0,0,53,0,18956,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lakka - On Script - Start Waypoint");
