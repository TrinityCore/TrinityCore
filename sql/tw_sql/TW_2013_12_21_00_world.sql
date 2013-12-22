-- Implements My Girl Loves to Skadi All the Ime (2156)
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7595;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`,
`value1`, `value2`, `ScriptName`) VALUES
(7595, 11, 0, 0, "TW_achievement_my_girl_loves_to_skadi_all_the_time");

DELETE FROM `disables` WHERE `entry` = 7595 AND `SourceType` = 4;
