-- Cursed Ooze SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=7086;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7086 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(7086, 0, 0, 0, 8, 0, 100, 1, 15698, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Ooze - On Spell Hit (Filling Empty Jar) - Despawn');

-- Tainted Ooze SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=7092;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7092 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(7092, 0, 0, 0, 8, 0, 100, 1, 15699, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tainted Ooze - On Spell Hit (Filling Empty Jar) - Despawn'),
(7092, 0, 1, 0, 9, 0, 100, 0, 0, 5, 180000, 180000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Ooze - Within 0-5 Range - Cast 'Dark Sludge'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (15698,15699);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17, 0, 15698, 0, 0, 31, 1, 3, 7086, 0, 0, 0, 0, '', "'Filling Empty Jar' must target Cursed Ooze"),
(17, 0, 15698, 0, 0, 36, 1, 0,    0, 0, 1, 0, 0, '', "'Filling Empty Jar' - Target must be dead"),
(17, 0, 15699, 0, 0, 31, 1, 3, 7092, 0, 0, 0, 0, '', "'Filling Empty Jar' must target Tainted Ooze"),
(17, 0, 15699, 0, 0, 36, 1, 0,    0, 0, 1, 0, 0, '', "'Filling Empty Jar' - Target must be dead");
