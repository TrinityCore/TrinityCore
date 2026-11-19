--
-- Table structure for table `cinematic_camera`
--

DROP TABLE IF EXISTS `cinematic_camera`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cinematic_camera` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Model` text,
  `OriginX` float NOT NULL DEFAULT '0',
  `OriginY` float NOT NULL DEFAULT '0',
  `OriginZ` float NOT NULL DEFAULT '0',
  `OriginFacing` float NOT NULL DEFAULT '0',
  `SoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cinematic_camera`
--

LOCK TABLES `cinematic_camera` WRITE;
/*!40000 ALTER TABLE `cinematic_camera` DISABLE KEYS */;
/*!40000 ALTER TABLE `cinematic_camera` ENABLE KEYS */;
UNLOCK TABLES;
