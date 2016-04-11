-- 
SET @OGUID:=79522;
SET @CGUID:=52022;
SET @Event:=2;

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+61 AND `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` SELECT @Event, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+61;

-- Add spawns Pat's Snowcloud Guy
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `spawnMask`,`PhaseId`) VALUES 
(@CGUID+0, 15730, 530, -3997.986, -11908.32, -1.411356, 0.2617994, 120, 0, 1, 169), -- 15730 (Area: 0) (Auras: 26000 - 26000)
(@CGUID+1, 15730, 530, -3997.807, -11908.79, 0.8329293, 4.782202, 120, 0, 1, 169); -- 15730 (Area: 0) (Auras: 26000 - 26000)

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1 AND `eventEntry`=@Event;
INSERT INTO `game_event_creature` SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+1;
