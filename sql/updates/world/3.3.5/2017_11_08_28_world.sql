--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=7311;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7311, 8679, 0, 0, 16, 0, 128, 0, 0, 0, 0, 0, "", "Show gossip text 19894 if player is a Troll"),
(15, 7311, 0, 0, 0, 16, 0, 128, 0, 0, 1, 0, 0, "", "Show gossip option 0 if player is NOT a Troll");

DELETE FROM `npc_text` WHERE `ID`=8679;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(8679, "Be gone filthy creature!  Why anyone would tolerate your filth is beyond me.", 12789);
DELETE FROM `gossip_menu` WHERE `MenuID`=7311 AND `TextID`=8679;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7311, 8679, 0);
