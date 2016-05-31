DELETE FROM `spell_script_names` WHERE `spell_id` IN (-53228);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-53228,'spell_hun_rapid_recuperation');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=53228;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(53228, 53228, 1),
(53228, 53232, 2);
