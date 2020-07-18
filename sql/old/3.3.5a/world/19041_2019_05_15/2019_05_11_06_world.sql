-- 
DELETE FROM `creature` WHERE `guid` IN (104824,104827,83516);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(104824, 18650, 560, 0, 0, 3, 1, 0, 0, 2478.69, 688.93, 55.7619, 0.286027, 86400, 0, 0, 500, 0, 0, 0, 0, 0, 0),
(104827, 18650, 560, 0, 0, 3, 1, 0, 0, 2486.82, 689.457, 55.8031, 1.65806, 86400, 0, 0, 500, 0, 0, 0, 0, 0, 0),
(83516, 18651, 560, 0, 0, 3, 1, 0, 0, 2476.17, 689.82, 55.8635, 1.51844, 86400, 0, 0, 55, 0, 0, 0, 0, 0, 0);
