--
UPDATE `creature_template` SET `gossip_menu_id`=4013 WHERE `entry`=3407;
DELETE FROM `gossip_menu` WHERE `MenuID`=4013 AND `TextID`=4870;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4013, 4870, 41812);

DELETE FROM `conditions` WHERE `SourceGroup`=4013 AND `SourceTypeOrReferenceId` IN (14, 15);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 4013, 4870, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, "", "Show gossip text if player is a Hunter"),
(14, 4013, 5004, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, "", "Show gossip text if player is not a Hunter"),
(15, 4013, 0, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Hunter"),
(15, 4013, 1, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Hunter"),
(15, 4013, 2, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Hunter");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=4013;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(4013, 0, 3, "I'd like to train.", 7149, 5, 16, 0, 0, 0, 0, "", 0, 0),
(4013, 1, 0, "I wish to unlearn my talents.", 8271, 16, 16, 4461, 0, 0, 0, "", 0, 0),
(4013, 2, 0, "I wish to know about Dual Talent Specialization.", 33762, 20, 1, 10371, 0, 0, 0, "", 0, 0);

UPDATE `gossip_menu_option` SET `OptionText`="I seek training in the ways of the Hunter.", `OptionBroadcastTextID`=7643 WHERE `MenuID`=4506 AND `OptionID`=0;
