DELETE FROM `spell_script_names` WHERE `spell_id` IN (-31571,-51664);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-31571,'spell_mage_arcane_potency'),
(-51664,'spell_rog_cut_to_the_chase');

DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (31571,51664);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(31571, 31571, 1),
(31571, 31572, 2),
(51664, 51664, 1),
(51664, 51665, 2),
(51664, 51667, 3);
