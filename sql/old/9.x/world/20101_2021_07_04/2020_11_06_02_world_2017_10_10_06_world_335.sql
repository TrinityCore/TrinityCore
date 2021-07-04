-- Geologist Larksbane
-- DELETE FROM `gossip_menu` WHERE `MenuID`=6532 AND `TextID`=7748;
-- INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
-- (6532,7748,0);
-- gossip_menu already exists in master

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6532;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6532,7748,0,0,28,0,8285,0,0,0,0,0,"","Show Gossip Menu Text 7748 if Quest 'The Deserter' is completed");
