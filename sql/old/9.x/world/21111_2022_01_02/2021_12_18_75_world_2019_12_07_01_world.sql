-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18399) AND `source_type`=0 AND `id`IN (11,12);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18399, 0, 11, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 39, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Murkblood Twin - On Aggro - Call for Help"),
(18399, 0, 12, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 45, 16, 16, 0, 0, 0, 0, 19, 18471, 0, 0, 0, 0, 0, 0, 0, "Murkblood Twin - On evade - Set Data");

