DROP TABLE IF EXISTS `archaeology_digsites`;
CREATE TABLE `archaeology_digsites`(
    `id` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    `minLevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `minSkillLevel` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    `currencyId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `archaeology_artifacts`;
CREATE TABLE `archaeology_artifacts`(
    `spellId` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `minSkillValue` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`spellId`)
);
