-- Creature templates
UPDATE `waypoint_path` SET `Comment`='Black Cat - Cosmetic Path' WHERE `PathId`=2281600;
UPDATE `waypoint_path_node` SET `Delay`=10 WHERE `PathId`=2281600 AND `NodeId` IN (0,1);

-- Spawns
DELETE FROM `gameobject` WHERE `guid`=3808020 AND `id`=180448;
SET @UPDATED := EXISTS(SELECT * FROM `gameobject` WHERE `guid`=3808020);
UPDATE `gameobject` SET `guid`=`guid`-1 WHERE @UPDATED=0 AND `guid` BETWEEN 3808021 AND 3808386;
DELETE FROM `gameobject` WHERE `guid`=3808387 AND `id`=180453;
SET @UPDATED := EXISTS(SELECT * FROM `gameobject` WHERE `guid` IN (3808386,3808387));
UPDATE `gameobject` SET `guid`=`guid`-2 WHERE @UPDATED=0 AND `guid` BETWEEN 3808387 AND 3808498;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (3808497,3808498);
