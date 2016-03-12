-- The Stonecore updates
-- Spell conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (93167, 86862, 86863);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 93167, 0, 0, 31, 0, 3, 40350, 0, 0, 0, 0, '', 'Twilight Documents targets Generic Trigger LAB'),
(13, 1, 86862, 0, 0, 31, 0, 3, 42355, 0, 0, 0, 0, '', 'Seismic Shard targets Seismic Shards'),
(13, 1, 86862, 0, 0, 1, 0, 79009, 0, 0, 0, 0, 0, '', 'Seismic Shard''s target must have SPELL_SEISMIC_SHARD_VISUAL aura'),
(13, 1, 86863, 0, 0, 31, 0, 3, 42333, 0, 0, 0, 0, '', 'Seismic Shard targets High Priestess Azil');

-- Set CREATURE_FLAG_EXTRA_TRIGGER to Stonecore Teleporters, Lava Fissure, Stalactite Trigger - Boss, Rupture Controller, Rupture, Gravity Well, Seismic Shard
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` IN (51396, 51397, 43242, 43159, 49597, 49576, 42499, 42355);

-- Stonecore Teleporters
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (51396, 51397);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51396, 95284, 3, 0),
(51397, 95285, 3, 0);

DELETE FROM `spell_target_position` WHERE `id` IN (95284, 95285);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES
(95284, 0, 725, 1313.26, 1236.833, 247.2859, 0, 0),
(95285, 0, 725, 853.8577, 999.7518, 317.3986, 0, 0);

-- Remove cpp script from Seismic Shard (86862) spell
DELETE FROM `spell_script_names` WHERE `spell_id` = 86862;
