/*
-- Royal Historian Archesonus
DELETE FROM `gossip_menu` WHERE `MenuID`=1561 AND `TextID`=2235;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1561,2235,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1561;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1561,2235,0,0,9,0,3702,0,0,0,0,0,"","Show gossip text 2235 if quest 'The Smoldering Ruins of Thaurissan' is taken");
*/
