-- Achievement Fa-la-la-la-Ogri'la 
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3936,3937,3938);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
-- requires aura
(3936, 5, 44827, 0, ''),
(3937, 5, 44825, 0, ''),
(3938, 5, 44824, 0, ''),
-- requires Holiday Winter Veil
(3936, 16, 141, 0, ''),
(3937, 16, 141, 0, ''),
(3938, 16, 141, 0, '');
