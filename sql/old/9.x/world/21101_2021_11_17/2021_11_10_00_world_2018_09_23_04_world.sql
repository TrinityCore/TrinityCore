-- 
-- UPDATE `gossip_menu_option` SET `OptionText`="What are Synthebrew Goggles?" , `OptionBroadcastTextID`=35222, `BoxMoney`=0, `BoxText`="", `BoxBroadcastTextID`=0, `ActionMenuID`=10604 WHERE `MenuID`=9016;
DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=9016 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option_action` (`MenuId`,`OptionIndex`,`ActionMenuId`,`ActionPoiId`) VALUES
(9016,0,10604,0);
