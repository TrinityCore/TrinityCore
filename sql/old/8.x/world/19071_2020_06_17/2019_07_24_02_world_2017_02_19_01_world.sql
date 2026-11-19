UPDATE `gameobject_template` SET `ScriptName`='go_bells' WHERE `entry` IN (175885, 176573, 182064);

DELETE FROM `game_event` WHERE `eventEntry`=73;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(73, '2010-01-01 01:00:00', '2025-01-01 01:00:00', 60, 1, 0, 'Hourly Bells', 0, 2);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=73;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
-- (73, 45022), -- Horde Bell
-- (73, 20802),
-- (73, 18103),
-- (73, 18102),
-- (73, 18101),
-- (73, 18100),
-- (73, 18099),
-- (73, 18098),
-- (73, 18097),
-- (73, 15508),
-- (73, 12439),
-- (73, 12438),
-- (73, 12437),
(73, 18683),
-- (73, 12436),
-- (73, 12435),
-- (73, 42666), -- Alliance Bell
-- (73, 42905),
-- (73, 42906),
-- (73, 42924),
-- (73, 48107),
-- (73, 49811),
-- (73, 94),
-- (73, 619),
-- (73, 870),
-- (73, 1140),
-- (73, 4841),
-- (73, 6867),
-- (73, 20801),
-- (73, 9114),
-- (73, 9104),
-- (73, 14562),
(73, 18894),
-- (73, 18901),
-- (73, 18906),
-- (73, 26283),
-- (73, 26414),
-- (73, 26426),
-- (73, 26435),
-- (73, 26469),
-- (73, 26743),
(73, 24539); -- Karazhan Bell
