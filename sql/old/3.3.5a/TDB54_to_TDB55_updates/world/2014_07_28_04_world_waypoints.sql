-- Fix speed for Fen Strider
UPDATE `creature_template` SET `speed_walk`=0.714285 WHERE `entry`=18134;

-- Pathing for Fen Strider Entry: 18134 "Missing Spawn"
SET @NPC := 45099;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@NPC,18134,530,1,1,-245.4115,7483.657,17.39584,6.021386,300,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-245.4115,7483.657,17.39584,0,0,0,0,100,0),
(@PATH,2,-247.2956,7450.507,17.5493,0,0,0,0,100,0),
(@PATH,3,-254.912,7428.493,17.75332,0,0,0,0,100,0),
(@PATH,4,-285.5298,7422.531,17.65393,0,0,0,0,100,0),
(@PATH,5,-305.5315,7416.8,17.66984,0,0,0,0,100,0),
(@PATH,6,-285.5298,7422.531,17.65393,0,0,0,0,100,0),
(@PATH,7,-254.912,7428.493,17.75332,0,0,0,0,100,0),
(@PATH,8,-247.2956,7450.507,17.5493,0,0,0,0,100,0),
(@PATH,9,-245.4115,7483.657,17.39584,0,0,0,0,100,0),
(@PATH,10,-247.987,7522.858,17.70378,0,0,0,0,100,0),
(@PATH,11,-247.1969,7559.842,17.57414,0,0,0,0,100,0),
(@PATH,12,-247.443,7578.94,17.37952,0,0,0,0,100,0),
(@PATH,13,-236.7838,7612.135,17.50561,0,0,0,0,100,0),
(@PATH,14,-216.761,7626.368,17.48851,0,0,0,0,100,0),
(@PATH,15,-236.7838,7612.135,17.50561,0,0,0,0,100,0),
(@PATH,16,-247.443,7578.94,17.37952,0,0,0,0,100,0),
(@PATH,17,-247.1969,7559.842,17.57414,0,0,0,0,100,0),
(@PATH,18,-247.987,7522.858,17.70378,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64767;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=223.5615,`position_y`=6374.221,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,223.5615,6374.221,17.49909,0,0,0,0,100,0),
(@PATH,2,256.5877,6388.807,17.4991,0,0,0,0,100,0),
(@PATH,3,251.3643,6428.167,17.49908,0,0,0,0,100,0),
(@PATH,4,256.2328,6456.2,17.50299,0,0,0,0,100,0),
(@PATH,5,251.3643,6428.167,17.49908,0,0,0,0,100,0),
(@PATH,6,256.5877,6388.807,17.4991,0,0,0,0,100,0),
(@PATH,7,223.5615,6374.221,17.49909,0,0,0,0,100,0),
(@PATH,8,182.964,6388.439,17.49308,0,0,0,0,100,0),
(@PATH,9,140.1335,6394.01,17.49909,0,0,0,0,100,0),
(@PATH,10,103.8388,6402.013,17.46575,0,0,0,0,100,0),
(@PATH,11,73.51573,6385.518,17.44332,0,0,0,0,100,0),
(@PATH,12,45.8967,6351.776,17.91318,0,0,0,0,100,0),
(@PATH,13,24.42795,6321.603,17.49905,0,0,0,0,100,0),
(@PATH,14,45.8967,6351.776,17.91318,0,0,0,0,100,0),
(@PATH,15,73.51573,6385.518,17.44332,0,0,0,0,100,0),
(@PATH,16,103.8388,6402.013,17.46575,0,0,0,0,100,0),
(@PATH,17,140.1335,6394.01,17.49909,0,0,0,0,100,0),
(@PATH,18,182.964,6388.439,17.49308,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64768;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-843.6936,`position_y`=5124.897,`position_z`=17.93274 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-843.6936,5124.897,17.93274,0,0,0,0,100,0),
(@PATH,2,-812.0039,5107.383,18.71229,0,0,0,0,100,0),
(@PATH,3,-843.6936,5124.897,17.93274,0,0,0,0,100,0),
(@PATH,4,-882.0682,5139.952,17.88305,0,0,0,0,100,0),
(@PATH,5,-902.012,5122.662,17.88305,0,0,0,0,100,0),
(@PATH,6,-916.0054,5086.631,17.8836,0,0,0,0,100,0),
(@PATH,7,-940.8605,5075.036,17.76662,0,0,0,0,100,0),
(@PATH,8,-979.3464,5083.667,18.55328,0,0,0,0,100,0),
(@PATH,9,-1017.911,5099.622,17.7586,0,0,0,0,100,0),
(@PATH,10,-1065.218,5100.495,17.5086,0,0,0,0,100,0),
(@PATH,11,-1017.911,5099.622,17.7586,0,0,0,0,100,0),
(@PATH,12,-979.3464,5083.667,18.55328,0,0,0,0,100,0),
(@PATH,13,-940.8605,5075.036,17.76662,0,0,0,0,100,0),
(@PATH,14,-916.0054,5086.631,17.8836,0,0,0,0,100,0),
(@PATH,15,-902.012,5122.662,17.88305,0,0,0,0,100,0),
(@PATH,16,-882.0682,5139.952,17.88305,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64769;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-740.3218,`position_y`=5196.946,`position_z`=17.88305 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-740.3218,5196.946,17.88305,0,0,0,0,100,0),
(@PATH,2,-711.1509,5226.004,17.73018,0,0,0,0,100,0),
(@PATH,3,-686.9243,5259.956,17.87972,0,0,0,0,100,0),
(@PATH,4,-656.3967,5287.788,17.88201,0,0,0,0,100,0),
(@PATH,5,-686.9243,5259.956,17.87972,0,0,0,0,100,0),
(@PATH,6,-711.1509,5226.004,17.73018,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64770;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-577.9679,`position_y`=5352.116,`position_z`=17.68461 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-577.9679,5352.116,17.68461,0,0,0,0,100,0),
(@PATH,2,-622.0549,5344.427,17.49935,0,0,0,0,100,0),
(@PATH,3,-577.9679,5352.116,17.68461,0,0,0,0,100,0),
(@PATH,4,-548.3535,5342.372,17.76349,0,0,0,0,100,0),
(@PATH,5,-449.3398,5342.336,17.79391,0,0,0,0,100,0),
(@PATH,6,-414.6554,5345.143,17.79263,0,0,0,0,100,0),
(@PATH,7,-477.406,5357.548,17.8798,0,0,0,0,100,0),
(@PATH,8,-509.2152,5366.26,18.13867,0,0,0,0,100,0),
(@PATH,9,-477.406,5357.548,17.8798,0,0,0,0,100,0),
(@PATH,10,-414.6554,5345.143,17.79263,0,0,0,0,100,0),
(@PATH,11,-449.3398,5342.336,17.79391,0,0,0,0,100,0),
(@PATH,12,-548.3535,5342.372,17.76349,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64771;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-403.375,`position_y`=5415.424,`position_z`=17.86433 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-403.375,5415.424,17.86433,0,0,0,0,100,0),
(@PATH,2,-384.9058,5415.971,17.7482,0,0,0,0,100,0),
(@PATH,3,-361.3589,5427.584,17.81659,0,0,0,0,100,0),
(@PATH,4,-330.2524,5423.488,17.93323,0,0,0,0,100,0),
(@PATH,5,-322.9159,5399.029,17.95394,0,0,0,0,100,0),
(@PATH,6,-331.5492,5380.434,17.98934,0,0,0,0,100,0),
(@PATH,7,-356.3358,5379.395,17.87109,0,0,0,0,100,0),
(@PATH,8,-378.2636,5382.861,17.86846,0,0,0,0,100,0),
(@PATH,9,-387.7549,5408.788,17.7482,0,0,0,0,100,0),
(@PATH,10,-415.6922,5415.858,17.86433,0,0,0,0,100,0),
(@PATH,11,-441.607,5418.342,17.76424,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64772;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1017.966,`position_y`=5538.429,`position_z`=17.10202 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1017.966,5538.429,17.10202,0,0,0,0,100,0),
(@PATH,2,-996.6628,5519.937,17.5215,0,0,0,0,100,0),
(@PATH,3,-992.8121,5500.504,17.52346,0,0,0,0,100,0),
(@PATH,4,-999.6793,5481.102,17.49909,0,0,0,0,100,0),
(@PATH,5,-1009.807,5457.827,17.48708,0,0,0,0,100,0),
(@PATH,6,-1013.846,5423.11,17.49909,0,0,0,0,100,0),
(@PATH,7,-1009.807,5457.827,17.48708,0,0,0,0,100,0),
(@PATH,8,-999.6793,5481.102,17.49909,0,0,0,0,100,0),
(@PATH,9,-992.8121,5500.504,17.52346,0,0,0,0,100,0),
(@PATH,10,-996.6628,5519.937,17.5215,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64773;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-987.5788,`position_y`=5744.341,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-987.5788,5744.341,17.49909,0,0,0,0,100,0),
(@PATH,2,-952.7982,5722.18,17.49813,0,0,0,0,100,0),
(@PATH,3,-984.4896,5717.205,17.49909,0,0,0,0,100,0),
(@PATH,4,-1025.188,5707.518,17.49699,0,0,0,0,100,0),
(@PATH,5,-984.4896,5717.205,17.49909,0,0,0,0,100,0),
(@PATH,6,-952.7982,5722.18,17.49813,0,0,0,0,100,0),
(@PATH,7,-987.5788,5744.341,17.49909,0,0,0,0,100,0),
(@PATH,8,-1007.783,5784.594,17.51414,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64774;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-457.9,`position_y`=5947.151,`position_z`=17.48606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-457.9,5947.151,17.48606,0,0,0,0,100,0),
(@PATH,2,-444.5015,5918.243,17.4935,0,0,0,0,100,0),
(@PATH,3,-443.175,5893.204,17.42938,0,0,0,0,100,0),
(@PATH,4,-422.4767,5919.401,17.5987,0,0,0,0,100,0),
(@PATH,5,-416.6625,5941.392,17.4036,0,0,0,0,100,0),
(@PATH,6,-400.2587,5966.586,17.4036,0,0,0,0,100,0),
(@PATH,7,-383.6613,5986.046,17.40285,0,0,0,0,100,0),
(@PATH,8,-354.2553,5978.438,17.49909,0,0,0,0,100,0),
(@PATH,9,-344.5939,5950.701,17.49909,0,0,0,0,100,0),
(@PATH,10,-308.6082,5944.29,17.49689,0,0,0,0,100,0),
(@PATH,11,-344.5939,5950.701,17.49909,0,0,0,0,100,0),
(@PATH,12,-354.2553,5978.438,17.49909,0,0,0,0,100,0),
(@PATH,13,-383.6613,5986.046,17.40285,0,0,0,0,100,0),
(@PATH,14,-400.2587,5966.586,17.4036,0,0,0,0,100,0),
(@PATH,15,-416.6625,5941.392,17.4036,0,0,0,0,100,0),
(@PATH,16,-422.4767,5919.401,17.5987,0,0,0,0,100,0),
(@PATH,17,-443.175,5893.204,17.42938,0,0,0,0,100,0),
(@PATH,18,-444.5015,5918.243,17.4935,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64775;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-384.029,`position_y`=5946.546,`position_z`=17.48655 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-384.029,5946.546,17.48655,0,0,0,0,100,0),
(@PATH,2,-350.0803,5951.836,17.49909,0,0,0,0,100,0),
(@PATH,3,-323.2102,5957.246,17.49909,0,0,0,0,100,0),
(@PATH,4,-294.5674,5946.367,17.50184,0,0,0,0,100,0),
(@PATH,5,-275.2058,5931.042,17.62954,0,0,0,0,100,0),
(@PATH,6,-251.2079,5941.814,17.49773,0,0,0,0,100,0),
(@PATH,7,-225.5439,5957.163,17.63308,0,0,0,0,100,0),
(@PATH,8,-240.6162,5982.624,17.52607,0,0,0,0,100,0),
(@PATH,9,-242.0302,6019.454,17.71815,0,0,0,0,100,0),
(@PATH,10,-214.7991,6041.711,18.32871,0,0,0,0,100,0),
(@PATH,11,-186.3317,6058.303,18.51708,0,0,0,0,100,0),
(@PATH,12,-164.5527,6085.354,18.3115,0,0,0,0,100,0),
(@PATH,13,-186.3317,6058.303,18.51708,0,0,0,0,100,0),
(@PATH,14,-214.7991,6041.711,18.32871,0,0,0,0,100,0),
(@PATH,15,-242.0302,6019.454,17.71815,0,0,0,0,100,0),
(@PATH,16,-240.6162,5982.624,17.52607,0,0,0,0,100,0),
(@PATH,17,-225.5439,5957.163,17.63308,0,0,0,0,100,0),
(@PATH,18,-251.2079,5941.814,17.49773,0,0,0,0,100,0),
(@PATH,19,-275.2058,5931.042,17.62954,0,0,0,0,100,0),
(@PATH,20,-294.5674,5946.367,17.50184,0,0,0,0,100,0),
(@PATH,21,-323.2102,5957.246,17.49909,0,0,0,0,100,0),
(@PATH,22,-350.0803,5951.836,17.49909,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64776;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-190.5273,`position_y`=6160.305,`position_z`=17.38075 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-190.5273,6160.305,17.38075,0,0,0,0,100,0),
(@PATH,2,-217.2867,6168.313,17.4991,0,0,0,0,100,0),
(@PATH,3,-253.0732,6165.761,17.57794,0,0,0,0,100,0),
(@PATH,4,-276.0217,6132.753,17.93902,0,0,0,0,100,0),
(@PATH,5,-301.7705,6095.704,17.49908,0,0,0,0,100,0),
(@PATH,6,-332.6654,6080.386,18.02447,0,0,0,0,100,0),
(@PATH,7,-367.4536,6078.913,17.49908,0,0,0,0,100,0),
(@PATH,8,-403.6659,6090.355,18.23721,0,0,0,0,100,0),
(@PATH,9,-367.4536,6078.913,17.49908,0,0,0,0,100,0),
(@PATH,10,-332.6654,6080.386,18.02447,0,0,0,0,100,0),
(@PATH,11,-301.7705,6095.704,17.49908,0,0,0,0,100,0),
(@PATH,12,-276.0217,6132.753,17.93902,0,0,0,0,100,0),
(@PATH,13,-253.0732,6165.761,17.57794,0,0,0,0,100,0),
(@PATH,14,-217.2867,6168.313,17.4991,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64777;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=51.84581,`position_y`=5928.761,`position_z`=17.4091 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,51.84581,5928.761,17.4091,0,0,0,0,100,0),
(@PATH,2,29.06456,5946.927,17.4991,0,0,0,0,100,0),
(@PATH,3,20.11274,5979.879,17.74711,0,0,0,0,100,0),
(@PATH,4,22.18533,6012.022,17.49818,0,0,0,0,100,0),
(@PATH,5,17.59191,6043.186,17.49818,0,0,0,0,100,0),
(@PATH,6,21.65831,6083.83,17.63726,0,0,0,0,100,0),
(@PATH,7,14.7615,6059.701,17.78932,0,0,0,0,100,0),
(@PATH,8,6.653971,6025.576,17.62318,0,0,0,0,100,0),
(@PATH,9,-32.80664,6032.478,17.49908,0,0,0,0,100,0),
(@PATH,10,-66.30209,6025.953,17.49908,0,0,0,0,100,0),
(@PATH,11,-81.81229,6005.886,17.5069,0,0,0,0,100,0),
(@PATH,12,-66.30209,6025.953,17.49908,0,0,0,0,100,0),
(@PATH,13,-32.80664,6032.478,17.49908,0,0,0,0,100,0),
(@PATH,14,6.653971,6025.576,17.62318,0,0,0,0,100,0),
(@PATH,15,14.7615,6059.701,17.78932,0,0,0,0,100,0),
(@PATH,16,21.65831,6083.83,17.63726,0,0,0,0,100,0),
(@PATH,17,17.59191,6043.186,17.49818,0,0,0,0,100,0),
(@PATH,18,22.18533,6012.022,17.49818,0,0,0,0,100,0),
(@PATH,19,20.11274,5979.879,17.74711,0,0,0,0,100,0),
(@PATH,20,29.06456,5946.927,17.4991,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64778;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=46.72515,`position_y`=5911.564,`position_z`=17.4091 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,46.72515,5911.564,17.4091,0,0,0,0,100,0),
(@PATH,2,77.36176,5883.848,17.4991,0,0,0,0,100,0),
(@PATH,3,89.86328,5851.272,17.4991,0,0,0,0,100,0),
(@PATH,4,77.36176,5883.848,17.4991,0,0,0,0,100,0),
(@PATH,5,46.72515,5911.564,17.4091,0,0,0,0,100,0),
(@PATH,6,16.72081,5907.729,17.48191,0,0,0,0,100,0),
(@PATH,7,-15.28299,5895.461,17.49908,0,0,0,0,100,0),
(@PATH,8,-45.57878,5883.192,17.49907,0,0,0,0,100,0),
(@PATH,9,-15.28299,5895.461,17.49908,0,0,0,0,100,0),
(@PATH,10,16.72081,5907.729,17.48191,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64779;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-48.9668,`position_y`=5785.517,`position_z`=17.49908 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-48.9668,5785.517,17.49908,0,0,0,0,100,0),
(@PATH,2,-31.21408,5790.6,17.80244,0,0,0,0,100,0),
(@PATH,3,6.899848,5785.177,17.49909,0,0,0,0,100,0),
(@PATH,4,12.50477,5748.672,17.75924,0,0,0,0,100,0),
(@PATH,5,8.448133,5700.218,17.46301,0,0,0,0,100,0),
(@PATH,6,-18.70009,5680.117,17.4991,0,0,0,0,100,0),
(@PATH,7,-48.19379,5666.413,17.4991,0,0,0,0,100,0),
(@PATH,8,-82.09049,5668.125,17.46832,0,0,0,0,100,0),
(@PATH,9,-102.2704,5658.955,16.82566,0,0,0,0,100,0),
(@PATH,10,-82.09049,5668.125,17.46832,0,0,0,0,100,0),
(@PATH,11,-48.19379,5666.413,17.4991,0,0,0,0,100,0),
(@PATH,12,-18.70009,5680.117,17.4991,0,0,0,0,100,0),
(@PATH,13,8.448133,5700.218,17.46301,0,0,0,0,100,0),
(@PATH,14,12.50477,5748.672,17.75924,0,0,0,0,100,0),
(@PATH,15,6.899848,5785.177,17.49909,0,0,0,0,100,0),
(@PATH,16,-31.21408,5790.6,17.80244,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-907.9193,`position_y`=5554.827,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-907.9193,5554.827,17.49909,0,0,0,0,100,0),
(@PATH,2,-906.6673,5589.928,17.49907,0,0,0,0,100,0),
(@PATH,3,-907.9579,5615.547,17.49908,0,0,0,0,100,0),
(@PATH,4,-893.4542,5636.297,17.4865,0,0,0,0,100,0),
(@PATH,5,-869.1836,5620.646,18.20904,0,0,0,0,100,0),
(@PATH,6,-845.2606,5594.781,17.49979,0,0,0,0,100,0),
(@PATH,7,-827.6858,5557.872,17.49905,0,0,0,0,100,0),
(@PATH,8,-845.2606,5594.781,17.49979,0,0,0,0,100,0),
(@PATH,9,-869.1836,5620.646,18.20904,0,0,0,0,100,0),
(@PATH,10,-893.4542,5636.297,17.4865,0,0,0,0,100,0),
(@PATH,11,-907.9579,5615.547,17.49908,0,0,0,0,100,0),
(@PATH,12,-906.6673,5589.928,17.49907,0,0,0,0,100,0),
(@PATH,13,-907.9193,5554.827,17.49909,0,0,0,0,100,0),
(@PATH,14,-889.6183,5537.365,17.49909,0,0,0,0,100,0),
(@PATH,15,-891.3976,5511.3,17.49909,0,0,0,0,100,0),
(@PATH,16,-907.3821,5509.792,17.48495,0,0,0,0,100,0),
(@PATH,17,-891.3976,5511.3,17.49909,0,0,0,0,100,0),
(@PATH,18,-889.6183,5537.365,17.49909,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64781;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-825.1914,`position_y`=5546.16,`position_z`=17.49905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-825.1914,5546.16,17.49905,0,0,0,0,100,0),
(@PATH,2,-826.8116,5506.765,17.49908,0,0,0,0,100,0),
(@PATH,3,-830.6971,5478.23,17.49908,0,0,0,0,100,0),
(@PATH,4,-807.579,5456.918,17.49909,0,0,0,0,100,0),
(@PATH,5,-772.4839,5443.94,17.62408,0,0,0,0,100,0),
(@PATH,6,-741.9182,5456.83,17.49908,0,0,0,0,100,0),
(@PATH,7,-711.4406,5466.509,17.49908,0,0,0,0,100,0),
(@PATH,8,-696.3304,5487.959,17.49909,0,0,0,0,100,0),
(@PATH,9,-691.9963,5512.772,17.47927,0,0,0,0,100,0),
(@PATH,10,-696.3304,5487.959,17.49909,0,0,0,0,100,0),
(@PATH,11,-711.4406,5466.509,17.49908,0,0,0,0,100,0),
(@PATH,12,-741.9182,5456.83,17.49908,0,0,0,0,100,0),
(@PATH,13,-772.4839,5443.94,17.62408,0,0,0,0,100,0),
(@PATH,14,-807.579,5456.918,17.49909,0,0,0,0,100,0),
(@PATH,15,-830.6971,5478.23,17.49908,0,0,0,0,100,0),
(@PATH,16,-826.8116,5506.765,17.49908,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64782;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-131.7958,`position_y`=5398.479,`position_z`=17.76864 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-131.7958,5398.479,17.76864,0,0,0,0,100,0),
(@PATH,2,-98.33811,5381.044,17.91549,0,0,0,0,100,0),
(@PATH,3,-65.86523,5378.005,18.42885,0,0,0,0,100,0),
(@PATH,4,-26.47841,5356.318,17.85734,0,0,0,0,100,0),
(@PATH,5,4.931749,5323.244,17.62409,0,0,0,0,100,0),
(@PATH,6,31.18707,5302.142,17.49909,0,0,0,0,100,0),
(@PATH,7,4.931749,5323.244,17.62409,0,0,0,0,100,0),
(@PATH,8,-26.47841,5356.318,17.85734,0,0,0,0,100,0),
(@PATH,9,-65.86523,5378.005,18.42885,0,0,0,0,100,0),
(@PATH,10,-98.33811,5381.044,17.91549,0,0,0,0,100,0),
(@PATH,11,-131.7958,5398.479,17.76864,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64783;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=0.041775,`position_y`=5430.892,`position_z`=17.49905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,0.041775,5430.892,17.49905,0,0,0,0,100,0),
(@PATH,2,-16.03722,5458.905,17.49905,0,0,0,0,100,0),
(@PATH,3,-19.83192,5492.91,17.55667,0,0,0,0,100,0),
(@PATH,4,-28.12771,5460.756,17.49905,0,0,0,0,100,0),
(@PATH,5,-61.99067,5453.709,17.49905,0,0,0,0,100,0),
(@PATH,6,-86.24381,5460.781,17.7697,0,0,0,0,100,0),
(@PATH,7,-61.99067,5453.709,17.49905,0,0,0,0,100,0),
(@PATH,8,-28.12771,5460.756,17.49905,0,0,0,0,100,0),
(@PATH,9,-19.83192,5492.91,17.55667,0,0,0,0,100,0),
(@PATH,10,-16.03722,5458.905,17.49905,0,0,0,0,100,0),
(@PATH,11,0.041775,5430.892,17.49905,0,0,0,0,100,0),
(@PATH,12,12.50011,5406.847,17.48977,0,0,0,0,100,0),
(@PATH,13,-23.77734,5374.397,17.72959,0,0,0,0,100,0),
(@PATH,14,12.50011,5406.847,17.48977,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64784;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=115.1097,`position_y`=5414.181,`position_z`=17.49907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,115.1097,5414.181,17.49907,0,0,0,0,100,0),
(@PATH,2,110.2024,5368.683,17.47716,0,0,0,0,100,0),
(@PATH,3,145.1066,5345.202,17.49734,0,0,0,0,100,0),
(@PATH,4,143.46,5322.411,17.95959,0,0,0,0,100,0),
(@PATH,5,146.4954,5283.085,17.65803,0,0,0,0,100,0),
(@PATH,6,143.46,5322.411,17.95959,0,0,0,0,100,0),
(@PATH,7,145.1066,5345.202,17.49734,0,0,0,0,100,0),
(@PATH,8,110.2024,5368.683,17.47716,0,0,0,0,100,0),
(@PATH,9,80.71908,5393.21,17.99909,0,0,0,0,100,0),
(@PATH,10,75.71604,5407.112,17.62408,0,0,0,0,100,0),
(@PATH,11,80.71908,5393.21,17.99909,0,0,0,0,100,0),
(@PATH,12,110.2024,5368.683,17.47716,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64785;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=264.2738,`position_y`=5531.262,`position_z`=17.92775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,264.2738,5531.262,17.92775,0,0,0,0,100,0),
(@PATH,2,232.8887,5527.525,17.5287,0,0,0,0,100,0),
(@PATH,3,199.9682,5558.708,17.60653,0,0,0,0,100,0),
(@PATH,4,166.1176,5583.089,17.4991,0,0,0,0,100,0),
(@PATH,5,148.7548,5566.394,17.49909,0,0,0,0,100,0),
(@PATH,6,146.8485,5519.998,17.49908,0,0,0,0,100,0),
(@PATH,7,148.7548,5566.394,17.49909,0,0,0,0,100,0),
(@PATH,8,166.1176,5583.089,17.4991,0,0,0,0,100,0),
(@PATH,9,199.9682,5558.708,17.60653,0,0,0,0,100,0),
(@PATH,10,232.8887,5527.525,17.5287,0,0,0,0,100,0),
(@PATH,11,264.2738,5531.262,17.92775,0,0,0,0,100,0),
(@PATH,12,299.4445,5544.412,17.37348,0,0,0,0,100,0),
(@PATH,13,330.2489,5563.043,17.41451,0,0,0,0,100,0),
(@PATH,14,299.4445,5544.412,17.37348,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64786;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=735.855,`position_y`=5712.859,`position_z`=17.57299 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,735.855,5712.859,17.57299,0,0,0,0,100,0),
(@PATH,2,711.5545,5729.475,17.49909,0,0,0,0,100,0),
(@PATH,3,668.0522,5732.768,17.49909,0,0,0,0,100,0),
(@PATH,4,632.2855,5728.686,17.49908,0,0,0,0,100,0),
(@PATH,5,616.373,5762.456,17.49908,0,0,0,0,100,0),
(@PATH,6,618.9044,5798.506,17.50095,0,0,0,0,100,0),
(@PATH,7,613.7986,5816.898,17.50571,0,0,0,0,100,0),
(@PATH,8,615.4912,5779.825,17.50095,0,0,0,0,100,0),
(@PATH,9,615.1094,5743.104,17.49908,0,0,0,0,100,0),
(@PATH,10,609.7659,5722.993,17.49908,0,0,0,0,100,0),
(@PATH,11,558.3204,5672.167,17.49909,0,0,0,0,100,0),
(@PATH,12,580.8484,5694.557,17.77685,0,0,0,0,100,0),
(@PATH,13,609.7659,5722.993,17.49908,0,0,0,0,100,0),
(@PATH,14,615.1094,5743.104,17.49908,0,0,0,0,100,0),
(@PATH,15,615.4912,5779.825,17.50095,0,0,0,0,100,0),
(@PATH,16,613.7986,5816.898,17.50571,0,0,0,0,100,0),
(@PATH,17,618.9044,5798.506,17.50095,0,0,0,0,100,0),
(@PATH,18,616.373,5762.456,17.49908,0,0,0,0,100,0),
(@PATH,19,632.2855,5728.686,17.49908,0,0,0,0,100,0),
(@PATH,20,668.0522,5732.768,17.49909,0,0,0,0,100,0),
(@PATH,21,711.5545,5729.475,17.49909,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64787;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=166.1176,`position_y`=5583.089,`position_z`=17.4991 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,166.1176,5583.089,17.4991,0,0,0,0,100,0),
(@PATH,2,148.7548,5566.394,17.49909,0,0,0,0,100,0),
(@PATH,3,146.8485,5519.998,17.49908,0,0,0,0,100,0),
(@PATH,4,148.7548,5566.394,17.49909,0,0,0,0,100,0),
(@PATH,5,166.1176,5583.089,17.4991,0,0,0,0,100,0),
(@PATH,6,199.9682,5558.708,17.60653,0,0,0,0,100,0),
(@PATH,7,232.8887,5527.525,17.5287,0,0,0,0,100,0),
(@PATH,8,264.2738,5531.262,17.92775,0,0,0,0,100,0),
(@PATH,9,299.4445,5544.412,17.37348,0,0,0,0,100,0),
(@PATH,10,330.2489,5563.043,17.41451,0,0,0,0,100,0),
(@PATH,11,299.4445,5544.412,17.37348,0,0,0,0,100,0),
(@PATH,12,264.2738,5531.262,17.92775,0,0,0,0,100,0),
(@PATH,13,232.8887,5527.525,17.5287,0,0,0,0,100,0),
(@PATH,14,199.9682,5558.708,17.60653,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64788;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=37.02224,`position_y`=5578.584,`position_z`=17.49907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,37.02224,5578.584,17.49907,0,0,0,0,100,0),
(@PATH,2,2.194553,5577.092,17.49908,0,0,0,0,100,0),
(@PATH,3,37.02224,5578.584,17.49907,0,0,0,0,100,0),
(@PATH,4,72.50792,5567.374,17.49907,0,0,0,0,100,0),
(@PATH,5,96.54264,5530.071,17.52178,0,0,0,0,100,0),
(@PATH,6,132.1394,5511.107,17.49908,0,0,0,0,100,0),
(@PATH,7,151.6769,5479.063,17.48717,0,0,0,0,100,0),
(@PATH,8,132.1394,5511.107,17.49908,0,0,0,0,100,0),
(@PATH,9,96.54264,5530.071,17.52178,0,0,0,0,100,0),
(@PATH,10,72.50792,5567.374,17.49907,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64789;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=90.24013,`position_y`=5621.603,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,90.24013,5621.603,17.49909,0,0,0,0,100,0),
(@PATH,2,138.8866,5615.225,17.46576,0,0,0,0,100,0),
(@PATH,3,182.4033,5597.265,17.49908,0,0,0,0,100,0),
(@PATH,4,202.7905,5615.53,17.55622,0,0,0,0,100,0),
(@PATH,5,215.2133,5641.461,17.49908,0,0,0,0,100,0),
(@PATH,6,244.4814,5650.017,17.49908,0,0,0,0,100,0),
(@PATH,7,282.8491,5652.73,17.49909,0,0,0,0,100,0),
(@PATH,8,324.8022,5649.672,17.49908,0,0,0,0,100,0),
(@PATH,9,335.1364,5631.01,17.49908,0,0,0,0,100,0),
(@PATH,10,332.5746,5589.228,17.49909,0,0,0,0,100,0),
(@PATH,11,335.1364,5631.01,17.49908,0,0,0,0,100,0),
(@PATH,12,324.8022,5649.672,17.49908,0,0,0,0,100,0),
(@PATH,13,282.8491,5652.73,17.49909,0,0,0,0,100,0),
(@PATH,14,244.4814,5650.017,17.49908,0,0,0,0,100,0),
(@PATH,15,215.2133,5641.461,17.49908,0,0,0,0,100,0),
(@PATH,16,202.7905,5615.53,17.55622,0,0,0,0,100,0),
(@PATH,17,182.4033,5597.265,17.49908,0,0,0,0,100,0),
(@PATH,18,138.8866,5615.225,17.46576,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64790;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=455.8582,`position_y`=5653.635,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,455.8582,5653.635,17.49909,0,0,0,0,100,0),
(@PATH,2,435.5963,5689.513,17.40821,0,0,0,0,100,0),
(@PATH,3,409.9687,5716.992,17.39267,0,0,0,0,100,0),
(@PATH,4,380.3604,5749.097,17.41897,0,0,0,0,100,0),
(@PATH,5,349.7367,5756.506,17.3762,0,0,0,0,100,0),
(@PATH,6,317.3354,5769.745,17.49909,0,0,0,0,100,0),
(@PATH,7,275.3563,5779.654,17.49909,0,0,0,0,100,0),
(@PATH,8,236.6264,5779.723,17.49908,0,0,0,0,100,0),
(@PATH,9,225.5676,5815.944,17.49908,0,0,0,0,100,0),
(@PATH,10,222.9546,5852.004,17.49909,0,0,0,0,100,0),
(@PATH,11,225.5676,5815.944,17.49908,0,0,0,0,100,0),
(@PATH,12,236.6264,5779.723,17.49908,0,0,0,0,100,0),
(@PATH,13,275.3563,5779.654,17.49909,0,0,0,0,100,0),
(@PATH,14,317.3354,5769.745,17.49909,0,0,0,0,100,0),
(@PATH,15,349.7367,5756.506,17.3762,0,0,0,0,100,0),
(@PATH,16,380.3604,5749.097,17.41897,0,0,0,0,100,0),
(@PATH,17,409.9687,5716.992,17.39267,0,0,0,0,100,0),
(@PATH,18,435.5963,5689.513,17.40821,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64791;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=352.3516,`position_y`=5677.601,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,352.3516,5677.601,17.49909,0,0,0,0,100,0),
(@PATH,2,373.3804,5720.132,17.53165,0,0,0,0,100,0),
(@PATH,3,414.3424,5717.605,17.44284,0,0,0,0,100,0),
(@PATH,4,445.9049,5718.17,17.39267,0,0,0,0,100,0),
(@PATH,5,487.558,5712.121,17.39835,0,0,0,0,100,0),
(@PATH,6,445.9049,5718.17,17.39267,0,0,0,0,100,0),
(@PATH,7,414.3424,5717.605,17.44284,0,0,0,0,100,0),
(@PATH,8,373.3804,5720.132,17.53165,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64792;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=737.8778,`position_y`=5839.425,`position_z`=17.60259 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,737.8778,5839.425,17.60259,0,0,0,0,100,0),
(@PATH,2,741.634,5876.525,17.18231,0,0,0,0,100,0),
(@PATH,3,732.2723,5906.607,17.55844,0,0,0,0,100,0),
(@PATH,4,707.1666,5940.431,17.53866,0,0,0,0,100,0),
(@PATH,5,683.2247,5947.035,17.75097,0,0,0,0,100,0),
(@PATH,6,649.7184,5950.69,17.49909,0,0,0,0,100,0),
(@PATH,7,683.2247,5947.035,17.75097,0,0,0,0,100,0),
(@PATH,8,707.1666,5940.431,17.53866,0,0,0,0,100,0),
(@PATH,9,732.2723,5906.607,17.55844,0,0,0,0,100,0),
(@PATH,10,741.634,5876.525,17.18231,0,0,0,0,100,0),
(@PATH,11,737.8778,5839.425,17.60259,0,0,0,0,100,0),
(@PATH,12,736.2857,5811.721,18.36215,0,0,0,0,100,0),
(@PATH,13,720.3111,5781.002,18.42918,0,0,0,0,100,0),
(@PATH,14,715.8815,5745.822,17.63034,0,0,0,0,100,0),
(@PATH,15,690.7528,5729.215,17.49909,0,0,0,0,100,0),
(@PATH,16,715.8815,5745.822,17.63034,0,0,0,0,100,0),
(@PATH,17,720.3111,5781.002,18.42918,0,0,0,0,100,0),
(@PATH,18,736.2857,5811.721,18.36215,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64793;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=578.2181,`position_y`=5920.502,`position_z`=17.49912 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,578.2181,5920.502,17.49912,0,0,0,0,100,0),
(@PATH,2,589.2954,5958.26,17.4991,0,0,0,0,100,0),
(@PATH,3,620.0464,5975.023,17.49909,0,0,0,0,100,0),
(@PATH,4,646.5626,6013.93,17.4991,0,0,0,0,100,0),
(@PATH,5,620.0464,5975.023,17.49909,0,0,0,0,100,0),
(@PATH,6,589.2954,5958.26,17.4991,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64794;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=336.6295,`position_y`=6207.977,`position_z`=17.40447 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,336.6295,6207.977,17.40447,0,0,0,0,100,0),
(@PATH,2,300.3756,6220.479,17.40025,0,0,0,0,100,0),
(@PATH,3,279.4986,6248.872,17.59603,0,0,0,0,100,0),
(@PATH,4,251.1006,6271.895,17.49814,0,0,0,0,100,0),
(@PATH,5,216.5504,6271.099,17.49909,0,0,0,0,100,0),
(@PATH,6,177.4853,6278.098,17.61749,0,0,0,0,100,0),
(@PATH,7,140.3005,6278.077,17.49908,0,0,0,0,100,0),
(@PATH,8,115.593,6294.441,17.62409,0,0,0,0,100,0),
(@PATH,9,90.39225,6284.697,17.58397,0,0,0,0,100,0),
(@PATH,10,115.593,6294.441,17.62409,0,0,0,0,100,0),
(@PATH,11,140.3005,6278.077,17.49908,0,0,0,0,100,0),
(@PATH,12,177.4853,6278.098,17.61749,0,0,0,0,100,0),
(@PATH,13,216.5504,6271.099,17.49909,0,0,0,0,100,0),
(@PATH,14,251.1006,6271.895,17.49814,0,0,0,0,100,0),
(@PATH,15,279.4986,6248.872,17.59603,0,0,0,0,100,0),
(@PATH,16,300.3756,6220.479,17.40025,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64795;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=319.1818,`position_y`=6152.123,`position_z`=17.49453 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,319.1818,6152.123,17.49453,0,0,0,0,100,0),
(@PATH,2,284.0559,6158.702,17.4991,0,0,0,0,100,0),
(@PATH,3,256.5737,6160.586,17.58199,0,0,0,0,100,0),
(@PATH,4,232.4042,6149.979,17.8349,0,0,0,0,100,0),
(@PATH,5,199.5684,6149.379,17.5218,0,0,0,0,100,0),
(@PATH,6,166.1183,6148.252,17.4991,0,0,0,0,100,0),
(@PATH,7,137.0536,6171.277,17.49908,0,0,0,0,100,0),
(@PATH,8,101.785,6158.617,17.72066,0,0,0,0,100,0),
(@PATH,9,79.87749,6178.27,17.49908,0,0,0,0,100,0),
(@PATH,10,83.44955,6212.276,17.50453,0,0,0,0,100,0),
(@PATH,11,79.87749,6178.27,17.49908,0,0,0,0,100,0),
(@PATH,12,101.785,6158.617,17.72066,0,0,0,0,100,0),
(@PATH,13,137.0536,6171.277,17.49908,0,0,0,0,100,0),
(@PATH,14,166.1183,6148.252,17.4991,0,0,0,0,100,0),
(@PATH,15,199.5684,6149.379,17.5218,0,0,0,0,100,0),
(@PATH,16,232.4042,6149.979,17.8349,0,0,0,0,100,0),
(@PATH,17,256.5737,6160.586,17.58199,0,0,0,0,100,0),
(@PATH,18,284.0559,6158.702,17.4991,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64796;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-32.07671,`position_y`=6208.437,`position_z`=17.49905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-32.07671,6208.437,17.49905,0,0,0,0,100,0),
(@PATH,2,-47.30773,6239.94,17.49905,0,0,0,0,100,0),
(@PATH,3,-92.32552,6253.953,17.49905,0,0,0,0,100,0),
(@PATH,4,-47.30773,6239.94,17.49905,0,0,0,0,100,0),
(@PATH,5,-32.07671,6208.437,17.49905,0,0,0,0,100,0),
(@PATH,6,7.392795,6180.204,17.49813,0,0,0,0,100,0),
(@PATH,7,-10.72135,6183.765,17.49905,0,0,0,0,100,0),
(@PATH,8,-46.33192,6188.717,17.84356,0,0,0,0,100,0),
(@PATH,9,-81.2232,6188.234,17.80721,0,0,0,0,100,0),
(@PATH,10,-46.33192,6188.717,17.84356,0,0,0,0,100,0),
(@PATH,11,-10.72135,6183.765,17.49905,0,0,0,0,100,0),
(@PATH,12,7.392795,6180.204,17.49813,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64797;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-118.2504,`position_y`=6237.651,`position_z`=17.49905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-118.2504,6237.651,17.49905,0,0,0,0,100,0),
(@PATH,2,-143.082,6223.518,17.49905,0,0,0,0,100,0),
(@PATH,3,-178.5324,6205.397,17.83854,0,0,0,0,100,0),
(@PATH,4,-192.5762,6181.449,17.4991,0,0,0,0,100,0),
(@PATH,5,-200.9498,6146.919,17.4991,0,0,0,0,100,0),
(@PATH,6,-211.2024,6124.59,17.79438,0,0,0,0,100,0),
(@PATH,7,-200.9498,6146.919,17.4991,0,0,0,0,100,0),
(@PATH,8,-192.5762,6181.449,17.4991,0,0,0,0,100,0),
(@PATH,9,-178.5324,6205.397,17.83854,0,0,0,0,100,0),
(@PATH,10,-143.082,6223.518,17.49905,0,0,0,0,100,0),
(@PATH,11,-118.2504,6237.651,17.49905,0,0,0,0,100,0),
(@PATH,12,-87.31641,6255.852,17.49905,0,0,0,0,100,0),
(@PATH,13,-88.65408,6288.479,17.50447,0,0,0,0,100,0),
(@PATH,14,-87.31641,6255.852,17.49905,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64798;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-467.0757,`position_y`=6111.034,`position_z`=17.89768 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-467.0757,6111.034,17.89768,0,0,0,0,100,0),
(@PATH,2,-449.6576,6111.891,17.64181,0,0,0,0,100,0),
(@PATH,3,-463.5695,6132.191,16.73776,0,0,0,0,100,0),
(@PATH,4,-466.8561,6165.977,17.51208,0,0,0,0,100,0),
(@PATH,5,-458.3137,6202.167,17.98819,0,0,0,0,100,0),
(@PATH,6,-447.2309,6217.37,17.48819,0,0,0,0,100,0),
(@PATH,7,-494.9173,6222.194,17.49908,0,0,0,0,100,0),
(@PATH,8,-447.2309,6217.37,17.48819,0,0,0,0,100,0),
(@PATH,9,-458.3137,6202.167,17.98819,0,0,0,0,100,0),
(@PATH,10,-466.8561,6165.977,17.51208,0,0,0,0,100,0),
(@PATH,11,-463.5695,6132.191,16.73776,0,0,0,0,100,0),
(@PATH,12,-449.6576,6111.891,17.64181,0,0,0,0,100,0),
(@PATH,13,-467.0757,6111.034,17.89768,0,0,0,0,100,0),
(@PATH,14,-504.0656,6103.058,17.57066,0,0,0,0,100,0),
(@PATH,15,-509.759,6077.143,17.54438,0,0,0,0,100,0),
(@PATH,16,-504.0656,6103.058,17.57066,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64799;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-582.1886,`position_y`=6080.161,`position_z`=17.77252 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-582.1886,6080.161,17.77252,0,0,0,0,100,0),
(@PATH,2,-579.3903,6044.984,17.49909,0,0,0,0,100,0),
(@PATH,3,-590.5842,6024.271,17.49909,0,0,0,0,100,0),
(@PATH,4,-626.2255,6025.92,18.17206,0,0,0,0,100,0),
(@PATH,5,-657.6616,6026.399,18.71043,0,0,0,0,100,0),
(@PATH,6,-684.582,6051.611,17.75496,0,0,0,0,100,0),
(@PATH,7,-706.742,6091.642,17.47389,0,0,0,0,100,0),
(@PATH,8,-706.4898,6107.64,17.53576,0,0,0,0,100,0),
(@PATH,9,-690.3274,6131.137,18.09341,0,0,0,0,100,0),
(@PATH,10,-650.1953,6128.293,17.31914,0,0,0,0,100,0),
(@PATH,11,-609.8489,6106.838,17.56293,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64800;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-523.5103,`position_y`=6283.41,`position_z`=17.46291 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-523.5103,6283.41,17.46291,0,0,0,0,100,0),
(@PATH,2,-525.4007,6319.861,17.4709,0,0,0,0,100,0),
(@PATH,3,-526.9883,6349.109,17.03569,0,0,0,0,100,0),
(@PATH,4,-529.2988,6395,16.74332,0,0,0,0,100,0),
(@PATH,5,-524.3882,6422.457,16.6176,0,0,0,0,100,0),
(@PATH,6,-508.7605,6455.354,17.40051,0,0,0,0,100,0),
(@PATH,7,-478.1498,6473.233,17.3984,0,0,0,0,100,0),
(@PATH,8,-508.7605,6455.354,17.40051,0,0,0,0,100,0),
(@PATH,9,-524.3882,6422.457,16.6176,0,0,0,0,100,0),
(@PATH,10,-529.2988,6395,16.74332,0,0,0,0,100,0),
(@PATH,11,-526.9883,6349.109,17.03569,0,0,0,0,100,0),
(@PATH,12,-525.4007,6319.861,17.4709,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64801;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-440.8055,`position_y`=6356.273,`position_z`=17.97383 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-440.8055,6356.273,17.97383,0,0,0,0,100,0),
(@PATH,2,-445.8972,6402.299,17.7183,0,0,0,0,100,0),
(@PATH,3,-443.1256,6439.643,18.01491,0,0,0,0,100,0),
(@PATH,4,-429.9254,6472.811,17.34434,0,0,0,0,100,0),
(@PATH,5,-404.1039,6448.9,17.32619,0,0,0,0,100,0),
(@PATH,6,-371.9603,6429.923,17.39659,0,0,0,0,100,0),
(@PATH,7,-340.8035,6459.065,16.77041,0,0,0,0,100,0),
(@PATH,8,-371.9603,6429.923,17.39659,0,0,0,0,100,0),
(@PATH,9,-404.1039,6448.9,17.32619,0,0,0,0,100,0),
(@PATH,10,-429.9254,6472.811,17.34434,0,0,0,0,100,0),
(@PATH,11,-443.1256,6439.643,18.01491,0,0,0,0,100,0),
(@PATH,12,-445.8972,6402.299,17.7183,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64802;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=156.8943,`position_y`=6555.767,`position_z`=17.81371 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,156.8943,6555.767,17.81371,0,0,0,0,100,0),
(@PATH,2,117.1081,6537.705,17.8617,0,0,0,0,100,0),
(@PATH,3,156.8943,6555.767,17.81371,0,0,0,0,100,0),
(@PATH,4,187.3945,6539.424,17.82612,0,0,0,0,100,0),
(@PATH,5,210.4182,6553.55,17.87408,0,0,0,0,100,0),
(@PATH,6,208.001,6595.793,17.71889,0,0,0,0,100,0),
(@PATH,7,209.3846,6549.31,17.87408,0,0,0,0,100,0),
(@PATH,8,182.1638,6512.291,17.87408,0,0,0,0,100,0),
(@PATH,9,207.6569,6529.196,17.79969,0,0,0,0,100,0),
(@PATH,10,228.9973,6516.417,17.79969,0,0,0,0,100,0),
(@PATH,11,259.3248,6504.434,17.89135,0,0,0,0,100,0),
(@PATH,12,228.9973,6516.417,17.79969,0,0,0,0,100,0),
(@PATH,13,207.6569,6529.196,17.79969,0,0,0,0,100,0),
(@PATH,14,182.1638,6512.291,17.87408,0,0,0,0,100,0),
(@PATH,15,209.3846,6549.31,17.87408,0,0,0,0,100,0),
(@PATH,16,208.001,6595.793,17.71889,0,0,0,0,100,0),
(@PATH,17,210.4182,6553.55,17.87408,0,0,0,0,100,0),
(@PATH,18,187.3945,6539.424,17.82612,0,0,0,0,100,0),
(@PATH,19,156.8943,6555.767,17.81371,0,0,0,0,100,0),
(@PATH,20,117.1081,6537.705,17.8617,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64803;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=288.2079,`position_y`=6287.81,`position_z`=17.47691 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,288.2079,6287.81,17.47691,0,0,0,0,100,0),
(@PATH,2,265.3102,6326.917,17.4991,0,0,0,0,100,0),
(@PATH,3,240.2501,6356.44,17.4991,0,0,0,0,100,0),
(@PATH,4,211.8344,6377.598,17.49909,0,0,0,0,100,0),
(@PATH,5,174.9317,6390.463,17.49308,0,0,0,0,100,0),
(@PATH,6,136.6278,6412.673,17.49909,0,0,0,0,100,0),
(@PATH,7,125.6221,6442.443,17.49907,0,0,0,0,100,0),
(@PATH,8,122.3177,6473.401,17.90341,0,0,0,0,100,0),
(@PATH,9,125.6221,6442.443,17.49907,0,0,0,0,100,0),
(@PATH,10,136.6278,6412.673,17.49909,0,0,0,0,100,0),
(@PATH,11,174.9317,6390.463,17.49308,0,0,0,0,100,0),
(@PATH,12,211.8344,6377.598,17.49909,0,0,0,0,100,0),
(@PATH,13,240.2501,6356.44,17.4991,0,0,0,0,100,0),
(@PATH,14,265.3102,6326.917,17.4991,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64804;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=159.9863,`position_y`=6623.709,`position_z`=18.07342 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,159.9863,6623.709,18.07342,0,0,0,0,100,0),
(@PATH,2,111.8225,6625.367,17.66128,0,0,0,0,100,0),
(@PATH,3,81.88726,6657.84,18.02862,0,0,0,0,100,0),
(@PATH,4,57.40994,6697.926,17.65664,0,0,0,0,100,0),
(@PATH,5,32.80285,6731.247,17.43388,0,0,0,0,100,0),
(@PATH,6,17.84668,6764.872,17.76712,0,0,0,0,100,0),
(@PATH,7,23.14041,6783.049,17.74185,0,0,0,0,100,0),
(@PATH,8,-17.14497,6796.488,17.49905,0,0,0,0,100,0),
(@PATH,9,-27.98785,6834.597,17.61574,0,0,0,0,100,0),
(@PATH,10,-17.14497,6796.488,17.49905,0,0,0,0,100,0),
(@PATH,11,23.14041,6783.049,17.74185,0,0,0,0,100,0),
(@PATH,12,17.84668,6764.872,17.76712,0,0,0,0,100,0),
(@PATH,13,32.80285,6731.247,17.43388,0,0,0,0,100,0),
(@PATH,14,57.40994,6697.926,17.65664,0,0,0,0,100,0),
(@PATH,15,81.88726,6657.84,18.02862,0,0,0,0,100,0),
(@PATH,16,111.707,6625.484,17.49905,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64805;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-164.5482,`position_y`=6934.413,`position_z`=18.18033 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-164.5482,6934.413,18.18033,0,0,0,0,100,0),
(@PATH,2,-183.632,6937.141,17.07717,0,0,0,0,100,0),
(@PATH,3,-220.5421,6920.763,17.85999,0,0,0,0,100,0),
(@PATH,4,-249.9142,6896.67,17.51774,0,0,0,0,100,0),
(@PATH,5,-273.4789,6939.156,17.17082,0,0,0,0,100,0),
(@PATH,6,-264.4938,6952.116,17.00809,0,0,0,0,100,0),
(@PATH,7,-254.6145,6980.825,17.49502,0,0,0,0,100,0),
(@PATH,8,-264.4938,6952.116,17.00809,0,0,0,0,100,0),
(@PATH,9,-273.4789,6939.156,17.17082,0,0,0,0,100,0),
(@PATH,10,-249.9142,6896.67,17.51774,0,0,0,0,100,0),
(@PATH,11,-220.5421,6920.763,17.85999,0,0,0,0,100,0),
(@PATH,12,-183.632,6937.141,17.07717,0,0,0,0,100,0),
(@PATH,13,-164.5482,6934.413,18.18033,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64806;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-110.7676,`position_y`=6852.486,`position_z`=17.62408 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-110.7676,6852.486,17.62408,0,0,0,0,100,0),
(@PATH,2,-103.8334,6871.367,17.72661,0,0,0,0,100,0),
(@PATH,3,-86.75879,6892.248,18.36382,0,0,0,0,100,0),
(@PATH,4,-55.5,6902.915,17.05776,0,0,0,0,100,0),
(@PATH,5,-11.81196,6910.387,18.13013,0,0,0,0,100,0),
(@PATH,6,-55.43544,6902.944,17.06338,0,0,0,0,100,0),
(@PATH,7,-86.75879,6892.248,18.36382,0,0,0,0,100,0),
(@PATH,8,-103.8334,6871.367,17.72661,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64807;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=131.712,`position_y`=7306.268,`position_z`=17.80821 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,131.712,7306.268,17.80821,0,0,0,0,100,0),
(@PATH,2,168.7971,7288.949,17.76567,0,0,0,0,100,0),
(@PATH,3,166.1125,7260.476,17.93367,0,0,0,0,100,0),
(@PATH,4,150.4501,7219.933,17.51093,0,0,0,0,100,0),
(@PATH,5,126.3356,7176.794,17.69943,0,0,0,0,100,0),
(@PATH,6,103.305,7142.358,17.74033,0,0,0,0,100,0),
(@PATH,7,80.52647,7112.708,17.75442,0,0,0,0,100,0),
(@PATH,8,103.305,7142.358,17.74033,0,0,0,0,100,0),
(@PATH,9,126.3356,7176.794,17.69943,0,0,0,0,100,0),
(@PATH,10,150.4501,7219.933,17.51093,0,0,0,0,100,0),
(@PATH,11,166.1125,7260.476,17.93367,0,0,0,0,100,0),
(@PATH,12,168.7971,7288.949,17.76567,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64808;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-69.97092,`position_y`=7225.815,`position_z`=17.65932 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-69.97092,7225.815,17.65932,0,0,0,0,100,0),
(@PATH,2,-51.22146,7254.379,17.96319,0,0,0,0,100,0),
(@PATH,3,-31.08843,7285.497,17.87614,0,0,0,0,100,0),
(@PATH,4,-0.755317,7303.553,17.76629,0,0,0,0,100,0),
(@PATH,5,24.6377,7284.342,17.64326,0,0,0,0,100,0),
(@PATH,6,20.54568,7251.821,17.75818,0,0,0,0,100,0),
(@PATH,7,12.20096,7214.417,17.49909,0,0,0,0,100,0),
(@PATH,8,-0.724392,7192.214,17.49909,0,0,0,0,100,0),
(@PATH,9,12.20096,7214.417,17.49909,0,0,0,0,100,0),
(@PATH,10,20.54568,7251.821,17.75818,0,0,0,0,100,0),
(@PATH,11,24.6377,7284.342,17.64326,0,0,0,0,100,0),
(@PATH,12,-0.755317,7303.553,17.76629,0,0,0,0,100,0),
(@PATH,13,-31.08843,7285.497,17.87614,0,0,0,0,100,0),
(@PATH,14,-51.22146,7254.379,17.96319,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64809;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-50.82888,`position_y`=7284.149,`position_z`=17.71222 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-50.82888,7284.149,17.71222,0,0,0,0,100,0),
(@PATH,2,-71.93815,7307.375,17.60395,0,0,0,0,100,0),
(@PATH,3,-79.30469,7347.694,18.22894,0,0,0,0,100,0),
(@PATH,4,-78.17383,7375.893,17.74908,0,0,0,0,100,0),
(@PATH,5,-101.6073,7395.806,17.49907,0,0,0,0,100,0),
(@PATH,6,-129.7888,7390.173,17.63237,0,0,0,0,100,0),
(@PATH,7,-152.8423,7399.184,17.46074,0,0,0,0,100,0),
(@PATH,8,-187.6275,7385.377,18.82357,0,0,0,0,100,0),
(@PATH,9,-152.8423,7399.184,17.46074,0,0,0,0,100,0),
(@PATH,10,-129.7888,7390.173,17.63237,0,0,0,0,100,0),
(@PATH,11,-101.6073,7395.806,17.49907,0,0,0,0,100,0),
(@PATH,12,-78.17383,7375.893,17.74908,0,0,0,0,100,0),
(@PATH,13,-79.38607,7347.979,18.26507,0,0,0,0,100,0),
(@PATH,14,-71.93815,7307.375,17.60395,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64810;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-70.2844,`position_y`=7559.799,`position_z`=17.62407 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-70.2844,7559.799,17.62407,0,0,0,0,100,0),
(@PATH,2,-105.9493,7532.406,17.49907,0,0,0,0,100,0),
(@PATH,3,-142.6079,7514.397,17.49906,0,0,0,0,100,0),
(@PATH,4,-176.8844,7491.043,17.52821,0,0,0,0,100,0),
(@PATH,5,-207.1196,7471.188,17.76062,0,0,0,0,100,0),
(@PATH,6,-235.5527,7450.708,17.67271,0,0,0,0,100,0),
(@PATH,7,-230.2877,7405.63,17.75596,0,0,0,0,100,0),
(@PATH,8,-235.5527,7450.708,17.67271,0,0,0,0,100,0),
(@PATH,9,-207.1196,7471.188,17.76062,0,0,0,0,100,0),
(@PATH,10,-176.8844,7491.043,17.52821,0,0,0,0,100,0),
(@PATH,11,-142.6079,7514.397,17.49906,0,0,0,0,100,0),
(@PATH,12,-105.9493,7532.406,17.49907,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64811;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-89.50771,`position_y`=7475.422,`position_z`=17.46522 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-89.50771,7475.422,17.46522,0,0,0,0,100,0),
(@PATH,2,-102.3241,7505.399,17.49907,0,0,0,0,100,0),
(@PATH,3,-92.54026,7535.951,17.49907,0,0,0,0,100,0),
(@PATH,4,-65.05643,7576.566,17.4934,0,0,0,0,100,0),
(@PATH,5,-83.05024,7596.74,17.61765,0,0,0,0,100,0),
(@PATH,6,-102.1886,7628.811,17.40077,0,0,0,0,100,0),
(@PATH,7,-144.708,7651.377,17.17211,0,0,0,0,100,0),
(@PATH,8,-176.6953,7662.959,17.9679,0,0,0,0,100,0),
(@PATH,9,-191.1144,7693.393,17.83742,0,0,0,0,100,0),
(@PATH,10,-222.6461,7705.538,17.70993,0,0,0,0,100,0),
(@PATH,11,-191.1144,7693.393,17.83742,0,0,0,0,100,0),
(@PATH,12,-176.6953,7662.959,17.9679,0,0,0,0,100,0),
(@PATH,13,-144.708,7651.377,17.17211,0,0,0,0,100,0),
(@PATH,14,-102.1886,7628.811,17.40077,0,0,0,0,100,0),
(@PATH,15,-83.05024,7596.74,17.61765,0,0,0,0,100,0),
(@PATH,16,-65.05643,7576.566,17.4934,0,0,0,0,100,0),
(@PATH,17,-92.54026,7535.951,17.49907,0,0,0,0,100,0),
(@PATH,18,-102.3241,7505.399,17.49907,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64812;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-51.63726,`position_y`=7580.237,`position_z`=17.4934 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-51.63726,7580.237,17.4934,0,0,0,0,100,0),
(@PATH,2,-83.06499,7593.451,17.99619,0,0,0,0,100,0),
(@PATH,3,-106.0209,7625.454,17.40077,0,0,0,0,100,0),
(@PATH,4,-127.7703,7661.864,17.16993,0,0,0,0,100,0),
(@PATH,5,-160.904,7655.143,17.60179,0,0,0,0,100,0),
(@PATH,6,-127.7703,7661.864,17.16993,0,0,0,0,100,0),
(@PATH,7,-106.0209,7625.454,17.40077,0,0,0,0,100,0),
(@PATH,8,-83.06499,7593.451,17.99619,0,0,0,0,100,0),
(@PATH,9,-51.63726,7580.237,17.4934,0,0,0,0,100,0),
(@PATH,10,-20.41309,7579.509,17.49661,0,0,0,0,100,0),
(@PATH,11,13.02083,7582.005,17.3819,0,0,0,0,100,0),
(@PATH,12,60.02941,7576.993,17.44869,0,0,0,0,100,0),
(@PATH,13,13.02083,7582.005,17.3819,0,0,0,0,100,0),
(@PATH,14,-20.41309,7579.509,17.49661,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64813;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-51.65668,`position_y`=7653.138,`position_z`=17.86285 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-51.65668,7653.138,17.86285,0,0,0,0,100,0),
(@PATH,2,-83.05686,7678.935,17.49904,0,0,0,0,100,0),
(@PATH,3,-89.03635,7712.265,17.49775,0,0,0,0,100,0),
(@PATH,4,-83.05686,7678.935,17.49904,0,0,0,0,100,0),
(@PATH,5,-51.65668,7653.138,17.86285,0,0,0,0,100,0),
(@PATH,6,-21.17806,7639.248,17.49908,0,0,0,0,100,0),
(@PATH,7,13.91471,7648.901,17.49908,0,0,0,0,100,0),
(@PATH,8,30.72461,7670.82,17.49908,0,0,0,0,100,0),
(@PATH,9,61.47429,7653.199,17.49908,0,0,0,0,100,0),
(@PATH,10,30.72461,7670.82,17.49908,0,0,0,0,100,0),
(@PATH,11,13.91471,7648.901,17.49908,0,0,0,0,100,0),
(@PATH,12,-21.17806,7639.248,17.49908,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64814;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=722.5497,`position_y`=6282.599,`position_z`=17.3627 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,722.5497,6282.599,17.3627,0,0,0,0,100,0),
(@PATH,2,753.8679,6301.88,17.4089,0,0,0,0,100,0),
(@PATH,3,796.7829,6309.162,17.56356,0,0,0,0,100,0),
(@PATH,4,753.8679,6301.88,17.4089,0,0,0,0,100,0),
(@PATH,5,722.5497,6282.599,17.3627,0,0,0,0,100,0),
(@PATH,6,703.7663,6252.408,17.49536,0,0,0,0,100,0),
(@PATH,7,689.2173,6222.884,17.46375,0,0,0,0,100,0),
(@PATH,8,682.1595,6188.333,17.47886,0,0,0,0,100,0),
(@PATH,9,671.9225,6158.111,17.60386,0,0,0,0,100,0),
(@PATH,10,652.0421,6132.491,17.55671,0,0,0,0,100,0),
(@PATH,11,671.9225,6158.111,17.60386,0,0,0,0,100,0),
(@PATH,12,682.1595,6188.333,17.47886,0,0,0,0,100,0),
(@PATH,13,689.2173,6222.884,17.46375,0,0,0,0,100,0),
(@PATH,14,703.7663,6252.408,17.49536,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64815;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=312.5683,`position_y`=6641.804,`position_z`=17.5959 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,312.5683,6641.804,17.5959,0,0,0,0,100,0),
(@PATH,2,285.068,6633.693,17.60875,0,0,0,0,100,0),
(@PATH,3,308.4703,6622.076,18.09456,0,0,0,0,100,0),
(@PATH,4,328.7995,6581.982,17.7435,0,0,0,0,100,0),
(@PATH,5,345.2822,6546.819,17.77597,0,0,0,0,100,0),
(@PATH,6,330.5563,6525.298,17.79731,0,0,0,0,100,0),
(@PATH,7,345.2822,6546.819,17.77597,0,0,0,0,100,0),
(@PATH,8,328.7995,6581.982,17.7435,0,0,0,0,100,0),
(@PATH,9,308.4703,6622.076,18.09456,0,0,0,0,100,0),
(@PATH,10,285.068,6633.693,17.60875,0,0,0,0,100,0),
(@PATH,11,312.5683,6641.804,17.5959,0,0,0,0,100,0),
(@PATH,12,337.7431,6654.514,17.49312,0,0,0,0,100,0),
(@PATH,13,341.8825,6677.266,17.46976,0,0,0,0,100,0),
(@PATH,14,329.1877,6699.689,18.18023,0,0,0,0,100,0),
(@PATH,15,341.8825,6677.266,17.46976,0,0,0,0,100,0),
(@PATH,16,337.7431,6654.514,17.49312,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64816;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=155.9221,`position_y`=6855.781,`position_z`=17.84563 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,155.9221,6855.781,17.84563,0,0,0,0,100,0),
(@PATH,2,117.3765,6856.435,18.00443,0,0,0,0,100,0),
(@PATH,3,92.60135,6873.068,17.51661,0,0,0,0,100,0),
(@PATH,4,93.71539,6909.779,17.80663,0,0,0,0,100,0),
(@PATH,5,111.3916,6943.985,17.7326,0,0,0,0,100,0),
(@PATH,6,124.318,6978.092,17.78216,0,0,0,0,100,0),
(@PATH,7,114.5778,7005.351,17.8101,0,0,0,0,100,0),
(@PATH,8,124.318,6978.092,17.78216,0,0,0,0,100,0),
(@PATH,9,111.3916,6943.985,17.7326,0,0,0,0,100,0),
(@PATH,10,93.71539,6909.779,17.80663,0,0,0,0,100,0),
(@PATH,11,92.60135,6873.068,17.51661,0,0,0,0,100,0),
(@PATH,12,117.3765,6856.435,18.00443,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=183.1641,`position_y`=7564.119,`position_z`=17.49908 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,183.1641,7564.119,17.49908,0,0,0,0,100,0),
(@PATH,2,216.8052,7572.568,18.05743,0,0,0,0,100,0),
(@PATH,3,258.3971,7558.753,17.49908,0,0,0,0,100,0),
(@PATH,4,290.4745,7531.033,17.49907,0,0,0,0,100,0),
(@PATH,5,293.8652,7496.662,17.46751,0,0,0,0,100,0),
(@PATH,6,290.4745,7531.033,17.49907,0,0,0,0,100,0),
(@PATH,7,258.3971,7558.753,17.49908,0,0,0,0,100,0),
(@PATH,8,216.8052,7572.568,18.05743,0,0,0,0,100,0),
(@PATH,9,183.1641,7564.119,17.49908,0,0,0,0,100,0),
(@PATH,10,172.0435,7526.779,17.80572,0,0,0,0,100,0),
(@PATH,11,133.5556,7498.767,17.49907,0,0,0,0,100,0),
(@PATH,12,126.3401,7461.87,17.49908,0,0,0,0,100,0),
(@PATH,13,130.8735,7420.252,17.95489,0,0,0,0,100,0),
(@PATH,14,161.1225,7403.103,17.76771,0,0,0,0,100,0),
(@PATH,15,130.8735,7420.252,17.95489,0,0,0,0,100,0),
(@PATH,16,126.3401,7461.87,17.49908,0,0,0,0,100,0),
(@PATH,17,133.5556,7498.767,17.49907,0,0,0,0,100,0),
(@PATH,18,172.0435,7526.779,17.80572,0,0,0,0,100,0);

-- Pathing for Fen Strider Entry: 18134
SET @NPC := 64818;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=154.9363,`position_y`=7579.639,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,154.9363,7579.639,17.49909,0,0,0,0,100,0),
(@PATH,2,173.8466,7585.545,17.49908,0,0,0,0,100,0),
(@PATH,3,181.9009,7614.029,17.48481,0,0,0,0,100,0),
(@PATH,4,217.3355,7622.445,17.62408,0,0,0,0,100,0),
(@PATH,5,243.8657,7637,17.74902,0,0,0,0,100,0),
(@PATH,6,255.2209,7680.37,17.50446,0,0,0,0,100,0),
(@PATH,7,243.8657,7637,17.74902,0,0,0,0,100,0),
(@PATH,8,217.3355,7622.445,17.62408,0,0,0,0,100,0),
(@PATH,9,181.9009,7614.029,17.48481,0,0,0,0,100,0),
(@PATH,10,173.8466,7585.545,17.49908,0,0,0,0,100,0);
