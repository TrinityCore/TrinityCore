-- Halls of Origination work
SET @CGUID := 377475; -- 91 entries needed (1000000 - 1000090)

-- Spawns --
-- spawn missing Temple Fireshaper (not in old sniffs)
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 48143, 644, 0, 0, 3, 0, 0, 0, 0, -640.624, 396.364, 83.8651, 1.54741, 7200, 0, 0, 1, 0, 0, 0, 0, 0, '', -1);

-- completely respawn troggs
DELETE FROM `creature` WHERE `map` = 644 AND `id` IN (40252, 40251, 39804);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+90;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+1, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -310.194, 470.802, 89.2101, 0.942478, 75, 0, 0, 1, 0, 2, 0, 0,  0, '', 0),
(@CGUID+2, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -306.049, 473.334, 89.2098, 3.32781,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+3, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -310.229, 475.618, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+4, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -314.069, 475.719, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+5, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -313.979, 472.288, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+6, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -314.16,  467.67,  89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+7, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -308.781, 468.149, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+8, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -308.802, 464.792, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+9, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -304.965, 467.861, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+10, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -301.382, 471.996, 89.2101, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+11, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -340.839, 347.286, 75.9967, 0.964845, 75, 0, 0, 1, 0, 2, 0, 0,  0, '', 0),
(@CGUID+12, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -346.127, 354.856, 75.9967, 5.85007,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+13, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -346.036, 351.425, 75.9967, 5.60471,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+14, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -346.217, 346.807, 75.9967, 0.486205, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+15, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -342.286, 354.755, 75.9967, 5.86649,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+16, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -342.252, 349.939, 75.9967, 0.300333, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+17, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -339.944, 351.752, 75.9395, 0.246043, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+18, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -338.092, 352.474, 75.9967, 6.11989,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+19, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -337.023, 346.998, 75.9967, 3.12421,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+20, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -340.859, 343.929, 75.9967, 0.0577634, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+21, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -327.108, 363.51,  75.9967, 0.191986, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+22, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -326.706, 371.395, 75.9149, 0.115208, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+23, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -323.705, 370.922, 75.9147, 5.43921,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+24, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -327.919, 369.543, 75.915,  6.1753,   75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+25, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -329.505, 368.512, 75.9967, 1.20988,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+26, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -322.414, 366.157, 75.9135, 2.20408,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+27, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -327.079, 366.141, 75.9135, 0.471097, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+28, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -329.941, 364.475, 75.9136, 2.99184,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+29, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -328.955, 360.703, 75.9967, 0.191986, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+30, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -324.66,  361.185, 75.9139, 6.02108,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+31, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -287.823, 385.519, 75.9193, 2.92434,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+32, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -299.3,   358.482, 75.8604, 3.52962,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+33, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -292.242, 380.517, 75.801,  3.16325,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+34, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -225.253, 369.491, 75.9968, 3.42004,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+35, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -223.826, 358.665, 75.9968, 2.10959,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+36, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -302.997, 356.95,  75.8869, 3.51183,  75, 0, 0, 1, 0, 2, 0, 0,  0, '', 0),
(@CGUID+37, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -268.631, 350.643, 75.8555, 5.96633,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+38, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -265.242, 356.885, 75.8571, 2.1115,   75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+39, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -235.209, 401.48,  78.039,  1.21846,  75, 0, 0, 1, 0, 2, 0, 0,  0, '', 0),
(@CGUID+40, 40251, 644, 0, 0, 3, 0, 0, 0, 0, -232.226, 336.948, 76.1978, 2.17494,  75, 0, 0, 1, 0, 2, 0, 0,  0, '', 0),
(@CGUID+41, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -229.985, 345.492, 75.9832, 3.14345,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+42, 40252, 644, 0, 0, 3, 0, 0, 0, 0, -227.76,  404.618, 78.4398, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+43, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -306.997, 356.864, 75.908,  3.51118,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+44, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -306.122, 359.457, 75.9034, 3.51491,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+45, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -306.001, 354.316, 75.9027, 3.51128,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+46, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -303.786, 360.88,  75.8911, 3.52073,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+47, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -303.601, 353.004, 75.8867, 3.51511,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+48, 39804, 644, 0, 0, 2, 0, 0, 0, 0, -301.767, 360.221, 75.88,   3.88732,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+49, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -300.917, 353.542, 75.8629, 3.52084,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+50, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -299.208, 355.679, 75.8515, 3.52591,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+51, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -295.094, 380.578, 75.823,  3.21846,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+52, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -292.451, 385.642, 75.9222, 1.82215,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+53, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -290.55,  383.07,  75.7897, 5.77275,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+54, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -290.126, 377.787, 75.783,  0.57182,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+55, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -288.722, 374.086, 75.8119, 2.14096,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+56, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -287.697, 378.254, 75.7646, 2.15255,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+57, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -284.984, 385.712, 75.7487, 0.553711, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+58, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -284.745, 380.914, 75.7436, 0.298799, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+59, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -269.067, 357.017, 75.8528, 5.32259,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+60, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -266.62,  352.449, 75.8571, 2.56367,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+61, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -266.006, 359.436, 75.8554, 4.82735,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+62, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -264.552, 360.05,  75.8568, 3.74199,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+63, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -262.46,  348.775, 75.8631, 5.90125,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+64, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -261.533, 354.988, 75.862,  3.6823,   75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+65, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -260.413, 357.929, 75.9242, 1.73724,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+66, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -260.307, 350.639, 75.8649, 5.97425,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+67, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -237.583, 339.826, 75.9239, 0.555555, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+68, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -237.493, 347.875, 75.9968, 6.11079,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+69, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -237.403, 344.444, 75.9941, 0.603315, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+70, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -233.653, 347.774, 75.9968, 4.36988,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+71, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -233.618, 342.958, 75.9755, 3.0492,   75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+72, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -232.327, 401.063, 77.917,  1.51474,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+73, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -232.205, 340.306, 75.9557, 1.25035,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+74, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -231.429, 395.645, 76.3648, 2.90686,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+75, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -231.346, 405.052, 79.0613, 1.62124,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+76, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -229.184, 361.543, 75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+77, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -229.094, 369.592, 75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+78, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -229.003, 366.161, 75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+79, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -228.389, 340.017, 75.9719, 2.85645,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+80, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -227.851, 396.569, 76.7132, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+81, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -227.67,  401.188, 77.3578, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+82, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -225.219, 364.675, 75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+83, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -224.806, 344.153, 75.9968, 2.59741,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+84, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -223.92,  404.517, 78.4297, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+85, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -223.885, 399.701, 77.6513, 0.942478, 75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+86, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -222.754, 363.174, 75.9125, 2.12401,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+87, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -221.988, 402.397, 78.3069, 5.59566,  75, 0, 0, 1, 0, 0, 0, 0,  0, '', 0),
(@CGUID+88, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -221.059, 367.21,  75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+89, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -219.99,  361.734, 75.9968, 0.942478, 75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0),
(@CGUID+90, 39804, 644, 0, 0, 3, 0, 0, 0, 0, -216.406, 365.87,  75.9968, 5.54348,  75, 3, 0, 1, 0, 1, 0, 0,  0, '', 0);

-- Creature Formations --
-- First group, on the beginning
DELETE FROM `creature_formations` WHERE `memberGUID` IN (322519, 322579, 322520, 322578);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(322519,322519,0,0,3,0,0),
(322519,322579,0,0,3,0,0),
(322519,322520,0,0,3,0,0),
(322519,322578,0,0,3,0,0);

-- Second right-side group
DELETE FROM `creature_formations` WHERE `memberGUID` IN (322466, 322211, 322053, 322465);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(322466,322466,0,0,3,0,0),
(322466,322211,13,330,515,5,10),
(322466,322053,13,30,515,5,10),
(322466,322465,7,0,515,5,10);

-- Second left-side group
DELETE FROM `creature_formations` WHERE `memberGUID` IN (322210, 321936, 321868, 321867);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(322210,322210,0,0,3,0,0),
(322210,321936,13,330,515,5,10),
(322210,321868,13,30,515,5,10),
(322210,321867,7,0,515,5,10);

-- Third group
DELETE FROM `creature_formations` WHERE `memberGUID` IN (@CGUID+0, 320942, 321479);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,3,0,0),
(@CGUID+0,320942,0,0,3,0,0),
(@CGUID+0,321479,0,0,3,0,0);

-- Group before elevator
DELETE FROM `creature_formations` WHERE `memberGUID` IN (317604, 317603, 317601, 317570);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(317604,317604,0,0,3,0,0),
(317604,317603,9,320,515,0,0),
(317604,317601,9,40,515,0,0),
(317604,317570,11,270,515,0,0);

-- Group west from elevator
DELETE FROM `creature_formations` WHERE `memberGUID` IN (317458, 320150, 317381, 317382);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(317458,317458,0,0,3,0,0),
(317458,320150,8,330,515,2,5),
(317458,317381,8,30,515,2,5),
(317458,317382,8,90,515,2,5);

-- First group east from elevator
DELETE FROM `creature_formations` WHERE `memberGUID` IN (307307, 307310, 307320, 307308);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(307307,307307,0,0,3,0,0),
(307307,307310,0,0,3,0,0),
(307307,307320,0,0,3,0,0),
(307307,307308,0,0,3,0,0);

-- Second group east from elevator
DELETE FROM `creature_formations` WHERE `memberGUID` IN (307365, 307452, 307418, 307453, 307333, 307360);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(307365,307365,0,0,3,0,0),
(307365,307452,0,0,3,0,0),
(307365,307418,0,0,3,0,0),
(307365,307453,0,0,3,0,0),
(307365,307333,0,0,3,0,0),
(307365,307360,0,0,3,0,0);

-- Third group east from elevator
DELETE FROM `creature_formations` WHERE `memberGUID` IN (308039, 307679, 307678, 307680, 307454);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(308039,308039,0,0,3,0,0),
(308039,307679,0,0,3,0,0),
(308039,307678,0,0,3,0,0),
(308039,307680,0,0,3,0,0),
(308039,307454,0,0,3,0,0);

-- Vault of Light troggs
DELETE FROM `creature_formations` WHERE `memberGUID` BETWEEN @CGUID+1 AND @CGUID+90; -- safe! troggs only in this range
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
-- First left-side group
(@CGUID+1,@CGUID+1,0,0,3,0,0),
(@CGUID+1,@CGUID+2,4,180,515,0,0),
(@CGUID+1,@CGUID+3,4,220,515,0,0),
(@CGUID+1,@CGUID+4,4,260,515,0,0),
(@CGUID+1,@CGUID+5,4,300,515,0,0),
(@CGUID+1,@CGUID+6,4,340,515,0,0),
(@CGUID+1,@CGUID+7,4,20,515,0,0),
(@CGUID+1,@CGUID+8,4,60,515,0,0),
(@CGUID+1,@CGUID+9,4,100,515,0,0),
(@CGUID+1,@CGUID+10,4,140,515,0,0),
-- First right-side group
(@CGUID+11,@CGUID+11,0,0,3,0,0),
(@CGUID+11,@CGUID+12,4,180,515,0,0),
(@CGUID+11,@CGUID+13,4,220,515,0,0),
(@CGUID+11,@CGUID+14,4,260,515,0,0),
(@CGUID+11,@CGUID+15,4,300,515,0,0),
(@CGUID+11,@CGUID+16,4,340,515,0,0),
(@CGUID+11,@CGUID+17,4,20,515,0,0),
(@CGUID+11,@CGUID+18,4,60,515,0,0),
(@CGUID+11,@CGUID+19,4,100,515,0,0),
(@CGUID+11,@CGUID+20,4,140,515,0,0),
-- First middle group
(@CGUID+21,@CGUID+21,0,0,3,0,0),
(@CGUID+21,@CGUID+22,0,0,3,0,0),
(@CGUID+21,@CGUID+23,0,0,3,0,0),
(@CGUID+21,@CGUID+24,0,0,3,0,0),
(@CGUID+21,@CGUID+25,0,0,3,0,0),
(@CGUID+21,@CGUID+26,0,0,3,0,0),
(@CGUID+21,@CGUID+27,0,0,3,0,0),
(@CGUID+21,@CGUID+28,0,0,3,0,0),
(@CGUID+21,@CGUID+29,0,0,3,0,0),
(@CGUID+21,@CGUID+30,0,0,3,0,0),
-- Second middle group
(@CGUID+31,@CGUID+31,0,0,3,0,0),
(@CGUID+31,@CGUID+33,0,0,3,0,0),
(@CGUID+31,@CGUID+51,0,0,3,0,0),
(@CGUID+31,@CGUID+52,0,0,3,0,0),
(@CGUID+31,@CGUID+53,0,0,3,0,0),
(@CGUID+31,@CGUID+54,0,0,3,0,0),
(@CGUID+31,@CGUID+55,0,0,3,0,0),
(@CGUID+31,@CGUID+56,0,0,3,0,0),
(@CGUID+31,@CGUID+57,0,0,3,0,0),
(@CGUID+31,@CGUID+58,0,0,3,0,0),
-- Third middle group
(@CGUID+37,@CGUID+37,0,0,3,0,0),
(@CGUID+37,@CGUID+38,0,0,3,0,0),
(@CGUID+37,@CGUID+59,0,0,3,0,0),
(@CGUID+37,@CGUID+60,0,0,3,0,0),
(@CGUID+37,@CGUID+61,0,0,3,0,0),
(@CGUID+37,@CGUID+62,0,0,3,0,0),
(@CGUID+37,@CGUID+63,0,0,3,0,0),
(@CGUID+37,@CGUID+64,0,0,3,0,0),
(@CGUID+37,@CGUID+65,0,0,3,0,0),
(@CGUID+37,@CGUID+66,0,0,3,0,0),
-- Forth middle group
(@CGUID+34,@CGUID+34,0,0,3,0,0),
(@CGUID+34,@CGUID+35,0,0,3,0,0),
(@CGUID+34,@CGUID+76,0,0,3,0,0),
(@CGUID+34,@CGUID+77,0,0,3,0,0),
(@CGUID+34,@CGUID+78,0,0,3,0,0),
(@CGUID+34,@CGUID+82,0,0,3,0,0),
(@CGUID+34,@CGUID+86,0,0,3,0,0),
(@CGUID+34,@CGUID+88,0,0,3,0,0),
(@CGUID+34,@CGUID+89,0,0,3,0,0),
(@CGUID+34,@CGUID+90,0,0,3,0,0),
-- Second left-side group
(@CGUID+39,@CGUID+39,0,0,3,0,0),
(@CGUID+39,@CGUID+42,4,180,515,0,0),
(@CGUID+39,@CGUID+72,4,220,515,0,0),
(@CGUID+39,@CGUID+74,4,260,515,0,0),
(@CGUID+39,@CGUID+75,4,300,515,0,0),
(@CGUID+39,@CGUID+80,4,340,515,0,0),
(@CGUID+39,@CGUID+81,4,20,515,0,0),
(@CGUID+39,@CGUID+84,4,60,515,0,0),
(@CGUID+39,@CGUID+85,4,100,515,0,0),
(@CGUID+39,@CGUID+87,4,140,515,0,0),
-- Second right-side group
(@CGUID+40,@CGUID+40,0,0,3,0,0),
(@CGUID+40,@CGUID+41,4,180,515,0,0),
(@CGUID+40,@CGUID+67,4,220,515,0,0),
(@CGUID+40,@CGUID+68,4,260,515,0,0),
(@CGUID+40,@CGUID+69,4,300,515,0,0),
(@CGUID+40,@CGUID+70,4,340,515,0,0),
(@CGUID+40,@CGUID+71,4,20,515,0,0),
(@CGUID+40,@CGUID+73,4,60,515,0,0),
(@CGUID+40,@CGUID+79,4,100,515,0,0),
(@CGUID+40,@CGUID+83,4,140,515,0,0),
-- Moving middle group
(@CGUID+36,@CGUID+36,0,0,3,0,0),
(@CGUID+36,@CGUID+32,4,180,515,0,0),
(@CGUID+36,@CGUID+50,4,220,515,0,0),
(@CGUID+36,@CGUID+49,4,260,515,0,0),
(@CGUID+36,@CGUID+47,4,300,515,0,0),
(@CGUID+36,@CGUID+45,4,340,515,0,0),
(@CGUID+36,@CGUID+43,4,20,515,0,0),
(@CGUID+36,@CGUID+44,4,60,515,0,0),
(@CGUID+36,@CGUID+46,4,100,515,0,0),
(@CGUID+36,@CGUID+48,4,140,515,0,0);

-- Isiset trash right-side formation
DELETE FROM `creature_formations` WHERE `memberGUID` IN (313971, 317535, 313950, 313951, 313952);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(313971,313971,0,0,3,0,0),
(313971,317535,0,0,3,0,0),
(313971,313950,0,0,3,0,0),
(313971,313951,0,0,3,0,0),
(313971,313952,0,0,3,0,0);

-- Isiset trash left-side formation
DELETE FROM `creature_formations` WHERE `memberGUID` IN (313972, 320781, 313954, 313949, 313953);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(313972,313972,0,0,3,0,0),
(313972,320781,0,0,3,0,0),
(313972,313954,0,0,3,0,0),
(313972,313949,0,0,3,0,0),
(313972,313953,0,0,3,0,0);

-- Ammunae trash
DELETE FROM `creature_formations` WHERE `memberGUID` IN (317605, 313947);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(317605,317605,0,0,3,0,0),
(317605,313947,0,0,3,0,0);

DELETE FROM `creature_formations` WHERE `memberGUID` IN (317606, 313948);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(317606,317606,0,0,3,0,0),
(317606,313948,0,0,3,0,0);

-- Setesh trash
-- Void Worms left-side formation
DELETE FROM `creature_formations` WHERE `memberGUID` IN (313958, 313959);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(313958,313958,0,0,3,5,10),
(313958,313959,2,270,515,5,10);

-- Void Worms right-side formation
DELETE FROM `creature_formations` WHERE `memberGUID` IN (313961, 313960);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(313961,313961,0,0,3,4,8),
(313961,313960,2,270,515,4,8);

-- Void Lord and 2x Void Seeker formation
DELETE FROM `creature_formations` WHERE `memberGUID` IN (313962, 313967, 313968);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(313962,313962,0,0,3,0,0),
(313962,313967,0,0,3,0,0),
(313962,313968,0,0,3,0,0);

-- Rajh trash
DELETE FROM `creature_formations` WHERE `memberGUID` IN (314159, 314158, 313086);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(314159,314159,0,0,3,0,0),
(314159,314158,0,0,3,0,0),
(314159,313086,0,0,3,0,0);

-- Random Movement --
-- Pit Viper snakes, Camels, most of Isiset trash, both Lifewarden Nymphs
UPDATE `creature` SET `MovementType` = 1, `spawndist` = 5 WHERE `map` = 644 AND `id` = 39444;
UPDATE `creature` SET `MovementType` = 1, `spawndist` = 5 WHERE `map` = 644 AND `id` = 39443;
UPDATE `creature` SET `MovementType` = 1, `spawndist` = 5 WHERE `guid` IN (317535, 313950, 313951, 313952, 320781, 320754, 313949, 313953);
UPDATE `creature` SET `MovementType` = 1, `spawndist` = 5 WHERE `guid` IN (313947, 313948);

-- Waypoints --
-- trash paths
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (322466);
DELETE FROM `creature_addon` WHERE `guid` IN (322466);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(322466, 3224660, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3224660);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3224660,  1, -749.123,  472.962,  67.20775, 0, 0, 0, 0, 100, 0),
(3224660,  2, -748.2323, 464.9793, 67.19108, 0, 0, 0, 0, 100, 0),
(3224660,  3, -734.168,  459.564,  67.17745, 0, 0, 0, 0, 100, 0),
(3224660,  4, -717.325,  459.96,   67.18442, 0, 0, 0, 0, 100, 0),
(3224660,  5, -697.075,  460.267,  73.2090,  0, 0, 0, 0, 100, 0),
(3224660,  6, -678.781,  460.182,  79.06738, 0, 0, 0, 0, 100, 0), -- turns back
(3224660,  7, -697.075,  460.267,  73.2090,  0, 0, 0, 0, 100, 0),
(3224660,  8, -717.325,  459.96,   67.18442, 0, 0, 0, 0, 100, 0),
(3224660,  9, -734.168,  459.564,  67.17745, 0, 0, 0, 0, 100, 0),
(3224660, 10, -748.2323, 464.9793, 67.19108, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (322210);
DELETE FROM `creature_addon` WHERE `guid` IN (322210);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(322210, 3222100, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3222100);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3222100,  1, -749.771, 499.585, 67.21061, 0, 0, 0, 0, 100, 0),
(3222100,  2, -746.602, 515.061, 67.2137,  0, 0, 0, 0, 100, 0),
(3222100,  3, -722.425, 516.491, 67.18806, 0, 0, 0, 0, 100, 0),
(3222100,  4, -697.958, 516.549, 72.92428, 0, 0, 0, 0, 100, 0),
(3222100,  5, -678.974, 516.177, 78.99928, 0, 0, 0, 0, 100, 0),
(3222100,  6, -664.887, 515.224, 83.51125, 0, 0, 0, 0, 100, 0), -- turns back
(3222100,  7, -678.974, 516.177, 78.99928, 0, 0, 0, 0, 100, 0), 
(3222100,  8, -697.958, 516.549, 72.92428, 0, 0, 0, 0, 100, 0),
(3222100,  9, -722.425, 516.491, 67.18806, 0, 0, 0, 0, 100, 0),
(3222100, 10, -746.602, 515.061, 67.2137,  0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (317458);
DELETE FROM `creature_addon` WHERE `guid` IN (317458);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(317458, 3174580, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3174580);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3174580, 1, -507.01,   338.422,  95.64893, 0, 0, 0, 0, 100, 0),
(3174580, 2, -506.941,  330.323,  95.65701, 0, 0, 0, 0, 100, 0), 
(3174580, 3, -507.142,  319.997,  95.65394, 0, 0, 0, 0, 100, 0), -- turns back
(3174580, 4, -506.941,  330.323,  95.65701, 0, 0, 0, 0, 100, 0), 
(3174580, 5, -507.01,   338.422,  95.64893, 0, 0, 0, 0, 100, 0),
(3174580, 6, -507.0659, 347.3517, 95.64893, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (317604);
DELETE FROM `creature_addon` WHERE `guid` IN (317604);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(317604, 3176040, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3176040);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3176040,  1, -622.665,  193.2998, 81.75228, 0, 0, 0, 0, 100, 0),
(3176040,  2, -634.005,  193.528,  81.82398, 0, 0, 0, 0, 100, 0),
(3176040,  3, -640.3165, 193.7006, 81.9477,  0, 0, 0, 0, 100, 0),
(3176040,  4, -640.856,  204.708,  81.80561, 0, 0, 0, 0, 100, 0),
(3176040,  5, -640.726,  212.753,  81.82135, 0, 0, 0, 0, 100, 0),
(3176040,  6, -640.714,  224.997,  81.84181, 0, 0, 0, 0, 100, 0), -- turns back
(3176040,  7, -640.726,  212.753,  81.82135, 0, 0, 0, 0, 100, 0),
(3176040,  8, -640.856,  204.708,  81.80561, 0, 0, 0, 0, 100, 0),
(3176040,  9, -640.3165, 193.7006, 81.9477,  0, 0, 0, 0, 100, 0),
(3176040, 10, -634.005,  193.528,  81.82398, 0, 0, 0, 0, 100, 0);

SET @WP := @CGUID+1+"0";
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (@CGUID+1);
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1, @WP, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (@WP);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP,  1, -340.8974, 457.3196, 89.13029, 0, 0, 0, 0, 100, 0),
(@WP,  2, -338.6441, 441.092,  89.15115, 0, 0, 0, 0, 100, 0),
(@WP,  3, -336.803,  421.161,  83.844,   0, 0, 0, 0, 100, 0),
(@WP,  4, -336.425,  402.235,  78.255,   0, 0, 0, 0, 100, 0),
(@WP,  5, -340.507,  389.498,  75.913,   0, 0, 0, 0, 100, 0),
(@WP,  6, -327.793,  380.275,  75.914,   0, 0, 0, 0, 100, 0),
(@WP,  7, -320.367,  404.156,  78.804,   0, 0, 0, 0, 100, 0),
(@WP,  8, -320.326,  387.264,  75.914,   0, 0, 0, 0, 100, 0),
(@WP,  9, -322.123,  418.502,  83.045,   0, 0, 0, 0, 100, 0),
(@WP, 10, -320.925,  445.385,  89.147,   0, 0, 0, 0, 100, 0),
(@WP, 11, -314.721,  466.031,  89.134,   0, 0, 0, 0, 100, 0),
(@WP, 12, -344.675,  464.471,  89.125,   0, 0, 0, 0, 100, 0);

SET @WP := @CGUID+11+"0";
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (@CGUID+11);
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+11);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+11, @WP, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (@WP);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP,  1, -320.240, 348.689, 75.915, 0, 0, 0, 0, 100, 0),
(@WP,  2, -322.295, 328.576, 79.189, 0, 0, 0, 0, 100, 0),
(@WP,  3, -321.970, 303.343, 86.694, 0, 0, 0, 0, 100, 0),
(@WP,  4, -320.053, 276.121, 89.126, 0, 0, 0, 0, 100, 0),
(@WP,  5, -313.603, 268.022, 89.126, 0, 0, 0, 0, 100, 0),
(@WP,  6, -344.487, 266.569, 89.126, 0, 0, 0, 0, 100, 0),
(@WP,  7, -338.947, 281.011, 89.126, 0, 0, 0, 0, 100, 0),
(@WP,  8, -338.379, 295.442, 89.009, 0, 0, 0, 0, 100, 0),
(@WP,  9, -337.555, 312.697, 83.940, 0, 0, 0, 0, 100, 0),
(@WP, 10, -337.478, 336.837, 76.707, 0, 0, 0, 0, 100, 0),
(@WP, 11, -334.222, 347.829, 75.916, 0, 0, 0, 0, 100, 0);

SET @WP := @CGUID+39+"0";
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (@CGUID+39);
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+39);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+39, @WP, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (@WP);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP,  1, -229.809, 425.084, 85.0233, 0, 0, 0, 0, 100, 0),
(@WP,  2, -231.281, 454.782, 89.1416, 0, 0, 0, 0, 100, 0),
(@WP,  3, -238.517, 466.93,  89.1382, 0, 0, 0, 0, 100, 0),
(@WP,  4, -207.506, 467.781, 89.1251, 0, 0, 0, 0, 100, 0),
(@WP,  5, -214.589, 455.196, 89.1241, 0, 0, 0, 0, 100, 0),
(@WP,  6, -214.108, 428.046, 85.9165, 0, 0, 0, 0, 100, 0),
(@WP,  7, -213.996, 399.453, 77.4527, 0, 0, 0, 0, 100, 0),
(@WP,  8, -215.003, 383.376, 75.9213, 0, 0, 0, 0, 100, 0),
(@WP,  9, -230.138, 382.637, 75.9021, 0, 0, 0, 0, 100, 0),
(@WP, 10, -231.266, 407.546, 79.7728, 0, 0, 0, 0, 100, 0);

SET @WP := @CGUID+40+"0";
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (@CGUID+40);
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+40);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+40, @WP, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (@WP);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP,  1, -223.72,  350.826, 75.912,  0, 0, 0, 0, 100, 0),
(@WP,  2, -214.202, 339.769, 75.8889, 0, 0, 0, 0, 100, 0),
(@WP,  3, -214.631, 315.951, 82.9647, 0, 0, 0, 0, 100, 0),
(@WP,  4, -214.432, 279.69,  89.1245, 0, 0, 0, 0, 100, 0),
(@WP,  5, -207.678, 267.186, 89.1249, 0, 0, 0, 0, 100, 0),
(@WP,  6, -238.754, 265.643, 89.1254, 0, 0, 0, 0, 100, 0),
(@WP,  7, -231.774, 279.155, 89.1254, 0, 0, 0, 0, 100, 0),
(@WP,  8, -232.392, 305.642, 86.0238, 0, 0, 0, 0, 100, 0),
(@WP,  9, -233.215, 323.859, 80.5908, 0, 0, 0, 0, 100, 0),
(@WP, 10, -233.501, 343.237, 75.9087, 0, 0, 0, 0, 100, 0);

SET @WP := @CGUID+36+"0";
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (@CGUID+36);
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+36);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+36, @WP, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (@WP);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP,  1, -286.595, 362.899, 75.8408, 0, 0, 0, 0, 100, 0),
(@WP,  2, -264.119, 373.367, 75.7968, 0, 0, 0, 0, 100, 0),
(@WP,  3, -241.036, 378.026, 75.9096, 0, 0, 0, 0, 100, 0),
(@WP,  4, -222.212, 381.237, 75.9118, 0, 0, 0, 0, 100, 0),
(@WP,  5, -208.335, 375.96,  75.9188, 0, 0, 0, 0, 100, 0),
(@WP,  6, -205.636, 357.433, 75.9146, 0, 0, 0, 0, 100, 0),
(@WP,  7, -208.335, 375.96,  75.9188, 0, 0, 0, 0, 100, 0),
(@WP,  8, -222.212, 381.237, 75.9118, 0, 0, 0, 0, 100, 0),
(@WP,  9, -241.036, 378.026, 75.9096, 0, 0, 0, 0, 100, 0),
(@WP, 10, -264.119, 373.367, 75.7968, 0, 0, 0, 0, 100, 0),
(@WP, 11, -286.595, 362.899, 75.8408, 0, 0, 0, 0, 100, 0),
(@WP, 12, -302.983, 356.94,  75.8865, 0, 0, 0, 0, 100, 0),
(@WP, 13, -316.96,  351.339, 75.9109, 0, 0, 0, 0, 100, 0),
(@WP, 14, -336.149, 350.328, 75.9152, 0, 0, 0, 0, 100, 0),
(@WP, 15, -344.571, 366.36,  75.9152, 0, 0, 0, 0, 100, 0),
(@WP, 16, -336.149, 350.328, 75.9152, 0, 0, 0, 0, 100, 0),
(@WP, 17, -316.96,  351.339, 75.9109, 0, 0, 0, 0, 100, 0),
(@WP, 18, -302.983, 356.94,  75.8865, 0, 0, 0, 0, 100, 0);

-- Void Wyrm left-side path
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (313958);
DELETE FROM `creature_addon` WHERE `guid` IN (313958);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(313958, 3139580, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3139580);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3139580,  1,  -486.3099, -3.628408, 343.9285, 0, 0, 0, 0, 100, 0),
(3139580,  2,  -478.6337,  2.699653, 343.9205, 0, 0, 0, 0, 100, 0),
(3139580,  3,  -479.5243, 11.73611,  343.924,  0, 0, 0, 0, 100, 0),
(3139580,  4,  -483.2934, 21.49826,  343.9048, 0, 0, 0, 0, 100, 0),
(3139580,  5,  -491.0434, 28.45313,  343.942,  0, 0, 0, 0, 100, 0),
(3139580,  6,  -498.3116, 27.82349,  343.9431, 0, 0, 0, 0, 100, 0), -- turn back
(3139580,  7,  -491.0434, 28.45313,  343.942,  0, 0, 0, 0, 100, 0),
(3139580,  8,  -483.2934, 21.49826,  343.9048, 0, 0, 0, 0, 100, 0),
(3139580,  9,  -479.5243, 11.73611,  343.924,  0, 0, 0, 0, 100, 0),
(3139580, 10,  -478.6337,  2.699653, 343.9205, 0, 0, 0, 0, 100, 0);

-- Void Wyrm right-side path
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (313961);
DELETE FROM `creature_addon` WHERE `guid` IN (313961);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(313961, 3139610, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3139610);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3139610,  1, -519.3091,  8.16338, 343.9321, 0, 0, 0, 0, 100, 0),
(3139610,  2, -522.6979, 13.5,     343.923,  0, 0, 0, 0, 100, 0),
(3139610,  3, -521.3993, 20.92361, 343.9171, 0, 0, 0, 0, 100, 0),
(3139610,  4, -519.0362, 24.70054, 343.9201, 0, 0, 0, 0, 100, 0),
(3139610,  5, -512.7574, 26.00804, 343.9253, 0, 0, 0, 0, 100, 0), -- turn back
(3139610,  6, -519.0362, 24.70054, 343.9201, 0, 0, 0, 0, 100, 0),
(3139610,  7, -521.3993, 20.92361, 343.9171, 0, 0, 0, 0, 100, 0),
(3139610,  8, -522.6979, 13.5,     343.923,  0, 0, 0, 0, 100, 0);
