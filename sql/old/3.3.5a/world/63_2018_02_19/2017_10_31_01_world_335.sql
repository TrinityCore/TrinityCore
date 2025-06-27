--
UPDATE `creature_queststarter` SET `id`=11056 WHERE `quest`=5505;
UPDATE `creature_questender` SET `id`=11056 WHERE `quest`=5505;

UPDATE `creature_queststarter` SET `id`=11057 WHERE `quest`=5511;
UPDATE `creature_questender` SET `id`=11057 WHERE `quest`=5511;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11056, 11057) AND `source_type`=0 AND `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1105600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11056, 0, 8, 0, 20, 0, 100, 0, 5803, 0, 0, 0, 80, 1105600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Quest 'Araj's Scarab' Rewarded - Run Script"),
(11057, 0, 8, 0, 20, 0, 100, 0, 5804, 0, 0, 0, 80, 1105600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Quest 'Araj's Scarab' Rewarded - Run Script"),
(1105600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington and Apothecary Dithers - On Quest 'Araj's Scarab' Rewarded - Say Line 0"),
(1105600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington and Apothecary Dithers - On Quest 'Araj's Scarab' Rewarded - Say Line 1"),
(1105600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 15050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington and Apothecary Dithers - On Quest 'Araj's Scarab' Rewarded - Cast 'Psychometry'");

DELETE FROM `creature_text` WHERE `CreatureID` IN (11056, 11057);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11056, 0, 0, "The solution is ready in my cauldron.  It's just the matter of treating both the unfinished key and the scarab.", 12, 0, 100, 0, 0, 0, 7278, 0, "Alchemist Arbington"),
(11056, 1, 0, "It's done $n, and I think you'll be satisfied with the results.", 12, 0, 100, 0, 0, 0, 7279, 0, "Alchemist Arbington"),
(11057, 0, 0, "The solution is ready in my cauldron.  It's just the matter of treating both the unfinished key and the scarab.", 12, 0, 100, 0, 0, 0, 7280, 0, "Apothecary Dithers"),
(11057, 1, 0, "It's done $n, and I think you'll be satisfied with the results.", 12, 0, 100, 0, 0, 0, 7281, 0, "Apothecary Dithers");

UPDATE `quest_offer_reward` SET `RewardText`="Well, here you are, $n - the completed Skeleton Key.  I am certain as I can be that this key will allow you within the confines of the Scholomance.  There's only one way to be absolutely sure it works, though. Waste no time in trying it out, I say.$B$BGood luck, mighty hero.  May your victories continue to bring you fame and power as you lay waste to Scholomance!" WHERE `ID` IN (5505, 5511);
