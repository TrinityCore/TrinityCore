SET @CGUID := 6748;
SET @OGUID := 1047;
DELETE FROM `creature` WHERE `map` = 33;
DELETE FROM `gameobject` WHERE `map` = 33;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+96;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 208523, 33, 1, 1, -231.2376, 2104.241, 76.15264, 4.337144, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+1, 208524, 33, 1, 1, -231.2376, 2104.241, 76.15264, 4.337144, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+2, 205477, 33, 1, 1, -221.007, 2103.98, 97.3899, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+3, 18934, 33, 1, 1, -251.2443, 2116.379, 81.218, 5.907941, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Cell Door (Area: 0)
(@OGUID+4, 18936, 33, 1, 1, -247.7566, 2125.233, 81.06256, 5.907941, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Cell Door (Area: 0)
(@OGUID+5, 18901, 33, 1, 1, -249.2201, 2123.104, 82.8052, 6.092354, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Lever (Area: 0)
(@OGUID+6, 18900, 33, 1, 1, -252.6959, 2114.227, 82.8052, 6.092354, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Lever (Area: 0)
(@OGUID+7, 101811, 33, 1, 1, -245.5985, 2132.321, 82.8052, 6.092354, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Lever (Area: 0)
(@OGUID+8, 18935, 33, 1, 1, -244.1402, 2134.414, 81.06256, 5.907941, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Cell Door (Area: 0)
(@OGUID+9, 205479, 33, 1, 1, -209.688, 2096.02, 97.3458, 4.904376, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+10, 205477, 33, 1, 1, -238.08, 2136.54, 100.029, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+11, 205477, 33, 1, 1, -253.615, 2120.7, 100.029, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+12, 205479, 33, 1, 1, -237.726, 2143.4, 100.029, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+13, 205479, 33, 1, 1, -262.814, 2115.23, 100.029, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+14, 205479, 33, 1, 1, -191.811, 2118.74, 97.2988, 2.844883, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+15, 205479, 33, 1, 1, -196.667, 2151.56, 79.7635, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+16, 18895, 33, 1, 1, -242.5815, 2159.057, 90.62266, 4.337144, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Courtyard Door (Area: 0)
(@OGUID+17, 205479, 33, 1, 1, -202.238, 2159.51, 79.7648, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+18, 101812, 33, 1, 1, -236.2511, 2164.048, 91.15625, 5.312439, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Lever (Area: 0)
(@OGUID+19, 205477, 33, 1, 1, -271.637, 2142.34, 95.8646, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+20, 205477, 33, 1, 1, -247.819, 2163.41, 93.9366, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+21, 205477, 33, 1, 1, -194.863, 2165.8, 79.7327, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+22, 205479, 33, 1, 1, -254.628, 2169.19, 93.9366, 2.286379, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+23, 205479, 33, 1, 1, -214, 2189.89, 79.9687, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+24, 205477, 33, 1, 1, -248.95, 2186.98, 93.9313, 4.991644, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+25, 205479, 33, 1, 1, -178.514, 2173.5, 97.3899, 4.782203, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+26, 205477, 33, 1, 1, -173.444, 2171.28, 94.0566, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+27, 205479, 33, 1, 1, -174.59, 2174.67, 94.0566, 6.056293, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+28, 205477, 33, 1, 1, -186.708, 2176.02, 126.284, 0.6632232, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+29, 205479, 33, 1, 1, -238.793, 2203.98, 97.3452, 5.777041, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+30, 205479, 33, 1, 1, -184.837, 2190.37, 114.031, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+31, 18972, 33, 1, 1, -129.0337, 2166.165, 129.1874, 5.907941, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Sorcerer's Gate (Area: 0)
(@OGUID+32, 18971, 33, 1, 1, -118.1101, 2161.861, 155.6785, 2.766338, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Arugal's Lair (Area: 0)
(@OGUID+33, 205477, 33, 1, 1, -172.861, 2178.94, 138.697, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+34, 205479, 33, 1, 1, -153.193, 2178.07, 99.8762, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+35, 205479, 33, 1, 1, -153.073, 2159.13, 128.944, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+36, 205477, 33, 1, 1, -148.191, 2159.12, 128.944, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+37, 205476, 33, 1, 1, -138.929, 2161.87, 129.587, 2.164206, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+38, 205477, 33, 1, 1, -125.96, 2160.27, 101.516, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+39, 205479, 33, 1, 1, -126.589, 2169.04, 94.0483, 3.194002, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+40, 36738, 33, 1, 1, -155.171, 2185.61, 130.643, 0.7853968, 0, 0, 0, 1, 7200, 255, 1), -- The Book of Ur (Area: 0)
(@OGUID+41, 205477, 33, 1, 1, -179.531, 2212.37, 79.8538, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+42, 205477, 33, 1, 1, -134.481, 2184.02, 113.132, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+43, 205477, 33, 1, 1, -173.682, 2179.49, 151.906, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+44, 205479, 33, 1, 1, -126.828, 2180.26, 113.132, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+45, 205477, 33, 1, 1, -161.406, 2175.24, 151.906, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+46, 205479, 33, 1, 1, -135.783, 2181.04, 128.944, 6.265733, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+47, 205477, 33, 1, 1, -131.776, 2162.59, 138.697, 2.687807, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+48, 205477, 33, 1, 1, -138.012, 2186.39, 128.944, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+49, 205477, 33, 1, 1, -119.925, 2160.16, 128.944, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+50, 205479, 33, 1, 1, -174.286, 2222.48, 79.7597, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+51, 18973, 33, 1, 1, -146.3912, 2173.001, 150.5433, 4.337144, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Arugal's Focus (Area: 0)
(@OGUID+52, 205477, 33, 1, 1, -190.512, 2225.8, 79.7583, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+53, 205477, 33, 1, 1, -103.708, 2153.57, 101.52, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+54, 205479, 33, 1, 1, -142.115, 2160.31, 155.678, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+55, 205479, 33, 1, 1, -198.701, 2226.63, 79.7588, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+56, 205477, 33, 1, 1, -135.97, 2156.85, 155.678, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+57, 205479, 33, 1, 1, -228.955, 2231.31, 93.5395, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+58, 205477, 33, 1, 1, -176.656, 2239.12, 76.2413, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+59, 91138, 33, 1, 1, -218.464, 2237.2, 80.7977, 4.101525, 0, 0, 0, 1, 7200, 255, 1), -- Jordan's Hammer (Area: 0)
(@OGUID+60, 205479, 33, 1, 1, -229.344, 2234.06, 79.7786, 1.884953, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+61, 182011, 33, 1, 1, -207.3954, 2245.313, 79.76888, 4.380776, 0, 0, 0, 1, 7200, 255, 1), -- Crate of Ingots (Area: 0)
(@OGUID+62, 205479, 33, 1, 1, -219.623, 2243.78, 79.7719, 4.904376, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+63, 205479, 33, 1, 1, -258.188, 2241.13, 100.893, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+64, 205477, 33, 1, 1, -228.33, 2247.05, 102.28, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+65, 205479, 33, 1, 1, -224.007, 2249.19, 102.756, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+66, 35595, 33, 1, 1, -218.5085, 2260.465, 77.338, 0.8028509, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+67, 35593, 33, 1, 1, -220.5779, 2258.186, 77.338, 5.907941, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+68, 35594, 33, 1, 1, -219.6944, 2259.449, 77.338, 3.551751, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+69, 205479, 33, 1, 1, -226.365, 2261.17, 102.756, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+70, 205479, 33, 1, 1, -216.665, 2259.35, 77.369, 0.9075702, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+71, 205479, 33, 1, 1, -199.259, 2262.45, 90.6437, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+72, 35596, 33, 1, 1, -215.0031, 2270.456, 77.338, 4.337144, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+73, 35597, 33, 1, 1, -214.7548, 2272.269, 77.338, 3.804818, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+74, 205479, 33, 1, 1, -198.661, 2268.45, 76.2013, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+75, 205479, 33, 1, 1, -213.429, 2270.35, 77.3683, 0.8377574, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+76, 205479, 33, 1, 1, -271.316, 2268.35, 95.8664, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+77, 35598, 33, 1, 1, -213.1998, 2273.377, 77.338, 3.159062, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Roaring Fire (Area: 0)
(@OGUID+78, 205477, 33, 1, 1, -206.868, 2272.48, 77.4965, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+79, 205479, 33, 1, 1, -228.019, 2279.81, 74.9993, 0.05235888, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+80, 205479, 33, 1, 1, -211.583, 2273.13, 77.3993, 3.630291, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+81, 205477, 33, 1, 1, -275.962, 2269.2, 95.8664, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+82, 205479, 33, 1, 1, -284.512, 2272.58, 96.6954, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+83, 205479, 33, 1, 1, -180.538, 2289.75, 95.899, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+84, 205477, 33, 1, 1, -243.387, 2295.59, 74.9993, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+85, 205479, 33, 1, 1, -224.309, 2294.28, 94.6765, 3.647741, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+86, 205479, 33, 1, 1, -266.962, 2296.04, 76.1532, 6.003934, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+87, 205479, 33, 1, 1, -214.806, 2311.03, 94.6765, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+88, 205479, 33, 1, 1, -124.974, 2174.3, 155.678, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+89, 205479, 33, 1, 1, -256.186, 2308.3, 95.8665, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+90, 205477, 33, 1, 1, -276.309, 2297.26, 76.1532, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+91, 205477, 33, 1, 1, -298.878, 2307.23, 91.3811, 5.916668, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+92, 205479, 33, 1, 1, -298.811, 2307.13, 82.4281, 5.916668, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+93, 18899, 33, 1, 1, -113.7616, 2165.086, 157.8547, 1.195702, 0, 0, -0.8265896, 0.5628051, 7200, 255, 1), -- Lever (Area: 0)
(@OGUID+94, 205479, 33, 1, 1, -98.6997, 2169.6, 155.682, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+95, 205477, 33, 1, 1, -82.5712, 2122.09, 144.921, 1.186823, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+96, 205479, 33, 1, 1, -73.4566, 2140.03, 155.655, 2.897245, 0, 0, 0, 1, 7200, 255, 1); -- -Unknown- (Area: 0)

DELETE FROM `quest_poi_points` WHERE (`questId`=27988 AND `id`=0) OR (`questId`=27988 AND `id`=1) OR (`questId`=27988 AND `id`=2) OR (`questId`=27996 AND `id`=0) OR (`questId`=27996 AND `id`=1) OR (`questId`=27998 AND `id`=0) OR (`questId`=27998 AND `id`=1);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(27988, 0, 0, -225, 2258), -- Plague...Plague Everywhere!
(27988, 1, 0, -270, 2295), -- Plague...Plague Everywhere!
(27988, 2, 0, -244, 2252), -- Plague...Plague Everywhere!
(27996, 0, 0, -147, 2173), -- Orders Are For the Living
(27996, 1, 0, -147, 2173), -- Orders Are For the Living
(27998, 0, 0, -94, 2144), -- Sweet, Merciless Revenge
(27998, 1, 0, -93, 2144); -- Sweet; Merciless Revenge

/*
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47131; -- Frantic Geist
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=0.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47135; -- Fetid Ghoul
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=33587264, `dynamicflags`=0 WHERE `entry`=3869; -- Lesser Gargoyle
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=0.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47134; -- Corpse Eater
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32832 WHERE `entry`=47140; -- Sorcerous Skeleton
UPDATE `creature_template` SET `minlevel`=6, `maxlevel`=6, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=48124; -- Rabid Mastiff
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32832, `VehicleId`=1422 WHERE `entry`=46962; -- Baron Ashbury
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=50604; -- Wings
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=33587264, `dynamicflags`=0 WHERE `entry`=3870; -- Stone Sleeper
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction_A`=12, `faction_H`=12, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=256 WHERE `entry`=47862; -- Magistrate Henry Maleb
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2110; -- Black Rat
UPDATE `creature_template` SET `minlevel`=18, `maxlevel`=19, `faction_A`=68, `faction_H`=68, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=47030; -- Veteran Forsaken Trooper
UPDATE `creature_template` SET `minlevel`=13, `maxlevel`=13, `faction_A`=68, `faction_H`=68, `speed_walk`=0.2857143, `speed_run`=0.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=47865; -- Forsaken Trooper
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47137; -- Mindless Horror
UPDATE `creature_template` SET `gossip_menu_id`=12258, `minlevel`=18, `maxlevel`=18, `faction_A`=68, `faction_H`=68, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=4, `unit_flags`=33536 WHERE `entry`=47293; -- Deathstalker Commander Belmont
UPDATE `creature_template` SET `minlevel`=15, `maxlevel`=15, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=51400; -- Haunted Stable Hand
UPDATE `creature_template` SET `minlevel`=18, `maxlevel`=19, `faction_A`=68, `faction_H`=68, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=47031; -- Forsaken Blightspreader
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3875; -- Haunted Servitor
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=43679; -- DEBUG Announcer
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3877; -- Wailing Guardsman
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3873; -- Tormented Officer
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1600, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47145; -- Spitebone Guardian
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32832 WHERE `entry`=46963; -- Lord Walden
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1.2, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4278; -- Commander Springvale
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32832 WHERE `entry`=46964; -- Lord Godfrey
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=16, `faction_H`=16, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3887; -- Baron Silverlaine
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47132; -- Dark Creeper
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=0.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47136; -- Unstable Ravager
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32832 WHERE `entry`=47141; -- Dread Scryer
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47146; -- Spitebone Flayer
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32832 WHERE `entry`=47231; -- Shadowy Attendant
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=50611; -- Springvale Spawn Stalker
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=15, `faction_H`=15, `speed_walk`=1.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=3865; -- Shadow Charger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.285714, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=3864; -- Fel Steed
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=24, `faction_H`=24, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50613; -- Wailing Guardsman
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50615; -- Tormented Officer
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47232; -- Ghostly Cook
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1600, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47143; -- Spitebone Skeleton
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=47294; -- High Warlord Cromush
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `faction_A`=16, `faction_H`=16, `speed_walk`=1.289683, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=47138; -- Pustulant Monstrosity
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=15106; -- Frostwolf Emissary
*/

REPLACE INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(47131, 0, 0x0, 0x1, '91077'), -- Frantic Geist - Frantic Leap
(47135, 0, 0x0, 0x1, '91561'), -- Fetid Ghoul - Disease Cloud
(47131, 0, 0x0, 0x1, ''), -- Frantic Geist
(3869, 0, 0x3000000, 0x1, ''), -- Lesser Gargoyle
(47134, 0, 0x0, 0x1, ''), -- Corpse Eater
(47140, 0, 0x0, 0x1, ''), -- Sorcerous Skeleton
(48124, 0, 0x0, 0x1, ''), -- Rabid Mastiff
(46962, 0, 0x0, 0x1, ''), -- Baron Ashbury
(50604, 0, 0x0, 0x1, '46598'), -- Wings - Ride Vehicle Hardcoded
(53488, 0, 0x0, 0x1, '99201'), -- Summon Enabler Stalker - Summon Enabler
(3870, 0, 0x3000000, 0x1, ''), -- Stone Sleeper
(47862, 0, 0x0, 0x1, ''), -- Magistrate Henry Maleb
(2110, 0, 0x0, 0x1, ''), -- Black Rat
(23837, 0, 0x0, 0x1, '88198'), -- ELM General Purpose Bunny - Disease Cloud
(47030, 0, 0x0, 0x1, ''), -- Veteran Forsaken Trooper
(47865, 0, 0x0, 0x1, ''), -- Forsaken Trooper
(47865, 0, 0x3, 0x1, ''), -- Forsaken Trooper
(47137, 0, 0x0, 0x1, ''), -- Mindless Horror
(47865, 0, 0x1, 0x1, ''), -- Forsaken Trooper
(47293, 0, 0x0, 0x1, ''), -- Deathstalker Commander Belmont
(51400, 0, 0x0, 0x1, ''), -- Haunted Stable Hand
(47031, 0, 0x0, 0x2, ''), -- Forsaken Blightspreader
(3875, 0, 0x0, 0x1, ''), -- Haunted Servitor
(43679, 0, 0x0, 0x1, ''), -- DEBUG Announcer
(3877, 0, 0x0, 0x1, ''), -- Wailing Guardsman
(3873, 0, 0x0, 0x1, ''), -- Tormented Officer
(47145, 0, 0x0, 0x1, ''), -- Spitebone Guardian
(46963, 0, 0x0, 0x1, ''), -- Lord Walden
(4278, 0, 0x0, 0x1, ''), -- Commander Springvale
(46964, 0, 0x0, 0x1, '93597'), -- Lord Godfrey - Pistols Visual Passive
(3887, 0, 0x0, 0x1, ''), -- Baron Silverlaine
(47132, 0, 0x0, 0x1, ''), -- Dark Creeper
(47136, 0, 0x0, 0x1, ''), -- Unstable Ravager
(45979, 0, 0x0, 0x1, ''), -- General Purpose Bunny JMF
(47141, 0, 0x0, 0x1, ''), -- Dread Scryer
(47146, 0, 0x0, 0x1, ''), -- Spitebone Flayer
(47231, 0, 0x0, 0x1, '37816'), -- Shadowy Attendant - Shadowform
(50611, 0, 0x0, 0x1, ''), -- Springvale Spawn Stalker
(3865, 0, 0x0, 0x1, ''), -- Shadow Charger
(3864, 0, 0x0, 0x1, ''), -- Fel Steed
(50613, 0, 0x0, 0x1, ''), -- Wailing Guardsman
(50615, 0, 0x0, 0x1, ''), -- Tormented Officer
(47232, 0, 0x0, 0x1, ''), -- Ghostly Cook
(47143, 0, 0x0, 0x1, ''), -- Spitebone Skeleton
(47293, 0, 0x0, 0x1, '58506'), -- Deathstalker Commander Belmont - Stealth
(47031, 0, 0x0, 0x1, ''), -- Forsaken Blightspreader
(47294, 0, 0x0, 0x1, ''), -- High Warlord Cromush
(47138, 0, 0x0, 0x1, ''), -- Pustulant Monstrosity
(47030, 0, 0x0, 0x1, '29266'), -- Veteran Forsaken Trooper - Permanent Feign Death
(47294, 0, 0x8, 0x1, ''), -- High Warlord Cromush
(47031, 0, 0x0, 0x1, '29266'); -- Forsaken Blightspreader - Permanent Feign Death

DELETE FROM `creature_model_info` WHERE `modelid` IN (304, 1141, 1310, 1312, 1313, 1318, 1320, 1358, 1392, 1619, 1951, 3128, 3229, 3230, 3546, 3564, 3604, 3605, 3606, 3608, 3609, 4259, 4260, 4356, 4514, 4601, 4602, 5205, 5706, 7117, 7137, 7511, 7534, 8000, 8001, 8971, 9133, 11686, 14429, 14501, 15237, 15244, 15245, 15467, 15468, 15511, 15966, 16045, 16176, 16850, 16925, 17188, 21264, 22493, 24985, 24992, 24998, 25001, 25182, 25183, 25184, 26918, 27323, 28022, 30210, 30211, 30212, 32904, 33988, 34009, 34077, 34136, 34139, 34141, 34143, 34144, 34154, 34155, 34156, 34157, 34172, 34173, 34174, 34406, 34412, 34610, 34611, 34612, 35140, 35141, 35148, 35574, 35868, 36256, 36329, 36374, 36559, 36583, 36584, 36585, 36615, 37138, 37287, 37288, 37289, 37290, 37291, 37292, 37294, 37297, 37298, 37299, 37300, 37301, 37302, 37358, 37374, 37724, 37726, 40012);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`) VALUES
(304, 0.145, 1, 2),
(1141, 1, 1, 2),
(1310, 0.372, 1.5, 0),
(1312, 0.236, 1.5, 1),
(1313, 0.372, 1.5, 0),
(1318, 0.372, 1.5, 0),
(1320, 0.372, 1.5, 0),
(1358, 0.236, 1.5, 1),
(1392, 0.372, 1.5, 0),
(1619, 0.4836, 1.95, 0),
(1951, 1.15, 1.725, 2),
(3128, 0.236, 1.5, 1),
(3229, 0.306, 1.5, 0),
(3230, 0.208, 1.5, 1),
(3546, 0.372, 1.5, 0),
(3564, 0.236, 1.5, 1),
(3604, 0.372, 1.5, 0),
(3605, 0.372, 1.5, 0),
(3606, 0.372, 1.5, 0),
(3608, 0.306, 1.5, 0),
(3609, 0.372, 1.5, 0),
(4259, 0.372, 1.5, 0),
(4260, 0.236, 1.5, 1),
(4356, 0.236, 1.5, 1),
(4514, 0.372, 1.5, 0),
(4601, 0.236, 1.5, 1),
(4602, 0.372, 1.5, 0),
(5205, 0.9747, 4.05, 0),
(5706, 0.236, 1.5, 1),
(7117, 0.383, 1.5, 0),
(7137, 0.306, 1.5, 0),
(7511, 0.05, 0.15, 2),
(7534, 1, 1.5, 2),
(8000, 0.372, 1.5, 0),
(8001, 0.372, 1.5, 0),
(8971, 0.05, 0.15, 2),
(9133, 0.372, 1.5, 0),
(11686, 0.5, 1, 2),
(14429, 0.4092, 1.65, 0),
(14501, 2.5, 5, 2),
(15237, 0.306, 1.5, 0),
(15244, 0.236, 1.5, 1),
(15245, 0.9747, 4.05, 0),
(15467, 0.05, 0.15, 2),
(15468, 0.05, 0.15, 2),
(15511, 0.5, 1.5, 0),
(15966, 0.372, 1.5, 0),
(16045, 1.65, 1.65, 2),
(16176, 0.6, 1.8, 0),
(16850, 0.383, 1.5, 1),
(16925, 0.5, 1, 2),
(17188, 0.125, 0.25, 2),
(21264, 0.383, 1.5, 0),
(22493, 0.306, 1.5, 0),
(24985, 0.306, 1.5, 1),
(24992, 0.31, 1, 2),
(24998, 0.3565, 1.15, 2),
(25001, 0.279, 0.9, 2),
(25182, 0.306, 1.5, 0),
(25183, 0.306, 1.5, 0),
(25184, 0.306, 1.5, 0),
(26918, 0.31, 1, 2),
(27323, 1.5, 0, 2),
(28022, 0.2777776, 1.2, 0),
(30210, 0.7, 0, 2),
(30211, 0.7, 0, 2),
(30212, 0.7, 0, 2),
(32904, 0.4185, 1.35, 0),
(33988, 0.383, 1.5, 0),
(34009, 0.465, 1.875, 0),
(34077, 0.4596, 1.8, 0),
(34136, 0.3366, 1.65, 0),
(34139, 0.3366, 1.65, 0),
(34141, 0.3366, 1.65, 0),
(34143, 0.3366, 1.65, 1),
(34144, 0.3366, 1.65, 1),
(34154, 0.3366, 1.65, 0),
(34155, 0.3366, 1.65, 0),
(34156, 0.3366, 1.65, 1),
(34157, 0.3366, 1.65, 1),
(34172, 0.4213, 1.65, 0),
(34173, 0.4213, 1.65, 0),
(34174, 0.4213, 1.65, 1),
(34406, 0.383, 1.5, 0),
(34412, 0.383, 1.5, 1),
(34610, 0.44045, 1.725, 0),
(34611, 0.5745, 2.25, 0),
(34612, 0.44045, 1.725, 0),
(35140, 0.372, 1.5, 0),
(35141, 0.236, 1.5, 1),
(35148, 0.372, 1.5, 0),
(35574, 0.2777776, 1.2, 0),
(35868, 0.4340275, 1.875, 0),
(36256, 0.85, 1.275, 2),
(36329, 1.5, 0, 2),
(36374, 0.2604165, 1.125, 0),
(36559, 0.3348, 1.35, 0),
(36583, 0.031, 0.1, 2),
(36584, 0.031, 0.1, 2),
(36585, 0.031, 0.1, 2),
(36615, 0.372, 1.5, 0),
(37138, 2.5, 3.75, 2),
(37287, 0.3825, 1.875, 0),
(37288, 0.3672, 1.8, 0),
(37289, 0.306, 1.5, 0),
(37290, 0.306, 1.5, 0),
(37291, 0.306, 1.5, 0),
(37292, 0.306, 1.5, 0),
(37294, 0.306, 1.5, 0),
(37297, 0.306, 1.5, 0),
(37298, 0.208, 1.5, 1),
(37299, 0.306, 1.5, 0),
(37300, 0.306, 1.5, 0),
(37301, 0.372, 1.2, 2),
(37302, 0.372, 1.2, 2),
(37358, 0.306, 1.5, 0),
(37374, 0.306, 1.5, 0),
(37724, 0.372, 1.5, 0),
(37726, 0.236, 1.5, 1),
(40012, 0.372, 1.5, 0);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+401;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 47131, 33, 1, 1, -192.3733, 2129.626, 81.50174, 1.131423, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+1, 47135, 33, 1, 1, -257.7135, 2117.493, 100.1122, 2.687807, 7200, 0, 0), -- 47135 (Area: 0) (possible waypoints or random movement)
(@CGUID+2, 47131, 33, 1, 1, -245.2069, 2143.401, 87.01566, 5.94434, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+3, 3869, 33, 1, 1, -198.316, 2138.08, 100.2357, 2.86234, 7200, 0, 0), -- 3869 (Area: 0) (possible waypoints or random movement)
(@CGUID+4, 47134, 33, 1, 1, -235.637, 2133.99, 87.09824, 0, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+5, 47134, 33, 1, 1, -238.516, 2139.9, 87.09624, 0, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+6, 47134, 33, 1, 1, -229.6594, 2149.573, 90.62401, 2.66108, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+7, 47131, 33, 1, 1, -226.663, 2143.481, 90.62401, 5.598114, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+8, 47131, 33, 1, 1, -221.4243, 2145.292, 90.62401, 3.819242, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+9, 47134, 33, 1, 1, -220.259, 2141.235, 90.624, 5.048132, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+10, 47131, 33, 1, 1, -241.4894, 2153.962, 90.62401, 4.661827, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+11, 47134, 33, 1, 1, -201.9822, 2140.161, 86.49866, 0.3909685, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+12, 47134, 33, 1, 1, -204.2973, 2136.145, 86.50033, 2.501437, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+13, 47134, 33, 1, 1, -195.0133, 2133.827, 81.50249, 3.409634, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+14, 47140, 33, 1, 1, -241.0747, 2134.972, 100.1122, 2.86234, 7200, 0, 0), -- 47140 (Area: 0) (possible waypoints or random movement)
(@CGUID+15, 47135, 33, 1, 1, -241.8594, 2137.193, 100.1122, 4.08407, 7200, 0, 0), -- 47135 (Area: 0) (possible waypoints or random movement)
(@CGUID+16, 48124, 33, 1, 1, -243.764, 2133.72, 81.26294, 2.687807, 7200, 0, 0), -- 48124 (Area: 0)
(@CGUID+17, 47131, 33, 1, 1, -236.6776, 2146.866, 89.29508, 1.390159, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+18, 47131, 33, 1, 1, -193.6445, 2142.774, 85.19395, 2.645304, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+19, 46962, 33, 1, 1, -256.1198, 2117.153, 81.26291, 1.239184, 7200, 0, 0), -- 46962 (Area: 0) (possible waypoints or random movement)
(@CGUID+20, 50604, 33, 1, 1, -256.0985, 2117.215, 83.08554, 1.239184, 7200, 0, 0), -- 50604 (Area: 0) (possible waypoints or random movement)
(@CGUID+21, 48124, 33, 1, 1, -238.9757, 2131.961, 81.17957, 0.3949043, 7200, 0, 0), -- 48124 (Area: 0) (possible waypoints or random movement)
(@CGUID+22, 48124, 33, 1, 1, -237.469, 2132.91, 81.17957, 6.217979, 7200, 0, 0), -- 48124 (Area: 0) (possible waypoints or random movement)
(@CGUID+23, 53488, 33, 1, 1, -226.5538, 2112.625, 76.9734, 0, 7200, 0, 0), -- 53488 (Area: 0)
(@CGUID+24, 53488, 33, 1, 1, -220.8542, 2129.608, 80.79417, 0, 7200, 0, 0), -- 53488 (Area: 0)
(@CGUID+25, 47131, 33, 1, 1, -191.6051, 2137.966, 97.38995, 1.26845, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+26, 47140, 33, 1, 1, -260.4965, 2116.21, 100.1122, 0.9075712, 7200, 0, 0), -- 47140 (Area: 0) (possible waypoints or random movement)
(@CGUID+27, 47140, 33, 1, 1, -261.5434, 2118.865, 100.1122, 0.03490658, 7200, 0, 0), -- 47140 (Area: 0) (possible waypoints or random movement)
(@CGUID+28, 47135, 33, 1, 1, -242.5851, 2132.731, 100.1122, 1.780236, 7200, 0, 0), -- 47135 (Area: 0) (possible waypoints or random movement)
(@CGUID+29, 47131, 33, 1, 1, -193.2111, 2128.549, 81.50174, 0.5227926, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+30, 47131, 33, 1, 1, -198.3053, 2126.011, 81.50174, 4.298252, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+31, 47134, 33, 1, 1, -195.8924, 2123.04, 81.50173, 3.458903, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+32, 47134, 33, 1, 1, -238.5556, 2117.652, 87.00503, 6.134785, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+33, 47134, 33, 1, 1, -243.9065, 2117.746, 87.00905, 1.762544, 7200, 0, 0), -- 47134 (Area: 0) (possible waypoints or random movement)
(@CGUID+34, 47131, 33, 1, 1, -235.3685, 2144.307, 88.34989, 1.140444, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+35, 3869, 33, 1, 1, -202.3299, 2127.677, 100.2357, 2.740167, 7200, 0, 0), -- 3869 (Area: 0) (possible waypoints or random movement)
(@CGUID+36, 3870, 33, 1, 1, -188.4635, 2122.181, 100.2353, 5.951573, 7200, 0, 0), -- 3870 (Area: 0) (possible waypoints or random movement)
(@CGUID+37, 47862, 33, 1, 1, -248.597, 2115.47, 81.26294, 2.775074, 7200, 0, 0), -- 47862 (Area: 0)
(@CGUID+38, 47131, 33, 1, 1, -190.1285, 2138.069, 97.38995, 1.266544, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+39, 3870, 33, 1, 1, -226.6076, 2099.431, 100.2353, 4.34587, 7200, 0, 0), -- 3870 (Area: 0) (possible waypoints or random movement)
(@CGUID+40, 3870, 33, 1, 1, -216.4965, 2095.53, 100.2353, 4.415683, 7200, 0, 0), -- 3870 (Area: 0) (possible waypoints or random movement)
(@CGUID+41, 3869, 33, 1, 1, -218.2153, 2103.663, 100.2357, 1.204277, 7200, 0, 0), -- 3869 (Area: 0) (possible waypoints or random movement)
(@CGUID+42, 3869, 33, 1, 1, -224.1198, 2106.042, 100.2357, 1.151917, 7200, 0, 0), -- 3869 (Area: 0) (possible waypoints or random movement)
(@CGUID+43, 47131, 33, 1, 1, -190.865, 2139.663, 97.38995, 1.287642, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+44, 47131, 33, 1, 1, -192.8881, 2140.326, 97.38995, 1.277357, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+45, 47131, 33, 1, 1, -192.6869, 2138.87, 97.38995, 1.278435, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+46, 2110, 33, 1, 1, -224.3172, 2110.893, 76.88892, 5.731835, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+47, 23837, 33, 1, 1, -232.595, 2109.81, 76.97463, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+48, 23837, 33, 1, 1, -233.111, 2110.01, 76.81664, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+49, 23837, 33, 1, 1, -233.965, 2112.36, 76.93284, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+50, 23837, 33, 1, 1, -233.917, 2113.56, 76.69134, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+51, 23837, 33, 1, 1, -233.686, 2114.25, 76.97353, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+52, 23837, 33, 1, 1, -232.684, 2115.75, 76.91784, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+53, 23837, 33, 1, 1, -221.415, 2106.98, 76.80504, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+54, 47030, 33, 1, 1, -228.497, 2122.73, 80.25184, 4.782202, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+55, 47030, 33, 1, 1, -226.722, 2124.83, 80.44633, 4.625123, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+56, 47030, 33, 1, 1, -216.899, 2120.18, 80.24763, 4.276057, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+57, 47865, 33, 1, 1, -236.7, 2124.06, 81.29574, 3.961897, 7200, 0, 0), -- 47865 (Area: 0)
(@CGUID+58, 47030, 33, 1, 1, -217.365, 2122.68, 80.41753, 4.34587, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+59, 47865, 33, 1, 1, -240.286, 2121.03, 81.26294, 4.502949, 7200, 0, 0), -- 47865 (Area: 0)
(@CGUID+60, 23837, 33, 1, 1, -213.844, 2104.05, 76.97723, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+61, 23837, 33, 1, 1, -214.318, 2102.04, 76.97733, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+62, 23837, 33, 1, 1, -213.181, 2102.54, 76.97733, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+63, 47137, 33, 1, 1, -215.4462, 2162.984, 79.84892, 0.3110535, 7200, 0, 0), -- 47137 (Area: 0) (possible waypoints or random movement)
(@CGUID+64, 23837, 33, 1, 1, -211.948, 2103.17, 76.97723, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+65, 23837, 33, 1, 1, -212.635, 2101.51, 76.97733, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+66, 23837, 33, 1, 1, -214.344, 2123.62, 80.32754, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+67, 47865, 33, 1, 1, -240.944, 2124.97, 81.26294, 4.101524, 7200, 0, 0), -- 47865 (Area: 0)
(@CGUID+68, 3870, 33, 1, 1, -184.8802, 2132.583, 100.2357, 5.864306, 7200, 0, 0), -- 3870 (Area: 0) (possible waypoints or random movement)
(@CGUID+69, 2110, 33, 1, 1, -244.4494, 2117.384, 87.0091, 2.128679, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+70, 23837, 33, 1, 1, -214.344, 2124.69, 80.37054, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+71, 47293, 33, 1, 1, -220.958, 2129.48, 80.78983, 4.607669, 7200, 0, 0), -- 47293 (Area: 0)
(@CGUID+72, 47865, 33, 1, 1, -244.807, 2121.68, 81.26294, 1.186824, 7200, 0, 0), -- 47865 (Area: 0)
(@CGUID+73, 23837, 33, 1, 1, -230.3, 2131.51, 80.54034, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+74, 23837, 33, 1, 1, -213.861, 2125.93, 80.53143, 2.984513, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+75, 47865, 33, 1, 1, -246.564, 2123.26, 81.17957, 4.28798, 7200, 0, 0), -- 47865 (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 47131, 33, 1, 1, -217.9365, 2163.404, 79.76488, 5.546183, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+77, 23837, 33, 1, 1, -204.96, 2104.55, 77.02894, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+78, 51400, 33, 1, 1, -205.1563, 2103.661, 76.97897, 3.577925, 7200, 0, 0), -- 51400 (Area: 0)
(@CGUID+79, 47031, 33, 1, 1, -225.693, 2136.02, 80.95454, 4.677482, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+80, 47131, 33, 1, 1, -218.3706, 2164.158, 79.76498, 5.429403, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+81, 23837, 33, 1, 1, -203.427, 2104.38, 76.40823, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+82, 47031, 33, 1, 1, -214.486, 2134.03, 80.94864, 4.485496, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+83, 3875, 33, 1, 1, -221.4245, 2168.729, 79.81442, 1.483001, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+84, 47131, 33, 1, 1, -217.966, 2165.442, 79.76516, 5.421358, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+85, 47131, 33, 1, 1, -215.3763, 2165.744, 79.76518, 5.482455, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+86, 47131, 33, 1, 1, -216.6836, 2166.071, 79.76524, 5.441153, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+87, 23837, 33, 1, 1, -216.286, 2140.91, 81.48534, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+88, 23837, 33, 1, 1, -215.217, 2140.47, 81.55943, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+89, 23837, 33, 1, 1, -218.227, 2141.67, 81.38644, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+90, 23837, 33, 1, 1, -217.28, 2141.3, 81.67484, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+91, 23837, 33, 1, 1, -214.439, 2140.15, 81.69784, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+92, 23837, 33, 1, 1, -219.042, 2141.99, 81.62763, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+93, 23837, 33, 1, 1, -213.128, 2139.61, 81.71724, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+94, 23837, 33, 1, 1, -219.905, 2142.33, 81.50333, 4.468043, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+95, 23837, 33, 1, 1, -220.905, 2142.73, 81.48224, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+96, 23837, 33, 1, 1, -221.708, 2143.04, 81.70863, 4.433136, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+97, 23837, 33, 1, 1, -222.495, 2143.35, 81.57973, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+98, 23837, 33, 1, 1, -223.46, 2143.73, 81.47704, 4.29351, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+99, 23837, 33, 1, 1, -224.319, 2144.07, 81.46143, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+100, 2110, 33, 1, 1, -205.2759, 2134.859, 86.50021, 1.362284, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+101, 23837, 33, 1, 1, -225.245, 2144.43, 81.35064, 4.520403, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+102, 23837, 33, 1, 1, -226.214, 2144.81, 81.37144, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+103, 23837, 33, 1, 1, -227.076, 2145.15, 81.34364, 4.555309, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+104, 23837, 33, 1, 1, -228.016, 2145.52, 81.41843, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+105, 23837, 33, 1, 1, -228.818, 2145.84, 81.49213, 4.537856, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+106, 23837, 33, 1, 1, -229.615, 2146.15, 81.40894, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+107, 23837, 33, 1, 1, -230.608, 2146.54, 81.36684, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+108, 43679, 33, 1, 1, -204.0156, 2094.72, 101.9963, 1.762783, 7200, 0, 0), -- 43679 (Area: 0)
(@CGUID+109, 3877, 33, 1, 1, -250.3969, 2172.874, 93.93663, 5.155059, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+110, 3873, 33, 1, 1, -249.0975, 2175.013, 93.93613, 1.093538, 7200, 0, 0), -- 3873 (Area: 0) (possible waypoints or random movement)
(@CGUID+111, 47137, 33, 1, 1, -209.9551, 2179.295, 79.76586, 5.137099, 7200, 0, 0), -- 47137 (Area: 0) (possible waypoints or random movement)
(@CGUID+112, 3873, 33, 1, 1, -245.9984, 2177.635, 93.93408, 1.795993, 7200, 0, 0), -- 3873 (Area: 0) (possible waypoints or random movement)
(@CGUID+113, 3877, 33, 1, 1, -251.1469, 2177.241, 93.93484, 4.538981, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+114, 47145, 33, 1, 1, -158.4944, 2177.135, 102.1777, 1.179529, 7200, 0, 0), -- 47145 (Area: 0) (possible waypoints or random movement)
(@CGUID+115, 2110, 33, 1, 1, -171.3948, 2183.017, 95.73417, 6.054548, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+116, 46963, 33, 1, 1, -141.955, 2184.03, 128.7793, 1.466077, 7200, 0, 0), -- 46963 (Area: 0) (possible waypoints or random movement)
(@CGUID+117, 4278, 33, 1, 1, -227.4983, 2257.703, 102.8365, 3.403392, 7200, 0, 0), -- 4278 (Area: 0) (possible waypoints or random movement)
(@CGUID+118, 46964, 33, 1, 1, -82.66493, 2157.446, 155.7951, 3.281219, 7200, 0, 0), -- 46964 (Area: 0) (possible waypoints or random movement)
(@CGUID+119, 3887, 33, 1, 1, -265.866, 2293.65, 76.23653, 5.899213, 7200, 0, 0), -- 3887 (Area: 0) (possible waypoints or random movement)
(@CGUID+120, 3875, 33, 1, 1, -205.6858, 2210.881, 79.76163, 4.335346, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+121, 3875, 33, 1, 1, -203.744, 2214.27, 79.75797, 5.986364, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+122, 47137, 33, 1, 1, -203.2014, 2211.637, 79.84709, 2.219436, 7200, 0, 0), -- 47137 (Area: 0) (possible waypoints or random movement)
(@CGUID+123, 47132, 33, 1, 1, -137.349, 2158.307, 94.12412, 0, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+124, 47136, 33, 1, 1, -134.7396, 2155.689, 94.12372, 1.989675, 7200, 0, 0), -- 47136 (Area: 0) (possible waypoints or random movement)
(@CGUID+125, 2110, 33, 1, 1, -158.1754, 2177.233, 102.1757, 1.226202, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+126, 47132, 33, 1, 1, -132.5395, 2158.443, 94.04028, 4.580991, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+127, 45979, 33, 1, 1, -145.467, 2172.359, 128.0363, 0, 7200, 0, 0), -- 45979 (Area: 0)
(@CGUID+128, 47132, 33, 1, 1, -130.5, 2165.382, 94.043, 2.737968, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+129, 47132, 33, 1, 1, -132.4359, 2168.933, 94.04301, 3.621696, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+130, 47136, 33, 1, 1, -119.3442, 2154.698, 101.5207, 0.7346082, 7200, 0, 0), -- 47136 (Area: 0) (possible waypoints or random movement)
(@CGUID+131, 47136, 33, 1, 1, -127.668, 2173.912, 94.04691, 5.413807, 7200, 0, 0), -- 47136 (Area: 0) (possible waypoints or random movement)
(@CGUID+132, 47132, 33, 1, 1, -111.3643, 2149.521, 101.5202, 3.389298, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+133, 47132, 33, 1, 1, -111.4049, 2154.45, 101.5202, 4.815115, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+134, 47132, 33, 1, 1, -113.8384, 2162.799, 101.5208, 4.335694, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+135, 47136, 33, 1, 1, -108.1423, 2150.79, 101.5202, 1.787061, 7200, 0, 0), -- 47136 (Area: 0) (possible waypoints or random movement)
(@CGUID+136, 47132, 33, 1, 1, -106.1061, 2150.675, 101.5202, 4.452779, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+137, 2110, 33, 1, 1, -118.5076, 2151.674, 101.5202, 3.002751, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+138, 47141, 33, 1, 1, -142.75, 2165.46, 155.7613, 0.8552113, 7200, 0, 0), -- 47141 (Area: 0) (possible waypoints or random movement)
(@CGUID+139, 47132, 33, 1, 1, -122.024, 2163.51, 138.697, 4.431886, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+140, 47132, 33, 1, 1, -122.5054, 2165.451, 138.697, 4.482479, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+141, 47146, 33, 1, 1, -141.9618, 2167.863, 155.7618, 5.183628, 7200, 0, 0), -- 47146 (Area: 0) (possible waypoints or random movement)
(@CGUID+142, 47132, 33, 1, 1, -120.1022, 2162.956, 138.697, 4.439153, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+143, 47132, 33, 1, 1, -120.5836, 2164.897, 138.697, 4.486944, 7200, 0, 0), -- 47132 (Area: 0) (possible waypoints or random movement)
(@CGUID+144, 47141, 33, 1, 1, -139.5243, 2166.899, 155.7613, 3.001966, 7200, 0, 0), -- 47141 (Area: 0) (possible waypoints or random movement)
(@CGUID+145, 3875, 33, 1, 1, -181.3802, 2233.094, 76.32468, 0.7330383, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+146, 47231, 33, 1, 1, -182.099, 2234.45, 76.32465, 0.2792527, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+147, 3875, 33, 1, 1, -176.8698, 2235.012, 76.32468, 2.86234, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+148, 47141, 33, 1, 1, -126.2917, 2168.372, 155.7618, 0.06981317, 7200, 0, 0), -- 47141 (Area: 0) (possible waypoints or random movement)
(@CGUID+149, 47231, 33, 1, 1, -177.9097, 2237.42, 76.32465, 4.13643, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+150, 47131, 33, 1, 1, -158.3407, 2233.846, 84.3741, 5.269541, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+151, 47131, 33, 1, 1, -156.411, 2233.32, 84.2351, 5.23184, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+152, 47146, 33, 1, 1, -123.4566, 2167.036, 155.7618, 3.001966, 7200, 0, 0), -- 47146 (Area: 0) (possible waypoints or random movement)
(@CGUID+153, 47146, 33, 1, 1, -124.6302, 2170.641, 155.7613, 4.171337, 7200, 0, 0), -- 47146 (Area: 0) (possible waypoints or random movement)
(@CGUID+154, 47131, 33, 1, 1, -157.4038, 2235.056, 84.55215, 5.27925, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+155, 47131, 33, 1, 1, -154.6748, 2234.313, 84.37283, 5.253146, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+156, 47131, 33, 1, 1, -155.8853, 2235.25, 84.55178, 5.272127, 7200, 0, 0), -- 47131 (Area: 0) (possible waypoints or random movement)
(@CGUID+157, 50611, 33, 1, 1, -235.5069, 2230.76, 93.62388, 0, 7200, 0, 0), -- 50611 (Area: 0)
(@CGUID+158, 2110, 33, 1, 1, -142.362, 2172.879, 155.6785, 1.201454, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+159, 2110, 33, 1, 1, -223.691, 2231.64, 79.76064, 5.667476, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+160, 3865, 33, 1, 1, -234.131, 2236.26, 79.86194, 0.296706, 7200, 0, 0), -- 3865 (Area: 0)
(@CGUID+161, 3865, 33, 1, 1, -223.612, 2245.72, 79.85824, 5.131268, 7200, 0, 0), -- 3865 (Area: 0)
(@CGUID+162, 3873, 33, 1, 1, -258.3246, 2241.748, 100.9767, 0.5759587, 7200, 0, 0), -- 3873 (Area: 0) (possible waypoints or random movement)
(@CGUID+163, 2110, 33, 1, 1, -259.3185, 2240.891, 100.8919, 3.322818, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+164, 3877, 33, 1, 1, -255.8385, 2244.964, 100.9758, 4.24115, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+165, 3873, 33, 1, 1, -258.7917, 2244.51, 100.9768, 5.986479, 7200, 0, 0), -- 3873 (Area: 0) (possible waypoints or random movement)
(@CGUID+166, 47030, 33, 1, 1, -240.047, 2143.16, 87.09624, 4.45059, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+167, 23837, 33, 1, 1, -245.837, 2149.73, 90.58404, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+168, 47293, 33, 1, 1, -240.5535, 2130.556, 87.04115, 4.047379, 7200, 0, 0), -- 47293 (Area: 0) (possible waypoints or random movement)
(@CGUID+169, 23837, 33, 1, 1, -244.672, 2149.47, 90.51843, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+170, 23837, 33, 1, 1, -241.332, 2148.02, 90.70734, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+171, 23837, 33, 1, 1, -242.214, 2149.84, 90.70734, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+172, 23837, 33, 1, 1, -240.747, 2149.55, 90.70734, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+173, 23837, 33, 1, 1, -239.46, 2127.16, 87.09354, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+174, 23837, 33, 1, 1, -240.908, 2150.54, 90.70734, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+175, 23837, 33, 1, 1, -238.49, 2127.21, 86.99274, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+176, 47030, 33, 1, 1, -233.597, 2140.91, 87.09624, 4.39823, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+177, 47030, 33, 1, 1, -237.592, 2150.78, 90.70734, 4.555309, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+178, 47030, 33, 1, 1, -233.04, 2149.04, 90.70734, 4.34587, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+179, 47031, 33, 1, 1, -220.705, 2140.32, 90.70734, 2.75762, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+180, 47031, 33, 1, 1, -218.477, 2146.08, 90.70734, 2.897247, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+181, 23837, 33, 1, 1, -211.467, 2145.36, 90.60223, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+182, 23837, 33, 1, 1, -210.578, 2127.44, 86.58394, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+183, 23837, 33, 1, 1, -209.547, 2127.47, 86.58434, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+184, 23837, 33, 1, 1, -209.188, 2128.17, 86.58434, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+185, 23837, 33, 1, 1, -195.33, 2139.63, 81.65154, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+186, 23837, 33, 1, 1, -194.257, 2139.17, 81.76923, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+187, 23837, 33, 1, 1, -193.042, 2138.81, 81.67624, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+188, 23837, 33, 1, 1, -193.012, 2137.23, 81.58414, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+189, 23837, 33, 1, 1, -192.332, 2138.53, 81.58394, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+190, 23837, 33, 1, 1, -198.984, 2109.59, 81.20223, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+191, 23837, 33, 1, 1, -198.033, 2110.79, 81.14014, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+192, 23837, 33, 1, 1, -191.642, 2125.76, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+193, 23837, 33, 1, 1, -196.424, 2111.61, 81.14014, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+194, 23837, 33, 1, 1, -190.896, 2127.02, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+195, 23837, 33, 1, 1, -197.415, 2109.11, 81.14014, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+196, 23837, 33, 1, 1, -191.422, 2124.09, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+197, 23837, 33, 1, 1, -196.08, 2110.17, 81.14014, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+198, 23837, 33, 1, 1, -189.793, 2125.31, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+199, 23837, 33, 1, 1, -189.962, 2124.26, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+200, 23837, 33, 1, 1, -195.901, 2108.78, 81.14014, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+201, 23837, 33, 1, 1, -189.167, 2125.87, 81.58504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+202, 23837, 33, 1, 1, -187.273, 2140.47, 83.16393, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+203, 3864, 33, 1, 1, -217.135, 2247.13, 79.85793, 4.886922, 7200, 0, 0), -- 3864 (Area: 0)
(@CGUID+204, 3877, 33, 1, 1, -245.1667, 2250.752, 100.9768, 1.605703, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+205, 3877, 33, 1, 1, -243.6129, 2252.712, 100.9759, 3.490659, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+206, 50613, 33, 1, 1, -228.3299, 2254.389, 102.8397, 3.368485, 7200, 0, 0), -- 50613 (Area: 0) (possible waypoints or random movement)
(@CGUID+207, 3873, 33, 1, 1, -245.9549, 2252.981, 100.9768, 5.497787, 7200, 0, 0), -- 3873 (Area: 0) (possible waypoints or random movement)
(@CGUID+208, 50615, 33, 1, 1, -229.6806, 2260.028, 102.8397, 3.455752, 7200, 0, 0), -- 50615 (Area: 0) (possible waypoints or random movement)
(@CGUID+209, 47232, 33, 1, 1, -203.4063, 2252.238, 76.28465, 5.969026, 7200, 0, 0), -- 47232 (Area: 0) (possible waypoints or random movement)
(@CGUID+210, 47232, 33, 1, 1, -207.3333, 2255.99, 76.28464, 4.118977, 7200, 0, 0), -- 47232 (Area: 0) (possible waypoints or random movement)
(@CGUID+211, 47232, 33, 1, 1, -204.8229, 2263.641, 76.28464, 1.37881, 7200, 0, 0), -- 47232 (Area: 0) (possible waypoints or random movement)
(@CGUID+212, 3875, 33, 1, 1, -200.9025, 2258.298, 76.2013, 5.836795, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+213, 2110, 33, 1, 1, -221.328, 2267.01, 74.99934, 5.883448, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+214, 3875, 33, 1, 1, -183.2928, 2259.838, 89.47455, 5.81283, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+215, 47232, 33, 1, 1, -195.726, 2265.19, 76.2013, 5.270895, 7200, 0, 0), -- 47232 (Area: 0) (possible waypoints or random movement)
(@CGUID+216, 50611, 33, 1, 1, -266.2257, 2270.207, 96.43494, 0, 7200, 0, 0), -- 50611 (Area: 0)
(@CGUID+217, 2110, 33, 1, 1, -229.703, 2280.27, 70.54643, 2.495821, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+218, 3875, 33, 1, 1, -251.8038, 2279.936, 75.08268, 0.2792527, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+219, 47231, 33, 1, 1, -246.1111, 2281.526, 75.08268, 3.857178, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+220, 3875, 33, 1, 1, -248.6667, 2279.146, 75.08268, 1.762783, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+221, 47231, 33, 1, 1, -249.526, 2282.563, 75.08268, 5.410521, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+222, 47143, 33, 1, 1, -268.595, 2271.635, 95.86646, 5.903875, 7200, 0, 0), -- 47143 (Area: 0) (possible waypoints or random movement)
(@CGUID+223, 47231, 33, 1, 1, -229.2872, 2286.404, 74.99934, 5.877216, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+224, 47143, 33, 1, 1, -213.0599, 2298.631, 95.87661, 5.895688, 7200, 0, 0), -- 47143 (Area: 0) (possible waypoints or random movement)
(@CGUID+225, 3877, 33, 1, 1, -222.5799, 2303.693, 94.75989, 3.036873, 7200, 0, 0), -- 3877 (Area: 0)
(@CGUID+226, 47231, 33, 1, 1, -227.5365, 2304.434, 94.75989, 6.091199, 7200, 0, 0), -- 47231 (Area: 0)
(@CGUID+227, 3877, 33, 1, 1, -225.3802, 2301.677, 94.75989, 1.099557, 7200, 0, 0), -- 3877 (Area: 0)
(@CGUID+228, 3875, 33, 1, 1, -224.6163, 2307.066, 94.75989, 4.520403, 7200, 0, 0), -- 3875 (Area: 0)
(@CGUID+229, 2110, 33, 1, 1, -201.7439, 2288.424, 95.899, 4.88339, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+230, 3877, 33, 1, 1, -258.8559, 2314.278, 95.94983, 5.742133, 7200, 0, 0), -- 3877 (Area: 0)
(@CGUID+231, 47231, 33, 1, 1, -253.8854, 2317.292, 96.09058, 3.630285, 7200, 0, 0), -- 47231 (Area: 0)
(@CGUID+232, 3877, 33, 1, 1, -255.816, 2312.448, 95.94983, 1.605703, 7200, 0, 0), -- 3877 (Area: 0)
(@CGUID+233, 3875, 33, 1, 1, -255.8264, 2319.333, 96.80138, 4.520403, 7200, 0, 0), -- 3875 (Area: 0)
(@CGUID+234, 47143, 33, 1, 1, -251.1512, 2313.644, 95.86648, 5.913985, 7200, 0, 0), -- 47143 (Area: 0) (possible waypoints or random movement)
(@CGUID+235, 47231, 33, 1, 1, -306.1111, 2282.854, 95.94981, 6.091199, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+236, 3877, 33, 1, 1, -303.2708, 2284.983, 95.94981, 4.520403, 7200, 0, 0), -- 3877 (Area: 0) (possible waypoints or random movement)
(@CGUID+237, 47231, 33, 1, 1, -301.0417, 2282.859, 95.94981, 3.036873, 7200, 0, 0), -- 47231 (Area: 0) (possible waypoints or random movement)
(@CGUID+238, 3875, 33, 1, 1, -303.6754, 2281.186, 95.94982, 1.937315, 7200, 0, 0), -- 3875 (Area: 0) (possible waypoints or random movement)
(@CGUID+239, 47293, 33, 1, 1, -260.385, 2290.04, 75.08263, 2.775074, 7200, 0, 0), -- 47293 (Area: 0)
(@CGUID+240, 47031, 33, 1, 1, -223.637, 2275.91, 77.13573, 5.585053, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+241, 23837, 33, 1, 1, -221.891, 2273.96, 77.13573, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+242, 23837, 33, 1, 1, -221.995, 2272.82, 77.13573, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+243, 47031, 33, 1, 1, -217.88, 2285.48, 77.13573, 1.448623, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+244, 23837, 33, 1, 1, -217.625, 2287.2, 76.94003, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+245, 23837, 33, 1, 1, -217.373, 2278.09, 77.13573, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+246, 23837, 33, 1, 1, -216.3368, 2286.54, 77.03741, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+247, 23837, 33, 1, 1, -214.177, 2259.62, 83.15204, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+248, 23837, 33, 1, 1, -204.274, 2271.15, 77.01453, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+249, 23837, 33, 1, 1, -203.703, 2271.25, 76.86504, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+250, 23837, 33, 1, 1, -203.359, 2271.83, 76.76674, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+251, 23837, 33, 1, 1, -203.111, 2272.61, 77.20544, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+252, 23837, 33, 1, 1, -203.488, 2271.35, 78.61384, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+253, 23837, 33, 1, 1, -203.132, 2270.7, 77.15324, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+254, 23837, 33, 1, 1, -202.703, 2272.38, 78.76473, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+255, 23837, 33, 1, 1, -202.156, 2273.49, 78.73904, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+256, 47030, 33, 1, 1, -287.7312, 2299.908, 89.64044, 4.768981, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+257, 47030, 33, 1, 1, -285.8244, 2304.515, 89.64634, 0.6435287, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+258, 47030, 33, 1, 1, -288.9552, 2300.522, 89.72758, 4.921014, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+259, 47030, 33, 1, 1, -287.1191, 2305.041, 89.74182, 0.5727214, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+260, 23837, 33, 1, 1, -194.944, 2263.74, 76.28464, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+261, 23837, 33, 1, 1, -202.627, 2250.4, 76.28464, 2.897247, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+262, 23837, 33, 1, 1, -194.781, 2263.11, 76.28464, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+263, 23837, 33, 1, 1, -202.089, 2249.86, 76.28464, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+264, 23837, 33, 1, 1, -201.847, 2248.88, 76.28464, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+265, 23837, 33, 1, 1, -199.908, 2230.16, 81.84364, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+266, 23837, 33, 1, 1, -198.583, 2229.32, 82.26794, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+267, 23837, 33, 1, 1, -197.302, 2228.6, 82.07034, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+268, 23837, 33, 1, 1, -181.095, 2245.94, 76.26663, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+269, 23837, 33, 1, 1, -180.616, 2244.9, 76.29803, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+270, 23837, 33, 1, 1, -180.087, 2243.93, 76.43644, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+271, 23837, 33, 1, 1, -226.009, 2206.58, 79.79234, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+272, 23837, 33, 1, 1, -226.057, 2205.81, 79.76114, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+273, 23837, 33, 1, 1, -226.271, 2204.88, 80.11623, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+274, 23837, 33, 1, 1, -175.674, 2228.62, 76.18094, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+275, 23837, 33, 1, 1, -192.259, 2205.29, 79.84174, 2.70526, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+276, 23837, 33, 1, 1, -213.503, 2193.08, 79.84804, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+277, 23837, 33, 1, 1, -214.997, 2192.38, 79.84834, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+278, 23837, 33, 1, 1, -213.41, 2192.32, 79.84804, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+279, 23837, 33, 1, 1, -213.297, 2192.14, 82.56724, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+280, 23837, 33, 1, 1, -214.839, 2191.37, 79.84834, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+281, 23837, 33, 1, 1, -212.054, 2192.07, 79.84814, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+282, 23837, 33, 1, 1, -177.997, 2212.55, 80.18803, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+283, 23837, 33, 1, 1, -212.493, 2191.66, 79.84814, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+284, 23837, 33, 1, 1, -215.231, 2190.72, 79.84843, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+285, 23837, 33, 1, 1, -213.929, 2191.35, 83.98174, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+286, 23837, 33, 1, 1, -213.632, 2191.24, 81.98494, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+287, 23837, 33, 1, 1, -213.165, 2191.37, 82.32024, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+288, 23837, 33, 1, 1, -213.875, 2190.87, 82.37473, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+289, 23837, 33, 1, 1, -213.594, 2191.03, 84.28364, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+290, 23837, 33, 1, 1, -177.424, 2211.92, 80.33204, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+291, 23837, 33, 1, 1, -214.299, 2190.41, 82.36844, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+292, 23837, 33, 1, 1, -214.444, 2190.19, 79.84834, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+293, 23837, 33, 1, 1, -212.069, 2190.69, 79.84834, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+294, 23837, 33, 1, 1, -212.434, 2190.51, 79.84834, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+295, 23837, 33, 1, 1, -176.701, 2211.61, 79.95013, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+296, 23837, 33, 1, 1, -213.547, 2189.75, 79.84843, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+297, 23837, 33, 1, 1, -175.649, 2212.22, 80.07214, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+298, 23837, 33, 1, 1, -174.637, 2212.59, 80.13503, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+299, 47294, 33, 1, 1, -269.828, 2293.46, 77.56844, 5.951573, 7200, 0, 0), -- 47294 (Area: 0)
(@CGUID+300, 47293, 33, 1, 1, -264.7126, 2269.896, 97.17555, 5.929502, 7200, 0, 0), -- 47293 (Area: 0) (possible waypoints or random movement)
(@CGUID+301, 23837, 33, 1, 1, -241.826, 2271.71, 87.31614, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+302, 23837, 33, 1, 1, -240.578, 2271.34, 87.07004, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+303, 23837, 33, 1, 1, -239.625, 2270.98, 87.19463, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+304, 23837, 33, 1, 1, -238.694, 2270.53, 87.15884, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+305, 23837, 33, 1, 1, -237.788, 2270.23, 87.21204, 1.186824, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+306, 23837, 33, 1, 1, -241.849, 2271.91, 85.65854, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+307, 23837, 33, 1, 1, -240.568, 2271.45, 85.53744, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+308, 23837, 33, 1, 1, -239.658, 2271.03, 85.75993, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+309, 23837, 33, 1, 1, -238.689, 2270.63, 85.55144, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+310, 23837, 33, 1, 1, -237.793, 2270.24, 85.63374, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+311, 23837, 33, 1, 1, -241.913, 2271.82, 83.70203, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+312, 23837, 33, 1, 1, -240.677, 2271.35, 83.54284, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+313, 23837, 33, 1, 1, -239.707, 2270.96, 83.63573, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+314, 23837, 33, 1, 1, -238.752, 2270.49, 83.55624, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+315, 23837, 33, 1, 1, -237.79, 2270.2, 83.57374, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+316, 23837, 33, 1, 1, -241.851, 2271.97, 82.00774, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+317, 23837, 33, 1, 1, -239.606, 2271.08, 81.91404, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+318, 23837, 33, 1, 1, -238.691, 2270.7, 81.82224, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+319, 23837, 33, 1, 1, -237.762, 2270.24, 81.89844, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+320, 23837, 33, 1, 1, -241.872, 2271.81, 80.15474, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+321, 23837, 33, 1, 1, -240.606, 2271.42, 79.42104, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+322, 23837, 33, 1, 1, -239.642, 2271.03, 79.38973, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+323, 23837, 33, 1, 1, -238.745, 2270.58, 79.31924, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+324, 23837, 33, 1, 1, -237.74, 2270.33, 79.46603, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+325, 23837, 33, 1, 1, -240.549, 2284.13, 76.39734, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+326, 23837, 33, 1, 1, -241.783, 2284.6, 76.40653, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+327, 23837, 33, 1, 1, -234.957, 2281.38, 76.41393, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+328, 23837, 33, 1, 1, -256.679, 2290.18, 76.35844, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+329, 23837, 33, 1, 1, -235.42, 2292.5, 75.16534, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+330, 23837, 33, 1, 1, -237.962, 2293.74, 75.38184, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+331, 23837, 33, 1, 1, -237.253, 2293.27, 75.01884, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+332, 23837, 33, 1, 1, -238.398, 2293.67, 74.87874, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+333, 23837, 33, 1, 1, -278.142, 2292.59, 76.36253, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+334, 23837, 33, 1, 1, -278.066, 2293.6, 76.22614, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+335, 23837, 33, 1, 1, -277.2, 2294.35, 76.47643, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+336, 23837, 33, 1, 1, -275.306, 2300.97, 76.03973, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+337, 23837, 33, 1, 1, -272.161, 2302.71, 76.23653, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+338, 23837, 33, 1, 1, -274.693, 2301.93, 76.17313, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+339, 23837, 33, 1, 1, -273.075, 2303.02, 76.08714, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+340, 23837, 33, 1, 1, -273.957, 2302.89, 76.30494, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+341, 47294, 33, 1, 1, -137.918, 2169.69, 136.6613, 2.775074, 7200, 0, 0), -- 47294 (Area: 0) (possible waypoints or random movement)
(@CGUID+342, 23837, 33, 1, 1, -199.486, 2159.17, 79.84794, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+343, 2110, 33, 1, 1, -240.7104, 2138.737, 87.01289, 4.263064, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+344, 2110, 33, 1, 1, -199.1043, 2144.186, 86.49985, 0.8422055, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+345, 47030, 33, 1, 1, -136.833, 2161.72, 138.7803, 2.059489, 7200, 0, 0), -- 47030 (Area: 0) (possible waypoints or random movement)
(@CGUID+346, 47030, 33, 1, 1, -134.288, 2164.36, 138.7803, 2.373648, 7200, 0, 0), -- 47030 (Area: 0) (possible waypoints or random movement)
(@CGUID+347, 47031, 33, 1, 1, -132.72, 2166.21, 138.7803, 2.80998, 7200, 0, 0), -- 47031 (Area: 0) (possible waypoints or random movement)
(@CGUID+348, 47031, 33, 1, 1, -131.734, 2167.9, 138.7803, 2.80998, 7200, 0, 0), -- 47031 (Area: 0) (possible waypoints or random movement)
(@CGUID+349, 47030, 33, 1, 1, -131.498, 2170.57, 138.7803, 3.124139, 7200, 0, 0), -- 47030 (Area: 0) (possible waypoints or random movement)
(@CGUID+350, 47030, 33, 1, 1, -131.438, 2174.3, 138.7803, 3.473205, 7200, 0, 0), -- 47030 (Area: 0) (possible waypoints or random movement)
(@CGUID+351, 47138, 33, 1, 1, -98.87782, 2135.14, 144.9209, 4.793252, 7200, 0, 0), -- 47138 (Area: 0) (possible waypoints or random movement)
(@CGUID+352, 2110, 33, 1, 1, -210.487, 2262.43, 76.2013, 2.741846, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+353, 23837, 33, 1, 1, -121.74, 2152.12, 101.6023, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+354, 23837, 33, 1, 1, -114.059, 2149.79, 101.6033, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+355, 23837, 33, 1, 1, -132.089, 2184.87, 113.2153, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+356, 23837, 33, 1, 1, -132.151, 2185.77, 113.2153, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+357, 23837, 33, 1, 1, -131.191, 2183.35, 113.2153, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+358, 23837, 33, 1, 1, -153.753, 2172.67, 99.59763, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+359, 23837, 33, 1, 1, -126.002, 2174.99, 94.13094, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+360, 23837, 33, 1, 1, -126.72, 2177, 94.13013, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+361, 23837, 33, 1, 1, -131.606, 2179.23, 94.12674, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+362, 23837, 33, 1, 1, -133.547, 2178.24, 94.83314, 4.991642, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+363, 23837, 33, 1, 1, -170.438, 2182.84, 94.94584, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+364, 23837, 33, 1, 1, -190.245, 2119.68, 97.36363, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+365, 23837, 33, 1, 1, -190.63, 2118.51, 97.27174, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+366, 23837, 33, 1, 1, -191.156, 2117.4, 97.08774, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+367, 23837, 33, 1, 1, -191.729, 2116.32, 97.06424, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+368, 47293, 33, 1, 1, -171.7906, 2180.634, 129.2917, 1.069335, 7200, 0, 0), -- 47293 (Area: 0) (possible waypoints or random movement)
(@CGUID+369, 23837, 33, 1, 1, -177.8, 2254.03, 86.64744, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+370, 23837, 33, 1, 1, -179.493, 2254.72, 86.79384, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+371, 23837, 33, 1, 1, -167.948, 2227.94, 79.81364, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+372, 23837, 33, 1, 1, -131.578, 2155.47, 94.12394, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+373, 23837, 33, 1, 1, -184.908, 2191.11, 114.0683, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+374, 23837, 33, 1, 1, -111.708, 2170.45, 101.6033, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+375, 23837, 33, 1, 1, -235.347, 2144.11, 100.1123, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+376, 23837, 33, 1, 1, -236.405, 2210.15, 97.58244, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+377, 23837, 33, 1, 1, -236.884, 2208.89, 97.25004, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+378, 47030, 33, 1, 1, -91.5174, 2148.32, 145.0043, 0, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+379, 47294, 33, 1, 1, -110.026, 2158.99, 155.7623, 6.178465, 7200, 0, 0), -- 47294 (Area: 0)
(@CGUID+380, 47031, 33, 1, 1, -87.6441, 2126.23, 145.0043, 2.443461, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+381, 47031, 33, 1, 1, -102.142, 2123.2, 155.7383, 5.864306, 7200, 0, 0), -- 47031 (Area: 0)
(@CGUID+382, 47030, 33, 1, 1, -111.995, 2133.53, 145.0043, 1.692969, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+383, 47030, 33, 1, 1, -75.3976, 2143.99, 155.6093, 3.577925, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+384, 47030, 33, 1, 1, -94.2517, 2138.56, 145.0043, 5.148721, 7200, 0, 0), -- 47030 (Area: 0)
(@CGUID+385, 2110, 33, 1, 1, -226.5356, 2249.337, 102.7583, 3.905907, 7200, 0, 0), -- 2110 (Area: 0)
(@CGUID+386, 23837, 33, 1, 1, -225.432, 2257.02, 102.8393, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+387, 23837, 33, 1, 1, -245.3229, 2189.37, 93.61277, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+388, 23837, 33, 1, 1, -246.519, 2188.93, 93.84444, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+389, 23837, 33, 1, 1, -246.54, 2190.07, 93.90604, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+390, 23837, 33, 1, 1, -247.786, 2189.25, 93.80784, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+391, 23837, 33, 1, 1, -248.462, 2188.46, 93.82413, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+392, 23837, 33, 1, 1, -238.844, 2245.65, 101.0493, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+393, 23837, 33, 1, 1, -239.667, 2245.22, 101.0163, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+394, 23837, 33, 1, 1, -255.774, 2169.76, 94.06554, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+395, 23837, 33, 1, 1, -256.259, 2168.7, 93.98884, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+396, 23837, 33, 1, 1, -256.59, 2167.6, 94.15224, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+397, 23837, 33, 1, 1, -257.156, 2166.52, 94.15434, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+398, 23837, 33, 1, 1, -241.432, 2127.75, 100.5973, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+399, 23837, 33, 1, 1, -245.323, 2128.09, 100.1123, 4.206244, 7200, 0, 0), -- 23837 (Area: 0)
(@CGUID+400, 47293, 33, 1, 1, -168.978, 2185.792, 151.9715, 4.799315, 7200, 0, 0), -- 47293 (Area: 0) (possible waypoints or random movement)
(@CGUID+401, 2110, 33, 1, 1, -111.3225, 2169.932, 101.577, 3.346581, 7200, 0, 0); -- 2110 (Area: 0)

DELETE FROM `gossip_menu` WHERE (`entry`=12258 AND `text_id`=17219);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12258, 17219); -- 47293

REPLACE INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(47030, 18167, 18166, 0), -- 47030
(47293, 57195, 57195, 0), -- 47293
(51400, 62484, 0, 0), -- 51400
(47031, 0, 0, 49711), -- 47031
(3877, 3432, 0, 0), -- 3877
(3873, 2147, 2052, 0), -- 3873
(47145, 49341, 56175, 0), -- 47145
(4278, 41343, 25818, 0), -- 4278
(3887, 11264, 0, 0), -- 3887
(47146, 57016, 57016, 0), -- 47146
(50613, 3432, 0, 0), -- 50613
(50615, 2147, 2052, 0), -- 50615
(47232, 2029, 0, 0), -- 47232
(47232, 2196, 0, 0), -- 47232
(47143, 43967, 0, 0), -- 47143
(47294, 47031, 0, 0), -- 47294
(3296, 5289, 0, 2507), -- 3296
(15116, 12850, 0, 0), -- 15116
(49750, 1906, 0, 0), -- 49750
(3370, 5303, 0, 0), -- 3370
(44874, 5289, 0, 5260), -- 44874
(6929, 6334, 0, 0), -- 6929
(14392, 18419, 0, 0), -- 14392
(3342, 12329, 0, 0), -- 3342
(44878, 5289, 0, 5260), -- 44878
(44851, 3346, 0, 0), -- 44851
(5609, 2703, 0, 0), -- 5609
(5817, 1910, 0, 0), -- 5817
(27815, 33161, 0, 0), -- 27815
(5606, 2703, 0, 0), -- 5606
(3313, 12850, 12745, 0), -- 3313
(5613, 2703, 0, 0), -- 5613
(6466, 63252, 0, 0), -- 6466
(44876, 5289, 0, 5260), -- 44876
(44877, 5289, 0, 5260), -- 44877
(5614, 2716, 0, 0), -- 5614
(5597, 2704, 0, 0), -- 5597
(5610, 2703, 0, 0), -- 5610
(5603, 5287, 0, 0), -- 5603
(5188, 5284, 0, 0), -- 5188
(5611, 0, 0, 2551), -- 5611
(44871, 5289, 0, 5260), -- 44871
(44872, 5289, 0, 5260), -- 44872
(3296, 0, 0, 2507), -- 3296
(3312, 2827, 2196, 2551), -- 3312
(49622, 1908, 0, 0), -- 49622
(4047, 5304, 0, 0), -- 4047
(3144, 10612, 0, 0), -- 3144
(46142, 5286, 0, 2551), -- 46142
(45339, 13709, 0, 0), -- 45339
(16012, 14824, 0, 0), -- 16012
(23128, 29403, 27406, 0), -- 23128
(45337, 12421, 0, 0), -- 45337
(51307, 5292, 0, 0), -- 51307
(46556, 49671, 49671, 0), -- 46556
(46555, 17383, 0, 0), -- 46555
(58155, 17462, 0, 0), -- 58155
(39605, 30414, 0, 0); -- 39605
