-- Pathing for Eye of Thrallmar
SET @NPC :=57585;
SET @PATH :=@NPC*10;
UPDATE `creature` SET `position_x`=203.191,`position_y`=2850.286,`position_z`=160.4257,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,197.9876,2842.495,160.4257,0,0,0,100,0),
(@PATH,2,212.5493,2807.971,174.2035,0,0,0,100,0),
(@PATH,3,244.0748,2812.302,156.8424,0,0,0,100,0),
(@PATH,4,262.963,2839.935,173.5923,0,0,0,100,0),
(@PATH,5,249.0294,2865.575,155.9257,0,0,0,100,0),
(@PATH,6,223.3671,2870.441,169.5924,0,0,0,100,0),
(@PATH,7,203.191,2850.286,160.4257,0,0,0,100,0);

-- Pathing for Eye of Thrallmar
SET @NPC :=57586;
SET @PATH :=@NPC*10;
UPDATE `creature` SET `position_x`=210.6249,`position_y`=2809.285,`position_z`=208.7277,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,213.0469,2809.036,207.1722,0,0,0,100,0),
(@PATH,2,223.5349,2797.282,213.4777,0,0,0,100,0),
(@PATH,3,238.895,2805.732,213.4777,0,0,0,100,0),
(@PATH,4,252.788,2818.183,213.4777,0,0,0,100,0),
(@PATH,5,255.2734,2839.056,213.4777,0,0,0,100,0),
(@PATH,6,245.0219,2851.84,213.4777,0,0,0,100,0),
(@PATH,7,229.2117,2860.19,213.4777,0,0,0,100,0),
(@PATH,8,213.6996,2851.376,206.5887,0,0,0,100,0),
(@PATH,9,204.457,2828.248,199.6443,0,0,0,100,0),
(@PATH,10,212.4397,2807.455,199.6443,0,0,0,100,0),
(@PATH,11,241.3802,2813.464,199.6443,0,0,0,100,0),
(@PATH,12,249.7797,2829.964,199.6443,0,0,0,100,0),
(@PATH,13,244.951,2854.129,199.6443,0,0,0,100,0),
(@PATH,14,221.8344,2856.781,199.6443,0,0,0,100,0),
(@PATH,15,210.7503,2837.578,199.6443,0,0,0,100,0),
(@PATH,16,210.6249,2809.285,208.7277,0,0,0,100,0);

-- Pathing for Eye of Thrallmar
SET @NPC :=57587;
SET @PATH :=@NPC*10;
UPDATE `creature` SET `position_x`=236.1859,`position_y`=2813.747,`position_z`=200.9708,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,241.7692,2815.284,200.8042,0,0,0,100,0),
(@PATH,2,255.8273,2833.317,201.443,0,0,0,100,0),
(@PATH,3,247.4309,2853.592,205.1653,0,0,0,100,0),
(@PATH,4,223.9901,2858.107,208.5819,0,0,0,100,0),
(@PATH,5,208.0596,2843.793,192.3596,0,0,0,100,0),
(@PATH,6,213.9734,2816.793,188.4153,0,0,0,100,0),
(@PATH,7,236.1859,2813.747,200.9708,0,0,0,100,0);

-- Pathing for Eye of Thrallmar
SET @NPC :=57588;
SET @PATH :=@NPC*10;
UPDATE `creature` SET `position_x`=245.9259,`position_y`=2829.09,`position_z`=177.804,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,251.6207,2841.322,177.804,0,0,0,100,0),
(@PATH,2,241.4914,2859.113,169.6652,0,0,0,100,0),
(@PATH,3,214.9913,2858.249,176.3595,0,0,0,100,0),
(@PATH,4,210.2245,2836.028,169.7762,0,0,0,100,0),
(@PATH,5,225.7556,2822.145,169.9707,0,0,0,100,0),
(@PATH,6,237.9712,2823.874,170.1096,0,0,0,100,0),
(@PATH,7,245.9259,2829.09,177.804,0,0,0,100,0);

DELETE FROM `creature` WHERE `guid`=57589;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=16598;


