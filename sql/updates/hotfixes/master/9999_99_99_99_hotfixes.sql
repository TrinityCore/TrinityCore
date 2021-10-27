--
-- Table structure for table `creature_difficulty`
--
DROP TABLE IF EXISTS `creature_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LevelDeltaMin` int(11) NOT NULL DEFAULT '0',
  `LevelDeltaMax` int(11) NOT NULL DEFAULT '0',
  `FactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ContentTuningID` int(11) NOT NULL DEFAULT '0',
  `Flags1` int(11) NOT NULL DEFAULT '0',
  `Flags2` int(11) NOT NULL DEFAULT '0',
  `Flags3` int(11) NOT NULL DEFAULT '0',
  `Flags4` int(11) NOT NULL DEFAULT '0',
  `Flags5` int(11) NOT NULL DEFAULT '0',
  `Flags6` int(11) NOT NULL DEFAULT '0',
  `Flags7` int(11) NOT NULL DEFAULT '0',
  `Flags8` int(11) NOT NULL DEFAULT '0',
  `CreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
