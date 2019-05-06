--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (6171, 5489, 6173);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6171, 548900, 617300) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6171, 0, 0, 0, 19, 0, 100, 0, 1781, 0, 0, 0, 80, 548900, 0, 0, 0, 0, 0, 19, 5489, 0, 0, 0, 0, 0, 0, "Duthorian Rall - On Quest 'The Tome of Divinity' Accepted - Run Script (Brother Joshua)"),
(548900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 2053, 0, 0, 0, 0, 0, 19, 6173, 0, 0, 0, 0, 0, 0, "Brother Joshua - On Script - Cast 'Lesser Heal' (Gazin Tenorm)"),
(548900, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 80, 617300, 0, 0, 0, 0, 0, 19, 6173, 0, 0, 0, 0, 0, 0, "Brother Joshua - On Script - Run Script (Gazin Tenorm)"),
(617300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 5489, 0, 0, 0, 0, 0, 0, "Gazin Tenorm - On Script - Face NPC 'Brother Joshua'"),
(617300, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 1, 0, 0, 0, 19, 5489, 0, 0, 0, 0, 0, 0, "Gazin Tenorm - On Script - Say Line 0"),
(617300, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.206, "Gazin Tenorm - On Script - Reset Orientation");

DELETE FROM `creature_text` WHERE `creatureid`=6173;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6173, 0, 0, "Thanks to you, $n.", 12, 0, 100, 0, 0, 0, 2284, 0, "Gazin Tenorm");
