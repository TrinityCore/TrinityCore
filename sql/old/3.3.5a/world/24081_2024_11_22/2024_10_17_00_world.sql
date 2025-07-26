-- The Behemoth:14474
SET @NPC=8924;
SET @GUID=18658;
SET @PATH=@GUID * 10;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID, @NPC, 0, 0, 0, 1, 1, 0, 0, -7404.57, -894.073, 171.873, 2.89516, 108000, 0, 0, 3323, 0, 2, 0, 0, 0, '', NULL, 0);
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
-- Pathing
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -7404.57, -894.073, 171.873,NULL,0,0,0,100,0),
(@PATH, 2, -7397.19, -934.067, 169.109,NULL,0,0,0,100,0),
(@PATH, 3, -7397.22, -957.259, 170.151,NULL,0,0,0,100,0),
(@PATH, 4, -7406.08, -992.606, 173.821,NULL,0,0,0,100,0),
(@PATH, 5, -7378.71, -995.416, 171.25,NULL,0,0,0,100,0),
(@PATH, 6, -7348, -986.191, 171.532,NULL,0,0,0,100,0),
(@PATH, 7, -7346.79, -1017.81, 177.942,NULL,0,0,0,100,0),
(@PATH, 8, -7371.64, -1036.28, 177.966,NULL,0,0,0,100,0),
(@PATH, 9, -7390.05, -1044.6, 176.843,NULL,0,0,0,100,0),
(@PATH, 10, -7406.18, -1044.51, 176.751,NULL,0,0,0,100,0),
(@PATH, 11, -7390.37, -1044.6, 176.823,NULL,0,0,0,100,0),
(@PATH, 12, -7371.64, -1036.28, 177.966,NULL,0,0,0,100,0),
(@PATH, 13, -7346.79, -1017.81, 177.942,NULL,0,0,0,100,0),
(@PATH, 14, -7348, -986.191, 171.532,NULL,0,0,0,100,0),
(@PATH, 15, -7378.71, -995.416, 171.25,NULL,0,0,0,100,0),
(@PATH, 16, -7406.08, -992.606, 173.821,NULL,0,0,0,100,0),
(@PATH, 17, -7397.25, -957.381, 170.135,NULL,0,0,0,100,0),
(@PATH, 18, -7397.19, -934.067, 169.109,NULL,0,0,0,100,0),
(@PATH, 19, -7404.57, -894.073, 171.873,NULL,0,0,0,100,0),
(@PATH, 20, -7438.96, -892.375, 171.973,NULL,0,0,0,100,0);
