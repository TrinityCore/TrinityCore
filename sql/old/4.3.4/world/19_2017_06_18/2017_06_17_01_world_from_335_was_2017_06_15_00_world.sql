--
DELETE FROM `creature_text` WHERE `CreatureID` = 24018;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24018, 0, 0, 'Foolish child, you will not stop what I have set in motion! Now, meet your doom!', 12, 0, 100, 0, 0, 0, 23694, 0, 'Necro Overlord Mezhen - SAY_AGGRO');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 43559;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 43559, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', 'RAISE DEAD');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=4 AND `SourceEntry` = 24018;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 4, 24018, 0, 0, 29, 1, 24014, 15, 1, 0, 0, 0, '', 'Necro Overlord Mezhen sai');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24018;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24018) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24018, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 43151, 2, 0, 0, 0, 0, 11, 24021, 30, 0, 0, 0, 0, 0, "Necro Overlord Mezhen - Out of Combat - Cast 'Necrolord: Purple Beam'(No Repeat)"),
(24018, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necro Overlord Mezhen - Out aggro - say text"),
(24018, 0, 2, 0, 0, 0, 100, 0, 2000, 4000, 3000, 5000, 11, 32862, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necro Overlord Mezhen - IC - cast Drain soul"),
(24018, 0, 3, 4, 0, 0, 100, 0, 8000, 11000, 15000, 20000, 11, 43559, 2, 0, 0, 0, 0, 19, 24014, 15, 1, 0, 0, 0, 0, "Necro Overlord Mezhen - IC - cast RAISE DEAD"),
(24018, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24014, 15, 1, 0, 0, 0, 0, "Necro Overlord Mezhen - IC - Despawn corpse");
