DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (7608,7609);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7608,7609);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7608,12,0,0, ''),
(7608,13,8,0, ''),
(7609,12,1,0, ''),
(7609,13,20,0, '');
