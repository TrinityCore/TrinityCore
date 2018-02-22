UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (48975, 49039, 49040, 48976, 49041, 49042);
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_glubtok_fire_wall';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91398 ,'spell_glubtok_fire_wall');
