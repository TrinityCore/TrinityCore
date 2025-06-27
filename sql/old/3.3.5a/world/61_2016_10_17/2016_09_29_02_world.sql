--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7353;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7353, 8776, 0, 0, 8, 0, 9312, 0, 0, 0, 0, 0, "", "Show gossip text 8776 if player has quest 9312 rewarded"),
(14, 7353, 8777, 0, 0, 8, 0, 9305, 0, 0, 0, 0, 0, "", "Show gossip text 8777 if player has quest 9305 rewarded"),
(14, 7353, 8777, 0, 0, 8, 0, 9312, 0, 0, 1, 0, 0, "", "Show gossip text 8777 if player has quest 9312 NOT rewarded");
