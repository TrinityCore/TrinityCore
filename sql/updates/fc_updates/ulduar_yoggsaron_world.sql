-- Sara
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 1, `ScriptName` = 'boss_sara' WHERE `entry` IN (33134, 34332);
UPDATE creature_model_info SET bounding_radius = 0.465, combat_reach = 45 WHERE modelid = 29117;
UPDATE `creature` SET `spawndist` = 0 WHERE `id` = 33134;
-- Ominous cloud
DELETE FROM `creature` WHERE `id`=33292;
UPDATE `creature_template` SET `ScriptName` = 'npc_ominous_cloud' WHERE `entry` = 33292;
-- Guardian of Yogg-Saron
UPDATE `creature_template` SET `difficulty_entry_1` = 33968, `faction_A` = 14, `faction_H` = 14, `ScriptName` = 'npc_guardian_yoggsaron' WHERE `entry` = 33136;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 33968;
UPDATE creature_model_info SET bounding_radius = 0.62, combat_reach = 1.5 WHERE modelid = 28465;
-- Yogg-Saron
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235, `ScriptName` = 'boss_yoggsaron' WHERE `entry` = 33288;
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 33955;
UPDATE creature_model_info SET bounding_radius = 0.755, combat_reach = 18 WHERE modelid = 28817;
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `speed_walk` = 2, `ScriptName` = 'npc_death_orb' WHERE `entry` = 33882;
-- Brain of Yogg-Saron
UPDATE `creature_template` SET `difficulty_entry_1` = 33954, `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235, `ScriptName` = 'boss_brain_yoggsaron' WHERE `entry` = 33890;
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235 WHERE `entry` = 33954;
UPDATE creature_model_info SET bounding_radius = 0.755, combat_reach = 30 WHERE modelid = 28951;
-- Illusions
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14, `ScriptName` = 'npc_laughing_skull' WHERE `entry` = 33990;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 7, `faction_H` = 7, `mechanic_immune_mask` = 650854235, `ScriptName` = 'npc_illusion' WHERE `entry` IN (33433, 33716, 33717, 33719, 33720, 33567);
UPDATE creature_model_info SET bounding_radius = 0.306, combat_reach = 1.5 WHERE modelid = 28621;
UPDATE creature_model_info SET bounding_radius = 1, combat_reach = 10 WHERE modelid IN (2718, 1687, 2717, 12869);
-- Influence Tentacle
UPDATE `creature_template` SET `difficulty_entry_1` = 33959, `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 33943;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 33959;
UPDATE creature_model_info SET bounding_radius = 0.306, combat_reach = 1.5 WHERE modelid = 28813;
-- Fake npcs
UPDATE `creature_template` SET ScriptName = "npc_passive_illusion" WHERE `entry` IN (33436, 33437, 33536, 33535, 33495, 33523, 33441, 33442);
-- Whispers
UPDATE `script_texts` SET `type` = 4 WHERE `entry` IN (-1603317, -1603340, -1603339);
-- Descend into madness portal
UPDATE `creature_template` SET `npcflag` = 16777216, `unit_flags` = 2, `type_flags` = 0, `ScriptName` = 'npc_descend_into_madness' WHERE `entry` = 34072;
DELETE FROM `creature_template` WHERE entry IN (34122, 34123);
INSERT INTO `creature_template` VALUES
('34122','0','0','0','0','0','29074','0','0','0','Descend Into Madness','','Interact','0','81','81','0','35','35','16777216','1','1.14286','1','0','0','0','0','0','1','2000','0','1','2','0','0','0','0','0','0','0','0','0','10','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_descend_into_madness','11159'),
('34123','0','0','0','0','0','29074','0','0','0','Descend Into Madness','','Interact','0','81','81','0','35','35','16777216','1','1.14286','1','0','0','0','0','0','1','2000','0','1','2','0','0','0','0','0','0','0','0','0','10','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_descend_into_madness','11159');
-- Flee to the Surface
UPDATE `gameobject_template` SET `data10` = 63992 WHERE `entry` = 194625;
DELETE FROM `gameobject` WHERE `id` = 194625;
INSERT INTO `gameobject` VALUES
(NULL, 194625, 603, 3, 1, 1996.41, -0.070, 240.59, 0, 0, 0, 1, 0, 300, 0, 1),
(NULL, 194625, 603, 3, 1, 1949.63, -26.07, 241.25, 0, 0, 0, 1, 0, 300, 0, 1),
(NULL, 194625, 603, 3, 1, 1995.03, -52.98, 241.02, 0, 0, 0, 1, 0, 300, 0, 1);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34072, 34122, 34123);
INSERT INTO `npc_spellclick_spells` VALUES
(34072, 63989, 0, 0, 0, 3, 0, 0, 0), -- Stormwind
(34122, 63997, 0, 0, 0, 3, 0, 0, 0), -- Chamber
(34123, 63998, 0, 0, 0, 3, 0, 0, 0); -- Icecrown
-- Cancel Illusion Room Aura
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 63992;
INSERT INTO `spell_linked_spell` VALUES
(63992, -63988, 0, "Cancel Illusion Room Aura");
-- Dragon blood
DELETE FROM gameobject WHERE id = 194462;
INSERT INTO gameobject VALUES (NULL, 194462, 603, 3, 1, 2104.35, -25.3753, 242.647, 0, 0, 0, 0, -1, 300, 0, 1);
-- Remove spawned mobs
-- DELETE FROM `creature` WHERE `id`=34137 AND position_x = 1921.84;
-- Portals coordinates
DELETE FROM `spell_target_position` WHERE `id` IN (63989, 63992, 63997, 63998);
INSERT INTO `spell_target_position` VALUES
(63989, 603, 1953.91, 21.91, 239.71, 2.08),
(63992, 603, 1980.28, -25.59, 329.40, 3.14),
(63997, 603, 2042.02, -25.54, 239.72, 0),
(63998, 603, 1948.44, -82.04, 239.99, 4.18);
-- Tentacles
UPDATE `creature_template` SET `difficulty_entry_1` = 33984, `faction_A` = 14, `faction_H` = 14, `ScriptName` = "npc_constrictor_tentacle" WHERE `entry` = 33983;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14, `VehicleId` = 385 WHERE `entry` = 33984;
UPDATE creature_model_info SET bounding_radius = 0.306, combat_reach = 1.5 WHERE modelid = 28815;
-- Constrictor vehicle
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 33983;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33983,46598,0,0,0,0,0,0,0);
UPDATE `creature_template` SET `difficulty_entry_1` = 33967, `faction_A` = 14, `faction_H` = 14, `baseattacktime` = 1800, `ScriptName` = 'npc_crusher_tentacle' WHERE `entry` = 33966;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `faction_A` = 14, `faction_H` = 14, `baseattacktime` = 1800 WHERE `entry` = 33967;
UPDATE creature_model_info SET bounding_radius = 0.985, combat_reach = 5 WHERE modelid = 28814;
UPDATE `creature_template` SET `difficulty_entry_1` = 33986, `faction_A` = 14, `faction_H` = 14, `ScriptName` = 'npc_corruptor_tentacle' WHERE `entry` = 33985;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 33986;
-- Immortal Guardian
UPDATE `creature_template` SET `difficulty_entry_1` = 33989, `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235, `ScriptName` = 'npc_immortal_guardian' WHERE `entry` = 33988;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14, `mechanic_immune_mask` = 650854235 WHERE `entry` = 33989;
UPDATE creature_model_info SET bounding_radius = 0.92, combat_reach = 4 WHERE modelid = 29024;
-- Remove area stun
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (64059, 65238);
INSERT INTO `spell_linked_spell` VALUES
(64059, 65238, 0, "Shattered illusion remove"),
(65238, -64173, 1, "Shattered illusion remove");
-- Yogg-Saron emotes
DELETE FROM script_texts WHERE entry IN (-1603342, -1603343, -1603344);
INSERT INTO script_texts VALUES 
(33288, -1603342, "Portals open into Yogg-Saron's mind!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_PORTALS"),
(33288, -1603343, "The Illusion shatters and a path to the central chamber opens!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_OPEN_CHAMBER"),
(33288, -1603344, "Yogg-Saron prepares to unleash Empowering Shadows!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_EMPOWERING");
-- Ulduar Keepers Images
DELETE FROM `creature` WHERE `id` IN (33213, 33241, 33242, 33244);
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(33241, 603, 3, 1, 0, 0, 2057.81, -24.0768, 421.532, 3.12904, 604800, 0, 0, 14433075, 0, 0, 0),
(33242, 603, 3, 1, 0, 0, 2036.81, -73.7053, 411.353, 2.43575, 604800, 0, 0, 14433075, 0, 0, 0),
(33244, 603, 3, 1, 0, 0, 2036.74, 25.4642, 411.357, 3.81412, 604800, 0, 0, 14433075, 0, 0, 0),
(33213, 603, 3, 1, 0, 0, 1939.29, -90.6994, 411.357, 1.02595, 604800, 0, 0, 14433075, 0, 0, 0);

UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `npcflag` = 1, `flags_extra` = 2, `ScriptName` = 'npc_keeper_image' WHERE `entry` IN (33213, 33241, 33242, 33244);

-- Keepers (Yogg Saron Encounter)
DELETE FROM `creature` WHERE `id` IN (33410, 33411, 33412, 33413);
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(33410, 603, 3, 1, 0, 0, 2036.739, 25.464, 338.296, 3.814, 604800, 0, 0, 14433075, 0, 0, 0),
(33411, 603, 3, 1, 0, 0, 1939.094, -90.699, 338.296, 1.026, 604800, 0, 0, 14433075, 0, 0, 0),
(33412, 603, 3, 1, 0, 0, 1939.094, 42.534, 338.296, 5.321, 604800, 0, 0, 14433075, 0, 0, 0),
(33413, 603, 3, 1, 0, 0, 2036.739, -73.705, 338.296, 2.435, 604800, 0, 0, 14433075, 0, 0, 0);

UPDATE `creature_template` SET `ScriptName` = 'npc_ys_freya' WHERE `entry` = 33410;
UPDATE `creature_template` SET `ScriptName` = 'npc_ys_hodir' WHERE `entry` = 33411;
UPDATE `creature_template` SET `ScriptName` = 'npc_ys_mimiron' WHERE `entry` = 33412;
UPDATE `creature_template` SET `ScriptName` = 'npc_ys_thorim' WHERE `entry` = 33413;
UPDATE `creature_template` SET `ScriptName` = 'npc_sanity_well' WHERE `entry` = 33991;

-- Death Ray Target
DELETE FROM conditions WHERE SourceEntry IN (63882, 63886);
INSERT INTO conditions VALUES 
(13, 0, 63882, 0, 18, 1, 33134, 0, 0, '', 'Death Ray Warning (Yogg-Saron)'),
(13, 0, 63886, 0, 18, 1, 33134, 0, 0, '', 'Death Ray Damage (Yogg-Saron)');

-- Shattered Illusion Targets
DELETE FROM conditions WHERE SourceEntry = 64173;
INSERT INTO conditions VALUES 
(13, 0, 64173, 0, 18, 1, 33966, 0, 0, '', 'Shattered Illusion (Yogg-Saron)'),
(13, 0, 64173, 0, 18, 1, 33983, 0, 0, '', 'Shattered Illusion (Yogg-Saron)'),
(13, 0, 64173, 0, 18, 1, 33985, 0, 0, '', 'Shattered Illusion (Yogg-Saron)');

-- Thorim's Titanic Storm
DELETE FROM conditions WHERE SourceEntry = 64172;
INSERT INTO conditions VALUES 
(13, 0, 64172, 0, 18, 1, 33988, 0, 0, '', 'Thorim''s Titanic Storm (Yogg-Saron)');

-- Empowering Shadows
DELETE FROM conditions WHERE SourceEntry = 64468;
INSERT INTO conditions VALUES 
(13, 0, 64468, 0, 18, 1, 33288, 0, 0, '', 'Empowering Shadows (Yogg-Saron)'),
(13, 0, 64468, 0, 18, 1, 33988, 0, 0, '', 'Empowering Shadows (Yogg-Saron)');

-- Shadow Nova Target
DELETE FROM conditions WHERE SourceEntry IN (62714, 65209);
INSERT INTO conditions VALUES 
(13, 0, 62714, 0, 18, 1, 33134, 0, 0, '', 'Shadow Nova (Yogg-Saron)'),
(13, 0, 65209, 0, 18, 1, 33134, 0, 0, '', 'Shadow Nova (Yogg-Saron)');

-- Spell Scripts
DELETE FROM spell_script_names WHERE spell_id IN (64164, 64168, 64059);
INSERT INTO spell_script_names VALUES 
(64164, "spell_yoggsaron_lunatic_gaze"),
(64168, "spell_yoggsaron_lunatic_gaze"),
(64059, "spell_yoggsaron_induce_madness");