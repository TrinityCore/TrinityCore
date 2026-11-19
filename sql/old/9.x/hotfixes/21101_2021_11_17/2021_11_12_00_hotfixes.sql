--
-- Table structure for table `ui_splash_screen`
--
DROP TABLE IF EXISTS `ui_splash_screen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_splash_screen` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Header` text,
  `TopLeftFeatureTitle` text,
  `TopLeftFeatureDesc` text,
  `BottomLeftFeatureTitle` text,
  `BottomLeftFeatureDesc` text,
  `RightFeatureTitle` text,
  `RightFeatureDesc` text,
  `AllianceQuestID` int(11) NOT NULL DEFAULT '0',
  `HordeQuestID` int(11) NOT NULL DEFAULT '0',
  `ScreenType` tinyint(4) NOT NULL DEFAULT '0',
  `TextureKitID` int(11) NOT NULL DEFAULT '0',
  `SoundKitID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `CharLevelConditionID` int(11) NOT NULL DEFAULT '0',
  `RequiredTimeEventPassed` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ui_splash_screen_locale`
--
DROP TABLE IF EXISTS `ui_splash_screen_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_splash_screen_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Header_lang` text,
  `TopLeftFeatureTitle_lang` text,
  `TopLeftFeatureDesc_lang` text,
  `BottomLeftFeatureTitle_lang` text,
  `BottomLeftFeatureDesc_lang` text,
  `RightFeatureTitle_lang` text,
  `RightFeatureDesc_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
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
/*!40101 SET character_set_client = @saved_cs_client */;
