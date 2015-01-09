DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_will_of_the_necropolis';
DELETE FROM `spell_script_names` WHERE `spell_id`=-52284;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-52284,'spell_dk_will_of_the_necropolis');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=52284;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(52284, 52284, 1),
(52284, 81163, 2),
(52284, 81164, 3);
