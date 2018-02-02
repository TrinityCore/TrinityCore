-- 
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (164871, 175080, 176495, 181689, 186238);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (164871, 175080, 176495, 181689, 186238, 17508000, 17649500) AND `source_type` IN (1, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(175080, 1, 0, 0, 71, 0, 100, 0, 15322, 0, 0, 0, 80, 17508000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Iron Eagle - On Event 15322 Inform - Run Script"),
(17508000, 9, 0, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 12136, 100, 0, 0, 0, 0, 0, "The Iron Eagle - On Script - Say Line 0 (Snurk Bucksquick)"),
(175080, 1, 1, 0, 71, 0, 100, 0, 15324, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3149, 100, 0, 0, 0, 0, 0, "The Iron Eagle - On Event 15324 Inform - Say Line 0 (Nez'raz)"),
(164871, 1, 0, 0, 71, 0, 100, 0, 15318, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 9564, 100, 0, 0, 0, 0, 0, "The Thundercaller - On Event 15318 Inform - Say Line 0 (Frezza)"),
(164871, 1, 1, 0, 71, 0, 100, 0, 15320, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 9566, 100, 0, 0, 0, 0, 0, "The Thundercaller - On Event 15320 Inform - Say Line 0 (Zapetta)"),
(176495, 1, 1, 0, 71, 0, 100, 0, 15312, 0, 0, 0, 80, 17649500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Purple Princess - On Event 15312 Inform - Run Script"),
(17649500, 9, 0, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3150, 100, 0, 0, 0, 0, 0, "The Purple Princess - On Script - Say Line 0 (Squibby Overspeck)"),
(176495, 1, 0, 0, 71, 0, 100, 0, 15314, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 12137, 100, 0, 0, 0, 0, 0, "The Purple Princess - On Event 15314 Inform - Say Line 0 (Hin Denburg)"),
(181689, 1, 0, 0, 71, 0, 100, 0, 19126, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26540, 100, 0, 0, 0, 0, 0, "Cloudkisser - On Event 19126 Inform - Say Line 0 (Drenk Spannerspark)"),
(181689, 1, 1, 0, 71, 0, 100, 0, 19127, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26539, 100, 0, 0, 0, 0, 0, "Cloudkisser - On Event 19127 Inform - Say Line 0 (Meefi Farthrottle)"),
(186238, 1, 0, 0, 71, 0, 100, 0, 19137, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26537, 100, 0, 0, 0, 0, 0, "The Mighty Wind - On Event 19137 Inform - Say Line 0 (Greeb Ramrocket)"),
(186238, 1, 1, 0, 71, 0, 100, 0, 19139, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26538, 100, 0, 0, 0, 0, 0, "The Mighty Wind - On Event 19139 Inform - Say Line 0 (Nargo Screwbore)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (3149, 3150, 9566, 12137, 26539, 26540, 26538);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3149, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", 14, 0, 100, 0, 0, 0, 29551, 0, "Nez'raz"),
(3150, 0, 0, "The zeppelin to Grom'gol has just arrived! All aboard for Stranglethorn!", 14, 0, 100, 0, 0, 0, 22097, 0, "Hin Denburg"),
(9566, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", 14, 0, 100, 0, 0, 0, 29551, 0, "Zapetta"),
(12137, 0, 0, "The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!", 14, 0, 100, 0, 0, 0, 29545, 0, "Squibby Overspeck"),
(26539, 0, 0, "The zeppelin to Vengeance Landing has just arrived! All aboard for Howling Fjord!", 14, 0, 100, 0, 0, 0, 29540, 0, "Meefi Farthrottle"),
(26540, 0, 0, "The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!", 14, 0, 100, 0, 0, 0, 29545, 0, "Drenk Spannerspark"),
(26538, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", 14, 0, 100, 0, 0, 0, 29551, 0, "Nargo Screwbore");

UPDATE `creature_template` SET `gossip_menu_id`=2441 WHERE `entry`=3149;
UPDATE `creature_template` SET `gossip_menu_id`=3842 WHERE `entry`=12137;
