-- 
SET @Guid=52270;
DELETE FROM `creature` WHERE `guid` BETWEEN @Guid+0 AND @Guid+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@Guid+0, 24789, 571, 0, 0, 1, 1, 20089, 0, 679.537, -3379.89, 67.5482, 4.74721, 300, 10, 0, 9291, 3155, 1, 0, 0, 0),
(@Guid+1, 24789, 571, 0, 0, 1, 1, 20089, 0, 721.82, -3380.29, 68.1963, 4.78832, 300, 10, 0, 9291, 3155, 1, 0, 0, 0),
(@Guid+2, 24789, 571, 0, 0, 1, 1, 20089, 0, 724.233, -3336.82, 68.0772, 1.22937, 300, 10, 0, 9291, 3155, 1, 0, 0, 0),
(@Guid+3, 24789, 571, 0, 0, 1, 1, 20089, 0, 695.932, -3417.13, 68.5955, 1.00392, 300, 10, 0, 9291, 3155, 1, 0, 0, 0);
