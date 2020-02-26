-- 
DELETE FROM `creature_text` WHERE `CreatureID`=28913;
DELETE FROM `creature_text` WHERE `CreatureID`=28914 AND `GroupID` BETWEEN 1 AND 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28913, 0, 0, "What, Orbaz? That he's a blood elf?", 12, 0, 100, 1, 0, 0, 29192, 0, "Tharassian"),
(28913, 1, 0, "In life we were hated enemies - this is true...", 12, 0, 100, 1, 0, 0, 29193, 0, "Tharassian"),
(28913, 2, 0, "But in death... We are the children of the damned. The orphaned sons and daughters of the Scourge.", 12, 0, 100, 1, 0, 0, 29194, 0, "Tharassian"),
(28913, 3, 0, "In death we are brothers.", 12, 0, 100, 1, 0, 0, 29195, 0, "Tharassian"),
(28914, 1, 0, "Why do you care, Thassarian?", 12, 0, 100, 1, 0, 0, 29189, 0, "Orbaz Bloodbane"),
(28914, 2, 0, "His weakness led to his capture.", 12, 0, 100, 1, 0, 0, 29190, 0, "Orbaz Bloodbane"),
(28914, 3, 0, "Only the strong should survive. Not to mention...", 12, 0, 100, 1, 0, 0, 29191, 0, "Orbaz Bloodbane"),
(28914, 4, 0, "To hell with you, Thassarian.", 12, 0, 100, 25, 0, 0, 29196, 0, "Orbaz Bloodbane");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28913;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28913, 2891300) AND `source_type` IN (0, 9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=28914 AND `source_type`=0 AND `id` BETWEEN 3 AND 6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28913, 0, 0, 0, 19, 0, 100, 0, 12725, 0, 0, 0, 80, 2891300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Quest 'Brothers In Death' accepted - Run Script"),
(2891300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 1 (Orbaz Bloodbane)"),
(2891300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45,1, 1, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Set Data 1 1 (Orbaz Bloodbane)"),
(2891300, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Set Data 2 2 (Orbaz Bloodbane)"),
(2891300, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 2 (Orbaz Bloodbane)"),
(2891300, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 3 (Orbaz Bloodbane)"),
(2891300, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Face Orbaz Bloodbane"),
(2891300, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 0"),
(2891300, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 1"),
(2891300, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 2"),
(2891300, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 3"),
(2891300, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Restore Orientation"),
(2891300, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Talk 4 (Orbaz Bloodbane)"),
(2891300, 9, 12, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Set Data 3 3 (Orbaz Bloodbane)"),
(2891300, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 28914, 0, 0, 0, 0, 0, 0, "Tharassian - On Script - Set Data 4 4 (Orbaz Bloodbane)"),
(28914, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Data 1 1 Set - Stand"),
(28914, 0, 4, 0, 38, 0, 100, 0, 2, 2, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 28913, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Data 2 2 Set - Face Tharassian"),
(28914, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Data 3 3 Set - Restore Orientation"),
(28914, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orbaz Bloodbane - On Data 4 4 Set - Kneel");
