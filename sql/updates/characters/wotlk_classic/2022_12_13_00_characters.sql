ALTER TABLE `character_void_storage` DROP COLUMN `randomBonusListId`;
ALTER TABLE `character_void_storage` ADD COLUMN `randomPropertyType` TINYINT UNSIGNED NOT NULL DEFAULT 0 AFTER `creatorGuid`, ADD COLUMN `randomProperty` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `randomPropertyType`, ADD COLUMN `suffixFactor` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `randomProperty`;

ALTER TABLE `item_instance` DROP COLUMN `randomBonusListId`;
ALTER TABLE `item_instance` ADD COLUMN `randomPropertyType` TINYINT UNSIGNED NOT NULL DEFAULT 0 AFTER `enchantments`, ADD COLUMN `randomPropertyId` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `randomPropertyType`;
