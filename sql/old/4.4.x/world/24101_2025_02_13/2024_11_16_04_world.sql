-- Paladin Trainers
DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (928, 5491, 5492);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(928, 4471, 55141), -- Lord Grayson Shadowbreaker
(5491, 4469, 55141), -- Arthur the Faithful
(5492, 4470, 55141); -- Katherine the Pure

DELETE FROM `gossip_menu` WHERE `MenuID` IN (4469, 4470, 4471);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4469, 3976, 55141), -- 5491 (Arthur the Faithful)
(4469, 3977, 55141), -- 5491 (Arthur the Faithful)
(4470, 3976, 55141), -- 5492 (Katherine the Pure)
(4470, 3977, 55141), -- 5492 (Katherine the Pure)
(4471, 3976, 55141), -- 928 (Lord Grayson Shadowbreaker)
(4471, 3977, 55141); -- 928 (Lord Grayson Shadowbreaker)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (4469, 4470, 4471);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4469, 89120, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4469, 89121, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4469, 89122, 0, 3, 'I would like to train further in the ways of the Light.', 5299, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4470, 89538, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4470, 89539, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4470, 89540, 0, 3, 'I would like to train further in the ways of the Light.', 5299, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4471, 90867, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4471, 90868, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4461, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4471, 90869, 0, 3, 'I would like to train further in the ways of the Light.', 5299, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141);

SET @CLASS_MASK := 2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (4469, 4470, 4471);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4469,3976,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Paladin'),
(14,4469,3977,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Paladin'),
(15,4469,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4469,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4469,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(14,4470,3976,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Paladin'),
(14,4470,3977,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Paladin'),
(15,4470,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4470,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4470,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(14,4471,3976,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Paladin'),
(14,4471,3977,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Paladin'),
(15,4471,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4471,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin'),
(15,4471,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Paladin');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (928, 5491, 5492);

-- delete some wrong gossips from hunter trainers
DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (44247, 43277) AND `MenuID` IN (10371, 4461);
