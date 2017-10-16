/*
-- Add waypoints and fix spawnpoint of Fury Shelda
SET @GUID := 46352;
SET @PATH_ID := @GUID * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_addon` SET `path_id`=@PATH_ID WHERE `guid`=@GUID;
UPDATE `creature` SET `position_x`=10652.09, `position_y`=2065.57, `position_z`=1330.613, `orientation`=4.3596 WHERE `guid`=@GUID;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 1, 10630.13, 2031.82, 1331.574),
(@PATH_ID, 2, 10600.19, 2014.94, 1329.95),
(@PATH_ID, 3, 10555.86, 2005.13, 1327.46),
(@PATH_ID, 4, 10523.80, 1974.52, 1327.12),
(@PATH_ID, 5, 10499.34, 1950.97, 1321.42),
(@PATH_ID, 6, 10459.50, 1936.29, 1319.83),
(@PATH_ID, 7, 10420.30, 1924.04, 1320.09),
(@PATH_ID, 8, 10369.82, 1909.25, 1321.91),
(@PATH_ID, 9, 10420.30, 1924.04, 1320.09),
(@PATH_ID, 10, 10459.50, 1936.29, 1319.83),
(@PATH_ID, 11, 10499.34, 1950.97, 1321.42),
(@PATH_ID, 12, 10523.80, 1974.52, 1327.12),
(@PATH_ID, 13, 10555.86, 2005.13, 1327.46),
(@PATH_ID, 14, 10600.19, 2014.94, 1329.95),
(@PATH_ID, 15, 10630.13, 2031.82, 1331.574),
(@PATH_ID, 16, 10652.09, 2065.57, 1330.61);
*/
