-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=23671 AND `source_type`=0 AND `id` IN (17,18);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23671, 0, 17, 18, 1, 0, 100, 1, 30000, 30000, 0, 0, 44, 2, 0, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Ooc - Change Phasemask of Val'kyr Observer"),
(23671, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Ooc - despawn");
