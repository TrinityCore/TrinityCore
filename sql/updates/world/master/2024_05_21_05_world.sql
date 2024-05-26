DELETE FROM `creature` WHERE `guid` IN (450485, 450492, 450480, 450462, 450391, 450612, 450482, 450619, 450486, 450616); -- Reusable guids

UPDATE `creature` SET `equipment_id` = 0 WHERE `guid` IN (450036, 450039, 450620, 450493);

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=60245 AND `DifficultyID`=0); -- Brewer Zhen
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=60248 AND `DifficultyID`=0); -- Chia-hui Autumnleaf
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=60253 AND `DifficultyID`=0); -- Brewer Lin

-- Waypoints
-- Fe-Feng Hozen 1
SET @ENTRY := 57205;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 5');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1244.173, 3667.366, 91.5778, NULL, 0),
(@PATH, 1, 1224.637, 3659.807, 92.90532, NULL, 0),
(@PATH, 2, 1227.151, 3646.648, 95.53232, NULL, 0),
(@PATH, 3, 1237.653, 3642.382, 93.94682, NULL, 0),
(@PATH, 4, 1239.809, 3635.231, 95.35127, NULL, 0),
(@PATH, 5, 1227.151, 3646.648, 95.53232, NULL, 0),
(@PATH, 6, 1224.637, 3659.807, 92.90532, NULL, 0),
(@PATH, 7, 1234.964, 3671.273, 92.63132, NULL, 0);

UPDATE `creature` SET `position_x`= 1244.173, `position_y`= 3667.366, `position_z`= 91.5778, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450394;
DELETE FROM `creature_addon` WHERE `guid`= 450394;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450394, @PATH, 1);

-- Fe-Feng Hozen 2
SET @ENTRY := 57205;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 6');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1269.55, 3727.061, 91.53522, NULL, 0),
(@PATH, 1, 1256.146, 3725.214, 92.103, NULL, 0),
(@PATH, 2, 1244.363, 3726.153, 93.97342, NULL, 0),
(@PATH, 3, 1242.783, 3735.703, 93.94279, NULL, 0),
(@PATH, 4, 1244.597, 3741.183, 93.36487, NULL, 0),
(@PATH, 5, 1254.595, 3739.469, 90.5905, NULL, 402),
(@PATH, 6, 1242.783, 3735.703, 93.94279, NULL, 0),
(@PATH, 7, 1244.363, 3726.153, 93.97342, NULL, 0),
(@PATH, 8, 1256.146, 3725.214, 92.103, NULL, 0),
(@PATH, 9, 1269.55, 3727.061, 91.53522, NULL, 0),
(@PATH, 10, 1278.092, 3720.293, 90.02708, NULL, 0),
(@PATH, 11, 1284.429, 3705.247, 86.14371, NULL, 0),
(@PATH, 12, 1291.422, 3704.616, 86.2205, NULL, 14),
(@PATH, 13, 1278.092, 3720.293, 90.02708, NULL, 0);

UPDATE `creature` SET `position_x`= 1190.519, `position_y`= 3745.292, `position_z`= 93.05916, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450494;
DELETE FROM `creature_addon` WHERE `guid`= 450494;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450494, @PATH, 1);

-- Fe-Feng Hozen 3
SET @ENTRY := 57205;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 7');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1191.799, 3687.529, 99.47076, NULL, 0),
(@PATH, 1, 1186.318, 3678.026, 99.45316, NULL, 0),
(@PATH, 2, 1197.944, 3672.267, 97.57945, NULL, 138),
(@PATH, 3, 1186.318, 3678.026, 99.45316, NULL, 0),
(@PATH, 4, 1191.799, 3687.529, 99.47076, NULL, 0),
(@PATH, 5, 1202.731, 3694.034, 96.55957, NULL, 0),
(@PATH, 6, 1209.949, 3697.479, 94.91675, NULL, 0),
(@PATH, 7, 1219.832, 3699.931, 93.70534, NULL, 107),
(@PATH, 8, 1202.734, 3694.031, 96.57874, NULL, 0);

UPDATE `creature` SET `position_x`= 1191.799, `position_y`= 3687.529, `position_z`= 99.47076, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450529;
DELETE FROM `creature_addon` WHERE `guid`= 450529;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450529, @PATH, 1);

-- Fe-Feng Hozen 4
SET @ENTRY := 57205;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 8');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1182.804, 3764.365, 91.73024, NULL, 0),
(@PATH, 1, 1188.118, 3772.423, 89.70108, NULL, 0),
(@PATH, 2, 1197.42, 3767.958, 89.47875, NULL, 0),
(@PATH, 3, 1200.476, 3754.757, 90.39675, NULL, 0),
(@PATH, 4, 1198.905, 3745.451, 91.50883, NULL, 0),
(@PATH, 5, 1190.519, 3745.292, 93.05916, NULL, 283),
(@PATH, 6, 1200.476, 3754.757, 90.39675, NULL, 0),
(@PATH, 7, 1197.42, 3767.958, 89.47875, NULL, 0),
(@PATH, 8, 1188.118, 3772.423, 89.70108, NULL, 0),
(@PATH, 9, 1182.804, 3764.365, 91.73024, NULL, 0),
(@PATH, 10, 1172.188, 3745.387, 93.76577, NULL, 0),
(@PATH, 11, 1167.257, 3730.832, 98.12619, NULL, 0),
(@PATH, 12, 1168.033, 3719.603, 99.47594, NULL, 276),
(@PATH, 13, 1172.188, 3745.387, 93.76577, NULL, 0);

UPDATE `creature` SET `position_x`= 1182.804, `position_y`= 3764.365, `position_z`= 91.73024, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450507;
DELETE FROM `creature_addon` WHERE `guid`= 450507;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450507, @PATH, 1);

-- Fe-Feng Hozen 5
SET @ENTRY := 57205;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 9');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1293.873, 3755.62, 82.17702, NULL, 0),
(@PATH, 1, 1282.594, 3757.129, 85.56174, NULL, 0),
(@PATH, 2, 1281.186, 3748.994, 88.807, NULL, 0),
(@PATH, 3, 1281.755, 3739.134, 89.93045, NULL, 0),
(@PATH, 4, 1298.151, 3731.044, 81.84277, NULL, 361),
(@PATH, 5, 1281.755, 3739.134, 89.93045, NULL, 0),
(@PATH, 6, 1281.186, 3748.994, 88.807, NULL, 0),
(@PATH, 7, 1282.594, 3757.129, 85.56174, NULL, 0),
(@PATH, 8, 1293.873, 3755.62, 82.17702, NULL, 0),
(@PATH, 9, 1287.311, 3762.478, 81.80273, NULL, 0),
(@PATH, 10, 1273.207, 3768.954, 83.10479, NULL, 0),
(@PATH, 11, 1247.661, 3763.284, 89.44864, NULL, 0),
(@PATH, 12, 1238.859, 3764.387, 90.39224, NULL, 355),
(@PATH, 13, 1273.207, 3768.954, 83.10479, NULL, 0),
(@PATH, 14, 1287.311, 3762.478, 81.80273, NULL, 0);

UPDATE `creature` SET `position_x`= 1293.873, `position_y`= 3755.62, `position_z`= 82.17702, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450509;
DELETE FROM `creature_addon` WHERE `guid`= 450509;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450509, @PATH, 1);

-- Fe-Feng Hozen 6
SET @ENTRY := 57205;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 10');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1130.002, 3694.614, 102.9448, NULL, 0),
(@PATH, 1, 1144.3, 3693.514, 104.1493, NULL, 0),
(@PATH, 2, 1151.035, 3696.048, 103.3115, NULL, 280),
(@PATH, 3, 1130.002, 3694.614, 102.9448, NULL, 0),
(@PATH, 4, 1131.681, 3681.453, 103.1755, NULL, 0),
(@PATH, 5, 1135.257, 3667.392, 101.0022, NULL, 0),
(@PATH, 6, 1143.129, 3652.982, 105.1957, NULL, 3020),
(@PATH, 7, 1131.681, 3681.453, 103.1755, NULL, 0);

UPDATE `creature` SET `position_x`= 1130.002, `position_y`= 3694.614, `position_z`= 102.9448, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450515;
DELETE FROM `creature_addon` WHERE `guid`= 450515;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450515, @PATH, 1);

-- Amberleaf Scamp 1
SET @ENTRY := 54130;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Amberleaf Scamp Cosmetic waypoint 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1277.88, 3543.563, 93.56727, NULL, 0),
(@PATH, 1, 1269.757, 3550.408, 95.10683, NULL, 0),
(@PATH, 2, 1259.813, 3557.848, 99.41698, NULL, 0),
(@PATH, 3, 1253.368, 3559.958, 101.3789, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`= 450286;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450286, @PATH, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450286 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = 5413000;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450286, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (54130 * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Just Created - Self: Start timed action list'),
(-450286, 0, 1, 0, 58, 0, 100, 0, 3, 5413000, 0, 0, 0, '', 41, 3500, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Waypoint Finished - Self: Despawn after 3,5 seconds'),
((54130 * 100), 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 0, '', 85, 109137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Between 1 and 3 seconds - Self: Cast to Self spell 109137'),
((54130 * 100), 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5413000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Self: Start path #5413000, run, do not repeat, Passive');

-- Amberleaf Scamp 2
SET @ENTRY := 54130;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Amberleaf Scamp Cosmetic waypoint 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1292.674, 3502.029, 102.3115, NULL, 0),
(@PATH, 1, 1299.087, 3493.448, 106.8531, NULL, 0),
(@PATH, 2, 1304.938, 3489.859, 109.5571, NULL, 0),
(@PATH, 3, 1318.639, 3477.482, 112.7021, NULL, 0),
(@PATH, 4, 1328.307, 3465.213, 114.6394, NULL, 0),
(@PATH, 5, 1327.819, 3459.954, 117.4277, NULL, 0),
(@PATH, 6, 1330.396, 3451.8, 120.444, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`= 450284;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450284, @PATH, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450284 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = 5413001;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450284, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (54130 * 100) + 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Just Created - Self: Start timed action list'),
(-450284, 0, 1, 0, 58, 0, 100, 0, 6, 5413001, 0, 0, 0, '', 41, 3500, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Waypoint Finished - Self: Despawn after 3,5 seconds'),
((54130 * 100) + 1, 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 0, '', 85, 109137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Between 1 and 3 seconds - Self: Cast to Self spell 109137'),
((54130 * 100) + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5413001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Self: Start path #5413000, run, do not repeat, Passive');

-- Amberleaf Scamp 3
SET @ENTRY := 54130;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Amberleaf Scamp Cosmetic waypoint 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1312.16, 3514.234, 103.2949, NULL, 0),
(@PATH, 1, 1320.901, 3511.293, 103.7662, NULL, 0),
(@PATH, 2, 1333.394, 3508.494, 102.8783, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`= 450297;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450297, @PATH, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450297 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = 5413002;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450297, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (54130 * 100) + 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Just Created - Self: Start timed action list'),
(-450297, 0, 1, 0, 58, 0, 100, 0, 2, 5413002, 0, 0, 0, '', 41, 3500, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Waypoint Finished - Self: Despawn after 3,5 seconds'),
((54130 * 100) + 2, 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 0, '', 85, 109137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Between 1 and 3 seconds - Self: Cast to Self spell 109137'),
((54130 * 100) + 2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5413002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Self: Start path #5413000, run, do not repeat, Passive');

-- Amberleaf Scamp 4
SET @ENTRY := 54130;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Amberleaf Scamp Cosmetic waypoint 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1314.536, 3541.405, 99.65874, NULL, 0),
(@PATH, 1, 1338.78, 3543.706, 94.42071, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`= 450296;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450296, @PATH, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450296 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = 5413003;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450296, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (54130 * 100) + 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Just Created - Self: Start timed action list'),
(-450296, 0, 1, 0, 58, 0, 100, 0, 1, 5413003, 0, 0, 0, '', 41, 3500, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Amberleaf Scamp - On Waypoint Finished - Self: Despawn after 3,5 seconds'),
((54130 * 100) + 3, 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 0, '', 85, 109137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Between 1 and 3 seconds - Self: Cast to Self spell 109137'),
((54130 * 100) + 3, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5413003, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Self: Start path #5413000, run, do not repeat, Passive');

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=60245; -- Brewer Zhen
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=60248; -- Chia-hui Autumnleaf
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=60253; -- Brewer Lin
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=54130; -- Amberleaf Scamp

DELETE FROM `smart_scripts` WHERE `entryorguid`=60245 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60245, 0, 0, 0, '', 1, 0, 100, 0, 2000, 10000, 2000, 10000, 0, '', 87, 6024500, 6024501, 0,  0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Every 2 to 10 seconds - Brewer Zhen - OOC - Random Action list');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6024500, 6024501) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6024500, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 10, 1, 5, 6, 25, 11, 273, 274, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Play random emote: 1, 5, 6, 25, 11, 273, 274'),
(6024501, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 56745, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Cast to Self spell 56745');

DELETE FROM `smart_scripts` WHERE `entryorguid`=60248 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60248, 0, 0, 0, '', 1, 0, 100, 0, 2000, 10000, 2000, 10000, 0, '', 87, 6024800, 6024801, 0,  0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Every 2 to 10 seconds - Chia-hui Autumnleaf - OOC - Random Action list');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6024800, 6024801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6024800, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 10, 1, 5, 6, 25, 11, 273, 274, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Play random emote: 1, 5, 6, 25, 11, 273, 274'),
(6024801, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 56745, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Cast to Self spell 56745');

DELETE FROM `smart_scripts` WHERE `entryorguid`=60253 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60253, 0, 0, 0, '', 1, 0, 100, 0, 2000, 10000, 2000, 10000, 0, '', 87, 6025300, 6025301, 0,  0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Every 2 to 10 seconds - Brewer Lin - OOC - Random Action list');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6025300, 6025301) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6025300, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 10, 1, 5, 6, 25, 11, 273, 274, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Play random emote: 1, 5, 6, 25, 11, 273, 274'),
(6025301, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 56745, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On Actionlist - Self: Cast to Self spell 56745');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450514 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450514, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450513 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450513, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450501 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450501, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450504 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450504, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450039 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450039, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450036 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450036, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');
