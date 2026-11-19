
DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_01_26_45_world;

DELIMITER ';;'
CREATE PROCEDURE apply_if_not_exists_2022_01_26_45_world() begin
  /* try to rerun a fixed version of the old update */
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='gossip_menu_option' AND `column_name`='OptionID') THEN
    ALTER TABLE `gossip_menu` CHANGE `MenuId` `MenuID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `gossip_menu` CHANGE `TextId` `TextID`int(10) unsigned NOT NULL DEFAULT 0;
    
    ALTER TABLE `gossip_menu_option` CHANGE `MenuId` `MenuID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `gossip_menu_option` CHANGE `OptionIndex` `OptionID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `gossip_menu_option` CHANGE `OptionBroadcastTextId` `OptionBroadcastTextID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `gossip_menu_option` ADD `ActionMenuID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OptionNpcFlag`;
    ALTER TABLE `gossip_menu_option` ADD `ActionPoiID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ActionMenuID`;
    ALTER TABLE `gossip_menu_option` ADD `BoxCoded` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ActionPoiID`;
    ALTER TABLE `gossip_menu_option` ADD `BoxMoney` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BoxCoded`;
    ALTER TABLE `gossip_menu_option` ADD `BoxText` mediumtext AFTER `BoxMoney`;
    ALTER TABLE `gossip_menu_option` ADD `BoxBroadcastTextID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BoxText`;
    
    ALTER TABLE `gossip_menu_option_locale` CHANGE `MenuId` `MenuID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `gossip_menu_option_locale` CHANGE `OptionIndex` `OptionID` int(10) unsigned NOT NULL DEFAULT 0;
    
    UPDATE `gossip_menu_option` gmo
      LEFT JOIN `gossip_menu_option_action` gmoa ON gmo.`MenuID` = gmoa.`MenuId` AND gmo.`OptionID` = gmoa.`OptionIndex`
      LEFT JOIN `gossip_menu_option_box` gmob ON gmo.`MenuId` = gmoa.`MenuId` AND gmo.`OptionID` = gmoa.`OptionIndex`
      SET gmo.`ActionMenuID` = COALESCE(gmoa.`ActionMenuId`, 0), gmo.`ActionPoiID` = COALESCE(gmoa.`ActionPoiId`, 0),
      gmo.`BoxCoded` = COALESCE(gmob.`BoxCoded`, 0), gmo.`BoxMoney` = COALESCE(gmob.`BoxMoney`, 0), gmo.`BoxText` = gmob.`BoxText`, gmo.`BoxBroadcastTextID` = COALESCE(gmob.`BoxBroadcastTextId`, 0);
    
    DROP TABLE `gossip_menu_option_action`;
    DROP TABLE `gossip_menu_option_box`;
    
    ALTER TABLE `creature_trainer` CHANGE `CreatureId` `CreatureID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `creature_trainer` CHANGE `TrainerId` `TrainerID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `creature_trainer` CHANGE `MenuId` `MenuID` int(10) unsigned NOT NULL DEFAULT 0;
    ALTER TABLE `creature_trainer` CHANGE `OptionIndex` `OptionID` int(10) unsigned NOT NULL DEFAULT 0;
  END IF;
END;;

DELIMITER ';'
CALL apply_if_not_exists_2022_01_26_45_world();

DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_01_26_45_world;
