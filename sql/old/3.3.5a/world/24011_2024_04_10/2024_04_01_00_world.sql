-- Deathstalker Maltendis gossip menu change after turning in quest "Troll Juju" and again after turning in "Trouble at the Underlight Mines"
-- NPC Text
DELETE FROM `npc_text` WHERE `ID` IN (8490,8491);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`Probability0`,`Emote0_0`,`EmoteDelay0_1`,`Emote0_1`,`BroadcastTextId0`,`VerifiedBuild`) VALUES
(8490,"Good to see you again, $g man! : gorgeous!; We work well together; $g see you around. : I hope we get to continue to do so.;","",1,2,0,0,12214,0),
(8491,"You've done us exemplary service, $n. Between dealing with the gnolls at the Underlight Mines, and the mummified trolls in the Amani Catacombs, you've dealt a mighty blow to our enemies!$B$B$G Good job! : We should get together for drinks sometime, what do you say?;","",1,1,1000,2,12213,0);

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7207 AND `TextID` IN (8490,8491);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7207,8490,0),
(7207,8491,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7207;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7207,8490,0,0,8,0,9199,0,0,0,0,0,"","Gossip text 8490 requires quest 'Troll Juju' rewarded or"),
(14,7207,8490,0,1,8,0,9192,0,0,0,0,0,"","Gossip text 8490 requires quest 'Trouble at the Underlight Mines' rewarded"),
(14,7207,8491,0,2,8,0,9199,0,0,0,0,0,"","Gossip text 8491 requires quest 'Troll Juju' rewarded and"),
(14,7207,8491,0,2,8,0,9192,0,0,0,0,0,"","Gossip text 8491 requires quest 'Trouble at the Underlight Mines' rewarded");
