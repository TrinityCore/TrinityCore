--
UPDATE `creature` SET `position_x`=7131.1055, `position_y`=-788.2168, `position_z`=68.10991, `orientation`=4.823452 WHERE `id`=3662;

DELETE FROM `waypoints` WHERE `entry`=3662;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(3662, 1, 7131.1055, -788.2168, 68.10991, 0, 0, "Delmanis the Hated"),
(3662, 2, 7132.319, -799.05426, 67.09526, 0, 0, "Delmanis the Hated"),
(3662, 3, 7133.391, -809.255, 64.173874, 0, 0, "Delmanis the Hated"),
(3662, 4, 7132.592, -825.3632, 60.088867, 0, 0, "Delmanis the Hated"),
(3662, 5, 7136.054, -835.60803, 60.363438, 0, 0, "Delmanis the Hated"),
(3662, 6, 7145.682, -835.7192, 57.829746, 0, 0, "Delmanis the Hated"),
(3662, 7, 7154.4517, -830.9819, 54.855022, 0, 0, "Delmanis the Hated"),
(3662, 8, 7169.194, -830.2854, 49.796597, 0, 0, "Delmanis the Hated"),
(3662, 9, 7177.8423, -833.73816, 47.257225, 0, 0, "Delmanis the Hated"),
(3662, 10, 7188.6157, -836.9415, 44.124046, 0, 0, "Delmanis the Hated"),
(3662, 11, 7195.45, -832.04913, 41.127407, 0, 0, "Delmanis the Hated"),
(3662, 12, 7198.3066, -820.4954, 38.81564, 0, 0, "Delmanis the Hated"),
(3662, 13, 7195.53, -810.4779, 39.79794, 0, 0, "Delmanis the Hated"),
(3662, 14, 7193.8965, -797.9671, 38.692898, 0, 0, "Delmanis the Hated"),
(3662, 15, 7188.472, -794.70746, 40.270535, 0, 0, "Delmanis the Hated"),
(3662, 16, 7176.377, -793.9976, 45.066433, 0, 0, "Delmanis the Hated"),
(3662, 17, 7170.9253, -787.92346, 48.985744, 0, 0, "Delmanis the Hated"),
(3662, 18, 7167.9863, -774.2246, 54.308132, 0, 0, "Delmanis the Hated"),
(3662, 19, 7163.884, -768.92413, 55.71805, 0, 0, "Delmanis the Hated"),
(3662, 20, 7161.0376, -757.4025, 53.92047, 0, 0, "Delmanis the Hated"),
(3662, 21, 7154.1353, -751.6702, 52.957825, 0, 0, "Delmanis the Hated"),
(3662, 22, 7145.8936, -753.8559, 52.582825, 0, 0, "Delmanis the Hated"),
(3662, 23, 7147.176, -762.29254, 52.995422, 0, 0, "Delmanis the Hated"),
(3662, 24, 7166.4023, -774.916, 54.510773, 0, 0, "Delmanis the Hated"),
(3662, 25, 7170.045, -789.13605, 49.020412, 0, 0, "Delmanis the Hated"),
(3662, 26, 7179.686, -794.86035, 43.309353, 0, 0, "Delmanis the Hated"),
(3662, 27, 7192.227, -794.8646, 38.97256, 0, 0, "Delmanis the Hated"),
(3662, 28, 7197.3394, -805.05524, 38.384, 0, 0, "Delmanis the Hated"),
(3662, 29, 7195.4526, -829.2479, 41.02145, 0, 0, "Delmanis the Hated"),
(3662, 30, 7186.5693, -837.9603, 44.8655, 0, 0, "Delmanis the Hated"),
(3662, 31, 7175.428, -845.94464, 48.054955, 0, 0, "Delmanis the Hated"),
(3662, 32, 7166.092, -849.53906, 50.470615, 0, 0, "Delmanis the Hated"),
(3662, 33, 7158.5493, -840.9361, 53.055332, 0, 0, "Delmanis the Hated"),
(3662, 34, 7152.6226, -833.03296, 55.390423, 0, 0, "Delmanis the Hated"),
(3662, 35, 7137.1543, -828.1305, 58.789837, 0, 0, "Delmanis the Hated"),
(3662, 36, 7138.5425, -812.9168, 62.99467, 0, 0, "Delmanis the Hated"),
(3662, 37, 7139.283, -787.2907, 67.73428, 0, 1000, "Delmanis the Hated"),
(3662, 38, 7131.9287, -780.9421, 67.05461, 0, 0, "Delmanis the Hated");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3662 AND `source_type`=0 AND `id` IN (3, 4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=366200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3662, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 3662, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Delmanis the Hated - On Respawn - Start Waypoint"),
(3662, 0, 4, 0, 40, 0, 100, 0, 38, 0, 0, 0, 0, 80, 366200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Delmanis the Hated - On Waypoint 38 Reached - Run Script"),
(366200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Delmanis the Hated - On Script - Set Random Move (5 Yards)"),
(366200, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 0, 53, 0, 3662, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Delmanis the Hated - On Script - Start Waypoint");
