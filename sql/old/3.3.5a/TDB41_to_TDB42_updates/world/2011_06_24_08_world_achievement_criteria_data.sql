DELETE FROM `disables` WHERE `entry`=7361 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7361 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7361,11,0,0,'achievement_oh_novos');
