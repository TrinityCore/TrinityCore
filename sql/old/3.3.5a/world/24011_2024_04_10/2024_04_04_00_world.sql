-- Ambassador Dawnsinger's gossip text should be different if player is blood elf.
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7359 AND `TextID`=8791;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7359,8791,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7359;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7359,8791,0,0,16,0,512,0,0,0,0,0,"","Show gossip text 8791 if player is a blood elf");
