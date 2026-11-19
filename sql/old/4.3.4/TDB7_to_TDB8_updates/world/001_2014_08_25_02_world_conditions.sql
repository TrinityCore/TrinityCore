-- Target limitation for quest 28280's item
DELETE FROM conditions WHERE sourceTypeOrReferenceId=13 and sourceEntry=89557;
INSERT INTO conditions (sourceTypeOrReferenceId, sourceGroup, sourceEntry, sourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, Comment) VALUES
(13,0,89557,0,0,31,3,48197,0,0,12,0,0,'Shoulder-Mounted Drake Dropper should target only Dragonmaw Black Drakes');
