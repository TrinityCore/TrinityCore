--
-- Table structure for table `item_modified_appearance_extra`
--
DROP TABLE IF EXISTS `item_modified_appearance_extra`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_modified_appearance_extra` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(11) NOT NULL DEFAULT '0',
  `UnequippedIconFileDataID` int(11) NOT NULL DEFAULT '0',
  `SheatheType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DisplayWeaponSubclassID` tinyint(4) NOT NULL DEFAULT '0',
  `DisplayInventoryType` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
