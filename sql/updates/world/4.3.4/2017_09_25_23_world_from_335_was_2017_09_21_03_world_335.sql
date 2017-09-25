/*
-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2498;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2498, 249800) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2498, 0, 0, 0, 20, 0, 100, 0, 621, 0, 0, 0, 80, 249800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crank Fizzlebub - On Quest 'Zanzil's Secret' Rewarded - Run Script"),
(249800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Crank Fizzlebub - On Script - Say Line 0"),
(249800, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Crank Fizzlebub - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2498;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2498, 0, 0, "Thank you, $n.", 12, 0, 100, 0, 0, 0, 1469, 0, "Crank Fizzlebub"),
(2498, 1, 0, "I'm sure I can find a use for this mixture...", 12, 0, 100, 0, 0, 0, 1470, 0, "Crank Fizzlebub");
*/
