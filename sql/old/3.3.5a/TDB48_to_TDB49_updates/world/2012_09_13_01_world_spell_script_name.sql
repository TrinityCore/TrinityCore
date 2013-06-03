-- Add spell script name for Fires Over Skettis and Bombing Run quests
DELETE FROM `spell_script_names` WHERE `spell_id`=40113;
DELETE FROM `spell_script_names` WHERE `spell_id`=40160;
DELETE FROM `spell_script_names` WHERE `spell_id`=39844;
DELETE FROM `spell_script_names` WHERE `spell_id`=40056;
DELETE FROM `spell_script_names` WHERE `spell_id`=40112;
DELETE FROM `spell_script_names` WHERE `spell_id`=40119;
INSERT INTO `spell_script_names` VALUES
(39844,'spell_q11010_q11102_q11023_q11008_check_fly_mount'),
(40160,'spell_q11010_q11102_q11023_q11008_check_fly_mount'),
(40113,'spell_q11010_q11102_q11023_aggro_check_aura'),
(40056,'spell_q11010_q11102_q11023_choose_loc'),
(40112,'spell_q11010_q11102_q11023_aggro_check'),
(40119,'spell_q11010_q11102_q11023_aggro_burst');
