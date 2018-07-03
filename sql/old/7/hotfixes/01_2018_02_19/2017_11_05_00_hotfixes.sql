--
-- Table structure for table `world_effect`
--

DROP TABLE IF EXISTS `world_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_effect` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetAsset` int(10) unsigned NOT NULL DEFAULT '0',
  `CombatConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TargetType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `WhenToDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `world_effect`
--

LOCK TABLES `world_effect` WRITE;
/*!40000 ALTER TABLE `world_effect` DISABLE KEYS */;
/*!40000 ALTER TABLE `world_effect` ENABLE KEYS */;
UNLOCK TABLES;
