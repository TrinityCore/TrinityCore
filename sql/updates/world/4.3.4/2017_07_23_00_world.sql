SET @OGUID := 235445;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 206789, 0, 0, 0, 1, 169, 0, -4992.544, 791.9916, 283.4222, 1.518432, 0.7152414, 0.6345606, -0.2739201, 0.1035873, 120, 255, 1, 23420),
(@OGUID+1, 206790, 0, 0, 0, 1, 169, 0, -4980.938, 790.9554, 283.4357, 4.607669, 0.6647811, -0.7047586, 0.2237301, 0.1064246, 120, 255, 1, 23420),
(@OGUID+2, 206791, 0, 0, 0, 1, 169, 0, -4993.368, 784.9834, 288.3069, 1.483528, 0.7253327, 0.6536493, -0.1819706, 0.116283, 120, 255, 1, 23420),
(@OGUID+3, 206792, 0, 0, 0, 1, 169, 0, -4981.317, 784.0011, 288.3503, 4.459317, 0.6060166, -0.7684984, 0.1564426, 0.132965, 120, 255, 1, 23420),
(@OGUID+4, 206793, 0, 0, 0, 1, 169, 0, -4992.336, 801.3435, 276.7948, 1.343903, -0.7821798, -0.6197767, 0.06066322, 0.01978443, 120, 255, 1, 23420),
(@OGUID+5, 206794, 0, 0, 0, 1, 169, 0, -4980.197, 800.079, 276.7903, 4.895649, -0.7685475, 0.6388483, -0.02767658, 0.0210117, 120, 255, 1, 23420),
(@OGUID+6, 206802, 0, 0, 0, 1, 169, 0, -5002.127, 775.9336, 289.0901, 5.99542, -0.989562, 0.1434259, 0.01270771, 0.005874614, 120, 255, 1, 23420),
(@OGUID+7, 206804, 0, 0, 0, 1, 169, 0, -5002.799, 762.9793, 289.0901, 3.429783, -0.1435304, 0.9895468, -0.001960754, 0.01386882, 120, 255, 1, 23420),
(@OGUID+8, 206806, 0, 0, 0, 1, 169, 0, -5018.079, 764.6555, 286.7074, 3.080507, 0.03108454, 0.9959307, -0.01033211, 0.08395882, 120, 255, 1, 23420),
(@OGUID+9, 206808, 0, 0, 0, 1, 169, 0, -5017.345, 777.0973, 286.6204, 6.222313, -0.9994373, 0.03048229, 0.01328278, 0.004408074, 120, 255, 1, 23420),
(@OGUID+10, 206810, 0, 0, 0, 1, 169, 0, -5031.533, 767.2573, 283.763, 3.037085, 0.05227757, 0.9985342, -0.004621506, 0.01323548, 120, 255, 1, 23420),
(@OGUID+11, 206812, 0, 0, 0, 1, 169, 0, -5052.666, 768.7577, 283.763, 3.063264, 0.03920317, 0.9991331, -0.004447937, 0.0132782, 120, 255, 1, 23420),
(@OGUID+12, 206814, 0, 0, 0, 1, 169, 0, -5075.226, 770.7531, 283.763, 3.037085, 0.05227757, 0.9985342, -0.004621506, 0.01323548, 120, 255, 1, 23420),
(@OGUID+13, 206816, 0, 0, 0, 1, 169, 0, -5095.867, 772.1594, 283.763, 3.037085, 0.05227757, 0.9985342, -0.004621506, 0.01323548, 120, 255, 1, 23420),
(@OGUID+14, 206818, 0, 0, 0, 1, 169, 0, -5030.677, 776.4708, 283.763, 6.196132, -0.9989529, 0.04356194, 0.01322556, 0.004541278, 120, 255, 1, 23420),
(@OGUID+15, 206820, 0, 0, 0, 1, 169, 0, -5051.743, 778.4418, 283.763, 6.196132, -0.9989529, 0.04356194, 0.01322556, 0.004541278, 120, 255, 1, 23420),
(@OGUID+16, 206822, 0, 0, 0, 1, 169, 0, -5074.55, 780.2567, 283.763, 6.196132, -0.9989529, 0.04356194, 0.01322556, 0.004541278, 120, 255, 1, 23420),
(@OGUID+17, 206824, 0, 0, 0, 1, 169, 0, -5094.733, 781.8713, 283.763, 6.196132, -0.9989529, 0.04356194, 0.01322556, 0.004541278, 120, 255, 1, 23420),
(@OGUID+18, 206795, 0, 0, 0, 1, 169, 0, -4992.346, 801.2899, 276.7692, 1.48374, 0.7371693, 0.6755629, -0.01253891, 0.006253051, 120, 255, 1, 23420),
(@OGUID+19, 206796, 0, 0, 0, 1, 169, 0, -4980.188, 800.0949, 276.8547, 4.97419, -0.7927885, 0.6078157, -0.03422737, 0.02957731, 120, 255, 1, 23420),
(@OGUID+20, 206797, 0, 0, 0, 1, 169, 0, -4980.953, 790.9731, 283.4774, 4.69494, 0.7000589, -0.6685724, 0.2469597, 0.04403812, 120, 255, 1, 23420),
(@OGUID+21, 206798, 0, 0, 0, 1, 169, 0, -4992.568, 792.0013, 283.4006, 1.50098, 0.7150755, 0.6514244, -0.2124367, 0.1385061, 120, 255, 1, 23420),
(@OGUID+22, 206799, 0, 0, 0, 1, 169, 0, -4993.366, 784.9441, 288.2817, 1.439898, 0.7356267, 0.6487494, -0.1370955, 0.1385007, 120, 255, 1, 23420),
(@OGUID+23, 206800, 0, 0, 0, 1, 169, 0, -4981.352, 783.9689, 288.3767, 4.546583, 0.6434474, -0.7347307, 0.18999, 0.1002494, 120, 255, 1, 23420),
(@OGUID+24, 206801, 0, 0, 0, 1, 169, 0, -5002.153, 775.9199, 289.0848, 6.003932, -0.9895186, 0.1389713, -0.007866859, 0.0384442, 120, 255, 1, 23420),
(@OGUID+25, 206803, 0, 0, 0, 1, 169, 0, -5002.784, 763.006, 289.0848, 3.438316, -0.1477904, 0.9882393, -0.03909206, 0.00358812, 120, 255, 1, 23420),
(@OGUID+26, 206805, 0, 0, 0, 1, 169, 0, -5018.057, 764.6747, 286.7074, 3.089233, 0.02907419, 0.9962883, -0.04531384, 0.06716397, 120, 255, 1, 23420),
(@OGUID+27, 206807, 0, 0, 0, 1, 169, 0, -5017.368, 777.0768, 286.6204, 6.230826, -0.9988899, 0.02606106, -0.003464699, 0.03908614, 120, 255, 1, 23420),
(@OGUID+28, 206809, 0, 0, 0, 1, 169, 0, -5031.51, 767.2747, 283.763, 3.045589, -0.04784489, -0.9980831, 0.03899956, 0.004468507, 120, 255, 1, 23420),
(@OGUID+29, 206811, 0, 0, 0, 1, 169, 0, -5052.644, 768.7751, 283.763, 3.071767, -0.03477669, -0.9986238, 0.03905296, 0.003974321, 120, 255, 1, 23420),
(@OGUID+30, 206813, 0, 0, 0, 1, 169, 0, -5075.202, 770.7708, 283.763, 3.045589, -0.04784489, -0.9980831, 0.03899956, 0.004468507, 120, 255, 1, 23420),
(@OGUID+31, 206815, 0, 0, 0, 1, 169, 0, -5095.845, 772.176, 283.763, 3.045589, -0.04784489, -0.9980831, 0.03899956, 0.004468507, 120, 255, 1, 23420),
(@OGUID+32, 206817, 0, 0, 0, 1, 169, 0, -5030.699, 776.4538, 283.763, 6.204648, -0.9984632, 0.03913307, -0.003975868, 0.0390396, 120, 255, 1, 23420),
(@OGUID+33, 206819, 0, 0, 0, 1, 169, 0, -5051.767, 778.4254, 283.763, 6.204648, -0.9984632, 0.03913307, -0.003975868, 0.0390396, 120, 255, 1, 23420),
(@OGUID+34, 206821, 0, 0, 0, 1, 169, 0, -5074.572, 780.2388, 283.763, 6.204648, -0.9984632, 0.03913307, -0.003975868, 0.0390396, 120, 255, 1, 23420),
(@OGUID+35, 206823, 0, 0, 0, 1, 169, 0, -5094.757, 781.8549, 283.763, 6.204648, -0.9984632, 0.03913307, -0.003975868, 0.0390396, 120, 255, 1, 23420),
(@OGUID+36, 204041, 0, 0, 0, 1, 169, 0, -5528.564, 695.3993, 376.0688, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+37, 204041, 0, 0, 0, 1, 169, 0, -5528.04, 694.4618, 375.96, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+38, 204041, 0, 0, 0, 1, 169, 0, -5524.741, 698.5226, 375.7831, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+39, 204041, 0, 0, 0, 1, 169, 0, -5521.247, 700.0382, 375.8384, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+40, 204041, 0, 0, 0, 1, 169, 0, -5527.807, 695.4722, 376.0211, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+41, 204041, 0, 0, 0, 1, 169, 0, -5519.471, 699.7257, 375.7709, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+42, 204041, 0, 0, 0, 1, 169, 0, -5529.175, 696, 376.1782, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+43, 204041, 0, 0, 0, 1, 169, 0, -5528.526, 696.1285, 376.071, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+44, 204041, 0, 0, 0, 1, 169, 0, -5525.146, 696.967, 375.6826, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+45, 204041, 0, 0, 0, 1, 169, 0, -5522.064, 698.816, 375.7734, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+46, 204041, 0, 0, 0, 1, 169, 0, -5520.741, 699.6059, 375.8032, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+47, 204041, 0, 0, 0, 1, 169, 0, -5523.179, 697.5174, 375.6854, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+48, 204041, 0, 0, 0, 1, 169, 0, -5521.229, 698.5799, 375.7239, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+49, 204041, 0, 0, 0, 1, 169, 0, -5520.615, 698.8958, 375.7323, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+50, 204041, 0, 0, 0, 1, 169, 0, -5523.984, 698.1563, 375.76, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+51, 204041, 0, 0, 0, 1, 169, 0, -5527.806, 696.467, 375.9571, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+52, 204041, 0, 0, 0, 1, 169, 0, -5524.002, 697.3785, 375.6923, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+53, 204041, 0, 0, 0, 1, 169, 0, -5525.835, 696.7969, 375.6837, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+54, 204041, 0, 0, 0, 1, 169, 0, -5521.34, 699.3837, 375.8027, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+55, 204041, 0, 0, 0, 1, 169, 0, -5518.179, 701.4861, 376.1995, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+56, 204041, 0, 0, 0, 1, 169, 0, -5518.427, 700.4375, 375.9195, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+57, 204041, 0, 0, 0, 1, 169, 0, -5518.012, 700.7604, 376.0291, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+58, 204041, 0, 0, 0, 1, 169, 0, -5518.597, 701.1024, 376.0438, 2.391098, 0, 0, 0.9304171, 0.3665025, 120, 255, 1, 23420),
(@OGUID+59, 204042, 0, 0, 0, 1, 169, 0, -5523.212, 708.6893, 376.9246, 6.230826, 0, 0, -0.02617645, 0.9996573, 120, 255, 1, 23420);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES
(@OGUID+0, 18, 1000),
(@OGUID+1, 18, 1000),
(@OGUID+2, 18, 1000),
(@OGUID+3, 18, 1000),
(@OGUID+4, 18, 1000),
(@OGUID+5, 18, 1000),
(@OGUID+6, 18, 1000),
(@OGUID+7, 18, 1000),
(@OGUID+8, 18, 1000),
(@OGUID+9, 18, 1000),
(@OGUID+10, 18, 1000),
(@OGUID+11, 18, 1000),
(@OGUID+12, 18, 1000),
(@OGUID+13, 18, 1000),
(@OGUID+14, 18, 1000),
(@OGUID+15, 18, 1000),
(@OGUID+16, 18, 1000),
(@OGUID+17, 18, 1000),
(@OGUID+18, 19, 1000),
(@OGUID+19, 19, 1000),
(@OGUID+20, 19, 1000),
(@OGUID+21, 19, 1000),
(@OGUID+22, 19, 1000),
(@OGUID+23, 19, 1000),
(@OGUID+24, 19, 1000),
(@OGUID+25, 19, 1000),
(@OGUID+26, 19, 1000),
(@OGUID+27, 19, 1000),
(@OGUID+28, 19, 1000),
(@OGUID+29, 19, 1000),
(@OGUID+30, 19, 1000),
(@OGUID+31, 19, 1000),
(@OGUID+32, 19, 1000),
(@OGUID+33, 19, 1000),
(@OGUID+34, 19, 1000),
(@OGUID+35, 19, 1000),
(@OGUID+36, 8, 1000),
(@OGUID+37, 8, 1000),
(@OGUID+38, 8, 1000),
(@OGUID+39, 8, 1000),
(@OGUID+40, 8, 1000),
(@OGUID+41, 8, 1000),
(@OGUID+42, 8, 1000),
(@OGUID+43, 8, 1000),
(@OGUID+44, 8, 1000),
(@OGUID+45, 8, 1000),
(@OGUID+46, 8, 1000),
(@OGUID+47, 8, 1000),
(@OGUID+48, 8, 1000),
(@OGUID+49, 8, 1000),
(@OGUID+50, 8, 1000),
(@OGUID+51, 8, 1000),
(@OGUID+52, 8, 1000),
(@OGUID+53, 8, 1000),
(@OGUID+54, 8, 1000),
(@OGUID+55, 8, 1000),
(@OGUID+56, 8, 1000),
(@OGUID+57, 8, 1000),
(@OGUID+58, 8, 1000),
(@OGUID+59, 8, 1000);

-- 204047
UPDATE `gameobject` SET `state`=0 WHERE `guid`=200360;
DELETE FROM `gameobject_addon` WHERE `guid`=200360;
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES (200360, 8, 1000);

-- Add quest invisibility spells for gameobjects
DELETE FROM `spell_area` WHERE `spell` IN (88957,88958,79701);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(88957,5495,28167,28169,0,64,2,1,74,1),(88958,5495,28169,27635,0,64,2,1,74,11),(79701,135,26318,0,0,64,2,1,10,0);

-- Remove scripted and overspawns
DELETE FROM `creature` WHERE `guid` IN (304869,304870,304871,304806,304807,304808,304876,304877,304878,304960,304961,304962,304963,304964,304965,305095,305096,305097,305103,305104,305105,305115,305116);
DELETE FROM `creature` WHERE `guid` IN (304446,304447,304809,304810,304811,304867,304868,304967,304969,304998,304999,305000,305002,305003,305023,305024,305183,305185,305188,305205,305223,305417,305418);
DELETE FROM `creature` WHERE `guid` IN (306206,304435,304436,304438,304439,304442,304443,304444,305561,305562,305117,305239,305240,305241,305419,305420,305422,305423,305425,305431,305518);
DELETE FROM `creature` WHERE `guid` IN (304437,304440,305560,305557,305558,305554,305555,305424,305421,305001,305184,305022,304866,304968,305559,305556,304606,304567);
DELETE FROM `creature` WHERE `guid` IN (304485,304574,304498,304620,304465,304480,304552,304573,304539,304569,304554,304665,304612,304690,304669,304688,304571,304483,304484,304560,304705,304650,304661,304651,304466,304549,304678,304686,304605);
DELETE FROM `creature` WHERE `guid` IN (304531,304634,304621,304622,304551,304706,304691,304604,304545,304660,304734,304721,304830,304794,304796,304798,304800,304865,304942,304879);
DELETE FROM `creature` WHERE `guid` IN (304703,304750,304577,304578,304487,304488,304497,304468,304469,304541,304565,304594,304582,305331,305333,305294,304884,304887,304791,304792,304519,304520,304521,304522,304523,304524,304525);

DELETE FROM `creature_addon` WHERE `guid` IN (304869,304870,304871,304806,304807,304808,304876,304877,304878,304960,304961,304962,304963,304964,304965,305095,305096,305097,305103,305104,305105,305115,305116);
DELETE FROM `creature_addon` WHERE `guid` IN (304446,304447,304809,304810,304811,304867,304868,304967,304969,304998,304999,305000,305002,305003,305023,305024,305183,305185,305188,305205,305223,305417,305418);
DELETE FROM `creature_addon` WHERE `guid` IN (306206,304435,304436,304438,304439,304442,304443,304444,305561,305562,305117,305239,305240,305241,305419,305420,305422,305423,305425,305431,305518);
DELETE FROM `creature_addon` WHERE `guid` IN (304437,304440,305560,305557,305558,305554,305555,305424,305421,305001,305184,305022,304866,304968,305559,305556,304606,304567);
DELETE FROM `creature_addon` WHERE `guid` IN (304485,304574,304498,304620,304465,304480,304552,304573,304539,304569,304554,304665,304612,304690,304669,304688,304571,304483,304484,304560,304705,304650,304661,304651,304466,304549,304678,304686,304605);
DELETE FROM `creature_addon` WHERE `guid` IN (304531,304634,304621,304622,304551,304706,304691,304604,304545,304660,304734,304721,304830,304794,304796,304798,304800,304865,304942,304879);
DELETE FROM `creature_addon` WHERE `guid` IN (304703,304750,304577,304578,304487,304488,304497,304468,304469,304541,304565,304594,304582,305331,305333,305294,304884,304887,304791,304792,304519,304520,304521,304522,304523,304524,304525);

-- Remove all spawned Captured Demolitionist
DELETE FROM `creature` WHERE `id`=42645;

-- Remove all Toxic Pool Go's
DELETE FROM `gameobject` WHERE `id`=203975;

-- fix some triggers
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128 WHERE `entry` IN (42894,43235,43422,46165);
UPDATE `creature_template` SET `InhabitType`=3,`flags_extra`=128 WHERE `entry` IN (42739,42763,42929);

-- Add random movement to misc creatures
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id` IN (1132,42286,42290);

-- Fix some spawns
UPDATE `creature` SET `position_x`=-5150.5,`position_y`=765.795,`position_z`=287.4803,`orientation`=6.108647 WHERE `guid`=304759;
UPDATE `creature` SET `position_x`=-5144.01,`position_y`=754.917,`position_z`=287.4803,`orientation`=0.541062 WHERE `guid`=304762;
UPDATE `creature` SET `position_x`=-5151.06,`position_y`=758.479,`position_z`=287.4803,`orientation`=6.120391 WHERE `guid`=304764;
DELETE FROM `creature_addon` WHERE `guid` IN (304759,304762,304764);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(304759,0,0,0,2,0, '78174'),(304762,0,0,0,2,0, '78174'),(304764,0,0,0,2,0, '78174');

-- Sparking Console
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128 WHERE `entry` IN (46085);

-- S.A.F.E. Operative <S.A.F.E.>
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry` IN (45847);
-- S.A.F.E. Operative <S.A.F.E.> Standstate/Emotestate update
DELETE FROM `creature_addon` WHERE `guid` IN (304957,304959,304771,304769,304768,304625,304626,304627,304587,304588,304589,304593,304602,
304609,304610,304615,304616,304617,304713,304714,304715,304647,304653,304592);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(304957,0,0,1,1,0, ''),(304959,0,0,1,1,0, ''),(304771,0,0,1,1,0, ''),(304769,0,0,1,1,0, ''),(304768,0,0,0,1,69, ''),
(304625,0,0,0,2,0, '78174'),(304626,0,0,0,2,0, '78174'),(304627,0,0,0,2,0, '78174'),(304587,0,0,0,2,0, '78174'),(304588,0,0,0,2,0, '78174'),
(304589,0,0,0,2,0, '78174'),(304593,0,0,0,2,0, '78174'),(304602,0,0,0,2,0, '78174'),(304609,0,0,0,2,0, '78174'),(304610,0,0,0,2,0, '78174'),
(304615,0,0,0,2,0, '78174'),(304616,0,0,0,2,0, '78174'),(304617,0,0,0,2,0, '78174'),(304713,0,0,0,2,0, '78174'),(304714,0,0,0,2,0, '78174'),
(304715,0,0,0,2,0, '78174'),(304647,0,0,0,2,0, '78174'),(304653,0,0,0,2,0, '78174'),(304592,0,0,0,2,0, '78174');

-- Target Acquisition Device
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (46012);

-- S.A.F.E. Operative SAI
SET @ENTRY := 45847;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'You''re doing well... you''re going to be fine.', 12, 0, 100, 1, 0, 0, 46503, 'S.A.F.E. Operative'),
(@ENTRY, 1, 0, 'Our men have secured the walkway. Focus on helping those in the main room.', 12, 0, 100, 1, 0, 0, 47758, 'S.A.F.E. Operative');

-- Nevin Twistwrench SAI
SET @ENTRY := 45966;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,28167,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,85,80653,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Irradiated'"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,60000,60000,12,46449,1,58000,0,0,0,8,0,0,0,-4958.17,827.382,285.8983,2.722714,"Nevin Twistwrench - OOC - Spawn 'S.A.F.E. Operative'");
-- Nevin Twistwrench text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'We have to break through those mindless leper gnomes if we want to get out of here alive!', 12, 0, 100, 25, 0, 0, 46382, 'Nevin Twistwrench');

-- Injured Gnome
SET @ENTRY := 46447;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,3,1,0, '');
-- S.A.F.E. Operative
DELETE FROM `vehicle_template_accessory` WHERE `entry`=46449;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(46449,46447,0,0,'S.A.F.E. Operative - Injured Gnome', 5, 0);
-- S.A.F.E. Operative
DELETE FROM `creature_addon` WHERE `guid` IN (304583,304595);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`,`aiAnimKit`) VALUES (304583,0,0,8,1,0, '',989),(304595,0,0,8,1,0, '',989);
DELETE FROM `creature_template_addon` WHERE `entry`=46449;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`,`aiAnimKit`) VALUES (46449,0,0,0,1,0, '',989);
-- Fix spell click for S.A.F.E. Operative
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=46449;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46449, 46598, 0, 0);

-- Areatrigger SAI
SET @ENTRY := 6454;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,304675,45847,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1 for S.A.F.E. Operative");

-- Areatrigger SAI
SET @ENTRY := 6455;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,304611,45847,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1 for S.A.F.E. Operative");

-- Areatrigger SAI
SET @ENTRY := 6427;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,304738,46025,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1 for S.A.F.E. Officer");

-- Pathing for S.A.F.E. Officer Entry: 46025
SET @NPC := 304802;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5174.54,`position_y`=694.491,`position_z`=288.0847 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5174.54,694.491,288.0847,0,0,0,0,100,0),
(@PATH,2,-5171.23,697.672,288.0847,0,0,0,0,100,0),
(@PATH,3,-5165.63,697.339,288.0847,0,0,0,0,100,0),
(@PATH,4,-5162.28,700.821,288.0846,0,0,0,0,100,0),
(@PATH,5,-5162.5,706.267,288.0846,0,0,0,0,100,0),
(@PATH,6,-5163.45,699.13,288.0846,0,0,0,0,100,0),
(@PATH,7,-5186.228,702.2438,287.3966,0,0,0,0,100,0),
(@PATH,8,-5190.88,706.243,288.0846,0,0,0,0,100,0),
(@PATH,9,-5192.31,712.806,288.0847,0,0,0,0,100,0),
(@PATH,10,-5192.3,726.49,288.0847,0,0,0,0,100,0),
(@PATH,11,-5188.57,730.585,288.0847,0,0,0,0,100,0),
(@PATH,12,-5182.98,733.458,287.3966,0,0,0,0,100,0),
(@PATH,13,-5179.74,740.569,287.3966,0,0,0,0,100,0),
(@PATH,14,-5173.1,749.821,287.3966,0,0,0,0,100,0),
(@PATH,15,-5169.34,756.757,285.4735,0,0,0,0,100,0),
(@PATH,16,-5161.67,770.976,285.4735,0,0,0,0,100,0),
(@PATH,17,-5164.83,773.25,285.4735,0,0,0,0,100,0),
(@PATH,18,-5170.41,773.576,285.4735,0,0,0,0,100,0),
(@PATH,19,-5171.09,773.307,285.4735,0,0,0,0,100,0),
(@PATH,20,-5177.56,773.984,285.4735,0,0,0,0,100,0),
(@PATH,21,-5181.96,770.342,285.4735,0,0,0,0,100,0),
(@PATH,22,-5182.8,764.394,285.4735,0,0,0,0,100,0),
(@PATH,23,-5178.91,762.078,285.4735,0,0,0,0,100,0),
(@PATH,24,-5175.96,758.773,285.4735,0,0,0,0,100,0),
(@PATH,25,-5174.99,753.215,287.3966,0,0,0,0,100,0),
(@PATH,26,-5175.83,742.33,287.3966,0,0,0,0,100,0),
(@PATH,27,-5180.01,736.88,287.3966,0,0,0,0,100,0),
(@PATH,28,-5184.59,732.028,288.0847,0,0,0,0,100,0),
(@PATH,29,-5188.63,730.26,288.0847,0,0,0,0,100,0),
(@PATH,30,-5191.72,729.444,288.0847,0,0,0,0,100,0),
(@PATH,31,-5192.98,707.752,288.0846,0,0,0,0,100,0),
(@PATH,32,-5186.28,704.604,288.0847,0,0,0,0,100,0),
(@PATH,33,-5180.88,698.278,288.0847,0,0,0,0,100,0),
(@PATH,34,-5179.07,689.382,288.0846,0,0,0,0,100,0),
(@PATH,35,-5180.31,683.691,287.7935,0,0,0,0,100,0),
(@PATH,36,-5191.8,677.115,287.7935,0,0,0,0,100,0),
(@PATH,37,-5190.27,665.979,287.7935,0,0,0,0,100,0),
(@PATH,38,-5182.36,661.24,287.7935,0,0,0,0,100,0),
(@PATH,39,-5172.09,660.498,287.7935,0,0,0,0,100,0),
(@PATH,40,-5162.96,666.186,287.7935,0,0,0,0,100,0),
(@PATH,41,-5162.76,674.427,287.7935,0,0,0,0,100,0),
(@PATH,42,-5167.66,681.953,287.7935,0,0,0,0,100,0),
(@PATH,43,-5172.3,684.665,287.7935,0,0,0,0,100,0),
(@PATH,44,-5174.32,689.691,288.0846,0,0,0,0,100,0);

-- Carvo Blastbolt <S.A.F.E.> SAI
SET @ENTRY := 47250;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,28171,0,0,0,85,80653,0,0,0,0,0,7,0,0,0,0,0,0,0,"Carvo Blastbolt <S.A.F.E.> - On Quest Accept - Invoker Cast 'Irradiated'"),
(@ENTRY,0,1,2,19,0,100,0,28169,0,0,0,85,80653,0,0,0,0,0,7,0,0,0,0,0,0,0,"Carvo Blastbolt <S.A.F.E.> - On Quest Accept - Invoker Cast 'Irradiated'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,85,88988,0,0,0,0,0,7,0,0,0,0,0,0,0,"Carvo Blastbolt <S.A.F.E.> - On Quest Accept - Invoker Cast 'Summon Loading Room Guide'");

-- Add target position for spell 'Summon Loading Room Guide'
DELETE FROM `spell_target_position` WHERE `ID`=88988;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES -- `Orientation`,
(88988,0,0,-4982.15,781.481,288.0833,23420); -- 3.64908,

-- Fix text for Survivor
DELETE FROM `creature_text` WHERE `CreatureID`=46268;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46268, 0, 0, 'Please help me!', 12, 0, 100, 20, 0, 0, 46385, 'Survivor'),
(46268, 0, 1, 'I don''t want to die down here!', 12, 0, 100, 18, 0, 0, 46386, 'Survivor'),
(46268, 0, 2, 'Don''t let them eat me!', 12, 0, 100, 20, 0, 0, 46387, 'Survivor'),
(46268, 0, 3, 'Some help! Anyone!', 12, 0, 100, 18, 0, 0, 46388, 'Survivor'),
(46268, 0, 4, 'I''m too young to die!', 12, 0, 100, 18, 0, 0, 46389, 'Survivor'),
(46268, 0, 5, 'I''m really going to die down here, aren''t I?', 12, 0, 100, 18, 0, 0, 46390, 'Survivor'),
(46268, 0, 6, 'Help! I''m too weak to make it on my own.', 12, 0, 100, 20, 0, 0, 46391, 'Survivor');

DELETE FROM `spell_area` WHERE `spell`=80653;

-- S.A.F.E. Operative SAI
SET @ENTRY := 47836;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,0,1,0, '88989');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - OOC - Load path 'No Repeat'"),
(@ENTRY,0,2,3,40,0,100,0,13,@ENTRY,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP13 - Emote 'OneShotSalute'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP13 - Despawn");
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'You can follow me to the Loading Room, $n.', 12, 0, 100, 25, 0, 0, 48091, 'S.A.F.E. Operative');
-- Pathing for S.A.F.E. Operative
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-4998.53,773.049,288.4843, 'S.A.F.E. Operative'),
(@ENTRY,2,-5008.5,771.33,286.6274, 'S.A.F.E. Operative'),
(@ENTRY,3,-5025.94,771.455,283.8422, 'S.A.F.E. Operative'),
(@ENTRY,4,-5059.79,774.16,283.2598, 'S.A.F.E. Operative'),
(@ENTRY,5,-5074.72,775.346,283.2925, 'S.A.F.E. Operative'),
(@ENTRY,6,-5096.14,776.859,283.315, 'S.A.F.E. Operative'),
(@ENTRY,7,-5104.25,777.34,283.315, 'S.A.F.E. Operative'),
(@ENTRY,8,-5109.37,777.58,286.4388, 'S.A.F.E. Operative'),
(@ENTRY,9,-5120.27,775.512,287.3623, 'S.A.F.E. Operative'),
(@ENTRY,10,-5127.87,767.137,287.3469, 'S.A.F.E. Operative'),
(@ENTRY,11,-5144.27,763.302,287.3963, 'S.A.F.E. Operative'),
(@ENTRY,12,-5156.222,763.1564,287.3966, 'S.A.F.E. Operative'),
(@ENTRY,13,-5173.52,767.115,285.4735, 'S.A.F.E. Operative');

-- Gaffer Coilspring <S.A.F.E.> SAI
SET @ENTRY := 46274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,27635,0,0,0,85,80653,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gaffer Coilspring <S.A.F.E.> - On Quest Accept - Invoker Cast 'Irradiated'");

-- Rescued Survivor Standstate update
DELETE FROM `creature_addon` WHERE `guid` IN (304757,304758,304761,304766,304767,304749,304748,304751,304747,304756);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(304757,0,0,1,1,0, ''),(304758,0,0,8,1,0, ''),(304761,0,0,1,1,0, ''),(304766,0,0,1,1,0, ''),(304767,0,0,8,1,0, ''),(304749,0,0,8,1,0, ''),
(304748,0,0,1,1,0, ''),(304751,0,0,1,1,0, ''),(304747,0,0,8,1,0, ''),(304756,0,0,8,1,0, '');

-- Physician's Assistant
DELETE FROM `creature_addon` WHERE `guid` IN (304763);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (304763,0,0,0,1,69, '');

-- Physician's Assistant SAI
SET @GUID := -304753;
SET @ENTRY := 42552;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-5161.37,`position_y`=775.453,`position_z`=287.3966 WHERE `guid`=304753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GUID) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+2,@ENTRY*100+3,@ENTRY*100+4) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Spawn - Start WP"),
(@GUID,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP1 - Pause WP"),
(@GUID,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP1 - Run Script 1"),
(@GUID,0,3,4,40,0,100,0,9,@ENTRY,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP9 - Pause WP"),
(@GUID,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+3,2,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP9 - Run Script 2"),
(@GUID,0,5,6,40,0,100,0,13,@ENTRY,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP13 - Pause WP"),
(@GUID,0,6,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - On Reached WP13 - Run Script 3"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.396263,"Physician's Assistant - Script - Turn to"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Turn run on"),
(@ENTRY*100+2,9,2,0,0,0,100,0,17000,17000,0,0,12,46267,1,45000,0,0,0,8,0,0,0,-5161.76,754.665,286.0393,1.884956,"Physician's Assistant - Script - Spawn 46267"),
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.24115,"Physician's Assistant - Script - Turn to"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Say 0"),
(@ENTRY*100+3,9,2,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Turn run off"),
(@ENTRY*100+4,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.715585,"Physician's Assistant - Script - Turn to"),
(@ENTRY*100+4,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set Emotstate"),
(@ENTRY*100+4,9,2,0,0,0,100,0,13000,13000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set Emotstate");
-- Physician's Assistant path
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5164.96,775.741,287.3966,'Physician''s Assistant'),
(@ENTRY,2,-5160.86,774.091,287.6851,'Physician''s Assistant'),
(@ENTRY,3,-5157.61,772.341,287.6851,'Physician''s Assistant'),
(@ENTRY,4,-5156.61,769.091,287.6851,'Physician''s Assistant'),
(@ENTRY,5,-5155.86,767.091,287.6851,'Physician''s Assistant'),
(@ENTRY,6,-5157.86,766.341,287.6851,'Physician''s Assistant'),
(@ENTRY,7,-5158.86,765.841,286.9351,'Physician''s Assistant'),
(@ENTRY,8,-5159.86,765.341,286.4351,'Physician''s Assistant'),
(@ENTRY,9,-5163.26,763.441,285.4735,'Physician''s Assistant'),
(@ENTRY,10,-5157.01,767.049,287.3966,'Physician''s Assistant'),
(@ENTRY,11,-5156.37,770.106,287.3966,'Physician''s Assistant'),
(@ENTRY,12,-5159.41,773.753,287.3966,'Physician''s Assistant'),
(@ENTRY,13,-5161.37,775.453,287.3966,'Physician''s Assistant');
-- Physician's Assistant text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Ah, a new arrival. Right this way, sir.', 12, 0, 100, 25, 0, 0, 46484, 'Physician''s Assistant');

-- Rescued Survivor SAI
SET @ENTRY := 46267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,7791,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - On Summon - Cast 'Teleport'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - On Summon - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,5,@ENTRY,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - On Reached WP5 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5163.988,759.5958,285.4735,0,"Rescued Survivor - Script - Move to"),
(@ENTRY*100,9,3,0,0,0,100,0,10000,10000,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - Script - Load path"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.380776,"Rescued Survivor - script - Turn to"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rescued Survivor - script - sit");
-- Rescued Survivor text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Thank the Light! I''ve made it.', 12, 0, 100, 1, 0, 0, 46477, 'Rescued Survivor'),
(@ENTRY, 0, 1, 'It''s a relief to be surrounded by normal gnomes again!', 12, 0, 100, 1, 0, 0, 46478, 'Rescued Survivor'),
(@ENTRY, 0, 2, 'I thought I was goner!', 12, 0, 100, 1, 0, 0, 46479, 'Rescued Survivor'),
(@ENTRY, 0, 3, 'You... you''re not going to try to eat me, are you?', 12, 0, 100, 1, 0, 0, 46480, 'Rescued Survivor'),
(@ENTRY, 0, 4, 'I never would''ve made it on my own...', 12, 0, 100, 1, 0, 0, 46481, 'Rescued Survivor'),
(@ENTRY, 0, 5, 'Thank you for getting me out of there!', 12, 0, 100, 1, 0, 0, 46482, 'Rescued Survivor'),
(@ENTRY, 0, 6, 'My family... did you find my family?', 12, 0, 100, 1, 0, 0, 46483, 'Rescued Survivor');
-- Rescued Survivor path
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5163.988,759.5958,285.4735,'Rescued Survivor'),
(@ENTRY,2,-5157.862,764.8845,286.7716,'Rescued Survivor'),
(@ENTRY,3,-5156.11,767.95,287.3966,'Rescued Survivor'),
(@ENTRY,4,-5158.27,773.444,287.3966,'Rescued Survivor'),
(@ENTRY,5,-5159.82,776.925,287.3966,'Rescued Survivor');

-- Fix spell click for Sanitron 500
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=46185;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46185, 86106, 0, 0);

-- Sanitron 500 text
SET @ENTRY := 46185;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Commencing decontamination sequence...', 12, 0, 100, 0, 0, 0, 46323, 'Sanitron 500'),
(@ENTRY, 1, 0, 'Decontamination complete. Standby for delivery.', 12, 0, 100, 0, 0, 0, 46324, 'Sanitron 500'),
(@ENTRY, 2, 0, 'Warning, system overload. Malfunction imminent!', 12, 0, 100, 0, 0, 0, 46325, 'Sanitron 500');

-- Clean Cannon X-2 SAI
SET @ENTRY := 46208;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,3,0,27669,0,0,0,0,1,0,0,0,0,0,0,0,"Clean Cannon X-2  - On Spawn - Set Model"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clean Cannon X-2  - On Spawn - Set Orientaion self");

-- Clean Cannon X-2 
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (46208);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(46208,45847,0,0,'Clean Cannon X-2 - S.A.F.E. Operative <S.A.F.E.>', 5, 0);

-- Fix spell click for Clean Cannon X-2
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (46208);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46208, 46598, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (41761,42563);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(41761,0,0,0,1,0, '16245'),(42563,0,0,0,1,0, '16245');

-- Rockjaw Fungus-Flinger SAI
SET @ENTRY := 43325;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,28,77831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Fungus-Flinger - Aggro - Remove Aura 'Trogg Sleep'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,80944,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Fungus-Flinger - In Combat - Cast 'Fling Fungus'"),
(@ENTRY,0,2,0,9,0,100,0,10,20,17000,22000,11,87347,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Fungus-Flinger - Within 10-20 Range - Cast 'Poisonous Mushroom'");

DELETE FROM `creature_addon` WHERE `guid` IN (304815,304819,304823,304829,304833,304835);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(304815,0,0,0,1,0, '80928 77831'),(304819,0,0,0,1,0, '80928 77831'),(304823,0,0,0,1,0, '80928 77831'),(304829,0,0,0,1,0, '80928 77831'),(304833,0,0,0,1,0, '80928 77831'),(304835,0,0,0,1,0, '80928 77831');

-- Pathing for Boss Bruggor Entry: 42773
SET @NPC := 304817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5527.891,`position_y`=716.5035,`position_z`=377.7816 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80928');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5527.891,716.5035,377.7816,0,0,0,0,100,0),
(@PATH,2,-5534.603,721.5382,377.7835,0,0,0,0,100,0),
(@PATH,3,-5539.186,727.467,378.1595,0,0,0,0,100,0),
(@PATH,4,-5546.078,736.9323,378.257,0,0,0,0,100,0),
(@PATH,5,-5539.186,727.467,378.1595,0,0,0,0,100,0),
(@PATH,6,-5534.603,721.5382,377.7835,0,0,0,0,100,0);

-- Pathing for Rockjaw Fungus-Flinger Entry: 43325
SET @NPC := 304822;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5519.579,`position_y`=658.2942,`position_z`=391.5736 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80928');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5519.579,658.2942,391.5736,0,0,0,0,100,0),
(@PATH,2,-5523.471,661.7014,391.7323,0,0,0,0,100,0),
(@PATH,3,-5519.708,658.4583,391.6187,0,0,0,0,100,0),
(@PATH,4,-5516.212,654.0295,391.832,0,0,0,0,100,0),
(@PATH,5,-5514.806,649.6614,391.47,0,0,0,0,100,0),
(@PATH,6,-5517.073,647.2257,391.0313,0,0,0,0,100,0),
(@PATH,7,-5516.212,654.0295,391.832,0,0,0,0,100,0);

-- Pathing for Rockjaw Fungus-Flinger Entry: 43325
SET @NPC := 304814;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5497.243,`position_y`=636.1989,`position_z`=393.1682 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80928');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5497.243,636.1989,393.1682,0,0,0,0,100,0),
(@PATH,2,-5507.578,640.1667,394.8632,0,0,0,0,100,0),
(@PATH,3,-5513.13,636.4132,393.8445,0,0,0,0,100,0),
(@PATH,4,-5518.698,636.9236,394.3814,0,0,0,0,100,0),
(@PATH,5,-5523.778,640.9549,395.4326,0,0,0,0,100,0),
(@PATH,6,-5518.698,636.9236,394.3814,0,0,0,0,100,0),
(@PATH,7,-5513.13,636.4132,393.8445,0,0,0,0,100,0),
(@PATH,8,-5507.578,640.1667,394.8632,0,0,0,0,100,0);

-- Pathing for Rockjaw Fungus-Flinger Entry: 43325
SET @NPC := 304827;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5545.739,`position_y`=652.4418,`position_z`=391.6404 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80928');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5545.739,652.4418,391.6404,0,0,0,0,100,0),
(@PATH,2,-5555.858,653.2674,389.2505,0,0,0,0,100,0),
(@PATH,3,-5565.984,655.3264,388.8374,0,0,0,0,100,0),
(@PATH,4,-5570.519,662.3577,387.9037,0,0,0,0,100,0),
(@PATH,5,-5571.361,670.0226,386.9476,0,0,0,0,100,0),
(@PATH,6,-5571.639,680.1962,384.6373,0,0,0,0,100,0),
(@PATH,7,-5570.522,693.3299,381.0876,0,0,0,0,100,0),
(@PATH,8,-5571.639,680.1962,384.6373,0,0,0,0,100,0),
(@PATH,9,-5571.361,670.0226,386.9476,0,0,0,0,100,0),
(@PATH,10,-5570.519,662.3577,387.9037,0,0,0,0,100,0),
(@PATH,11,-5565.984,655.3264,388.8374,0,0,0,0,100,0),
(@PATH,12,-5556.008,653.298,389.214,0,0,0,0,100,0);

-- Pathing for Rockjaw Fungus-Flinger Entry: 43325
SET @NPC := 304832;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5515.535,`position_y`=630.0781,`position_z`=393.6012 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '80928');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5515.535,630.0781,393.6012,0,0,0,0,100,0),
(@PATH,2,-5519.882,620.7691,393.7703,0,0,0,0,100,0),
(@PATH,3,-5526.274,613.6198,393.4691,0,0,0,0,100,0),
(@PATH,4,-5533.971,612.6094,394.6785,0,0,0,0,100,0),
(@PATH,5,-5539.453,609.5469,394.0056,0,0,0,0,100,0),
(@PATH,6,-5543.944,601.7726,392.8634,0,0,0,0,100,0),
(@PATH,7,-5544.563,593.6458,393.6307,0,0,0,0,100,0),
(@PATH,8,-5546.088,579.4757,394.8256,0,0,0,0,100,0),
(@PATH,9,-5544.563,593.6458,393.6307,0,0,0,0,100,0),
(@PATH,10,-5543.944,601.7726,392.8634,0,0,0,0,100,0),
(@PATH,11,-5539.453,609.5469,394.0056,0,0,0,0,100,0),
(@PATH,12,-5533.971,612.6094,394.6785,0,0,0,0,100,0),
(@PATH,13,-5526.274,613.6198,393.4691,0,0,0,0,100,0),
(@PATH,14,-5519.882,620.7691,393.7703,0,0,0,0,100,0);

-- Gnomeregan Infantry
DELETE FROM `creature_addon` WHERE `guid` IN (304861,304862,304863,304864,305035);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(304861,0,0,0,258,0, '18950 78174'),(304862,0,0,0,258,0, '18950 78174'),(304863,0,0,0,258,0, '18950 78174'),(304864,0,0,0,258,0, '18950 78174'),(305035,0,0,0,258,0, '18950 78174');

-- Pathing for Gnomeregan Infantry Entry: 42319
SET @NPC := 305242;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5125.31,`position_y`=440.295,`position_z`=396.3953 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6569,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5125.31,440.295,396.3953,0,0,0,0,100,0),
(@PATH,2,-5122.31,430.474,396.7182,0,0,0,0,100,0),
(@PATH,3,-5121.23,416.439,396.7182,0,0,0,0,100,0),
(@PATH,4,-5125.21,401.132,396.7182,0,0,0,0,100,0),
(@PATH,5,-5124.19,377.036,396.6783,0,0,0,0,100,0),
(@PATH,6,-5122.13,347.938,395.8626,0,0,0,0,100,0),
(@PATH,7,-5114.43,323.962,394.2638,0,0,0,0,100,0),
(@PATH,8,-5099.18,306.385,394.2638,0,0,0,0,100,0),
(@PATH,9,-5090.41,298.01,394.3232,0,0,0,0,100,0),
(@PATH,10,-5087.61,279.717,393.7018,0,0,0,0,100,0),
(@PATH,11,-5090.41,298.01,394.3232,0,0,0,0,100,0),
(@PATH,12,-5099.18,306.385,394.2638,0,0,0,0,100,0),
(@PATH,13,-5114.43,323.962,394.2638,0,0,0,0,100,0),
(@PATH,14,-5122.13,347.938,395.8626,0,0,0,0,100,0),
(@PATH,15,-5124.19,377.036,396.6783,0,0,0,0,100,0),
(@PATH,16,-5125.21,401.132,396.7182,0,0,0,0,100,0),
(@PATH,17,-5121.23,416.439,396.7182,0,0,0,0,100,0),
(@PATH,18,-5122.31,430.474,396.7182,0,0,0,0,100,0);

-- Pathing for Gnomeregan Infantry Entry: 42319
SET @NPC := 305447;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5420.238,`position_y`=-126.1302,`position_z`=395.937 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-5420.238,`position_y`=-126.1302,`position_z`=395.937 WHERE `guid`=305448;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,305448);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6569,0,1,0, '18950'),(305448,0,6569,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5420.238,-126.1302,395.937,0,0,0,0,100,0),
(@PATH,2,-5411.441,-94.61459,393.4916,0,0,0,0,100,0),
(@PATH,3,-5395.215,-79.4375,391.8275,0,0,0,0,100,0),
(@PATH,4,-5388.509,-48.77431,391.1765,0,0,0,0,100,0),
(@PATH,5,-5386.528,0.211806,391.1544,0,0,0,0,100,0),
(@PATH,6,-5389.167,32.98785,391.1544,0,0,0,0,100,0),
(@PATH,7,-5407.365,58.6875,393.505,0,0,0,0,100,0),
(@PATH,8,-5414.389,86.5625,393.4214,0,0,0,0,100,0),
(@PATH,9,-5424.365,129.6007,393.482,0,0,0,0,100,0),
(@PATH,10,-5440.771,156.5313,394.3673,0,0,0,0,100,0),
(@PATH,11,-5443.151,201.8559,394.3531,0,0,0,0,100,0),
(@PATH,12,-5439.891,232.0781,394.8531,0,0,0,0,100,0),
(@PATH,13,-5422.262,255.0295,394.6998,0,0,0,0,100,0),
(@PATH,14,-5419.847,279.6267,394.7136,0,0,0,0,100,0),
(@PATH,15,-5414.637,301.7326,394.7037,0,0,0,0,100,0),
(@PATH,16,-5419.847,279.6267,394.7136,0,0,0,0,100,0),
(@PATH,17,-5422.262,255.0295,394.6998,0,0,0,0,100,0),
(@PATH,18,-5439.891,232.0781,394.8531,0,0,0,0,100,0),
(@PATH,19,-5443.151,201.8559,394.3531,0,0,0,0,100,0),
(@PATH,20,-5440.771,156.5313,394.3673,0,0,0,0,100,0),
(@PATH,21,-5424.365,129.6007,393.482,0,0,0,0,100,0),
(@PATH,22,-5414.389,86.5625,393.4214,0,0,0,0,100,0),
(@PATH,23,-5407.365,58.6875,393.505,0,0,0,0,100,0),
(@PATH,24,-5389.167,32.98785,391.1544,0,0,0,0,100,0),
(@PATH,25,-5386.528,0.211806,391.1544,0,0,0,0,100,0),
(@PATH,26,-5388.509,-48.77431,391.1765,0,0,0,0,100,0),
(@PATH,27,-5395.215,-79.4375,391.8275,0,0,0,0,100,0),
(@PATH,28,-5411.441,-94.61459,393.4916,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,305448,2,90,515,1,15);

-- Pathing for Gnomeregan Infantry Entry: 42319
SET @NPC := 305180;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5183.054,`position_y`=460.9375,`position_z`=388.5871 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-5183.054,`position_y`=460.9375,`position_z`=388.5871 WHERE `guid`=305181;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,305181);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6569,0,1,0, '18950'),(305181,0,6569,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5183.054,460.9375,388.5871,0,0,0,0,100,0),
(@PATH,2,-5189.894,449.4132,388.7199,0,0,0,0,100,0),
(@PATH,3,-5220.471,420.9219,390.668,0,0,0,0,100,0),
(@PATH,4,-5251.049,400.8073,392.1854,0,0,0,0,100,0),
(@PATH,5,-5283.846,384.0365,392.7727,0,0,0,0,100,0),
(@PATH,6,-5317.189,376.0278,393.3362,0,0,0,0,100,0),
(@PATH,7,-5342.002,369.0313,394.0493,0,0,0,0,100,0),
(@PATH,8,-5361.646,339.3281,394.6998,0,0,0,0,100,0),
(@PATH,9,-5342.002,369.0313,394.0493,0,0,0,0,100,0),
(@PATH,10,-5317.189,376.0278,393.3362,0,0,0,0,100,0),
(@PATH,11,-5283.846,384.0365,392.7727,0,0,0,0,100,0),
(@PATH,12,-5251.049,400.8073,392.1854,0,0,0,0,100,0),
(@PATH,13,-5220.471,420.9219,390.668,0,0,0,0,100,0),
(@PATH,14,-5189.894,449.4132,388.7199,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,305181,2,90,515,1,8);

-- Pathing for Gnomeregan Infantry Entry: 42319
SET @NPC := 305085;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5095.03,`position_y`=463.3767,`position_z`=404.3729 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-5095.03,`position_y`=463.3767,`position_z`=404.3729 WHERE `guid`=305086;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,305086);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,6569,0,1,0, '18950'),(305086,0,6569,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5095.03,463.3767,404.3729,0,0,0,0,100,0),
(@PATH,2,-5106.811,458.717,402.2605,0,0,0,0,100,0),
(@PATH,3,-5119.035,451.9913,398.0034,0,0,0,0,100,0),
(@PATH,4,-5130.811,449.0313,395.0105,0,0,0,0,100,0),
(@PATH,5,-5159.512,475.0556,390.5904,0,0,0,0,100,0),
(@PATH,6,-5175.925,486.882,388.3117,0,0,0,0,100,0),
(@PATH,7,-5186.391,502.3889,387.8832,0,0,0,0,100,0),
(@PATH,8,-5187.957,516.5087,388.0158,0,0,0,0,100,0),
(@PATH,9,-5188.747,536.0521,389.8044,0,0,0,0,100,0),
(@PATH,10,-5188.016,553.0527,394.6518,0,0,0,0,100,0),
(@PATH,11,-5185.13,568.2049,398.9561,0,0,0,0,100,0),
(@PATH,12,-5183.821,589.1476,405.4956,0,0,0,0,100,0),
(@PATH,13,-5185.13,568.2049,398.9561,0,0,0,0,100,0),
(@PATH,14,-5188.012,553.2778,394.8942,0,0,0,0,100,0),
(@PATH,15,-5188.747,536.0521,389.8044,0,0,0,0,100,0),
(@PATH,16,-5187.957,516.5087,388.0158,0,0,0,0,100,0),
(@PATH,17,-5186.391,502.3889,387.8832,0,0,0,0,100,0),
(@PATH,18,-5175.925,486.882,388.3117,0,0,0,0,100,0),
(@PATH,19,-5159.512,475.0556,390.5904,0,0,0,0,100,0),
(@PATH,20,-5130.811,449.0313,395.0105,0,0,0,0,100,0),
(@PATH,21,-5119.035,451.9913,398.0034,0,0,0,0,100,0),
(@PATH,22,-5106.811,458.717,402.2605,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,305086,2,90,515,1,12);

-- Pathing for Dun Morogh Mountaineer Entry: 13076
SET @NPC := 305229;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5361.591,`position_y`=273.7827,`position_z`=394.3212 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5361.591,273.7827,394.3212,0,0,0,0,100,0),
(@PATH,2,-5374.789,277.4015,394.4011,0,0,0,0,100,0),
(@PATH,3,-5387.133,287.2208,394.364,0,0,0,0,100,0),
(@PATH,4,-5396.016,300.0359,394.864,0,0,0,0,100,0),
(@PATH,5,-5397.955,306.3506,394.614,0,0,0,0,100,0),
(@PATH,6,-5394.629,317.1513,394.614,0,0,0,0,100,0),
(@PATH,7,-5388.861,320.6727,394.614,0,0,0,0,100,0),
(@PATH,8,-5377.084,326.5625,394.864,0,0,0,0,100,0),
(@PATH,9,-5363.929,327.5,394.2086,0,0,0,0,100,0),
(@PATH,10,-5350.521,324.4785,394.4586,0,0,0,0,100,0),
(@PATH,11,-5346.875,314.584,394.5836,0,0,0,0,100,0),
(@PATH,12,-5353.341,304.5788,394.3336,0,0,0,0,100,0),
(@PATH,13,-5344.709,297.2312,394.9048,0,0,0,0,100,0),
(@PATH,14,-5344.167,284.8842,392.7645,0,0,0,0,100,0),
(@PATH,15,-5355.671,286.3484,393.8218,0,0,0,0,100,0);

-- Gnomeregan Trainee SAI
SET @ENTRY := 42329;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,5000,5000,5000,87,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Trainee - OOC - Run Random Script"),
(@ENTRY*100  ,9,0,0,0,0,100,0,0,0,0,0,11,42880,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Attack 1H'"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,11,44079,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Special Attack 1H'"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,11,78959,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Attack 1H (Thrust)'");
UPDATE `creature_template_addon` SET `emote`=333 WHERE entry=42329;

-- Practice Dummy SAI
SET @ENTRY := 42328;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,42880,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Practice Dummy - On Spellhit - Cast 'Wound Impact'"),
(@ENTRY,0,1,0,8,0,100,0,78959,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Practice Dummy - On Spellhit - Cast 'Wound Impact'"),
(@ENTRY,0,2,0,8,0,100,0,44079,0,0,0,11,78961,0,0,0,0,0,1,0,0,0,0,0,0,0,"Practice Dummy - On Spellhit - Cast 'Wound Impact Critical'");

-- Drill Sergeant Steamcrank SAI
SET @ENTRY := 42324;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-5173.221,`position_y`=454.1667,`position_z`=391.5764 WHERE `guid`=305038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Spawn - Start WP"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Gossip Hello - Pause WP"),
(@ENTRY,0,2,3,40,0,100,0,2,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP2 - Pause WP"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP2 - Run Script"),
(@ENTRY,0,4,5,40,0,100,0,3,@ENTRY,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP3 - Pause WP"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP3 - Run Script"),
(@ENTRY,0,6,7,40,0,100,0,5,@ENTRY,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP5 - Pause WP"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP5 - Run Script"),
(@ENTRY,0,8,9,40,0,100,0,6,@ENTRY,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP6 - Pause WP"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Reached WP6 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,42329,5,0,0,0,0,0,"Drill Sergeant Steamcrank - Script - Turn to closest Trainee"),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,10,5,25,273,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - Script - Play random emote");
-- Pathing for Drill Sergeant Steamcrank
SET @ENTRY := @ENTRY;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5173.221,454.1667,390.5764, 'Drill Sergeant Steamcrank'),
(@ENTRY,2,-5173.526,453.4757,390.5863, 'Drill Sergeant Steamcrank'),
(@ENTRY,3,-5158.389,456.6371,392.4055, 'Drill Sergeant Steamcrank'),
(@ENTRY,4,-5162.455,455.5729,392.2448, 'Drill Sergeant Steamcrank'),
(@ENTRY,5,-5163.068,454.2274,392.3141, 'Drill Sergeant Steamcrank'),
(@ENTRY,6,-5167.78,453.7014,391.8134, 'Drill Sergeant Steamcrank');

-- Physician's Assistant SAI
SET @ENTRY := -305079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=42552;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=42552*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,30000,30000,80,42552*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - OOC - Play script"),
(42552*100,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Turn run off"),
(42552*100,9,1,0,0,0,100,0,500,500,500,500,69,0,0,0,0,0,0,8,0,0,0,-5065.667,482.6807,401.6831,0,"Physician's Assistant - Script - Move to"),
(42552*100,9,2,0,0,0,100,0,1500,1500,1500,1500,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100,9,3,0,0,0,100,0,5000,5000,5000,5000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100,9,4,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,8,0,0,0,-5062.813,484.026,401.8641,0,"Physician's Assistant - Script - Move to"),
(42552*100,9,5,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,8,0,0,0,-5062.988,483.9432,401.8529,0,"Physician's Assistant - Script - Move to"),
(42552*100,9,6,0,0,0,100,0,500,500,500,500,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.775074,"Physician's Assistant - Script - Turn to"),
(42552*100,9,7,0,0,0,100,0,500,500,500,500,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100,9,8,0,0,0,100,0,20000,20000,20000,20000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state");

-- Physician's Assistant SAI
SET @ENTRY := -305082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=42552;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=42552*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,30000,30000,80,42552*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - OOC - Play script"),
(42552*100+1,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Turn run off"),
(42552*100+1,9,1,0,0,0,100,0,500,500,500,500,69,0,0,0,0,0,0,8,0,0,0,-5068.816,480.6089,401.8107,0,"Physician's Assistant - Script - Move to"),
(42552*100+1,9,2,0,0,0,100,0,2500,2500,2500,2500,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100+1,9,3,0,0,0,100,0,5000,5000,5000,5000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100+1,9,4,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,8,0,0,0,-5073.549,479.0278,401.6669,0,"Physician's Assistant - Script - Move to"),
(42552*100+1,9,5,0,0,0,100,0,2500,2500,2500,2500,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.500983,"Physician's Assistant - Script - Turn to"),
(42552*100+1,9,6,0,0,0,100,0,1000,1000,1000,1000,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state"),
(42552*100+1,9,7,0,0,0,100,0,18000,18000,18000,18000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Physician's Assistant - Script - Set emote state");

-- Wounded Infantry
DELETE FROM `creature_template_addon` WHERE `entry`=42501;
DELETE FROM `creature_addon` WHERE `guid` IN (305081,305080,305078,305077);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(305081,0,0,8,1,0, '46577'),(305080,0,0,1,1,0, '46577'),(305078,0,0,1,1,0, '46577'),(305077,0,0,3,1,0, '46577');
-- Healing Shield
UPDATE `creature_template` SET `unit_flags2`=2099200, `InhabitType`=4, `flags_extra`=128 WHERE `entry`=42557;

-- Rocket Defence Turrent
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (43259);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(43259,42316,0,0,'Rocket Defence Turrent - Gnomeregan Infantry', 8, 0);

-- Fix spell click for Rocket Defence Turrent
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (43259);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(43259, 46598, 0, 0);

-- Irradiated Technician
DELETE FROM `creature_template_addon` WHERE `entry` IN (42223);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(42223,0,0,0,1,133, '');

-- Irradiated Technician
DELETE FROM `creature_addon` WHERE `guid` IN (305273,305276,305351,305354,305356,305364,305366,305372,305373,305380);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(305273,0,0,0,1,0, '78858'),(305276,0,0,0,1,0, '78858'),(305351,0,0,0,1,0, '78858'),(305354,0,0,0,1,0, '78858'),(305356,0,0,0,1,0, '78858'),
(305364,0,0,0,1,0, '78858'),(305366,0,0,0,1,0, '78858'),(305372,0,0,0,1,0, '78858'),(305373,0,0,0,1,0, '78858'),(305380,0,0,0,1,0, '78858');

-- Missing Mounts
DELETE FROM `creature_template_addon` WHERE `entry` IN (42849,42852);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(42849,0,31692,0,1,0, ''),(42852,0,2786,0,257,0, '');

-- Set Irradiated Cockroach to random movement
UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `id`=48956;

-- Set addon for Toxic Sludge
DELETE FROM `creature_template_addon` WHERE `entry` IN (42184);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (42184,0,0,0,1,0, '78783');

-- Pathing for Living Contamination Entry: 42185
SET @NPC := 304936;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5335.988,`position_y`=520.5104,`position_z`=385.0753 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5335.988,520.5104,385.0753,0,0,0,0,100,0),
(@PATH,2,-5324.955,529.3802,384.7065,0,0,0,0,100,0),
(@PATH,3,-5322.747,544.4896,385.1666,0,0,0,0,100,0),
(@PATH,4,-5317.665,559.1771,385.6061,0,0,0,0,100,0),
(@PATH,5,-5310.064,570.9355,388.3036,0,0,0,0,100,0),
(@PATH,6,-5299.486,574.9132,388.5087,0,0,0,0,100,0),
(@PATH,7,-5291.543,575.3212,386.9976,0,0,0,0,100,0),
(@PATH,8,-5299.486,574.9132,388.5087,0,0,0,0,100,0),
(@PATH,9,-5310.04,570.9792,388.2136,0,0,0,0,100,0),
(@PATH,10,-5317.665,559.1771,385.6061,0,0,0,0,100,0),
(@PATH,11,-5322.747,544.4896,385.1666,0,0,0,0,100,0),
(@PATH,12,-5324.955,529.3802,384.7065,0,0,0,0,100,0);

-- Pathing for Living Contamination Entry: 42185
SET @NPC := 304916;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5488.762,`position_y`=530.0851,`position_z`=388.4988 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5488.762,530.0851,388.4988,0,0,0,0,100,0),
(@PATH,2,-5483.668,559.1771,394.1418,0,0,0,0,100,0),
(@PATH,3,-5488.762,530.0851,388.4988,0,0,0,0,100,0),
(@PATH,4,-5489.656,509.0191,387.3738,0,0,0,0,100,0),
(@PATH,5,-5482.627,487.882,386.1718,0,0,0,0,100,0),
(@PATH,6,-5476.207,475.0521,385.9962,0,0,0,0,100,0),
(@PATH,7,-5482.627,487.882,386.1718,0,0,0,0,100,0),
(@PATH,8,-5489.656,509.0191,387.3738,0,0,0,0,100,0);

-- Pathing for Living Contamination Entry: 42185
SET @NPC := 304934;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5381.647,`position_y`=498.2743,`position_z`=384.616 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5381.647,498.2743,384.616,0,0,0,0,100,0),
(@PATH,2,-5377.075,508.1285,385.2655,0,0,0,0,100,0),
(@PATH,3,-5362.855,515.4414,385.0929,0,0,0,0,100,0),
(@PATH,4,-5377.075,508.1285,385.2655,0,0,0,0,100,0),
(@PATH,5,-5381.647,498.2743,384.616,0,0,0,0,100,0),
(@PATH,6,-5375.323,483.9983,384.6072,0,0,0,0,100,0),
(@PATH,7,-5365.521,478.9635,383.9044,0,0,0,0,100,0),
(@PATH,8,-5360.731,462.2552,385.2377,0,0,0,0,100,0),
(@PATH,9,-5364.658,453.3837,384.2045,0,0,0,0,100,0),
(@PATH,10,-5360.731,462.2552,385.2377,0,0,0,0,100,0),
(@PATH,11,-5365.521,478.9635,383.9044,0,0,0,0,100,0),
(@PATH,12,-5375.323,483.9983,384.6072,0,0,0,0,100,0);

-- Pathing for Living Contamination Entry: 42185
SET @NPC := 304973;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5348.663,`position_y`=465.5764,`position_z`=385.5111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5348.663,465.5764,385.5111,0,0,0,0,100,0),
(@PATH,2,-5334.361,472.151,384.552,0,0,0,0,100,0),
(@PATH,3,-5320.378,480.0955,384.7431,0,0,0,0,100,0),
(@PATH,4,-5312.521,485.1754,384.3111,0,0,0,0,100,0),
(@PATH,5,-5293.266,489.4045,382.8457,0,0,0,0,100,0),
(@PATH,6,-5281.603,489.8195,382.8457,0,0,0,0,100,0),
(@PATH,7,-5293.266,489.4045,382.8457,0,0,0,0,100,0),
(@PATH,8,-5312.521,485.1754,384.3111,0,0,0,0,100,0),
(@PATH,9,-5320.378,480.0955,384.7431,0,0,0,0,100,0),
(@PATH,10,-5334.361,472.151,384.552,0,0,0,0,100,0);

-- Pathing for Living Contamination Entry: 42185
SET @NPC := 305014;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5485.969,`position_y`=442.8559,`position_z`=384.2159 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5485.969,442.8559,384.2159,0,0,0,0,100,0),
(@PATH,2,-5474.757,455.9879,384.7703,0,0,0,0,100,0),
(@PATH,3,-5467.408,464.1858,385.4248,0,0,0,0,100,0),
(@PATH,4,-5438.734,467.3438,385.5319,0,0,0,0,100,0),
(@PATH,5,-5422.363,459.8837,385.9211,0,0,0,0,100,0),
(@PATH,6,-5428.632,450.6858,385.1657,0,0,0,0,100,0),
(@PATH,7,-5437.603,436.9271,386.4043,0,0,0,0,100,0),
(@PATH,8,-5441.721,423.0799,388.4589,0,0,0,0,100,0),
(@PATH,9,-5442.818,409.1806,390.963,0,0,0,0,100,0),
(@PATH,10,-5458.615,402.7118,390.3226,0,0,0,0,100,0),
(@PATH,11,-5474.383,385.9551,392.2984,0,0,0,0,100,0),
(@PATH,12,-5493.778,429.0677,383.1872,0,0,0,0,100,0);

-- Set rest of Living Contamination to random movement
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id`=42185 AND `MovementType`=0;

-- Pathing for Toxic Sludge Entry: 42184
SET @NPC := 304921;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5405.276,`position_y`=559.3577,`position_z`=388.9521 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '78783');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5405.276,559.3577,388.9521,0,0,0,0,100,0),
(@PATH,2,-5420.559,556.2049,389.1217,0,0,0,0,100,0),
(@PATH,3,-5436.835,547.5851,387.546,0,0,0,0,100,0),
(@PATH,4,-5439.604,536.8733,387.1427,0,0,0,0,100,0),
(@PATH,5,-5436.835,547.5851,387.546,0,0,0,0,100,0),
(@PATH,6,-5420.559,556.2049,389.1217,0,0,0,0,100,0),
(@PATH,7,-5405.276,559.3577,388.9521,0,0,0,0,100,0),
(@PATH,8,-5397.918,549.408,386.3442,0,0,0,0,100,0),
(@PATH,9,-5367.174,546.5625,386.5459,0,0,0,0,100,0),
(@PATH,10,-5352.66,563.882,384.3105,0,0,0,0,100,0),
(@PATH,11,-5367.174,546.5625,386.5459,0,0,0,0,100,0),
(@PATH,12,-5397.918,549.408,386.3442,0,0,0,0,100,0);

-- Pathing for Toxic Sludge Entry: 42184
SET @NPC := 305010;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5402.78,`position_y`=468.7361,`position_z`=385.6003 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '78783');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5402.78,468.7361,385.6003,0,0,0,0,100,0),
(@PATH,2,-5395.064,458.5347,384.6376,0,0,0,0,100,0),
(@PATH,3,-5382.682,444.3073,385.997,0,0,0,0,100,0),
(@PATH,4,-5370.835,426.7431,384.9478,0,0,0,0,100,0),
(@PATH,5,-5382.682,444.3073,385.997,0,0,0,0,100,0),
(@PATH,6,-5395.064,458.5347,384.6376,0,0,0,0,100,0);

-- Pathing for Toxic Sludge Entry: 42184
SET @NPC := 305111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5375.188,`position_y`=409.5104,`position_z`=389.4726 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '78783');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5375.188,409.5104,389.4726,0,0,0,0,100,0),
(@PATH,2,-5367.422,421.1582,385.6376,0,0,0,0,100,0),
(@PATH,3,-5355.188,422.6094,384.5912,0,0,0,0,100,0),
(@PATH,4,-5342.764,421.1892,387.4567,0,0,0,0,100,0),
(@PATH,5,-5335.753,413.2639,388.2043,0,0,0,0,100,0),
(@PATH,6,-5325.132,407.132,389.3931,0,0,0,0,100,0),
(@PATH,7,-5311.54,406.684,389.4905,0,0,0,0,100,0),
(@PATH,8,-5325.132,407.132,389.3931,0,0,0,0,100,0),
(@PATH,9,-5335.753,413.2639,388.2043,0,0,0,0,100,0),
(@PATH,10,-5342.764,421.1892,387.4567,0,0,0,0,100,0),
(@PATH,11,-5355.188,422.6094,384.5912,0,0,0,0,100,0),
(@PATH,12,-5367.333,421.2882,385.6962,0,0,0,0,100,0);

-- Set rest of Toxic Sludge to random movement
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id`=42184 AND `MovementType`=0;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=304856;
UPDATE `creature` SET `spawndist`=2,`MovementType`=1 WHERE `guid`=304859;

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 304820;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5554.495,`position_y`=729.9583,`position_z`=377.7221 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5554.495,729.9583,377.7221,0,0,0,0,100,0),
(@PATH,2,-5540.143,703.5018,372.3741,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 304913;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5578.689,`position_y`=451.9566,`position_z`=383.8326 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5578.689,451.9566,383.8326,0,0,0,0,100,0),
(@PATH,2,-5605.662,458.3368,383.4257,0,0,0,0,100,0),
(@PATH,3,-5627.88,463.9288,384.63,0,0,0,0,100,0),
(@PATH,4,-5640.616,471.8958,386.2059,0,0,0,0,100,0),
(@PATH,5,-5655.656,479.5295,387.4268,0,0,0,0,100,0),
(@PATH,6,-5668.726,483.5521,388.8936,0,0,0,0,100,0),
(@PATH,7,-5655.656,479.5295,387.4268,0,0,0,0,100,0),
(@PATH,8,-5640.616,471.8958,386.2059,0,0,0,0,100,0),
(@PATH,9,-5627.88,463.9288,384.63,0,0,0,0,100,0),
(@PATH,10,-5605.662,458.3368,383.4257,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 304900;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5593.222,`position_y`=482.9288,`position_z`=385.0974 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5593.222,482.9288,385.0974,0,0,0,0,100,0),
(@PATH,2,-5596.588,496.3108,384.7564,0,0,0,0,100,0),
(@PATH,3,-5597.483,512.2778,383.7751,0,0,0,0,100,0),
(@PATH,4,-5591.219,522.0382,383.3913,0,0,0,0,100,0),
(@PATH,5,-5582.045,532.5469,383.8344,0,0,0,0,100,0),
(@PATH,6,-5566.719,541.3854,385.2649,0,0,0,0,100,0),
(@PATH,7,-5555.174,544.4861,388.8182,0,0,0,0,100,0),
(@PATH,8,-5566.719,541.3854,385.2649,0,0,0,0,100,0),
(@PATH,9,-5582.045,532.5469,383.8344,0,0,0,0,100,0),
(@PATH,10,-5591.219,522.0382,383.3913,0,0,0,0,100,0),
(@PATH,11,-5597.483,512.2778,383.7751,0,0,0,0,100,0),
(@PATH,12,-5596.588,496.3108,384.7564,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 304902;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5635.768,`position_y`=511.441,`position_z`=386.9115 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5635.768,511.441,386.9115,0,0,0,0,100,0),
(@PATH,2,-5640.137,516.3629,387.1353,0,0,0,0,100,0),
(@PATH,3,-5654.481,529.6233,387.3961,0,0,0,0,100,0),
(@PATH,4,-5674.986,533.2674,386.5665,0,0,0,0,100,0),
(@PATH,5,-5654.481,529.6233,387.3961,0,0,0,0,100,0),
(@PATH,6,-5640.137,516.3629,387.1353,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 305138;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5656.09,`position_y`=332.3108,`position_z`=387.5215 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5656.09,332.3108,387.5215,0,0,0,0,100,0),
(@PATH,2,-5637.276,343.0208,387.1458,0,0,0,0,100,0),
(@PATH,3,-5623.571,336.7969,388.5245,0,0,0,0,100,0),
(@PATH,4,-5612.106,336.6146,388.4062,0,0,0,0,100,0),
(@PATH,5,-5598.698,341.6215,389.0514,0,0,0,0,100,0),
(@PATH,6,-5581.003,349.9757,389.4549,0,0,0,0,100,0),
(@PATH,7,-5566.387,355.0191,390.5592,0,0,0,0,100,0),
(@PATH,8,-5581.003,349.9757,389.4549,0,0,0,0,100,0),
(@PATH,9,-5598.698,341.6215,389.0514,0,0,0,0,100,0),
(@PATH,10,-5612.106,336.6146,388.4062,0,0,0,0,100,0),
(@PATH,11,-5623.571,336.7969,388.5245,0,0,0,0,100,0),
(@PATH,12,-5637.225,343.0078,387.1566,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 305153;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5589.743,`position_y`=316.9601,`position_z`=393.6562 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5589.743,316.9601,393.6562,0,0,0,0,100,0),
(@PATH,2,-5598.135,307.5087,393.7838,0,0,0,0,100,0),
(@PATH,3,-5607.58,289.6302,393.7737,0,0,0,0,100,0),
(@PATH,4,-5599.374,277.4601,395.2696,0,0,0,0,100,0),
(@PATH,5,-5580.641,271.2621,396.2657,0,0,0,0,100,0),
(@PATH,6,-5565.153,272.0608,396.6893,0,0,0,0,100,0),
(@PATH,7,-5554.327,271.7361,396.1879,0,0,0,0,100,0),
(@PATH,8,-5542.771,279.5017,395.9838,0,0,0,0,100,0),
(@PATH,9,-5531.137,290.0174,396.6981,0,0,0,0,100,0),
(@PATH,10,-5543.066,310.4531,396.4598,0,0,0,0,100,0),
(@PATH,11,-5558.249,320.9392,394.8822,0,0,0,0,100,0),
(@PATH,12,-5574.37,322.0521,394.5019,0,0,0,0,100,0);

-- Pathing for Rockjaw Marauder Entry: 42222
SET @NPC := 304984;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5609.707,`position_y`=408.6615,`position_z`=380.695 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '79253');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5609.707,408.6615,380.695,0,0,0,0,100,0),
(@PATH,2,-5619.134,422.2934,381.429,0,0,0,0,100,0),
(@PATH,3,-5632.656,440.8906,383.3628,0,0,0,0,100,0),
(@PATH,4,-5637.721,453.0833,383.9783,0,0,0,0,100,0),
(@PATH,5,-5632.675,440.9462,383.2378,0,0,0,0,100,0),
(@PATH,6,-5619.134,422.2934,381.429,0,0,0,0,100,0),
(@PATH,7,-5609.707,408.6615,380.695,0,0,0,0,100,0),
(@PATH,8,-5601.2,402.033,381.8257,0,0,0,0,100,0),
(@PATH,9,-5588.443,398.9184,381.775,0,0,0,0,100,0),
(@PATH,10,-5581.781,384.6181,383.8971,0,0,0,0,100,0),
(@PATH,11,-5588.443,398.9184,381.775,0,0,0,0,100,0),
(@PATH,12,-5601.063,401.9902,381.6953,0,0,0,0,100,0);

-- Set rest of Rockjaw Marauder to random movement
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id`=42222 AND `MovementType`=0;

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305342;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5068.47,`position_y`=151.804,`position_z`=390.4384 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5068.47,151.804,390.4384,0,0,0,0,100,0),
(@PATH,2,-5068.22,127.526,390.6073,0,0,0,0,100,0),
(@PATH,3,-5068.22,94.6476,390.4132,0,0,0,0,100,0),
(@PATH,4,-5066.71,67.8229,391.774,0,0,0,0,100,0),
(@PATH,5,-5068.22,94.6476,390.4132,0,0,0,0,100,0),
(@PATH,6,-5068.22,127.526,390.6073,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305379;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4894.89,`position_y`=32.5556,`position_z`=386.8923 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4894.89,32.5556,386.8923,0,0,0,0,100,0),
(@PATH,2,-4891.63,55.5764,386.8923,0,0,0,0,100,0),
(@PATH,3,-4894.01,76.1563,386.8929,0,0,0,0,100,0),
(@PATH,4,-4901.11,90.9931,386.8818,0,0,0,0,100,0),
(@PATH,5,-4914.46,109.651,386.8922,0,0,0,0,100,0),
(@PATH,6,-4901.11,90.9931,386.8818,0,0,0,0,100,0),
(@PATH,7,-4894.01,76.1563,386.8929,0,0,0,0,100,0),
(@PATH,8,-4891.63,55.5764,386.8923,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305357;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5010.21,`position_y`=182.3,`position_z`=386.8922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5010.21,182.3,386.8922,0,0,0,0,100,0),
(@PATH,2,-5009.55,149.33,386.8922,0,0,0,0,100,0),
(@PATH,3,-5009.07,117.043,386.8922,0,0,0,0,100,0),
(@PATH,4,-5009.55,149.33,386.8922,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305369;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4976.25,`position_y`=180.818,`position_z`=386.8922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4976.25,180.818,386.8922,0,0,0,0,100,0),
(@PATH,2,-4972.53,147.288,386.8922,0,0,0,0,100,0),
(@PATH,3,-4963.96,113.085,386.8922,0,0,0,0,100,0),
(@PATH,4,-4972.53,147.288,386.8922,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305358;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4994.26,`position_y`=182.375,`position_z`=386.8922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4994.26,182.375,386.8922,0,0,0,0,100,0),
(@PATH,2,-4992.91,148.507,386.8922,0,0,0,0,100,0),
(@PATH,3,-4992.09,116.934,386.8922,0,0,0,0,100,0),
(@PATH,4,-4992.91,148.507,386.8922,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305345;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5036.24,`position_y`=180.519,`position_z`=386.7807 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5036.24,180.519,386.7807,0,0,0,0,100,0),
(@PATH,2,-5033.16,152.667,386.8922,0,0,0,0,100,0),
(@PATH,3,-5032.65,132.717,386.8922,0,0,0,0,100,0),
(@PATH,4,-5030.78,106.286,386.8922,0,0,0,0,100,0),
(@PATH,5,-5032.65,132.717,386.8922,0,0,0,0,100,0),
(@PATH,6,-5033.16,152.667,386.8922,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305277;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4997.99,`position_y`=244.476,`position_z`=390.8483 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4997.99,244.476,390.8483,0,0,0,0,100,0),
(@PATH,2,-5011.59,227.74,387.5639,0,0,0,0,100,0),
(@PATH,3,-5028,206.168,386.8922,0,0,0,0,100,0),
(@PATH,4,-5054.44,188.523,387.1906,0,0,0,0,100,0),
(@PATH,5,-5070.57,180.696,392.4094,0,0,0,0,100,0),
(@PATH,6,-5054.44,188.523,387.1906,0,0,0,0,100,0),
(@PATH,7,-5028,206.168,386.8922,0,0,0,0,100,0),
(@PATH,8,-5011.59,227.74,387.5639,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305348;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5048.14,`position_y`=79.8229,`position_z`=387.0368 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5048.14,79.8229,387.0368,0,0,0,0,100,0),
(@PATH,2,-5056.66,54.6875,391.3739,0,0,0,0,100,0),
(@PATH,3,-5064.836,33.16992,397.0528,0,0,0,0,100,0),
(@PATH,4,-5063.62,11.8299,398.3746,0,0,0,0,100,0),
(@PATH,5,-5064.809,32.78906,397.0528,0,0,0,0,100,0),
(@PATH,6,-5056.66,54.6875,391.3739,0,0,0,0,100,0);

-- Pathing for Crushcog Battle Suit Entry: 42226
SET @NPC := 305382;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4889.46,`position_y`=-3.39757,`position_z`=391.3463 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4889.46,-3.39757,391.3463,0,0,0,0,100,0),
(@PATH,2,-4885.28,26.6997,387.9087,0,0,0,0,100,0),
(@PATH,3,-4878.93,63.8715,388.9148,0,0,0,0,100,0),
(@PATH,4,-4878.49,93.0417,389.0364,0,0,0,0,100,0),
(@PATH,5,-4878.93,63.8715,388.9148,0,0,0,0,100,0),
(@PATH,6,-4885.28,26.6997,387.9087,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305281;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5144.444,`position_y`=135.7778,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5144.444,135.7778,386.2361,0,0,0,0,100,0),
(@PATH,2,-5163.174,161.059,386.2361,0,0,0,0,100,0),
(@PATH,3,-5178.377,168.9271,386.2361,0,0,0,0,100,0),
(@PATH,4,-5198.179,182.6007,386.2361,0,0,0,0,100,0),
(@PATH,5,-5214.056,205.0868,386.2361,0,0,0,0,100,0),
(@PATH,6,-5227.264,224.3316,386.2361,0,0,0,0,100,0),
(@PATH,7,-5247.384,236.4879,386.2361,0,0,0,0,100,0),
(@PATH,8,-5271.335,230.816,386.2361,0,0,0,0,100,0),
(@PATH,9,-5291.893,223.9688,386.2361,0,0,0,0,100,0),
(@PATH,10,-5313.757,234.9254,386.2361,0,0,0,0,100,0),
(@PATH,11,-5291.893,223.9688,386.2361,0,0,0,0,100,0),
(@PATH,12,-5271.335,230.816,386.2361,0,0,0,0,100,0),
(@PATH,13,-5247.384,236.4879,386.2361,0,0,0,0,100,0),
(@PATH,14,-5227.264,224.3316,386.2361,0,0,0,0,100,0),
(@PATH,15,-5214.056,205.0868,386.2361,0,0,0,0,100,0),
(@PATH,16,-5198.179,182.6007,386.2361,0,0,0,0,100,0),
(@PATH,17,-5178.377,168.9271,386.2361,0,0,0,0,100,0),
(@PATH,18,-5163.174,161.059,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305287;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5281.436,`position_y`=171.4757,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5281.436,171.4757,386.2361,0,0,0,0,100,0),
(@PATH,2,-5286.653,181.5764,386.2361,0,0,0,0,100,0),
(@PATH,3,-5308.518,187.658,386.2361,0,0,0,0,100,0),
(@PATH,4,-5338.458,181.9965,386.2361,0,0,0,0,100,0),
(@PATH,5,-5346.128,155.1701,386.2361,0,0,0,0,100,0),
(@PATH,6,-5339.08,136.8038,386.2361,0,0,0,0,100,0),
(@PATH,7,-5312.268,118.8125,386.2361,0,0,0,0,100,0),
(@PATH,8,-5339.08,136.8038,386.2361,0,0,0,0,100,0),
(@PATH,9,-5346.128,155.1701,386.2361,0,0,0,0,100,0),
(@PATH,10,-5338.458,181.9965,386.2361,0,0,0,0,100,0),
(@PATH,11,-5308.518,187.658,386.2361,0,0,0,0,100,0),
(@PATH,12,-5286.653,181.5764,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5132.681,`position_y`=140.4167,`position_z`=386.2362 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5132.681,140.4167,386.2362,0,0,0,0,100,0),
(@PATH,2,-5140.085,152.6667,386.2361,0,0,0,0,100,0),
(@PATH,3,-5152.662,166.9236,386.2361,0,0,0,0,100,0),
(@PATH,4,-5173.712,174.3681,386.2361,0,0,0,0,100,0),
(@PATH,5,-5189.203,189.0833,386.2361,0,0,0,0,100,0),
(@PATH,6,-5202.469,210.4063,386.2361,0,0,0,0,100,0),
(@PATH,7,-5215.113,231.6441,386.2361,0,0,0,0,100,0),
(@PATH,8,-5237.088,251.1458,386.2361,0,0,0,0,100,0),
(@PATH,9,-5266.859,246.8681,386.2361,0,0,0,0,100,0),
(@PATH,10,-5237.088,251.1458,386.2361,0,0,0,0,100,0),
(@PATH,11,-5215.113,231.6441,386.2361,0,0,0,0,100,0),
(@PATH,12,-5202.469,210.4063,386.2361,0,0,0,0,100,0),
(@PATH,13,-5189.203,189.0833,386.2361,0,0,0,0,100,0),
(@PATH,14,-5173.712,174.3681,386.2361,0,0,0,0,100,0),
(@PATH,15,-5152.662,166.9236,386.2361,0,0,0,0,100,0),
(@PATH,16,-5140.085,152.6667,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 315314;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5374.753,`position_y`=115.9931,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5374.753,115.9931,386.2361,0,0,0,0,100,0),
(@PATH,2,-5376.726,130.9879,386.2361,0,0,0,0,100,0),
(@PATH,3,-5388.217,153.0538,386.2361,0,0,0,0,100,0),
(@PATH,4,-5389.738,174.5694,386.2361,0,0,0,0,100,0),
(@PATH,5,-5384.281,199.7604,386.2361,0,0,0,0,100,0),
(@PATH,6,-5367.406,217.7326,386.2361,0,0,0,0,100,0),
(@PATH,7,-5349.922,230.0104,386.2361,0,0,0,0,100,0),
(@PATH,8,-5367.406,217.7326,386.2361,0,0,0,0,100,0),
(@PATH,9,-5384.281,199.7604,386.2361,0,0,0,0,100,0),
(@PATH,10,-5389.738,174.5694,386.2361,0,0,0,0,100,0),
(@PATH,11,-5388.217,153.0538,386.2361,0,0,0,0,100,0),
(@PATH,12,-5376.726,130.9879,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305315;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5281.436,`position_y`=171.4757,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5281.436,171.4757,386.2361,0,0,0,0,100,0),
(@PATH,2,-5286.653,181.5764,386.2361,0,0,0,0,100,0),
(@PATH,3,-5308.518,187.658,386.2361,0,0,0,0,100,0),
(@PATH,4,-5338.458,181.9965,386.2361,0,0,0,0,100,0),
(@PATH,5,-5346.128,155.1701,386.2361,0,0,0,0,100,0),
(@PATH,6,-5339.08,136.8038,386.2361,0,0,0,0,100,0),
(@PATH,7,-5312.268,118.8125,386.2361,0,0,0,0,100,0),
(@PATH,8,-5339.08,136.8038,386.2361,0,0,0,0,100,0),
(@PATH,9,-5346.128,155.1701,386.2361,0,0,0,0,100,0),
(@PATH,10,-5338.458,181.9965,386.2361,0,0,0,0,100,0),
(@PATH,11,-5308.518,187.658,386.2361,0,0,0,0,100,0),
(@PATH,12,-5286.653,181.5764,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305316;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5339.967,`position_y`=223.1424,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5339.967,223.1424,386.2361,0,0,0,0,100,0),
(@PATH,2,-5356.075,212.0851,386.2361,0,0,0,0,100,0),
(@PATH,3,-5368.215,197.8142,386.2361,0,0,0,0,100,0),
(@PATH,4,-5376.866,177.4323,386.2361,0,0,0,0,100,0),
(@PATH,5,-5374.035,155.1181,386.2361,0,0,0,0,100,0),
(@PATH,6,-5366.207,133.9444,386.2361,0,0,0,0,100,0),
(@PATH,7,-5364.483,115.0382,386.2361,0,0,0,0,100,0),
(@PATH,8,-5366.207,133.9444,386.2361,0,0,0,0,100,0),
(@PATH,9,-5374.035,155.1181,386.2361,0,0,0,0,100,0),
(@PATH,10,-5376.866,177.4323,386.2361,0,0,0,0,100,0),
(@PATH,11,-5368.215,197.8142,386.2361,0,0,0,0,100,0),
(@PATH,12,-5356.075,212.0851,386.2361,0,0,0,0,100,0);

-- Pathing for Crushcog Sentry-Bot Entry: 42291
SET @NPC := 305408;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5368.215,`position_y`=197.8142,`position_z`=386.2361 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5368.215,197.8142,386.2361,0,0,0,0,100,0),
(@PATH,2,-5356.075,212.0851,386.2361,0,0,0,0,100,0),
(@PATH,3,-5339.967,223.1424,386.2361,0,0,0,0,100,0),
(@PATH,4,-5356.075,212.0851,386.2361,0,0,0,0,100,0),
(@PATH,5,-5368.215,197.8142,386.2361,0,0,0,0,100,0),
(@PATH,6,-5376.866,177.4323,386.2361,0,0,0,0,100,0),
(@PATH,7,-5374.035,155.1181,386.2361,0,0,0,0,100,0),
(@PATH,8,-5366.207,133.9444,386.2361,0,0,0,0,100,0),
(@PATH,9,-5364.483,115.0382,386.2361,0,0,0,0,100,0),
(@PATH,10,-5366.207,133.9444,386.2361,0,0,0,0,100,0),
(@PATH,11,-5374.035,155.1181,386.2361,0,0,0,0,100,0),
(@PATH,12,-5376.866,177.4323,386.2361,0,0,0,0,100,0);

-- Set rest of Crushcog Sentry-Bot to random movement
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id`=42291 AND `MovementType`=0;

-- Pathing for Crazed Leper Gnome Entry: 46363
SET @NPC := 304731;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5039.6,`position_y`=775.127,`position_z`=283.185 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '95205 86400 86414');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5039.6,775.127,283.185,0,0,0,0,100,0),
(@PATH,2,-5005.81,773.05,287.0352,0,0,0,0,100,0),
(@PATH,3,-4995.18,777.651,288.4843,0,0,0,0,100,0),
(@PATH,4,-5005.81,773.05,287.0352,0,0,0,0,100,0),
(@PATH,5,-5039.6,775.127,283.185,0,0,0,0,100,0),
(@PATH,6,-5060.95,776.913,283.2628,0,0,0,0,100,0),
(@PATH,7,-5085.1,779.116,283.3157,0,0,0,0,100,0),
(@PATH,8,-5102.52,780.148,283.315,0,0,0,0,100,0),
(@PATH,9,-5085.1,779.116,283.3157,0,0,0,0,100,0),
(@PATH,10,-5060.95,776.913,283.2628,0,0,0,0,100,0);

-- Pathing for Crazed Leper Gnome Entry: 46363
SET @NPC := 304557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4956.99,`position_y`=758.486,`position_z`=276.2519 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '95205 86400 86414');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4956.99,758.486,276.2519,0,0,0,0,100,0),
(@PATH,2,-4957.82,734.997,276.2451,0,0,0,0,100,0),
(@PATH,3,-4966.06,714.988,276.2374,0,0,0,0,100,0),
(@PATH,4,-4957.82,734.997,276.2451,0,0,0,0,100,0),
(@PATH,5,-4956.99,758.486,276.2519,0,0,0,0,100,0),
(@PATH,6,-4955.02,778.299,276.2478,0,0,0,0,100,0),
(@PATH,7,-4951.05,795.007,276.2422,0,0,0,0,100,0),
(@PATH,8,-4955.23,805.839,276.2381,0,0,0,0,100,0),
(@PATH,9,-4951.05,795.007,276.2422,0,0,0,0,100,0),
(@PATH,10,-4955.02,778.299,276.2478,0,0,0,0,100,0);

-- Pathing for Crazed Leper Gnome Entry: 46363
SET @NPC := 304712;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5026.68,`position_y`=750.795,`position_z`=276.2044 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '95205 86400 86414');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5026.68,750.795,276.2044,0,0,0,0,100,0),
(@PATH,2,-5027.85,736.826,276.2193,0,0,0,0,100,0),
(@PATH,3,-5024.76,723.394,276.2274,0,0,0,0,100,0),
(@PATH,4,-5014.55,713.339,276.2362,0,0,0,0,100,0),
(@PATH,5,-5004.72,709.566,276.2415,0,0,0,0,100,0),
(@PATH,6,-5014.55,713.339,276.2362,0,0,0,0,100,0),
(@PATH,7,-5024.76,723.394,276.2274,0,0,0,0,100,0),
(@PATH,8,-5027.85,736.826,276.2193,0,0,0,0,100,0);

-- Pathing for Crazed Leper Gnome Entry: 46363
SET @NPC := 304720;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5018.35,`position_y`=767.514,`position_z`=285.1031 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '95205 86400 86414');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5018.35,767.514,285.1031,0,0,0,0,100,0),
(@PATH,2,-5050.1,769.901,283.238,0,0,0,0,100,0),
(@PATH,3,-5075.68,772.302,283.2941,0,0,0,0,100,0),
(@PATH,4,-5105.59,773.372,283.315,0,0,0,0,100,0),
(@PATH,5,-5075.68,772.302,283.2941,0,0,0,0,100,0),
(@PATH,6,-5050.1,769.901,283.238,0,0,0,0,100,0),
(@PATH,7,-5018.35,767.514,285.1031,0,0,0,0,100,0),
(@PATH,8,-5002.64,766.743,288.4843,0,0,0,0,100,0);

-- Set rest of Crazed Leper Gnome to random movement
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id`=46363 AND `MovementType`=0;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (304704,304481);

-- Crazed Leper Gnome
DELETE FROM `creature_template_addon` WHERE `entry` IN (46363);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(46363,0,0,0,1,0, '95205 86400 86414');

-- Fix some positions for Crazed Leper Gnome
UPDATE `creature` SET `position_z`=276.235199 WHERE `guid`=304550;
UPDATE `creature` SET `position_z`=276.237122 WHERE `guid`=304619;
UPDATE `creature` SET `position_z`=276.235596 WHERE `guid`=304652;
UPDATE `creature` SET `position_z`=276.236450 WHERE `guid`=304664;
UPDATE `creature` SET `position_z`=276.235119 WHERE `guid`=304666;
UPDATE `creature` SET `position_z`=276.233582 WHERE `guid`=304685;
UPDATE `creature` SET `position_z`=288.584582 WHERE `guid`=304687;
UPDATE `creature` SET `position_z`=276.234344 WHERE `guid`=304689;
UPDATE `creature` SET `position_z`=283.219421 WHERE `guid`=304704;
UPDATE `creature` SET `position_x`=-5085.354,`position_y`=775.8514,`position_z`=283.3139 WHERE `guid`=304733;
UPDATE `creature` SET `position_x`=-4961.679,`position_y`=762.7418,`position_z`=276.4213 WHERE `guid`=304633;
UPDATE `creature` SET `position_x`=-5018.792,`position_y`=753.9731,`position_z`=276.2087 WHERE `guid`=304711;
UPDATE `creature` SET `position_x`=-5020.201,`position_y`=783.2876,`position_z`=276.2133 WHERE `guid`=304482;
UPDATE `creature` SET `position_x`=-5030.191,`position_y`=762.8406,`position_z`=276.2173,`orientation`=6.235861 WHERE `guid`=304481;

-- High Tinker Mekkatorque Table images
DELETE FROM `creature_template_addon` WHERE `entry` IN (42419,42420,42422,42441,42452);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(42419,0,31692,0,1,0, ''),(42420,0,10664,0,1,0, ''),(42422,0,6569,0,1,0, ''),(42441,0,0,0,1,0, '35356'),(42452,0,0,0,1,0, '79212');

-- fix trigger
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128 WHERE `entry` IN (42452);

-- Fix loot template for 'Spare Parts' Gameobject
UPDATE `gameobject_loot_template` SET `MinCount`=1, `MaxCount`=1 WHERE `Entry`=30020;

-- Multi-bot Text'
DELETE FROM `creature_text` WHERE `CreatureID`=42598;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42598, 0, 0, 'Initiating cleanup ... ...', 12, 0, 100, 0, 0, 0, 42476, 'GS-9x Multi-Bot');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=79424 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 79424, 0, 0, 31, 0, 3, 42563, 0, 0, 0, 0, '', 'Spell Clean Up Toxic Pool (effect 0) will hit the potential target of the spell if target is unit Toxic Pool.');

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (12634);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12634,0,0, 'I need a new GS-9x Multibot.',50617,1,1,0,0,0,0, '',0,23420); -- Show if player has quest 26205 but no multibot
-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12634 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12634, 0, 0, 1, 9, 0, 26205, 0, 0, 0, 0, 0, '', 'Show gossip menu 12634 option id 0 if quest A Job for the Multi-Bot has been taken.');

DELETE FROM `creature_queststarter` WHERE `id` IN (42563,42645,42224);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=42563;

-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26316 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26316, 0, 1, 8, 0, 26205, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest A Job for the Multi-Bot has been rewarded.'),
(19, 0, 26316, 0, 1, 8, 0, 26264, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest What''s Left Behind has been rewarded.'),
(19, 0, 26316, 0, 1, 8, 0, 26265, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest Dealing with the Fallout has been rewarded.');
-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26318 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26318, 0, 1, 8, 0, 26284, 0, 0, 0, 0, 0, '', 'Show quest Finishin'' the Job if quest Missing in Action has been rewarded.'),
(19, 0, 26318, 0, 1, 8, 0, 26285, 0, 0, 0, 0, 0, '', 'Show quest Finishin'' the Job if quest Get Me Explosives Back! has been rewarded.');
-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26339 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26339, 0, 1, 8, 0, 26331, 0, 0, 0, 0, 0, '', 'Show quest Staging in Brewnall if quest Crushcog''s Minions has been rewarded.'),
(19, 0, 26339, 0, 1, 8, 0, 26333, 0, 0, 0, 0, 0, '', 'Show quest Staging in Brewnall if quest No Tanks! has been rewarded.');

-- Makeshift Cage SAI
SET @ENTRY := 204019;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,11,0,100,0,0,0,0,0,12,42645,5,0,0,0,0,1,0,0,0,0,0,0,0,"Makeshift Cage - On Gameobject State Change - Give Quest Credit"),
(@ENTRY,1,1,2,70,0,100,0,2,0,0,0,33,42645,0,0,0,0,0,7,0,0,0,0,0,0,0,"Makeshift Cage - On Gameobject State Change - Give Quest Credit"),
(@ENTRY,1,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,42645,5,0,0,0,0,0,"Makeshift Cage - On Gameobject State Changed - Set Data 1 1"),
(@ENTRY,1,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Makeshift Cage - On Gameobject State Changed - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,120000,120000,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Makeshift Cage - On Gameobject State Changed - Run Script"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,12,42645,5,0,0,0,0,1,0,0,0,0,0,0,0,"Makeshift Cage - On Gameobject State Changed - Run Script");

SET @ENTRY := 42645;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Thank you for breaking me out of here!', 12, 0, 100, 1, 0, 0, 42579, 'Captured Demolitionist'),
(@ENTRY, 0, 1, 'I don''t ever want to smell unwashed trogg again!', 12, 0, 100, 274, 0, 0, 42580, 'Captured Demolitionist'),
(@ENTRY, 0, 2, 'Thanks. Now, let''s blow up that cave!', 12, 0, 100, 4, 0, 0, 42581, 'Captured Demolitionist'),
(@ENTRY, 0, 3, 'You have no idea how happy I am to see you!', 12, 0, 100, 1, 0, 0, 42582, 'Captured Demolitionist'),
(@ENTRY, 0, 4, 'Finally, someone who''s not a trogg!', 12, 0, 100, 6, 0, 0, 42583, 'Captured Demolitionist'),
(@ENTRY, 0, 5, 'I''m free! I''m really free!', 12, 0, 100, 5, 0, 0, 42584, 'Captured Demolitionist');

-- Rockjaw Bonepicker
SET @ENTRY := 42221;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,0,1,173, '79253');
DELETE FROM `creature_addon` WHERE `guid` IN (305176,304995,304890,304837,304888);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(305176,0,0,0,1,0, '77831'),(304995,0,0,0,1,0, '77831'),(304890,0,0,0,1,0, '77831'),(304837,0,0,0,1,0, '77831'),(304888,0,0,0,1,0, '77831');

-- Rockjaw Bonepicker SAI
SET @ENTRY := 42221;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,28,77831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Bonepicker - On Aggro - Cast 'Bone Toss'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,4000,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Bonepicker - Combat - Cast 'Bone Toss'");

-- Update Rares in area
UPDATE `creature_template` SET `ArmorModifier`=2,`ExperienceModifier`=7.5 WHERE `entry` IN (1132,1260);
UPDATE `creature` SET `spawntimesecs`=10800 WHERE `id` IN (1132,1260);

-- Fixup Loot for Gnome start area
DELETE FROM `creature_loot_template` WHERE `Entry`=46363;
UPDATE `creature_template` SET `lootid`=0 WHERE `entry` IN (46363);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (42184,42185,42221,42222,42223,42226,42773,43325,46363);
UPDATE `creature_template` SET `mingold`=2, `maxgold`=7 WHERE `entry` IN (42291);
UPDATE `creature_template` SET `mingold`=50, `maxgold`=60 WHERE `entry` IN (1260);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42184 AND `Item`=1;
UPDATE `creature_loot_template` SET `QuestRequired`=1, `Comment`='Recovered Possession' WHERE `Entry`=42184 AND `Item`=57987;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Squishy Chunk' WHERE `Entry`=42184 AND `Item`=62771;
UPDATE `creature_loot_template` SET `Chance`=90, `GroupId`=1, `Comment`='Drop of Slime' WHERE `Entry`=42184 AND `Item`=62772;
DELETE FROM `creature_loot_template` WHERE `Entry`=42185 AND `Item` IN (17056,56151,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42185 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Inert Elemental Scintilla' WHERE `Entry`=42185 AND `Item`=55983;
UPDATE `creature_loot_template` SET `Chance`=90, `GroupId`=1, `Comment`='Inert Elemental Speck' WHERE `Entry`=42185 AND `Item`=55973;
DELETE FROM `creature_loot_template` WHERE `Entry`=42221 AND `Item` IN (2,2589,55973,55983,62771,62772,67229);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42221 AND `Item`=1;
UPDATE `creature_loot_template` SET `QuestRequired`=1, `Comment`='Stolen Powder Keg' WHERE `Entry`=42221 AND `Item`=58202;
DELETE FROM `creature_loot_template` WHERE `Entry`=42222 AND `Item` IN (2,2589,3173,55973,55983,62328,62771,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42222 AND `Item`=1;
UPDATE `creature_loot_template` SET `QuestRequired`=1, `Comment`='Stolen Powder Keg' WHERE `Entry`=42222 AND `Item`=58202;
DELETE FROM `creature_loot_template` WHERE `Entry`=43325 AND `Item` IN (2,4306,7101,49747,49748,49751,55973,55983,57987,62771,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=43325 AND `Item`=1;
UPDATE `creature_loot_template` SET `Item`=117, `Chance`=5, `GroupId`=1, `Comment`='Tough Jerky' WHERE `Entry`=43325 AND `Item`=3770;
DELETE FROM `creature_loot_template` WHERE `Entry`=42773 AND `Item` IN (2,55973,55983,62771,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42773 AND `Item`=1;
DELETE FROM `creature_loot_template` WHERE `Entry`=1260 AND `Item` IN (118,159,2546,2589,3223,24071,24100,24730);
UPDATE `creature_loot_template` SET `Item`=1, `Reference`=11111, `Chance`=100 WHERE `Entry`=1260 AND `Item`=117;
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=1260 AND `Item`=1;
DELETE FROM `creature_loot_template` WHERE `Entry`=42286 AND `Item` IN (2,2589,55973,62328,62771,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42286 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Ruined Pelt' WHERE `Entry`=42286 AND `Item`=4865;
UPDATE `creature_loot_template` SET `Chance`=45, `GroupId`=1, `Comment`='Broken Fang' WHERE `Entry`=42286 AND `Item`=7073;
UPDATE `creature_loot_template` SET `Chance`=45, `GroupId`=1, `Comment`='Chipped Claw' WHERE `Entry`=42286 AND `Item`=7074;
DELETE FROM `creature_loot_template` WHERE `Entry`=42290 AND `Item` IN (2589,6519,49747,49748,49751,55983,62772);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42290 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Rabbit''s Foot' WHERE `Entry`=42290 AND `Item`=3300;
UPDATE `creature_loot_template` SET `Chance`=90, `GroupId`=1, `Comment`='Shed Fur' WHERE `Entry`=42290 AND `Item`=62328;
DELETE FROM `creature_loot_template` WHERE `Entry`=42291 AND `Item` IN (117,2592);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42291 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Defective Gear' WHERE `Entry`=42291 AND `Item`=54624;
UPDATE `creature_loot_template` SET `Chance`=90, `GroupId`=1, `Comment`='Fractured Gear Tooth' WHERE `Entry`=42291 AND `Item`=57058;
DELETE FROM `creature_loot_template` WHERE `Entry`=42223 AND `Item` <> 1;
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42223 AND `Item`=1;
DELETE FROM `creature_loot_template` WHERE `Entry`=42226 AND `Item` IN (117,2886,49751);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=42226 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Defective Gear' WHERE `Entry`=42226 AND `Item`=54624;
UPDATE `creature_loot_template` SET `Chance`=90, `GroupId`=1, `Comment`='Fractured Gear Tooth' WHERE `Entry`=42226 AND `Item`=57058;
DELETE FROM `creature_loot_template` WHERE `Entry`=1132 AND `Item` IN (2672,3224,3299,24071,24073,24100,24730,44007);
UPDATE `creature_loot_template` SET `Comment`='Reference Small Pouch' WHERE `Entry`=1132 AND `Item`=1;
UPDATE `creature_loot_template` SET `Chance`=10, `GroupId`=1, `Comment`='Rabbit''s Foot' WHERE `Entry`=1132 AND `Item`=3300;
UPDATE `creature_loot_template` SET `Chance`=90, `Item`=62328, `GroupId`=1, `Comment`='Shed Fur' WHERE `Entry`=1132 AND `Item`=1965;
UPDATE `creature_loot_template` SET `Item`=1, `Chance`=100 WHERE `Entry`=1132 AND `Reference`=11111;

-- Crushcog Sentry-Bot SAI
SET @ENTRY := 42291;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,84152,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Aggro - Cast 'Wailing Siren' (No Repeat)"),
(@ENTRY,0,1,2,8,0,100,1,79781,0,10000,10000,33,42796,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Spellhit - Give Quest Credit"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Spellhit - Say 0"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Spellhit - Run Script"),
(@ENTRY,0,4,5,0,1,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Death - Set Corpse Delay (Phase 1)"),
(@ENTRY,0,5,6,61,1,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Death - Set Stand State (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - On Death - Remove Root (Phase 1)"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set run on"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,122,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Flee"),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set Root"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set Stand State"),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,0,0,18,526336,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set Unit Flags"),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,0,0,18,524288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set Unit Flags"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushcog Sentry-Bot - Script - Set Phase");
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Optical sensor malfunction detected! Shutting down...', 12, 0, 100, 0, 0, 10571, 42702, 'Crushcog Sentry-Bot');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=79781 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 79781, 0, 0, 31, 0, 3, 42291, 0, 0, 0, 0, '', 'Spell Blind Sentry (effect 0) will hit the target of the spell if target is unit Crushcog Sentry-Bot.');

DELETE FROM `creature_addon` WHERE `guid` IN (305228,305304,305307,305310,305311);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(305228,0,0,1,258,0, ''),(305304,0,0,0,258,0, '18950 78174'),(305307,0,0,0,258,0, '18950 78174'),(305310,0,0,0,258,0, '18950 78174'),(305311,0,0,0,258,0, '18950 78174');

-- Razio Crushcog
DELETE FROM `vehicle_template_accessory` WHERE `entry`=42839;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(42839,42494,0,1,'Razio Crushcog - Razio Crushcog', 5, 0);
-- Fix spell click for -- Razio Crushcog
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=42839;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42839, 46598, 0, 0);
-- Razio Crushcog Add missing ani kit
UPDATE `creature_template_addon` SET `aiAnimKit`=695 WHERE `entry`=42839;

-- Trogg Tunnel SAI
SET @ENTRY := 42894;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,11,80054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trogg Tunnel - OOC - Cast 'Boulder Impact'");

-- Explosive Fuse SAI
SET @ENTRY := 42763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,33343,0,0,0,0,0,1,0,0,0,0,0,0,0,"Explosive Fuse - OOC - Cast 'Red Banish State'"),
(@ENTRY,0,1,2,1,0,100,1,1300,1300,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Explosive Fuse - OOC - Move to'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-5523.596,699.3292,375.8474,0,"Explosive Fuse - OOC - Move to'"),
(@ENTRY,0,3,0,1,0,100,1,4000,4000,0,0,45,1,1,0,0,0,0,19,42739,20,0,0,0,0,0,"Explosive Fuse - OOC - Set Data Frostmane Hold Target");

-- Frostmane Hold Target SAI
SET @ENTRY := 42739;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,10000,10000,11,76841,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Hold Target - On Data Set - Cast 'Cosmetic - Explosion'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,66772,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Hold Target - On Data Set - Cast 'Earthquake Camera Shake'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,79695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Hold Target - On Data Set - Cast 'Trigger Powder Keg Explosions'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Hold Target - On Data Set - Cast 'Trigger Powder Keg Explosions'"),
(@ENTRY*100,9,0,0,0,0,100,0,3000,3000,0,0,11,63360,0,0,0,0,0,8,0,0,0,-5523.764, 698.3386, 375.8542, 2.111848,"Frostmane Hold Target - Script - Cast 'Dusty Explosion'"),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,32,0,0,0,0,0,0,20,204047,10,0,0,0,0,0,"Frostmane Hold Target - Script - Reset Go");

UPDATE `gameobject` SET `spawntimesecs`=16 WHERE `id`=204041;
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE entry=204041;

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (42505);

-- All quest reward text for gnome start zone
DELETE FROM `quest_offer_reward` WHERE `ID` IN (27670,28167,27671,28169,27635,27674,26203,26425,26208,26566,26222,26205,26264,26265,26316,26285,26284,26318,26329,26331,26333,26339,26342,26364);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(27670,0,0,0,0,0,0,0,0, 'Well done, $n. My men can take it from here. Let''s focus on getting the other survivors out now.',23420),
(28167,0,0,0,0,0,0,0,0, 'Did Nevin send you ahead? That means he''s getting ready to end the mission, but there are still survivors to be rescued. We have to help them!',23420),
(27671,0,0,0,0,0,0,0,0, 'I know Nevin will be pleased with all the survivors you managed to help. I still can''t believe you managed to stay so strong down here in the radiation. You''ve seen the shape the other survivors are in.$B$BLet''s get you to the loading room for decontamination.',23420),
(28169,0,0,0,0,0,0,0,0, 'It''s good to meet you, $c. We rarely come across survivors as strong and capable as you are. I can help get you decontaminated and on your way out of here.',23420),
(27635,0,0,0,0,0,0,0,0, 'There, now you''re fit to head off to the surface and start your new life. The High Tinker will be delighted to hear of your arrival.',23420),
(27674,0,0,0,0,0,0,0,0, 'It''s good to see you again, $n. Without your help, we wouldn''t have been able to get so many survivors out of Gnomeregan this time. Everyone is going to be thrilled to meet you and hear your story.',23420),
(26203,0,0,0,0,0,0,0,0, 'For a gnome who has spent so much time inside Gnomeregan, you look positively fit and healthy, $n. That''s good. Before we can complete what Operation: Gnomeregan began, we''re going to need more warriors like you.',23420),
(26425,0,0,0,0,0,0,0,0, 'It''s good to meet you, $n. You''ve probably heard others speaking of Operation: Gnomeregan. Let me tell you a bit about what happened and why we left the dwarven city of Ironforge.',23420),
(26208,0,0,0,0,0,0,0,0, 'Even now, only the S.A.F.E. teams dare to venture far into the city to search for survivors. Meanwhile, Thermaplugg has sent one of his followers, Crushcog, to distract us and buy time for him to dig in.',23420),
(26566,0,0,0,0,0,0,0,0, 'So Mekkatorque himself has heard of my little project? Splendid! I''ve almost finished my latest prototype, but maybe you can help me chase down those last few parts.',23420),
(26222,0,0,0,0,0,0,0,0, 'These are fantastic! Let''s see what we can put together. Would you be interested in testing out the prototype once I''m done?',23420),
(26205,0,0,0,0,0,0,0,0, 'Wow, I never expected it to work on the first trial!$B$BUh, I mean, we''ve succeeded! I wonder what other uses I we can find for this handy little guy.',23420),
(26264,0,0,0,0,0,0,0,0, 'I can''t wait to give this new technology a try! We''ve lost more gnomes to radiation than we can count. It''s time to turn that around!',23420),
(26265,0,0,0,0,0,0,0,0, 'What a relief! Thank you for your help. I hope that gadget Engineer Grindspark was working on helps get the airfield cleaned up permanently.',23420),
(26316,0,0,0,0,0,0,0,0, 'It won''t be tough to collapse th'' tunnel, but I''m goin'' to need my team an'' my equipment ''afore I can get to th'' task.',23420),
(26285,0,0,0,0,0,0,0,0, 'Well, now, that''s more like it. We may get around to blowin'' up somethin'' after all.',23420),
(26284,0,0,0,0,0,0,0,0, 'You have me own thanks and th'' thanks of th'' men you rescued. I''ve already had th'' boys start setting up the gear down inside the cave. It should be ready to go soon.',23420),
(26318,0,0,0,0,0,0,0,0, 'I could feel th'' explosion way up here! My boys did a fine job riggin'' up that blast, but it wouldn''t have happened without your help. It''s only fair that I split my contract payment with you for helpin'' me finish th'' job.',23420),
(26329,0,0,0,0,0,0,0,0, '<The high tinker reads Jessup''s report.>$B$BSplendid news! With the troggs taken care of, we should be able to turn our attention to Crushcog''s troublemaking.',23420),
(26331,0,0,0,0,0,0,0,0, 'That should set back Crushcog''s plans a bit, but we can''t rest until he is defeated and Chill Breeze Valley is secure.',23420),
(26333,0,0,0,0,0,0,0,0, 'Mekkatorque will be pleased to hear that you''ve ruined Crushcog''s plans to use our old weapons for his followers. Without the mechano-tanks under his command, he''ll be weak and vulnerable.',23420),
(26339,0,0,0,0,0,0,0,0, 'Ah, yes, Kelsey told me to expect you. There''s still much to do before we can take on Crushcog.',23420),
(26342,0,0,0,0,0,0,0,0, 'You''ve given us just the opening we''ll need to get the drop on Crushcog. Excellent work, $n.',23420),
(26364,0,0,0,0,0,0,0,0, 'We''re finally free of Razlo Crushcog and his interference! With the defeat of Crushcog and his forces, Thermaplugg can''t afford to send any more of his followers to the surface. I can''t wait for the day when we defeat him for good!',23420);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (11662);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11662,0,0, 'I''m ready to start the assault.',42755,1,1,0,0,0,0, '',0,23420);
-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11662 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11662, 0, 0, 1, 9, 0, 26364, 0, 0, 0, 0, 0, '', 'Show gossip menu 11662 option id 0 if quest Down with Crushcog! has been taken.');

-- Quest Linking
DELETE FROM `quest_template_addon` WHERE `ID` IN (28167,27671,28169,27635,27674,26197,26199,26202,26203,26206,26421,26422,26423,26424,26425,26264,26265,26333,26284,26285,26373);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`SpecialFlags`) VALUES 
(28167,0,27670,4),(27671,0,28167,4),(28169,0,27671,4),(27635,0,28169,6),(27674,0,27635,4),
(26197,128,27674,4),(26199,16,27674,4),(26202,256,27674,4),(26203,1,27674,4),(26206,8,27674,4),
(26421,128,26197,4),(26422,16,26199,4),(26424,256,26202,4),(26425,1,26203,4),(26423,8,26206,4),
(26264,0,26222,4),(26265,0,26222,0),(26333,0,26329,4),(26284,0,26316,0),(26285,0,26316,0),(26373,0,26364,4);

-- Irradiated spell for Gnome players
DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask`=64 AND `spell`=80653;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`,`classMask`,`spell`,`note`) VALUES
(64,1,80653, 'Warrior - Gnome - Irradiated Aura'),
(64,8,80653, 'Rogue - Gnome - Irradiated Aura'),
(64,16,80653, 'Priest - Gnome - Irradiated Aura'),
(64,128,80653, 'Mage - Gnome - Irradiated Aura'),
(64,256,80653, 'Warlock - Gnome - Irradiated Aura');

-- S.A.F.E. Operative SAI
SET @ENTRY := 46449;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-304583,-304595) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - OOC - Load path"),
(@ENTRY,0,1,2,40,0,100,0,11,@ENTRY,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP11 - Pause WP"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP11 - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,21,@ENTRY,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP21 - Despawn"),
(-304583,0,0,0,1,0,100,0,5000,40000,75000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - OOC - Say 0"),
(-304595,0,0,0,1,0,100,0,5000,40000,75000,90000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - OOC - Say 1"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.146755,"S.A.F.E. Operative - script - Turn to"),
(@ENTRY*100,9,1,0,0,0,100,0,1500,1500,0,0,11,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - script - Cast 'OneShotKneel'"),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,29,0,0,0,0,0,0,0,"S.A.F.E. Operative - script - Despawn Injured Gnome"),
(@ENTRY*100,9,3,0,0,0,100,0,500,500,0,0,128,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - script - Set animKit"),
(@ENTRY*100,9,4,0,0,0,100,0,500,500,0,0,12,46447,3,15000,0,0,0,8,0,0,0,-4974.72,872.908,274.3923,3.700098,"S.A.F.E. Operative - script - Spawn Injured Gnome"),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - script - Remove Aura");
-- S.A.F.E. Operative text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Stay with me. You''re going to make it out of here.', 12, 0, 100, 0, 0, 0, 46501, 'S.A.F.E. Operative'),
(@ENTRY, 1, 0, 'We''re going to get you some help.', 12, 0, 100, 0, 0, 0, 46502, 'S.A.F.E. Operative');
-- S.A.F.E. Operative path
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-4962.9,830.281,283.7434, 'S.A.F.E. Operative'),
(@ENTRY,2,-4966.8,833.354,280.0607, 'S.A.F.E. Operative'),
(@ENTRY,3,-4970.68,835.288,276.7794, 'S.A.F.E. Operative'),
(@ENTRY,4,-4975.79,836.703,276.2314, 'S.A.F.E. Operative'),
(@ENTRY,5,-4979.44,837,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,6,-4980.32,843.554,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,7,-4981.08,851.715,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,8,-4980.9,856.639,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,9,-4979.95,863.483,274.3092, 'S.A.F.E. Operative'),
(@ENTRY,10,-4977.01,869.118,274.3092, 'S.A.F.E. Operative'),
(@ENTRY,11,-4973.9,872.045,274.3092, 'S.A.F.E. Operative'),
(@ENTRY,12,-4979.47,868.085,274.3092, 'S.A.F.E. Operative'),
(@ENTRY,13,-4980.03,863.34,274.3092, 'S.A.F.E. Operative'),
(@ENTRY,14,-4980.783,858.1419,274.9824, 'S.A.F.E. Operative'),
(@ENTRY,15,-4981.21,853.278,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,16,-4981.36,844.91,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,17,-4979.28,837.082,276.2324, 'S.A.F.E. Operative'),
(@ENTRY,18,-4972.71,836.391,276.2365, 'S.A.F.E. Operative'),
(@ENTRY,19,-4968.52,834.043,278.6633, 'S.A.F.E. Operative'),
(@ENTRY,20,-4962.63,830.747,283.767, 'S.A.F.E. Operative'),
(@ENTRY,21,-4959.75,828.16,285.8152, 'S.A.F.E. Operative');

-- S.A.F.E. Technician SAI
SET @ENTRY := 46230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Reset - Set Phase 1"),
(@ENTRY,0,1,0,38,1,100,0,1,2,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Data Set 1 2 - Run Script"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,1,0,15000,15000,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Data Set 1 1 - Sat 0"),
(@ENTRY,0,3,4,54,0,100,0,0,0,0,0,11,7791,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Summon - Cast 'Teleport'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Summon - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,10,42396,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - On Reached WP10 - Despawn"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Emotstate"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.296706,"S.A.F.E. Technician - Script - Turn to"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Play Emote 'OneShotExclamation'"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Turn run on"),
(@ENTRY*100,9,5,0,0,0,100,0,1500,1500,0,0,69,0,0,0,0,0,0,8,0,0,0,-5178.174,696.8113,288.0847,0,"S.A.F.E. Technician - Script - Move to"),
(@ENTRY*100,9,6,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.500983,"S.A.F.E. Technician - Script - Turn to"),
(@ENTRY*100,9,7,0,0,0,100,0,1500,1500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Say 1"),
(@ENTRY*100,9,8,0,0,0,100,0,2500,2500,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Emotstate"),
(@ENTRY*100,9,9,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Emotstate"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Turn run off"),
(@ENTRY*100,9,11,0,0,0,100,0,1500,1500,0,0,69,0,0,0,0,0,0,8,0,0,0,-5184.88,699.385,288.0847,0,"S.A.F.E. Technician - Script - Move to"),
(@ENTRY*100,9,12,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.066617,"S.A.F.E. Technician - Script - Turn to"),
(@ENTRY*100,9,13,0,0,0,100,0,500,500,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Emotstate"),
(@ENTRY*100,9,14,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Phase 1"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Turn run off"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Set Emotestate"),
(@ENTRY*100+1,9,2,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5201.011,476.3196,388.2941,0,"S.A.F.E. Technician - Script - Move to"),
(@ENTRY*100+1,9,3,0,0,0,100,0,1000,1000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Play Emote OneShotSalute"),
(@ENTRY*100+1,9,4,0,0,0,100,0,3000,3000,0,0,53,0,42396,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Technician - Script - Load path");
-- S.A.F.E. Technician text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Ugh! Not this again! I''m asking for a new station next expedition...', 12, 0, 100, 1, 0, 0, 46342, 'S.A.F.E. Technician'),
(@ENTRY, 1, 0, 'No, not the Sanitron... it was my pride and joy!', 12, 0, 100, 6, 0, 0, 46341, 'S.A.F.E. Technician');
-- S.A.F.E. Technician addon
DELETE FROM `creature_template_addon` WHERE `entry`=46230;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(46230,0,0,0,1,233, '');
DELETE FROM `creature_addon` WHERE `guid` IN (304781);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (304781,0,0,0,1,69, '');

-- S.A.F.E. Officer SAI
SET @ENTRY := 46025;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-304738,-304770) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,7791,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - On Summon - Cast 'Teleport'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - On Summon - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,10,42396,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - On Reached WP10 - Despawn"),
(-304738,0,0,0,38,0,100,0,1,1,15000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - On Data Set - Say 0"),
(-304770,0,0,0,1,0,100,0,1000,1000,5000,5000,10,6,273,274,396,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer  - OOC - Random Emote"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - Script - Turn run off"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,71,0,0,0,61392,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - Script - Equip Weapon"),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5201.011,476.3196,388.2941,0,"S.A.F.E. Officer - Script - Move to"),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - Script - Play Emote OneShotSalute"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,53,0,42396,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Officer - Script - Load path");
-- S.A.F.E. Officer text
DELETE FROM `creature_text` WHERE `CreatureID`=46025;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46025, 0, 0, 'This path only leads deeper into the city. Keep going south toward the Loading Room.', 12, 0, 100, 5, 0, 0, 47191, 'S.A.F.E. Officer');

-- Nevin Twistwrench <S.A.F.E. Commander> SAI
SET @ENTRY := 42396;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,75000,75000,87,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,0,0,0,1,0,0,0,0,0,0,0,"Nevin Twistwrench - OOC - Run Random Script'"),
(@ENTRY,0,1,0,19,0,100,0,26197,0,0,0,85,88340,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Summon Mage Guide'"),
(@ENTRY,0,2,0,19,0,100,0,26199,0,0,0,85,88347,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Summon Priest Guide'"),
(@ENTRY,0,3,0,19,0,100,0,26202,0,0,0,85,88303,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Summon Warlock Guide'"),
(@ENTRY,0,4,0,19,0,100,0,26203,0,0,0,85,88326,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Summon Warrior Guide'"),
(@ENTRY,0,5,0,19,0,100,0,26206,0,0,0,85,88328,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Summon Rogue Guide'"),
(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,12,45847,1,60000,0,0,0,8,0,0,0,-5201.76,478.174,388.5433,5.096361,"Nevin Twistwrench - Script - Spawn 'S.A.F.E. Operative'"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,12,46025,1,60000,0,0,0,8,0,0,0,-5201.76,478.174,388.5433,5.096361,"Nevin Twistwrench - Script - Spawn 'S.A.F.E. Officer'"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,12,46230,1,60000,0,0,0,8,0,0,0,-5201.76,478.174,388.5433,5.096361,"Nevin Twistwrench - Script - Spawn 'S.A.F.E. Technician'");
-- Path for S.A.F.E. Officer / Technician
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5196.02,474.892,388.4878,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,2,-5186.08,473.747,388.4367,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,3,-5181.28,479.153,388.3117,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,4,-5180.78,488.089,388.1784,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,5,-5185.95,495.59,388.0617,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,6,-5190.03,506.799,387.8832,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,7,-5192.92,514.186,387.7582,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,8,-5198.438,512.0156,388.2802,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,9,-5205.1,505.281,388.2802,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench'),
(@ENTRY,10,-5205.77,501.943,388.2802,'S.A.F.E. Officer / Technician Summoned by Nevin Twistwrench');
-- ENTRY for S.A.F.E. Operative
DELETE FROM `waypoint_data` WHERE `id`=@ENTRY;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@ENTRY,1,-5196.02,474.892,388.4878,0,0,0,0,100,0),
(@ENTRY,2,-5186.08,473.747,388.4367,0,0,0,0,100,0),
(@ENTRY,3,-5181.28,479.153,388.3117,0,0,0,0,100,0),
(@ENTRY,4,-5180.78,488.089,388.1784,0,0,0,0,100,0),
(@ENTRY,5,-5185.95,495.59,388.0617,0,0,0,0,100,0),
(@ENTRY,6,-5190.03,506.799,387.8832,0,0,0,0,100,0),
(@ENTRY,7,-5192.92,514.186,387.7582,0,0,0,0,100,0),
(@ENTRY,8,-5198.438,512.0156,388.2802,0,0,0,0,100,0),
(@ENTRY,9,-5205.1,505.281,388.2802,0,0,0,0,100,0),
(@ENTRY,10,-5205.77,501.943,388.2802,0,0,0,0,100,0);

-- Add target position for spells 'Summon Class Guides'
DELETE FROM `spell_target_position` WHERE `ID` IN (88340,88347,88303,88326,88328,205137);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES -- ,`Orientation`
(88340,0,0,-5196.8,475.03,388.5483,23420), -- ,3.036349
(88347,0,0,-5196.8,475.03,388.5483,23420),
(88303,0,0,-5196.8,475.03,388.5483,23420),
(88326,0,0,-5196.8,475.03,388.5483,23420),
(88328,0,0,-5196.8,475.03,388.5483,23420);

-- S.A.F.E. Guide SAI <Warlock Trainer>
SET @ENTRY := 47323;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,5,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.595378,"S.A.F.E. Guide - On Reached WP5 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP5 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP5 - Despawn in 6 sec");

-- S.A.F.E. Guide SAI <Warrior Trainer>
SET @ENTRY := 47349;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,3,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.131268,"S.A.F.E. Guide - On Reached WP3 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP3 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP3 - Despawn in 6 sec");

-- S.A.F.E. Guide SAI <Rogue Trainer>
SET @ENTRY := 47350;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,7,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.7679449,"S.A.F.E. Guide - On Reached WP7 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP7 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP7 - Despawn in 6 sec");

-- S.A.F.E. Guide SAI <Mage Trainer>
SET @ENTRY := 47351;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,9,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.532694,"S.A.F.E. Guide - On Reached WP9 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP9 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP9 - Despawn in 6 sec");

-- S.A.F.E. Guide SAI <Priest Trainer>
SET @ENTRY := 47359;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,8,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.595378,"S.A.F.E. Guide - On Reached WP8 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP8 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP8 - Despawn in 6 sec");

-- S.A.F.E. Guide SAI <Hunter Trainer>
SET @ENTRY := 103618;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Turn to Summoner 'No Repeat'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,3000,3000,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Say 0 'No Repeat'"),
(@ENTRY,0,2,0,1,0,100,1,5000,5000,5000,5000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - OOC - Load path 'No Repeat'"),
(@ENTRY,0,3,4,40,0,100,0,8,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.595378,"S.A.F.E. Guide - On Reached WP13 - Turn to"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,1,0,1,0,0,0,23,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP13 - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Guide - On Reached WP13 - Despawn in 6 sec");

DELETE FROM `creature_text` WHERE `CreatureID` IN (47323,47349,47350,47351,47359,103618);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Alamar Grimm <Warlock Trainer> Entry: 460
(47323, 0, 0, 'Follow me, $n, and I''ll introduce you to your trainer, Alamar Grimm.', 12, 0, 100, 1, 0, 0, 47493, 'S.A.F.E. Guide'),
(47323, 1, 0, 'Alamar, I''d  like to introduce you to $n, a recent escapee from Gnomeregan.', 12, 0, 100, 1, 0, 0, 47494, 'S.A.F.E. Guide'),
-- Drill Sergeant Steamcrank <Warrior Trainer> Entry: 42324
(47349, 0, 0, 'Follow me, $n, and I''ll introduce you to your trainer, Drill Sergeant Steamcrank.', 12, 0, 100, 1, 0, 0, 47516, 'S.A.F.E. Guide'),
(47349, 1, 0, 'Sergeant, allow me to introduce $n, who helped us rescue survivors in Gnomeregan.', 12, 0, 100, 1, 0, 0, 47517, 'S.A.F.E. Guide'),
-- Kelsey Steelspark <Rogue Trainer> Entry: 42366
(47350, 0, 0, 'Follow me, $n, and I''ll introduce you to your trainer, Kelsey Steelspark.', 12, 0, 100, 1, 0, 0, 47519, 'S.A.F.E. Guide'),
(47350, 1, 0, 'Kelsey, allow me to introduce $n, who helped us rescue survivors in Gnomeregan.', 12, 0, 100, 1, 0, 0, 47520, 'S.A.F.E. Guide'),
-- Bipsi Frostflinger <Mage Trainer> Entry: 42331
(47351, 0, 0, 'Follow me, $n, and I''ll introduce you to your trainer, Bipsi Frostflinger.', 12, 0, 100, 1, 0, 0, 47531, 'S.A.F.E. Guide'),
(47351, 1, 0, 'Bipsi, this is $n, one of the most recent survivors to emerge from Gnomeregan.', 12, 0, 100, 1, 0, 0, 47532, 'S.A.F.E. Guide'),
-- "Doc" Cogspin <Priest Trainer> Entry: 42323
(47359, 0, 0, 'Follow me, $n, and I''ll introduce you to your trainer, "Doc" Cogspin.', 12, 0, 100, 1, 0, 0, 47533, 'S.A.F.E. Guide'),
(47359, 1, 0, 'Doc, this is $n, who helped Nevin''s team get a number of survivors out of Gnomeregan.', 12, 0, 100, 1, 0, 0, 47534, 'S.A.F.E. Guide');

-- Pathing for S.A.F.E. Guide
SET @ENTRY := 47323;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5187.03,474.24,388.4367, 'S.A.F.E. Guide'),
(@ENTRY,2,-5181.46,480.069,388.3117, 'S.A.F.E. Guide'),
(@ENTRY,3,-5181.73,488.365,388.1453, 'S.A.F.E. Guide'),
(@ENTRY,4,-5186.75,500.146,387.8832, 'S.A.F.E. Guide'),
(@ENTRY,5,-5192.54,508.486,387.8832, 'S.A.F.E. Guide');

-- Pathing for S.A.F.E. Guide
SET @ENTRY := 47349;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5180.05,470.845,388.4367, 'S.A.F.E. Guide'),
(@ENTRY,2,-5172.42,465.8,389.3726, 'S.A.F.E. Guide'),
(@ENTRY,3,-5167.26,460.304,390.8954, 'S.A.F.E. Guide');

-- Pathing for S.A.F.E. Guide
SET @ENTRY := 47350;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5176.65,480.795,388.4367, 'S.A.F.E. Guide'),
(@ENTRY,2,-5161.17,476.915,390.4193, 'S.A.F.E. Guide'),
(@ENTRY,3,-5153.205,478.2153,391.2967, 'S.A.F.E. Guide'),
(@ENTRY,4,-5146.082,487.2708,394.612, 'S.A.F.E. Guide'),
(@ENTRY,5,-5142.51,493.8958,395.6693, 'S.A.F.E. Guide'),
(@ENTRY,6,-5145.514,500.4184,395.5937, 'S.A.F.E. Guide'),
(@ENTRY,7,-5141.986,502.0712,395.5937, 'S.A.F.E. Guide');

-- Pathing for S.A.F.E. Guide
SET @ENTRY := 47351;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5177.57,476.611,388.4367, 'S.A.F.E. Guide'),
(@ENTRY,2,-5164.87,478.951,389.9754, 'S.A.F.E. Guide'),
(@ENTRY,3,-5155.42,470.168,390.6693, 'S.A.F.E. Guide'),
(@ENTRY,4,-5146.19,459.63,392.3894, 'S.A.F.E. Guide'),
(@ENTRY,5,-5130.46,450.373,394.9455, 'S.A.F.E. Guide'),
(@ENTRY,6,-5116.67,453.446,399.0573, 'S.A.F.E. Guide'),
(@ENTRY,7,-5105.842,458.625,402.5203, 'S.A.F.E. Guide'),
(@ENTRY,8,-5093.27,457.524,405.4066, 'S.A.F.E. Guide'),
(@ENTRY,9,-5087.58,448.462,409.1436, 'S.A.F.E. Guide');

-- Pathing for S.A.F.E. Guide
SET @ENTRY := 47359;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5175.7,479.142,388.4367, 'S.A.F.E. Guide'),
(@ENTRY,2,-5169.51,475.753,389.2261, 'S.A.F.E. Guide'),
(@ENTRY,3,-5151.5,465.866,391.3056, 'S.A.F.E. Guide'),
(@ENTRY,4,-5139.414,453.9121,393.8894, 'S.A.F.E. Guide'),
(@ENTRY,5,-5122.746,450.625,396.8953, 'S.A.F.E. Guide'),
(@ENTRY,6,-5104.41,459.804,402.8367, 'S.A.F.E. Guide'),
(@ENTRY,7,-5094.97,465.049,404.1793, 'S.A.F.E. Guide'),
(@ENTRY,8,-5077.84,475.616,401.9251, 'S.A.F.E. Guide');

-- Captain Tread Sparknozzle SAI
SET @ENTRY := 42489;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,300000,300000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - OOC - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,19,42491,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Hinkles Fastblast Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,42505,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Set Data"),
(@ENTRY*100,9,4,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,19,42491,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Hinkles Fastblast Say 1"),
(@ENTRY*100,9,5,0,0,0,100,0,11000,11000,0,0,1,0,0,0,0,0,0,19,42366,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Kelsey Steelspark Say 0"),
(@ENTRY*100,9,6,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,19,42490,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Elgin Clickspring Say 0"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.01,498.262,396.4203,1.500983,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.44,498.372,396.4214,1.413717,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.9,498.429,396.4363,1.413717,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,10,0,0,0,100,0,4000,4000,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.73,499.203,396.4203,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.75,499.571,396.4563,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.76,499.977,396.4433,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,13,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 2"),
(@ENTRY*100,9,14,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,11,43132,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Image of Dwarf  Mountaineer oneshotcheer"),
(@ENTRY*100,9,15,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 3"),
(@ENTRY*100,9,16,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,11,43131,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Image of Gnomeregan Infantry oneshotcheer");

DELETE FROM `creature_text` WHERE `CreatureID` IN (42489,42491,42366,42490);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42489, 0, 0, 'We can''t afford to let our enemy, Thermaplugg, continue to tighten his grip on the rest of Gnomeregan.', 12, 0, 100, 1, 0, 0, 43103, 'Captain Tread Sparknozzle'),
(42489, 1, 0, 'He has ordered his crony, Razlo Crushcog, to keep us on the defensive. Hinkles, what''s the latest intelligence on Razlo and his men?', 12, 0, 100, 1, 0, 0, 43104, 'Captain Tread Sparknozzle'),
(42491, 0, 0, 'It''s been hard for our scouts to get information on what Crushcog is planning.', 12, 0, 100, 1, 0, 0, 43105, 'Hinkles Fastblast to Captain Tread Sparknozzle'),
(42491, 1, 0, 'What we do know is that Crushcog is using an advanced mechano-tank prototype and his irradiated gnomes are trying to repair more at the old arsenal.', 12, 0, 100, 1, 0, 0, 43110, 'Hinkles Fastblast to Captain Tread Sparknozzle'),
(42366, 0, 0, 'We''re going to have a hard time handling this one alone. I sent a message to the dwarven capital of Ironforge asking for their support.', 12, 0, 100, 1, 0, 0, 43111, 'Kelsey Steelspark to Captain Tread Sparknozzle'),
(42490, 0, 0, 'A messenger reached us from Brewnall Village this morning. The dwarves are sending a squad of mountaineers to help us.', 12, 0, 100, 1, 0, 0, 43117, 'Elgin Clickspring to Captain Tread Sparknozzle'),
(42489, 2, 0, 'We have to be in position to strike against Crushcog when the mountaineers arrive.', 12, 0, 100, 1, 0, 0, 43118, 'Captain Tread Sparknozzle to Captain Tread Sparknozzle'),
(42489, 3, 0, 'With Crushcog defeated, Thermaplugg is sure to be quaking in his mechano-tank, and rightly so. You''re next, Thermaplugg. You''re next!', 12, 0, 100, 1, 0, 0, 43119, 'Captain Tread Sparknozzle to Captain Tread Sparknozzle');

-- Image of Razlo Crushcog SAI
SET @ENTRY := 42505;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reset - Cast Freeze Anim'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,10000,10000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Data Set - Load Path'"),
(@ENTRY,0,2,0,40,0,100,0,2,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP2 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,43133,1,42000,0,0,0,8,0,0,0,-5137.05,499.769,396.4573,3.106686,"Image of Razlo Crushcog - Script - Spawn 43133"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,12,43133,1,42000,0,0,0,8,0,0,0,-5138.56,500.873,396.4693,4.34587,"Image of Razlo Crushcog - Script - Spawn 43133"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,3,0,35960,0,0,0,0,11,43133,5,0,0,0,0,0,"Image of Razlo Crushcog - Script - Image of Mechano-Tank Set Model"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.996804,"Image of Razlo Crushcog - Script - Turn to"),
(@ENTRY*100,9,4,0,0,0,100,0,30000,30000,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Remove aura Freeze Anim"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Emote OneShotExclamation"),
(@ENTRY*100,9,6,0,0,0,100,0,8000,8000,0,0,41,0,8,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Despawn");
-- Pathing for Image of Razlo Crushcog
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5140.15,498.619,396.504, 'Image of Razlo Crushcog'),
(@ENTRY,2,-5137.77,500.366,395.8836, 'Image of Razlo Crushcog');

-- High Tinker Mekkatorque <King of Gnomes> SAI
SET @ENTRY := 42317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Resst - Set Phase 1"),
(@ENTRY,0,1,0,19,1,100,0,26208,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,4000,4000,0,0,11,79227,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Cast 'Op: Gnomeregan Recap Credit'"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 0"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5132.723,491.5582,395.7945,0,"High Tinker Mekkatorque - Script - Move to"),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,4,8684,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Play Sound"),
(@ENTRY*100,9,6,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 1"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,42419,1,83000,0,0,0,8,0,0,0,-5134.90,495.592,396.4183,5.61996,"High Tinker Mekkatorque - Script - Spawn Image of High Tinker Mekkatorque"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,42420,1,83000,0,0,0,8,0,0,0,-5134.27,496.132,396.4193,5.532694,"High Tinker Mekkatorque - Script - Spawn Image of Doc Cogspin"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,12,42422,1,83000,0,0,0,8,0,0,0,-5135.19,494.830,396.4193,5.5676,"High Tinker Mekkatorque - Script - Spawn Image of Hinkles Fastblast"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,12,42441,1,83000,0,0,0,8,0,0,0,-5133.28,496.009,396.4193,4.433136,"High Tinker Mekkatorque - Script - Spawn Irradiated Trogg Corpse"),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,12,42441,1,83000,0,0,0,8,0,0,0,-5134.98,494.033,396.4183,0.7504916,"High Tinker Mekkatorque - Script - Spawn Irradiated Trogg Corpse"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,12,42452,1,83000,0,0,0,8,0,0,0,-5132.73,493.806,396.5594,2.111848,"High Tinker Mekkatorque - Script - Spawn Irradiator 3000 Image"),
(@ENTRY*100,9,13,0,0,0,100,0,0,0,0,0,50,203862,83,0,0,0,0,8,0,0,0,-5133.672,494.8368,395.4257,0,"High Tinker Mekkatorque - Script - Spawn 203862"),
(@ENTRY*100,9,14,0,0,0,100,0,6000,6000,0,0,1,0,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 0"),
(@ENTRY*100,9,15,0,0,0,100,0,7000,7000,0,0,12,42423,1,70000,0,0,0,8,0,0,0,-5133.471,494.375,396.4433,2.775074,"High Tinker Mekkatorque - Script - Spawn 42423"),
(@ENTRY*100,9,16,0,0,0,100,0,1000,1000,0,0,1,0,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 0"),
(@ENTRY*100,9,17,0,0,0,100,0,7000,7000,0,0,1,1,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 1"),
(@ENTRY*100,9,18,0,0,0,100,0,4000,4000,0,0,1,2,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 2"),
(@ENTRY*100,9,19,0,0,0,100,0,4000,4000,0,0,1,1,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 1"),
(@ENTRY*100,9,20,0,0,0,100,0,5000,5000,0,0,1,0,1,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Say 0"),
(@ENTRY*100,9,21,0,0,0,100,0,11000,11000,0,0,1,2,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 2"),
(@ENTRY*100,9,22,0,0,0,100,0,7000,7000,0,0,1,3,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 3"),
(@ENTRY*100,9,23,0,0,0,100,0,10000,10000,0,0,1,3,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 3"),
(@ENTRY*100,9,24,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Remove mount"),
(@ENTRY*100,9,25,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Remove mount"),
(@ENTRY*100,9,26,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin set emotestate 69"),
(@ENTRY*100,9,27,0,0,0,100,0,0,0,0,0,17,428,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast set emotestate 428"),
(@ENTRY*100,9,28,0,0,0,100,0,5000,5000,0,0,1,1,1,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Say 1"),
(@ENTRY*100,9,29,0,0,0,100,0,5000,5000,0,0,1,5,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 5"),
(@ENTRY*100,9,30,0,0,0,100,0,6000,6000,0,0,86,51347,0,19,42422,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Cast 'Teleport Visual Only'"),
(@ENTRY*100,9,31,0,0,0,100,0,0,0,0,0,86,51347,0,19,42420,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Cast 'Teleport Visual Only"),
(@ENTRY*100,9,32,0,0,0,100,0,0,0,0,0,86,51347,0,19,42419,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Cast 'Teleport Visual Only"),
(@ENTRY*100,9,33,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Despawn"),
(@ENTRY*100,9,34,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Despawn"),
(@ENTRY*100,9,35,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Despawn"),
(@ENTRY*100,9,36,0,0,0,100,0,1000,1000,0,0,86,51929,0,19,42452,10,0,0,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Cast 'Bloody Explosion (Green)'"),
(@ENTRY*100,9,37,0,0,0,100,0,0,0,0,0,86,46419,0,19,42452,10,0,0,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Cast 'Cosmetic - Explosion'"),
(@ENTRY*100,9,38,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,9,42441,0,10,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiated Trogg Corpse Despawn"),
(@ENTRY*100,9,39,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Despawn"),
(@ENTRY*100,9,40,0,0,0,100,0,2000,2000,0,0,11,79227,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Cast 'Op: Gnomeregan Recap Credit'"),
(@ENTRY*100,9,41,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 2"),
(@ENTRY*100,9,42,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5131.771,490.1035,395.5858,0,"High Tinker Mekkatorque - Script - Move to"),
(@ENTRY*100,9,43,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.303835,"High Tinker Mekkatorque - Script - turn to"),
(@ENTRY*100,9,44,0,0,0,100,0,1000,1000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Set Phase 1");
-- High Tinker Mekkatorque text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'We assembled a mighty force and defeated Thermaplugg''s servants, fighting our way into the city. But, the usurper Thermaplugg had one last trick up his sleeve...', 12, 0, 100, 1, 0, 20895, 42408, 'High Tinker Mekkatorque'),
(@ENTRY, 1, 0, 'Take a look at this holotable. I want to show you a bit about Operation: Gnomeregan.', 12, 0, 100, 25, 0, 12148, 48277, 'High Tinker Mekkatorque'),
(@ENTRY, 2, 0, 'We were forced to retreat. Thermaplugg continues to hide behind the radiation, sending his crony, Crushcog, to harass us here on the surface.', 12, 0, 100, 1, 0, 20896, 42411, 'High Tinker Mekkatorque');
DELETE FROM `creature_text` WHERE `CreatureID`=42419;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42419, 0, 0, 'It''s too quiet. Where are Thermaplugg''s defense forces?', 12, 0, 100, 1, 0, 17552, 39883, 'Image of High Tinker Mekkatorque'),
(42419, 1, 0, 'IT''S A TRAP! That''s a fully functional irradiator!', 12, 0, 100, 5, 0, 17554, 39869, 'Image of High Tinker Mekkatorque'),
(42419, 2, 0, 'Ten minutes? Plenty of time to disarm the device.', 12, 0, 100, 1, 0, 17556, 39893, 'Image of High Tinker Mekkatorque'),
(42419, 3, 0, 'Hinkles, hand me that Whirring Bronze Gizmo and some Fresh Spring Water. Cogspin, toss me that Dirty Trogg Cloth and a Handful of Copper Bolts...', 12, 0, 100, 1, 0, 0, 39894, 'Image of High Tinker Mekkatorque'),
(42419, 5, 0, 'Whuh-oh! We''ve got to get out of here! Lapforge, beam us back, quickly!', 12, 0, 100, 5, 0, 17557, 39895, 'Image of High Tinker Mekkatorque');
DELETE FROM `creature_text` WHERE `CreatureID`=42423;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42423, 0, 0, 'No! No, no, NO!!! I won''t allow you into my kingdom, usurper! I WON''T ALLOW IT! ', 12, 0, 100, 0, 0, 17570, 39885, 'Thermaplugg''s Brag-bot'),
(42423, 1, 0, 'Activate the Ultimate Atomic Protection System.', 12, 0, 100, 0, 0, 0, 39886, 'Thermaplugg''s Brag-bot'),
(42423, 2, 0, '...DISINTEGRATE THEM ALL!', 12, 0, 100, 0, 0, 0, 39887, 'Thermaplugg''s Brag-bot'),
(42423, 3, 0, 'TEN MINUTES?! You left the factory setting on? Give me that controller, you idiot!', 12, 0, 100, 0, 0, 17572, 39889, 'Thermaplugg''s Brag-bot');
DELETE FROM `creature_text` WHERE `CreatureID`=42452;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42452, 0, 0, 'Irradiator 3000 activated. Attention. Emergency. You now have ten minutes to reach minimum safe distance.', 12, 0, 100, 0, 0, 17635, 39928, 'Irradiator 3000 Image'),
(42452, 1, 0, '*BEEP* Attention. Emergency. You now have ten seconds to reach minimum safe distance.', 12, 0, 100, 0, 0, 17636, 39929, 'Irradiator 3000 Image');

UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=42316;
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=42319;

-- High Tinker Mekkatorque
DELETE FROM `creature_text` WHERE `CreatureID` IN (42849);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42849, 0, 0, 'Mekgineer Thermaplugg refuses to acknowledge that his defeat is imminent! He has sent Razlo Crushcog to prevent us from rebuilding our beloved Gnomeregan!', 12, 0, 100, 5, 0, 20890, 42758, 'High Tinker Mekkatorque'),
(42849, 1, 0, 'But $n has thwarted his plans at every turn, and the dwarves of Ironforge stand with us!', 12, 0, 100, 25, 0, 20891, 42759, 'High Tinker Mekkatorque'),
(42849, 2, 0, 'Let''s send him crawling back to his master in defeat!', 12, 0, 100, 5, 0, 20892, 42760, 'High Tinker Mekkatorque'),
(42849, 3, 0, 'We''ve done it! We''re victorious!', 12, 0, 100, 5, 0, 20893, 42763, 'High Tinker Mekkatorque'),
(42849, 4, 0, 'With Crushcog defeated, Thermaplugg is sure to be quaking in his mechano-tank, and rightly so. You''re next Thermaplugg. You''re next!', 12, 0, 100, 5, 0, 20894, 42765, 'High Tinker Mekkatorque'),
(42849, 5, 0, 'Mekkatorque-Cannon!', 14, 0, 100, 0, 0, 0, 42829, 'High Tinker Mekkatorque'),
(42849, 6, 0, 'Mekkatorque-Ray!', 14, 0, 100, 0, 0, 0, 42832, 'High Tinker Mekkatorque'),
(42849, 7, 0, 'Mekkatorque-Missiles!', 14, 0, 100, 0, 0, 0, 42833, 'High Tinker Mekkatorque'),
(42849, 8, 0, 'Mekkatorque-Beam!', 14, 0, 100, 0, 0, 0, 42834, 'High Tinker Mekkatorque');

-- Mountaineer Stonegrind
DELETE FROM `creature_text` WHERE `CreatureID` IN (42852);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42852, 0, 0, 'Aye, let''s teach this addle-brained gnome a lesson!', 12, 0, 100, 25, 0, 0, 42767, 'Mountaineer Stonegrind'),
(42852, 1, 0, 'That''ll teach you to mess with the might of Ironforge and Gnomeregan!', 12, 0, 100, 25, 0, 0, 42766, 'Mountaineer Stonegrind');

-- Razlo Crushcog
DELETE FROM `creature_text` WHERE `CreatureID` IN (42839);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42839, 0, 0, 'You! How did you escape detection by my sentry-bots?', 12, 0, 100, 0, 0, 21243, 42761, 'Razlo Crushcog'),
(42839, 1, 0, 'No matter! My guardians and I will make short work of you. To arms, men!', 12, 0, 100, 0, 0, 21244, 42762, 'Razlo Crushcog'),
(42839, 2, 0, 'You will never defeat the true sons of Gnomeregan!', 12, 0, 100, 0, 0, 21245, 42781, 'Razlo Crushcog');

-- Engineer Grindspark SAI
SET @ENTRY := 42553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Resst - Set Phase 1"),
(@ENTRY,0,1,0,20,1,100,0,26222,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Run Script"),
(@ENTRY,0,2,0,19,0,100,0,26205,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Accept - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,3,4,62,0,100,0,12634,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,5,0,20,0,100,0,26205,0,0,0,85,79435,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Invoker Cast''"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5070.834,455.209,410.7567,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,5,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 1"),
(@ENTRY*100,9,7,0,0,0,100,0,3500,3500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 2'"),
(@ENTRY*100,9,8,0,0,0,100,0,3500,3500,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Play Emote 'OneShotTalk'"),
(@ENTRY*100,9,9,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,42945,10,0,0,0,0,0,"Areatrigger - Script - Set Data 1 1 for GS-9x Prototype"),
(@ENTRY*100,9,10,0,0,0,100,0,7500,7500,0,0,69,0,0,0,0,0,0,8,0,0,0,-5073.268,454.8828,410.9308,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,11,0,0,0,100,0,1300,1300,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.321288,"Engineer Grindspark - Script - Turn to"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 3'"),
(@ENTRY*100,9,13,0,0,0,100,0,5000,5000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 1");
-- Engineer Grindspark text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Time to put the finishing touches on my bot.', 12, 0, 100, 5, 0, 0, 42947, 'Engineer Grindspark'),
(@ENTRY, 1, 0, 'At last, it''s finished.', 12, 0, 100, 25, 0, 0, 42948, 'Engineer Grindspark'),
(@ENTRY, 2, 0, 'Arise my, uh... what shall I call you? How about ''multi-bot''? Arise, my multi-bot!', 12, 0, 100, 5, 0, 0, 42949, 'Engineer Grindspark'),
(@ENTRY, 3, 0, 'Uh... a couple more tweaks should do it, I think...', 12, 0, 100, 6, 0, 0, 42950, 'Engineer Grindspark');

-- GS-9x Prototype SAI
SET @ENTRY := 42945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Reset - Cast 'Permanent Feign Death'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,10000,10000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Data Set - Run Script"),
(@ENTRY,0,2,3,40,0,100,0,8,@ENTRY,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Cast 'Cosmetic - Explosion'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,1000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Despawn"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove aura"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,19,536870912,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag2"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,4,12182,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Play Sound"),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Load Path");
-- Pathing for GS-9x Prototype
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5076.739,457.9864,410.2584, 'GS-9x Prototype'),
(@ENTRY,2,-5079.739,458.7364,409.0084, 'GS-9x Prototype'),
(@ENTRY,3,-5081.489,459.2364,408.0084, 'GS-9x Prototype'),
(@ENTRY,4,-5083.489,459.7364,407.2584, 'GS-9x Prototype'),
(@ENTRY,5,-5086.989,460.7364,406.5084, 'GS-9x Prototype'),
(@ENTRY,6,-5089.989,461.4864,405.7584, 'GS-9x Prototype'),
(@ENTRY,7,-5093.739,462.4864,405.0084, 'GS-9x Prototype'),
(@ENTRY,8,-5097.021,463.3582,404.2216, 'GS-9x Prototype');
