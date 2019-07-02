-- Annie Bonn Gossip text conditions
DELETE FROM `gossip_menu` WHERE `MenuID`=9019 AND `TextID`=12186;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(9019, 12186, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9019;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9019, 12186, 0, 0, 8, 0, 11471, 0, 0, 1, 0, 0, "", "Gossip text 12186 requires quest The Jig is Up NOT rewarded"),
(14, 9019, 12187, 0, 0, 8, 0, 11471, 0, 0, 0, 0, 0, "", "Gossip text 12187 requires quest The Jig is Up rewarded");
