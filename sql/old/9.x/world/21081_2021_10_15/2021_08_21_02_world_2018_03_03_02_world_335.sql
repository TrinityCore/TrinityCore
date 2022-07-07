-- Fix gossip option for Spark Nilminer
DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=2422 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option_action` (`MenuId`,`OptionIndex`,`ActionMenuId`) VALUES
(2422,0,2721);
