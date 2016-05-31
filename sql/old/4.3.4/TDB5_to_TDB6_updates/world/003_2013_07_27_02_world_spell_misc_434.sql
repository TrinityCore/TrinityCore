DELETE FROM `spell_script_names` WHERE `spell_id`=118;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(118,'spell_mage_polymorph');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=83046;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(83046, 83046, 1),
(83046, 83047, 2);
