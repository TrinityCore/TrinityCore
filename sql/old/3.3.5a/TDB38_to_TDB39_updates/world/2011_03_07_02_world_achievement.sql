DELETE FROM `disables` WHERE `entry`=7622 AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7622;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7622,0,0,0, '');
