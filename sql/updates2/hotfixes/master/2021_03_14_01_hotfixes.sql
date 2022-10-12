--
-- Table structure for table `chr_class_ui_display`
--
DROP TABLE IF EXISTS `chr_class_ui_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_class_ui_display` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrClassesID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AdvGuidePlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `SplashPlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
