DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (44395, 44396, 11397, 5504, 44393, 44394, 20407, 45306);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(44395, 11829, 55141), -- Celestine of the Harvest
(44396, 11829, 55141), -- Celestine of the Harvest
(11397, 12537, 55141), -- Nara Meideros
(5504, 4508, 55141), -- Sheldras Moontree
(44393, 12529, 55141), -- Bolner Hammerbeak
(44394, 12529, 55141), -- Dalga Hammerbeak
(20407, 8110, 55141), -- Farseer Umbrua
(45306, 12004, 55141); -- Chief Surgeon Gashweld

DELETE FROM `npc_text` WHERE `ID` IN (4438, 4784, 15110, 15111, 10040, 10043, 16561);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(4438, 1, 0, 0, 0, 0, 0, 0, 0, 7166, 0, 0, 0, 0, 0, 0, 0, 55141), -- 11397 (Nara Meideros)
(4784, 1, 0, 0, 0, 0, 0, 0, 0, 8269, 0, 0, 0, 0, 0, 0, 0, 55141), -- 5504 (Sheldras Moontree)
(15110, 1, 0, 0, 0, 0, 0, 0, 0, 36938, 0, 0, 0, 0, 0, 0, 0, 55141), -- 44393 (Bolner Hammerbeak)
(15111, 1, 0, 0, 0, 0, 0, 0, 0, 36939, 0, 0, 0, 0, 0, 0, 0, 55141), -- 44393 (Bolner Hammerbeak)
(10040, 1, 0, 0, 0, 0, 0, 0, 0, 18105, 0, 0, 0, 0, 0, 0, 0, 55141), -- 20407 Farseer Umbrua
(10043, 1, 0, 0, 0, 0, 0, 0, 0, 18111, 0, 0, 0, 0, 0, 0, 0, 55141), -- 20407 Farseer Umbrua
(16561, 1, 0, 0, 0, 0, 0, 0, 0, 45515, 0, 0, 0, 0, 0, 0, 0, 57564); -- 45306 (Chief Surgeon Gashweld)

DELETE FROM `gossip_menu` WHERE `MenuID` IN (11829, 12537, 4508, 12529, 8110, 12004);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11829, 14835, 55141), -- 44395 (Celestine of the Harvest)
(11829, 16586, 55141), -- 44395 (Celestine of the Harvest)
(12537, 4437, 55141), -- 11397 (Nara Meideros)
(12537, 4438, 55141), -- 11397 (Nara Meideros)
(4508, 4783, 55141), -- 5504 (Sheldras Moontree)
(4508, 4784, 55141), -- 5504 (Sheldras Moontree)
(12529, 15110, 55141), -- 12529 (Bolner Hammerbeak)
(12529, 15111, 55141), -- 12529 (Bolner Hammerbeak)
(8110, 10040, 55141), -- 20407 (Farseer Umbrua)
(8110, 10043, 55141), -- 20407 (Farseer Umbrua)
(12004, 16562, 55141), -- 45306 (Chief Surgeon Gashweld)
(12004, 16561, 55141); -- 45306 (Chief Surgeon Gashweld)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (11829, 12537, 4508, 8110, 12529, 12004, 4463);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11829, 112543, 0, 3, 'I seek training as a druid.', 7452, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(11829, 112544, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(11829, 112545, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(12537, 113385, 0, 3, 'I would like to train.', 2548, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 2548 - 5597 - 7563 - 8221
(12537, 113386, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 2001, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(12537, 113387, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4508, 89566, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4508, 89567, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(4508, 89568, 0, 3, 'I seek training as a druid.', 7452, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(8110, 91890, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(8110, 91891, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(8110, 91892, 0, 3, 'Teach me the ways of the spirits.', 7658, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(12529, 113347, 0, 3, 'Teach me the ways of the spirits.', 7658, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(12529, 113348, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(12529, 113349, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(12004, 112718, 0, 3, 'I require priest training.', 11072, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57564),
(12004, 112719, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 4463, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(12004, 112720, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 10371, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141),
(4463, 89692, 0, 11, 'Yes. I do.', 8262, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55141); -- OptionBroadcastTextID: 8262 - 8272 - 60960 - 60961

-- Druid
SET @CLASS_MASK := 1024;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (11829, 12537, 4508, 12529, 8110, 12004, 4463);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,11829,14836,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Druid'),
(14,11829,16585,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Druid'),
(15,11829,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,11829,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,11829,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),

(14,4508,4784,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Druid'),
(14,4508,4783,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Druid'),
(15,4508,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,4508,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,4508,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid');

-- Priest
SET @CLASS_MASK := 16;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,12537,4438,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Priest'),
(14,12537,4437,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Priest'),
(15,12537,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,12537,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,12537,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),

(14,12004,16561,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Priest'),
(14,12004,16562,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Priest'),
(15,12004,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,12004,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest'),
(15,12004,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Priest');

-- Shaman
SET @CLASS_MASK := 64;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,12529,15110,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Shaman'),
(14,12529,15111,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Shaman'),
(15,12529,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman'),
(15,12529,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman'),
(15,12529,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman'),

(14,8110,10043,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Shaman'),
(14,8110,10040,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Shaman'),
(15,8110,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman'),
(15,8110,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman'),
(15,8110,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Shaman');

UPDATE `creature_template` SET `npcflag`= `npcflag` | 0x1 WHERE `entry` IN (44395, 44396, 11397, 5504, 44393, 44394, 20407, 45306);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=45306 AND `MenuID`=12004 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(45306, 3, 12004, 0);
