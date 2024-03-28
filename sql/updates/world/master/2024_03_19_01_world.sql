-- Areatrigger 7746
DELETE FROM `areatrigger_scripts` WHERE `entry`=7746;
INSERT INTO `areatrigger_scripts` VALUES
(7746, 'SmartTrigger');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=7746;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7746, 2, 0, 9, 0, 29409,  0, 0, 0, 0, 0, '', 'Areatrigger 7746 only triggers when quest 29409 is taken'),
(22, 1, 7746, 2, 0, 1, 0, 116219, 0, 0, 1, 0, 0, '', 'Areatrigger 7746 only triggers when player has not aura 116219');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`= 6018300;

DELETE FROM `smart_scripts` WHERE `entryorguid`=7746 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7746, 2, 0, 0, 46, 0, 100, 0, 7746, 0, 0, 0, 0, '', 86, 116219, 2, 10, 450138, 60183, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura A');

DELETE FROM `smart_scripts` WHERE `entryorguid`=60183 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60183, 0, 0, 0, 31, 0, 100, 0, 116219, 0, 1000, 1000, 0, '', 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Trainee Nim - On Spellhit Target - Talk');

-- Areatrigger 7747
DELETE FROM `areatrigger_scripts` WHERE `entry`=7747;
INSERT INTO `areatrigger_scripts` VALUES
(7747, 'SmartTrigger');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=7747;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7747, 2, 0, 28, 0, 29410, 0, 0, 0, 0, 0, '', 'Areatrigger 7746 only triggers when quest 29410 is completed'),
(22, 1, 7747, 2, 0, 1, 0, 116220, 0, 0, 1, 0, 0, '', 'Areatrigger 7746 only triggers when player has not aura 116220');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`= 6024400;

DELETE FROM `smart_scripts` WHERE `entryorguid`=7747 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7747, 2, 0, 0, 46, 0, 100, 0, 7747, 0, 0, 0, 0, '', 86, 116220, 2, 10, 450099, 60244, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura B');

DELETE FROM `smart_scripts` WHERE `entryorguid`=60244 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60244, 0, 0, 0, 31, 0, 100, 0, 116220, 0, 1000, 1000, 0, '', 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Trainee Guang - On Spellhit Target - Talk');
