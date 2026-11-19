-- 
-- Quests Poison Water and Thunderhorn Totem
DELETE FROM `creature_text` WHERE `CreatureID`=2948;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2948, 0, 0, "%s begins a rite of creation...", 16, 0, 100, 0, 0, 0, 952, 0, "Mull Thunderhorn"),
(2948, 0, 1, "%s holds high the items $n gave him...", 16, 0, 100, 0, 0, 0, 955, 0, "Mull Thunderhorn"),
(2948, 0, 2, "%s enters a trance...", 16, 0, 100, 0, 0, 0, 999, 0, "Mull Thunderhorn"),
(2948, 0, 3, "%s uses $n's offering in a ritual...", 16, 0, 100, 0, 0, 0, 1000, 0, "Mull Thunderhorn"),
(2948, 0, 4, "%s accepts $n's offering, and begins to chant...", 16, 0, 100, 0, 0, 0, 1001, 0, "Mull Thunderhorn"),
(2948, 0, 5, "%s draws power to him...", 16, 0, 100, 0, 0, 0, 1002, 0, "Mull Thunderhorn"),
(2948, 0, 6, "%s transforms the items $n gave him into a totem of cleansing...", 16, 0, 100, 0, 0, 0, 1003, 0, "Mull Thunderhorn"),
(2948, 0, 7, "%s creates a new totem...", 16, 0, 100, 0, 0, 0, 1004, 0, "Mull Thunderhorn"),
(2948, 1, 0, "It is done.", 12, 3, 100, 0, 0, 0, 953, 0, "Mull Thunderhorn"),
(2948, 1, 1, "The totem is made, $n.", 12, 3, 100, 0, 0, 0, 954, 0, "Mull Thunderhorn"),
(2948, 1, 2, "I have the totem of cleansing, $n.", 12, 3, 100, 0, 0, 0, 1005, 0, "Mull Thunderhorn"),
(2948, 1, 3, "The totem is made.  The well may now be cleansed.", 12, 3, 100, 0, 0, 0, 1006, 0, "Mull Thunderhorn"),
(2948, 1, 4, "$n, I have created the cleansing totem.", 12, 3, 100, 0, 0, 0, 1007, 0, "Mull Thunderhorn"),
(2948, 1, 5, "The deed is done.  The totem is made.", 12, 3, 100, 0, 0, 0, 1008, 0, "Mull Thunderhorn"),
(2948, 1, 6, "I have created the totem.  You, $n, must cleanse the well.", 12, 3, 100, 0, 0, 0, 1009, 0, "Mull Thunderhorn"),
(2948, 1, 7, "The items you offered were pure, $n.  This new cleansing totem is strong.", 12, 3, 100, 0, 0, 0, 1010, 0, "Mull Thunderhorn");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2948;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2948) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (294800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `COMMENT`) VALUES
(2948, 0, 0, 0, 20, 0, 100, 0, 20440, 0, 0, 0, 80, 294800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mull Thunderhorn - On Quest 'Poison Water' Rewarded - Run Script"),
(2948, 0, 1, 0, 20, 0, 100, 0, 24441, 0, 0, 0, 80, 294800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mull Thunderhorn - On Quest 'Thunderhorn Totem' Rewarded - Run Script"),
(294800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Mull Thunderhorn - On Script - Talk 0"),
(294800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 4983, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Mull Thunderhorn - On Script - Cast 'Create Cleansing Totem"),
(294800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Mull Thunderhorn - On Script - Talk 1");
