/*
-- Tajarri
DELETE FROM `gossip_menu` WHERE `MenuID`=4084 AND `TextID`=4978;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4084,4978,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4084;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4084,4977,0,0,15,0,511,0,0,0,0,0,"","Show gossip text 4977 if Player is not a Druid"),
(14,4084,4978,0,0,15,0,1024,0,0,0,0,0,"","Show gossip text 4978 if Player is a Druid");
*/
