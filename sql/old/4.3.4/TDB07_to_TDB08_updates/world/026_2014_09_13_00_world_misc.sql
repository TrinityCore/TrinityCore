DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(31606,47190);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(31606, 31746, 0, 'Stormcrow Amulet triggers Stormcrow Shape'),
(47190, 47189, 1, 'Toaluus Spiritual Incense triggers Spiritual Insight');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry` IN(26595,17841);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(26595,17841) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26595, 0, 0, 0, 10, 0, 100, 0, 1, 30, 10, 10, 28, 47189, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Toaluu the Mystic - Out of Combat - Remove Aura Spiritual Insight'),
(17841, 0, 0, 0, 10, 0, 100, 0, 1, 30, 10, 10, 28, 31746, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ysiel Windsinger - Out of Combat - Remove Aura Stormcrow Shape');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(26595,17841);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 26595, 0, 0, 28, 0, 12028, 0, 0, 0, 0, 0, '', 'Only run SAI if Player Has Spiritual Insight Complete in Log'),
(22, 1, 26595, 0, 0, 1, 0, 47189, 0, 0, 0, 0, 0, '', 'Only run SAI if Player Has Aura Spiritual Insight'),
(22, 1, 17841, 0, 0, 28, 0, 9718, 0, 0, 0, 0, 0, '', 'Only run SAI if Player Has As The Crow Flies Complete in Log'),
(22, 1, 17841, 0, 0, 1, 0, 31746, 0, 0, 0, 0, 0, '', 'Only run SAI if Player Has Aura Stormcrow Shape');
