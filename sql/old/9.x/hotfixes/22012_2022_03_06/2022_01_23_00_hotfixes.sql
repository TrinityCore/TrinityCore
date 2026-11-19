--
-- Table structure for table `gameobject_art_kit`
--
DROP TABLE IF EXISTS `gameobject_art_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gameobject_art_kit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AttachModelFileID` int(11) NOT NULL DEFAULT '0',
  `TextureVariationFileID1` int(11) NOT NULL DEFAULT '0',
  `TextureVariationFileID2` int(11) NOT NULL DEFAULT '0',
  `TextureVariationFileID3` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
