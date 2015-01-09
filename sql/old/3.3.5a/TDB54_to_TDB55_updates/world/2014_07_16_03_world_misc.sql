--
UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=3287;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=3287 AND `source_type`=0);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(3287, 0, 0, 1, 20, 0, 100, 0, 790, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Quest reward Sarkoth  - Set Bytes 1'),
(3287, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Quest reward Sarkoth  - Store Targetlist'),
(3287, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Quest reward Sarkoth  - Face Player'),
(3287, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Quest reward Sarkoth  - Set Phase 1'),
(3287, 0, 4, 5, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - OOC (Phase 1)  - Set Bytes 1'),
(3287, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 60000, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Hana zua - OOC (Phase 1)  - Set Say Line 0'),
(3287, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - OOC (Phase 1)  - Set Phase 0'),
(3287, 0, 7, 8, 52, 0, 100, 0, 0, 3287, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Text Over Line 0  - Set Bytes 1'),
(3287, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hana zua - On Text Over Line 0  - Set Bytes 1');

DELETE FROM `creature_text` WHERE `entry`=3287;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(3287, 0, 0, 'Go swiftly, $n. My fate is in your hands.', 12, 1, 100, 0, 0, 0, 'Hana zua', 1341);
