--
UPDATE `smart_scripts` SET `action_param3`=15000, `target_type`=8, `target_x`=-10238.1572, `target_y`=353.7254, `target_z`=50.9208, `target_o`=2.7230 WHERE `entryorguid`=61 AND `source_type`=1 AND `id`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3301, 330100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3301, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 330100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Spawn - Start Script"),
(330100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Script - Set Flags Not Attackable & Immune To NPC's"),
(330100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Script - Emote Bow"),
(330100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 84, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Script - Say Line 1"),
(330100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 84, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Script - Say Line 2"),
(330100, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Morgan Ladimore - On Script - Set Flag Standstate Kneel");
