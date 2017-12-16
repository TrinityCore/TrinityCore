SET @CGUID := 84293; -- SET BY TC
DELETE FROM `creature` WHERE `id`=30447;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 30447, 571, 0, 0,  1, 1, 0, 0, 7984.078, -2989.304, 1139.083, 0.3093449, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: 0) (possible waypoints or random movement)
(@CGUID+1, 30447, 571, 0, 0,  1, 1, 0, 0, 7983.461, -2980.022, 1141.255, 0.3097978, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: 0) (possible waypoints or random movement)
(@CGUID+2, 30447, 571, 0, 0,  1, 1, 0, 0, 7975.4, -2985.354, 1139.796, 0.1802355, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: 0) (possible waypoints or random movement)
(@CGUID+3, 30447, 571, 0, 0,  1, 1, 0, 0, 8005.68, -2935.988, 1136.467, 4.198086, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+4, 30447, 571, 0, 0,  1, 1, 0, 0, 7939.006, -2886.748, 1134.149, 0.236685, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+5, 30447, 571, 0, 0,  1, 1, 0, 0, 7941.088, -2887.535, 1133.974, 4.221686, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+6, 30447, 571, 0, 0,  1, 1, 0, 0, 8051.368, -2880.661, 1137.401, 3.104516, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+7, 30447, 571, 0, 0,  1, 1, 0, 0, 8177.225, -2820.83, 1136.238, 0.3045847, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+8, 30447, 571, 0, 0,  1, 1, 0, 0, 8194.472, -2751.588, 1139.11, 1.072228, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+9, 30447, 571, 0, 0,  1, 1, 0, 0, 8150.27, -2793.455, 1134.958, 5.553068, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+10, 30447, 571, 0, 0, 1, 1, 0, 0, 8157.279, -2786.854, 1136.72, 5.414876, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+11, 30447, 571, 0, 0, 1, 1, 0, 0, 8160.097, -2796.68, 1135.685, 5.476207, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+12, 30447, 571, 0, 0, 1, 1, 0, 0, 8078.171, -2652.576, 1138.168, 5.448443, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+13, 30447, 571, 0, 0, 1, 1, 0, 0, 8072.478, -2618.102, 1140.539, 4.790993, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+14, 30447, 571, 0, 0, 1, 1, 0, 0, 8067.925, -2633.752, 1138.675, 5.127465, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+15, 30447, 571, 0, 0, 1, 1, 0, 0, 8081.401, -2617.683, 1140.041, 4.649848, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+16, 30447, 571, 0, 0, 1, 1, 0, 0, 7994.917, -2946.966, 1137.692, 2.369324, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+17, 30447, 571, 0, 0, 1, 1, 0, 0, 7971.485, -2878.911, 1133.459, 0.23685, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+18, 30447, 571, 0, 0, 1, 1, 0, 0, 7990.792, -2959.07, 1140.623, 1.733696, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+19, 30447, 571, 0, 0, 1, 1, 0, 0, 7984.026, -2962.738, 1141.202, 1.459277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+20, 30447, 571, 0, 0, 1, 1, 0, 0, 7992.106, -2969.481, 1141.56, 1.475012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+21, 30447, 571, 0, 0, 1, 1, 0, 0, 7992.757, -2958.356, 1140.335, 1.581538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+22, 30447, 571, 0, 0, 1, 1, 0, 0, 8179.327, -2561.278, 1141.933, 2.080739, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+23, 30447, 571, 0, 0, 1, 1, 0, 0, 8150.755, -2540.35, 1138.041, 3.960841, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+24, 30447, 571, 0, 0, 1, 1, 0, 0, 8171.236, -2574.502, 1144.015, 1.908301, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+25, 30447, 571, 0, 0, 1, 1, 0, 0, 8202.215, -2719.804, 1137.763, 1.774517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes)
(@CGUID+26, 30447, 571, 0, 0, 1, 1, 0, 0, 8209.81, -2731.839, 1139.254, 2.522765, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+27, 30447, 571, 0, 0, 1, 1, 0, 0, 8203.374, -2732.826, 1139.048, 2.18424, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)
(@CGUID+28, 30447, 571, 0, 0, 1, 1, 0, 0, 8194.94, -2735.072, 1139.284, 2.203755, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360); -- Romping Rhino (Area: Plain of Echoes) (possible waypoints or random movement)

UPDATE `creature` SET `spawntimesecs`=300 WHERE  `id`=30447;

-- Pathing number: 1
SET @NPC := @CGUID+17; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8000.43,`position_y`=-2945.279,`position_z`=1136.98 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8000.43,-2945.279,1136.98,0,0,0,0,100,0), -- 12:02:14
(@PATH,2,7999.445,-2947.021,1137.515,0,0,0,0,100,0), -- 12:02:14
(@PATH,3,7997.969,-2949.635,1138.265,0,0,0,0,100,0), -- 12:02:14
(@PATH,4,7996.984,-2951.377,1138.89,0,0,0,0,100,0), -- 12:02:14
(@PATH,5,7995.016,-2954.861,1139.64,0,0,0,0,100,0), -- 12:02:14
(@PATH,6,7993.539,-2957.475,1140.265,0,0,0,0,100,0), -- 12:02:14
(@PATH,7,7991.57,-2960.959,1140.89,0,0,0,0,100,0), -- 12:02:14
(@PATH,8,7988.617,-2966.186,1141.515,0,0,0,0,100,0), -- 12:02:14
(@PATH,9,7985.554,-2971.575,1141.815,0,0,0,0,100,0), -- 12:02:14
(@PATH,10,7985.554,-2971.575,1141.815,0,0,0,0,100,0), -- 12:02:14
(@PATH,11,7994.182,-2964.05,1141.526,0,0,0,0,100,0), -- 12:02:17
(@PATH,12,7998.432,-2960.3,1140.776,0,0,0,0,100,0), -- 12:02:17
(@PATH,13,8001.432,-2957.8,1140.276,0,0,0,0,100,0), -- 12:02:17
(@PATH,14,8004.085,-2955.57,1139.719,0,0,0,0,100,0), -- 12:02:19
(@PATH,15,8001.085,-2952.82,1138.969,0,0,0,0,100,0), -- 12:02:19
(@PATH,16,7997.585,-2949.57,1138.719,0,0,0,0,100,0), -- 12:02:19
(@PATH,17,7994.585,-2946.82,1137.969,0,0,0,0,100,0), -- 12:02:19
(@PATH,18,7989.085,-2941.07,1137.469,0,0,0,0,100,0), -- 12:02:19
(@PATH,19,7993.485,-2939.445,1136.842,0,0,0,0,100,0), -- 12:02:22
(@PATH,20,8001.987,-2909.999,1137.335,0,0,0,0,100,0), -- 12:02:23
(@PATH,21,8001.031,-2905.984,1137.753,0,0,0,0,100,0), -- 12:02:27
(@PATH,22,8006.789,-2934.026,1136.72,0,0,0,0,100,0), -- 12:02:28
(@PATH,23,8000.539,-2945.026,1137.47,0,0,0,0,100,0); -- 12:02:28
-- 0x20197C47601DBBC00000360000082C98 .go 8000.43 -2945.279 1136.98

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 2
SET @NPC := @CGUID+15;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7959.272,`position_y`=-2884.071,`position_z`=1133.766 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7959.272,`position_y`=-2884.071,`position_z`=1133.766 WHERE `guid` IN (@CGUID+20, @CGUID+18, @CGUID+19);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7959.272,-2884.071,1133.766,0,0,0,0,100,0), -- 12:02:17
(@PATH,2,7945.515,-2879.25,1132.664,0,0,0,0,100,0), -- 12:02:17
(@PATH,3,7943.628,-2882.781,1133.216,0,0,0,0,100,0), -- 12:02:17
(@PATH,4,7927.119,-2913.68,1135.113,0,0,0,0,100,0), -- 12:02:17
(@PATH,5,7926.772,-2914.314,1135.204,0,0,0,0,100,0), -- 12:02:17
(@PATH,6,7928.581,-2928.274,1138.02,0,0,0,0,100,0), -- 12:02:18
(@PATH,7,7931.831,-2954.774,1138.77,0,0,0,0,100,0), -- 12:02:18
(@PATH,8,7937.19,-2978.99,1139.8,0,0,0,0,100,0), -- 12:02:23
(@PATH,9,7938.92,-2983.871,1138.668,0,0,0,0,100,0), -- 12:02:26
(@PATH,10,7944.67,-2987.621,1137.918,0,0,0,0,100,0), -- 12:02:26
(@PATH,11,7971.077,-2990.12,1138.138,0,0,0,0,100,0), -- 12:02:27
(@PATH,12,7992.952,-2975.797,1142.036,0,0,0,0,100,0), -- 12:02:29
(@PATH,13,7988.995,-2947.633,1138.8,0,0,0,0,100,0), -- 12:02:32
(@PATH,14,7980.995,-2897.633,1138.05,0,0,0,0,100,0), -- 12:02:32
(@PATH,15,7969.358,-2887.465,1135.122,0,0,0,0,100,0), -- 12:02:40
(@PATH,16,7965.608,-2886.215,1134.622,0,0,0,0,100,0); -- 12:02:40
-- 0x20197C47601DBBC00000360000082C9B .go 7959.272 -2884.071 1133.766

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+15;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@CGUID+15, @CGUID+15, 0, 0, 2, 0, 0),
(@CGUID+15, @CGUID+20, 8, 40, 2, 0, 0),
(@CGUID+15, @CGUID+18, 8, 320, 2, 0, 0),
(@CGUID+15, @CGUID+19, 12, 350, 2, 0, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Correction due to double spawn
DELETE FROM `creature` WHERE `guid` IN (@CGUID+2, @CGUID+0, @CGUID+1, 4109225, @CGUID+4, @CGUID+3, @CGUID+24, @CGUID+23, @CGUID+22);

-- Pathing number: 3
SET @NPC := @CGUID+5;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8051.368,`position_y`=-2880.661,`position_z`=1137.401 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8051.368,-2880.661,1137.401,0,0,0,0,100,0), -- 12:02:18
(@PATH,2,8021.453,-2879.533,1138.375,0,0,0,0,100,0), -- 12:02:18
(@PATH,3,8024.834,-2845.973,1137.817,0,0,0,0,100,0), -- 12:02:22
(@PATH,4,8034.395,-2834.992,1136.481,0,0,0,0,100,0), -- 12:02:28
(@PATH,5,8050.562,-2843.835,1138.347,0,0,0,0,100,0), -- 12:02:28
(@PATH,6,8069.586,-2844.144,1139.139,0,0,0,0,100,0), -- 12:02:28
(@PATH,7,8090.448,-2841.569,1137.427,0,0,0,0,100,0), -- 12:02:29
(@PATH,8,8106.995,-2820.623,1135.879,0,0,0,0,100,0), -- 12:02:30
(@PATH,9,8119.745,-2800.373,1135.379,0,0,0,0,100,0), -- 12:02:30
(@PATH,10,8138.245,-2772.123,1133.379,0,0,0,0,100,0), -- 12:02:30
(@PATH,11,8142.495,-2765.373,1134.129,0,0,0,0,100,0), -- 12:02:30
(@PATH,12,8079.229,-2834.587,1140.444,0,0,0,0,100,0), -- 12:03:08
(@PATH,13,8066.808,-2855.118,1139.602,0,0,0,0,100,0), -- 12:03:08
(@PATH,14,8054.387,-2875.648,1138.759,0,0,0,0,100,0); -- 12:03:08
-- 0x20197C47601DBBC00000360000882C98 .go 8051.368 -2880.661 1137.401

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 4
SET @NPC := @CGUID+16;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7921.855,`position_y`=-2890.884,`position_z`=1136.076 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7921.855,-2890.884,1136.076,0,0,0,0,100,0), -- 12:02:17
(@PATH,2,7926.714,-2889.713,1135.441,0,0,0,0,100,0), -- 12:02:17
(@PATH,3,7953.922,-2883.15,1132.966,0,0,0,0,100,0), -- 12:02:17
(@PATH,4,7973.296,-2878.474,1133.51,0,0,0,0,100,0), -- 12:02:17
(@PATH,5,7973.296,-2878.474,1133.51,0,0,0,0,100,0), -- 12:02:17
(@PATH,6,7965.624,-2887.631,1134.884,0,0,0,0,100,0), -- 12:02:18
(@PATH,7,7950.446,-2905.34,1132.723,0,0,0,0,100,0), -- 12:02:22
(@PATH,8,7947.196,-2900.09,1133.223,0,0,0,0,100,0), -- 12:02:22
(@PATH,9,7932.196,-2875.34,1135.723,0,0,0,0,100,0), -- 12:02:22
(@PATH,10,7929.696,-2871.09,1134.973,0,0,0,0,100,0), -- 12:02:22
(@PATH,11,7920.696,-2855.59,1131.223,0,0,0,0,100,0), -- 12:02:22
(@PATH,12,7906.196,-2831.84,1134.473,0,0,0,0,100,0), -- 12:02:22
(@PATH,13,7945.347,-2848.239,1134.082,0,0,0,0,100,0), -- 12:02:43
(@PATH,14,7936.322,-2868.307,1132.716,0,0,0,0,100,0), -- 12:02:43
(@PATH,15,7933.041,-2875.604,1135.305,0,0,0,0,100,0), -- 12:02:43
(@PATH,16,7926.714,-2889.713,1135.441,0,0,0,0,100,0); -- 12:02:43
-- 0x20197C47601DBBC00000360004082C9B .go 7921.855 -2890.884 1136.076

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 5 
SET @NPC := @CGUID+26;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8199.652,`position_y`=-2742.033,`position_z`=1139.912 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=8199.652,`position_y`=-2742.033,`position_z`=1139.912 WHERE `guid` IN (@CGUID+28, @CGUID+27, @CGUID+25);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8199.652,-2742.033,1139.912,0,0,0,0,100,0),
(@PATH,2,8204.902,-2732.283,1139.662,0,0,0,0,100,0),
(@PATH,3,8195.85,-2693.724,1139.285,0,0,0,0,100,0),
(@PATH,4,8192.6,-2684.224,1140.785,0,0,0,0,100,0),
(@PATH,5,8183.967,-2644.339,1145.626,0,0,0,0,100,0),
(@PATH,6,8171.217,-2626.589,1144.626,0,0,0,0,100,0),
(@PATH,7,8169.967,-2625.339,1143.876,0,0,0,0,100,0),
(@PATH,8,8167.467,-2623.339,1143.126,0,0,0,0,100,0),
(@PATH,9,8164.467,-2621.089,1142.376,0,0,0,0,100,0),
(@PATH,10,8169.626,-2625.322,1143.746,0,0,0,0,100,0),
(@PATH,11,8143.126,-2650.072,1141.496,0,0,0,0,100,0),
(@PATH,12,8125.481,-2670.997,1138.142,0,0,0,0,100,0),
(@PATH,13,8114.144,-2701.983,1134.236,0,0,0,0,100,0),
(@PATH,14,8106.629,-2720.342,1133.888,0,0,0,0,100,0),
(@PATH,15,8103.292,-2744.693,1135.751,0,0,0,0,100,0),
(@PATH,16,8120.627,-2767.206,1134.296,0,0,0,0,100,0),
(@PATH,17,8135.127,-2769.956,1133.796,0,0,0,0,100,0),
(@PATH,18,8155.579,-2773.56,1136.645,0,0,0,0,100,0),
(@PATH,19,8168.493,-2773.339,1137.527,0,0,0,0,100,0),
(@PATH,20,8177.993,-2773.339,1137.527,0,0,0,0,100,0),
(@PATH,21,8184.493,-2766.089,1138.027,0,0,0,0,100,0);
-- 0x20197C47601DBBC00000360001082C98 .go 8199.652 -2742.033 1139.912

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+26;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@CGUID+26, @CGUID+26, 0, 0, 2, 0, 0),
(@CGUID+26, @CGUID+28, 8, 40, 2, 0, 0),
(@CGUID+26, @CGUID+27, 8, 320, 2, 0, 0),
(@CGUID+26, @CGUID+25, 12, 350, 2, 0, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 6
SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8199.652,`position_y`=-2742.033,`position_z`=1139.912 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8199.652,-2742.033,1139.912,0,0,0,0,100,0),
(@PATH,2,8204.902,-2732.283,1139.662,0,0,0,0,100,0),
(@PATH,3,8195.85,-2693.724,1139.285,0,0,0,0,100,0),
(@PATH,4,8192.6,-2684.224,1140.785,0,0,0,0,100,0),
(@PATH,5,8183.967,-2644.339,1145.626,0,0,0,0,100,0),
(@PATH,6,8171.217,-2626.589,1144.626,0,0,0,0,100,0),
(@PATH,7,8169.967,-2625.339,1143.876,0,0,0,0,100,0),
(@PATH,8,8167.467,-2623.339,1143.126,0,0,0,0,100,0),
(@PATH,9,8164.467,-2621.089,1142.376,0,0,0,0,100,0),
(@PATH,10,8169.626,-2625.322,1143.746,0,0,0,0,100,0),
(@PATH,11,8143.126,-2650.072,1141.496,0,0,0,0,100,0),
(@PATH,12,8125.481,-2670.997,1138.142,0,0,0,0,100,0),
(@PATH,13,8114.144,-2701.983,1134.236,0,0,0,0,100,0),
(@PATH,14,8106.629,-2720.342,1133.888,0,0,0,0,100,0),
(@PATH,15,8103.292,-2744.693,1135.751,0,0,0,0,100,0),
(@PATH,16,8120.627,-2767.206,1134.296,0,0,0,0,100,0),
(@PATH,17,8135.127,-2769.956,1133.796,0,0,0,0,100,0),
(@PATH,18,8155.579,-2773.56,1136.645,0,0,0,0,100,0),
(@PATH,19,8168.493,-2773.339,1137.527,0,0,0,0,100,0),
(@PATH,20,8177.993,-2773.339,1137.527,0,0,0,0,100,0),
(@PATH,21,8184.493,-2766.089,1138.027,0,0,0,0,100,0);
-- 0x20197C47601DBBC00000360001082C98 .go 8199.652 -2742.033 1139.912

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 7
SET @NPC := @CGUID+9;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8190.176,`position_y`=-2817.482,`position_z`=1135.828 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=8190.176,`position_y`=-2817.482,`position_z`=1135.828 WHERE `guid` IN (@CGUID+8, @CGUID+10, @CGUID+6);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8190.176,-2817.482,1135.828,0,0,0,0,100,0),
(@PATH,2,8210.316,-2813.081,1132.71,0,0,0,0,100,0),
(@PATH,3,8225.721,-2793.372,1130.372,0,0,0,0,100,0),
(@PATH,4,8224.471,-2775.622,1131.122,0,0,0,0,100,0),
(@PATH,5,8209.764,-2731.575,1139.488,0,0,0,0,100,0),
(@PATH,6,8201.764,-2725.825,1138.738,0,0,0,0,100,0),
(@PATH,7,8184.014,-2713.325,1137.738,0,0,0,0,100,0),
(@PATH,8,8169.027,-2707.665,1137.048,0,0,0,0,100,0),
(@PATH,9,8148.066,-2747.88,1134.345,0,0,0,0,100,0),
(@PATH,10,8139.816,-2765.88,1133.845,0,0,0,0,100,0),
(@PATH,11,8130.182,-2786.538,1133.636,0,0,0,0,100,0),
(@PATH,12,8131.318,-2815.248,1135.326,0,0,0,0,100,0),
(@PATH,13,8145.969,-2830.457,1136.547,0,0,0,0,100,0),
(@PATH,14,8149.719,-2829.207,1134.797,0,0,0,0,100,0),
(@PATH,15,8169.469,-2822.957,1136.547,0,0,0,0,100,0),
(@PATH,16,8179.646,-2819.907,1136.379,0,0,0,0,100,0);
-- 0x20197C47601DBBC00000360002082C9B .go 8190.176 -2817.482 1135.828

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+9;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@CGUID+9, @CGUID+9, 0, 0, 2, 0, 0),
(@CGUID+9, @CGUID+8, 8, 40, 2, 0, 0),
(@CGUID+9, @CGUID+10, 8, 320, 2, 0, 0),
(@CGUID+9, @CGUID+6, 12, 350, 2, 0, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 8
SET @NPC := @CGUID+13;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8133.842,`position_y`=-2558.543,`position_z`=1140.084 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=8133.842,`position_y`=-2558.543,`position_z`=1140.084 WHERE `guid` IN (@CGUID+11, @CGUID+12, @CGUID+14);  
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8133.842,-2558.543,1140.084,0,0,0,0,100,0),
(@PATH,2,8100.842,-2584.543,1140.834,0,0,0,0,100,0),
(@PATH,3,8082.112,-2588.569,1143.633,0,0,0,0,100,0),
(@PATH,4,8065.112,-2589.569,1143.133,0,0,0,0,100,0),
(@PATH,5,8052.68,-2600.158,1139.012,0,0,0,0,100,0),
(@PATH,6,8048.396,-2606.794,1136.789,0,0,0,0,100,0),
(@PATH,7,8058.987,-2631.079,1135.127,0,0,0,0,100,0),
(@PATH,8,8068.987,-2642.079,1138.377,0,0,0,0,100,0),
(@PATH,9,8086.705,-2661.759,1138.303,0,0,0,0,100,0),
(@PATH,10,8125.165,-2679.654,1136.277,0,0,0,0,100,0),
(@PATH,11,8129.415,-2676.654,1137.277,0,0,0,0,100,0),
(@PATH,12,8153.084,-2651.571,1141.235,0,0,0,0,100,0),
(@PATH,13,8156.834,-2639.071,1142.485,0,0,0,0,100,0),
(@PATH,14,8166.834,-2603.571,1145.235,0,0,0,0,100,0),
(@PATH,15,8175.584,-2573.821,1144.485,0,0,0,0,100,0),
(@PATH,16,8187.084,-2533.571,1137.485,0,0,0,0,100,0),
(@PATH,17,8191.23,-2519.868,1135.488,0,0,0,0,100,0),
(@PATH,18,8169.48,-2530.118,1136.238,0,0,0,0,100,0),
(@PATH,19,8137.485,-2554.561,1139.413,0,0,0,0,100,0);
-- 0x20197C47601DBBC00000360001882C98 .go 8133.842 -2558.543 1140.084

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+13;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@CGUID+13, @CGUID+13, 0, 0, 2, 0, 0),
(@CGUID+13, @CGUID+11, 8, 40, 2, 0, 0),
(@CGUID+13, @CGUID+12, 8, 320, 2, 0, 0),
(@CGUID+13, @CGUID+14, 12, 350, 2, 0, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Pathing number: 
SET @NPC := @CGUID+21;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7896.452,`position_y`=-2693.872,`position_z`=1136.874 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7896.452,-2693.872,1136.874,0,0,0,0,100,0), -- 12:03:13
(@PATH,2,7889.518,-2717.896,1136.447,0,0,0,0,100,0), -- 12:03:13
(@PATH,3,7884.905,-2733.918,1136.344,0,0,0,0,100,0), -- 12:03:13
(@PATH,4,7884.905,-2733.918,1136.344,0,0,0,0,100,0), -- 12:03:13
(@PATH,5,7891.485,-2710.798,1136.346,0,0,0,0,100,0), -- 12:03:24
(@PATH,6,7900.502,-2688.753,1137.718,0,0,0,0,100,0), -- 12:03:45
(@PATH,7,7903.752,-2682.753,1138.468,0,0,0,0,100,0), -- 12:03:45
(@PATH,8,7907.002,-2676.753,1138.968,0,0,0,0,100,0), -- 12:03:45
(@PATH,9,7913.202,-2665.231,1139.857,0,0,0,0,100,0), -- 12:05:37
(@PATH,10,7909.39,-2672.262,1139.156,0,0,0,0,100,0), -- 12:05:37
(@PATH,11,7905.577,-2679.293,1138.454,0,0,0,0,100,0), -- 12:05:37
(@PATH,12,7902.241,-2685.445,1137.829,0,0,0,0,100,0), -- 12:05:37
(@PATH,13,7899.382,-2690.719,1137.282,0,0,0,0,100,0); -- 12:05:37
-- 0x20197C47601DBC000000360000082C98 .go 7896.452 -2693.872 1136.874

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;
