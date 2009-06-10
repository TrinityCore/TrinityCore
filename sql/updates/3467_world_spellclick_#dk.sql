ALTER TABLE `npc_spellclick_spells`
  ADD COLUMN `quest_status` int(11) UNSIGNED NOT NULL DEFAULT 3 COMMENT 'Quest status: 3 incompleted, 1 completed/rewarded' AFTER `quest_id`;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN ('29501', '29488');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
('29488', '54568', '12670', '1', '3'),
('29501', '54575', '12670', '1', '3');

