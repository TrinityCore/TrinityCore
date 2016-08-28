--
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (6140, 6141, 6142);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6140, 24, 4, 0, ""),
(6141, 24, 5, 0, ""),
(6142, 24, 4, 0, "");

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` BETWEEN 4768 AND 4786;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` BETWEEN 4768 AND 4786;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(4768, 24, 4, 0, ""),
(4769, 24, 4, 0, ""),
(4770, 24, 4, 0, ""),
(4771, 24, 4, 0, ""),
(4772, 24, 4, 0, ""),
(4773, 24, 4, 0, ""),
(4774, 24, 4, 0, ""),
(4775, 24, 4, 0, ""),
(4776, 24, 4, 0, ""),
(4777, 24, 4, 0, ""),
(4778, 24, 4, 0, ""),
(4779, 24, 4, 0, ""),
(4780, 24, 4, 0, ""),
(4781, 24, 4, 0, ""),
(4782, 24, 4, 0, ""),
(4783, 24, 4, 0, ""),
(4784, 24, 4, 0, ""),
(4785, 24, 4, 0, ""),
(4786, 24, 4, 0, "");
