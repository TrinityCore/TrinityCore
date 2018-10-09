-- Liv Rizzlefix
DELETE FROM `gossip_menu` WHERE `MenuID`=5503 AND `TextID`=6557;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5503,6557,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5503;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,5503,6557,0,0,9,0,3444,0,0,0,0,0,"","Show gossip text 6557 if quest 'The Stone Circle' is taken");
