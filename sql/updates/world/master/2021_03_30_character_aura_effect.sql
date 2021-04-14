@ -560,6 +560,34 @@ LOCK TABLES `character_aura_effect` WRITE;
/*!40000 ALTER TABLE `character_aura_effect` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `character_aura_stored_location`
--

DROP TABLE IF EXISTS `character_aura_stored_location`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `character_aura_stored_location` (
  `Guid` bigint(20) unsigned NOT NULL COMMENT 'Global Unique Identifier of Player',
  `Spell` int(10) unsigned NOT NULL COMMENT 'Spell Identifier',
  `MapId` int(10) unsigned NOT NULL COMMENT 'Map Id',
  `PositionX` float NOT NULL COMMENT 'position x',
  `PositionY` float NOT NULL COMMENT 'position y',
  `PositionZ` float NOT NULL COMMENT 'position z',
  `Orientation` float NOT NULL COMMENT 'Orientation',
  PRIMARY KEY (`Guid`,`Spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `character_aura_stored_location`
--

LOCK TABLES `character_aura_stored_location` WRITE;
/*!40000 ALTER TABLE `character_aura_stored_location` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_aura_stored_location` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `character_banned`
--
@ -3822,7 +3850,8 @@ INSERT INTO `updates` VALUES
('2020_08_14_00_characters.sql','355685FF86EE64E2ED9D4B7D1311D53A9C2E0FA5','ARCHIVED','2020-08-14 21:41:24',0),
('2020_10_20_00_characters.sql','744F2A36865761920CE98A6DDE3A3BADF44D1E77','ARCHIVED','2020-10-20 21:36:49',0),
('2020_11_16_00_characters.sql','33D5C7539E239132923D01F4B6EAD5F3EF3EEB69','RELEASED','2020-11-16 19:16:31',0),
('2020_12_13_00_characters.sql','6AC743240033DED2C402ECB894A59D79EF607920','RELEASED','2020-12-13 18:36:58',0);
('2020_12_13_00_characters.sql','6AC743240033DED2C402ECB894A59D79EF607920','RELEASED','2020-12-13 18:36:58',0),
('2021_03_27_00_characters_aura_stored_location.sql','BF772ABC2DF186AF0A5DC56D5E824A2F4813BA69','RELEASED','2021-03-27 15:53:04',0);
/*!40000 ALTER TABLE `updates` ENABLE KEYS */;
UNLOCK TABLES;