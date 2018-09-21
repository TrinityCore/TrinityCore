--
UPDATE `spell_area` SET `spell`=44018 WHERE `spell`=44017;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24713, 2471300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24713, 0, 0, 0, 9, 0, 100, 0, 0, 5, 5000, 8000, 11, 50311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Range - Cast Thrash Kick"),
(24713, 0, 1, 0, 62, 0, 100, 512, 9335, 0, 0, 0, 80, 2471300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Gossip Option Select - Close Gossip"),
(2471300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Script - Close Gossip"),
(2471300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Script - Say Line 1"),
(2471300, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 2, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Script - Set Faction to 12"),
(2471300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "\"Crowleg\" Dan - On Script - Start Attack");
