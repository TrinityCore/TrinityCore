/*
-- Anchorite Delan --> Fix gossip text
DELETE FROM `gossip_menu` WHERE `MenuID`=7364 AND `TextID`=8799;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7364,8799,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7364;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7364,8799,0,0,16,0,1024,0,0,0,0,0,"","Show gossip text if player is a Draenei"),
(14,7364,8798,0,0,16,0,767,0,0,0,0,0,"","Show gossip text if player is not a Draenei");
*/
