--
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=27056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26568;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26568, 2656800, 2656801, 2656802, 2656803);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26568, 0, 0, 0, 1, 0, 100, 0, 10000, 20000, 600000, 600000, 87, 2656800, 2656801, 2656802, 2656803, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - Out of Combat - Call random script"),
(2656800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 0"),
(2656800, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26569, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 0 (Alys Vol'tyr)"),
(2656801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 1"),
(2656801, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26569, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 1 (Alys Vol'tyr)"),
(2656801, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 2"),
(2656802, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 3"),
(2656802, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26569, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 2 (Alys Vol'tyr)"),
(2656803, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 4"),
(2656803, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 26569, 0, 0, 0, 0, 0, 0, "Zebu'tan - On Script - Talk 3 (Alys Vol'tyr)");

DELETE FROM `creature_text` WHERE `entry` IN (26568, 26569);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26568, 0, 0, "Don't be shy, elfy. Don't you feel dis burnin' love formin' between us?", 12, 1, 100, 0, 0, 0, 25790, 0, "Zebu'tan"),
(26568, 1, 0, "Lookie what Zebu'tan got for you! Roses for da rose!", 12, 1, 100, 0, 0, 0, 25782, 0, "Zebu'tan"),
(26568, 2, 0, "%s grumbles.", 16, 0, 100, 0, 0, 0, 25783, 0, "Zebu'tan"),
(26568, 3, 0, "Hey pretty lady, Zebu'tan got two rugs over here! Why don't you come on over and keep he warm, eh?", 12, 1, 100, 0, 0, 0, 25781, 0, "Zebu'tan"),
(26568, 4, 0, "Dis troll tink you got a crush on he! Come on over!", 12, 1, 100, 0, 0, 0, 25789, 0, "Zebu'tan"),
(26569, 0, 0, "Get lost, creep!", 12, 1, 100, 0, 0, 0, 25787, 0, "Alys Vol'tyr"),
(26569, 1, 0, "Ewwww!", 12, 1, 100, 0, 0, 0, 25785, 0, "Alys Vol'tyr"),
(26569, 2, 0, "Not if you were the last troll on Azeroth!", 12, 1, 100, 0, 0, 0, 25784, 0, "Alys Vol'tyr"),
(26569, 2, 1, "I've got a man! Now take a hike!", 12, 1, 100, 0, 0, 0, 25788, 0, "Alys Vol'tyr"),
(26569, 3, 0, "Never!", 12, 1, 100, 0, 0, 0, 25786, 0, "Alys Vol'tyr");
