--
-- Table structure for table `broadcast_text_duration`
--
DROP TABLE IF EXISTS `broadcast_text_duration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `broadcast_text_duration` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BroadcastTextID` int(11) NOT NULL DEFAULT '0',
  `Locale` int(11) NOT NULL DEFAULT '0',
  `Duration` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
