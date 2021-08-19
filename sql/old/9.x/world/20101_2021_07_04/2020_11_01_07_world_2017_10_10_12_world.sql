-- 
SET @cguid:=146981;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 25419, 571, 0, 0, '0', 0, 0, 0, 4419.61, 5952.447, 57.03477, 1.121153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+1, 25419, 571, 0, 0, '0', 0, 0, 0, 4448.788, 5916.716, 57.72005, 5.721869, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+2, 25419, 571, 0, 0, '0', 0, 0, 0, 4448.035, 5957.813, 57.98078, 1.14177, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+3, 25419, 571, 0, 0, '0', 0, 0, 0, 4461.483, 5886.482, 61.893, 3.48094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+4, 25419, 571, 0, 0, '0', 0, 0, 0, 4413.073, 5904.856, 56.37568, 4.019106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+5, 25419, 571, 0, 0, '0', 0, 0, 0, 4382.702, 5905.957, 55.72123, 2.909203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+6, 25419, 571, 0, 0, '0', 0, 0, 0, 4421.654, 5896.283, 55.94137, 4.782922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: -1)
(@CGUID+7, 25419, 571, 0, 0, '0', 0, 0, 0, 4348.286, 5917.032, 60.72934, 5.387158, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+8, 25419, 571, 0, 0, '0', 0, 0, 0, 4451.888, 5851.77, 69.95783, 6.034452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+9, 25417, 571, 0, 0, '0', 0, 0, 0, 4393.225, 5881.099, 55.97466, 4.578428, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+10, 25419, 571, 0, 0, '0', 0, 0, 0, 4386.144, 5881.497, 55.75355, 3.575644, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+11, 25419, 571, 0, 0, '0', 0, 0, 0, 4384.099, 5850.214, 69.215, 0.3004377, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+12, 25419, 571, 0, 0, '0', 0, 0, 0, 4320.845, 5906.834, 57.5699, 5.094295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+13, 25419, 571, 0, 0, '0', 0, 0, 0, 4343.608, 5851.565, 56.67913, 1.960553, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+14, 25417, 571, 0, 0, '0', 0, 0, 0, 4313.515, 5889.598, 56.97303, 0.8698314, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+15, 25419, 571, 0, 0, '0', 0, 0, 0, 4344.71, 5882.019, 56.23266, 5.41927, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+16, 25419, 571, 0, 0, '0', 0, 0, 0, 4315.075, 5880.785, 56.03077, 1.569275, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+17, 25419, 571, 0, 0, '0', 0, 0, 0, 4284.087, 5915.679, 57.39619, 2.622871, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+18, 25419, 571, 0, 0, '0', 0, 0, 0, 4386.544, 5815.437, 71.95725, 5.795134, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+19, 25419, 571, 0, 0, '0', 0, 0, 0, 4315.096, 5840.36, 58.56625, 5.083281, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+20, 25419, 571, 0, 0, '0', 0, 0, 0, 4285.949, 5883.651, 58.90496, 0.1985445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+21, 25417, 571, 0, 0, '0', 0, 0, 0, 4417.659, 5814.049, 73.62916, 2.305409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+22, 25419, 571, 0, 0, '0', 0, 0, 0, 4347.293, 5797.105, 70.4449, 3.9803, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+23, 25417, 571, 0, 0, '0', 0, 0, 0, 4287.359, 5808.424, 65.015, 1.333162, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+24, 25419, 571, 0, 0, '0', 0, 0, 0, 4315.808, 5817.751, 63.17729, 1.716837, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+25, 25419, 571, 0, 0, '0', 0, 0, 0, 4295.346, 5844.404, 59.16083, 5.644846, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+26, 25417, 571, 0, 0, '0', 0, 0, 0, 4313.68, 5790.48, 68.38795, 3.758053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+27, 25417, 571, 0, 0, '0', 0, 0, 0, 4306.196, 5755.188, 74.17075, 0.4614642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+28, 25417, 571, 0, 0, '0', 0, 0, 0, 4285.329, 5785.763, 69.6144, 6.263107, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+29, 25417, 571, 0, 0, '0', 0, 0, 0, 4380.976, 5786.691, 76.09017, 5.706718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+30, 25417, 571, 0, 0, '0', 0, 0, 0, 4345.296, 5780.17, 74.79289, 2.769791, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+31, 25417, 571, 0, 0, '0', 0, 0, 0, 4380.676, 5750.541, 81.36572, 2.86511, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+32, 25417, 571, 0, 0, '0', 0, 0, 0, 4277.169, 5757.782, 68.8129, 0.09976582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+33, 25417, 571, 0, 0, '0', 0, 0, 0, 4350.86, 5749.646, 82.05293, 4.125741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+34, 25419, 571, 0, 0, '0', 0, 0, 0, 4411.514, 5790.069, 76.78316, 3.849571, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25419 (Area: 4134)
(@CGUID+35, 25417, 571, 0, 0, '0', 0, 0, 0, 4413.009, 5788.343, 77.10886, 5.096886, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+36, 25417, 571, 0, 0, '0', 0, 0, 0, 4351.502, 5714.72, 86.44733, 4.789735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+37, 25417, 571, 0, 0, '0', 0, 0, 0, 4373.826, 5713.223, 85.16576, 3.343639, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4134)
(@CGUID+38, 25417, 571, 0, 0, '0', 0, 0, 0, 4317.503, 5711.320, 89.224, 4.042527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+39, 25417, 571, 0, 0, '0', 0, 0, 0, 4250.292, 5746.842, 66.42384, 1.142227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+40, 25417, 571, 0, 0, '0', 0, 0, 0, 4309.887, 5676.108, 92.774, 5.29737, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+41, 25417, 571, 0, 0, '0', 0, 0, 0, 4315.956, 5653.785, 94.06521, 3.442963, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+42, 25417, 571, 0, 0, '0', 0, 0, 0, 4255.53, 5709.95, 56.70618, 2.291923, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+43, 25417, 571, 0, 0, '0', 0, 0, 0, 4242.124, 5780.734, 66.33765, 3.578308, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+44, 25417, 571, 0, 0, '0', 0, 0, 0, 4218.904, 5751.581, 65.40733, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+45, 25419, 571, 0, 0, '0', 0, 0, 0, 4420.043, 5841.368, 67.582, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
-- water eles
(@CGUID+46, 25419, 571, 0, 0, '0', 0, 0, 0, 4456.091, 5874.284, 64.093, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+47, 25419, 571, 0, 0, '0', 0, 0, 0, 4456.091, 5874.284, 64.093, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+48, 25419, 571, 0, 0, '0', 0, 0, 0, 4325.170, 5855.809, 57.569, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+49, 25419, 571, 0, 0, '0', 0, 0, 0, 4325.170, 5855.809, 57.569, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
-- fire eles
(@CGUID+50, 25417, 571, 0, 0, '0', 0, 0, 0, 4348.101, 5731.171, 83.638, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+51, 25417, 571, 0, 0, '0', 0, 0, 0, 4348.101, 5731.171, 83.638, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+52, 25417, 571, 0, 0, '0', 0, 0, 0, 4348.101, 5731.171, 83.638, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 25417 (Area: 4133)
(@CGUID+53, 25417, 571, 0, 0, '0', 0, 0, 0, 4348.101, 5731.171, 83.638, 1.580321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- 25417 (Area: 4133)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, ''), -- 25415
(@CGUID+1, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+2, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+3, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+4, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+5, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+6, 0, 0, 0, 1, 0, ''), -- 25418
(@CGUID+7, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+8, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+10, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+11, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+12, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+13, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+15, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+16, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+18, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+19, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+20, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+21, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+22, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+23, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+24, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+25, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+26, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+27, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+28, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+29, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+30, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+32, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+33, 0, 0, 0, 1, 0, ''), -- 31685
(@CGUID+34, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+35, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+36, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+37, 0, 0, 0, 1, 0, ''), -- 25419
(@CGUID+38, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+39, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+40, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+41, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+42, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+43, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+44, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+45, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- 25417
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- 25416
(@CGUID+49, 0, 0, 0, 1, 0, ''), -- 24613
(@CGUID+50, 0, 0, 0, 1, 0, ''), -- 24613
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- 24613
(@CGUID+52, 0, 0, 0, 1, 0, ''), -- 24614
(@CGUID+53, 0, 0, 0, 1, 0, ''); -- 31685

UPDATE `creature` SET `spawntimesecs` = 300 , `spawndist` = 10 , `curhealth` = 1 , `MovementType` = 1 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53; 
UPDATE `creature` SET `spawntimesecs` = 300 , `spawndist` = 4 , `curhealth` = 1 , `MovementType` = 1 WHERE `guid` = @CGUID+11; 

-- delete water eles
DELETE FROM `creature` WHERE `guid` BETWEEN 102648 AND 102652;
DELETE FROM `creature` WHERE `guid` BETWEEN 102661 AND 102666;
DELETE FROM `creature` WHERE `guid` IN (102645, 102626);
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 102648 AND 102652;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 102661 AND 102666;
DELETE FROM `creature_addon` WHERE `guid` IN (102645, 102626);

UPDATE `creature` SET `position_x` = 4309.695 , `position_y` = 5633.367 , `position_z` = 94.87403 , `orientation` = 1.413717 WHERE `guid` = 200013; 

-- air eles
UPDATE `creature` SET `spawndist` = 10 WHERE `guid` BETWEEN 102437 AND 102442; 
UPDATE `creature` SET `spawndist` = 10 WHERE `guid` BETWEEN 102471 AND 102485; 
UPDATE `creature` SET `spawndist` = 10 WHERE `guid` = 102452; 

-- Pathing for Enraged Tempest Entry: 25415 'TDB FORMAT' 
SET @NPC := 102479;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4582.429,`position_y`=5916.411,`position_z`=56.099 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4582.429,5916.411,56.099,0,0,0,0,100,0), -- 20:25:05
(@PATH,2,4567.213,5933.478,62.72065,0,0,0,0,100,0), -- 20:25:16
(@PATH,3,4550.817,5949.297,68.55141,0,0,0,0,100,0), -- 20:25:25
(@PATH,4,4542.173,5982.366,71.99318,0,0,0,0,100,0), -- 20:25:36
(@PATH,5,4563.726,6018.92,78.21175,0,0,0,0,100,0), -- 20:25:51
(@PATH,6,4586.041,6047.054,81.09695,0,0,0,0,100,0), -- 20:26:09
(@PATH,7,4606.639,6079.772,79.38864,0,0,0,0,100,0), -- 20:26:23
(@PATH,8,4602.986,6101.729,78.74768,0,0,0,0,100,0), -- 20:26:37
(@PATH,9,4582.914,6126.627,81.2157,0,0,0,0,100,0), -- 20:26:49
(@PATH,10,4556.886,6142.86,81.20538,0,0,0,0,100,0), -- 20:27:03
(@PATH,11,4572.895,6134.833,81.22743,0,0,0,0,100,0), -- 20:27:16
(@PATH,12,4600.353,6109.119,78.72827,0,0,0,0,100,0), -- 20:27:26
(@PATH,13,4604.147,6095.896,79.12968,0,0,0,0,100,0), -- 20:27:39
(@PATH,14,4600.552,6070.209,81.15663,0,0,0,0,100,0), -- 20:27:52
(@PATH,15,4570.93,6028.483,79.49257,0,0,0,0,100,0), -- 20:28:07
(@PATH,16,4542.822,5986.35,72.76584,0,0,0,0,100,0), -- 20:28:19
(@PATH,17,4550.624,5951.442,69.22236,0,0,0,0,100,0), -- 20:28:38
(@PATH,18,4564.791,5935.697,64.15934,0,0,0,0,100,0), -- 20:28:54
(@PATH,19,4582.332,5916.214,55.95428,0,0,0,0,100,0); -- 20:29:03

-- Pathing for Enraged Tempest Entry: 25415 'TDB FORMAT' 
SET @NPC := 102473;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4497.891,`position_y`=6137.541,`position_z`=80.16054 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4497.891,6137.541,80.16054,0,0,0,0,100,0), -- 20:26:22
(@PATH,2,4497.828,6131.405,79.64149,0,0,0,0,100,0), -- 20:26:30
(@PATH,3,4499.488,6112.93,80.19643,0,0,0,0,100,0), -- 20:26:35
(@PATH,4,4491.456,6088.593,78.08659,0,0,0,0,100,0), -- 20:26:45
(@PATH,5,4505.488,6055.596,76.68158,0,0,0,0,100,0), -- 20:26:52
(@PATH,6,4491.953,6023.114,67.60138,0,0,0,0,100,0), -- 20:27:07
(@PATH,7,4514.078,5986.287,68.74522,0,0,0,0,100,0), -- 20:27:21
(@PATH,8,4500.425,5965.788,63.89717,0,0,0,0,100,0), -- 20:27:39
(@PATH,9,4503.254,5931.495,61.60934,0,0,0,0,100,0), -- 20:27:57
(@PATH,10,4489.393,5948.091,63.07407,0,0,0,0,100,0), -- 20:28:15
(@PATH,11,4513.931,5982.552,67.93922,0,0,0,0,100,0), -- 20:28:30
(@PATH,12,4494.02,6016.712,67.46692,0,0,0,0,100,0), -- 20:28:48
(@PATH,13,4501.351,6044.861,75.96799,0,0,0,0,100,0), -- 20:29:05
(@PATH,14,4492.195,6082.638,77.78274,0,0,0,0,100,0), -- 20:29:21
(@PATH,15,4500.411,6098.807,79.48975,0,0,0,0,100,0), -- 20:29:35
(@PATH,16,4498.477,6122.489,79.74394,0,0,0,0,100,0), -- 20:29:41
(@PATH,17,4497.76,6137.652,80.19916,0,0,0,0,100,0); -- 20:29:51

-- paths water eles
SET @NPC := @CGUID+46;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4456.091,`position_y`=5874.284,`position_z`=64.093 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,3,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,5,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,6,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,8,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,9,4456.091,5874.284,64.093,0,0,1,0,100,0); -- 20:26:22

SET @NPC := @CGUID+47;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4408.679,`position_y`=5920.878,`position_z`=55.669 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4408.679,5920.878,55.669,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,3,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,4,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,5,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,6,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,8,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,9,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,10,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,11,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,12,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,13,4408.679,5920.878,55.669,0,0,1,0,100,0); -- 20:26:22

SET @NPC := @CGUID+48;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4325.170,`position_y`=5855.809,`position_z`=57.569 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,3,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,5,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,6,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,8,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,9,4325.170,5855.809,57.569,0,0,1,0,100,0); -- 20:26:22

SET @NPC := @CGUID+49;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4370.834,`position_y`=5889.521,`position_z`=55.853 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4370.834,5889.521,55.853,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,3,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,4,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,5,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,6,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,8,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,9,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,10,4325.170,5855.809,57.569,0,0,1,0,100,0); -- 20:26:22


SET @NPC := @CGUID+34;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4400.289,`position_y`=5853.771,`position_z`=64.700 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4400.289,5853.771,64.700,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4406.379,5794.868,75.189,0,0,1,0,100,0), -- 20:26:30
(@PATH,3,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,5,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,6,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,8,4406.379,5794.868,75.189,0,0,1,0,100,0), -- 20:26:30
(@PATH,9,4400.289,5853.771,64.700,0,0,1,0,100,0); -- 20:26:22

SET @NPC := @CGUID+19;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4325.170,`position_y`=5855.809,`position_z`=57.569 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,2,4301.863,5794.378,67.805,0,0,1,0,100,0), -- 20:26:30
(@PATH,3,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,5,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,6,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,7,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,8,4301.863,5794.378,67.805,0,0,1,0,100,0), -- 20:26:30
(@PATH,9,4325.170,5855.809,57.569,0,0,1,0,100,0); -- 20:26:22

-- fire eles paths
SET @NPC := @CGUID+50;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4309.625,`position_y`=5638.164,`position_z`=94.449 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,2,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,3,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,5,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,6,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,7,4408.679,5920.878,55.669,0,0,1,0,100,0), -- 20:26:22
(@PATH,8,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,9,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,10,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,11,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,12,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,13,4309.625,5638.164,94.449,0,0,1,0,100,0); -- 20:26:45

SET @NPC := @CGUID+51;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4347.967,`position_y`=5730.564,`position_z`=83.739 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4347.967,5730.564,83.739,0,0,1,0,100,0), -- 20:26:35
(@PATH,2,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,3,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,4,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,5,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,6,4408.679,5920.878,55.669,0,0,1,0,100,0), -- 20:26:22
(@PATH,7,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,8,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,9,4418.135,5826.952,70.059,0,0,1,0,100,0), -- 20:26:30
(@PATH,10,4364.599,5757.606,80.218,0,0,1,0,100,0), -- 20:26:35
(@PATH,11,4347.967,5730.564,83.739,0,0,1,0,100,0); -- 20:26:35

SET @NPC := 102601;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4400.118,`position_y`=5793.260,`position_z`=75.037 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4400.118,5793.260,75.037,0,0,1,0,100,0), -- 20:26:35
(@PATH,2,4400.289,5853.771,64.700,0,0,1,0,100,0), -- 20:26:22
(@PATH,3,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,4,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,5,4391.264,5878.812,55.666,0,0,1,0,100,0), -- 20:26:22
(@PATH,6,4356.525,5896.896,56.012,0,0,1,0,100,0), -- 20:26:22
(@PATH,7,4391.264,5878.812,55.666,0,0,1,0,100,0), -- 20:26:22
(@PATH,8,4453.867,5900.081,59.354,0,0,1,0,100,0), -- 20:26:22
(@PATH,9,4456.091,5874.284,64.093,0,0,1,0,100,0), -- 20:26:22
(@PATH,10,4400.289,5853.771,64.700,0,0,1,0,100,0), -- 20:26:22
(@PATH,11,4400.118,5793.260,75.037,0,0,1,0,100,0); -- 20:26:35

SET @NPC := @CGUID+52;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4309.625,`position_y`=5638.164,`position_z`=94.449 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4309.625,5638.164,94.449,0,0,1,0,100,0), -- 20:26:45
(@PATH,2,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,3,4347.967,5730.564,83.739,0,0,1,0,100,0), -- 20:26:35
(@PATH,4,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,5,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,6,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,7,4356.525,5896.896,56.012,0,0,1,0,100,0), -- 20:26:22
(@PATH,8,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,9,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,10,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,11,4347.967,5730.564,83.739,0,0,1,0,100,0), -- 20:26:35
(@PATH,12,4312.593,5704.205,90.690,0,0,1,0,100,0), -- 20:26:45
(@PATH,13,4309.625,5638.164,94.449,0,0,1,0,100,0); -- 20:26:45

SET @NPC := @CGUID+53;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4347.967,`position_y`=5730.564,`position_z`=83.739 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4347.967,5730.564,83.739,0,0,1,0,100,0), -- 20:26:35
(@PATH,2,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,3,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,4,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,5,4356.525,5896.896,56.012,0,0,1,0,100,0), -- 20:26:22
(@PATH,6,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,7,4331.969,5789.342,70.842,0,0,1,0,100,0), -- 20:26:30
(@PATH,8,4340.155,5758.681,79.466,0,0,1,0,100,0), -- 20:26:35
(@PATH,9,4347.967,5730.564,83.739,0,0,1,0,100,0); -- 20:26:35

SET @NPC := 102600;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4319.603,`position_y`=5784.604,`position_z`=69.714 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4319.603,5784.604,69.714,0,0,1,0,100,0), -- 20:26:35
(@PATH,2,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,3,4356.525,5896.896,56.012,0,0,1,0,100,0), -- 20:26:22
(@PATH,4,4325.170,5855.809,57.569,0,0,1,0,100,0), -- 20:26:22
(@PATH,5,4319.603,5784.604,69.714,0,0,1,0,100,0);

-- Boiling Spirit SAI
SET @ENTRY := 25419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,50206,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boiling Spirit - In Combat - Cast 'Scalding Steam'");

-- Raging Boiler SAI
SET @ENTRY := 25417;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,50207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Boiler - In Combat - Cast 'Boiling Blood'");

UPDATE `creature_template` SET `DamageModifier` = 1.2 WHERE `entry` = 25417; 

-- Enraged Tempest SAI
SET @ENTRY := 25415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,120000,120000,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Tempest - Between 0-50% Health - Cast 'Enrage'"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,11,50215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Tempest - On Just Died - Cast 'Zephyr'");
