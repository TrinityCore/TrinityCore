--
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerLevelToItemLevelCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(11) NOT NULL DEFAULT '0',
  `MaxLevel` int(11) NOT NULL DEFAULT '0',
  `Bonus1` int(10) NOT NULL DEFAULT '0',
  `Bonus2` int(10) NOT NULL DEFAULT '0',
  `Bonus3` int(10) NOT NULL DEFAULT '0',
  `Bonus4` int(10) NOT NULL DEFAULT '0',
  `Bonus5` int(10) NOT NULL DEFAULT '0',
  `Bonus6` int(10) NOT NULL DEFAULT '0',
  `Bonus7` int(10) NOT NULL DEFAULT '0',
  `Bonus8` int(10) NOT NULL DEFAULT '0',
  `Bonus9` int(10) NOT NULL DEFAULT '0',
  `Bonus10` int(10) NOT NULL DEFAULT '0',
  `StatID1` int(10) NOT NULL DEFAULT '0',
  `StatID2` int(10) NOT NULL DEFAULT '0',
  `StatID3` int(10) NOT NULL DEFAULT '0',
  `StatID4` int(10) NOT NULL DEFAULT '0',
  `StatID5` int(10) NOT NULL DEFAULT '0',
  `StatID6` int(10) NOT NULL DEFAULT '0',
  `StatID7` int(10) NOT NULL DEFAULT '0',
  `StatID8` int(10) NOT NULL DEFAULT '0',
  `StatID9` int(10) NOT NULL DEFAULT '0',
  `StatID10` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scaling_stat_distribution`
--

LOCK TABLES `scaling_stat_distribution` WRITE;
/*!40000 ALTER TABLE `scaling_stat_distribution` DISABLE KEYS */;
/*!40000 ALTER TABLE `scaling_stat_distribution` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scaling_stat_values`
--

DROP TABLE IF EXISTS `scaling_stat_values`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scaling_stat_values` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Charlevel` int(11) NOT NULL DEFAULT '0',
  `WeaponDPS1H` int(11) NOT NULL DEFAULT '0',
  `WeaponDPS2H` int(11) NOT NULL DEFAULT '0',
  `SpellcasterDPS1H` int(11) NOT NULL DEFAULT '0',
  `SpellcasterDPS2H` int(11) NOT NULL DEFAULT '0',
  `RangedDPS` int(11) NOT NULL DEFAULT '0',
  `WandDPS` int(11) NOT NULL DEFAULT '0',
  `SpellPower` int(11) NOT NULL DEFAULT '0',
  `ShoulderBudget` int(11) NOT NULL DEFAULT '0',
  `TrinketBudget` int(11) NOT NULL DEFAULT '0',
  `WeaponBudget1H` int(11) NOT NULL DEFAULT '0',
  `PrimaryBudget` int(11) NOT NULL DEFAULT '0',
  `RangedBudget` int(11) NOT NULL DEFAULT '0',
  `TertiaryBudget` int(11) NOT NULL DEFAULT '0',
  `ClothShoulderArmor` int(11) NOT NULL DEFAULT '0',
  `LeatherShoulderArmor` int(11) NOT NULL DEFAULT '0',
  `MailShoulderArmor` int(11) NOT NULL DEFAULT '0',
  `PlateShoulderArmor` int(11) NOT NULL DEFAULT '0',
  `ClothCloakArmor` int(11) NOT NULL DEFAULT '0',
  `ClothChestArmor` int(11) NOT NULL DEFAULT '0',
  `LeatherChestArmor` int(11) NOT NULL DEFAULT '0',
  `MailChestArmor` int(11) NOT NULL DEFAULT '0',
  `PlateChestArmor` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scaling_stat_values`
--

LOCK TABLES `scaling_stat_values` WRITE;
/*!40000 ALTER TABLE `scaling_stat_values` DISABLE KEYS */;
/*!40000 ALTER TABLE `scaling_stat_values` ENABLE KEYS */;
UNLOCK TABLES;
