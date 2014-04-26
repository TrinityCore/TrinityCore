DELETE FROM `game_event` `eventEntry` IN (65,66,67,68);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(65, '2011-11-20 00:01:00', '2011-12-03 23:59:00', 525600, 336, 467, 'WoW''s 7th Anniversary', 0, 2),
(66, '2012-11-18 00:01:00', '2012-12-01 23:59:00', 525600, 336, 484, 'WoW''s 8th Anniversary', 0, 2),
(67, '2013-11-18 00:01:00', '2013-12-01 23:59:00', 525600, 336, 0/*509*/, 'WoW''s 9th Anniversary', 0, 2),
(68, '2014-11-17 00:01:00', '2014-12-01 23:59:00', 525600, 336, 0/*514*/, 'WoW''s 10th Anniversary', 0, 2);
