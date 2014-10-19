DELETE FROM `smart_scripts` WHERE `entryorguid` = 23030 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23030, 0, 0, 0, 6, 0, 100, 2, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Sky Stalker - On Creature Death - Dismount"),
(23030, 0, 1, 0, 0, 0, 100, 2, 0, 0, 0, 0, 19, 0x02000000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Sky Stalker - In Combat - Remove unit flag"),
(23030, 0, 2, 0, 9, 0, 100, 2, 5, 41, 15800, 15800, 11, 40872, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Sky Stalker - At 5 - 41 Range - Cast Immolation Arrow"),
(23030, 0, 3, 0, 9, 0, 100, 2, 5, 41, 9800, 9800, 11, 40873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Sky Stalker - At 5 - 41 Range - Cast Shoot");
