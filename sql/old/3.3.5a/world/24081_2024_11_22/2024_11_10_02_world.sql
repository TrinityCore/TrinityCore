--
SET @OGUID := 12647; -- Need 4
SET @EVENT := 24;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 195256, 571, 4197, 4589, 1, 1, 5015.90380859375, 3672.697998046875, 362.823822021484375, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 0), -- Standing, Exterior, Medium - Brewfest (Area: The Chilled Quagmire - Difficulty: 0) CreateObject1
(@OGUID+1, 195256, 571, 4197, 4589, 1, 1, 5030.37744140625, 3683.822509765625, 362.924468994140625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 0), -- Standing, Exterior, Medium - Brewfest (Area: The Chilled Quagmire - Difficulty: 0) CreateObject1
(@OGUID+2, 195259, 571, 4197, 4589, 1, 1, 5027.66162109375, 3690.940185546875, 364.056243896484375, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 0), -- Hanging, Square, Small - Brewfest (Area: The Chilled Quagmire - Difficulty: 0) CreateObject1
(@OGUID+3, 195259, 571, 4197, 4589, 1, 1, 5018.60205078125, 3683.81982421875, 363.97735595703125, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 0); -- Hanging, Square, Small - Brewfest (Area: The Chilled Quagmire - Difficulty: 0) CreateObject1


DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3 AND `eventEntry`=@EVENT;
INSERT INTO `game_event_gameobject` SELECT @EVENT, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+3;
