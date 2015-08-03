--
-- Table structure for table `hotfix_data`
--

DROP TABLE IF EXISTS `hotfix_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hotfix_data` (
  `TableHash` int(10) unsigned NOT NULL DEFAULT '0',
  `RecordID` int(10) NOT NULL,
  `Timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`TableHash`,`RecordID`,`Timestamp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
