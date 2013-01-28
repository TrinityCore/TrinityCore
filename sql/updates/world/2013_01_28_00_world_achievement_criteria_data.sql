
-- Was (12979, 12, 1, 0, '')
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12979 AND `type` = 12;

-- Was (12971, 12, 2, 0, '')
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12971 AND `type` = 12;


INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`)
VALUES
(12979, 12, 2, 0, ''),
(12971, 12, 1, 0, '');
