-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15291;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15291 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1529100, 1529101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15291, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 50000, 120000, 53, 0, 15291, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - Out Of Combat - Start Waypoint"),
(15291, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, 1529100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - On WP 2 Reached - Run Actionlist"),
(15291, 0, 2, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, 1529101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - On WP 4 Reached - Run Actionlist"),
(1529100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 9000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - On Script - Pause Waypoint"),
(1529100, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.9839, "Jainthess Thelryn - On Script - Change Orientation"),
(1529100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - On Script - Emote 'Oneshot Point'"),
(1529101, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jainthess Thelryn - On Script - Emote 'Oneshot Kneel'"),
(1529101, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.0143, "Jainthess Thelryn - On Script - Change Orientation");

DELETE FROM `waypoints` WHERE `entry`=15291;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(15291, 1, 10419.11, -6319.905, 35.5736, "Jainthess Thelryn"),
(15291, 2, 10424.43, -6320.706, 35.5736, "Jainthess Thelryn"),
(15291, 3, 10419.11, -6319.905, 35.5736, "Jainthess Thelryn"),
(15291, 4, 10416.7998, -6316.6001, 35.5763, "Jainthess Thelryn");
