ALTER TABLE `npc_spellclick_spells` DROP COLUMN `quest_status`;
ALTER TABLE `npc_spellclick_spells` ADD `aura_required` INT(11) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'player without aura cant click' AFTER `cast_flags`;
ALTER TABLE `npc_spellclick_spells` ADD `aura_forbidden` INT(11) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'player with aura cant click' AFTER `aura_required`;
ALTER TABLE `npc_spellclick_spells` ADD `user_type` SMALLINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'relation with summoner: 0-no 1-friendly 2-raid 3-party player can click' AFTER `aura_forbidden`;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(31883, 31893, 31894, 31895, 31896, 31897);
INSERT INTO `npc_spellclick_spells` (npc_entry, spell_id, quest_start, quest_start_active, quest_end, cast_flags, aura_required, aura_forbidden, user_type) VALUES
(31883, 60123, 0, 0, 0, 0x2, 0, 48085, 2),
(31893, 60123, 0, 0, 0, 0x2, 0, 48084, 2),
(31894, 60123, 0, 0, 0, 0x2, 0, 28276, 2),
(31895, 60123, 0, 0, 0, 0x2, 0, 27874, 2),
(31896, 60123, 0, 0, 0, 0x2, 0, 27873, 2),
(31897, 60123, 0, 0, 0, 0x2, 0, 7001, 2);

DELETE FROM `spell_bonus_data` WHERE `entry` IN(7001);
REPLACE INTO `spell_bonus_data` (entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus, comments) VALUES
(7001, -1, 0.3333, -1, -1, 'Priest - Lightwell Renew Rank 1');
