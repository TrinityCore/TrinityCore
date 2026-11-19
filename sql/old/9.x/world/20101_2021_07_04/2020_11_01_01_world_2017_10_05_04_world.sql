-- Update Tempers gossip to show different texts depending on class
DELETE FROM `gossip_menu` WHERE `MenuID`=7378 AND `TextID`=8830;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES 
(7378, 8830);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7378;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 7378, 8832, 0, 0, 15, 0, 64, 0, 0, 0, 0, 0, "", "Show gossip text if class is shaman"), 
(14, 7378, 8830, 0, 0, 15, 0, 64, 0, 0, 1, 0, 0, "", "Show gossip text if class isn't shaman");
