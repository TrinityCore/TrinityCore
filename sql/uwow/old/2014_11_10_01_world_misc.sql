UPDATE creature_template SET ScriptName = '' WHERE entry = 48510;
delete from conditions where SourceGroup = 48510 and SourceTypeOrReferenceId = 25 and ConditionTypeOrReference = 16;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(25, 48510, 62462, 0, 1, 16, 0, 256, 0, 0, 0, 0, '', NULL),
(25, 48510, 62461, 0, 1, 16, 0, 256, 0, 0, 0, 0, '', NULL);