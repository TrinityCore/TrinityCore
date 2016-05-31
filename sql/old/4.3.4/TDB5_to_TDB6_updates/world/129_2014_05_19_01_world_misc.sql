--
DELETE FROM `smart_scripts` WHERE `entryorguid`=26737 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26737, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 19, 537133824, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crazed Mana-Surge - On Reset - Remove Unit Flags (UNK_29 / STUNNED / IMMUNE TO NPC / IMMUNE TO PC)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=26737;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 6, 26737, 0, 0, 1, 1, 29266, 0, 0, 1, 0, 0, '', 'Crazed Mana Surge only run SAI if Crazed mana surge does not have aura Permanent Feign Death');
