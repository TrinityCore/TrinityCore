DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (1237,1240,1241);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(1237, 0, 0, 0, ''), -- Achievement: Let's Get This Done
(1240, 0, 0, 0, ''), -- Achievement: Flurry
(1241, 0, 0, 0, ''); -- Achievement: The Alterac Blitz
