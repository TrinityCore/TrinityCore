-- 
DELETE FROM `creature` WHERE `guid` IN (91691,91692,91693,91694,91695);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(91691,8387,1,1,1,0,0, 1747.24, -5859.60, -90.3817, 3.98543,300,0,0),
(91692,8388,1,1,1,0,0, 1747.62, -5862.27, -90.9249, 3.17332,300,0,0),
(91693,8389,1,1,1,0,0, 1748.87, -5863.46, -90.2665, 2.83088,300,0,0),
(91694,8394,1,1,1,0,0, 1746.45, -5861.29, -91.4165, 3.20841,300,0,0),
(91695,8478,1,1,1,0,0, 1916.44, -5733.37, 10.1936, 4.10397,300,0,0);

DELETE FROM `creature_addon` WHERE `guid` IN (91694,91695);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`auras`) VALUES 
(91694,0,1, '66515'),(91695,8,0, '0');
