DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (461, 5496, 5495, 5520);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(461, 4503, 55141), -- Demisette Cloyce
(5496, 4504, 55141), -- Sandahl
(5495, 4505, 55141), -- Ursula Deline
(5520, 12670, 55141); -- Spackle Thornberry

DELETE FROM `gossip_menu` WHERE `MenuID` IN (4503, 4504, 4505, 12670);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4503, 5693, 55141), -- 461 (Demisette Cloyce)
(4503, 5722, 55141), -- 461 (Demisette Cloyce)
(4504, 5693, 55141), -- 5496 (Sandahl)
(4504, 5722, 55141), -- 5496 (Sandahl)
(4505, 5693, 55141), -- 5495 (Ursula Deline)
(4505, 5722, 55141), -- 5495 (Ursula Deline)
(12670, 12549, 55141), -- 5520 (Spackle Thornberry)
(12670, 17816, 55141); -- 5520 (Spackle Thornberry)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (4503, 4504, 4505, 12670);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(4503, 89960, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4503, 89961, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4503, 89962, 0, 3, 'I am interested in warlock training.', 2544, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4504, 89963, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4504, 89964, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4504, 89965, 0, 3, 'I am interested in warlock training.', 2544, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4505, 89070, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4505, 89071, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4505, 89072, 0, 3, 'I am interested in warlock training.', 2544, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(12670, 113529, 0, 0, 'Abandon Imp', 50696, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 95308, NULL, 55141),
(12670, 113530, 1, 0, 'Abandon Voidwalker', 50697, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 95307, NULL, 55141),
(12670, 113531, 2, 0, 'Abandon Succubus', 50698, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 95309, NULL, 55141),
(12670, 113532, 3, 0, 'Abandon Felhunter', 50699, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 95310, NULL, 55141),
(12670, 113533, 4, 0, 'Abandon Felguard', 50700, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 95312, NULL, 57564),
(12670, 122994, 5, 0, 'Abandon Incubus', 0, 0, 0, 0, 0, NULL, 0, 500000, 'Are you sure you want to pay to abandon your minion?', 50701, 455661, NULL, 55141);

-- Warlock
SET @CLASS_MASK := 256;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (4503, 4504, 4505, 12670);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4503,5693,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Warlock'),
(14,4503,5722,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Warlock'),
(15,4503,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4503,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4503,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),

(14,4504,5693,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Warlock'),
(14,4504,5722,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Warlock'),
(15,4504,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4504,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4504,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),


(14,4505,5693,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Warlock'),
(14,4505,5722,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Warlock'),
(15,4505,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4505,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,4505,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),

(14,12670,17816,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Warlock'),
(14,12670,12549,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Warlock'),
(15,12670,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,12670,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,12670,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,12670,3,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,12670,4,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock'),
(15,12670,5,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Warlock');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (461, 5496, 5495, 5520);
