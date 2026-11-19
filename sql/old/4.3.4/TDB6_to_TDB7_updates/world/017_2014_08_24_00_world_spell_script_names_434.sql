-- 53600 - Shield of the Righteous
-- Delete old (wotlk) scaling
DELETE FROM `spell_bonus_data` WHERE `entry`=53600;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_shield_of_the_righteous';
INSERT INTO `spell_script_names` VALUES
(53600,'spell_pal_shield_of_the_righteous');
