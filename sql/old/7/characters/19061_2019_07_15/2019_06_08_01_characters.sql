UPDATE `character_void_storage` SET `randomProperty`=0 WHERE `randomPropertyType`!=2;
UPDATE `item_instance` SET `randomPropertyId`=0 WHERE `randomPropertyType`!=2;
UPDATE `item_loot_items` SET `rnd_prop`=0 WHERE `rnd_type`!=2;

ALTER TABLE `character_void_storage`
  DROP `randomPropertyType`,
  CHANGE `randomProperty` `randomBonusListId` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_instance`
  DROP `randomPropertyType`,
  CHANGE `randomPropertyId` `randomBonusListId` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_loot_items`
  DROP `rnd_type`,
  CHANGE `rnd_prop` `rnd_bonus` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'random bonus list added when originally rolled';
