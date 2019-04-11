-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (36310);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 36310, 0, 0, 31, 1, 3, 20058, 0, 0, 0, 0, '', 'Spell "Rina\'s Diminution Powder" can only be used on Bloodmaul Dire Wolf'),
(17, 0, 36310, 0, 0,  1, 1, 36310, 0, 0, 1, 0, 0, '', 'Spell "Rina\'s Diminution Powder" can not be reapplied.');
