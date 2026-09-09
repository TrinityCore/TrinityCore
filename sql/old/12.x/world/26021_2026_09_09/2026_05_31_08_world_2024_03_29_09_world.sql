-- Aqueous's gossip menu text changes after turning in quest "Call of Water" (9508)
DELETE FROM `gossip_menu` WHERE `MenuID`=7417 AND `TextID` IN (8958,9014,9016);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7417,8958,0),
(7417,9014,0),
(7417,9016,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7417 AND `SourceEntry` IN (9014,9015,9016);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7417,9014,0,0,15,0,64,0,0,0,0,0,"","Gossip text 9014 requires players to be a Shaman"),
(14,7417,9015,0,0,8,0,9501,0,0,0,0,0,"","Gossip text 9015 requires quest 'Call of Water' (9501) rewarded"),
(14,7417,9016,0,0,8,0,9508,0,0,0,0,0,"","Gossip text 9016 requires quest 'Call of Water' (9508) rewarded");
