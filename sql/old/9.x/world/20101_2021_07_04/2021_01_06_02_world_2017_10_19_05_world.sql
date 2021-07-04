-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25596) AND `source_type` IN (0) AND `id`>7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25596, 0, 8, 0, 27, 0, 100, 512, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Infected Kodo Beast - On passenger boarded - remove immune to npc"),
(25596, 0, 9, 0, 28, 0, 100, 512, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Infected Kodo Beast - On passenger removed - Set immune to npc");
