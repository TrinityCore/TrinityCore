-- Rogue Trainers
DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (918, 51998, 13283);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(918, 4502, 55141), -- Osborne the Night Man
(51998, 5061, 55141), -- Arthur Huwe
(13283, 5061, 55141); -- Lord Tony Romano

DELETE FROM `gossip_menu` WHERE `MenuID` IN (4502, 5061);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4502, 4835, 55141), -- 918 (Osborne the Night Man)
(4502, 4837, 55141), -- 918 (Osborne the Night Man)
(5061, 4835, 55141), -- 51998 (Arthur Huwe)
(5061, 4837, 55141); -- 51998 (Arthur Huwe)

DELETE FROM `npc_text` WHERE `ID`= 4835;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(4835, 1, 0, 0, 0, 0, 0, 0, 0, 8547, 0, 0, 0, 0, 0, 0, 0, 55141); -- 918 (Osborne the Night Man)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (4502, 5061);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4502, 89949, 10, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4502, 89958, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4502, 89959, 0, 3, 'Can you train me how to use rogue skills?', 7491, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(5061, 90546, 8, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(5061, 90553, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(5061, 90554, 0, 3, 'Can you train me how to use rogue skills?', 7491, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141);

SET @CLASS_MASK := 8;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (4502, 5061);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4502,4835,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Rogue'),
(14,4502,4837,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Rogue'),
(15,4502,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue'),
(15,4502,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue'),
(15,4502,10,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue'),
(14,5061,4835,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Rogue'),
(14,5061,4837,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Rogue'),
(15,5061,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue'),
(15,5061,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue'),
(15,5061,8,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Rogue');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (918, 51998, 13283);
