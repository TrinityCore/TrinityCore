DELETE FROM `creature_text` WHERE `CreatureID`=17282;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17282, 0, 0, "We're never going to fire one of these, are we?", 12, 1, 100, 0, 0, 0, 19346, 0, "Falcon Watch Ranger"),
(17282, 0, 1, "Do we even have ammunition for these?", 12, 1, 100, 0, 0, 0, 19347, 0, "Falcon Watch Ranger"),
(17282, 0, 2, "What, exactly, are we ever going to fire these at?", 12, 1, 100, 0, 0, 0, 19348, 0, "Falcon Watch Ranger"),
(17282, 0, 3, "I wonder how far this would launch that white cat...", 12, 1, 100, 0, 0, 0, 19349, 0, "Falcon Watch Ranger");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17282;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-62073, -62075) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-62073, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 120000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Falcon Watch Ranger - Out Of Combat - Talk"),
(-62075, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 120000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Falcon Watch Ranger - Out Of Combat - Talk");
