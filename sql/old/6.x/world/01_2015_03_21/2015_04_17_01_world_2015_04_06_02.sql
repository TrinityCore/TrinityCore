UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16222;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 16222;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Eye (Paladin's only)
(16222,0,0,1,22,0,100,0,38,5000,5000,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Receive Emote Eye (Paladin Only) - Set Orientation Invoker'),
(16222,0,1,15,61,0,100,0,0,0,0,0,67,1,1000,1000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 1'),
(16222,0,2,0,59,0,100,0,1,0,0,0,5,16,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Play Emote Kneel'),
-- Kiss
(16222,0,3,4,22,0,100,0,58,5000,5000,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Receive Emote Kiss - Set Orientation Invoker'),
(16222,0,4,15,61,0,100,0,0,0,0,0,67,2,1000,1000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 2'),
(16222,0,5,0,59,0,100,0,2,0,0,0,5,2,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Play Emote Bow'),
-- Salute
(16222,0,6,7,22,0,100,0,78,5000,5000,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Receive Emote Salute - Set Orientation Invoker'),
(16222,0,7,15,61,0,100,0,0,0,0,0,67,3,1000,1000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 3'),
(16222,0,8,0,59,0,100,0,3,0,0,0,5,66,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Play Emote Salute'),
-- Rude
(16222,0,9,10,22,0,100,0,77,5000,5000,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Receive Emote Rude - Set Orientation Invoker'),
(16222,0,10,15,61,0,100,0,0,0,0,0,67,4,1000,1000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 4'),
(16222,0,11,0,59,0,100,0,4,0,0,0,5,25,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Play Emote Poinit'),
-- Shy
(16222,0,12,13,22,0,100,0,84,5000,5000,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Receive Emote Shy - Set Orientation Invoker'),
(16222,0,13,15,61,0,100,0,0,0,0,0,67,5,1000,1000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 5'),
(16222,0,14,0,59,0,100,0,5,0,0,0,5,23,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Play Emote Flex'),
-- Clean up
(16222,0,15,0,61,0,100,0,0,0,0,0,67,6,5000,5000,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Event Link - Create Timed Event 6'),
(16222,0,16,0,59,0,100,0,6,0,0,0,66,0,0,0,0,0,100,1,0,0,0,0,0,0,0,'Silvermoon City Guardian - On Timed Event - Reset Orientation');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 16222;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 16222, 0, 0, 15, 0, 2, 0, 0, 0, 0, 0, '', 'Silvermoon Guardian - Only Kneel to Paladins');
