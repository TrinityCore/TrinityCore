-- Add spell script name for Trhow Bomb
DELETE FROM `spell_script_names` WHERE `spell_id`=40160;
INSERT INTO `spell_script_names` VALUES
(40160,'spell_q11010_q11102_q11023_throw_bomb');