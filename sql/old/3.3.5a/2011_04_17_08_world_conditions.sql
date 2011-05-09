-- Koralon Burning breath Target
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=13 AND SourceEntry IN (66665,67328);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,66665,0,18,1,35013,0,0, '','Koralon Burning Breath'), -- 10 man
(13,0,67328,0,18,1,35013,0,0, '','Koralon Burning Breath'); -- 25 man
