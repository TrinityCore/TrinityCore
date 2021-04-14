-- No Tanks! (26333) quest script
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 79751; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 79751, 0, 0, 31, 1, 3, 42224, 0, 0, 0, 0, '', 'Destroy Mechano-Tank can target only Repaired Mechano-Tank');
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42224;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42224;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42224, 0, 0, 1, 8, 0, 100, 1, 79751, 0, 0, 0, 33, 42224, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Repaired Mechano-Tank - on spell hit (79751) - give quest credit (42224)'),
(42224, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 80476, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Repaired Mechano-Tank - linked - cast spell (80476)'),
(42224, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Repaired Mechano-Tank - linked - die'),
(42224, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Repaired Mechano-Tank - linked - despawn after 3 seconds');
