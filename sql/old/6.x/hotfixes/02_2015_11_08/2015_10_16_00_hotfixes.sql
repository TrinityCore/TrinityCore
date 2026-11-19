DROP TABLE IF EXISTS `heirloom`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `heirloom` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `SourceText` text,
  `Source` int(10) unsigned NOT NULL DEFAULT '0',
  `OldItem1` int(10) unsigned NOT NULL DEFAULT '0',
  `OldItem2` int(10) unsigned NOT NULL DEFAULT '0',
  `NextDifficultyItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeItemID1` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeItemID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID2` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

DROP TABLE IF EXISTS `heirloom_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `heirloom_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
