-- Stratholme: Move Timmy the Cruel to database
SET @TIMMY=10808;
SET @CGUID=39690;

DELETE FROM `creature` WHERE `guid`=@CGUID AND `id`=@TIMMY;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `curHealthPct`, `MovementType`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID, @TIMMY, 329, 2017, 0, '1', 0, 0, 0, 3730.4882, -3261.4194, 128.18633, 3.021940, 604800, 5, 100, 1, '', NULL, 68256); -- Timmy the Cruel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)

DELETE FROM `creature` WHERE `guid` IN (52173,53008,52210,53164,53163,53007,52209) AND `map`=329;
