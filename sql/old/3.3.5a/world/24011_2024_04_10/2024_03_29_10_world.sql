-- Vindicator Kuros gossip menu changes after turning in quest "The Cryo-Core"
-- Gossip menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7489 AND `TextID`=9107;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7489,9107,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7489;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7489,9107,0,0,8,0,9703,0,0,0,0,0,"","Gossip text 9107 requires quest 'The Cryo-Core' rewarded");
