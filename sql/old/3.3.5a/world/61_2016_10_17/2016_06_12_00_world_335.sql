-- 
SET @Entry := 17093;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Entry;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Entry, @Entry*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Entry    , 0, 0, 0, 20, 0, 100, 0, 9434, 0, 0, 0, 80, @Entry*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Quest \"Testing the Tonic\" rewarded - Run script"),
(@Entry*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Remove questgiver flag"),
(@Entry*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Talk (0)"),
(@Entry*100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 60888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - cast cosmetic emote"),
(@Entry*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Talk (1)"),
(@Entry*100, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Talk (2)"),
(@Entry*100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Change emote state"),
(@Entry*100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 3, 17162, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Change model"),
(@Entry*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Talk (3)"),
(@Entry*100, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Talk (4)"),
(@Entry*100, 9, 9, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 3, 17093, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Change Entry"),
(@Entry*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Change emote state"),
(@Entry*100, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Elosai - On Script - Add questgiver flag");

DELETE FROM `creature_text` WHERE `entry`=@Entry;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Entry, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=13508), 16, 0, 100, 0, 0, 0, 13508, 0, ""),
(@Entry, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=13509), 12, 0, 100, 7, 0, 0, 13509, 0, ""),
(@Entry, 2, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=13510), 12, 0, 100, 0, 0, 0, 13510, 0, ""),
(@Entry, 3, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=13511), 12, 0, 100, 0, 0, 0, 13511, 0, ""),
(@Entry, 4, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=14318), 12, 0, 100, 0, 0, 0, 14318, 0, "");
