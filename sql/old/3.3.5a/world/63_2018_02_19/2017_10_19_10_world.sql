-- Advisor Sunsworn
DELETE FROM `gossip_menu` WHERE `MenuID`=7362 AND `TextID`=8795;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7362,8795,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7362;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7362,8794,0,0,16,0,512,0,0,1,0,0,"","Show gossip text if player is not a Blood Elf"),
(14,7362,8795,0,0,16,0,512,0,0,0,0,0,"","Show gossip text if player is a Blood Elf");
