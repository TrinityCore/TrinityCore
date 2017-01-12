/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13, 17) AND `SourceEntry` IN (15366,22817,22818,22888,22820,24425);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 15366, 0, 0, 27, 1, 63, 4, 0, 0, 0, 0, '', 'Spell Songflower Serenade will hit the explicit target of the spell if player level must be equal or lower than 63.'),
(17, 0, 22817, 0, 0, 27, 1, 63, 4, 0, 0, 0, 0, '', 'Spell Fengus'' Ferocity will hit the explicit target of the spell if player level must be equal or lower than 63.'),
(17, 0, 22818, 0, 0, 27, 1, 63, 4, 0, 0, 0, 0, '', 'Spell Mol''dar''s Moxie will hit the explicit target of the spell if player level must be equal or lower than 63.'),
(13, 3, 22888, 0, 0, 27, 0, 63, 4, 0, 0, 0, 0, '', 'Spell Rallying Cry of the Dragonslayer (effects 1 & 2) will hit the potential target of the spell if player level must be equal or lower than 63.'),
(17, 0, 22820, 0, 0, 27, 1, 63, 4, 0, 0, 0, 0, '', 'Spell Slip''kik''s Savvy will hit the explicit target of the spell if player level must be equal or lower than 63.'),
(13, 4, 24425, 0, 0, 27, 0, 63, 4, 0, 0, 0, 0, '', 'Spell Spirit of Zandalar (effect 2) will hit the potential target of the spell if player level must be equal or lower than 63.');
*/
