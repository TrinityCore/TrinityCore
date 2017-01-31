-- This Stormforged War Golem has a larger random movement than in db
UPDATE `creature` SET `spawndist`=10 WHERE `guid`=114468;

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114457;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8023.331,`position_y`=77.24121,`position_z`=999.9595 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8023.331,77.24121,999.9595,0,0,0,0,100,0),
(@PATH,2,8016.558,64.0587,989.7907,0,0,0,0,100,0),
(@PATH,3,8009.225,52.23459,980.1657,0,0,0,0,100,0),
(@PATH,4,8005.339,45.29612,973.7907,0,0,0,0,100,0),
(@PATH,5,8001.864,36.03364,967.7907,0,0,0,0,100,0),
(@PATH,6,8000.232,26.16992,963.5776,0,0,0,0,100,0),
(@PATH,7,8001.864,36.03364,967.7907,0,0,0,0,100,0),
(@PATH,8,8005.339,45.29612,973.7907,0,0,0,0,100,0),
(@PATH,9,8009.225,52.23459,980.1657,0,0,0,0,100,0),
(@PATH,10,8016.558,64.0587,989.7907,0,0,0,0,100,0),
(@PATH,11,8023.331,77.24121,999.9595,0,0,0,0,100,0),
(@PATH,12,8032.478,95.32867,1012.085,0,0,0,0,100,0),
(@PATH,13,8031.838,102.6918,1015.026,0,0,0,0,100,0),
(@PATH,14,8023.94,108.6624,1017.026,0,0,0,0,100,0),
(@PATH,15,8014.495,112.6428,1019.401,0,0,0,0,100,0),
(@PATH,16,8003.407,107.8157,1021.276,0,0,0,0,100,0),
(@PATH,17,7993.737,99.56966,1024.987,0,0,0,0,100,0),
(@PATH,18,8003.407,107.8157,1021.276,0,0,0,0,100,0),
(@PATH,19,8014.495,112.6428,1019.401,0,0,0,0,100,0),
(@PATH,20,8023.94,108.6624,1017.026,0,0,0,0,100,0),
(@PATH,21,8031.838,102.6918,1015.026,0,0,0,0,100,0),
(@PATH,22,8032.478,95.32867,1012.085,0,0,0,0,100,0),
(@PATH,23,8028.997,86.29623,1006.21,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114469;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8210.855,`position_y`=83.22288,`position_z`=899.8224 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8210.855,83.22288,899.8224,0,0,0,0,100,0),
(@PATH,2,8206.622,70.00694,899.5724,0,0,0,0,100,0),
(@PATH,3,8197.973,61.24078,899.2055,0,0,0,0,100,0),
(@PATH,4,8184.639,55.54492,899.8305,0,0,0,0,100,0),
(@PATH,5,8197.973,61.24078,899.2055,0,0,0,0,100,0),
(@PATH,6,8206.622,70.00694,899.5724,0,0,0,0,100,0),
(@PATH,7,8210.855,83.22288,899.8224,0,0,0,0,100,0),
(@PATH,8,8206.317,98.42123,900.0724,0,0,0,0,100,0),
(@PATH,9,8198.927,116.0298,899.1041,0,0,0,0,100,0),
(@PATH,10,8206.317,98.42123,900.0724,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114458;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8174.757,`position_y`=6.792969,`position_z`=852.8932 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8174.757,6.792969,852.8932,0,0,0,0,100,0),
(@PATH,2,8163.236,5.554037,856.1956,0,0,0,0,100,0),
(@PATH,3,8148.116,-1.020725,859.5831,0,0,0,0,100,0),
(@PATH,4,8136.771,-4.926215,860.8331,0,0,0,0,100,0),
(@PATH,5,8126.096,-10.58008,863.0983,0,0,0,0,100,0),
(@PATH,6,8115.336,-16.46669,866.2233,0,0,0,0,100,0),
(@PATH,7,8125.859,-10.70117,863.4733,0,0,0,0,100,0),
(@PATH,8,8136.771,-4.926215,860.8331,0,0,0,0,100,0),
(@PATH,9,8148.116,-1.020725,859.5831,0,0,0,0,100,0),
(@PATH,10,8163.236,5.554037,856.1956,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114470;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8115.971,`position_y`=42.09624,`position_z`=900.9437 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8115.971,42.09624,900.9437,0,0,0,0,100,0),
(@PATH,2,8126.555,49.1735,902.4437,0,0,0,0,100,0),
(@PATH,3,8115.971,42.09624,900.9437,0,0,0,0,100,0),
(@PATH,4,8105.812,37.60786,898.8187,0,0,0,0,100,0),
(@PATH,5,8094.797,32.17817,896.4277,0,0,0,0,100,0),
(@PATH,6,8084.893,20.01226,892.8027,0,0,0,0,100,0),
(@PATH,7,8076.25,7.765625,888.1777,0,0,0,0,100,0),
(@PATH,8,8070.748,-0.3867188,883.864,0,0,0,0,100,0),
(@PATH,9,8068.489,-9.105469,880.239,0,0,0,0,100,0),
(@PATH,10,8070.748,-0.3867188,883.864,0,0,0,0,100,0),
(@PATH,11,8076.067,7.493273,888.1777,0,0,0,0,100,0),
(@PATH,12,8084.893,20.01226,892.8027,0,0,0,0,100,0),
(@PATH,13,8094.797,32.17817,896.4277,0,0,0,0,100,0),
(@PATH,14,8105.812,37.60786,898.8187,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114456;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8083.848,`position_y`=66.86187,`position_z`=928.5247 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8083.848,66.86187,928.5247,0,0,0,0,100,0),
(@PATH,2,8055.064,57.03885,945.9103,0,0,0,0,100,0),
(@PATH,3,8044.63,51.07888,947.9103,0,0,0,0,100,0),
(@PATH,4,8036.362,43.75098,948.4103,0,0,0,0,100,0),
(@PATH,5,8028.82,33.40723,952.9157,0,0,0,0,100,0),
(@PATH,6,8021.039,24.85319,956.2026,0,0,0,0,100,0),
(@PATH,7,8015.258,18.09885,958.2026,0,0,0,0,100,0),
(@PATH,8,8021.039,24.85319,956.2026,0,0,0,0,100,0),
(@PATH,9,8028.82,33.40723,952.9157,0,0,0,0,100,0),
(@PATH,10,8036.362,43.75098,948.4103,0,0,0,0,100,0),
(@PATH,11,8044.63,51.07888,947.9103,0,0,0,0,100,0),
(@PATH,12,8055.064,57.03885,945.9103,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114452;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7891.817,`position_y`=29.8049,`position_z`=1012.99 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7891.817,29.8049,1012.99,0,0,0,0,100,0),
(@PATH,2,7902.199,39.88314,1019.54,0,0,0,0,100,0),
(@PATH,3,7910.464,47.52941,1024.165,0,0,0,0,100,0),
(@PATH,4,7917.577,54.32107,1027.29,0,0,0,0,100,0),
(@PATH,5,7910.464,47.52941,1024.165,0,0,0,0,100,0),
(@PATH,6,7902.199,39.88314,1019.54,0,0,0,0,100,0),
(@PATH,7,7891.817,29.8049,1012.99,0,0,0,0,100,0),
(@PATH,8,7877.582,23.72005,1007.24,0,0,0,0,100,0),
(@PATH,9,7858.5,22.52029,1004.369,0,0,0,0,100,0),
(@PATH,10,7845.615,28.44293,1005.119,0,0,0,0,100,0),
(@PATH,11,7834.722,33.47287,1007.502,0,0,0,0,100,0),
(@PATH,12,7825.046,33.51389,1009.348,0,0,0,0,100,0),
(@PATH,13,7834.722,33.47287,1007.502,0,0,0,0,100,0),
(@PATH,14,7845.615,28.44293,1005.119,0,0,0,0,100,0),
(@PATH,15,7858.5,22.52029,1004.369,0,0,0,0,100,0),
(@PATH,16,7877.582,23.72005,1007.24,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114466;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8052.202,`position_y`=-165.8067,`position_z`=858.999 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8052.202,-165.8067,858.999,0,0,0,0,100,0),
(@PATH,2,8059.497,-161.3153,857.999,0,0,0,0,100,0),
(@PATH,3,8071.769,-156.6751,858.2012,0,0,0,0,100,0),
(@PATH,4,8086.116,-153.3002,856.5762,0,0,0,0,100,0),
(@PATH,5,8095.891,-153.3699,857.7012,0,0,0,0,100,0),
(@PATH,6,8105.404,-155.2473,858.9095,0,0,0,0,100,0),
(@PATH,7,8095.891,-153.3699,857.7012,0,0,0,0,100,0),
(@PATH,8,8086.116,-153.3002,856.5762,0,0,0,0,100,0),
(@PATH,9,8071.769,-156.6751,858.2012,0,0,0,0,100,0),
(@PATH,10,8059.497,-161.3153,857.999,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114463;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8070.4,`position_y`=-277.1614,`position_z`=864.549 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8070.4,-277.1614,864.549,0,0,0,0,100,0),
(@PATH,2,8062.835,-282.7156,867.5071,0,0,0,0,100,0),
(@PATH,3,8056.209,-286.8712,868.4637,0,0,0,0,100,0),
(@PATH,4,8048.796,-294.7416,868.7055,0,0,0,0,100,0),
(@PATH,5,8044.233,-303.6937,867.402,0,0,0,0,100,0),
(@PATH,6,8037.981,-317.1875,865.6969,0,0,0,0,100,0),
(@PATH,7,8028.49,-325.9581,864.4135,0,0,0,0,100,0),
(@PATH,8,8020.713,-345.0319,859.0582,0,0,0,0,100,0),
(@PATH,9,8009.588,-357.7793,853.5903,0,0,0,0,100,0),
(@PATH,10,8020.713,-345.0319,859.0582,0,0,0,0,100,0),
(@PATH,11,8028.449,-326.0605,864.4465,0,0,0,0,100,0),
(@PATH,12,8037.981,-317.1875,865.6969,0,0,0,0,100,0),
(@PATH,13,8044.233,-303.6937,867.402,0,0,0,0,100,0),
(@PATH,14,8048.796,-294.7416,868.7055,0,0,0,0,100,0),
(@PATH,15,8056.209,-286.8712,868.4637,0,0,0,0,100,0),
(@PATH,16,8062.701,-282.7995,867.561,0,0,0,0,100,0),
(@PATH,17,8070.4,-277.1614,864.549,0,0,0,0,100,0),
(@PATH,18,8076.281,-272.4348,863.3943,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114467;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8066.473,`position_y`=-227.3648,`position_z`=850.1917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8066.473,-227.3648,850.1917,0,0,0,0,100,0),
(@PATH,2,8060.724,-215.8946,847.5667,0,0,0,0,100,0),
(@PATH,3,8066.473,-227.3648,850.1917,0,0,0,0,100,0),
(@PATH,4,8072.938,-237.2425,853.0301,0,0,0,0,100,0),
(@PATH,5,8082.311,-252.4066,857.7801,0,0,0,0,100,0),
(@PATH,6,8092.322,-256.9824,859.9051,0,0,0,0,100,0),
(@PATH,7,8104.916,-253.7578,862.3018,0,0,0,0,100,0),
(@PATH,8,8092.322,-256.9824,859.9051,0,0,0,0,100,0),
(@PATH,9,8082.311,-252.4066,857.7801,0,0,0,0,100,0),
(@PATH,10,8072.938,-237.2425,853.0301,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114462;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7951.181,`position_y`=-303.6466,`position_z`=868.0612 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7951.181,-303.6466,868.0612,0,0,0,0,100,0),
(@PATH,2,7953.972,-293.1617,864.6669,0,0,0,0,100,0),
(@PATH,3,7958.955,-282.3007,860.7919,0,0,0,0,100,0),
(@PATH,4,7962.751,-272.1515,857.0419,0,0,0,0,100,0),
(@PATH,5,7966.29,-263.5002,854.0172,0,0,0,0,100,0),
(@PATH,6,7970.295,-257.2281,851.6115,0,0,0,0,100,0),
(@PATH,7,7966.29,-263.5002,854.0172,0,0,0,0,100,0),
(@PATH,8,7962.751,-272.1515,857.0419,0,0,0,0,100,0),
(@PATH,9,7958.955,-282.3007,860.7919,0,0,0,0,100,0),
(@PATH,10,7953.972,-293.1617,864.6669,0,0,0,0,100,0),
(@PATH,11,7951.181,-303.6466,868.0612,0,0,0,0,100,0),
(@PATH,12,7947.293,-317.9044,872.9362,0,0,0,0,100,0),
(@PATH,13,7946.081,-328.0955,876.0612,0,0,0,0,100,0),
(@PATH,14,7947.293,-317.9044,872.9362,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114460;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7988.024,`position_y`=-360.8784,`position_z`=851.5723 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7988.024,-360.8784,851.5723,0,0,0,0,100,0),
(@PATH,2,7981.517,-348.1698,848.4473,0,0,0,0,100,0),
(@PATH,3,7981.517,-337.562,848.1973,0,0,0,0,100,0),
(@PATH,4,7984.724,-323.3203,847.6024,0,0,0,0,100,0),
(@PATH,5,7990.423,-311.3583,847.1024,0,0,0,0,100,0),
(@PATH,6,7984.724,-323.3203,847.6024,0,0,0,0,100,0),
(@PATH,7,7981.517,-337.562,848.1973,0,0,0,0,100,0),
(@PATH,8,7981.517,-348.1698,848.4473,0,0,0,0,100,0),
(@PATH,9,7988.024,-360.8784,851.5723,0,0,0,0,100,0),
(@PATH,10,7993.853,-367.1549,852.2777,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114464;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7938.075,`position_y`=-292.4181,`position_z`=872.0419 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7938.075,-292.4181,872.0419,0,0,0,0,100,0),
(@PATH,2,7933.337,-302.122,873.6862,0,0,0,0,100,0),
(@PATH,3,7929.871,-311.5463,875.9217,0,0,0,0,100,0),
(@PATH,4,7933.337,-302.122,873.6862,0,0,0,0,100,0),
(@PATH,5,7938.075,-292.4181,872.0419,0,0,0,0,100,0),
(@PATH,6,7937.996,-284.6571,872.2919,0,0,0,0,100,0),
(@PATH,7,7940.083,-276.4322,873.5419,0,0,0,0,100,0),
(@PATH,8,7944.605,-263.8913,873.1422,0,0,0,0,100,0),
(@PATH,9,7947.522,-254.4118,872.0172,0,0,0,0,100,0),
(@PATH,10,7963.557,-224.8985,868.0352,0,0,0,0,100,0),
(@PATH,11,7948.587,-241.9518,872.2672,0,0,0,0,100,0),
(@PATH,12,7970.556,-216.756,868.567,0,0,0,0,100,0),
(@PATH,13,7983.082,-208.4296,868.817,0,0,0,0,100,0),
(@PATH,14,7970.556,-216.756,868.567,0,0,0,0,100,0),
(@PATH,15,7948.587,-241.9518,872.2672,0,0,0,0,100,0),
(@PATH,16,7963.557,-224.8985,868.0352,0,0,0,0,100,0),
(@PATH,17,7947.522,-254.4118,872.0172,0,0,0,0,100,0),
(@PATH,18,7944.605,-263.8913,873.1422,0,0,0,0,100,0),
(@PATH,19,7940.083,-276.4322,873.5419,0,0,0,0,100,0),
(@PATH,20,7937.996,-284.6571,872.2919,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114448;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8292.766,`position_y`=-246.2448,`position_z`=925.6675 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8292.766,-246.2448,925.6675,0,0,0,0,100,0),
(@PATH,2,8301.604,-243.4602,923.659,0,0,0,0,100,0),
(@PATH,3,8292.766,-246.2448,925.6675,0,0,0,0,100,0),
(@PATH,4,8280.42,-246.1662,933.0425,0,0,0,0,100,0),
(@PATH,5,8269.42,-246.2734,940.4175,0,0,0,0,100,0),
(@PATH,6,8260.231,-245.6485,946.4034,0,0,0,0,100,0),
(@PATH,7,8245.475,-248.834,952.5284,0,0,0,0,100,0),
(@PATH,8,8239.138,-252.9452,952.7784,0,0,0,0,100,0),
(@PATH,9,8245.475,-248.834,952.5284,0,0,0,0,100,0),
(@PATH,10,8260.231,-245.6485,946.4034,0,0,0,0,100,0),
(@PATH,11,8269.42,-246.2734,940.4175,0,0,0,0,100,0),
(@PATH,12,8280.42,-246.1662,933.0425,0,0,0,0,100,0),
(@PATH,13,8292.766,-246.2448,925.6675,0,0,0,0,100,0),
(@PATH,14,8301.604,-243.4602,923.659,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114454;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8287.12,`position_y`=-232.0705,`position_z`=920.8063 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8287.12,-232.0705,920.8063,0,0,0,0,100,0),
(@PATH,2,8279.343,-226.6951,918.1813,0,0,0,0,100,0),
(@PATH,3,8270.205,-221.0446,914.4313,0,0,0,0,100,0),
(@PATH,4,8260.98,-219.1772,911.1617,0,0,0,0,100,0),
(@PATH,5,8251.401,-217.5979,908.6617,0,0,0,0,100,0),
(@PATH,6,8240.566,-216.677,906.1617,0,0,0,0,100,0),
(@PATH,7,8232.138,-216.4807,904.547,0,0,0,0,100,0),
(@PATH,8,8224.63,-221.0824,903.422,0,0,0,0,100,0),
(@PATH,9,8217.282,-228.2757,902.297,0,0,0,0,100,0),
(@PATH,10,8209.278,-233.1008,901.422,0,0,0,0,100,0),
(@PATH,11,8199.357,-237.1406,897.0337,0,0,0,0,100,0),
(@PATH,12,8209.278,-233.1008,901.422,0,0,0,0,100,0),
(@PATH,13,8217.282,-228.2757,902.297,0,0,0,0,100,0),
(@PATH,14,8224.63,-221.0824,903.422,0,0,0,0,100,0),
(@PATH,15,8232.138,-216.4807,904.547,0,0,0,0,100,0),
(@PATH,16,8240.566,-216.677,906.1617,0,0,0,0,100,0),
(@PATH,17,8251.401,-217.5979,908.6617,0,0,0,0,100,0),
(@PATH,18,8260.98,-219.1772,911.1617,0,0,0,0,100,0),
(@PATH,19,8270.205,-221.0446,914.4313,0,0,0,0,100,0),
(@PATH,20,8279.343,-226.6951,918.1813,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7763.875,`position_y`=25.31001,`position_z`=1009.387 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7763.875,25.31001,1009.387,0,0,0,0,100,0),
(@PATH,2,7774.83,29.45172,1009.433,0,0,0,0,100,0),
(@PATH,3,7784.966,36.1964,1009.425,0,0,0,0,100,0),
(@PATH,4,7792.793,46.41374,1009.425,0,0,0,0,100,0),
(@PATH,5,7784.966,36.1964,1009.425,0,0,0,0,100,0),
(@PATH,6,7774.83,29.45172,1009.433,0,0,0,0,100,0),
(@PATH,7,7763.875,25.31001,1009.387,0,0,0,0,100,0),
(@PATH,8,7757.785,17.42741,1009.387,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114471;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8062.678,`position_y`=-34.05208,`position_z`=872.399 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8062.678,-34.05208,872.399,0,0,0,0,100,0),
(@PATH,2,8050.187,-36.93273,874.024,0,0,0,0,100,0),
(@PATH,3,8041.209,-47.45063,875.399,0,0,0,0,100,0),
(@PATH,4,8050.187,-36.93273,874.024,0,0,0,0,100,0),
(@PATH,5,8062.678,-34.05208,872.399,0,0,0,0,100,0),
(@PATH,6,8071.337,-37.65701,869.6487,0,0,0,0,100,0),
(@PATH,7,8083.439,-34.81456,866.6487,0,0,0,0,100,0),
(@PATH,8,8092.34,-23.51801,869.239,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114450;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8020.559,`position_y`=-462.7457,`position_z`=945.5956 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8020.559,-462.7457,945.5956,0,0,0,0,100,0),
(@PATH,2,8021.167,-454.9322,943.7206,0,0,0,0,100,0),
(@PATH,3,8021.333,-447.3739,941.8456,0,0,0,0,100,0),
(@PATH,4,8019.993,-438.8365,940.0956,0,0,0,0,100,0),
(@PATH,5,8018.624,-428.8778,938.6416,0,0,0,0,100,0),
(@PATH,6,8015.852,-421.9554,938.6416,0,0,0,0,100,0),
(@PATH,7,8015.377,-415.9785,937.8916,0,0,0,0,100,0),
(@PATH,8,8015.852,-421.9554,938.6416,0,0,0,0,100,0),
(@PATH,9,8018.624,-428.8778,938.6416,0,0,0,0,100,0),
(@PATH,10,8019.993,-438.8365,940.0956,0,0,0,0,100,0),
(@PATH,11,8021.333,-447.3739,941.8456,0,0,0,0,100,0),
(@PATH,12,8021.167,-454.9322,943.7206,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114465;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8135.024,`position_y`=-370.0041,`position_z`=963.259 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8135.024,-370.0041,963.259,0,0,0,100,0),
(@PATH,2,8141.749,-366.09,960.2184,0,0,0,100,0),
(@PATH,3,8149.224,-360.9964,959.7184,0,0,0,100,0),
(@PATH,4,8154.405,-356.4004,961.2184,0,0,0,100,0),
(@PATH,5,8159.849,-352.6774,963.8434,0,0,0,100,0),
(@PATH,6,8165.625,-349.4785,964.9684,0,0,0,100,0),
(@PATH,7,8172.873,-345.124,967.3318,0,0,0,100,0),
(@PATH,8,8180.829,-338.1227,969.8495,0,0,0,100,0),
(@PATH,9,8188.221,-330.7452,970.2561,0,0,0,100,0),
(@PATH,10,8195.111,-320.5364,969.1892,0,0,0,100,0),
(@PATH,11,8203.715,-304.7978,966.9639,0,0,0,100,0),
(@PATH,12,8195.111,-320.5364,969.1892,0,0,0,100,0),
(@PATH,13,8188.221,-330.7452,970.2561,0,0,0,100,0),
(@PATH,14,8180.829,-338.1227,969.8495,0,0,0,100,0),
(@PATH,15,8172.873,-345.124,967.3318,0,0,0,100,0),
(@PATH,16,8165.625,-349.4785,964.9684,0,0,0,100,0),
(@PATH,17,8159.849,-352.6774,963.8434,0,0,0,100,0),
(@PATH,18,8154.405,-356.4004,961.2184,0,0,0,100,0),
(@PATH,19,8149.224,-360.9964,959.7184,0,0,0,100,0),
(@PATH,20,8141.749,-366.09,960.2184,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114461;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8166.605,`position_y`=-333.7136,`position_z`=1002.62 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8166.605,-333.7136,1002.62,0,0,0,100,0),
(@PATH,2,8179.676,-327.8151,1004.554,0,0,0,100,0),
(@PATH,3,8190.838,-319.5394,1004.838,0,0,0,100,0),
(@PATH,4,8201.984,-310.4258,1003.127,0,0,0,100,0),
(@PATH,5,8190.838,-319.5394,1004.838,0,0,0,100,0),
(@PATH,6,8179.676,-327.8151,1004.554,0,0,0,100,0),
(@PATH,7,8166.605,-333.7136,1002.62,0,0,0,100,0),
(@PATH,8,8151.038,-342.4005,1003.778,0,0,0,100,0),
(@PATH,9,8136.858,-348.6777,1003.9702,0,0,0,100,0),
(@PATH,10,8151.038,-342.4005,1003.778,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114451;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8203.202,`position_y`=-201.5354,`position_z`=871.047 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8203.202,-201.5354,871.047,0,0,0,0,100,0),
(@PATH,2,8210.509,-193.4404,865.8152,0,0,0,0,100,0),
(@PATH,3,8203.202,-201.5354,871.047,0,0,0,0,100,0),
(@PATH,4,8197.84,-207.3055,874.847,0,0,0,0,100,0),
(@PATH,5,8189.615,-210.5096,877.097,0,0,0,0,100,0),
(@PATH,6,8178.526,-213.311,878.847,0,0,0,0,100,0),
(@PATH,7,8163.427,-218.207,883.10522,0,0,0,0,100,0),
(@PATH,8,8150.156,-226.349,882.16364,0,0,0,0,100,0),
(@PATH,9,8138.535,-234.773,880.50934,0,0,0,0,100,0),
(@PATH,10,8150.156,-226.349,882.16364,0,0,0,0,100,0),
(@PATH,11,8163.427,-218.207,883.10522,0,0,0,0,100,0),
(@PATH,12,8178.526,-213.311,878.847,0,0,0,0,100,0),
(@PATH,13,8189.615,-210.5096,877.097,0,0,0,0,100,0),
(@PATH,14,8197.84,-207.3055,874.847,0,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114455;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8040.252,`position_y`=-470.226,`position_z`=960.61102 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8040.252,-470.226,960.61102,0,0,0,100,0),
(@PATH,2,8047.966,-456.777,968.20410,0,0,0,100,0),
(@PATH,3,8055.527,-444.8557,974.9588,0,0,0,100,0),
(@PATH,4,8062.53,-433.15,980.1395,0,0,0,100,0),
(@PATH,5,8067.174,-421.3754,980.673,0,0,0,100,0),
(@PATH,6,8074.543,-413.8202,982.8965,0,0,0,100,0),
(@PATH,7,8083.434,-407.5285,984.6893,0,0,0,100,0),
(@PATH,8,8092.955,-402.0415,984.0195,0,0,0,100,0),
(@PATH,9,8103.769,-391.861,982.40454,0,0,0,100,0),
(@PATH,10,8092.955,-402.0415,984.0195,0,0,0,100,0),
(@PATH,11,8083.434,-407.5285,984.6893,0,0,0,100,0),
(@PATH,12,8074.543,-413.8202,982.8965,0,0,0,100,0),
(@PATH,13,8067.174,-421.3754,980.673,0,0,0,100,0),
(@PATH,14,8062.53,-433.15,980.1395,0,0,0,100,0),
(@PATH,15,8055.527,-444.8557,974.9588,0,0,0,100,0),
(@PATH,16,8047.966,-456.777,968.20410,0,0,0,100,0);

-- Pathing for Stormforged War Golem Entry: 29380
SET @NPC := 114449;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7951.311,`position_y`=-378.571,`position_z`=887.77075 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7951.311,-378.571,887.77075,0,0,0,100,0),
(@PATH,2,7960.646,-389.960,892.92139,0,0,0,100,0),
(@PATH,3,7968.372,-399.0812,898.0277,0,0,0,100,0),
(@PATH,4,7977.658,-409.0112,903.3966,0,0,0,100,0),
(@PATH,5,7981.982,-417.7852,908.3966,0,0,0,100,0),
(@PATH,6,7984.058,-427.559,913.42731,0,0,0,100,0),
(@PATH,7,7985.685,-434.808,917.18005,0,0,0,100,0),
(@PATH,8,7990.529,-444.403,924.04565,0,0,0,100,0),
(@PATH,9,7996.638,-456.090,931.35016,0,0,0,100,0),
(@PATH,10,8001.585,-467.127,938.43726,0,0,0,100,0),
(@PATH,11,8014.281,-473.688,946.06091,0,0,0,100,0),
(@PATH,12,8025.918,-483.258,952.99622,0,0,0,100,0),
(@PATH,13,8038.910,-488.314,958.12402,0,0,0,100,0),
(@PATH,14,8048.530,-496.921,961.03595,0,0,0,100,0),
(@PATH,15,8038.910,-488.314,958.12402,0,0,0,100,0),
(@PATH,16,8025.918,-483.258,952.99622,0,0,0,100,0),
(@PATH,17,8014.281,-473.688,946.06091,0,0,0,100,0),
(@PATH,18,8001.585,-467.127,938.43726,0,0,0,100,0),
(@PATH,19,7996.638,-456.090,931.35016,0,0,0,100,0),
(@PATH,20,7990.529,-444.403,924.04565,0,0,0,100,0),
(@PATH,21,7985.685,-434.808,917.18005,0,0,0,100,0),
(@PATH,22,7984.058,-427.559,913.42731,0,0,0,100,0),
(@PATH,23,7981.982,-417.7852,908.3966,0,0,0,100,0),
(@PATH,24,7977.658,-409.0112,903.3966,0,0,0,100,0),
(@PATH,25,7968.372,-399.0812,898.0277,0,0,0,100,0),
(@PATH,26,7960.646,-389.960,892.92139,0,0,0,100,0);
