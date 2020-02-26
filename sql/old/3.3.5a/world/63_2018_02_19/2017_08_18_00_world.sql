-- 
DELETE FROM `gameobject` WHERE `guid` IN (84,85,87,89);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(87, 189996, 571, 0, 0, 1, 1, 3687.47, -1182.08, 102.337, 1.0472, 0, 0, -0.528919, -0.848673, 180, 0, 1, 0),
(89, 189996, 571, 0, 0, 1, 1, 3669.43, -1172.8, 102.337, 1.09956, 0, 0, -0.55327, -0.833002, 180, 0, 1, 0),
(85, 189996, 571, 0, 0, 1, 1, 3663.93, -1186.44, 102.404, 3.17654, 0, 0, -0.990359, 0.138522, 180, 0, 1, 0),
(84, 189996, 571, 0, 0, 1, 1, 3662.3, -1190.05, 102.447, 2.26893, 0, 0, -0.839429, -0.54347, 180, 0, 1, 0);

DELETE FROM `creature` WHERE `guid` IN (48304,48305);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(48304, 27713, 571, 0, 0, 1, 1, 0, 1, 3663.803, -1191.971, 102.336, 2.065532, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(48305, 27713, 571, 0, 0, 1, 1, 0, 1, 3666.517, -1185.729, 102.336, 3.322169, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
