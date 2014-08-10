UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` =17542;
DELETE FROM `smart_scripts` WHERE `entryorguid` =17542;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17542,0,0,1,8,0,100,0,8593,0,0,0,33,17542,0,0,0,0,0,7,0,0,0,0,0,0,0,'Young Furbolg Shaman - On Spell Hit - Give Kill Credit'),
(17542,0,1,2,61,0,100,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,'Young Furbolg Shaman - Linked with Previous Event - Remove permament Feign Death'),
(17542,0,2,0,61,0,100,0,0,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Young Furbolg Shaman - Linked with Previous Event - Set Phase 2'),

(17542,0,4,5, 1,2,100,0,60000,60000,60000,60000,11,29266,2,0,0,0,0,1,0,0,0,0,0,0,0,'Young Furbolg Shaman - OOC - Cast Permament Feign Death'),
(17542,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Young Furbolg Shaman - Linked with Previous Event - Set Phase 1'),
(17542,0,6,0,25,0,100,0,0,0,0,0,11,29266,2,0,0,0,0,1,0,0,0,0,0,0,0,'Young Furbolg Shaman - On Spawn - Cast Permament Feign Death');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=8593;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 8593, 0, 0, 31, 0, 3, 17542, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Young Furbolg Shaman'),
(13, 1, 8593, 0, 1, 31, 0, 3, 6172, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Henze Faulk'),
(13, 1, 8593, 0, 2, 31, 0, 3, 6177, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Narm Faulk');
