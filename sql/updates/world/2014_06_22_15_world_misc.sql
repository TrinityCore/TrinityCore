--
UPDATE `smart_scripts` SET `event_type`=11 WHERE  `entryorguid`=24788 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24639 AND `id`>2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24639, 0, 3, 0, 40, 0, 100, 0, 3, 246390, 0, 0, 66, 5.07, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 'Olga, the Scalawag Wench - On Waypoint 3 (Return) Reached - Set Orientation'),
(24639, 0, 4, 5, 38, 0, 100, 0, 4, 4, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olga, the Scalawag Wench - On Data set 4 4 - Set Data 1 0'),
(24639, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olga, the Scalawag Wench - On Data set 4 4 - Set NPC Flags');

DELETE FROM `smart_scripts` WHERE `entryorguid`=24788 AND `id`>7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24788, 0, 8, 9, 25, 0, 100, 0, 0, 0, 0, 0, 28, 58806, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jack Adams - On Reset - Remove permanent feign death'),
(24788, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 24639, 0, 0, 0, 0, 0, 0, 'Jack Adams - On Reset - Set Data 4 4');

UPDATE `smart_scripts` SET `action_param1`=58806 WHERE  `entryorguid`=2478800 AND `source_type`=9 AND `id`=6 AND `link`=0;

DELETE FROM `waypoints` WHERE `entry`=246390 AND `pointid`=3;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(246390, 3, -91.8194, -3532.71, 7.7126, 'Olga, the Scalawag Wench');
