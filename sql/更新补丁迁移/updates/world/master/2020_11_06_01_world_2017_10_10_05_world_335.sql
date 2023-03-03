-- Vish Kozus
DELETE FROM `gossip_menu` WHERE `MenuID`=6531 AND `TextID`=7751;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6531,7751,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6531;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6531,7751,0,0,9,0,8283,0,0,0,0,0,"","Show Gossip Menu Text 7751 if Quest 'Wanted - Deathclasp, Terror of the Sands' is taken"),
(14,6531,7751,0,1,28,0,8283,0,0,0,0,0,"","Show Gossip Menu Text 7751 if Quest 'Wanted - Deathclasp, Terror of the Sands' is completed");
