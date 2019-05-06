-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=16880 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16880, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 33908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hulking Helboar - On Reset - Cast 'Burning Spikes'"),
(16880, 0, 1, 0, 2, 0, 100, 1, 34, 66, 0, 0, 11, 33909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hulking Helboar - Between 34-66% Health - Cast 'Hulk' (No Repeat)"),
(16880, 0, 2, 0, 2, 0, 100, 1, 1, 66, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hulking Helboar - Between 1-66% Health - Say Line 0 (No Repeat)"),
(16880, 0, 3, 0, 2, 0, 100, 1, 1, 33, 0, 0, 11, 33909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hulking Helboar - Between 1-33% Health - Cast 'Hulk' (No Repeat)"),
(16880, 0, 4, 0, 8, 0, 100, 1, 34665, 0, 0, 0, 33, 16992, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Hulking Helboar - On Spellhit 'Administer Antidote' - Quest Credit 'Testing the Antidote' (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (16880, 16992);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16880, 0, 0, "%s begins to grow stronger.", 16, 0, 100, 0, 0, 0, 16646, 0, "Hulking Helboar"),
(16992, 0, 0, "%s begins to grow stronger.", 16, 0, 100, 0, 0, 0, 16646, 0, "Dreadtusk");
