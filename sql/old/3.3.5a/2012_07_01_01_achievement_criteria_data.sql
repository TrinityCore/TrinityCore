DELETE FROM `disables` WHERE `entry` IN (7626,7634) AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7626,7634);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7626, 11, 0, 0, 'achievement_not_even_a_scratch'),
(7634, 11, 0, 0, 'achievement_not_even_a_scratch');
