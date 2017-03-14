-- Class: Warrior
-- Spect: Arm, Protection
-- Spell: Impending Victory

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_impending_victory';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('202168', 'spell_warr_impending_victory');