DELETE FROM `creature` WHERE `id`=19461;
DELETE FROM `script_waypoint` WHERE `entry`=17077 AND `pointid` IN (51, 52);
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(17077, 51, 519.146, 3886.7, 190.128, 10000, 'RYGA_WALK'),
(17077, 52, 519.146, 3886.7, 190.128, 1000, 'RYGA_RETURN');
