DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceEntry` IN (45786,45788,45815);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceEntry`=46110;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4,27078,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,27079,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,27080,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,27081,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,26959,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,26960,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,26961,46110,0,0,7,0,171,425,0,0,0,0,'',NULL),
(4,26962,46110,0,0,7,0,171,425,0,0,0,0,'',NULL);
