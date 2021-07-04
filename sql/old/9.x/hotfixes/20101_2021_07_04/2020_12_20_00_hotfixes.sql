--
-- Table structure for table `hotfix_optional_data`
--
DROP TABLE IF EXISTS `hotfix_optional_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hotfix_optional_data` (
  `TableHash` int(10) unsigned NOT NULL,
  `RecordId` int(10) unsigned NOT NULL,
  `locale` varchar(4) NOT NULL,
  `Key` int(10) unsigned NOT NULL,
  `Data` blob NOT NULL,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
