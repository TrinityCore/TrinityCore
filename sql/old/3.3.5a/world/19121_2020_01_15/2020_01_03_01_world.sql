-- 
UPDATE `creature_template` SET `gossip_menu_id`=301 WHERE `entry`=3849;
UPDATE `creature_template` SET `gossip_menu_id`=300 WHERE `entry`=3850;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (21213, 21214, 300, 301) AND `TextID` IN (798,799);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(300,798),
(301,799);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21213, 21214, 300, 301);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, BoxBroadcastTextID, `VerifiedBuild`) VALUES
(300, 0, 0, "Please unlock the courtyard door.", 2802, 1, 1, 0, 0, 0, 0, "", 0, 0),
(301, 0, 0, "Please unlock the courtyard door.", 2802, 1, 1, 0, 0, 0, 0, "", 0, 0);
