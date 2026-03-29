DROP TABLE IF EXISTS `character_background_filters`;
CREATE TABLE `character_background_filters` (
    `guid` BIGINT UNSIGNED NOT NULL,
    `filter_id` INT UNSIGNED NOT NULL,
    PRIMARY KEY (`guid`, `filter_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
