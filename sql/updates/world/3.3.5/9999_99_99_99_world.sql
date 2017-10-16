-- Ragged John
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 9563;

DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 9563);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9563, 0, 0, 1, 10, 0, 100, 0, 0, 15, 0, 0, 11, 16472, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ragged John - Within 0-15 Range Out of Combat LoS - Cast \'Wicked Milking\''),
(9563, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, 4866, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ragged John - Within 0-15 Range Out of Combat LoS - Quest Credit \'undefined\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = 9563 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 9563, 0, 0, 1, 0, 16468, 1, 0, 0, 0, 0, '', 'SAI event 0 for Ragged John will execute if target has aura Mother\'s Milk.'),
(22, 1, 9563, 0, 0, 32, 0, 16, 0, 0, 0, 0, 0, '', 'SAI event 0 for Ragged John will execute if target is player.');
