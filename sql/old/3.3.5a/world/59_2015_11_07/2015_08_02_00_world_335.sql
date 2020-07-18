-- Crudely-Written Log 3.x only
DELETE FROM `conditions` WHERE `sourceentry`=12842;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 10738, 12842, 0, 2, 8, 0, 5121, 0, 0, 0, 0, 0, '', 'Loot Condition: Crudely-Written Log'),
(1, 10738, 12842, 0, 0, 28, 0, 5121, 0, 0, 0, 0, 0, '', 'Loot Condition: Crudely-Written Log'),
(1, 10738, 12842, 0, 1, 9, 0, 5121, 0, 0, 0, 0, 0, '', 'Loot Condition: Crudely-Written Log');
