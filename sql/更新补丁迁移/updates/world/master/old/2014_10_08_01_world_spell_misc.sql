delete from spell_script_names where ScriptName = 'spell_mage_glyph_of_conjure_familiar';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (126578, 'spell_mage_glyph_of_conjure_familiar');

delete from spell_talent_linked_spell where spellid in (-126748, 126748);
INSERT INTO `spell_talent_linked_spell` (`spellid`, `spelllink`, `type`, `target`, `caster`, `comment`) VALUES 
(-126748, -126578, 1, 0, 0, 'Снятие Символ призыва фамилиара'),
(126748, 126578, 1, 0, 0, 'Символ призыва фамилиара');