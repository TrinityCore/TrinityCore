-- Pathing for  Entry: 47131 'TDB FORMAT' 
-- SET @NPC := 370929;
SET @NPC := 370931;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-224.573,`position_y`=2147.43,`position_z`=90.74601 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-224.573,2147.43,90.74601,0,0,1,0,100,0),
(@PATH,2,-213.948,2142.21,90.73151,0,0,1,0,100,0),
(@PATH,3,-232.9186,2149.677,90.48258,0,0,1,0,100,0),
(@PATH,4,-234.502,2148.04,90.3751,0,0,1,0,100,0),
(@PATH,5,-242.231,2141.31,87.3315,0,0,1,0,100,0),
(@PATH,6,-250.325,2140.73,86.25217,0,0,1,0,100,0),
(@PATH,7,-253.79,2128.93,81.3315,0,0,1,0,100,0),
(@PATH,8,-245.76,2142.74,87.17836,0,0,1,0,100,0),
(@PATH,9,-242.231,2141.31,87.3315,0,0,1,0,100,0),
(@PATH,10,-234.502,2148.04,90.3751,0,0,1,0,100,0);
-- 0x20309404202E06C000717400004B9BCD .go xyz -224.573 2147.43 90.74601

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370938;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-242.825,`position_y`=2155.08,`position_z`=90.73151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-242.825,2155.08,90.73151,0,0,1,0,100,0),
(@PATH,2,-241.351,2135.02,87.17239,0,0,1,0,100,0),
(@PATH,3,-238.4806,2142.995,87.1442,0,0,1,0,100,0),
(@PATH,4,-248.4996,2114.142,87.17899,0,0,1,0,100,0),
(@PATH,5,-241.351,2135.02,87.17239,0,0,1,0,100,0),
(@PATH,6,-236.75,2146.47,89.28158,0,0,1,0,100,0),
(@PATH,7,-242.825,2155.08,90.73151,0,0,1,0,100,0),
(@PATH,8,-241.351,2135.02,87.17239,0,0,1,0,100,0),
(@PATH,9,-245.734,2122.86,87.13149,0,0,1,0,100,0),
(@PATH,10,-248.4996,2114.142,87.17899,0,0,1,0,100,0),
(@PATH,11,-241.351,2135.02,87.17239,0,0,1,0,100,0);
-- 0x20309404202E06C00071740000CB9BCD .go xyz -242.825 2155.08 90.73151

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370955;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-219.319,`position_y`=2141.33,`position_z`=90.73151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-219.319,2141.33,90.73151,0,0,1,0,100,0),
(@PATH,2,-209.226,2138.93,90.73151,0,0,1,0,100,0),
(@PATH,3,-218.231,2146.49,90.73151,0,0,1,0,100,0),
(@PATH,4,-234.7934,2153.074,90.68277,0,0,1,0,100,0),
(@PATH,5,-241.405,2155.63,90.73151,0,0,1,0,100,0),
(@PATH,6,-234.7934,2153.074,90.68277,0,0,1,0,100,0),
(@PATH,7,-219.319,2141.33,90.73151,0,0,1,0,100,0),
(@PATH,8,-211.979,2137.72,90.73151,0,0,1,0,100,0),
(@PATH,9,-214.542,2145.04,90.73151,0,0,1,0,100,0),
(@PATH,10,-225.483,2149.2,90.73151,0,0,1,0,100,0),
(@PATH,11,-234.7934,2153.074,90.68277,0,0,1,0,100,0),
(@PATH,12,-236.892,2151.64,90.60165,0,0,1,0,100,0),
(@PATH,13,-228.297,2147.62,90.73151,0,0,1,0,100,0),
(@PATH,14,-219.319,2141.33,90.73151,0,0,1,0,100,0),
(@PATH,15,-208.745,2140.91,90.7315,0,0,1,0,100,0),
(@PATH,16,-218.231,2146.49,90.73151,0,0,1,0,100,0),
(@PATH,17,-234.7934,2153.074,90.68277,0,0,1,0,100,0),
(@PATH,18,-225.0756,2149.048,90.73151,0,0,1,0,100,0),
(@PATH,19,-228.297,2147.62,90.73151,0,0,1,0,100,0);
-- 0x20309404202E06C000717400014B9BCD .go xyz -219.319 2141.33 90.73151

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370923;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-202.503,`position_y`=2137.75,`position_z`=86.5315 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-205.106,2132.89,86.53151,0,0,1,0,100,0),
(@PATH,2,-193.102,2142.48,85.03326,0,0,1,0,100,0),
(@PATH,3,-191.53,2132.7,81.53151,0,0,1,0,100,0),
(@PATH,4,-194.691,2127.82,81.53151,0,0,1,0,100,0),
(@PATH,5,-205.257,2116.96,81.1315,0,0,1,0,100,0),
(@PATH,6,-191.53,2132.7,81.53151,0,0,1,0,100,0),
(@PATH,7,-191.17,2141.42,83.99815,0,0,1,0,100,0),
(@PATH,8,-200.236,2141.76,86.53151,0,0,1,0,100,0),
(@PATH,9,-205.106,2132.89,86.53151,0,0,1,0,100,0),
(@PATH,10,-193.102,2142.48,85.03326,0,0,1,0,100,0),
(@PATH,11,-191.17,2141.42,83.99815,0,0,1,0,100,0),
(@PATH,12,-194.691,2127.82,81.53151,0,0,1,0,100,0),
(@PATH,13,-202.049,2120.02,81.30997,0,0,1,0,100,0),
(@PATH,14,-205.257,2116.96,81.1315,0,0,1,0,100,0),
(@PATH,15,-191.53,2132.7,81.53151,0,0,1,0,100,0),
(@PATH,16,-189.4205,2139.011,83.39886,0,0,1,0,100,0),
(@PATH,17,-196.962,2144.57,86.53151,0,0,1,0,100,0);
-- 0x20309404202E06C00071740001CB9BCD .go xyz -202.503 2137.75 86.5315

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-234.826,`position_y`=2134.83,`position_z`=87.1315 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-234.826,2134.83,87.1315,0,0,1,0,100,0),
(@PATH,2,-235.071,2121.86,87.1315,0,0,1,0,100,0),
(@PATH,3,-241.924,2114.7,87.21809,0,0,1,0,100,0),
(@PATH,4,-239.7693,2124.258,87.25138,0,0,1,0,100,0),
(@PATH,5,-236.122,2134.18,87.1315,0,0,1,0,100,0),
(@PATH,6,-243.188,2142.16,87.30859,0,0,1,0,100,0),
(@PATH,7,-252.45,2136.43,83.97578,0,0,1,0,100,0),
(@PATH,8,-249.384,2143.36,87.1315,0,0,1,0,100,0),
(@PATH,9,-246.487,2136.175,81.3315,0,0,1,0,100,0),
(@PATH,10,-249.861,2129.61,81.3315,0,0,1,0,100,0),
(@PATH,11,-252.168,2136.66,84.14391,0,0,1,0,100,0),
(@PATH,12,-247.872,2144.34,87.1315,0,0,1,0,100,0),
(@PATH,13,-236.276,2137.76,87.13151,0,0,1,0,100,0),
(@PATH,14,-235.071,2121.86,87.1315,0,0,1,0,100,0),
(@PATH,15,-237.786,2116.24,87.18414,0,0,1,0,100,0),
(@PATH,16,-243.507,2121.98,87.13967,0,0,1,0,100,0),
(@PATH,17,-236.122,2134.18,87.1315,0,0,1,0,100,0),
(@PATH,18,-243.188,2142.16,87.30859,0,0,1,0,100,0),
(@PATH,19,-250.8594,2140.252,85.88985,0,0,1,0,100,0),
(@PATH,20,-254.615,2131.19,81.4307,0,0,1,0,100,0),
(@PATH,21,-247.569,2132.49,81.3315,0,0,1,0,100,0),
(@PATH,22,-247.911,2134.33,81.3315,0,0,1,0,100,0),
(@PATH,23,-253.599,2133.66,82.34867,0,0,1,0,100,0),
(@PATH,24,-249.236,2143.11,87.1315,0,0,1,0,100,0),
(@PATH,25,-252.168,2136.66,84.14391,0,0,1,0,100,0),
(@PATH,26,-233.776,2128.49,87.1315,0,0,1,0,100,0),
(@PATH,27,-237.786,2116.24,87.18414,0,0,1,0,100,0),
(@PATH,28,-246.085,2117.8,87.1315,0,0,1,0,100,0),
(@PATH,29,-236.597,2127.02,87.1315,0,0,1,0,100,0),
(@PATH,30,-237.906,2138.05,87.13151,0,0,1,0,100,0),
(@PATH,31,-245.997,2143.29,87.1315,0,0,1,0,100,0),
(@PATH,32,-241.4279,2140.79,87.30955,0,0,1,0,100,0),
(@PATH,33,-251.3684,2127.315,81.33147,0,0,1,0,100,0),
(@PATH,34,-246.38,2138.16,81.3315,0,0,1,0,100,0),
(@PATH,35,-251.691,2128.05,81.33734,0,0,1,0,100,0),
(@PATH,36,-250.616,2139.75,85.75424,0,0,1,0,100,0),
(@PATH,37,-244.495,2143.15,87.16512,0,0,1,0,100,0);
-- 0x20309404202E06C000717400024B9BCD .go xyz -234.826 2134.83 87.1315

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370951;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-189.0459,`position_y`=2139.051,`position_z`=83.33153 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-189.0459,2139.051,83.33153,0,0,1,0,100,0),
(@PATH,2,-190.082,2141.37,83.45259,0,0,1,0,100,0),
(@PATH,3,-192.554,2142.34,84.80293,0,0,1,0,100,0),
(@PATH,4,-197.09,2144.55,86.53151,0,0,1,0,100,0),
(@PATH,5,-201.238,2146.09,87.6928,0,0,1,0,100,0),
(@PATH,6,-204.189,2146.04,89.06788,0,0,1,0,100,0),
(@PATH,7,-206.266,2143.87,90.47363,0,0,1,0,100,0),
(@PATH,8,-208.747,2141.62,90.7315,0,0,1,0,100,0),
(@PATH,9,-217.774,2143.43,90.73151,0,0,1,0,100,0),
(@PATH,10,-222.365,2145.58,90.79582,0,0,1,0,100,0),
(@PATH,11,-233.3,2151.05,90.81931,0,0,1,0,100,0),
(@PATH,12,-241.712,2154.96,90.73151,0,0,1,0,100,0),
(@PATH,13,-233.3,2151.05,90.81931,0,0,1,0,100,0),
(@PATH,14,-222.365,2145.58,90.79582,0,0,1,0,100,0),
(@PATH,15,-217.774,2143.43,90.73151,0,0,1,0,100,0),
(@PATH,16,-211.326,2141.1,90.73151,0,0,1,0,100,0),
(@PATH,17,-208.747,2141.62,90.7315,0,0,1,0,100,0),
(@PATH,18,-206.266,2143.87,90.47363,0,0,1,0,100,0),
(@PATH,19,-204.189,2146.04,89.06788,0,0,1,0,100,0),
(@PATH,20,-201.238,2146.09,87.6928,0,0,1,0,100,0),
(@PATH,21,-197.09,2144.55,86.53151,0,0,1,0,100,0),
(@PATH,22,-192.554,2142.34,84.80293,0,0,1,0,100,0),
(@PATH,23,-190.082,2141.37,83.45259,0,0,1,0,100,0),
(@PATH,24,-189.03,2139.11,83.32229,0,0,1,0,100,0),
(@PATH,25,-190.51,2133.59,81.53151,0,0,1,0,100,0),
(@PATH,26,-193.363,2127.52,81.53151,0,0,1,0,100,0),
(@PATH,27,-195.995,2122.86,81.5315,0,0,1,0,100,0),
(@PATH,28,-193.363,2127.52,81.53151,0,0,1,0,100,0),
(@PATH,29,-190.51,2133.59,81.53151,0,0,1,0,100,0);
-- 0x20309404202E06C00071740002CB9BCD .go xyz -189.0459 2139.051 83.33153


-- Pathing for  Entry: 47131 'TDB FORMAT' 
-- formation leader
SET @NPC := 371072;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-161.823,`position_y`=2223.74,`position_z`=82.19942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-161.823,2223.74,82.19942,0,0,1,0,100,0),
(@PATH,2,-171.804,2217.05,80.60416,0,0,1,0,100,0),
(@PATH,3,-177.542,2215.56,80.06255,0,0,1,0,100,0),
(@PATH,4,-161.823,2223.74,82.19942,0,0,1,0,100,0),
(@PATH,5,-156.411,2233.32,84.37106,0,0,1,0,100,0),
(@PATH,6,-162.856,2244.59,86.31627,0,0,1,0,100,0),
(@PATH,7,-168.813,2251.34,86.5315,0,0,1,0,100,0),
(@PATH,8,-189.283,2262.72,90.8772,0,0,1,0,100,0),
(@PATH,9,-196.215,2265.29,90.73151,0,0,1,0,100,0),
(@PATH,10,-176.066,2256.23,87.02258,0,0,1,0,100,0),
(@PATH,11,-168.813,2251.34,86.5315,0,0,1,0,100,0),
(@PATH,12,-162.856,2244.59,86.31627,0,0,1,0,100,0),
(@PATH,13,-156.411,2233.32,84.37106,0,0,1,0,100,0);
-- 0x20309404202E06C000717400044B9BCD .go xyz -161.823 2223.74 82.19942

DELETE FROM `creature_formations` WHERE `leaderGUID`= 371072;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(371072, 371072, 0, 0, 515, 0, 0),
(371072, 371076, 1.7, 80, 515, 0, 0),
(371072, 371071, 1.7, 280, 515, 0, 0),
(371072, 371077, 1.7, 330, 515, 0, 0),
(371072, 371075, 1.7, 30, 515, 0, 0);

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 371005;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-205.6569,`position_y`=2159.164,`position_z`=79.9315 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-205.6569,2159.164,79.9315,0,0,1,0,100,0),
(@PATH,2,-207.2158,2171.358,79.93151,0,0,1,0,100,0),
(@PATH,3,-207.1185,2183.651,79.9315,0,0,1,0,100,0),
(@PATH,4,-206.6177,2195.511,79.9315,0,0,1,0,100,0),
(@PATH,5,-201.8645,2206.329,79.99627,0,0,1,0,100,0),
(@PATH,6,-190.8698,2211.921,79.9315,0,0,1,0,100,0),
(@PATH,7,-181.1818,2216.823,79.79803,0,0,1,0,100,0),
(@PATH,8,-183.4368,2217.228,79.84972,0,0,1,0,100,0),
(@PATH,9,-195.474,2216.148,79.9315,0,0,1,0,100,0),
(@PATH,10,-206.6364,2221.896,79.94035,0,0,1,0,100,0),
(@PATH,11,-214.7874,2221.659,80.03462,0,0,1,0,100,0),
(@PATH,12,-219.9644,2212.874,79.95942,0,0,1,0,100,0),
(@PATH,13,-221.6301,2201.626,79.9315,0,0,1,0,100,0),
(@PATH,14,-222.7887,2189.785,79.9315,0,0,1,0,100,0),
(@PATH,15,-223.4415,2177.728,79.93151,0,0,1,0,100,0),
(@PATH,16,-221.2689,2168.338,79.93151,0,0,1,0,100,0),
(@PATH,17,-212.4943,2160.883,79.93151,0,0,1,0,100,0),
(@PATH,18,-205.1652,2156.023,79.9315,0,0,1,0,100,0);
-- 0x20309404202E06C00071740007CB9BCD .go xyz -205.6569 2159.164 79.9315

DELETE FROM `creature_formations` WHERE `leaderGUID`= 371005;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(371005, 371005, 0, 0, 515, 0, 0),
(371005, 371007, 1.3, 100, 515, 0, 0),
(371005, 371001, 1.3, 260, 515, 0, 0),
(371005, 371006, 3, 225, 515, 0, 0),
(371005, 370997, 3, 135, 515, 0, 0);

-- Pathing for  Entry: 47131 'TDB FORMAT' 
SET @NPC := 370964;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-180.995,`position_y`=2172.09,`position_z`=97.53151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-180.995,2172.09,97.53151,0,0,1,0,100,0),
(@PATH,2,-191.658,2136.938,97.53151,0,0,1,0,100,0),
(@PATH,3,-194.9167,2126.898,97.53151,0,0,1,0,100,0),
(@PATH,4,-198.5885,2116.054,97.5315,0,0,1,0,100,0),
(@PATH,5,-201.1354,2109.094,97.5315,0,0,1,0,100,0),
(@PATH,6,-194.9167,2126.898,97.53151,0,0,1,0,100,0),
(@PATH,7,-191.658,2136.938,97.53151,0,0,1,0,100,0),
(@PATH,8,-186.283,2155.41,97.53151,0,0,1,0,100,0);
-- 0x20309404202E06C000717400094B9BCD .go xyz -180.995 2172.09 97.53151

DELETE FROM `creature_formations` WHERE `leaderGUID`= 370964;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(370964, 370964, 0, 0, 515, 0, 0),
(370964, 370959, 1.7, 80, 515, 0, 0),
(370964, 370965, 1.7, 280, 515, 0, 0),
(370964, 370966, 1.7, 330, 515, 0, 0),
(370964, 370946, 1.7, 30, 515, 0, 0);

-- Pathing for  Entry: 3875 'TDB FORMAT' 
SET @NPC := 371042;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-187.786,`position_y`=2215.41,`position_z`=79.86974 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-187.786,2215.41,79.86974,0,0,0,0,100,0),
(@PATH,2,-178.976,2217.85,80.00671,0,0,0,0,100,0),
(@PATH,3,-178.0273,2228.236,77.39046,0,0,0,0,100,0),
(@PATH,4,-178.976,2217.85,80.00671,0,0,0,0,100,0),
(@PATH,5,-187.786,2215.41,79.86974,0,0,0,0,100,0),
(@PATH,6,-203.744,2214.27,80.11271,0,0,0,0,100,0),
(@PATH,7,-211.75,2216.71,79.96252,0,0,0,0,100,0),
(@PATH,8,-203.744,2214.27,80.11271,0,0,0,0,100,0);
-- 0x203094042003C8C000717400004B9BCD .go xyz -187.786 2215.41 79.86974

-- Pathing for  Entry: 3875 'TDB FORMAT' 
SET @NPC := 371004;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-218.328,`position_y`=2200.86,`position_z`=79.93149 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-218.328,2200.86,79.93149,0,0,0,0,100,0),
(@PATH,2,-208.717,2211.1,80.02415,0,0,0,0,100,0),
(@PATH,3,-198.048,2223.75,79.9315,0,0,0,0,100,0),
(@PATH,4,-208.717,2211.1,80.02415,0,0,0,0,100,0),
(@PATH,5,-218.328,2200.86,79.93149,0,0,0,0,100,0),
(@PATH,6,-220.208,2182.55,79.9315,0,0,0,0,100,0),
(@PATH,7,-222.141,2159.87,79.93151,0,0,0,0,100,0),
(@PATH,8,-220.208,2182.55,79.9315,0,0,0,0,100,0);
-- 0x203094042003C8C00071740000CB9BCD .go xyz -218.328 2200.86 79.93149

-- Pathing for  Entry: 3875 'TDB FORMAT' 
SET @NPC := 371135;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-186.621,`position_y`=2261.53,`position_z`=91.02705 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-186.621,2261.53,91.02705,0,0,0,0,100,0),
(@PATH,2,-174.997,2255.62,86.68996,0,0,0,0,100,0),
(@PATH,3,-155.284,2237.76,84.90366,0,0,0,0,100,0),
(@PATH,4,-157.8985,2227.425,82.91762,0,0,0,0,100,0),
(@PATH,5,-155.284,2237.76,84.90366,0,0,0,0,100,0),
(@PATH,6,-155.3389,2237.543,84.86978,0,0,0,0,100,0);
-- 0x203094042003C8C000717400014B9BCD .go xyz -186.621 2261.53 91.02705

-- Pathing for  Entry: 3875 'TDB FORMAT' 
SET @NPC := 371041;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-213.193,`position_y`=2168.08,`position_z`=79.93151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-213.193,2168.08,79.93151,0,0,0,0,100,0),
(@PATH,2,-201.619,2159.46,79.9315,0,0,0,0,100,0),
(@PATH,3,-213.193,2168.08,79.93151,0,0,0,0,100,0),
(@PATH,4,-206.565,2190.57,79.93151,0,0,0,0,100,0),
(@PATH,5,-208.078,2204.84,80.0667,0,0,0,0,100,0),
(@PATH,6,-202.946,2217.8,80.14151,0,0,0,0,100,0),
(@PATH,7,-208.078,2204.84,80.0667,0,0,0,0,100,0),
(@PATH,8,-206.5652,2190.572,79.9315,0,0,0,0,100,0);
-- 0x203094042003C8C00071740001CB9BCD .go xyz -213.193 2168.08 79.93151

-- Pathing for  Entry: 3875 'TDB FORMAT' 
SET @NPC := 371144;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-249.528,`position_y`=2281,`position_z`=75.13151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-249.528,2281,75.13151,0,0,0,0,100,0),
(@PATH,2,-257.429,2283.96,75.13149,0,0,0,0,100,0),
(@PATH,3,-261.245,2285.5,75.13151,0,0,0,0,100,0),
(@PATH,4,-262.115,2289.77,75.1315,0,0,0,0,100,0),
(@PATH,5,-260.658,2294.45,75.13151,0,0,0,0,100,0),
(@PATH,6,-256.936,2296.94,75.13151,0,0,0,0,100,0),
(@PATH,7,-250.703,2294.9,75.13151,0,0,0,0,100,0),
(@PATH,8,-244.811,2292.94,75.13149,0,0,0,0,100,0),
(@PATH,9,-237.326,2290.35,75.1315,0,0,0,0,100,0),
(@PATH,10,-231.441,2287.33,75.1315,0,0,0,0,100,0),
(@PATH,11,-226.16,2285.06,75.13149,0,0,0,0,100,0),
(@PATH,12,-224.778,2280.57,75.1315,0,0,0,0,100,0),
(@PATH,13,-226.003,2275.97,75.1315,0,0,0,0,100,0),
(@PATH,14,-228.705,2272.94,75.1315,0,0,0,0,100,0),
(@PATH,15,-234.149,2275.06,75.16153,0,0,0,0,100,0),
(@PATH,16,-241.1499,2277.745,75.13152,0,0,0,0,100,0);
-- 0x203094042003C8C000717400044B9BCD .go xyz -249.528 2281 75.13151

-- Pathing for  Entry: 47143 'TDB FORMAT' 
SET @NPC := 371155;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-255.974,`position_y`=2315.51,`position_z`=95.9315 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-255.974,2315.51,95.9315,0,0,0,0,100,0),
(@PATH,2,-277.262,2324.03,95.9315,0,0,0,0,100,0),
(@PATH,3,-269.446,2320.89,95.9315,0,0,0,0,100,0),
(@PATH,4,-248.9933,2312.855,96.07217,0,0,0,0,100,0),
(@PATH,5,-240.427,2309.49,95.9315,0,0,0,0,100,0),
(@PATH,6,-236.655,2307.97,95.93151,0,0,0,0,100,0),
(@PATH,7,-248.9933,2312.855,96.07217,0,0,0,0,100,0);
-- 0x20309404202E09C000717400004B9BCD .go xyz -255.974 2315.51 95.9315

-- Pathing for  Entry: 47143 'TDB FORMAT' 
SET @NPC := 371145;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-205.785,`position_y`=2295.68,`position_z`=95.93151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-205.785,2295.68,95.93151,0,0,0,0,100,0),
(@PATH,2,-213.009,2298.61,95.9315,0,0,0,0,100,0),
(@PATH,3,-215.851,2299.77,95.9315,0,0,0,0,100,0),
(@PATH,4,-205.785,2295.68,95.93151,0,0,0,0,100,0),
(@PATH,5,-196.538,2291.93,95.93152,0,0,0,0,100,0),
(@PATH,6,-191.057,2289.7,95.9315,0,0,0,0,100,0),
(@PATH,7,-186.377,2287.84,95.9315,0,0,0,0,100,0),
(@PATH,8,-191.057,2289.7,95.9315,0,0,0,0,100,0),
(@PATH,9,-196.538,2291.93,95.93152,0,0,0,0,100,0);
-- 0x20309404202E09C00071740000CB9BCD .go xyz -205.785 2295.68 95.93151

-- Pathing for  Entry: 47143 'TDB FORMAT' 
SET @NPC := 371143;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-272.924,`position_y`=2273.36,`position_z`=95.9315 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-272.924,2273.36,95.9315,0,0,0,0,100,0),
(@PATH,2,-284.042,2277.57,95.9315,0,0,0,0,100,0),
(@PATH,3,-290.1371,2279.946,95.9315,0,0,0,0,100,0),
(@PATH,4,-284.042,2277.57,95.9315,0,0,0,0,100,0),
(@PATH,5,-272.924,2273.36,95.9315,0,0,0,0,100,0),
(@PATH,6,-263.441,2269.58,97.97887,0,0,0,0,100,0),
(@PATH,7,-256.03,2266.48,100.9315,0,0,0,0,100,0),
(@PATH,8,-263.441,2269.58,97.97887,0,0,0,0,100,0);
-- 0x20309404202E09C000717400014B9BCD .go xyz -272.924 2273.36 95.9315

-- Pathing for  Entry: 47132 'TDB FORMAT' 
SET @NPC := 371060;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-130.043,`position_y`=2198.16,`position_z`=144.9528 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-130.043,2198.16,144.9528,0,0,1,0,100,0),
(@PATH,2,-123.637,2191.48,143.5198,0,0,1,0,100,0),
(@PATH,3,-119.444,2181.99,141.5708,0,0,1,0,100,0),
(@PATH,4,-119.76,2171.37,139.7816,0,0,1,0,100,0),
(@PATH,5,-122.024,2163.51,138.7315,0,0,1,0,100,0),
(@PATH,6,-119.444,2181.99,141.5708,0,0,1,0,100,0),
(@PATH,7,-123.637,2191.48,143.5198,0,0,1,0,100,0),
(@PATH,8,-130.043,2198.16,144.9528,0,0,1,0,100,0),
(@PATH,9,-139.313,2202.1,146.7611,0,0,1,0,100,0),
(@PATH,10,-148.03,2202.66,148.2551,0,0,1,0,100,0),
(@PATH,11,-156.464,2200.04,149.8841,0,0,1,0,100,0),
(@PATH,12,-162.661,2195.54,151.058,0,0,1,0,100,0),
(@PATH,13,-170.503,2183.05,151.9315,0,0,1,0,100,0),
(@PATH,14,-162.661,2195.54,151.058,0,0,1,0,100,0),
(@PATH,15,-156.464,2200.04,149.8841,0,0,1,0,100,0),
(@PATH,16,-148.03,2202.66,148.2551,0,0,1,0,100,0),
(@PATH,17,-139.313,2202.1,146.7611,0,0,1,0,100,0);
-- 0x20309404202E070000717400044B9BCD .go xyz -130.043 2198.16 144.9528

DELETE FROM `creature_formations` WHERE `leaderGUID`= 371060;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(371060, 371060, 0, 0, 515, 0, 0),
(371060, 371063, 1.7, 270, 515, 0, 0),
(371060, 371061, 1.7, 45, 515, 0, 0),
(371060, 371064, 1.7, 315, 515, 0, 0);

-- Pathing for  Entry: 47145 'TDB FORMAT' 
SET @NPC := 371035;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-153.214,`position_y`=2187.62,`position_z`=105.2829 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-153.214,2187.62,105.2829,0,0,0,0,100,0),
(@PATH,2,-151.4448,2186.933,105.804,0,0,0,0,100,0),
(@PATH,3,-147.009,2185.09,107.5957,0,0,0,0,100,0),
(@PATH,4,-139.924,2182.26,111.1069,0,0,0,0,100,0),
(@PATH,5,-125.892,2176.94,112.7315,0,0,0,0,100,0),
(@PATH,6,-121.795,2175.26,112.7315,0,0,0,0,100,0),
(@PATH,7,-110.116,2170.54,107.4586,0,0,0,0,100,0),
(@PATH,8,-105.325,2168.27,105.4702,0,0,0,0,100,0),
(@PATH,9,-104.118,2167.28,105.0464,0,0,0,0,100,0),
(@PATH,10,-107.112,2158.055,102.3315,0,0,0,0,100,0),
(@PATH,11,-104.217,2165.6,104.9077,0,0,0,0,100,0),
(@PATH,12,-104.118,2167.28,105.0464,0,0,0,0,100,0),
(@PATH,13,-110.116,2170.54,107.4586,0,0,0,0,100,0),
(@PATH,14,-121.795,2175.26,112.7315,0,0,0,0,100,0),
(@PATH,15,-125.892,2176.94,112.7315,0,0,0,0,100,0),
(@PATH,16,-139.924,2182.26,111.1069,0,0,0,0,100,0),
(@PATH,17,-147.009,2185.09,107.5957,0,0,0,0,100,0),
(@PATH,18,-151.307,2186.88,105.8647,0,0,0,0,100,0),
(@PATH,19,-154.7157,2186.236,105.1315,0,0,0,0,100,0),
(@PATH,20,-158.517,2177.08,102.3315,0,0,0,0,100,0),
(@PATH,21,-157.297,2176,102.3315,0,0,0,0,100,0),
(@PATH,22,-151.898,2174.59,99.9315,0,0,0,0,100,0),
(@PATH,23,-157.2549,2175.989,102.3244,0,0,0,0,100,0),
(@PATH,24,-158.517,2177.08,102.3315,0,0,0,0,100,0),
(@PATH,25,-154.755,2186.2,105.1045,0,0,0,0,100,0);
-- 0x20309404202E0A4000717400004B9BCD .go xyz -153.214 2187.62 105.2829

-- Pathing for  Entry: 3873 'TDB FORMAT' 
SET @NPC := 371031;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-240.239,`position_y`=2190.376,`position_z`=97.53152 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-240.239,2190.376,97.53152,0,33,0,0,100,0),
(@PATH,2,-233.293,2218.07,97.53151,0,33,0,0,100,0),
(@PATH,3,-240.239,2190.376,97.53152,0,33,0,0,100,0),
(@PATH,4,-244.8245,2183.276,94.13151,0,33,0,0,100,0),
(@PATH,5,-253.2409,2165.885,94.1315,0,33,0,0,100,0),
(@PATH,6,-244.8245,2183.276,94.13151,0,33,0,0,100,0);
-- 0x203094042003C84000717400024B9BCD .go xyz -240.239 2190.376 97.53152
