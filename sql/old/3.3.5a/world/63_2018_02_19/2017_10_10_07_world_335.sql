-- Hermit Ortell
DELETE FROM `gossip_menu` WHERE `MenuID`=6596 AND `TextID`=7817;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6596,7817,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6596;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6596,7817,0,0,8,0,8285,0,0,0,0,0,"","Show Gossip Menu Text 7817 if Quest 'The Deserter' is rewarded");
