-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23306;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23306 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23038 AND `source_type`=0 AND `id`=13;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23042 AND `source_type`=0 AND `id` IN (8, 9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2303801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23306, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Hazzik - On Data 1 1 Set - Say Line 0 (Stored Target)"),
(23038, 0, 13, 0, 20, 1, 100, 0, 11028, 0, 0, 0, 0, 80, 2303801, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Quest 'Countdown to Doom' Rewarded - Run Script (Phase 1)"),
(23042, 0, 8, 0, 38, 0, 100, 0, 3, 3, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Data 3 3 Set - Set Event Phase 0"),
(23042, 0, 9, 0, 38, 0, 100, 0, 4, 4, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Data 4 4 Set - Set Event Phase 1"),
(2303801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Event Phase 0"),
(2303801, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 23042, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 3 3 (Severin)"),
(2303801, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Store Invoker"),
(2303801, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 23306, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Send Stored Target (Hazzik)"),
(2303801, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23306, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 1 1 (Hazzik)"),
(2303801, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Say Line 5"),
(2303801, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 23042, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 4 4 (Severin)"),
(2303801, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID`=23306;
DELETE FROM `creature_text` WHERE `CreatureID`=23038 AND `GroupID`=5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23306, 0, 0, "You over there!  I must speak with you!", 15, 0, 100, 0, 0, 0, 21339, 0, "Hazzik"),
(23038, 5, 0, "Do not... bring Terokk into our world, $n...  That would be... madness...", 12, 0, 100, 0, 0, 0, 21907, 0, "Sky Commander Adaris");
