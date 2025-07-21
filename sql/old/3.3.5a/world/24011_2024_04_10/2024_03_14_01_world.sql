-- Update Kialon Nightblade
UPDATE `creature_template_addon` SET `PvPFlags`=1 WHERE `entry`=18098;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=18098;

-- Waypoints
SET @PATH=64051 * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 1955.909, 6887.554, 162.2125, NULL, 0, 0, 0, 100, 0),
(@PATH, 1, 1957.126, 6870.499, 161.0544, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, 1963.431, 6862.901, 160.0951, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, 1972.715, 6859.702, 162.0977, NULL, 60000, 0, 0, 100, 0),
(@PATH, 4, 1964.917, 6866.565, 160.7522, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, 1956.629, 6881.325, 161.8812, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, 1955.969, 6887.533, 162.1539, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, 1957.679, 6894.385, 161.872, NULL, 300000, 0, 0, 100, 0);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18098;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 18098;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18098, 0, 0, 0, 40, 0, 100, 0, 3, 640510, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Kialon Nightblade - On Waypoint 3 reached - Say Line 0"),
(18098, 0, 1, 0, 40, 0, 100, 0, 7, 640510, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.45059,  "Kialon Nightblade - On Waypoint 7 reached - Set Orientation");
