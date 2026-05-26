-- Stratholme: Move Timmy the Cruel to database
SET @TIMMY=10808;
SET @CGUID=39690;
SET @SGROUP=327;

DELETE FROM `creature` WHERE `guid`=@CGUID AND `id`=@TIMMY;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID, @TIMMY, 329, 2017, 0, 1, 1, 0, 0, 3625.3583984375, -3188.1083984375, 130.3984832763671875, 4.834561824798583984, 604800, 0, 0, 22968, 0, 2, 0, 0, 0, '', NULL, 11159); -- Timmy the Cruel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)

DELETE FROM `spawn_group_template` WHERE `groupId`=@SGROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SGROUP, 'Stratholme - Timmy the Cruel', 4);

DELETE FROM `spawn_group` WHERE `groupId`=@SGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SGROUP, 0, @CGUID);

-- Thanks @Rushor for wp
SET @PATH=@TIMMY * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 3625.36, -3188.11, 130.398, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, 3637.91, -3196.12, 128.729, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, 3653.79, -3202.95, 127.506, NULL, 0, 0, 0, 100, 0),
(@PATH, 4, 3674.53, -3204.6, 126.548, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, 3689.46, -3191.14, 127.1, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, 3657.53, -3188.62, 126.672, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, 3655.75, -3177.17, 126.752, NULL, 0, 0, 0, 100, 0),
(@PATH, 8, 3672.97, -3171.48, 126.442, NULL, 0, 0, 0, 100, 0),
(@PATH, 9, 3680.46, -3162.15, 126.653, NULL, 0, 0, 0, 100, 0),
(@PATH, 10, 3689.46, -3191.14, 127.1, NULL, 0, 0, 0, 100, 0),
(@PATH, 11, 3674.53, -3204.6, 126.548, NULL, 0, 0, 0, 100, 0),
(@PATH, 12, 3673.84, -3194.01, 126.247, NULL, 0, 0, 0, 100, 0),
(@PATH, 13, 3668.11, -3185.75, 126.224, NULL, 0, 0, 0, 100, 0),
(@PATH, 14, 3651.18, -3196.81, 127.28, NULL, 0, 0, 0, 100, 0),
(@PATH, 15, 3658.59, -3188.92, 126.64, NULL, 0, 0, 0, 100, 0),
(@PATH, 16, 3668.11, -3185.75, 126.224, NULL, 0, 0, 0, 100, 0),
(@PATH, 17, 3678.24, -3171.01, 126.461, NULL, 0, 0, 0, 100, 0),
(@PATH, 18, 3653.57, -3174.7, 127.125, NULL, 0, 0, 0, 100, 0),
(@PATH, 19, 3645.68, -3185.68, 127.561, NULL, 0, 0, 0, 100, 0),
(@PATH, 20, 3634.09, -3178.54, 128.862, NULL, 0, 0, 0, 100, 0),
(@PATH, 21, 3623.95, -3180.23, 130.456, NULL, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=@TIMMY; -- 10808 (Timmy the Cruel)

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 3, NULL);
