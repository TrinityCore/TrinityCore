UPDATE `creature_template` SET `ScriptName` = 'npc_lightwell' WHERE `entry` IN (31883, 31893, 31894, 31895, 31896, 31897);

REPLACE INTO `npc_spellclick_spells` (npc_entry, spell_id, quest_start, quest_start_active, quest_end, cast_flags, quest_status) VALUES
(31883, 60123, 0, 0, 0, 2, 0),
(31893, 60123, 0, 0, 0, 2, 0),
(31894, 60123, 0, 0, 0, 2, 0),
(31895, 60123, 0, 0, 0, 2, 0),
(31896, 60123, 0, 0, 0, 2, 0),
(31897, 60123, 0, 0, 0, 2, 0);

REPLACE INTO `spell_bonus_data` (entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus, comments) VALUES
(7001, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 1'),
(27873, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 2'),
(27874, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 3'),
(28276, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 4'),
(48084, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 5'),
(48085, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 6');

REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-59907,     7, 0, 'Lightwell Charges - Suicide');