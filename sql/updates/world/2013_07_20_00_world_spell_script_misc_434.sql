DELETE FROM `spell_script_names` WHERE `spell_id` IN (-48979);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-48979,'spell_dk_butchery');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=48979;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(48979, 48979, 1),
(48979, 49483, 2);
