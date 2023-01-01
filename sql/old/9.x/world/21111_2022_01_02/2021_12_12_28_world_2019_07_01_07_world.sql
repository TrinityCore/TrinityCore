--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30012, 3001200) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30012, 0, 0, 0, 25, 0, 100, 512, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - On Reset - Set Faction 0"),
(30012, 0, 1, 2, 62, 0, 100, 512, 9865, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - On Gossip Option 0 Selected - Close Gossip"),
(30012, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - On Gossip Option 0 Selected - Say Line 0"),
(30012, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - On Gossip Option 0 Selected - Set Faction 14"),
(30012, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - On Gossip Option 0 Selected - Start Attacking"),
(30012, 0, 5, 0, 9, 0, 100, 0, 0, 5, 5000, 10000, 0, 11, 11971, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - Within 0-5 Range - Cast 'Sunder Armor'"),
(30012, 0, 6, 0, 0, 0, 100, 0, 10000, 15000, 15000, 20000, 0, 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Victorious Challenger - In Combat - Cast 'Rend'");
