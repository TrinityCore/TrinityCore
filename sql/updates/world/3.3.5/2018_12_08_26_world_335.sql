-- Janice Felstone
DELETE FROM `gossip_menu` WHERE `MenuID`=2961 AND `TextID`=3669;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2961,3669,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2961;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2961,3669,0,0,8,0,5051,0,0,0,0,0,"","Show gossip text 3669 if quest 'Two Halves Become One' is rewarded");
