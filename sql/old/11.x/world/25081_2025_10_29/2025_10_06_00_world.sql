-- Westfall Rares: Slark, Brack, Master Digger, Leprithus
SET @CGUID := 224147;

-- Update creature spawn pos with createobject2 data
UPDATE `creature` SET `position_x` = -9627.0400390625, `position_y` = 1042.1500244140625, `position_z` = 7.119823455810546875, `orientation` = 2.202322244644165039, `VerifiedBuild` = 63305 WHERE `guid` = 276279;
UPDATE `creature` SET `position_x` = -9840.1298828125, `position_y` = 1392.18994140625, `position_z` = 37.94233322143554687, `orientation` = 2.219662427902221679 , `VerifiedBuild` = 63305 WHERE `guid` = 275919;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 520, 0, 40, 2, '0', 0, 0, 0, 1, -11382.5302734375, 1805.13916015625, 8.410287857055664062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Brack (Area: Longshore - Difficulty: 0) CreateObject2
(@CGUID+1, 572, 0, 40, 0, '0', 0, 0, 0, 0, -10085.751953125, 1558.404541015625, 40.9974822998046875, 4.066617012023925781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Leprithus (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+2, 846, 0, 40, 0, '0', 0, 0, 0, 0, -10081.9912109375, 1557.95654296875, 41.22451400756835937, 5.689773082733154296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rotten Ghoul (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+3, 846, 0, 40, 0, '0', 0, 0, 0, 0, -10083.8564453125, 1556.6685791015625, 41.06193161010742187, 4.764749050140380859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Rotten Ghoul (Area: 0 - Difficulty: 0) CreateObject2

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`IN (519,520,846,572) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=519 AND `DifficultyID`=0); -- 519 (Slark) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=6, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=520 AND `DifficultyID`=0); -- 520 (Brack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=6, `StaticFlags1`=0x0, `VerifiedBuild`=63305 WHERE (`Entry`=846 AND `DifficultyID`=0); -- 846 (Rotten Ghoul) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=6, `StaticFlags1`=0x0, `VerifiedBuild`=63305 WHERE (`Entry`=572 AND `DifficultyID`=0); -- 572 (Leprithus) - 

-- Update movement
UPDATE `creature` SET `wander_distance`=2, `MovementType`=1 WHERE `guid`= 275919;

-- Update spawntimesecs - Spawntime should be between 30 - 60 minutes (nyi)
UPDATE `creature` SET `spawntimesecs` = 3600 WHERE `guid` IN (276279,275919, @CGUID+0);

-- Leprithus spawns only once per night event at 8pm
UPDATE `creature` SET `spawntimesecs` = 36000 WHERE `guid` = @CGUID+1;

-- Creature Formation
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+1;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+1, @CGUID+1, 0, 0, 3, 0, 0),
(@CGUID+1, @CGUID+2, 0, 0, 3, 0, 0),
(@CGUID+1, @CGUID+3, 0, 0, 3, 0, 0);

-- GameEvents (Night)
DELETE FROM `game_event_creature` WHERE (`eventEntry` = 25 AND `guid` IN (@CGUID+1,@CGUID+2,@CGUID+3));
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(25, @CGUID+1),
(25, @CGUID+2),
(25, @CGUID+3);

-- Path for Slark
SET @MOVERGUID := 276279;
SET @ENTRY := 519;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Slark - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9658.67, 1083.16, 9.985499, NULL, 0),
(@PATH, 1, -9680.95, 1098.29, 11.84145, NULL, 0),
(@PATH, 2, -9678.79, 1121.82, 8.715832, NULL, 0),
(@PATH, 3, -9664.5, 1136.53, 7.0377398, NULL, 0),
(@PATH, 4, -9651.69, 1153.71, 5.661127, NULL, 0),
(@PATH, 5, -9647.02, 1172.72, 6.90375, NULL, 0),
(@PATH, 6, -9650.58, 1200.4, 9.975912, NULL, 0),
(@PATH, 7, -9666.19, 1235.72, 9.289491, NULL, 0),
(@PATH, 8, -9633.176, 1217.6323, 7.110218, NULL, 0),
(@PATH, 9, -9632.59, 1215.72, 6.8077264, NULL, 0),
(@PATH, 10, -9632.004, 1213.8076, 6.5052347, NULL, 0),
(@PATH, 11, -9631.125, 1210.9395, 6.1726036, NULL, 0),
(@PATH, 12, -9629.953, 1207.1152, 5.970174, NULL, 0),
(@PATH, 13, -9628.195, 1201.3789, 6.184729, NULL, 0),
(@PATH, 14, -9627.316, 1198.5107, 6.432972, NULL, 0),
(@PATH, 15, -9626.4375, 1195.6426, 6.6064353, NULL, 0),
(@PATH, 16, -9624.973, 1190.8623, 6.36508, NULL, 0),
(@PATH, 17, -9624.75, 1190.18, 6.4010525, NULL, 0),
(@PATH, 18, -9621.14, 1156.26, 4.582095, NULL, 0),
(@PATH, 19, -9638.33, 1128.18, 5.4616294, NULL, 0),
(@PATH, 20, -9648.23, 1095.11, 7.851682, NULL, 0),
(@PATH, 21, -9635.76, 1078.21, 6.0993657, NULL, 0),
(@PATH, 22, -9618.04, 1049.81, 7.696491, NULL, 0),
(@PATH, 23, -9634.15, 1045.66, 8.429413, NULL, 0),
(@PATH, 24, -9645.46, 1067.31, 8.098515, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Bark
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 520;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Brack - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -11334.3, 1820.82, 11.3984165, NULL, 0),
(@PATH, 1, -11323.1, 1847.23, 11.678829, NULL, 0),
(@PATH, 2, -11322.3, 1872.74, 12.542551, NULL, 0),
(@PATH, 3, -11331.1, 1886.89, 10.049097, NULL, 0),
(@PATH, 4, -11322.6, 1903.16, 10.28702, NULL, 0),
(@PATH, 5, -11305.3, 1916.46, 10.718233, NULL, 0),
(@PATH, 6, -11301.7, 1932.71, 9.455284, NULL, 0),
(@PATH, 7, -11291.5, 1947.28, 10.18465, NULL, 0),
(@PATH, 8, -11268.2, 1960.64, 10.672818, NULL, 0),
(@PATH, 9, -11240.6, 1971.12, 10.715382, NULL, 0),
(@PATH, 10, -11215.1, 1986.9, 11.243917, NULL, 0),
(@PATH, 11, -11197.3, 1998.39, 11.200207, NULL, 0),
(@PATH, 12, -11179.3, 1994.63, 10.357056, NULL, 0),
(@PATH, 13, -11151, 1996.52, 9.9727335, NULL, 0),
(@PATH, 14, -11122.4, 2001.22, 8.3284, NULL, 0),
(@PATH, 15, -11090.7, 2011.1, 7.8235083, NULL, 0),
(@PATH, 16, -11059.5, 2009.94, 9.429759, NULL, 0),
(@PATH, 17, -11034.1, 2028.67, 10.9667425, NULL, 0),
(@PATH, 18, -11012, 2023.92, 11.82601, NULL, 0),
(@PATH, 19, -10999.7, 2034.1, 12.647066, NULL, 0),
(@PATH, 20, -11005.7, 2044.73, 10.891759, NULL, 0),
(@PATH, 21, -11023.1, 2045.1, 9.171375, NULL, 0),
(@PATH, 22, -11039.1, 2041.65, 10.645846, NULL, 0),
(@PATH, 23, -11061.3, 2030.32, 8.771031, NULL, 0),
(@PATH, 24, -11088.6, 1996, 9.406014, NULL, 0),
(@PATH, 25, -11120.3, 1994.84, 9.737846, NULL, 0),
(@PATH, 26, -11154.3, 2012.51, 5.9090576, NULL, 0),
(@PATH, 27, -11174.1, 2020.69, 4.4111633, NULL, 0),
(@PATH, 28, -11185.7, 2019.04, 5.7014437, NULL, 0),
(@PATH, 29, -11206.7, 2003.88, 8.7110195, NULL, 0),
(@PATH, 30, -11226, 1994.31, 8.714533, NULL, 0),
(@PATH, 31, -11249.2, 1992.84, 6.766321, NULL, 0),
(@PATH, 32, -11281.1, 1978.71, 6.499329, NULL, 0),
(@PATH, 33, -11299.801, 1962.1084, 6.2086263, NULL, 0),
(@PATH, 34, -11316.6, 1939.71, 7.068871, NULL, 0),
(@PATH, 35, -11325.7, 1916.5, 8.485589, NULL, 0),
(@PATH, 36, -11337.6, 1892.39, 8.121015, NULL, 0),
(@PATH, 37, -11334.9, 1866.87, 10.1735735, NULL, 0),
(@PATH, 38, -11341.9, 1843.51, 9.1919155, NULL, 0),
(@PATH, 39, -11358.02, 1830.0361, 7.4541655, NULL, 0),
(@PATH, 40, -11365.254, 1822.9746, 7.2744493, NULL, 0),
(@PATH, 41, -11368.027, 1820.0918, 7.039713, NULL, 0),
(@PATH, 42, -11370.107, 1817.9297, 6.857504, NULL, 0),
(@PATH, 43, -11370.801, 1817.209, 7.034489, NULL, 0),
(@PATH, 44, -11374.961, 1812.8848, 7.2986364, NULL, 0),
(@PATH, 45, -11376.348, 1811.4434, 7.581752, NULL, 0),
(@PATH, 46, -11378.428, 1809.2812, 7.8499217, NULL, 0),
(@PATH, 47, -11380.508, 1807.1191, 8.057067, NULL, 0),
(@PATH, 48, -11382.5, 1805.03, 8.166422, NULL, 0),
(@PATH, 49, -11360.7, 1819.91, 8.054203, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
