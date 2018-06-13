-- 
-- Valusha Gossip Text
DELETE FROM `gossip_menu` WHERE `MenuID`=7408 AND `TextID` IN (8887,8888);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7408,8887,0),
(7408,8888,0);

DELETE FROM `npc_text` WHERE `ID`=8888;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(8888,"You honor us with your presence, $n.","",13803,0,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7408;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7408,8887,0,0,8,0,9534,0,0,0,0,0,"","Show gossip text 8887 if quest 'Destroy the Legion' is rewarded"),
(14,7408,8887,0,0,8,0,9536,0,0,1,0,0,"","Show gossip text 8887 if quest 'Never Again!' is NOT rewarded"),
(14,7408,8888,0,0,8,0,9534,0,0,0,0,0,"","Show gossip text 8888 if quest 'Destroy the Legion' is rewarded"),
(14,7408,8888,0,0,8,0,9536,0,0,0,0,0,"","Show gossip text 8888 if quest 'Never Again!' is rewarded");
