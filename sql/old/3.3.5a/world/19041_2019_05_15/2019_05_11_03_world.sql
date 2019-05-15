-- 
DELETE FROM `creature` WHERE `guid` IN (104820);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(104820, 18628, 530, 0, 0, 1, 1, 0, 0, 9735.65, -7357.74, 24.3316, 2.79582, 180, 0, 0, 6900, 0, 2, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (104820);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `visibilityDistanceType`) VALUES
(104820, 1048200, 0, 0, 1, 0, '32615', 0);

DELETE FROM `waypoint_data` WHERE `id` IN (1048200);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`move_type`,`action_chance`) VALUES
(1048200, 5, 9732.63, -7360.24, 24.3316, 3.00238, 5000, 0, 0, 100),
(1048200, 4, 9732.63, -7360.24, 24.3316, 3.00238, 1000, 0, 0, 100),
(1048200, 3, 9734.19, -7359.6, 24.3316, 3.53017, 0, 0,  0, 100),
(1048200, 2, 9735.65, -7357.74, 24.3316, 2.79582, 5000, 0, 0, 100),
(1048200, 1, 9735.65, -7357.74, 24.3316, 2.79582, 1000, 0, 0, 100),
(1048200, 6, 9735.58, -7360.2, 24.3316, 1.12135, 0, 0, 0, 100),
(1048200, 7, 9737.62, -7358.28, 24.3316, 1.88162, 0, 0, 0, 100);
