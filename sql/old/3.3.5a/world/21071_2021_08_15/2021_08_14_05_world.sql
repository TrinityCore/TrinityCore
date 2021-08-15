--
DELETE FROM `creature` WHERE `guid` IN (83061,83062) AND `id` = 10558;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(83061,10558,329,0,0,1,1,0,1,3680.27,-3512.37,136.152,2.04204,86400,0,0,1,0,0,0,0,0,'',0),
(83062,10558,329,0,0,1,1,0,1,3683.75,-3334.07,125.32,3.14159,86400,0,0,1,0,0,0,0,0,'',0);

DELETE FROM `pool_members` WHERE `type` = 0 AND `spawnId` IN (83061,83062);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 83061, 376, 0, "Stratholme - Hearthsinger Forresten"),
(0, 83062, 376, 0, "Stratholme - Hearthsinger Forresten");
