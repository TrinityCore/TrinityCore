-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(7053) AND `SourceGroup`=4;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 4, 7053, 0, 0, 1, 0, 1784, 0, 0, 0, 0, 0, '', 'Klaven Mortwake - run SAI event 4 only if the player is stealthed'),
(22, 4, 7053, 0, 1, 1, 0, 1785, 0, 0, 0, 0, 0, '', 'Klaven Mortwake - run SAI event 4 only if the player is stealthed'),
(22, 4, 7053, 0, 2, 1, 0, 1786, 0, 0, 0, 0, 0, '', 'Klaven Mortwake - run SAI event 4 only if the player is stealthed'),
(22, 4, 7053, 0, 3, 1, 0, 1787, 0, 0, 0, 0, 0, '', 'Klaven Mortwake - run SAI event 4 only if the player is stealthed');
