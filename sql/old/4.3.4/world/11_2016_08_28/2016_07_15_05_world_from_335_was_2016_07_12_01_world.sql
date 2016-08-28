-- 
SET @Guid:=52664;
DELETE FROM `creature` WHERE `guid` BETWEEN @Guid AND @Guid+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@Guid+0, 36811, 631, 0, 0, 10, 1, 0, 1, -568.121, 2225.85, 49.4766, 3.12087, 300, 0, 0, 808800, 91600, 0, 0, 0, 0, 0),
(@Guid+1, 36811, 631, 0, 0, 10, 1, 0, 1, -568.878, 2197.52, 49.4766, 2.93833, 300, 0, 0, 808800, 91600, 0, 0, 0, 0, 0),
(@Guid+2, 36807, 631, 0, 0, 10, 1, 0, 0, -582.666, 2221.75, 49.4766, 3.32411, 300, 0, 0, 808800, 91600, 0, 0, 0, 0, 0),
(@Guid+3, 36807, 631, 0, 0, 10, 1, 0, 0, -583.898, 2200.98, 49.4766, 3.00995, 300, 0, 0, 808800, 91600, 0, 0, 0, 0, 0);
