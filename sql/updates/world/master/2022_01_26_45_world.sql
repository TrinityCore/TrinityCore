ALTER TABLE `gossip_menu` RENAME COLUMN `MenuId` TO `MenuID`;
ALTER TABLE `gossip_menu` RENAME COLUMN `TextId` TO `TextID`;

ALTER TABLE `gossip_menu_option` RENAME COLUMN `MenuId` TO `MenuID`;
ALTER TABLE `gossip_menu_option` RENAME COLUMN `OptionIndex` TO `OptionID`;
ALTER TABLE `gossip_menu_option` RENAME COLUMN `OptionBroadcastTextId` TO `OptionBroadcastTextID`;
ALTER TABLE `gossip_menu_option` ADD `ActionMenuID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OptionNpcFlag`;
ALTER TABLE `gossip_menu_option` ADD `ActionPoiID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ActionMenuID`;
ALTER TABLE `gossip_menu_option` ADD `BoxCoded` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ActionPoiID`;
ALTER TABLE `gossip_menu_option` ADD `BoxMoney` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BoxCoded`;
ALTER TABLE `gossip_menu_option` ADD `BoxText` mediumtext AFTER `BoxMoney`;
ALTER TABLE `gossip_menu_option` ADD `BoxBroadcastTextID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BoxText`;

ALTER TABLE `gossip_menu_option_locale` RENAME COLUMN `MenuId` TO `MenuID`;
ALTER TABLE `gossip_menu_option_locale` RENAME COLUMN `OptionIndex` TO `OptionID`;

UPDATE `gossip_menu_option` gmo
  LEFT JOIN `gossip_menu_option_action` gmoa ON gmo.`MenuID` = gmoa.`MenuId` AND gmo.`OptionID` = gmoa.`OptionIndex`
  LEFT JOIN `gossip_menu_option_box` gmob ON gmo.`MenuId` = gmoa.`MenuId` AND gmo.`OptionID` = gmoa.`OptionIndex`
  SET gmo.`ActionMenuID` = COALESCE(gmoa.`ActionMenuId`, 0), gmo.`ActionPoiID` = COALESCE(gmoa.`ActionPoiId`, 0),
  gmo.`BoxCoded` = COALESCE(gmob.`BoxCoded`, 0), gmo.`BoxMoney` = COALESCE(gmob.`BoxMoney`, 0), gmo.`BoxText` = gmob.`BoxText`, gmo.`BoxBroadcastTextID` = COALESCE(gmob.`BoxBroadcastTextId`, 0);

DROP TABLE `gossip_menu_option_action`;
DROP TABLE `gossip_menu_option_box`;

ALTER TABLE `creature_trainer` RENAME COLUMN `CreatureId` TO `CreatureID`;
ALTER TABLE `creature_trainer` RENAME COLUMN `TrainerId` TO `TrainerID`;
ALTER TABLE `creature_trainer` RENAME COLUMN `MenuId` TO `MenuID`;
ALTER TABLE `creature_trainer` RENAME COLUMN `OptionIndex` TO `OptionID`;
