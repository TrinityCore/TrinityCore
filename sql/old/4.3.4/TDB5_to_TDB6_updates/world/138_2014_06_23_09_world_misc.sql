--
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=185928;

DELETE FROM `smart_scripts` WHERE `entryorguid`=185928 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185928, 1, 0, 1, 62, 0, 100, 0, 8687, 0, 0, 0, 85, 41004, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Skull Pile - On Gossip Option 0 Selected - Invoker Cast Summon Terokk'),
(185928, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Skull Pile - On Gossip Option 0 Selected - Close Gossip');

DELETE FROM `event_scripts` WHERE `id` =15014;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(15014, 0, 10, 21838, 3000000, 0, -3789.4, 3507.63, 286.982, -0.994838);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8687 AND `ConditionTypeOrReference`=29;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8687, 0, 0, 0, 29, 0, 21838, 200, 0, 1, 0, 0, '', 'Only show gossip if no terokk nearby');
