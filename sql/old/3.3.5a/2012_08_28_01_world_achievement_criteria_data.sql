DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11478,11479,12827,12828);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(11478, 12, 0, 0, ''), -- Koralon the Flame Watcher (10 player)
(11479, 12, 1, 0, ''), -- Koralon the Flame Watcher (25 player)
(12827, 12, 0, 0, ''), -- Toravon the Ice Watcher (10 player)
(12828, 12, 1, 0, ''); -- Toravon the Ice Watcher (25 player)
