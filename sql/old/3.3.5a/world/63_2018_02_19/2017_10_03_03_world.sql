-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=8985 AND `TextID`=12124;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8985, 12124, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8985;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 8985, 12124, 0, 0, 8, 0, 11422, 0, 0, 1, 0, 0, "", "Show gossip text if quest 'Trident of the Son' is NOT rewarded"),
(14, 8985, 12130, 0, 0, 8, 0, 11422, 0, 0, 0, 0, 0, "", "Show gossip text if quest 'Trident of the Son' is rewarded");
