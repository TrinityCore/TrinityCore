-- To A'lar
UPDATE `creature` SET `position_x` = 104.595, `position_y` = -11.3571, `position_z` = -2.25123, `orientation` = 2.46091, `VerifiedBuild` = 15354 WHERE `guid` = 12448 AND `id` = 20031;
UPDATE `creature` SET `position_x` = 108.159, `position_y` = -8.67961, `position_z` = -2.24247, `orientation` = 1.15192, `VerifiedBuild` = 15354, `id` = 20032 WHERE `guid` = 12446 AND `id` = 20033;
UPDATE `creature` SET `position_x` = 62.1931, `position_y` = -6.53074, `position_z` = -2.34494, `orientation` = 2.74017, `VerifiedBuild` = 15354 WHERE `guid` = 12484 AND `id` = 20031;
UPDATE `creature` SET `position_x` = 191.414, `position_y` = -5.72624, `position_z` = -2.35336, `orientation` = 3.01942, `VerifiedBuild` = 15354 WHERE `guid` = 12480 AND `id` = 20031;
UPDATE `creature` SET `position_x` = 187.621, `position_y` = -10.937, `position_z` = -2.3892, `orientation` = 2.86234, `VerifiedBuild` = 15354 WHERE `guid` = 12454 AND `id` = 20033;
UPDATE `creature` SET `position_x` = 188.956, `position_y` = 5.88125, `position_z` = -2.3803, `orientation` = 3.33358, `VerifiedBuild` = 15354 WHERE `guid` = 12487 AND `id` = 20032;
UPDATE `creature` SET `position_x` = 61.6321, `position_y` = 3.35163, `position_z` = -2.34492, `orientation` = 3.63028, `VerifiedBuild` = 15354 WHERE `guid` = 12485 AND `id` = 20031;

DELETE FROM `creature` WHERE `guid` = 44023 AND `id` = 20031;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(44023,20031,550,1,1,0,1,191.375,3.30484,-2.35456,3.26377,7200,0,0,15354);
DELETE FROM `spawn_group` WHERE `spawnId` = 44023 AND `spawnType` = 0 AND `groupId` = 44;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(44,0,44023);

UPDATE `creature` SET `position_x` = 188.045, `position_y` = 8.61233, `position_z` = -2.39762, `orientation` = 3.42085, `VerifiedBuild` = 15354 WHERE `guid` = 12486 AND `id` = 20034;
UPDATE `creature` SET `position_x` = 188.992, `position_y` = -8.09278, `position_z` = -2.37145, `orientation` = 2.94961, `VerifiedBuild` = 15354, `id` = 20032 WHERE `guid` = 12455 AND `id` = 20033;
UPDATE `creature` SET `position_x` = 53.3193, `position_y` = 7.81006, `position_z` = -2.34492, `orientation` = 4.5204, `VerifiedBuild` = 15354, `id` = 20033 WHERE `guid` = 12453 AND `id` = 20034;
UPDATE `creature` SET `position_x` = 53.8861, `position_y` = -10.7066, `position_z` = -2.34495, `orientation` = 1.8326, `VerifiedBuild` = 15354 WHERE `guid` = 12451 AND `id` = 20034;

DELETE FROM `creature` WHERE `guid` = 44024 AND `id` = 20032;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(44024,20032,550,1,1,0,1,57.8223,7.00091,-2.34492,4.10152,7200,0,0,15354);
DELETE FROM `spawn_group` WHERE `spawnId` = 44024 AND `spawnType` = 0 AND `groupId` = 44;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(44,0,44024);

UPDATE `creature` SET `position_x` = 58.5711, `position_y` = -10.2187, `position_z` = -2.34494, `orientation` = 2.26893, `VerifiedBuild` = 15354 WHERE `guid` = 12452 AND `id` = 20033;
UPDATE `creature` SET `position_x` = 104.795, `position_y` = 8.55721, `position_z` = -2.25027, `orientation` = 3.80482, `VerifiedBuild` = 15354 WHERE `guid` = 12449 AND `id` = 20031;
UPDATE `creature` SET `position_x` = 113.951, `position_y` = 5.66478, `position_z` = -2.24247, `orientation` = 4.36332, `VerifiedBuild` = 15354, `id` = 20033 WHERE `guid` = 12447 AND `id` = 20034;
UPDATE `creature` SET `position_x` = 108.604, `position_y` = 5.36372, `position_z` = -2.24215, `orientation` = 5.11381, `VerifiedBuild` = 15354 WHERE `guid` = 12450 AND `id` = 20032;
UPDATE `creature` SET `position_x` = 114.112, `position_y` = -8.94633, `position_z` = -2.24276, `orientation` = 1.90241, `VerifiedBuild` = 15354 WHERE `guid` = 12445 AND `id` = 20034;

-- Void Reaver
UPDATE `creature` SET `position_x` = 522.524, `position_y` = 136.295, `position_z` = 20.336, `orientation` = 2.94961, `VerifiedBuild` = 15354 WHERE `guid` = 12543 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 528.337, `position_y` = 159.21, `position_z` = 20.3332, `orientation` = 3.07178, `VerifiedBuild` = 15354 WHERE `guid` = 12544 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 499.913, `position_y` = 234.991, `position_z` = 20.3294, `orientation` = 5.91667, `VerifiedBuild` = 15354 WHERE `guid` = 12462 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 516.177, `position_y` = 243.245, `position_z` = 20.3168, `orientation` = 4.69494, `VerifiedBuild` = 15354 WHERE `guid` = 12458 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 423.913, `position_y` = 327.611, `position_z` = 15.2007, `orientation` = 1.48353, `VerifiedBuild` = 15354 WHERE `guid` = 12552 AND `id` = 20040;
UPDATE `creature` SET `position_x` = 457.151, `position_y` = 344.334, `position_z` = 14.9878, `orientation` = 4.99164, `VerifiedBuild` = 15354 WHERE `guid` = 12561 AND `id` = 20042;
UPDATE `creature` SET `position_x` = 425.733, `position_y` = 323.265, `position_z` = 15.5336, `orientation` = 1.8675, `VerifiedBuild` = 15354 WHERE `guid` = 12553 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 418.131, `position_y` = 328.526, `position_z` = 15.5518, `orientation` = 6.12611, `VerifiedBuild` = 15354 WHERE `guid` = 75558 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 454.04, `position_y` = 334.52, `position_z` = 15.2268, `orientation` = 0.279253, `VerifiedBuild` = 15354 WHERE `guid` = 12551 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 426.618, `position_y` = 334.85, `position_z` = 14.6985, `orientation` = 4.29351, `VerifiedBuild` = 15354 WHERE `guid` = 12563 AND `id` = 20042;
UPDATE `creature` SET `position_x` = 459.577, `position_y` = 337.187, `position_z` = 15.2522, `orientation` = 2.35619, `VerifiedBuild` = 15354 WHERE `guid` = 12461 AND `id` = 20040;
UPDATE `creature` SET `position_x` = 465.414, `position_y` = 336.68, `position_z` = 15.8237, `orientation` = 2.58309, `VerifiedBuild` = 15354 WHERE `guid` = 12550 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 468.497, `position_y` = 382.066, `position_z` = 14.9938, `orientation` = 0.925025, `VerifiedBuild` = 15354 WHERE `guid` = 12562 AND `id` = 20042;
UPDATE `creature` SET `position_x` = 481.119, `position_y` = 376.113, `position_z` = 15.8953, `orientation` = 2.37365, `VerifiedBuild` = 15354 WHERE `guid` = 84444 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 476.323, `position_y` = 378.244, `position_z` = 15.319, `orientation` = 3.35103, `VerifiedBuild` = 15354 WHERE `guid` = 12558 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 397.997, `position_y` = 361.119, `position_z` = 14.9771, `orientation` = 3.42085, `VerifiedBuild` = 15354 WHERE `guid` = 84484 AND `id` = 20042;
UPDATE `creature` SET `position_x` = 393.282, `position_y` = 353.826, `position_z` = 15.3139, `orientation` = 0.349066, `VerifiedBuild` = 15354 WHERE `guid` = 12555 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 388.995, `position_y` = 355.609, `position_z` = 15.7319, `orientation` = 5.68977, `VerifiedBuild` = 15354 WHERE `guid` = 12556 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 469.932, `position_y` = 393.257, `position_z` = 15.0503, `orientation` = 5.06145, `VerifiedBuild` = 15354 WHERE `guid` = 12560 AND `id` = 20052;
UPDATE `creature` SET `position_x` = 473.639, `position_y` = 388.329, `position_z` = 15.3246, `orientation` = 3.49066, `VerifiedBuild` = 15354 WHERE `guid` = 12559 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 389.993, `position_y` = 363.854, `position_z` = 15.3363, `orientation` = 0.279253, `VerifiedBuild` = 15354 WHERE `guid` = 12554 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 424.235, `position_y` = 403.475, `position_z` = 14.9773, `orientation` = 4.99164, `VerifiedBuild` = 15354 WHERE `guid` = 12478 AND `id` = 19516;
UPDATE `creature` SET `position_x` = 390.007, `position_y` = 370.393, `position_z` = 15.2625, `orientation` = 4.27606, `VerifiedBuild` = 15354 WHERE `guid` = 12557 AND `id` = 20052;

-- To Solarian
UPDATE `creature` SET `position_x` = 505.014, `position_y` = -159.06, `position_z` = 20.4535, `orientation` = 6.19592, `VerifiedBuild` = 15354 WHERE `guid` = 12423 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 502.859, `position_y` = -151.514, `position_z` = 22.0813, `orientation` = 1.309, `VerifiedBuild` = 15354 WHERE `guid` = 12428 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 505.813, `position_y` = -148.402, `position_z` = 20.3507, `orientation` = 3.92699, `VerifiedBuild` = 15354 WHERE `guid` = 12426 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 508.967, `position_y` = -158.539, `position_z` = 20.3488, `orientation` = 2.74017, `VerifiedBuild` = 15354 WHERE `guid` = 12427 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 504.446, `position_y` = -156.253, `position_z` = 21.616, `orientation` = 0.331613, `VerifiedBuild` = 15354 WHERE `guid` = 12424 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 505.606, `position_y` = -151.263, `position_z` = 20.3535, `orientation` = 2.56563, `VerifiedBuild` = 15354 WHERE `guid` = 12429 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 507.289, `position_y` = -160.424, `position_z` = 20.3595, `orientation` = 2.32129, `VerifiedBuild` = 15354 WHERE `guid` = 12430 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 503.468, `position_y` = -153.307, `position_z` = 20.5073, `orientation` = 5.5676, `VerifiedBuild` = 15354, `id` = 20044 WHERE `guid` = 12425 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 502.495, `position_y` = -149.418, `position_z` = 20.3666, `orientation` = 4.90438, `VerifiedBuild` = 15354, `id` = 20043, `equipment_id` = 0 WHERE `guid` = 12422 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 506.166, `position_y` = -154.226, `position_z` = 20.3567, `orientation` = 3.9619, `VerifiedBuild` = 15354, `id` = 20043, `equipment_id` = 0 WHERE `guid` = 12421 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 530.071, `position_y` = -158.822, `position_z` = 20.3428, `orientation` = 3.59538, `VerifiedBuild` = 15354 WHERE `guid` = 12468 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 523.206, `position_y` = -137.925, `position_z` = 20.3386, `orientation` = 3.47321, `VerifiedBuild` = 15354 WHERE `guid` = 12466 AND `id` = 20041;
UPDATE `creature` SET `position_x` = 506.688, `position_y` = -157.552, `position_z` = 20.3571, `orientation` = 3.94444, `VerifiedBuild` = 15354, `id` = 20036 WHERE `guid` = 12471 AND `id` = 20034;
UPDATE `creature` SET `position_x` = 503.185, `position_y` = -146.249, `position_z` = 20.3612, `orientation` = 5.5676, `VerifiedBuild` = 15354, `id` = 20036 WHERE `guid` = 12472 AND `id` = 20032;
UPDATE `creature` SET `position_x` = 498.681, `position_y` = -241.203, `position_z` = 20.3194, `orientation` = 1.69297, `VerifiedBuild` = 15354 WHERE `guid` = 12413 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 500.876, `position_y` = -238.636, `position_z` = 20.3007, `orientation` = 4.7473, `VerifiedBuild` = 15354 WHERE `guid` = 12415 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 504.222, `position_y` = -240.496, `position_z` = 20.3758, `orientation` = 4.18879, `VerifiedBuild` = 15354 WHERE `guid` = 12414 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 501.313, `position_y` = -241.167, `position_z` = 20.2896, `orientation` = 0.541052, `VerifiedBuild` = 15354 WHERE `guid` = 12411 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 504.087, `position_y` = -237.534, `position_z` = 20.3063, `orientation` = 3.82227, `VerifiedBuild` = 15354 WHERE `guid` = 12410 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 502.845, `position_y` = -244.156, `position_z` = 20.3911, `orientation` = 1.23918, `VerifiedBuild` = 15354 WHERE `guid` = 12412 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 513.877, `position_y` = -247.938, `position_z` = 20.2956, `orientation` = 1.62316, `VerifiedBuild` = 15354 WHERE `guid` = 12420 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 510.537, `position_y` = -246.791, `position_z` = 20.2972, `orientation` = 6.17847, `VerifiedBuild` = 15354 WHERE `guid` = 12416 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 516.322, `position_y` = -245.612, `position_z` = 20.313, `orientation` = 3.22886, `VerifiedBuild` = 15354 WHERE `guid` = 12417 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 516.495, `position_y` = -247.968, `position_z` = 20.3432, `orientation` = 1.53589, `VerifiedBuild` = 15354, `id` = 20043 WHERE `guid` = 12418 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 514.988, `position_y` = -242.226, `position_z` = 20.329, `orientation` = 4.45059, `VerifiedBuild` = 15354 WHERE `guid` = 12419 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 512.658, `position_y` = -244.061, `position_z` = 20.3157, `orientation` = 5.65487, `VerifiedBuild` = 15354, `id` = 20044, `equipment_id` = 0 WHERE `guid` = 12473 AND `id` = 20033;

-- Solarian
UPDATE `creature` SET `position_x` = 531.524, `position_y` = -379.077, `position_z` = 22.1002, `orientation` = 2.67035, `VerifiedBuild` = 15354 WHERE `guid` = 12492 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 528.726, `position_y` = -364.973, `position_z` = 22.1002, `orientation` = 5.41052, `VerifiedBuild` = 15354 WHERE `guid` = 12490 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 526.949, `position_y` = -375.876, `position_z` = 22.1001, `orientation` = 4.90438, `VerifiedBuild` = 15354 WHERE `guid` = 12491 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 527.223, `position_y` = -368.722, `position_z` = 22.1002, `orientation` = 0.680678, `VerifiedBuild` = 15354 WHERE `guid` = 12493 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 527.879, `position_y` = -381.096, `position_z` = 22.1001, `orientation` = 0.575959, `VerifiedBuild` = 15354, `id` = 20043 WHERE `guid` = 12488 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 531.457, `position_y` = -366.802, `position_z` = 22.1002, `orientation` = 3.38594, `VerifiedBuild` = 15354 WHERE `guid` = 12489 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 432.74, `position_y` = -373.645, `position_z` = 18.0138, `orientation` = 1.39626, `VerifiedBuild` = 15354 WHERE `guid` = 12477 AND `id` = 18805;
UPDATE `creature` SET `position_x` = 354.351, `position_y` = -317.713, `position_z` = 22.1003, `orientation` = 3.29867, `VerifiedBuild` = 15354 WHERE `guid` = 12527 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 519.811, `position_y` = -413.351, `position_z` = 22.1002, `orientation` = 5.27089, `VerifiedBuild` = 15354 WHERE `guid` = 12496 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 518.084, `position_y` = -415.48, `position_z` = 22.1003, `orientation` = 0.331613, `VerifiedBuild` = 15354 WHERE `guid` = 12495 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 513.288, `position_y` = -421.953, `position_z` = 22.1003, `orientation` = 5.11381, `VerifiedBuild` = 15354 WHERE `guid` = 12497 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 352.458, `position_y` = -319.709, `position_z` = 22.1003, `orientation` = 1.81514, `VerifiedBuild` = 15354 WHERE `guid` = 12528 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 343.001, `position_y` = -330.82, `position_z` = 22.1003, `orientation` = 5.55015, `VerifiedBuild` = 15354 WHERE `guid` = 12525 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 521.402, `position_y` = -415.551, `position_z` = 22.1003, `orientation` = 2.84489, `VerifiedBuild` = 15354 WHERE `guid` = 12499 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 351.418, `position_y` = -316.259, `position_z` = 22.1003, `orientation` = 5.14872, `VerifiedBuild` = 15354 WHERE `guid` = 12523 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 346.987, `position_y` = -331.116, `position_z` = 22.1003, `orientation` = 2.47837, `VerifiedBuild` = 15354 WHERE `guid` = 12526 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 335.097, `position_y` = -368.078, `position_z` = 22.1003, `orientation` = 6.05629, `VerifiedBuild` = 15354 WHERE `guid` = 12521 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 340.303, `position_y` = -370.587, `position_z` = 22.1003, `orientation` = 2.28638, `VerifiedBuild` = 15354 WHERE `guid` = 12518 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 515.806, `position_y` = -426.442, `position_z` = 22.1003, `orientation` = 2.56563, `VerifiedBuild` = 15354 WHERE `guid` = 12498 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 512.518, `position_y` = -425.02, `position_z` = 22.1003, `orientation` = 0.802851, `VerifiedBuild` = 15354 WHERE `guid` = 12500 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 338.58, `position_y` = -366.39, `position_z` = 22.1003, `orientation` = 4.99164, `VerifiedBuild` = 15354 WHERE `guid` = 12519 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 344.225, `position_y` = -333.593, `position_z` = 22.1002, `orientation` = 2.28638, `VerifiedBuild` = 15354 WHERE `guid` = 12524 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 388.687, `position_y` = -457.694, `position_z` = 22.1003, `orientation` = 1.8326, `VerifiedBuild` = 15354 WHERE `guid` = 12516 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 380.025, `position_y` = -451.003, `position_z` = 22.1003, `orientation` = 3.47321, `VerifiedBuild` = 15354 WHERE `guid` = 12513 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 425.113, `position_y` = -471.939, `position_z` = 22.1003, `orientation` = 0.261799, `VerifiedBuild` = 15354 WHERE `guid` = 12508 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 428.962, `position_y` = -474.042, `position_z` = 22.1003, `orientation` = 1.90241, `VerifiedBuild` = 15354 WHERE `guid` = 12506 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 439.473, `position_y` = -468.015, `position_z` = 22.1003, `orientation` = 3.90954, `VerifiedBuild` = 15354 WHERE `guid` = 12504 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 375.265, `position_y` = -452.356, `position_z` = 22.1003, `orientation` = 4.59022, `VerifiedBuild` = 15354 WHERE `guid` = 12514 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 330.858, `position_y` = -377.786, `position_z` = 22.1003, `orientation` = 5.91667, `VerifiedBuild` = 15354, `id` = 20043 WHERE `guid` = 12520 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 337.739, `position_y` = -380.531, `position_z` = 22.1003, `orientation` = 2.89725, `VerifiedBuild` = 15354 WHERE `guid` = 12517 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 427.989, `position_y` = -468.895, `position_z` = 22.1003, `orientation` = 4.62512, `VerifiedBuild` = 15354 WHERE `guid` = 12507 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 435.639, `position_y` = -466.829, `position_z` = 22.1003, `orientation` = 5.02655, `VerifiedBuild` = 15354 WHERE `guid` = 12503 AND `id` = 20043;
UPDATE `creature` SET `position_x` = 388.877, `position_y` = -462.481, `position_z` = 22.1003, `orientation` = 1.62316, `VerifiedBuild` = 15354 WHERE `guid` = 12510 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 335.748, `position_y` = -376.818, `position_z` = 22.1003, `orientation` = 4.64258, `VerifiedBuild` = 15354 WHERE `guid` = 12522 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 438.087, `position_y` = -471.081, `position_z` = 22.1003, `orientation` = 1.39626, `VerifiedBuild` = 15354 WHERE `guid` = 12505 AND `id` = 20036;
UPDATE `creature` SET `position_x` = 391.798, `position_y` = -459.901, `position_z` = 22.1003, `orientation` = 3.94444, `VerifiedBuild` = 15354 WHERE `guid` = 12512 AND `id` = 20044;
UPDATE `creature` SET `position_x` = 376.944, `position_y` = -455.145, `position_z` = 22.1003, `orientation` = 5.60251, `VerifiedBuild` = 15354 WHERE `guid` = 12511 AND `id` = 20043;
DELETE FROM `creature` WHERE `guid` IN (12494,12501,12502,12509,12515,12529,12531,12530,12532,12533,12534,12535,12536,12474,12469,12470) AND `id` IN (20031,20033,20036,20043,20044);
DELETE FROM `spawn_group` WHERE `spawnId` IN (12494,12501,12502,12509,12515,12529,12531,12530,12532,12533,12534,12535,12536,12474,12469,12470) AND `groupId` = 46 AND `spawnType` = 0;

-- Other
UPDATE `creature` SET `VerifiedBuild` = 15354 WHERE `map` = 550 AND `id` IN (20047,20049,12999,15384,19622,20060,20062,20063,20064,22515,22517);
UPDATE `creature` SET `VerifiedBuild` = 15354 WHERE `guid` NOT IN (12456) AND `id` = 20035;
UPDATE `creature` SET `VerifiedBuild` = 15354 WHERE `guid` NOT IN (86939,86941,12463,12464) AND `id` = 20048;
UPDATE `creature` SET `VerifiedBuild` = 15354 WHERE `guid` NOT IN (86940,12465) AND `id` = 20050;
-- Not needed
DELETE FROM `creature` WHERE `id` = 18928;



-- Waypoints
-- Phoenix-Hawk
UPDATE `creature` SET `position_x` = 393.09442, `position_y` = 71.806984, `position_z` = 20.179274 WHERE `guid` = 554 AND `id` = 20039;
UPDATE `creature` SET `position_x` = 407.83536, `position_y` = 44.418842, `position_z` = 20.179426 WHERE `guid` = 12433 AND `id` = 20039;
UPDATE `creature` SET `position_x` = 237.7101, `position_y` = -3.185129, `position_z` = 26.845533 WHERE `guid` = 12434 AND `id` = 20039;
UPDATE `creature` SET `position_x` = 409.35928, `position_y` = -46.213287, `position_z` = 20.180698 WHERE `guid` = 12475 AND `id` = 20039;
DELETE FROM `waypoint_data` WHERE `id` IN (5540,124330,124340,124750);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(5540,1,393.09442,71.806984,20.179274,0,0,1,0,0,0),
(5540,2,364.4904,86.93881,19.899294,0,0,1,0,0,0),
(5540,3,315.06958,88.61644,20.179047,0,0,1,0,0,0),
(5540,4,278.68005,77.846535,20.179838,0,0,1,0,0,0),
(5540,5,247.10265,42.687233,20.1815,0,0,1,0,0,0),
(5540,6,238.54498,-0.783009,27.160496,0,0,1,0,0,0),
(5540,7,248.1438,-44.6957,20.179852,0,0,1,0,0,0),
(5540,8,267.64313,-70.481125,20.180151,0,0,1,0,0,0),
(5540,9,304.74136,-89.18661,20.179611,0,0,1,0,0,0),
(5540,10,342.51788,-91.57152,20.239723,0,0,1,0,0,0),
(5540,11,372.6342,-85.409676,19.976614,0,0,1,0,0,0),
(5540,12,390.3265,-72.53096,20.179316,0,0,1,0,0,0),
(5540,13,408.78253,-48.827328,20.180618,0,0,1,0,0,0),
(5540,14,423.3208,-14.964696,20.179365,0,0,1,0,0,0),
(5540,15,423.24957,11.023921,20.179274,0,0,1,0,0,0),
(5540,16,409.24487,45.13489,20.179453,0,0,1,0,0,0),
(124330,1,407.83536,44.418842,20.179426,0,0,1,0,0,0),
(124330,2,400.30106,58.746677,20.179379,0,0,1,0,0,0),
(124330,3,378.6678,78.538414,20.175188,0,0,1,0,0,0),
(124330,4,351.08105,85.944336,20.148655,0,0,1,0,0,0),
(124330,5,309.90018,86.33295,20.179213,0,0,1,0,0,0),
(124330,6,284.328,78.01011,20.17977,0,0,1,0,0,0),
(124330,7,258.2736,58.820984,20.17975,0,0,1,0,0,0),
(124330,8,244.32275,38.13153,20.180424,0,0,1,0,0,0),
(124330,9,258.2736,58.820984,20.17975,0,0,1,0,0,0),
(124330,10,284.328,78.01011,20.17977,0,0,1,0,0,0),
(124330,11,309.90018,86.33295,20.179213,0,0,1,0,0,0),
(124330,12,351.08105,85.944336,20.148655,0,0,1,0,0,0),
(124330,13,378.6678,78.538414,20.175188,0,0,1,0,0,0),
(124330,14,400.30106,58.746677,20.179379,0,0,1,0,0,0),
(124340,1,237.7101,-3.185129,26.845533,0,0,1,0,0,0),
(124340,2,244.19905,41.52916,20.181135,0,0,1,0,0,0),
(124340,3,264.55344,65.30175,20.179731,0,0,1,0,0,0),
(124340,4,306.48563,88.13809,20.179314,0,0,1,0,0,0),
(124340,5,351.13263,89.27576,20.209774,0,0,1,0,0,0),
(124340,6,390.0448,72.604225,20.179249,0,0,1,0,0,0),
(124340,7,411.91235,43.539856,20.179478,0,0,1,0,0,0),
(124340,8,424.0854,14.535274,20.179274,0,0,1,0,0,0),
(124340,9,423.90387,-27.01116,20.179367,0,0,1,0,0,0),
(124340,10,409.96698,-46.97388,20.179514,0,0,1,0,0,0),
(124340,11,392.50244,-74.72135,20.179327,0,0,1,0,0,0),
(124340,12,357.12787,-90.9714,20.050903,0,0,1,0,0,0),
(124340,13,308.62036,-90.155365,20.179478,0,0,1,0,0,0),
(124340,14,278.25125,-78.9372,20.179787,0,0,1,0,0,0),
(124340,15,245.54774,-44.11123,20.179893,0,0,1,0,0,0),
(124750,1,409.35928,-46.213287,20.180698,0,0,1,0,0,0),
(124750,2,398.48242,-65.72802,20.179398,0,0,1,0,0,0),
(124750,3,371.6328,-83.46188,19.915161,0,0,1,0,0,0),
(124750,4,332.14322,-90.43943,20.276579,0,0,1,0,0,0),
(124750,5,295.8723,-83.535995,20.179678,0,0,1,0,0,0),
(124750,6,269.5972,-71.95888,20.180143,0,0,1,0,0,0),
(124750,7,251.01363,-49.446224,20.179844,0,0,1,0,0,0),
(124750,8,243.69856,-30.80361,20.173084,0,0,1,0,0,0),
(124750,9,251.01363,-49.446224,20.179844,0,0,1,0,0,0),
(124750,10,269.5972,-71.95888,20.180143,0,0,1,0,0,0),
(124750,11,295.8723,-83.535995,20.179678,0,0,1,0,0,0),
(124750,12,332.14322,-90.43943,20.276579,0,0,1,0,0,0),
(124750,13,371.6328,-83.46188,19.915161,0,0,1,0,0,0),
(124750,14,398.48242,-65.72802,20.179398,0,0,1,0,0,0);

-- Astromancer Lord
UPDATE `creature` SET `position_x` = 473.84668, `position_y` = -84.87884, `position_z` = 20.216114 WHERE `guid` IN (12467,12431,12432) AND `id` IN (20046,20031);
DELETE FROM `waypoint_data` WHERE `id` IN (124670);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(124670,1,473.84668,-84.87884,20.216114,0,0,0,0,0,0),
(124670,2,491.02115,-103.594,20.289867,0,0,0,0,0,0),
(124670,3,502.49777,-118.99611,20.28987,0,0,0,0,0,0),
(124670,4,511.05252,-140.89236,20.237894,0,0,0,0,0,0),
(124670,5,517.2678,-163.51216,20.239647,0,0,0,0,0,0),
(124670,6,520.5802,-185.61877,20.289864,0,0,0,0,0,0),
(124670,7,517.4262,-208.08437,20.289856,0,0,0,0,0,0),
(124670,8,511.51535,-232.16605,20.341183,0,0,0,0,0,0),
(124670,9,517.4262,-208.08437,20.289856,0,0,0,0,0,0),
(124670,10,520.61035,-185.82002,20.289864,0,0,0,0,0,0),
(124670,11,517.2678,-163.51216,20.239647,0,0,0,0,0,0),
(124670,12,511.05252,-140.89236,20.237894,0,0,0,0,0,0),
(124670,13,502.49777,-118.99611,20.28987,0,0,0,0,0,0),
(124670,14,491.02115,-103.594,20.289867,0,0,0,0,0,0);

-- Crimson Hand Inquisitor
UPDATE `creature` SET `position_x` = 657.5163, `position_y` = 70.17264, `position_z` = 46.771988 WHERE `guid` IN (86940,86939,86941) AND `id` IN (20048,20050);
UPDATE `creature` SET `position_x` = 569.4054, `position_y` = -134.02185, `position_z` = 33.9291 WHERE `guid` IN (12465,12463,12464) AND `id` IN (20048,20050);
DELETE FROM `waypoint_data` WHERE `id` IN (869400,124650);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(869400,1,657.5163,70.17264,46.771988,0,0,0,0,0,0),
(869400,2,642.7598,88.49879,46.82853,0,0,0,0,0,0),
(869400,3,627.3768,104.11148,46.740147,0,0,0,0,0,0),
(869400,4,612.29346,113.80901,43.520176,0,0,0,0,0,0),
(869400,5,596.7023,121.07731,38.243553,0,0,0,0,0,0),
(869400,6,586.87726,125.51434,36.05955,0,0,0,0,0,0),
(869400,7,578.00616,129.33405,35.686752,0,0,0,0,0,0),
(869400,8,564.6969,134.79558,32.850464,0,0,0,0,0,0),
(869400,9,578.00616,129.33405,35.686752,0,0,0,0,0,0),
(869400,10,586.87726,125.51434,36.05955,0,0,0,0,0,0),
(869400,11,596.7023,121.07731,38.243553,0,0,0,0,0,0),
(869400,12,612.29346,113.80901,43.520176,0,0,0,0,0,0),
(869400,13,627.3768,104.11148,46.740147,0,0,0,0,0,0),
(869400,14,642.7598,88.49879,46.82853,0,0,0,0,0,0),
(124650,1,569.4054,-134.02185,33.9291,0,0,0,0,0,0),
(124650,2,588.5716,-126.52433,36.050453,0,0,0,0,0,0),
(124650,3,597.0831,-122.83465,38.35739,0,0,0,0,0,0),
(124650,4,614.51105,-114.18895,44.410213,0,0,0,0,0,0),
(124650,5,629.024,-104.85851,46.76857,0,0,0,0,0,0),
(124650,6,644.30804,-89.03651,46.81918,0,0,0,0,0,0),
(124650,7,658.1658,-70.976105,46.769356,0,0,0,0,0,0),
(124650,8,644.30804,-89.03651,46.81918,0,0,0,0,0,0),
(124650,9,629.024,-104.85851,46.76857,0,0,0,0,0,0),
(124650,10,614.51105,-114.18895,44.410213,0,0,0,0,0,0),
(124650,11,597.0831,-122.83465,38.35739,0,0,0,0,0,0),
(124650,12,588.5716,-126.52433,36.050453,0,0,0,0,0,0);

-- Crystalcore Devastator 1
UPDATE `creature` SET `position_x` = 475.72092, `position_y` = 86.03086, `position_z` = 20.252535 WHERE `guid` = 12549 AND `id` = 20040;
DELETE FROM `waypoint_data` WHERE `id` IN (125490);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(125490,1,475.72092,86.03086,20.252535,0,0,0,0,0,0),
(125490,2,486.81604,97.507996,20.289883,0,0,0,0,0,0),
(125490,3,497.40924,110.58228,20.289906,0,0,0,0,0,0),
(125490,4,507.257,127.883,20.271929,0,0,0,0,0,0),
(125490,5,514.15625,150.00967,20.235924,0,0,0,0,0,0),
(125490,6,520.88763,179.39882,20.278658,0,0,0,0,0,0),
(125490,7,518.6552,206.79694,20.289883,0,0,0,0,0,0),
(125490,8,511.54654,229.24347,20.301516,0,0,0,0,0,0),
(125490,9,518.6552,206.79694,20.289883,0,0,0,0,0,0),
(125490,10,520.88763,179.39882,20.278658,0,0,0,0,0,0),
(125490,11,514.15625,150.00967,20.235924,0,0,0,0,0,0),
(125490,12,507.257,127.883,20.271929,0,0,0,0,0,0),
(125490,13,497.40924,110.58228,20.289906,0,0,0,0,0,0),
(125490,14,486.81604,97.507996,20.289883,0,0,0,0,0,0);

-- Crystalcore Devastator 2, incomplete path
UPDATE `creature` SET `position_x` = 460.9808, `position_y` = 314.85217, `position_z` = 17.816647 WHERE `guid` IN (12566,12565,12564) AND `id` IN (20040,20042);
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (12564) AND `id` IN (20040);
DELETE FROM `creature_formations` WHERE `memberGUID` IN (12566,12565,12564);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(12564,12564,0,0,515,0,0),
(12564,12565,4,270,515,0,0),
(12564,12566,4,90,515,0,0);
DELETE FROM `creature_addon` WHERE `guid` IN (12564);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(12564,125640,0,0,1,0,3,"");
DELETE FROM `waypoint_data` WHERE `id` IN (125640);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(125640,1,460.9808,314.85217,17.816647,0,0,0,0,0,0),
(125640,2,480.81116,330.3677,17.701868,0,0,0,0,0,0),
(125640,3,488.87756,342.66516,17.682777,0,0,0,0,0,0),
(125640,4,480.81116,330.3677,17.701868,0,0,0,0,0,0),
(125640,5,460.9808,314.85217,17.816647,0,0,0,0,0,0);

-- Al'ar, spline actually
UPDATE `creature` SET `position_x` = 370.3282, `position_y` = -32.59526, `position_z` = 44.086323 WHERE `guid` = 12479 AND `id` = 19514;
DELETE FROM `waypoint_data` WHERE `id` IN (124790);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(124790,1,370.3282,-32.59526,44.086323,0,0,1,0,0,0),
(124790,2,383.00952,-0.892289,43.999462,0,0,1,0,0,0),
(124790,3,370.54208,31.286678,43.80863,0,0,1,0,0,0),
(124790,4,332.54654,45.770878,43.6697,0,0,1,0,0,0),
(124790,5,294.31482,30.929195,43.8919,0,0,1,0,0,0),
(124790,6,282.06378,-0.653615,43.91968,0,0,1,0,0,0),
(124790,7,294.21323,-32.41557,43.61413,0,0,1,0,0,0),
(124790,8,332.34235,-47.540607,43.697468,0,0,1,0,0,0);



-- Fix & update addon data
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (18805,19514,19516,19622,20031,20032,20033,20034,20035,20036,20037,20038,20039,20040,20041,20042,20043,20044,20045,20046,20047,20048,20049,20050,20052,20060,20062,20063,20064,20602,19551,21274,21270,21272,21269,21273,21271,21268,19577,18925,18806,18928,18932,22290,21369,21362,21002,21364);
UPDATE `creature_addon` SET `bytes2` = 1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 19514);

UPDATE `creature_template_addon` SET `auras` = "8876" WHERE `entry` = 20060;
UPDATE `creature_addon` SET `auras` = "19818" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 20039);
UPDATE `creature_template_addon` SET `auras` = "19818" WHERE `entry` = 20039;
UPDATE `creature_addon` SET `auras` = "18943" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 20040);
UPDATE `creature_template_addon` SET `auras` = "18943" WHERE `entry` = 20040;
UPDATE `creature_template_addon` SET `auras` = "37016" WHERE `entry` = 21273;

-- No sniff for 18806,18925,18928,18932,19577
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=19622; -- Kael'thas Sunstrider
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20063; -- Master Engineer Telonicus
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20064; -- Thaladred the Darkener
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20062; -- Grand Astromancer Capernian
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000 WHERE `entry`=20060; -- Lord Sanguinar
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20045; -- Nether Scryer
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=2.142857074737548828, `unit_flags`=32832 WHERE `entry`=18805; -- High Astromancer Solarian
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=20044; -- Novice Astromancer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=20043; -- Apprentice Star Scryer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20046; -- Astromancer Lord
UPDATE `creature_template` SET `speed_walk`=3.20000004768371582, `speed_run`=2.857142925262451171, `unit_flags`=32832 WHERE `entry`=19516; -- Void Reaver
UPDATE `creature_template` SET `speed_walk`=0.944444000720977783, `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20052; -- Crystalcore Mechanic
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20042; -- Tempest-Smith
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20047; -- Crimson Hand Battle Mage
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20049; -- Crimson Hand Blood Knight
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20050; -- Crimson Hand Inquisitor
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20048; -- Crimson Hand Centurion
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20040; -- Crystalcore Devastator
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `unit_flags`=32832 WHERE `entry`=20041; -- Crystalcore Sentinel
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32768 WHERE `entry`=20038; -- Phoenix-Hawk Hatchling
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20037; -- Tempest Falconer
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=2.142857074737548828, `unit_flags`=32832 WHERE `entry`=19514; -- Al'ar
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20039; -- Phoenix-Hawk
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20034; -- Star Scryer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=1600, `unit_flags`=32832 WHERE `entry`=20035; -- Bloodwarder Marshal
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=20033; -- Astromancer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=20036; -- Bloodwarder Squire
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `unit_flags`=32832 WHERE `entry`=20032; -- Bloodwarder Vindicator
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=1600, `unit_flags`=32832 WHERE `entry`=20031; -- Bloodwarder Legionnaire
UPDATE `creature_template` SET `speed_run`=2.14285714286, `unit_flags`=32768 WHERE `entry`=19551; -- Ember of Al'ar
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20602; -- Flame Patch (Al'ar)
UPDATE `creature_template` SET `speed_run`=0.42857142857, `unit_flags`=33554432 WHERE `entry`=21002; -- Nether Vapor
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768 WHERE `entry`=21268; -- Netherstrand Longbow
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768, `BaseAttackTime`=3000 WHERE `entry`=21269; -- Devastation
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585 WHERE `entry`=21270; -- Cosmic Infuser
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768 WHERE `entry`=21271; -- Infinity Blades
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768 WHERE `entry`=21272; -- Warp Slicer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768, `BaseAttackTime`=3000 WHERE `entry`=21273; -- Phaseshift Bulwark
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `unit_flags`=32768 WHERE `entry`=21274; -- Staff of Disintegration
UPDATE `creature_template` SET `speed_run`=0.85714285714, `unit_flags`=32768, `BaseAttackTime`=2000, `unit_flags2`=0 WHERE `entry`=21362; -- Phoenix
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=21364; -- Phoenix Egg

UPDATE `creature_model_info` SET `BoundingRadius` = 1.5, `CombatReach` = 3 WHERE `DisplayID` IN (26083,26081,26080,26082,26086,26084,26085);
UPDATE `creature_model_info` SET `BoundingRadius` = 0.3, `CombatReach` = 1 WHERE `DisplayID` = 19988;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.525, `CombatReach` = 4.5 WHERE `DisplayID` = 17765;
UPDATE `creature_model_info` SET `BoundingRadius` = 8, `CombatReach` = 10.4 WHERE `DisplayID` = 18988;
UPDATE `creature_model_info` SET `BoundingRadius`=1.148999929428100585, `CombatReach`=4.5 WHERE `DisplayID`=20177;
UPDATE `creature_model_info` SET `BoundingRadius`=1.148999929428100585, `CombatReach`=4.5 WHERE `DisplayID`=20236;
UPDATE `creature_model_info` SET `BoundingRadius`=1.148999929428100585, `CombatReach`=4.5 WHERE `DisplayID`=20237;
UPDATE `creature_model_info` SET `BoundingRadius`=1.148999929428100585, `CombatReach`=4.5 WHERE `DisplayID`=20178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.5 WHERE `DisplayID`=19254;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19507;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19508;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19503;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19504;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19505;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19506;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19500;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19423;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19475;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19472;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19470;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19412;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19413;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25, `CombatReach`=7.5 WHERE `DisplayID`=19300;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=9 WHERE `DisplayID`=19410;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=3.75 WHERE `DisplayID`=19299;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1.5 WHERE `DisplayID`=19298;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19398;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=19394;
UPDATE `creature_model_info` SET `BoundingRadius`=0.574499964714050292, `CombatReach`=2.25 WHERE `DisplayID`=21001;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3 WHERE `DisplayID`=19397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19392;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19393;
UPDATE `creature_model_info` SET `BoundingRadius`=0.612800002098083496, `CombatReach`=2.40000009536743164 WHERE `DisplayID`=19390;
UPDATE `creature_model_info` SET `BoundingRadius`=0.612800002098083496, `CombatReach`=2.40000009536743164 WHERE `DisplayID`=19391;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=19388;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689399957656860351, `CombatReach`=2.699999809265136718 WHERE `DisplayID`=21000;
UPDATE `creature_model_info` SET `BoundingRadius`=0.612800002098083496, `CombatReach`=2.40000009536743164 WHERE `DisplayID`=19386;
UPDATE `creature_model_info` SET `BoundingRadius`=0.612800002098083496, `CombatReach`=2.40000009536743164 WHERE `DisplayID`=19387;
UPDATE `creature_model_info` SET `BoundingRadius`=0.900000035762786865, `CombatReach`=9 WHERE `DisplayID`=20023;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=15 WHERE `DisplayID`=18951;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=15 WHERE `DisplayID`=18945;
UPDATE `creature_model_info` SET `BoundingRadius`=1.531999945640563964, `CombatReach`=6 WHERE `DisplayID`=18239;
