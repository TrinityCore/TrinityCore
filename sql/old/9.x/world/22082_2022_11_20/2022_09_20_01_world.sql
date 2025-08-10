SET @CGUID := 1051509;
SET @OGUID := 600238;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 532.47918701171875, -2473.067626953125, 152.8841094970703125, 0.816193342208862304, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 156986, 2175, 10424, 10528, '0', 0, 0, 0, 1, 516.81097412109375, -2476.11474609375, 151.1571197509765625, 1.889551401138305664, 7200, 0, 0, 297, 382, 0, 0, 0, 0, 45338), -- Ogre Taskmaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 490.337982177734375, -2490.9091796875, 149.355987548828125, 6.181377410888671875, 7200, 4, 0, 37, 0, 1, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 152571, 2175, 10424, 10528, '0', 0, 0, 0, 0, 474.517364501953125, -2444.35595703125, 153.1246337890625, 0.943628787994384765, 7200, 0, 0, 124, 100, 0, 0, 0, 0, 45338), -- Harpy Snatcher (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 152571, 2175, 10424, 10528, '0', 0, 0, 0, 0, 488, -2536.057373046875, 153.208770751953125, 4.258255481719970703, 7200, 0, 0, 124, 100, 0, 0, 0, 0, 45338), -- Harpy Snatcher (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 152843, 2175, 10424, 10528, '0', 0, 0, 0, 0, 433.510406494140625, -2486.916748046875, 142.18408203125, 2.924199819564819335, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 45338), -- Harpy Boltcaller (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 535.45489501953125, -2471.80029296875, 153.322509765625, 3.146941423416137695, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 466.13714599609375, -2408.578125, 146.82232666015625, 3.676610946655273437, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 152571, 2175, 10424, 10528, '0', 0, 0, 0, 0, 463.493072509765625, -2507.791748046875, 147.019439697265625, 6.064158439636230468, 7200, 0, 0, 124, 100, 0, 0, 0, 0, 45338), -- Harpy Snatcher (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 480.728515625, -2485.416015625, 150.3651885986328125, 5.225788116455078125, 7200, 4, 0, 37, 0, 1, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 463.532989501953125, -2409.484375, 145.7851409912109375, 0.148718908429145812, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 152843, 2175, 10424, 10528, '0', 0, 0, 0, 0, 431.530029296875, -2407.891845703125, 146.169158935546875, 5.492168903350830078, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 45338), -- Harpy Boltcaller (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 472.173614501953125, -2396.953125, 146.9133148193359375, 1.962240457534790039, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 152571, 2175, 10424, 10528, '0', 0, 0, 0, 0, 547.53900146484375, -2516.50390625, 154.1284942626953125, 2.111484766006469726, 7200, 0, 0, 124, 100, 0, 0, 0, 0, 45338), -- Harpy Snatcher (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 527.47918701171875, -2561.755126953125, 157.620635986328125, 1.36496591567993164, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 552.56427001953125, -2515.26220703125, 154.17718505859375, 0.816193342208862304, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 531.14239501953125, -2561.829833984375, 157.5560302734375, 4.26859903335571289, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 555.5382080078125, -2513.9931640625, 154.1770782470703125, 3.146941423416137695, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338), -- Hunting Worg (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 152843, 2175, 10424, 10528, '0', 0, 0, 0, 0, 507.67742919921875, -2599.332763671875, 155.37420654296875, 2.839890718460083007, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 45338), -- Harpy Boltcaller (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 152843, 2175, 10424, 10528, '0', 0, 0, 0, 0, 505.0296630859375, -2598.486572265625, 155.30914306640625, 6.226494789123535156, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 45338), -- Harpy Boltcaller (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 152998, 2175, 10424, 10528, '0', 0, 0, 0, 0, 473.795135498046875, -2396.376708984375, 146.7750244140625, 2.285255908966064453, 7200, 0, 0, 37, 0, 0, 0, 0, 0, 45338); -- Hunting Worg (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 1, 468, 0, 0, 0, 0, ''), -- Harpy Snatcher
(@CGUID+4, 0, 0, 0, 1, 468, 0, 0, 0, 0, ''), -- Harpy Snatcher
(@CGUID+5, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Harpy Boltcaller
(@CGUID+7, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Hunting Worg
(@CGUID+8, 0, 0, 0, 1, 468, 0, 0, 0, 0, ''), -- Harpy Snatcher
(@CGUID+10, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Hunting Worg
(@CGUID+11, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Harpy Boltcaller
(@CGUID+12, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Hunting Worg
(@CGUID+13, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Harpy Snatcher
(@CGUID+14, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Hunting Worg
(@CGUID+16, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Hunting Worg
(@CGUID+18, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Harpy Boltcaller
(@CGUID+19, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Harpy Boltcaller
(@CGUID+20, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''); -- Hunting Worg

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=152843; -- Harpy Boltcaller
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=152571; -- Harpy Snatcher
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=156986; -- Ogre Taskmaster
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=152998; -- Hunting Worg

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 327146, 2175, 10424, 10528, '0', 0, 0, 430.526031494140625, -2487.46533203125, 142.301300048828125, 1.587361812591552734, 0, 0, 0.712939262390136718, 0.701225817203521728, 7200, 255, 1, 45338), -- Harpy Totem (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 327146, 2175, 10424, 10528, '0', 0, 0, 481.75, -2452.32470703125, 152.03143310546875, 0.12650531530380249, 0, 0, 0.063210487365722656, 0.998000204563140869, 7200, 255, 1, 45338), -- Harpy Totem (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 327146, 2175, 10424, 10528, '0', 0, 0, 465.720489501953125, -2508.295166015625, 147.4104156494140625, 3.157217979431152343, 0, 0, -0.999969482421875, 0.0078125, 7200, 255, 1, 45338), -- Harpy Totem (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 327146, 2175, 10424, 10528, '0', 0, 0, 552.93402099609375, -2513.6650390625, 154.2525177001953125, 3.795985698699951171, 0, 0, -0.94694709777832031, 0.321389496326446533, 7200, 255, 1, 45338), -- Harpy Totem (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 327146, 2175, 10424, 10528, '0', 0, 0, 502, -2589.651123046875, 155.433013916015625, 1.940680384635925292, 0, 0, 0.825078010559082031, 0.565018832683563232, 7200, 255, 1, 45338); -- Harpy Totem (Area: -Unknown- - Difficulty: 0)

-- Waypoints for CGUID+1
SET @PATH := @CGUID+1 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 521.3785, -2505.967, 152.1503, NULL, 0),
(@PATH, 1, 519.243, -2489.641, 151.4003, NULL, 0),
(@PATH, 2, 518.507, -2481.238, 150.9003, NULL, 0),
(@PATH, 3, 514.1268, -2467.981, 151.305, NULL, 0),
(@PATH, 4, 518.507, -2481.238, 150.9003, NULL, 0),
(@PATH, 5, 519.243, -2489.641, 151.4003, NULL, 0),
(@PATH, 6, 521.3785, -2505.967, 152.1503, NULL, 0),
(@PATH, 7, 521.2118, -2519.878, 153.8483, NULL, 0);

UPDATE `creature` SET `position_x`= 521.3785, `position_y`= -2505.967, `position_z`= 152.1503, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+1, @PATH, 1);

-- Waypoints for CGUID+18
SET @PATH := @CGUID+18 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 509.3316, -2599.847, 156.4041, NULL, 0),
(@PATH, 1, 503.125, -2597.916, 156.3284, NULL, 0),
(@PATH, 2, 499.7865, -2596.875, 156.8123, NULL, 0),
(@PATH, 3, 501.1059, -2589.887, 156.417, NULL, 0),
(@PATH, 4, 505.8733, -2587.913, 156.5159, NULL, 0),
(@PATH, 5, 510.8993, -2592.21, 156.8892, NULL, 0);

UPDATE `creature` SET `position_x`= 509.3316, `position_y`= -2599.847, `position_z`= 156.4041, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`) VALUES
(@CGUID+18, @PATH, 33554432, 1);

-- Waypoints for CGUID+19
SET @PATH := @CGUID+19 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 501.7917, -2588.821, 156.4871, NULL, 0),
(@PATH, 1, 500.6024, -2594.535, 156.5476, NULL, 0),
(@PATH, 2, 503.125, -2597.916, 156.3284, NULL, 0),
(@PATH, 3, 509.4583, -2598.74, 156.5521, NULL, 0),
(@PATH, 4, 511.4792, -2592.972, 157.1409, NULL, 0),
(@PATH, 5, 506.5573, -2587.813, 156.5159, NULL, 0);

UPDATE `creature` SET `position_x`= 501.7917, `position_y`= -2588.821, `position_z`= 156.4871, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+19;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`) VALUES
(@CGUID+19, @PATH, 33554432, 1);
