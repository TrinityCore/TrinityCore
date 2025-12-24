--
DELETE FROM `creature_formations` WHERE `leaderGUID` = 7483;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(7483,7483,0,0,3,0,0),
(7483,81643,0,0,3,0,0),
(7483,48348,0,0,3,0,0),
(7483,81652,0,0,3,0,0),
(7483,81651,0,0,3,0,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gruul_gronn_lords_grasp';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(33572, 'spell_gruul_gronn_lords_grasp');
