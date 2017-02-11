-- Bleeding Hollow Peon - Movement + Emotescript
SET @MAXGUID := 945; 
SET @SCRIPTID := 5862800; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES 
-- EMOTE (state)
(@SCRIPTID+0, 2, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 42, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 58628;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0,`MovementType`= 2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`action`,`delay`) VALUES
(@PATH,  1, -1066.28, 2076.29, 65.2581, 2.20343, 0, 0),
(@PATH,  2, -1084.71, 2090.96, 64.0698, 2.9684,  0, 0),
(@PATH,  3, -1107.22, 2093.74, 67.0261, 3.23937, 0, 0),
(@PATH,  4, -1126.19, 2091.05, 67.6642, 3.41215, 0, 0),
(@PATH,  5, -1140.15, 2088.18, 67.046,  3.85198, 0, 0),
(@PATH,  6, -1144.39, 2084.57, 66.9404, 3.93593, @SCRIPTID, 45000),
(@PATH,  7, -1132.81, 2089.31, 67.6161, 0.167592,0, 0),
(@PATH,  8, -1115.34, 2093.11, 67.5254, 0.0058,  0, 0),
(@PATH,  9, -1091.94, 2092.04, 65.1282, 5.93556, 0, 0),
(@PATH, 10, -1073.86, 2086.69, 63.2546, 5.72507, 0, 0),
(@PATH, 11, -1064.04, 2075.59, 65.6203, 5.00251, 0, 0),
(@PATH, 12, -1064.26, 2062.38, 67.3094, 4.686,   @SCRIPTID, 45000);

SET @NPC := 58632;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0,`MovementType`= 2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`action`,`delay`) VALUES
(@PATH,  1, -967.837, 2049.47, 66.9396, 1.04197, 0, 0),
(@PATH,  2, -961.27,  2056.9,  66.9396, 1.31921, 0, 0),
(@PATH,  3, -959.369, 2062.51, 66.9396, 1.27759, @SCRIPTID, 45000),
(@PATH,  4, -963.171, 2062.44, 66.9396, 2.69897, 0, 0),
(@PATH,  5, -972.978, 2069.15, 67.2109, 2.68091, 0, 0),
(@PATH,  6, -980.363, 2071.69, 68.1111, 3.50008, 0, 0),
(@PATH,  7, -983.956, 2068.97, 67.4094, 4.27448, 0, 0),
(@PATH,  8, -985.507, 2063.74, 66.9396, 4.73079, 0, 0),
(@PATH,  9, -981.499, 2052.05, 67.3838, 5.23737, 0, 0),
(@PATH, 10, -969.215, 2033.99, 66.9399, 5.01824, 0, 0),
(@PATH, 11, -967.02,  2022.12, 66.9399, 4.62633, 0, 0),
(@PATH, 12, -967.238, 2012.22, 66.9399, 4.5423,  @SCRIPTID, 45000),
(@PATH, 13, -966.301, 2034.51, 66.9405, 1.55778, 0, 0);

SET @NPC := 58635;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0,`MovementType`= 2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`action`,`delay`) VALUES
(@PATH, 1, -930.128, 2000.58, 65.8055, 3.10085, 0, 0),
(@PATH, 2, -943.891, 2000.6,  66.8665, 3.1574,  @SCRIPTID, 45000),
(@PATH, 3, -927.429, 1999.94, 65.7533, 5.91571, 0, 0),
(@PATH, 4, -916.524, 1997.9,  66.3727, 5.4429,  0, 0),
(@PATH, 5, -911.155, 1991.46, 67.3741, 5.12875, 0, 0),
(@PATH, 6, -906.294, 1982.16, 67.5317, 5.10519, @SCRIPTID, 45000),
(@PATH, 7, -912.459, 1992.95, 67.1693, 2.59192, 0, 0),
(@PATH, 8, -925.844, 1998.59, 65.8413, 2.45997, 0, 0);

SET @NPC := 58636;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0,`MovementType`= 2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`action`,`delay`) VALUES
(@PATH,  1, -989.995, 1941.95, 71.4595, 2.19392, 0, 0),
(@PATH,  2, -1008.41, 1959.06, 68.9236, 2.41776, 0, 0),
(@PATH,  3, -1019.71, 1969.1,  68.6018, 2.38635, 0, 0),
(@PATH,  4, -1026.27, 1974.99, 70.055,  1.87191, 0, 0),
(@PATH,  5, -1026.92, 1982.57, 69.3283, 1.70698, @SCRIPTID, 45000),
(@PATH,  6, -1025.51, 1975.34, 69.8823, 5.22006, 0, 0),
(@PATH,  7, -1020.08, 1966.5,  68.308,  6.11541, 0, 0),
(@PATH,  8, -995.228, 1955.72, 69.9662, 5.31744, 0, 0),
(@PATH,  9, -978.143, 1924.37, 75.1594, 5.15555, 0, 0),
(@PATH, 10, -971.913, 1906.66, 81.0091, 4.7927, 0, 0),
(@PATH, 11, -969.988, 1896.65, 85.587,  4.44712, 0, 0),
(@PATH, 12, -968.026, 1884.12, 93.5716, 4.80605, @SCRIPTID, 45000),
(@PATH, 13, -968.339, 1894.25, 86.2747, 1.97154, 0, 0),
(@PATH, 14, -971.346, 1907.8,  80.164,  2.20952, 0, 0),
(@PATH, 15, -978.063, 1919.93, 76.9127, 2.11606, 0, 0);

SET @NPC := 58638;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0,`MovementType`= 2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`action`,`delay`) VALUES
(@PATH,  1, -969.117, 1895.51, 85.8342, 3.44732, 0, 0),
(@PATH,  2, -979.002, 1893.24, 92.7384, 3.86279, 0, 0),
(@PATH,  3, -980.753, 1889.95, 94.2667, 4.52409, @SCRIPTID, 45000),
(@PATH,  4, -969.104, 1893.87, 86.9405, 0.295507,0, 0),
(@PATH,  5, -943.258, 1896.12, 76.5289, 0.226394,0, 0),
(@PATH,  6, -927.465, 1904.29, 70.9232, 0.853927,0, 0),
(@PATH,  7, -918.028, 1919.59, 67.2824, 1.03928, 0, 0),
(@PATH,  8, -912.198, 1930.65, 66.9439, 0.900266,0, 0),
(@PATH,  9, -906.253, 1936.39, 66.9409, 6.10431, 0, 0),
(@PATH, 10, -902.916, 1935.38, 66.9409, 5.57889, 0, 0),
(@PATH, 11, -899.893, 1931.82, 66.9409, 5.33149, @SCRIPTID, 45000),
(@PATH, 12, -904.32,  1933.33, 66.9409, 3.3892,  0, 0),
(@PATH, 13, -909.279, 1931.34, 66.9409, 3.93348, 0, 0),
(@PATH, 14, -923.102, 1907.03, 69.6799, 3.97431, 0, 0),
(@PATH, 15, -935.694, 1898.91, 74.0559, 3.26588, 0, 0),
(@PATH, 16, -957.265, 1896.2,  79.8492, 3.07739, 0, 0);

UPDATE `waypoint_data` SET `action_chance`= 100 WHERE `action` IN (@SCRIPTID);
