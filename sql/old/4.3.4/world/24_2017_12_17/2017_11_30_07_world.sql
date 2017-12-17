--
DELETE FROM conditions WHERE SourceEntry IN (83445, 91257, 83466, 81350, 91263, 91263, 83235) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, COMMENT) VALUES
(13, 1, 83466, 0, 0, 31, 0, 3, 44712, 0, 0, 0, '', 'Shockwave Searcher - Target Shockwave Visual'),
(13, 1, 83445, 0, 0, 31, 0, 3, 44711, 0, 0, 0, '', 'Shockwave - Target Shockwave Stalker'),
(13, 1, 91257, 0, 0, 31, 0, 3, 44711, 0, 0, 0, '', 'Shockwave - Target Shockwave Stalker'),
(13, 1, 91263, 0, 0, 31, 0, 3, 44796, 0, 0, 0, '', 'Detonate Traps - Target Tolvir Land Mine');
