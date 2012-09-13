-- Add spell script name for Knockdown Fel Cannon: The Aggro Check Aura
DELETE FROM `spell_script_names` WHERE `spell_id`=40113;
INSERT INTO `spell_script_names` VALUES
(40113,'spell_q11010_q11102_q11023_aggro_check_aura');