--
UPDATE `creature_template` SET `gossip_menu_id`=4510 WHERE `entry`=3408;
DELETE FROM `gossip_menu` WHERE `MenuID`=4510 AND `TextID`=4987;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4510, 4987, 41812);

DELETE FROM `conditions` WHERE `SourceGroup`=4510 AND `SourceTypeOrReferenceId` IN (14, 15);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 4510, 4987, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, "", "Show gossip text if player is a Warrior"),
(14, 4510, 4986, 0, 0, 15, 0, 1, 0, 0, 1, 0, 0, "", "Show gossip text if player is not a Warrior"),
(15, 4510, 0, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Warrior"),
(15, 4510, 1, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Warrior"),
(15, 4510, 2, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Warrior");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=4510;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(4510, 0, 3, "I require warrior training.", 3147, 5, 16, 0, 0, 0, 0, "", 0, 0),
(4510, 1, 0, "I wish to unlearn my talents.", 8271, 16, 16, 4461, 0, 0, 0, "", 0, 0),
(4510, 2, 0, "I wish to know about Dual Talent Specialization.", 33762, 20, 1, 10371, 0, 0, 0, "", 0, 0);
