--
UPDATE `creature_text` SET `text`=(SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=14447), `BroadcastTextId`=14447 WHERE `entry`=17664 AND `groupid`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=17664;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 4, 17664, 0, 0, 29, 1, 17853, 15, 0, 0, 0, 0, "", "Matis the Cruel must be within 15 yards of Tracker of the Hand in order to execute SAI ID 3");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=31333;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 31333, 0, 0, 29, 0, 17664, 15, 0, 0, 0, 0, "", "Spell Signal Flare can be used within 15 yards of Matis the Cruel");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17664, 17853, 1785300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17664, 0, 0, 1, 38, 0, 100, 512, 1, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Face Tracker of the Hand"),
(17664, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Attack Tracker of the Hand"),
(17664, 0, 3, 4, 2, 0, 100, 0, 0, 50, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Between 0 - 50% HP - Set Data on Tracker of the Hand"),
(17664, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Immune to Player Character"),
(17664, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Invincibility HP"),
(17664, 0, 6, 7, 61, 0, 100, 1, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Disable Auto Attack"),
(17664, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Disable Combat Movement"),
(17664, 0, 8, 9, 61, 0, 100, 1, 2, 2, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Bytes 1"),
(17664, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Say Line 2"),
(17664, 0, 10, 11, 61, 0, 100, 1, 25, 50, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Data 2 2 Tracker of the Hand"),
(17664, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 11, 31336, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Cast Matis Captured DND"),
(17664, 0, 12, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 14000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Despawn after 14 seconds"),

(17853, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17664, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Just Summoned - Face Matis the Cruel"),
(17853, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Just Summoned - Say Line 1"),
(17853, 0, 2, 3, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 17664, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Data Set - Say Line 1 (Matis the Cruel)"),
(17853, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Just Summoned - Set Aggresive"),
(17853, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Just Summoned - Set Data to Matis the Cruel"),
(17853, 0, 5, 0, 61, 0, 100, 1, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Just Summoned - Set Phase 2"),
(17853, 0, 6, 0, 38, 2, 100, 1, 1, 1, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17664, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Data Set 1 1 (Phase 2) - Set Data 2 2 on Matis the Cruel"),
(17853, 0, 7, 0, 38, 0, 100, 1, 2, 2, 0, 0, 80, 1785300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - On Data Set 2 2 - Run Script"),

(1785300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - Script - Disable Auto Attack"),
(1785300, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - Script - Say Line 2"),
(1785300, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tracker of the Hand - Script - Despawn");
