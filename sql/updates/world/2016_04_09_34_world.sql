-- 
SET @OGUID:=79521;
SET @CGUID:=52265;
SET @Event:=2;

DELETE FROM `game_event_gameobject` WHERE `guid` IN (@OGUID+0);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@Event, @OGUID+0);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4 AND `eventEntry`=@Event;
INSERT INTO game_event_creature SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+4;
