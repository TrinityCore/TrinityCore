-- Ranger Lethvalin's gossip menu text changes when quest "Dealing with Zeb'Sora" (9143) is rewarded.
DELETE FROM `gossip_menu` WHERE `MenuID`=7158 AND `TextID`=8428;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7158,8428,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7158;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7158,8428,0,0,8,0,9143,0,0,0,0,0,"","Show gossip dialog text 8428 if Quest 'Dealing with Zeb'Sora' (9143) is rewarded");
