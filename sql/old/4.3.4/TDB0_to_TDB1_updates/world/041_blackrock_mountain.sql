SET @OGUID := 326;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+23;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179879, 0, 1, 1, -7662.91, -1218.73, 287.788, 5.846854, 0, 0, 0, 1, 120, 255, 1), -- Orb of Command (Area: -Unknown-)
(@OGUID+1, 126339, 0, 1, 1, -7543, -1285.665, 301.3497, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126339 (Area: -Unknown-)
(@OGUID+2, 202832, 0, 1, 1, -7552.207, -1251.161, 482.7735, 0.3503397, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+3, 202829, 0, 1, 1, -7541.576, -1188.689, 478.5922, 5.062729, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+4, 202823, 0, 1, 1, -7541.576, -1188.689, 478.5922, 5.062729, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+5, 202827, 0, 1, 1, -7541.576, -1188.689, 478.5922, 5.062729, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+6, 202825, 0, 1, 1, -7541.576, -1188.689, 478.5922, 5.062729, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+7, 126341, 0, 1, 1, -7524.319, -1293.104, 296.6364, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126341 (Area: -Unknown-)
(@OGUID+8, 126340, 0, 1, 1, -7522.605, -1274.593, 296.6364, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126340 (Area: -Unknown-)
(@OGUID+9, 205566, 0, 1, 1, -7520.001, -1285.747, 477.8941, 3.38993, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+10, 179584, 0, 1, 1, -7590.697, -1139.77, 260.6799, 3.516848, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Meeting Stone (Area: -Unknown-)
(@OGUID+11, 126345, 0, 1, 1, -7534.016, -1316.827, 289.9157, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126345 (Area: -Unknown-)
(@OGUID+12, 179585, 0, 1, 1, -7625.354, -1226.51, 231.7755, 3.510568, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Meeting Stone (Area: -Unknown-)
(@OGUID+13, 204857, 0, 1, 1, -7570.299, -1329.835, 246.7333, 1.692969, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+14, 204858, 0, 1, 1, -7570.299, -1329.835, 246.7333, 1.692969, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+15, 126342, 0, 1, 1, -7517.619, -1338.702, 291.7721, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126342 (Area: -Unknown-)
(@OGUID+16, 126313, 0, 1, 1, -7543.08, -1272.846, 273.1511, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Bonfire (Area: -Unknown-)
(@OGUID+17, 126335, 0, 1, 1, -7576.996, -1296.622, 245.5172, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Bonfire (Area: -Unknown-)
(@OGUID+18, 126314, 0, 1, 1, -7543.867, -1274.216, 250.3917, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Bonfire (Area: -Unknown-)
(@OGUID+19, 126337, 0, 1, 1, -7579.472, -1269.678, 301.3497, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126337 (Area: 0)
(@OGUID+20, 126312, 0, 1, 1, -7588.212, -1286.623, 244.8108, 3.262118, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+21, 126338, 0, 1, 1, -7586.381, -1285.8, 301.3497, 3.263772, 0, 0, 0.9981348, -0.0610486, 120, 255, 1), -- 126338 (Area: 0)
(@OGUID+22, 207328, 0, 1, 1, -7550.783, -1307.545, 249.7316, 4.485497, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+23, 207303, 0, 1, 1, -8071.538, -998.9653, 133.0455, 5.270896, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: 0)

UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=9699; -- Fire Beetle
UPDATE `creature_template` SET `minlevel`=51, `maxlevel`=52, `faction_A`=103, `faction_H`=103, `speed_walk`=2.857143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555264, `HoverHeight`=1 WHERE `entry`=8964; -- Blackrock Drake
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=56, `faction_A`=40, `faction_H`=40, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=9044; -- Scarshield Sentry
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=56, `faction_A`=40, `faction_H`=40, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=9043; -- Scarshield Grunt
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `gossip_menu_id`=5750, `minlevel`=60, `maxlevel`=60, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=14387; -- Lothos Riftwaker
UPDATE `creature_template` SET `minlevel`=46, `maxlevel`=48, `faction_A`=15, `faction_H`=15, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `HoverHeight`=1 WHERE `entry`=8917; -- Quarry Slave
UPDATE `creature_template` SET `minlevel`=49, `maxlevel`=50, `faction_A`=54, `faction_H`=54, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=24819; -- Anvilrage Enforcer
UPDATE `creature_template` SET `minlevel`=48, `maxlevel`=49, `faction_A`=54, `faction_H`=54, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1667, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=24818; -- Anvilrage Taskmaster
UPDATE `creature_template` SET `minlevel`=56, `maxlevel`=56, `faction_A`=40, `faction_H`=40, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=9046; -- Scarshield Quartermaster
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction_A`=54, `faction_H`=54, `speed_walk`=1.142857, `speed_run`=0.666668, `baseattacktime`=2800, `rangeattacktime`=2000, `unit_flags`=64, `HoverHeight`=1 WHERE `entry`=8924; -- The Behemoth
UPDATE `creature_template` SET `minlevel`=51, `maxlevel`=51, `faction_A`=91, `faction_H`=91, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1600, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=64, `HoverHeight`=1 WHERE `entry`=9026; -- Overmaster Pyron
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `faction_A`=575, `faction_H`=575, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=5858; -- Greater Lava Spider
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=42173; -- The Undershell Tentacle Flavor
UPDATE `creature_template` SET `faction_A`=31, `faction_H`=31, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=9700; -- Lava Crab


DELETE FROM `creature_template_addon` WHERE `entry` IN (9699, 8964, 9699, 9044, 9044, 9699, 9699, 9699, 9699, 9699, 9699, 9699, 8964, 9699, 9044, 9044, 9699, 9699, 9699, 9699, 9044, 9699, 9043, 9699, 9699, 9044, 9043, 32520, 32520, 32520, 32520, 9699, 9699, 9699, 14387, 9699, 9699, 9699, 9699, 8917, 8917, 9699, 8917, 8917, 9699, 24819, 9699, 8917, 8917, 8917, 24818, 24819, 9044, 9044, 9044, 9044, 9699, 9044, 9043, 9699, 9046, 9699, 9699, 8917, 9699, 9699, 8917, 8917, 9699, 9699, 24818, 24819, 8917, 9699, 9699, 24819, 8924, 8917, 9699, 24819, 9699, 8917, 9699, 8917, 8917, 8917, 24819, 8917, 24818, 9699, 24819, 9699, 24819, 24819, 24818, 9699, 8917, 8917, 24818, 9699, 9699, 24819, 8917, 8917, 8917, 9699, 9699, 8917, 8917, 8917, 8917, 24818, 24819, 24819, 9699, 8917, 8917, 8917, 9699, 9699, 9699, 24819, 24818, 24818, 9026, 24818, 24819, 9699, 9699, 24818, 9699, 9699, 9699, 9699, 24818, 24819, 24819, 5858, 42173, 8917, 8917, 9700, 32520, 32520, 32520, 32520);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(9699, 0, 0x0, 0x1, ''), -- Fire Beetle
(8964, 0, 0x0, 0x1, ''), -- Blackrock Drake
(9044, 0, 0x0, 0x1, ''), -- Scarshield Sentry
(9043, 0, 0x0, 0x1, ''), -- Scarshield Grunt
-- (9043, 0, 0x1, 0x1, ''), -- Scarshield Grunt
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(14387, 0, 0x0, 0x1, ''), -- Lothos Riftwaker
(8917, 0, 0x0, 0x1, ''), -- Quarry Slave
(24819, 0, 0x0, 0x1, '3417'), -- Anvilrage Enforcer - Thrash
(24818, 0, 0x0, 0x1, '13589'), -- Anvilrage Taskmaster - Haste Aura
(9046, 0, 0x0, 0x1, ''), -- Scarshield Quartermaster
(8924, 0, 0x0, 0x1, '742'), -- The Behemoth - Pulverize
(9026, 0, 0x0, 0x1, ''), -- Overmaster Pyron
(5858, 0, 0x0, 0x1, '11984'), -- Greater Lava Spider - Immolate
(42173, 0, 0x0, 0x1, ''), -- The Undershell Tentacle Flavor
(9700, 0, 0x0, 0x1, ''); -- Lava Crab


-- `creature_model_info` has empty data.
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=487;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=2 WHERE `modelid`=1070;
UPDATE `creature_model_info` SET `bounding_radius`=0.1, `combat_reach`=0.125 WHERE `modelid`=5560;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=3 WHERE `modelid`=6374;
UPDATE `creature_model_info` SET `bounding_radius`=0.759, `combat_reach`=1.4375 WHERE `modelid`=7510;
UPDATE `creature_model_info` SET `bounding_radius`=2.25, `combat_reach`=2.25, `gender`=0 WHERE `modelid`=8390;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=8754;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=8758;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=8891;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=8892;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=8893;
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=8899;
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=8900;
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=8901;
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=9599;
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=9606;
UPDATE `creature_model_info` SET `bounding_radius`=0.2832, `combat_reach`=1.8, `gender`=1 WHERE `modelid`=9861;
UPDATE `creature_model_info` SET `bounding_radius`=0.2832, `combat_reach`=1.8, `gender`=1 WHERE `modelid`=9862;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=21009;

SET @CGUID := 2361;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+145;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 9699, 0, 1, 1, -7661.595, -1211.16, 224.2943, 5.743092, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+1, 8964, 0, 1, 1, -7563.523, -1206.015, 290.6637, 0.2854751, 120, 0, 0), -- Blackrock Drake (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+2, 9699, 0, 1, 1, -7537.819, -1296.795, 260.3813, 4.927681, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+3, 9044, 0, 1, 1, -7540.205, -1274.36, 273.2353, 5.550147, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+4, 9044, 0, 1, 1, -7532.288, -1277.221, 250.5509, 2.478368, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-)
(@CGUID+5, 9699, 0, 1, 1, -7546.008, -1298.105, 302.0706, 4.986882, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+6, 9699, 0, 1, 1, -7501.794, -1281.313, 296.5462, 4.390477, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+7, 9699, 0, 1, 1, -7506.232, -1299.8, 296.5628, 0.7018205, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+8, 9699, 0, 1, 1, -7520.262, -1269.339, 296.847, 3.640296, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+9, 9699, 0, 1, 1, -7527.635, -1305.28, 261.6013, 3.227088, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+10, 9699, 0, 1, 1, -7555.226, -1132.056, 258.6472, 5.577262, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+11, 9699, 0, 1, 1, -7576.792, -1124.93, 262.3647, 0.4728007, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+12, 8964, 0, 1, 1, -7574.527, -1127.818, 302.1821, 3.184136, 120, 0, 0), -- Blackrock Drake (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+13, 9699, 0, 1, 1, -7568.909, -1313.173, 245.5356, 3.19397, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+14, 9044, 0, 1, 1, -7655.125, -1227.002, 287.7397, 5.969026, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-)
(@CGUID+15, 9044, 0, 1, 1, -7652.354, -1221.21, 287.6708, 5.637414, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-)
(@CGUID+16, 9699, 0, 1, 1, -7576.314, -1313.727, 245.5325, 4.851468, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+17, 9699, 0, 1, 1, -7511.281, -1335.825, 302.4253, 3.252525, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+18, 9699, 0, 1, 1, -7557.864, -1274.702, 249.1118, 6.016164, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+19, 9699, 0, 1, 1, -7553.553, -1285.031, 273.8579, 6.049248, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+20, 9044, 0, 1, 1, -7543.941, -1280.48, 273.2399, 0.3665192, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+21, 9699, 0, 1, 1, -7565.168, -1277.174, 245.5409, 3.263801, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+22, 9043, 0, 1, 1, -7534.646, -1274.3, 250.5517, 5.026548, 120, 0, 0), -- Scarshield Grunt (Area: -Unknown-)
(@CGUID+23, 9699, 0, 1, 1, -7492.958, -1351.62, 296.602, 4.41391, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+24, 9699, 0, 1, 1, -7620.26, -1256.109, 235.7785, 2.322333, 120, 0, 0), -- Fire Beetle (Area: -Unknown-)
(@CGUID+25, 9044, 0, 1, 1, -7552.641, -1239.985, 285.4039, 5.375614, 120, 0, 0), -- Scarshield Sentry (Area: -Unknown-)
(@CGUID+26, 9043, 0, 1, 1, -7549.878, -1243.629, 285.4411, 2.583087, 120, 0, 0), -- Scarshield Grunt (Area: -Unknown-)
(@CGUID+27, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: -Unknown-)
(@CGUID+28, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: -Unknown-)
(@CGUID+29, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: -Unknown-)
(@CGUID+30, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: -Unknown-)
(@CGUID+31, 9699, 0, 1, 1, -7581.768, -1296.71, 301.257, 3.447615, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+32, 9699, 0, 1, 1, -7583.089, -1118.95, 263.1417, 3.173699, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+33, 9699, 0, 1, 1, -7496.645, -1117.685, 265.6068, 1.911903, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+34, 14387, 0, 1, 1, -7508.632, -1039.495, 180.9942, 3.717551, 120, 0, 0), -- Lothos Riftwaker (Area: 0)
(@CGUID+35, 9699, 0, 1, 1, -7591.145, -1003.388, 246.6307, 0.02451351, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+36, 9699, 0, 1, 1, -7499.43, -1046.407, 182.0213, 0.2521345, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+37, 9699, 0, 1, 1, -7693.29, -1135.462, 215.2823, 1.620808, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+38, 9699, 0, 1, 1, -7479.942, -1038.143, 177.6227, 4.110557, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+39, 8917, 0, 1, 1, -7468.061, -980.5121, 155.8826, 1.082104, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+40, 8917, 0, 1, 1, -7466.736, -1002.316, 117.2894, 3.403392, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+41, 9699, 0, 1, 1, -7466.649, -1016.354, 172.6921, 1.519387, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+42, 8917, 0, 1, 1, -7438.753, -933.619, 172.1145, 3.368485, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+43, 8917, 0, 1, 1, -7445.624, -975.4891, 171.9754, 2.687807, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+44, 9699, 0, 1, 1, -7440.797, -1000.687, 170.778, 4.427208, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+45, 24819, 0, 1, 1, -7452.227, -1018.257, 171.7792, 5.119071, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+46, 9699, 0, 1, 1, -7440.323, -996.3292, 170.722, 6.164865, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+47, 8917, 0, 1, 1, -7471.422, -927.5989, 131.9955, 4.660029, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+48, 8917, 0, 1, 1, -7477.865, -916.0174, 107.3892, 4.153883, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+49, 8917, 0, 1, 1, -7456.123, -925.0607, 171.3239, 5.026548, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+50, 24818, 0, 1, 1, -7453.741, -919.4227, 170.9079, 3.124139, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+51, 24819, 0, 1, 1, -7456.648, -920.804, 171.1413, 0.7504916, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+52, 9044, 0, 1, 1, -7578.502, -1240.42, 284.8457, 4.537856, 120, 0, 0), -- Scarshield Sentry (Area: 0)
(@CGUID+53, 9044, 0, 1, 1, -7584.25, -1241.369, 284.8457, 5.166174, 120, 0, 0), -- Scarshield Sentry (Area: 0)
(@CGUID+54, 9044, 0, 1, 1, -7579.887, -1280.516, 245.6049, 3.124139, 120, 0, 0), -- Scarshield Sentry (Area: 0)
(@CGUID+55, 9044, 0, 1, 1, -7585.463, -1284.789, 245.3938, 2.775074, 120, 0, 0), -- Scarshield Sentry (Area: 0)
(@CGUID+56, 9699, 0, 1, 1, -7580.237, -1284.763, 245.5297, 3.540309, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+57, 9044, 0, 1, 1, -7575.958, -1279.524, 278.2722, 4.660029, 120, 0, 0), -- Scarshield Sentry (Area: 0)
(@CGUID+58, 9043, 0, 1, 1, -7576.59, -1282.923, 278.2698, 1.22173, 120, 0, 0), -- Scarshield Grunt (Area: 0)
(@CGUID+59, 9699, 0, 1, 1, -7552.941, -1280.112, 273.1621, 0.870346, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+60, 9046, 0, 1, 1, -7575.142, -1289.985, 278.2585, 1.675516, 120, 0, 0), -- Scarshield Quartermaster (Area: 0)
(@CGUID+61, 9699, 0, 1, 1, -7576.99, -1287.83, 278.1942, 4.850388, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+62, 9699, 0, 1, 1, -7571.746, -1292.547, 301.2758, 0.9627028, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+63, 8917, 0, 1, 1, -7433.471, -1049.259, 177.5151, 5.375614, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+64, 9699, 0, 1, 1, -7400.408, -1040.586, 176.409, 5.117342, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+65, 9699, 0, 1, 1, -7415.566, -1030.126, 175.9231, 3.558079, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+66, 8917, 0, 1, 1, -7386.417, -1057.578, 177.6167, 3.752458, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+67, 8917, 0, 1, 1, -7395.854, -1051.482, 177.6406, 4.939282, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+68, 9699, 0, 1, 1, -7401.441, -1041.946, 176.5525, 0.7484384, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+69, 9699, 0, 1, 1, -7418.566, -1006.922, 173.72, 1.913898, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+70, 24818, 0, 1, 1, -7399.051, -999.9252, 175.71, 2.252406, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+71, 24819, 0, 1, 1, -7384.18, -1037.236, 176.8041, 1.921096, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+72, 8917, 0, 1, 1, -7423.083, -961.6693, 173.4986, 2.897247, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+73, 9699, 0, 1, 1, -7366.366, -984.8271, 170.1047, 0.962015, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+74, 9699, 0, 1, 1, -7431.267, -934.2838, 171.1363, 5.541753, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+75, 24819, 0, 1, 1, -7396.445, -940.2507, 169.8431, 1.414957, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 8924, 0, 1, 1, -7397.218, -957.259, 170.1512, 4.711198, 120, 0, 0), -- The Behemoth (Area: 0) (possible waypoints or random movement)
(@CGUID+77, 8917, 0, 1, 1, -7431.536, -912.5192, 171.7739, 0.8901179, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+78, 9699, 0, 1, 1, -7446.249, -908.6053, 170.4099, 5.357067, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+79, 24819, 0, 1, 1, -7450.423, -906.2993, 170.5729, 0.6156276, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+80, 9699, 0, 1, 1, -7424.024, -924.9653, 169.5136, 2.671654, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+81, 8917, 0, 1, 1, -7369.12, -1058.189, 178.8194, 3.804818, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+82, 9699, 0, 1, 1, -7376.41, -1047.751, 178.2131, 2.599147, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+83, 8917, 0, 1, 1, -7352.283, -1045.893, 180.0448, 4.939282, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+84, 8917, 0, 1, 1, -7340.096, -1025.45, 179.6449, 4.39823, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+85, 8917, 0, 1, 1, -7351.241, -970.9822, 171.1597, 1.902409, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+86, 24819, 0, 1, 1, -7341.181, -1023.781, 179.2816, 3.857178, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+87, 8917, 0, 1, 1, -7365.058, -965.9848, 170.7958, 0.2268928, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+88, 24818, 0, 1, 1, -7344.472, -1025.825, 179.5788, 0.418879, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+89, 9699, 0, 1, 1, -7351.328, -1032.369, 179.6243, 1.510955, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+90, 24819, 0, 1, 1, -7354.43, -1021.288, 178.2374, 2.383284, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+91, 9699, 0, 1, 1, -7341.141, -1017.876, 178.1116, 1.15803, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+92, 24819, 0, 1, 1, -7354.96, -985.0818, 170.8784, 2.242296, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+93, 24819, 0, 1, 1, -7331.127, -988.8091, 173.675, 0.7679449, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+94, 24818, 0, 1, 1, -7328.854, -986.5788, 173.5029, 3.944444, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+95, 9699, 0, 1, 1, -7424.301, -896.4681, 172.7056, 1.315866, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+96, 8917, 0, 1, 1, -7424.382, -904.4178, 172.9483, 4.468043, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+97, 8917, 0, 1, 1, -7385, -902.7553, 168.4978, 1.151917, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+98, 24818, 0, 1, 1, -7438.765, -891.5178, 172.0002, 3.277164, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+99, 9699, 0, 1, 1, -7377.529, -924.0582, 167.6081, 3.249786, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+100, 9699, 0, 1, 1, -7359.967, -920.3131, 166.9394, 4.74945, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+101, 24819, 0, 1, 1, -7359.503, -926.1163, 166.8215, 1.331448, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+102, 8917, 0, 1, 1, -7324.448, -1009.387, 178.0016, 1.675516, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+103, 8917, 0, 1, 1, -7327.971, -967.319, 173.4521, 1.134464, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+104, 8917, 0, 1, 1, -7326.047, -994.3331, 175.0614, 4.782202, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+105, 9699, 0, 1, 1, -7327.243, -968.8354, 173.4667, 0.2009416, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+106, 9699, 0, 1, 1, -7424.335, -886.7401, 172.5172, 3.465026, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+107, 8917, 0, 1, 1, -7445.857, -877.988, 171.7987, 2.6529, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+108, 8917, 0, 1, 1, -7388.935, -873.7259, 171.7251, 5.759586, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+109, 8917, 0, 1, 1, -7356.387, -898.9631, 168.8111, 2.740167, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+110, 8917, 0, 1, 1, -7460.208, -881.1481, 172.4284, 1.151917, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+111, 24818, 0, 1, 1, -7425.082, -873.4043, 173.7625, 3.926991, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+112, 24819, 0, 1, 1, -7427.552, -877.0044, 173.3016, 1.151917, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+113, 24819, 0, 1, 1, -7409.873, -885.0193, 171.6812, 0.3756322, 120, 0, 0), -- Anvilrage Enforcer (Area: 0) (possible waypoints or random movement)
(@CGUID+114, 9699, 0, 1, 1, -7461.552, -888.2417, 172.2684, 5.238482, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+115, 8917, 0, 1, 1, -7435.088, -869.5609, 176.1553, 2.513274, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+116, 8917, 0, 1, 1, -7411.068, -863.7253, 173.0363, 2.199115, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+117, 8917, 0, 1, 1, -7382.351, -868.261, 179.2484, 5.899213, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+118, 9699, 0, 1, 1, -7297.062, -939.0278, 165.3008, 3.185455, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+119, 9699, 0, 1, 1, -7275.555, -883.3321, 165.5264, 3.122212, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+120, 9699, 0, 1, 1, -7280.067, -883.282, 165.7647, 3.14009, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+121, 24819, 0, 1, 1, -7280.331, -879.17, 169.6282, 0.03490658, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+122, 24818, 0, 1, 1, -7276.638, -879.5872, 170.0563, 2.844887, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+123, 24818, 0, 1, 1, -7286.057, -911.9608, 165.3817, 5.534343, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+124, 9026, 0, 1, 1, -7281.414, -889.6945, 168.7037, 3.313451, 120, 0, 0), -- Overmaster Pyron (Area: 0) (possible waypoints or random movement)
(@CGUID+125, 24818, 0, 1, 1, -7248.038, -941.054, 168.3617, 1.291544, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+126, 24819, 0, 1, 1, -7246.876, -938.2266, 168.3982, 4.24115, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+127, 9699, 0, 1, 1, -7230.712, -896.1061, 165.3776, 3.470593, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+128, 9699, 0, 1, 1, -7230.284, -897.1263, 165.3776, 3.759177, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+129, 24818, 0, 1, 1, -7240.603, -905.8966, 165.3776, 4.52946, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+130, 9699, 0, 1, 1, -7221.366, -932.8096, 165.9159, 3.338732, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+131, 9699, 0, 1, 1, -7220.038, -889.5518, 165.3767, 4.852709, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+132, 9699, 0, 1, 1, -7192.445, -910.2615, 165.4658, 2.849634, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+133, 9699, 0, 1, 1, -7197.886, -895.9125, 165.4893, 5.733872, 120, 0, 0), -- Fire Beetle (Area: 0)
(@CGUID+134, 24818, 0, 1, 1, -7179.414, -881.2792, 164.0213, 2.042035, 120, 0, 0), -- Anvilrage Taskmaster (Area: 0)
(@CGUID+135, 24819, 0, 1, 1, -7184.782, -877.6999, 164.0213, 5.864306, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+136, 24819, 0, 1, 1, -7181.056, -875.744, 164.0213, 4.939282, 120, 0, 0), -- Anvilrage Enforcer (Area: 0)
(@CGUID+137, 5858, 0, 1, 1, -7214.143, -964.8126, 244.659, 2.359921, 120, 0, 0), -- Greater Lava Spider (Area: 0)
(@CGUID+138, 42173, 0, 1, 1, -6230.174, 6798.166, -1075.454, 6.143559, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: 0)
(@CGUID+139, 8917, 0, 1, 1, -7342.71, -1044.403, 180.4342, 4.433136, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+140, 8917, 0, 1, 1, -7322.717, -1026.879, 181.0208, 2.86234, 120, 0, 0), -- Quarry Slave (Area: 0)
(@CGUID+141, 9700, 0, 1, 1, -7678.292, -1330.081, 123.7707, 2.321288, 120, 0, 0), -- Lava Crab (Area: 0)
(@CGUID+142, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+143, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+144, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+145, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0); -- Totally Generic Bunny (All Phase) (Area: 0)


DELETE FROM `npc_text` WHERE `ID`=6933;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(6933, 'The fabric of which our world is woven is most delicate. It merely takes some knowledge and the application of said knowledge to tear the fabric. It is thusly that rifts are born. ', '', 0, 1, 1, 1, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 6933


DELETE FROM `gossip_menu_option` WHERE (`menu_id`=5750 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(5750, 0, 0, 'Transport me to the Molten Core, Lothos.', 0, 0, ''); -- Lothos Riftwaker
