-- low-level PvP vendor spawns
SET @GUID := 900012;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID+0, 13217, 0, 0, 0, 1, 1, 0, 1, -8767.85,  418.382, 103.921, 3.64665, 300, 0, 0, 57420, 0, 0, 0, 0, 0, 0),
(@GUID+1, 15127, 0, 0, 0, 1, 1, 0, 1, -8765.48,  415.266, 103.921, 3.81863, 300, 0, 0, 52280, 0, 0, 0, 0, 0, 0),
(@GUID+2, 14753, 0, 0, 0, 1, 1, 0, 1, -8770.48,  421.691, 103.921, 3.89481, 300, 0, 0, 52280, 0, 0, 0, 0, 0, 0),
(@GUID+3, 13219, 1, 0, 0, 1, 1, 0, 1,  1646.77, -4219.27, 56.3828, 0.80658, 300, 0, 0, 57420, 0, 0, 0, 0, 0, 0),
(@GUID+4, 15126, 1, 0, 0, 1, 1, 0, 1,  1648.93, -4221.42, 56.3785, 1.00293, 300, 0, 0, 52280, 0, 0, 0, 0, 0, 0),
(@GUID+5, 14754, 1, 0, 0, 1, 1, 0, 1,  1651.95, -4222.54, 56.3789, 1.26211, 300, 0, 0, 52280, 0, 0, 0, 0, 0, 0);

-- Flame Revenant (30873)
UPDATE `creature` SET `phaseMask` = 1 WHERE `id` = 30873;

-- Hackfix Sons of Hodir Vendor
DELETE FROM `creature` WHERE `guid` = 900014;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(900014, 32540, 571, 0, 0, 1, 1, 0, 1, 7294.19, -2874.07, 822.378, 1.52255, 300, 0, 0, 50400, 0, 0, 0, 0, 0, 0);
