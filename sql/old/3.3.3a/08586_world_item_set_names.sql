--
-- Table structure for table `item_set_names`
--

DROP TABLE IF EXISTS `item_set_names`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_set_names` (
  `entry` mediumint(8) unsigned NOT NULL,
  `name` varchar(255) character set utf8 NOT NULL default '',
  `InventoryType` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;
