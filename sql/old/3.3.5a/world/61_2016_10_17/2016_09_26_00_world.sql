--
DELETE FROM `creature_text` WHERE `entry`=23963;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23963, 0, 0, "Fire!", 14, 7, 100, 25, 0, 0, 0, 0, "Sergeant Lorric");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23963;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23963;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23963, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sergeant Lorric - OOC - Talk 0");
