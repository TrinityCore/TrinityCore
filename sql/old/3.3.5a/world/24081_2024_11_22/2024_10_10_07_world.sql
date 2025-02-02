-- Pathing for Treebole:22215
SET @NPC=22215;
SET @GUID=77879;
SET @PATH=@GUID * 10;
UPDATE `creature` SET `position_x`=3609.03,`position_y`=6829.56,`position_z`=136.69,`orientation`=5.2105,`wander_distance`=0,`MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=@NPC;
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 3609.03, 6829.57, 136.69, 5.2105, 300000, 0, 0, 100, 0),
(@PATH, 2, 3598.63, 6845.62, 140.703, 2.54014, 0, 0, 0, 100, 0),
(@PATH, 3, 3587.26, 6853.75, 141.589, 2.52051, 0, 0, 0, 100, 0),
(@PATH, 4, 3568.35, 6864.28, 140.533, 4.41331, 300000, 0, 0, 100, 0),
(@PATH, 5, 3587.72, 6853.33, 141.546, 5.70922, 0, 0, 0, 100, 0),
(@PATH, 6, 3599.61, 6845.15, 140.649, 5.70922, 0, 0, 0, 100, 0);
