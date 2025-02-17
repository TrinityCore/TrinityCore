-- King Varian Wrynn gossip menu changes when quest "Where Kings Walk" (13188) is active
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=9834 AND `TextID`=13905;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(9834,13905,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9834;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,9834,13905,0,0,47,0,13188,10,0,0,0,0,"","Show gossip dialog text 13905 if Quest 'Where Kings Walk' is taken (active)");
