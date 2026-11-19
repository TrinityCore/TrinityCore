SET @CGUID := 396661;
SET @OGUID := 251907;
SET @EVENT := 2;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (89377, 89378);
DELETE FROM `game_event_creature` WHERE `guid` IN (89377, 89378);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Azure Watch
(@CGUID+0, 15760, 530, 3524, 3576, '0', 0, 0, 0, 1, -4123.8662109375, -12475.41015625, 44.65128326416015625, 1.259354591369628906, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Winter Reveler (Area: Azure Watch - Difficulty: 0)
(@CGUID+1, 15760, 530, 3524, 3576, '0', 0, 0, 0, 1, -4123.24658203125, -12473.486328125, 44.65177154541015625, 4.453307151794433593, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187); -- Winter Reveler (Area: Azure Watch - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '39858'), -- 15760 (Winter Reveler)
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 0, '39859'); -- 15760 (Winter Reveler)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 79542 AND 79554;
DELETE FROM `gameobject` WHERE `guid` IN (41187, 79569);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 79542 AND 79554;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (41187, 79569);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Azure Watch
(@OGUID+0, 180844, 530, 3524, 3576, '0', 0, 0, -4123.37353515625, -12474.455078125, 54.29829788208007812, 1.329165458679199218, 0, 0, 0.616730690002441406, 0.787174165248870849, 120, 255, 1, 47187), -- Mistletoe (Area: Azure Watch - Difficulty: 0)
(@OGUID+1, 187235, 530, 3524, 3576, '0', 0, 0, -4185.7119140625, -12504.830078125, 44.36132049560546875, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+2, 187235, 530, 3524, 3576, '0', 0, 0, -4212.52685546875, -12510.3369140625, 45.444061279296875, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+3, 187235, 530, 3524, 3576, '0', 0, 0, -4158.138671875, -12463.0830078125, 45.08137893676757812, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+4, 187235, 530, 3524, 3576, '0', 0, 0, -4171.6240234375, -12506.6240234375, 44.36132049560546875, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+5, 187235, 530, 3524, 3576, '0', 0, 0, -4158.6435546875, -12533.3291015625, 45.45203781127929687, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+6, 187235, 530, 3524, 3576, '0', 0, 0, -4209.37939453125, -12517.650390625, 45.81722259521484375, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+7, 187235, 530, 3524, 3576, '0', 0, 0, -4214.63330078125, -12476.001953125, 45.07409286499023437, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+8, 187235, 530, 3524, 3576, '0', 0, 0, -4153.74169921875, -12484.6025390625, 44.51341629028320312, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+9, 187235, 530, 3524, 3576, '0', 0, 0, -4176.95849609375, -12493.9736328125, 44.36100006103515625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+10, 187567, 530, 3524, 3576, '0', 0, 0, -4152.03466796875, -12529.416015625, 49.52318954467773437, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 47187), -- Hanging, Streamer - Xmas (Area: Azure Watch - Difficulty: 0)
(@OGUID+11, 187567, 530, 3524, 3576, '0', 0, 0, -4205.994140625, -12527.1259765625, 50.12774658203125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 47187), -- Hanging; Streamer - Xmas (Area: Azure Watch - Difficulty: 0)
-- Ammen Vale
(@OGUID+12, 187235, 530, 6456, 3527, '0', '0', 0, -4048.503173828125, -13778.9306640625, 75.01584625244140625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Crash Site - Difficulty: 0)
(@OGUID+13, 187567, 530, 6456, 3527, '0', '0', 0, -4054.646240234375, -13772.2783203125, 84.39475250244140625, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 47187), -- Hanging, Streamer - Xmas (Area: Crash Site - Difficulty: 0)
(@OGUID+14, 187567, 530, 6456, 3527, '0', '0', 0, -4171.05322265625, -13734.392578125, 82.08740997314453125, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 47187); -- Hanging, Streamer - Xmas (Area: Crash Site - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+14;
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
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14);
