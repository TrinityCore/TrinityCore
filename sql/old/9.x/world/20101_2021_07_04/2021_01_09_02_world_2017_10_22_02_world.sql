-- 
DELETE FROM `creature_text` WHERE `CreatureID` IN (18175, 18174);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18175, 0, 0, "Matters are so uncertain now that the chamber below is empty...", 12, 1, 100, 1, 0, 0, 14831, 0, "Initiate Emeline"),
(18175, 0, 1, "It's gone. I can't believe it's gone. Who would have thought we'd be betrayed like this?", 12, 1, 100, 1, 0, 0, 14833, 0, "Initiate Emeline"),
(18175, 1, 0, "Our neighbors are positively laughable. Have you seen the way they turn up their noses at us?", 12, 1, 100, 1, 0, 0, 14815, 0, "Initiate Emeline"),
(18175, 1, 1, "The rangers certainly have a high opinion of themselves.", 12, 1, 100, 1, 0, 0, 14818, 0, "Initiate Emeline"),
(18175, 1, 2, "I'm quickly tiring of the haughty attitude I receive from those grubby bowslingers outside.", 12, 1, 100, 1, 0, 0, 14819, 0, "Initiate Emeline"),
(18174, 0, 0, "Lady Liadrin is bound to find a way. She must.", 12, 1, 100, 1, 0, 0, 14838, 0, "Initiate Colin"),
(18174, 0, 1, "Is... it true, what I've heard?  That it was the Sun King himself?", 12, 1, 100, 1, 0, 0, 14839, 0, "Initiate Colin"),
(18174, 0, 2, "Still, the Blood Knights will endure through this loss. We have no other choice... we must find another source.", 12, 1, 100, 1, 0, 0, 14840, 0, "Initiate Colin"),
(18174, 1, 0, "Who do they think they are?", 12, 1, 100, 1, 0, 0, 14820, 0, "Initiate Colin"),
(18174, 1, 1, "I know what you mean... they whisper about us when they think we can't hear them. They'll get theirs.", 12, 1, 100, 1, 0, 0, 14821, 0, "Initiate Colin"),
(18174, 1, 2, "Jealous, that's what they are. They're afraid to dedicate themselves to true power.", 12, 1, 100, 1, 0, 0, 14822, 0, "Initiate Colin"),
(18174, 1, 3, "They simply fear what they cannot begin to understand.", 12, 1, 100, 1, 0, 0, 14823, 0, "Initiate Colin");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18175;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18175, 1817500, 1817501) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18175, 0, 0, 0, 1, 0, 100, 0, 10000, 20000, 30000, 180000, 87, 1817500, 1817501, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Initiate Emeline - Out Of Combat - Run Script"),
(1817500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Initiate Emeline - On Script - Say Line 0"),
(1817500, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 18174, 0, 0, 0, 0, 0, 0, "Initiate Emeline - On Script - Say Line 0 (Initiate Colin)"),
(1817501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Initiate Emeline - On Script - Say Line 1"),
(1817501, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 18174, 0, 0, 0, 0, 0, 0, "Initiate Emeline - On Script - Say Line 1 (Initiate Colin)");
