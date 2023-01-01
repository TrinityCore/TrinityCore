--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23732;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23732 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2373200, 2373201) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23732, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Reset - Set Event Phase 1"),
(23732, 0, 1, 0, 1, 1, 100, 0, 3000, 3000, 3000, 3000, 0, 87, 2373200, 2373201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - OOC - Run Random Actionlist (Phase 1)"),
(2373200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set Event Phase 2"),
(2373200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Play Emote 'Eat'"),
(2373200, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Say Line 0"),
(2373200, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Play Emote 'Talk'"),
(2373200, 9, 4, 0, 0, 0, 100, 0, 18000, 27000, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set Event Phase 1"),
(2373201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set Event Phase 2"),
(2373201, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Play Emote 'Laugh'"),
(2373201, 9, 2, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Say Line 1"),
(2373201, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Play Emote 'Yes'"),
(2373201, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Say Line 2"),
(2373201, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set EmoteState 'Dance'"),
(2373201, 9, 6, 0, 0, 0, 100, 0, 40000, 81000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set EmoteState 'None'"),
(2373201, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sorely Twitchblade - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID`=23732;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23732, 0, 0, "That hit the shpot! Gimmie anudder one, Coot! *hic*", 12, 7, 100, 5, 0, 0, 22200, 0, "Sorely Twitchblade"),
(23732, 1, 0, "You're shayin' you wan... you wan... *hic* you wan' me to dansh on dis bar? *hic*", 12, 7, 100, 6, 0, 0, 22201, 0, "Sorely Twitchblade"),
(23732, 2, 0, "Maeshtro! Cue da mushic!", 12, 7, 100, 5, 0, 0, 22202, 0, "Sorely Twitchblade");
