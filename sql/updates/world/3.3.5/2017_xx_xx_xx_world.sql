-- gossip_menu
ALTER TABLE `gossip_menu` CHANGE `entry` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu` CHANGE `text_id` `TextID` mediumint(8) unsigned NOT NULL DEFAULT '0';

-- gossip_menu_option
ALTER TABLE `gossip_menu_option` CHANGE `entry` `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `id` `TextID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `option_icon` `OptionIcon` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `option_text` `OptionText` text;
ALTER TABLE `gossip_menu_option` CHANGE `OptionBroadcastTextID` `OptionBroadCastTextID` mediumint(6) NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `option_id` `OptionType` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `npc_option_npcflag` `OptionNpcFlag` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `action_menu_id` `ActionMenuID` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `action_poi_id` `ActionPoiID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_coded` `BoxCoded` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_money` `BoxMoney` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `box_text` `BoxText` text;
ALTER TABLE `gossip_menu_option` CHANGE `BoxBroadcastTextID` `BoxBroadCastTextID` mediumint(6) NOT NULL DEFAULT '0';

-- gossip_menu_option_locale
DROP TABLE IF EXISTS `gossip_menu_option_locale`;
CREATE TABLE IF NOT EXISTS `gossip_menu_option_locale` (
  `MenuID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TextID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Locale` varchar(4) NOT NULL,
  `OptionText` text,
  `BoxText` text,
  PRIMARY KEY (`MenuID`, `TextID`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `locales_gossip_menu_option`;
