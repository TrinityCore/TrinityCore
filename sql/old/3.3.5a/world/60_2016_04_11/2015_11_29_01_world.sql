--
DELETE FROM `creature_text` WHERE `entry` = 22293;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `TextRange`, `comment`, `BroadcastTextId`) VALUES
(22293, 0, 0, "%s begins to sputter as its engine malfunctions.", 16, 0, 100, 0, 0, 0, 0, "Inactive Fel Reaver", 20103);

-- Creature Script - Inactive Fel Reaver
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22293);
DELETE FROM `smart_scripts` WHERE (source_type = 9 AND entryorguid = 2229300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22293, 0, 0, 0, 20, 0, 100, 0, 10850, 0, 0, 0, 80, 2229300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - On Quest complete - Action list'),
(2229300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list - Say text'),
(2229300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list  - Remove npc flag'),
(2229300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list - Random Move'),
(2229300, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 33, 22293, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list - Give Credit'),
(2229300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list - Kill Itself');
