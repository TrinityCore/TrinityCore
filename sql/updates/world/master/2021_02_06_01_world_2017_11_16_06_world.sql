-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=47542;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 47542, 0, 0, 29, 0, 26855, 10, 0, 0, 0, 0, "", "Spell 'Draw Power' can be used within 10 yards of 'East Stone' OR"),
(17, 0, 47542, 0, 1, 29, 0, 26856, 10, 0, 0, 0, 0, "", "Spell 'Draw Power' can be used within 10 yards of 'North Stone' OR"),
(17, 0, 47542, 0, 2, 29, 0, 26857, 10, 0, 0, 0, 0, "", "Spell 'Draw Power' can be used within 10 yards of 'South Stone'");
