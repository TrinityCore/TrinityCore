-- 
DELETE FROM `creature` WHERE `guid`=111168;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(111168, 28656, 595, 4100, 0, 3, 1, 0, 0, 1810.875, 1285.035, 142.4917, 4.485496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 28656 (Area: 0 - Difficulty: 0)
DELETE FROM `gameobject` WHERE `guid`=9223;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9223, 190117, 595, 4100, 0, 3, 1, 1813.312, 1283.587, 142.2434, 4.81711, 0, 0, -0.6691303, 0.743145, 7200, 255, 1, 15595); -- 190117 (Area: 0 - Difficulty: 0)
UPDATE `creature` SET `equipment_id`=1 WHERE `id`=27915;
