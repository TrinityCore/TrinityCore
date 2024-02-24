-- Velaada is missing npc text
DELETE FROM `npc_text` WHERE `ID`=8957;
INSERT INTO `npc_text` (`ID`,`text0_1`,`Probability0`,`Emote0_0`,`Probability1`,`Probability2`,`Probability3`,`Probability4`,`Probability5`,`Probability6`,`Probability7`,`BroadcastTextId0`,`BroadcastTextId1`,`BroadcastTextId2`,`BroadcastTextId3`,`BroadcastTextId4`,`BroadcastTextId5`,`BroadcastTextId6`,`BroadcastTextId7`,`VerifiedBuild`) VALUES
(8957,"Susurrus is expecting you, $n.",1,1,0,0,0,0,0,0,0,14014,0,0,0,0,0,0,0,0);

-- Velaada is missing gossip_menu text
DELETE FROM `gossip_menu` WHERE `MenuID`=7416 AND `TextID` IN (8957,8959);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7416,8957,0),
(7416,8959,0);

-- Velaada Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7416;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7416,8959,0,0,47,0,9552,10,0,0,0,0,"","Show gossip dialog text 8959 if Quest Call of Air (9552) is taken (active)"),
(14,7416,8957,0,0,47,0,9553,10,0,0,0,0,"","Show gossip dialog text 8957 if Quest Call of Air (9553) is taken (active)");
