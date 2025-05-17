SET @CGUID := 10005240;

SET @GGUID := 100068;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2127, 10416, 15535, '0', 0, 0, 0, 0, 2114.19970703125, -37.5520820617675781, 4.571382045745849609, 1.704113602638244628, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Spirit Healer (Area: Flotsam Shoal - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+1, 6491, 2127, 10416, 15539, '0', 0, 0, 0, 0, 1957.532958984375, 504, 87.9236602783203125, 0.297285467386245727, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Spirit Healer (Area: Ghoststone Diggings - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 10848 - Shroud of Death)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+1;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 10416, 'Siren Isle - Flotsam Shoal'),
(@GGUID+1, 10416, 'Siren Isle - Ghoststone Diggings');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2127, 2112.4392, -32.595486, 2.91371, 5.0626/(2 * PI() / 360), 'Siren Isle - Flotsam Shoal - GY'),
(@GGUID+1, 2127, 1961.5192, 508.56598, 87.36412, 4.0042486/(2 * PI() / 360), 'Siren Isle - Ghoststone Digging1 - GY');
