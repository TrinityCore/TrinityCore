ALTER TABLE `gossip_menu`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `TextID` `TextId` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu_option`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionID` `OptionIndex` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionNpcflag` `OptionNpcFlag` bigint(20) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu_option_action`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionID` `OptionIndex` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu_option_box`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionID` `OptionIndex` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu_option_trainer`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionID` `OptionIndex` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu_option_locale`
  CHANGE `MenuID` `MenuId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `OptionID` `OptionIndex` INT(10) UNSIGNED NOT NULL DEFAULT '0';
