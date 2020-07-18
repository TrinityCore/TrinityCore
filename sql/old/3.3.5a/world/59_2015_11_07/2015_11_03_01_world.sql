SET @CGUID:=86954;

DELETE FROM `creature` WHERE `id` IN (30655, 30640, 30832, 30646, 30651, 30707, 30649, 30749, 30700, 30699, 30690, 31246, 31353, 30589, 30588, 30476, 30559);
DELETE FROM `creature` WHERE `guid` IN (122568, 122569, 122570);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+29;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 30640, 623, 1, 1, 35.03846, 36.06336, 25.11708, 5.288348, 120, 0, 0), -- 30640 (Area: 4508) (possible waypoints or random movement)
(@CGUID+1, 30640, 623, 1, 1, 6.909693, 9.529325, 20.54005, 2.303835, 120, 0, 0), -- 30640 (Area: 4508) (possible waypoints or random movement)
(@CGUID+2, 30640, 623, 1, 1, -27.16368, 2.981263, 20.54094, 0.122173, 120, 0, 0), -- 30640 (Area: 4508) (possible waypoints or random movement)
(@CGUID+3, 30640, 623, 1, 1, -56.31194, 12.39219, 31.00466, 3.281219, 120, 0, 0), -- 30640 (Area: 4537) (possible waypoints or random movement)
(@CGUID+4, 30646, 623, 1, 1, -30.25571, 31.80029, 12.35424, 1.605703, 120, 0, 0), -- 30646 (Area: 4508) (possible waypoints or random movement)
(@CGUID+5, 30646, 623, 1, 1, -5.325279, 31.62501, 12.34004, 1.500983, 120, 0, 0), -- 30646 (Area: 4508) (possible waypoints or random movement)
(@CGUID+6, 30651, 623, 1, 1, -40.68238, 29.21558, 12.33503, 1.919862, 120, 0, 0), -- 30651 (Area: 4508) (possible waypoints or random movement)
(@CGUID+7, 30651, 623, 1, 1, -17.81335, 32.07878, 12.3449, 1.553343, 120, 0, 0), -- 30651 (Area: 4508) (possible waypoints or random movement)
(@CGUID+8, 30651, 623, 1, 1, 5.88316, 30.50419, 12.34755, 1.32645, 120, 0, 0), -- 30651 (Area: 4508) (possible waypoints or random movement)
(@CGUID+9, 30655, 623, 1, 1, 6.662919, 19.23895, 10.05156, 0.5061455, 120, 0, 0), -- 30655 (Area: 4509)
(@CGUID+10, 30655, 623, 1, 1, -43.53964, 18.66365, 9.692578, 3.246312, 120, 0, 0), -- 30655 (Area: 4509) (possible waypoints or random movement)
(@CGUID+11, 30559, 623, 1, 1, 38.16154, -0.040522, 40.16801, 4.223697, 120, 0, 0), -- 30559 (Area: 4508) (possible waypoints or random movement)
(@CGUID+12, 30476, 623, 1, 1, 31.41805, 0.126893, 41.69821, 0.05235988, 120, 0, 0), -- 30476 (Area: 4508) (Auras: 56852 - 56852) (possible waypoints or random movement)
(@CGUID+13, 31353, 623, 1, 1, -21.7234, 19.33753, 9.687197, 1.64061, 120, 0, 0), -- 31353 (Area: 4509) (Auras: 57726 - 57726)
(@CGUID+14, 30690, 622, 1, 1, 15.24723, 32.37709, 10.63188, 1.553343, 120, 0, 0), -- 30690 (Area: 4533) (possible waypoints or random movement)
(@CGUID+15, 30690, 622, 1, 1, -11.22309, 32.91199, 10.55865, 1.58825, 120, 0, 0), -- 30690 (Area: 4533) (possible waypoints or random movement)
(@CGUID+16, 30649, 622, 1, 1, 4.109683, 19.52689, 34.74765, 3.752458, 120, 0, 0), -- 30649 (Area: 4533) (possible waypoints or random movement)
(@CGUID+17, 30649, 622, 1, 1, -32.53434, 24.30232, 33.9708, 3.211406, 120, 0, 0), -- 30649 (Area: 4533) (possible waypoints or random movement)
(@CGUID+18, 30649, 622, 1, 1, 50.99569, 46.95655, 23.41373, 2.583087, 120, 0, 0), -- 30649 (Area: 4533) (possible waypoints or random movement)
(@CGUID+19, 30649, 622, 1, 1, 2.006737, 15.73845, 9.250069, 3.368485, 120, 0, 0), -- 30649 (Area: 4533) (possible waypoints or random movement)
(@CGUID+20, 30699, 622, 1, 1, 1.853844, 32.8888, 10.02361, 1.58825, 120, 0, 0), -- 30699 (Area: 4533) (possible waypoints or random movement)
(@CGUID+21, 30700, 622, 1, 1, -35.66628, 29.43331, 1.87925, 1.745329, 120, 0, 0), -- 30700 (Area: 0) (possible waypoints or random movement)
(@CGUID+22, 30700, 622, 1, 1, 7.417077, 32.82674, 38.35604, 1.553343, 120, 0, 0), -- 30700 (Area: 0) (possible waypoints or random movement)
(@CGUID+23, 30700, 622, 1, 1, -55.9708, 28.44186, 18.02501, 2.268928, 120, 0, 0), -- 30700 (Area: 0) (possible waypoints or random movement)
(@CGUID+24, 30700, 622, 1, 1, 38.76255, 30.09343, 2.308181, 1.134464, 120, 0, 0), -- 30700 (Area: 4533) (possible waypoints or random movement)
(@CGUID+25, 30707, 622, 1, 1, 19.47087, 27.5296, 10.64527, 1.396263, 120, 0, 0), -- 30707 (Area: 4533) (possible waypoints or random movement)
(@CGUID+26, 30707, 622, 1, 1, -15.3085, 30.59285, 11.11614, 2.635447, 120, 0, 0), -- 30707 (Area: 0) (possible waypoints or random movement)
(@CGUID+27, 31353, 622, 1, 1, -7.999845, 17.85185, 35.04856, 2.460914, 120, 0, 0), -- 31353 (Area: 0) (possible waypoints or random movement)
(@CGUID+28, 30588, 622, 1, 1, -18.10283, -0.042108, 45.31725, 1.762783, 120, 0, 0), -- 30588 (Area: 4533) (Auras: 57424 - 57424) (possible waypoints or random movement)
(@CGUID+29, 30589, 622, 1, 1, -11.83204, -0.019289, 43.11467, 4.153883, 120, 0, 0); -- 30589 (Area: 4533) (possible waypoints or random movement)

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (30690, 30699);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (30700, 30646,30651,31353);

DELETE FROM `creature_addon` WHERE `guid` IN (122568, 122569, 122758, 122777, 124002, 124113);
