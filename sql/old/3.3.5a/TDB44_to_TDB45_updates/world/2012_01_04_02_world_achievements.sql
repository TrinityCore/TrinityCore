-- The Undying
DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` IN (13237, 13238, 13239, 13240, 7617); -- Enable criteria
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (13237, 13238, 13239, 13240, 7617); -- Enable instance script execution for achievement criteria
INSERT INTO `achievement_criteria_data` VALUES
(13237, 12, 0, 0, ''),
(13237, 18, 0, 0, ''),
(13238, 12, 0, 0, ''),
(13238, 18, 0, 0, ''),
(13239, 12, 0, 0, ''),
(13239, 18, 0, 0, ''),
(13240, 12, 0, 0, ''),
(13240, 18, 0, 0, ''),
(7617, 12, 0, 0, ''),
(7617, 18, 0, 0, '');

-- The Immortal
DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` IN (13233, 13234, 13235, 13236, 7616); -- Enable criteria
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (13233, 13234, 13235, 13236, 7616); -- Enable instance script execution for achievement criteria
INSERT INTO `achievement_criteria_data` VALUES
(13233, 12, 1, 0, ''),
(13233, 18, 0, 0, ''),
(13234, 12, 1, 0, ''),
(13234, 18, 0, 0, ''),
(13235, 12, 1, 0, ''),
(13235, 18, 0, 0, ''),
(13236, 12, 1, 0, ''),
(13236, 18, 0, 0, ''),
(7616, 12, 1, 0, ''),
(7616, 18, 0, 0, '');
