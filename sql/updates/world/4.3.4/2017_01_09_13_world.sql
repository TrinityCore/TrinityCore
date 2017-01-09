--
SET @CGUID := 250026;
DELETE FROM `creature` WHERE `id` BETWEEN 8210 AND 8219;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 8210, 0, 0, 0, 1, 1, 0, 0, 0, 101.2535, -4123.439, 172.8117, 2.513274, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8210 Razortalon Rare
(@CGUID+1, 8211, 0, 0, 0, 1, 1, 0, 0, 0, 80.68924, -2095.195, 113.1613, 3.735005, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8211 Old Cliff Jumper Rare
(@CGUID+2, 8212, 0, 0, 0, 1, 1, 0, 0, 0, 364.6962, -3795.405, 171.4433, 0.50505, 120000, 5, 0, 1, 0, 1, 0, 0, 0, 23222), -- 8212 The Reak Rare
(@CGUID+3, 8213, 0, 0, 0, 1, 1, 0, 0, 0, 13.55792, -4670.14, 9.560886, 5.367609, 120000, 10, 0, 1, 0, 1, 0, 0, 0, 23222), -- 8213 Ironback Rare
(@CGUID+4, 8214, 0, 0, 0, 1, 1, 0, 0, 0, 58.53993, -2908.906, 115.6817, 2.199115, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8214 Jalinde Summerdrake Rare
(@CGUID+5, 8215, 0, 0, 0, 1, 1, 0, 0, 0, -131.599, -4337.361, 135.6074, 5.575138, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8215 Grimungous Rare
(@CGUID+6, 8216, 0, 0, 0, 1, 1, 0, 0, 0, -252.7065, -3418.581, 163.9043, 3.83404, 120000, 0, 0, 1, 0, 2, 0, 0, 0, 23222), -- 8216 Retherokk The Berserker Rare
(@CGUID+7, 8217, 0, 0, 0, 1, 1, 0, 0, 0, -631.6024, -4072.503, 238.6663, 3.159046, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8217 Mith`rethis The Enchanter Rare
(@CGUID+8, 8218, 0, 0, 0, 1, 1, 0, 0, 0, -237.7153, -3112.335, 125.751, 1.727876, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8218 Witherheart The Stalker Rare
(@CGUID+9, 8219, 0, 0, 0, 1, 1, 0, 0, 0, -214.1649, -2523.273, 118.5041, 4.18879, 120000, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 8219 Zul'arek Hatefowler Rare
(@CGUID+10, 2640, 0, 0, 0, 1, 1, 0, 0, 0, -296.8905, -4167.815, 136.4466, 0.9849242, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2640 
(@CGUID+11, 2640, 0, 0, 0, 1, 1, 0, 0, 0, -294.7113, -4111.446, 137.4777, 4.027113, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2640 
(@CGUID+12, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -310.6821, -4202.085, 137.5622, 5.925552, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4465 
(@CGUID+13, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -311.3799, -4135.26, 136.9623, 2.597605, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4465 
(@CGUID+14, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -283.0217, -4142.365, 136.7434, 0.01745329, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4465
(@CGUID+15, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -276.6738, -4212.105, 136.3606, 5.826622, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4465
(@CGUID+16, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -280.7188, -4214.664, 136.8459, 2.8292, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222); -- 4465

SET @CGUID := 251184;
DELETE FROM `creature` WHERE `guid` IN (278801,278787,278426,278427);
DELETE FROM `creature` WHERE `guid` BETWEEN 278812 AND 278840;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 278812 AND 278840;
DELETE FROM `creature` WHERE `guid` IN (278810,278811,278817,278833,278844,278848,278863,278864);
DELETE FROM `creature_addon` WHERE `guid` IN (278810,278811,278817,278833,278844,278848,278863,278864);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -608.7956, -3806.088, 238.9825, 0.3391256, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+1, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -638.423, -3813.172, 230.7805, 1.849781, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+2, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -664.152, -3795.323, 223.439, 5.390024, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+3, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -701.6794, -3718.922, 238.1163, 0.6001411, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+4, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -731.1082, -3750.499, 235.2371, 3.583518, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+5, 4075, 0, 0, 0, 1, 1, 0, 0, 0, -710.8499, -3700.889, 233.908, 5.032559, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 4075 Rat
(@CGUID+6, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -627.1963, -3841.872, 235.0289, 4.363582, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+7, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -600.8868, -3799.866, 236.493, 0.3592527, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+8, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -574.8731, -3806.915, 235.4047, 4.899583, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+9, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -593.2894, -3788.529, 236.7897, 5.968546, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+10, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -605.1924, -3794.589, 237.9833, 3.620992, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+11, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -608.329, -3781.287, 240.1658, 1.192191, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+12, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -627.267, -3794.745, 235.7311, 3.474902, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+13, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -656.5789, -3813.464, 226.1417, 1.755308, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+14, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -636.5413, -3785.888, 231.2919, 5.654318, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+15, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -611.775, -3763.216, 233.2912, 4.610962, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+16, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -609.386, -3757.009, 232.0977, 2.132595, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+17, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -659.9223, -3798.425, 224.5815, 1.962019, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+18, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -627.1904, -3739.672, 233.293, 0.08660996, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+19, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -618.6515, -3740.074, 232.5356, 6.202462, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+20, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -669.9534, -3792.662, 222.7375, 6.031985, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+21, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -661.8912, -3767.821, 223.5414, 3.680815, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+22, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -635.5818, -3727.25, 234.8563, 0.5121437, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+23, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -626.7623, -3734.221, 233.2612, 6.132655, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+24, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -671.5661, -3743.432, 221.2046, 5.201729, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+25, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -680.4857, -3768.191, 220.6308, 2.64238, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+26, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -641.0101, -3726.152, 235.6062, 5.662982, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+27, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -672.3889, -3757.501, 220.9368, 2.202346, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+28, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -693.2059, -3756.623, 220.7856, 2.11699, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+29, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -705.5532, -3781.617, 226.4135, 3.639673, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+30, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -713.0941, -3780.002, 226.8275, 2.970215, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+31, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -712.642, -3755.924, 234.1238, 1.191027, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+32, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -721.307, -3757.205, 233.8016, 3.353385, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+33, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -677.909, -3703.467, 224.9244, 5.608123, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+34, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -731.611, -3780.07, 230.2183, 0, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+35, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -671.8797, -3700.797, 224.9471, 6.204938, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+36, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -737.0838, -3762.26, 233.2035, 4.43078, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+37, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -733.5049, -3778.053, 230.347, 0.8571718, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+38, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -704.7576, -3719.207, 238.1415, 3.972723, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+39, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -736.3867, -3762.977, 233.0542, 0.7418172, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+40, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -718.1517, -3728.705, 238.2844, 4.311355, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+41, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -743.6503, -3784.961, 231.5213, 2.880282, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+42, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -675.6412, -3690.571, 228.5154, 4.886071, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+43, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -676.618, -3685.632, 230.4247, 5.341321, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+44, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -674.0057, -3677.806, 231.4881, 3.279948, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+45, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -709.3322, -3680.713, 232.1908, 1.277609, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+46, 14881, 0, 0, 0, 1, 1, 0, 0, 0, -697.691, -3673.721, 232.8588, 1.259923, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 14881 Spider
(@CGUID+47, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -565.5434, -3831.823, 234.9122, 5.864306, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+48, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -578.7448, -3803.799, 235.0221, 2.154474, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+49, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -604.2947, -3791.699, 238.5831, 6.183424, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+50, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -611.9299, -3748.688, 231.1299, 3.266886, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+51, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -645.0364, -3811.121, 229.167, 1.647379, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+52, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -667.4815, -3801.322, 222.9417, 4.726198, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+53, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -625.8585, -3736.616, 233.1844, 5.646459, 120, 0, 0, 1, 0, 2, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+54, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -638.6163, -3730.158, 230.592, 2.373648, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+55, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -675.9734, -3779.973, 221.9275, 4.978273, 120, 0, 0, 1, 0, 2, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+56, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -690.4488, -3779.787, 228.1711, 0.192542, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+57, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -677.6154, -3764.926, 220.8464, 5.583363, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+58, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -682.3189, -3735.995, 218.923, 0.7508205, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+59, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -714.1218, -3747.265, 235.3767, 1.025457, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+60, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -726.3847, -3777.65, 229.8129, 0.9328126, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+61, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -706.651, -3721.888, 238.1756, 1.559227, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+62, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -715.2934, -3732.658, 238.1331, 4.315888, 120, 0, 0, 1, 0, 2, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+63, 42879, 0, 0, 0, 1, 1, 0, 0, 0, -688.2827, -3674.572, 233.4627, 5.552467, 120, 6, 0, 1, 0, 1, 0, 0, 0, 23222), -- 42879 Spawn of Shadra
(@CGUID+64, 45439, 0, 0, 0, 1, 1, 0, 0, 0, -680.3643, -3771.307, 220.7337, 2.174744, 120, 8, 0, 0, 0, 1, 0, 0, 0, 23222), -- 45439 Cockroach
(@CGUID+65, 45439, 0, 0, 0, 1, 1, 0, 0, 0, -675.3947, -3734.667, 220.0398, 1.739893, 120, 8, 0, 0, 0, 1, 0, 0, 0, 23222), -- 45439 Cockroach
(@CGUID+66, 42877, 0, 0, 0, 1, 1, 0, 0, 0, -752.4427, -3787.913, 230.9504, 3.543018, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23222); -- 42877 Morta'gya the Keeper

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(278810, 2645, 0, 0, 0, 1, 1, 0, 0, 0, -162.014, -3792.81, 238.2969, 2.513274, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 2645 Vilebranch Shadow Hunter
(278811, 4465, 0, 0, 0, 1, 1, 0, 0, 0, -300.8814, -4190.363, 136.5622, 2.513274, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23222), -- 4465 Vilebranch Warrior 
(278817, 2640, 0, 0, 0, 1, 1, 0, 0, 0, -336.711, -4213.299, 152.1899, 0.2114051, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2640
(278833, 2640, 0, 0, 0, 1, 1, 0, 0, 0, -313.7775, -4228.961, 136.6896, 3.159046, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2640
(278844, 2641, 0, 0, 0, 1, 1, 0, 0, 0, -351.2706, -4181.298, 152.1125, 1.68542, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2641
(278848, 2641, 0, 0, 0, 1, 1, 0, 0, 0, -351.9893, -4205.648, 152.3052, 2.485164, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2641
(278863, 2641, 0, 0, 0, 1, 1, 0, 0, 0, -348.0254, -4222.727, 152.3547, 3.40067, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222), -- 2641
(278864, 2641, 0, 0, 0, 1, 1, 0, 0, 0, -358.0292, -4116.998, 154.2687, 3.40067, 120, 2, 0, 1, 0, 1, 0, 0, 0, 23222); -- 2641

UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id` IN (2505,2655,2656,2657,2658,2923,2924,2925,2926,2927,2928,2929,16030,42913);
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id` IN (2639,2681,4466,4467,42592,43891);
UPDATE `creature` SET `spawndist`=15,`MovementType`=1 WHERE `id` IN (2657);
UPDATE `creature` SET `spawndist`=2,`MovementType`=1 WHERE `id` IN (2640,2641,2642,2643,2644,2645,2646,2647,2648);
UPDATE `creature` SET `spawndist`=2,`MovementType`=1 WHERE `guid` IN (278638);

UPDATE `creature` SET `position_x`=375.012, `position_y`=-2812.79, `position_z`=122.6463, `orientation`=3.508112 WHERE `guid`=279310;

UPDATE `npc_spellclick_spells` SET `cast_flags`=3 WHERE `npc_entry` IN (44776);

DELETE FROM `gossip_menu` WHERE `entry`=12091;
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES (12091,16975,23222);

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (42704);
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry` IN (42704);


UPDATE `creature_template` SET `VehicleId`=1434, `InhabitType`=4 WHERE `entry` IN (43161);

UPDATE `creature_template` SET `gossip_menu_id`=11715 WHERE `entry` IN (43156);
UPDATE `creature_template` SET `gossip_menu_id`=11716 WHERE `entry` IN (43157);
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry` IN (43770);
UPDATE `creature_template` SET `gossip_menu_id`=345 WHERE `entry` IN (43699);
UPDATE `creature_template` SET `gossip_menu_id`=11771 WHERE `entry` IN (43109);
UPDATE `creature_template` SET `gossip_menu_id`=11687 WHERE `entry` IN (43108);
UPDATE `creature_template` SET `gossip_menu_id`=12127 WHERE `entry` IN (46475);
UPDATE `creature_template` SET `gossip_menu_id`=11772 WHERE `entry` IN (43200);

DELETE FROM `gossip_menu` WHERE `entry` IN (11687,11715,11716,11771);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES (11687,16364,23222);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES (11715,16394,23222);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES (11716,16396,23222);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES (11771,16505,23222);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=11716;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(11716,0,0, 'I need to get to the top of Jintha''Alor. Time to ride Sharpbeak!',44810,1,1,0,0,0,0,NULL);

-- Old Cliff Jumper SAI
SET @ENTRY := 8211;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,17,418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Cliff Jumper - Out of Combat - Set Emotestate (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Cliff Jumper - On Aggro - Set Emotestate"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,12000,14000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Cliff Jumper - In Combat - Cast 'Carnivorous Bite'"),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,19000,22000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Cliff Jumper - In Combat - Cast 'Blood Howl'"),
(@ENTRY,0,4,0,9,0,100,0,0,5,15000,16000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Cliff Jumper - Within 0-5 Range - Cast 'Tendon Rip'");

-- Zul'arek Hatefowler SAI
SET @ENTRY := 8219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'arek Hatefowler - Out of Combat - Set Bytes_1 (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'arek Hatefowler - On Aggro - Remove Bytes_1 value"),
(@ENTRY,0,2,0,0,0,100,0,3500,5800,11000,16000,11,17228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'arek Hatefowler - In Combat - Cast 'Shadow Bolt Volley'");

-- Mith'rethis the Enchanter SAI
SET @ENTRY := 8217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,79452,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - Out of Combat - Cast 'Shadow Channeling' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,30000,38000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,15000,30000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - In Combat - Cast 'Slow'"),
(@ENTRY,0,3,0,0,0,100,0,0,0,20000,24000,11,3443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mith'rethis the Enchanter - In Combat - Cast 'Enchanted Quickness' (No Repeat)");

-- Razortalon SAI
SET @ENTRY := 8210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,96433,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razortalon - OOC - Cast 'Moonbeam Visual'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,12000,13000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - In Combat - Cast 'Moonfire'"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,22000,25000,11,79823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - In Combat - Cast 'Starfall'");

-- Doran Steelwing SAI
SET @ENTRY := 43157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11716,0,0,0,11,83486,0,0,0,0,0,7,0,0,0,0,0,0,0,"Doran Steelwing - On Gossip Option 0 Selected - Cast 'Sharpbeak Taxi - Camp to Jintha'Alor - Force Cast'");

-- Vilebranch Shadowcaster SAI
SET @ENTRY := 2642;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4500,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,9500,25000,26000,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat - Cast 'Shrink'");

-- Umboda Three-Heads SAI
SET @ENTRY := 42724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,2000,2000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - OOC - Play emote"),
(@ENTRY,0,1,0,1,0,100,0,2000,2000,2000,2000,5,389,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - OOC - Play emote"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - On Aggro - Say Line 1"),
(@ENTRY,0,3,0,0,0,100,0,0,0,7000,9000,11,85280,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umboda Three-Heads - In Combat - Cast 'Two-fisted Skull Bash'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - Between 0-30% Health - Cast 'Enrage'"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umboda Three-Heads - Between 0-30% Health - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=42724 AND `groupid`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42724, 1, 0, 'Ya head''s gonna make a nice bag!', 12, 0, 100, 0, 0, 0, 43286, 'Umboda Three-Heads');

-- Pathing for Grimungous Entry: 8215 'TDB FORMAT'
SET @NPC := 250031;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-131.599,`position_y`=-4337.361,`position_z`=135.6074 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-131.599,-4337.361,135.6074,0,0,0,0,100,0),
(@PATH,2,-107.9705,-4329.764,136.531,0,0,0,0,100,0),
(@PATH,3,-84.55729,-4338.757,128.7241,0,0,0,0,100,0),
(@PATH,4,-58.87153,-4358.403,132.0829,0,0,0,0,100,0),
(@PATH,5,-29.8125,-4387.245,145.1532,0,0,0,0,100,0),
(@PATH,6,3.053819,-4376.488,138.2881,0,0,0,0,100,0),
(@PATH,7,31.80903,-4406.141,144.5007,0,0,0,0,100,0),
(@PATH,8,52.05556,-4423.448,142.3691,0,0,0,0,100,0),
(@PATH,9,45.2309,-4454.274,144.5039,0,0,0,0,100,0),
(@PATH,10,54.75174,-4469.245,142.0615,0,0,0,0,100,0),
(@PATH,11,72.74132,-4460.874,147.0309,0,0,0,0,100,0),
(@PATH,12,93.01389,-4476.587,145.2449,0,0,0,0,100,0),
(@PATH,13,87.24306,-4491.625,141.287,0,0,0,0,100,0),
(@PATH,14,61.44271,-4518.493,142.6496,0,0,0,0,100,0),
(@PATH,15,35.66146,-4527.335,146.5226,0,0,0,0,100,0),
(@PATH,16,51.17361,-4522.934,145.3512,0,0,0,0,100,0),
(@PATH,17,76.07291,-4504.045,144.1156,0,0,0,0,100,0),
(@PATH,18,97.61632,-4520.255,135.2897,0,0,0,0,100,0),
(@PATH,19,126.2344,-4516.108,127.969,0,0,0,0,100,0),
(@PATH,20,147.8316,-4539.193,120.3605,0,0,0,0,100,0),
(@PATH,21,146.3681,-4586.854,119.9066,0,0,0,0,100,0),
(@PATH,22,181.1858,-4595.208,123.1245,0,0,0,0,100,0),
(@PATH,23,146.3681,-4586.854,119.9066,0,0,0,0,100,0),
(@PATH,24,147.8316,-4539.193,120.3605,0,0,0,0,100,0),
(@PATH,25,126.2344,-4516.108,127.969,0,0,0,0,100,0),
(@PATH,26,97.61632,-4520.255,135.2897,0,0,0,0,100,0),
(@PATH,27,76.07291,-4504.045,144.1156,0,0,0,0,100,0),
(@PATH,28,51.17361,-4522.934,145.3512,0,0,0,0,100,0),
(@PATH,29,35.66146,-4527.335,146.5226,0,0,0,0,100,0),
(@PATH,30,61.18555,-4518.58,142.6151,0,0,0,0,100,0),
(@PATH,31,87.24306,-4491.625,141.287,0,0,0,0,100,0),
(@PATH,32,93.01389,-4476.587,145.2449,0,0,0,0,100,0),
(@PATH,33,72.74132,-4460.874,147.0309,0,0,0,0,100,0),
(@PATH,34,54.75174,-4469.245,142.0615,0,0,0,0,100,0),
(@PATH,35,45.2309,-4454.274,144.5039,0,0,0,0,100,0),
(@PATH,36,52.05556,-4423.448,142.3691,0,0,0,0,100,0),
(@PATH,37,31.80903,-4406.141,144.5007,0,0,0,0,100,0),
(@PATH,38,3.300781,-4376.672,138.3854,0,0,0,0,100,0),
(@PATH,39,-29.8125,-4387.245,145.1532,0,0,0,0,100,0),
(@PATH,40,-58.87153,-4358.403,132.0829,0,0,0,0,100,0),
(@PATH,41,-84.55729,-4338.757,128.7241,0,0,0,0,100,0),
(@PATH,42,-107.9705,-4329.764,136.531,0,0,0,0,100,0);

-- Pathing for Retherokk the Berserker Entry: 8216 'TDB FORMAT' 
SET @NPC := 250032;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-239.6146,`position_y`=-3406.905,`position_z`=152.6844 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-239.6146,-3406.905,152.6844,0,0,0,0,100,0),
(@PATH,2,-247.0243,-3413.868,156.9854,0,0,0,0,100,0),
(@PATH,3,-252.9184,-3418.757,164.1624,0,0,0,0,100,0),
(@PATH,4,-269.934,-3435.764,187.1341,0,0,0,0,100,0),
(@PATH,5,-275.066,-3436.215,187.1301,0,0,0,0,100,0),
(@PATH,6,-291.474,-3451.382,190.4714,0,0,0,0,100,0),
(@PATH,7,-291.9462,-3456.253,191.754,0,0,0,0,100,0),
(@PATH,8,-291.474,-3451.382,190.4714,0,0,0,0,100,0),
(@PATH,9,-275.066,-3436.215,187.1301,0,0,0,0,100,0),
(@PATH,10,-269.934,-3435.764,187.1341,0,0,0,0,100,0),
(@PATH,11,-252.9184,-3418.757,164.1624,0,0,0,0,100,0),
(@PATH,12,-247.0243,-3413.868,156.9854,0,0,0,0,100,0);

-- Pathing for Wildhammer Sentry Entry: 7865 'TDB FORMAT' 
SET @NPC := 279453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=196.2908,`position_y`=-2016.318,`position_z`=142.7772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,196.2908,-2016.318,142.7772,0,0,0,0,100,0),
(@PATH,2,198.6215,-2032.04,137.4908,0,0,0,0,100,0),
(@PATH,3,207.4544,-2045.196,133.0707,0,0,0,0,100,0),
(@PATH,4,224.699,-2066.138,127.2239,0,0,0,0,100,0),
(@PATH,5,235.4831,-2086.107,122.5928,0,0,0,0,100,0),
(@PATH,6,233.9076,-2110.25,117.9585,0,0,0,0,100,0),
(@PATH,7,230.9954,-2125.501,117.6037,0,0,0,0,100,0),
(@PATH,8,233.087,-2143.763,119.2953,0,0,0,0,100,0),
(@PATH,9,233.1134,-2162.836,120.0148,0,0,0,0,100,0),
(@PATH,10,238.9667,-2174.679,118.8334,0,0,0,0,100,0),
(@PATH,11,233.1134,-2162.836,120.0148,0,0,0,0,100,0),
(@PATH,12,233.087,-2143.763,119.2953,0,0,0,0,100,0),
(@PATH,13,230.9954,-2125.501,117.6037,0,0,0,0,100,0),
(@PATH,14,233.9076,-2110.25,117.9585,0,0,0,0,100,0),
(@PATH,15,235.4831,-2086.107,122.5928,0,0,0,0,100,0),
(@PATH,16,224.699,-2066.138,127.2239,0,0,0,0,100,0),
(@PATH,17,207.4544,-2045.196,133.0707,0,0,0,0,100,0),
(@PATH,18,198.6215,-2032.04,137.4908,0,0,0,0,100,0);

-- Pathing for Wildhammer Sentry Entry: 7865 'TDB FORMAT' 
SET @NPC := 278606;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=344.983,`position_y`=-4140.87,`position_z`=124.0857,`orientation`=1.7558 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,344.983,-4140.87,124.0857,0,10000,0,0,100,0),
(@PATH,2,346.988,-4142.09,124.0857,0,0,0,0,100,0),
(@PATH,3,349.04,-4139.33,124.0857,0,0,0,0,100,0),
(@PATH,4,349.257,-4138.13,124.0857,0,0,0,0,100,0),
(@PATH,5,349.252,-4133.68,124.0857,0,0,0,0,100,0),
(@PATH,6,351.028,-4127.83,124.0857,0,0,0,0,100,0),
(@PATH,7,350.175,-4123.31,124.0857,0,0,0,0,100,0),
(@PATH,8,345.595,-4116.22,124.0857,0,0,0,0,100,0),
(@PATH,9,345.595,-4116.22,124.0857,3.595378,18000,0,0,100,0),
(@PATH,10,352.34,-4123.79,124.0857,0,0,0,0,100,0),
(@PATH,11,351.878,-4126.89,124.0857,0,0,0,0,100,0),
(@PATH,12,351.498,-4131.66,124.0857,0,0,0,0,100,0),
(@PATH,13,347.417,-4133.28,124.0857,0,0,0,0,100,0),
(@PATH,14,342.252,-4132.51,124.0857,0,0,0,0,100,0),
(@PATH,15,341.177,-4128.88,125.7862,0,0,0,0,100,0),
(@PATH,16,341.543,-4126.16,127.6093,0,0,0,0,100,0),
(@PATH,17,339.653,-4117.85,131.1938,0,0,0,0,100,0),
(@PATH,18,333.175,-4121.01,131.1959,0,0,0,0,100,0),
(@PATH,19,330.332,-4130.83,131.2008,0,0,0,0,100,0),
(@PATH,20,334.252,-4136.15,131.1891,0,0,0,0,100,0),
(@PATH,21,342.063,-4137.24,131.1999,0,0,0,0,100,0),
(@PATH,22,347.519,-4134.63,131.2081,0,0,0,0,100,0),
(@PATH,23,350.589,-4127.01,131.2094,0,0,0,0,100,0),
(@PATH,24,349.915,-4122.56,131.2085,0,0,0,0,100,0),
(@PATH,25,349.915,-4122.56,131.2085,0.9424778,20000,0,0,100,0),
(@PATH,26,343.602,-4118.86,131.2005,0,0,0,0,100,0),
(@PATH,27,342.179,-4121.43,130.7798,0,0,0,0,100,0),
(@PATH,28,341.323,-4123.93,129.1039,0,0,0,0,100,0),
(@PATH,29,341.446,-4128.9,125.7726,0,0,0,0,100,0),
(@PATH,30,340.224,-4132.68,124.0857,0,0,0,0,100,0),
(@PATH,31,347.719,-4133.81,124.0857,0,0,0,0,100,0),
(@PATH,32,350.486,-4133.42,124.0857,0,0,0,0,100,0),
(@PATH,33,352.436,-4130.34,124.0857,0,0,0,0,100,0),
(@PATH,34,351.75,-4125.81,124.0857,0,0,0,0,100,0),
(@PATH,35,347.899,-4120.95,124.0857,0,0,0,0,100,0),
(@PATH,36,345.667,-4116.65,124.0857,0,0,0,0,100,0),
(@PATH,37,345.667,-4116.65,124.0857,3.595378,16000,0,0,100,0),
(@PATH,38,351.715,-4122.61,124.0857,0,0,0,0,100,0),
(@PATH,39,352.351,-4126.03,124.0857,0,0,0,0,100,0),
(@PATH,40,352.212,-4130.76,124.0857,0,0,0,0,100,0),
(@PATH,41,349.04,-4139.33,124.0857,0,0,0,0,100,0),
(@PATH,42,346.988,-4142.09,124.0857,0,0,0,0,100,0);

-- Pathing for Wildhammer Sentry Entry: 7865 'TDB FORMAT' 
SET @NPC := 279029;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-248.979,`position_y`=-3663.22,`position_z`=237.8069 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-248.979,-3663.22,237.8069,0,0,0,0,100,0),
(@PATH,2,-243.75,-3652.35,236.9185,0,0,0,0,100,0);

-- Pathing for Gammerita Entry: 7977 'TDB FORMAT' 
SET @NPC := 278327;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-463.8164,`position_y`=-4545.512,`position_z`=8.880444 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-463.8164,-4545.512,8.880444,0,0,0,0,100,0),
(@PATH,2,-475.3613,-4525.611,13.19495,0,0,0,0,100,0),
(@PATH,3,-458.0208,-4518.71,10.41739,0,0,0,0,100,0),
(@PATH,4,-444.3385,-4521.28,9.717922,0,0,0,0,100,0),
(@PATH,5,-432.5868,-4521.139,9.457339,0,0,0,0,100,0),
(@PATH,6,-406.3611,-4518.181,8.639224,0,0,0,0,100,0),
(@PATH,7,-395.474,-4516.976,7.59934,0,0,0,0,100,0),
(@PATH,8,-379.3438,-4514.667,7.707251,0,0,0,0,100,0),
(@PATH,9,-363.026,-4516.372,8.693643,0,0,0,0,100,0),
(@PATH,10,-348.4097,-4529.736,9.599404,0,0,0,0,100,0),
(@PATH,11,-353.3056,-4560.213,8.476274,0,0,0,0,100,0),
(@PATH,12,-360.1545,-4586.944,5.410193,0,0,0,0,100,0),
(@PATH,13,-359.9844,-4616.25,6.888034,0,0,0,0,100,0),
(@PATH,14,-340.4375,-4646.484,8.036587,0,0,0,0,100,0),
(@PATH,15,-308.9948,-4626.662,9.056196,0,0,0,0,100,0),
(@PATH,16,-285.033,-4582.703,11.21207,0,0,0,0,100,0),
(@PATH,17,-246.2656,-4582.21,10.08424,0,0,0,0,100,0),
(@PATH,18,-214.5313,-4586.795,9.048365,0,0,0,0,100,0),
(@PATH,19,-196.6267,-4569.622,11.25989,0,0,0,0,100,0),
(@PATH,20,-190.4965,-4545.601,12.59623,0,0,0,0,100,0),
(@PATH,21,-210.408,-4529.252,11.47813,0,0,0,0,100,0),
(@PATH,22,-229.6927,-4514.13,11.22813,0,0,0,0,100,0),
(@PATH,23,-219.3542,-4488.837,11.51373,0,0,0,0,100,0),
(@PATH,24,-201.8125,-4484.825,12.30059,0,0,0,0,100,0),
(@PATH,25,-178.9462,-4499.559,12.41798,0,0,0,0,100,0),
(@PATH,26,-201.8125,-4484.825,12.30059,0,0,0,0,100,0),
(@PATH,27,-219.3542,-4488.837,11.51373,0,0,0,0,100,0),
(@PATH,28,-229.6927,-4514.13,11.22813,0,0,0,0,100,0),
(@PATH,29,-210.408,-4529.252,11.47813,0,0,0,0,100,0),
(@PATH,30,-190.4965,-4545.601,12.59623,0,0,0,0,100,0),
(@PATH,31,-196.6267,-4569.622,11.25989,0,0,0,0,100,0),
(@PATH,32,-214.5313,-4586.795,9.048365,0,0,0,0,100,0),
(@PATH,33,-246.2656,-4582.21,10.08424,0,0,0,0,100,0),
(@PATH,34,-285.033,-4582.703,11.21207,0,0,0,0,100,0),
(@PATH,35,-308.959,-4626.648,9.051313,0,0,0,0,100,0),
(@PATH,36,-340.3056,-4646.712,7.926479,0,0,0,0,100,0),
(@PATH,37,-359.8516,-4616.479,6.897068,0,0,0,0,100,0),
(@PATH,38,-360.1545,-4586.944,5.410193,0,0,0,0,100,0),
(@PATH,39,-353.3056,-4560.213,8.476274,0,0,0,0,100,0),
(@PATH,40,-348.4097,-4529.736,9.599404,0,0,0,0,100,0),
(@PATH,41,-363.026,-4516.372,8.693643,0,0,0,0,100,0),
(@PATH,42,-379.3438,-4514.667,7.707251,0,0,0,0,100,0),
(@PATH,43,-395.474,-4516.976,7.59934,0,0,0,0,100,0),
(@PATH,44,-406.3611,-4518.181,8.639224,0,0,0,0,100,0),
(@PATH,45,-432.5868,-4521.139,9.457339,0,0,0,0,100,0),
(@PATH,46,-444.3385,-4521.28,9.717922,0,0,0,0,100,0),
(@PATH,47,-458.0208,-4518.71,10.41739,0,0,0,0,100,0),
(@PATH,48,-475.3611,-4525.611,13.16492,0,0,0,0,100,0);

-- Pathing for Howin Kindfeather Entry: 11810 'TDB FORMAT' 
SET @NPC := 279442;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=254.3536,`position_y`=-2202.799,`position_z`=126.008 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,254.3536,-2202.799,126.008,0,0,0,0,100,0),
(@PATH,2,250.2853,-2203.817,125.1713,0,0,0,0,100,0),
(@PATH,3,249.2905,-2215.209,125.1713,0,0,0,0,100,0),
(@PATH,4,255.6829,-2213.673,125.1713,0,0,0,0,100,0),
(@PATH,5,256.5536,-2200.791,119.606,0,0,0,0,100,0),
(@PATH,6,256.2706,-2192.515,118.2796,0,0,0,0,100,0),
(@PATH,7,255.9236,-2176.508,118.4213,0,0,0,0,100,0),
(@PATH,8,257.3325,-2170.289,118.349,0,0,0,0,100,0),
(@PATH,9,272.5926,-2170.769,120.0333,0,0,0,0,100,0),
(@PATH,10,270.6538,-2163.285,119.9588,0,0,0,0,100,0),
(@PATH,11,262.2642,-2152.012,118.9759,0,0,0,0,100,0),
(@PATH,12,243.0674,-2139.406,118.1202,0,0,0,0,100,0),
(@PATH,13,231.1458,-2134.945,118.1703,0,0,0,0,100,0),
(@PATH,14,225.0213,-2123.609,117.2197,0,0,0,0,100,0),
(@PATH,15,234.0579,-2118.286,117.6016,0,0,0,0,100,0),
(@PATH,16,243.957,-2123.702,118.2894,0,0,0,0,100,0),
(@PATH,17,243.3891,-2137.016,118.2259,0,0,0,0,100,0),
(@PATH,18,260.9153,-2149.796,118.8484,0,0,0,0,100,0),
(@PATH,19,271.6249,-2161.664,119.8695,0,0,0,0,100,0),
(@PATH,20,270.0318,-2169.454,120.1404,0,0,0,0,100,0),
(@PATH,21,258.7433,-2171.492,118.327,0,0,0,0,100,0),
(@PATH,22,256.8065,-2184.236,118.2726,0,0,0,0,100,0),
(@PATH,23,256.8702,-2193.985,118.2862,0,0,0,0,100,0),
(@PATH,24,257.3294,-2206.738,122.5829,0,0,0,0,100,0),
(@PATH,25,253.1952,-2213.715,125.1713,0,0,0,0,100,0),
(@PATH,26,250.0129,-2211.885,125.1713,0,0,0,0,100,0),
(@PATH,27,251.2692,-2204.305,125.1713,0,0,0,0,100,0),
(@PATH,28,262.6602,-2202.89,131.5751,0,0,0,0,100,0),
(@PATH,29,267.0834,-2201.773,132.2766,0,0,0,0,100,0),
(@PATH,30,264.1442,-2194.333,132.2772,0,0,0,0,100,0),
(@PATH,31,256.1949,-2191.107,132.2842,0,0,0,0,100,0),
(@PATH,32,249.1365,-2194.511,132.2729,0,0,0,0,100,0),
(@PATH,33,245.9393,-2201.257,132.2761,0,0,0,0,100,0),
(@PATH,34,245.7223,-2205.74,132.29,0,0,0,0,100,0),
(@PATH,35,244.8587,-2206.531,132.2915,0,0,0,0,100,0),
(@PATH,36,244.8587,-2206.531,132.2915,3.124139,600000,0,0,100,0),
(@PATH,37,252.5223,-2213.902,132.2978,0,0,0,0,100,0),
(@PATH,38,261.8993,-2213.22,132.2952,0,0,0,0,100,0),
(@PATH,39,267.4277,-2206.431,132.2897,0,0,0,0,100,0),
(@PATH,40,267.0929,-2203.226,132.2767,0,0,0,0,100,0),
(@PATH,41,260.2747,-2202.865,129.9763,0,0,0,0,100,0),
(@PATH,42,254.3536,-2202.799,126.008,0,0,0,0,100,0);

-- Pathing for Vilebranch Hideskinner Entry: 2644 'TDB FORMAT' 
SET @NPC := 278578;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-617.422,`position_y`=-4087.11,`position_z`=238.3978 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-617.422,-4087.11,238.3978,0,0,0,0,100,0),
(@PATH,2,-615.159,-4073.36,238.3978,0,0,0,0,100,0),
(@PATH,3,-617.313,-4056.43,238.3155,0,0,0,0,100,0),
(@PATH,4,-626.395,-4051.12,238.3724,0,0,0,0,100,0),
(@PATH,5,-642.958,-4046.57,238.1797,0,0,0,0,100,0),
(@PATH,6,-652.856,-4045.04,238.4622,0,0,0,0,100,0),
(@PATH,7,-658.576,-4038.93,238.3214,0,0,0,0,100,0),
(@PATH,8,-664.817,-4029.27,238.3959,0,0,0,0,100,0),
(@PATH,9,-672.11,-4023.52,238.3713,0,0,0,0,100,0),
(@PATH,10,-674.927,-4015.85,238.1105,0,0,0,0,100,0),
(@PATH,11,-668.334,-4009.98,238.2734,0,0,0,0,100,0),
(@PATH,12,-660.323,-4012.63,238.2197,0,0,0,0,100,0),
(@PATH,13,-659.504,-4024.02,238.3959,0,0,0,0,100,0),
(@PATH,14,-651.26,-4040.32,238.3372,0,0,0,0,100,0),
(@PATH,15,-635.363,-4043.91,238.0872,0,0,0,0,100,0),
(@PATH,16,-618.33,-4049.29,238.3006,0,0,0,0,100,0),
(@PATH,17,-601.143,-4048.04,238.8006,0,0,0,0,100,0),
(@PATH,18,-584.3,-4046.97,238.6011,0,0,0,0,100,0),
(@PATH,19,-581.644,-4032.25,238.4761,0,0,0,0,100,0),
(@PATH,20,-584.3,-4046.97,238.6011,0,0,0,0,100,0),
(@PATH,21,-601.143,-4048.04,238.8006,0,0,0,0,100,0),
(@PATH,22,-618.33,-4049.29,238.3006,0,0,0,0,100,0),
(@PATH,23,-635.363,-4043.91,238.0872,0,0,0,0,100,0),
(@PATH,24,-651.26,-4040.32,238.3372,0,0,0,0,100,0),
(@PATH,25,-659.504,-4024.02,238.3959,0,0,0,0,100,0),
(@PATH,26,-660.323,-4012.63,238.2197,0,0,0,0,100,0),
(@PATH,27,-668.334,-4009.98,238.2734,0,0,0,0,100,0),
(@PATH,28,-674.927,-4015.85,238.1105,0,0,0,0,100,0),
(@PATH,29,-672.11,-4023.52,238.3713,0,0,0,0,100,0),
(@PATH,30,-664.817,-4029.27,238.3959,0,0,0,0,100,0),
(@PATH,31,-658.576,-4038.93,238.3214,0,0,0,0,100,0),
(@PATH,32,-652.856,-4045.04,238.4622,0,0,0,0,100,0),
(@PATH,33,-642.958,-4046.57,238.1797,0,0,0,0,100,0),
(@PATH,34,-626.395,-4051.12,238.3724,0,0,0,0,100,0),
(@PATH,35,-617.313,-4056.43,238.3155,0,0,0,0,100,0),
(@PATH,36,-615.159,-4073.36,238.3978,0,0,0,0,100,0),
(@PATH,37,-617.422,-4087.11,238.3978,0,0,0,0,100,0),
(@PATH,38,-620.325,-4096.9,238.7728,0,0,0,0,100,0),
(@PATH,39,-635.216,-4105.27,238.4761,0,0,0,0,100,0),
(@PATH,40,-637.369,-4113.54,238.648,0,0,0,0,100,0),
(@PATH,41,-629.997,-4123.85,238.4761,0,0,0,0,100,0),
(@PATH,42,-618.794,-4133.64,238.4761,0,0,0,0,100,0),
(@PATH,43,-609.788,-4143.3,238.4761,0,0,0,0,100,0),
(@PATH,44,-604.701,-4149.38,238.4761,0,0,0,0,100,0),
(@PATH,45,-597.861,-4152,238.4761,0,0,0,0,100,0),
(@PATH,46,-592.122,-4145.3,238.4761,0,0,0,0,100,0),
(@PATH,47,-587.98,-4137.89,238.4761,0,0,0,0,100,0),
(@PATH,48,-587.131,-4129.96,238.4761,0,0,0,0,100,0),
(@PATH,49,-590.743,-4120.82,238.4761,0,0,0,0,100,0),
(@PATH,50,-599.139,-4115.67,238.6011,0,0,0,0,100,0),
(@PATH,51,-603.904,-4101.75,238.6011,0,0,0,0,100,0),
(@PATH,52,-601.555,-4093.51,238.5228,0,0,0,0,100,0),
(@PATH,53,-599.059,-4080.79,238.4653,0,0,0,0,100,0),
(@PATH,54,-595.993,-4067.94,238.4653,0,0,0,0,100,0),
(@PATH,55,-592.398,-4054.39,238.6011,0,0,0,0,100,0),
(@PATH,56,-589.839,-4045.96,238.7261,0,0,0,0,100,0),
(@PATH,57,-582.737,-4032.17,238.4761,0,0,0,0,100,0),
(@PATH,58,-589.839,-4045.96,238.7261,0,0,0,0,100,0),
(@PATH,59,-592.398,-4054.39,238.6011,0,0,0,0,100,0),
(@PATH,60,-595.993,-4067.94,238.4653,0,0,0,0,100,0),
(@PATH,61,-599.059,-4080.79,238.4653,0,0,0,0,100,0),
(@PATH,62,-601.555,-4093.51,238.5228,0,0,0,0,100,0),
(@PATH,63,-603.904,-4101.75,238.6011,0,0,0,0,100,0),
(@PATH,64,-599.139,-4115.67,238.6011,0,0,0,0,100,0),
(@PATH,65,-590.743,-4120.82,238.4761,0,0,0,0,100,0),
(@PATH,66,-587.131,-4129.96,238.4761,0,0,0,0,100,0),
(@PATH,67,-587.98,-4137.89,238.4761,0,0,0,0,100,0),
(@PATH,68,-592.122,-4145.3,238.4761,0,0,0,0,100,0),
(@PATH,69,-597.861,-4152,238.4761,0,0,0,0,100,0),
(@PATH,70,-604.701,-4149.38,238.4761,0,0,0,0,100,0),
(@PATH,71,-609.788,-4143.3,238.4761,0,0,0,0,100,0),
(@PATH,72,-618.794,-4133.64,238.4761,0,0,0,0,100,0),
(@PATH,73,-629.997,-4123.85,238.4761,0,0,0,0,100,0),
(@PATH,74,-637.369,-4113.54,238.648,0,0,0,0,100,0),
(@PATH,75,-635.216,-4105.27,238.4761,0,0,0,0,100,0),
(@PATH,76,-620.325,-4096.9,238.7728,0,0,0,0,100,0);

-- Pathing for Vilebranch Shadow Hunter Entry: 2645 'TDB FORMAT' 
SET @NPC := 278656;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-617.594,`position_y`=-4001.79,`position_z`=238.3078 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-617.594,-4001.79,238.3078,0,0,0,0,100,0),
(@PATH,2,-619.258,-4027.49,238.0563,0,0,0,0,100,0),
(@PATH,3,-620.661,-4046.07,237.9749,0,0,0,0,100,0),
(@PATH,4,-615.425,-4062.82,238.1756,0,0,0,0,100,0),
(@PATH,5,-616.057,-4074.54,238.3978,0,0,0,0,100,0),
(@PATH,6,-602.754,-4085.15,238.3978,0,0,0,0,100,0),
(@PATH,7,-585.313,-4084.97,238.4653,0,0,0,0,100,0),
(@PATH,8,-569.511,-4086.22,233.7231,0,0,0,0,100,0),
(@PATH,9,-556.8951,-4085.668,223.9337,0,0,0,0,100,0),
(@PATH,10,-545.379,-4085.4,215.8902,0,0,0,0,100,0),
(@PATH,11,-536.748,-4089.53,215.8902,0,0,0,0,100,0),
(@PATH,12,-540.633,-4101.85,216.3315,0,0,0,0,100,0),
(@PATH,13,-544.273,-4114.94,216.2829,0,0,0,0,100,0),
(@PATH,14,-540.346,-4129.46,215.9274,0,0,0,0,100,0),
(@PATH,15,-532.33,-4139.31,215.9487,0,0,0,0,100,0),
(@PATH,16,-520.546,-4137,216.062,0,0,0,0,100,0),
(@PATH,17,-509.073,-4141.73,216.2883,0,0,0,0,100,0),
(@PATH,18,-520.546,-4137,216.062,0,0,0,0,100,0),
(@PATH,19,-532.33,-4139.31,215.9487,0,0,0,0,100,0),
(@PATH,20,-540.346,-4129.46,215.9274,0,0,0,0,100,0),
(@PATH,21,-544.273,-4114.94,216.2829,0,0,0,0,100,0),
(@PATH,22,-540.633,-4101.85,216.3315,0,0,0,0,100,0),
(@PATH,23,-536.748,-4089.53,215.8902,0,0,0,0,100,0),
(@PATH,24,-545.379,-4085.4,215.8902,0,0,0,0,100,0),
(@PATH,25,-556.8951,-4085.668,223.8895,0,0,0,0,100,0),
(@PATH,26,-569.511,-4086.22,233.7231,0,0,0,0,100,0),
(@PATH,27,-585.313,-4084.97,238.4653,0,0,0,0,100,0),
(@PATH,28,-602.754,-4085.15,238.3978,0,0,0,0,100,0),
(@PATH,29,-616.057,-4074.54,238.3978,0,0,0,0,100,0),
(@PATH,30,-615.425,-4062.82,238.1756,0,0,0,0,100,0),
(@PATH,31,-620.661,-4046.07,237.9749,0,0,0,0,100,0),
(@PATH,32,-619.258,-4027.49,238.0563,0,0,0,0,100,0);

-- Pathing for Vilebranch Headhunter Entry: 2641 'TDB FORMAT' 
SET @NPC := 278633;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-284.571,`position_y`=-4085.302,`position_z`=152.14 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-284.571,-4085.302,152.14,0,0,0,0,100,0),
(@PATH,2,-295.6881,-4087.868,152.4837,0,0,0,0,100,0),
(@PATH,3,-304.2423,-4087.691,152.2971,0,0,0,0,100,0),
(@PATH,4,-314.2382,-4088.344,152.2971,0,0,0,0,100,0),
(@PATH,5,-322.7508,-4087.331,152.5894,0,0,0,0,100,0),
(@PATH,6,-331.1907,-4082.108,152.5066,0,0,0,0,100,0),
(@PATH,7,-338.1729,-4086.666,153.3141,0,0,0,0,100,0),
(@PATH,8,-342.3202,-4093.814,152.2581,0,0,0,0,100,0),
(@PATH,9,-338.1729,-4086.666,153.3141,0,0,0,0,100,0),
(@PATH,10,-331.1907,-4082.108,152.5066,0,0,0,0,100,0),
(@PATH,11,-322.7508,-4087.331,152.5894,0,0,0,0,100,0),
(@PATH,12,-314.2382,-4088.344,152.2971,0,0,0,0,100,0),
(@PATH,13,-304.2423,-4087.691,152.2971,0,0,0,0,100,0),
(@PATH,14,-295.6881,-4087.868,152.4837,0,0,0,0,100,0);

-- Pathing for Vilebranch Hideskinner Entry: 2644 'TDB FORMAT' 
SET @NPC := 278898;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-343.723,`position_y`=-3778.68,`position_z`=238.563 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-343.723,-3778.68,238.563,0,0,0,0,100,0),
(@PATH,2,-322.46,-3789.93,238.4762,0,0,0,0,100,0),
(@PATH,3,-307.294,-3803.71,238.3216,0,0,0,0,100,0),
(@PATH,4,-287.549,-3801.64,238.3097,0,0,0,0,100,0),
(@PATH,5,-256.282,-3800.55,238.366,0,0,0,0,100,0),
(@PATH,6,-243.44,-3793.04,237.9253,0,0,0,0,100,0),
(@PATH,7,-235.215,-3810.61,238.3186,0,0,0,0,100,0),
(@PATH,8,-232.303,-3826.62,238.116,0,0,0,0,100,0),
(@PATH,9,-237.351,-3847.93,238.3399,0,0,0,0,100,0),
(@PATH,10,-243.772,-3855.53,238.4649,0,0,0,0,100,0),
(@PATH,11,-270.024,-3856.79,238.4717,0,0,0,0,100,0),
(@PATH,12,-300.305,-3856.29,238.4274,0,0,0,0,100,0),
(@PATH,13,-305.67,-3848.49,238.3676,0,0,0,0,100,0),
(@PATH,14,-300.305,-3856.29,238.4274,0,0,0,0,100,0),
(@PATH,15,-270.024,-3856.79,238.4717,0,0,0,0,100,0),
(@PATH,16,-243.772,-3855.53,238.4649,0,0,0,0,100,0),
(@PATH,17,-237.351,-3847.93,238.3399,0,0,0,0,100,0),
(@PATH,18,-232.303,-3826.62,238.116,0,0,0,0,100,0),
(@PATH,19,-235.215,-3810.61,238.3186,0,0,0,0,100,0),
(@PATH,20,-243.44,-3793.04,237.9253,0,0,0,0,100,0),
(@PATH,21,-256.282,-3800.55,238.366,0,0,0,0,100,0),
(@PATH,22,-287.549,-3801.64,238.3097,0,0,0,0,100,0),
(@PATH,23,-307.294,-3803.71,238.3216,0,0,0,0,100,0),
(@PATH,24,-322.46,-3789.93,238.4762,0,0,0,0,100,0);

-- Pathing for Vilebranch Hideskinner Entry: 2644 'TDB FORMAT'
SET @NPC := 278889;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-317.657,`position_y`=-3877.56,`position_z`=217.3991 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-317.657,-3877.56,217.3991,0,0,0,0,100,0),
(@PATH,2,-302.216,-3884.26,216.4836,0,0,0,0,100,0),
(@PATH,3,-274.361,-3882.77,216.3608,0,0,0,0,100,0),
(@PATH,4,-239.115,-3883.23,216.2421,0,0,0,0,100,0),
(@PATH,5,-226.044,-3880.7,215.9858,0,0,0,0,100,0),
(@PATH,6,-215.985,-3886.69,215.9858,0,0,0,0,100,0),
(@PATH,7,-195.26,-3882.41,215.9858,0,0,0,0,100,0),
(@PATH,8,-180.624,-3884.5,215.9858,0,0,0,0,100,0),
(@PATH,9,-169.008,-3889.67,215.9858,0,0,0,0,100,0),
(@PATH,10,-180.624,-3884.5,215.9858,0,0,0,0,100,0),
(@PATH,11,-195.26,-3882.41,215.9858,0,0,0,0,100,0),
(@PATH,12,-215.985,-3886.69,215.9858,0,0,0,0,100,0),
(@PATH,13,-226.044,-3880.7,215.9858,0,0,0,0,100,0),
(@PATH,14,-239.115,-3883.23,216.2421,0,0,0,0,100,0),
(@PATH,15,-274.361,-3882.77,216.3608,0,0,0,0,100,0),
(@PATH,16,-302.216,-3884.26,216.4836,0,0,0,0,100,0);

-- Pathing for Vilebranch Hideskinner Entry: 2644 'TDB FORMAT'
SET @NPC := 278763;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-316.637,`position_y`=-3928.29,`position_z`=215.9858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-316.637,-3928.29,215.9858,0,0,0,0,100,0),
(@PATH,2,-317.55,-3938.47,216.2606,0,0,0,0,100,0),
(@PATH,3,-306.366,-3940.54,215.9396,0,0,0,0,100,0),
(@PATH,4,-292.395,-3934.19,215.9664,0,0,0,0,100,0),
(@PATH,5,-282.17,-3933.6,215.9664,0,0,0,0,100,0),
(@PATH,6,-264.585,-3937.27,215.9396,0,0,0,0,100,0),
(@PATH,7,-246.173,-3928.89,215.9858,0,0,0,0,100,0),
(@PATH,8,-250.33,-3914.34,216.4858,0,0,0,0,100,0),
(@PATH,9,-246.023,-3896.66,215.9858,0,0,0,0,100,0),
(@PATH,10,-250.33,-3914.34,216.4858,0,0,0,0,100,0),
(@PATH,11,-246.173,-3928.89,215.9858,0,0,0,0,100,0),
(@PATH,12,-264.585,-3937.27,215.9396,0,0,0,0,100,0),
(@PATH,13,-282.17,-3933.6,215.9664,0,0,0,0,100,0),
(@PATH,14,-292.395,-3934.19,215.9664,0,0,0,0,100,0),
(@PATH,15,-306.366,-3940.54,215.9396,0,0,0,0,100,0),
(@PATH,16,-317.55,-3938.47,216.2606,0,0,0,0,100,0);

-- Pathing for Vilebranch Hideskinner Entry: 2644 'TDB FORMAT' 
SET @NPC := 278884;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-362.172,`position_y`=-3779.62,`position_z`=238.7829 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-362.172,-3779.62,238.7829,0,0,0,0,100,0),
(@PATH,2,-368.383,-3786.73,237.9444,0,0,0,0,100,0),
(@PATH,3,-390.767,-3786.42,238.3961,0,0,0,0,100,0),
(@PATH,4,-407.419,-3777.61,238.4286,0,0,0,0,100,0),
(@PATH,5,-419.93,-3783.76,238.6806,0,0,0,0,100,0),
(@PATH,6,-423.123,-3796.87,238.1647,0,0,0,0,100,0),
(@PATH,7,-424.266,-3834.36,238.1473,0,0,0,0,100,0),
(@PATH,8,-411.085,-3850.56,238.3973,0,0,0,0,100,0),
(@PATH,9,-397.149,-3846.89,238.4762,0,0,0,0,100,0),
(@PATH,10,-365.926,-3843.47,238.4678,0,0,0,0,100,0),
(@PATH,11,-362.966,-3853.86,238.4678,0,0,0,0,100,0),
(@PATH,12,-365.926,-3843.47,238.4678,0,0,0,0,100,0),
(@PATH,13,-397.149,-3846.89,238.4762,0,0,0,0,100,0),
(@PATH,14,-411.085,-3850.56,238.3973,0,0,0,0,100,0),
(@PATH,15,-424.266,-3834.36,238.1473,0,0,0,0,100,0),
(@PATH,16,-423.123,-3796.87,238.1647,0,0,0,0,100,0),
(@PATH,17,-419.93,-3783.76,238.6806,0,0,0,0,100,0),
(@PATH,18,-407.419,-3777.61,238.4286,0,0,0,0,100,0),
(@PATH,19,-390.767,-3786.42,238.3961,0,0,0,0,100,0),
(@PATH,20,-368.383,-3786.73,237.9444,0,0,0,0,100,0);

-- Pathing for Vilebranch Shadow Hunter Entry: 2645 'TDB FORMAT'
SET @NPC := 278810;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-162.014,`position_y`=-3792.81,`position_z`=238.2969 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-162.014,-3792.81,238.2969,0,0,0,0,100,0),
(@PATH,2,-166.069,-3800.7,238.4127,0,0,0,0,100,0),
(@PATH,3,-161.612,-3808.13,238.4127,0,0,0,0,100,0),
(@PATH,4,-159.916,-3828.66,238.4127,0,0,0,0,100,0),
(@PATH,5,-161.671,-3853.64,238.4881,0,0,0,0,100,0),
(@PATH,6,-171.168,-3857.69,238.3658,0,0,0,0,100,0),
(@PATH,7,-200.833,-3857.43,238.3714,0,0,0,0,100,0),
(@PATH,8,-227.027,-3857.7,238.3578,0,0,0,0,100,0),
(@PATH,9,-235.117,-3844.45,238.1114,0,0,0,0,100,0),
(@PATH,10,-234.359,-3817.11,238.0608,0,0,0,0,100,0),
(@PATH,11,-238.431,-3800.08,238.01,0,0,0,0,100,0),
(@PATH,12,-247.612,-3784.92,238.4253,0,0,0,0,100,0),
(@PATH,13,-257.987,-3777.18,238.4253,0,0,0,0,100,0),
(@PATH,14,-269.761,-3774.31,238.4934,0,0,0,0,100,0),
(@PATH,15,-257.987,-3777.18,238.4253,0,0,0,0,100,0),
(@PATH,16,-247.612,-3784.92,238.4253,0,0,0,0,100,0),
(@PATH,17,-238.431,-3800.08,238.01,0,0,0,0,100,0),
(@PATH,18,-234.359,-3817.11,238.0608,0,0,0,0,100,0),
(@PATH,19,-235.117,-3844.45,238.1114,0,0,0,0,100,0),
(@PATH,20,-227.027,-3857.7,238.3578,0,0,0,0,100,0),
(@PATH,21,-200.833,-3857.43,238.3714,0,0,0,0,100,0),
(@PATH,22,-171.168,-3857.69,238.3658,0,0,0,0,100,0),
(@PATH,23,-161.671,-3853.64,238.4881,0,0,0,0,100,0),
(@PATH,24,-159.916,-3828.66,238.4127,0,0,0,0,100,0),
(@PATH,25,-161.612,-3808.13,238.4127,0,0,0,0,100,0),
(@PATH,26,-166.069,-3800.7,238.4127,0,0,0,0,100,0);

-- Pathing for Vilebranch Shadow Hunter Entry: 2645 'TDB FORMAT'
SET @NPC := 278881;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-335.416,`position_y`=-3837.5,`position_z`=238.4678 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-335.416,-3837.5,238.4678,0,0,0,0,100,0),
(@PATH,2,-335.324,-3854.04,237.9438,0,0,0,0,100,0),
(@PATH,3,-334.964,-3868.8,226.3614,0,0,0,0,100,0),
(@PATH,4,-334.8965,-3882.813,215.9858,0,0,0,0,100,0),
(@PATH,5,-341.121,-3896.15,215.9858,0,0,0,0,100,0),
(@PATH,6,-354.607,-3893.84,216.3608,0,0,0,0,100,0),
(@PATH,7,-382.153,-3894.92,216.1579,0,0,0,0,100,0),
(@PATH,8,-391.158,-3894.9,215.9609,0,0,0,0,100,0),
(@PATH,9,-401.636,-3888.65,216.1865,0,0,0,0,100,0),
(@PATH,10,-412.853,-3886.42,216.0729,0,0,0,0,100,0),
(@PATH,11,-427.805,-3888.21,215.9858,0,0,0,0,100,0),
(@PATH,12,-412.853,-3886.42,216.0729,0,0,0,0,100,0),
(@PATH,13,-401.636,-3888.65,216.1865,0,0,0,0,100,0),
(@PATH,14,-391.158,-3894.9,215.9609,0,0,0,0,100,0),
(@PATH,15,-382.153,-3894.92,216.1579,0,0,0,0,100,0),
(@PATH,16,-354.607,-3893.84,216.3608,0,0,0,0,100,0),
(@PATH,17,-341.121,-3896.15,215.9858,0,0,0,0,100,0),
(@PATH,18,-334.982,-3883.49,215.9858,0,0,0,0,100,0),
(@PATH,19,-334.964,-3868.8,226.3614,0,0,0,0,100,0),
(@PATH,20,-335.324,-3854.04,237.9438,0,0,0,0,100,0);

-- Pathing for Vilebranch Warrior Entry: 4465 'TDB FORMAT' ## Spawn Missing ##
SET @NPC := 278811;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-300.8814,`position_y`=-4190.363,`position_z`=136.5622 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-300.8814,-4190.363,136.5622,0,0,0,0,100,0),
(@PATH,2,-299.2402,-4199.432,136.8216,0,0,0,0,100,0),
(@PATH,3,-294.703,-4206.721,136.5972,0,0,0,0,100,0),
(@PATH,4,-284.916,-4203.682,136.7266,0,0,0,0,100,0),
(@PATH,5,-281.4611,-4198.692,136.5716,0,0,0,0,100,0),
(@PATH,6,-278.4128,-4187.48,136.5716,0,0,0,0,100,0),
(@PATH,7,-279.7527,-4179.343,136.4959,0,0,0,0,100,0),
(@PATH,8,-282.9599,-4172.346,136.5655,0,0,0,0,100,0),
(@PATH,9,-291.1088,-4159.861,136.5396,0,0,0,0,100,0),
(@PATH,10,-296.5112,-4150.362,136.5396,0,0,0,0,100,0),
(@PATH,11,-297.4698,-4136.667,136.5396,0,0,0,0,100,0),
(@PATH,12,-296.116,-4127.808,136.4748,0,0,0,0,100,0),
(@PATH,13,-287.9145,-4123.469,136.6125,0,0,0,0,100,0),
(@PATH,14,-276.8211,-4123.947,137.0688,0,0,0,0,100,0),
(@PATH,15,-268.0964,-4124.016,135.5142,0,0,0,0,100,0),
(@PATH,16,-259.8373,-4124.032,128.8289,0,0,0,0,100,0),
(@PATH,17,-253.119,-4123.896,124.5996,0,0,0,0,100,0),
(@PATH,18,-245.0412,-4124.756,119.3458,0,0,0,0,100,0),
(@PATH,19,-231.2207,-4124.845,117.8142,0,0,0,0,100,0),
(@PATH,20,-213.4383,-4132.925,118.0337,0,6000,0,0,100,0),
(@PATH,21,-231.2207,-4124.845,117.8142,0,0,0,0,100,0),
(@PATH,22,-245.0412,-4124.756,119.3458,0,0,0,0,100,0),
(@PATH,23,-253.119,-4123.896,124.5996,0,0,0,0,100,0),
(@PATH,24,-259.8373,-4124.032,128.8289,0,0,0,0,100,0),
(@PATH,25,-268.0964,-4124.016,135.5142,0,0,0,0,100,0),
(@PATH,26,-276.8211,-4123.947,137.0688,0,0,0,0,100,0),
(@PATH,27,-287.9145,-4123.469,136.6125,0,0,0,0,100,0),
(@PATH,28,-296.116,-4127.808,136.4748,0,0,0,0,100,0),
(@PATH,29,-297.4698,-4136.667,136.5396,0,0,0,0,100,0),
(@PATH,30,-296.5112,-4150.362,136.5396,0,0,0,0,100,0),
(@PATH,31,-291.1088,-4159.861,136.5396,0,0,0,0,100,0),
(@PATH,32,-282.9599,-4172.346,136.5655,0,0,0,0,100,0),
(@PATH,33,-279.7527,-4179.343,136.4959,0,0,0,0,100,0),
(@PATH,34,-278.4128,-4187.48,136.5716,0,0,0,0,100,0),
(@PATH,35,-281.4611,-4198.692,136.5716,0,0,0,0,100,0),
(@PATH,36,-284.916,-4203.682,136.7266,0,0,0,0,100,0),
(@PATH,37,-294.703,-4206.721,136.5972,0,0,0,0,100,0),
(@PATH,38,-299.2402,-4199.432,136.8216,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 278561;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-344.6414,`position_y`=-4206.899,`position_z`=152.1899 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-344.6414,-4206.899,152.1899,0,0,0,0,100,0),
(@PATH,2,-332.2438,-4159.961,152.3122,0,0,0,0,100,0),
(@PATH,3,-344.8486,-4207.169,152.1899,0,20000,0,0,100,0),
(@PATH,4,-341.8112,-4169.34,152.1125,0,10000,0,0,100,0),
(@PATH,5,-343.0592,-4185.272,152.0674,0,0,0,0,100,0),
(@PATH,6,-343.1734,-4200.058,152.6204,0,0,0,0,100,0),
(@PATH,7,-345.5082,-4209.125,152.0649,0,0,0,0,100,0),
(@PATH,8,-347.6425,-4196.642,152.3279,0,0,0,0,100,0),
(@PATH,9,-344.9586,-4183.099,152.0781,0,0,0,0,100,0),
(@PATH,10,-347.457,-4163.811,152.1256,0,0,0,0,100,0),
(@PATH,11,-356.2252,-4154.307,154.0861,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 278643;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-377.1866,`position_y`=-4184.02,`position_z`=174.0451 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-377.1866,-4184.02,174.0451,0,0,0,0,100,0),
(@PATH,2,-391.189,-4145.161,174.0482,0,0,0,0,100,0),
(@PATH,3,-385.9364,-4136.036,174.043,0,0,0,0,100,0),
(@PATH,4,-387.2604,-4121.801,174.1548,0,0,0,0,100,0),
(@PATH,5,-382.0274,-4117.315,174.4048,0,0,0,0,100,0),
(@PATH,6,-382.2926,-4112.674,174.4048,0,0,0,0,100,0),
(@PATH,7,-387.0661,-4112.844,174.0298,0,0,0,0,100,0),
(@PATH,8,-392.4414,-4118.366,174.0298,0,0,0,0,100,0),
(@PATH,9,-401.6256,-4124.279,173.7662,0,0,0,0,100,0),
(@PATH,10,-410.1769,-4117.294,174.1412,0,0,0,0,100,0),
(@PATH,11,-418.0531,-4101.264,174.3553,0,0,0,0,100,0),
(@PATH,12,-413.46,-4105.703,174.2462,0,0,0,0,100,0),
(@PATH,13,-414.6765,-4123.939,174.1412,0,0,0,0,100,0),
(@PATH,14,-410.0478,-4140.599,174.2085,0,0,0,0,100,0),
(@PATH,15,-403.6724,-4154.777,174.1489,0,0,0,0,100,0),
(@PATH,16,-397.8997,-4165.716,174.168,0,0,0,0,100,0),
(@PATH,17,-403.1367,-4174.234,173.9201,0,0,0,0,100,0),
(@PATH,18,-398.115,-4183.742,174.1899,0,0,0,0,100,0),
(@PATH,19,-386.8537,-4191.472,174.1899,0,0,0,0,100,0),
(@PATH,20,-380.9002,-4188.636,174.0649,0,0,0,0,100,0),
(@PATH,21,-375.5237,-4184.854,174.0646,0,0,0,0,100,0),
(@PATH,22,-377.2255,-4184.558,173.9807,0,20000,0,0,100,0),
(@PATH,23,-392.2314,-4188.376,174.1899,0,0,0,0,100,0),
(@PATH,24,-399.872,-4184.01,174.1899,0,0,0,0,100,0),
(@PATH,25,-400.0875,-4167.04,174.0451,0,0,0,0,100,0),
(@PATH,26,-401.2863,-4159.944,174.1489,0,0,0,0,100,0),
(@PATH,27,-413.8907,-4146.77,174.6489,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 278624;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-304.0234,`position_y`=-4211.959,`position_z`=136.61 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-304.0234,-4211.959,136.61,0,20000,0,0,100,0),
(@PATH,2,-292.2878,-4158.361,136.5396,0,0,0,0,100,0),
(@PATH,3,-298.9451,-4127.781,136.5146,0,0,0,0,100,0),
(@PATH,4,-306.1327,-4119.889,137.2355,0,0,0,0,100,0),
(@PATH,5,-308.5364,-4114.935,139.06,0,0,0,0,100,0),
(@PATH,6,-310.9892,-4125.454,137.32,0,0,0,0,100,0),
(@PATH,7,-296.8998,-4159.29,136.6646,0,0,0,0,100,0),
(@PATH,8,-296.0485,-4134.66,136.3862,0,0,0,0,100,0),
(@PATH,9,-298.9451,-4127.781,136.5146,0,0,0,0,100,0),
(@PATH,10,-306.1327,-4119.889,137.2355,0,0,0,0,100,0),
(@PATH,11,-308.5364,-4114.935,139.06,0,0,0,0,100,0),
(@PATH,12,-310.9892,-4125.454,137.32,0,0,0,0,100,0),
(@PATH,13,-308.9563,-4132.816,136.8122,0,0,0,0,100,0),
(@PATH,14,-296.7757,-4143.554,136.5396,0,0,0,0,100,0),
(@PATH,15,-303.8795,-4153.335,137.2751,0,0,0,0,100,0),
(@PATH,16,-312.6448,-4157.02,137.9267,0,0,0,0,100,0),
(@PATH,17,-292.2878,-4158.361,136.5396,0,0,0,0,100,0),
(@PATH,18,-285.7379,-4169.449,136.7181,0,0,0,0,100,0),
(@PATH,19,-281.2484,-4185.854,136.4466,0,0,0,0,100,0),
(@PATH,20,-293.4341,-4195.34,136.45,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 278703;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-399.179,`position_y`=-4069.833,`position_z`=174.1493 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-399.179,-4069.833,174.1493,0,0,0,0,100,0),
(@PATH,2,-396.3883,-4077.325,174.2743,0,0,0,0,100,0),
(@PATH,3,-383.4161,-4085.289,174.5715,0,0,0,0,100,0),
(@PATH,4,-375.5111,-4080.216,174.4618,0,0,0,0,100,0),
(@PATH,5,-372.7372,-4065.948,174.444,0,0,0,0,100,0),
(@PATH,6,-369.3305,-4059.956,174.2011,0,0,0,0,100,0),
(@PATH,7,-361.9381,-4048.935,174.1945,0,0,0,0,100,0),
(@PATH,8,-351.8234,-4046.653,174.1342,0,0,0,0,100,0),
(@PATH,9,-350.3942,-4036.458,174.1342,0,0,0,0,100,0),
(@PATH,10,-335.2397,-4022.8,174.1978,0,0,0,0,100,0),
(@PATH,11,-308.9385,-4011.775,176.8242,0,1000,0,0,100,0),
(@PATH,12,-310.0528,-4011.624,176.7268,0,1000,0,0,100,0),
(@PATH,13,-309.2264,-4011.57,176.8638,0,7000,0,0,100,0),
(@PATH,14,-307.4339,-4011.602,176.977,0,1000,0,0,100,0),
(@PATH,15,-307.2738,-4011.522,176.9863,0,1000,0,0,100,0),
(@PATH,16,-309.9507,-4011.413,176.8266,0,1000,0,0,100,0),
(@PATH,17,-313.5483,-4022.663,174.1362,0,10000,0,0,100,0),
(@PATH,18,-318.0231,-4035.041,174.2404,0,0,0,0,100,0),
(@PATH,19,-325.7678,-4035.349,174.3703,0,0,0,0,100,0),
(@PATH,20,-328.2054,-4028.948,174.1362,0,0,0,0,100,0),
(@PATH,21,-332.2809,-4024.947,174.1362,0,0,0,0,100,0),
(@PATH,22,-345.0593,-4026.547,174.4193,0,0,0,0,100,0),
(@PATH,23,-349.4971,-4036.292,174.1342,0,0,0,0,100,0),
(@PATH,24,-356.6894,-4047.306,174.1342,0,0,0,0,100,0),
(@PATH,25,-307.291,-4011.459,177.0112,0,0,0,0,100,0),
(@PATH,26,-357.4291,-4065.584,174.2592,0,0,0,0,100,0),
(@PATH,27,-365.625,-4069.791,174.2581,0,0,0,0,100,0),
(@PATH,28,-374.9184,-4072.842,174.3993,0,0,0,0,100,0),
(@PATH,29,-379.9338,-4067.276,174.5243,0,0,0,0,100,0),
(@PATH,30,-389.961,-4066.648,174.194,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 278705;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-228.9834,`position_y`=-4025.023,`position_z`=173.9317 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-228.9834,-4025.023,173.9317,0,0,0,0,100,0),
(@PATH,2,-234.3542,-4028.461,174.4158,0,0,0,0,100,0),
(@PATH,3,-227.9981,-4048.856,173.748,0,0,0,0,100,0),
(@PATH,4,-234.079,-4049.106,174.3304,0,0,0,0,100,0),
(@PATH,5,-247.4214,-4044.918,173.7503,0,0,0,0,100,0),
(@PATH,6,-254.7332,-4049.767,174.1307,0,0,0,0,100,0),
(@PATH,7,-206.662,-4021.473,178.6202,0,10000,0,0,100,0),
(@PATH,8,-262.7414,-4035.608,174.1253,0,0,0,0,100,0),
(@PATH,9,-272.1259,-4036.031,174.3154,0,0,0,0,100,0),
(@PATH,10,-279.5847,-4044.235,174.925,0,0,0,0,100,0),
(@PATH,11,-206.9664,-4021.382,178.4127,0,10000,0,0,100,0),
(@PATH,12,-263.0231,-4034.824,174.1253,0,0,0,0,100,0),
(@PATH,13,-246.1163,-4040.609,173.8148,0,0,0,0,100,0),
(@PATH,14,-228.2806,-4036.684,174.1201,0,0,0,0,100,0),
(@PATH,15,-218.4314,-4026.098,174.3067,0,0,0,0,100,0),
(@PATH,16,-212.228,-4025.059,175.7166,0,0,0,0,100,0),
(@PATH,17,-206.2172,-4019.938,179.0215,0,0,0,0,100,0);

-- Pathing for Spawn of Shadra Entry: 42879 'TDB FORMAT' 
SET @NPC := @CGUID+53;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-570.9514,`position_y`=-3824.368,`position_z`=235.838 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-570.9514,-3824.368,235.838,0,0,0,0,100,0),
(@PATH,2,-577.8333,-3810.632,235.3809,0,0,0,0,100,0),
(@PATH,3,-588.4496,-3796.752,235.2166,0,0,0,0,100,0),
(@PATH,4,-605.0972,-3785.509,239.6498,0,0,0,0,100,0),
(@PATH,5,-607.6285,-3774.134,238.9769,0,0,0,0,100,0),
(@PATH,6,-609.356,-3755.959,231.8343,0,0,0,0,100,0),
(@PATH,7,-617.8542,-3742.535,232.3098,0,0,0,0,100,0),
(@PATH,8,-629.9028,-3733.625,233.5851,0,0,0,0,100,0),
(@PATH,9,-642.8403,-3731.372,235.637,0,0,0,0,100,0),
(@PATH,10,-654.6371,-3732.884,237.7056,0,0,0,0,100,0),
(@PATH,11,-642.8403,-3731.372,235.637,0,0,0,0,100,0),
(@PATH,12,-629.9028,-3733.625,233.5851,0,0,0,0,100,0),
(@PATH,13,-617.8542,-3742.535,232.3098,0,0,0,0,100,0),
(@PATH,14,-609.356,-3755.959,231.8343,0,0,0,0,100,0),
(@PATH,15,-607.6285,-3774.134,238.9769,0,0,0,0,100,0),
(@PATH,16,-605.0972,-3785.509,239.6498,0,0,0,0,100,0),
(@PATH,17,-588.4496,-3796.752,235.2166,0,0,0,0,100,0),
(@PATH,18,-577.8333,-3810.632,235.3809,0,0,0,0,100,0);

-- Pathing for Spawn of Shadra Entry: 42879 'TDB FORMAT' 
SET @NPC := @CGUID+55;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-625.0486,`position_y`=-3801.931,`position_z`=236.4647 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-625.0486,-3801.931,236.4647,0,0,0,0,100,0),
(@PATH,2,-635.8524,-3813.695,231.5473,0,0,0,0,100,0),
(@PATH,3,-649.4479,-3815.259,228.2566,0,0,0,0,100,0),
(@PATH,4,-661.0521,-3807.406,224.6921,0,0,0,0,100,0),
(@PATH,5,-673.25,-3789.974,222.6512,0,0,0,0,100,0),
(@PATH,6,-678.0799,-3772.238,220.8501,0,0,0,0,100,0),
(@PATH,7,-678.5868,-3751.087,219.3376,0,0,0,0,100,0),
(@PATH,8,-680.4653,-3726.747,219.4233,0,0,0,0,100,0),
(@PATH,9,-678.7761,-3707.722,223.9915,0,0,0,0,100,0),
(@PATH,10,-680.4653,-3726.747,219.4233,0,0,0,0,100,0),
(@PATH,11,-678.5868,-3751.087,219.3376,0,0,0,0,100,0),
(@PATH,12,-678.0799,-3772.238,220.8501,0,0,0,0,100,0),
(@PATH,13,-673.25,-3789.974,222.6512,0,0,0,0,100,0),
(@PATH,14,-661.0947,-3807.345,224.6927,0,0,0,0,100,0),
(@PATH,15,-649.4479,-3815.259,228.2566,0,0,0,0,100,0),
(@PATH,16,-635.8945,-3813.699,231.5298,0,0,0,0,100,0);

-- Pathing for Spawn of Shadra Entry: 42879 'TDB FORMAT'
SET @NPC := @CGUID+62;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-687.1893,`position_y`=-3778.307,`position_z`=228.8614 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-687.1893,-3778.307,228.8614,0,0,0,0,100,0),
(@PATH,2,-700.3137,-3778.899,226.8267,0,0,0,0,100,0),
(@PATH,3,-715.7847,-3777.368,227.8993,0,0,0,0,100,0),
(@PATH,4,-734.425,-3776.88,230.4668,0,0,0,0,100,0),
(@PATH,5,-737.7118,-3767.247,232.284,0,0,0,0,100,0),
(@PATH,6,-732.941,-3756.951,234.0033,0,0,0,0,100,0),
(@PATH,7,-721.9601,-3748.582,235.3382,0,0,0,0,100,0),
(@PATH,8,-715.2934,-3732.658,238.1331,0,0,0,0,100,0),
(@PATH,9,-712.2969,-3719.472,237.7837,0,0,0,0,100,0),
(@PATH,10,-708.941,-3695.559,233.6271,0,0,0,0,100,0),
(@PATH,11,-701.3143,-3680.184,233.0555,0,0,0,0,100,0),
(@PATH,12,-708.941,-3695.559,233.6271,0,0,0,0,100,0),
(@PATH,13,-712.2969,-3719.472,237.7837,0,0,0,0,100,0),
(@PATH,14,-715.2934,-3732.658,238.1331,0,0,0,0,100,0),
(@PATH,15,-721.9601,-3748.582,235.3382,0,0,0,0,100,0),
(@PATH,16,-732.941,-3756.951,234.0033,0,0,0,0,100,0),
(@PATH,17,-737.7118,-3767.247,232.284,0,0,0,0,100,0),
(@PATH,18,-734.533,-3776.877,230.4756,0,0,0,0,100,0),
(@PATH,19,-715.7847,-3777.368,227.8993,0,0,0,0,100,0),
(@PATH,20,-700.4774,-3778.906,226.8431,0,0,0,0,100,0);

-- Pathing for Hiri'watha Deathguard Entry: 43715 'TDB FORMAT' 
SET @NPC := 279326;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-29.6389,`position_y`=-2819.92,`position_z`=124.1563 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-29.6389,-2819.92,124.1563,0,0,0,0,100,0),
(@PATH,2,-37.6753,-2816.78,122.1611,0,0,0,0,100,0),
(@PATH,3,-42.1667,-2818.29,122.1611,0,0,0,0,100,0),
(@PATH,4,-49.7257,-2825.17,122.6611,0,40000,0,0,100,0),
(@PATH,5,-38.97396,-2810.599,122.2861,0,0,0,0,100,0),
(@PATH,6,-32.05035,-2810.639,122.5359,0,0,0,0,100,0),
(@PATH,7,-24.40278,-2803.2,121.9825,0,0,0,0,100,0),
(@PATH,8,-15.93403,-2801.358,122.437,0,0,0,0,100,0),
(@PATH,9,-15.03125,-2795.036,122.889,0,0,0,0,100,0),
(@PATH,10,-13.78125,-2791.979,123.281,0,35000,0,0,100,0),
(@PATH,11,-13.6424,-2804.63,123.3118,0,0,0,0,100,0),
(@PATH,12,-15.7257,-2811.05,122.6746,0,0,0,0,100,0),
(@PATH,13,-21.8229,-2819.5,124.8125,0,0,0,0,100,0),
(@PATH,14,-20.6337,-2825.87,126.866,0,35000,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279102;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-206.904,`position_y`=-3475.084,`position_z`=151.9043 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-206.904,-3475.084,151.9043,0,0,0,0,100,0),
(@PATH,2,-200.4788,-3434.95,146.2304,0,0,0,0,100,0),
(@PATH,3,-203.9309,-3418.808,143.2951,0,0,0,0,100,0),
(@PATH,4,-195.2656,-3404.164,141.2934,0,0,0,0,100,0),
(@PATH,5,-202.2799,-3375.22,140.7173,0,0,0,0,100,0),
(@PATH,6,-203.4991,-3362.463,138.0727,0,0,0,0,100,0),
(@PATH,7,-210.0501,-3339.789,129.6406,0,0,0,0,100,0),
(@PATH,8,-203.4991,-3362.463,138.0727,0,0,0,0,100,0),
(@PATH,9,-202.2799,-3375.22,140.7173,0,0,0,0,100,0),
(@PATH,10,-195.1908,-3404.021,141.3093,0,0,0,0,100,0),
(@PATH,11,-203.9309,-3418.808,143.2951,0,0,0,0,100,0),
(@PATH,12,-200.4788,-3434.95,146.2304,0,0,0,0,100,0),
(@PATH,13,-206.904,-3475.084,151.9043,0,0,0,0,100,0),
(@PATH,14,-199.7915,-3487.105,148.1571,0,0,0,0,100,0),
(@PATH,15,-174.5607,-3523.659,133.8973,0,0,0,0,100,0),
(@PATH,16,-179.4385,-3544.364,128.0257,0,0,0,0,100,0),
(@PATH,17,-174.5607,-3523.659,133.8973,0,0,0,0,100,0),
(@PATH,18,-199.7915,-3487.105,148.1571,0,0,0,0,100,0),
(@PATH,19,-179.1244,-3493.43,135.2657,0,0,0,0,100,0),
(@PATH,20,-173.9696,-3489.252,134.2533,0,0,0,0,100,0),
(@PATH,21,-173.435,-3488.396,134.2411,0,0,0,0,100,0),
(@PATH,22,-172.373,-3486.682,134.1856,0,0,0,0,100,0),
(@PATH,23,-171.8432,-3485.827,134.0733,0,0,0,0,100,0),
(@PATH,24,-191.2269,-3499.546,138.0598,0,0,0,0,100,0),
(@PATH,25,-199.7915,-3487.105,148.1571,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279138;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-204.3212,`position_y`=-3441.696,`position_z`=149.5521 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-204.3212,-3441.696,149.5521,0,0,0,0,100,0),
(@PATH,2,-205.9057,-3457.722,150.546,0,0,0,0,100,0),
(@PATH,3,-202.4709,-3479.104,151.2285,0,0,0,0,100,0),
(@PATH,4,-194.7148,-3496.434,141.0028,0,0,0,0,100,0),
(@PATH,5,-197.7368,-3505.634,139.2613,0,0,0,0,100,0),
(@PATH,6,-221.2634,-3510.848,147.3332,0,0,0,0,100,0),
(@PATH,7,-226.2365,-3526.755,144.9807,0,0,0,0,100,0),
(@PATH,8,-222.5308,-3544.987,137.8342,0,0,0,0,100,0),
(@PATH,9,-226.2365,-3526.755,144.9807,0,0,0,0,100,0),
(@PATH,10,-204.3212,-3441.696,149.5521,0,0,0,0,100,0),
(@PATH,11,-206.0197,-3427.299,146.5487,0,0,0,0,100,0),
(@PATH,12,-225.0481,-3418.769,150.3322,0,0,0,0,100,0),
(@PATH,13,-227.4273,-3399.455,149.1401,0,0,0,0,100,0),
(@PATH,14,-232.7189,-3370.76,137.6809,0,0,0,0,100,0),
(@PATH,15,-227.4512,-3399.307,149.1672,0,0,0,0,100,0),
(@PATH,16,-225.0481,-3418.769,150.3322,0,0,0,0,100,0),
(@PATH,17,-206.0197,-3427.299,146.5487,0,0,0,0,100,0),
(@PATH,18,-204.3212,-3441.696,149.5521,0,0,0,0,100,0),
(@PATH,19,-205.9057,-3457.722,150.546,0,0,0,0,100,0),
(@PATH,20,-181.0256,-3469.277,142.4674,0,0,0,0,100,0),
(@PATH,21,-181.0256,-3469.277,142.4674,0,0,0,0,100,0),
(@PATH,22,-182.4888,-3471.364,144.1296,0,0,0,0,100,0),
(@PATH,23,-182.3516,-3470.645,144.0028,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279141;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-173.9625,`position_y`=-3391.907,`position_z`=130.7934 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-173.9625,-3391.907,130.7934,0,0,0,0,100,0),
(@PATH,2,-203.4194,-3403.643,141.8034,0,0,0,0,100,0),
(@PATH,3,-212.8586,-3390.262,144.3594,0,0,0,0,100,0),
(@PATH,4,-224.8477,-3373.99,139.1672,0,0,0,0,100,0),
(@PATH,5,-240.878,-3363.784,138.5009,0,0,0,0,100,0),
(@PATH,6,-255.0435,-3335.365,135.0048,0,0,0,0,100,0),
(@PATH,7,-240.878,-3363.784,138.5009,0,0,0,0,100,0),
(@PATH,8,-224.8477,-3373.99,139.1672,0,0,0,0,100,0),
(@PATH,9,-212.8586,-3390.262,144.3594,0,0,0,0,100,0),
(@PATH,10,-203.4194,-3403.643,141.8034,0,0,0,0,100,0),
(@PATH,11,-173.9625,-3391.907,130.7934,0,0,0,0,100,0),
(@PATH,12,-163.2272,-3415.764,131.2807,0,0,0,0,100,0),
(@PATH,13,-175.9346,-3436.92,136.1306,0,0,0,0,100,0),
(@PATH,14,-170.0045,-3455.669,134.8135,0,0,0,0,100,0),
(@PATH,15,-156.9954,-3465.994,131.035,0,0,0,0,100,0),
(@PATH,16,-170.0045,-3455.669,134.8135,0,0,0,0,100,0),
(@PATH,17,-175.9346,-3436.92,136.1306,0,0,0,0,100,0),
(@PATH,18,-163.2272,-3415.764,131.2807,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279182;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-189.7311,`position_y`=-3299.194,`position_z`=126.0412 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-189.7311,-3299.194,126.0412,0,0,0,0,100,0),
(@PATH,2,-221.4348,-3291.724,122.945,0,0,0,0,100,0),
(@PATH,3,-234.8142,-3318.671,129.0955,0,0,0,0,100,0),
(@PATH,4,-249.1305,-3342.041,134.184,0,0,0,0,100,0),
(@PATH,5,-272.4542,-3338.597,139.6066,0,0,0,0,100,0),
(@PATH,6,-281.9175,-3328.704,137.789,0,0,0,0,100,0),
(@PATH,7,-312.8323,-3331.88,140.4149,0,0,0,0,100,0),
(@PATH,8,-329.8807,-3311.526,133.1639,0,0,0,0,100,0),
(@PATH,9,-352.9347,-3309.36,133.2147,0,0,0,0,100,0),
(@PATH,10,-330.0254,-3311.516,133.3031,0,0,0,0,100,0),
(@PATH,11,-312.8323,-3331.88,140.4149,0,0,0,0,100,0),
(@PATH,12,-281.9175,-3328.704,137.789,0,0,0,0,100,0),
(@PATH,13,-272.4542,-3338.597,139.6066,0,0,0,0,100,0),
(@PATH,14,-249.1305,-3342.041,134.184,0,0,0,0,100,0),
(@PATH,15,-234.8142,-3318.671,129.0955,0,0,0,0,100,0),
(@PATH,16,-221.4348,-3291.724,122.945,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279151;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-339.9403,`position_y`=-3279.894,`position_z`=125.1113 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-339.9403,-3279.894,125.1113,0,0,0,0,100,0),
(@PATH,2,-326.524,-3297.52,127.3058,0,0,0,0,100,0),
(@PATH,3,-317.7809,-3326.113,140.1778,0,0,0,0,100,0),
(@PATH,4,-317.621,-3342.04,140.5803,0,0,0,0,100,0),
(@PATH,5,-317.7366,-3360.364,148.4025,0,0,0,0,100,0),
(@PATH,6,-331.2551,-3378.782,149.8505,0,0,0,0,100,0),
(@PATH,7,-338.6738,-3395.199,156.6765,0,0,0,0,100,0),
(@PATH,8,-334.6689,-3405.388,158.7557,0,0,0,0,100,0),
(@PATH,9,-338.7488,-3395.37,156.5903,0,0,0,0,100,0),
(@PATH,10,-331.2551,-3378.782,149.8505,0,0,0,0,100,0),
(@PATH,11,-317.7366,-3360.364,148.4025,0,0,0,0,100,0),
(@PATH,12,-317.621,-3342.04,140.5803,0,0,0,0,100,0),
(@PATH,13,-317.7809,-3326.113,140.1778,0,0,0,0,100,0),
(@PATH,14,-326.524,-3297.52,127.3058,0,0,0,0,100,0);

-- Pathing for Vilebranch Wolf Pup Entry: 2680 'TDB FORMAT' 
SET @NPC := 279186;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-194.461,`position_y`=-3306.197,`position_z`=126.2076 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-194.461,-3306.197,126.2076,0,0,0,0,100,0),
(@PATH,2,-199.4555,-3286.746,123.7389,0,0,0,0,100,0),
(@PATH,3,-194.8121,-3265.847,118.4571,0,0,0,0,100,0),
(@PATH,4,-208.3118,-3248.933,119.8761,0,0,0,0,100,0),
(@PATH,5,-234.5598,-3247.828,122.7559,0,0,0,0,100,0),
(@PATH,6,-256.2849,-3250.373,124.8579,0,0,0,0,100,0),
(@PATH,7,-277.8226,-3252.738,121.0488,0,0,0,0,100,0),
(@PATH,8,-302.1093,-3237.622,120.4203,0,0,0,0,100,0),
(@PATH,9,-311.2962,-3234.398,128.6808,0,0,0,0,100,0),
(@PATH,10,-320.9648,-3231.879,129.2975,0,0,0,0,100,0),
(@PATH,11,-335.9349,-3230.234,124.364,0,0,0,0,100,0),
(@PATH,12,-321.2754,-3231.801,129.3451,0,0,0,0,100,0),
(@PATH,13,-311.2962,-3234.398,128.8555,0,0,0,0,100,0),
(@PATH,14,-302.1093,-3237.622,120.4203,0,0,0,0,100,0),
(@PATH,15,-277.8226,-3252.738,121.0168,0,0,0,0,100,0),
(@PATH,16,-256.2849,-3250.373,124.8579,0,0,0,0,100,0),
(@PATH,17,-234.5598,-3247.828,122.7559,0,0,0,0,100,0),
(@PATH,18,-208.3118,-3248.933,119.8761,0,0,0,0,100,0),
(@PATH,19,-194.8121,-3265.847,118.4571,0,0,0,0,100,0),
(@PATH,20,-199.4555,-3286.746,123.7389,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279417;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=179.5265,`position_y`=-2221.172,`position_z`=99.91411 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,179.5265,-2221.172,99.91411,0,0,0,0,100,0),
(@PATH,2,164.0377,-2200.086,99.37125,0,0,0,0,100,0),
(@PATH,3,150.845,-2176.286,102.3184,0,0,0,0,100,0),
(@PATH,4,144.5677,-2163.21,103.3494,0,0,0,0,100,0),
(@PATH,5,150.4954,-2144.921,102.6832,0,0,0,0,100,0),
(@PATH,6,163.6321,-2123.072,101.7304,0,0,0,0,100,0),
(@PATH,7,156.652,-2106.512,104.4705,0,0,0,0,100,0),
(@PATH,8,168.3095,-2087.278,110.857,0,0,0,0,100,0),
(@PATH,9,171.3452,-2071.499,117.2696,0,0,0,0,100,0),
(@PATH,10,161.3516,-2057.752,118.4549,0,0,0,0,100,0),
(@PATH,11,144.7996,-2047.729,117.3365,0,0,0,0,100,0),
(@PATH,12,124.0238,-2052.106,114.9393,0,0,0,0,100,0),
(@PATH,13,93.03144,-2075.449,112.8879,0,0,0,0,100,0),
(@PATH,14,85.10664,-2101.786,110.5066,0,0,0,0,100,0),
(@PATH,15,67.45117,-2105.097,117.0851,0,0,0,0,100,0),
(@PATH,16,85.10664,-2101.786,110.5066,0,0,0,0,100,0),
(@PATH,17,93.03144,-2075.449,112.8879,0,0,0,0,100,0),
(@PATH,18,124.0238,-2052.106,114.9393,0,0,0,0,100,0),
(@PATH,19,144.5723,-2047.758,117.4549,0,0,0,0,100,0),
(@PATH,20,161.1847,-2057.534,118.4288,0,0,0,0,100,0),
(@PATH,21,171.3452,-2071.499,117.2696,0,0,0,0,100,0),
(@PATH,22,168.3145,-2087.217,111.0186,0,0,0,0,100,0),
(@PATH,23,156.652,-2106.512,104.4705,0,0,0,0,100,0),
(@PATH,24,163.6321,-2123.072,101.7304,0,0,0,0,100,0),
(@PATH,25,150.4954,-2144.921,102.6832,0,0,0,0,100,0),
(@PATH,26,144.5677,-2163.21,103.3494,0,0,0,0,100,0),
(@PATH,27,150.845,-2176.286,102.3184,0,0,0,0,100,0),
(@PATH,28,164.0377,-2200.086,99.37125,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279423;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=37.75754,`position_y`=-2190.211,`position_z`=111.1299 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,37.75754,-2190.211,111.1299,0,0,0,0,100,0),
(@PATH,2,64.65501,-2195.903,105.8014,0,0,0,0,100,0),
(@PATH,3,95.82693,-2211.324,102.3146,0,0,0,0,100,0),
(@PATH,4,90.93012,-2238.993,102.5777,0,0,0,0,100,0),
(@PATH,5,101.8587,-2265.823,104.4002,0,0,0,0,100,0),
(@PATH,6,121.0381,-2275.893,103.8506,0,0,0,0,100,0),
(@PATH,7,131.25,-2267.709,103.4378,0,0,0,0,100,0),
(@PATH,8,159.6513,-2255.293,99.45204,0,0,0,0,100,0),
(@PATH,9,177.9442,-2271.794,102.02,0,0,0,0,100,0),
(@PATH,10,176.9244,-2304.868,104.844,0,0,0,0,100,0),
(@PATH,11,202.998,-2312.318,107.7501,0,0,0,0,100,0),
(@PATH,12,242.5796,-2336.158,114.2354,0,0,0,0,100,0),
(@PATH,13,202.998,-2312.318,107.7501,0,0,0,0,100,0),
(@PATH,14,176.9244,-2304.868,104.844,0,0,0,0,100,0),
(@PATH,15,177.9442,-2271.794,102.02,0,0,0,0,100,0),
(@PATH,16,159.6513,-2255.293,99.45204,0,0,0,0,100,0),
(@PATH,17,131.25,-2267.709,103.4378,0,0,0,0,100,0),
(@PATH,18,121.0381,-2275.893,103.8506,0,0,0,0,100,0),
(@PATH,19,101.8587,-2265.823,104.4002,0,0,0,0,100,0),
(@PATH,20,90.93012,-2238.993,102.5777,0,0,0,0,100,0),
(@PATH,21,95.82693,-2211.324,102.3146,0,0,0,0,100,0),
(@PATH,22,64.65501,-2195.903,105.8014,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279425;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=107.9462,`position_y`=-2092.908,`position_z`=109.5675 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,107.9462,-2092.908,109.5675,0,0,0,0,100,0),
(@PATH,2,152.8941,-2104.095,105.2553,0,0,0,0,100,0),
(@PATH,3,163.684,-2125.115,101.5708,0,0,0,0,100,0),
(@PATH,4,179.4497,-2143.958,100.7923,0,0,0,0,100,0),
(@PATH,5,195.6775,-2148.733,104.9724,0,0,0,0,100,0),
(@PATH,6,200.4404,-2169.921,107.1781,0,0,0,0,100,0),
(@PATH,7,206.7194,-2185.296,106.7243,0,0,0,0,100,0),
(@PATH,8,215.7208,-2191.953,108.5033,0,0,0,0,100,0),
(@PATH,9,204.2096,-2212.008,102.5331,0,0,0,0,100,0),
(@PATH,10,181.2352,-2224.846,99.18852,0,0,0,0,100,0),
(@PATH,11,169.8631,-2243.397,98.13044,0,0,0,0,100,0),
(@PATH,12,171.4284,-2261.976,100.1387,0,0,0,0,100,0),
(@PATH,13,183.8524,-2279.712,103.051,0,0,0,0,100,0),
(@PATH,14,171.4284,-2261.976,100.1387,0,0,0,0,100,0),
(@PATH,15,169.8631,-2243.397,98.13044,0,0,0,0,100,0),
(@PATH,16,181.2352,-2224.846,99.18852,0,0,0,0,100,0),
(@PATH,17,203.9336,-2212.15,102.4115,0,0,0,0,100,0),
(@PATH,18,215.7208,-2191.953,108.5033,0,0,0,0,100,0),
(@PATH,19,206.8691,-2185.422,106.5824,0,0,0,0,100,0),
(@PATH,20,200.4404,-2169.921,107.1781,0,0,0,0,100,0),
(@PATH,21,195.6775,-2148.733,104.9724,0,0,0,0,100,0),
(@PATH,22,179.4497,-2143.958,100.7923,0,0,0,0,100,0),
(@PATH,23,163.684,-2125.115,101.5708,0,0,0,0,100,0),
(@PATH,24,152.8941,-2104.095,105.2553,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279408;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=13.80431,`position_y`=-2285.122,`position_z`=117.2496 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,13.80431,-2285.122,117.2496,0,0,0,0,100,0),
(@PATH,2,26.68392,-2286.802,117.826,0,0,0,0,100,0),
(@PATH,3,41.79129,-2274.867,114.2015,0,0,0,0,100,0),
(@PATH,4,66.99517,-2278.884,108.5381,0,0,0,0,100,0),
(@PATH,5,93.5861,-2276.216,106.4078,0,0,0,0,100,0),
(@PATH,6,111.2402,-2279.241,105.3477,0,0,0,0,100,0),
(@PATH,7,102.5366,-2313.62,111.2529,0,0,0,0,100,0),
(@PATH,8,123.002,-2329.666,111.6811,0,0,0,0,100,0),
(@PATH,9,127.9236,-2353.786,119.2942,0,0,0,0,100,0),
(@PATH,10,139.9812,-2367.15,122.9519,0,0,0,0,100,0),
(@PATH,11,162.3677,-2362.794,122.7193,0,0,0,0,100,0),
(@PATH,12,176.9903,-2379.205,133.6557,0,0,0,0,100,0),
(@PATH,13,162.3677,-2362.794,122.7193,0,0,0,0,100,0),
(@PATH,14,139.9812,-2367.15,122.9519,0,0,0,0,100,0),
(@PATH,15,127.9236,-2353.786,119.2942,0,0,0,0,100,0),
(@PATH,16,123.0938,-2329.748,111.6618,0,0,0,0,100,0),
(@PATH,17,102.5366,-2313.62,111.2529,0,0,0,0,100,0),
(@PATH,18,111.2402,-2279.241,105.3477,0,0,0,0,100,0),
(@PATH,19,93.5861,-2276.216,106.4078,0,0,0,0,100,0),
(@PATH,20,66.99517,-2278.884,108.5381,0,0,0,0,100,0),
(@PATH,21,41.79129,-2274.867,114.2015,0,0,0,0,100,0),
(@PATH,22,26.68392,-2286.802,117.826,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279409;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=116.495,`position_y`=-2174.824,`position_z`=106.2546 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,116.495,-2174.824,106.2546,0,0,0,0,100,0),
(@PATH,2,90.23432,-2214.412,101.878,0,0,0,0,100,0),
(@PATH,3,86.02113,-2247.196,102.5777,0,0,0,0,100,0),
(@PATH,4,103.5695,-2278.689,106.1981,0,0,0,0,100,0),
(@PATH,5,98.37682,-2311.304,110.9629,0,0,0,0,100,0),
(@PATH,6,103.7768,-2334.411,114.2902,0,0,0,0,100,0),
(@PATH,7,127.6483,-2358.697,119.9755,0,0,0,0,100,0),
(@PATH,8,153.3342,-2366.445,122.4797,0,0,0,0,100,0),
(@PATH,9,172.5862,-2344.447,120.9098,0,0,0,0,100,0),
(@PATH,10,194.1328,-2351.588,125.6396,0,0,0,0,100,0),
(@PATH,11,221.4874,-2341.675,114.1193,0,0,0,0,100,0),
(@PATH,12,194.1328,-2351.588,125.6396,0,0,0,0,100,0),
(@PATH,13,172.5862,-2344.447,120.9098,0,0,0,0,100,0),
(@PATH,14,153.3342,-2366.445,122.4797,0,0,0,0,100,0),
(@PATH,15,127.6483,-2358.697,119.9755,0,0,0,0,100,0),
(@PATH,16,103.7768,-2334.411,114.2902,0,0,0,0,100,0),
(@PATH,17,98.37682,-2311.304,110.9629,0,0,0,0,100,0),
(@PATH,18,103.5695,-2278.689,106.1981,0,0,0,0,100,0),
(@PATH,19,86.02113,-2247.196,102.5777,0,0,0,0,100,0),
(@PATH,20,90.23432,-2214.412,101.878,0,0,0,0,100,0);

-- Pathing for Trained Razorbeak Entry: 2657 'TDB FORMAT' 
SET @NPC := 279437;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=168.0087,`position_y`=-2132.8,`position_z`=101.3473 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,168.0087,-2132.8,101.3473,0,0,0,0,100,0),
(@PATH,2,191.5208,-2154.24,104.3058,0,0,0,0,100,0),
(@PATH,3,202.3086,-2172.287,107.8324,0,0,0,0,100,0),
(@PATH,4,207.4774,-2195.295,105.3791,0,0,0,0,100,0),
(@PATH,5,202.3394,-2211.945,102.2589,0,0,0,0,100,0),
(@PATH,6,177.2196,-2222.978,100.1963,0,0,0,0,100,0),
(@PATH,7,167.9087,-2243.185,98.13557,0,0,0,0,100,0),
(@PATH,8,173.4446,-2262.221,100.4395,0,0,0,0,100,0),
(@PATH,9,199.865,-2264.24,105.0054,0,0,0,0,100,0),
(@PATH,10,228.6064,-2260.211,104.7093,0,0,0,0,100,0),
(@PATH,11,245.6556,-2281.27,109.3484,0,0,0,0,100,0),
(@PATH,12,255.9115,-2298.467,112.8083,0,0,0,0,100,0),
(@PATH,13,245.6556,-2281.27,109.3484,0,0,0,0,100,0),
(@PATH,14,228.6064,-2260.211,104.7093,0,0,0,0,100,0),
(@PATH,15,199.865,-2264.24,105.0054,0,0,0,0,100,0),
(@PATH,16,173.4446,-2262.221,100.4395,0,0,0,0,100,0),
(@PATH,17,167.9087,-2243.185,98.13557,0,0,0,0,100,0),
(@PATH,18,177.2196,-2222.978,100.1963,0,0,0,0,100,0),
(@PATH,19,202.3394,-2211.945,102.2589,0,0,0,0,100,0),
(@PATH,20,207.4774,-2195.295,105.3791,0,0,0,0,100,0),
(@PATH,21,202.3281,-2172.326,107.7415,0,0,0,0,100,0),
(@PATH,22,191.5208,-2154.24,104.3058,0,0,0,0,100,0);

-- Pathing for Vilebranch Headhunter Entry: 2641 'TDB FORMAT' 
SET @NPC := 278864;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-358.0292,`position_y`=-4116.998,`position_z`=154.2687 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-358.0292,-4116.998,154.2687,0,0,0,0,100,0),
(@PATH,2,-345.4443,-4114.745,151.9538,0,0,0,0,100,0),
(@PATH,3,-334.7697,-4118.176,152.1513,0,0,0,0,100,0),
(@PATH,4,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,5,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,6,-346.6712,-4160.327,152.1256,0,0,0,0,100,0),
(@PATH,7,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,8,-346.2449,-4195.276,152.2244,0,0,0,0,100,0),
(@PATH,9,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,10,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,11,-337.7476,-4206.129,152.1899,0,0,0,0,100,0),
(@PATH,12,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,13,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,14,-346.2449,-4195.276,152.2244,0,0,0,0,100,0),
(@PATH,15,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,16,-346.6712,-4160.327,152.1256,0,0,0,0,100,0),
(@PATH,17,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,18,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,19,-334.7697,-4118.176,152.1513,0,0,0,0,100,0),
(@PATH,20,-345.4443,-4114.745,151.9538,0,0,0,0,100,0);

-- Pathing for Soaring Razorbeak Entry: 8276 'TDB FORMAT' 
SET @NPC := 279406;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8.138883,`position_y`=-2010.767,`position_z`=256.8609 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 8.138883, -2010.767, 256.8609,0,0,0,0,100,0),
(@PATH,2, 9.300347, -2000.809, 255.784,0,0,0,0,100,0),
(@PATH,3, 9.532987, -1995.004, 256.1451,0,0,0,0,100,0),
(@PATH,4, 10.56076, -1984.519, 254.9229,0,0,0,0,100,0),
(@PATH,5, 15.98508, -1973.704, 241.5342,0,0,0,0,100,0),
(@PATH,6, 34.32915, -1949.409, 222.7841,0,0,0,0,100,0),
(@PATH,7, 42.90603, -1945.032, 210.0897,0,0,0,0,100,0),
(@PATH,8, 55.24517, -1954.354, 201.6454,0,0,0,0,100,0),
(@PATH,9, 74.63949, -1952.484, 186.173,0,0,0,0,100,0),
(@PATH,10, 96.28931, -1945.88, 178.5898,0,0,0,0,100,0),
(@PATH,11, 119.4835, -1949.763, 175.6732,0,0,0,0,100,0),
(@PATH,12, 140.9103, -1954.463, 178.5898,0,0,0,0,100,0),
(@PATH,13, 175.9826, -1968.736, 181.1453,0,0,0,0,100,0),
(@PATH,14, 234.7396, -2023.986, 179.3675,0,0,0,0,100,0),
(@PATH,15, 268.4167, -2072.503, 178.5898,0,0,0,0,100,0),
(@PATH,16, 272.2799, -2094.271, 162.3121,0,0,0,0,100,0),
(@PATH,17, 273.1461, -2106.721, 146.4232,0,0,0,0,100,0),
(@PATH,18, 264.7748, -2126.123, 141.1454,0,0,0,0,100,0),
(@PATH,19, 237.9751, -2146.008, 140.6177,0,0,0,0,100,0),
(@PATH,20, 224.3799, -2159.136, 146.7565,0,0,0,0,100,0),
(@PATH,21, 215.8537, -2187.316, 142.2844,0,0,0,0,100,0),
(@PATH,22, 211.499, -2223.978, 137.1456,0,0,0,0,100,0),
(@PATH,23, 206.0708, -2247.768, 131.3956,0,0,0,0,100,0),
(@PATH,24, 193.518, -2268.615, 122.4788,0,0,0,0,100,0),
(@PATH,25, 191.5475, -2312.957, 138.7289,0,0,0,0,100,0),
(@PATH,26, 184.4495, -2339.293, 152.8955,0,0,0,0,100,0),
(@PATH,27, 157.4132, -2363.806, 153.4232,0,0,0,0,100,0),
(@PATH,28, 137.0358, -2370.974, 154.84,0,0,0,0,100,0),
(@PATH,29, 100.0434, -2370.155, 159.9232,0,0,0,0,100,0),
(@PATH,30, 91.16349, -2316.633, 167.0065,0,0,0,0,100,0),
(@PATH,31, 66.26958, -2319.838, 161.7567,0,0,0,0,100,0),
(@PATH,32, 51.68322, -2351.017, 155.34,0,0,0,0,100,0),
(@PATH,33, 46.88558, -2391.454, 155.3955,0,0,0,0,100,0),
(@PATH,34, 48.95198, -2429.261, 167.0065,0,0,0,0,100,0),
(@PATH,35, 60.98427, -2457.343, 160.5621,0,0,0,0,100,0),
(@PATH,36, 72.59733, -2484.933, 167.0065,0,0,0,0,100,0),
(@PATH,37, 67.51839, -2521.897, 160.6455,0,0,0,0,100,0),
(@PATH,38, 47.9924, -2556.676, 154.6733,0,0,0,0,100,0),
(@PATH,39, 27.44385, -2588.135, 146.9788,0,0,0,0,100,0),
(@PATH,40, 17.39686, -2612.678, 148.6455,0,0,0,0,100,0),
(@PATH,41, 21.83122, -2637.95, 152.451,0,0,0,0,100,0),
(@PATH,42, 55.23676, -2648.286, 155.8678,0,0,0,0,100,0),
(@PATH,43, 79.08621, -2628.212, 160.8954,0,0,0,0,100,0),
(@PATH,44, 67.07992, -2605.687, 163.1453,0,0,0,0,100,0),
(@PATH,45, 58.42876, -2578.681, 158.2565,0,0,0,0,100,0),
(@PATH,46, 72.62418, -2532.922, 160.9789,0,0,0,0,100,0),
(@PATH,47, 81.3728, -2498.174, 155.0899,0,0,0,0,100,0),
(@PATH,48, 100.9606, -2456.425, 157.4788,0,0,0,0,100,0),
(@PATH,49, 97.07639, -2406.302, 160.9788,0,0,0,0,100,0),
(@PATH,50, 107.3507, -2379.434, 157.7843,0,0,0,0,100,0),
(@PATH,51, 133.4757, -2354.778, 153.3677,0,0,0,0,100,0),
(@PATH,52, 80.57438, -2283.499, 143.8122,0,0,0,0,100,0),
(@PATH,53, 84.78071, -2245.21, 144.7843,0,0,0,0,100,0),
(@PATH,54, 92.43682, -2223.625, 147.2844,0,0,0,0,100,0),
(@PATH,55, 98.48202, -2205.757, 138.5344,0,0,0,0,100,0),
(@PATH,56, 109.2431, -2172.123, 140.0066,0,0,0,0,100,0),
(@PATH,57, 104.0712, -2148.068, 136.7566,0,0,0,0,100,0),
(@PATH,58, 90.35813, -2125.51, 145.5621,0,0,0,0,100,0),
(@PATH,59, 69.62039, -2110.209, 155.8121,0,0,0,0,100,0),
(@PATH,60, 49.8979, -2097.538, 174.3676,0,0,0,0,100,0),
(@PATH,61, 40.1824, -2089.698, 184.5359,0,0,0,0,100,0),
(@PATH,62, 33.39735, -2076.468, 198.8176,0,0,0,0,100,0),
(@PATH,63, 17.7984, -2058.321, 206.4115,0,0,0,0,100,0),
(@PATH,64, 8.934028, -2051.87, 219.2886,0,0,0,0,100,0);
 
 -- Pathing for Soaring Razorbeak Entry: 8276 'TDB FORMAT' 
SET @NPC := 279286;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8.138883,`position_y`=-2010.767,`position_z`=256.8609 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 407.7414, -3026.062, 170.9778,0,0,0,0,100,0),
(@PATH, 2, 408.3816, -3022.08, 172.061,0,0,0,0,100,0),
(@PATH, 3, 408.7644, -3001.821, 180.1716,0,0,0,0,100,0),
(@PATH, 4, 390.4138, -2980.695, 186.3105,0,0,0,0,100,0),
(@PATH, 5, 360.4061, -2967.067, 181.061,0,0,0,0,100,0),
(@PATH, 6, 333.6045, -2964.407, 169.9501,0,0,0,0,100,0),
(@PATH, 7, 312.3234, -2950.052, 169.9501,0,0,0,0,100,0),
(@PATH, 8, 292.4103, -2925.483, 169.9501,0,0,0,0,100,0),
(@PATH, 9, 262.3471, -2894.731, 169.9501,0,0,0,0,100,0),
(@PATH, 10, 232.4911, -2859.147, 169.9501,0,0,0,0,100,0),
(@PATH, 11, 209.5929, -2823.021, 169.9501,0,0,0,0,100,0),
(@PATH, 12, 183.598, -2800.427, 169.9501,0,0,0,0,100,0),
(@PATH, 13, 167.4887, -2779.08, 169.9501,0,0,0,0,100,0),
(@PATH, 14, 141.4919, -2772.1, 169.9501,0,0,0,0,100,0),
(@PATH, 15, 105.7804, -2778.329, 169.9501,0,0,0,0,100,0),
(@PATH, 16, 89.81522, -2776.243, 169.9501,0,0,0,0,100,0),
(@PATH, 17, 62.67708, -2785.582, 169.9501,0,0,0,0,100,0),
(@PATH, 18, 41.96843, -2823.31, 169.9501,0,0,0,0,100,0),
(@PATH, 19, 46.22146, -2853.429, 172.2555,0,0,0,0,100,0),
(@PATH, 20, 33.42741, -2886.248, 169.9501,0,0,0,0,100,0),
(@PATH, 21, 3.648112, -2911.167, 169.9501,0,0,0,0,100,0),
(@PATH, 22, -38.49284, -2938.704, 169.9501,0,0,0,0,100,0),
(@PATH, 23, -51.07465, -3008.731, 169.9501,0,0,0,0,100,0),
(@PATH, 24, -24.44618, -3058.196, 169.9501,0,0,0,0,100,0),
(@PATH, 25, 18.36111, -3092.292, 174.7917,0,0,0,0,100,0),
(@PATH, 26, 63.39236, -3103.908, 166.9942,0,0,0,0,100,0),
(@PATH, 27, 91.07227, -3112.037, 169.9501,0,0,0,0,100,0),
(@PATH, 28, 127.375, -3123.436, 169.9501,0,0,0,0,100,0),
(@PATH, 29, 172.0519, -3135.789, 169.9501,0,0,0,0,100,0),
(@PATH, 30, 198.6322, -3119.656, 169.9501,0,0,0,0,100,0),
(@PATH, 31, 214.2938, -3097.128, 169.9501,0,0,0,0,100,0),
(@PATH, 32, 215.7621, -3067.858, 169.9501,0,0,0,0,100,0),
(@PATH, 33, 213.4889, -3032.985, 169.9501,0,0,0,0,100,0),
(@PATH, 34, 191.5654, -2997.423, 169.9501,0,0,0,0,100,0),
(@PATH, 35, 157.8765, -2987.229, 169.9501,0,0,0,0,100,0),
(@PATH, 36, 143.0476, -2974.784, 169.9501,0,0,0,0,100,0),
(@PATH, 37, 143.9447, -2951.888, 169.7001,0,0,0,0,100,0),
(@PATH, 38, 161.382, -2943.685, 169.9501,0,0,0,0,100,0),
(@PATH, 39, 181.4357, -2949.301, 169.9501,0,0,0,0,100,0),
(@PATH, 40, 199.6969, -2960.48, 169.9501,0,0,0,0,100,0),
(@PATH, 41, 211.579, -2973.645, 169.9501,0,0,0,0,100,0),
(@PATH, 42, 234.6239, -2994.183, 169.9501,0,0,0,0,100,0),
(@PATH, 43, 234.424, -3036.441, 169.9501,0,0,0,0,100,0),
(@PATH, 44, 254.6997, -3059.207, 169.9501,0,0,0,0,100,0),
(@PATH, 45, 286.7328, -3084.267, 169.9501,0,0,0,0,100,0),
(@PATH, 46, 308.4647, -3084.497, 169.9501,0,0,0,0,100,0),
(@PATH, 47, 341.8581, -3070.787, 169.9501,0,0,0,0,100,0),
(@PATH, 48, 368.4164, -3064.39, 169.9501,0,0,0,0,100,0),
(@PATH, 49, 391.3282, -3055.33, 171.3112,0,0,0,0,100,0),
(@PATH, 50, 404.2534, -3043.248, 171.4779,0,0,0,0,100,0);

-- Pathing for Razorbeak Skylord Entry: 2659 'TDB FORMAT' 
SET @NPC := 279045;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=16.59071,`position_y`=-3620.027,`position_z`=120.636 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,16.59071,-3620.027,120.636,0,0,0,0,100,0),
(@PATH,2,46.47087,-3625.726,122.0062,0,0,0,0,100,0),
(@PATH,3,82.99265,-3616.286,127.1898,0,0,0,0,100,0),
(@PATH,4,117.2668,-3619.316,128.5378,0,0,0,0,100,0),
(@PATH,5,142.9924,-3598.415,127.4793,0,0,0,0,100,0),
(@PATH,6,182.0998,-3585.068,126.9413,0,0,0,0,100,0),
(@PATH,7,218.6891,-3571.978,128.8637,0,0,0,0,100,0),
(@PATH,8,247.9379,-3583.79,129.2427,0,0,0,0,100,0),
(@PATH,9,221.5409,-3607.947,129.086,0,0,0,0,100,0),
(@PATH,10,203.2664,-3637.025,131.0454,0,0,0,0,100,0),
(@PATH,11,192.0568,-3658.608,132.675,0,0,0,0,100,0),
(@PATH,12,185.4547,-3684.577,131.2249,0,0,0,0,100,0),
(@PATH,13,156.6011,-3714.952,131.1908,0,0,0,0,100,0),
(@PATH,14,135.6442,-3740.408,126.6671,0,0,0,0,100,0),
(@PATH,15,156.6011,-3714.952,131.1908,0,0,0,0,100,0),
(@PATH,16,185.4547,-3684.577,131.2249,0,0,0,0,100,0),
(@PATH,17,192.0568,-3658.608,132.675,0,0,0,0,100,0),
(@PATH,18,203.2664,-3637.025,131.0454,0,0,0,0,100,0),
(@PATH,19,221.5409,-3607.947,129.086,0,0,0,0,100,0),
(@PATH,20,247.9379,-3583.79,129.2427,0,0,0,0,100,0),
(@PATH,21,218.6891,-3571.978,128.8637,0,0,0,0,100,0),
(@PATH,22,182.0998,-3585.068,126.9413,0,0,0,0,100,0),
(@PATH,23,142.9924,-3598.415,127.4793,0,0,0,0,100,0),
(@PATH,24,117.2668,-3619.316,128.5378,0,0,0,0,100,0),
(@PATH,25,82.99265,-3616.286,127.1898,0,0,0,0,100,0),
(@PATH,26,46.47087,-3625.726,122.0062,0,0,0,0,100,0);

-- Pathing for Razorbeak Skylord Entry: 2659 'TDB FORMAT' 
SET @NPC := 279019;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=262.7331,`position_y`=-3578.041,`position_z`=126.3716 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,262.7331,-3578.041,126.3716,0,0,0,0,100,0),
(@PATH,2,271.6699,-3612.041,124.0265,0,0,0,0,100,0),
(@PATH,3,250.0118,-3641.868,129.8539,0,0,0,0,100,0),
(@PATH,4,235.0116,-3652.491,130.4306,0,0,0,0,100,0),
(@PATH,5,196.4548,-3664.036,134.3685,0,0,0,0,100,0),
(@PATH,6,188.6865,-3677.475,132.8554,0,0,0,0,100,0),
(@PATH,7,199.719,-3703.632,134.938,0,0,0,0,100,0),
(@PATH,8,172.6593,-3728.735,132.5708,0,0,0,0,100,0),
(@PATH,9,154.3199,-3765.914,126.158,0,0,0,0,100,0),
(@PATH,10,131.8654,-3785.077,125.3899,0,0,0,0,100,0),
(@PATH,11,107.0458,-3822.554,124.7163,0,0,0,0,100,0),
(@PATH,12,101.3766,-3854.933,131.8144,0,0,0,0,100,0),
(@PATH,13,85.58637,-3883.758,135.753,0,0,0,0,100,0),
(@PATH,14,75.38227,-3910.458,139.9388,0,0,0,0,100,0),
(@PATH,15,47.69358,-3925.983,143.0528,0,0,0,0,100,0),
(@PATH,16,21.89583,-3944.484,140.2773,0,0,0,0,100,0),
(@PATH,17,47.69358,-3925.983,143.0528,0,0,0,0,100,0),
(@PATH,18,75.38227,-3910.458,139.9388,0,0,0,0,100,0),
(@PATH,19,85.58637,-3883.758,135.753,0,0,0,0,100,0),
(@PATH,20,101.3766,-3854.933,131.8144,0,0,0,0,100,0),
(@PATH,21,107.0458,-3822.554,124.7163,0,0,0,0,100,0),
(@PATH,22,131.8654,-3785.077,125.3899,0,0,0,0,100,0),
(@PATH,23,154.3199,-3765.914,126.158,0,0,0,0,100,0),
(@PATH,24,172.6593,-3728.735,132.5708,0,0,0,0,100,0),
(@PATH,25,199.719,-3703.632,134.938,0,0,0,0,100,0),
(@PATH,26,188.6865,-3677.475,132.8554,0,0,0,0,100,0),
(@PATH,27,196.4548,-3664.036,134.3685,0,0,0,0,100,0),
(@PATH,28,235.0116,-3652.491,130.4306,0,0,0,0,100,0),
(@PATH,29,250.0118,-3641.868,129.8539,0,0,0,0,100,0),
(@PATH,30,271.6699,-3612.041,124.0265,0,0,0,0,100,0);

-- Pathing for Razorbeak Skylord Entry: 2659 'TDB FORMAT' 
SET @NPC := 278736;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=106.3129,`position_y`=-4043.603,`position_z`=130.738 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,106.3129,-4043.603,130.738,0,0,0,0,100,0),
(@PATH,2,138.7693,-4030.442,127.7043,0,0,0,0,100,0),
(@PATH,3,140.8691,-3996.71,125.0627,0,0,0,0,100,0),
(@PATH,4,173.6798,-3996.068,122.7942,0,0,0,0,100,0),
(@PATH,5,208.9996,-4009.34,118.9548,0,0,0,0,100,0),
(@PATH,6,234.1293,-3995.892,119.9531,0,0,0,0,100,0),
(@PATH,7,256.9539,-4001.861,118.9069,0,0,0,0,100,0),
(@PATH,8,281.8058,-4024.987,119.4351,0,0,0,0,100,0),
(@PATH,9,309.3736,-4038.102,118.4895,0,0,0,0,100,0),
(@PATH,10,345.3002,-4036.675,118.7776,0,0,0,0,100,0),
(@PATH,11,369.2647,-4020.886,122.8615,0,0,0,0,100,0),
(@PATH,12,381.0846,-4001.104,125.9293,0,0,0,0,100,0),
(@PATH,13,398.5263,-3998.49,125.911,0,0,0,0,100,0),
(@PATH,14,381.0846,-4001.104,125.9293,0,0,0,0,100,0),
(@PATH,15,369.2647,-4020.886,122.8615,0,0,0,0,100,0),
(@PATH,16,345.3002,-4036.675,118.7776,0,0,0,0,100,0),
(@PATH,17,309.3736,-4038.102,118.4895,0,0,0,0,100,0),
(@PATH,18,281.8058,-4024.987,119.4351,0,0,0,0,100,0),
(@PATH,19,256.9539,-4001.861,118.9069,0,0,0,0,100,0),
(@PATH,20,234.1293,-3995.892,119.9531,0,0,0,0,100,0),
(@PATH,21,208.9996,-4009.34,118.9548,0,0,0,0,100,0),
(@PATH,22,173.6798,-3996.068,122.7942,0,0,0,0,100,0),
(@PATH,23,140.8691,-3996.71,125.0627,0,0,0,0,100,0),
(@PATH,24,138.7693,-4030.442,127.7043,0,0,0,0,100,0);

-- Pathing for Wildhammer Warrior Entry: 42518 'TDB FORMAT' 
SET @NPC := 278729;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=86.63715,`position_y`=-4041.835,`position_z`=131.2856 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,86.63715,-4041.835,131.2856,0,0,0,0,100,0),
(@PATH,2,103.0781,-4035.844,128.5721,0,0,0,0,100,0),
(@PATH,3,126.9271,-4032.019,128.5479,0,0,0,0,100,0),
(@PATH,4,146.1267,-4041.332,123.6263,0,0,0,0,100,0),
(@PATH,5,126.9271,-4032.019,128.5479,0,0,0,0,100,0),
(@PATH,6,103.0781,-4035.844,128.5721,0,0,0,0,100,0);
--