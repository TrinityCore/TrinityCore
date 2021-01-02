-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=23038 AND `source_type`=0 AND `id`=14;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2303802 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23038, 0, 14, 0, 20, 1, 100, 0, 11073, 0, 0, 0, 0, 80, 2303802, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Quest 'Terokk's Downfall' Rewarded - Run Script (Phase 1)"),
(2303802, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Event Phase 0"),
(2303802, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 23042, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 3 3 (Severin)"),
(2303802, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script -  Remove StandState Sit"),
(2303802, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Say Line 6"),
(2303802, 9, 4, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script -  Set StandState Sit"),
(2303802, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 23042, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 4 4 (Severin)"),
(2303802, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID`=23038 AND `GroupID`=6;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23038, 6, 0, "You're one of our bravest, $n.  All of the Skyguard is in your debt.", 12, 0, 100, 66, 0, 0, 21906, 0, "Sky Commander Adaris");
