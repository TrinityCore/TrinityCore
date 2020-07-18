-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (44550, 44610, 44609);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 44550, 0, 0, 29, 0, 24820, 5, 0, 0, 0, 0, '', 'Allow spell Collect Data only on Iron Dwarf Relic 24820'),
(17, 0, 44610, 0, 0, 29, 0, 24824, 5, 0, 0, 0, 0, '', 'Allow spell Collect Data only on Iron Dwarf Relics'),
(17, 0, 44609, 0, 0, 29, 0, 24271, 10, 0, 0, 0, 0, '', 'Allow spell Bluff only on Iron Dwarf'),
(17, 0, 44609, 0, 1, 29, 0, 23673, 10, 0, 0, 0, 0, '', 'Allow spell Bluff only on Iron Dwarf'),
(17, 0, 44609, 0, 2, 29, 0, 23672, 10, 0, 0, 0, 0, '', 'Allow spell Bluff only on Iron Dwarf'),
(17, 0, 44609, 0, 3, 29, 0, 23675, 10, 0, 0, 0, 0, '', 'Allow spell Bluff only on Iron Dwarf');
