-- The Behemoth:14474
SET @NPC=8924;
SET @GUID=18658;
SET @PATH=1492640;
DELETE FROM `creature` WHERE `guid` IN (@GUID,289871);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID, @NPC, 0, 0, 0, '0', 0, 0, 0, -7413.0767, -886.08105, 171.9364, 5.528909206390380859, 300, 0, 0, 100, 2, '', NULL, 0);
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
-- Pathing
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x1, NULL, 'The Behemoth - Idle');
DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -7438.9595, -892.37555, 172.11932, NULL, 300),
(@PATH, 1, -7404.5703, -894.07355, 171.88318, NULL, 0),
(@PATH, 2, -7397.191, -934.0672, 169.25267, NULL, 0),
(@PATH, 3, -7397.218, -957.25903, 170.18488, NULL, 0),
(@PATH, 4, -7406.079, -992.60547, 173.96391, NULL, 0),
(@PATH, 5, -7378.7056, -995.4157, 171.39268, NULL, 0),
(@PATH, 6, -7347.9946, -986.1914, 171.59592, NULL, 0),
(@PATH, 7, -7346.789, -1017.8084, 178.07593, NULL, 0),
(@PATH, 8, -7371.6406, -1036.2809, 178.07576, NULL, 0),
(@PATH, 9, -7390.0503, -1044.6013, 176.90913, NULL, 0),
(@PATH, 10, -7406.178, -1044.5083, 176.88202, NULL, 300);
