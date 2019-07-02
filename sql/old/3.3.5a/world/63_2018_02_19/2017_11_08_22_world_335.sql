--
UPDATE `creature_text` SET `Type`=12 WHERE `CreatureID`=4049;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4049, 404900) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4049, 0, 0, 0, 20, 0, 100, 0, 1062, 0, 0, 0, 80, 404900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seereth Stonebreak - On Quest 'Goblin Invaders' Finished - Call Script"),
(404900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Seereth Stonebreak - On Script - Say Line 0"),
(404900, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Seereth Stonebreak - On Script - Say Line 1");
