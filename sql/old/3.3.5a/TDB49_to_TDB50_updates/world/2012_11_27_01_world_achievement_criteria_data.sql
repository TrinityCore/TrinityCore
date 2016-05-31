DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=7321;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7321;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7321,11,0,0,'achievement_shatter_resistant'),
(7321,12,1,0,'');
