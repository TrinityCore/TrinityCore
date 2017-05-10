--
/*
DELETE FROM `smart_scripts` WHERE `entryorguid`=6497;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6497, 0, 0, 1, 62, 0, 100, 0, 125, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Gossip Select - Close Menu'),
(6497, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with Previous Event - Set Hostile'),
(6497, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 55, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with Previous Event - Stop WP'),
(6497, 0, 3, 4, 11, 0, 100, 0, 0, 0, 0, 0, 2, 68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Spawn - Set Friendly'),
(6497, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 6497, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with previous Event - Start WP'),
(6497, 0, 5, 0, 64, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Gossip Hello - Pause WP');

UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=44738;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=44738;

DELETE FROM  `waypoint_data` WHERE `id`=447380;
DELETE FROM `waypoints` WHERE `entry`=6497;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6497, 1, 1597.4, 566.768, 37.8602, 'Astor Hadren'),
(6497, 2, 1613.91, 562.333, 35.146, 'Astor Hadren'),
(6497, 3, 1631.83, 557.812, 33.7566, 'Astor Hadren'),
(6497, 4, 1661.1, 550.278, 33.3758, 'Astor Hadren'),
(6497, 5, 1689.98, 545.014, 33.4033, 'Astor Hadren'),
(6497, 6, 1714.5, 540.561, 33.6137, 'Astor Hadren'),
(6497, 7, 1737.88, 533.75, 33.3961, 'Astor Hadren'),
(6497, 8, 1772.23, 525.741, 33.3961, 'Astor Hadren'),
(6497, 9, 1802.45, 516.861, 33.4219, 'Astor Hadren'),
(6497, 10, 1836.05, 504.973, 34.1916, 'Astor Hadren'),
(6497, 11, 1850.21, 496.778, 34.6882, 'Astor Hadren'),
(6497, 12, 1867.39, 481.534, 34.5889, 'Astor Hadren'),
(6497, 13, 1877.67, 463.224, 34.1472, 'Astor Hadren'),
(6497, 14, 1890.49, 434.482, 33.8649, 'Astor Hadren'),
(6497, 15, 1898.6, 404.11, 34.3546, 'Astor Hadren'),
(6497, 16, 1909.06, 371.483, 34.0201, 'Astor Hadren'),
(6497, 17, 1927.47, 333.806, 35.1605, 'Astor Hadren'),
(6497, 18, 1948.33, 293.56, 38.7782, 'Astor Hadren'),
(6497, 19, 1960.17, 272.962, 38.3855, 'Astor Hadren'),
(6497, 20, 1981.05, 237.328, 36.6631, 'Astor Hadren'),
(6497, 21, 1955.89, 236.574, 41.3907, 'Astor Hadren'),
(6497, 22, 1922.53, 240.366, 49.3415, 'Astor Hadren'),
(6497, 23, 1938.41, 259.961, 44.9292, 'Astor Hadren'),
(6497, 24, 1949.26, 286.982, 38.8665, 'Astor Hadren'),
(6497, 25, 1941.21, 306.375, 37.5792, 'Astor Hadren'),
(6497, 26, 1927.42, 334.68, 35.107, 'Astor Hadren'),
(6497, 27, 1912.91, 362.632, 33.9933, 'Astor Hadren'),
(6497, 28, 1899.77, 399.685, 34.2583, 'Astor Hadren'),
(6497, 29, 1894.23, 419.938, 34.2863, 'Astor Hadren'),
(6497, 30, 1883.81, 449.623, 33.9371, 'Astor Hadren'),
(6497, 31, 1865.35, 482.581, 34.6089, 'Astor Hadren'),
(6497, 32, 1839.53, 502.555, 34.3171, 'Astor Hadren'),
(6497, 33, 1810.76, 513.551, 33.4393, 'Astor Hadren'),
(6497, 34, 1780.72, 522.962, 33.3959, 'Astor Hadren'),
(6497, 35, 1744.62, 532.56, 33.3959, 'Astor Hadren'),
(6497, 36, 1713.98, 539.842, 33.5092, 'Astor Hadren'),
(6497, 37, 1683.12, 546.073, 33.4104, 'Astor Hadren'),
(6497, 38, 1642.1, 554.955, 33.448, 'Astor Hadren'),
(6497, 39, 1612.29, 563.53, 35.3895, 'Astor Hadren');
*/