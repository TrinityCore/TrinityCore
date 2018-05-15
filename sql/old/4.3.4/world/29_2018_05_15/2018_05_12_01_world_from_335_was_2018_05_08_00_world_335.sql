/*
-- 
-- Gaeriyan --> Fix Gossip Texts
DELETE FROM `gossip_menu` WHERE `MenuID`=1914 AND `TextID` IN (2567,2569);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1914,2567,0),
(1914,2569,0);

DELETE FROM `npc_text` WHERE `ID`=2569;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(2569,"I have given you all the knowledge I have, $n. May luck be with you.","",4826,0,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1914;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1914,2567,0,0,14,0,3912,0,0,0,0,0,"","Show gossip text 2567 if quest 'Meet at the Grave' is not taken"),
(14,1914,2568,0,0,14,0,3912,0,0,1,0,0,"","Show gossip text 2568 if quest 'Meet at the Grave' is taken"),
(14,1914,2568,0,0,14,0,3913,0,0,0,0,0,"","Show gossip text 2568 if quest 'A Grave Situation' is not taken"),
(14,1914,2569,0,0,14,0,3913,0,0,1,0,0,"","Show gossip text 2569 if quest 'A Grave Situation' is taken");
*/
