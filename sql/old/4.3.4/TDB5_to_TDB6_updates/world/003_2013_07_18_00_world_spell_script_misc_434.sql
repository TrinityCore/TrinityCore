DELETE FROM `spell_script_names` WHERE `spell_id` IN (-31641,50421,-30881);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-31641,'spell_mage_blazing_speed'),
(50421,'spell_dk_scent_of_blood'),
(-30881,'spell_sha_nature_guardian');

DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (31641,30881);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(31641, 31641, 1),
(31641, 31642, 2),
(30881, 30881, 1),
(30881, 30883, 2),
(30881, 30884, 3);

DELETE FROM `spell_proc_event` WHERE `entry` IN (30881,30883,30884);
