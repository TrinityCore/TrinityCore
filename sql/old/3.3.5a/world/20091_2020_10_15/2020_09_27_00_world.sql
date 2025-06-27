-- Fix wrong stats & reduce difference between normal and heroic templates
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 67 WHERE `entry` = 19429; -- Avian Darkhawk
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20686; -- Avian Darkhawk (1)
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.14286 WHERE `entry` = 21988; -- Avian Flyer (1)
UPDATE `creature_template` SET `minlevel` = 69, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 21989; -- Avian Ripper (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 21990; -- Avian Warhawk (1)
UPDATE `creature_template` SET `minlevel` = 70, `speed_walk` = 1, `unit_flags` = 64 WHERE `entry` = 20688; -- Cobalt Serpent (1)
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 69 WHERE `entry` = 18472; -- Darkweaver Syth
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20690; -- Darkweaver Syth (1)
UPDATE `creature_template` SET `maxlevel` = 68 WHERE `entry` = 18323; -- Sethekk Guard
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20692; -- Sethekk Guard (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20693; -- Sethekk Initiate (1)
UPDATE `creature_template` SET `maxlevel` = 68 WHERE `entry` = 18328; -- Sethekk Oracle
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20694; -- Sethekk Oracle (1)
UPDATE `creature_template` SET `maxlevel` = 69 WHERE `entry` = 18325; -- Sethekk Prophet
UPDATE `creature_template` SET `minlevel` = 71, `speed_walk` = 1, `speed_run` = 1 WHERE `entry` = 20695; -- Sethekk Prophet (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1600, `unit_flags` = 64 WHERE `entry` = 20696; -- Sethekk Ravenguard (1)
UPDATE `creature_template` SET `minlevel` = 72, `speed_walk` = 1, `BaseAttackTime` = 1600, `unit_flags` = 64 WHERE `entry` = 20699; -- Sethekk Shaman (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1800, `unit_flags` = 64 WHERE `entry` = 20701; -- Sethekk Talon Lord (1)
UPDATE `creature_template` SET `minlevel` = 69, `maxlevel` = 69 WHERE `entry` = 18473; -- Talon King Ikiss
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 20706; -- Talon King Ikiss (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20691; -- Time-Lost Controller (1)
UPDATE `creature_template` SET `maxlevel` = 68 WHERE `entry` = 18319; -- Time-Lost Scryer
UPDATE `creature_template` SET `minlevel` = 70, `speed_walk` = 1 WHERE `entry` = 20697; -- Time-Lost Scryer (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1800, `unit_flags` = 64 WHERE `entry` = 20698; -- Time-Lost Shadowmage (1)
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 18703; -- Sethekk Spirit
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 20700; -- Sethekk Spirit (1)
UPDATE `creature_template` SET `maxlevel` = 60, `speed_walk` = 1, `speed_run` = 0.99206, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 20343; -- Charming Totem
UPDATE `creature_template` SET `minlevel` = 69, `speed_walk` = 1, `speed_run` = 0.99206, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 20687; -- Charming Totem (1)
UPDATE `creature_template` SET `minlevel` = 67, `maxlevel` = 67, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 18701; -- Dark Vortex
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 20689; -- Dark Vortex (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` IN (19203,19204,19205,19206,20702,20703,20704,20705); -- Syth's elementals

-- Avian Ripper
/*
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (45134,45137,47275,47277);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(45134,45134,0,0,3,0,0),
(45134,45100,0,0,3,0,0),
(45134,45102,0,0,3,0,0),
(45134,45101,0,0,3,0,0),
(45134,45077,0,0,3,0,0),
(45137,45137,0,0,3,0,0),
(45137,46702,0,0,3,0,0),
(45137,45135,0,0,3,0,0),
(45137,46674,0,0,3,0,0),
(45137,45186,0,0,3,0,0),
(45137,45209,0,0,3,0,0),
(45137,45897,0,0,3,0,0),
(45137,46656,0,0,3,0,0),
(45137,45207,0,0,3,0,0),
(45137,45206,0,0,3,0,0),
(47275,47275,0,0,3,0,0),
(47275,47274,0,0,3,0,0),
(47275,47272,0,0,3,0,0),
(47275,47273,0,0,3,0,0),
(47275,46987,0,0,3,0,0),
(47277,47277,0,0,3,0,0),
(47277,47938,0,0,3,0,0),
(47277,47935,0,0,3,0,0),
(47277,47278,0,0,3,0,0),
(47277,47930,0,0,3,0,0);
*/

UPDATE `creature` SET `position_x` = -235.199, `position_y` = 185.947, `position_z` = 1.49576, `orientation` = 2.20961, `VerifiedBuild` = 12340 WHERE `guid` = 45134 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -227.287, `position_y` = 185.071, `position_z` = 3.31209, `orientation` = 0.35224, `VerifiedBuild` = 12340 WHERE `guid` = 45100 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -225.328, `position_y` = 196.138, `position_z` = 7.00514, `orientation` = 3.57880, `VerifiedBuild` = 12340 WHERE `guid` = 45102 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -222.748, `position_y` = 187.644, `position_z` = 4.64263, `orientation` = 5.92951, `VerifiedBuild` = 12340 WHERE `guid` = 45101 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -229.605, `position_y` = 190.134, `position_z` = 4.00196, `orientation` = 5.41000, `VerifiedBuild` = 12340 WHERE `guid` = 45077 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -252.052, `position_y` = 278.291, `position_z` = 27.2019, `orientation` = 4.03605, `VerifiedBuild` = 12340 WHERE `guid` = 45137 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -241.569, `position_y` = 280.768, `position_z` = 27.1944, `orientation` = 4.58557, `VerifiedBuild` = 12340 WHERE `guid` = 46702 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -246.583, `position_y` = 275.858, `position_z` = 27.0557, `orientation` = 5.84548, `VerifiedBuild` = 12340 WHERE `guid` = 45135 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -238.189, `position_y` = 275.694, `position_z` = 26.7466, `orientation` = 1.01719, `VerifiedBuild` = 12340 WHERE `guid` = 46674 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -256.163, `position_y` = 287.915, `position_z` = 26.8606, `orientation` = 4.77475, `VerifiedBuild` = 12340 WHERE `guid` = 45186 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -244.473, `position_y` = 289.472, `position_z` = 27.3912, `orientation` = 0.86289, `VerifiedBuild` = 12340 WHERE `guid` = 45209 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -237.256, `position_y` = 294.864, `position_z` = 27.0102, `orientation` = 4.73646, `VerifiedBuild` = 12340 WHERE `guid` = 45897 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -234.728, `position_y` = 286.701, `position_z` = 26.8191, `orientation` = 5.55045, `VerifiedBuild` = 12340 WHERE `guid` = 46656 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -248.445, `position_y` = 282.805, `position_z` = 27.5006, `orientation` = 6.15205, `VerifiedBuild` = 12340 WHERE `guid` = 45207 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -243.294, `position_y` = 288.046, `position_z` = 27.4778, `orientation` = 5.48582, `VerifiedBuild` = 12340 WHERE `guid` = 45206 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -213.887, `position_y` = 313.430, `position_z` = 34.4400, `orientation` = 3.68809, `VerifiedBuild` = 12340 WHERE `guid` = 47275 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -209.256, `position_y` = 312.305, `position_z` = 32.5998, `orientation` = 0.93447, `VerifiedBuild` = 12340 WHERE `guid` = 47274 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -214.734, `position_y` = 315.290, `position_z` = 32.2853, `orientation` = 2.76133, `VerifiedBuild` = 12340 WHERE `guid` = 47272 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -201.273, `position_y` = 313.070, `position_z` = 27.8368, `orientation` = 1.85617, `VerifiedBuild` = 12340 WHERE `guid` = 47273 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -210.865, `position_y` = 318.438, `position_z` = 30.8078, `orientation` = 0.93835, `VerifiedBuild` = 12340 WHERE `guid` = 46987 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -187.881, `position_y` = 327.553, `position_z` = 25.7592, `orientation` = 4.39441, `VerifiedBuild` = 12340 WHERE `guid` = 47277 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -188.226, `position_y` = 342.496, `position_z` = 27.4731, `orientation` = 3.44712, `VerifiedBuild` = 12340 WHERE `guid` = 47938 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -190.992, `position_y` = 334.775, `position_z` = 24.1323, `orientation` = 1.15075, `VerifiedBuild` = 12340 WHERE `guid` = 47935 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -178.998, `position_y` = 337.938, `position_z` = 27.3219, `orientation` = 1.38443, `VerifiedBuild` = 12340 WHERE `guid` = 47278 AND `id` = 21891;
UPDATE `creature` SET `position_x` = -181.154, `position_y` = 332.424, `position_z` = 26.1099, `orientation` = 2.66803, `VerifiedBuild` = 12340 WHERE `guid` = 47930 AND `id` = 21891;
UPDATE `creature` SET `wander_distance` = 2 WHERE `id` = 21891;

-- Critters
DELETE FROM `creature` WHERE `guid` IN (84262,86647,86648,86649,86650,86718,86720,86734,86735,86736,86737,86738,86739,86740,86741,86742,86743,86751,86752,86780,89279,95101,95102,95103,95107,130972,130973,130974,130975,130976,130977);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(84262, 2914, 556, 3, 1, 0, 20.4411, 4.78177, 0.00504, 3.23121, 300, 5, 1, 12340),
(86647, 2914, 556, 3, 1, 0, 47.2579, 34.4720, 0.0074, 1.62782, 300, 5, 1, 12340),
(86648, 2914, 556, 3, 1, 0, 66.6837, 101.475, 0.06310, 2.34481, 300, 5, 1, 12340),
(86649, 2914, 556, 3, 1, 0, -67.7293, 178.198, 0.01077, 3.88638, 300, 5, 1, 12340),
(86650, 2914, 556, 3, 1, 0, -116.564, 279.974, 26.9728, 0.19899, 300, 5, 1, 12340),
(86718, 2914, 556, 3, 1, 0, 23.5708, 293.130, 25.0942, 1.72880, 300, 5, 1, 12340),
(86720, 3300, 556, 3, 1, 0, -254.628, 170.189, 0.17454, 5.84685, 300, 0, 0, 12340),
(86734, 3300, 556, 3, 1, 0, -247.199, 294.800, 27.0599, 0.30800, 300, 5, 1, 12340),
(86735, 3300, 556, 3, 1, 0, -189.204, 316.802, 26.7118, 5.04503, 300, 5, 1, 12340),
(86736, 4075, 556, 3, 1, 0, -218.644, 341.310, 26.8966, 4.01301, 300, 5, 1, 12340),
(86737, 4075, 556, 3, 1, 0, -55.1718, 269.534, 26.8482, 3.16974, 300, 5, 1, 12340),
(86738, 4075, 556, 3, 1, 0, -85.7282, 113.407, 0.00719, 0.74041, 300, 5, 1, 12340),
(86739, 4075, 556, 3, 1, 0, -163.745, 166.369, 0.00686, 1.47833, 300, 5, 1, 12340),
(86740, 4075, 556, 3, 1, 0, -149.696, 199.330, 0.01076, 0.94774, 300, 5, 1, 12340),
(86741, 4075, 556, 3, 1, 0, -224.816, 180.553, 1.73431, 4.78220, 300, 5, 1, 12340),
(86742, 4076, 556, 3, 1, 0, 47.0275, -0.31095, 0.00697, 4.09243, 300, 5, 1, 12340),
(86743, 4076, 556, 3, 1, 0, 9.24132, 91.1123, 0.12924, 1.34344, 300, 5, 1, 12340),
(86751, 4076, 556, 3, 1, 0, -21.9051, 96.0083, 0.00954, 0.08577, 300, 5, 1, 12340),
(86752, 4076, 556, 3, 1, 0, -44.6355, 91.4519, 0.36346, 3.61135, 300, 5, 1, 12340),
(86780, 4076, 556, 3, 1, 0, -74.8093, 156.331, 0.00707, 5.78743, 300, 5, 1, 12340),
(89279, 4076, 556, 3, 1, 0, -123.420, 176.658, 0.01076, 5.56882, 300, 5, 1, 12340),
(95101, 4076, 556, 3, 1, 0, -202.105, 179.907, 0.09477, 2.16420, 300, 5, 1, 12340),
(95102, 4076, 556, 3, 1, 0, -236.364, 226.582, 26.7249, 1.51261, 300, 5, 1, 12340),
(95103, 4076, 556, 3, 1, 0, -80.2957, 317.625, 27.2346, 5.95815, 300, 5, 1, 12340),
(95107, 4076, 556, 3, 1, 0, 61.9060, 248.264, 26.5267, 1.21204, 300, 5, 1, 12340),
(130972, 14881, 556, 3, 1, 0, -213.718, 177.578, 27.0923, 0, 300, 0, 0, 12340),
(130973, 14881, 556, 3, 1, 0, -244.417, 199.308, 0.14756, 2.56563, 300, 0, 0, 12340),
(130974, 14881, 556, 3, 1, 0, -248.428, 247.220, 26.7268, 1.84640, 300, 5, 1, 12340),
(130975, 14881, 556, 3, 1, 0, -148.939, 280.836, 26.7320, 4.14789, 300, 5, 1, 12340),
(130976, 14881, 556, 3, 1, 0, 11.3015, 265.329, 26.2511, 0.54966, 300, 5, 1, 12340),
(130977, 14881, 556, 3, 1, 0, 54.8938, 328.390, 26.6239, 1.03979, 300, 5, 1, 12340);
