-- Hunter Trainers
DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (44247, 43277);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(44247, 10371, 55141), -- Wulf Hansreim
(44247, 11817, 55141), -- Wulf Hansreim
(44247, 4461, 55141), -- Wulf Hansreim
(43277, 10371, 55141), -- Don Omar
(43277, 11817, 55141), -- Don Omar
(43277, 4461, 55141); -- Don Omar

SET @NPCTEXTID := 530008;
DELETE FROM `npc_text` WHERE `ID`= @NPCTEXTID;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 44495, 0, 0, 0, 0, 0, 0, 0, 55141);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (10371, 11817, 4461);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10371, 14391, 55141),
(11817, 16569, 55141),
(11817, @NPCTEXTID, 55141),
(4461, 5673, 55141);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (10371, 11817, 4461);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(10371, 93706, 0, 0, 'Purchase a Dual Talent Specialization.', 0, 0, 0, 0, 0, NULL, 0, 100000, 'Are you sure you would like to purchase your second talent specialization?', 0, 63624, NULL, 55141),
(11817, 112533, 0, 3, 'I seek training in the ways of the Hunter.', 7643, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(11817, 112534, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(11817, 112535, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4461, 89689, 0, 11, 'Yes. I do.', 8262, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141); -- OptionBroadcastTextID: 8262 - 8272 - 60960 - 60961

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`= 11817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,11817,@NPCTEXTID,0,0,15,0,4,0,0,'',0,0,0,'','Show gossip text if player is a Hunter'),
(14,11817,16569,0,0,15,0,4,0,0,'',1,0,0,'','Show gossip text if player is not a Hunter'),
(15,11817,0,0,0,15,0,4,0,0,'',0,0,0,'','Show gossip option if player is a Hunter'),
(15,11817,1,0,0,15,0,4,0,0,'',0,0,0,'','Show gossip option if player is a Hunter'),
(15,11817,2,0,0,15,0,4,0,0,'',0,0,0,'','Show gossip option if player is a Hunter');
