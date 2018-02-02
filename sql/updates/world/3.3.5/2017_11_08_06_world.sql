-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2891400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2891400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Stand"),
(2891400, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.39, "Orbaz Bloodbane - On Script - Turn"),
(2891400, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 53105, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Cast 'Acherus Portal Dummy'"),
(2891400, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 53097, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Cast 'Portal: Acherus'"),
(2891400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Say Line 0"),
(2891400, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Turn"),
(2891400, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Script - Kneel");
