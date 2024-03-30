-- Magister Duskwither gossip menu text changes after turning in quest "The Magister's Apprentice"
-- Gossip menu
DELETE FROM `gossip_menu` WHERE `MenuID`=6942 AND `TextID`=8233;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6942,8233,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=6942;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6942,8233,0,0,8,0,8888,0,0,0,0,0,"","Gossip text 8233 requires quest The Magister's Apprentice rewarded");
