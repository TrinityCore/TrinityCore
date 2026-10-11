--
-- Table structure for table `player_data_element_account`
--
DROP TABLE IF EXISTS `player_data_element_account`;
CREATE TABLE `player_data_element_account` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StorageIndex` int NOT NULL DEFAULT '0',
  `Type` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `player_data_element_character`
--
DROP TABLE IF EXISTS `player_data_element_character`;
CREATE TABLE `player_data_element_character` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StorageIndex` int NOT NULL DEFAULT '0',
  `Type` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `player_data_flag_account`
--
DROP TABLE IF EXISTS `player_data_flag_account`;
CREATE TABLE `player_data_flag_account` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StorageIndex` int NOT NULL DEFAULT '0',
  `Unknown1107` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `player_data_flag_character`
--
DROP TABLE IF EXISTS `player_data_flag_character`;
CREATE TABLE `player_data_flag_character` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StorageIndex` int NOT NULL DEFAULT '0',
  `Unknown1107` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
