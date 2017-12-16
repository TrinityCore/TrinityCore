--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18810;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18810;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18810, 0, 0, 0, 1, 0, 100, 0, 120000, 240000, 300000, 420000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Otonambusi - Out of Combat - Talk 0");

DELETE FROM `creature_text` WHERE `entry`=18810;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18810, 0, 0, "How can you have any pudding if you don't eat your fish?", 12, 7, 100, 5, 0, 0, 15941, 0, "Otonambusi"),
(18810, 0, 1, "If you don't eat your fish, you can't have any pudding!", 12, 7, 100, 5, 0, 0, 15942, 0, "Otonambusi");
