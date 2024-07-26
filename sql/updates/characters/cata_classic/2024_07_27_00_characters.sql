DROP TABLE IF EXISTS `character_talent`;
CREATE TABLE `character_talent`  (
  `guid` bigint UNSIGNED NOT NULL,
  `talentGroup` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `talentId` int UNSIGNED NOT NULL,
  `rank` tinyint UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`, `talentId`, `talentGroup`)
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `character_talent_group`;
CREATE TABLE `character_talent_group`  (
  `guid` bigint UNSIGNED NOT NULL DEFAULT 0,
  `id` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `talentTabId` int UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`, `id`)
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci;
