--
DELETE FROM `game_event` WHERE `eventEntry` = 66;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES
(66, '2012-02-11 00:00:00', '2020-02-11 00:00:00', 10080, 2880, 0, 'Weekend XP Bonus', 0);
