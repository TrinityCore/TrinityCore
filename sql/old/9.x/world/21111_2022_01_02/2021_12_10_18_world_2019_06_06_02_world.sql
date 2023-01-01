-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=9999 AND `TextID`=13857;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(9999, 13857, -1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9999;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9999, 13856, 0, 0, 15, 0, 32, 0, 0, 1, 0, 0, "", "Show gossip text 13856 if player is NOT a Death Knight"),
(14, 9999, 13857, 0, 0, 15, 0, 32, 0, 0, 0, 0, 0, "", "Show gossip text 13857 if player is a Death Knight");
