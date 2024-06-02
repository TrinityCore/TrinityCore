--
-- Table structure for table `item_sparse`
--

DROP TABLE IF EXISTS `item_sparse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_sparse` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllowableRace` bigint(20) NOT NULL DEFAULT '0',
  `Description` text,
  `Display3` text,
  `Display2` text,
  `Display1` text,
  `Display` text,
  `DmgVariance` float NOT NULL DEFAULT '0',
  `DurationInInventory` int(10) unsigned NOT NULL DEFAULT '0',
  `QualityModifier` float NOT NULL DEFAULT '0',
  `BagFamily` int(10) unsigned NOT NULL DEFAULT '0',
  `StartQuestID` int(11) NOT NULL DEFAULT '0',
  `ItemRange` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket1` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket2` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket3` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket4` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket5` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket6` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket7` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket8` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket9` float NOT NULL DEFAULT '0',
  `StatPercentageOfSocket10` float NOT NULL DEFAULT '0',
  `Unknown440_11` int(11) NOT NULL DEFAULT '0',
  `Unknown440_12` int(11) NOT NULL DEFAULT '0',
  `Unknown440_13` int(11) NOT NULL DEFAULT '0',
  `Unknown440_14` int(11) NOT NULL DEFAULT '0',
  `Unknown440_15` int(11) NOT NULL DEFAULT '0',
  `Unknown440_16` int(11) NOT NULL DEFAULT '0',
  `Unknown440_17` int(11) NOT NULL DEFAULT '0',
  `Unknown440_18` int(11) NOT NULL DEFAULT '0',
  `Unknown440_19` int(11) NOT NULL DEFAULT '0',
  `Unknown440_110` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor1` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor2` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor3` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor4` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor5` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor6` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor7` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor8` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor9` int(11) NOT NULL DEFAULT '0',
  `StatPercentEditor10` int(11) NOT NULL DEFAULT '0',
  `Stackable` int(11) NOT NULL DEFAULT '0',
  `MaxCount` int(11) NOT NULL DEFAULT '0',
  `MinReputation` int(11) NOT NULL DEFAULT '0',
  `RequiredAbility` int(10) unsigned NOT NULL DEFAULT '0',
  `SellPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `BuyPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `VendorStackCount` int(10) unsigned NOT NULL DEFAULT '0',
  `PriceVariance` float NOT NULL DEFAULT '0',
  `PriceRandomValue` float NOT NULL DEFAULT '0',
  `Flags1` int(11) NOT NULL DEFAULT '0',
  `Flags2` int(11) NOT NULL DEFAULT '0',
  `Flags3` int(11) NOT NULL DEFAULT '0',
  `Flags4` int(11) NOT NULL DEFAULT '0',
  `FactionRelated` int(11) NOT NULL DEFAULT '0',
  `ModifiedCraftingReagentItemID` int(11) NOT NULL DEFAULT '0',
  `ContentTuningID` int(11) NOT NULL DEFAULT '0',
  `PlayerLevelToItemLevelCurveID` int(11) NOT NULL DEFAULT '0',
  `MaxDurability` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredTransmogHoliday` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredHoliday` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LimitCategory` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GemProperties` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SocketMatchEnchantmentId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TotemCategoryID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `InstanceBound` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ZoneBound1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ZoneBound2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemSet` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LockID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemDelay` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllowableClass` smallint(6) NOT NULL DEFAULT '0',
  `ItemRandomSuffixGroupID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RandomSelect` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinDamage1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinDamage2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinDamage3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinDamage4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinDamage5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxDamage1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxDamage2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxDamage3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxDamage4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxDamage5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Resistances1` smallint(6) NOT NULL DEFAULT '0',
  `Resistances2` smallint(6) NOT NULL DEFAULT '0',
  `Resistances3` smallint(6) NOT NULL DEFAULT '0',
  `Resistances4` smallint(6) NOT NULL DEFAULT '0',
  `Resistances5` smallint(6) NOT NULL DEFAULT '0',
  `Resistances6` smallint(6) NOT NULL DEFAULT '0',
  `Resistances7` smallint(6) NOT NULL DEFAULT '0',
  `ScalingStatDistributionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StatModifierBonusAmount1` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount2` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount3` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount4` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount5` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount6` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount7` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount8` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount9` smallint(6) NOT NULL DEFAULT '0',
  `StatModifierBonusAmount10` smallint(6) NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellWeight` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellWeightCategory` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SheatheType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Material` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PageMaterialID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Bonding` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DamageDamageType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StatModifierBonusStat1` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat2` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat3` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat4` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat5` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat6` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat7` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat8` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat9` tinyint(4) NOT NULL DEFAULT '0',
  `StatModifierBonusStat10` tinyint(4) NOT NULL DEFAULT '0',
  `ContainerSlots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredPVPMedal` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InventoryType` tinyint(4) NOT NULL DEFAULT '0',
  `OverallQualityID` tinyint(4) NOT NULL DEFAULT '0',
  `AmmunitionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_sparse`
--

LOCK TABLES `item_sparse` WRITE;
/*!40000 ALTER TABLE `item_sparse` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_sparse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_sparse_locale`
--

DROP TABLE IF EXISTS `item_sparse_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_sparse_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Display3_lang` text,
  `Display2_lang` text,
  `Display1_lang` text,
  `Display_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_sparse_locale`
--

LOCK TABLES `item_sparse_locale` WRITE;
/*!40000 ALTER TABLE `item_sparse_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_sparse_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_item_enchantment`
--

DROP TABLE IF EXISTS `spell_item_enchantment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_item_enchantment` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `HordeName` text,
  `Charges` int(11) NOT NULL DEFAULT '0',
  `Effect1` int(11) NOT NULL DEFAULT '0',
  `Effect2` int(11) NOT NULL DEFAULT '0',
  `Effect3` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMin1` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMin2` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMin3` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMax1` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMax2` int(11) NOT NULL DEFAULT '0',
  `EffectPointsMax3` int(11) NOT NULL DEFAULT '0',
  `EffectArg1` int(11) NOT NULL DEFAULT '0',
  `EffectArg2` int(11) NOT NULL DEFAULT '0',
  `EffectArg3` int(11) NOT NULL DEFAULT '0',
  `ItemVisual` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `EffectScalingPoints1` float NOT NULL DEFAULT '0',
  `EffectScalingPoints2` float NOT NULL DEFAULT '0',
  `EffectScalingPoints3` float NOT NULL DEFAULT '0',
  `ScalingClass` int(11) NOT NULL DEFAULT '0',
  `Unk440_1` int(11) NOT NULL DEFAULT '0',
  `GemItemID` int(11) NOT NULL DEFAULT '0',
  `ConditionID` int(11) NOT NULL DEFAULT '0',
  `RequiredSkillID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(11) NOT NULL DEFAULT '0',
  `Unk440_2` int(11) NOT NULL DEFAULT '0',
  `Unk440_3` int(11) NOT NULL DEFAULT '0',
  `ItemLevel` int(11) NOT NULL DEFAULT '0',
  `Unk440_4` int(11) NOT NULL DEFAULT '0',
  `Unk440_5` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_item_enchantment`
--

LOCK TABLES `spell_item_enchantment` WRITE;
/*!40000 ALTER TABLE `spell_item_enchantment` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_item_enchantment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_item_enchantment_locale`
--

DROP TABLE IF EXISTS `spell_item_enchantment_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_item_enchantment_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `HordeName_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_item_enchantment_locale`
--
