--
DELETE FROM `gossip_menu` WHERE (`MenuID`=6476 AND `TextID`=7676) OR (`MenuID`=6513 AND `TextID`=7711);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6476, 7676, 0),
(6513, 7711, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (6476, 6513);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 6476, 7676, 0, 0, 27, 0, 35, 2, 0, 0, 0, 0, "", "Gossip text 7676 for NPC Grinkle requires level to be lower than 35"),
(14, 6476, 7677, 0, 0, 27, 0, 35, 3, 0, 0, 0, 0, "", "Gossip text 7677 for NPC Grinkle requires level to be 35 or higher"),
(14, 6513, 7711, 0, 0, 27, 0, 35, 2, 0, 0, 0, 0, "", "Gossip text 7676 for NPC Barrus requires level to be lower than 35"),
(14, 6513, 7712, 0, 0, 27, 0, 35, 3, 0, 0, 0, 0, "", "Gossip text 7677 for NPC Barrus requires level to be 35 or higher");

DELETE FROM `npc_text` WHERE `ID`=7711;
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`) VALUES
(7711, 10596);
