-- 
SET @OGUID:=66937;
SET @CGUID:=12545;
SET @Event:=2;

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+26 AND `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` SELECT @Event, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+26;

-- Add spawns Pat's Snowcloud Guy
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `spawnMask`,`PhaseId`) VALUES 
(@CGUID+0, 15730, 530, 9346.396, -7265.283, 20.67977, 6.021386, 120, 0, 1, 169), -- 15730 (Area: 0) (Auras: 26000 - 26000)
(@CGUID+1, 15730, 530, 9347.098, -7267.961, 20.6914, 3.263766, 120, 0, 1, 169); -- 15730 (Area: 0) (Auras: 26000 - 26000)

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1 AND `eventEntry`=@Event;
INSERT INTO `game_event_creature` SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+1;
