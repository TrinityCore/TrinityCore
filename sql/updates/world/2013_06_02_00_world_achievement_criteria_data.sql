DELETE FROM `disables` WHERE `sourceType` IN (10082,10083,10084,10085,10086,10087);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10082,10083,10084,10085,10086,10087);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10082, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10082, 12, 0, 0, ''),
(10083, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10083, 12, 0, 0, ''),
(10084, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10084, 12, 0, 0, ''),
(10085, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10085, 12, 1, 0, ''),
(10086, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10086, 12, 1, 0, ''),
(10087, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10087, 12, 1, 0, '');