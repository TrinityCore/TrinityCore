/*
DROP TABLE IF EXISTS `character_currency`;
CREATE TABLE `character_currency` (
  `CharacterGuid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0',
  `Currency` SMALLINT(5) UNSIGNED NOT NULL,
  `Quantity` INT(10) UNSIGNED NOT NULL,
  `WeeklyQuantity` INT(10) UNSIGNED NOT NULL,
  `TrackedQuantity` INT(10) UNSIGNED NOT NULL,
  `Flags` TINYINT(3) UNSIGNED NOT NULL,
  PRIMARY KEY (`CharacterGuid`, `Currency`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB;
*/
ALTER TABLE `character_currency`
  CHANGE COLUMN `guid` `CharacterGuid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  CHANGE COLUMN `currency` `Currency` SMALLINT(5) UNSIGNED NOT NULL AFTER `CharacterGuid`,
  CHANGE COLUMN `total_count` `Quantity` INT(10) UNSIGNED NOT NULL AFTER `Currency`,
  CHANGE COLUMN `week_count` `WeeklyQuantity` INT(10) UNSIGNED NOT NULL AFTER `Quantity`,
  ADD COLUMN `TrackedQuantity` INT(10) UNSIGNED NOT NULL AFTER `WeeklyQuantity`,
  ADD COLUMN `Flags` TINYINT(3) UNSIGNED NOT NULL AFTER `TrackedQuantity`;
