-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=7162 AND `TextID`=8432;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7162, 8432, 0);
UPDATE `gossip_menu_option` SET `OptionIcon` = 1 WHERE `MenuID` = 7162;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7162;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7162, 8431, 0, 0, 8, 0, 9152, 0, 0, 1, 0, 0, "", "Show gossip text if quest 'Tomber\'s Supplies' has not been rewarded."),
(14, 7162, 8432, 0, 0, 8, 0, 9152, 0, 0, 0, 0, 0, "", "Show gossip text if quest 'Tomber\'s Supplies' has been rewarded.");
