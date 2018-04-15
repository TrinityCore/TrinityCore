-- Cast self Charge Up to get Temporary Electrical Charge
DELETE FROM `waypoint_scripts` WHERE `id`=12698101;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(12698101, 0, 14, 52092, 1, 0, 0, 0, 0, 0, 855),
(12698101, 2, 15, 52098, 1, 0, 0, 0, 0, 0, 856);

-- Remove aura Temporary Electrical Charge
DELETE FROM `waypoint_scripts` WHERE `id`=12698102;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(12698102, 0, 14, 52092, 1, 0, 0, 0, 0, 0, 857);
