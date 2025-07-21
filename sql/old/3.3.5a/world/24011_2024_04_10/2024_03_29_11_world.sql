-- Library Guardian (29724)
DELETE FROM `creature` WHERE `id`=29724 AND `guid` IN (83139,83140,83141,83142,83143);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(83139, 29724, 571, 0, 0, 1, 1, 26475, 1, 8058.83, -854.984, 971.823, 0.628318011760711669, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, '', 0),
(83140, 29724, 571, 0, 0, 1, 1, 26475, 1, 8064.08, -831.682, 971.823, 5.427969932556152343, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, '', 0),
(83141, 29724, 571, 0, 0, 1, 1, 26475, 1, 8110.12, -871.216, 957.133, 6.126110076904296875, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, '', 0),
(83142, 29724, 571, 0, 0, 1, 1, 26475, 1, 8117.55, -838.988, 957.313, 6.230820178985595703, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, '', 0),
(83143, 29724, 571, 0, 0, 1, 1, 26475, 1, 8129.377, -859.2718, 955.6569, 6.045253276824951171, 300, 0, 0, 12175, 3893, 2, 0, 0, 0, '', 0);

-- Waypoints
SET @PATH=83143 * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 8087.6626, -849.15497, 970.93066, NULL, 0, 0, 0, 100, 0),
(@PATH, 1, 8088.6396, -849.36865, 970.93066, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, 8091.55, -850.0977, 968.5479, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, 8095.437, -851.04047, 966.1648, NULL, 0, 0, 0, 100, 0),
(@PATH, 4, 8099.324, -851.9832, 963.7824, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, 8103.2114, -852.92596, 961.39984, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, 8107.0986, -853.8687, 959.09894, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, 8110.986, -854.81146, 956.6338, NULL, 0, 0, 0, 100, 0),
(@PATH, 8, 8114.873, -855.7542, 956.57263, NULL, 0, 0, 0, 100, 0),
(@PATH, 9, 8118.7603, -856.69696, 956.595, NULL, 0, 0, 0, 100, 0),
(@PATH, 10, 8122.6475, -857.6397, 956.32056, NULL, 0, 0, 0, 100, 0),
(@PATH, 11, 8126.5347, -858.58246, 955.9371, NULL, 0, 0, 0, 100, 0),
(@PATH, 12, 8130.422, -859.5252, 955.5539, NULL, 0, 0, 0, 100, 0),
(@PATH, 13, 8134.47, -860.507, 955.6393, NULL, 0, 0, 0, 100, 0);

DELETE FROM `creature_addon` WHERE `guid`=83143;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(83143, @PATH, 9474, 0, 0, 0, 0, 0, 0, 0, 0, NULL);
