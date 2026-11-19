--
-- Table structure for table `spell_label`
--
DROP TABLE IF EXISTS `spell_label`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_label` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LabelID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
