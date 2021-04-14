-- Fix "There is no waypoint which links to the waypoint script 332"

DELETE FROM `waypoint_scripts` WHERE `id`=332;
DELETE FROM `db_script_string` WHERE `entry`=2000005146;
