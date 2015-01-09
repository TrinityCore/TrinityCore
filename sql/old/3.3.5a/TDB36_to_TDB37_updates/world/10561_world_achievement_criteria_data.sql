DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12780,13012,13011,13013) AND `type` IN (0,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(12780,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13012,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13011,11,0,0, 'achievement_once_bitten_twice_shy_v'),
(13013,11,0,0, 'achievement_once_bitten_twice_shy_v');
