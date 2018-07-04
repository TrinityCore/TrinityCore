--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=17664;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 17664, 0, 0, 29, 1, 17853, 15, 0, 0, 0, 0, "", "Matis the Cruel must be within 15 yards of Tracker of the Hand in order to execute SAI ID 2");

DELETE FROM `smart_scripts` WHERE `entryorguid`=17664;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17664, 0, 0, 1, 38, 0, 100, 512, 1, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Face Tracker of the Hand"),
(17664, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Attack Tracker of the Hand"),
(17664, 0, 2, 3, 2, 0, 100, 0, 0, 50, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Between 0 - 50% HP - Set Data on Tracker of the Hand"),
(17664, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Immune to Player Character"),
(17664, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Invincibility HP"),
(17664, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Disable Auto Attack"),
(17664, 0, 6, 7, 61, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Disable Combat Movement"),
(17664, 0, 7, 8, 61, 0, 100, 1, 2, 2, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Bytes 1"),
(17664, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Say Line 2"),
(17664, 0, 9, 10, 61, 0, 100, 1, 25, 50, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Set Data 2 2 Tracker of the Hand"),
(17664, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 31336, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Cast Matis Captured DND"),
(17664, 0, 11, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 14000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Matis the Cruel - On Data Set - Despawn after 14 seconds");
