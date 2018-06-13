-- 
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0, `phaseMask` =2, `spawntimesecs`=120 WHERE `id` = 28529;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 2, `phaseMask` =2, `spawntimesecs`=120 WHERE `id` = 28530;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` = 28557;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` = 28594;
UPDATE `creature_addon` SET `auras`= 29266 WHERE `guid`=130211;

-- duplicates removed.
DELETE FROM creature WHERE guid IN (128498, 128499, 128763, 128776, 128784, 128786, 128794, 129151, 129152, 129214, 129215, 129235, 129236, 129245, 129246, 129247, 129248, 129249, 129251, 129255, 129259, 129263, 129270, 129271, 129272, 129280, 129283, 129293, 129294, 129295, 129298, 129305);
DELETE FROM creature_addon WHERE guid IN (128498, 128499, 128763, 128776, 128784, 128786, 128794, 129151, 129152, 129214, 129215, 129235, 129236, 129245, 129246, 129247, 129248, 129249, 129251, 129255, 129259, 129263, 129270, 129271, 129272, 129280, 129283, 129293, 129294, 129295, 129298, 129305);

-- Acherus Geist
UPDATE creature SET position_x = 2374.8103, position_y = -5768.86914, position_z = 151.36789, orientation = 1.0397, spawndist = 10, MovementType = 1 WHERE guid = 128493;
UPDATE creature SET position_x = 2308.156738, position_y = -5692.175293, position_z = 154.035553, orientation = 5.493559, spawndist = 10, MovementType = 1 WHERE guid = 128492;
UPDATE creature SET position_x = 2294.674805, position_y = -5664.577148, position_z = 149.566483, orientation = 5.033237, spawndist = 10, MovementType = 1 WHERE guid = 128491;
UPDATE creature SET position_x = 2353.526855, position_y = -5650.782715, position_z = 155.107605, orientation = 5.975759, spawndist = 10, MovementType = 1 WHERE guid = 128490;
UPDATE creature SET position_x = 2388.947510, position_y = -5671.491211, position_z = 153.925858, orientation = 5.407634, spawndist = 15, MovementType = 1 WHERE guid = 128485;
UPDATE creature SET position_x = 2407.680664, position_y = -5656.884766, position_z = 156.329193, orientation = 6.108020, spawndist = 10, MovementType = 1 WHERE guid = 128489;
UPDATE creature SET position_x = 2396.615234, position_y = -5642.852051, position_z = 156.710114, orientation = 1.415266, spawndist = 10, MovementType = 1 WHERE guid = 128488;
UPDATE creature SET position_x = 2274.42, position_y = -5646.18, position_z = 142.258, orientation = 3.61903, spawndist = 0, MovementType = 2 WHERE guid = 128494;
UPDATE creature SET position_x = 2259.67, position_y = -5641.18, position_z = 138.909, orientation = 3.15041, spawndist = 0, MovementType = 2 WHERE guid = 128495;
UPDATE creature SET position_x = 2317.49, position_y = -5661.7, position_z = 153.201, orientation = 2.40253, spawndist = 0, MovementType = 2 WHERE guid = 128486;
UPDATE creature SET position_x = 2420.91, position_y = -5783.06, position_z = 144.912, orientation = 5.05147, spawndist = 0, MovementType = 2 WHERE guid = 128497;
UPDATE creature SET position_x = 2428.08, position_y = -5781.23, position_z = 143.936, orientation = 4.95301, spawndist = 0, MovementType = 2 WHERE guid = 128496;
UPDATE creature SET position_x = 2345.153809, position_y = -5720.771484, position_z = 153.922424, orientation = 0.743744, spawndist = 0, MovementType = 0 WHERE guid = 128578;
UPDATE `creature` SET `position_x` = -2866.342, `position_y` = 6403.193, `position_z`= 80.44, `orientation` = 0.044664 WHERE `guid`= 28647;

-- Scarlet Farm Hound
UPDATE creature SET position_x = 1993.386230, position_y = -5786.060547, position_z = 100.834045, orientation = 4.610285, spawndist = 10, MovementType = 1 WHERE guid = 128584;
UPDATE creature SET position_x = 2032.527954, position_y = -5819.889648, position_z = 100.997482, orientation = 3.675666, spawndist = 10, MovementType = 1 WHERE guid = 128586;
UPDATE creature SET position_x = 1992.902222, position_y = -5866.563477, position_z = 100.788521, orientation = 4.040874, spawndist = 10, MovementType = 1 WHERE guid = 128583;
UPDATE creature SET position_x = 1951.767578, position_y = -5825.396484, position_z = 100.842171, orientation = 3.227984, spawndist = 10, MovementType = 1 WHERE guid = 128587;
UPDATE creature SET spawndist = 10, MovementType = 1 WHERE guid = 128589;
 
-- Scarlet Medic
UPDATE creature SET position_x = 2172.88, position_y = -5729.58, position_z = 101.757, orientation = 1.30883 WHERE guid = 129257;

-- Scarlet Peasant
UPDATE creature SET orientation = 5.90615 WHERE guid = 128758;

-- Scarlet Captain
UPDATE `creature_addon` SET `path_id` = 1292990 WHERE `guid` = 128758;

-- Havenshire Stallion - spawntime req. for his event
UPDATE `creature` SET `spawntimesecs` = 20 WHERE `guid`  IN (129217,129237,129216,129252);

DELETE FROM `creature_formations` WHERE `leaderGUID`=129217;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(129217, 129217, 0, 0, 515, 0, 0),
(129217, 129237, 5, 45, 515, 0, 0),
(129217, 129216, 5, 315, 515, 0, 0),
(129217, 129252, 5, 0, 515, 0, 0);
UPDATE `creature_formations` SET `dist`=6, `angle`=0 WHERE `leaderGUID`=129212 AND `memberGUID`=129230;

-- Scarlet Fleet Defender - q. req.
UPDATE creature SET spawntimesecs = 60 WHERE id = 28834;

-- Scarlet Infantryman - all should have same aura addon (we can use template and remove from creature_addon)
DELETE FROM creature_addon WHERE guid IN (129264,129265,129266,129267,129268,129269,129270,129271,129272,129273,129274,129275,129276,129277,129278,129279,129281,129283,129285,129286,129287,129288,129289,129290,129291);
DELETE FROM creature_template_addon WHERE entry = 28609;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(28609,0,0,0,1,333,'48356');
UPDATE `creature_addon` SET `auras` = "48356 52103", `bytes2`=1, `emote`=0 WHERE `guid` = 129282;
UPDATE `creature_addon` SET `auras` = "48356 52103", `bytes2`=1, `emote`=0 WHERE `guid` = 129284;

UPDATE creature SET position_x = 2417.918945, position_y = -5859.758789, position_z = 105.522697, orientation = 0.9 WHERE guid = 129286;
UPDATE creature SET position_x = 2435.682373, position_y = -5867.880859, position_z = 106.577202, orientation = 1.6 WHERE guid = 129287;
UPDATE creature SET position_x = 2144.156006, position_y = -5674.584961, position_z = 110.115265, orientation = 0.2 WHERE guid = 129291;
UPDATE creature SET position_x = 2232.0961, position_y = -5832.9101, position_z = 101.341705, orientation = 4.845213 WHERE guid = 129210;

-- Scarlet Peasant
UPDATE creature SET position_x = 2134.455811, position_y = -5743.186035, position_z = 99.443970, orientation = 2.490976 WHERE guid = 128792;
UPDATE creature SET position_x = 2085.78, position_y = -5754.1, position_z = 99.3376, orientation = 6.07106 WHERE guid = 128766;
UPDATE creature SET spawndist = 0, MovementType = 0 WHERE guid IN (128755,128761);
DELETE FROM creature_addon WHERE guid IN (128766,128782,128772,128774,128791,128792,128795);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(128766,0,0,0,1,234,'48356'),
(128782,0,0,0,1,234,'48356'),
(128772,0,0,0,1,234,'48356'),
(128774,0,0,0,1,234,'48356'),
(128791,0,0,0,1,234,'48356'),
(128792,0,0,0,1,234,'48356'),
(128795,0,0,0,1,234,'48356');

-- WAYPOINTS --  for phase 1
UPDATE creature SET MovementType = 2, spawndist = 0 WHERE guid IN (128486,  128484,128494,128495,128497,128496,129302,129299,129217);
DELETE FROM creature_addon WHERE guid IN (128486,  128484,128494,128495,128497,128496,129302,129299,129217,128735,128736,128737);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(128486, 1284860,0,0,0, 0,''),
(128484, 1284840,0,0,0, 0,''),
(128494, 1284940,0,0,0, 0,''),
(128495, 1284950,0,0,0, 0,''),
(128497, 1284970,0,0,0, 0,''),
(128496, 1284960,0,0,0, 0,''),
(129302, 1293020,2404,0,0, 0,'48356'),
(129299, 1292990,2404,0,0, 0,'48356'),
(129217, 1292170,0,0,0,0,''),
(128735, 1287350,2404,0,0, 0,''),
(128737, 1287370,2404,0,0, 0,''),
(128736, 1287360,2404,0,0, 0,'');

DELETE FROM `waypoint_data` WHERE `id` IN (1284860,1284840,1284940,1284950,1284970,1284960,1293020,1292990,1292170,1287350,1287360,1287370);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(1284860,1,2317.49,-5661.7,153.201,2000,0,2.40253,100,1),
(1284860,2,2339.6,-5683.8,153.922,0,0,5.5874,100,1),
(1284860,3,2355.11,-5702.48,153.92,0,0,5.47194,100,1),
(1284860,4,2385.46,-5730.73,153.922,0,0,5.43574,100,1),
(1284860,5,2407.29,-5754.73,153.907,2000,0,5.50643,100,1),
(1284860,6,2363.77,-5709.2,153.923,0,0,2.27844,100,1),
(1284860,7,2317.49,-5661.7,153.201,2000,0,2.4,100,1),
(1284840,1,2322.74,-5624.89,152.099,1000,0,0.2,100,1),
(1284840,2,2312.95,-5645.39,149.817,0,0,0.21,100,1),
(1284940,1,2274.42,-5646.18,142.258,1000,0,3.62,100,1),
(1284940,2,2263.38,-5651.55,138.595,0,0,3.37974,100,1),
(1284940,3,2220.51,-5658.85,125.151,0,0,3.72,100,1),
(1284940,4,2206.73,-5668.97,118.319,0,0,3.72453,100,1),
(1284940,5,2184.66,-5685.67,110.593,0,0,1.62937,100,1),
(1284940,6,2183.91,-5677.17,112.45,0,0,1.07671,100,1),
(1284940,7,2202.52,-5652.79,121.832,0,0,0.505729,100,1),
(1284940,8,2234.02,-5638.04,133.237,0,0,0.255441,100,1),
(1284940,9,2262.76,-5630.8,142.946,0,0,5.64327,100,1),
(1284940,10,2279.18,-5643.24,143.819,0,0,3.68213,100,1),
(1284950,1,2259.67,-5641.18,138.909,1000,0,3.15,100,1),
(1284950,2,2220.92,-5644.93,127.963,0,0,3.7,100,1),
(1284950,3,2180.75,-5671.91,113.432,0,0,5.07701,100,1),
(1284950,4,2186.25,-5687.66,110.304,0,0,0.591784,100,1),
(1284950,5,2198.87,-5677.85,113.546,0,0,0.827452,100,1),
(1284950,6,2211.37,-5665.1,120.953,0,0,0.4346,100,1),
(1284950,7,2215.85,-5662.83,122.909,0,0,0.113371,100,1),
(1284950,8,2230.85,-5660.58,127.762,0,0,0.217311,100,1),
(1284950,9,2268.12,-5652.45,140.123,0,0,2.3,100,1),
(1284970,1,2420.91,-5783.06,144.912,1000,0,5.05147,100,1),
(1284970,2,2424.91,-5795.56,136.284,0,0,5.0,100,1),
(1284970,3,2430.05,-5813.4,123.698,0,0,4.76715,100,1),
(1284970,4,2431.55,-5839.9,112.193,0,0,5.14022,100,1),
(1284970,5,2435.88,-5848.18,110.821,0,0,1.28234,100,1),
(1284970,6,2439.07,-5830.71,117.19,0,0,1.7575,100,1),
(1284970,7,2437.07,-5817.21,121.852,0,0,1.7575,100,1),
(1284970,8,2433.13,-5798.02,133.529,0,0,1.72991,100,1),
(1284970,9,2428.88,-5780.52,144.159,0,0,3.64,100,1),
(1284960,1,2428.08,-5781.23,143.936,1000,0,4.95,100,1),
(1284960,2,2431.83,-5801.73,131.007,0,0,4.9,100,1),
(1284960,3,2434.52,-5815.74,122.281,0,0,4.70491,100,1),
(1284960,4,2435.68,-5850.09,110.343,0,0,2.27017,100,1),
(1284960,5,2426.39,-5839.45,112.787,0,0,1.48386,100,1),
(1284960,6,2426.89,-5832.45,115.05,0,0,1.48386,100,1),
(1284960,7,2428.61,-5806.57,127.862,0,0,1.87184,100,1),
(1284960,8,2424.36,-5792.57,138.63,0,0,1.87184,100,1),
(1284960,9,2420.36,-5779.07,146.508,0,0,6.21274,100,1),
(1284960,10,2426.77,-5779.23,145.036,0,0,5.28497,100,1),
(1293020,1,2142.69,-5854.15,101.352,0,0,5.64134,100,0),
(1293020,2,2160.03,-5863.74,101.343,0,0,5.96987,100,0),
(1293020,3,2163.18,-5866.82,101.325,5000,0,5.95,100,0),
(1293020,4,2181.06,-5870.53,101.288,0,0,6.1,100,0),
(1293020,5,2162.67,-5866.22,101.328,0,0,2.74714,100,0),
(1293020,6,2142.94,-5853.58,101.349,0,0,2.0285,100,0),
(1293020,7,2142.59,-5841.03,101.318,0,0,1.42374,100,0),
(1293020,8,2142.77,-5819.21,100.895,0,0,1.86334,100,0),
(1293020,9,2128.82,-5790.25,98.8795,0,0,1.38032,100,0),
(1293020,10,2128.17,-5794.43,99.0854,0,0,4.67271,100,0),
(1293020,11,2130.96,-5801.12,99.619,0,0,5.31045,100,0),
(1293020,12,2143.34,-5819.31,100.926,0,0,5.01514,100,0),
(1292990,1,2144.25,-5736.86,100.243,0,0,2.01409,100,0),
(1292990,2,2137.89,-5727.64,100.314,0,0,2.35,100,0),
(1292990,3,2128.15,-5716.13,100.621,0,0,2.2,100,0),
(1292990,4,2138.36,-5728.58,100.285,5000,0,5.34968,100,0),
(1292990,5,2144.69,-5738.47,100.186,0,0,4.96091,100,0),
(1292990,6,2147.98,-5759.81,99.8653,0,0,4.61769,100,0),
(1292990,7,2145.06,-5766.31,99.5844,0,0,4.25013,100,0),
(1292990,8,2148.29,-5759.08,99.9146,0,0,1.63554,100,0),
(1292170,1,2217.34,-5873.99,101.251,1000,0,0.593412,100,1),
(1292170,2,2214.53,-5869.6,101.534,0,0,2.83545,100,1),
(1292170,3,2181.07,-5865.87,101.331,0,0,3.36324,100,1),
(1292170,4,2139.21,-5878.27,101.469,0,0,3.93265,100,1),
(1292170,5,2118.11,-5903.57,104.343,0,0,3.3436,100,1),
(1292170,6,2072.44,-5914.58,106.378,0,0,3.39073,100,1),
(1292170,7,2028.89,-5920.68,105.233,0,0,3.28863,100,1),
(1292170,8,2003.16,-5924.91,105.324,0,0,3.41822,100,1),
(1292170,9,1968.43,-5935.75,102.545,0,0,3.21401,100,1),
(1292170,10,1924.76,-5931.14,103.405,0,0,2.93127,100,1),
(1292170,11,1894.96,-5921.15,103.129,0,0,2.94698,100,1),
(1292170,12,1849.19,-5916.93,105.57,0,0,3.19438,100,1),
(1292170,13,1818.86,-5920.18,112.552,0,0,3.19438,100,1),
(1292170,14,1780.82,-5925.05,116.113,0,0,2.85273,100,1),
(1292170,15,1741.46,-5907.59,116.121,1000,1188,2.73099,100,1),
-- Scarlet Commander
(1287350,1,1775.91,-5832.22,116.268,0,0,3.27545,100,0),
(1287350,2,1755.28,-5834.67,116.466,0,0,0.155067,100,0),
(1287370,1,1762.27,-5808.16,116.622,0,0,0.0435456,100,0),
(1287370,2,1784.43,-5806.17,114.238,0,0,3.29274,100,0),
(1287360,1,1576.5323,-5779.924,117.6273,0,0, 4.752857,100,0),
(1287360,2,1578.6364,-5790.505,119.1621,0,0, 4.963344,100,0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28605; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=-129217 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-129217,0,0,0,34,0,100,0,2,14,0,0,41,0,0,0,0,0,0,11,28607,30,0,0,0,0,0,"Havenshire Stallion - On movement informer - despawn all guars"),
(-129217,0,1,0,34,0,100,0,2,14,0,0,41,0,0,0,0,0,0,11,28606,30,0,0,0,0,0,"Havenshire Stallion - On movement informer - despawn all guars"),
(-129217,0,2,0,34,0,100,0,2,14,0,0,41,0,0,0,0,0,0,11,28605,30,0,0,0,0,0,"Havenshire Stallion - On movement informer - despawn all guars"),
(-129217,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Havenshire Stallion - On reset - set active"),
(-129217,0,4,0,25,0,100,0,0,0,0,0,83,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Havenshire Stallion - On reset - Remove npc flag");
