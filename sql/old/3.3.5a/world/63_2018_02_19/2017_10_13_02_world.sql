-- Vindicator Palanaar
DELETE FROM `gossip_menu` WHERE `MenuID`=7367 AND `TextID`=8803;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7367,8803,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7367;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7367,8802,0,0,16,0,767,0,0,0,0,0,"","Show gossip text 8802 if player is not a Draenei"),
(14,7367,8803,0,0,16,0,1024,0,0,0,0,0,"","Show gossip text 8803 if player is a Draenei");
