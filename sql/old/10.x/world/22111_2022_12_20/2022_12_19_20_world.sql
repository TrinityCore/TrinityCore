SET @CGUID := 396652;
SET @OGUID := 251795;
SET @EVENT := 2;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Dolanaar
(@CGUID+0, 15760, 1, 141, 186, '0', 0, 0, 0, 1, 9817.052734375, 956.271484375, 1308.8724365234375, 1.884955525398254394, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Winter Reveler (Area: Dolanaar - Difficulty: 0)
(@CGUID+1, 15760, 1, 141, 186, '0', 0, 0, 0, 1, 9816.5703125, 957.97528076171875, 1308.87744140625, 4.886921882629394531, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187); -- Winter Reveler (Area: Dolanaar - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26245'), -- 15760 (Winter Reveler)
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26246'); -- 15760 (Winter Reveler)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Dolanaar
(@OGUID+0, 180844, 1, 141, 186, '0', 0, 0, 9817.0068359375, 957.181884765625, 1322.585693359375, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 47187), -- Mistletoe (Area: Dolanaar - Difficulty: 0)
(@OGUID+1, 187194, 1, 141, 186, '0', 0, 0, 9841.8798828125, 955.0830078125, 1316.25, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Dolanaar - Difficulty: 0)
(@OGUID+2, 187194, 1, 141, 186, '0', 0, 0, 9838.830078125, 965.88897705078125, 1316.25, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Dolanaar - Difficulty: 0)
(@OGUID+3, 187194, 1, 141, 186, '0', 0, 0, 9835.2900390625, 976.37200927734375, 1316.3199462890625, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Dolanaar - Difficulty: 0)
(@OGUID+4, 187235, 1, 141, 186, '0', 0, 0, 9877.009765625, 966.86798095703125, 1308.68994140625, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: Dolanaar - Difficulty: 0)
-- Aldrassil
(@OGUID+5, 187194, 1, 6450, 256, '0', 0, 0, 10385.0615234375, 771.796875, 1333.4215087890625, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Aldrassil - Difficulty: 0)
(@OGUID+6, 187194, 1, 6450, 256, '0', 0, 0, 10403.4833984375, 744.28302001953125, 1333.2265625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Aldrassil - Difficulty: 0)
(@OGUID+7, 187194, 1, 6450, 256, '0', 0, 0, 10390.9716796875, 762.6788330078125, 1333.301513671875, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Aldrassil - Difficulty: 0)
(@OGUID+8, 187194, 1, 6450, 256, '0', 0, 0, 10397.0771484375, 753.3836669921875, 1333.301513671875, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 47187), -- Hanging, Streamer x3 - Xmas (Area: Aldrassil - Difficulty: 0)
(@OGUID+9, 187235, 1, 6450, 256, '0', 0, 0, 10320.900390625, 818.420166015625, 1326.2664794921875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 47187); -- Standing, Exterior, Medium - Xmas (Area: Aldrassil - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+9;
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
(@EVENT, @OGUID+9);
