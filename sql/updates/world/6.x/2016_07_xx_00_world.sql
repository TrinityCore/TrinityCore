-- Added missing spellscript (generic berserk spell)
DELETE FROM `spell_script_names` WHERE `spell_id` = 26662;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26662, 'spell_gen_berserk');
