--
DELETE FROM `game_event_gameobject` WHERE `guid` IN (220041, 220044, 220043, 220042, 220048, 220049, 220076, 220148, 220147, 220029);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(3, 220029),
(3, 220041),
(3, 220042),
(3, 220043),
(3, 220044),
(3, 220147),
(3, 220048),
(3, 220049),
(3, 220076),
(3, 220148);
