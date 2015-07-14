--
DELETE FROM `spell_scripts` WHERE `id`=38173;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(38173, 0, 0, 10, 22023, 12000, 0, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (38173);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,38173,0,0, 31,0,3,22160,0,0,0,'','Summon Spirit require Bloodmaul Taskmaster'),
(13,1,38173,0,0, 29,0,22384,15,0,0,0,'','Summon Spirit if Bloodmaul Soothsayer is around');

UPDATE `creature_template` SET `flags_extra`=2, `AIName`='SmartAI' WHERE `Entry`=22023;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22023 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2202300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22023, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2202300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit  - Just summoned - action list'),
(2202300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 22160, 50, 0, 0, 0, 0, 0, 'Spirit  - action list - move to pos'),
(2202300, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spirit  - action list - move to pos'),
(2202300, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 85, 39074, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spirit  - action list - Cast credit spell');

DELETE FROM `smart_scripts` WHERE `entryorguid`=22160 AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22384 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22160, 0, 4, 0, 1, 0, 100, 0, 5000, 5000, 3000, 5000, 10, 1, 11, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodmaul Taskmaster - Out of Combat - play random emotes'),
(22384, 0, 6, 0, 1, 0, 100, 0, 5000, 5000, 3000, 5000, 10, 1, 11, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodmaul Soothsayer - Out of Combat - play random emotes');
