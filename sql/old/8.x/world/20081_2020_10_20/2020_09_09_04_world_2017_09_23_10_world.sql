-- Fix gossip for NPC Eversong Partygoer
DELETE FROM `gossip_menu` WHERE `MenuID`=7346 AND `TextID` IN (8760, 8761);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7346, 8760, 0),
(7346, 8761, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7346;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7346, 8759, 0, 0, 8, 0, 9067, 0, 0, 1, 0, 0, "", "Show gossip text 8759 if quest 'The Party Never Ends' is NOT rewarded AND"),
(14, 7346, 8759, 0, 0, 42, 1, 0, 3, 0, 1, 0, 0, "", "Show gossip text 8759 if NPC standstate is NOT 'sleep'"),
(14, 7346, 8760, 0, 0, 8, 0, 9067, 0, 0, 0, 0, 0, "", "Show gossip text 8759 if quest 'The Party Never Ends' is rewarded AND"),
(14, 7346, 8760, 0, 0, 42, 1, 0, 3, 0, 1, 0, 0, "", "Show gossip text 8759 if NPC standstate is NOT 'sleep'"),
(14, 7346, 8761, 0, 0, 42, 1, 0, 3, 0, 0, 0, 0, "", "Show gossip text 8759 if NPC standstate is 'sleep'");
