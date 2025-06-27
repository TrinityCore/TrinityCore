-- Quest "The Corrupter (Part 3)" --> Completion Event
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=2 WHERE `entry`=4498;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|898 WHERE `entry` IN (5773,5772);
DELETE FROM `smart_scripts` WHERE `source_type` IN (0, 9) AND `entryorguid` IN (4498, 449800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4498, 0, 0, 0, 20, 0, 100, 0, 1482, 0, 0, 0, 80, 449800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Quest 'The Corruptor' Rewarded - Remove npc flag"),
(449800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 0"),
(449800, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 0"),
(449800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 1"),
(449800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 7960, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Cast 'Scry on Azrethoc'"),
(449800, 9, 4, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 12, 5773, 1, 24000, 0, 0, 0, 8, 0, 0, 0, -1152.9536, 1887.8666, 88.8724, 5.4946, "Maurin Bonesplitter - On Script - Summon Jugkar Grim'rod's Image"),
(449800, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 90, 0, 0, 0, 0, 0, 19, 5773, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Set Faction To 90 (Jugkar Grim'rod's Image)"),
(449800, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 86, 51347, 0, 19, 5773, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Maurin Bonesplitter - On Script - Cross Cast 'Teleport Visual Only'"),
(449800, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 5773, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 0 (Jugkar Grim'rod's Image)"),
(449800, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 12, 5772, 1, 16000, 0, 0, 0, 8, 0, 0, 0, -1154.3765, 1892.2039, 88.8710, 5.1961, "Maurin Bonesplitter - On Script - Summon Lord Azrethoc's Image"),
(449800, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 5772, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 0 (Lord Azrethoc's Image)"),
(449800, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 5772, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 1 (Lord Azrethoc's Image)"),
(449800, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 86, 7961, 0, 19, 5772, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Crosscast Spell 'Azrethoc's Stomp' (Lord Azrethoc's Image)"),
(449800, 9, 12, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 5772, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 2 (Lord Azrethoc's Image)"),
(449800, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 5773, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 1 (Jugkar Grim'rod's Image)"),
(449800, 9, 14, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - Talk 2"),
(449800, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maurin Bonesplitter - On Script - add npc flag");
DELETE FROM `creature_text` WHERE `CreatureID` IN (4498, 5773, 5772);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4498, 0, 0, "This should only take a moment, $n.", 12, 1, 100, 1, 0, 0, 2085, 0, "Maurin Bonesplitter"),
(4498, 1, 0, "I call your true name, Azrethoc. Show your visage to me!", 12, 8, 100, 22, 0, 0, 2087, 0, "Maurin Bonesplitter"),
(4498, 2, 0, "An interesting turning of events.", 12, 1, 100, 6, 0, 0, 2094, 0, "Maurin Bonesplitter"),
(5773, 0, 0, "Pathetic Forsaken weakling. You wish to see my master? So be it.", 12, 1, 100, 25, 0, 0, 2089, 0, "Jugkar Grim'rod's Image"),
(5773, 1, 0, "Yes, come. My master and I shall be waiting.", 12, 1, 100, 273, 0, 0, 2093, 0, "Jugkar Grim'rod's Image"),
(5772, 0, 0, "Who dares to seek me out?!", 14, 8, 100, 15, 0, 0, 2090, 0, "Lord Azrethoc's Image"),
(5772, 1, 0, "Insects!", 14, 8, 100, 0, 0, 0, 2091, 0, "Lord Azrethoc's Image"),
(5772, 2, 0, "Come! Come to your deaths--if you dare!", 14, 8, 100, 396, 0, 0, 2092, 0, "Lord Azrethoc's Image");
