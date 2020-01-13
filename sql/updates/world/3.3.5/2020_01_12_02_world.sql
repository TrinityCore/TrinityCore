-- 
DELETE FROM `spawn_group` WHERE `groupId` IN (57,58) AND `spawnId` IN (84090,208778);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(57, 0, 208778),
(58, 0, 84090);

DELETE FROM `creature` WHERE `guid`=84090;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(84090, 38491, 631, 4812, 0, 15, 1, 0, 1,  -532.6129, 2151.1406, 199.9705, 3.294214, 7200, 0, 0, 1, 0, 0, 0, 0, 0, 12213); -- 38492 (Area: 0 - Difficulty: 0)
