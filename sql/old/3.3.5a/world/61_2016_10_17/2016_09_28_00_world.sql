-- Utgarde Catacombs cleanup
DELETE FROM `creature_addon` WHERE `guid`= 104386;
DELETE FROM `creature` WHERE `id` IN (24177,24250,24226,24253,24254,24255,24270);
UPDATE `creature` SET `modelid`=0, `curhealth`=1 WHERE `id` IN (24216,24249,24250);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (24221,24258,24260);
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry` IN (24253,24254,24255);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry` IN (24177,24270);

-- Spawn Devoring maggot
SET @CGUID := 87514;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 24270, 571, 0, 0, 1, 1, 0, 0, 920.3727, -4820.956, -116.1583, 1.39876, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+1, 24270, 571, 0, 0, 1, 1, 0, 0, 867.1586, -4866.869, -115.7611, 1.117435, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+2, 24270, 571, 0, 0, 1, 1, 0, 0, 868.3704, -4858.826, -115.9888, 5.194222, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+3, 24270, 571, 0, 0, 1, 1, 0, 0, 847.1349, -4847.13, -115.7101, 3.256897, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+4, 24270, 571, 0, 0, 1, 1, 0, 0, 845.8868, -4842.255, -114.9933, 4.433831, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+5, 24270, 571, 0, 0, 1, 1, 0, 0, 846.8536, -4815.939, -115.8419, 5.850776, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+6, 24270, 571, 0, 0, 1, 1, 0, 0, 847.973, -4870.388, -115.7377, 4.820714, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+7, 24270, 571, 0, 0, 1, 1, 0, 0, 838.5492, -4853.339, -115.7324, 3.754435, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+8, 24270, 571, 0, 0, 1, 1, 0, 0, 919.4053, -4845.84, -116.1583, 3.593357, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+9, 24270, 571, 0, 0, 1, 1, 0, 0, 833.8646, -4824.632, -115.9204, 6.045882, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+10, 24270, 571, 0, 0, 1, 1, 0, 0, 828.0585, -4858.886, -115.74, 6.0632, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+11, 24270, 571, 0, 0, 1, 1, 0, 0, 826.5804, -4799.911, -115.99, 5.823083, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+12, 24270, 571, 0, 0, 1, 1, 0, 0, 806.4168, -4802.574, -115.8733, 3.316379, 120, 5, 0, 0, 0, 1, 0, 0, 0, 22594);

-- Spawn Decomposing Ghoul
SET @CGUID := 145699;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+126;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 24177, 571, 0, 0, 1, 1, 0, 0, 808.4636, -4797.996, -115.8793, 0.7169195, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+1, 24177, 571, 0, 0, 1, 1, 0, 0, 819.7922, -4789.436, -115.9284, 2.880837, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+2, 24177, 571, 0, 0, 1, 1, 0, 0, 834.6697, -4786.813, -115.8698, 2.826272, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+3, 24177, 571, 0, 0, 1, 1, 0, 0, 830.127, -4797.064, -116.0019, 2.066683, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+4, 24177, 571, 0, 0, 1, 1, 0, 0, 814.3804, -4803.061, -116.0116, 1.952072, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+5, 24177, 571, 0, 0, 1, 1, 0, 0, 820.9244, -4796.607, -115.9562, 2.57072, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+6, 24177, 571, 0, 0, 1, 1, 0, 0, 836.3658, -4796.596, -115.9631, 2.620821, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+7, 24177, 571, 0, 0, 1, 1, 0, 0, 836.9569, -4828.314, -115.8047, 3.965634, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+8, 24177, 571, 0, 0, 1, 1, 0, 0, 832.2262, -4827.972, -115.8962, 0.8343676, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+9, 24177, 571, 0, 0, 1, 1, 0, 0, 825.8709, -4809.887, -115.9786, 3.707594, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+10, 24177, 571, 0, 0, 1, 1, 0, 0, 805.5407, -4809.622, -115.8285, 5.869238, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+11, 24177, 571, 0, 0, 1, 1, 0, 0, 837.6436, -4820.801, -116.0065, 5.107606, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+12, 24177, 571, 0, 0, 1, 1, 0, 0, 850.1172, -4814.111, -115.7666, 1.185809, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+13, 24177, 571, 0, 0, 1, 1, 0, 0, 843.7394, -4824.81, -115.8572, 3.093958, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+14, 24177, 571, 0, 0, 1, 1, 0, 0, 842.1713, -4837.415, -113.4563, 2.831025, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+15, 24177, 571, 0, 0, 1, 1, 0, 0, 807.8621, -4798.521, -115.8278, 2.666807, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+16, 24177, 571, 0, 0, 1, 1, 0, 0, 850.8365, -4828.295, -115.692, 1.193931, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+17, 24177, 571, 0, 0, 1, 1, 0, 0, 847.2565, -4830.262, -114.3305, 1.14769, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+18, 24177, 571, 0, 0, 1, 1, 0, 0, 843.7939, -4839.741, -114.0746, 5.781772, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+19, 24177, 571, 0, 0, 1, 1, 0, 0, 840.8472, -4838.659, -114.003, 5.042519, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+20, 24177, 571, 0, 0, 1, 1, 0, 0, 833.5086, -4848.921, -115.7298, 5.990555, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+21, 24177, 571, 0, 0, 1, 1, 0, 0, 860.8289, -4836.274, -115.9059, 5.734684, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+22, 24177, 571, 0, 0, 1, 1, 0, 0, 851.3378, -4842.24, -115.1776, 0.7558016, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+23, 24177, 571, 0, 0, 1, 1, 0, 0, 836.7084, -4796.792, -115.885, 0.1194325, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+24, 24177, 571, 0, 0, 1, 1, 0, 0, 853.4523, -4840.377, -115.4864, 2.533747, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+25, 24177, 571, 0, 0, 1, 1, 0, 0, 844.9199, -4844.611, -115.7014, 2.460152, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+26, 24177, 571, 0, 0, 1, 1, 0, 0, 814.6788, -4803.805, -115.9397, 5.893111, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+27, 24177, 571, 0, 0, 1, 1, 0, 0, 831.8257, -4849.502, -115.7292, 2.5805, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+28, 24177, 571, 0, 0, 1, 1, 0, 0, 818.0094, -4851.88, -115.7218, 2.113412, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+29, 24177, 571, 0, 0, 1, 1, 0, 0, 828.2495, -4828.085, -115.8262, 4.087398, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+30, 24177, 571, 0, 0, 1, 1, 0, 0, 828.1373, -4851.577, -115.728, 4.856216, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+31, 24177, 571, 0, 0, 1, 1, 0, 0, 844.6647, -4847.712, -115.7254, 2.022138, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+32, 24177, 571, 0, 0, 1, 1, 0, 0, 837.4983, -4827.729, -115.7987, 3.633486, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+33, 24177, 571, 0, 0, 1, 1, 0, 0, 826.1506, -4861.629, -115.7426, 0.01710411, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+34, 24177, 571, 0, 0, 1, 1, 0, 0, 834.8387, -4860.164, -115.7384, 5.660616, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+35, 24177, 571, 0, 0, 1, 1, 0, 0, 863.8371, -4846.45, -115.9369, 3.531654, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+36, 24177, 571, 0, 0, 1, 1, 0, 0, 857.8271, -4852.726, -115.7195, 5.682756, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+37, 24177, 571, 0, 0, 1, 1, 0, 0, 822.2843, -4872.957, -115.7492, 1.506214, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+38, 24177, 571, 0, 0, 1, 1, 0, 0, 814.674, -4871.774, -115.7436, 5.964203, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+39, 24177, 571, 0, 0, 1, 1, 0, 0, 823.4733, -4871.064, -115.7419, 3.113011, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+40, 24177, 571, 0, 0, 1, 1, 0, 0, 825.8453, -4864.377, -115.7445, 0.1696776, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+41, 24177, 571, 0, 0, 1, 1, 0, 0, 852.1545, -4846.012, -115.7069, 1.761619, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+42, 24177, 571, 0, 0, 1, 1, 0, 0, 834.5052, -4856.091, -115.7357, 1.31766, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+43, 24177, 571, 0, 0, 1, 1, 0, 0, 862.3116, -4850.041, -115.7678, 4.04623, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+44, 24177, 571, 0, 0, 1, 1, 0, 0, 853.0767, -4853.572, -115.7221, 4.217582, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+45, 24177, 571, 0, 0, 1, 1, 0, 0, 830.9197, -4859.985, -115.7397, 2.46908, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+46, 24177, 571, 0, 0, 1, 1, 0, 0, 831.5666, -4858.051, -115.7382, 0.8345159, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+47, 24177, 571, 0, 0, 1, 1, 0, 0, 848.0559, -4852.78, -115.7214, 4.1928, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+48, 24177, 571, 0, 0, 1, 1, 0, 0, 825.5488, -4860.901, -115.7423, 3.012207, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+49, 24177, 571, 0, 0, 1, 1, 0, 0, 819.7171, -4866.284, -115.7481, 3.594609, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+50, 24177, 571, 0, 0, 1, 1, 0, 0, 843.5623, -4864.808, -115.7351, 0.8786021, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+51, 24177, 571, 0, 0, 1, 1, 0, 0, 843.0001, -4863.766, -115.7346, 0.443577, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+52, 24177, 571, 0, 0, 1, 1, 0, 0, 828.4319, -4869.073, -115.7352, 1.259728, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+53, 24177, 571, 0, 0, 1, 1, 0, 0, 854.4937, -4858.273, -115.7319, 5.601525, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+54, 24177, 571, 0, 0, 1, 1, 0, 0, 847.6058, -4863.426, -115.7349, 5.189471, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+55, 24177, 571, 0, 0, 1, 1, 0, 0, 875.7982, -4840.995, -116.1583, 5.949879, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+56, 24177, 571, 0, 0, 1, 1, 0, 0, 834.7258, -4869.169, -115.7291, 1.453525, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+57, 24177, 571, 0, 0, 1, 1, 0, 0, 891.2355, -4836.412, -116.1583, 4.102076, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+58, 24177, 571, 0, 0, 1, 1, 0, 0, 847.6824, -4867.806, -115.7367, 4.502145, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+59, 24177, 571, 0, 0, 1, 1, 0, 0, 885.2512, -4844.67, -116.1583, 3.705964, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+60, 24177, 571, 0, 0, 1, 1, 0, 0, 836.3104, -4873.042, -115.7318, 3.058218, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+61, 24177, 571, 0, 0, 1, 1, 0, 0, 888.4177, -4842.062, -116.1583, 3.002584, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+62, 24177, 571, 0, 0, 1, 1, 0, 0, 847.8503, -4866.572, -115.7366, 1.136817, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+63, 24177, 571, 0, 0, 1, 1, 0, 0, 885.7404, -4844.397, -116.1583, 3.825317, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+64, 24177, 571, 0, 0, 1, 1, 0, 0, 843.4739, -4866.923, -115.7361, 4.962575, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+65, 24177, 571, 0, 0, 1, 1, 0, 0, 874.4485, -4848.259, -116.1583, 4.714963, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+66, 24177, 571, 0, 0, 1, 1, 0, 0, 847.4407, -4871.623, -115.738, 3.9833, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+67, 24177, 571, 0, 0, 1, 1, 0, 0, 878.965, -4845.469, -116.1583, 3.92221, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+68, 24177, 571, 0, 0, 1, 1, 0, 0, 869.8378, -4851.975, -116.1583, 4.504878, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+69, 24177, 571, 0, 0, 1, 1, 0, 0, 829.4056, -4872.515, -115.738, 0.8767114, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+70, 24177, 571, 0, 0, 1, 1, 0, 0, 827.207, -4873.942, -115.7417, 3.053371, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+71, 24177, 571, 0, 0, 1, 1, 0, 0, 881.8891, -4844.848, -116.1583, 0.3287937, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+72, 24177, 571, 0, 0, 1, 1, 0, 0, 885.7446, -4841.823, -116.1583, 6.117681, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+73, 24177, 571, 0, 0, 1, 1, 0, 0, 842.5847, -4870.478, -115.7376, 4.864264, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+74, 24177, 571, 0, 0, 1, 1, 0, 0, 878.3131, -4852.063, -116.1583, 5.697653, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+75, 24177, 571, 0, 0, 1, 1, 0, 0, 850.71, -4870.193, -115.7385, 1.961745, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+76, 24177, 571, 0, 0, 1, 1, 0, 0, 864.5143, -4864.806, -115.7531, 2.512236, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+77, 24177, 571, 0, 0, 1, 1, 0, 0, 855.4762, -4863.237, -115.7409, 3.652666, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+78, 24177, 571, 0, 0, 1, 1, 0, 0, 893.361, -4836.267, -116.1583, 0.324621, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+79, 24177, 571, 0, 0, 1, 1, 0, 0, 859.8801, -4869.853, -115.7517, 3.27202, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+80, 24177, 571, 0, 0, 1, 1, 0, 0, 845.4211, -4874.914, -115.7394, 4.101222, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+81, 24177, 571, 0, 0, 1, 1, 0, 0, 848.3683, -4880.06, -115.488, 5.947936, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+82, 24177, 571, 0, 0, 1, 1, 0, 0, 896.2366, -4836.884, -116.1583, 0.3176279, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+83, 24177, 571, 0, 0, 1, 1, 0, 0, 879.9091, -4858.466, -116.1583, 4.919203, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+84, 24177, 571, 0, 0, 1, 1, 0, 0, 829.8646, -4877.726, -115.7433, 3.958011, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+85, 24177, 571, 0, 0, 1, 1, 0, 0, 871.4382, -4870, -115.7738, 1.426269, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+86, 24177, 571, 0, 0, 1, 1, 0, 0, 883.7388, -4854.001, -116.1583, 0.05471943, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+87, 24177, 571, 0, 0, 1, 1, 0, 0, 863.3215, -4867.509, -115.7548, 5.755741, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+88, 24177, 571, 0, 0, 1, 1, 0, 0, 883.8721, -4850.29, -116.1583, 0.4731597, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+89, 24177, 571, 0, 0, 1, 1, 0, 0, 838.0579, -4879.812, -115.7148, 2.359357, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+90, 24177, 571, 0, 0, 1, 1, 0, 0, 855.0587, -4879.413, -115.517, 2.121084, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+91, 24177, 571, 0, 0, 1, 1, 0, 0, 889.038, -4852.812, -116.1583, 1.002916, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+92, 24177, 571, 0, 0, 1, 1, 0, 0, 898.6837, -4838.287, -116.1583, 0.2386714, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+93, 24177, 571, 0, 0, 1, 1, 0, 0, 888.8219, -4852.866, -116.1583, 3.356553, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+94, 24177, 571, 0, 0, 1, 1, 0, 0, 905.2521, -4810.721, -116.1583, 6.060209, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+95, 24177, 571, 0, 0, 1, 1, 0, 0, 827.3425, -4887.504, -115.0758, 5.229586, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+96, 24177, 571, 0, 0, 1, 1, 0, 0, 894.3109, -4848.724, -116.1583, 3.00603, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+97, 24177, 571, 0, 0, 1, 1, 0, 0, 887.8231, -4847.789, -116.1583, 0.2047823, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+98, 24177, 571, 0, 0, 1, 1, 0, 0, 899.4642, -4845.182, -116.1583, 3.341415, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+99, 24177, 571, 0, 0, 1, 1, 0, 0, 855.9176, -4882.931, -115.3269, 1.696197, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+100, 24177, 571, 0, 0, 1, 1, 0, 0, 904.578, -4835.06, -116.1583, 3.380328, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+101, 24177, 571, 0, 0, 1, 1, 0, 0, 906.4981, -4833.705, -116.1583, 4.58811, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+102, 24177, 571, 0, 0, 1, 1, 0, 0, 903.6366, -4837.302, -116.1583, 0.2942208, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+103, 24177, 571, 0, 0, 1, 1, 0, 0, 906.4175, -4842.198, -116.1583, 0.3234872, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+104, 24177, 571, 0, 0, 1, 1, 0, 0, 903.2219, -4847.269, -116.1583, 3.389911, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+105, 24177, 571, 0, 0, 1, 1, 0, 0, 911.1688, -4828.593, -116.1583, 3.896492, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+106, 24177, 571, 0, 0, 1, 1, 0, 0, 906.7734, -4837.877, -116.1583, 0.6040173, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+107, 24177, 571, 0, 0, 1, 1, 0, 0, 908.0163, -4838.889, -116.1583, 3.144877, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+108, 24177, 571, 0, 0, 1, 1, 0, 0, 903.9756, -4847.67, -116.1583, 0.5884923, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+109, 24177, 571, 0, 0, 1, 1, 0, 0, 905.2701, -4847.071, -116.1583, 0.3876575, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+110, 24177, 571, 0, 0, 1, 1, 0, 0, 907.4946, -4842.498, -116.1583, 3.298591, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+111, 24177, 571, 0, 0, 1, 1, 0, 0, 840.7349, -4850.945, -115.649, 3.784741, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+112, 24177, 571, 0, 0, 1, 1, 0, 0, 852.8289, -4841.896, -115.2602, 0.8993842, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+113, 24177, 571, 0, 0, 1, 1, 0, 0, 830.592, -4871.405, -115.6616, 5.287065, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+114, 24177, 571, 0, 0, 1, 1, 0, 0, 834.9018, -4869.266, -115.6561, 4.333441, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+115, 24177, 571, 0, 0, 1, 1, 0, 0, 851.2184, -4857.029, -115.6508, 1.475937, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+116, 24177, 571, 0, 0, 1, 1, 0, 0, 882.3494, -4849.438, -116.0751, 4.014238, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+117, 24177, 571, 0, 0, 1, 1, 0, 0, 850.9045, -4827.906, -115.634, 2.3141, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+118, 24177, 571, 0, 0, 1, 1, 0, 0, 909.7491, -4841.657, -116.1583, 0.4638954, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+119, 24177, 571, 0, 0, 1, 1, 0, 0, 913.6365, -4814.198, -116.1583, 2.948089, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+120, 24177, 571, 0, 0, 1, 1, 0, 0, 893.0379, -4847.629, -116.0751, 4.01526, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+121, 24177, 571, 0, 0, 1, 1, 0, 0, 907.9617, -4829.465, -116.0752, 0.2794109, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+122, 24177, 571, 0, 0, 1, 1, 0, 0, 908.7168, -4847.154, -116.1583, 3.538296, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+123, 24177, 571, 0, 0, 1, 1, 0, 0, 911.0574, -4839.668, -116.1583, 3.294111, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+124, 24177, 571, 0, 0, 1, 1, 0, 0, 805.171, -4809.459, -115.7392, 2.883095, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+125, 24177, 571, 0, 0, 1, 1, 0, 0, 835.0423, -4786.934, -115.7897, 4.563146, 120,5, 0, 0, 0,1, 0, 0, 0, 22624),
(@CGUID+126, 24177, 571, 0, 0, 1, 1, 0, 0, 847.8881, -4874.416, -115.6562, 2.861061, 120,5, 0, 0, 0,1, 0, 0, 0, 22624);

-- Spawn Dragonflayer Prisoner
SET @CGUID := 84095;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 24226, 571, 0, 0, 1, 1, 0, 0, 905.3108, -4815.514, -72.35855, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+1, 24226, 571, 0, 0, 1, 1, 0, 0, 927.2919, -4862.971, -72.35854, 1.954769, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+2, 24226, 571, 0, 0, 1, 1, 0, 0, 915.6233, -4852.041, -72.35854, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+3, 24226, 571, 0, 0, 1, 1, 0, 0, 918.6141, -4809.841, -72.35852, 4.485496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+4, 24226, 571, 0, 0, 1, 1, 0, 0, 933.6851, -4857.119, -72.35854, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+5, 24226, 571, 0, 0, 1, 1, 0, 0, 913.6568, -4812.906, -72.35854, 4.799655, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594);
-- Dragonflayer Prisoner Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@CGUID+0,0,0,3,1,0, ''),(@CGUID+1,0,0,7,1,0, ''),(@CGUID+2,0,0,3,1,0, ''),(@CGUID+3,0,0,1,1,0, ''),(@CGUID+4,0,0,1,1,0, ''),(@CGUID+5,0,0,1,1,0, '');

-- Spawn Dragonflayer Prisoner
SET @CGUID := 86498;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 24254, 571, 0, 0, 1, 1, 0, 0, 768.5223, -4705.587, -96.23607, 5.445427, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+1, 24254, 571, 0, 0, 1, 1, 0, 0, 768.3083, -4708.337, -96.23607, 1.954769, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+2, 24254, 571, 0, 0, 1, 1, 0, 0, 769.8153, -4705.827, -96.23607, 1.291544, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+3, 24254, 571, 0, 0, 1, 1, 0, 0, 830.6913, -4730.481, -96.23607, 4.485496, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+4, 24254, 571, 0, 0, 1, 1, 0, 0, 830.3710, -4729.467, -96.23606, 2.687807, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+5, 24254, 571, 0, 0, 1, 1, 0, 0, 831.2427, -4729.956, -96.23607, 4.799655, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+6, 24253, 571, 0, 0, 1, 1, 0, 0, 768.2363, -4706.837, -96.23607, 2.222227, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+7, 24253, 571, 0, 0, 1, 1, 0, 0, 831.6885, -4729.309, -96.23608, 1.921136, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+8, 24255, 571, 0, 0, 1, 1, 0, 0, 768.1453, -4707.107, -96.23607, 5.445427, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594),
(@CGUID+9, 24255, 571, 0, 0, 1, 1, 0, 0, 831.4733, -4728.882, -96.23608, 4.865136, 120, 1, 0, 0, 0, 1, 0, 0, 0, 22594);

-- Spawn Dragonflayer Fleshripper
SET @CGUID := 87658;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 24250, 571, 0, 0, 1, 1, 0, 0, 894.2793 ,-4853.812 ,-72.35857, 1.09911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+1, 24250, 571, 0, 0, 1, 1, 0, 0, 835.082 ,-4852.535 ,-72.34498, 5.131268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+2, 24250, 571, 0, 0, 1, 1, 0, 0, 889.3472 ,-4931.63 ,-72.35851, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+3, 24250, 571, 0, 0, 1, 1, 0, 0, 843.719 ,-4788.988 ,-94.0441, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+4, 24250, 571, 0, 0, 1, 1, 0, 0, 832.092 ,-4885.617 ,-72.35873, 1.727876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+5, 24250, 571, 0, 0, 1, 1, 0, 0, 802.9092 ,-4796.535 ,-94.0372, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+6, 24250, 571, 0, 0, 1, 1, 0, 0, 854.3528 ,-4928.178 ,-72.35851, 0.9545009, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+7, 24250, 571, 0, 0, 1, 1, 0, 0, 845.1808 ,-4946.441 ,-72.35851, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+8, 24250, 571, 0, 0, 1, 1, 0, 0, 1012.705 ,-4799.854 ,-70.8481, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+9, 24250, 571, 0, 0, 1, 1, 0, 0 ,982.7759 ,-4805.024 ,-72.35856, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+10, 24250, 571, 0, 0, 1, 1, 0, 0 ,880.2073, -4949.447, -72.3585, 2.570883, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22594),
(@CGUID+11, 24250, 571, 0, 0, 1, 1, 0, 0 ,919.5702, -4815.712, -72.44168, 1.53589, 120, 0, 0, 0, 0, 2, 0, 0, 0, 22594),
(@CGUID+12, 24250, 571, 0, 0, 1, 1, 0, 0 ,917.287, -4848.597, -72.4417, 4.29351, 120, 0, 0, 0, 0, 2, 0, 0, 0, 22594),
(@CGUID+13, 24250, 571, 0, 0, 1, 1, 0, 0 ,830.6761 ,-4871.174 ,-72.42693, 3.996804, 120, 0, 0, 0, 0, 2, 0, 0, 0, 22594);

-- Pathing for Dragonflayer Fleshripper Entry: 24250 'TDB FORMAT' 
SET @NPC := @CGUID+11;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,929.5845,-4854.908,-72.44169,0,0,0,0,100,0),
(@PATH,2,929.5845,-4854.908,-72.44169,5.916666,46000,0,476,100,0),
(@PATH,3,929.5845,-4854.908,-72.44169,5.916666,1000,0,21,100,0),
(@PATH,4,921.6194,-4826.802,-72.4417,0,0,0,0,100,0),
(@PATH,5,919.5702,-4815.712,-72.44168,0,0,0,0,100,0),
(@PATH,6,919.5702,-4815.712,-72.44168,1.53589,33000,0,476,100,0),
(@PATH,7,919.5702,-4815.712,-72.44168,1.53589,33000,0,21,100,0);

-- Pathing for Dragonflayer Fleshripper Entry: 24250 'TDB FORMAT' 
SET @NPC := @CGUID+12;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,909.7383,-4820.702,-72.4417,0,0,0,0,100,0),
(@PATH,2,909.7383,-4820.702,-72.4417,2.408554,180000,0,476,100,0),
(@PATH,3,909.7383,-4820.702,-72.4417,2.408554,1000,0,21,100,0),
(@PATH,4,916.5015,-4834.056,-72.44172,0,0,0,0,100,0),
(@PATH,5,917.287,-4848.597,-72.4417,0,0,0,0,100,0),
(@PATH,6,917.287,-4848.597,-72.4417,4.29351,47000,0,476,100,0),
(@PATH,7,917.287,-4848.597,-72.4417,4.29351,47000,0,21,100,0);

-- Pathing for Dragonflayer Fleshripper Entry: 24250 'TDB FORMAT' 
SET @NPC := @CGUID+13;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=830.6761,`position_y`=-4871.174,`position_z`=-72.42693 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,830.6761,-4871.174,-72.42693,0,0,0,0,100,0),
(@PATH,2,829.3475,-4878.425,-72.43112,0,0,0,0,100,0),
(@PATH,3,829.3475,-4878.425,-72.43112,3.996804,44000,0,476,100,0),
(@PATH,4,829.3475,-4878.425,-72.43112,3.996804,1000,0,21,100,0),
(@PATH,5,829.4708,-4857.084,-72.4222,0,0,0,0,100,0),
(@PATH,6,829.4708,-4857.084,-72.4222,2.164208,39000,0,476,100,0),
(@PATH,7,829.4708,-4857.084,-72.4222,2.164208,1000,0,21,100,0),
(@PATH,8,821.4581,-4857.853,-72.42,0,0,0,0,100,0),
(@PATH,9,821.4581,-4857.853,-72.42,3.089233,37000,0,476,100,0),
(@PATH,10,821.4581,-4857.853,-72.42,3.089233,1000,0,21,100,0);

-- Daegarn SAI
SET @ENTRY := 24151;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,40000,40000,40000,40000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daegarn - Out of Combat - talk");

-- Texts for Daegarn
SET @ENTRY := 24151;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What did you do with the people of this village!?",12,7,100,5,0,0,"Daegarn"),
(@ENTRY,0,1,"What do you want with me?",12,7,100,5,0,0,"Daegarn"),
(@ENTRY,0,2,"Release me, cowards! I'll show you what a dwarf is made of!",12,7,100,5,0,0,"Daegarn");

-- Dragonflayer Berserker SAI
SET @ENTRY := 24216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,0,1,27, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,6000,7000,6000,7000,10,53,60,113,388,397,0,1,0,0,0,0,0,0,0,"Dragonflayer Berserker - Out of Combat - Play Random Emote"),
(@ENTRY,0,1,0,1,0,100,0,5000,15000,30000,40000,11,43291,0,0,0,0,0,11,24221,40,0,0,0,0,0,"Dragonflayer Berserker - Out of Combat - Cast Throw Bottle"),
(@ENTRY,0,2,0,1,0,40,0,14000,26000,14000,26000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Berserker - Out of Combat - talk"),
(@ENTRY,0,3,0,4,0,70,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Berserker - Aggro - talk");

-- Texts for Dragonflayer Berserker
SET @ENTRY := 24216;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Beg for your life...",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,0,1,"Suffer, insect!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,0,2,"Your end draws closer!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,0,3,"My life for Ymiron!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,0,4,"For Ymiron!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,0,5,"YAAARRRGH!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,1,0,"Take me! I am ready to die!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,1,1,"We battle for the glory of Ymiron! We die in the name of the Lich King!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,1,2,"Drink in their misery, brother!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,1,3,"Stand and be judged!",12,0,100,0,0,0,"Dragonflayer Berserker"),
(@ENTRY,1,4,"May you die in the Lich King''s favor!",12,0,100,0,0,0,"Dragonflayer Berserker");

-- Dragonflayer Soulreaver SAI
SET @ENTRY := 24249;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,0,1,0, '43170 43395');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,9000,9000,6000,7000,11,43512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Combat - Cast Spell Mind Flay"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,30000,30000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Combat - Cast Spell Shadow Word: Pain"),
(@ENTRY,0,2,0,4,0,80,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Aggro - talk");

-- Dragonflayer Soulreaver SAI
SET @ENTRY := -113439;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,22000,11,43512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Combat - Cast Spell Mind Flay"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,24000,28000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Combat - Cast Spell Shadow Word: Pain"),
(@ENTRY,0,2,0,1,0,100,0,13000,16000,13000,16000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Out of Combat - talk"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Reset - Set bytes_1 value 8"),
(@ENTRY,0,4,0,4,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Aggro - Remove bytes_1 value 8"),
(@ENTRY,0,5,0,4,0,80,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Soulreaver - Aggro - talk");

-- Texts for Dragonflayer Soulreaver
SET @ENTRY := 24249;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Beg for your life...",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,0,1,"Suffer, insect!",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,0,2,"Your end draws closer!",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,0,3,"My life for Ymiron!",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,0,4,"For Ymiron!",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,0,5,"YAAARRRGH!",12,0,100,0,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,1,0,"I sacrifice this human in the name of our dark master!",12,0,100,53,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,1,1,"Take me, val'kyr! I am ready to be judged!",12,0,100,53,0,0,"Dragonflayer Soulreaver"),
(@ENTRY,1,2,"I am ready to die!",12,0,100,53,0,0,"Dragonflayer Soulreaver");

-- Dragonflayer Fleshripper SAI
SET @ENTRY := 24250;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,25000,35000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Combat - Cast Spell Rend"),
(@ENTRY,0,1,0,0,0,100,0,20000,25000,30000,40000,11,35948,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Combat - Cast Spell Bloodthirst"),
(@ENTRY,0,2,0,4,0,80,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Aggro - talk"),
(@ENTRY,0,3,0,75,0,20,0,0,24249,10,5000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Creature Distance - Run script"),
(@ENTRY,0,4,0,75,0,30,0,0,24226,5,60000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Creature Distance - Say text"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,24249,10,0,0,0,0,0,"Dragonflayer Fleshripper - Script - turn to 24249"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,5,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Script - emote salute"),
(@ENTRY*100,9,2,0,0,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Script - talk"),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fleshripper - Script - turn back");

-- Texts for Dragonflayer Fleshripper
SET @ENTRY := 24250;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Beg for your life...",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,0,1,"Suffer, insect!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,0,2,"Your end draws closer!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,0,3,"My life for Ymiron!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,0,4,"For Ymiron!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,0,5,"YAAARRRGH!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,1,0,"The interlopers will be stopped, my lord.",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,1,1,"One among us will ascend on this day.",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,1,2,"My life for the Dread King!",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,2,0,"I should be in Utgarde Keep, battling at Ingvar's side! Instead I am charged to guard little maggots like you.",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,2,1,"Why we don't just kill you is beyond my understanding.",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,2,2,"Ingvar has plans for you, little one.",12,0,100,0,0,0,"Dragonflayer Fleshripper"),
(@ENTRY,2,3,"Your time in the Ring of Judgment comes soon, maggot.",12,0,100,0,0,0,"Dragonflayer Fleshripper");

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115488;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=910.9276,`position_y`=-4821.955,`position_z`=-55.60853 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,910.9276,-4821.955,-55.60853,0,0,0,0,100,0),
(@PATH,2,914.6762,-4821.778,-55.49743,0,0,0,0,100,0),
(@PATH,3,917.8987,-4821.01,-53.96965,0,0,0,0,100,0),
(@PATH,4,918.1646,-4815.973,-54.85854,0,0,0,0,100,0),
(@PATH,5,915.9987,-4812.069,-53.46965,0,0,0,0,100,0),
(@PATH,6,910.2852,-4813.324,-53.58076,0,0,0,0,100,0),
(@PATH,7,907.968,-4818.275,-53.74744,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115489;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=841.3709,`position_y`=-4795.872,`position_z`=-76.12601 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,841.3709,-4795.872,-76.12601,0,0,0,0,100,0),
(@PATH,2,840.8404,-4793.573,-74.04266,0,0,0,0,100,0),
(@PATH,3,833.8113,-4790.756,-74.04266,0,0,0,0,100,0),
(@PATH,4,821.3549,-4792.356,-76.57045,0,0,0,0,100,0),
(@PATH,5,807.6492,-4795.983,-71.45934,0,0,0,0,100,0),
(@PATH,6,804.2573,-4805.17,-76.09821,0,0,0,0,100,0),
(@PATH,7,808.1563,-4809.107,-71.95932,0,0,0,0,100,0),
(@PATH,8,818.5612,-4809.982,-76.18156,0,0,0,0,100,0),
(@PATH,9,828.702,-4805.078,-72.2371,0,0,0,0,100,0),
(@PATH,10,837.5706,-4800.342,-76.876,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115490;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=842.3616,`position_y`=-4806.111,`position_z`=-49.18903 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,842.3616,-4806.111,-49.18903,0,0,0,0,100,0),
(@PATH,2,837.8431,-4792.732,-47.24458,0,0,0,0,100,0),
(@PATH,3,822.476,-4803.012,-73.18903,0,0,0,0,100,0),
(@PATH,4,809.6625,-4811.376,-83.49458,0,0,0,0,100,0),
(@PATH,5,805.5521,-4798.9,-71.82793,0,0,0,0,100,0),
(@PATH,6,820.4665,-4799.209,-57.68902,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115491;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=875.4474,`position_y`=-4849.245,`position_z`=-55.69189 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,875.4474,-4849.245,-55.69189,0,0,0,0,100,0),
(@PATH,2,881.7186,-4848.778,-52.553,0,0,0,0,100,0),
(@PATH,3,887.1019,-4850.419,-52.553,0,0,0,0,100,0),
(@PATH,4,900.8484,-4871.943,-56.13634,0,0,0,0,100,0),
(@PATH,5,922.4768,-4866.539,-54.77522,0,0,0,0,100,0),
(@PATH,6,956.3114,-4855.176,-55.69189,0,0,0,0,100,0),
(@PATH,7,950.0135,-4821.555,-55.69189,0,0,0,0,100,0),
(@PATH,8,936.5696,-4800.533,-55.69189,0,0,0,0,100,0),
(@PATH,9,902.1412,-4808.334,-55.69189,0,0,0,0,100,0),
(@PATH,10,883.8032,-4817.885,-55.69189,0,0,0,0,100,0),
(@PATH,11,889.0018,-4840.078,-55.69189,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115492;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=848.9135,`position_y`=-4861.279,`position_z`=-56.35685 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,848.9135,-4861.279,-56.35685,0,0,0,0,100,0),
(@PATH,2,843.5121,-4860.611,-55.99573,0,0,0,0,100,0),
(@PATH,3,832.5501,-4862.95,-52.30128,0,0,0,0,100,0),
(@PATH,4,830.4649,-4874.266,-55.3013,0,0,0,0,100,0),
(@PATH,5,838.2181,-4877.518,-57.77352,0,0,0,0,100,0),
(@PATH,6,849.6647,-4878.198,-52.30129,0,0,0,0,100,0),
(@PATH,7,855.8818,-4870.289,-54.88462,0,0,0,0,100,0),
(@PATH,8,853.1998,-4863.428,-54.07906,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115493;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=885.3649,`position_y`=-4965.276,`position_z`=-61.13626 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,885.3649,-4965.276,-61.13626,0,0,0,0,100,0),
(@PATH,2,880.6454,-4976.131,-58.33071,0,0,0,0,100,0),
(@PATH,3,871.6718,-4968.588,-58.33071,0,0,0,0,100,0),
(@PATH,4,847.3286,-4975.932,-58.33071,0,0,0,0,100,0),
(@PATH,5,842.7772,-4960.105,-53.94181,0,0,0,0,100,0),
(@PATH,6,830.4276,-4921.741,-59.58071,0,0,0,0,100,0),
(@PATH,7,847.0207,-4915.108,-55.0807,0,0,0,0,100,0),
(@PATH,8,884.1066,-4903.206,-59.33071,0,0,0,0,100,0),
(@PATH,9,895.1483,-4929.245,-53.91404,0,0,0,0,100,0),
(@PATH,10,904.248,-4959.203,-58.33071,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272 
SET @NPC := 115494;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=856.3028,`position_y`=-4904.302,`position_z`=-58.41408 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,856.3028,-4904.302,-58.41408,0,0,0,0,100,0),
(@PATH,2,854.1736,-4898.4,-59.71962,0,0,0,0,100,0),
(@PATH,3,863.1304,-4928.385,-56.85851,0,0,0,0,100,0),
(@PATH,4,871.4412,-4934.106,-46.71962,0,0,0,0,100,0),
(@PATH,5,873.2085,-4937.753,-46.55295,0,0,0,0,100,0),
(@PATH,6,868.9045,-4944.409,-46.80294,0,0,0,0,100,0),
(@PATH,7,865.4396,-4945.678,-47.44184,0,0,0,0,100,0),
(@PATH,8,859.106,-4939.404,-47.24738,0,0,0,0,100,0),
(@PATH,9,857.4418,-4936.167,-47.58073,0,0,0,0,100,0),
(@PATH,10,861.1564,-4927.124,-47.83072,0,0,0,0,100,0),
(@PATH,11,885.2923,-4930.489,-57.85852,0,0,0,0,100,0),
(@PATH,12,890.7579,-4935.603,-57.85853,0,0,0,0,100,0),
(@PATH,13,902.4837,-4955.032,-59.19186,0,0,0,0,100,0),
(@PATH,14,897.8882,-4959.803,-59.19187,0,0,0,0,100,0),
(@PATH,15,888.0645,-4963.673,-59.19187,0,0,0,0,100,0),
(@PATH,16,878.6978,-4969.428,-59.19187,0,0,0,0,100,0),
(@PATH,17,867.5073,-4945.597,-58.41409,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272 
SET @NPC := 115495;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=956.2941,`position_y`=-4824.18,`position_z`=-58.55297 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,956.2941,-4824.18,-58.55297,0,0,0,0,100,0),
(@PATH,2,954.3386,-4825.676,-56.6363,0,0,0,0,100,0),
(@PATH,3,944.4089,-4828.891,-58.05299,0,0,0,0,100,0),
(@PATH,4,930.319,-4833.362,-58.55297,0,0,0,0,100,0),
(@PATH,5,916.5547,-4832.821,-58.55297,0,0,0,0,100,0),
(@PATH,6,907.5634,-4820.896,-58.55297,0,0,0,0,100,0),
(@PATH,7,912.1163,-4808.627,-58.55297,0,0,0,0,100,0),
(@PATH,8,919.0394,-4811.311,-58.55297,0,0,0,0,100,0),
(@PATH,9,922.1953,-4824.792,-58.55297,0,0,0,0,100,0),
(@PATH,10,917.2956,-4855.327,-58.55297,0,0,0,0,100,0),
(@PATH,11,923.5457,-4863.144,-58.55297,0,0,0,0,100,0),
(@PATH,12,933.1302,-4851.119,-58.55297,0,0,0,0,100,0),
(@PATH,13,917.717,-4840.79,-58.55297,0,0,0,0,100,0),
(@PATH,14,897.5533,-4841.828,-58.55297,0,0,0,0,100,0),
(@PATH,15,879.6963,-4848.92,-58.55297,0,0,0,0,100,0),
(@PATH,16,894.9749,-4844.975,-58.55297,0,0,0,0,100,0),
(@PATH,17,927.064,-4833.625,-58.55297,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272 
SET @NPC := 115496;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=929.0633,`position_y`=-4850.184,`position_z`=-55.19186 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,929.0633,-4850.184,-55.19186,0,0,0,0,100,0),
(@PATH,2,923.3711,-4849.388,-54.10855,0,0,0,0,100,0),
(@PATH,3,919.9915,-4853.378,-54.46964,0,0,0,0,100,0),
(@PATH,4,920.9106,-4857.063,-57.80299,0,0,0,0,100,0),
(@PATH,5,925.6862,-4858.741,-57.38632,0,0,0,0,100,0),
(@PATH,6,929.6542,-4854.92,-59.05297,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272
SET @NPC := 115497;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=808.7459,`position_y`=-4812.053,`position_z`=-60.78423 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,808.7459,-4812.053,-60.78423,0,0,0,0,100,0),
(@PATH,2,808.2299,-4801.94,-63.67312,0,0,0,0,100,0),
(@PATH,3,816.9509,-4795.504,-61.22866,0,0,0,0,100,0),
(@PATH,4,829.1684,-4789.443,-59.75644,0,0,0,0,100,0),
(@PATH,5,841.4839,-4787.07,-63.67311,0,0,0,0,100,0),
(@PATH,6,847.0665,-4798.997,-67.97867,0,0,0,0,100,0),
(@PATH,7,842.1066,-4805.202,-66.75646,0,0,0,0,100,0),
(@PATH,8,832.9062,-4808.456,-63.67311,0,0,0,0,100,0),
(@PATH,9,822.2617,-4811.945,-70.97868,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272 
SET @NPC := 115498;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=855.2356,`position_y`=-4870.746,`position_z`=-52.50243 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,855.2356,-4870.746,-52.50243,0,0,0,0,100,0),
(@PATH,2,854.4634,-4865.868,-55.0302,0,0,0,0,100,0),
(@PATH,3,847.1954,-4852.519,-51.00243,0,0,0,0,100,0),
(@PATH,4,833.2609,-4847.016,-52.50243,0,0,0,0,100,0),
(@PATH,5,826.8834,-4840.739,-55.6691,0,0,0,0,100,0),
(@PATH,6,824.3039,-4827.225,-50.64132,0,0,0,0,100,0),
(@PATH,7,833.8077,-4811.925,-57.25243,0,0,0,0,100,0),
(@PATH,8,829.8226,-4795.333,-51.89131,0,0,0,0,100,0),
(@PATH,9,808.6812,-4796.883,-50.14132,0,0,0,0,100,0),
(@PATH,10,809.5606,-4808.788,-52.50243,0,0,0,0,100,0),
(@PATH,11,819.323,-4813.951,-56.2802,0,0,0,0,100,0),
(@PATH,12,834.9311,-4820.883,-55.75244,0,0,0,0,100,0),
(@PATH,13,839.3295,-4836.557,-51.00243,0,0,0,0,100,0),
(@PATH,14,837.7294,-4845.846,-52.50243,0,0,0,0,100,0),
(@PATH,15,836.0781,-4862.733,-50.97466,0,0,0,0,100,0),
(@PATH,16,842.9083,-4873.529,-52.50243,0,0,0,0,100,0),
(@PATH,17,851.3279,-4875.863,-56.25243,0,0,0,0,100,0);

-- Pathing for Val'kyr Watcher Entry: 24272 
SET @NPC := 115499;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=920.4993,`position_y`=-4830.998,`position_z`=-51.35856 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,920.4993,-4830.998,-51.35856,0,0,0,0,100,0),
(@PATH,2,915.2309,-4832.864,-51.63634,0,0,0,0,100,0),
(@PATH,3,914.1133,-4838.874,-51.21967,0,0,0,0,100,0),
(@PATH,4,918.5,-4841.554,-50.99744,0,0,0,0,100,0),
(@PATH,5,923.9588,-4838.46,-51.77522,0,0,0,0,100,0),
(@PATH,6,923.8309,-4834.089,-51.44189,0,0,0,0,100,0);

-- Pathing for Dragonflayer Soulreaver Entry: 24249 
SET @NPC := 113437;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=885.358,`position_y`=-4847.41,`position_z`=-72.44175 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43170 43395');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,885.358,-4847.41,-72.44175,0,0,0,0,100,0),
(@PATH,2,898.1722,-4843.27,-72.44173,0,0,0,0,100,0),
(@PATH,3,921.0853,-4835.571,-72.44172,0,0,0,0,100,0),
(@PATH,4,936.793,-4830.751,-72.4417,0,0,0,0,100,0),
(@PATH,5,960.9143,-4823.05,-72.44169,0,0,0,0,100,0),
(@PATH,6,984.8827,-4814.897,-72.43644,0,0,0,0,100,0),
(@PATH,7,1004.875,-4808.8,-71.58034,0,0,0,0,100,0),
(@PATH,8,984.8827,-4814.897,-72.43644,0,0,0,0,100,0),
(@PATH,9,960.9143,-4823.05,-72.44169,0,0,0,0,100,0),
(@PATH,10,936.793,-4830.751,-72.4417,0,0,0,0,100,0),
(@PATH,11,921.0853,-4835.571,-72.44172,0,0,0,0,100,0),
(@PATH,12,898.1722,-4843.27,-72.44173,0,0,0,0,100,0),
(@PATH,13,885.358,-4847.41,-72.44175,0,0,0,0,100,0),
(@PATH,14,866.1418,-4853.872,-72.43889,0,0,0,0,100,0),
(@PATH,15,853.93,-4866.703,-72.41554,0,0,0,0,100,0),
(@PATH,16,848.7006,-4882.123,-72.43921,0,0,0,0,100,0),
(@PATH,17,855.0558,-4900.146,-72.44171,0,0,0,0,100,0),
(@PATH,18,859.8029,-4916.118,-72.44168,0,0,0,0,100,0),
(@PATH,19,867.2998,-4938.807,-72.44167,0,0,0,0,100,0),
(@PATH,20,869.3615,-4945.732,-72.44165,0,0,0,0,100,0),
(@PATH,21,872.436,-4955,-72.44164,0,0,0,0,100,0),
(@PATH,22,869.3615,-4945.732,-72.44165,0,0,0,0,100,0),
(@PATH,23,867.2998,-4938.807,-72.44167,0,0,0,0,100,0),
(@PATH,24,859.8029,-4916.118,-72.44168,0,0,0,0,100,0),
(@PATH,25,855.0558,-4900.146,-72.44171,0,0,0,0,100,0),
(@PATH,26,848.7006,-4882.123,-72.43921,0,0,0,0,100,0),
(@PATH,27,853.93,-4866.703,-72.41554,0,0,0,0,100,0),
(@PATH,28,866.1418,-4853.872,-72.43889,0,0,0,0,100,0);

-- Pathing for Dragonflayer Soulreaver Entry: 24249 
SET @NPC := 113440;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=824.0359,`position_y`=-4868.71,`position_z`=-72.42241 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43170 43395');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,824.0359,-4868.71,-72.42241,0,0,0,0,100,0),
(@PATH,2,834.4585,-4867.213,-72.42434,0,0,0,0,100,0),
(@PATH,3,843.8245,-4861.521,-72.42833,0,0,0,0,100,0),
(@PATH,4,847.9713,-4848.108,-72.40897,0,0,0,0,100,0),
(@PATH,5,845.7209,-4832.671,-77.23508,0,0,0,0,100,0),
(@PATH,6,841.707,-4818.461,-86.72793,0,0,0,0,100,0),
(@PATH,7,836.6263,-4805.677,-94.12235,0,0,0,0,100,0),
(@PATH,8,827.1885,-4798.477,-94.1694,0,0,0,0,100,0),
(@PATH,9,816.0269,-4803.745,-94.1339,0,0,0,0,100,0),
(@PATH,10,816.0802,-4817.76,-95.55515,0,0,0,0,100,0),
(@PATH,11,817.9224,-4829.894,-103.178,0,0,0,0,100,0),
(@PATH,12,820.6011,-4838.25,-108.7283,0,0,0,0,100,0),
(@PATH,13,823.5452,-4846.18,-114.0035,0,0,0,0,100,0),
(@PATH,14,820.6011,-4838.25,-108.7283,0,0,0,0,100,0),
(@PATH,15,817.9647,-4830.026,-103.2644,0,0,0,0,100,0),
(@PATH,16,816.0802,-4817.76,-95.55515,0,0,0,0,100,0),
(@PATH,17,816.0269,-4803.745,-94.1339,0,0,0,0,100,0),
(@PATH,18,827.1885,-4798.477,-94.1694,0,0,0,0,100,0),
(@PATH,19,836.6263,-4805.677,-94.12235,0,0,0,0,100,0),
(@PATH,20,841.6176,-4818.145,-86.91146,0,0,0,0,100,0),
(@PATH,21,845.7209,-4832.671,-77.23508,0,0,0,0,100,0),
(@PATH,22,847.9713,-4848.108,-72.40897,0,0,0,0,100,0),
(@PATH,23,843.8245,-4861.521,-72.42833,0,0,0,0,100,0),
(@PATH,24,834.4585,-4867.213,-72.42434,0,0,0,0,100,0);

-- Pathing for Dragonflayer Soulreaver Entry: 24249 
SET @NPC := 113441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=807.8324,`position_y`=-4679.818,`position_z`=-94.18642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43170 43395');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,807.8324,-4679.818,-94.18642,0,0,0,0,100,0),
(@PATH,2,833.4255,-4687.322,-94.18632,0,0,0,0,100,0),
(@PATH,3,842.6976,-4721.211,-94.18537,0,0,0,0,100,0),
(@PATH,4,851.1219,-4726.752,-94.18114,0,0,0,0,100,0),
(@PATH,5,849.4189,-4740.732,-94.18343,0,0,0,0,100,0),
(@PATH,6,841.0457,-4748.864,-94.18208,0,0,0,0,100,0),
(@PATH,7,830.0615,-4755.675,-94.18501,0,0,0,0,100,0),
(@PATH,8,820.2598,-4769.392,-94.18431,0,0,0,0,100,0),
(@PATH,9,797.0748,-4775.84,-94.17949,0,0,0,0,100,0),
(@PATH,10,777.4241,-4764.886,-94.18331,0,0,0,0,100,0),
(@PATH,11,767.0198,-4768.298,-94.18798,0,0,0,0,100,0),
(@PATH,12,753.5901,-4754.301,-94.18281,0,0,0,0,100,0),
(@PATH,13,755.6175,-4741.035,-94.1843,0,0,0,0,100,0),
(@PATH,14,752.2223,-4721.712,-94.18828,0,0,0,0,100,0),
(@PATH,15,743.8878,-4718.405,-94.18477,0,0,0,0,100,0),
(@PATH,16,748.4409,-4704.046,-94.18089,0,0,0,0,100,0),
(@PATH,17,758.511,-4702.61,-94.18445,0,0,0,0,100,0),
(@PATH,18,776.7408,-4684.623,-94.18909,0,0,0,0,100,0),
(@PATH,19,775.6336,-4674.919,-94.18436,0,0,0,0,100,0),
(@PATH,20,787.8163,-4670.81,-94.18746,0,0,0,0,100,0),
(@PATH,21,792.2169,-4677.878,-94.18677,0,0,0,0,100,0);

-- Pathing for Dragonflayer Soulreaver Entry: 24249 
SET @NPC := 113442;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=823.4291,`position_y`=-4766.659,`position_z`=-94.18111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43170 43395');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,823.4291,-4766.659,-94.18111,0,0,0,0,100,0),
(@PATH,2,833.645,-4755.143,-94.18497,0,0,0,0,100,0),
(@PATH,3,846.8239,-4750.019,-94.18383,0,0,0,0,100,0),
(@PATH,4,853.4371,-4737.234,-94.18234,0,0,0,0,100,0),
(@PATH,5,853.8495,-4721.374,-94.18234,0,0,0,0,100,0),
(@PATH,6,844.4109,-4714.604,-94.18147,0,0,0,0,100,0),
(@PATH,7,840.1658,-4703.946,-94.18958,0,0,0,0,100,0),
(@PATH,8,844.4326,-4692.242,-94.18233,0,0,0,0,100,0),
(@PATH,9,835.8003,-4680.62,-94.18233,0,0,0,0,100,0),
(@PATH,10,820.7093,-4672.119,-94.18233,0,0,0,0,100,0),
(@PATH,11,808.5036,-4678.676,-94.18518,0,0,0,0,100,0),
(@PATH,12,793.2575,-4665.763,-94.18475,0,0,0,0,100,0),
(@PATH,13,778.1424,-4669.995,-94.18234,0,0,0,0,100,0),
(@PATH,14,768.0452,-4675.979,-94.18233,0,0,0,0,100,0),
(@PATH,15,763.7438,-4693.8,-94.18654,0,0,0,0,100,0),
(@PATH,16,745.8027,-4700.843,-94.18233,0,0,0,0,100,0),
(@PATH,17,739.8701,-4714.022,-94.18233,0,0,0,0,100,0),
(@PATH,18,743.1232,-4730.644,-94.18164,0,0,0,0,100,0),
(@PATH,19,755.0081,-4737.88,-94.18655,0,0,0,0,100,0),
(@PATH,20,750.1789,-4753.967,-94.18233,0,0,0,0,100,0),
(@PATH,21,757.1357,-4765.574,-94.18233,0,0,0,0,100,0),
(@PATH,22,773.7014,-4776.117,-94.18233,0,0,0,0,100,0),
(@PATH,23,789.7719,-4768.197,-94.18789,0,0,0,0,100,0),
(@PATH,24,800.2666,-4774.506,-94.1813,0,0,0,0,100,0),
(@PATH,25,812.3613,-4773.502,-94.18728,0,0,0,0,100,0);

-- Pathing for Val'kyr Overseer Entry: 24258
SET @NPC := 114183;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=801.7946,`position_y`=-4743.732,`position_z`=-68.81113 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,801.7946,-4743.732,-68.81113,0,0,0,0,100,0),
(@PATH,2,810.841,-4724.843,-68.61668,0,0,0,0,100,0),
(@PATH,3,808.7681,-4718.541,-65.17223,0,0,0,0,100,0),
(@PATH,4,798.9675,-4710.67,-65.17223,0,0,0,0,100,0),
(@PATH,5,785.416,-4707.411,-65.17223,0,0,0,0,100,0),
(@PATH,6,775.47,-4725.557,-65.17223,0,0,0,0,100,0),
(@PATH,7,784.8812,-4743.483,-65.17223,0,0,0,0,100,0);

-- Pathing for Val'kyr Overseer Entry: 24258 
SET @NPC := 114190;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=801.8325,`position_y`=-4702.211,`position_z`=-73.97776 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,801.8325,-4702.211,-73.97776,0,0,0,0,100,0),
(@PATH,2,815.7599,-4716.915,-71.25553,0,0,0,0,100,0),
(@PATH,3,816.8605,-4741.882,-73.00555,0,0,0,0,100,0),
(@PATH,4,795.744,-4748.135,-71.9222,0,0,0,0,100,0),
(@PATH,5,778.3672,-4739.311,-69.28331,0,0,0,0,100,0),
(@PATH,6,775.7975,-4717.895,-73.11665,0,0,0,0,100,0),
(@PATH,7,788.4036,-4704.089,-73.61664,0,0,0,0,100,0);

-- Pathing for Val'kyr Overseer Entry: 24258 
SET @NPC := 114191;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=801.2428,`position_y`=-4748.294,`position_z`=-79.56106 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,801.2428,-4748.294,-79.56106,0,0,0,0,100,0),
(@PATH,2,820.7194,-4732.687,-84.69994,0,0,0,0,100,0),
(@PATH,3,819.9661,-4713.885,-82.53329,0,0,0,0,100,0),
(@PATH,4,809.4178,-4704.249,-83.28329,0,0,0,0,100,0),
(@PATH,5,794.2107,-4704.679,-78.50551,0,0,0,0,100,0),
(@PATH,6,781.2782,-4710.818,-84.64439,0,0,0,0,100,0),
(@PATH,7,780.4466,-4742.383,-82.83884,0,0,0,0,100,0);

-- Pathing for Val'kyr Overseer Entry: 24258 
SET @NPC := 114192;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=778.0256,`position_y`=-4713.221,`position_z`=-67.42218 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,778.0256,-4713.221,-67.42218,0,0,0,0,100,0),
(@PATH,2,795.8828,-4708.047,-73.64442,0,0,0,0,100,0),
(@PATH,3,814.5335,-4707.928,-72.67219,0,0,0,0,100,0),
(@PATH,4,819.3694,-4734.119,-73.94997,0,0,0,0,100,0),
(@PATH,5,814.3889,-4744.631,-70.1722,0,0,0,0,100,0),
(@PATH,6,794.3046,-4746.817,-73.53331,0,0,0,0,100,0),
(@PATH,7,779.2559,-4732.826,-70.1722,0,0,0,0,100,0);
