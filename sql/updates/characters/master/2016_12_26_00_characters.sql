ALTER TABLE `character_void_storage` ADD `randomPropertyType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `creatorGuid`;
UPDATE `character_void_storage` SET `randomPropertyType`=1,`randomProperty`=0xFFFFFFFF-`randomProperty`+1 WHERE `randomProperty`>=0x80000000; -- recover from underflow when saving data in old format

ALTER TABLE `item_instance` ADD `randomPropertyType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `enchantments`;
UPDATE `item_instance` SET `randomPropertyType`=1 WHERE `randomPropertyId`<0;
UPDATE `item_instance` SET `randomPropertyId`=ABS(`randomPropertyId`);
ALTER TABLE `item_instance` CHANGE `randomPropertyId` `randomPropertyId` int(10) unsigned NOT NULL DEFAULT '0';


ALTER TABLE `item_loot_items` ADD `rnd_type` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'random enchantment type' AFTER `needs_quest`;
UPDATE `item_loot_items` SET `rnd_type`=1 WHERE `rnd_prop`<0;
UPDATE `item_loot_items` SET `rnd_prop`=ABS(`rnd_prop`);
ALTER TABLE `item_loot_items` CHANGE `rnd_prop` `rnd_prop` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'random enchantment added when originally rolled';
