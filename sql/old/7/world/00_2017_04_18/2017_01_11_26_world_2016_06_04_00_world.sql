UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=6556;

DELETE FROM `smart_scripts` WHERE `entryorguid`=6556 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6557 AND `source_type`=0 AND `id`=7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6559 AND `source_type`=0 AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(6556, 0, 0, 0, 8, 0, 100, 1, 15702, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muculent Ooze - On Spell Hit (Filling Empty Jar) - Despawn'),
(6557, 0, 7, 0, 8, 0, 100, 1, 15702, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Primal Ooze - On Spell Hit (Filling Empty Jar) - Despawn'),
(6559, 0, 1, 0, 8, 0, 100, 1, 15702, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glutinous Ooze - On Spell Hit (Filling Empty Jar) - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=15702;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 15702, 0, 0, 31, 1, 3, 6556, 0, 0, 0, 0, '', 'Filling Empty Jar can be used on Muculent Ooze'),
(17, 0, 15702, 0, 1, 31, 1, 3, 6557, 0, 0, 0, 0, '', 'Filling Empty Jar can be used on Muculent Ooze'),
(17, 0, 15702, 0, 2, 31, 1, 3, 6559, 0, 0, 0, 0, '', 'Filling Empty Jar can be used on Muculent Ooze'),
(17, 0, 15702, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target must be dead'),
(17, 0, 15702, 0, 1, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target must be dead'),
(17, 0, 15702, 0, 2, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target must be dead');
