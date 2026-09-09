DELETE FROM `npc_text` WHERE `ID` IN (16623, 16622);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(16623, 1, 0, 0, 0, 0, 0, 0, 0, 44643, 0, 0, 0, 0, 0, 0, 0, 60192), -- 43278 (Ashley Blank)
(16622, 1, 0, 0, 0, 0, 0, 0, 0, 44642, 0, 0, 0, 0, 0, 0, 0, 60192); -- 43278 (Ashley Blank)

DELETE FROM `gossip_menu` WHERE `MenuID` IN (11860, 4659);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11860, 16622, 0), -- 43278 (Ashley Blank)
(11860, 16623, 60192), -- 43278 (Ashley Blank)
(4659,  4835, 60192), -- 915 (Jorik Kerridan)
(4659,  4837, 0); -- 915 (Jorik Kerridan)

UPDATE `creature_template` SET `npcflag`= 0x1 | 0x2 | 0x10 | 0x20 WHERE `entry`= 43278;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`= 11860;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES
(14, 11860, 16623, 15, 4, 0, 'Show gossip text if player is a Hunter'),
(14, 11860, 16622, 15, 4, 1, 'Show gossip text if player is not a Hunter'),
(15, 11860, 0, 15, 4, 0, 'Show gossip menu option if player is a Hunter'),
(15, 11860, 1, 15, 4, 0, 'Show gossip menu option if player is a Hunter'),
(15, 11860, 2, 15, 4, 0, 'Show gossip menu option if player is a Hunter');

DELETE FROM `gossip_menu_option` WHERE `MenuID`= 11860 AND `OptionID` IN (1, 2);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11860,-1192705,1,0,'I wish to unlearn my talents.',8271,0,0,4461,0,NULL,0,0,NULL,0,NULL,NULL,0),
(11860,-1192706,2,0,'I wish to know about Dual Talent Specialization.',33762,0,0,10371,0,NULL,0,0,NULL,0,NULL,NULL,0);
