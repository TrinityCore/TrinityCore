--
DELETE FROM `creature` WHERE `guid` IN (252325,252327,252336);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`) VALUES
(252325, 1265, 0, 0, 0, 1, 169, 0, 1, -5513.79, -1304.71, 404.609, 3.50811, 300, 0, 0, 0),
(252327, 41611, 0, 0, 0, 1, 169, 0, 1, -5519.944, -1301.976, 405.013, 4.281697, 300, 0, 0, 0),
(252336, 3177, 0, 0, 0, 1, 169, 0, 1,  -5514.956, -1296.109, 405.935, 5.001653, 300, 0, 0, 0);
