DELETE FROM `smart_scripts` WHERE `entryorguid`=202443 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20244300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(202443, 1, 0, 1, 64, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dedication of Honor - On Gossip Hello - Store Targetlist'),
(202443, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 20244300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dedication of Honor - On Gossip Hello - Run Script'),
(202443, 1, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 151164, 202616, 0, 0, 0, 0, 0, 'Dedication of Honor - OOC - Activate Go (No Repeat)'),
(20244300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 68, 16, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Dedication of Honor - On Script - Play Movie 16');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=202443 and `SourceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 202443, 1, 0, 17, 0, 4530, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has  achievement'),
(22, 1, 202443, 1, 1, 17, 0, 4597, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has  achievement'),
(22, 3, 202443, 1, 0, 40, 1, 4576, 0, 0, 0, 0, 0, '', 'Only run SAI if realm first rewarded');
UPDATE `gameobject` SET `state`=1 WHERE  `guid`=151164;
UPDATE `gameobject_template` SET `flags`=32 WHERE  `entry`=202616;
