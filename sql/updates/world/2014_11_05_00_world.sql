-- The Stonecore
DELETE FROM `instance_template` WHERE `map` = 725;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(725, 0, 'instance_stonecore', 0);

DELETE FROM `instance_encounters` WHERE `entry` IN (1056, 1059, 1058, 1057);
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES
(1056, 0, 43438, 0, 'Corborus'),
(1059, 0, 43214, 0, 'Slabhide'),
(1058, 0, 42188, 0, 'Ozruk'),
(1057, 0, 42333, 0, 'High Priestess Azil');

UPDATE `creature_template` SET `mechanic_immune_mask` = 617299839 WHERE `entry` IN (43391, 43438, 43214, 42188, 42333);

-- Script names
UPDATE `creature_template` SET `ScriptName` = 'boss_corborus' WHERE `entry` = 43438;
UPDATE `creature_template` SET `ScriptName` = 'boss_slabhide' WHERE `entry` = 43214;
UPDATE `creature_template` SET `ScriptName` = 'boss_ozruk' WHERE `entry` = 42188;
UPDATE `creature_template` SET `ScriptName` = 'boss_high_priestess_azil' WHERE `entry` = 42333;
UPDATE `creature_template` SET `ScriptName` = 'npc_rock_borer' WHERE `entry` = 43917;
UPDATE `creature_template` SET `ScriptName` = 'npc_sc_millhouse_manastorm' WHERE `entry` = 43391;
UPDATE `creature_template` SET `ScriptName` = 'npc_lava_fissure' WHERE `entry` = 43242;
UPDATE `creature_template` SET `ScriptName` = 'npc_stalactite_trigger' WHERE `entry` = 43159;
UPDATE `creature_template` SET `ScriptName` = 'npc_devout_follower' WHERE `entry` = 42428;
UPDATE `creature_template` SET `ScriptName` = 'npc_gravity_well' WHERE `entry` = 42499;
UPDATE `creature_template` SET `ScriptName` = 'npc_seismic_shard' WHERE `entry` = 42355;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (81459, 45313, 93167, 81008, 81035, 81028, 80650, 80654, 80643, 92653, 80647, 92309, 92306, 92300, 92393, 78835, 92429, 79200, 79196, 79251, 79249, 79332, 86862, 86863, 79015);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81459, 'spell_force_of_earth'),
(45313, 'spell_sc_anchor_here'),
(93167, 'spell_sc_twilight_documents'),
(81008, 'spell_sc_quake'),
(81035, 'spell_s81035_stalactite'),
(81028, 'spell_s81028_s80650_stalactite'),
(80650, 'spell_s81028_s80650_stalactite'),
(80654, 'spell_stalactite_mod_dest_height'),
(80643, 'spell_stalactite_mod_dest_height'),
(92653, 'spell_stalactite_mod_dest_height'),
(80647, 'spell_stalactite_mod_dest_height'),
(92309, 'spell_stalactite_mod_dest_height'),
(92306, 'spell_s92306_crystal_storm'),
(92300, 'spell_s92300_crystal_storm'),
(92393, 'spell_rupture'),
(78835, 'spell_elementium_spike_shield'),
(92429, 'spell_elementium_spike_shield'),
(79200, 'spell_summon_wave_south'),
(79196, 'spell_summon_wave_west'),
(79251, 'spell_gravity_well_damage_nearby'),
(79249, 'spell_gravity_well_damage'),
(79332, 'spell_gravity_well_pull'),
(86862, 'spell_seismic_shard_prepare'),
(86863, 'spell_seismic_shard_change_seat'),
(79015, 'spell_seismic_shard');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6076, 6070);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6076, 'at_sc_corborus_intro'),
(6070, 'at_sc_slabhide_intro');

-- Twilight Documents object is spawned by Millhouse.
DELETE FROM `gameobject` WHERE `id` = 207415;

-- Millhouse Manastorm texts
DELETE FROM `creature_text` WHERE `entry` IN (43391);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43391, 0, 1, 'Follow me if you dare!', 14, 0, 100, 0, 0, 21783, 0, 0, 'Millhouse Manastorm'),
(43391, 0, 2, 'It''s time for a tactical retreat!', 14, 0, 100, 0, 0, 21784, 0, 0, 'Millhouse Manastorm'),
(43391, 0, 3, 'You''re gonna be sorry!', 14, 0, 100, 0, 0, 21785, 0, 0, 'Millhouse Manastorm'),
(43391, 0, 4, 'Don''t say I didn''t warn ya!', 14, 0, 100, 0, 0, 21786, 0, 0, 'Millhouse Manastorm'),
(43391, 1, 1, 'Ah-ha! I''ve got you right where I want you!', 14, 0, 100, 0, 0, 21787, 0, 0, 'Millhouse Manastorm'),
(43391, 1, 2, 'Now... witness the full power of Millhouse Manastorm!', 14, 0, 100, 0, 0, 21788, 0, 0, 'Millhouse Manastorm'),
(43391, 1, 3, 'Prison taught me one very important lesson, well, two if you count how to hold your soap, but yes! SURVIVAL!', 14, 0, 100, 0, 0, 21789, 0, 0, 'Millhouse Manastorm');

-- Creature formations for Millhouse event (340418 -> trash, 340492 -> last group)
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (340418, 340392, 340492);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(340418, 340418, 0, 0, 0, 0, 0),
(340418, 340419, 0, 0, 0, 0, 0),
(340418, 340421, 0, 0, 0, 0, 0),
(340418, 340422, 0, 0, 0, 0, 0),
(340418, 340465, 0, 0, 0, 0, 0),
(340418, 340466, 0, 0, 0, 0, 0),
(340418, 340467, 0, 0, 0, 0, 0),
(340418, 340469, 0, 0, 0, 0, 0),
(340418, 340476, 0, 0, 0, 0, 0),
(340418, 340477, 0, 0, 0, 0, 0),
(340418, 340478, 0, 0, 0, 0, 0),
(340418, 340479, 0, 0, 0, 0, 0),
(340492, 340492, 0, 0, 0, 0, 0),
(340492, 340493, 0, 0, 0, 0, 0),
(340492, 340494, 0, 0, 0, 0, 0),
(340492, 340495, 0, 0, 0, 0, 0),
(340492, 340496, 0, 0, 0, 0, 0),
(340492, 340497, 0, 0, 0, 0, 0),
(340492, 340498, 0, 0, 0, 0, 0),
(340492, 340499, 0, 0, 0, 0, 0),
(340492, 340500, 0, 0, 0, 0, 0);

-- Stonecore Flayer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42808;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42808 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42808, 0, 0, 0, 1, 0, 100, 0, 0, 0, 60000, 60000, 17, 438, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Flayer - In Combat - Set emote state 438"),
(42808, 0, 1, 0, 4, 0, 100, 0, 2500, 10000, 10000, 15000, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Flayer - On Aggro - Set emote state 0"),
(42808, 0, 2, 0, 0, 0, 100, 0, 2500, 10000, 10000, 15000, 11, 79922, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Flayer - In Combat - Cast 'Flay'");

-- Stonecore Earthshaper SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 43537;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43537 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(43537, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - On Reset - Set Phase 1"),
(43537, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - Linked - Demorph"),
(43537, 0, 2, 0, 0, 1, 100, 0, 3000, 3000, 10000, 15000, 11, 81576, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - In Combat (Phase 1) - Cast 'Lava Burst'"),
(43537, 0, 3, 4, 0, 1, 100, 0, 9000, 9000, 12000, 12000, 11, 81459, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - In Combat (Phase 1) - Cast 'Force of Earth'"),
(43537, 0, 4, 0, 61, 1, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - Linked - Say Text 0"),
(43537, 0, 5, 0, 0, 1, 100, 0, 15000, 15000, 10000, 15000, 11, 81530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - In Combat (Phase 1) - Cast 'Ground Shock'"),
(43537, 0, 6, 7, 8, 1, 100, 1, 81459, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - Hit by 'Force of Earth' (Phase 1) - Set Phase 2"),
(43537, 0, 7, 0, 61, 1, 100, 1, 81459, 0, 0, 0, 3, 26693, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - Linked - Morph"),
(43537, 0, 8, 0, 0, 2, 100, 0, 5000, 5000, 15000, 15000, 11, 81463, 64, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - In Combat (Phase 2) - Cast 'Dust Storm'"),
(43537, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Earthshaper - On Death - Demorph");
-- TODO: Demorph 3 seconds after death. Need more sniffs for Force of Earth's dummy.

DELETE FROM `creature_text` WHERE `entry` = 43537 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(43537, 0, 0, '%s begins to transform into a Force of Earth!', 16, 0, 100, 0, 0, 0, 46680, 'Stonecore Earthshaper');

-- Stonecore Warbringer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42696;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42696 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42696, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 12000, 12000, 11, 80158, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Stonecore Warbringer - In Combat - Cast 'Rage'"),
(42696, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 8000, 12000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Stonecore Warbringer - In Combat - Cast 'Cleave'");

-- Stonecore Berserker SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 43430;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43430 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(43430, 0, 0, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 81574, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Stonecore Warbringer - In Combat - Cast 'Charge'"),
(43430, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 10000, 20000, 11, 81568, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Warbringer - In Combat - Cast 'Spinning Slash'");

-- Heroic template of Corborus, Flags on creation (from sniffs) 
UPDATE `creature_template` SET `difficulty_entry_1` = 49642, `unit_flags` = 33088 WHERE `entry` = 43438;
DELETE FROM `creature_template` WHERE `entry` = 49642;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(49642, 0, 0, 0, 0, 0, 33477, 0, 0, 0, 'Corborus (1)', '', '', '', 0, 87, 87, 3, 0, 14, 0, 2.8, 1.14286, 1, 1, 0, 2000, 2000, 1, 1, 1, 33088, 2048, 0, 0, 0, 0, 0, 4, 584, 0, 49642, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 35, 1, 1, 1, 1, 1, 1, 0, 52506, 0, 0, 0, 0, 0, 154, 1, 617299839, 1, '', 15595);

-- Corborus loot
UPDATE `creature_template` SET `lootid` = 43438 WHERE `entry` = 43438;
UPDATE `creature_template` SET `lootid` = 49642 WHERE `entry` = 49642;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43438, 49642);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43438, 1, 43400, 100, 0, 1, 0, 1, 1, NULL),
(49642, 1, 43401, 100, 0, 1, 0, 1, 1, NULL);

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43400, 43401);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43400, 55792, 0, 0, 0, 1, 1, 1, 1, NULL),
(43400, 55793, 0, 0, 0, 1, 1, 1, 1, NULL),
(43400, 55794, 0, 0, 0, 1, 1, 1, 1, NULL),
(43400, 55795, 0, 0, 0, 1, 1, 1, 1, NULL),
(43400, 55796, 0, 0, 0, 1, 1, 1, 1, NULL),
(43401, 56328, 0, 0, 0, 1, 1, 1, 1, NULL),
(43401, 56329, 0, 0, 0, 1, 1, 1, 1, NULL),
(43401, 56330, 0, 0, 0, 1, 1, 1, 1, NULL),
(43401, 56331, 0, 0, 0, 1, 1, 1, 1, NULL),
(43401, 56332, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Set UNIT_FLAG_NOT_SELECTABLE to Trashing Charge.
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 43743;

-- Crystalspawn Giant SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42810;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42810 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42810, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 12000, 12000, 11, 81008, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crystalspawn Giant - In Combat - Cast 'Quake'");
-- (42810, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 12000, 12000, 11, ?????, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crystalspawn Giant - In Combat - Cast 'Crystal Shard'");
-- need Stonecore HC sniffs for this spell

-- Remove one Slabhide spawn, only the flying one is needed
DELETE FROM `creature` WHERE `id` = 43214;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(340550, 43214, 725, 0, 0, 3, 1, 0, 0, 0, 0, 1191.1, 1154.01, 270.759, 4.69494, 7200, 0, 0, 1, 0, 0, 0, 0, 0, 0);

-- Heroic template of Slabhide, InhabitType correction
UPDATE `creature_template` SET `difficulty_entry_1` = 49538, `InhabitType` = 7 WHERE `entry` = 43214;
DELETE FROM `creature_template` WHERE `entry` = 49538;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(49538, 0, 0, 0, 0, 0, 36476, 0, 0, 0, 'Slabhide (1)', '', '', '', 0, 87, 87, 3, 0, 16, 0, 2.8, 1.42857, 1, 1, 0, 2000, 2000, 1, 1, 1, 33587264, 2048, 0, 0, 0, 0, 0, 2, 72, 0, 49538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 7, 1.25, 50, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 154, 1, 0, 1, '', 15595);

-- Slabhide loot
UPDATE `creature_template` SET `lootid` = 43214 WHERE `entry` = 43214;
UPDATE `creature_template` SET `lootid` = 49538 WHERE `entry` = 49538;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43214, 49538);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43214, 1, 43402, 100, 0, 1, 0, 1, 1, 'Slabhide N - Reference Loot'),
(49538, 1, 43403, 100, 0, 1, 0, 1, 1, 'Slabhide H - Reference Loot'),
(43214, 63043, 0, 1, 0, 1, 0, 1, 1, 'Slabhide N - Mount Drop'),
(49538, 63043, 0, 1, 0, 1, 0, 1, 1, 'Slabhide H - Mount Drop');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43402, 43403);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43402, 55797, 0, 0, 0, 1, 1, 1, 1, NULL),
(43402, 55798, 0, 0, 0, 1, 1, 1, 1, NULL),
(43402, 55799, 0, 0, 0, 1, 1, 1, 1, NULL),
(43402, 55800, 0, 0, 0, 1, 1, 1, 1, NULL),
(43402, 55801, 0, 0, 0, 1, 1, 1, 1, NULL),
(43403, 56333, 0, 0, 0, 1, 1, 1, 1, NULL),
(43403, 56334, 0, 0, 0, 1, 1, 1, 1, NULL),
(43403, 56335, 0, 0, 0, 1, 1, 1, 1, NULL),
(43403, 56336, 0, 0, 0, 1, 1, 1, 1, NULL),
(43403, 56337, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Set UNIT_FLAG_NOT_SELECTABLE to Stalactite Trigger - Boss, Lava Fissure, .
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (43159, 43242);

-- "Stalactite Trigger - Boss": InhabitType correction
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 43159;

-- Stonecore Magmalord SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42789;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42789 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42789, 0, 0, 0, 0, 0, 100, 0, 4000, 8000, 10000, 20000, 11, 80151, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Stonecore Magmalord - In Combat - Cast '80151'"),
(42789, 0, 1, 0, 0, 0, 100, 0, 8000, 10000, 10000, 20000, 11, 80038, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Magmalord - In Combat - Cast 'Eruption'");

-- Stonecore Rift Conjurer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42691;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42691 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42691, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, 11, 80279, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Stonecore Rift Conjurer - In Combat - Cast 'Shadow Bolt'"),
(42691, 0, 1, 0, 0, 0, 100, 0, 10000, 20000, 20000, 30000, 11, 80308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Rift Conjurer - In Combat - Cast 'Demon Portal'");

-- Imp SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 43014;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43014 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(43014, 0, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 80344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Imp - In Combat - Cast 'Fel Firebolt'");

-- Stonecore Bruiser SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42692;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42692 AND `source_type` = 0 OR `entryorguid` = 4269200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42692, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 13000, 15000, 80, 4269200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Bruiser - In Combat - Start Actionlist"),
(4269200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 80180, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Stonecore Bruiser - Actionlist- Cast 'Body Slam'"),
(4269200, 9, 1, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 11, 80180, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Stonecore Bruiser - Actionlist - Cast 'Body Slam' again"),
(4269200, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 11, 80180, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Stonecore Bruiser - Actionlist - Cast 'Body Slam' again"),
(42692, 0, 1, 0, 0, 0, 100, 0, 14000, 18000, 14000, 18000, 11, 80195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stonecore Bruiser - In Combat - Cast 'Shockwave'");

-- Heroic template of Ozruk 
UPDATE `creature_template` SET `difficulty_entry_1` = 49654 WHERE `entry` = 42188;
DELETE FROM `creature_template` WHERE `entry` = 49654;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(49654, 0, 0, 0, 0, 0, 36475, 0, 0, 0, 'Ozruk (1)', '', '', '', 0, 87, 87, 3, 0, 14, 0, 1, 1.5873, 1, 1, 0, 2000, 2000, 1, 1, 1, 32832, 134219776, 0, 0, 0, 0, 0, 5, 584, 0, 49654, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 867, 0, 0, '', 0, 3, 1, 40, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 617299839, 1, '', 15595);

-- Ozruk texts
DELETE FROM `creature_text` WHERE `entry` = 42188;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(42188, 0, 0, 'None may pass into the World''s Heart!', 14, 0, 100, 0, 0, 21919, 0, 0, 'Ozruk to Player'),
(42188, 1, 0, '|TInterface\\Icons\\ability_warrior_shieldreflection.blp:20|tOzruk casts |cFFFF0000|Hspell:78939|h[Elementium Bulwark]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Ozruk'),
(42188, 2, 0, 'Break yourselves upon my body. Feel the strength of the earth!', 14, 0, 100, 0, 0, 21921, 0, 0, 'Ozruk'),
(42188, 3, 0, '%s becomes enraged!', 41, 0, 100, 0, 0, 0, 0, 0, 'Ozruk'),
(42188, 4, 0, 'A protector has fallen. The World''s Heart lies exposed!', 14, 0, 100, 0, 0, 21922, 0, 0, 'Ozruk to Player');

-- Ozruk loot
UPDATE `creature_template` SET `lootid` = 42188 WHERE `entry` = 42188;
UPDATE `creature_template` SET `lootid` = 49654 WHERE `entry` = 49654;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (42188, 49654);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(42188, 1, 43404, 100, 0, 1, 0, 1, 1, 'Ozruk N - Reference Loot'),
(49654, 1, 43405, 100, 0, 1, 0, 1, 1, 'Ozruk H - Reference Loot');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43404, 43405);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43404, 55802, 0, 0, 0, 1, 1, 1, 1, NULL),
(43404, 55803, 0, 0, 0, 1, 1, 1, 1, NULL),
(43404, 55804, 0, 0, 0, 1, 1, 1, 1, NULL),
(43404, 55810, 0, 0, 0, 1, 1, 1, 1, NULL),
(43404, 55811, 0, 0, 0, 1, 1, 1, 1, NULL),
(43405, 56338, 0, 0, 0, 1, 1, 1, 1, NULL),
(43405, 56339, 0, 0, 0, 1, 1, 1, 1, NULL),
(43405, 56340, 0, 0, 0, 1, 1, 1, 1, NULL),
(43405, 56341, 0, 0, 0, 1, 1, 1, 1, NULL),
(43405, 56342, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Set UNIT_FLAG_NOT_SELECTABLE to Rupture Controller and Rupture.
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (49597, 49576);

-- Heroic template of High Priestess Azil 
UPDATE `creature_template` SET `difficulty_entry_1` = 49624 WHERE `entry` = 42333;
DELETE FROM `creature_template` WHERE `entry` = 49624;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(49624, 0, 0, 0, 0, 0, 26448, 0, 0, 0, 'High Priestess Azil (1)', '', '', '', 0, 84, 84, 3, 0, 14, 2, 1.2, 1.42857, 1, 1, 0, 2000, 2000, 1, 1, 1, 32832, 2048, 0, 0, 0, 0, 0, 7, 72, 0, 49624, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 903, 0, 0, '', 0, 3, 1, 30, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 721, 1, 617299839, 1, '', 15595);

-- "Stalactite Trigger - Boss": InhabitType correction
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` IN (42333, 49624);

-- High Priestess Azil texts
DELETE FROM `creature_text` WHERE `entry` = 42333;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(42333, 0, 0, 'The world will be reborn in flames!', 14, 0, 100, 0, 0, 21634, 0, 0, 'High Priestess Azil to Player'),
(42333, 1, 0, 'Witness the power bestowed upon me by Deathwing! Feel the fury of earth!', 14, 0, 100, 0, 0, 21628, 0, 0, 'High Priestess Azil to High Priestess Azil'),
(42333, 2, 0, 'For my death, countless more will fall. The burden is now yours to bear.', 14, 0, 100, 0, 0, 21633, 0, 0, 'High Priestess Azil to Player');

-- High Priestess Azil loot
UPDATE `creature_template` SET `lootid` = 42333 WHERE `entry` = 42333;
UPDATE `creature_template` SET `lootid` = 49624 WHERE `entry` = 49624;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (42333, 49624);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(42333, 1, 43406, 100, 0, 1, 0, 1, 1, 'High Priestess Azil N - Reference Loot'),
(49624, 1, 43407, 100, 0, 1, 0, 1, 1, 'High Priestess Azil H - Reference Loot'),
(49624, 52078, 0, 100, 0, 1, 0, 1, 1, 'High Priestess Azil H - Chaos Orb');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43406, 43407);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43406, 55812, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55813, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55814, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55815, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55816, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55817, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55818, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55819, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55820, 0, 0, 0, 1, 1, 1, 1, NULL),
(43406, 55821, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56343, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56344, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56345, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56346, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56347, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56348, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56349, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56350, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56351, 0, 0, 0, 1, 1, 1, 1, NULL),
(43407, 56352, 0, 0, 0, 1, 1, 1, 1, NULL);

DELETE FROM `spell_target_position` WHERE `id` IN (79193, 79199, 86860, 86858, 86856);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES
(79193, 0, 725, 1260, 960, 205.443756, 0, 0),
(79199, 0, 725, 1280, 1050, 210.383057, 0, 0),
(86860, 0, 725, 1350.75, 919.133, 194.769, 0, 0),
(86858, 0, 725, 1341.19, 913.399, 197.092, 0, 0),
(86856, 0, 725, 1361.89, 920.219, 196.308, 0, 0);

-- Set UNIT_FLAG_NOT_SELECTABLE to Gravity Well and Seismic Shard.
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (42499, 42355);
