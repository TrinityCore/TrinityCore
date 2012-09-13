-- Add spell script name for Knockdown Fel Cannon: The Aggro Burst
DELETE FROM `spell_script_names` WHERE `spell_id`=40119;
INSERT INTO `spell_script_names` VALUES
(40119,'spell_q11010_q11102_q11023_aggro_burst');