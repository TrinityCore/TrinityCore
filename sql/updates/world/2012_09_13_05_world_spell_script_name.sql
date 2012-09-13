-- Add spell script name for Skyguard Blasting Charge
DELETE FROM `spell_script_names` WHERE `spell_id`=39844;
INSERT INTO `spell_script_names` VALUES
(39844,'spell_q11008_blasting_charge');