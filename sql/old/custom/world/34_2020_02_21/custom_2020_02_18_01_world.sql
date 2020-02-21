-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8477.475, `position_y`= 1169.949, `position_z`= 17.7196 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8477.475, 1169.949, 17.7196, 0, 295, 0, 0, 100, 0),
(@PATH, 2, -8508.547, 1169.438, 17.7048, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8547.19, 1170.827, 17.73302, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8581.927, 1169.016, 17.80247, 0, 230, 0, 0, 100, 0),
(@PATH, 5, -8547.19, 1170.827, 17.73302, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8508.547, 1169.438, 17.7048, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050000497FDB .go xyz -8477.475 1169.949 17.7196

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313742;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8604.854, `position_y`= 1039.209, `position_z`= 96.19238 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8604.854, 1039.209, 96.19238, 0, 151, 0, 0, 100, 0),
(@PATH, 2, -8586.875, 1019.077, 96.17702, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8580.669, 1005.541, 96.29066, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8571.524, 993.6271, 96.37449, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8564.381, 983.8884, 96.45055, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8545.017, 962.062, 96.68864, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8535.311, 952.0538, 96.716, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8510.51, 949.2531, 96.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8510.51, 949.2531, 96.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8490.954, 951.4664, 96.31528, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8481.771, 955.3033, 96.33884, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8458.89, 977.1547, 96.31528, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8436.071, 996.3249, 96.3735, 0, 157, 0, 0, 100, 0),
(@PATH, 14, -8458.837, 977.1993, 96.31528, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -8481.771, 955.3033, 96.33884, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -8490.954, 951.4664, 96.31528, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -8510.51, 949.2531, 96.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -8535.311, 952.0538, 96.716, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -8545.017, 962.062, 96.68864, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -8564.381, 983.8884, 96.45055, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -8571.524, 993.6271, 96.37449, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -8580.669, 1005.541, 96.29066, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -8586.875, 1019.077, 96.17702, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050000497FDF .go xyz -8604.854 1039.209 96.19238

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313606;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8372.844, `position_y`= 1242.286, `position_z`= 5.377557 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8372.844, 1242.286, 5.377557, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8376.075, 1245.286, 5.355601, 0, 69, 0, 0, 100, 0),
(@PATH, 3, -8363.169, 1243.203, 5.44591, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8363.301, 1243.191, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8270.255, 1234.741, 5.319743, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8263.469, 1228.884, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8254.337, 1227.42, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8251.051, 1223.724, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8235.974, 1223.483, 5.319611, 0, 330, 0, 0, 100, 0),
(@PATH, 10, -8251.051, 1223.724, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8254.337, 1227.42, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8263.469, 1228.884, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8270.255, 1234.741, 5.319743, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8315.778, 1247.233, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -8363.008, 1243.217, 5.319611, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050001497FE0 .go xyz -8372.844 1242.286 5.377557

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8395.935, `position_y`= 1116.135, `position_z`= 17.96996 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8395.935, 1116.135, 17.96996, 0, 276, 0, 0, 100, 0),
(@PATH, 2, -8395.961, 1107.979, 19.90427, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8397.671, 1086.549, 29.42476, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8400.794, 1075.946, 31.7196, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8412.029, 1068.872, 31.7196, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8431.488, 1055.909, 41.0016, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8448.238, 1039.041, 53.60736, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8464.138, 1029.035, 59.51529, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8483.146, 1027.786, 59.7512, 0, 74, 0, 0, 100, 0),
(@PATH, 10, -8464.138, 1029.035, 59.51529, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8448.238, 1039.041, 53.60736, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8431.488, 1055.909, 41.0016, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8412.029, 1068.872, 31.7196, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8400.794, 1075.946, 31.7196, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -8397.671, 1086.549, 29.42476, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -8395.961, 1107.979, 19.90427, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050001C97FDB .go xyz -8395.935 1116.135 17.96996

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313615;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8361.695, `position_y`= 1214.241, `position_z`= 5.15971 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 2410, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8361.695, 1214.241, 5.15971, 0, 369, 0, 0, 100, 0),
(@PATH, 2, -8337.396, 1215.517, 5.28471, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8298.195, 1215.461, 5.268316, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8251.519, 1215.401, 5.174629, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8208.684, 1208.903, 6.532701, 0, 362, 0, 0, 100, 0),
(@PATH, 6, -8251.519, 1215.401, 5.174629, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8298.195, 1215.461, 5.268316, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8337.396, 1215.517, 5.28471, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050001C97FE0 .go xyz -8361.695 1214.241 5.15971

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313667;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8466.758, `position_y`= 985.998, `position_z`= 79.16684 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8466.758, 985.998, 79.16684, 0, 205, 0, 0, 100, 0),
(@PATH, 2, -8448.758, 999.7491, 79.45979, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8430.958, 1014.584, 75.0847, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8418.053, 1024.265, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8420.548, 1036.334, 68.54607, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8419.694, 1043.185, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8420.149, 1039.53, 68.53374, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8416.995, 1046.547, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8406.388, 1049.458, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8399.659, 1046.967, 68.53001, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8390.372, 1043.123, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8366.223, 1061.28, 57.72956, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8344.169, 1080.097, 57.38107, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8331.262, 1091.611, 57.31961, 0, 218, 0, 0, 100, 0),
(@PATH, 15, -8344.169, 1080.097, 57.38107, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -8366.223, 1061.28, 57.72956, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -8390.372, 1043.123, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -8399.659, 1046.967, 68.53001, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -8406.388, 1049.458, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -8412.033, 1049.239, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -8416.558, 1047.092, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -8419.694, 1043.185, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -8419.146, 1043.868, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -8418.053, 1024.265, 68.51527, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -8430.958, 1014.584, 75.0847, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -8448.758, 999.7491, 79.45979, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050002C97FDF .go xyz -8466.758 985.998 79.16684

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313617;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8301.696, `position_y`= 1170.134, `position_z`= 17.7196 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8301.696, 1170.134, 17.7196, 0, 180, 0, 0, 100, 0),
(@PATH, 2, -8278.599, 1171.045, 17.7196, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8229.291, 1170.029, 17.68251, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8205.958, 1172.401, 17.73548, 0, 154, 0, 0, 100, 0),
(@PATH, 5, -8229.291, 1170.029, 17.68251, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8278.599, 1171.045, 17.7196, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050003497FDB .go xyz -8301.696 1170.134 17.7196

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313466;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8549.759, `position_y`= 1245.416, `position_z`= 5.402481 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8549.759, 1245.416, 5.402481, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8526.583, 1246.124, 5.31961, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8521.271, 1234.52, 5.319612, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8503.136, 1233.855, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8473.279, 1244.646, 5.409661, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8473.544, 1248.154, 5.397026, 0, 256, 0, 0, 100, 0),
(@PATH, 7, -8503.136, 1233.855, 5.319611, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8521.271, 1234.52, 5.319612, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8526.583, 1246.124, 5.31961, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8549.759, 1245.416, 5.402481, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8558.985, 1239.222, 5.402481, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8584.936, 1235.224, 5.402481, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8593.689, 1237.97, 5.402481, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8596.938, 1243.012, 5.402481, 0, 5574, 0, 0, 100, 0),
(@PATH, 15, -8558.985, 1239.222, 5.402481, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050003497FDD .go xyz -8549.759 1245.416 5.402481

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313669;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8577.755, `position_y`= 1124.458, `position_z`= 18.06503 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 2410, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8577.755, 1124.458, 18.06503, 0, 283, 0, 0, 100, 0),
(@PATH, 2, -8584.051, 1114.951, 19.53339, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8593.218, 1090.801, 32.6083, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8583.412, 1071.972, 36.76746, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8567.036, 1050.443, 49.94305, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8552.774, 1036.753, 59.41509, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8535.628, 1034.673, 59.79605, 0, 297, 0, 0, 100, 0),
(@PATH, 8, -8552.774, 1036.753, 59.41509, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8567.036, 1050.443, 49.94305, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8583.316, 1071.846, 36.78777, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8593.218, 1090.801, 32.6083, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8584.051, 1114.951, 19.53339, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050003497FE0 .go xyz -8577.755 1124.458 18.06503

-- Pathing for  Entry: 29712 'TDB FORMAT' 
SET @NPC := 313610;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8510.788, `position_y`= 1214.557, `position_z`= 5.190891 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 2410, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8510.788, 1214.557, 5.190891, 0, 106, 0, 0, 100, 0),
(@PATH, 2, -8475.846, 1209.424, 5.320824, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8444.612, 1208.325, 5.18425, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8419.291, 1208.162, 5.281563, 0, 99, 0, 0, 100, 0),
(@PATH, 5, -8444.612, 1208.325, 5.18425, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8475.846, 1209.424, 5.320824, 0, 0, 0, 0, 100, 0);
-- 0x2030A400001D0400004A050004C97FDB .go xyz -8510.788 1214.557 5.190891


DELETE FROM `creature_addon` WHERE `guid`= 313674;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(313674, 0, 2410, 0, 1, 0, '');
