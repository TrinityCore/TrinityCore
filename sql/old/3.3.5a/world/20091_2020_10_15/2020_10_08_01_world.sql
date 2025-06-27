--
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=10279;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10279,18,0,0,''),
(10279,12,1,0,'');
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=10279;
