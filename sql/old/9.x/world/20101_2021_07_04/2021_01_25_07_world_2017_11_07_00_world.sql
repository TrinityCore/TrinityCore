-- 
DELETE FROM `creature` WHERE `guid` IN (81144,81145,81146);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `VerifiedBuild`) VALUES
(81144, 24580, 571, 0, 0, '0', 170, 0, 0, 1321.86, 5985.3, 24.0983, 5.96903, 180, 0, 0, 6986, 0, 0, 0),
(81145, 24580, 571, 0, 0, '0', 170, 0, 0, 1371.06, 5813.19, 6.16783, 1.20428, 180, 0, 0, 6986, 0, 0, 0),
(81146, 24580, 571, 0, 0, '0', 170, 0, 0, 1407.27, 5971.62, 5.82894, 0.959931, 180, 0, 0, 6986, 0, 0, 0);

DELETE FROM `gameobject` WHERE `guid` IN (1430);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(1430, 187703, 571, 0, 0, '0', 170, 1325.65, 5984.97, 23.4195, 2.076939, 0, 0, 0.8616285, 0.5075394, 300, 255, 1, 0);
