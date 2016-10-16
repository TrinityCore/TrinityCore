--
DELETE FROM `quest_template_addon` WHERE `ID`=11272;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(11272, 11234);

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry` IN (24041, 24044);

DELETE FROM `creature_text` WHERE `entry`=23780;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23780, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22662), 14, 0, 100, 0, 0, 0, 22662, 0, "High Executor Anselm"),
(23780, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22663), 14, 0, 100, 0, 0, 0, 22663, 0, "High Executor Anselm"),
(23780, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22686), 12, 0, 100, 0, 0, 0, 22686, 0, "High Executor Anselm"),
(23780, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22687), 14, 0, 100, 0, 0, 0, 22687, 0, "High Executor Anselm");

DELETE FROM `creature_text` WHERE `entry`=24041;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24041, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22665), 12, 0, 100, 0, 0, 0, 22665, 0, "Prince Keleseth"),
(24041, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22669), 12, 0, 100, 0, 0, 0, 22669, 0, "Prince Keleseth"),
(24041, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22671), 12, 0, 100, 0, 0, 0, 22671, 0, "Prince Keleseth"),
(24041, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22722), 12, 0, 100, 0, 0, 0, 22722, 0, "Prince Keleseth"),
(24041, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22723), 12, 0, 100, 0, 0, 0, 22723, 0, "Prince Keleseth"),
(24041, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22758), 12, 0, 100, 0, 0, 0, 22758, 0, "Prince Keleseth"),
(24041, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22766), 12, 0, 100, 0, 0, 0, 22766, 0, "Prince Keleseth"),
(24041, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22764), 12, 0, 100, 0, 0, 0, 22764, 0, "Prince Keleseth");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2378000;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2378000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 1"),
(2378000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 1"),
(2378000, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0"),
(2378000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 2"),
(2378000, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1"),
(2378000, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0 (Prince Keleseth)"),
(2378000, 9, 6, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1 (Prince Keleseth)"),
(2378000, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2 (Prince Keleseth)"),
(2378000, 9, 8, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 3 (Prince Keleseth)"),
(2378000, 9, 9, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 4 (Prince Keleseth)"),
(2378000, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2"),
(2378000, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 5 (Prince Keleseth)"),
(2378000, 9, 15, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 17, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 18, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 19, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 20, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 21, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 2"),
(2378000, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Prince Keleseth"),
(2378000, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Winterskorn Guard"),
(2378000, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Forsaken Crossbow Man");

UPDATE `creature_summon_groups` SET `summonTime`=152000 WHERE `summonerId`=23780;
