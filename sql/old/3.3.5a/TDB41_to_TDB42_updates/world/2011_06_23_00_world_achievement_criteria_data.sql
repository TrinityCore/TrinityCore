DELETE FROM `disables` WHERE `entry`=7317 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7317 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7317,11,0,0,'achievement_respect_your_elders');
