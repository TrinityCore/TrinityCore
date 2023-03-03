CREATE TABLE `character_pool_guid`(  
  `id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `type` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
  `count` INT(10) UNSIGNED DEFAULT 1 NOT NULL,
  `start` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `end` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`, `type`),
  INDEX `start` (`start`),
  INDEX `end` (`end`),
  INDEX `id` (`id`),
  INDEX `type` (`type`)
) ENGINE=INNODB CHARSET=utf8 COLLATE=utf8_general_ci;
