-- Class: Priest, spec: All
-- Spell: Power Word: Shield
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_power_word_shield';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (17, 'spell_pri_power_word_shield');
