-- Subjugator Shiaziv and Subjugator Yalqiz
-- Shattered Hand Berserker (one one spawn, the other two should be waypoints of the frist spawn)
-- Dread Tactician (remove 2 bad paths (i added them wrong in the past))
-- Hellfire Abyssal Shelf - Rework for Mo'arg Overseer and Fel Cannon

UPDATE `creature` SET `position_x`=54.600360, `position_y`=1805.335, `position_z`=49.12101, `orientation`=1.304091, `MovementType`=2 WHERE `id`=19282; -- Subjugator Shiaziv
UPDATE `creature` SET `position_x`=-500.3803, `position_y`=1718.960, `position_z`=60.87181, `orientation`=3.734013, `MovementType`=2 WHERE `id`=19335; -- Subjugator Yalqiz

-- Subjugator Shiaziv
SET @POINT := 0;
SET @NPC := 68851;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 61.394100, 1830.152, 42.73946, 0),
(@PATH, @POINT := @POINT + 1, 56.415040, 1842.111, 42.80701, 0),
(@PATH, @POINT := @POINT + 1, 45.974290, 1851.916, 45.31885, 0),
(@PATH, @POINT := @POINT + 1, 24.965390, 1857.521, 54.07980, 0),
(@PATH, @POINT := @POINT + 1, 12.386280, 1857.223, 59.04086, 0),
(@PATH, @POINT := @POINT + 1, 2.0895180, 1853.448, 63.62301, 0),
(@PATH, @POINT := @POINT + 1, -10.91016, 1844.119, 69.45425, 0),
(@PATH, @POINT := @POINT + 1, -15.76009, 1833.515, 71.19009, 0),
(@PATH, @POINT := @POINT + 1, -13.49230, 1816.223, 66.91240, 0),
(@PATH, @POINT := @POINT + 1, -13.57107, 1802.379, 64.31023, 0),
(@PATH, @POINT := @POINT + 1, -13.02865, 1783.143, 61.35052, 0),
(@PATH, @POINT := @POINT + 1, -3.038954, 1762.001, 55.16345, 0),
(@PATH, @POINT := @POINT + 1, 9.0533860, 1752.676, 51.47461, 0),
(@PATH, @POINT := @POINT + 1, 21.688150, 1744.582, 48.89075, 0),
(@PATH, @POINT := @POINT + 1, 30.346680, 1750.987, 49.41211, 0),
(@PATH, @POINT := @POINT + 1, 42.703990, 1761.808, 49.77660, 0),
(@PATH, @POINT := @POINT + 1, 48.186630, 1777.874, 51.45816, 0),
(@PATH, @POINT := @POINT + 1, 55.352320, 1790.654, 51.11136, 0),
(@PATH, @POINT := @POINT + 1, 57.881180, 1800.581, 49.18709, 0),
(@PATH, @POINT := @POINT + 1, 59.407880, 1812.943, 46.47115, 0);


-- Subjugator Yalqiz
SET @NPC := 68916;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -516.5024, 1708.104, 57.89871, 0),
(@PATH, @POINT := @POINT + 1, -533.4302, 1692.131, 53.87750, 0),
(@PATH, @POINT := @POINT + 1, -532.1133, 1686.306, 51.65182, 0),
(@PATH, @POINT := @POINT + 1, -526.8643, 1677.809, 47.36276, 0),
(@PATH, @POINT := @POINT + 1, -510.7744, 1675.963, 47.51254, 0),
(@PATH, @POINT := @POINT + 1, -490.4778, 1679.859, 49.24321, 0),
(@PATH, @POINT := @POINT + 1, -482.0579, 1687.759, 51.38897, 0),
(@PATH, @POINT := @POINT + 1, -480.3202, 1701.180, 55.15236, 0),
(@PATH, @POINT := @POINT + 1, -489.2083, 1714.007, 58.48391, 0),
(@PATH, @POINT := @POINT + 1, -496.4688, 1719.324, 60.74733, 0),
(@PATH, @POINT := @POINT + 1, -505.4727, 1714.474, 59.55276, 0);

-- Dread Tactician (remove 2 bad paths (i added them wrong in the past))
UPDATE `creature` SET `position_x`=-296.4266, `position_y`=1568.856, `position_z`=41.835220, `orientation`=3.729646, `spawndist`=0, `MovementType`=2 WHERE `guid`=59170;
UPDATE `creature` SET `position_x`=-133.5336, `position_y`=1582.918, `position_z`=42.812290, `orientation`=6.205007, `spawndist`=0, `MovementType`=2 WHERE `guid`=59171;

-- Shattered Hand Berserker (one one spawn, the other two should be waypoints of the frist spawn)
DELETE FROM `creature` WHERE `guid` IN (58280, 58296);
UPDATE `creature` SET `position_x`=-432.5425, `position_y`=3016.569, `position_z`=-16.84295, `orientation`=5.780838, `spawndist`=0, `MovementType`=2 WHERE `guid`=58295;

-- Dread Tactician
SET @POINT := 0;
SET @NPC := 59170;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -334.0984, 1543.753, 45.24116, 0),
(@PATH, @POINT := @POINT + 1, -330.8320, 1499.882, 33.38686, 0),
(@PATH, @POINT := @POINT + 1, -305.9742, 1485.383, 29.53335, 0),
(@PATH, @POINT := @POINT + 1, -278.9718, 1485.058, 26.72857, 0),
(@PATH, @POINT := @POINT + 1, -267.6284, 1503.790, 27.89097, 0),
(@PATH, @POINT := @POINT + 1, -278.5529, 1506.749, 29.44310, 0),
(@PATH, @POINT := @POINT + 1, -296.3520, 1498.046, 30.37249, 0),
(@PATH, @POINT := @POINT + 1, -317.3887, 1501.720, 33.08825, 0),
(@PATH, @POINT := @POINT + 1, -325.3594, 1509.314, 35.02624, 0),
(@PATH, @POINT := @POINT + 1, -328.6507, 1539.184, 42.72945, 0),
(@PATH, @POINT := @POINT + 1, -307.0767, 1556.214, 41.62386, 0),
(@PATH, @POINT := @POINT + 1, -282.0919, 1553.386, 35.78281, 0),
(@PATH, @POINT := @POINT + 1, -268.9562, 1558.210, 34.82322, 0),
(@PATH, @POINT := @POINT + 1, -276.4884, 1575.941, 38.92973, 0),
(@PATH, @POINT := @POINT + 1, -295.1560, 1585.103, 45.23344, 0),
(@PATH, @POINT := @POINT + 1, -312.2053, 1568.992, 46.25256, 0);

-- Dread Tactician
SET @POINT := 0;
SET @NPC := 59171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -109.3626, 1581.022, 46.17117, 0),
(@PATH, @POINT := @POINT + 1, -84.37858, 1569.632, 46.29124, 0),
(@PATH, @POINT := @POINT + 1, -69.36133, 1540.273, 37.61205, 0),
(@PATH, @POINT := @POINT + 1, -72.20546, 1515.617, 32.32233, 0),
(@PATH, @POINT := @POINT + 1, -85.17464, 1487.418, 27.94559, 0),
(@PATH, @POINT := @POINT + 1, -102.4884, 1477.535, 27.37716, 0),
(@PATH, @POINT := @POINT + 1, -137.4821, 1476.977, 26.37018, 0),
(@PATH, @POINT := @POINT + 1, -153.9442, 1488.082, 27.13812, 0),
(@PATH, @POINT := @POINT + 1, -178.7490, 1510.963, 27.16745, 0),
(@PATH, @POINT := @POINT + 1, -185.4963, 1510.206, 26.95163, 0),
(@PATH, @POINT := @POINT + 1, -168.7500, 1488.021, 26.56499, 0),
(@PATH, @POINT := @POINT + 1, -147.7747, 1475.077, 25.78192, 0),
(@PATH, @POINT := @POINT + 1, -120.5284, 1482.918, 28.66402, 0),
(@PATH, @POINT := @POINT + 1, -94.96957, 1495.692, 30.73173, 0),
(@PATH, @POINT := @POINT + 1, -89.56852, 1516.276, 31.52229, 0),
(@PATH, @POINT := @POINT + 1, -88.22846, 1545.273, 39.60253, 0),
(@PATH, @POINT := @POINT + 1, -110.4561, 1566.677, 42.09719, 0),
(@PATH, @POINT := @POINT + 1, -134.7303, 1571.194, 40.62461, 0),
(@PATH, @POINT := @POINT + 1, -164.3697, 1573.173, 35.20005, 0),
(@PATH, @POINT := @POINT + 1, -164.0840, 1579.898, 36.36607, 0),
(@PATH, @POINT := @POINT + 1, -144.3336, 1584.482, 41.05930, 0);

-- Shattered Hand Berserker
SET @POINT := 0;
SET @NPC := 58295;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -406.9757, 3022.114, -16.14812, 0),
(@PATH, @POINT := @POINT + 1, -384.4923, 3027.486, -16.35291, 0),
(@PATH, @POINT := @POINT + 1, -369.7765, 3031.631, -16.32663, 0),
(@PATH, @POINT := @POINT + 1, -332.8234, 3039.824, -16.66688, 0),
(@PATH, @POINT := @POINT + 1, -323.3225, 3038.536, -16.45017, 0),
(@PATH, @POINT := @POINT + 1, -318.3123, 3033.358, -15.99788, 0),
(@PATH, @POINT := @POINT + 1, -289.7150, 3032.069, -8.329719, 0),
(@PATH, @POINT := @POINT + 1, -279.9789, 3038.296, -5.068746, 0),
(@PATH, @POINT := @POINT + 1, -282.3609, 3047.840, -4.396113, 0),
(@PATH, @POINT := @POINT + 1, -269.6367, 3050.605, -4.484854, 0),
(@PATH, @POINT := @POINT + 1, -242.5817, 3041.765, -4.301134, 0),
(@PATH, @POINT := @POINT + 1, -230.1253, 3038.011, -4.320513, 0),
(@PATH, @POINT := @POINT + 1, -242.5817, 3041.765, -4.301134, 0),
(@PATH, @POINT := @POINT + 1, -269.6367, 3050.605, -4.484854, 0),
(@PATH, @POINT := @POINT + 1, -282.3609, 3047.840, -4.396113, 0),
(@PATH, @POINT := @POINT + 1, -279.9789, 3038.296, -5.068746, 0),
(@PATH, @POINT := @POINT + 1, -289.7150, 3032.069, -8.329719, 0),
(@PATH, @POINT := @POINT + 1, -318.3123, 3033.358, -15.99788, 0),
(@PATH, @POINT := @POINT + 1, -323.3225, 3038.536, -16.45017, 0),
(@PATH, @POINT := @POINT + 1, -331.8813, 3040.104, -16.65558, 0),
(@PATH, @POINT := @POINT + 1, -369.7765, 3031.631, -16.32663, 0),
(@PATH, @POINT := @POINT + 1, -384.4923, 3027.486, -16.35291, 0),
(@PATH, @POINT := @POINT + 1, -406.3353, 3022.268, -16.14812, 0),
(@PATH, @POINT := @POINT + 1, -433.0263, 3016.659, -16.49373, 0);

-- Hellfire Abyssal Shelf
-- Fel Cannon 19 Updates
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69247;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69248;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `orientation`=3.882448, `MovementType`=0 WHERE `guid`=69249;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `orientation`=4.904270, `MovementType`=0 WHERE `guid`=69266;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `orientation`=3.971199, `MovementType`=0 WHERE `guid`=69254;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69251;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69250;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69255;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69257;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `position_x`=931.603027, `position_y`=1724.815308, `position_z`=102.419891, `orientation`=4.597957, `MovementType`=0 WHERE `guid`=69260;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `position_x`=970.444275, `position_y`=1703.526978, `position_z`=90.229973, `orientation`=4.643500, `MovementType`=0 WHERE `guid`=69263;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `position_x`=1022.650024, `position_y`=1727.25000, `position_z`=96.733101, `orientation`=5.517640, `MovementType`=0 WHERE `guid`=69265;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `position_x`=835.013977, `position_y`=1722.472534, `position_z`=108.600487, `orientation`=5.563979, `MovementType`=0 WHERE `guid`=69256;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `position_x`=716.960022, `position_y`=1710.010132, `position_z`=94.432152, `orientation`=1.856893, `MovementType`=0 WHERE `guid`=69252;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69262;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69261;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69264;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69267;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=35, `MovementType`=0 WHERE `guid`=69259;

-- Moarg Overseer
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=700.574402, `position_y`=1863.209961, `position_z`=146.867691, `orientation`=4.6, `MovementType`=2 WHERE `guid`=69146;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=912.013062, `position_y`=1684.601562, `position_z`=86.6479449, `orientation`=1.8, `MovementType`=2 WHERE `guid`=69147;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=647.887329, `position_y`=1755.359619, `position_z`=102.724243, `orientation`=1.8, `MovementType`=2 WHERE `guid`=69148;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=775.672791, `position_y`=1680.854004, `position_z`=96.071106, `orientation`=1.3, `MovementType`=2 WHERE `guid`=69149;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=775.672791, `position_y`=1680.854004, `position_z`=96.071106, `orientation`=1.3, `MovementType`=2 WHERE `guid`=69149;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=847.257013, `position_y`=1858.979980, `position_z`=141.001999, `orientation`=4.7, `MovementType`=2 WHERE `guid`=69150;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=1119.588745, `position_y`=1716.730225, `position_z`=84.372009, `orientation`=2.7, `MovementType`=2 WHERE `guid`=69151;
UPDATE `creature` SET  `spawndist`=0, `spawntimesecs`=45, `position_x`=985.438416, `position_y`=1847.512573, `position_z`=131.616867, `orientation`=4.6, `MovementType`=2 WHERE `guid`=69152;

-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69146;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 699.447693, 1851.012207, 139.298737, 0),
(@PATH, @POINT := @POINT + 1, 699.596069, 1834.927368, 132.742493, 0),
(@PATH, @POINT := @POINT + 1, 700.293579, 1827.491089, 128.716919, 0),
(@PATH, @POINT := @POINT + 1, 701.856445, 1820.550171, 130.101944, 0),
(@PATH, @POINT := @POINT + 1, 711.500488, 1805.117554, 128.486481, 0),
(@PATH, @POINT := @POINT + 1, 720.121399, 1791.661255, 124.981514, 0),
(@PATH, @POINT := @POINT + 1, 713.357971, 1782.760010, 120.797997, 0),
(@PATH, @POINT := @POINT + 1, 703.561890, 1762.689453, 111.730690, 0),
(@PATH, @POINT := @POINT + 1, 706.341858, 1753.165283, 108.395851, 0),
(@PATH, @POINT := @POINT + 1, 714.729126, 1749.719116, 102.424103, 0),
(@PATH, @POINT := @POINT + 1, 718.569580, 1746.259888, 103.555771, 0),
(@PATH, @POINT := @POINT + 1, 720.745728, 1743.383179, 105.289757, 0),
(@PATH, @POINT := @POINT + 1, 716.636047, 1734.510010, 101.078445, 0),
(@PATH, @POINT := @POINT + 1, 709.200623, 1728.714233, 89.643059,  0),
(@PATH, @POINT := @POINT + 1, 711.632690, 1721.802368, 91.388512,  0),
(@PATH, @POINT := @POINT + 1, 713.617004, 1717.716553, 94.599648,  0),
(@PATH, @POINT := @POINT + 1, 718.523376, 1705.399536, 92.815170,  0),
(@PATH, @POINT := @POINT + 1, 713.617004, 1717.716553, 94.599648,  0),
(@PATH, @POINT := @POINT + 1, 711.632690, 1721.802368, 91.388512,  0),
(@PATH, @POINT := @POINT + 1, 709.200623, 1728.714233, 89.643059,  0),
(@PATH, @POINT := @POINT + 1, 716.636047, 1734.510010, 101.078445, 0),
(@PATH, @POINT := @POINT + 1, 720.745728, 1743.383179, 105.289757, 0),
(@PATH, @POINT := @POINT + 1, 718.569580, 1746.259888, 103.555771, 0),
(@PATH, @POINT := @POINT + 1, 714.729126, 1749.719116, 102.424103, 0),
(@PATH, @POINT := @POINT + 1, 706.341858, 1753.165283, 108.395851, 0),
(@PATH, @POINT := @POINT + 1, 703.561890, 1762.689453, 111.730690, 0),
(@PATH, @POINT := @POINT + 1, 713.357971, 1782.760010, 120.797997, 0),
(@PATH, @POINT := @POINT + 1, 720.121399, 1791.661255, 124.981514, 0),
(@PATH, @POINT := @POINT + 1, 711.500488, 1805.117554, 128.486481, 0),
(@PATH, @POINT := @POINT + 1, 701.856445, 1820.550171, 130.101944, 0),
(@PATH, @POINT := @POINT + 1, 700.293579, 1827.491089, 128.716919, 0),
(@PATH, @POINT := @POINT + 1, 699.596069, 1834.927368, 132.742493, 0),
(@PATH, @POINT := @POINT + 1, 699.447693, 1851.012207, 139.298737, 0);


-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69147;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 906.696899, 1701.634644, 94.417450,  0),
(@PATH, @POINT := @POINT + 1, 914.734009, 1723.858643, 103.68199,  0),
(@PATH, @POINT := @POINT + 1, 923.744263, 1740.360352, 105.987480, 0),
(@PATH, @POINT := @POINT + 1, 919.721252, 1756.784302, 113.964417, 0),
(@PATH, @POINT := @POINT + 1, 912.116150, 1787.142578, 122.332787, 0),
(@PATH, @POINT := @POINT + 1, 916.540039, 1809.919067, 124.778526, 0),
(@PATH, @POINT := @POINT + 1, 917.115845, 1826.173462, 130.779053, 0),
(@PATH, @POINT := @POINT + 1, 922.766113, 1850.249512, 136.603439, 0),
(@PATH, @POINT := @POINT + 1, 915.619141, 1857.460938, 140.105988, 0),
(@PATH, @POINT := @POINT + 1, 922.766113, 1850.249512, 136.603439, 0),
(@PATH, @POINT := @POINT + 1, 917.115845, 1826.173462, 130.779053, 0),
(@PATH, @POINT := @POINT + 1, 916.540039, 1809.919067, 124.778526, 0),
(@PATH, @POINT := @POINT + 1, 912.116150, 1787.142578, 122.332787, 0),
(@PATH, @POINT := @POINT + 1, 919.721252, 1756.784302, 113.964417, 0),
(@PATH, @POINT := @POINT + 1, 923.744263, 1740.360352, 105.987480, 0),
(@PATH, @POINT := @POINT + 1, 914.734009, 1723.858643, 103.68199,  0),
(@PATH, @POINT := @POINT + 1, 906.696899, 1701.634644, 94.417450,  0),
(@PATH, @POINT := @POINT + 1, 847.257013, 1858.979980, 141.001999, 0);


-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69148;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 663.626404, 1767.271484, 108.425529,  0),
(@PATH, @POINT := @POINT + 1, 688.952271, 1749.683350, 105.147018,  0),
(@PATH, @POINT := @POINT + 1, 708.846130, 1755.718140, 109.675903,  0),
(@PATH, @POINT := @POINT + 1, 717.952637, 1755.217163, 105.999550,  0),
(@PATH, @POINT := @POINT + 1, 733.536926, 1752.255493, 110.545158,  0),
(@PATH, @POINT := @POINT + 1, 745.250366, 1751.058838, 110.216652,  0),
(@PATH, @POINT := @POINT + 1, 754.388062, 1752.052246, 109.739639,  0),
(@PATH, @POINT := @POINT + 1, 761.496155, 1753.9000024, 115.295876, 0),
(@PATH, @POINT := @POINT + 1, 785.477661, 1763.860596, 121.862541,  0),
(@PATH, @POINT := @POINT + 1, 816.670959, 1737.048340, 114.875328,  0),
(@PATH, @POINT := @POINT + 1, 832.429321, 1747.258667, 113.252502,  0),
(@PATH, @POINT := @POINT + 1, 845.364502, 1755.844482, 118.307350,  0),
(@PATH, @POINT := @POINT + 1, 866.321533, 1757.407837, 117.633759,  0),
(@PATH, @POINT := @POINT + 1, 914.577271, 1755.919189, 113.774620,  0),
(@PATH, @POINT := @POINT + 1, 959.877808, 1736.482056, 106.987320,  0),
(@PATH, @POINT := @POINT + 1, 974.641541, 1754.916870, 111.713875,  0),
(@PATH, @POINT := @POINT + 1, 986.710083, 1755.266724, 106.319138,  0),
(@PATH, @POINT := @POINT + 1, 992.729614, 1753.885376, 108.663559,  0),
(@PATH, @POINT := @POINT + 1, 1010.583435, 1751.816650, 104.732956, 0),
(@PATH, @POINT := @POINT + 1, 1040.523804, 1748.426514, 97.014572,  0),
(@PATH, @POINT := @POINT + 1, 1052.749878, 1748.949097, 99.107422,  0),
(@PATH, @POINT := @POINT + 1, 1072.766602, 1744.159912, 100.537209, 0),
(@PATH, @POINT := @POINT + 1, 1105.838013, 1741.597656, 98.447639,  0),
(@PATH, @POINT := @POINT + 1, 1122.749512, 1748.162476, 101.595871, 0),
(@PATH, @POINT := @POINT + 1, 1138.507690, 1751.462769, 95.233978,  0),
(@PATH, @POINT := @POINT + 1, 1122.749512, 1748.162476, 101.595871, 0),
(@PATH, @POINT := @POINT + 1, 1105.838013, 1741.597656, 98.447639,  0),
(@PATH, @POINT := @POINT + 1, 1072.766602, 1744.159912, 100.537209, 0),
(@PATH, @POINT := @POINT + 1, 1052.749878, 1748.949097, 99.107422,  0),
(@PATH, @POINT := @POINT + 1, 1040.523804, 1748.426514, 97.014572,  0),
(@PATH, @POINT := @POINT + 1, 1040.523804, 1748.426514, 97.014572,  0),
(@PATH, @POINT := @POINT + 1, 992.729614, 1753.885376, 108.663559,  0),
(@PATH, @POINT := @POINT + 1, 986.710083, 1755.266724, 106.319138,  0),
(@PATH, @POINT := @POINT + 1, 974.641541, 1754.916870, 111.713875,  0),
(@PATH, @POINT := @POINT + 1, 959.877808, 1736.482056, 106.987320,  0),
(@PATH, @POINT := @POINT + 1, 914.577271, 1755.919189, 113.774620,  0),
(@PATH, @POINT := @POINT + 1, 866.321533, 1757.407837, 117.633759,  0),
(@PATH, @POINT := @POINT + 1, 845.364502, 1755.844482, 118.307350,  0),
(@PATH, @POINT := @POINT + 1, 832.429321, 1747.258667, 113.252502,  0),
(@PATH, @POINT := @POINT + 1, 816.670959, 1737.048340, 114.875328,  0),
(@PATH, @POINT := @POINT + 1, 785.477661, 1763.860596, 121.862541,  0),
(@PATH, @POINT := @POINT + 1, 761.496155, 1753.9000024, 115.295876, 0),
(@PATH, @POINT := @POINT + 1, 754.388062, 1752.052246, 109.739639,  0),
(@PATH, @POINT := @POINT + 1, 745.250366, 1751.058838, 110.216652,  0),
(@PATH, @POINT := @POINT + 1, 733.536926, 1752.255493, 110.545158,  0),
(@PATH, @POINT := @POINT + 1, 717.952637, 1755.217163, 105.999550,  0),
(@PATH, @POINT := @POINT + 1, 708.846130, 1755.718140, 109.675903,  0),
(@PATH, @POINT := @POINT + 1, 688.952271, 1749.683350, 105.147018,  0);

-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69149;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 783.789062, 1692.381714, 99.448456,  0),
(@PATH, @POINT := @POINT + 1, 784.510010, 1703.207275, 102.671310, 0),
(@PATH, @POINT := @POINT + 1, 783.977722, 1719.925171, 108.779831, 0),
(@PATH, @POINT := @POINT + 1, 766.377869, 1742.267212, 111.976273, 0),
(@PATH, @POINT := @POINT + 1, 776.407715, 1759.183105, 119.131607, 0),
(@PATH, @POINT := @POINT + 1, 793.434387, 1785.451538, 128.699585, 0),
(@PATH, @POINT := @POINT + 1, 786.241211, 1801.446289, 132.674088, 0),
(@PATH, @POINT := @POINT + 1, 794.754456, 1841.365845, 138.421371, 0),
(@PATH, @POINT := @POINT + 1, 794.754456, 1841.365845, 138.421371, 0),
(@PATH, @POINT := @POINT + 1, 786.241211, 1801.446289, 132.674088, 0),
(@PATH, @POINT := @POINT + 1, 793.434387, 1785.451538, 128.699585, 0),
(@PATH, @POINT := @POINT + 1, 776.407715, 1759.183105, 119.131607, 0),
(@PATH, @POINT := @POINT + 1, 766.377869, 1742.267212, 111.976273, 0),
(@PATH, @POINT := @POINT + 1, 783.977722, 1719.925171, 108.779831, 0),
(@PATH, @POINT := @POINT + 1, 784.510010, 1703.207275, 102.671310, 0);

-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69150;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 850.932983, 1815.473267, 131.183044, 0),
(@PATH, @POINT := @POINT + 1, 858.758179, 1780.179321, 124.588852, 0),
(@PATH, @POINT := @POINT + 1, 849.030212, 1744.467041, 114.647156, 0),
(@PATH, @POINT := @POINT + 1, 845.963623, 1732.986572, 106.524895, 0),
(@PATH, @POINT := @POINT + 1, 850.220581, 1717.297363, 101.295227, 0),
(@PATH, @POINT := @POINT + 1, 852.464966, 1705.421509, 94.012650,  0),
(@PATH, @POINT := @POINT + 1, 852.184326, 1689.628784, 90.334763,  0),
(@PATH, @POINT := @POINT + 1, 848.187012, 1677.214600, 86.458450,  0),
(@PATH, @POINT := @POINT + 1, 845.254272, 1671.283081, 77.311638,  0),
(@PATH, @POINT := @POINT + 1, 840.754728, 1662.330200, 71.406410,  0),
(@PATH, @POINT := @POINT + 1, 845.254272, 1671.283081, 77.311638,  0),
(@PATH, @POINT := @POINT + 1, 848.187012, 1677.214600, 86.458450,  0),
(@PATH, @POINT := @POINT + 1, 852.184326, 1689.628784, 90.334763,  0),
(@PATH, @POINT := @POINT + 1, 852.464966, 1705.421509, 94.012650,  0),
(@PATH, @POINT := @POINT + 1, 850.220581, 1717.297363, 101.295227, 0),
(@PATH, @POINT := @POINT + 1, 845.963623, 1732.986572, 106.524895, 0),
(@PATH, @POINT := @POINT + 1, 849.030212, 1744.467041, 114.647156, 0),
(@PATH, @POINT := @POINT + 1, 858.758179, 1780.179321, 124.588852, 0),
(@PATH, @POINT := @POINT + 1, 851.109314, 1852.231567, 138.572388, 0);

-- Moarg Overseer
SET @POINT := 0;
SET @NPC := 69151;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 1093.386108, 1724.781372, 90.728683, 0),
(@PATH, @POINT := @POINT + 1, 1048.029663, 1725.610352, 93.876816, 0),
(@PATH, @POINT := @POINT + 1, 1035.148193, 1724.635620, 91.812302, 0),
(@PATH, @POINT := @POINT + 1, 999.015442, 1713.564087, 91.345856,  0),
(@PATH, @POINT := @POINT + 1, 985.505371, 1709.543701, 82.027374,  0),
(@PATH, @POINT := @POINT + 1, 969.185974, 1709.052979, 90.147209,  0),
(@PATH, @POINT := @POINT + 1, 953.161621, 1719.715820, 97.129723,  0),
(@PATH, @POINT := @POINT + 1, 931.432007, 1729.417480, 101.466690, 0),
(@PATH, @POINT := @POINT + 1, 900.818298, 1722.679932, 103.876762, 0),
(@PATH, @POINT := @POINT + 1, 867.406128, 1714.553467, 101.787544, 0),
(@PATH, @POINT := @POINT + 1, 853.799622, 1709.166748, 94.48749,   0),
(@PATH, @POINT := @POINT + 1, 823.053467, 1699.805542, 98.259392,  0),
(@PATH, @POINT := @POINT + 1, 802.691956, 1689.481079, 100.677605, 0),
(@PATH, @POINT := @POINT + 1, 791.075134, 1687.779297, 97.579872,  0),
(@PATH, @POINT := @POINT + 1, 752.406738, 1716.276978, 98.543800,  0),
(@PATH, @POINT := @POINT + 1, 752.406738, 1716.276978, 98.543800,  0),
(@PATH, @POINT := @POINT + 1, 791.075134, 1687.779297, 97.579872,  0),
(@PATH, @POINT := @POINT + 1, 802.691956, 1689.481079, 100.677605, 0),
(@PATH, @POINT := @POINT + 1, 823.053467, 1699.805542, 98.259392,  0),
(@PATH, @POINT := @POINT + 1, 853.799622, 1709.166748, 94.48749,   0),
(@PATH, @POINT := @POINT + 1, 867.406128, 1714.553467, 101.787544, 0),
(@PATH, @POINT := @POINT + 1, 900.818298, 1722.679932, 103.876762, 0),
(@PATH, @POINT := @POINT + 1, 931.432007, 1729.417480, 101.466690, 0),
(@PATH, @POINT := @POINT + 1, 953.161621, 1719.715820, 97.129723,  0),
(@PATH, @POINT := @POINT + 1, 969.185974, 1709.052979, 90.147209,  0),
(@PATH, @POINT := @POINT + 1, 985.505371, 1709.543701, 82.027374,  0),
(@PATH, @POINT := @POINT + 1, 999.015442, 1713.564087, 91.345856,  0),
(@PATH, @POINT := @POINT + 1, 1035.148193, 1724.635620, 91.812302, 0),
(@PATH, @POINT := @POINT + 1, 1048.029663, 1725.610352, 93.876816, 0),
(@PATH, @POINT := @POINT + 1, 1093.386108, 1724.781372, 90.728683, 0),
(@PATH, @POINT := @POINT + 1, 1119.588745, 1716.730225, 84.372009, 0);


-- Moarg Overseer
SET @GUID := 69152;
SET @POINT := 0;
SET @NPC := 69152;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 980.268799, 1848.870117, 131.911499, 0),
(@PATH, @POINT := @POINT + 1, 988.033997, 1785.729980, 118.09996,  0),
(@PATH, @POINT := @POINT + 1, 984.196899, 1771.750732, 113.933479, 0),
(@PATH, @POINT := @POINT + 1, 978.986877, 1762.243896, 112.581924, 0),
(@PATH, @POINT := @POINT + 1, 967.583191, 1737.078979, 106.542763, 0),
(@PATH, @POINT := @POINT + 1, 975.760986, 1734.712158, 101.783585, 0),
(@PATH, @POINT := @POINT + 1, 986.535706, 1731.655151, 102.132362, 0),
(@PATH, @POINT := @POINT + 1, 981.712769, 1714.359985, 88.433220,  0),
(@PATH, @POINT := @POINT + 1, 977.118408, 1700.509033, 85.810806,  0),
(@PATH, @POINT := @POINT + 1, 971.770752, 1688.218506, 84.186691,  0),
(@PATH, @POINT := @POINT + 1, 977.118408, 1700.509033, 85.810806,  0),
(@PATH, @POINT := @POINT + 1, 981.712769, 1714.359985, 88.433220,  0),
(@PATH, @POINT := @POINT + 1, 986.535706, 1731.655151, 102.132362, 0),
(@PATH, @POINT := @POINT + 1, 975.760986, 1734.712158, 101.783585, 0),
(@PATH, @POINT := @POINT + 1, 967.583191, 1737.078979, 106.542763, 0),
(@PATH, @POINT := @POINT + 1, 978.986877, 1762.243896, 112.581924, 0),
(@PATH, @POINT := @POINT + 1, 984.196899, 1771.750732, 113.933479, 0),
(@PATH, @POINT := @POINT + 1, 988.033997, 1785.729980, 118.09996,  0),
(@PATH, @POINT := @POINT + 1, 980.268799, 1848.870117, 131.911499, 0),
(@PATH, @POINT := @POINT + 1, 985.438416, 1847.512573, 131.616867, 0);

-- Moarg Forgefiend
SET @GUID := 58280;

DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID, 16946, 530, '0', 0, 0, 346.7749, 2238.071, 119.0799, 4.683131, 30, 0, 0, 5158, 0, 2);

UPDATE `creature` SET `position_x`=352.1310, `position_y`=2184.019, `position_z`=118.1270, `orientation`=1.2042770, `spawndist`=0, `MovementType`=2 WHERE `guid`=58976;
UPDATE `creature` SET `position_x`=386.5509, `position_y`=2500.263, `position_z`=150.6602, `orientation`=0.9773844, `spawndist`=0, `MovementType`=2 WHERE `guid`=58977;
UPDATE `creature` SET `position_x`=465.6350, `position_y`=2500.467, `position_z`=158.4418, `orientation`=1.6961510, `spawndist`=0, `MovementType`=2 WHERE `guid`=58978;
UPDATE `creature` SET `position_x`=599.9173, `position_y`=2796.910, `position_z`=222.7564, `orientation`=1.6038840, `spawndist`=0, `MovementType`=2 WHERE `guid`=58979;
UPDATE `creature` SET `position_x`=518.7199, `position_y`=2787.585, `position_z`=213.9373, `orientation`=3.4208450, `spawndist`=0, `MovementType`=2 WHERE `guid`=58980;

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58976;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES

(@PATH, @POINT := @POINT + 1, 372.0695, 2182.736, 118.8579, 0),
(@PATH, @POINT := @POINT + 1, 366.0564, 2166.699, 120.0926, 0),
(@PATH, @POINT := @POINT + 1, 340.2971, 2157.962, 118.1013, 0),
(@PATH, @POINT := @POINT + 1, 366.6094, 2145.635, 119.6319, 0),
(@PATH, @POINT := @POINT + 1, 383.8836, 2119.436, 116.9982, 0),
(@PATH, @POINT := @POINT + 1, 421.0439, 2133.671, 115.8215, 0),
(@PATH, @POINT := @POINT + 1, 440.9657, 2161.880, 116.4515, 0),
(@PATH, @POINT := @POINT + 1, 440.4790, 2203.000, 116.4050, 0),
(@PATH, @POINT := @POINT + 1, 403.2045, 2208.661, 118.3625, 0),
(@PATH, @POINT := @POINT + 1, 401.5527, 2174.006, 118.6883, 0),
(@PATH, @POINT := @POINT + 1, 401.5527, 2174.006, 118.6883, 30000),
(@PATH, @POINT := @POINT + 1, 399.2104, 2191.823, 118.6424, 0),
(@PATH, @POINT := @POINT + 1, 404.8127, 2217.122, 118.2728, 0),
(@PATH, @POINT := @POINT + 1, 396.1408, 2236.705, 118.3385, 0),
(@PATH, @POINT := @POINT + 1, 368.2067, 2248.499, 119.0556, 0),
(@PATH, @POINT := @POINT + 1, 342.0200, 2226.372, 118.8797, 0),
(@PATH, @POINT := @POINT + 1, 346.1346, 2207.040, 118.0938, 0),
(@PATH, @POINT := @POINT + 1, 336.8192, 2195.197, 118.9098, 0),
(@PATH, @POINT := @POINT + 1, 336.6985, 2183.829, 118.4553, 0),
(@PATH, @POINT := @POINT + 1, 351.0053, 2183.569, 117.9545, 30000);

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58977;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 399.4823, 2519.981, 149.8910, 0),
(@PATH, @POINT := @POINT + 1, 406.9428, 2533.171, 148.9787, 0),
(@PATH, @POINT := @POINT + 1, 448.0670, 2525.669, 156.6973, 0),
(@PATH, @POINT := @POINT + 1, 456.0293, 2499.882, 155.5886, 0),
(@PATH, @POINT := @POINT + 1, 434.0441, 2479.981, 147.4321, 0),
(@PATH, @POINT := @POINT + 1, 399.7392, 2485.552, 148.1255, 0),
(@PATH, @POINT := @POINT + 1, 381.8427, 2486.963, 151.5587, 0),
(@PATH, @POINT := @POINT + 1, 367.8258, 2472.422, 154.5495, 0),
(@PATH, @POINT := @POINT + 1, 356.6569, 2483.301, 157.8432, 0),
(@PATH, @POINT := @POINT + 1, 351.3705, 2500.854, 158.6630, 0),
(@PATH, @POINT := @POINT + 1, 357.8864, 2513.297, 157.3211, 0),
(@PATH, @POINT := @POINT + 1, 367.5656, 2531.288, 153.4439, 0),
(@PATH, @POINT := @POINT + 1, 398.3242, 2527.413, 149.3065, 0),
(@PATH, @POINT := @POINT + 1, 395.4784, 2500.946, 149.1616, 0),
(@PATH, @POINT := @POINT + 1, 387.3022, 2499.525, 150.4558, 0);

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58978;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 462.0394, 2528.989, 161.5348, 0),     
(@PATH, @POINT := @POINT + 1, 434.7895, 2532.606, 153.8877, 0),     
(@PATH, @POINT := @POINT + 1, 404.5577, 2534.032, 148.8993, 0),     
(@PATH, @POINT := @POINT + 1, 370.8831, 2546.889, 152.6021, 0),     
(@PATH, @POINT := @POINT + 1, 339.7602, 2528.979, 162.1630, 0),     
(@PATH, @POINT := @POINT + 1, 342.0280, 2510.275, 161.7880, 0),     
(@PATH, @POINT := @POINT + 1, 344.9770, 2491.313, 161.0138, 0),     
(@PATH, @POINT := @POINT + 1, 340.4948, 2467.489, 161.9072, 0),     
(@PATH, @POINT := @POINT + 1, 364.9402, 2466.368, 155.6125, 0),     
(@PATH, @POINT := @POINT + 1, 377.1379, 2448.386, 152.2784, 0),     
(@PATH, @POINT := @POINT + 1, 400.8357, 2454.159, 145.8710, 0),     
(@PATH, @POINT := @POINT + 1, 435.5023, 2459.958, 143.4676, 0),     
(@PATH, @POINT := @POINT + 1, 464.7622, 2488.856, 156.6905, 30000),
(@PATH, @POINT := @POINT + 1, 435.5023, 2459.958, 143.4676, 0),     
(@PATH, @POINT := @POINT + 1, 400.8357, 2454.159, 145.8710, 0),     
(@PATH, @POINT := @POINT + 1, 377.1379, 2448.386, 152.2784, 0),     
(@PATH, @POINT := @POINT + 1, 364.9402, 2466.368, 155.6125, 0),     
(@PATH, @POINT := @POINT + 1, 340.4948, 2467.489, 161.9072, 0),     
(@PATH, @POINT := @POINT + 1, 344.9770, 2491.313, 161.0138, 0),     
(@PATH, @POINT := @POINT + 1, 342.0280, 2510.275, 161.7880, 0),     
(@PATH, @POINT := @POINT + 1, 339.7602, 2528.979, 162.1630, 0),     
(@PATH, @POINT := @POINT + 1, 370.8831, 2546.889, 152.6021, 0),     
(@PATH, @POINT := @POINT + 1, 404.5577, 2534.032, 148.8993, 0),     
(@PATH, @POINT := @POINT + 1, 434.7895, 2532.606, 153.8877, 0),     
(@PATH, @POINT := @POINT + 1, 462.0394, 2528.989, 161.5348, 0),     
(@PATH, @POINT := @POINT + 1, 464.5326, 2500.708, 158.1301, 0);

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58979;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 588.9837, 2829.249, 219.6789, 0),
(@PATH, @POINT := @POINT + 1, 561.5564, 2834.301, 216.8961, 0),
(@PATH, @POINT := @POINT + 1, 536.1294, 2829.619, 214.0218, 0),
(@PATH, @POINT := @POINT + 1, 512.0079, 2818.889, 210.7213, 0),
(@PATH, @POINT := @POINT + 1, 500.9739, 2804.032, 208.2527, 0),
(@PATH, @POINT := @POINT + 1, 512.1336, 2782.000, 210.7045, 0),
(@PATH, @POINT := @POINT + 1, 533.5712, 2764.431, 214.2345, 0),
(@PATH, @POINT := @POINT + 1, 563.5703, 2764.285, 221.0970, 0),
(@PATH, @POINT := @POINT + 1, 596.6008, 2779.521, 224.6383, 0),
(@PATH, @POINT := @POINT + 1, 600.4445, 2798.629, 222.4285, 0),
(@PATH, @POINT := @POINT + 1, 599.4482, 2811.425, 219.6513, 0),
(@PATH, @POINT := @POINT + 1, 588.9837, 2829.249, 219.6789, 0);

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58980;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 517.9482, 2799.258, 214.2896, 0),
(@PATH, @POINT := @POINT + 1, 511.5638, 2804.806, 212.4117, 0),
(@PATH, @POINT := @POINT + 1, 515.9873, 2827.771, 211.1559, 0),
(@PATH, @POINT := @POINT + 1, 561.7473, 2830.094, 216.9400, 0),
(@PATH, @POINT := @POINT + 1, 583.3977, 2830.366, 218.8746, 0),
(@PATH, @POINT := @POINT + 1, 583.2642, 2813.984, 221.0345, 0),
(@PATH, @POINT := @POINT + 1, 572.8552, 2810.281, 221.3586, 0),
(@PATH, @POINT := @POINT + 1, 568.3524, 2799.524, 218.4582, 0),
(@PATH, @POINT := @POINT + 1, 574.8149, 2798.920, 218.5063, 0),
(@PATH, @POINT := @POINT + 1, 574.8149, 2798.920, 218.5063, 30000),
(@PATH, @POINT := @POINT + 1, 572.8413, 2788.211, 222.1392, 0),
(@PATH, @POINT := @POINT + 1, 581.5683, 2772.743, 222.3933, 0),
(@PATH, @POINT := @POINT + 1, 566.0281, 2761.802, 222.5634, 0),
(@PATH, @POINT := @POINT + 1, 546.7617, 2766.647, 216.6348, 0),
(@PATH, @POINT := @POINT + 1, 515.7907, 2761.146, 211.7126, 0),
(@PATH, @POINT := @POINT + 1, 485.8520, 2762.804, 201.7888, 0),
(@PATH, @POINT := @POINT + 1, 491.7773, 2799.334, 205.7678, 0),
(@PATH, @POINT := @POINT + 1, 529.5818, 2800.269, 214.2635, 0),
(@PATH, @POINT := @POINT + 1, 517.9482, 2799.258, 214.2896, 30000);

-- Moarg Forgefiend
SET @POINT := 0;
SET @NPC := 58280;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, 346.0393, 2213.309, 117.9897, 0),
(@PATH, @POINT := @POINT + 1, 337.5000, 2166.667, 118.4763, 0),
(@PATH, @POINT := @POINT + 1, 365.4210, 2150.536, 119.2263, 0),
(@PATH, @POINT := @POINT + 1, 373.9099, 2131.246, 119.1636, 0),
(@PATH, @POINT := @POINT + 1, 401.7648, 2127.054, 116.1107, 0),
(@PATH, @POINT := @POINT + 1, 411.4461, 2144.292, 116.6813, 0),
(@PATH, @POINT := @POINT + 1, 438.6080, 2145.507, 116.6686, 0),
(@PATH, @POINT := @POINT + 1, 465.7404, 2144.955, 119.1745, 0),
(@PATH, @POINT := @POINT + 1, 464.4419, 2177.614, 119.7132, 0),
(@PATH, @POINT := @POINT + 1, 459.4780, 2209.128, 118.3973, 0),
(@PATH, @POINT := @POINT + 1, 449.0729, 2228.586, 118.2239, 0),
(@PATH, @POINT := @POINT + 1, 437.4313, 2244.417, 117.8247, 0),
(@PATH, @POINT := @POINT + 1, 400.4362, 2243.787, 116.9467, 0),
(@PATH, @POINT := @POINT + 1, 366.4103, 2246.238, 119.1055, 0),
(@PATH, @POINT := @POINT + 1, 338.0428, 2233.658, 118.9569, 0);
