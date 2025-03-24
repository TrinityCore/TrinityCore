-- Add missing Gurthock gossip_menu
UPDATE `gossip_menu` SET `VerifiedBuild`=59679 WHERE `MenuID`=7699 AND `TextID`=9394;

DELETE FROM `gossip_menu` WHERE `MenuID`=7699 AND `TextID`=9403;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7699, 9403, 59679);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7699 AND `SourceEntry` IN (9394,9403);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7699, 9394, 0, 0, 47, 0, 9977, 64, 0, 1, 0, 0, '', "Show gossip menu if player does not have quest 'The Ring of Blood: The Final Challenge' rewarded"),
(14, 7699, 9403, 0, 0, 47, 0, 9977, 64, 0, 0, 0, 0, '', "Show gossip menu if player has quest 'The Ring of Blood: The Final Challenge' rewarded");
