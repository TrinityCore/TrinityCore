-- 
UPDATE `quest_template_addon` SET `PrevQuestID`=12854 WHERE `ID`=12855;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29650;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29650, 2965000) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29650, 0, 0, 0, 20, 0, 100, 0, 12854, 0, 0, 0, 0, 80, 2965000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Quest 'On Brann's Trail' Rewarded - Run Script"),
(2965000, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Face Invoker"),
(2965000, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Talk 0"),
(2965000, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Talk 1"),
(2965000, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Talk 2"),
(2965000, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Talk 3"),
(2965000, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Script - Restore Orientation");

DELETE FROM `creature_text` WHERE `CreatureID`=29650;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29650, 0, 0, "It's those blasted iron dwarves again! Somehow, they found him before we did.", 12, 7, 100, 1, 0, 0, 30322, 0, "Archaeologist Andorin"),
(29650, 1, 0, "They're not going to give up until they find him. We can't allow that to happen, $n, and Brann knows it.", 12, 7, 100, 1, 0, 0, 30323, 0, "Archaeologist Andorin"),
(29650, 2, 0, "There are some rather cryptic instructions in this note. Brann must've had some kind of backup plan, but he can't keep evading capture forever...", 12, 7, 100, 1, 0, 0, 30324, 0, "Archaeologist Andorin"),
(29650, 3, 0, "It's up to you to find him before the irons do!", 12, 7, 100, 397, 0, 0, 30325, 0, "Archaeologist Andorin");
