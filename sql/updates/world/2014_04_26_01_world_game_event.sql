DELETE FROM `game_event` WHERE `eventEntry` IN (65,66,67,68,69,70,71);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(65, '2008-11-23 00:01:00', '2008-11-23 23:59:00', 525600, 1440, 0, 'WoW''s 4th Anniversary', 0, 2),
(66, '2009-11-22 00:01:00', '2009-12-06 23:59:00', 525600, 10080, 0, 'WoW''s 5th Anniversary', 0, 2),
(67, '2010-11-30 00:01:00', '2010-12-14 23:59:00', 525600, 10080, 0, 'WoW''s 6th Anniversary', 0, 2),
(68, '2011-11-20 00:01:00', '2011-12-03 23:59:00', 525600, 10080, 467, 'WoW''s 7th Anniversary', 0, 2),
(69, '2012-11-18 00:01:00', '2012-12-01 23:59:00', 525600, 10080, 484, 'WoW''s 8th Anniversary', 0, 2),
(70, '2013-11-18 00:01:00', '2013-12-01 23:59:00', 525600, 10080, 0/*509*/, 'WoW''s 9th Anniversary', 0, 2),
(71, '2014-11-17 00:01:00', '2014-12-01 23:59:00', 525600, 10080, 0/*514*/, 'WoW''s 10th Anniversary', 0, 2);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (9058, 12562,16082,17804,18500);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(9058, 23, 65, 0, ''), -- WoW''s 4th Anniversary'
(12562, 23, 66, 0, ''), -- WoW''s 5th Anniversary
(16082, 23, 67, 0, ''), -- WoW''s 6th Anniversary
(17804, 16, 467, 0, ''), -- WoW''s 7th Anniversary
(18500, 16, 484, 0, ''); -- WoW''s 8th Anniversary
