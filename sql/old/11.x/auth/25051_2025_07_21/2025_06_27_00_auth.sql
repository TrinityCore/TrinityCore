--
-- Table structure for table `battlenet_account_player_data_element`
--
DROP TABLE IF EXISTS `battlenet_account_player_data_element`;
CREATE TABLE `battlenet_account_player_data_element` (
  `battlenetAccountId` int unsigned NOT NULL,
  `playerDataElementAccountId` int unsigned NOT NULL,
  `floatValue` float DEFAULT NULL,
  `int64Value` bigint DEFAULT NULL,
  PRIMARY KEY (`battlenetAccountId`,`playerDataElementAccountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `battlenet_account_player_data_flag`
--
DROP TABLE IF EXISTS `battlenet_account_player_data_flag`;
CREATE TABLE `battlenet_account_player_data_flag` (
  `battlenetAccountId` int unsigned NOT NULL,
  `storageIndex` int unsigned NOT NULL,
  `mask` bigint unsigned NOT NULL,
  PRIMARY KEY (`battlenetAccountId`,`storageIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
