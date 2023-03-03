DROP TABLE IF EXISTS `character_archaeology_branchs`;
CREATE TABLE `character_archaeology_branchs`(
    `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT 0,
    `projectId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`guid`, `projectId`)
);

DROP TABLE IF EXISTS `character_archaeology_digsites`;
CREATE TABLE `character_archaeology_digsites`(
    `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT 0,
    `digsiteId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    `point_x` FLOAT DEFAULT 0,
    `point_y` FLOAT DEFAULT 0,
    `count` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`guid`, `digsiteId`)
);

DROP TABLE IF EXISTS `character_archaeology_history`;
CREATE TABLE `character_archaeology_history`(
    `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT 0,
    `time` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    `projectId` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `count` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`guid`, `projectId`)
);
