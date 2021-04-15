-- Mustering the Reds
DELETE FROM `creature_text` WHERE `CreatureID`=26206;
DELETE FROM `creature_text` WHERE `CreatureID`=26117 AND `GroupID` BETWEEN 2 AND 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26206, 0, 0, "Raelorasz, it is good to see you again.", 12, 0, 100, 2, 0, 0, 25463, 0, "Keristrasza"),
(26206, 1, 0, "Fate, it seems, has been more than kind. A blow has been dealt to Malygos. When he learns of it, I am confident he will leave the safety of the Nexus.", 12, 0, 100, 1, 0, 0, 25466, 0, "Keristrasza"),
(26206, 2, 0, "Prepare them well, Raelorasz. Malygos' power is like nothing they've seen. We will likely only delay his plans with this diversion.", 12, 0, 100, 1, 0, 0, 25469, 0, "Keristrasza"),
(26206, 3, 0, "Farewell, Raelorasz.", 12, 0, 100, 1, 0, 0, 25472, 0, "Keristrasza"),
(26117, 2, 0, "Keristrasza! I wish that circumstances allowed for a more fitting welcome. Fate has been kind to return you to us.", 12, 0, 100, 5, 0, 0, 25464, 0, "Raelorasz"),
(26117, 3, 0, "Malygos - in the open? I hadn't dared hope for an opportunity such as this. I'll assemble our bretheren at once!", 12, 0, 100, 1, 0, 0, 25467, 0, "Raelorasz"),
(26117, 4, 0, "Of course, my lady. Until we meet again...", 12, 0, 100, 1, 0, 0, 25468, 0, "Raelorasz");

DELETE FROM `smart_scripts` WHERE `entryorguid`=26117 AND `source_type`=0 AND `id` IN (3, 4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=26206 AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2620600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26117, 0, 3, 0, 20, 0, 100, 0, 11967, 0, 0, 0, 12, 26206, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 3579.6333, 6653.4771, 195.5151, 3.4422, "Raelorasz - On Quest 'Mustering the Reds' Rewarded - Summon NPC Keristrasza"),
(26117, 0, 4, 0, 17, 0, 100, 0, 26206, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Raelorasz - On NPC 'Keristrasza' Summoned - Set Data 1 1 To Invoker"),
(26206, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2620600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Data 1 1 Set - Run Script"),
(2620600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Remove Gossip+QuestGiver Flag"),
(2620600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Set Run Off"),
(2620600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Cast Spell 'Teleport Visual Only'"),
(2620600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3572.7424, 6651.2246, 195.1808, 0, "Keristrasza - On Script - Move To Pos"),
(2620600, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 0"),
(2620600, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26117, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 2 (Raelorasz)"),
(2620600, 9, 6, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 1"),
(2620600, 9, 7, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 26117, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 3 (Raelorasz)"),
(2620600, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 2"),
(2620600, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 26117, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 4 (Raelorasz)"),
(2620600, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Say Line 3"),
(2620600, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3582.6934, 6632.1885, 195.1749, 0, "Keristrasza - On Script - Move To Pos"),
(2620600, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 9000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Keristrasza - On Script - Despawn In 9 Seconds");
