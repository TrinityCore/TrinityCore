-- gossip_menu_option_action
ALTER TABLE `gossip_menu_option_action` CHANGE `MenuId` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option_action` CHANGE `OptionIndex` `OptionID` smallint(5) unsigned NOT NULL DEFAULT '0';

-- gossip_menu_option_box
ALTER TABLE `gossip_menu_option_box` CHANGE `MenuId` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option_box` CHANGE `OptionIndex` `OptionID` smallint(5) unsigned NOT NULL DEFAULT '0';

-- gossip_menu_option_trainer
ALTER TABLE `gossip_menu_option_trainer` CHANGE `MenuId` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option_trainer` CHANGE `OptionIndex` `OptionID` smallint(5) unsigned NOT NULL DEFAULT '0';
