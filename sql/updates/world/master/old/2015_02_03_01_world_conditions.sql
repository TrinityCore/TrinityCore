delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (62713, 62968);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 62713, 0, 0, 31, 0, 3, 32918, 0, 0, 0, '', NULL),
(13, 1, 62713, 0, 1, 31, 0, 3, 33203, 0, 0, 0, '', NULL),
(13, 1, 62713, 0, 2, 31, 0, 3, 33202, 0, 0, 0, '', NULL),
(13, 1, 62713, 0, 3, 31, 0, 3, 32919, 0, 0, 0, '', NULL),
(13, 1, 62713, 0, 4, 31, 0, 3, 32916, 0, 0, 0, '', NULL),
(13, 1, 62713, 0, 5, 31, 0, 3, 32906, 0, 0, 0, '', NULL),

(13, 3, 62968, 0, 0, 31, 0, 3, 32918, 0, 0, 0, '', NULL),
(13, 3, 62968, 0, 1, 31, 0, 3, 33203, 0, 0, 0, '', NULL),
(13, 3, 62968, 0, 2, 31, 0, 3, 33202, 0, 0, 0, '', NULL),
(13, 3, 62968, 0, 3, 31, 0, 3, 32919, 0, 0, 0, '', NULL),
(13, 3, 62968, 0, 4, 31, 0, 3, 32916, 0, 0, 0, '', NULL),
(13, 3, 62968, 0, 5, 31, 0, 3, 32906, 0, 0, 0, '', NULL);
