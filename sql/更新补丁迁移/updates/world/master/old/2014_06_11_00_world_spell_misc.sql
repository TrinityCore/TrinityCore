delete from spell_group where spell_id = 111923;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES 
(1250, 111923);

delete from spell_linked_spell where spell_trigger = 111922 and spell_effect = 111923;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(111922, 111923, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Runescroll of Fortitude III');