--
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (51101,51102,51103);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(51101, 41020, 1),
(51102, 41020, 1),
(51103, 41020, 1);
