SET @EVENT := 3;

-- Gameobject spawn incorrectly linked to the event
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid`=220436;

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` IN (535, 296252, 307954, 312055, 314353);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, 535), 
(@EVENT, 296252),
(@EVENT, 307954),
(@EVENT, 312055),
(@EVENT, 314353);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` IN (312, 313, 214889, 214890, 218246, 218251, 218911, 218912, 219321, 219322, 220102, 220438, 220458);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, 312),
(@EVENT, 313),
(@EVENT, 214889),
(@EVENT, 214890),
(@EVENT, 218246),
(@EVENT, 218251),
(@EVENT, 218911),
(@EVENT, 218912),
(@EVENT, 219321),
(@EVENT, 219322),
(@EVENT, 220102),
(@EVENT, 220438),
(@EVENT, 220458);
