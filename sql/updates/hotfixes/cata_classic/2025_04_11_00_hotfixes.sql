--
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StatID1` int NOT NULL DEFAULT '0',
  `StatID2` int NOT NULL DEFAULT '0',
  `StatID3` int NOT NULL DEFAULT '0',
  `StatID4` int NOT NULL DEFAULT '0',
  `StatID5` int NOT NULL DEFAULT '0',
  `StatID6` int NOT NULL DEFAULT '0',
  `StatID7` int NOT NULL DEFAULT '0',
  `StatID8` int NOT NULL DEFAULT '0',
  `StatID9` int NOT NULL DEFAULT '0',
  `StatID10` int NOT NULL DEFAULT '0',
  `Bonus1` int NOT NULL DEFAULT '0',
  `Bonus2` int NOT NULL DEFAULT '0',
  `Bonus3` int NOT NULL DEFAULT '0',
  `Bonus4` int NOT NULL DEFAULT '0',
  `Bonus5` int NOT NULL DEFAULT '0',
  `Bonus6` int NOT NULL DEFAULT '0',
  `Bonus7` int NOT NULL DEFAULT '0',
  `Bonus8` int NOT NULL DEFAULT '0',
  `Bonus9` int NOT NULL DEFAULT '0',
  `Bonus10` int NOT NULL DEFAULT '0',
  `Maxlevel` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Charlevel` int NOT NULL DEFAULT '0',
  `WeaponDPS1H` int NOT NULL DEFAULT '0',
  `WeaponDPS2H` int NOT NULL DEFAULT '0',
  `SpellcasterDPS1H` int NOT NULL DEFAULT '0',
  `SpellcasterDPS2H` int NOT NULL DEFAULT '0',
  `RangedDPS` int NOT NULL DEFAULT '0',
  `WandDPS` int NOT NULL DEFAULT '0',
  `SpellPower` int NOT NULL DEFAULT '0',
  `BudgetPrimary` int NOT NULL DEFAULT '0',
  `BudgetSecondary` int NOT NULL DEFAULT '0',
  `BudgetTertiary` int NOT NULL DEFAULT '0',
  `BudgetSub` int NOT NULL DEFAULT '0',
  `BudgetTrivial` int NOT NULL DEFAULT '0',
  `ClothCloakArmor` int NOT NULL DEFAULT '0',
  `Unk440_0` int NOT NULL DEFAULT '0',
  `Unk440_1` int NOT NULL DEFAULT '0',
  `Unk440_2` int NOT NULL DEFAULT '0',
  `Unk440_3` int NOT NULL DEFAULT '0',
  `Unk440_4` int NOT NULL DEFAULT '0',
  `Unk440_5` int NOT NULL DEFAULT '0',
  `Unk440_6` int NOT NULL DEFAULT '0',
  `Unk440_7` int NOT NULL DEFAULT '0',
  `Unk440_8` int NOT NULL DEFAULT '0',
  `Unk440_9` int NOT NULL DEFAULT '0',
  `Unk440_10` int NOT NULL DEFAULT '0',
  `Unk440_11` int NOT NULL DEFAULT '0',
  `Unk440_12` int NOT NULL DEFAULT '0',
  `Unk440_13` int NOT NULL DEFAULT '0',
  `Unk440_14` int NOT NULL DEFAULT '0',
  `Unk440_15` int NOT NULL DEFAULT '0',
  `ShoulderArmor1` int NOT NULL DEFAULT '0',
  `ShoulderArmor2` int NOT NULL DEFAULT '0',
  `ShoulderArmor3` int NOT NULL DEFAULT '0',
  `ShoulderArmor4` int NOT NULL DEFAULT '0',
  `ChestArmor1` int NOT NULL DEFAULT '0',
  `ChestArmor2` int NOT NULL DEFAULT '0',
  `ChestArmor3` int NOT NULL DEFAULT '0',
  `ChestArmor4` int NOT NULL DEFAULT '0',
  `HeadArmor1` int NOT NULL DEFAULT '0',
  `HeadArmor2` int NOT NULL DEFAULT '0',
  `HeadArmor3` int NOT NULL DEFAULT '0',
  `HeadArmor4` int NOT NULL DEFAULT '0',
  `LegsArmor1` int NOT NULL DEFAULT '0',
  `LegsArmor2` int NOT NULL DEFAULT '0',
  `LegsArmor3` int NOT NULL DEFAULT '0',
  `LegsArmor4` int NOT NULL DEFAULT '0',
  `FeetArmor1` int NOT NULL DEFAULT '0',
  `FeetArmor2` int NOT NULL DEFAULT '0',
  `FeetArmor3` int NOT NULL DEFAULT '0',
  `FeetArmor4` int NOT NULL DEFAULT '0',
  `WaistArmor1` int NOT NULL DEFAULT '0',
  `WaistArmor2` int NOT NULL DEFAULT '0',
  `WaistArmor3` int NOT NULL DEFAULT '0',
  `WaistArmor4` int NOT NULL DEFAULT '0',
  `HandsArmor1` int NOT NULL DEFAULT '0',
  `HandsArmor2` int NOT NULL DEFAULT '0',
  `HandsArmor3` int NOT NULL DEFAULT '0',
  `HandsArmor4` int NOT NULL DEFAULT '0',
  `WristsArmor1` int NOT NULL DEFAULT '0',
  `WristsArmor2` int NOT NULL DEFAULT '0',
  `WristsArmor3` int NOT NULL DEFAULT '0',
  `WristsArmor4` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
