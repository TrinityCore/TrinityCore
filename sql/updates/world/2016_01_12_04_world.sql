SET @OGUID:=79521;
SET @CGUID:=52265;
SET @Event:=2;

DELETE FROM `gameobject` WHERE `guid` IN (@OGUID+0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 187567, 530, 1, 1, -690.7932, 2724.943, 100.9289, 6.265733, 0, 0, 0, 1, 120, 255, 1); -- 187567 (Area: 3483)

DELETE FROM `game_event_gameobject` WHERE `guid` IN (@OGUID+0);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@Event, @OGUID+0);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4 AND `eventEntry`=@Event;
INSERT INTO `game_event_creature` SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+4;
