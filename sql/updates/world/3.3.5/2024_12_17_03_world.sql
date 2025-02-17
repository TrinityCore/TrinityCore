--
SET @OGUID := 12730; -- Need 4
SET @EVENT := 8;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 181015, 571, 2817, 4553, 1, 1, 5604.60791015625, 115.6718826293945312, 151.761444091796875, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 52237), -- Standing, Large - Val (Area: Forlorn Woods - Difficulty: 0) CreateObject1
(@OGUID+1, 181015, 571, 2817, 4553, 1, 1, 5604.44091796875, 113.9027786254882812, 151.72705078125, 0, 0, 0, 0, 1, 120, 255, 1, 52237), -- Standing, Large - Val (Area: Forlorn Woods - Difficulty: 0) CreateObject1
(@OGUID+2, 181015, 571, 2817, 4553, 1, 1, 5569.87744140625, 158.564239501953125, 151.6475677490234375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 52237), -- Standing, Large - Val (Area: Forlorn Woods - Difficulty: 0) CreateObject1
(@OGUID+3, 181015, 571, 2817, 4553, 1, 1, 5568.32666015625, 159.4322967529296875, 151.8090362548828125, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 52237); -- Standing, Large - Val (Area: Forlorn Woods - Difficulty: 0) CreateObject1

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3 AND `eventEntry`=@EVENT;
INSERT INTO `game_event_gameobject` SELECT @EVENT, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+3;
