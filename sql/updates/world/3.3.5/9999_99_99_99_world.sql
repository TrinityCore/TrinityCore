-- Greengill Slave
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 25084;

-- These are reordered from c++-script so that conditions will work on linked events properly.
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 25084);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25084, 0, 0, 1, 61, 0, 100, 0, 0, 0, 0, 0, 11, 45111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greengill Slave - On Spellhit \'Orb of Murloc Control\' - Cast \'Enrage\''),
(25084, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 123, 100000, 0, 0, 0, 0, 0, 19, 25060, 70, 0, 0, 0, 0, 0, 'Greengill Slave - On Spellhit \'Orb of Murloc Control\' - Add 100000 Threat to nearest Darkspine Myrmidon'),
(25084, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 25060, 70, 0, 0, 0, 0, 0, 'Greengill Slave - On Spellhit \'Orb of Murloc Control\' - Start Attacking nearest Darkspine Myrmidon'),
(25084, 0, 3, 0, 8, 0, 100, 0, 45109, 0, 0, 0, 11, 45110, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greengill Slave - On Spellhit \'Orb of Murloc Control\' - Cast \'Greengill Slave Freed\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25084
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 4, 25084, 0, 0, 9, 0, 11541, 0, 0, 0, 0, 0, '', 'Smart event 3 for Greengill Slave will execute if quest Disrupt the Greengill Coast has been taken.'),
(22, 1, 25084, 0, 0, 1, 1, 45111, 1, 0, 1, 0, 0, '', 'Smart event 0 for Greengill Slave will execute if creature does not have aura Enrage.');
