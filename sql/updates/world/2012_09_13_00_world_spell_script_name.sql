-- Add spell script name for Knockdown Fel Cannon: Choose Loc
DELETE FROM `spell_script_names` WHERE `spell_id`=40056;
INSERT INTO `spell_script_names` VALUES
(40056,'spell_q11010_q11102_q11023_choose_loc');