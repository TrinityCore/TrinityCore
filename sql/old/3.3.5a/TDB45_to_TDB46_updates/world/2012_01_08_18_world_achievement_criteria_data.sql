-- Lightning Struck achievement
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=6835;
DELETE FROM `achievement_criteria_data` WHERE `type`=11 AND `criteria_id`=6835;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6835, 11, 0, 0, 'achievement_lightning_struck');
