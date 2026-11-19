-- 
SET @CGUID:=251504;
SET @OGUID:=235375;
SET @Event:=11;

-- CleanUp
DELETE FROM `creature` WHERE `guid` IN (SELECT `guid` FROM `game_event_creature` WHERE `eventEntry`=@Event) AND `map`=1;
DELETE FROM `gameobject` WHERE `guid` IN (SELECT `guid` FROM `game_event_gameobject` WHERE `eventEntry`=@Event) AND `map`=1;
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1294.821, -4414.814, 26.73391, 1.338571, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+1 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1295.087, -4430.118, 26.98391, 3.441302, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+2 , 15012, 1, 14, 4982, 1, 0, 0, 0, 0, 1275.997, -4407.875, 26.45633, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+3 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1277.591, -4409.775, 26.49831, 4.950744, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+4 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1294.211, -4410.554, 26.60891, 4.162745, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+5 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1286.224, -4406.192, 26.60891, 4.669778, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+6 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1302.648, -4424.693, 25.9701, 5.108256, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+7 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1273.59, -4415.275, 26.23391, 3.741375, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+8 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1284.849, -4440.306, 27.60445, 0.9043835, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+9 , 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1273.67, -4428.447, 26.77223, 1.096001, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+10, 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1295.626, -4436.921, 27.19735, 4.991863, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+11, 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1270.057, -4423.686, 26.63869, 0.4488501, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566), -- (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+12, 15115, 1, 14, 4982, 1, 0, 0, 0, 0, 1278.223, -4437.403, 27.11007, 1.13003, 120, 2, 0, 0, 0, 1, 0, 0, 0, 22566); -- (Area: The Dranosh'ar Blockade - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry`=15115;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+1 , 0, 0, 0, 257, 0, 0, 0, 0, ''),
(@CGUID+3 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+4 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+5 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+6 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+7 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+8 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+9 , 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''),
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12 AND `eventEntry`=@Event;
INSERT INTO `game_event_creature` SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+12;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+69;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0 , 180338, 1, 14, 4982, 1, 0, 0, 1292.922, -4419.682, 27.30121, 2.35619, 0, 0, 0.9238787, 0.3826855, 120, 255, 1, 22566), -- Candle 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+1 , 180339, 1, 14, 4982, 1, 0, 0, 1290.866, -4418.693, 27.33226, 3.368496, 0, 0, -0.9935713, 0.1132084, 120, 255, 1, 22566), -- Candle 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+2 , 180340, 1, 14, 4982, 1, 0, 0, 1290.618, -4428.859, 27.58574, 3.68265, 0, 0, -0.9636297, 0.267241, 120, 255, 1, 22566), -- Candle 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+3 , 180338, 1, 14, 4982, 1, 0, 0, 1290.797, -4418.344, 27.33574, 3.752462, 0, 0, -0.9537163, 0.3007079, 120, 255, 1, 22566), -- Candle 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+4 , 180326, 1, 14, 4982, 1, 0, 0, 1290.344, -4429.337, 26.88542, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 22566), -- OrcBench01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+5 , 180370, 1, 14, 4982, 1, 0, 0, 1291.807, -4419.147, 27.36021, 1.989672, 0, 0, 0.8386698, 0.5446402, 120, 255, 1, 22566), -- Harvest Fruit (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+6 , 180374, 1, 14, 4982, 1, 0, 0, 1291.606, -4428.842, 27.62236, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+7 , 180345, 1, 14, 4982, 1, 0, 0, 1290.99, -4428.547, 27.52957, 0.9075702, 0, 0, 0.4383707, 0.8987942, 120, 255, 1, 22566), -- Jar Orc 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+8 , 180349, 1, 14, 4982, 1, 0, 0, 1291.83, -4427.78, 27.49485, 5.480334, 0, 0, -0.3907309, 0.920505, 120, 255, 1, 22566), -- Jar Orc 06 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+9 , 180350, 1, 14, 4982, 1, 0, 0, 1285.28, -4422.219, 26.60764, 4.084071, 0, 0, -0.8910065, 0.4539906, 120, 255, 1, 22566), -- Orc Jug 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+10, 180374, 1, 14, 4982, 1, 0, 0, 1282.764, -4417.128, 27.32108, 4.32842, 0, 0, -0.8290367, 0.5591941, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+11, 180326, 1, 14, 4982, 1, 0, 0, 1290.785, -4418.292, 26.61285, 3.926996, 0, 0, -0.9238787, 0.3826855, 120, 255, 1, 22566), -- OrcBench01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+12, 180374, 1, 14, 4982, 1, 0, 0, 1289.806, -4417.8, 27.37931, 1.780234, 0, 0, 0.7771454, 0.6293211, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+13, 180348, 1, 14, 4982, 1, 0, 0, 1292.273, -4420.01, 27.26779, 4.24115, 0, 0, -0.8526402, 0.5224986, 120, 255, 1, 22566), -- Jar Orc 05 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+14, 180341, 1, 14, 4982, 1, 0, 0, 1291.273, -4418.462, 27.2952, 0.9075702, 0, 0, 0.4383707, 0.8987942, 120, 255, 1, 22566), -- Jar Orc 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+15, 180350, 1, 14, 4982, 1, 0, 0, 1287.122, -4415.644, 26.56771, 3.054327, 0, 0, 0.9990482, 0.04361926, 120, 255, 1, 22566), -- Orc Jug 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+16, 180352, 1, 14, 4982, 1, 0, 0, 1285.396, -4414.597, 26.47974, 0.2967052, 0, 0, 0.147809, 0.9890159, 120, 255, 1, 22566), -- General Torch 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+17, 180374, 1, 14, 4982, 1, 0, 0, 1290.585, -4417.257, 27.37614, 5.654869, 0, 0, -0.3090162, 0.9510568, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+18, 180339, 1, 14, 4982, 1, 0, 0, 1290.444, -4428.497, 27.56664, 4.118979, 0, 0, -0.882947, 0.4694727, 120, 255, 1, 22566), -- Candle 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+19, 180338, 1, 14, 4982, 1, 0, 0, 1281.464, -4417.806, 27.2771, 0.06981169, 0, 0, 0.03489876, 0.9993908, 120, 255, 1, 22566), -- Candle 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+20, 180347, 1, 14, 4982, 1, 0, 0, 1289.646, -4416.979, 27.29173, 2.705255, 0, 0, 0.9762955, 0.2164421, 120, 255, 1, 22566), -- Jar Orc 04 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+21, 180341, 1, 14, 4982, 1, 0, 0, 1282.089, -4417.549, 27.24246, 2.757613, 0, 0, 0.9816265, 0.1908124, 120, 255, 1, 22566), -- Jar Orc 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+22, 180374, 1, 14, 4982, 1, 0, 0, 1293.031, -4420.622, 27.35604, 4.380776, 0, 0, -0.8141155, 0.580703, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+23, 180370, 1, 14, 4982, 1, 0, 0, 1288.974, -4416.073, 27.35717, 5.602507, 0, 0, -0.333807, 0.9426414, 120, 255, 1, 22566), -- Harvest Fruit (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+24, 180340, 1, 14, 4982, 1, 0, 0, 1289.243, -4417.149, 27.32567, 3.298687, 0, 0, -0.9969168, 0.07846643, 120, 255, 1, 22566), -- Candle 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+25, 180347, 1, 14, 4982, 1, 0, 0, 1290.292, -4428.944, 27.55214, 5.462882, 0, 0, -0.3987484, 0.9170604, 120, 255, 1, 22566), -- Jar Orc 04 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+26, 180348, 1, 14, 4982, 1, 0, 0, 1290.5, -4429.438, 27.57993, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 1, 22566), -- Jar Orc 05 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+27, 180350, 1, 14, 4982, 1, 0, 0, 1283.24, -4415.913, 26.54588, 0.8901166, 0, 0, 0.4305105, 0.9025856, 120, 255, 1, 22566), -- Orc Jug 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+28, 180352, 1, 14, 4982, 1, 0, 0, 1294.358, -4424.016, 26.6114, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 22566), -- General Torch 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+29, 180374, 1, 14, 4982, 1, 0, 0, 1281.707, -4416.948, 27.30465, 0.1396245, 0, 0, 0.06975555, 0.9975641, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+30, 180370, 1, 14, 4982, 1, 0, 0, 1292.484, -4426.872, 27.6505, 0.383971, 0, 0, 0.1908083, 0.9816273, 120, 255, 1, 22566), -- Harvest Fruit (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+31, 180352, 1, 14, 4982, 1, 0, 0, 1284.686, -4422.53, 26.61215, 2.809975, 0, 0, 0.9862852, 0.1650499, 120, 255, 1, 22566), -- General Torch 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+32, 180352, 1, 14, 4982, 1, 0, 0, 1276.186, -4423.889, 26.56408, 6.161013, 0, 0, -0.06104851, 0.9981348, 120, 255, 1, 22566), -- General Torch 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+33, 180338, 1, 14, 4982, 1, 0, 0, 1281.063, -4430.611, 27.59973, 5.777041, 0, 0, -0.2503796, 0.9681478, 120, 255, 1, 22566), -- Candle 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+34, 180374, 1, 14, 4982, 1, 0, 0, 1277.151, -4427.215, 27.60263, 1.431168, 0, 0, 0.6560583, 0.7547102, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+35, 180345, 1, 14, 4982, 1, 0, 0, 1279.861, -4428.736, 27.48964, 2.967041, 0, 0, 0.9961939, 0.08716504, 120, 255, 1, 22566), -- Jar Orc 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+36, 180350, 1, 14, 4982, 1, 0, 0, 1286.432, -4431.778, 27.05208, 3.57793, 0, 0, -0.9762955, 0.2164421, 120, 255, 1, 22566), -- Orc Jug 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+37, 180374, 1, 14, 4982, 1, 0, 0, 1279.63, -4419.181, 27.32723, 0.4886912, 0, 0, 0.2419214, 0.9702958, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+38, 180341, 1, 14, 4982, 1, 0, 0, 1281.358, -4431.012, 27.59795, 2.600535, 0, 0, 0.9636297, 0.267241, 120, 255, 1, 22566), -- Jar Orc 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+39, 180374, 1, 14, 4982, 1, 0, 0, 1284.269, -4424.625, 27.56357, 2.967041, 0, 0, 0.9961939, 0.08716504, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+40, 180371, 1, 14, 4982, 1, 0, 0, 1287.998, -4431.903, 27.64334, 3.368496, 0, 0, -0.9935713, 0.1132084, 120, 255, 1, 22566), -- Harvest Fish (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+41, 180345, 1, 14, 4982, 1, 0, 0, 1279.623, -4419.745, 27.26221, 0.8901166, 0, 0, 0.4305105, 0.9025856, 120, 255, 1, 22566), -- Jar Orc 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+42, 180326, 1, 14, 4982, 1, 0, 0, 1279.898, -4429.236, 26.82986, 3.926996, 0, 0, -0.9238787, 0.3826855, 120, 255, 1, 22566), -- OrcBench01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+43, 180347, 1, 14, 4982, 1, 0, 0, 1277.929, -4427.249, 27.4011, 3.769912, 0, 0, -0.9510565, 0.3090171, 120, 255, 1, 22566), -- Jar Orc 04 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+44, 180351, 1, 14, 4982, 1, 0, 0, 1286.563, -4430.677, 26.97743, 3.804818, 0, 0, -0.9455185, 0.3255684, 120, 255, 1, 22566), -- Orc Jug 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+45, 180339, 1, 14, 4982, 1, 0, 0, 1280.024, -4420.028, 27.30576, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 22566), -- Candle 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+46, 180348, 1, 14, 4982, 1, 0, 0, 1280.484, -4429.202, 27.52089, 3.490667, 0, 0, -0.984807, 0.1736523, 120, 255, 1, 22566), -- Jar Orc 05 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+47, 180370, 1, 14, 4982, 1, 0, 0, 1278.816, -4428.393, 27.60247, 2.530723, 0, 0, 0.9537163, 0.3007079, 120, 255, 1, 22566), -- Harvest Fruit (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+48, 180374, 1, 14, 4982, 1, 0, 0, 1277.946, -4426.452, 27.56903, 5.358162, 0, 0, -0.4461975, 0.8949345, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+49, 180341, 1, 14, 4982, 1, 0, 0, 1279.524, -4429.125, 27.51048, 2.094393, 0, 0, 0.866025, 0.5000008, 120, 255, 1, 22566), -- Jar Orc 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+50, 180350, 1, 14, 4982, 1, 0, 0, 1276.879, -4425.889, 26.66493, 5.061456, 0, 0, -0.573576, 0.8191524, 120, 255, 1, 22566), -- Orc Jug 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+51, 180374, 1, 14, 4982, 1, 0, 0, 1278.826, -4419.712, 27.32723, 1.291542, 0, 0, 0.6018143, 0.7986361, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+52, 180339, 1, 14, 4982, 1, 0, 0, 1279.887, -4429.368, 27.56664, 2.844883, 0, 0, 0.9890156, 0.1478114, 120, 255, 1, 22566), -- Candle 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+53, 180348, 1, 14, 4982, 1, 0, 0, 1279.462, -4420.575, 27.27374, 1.256636, 0, 0, 0.5877848, 0.8090174, 120, 255, 1, 22566), -- Jar Orc 05 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+54, 180374, 1, 14, 4982, 1, 0, 0, 1289.837, -4430.799, 27.66272, 4.939284, 0, 0, -0.6225138, 0.7826088, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+55, 180371, 1, 14, 4982, 1, 0, 0, 1278.411, -4421.422, 27.34835, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 22566), -- Harvest Fish (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+56, 180374, 1, 14, 4982, 1, 0, 0, 1289.748, -4429.458, 27.6477, 0.4188786, 0, 0, 0.2079115, 0.9781476, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+57, 180371, 1, 14, 4982, 1, 0, 0, 1282.16, -4430.776, 27.5903, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 22566), -- Harvest Fish (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+58, 180340, 1, 14, 4982, 1, 0, 0, 1278.285, -4427.639, 27.58184, 1.029743, 0, 0, 0.4924231, 0.870356, 120, 255, 1, 22566), -- Candle 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+59, 180374, 1, 14, 4982, 1, 0, 0, 1280.516, -4430.542, 27.5873, 3.211419, 0, 0, -0.9993906, 0.03490613, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+60, 180339, 1, 14, 4982, 1, 0, 0, 1288.965, -4431.116, 27.67178, 5.166176, 0, 0, -0.5299187, 0.8480484, 120, 255, 1, 22566), -- Candle 02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+61, 180372, 1, 14, 4982, 1, 0, 0, 1280.754, -4418.191, 27.31807, 0.6806767, 0, 0, 0.333806, 0.9426418, 120, 255, 1, 22566), -- Harvest Boar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+62, 180340, 1, 14, 4982, 1, 0, 0, 1279.493, -4420.125, 27.30206, 0.7853968, 0, 0, 0.3826828, 0.9238798, 120, 255, 1, 22566), -- Candle 03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+63, 180337, 1, 14, 4982, 1, 0, 0, 1285.181, -4424.196, 26.64032, 2.722713, 0, 0, 0.9781475, 0.2079121, 120, 255, 1, 22566), -- Cooking Table (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+64, 180338, 1, 14, 4982, 1, 0, 0, 1280.056, -4429.052, 27.54755, 5.515242, 0, 0, -0.3746061, 0.927184, 120, 255, 1, 22566), -- Candle 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+65, 180374, 1, 14, 4982, 1, 0, 0, 1289.03, -4430.198, 27.65899, 0.9250238, 0, 0, 0.4461975, 0.8949345, 120, 255, 1, 22566), -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+66, 180349, 1, 14, 4982, 1, 0, 0, 1280.247, -4429.712, 27.56082, 0.9424766, 0, 0, 0.45399, 0.8910068, 120, 255, 1, 22566), -- Jar Orc 06 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+67, 180326, 1, 14, 4982, 1, 0, 0, 1280.073, -4419.391, 26.57118, 5.532695, 0, 0, -0.3665009, 0.9304177, 120, 255, 1, 22566), -- OrcBench01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+68, 180352, 1, 14, 4982, 1, 0, 0, 1284.738, -4433.455, 27.15543, 2.670348, 0, 0, 0.9723692, 0.2334484, 120, 255, 1, 22566), -- General Torch 01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+69, 180374, 1, 14, 4982, 1, 0, 0, 1284.241, -4423.913, 27.55278, 0.5410506, 0, 0, 0.2672377, 0.9636307, 120, 255, 1, 22566); -- Harvest Nectar (Area: The Dranosh'ar Blockade - Difficulty: 0)

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+69 AND `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` SELECT @Event, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+69;
--
