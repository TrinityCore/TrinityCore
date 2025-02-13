DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (5498, 5497, 2485, 331);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(5498, 4484, 55141), -- Elsharin
(5497, 4485, 55141), -- Jennea Cannon
(331, 4486, 55141), -- Maginor Dumas
(2485, 4822, 55141); -- Larimaine Purdue

DELETE FROM `gossip_menu` WHERE `MenuID` IN (4484, 4485, 4486, 4822);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4484, 538, 55141), -- 5498 (Elsharin)
(4484, 539, 55141), -- 5498 (Elsharin)
(4485, 538, 55141), -- 5497 (Jennea Cannon)
(4485, 539, 55141), -- 5497 (Jennea Cannon)
(4486, 538, 57564), -- 331 (Maginor Dumas)
(4486, 539, 57564), -- 331 (Maginor Dumas)
(4822, 5875, 57564), -- 2485 (Larimaine Purdue)
(4822, 5876, 55141); -- 2485 (Larimaine Purdue)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (4484, 4485, 4486, 4822);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4484, 89002, 0, 3, 'I am interested in mage training.', 2522, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564),
(4484, 89001, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4484, 89000, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4485, 89005, 0, 3, 'I am interested in mage training.', 2522, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564),
(4485, 89004, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4485, 89003, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4486, 89008, 0, 3, 'I am interested in mage training.', 2522, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564),
(4486, 89007, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4486, 89006, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4822, 90316, 0, 3, 'Please teach me.', 8442, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564);

-- Mage
SET @CLASS_MASK := 128;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (4484, 4485, 4486, 4822);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4484,538,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Mage'),
(14,4484,539,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Mage'),
(15,4484,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4484,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4484,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),

(14,4485,538,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Mage'),
(14,4485,539,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Mage'),
(15,4485,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4485,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4485,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),

(14,4486,538,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Mage'),
(14,4486,539,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Mage'),
(15,4486,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4486,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),
(15,4486,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage'),

(14,4822,5876,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Mage'),
(14,4822,5875,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Mage'),
(15,4822,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Mage');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (5498, 5497, 2485, 331);
