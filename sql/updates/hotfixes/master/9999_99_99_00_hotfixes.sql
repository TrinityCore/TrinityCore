--
-- Table structure for table `quest_poi_blob`
--

DROP TABLE IF EXISTS `quest_poi_blob`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_poi_blob` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `UiMapID` int(11) NOT NULL DEFAULT '0',
  `NumPoints` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `QuestID` int(10) unsigned NOT NULL DEFAULT '0',
  `ObjectiveIndex` int(11) NOT NULL DEFAULT '0',
  `ObjectiveID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Unknown901` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_poi_point`
--

DROP TABLE IF EXISTS `quest_poi_point`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_poi_point` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `X` smallint(6) NOT NULL DEFAULT '0',
  `Y` smallint(6) NOT NULL DEFAULT '0',
  `Z` smallint(6) NOT NULL DEFAULT '0',
  `QuestPOIBlob` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;