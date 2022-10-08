update creature_template set AIName = 'SmartAI' where entry >= '20905' and entry <= '20911';
delete from smart_scripts where entryorguid >= '20905' and entryorguid <= '20911';
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(20905, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Blazing Trickster - Set Instance Data on Death'),
(20905, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Blazing Trickster - Set Instance Data on Evade'),
(20906, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Phase-Hunter - Set Instance Data on Death'),
(20906, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Phase-Hunter - Set Instance Data on Evade'),
(20908, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Akkiris Lightning-Waker - Set Instance Data on Death'),
(20908, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Akkiris Lightning-Waker - Set Instance Data on Evade'),
(20909, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Sulfuron Magma-Thrower - Set Instance Data on Death'),
(20909, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Sulfuron Magma-Thrower - Set Instance Data on Evade'),
(20910, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Twilight Drakonaar - Set Instance Data on Death'),
(20910, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Twilight Drakonaar - Set Instance Data on Evade'),
(20911, 0, 0, 0, 6, 0, 100, 6, 0, 0, 0, 0, 34, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Blackwing Drakonaar - Set Instance Data on Death'),
(20911, 0, 1, 0, 7, 0, 100, 6, 0, 0, 0, 0, 34, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Blackwing Drakonaar - Set Instance Data on Evade');