-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (72272, 72273);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 7, 72272, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell Vile Gas (effect 0 & 1 & 2) will hit the potential target of the spell if target is player any player.'),
(13, 7, 72273, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell Vile Gas (effect 0 & 1 & 2) will hit the potential target of the spell if target is player any player.');
