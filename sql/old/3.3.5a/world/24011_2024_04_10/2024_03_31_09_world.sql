-- Captaion Helios gossip menu text
-- NPC Text
DELETE FROM `npc_text` WHERE `ID` IN (8493,8494,8496);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`Probability0`,`Emote0_0`,`EmoteDelay0_1`,`Emote0_1`,`BroadcastTextId0`,`VerifiedBuild`) VALUES
(8493,"You've dealt the decisive blow against the Shadowpine trolls, $n. I only hope that we can muster our forces quickly enough to finish them off before they receive reinforcements from Zul'Aman.$B$BIt would be nice if Tranquillien were to reinforce us.","",1,1,0,0,12219,0),
(8494,"You're a one-$g man : woman; rescue machine. That's three of my Farstriders that you've saved now!","",1,1,0,0,12217,0),
(8496,"What can I say, $c? You're a true $g hero : heroine;! Not only have you personally saved many of my rangers, but you've dealt a decisive blow against the Shadowpine trolls. Are you sure that you don't want to stay here and be one of my Farstriders?$B$BFare well, $n.","",1,1,1000,2,12216,0);

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7160 AND `TextID` IN (8493,8494,8495,8496);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7160,8493,0),
(7160,8494,0),
(7160,8495,0),
(7160,8496,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7160;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7160,8496,0,4,8,0,9146,0,0,0,0,0,"","Gossip text 8496 requires quest 'Report to Captain Helios' (9146) rewarded and"),
(14,7160,8496,0,4,8,0,9212,0,0,0,0,0,"","Gossip text 8496 requires quest 'Escape from the Catacombs' (9212) rewarded and"),
(14,7160,8496,0,4,8,0,9214,0,0,0,0,0,"","Gossip text 8496 requires quest 'Shadowpine Weaponry' (9214) rewarded and"),
(14,7160,8496,0,4,8,0,9215,0,0,0,0,0,"","Gossip text 8496 requires quest 'Bring Me Kel'gash's Head!' (9215) rewarded"),
(14,7160,8494,0,0,8,0,9146,0,0,0,0,0,"","Gossip text 8494 requires quest 'Report to Captain Helios' (9146) rewarded and"),
(14,7160,8494,0,0,8,0,9212,0,0,0,0,0,"","Gossip text 8494 requires quest 'Escape from the Catacombs' (9212) rewarded and"),
(14,7160,8494,0,0,8,0,9214,0,0,1,0,0,"","Gossip text 8494 requires quest 'Shadowpine Weaponry' (9214) not rewarded and"),
(14,7160,8494,0,0,8,0,9215,0,0,1,0,0,"","Gossip text 8494 requires quest 'Bring Me Kel'gash's Head!' (9215) not rewarded"),
(14,7160,8495,0,1,47,0,9214,10,0,0,0,0,"","Show gossip dialog text 8495 if Quest 'Shadowpine Weaponry' (9214) is taken (active) and completed or"),
(14,7160,8495,0,2,47,0,9215,10,0,0,0,0,"","Show gossip dialog text 8495 if Quest 'Bring Me Kel'gash's Head!' (9215) is taken (active) and completed"),
(14,7160,8493,0,3,8,0,9214,0,0,0,0,0,"","Gossip text 8493 requires quest 'Shadowpine Weaponry rewarded' (9214) and"),
(14,7160,8493,0,3,8,0,9215,0,0,0,0,0,"","Gossip text 8493 requires quest 'Bring Me Kel'gash's Head!' (9215) rewarded and");
