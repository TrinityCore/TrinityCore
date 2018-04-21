-- condition for Faerie Fire bonus (only in bear form)
DELETE FROM `conditions` WHERE `SourceEntry` =60089;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,60089,0,1,5487,0,0,0, '', 'Faerie Fire - Bear Form'),
(17,0,60089,1,1,9634,0,0,0, '', 'Faerie Fire - Dire Bear Form');
