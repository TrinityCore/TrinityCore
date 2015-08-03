-- Delete the criteria from the disables table
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=3880;

-- criteria data for achievement Not So Fast
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3880;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `TYPE`, `value1`, `value2`, `ScriptName`) VALUES
(3880,6,3277,0, ''),
(3880,7,23451,0, '');
