-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID`=922 AND `OptionID`=1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(922, 1, 0, "Seen any strange things in the desert lately?", 3662, 1, 1, 1423, 0, 0, 0, "", 0, 0);
