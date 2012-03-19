DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7604, 7605) AND `type` IN (18,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7604,11,0,0, 'achievement_polarity_switch'),
(7605,11,0,0, 'achievement_polarity_switch');
