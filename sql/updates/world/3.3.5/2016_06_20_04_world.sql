--
SET @CGUID := 87945; -- 15 required
SET @OGUID := 64102; -- 15 required

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14 AND `eventEntry`=14;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14 AND `eventEntry`=14;
