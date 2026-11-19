--
-- Table structure for table `guild_achievement_progress`
--

DROP TABLE IF EXISTS `guild_achievement_progress`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guild_achievement_progress` (
  `guildId` int(10) unsigned NOT NULL,
  `criteria` smallint(5) unsigned NOT NULL,
  `counter` int(10) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  `completedGuid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildId`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guild_achievement_progress`
--

LOCK TABLES `guild_achievement_progress` WRITE;
/*!40000 ALTER TABLE `guild_achievement_progress` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_achievement_progress` ENABLE KEYS */;
UNLOCK TABLES;
