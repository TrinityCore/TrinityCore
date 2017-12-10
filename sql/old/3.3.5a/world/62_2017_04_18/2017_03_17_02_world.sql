--
SET @CGUID := 146562;
SET @OGUID := 9743;


DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+62 AND `eventEntry`=8;
INSERT INTO `game_event_creature` SELECT 8, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+62;

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+94 AND `eventEntry`=8;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+94 AND `eventEntry`=8;
INSERT INTO `game_event_gameobject` SELECT 8, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+94;
--
