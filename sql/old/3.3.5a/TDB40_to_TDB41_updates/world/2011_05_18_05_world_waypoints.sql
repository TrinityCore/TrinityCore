-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126691;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1090.053,`position_y`=657.417,`position_z`=201.9775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1094.174,663.0545,202.243,0,0,0,100,0),
(@PATH,2,1093.973,671.6352,202.1839,0,0,0,100,0),
(@PATH,3,1090.33,676.6746,201.9775,0,0,0,100,0),
(@PATH,4,1080.979,677.0645,201.9775,0,0,0,100,0),
(@PATH,5,1077.056,671.3228,202.4617,0,0,0,100,0),
(@PATH,6,1076.541,663.8468,202.5533,0,0,0,100,0),
(@PATH,7,1080.974,657.8231,201.9775,0,0,0,100,0),
(@PATH,8,1090.053,657.417,201.9775,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126695;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1170.523,`position_y`=645.3429,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1161.521,639.6048,196.235,0,0,0,100,0),
(@PATH,2,1153.933,638.7031,196.235,0,0,0,100,0),
(@PATH,3,1145.4,639.8294,196.235,0,0,0,100,0),
(@PATH,4,1138.166,644.63,196.235,0,0,0,100,0),
(@PATH,5,1145.4,639.8294,196.235,0,0,0,100,0),
(@PATH,6,1153.933,638.7031,196.235,0,0,0,100,0),
(@PATH,7,1161.521,639.6048,196.235,0,0,0,100,0),
(@PATH,8,1170.523,645.3429,196.235,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126694;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1008.858,`position_y`=651.2056,`position_z`=201.9775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1000.427,660.0714,202.4617,0,0,0,100,0),
(@PATH,2,1008.856,651.2029,201.9775,0,0,0,100,0),
(@PATH,3,1017.993,659.7945,202.4206,0,0,0,100,0),
(@PATH,4,1008.858,651.2056,201.9775,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126689;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1007.622,`position_y`=680.3897,`position_z`=201.9775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1009.632,678.1111,201.9775,0,0,0,100,0),
(@PATH,2,1011.626,675.8503,201.9775,0,0,0,100,0),
(@PATH,3,1013.619,673.5897,201.9775,0,0,0,100,0),
(@PATH,4,1014.087,673.0586,201.9775,0,0,0,100,0),
(@PATH,5,1012.174,675.2281,201.9775,0,0,0,100,0),
(@PATH,6,1010.179,677.4907,201.9775,0,0,0,100,0),
(@PATH,7,1009.943,677.858,201.9775,0,0,0,100,0),
(@PATH,8,1008.536,677.9459,201.9775,0,0,0,100,0),
(@PATH,9,1006.057,676.2379,201.9775,0,0,0,100,0),
(@PATH,10,1003.621,674.5599,201.9775,0,0,0,100,0),
(@PATH,11,1003.016,674.143,201.9775,0,0,0,100,0),
(@PATH,12,1005.35,675.7533,201.9775,0,0,0,100,0),
(@PATH,13,1007.832,677.4641,201.9775,0,0,0,100,0),
(@PATH,14,1007.622,680.3897,201.9775,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126688;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1003.653,`position_y`=679.7339,`position_z`=201.9775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1001.198,678.0424,202.4496,0,0,0,100,0),
(@PATH,2,1000.609,677.6369,202.4617,0,0,0,100,0),
(@PATH,3,1002.948,679.2506,201.9884,0,0,0,100,0),
(@PATH,4,1005.432,680.9628,201.9775,0,0,0,100,0),
(@PATH,5,1010.811,683.1892,201.9775,0,0,0,100,0),
(@PATH,6,1012.803,680.9303,201.9775,0,0,0,100,0),
(@PATH,7,1014.796,678.6695,201.9775,0,0,0,100,0),
(@PATH,8,1016.789,676.4094,202.0681,0,0,0,100,0),
(@PATH,9,1017.27,675.8646,202.2087,0,0,0,100,0),
(@PATH,10,1015.357,678.0338,201.9775,0,0,0,100,0),
(@PATH,11,1013.363,680.2949,201.9775,0,0,0,100,0),
(@PATH,12,1008.611,683.1473,201.9775,0,0,0,100,0),
(@PATH,13,1006.133,681.4426,201.9775,0,0,0,100,0),
(@PATH,14,1003.653,679.7339,201.9775,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126690;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1125.967,`position_y`=667.0475,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1126.472,676.8317,196.235,0,0,0,100,0),
(@PATH,2,1131.925,686.5771,196.235,0,0,0,100,0),
(@PATH,3,1126.472,676.8317,196.235,0,0,0,100,0),
(@PATH,4,1125.968,667.053,196.235,0,0,0,100,0),
(@PATH,5,1125.741,658.6804,196.235,0,0,0,100,0),
(@PATH,6,1130.845,649.0156,196.235,0,0,0,100,0),
(@PATH,7,1125.741,658.6804,196.235,0,0,0,100,0),
(@PATH,8,1125.967,667.0475,196.235,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1177.753,`position_y`=651.6073,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1180.727,659.129,196.2331,0,0,0,100,0),
(@PATH,2,1181.298,667.9468,196.2331,0,0,0,100,0),
(@PATH,3,1180.703,675.5833,196.235,0,0,0,100,0),
(@PATH,4,1177.057,683.4843,196.235,0,0,0,100,0),
(@PATH,5,1177.753,651.6073,196.235,0,0,0,100,0);

-- Pathing for Dark Rune Warrior Entry: 27960
SET @NPC := 126687;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1145.315,`position_y`=695.628,`position_z`=196.2341 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1153.682,695.8888,196.2342,0,0,0,100,0),
(@PATH,2,1162.608,695.6946,196.2344,0,0,0,100,0),
(@PATH,3,1170.438,690.9058,196.235,0,0,0,100,0),
(@PATH,4,1162.608,695.6946,196.2344,0,0,0,100,0),
(@PATH,5,1153.682,695.8888,196.2342,0,0,0,100,0),
(@PATH,6,1145.315,695.628,196.2341,0,0,0,100,0),
(@PATH,7,1135.572,689.3916,196.235,0,0,0,100,0),
(@PATH,8,1145.315,695.628,196.2341,0,0,0,100,0);

-- Pathing for Dark Rune Elementalist Entry: 27962
SET @NPC := 126703;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1145.024,`position_y`=642.0187,`position_z`=196.4137 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1150.999,641.2302,196.3704,0,0,0,100,0),
(@PATH,2,1153.455,640.7827,196.235,0,0,0,100,0),
(@PATH,3,1156.446,641.1381,196.3269,0,0,0,100,0),
(@PATH,4,1158.825,640.4028,196.235,0,0,0,100,0),
(@PATH,5,1161.368,642.0229,196.6185,0,0,0,100,0),
(@PATH,6,1163.906,643.6405,196.6111,0,0,0,100,0),
(@PATH,7,1166.443,645.2581,196.6037,0,0,0,100,0),
(@PATH,8,1167.594,645.9916,196.6003,0,0,0,100,0),
(@PATH,9,1165.148,644.4322,196.6075,0,0,0,100,0),
(@PATH,10,1162.606,642.8119,196.6148,0,0,0,100,0),
(@PATH,11,1160.97,641.7167,196.5989,0,0,0,100,0),
(@PATH,12,1157.9,641.3109,196.4085,0,0,0,100,0),
(@PATH,13,1155.433,640.6448,196.235,0,0,0,100,0),
(@PATH,14,1152.448,641.0389,196.2801,0,0,0,100,0),
(@PATH,15,1149.457,641.4337,196.4665,0,0,0,100,0),
(@PATH,16,1147.237,641.1562,196.3355,0,0,0,100,0),
(@PATH,17,1144.726,642.8226,196.6567,0,0,0,100,0),
(@PATH,18,1142.219,644.4866,196.6761,0,0,0,100,0),
(@PATH,19,1141.106,645.2245,196.6847,0,0,0,100,0),
(@PATH,20,1143.517,643.6247,196.666,0,0,0,100,0),
(@PATH,21,1145.024,642.0187,196.4137,0,0,0,100,0);

-- Pathing for Dark Rune Elementalist Entry: 27962
SET @NPC := 126701;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1129.024,`position_y`=657.0057,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1127.864,658.7399,196.235,0,0,0,100,0),
(@PATH,2,1127.946,661.7473,196.5042,0,0,0,100,0),
(@PATH,3,1128.027,664.7563,196.5429,0,0,0,100,0),
(@PATH,4,1128.126,667.7181,196.5897,0,0,0,100,0),
(@PATH,5,1128.281,670.7305,196.6634,0,0,0,100,0),
(@PATH,6,1128.436,673.7336,196.737,0,0,0,100,0),
(@PATH,7,1128.333,675.8134,196.344,0,0,0,100,0),
(@PATH,8,1129.804,678.4424,196.2552,0,0,0,100,0),
(@PATH,9,1131.276,681.0732,196.235,0,0,0,100,0),
(@PATH,10,1132.74,683.6888,196.235,0,0,0,100,0),
(@PATH,11,1132.74,683.69,196.235,0,0,0,100,0),
(@PATH,12,1131.326,681.163,196.235,0,0,0,100,0),
(@PATH,13,1129.854,678.5325,196.2521,0,0,0,100,0),
(@PATH,14,1128.596,676.8445,196.235,0,0,0,100,0),
(@PATH,15,1128.441,673.8321,196.7393,0,0,0,100,0),
(@PATH,16,1128.286,670.8169,196.6655,0,0,0,100,0),
(@PATH,17,1128.112,667.863,196.5829,0,0,0,100,0),
(@PATH,18,1128.03,664.851,196.5442,0,0,0,100,0),
(@PATH,19,1127.946,661.7473,196.5042,0,0,0,100,0),
(@PATH,20,1128.552,657.9015,196.2763,0,0,0,100,0),
(@PATH,21,1129.957,655.2396,196.235,0,0,0,100,0),
(@PATH,22,1131.364,652.576,196.235,0,0,0,100,0),
(@PATH,23,1131.73,651.8821,196.235,0,0,0,100,0),
(@PATH,24,1130.38,654.4395,196.235,0,0,0,100,0),
(@PATH,25,1129.024,657.0057,196.235,0,0,0,100,0);

-- Pathing for Dark Rune Theurgist Entry: 27963
SET @NPC := 126711;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1015.999,`position_y`=655.0078,`position_z`=201.9775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1017.901,656.7959,202.3935,0,0,0,100,0),
(@PATH,2,1015.829,654.8475,201.9775,0,0,0,100,0),
(@PATH,3,1013.636,652.786,201.9775,0,0,0,100,0),
(@PATH,4,1008.389,648.621,202.0844,0,0,0,100,0),
(@PATH,5,1006.314,650.805,201.9775,0,0,0,100,0),
(@PATH,6,1004.238,652.9855,201.9775,0,0,0,100,0),
(@PATH,7,1002.176,655.1539,202.1629,0,0,0,100,0),
(@PATH,8,1000.352,657.0724,202.4617,0,0,0,100,0),
(@PATH,9,1002.312,655.0092,202.1233,0,0,0,100,0),
(@PATH,10,1004.39,652.8227,201.9775,0,0,0,100,0),
(@PATH,11,1009.411,648.8157,201.9775,0,0,0,100,0),
(@PATH,12,1011.61,650.8812,201.9775,0,0,0,100,0),
(@PATH,13,1013.805,652.9445,201.9775,0,0,0,100,0),
(@PATH,14,1015.999,655.0078,201.9775,0,0,0,100,0);

-- Pathing for Dark Rune Theurgist Entry: 27963
SET @NPC := 126706;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1000.065,`position_y`=674.6865,`position_z`=202.4617 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1009.652,681.2956,201.9775,0,0,0,100,0),
(@PATH,2,1017.081,672.8705,202.1537,0,0,0,100,0),
(@PATH,3,1009.655,681.2927,201.9776,0,0,0,100,0),
(@PATH,4,1000.065,674.6865,202.4617,0,0,0,100,0);

-- Pathing for Dark Rune Theurgist Entry: 27963
SET @NPC := 126709;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1153.176,`position_y`=763.721,`position_z`=195.9379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1152.519,749.35,195.3503,0,0,0,100,0),
(@PATH,2,1153.176,763.721,195.9379,0,0,0,100,0),
(@PATH,3,1153.054,777.6341,195.0444,0,0,0,100,0),
(@PATH,4,1153.176,763.721,195.9379,0,0,0,100,0);

-- Pathing for Dark Rune Theurgist Entry: 27963
SET @NPC := 126715;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=986.8647,`position_y`=666.3177,`position_z`=202.871 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1009.195,666.1702,201.9775,0,0,0,100,0),
(@PATH,2,1035.709,665.5925,202.4466,0,0,0,100,0),
(@PATH,3,1009.197,666.1702,201.9775,0,0,0,100,0),
(@PATH,4,986.8647,666.3177,202.871,0,0,0,100,0);

-- Pathing for Dark Rune Theurgist Entry: 27963
SET @NPC := 126710;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1135.301,`position_y`=743.4152,`position_z`=195.3503 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1172.016,743.1987,195.647,0,0,0,100,0),
(@PATH,2,1135.301,743.4152,195.3503,0,0,0,100,0);

-- Pathing for Dark Rune Controller Entry: 27966
SET @NPC := 126732;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=959.431,`position_y`=770.3616,`position_z`=198.8232 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,969.4739,773.4847,199.2813,0,0,0,100,0),
(@PATH,2,967.765,784.1023,197.2568,0,0,0,100,0),
(@PATH,3,961.8073,788.9789,196.0064,0,0,0,100,0),
(@PATH,4,953.1095,795.3681,193.9678,0,0,0,100,0),
(@PATH,5,944.3715,791.49,194.977,0,0,0,100,0),
(@PATH,6,943.6695,784.9597,196.3876,0,0,0,100,0),
(@PATH,7,949.5979,774.4566,198.258,0,0,0,100,0),
(@PATH,8,959.431,770.3616,198.8232,0,0,0,100,0);

-- Pathing for Dark Rune Controller Entry: 27966
SET @NPC := 126728;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=937.8448,`position_y`=816.6932,`position_z`=189.7503 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,956.9082,820.8291,187.6685,0,0,0,100,0),
(@PATH,2,970.3458,829.6348,186.9343,0,0,0,100,0),
(@PATH,3,978.5536,836.1985,186.3881,0,0,0,100,0),
(@PATH,4,970.3458,829.6348,186.9343,0,0,0,100,0),
(@PATH,5,956.9082,820.8291,187.6685,0,0,0,100,0),
(@PATH,6,937.8448,816.6932,189.7503,0,0,0,100,0);

-- Pathing for Dark Rune Giant Entry: 27969
SET @NPC := 126733;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1048.362,`position_y`=627.2144,`position_z`=207.7195 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1048.035,534.076,207.7195,0,0,0,100,0),
(@PATH,2,1048.362,627.2144,207.7195,0,0,0,100,0);

-- Pathing for Dark Rune Giant Entry: 27969
SET @NPC := 126734;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1182.628,`position_y`=642.6927,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1191.198,663.7195,196.2346,0,0,0,100,0),
(@PATH,2,1182.631,642.6952,196.235,0,0,0,100,0),
(@PATH,3,1169.885,632.327,196.235,0,0,0,100,0),
(@PATH,4,1154.578,627.3207,196.235,0,0,0,100,0),
(@PATH,5,1140.422,631.9984,196.235,0,0,0,100,0),
(@PATH,6,1124.699,645.2076,196.235,0,0,0,100,0),
(@PATH,7,1121.548,657.0721,196.235,0,0,0,100,0),
(@PATH,8,1124.699,645.2076,196.235,0,0,0,100,0),
(@PATH,9,1140.422,631.9984,196.235,0,0,0,100,0),
(@PATH,10,1154.578,627.3207,196.235,0,0,0,100,0),
(@PATH,11,1169.885,632.327,196.235,0,0,0,100,0),
(@PATH,12,1182.628,642.6927,196.235,0,0,0,100,0);

-- Pathing for Dark Rune Giant Entry: 27969
SET @NPC := 126736;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=905.2296,`position_y`=666.2713,`position_z`=196.4107 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,946.57,666.5284,196.1596,0,0,0,100,0),
(@PATH,2,968.8573,666.6479,196.4836,0,0,0,100,0),
(@PATH,3,946.5755,666.5284,196.1597,0,0,0,100,0),
(@PATH,4,905.2296,666.2713,196.4107,0,0,0,100,0);

-- Pathing for Dark Rune Giant Entry: 27969
SET @NPC := 126735;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1124.234,`position_y`=666.6528,`position_z`=196.235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1122.256,687.0065,196.235,0,0,0,100,0),
(@PATH,2,1133.015,698.6454,196.235,0,0,0,100,0),
(@PATH,3,1148.657,706.8157,196.2355,0,0,0,100,0),
(@PATH,4,1161.399,706.7985,196.2357,0,0,0,100,0),
(@PATH,5,1177.772,696.8011,196.2348,0,0,0,100,0),
(@PATH,6,1186.349,682.7001,196.235,0,0,0,100,0),
(@PATH,7,1177.772,696.8011,196.2348,0,0,0,100,0),
(@PATH,8,1161.399,706.7985,196.2357,0,0,0,100,0),
(@PATH,9,1148.657,706.8157,196.2355,0,0,0,100,0),
(@PATH,10,1133.015,698.6454,196.235,0,0,0,100,0),
(@PATH,11,1122.256,687.0065,196.235,0,0,0,100,0),
(@PATH,12,1124.234,666.6528,196.235,0,0,0,100,0);

-- Pathing for Lightning Construct Entry: 27972
SET @NPC := 126746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=972.5233,`position_y`=420.2028,`position_z`=205.9943 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,980.9671,415.2457,205.9943,0,0,0,100,0),
(@PATH,2,972.5233,420.2028,205.9943,0,0,0,100,0),
(@PATH,3,961.5862,421.183,205.9943,0,0,0,100,0),
(@PATH,4,952.4949,416.0938,205.9943,0,0,0,100,0),
(@PATH,5,961.5389,421.1565,205.9943,0,0,0,100,0),
(@PATH,6,972.5233,420.2028,205.9943,0,0,0,100,0);

-- Pathing for Lightning Construct Entry: 27972
SET @NPC := 126750;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=967.9682,`position_y`=381.0118,`position_z`=205.9943 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,954.208,382.8831,205.9943,0,0,0,100,0),
(@PATH,2,944.4269,394.0551,205.9943,0,0,0,100,0),
(@PATH,3,946.6729,409.3246,205.9943,0,0,0,100,0),
(@PATH,4,944.4262,394.0558,205.9943,0,0,0,100,0),
(@PATH,5,954.208,382.8831,205.9943,0,0,0,100,0),
(@PATH,6,967.9682,381.0118,205.9943,0,0,0,100,0);

-- Pathing for Lightning Construct Entry: 27972
SET @NPC := 126749;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=983.2661,`position_y`=390.105,`position_z`=205.9943 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,986.5608,402.9213,205.9943,0,0,0,100,0),
(@PATH,2,983.0714,412.1025,205.9943,0,0,0,100,0),
(@PATH,3,986.5522,402.9439,205.9943,0,0,0,100,0),
(@PATH,4,983.2661,390.105,205.9943,0,0,0,100,0),
(@PATH,5,974.4719,382.4703,205.9943,0,0,0,100,0),
(@PATH,6,983.2661,390.105,205.9943,0,0,0,100,0);

-- Pathing for Crystalline Shardling Entry: 27973
SET @NPC := 126787;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=938.4828,`position_y`=813.7618,`position_z`=189.9927 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,942.4637,814.6254,189.3832,0,0,0,100,0),
(@PATH,2,945.379,815.2579,188.9368,0,0,0,100,0),
(@PATH,3,948.2987,815.8914,188.4898,0,0,0,100,0),
(@PATH,4,951.2225,816.5258,188.1479,0,0,0,100,0),
(@PATH,5,954.1625,817.1636,188.069,0,0,0,100,0),
(@PATH,6,957.1072,817.8024,187.99,0,0,0,100,0),
(@PATH,7,960.6969,819.7251,187.7678,0,0,0,100,0),
(@PATH,8,965.7293,823.0229,187.4797,0,0,0,100,0),
(@PATH,9,968.2454,824.6718,187.3356,0,0,0,100,0),
(@PATH,10,970.7648,826.3227,187.1914,0,0,0,100,0),
(@PATH,11,973.4231,828.2544,187.06,0,0,0,100,0),
(@PATH,12,975.7665,830.1284,186.9356,0,0,0,100,0),
(@PATH,13,978.1152,832.0066,186.8109,0,0,0,100,0),
(@PATH,14,980.4257,833.8543,186.6883,0,0,0,100,0),
(@PATH,15,977.209,831.2819,186.8591,0,0,0,100,0),
(@PATH,16,974.8596,829.4031,186.9837,0,0,0,100,0),
(@PATH,17,972.5027,827.5184,187.1088,0,0,0,100,0),
(@PATH,18,969.7669,825.6686,187.2486,0,0,0,100,0),
(@PATH,19,967.2497,824.0191,187.3926,0,0,0,100,0),
(@PATH,20,964.7295,822.3676,187.5369,0,0,0,100,0),
(@PATH,21,962.2039,820.7126,187.6815,0,0,0,100,0),
(@PATH,22,959.684,819.0614,187.8257,0,0,0,100,0),
(@PATH,23,955.9277,817.5466,188.0217,0,0,0,100,0),
(@PATH,24,952.986,816.9084,188.1006,0,0,0,100,0),
(@PATH,25,950.0452,816.2703,188.2224,0,0,0,100,0),
(@PATH,26,947.1313,815.6381,188.6686,0,0,0,100,0),
(@PATH,27,941.3091,814.3749,189.56,0,0,0,100,0),
(@PATH,28,938.4828,813.7618,189.9927,0,0,0,100,0);

-- Pathing for Crystalline Shardling Entry: 27973
SET @NPC := 126788;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=937.2088,`position_y`=819.625,`position_z`=189.5746 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,941.1921,820.4892,188.9586,0,0,0,100,0),
(@PATH,2,944.1083,821.1219,188.5076,0,0,0,100,0),
(@PATH,3,947.0261,821.7549,188.0563,0,0,0,100,0),
(@PATH,4,949.9498,822.3893,187.7245,0,0,0,100,0),
(@PATH,5,952.8904,823.0272,187.5842,0,0,0,100,0),
(@PATH,6,955.8341,823.6659,187.4437,0,0,0,100,0),
(@PATH,7,957.4083,824.7435,187.3226,0,0,0,100,0),
(@PATH,8,962.4407,828.0413,186.9908,0,0,0,100,0),
(@PATH,9,964.958,829.6909,186.8311,0,0,0,100,0),
(@PATH,10,967.4774,831.3419,186.6792,0,0,0,100,0),
(@PATH,11,969.6763,832.9407,186.5558,0,0,0,100,0),
(@PATH,12,972.0192,834.8143,186.4057,0,0,0,100,0),
(@PATH,13,974.3668,836.6917,186.2552,0,0,0,100,0),
(@PATH,14,976.6784,838.5402,186.1071,0,0,0,100,0),
(@PATH,15,973.4617,835.9678,186.3132,0,0,0,100,0),
(@PATH,16,971.1112,834.0882,186.4638,0,0,0,100,0),
(@PATH,17,968.7542,832.2033,186.6149,0,0,0,100,0),
(@PATH,18,966.4784,830.6872,186.7346,0,0,0,100,0),
(@PATH,19,963.961,829.0375,186.8943,0,0,0,100,0),
(@PATH,20,961.4396,827.3853,187.0543,0,0,0,100,0),
(@PATH,21,958.9153,825.7311,187.2144,0,0,0,100,0),
(@PATH,22,956.396,824.0802,187.3987,0,0,0,100,0),
(@PATH,23,954.6556,823.4102,187.5,0,0,0,100,0),
(@PATH,24,951.9318,822.8305,187.6292,0,0,0,100,0),
(@PATH,25,948.8242,822.1456,187.7782,0,0,0,100,0),
(@PATH,26,945.8588,821.5016,188.2368,0,0,0,100,0),
(@PATH,27,940.0389,820.239,189.1369,0,0,0,100,0),
(@PATH,28,937.2088,819.625,189.5746,0,0,0,100,0);
