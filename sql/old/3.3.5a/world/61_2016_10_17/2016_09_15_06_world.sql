--
DELETE FROM `creature_text` WHERE `entry`=24371;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24371, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=23530), 14, 0, 100, 0, 0, 0, 23530, 0, "Megalith");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24371;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24371;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24371, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 15000, 20000, 11, 50084, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Megalith - In Combat - Cast 'Hulking Uppercut'"),
(24371, 0, 1, 0, 0, 0, 100, 0, 0, 1000, 5000, 5000, 11, 50086, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Megalith - In Combat - Cast 'Boulder'"),
(24371, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Megalith - On Death - Say Line 1");
