-- correct waypointid to guid*10
UPDATE `waypoint_data` SET `id`=2026020 WHERE `id`=2026060;
UPDATE `creature_addon` SET `path_id`=2026020 WHERE `guid`=202602;
