-- Necro Overlord Mezhen (24018)
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_necro_overlord_mezhen' WHERE `entry` = 24018;

DELETE FROM `creature_text` WHERE `CreatureID` = 24018; -- entire row missing in TDB 335.63
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24018, 0, 0, 'Foolish child, you will not stop what I have set in motion! Now, meet your doom!', 12, 0, 100, 0, 0, 0, 23694, 0, 'Necro Overlord Mezhen - SAY_AGGRO');

DELETE FROM `conditions` WHERE `SourceEntry` = 43559;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 43559, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', '');
