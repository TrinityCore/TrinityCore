DELETE FROM `spell_script_names` WHERE `spell_id` IN (-11175);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-11175,'spell_mage_permafrost');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=11175;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(11175, 11175, 1),
(11175, 12569, 2),
(11175, 12571, 3);

DELETE FROM `spell_bonus_data` WHERE `entry`=91394;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(91394, 0, 0, 0, 0, 'Mage - Permafrost');
