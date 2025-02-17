-- Ranger Valanna's gossip menu text changes depending on different quest statuses.
-- NPC Text
DELETE FROM `npc_text` WHERE `ID`=8508;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`Probability0`,`BroadcastTextId0`,`VerifiedBuild`) VALUES
(8508,"","I'm sure that help from Farstrider Enclave will be here soon to help me and this useless lieutenant get to safety. You might not want to stick around; I've heard all sorts of strange sounds coming from the lake and that village over yonder.",1,12101,0);

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7159 AND `TextID`IN (8505,8508);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7159,8505,0),
(7159,8508,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7159;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7159,8505,0,0,47,0,9145,10,0,1,0,0,"","Show gossip dialog text 8505 if Quest 'Help Ranger Valanna!' (9145) is not taken (active)"),
(14,7159,8508,0,0,47,0,9146,74,0,0,0,0,"","Show gossip dialog text 8508 if Quest 'Report to Captain Helios' (9146) is taken, completed or rewarded");
