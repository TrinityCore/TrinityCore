--
DELETE FROM `quest_template_addon` WHERE `ID`=919;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(919, 997);

UPDATE quest_offer_reward SET `RewardText`="Ah, it's here! I have waited for this rare earth for quite some time. I hope it's still fresh...$b$bThank you for bringing it to me, $N. You are a $R who is generous with $Ghis:her; time." WHERE `ID`=997;

UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid`=2080 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2080 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2080, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Quest Finished - Set Run Off");

DELETE FROM `smart_scripts` WHERE `entryorguid`=208000;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(208000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Remove Npc Flag Questgiver"),
(208000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 0"),
(208000, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9508.02, 715.749, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208000, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9507.66, 718.009, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208000, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9505.56, 719.088, 1256.2, 0, "Denalan - On Script - Move To Position"),
(208000, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Play Emote 16"),
(208000, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Set Orientation to Invoker"),
(208000, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 1"),
(208000, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9506.9199, 713.7660, 1255.89, 0, "Denalan - Script - Move"),
(208000, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Reset Orientation"),
(208000, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Add Npc Flag Questgiver");

DELETE FROM `smart_scripts` WHERE `entryorguid`=208001;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(208001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Remove Npc Flag Questgiver"),
(208001, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 2"),
(208001, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9508.02, 715.749, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208001, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9507.66, 718.009, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208001, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9505.56, 719.088, 1256.2, 0, "Denalan - On Script - Move To Position"),
(208001, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Play Emote 16"),
(208001, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 3"),
(208001, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9506.9199, 713.7660, 1255.89, 0, "Denalan - Script - Move"),
(208001, 9, 8, 0, 0, 0, 100, 0, 500, 500, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 67984, 7510, 0, 0, 0, 0, 0, "Denalan - On Script - Respawn Closest Gameobject 'Sprouted Frond'"),
(208001, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 42936, 7510, 0, 0, 0, 0, 0, "Denalan - On Script - Respawn Closest Gameobject 'Sprouted Frond'"),
(208001, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 30276, 7510, 0, 0, 0, 0, 0, "Denalan - On Script - Respawn Closest Gameobject 'Sprouted Frond'"),
(208001, 9, 11, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Reset Orientation"),
(208001, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Add Npc Flag Questgiver");

DELETE FROM `smart_scripts` WHERE `entryorguid`=208002;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(208002, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Remove Npc Flag Questgiver"),
(208002, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 4"),
(208002, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 5"),
(208002, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9508.02, 715.749, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208002, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9507.66, 718.009, 1255.89, 0, "Denalan - On Script - Move To Position"),
(208002, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9505.56, 719.088, 1256.2, 0, "Denalan - On Script - Move To Position"),
(208002, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Play Emote 16"),
(208002, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 6"),
(208002, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 12, 3569, 3, 20000, 0, 0, 0, 8, 0, 0, 0, 9505.13, 722.011, 1255.94, 0.0244875, "Denalan - On Script - Summon Creature 'Bogling'"),
(208002, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 3569, 3, 20000, 0, 0, 0, 8, 0, 0, 0, 9504.09, 720.294, 1255.94, 1.00709, "Denalan - On Script - Summon Creature 'Bogling'"),
(208002, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 3569, 3, 20000, 0, 0, 0, 8, 0, 0, 0, 9504.13, 721.459, 1255.94, 6.24727, "Denalan - On Script - Summon Creature 'Bogling'"),
(208002, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 3569, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 1 (Bogling)"),
(208002, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 9506.9199, 713.7660, 1255.89, 0, "Denalan - Script - Move"),
(208002, 9, 13, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Reset Orientation"),
(208002, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=2080 AND `groupid`=7;
DELETE FROM `creature_text` WHERE `entry`=3569 AND `groupid`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3569, 1, 0, "%s rises from the soil!", 16, 0, 100, 1, 0, 0, 1174, 0, "Bogling");

UPDATE `creature_text` SET `type`=16, `emote`=0 WHERE `entry`=2080 AND `groupid` IN (2, 4, 6);

UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=3569;
