--
-- Table structure for table `location`
--
DROP TABLE IF EXISTS `location`;
CREATE TABLE `location` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `path`
--
DROP TABLE IF EXISTS `path`;
CREATE TABLE `path` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `SplineType` tinyint unsigned NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `Alpha` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `path_node`
--
DROP TABLE IF EXISTS `path_node`;
CREATE TABLE `path_node` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PathID` smallint unsigned NOT NULL DEFAULT '0',
  `Sequence` smallint NOT NULL DEFAULT '0',
  `LocationID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `path_property`
--
DROP TABLE IF EXISTS `path_property`;
CREATE TABLE `path_property` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PathID` smallint unsigned NOT NULL DEFAULT '0',
  `PropertyIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `Value` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
