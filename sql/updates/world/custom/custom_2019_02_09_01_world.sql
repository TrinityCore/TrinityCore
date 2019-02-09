DELETE FROM `spell_bonus_data` WHERE `entry`= 85673;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_light_of_dawn';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85222, 'spell_pal_light_of_dawn');
