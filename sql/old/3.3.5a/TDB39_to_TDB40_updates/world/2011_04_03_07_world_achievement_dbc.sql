--
-- Table structure for table `achievement_dbc`
--

DROP TABLE IF EXISTS `achievement_dbc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `achievement_dbc` (
  `ID` int(10) unsigned NOT NULL,
  `requiredFaction` int(11) NOT NULL DEFAULT '-1',
  `mapID` int(11) NOT NULL DEFAULT '-1',
  `points` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '0',
  `refAchievement` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `achievement_dbc`
--

LOCK TABLES `achievement_dbc` WRITE;
/*!40000 ALTER TABLE `achievement_dbc` DISABLE KEYS */;
INSERT INTO `achievement_dbc` VALUES
(3696,-1,-1,0,2,1,0), -- Earned the right to represent a city in the Argent Tournament
(4788,-1,-1,0,2,1,0), -- Is exalted with The Aldor or has any of exalted rewards
(4789,-1,-1,0,2,1,0); -- Is exalted with The Scryers or has any of exalted rewards
/*!40000 ALTER TABLE `achievement_dbc` ENABLE KEYS */;
UNLOCK TABLES;
