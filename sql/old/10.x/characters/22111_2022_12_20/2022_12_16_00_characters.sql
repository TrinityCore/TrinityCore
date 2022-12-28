
DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_12_16_00_characters;

DELIMITER ';;'
CREATE PROCEDURE apply_if_not_exists_2022_12_16_00_characters() BEGIN

IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='character_action' AND `column_name`='traitConfigId') THEN

ALTER TABLE `character_inventory` ADD `newSlot` tinyint unsigned;
ALTER TABLE `character_inventory` DROP INDEX `guid`;
UPDATE `character_inventory` SET `newSlot`=`slot`;
UPDATE `character_inventory` SET `newSlot`=`slot`+12 WHERE `slot`>=23 AND `bag`=0; -- free up space for reagent bag
UPDATE `character_inventory` SET `newSlot`=`slot`+11 WHERE `slot` BETWEEN 19 AND 22 AND `bag`=0; -- free up space for profession equipment
UPDATE `character_inventory` SET `slot`=`newSlot`;
ALTER TABLE `character_inventory` ADD UNIQUE KEY `uk_location` (`guid`,`bag`,`slot`);
ALTER TABLE `character_inventory` DROP `newSlot`;

UPDATE `characters` SET `equipmentCache`=CONCAT(`equipmentCache`, '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ');

--
-- Table structure for table `character_trait_entry`
--
DROP TABLE IF EXISTS `character_trait_entry`;
CREATE TABLE `character_trait_entry` (
  `guid` bigint unsigned NOT NULL,
  `traitConfigId` int NOT NULL,
  `traitNodeId` int NOT NULL,
  `traitNodeEntryId` int NOT NULL,
  `rank` int NOT NULL DEFAULT '0',
  `grantedRanks` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`traitConfigId`,`traitNodeId`,`traitNodeEntryId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `character_trait_config`
--
DROP TABLE IF EXISTS `character_trait_config`;
CREATE TABLE `character_trait_config` (
  `guid` bigint unsigned NOT NULL,
  `traitConfigId` int NOT NULL,
  `type` int NOT NULL,
  `chrSpecializationId` int DEFAULT NULL,
  `combatConfigFlags` int DEFAULT NULL,
  `localIdentifier` int DEFAULT NULL,
  `skillLineId` int DEFAULT NULL,
  `traitSystemId` int DEFAULT NULL,
  `name` varchar(260) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`,`traitConfigId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `character_action` ADD `traitConfigId` int NOT NULL DEFAULT 0 AFTER `spec`;
ALTER TABLE `character_action` DROP PRIMARY KEY;
ALTER TABLE `character_action` ADD PRIMARY KEY (`guid`,`spec`,`traitConfigId`,`button`);

DELETE FROM `character_talent`;

END IF;
END;;

DELIMITER ';'
CALL apply_if_not_exists_2022_12_16_00_characters();

DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_12_16_00_characters;
