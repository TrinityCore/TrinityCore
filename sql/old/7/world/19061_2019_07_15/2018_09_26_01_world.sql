-- 
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11326 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(11326, 0, 11325, 0);
