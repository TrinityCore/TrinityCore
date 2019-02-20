UPDATE `creature_template` SET `InhabitType`=4, `AIName`="SmartAI" WHERE `entry`=24168;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24168 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24168, 0, 0, 0, 1, 0, 100, 0, 30000, 120000, 120000, 180000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Micah Stonebreaker - OOC - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=24168;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24168, 0, 0, "AGH! Not again with the sprayin'!", 12, 6, 100, 0, 0, 0, 22869, 0, "Micah Stonebreaker"),
(24168, 0, 1, "What's that n- AGH!", 12, 6, 100, 0, 0, 0, 22870, 0, "Micah Stonebreaker"),
(24168, 0, 2, "Brann's beard, just STOP!", 12, 6, 100, 0, 0, 0, 22871, 0, "Micah Stonebreaker"),
(24168, 0, 3, "The dwarf coughs, sputters, and shivers in the cage.", 16, 0, 100, 0, 0, 0, 22872, 0, "Micah Stonebreaker"),
(24168, 0, 4, "A low, despairing moan escapes the caged dwarf.", 16, 0, 100, 0, 0, 0, 22873, 0, "Micah Stonebreaker"),
(24168, 0, 5, "%s shakes the bars of the cage weakly.", 16, 0, 100, 0, 0, 0, 22874, 0, "Micah Stonebreaker"),
(24168, 0, 6, "%s slumps against the cage bars dejectedly.", 16, 0, 100, 0, 0, 0, 22875, 0, "Micah Stonebreaker");
