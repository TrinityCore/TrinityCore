DELETE FROM `disables` WHERE `entry`=7579 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7579 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7579,11,0,0,'achievement_consumption_junction');
