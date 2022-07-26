--
DELETE FROM `game_event` WHERE `eventEntry`=85;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`, `description`, `world_event`, `announce`) VALUES (85, '2010-01-01 02:00:00', '2030-12-31 07:00:00', 60, 1, 0, 0, 'Honor Hold Hellfire', 0, 2);
