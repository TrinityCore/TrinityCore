-- Vindicator Aesom gossip menu text changes after turning in quest "The Sun Gate"
-- Gossip menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7517 AND `TextID`=9130;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7517,9130,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7517;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7517,9130,0,0,8,0,9740,0,0,0,0,0,"","Gossip text 9130 requires quest The Sun Gate (9740) rewarded");
