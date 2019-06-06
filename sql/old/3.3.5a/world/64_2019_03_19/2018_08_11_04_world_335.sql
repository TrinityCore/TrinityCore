-- Apprentice Kryten
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2601;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2601,3294,0,0,8,0,690,0,0,0,0,0,"","Show gossip text 3294 if quest 'Malin's Request' is rewarded"),
(14,2601,3294,0,0,14,0,691,0,0,0,0,0,"","Show gossip text 3294 if quest 'Worth Its Weight in Gold' is not taken");
