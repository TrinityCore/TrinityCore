SET @CGUID := 396650;
SET @OGUID := 251781;
SET @EVENT := 2;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=6813, `minlevel`=70, `maxlevel`=70, `faction`=774, `speed_walk`=1, `npcflag`=1, `unit_flags`=32768 WHERE `entry` IN (15784, 15794); -- Night Elf Winter Reveler

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 15760, 1, 1657, 1659, '0', 0, 0, 0, 1, 10128.28125, 2218.376708984375, 1330.064208984375, 6.195918560028076171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Winter Reveler (Area: Craftsmen's Terrace - Difficulty: 0) (Auras: )
(@CGUID+1, 15760, 1, 1657, 1659, '0', 0, 0, 0, 1, 10130.099609375, 2217.960205078125, 1330.0634765625, 2.338741064071655273, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187); -- Winter Reveler (Area: Craftsmen's Terrace - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26245'), -- 15760 (Winter Reveler)
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26246'); -- 15760 (Winter Reveler)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180844, 1, 1657, 1659, '0', 0, 0, 10129.564453125, 2218.098876953125, 1336.2939453125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 47187), -- Mistletoe (Area: Craftsmen's Terrace - Difficulty: 0)
(@OGUID+1, 187235, 1, 1657, 0, '0', 0, 0, 9686.9599609375, 2531.010009765625, 1337.300048828125, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+2, 187235, 1, 1657, 0, '0', 0, 0, 9658.8603515625, 2532.6298828125, 1331.52001953125, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+3, 187235, 1, 1657, 0, '0', 0, 0, 9687.2998046875, 2518.820068359375, 1337.31005859375, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+4, 187235, 1, 1657, 0, '0', 0, 0, 9662.25, 2519.780029296875, 1331.6199951171875, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+5, 187194, 1, 1657, 0, '0', 0, 0, 9919.376953125, 2271.4912109375, 1355.086669921875, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+6, 187194, 1, 1657, 0, '0', 0, 0, 9930.4130859375, 2271.809814453125, 1355.079345703125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+7, 187194, 1, 1657, 0, '0', 0, 0, 9908.3173828125, 2270.951416015625, 1355.0899658203125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+8, 187194, 1, 1657, 0, '0', 0, 0, 9973.708984375, 2273.312255859375, 1355.0858154296875, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+9, 187194, 1, 1657, 0, '0', 0, 0, 9985.8095703125, 2272.694580078125, 1354.99658203125, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: 0 - Difficulty: 0)
(@OGUID+10, 187194, 1, 1657, 1660, '0', 0, 0, 9996.8857421875, 2273.37841796875, 1355.0816650390625, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Warrior's Terrace - Difficulty: 0)
(@OGUID+11, 187194, 1, 1657, 1660, '0', 0, 0, 10119.2998046875, 2216.14990234375, 1351.8199462890625, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Warrior's Terrace - Difficulty: 0)
(@OGUID+12, 187194, 1, 1657, 1660, '0', 0, 0, 10130.900390625, 2224.819580078125, 1352.219970703125, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Warrior's Terrace - Difficulty: 0)
(@OGUID+13, 187194, 1, 1657, 1659, '0', 0, 0, 10144.400390625, 2233.65966796875, 1352.199951171875, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 47187); -- Hanging, Streamer x3 - Xmas (Area: Craftsmen's Terrace - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13);
