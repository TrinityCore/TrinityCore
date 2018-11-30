-- Booty Bay Bruiser 1
SET @NPC := 178;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14442.4,`position_y`=414.102,`position_z`=25.0155, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14442.4, 414.102, 25.0155, 0),
(@PATH, 2, -14445.7, 412.951, 25.0162, 0),
(@PATH, 3, -14455, 423.15, 25.0954, 0),
(@PATH, 4, -14461.4, 430.758, 25.2104, 0),
(@PATH, 5, -14468.4, 441.477, 30.2791, 0),
(@PATH, 6, -14471.2, 446.957, 30.544, 0),
(@PATH, 7, -14472.9, 454.424, 30.4841, 0),
(@PATH, 8, -14472.3, 461.029, 30.6343, 0),
(@PATH, 9, -14479.2, 463.782, 30.7789, 0),
(@PATH, 10, -14482.8, 467.095, 31.5195, 0),
(@PATH, 11, -14479.2, 472.917, 31.5351, 0),
(@PATH, 12, -14482.5, 467.054, 31.6192, 0),
(@PATH, 13, -14479, 463.804, 30.8692, 0),
(@PATH, 14, -14472, 461.054, 30.8692, 0),
(@PATH, 15, -14472.5, 454.304, 30.6192, 0),
(@PATH, 16, -14471, 447.304, 30.6192, 0),
(@PATH, 17, -14468.3, 441.804, 30.3692, 0),
(@PATH, 18, -14461.3, 431.054, 25.6192, 0),
(@PATH, 19, -14454.8, 423.304, 25.6192, 0),
(@PATH, 20, -14445.8, 413.304, 25.3692, 0),
(@PATH, 21, -14442.3, 414.304, 25.3692, 0),
(@PATH, 22, -14424.3, 424.192, 21.7033, 0);

-- Booty Bay Bruiser 2
SET @NPC := 715;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14443.3,`position_y`=410.566,`position_z`=25.0075, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14443.3, 410.566, 25.0075, 0),
(@PATH, 2, -14457.4, 426.895, 25.1528, 0),
(@PATH, 3, -14466.7, 441.322, 29.8059, 0),
(@PATH, 4, -14455.6, 425.828, 25.131, 0),
(@PATH, 5, -14443.5, 432.869, 20.2956, 0),
(@PATH, 6, -14455.6, 425.828, 25.131, 0),
(@PATH, 7, -14466.7, 441.322, 29.8059, 0),
(@PATH, 8, -14457.4, 426.895, 25.1528, 0),
(@PATH, 9, -14443.3, 410.566, 25.0075, 0),
(@PATH, 10, -14437.1, 398.968, 31.7248, 0);

-- Booty Bay Bruiser 3
SET @NPC := 695;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14465.5,`position_y`=479.746,`position_z`=26.8295, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14465.5, 479.746, 26.8295, 0),
(@PATH, 2, -14466.8, 471.284, 30.7113, 0),
(@PATH, 3, -14469.5, 462.674, 30.6577, 0),
(@PATH, 4, -14472.3, 454.081, 30.4917, 0),
(@PATH, 5, -14470.2, 446.919, 30.5566, 0),
(@PATH, 6, -14474.8, 441.263, 30.705, 0),
(@PATH, 7, -14474.5, 434.851, 33.2027, 0),
(@PATH, 8, -14473.8, 431.647, 34.314, 0),
(@PATH, 9, -14478.6, 428.314, 34.249, 0),
(@PATH, 10, -14473.8, 431.647, 34.314, 0),
(@PATH, 11, -14474.5, 434.851, 33.2027, 0),
(@PATH, 12, -14474.8, 441.263, 30.705, 0),
(@PATH, 13, -14470.2, 446.919, 30.5566, 0),
(@PATH, 14, -14472.3, 454.081, 30.4917, 0),
(@PATH, 15, -14469.5, 462.674, 30.6577, 0),
(@PATH, 16, -14467, 470.439, 30.7043, 0),
(@PATH, 17, -14465.5, 479.746, 26.8295, 0),
(@PATH, 18, -14474, 487.33, 26.7089, 0);

-- Booty Bay Bruiser 4
SET @NPC := 657;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14312.8,`position_y`=483.192,`position_z`=14.819, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14312.8, 483.192, 14.819, 0),
(@PATH, 2, -14317.7, 466.225, 19.1429, 0),
(@PATH, 3, -14323.2, 444.298, 22.747, 0),
(@PATH, 4, -14316.2, 432.447, 22.7259, 0),
(@PATH, 5, -14319, 417.219, 23.4741, 0),
(@PATH, 6, -14322.2, 399.648, 24.0779, 0),
(@PATH, 7, -14334.9, 395.419, 23.3598, 0),
(@PATH, 8, -14343.8, 390.811, 23.2622, 0),
(@PATH, 9, -14363.4, 383.449, 23.4848, 0),
(@PATH, 10, -14375.8, 383.213, 22.6782, 0),
(@PATH, 11, -14390.6, 399.044, 22.8109, 0),
(@PATH, 12, -14375.8, 383.213, 22.6782, 0),
(@PATH, 13, -14363.4, 383.449, 23.4848, 0),
(@PATH, 14, -14343.8, 390.811, 23.2622, 0),
(@PATH, 15, -14334.9, 395.419, 23.3598, 0),
(@PATH, 16, -14322.2, 399.648, 24.0779, 0),
(@PATH, 17, -14319, 417.219, 23.4741, 0),
(@PATH, 18, -14316.2, 432.447, 22.7259, 0),
(@PATH, 19, -14323.2, 444.298, 22.747, 0),
(@PATH, 20, -14317.7, 466.225, 19.1429, 0),
(@PATH, 21, -14312.8, 483.192, 14.819, 0),
(@PATH, 22, -14299.8, 503.744, 9.08229, 0);

-- Booty Bay Bruiser 5
SET @NPC := 654;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14425.3,`position_y`=424.265,`position_z`=8.99519, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14425.3, 424.265, 8.99519, 0),
(@PATH, 2, -14423.7, 428.519, 8.96744, 0),
(@PATH, 3, -14428.8, 437.855, 6.48981, 0),
(@PATH, 4, -14436.4, 449.562, 3.69352, 0),
(@PATH, 5, -14445.5, 463.716, 3.84649, 0),
(@PATH, 6, -14436.9, 448.047, 3.69427, 0),
(@PATH, 7, -14448.3, 439.089, 3.86408, 0),
(@PATH, 8, -14436.9, 448.047, 3.69427, 0),
(@PATH, 9, -14445.5, 463.716, 3.84649, 0),
(@PATH, 10, -14436.4, 449.562, 3.69352, 0),
(@PATH, 11, -14428.8, 437.855, 6.48981, 0),
(@PATH, 12, -14423.7, 428.519, 8.96744, 0),
(@PATH, 13, -14425.3, 424.265, 8.99519, 0),
(@PATH, 14, -14434.6, 416.965, 8.75356, 0);

-- Booty Bay Bruiser 6
SET @NPC := 651;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14466.6,`position_y`=453.068,`position_z`=15.3329, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14466.6, 453.068, 15.3329, 0),
(@PATH, 2, -14467, 449.978, 15.4687, 0),
(@PATH, 3, -14463.1, 446.736, 15.4737, 0),
(@PATH, 4, -14454.3, 434.906, 15.1878, 0),
(@PATH, 5, -14442.7, 415.397, 15.0957, 0),
(@PATH, 6, -14453.6, 434.036, 15.1696, 0),
(@PATH, 7, -14437.8, 449.306, 15.3789, 0),
(@PATH, 8, -14449.8, 463.889, 15.3359, 0);

-- Booty Bay Bruiser 7
SET @NPC := 599;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14318.6,`position_y`=455.081,`position_z`=23.4482, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14318.6, 455.081, 23.4482, 0),
(@PATH, 2, -14314.7, 468.257, 18.4367, 0),
(@PATH, 3, -14314.7, 474.267, 18.3547, 0),
(@PATH, 4, -14307.9, 487.469, 13.2721, 0),
(@PATH, 5, -14301.7, 497.471, 10.601, 0),
(@PATH, 6, -14298.1, 505.389, 8.96902, 0),
(@PATH, 7, -14301.7, 509.774, 8.6758, 0),
(@PATH, 8, -14307.6, 504.115, 8.64554, 0),
(@PATH, 9, -14309.8, 498.715, 8.6345, 0),
(@PATH, 10, -14313.3, 490.275, 8.6164, 0),
(@PATH, 11, -14317.3, 482.241, 8.59652, 0),
(@PATH, 12, -14323, 471.202, 8.39456, 0),
(@PATH, 13, -14330, 457.738, 7.90804, 0),
(@PATH, 14, -14341.2, 443.758, 7.48909, 0),
(@PATH, 15, -14353.5, 435.965, 7.38517, 0),
(@PATH, 16, -14369, 429.004, 7.37672, 0),
(@PATH, 17, -14382.4, 424.817, 7.3554, 0),
(@PATH, 18, -14394.1, 421.125, 7.63872, 0),
(@PATH, 19, -14405.2, 422.36, 8.48729, 0),
(@PATH, 20, -14412.8, 428.759, 8.93994, 0),
(@PATH, 21, -14420.9, 435.219, 9.53649, 0),
(@PATH, 22, -14425.8, 441.807, 12.1688, 0),
(@PATH, 23, -14429.8, 447.25, 15.4427, 0),
(@PATH, 24, -14431.9, 447.814, 15.4255, 0),
(@PATH, 25, -14432.5, 445.842, 15.4692, 0),
(@PATH, 26, -14426.6, 438.212, 18.0541, 0),
(@PATH, 27, -14422.9, 432.659, 21.3357, 0),
(@PATH, 28, -14419.3, 428.27, 22.0601, 0),
(@PATH, 29, -14415.8, 424.096, 22.1281, 0),
(@PATH, 30, -14394.2, 414.212, 22.6782, 0),
(@PATH, 31, -14392.2, 409.483, 22.7452, 0),
(@PATH, 32, -14392.5, 402.863, 22.712, 0),
(@PATH, 33, -14387.6, 390.908, 22.9852, 0),
(@PATH, 34, -14382, 384.972, 23.2067, 0),
(@PATH, 35, -14375, 380.035, 23.1574, 0),
(@PATH, 36, -14365.2, 378.422, 23.3867, 0),
(@PATH, 37, -14355.3, 380.67, 23.3598, 0),
(@PATH, 38, -14342.3, 385.995, 23.4673, 0),
(@PATH, 39, -14326.5, 392.474, 23.8077, 0),
(@PATH, 40, -14320, 399.283, 24.0117, 0),
(@PATH, 41, -14315, 416.881, 23.6653, 0),
(@PATH, 42, -14313.4, 427.522, 23.1797, 0),
(@PATH, 43, -14314.8, 435.38, 22.9005, 0),
(@PATH, 44, -14316.6, 447.09, 23.2387, 0);

-- Booty Bay Bruiser 8
SET @NPC := 598;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14392.1,`position_y`=420.434,`position_z`=7.54837, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14392.1, 420.434, 7.54837, 0),
(@PATH, 2, -14385.4, 425.173, 7.36117, 0),
(@PATH, 3, -14373.1, 430.034, 7.31295, 0),
(@PATH, 4, -14360.3, 433.72, 7.36588, 0),
(@PATH, 5, -14344.8, 443.056, 7.4693, 0),
(@PATH, 6, -14337.3, 451.978, 7.67435, 0),
(@PATH, 7, -14327.3, 466.137, 8.1809, 0),
(@PATH, 8, -14317.2, 485.579, 8.59669, 0),
(@PATH, 9, -14308.3, 506.756, 8.64147, 0),
(@PATH, 10, -14294.1, 534.231, 8.6887, 0),
(@PATH, 11, -14286.1, 552.673, 8.70584, 0),
(@PATH, 12, -14294.1, 534.231, 8.6887, 0),
(@PATH, 13, -14308.3, 506.756, 8.64147, 0),
(@PATH, 14, -14317.2, 485.579, 8.59669, 0),
(@PATH, 15, -14327.3, 466.137, 8.1809, 0),
(@PATH, 16, -14337.3, 451.978, 7.67435, 0),
(@PATH, 17, -14344.8, 443.056, 7.4693, 0),
(@PATH, 18, -14360.3, 433.72, 7.36588, 0),
(@PATH, 19, -14373.1, 430.034, 7.31295, 0),
(@PATH, 20, -14385.4, 425.173, 7.36117, 0),
(@PATH, 21, -14392.1, 420.434, 7.54837, 0),
(@PATH, 22, -14400, 412.727, 7.77239, 0);

-- Booty Bay Bruiser 9
SET @NPC := 594;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14287,`position_y`=428.87,`position_z`=33.7043, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14287, 428.87, 33.7043, 0),
(@PATH, 2, -14280.9, 424.514, 35.3712, 0),
(@PATH, 3, -14277.2, 419.943, 36.423, 0),
(@PATH, 4, -14275.8, 411.91, 37.235, 0),
(@PATH, 5, -14276.6, 402.768, 37.0483, 0),
(@PATH, 6, -14279, 390.305, 36.3309, 0),
(@PATH, 7, -14281.4, 379.503, 35.133, 0),
(@PATH, 8, -14279.8, 368.264, 33.6549, 0),
(@PATH, 9, -14277.5, 359.923, 33.2561, 0),
(@PATH, 10, -14273.1, 350.615, 32.7842, 0),
(@PATH, 11, -14268.5, 346.023, 31.3686, 0),
(@PATH, 12, -14273.1, 350.615, 32.7842, 0),
(@PATH, 13, -14277.5, 359.923, 33.2561, 0),
(@PATH, 14, -14279.8, 368.264, 33.6549, 0),
(@PATH, 15, -14281.4, 379.503, 35.133, 0),
(@PATH, 16, -14279, 390.305, 36.3309, 0),
(@PATH, 17, -14276.6, 402.703, 37.0651, 0),
(@PATH, 18, -14275.8, 411.91, 37.235, 0),
(@PATH, 19, -14277.2, 419.943, 36.423, 0),
(@PATH, 20, -14280.9, 424.514, 35.3712, 0),
(@PATH, 21, -14287, 428.87, 33.7043, 0),
(@PATH, 22, -14298, 435.509, 31.579, 0);

-- Booty Bay Bruiser 10
SET @NPC := 591;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-14444.9,`position_y`=445.531,`position_z`=20.4134, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -14444.9, 445.531, 20.4134, 0),
(@PATH, 2, -14441.3, 438.778, 20.4903, 0),
(@PATH, 3, -14440.8, 432.276, 20.3793, 0),
(@PATH, 4, -14435.4, 430.078, 20.2879, 0),
(@PATH, 5, -14433.8, 427.503, 20.2863, 0),
(@PATH, 6, -14440.7, 422.971, 15.5599, 0),
(@PATH, 7, -14442.9, 426.732, 15.5587, 0),
(@PATH, 8, -14438.8, 432.066, 15.5848, 0),
(@PATH, 9, -14434.1, 432.398, 15.5545, 0),
(@PATH, 10, -14431.3, 428.801, 15.5621, 0),
(@PATH, 11, -14439.6, 423.793, 9.06026, 0),
(@PATH, 12, -14441.4, 425.5, 9.06026, 0),
(@PATH, 13, -14443.9, 430.25, 4.18761, 0),
(@PATH, 14, -14438.3, 434.884, 4.19606, 0),
(@PATH, 15, -14439.3, 437.73, 4.19911, 0),
(@PATH, 16, -14444.7, 430.757, 4.18845, 0),
(@PATH, 17, -14441.4, 425.5, 9.06026, 0),
(@PATH, 18, -14431.3, 428.801, 15.5621, 0),
(@PATH, 19, -14434.1, 432.398, 15.5545, 0),
(@PATH, 20, -14438.8, 432.066, 15.5848, 0),
(@PATH, 21, -14442.9, 426.732, 15.5587, 0),
(@PATH, 22, -14440.7, 422.971, 15.5599, 0),
(@PATH, 23, -14433.8, 427.503, 20.2863, 0),
(@PATH, 24, -14435.4, 430.078, 20.2879, 0),
(@PATH, 25, -14440.6, 432.196, 20.3668, 0),
(@PATH, 26, -14441.3, 438.778, 20.4903, 0),
(@PATH, 27, -14444.9, 445.531, 20.4134, 0),
(@PATH, 28, -14449.4, 451.391, 20.4759, 0);

-- Ironforge Mountaineer
SET @NPC := 225;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `position_x`=-5711.44,`position_y`=-553.78,`position_z`=398.49, `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -5711.44, -553.78, 398.49, 0),
(@PATH, 2, -5701.5, -556.94, 399.42, 0),
(@PATH, 3, -5690.68, -562.23, 399.75, 0),
(@PATH, 4, -5686.02, -576.38, 401.57, 0),
(@PATH, 5, -5703.14, -576.05, 401.19, 0),
(@PATH, 6, -5712.95, -566.86, 399.93, 0),
(@PATH, 7, -5719.97, -550.44, 398.7, 0);
