-- Potion Savoir antique lvl 84 Max
DELETE From conditions WHERE SourceTypeOrReferenceId = 17 AND SourceEntry = 127250;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry , SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES 
(17, 0, 127250, 0, 0, 27, 0, 84, 4, 0, 0, 0, 0, '', 'Level to High to use this object');

-- Correction Stalker ombrecroc
UPDATE `creature_template` SET `flags_extra` = 128 WHERE (entry = 50611);

