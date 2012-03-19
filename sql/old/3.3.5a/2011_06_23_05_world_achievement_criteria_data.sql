DELETE FROM `disables` WHERE `entry`=4240 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=4240 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(4240,11,0,0,'achievement_watch_him_die');
