UPDATE `achievement_criteria_data` SET `value2` = 3 WHERE `type`=8 AND `criteria_id` IN (2358, 2412, 3384);
UPDATE `achievement_criteria_data` SET `type` = 0 WHERE `type`=8 AND `criteria_id` IN (12066, 12067, 12132);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (4944,4946,4948,4949,4950,4951,4952,4953,4954,4955,4956,4957,4958);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(4944, 0, 0,  0, ''), -- no criteria data
(4946,11, 0,  0, 'achievement_killed_exp_or_honor_target'),
(4948, 8, 1,  0, ''), -- Beast
(4949, 8, 3,  0, ''), -- Dragonkin
(4950, 8, 2,  0, ''), -- drachkin
(4951, 8, 4,  0, ''), -- Elemental
(4952, 8, 5,  0, ''), -- Giant
(4953, 8, 7,  0, ''), -- Humanoid
(4954, 8, 9,  0, ''), -- Mechanical
(4955, 8, 6,  0, ''), -- Undead
(4956, 8, 10, 0, ''), -- Not specified
(4957, 8, 11, 0, ''), -- Totem
(4958, 8, 12, 0, ''); -- Non-Combat Pet
