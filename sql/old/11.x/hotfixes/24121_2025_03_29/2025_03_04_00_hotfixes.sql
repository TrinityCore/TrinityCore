--
-- Table structure for table `warband_scene`
--
DROP TABLE IF EXISTS `warband_scene`;
CREATE TABLE `warband_scene` (
  `Name` text,
  `Description` text,
  `Source` text,
  `PositionX` float NOT NULL DEFAULT '0',
  `PositionY` float NOT NULL DEFAULT '0',
  `PositionZ` float NOT NULL DEFAULT '0',
  `LookAtX` float NOT NULL DEFAULT '0',
  `LookAtY` float NOT NULL DEFAULT '0',
  `LookAtZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MapID` int unsigned NOT NULL DEFAULT '0',
  `Fov` float NOT NULL DEFAULT '0',
  `TimeOfDay` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SoundAmbienceID` int NOT NULL DEFAULT '0',
  `Quality` tinyint NOT NULL DEFAULT '0',
  `TextureKit` int NOT NULL DEFAULT '0',
  `DefaultScenePriority` int NOT NULL DEFAULT '0',
  `SourceType` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `warband_scene_locale`
--
DROP TABLE IF EXISTS `warband_scene_locale`;
CREATE TABLE `warband_scene_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `Source_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;
