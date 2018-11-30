-- Sleyin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18926;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18926, 1892600, 1892601) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18926, 0, 0, 0, 1, 0, 100, 0, 10000, 30000, 270000, 330000, 87, 1892900, 1892901, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sleyin - Out Of Combat - Call Random Script"),
(1892600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sleyin - On Script - Say Line 0"),
(1892600, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sleyin - On Script - Say Line 1"),
(1892601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sleyin - On Script - Say Line 2"),
(1892601, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sleyin - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID`=18926;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18926, 0, 0, "Having trouble dealing with the Wretched? I've got just what you need.", 12, 0, 100, 0, 0, 0, 16058, 0, "Sleyin"),
(18926, 1, 0, "Just don't ask me where I got it...", 12, 0, 100, 0, 0, 0, 16059, 0, "Sleyin"),
(18926, 2, 0, "Something must be done about these Wretched...", 12, 0, 100, 0, 0, 0, 16091, 0, "Sleyin"),
(18926, 3, 0, "Once they're dealt with we can dedicate more resources to the war effort.", 12, 0, 100, 0, 0, 0, 16092, 0, "Sleyin");
