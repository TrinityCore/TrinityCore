-- Stormwind Pathing master branch
-- Reusing bad spawns
SET @CGUID := 314218;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 68, 0, 0, 0, 1, 169, 0, 0, 0, -8950.371, 508.7445, 96.35762, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormwind City Guard
(@CGUID+1, 37944, 0, 0, 0, 1, 169, 0, 0, 0, -8826.185, 622.1094, 94.37334, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Stormwind City Guard

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (52361);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (52358,52359);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(52358,52359,0,1,'Craggle Wobbletop - Toy Cart', 8, 0),
(52359,52361,0,1,'Toy Cart - Toy Cart Bunny', 8, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (52358,52359);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(52358, 46598, 0, 0),(52359, 46598, 0, 0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 313855;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8858.68,`position_y`=934.042,`position_z`=101.989 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8858.68,934.042,101.989,0,0,0,0,100,0),
(@PATH,2,-8858.68,934.042,101.989,5.183628,38000,0,0,100,0),
(@PATH,3,-8891.83,915.7,110.588,0,0,0,0,100,0),
(@PATH,4,-8891.83,915.7,110.588,5.358161,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314069;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8693.63,`position_y`=715.87,`position_z`=97.0443 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8693.63,715.87,97.0443,0,0,0,0,100,0),
(@PATH,2,-8693.63,715.87,97.0443,2.251475,38000,0,0,100,0),
(@PATH,3,-8664.26,739.443,96.9903,0,0,0,0,100,0),
(@PATH,4,-8664.26,739.443,96.9903,2.234021,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314331;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8640.46,`position_y`=479.21,`position_z`=102.553 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8640.46,479.21,102.553,0,0,0,0,100,0),
(@PATH,2,-8640.46,479.21,102.553,2.321288,38000,0,0,100,0),
(@PATH,3,-8610.83,502.576,103.423,0,0,0,0,100,0),
(@PATH,4,-8610.83,502.576,103.423,2.303835,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 313758;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8677.32,`position_y`=875.776,`position_z`=97.1262 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8677.32,875.776,97.1262,0,0,0,0,100,0),
(@PATH,2,-8677.32,875.776,97.1262,3.857178,38000,0,0,100,0),
(@PATH,3,-8653.88,846.043,97.0388,0,0,0,0,100,0),
(@PATH,4,-8653.88,846.043,97.0388,3.892084,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314625;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8567.35,`position_y`=676.016,`position_z`=97.0544 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8567.35,676.016,97.0544,0,0,0,0,100,0),
(@PATH,2,-8567.35,676.016,97.0544,0.6981317,38000,0,0,100,0),
(@PATH,3,-8590.81,705.696,97.0145,0,0,0,0,100,0),
(@PATH,4,-8590.81,705.696,97.0145,0.6806784,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314048;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8824.81,`position_y`=683.625,`position_z`=97.1527 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8824.81,683.625,97.1527,0,0,0,0,100,0),
(@PATH,2,-8824.81,683.625,97.1527,3.543018,38000,0,0,100,0),
(@PATH,3,-8840.42,717.938,97.7169,0,0,0,0,100,0),
(@PATH,4,-8840.42,717.938,97.7169,3.525565,38000,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314253;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8722.11,`position_y`=506.99,`position_z`=96.6184 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8722.11,506.99,96.6184,0,0,0,0,100,0),
(@PATH,2,-8722.11,506.99,96.6184,0.541052,38000,0,0,100,0),
(@PATH,3,-8698.25,476.49,95.4213,0,0,0,0,100,0),
(@PATH,4,-8698.25,476.49,95.4213,0.5934119,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314119;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8765.54,`position_y`=607.7,`position_z`=97.0107 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8765.54,607.7,97.0107,0,0,0,0,100,0),
(@PATH,2,-8765.54,607.7,97.0107,3.839724,38000,0,0,100,0),
(@PATH,3,-8738.67,580.521,97.6671,0,0,0,0,100,0),
(@PATH,4,-8738.67,580.521,97.6671,3.892084,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314015;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8908.29,`position_y`=785.601,`position_z`=88.1807 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8908.29,785.601,88.1807,0,0,0,0,100,0),
(@PATH,2,-8908.29,785.601,88.1807,0.715585,38000,0,0,100,0),
(@PATH,3,-8885.14,756.491,95.6911,0,0,0,0,100,0),
(@PATH,4,-8885.14,756.491,95.6911,0.7330383,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314421;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8510.24,`position_y`=525.635,`position_z`=98.3494 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8510.24,525.635,98.3494,0,0,0,0,100,0),
(@PATH,2,-8510.24,525.635,98.3494,2.216568,38000,0,0,100,0),
(@PATH,3,-8539.5,502.309,98.6891,0,0,0,0,100,0),
(@PATH,4,-8539.5,502.309,98.6891,2.234021,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314630;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8471,`position_y`=685.602,`position_z`=99.5979 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8471,685.602,99.5979,0,0,0,0,100,0),
(@PATH,2,-8471,685.602,99.5979,0.6632251,38000,0,0,100,0),
(@PATH,3,-8447.56,655.849,93.387,0,0,0,0,100,0),
(@PATH,4,-8447.56,655.849,93.387,0.6806784,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 313911;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8965.598,`position_y`=526.1793,`position_z`=96.59669 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8965.598,526.1793,96.59669,0,0,0,0,100,0),
(@PATH,2,-8965.982,522.4747,96.59444,0,0,0,0,100,0),
(@PATH,3,-8969.254,518.1631,96.59999,0,0,0,0,100,0),
(@PATH,4,-8975.611,512.5862,96.60799,0,0,0,0,100,0),
(@PATH,5,-8986.57,504.235,96.71362,0,0,0,0,100,0),
(@PATH,6,-8995.803,496.151,96.78673,0,0,0,0,100,0),
(@PATH,7,-9005.762,488.3779,96.85242,0,0,0,0,100,0),
(@PATH,8,-9018.345,478.5271,96.3728,0,0,0,0,100,0),
(@PATH,9,-9030.404,469.7563,94.4462,0,0,0,0,100,0),
(@PATH,10,-9036.536,464.3288,93.2955,0,0,0,0,100,0),
(@PATH,11,-9045.851,460.8364,93.2955,0,0,0,0,100,0),
(@PATH,12,-9057.414,457.4207,93.29055,0,0,0,0,100,0),
(@PATH,13,-9072.467,445.5624,93.28751,0,0,0,0,100,0),
(@PATH,14,-9057.414,457.4207,93.29055,0,0,0,0,100,0),
(@PATH,15,-9046.159,460.7451,93.29484,0,0,0,0,100,0),
(@PATH,16,-9036.536,464.3288,93.2955,0,0,0,0,100,0),
(@PATH,17,-9030.404,469.7563,94.4462,0,0,0,0,100,0),
(@PATH,18,-9018.345,478.5271,96.3728,0,0,0,0,100,0),
(@PATH,19,-9005.913,488.259,96.84912,0,0,0,0,100,0),
(@PATH,20,-8995.803,496.151,96.78673,0,0,0,0,100,0),
(@PATH,21,-8986.57,504.235,96.71362,0,0,0,0,100,0),
(@PATH,22,-8975.611,512.5862,96.60799,0,0,0,0,100,0),
(@PATH,23,-8969.254,518.1631,96.59999,0,0,0,0,100,0),
(@PATH,24,-8965.982,522.4747,96.59444,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314338;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8659.22,`position_y`=759.667,`position_z`=97.14017 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8659.22,759.667,97.14017,0,0,0,0,100,0),
(@PATH,2,-8643.39,736.781,96.84623,0,0,0,0,100,0),
(@PATH,3,-8627.08,727.135,96.92905,0,0,0,0,100,0),
(@PATH,4,-8616.54,711.675,96.80405,0,0,0,0,100,0),
(@PATH,5,-8611.82,710.925,96.80405,0,0,0,0,100,0),
(@PATH,6,-8588.46,730.727,96.90238,0,0,0,0,100,0),
(@PATH,7,-8568.56,747.234,96.99006,0,0,0,0,100,0),
(@PATH,8,-8556.06,758.146,98.65372,0,0,0,0,100,0),
(@PATH,9,-8553.96,767.128,99.45676,0,0,0,0,100,0),
(@PATH,10,-8562.19,766.477,98.75309,0,0,0,0,100,0),
(@PATH,11,-8566.45,762.918,98.24186,0,0,0,0,100,0),
(@PATH,12,-8579.66,758.583,97.15803,0,0,0,0,100,0),
(@PATH,13,-8597.54,759.863,97.02985,0,0,0,0,100,0),
(@PATH,14,-8613.81,769.677,96.84048,0,0,0,0,100,0),
(@PATH,15,-8627.23,786.378,96.84451,0,0,0,0,100,0),
(@PATH,16,-8631.96,803.465,96.81436,0,0,0,0,100,0),
(@PATH,17,-8628.67,820.99,96.81436,0,0,0,0,100,0),
(@PATH,18,-8617.5,833.314,96.93936,0,0,0,0,100,0),
(@PATH,19,-8602.16,845.96,96.99668,0,0,0,0,100,0),
(@PATH,20,-8601.26,853.328,96.99668,0,0,0,0,100,0),
(@PATH,21,-8607.07,859.941,96.99668,0,0,0,0,100,0),
(@PATH,22,-8617.37,859.313,96.99668,0,0,0,0,100,0),
(@PATH,23,-8644.5,837.304,96.73873,0,0,0,0,100,0),
(@PATH,24,-8659.97,824.448,96.98507,0,0,0,0,100,0),
(@PATH,25,-8661.87,816.052,96.75191,0,0,0,0,100,0),
(@PATH,26,-8642.01,793.733,96.92826,0,0,0,0,100,0),
(@PATH,27,-8635.92,786.597,97.09916,0,0,0,0,100,0),
(@PATH,28,-8639.05,780.377,97.17826,0,0,0,0,100,0),
(@PATH,29,-8658.02,766.161,96.97123,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314065;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8802.705,`position_y`=490.125,`position_z`=96.84409 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8802.705,490.125,96.84409,0,0,0,0,100,0),
(@PATH,2,-8793.83,506.099,98.1385,0,0,0,0,100,0),
(@PATH,3,-8783.61,515.064,97.8885,0,0,0,0,100,0),
(@PATH,4,-8770.73,530.464,97.5135,0,0,0,0,100,0),
(@PATH,5,-8760.29,545.951,97.46362,0,0,0,0,100,0),
(@PATH,6,-8749.31,560.582,97.46459,0,0,0,0,100,0),
(@PATH,7,-8734.87,575.12,97.52133,0,0,0,0,100,0),
(@PATH,8,-8720.74,587.441,98.3885,0,0,0,0,100,0),
(@PATH,9,-8710.14,596.498,99.03071,0,0,0,0,100,0),
(@PATH,10,-8703.1,612.382,99.8231,0,0,0,0,100,0),
(@PATH,11,-8703.41,625.927,100.4963,0,0,0,0,100,0),
(@PATH,12,-8706.46,645.846,100.3619,0,0,0,0,100,0),
(@PATH,13,-8711.11,655.55,99.6385,0,0,0,0,100,0),
(@PATH,14,-8717.33,670.292,98.98618,0,0,0,0,100,0),
(@PATH,15,-8725.89,686.734,98.86118,0,0,0,0,100,0),
(@PATH,16,-8736.18,700.851,98.8199,0,0,0,0,100,0),
(@PATH,17,-8750.85,720.873,98.2635,0,0,0,0,100,0),
(@PATH,18,-8764.49,736.75,99.1385,0,0,0,0,100,0),
(@PATH,19,-8782.12,745.891,98.96834,0,0,0,0,100,0),
(@PATH,20,-8801.91,745.823,97.7635,0,0,0,0,100,0),
(@PATH,21,-8826.35,733.76,98.3885,0,0,0,0,100,0),
(@PATH,22,-8854.57,718.51,97.5135,0,0,0,0,100,0),
(@PATH,23,-8879.35,708.335,98.096,0,0,0,0,100,0),
(@PATH,24,-8904.08,692.448,99.45762,0,0,0,0,100,0),
(@PATH,25,-8904.08,692.448,99.45762,0.6108652,24000,0,0,100,0),
(@PATH,26,-8887.21,702.74,98.51739,0,0,0,0,100,0),
(@PATH,27,-8876.8,708.427,98.08501,0,0,0,0,100,0),
(@PATH,28,-8859.61,715.915,97.70039,0,0,0,0,100,0),
(@PATH,29,-8838.97,724.627,97.77448,0,0,0,0,100,0),
(@PATH,30,-8822.9,734.085,98.32404,0,0,0,0,100,0),
(@PATH,31,-8803.81,743.306,97.7635,0,0,0,0,100,0),
(@PATH,32,-8786.94,744.701,98.85176,0,0,0,0,100,0),
(@PATH,33,-8770.89,738.918,99.46785,0,0,0,0,100,0),
(@PATH,34,-8760.34,731.017,98.7635,0,0,0,0,100,0),
(@PATH,35,-8750.1,718.451,98.2635,0,0,0,0,100,0),
(@PATH,36,-8740.53,705.576,98.78181,0,0,0,0,100,0),
(@PATH,37,-8728.87,690.2,98.98618,0,0,0,0,100,0),
(@PATH,38,-8717.33,670.292,98.98618,0,0,0,0,100,0),
(@PATH,39,-8711.11,655.55,99.6385,0,0,0,0,100,0),
(@PATH,40,-8706.5,641.319,100.296,0,0,0,0,100,0),
(@PATH,41,-8703.83,625.064,100.492,0,0,0,0,100,0),
(@PATH,42,-8706.2,608.936,99.71604,0,0,0,0,100,0),
(@PATH,43,-8710.09,598.036,99.23859,0,0,0,0,100,0),
(@PATH,44,-8717.44,589.771,98.48322,0,0,0,0,100,0),
(@PATH,45,-8731.84,576.365,97.3885,0,0,0,0,100,0),
(@PATH,46,-8746.06,564.229,97.62475,0,0,0,0,100,0),
(@PATH,47,-8758.94,548.776,97.58959,0,0,0,0,100,0),
(@PATH,48,-8771.33,530.757,97.51691,0,0,0,0,100,0),
(@PATH,49,-8783.61,515.064,97.8885,0,0,0,0,100,0),
(@PATH,50,-8796.23,503.66,98.12531,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8997.55,`position_y`=759.071,`position_z`=131.7325 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8997.55,759.071,131.7325,0,0,0,0,100,0),
(@PATH,2,-9003.54,764.872,132.2214,0,0,0,0,100,0),
(@PATH,3,-9011.56,778.205,137.1929,0,0,0,0,100,0),
(@PATH,4,-9016.519,790.8154,138.0036,0,0,0,0,100,0),
(@PATH,5,-9016.519,790.8154,138.0036,5.148721,11000,0,0,100,0),
(@PATH,6,-9005.792,771.3577,134.2723,0,0,0,0,100,0),
(@PATH,7,-8979.82,751.514,126.1929,0,0,0,0,100,0),
(@PATH,8,-8969.11,747.618,126.1929,0,0,0,0,100,0),
(@PATH,9,-8969.11,747.618,126.1929,2.879793,17000,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314087;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8960.388,`position_y`=571.9006,`position_z`=93.81674 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8960.388,571.9006,93.81674,0,0,0,0,100,0),
(@PATH,2,-8953.924,570.0947,93.79936,0,0,0,0,100,0),
(@PATH,3,-8942.186,556.7715,93.97713,0,0,0,0,100,0),
(@PATH,4,-8932.92,546.87,94.72253,0,0,0,0,100,0),
(@PATH,5,-8926.496,547.9117,94.72253,0,0,0,0,100,0),
(@PATH,6,-8912.01,561.03,94.3512,0,0,0,0,100,0),
(@PATH,7,-8903.67,567.644,93.59348,0,0,0,0,100,0),
(@PATH,8,-8897.69,572.417,93.06246,0,0,0,0,100,0),
(@PATH,9,-8895.44,569.826,93.12081,0,0,0,0,100,0),
(@PATH,10,-8910.1,558.852,94.22253,0,0,0,0,100,0),
(@PATH,11,-8928.88,544.403,94.72253,0,0,0,0,100,0),
(@PATH,12,-8927.04,534.434,94.72253,0,0,0,0,100,0),
(@PATH,13,-8915.321,517.5744,93.81846,0,0,0,0,100,0),
(@PATH,14,-8916.146,501.6403,93.87549,0,0,0,0,100,0),
(@PATH,15,-8934.219,502.0309,94.2423,0,0,0,0,100,0),
(@PATH,16,-8940.811,511.4095,95.89371,0,0,0,0,100,0),
(@PATH,17,-8947.672,515.8253,96.35957,0,0,0,0,100,0),
(@PATH,18,-8961.026,516.0897,96.35683,0,0,0,0,100,0),
(@PATH,19,-8960.283,529.7083,96.35609,0,0,0,0,100,0),
(@PATH,20,-8974.147,544.0145,94.21961,0,0,0,0,100,0),
(@PATH,21,-8981.909,554.1882,93.96465,0,0,0,0,100,0),
(@PATH,22,-8970.026,564.7144,93.88353,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313937;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8824.64,`position_y`=619.983,`position_z`=94.49273 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8824.64,619.983,94.49273,0,0,0,0,100,0),
(@PATH,2,-8825.31,615.174,94.85332,0,0,0,0,100,0),
(@PATH,3,-8827.044,611.3048,94.66717,0,0,0,0,100,0),
(@PATH,4,-8827.044,611.3048,94.66717,0.9599311,18000,0,0,100,0),
(@PATH,5,-8825.54,619.632,94.53228,0,0,0,0,100,0),
(@PATH,6,-8826.18,624.085,94.32818,0,0,0,0,100,0),
(@PATH,7,-8825.56,626.854,94.45318,0,0,0,0,100,0),
(@PATH,8,-8824.12,628.957,94.45318,0,0,0,0,100,0),
(@PATH,9,-8824.12,628.957,94.45318,0.7679449,19000,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314050;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8753.33,`position_y`=824.486,`position_z`=120.5929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8753.33,824.486,120.5929,0,0,0,0,100,0),
(@PATH,2,-8753.33,824.486,120.5929,6.126106,16000,0,0,100,0),
(@PATH,3,-8754.59,812.575,123.3929,0,0,0,0,100,0),
(@PATH,4,-8752.26,808.583,123.3929,0,0,0,0,100,0),
(@PATH,5,-8752.1,804.274,123.3929,0,0,0,0,100,0),
(@PATH,6,-8755.52,801.361,123.3929,0,0,0,0,100,0),
(@PATH,7,-8760.75,801.464,123.3929,0,0,0,0,100,0),
(@PATH,8,-8764.04,805.165,123.3929,0,0,0,0,100,0),
(@PATH,9,-8772.33,806.238,120.5929,0,0,0,0,100,0),
(@PATH,10,-8781.42,808.146,120.5929,0,0,0,0,100,0),
(@PATH,11,-8791.66,809.958,120.6623,0,0,0,0,100,0),
(@PATH,12,-8799.19,811.471,123.3929,0,0,0,0,100,0),
(@PATH,13,-8802.89,809.432,123.3929,0,0,0,0,100,0),
(@PATH,14,-8807.69,810.059,123.3929,0,0,0,0,100,0),
(@PATH,15,-8810.43,814.259,123.3929,0,0,0,0,100,0),
(@PATH,16,-8808.67,817.922,123.3929,0,0,0,0,100,0),
(@PATH,17,-8805.32,819.717,123.3929,0,0,0,0,100,0),
(@PATH,18,-8805.07,827.689,120.5929,0,0,0,0,100,0),
(@PATH,19,-8805.14,832.712,120.5929,0,0,0,0,100,0),
(@PATH,20,-8805.14,832.712,120.5929,3.071779,16000,0,0,100,0),
(@PATH,21,-8805.894,826.8928,120.9341,0,0,0,0,100,0),
(@PATH,22,-8805.998,820.9844,123.3922,0,0,0,0,100,0),
(@PATH,23,-8808.49,818.016,123.3929,0,0,0,0,100,0),
(@PATH,24,-8809.88,813.924,123.3929,0,0,0,0,100,0),
(@PATH,25,-8808.26,809.839,123.3929,0,0,0,0,100,0),
(@PATH,26,-8804.4,808.122,123.3929,0,0,0,0,100,0),
(@PATH,27,-8801.69,809.45,123.3929,0,0,0,0,100,0),
(@PATH,28,-8799.48,811.596,123.3929,0,0,0,0,100,0),
(@PATH,29,-8791.92,809.976,120.6611,0,0,0,0,100,0),
(@PATH,30,-8783.94,808.399,120.6795,0,0,0,0,100,0),
(@PATH,31,-8772.33,806.238,120.5929,0,0,0,0,100,0),
(@PATH,32,-8764.04,805.165,123.3929,0,0,0,0,100,0),
(@PATH,33,-8760.75,801.464,123.3929,0,0,0,0,100,0),
(@PATH,34,-8755.88,800.997,123.3929,0,0,0,0,100,0),
(@PATH,35,-8752.56,803.717,123.3929,0,0,0,0,100,0),
(@PATH,36,-8752.26,808.583,123.3929,0,0,0,0,100,0),
(@PATH,37,-8754.59,812.575,123.3929,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313928;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8923.8,`position_y`=536.245,`position_z`=94.72253 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8923.8,536.245,94.72253,0,0,0,0,100,0),
(@PATH,2,-8921.13,541.922,94.72253,0,0,0,0,100,0),
(@PATH,3,-8908.25,552.203,94.34753,0,0,0,0,100,0),
(@PATH,4,-8893.43,563.925,93.60017,0,0,0,0,100,0),
(@PATH,5,-8895.64,566.903,93.47164,0,0,0,0,100,0),
(@PATH,6,-8910.59,554.939,94.34753,0,0,0,0,100,0),
(@PATH,7,-8923.31,544.448,94.72253,0,0,0,0,100,0),
(@PATH,8,-8934.71,543.941,94.72713,0,0,0,0,100,0),
(@PATH,9,-8946.599,558.0619,93.80767,0,0,0,0,100,0),
(@PATH,10,-8966.211,561.7438,93.87334,0,0,0,0,100,0),
(@PATH,11,-8967.722,542.7493,94.10295,0,0,0,0,100,0),
(@PATH,12,-8956.603,532.3937,96.3556,0,0,0,0,100,0),
(@PATH,13,-8961.372,518.6285,96.3569,0,0,0,0,100,0),
(@PATH,14,-8947.429,510.6634,96.36288,0,0,0,0,100,0),
(@PATH,15,-8935.815,494.4655,94.18289,0,0,0,0,100,0),
(@PATH,16,-8926.802,490.1726,93.89268,0,0,0,0,100,0),
(@PATH,17,-8918.674,495.736,93.89837,0,0,0,0,100,0),
(@PATH,18,-8912.285,501.3521,93.85649,0,0,0,0,100,0),
(@PATH,19,-8908.821,507.9319,93.827,0,0,0,0,100,0),
(@PATH,20,-8909.695,514.5034,93.81547,0,0,0,0,100,0),
(@PATH,21,-8912.723,523.9491,93.80155,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314033;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8751.83,`position_y`=836.113,`position_z`=120.5929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8751.83,836.113,120.5929,0,0,0,0,100,0),
(@PATH,2,-8751.83,836.113,120.5929,6.161012,15000,0,0,100,0),
(@PATH,3,-8750.19,849.483,123.3929,0,0,0,0,100,0),
(@PATH,4,-8747.05,852.116,123.3929,0,0,0,0,100,0),
(@PATH,5,-8746.29,856.995,123.3929,0,0,0,0,100,0),
(@PATH,6,-8749.47,860.488,123.3929,0,0,0,0,100,0),
(@PATH,7,-8754.9,860.389,123.3929,0,0,0,0,100,0),
(@PATH,8,-8757.99,858.061,123.3929,0,0,0,0,100,0),
(@PATH,9,-8765.68,858.938,120.5929,0,0,0,0,100,0),
(@PATH,10,-8775.31,860.625,120.5929,0,0,0,0,100,0),
(@PATH,11,-8785.92,861.988,120.5929,0,0,0,0,100,0),
(@PATH,12,-8793.21,862.505,123.3929,0,0,0,0,100,0),
(@PATH,13,-8796.75,866.623,123.3929,0,0,0,0,100,0),
(@PATH,14,-8802.2,866.123,123.3929,0,0,0,0,100,0),
(@PATH,15,-8805.08,863.123,123.3929,0,0,0,0,100,0),
(@PATH,16,-8804.43,859.201,123.3929,0,0,0,0,100,0),
(@PATH,17,-8801.6,855.571,123.3929,0,0,0,0,100,0),
(@PATH,18,-8802.86,847.953,120.6912,0,0,0,0,100,0),
(@PATH,19,-8803.65,842.785,120.5929,0,0,0,0,100,0),
(@PATH,20,-8803.65,842.785,120.5929,3.001966,14000,0,0,100,0),
(@PATH,21,-8803.37,848.125,120.7248,0,0,0,0,100,0),
(@PATH,22,-8802.13,854.979,123.3929,0,0,0,0,100,0),
(@PATH,23,-8804.92,859.292,123.3929,0,0,0,0,100,0),
(@PATH,24,-8805.57,863.007,123.3929,0,0,0,0,100,0),
(@PATH,25,-8802.59,866.101,123.3929,0,0,0,0,100,0),
(@PATH,26,-8798.29,867.389,123.3929,0,0,0,0,100,0),
(@PATH,27,-8795.37,865,123.3929,0,0,0,0,100,0),
(@PATH,28,-8793.04,861.823,123.3929,0,0,0,0,100,0),
(@PATH,29,-8786.3,861.316,120.8576,0,0,0,0,100,0),
(@PATH,30,-8776.96,860.431,120.5929,0,0,0,0,100,0),
(@PATH,31,-8764.96,858.703,120.5929,0,0,0,0,100,0),
(@PATH,32,-8758.24,857.616,123.3929,0,0,0,0,100,0),
(@PATH,33,-8754.53,860.24,123.3929,0,0,0,0,100,0),
(@PATH,34,-8748.16,859.767,123.3929,0,0,0,0,100,0),
(@PATH,35,-8746.71,855.309,123.3929,0,0,0,0,100,0),
(@PATH,36,-8747.91,851.823,123.3929,0,0,0,0,100,0),
(@PATH,37,-8750.98,849.469,123.3929,0,0,0,0,100,0),
(@PATH,38,-8751.77,842.549,120.8328,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 37944 'TDB FORMAT' 
SET @NPC := 313764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8572.911,`position_y`=751.191,`position_z`=96.94941 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8572.911,751.191,96.94941,0,0,0,0,100,0),
(@PATH,2,-8574.042,741.4809,96.90485,0,0,0,0,100,0),
(@PATH,3,-8586.103,728.0364,96.90238,0,0,0,0,100,0),
(@PATH,4,-8595.998,718.007,96.90238,0,0,0,0,100,0),
(@PATH,5,-8609.936,707.8021,96.80405,0,0,0,0,100,0),
(@PATH,6,-8617.886,709.2083,96.80405,0,0,0,0,100,0),
(@PATH,7,-8626.294,721.908,96.80405,0,0,0,0,100,0),
(@PATH,8,-8648.229,745.9427,96.97123,0,0,0,0,100,0),
(@PATH,9,-8663.17,764.5104,97.07841,0,0,0,0,100,0),
(@PATH,10,-8638.526,784.1458,97.24271,0,0,0,0,100,0),
(@PATH,11,-8633.321,789.1233,97.07547,0,0,0,0,100,0),
(@PATH,12,-8649.272,806.6285,97.11373,0,0,0,0,100,0),
(@PATH,13,-8660.446,820.4358,96.86373,0,0,0,0,100,0),
(@PATH,14,-8654.766,826.5886,96.98556,0,0,0,0,100,0),
(@PATH,15,-8645.361,833.4948,96.73873,0,0,0,0,100,0),
(@PATH,16,-8630.7,844.8698,96.94358,0,0,0,0,100,0),
(@PATH,17,-8614.993,858.0226,96.99668,0,0,0,0,100,0),
(@PATH,18,-8602.837,846.7188,96.99668,0,0,0,0,100,0),
(@PATH,19,-8618.085,835.0347,96.87168,0,0,0,0,100,0),
(@PATH,20,-8633.176,818.7309,96.81436,0,0,0,0,100,0),
(@PATH,21,-8634.792,802.2136,96.97628,0,0,0,0,100,0),
(@PATH,22,-8627.799,785.5,96.88919,0,0,0,0,100,0),
(@PATH,23,-8622.018,775.5434,96.88651,0,0,0,0,100,0),
(@PATH,24,-8602.085,760.8195,96.95193,0,0,0,0,100,0),
(@PATH,25,-8583.335,757.3489,96.90485,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 37944 'TDB FORMAT' 
SET @NPC := 313867;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8999.645,`position_y`=900.3055,`position_z`=105.8661 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8999.645,900.3055,105.8661,0,0,0,0,100,0),
(@PATH,2,-8988.685,892.4722,105.7929,0,0,0,0,100,0),
(@PATH,3,-8978.679,881.5313,106.5103,0,0,0,0,100,0),
(@PATH,4,-8975.33,873.3837,106.697,0,0,0,0,100,0),
(@PATH,5,-8975.759,862.7708,106.6103,0,0,0,0,100,0),
(@PATH,6,-8979.109,848.7205,105.7086,0,0,0,0,100,0),
(@PATH,7,-8988.859,836.5746,105.8641,0,0,0,0,100,0),
(@PATH,8,-8996.136,826.1215,105.3302,0,0,0,0,100,0),
(@PATH,9,-8992.526,811.4705,103.8831,0,0,0,0,100,0),
(@PATH,10,-8989.761,799.3646,102.6033,0,0,0,0,100,0),
(@PATH,11,-8986.236,792.9774,100.6478,0,0,0,0,100,0),
(@PATH,12,-8984.341,787.2726,99.39093,0,0,0,0,100,0),
(@PATH,13,-8974.569,780.2969,97.01678,0,0,0,0,100,0),
(@PATH,14,-8964.677,771.6754,94.99409,0,0,0,0,100,0),
(@PATH,15,-8942.88,770.7778,90.34907,0,0,0,0,100,0),
(@PATH,16,-8924.33,777.8976,87.43955,0,0,0,0,100,0),
(@PATH,17,-8907.863,791.7952,87.48057,0,0,0,0,100,0),
(@PATH,18,-8905.719,793.7778,87.56455,0,0,0,0,100,0),
(@PATH,19,-8902.533,796.9705,87.43955,0,0,0,0,100,0),
(@PATH,20,-8899.582,801.382,87.78739,0,0,0,0,100,0),
(@PATH,21,-8899.214,809.9305,88.72025,0,0,0,0,100,0),
(@PATH,22,-8898.338,823.9033,91.93412,0,0,0,0,100,0),
(@PATH,23,-8901.962,837.0018,94.70567,0,0,0,0,100,0),
(@PATH,24,-8908.118,843.2396,95.9022,0,0,0,0,100,0),
(@PATH,25,-8907.132,849.0018,96.38816,0,0,0,0,100,0),
(@PATH,26,-8898.721,861.5399,96.34712,0,0,0,0,100,0),
(@PATH,27,-8892.554,872.0364,99.05116,0,0,0,0,100,0),
(@PATH,28,-8887.252,889.7014,103.4493,0,0,0,0,100,0),
(@PATH,29,-8887.598,896.2674,105.4314,0,0,0,0,100,0),
(@PATH,30,-8894.627,910.6337,110.5838,0,0,0,0,100,0),
(@PATH,31,-8901.451,922.4254,114.1822,0,0,0,0,100,0),
(@PATH,32,-8907,928.7587,116.0073,0,0,0,0,100,0),
(@PATH,33,-8912.056,938.066,116.9701,0,0,0,0,100,0),
(@PATH,34,-8922.656,952.7986,117.6209,0,0,0,0,100,0),
(@PATH,35,-8927.382,962.8021,117.3929,0,0,0,0,100,0),
(@PATH,36,-8932.094,970.7327,117.3396,0,0,0,0,100,0),
(@PATH,37,-8941.069,970.8958,117.5754,0,0,0,0,100,0),
(@PATH,38,-8948.77,965.6545,117.9675,0,0,0,0,100,0),
(@PATH,39,-8964.098,955.4913,117.4277,0,0,0,0,100,0),
(@PATH,40,-8980.754,959.7205,116.4141,0,0,0,0,100,0),
(@PATH,41,-8987.286,960.4809,115.4679,0,0,0,0,100,0),
(@PATH,42,-8997.143,959.2726,113.1225,0,0,0,0,100,0),
(@PATH,43,-9006.176,953.0989,110.3786,0,0,0,0,100,0),
(@PATH,44,-9010.875,940.7274,109.3073,0,0,0,0,100,0),
(@PATH,45,-9014.79,927.2309,108.2178,0,0,0,0,100,0),
(@PATH,46,-9010.734,911.8871,106.8074,0,0,0,0,100,0);

-- Pathing for Crier Goodman Entry: 2198 'TDB FORMAT' 
SET @NPC := 314501;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8714.745,`position_y`=421.8576,`position_z`=98.38122 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8714.745,421.8576,98.38122,0,0,0,0,100,0),
(@PATH,2,-8709.191,415.9583,98.84228,0,0,0,0,100,0),
(@PATH,3,-8705.984,410.5746,99.30285,0,0,0,0,100,0),
(@PATH,4,-8703.332,404.0938,100.5708,0,0,0,0,100,0),
(@PATH,5,-8697.991,398.5347,101.6036,0,0,0,0,100,0),
(@PATH,6,-8694.011,396.1736,101.9679,0,0,0,0,100,0),
(@PATH,7,-8687.575,395.7396,102.1886,0,0,0,0,100,0),
(@PATH,8,-8682.071,397.6111,102.5514,0,0,0,0,100,0),
(@PATH,9,-8673.799,403.0174,103.6173,0,0,0,0,100,0),
(@PATH,10,-8660.274,413.5226,102.9036,0,0,0,0,100,0),
(@PATH,11,-8653.747,420.092,102.2451,0,0,0,0,100,0),
(@PATH,12,-8646.578,428.1371,101.7329,0,0,0,0,100,0),
(@PATH,13,-8637.132,440.8542,102.3573,0,0,0,0,100,0),
(@PATH,14,-8634.719,450.6233,102.5006,0,0,0,0,100,0),
(@PATH,15,-8633.181,455.8785,102.4575,0,0,0,0,100,0),
(@PATH,16,-8634.571,461.4566,102.3756,0,0,0,0,100,0),
(@PATH,17,-8638.441,466.934,102.3068,0,0,0,0,100,0),
(@PATH,18,-8644.759,476.1441,102.6313,0,0,0,0,100,0),
(@PATH,19,-8644.231,479.8246,102.6313,0,0,0,0,100,0),
(@PATH,20,-8634.696,488.0868,102.6313,0,0,0,0,100,0),
(@PATH,21,-8620.859,498.1615,102.9922,0,0,0,0,100,0),
(@PATH,22,-8610,506.276,103.7635,0,0,0,0,100,0),
(@PATH,23,-8605.667,506.6945,103.8885,0,0,0,0,100,0),
(@PATH,24,-8594.814,497.2014,104.0135,0,0,0,0,100,0),
(@PATH,25,-8588.022,488.3889,104.1385,0,0,0,0,100,0),
(@PATH,26,-8582.486,481.1233,104.3885,0,0,0,0,100,0),
(@PATH,27,-8575.618,473.9291,104.3885,0,0,0,0,100,0),
(@PATH,28,-8566.29,467.182,104.8406,0,0,0,0,100,0),
(@PATH,29,-8557.69,467.762,104.5898,0,0,0,0,100,0),
(@PATH,30,-8552.34,470.172,104.5898,0,0,0,0,100,0),
(@PATH,31,-8545.313,473.8611,104.1639,0,0,0,0,100,0),
(@PATH,32,-8538.047,481.6771,102.2373,0,0,0,0,100,0),
(@PATH,33,-8536.002,487.7135,101.119,0,0,0,0,100,0),
(@PATH,34,-8537.272,491.0695,100.5637,0,0,0,0,100,0),
(@PATH,35,-8552.479,510.2708,98.60273,0,0,0,0,100,0),
(@PATH,36,-8556.004,516.5972,99.65998,0,0,0,0,100,0),
(@PATH,37,-8560.851,526.1059,100.8228,0,0,0,0,100,0),
(@PATH,38,-8565.419,531.8299,101.4478,0,0,0,0,100,0),
(@PATH,39,-8573.931,537.7847,101.7834,0,0,0,0,100,0),
(@PATH,40,-8579.681,546.2639,102.2732,0,0,0,0,100,0),
(@PATH,41,-8582.172,554.8004,102.0334,0,0,0,0,100,0),
(@PATH,42,-8585.071,562.7726,102.1287,0,0,0,0,100,0),
(@PATH,43,-8588.524,574.8177,103.078,0,0,0,0,100,0),
(@PATH,44,-8584.609,586.1823,103.7635,0,0,0,0,100,0),
(@PATH,45,-8581.978,591.5677,103.8885,0,0,0,0,100,0),
(@PATH,46,-8579.946,597.283,103.6521,0,0,0,0,100,0),
(@PATH,47,-8576.239,603.8386,103.297,0,0,0,0,100,0),
(@PATH,48,-8570.06,610.4254,102.8814,0,0,0,0,100,0),
(@PATH,49,-8563.469,615.4722,102.4693,0,0,0,0,100,0),
(@PATH,50,-8559.404,615.184,102.4283,0,0,0,0,100,0),
(@PATH,51,-8552.944,620.0764,101.9168,0,0,0,0,100,0),
(@PATH,52,-8543.603,627.908,101.0135,0,0,0,0,100,0),
(@PATH,53,-8538.286,631.7327,100.6705,0,0,0,0,100,0),
(@PATH,54,-8531.823,635.8299,100.3885,0,0,0,0,100,0),
(@PATH,55,-8525.877,639.1528,100.1278,0,0,0,0,100,0),
(@PATH,56,-8520.724,643.0903,100.1385,0,0,0,0,100,0),
(@PATH,57,-8513.846,648.618,100.5135,0,0,0,0,100,0),
(@PATH,58,-8510.974,652.6771,100.6385,0,0,0,0,100,0),
(@PATH,59,-8515.399,660.4774,101.7658,0,0,0,0,100,0),
(@PATH,60,-8524.179,672.8299,102.7199,0,0,0,0,100,0),
(@PATH,61,-8533.482,686.0452,97.7635,0,0,0,0,100,0),
(@PATH,62,-8537.271,687.5261,97.7635,0,0,0,0,100,0),
(@PATH,63,-8542.841,686.3733,97.69075,0,0,0,0,100,0),
(@PATH,64,-8551.399,680.9549,97.40779,0,0,0,0,100,0),
(@PATH,65,-8562.236,673.7396,97.1385,0,0,0,0,100,0),
(@PATH,66,-8576.033,690.8837,97.11234,0,0,0,0,100,0),
(@PATH,67,-8584.739,702.3333,97.15238,0,0,0,0,100,0),
(@PATH,68,-8591.779,711.5226,96.90238,0,0,0,0,100,0),
(@PATH,69,-8591.692,715.8038,96.90238,0,0,0,0,100,0),
(@PATH,70,-8589.38,727.4184,96.90238,0,0,0,0,100,0),
(@PATH,71,-8581.639,738.3333,96.90485,0,0,0,0,100,0),
(@PATH,72,-8585.817,744.441,97.02985,0,0,0,0,100,0),
(@PATH,73,-8591.917,752.2691,97.02985,0,0,0,0,100,0),
(@PATH,74,-8597.167,758.0712,97.02985,0,0,0,0,100,0),
(@PATH,75,-8605.716,757.1858,97.01419,0,0,0,0,100,0),
(@PATH,76,-8620.476,754.8577,97.13919,0,0,0,0,100,0),
(@PATH,77,-8629.976,736.4393,97.01419,0,0,0,0,100,0),
(@PATH,78,-8635.436,734.441,96.97123,0,0,0,0,100,0),
(@PATH,79,-8639.54,735.2205,96.91386,0,0,0,0,100,0),
(@PATH,80,-8647.239,739.9219,96.84623,0,0,0,0,100,0),
(@PATH,81,-8652.719,745.6927,96.84623,0,0,0,0,100,0),
(@PATH,82,-8655.929,750.7153,96.97123,0,0,0,0,100,0),
(@PATH,83,-8660.058,760.3629,97.24052,0,0,0,0,100,0),
(@PATH,84,-8660.426,765.5018,97.0485,0,0,0,0,100,0),
(@PATH,85,-8656.897,769.1858,96.81351,0,0,0,0,100,0),
(@PATH,86,-8651.192,773.8281,96.92826,0,0,0,0,100,0),
(@PATH,87,-8646.156,777.5781,97.05326,0,0,0,0,100,0),
(@PATH,88,-8640.77,782.5781,97.17826,0,0,0,0,100,0),
(@PATH,89,-8636.325,786.7344,97.08268,0,0,0,0,100,0),
(@PATH,90,-8636.395,791.8281,96.92826,0,0,0,0,100,0),
(@PATH,91,-8637.714,800.1268,96.98873,0,0,0,0,100,0),
(@PATH,92,-8638.455,809.9618,96.98873,0,0,0,0,100,0),
(@PATH,93,-8638.799,816.1389,96.98873,0,0,0,0,100,0),
(@PATH,94,-8641.569,822.7535,96.98873,0,0,0,0,100,0),
(@PATH,95,-8645.297,828.75,96.86373,0,0,0,0,100,0),
(@PATH,96,-8647.567,832.5364,96.73873,0,0,0,0,100,0),
(@PATH,97,-8650.654,837.0833,96.86373,0,0,0,0,100,0),
(@PATH,98,-8655.531,843.6563,97.21505,0,0,0,0,100,0),
(@PATH,99,-8662.895,853.0521,97.11373,0,0,0,0,100,0),
(@PATH,100,-8675.931,869.1875,97.14622,0,0,0,0,100,0),
(@PATH,101,-8680.646,875.2309,97.30601,0,0,0,0,100,0),
(@PATH,102,-8684.993,875.8351,97.14622,0,0,0,0,100,0),
(@PATH,103,-8692.691,870.4583,97.22422,0,0,0,0,100,0),
(@PATH,104,-8701.479,863.3646,97.20899,0,0,0,0,100,0),
(@PATH,105,-8705.778,860.981,97.33399,0,0,0,0,100,0),
(@PATH,106,-8710.103,858.1354,97.20899,0,0,0,0,100,0),
(@PATH,107,-8725.217,842.9583,96.20899,0,0,0,0,100,0),
(@PATH,108,-8729.165,833.7292,96.47401,0,0,0,0,100,0),
(@PATH,109,-8729.951,821.3802,97.01044,0,0,0,0,100,0),
(@PATH,110,-8724.859,807.908,97.3885,0,0,0,0,100,0),
(@PATH,111,-8717.145,794.6614,97.34675,0,0,0,0,100,0),
(@PATH,112,-8724.859,784.0364,97.6385,0,0,0,0,100,0),
(@PATH,113,-8730.007,776.7361,97.99262,0,0,0,0,100,0),
(@PATH,114,-8732.799,767.243,98.14021,0,0,0,0,100,0),
(@PATH,115,-8732.453,757.7413,98.05647,0,0,0,0,100,0),
(@PATH,116,-8727.776,750.4479,98.118,0,0,0,0,100,0),
(@PATH,117,-8723.232,744.4722,97.91267,0,0,0,0,100,0),
(@PATH,118,-8716.214,735.9427,97.8885,0,0,0,0,100,0),
(@PATH,119,-8717.907,732.3817,98.01238,0,0,0,0,100,0),
(@PATH,120,-8730.286,722.3073,101.6622,0,0,0,0,100,0),
(@PATH,121,-8740.571,713.7327,99.00285,0,0,0,0,100,0),
(@PATH,122,-8744.853,712.092,98.70857,0,0,0,0,100,0),
(@PATH,123,-8751.221,720.7083,98.2635,0,0,0,0,100,0),
(@PATH,124,-8759.058,732.3143,98.7635,0,0,0,0,100,0),
(@PATH,125,-8767.341,740.6215,99.1053,0,0,0,0,100,0),
(@PATH,126,-8777.214,746.8577,99.14876,0,0,0,0,100,0),
(@PATH,127,-8789.653,749.4879,97.95161,0,0,0,0,100,0),
(@PATH,128,-8798.609,748.8854,97.62801,0,0,0,0,100,0),
(@PATH,129,-8810.413,745.4688,97.8885,0,0,0,0,100,0),
(@PATH,130,-8821.294,740.8038,98.1385,0,0,0,0,100,0),
(@PATH,131,-8833.5,731.868,98.1385,0,0,0,0,100,0),
(@PATH,132,-8843.832,722.6215,97.5135,0,0,0,0,100,0),
(@PATH,133,-8848.403,726.4531,97.68182,0,0,0,0,100,0),
(@PATH,134,-8856.799,742.3177,100.6462,0,0,0,0,100,0),
(@PATH,135,-8863.691,753.1597,98.66906,0,0,0,0,100,0),
(@PATH,136,-8869.285,760.8906,96.8108,0,0,0,0,100,0),
(@PATH,137,-8862.712,769.941,96.78592,0,0,0,0,100,0),
(@PATH,138,-8853.339,777.6667,95.9838,0,0,0,0,100,0),
(@PATH,139,-8840.641,785.9254,96.11783,0,0,0,0,100,0),
(@PATH,140,-8831.247,791.743,96.78184,0,0,0,0,100,0),
(@PATH,141,-8826.772,799.5399,97.57627,0,0,0,0,100,0),
(@PATH,142,-8824.7,809.441,98.62839,0,0,0,0,100,0),
(@PATH,143,-8823.349,818.4809,98.95956,0,0,0,0,100,0),
(@PATH,144,-8821.856,829.2778,98.95956,0,0,0,0,100,0),
(@PATH,145,-8819.745,845.0955,98.98844,0,0,0,0,100,0),
(@PATH,146,-8818.647,861.6129,99.11344,0,0,0,0,100,0),
(@PATH,147,-8817.107,884.0555,98.68258,0,0,0,0,100,0),
(@PATH,148,-8828.731,900.7691,98.26041,0,0,0,0,100,0),
(@PATH,149,-8843.861,918.6632,100.6945,0,0,0,0,100,0),
(@PATH,150,-8850.545,928.2795,102.3424,0,0,0,0,100,0),
(@PATH,151,-8856.283,931.5226,102.1977,0,0,0,0,100,0),
(@PATH,152,-8861.611,929.3386,103.3009,0,0,0,0,100,0),
(@PATH,153,-8874.364,922.0729,107.0432,0,0,0,0,100,0),
(@PATH,154,-8891.656,912.9531,110.8513,0,0,0,0,100,0),
(@PATH,155,-8895.931,912.0764,110.7429,0,0,0,0,100,0),
(@PATH,156,-8899.979,918.9746,113.0318,0,0,0,0,100,0),
(@PATH,157,-8905.172,927.809,115.6039,0,0,0,0,100,0),
(@PATH,158,-8911.143,936.3246,116.9107,0,0,0,0,100,0),
(@PATH,159,-8918.625,947.6077,117.5643,0,0,0,0,100,0),
(@PATH,160,-8922.868,949.6875,117.5215,0,0,0,0,100,0),
(@PATH,161,-8928.904,949.132,117.4647,0,0,0,0,100,0),
(@PATH,162,-8935.31,946.0174,117.3027,0,0,0,0,100,0),
(@PATH,163,-8943.099,949.7708,117.3027,0,0,0,0,100,0),
(@PATH,164,-8950.761,954.7552,117.5527,0,0,0,0,100,0),
(@PATH,165,-8962.226,956.5833,117.5231,0,0,0,0,100,0),
(@PATH,166,-8973.391,957.6077,117.3033,0,0,0,0,100,0),
(@PATH,167,-8984.176,959.7881,116.0421,0,0,0,0,100,0),
(@PATH,168,-8991.073,959.5712,114.5295,0,0,0,0,100,0),
(@PATH,169,-8997.382,957.8403,112.9221,0,0,0,0,100,0),
(@PATH,170,-9003.143,955.9271,111.3266,0,0,0,0,100,0),
(@PATH,171,-9008.035,950.3993,110.1554,0,0,0,0,100,0),
(@PATH,172,-9010.879,942.158,109.3073,0,0,0,0,100,0),
(@PATH,173,-9012.866,934.8125,108.5758,0,0,0,0,100,0),
(@PATH,174,-9014.596,925.3195,107.9693,0,0,0,0,100,0),
(@PATH,175,-9010.964,914.8195,106.8982,0,0,0,0,100,0),
(@PATH,176,-9007.606,906.0191,106.4324,0,0,0,0,100,0),
(@PATH,177,-9003.989,901.0712,106.1824,0,0,0,0,100,0),
(@PATH,178,-8998.861,897.967,105.8671,0,0,0,0,100,0),
(@PATH,179,-8988.141,894.7656,105.7929,0,0,0,0,100,0),
(@PATH,180,-8983.886,887.5121,105.8942,0,0,0,0,100,0),
(@PATH,181,-8978.698,882.1684,106.4693,0,0,0,0,100,0),
(@PATH,182,-8975.08,876.3698,106.641,0,0,0,0,100,0),
(@PATH,183,-8975.98,867.9738,106.8003,0,0,0,0,100,0),
(@PATH,184,-8976.747,852.8559,105.7731,0,0,0,0,100,0),
(@PATH,185,-8981,845.5243,105.7612,0,0,0,0,100,0),
(@PATH,186,-8988.146,838.2361,105.8544,0,0,0,0,100,0),
(@PATH,187,-8996.441,828.0504,105.5617,0,0,0,0,100,0),
(@PATH,188,-8996.087,823.1094,104.9293,0,0,0,0,100,0),
(@PATH,189,-8992.712,813.0313,103.8844,0,0,0,0,100,0),
(@PATH,190,-8990.83,804.1493,103.2807,0,0,0,0,100,0),
(@PATH,191,-8987.7,796.8559,101.944,0,0,0,0,100,0),
(@PATH,192,-8983.816,789.4254,99.71136,0,0,0,0,100,0),
(@PATH,193,-8979.864,784.9496,98.4715,0,0,0,0,100,0),
(@PATH,194,-8974.67,780.2666,97.04718,0,0,0,0,100,0),
(@PATH,195,-8970.998,776.9427,96.29999,0,0,0,0,100,0),
(@PATH,196,-8965.938,772.9983,95.18256,0,0,0,0,100,0),
(@PATH,197,-8958.44,771.337,93.83295,0,0,0,0,100,0),
(@PATH,198,-8951.629,770.8611,92.13276,0,0,0,0,100,0),
(@PATH,199,-8940.27,772.0851,89.82734,0,0,0,0,100,0),
(@PATH,200,-8928.703,777.1285,88.07822,0,0,0,0,100,0),
(@PATH,201,-8920.979,781.0799,87.43955,0,0,0,0,100,0),
(@PATH,202,-8913.458,787.6441,87.43955,0,0,0,0,100,0),
(@PATH,203,-8909.484,789.8489,87.64451,0,0,0,0,100,0),
(@PATH,204,-8905.158,785.4705,88.49558,0,0,0,0,100,0),
(@PATH,205,-8897.724,775.875,90.54147,0,0,0,0,100,0),
(@PATH,206,-8888.172,764.5868,93.72974,0,0,0,0,100,0),
(@PATH,207,-8882.232,756.8629,95.99427,0,0,0,0,100,0),
(@PATH,208,-8879.431,755.882,96.3108,0,0,0,0,100,0),
(@PATH,209,-8875.904,757.2274,96.6858,0,0,0,0,100,0),
(@PATH,210,-8872.299,759.4705,96.88477,0,0,0,0,100,0),
(@PATH,211,-8868.545,759.4254,97.06606,0,0,0,0,100,0),
(@PATH,212,-8863.677,753.1632,98.67068,0,0,0,0,100,0),
(@PATH,213,-8856.301,741.5295,100.6525,0,0,0,0,100,0),
(@PATH,214,-8847.496,725.7003,97.3828,0,0,0,0,100,0),
(@PATH,215,-8843.221,718.0504,97.6385,0,0,0,0,100,0),
(@PATH,216,-8837.417,705.7083,97.7635,0,0,0,0,100,0),
(@PATH,217,-8828.337,687.3299,97.3277,0,0,0,0,100,0),
(@PATH,218,-8825.271,680.6424,97.49286,0,0,0,0,100,0),
(@PATH,219,-8825.814,676.941,97.8277,0,0,0,0,100,0),
(@PATH,220,-8829.926,674.6493,98.35626,0,0,0,0,100,0),
(@PATH,221,-8840.018,668.6389,98.06687,0,0,0,0,100,0),
(@PATH,222,-8847.436,663.7639,97.58963,0,0,0,0,100,0),
(@PATH,223,-8850.52,660.4549,97.28665,0,0,0,0,100,0),
(@PATH,224,-8851.067,656.3802,96.90384,0,0,0,0,100,0),
(@PATH,225,-8850.951,652.158,96.66776,0,0,0,0,100,0),
(@PATH,226,-8847.42,643.2795,96.46658,0,0,0,0,100,0),
(@PATH,227,-8839.976,632.5278,94.72533,0,0,0,0,100,0),
(@PATH,228,-8833.038,626.4965,94.19524,0,0,0,0,100,0),
(@PATH,229,-8826.794,618.6996,94.49395,0,0,0,0,100,0),
(@PATH,230,-8818.886,612.941,95.39361,0,0,0,0,100,0),
(@PATH,231,-8810.872,604.9913,96.32818,0,0,0,0,100,0),
(@PATH,232,-8805.935,598.6215,96.81514,0,0,0,0,100,0),
(@PATH,233,-8799.757,591.8108,97.80921,0,0,0,0,100,0),
(@PATH,234,-8794.614,591.2049,97.80921,0,0,0,0,100,0),
(@PATH,235,-8789.125,593.243,97.80921,0,0,0,0,100,0),
(@PATH,236,-8778.571,602.0799,97.40015,0,0,0,0,100,0),
(@PATH,237,-8773.149,606.7969,97.40015,0,0,0,0,100,0),
(@PATH,238,-8769.186,607.5278,97.15015,0,0,0,0,100,0),
(@PATH,239,-8764.938,603.1684,97.02589,0,0,0,0,100,0),
(@PATH,240,-8754.044,592.1059,97.39633,0,0,0,0,100,0),
(@PATH,241,-8740.547,578.1389,97.64633,0,0,0,0,100,0),
(@PATH,242,-8739.441,574.5677,97.64633,0,0,0,0,100,0),
(@PATH,243,-8740.563,570.8351,97.52133,0,0,0,0,100,0),
(@PATH,244,-8744.567,566.6371,97.46459,0,0,0,0,100,0),
(@PATH,245,-8746.016,562.8802,97.63012,0,0,0,0,100,0),
(@PATH,246,-8745.857,558.3984,97.73678,0,0,0,0,100,0),
(@PATH,247,-8742.857,553.8455,98.72974,0,0,0,0,100,0),
(@PATH,248,-8730.731,541.0434,101.1334,0,0,0,0,100,0),
(@PATH,249,-8717.742,524.9555,98.18775,0,0,0,0,100,0),
(@PATH,250,-8716.509,519.9238,97.17777,0,0,0,0,100,0),
(@PATH,251,-8719.073,515.9514,96.8885,0,0,0,0,100,0),
(@PATH,252,-8720.363,510.8698,96.6385,0,0,0,0,100,0),
(@PATH,253,-8716.368,504.276,96.1385,0,0,0,0,100,0),
(@PATH,254,-8707.717,493.151,95.47239,0,0,0,0,100,0),
(@PATH,255,-8697.283,479.6233,95.49294,0,0,0,0,100,0),
(@PATH,256,-8694.848,476.6094,95.49294,0,0,0,0,100,0),
(@PATH,257,-8695.075,473.316,95.49294,0,0,0,0,100,0),
(@PATH,258,-8701.129,468.5729,96.04539,0,0,0,0,100,0),
(@PATH,259,-8707.841,461.6597,96.76711,0,0,0,0,100,0),
(@PATH,260,-8713.435,455.151,97.19191,0,0,0,0,100,0),
(@PATH,261,-8717.708,445.066,97.39211,0,0,0,0,100,0),
(@PATH,262,-8718.62,436.1945,97.61122,0,0,0,0,100,0),
(@PATH,263,-8717.66,425.4583,98.27135,0,0,0,0,100,0);

-- Pathing for Reese Langston Entry: 1327 'TDB FORMAT' 
SET @NPC := 314314;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8610.066,`position_y`=397.2917,`position_z`=102.9234 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8610.066,397.2917,102.9234,0,0,0,0,100,0),
(@PATH,2,-8610.066,397.2917,102.9234,3.839725,30000,0,0,100,0),
(@PATH,3,-8604.423,385.6005,102.9252,0,0,0,0,100,0),
(@PATH,4,-8604.423,385.6005,102.9252,3.839725,30000,0,0,100,0);

-- Pathing for Nikova Raskol Entry: 1721 'TDB FORMAT' 
SET @NPC := 314325;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8633.33,`position_y`=442.715,`position_z`=102.707 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8633.33,442.715,102.707,0,0,0,0,100,0),
(@PATH,2,-8640.1,436.517,101.8207,0,0,0,0,100,0),
(@PATH,3,-8647.26,427.427,101.7329,0,0,0,0,100,0),
(@PATH,4,-8655.34,420.252,102.4363,0,0,0,0,100,0),
(@PATH,5,-8664.83,410.733,103.3249,0,0,0,0,100,0),
(@PATH,6,-8670.94,403.806,103.6927,0,0,0,0,100,0),
(@PATH,7,-8680.04,399.446,103.0151,0,0,0,0,100,0),
(@PATH,8,-8687.06,395.845,102.3116,0,0,0,0,100,0),
(@PATH,9,-8693.09,396.72,102.0782,0,0,0,0,100,0),
(@PATH,10,-8695.88,392.01,102.2763,0,0,0,0,100,0),
(@PATH,11,-8695.88,392.01,102.2763,1.134464,210000,0,0,100,0),
(@PATH,12,-8698.44,401.653,101.4317,0,0,0,0,100,0),
(@PATH,13,-8717.6,406.825,98.02123,0,0,0,0,100,0),
(@PATH,14,-8724.56,406.731,97.82568,0,0,0,0,100,0),
(@PATH,15,-8733.46,394.09,98.20717,0,0,0,0,100,0),
(@PATH,16,-8733.46,394.09,98.20717,1.047198,300000,0,0,100,0),
(@PATH,17,-8726.093,405.4189,97.9829,0,0,0,0,100,0),
(@PATH,18,-8724.291,423.0988,98.07079,0,0,0,0,100,0),
(@PATH,19,-8715.034,455.9825,97.25856,0,0,0,0,100,0),
(@PATH,20,-8681.313,485.2584,96.97781,0,0,0,0,100,0),
(@PATH,21,-8666.829,497.8943,100.7803,0,0,0,0,100,0),
(@PATH,22,-8652.376,486.1017,102.3887,0,0,0,0,100,0),
(@PATH,23,-8636.195,465.4633,102.3756,0,0,0,0,100,0),
(@PATH,24,-8632.351,456.5933,102.4575,0,0,0,0,100,0),
(@PATH,25,-8638.788,450.0242,102.4677,0,0,0,0,100,0),
(@PATH,26,-8638.788,450.0242,102.4677,1.256637,173000,0,0,100,0);

-- Pathing for Thomas Miller Entry: 3518 'TDB FORMAT' 
SET @NPC := 314092;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8815.819,`position_y`=581.5087,`position_z`=95.65852 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8815.819,581.5087,95.65852,0,0,0,0,100,0),
(@PATH,2,-8821.129,571.1163,94.31514,0,0,0,0,100,0),
(@PATH,3,-8830.799,559.092,95.08386,0,0,0,0,100,0),
(@PATH,4,-8834.429,549.6285,96.33086,0,0,0,0,100,0),
(@PATH,5,-8831.716,543.0399,96.88525,0,0,0,0,100,0),
(@PATH,6,-8824.966,553.6528,95.42029,0,0,0,0,100,0),
(@PATH,7,-8816.536,562.6476,94.36243,0,0,0,0,100,0),
(@PATH,8,-8812.607,575.1649,95.02229,0,0,0,0,100,0),
(@PATH,9,-8798.552,587.6337,97.5127,0,0,0,0,100,0),
(@PATH,10,-8788.764,593.309,97.80921,0,0,0,0,100,0),
(@PATH,11,-8776.413,603.9184,97.40015,0,0,0,0,100,0),
(@PATH,12,-8762.692,617.3108,99.17336,0,0,0,0,100,0),
(@PATH,13,-8758.288,627.4583,102.116,0,0,0,0,100,0),
(@PATH,14,-8759.382,641.9202,103.8589,0,0,0,0,100,0),
(@PATH,15,-8770.591,661.3212,103.7889,0,0,0,0,100,0),
(@PATH,16,-8779.109,672.4983,103.1762,0,0,0,0,100,0),
(@PATH,17,-8787.319,680.4358,102.4533,0,0,0,0,100,0),
(@PATH,18,-8804.333,683.7587,101.0262,0,0,0,0,100,0),
(@PATH,19,-8815.252,680.6893,98.55988,0,0,0,0,100,0),
(@PATH,20,-8831.311,674.4184,98.52252,0,0,0,0,100,0),
(@PATH,21,-8844.646,666.4323,97.67435,0,0,0,0,100,0),
(@PATH,22,-8853.107,657.9705,96.98856,0,0,0,0,100,0),
(@PATH,23,-8848.717,646.9445,96.52359,0,0,0,0,100,0),
(@PATH,24,-8842.514,637.9985,95.83914,0,0,0,0,100,0),
(@PATH,25,-8834.657,634.1927,94.76016,0,0,0,0,100,0),
(@PATH,26,-8823.594,639.3086,94.6514,0,0,0,0,100,0),
(@PATH,27,-8818.339,641.126,94.6514,0,0,0,0,100,0),
(@PATH,28,-8811.451,634.4778,94.5264,0,0,0,0,100,0),
(@PATH,29,-8813.913,625.3655,94.32818,0,0,0,0,100,0),
(@PATH,30,-8827.42,620.4167,94.45318,0,0,0,0,100,0),
(@PATH,31,-8837.016,613.5156,93.47093,0,0,0,0,100,0),
(@PATH,32,-8845.904,602.0156,93.15428,0,0,0,0,100,0),
(@PATH,33,-8854.498,591.4705,92.98204,0,0,0,0,100,0),
(@PATH,34,-8863.731,582.434,93.65245,0,0,0,0,100,0),
(@PATH,35,-8875.354,571.8542,93.77254,0,0,0,0,100,0),
(@PATH,36,-8883.438,571.8646,93.18746,0,0,0,0,100,0),
(@PATH,37,-8888.377,578.1823,93.26974,0,0,0,0,100,0),
(@PATH,38,-8889.476,585.2761,93.5129,0,0,0,0,100,0),
(@PATH,39,-8880.286,592.1337,93.50289,0,0,0,0,100,0),
(@PATH,40,-8867.208,597.9323,92.81246,0,0,0,0,100,0),
(@PATH,41,-8849.514,608.0052,92.85033,0,0,0,0,100,0),
(@PATH,42,-8835.442,618.3976,93.40965,0,0,0,0,100,0),
(@PATH,43,-8828.321,620.059,94.45318,0,0,0,0,100,0),
(@PATH,44,-8819.851,613.2379,95.20635,0,0,0,0,100,0),
(@PATH,45,-8809.667,603.6268,96.4555,0,0,0,0,100,0),
(@PATH,46,-8806.913,593.1528,97.29805,0,0,0,0,100,0);

-- Pathing for Jenn Langston Entry: 3626 'TDB FORMAT' 
SET @NPC := 314233;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8637.551,`position_y`=466.9983,`position_z`=102.2336 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8637.551,466.9983,102.2336,0,0,0,0,100,0),
(@PATH,2,-8632.739,458.7951,102.3481,0,0,0,0,100,0),
(@PATH,3,-8632.373,446.901,102.5825,0,0,0,0,100,0),
(@PATH,4,-8639.123,438.7726,102.111,0,0,0,0,100,0),
(@PATH,5,-8645.071,427.6771,101.7329,0,0,0,0,100,0),
(@PATH,6,-8651.674,418.2379,102.1068,0,0,0,0,100,0),
(@PATH,7,-8665.096,409.6215,103.3579,0,0,0,0,100,0),
(@PATH,8,-8680.462,399.7708,103.0036,0,0,0,0,100,0),
(@PATH,9,-8692.747,396.6858,102.1192,0,0,0,0,100,0),
(@PATH,10,-8703.323,406.0313,100.3234,0,0,0,0,100,0),
(@PATH,11,-8712.542,405.809,98.49389,0,0,0,0,100,0),
(@PATH,12,-8724.364,406.4462,97.85986,0,0,0,0,100,0),
(@PATH,13,-8726.004,415.5938,97.82079,0,0,0,0,100,0),
(@PATH,14,-8723.203,424.507,98.19921,0,0,0,0,100,0),
(@PATH,15,-8721.098,435.8438,97.73634,0,0,0,0,100,0),
(@PATH,16,-8716.95,446.8212,97.23878,0,0,0,0,100,0),
(@PATH,17,-8713.995,455.7517,97.25905,0,0,0,0,100,0),
(@PATH,18,-8705.231,463.9653,96.45753,0,0,0,0,100,0),
(@PATH,19,-8682.615,483.6523,96.74294,0,0,0,0,100,0),
(@PATH,20,-8674.91,493.2205,99.19021,0,0,0,0,100,0),
(@PATH,21,-8666.255,496.9323,100.6449,0,0,0,0,100,0),
(@PATH,22,-8659.67,494.7951,101.1584,0,0,0,0,100,0),
(@PATH,23,-8651.92,485.8837,102.4699,0,0,0,0,100,0);

-- Pathing for Officer Pomeroy Entry: 14438 'TDB FORMAT' 
SET @NPC := 313924;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8791.98,`position_y`=744.517,`position_z`=98.51912 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8791.98,744.517,98.51912,0,0,0,0,100,0),
(@PATH,2,-8812.15,738.472,97.83808,0,0,0,0,100,0),
(@PATH,3,-8830.81,728.08,98.3643,0,0,0,0,100,0),
(@PATH,4,-8839.59,723.241,97.70026,0,0,0,0,100,0),
(@PATH,5,-8844.19,722.557,97.5135,0,0,0,0,100,0),
(@PATH,6,-8846.86,725.811,97.54829,0,0,0,0,100,0),
(@PATH,7,-8854.46,742.389,100.7206,0,0,0,0,100,0),
(@PATH,8,-8867.08,758.161,97.38157,0,0,0,0,100,0),
(@PATH,9,-8858.702,747.6907,100.0901,0,0,0,0,100,0),
(@PATH,10,-8867.08,758.161,97.38157,0,0,0,0,100,0),
(@PATH,11,-8872.89,759.063,96.83582,0,0,0,0,100,0),
(@PATH,12,-8878.06,756.849,96.44166,0,0,0,0,100,0),
(@PATH,13,-8881.35,757.905,95.97523,0,0,0,0,100,0),
(@PATH,14,-8899.588,780.4199,89.6235,0,0,0,0,100,0),
(@PATH,15,-8906.11,789.175,88.00523,0,0,0,0,100,0),
(@PATH,16,-8906.12,793.255,87.51463,0,0,0,0,100,0),
(@PATH,17,-8899.29,798.613,87.66708,0,0,0,0,100,0),
(@PATH,18,-8898.14,812.682,89.30436,0,0,0,0,100,0),
(@PATH,19,-8897.64,822.108,91.49003,0,0,0,0,100,0),
(@PATH,20,-8899,832.806,93.86393,0,0,0,0,100,0),
(@PATH,21,-8905.656,842.79,95.7772,0,0,0,0,100,0),
(@PATH,22,-8915.88,854.507,97.12046,0,0,0,0,100,0),
(@PATH,23,-8929.334,858.376,100.4022,0,0,0,0,100,0),
(@PATH,24,-8941.87,862.293,103.9403,0,0,0,0,100,0),
(@PATH,25,-8961.7,861.372,105.9076,0,0,0,0,100,0),
(@PATH,26,-8974.94,855.859,106.0113,0,0,0,0,100,0),
(@PATH,27,-8981.46,845.043,105.7424,0,0,0,0,100,0),
(@PATH,28,-8988.97,837.08,105.8507,0,0,0,0,100,0),
(@PATH,29,-8993.58,828.012,105.3831,0,0,0,0,100,0),
(@PATH,30,-8994.4,818.293,104.4925,0,0,0,0,100,0),
(@PATH,31,-8990.47,797.905,102.4023,0,0,0,0,100,0),
(@PATH,32,-8984,786.214,99.20538,0,0,0,0,100,0),
(@PATH,33,-8971.41,773.849,96.17218,0,0,0,0,100,0),
(@PATH,34,-8958.87,769.747,93.86665,0,0,0,0,100,0),
(@PATH,35,-8942.21,769.925,90.31293,0,0,0,0,100,0),
(@PATH,36,-8925.67,776.995,87.58237,0,0,0,0,100,0),
(@PATH,37,-8912.66,788.337,87.43955,0,0,0,0,100,0),
(@PATH,38,-8907.98,787.854,88.08457,0,0,0,0,100,0),
(@PATH,39,-8900.26,779.328,89.76389,0,0,0,0,100,0),
(@PATH,40,-8882.48,756.003,96.06776,0,0,0,0,100,0),
(@PATH,41,-8877.78,755.155,96.5398,0,0,0,0,100,0),
(@PATH,42,-8872.96,758.995,96.82777,0,0,0,0,100,0),
(@PATH,43,-8869.481,757.6542,97.04164,0,0,0,0,100,0),
(@PATH,44,-8857.65,740.483,100.5976,0,0,0,0,100,0),
(@PATH,45,-8849.66,725.911,97.6571,0,0,0,0,100,0),
(@PATH,46,-8843.38,715.389,97.62019,0,0,0,0,100,0),
(@PATH,47,-8835.01,696.599,97.64268,0,0,0,0,100,0),
(@PATH,48,-8827.22,680.012,97.42072,0,0,0,0,100,0),
(@PATH,49,-8828.2,677.165,97.82733,0,0,0,0,100,0),
(@PATH,50,-8836,673.503,98.40061,0,0,0,0,100,0),
(@PATH,51,-8845.13,667.358,97.89268,0,0,0,0,100,0),
(@PATH,52,-8850.67,661.948,97.34073,0,0,0,0,100,0),
(@PATH,53,-8861.62,654.656,96.34073,0,0,0,0,100,0),
(@PATH,54,-8872.41,648.339,96.05089,0,0,0,0,100,0),
(@PATH,55,-8877.12,645.417,96.04279,0,0,0,0,100,0),
(@PATH,56,-8885.92,640.234,99.52245,0,0,0,0,100,0),
(@PATH,57,-8896.3,634.474,99.52596,0,0,0,0,100,0),
(@PATH,58,-8913.21,625.533,99.52424,0,10000,0,0,100,0),
(@PATH,59,-8918.66,622.625,100.225,0,0,0,0,100,0),
(@PATH,60,-8926.51,621.535,100.226,0,0,0,0,100,0),
(@PATH,61,-8931.55,628.326,100.226,0,0,0,0,100,0),
(@PATH,62,-8933.26,627.243,100.226,0,0,0,0,100,0),
(@PATH,63,-8928.43,616.533,100.226,0,0,0,0,100,0),
(@PATH,64,-8922.06,606.464,100.226,0,0,0,0,100,0),
(@PATH,65,-8922.44,616.783,100.226,0,0,0,0,100,0),
(@PATH,66,-8918.446,622.231,100.225,0,0,0,0,100,0),
(@PATH,67,-8913.33,624.602,99.52355,0,0,0,0,100,0),
(@PATH,68,-8895.8,633.929,99.52586,0,0,0,0,100,0),
(@PATH,69,-8886.15,639.326,99.52247,0,0,0,0,100,0),
(@PATH,70,-8876.45,644.658,96.04852,0,0,0,0,100,0),
(@PATH,71,-8868.748,643.75,96.16636,0,0,0,0,100,0),
(@PATH,72,-8862.2,641.198,96.21951,0,0,0,0,100,0),
(@PATH,73,-8854.06,642.747,96.59451,0,0,0,0,100,0),
(@PATH,74,-8844.64,646.278,96.71951,0,0,0,0,100,0),
(@PATH,75,-8840.218,649.217,98.02964,0,0,0,0,100,0),
(@PATH,76,-8831.67,652.198,98.02465,0,0,0,0,100,0),
(@PATH,77,-8825.58,653.316,98.02496,0,0,0,0,100,0),
(@PATH,78,-8820.68,651.988,98.02496,0,0,0,0,100,0),
(@PATH,79,-8816.14,659.849,98.01369,0,0,0,0,100,0),
(@PATH,80,-8825.2,663.273,98.0191,0,0,0,0,100,0),
(@PATH,81,-8827.67,657.3,98.0219,0,0,0,0,100,0),
(@PATH,82,-8832.18,654.106,98.02564,0,0,0,0,100,0),
(@PATH,83,-8839.73,650.196,98.02621,0,0,0,0,100,0),
(@PATH,84,-8844.791,646.875,96.71951,0,0,0,0,100,0),
(@PATH,85,-8846.81,643.278,96.53958,0,0,0,0,100,0),
(@PATH,86,-8845.8,637.014,95.59866,0,0,0,0,100,0),
(@PATH,87,-8836.41,624.498,93.79344,0,0,0,0,100,0),
(@PATH,88,-8824.48,616.141,94.95293,0,0,0,0,100,0),
(@PATH,89,-8813.03,605.033,96.28667,0,0,0,0,100,0),
(@PATH,90,-8801.28,591.116,97.72408,0,0,0,0,100,0),
(@PATH,91,-8795.08,589.691,97.75965,0,0,0,0,100,0),
(@PATH,92,-8781.9,597.009,97.55921,0,0,0,0,100,0),
(@PATH,93,-8771.35,606.927,97.27515,0,0,0,0,100,0),
(@PATH,94,-8761.1,618.109,99.48268,0,0,0,0,100,0),
(@PATH,95,-8757.65,631.413,102.7328,0,0,0,0,100,0),
(@PATH,96,-8760.83,646.507,103.9702,0,0,0,0,100,0),
(@PATH,97,-8767.24,659.741,103.7889,0,0,0,0,100,0),
(@PATH,98,-8772.75,666.458,103.4139,0,0,0,0,100,0),
(@PATH,99,-8772.96,670.351,103.3691,0,0,0,0,100,0),
(@PATH,100,-8740.38,696.811,99.29871,0,0,0,0,100,0),
(@PATH,101,-8739.2,702.446,98.8885,0,0,0,0,100,0),
(@PATH,102,-8742.47,707.642,98.75008,0,0,0,0,100,0),
(@PATH,103,-8747.336,713.6754,98.75362,0,0,0,0,100,0),
(@PATH,104,-8760.93,730.528,98.7635,0,0,0,0,100,0),
(@PATH,105,-8776.99,741.866,99.68733,0,0,0,0,100,0);

-- Pathing for Little Adeline Entry: 35477 'TDB FORMAT' 
SET @NPC := 314131;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8827.979,`position_y`=515.408,`position_z`=98.68262 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8827.979,515.408,98.68262,0,0,0,0,100,0),
(@PATH,2,-8827.979,515.408,98.68262,6.003932,35000,0,0,100,0),
(@PATH,3,-8823.467,518.9063,98.68262,0,0,0,0,100,0),
(@PATH,4,-8823.467,518.9063,98.68262,5.899213,10000,0,0,100,0);

-- Pathing for Lana Ashwin Entry: 54215 'TDB FORMAT' 
SET @NPC := 314606;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8543.738,`position_y`=613.7899,`position_z`=102.8977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8543.738,613.7899,102.8977,0,0,0,0,100,0),
(@PATH,2,-8543.738,613.7899,102.8977,6.126106,13000,0,0,100,0),
(@PATH,3,-8543.239,612.9439,102.8977,0,0,0,0,100,0),
(@PATH,4,-8543.239,612.9439,102.8977,3.857178,19000,0,0,100,0),
(@PATH,5,-8536.623,608.9531,102.9231,0,0,0,0,100,0),
(@PATH,6,-8535.835,603.9045,102.8977,0,0,0,0,100,0),
(@PATH,7,-8535.835,603.9045,102.8977,4.276057,27000,0,0,100,0),
(@PATH,8,-8536.929,614.6214,102.8977,0,0,0,0,100,0),
(@PATH,9,-8536.929,614.6214,102.8977,0.5934119,15000,0,0,100,0);

-- Pathing for Craggle Wobbletop Entry: 52358 'TDB FORMAT' 
SET @NPC := 314220;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8742.114,`position_y`=565.3264,`position_z`=97.44653 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`auras`) VALUES (@NPC,@PATH,0,0,257,0,645, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8742.114,565.3264,97.44653,0,0,0,0,100,0),
(@PATH,2,-8724.279,581.9375,98.00959,0,0,0,0,100,0),
(@PATH,3,-8706.552,599.9983,99.20075,0,0,0,0,100,0),
(@PATH,4,-8701.125,615.5816,99.90452,0,0,0,0,100,0),
(@PATH,5,-8702.056,636.1893,100.2635,0,0,0,0,100,0),
(@PATH,6,-8706.832,653.5018,99.88118,0,0,0,0,100,0),
(@PATH,7,-8716.931,673.6771,98.98618,0,0,0,0,100,0),
(@PATH,8,-8731.679,694.6024,99.02598,0,0,0,0,100,0),
(@PATH,9,-8744.106,710.6511,98.6385,0,0,0,0,100,0),
(@PATH,10,-8756.377,726.1945,98.46931,0,0,0,0,100,0),
(@PATH,11,-8772.681,740.0347,99.52376,0,0,0,0,100,0),
(@PATH,12,-8784.974,744.4028,99.00801,0,0,0,0,100,0),
(@PATH,13,-8806.591,741.7726,97.7635,0,0,0,0,100,0),
(@PATH,14,-8831.721,728.4132,98.3643,0,0,0,0,100,0),
(@PATH,15,-8850.835,719.2344,97.5135,0,0,0,0,100,0),
(@PATH,16,-8874.033,709.7396,97.92754,0,0,0,0,100,0),
(@PATH,17,-8888.763,701.6215,98.53374,0,0,0,0,100,0),
(@PATH,18,-8897.935,696.4219,98.95294,0,0,0,0,100,0),
(@PATH,19,-8888.763,701.6215,98.53374,0,0,0,0,100,0),
(@PATH,20,-8874.033,709.7396,97.92754,0,0,0,0,100,0),
(@PATH,21,-8850.835,719.2344,97.5135,0,0,0,0,100,0),
(@PATH,22,-8831.721,728.4132,98.3643,0,0,0,0,100,0),
(@PATH,23,-8806.591,741.7726,97.7635,0,0,0,0,100,0),
(@PATH,24,-8784.974,744.4028,99.00801,0,0,0,0,100,0),
(@PATH,25,-8772.681,740.0347,99.52376,0,0,0,0,100,0),
(@PATH,26,-8756.377,726.1945,98.46931,0,0,0,0,100,0),
(@PATH,27,-8744.106,710.6511,98.6385,0,0,0,0,100,0),
(@PATH,28,-8731.679,694.6024,99.02598,0,0,0,0,100,0),
(@PATH,29,-8716.931,673.6771,98.98618,0,0,0,0,100,0),
(@PATH,30,-8706.832,653.5018,99.88118,0,0,0,0,100,0),
(@PATH,31,-8702.056,636.1893,100.2635,0,0,0,0,100,0),
(@PATH,32,-8701.125,615.5816,99.90452,0,0,0,0,100,0),
(@PATH,33,-8706.552,599.9983,99.20075,0,0,0,0,100,0),
(@PATH,34,-8724.082,582.1758,97.8885,0,0,0,0,100,0);

-- Pathing for Stormwind Royal Guard Entry: 1756 'TDB FORMAT' 
SET @NPC := 314320;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8525.409,`position_y`=439.1311,`position_z`=105.8722 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8525.409,439.1311,105.8722,0,0,0,0,100,0),
(@PATH,2,-8517.59,428.76,105.6033,0,0,0,0,100,0),
(@PATH,3,-8503.44,410.448,115.6906,0,0,0,0,100,0),
(@PATH,4,-8476.49,405.564,116.1419,0,0,0,0,100,0),
(@PATH,5,-8459.39,418.391,125.5977,0,0,0,0,100,0),
(@PATH,6,-8447.14,427.868,125.5741,0,0,0,0,100,0),
(@PATH,7,-8439.674,418.4402,125.6087,0,0,0,0,100,0),
(@PATH,8,-8426.19,400.125,135.7049,0,0,0,0,100,0),
(@PATH,9,-8436.19,373.74,135.7005,0,0,0,0,100,0),
(@PATH,10,-8454.31,347.528,135.8054,0,0,0,0,100,0),
(@PATH,11,-8482.68,336.856,135.7155,0,0,0,0,100,0),
(@PATH,12,-8510.99,333.622,135.6857,0,0,0,0,100,0),
(@PATH,13,-8525.77,349.891,125.6314,0,0,0,0,100,0),
(@PATH,14,-8533.43,359.311,125.5952,0,0,0,0,100,0),
(@PATH,15,-8520.52,369.59,125.5979,0,0,0,0,100,0),
(@PATH,16,-8504.18,383.849,115.8748,0,0,0,0,100,0),
(@PATH,17,-8504.01,409.948,115.6906,0,0,0,0,100,0),
(@PATH,18,-8518.03,428.438,105.6024,0,0,0,0,100,0);

-- Pathing for Officer Brady Entry: 14439 'TDB FORMAT' 
SET @NPC := 314614;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8440.9,`position_y`=653.321,`position_z`=93.12654 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8440.9,653.321,93.12654,0,0,0,0,100,0),
(@PATH,2,-8428.79,661.781,94.28989,0,0,0,0,100,0),
(@PATH,3,-8413.68,671.068,95.198,0,0,0,0,100,0),
(@PATH,4,-8405.87,671.346,95.2771,0,0,0,0,100,0),
(@PATH,5,-8397.8,666.096,95.11058,0,0,0,0,100,0),
(@PATH,6,-8390.28,655.017,95.23558,0,0,0,0,100,0),
(@PATH,7,-8377.9,634.795,94.86058,0,0,0,0,100,0),
(@PATH,8,-8372.91,623.271,95.26123,0,0,0,0,100,0),
(@PATH,9,-8365.95,620.306,95.35988,0,0,0,0,100,0),
(@PATH,10,-8358.91,621.01,95.35915,0,0,0,0,100,0),
(@PATH,11,-8353.69,622.894,95.35915,0,0,0,0,100,0),
(@PATH,12,-8349.22,621.965,95.48415,0,0,0,0,100,0),
(@PATH,13,-8341.295,614.0766,99.69801,0,0,0,0,100,0),
(@PATH,14,-8335.53,607.67,99.69768,0,0,0,0,100,0),
(@PATH,15,-8327.21,596.321,99.85445,0,0,0,0,100,0),
(@PATH,16,-8318.661,586.838,99.69768,0,0,0,0,100,0),
(@PATH,17,-8316.55,583.7751,100.4331,0,0,0,0,100,0),
(@PATH,18,-8312.64,577.026,100.4977,0,0,0,0,100,0),
(@PATH,19,-8313.58,573.701,100.4977,0,0,0,0,100,0),
(@PATH,20,-8318.65,569.719,100.4977,0,0,0,0,100,0),
(@PATH,21,-8318.95,567.255,100.4977,0,0,0,0,100,0),
(@PATH,22,-8307.79,573.471,100.4977,0,0,0,0,100,0),
(@PATH,23,-8300.46,581.465,100.4977,0,0,0,0,100,0),
(@PATH,24,-8300.42,584.163,100.4977,0,0,0,0,100,0),
(@PATH,25,-8302.77,582.971,100.4977,0,0,0,0,100,0),
(@PATH,26,-8309.117,579.2571,100.4977,0,0,0,0,100,0),
(@PATH,27,-8315.96,584.017,100.8805,0,0,0,0,100,0),
(@PATH,28,-8318.16,587.233,99.81283,0,0,0,0,100,0),
(@PATH,29,-8325.72,597.49,99.89234,0,0,0,0,100,0),
(@PATH,30,-8335.06,608.122,99.69768,0,0,0,0,100,0),
(@PATH,31,-8339.322,614.1126,99.69768,0,0,0,0,100,0),
(@PATH,32,-8345.34,625.736,95.58327,0,0,0,0,100,0),
(@PATH,33,-8350.47,635.148,95.39003,0,0,0,0,100,0),
(@PATH,34,-8358.37,644.394,95.25014,0,0,0,0,100,0),
(@PATH,35,-8361.477,650.3644,97.29767,0,0,0,0,100,0),
(@PATH,36,-8363.097,656.6646,97.3227,0,0,0,0,100,0),
(@PATH,37,-8365.065,665.8271,97.44387,0,0,0,0,100,0),
(@PATH,38,-8360.7,669.91,97.45067,0,0,0,0,100,0),
(@PATH,39,-8361.877,674.6228,97.28861,0,0,0,0,100,0),
(@PATH,40,-8368.12,675.641,97.29767,0,0,0,0,100,0),
(@PATH,41,-8373.31,671.563,97.29766,0,0,0,0,100,0),
(@PATH,42,-8372.38,667.693,97.423,0,0,0,0,100,0),
(@PATH,43,-8366.73,665.319,97.42899,0,0,0,0,100,0),
(@PATH,44,-8363.92,656.347,97.45051,0,0,0,0,100,0),
(@PATH,45,-8362.87,650.031,97.29767,0,0,0,0,100,0),
(@PATH,46,-8363.021,644.2715,95.39003,0,0,0,0,100,0),
(@PATH,47,-8364.18,640.076,95.26503,0,0,0,0,100,0),
(@PATH,48,-8368.58,639.358,95.11058,0,0,0,0,100,0),
(@PATH,49,-8377.79,645.476,95.50523,0,0,0,0,100,0),
(@PATH,50,-8386.32,657.245,95.11058,0,0,0,0,100,0),
(@PATH,51,-8393.95,667.274,94.9614,0,0,0,0,100,0),
(@PATH,52,-8403.78,673.569,95.16821,0,0,0,0,100,0),
(@PATH,53,-8413.61,675.149,95.1521,0,0,0,0,100,0),
(@PATH,54,-8421.54,670.168,95.00464,0,0,0,0,100,0),
(@PATH,55,-8425.13,666.132,94.62814,0,0,0,0,100,0),
(@PATH,56,-8429.34,662.934,93.94577,0,0,0,0,100,0),
(@PATH,57,-8439.62,656.471,93.1949,0,0,0,0,100,0),
(@PATH,58,-8443.92,656.934,93.1949,0,0,0,0,100,0),
(@PATH,59,-8457.44,674.741,97.21708,0,0,0,0,100,0),
(@PATH,60,-8468.45,688.644,99.73982,0,0,0,0,100,0),
(@PATH,61,-8475.62,691.401,99.98286,0,0,0,0,100,0),
(@PATH,62,-8483.17,689.389,100.3493,0,0,0,0,100,0),
(@PATH,63,-8488.69,682.451,100.8068,0,0,0,0,100,0),
(@PATH,64,-8494.29,675.342,100.617,0,0,0,0,100,0),
(@PATH,65,-8497.41,670.632,100.6385,0,0,0,0,100,0),
(@PATH,66,-8505.49,658.682,100.4849,0,0,0,0,100,0),
(@PATH,67,-8508.51,655.823,100.6497,0,0,0,0,100,0),
(@PATH,68,-8512.29,658.012,101.2182,0,0,0,0,100,0),
(@PATH,69,-8520.71,670.792,102.8479,0,0,0,0,100,0),
(@PATH,70,-8529.791,683.2807,99.05753,0,0,0,0,100,0),
(@PATH,71,-8534.98,686.146,97.7635,0,0,0,0,100,0),
(@PATH,72,-8545.46,686.007,97.6385,0,0,0,0,100,0),
(@PATH,73,-8553.93,680.721,97.10432,0,0,0,0,100,0),
(@PATH,74,-8561.24,675.715,97.1385,0,0,0,0,100,0),
(@PATH,75,-8571.97,667.931,97.15067,0,0,0,0,100,0),
(@PATH,76,-8594.18,658.63,98.35725,0,0,0,0,100,0),
(@PATH,77,-8611.94,654.365,98.88226,0,0,0,0,100,0),
(@PATH,78,-8632.9,654.854,100.7014,0,0,0,0,100,0),
(@PATH,79,-8649.68,658.347,100.9347,0,0,0,0,100,0),
(@PATH,80,-8660.41,664.408,100.6471,0,0,0,0,100,0),
(@PATH,81,-8665.66,672.319,100.1719,0,0,0,0,100,0),
(@PATH,82,-8671.01,681.795,99.17683,0,0,0,0,100,0),
(@PATH,83,-8684.43,698.295,97.78059,0,0,0,0,100,0),
(@PATH,84,-8695.81,712.828,97.08251,0,0,0,0,100,0),
(@PATH,85,-8705.93,726.651,97.35668,0,0,0,0,100,0),
(@PATH,86,-8713.59,734.705,97.8885,0,0,0,0,100,0),
(@PATH,87,-8705.989,726.7133,97.36407,0,0,0,0,100,0),
(@PATH,88,-8713.59,734.705,97.8885,0,0,0,0,100,0),
(@PATH,89,-8719.874,733.8921,98.20097,0,0,0,0,100,0),
(@PATH,90,-8732.99,723.781,101.5783,0,0,0,0,100,0),
(@PATH,91,-8742.2,715.842,98.86562,0,0,0,0,100,0),
(@PATH,92,-8744.63,711.906,98.68172,0,0,0,0,100,0),
(@PATH,93,-8741.31,704.679,98.8896,0,0,0,0,100,0),
(@PATH,94,-8739.53,700.569,99.00764,0,0,0,0,100,0),
(@PATH,95,-8740.83,697.936,99.1405,0,0,0,0,100,0),
(@PATH,96,-8759.24,684.505,101.4374,0,0,0,0,100,0),
(@PATH,97,-8771.17,675.271,103.024,0,0,0,0,100,0),
(@PATH,98,-8776.43,671.064,103.3691,0,0,0,0,100,0),
(@PATH,99,-8776.85,666.484,103.2889,0,0,0,0,100,0),
(@PATH,100,-8768.4,657.102,103.7036,0,0,0,0,100,0),
(@PATH,101,-8763.35,648.83,103.7797,0,0,0,0,100,0),
(@PATH,102,-8759.91,637.991,103.4518,0,0,0,0,100,0),
(@PATH,103,-8759.63,628.649,102.3084,0,0,0,0,100,0),
(@PATH,104,-8762.64,619.302,99.67116,0,0,0,0,100,0),
(@PATH,105,-8767.85,612.571,97.94556,0,0,0,0,100,0),
(@PATH,106,-8781.58,601.137,97.52515,0,0,0,0,100,0),
(@PATH,107,-8790.02,594.733,97.80921,0,0,0,0,100,0),
(@PATH,108,-8795.45,594.311,97.93421,0,0,0,0,100,0),
(@PATH,109,-8801.02,596.868,97.4438,0,0,0,0,100,0),
(@PATH,110,-8815.11,613.038,95.45123,0,0,0,0,100,0),
(@PATH,111,-8827.83,624.788,94.32818,0,0,0,0,100,0),
(@PATH,112,-8844.84,640.023,96.32523,0,0,0,0,100,0),
(@PATH,113,-8845.09,644.236,96.71536,0,0,0,0,100,0),
(@PATH,114,-8839.761,648.1981,98.03027,0,0,0,0,100,0),
(@PATH,115,-8835.21,651.106,98.0269,0,0,0,0,100,0),
(@PATH,116,-8826.59,653.731,98.02496,0,0,0,0,100,0),
(@PATH,117,-8819.21,651.781,98.02496,0,0,0,0,100,0),
(@PATH,118,-8815.72,653.297,98.02105,0,0,0,0,100,0),
(@PATH,119,-8816.27,659.194,98.01458,0,0,0,0,100,0),
(@PATH,120,-8820.146,664.3714,98.01817,0,0,0,0,100,0),
(@PATH,121,-8823.88,662.924,98.01824,0,0,0,0,100,0),
(@PATH,122,-8827.65,656.026,98.02222,0,0,0,0,100,0),
(@PATH,123,-8835.293,651.998,98.03162,0,0,0,0,100,0),
(@PATH,124,-8840.55,650.561,98.02579,0,0,0,0,100,0),
(@PATH,125,-8847,648.578,96.65872,0,0,0,0,100,0),
(@PATH,126,-8850.53,651.122,96.71854,0,0,0,0,100,0),
(@PATH,127,-8855.34,655.479,96.56448,0,0,0,0,100,0),
(@PATH,128,-8862.39,655.161,96.27628,0,0,0,0,100,0),
(@PATH,129,-8866.58,651.16,96.21951,0,0,0,0,100,0),
(@PATH,130,-8880.89,642.939,97.77124,0,0,0,0,100,0),
(@PATH,131,-8884.23,641.113,99.35641,0,0,0,0,100,0),
(@PATH,132,-8891.38,636.667,99.52318,0,0,0,0,100,0),
(@PATH,133,-8906.71,628.972,99.54033,0,0,0,0,100,0),
(@PATH,134,-8914.156,625.0789,99.5231,0,0,0,0,100,0),
(@PATH,135,-8917.594,623.2486,100.3332,0,0,0,0,100,0),
(@PATH,136,-8924.57,620.403,100.226,0,0,0,0,100,0),
(@PATH,137,-8927.91,621.967,100.226,0,0,0,0,100,0),
(@PATH,138,-8930.72,627.455,100.226,0,0,0,0,100,0),
(@PATH,139,-8933.26,628.288,100.226,0,0,0,0,100,0),
(@PATH,140,-8931.651,627.7604,100.226,0,0,0,0,100,0),
(@PATH,141,-8933.26,628.288,100.226,0,0,0,0,100,0),
(@PATH,142,-8928.24,616.757,100.226,0,0,0,0,100,0),
(@PATH,143,-8922.51,606.66,100.226,0,0,0,0,100,0),
(@PATH,144,-8919.56,605.738,100.226,0,0,0,0,100,0),
(@PATH,145,-8919.23,608.719,100.226,0,0,0,0,100,0),
(@PATH,146,-8922.127,613.6187,100.226,0,0,0,0,100,0),
(@PATH,147,-8922.42,616.688,100.226,0,0,0,0,100,0),
(@PATH,148,-8917.54,622.538,100.2601,0,0,0,0,100,0),
(@PATH,149,-8914.35,624.218,99.78259,0,0,0,0,100,0),
(@PATH,150,-8906.29,628.55,99.53779,0,0,0,0,100,0),
(@PATH,151,-8891.22,636.708,99.5231,0,0,0,0,100,0),
(@PATH,152,-8883.22,639.925,99.22947,0,0,0,0,100,0),
(@PATH,153,-8876.43,641.576,96.42488,0,0,0,0,100,0),
(@PATH,154,-8866.71,641.2,96.29771,0,0,0,0,100,0),
(@PATH,155,-8860.93,641.158,96.34598,0,0,0,0,100,0),
(@PATH,156,-8853.87,644.134,96.59451,0,0,0,0,100,0),
(@PATH,157,-8851.03,650.814,96.65848,0,0,0,0,100,0),
(@PATH,158,-8851.31,656.245,96.87479,0,0,0,0,100,0),
(@PATH,159,-8848.21,663.002,97.49686,0,0,0,0,100,0),
(@PATH,160,-8832.9,671.639,98.36188,0,0,0,0,100,0),
(@PATH,161,-8820.42,677.415,97.96259,0,0,0,0,100,0),
(@PATH,162,-8803.58,682.628,100.8214,0,0,0,0,100,0),
(@PATH,163,-8793.28,680.073,101.8169,0,0,0,0,100,0),
(@PATH,164,-8785.37,676.986,102.9372,0,0,0,0,100,0),
(@PATH,165,-8779.09,669.971,103.2441,0,0,0,0,100,0),
(@PATH,166,-8774.32,668.703,103.3691,0,0,0,0,100,0),
(@PATH,167,-8769.23,672.128,103.1142,0,0,0,0,100,0),
(@PATH,168,-8757.64,682.123,101.4948,0,0,0,0,100,0),
(@PATH,169,-8739.27,696.181,99.16541,0,0,0,0,100,0),
(@PATH,170,-8737.03,700.488,98.89461,0,0,0,0,100,0),
(@PATH,171,-8741.56,708.12,98.47664,0,0,0,0,100,0),
(@PATH,172,-8741.43,711.618,98.54563,0,0,0,0,100,0),
(@PATH,173,-8730.23,720.08,101.7436,0,0,0,0,100,0),
(@PATH,174,-8717.32,730.469,98.24545,0,0,0,0,100,0),
(@PATH,175,-8713.15,731.205,97.90527,0,0,0,0,100,0),
(@PATH,176,-8696.87,710.571,97.20751,0,0,0,0,100,0),
(@PATH,177,-8689.31,698.372,97.6385,0,0,0,0,100,0),
(@PATH,178,-8676.47,683.326,98.7635,0,0,0,0,100,0),
(@PATH,179,-8668.36,670.998,99.99763,0,0,0,0,100,0),
(@PATH,180,-8658.16,660.54,100.84,0,0,0,0,100,0),
(@PATH,181,-8644.94,654.325,101.0403,0,0,0,0,100,0),
(@PATH,182,-8628,651.106,100.0388,0,0,0,0,100,0),
(@PATH,183,-8607.27,651.017,98.54596,0,0,0,0,100,0),
(@PATH,184,-8590.44,653.596,97.97626,0,0,0,0,100,0),
(@PATH,185,-8573.43,661.188,97.60627,0,0,0,0,100,0),
(@PATH,186,-8557.19,673.665,97.1385,0,0,0,0,100,0),
(@PATH,187,-8547.64,680.733,97.73347,0,0,0,0,100,0),
(@PATH,188,-8537.84,684.66,97.7635,0,0,0,0,100,0),
(@PATH,189,-8533.563,683.4695,98.21477,0,0,0,0,100,0),
(@PATH,190,-8527.58,675.2491,102.118,0,0,0,0,100,0),
(@PATH,191,-8523.14,669.149,102.8413,0,0,0,0,100,0),
(@PATH,192,-8514.69,655.889,101.1217,0,0,0,0,100,0),
(@PATH,193,-8509.94,653.549,100.6385,0,0,0,0,100,0),
(@PATH,194,-8502.23,657.375,100.461,0,0,0,0,100,0),
(@PATH,195,-8496.49,664.795,100.5293,0,0,0,0,100,0),
(@PATH,196,-8488.12,676.79,100.8768,0,0,0,0,100,0),
(@PATH,197,-8475.44,687.882,100.1287,0,0,0,0,100,0),
(@PATH,198,-8470.3,686.856,99.74532,0,0,0,0,100,0),
(@PATH,199,-8459.4,672.542,97.18851,0,0,0,0,100,0),
(@PATH,200,-8445.76,655.332,93.1949,0,0,0,0,100,0);

-- Pathing for Myrla Stoneround Entry: 44236 'TDB FORMAT' 
SET @NPC := 314464;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8366.56,`position_y`=575.859,`position_z`=97.09768 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8366.56,575.859,97.09768,0,0,0,0,100,0),
(@PATH,2,-8366.56,575.859,97.09768,1.623156,2000,0,0,100,0),
(@PATH,3,-8357.94,582.795,97.001,0,0,0,0,100,0),
(@PATH,4,-8362.4,588.651,96.9994,0,0,0,0,100,0),
(@PATH,5,-8370.89,582.118,97.0017,0,0,0,0,100,0),
(@PATH,6,-8370.89,582.118,97.0017,1.37881,2000,0,0,100,0);

-- Pathing for Officer Connelly Entry: 47688 'TDB FORMAT' 
SET @NPC := 314409;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8537.17,`position_y`=485.715,`position_z`=101.3703 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8537.17,485.715,101.3703,0,0,0,0,100,0),
(@PATH,2,-8536.56,492.865,100.1335,0,0,0,0,100,0),
(@PATH,3,-8540.9,498.453,99.213,0,0,0,0,100,0),
(@PATH,4,-8541.72,501.622,98.87165,0,0,0,0,100,0),
(@PATH,5,-8538.03,504.599,98.70832,0,0,0,0,100,0),
(@PATH,6,-8524.11,515.227,98.46122,0,0,0,0,100,0),
(@PATH,7,-8505.37,529.655,98.21525,0,0,0,0,100,0),
(@PATH,8,-8492.54,541.25,97.81988,0,0,0,0,100,0),
(@PATH,9,-8481.97,555.068,98.06988,0,0,0,0,100,0),
(@PATH,10,-8468.35,568.253,96.6907,0,0,0,0,100,0),
(@PATH,11,-8450.76,577.191,94.7769,0,0,0,0,100,0),
(@PATH,12,-8440.84,575.649,94.74809,0,0,0,0,100,0),
(@PATH,13,-8425.85,566.255,94.05686,0,0,0,0,100,0),
(@PATH,14,-8411.59,564.665,92.69505,0,0,0,0,100,0),
(@PATH,15,-8400.56,567.573,92.18973,0,0,0,0,100,0),
(@PATH,16,-8393.31,578.253,91.92184,0,0,0,0,100,0),
(@PATH,17,-8394.19,589.762,92.7557,0,0,0,0,100,0),
(@PATH,18,-8393.76,602.628,94.14209,0,0,0,0,100,0),
(@PATH,19,-8391.63,611.922,95.12939,0,0,0,0,100,0),
(@PATH,20,-8382.95,618.389,95.60046,0,0,0,0,100,0),
(@PATH,21,-8370.25,620.304,95.26123,0,0,0,0,100,0),
(@PATH,22,-8359.98,620.759,95.30544,0,0,0,0,100,0),
(@PATH,23,-8353.75,622.991,95.35915,0,0,0,0,100,0),
(@PATH,24,-8349.02,621.993,95.48415,0,0,0,0,100,0),
(@PATH,25,-8341.315,614.0599,99.69852,0,0,0,0,100,0),
(@PATH,26,-8335.46,607.59,99.69768,0,0,0,0,100,0),
(@PATH,27,-8327.16,596.281,99.85354,0,0,0,0,100,0),
(@PATH,28,-8318.694,586.7764,99.69768,0,0,0,0,100,0),
(@PATH,29,-8316.868,584.3824,100.5787,0,0,0,0,100,0),
(@PATH,30,-8312.68,576.943,100.4977,0,0,0,0,100,0),
(@PATH,31,-8313.5,573.623,100.4977,0,0,0,0,100,0),
(@PATH,32,-8318.56,569.726,100.4977,0,0,0,0,100,0),
(@PATH,33,-8316.36,567.441,100.4977,0,0,0,0,100,0),
(@PATH,34,-8307.78,573.63,100.4977,0,0,0,0,100,0),
(@PATH,35,-8300.5,581.413,100.4977,0,0,0,0,100,0),
(@PATH,36,-8300.45,584.231,100.4977,0,0,0,0,100,0),
(@PATH,37,-8302.89,582.809,100.4977,0,0,0,0,100,0),
(@PATH,38,-8309.138,579.304,100.4977,0,0,0,0,100,0),
(@PATH,39,-8315.89,584.078,100.8893,0,0,0,0,100,0),
(@PATH,40,-8318.22,587.281,99.77914,0,0,0,0,100,0),
(@PATH,41,-8325.75,597.342,99.88815,0,0,0,0,100,0),
(@PATH,42,-8335.04,608.069,99.69768,0,0,0,0,100,0),
(@PATH,43,-8339.452,614.0086,99.69768,0,0,0,0,100,0),
(@PATH,44,-8345.36,625.7,95.58778,0,0,0,0,100,0),
(@PATH,45,-8350.48,635.085,95.39003,0,0,0,0,100,0),
(@PATH,46,-8358.39,644.403,95.24928,0,0,0,0,100,0),
(@PATH,47,-8352.204,637.1161,95.35935,0,0,0,0,100,0),
(@PATH,48,-8358.39,644.403,95.24928,0,0,0,0,100,0),
(@PATH,49,-8361.518,650.3497,97.29767,0,0,0,0,100,0),
(@PATH,50,-8363.18,656.373,97.44465,0,0,0,0,100,0),
(@PATH,51,-8365.069,665.7986,97.44516,0,0,0,0,100,0),
(@PATH,52,-8360.75,669.905,97.4532,0,0,0,0,100,0),
(@PATH,53,-8361.74,674.707,97.29767,0,0,0,0,100,0),
(@PATH,54,-8368.19,675.514,97.29767,0,0,0,0,100,0),
(@PATH,55,-8373.42,671.715,97.29766,0,0,0,0,100,0),
(@PATH,56,-8372.38,667.596,97.4209,0,0,0,0,100,0),
(@PATH,57,-8366.72,665.349,97.4295,0,0,0,0,100,0),
(@PATH,58,-8363.92,656.358,97.44591,0,0,0,0,100,0),
(@PATH,59,-8362.91,650.064,97.29767,0,0,0,0,100,0),
(@PATH,60,-8363.021,644.2715,95.39003,0,0,0,0,100,0),
(@PATH,61,-8364.11,640.033,95.26503,0,0,0,0,100,0),
(@PATH,62,-8368.6,639.241,95.11058,0,0,0,0,100,0),
(@PATH,63,-8377.71,645.535,95.51231,0,0,0,0,100,0),
(@PATH,64,-8386.41,657.082,95.07323,0,0,0,0,100,0),
(@PATH,65,-8394.16,667.229,94.9614,0,0,0,0,100,0),
(@PATH,66,-8403.76,673.531,95.16577,0,0,0,0,100,0),
(@PATH,67,-8414.02,674.931,95.10291,0,0,0,0,100,0),
(@PATH,68,-8422.56,668.96,94.75732,0,0,0,0,100,0),
(@PATH,69,-8430.56,662.066,93.85153,0,0,0,0,100,0),
(@PATH,70,-8439.5,656.125,93.24239,0,0,0,0,100,0),
(@PATH,71,-8451.38,648.007,92.66512,0,0,0,0,100,0),
(@PATH,72,-8457.17,642.253,92.06197,0,0,0,0,100,0),
(@PATH,73,-8469.47,634.012,93.17827,0,0,0,0,100,0),
(@PATH,74,-8475.69,626.087,94.03833,0,0,0,0,100,0),
(@PATH,75,-8473.24,615.181,94.85632,0,0,0,0,100,0),
(@PATH,76,-8465.15,603.821,94.55984,0,0,0,0,100,0),
(@PATH,77,-8457.48,595.472,94.49809,0,0,0,0,100,0),
(@PATH,78,-8454.13,587.557,94.62309,0,0,0,0,100,0),
(@PATH,79,-8458.14,580.712,95.00005,0,0,0,0,100,0),
(@PATH,80,-8465.71,574.448,96.32439,0,0,0,0,100,0),
(@PATH,81,-8477.44,569.247,97.17923,0,0,0,0,100,0),
(@PATH,82,-8484.4,564.969,97.71111,0,0,0,0,100,0),
(@PATH,83,-8493.89,557.54,98.19488,0,0,0,0,100,0),
(@PATH,84,-8501.89,549.012,98.09548,0,0,0,0,100,0),
(@PATH,85,-8506.64,540.038,97.86135,0,0,0,0,100,0),
(@PATH,86,-8509.14,532.521,98.21122,0,0,0,0,100,0),
(@PATH,87,-8525.86,517.418,98.46122,0,0,0,0,100,0),
(@PATH,88,-8539.79,506.809,98.4809,0,0,0,0,100,0),
(@PATH,89,-8543.22,503.582,98.58051,0,0,0,0,100,0),
(@PATH,90,-8546.27,504.285,98.31281,0,0,0,0,100,0),
(@PATH,91,-8552.86,513.375,99.02131,0,0,0,0,100,0),
(@PATH,92,-8564.4,530.95,101.3228,0,0,0,0,100,0),
(@PATH,93,-8573.39,540.646,101.9676,0,0,0,0,100,0),
(@PATH,94,-8579.7,542.667,102.1584,0,0,0,0,100,0),
(@PATH,95,-8584.5,541,102.5674,0,0,0,0,100,0),
(@PATH,96,-8598.79,529.497,106.3403,0,0,0,0,100,0),
(@PATH,97,-8610.87,517.846,104.0765,0,0,0,0,100,0),
(@PATH,98,-8611.459,512.5,103.6385,0,0,0,0,100,0),
(@PATH,99,-8611.86,508.554,103.7635,0,0,0,0,100,0),
(@PATH,100,-8614.5,505.144,103.211,0,0,0,0,100,0),
(@PATH,101,-8632.28,491.085,102.735,0,0,0,0,100,0),
(@PATH,102,-8643.64,482.212,102.6313,0,0,0,0,100,0),
(@PATH,103,-8648.39,481.668,102.6313,0,0,0,0,100,0),
(@PATH,104,-8650.54,484.851,102.6342,0,0,0,0,100,0),
(@PATH,105,-8656.46,492.122,101.6686,0,0,0,0,100,0),
(@PATH,106,-8663.04,497.024,100.9591,0,0,0,0,100,0),
(@PATH,107,-8669.12,497.146,100.3561,0,0,0,0,100,0),
(@PATH,108,-8677.85,491.028,98.2947,0,0,0,0,100,0),
(@PATH,109,-8683.89,484.406,96.55093,0,0,0,0,100,0),
(@PATH,110,-8697.83,472.554,95.4739,0,0,0,0,100,0),
(@PATH,111,-8705.07,465.991,96.313,0,0,0,0,100,0),
(@PATH,112,-8712.88,458.28,97.26711,0,0,0,0,100,0),
(@PATH,113,-8706.302,464.7726,96.51366,0,0,0,0,100,0),
(@PATH,114,-8712.88,458.28,97.26711,0,0,0,0,100,0),
(@PATH,115,-8718.2,451.398,97.38869,0,0,0,0,100,0),
(@PATH,116,-8721.73,441.677,97.56227,0,0,0,0,100,0),
(@PATH,117,-8723.21,429.755,98.16845,0,0,0,0,100,0),
(@PATH,118,-8725.3,418.776,97.9724,0,0,0,0,100,0),
(@PATH,119,-8727.08,410.024,97.82079,0,0,0,0,100,0),
(@PATH,120,-8722.47,404.505,97.94579,0,0,0,0,100,0),
(@PATH,121,-8710.564,403.0293,99.32079,0,0,0,0,100,0),
(@PATH,122,-8699.34,397.847,101.5616,0,0,0,0,100,0),
(@PATH,123,-8683.92,396.082,102.3116,0,0,0,0,100,0),
(@PATH,124,-8673.88,400.115,103.519,0,0,0,0,100,0),
(@PATH,125,-8660.58,409.536,103.1512,0,0,0,0,100,0),
(@PATH,126,-8650.53,420.29,102.1079,0,0,0,0,100,0),
(@PATH,127,-8642.07,430.276,101.6763,0,0,0,0,100,0),
(@PATH,128,-8635.19,439.024,102.5902,0,0,0,0,100,0),
(@PATH,129,-8632.44,449.168,102.5825,0,0,0,0,100,0),
(@PATH,130,-8634.58,461.438,102.3756,0,0,0,0,100,0),
(@PATH,131,-8641.52,474.212,102.6313,0,0,0,0,100,0),
(@PATH,132,-8643.48,476.837,102.6313,0,0,0,0,100,0),
(@PATH,133,-8642.04,480.009,102.6313,0,0,0,0,100,0),
(@PATH,134,-8630.47,488.656,102.7422,0,0,0,0,100,0),
(@PATH,135,-8613.46,502.352,103.2635,0,0,0,0,100,0),
(@PATH,136,-8608.71,505.637,103.7635,0,0,0,0,100,0),
(@PATH,137,-8603.57,503.875,103.8885,0,0,0,0,100,0),
(@PATH,138,-8594.86,495.125,104.036,0,0,0,0,100,0),
(@PATH,139,-8583.24,480.342,104.3885,0,0,0,0,100,0),
(@PATH,140,-8574.08,471.24,104.3885,0,0,0,0,100,0),
(@PATH,141,-8566.83,467.047,104.8062,0,0,0,0,100,0),
(@PATH,142,-8557.75,463.396,104.6738,0,0,0,0,100,0),
(@PATH,143,-8549.86,461.328,104.6738,0,0,0,0,100,0),
(@PATH,144,-8543.8,459.207,104.7343,0,0,0,0,100,0),
(@PATH,145,-8533.68,446.269,105.4686,0,0,0,0,100,0),
(@PATH,146,-8523.3,429.806,105.5351,0,0,0,0,100,0),
(@PATH,147,-8513.21,416.872,110.9986,0,0,0,0,100,0),
(@PATH,148,-8504.67,406.91,115.6894,0,0,0,0,100,0),
(@PATH,149,-8504.19,396.72,115.7195,0,0,0,0,100,0),
(@PATH,150,-8506.61,389.726,115.747,0,0,0,0,100,0),
(@PATH,151,-8510.12,384.946,117.7551,0,0,0,0,100,0),
(@PATH,152,-8517.29,377.455,122.6263,0,0,0,0,100,0),
(@PATH,153,-8522.8,372.266,125.6001,0,0,0,0,100,0),
(@PATH,154,-8528.19,366.908,125.5953,0,0,0,0,100,0),
(@PATH,155,-8530.16,361.569,125.5907,0,0,0,0,100,0),
(@PATH,156,-8528.74,351.983,125.6017,0,0,0,0,100,0),
(@PATH,157,-8526.822,348.7382,125.7487,0,0,0,0,100,0),
(@PATH,158,-8523.46,343.047,128.855,0,0,0,0,100,0),
(@PATH,159,-8517.5,335.217,133.5238,0,0,0,0,100,0),
(@PATH,160,-8513.33,330.372,135.6879,0,0,0,0,100,0),
(@PATH,161,-8505.35,326.436,135.7095,0,0,0,0,100,0),
(@PATH,162,-8489.11,327.042,135.7095,0,0,0,0,100,0),
(@PATH,163,-8469.29,332.819,135.6677,0,0,0,0,100,0),
(@PATH,164,-8452.29,344.519,135.9269,0,0,0,0,100,0),
(@PATH,165,-8438.04,358.649,135.6094,0,0,0,0,100,0),
(@PATH,166,-8431.4,372.465,135.2877,0,0,0,0,100,0),
(@PATH,167,-8424.31,389.486,135.7035,0,0,0,0,100,0),
(@PATH,168,-8423.73,401.854,135.7032,0,0,0,0,100,0),
(@PATH,169,-8429.07,411.587,131.2847,0,0,0,0,100,0),
(@PATH,170,-8436.89,421.465,125.6053,0,0,0,0,100,0),
(@PATH,171,-8443.25,424.552,125.5819,0,0,0,0,100,0),
(@PATH,172,-8453.08,426.085,125.5793,0,0,0,0,100,0),
(@PATH,173,-8460.42,422.293,125.5898,0,0,0,0,100,0),
(@PATH,174,-8466.73,418.229,123.4262,0,0,0,0,100,0),
(@PATH,175,-8473.74,414.503,119.7355,0,0,0,0,100,0),
(@PATH,176,-8482.37,411.259,115.7348,0,0,0,0,100,0),
(@PATH,177,-8490.9,408.851,115.7111,0,0,0,0,100,0),
(@PATH,178,-8499.15,411.257,115.6894,0,0,0,0,100,0),
(@PATH,179,-8507.8,421.292,110.9551,0,0,0,0,100,0),
(@PATH,180,-8518.65,434.007,105.6664,0,0,0,0,100,0),
(@PATH,181,-8531.3,448.389,105.4449,0,0,0,0,100,0),
(@PATH,182,-8541.12,461.696,104.7217,0,0,0,0,100,0),
(@PATH,183,-8543.95,469.842,104.5898,0,0,0,0,100,0),
(@PATH,184,-8541.982,476.5547,103.3398,0,0,0,0,100,0);

-- Pathing for Stormwind City Guard Entry: 68 'TDB FORMAT' 
SET @NPC := 314218;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8950.371,`position_y`=508.7445,`position_z`=96.35762 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8950.371,508.7445,96.35762,0,0,0,0,100,0),
(@PATH,2,-8954.747,509.3559,96.59673,0,0,0,0,100,0),
(@PATH,3,-8958.404,509.0487,96.59682,0,0,0,0,100,0),
(@PATH,4,-8962.925,505.8056,96.6039,0,0,0,0,100,0),
(@PATH,5,-8971.028,499.3438,96.63739,0,0,0,0,100,0),
(@PATH,6,-8982.333,490.5005,96.75289,0,0,0,0,100,0),
(@PATH,7,-8989.75,484.4235,96.81427,0,0,0,0,100,0),
(@PATH,8,-8996.949,478.2845,96.83933,0,0,0,0,100,0),
(@PATH,9,-9004.832,472.2305,96.7569,0,0,0,0,100,0),
(@PATH,10,-9012.174,466.0448,96.01675,0,0,0,0,100,0),
(@PATH,11,-9018.016,461.8263,95.12923,0,0,0,0,100,0),
(@PATH,12,-9022.856,457.7466,94.22065,0,0,0,0,100,0),
(@PATH,13,-9029.848,452.3351,93.29549,0,0,0,0,100,0),
(@PATH,14,-9028.841,447.2014,92.81601,0,0,0,0,100,0),
(@PATH,15,-9020.933,436.2153,86.36632,0,0,0,0,100,0),
(@PATH,16,-9021.507,432.7257,85.23506,0,0,0,0,100,0),
(@PATH,17,-9025.52,433.3199,87.02644,0,0,0,0,100,0),
(@PATH,18,-9034.64,442.5578,93.29363,0,0,0,0,100,0),
(@PATH,19,-9037.929,440.9308,93.29333,0,0,0,0,100,0),
(@PATH,20,-9041.821,436.5854,93.29466,0,0,0,0,100,0),
(@PATH,21,-9049.56,429.8676,93.29549,0,0,0,0,100,0),
(@PATH,22,-9055.844,424.9286,93.28777,0,0,0,0,100,0),
(@PATH,23,-9049.56,429.8676,93.29549,0,0,0,0,100,0),
(@PATH,24,-9041.821,436.5854,93.29466,0,0,0,0,100,0),
(@PATH,25,-9037.929,440.9308,93.29333,0,0,0,0,100,0),
(@PATH,26,-9034.64,442.5578,93.29363,0,0,0,0,100,0),
(@PATH,27,-9025.52,433.3199,87.02644,0,0,0,0,100,0),
(@PATH,28,-9021.507,432.7257,85.23506,0,0,0,0,100,0),
(@PATH,29,-9020.933,436.2153,86.36632,0,0,0,0,100,0),
(@PATH,30,-9028.841,447.2014,92.81601,0,0,0,0,100,0),
(@PATH,31,-9029.848,452.3351,93.29549,0,0,0,0,100,0),
(@PATH,32,-9022.856,457.7466,94.22065,0,0,0,0,100,0),
(@PATH,33,-9018.016,461.8263,95.12923,0,0,0,0,100,0),
(@PATH,34,-9012.174,466.0448,96.01675,0,0,0,0,100,0),
(@PATH,35,-9004.832,472.2305,96.7569,0,0,0,0,100,0),
(@PATH,36,-8996.949,478.2845,96.83933,0,0,0,0,100,0),
(@PATH,37,-8989.75,484.4235,96.81427,0,0,0,0,100,0),
(@PATH,38,-8982.333,490.5005,96.75289,0,0,0,0,100,0),
(@PATH,39,-8971.028,499.3438,96.63739,0,0,0,0,100,0),
(@PATH,40,-8962.925,505.8056,96.6039,0,0,0,0,100,0),
(@PATH,41,-8958.404,509.0487,96.59682,0,0,0,0,100,0),
(@PATH,42,-8954.747,509.3559,96.59673,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 37944 'TDB FORMAT' 
SET @NPC := 314219;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8826.185,`position_y`=622.1094,`position_z`=94.37334 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8826.185,622.1094,94.37334,0,0,0,0,100,0),
(@PATH,2,-8810.63,605.2083,96.32818,0,0,0,0,100,0),
(@PATH,3,-8802.592,596.066,97.35115,0,0,0,0,100,0),
(@PATH,4,-8824.471,568.592,94.31514,0,0,0,0,100,0),
(@PATH,5,-8837.691,549.7222,96.50078,0,0,0,0,100,0),
(@PATH,6,-8831.207,544.908,96.78589,0,0,0,0,100,0),
(@PATH,7,-8819.263,559.0972,94.70825,0,0,0,0,100,0),
(@PATH,8,-8805.764,578.9727,96.06514,0,0,0,0,100,0),
(@PATH,9,-8789.558,592.4045,97.80921,0,0,0,0,100,0),
(@PATH,10,-8762.766,617.5121,99.19533,0,0,0,0,100,0),
(@PATH,11,-8759.373,637.5,103.3268,0,0,0,0,100,0),
(@PATH,12,-8763.721,653.6302,103.866,0,0,0,0,100,0),
(@PATH,13,-8775.688,668.5746,103.3691,0,0,0,0,100,0),
(@PATH,14,-8787.933,681.7465,102.3799,0,0,0,0,100,0),
(@PATH,15,-8806.573,684.743,100.6068,0,0,0,0,100,0),
(@PATH,16,-8824.726,678.4427,97.72699,0,0,0,0,100,0),
(@PATH,17,-8840.856,669.757,98.20115,0,0,0,0,100,0),
(@PATH,18,-8855.31,658.2847,96.76981,0,0,0,0,100,0),
(@PATH,19,-8865.203,652.0729,96.21951,0,0,0,0,100,0),
(@PATH,20,-8866.903,645.1875,96.16636,0,0,0,0,100,0),
(@PATH,21,-8860.373,641.533,96.39102,0,0,0,0,100,0),
(@PATH,22,-8849.085,645.1667,96.59451,0,0,0,0,100,0),
(@PATH,23,-8839.247,627.3837,94.34593,0,0,0,0,100,0),
(@PATH,24,-8841.551,615.7309,92.97533,0,0,0,0,100,0),
(@PATH,25,-8867.569,596.1545,92.81246,0,0,0,0,100,0),
(@PATH,26,-8886.886,583.8629,93.43856,0,0,0,0,100,0),
(@PATH,27,-8882.185,574.1511,93.31246,0,0,0,0,100,0),
(@PATH,28,-8863.263,587.6424,93.10704,0,0,0,0,100,0),
(@PATH,29,-8848.558,601.1163,92.88939,0,0,0,0,100,0),
(@PATH,30,-8834.627,616.6077,93.57713,0,0,0,0,100,0);

-- Pathing for Officer Jaxon Entry: 14423 'TDB FORMAT' 
SET @NPC := 313917;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8857.74,`position_y`=642.102,`position_z`=96.36331 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8857.74,642.102,96.36331,0,0,0,0,100,0),
(@PATH,2,-8850.46,643.066,96.59451,0,0,0,0,100,0),
(@PATH,3,-8845.32,637.816,95.79544,0,0,0,0,100,0),
(@PATH,4,-8840.18,625.976,94.15501,0,0,0,0,100,0),
(@PATH,5,-8839.32,619.351,93.20396,0,0,0,0,100,0),
(@PATH,6,-8842.4,614.681,92.97533,0,0,0,0,100,0),
(@PATH,7,-8857.47,605.059,92.72533,0,0,0,0,100,0),
(@PATH,8,-8872.44,596.267,93.06246,0,0,0,0,100,0),
(@PATH,9,-8885.76,587.531,93.62875,0,0,0,0,100,0),
(@PATH,10,-8889.2,579.241,93.29586,0,0,0,0,100,0),
(@PATH,11,-8884.41,571.583,93.18746,0,0,0,0,100,0),
(@PATH,12,-8875.75,572.806,93.61056,0,0,0,0,100,0),
(@PATH,13,-8863.61,584.851,93.41661,0,0,0,0,100,0),
(@PATH,14,-8851.72,597.983,92.85704,0,0,0,0,100,0),
(@PATH,15,-8838.03,612.28,93.47435,0,0,0,0,100,0),
(@PATH,16,-8833.01,617.422,93.8045,0,0,0,0,100,0),
(@PATH,17,-8828.31,619.413,94.36846,0,0,0,0,100,0),
(@PATH,18,-8823.67,616.932,94.85894,0,0,0,0,100,0),
(@PATH,19,-8810.59,605.248,96.32818,0,0,0,0,100,0),
(@PATH,20,-8808.12,599.115,96.89571,0,0,0,0,100,0),
(@PATH,21,-8811.34,588.977,96.80489,0,0,0,0,100,0),
(@PATH,22,-8817.06,578.738,95.21638,0,0,0,0,100,0),
(@PATH,23,-8827.94,562.146,94.90271,0,0,0,0,100,0),
(@PATH,24,-8836.99,545.214,96.91667,0,0,0,0,100,0),
(@PATH,25,-8842.813,536.3844,102.5473,0,0,0,0,100,0),
(@PATH,26,-8847.85,530.868,105.974,0,0,0,0,100,0),
(@PATH,27,-8850.82,532.003,105.9456,0,0,0,0,100,0),
(@PATH,28,-8852.95,536.531,105.9345,0,0,0,0,100,0),
(@PATH,29,-8858.02,538.415,106.3178,0,0,0,0,100,0),
(@PATH,30,-8866.391,535.9896,106.4921,0,0,0,0,100,0),
(@PATH,31,-8868.88,529.99,106.8701,0,0,0,0,100,0),
(@PATH,32,-8858.85,513.043,109.1678,0,0,0,0,100,0),
(@PATH,33,-8853.74,506.424,109.6057,0,0,0,0,100,0),
(@PATH,34,-8845.31,494.193,109.6065,0,0,0,0,100,0),
(@PATH,35,-8840.22,484.472,109.6028,0,0,0,0,100,0),
(@PATH,36,-8837.66,480.599,109.6074,0,0,0,0,100,0),
(@PATH,37,-8834.77,479.448,109.6136,0,0,0,0,100,0),
(@PATH,38,-8836.95,487.299,109.6105,0,0,0,0,100,0),
(@PATH,39,-8844.02,495.927,109.6102,0,0,0,0,100,0),
(@PATH,40,-8852.18,507.552,109.6099,0,0,0,0,100,0),
(@PATH,41,-8863.7,524.826,107.4947,0,0,0,0,100,0),
(@PATH,42,-8866.53,530.658,106.8426,0,0,0,0,100,0),
(@PATH,43,-8864.9,534.064,106.5655,0,0,0,0,100,0),
(@PATH,44,-8858.02,537.08,106.3583,0,0,0,0,100,0),
(@PATH,45,-8853.71,535.738,105.9292,0,0,0,0,100,0),
(@PATH,46,-8851.66,530.99,105.9456,0,0,0,0,100,0),
(@PATH,47,-8849.01,529.589,105.9642,0,0,0,0,100,0),
(@PATH,48,-8845.79,529.882,105.9793,0,0,0,0,100,0),
(@PATH,49,-8840.07,536.111,101.601,0,0,0,0,100,0),
(@PATH,50,-8835.37,542.875,97.07243,0,0,0,0,100,0),
(@PATH,51,-8829.26,547.92,96.37329,0,0,0,0,100,0),
(@PATH,52,-8821.48,557.46,95.00256,0,0,0,0,100,0),
(@PATH,53,-8815.7,563.615,94.36243,0,0,0,0,100,0),
(@PATH,54,-8811.12,572.536,94.95686,0,0,0,0,100,0),
(@PATH,55,-8803.3,582.158,96.90816,0,0,0,0,100,0),
(@PATH,56,-8793.97,588.352,97.68421,0,0,0,0,100,0),
(@PATH,57,-8784.64,595.061,97.68421,0,0,0,0,100,0),
(@PATH,58,-8777.35,601.026,97.40015,0,0,0,0,100,0),
(@PATH,59,-8772.46,605.719,97.27515,0,0,0,0,100,0),
(@PATH,60,-8769.39,606.299,97.15015,0,0,0,0,100,0),
(@PATH,61,-8752.92,589.005,97.52133,0,0,0,0,100,0),
(@PATH,62,-8742.93,578.293,97.64633,0,0,0,0,100,0),
(@PATH,63,-8738.69,574.87,97.64633,0,0,0,0,100,0),
(@PATH,64,-8733.19,575.979,97.48859,0,0,0,0,100,0),
(@PATH,65,-8724.83,580.993,97.96235,0,0,0,0,100,0),
(@PATH,66,-8716.41,589.102,98.3885,0,0,0,0,100,0),
(@PATH,67,-8710.38,593.505,98.7635,0,0,0,0,100,0),
(@PATH,68,-8704.85,601.403,99.13047,0,0,0,0,100,0),
(@PATH,69,-8699.9,614.069,99.80859,0,0,0,0,100,0),
(@PATH,70,-8698.96,624.563,100.0925,0,0,0,0,100,0),
(@PATH,71,-8700.71,639.292,100.1385,0,0,0,0,100,0),
(@PATH,72,-8699.636,630.2468,100.2263,0,0,0,0,100,0),
(@PATH,73,-8700.71,639.292,100.1385,0,0,0,0,100,0),
(@PATH,74,-8705.8,653.686,100.0052,0,0,0,0,100,0),
(@PATH,75,-8711.88,667.766,99.23618,0,0,0,0,100,0),
(@PATH,76,-8720.92,680.866,99.16319,0,0,0,0,100,0),
(@PATH,77,-8726.96,691.559,98.90879,0,0,0,0,100,0),
(@PATH,78,-8734.89,701.233,98.92879,0,0,0,0,100,0),
(@PATH,79,-8740.42,706.792,98.63594,0,0,0,0,100,0),
(@PATH,80,-8742.2,709.689,98.66328,0,0,0,0,100,0),
(@PATH,81,-8741.325,712.342,98.46466,0,0,0,0,100,0),
(@PATH,82,-8730.27,720.285,101.7357,0,0,0,0,100,0),
(@PATH,83,-8717.45,730.873,98.19746,0,0,0,0,100,0),
(@PATH,84,-8713.91,731.267,98.00365,0,0,0,0,100,0),
(@PATH,85,-8705.63,722.241,97.20751,0,0,0,0,100,0),
(@PATH,86,-8700.26,716.984,97.05126,0,0,0,0,100,0),
(@PATH,87,-8695.75,716.097,97.08251,0,0,0,0,100,0),
(@PATH,88,-8691.37,718.396,97.08251,0,0,0,0,100,0),
(@PATH,89,-8679.17,727.839,97.08251,0,0,0,0,100,0),
(@PATH,90,-8662.59,742.356,96.97123,0,0,0,0,100,0),
(@PATH,91,-8662.14,749.418,96.99052,0,0,0,0,100,0),
(@PATH,92,-8665.03,755.208,96.97123,0,0,0,0,100,0),
(@PATH,93,-8664.47,764.215,96.97123,0,0,0,0,100,0),
(@PATH,94,-8658.04,772.052,96.80326,0,0,0,0,100,0),
(@PATH,95,-8647.35,780.346,96.92826,0,0,0,0,100,0),
(@PATH,96,-8638.88,784.104,97.19999,0,0,0,0,100,0),
(@PATH,97,-8631.61,784.267,97.01419,0,0,0,0,100,0),
(@PATH,98,-8623.73,774.911,97.04935,0,0,0,0,100,0),
(@PATH,99,-8608.34,764.438,96.96915,0,0,0,0,100,0),
(@PATH,100,-8594.14,757.089,97.02985,0,0,0,0,100,0),
(@PATH,101,-8586.76,747.63,97.02985,0,0,0,0,100,0),
(@PATH,102,-8581.17,740.319,96.90485,0,0,0,0,100,0),
(@PATH,103,-8581.21,735.167,96.90485,0,0,0,0,100,0),
(@PATH,104,-8590.6,725.693,96.90238,0,0,0,0,100,0),
(@PATH,105,-8602.58,716.686,96.92905,0,0,0,0,100,0),
(@PATH,106,-8611.27,710.189,96.80405,0,0,0,0,100,0),
(@PATH,107,-8616.58,711.592,96.80405,0,0,0,0,100,0),
(@PATH,108,-8623.62,719.964,96.80405,0,0,0,0,100,0),
(@PATH,109,-8630.83,728.186,96.92905,0,0,0,0,100,0),
(@PATH,110,-8637.43,736.036,96.97123,0,0,0,0,100,0),
(@PATH,111,-8647.25,743.396,96.84623,0,0,0,0,100,0),
(@PATH,112,-8656.38,746.253,96.84623,0,0,0,0,100,0),
(@PATH,113,-8664.9,744.734,96.97123,0,0,0,0,100,0),
(@PATH,114,-8676.78,735.203,97.1023,0,0,0,0,100,0),
(@PATH,115,-8696.46,718.752,97.14526,0,0,0,0,100,0),
(@PATH,116,-8699.75,718.58,97.08251,0,0,0,0,100,0),
(@PATH,117,-8706.77,725.339,97.45751,0,0,0,0,100,0),
(@PATH,118,-8714.8,734.858,97.8885,0,0,0,0,100,0),
(@PATH,119,-8719.955,734.0773,98.18456,0,0,0,0,100,0),
(@PATH,120,-8733.23,723.507,101.5855,0,0,0,0,100,0),
(@PATH,121,-8742.77,715.142,98.52834,0,0,0,0,100,0),
(@PATH,122,-8744.09,708.717,98.6385,0,0,0,0,100,0),
(@PATH,123,-8739.32,702.594,98.88972,0,0,0,0,100,0),
(@PATH,124,-8741,698.439,99.1405,0,0,0,0,100,0),
(@PATH,125,-8752.09,690.316,100.365,0,0,0,0,100,0),
(@PATH,126,-8764.67,680.457,102.1732,0,0,0,0,100,0),
(@PATH,127,-8774.49,671.972,103.3706,0,0,0,0,100,0),
(@PATH,128,-8777.84,672.604,103.3159,0,0,0,0,100,0),
(@PATH,129,-8783.61,679.543,102.8864,0,0,0,0,100,0),
(@PATH,130,-8792.09,684.712,101.9837,0,0,0,0,100,0),
(@PATH,131,-8807.31,685.378,100.6287,0,0,0,0,100,0),
(@PATH,132,-8800.774,685.0936,101.446,0,0,0,0,100,0),
(@PATH,133,-8807.31,685.378,100.6287,0,0,0,0,100,0),
(@PATH,134,-8819.33,681.41,97.94562,0,0,0,0,100,0),
(@PATH,135,-8831.76,676.392,98.34686,0,0,0,0,100,0),
(@PATH,136,-8844.51,667.564,97.89268,0,0,0,0,100,0),
(@PATH,137,-8852.06,660.326,97.0347,0,0,0,0,100,0),
(@PATH,138,-8851.87,652.611,96.68265,0,0,0,0,100,0),
(@PATH,139,-8845.6,648.816,96.71951,0,0,0,0,100,0),
(@PATH,140,-8839.1,650.533,98.02631,0,0,0,0,100,0),
(@PATH,141,-8832.81,653.003,98.02633,0,0,0,0,100,0),
(@PATH,142,-8827.6,656.851,98.02197,0,0,0,0,100,0),
(@PATH,143,-8826.19,661.481,98.01896,0,0,0,0,100,0),
(@PATH,144,-8821.85,663.884,98.0175,0,0,0,0,100,0),
(@PATH,145,-8816.837,659.6501,98.01428,0,0,0,0,100,0),
(@PATH,146,-8816.73,652.264,98.0236,0,0,0,0,100,0),
(@PATH,147,-8820.92,650.835,98.02496,0,0,0,0,100,0),
(@PATH,148,-8826.27,653.736,98.02496,0,0,0,0,100,0),
(@PATH,149,-8832.38,652.297,98.02458,0,0,0,0,100,0),
(@PATH,150,-8838.72,649.597,98.02679,0,0,0,0,100,0),
(@PATH,151,-8845.311,648.4375,96.71951,0,0,0,0,100,0),
(@PATH,152,-8851.65,652.625,96.70901,0,0,0,0,100,0),
(@PATH,153,-8856.26,655.328,96.54642,0,0,0,0,100,0),
(@PATH,154,-8862.27,654.976,96.25418,0,0,0,0,100,0),
(@PATH,155,-8876.29,645.333,96.04559,0,0,0,0,100,0),
(@PATH,156,-8884.94,640.417,99.52242,0,0,0,0,100,0),
(@PATH,157,-8890.46,637.335,99.52266,0,0,0,0,100,0),
(@PATH,158,-8902.03,632.385,99.5519,0,0,0,0,100,0),
(@PATH,159,-8909.55,627.785,99.53941,0,0,0,0,100,0),
(@PATH,160,-8914.161,625.0959,99.52311,0,0,0,0,100,0),
(@PATH,161,-8917.11,623.535,100.3318,0,0,0,0,100,0),
(@PATH,162,-8924.71,620.003,100.226,0,0,0,0,100,0),
(@PATH,163,-8927.15,621.536,100.226,0,0,0,0,100,0),
(@PATH,164,-8931.01,628.069,100.226,0,0,0,0,100,0),
(@PATH,165,-8933.66,627.786,100.226,0,0,0,0,100,0),
(@PATH,166,-8929.13,616.642,100.226,0,0,0,0,100,0),
(@PATH,167,-8922.17,608.233,100.226,0,0,0,0,100,0),
(@PATH,168,-8919.88,609.726,100.226,0,0,0,0,100,0),
(@PATH,169,-8924.02,617.778,100.226,0,0,0,0,100,0),
(@PATH,170,-8916.64,623.002,100.3348,0,0,0,0,100,0),
(@PATH,171,-8914.313,624.1467,99.78259,0,0,0,0,100,0),
(@PATH,172,-8908.82,627.194,99.53564,0,0,0,0,100,0),
(@PATH,173,-8900.6,630.205,99.52666,0,0,0,0,100,0),
(@PATH,174,-8890.495,636.6929,99.52277,0,0,0,0,100,0),
(@PATH,175,-8884.19,639.575,99.5224,0,0,0,0,100,0),
(@PATH,176,-8876.33,643.938,96.05248,0,0,0,0,100,0),
(@PATH,177,-8866.18,641.372,96.21951,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314481;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8448.21,`position_y`=577.583,`position_z`=94.74809 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8448.21,577.583,94.74809,0,0,0,0,100,0),
(@PATH,2,-8438.53,575.208,94.74809,0,0,0,0,100,0),
(@PATH,3,-8431.64,568.837,94.61185,0,0,0,0,100,0),
(@PATH,4,-8422.47,565.078,93.70408,0,0,0,0,100,0),
(@PATH,5,-8412.58,565.422,92.76731,0,0,0,0,100,0),
(@PATH,6,-8403.83,568.71,92.30984,0,0,0,0,100,0),
(@PATH,7,-8395.84,576.859,92.01119,0,0,0,0,100,0),
(@PATH,8,-8394.12,588.597,92.5649,0,0,0,0,100,0),
(@PATH,9,-8393.84,598.74,93.70821,0,0,0,0,100,0),
(@PATH,10,-8393.18,607.533,94.72766,0,0,0,0,100,0),
(@PATH,11,-8388.8,612.948,95.13623,0,0,0,0,100,0),
(@PATH,12,-8382.19,619.556,95.55164,0,0,0,0,100,0),
(@PATH,13,-8378.84,623.566,95.40967,0,0,0,0,100,0),
(@PATH,14,-8377.89,628.398,95.13623,0,0,0,0,100,0),
(@PATH,15,-8377.89,628.398,95.13623,6.143559,0,0,0,100,0),
(@PATH,16,-8380.98,639.62,94.83031,0,0,0,0,100,0),
(@PATH,17,-8384.76,649.971,95.25194,0,0,0,0,100,0),
(@PATH,18,-8389.32,658.807,95.11058,0,0,0,0,100,0),
(@PATH,19,-8395.42,667.186,94.9614,0,0,0,0,100,0),
(@PATH,20,-8404.04,672.844,95.19946,0,0,0,0,100,0),
(@PATH,21,-8413.07,673.604,95.1521,0,0,0,0,100,0),
(@PATH,22,-8421.13,669.901,94.92896,0,0,0,0,100,0),
(@PATH,23,-8432.48,660.752,93.59885,0,0,0,0,100,0),
(@PATH,24,-8438.23,656.075,93.09505,0,0,0,0,100,0),
(@PATH,25,-8441.86,654.986,93.1949,0,0,0,0,100,0),
(@PATH,26,-8444.33,657.038,93.1949,0,0,0,0,100,0),
(@PATH,27,-8449.95,664.049,94.74995,0,0,0,0,100,0),
(@PATH,28,-8458.619,675.041,97.48038,0,0,0,0,100,0),
(@PATH,29,-8468.06,687.285,99.55025,0,0,0,0,100,0),
(@PATH,30,-8473.32,689.641,100.0135,0,0,0,0,100,0),
(@PATH,31,-8478.98,687.88,100.5708,0,0,0,0,100,0),
(@PATH,32,-8486.56,681.953,100.8885,0,0,0,0,100,0),
(@PATH,33,-8494.07,671.028,100.6385,0,0,0,0,100,0),
(@PATH,34,-8501.67,661.495,100.5932,0,0,0,0,100,0),
(@PATH,35,-8512.74,649.96,100.5135,0,0,0,0,100,0),
(@PATH,36,-8528.39,641.835,100.0135,0,0,0,0,100,0),
(@PATH,37,-8539.3,635.63,100.4657,0,0,0,0,100,0),
(@PATH,38,-8551.39,626.599,101.3841,0,0,0,0,100,0),
(@PATH,39,-8560.73,619.396,102.2386,0,0,0,0,100,0),
(@PATH,40,-8572.64,610.175,102.9115,0,0,0,0,100,0),
(@PATH,41,-8582.11,599.911,103.5135,0,0,0,0,100,0),
(@PATH,42,-8588.8,587.417,103.5135,0,0,0,0,100,0),
(@PATH,43,-8591.63,573.309,102.7052,0,0,0,0,100,0),
(@PATH,44,-8589.79,559.16,102.0334,0,0,0,0,100,0),
(@PATH,45,-8583.82,547.91,102.0334,0,0,0,0,100,0),
(@PATH,46,-8575.34,535.382,101.8201,0,0,0,0,100,0),
(@PATH,47,-8563.85,521.712,100.6413,0,0,0,0,100,0),
(@PATH,48,-8554.03,509.247,98.66596,0,0,0,0,100,0),
(@PATH,49,-8547.85,503.378,98.57282,0,0,0,0,100,0),
(@PATH,50,-8543.4,503.104,98.63789,0,0,0,0,100,0),
(@PATH,51,-8541.73,504.49,98.77619,0,0,0,0,100,0),
(@PATH,52,-8530.34,513.177,98.46122,0,0,0,0,100,0),
(@PATH,53,-8519.73,521.319,98.46122,0,0,0,0,100,0),
(@PATH,54,-8511.68,527.729,98.46122,0,0,0,0,100,0),
(@PATH,55,-8497.13,540.33,97.97198,0,0,0,0,100,0),
(@PATH,56,-8484.18,554.988,98.06988,0,0,0,0,100,0),
(@PATH,57,-8473.86,564.444,97.12066,0,0,0,0,100,0),
(@PATH,58,-8459.31,574.096,95.67778,0,0,0,0,100,0);
-- 0x203CB8000001EE00002F4D00007ABEE6 .go -8448.21 577.583 94.74809

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314635;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8494.79,`position_y`=682.359,`position_z`=101.2651 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8494.79,682.359,101.2651,0,0,0,0,100,0),
(@PATH,2,-8492.709,678.125,100.8885,0,0,0,0,100,0),
(@PATH,3,-8494.57,674.342,100.6385,0,0,0,0,100,0),
(@PATH,4,-8499.87,666.703,100.7523,0,0,0,0,100,0),
(@PATH,5,-8504.35,660.137,100.5135,0,0,0,0,100,0),
(@PATH,6,-8507.55,656.974,100.607,0,0,0,0,100,0),
(@PATH,7,-8510.32,657.3027,101.1149,0,0,0,0,100,0),
(@PATH,8,-8512.56,659.063,101.3661,0,0,0,0,100,0),
(@PATH,9,-8519.54,669.622,102.7959,0,0,0,0,100,0),
(@PATH,10,-8527.762,681.0116,100.5279,0,0,0,0,100,0),
(@PATH,11,-8530.387,684.9006,98.265,0,0,0,0,100,0),
(@PATH,12,-8530.55,688.097,97.7635,0,0,0,0,100,0),
(@PATH,13,-8528.2,690.958,97.78609,0,0,0,0,100,0),
(@PATH,14,-8516.95,698.382,97.3885,0,0,0,0,100,0),
(@PATH,15,-8503.22,708.743,97.71669,0,0,0,0,100,0),
(@PATH,16,-8491.9,717.604,97.98354,0,0,0,0,100,0),
(@PATH,17,-8482.73,725.778,98.16409,0,0,0,0,100,0),
(@PATH,18,-8476.798,732.3755,98.59451,0,0,0,0,100,0),
(@PATH,19,-8476.39,736.401,98.1945,0,0,0,0,100,0),
(@PATH,20,-8483.94,745.316,98.39451,0,0,0,0,100,0),
(@PATH,21,-8493.45,754.255,98.3945,0,0,0,0,100,0),
(@PATH,22,-8504.05,764.936,98.56689,0,0,0,0,100,0),
(@PATH,23,-8510.47,771.328,97.74396,0,0,0,0,100,0),
(@PATH,24,-8512.54,775.479,99.22662,0,0,0,0,100,0),
(@PATH,25,-8512.66,779.127,100.5258,0,0,0,0,100,0),
(@PATH,26,-8509.34,782.639,102.3426,0,0,0,0,100,0),
(@PATH,27,-8503.61,784.811,104.0574,0,0,0,0,100,0),
(@PATH,28,-8496.28,786.54,105.1863,0,0,0,0,100,0),
(@PATH,29,-8488.69,791.925,105.7602,0,0,0,0,100,0),
(@PATH,30,-8482.22,799.236,106.4167,0,0,0,0,100,0),
(@PATH,31,-8479.27,808.988,106.3242,0,0,0,0,100,0),
(@PATH,32,-8479.87,819.135,106.0959,0,0,0,0,100,0),
(@PATH,33,-8482.07,826.849,105.9149,0,0,0,0,100,0),
(@PATH,34,-8489.36,832.674,105.8242,0,0,0,0,100,0),
(@PATH,35,-8495.24,835.684,105.8569,0,0,0,0,100,0),
(@PATH,36,-8498.73,839.969,105.9819,0,0,0,0,100,0),
(@PATH,37,-8498.23,845.906,106.1069,0,0,0,0,100,0),
(@PATH,38,-8493.51,849.816,106.0156,0,0,0,0,100,0),
(@PATH,39,-8489.91,856.583,105.8795,0,0,0,0,100,0),
(@PATH,40,-8490.08,864.049,105.7319,0,0,0,0,100,0),
(@PATH,41,-8492.066,874.3994,106.4444,0,0,0,0,100,0),
(@PATH,42,-8492.066,874.3994,106.4444,5.026548,16000,0,0,100,0),
(@PATH,43,-8489.2,864.54,105.7319,0,0,0,0,100,0),
(@PATH,44,-8490.89,855.398,105.8569,0,0,0,0,100,0),
(@PATH,45,-8495.31,848.875,106.1069,0,0,0,0,100,0),
(@PATH,46,-8497.81,842.335,105.9996,0,0,0,0,100,0),
(@PATH,47,-8496.95,837.158,105.8569,0,0,0,0,100,0),
(@PATH,48,-8493.65,834.269,105.8569,0,0,0,0,100,0),
(@PATH,49,-8487.82,833.021,105.8242,0,0,0,0,100,0),
(@PATH,50,-8481.79,829.016,105.8242,0,0,0,0,100,0),
(@PATH,51,-8479.99,823.816,105.9855,0,0,0,0,100,0),
(@PATH,52,-8479.29,813.741,106.1516,0,0,0,0,100,0),
(@PATH,53,-8479.89,804.453,106.4492,0,0,0,0,100,0),
(@PATH,54,-8484.72,796.224,106.1511,0,0,0,0,100,0),
(@PATH,55,-8493.48,788.984,105.4073,0,0,0,0,100,0),
(@PATH,56,-8503.35,785.009,104.1437,0,0,0,0,100,0),
(@PATH,57,-8509.36,781.24,101.8716,0,0,0,0,100,0),
(@PATH,58,-8510.846,773.3809,98.55939,0,0,0,0,100,0),
(@PATH,59,-8507.54,768.472,98.03841,0,0,0,0,100,0),
(@PATH,60,-8499.31,760.278,98.48501,0,0,0,0,100,0),
(@PATH,61,-8490.29,751.472,98.3945,0,0,0,0,100,0),
(@PATH,62,-8481.8,743.642,98.39451,0,0,0,0,100,0),
(@PATH,63,-8476.72,737.566,98.2743,0,0,0,0,100,0),
(@PATH,64,-8476.16,734.842,98.1945,0,0,0,0,100,0),
(@PATH,65,-8478.59,731.884,98.59451,0,0,0,0,100,0),
(@PATH,66,-8487.3,725.483,98.39297,0,0,0,0,100,0),
(@PATH,67,-8496.39,719.743,98.32876,0,0,0,0,100,0),
(@PATH,68,-8509.52,709.71,97.90602,0,0,0,0,100,0),
(@PATH,69,-8523.97,699.167,97.3885,0,0,0,0,100,0),
(@PATH,70,-8532.02,691.528,97.7635,0,0,0,0,100,0),
(@PATH,71,-8533.23,686.066,97.7635,0,0,0,0,100,0),
(@PATH,72,-8532.02,680.807,99.37415,0,0,0,0,100,0),
(@PATH,73,-8524.04,668.727,102.8441,0,0,0,0,100,0),
(@PATH,74,-8515.42,656.913,101.3437,0,0,0,0,100,0),
(@PATH,75,-8511.459,655.209,100.6385,0,0,0,0,100,0),
(@PATH,76,-8505.85,655.691,100.5279,0,0,0,0,100,0),
(@PATH,77,-8496.87,662.906,100.5293,0,0,0,0,100,0),
(@PATH,78,-8490.13,673.208,100.6385,0,0,0,0,100,0),
(@PATH,79,-8489.76,677.283,100.7249,0,0,0,0,100,0),
(@PATH,80,-8492.801,681.6151,101.2113,0,0,0,0,100,0),
(@PATH,81,-8498.48,686.639,100.8977,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314321;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8447.39,`position_y`=451.179,`position_z`=169.8121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8447.39,451.179,169.8121,0,0,0,0,100,0),
(@PATH,2,-8441.7,453.691,169.774,0,0,0,0,100,0),
(@PATH,3,-8436.51,452.59,169.8241,0,0,0,0,100,0),
(@PATH,4,-8433.13,447.307,169.7737,0,0,0,0,100,0),
(@PATH,5,-8427.79,434.84,169.5635,0,0,0,0,100,0),
(@PATH,6,-8427.79,434.84,169.5635,1.902409,17000,0,0,100,0),
(@PATH,7,-8432.1,445.181,169.7904,0,0,0,0,100,0),
(@PATH,8,-8434.56,449.675,169.7522,0,0,0,0,100,0),
(@PATH,9,-8438.01,453.087,169.7289,0,0,0,0,100,0),
(@PATH,10,-8443.1,453.432,169.7868,0,0,0,0,100,0),
(@PATH,11,-8453.57,453.724,169.2472,0,0,0,0,100,0),
(@PATH,12,-8469.94,455.333,162.8454,0,0,0,0,100,0),
(@PATH,13,-8486.67,455.578,154.3954,0,0,0,0,100,0),
(@PATH,14,-8498.42,454.005,154.5549,0,0,0,0,100,0),
(@PATH,15,-8506.34,452.238,154.1178,0,0,0,0,100,0),
(@PATH,16,-8514.94,452.578,153.4812,0,10000,0,0,100,0),
(@PATH,17,-8506.04,449.99,154.3002,0,0,0,0,100,0),
(@PATH,18,-8500.55,452.964,154.4781,0,0,0,0,100,0),
(@PATH,19,-8490.63,454.753,154.4181,0,0,0,0,100,0),
(@PATH,20,-8471.99,452.783,161.7066,0,0,0,0,100,0),
(@PATH,21,-8456.93,450.608,169.2501,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314316;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8647.848,`position_y`=578.2299,`position_z`=120.6503 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8647.848,578.2299,120.6503,0,0,0,0,100,0),
(@PATH,2,-8647.848,578.2299,120.6503,4.590216,15000,0,0,100,0),
(@PATH,3,-8642.681,577.4731,120.6977,0,0,0,0,100,0),
(@PATH,4,-8635.05,576.266,123.4977,0,0,0,0,100,0),
(@PATH,5,-8632.21,572.568,123.4977,0,0,0,0,100,0),
(@PATH,6,-8627.38,572.366,123.4977,0,0,0,0,100,0),
(@PATH,7,-8623.72,575.908,123.4977,0,0,0,0,100,0),
(@PATH,8,-8624.38,581.049,123.4977,0,0,0,0,100,0),
(@PATH,9,-8626.97,583.385,123.4977,0,0,0,0,100,0),
(@PATH,10,-8625.065,591.7084,120.6977,0,0,0,0,100,0),
(@PATH,11,-8624.02,602.337,120.682,0,0,0,0,100,0),
(@PATH,12,-8622.72,613.148,120.6977,0,0,0,0,100,0),
(@PATH,13,-8622.54,620.514,123.4977,0,0,0,0,100,0),
(@PATH,14,-8618.87,622.981,123.4977,0,0,0,0,100,0),
(@PATH,15,-8618,628.087,123.4977,0,0,0,0,100,0),
(@PATH,16,-8620.86,632.094,123.4977,0,0,0,0,100,0),
(@PATH,17,-8624.46,632.253,123.4977,0,0,0,0,100,0),
(@PATH,18,-8628.94,629.41,123.4977,0,0,0,0,100,0),
(@PATH,19,-8636.527,630.0401,120.6836,0,0,0,0,100,0),
(@PATH,20,-8641.78,630.851,120.661,0,0,0,0,100,0),
(@PATH,21,-8641.78,630.851,120.661,1.396263,18000,0,0,100,0),
(@PATH,22,-8636.73,630.516,120.6591,0,0,0,0,100,0),
(@PATH,23,-8629.61,629.29,123.4977,0,0,0,0,100,0),
(@PATH,24,-8624.98,632.066,123.4977,0,0,0,0,100,0),
(@PATH,25,-8620.13,631.858,123.4977,0,0,0,0,100,0),
(@PATH,26,-8618.07,628.134,123.4977,0,0,0,0,100,0),
(@PATH,27,-8617.96,623.514,123.4977,0,0,0,0,100,0),
(@PATH,28,-8622.47,621.328,123.4977,0,0,0,0,100,0),
(@PATH,29,-8623.74,612.372,120.6977,0,0,0,0,100,0),
(@PATH,30,-8624.88,602.083,120.665,0,0,0,0,100,0),
(@PATH,31,-8626.04,592.094,120.6652,0,0,0,0,100,0),
(@PATH,32,-8627.11,583.248,123.4977,0,0,0,0,100,0),
(@PATH,33,-8623.96,578.991,123.4977,0,0,0,0,100,0),
(@PATH,34,-8625.79,573.543,123.4977,0,0,0,0,100,0),
(@PATH,35,-8631.46,573.283,123.4977,0,0,0,0,100,0),
(@PATH,36,-8634.26,576.733,123.4977,0,0,0,0,100,0),
(@PATH,37,-8642.687,577.4206,120.6977,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314346;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8219.1,`position_y`=891.293,`position_z`=106.6977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8219.1,891.293,106.6977,0,0,0,0,100,0),
(@PATH,2,-8219.1,891.293,106.6977,4.363323,11000,0,0,100,0),
(@PATH,3,-8232.23,869.372,106.1377,0,0,0,0,100,0),
(@PATH,4,-8245.39,850.807,108.2462,0,0,0,0,100,0),
(@PATH,5,-8255.57,839.934,111.595,0,0,0,0,100,0),
(@PATH,6,-8266.31,829.708,118.3986,0,0,0,0,100,0),
(@PATH,7,-8272.24,823.774,121.0449,0,0,0,0,100,0),
(@PATH,8,-8284.35,802.997,126.2397,0,0,0,0,100,0),
(@PATH,9,-8289.78,793.363,127.8977,0,0,0,0,100,0),
(@PATH,10,-8289.78,793.363,127.8977,0.9773844,0,0,0,100,0),
(@PATH,11,-8277.72,813.681,123.4626,0,0,0,0,100,0),
(@PATH,12,-8267.59,827.589,119.6402,0,0,0,0,100,0),
(@PATH,13,-8254.39,840.236,111.0594,0,0,0,0,100,0),
(@PATH,14,-8247.42,847.557,108.4776,0,0,0,0,100,0),
(@PATH,15,-8232.86,865.71,106.0704,0,0,0,0,100,0),
(@PATH,16,-8224.96,878.2913,106.3829,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8345.56,`position_y`=585.092,`position_z`=140.0977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8345.56,585.092,140.0977,0,0,0,0,100,0),
(@PATH,2,-8348.41,588.172,140.0977,0,0,0,0,100,0),
(@PATH,3,-8348.41,588.172,140.0977,0.9599311,16000,0,0,100,0),
(@PATH,4,-8357.69,583.986,140.0977,0,0,0,0,100,0),
(@PATH,5,-8356.73,577.035,140.0977,0,0,0,0,100,0),
(@PATH,6,-8365.96,567.318,138.9721,0,0,0,0,100,0),
(@PATH,7,-8386.34,555.436,143.8027,0,0,0,0,100,0),
(@PATH,8,-8406.28,537.281,149.5062,0,0,0,0,100,0),
(@PATH,9,-8413.99,530.503,149.4977,0,0,0,0,100,0),
(@PATH,10,-8421.39,519.139,149.4363,0,0,0,0,100,0),
(@PATH,11,-8424.92,496.161,148.1134,0,0,0,0,100,0),
(@PATH,12,-8430.881,480.4485,155.0549,0,0,0,0,100,0),
(@PATH,13,-8434.16,464.047,155.1439,0,0,0,0,100,0),
(@PATH,14,-8433.27,463.727,155.1378,0,0,0,0,100,0),
(@PATH,15,-8433.27,463.727,155.1378,1.239184,15000,0,0,100,0),
(@PATH,16,-8423.84,494.227,148.5325,0,0,0,0,100,0),
(@PATH,17,-8420.93,511.694,149.1081,0,0,0,0,100,0),
(@PATH,18,-8419.833,520.1927,149.4977,0,0,0,0,100,0),
(@PATH,19,-8416.37,523.288,149.4977,0,0,0,0,100,0),
(@PATH,20,-8411.78,526.512,149.4977,0,0,0,0,100,0),
(@PATH,21,-8411.37,531.642,149.4977,0,0,0,0,100,0),
(@PATH,22,-8402.96,538.354,149.714,0,0,0,0,100,0),
(@PATH,23,-8385.47,550.613,143.6802,0,0,0,0,100,0),
(@PATH,24,-8367.7,561.953,139.5601,0,0,0,0,100,0),
(@PATH,25,-8361.55,569.3,138.8977,0,0,0,0,100,0),
(@PATH,26,-8358.37,573.804,140.0977,0,0,0,0,100,0),
(@PATH,27,-8354.86,576.139,140.0977,0,0,0,0,100,0),
(@PATH,28,-8348.47,576.552,140.0977,0,0,0,0,100,0),
(@PATH,29,-8345.18,580.226,140.0977,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8954.93,`position_y`=1008.29,`position_z`=152.3497 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8954.93,1008.29,152.3497,0,0,0,0,100,0),
(@PATH,2,-8964.17,998.965,152.6351,0,0,0,0,100,0),
(@PATH,3,-8964.17,998.965,152.6351,0.7679449,10000,0,0,100,0),
(@PATH,4,-8954.93,1008.29,152.3497,0,0,0,0,100,0),
(@PATH,5,-8935.573,1015.063,152.0757,0,0,0,0,100,0),
(@PATH,6,-8914.98,1012.43,148.5928,0,0,0,0,100,0),
(@PATH,7,-8894.771,1004.378,148.5929,0,0,0,0,100,0),
(@PATH,8,-8882.01,984.314,148.5929,0,0,0,0,100,0),
(@PATH,9,-8882.01,984.314,148.5929,2.094395,18000,0,0,100,0),
(@PATH,10,-8894.38,1003.39,148.5929,0,0,0,0,100,0),
(@PATH,11,-8914.75,1012.68,148.5928,0,0,0,0,100,0),
(@PATH,12,-8935.237,1014.323,152.0251,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313806;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9055.5,`position_y`=889.243,`position_z`=140.44 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9055.5,889.243,140.44,0,0,0,0,100,0),
(@PATH,2,-9063.17,868.023,140.5603,0,0,0,0,100,0),
(@PATH,3,-9062.08,848.616,140.1929,0,0,0,0,100,0),
(@PATH,4,-9054.19,828.701,138.3929,0,0,0,0,100,0),
(@PATH,5,-9039.76,814.233,138.3929,0,0,0,0,100,0),
(@PATH,6,-9034.1,807.434,138.3929,0,0,0,0,100,0),
(@PATH,7,-9034.1,807.434,138.3929,2.495821,12000,0,0,100,0),
(@PATH,8,-9048.33,818.599,138.3929,0,0,0,0,100,0),
(@PATH,9,-9056.62,827.274,138.3929,0,0,0,0,100,0),
(@PATH,10,-9064.21,844.91,140.1283,0,0,0,0,100,0),
(@PATH,11,-9066.21,868.2,140.5244,0,0,0,0,100,0),
(@PATH,12,-9059.28,889,140.54,0,0,0,0,100,0),
(@PATH,13,-9048.19,903.668,140.5929,0,0,0,0,100,0),
(@PATH,14,-9048.19,903.668,140.5929,4.118977,20000,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8985.63,`position_y`=987.658,`position_z`=150.7929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8985.63,987.658,150.7929,0,0,0,0,100,0),
(@PATH,2,-8985.63,987.658,150.7929,3.403392,18000,0,0,100,0),
(@PATH,3,-9016.39,979.493,149.5928,0,0,0,0,100,0),
(@PATH,4,-9025.31,970.932,145.7287,0,0,0,0,100,0),
(@PATH,5,-9032.723,961.3311,142.795,0,0,0,0,100,0),
(@PATH,6,-9038.64,944.899,139.8593,0,0,0,0,100,0),
(@PATH,7,-9040.48,925.491,140.6955,0,0,0,0,100,0),
(@PATH,8,-9040.48,925.491,140.6955,1.448623,18000,0,0,100,0),
(@PATH,9,-9038.49,944.767,139.8687,0,0,0,0,100,0),
(@PATH,10,-9031.5,963.153,142.8713,0,0,0,0,100,0),
(@PATH,11,-9025.31,970.932,145.7287,0,0,0,0,100,0),
(@PATH,12,-9016.39,979.493,149.5928,0,0,0,0,100,0),
(@PATH,13,-9000.04,984.3,150.5929,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314334;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8674.37,`position_y`=580.179,`position_z`=123.4977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8674.37,580.179,123.4977,0,0,0,0,100,0),
(@PATH,2,-8670.75,582.958,123.4977,0,0,0,0,100,0),
(@PATH,3,-8663.47,581.698,120.6977,0,0,0,0,100,0),
(@PATH,4,-8658.39,580.658,120.6706,0,0,0,0,100,0),
(@PATH,5,-8658,580.457,120.6691,0,0,0,0,100,0),
(@PATH,6,-8658,580.457,120.6691,4.415683,10000,0,0,100,0),
(@PATH,7,-8670.45,582.802,123.4977,0,0,0,0,100,0),
(@PATH,8,-8674.43,580.526,123.4977,0,0,0,0,100,0),
(@PATH,9,-8678.76,580.102,123.4977,0,0,0,0,100,0),
(@PATH,10,-8681.75,583.568,123.4977,0,0,0,0,100,0),
(@PATH,11,-8682.19,588.205,123.4977,0,0,0,0,100,0),
(@PATH,12,-8677.87,590.53,123.4977,0,0,0,0,100,0),
(@PATH,13,-8677.17,598.458,120.7306,0,0,0,0,100,0),
(@PATH,14,-8675.7,608.547,120.6588,0,0,0,0,100,0),
(@PATH,15,-8674.84,618.944,120.7232,0,0,0,0,100,0),
(@PATH,16,-8673.63,626.488,123.4977,0,0,0,0,100,0),
(@PATH,17,-8676.48,630.872,123.4977,0,0,0,0,100,0),
(@PATH,18,-8676.27,635.24,123.4977,0,0,0,0,100,0),
(@PATH,19,-8671.59,638.04,123.4977,0,0,0,0,100,0),
(@PATH,20,-8667.33,636.109,123.4977,0,0,0,0,100,0),
(@PATH,21,-8665.05,633.285,123.4977,0,0,0,0,100,0),
(@PATH,22,-8656.47,632.995,120.6977,0,0,0,0,100,0),
(@PATH,23,-8652.74,632.653,120.6905,0,0,0,0,100,0),
(@PATH,24,-8652.74,632.653,120.6905,1.48353,0,0,0,100,0),
(@PATH,25,-8664.9,633.858,123.4977,0,0,0,0,100,0),
(@PATH,26,-8667.5,636.877,123.4977,0,0,0,0,100,0),
(@PATH,27,-8671.27,638.099,123.4977,0,0,0,0,100,0),
(@PATH,28,-8675.58,636.102,123.4977,0,0,0,0,100,0),
(@PATH,29,-8677.31,632.573,123.4977,0,0,0,0,100,0),
(@PATH,30,-8675.35,628.215,123.4977,0,0,0,0,100,0),
(@PATH,31,-8673.58,626.137,123.4977,0,0,0,0,100,0),
(@PATH,32,-8674.88,618.201,120.7142,0,0,0,0,100,0),
(@PATH,33,-8675.777,609.0536,120.7448,0,0,0,0,100,0),
(@PATH,34,-8677.365,598.8329,120.6977,0,0,0,0,100,0),
(@PATH,35,-8678.15,591.328,123.4977,0,0,0,0,100,0),
(@PATH,36,-8681.48,588.722,123.4977,0,0,0,0,100,0),
(@PATH,37,-8681.89,583.752,123.4977,0,0,0,0,100,0),
(@PATH,38,-8678.62,580.229,123.4977,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313709;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8462.83,`position_y`=902.264,`position_z`=99.10195 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8462.83,902.264,99.10195,0,0,0,0,100,0),
(@PATH,2,-8462.83,902.264,99.10195,2.129302,45000,0,0,100,0),
(@PATH,3,-8456.03,907.234,99.35195,0,0,0,0,100,0),
(@PATH,4,-8449.83,912.122,99.60195,0,0,0,0,100,0),
(@PATH,5,-8441.14,917.491,99.22695,0,0,0,0,100,0),
(@PATH,6,-8432.2,923.556,98.88975,0,0,0,0,100,0),
(@PATH,7,-8423.38,930.104,98.77207,0,0,0,0,100,0),
(@PATH,8,-8415.42,935.493,98.38635,0,0,0,0,100,0),
(@PATH,9,-8406.39,941.554,98.03711,0,0,0,0,100,0),
(@PATH,10,-8395.65,946.781,97.48492,0,0,0,0,100,0),
(@PATH,11,-8386.01,947.811,97.06939,0,0,0,0,100,0),
(@PATH,12,-8376.68,945.944,96.81939,0,0,0,0,100,0),
(@PATH,13,-8364.99,940.899,96.84547,0,0,0,0,100,0),
(@PATH,14,-8352.54,935.314,96.92017,0,0,0,0,100,0),
(@PATH,15,-8340.8,929.769,96.98351,0,0,0,0,100,0),
(@PATH,16,-8327.48,922.67,97.26117,0,0,0,0,100,0),
(@PATH,17,-8313.93,914.561,97.76117,0,0,0,0,100,0),
(@PATH,18,-8307.23,911.873,97.89886,0,0,0,0,100,0),
(@PATH,19,-8295.16,907.153,97.93992,0,0,0,0,100,0),
(@PATH,20,-8284.69,902.361,100.4211,0,0,0,0,100,0),
(@PATH,21,-8265.26,892.922,100.4211,0,0,0,0,100,0),
(@PATH,22,-8261.79,893.651,100.4211,0,0,0,0,100,0),
(@PATH,23,-8261.79,893.651,100.4211,2.75762,54000,0,0,100,0),
(@PATH,24,-8279.55,899.773,100.4211,0,0,0,0,100,0),
(@PATH,25,-8286.18,903.165,100.4211,0,0,0,0,100,0),
(@PATH,26,-8292.188,905.7285,97.81492,0,0,0,0,100,0),
(@PATH,27,-8300.37,910.071,98.01117,0,0,0,0,100,0),
(@PATH,28,-8305.8,915.26,97.85919,0,0,0,0,100,0),
(@PATH,29,-8309.43,918.356,97.63617,0,0,0,0,100,0),
(@PATH,30,-8320.97,924.561,97.38617,0,0,0,0,100,0),
(@PATH,31,-8328.67,928.599,97.13617,0,0,0,0,100,0),
(@PATH,32,-8335.5,932.219,96.98351,0,0,0,0,100,0),
(@PATH,33,-8341.83,935.436,96.84547,0,0,0,0,100,0),
(@PATH,34,-8347.82,938.226,96.82093,0,0,0,0,100,0),
(@PATH,35,-8357.89,942.281,96.83424,0,0,0,0,100,0),
(@PATH,36,-8364.73,945.455,96.72047,0,0,0,0,100,0),
(@PATH,37,-8374.54,949.628,96.55157,0,0,0,0,100,0),
(@PATH,38,-8383.89,951.648,96.81939,0,0,0,0,100,0),
(@PATH,39,-8391.25,951.694,97.06939,0,0,0,0,100,0),
(@PATH,40,-8398.85,949.774,97.44439,0,0,0,0,100,0),
(@PATH,41,-8409.36,943.299,98.0188,0,0,0,0,100,0),
(@PATH,42,-8419.17,936.826,98.45801,0,0,0,0,100,0),
(@PATH,43,-8429.75,929.971,98.77891,0,0,0,0,100,0),
(@PATH,44,-8439.83,923.262,99.10195,0,0,0,0,100,0),
(@PATH,45,-8448.69,916.944,99.50613,0,0,0,0,100,0),
(@PATH,46,-8456.81,909.536,99.22695,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 313836;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8999.094,`position_y`=835.6267,`position_z`=105.8757 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8999.094,835.6267,105.8757,0,0,0,0,100,0),
(@PATH,2,-8989.134,836.3607,105.896,0,0,0,0,100,0),
(@PATH,3,-8975.819,855.2985,105.9418,0,0,0,0,100,0),
(@PATH,4,-8946.073,862.1788,104.2821,0,0,0,0,100,0),
(@PATH,5,-8923.885,855.8956,98.75962,0,0,0,0,100,0),
(@PATH,6,-8910.681,845.6351,96.41013,0,0,0,0,100,0),
(@PATH,7,-8897.915,861.8436,96.34712,0,0,0,0,100,0),
(@PATH,8,-8887.008,894.9473,104.8007,0,0,0,0,100,0),
(@PATH,9,-8895.105,910.8882,110.6451,0,0,0,0,100,0),
(@PATH,10,-8854.335,933.8832,102.4533,0,0,0,0,100,0),
(@PATH,11,-8895.105,910.8882,110.6451,0,0,0,0,100,0),
(@PATH,12,-8887.221,894.8487,104.777,0,0,0,0,100,0),
(@PATH,13,-8898.143,862.0516,96.34712,0,0,0,0,100,0),
(@PATH,14,-8910.95,844.7175,96.3325,0,0,0,0,100,0),
(@PATH,15,-8897.665,824.4957,92.22282,0,0,0,0,100,0),
(@PATH,16,-8900.968,800.7687,87.70921,0,0,0,0,100,0),
(@PATH,17,-8931.896,772.2679,88.57969,0,0,0,0,100,0),
(@PATH,18,-8963.62,770.3228,94.62934,0,0,0,0,100,0),
(@PATH,19,-8987.596,793.0107,100.9222,0,0,0,0,100,0);

-- Pathing for Erich Lohan Entry: 3627 'TDB FORMAT' 
SET @NPC := 313872;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8946.344,`position_y`=955.1563,`position_z`=117.3027 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8946.344,955.1563,117.3027,0,0,0,0,100,0),
(@PATH,2,-8931.816,949.7118,117.334,0,0,0,0,100,0),
(@PATH,3,-8920.719,949.9323,117.4102,0,0,0,0,100,0),
(@PATH,4,-8913.196,939.5139,117.1439,0,0,0,0,100,0),
(@PATH,5,-8901.958,921.1684,113.7942,0,0,0,0,100,0),
(@PATH,6,-8890.076,901.2066,107.3182,0,0,0,0,100,0),
(@PATH,7,-8888.372,891.6476,103.9439,0,0,0,0,100,0),
(@PATH,8,-8892.754,874.5608,99.40784,0,0,0,0,100,0),
(@PATH,9,-8899.431,861.0261,96.34712,0,0,0,0,100,0),
(@PATH,10,-8907.073,849.4705,96.43736,0,0,0,0,100,0),
(@PATH,11,-8915.045,852.2465,96.85215,0,0,0,0,100,0),
(@PATH,12,-8926.078,858.5243,99.49644,0,0,0,0,100,0),
(@PATH,13,-8938.801,860.7874,102.8602,0,0,0,0,100,0),
(@PATH,14,-8953.069,862.7512,105.0891,0,0,0,0,100,0),
(@PATH,15,-8966.061,861.0922,106.1805,0,0,0,0,100,0),
(@PATH,16,-8975.815,856.0721,105.9929,0,0,0,0,100,0),
(@PATH,17,-8981.12,845.0746,105.7443,0,0,0,0,100,0),
(@PATH,18,-8989.806,836.3768,105.8791,0,0,0,0,100,0),
(@PATH,19,-8996.647,835.3021,105.7929,0,0,0,0,100,0),
(@PATH,20,-9003.757,831.3663,106.0083,0,0,0,0,100,0),
(@PATH,21,-9009.389,825.1719,105.4831,0,0,0,0,100,0),
(@PATH,22,-9016.099,823.658,105.4568,0,0,0,0,100,0),
(@PATH,23,-9024.591,832.5903,105.7929,0,0,0,0,100,0),
(@PATH,24,-9029.763,838.6702,107.1929,0,0,0,0,100,0),
(@PATH,25,-9035.243,850.5191,107.1929,0,0,0,0,100,0),
(@PATH,26,-9035.667,862.0278,107.2941,0,0,0,0,100,0),
(@PATH,27,-9034.719,850.7535,107.1929,0,0,0,0,100,0),
(@PATH,28,-9029.297,839.1349,107.1898,0,0,0,0,100,0),
(@PATH,29,-9024.158,832.8368,105.7929,0,0,0,0,100,0),
(@PATH,30,-9015.763,824.0608,105.466,0,0,0,0,100,0),
(@PATH,31,-9009.505,825.4896,105.5089,0,0,0,0,100,0),
(@PATH,32,-9004.045,831.7083,106.0259,0,0,0,0,100,0),
(@PATH,33,-8996.778,835.625,105.7929,0,0,0,0,100,0),
(@PATH,34,-8989.514,837.2116,105.8744,0,0,0,0,100,0),
(@PATH,35,-8981.633,844.1547,105.6958,0,0,0,0,100,0),
(@PATH,36,-8975.935,855.5984,105.9552,0,0,0,0,100,0),
(@PATH,37,-8966.666,860.416,106.1866,0,0,0,0,100,0),
(@PATH,38,-8953.057,862.613,105.0713,0,0,0,0,100,0),
(@PATH,39,-8938.807,860.5985,102.8386,0,0,0,0,100,0),
(@PATH,40,-8926.223,857.8316,99.44566,0,0,0,0,100,0),
(@PATH,41,-8915.429,851.7813,96.84226,0,0,0,0,100,0),
(@PATH,42,-8907.618,843.4045,95.9022,0,0,0,0,100,0),
(@PATH,43,-8899.587,830.2136,93.37223,0,0,0,0,100,0),
(@PATH,44,-8898.681,814.7031,89.55863,0,0,0,0,100,0),
(@PATH,45,-8900.698,798.9531,87.62644,0,0,0,0,100,0),
(@PATH,46,-8910.101,791.1406,87.56455,0,0,0,0,100,0),
(@PATH,47,-8919.978,783.4045,87.43955,0,0,0,0,100,0),
(@PATH,48,-8926.736,775.8663,87.73154,0,0,0,0,100,0),
(@PATH,49,-8938.846,771.217,89.65668,0,0,0,0,100,0),
(@PATH,50,-8955.761,770.6805,93.18989,0,0,0,0,100,0),
(@PATH,51,-8967.857,773.3229,95.5025,0,0,0,0,100,0),
(@PATH,52,-8974.045,779.8623,96.92218,0,0,0,0,100,0),
(@PATH,53,-8984.654,788.9814,99.79718,0,0,0,0,100,0),
(@PATH,54,-8988.549,796.9358,102.0555,0,0,0,0,100,0),
(@PATH,55,-8991.433,807.8368,103.7611,0,0,0,0,100,0),
(@PATH,56,-8994.056,821.0833,104.6262,0,0,0,0,100,0),
(@PATH,57,-8993.146,830.4149,105.5081,0,0,0,0,100,0),
(@PATH,58,-8987.819,839.1111,105.8476,0,0,0,0,100,0),
(@PATH,59,-8981.388,845.7552,105.7688,0,0,0,0,100,0),
(@PATH,60,-8975.966,856.0245,105.9785,0,0,0,0,100,0),
(@PATH,61,-8975.453,869.4114,106.7735,0,0,0,0,100,0),
(@PATH,62,-8976.623,878.1858,106.6149,0,0,0,0,100,0),
(@PATH,63,-8984.571,888.1458,105.8159,0,0,0,0,100,0),
(@PATH,64,-8994.995,896.6545,105.865,0,0,0,0,100,0),
(@PATH,65,-9004.228,902.5035,106.2953,0,0,0,0,100,0),
(@PATH,66,-9013.134,918.0695,107.0519,0,0,0,0,100,0),
(@PATH,67,-9013.901,933.9688,108.4323,0,0,0,0,100,0),
(@PATH,68,-9008.544,946.6268,109.5021,0,0,0,0,100,0),
(@PATH,69,-9005.526,954.1077,110.4567,0,0,0,0,100,0),
(@PATH,70,-8996.823,958.717,113.0944,0,0,0,0,100,0),
(@PATH,71,-8984.311,960.5625,115.9871,0,0,0,0,100,0),
(@PATH,72,-8974.764,959.0208,117.1329,0,0,0,0,100,0),
(@PATH,73,-8959.587,956.2656,117.742,0,0,0,0,100,0);

-- Pathing for Brother Benjamin Entry: 5484 'TDB FORMAT' 
SET @NPC := 313733;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8525.907,`position_y`=831.7747,`position_z`=106.5945 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8525.907,831.7747,106.5945,0,0,0,0,100,0),
(@PATH,2,-8511.314,843.3931,106.5945,0,0,0,0,100,0),
(@PATH,3,-8525.907,831.7747,106.5945,0,0,0,0,100,0),
(@PATH,4,-8547.646,814.5632,106.5945,0,0,0,0,100,0);

-- Pathing for Ol' Emma Entry: 3520 'TDB FORMAT' 
SET @NPC := 314085;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8774.427,`position_y`=666.4566,`position_z`=103.4139 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8774.427,666.4566,103.4139,0,0,0,0,100,0),
(@PATH,2,-8768.528,658.816,103.7889,0,0,0,0,100,0),
(@PATH,3,-8762.686,650.0052,104.0538,0,0,0,0,100,0),
(@PATH,4,-8759.118,637.8125,103.4518,0,0,0,0,100,0),
(@PATH,5,-8759.073,625.3489,101.5838,0,0,0,0,100,0),
(@PATH,6,-8763.571,616.5469,98.81667,0,0,0,0,100,0),
(@PATH,7,-8778.382,602.059,97.40015,0,0,0,0,100,0),
(@PATH,8,-8793.395,591.9011,97.77479,0,0,0,0,100,0),
(@PATH,9,-8810.401,578.6962,95.51057,0,0,0,0,100,0),
(@PATH,10,-8819.727,566.627,94.551,0,0,0,0,100,0),
(@PATH,11,-8807.325,581.8958,96.47041,0,0,0,0,100,0),
(@PATH,12,-8790.901,593.7344,97.80921,0,0,0,0,100,0),
(@PATH,13,-8773.188,607.4774,97.40015,0,0,0,0,100,0),
(@PATH,14,-8768.804,606.7535,97.15015,0,0,0,0,100,0),
(@PATH,15,-8755.163,593.6875,97.39633,0,0,0,0,100,0),
(@PATH,16,-8738.802,576.6077,97.64633,0,0,0,0,100,0),
(@PATH,17,-8731.153,577.8646,97.54487,0,0,0,0,100,0),
(@PATH,18,-8723.391,587.1389,98.2635,0,0,0,0,100,0),
(@PATH,19,-8718.67,592.3906,98.71589,0,0,0,0,100,0),
(@PATH,20,-8711.368,594.5382,98.7635,0,0,0,0,100,0),
(@PATH,21,-8705.665,604.6858,99.39964,0,0,0,0,100,0),
(@PATH,22,-8703.114,614.6024,100.0256,0,0,0,0,100,0),
(@PATH,23,-8704.326,627.6702,100.4814,0,0,0,0,100,0),
(@PATH,24,-8707.979,641.7292,100.2435,0,0,0,0,100,0),
(@PATH,25,-8713.056,657.7674,99.38411,0,0,0,0,100,0),
(@PATH,26,-8719.231,670.2743,98.98618,0,0,0,0,100,0),
(@PATH,27,-8726.87,681.6077,98.98618,0,0,0,0,100,0),
(@PATH,28,-8731.857,692.6389,98.98618,0,0,0,0,100,0),
(@PATH,29,-8739.575,703.9722,98.72432,0,0,0,0,100,0),
(@PATH,30,-8742.363,713.5608,98.37359,0,0,0,0,100,0),
(@PATH,31,-8731.728,721.743,101.6664,0,0,0,0,100,0),
(@PATH,32,-8718.942,732.882,98.16624,0,0,0,0,100,0),
(@PATH,33,-8714.424,734.0295,97.8885,0,0,0,0,100,0),
(@PATH,34,-8705.797,722.9549,97.20751,0,0,0,0,100,0),
(@PATH,35,-8690.241,703.1736,97.38915,0,0,0,0,100,0),
(@PATH,36,-8681.62,692.1649,98.1385,0,0,0,0,100,0),
(@PATH,37,-8674.399,686.1632,98.62093,0,0,0,0,100,0),
(@PATH,38,-8668.17,676.7205,99.7635,0,0,0,0,100,0),
(@PATH,39,-8665.339,670.1424,100.1642,0,0,0,0,100,0),
(@PATH,40,-8661.473,669.2813,100.5469,0,0,0,0,100,0),
(@PATH,41,-8658.97,671.4159,101.7947,0,0,0,0,100,0),
(@PATH,42,-8654.989,675.8229,101.7945,0,0,0,0,100,0),
(@PATH,43,-8646.609,681.7969,102.1945,0,0,0,0,100,0),
(@PATH,44,-8640.983,678.503,101.7945,0,0,0,0,100,0),
(@PATH,45,-8640.929,675.0018,101.7945,0,0,0,0,100,0),
(@PATH,46,-8648.701,669.4844,108.1945,0,0,0,0,100,0),
(@PATH,47,-8650.832,669.8507,108.1945,0,0,0,0,100,0),
(@PATH,48,-8652.886,673.2604,108.1945,0,0,0,0,100,0),
(@PATH,49,-8656.448,676.9375,108.1945,0,0,0,0,100,0),
(@PATH,50,-8653.119,673.7007,108.1945,0,0,0,0,100,0),
(@PATH,51,-8650.457,670.2184,108.1945,0,0,0,0,100,0),
(@PATH,52,-8647.85,669.8229,108.1945,0,0,0,0,100,0),
(@PATH,53,-8640.595,674.8696,101.7945,0,0,0,0,100,0),
(@PATH,54,-8641.316,677.9182,101.7945,0,0,0,0,100,0),
(@PATH,55,-8646.123,681.2514,102.1945,0,0,0,0,100,0),
(@PATH,56,-8654.254,676.4114,101.7945,0,0,0,0,100,0),
(@PATH,57,-8658.893,671.2893,101.7945,0,0,0,0,100,0),
(@PATH,58,-8661.979,669.2715,100.5469,0,0,0,0,100,0),
(@PATH,59,-8666.408,672.7882,100.1719,0,0,0,0,100,0),
(@PATH,60,-8670.099,681.2952,99.22102,0,0,0,0,100,0),
(@PATH,61,-8679.127,690.8976,98.3885,0,0,0,0,100,0),
(@PATH,62,-8687.364,699.7917,97.42952,0,0,0,0,100,0),
(@PATH,63,-8692.518,705.8785,97.20751,0,0,0,0,100,0),
(@PATH,64,-8706.669,723.7153,97.35387,0,0,0,0,100,0),
(@PATH,65,-8715.255,734.1545,97.8885,0,0,0,0,100,0),
(@PATH,66,-8719.421,732.8547,98.29291,0,0,0,0,100,0),
(@PATH,67,-8730.271,723.8229,101.541,0,0,0,0,100,0),
(@PATH,68,-8742.438,713.7399,98.36062,0,0,0,0,100,0),
(@PATH,69,-8743.101,708.8125,98.6385,0,0,0,0,100,0),
(@PATH,70,-8739.368,703.1077,98.82808,0,0,0,0,100,0),
(@PATH,71,-8740.236,697.868,99.1405,0,0,0,0,100,0),
(@PATH,72,-8760.752,681.8984,101.7655,0,0,0,0,100,0),
(@PATH,73,-8773.578,671.4739,103.3547,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT'
SET @NPC := 314122;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8858.91,`position_y`=500.276,`position_z`=138.9021 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8858.91,500.276,138.9021,0,0,0,0,100,0),
(@PATH,2,-8850.22,489.236,138.9005,0,0,0,0,100,0),
(@PATH,3,-8840.06,476.578,138.8469,0,0,0,0,100,0),
(@PATH,4,-8831.41,467.128,138.9354,0,0,0,0,100,0),
(@PATH,5,-8821.76,456.269,138.9549,0,0,0,0,100,0),
(@PATH,6,-8819.23,448.913,138.9295,0,0,0,0,100,0),
(@PATH,7,-8819.23,448.913,138.9295,2.391101,11000,0,0,100,0),
(@PATH,8,-8843.83,474.033,138.9068,0,0,0,0,100,0),
(@PATH,9,-8854.68,487.203,138.8833,0,0,0,0,100,0),
(@PATH,10,-8863.21,501.262,138.9025,0,0,0,0,100,0),
(@PATH,11,-8872.91,511.175,138.9028,0,0,0,0,100,0),
(@PATH,12,-8872.91,511.175,138.9028,5.585053,20000,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314508;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8435.28,`position_y`=700.156,`position_z`=115.0977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8435.28,700.156,115.0977,0,0,0,0,100,0),
(@PATH,2,-8435.28,700.156,115.0977,0.6283185,20000,0,0,100,0),
(@PATH,3,-8422.67,710.502,115.0977,0,0,0,0,100,0),
(@PATH,4,-8413.84,717.092,114.9219,0,0,0,0,100,0),
(@PATH,5,-8405.17,723.368,114.3239,0,0,0,0,100,0),
(@PATH,6,-8394.24,732.28,114.4097,0,0,0,0,100,0),
(@PATH,7,-8381.44,716.314,114.7478,0,0,0,0,100,0),
(@PATH,8,-8381.44,716.314,114.7478,2.199115,16000,0,0,100,0),
(@PATH,9,-8389.73,727.092,114.3211,0,0,0,0,100,0),
(@PATH,10,-8393.94,731.59,114.3714,0,0,0,0,100,0),
(@PATH,11,-8403.7,724.245,114.1387,0,0,0,0,100,0),
(@PATH,12,-8417.32,715.094,115.0288,0,0,0,0,100,0);

-- Reusing bad spawns
SET @CGUID1 := 326106;
SET @CGUID2 := 307150;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID1+0 AND @CGUID1+2;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID2+0 AND @CGUID2+1;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID1+0 AND @CGUID1+2;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID2+0 AND @CGUID2+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID1+0, 1976, 0, 0, 0, 1, 169, 0, 0, 0, -8720.086, 846.207, 96.48609, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormwind City Patroller
(@CGUID2+0, 37944, 0, 0, 0, 1, 169, 0, 0, 0, -8382.993, 593.6163, 92.73832, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormwind City Patroller
(@CGUID2+1, 37944, 0, 0, 0, 1, 169, 0, 0, 0, -8699.839, 400.4948, 101.4027, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Stormwind City Patroller

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 326106;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8720.086,`position_y`=846.207,`position_z`=96.48609 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8720.086,846.207,96.48609,0,0,0,0,100,0),
(@PATH,2,-8711.143,856.3293,97.15601,0,0,0,0,100,0),
(@PATH,3,-8693.035,870.7116,97.296,0,0,0,0,100,0),
(@PATH,4,-8682.325,877.6946,97.14622,0,0,0,0,100,0),
(@PATH,5,-8664.145,854.98,97.11373,0,0,0,0,100,0),
(@PATH,6,-8648.738,835.6584,96.86629,0,0,0,0,100,0),
(@PATH,7,-8649.241,829.9152,96.83639,0,0,0,0,100,0),
(@PATH,8,-8658.901,822.8331,96.98312,0,0,0,0,100,0),
(@PATH,9,-8659.609,817.3097,96.86373,0,0,0,0,100,0),
(@PATH,10,-8647.54,802.587,97.11373,0,0,0,0,100,0),
(@PATH,11,-8631.366,784.0831,97.01419,0,0,0,0,100,0),
(@PATH,12,-8614.122,763.8488,97.01419,0,0,0,0,100,0),
(@PATH,13,-8594.368,754.4247,97.02985,0,0,0,0,100,0),
(@PATH,14,-8584.256,742.1224,97.02985,0,0,0,0,100,0),
(@PATH,15,-8584.33,735.3177,96.90485,0,0,0,0,100,0),
(@PATH,16,-8594.968,720.7852,96.90238,0,0,0,0,100,0),
(@PATH,17,-8594.556,713.834,96.90238,0,0,0,0,100,0),
(@PATH,18,-8574.029,688.5577,97.11234,0,0,0,0,100,0),
(@PATH,19,-8564.225,675.9625,97.1385,0,0,0,0,100,0),
(@PATH,20,-8564.967,670.4538,97.1385,0,0,0,0,100,0),
(@PATH,21,-8572.65,664.7967,97.38776,0,0,0,0,100,0),
(@PATH,22,-8587.497,658.5293,98.10725,0,0,0,0,100,0),
(@PATH,23,-8601.535,656.4609,98.58319,0,0,0,0,100,0),
(@PATH,24,-8620.167,654.048,99.27838,0,0,0,0,100,0),
(@PATH,25,-8638.708,656.3004,101.1525,0,0,0,0,100,0),
(@PATH,26,-8654.551,660.4544,101.026,0,0,0,0,100,0),
(@PATH,27,-8669.625,677.5877,99.47298,0,0,0,0,100,0),
(@PATH,28,-8674.721,685.6146,98.64827,0,0,0,0,100,0),
(@PATH,29,-8691.579,704.7813,97.20751,0,0,0,0,100,0),
(@PATH,30,-8707.09,724.6858,97.52062,0,0,0,0,100,0),
(@PATH,31,-8719.375,743.3528,98.0135,0,0,0,0,100,0),
(@PATH,32,-8734.063,764.3741,98.1385,0,0,0,0,100,0),
(@PATH,33,-8725.891,778.8763,98.06647,0,0,0,0,100,0),
(@PATH,34,-8717.271,790.4794,97.6385,0,0,0,0,100,0),
(@PATH,35,-8717.302,797.8687,97.49958,0,0,0,0,100,0),
(@PATH,36,-8726.464,812.5443,97.3885,0,0,0,0,100,0),
(@PATH,37,-8727.505,831.6793,96.39948,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314333;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8700,`position_y`=436.9785,`position_z`=98.89211 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8700,436.9785,98.89211,0,0,0,0,100,0),
(@PATH,2,-8712.92,439.72,97.14211,0,0,0,0,100,0),
(@PATH,3,-8714.28,445.035,97.14211,0,0,0,0,100,0),
(@PATH,4,-8712.76,454.082,97.16322,0,0,0,0,100,0),
(@PATH,5,-8703.92,463.224,96.49269,0,0,0,0,100,0),
(@PATH,6,-8695.15,470.632,95.49294,0,0,0,0,100,0),
(@PATH,7,-8692.7,475.092,95.49294,0,0,0,0,100,0),
(@PATH,8,-8693.89,479.328,95.49294,0,0,0,0,100,0),
(@PATH,9,-8718.28,510.09,96.53681,0,0,0,0,100,0),
(@PATH,10,-8718.28,510.09,96.53681,0,0,0,0,100,0),
(@PATH,11,-8722.02,512.082,96.80866,0,0,0,0,100,0),
(@PATH,12,-8726.45,510.918,96.6385,0,0,0,0,100,0),
(@PATH,13,-8731.62,506.642,96.6385,0,0,0,0,100,0),
(@PATH,14,-8745.44,493.533,96.93211,0,0,0,0,100,0),
(@PATH,15,-8764.87,474.469,97.77903,0,0,0,0,100,0),
(@PATH,16,-8773.1,469.899,97.85851,0,0,0,0,100,0),
(@PATH,17,-8782.25,469.95,97.80883,0,0,0,0,100,0),
(@PATH,18,-8792.74,472.281,96.80883,0,0,0,0,100,0),
(@PATH,19,-8798.15,471.561,97.03405,0,0,0,0,100,0),
(@PATH,20,-8798.15,471.561,97.03405,0.6981317,24000,0,0,100,0),
(@PATH,21,-8792.74,472.281,96.80883,0,0,0,0,100,0),
(@PATH,22,-8782.13,470.085,97.80883,0,0,0,0,100,0),
(@PATH,23,-8772.96,470.128,97.8308,0,0,0,0,100,0),
(@PATH,24,-8765.05,474.661,97.80051,0,0,0,0,100,0),
(@PATH,25,-8744.76,492.804,96.93211,0,0,0,0,100,0),
(@PATH,26,-8726.89,509.75,96.6385,0,0,0,0,100,0),
(@PATH,27,-8712.85,519.693,97.284,0,0,0,0,100,0),
(@PATH,28,-8695.04,535.842,97.8885,0,0,0,0,100,0),
(@PATH,29,-8680.4,548.542,97.54035,0,0,0,0,100,0),
(@PATH,30,-8665.94,553.575,97.03342,0,0,0,0,100,0),
(@PATH,31,-8655.41,552.344,97.1655,0,0,0,0,100,0),
(@PATH,32,-8645.14,547.274,98.30418,0,0,0,0,100,0),
(@PATH,33,-8628.94,531.073,101.1031,0,0,0,0,100,0),
(@PATH,34,-8616.8,518.278,103.2635,0,0,0,0,100,0),
(@PATH,35,-8611.27,510.786,103.7237,0,0,0,0,100,0),
(@PATH,36,-8612.17,506.748,103.4906,0,0,0,0,100,0),
(@PATH,37,-8644.15,481.595,102.6313,0,0,0,0,100,0),
(@PATH,38,-8645.32,475.691,102.6313,0,0,0,0,100,0),
(@PATH,39,-8638.5,464.875,102.3756,0,0,0,0,100,0),
(@PATH,40,-8635.96,451.319,102.5006,0,0,0,0,100,0),
(@PATH,41,-8637.12,442.094,102.3644,0,0,0,0,100,0),
(@PATH,42,-8643.88,433.852,101.4223,0,0,0,0,100,0),
(@PATH,43,-8650.36,431.698,101.6079,0,0,0,0,100,0),
(@PATH,44,-8654.6,433.288,101.6184,0,0,0,0,100,0),
(@PATH,45,-8664.4,445.163,100.5265,0,0,0,0,100,0),
(@PATH,46,-8671.05,451.139,99.83105,0,0,0,0,100,0),
(@PATH,47,-8677.43,452.205,99.83105,0,0,0,0,100,0),
(@PATH,48,-8683.74,448.385,99.95605,0,0,0,0,100,0),
(@PATH,49,-8690,442.255,99.58923,0,0,0,0,100,0),
(@PATH,50,-8697.66,437.872,99.31726,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 37944 'TDB FORMAT' 
SET @NPC := 307150;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8382.993,`position_y`=593.6163,`position_z`=92.73832 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8394.993,603.2112,94.20713,0,0,0,0,100,0),
(@PATH,2,-8391.466,611.0927,94.90211,0,0,0,0,100,0),
(@PATH,3,-8386.328,616.1337,95.33936,0,0,0,0,100,0),
(@PATH,4,-8375.594,625.5516,95.23751,0,0,0,0,100,0),
(@PATH,5,-8374.691,637.4271,94.98558,0,0,0,0,100,0),
(@PATH,6,-8387.234,654.5434,95.37791,0,0,0,0,100,0),
(@PATH,7,-8395.723,666.5364,94.81358,0,0,0,0,100,0),
(@PATH,8,-8403.931,672.5261,95.18652,0,0,0,0,100,0),
(@PATH,9,-8413.647,673.8229,95.1521,0,0,0,0,100,0),
(@PATH,10,-8424.304,664.9531,94.58127,0,0,0,0,100,0),
(@PATH,11,-8440.395,654.566,93.05537,0,0,0,0,100,0),
(@PATH,12,-8459.266,640.7726,92.23958,0,0,0,0,100,0),
(@PATH,13,-8474.049,626.993,93.92981,0,0,0,0,100,0),
(@PATH,14,-8476.113,620.7952,94.73132,0,0,0,0,100,0),
(@PATH,15,-8466.738,607.5746,94.63489,0,0,0,0,100,0),
(@PATH,16,-8454.596,589.9184,94.62309,0,0,0,0,100,0),
(@PATH,17,-8457.071,582.1979,94.87309,0,0,0,0,100,0),
(@PATH,18,-8469,573.2153,96.51883,0,0,0,0,100,0),
(@PATH,19,-8487.569,562.257,97.78643,0,0,0,0,100,0),
(@PATH,20,-8502.451,552.8976,97.98879,0,0,0,0,100,0),
(@PATH,21,-8506.188,537.4774,97.97048,0,0,0,0,100,0),
(@PATH,22,-8492.596,539.8559,97.81988,0,0,0,0,100,0),
(@PATH,23,-8481.457,556.8125,97.94488,0,0,0,0,100,0),
(@PATH,24,-8473.154,566.4705,97.03594,0,0,0,0,100,0),
(@PATH,25,-8457.761,578.5174,95.01347,0,0,0,0,100,0),
(@PATH,26,-8445.566,585.2031,94.65361,0,0,0,0,100,0),
(@PATH,27,-8435.991,576.0799,94.55595,0,0,0,0,100,0),
(@PATH,28,-8424.627,567.2552,93.82767,0,0,0,0,100,0),
(@PATH,29,-8416.424,565.3577,93.0731,0,0,0,0,100,0),
(@PATH,30,-8394,576.257,91.92184,0,0,0,0,100,0),
(@PATH,31,-8391.533,578.4219,91.79684,0,0,0,0,100,0),
(@PATH,32,-8394.059,590.1312,92.75985,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 37944 'TDB FORMAT' 
SET @NPC := 307151;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8699.839,`position_y`=400.4948,`position_z`=101.4027 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8699.839,400.4948,101.4027,0,0,0,0,100,0),
(@PATH,2,-8717.941,405.6181,97.98022,0,0,0,0,100,0),
(@PATH,3,-8726.629,409.3108,97.82079,0,0,0,0,100,0),
(@PATH,4,-8725.007,422.0174,98.02538,0,0,0,0,100,0),
(@PATH,5,-8720.864,438.9201,97.58351,0,0,0,0,100,0),
(@PATH,6,-8714.594,454.1476,97.39113,0,0,0,0,100,0),
(@PATH,7,-8703.426,467.0486,96.32102,0,0,0,0,100,0),
(@PATH,8,-8694.274,474.1389,95.57754,0,0,0,0,100,0),
(@PATH,9,-8678.473,488.8594,97.88503,0,0,0,0,100,0),
(@PATH,10,-8667.526,497.276,100.5486,0,0,0,0,100,0),
(@PATH,11,-8659.889,495.3004,101.132,0,0,0,0,100,0),
(@PATH,12,-8651.598,485.1354,102.4734,0,0,0,0,100,0),
(@PATH,13,-8644.703,475.6545,102.6313,0,0,0,0,100,0),
(@PATH,14,-8637.254,466.5504,102.3756,0,0,0,0,100,0),
(@PATH,15,-8632.403,456.7153,102.4575,0,0,0,0,100,0),
(@PATH,16,-8633.111,446.684,102.5825,0,0,0,0,100,0),
(@PATH,17,-8649.333,424.2656,101.7585,0,0,0,0,100,0),
(@PATH,18,-8664.069,409.9219,103.3586,0,0,0,0,100,0),
(@PATH,19,-8678.203,400.224,103.2457,0,0,0,0,100,0),
(@PATH,20,-8688.297,395.7049,102.3116,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314174;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8725,`position_y`=402.217,`position_z`=97.94579 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8725,402.217,97.94579,0,0,0,0,100,0),
(@PATH,2,-8717.33,403.668,98.06811,0,0,0,0,100,0),
(@PATH,3,-8710.66,403.729,99.21911,0,0,0,0,100,0),
(@PATH,4,-8705.14,401.422,100.6584,0,0,0,0,100,0),
(@PATH,5,-8699.42,397.469,101.5616,0,0,0,0,100,0),
(@PATH,6,-8693.18,394.668,102.1449,0,0,0,0,100,0),
(@PATH,7,-8687.11,395.844,102.3116,0,0,0,0,100,0),
(@PATH,8,-8680.7,396.031,102.6513,0,0,0,0,100,0),
(@PATH,9,-8673.73,400.123,103.52,0,0,0,0,100,0),
(@PATH,10,-8665.96,405.792,103.6005,0,0,0,0,100,0),
(@PATH,11,-8656.55,414.514,102.5813,0,0,0,0,100,0),
(@PATH,12,-8646.65,425.009,101.9192,0,0,0,0,100,0),
(@PATH,13,-8639.83,433.106,102.0159,0,0,0,0,100,0),
(@PATH,14,-8635.35,439.231,102.5712,0,0,0,0,100,0),
(@PATH,15,-8632.09,443.455,102.7671,0,0,0,0,100,0),
(@PATH,16,-8631.72,451.16,102.4575,0,0,0,0,100,0),
(@PATH,17,-8632.03,459.635,102.3329,0,0,0,0,100,0),
(@PATH,18,-8634.97,465.382,102.3756,0,0,0,0,100,0),
(@PATH,19,-8640.01,472.892,102.6313,0,0,0,0,100,0),
(@PATH,20,-8645.24,480.253,102.6313,0,0,0,0,100,0),
(@PATH,21,-8651,486.854,102.4638,0,0,0,0,100,0),
(@PATH,22,-8655.86,493.196,101.7404,0,0,0,0,100,0),
(@PATH,23,-8660.4,496.998,101.0707,0,0,0,0,100,0),
(@PATH,24,-8667.79,497.623,100.5999,0,0,0,0,100,0),
(@PATH,25,-8678.13,491.88,98.32973,0,0,0,0,100,0),
(@PATH,26,-8683.81,484.271,96.55325,0,0,0,0,100,0),
(@PATH,27,-8695.27,475.592,95.49294,0,0,0,0,100,0),
(@PATH,28,-8703.01,468.816,96.14622,0,0,0,0,100,0),
(@PATH,29,-8706.1,465.45,96.43654,0,0,0,0,100,0),
(@PATH,30,-8712.62,459.22,97.13795,0,0,0,0,100,0),
(@PATH,31,-8718.02,452.236,97.39211,0,0,0,0,100,0),
(@PATH,32,-8722.25,446.531,97.62477,0,0,0,0,100,0),
(@PATH,33,-8725.24,438.37,97.98341,0,0,0,0,100,0),
(@PATH,34,-8725.22,430.161,98.1599,0,0,0,0,100,0),
(@PATH,35,-8724.79,420.998,97.90307,0,0,0,0,100,0),
(@PATH,36,-8728.89,413.262,97.82079,0,0,0,0,100,0),
(@PATH,37,-8738.23,403.247,97.98989,0,0,0,0,100,0),
(@PATH,38,-8740.488,400.6852,98.20876,0,0,0,0,100,0),
(@PATH,39,-8748.56,394.422,101.0424,0,0,0,0,100,0),
(@PATH,40,-8749.76,392.26,101.0569,0,0,0,0,100,0),
(@PATH,41,-8747.9,388.778,101.0557,0,0,0,0,100,0),
(@PATH,42,-8745.69,385.849,101.0469,0,0,0,0,100,0),
(@PATH,43,-8744.29,381.606,101.0381,0,0,0,0,100,0),
(@PATH,44,-8743.89,377.712,101.0312,0,0,0,0,100,0),
(@PATH,45,-8742.186,373.4375,100.9835,0,0,0,0,100,0),
(@PATH,46,-8740.33,367.474,100.949,0,0,0,0,100,0),
(@PATH,47,-8740.85,360.641,101.3289,0,0,0,0,100,0),
(@PATH,48,-8743.63,353.97,100.8702,0,0,0,0,100,0),
(@PATH,49,-8747.14,347.517,100.4185,0,0,0,0,100,0),
(@PATH,50,-8749.93,340.53,101.1685,0,10000,0,0,100,0),
(@PATH,51,-8749.87,346.227,100.8556,0,0,0,0,100,0),
(@PATH,52,-8753.27,352.446,100.5625,0,0,0,0,100,0),
(@PATH,53,-8758.22,357.233,100.5435,0,0,0,0,100,0),
(@PATH,54,-8763.32,362.052,100.9097,0,0,0,0,100,0),
(@PATH,55,-8768.34,366.097,100.9457,0,0,0,0,100,0),
(@PATH,56,-8774.54,369.403,100.9904,0,0,0,0,100,0),
(@PATH,57,-8774.54,369.403,100.9904,2.338741,22000,0,0,100,0),
(@PATH,58,-8767.14,369.007,100.8812,0,0,0,0,100,0),
(@PATH,59,-8763.68,372.45,100.898,0,0,0,0,100,0),
(@PATH,60,-8760.53,376.352,100.8585,0,0,0,0,100,0),
(@PATH,61,-8756.51,379.135,101.0505,0,0,0,0,100,0),
(@PATH,62,-8755.6,382.918,101.0561,0,0,0,0,100,0),
(@PATH,63,-8755.5,387.391,101.057,0,0,0,0,100,0),
(@PATH,64,-8752.55,391.076,101.0572,0,0,0,0,100,0),
(@PATH,65,-8748.37,394.462,100.9933,0,0,0,0,100,0),
(@PATH,66,-8740.65,400.174,98.20898,0,0,0,0,100,0),
(@PATH,67,-8737.03,401.759,97.98989,0,0,0,0,100,0),
(@PATH,68,-8732.82,401.076,98.07079,0,0,0,0,100,0);

-- Pathing for Stormwind City Patroller Entry: 1976 'TDB FORMAT' 
SET @NPC := 314480;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8342.29,`position_y`=639.946,`position_z`=95.9051 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8342.29,639.946,95.9051,0,0,0,0,100,0),
(@PATH,2,-8342.29,639.946,95.9051,0.6108652,10000,0,0,100,0),
(@PATH,3,-8346.135, 638.6555, 95.61925,0,0,0,0,100,0),
(@PATH,4,-8352.135, 638.1555, 95.36925,0,0,0,0,100,0),
(@PATH,5,-8357.135, 639.1555, 95.36925,0,0,0,0,100,0),
(@PATH,6,-8364.135, 638.9055, 95.36925,0,0,0,0,100,0),
(@PATH,7,-8373.635, 637.1555, 95.36925,0,0,0,0,100,0),
(@PATH,8,-8380.635, 638.1555, 95.36925,0,0,0,0,100,0),
(@PATH,9,-8385.635, 638.6555, 95.11925,0,0,0,0,100,0),
(@PATH,10,-8391.635, 636.1555, 95.36925,0,0,0,0,100,0),
(@PATH,11,-8396.885, 629.6555, 95.61925,0,0,0,0,100,0),
(@PATH,12,-8402.385, 625.4055, 95.61925,0,0,0,0,100,0),
(@PATH,13,-8408.135, 624.1555, 95.86925,0,0,0,0,100,0),
(@PATH,14,-8413.385, 624.1555, 95.86925,0,0,0,0,100,0),
(@PATH,15,-8417.885, 623.4055, 95.86925,0,0,0,0,100,0),
(@PATH,16,-8422.635, 623.4055, 95.86925,0,0,0,0,100,0),
(@PATH,17,-8427.385, 621.4055, 95.86925,0,0,0,0,100,0),
(@PATH,18,-8431.385, 616.9055, 95.36925,0,0,0,0,100,0),
(@PATH,19,-8433.135, 610.6555, 95.36925,0,0,0,0,100,0),
(@PATH,20,-8433.98,602.365,94.8334,0,0,0,0,100,0),
(@PATH,21,-8433.98,602.365,94.8334,6.038839,24000,0,0,100,0),
(@PATH,22,-8432.885, 610.6555, 95.36925,0,0,0,0,100,0),
(@PATH,23,-8431.135, 617.1555, 95.36925,0,0,0,0,100,0),
(@PATH,24,-8427.135, 621.4055, 95.86925,0,0,0,0,100,0),
(@PATH,25,-8422.635, 623.4055, 95.86925,0,0,0,0,100,0),
(@PATH,26,-8417.885, 623.4055, 95.86925,0,0,0,0,100,0),
(@PATH,27,-8413.385, 624.1555, 95.86925,0,0,0,0,100,0),
(@PATH,28,-8408.135, 623.9055, 95.86925,0,0,0,0,100,0),
(@PATH,29,-8402.385, 622.4055, 95.36925,0,0,0,0,100,0),
(@PATH,30,-8397.885, 621.1555, 95.36925,0,0,0,0,100,0),
(@PATH,31,-8393.885, 619.9055, 95.36925,0,0,0,0,100,0),
(@PATH,32,-8388.385, 618.4055, 95.61925,0,0,0,0,100,0),
(@PATH,33,-8381.885, 618.1555, 95.86925,0,0,0,0,100,0),
(@PATH,34,-8374.885, 620.4055, 95.36925,0,0,0,0,100,0),
(@PATH,35,-8371.635, 621.4055, 95.36925,0,0,0,0,100,0),
(@PATH,36,-8366.135, 621.4055, 95.36925,0,0,0,0,100,0),
(@PATH,37,-8360.635, 621.4055, 95.61925,0,0,0,0,100,0),
(@PATH,38,-8353.385, 625.1555, 95.36925,0,0,0,0,100,0),
(@PATH,39,-8347.885, 631.4055, 95.36925,0,0,0,0,100,0),
(@PATH,40,-8344.635, 636.6555, 95.61925,0,0,0,0,100,0);

-- Pathing for David Gregory Entry: 50434 'TDB FORMAT' 
SET @NPC := 313760;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8544.669,`position_y`=775.8941,`position_z`=99.76182 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8544.669,775.8941,99.76182,0,0,0,0,100,0),
(@PATH,2,-8555.473,766.2761,99.44987,0,0,0,0,100,0),
(@PATH,3,-8563.448,760.5799,98.30936,0,0,0,0,100,0),
(@PATH,4,-8576.564,756.8993,96.92023,0,0,0,0,100,0),
(@PATH,5,-8586.326,757.0555,96.90485,0,0,0,0,100,0),
(@PATH,6,-8599.663,759.2639,96.95869,0,0,0,0,100,0),
(@PATH,7,-8608.788,763.5295,97.07816,0,0,0,0,100,0),
(@PATH,8,-8621.739,773.2292,96.88919,0,0,0,0,100,0),
(@PATH,9,-8632.16,789.3108,96.93607,0,0,0,0,100,0),
(@PATH,10,-8632.647,803.8802,96.81436,0,0,0,0,100,0),
(@PATH,11,-8630.54,817.9479,96.81436,0,0,0,0,100,0),
(@PATH,12,-8626.054,825.3663,96.81436,0,0,0,0,100,0),
(@PATH,13,-8615.679,836.2847,96.92783,0,0,0,0,100,0),
(@PATH,14,-8608.085,843.5851,96.83897,0,0,0,0,100,0),
(@PATH,15,-8597.951,851.0399,96.9703,0,0,0,0,100,0),
(@PATH,16,-8578.879,859.8789,98.3453,0,0,0,0,100,0),
(@PATH,17,-8570.92,870.4305,99.59727,0,0,0,0,100,0),
(@PATH,18,-8567.071,881.684,100.2706,0,0,0,0,100,0),
(@PATH,19,-8562.337,890.3889,100.9072,0,0,0,0,100,0),
(@PATH,20,-8547.274,904.5538,100.024,0,0,0,0,100,0),
(@PATH,21,-8536.134,897.6268,100.8751,0,0,0,0,100,0),
(@PATH,22,-8522.629,890.5068,99.52771,0,0,0,0,100,0),
(@PATH,23,-8513.109,883.0469,105.2515,0,0,0,0,100,0),
(@PATH,24,-8497.916,870.833,105.6756,0,0,0,0,100,0),
(@PATH,25,-8490.208,868.4653,105.8006,0,0,0,0,100,0),
(@PATH,26,-8485.754,871.2483,105.8133,0,0,0,0,100,0),
(@PATH,27,-8481.064,880.2205,105.1756,0,0,0,0,100,0),
(@PATH,28,-8479.63,885.5781,104.7084,0,0,0,0,100,0),
(@PATH,29,-8475,901.041,98.83204,0,0,0,0,100,0),
(@PATH,30,-8475,901.041,98.83204,0,0,0,0,100,0),
(@PATH,31,-8468.75,902.084,99.08204,0,0,0,0,100,0),
(@PATH,32,-8461.701,905.5469,99.10195,0,0,0,0,100,0),
(@PATH,33,-8455.857,909.4861,99.22695,0,0,0,0,100,0),
(@PATH,34,-8451.024,912.8768,99.35195,0,0,0,0,100,0),
(@PATH,35,-8444.797,916.8229,99.35195,0,0,0,0,100,0),
(@PATH,36,-8431.736,925.5399,98.90391,0,0,0,0,100,0),
(@PATH,37,-8420.294,933.9114,98.70117,0,0,0,0,100,0),
(@PATH,38,-8412.248,939.0555,98.20801,0,0,0,0,100,0),
(@PATH,39,-8401.156,944.993,97.70801,0,0,0,0,100,0),
(@PATH,40,-8392.384,949.0104,97.12554,0,0,0,0,100,0),
(@PATH,41,-8382.033,949.4236,96.81939,0,0,0,0,100,0),
(@PATH,42,-8367.849,944.2604,96.69561,0,0,0,0,100,0),
(@PATH,43,-8348.872,935.7813,96.84547,0,0,0,0,100,0),
(@PATH,44,-8329.938,926.1024,97.13617,0,0,0,0,100,0),
(@PATH,45,-8318.207,919.7969,97.51117,0,0,0,0,100,0),
(@PATH,46,-8310.368,916.191,97.76117,0,0,0,0,100,0),
(@PATH,47,-8303.654,916.3768,97.88617,0,0,0,0,100,0),
(@PATH,48,-8297.498,920.5156,97.6655,0,0,0,0,100,0),
(@PATH,49,-8292.049,921.2934,97.68992,0,0,0,0,100,0),
(@PATH,50,-8281.786,919.7136,97.68992,0,0,0,0,100,0),
(@PATH,51,-8271.518,917.5313,97.56492,0,0,0,0,100,0),
(@PATH,52,-8257.808,915.5868,97.73205,0,0,0,0,100,0),
(@PATH,53,-8247.552,914.6667,98.60705,0,0,0,0,100,0),
(@PATH,54,-8241.207,914.0521,98.60705,0,0,0,0,100,0),
(@PATH,55,-8254.431,915.4705,98.01281,0,0,0,0,100,0),
(@PATH,56,-8266.272,916.1893,97.60705,0,0,0,0,100,0),
(@PATH,57,-8272.388,917.6893,97.62974,0,0,0,0,100,0),
(@PATH,58,-8280.627,919.3941,97.68992,0,0,0,0,100,0),
(@PATH,59,-8291.681,921.5608,97.68992,0,0,0,0,100,0),
(@PATH,60,-8297.649,920.6771,97.64622,0,0,0,0,100,0),
(@PATH,61,-8303.224,916.3976,97.88617,0,0,0,0,100,0),
(@PATH,62,-8307.363,913.9861,97.89532,0,0,0,0,100,0),
(@PATH,63,-8317.732,919.5399,97.51117,0,0,0,0,100,0),
(@PATH,64,-8328.942,926.2222,97.13617,0,0,0,0,100,0),
(@PATH,65,-8348.771,936.2101,96.84547,0,0,0,0,100,0),
(@PATH,66,-8365.413,943.2986,96.72047,0,0,0,0,100,0),
(@PATH,67,-8378.082,947.8715,96.81939,0,0,0,0,100,0),
(@PATH,68,-8386.212,949.8333,97.10259,0,0,0,0,100,0),
(@PATH,69,-8394.247,948.7448,97.28252,0,0,0,0,100,0),
(@PATH,70,-8404.113,944.3386,97.69983,0,0,0,0,100,0),
(@PATH,71,-8417.978,935.9879,98.45801,0,0,0,0,100,0),
(@PATH,72,-8432.279,925.3333,98.90391,0,0,0,0,100,0),
(@PATH,73,-8444.554,917.4288,99.35195,0,0,0,0,100,0),
(@PATH,74,-8453.092,911.132,99.27004,0,0,0,0,100,0),
(@PATH,75,-8463.205,905.3316,99.10195,0,0,0,0,100,0),
(@PATH,76,-8474.634,901.5121,98.81934,0,0,0,0,100,0),
(@PATH,77,-8475.943,898.0737,98.87817,0,0,0,0,100,0),
(@PATH,78,-8479.107,887.1285,104.2702,0,0,0,0,100,0),
(@PATH,79,-8479.549,886.0712,104.7084,0,0,0,0,100,0),
(@PATH,80,-8482.743,876.1215,105.4786,0,0,0,0,100,0),
(@PATH,81,-8484.301,866.8299,105.8006,0,0,0,0,100,0),
(@PATH,82,-8484.471,854.2327,105.8569,0,0,0,0,100,0),
(@PATH,83,-8484.31,839.8871,105.8569,0,0,0,0,100,0),
(@PATH,84,-8482.104,829.4479,105.8242,0,0,0,0,100,0),
(@PATH,85,-8480.212,823.4167,106.0122,0,0,0,0,100,0),
(@PATH,86,-8479.167,807.2222,106.4492,0,0,0,0,100,0),
(@PATH,87,-8480.854,797.868,106.4167,0,0,0,0,100,0),
(@PATH,88,-8488.143,793.3177,105.9167,0,0,0,0,100,0),
(@PATH,89,-8495.455,789.4618,105.4647,0,0,0,0,100,0),
(@PATH,90,-8503.87,785.6458,104.0956,0,0,0,0,100,0),
(@PATH,91,-8521.271,780.691,99.68512,0,0,0,0,100,0),
(@PATH,92,-8531.863,780.9757,99.08893,0,0,0,0,100,0);

-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=313760;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(313760,313760,0,0,2),
(313760,313759,2,270,2);
--