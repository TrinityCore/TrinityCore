-- Add spell script name for Knockdown Fel Cannon: The Aggro Check
DELETE FROM `spell_script_names` WHERE `spell_id`=40112;
INSERT INTO `spell_script_names` VALUES
(40112,'spell_q11010_q11102_q11023_aggro_check');