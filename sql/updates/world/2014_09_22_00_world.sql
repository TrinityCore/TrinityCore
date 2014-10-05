-- UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE `Id`IN(29396,29397); 335a only

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19656,17034) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(1965600,1965601) AND `source_type`=9;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` =17034;

DELETE FROM `creature` WHERE  `id`=17034;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19656, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, 1965600, 1965601, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - On Just Summoned - Run Random Script'),
(1965600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 29396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - Script 1 - Cast Summon Kaliri Female'),
(1965601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 29397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - Script 2 - Cast Summon Kaliri Male'),
(17034, 0, 1, 0, 8, 0, 100, 0, 29435, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Female Kaliri Hatchling - On Spellhit Capture Female Kaliri Hatchling  - Despawn');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=181582;
DELETE FROM `smart_scripts` WHERE `entryorguid`=181582 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181582, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 12, 19656, 1, 30000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kaliri Nest - On State Changed - Summon Invisible Location Trigger'),
(181582, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kaliri Nest - On State Changed - Despawn');

UPDATE `gameobject` SET `state`=1 WHERE  `id`=181582;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19656;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 19656, 0, 0, 23, 1, 3556, 0, 0, 0, 0, 0, '', '');

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`IN(13,17) AND  `SourceEntry`=29435;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 29435, 0, 0, 31, 0, 3, 17034, 0, 0, 0, 0, '', 'Capture Female Kaliri Hatchling requires target Female Kaliri Hatchling'),
(17, 0, 29435, 0, 0, 31, 1, 3, 17034, 0, 0, 0, 0, '', 'Capture Female Kaliri Hatchling requires target Female Kaliri Hatchling');
