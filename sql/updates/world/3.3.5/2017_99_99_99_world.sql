UPDATE creature_template SET AIName='', ScriptName='npc_necro_overlord_mezhen' WHERE entry='24018';

DELETE FROM conditions WHERE SourceEntry='43559';
INSERT INTO conditions
	(SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment)
	VALUES (13, 1, 43559, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', '');

