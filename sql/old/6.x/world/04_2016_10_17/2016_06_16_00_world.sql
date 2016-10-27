--
DELETE FROM `game_event_creature` WHERE `guid` IN (314040, 314484, 310945);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(3, 314040),
(3, 314484),
(3, 310945);

DELETE FROM `game_event_gameobject` WHERE `guid` IN (220437, 220463, 220468, 220476, 220461, 220436, 220466);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(3, 220437),
(3, 220463),
(3, 220468),
(3, 220476),
(3, 220461),
(3, 220436),
(3, 220466);
