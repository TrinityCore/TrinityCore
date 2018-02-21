-- Add some missing spawns
SET @CGUID :=452564;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 63258, 0, 0, 0, 1, 1, 0, 0, 0, -8907.551, -212.0174, 82.19667, 2.830582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Bao <Monk Trainer>
(@CGUID+1, 63238, 0, 0, 0, 1, 1, 0, 0, 0, -5166.229, 464.4757, 390.5133, 5.212526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Xi, Friend to the Small <Monk Trainer>
(@CGUID+2, 63239, 0, 0, 0, 1, 1, 0, 0, 0, -5164.262, 460.6892, 391.2339, 2.075682, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Monk Trainee
(@CGUID+3, 63241, 0, 0, 0, 1, 1, 0, 0, 0, -5167.268, 460.6563, 390.8431, 1.262669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Monk Trainee
(@CGUID+4, 63242, 0, 0, 0, 1, 1, 0, 0, 0, -5162.328, 462.9323, 391.1115, 2.71077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Monk Trainee
(@CGUID+5, 63285, 0, 0, 0, 1, 1, 0, 0, 0, -6105.804, 369.4063, 395.626, 1.095405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Lo <Monk Trainer>

-- Reposition Some spawns for master
DELETE FROM `gameobject` WHERE `id` IN (201704,201705,201706);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(217396, 201704, 0, 0, 0, 1, 169, 0, -6114.495, 379.6945, 396.4621, 0, 0, 0, 0, 1, 120, 255, 1, 23877),
(217370, 201705, 0, 0, 0, 1, 169, 0, -6116.972, 379.0938, 395.5426, 1.167404, 0, 0, 0.5511169, 0.834428, 120, 255, 1, 23877),
(217394, 201706, 0, 0, 0, 1, 169, 0, -6113.611, 376.7361, 395.5426, 0, 0, 0, 0, 1, 120, 255, 1, 23877);
