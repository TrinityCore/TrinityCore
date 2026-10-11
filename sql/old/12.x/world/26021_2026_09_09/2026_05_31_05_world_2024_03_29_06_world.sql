-- High Chief Stillpine is missing gossip menu text
DELETE FROM `gossip_menu` WHERE `MenuID`=7434 AND `TextID`=9173;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7434,9173,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7434 AND `SourceEntry` IN (9173,9039);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7434,9173,0,0,8,0,9544,0,0,1,0,0,"","Gossip text 9173 requires quest 'The Prophecy of Akida (9544)' not rewarded and"),
(14,7434,9173,0,0,47,0,9663,10,0,0,0,0,"","Gossip text 9173 requires players to have quest 'The Kessel Run' (9663) taken (active)"),
(14,7434,9039,0,1,8,0,9544,0,0,0,0,0,"","Gossip text 9039 requires quest 'The Prophecy of Akida (9544)' rewarded and"),
(14,7434,9039,0,1,47,0,9663,10,0,0,0,0,"","Gossip text 9039 requires players to have quest 'The Kessel Run' (9663) taken (active)");
