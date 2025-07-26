-- Pathing for Zora:14474
SET @NPC=14474;
SET @GUID=51835;
SET @PATH=@GUID * 10;
UPDATE `creature` SET `position_x`=-7378.239,`position_y`=1714.3088,`position_z`=-91.72752,`wander_distance`=0,`MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH,1,-7378.239,1714.3088,-91.72752,NULL,0,0,0,100,0),
(@PATH,2,-7393.453,1717.8257,-92.846466,NULL,0,0,0,100,0),
(@PATH,3,-7401.651,1709.8647,-92.29474,NULL,0,0,0,100,0),
(@PATH,4,-7396.23,1696.348,-92.5287,NULL,0,0,0,100,0),
(@PATH,5,-7377.1226,1687.7341,-91.2392,NULL,0,0,0,100,0),
(@PATH,6,-7368.2925,1700.2347,-86.44376,NULL,0,0,0,100,0);
