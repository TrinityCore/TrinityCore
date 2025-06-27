-- Windcaller Proudhorn
DELETE FROM `gossip_menu` WHERE `MenuID`=6541 AND `TextID`=7747;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6541,7747,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6541;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6541,7747,0,0,8,0,8281,0,0,0,0,0,"","Show Gossip Menu Text 7747 if Quest 'Stepping Up Security' is rewarded");
