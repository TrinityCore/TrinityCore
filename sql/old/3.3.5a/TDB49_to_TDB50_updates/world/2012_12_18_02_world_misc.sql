UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=15760;

DELETE FROM `smart_scripts` WHERE `entryorguid`=15760 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15760, 0, 0, 0, 22, 0, 100, 0, 58, 0, 0, 0, 11, 26218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Winter Reveler - Cast Mistletoe on /kiss');

DELETE FROM `spell_script_names` WHERE `spell_id`=26218;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(26218,'spell_winter_veil_mistletoe');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=15760;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 15760, 0, 0, 1, 0, 26218, 1, 0, 1, 0, 0, '', 'execute sai only if player has not Mistletoe Debuff'),
(22, 1, 15760, 0, 0, 12, 0, 2, 0, 0, 0, 0, 0, '', 'execute sai only if Winter Veil');
