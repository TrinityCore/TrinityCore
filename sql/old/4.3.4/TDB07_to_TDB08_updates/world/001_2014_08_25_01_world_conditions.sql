-- Target limitation for quest 28189's item
DELETE FROM conditions WHERE sourceTypeOrReferenceId=13 AND sourceEntry=89089;
INSERT INTO conditions (sourceTypeOrReferenceId, sourceGroup, sourceEntry, sourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, COMMENT) VALUES
(13,0,89089,0,0,31,3,47872,0,0,12,0,0,'Shovel should target only Human Seedlings');
