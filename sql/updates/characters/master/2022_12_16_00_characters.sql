ALTER TABLE `character_inventory` ADD `newSlot` tinyint unsigned;
ALTER TABLE `character_inventory` DROP INDEX `guid`;
UPDATE `character_inventory` SET `newSlot`=`slot`;
UPDATE `character_inventory` SET `newSlot`=`slot`+12 WHERE `slot`>=23 AND `bag`=0; -- free up space for reagent bag
UPDATE `character_inventory` SET `newSlot`=`slot`+11 WHERE `slot` BETWEEN 19 AND 22 AND `bag`=0; -- free up space for profession equipment
UPDATE `character_inventory` SET `slot`=`newSlot`;
ALTER TABLE `character_inventory` ADD UNIQUE KEY `uk_location` (`guid`,`bag`,`slot`);
ALTER TABLE `character_inventory` DROP `newSlot`;

UPDATE `characters` SET `equipmentCache`=CONCAT(`equipmentCache`, '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ');
