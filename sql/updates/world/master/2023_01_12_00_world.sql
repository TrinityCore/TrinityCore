SET @CGUID := 1051255;
SET @PATH := @CGUID * 10;

UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID;

DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 89.90625, -2567.559, 65.98618, NULL, 2916),
(@PATH, 1, 81.03819, -2561.205, 66.47967, NULL, 399);

-- Fix: path_id = @guid * 100
UPDATE `creature_addon` SET `path_id`=1136680 WHERE `guid`=113668;
UPDATE `waypoint_data` SET `id`=1136680 WHERE `id`=11366800;
