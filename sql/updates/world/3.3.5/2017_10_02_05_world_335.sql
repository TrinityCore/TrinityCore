-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=1043 AND `TextID`=1641;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1043, 1641, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (1043);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1043, 0, 3, "Train me.", 3266, 5, 16, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1043 AND `SourceEntry` IN (1640, 1641);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1043;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 1043, 1640, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, "", "Show gossip text 1640 if player is a blacksmith AND"),
(14, 1043, 1640, 0, 0, 25, 0, 9788, 0, 0, 1, 0, 0, "", "Show gossip text 1640 if player does NOT have spell 'Armorsmith'"),
(14, 1043, 1641, 0, 0, 25, 0, 9788, 0, 0, 0, 0, 0, "", "Show gossip text 1641 if player has spell 'Armorsmith'"),
(15, 1043, 0, 0, 0, 25, 0, 9788, 0, 0, 0, 0, 0, "", "Show gossip option if player has spell 'Armorsmith'");
