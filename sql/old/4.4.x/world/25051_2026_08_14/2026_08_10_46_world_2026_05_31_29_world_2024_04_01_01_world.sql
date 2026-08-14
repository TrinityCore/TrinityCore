-- Advisor Valwyn gossip menu changes when quest "Investigate the Amani Catacombs" is active and changes again after it has been turned in
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7188 AND `TextID` IN (8467,8468);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7188,8467,0),
(7188,8468,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7188;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7188,8468,0,0,8,0,9193,0,0,0,0,0,"","Gossip text 8491 requires quest 'Investigate the Amani Catacombs' rewarded"),
(14,7188,8467,0,0,47,0,9193,10,0,0,0,0,"","Show gossip dialog text 8467 if Quest 'Investigate the Amani Catacombs' is taken (active)");
