DELETE FROM `spell_script_names` where `ScriptName` IN ('spell_fel_streak_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66493,'spell_fel_streak_visual');

DELETE FROM `creature_template_addon` WHERE `entry` IN (34815,35262,35263,35264);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34815,0,0,0,1,0,'66327'),
(35262,0,0,0,1,0,'66327'),
(35263,0,0,0,1,0,'66327'),
(35264,0,0,0,1,0,'66327');
