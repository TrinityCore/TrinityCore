-- Volcor
DELETE FROM `gossip_menu` WHERE `MenuID`=3692;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(3692,3213,0),
(3692,3214,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 3692;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,3692,3214,0,0,8,0,993,0,0,0,0,0,"","Volcor - Show Gossip Menu Text 3214 if Quest 993 is rewarded");
