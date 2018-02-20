--
UPDATE `smart_scripts` SET `event_type`=4, `comment`="Plague Walker - On Aggro - Cast 'Aura of Lost Hope' (Dungeon)" WHERE `entryorguid`=30283 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=30283 AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30283, 0, 3, 0, 25, 0, 100, 2, 0, 0, 0, 0, 28, 56709, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plague Walker - On Reset - Remove auras from spell 'Aura of Lost Hope' (Dungeon)"),
(30283, 0, 4, 0, 25, 0, 100, 4, 0, 0, 0, 0, 28, 61459, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plague Walker - On Reset - Remove auras from spell 'Aura of Lost Hope' (Dungeon)");
