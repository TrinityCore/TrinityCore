-- 
DELETE FROM `creature` WHERE `id`  IN (23168) AND `guid` IN (109649);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(109649, 23168, 530, 1, 1, 1, -5338.61, -108.45, 72.423, 1.41698, 1800, 0, 2);

DELETE FROM `creature_addon` WHERE `guid` IN (109649);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(109649,1096490,0,1,'');

DELETE FROM `waypoint_data` WHERE `id` IN (1096490);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`, `action_chance`, `move_type`, `wpguid`) VALUES
(1096490, 1, -5332.09, -85.8966, 83.0617, 1.80261, 100, 0, 0),
(1096490, 2, -5345.18, -60.7703, 86.1259, 2.29505, 100, 0, 0),
(1096490, 3, -5359.92, -47.2275, 88.2481, 3.41582, 100, 0, 0),
(1096490, 4, -5375.98, -54.8256, 85.1149, 4.11639, 100, 0, 0),
(1096490, 5, -5383.74, -67.6999, 82.852, 4.64811, 100, 0, 0),
(1096490, 6, -5382.25, -85.6452, 77.1119, 4.99053, 100, 0, 0),
(1096490, 7, -5369.33, -110.352, 68.5213, 4.55071, 100, 0, 0),
(1096490, 8, -5376.19, -131.543, 60.2006, 5.28192, 100, 0, 0),
(1096490, 9, -5365.88, -147.114, 56.8587, 5.97856, 100, 0, 0),
(1096490, 10, -5354.64, -146.72, 57.3092, 0.628427, 100, 0, 0),
(1096490, 11, -5347.56, -140.622, 59.763, 1.09181, 100, 0, 0),
(1096490, 12, -5337.81, -108.826, 72.3716, 1.38112, 100, 0, 0);
