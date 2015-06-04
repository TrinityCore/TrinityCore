DELETE FROM `event_scripts` WHERE `id`=18223;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(18223, 0, 10, 23837, 180000, 0, 2629.2, 8.1333, 26.347, 0.401426);

DELETE FROM `smart_scripts` WHERE `entryorguid`=23837 AND `source_type`=0 AND `id` =6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27249 AND `source_type`=0 AND `id`>2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23837, 0, 6, 0, 11, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 27249, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - On Just Summoned - Set Data to Alystros the Verdant Keeper'),
(27249, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alystros the Verdant Keeper - On Data Set - Set Emote State None'),
(27249, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alystros the Verdant Keeper - On Data Set - Set Unit Flags'),
(27249, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 4, 3605, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alystros the Verdant Keeper - On Data Set - Play Sound 3605'),
(27249, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Alystros the Verdant Keeper - On Data Set - Attack');

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=27249;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=7 AND `SourceEntry`=23837;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 7, 23837, 0, 0, 23, 1, 4179, 0, 0, 0, 0, 0, '', 'Only run SAI at Emerald Dragonshrine'),
(22, 7, 23837, 0, 1, 23, 1, 3979, 0, 0, 0, 0, 0, '', 'Only run SAI at Emerald Dragonshrine');

UPDATE `gameobject` SET `position_x`=2642.311523, `position_y`=-19.100948, `position_z`=1.434421 WHERE  `guid`=99753;
