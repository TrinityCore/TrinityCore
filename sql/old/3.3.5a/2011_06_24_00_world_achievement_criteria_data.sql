DELETE FROM `disables` WHERE `entry`=6803 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=6803 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(6803,11,0,0,'achievement_defenseless');
