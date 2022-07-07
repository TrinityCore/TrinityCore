-- 
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=9812 AND `OptionIndex`=0) OR (`MenuId`=9546 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option_action` (`MenuID`, `OptionIndex`, `ActionMenuId`, `ActionPoiID`) VALUES
(9812, 0, 9806, 0),
(9546, 2, 9546, 0);
