-- Update Proto-Drake Handler SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24082;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24082 AND `source_type` = 0 AND `id` IN (4, 5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24082, 0, 4, 0, 0, 0, 100, 2, 5000, 10000, 35000, 40000, 0, 11, 43664, 0, 0, 0, 0, 0, 11, 24083, 0, 1, 0, 0, 0, 0, 0, "Proto-Drake Handler - In Combat - Cast 'Unholy Rage' Target Enslaved Proto-Drake (Normal Dungeon)"),
(24082, 0, 5, 0, 0, 0, 100, 4, 5000, 10000, 35000, 40000, 0, 11, 59694, 0, 0, 0, 0, 0, 11, 24083, 0, 1, 0, 0, 0, 0, 0, "Proto-Drake Handler - In Combat - Cast 'Unholy Rage' Target Enslaved Proto-Drake (Heroic Dungeon)");

-- ConditionTarget thanks @Nyr97
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN (43664, 59694) AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=24083 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 43664, 0, 0, 31, 0, 3, 24083, 0, 0, 0, 0, '', 'Unholy Rage - Target Enslaved Proto-Drake'),
(13, 3, 59694, 0, 0, 31, 0, 3, 24083, 0, 0, 0, 0, '', 'Unholy Rage - Target Enslaved Proto-Drake');
