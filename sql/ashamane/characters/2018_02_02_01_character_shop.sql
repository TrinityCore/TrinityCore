DROP TABLE IF EXISTS `character_shop`;
CREATE TABLE `character_shop` (
  `id` INT (10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `guid` BIGINT (20) NOT NULL,
  `type` TINYINT (3) NOT NULL,
  `itemId` INT (10) NOT NULL DEFAULT 0,
  `itemCount` INT (10) NOT NULL DEFAULT 0,
  `delivered` TINYINT (3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
);
