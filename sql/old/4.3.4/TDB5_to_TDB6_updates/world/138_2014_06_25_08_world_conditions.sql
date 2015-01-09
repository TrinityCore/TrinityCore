DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=8593 OR `SourceTypeOrReferenceId`=17 AND `SourceEntry`=8593;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 8593, 0, 0, 29, 0, 17542, 40, 0, 0, 0, 0, '', 'Symbol of Life can be casted within 40 yards of Young Furbolg Shaman'),
(17, 0, 8593, 0, 1, 29, 0, 6172, 40, 0, 0, 0, 0, '', 'Symbol of Life can be casted within 40 yards Henze Faulk'),
(17, 0, 8593, 0, 2, 29, 0, 6177, 40, 0, 0, 0, 0, '', 'Symbol of Life can be casted within 40 yards Henze Faulk'),
(13, 1, 8593, 0, 0, 31, 0, 3, 17542, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Young Furbolg Shaman'),
(13, 1, 8593, 0, 1, 31, 0, 3, 6172, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Henze Faulk'),
(13, 1, 8593, 0, 2, 31, 0, 3, 6177, 0, 0, 0, 0, '', 'Symbol of Life can be casted on Narm Faulk');
