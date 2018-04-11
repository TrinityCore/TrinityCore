DELETE FROM conditions WHERE SourceEntry IN (28806,29172,29531,30098,29831) AND SourceTypeOrReferenceId IN (13,17);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId) VALUES
(13, 2, 28806, 0, 1, 31, 0, 3, 16592, 0, 0, 0, 0),
(13, 1, 29172, 0, 0, 31, 0, 3, 17066, 0, 0, 0, 0),
(13, 1, 29531, 0, 0, 31, 0, 3, 17066, 0, 0, 0, 0),
(13, 2, 29831, 0, 0, 31, 0, 3, 17066, 0, 0, 0, 0),
(13, 2, 30098, 0, 0, 31, 0, 3, 17253, 0, 0, 0, 0),
(13, 2, 30098, 0, 0, 29, 0, 17233, 20, 0, 1, 0, 0),
(13, 1, 30098, 0, 0, 31, 0, 5, 182483, 0, 0, 0, 0),
(13, 4, 30098, 0, 0, 31, 0, 5, 181653, 0, 0, 0, 0);
