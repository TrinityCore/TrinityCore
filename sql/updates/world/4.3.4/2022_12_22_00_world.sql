DELETE FROM `game_event` WHERE `eventEntry` IN (84, 85, 86);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `description`) VALUES
(84, null, null, 5184000, 2592000, 'Arena Season 9'),
(85, null, null, 5184000, 2592000, 'Arena Season 10'),
(86, null, null, 5184000, 2592000, 'Arena Season 11');

DELETE FROM `game_event_arena_seasons` WHERE `eventEntry` IN (84, 85, 86);
INSERT INTO `game_event_arena_seasons` (`eventEntry`, `season`) VALUES
(84, 9),
(85, 10),
(86, 11);
