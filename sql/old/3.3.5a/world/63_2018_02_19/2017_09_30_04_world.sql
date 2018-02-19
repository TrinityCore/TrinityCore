-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9188;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9188, 12485, 0, 0, 8, 0, 11892, 0, 0, 1, 0, 0, "", "Gossip text 12485 requires quest 'The Assassination of Harold Lane' NOT rewarded"),
(14, 9188, 12511, 0, 0, 8, 0, 11892, 0, 0, 0, 0, 0, "", "Gossip text 12511 requires quest 'The Assassination of Harold Lane' rewarded");
