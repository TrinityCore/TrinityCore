-- 
DELETE FROM `creature` WHERE `guid` IN (104829, 104830, 104832);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(104829, 18657, 560, 0, 0, 3, 1, 0, 1, 2397, 747.512, 54.2694, 4.18879, 86400, 0, 0, 617, 0, 0, 0, 0, 0, 0),
(104830, 18657, 560, 0, 0, 3, 1, 0, 1, 2399.98, 744.429, 54.378, 3.92699, 86400, 0, 0, 617, 0, 0, 0, 0, 0, 0),
(104832, 18657, 560, 0, 0, 3, 1, 0, 1, 2404.2, 740.228, 54.419, 4.2586, 86400, 0, 0, 617, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (18657);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`) VALUES
(18657, 0, 0, 0, 1, 379);
