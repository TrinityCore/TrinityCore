DELETE FROM conditions WHERE SourceTypeOrReferenceId=22 AND SourceEntry=160445;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(22, 1, 160445, 1, 0, 28, 0, 3821, 0, 0, 0, 0, '', 'Execute SmartAI for gameobject 160445 only if player has complete quest 3821');
