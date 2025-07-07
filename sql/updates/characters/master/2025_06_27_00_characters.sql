--
-- Table structure for table `character_player_data_element`
--
DROP TABLE IF EXISTS `character_player_data_element`;
CREATE TABLE `character_player_data_element` (
  `characterGuid` bigint unsigned NOT NULL,
  `playerDataElementCharacterId` int unsigned NOT NULL,
  `floatValue` float DEFAULT NULL,
  `int64Value` bigint DEFAULT NULL,
  PRIMARY KEY (`characterGuid`,`playerDataElementCharacterId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `character_player_data_flag`
--
DROP TABLE IF EXISTS `character_player_data_flag`;
CREATE TABLE `character_player_data_flag` (
  `characterGuid` bigint unsigned NOT NULL,
  `storageIndex` int unsigned NOT NULL,
  `mask` bigint unsigned NOT NULL,
  PRIMARY KEY (`characterGuid`,`storageIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
