-- The Vortex Pinnacle
UPDATE `instance_template` SET `script` = 'instance_vortex_pinnacle' WHERE `map` = 657;

UPDATE `creature_template` SET `mechanic_immune_mask` = 617299839 WHERE `entry` IN (43878, 43873, 43875);

-- Script names
UPDATE `creature_template` SET `ScriptName` = 'boss_grand_vizier_ertan' WHERE `entry` = 43878;
UPDATE `creature_template` SET `ScriptName` = 'boss_altairus' WHERE `entry` = 43873;
UPDATE `creature_template` SET `ScriptName` = 'boss_asaad' WHERE `entry` = 43875;

UPDATE `creature_template` SET `ScriptName` = 'npc_lurking_tempest' WHERE `entry` = 45704;
UPDATE `creature_template` SET `ScriptName` = 'npc_ertans_vortex' WHERE `entry` = 46007;
UPDATE `creature_template` SET `ScriptName` = 'npc_slipstream' WHERE `entry` = 45455;
UPDATE `creature_template` SET `ScriptName` = 'npc_slipstream_landing_zone' WHERE `entry` = 45504;
UPDATE `creature_template` SET `ScriptName` = 'npc_young_storm_dragon' WHERE `entry` = 45919;
UPDATE `creature_template` SET `ScriptName` = 'npc_air_current' WHERE `entry` = 47305;
UPDATE `creature_template` SET `ScriptName` = 'npc_grounding_field' WHERE `entry` = 47085;
UPDATE `creature_template` SET `ScriptName` = 'npc_skyfall' WHERE `entry` = 45981;
UPDATE `creature_template` SET `ScriptName` = 'npc_skyfall_star' WHERE `entry` = 45932;
UPDATE `creature_template` SET `ScriptName` = 'npc_unstable_grounding_field' WHERE `entry` = 46492;
UPDATE `creature_template` SET `ScriptName` = 'npc_storm_target' WHERE `entry` = 46387;
UPDATE `creature_template` SET `ScriptName` = 'npc_asaad_grounding_field' WHERE `entry` = 47000;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (84978, 84989, 85395, 85396, 85017);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84978, 'spell_slipstream'),
(84989, 'spell_slipstream'),
(85395, 'spell_slipstream'),
(85396, 'spell_slipstream'),
(85017, 'spell_slipstream');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (85294, 85291, 85267, 86493, 85281, 86456, 86284, 86311, 86299, 85084, 88276, 88282, 88772, 88322, 87726, 87850, 87854);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85294, 'spell_lurk_search'),
(85291, 'spell_lurk_search_check'),
(85267, 'spell_feign_death'),
(86493, 'spell_lurk_search_check'),
(85281, 'spell_lurk_ressurect'),
(86456, 'spell_lurk_search_victim'),
(86284, 'spell_storms_edge'),
(86311, 'spell_storms_edge'),
(86299, 'spell_storms_edge_script'),
(85084, 'spell_howling_gale'),
(88276, 'spell_call_the_wind'),
(88282, 'spell_upwind_of_altairus'),
(88772, 'spell_call_the_wind_channel'),
(88322, 'spell_chilling_breath'),
(87726, 'spell_grounding_field'),
(87850, 'spell_skyfall'),
(87854, 'spell_arcane_barrage');

-- Asaad spell script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (86632, 86926, 86921, 86923, 86925, 87517, 87553, 93994);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86632, 'spell_sots_targeting'),
(86926, 'spell_sots_trigger'),
(86921, 'spell_storm_rune_beam'),
(86923, 'spell_storm_rune_beam'),
(86925, 'spell_storm_rune_beam'),
(87517, 'spell_grounding_field_visual_beams'),
(87553, 'spell_supremacy_of_the_storm'),
(93994, 'spell_supremacy_of_the_storm');

-- Spell condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (86284, 86299, 88276, 88772, 87724, 87726, 87850, 86632, 86926, 86911, 86981, 87328);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 86284, 0, 0, 35, 0, 1, 25, 3, 0, 0, 0, '', 'Storm''s Edge targets must be further than 25 yards'),
(13, 1, 86299, 0, 0, 31, 0, 3, 46007, 0, 0, 0, 0, '', 'Call The Wind targets NPC_ERTANS_VORTEX'),
(13, 1, 88276, 0, 0, 31, 0, 3, 47305, 0, 0, 0, 0, '', 'Call The Wind EFFECT_0 can only hit NPC_AIR_CURRENT'),
(13, 1, 88772, 0, 0, 31, 0, 3, 47305, 0, 0, 0, 0, '', 'Call The Wind targets NPC_AIR_CURRENT'),
(13, 1, 88772, 0, 0, 1, 0, 88244, 0, 0, 0, 0, 0, '', 'Call The Wind target must have Call The Wind aura'),
(13, 1, 87724, 0, 0, 1, 0, 87721, 0, 0, 0, 0, 0, '', 'Prism Beam EFFECT_0 target must have SPELL_BEAM_A aura'),
(13, 2, 87724, 0, 0, 1, 0, 87722, 0, 0, 0, 0, 0, '', 'Prism Beam EFFECT_1 target must have SPELL_BEAM_B aura'),
(13, 4, 87724, 0, 0, 1, 0, 87723, 0, 0, 0, 0, 0, '', 'Prism Beam EFFECT_2 target must have SPELL_BEAM_C aura'),
(13, 1, 87726, 0, 0, 31, 0, 3, 45926, 0, 0, 0, 0, '', 'Grounding Field can target npc Servant of Asaad'),
(13, 1, 87726, 0, 1, 31, 0, 3, 45928, 0, 0, 0, 0, '', 'Grounding Field can target npc Executor of the Caliph'),
(13, 1, 87726, 0, 2, 31, 0, 3, 45930, 0, 0, 0, 0, '', 'Grounding Field can target npc Minister of Air'),
(13, 1, 87726, 0, 3, 31, 0, 3, 45935, 0, 0, 0, 0, '', 'Grounding Field can target npc Temple Adept'),
(13, 1, 87850, 0, 0, 31, 0, 3, 52019, 0, 0, 0, 0, '', 'Skyfall targets NPC_SKYFALL_STAR'),
(13, 1, 86632, 0, 0, 31, 0, 3, 46387, 0, 0, 0, 0, '', 'SOTS Targeting targets NPC_STORM_TARGET'),
(13, 1, 86926, 0, 0, 31, 0, 3, 43875, 0, 0, 0, 0, '', 'SOTS Trigger targets BOSS_ASAAD'),
(13, 1, 86911, 0, 0, 31, 0, 3, 46492, 0, 0, 0, 0, '', 'Unstable Grounding Field targets NPC_UNSTABLE_GROUNDING_FIELD'),
(13, 1, 86981, 0, 0, 31, 0, 3, 46387, 0, 0, 0, 0, '', 'Storm Rune Beam AA targets NPC_STORM_TARGET'),
(13, 1, 87328, 0, 0, 31, 0, 3, 47000, 0, 0, 0, 0, '', 'Supremacy of the Storm targets NPC_ASAAD_GROUNDING_FIELD');

-- Lurking Tempest
DELETE FROM `creature_template_addon` WHERE `entry` = 45704;

DELETE FROM `creature_text` WHERE `entry` = 45704;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(45704, 0, 0, '%s realizes it''s been spotted and quickly plays dead!', 16, 0, 100, 0, 0, 0, 0, 0, 'Lurking Tempest to Lurking Tempest');

-- Grand Vizier Ertan
UPDATE `creature_template` SET `difficulty_entry_1` = 43879 WHERE `entry` = 43878;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `exp` = 3, `faction` = 16, `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_class` = 2, `unit_flags` = 32832, `ManaModifier` = 2, `flags_extra` = 1 WHERE `entry` = 43879;

-- Grand Vizier Ertan texts
DELETE FROM `creature_text` WHERE `entry` = 43878;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43878, 0, 0, 'Filthy beasts! Your presence in Skywall will not be tolerated!', 14, 0, 100, 0, 0, 20876, 0, 0, 'Grand Vizier Ertan to Player'),
(43878, 1, 0, '%s retracts her cyclone shield!', 41, 0, 100, 0, 0, 0, 47800, 0, 'Grand Vizier Ertan');

-- Grand Vizier Ertan loot
UPDATE `creature_template` SET `lootid` = 43878 WHERE `entry` = 43878;
UPDATE `creature_template` SET `lootid` = 43879 WHERE `entry` = 43879;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43878, 43879);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43878, 1, 43410, 100, 0, 1, 0, 1, 1, 'Grand Vizier Ertan N - Reference Loot'),
(43879, 1, 43411, 100, 0, 1, 0, 1, 1, 'Grand Vizier Ertan H - Reference Loot'),
(43878, 65660, 0, 100, 1, 1, 0, 1, 1, 'Grand Vizier Ertan N - Quest Item'),
(43879, 65660, 0, 100, 1, 1, 0, 1, 1, 'Grand Vizier Ertan H - Quest Item');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43410, 43411);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43410, 55830, 0, 0, 0, 1, 1, 1, 1, NULL),
(43410, 55831, 0, 0, 0, 1, 1, 1, 1, NULL),
(43410, 55832, 0, 0, 0, 1, 1, 1, 1, NULL),
(43410, 55833, 0, 0, 0, 1, 1, 1, 1, NULL),
(43410, 55834, 0, 0, 0, 1, 1, 1, 1, NULL),
(43411, 56356, 0, 0, 0, 1, 1, 1, 1, NULL),
(43411, 56357, 0, 0, 0, 1, 1, 1, 1, NULL),
(43411, 56358, 0, 0, 0, 1, 1, 1, 1, NULL),
(43411, 56359, 0, 0, 0, 1, 1, 1, 1, NULL),
(43411, 56360, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Ertan's Vortex.
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 46007;

-- Slipstream
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` IN (45455, 45504);
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 45504;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 45455;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45455, 84965, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 45455;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45455, 0, 0, 0, 1, 0, '85021');

-- Young Storm Dragon
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 45919;

DELETE FROM `creature_template_addon` WHERE `entry` = 45919;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45919, 0, 0, 0, 1, 0, '88192');

-- Howling Gale
DELETE FROM `creature_template_addon` WHERE `entry` = 45572;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45572, 0, 0, 0, 1, 0, '85084');

-- Altairus
UPDATE `creature_template` SET `difficulty_entry_1` = 43874, `InhabitType` = 7 WHERE `entry` = 43873;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `exp` = 3, `faction` = 16, `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 32832, `InhabitType` = 7, `HoverHeight` = 10.125, `flags_extra` = 1 WHERE `entry` = 43874;

-- Altairus texts
DELETE FROM `creature_text` WHERE `entry` = 43873;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43873, 0, 0, 'The wind abruptly shifts direction at %s'' command!', 41, 0, 100, 0, 0, 0, 0, 0, 'Altairus');

-- Altairus loot
UPDATE `creature_template` SET `lootid` = 43873 WHERE `entry` = 43873;
UPDATE `creature_template` SET `lootid` = 43874 WHERE `entry` = 43874;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43873, 43874);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43873, 1, 43412, 100, 0, 1, 0, 1, 1, 'Altairus N - Reference Loot'),
(43874, 1, 43413, 100, 0, 1, 0, 1, 1, 'Altairus H - Reference Loot'),
(43873, 63040, 0, 1, 0, 1, 0, 1, 1, 'Altairus N - Mount Drop'),
(43874, 63040, 0, 1, 0, 1, 0, 1, 1, 'Altairus H - Mount Drop');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43412, 43413);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43412, 55835, 0, 0, 0, 1, 1, 1, 1, NULL),
(43412, 55838, 0, 0, 0, 1, 1, 1, 1, NULL),
(43412, 55839, 0, 0, 0, 1, 1, 1, 1, NULL),
(43412, 55840, 0, 0, 0, 1, 1, 1, 1, NULL),
(43412, 55841, 0, 0, 0, 1, 1, 1, 1, NULL),
(43413, 56361, 0, 0, 0, 1, 1, 1, 1, NULL),
(43413, 56362, 0, 0, 0, 1, 1, 1, 1, NULL),
(43413, 56363, 0, 0, 0, 1, 1, 1, 1, NULL),
(43413, 56364, 0, 0, 0, 1, 1, 1, 1, NULL),
(43413, 56365, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Invisible Stalker (Cataclysm Boss, Ignore Combat)
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 42844;
DELETE FROM `creature_template_addon` WHERE `entry` = 42844;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(42844, 0, 0, 0, 1, 0, '88350');

-- Air Current
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 128 WHERE `entry` = 47305;

-- Twister
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 47342;
DELETE FROM `creature_template_addon` WHERE `entry` = 47342;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(47342, 0, 0, 0, 1, 0, '88313');

-- Zephyr
UPDATE `creature_template` SET `speed_walk` = 4, `speed_run` = 12, `flags_extra` = 128 WHERE `entry` = 45991;
DELETE FROM `creature_template_addon` WHERE `entry` = 45991;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45991, 0, 0, 0, 1, 0, '85734');
DELETE FROM `waypoint_data` WHERE `id` IN (4599100, 4599101);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(4599100, 1, -1050.74,  429.649,  651.2561, 0, 0, 0, 0, 100, 0),
(4599100, 2, -1025.79,  446.358,  657.6731, 0, 0, 0, 0, 100, 0),
(4599100, 3, -1021.287, 474.0407, 664.598,  0, 0, 0, 0, 100, 0),
(4599100, 4, -1036.114, 495.2139, 670.9863, 0, 0, 0, 0, 100, 0),
(4599100, 5, -1059.67,  498.865,  677.6423, 0, 0, 0, 0, 100, 0),
(4599100, 6, -1077.17,  485.951,  683.4588, 0, 0, 0, 0, 100, 0),
(4599100, 7, -1080.06,  466.3477, 688.7894, 0, 0, 0, 0, 100, 0),
(4599100, 8, -1069.01,  452.476,  693.6293, 0, 0, 0, 0, 100, 0),
(4599100, 9, -1053.397, 450.5248, 698.0431, 0, 0, 0, 45991, 100, 0),
(4599101, 1, -781.4438, 491.1446, 698.0991, 0, 0, 0, 0, 100, 0),
(4599101, 2, -765.677,  487.116,  693.6418, 0, 0, 0, 0, 100, 0),
(4599101, 3, -756.743,  472.135,  688.8555, 0, 0, 0, 0, 100, 0),
(4599101, 4, -762.127,  453.059,  683.3886, 0, 0, 0, 0, 100, 0),
(4599101, 5, -780.924,  442.635,  677.577,  0, 0, 0, 0, 100, 0),
(4599101, 6, -803.446,  449.476,  670.8987, 0, 0, 0, 0, 100, 0),
(4599101, 7, -815.382,  471.972,  664.5117, 0, 0, 0, 0, 100, 0),
(4599101, 8, -807.351,  498.323,  657.6155, 0, 0, 0, 0, 100, 0),
(4599101, 9, -780.9688, 511.8101, 651.2169, 0, 0, 0, 45991, 100, 0);
DELETE FROM `waypoint_scripts` WHERE `id` = 45991;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(45991, 0, 18, 0, 0, 0, 0, 0, 0, 0, 8);

-- Grounding Field and Skyfall Star inhabit type correction
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` IN (47085, 45932);

-- Asaad
UPDATE `creature_template` SET `difficulty_entry_1` = 43876, `InhabitType` = 7 WHERE `entry` = 43875;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `exp` = 3, `faction` = 16, `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_class` = 2, `unit_flags` = 32832, `ManaModifier` = 2, `flags_extra` = 1 WHERE `entry` = 43876;

-- Asaad texts
DELETE FROM `creature_text` WHERE `entry` = 43875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43875, 0, 0, 'YOU tread upon the sacrosanct! Mortals have no place amidst the clouds.', 14, 0, 100, 0, 0, 20867, 0, 0, 'Asaad to Player'),
(43875, 1, 0, 'Al''Akir, your servant calls for aid!', 14, 0, 100, 0, 0, 20869, 0, 0, 'Asaad'),
(43875, 2, 0, '%s conjures a temporary grounding field!', 41, 0, 100, 0, 0, 20869, 0, 0, 'Asaad'),
(43875, 3, 0, 'The winds take me!', 14, 0, 100, 0, 0, 20870, 0, 0, 'Asaad to Player');

-- Asaad loot
UPDATE `creature_template` SET `lootid` = 43875 WHERE `entry` = 43875;
UPDATE `creature_template` SET `lootid` = 43876 WHERE `entry` = 43876;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43875, 43876);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43875, 1, 43414, 100, 0, 1, 0, 2, 2, 'Asaad N - Reference Loot'),
(43876, 1, 43415, 100, 0, 1, 0, 2, 2, 'Asaad H - Reference Loot'),
(43876, 52078, 0, 100, 0, 1, 0, 1, 1, 'Asaad H - Chaos Orb');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43414, 43415);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43414, 55842, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55844, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55845, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55846, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55847, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55848, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55849, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55850, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55851, 0, 0, 0, 1, 1, 1, 1, NULL),
(43414, 55852, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Grounding Field inhabit type correction
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` IN (47000);

-- Set CREATURE_FLAG_EXTRA_TRIGGER to Storm Target, Unstable Grounding Field and Grounding Field.
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` IN (46387, 46492, 47000);
