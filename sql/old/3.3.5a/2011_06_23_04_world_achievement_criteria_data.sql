DELETE FROM `disables` WHERE `entry`=7136 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7136 AND `type`=5;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7136,5,55817,0,'');
