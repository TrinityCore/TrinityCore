--
DELETE FROM `game_event_creature` WHERE `eventEntry`=3 AND `guid` IN (358708,293873);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(3, 358708),
(3, 293873);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=3 AND `guid` IN (214426,214910,224383,224458);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES 
(3, 214426),
(3, 214910),
(3, 224383),
(3, 224458);
