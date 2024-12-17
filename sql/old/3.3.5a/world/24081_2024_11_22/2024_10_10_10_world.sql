-- Pathing for Archmage Xylem: 12759
SET @NPC=8379;
SET @GUID=35886;
SET @PATH=@GUID * 10;
UPDATE `creature` SET `position_x`=3982.08,`position_y`=-4760.25,`position_z`=304.8,`orientation`=0.347593,`wander_distance`=0,`MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=@NPC;
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 3982.08, -4760.25, 304.803, 5.3781, 60000, 0, 0, 100, 0),
(@PATH, 2, 3975.94, -4767.85, 304.728, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, 3972.76, -4771.82, 304.716, NULL, 0, 0, 0, 100, 0),
(@PATH, 4, 3970.95, -4777.04, 304.728, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, 3970.78, -4780.04, 304.712, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, 3971.65, -4784.84, 304.718, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, 3976.24, -4788.04, 304.717, NULL, 0, 0, 0, 100, 0),
(@PATH, 8, 3977.89, -4786.99, 304.73, NULL, 0, 0, 0, 100, 0),
(@PATH, 9, 3977.45, -4783.41, 303.731, NULL, 0, 0, 0, 100, 0),
(@PATH, 10, 3979.76, -4780.78, 301.995, NULL, 0, 0, 0, 100, 0),
(@PATH, 11, 3983.23, -4782.2, 299.606, NULL, 0, 0, 0, 100, 0),
(@PATH, 12, 3982.05, -4785.25, 297.913, NULL, 0, 0, 0, 100, 0),
(@PATH, 13, 3974.91, -4782.9, 295.922, NULL, 0, 0, 0, 100, 0),
(@PATH, 14, 3969.92, -4784.16, 296.018, NULL, 10000, 0, 0, 100, 0),
(@PATH, 15, 3974.91, -4782.9, 295.922, NULL, 0, 0, 0, 100, 0),
(@PATH, 16, 3982.05, -4785.25, 297.913, NULL, 0, 0, 0, 100, 0),
(@PATH, 17, 3983.23, -4782.2, 299.606, NULL, 0, 0, 0, 100, 0),
(@PATH, 18, 3979.76, -4780.78, 301.995, NULL, 0, 0, 0, 100, 0),
(@PATH, 19, 3977.45, -4783.41, 303.731, NULL, 0, 0, 0, 100, 0),
(@PATH, 20, 3977.89, -4786.99, 304.73, NULL, 0, 0, 0, 100, 0),
(@PATH, 21, 3976.24, -4788.04, 304.717, NULL, 0, 0, 0, 100, 0),
(@PATH, 22, 3971.65, -4784.84, 304.718, NULL, 0, 0, 0, 100, 0),
(@PATH, 23, 3970.78, -4780.04, 304.712, NULL, 0, 0, 0, 100, 0),
(@PATH, 24, 3970.95, -4777.04, 304.728, NULL, 0, 0, 0, 100, 0),
(@PATH, 25, 3972.76, -4771.82, 304.716, NULL, 0, 0, 0, 100, 0),
(@PATH, 26, 3975.94, -4767.85, 304.728, NULL, 0, 0, 0, 100, 0);
