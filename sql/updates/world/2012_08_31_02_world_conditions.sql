-- Conditions for Battered hilt drop
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=35075;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(10, 35075, 50379, 0, 0, 6, 0, 469, 0, 0, 0, 0, '', 'Battered Hilt Must Be Alliance'),
(10, 35075, 50380, 0, 0, 6, 0, 67, 0, 0, 0, 0, '', 'Battered Hilt Must Be Horde');