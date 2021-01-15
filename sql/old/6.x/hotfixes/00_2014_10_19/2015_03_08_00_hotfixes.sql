--
-- Table structure for table `spell_power_difficulty`
--

DROP TABLE IF EXISTS `spell_power_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_power_difficulty` (
  `SpellPowerID` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellPowerID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_power_difficulty`
--

LOCK TABLES `spell_power_difficulty` WRITE;
/*!40000 ALTER TABLE `spell_power_difficulty` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_power_difficulty` ENABLE KEYS */;
UNLOCK TABLES;
