DELETE FROM `disables` WHERE `entry`=7320 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7320 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7320,11,0,0,'achievement_dehydration');
