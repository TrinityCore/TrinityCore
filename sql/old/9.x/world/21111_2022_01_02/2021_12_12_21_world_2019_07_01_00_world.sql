--
DELETE FROM `creature_text` WHERE `CreatureID`=29915;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29915, 0, 0, "You call that fighting? Let me go grab your dolly. Maybe she could teach you how to swing.", 12, 0, 100, 0, 0, 0, 30569, 0, "Instructor Hroegar"),
(29915, 0, 1, "My dead grandmater, rest her soul, could beat you... even now!", 12, 0, 100, 0, 0, 0, 30570, 0, "Instructor Hroegar"),
(29915, 0, 2, "I've half a mind to cut you both down where you stand! The other half isn't arguing!", 12, 0, 100, 0, 0, 0, 30571, 0, "Instructor Hroegar"),
(29915, 0, 3, "Well hello, ladies. What do you think this is... Skorn?", 12, 0, 100, 0, 0, 0, 30572, 0, "Instructor Hroegar"),
(29915, 0, 4, "You will practice until your lungs are bursting and your arms are aching, and then we'll really start!", 12, 0, 100, 0, 0, 0, 30573, 0, "Instructor Hroegar"),
(29915, 0, 5, "Only the best of the best get a shot in Valhalas to go to Ymirheim. Everyone else dies... or worse!", 12, 0, 100, 0, 0, 0, 30574, 0, "Instructor Hroegar"),
(29915, 0, 6, "Stop trying to hit him and HIT HIM already!", 12, 0, 100, 0, 0, 0, 30575, 0, "Instructor Hroegar"),
(29915, 0, 7, "Are you trying to make me look bad? That's the only thing that you're good for today!", 12, 0, 100, 0, 0, 0, 30575, 0, "Instructor Hroegar");

DELETE FROM `smart_scripts` WHERE `entryorguid`=29915 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29915, 0, 0, 0, 1, 0, 100, 0, 10000, 30000, 120000, 240000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Instructor Hroegar - OOC - Say Line 0");
