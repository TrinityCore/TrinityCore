-- Priest Trainers
DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (5489, 5484, 376);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(5489, 4467, 55141), -- Brother Joshua
(5484, 4468, 55141), -- Brother Benjamin
(376, 4466, 55141); -- High Priestess Laurena

DELETE FROM `gossip_menu` WHERE `MenuID` IN (4467, 4468, 4466);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4466, 4433, 55141), -- 376 (High Priestess Laurena)
(4466, 4434, 55141), -- 376 (High Priestess Laurena)
(4467, 4433, 55141), -- 5489 (Brother Joshua)
(4467, 4434, 55141), -- 5489 (Brother Joshua)
(4468, 4433, 55141), -- 5484 (Brother Benjamin)
(4468, 4434, 55141); -- 5484 (Brother Benjamin)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (4467, 4468, 4466);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4466, 89697, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4466, 89698, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4466, 89699, 0, 3, 'I seek more training in the priestly ways.', 7157, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 7157 - 7160 - 7167 - 7168 - 7169
(4467, 89700, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4467, 89701, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4467, 89702, 0, 3, 'I seek more training in the priestly ways.', 7157, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 7157 - 7160 - 7167 - 7168 - 7169
(4468, 89703, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4468, 89704, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4468, 89705, 0, 3, 'I seek more training in the priestly ways.', 7157, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141); -- OptionBroadcastTextID: 7157 - 7160 - 7167 - 7168 - 7169

SET @CLASS_MASK := 16;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (4467, 4468, 4466);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4466,4433,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Priest'),
(14,4466,4434,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Priest'),
(15,4466,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4466,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4466,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(14,4467,4433,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Priest'),
(14,4467,4434,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Priest'),
(15,4467,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4467,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4467,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(14,4468,4433,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Priest'),
(14,4468,4434,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Priest'),
(15,4468,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4468,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,4468,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (5489, 5484, 376);
