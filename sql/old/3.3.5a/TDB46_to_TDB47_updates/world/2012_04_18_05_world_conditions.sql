-- Add condition to the Lovely Charm aura
DELETE FROM conditions WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`= 69511;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, ScriptName, COMMENT) VALUES
(17,0,69511,0,12,8,0,0,0, '', 'Lovely Charm - Only during event');
