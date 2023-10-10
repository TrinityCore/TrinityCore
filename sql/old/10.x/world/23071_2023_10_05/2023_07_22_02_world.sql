DELETE FROM `spell_custom_attr` WHERE `entry`=184689;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(184689,0x8); -- SPELL_ATTR0_CU_SHARE_DAMAGE

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_shield_of_vengeance');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(184662,'spell_pal_shield_of_vengeance');
