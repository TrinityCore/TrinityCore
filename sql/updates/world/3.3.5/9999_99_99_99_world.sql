UPDATE `gameobject_template` SET `ScriptName`='go_bells' WHERE `entry` IN (175885, 176573, 182064);

DELETE FROM `game_event` WHERE  `eventEntry`=73;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(73, '2010-01-01 01:00:00', '2025-01-01 01:00:00', 60, 1, 0, 'Hourly Bells', 0, 2);
