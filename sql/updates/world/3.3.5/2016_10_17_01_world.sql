--
DELETE FROM `smart_scripts` WHERE `entryorguid`=1722601;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1722601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 17226, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Quest Credit 'Arelion's Mistress'"),
(1722601, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Say Line 2"),
(1722601, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 9, 17230, 0, 25, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Say Line 0"),
(1722601, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Say Line 3"),
(1722601, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, 61963, 17230, 0, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Set Data 1 2"),
(1722601, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 172260, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Viera Sunwhisper - On Script - Start Waypoint");
