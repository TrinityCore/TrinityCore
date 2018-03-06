/*
-- Advisor Duskingdawn --> Fix gossip text
DELETE FROM `gossip_menu` WHERE `MenuID`=7358 AND `TextID`=8787;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7358,8787,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7358;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7358,8789,0,0,16,0,512,0,0,0,0,0,"","Show gossip text if player is a Blood Elf"),
(14,7358,8787,0,0,16,0,1279,0,0,0,0,0,"","Show gossip text if player is not a Blood Elf");
*/
