-- Out of combat texts for NPC Ranger Lethvalin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16213;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16213 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16213, 0, 0, 0, 1, 0, 100, 0, 20000, 40000, 590000, 620000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ranger Lethvalin - Out Of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=16213;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16213, 0, 0, "%s taps his foot impatiently.", 16, 0, 100, 0, 0, 0, 12590, 0, "Ranger Lethvalin"),
(16213, 0, 1, "%s glares at the guards.", 16, 0, 100, 0, 0, 0, 12591, 0, "Ranger Lethvalin"),
(16213, 0, 2, "%s sighs in apparent frustration.", 16, 0, 100, 0, 0, 0, 12592, 0, "Ranger Lethvalin"),
(16213, 0, 3, "%s peers inside the tower and then clenches his jaw.", 16, 0, 100, 0, 0, 0, 12593, 0, "Ranger Lethvalin");
