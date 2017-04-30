-- gossip_menu
ALTER TABLE `gossip_menu` CHANGE `entry` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu` CHANGE `text_id` `TextID` mediumint(8) unsigned NOT NULL DEFAULT '0';

-- gossip_menu_option
ALTER TABLE `gossip_menu_option` CHANGE `entry` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `id` `OptionID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `option_icon` `OptionIcon` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `option_text` `OptionText` text;
ALTER TABLE `gossip_menu_option` CHANGE `option_id` `OptionType` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `npc_option_npcflag` `OptionNpcFlag` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `action_menu_id` `ActionMenuID` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `action_poi_id` `ActionPoiID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_coded` `BoxCoded` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_money` `BoxMoney` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_text` `BoxText` text;

-- gossip_menu_option_locale
DROP TABLE IF EXISTS `gossip_menu_option_locale`;
CREATE TABLE IF NOT EXISTS `gossip_menu_option_locale` (
  `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OptionID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Locale` varchar(4) NOT NULL,
  `OptionText` text,
  `BoxText` text,
  PRIMARY KEY (`MenuID`, `OptionID`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "koKR", `text_loc1` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc1) > 0);

-- frFR
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "frFR", `text_loc2` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc2) > 0);

-- deDE
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "deDE", `text_loc3` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc3) > 0);

-- zhCN
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "zhCN", `text_loc4` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc4) > 0);

-- zhTW
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "zhTW", `text_loc5` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc5) > 0);

-- esES
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "esES", `text_loc6` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc6) > 0);

-- esMX
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "esMX", `text_loc7` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc7) > 0);

-- ruRU
INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "ruRU", `text_loc8` FROM `locales_gossip_menu_option` WHERE LENGTH(text_loc8) > 0);

DROP TABLE IF EXISTS `locales_gossip_menu_option`;
