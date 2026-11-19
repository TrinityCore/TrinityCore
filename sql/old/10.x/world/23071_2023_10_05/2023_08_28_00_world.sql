DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_holy_word_salvation', 'spell_pri_holy_word_salvation_cooldown_reduction');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(265202, 'spell_pri_holy_word_salvation'),
(2050, 'spell_pri_holy_word_salvation_cooldown_reduction'),
(34861, 'spell_pri_holy_word_salvation_cooldown_reduction');
