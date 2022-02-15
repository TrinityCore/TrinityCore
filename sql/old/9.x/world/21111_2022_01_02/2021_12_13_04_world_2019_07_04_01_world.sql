--
DELETE FROM `creature_template_addon` WHERE `entry`=24525;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(24525, 0, 0, 0, 0, 10, "");

UPDATE `creature_template` SET AIName="SmartAI" WHERE `entry`=26531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26531 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24525 AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2452500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`,`action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26531, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.52819, "Mesmerized Frog - On Data 1 1 Set - Set Orientation"),
(24525, 0, 1, 0, 1, 0, 100, 0, 30000, 60000, 300000, 600000, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - OOC - Talk 2"),
(2452500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Remove Npcflag Gossip+Questgiver"),
(2452500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Set EmoteState 0"),
(2452500, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 26531, 1, 16000, 0, 0, 0, 8, 0, 0, 0, 0, -133.458, -3545.55, 2.89468, 4.5204, "Zeh'gehn - On Script - Spawn Mesmerized Frog"),
(2452500, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Say Line 1"),
(2452500, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26531, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Say Line 1 (Mesmerized Frog)"),
(2452500, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26531, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Set Data 1 1 (Mesmerized Frog)"),
(2452500, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26531, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Say Line 2 (Mesmerized Frog)"),
(2452500, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Say Line 2"),
(2452500, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Set EmoteState Dance"),
(2452500, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zeh'gehn - On Script - Add Npcflag Gossip+Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=24525 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24525, 2, 0, "Watch nah, ye bogfiddler!  I an' I gunna show ye 'ow a jig meant fe be jigged to!", 12, 0, 100, 0, 0, 0, 23580, 0, "Zeh'gehn"),
(24525, 2, 1, "Yah, me bredren!  Galang now and pass us a grog, just dead men yahso.", 12, 0, 100, 0, 0, 0, 23579, 0, "Zeh'gehn"),
(24525, 2, 2, "Yarrrr, mon!", 12, 0, 100, 0, 0, 0, 23849, 0, "Zeh'gehn");
