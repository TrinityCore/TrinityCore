-- 
DELETE FROM `areatrigger_scripts` WHERE `entry`=4071;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4071 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16295 AND `source_type`=0 AND `id`=8;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16295, 0, 8, 0, 1, 1, 100, 0, 20000, 40000, 60000, 180000, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ranger Lilatha - OOC - Say Line 6 (Phase 1)");
