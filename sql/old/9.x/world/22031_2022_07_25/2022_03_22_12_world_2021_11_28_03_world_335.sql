--
DELETE FROM `smart_scripts` WHERE `id` IN (3,5) AND `entryorguid`=2433 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2433, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 2433, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Spawn - Start Waypoint'),
(2433, 0, 5, 0, 58, 0, 100, 0, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Waypoint Finished - Delayed Despawn');

DELETE FROM `waypoints` WHERE `entry`=2433;
INSERT INTO `waypoints` VALUES
(2433, 1, -749.03, -598.01, 18.4133, 0, 0, 'Helcular Remains'),
(2433, 2, -773.83, -587.81, 15.9183, 0, 0, 'Helcular Remains'),
(2433, 3, -747.35, -586.21, 19.8563, 0, 0, 'Helcular Remains'),
(2433, 4, -755.06, -570.77, 19.3430, 0, 0, 'Helcular Remains'),
(2433, 5, -773.37, -546.27, 17.8202, 0, 0, 'Helcular Remains'),
(2433, 6, -820.27, -533.12, 15.0504, 0, 0, 'Helcular Remains'),
(2433, 7, -842.47, -540.02, 12.7530, 0, 0, 'Helcular Remains'),
(2433, 8, -864.46, -521.96, 10.8711, 0, 0, 'Helcular Remains'),
(2433, 9, -878.53, -532.17, 10.0846, 0, 0, 'Helcular Remains'),
(2433, 10, -921.94, -524.36, 6.8796, 0, 0, 'Helcular Remains'),
(2433, 11, -904.65, -545.08, 6.8796, 0, 0, 'Helcular Remains'),
(2433, 12, -900.60, -577.46, 6.8796, 0, 0, 'Helcular Remains');
