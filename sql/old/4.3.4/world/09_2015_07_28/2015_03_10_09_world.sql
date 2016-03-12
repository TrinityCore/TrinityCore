--
UPDATE creature_template SET InhabitType=4, unit_flags=64 WHERE Entry=17592;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17592 AND `source_type`=0 AND `id`IN(5, 6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17592, 0, 5, 6, 40, 0, 100, 0, 10, 17592, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Waypoint 10 Reached - Set Home Position'),
(17592, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Waypoint 10 Reached - Set Agressive'),
(17592, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razormaw - On Respawn - Add unit_flag');
