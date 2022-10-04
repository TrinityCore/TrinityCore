--
-- Table structure for table `character_instance_lock`
--
DROP TABLE IF EXISTS `character_instance_lock`;
CREATE TABLE `character_instance_lock` (
  `guid` bigint unsigned NOT NULL,
  `mapId` int unsigned NOT NULL,
  `lockId` int unsigned NOT NULL,
  `instanceId` int unsigned DEFAULT NULL,
  `difficulty` tinyint unsigned DEFAULT NULL,
  `data` text COLLATE utf8mb4_unicode_ci,
  `completedEncountersMask` int unsigned DEFAULT NULL,
  `entranceWorldSafeLocId` int unsigned DEFAULT NULL,
  `expiryTime` bigint unsigned DEFAULT NULL,
  `extended` tinyint unsigned DEFAULT NULL,
  PRIMARY KEY (`guid`,`mapId`,`lockId`),
  UNIQUE KEY `uk_character_instanceId` (`guid`,`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `instance`
--
DROP TABLE IF EXISTS `instance`;
CREATE TABLE `instance` (
  `instanceId` int unsigned NOT NULL,
  `data` text COLLATE utf8mb4_unicode_ci,
  `completedEncountersMask` int unsigned DEFAULT NULL,
  `entranceWorldSafeLocId` int unsigned DEFAULT NULL,
  PRIMARY KEY (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
