DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry` IN (63989,63997,63998);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=34072;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34072, 51347, 3, 0);
