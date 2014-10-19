-- Proper condition for spell
DELETE FROM `conditions` WHERE `SourceEntry`=34083; 
DELETE FROM `conditions` WHERE `SourceEntry`=50165; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 50165, 0, 0, 31, 1, 3, 24669, 0, 0, 173, 0, '', 'Awakening Rod target limit to Dormant Vrykul');
