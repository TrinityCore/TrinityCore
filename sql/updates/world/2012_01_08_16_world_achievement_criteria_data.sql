-- The Incredible Hulk achievement 2043
DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` = 7322;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7322 AND `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
('7322', '11', '0', '0', 'achievement_incredible_hulk');
