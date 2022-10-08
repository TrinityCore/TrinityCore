update spell_proc_event set cooldown = 5 where entry = 34477;
delete from spell_linked_spell where spell_trigger = '-35079' and spell_effect = '-34477';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(-35079, -34477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Hunter - Remove Misdirection');

delete from spell_script_names where spell_id in (34477, 110588);