/*
-- Mulgris Deepriver --> Fix gossip texts
DELETE FROM `gossip_menu` WHERE `MenuID`=2921 AND `TextID` IN (3633, 3635);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2921,3633,0),
(2921,3635,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 2921;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2921,3635,0,0,8,0,4985,0,0,0,0,0,'',"Show Gossip Menu Text 3635 if Quest 'The Wildlife Suffers Too (Part 2)' is rewarded"),
(14,2921,3633,0,0,6,0,67,0,0,0,0,0,'',"Show Gossip Menu Text 3633 if Player is Horde"),
(14,2921,3634,0,0,6,0,469,0,0,0,0,0,'',"Show Gossip Menu Text 3634 if Player is Alliance");
*/
