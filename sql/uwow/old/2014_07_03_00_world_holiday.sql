DELETE FROM game_event_gameobject WHERE guid in (SELECT guid from gameobject WHERE id = 217851);
DELETE FROM `gameobject` WHERE id = 217851;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES
( 217851, 870, 5840, 5840, 1, 1, 1322.29, 460.914, 457.784, 3.87661, 0, 0, 0.933225, -0.359292, 300, 0, 1, 0);
INSERT INTO game_event_gameobject (eventEntry, guid) SELECT 1, guid FROM gameobject WHERE id = 187892;

DELETE FROM game_event_gameobject WHERE guid in (SELECT guid from gameobject WHERE id = 217852);
DELETE FROM `gameobject` WHERE id = 217852;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES
(217852, 870, 5840, 5840, 1, 1, 1379.19, 510.554, 457.784, 0.763297, 0, 0, 0.372451, 0.928052, 300, 0, 1, 0);
INSERT INTO game_event_gameobject (eventEntry, guid) SELECT 1, guid FROM gameobject WHERE id = 217852;

DELETE FROM creature WHERE id = 69551;
DELETE FROM game_event_creature WHERE guid in (SELECT guid FROM creature WHERE id = 69551);
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES
( 69551, 870, 5840, 5840, 1, 1, 0, 0, 1396.39, 495.719, 457.784, 2.34587, 300, 0, 0, 84, 0, 0, 0, 0, 0, 0);
INSERT INTO game_event_creature (eventEntry, game_event_creature.guid) SELECT 1, guid FROM  creature WHERE id =69551;