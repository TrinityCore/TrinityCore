--
-- Table structure for table `achievement`
--

DROP TABLE IF EXISTS `achievement`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `achievement` (
  `Description` text,
  `Title` text,
  `Reward` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `InstanceID` smallint NOT NULL DEFAULT '0',
  `Faction` tinyint NOT NULL DEFAULT '0',
  `Supercedes` smallint NOT NULL DEFAULT '0',
  `Category` smallint NOT NULL DEFAULT '0',
  `MinimumCriteria` tinyint NOT NULL DEFAULT '0',
  `Points` tinyint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `UiOrder` smallint unsigned NOT NULL DEFAULT '0',
  `IconFileID` int NOT NULL DEFAULT '0',
  `CriteriaTree` int unsigned NOT NULL DEFAULT '0',
  `SharesCriteria` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `achievement`
--

LOCK TABLES `achievement` WRITE;
/*!40000 ALTER TABLE `achievement` DISABLE KEYS */;
/*!40000 ALTER TABLE `achievement` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `achievement_locale`
--

DROP TABLE IF EXISTS `achievement_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `achievement_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Title_lang` text,
  `Reward_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `achievement_locale`
--

LOCK TABLES `achievement_locale` WRITE;
/*!40000 ALTER TABLE `achievement_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `achievement_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `achievement_category`
--

DROP TABLE IF EXISTS `achievement_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `achievement_category` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Parent` smallint NOT NULL DEFAULT '0',
  `UiOrder` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `achievement_category`
--

LOCK TABLES `achievement_category` WRITE;
/*!40000 ALTER TABLE `achievement_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `achievement_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `achievement_category_locale`
--

DROP TABLE IF EXISTS `achievement_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `achievement_category_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `achievement_category_locale`
--

LOCK TABLES `achievement_category_locale` WRITE;
/*!40000 ALTER TABLE `achievement_category_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `achievement_category_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `animation_data`
--

DROP TABLE IF EXISTS `animation_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `animation_data` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Fallback` smallint unsigned NOT NULL DEFAULT '0',
  `BehaviorTier` tinyint unsigned NOT NULL DEFAULT '0',
  `BehaviorID` smallint NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `animation_data`
--

LOCK TABLES `animation_data` WRITE;
/*!40000 ALTER TABLE `animation_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `animation_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `anim_kit`
--

DROP TABLE IF EXISTS `anim_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `anim_kit` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OneShotDuration` int unsigned NOT NULL DEFAULT '0',
  `OneShotStopAnimKitID` smallint unsigned NOT NULL DEFAULT '0',
  `LowDefAnimKitID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `anim_kit`
--

LOCK TABLES `anim_kit` WRITE;
/*!40000 ALTER TABLE `anim_kit` DISABLE KEYS */;
/*!40000 ALTER TABLE `anim_kit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_group_member`
--

DROP TABLE IF EXISTS `area_group_member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_group_member` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint unsigned NOT NULL DEFAULT '0',
  `AreaGroupID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `area_group_member`
--

LOCK TABLES `area_group_member` WRITE;
/*!40000 ALTER TABLE `area_group_member` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_group_member` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_table`
--

DROP TABLE IF EXISTS `area_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_table` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ZoneName` text,
  `AreaName` text,
  `ContinentID` smallint unsigned NOT NULL DEFAULT '0',
  `ParentAreaID` smallint unsigned NOT NULL DEFAULT '0',
  `AreaBit` smallint NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint unsigned NOT NULL DEFAULT '0',
  `AmbienceID` smallint unsigned NOT NULL DEFAULT '0',
  `UwAmbience` smallint unsigned NOT NULL DEFAULT '0',
  `ZoneMusic` smallint unsigned NOT NULL DEFAULT '0',
  `UwZoneMusic` smallint unsigned NOT NULL DEFAULT '0',
  `ExplorationLevel` tinyint NOT NULL DEFAULT '0',
  `IntroSound` smallint unsigned NOT NULL DEFAULT '0',
  `UwIntroSound` int unsigned NOT NULL DEFAULT '0',
  `FactionGroupMask` tinyint unsigned NOT NULL DEFAULT '0',
  `AmbientMultiplier` float NOT NULL DEFAULT '0',
  `MountFlags` int NOT NULL DEFAULT '0',
  `PvpCombatWorldStateID` smallint NOT NULL DEFAULT '0',
  `WildBattlePetLevelMin` tinyint unsigned NOT NULL DEFAULT '0',
  `WildBattlePetLevelMax` tinyint unsigned NOT NULL DEFAULT '0',
  `WindSettingsID` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `LiquidTypeID1` smallint unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID2` smallint unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID3` smallint unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID4` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `area_table`
--

LOCK TABLES `area_table` WRITE;
/*!40000 ALTER TABLE `area_table` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_table_locale`
--

DROP TABLE IF EXISTS `area_table_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_table_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `area_table_locale`
--

LOCK TABLES `area_table_locale` WRITE;
/*!40000 ALTER TABLE `area_table_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_table_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_trigger`
--

DROP TABLE IF EXISTS `area_trigger`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_trigger` (
  `Message` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ContinentID` smallint unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` int NOT NULL DEFAULT '0',
  `PhaseID` smallint NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `BoxLength` float NOT NULL DEFAULT '0',
  `BoxWidth` float NOT NULL DEFAULT '0',
  `BoxHeight` float NOT NULL DEFAULT '0',
  `BoxYaw` float NOT NULL DEFAULT '0',
  `ShapeType` tinyint NOT NULL DEFAULT '0',
  `ShapeID` smallint NOT NULL DEFAULT '0',
  `AreaTriggerActionSetID` int NOT NULL DEFAULT '0',
  `Flags` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `area_trigger`
--

LOCK TABLES `area_trigger` WRITE;
/*!40000 ALTER TABLE `area_trigger` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_trigger` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_trigger_locale`
--

DROP TABLE IF EXISTS `area_trigger_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_trigger_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Message_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `area_trigger_locale`
--

LOCK TABLES `area_trigger_locale` WRITE;
/*!40000 ALTER TABLE `area_trigger_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_trigger_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `area_trigger_action_set`
--

DROP TABLE IF EXISTS `area_trigger_action_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area_trigger_action_set` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `area_trigger_action_set`
--

LOCK TABLES `area_trigger_action_set` WRITE;
/*!40000 ALTER TABLE `area_trigger_action_set` DISABLE KEYS */;
/*!40000 ALTER TABLE `area_trigger_action_set` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `armor_location`
--

DROP TABLE IF EXISTS `armor_location`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `armor_location` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Clothmodifier` float NOT NULL DEFAULT '0',
  `Leathermodifier` float NOT NULL DEFAULT '0',
  `Chainmodifier` float NOT NULL DEFAULT '0',
  `Platemodifier` float NOT NULL DEFAULT '0',
  `Modifier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `armor_location`
--

LOCK TABLES `armor_location` WRITE;
/*!40000 ALTER TABLE `armor_location` DISABLE KEYS */;
/*!40000 ALTER TABLE `armor_location` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auction_house`
--

DROP TABLE IF EXISTS `auction_house`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `auction_house` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `FactionID` smallint unsigned NOT NULL DEFAULT '0',
  `DepositRate` tinyint unsigned NOT NULL DEFAULT '0',
  `ConsignmentRate` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auction_house`
--

LOCK TABLES `auction_house` WRITE;
/*!40000 ALTER TABLE `auction_house` DISABLE KEYS */;
/*!40000 ALTER TABLE `auction_house` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auction_house_locale`
--

DROP TABLE IF EXISTS `auction_house_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `auction_house_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `auction_house_locale`
--

LOCK TABLES `auction_house_locale` WRITE;
/*!40000 ALTER TABLE `auction_house_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `auction_house_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bank_bag_slot_prices`
--

DROP TABLE IF EXISTS `bank_bag_slot_prices`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bank_bag_slot_prices` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Cost` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bank_bag_slot_prices`
--

LOCK TABLES `bank_bag_slot_prices` WRITE;
/*!40000 ALTER TABLE `bank_bag_slot_prices` DISABLE KEYS */;
/*!40000 ALTER TABLE `bank_bag_slot_prices` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `banned_addons`
--

DROP TABLE IF EXISTS `banned_addons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `banned_addons` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Version` text,
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `banned_addons`
--

LOCK TABLES `banned_addons` WRITE;
/*!40000 ALTER TABLE `banned_addons` DISABLE KEYS */;
/*!40000 ALTER TABLE `banned_addons` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `barber_shop_style`
--

DROP TABLE IF EXISTS `barber_shop_style`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `barber_shop_style` (
  `DisplayName` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `CostModifier` float NOT NULL DEFAULT '0',
  `Race` tinyint unsigned NOT NULL DEFAULT '0',
  `Sex` tinyint unsigned NOT NULL DEFAULT '0',
  `Data` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `barber_shop_style`
--

LOCK TABLES `barber_shop_style` WRITE;
/*!40000 ALTER TABLE `barber_shop_style` DISABLE KEYS */;
/*!40000 ALTER TABLE `barber_shop_style` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `barber_shop_style_locale`
--

DROP TABLE IF EXISTS `barber_shop_style_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `barber_shop_style_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `barber_shop_style_locale`
--

LOCK TABLES `barber_shop_style_locale` WRITE;
/*!40000 ALTER TABLE `barber_shop_style_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `barber_shop_style_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_ability`
--

DROP TABLE IF EXISTS `battle_pet_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_ability` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `PetTypeEnum` tinyint NOT NULL DEFAULT '0',
  `Cooldown` int unsigned NOT NULL DEFAULT '0',
  `BattlePetVisualID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_ability`
--

LOCK TABLES `battle_pet_ability` WRITE;
/*!40000 ALTER TABLE `battle_pet_ability` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_ability` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_ability_locale`
--

DROP TABLE IF EXISTS `battle_pet_ability_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_ability_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `battle_pet_ability_locale`
--

LOCK TABLES `battle_pet_ability_locale` WRITE;
/*!40000 ALTER TABLE `battle_pet_ability_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_ability_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_breed_quality`
--

DROP TABLE IF EXISTS `battle_pet_breed_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_breed_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `StateMultiplier` float NOT NULL DEFAULT '0',
  `QualityEnum` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_breed_quality`
--

LOCK TABLES `battle_pet_breed_quality` WRITE;
/*!40000 ALTER TABLE `battle_pet_breed_quality` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_breed_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_breed_state`
--

DROP TABLE IF EXISTS `battle_pet_breed_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_breed_state` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `BattlePetStateID` tinyint unsigned NOT NULL DEFAULT '0',
  `Value` smallint unsigned NOT NULL DEFAULT '0',
  `BattlePetBreedID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_breed_state`
--

LOCK TABLES `battle_pet_breed_state` WRITE;
/*!40000 ALTER TABLE `battle_pet_breed_state` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_breed_state` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_species`
--

DROP TABLE IF EXISTS `battle_pet_species`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_species` (
  `Description` text,
  `SourceText` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CreatureID` int NOT NULL DEFAULT '0',
  `SummonSpellID` int NOT NULL DEFAULT '0',
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `PetTypeEnum` tinyint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint NOT NULL DEFAULT '0',
  `CardUIModelSceneID` int NOT NULL DEFAULT '0',
  `LoadoutUIModelSceneID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_species`
--

LOCK TABLES `battle_pet_species` WRITE;
/*!40000 ALTER TABLE `battle_pet_species` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_species` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_species_locale`
--

DROP TABLE IF EXISTS `battle_pet_species_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_species_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `SourceText_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `battle_pet_species_locale`
--

LOCK TABLES `battle_pet_species_locale` WRITE;
/*!40000 ALTER TABLE `battle_pet_species_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_species_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_species_state`
--

DROP TABLE IF EXISTS `battle_pet_species_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battle_pet_species_state` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `BattlePetStateID` tinyint unsigned NOT NULL DEFAULT '0',
  `Value` int NOT NULL DEFAULT '0',
  `BattlePetSpeciesID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_species_state`
--

LOCK TABLES `battle_pet_species_state` WRITE;
/*!40000 ALTER TABLE `battle_pet_species_state` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_species_state` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlemaster_list`
--

DROP TABLE IF EXISTS `battlemaster_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battlemaster_list` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `GameType` text,
  `ShortDescription` text,
  `LongDescription` text,
  `InstanceType` tinyint NOT NULL DEFAULT '0',
  `MinLevel` tinyint NOT NULL DEFAULT '0',
  `MaxLevel` tinyint NOT NULL DEFAULT '0',
  `RatedPlayers` tinyint NOT NULL DEFAULT '0',
  `MinPlayers` tinyint NOT NULL DEFAULT '0',
  `MaxPlayers` int NOT NULL DEFAULT '0',
  `GroupsAllowed` tinyint NOT NULL DEFAULT '0',
  `MaxGroupSize` tinyint NOT NULL DEFAULT '0',
  `HolidayWorldState` smallint NOT NULL DEFAULT '0',
  `Flags` tinyint NOT NULL DEFAULT '0',
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `RequiredPlayerConditionID` int NOT NULL DEFAULT '0',
  `Unknown1153_0` int NOT NULL DEFAULT '0',
  `Unknown1153_1` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlemaster_list`
--

LOCK TABLES `battlemaster_list` WRITE;
/*!40000 ALTER TABLE `battlemaster_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlemaster_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlemaster_list_locale`
--

DROP TABLE IF EXISTS `battlemaster_list_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battlemaster_list_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `GameType_lang` text,
  `ShortDescription_lang` text,
  `LongDescription_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `battlemaster_list_locale`
--

LOCK TABLES `battlemaster_list_locale` WRITE;
/*!40000 ALTER TABLE `battlemaster_list_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlemaster_list_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlemaster_list_x_map`
--

DROP TABLE IF EXISTS `battlemaster_list_x_map`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `battlemaster_list_x_map` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MapID` int NOT NULL DEFAULT '0',
  `BattlemasterListID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlemaster_list_x_map`
--

LOCK TABLES `battlemaster_list_x_map` WRITE;
/*!40000 ALTER TABLE `battlemaster_list_x_map` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlemaster_list_x_map` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cfg_categories`
--

DROP TABLE IF EXISTS `cfg_categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cfg_categories` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `LocaleMask` smallint unsigned NOT NULL DEFAULT '0',
  `CreateCharsetMask` tinyint unsigned NOT NULL DEFAULT '0',
  `ExistingCharsetMask` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `Order` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cfg_categories`
--

LOCK TABLES `cfg_categories` WRITE;
/*!40000 ALTER TABLE `cfg_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `cfg_categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cfg_categories_locale`
--

DROP TABLE IF EXISTS `cfg_categories_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cfg_categories_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `cfg_categories_locale`
--

LOCK TABLES `cfg_categories_locale` WRITE;
/*!40000 ALTER TABLE `cfg_categories_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `cfg_categories_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cfg_regions`
--

DROP TABLE IF EXISTS `cfg_regions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cfg_regions` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Tag` text,
  `RegionID` smallint unsigned NOT NULL DEFAULT '0',
  `Raidorigin` int unsigned NOT NULL DEFAULT '0',
  `RegionGroupMask` tinyint unsigned NOT NULL DEFAULT '0',
  `ChallengeOrigin` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cfg_regions`
--

LOCK TABLES `cfg_regions` WRITE;
/*!40000 ALTER TABLE `cfg_regions` DISABLE KEYS */;
/*!40000 ALTER TABLE `cfg_regions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `char_titles`
--

DROP TABLE IF EXISTS `char_titles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `char_titles` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Name1` text,
  `MaskID` smallint NOT NULL DEFAULT '0',
  `Flags` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `char_titles`
--

LOCK TABLES `char_titles` WRITE;
/*!40000 ALTER TABLE `char_titles` DISABLE KEYS */;
/*!40000 ALTER TABLE `char_titles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `char_titles_locale`
--

DROP TABLE IF EXISTS `char_titles_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `char_titles_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name1_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `char_titles_locale`
--

LOCK TABLES `char_titles_locale` WRITE;
/*!40000 ALTER TABLE `char_titles_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `char_titles_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `character_loadout`
--

DROP TABLE IF EXISTS `character_loadout`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_loadout` (
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrClassID` tinyint NOT NULL DEFAULT '0',
  `Purpose` int NOT NULL DEFAULT '0',
  `ItemContext` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `character_loadout`
--

LOCK TABLES `character_loadout` WRITE;
/*!40000 ALTER TABLE `character_loadout` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_loadout` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `character_loadout_item`
--

DROP TABLE IF EXISTS `character_loadout_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_loadout_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CharacterLoadoutID` smallint unsigned NOT NULL DEFAULT '0',
  `ItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `character_loadout_item`
--

LOCK TABLES `character_loadout_item` WRITE;
/*!40000 ALTER TABLE `character_loadout_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_loadout_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chat_channels`
--

DROP TABLE IF EXISTS `chat_channels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chat_channels` (
  `Name` text,
  `Shortcut` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `FactionGroup` tinyint NOT NULL DEFAULT '0',
  `Ruleset` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chat_channels`
--

LOCK TABLES `chat_channels` WRITE;
/*!40000 ALTER TABLE `chat_channels` DISABLE KEYS */;
/*!40000 ALTER TABLE `chat_channels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chat_channels_locale`
--

DROP TABLE IF EXISTS `chat_channels_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chat_channels_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Shortcut_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chat_channels_locale`
--

LOCK TABLES `chat_channels_locale` WRITE;
/*!40000 ALTER TABLE `chat_channels_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chat_channels_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_class_ui_display`
--

DROP TABLE IF EXISTS `chr_class_ui_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_class_ui_display` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrClassesID` tinyint unsigned NOT NULL DEFAULT '0',
  `AdvGuidePlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `SplashPlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_class_ui_display`
--

LOCK TABLES `chr_class_ui_display` WRITE;
/*!40000 ALTER TABLE `chr_class_ui_display` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_class_ui_display` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_classes`
--

DROP TABLE IF EXISTS `chr_classes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_classes` (
  `Name` text,
  `Filename` text,
  `NameMale` text,
  `NameFemale` text,
  `PetNameToken` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CreateScreenFileDataID` int unsigned NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int unsigned NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `StartingLevel` int NOT NULL DEFAULT '0',
  `SpellTextureBlobFileDataID` int unsigned NOT NULL DEFAULT '0',
  `ArmorTypeMask` int unsigned NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint unsigned NOT NULL DEFAULT '0',
  `DefaultSpec` smallint unsigned NOT NULL DEFAULT '0',
  `HasStrengthAttackBonus` tinyint unsigned NOT NULL DEFAULT '0',
  `PrimaryStatPriority` tinyint unsigned NOT NULL DEFAULT '0',
  `DisplayPower` tinyint NOT NULL DEFAULT '0',
  `RangedAttackPowerPerAgility` tinyint unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerAgility` tinyint unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerStrength` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint unsigned NOT NULL DEFAULT '0',
  `RolesMask` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageBonusStat` tinyint unsigned NOT NULL DEFAULT '0',
  `HasRelicSlot` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_classes`
--

LOCK TABLES `chr_classes` WRITE;
/*!40000 ALTER TABLE `chr_classes` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_classes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_classes_locale`
--

DROP TABLE IF EXISTS `chr_classes_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_classes_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameMale_lang` text,
  `NameFemale_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chr_classes_locale`
--

LOCK TABLES `chr_classes_locale` WRITE;
/*!40000 ALTER TABLE `chr_classes_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_classes_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_classes_x_power_types`
--

DROP TABLE IF EXISTS `chr_classes_x_power_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_classes_x_power_types` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint NOT NULL DEFAULT '0',
  `ClassID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_classes_x_power_types`
--

LOCK TABLES `chr_classes_x_power_types` WRITE;
/*!40000 ALTER TABLE `chr_classes_x_power_types` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_classes_x_power_types` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_choice`
--

DROP TABLE IF EXISTS `chr_customization_choice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_choice` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationOptionID` int unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int NOT NULL DEFAULT '0',
  `ChrCustomizationVisReqID` int NOT NULL DEFAULT '0',
  `OrderIndex` smallint unsigned NOT NULL DEFAULT '0',
  `UiOrderIndex` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `AddedInPatch` int NOT NULL DEFAULT '0',
  `SoundKitID` int NOT NULL DEFAULT '0',
  `SwatchColor1` int NOT NULL DEFAULT '0',
  `SwatchColor2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_choice`
--

LOCK TABLES `chr_customization_choice` WRITE;
/*!40000 ALTER TABLE `chr_customization_choice` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_choice` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_choice_locale`
--

DROP TABLE IF EXISTS `chr_customization_choice_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_choice_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chr_customization_choice_locale`
--

LOCK TABLES `chr_customization_choice_locale` WRITE;
/*!40000 ALTER TABLE `chr_customization_choice_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_choice_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_display_info`
--

DROP TABLE IF EXISTS `chr_customization_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_display_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellShapeshiftFormID` int NOT NULL DEFAULT '0',
  `CreatureDisplayInfoID` int NOT NULL DEFAULT '0',
  `BarberShopMinCameraDistance` float NOT NULL DEFAULT '0',
  `BarberShopHeightOffset` float NOT NULL DEFAULT '0',
  `BarberShopCameraZoomOffset` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_display_info`
--

LOCK TABLES `chr_customization_display_info` WRITE;
/*!40000 ALTER TABLE `chr_customization_display_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_display_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_element`
--

DROP TABLE IF EXISTS `chr_customization_element`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_element` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationChoiceID` int NOT NULL DEFAULT '0',
  `RelatedChrCustomizationChoiceID` int NOT NULL DEFAULT '0',
  `ChrCustomizationGeosetID` int NOT NULL DEFAULT '0',
  `ChrCustomizationSkinnedModelID` int NOT NULL DEFAULT '0',
  `ChrCustomizationMaterialID` int NOT NULL DEFAULT '0',
  `ChrCustomizationBoneSetID` int NOT NULL DEFAULT '0',
  `ChrCustomizationCondModelID` int NOT NULL DEFAULT '0',
  `ChrCustomizationDisplayInfoID` int NOT NULL DEFAULT '0',
  `ChrCustItemGeoModifyID` int NOT NULL DEFAULT '0',
  `ChrCustomizationVoiceID` int NOT NULL DEFAULT '0',
  `AnimKitID` int NOT NULL DEFAULT '0',
  `ParticleColorID` int NOT NULL DEFAULT '0',
  `ChrCustGeoComponentLinkID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_element`
--

LOCK TABLES `chr_customization_element` WRITE;
/*!40000 ALTER TABLE `chr_customization_element` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_element` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_option`
--

DROP TABLE IF EXISTS `chr_customization_option`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_option` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SecondaryID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ChrModelID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `ChrCustomizationCategoryID` int NOT NULL DEFAULT '0',
  `OptionType` int NOT NULL DEFAULT '0',
  `BarberShopCostModifier` float NOT NULL DEFAULT '0',
  `ChrCustomizationID` int NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int NOT NULL DEFAULT '0',
  `SecondaryOrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_option`
--

LOCK TABLES `chr_customization_option` WRITE;
/*!40000 ALTER TABLE `chr_customization_option` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_option` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_option_locale`
--

DROP TABLE IF EXISTS `chr_customization_option_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_option_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chr_customization_option_locale`
--

LOCK TABLES `chr_customization_option_locale` WRITE;
/*!40000 ALTER TABLE `chr_customization_option_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_option_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_req`
--

DROP TABLE IF EXISTS `chr_customization_req`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_req` (
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `ReqSource` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `AchievementID` int NOT NULL DEFAULT '0',
  `QuestID` int NOT NULL DEFAULT '0',
  `OverrideArchive` int NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_req`
--

LOCK TABLES `chr_customization_req` WRITE;
/*!40000 ALTER TABLE `chr_customization_req` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_req` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_req_locale`
--

DROP TABLE IF EXISTS `chr_customization_req_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_req_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ReqSource_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chr_customization_req_locale`
--

LOCK TABLES `chr_customization_req_locale` WRITE;
/*!40000 ALTER TABLE `chr_customization_req_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_req_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_customization_req_choice`
--

DROP TABLE IF EXISTS `chr_customization_req_choice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_customization_req_choice` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationChoiceID` int NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_customization_req_choice`
--

LOCK TABLES `chr_customization_req_choice` WRITE;
/*!40000 ALTER TABLE `chr_customization_req_choice` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_customization_req_choice` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_model`
--

DROP TABLE IF EXISTS `chr_model`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_model` (
  `FaceCustomizationOffsetX` float NOT NULL DEFAULT '0',
  `FaceCustomizationOffsetY` float NOT NULL DEFAULT '0',
  `FaceCustomizationOffsetZ` float NOT NULL DEFAULT '0',
  `CustomizeOffsetX` float NOT NULL DEFAULT '0',
  `CustomizeOffsetY` float NOT NULL DEFAULT '0',
  `CustomizeOffsetZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Sex` tinyint NOT NULL DEFAULT '0',
  `DisplayID` int unsigned NOT NULL DEFAULT '0',
  `CharComponentTextureLayoutID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SkeletonFileDataID` int NOT NULL DEFAULT '0',
  `ModelFallbackChrModelID` int NOT NULL DEFAULT '0',
  `TextureFallbackChrModelID` int NOT NULL DEFAULT '0',
  `HelmVisFallbackChrModelID` int NOT NULL DEFAULT '0',
  `CustomizeScale` float NOT NULL DEFAULT '0',
  `CustomizeFacing` float NOT NULL DEFAULT '0',
  `CameraDistanceOffset` float NOT NULL DEFAULT '0',
  `BarberShopCameraOffsetScale` float NOT NULL DEFAULT '0',
  `BarberShopCameraRotationFacing` float NOT NULL DEFAULT '0',
  `BarberShopCameraRotationOffset` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_model`
--

LOCK TABLES `chr_model` WRITE;
/*!40000 ALTER TABLE `chr_model` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_model` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_race_x_chr_model`
--

DROP TABLE IF EXISTS `chr_race_x_chr_model`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_race_x_chr_model` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrRacesID` int unsigned NOT NULL DEFAULT '0',
  `ChrModelID` int NOT NULL DEFAULT '0',
  `Sex` int NOT NULL DEFAULT '0',
  `AllowedTransmogSlots` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_race_x_chr_model`
--

LOCK TABLES `chr_race_x_chr_model` WRITE;
/*!40000 ALTER TABLE `chr_race_x_chr_model` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_race_x_chr_model` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_races`
--

DROP TABLE IF EXISTS `chr_races`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_races` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClientPrefix` text,
  `ClientFileString` text,
  `Name` text,
  `NameFemale` text,
  `NameLowercase` text,
  `NameFemaleLowercase` text,
  `LoreName` text,
  `LoreNameFemale` text,
  `LoreNameLower` text,
  `LoreNameLowerFemale` text,
  `LoreDescription` text,
  `ShortName` text,
  `ShortNameFemale` text,
  `ShortNameLower` text,
  `ShortNameLowerFemale` text,
  `Flags` int NOT NULL DEFAULT '0',
  `MaleDisplayID` int unsigned NOT NULL DEFAULT '0',
  `FemaleDisplayID` int unsigned NOT NULL DEFAULT '0',
  `HighResMaleDisplayID` int unsigned NOT NULL DEFAULT '0',
  `HighResFemaleDisplayID` int unsigned NOT NULL DEFAULT '0',
  `ResSicknessSpellID` int NOT NULL DEFAULT '0',
  `SplashSoundID` int NOT NULL DEFAULT '0',
  `CreateScreenFileDataID` int NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID1` int unsigned NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID2` int unsigned NOT NULL DEFAULT '0',
  `AlteredFormStartVisualKitID3` int unsigned NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID1` int unsigned NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID2` int unsigned NOT NULL DEFAULT '0',
  `AlteredFormFinishVisualKitID3` int unsigned NOT NULL DEFAULT '0',
  `HeritageArmorAchievementID` int NOT NULL DEFAULT '0',
  `StartingLevel` int NOT NULL DEFAULT '0',
  `UiDisplayOrder` int NOT NULL DEFAULT '0',
  `PlayableRaceBit` int NOT NULL DEFAULT '0',
  `FemaleSkeletonFileDataID` int NOT NULL DEFAULT '0',
  `MaleSkeletonFileDataID` int NOT NULL DEFAULT '0',
  `HelmetAnimScalingRaceID` int NOT NULL DEFAULT '0',
  `TransmogrifyDisabledSlotMask` int NOT NULL DEFAULT '0',
  `AlteredFormCustomizeOffsetFallback1` float NOT NULL DEFAULT '0',
  `AlteredFormCustomizeOffsetFallback2` float NOT NULL DEFAULT '0',
  `AlteredFormCustomizeOffsetFallback3` float NOT NULL DEFAULT '0',
  `AlteredFormCustomizeRotationFallback` float NOT NULL DEFAULT '0',
  `Unknown901_01` float NOT NULL DEFAULT '0',
  `Unknown901_02` float NOT NULL DEFAULT '0',
  `Unknown901_03` float NOT NULL DEFAULT '0',
  `Unknown901_11` float NOT NULL DEFAULT '0',
  `Unknown901_12` float NOT NULL DEFAULT '0',
  `Unknown901_13` float NOT NULL DEFAULT '0',
  `FactionID` smallint NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint NOT NULL DEFAULT '0',
  `BaseLanguage` tinyint NOT NULL DEFAULT '0',
  `CreatureType` tinyint NOT NULL DEFAULT '0',
  `Alliance` tinyint NOT NULL DEFAULT '0',
  `RaceRelated` tinyint NOT NULL DEFAULT '0',
  `UnalteredVisualRaceID` tinyint NOT NULL DEFAULT '0',
  `DefaultClassID` tinyint NOT NULL DEFAULT '0',
  `NeutralRaceID` tinyint NOT NULL DEFAULT '0',
  `MaleModelFallbackRaceID` tinyint NOT NULL DEFAULT '0',
  `MaleModelFallbackSex` tinyint NOT NULL DEFAULT '0',
  `FemaleModelFallbackRaceID` tinyint NOT NULL DEFAULT '0',
  `FemaleModelFallbackSex` tinyint NOT NULL DEFAULT '0',
  `MaleTextureFallbackRaceID` tinyint NOT NULL DEFAULT '0',
  `MaleTextureFallbackSex` tinyint NOT NULL DEFAULT '0',
  `FemaleTextureFallbackRaceID` tinyint NOT NULL DEFAULT '0',
  `FemaleTextureFallbackSex` tinyint NOT NULL DEFAULT '0',
  `UnalteredVisualCustomizationRaceID` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chr_races`
--

LOCK TABLES `chr_races` WRITE;
/*!40000 ALTER TABLE `chr_races` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_races` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chr_races_locale`
--

DROP TABLE IF EXISTS `chr_races_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `chr_races_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameFemale_lang` text,
  `NameLowercase_lang` text,
  `NameFemaleLowercase_lang` text,
  `LoreName_lang` text,
  `LoreNameFemale_lang` text,
  `LoreNameLower_lang` text,
  `LoreNameLowerFemale_lang` text,
  `LoreDescription_lang` text,
  `ShortName_lang` text,
  `ShortNameFemale_lang` text,
  `ShortNameLower_lang` text,
  `ShortNameLowerFemale_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `chr_races_locale`
--

LOCK TABLES `chr_races_locale` WRITE;
/*!40000 ALTER TABLE `chr_races_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `chr_races_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cinematic_camera`
--

DROP TABLE IF EXISTS `cinematic_camera`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cinematic_camera` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OriginX` float NOT NULL DEFAULT '0',
  `OriginY` float NOT NULL DEFAULT '0',
  `OriginZ` float NOT NULL DEFAULT '0',
  `SoundID` int unsigned NOT NULL DEFAULT '0',
  `OriginFacing` float NOT NULL DEFAULT '0',
  `FileDataID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cinematic_camera`
--

LOCK TABLES `cinematic_camera` WRITE;
/*!40000 ALTER TABLE `cinematic_camera` DISABLE KEYS */;
/*!40000 ALTER TABLE `cinematic_camera` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cinematic_sequences`
--

DROP TABLE IF EXISTS `cinematic_sequences`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cinematic_sequences` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SoundID` int unsigned NOT NULL DEFAULT '0',
  `Camera1` smallint unsigned NOT NULL DEFAULT '0',
  `Camera2` smallint unsigned NOT NULL DEFAULT '0',
  `Camera3` smallint unsigned NOT NULL DEFAULT '0',
  `Camera4` smallint unsigned NOT NULL DEFAULT '0',
  `Camera5` smallint unsigned NOT NULL DEFAULT '0',
  `Camera6` smallint unsigned NOT NULL DEFAULT '0',
  `Camera7` smallint unsigned NOT NULL DEFAULT '0',
  `Camera8` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cinematic_sequences`
--

LOCK TABLES `cinematic_sequences` WRITE;
/*!40000 ALTER TABLE `cinematic_sequences` DISABLE KEYS */;
/*!40000 ALTER TABLE `cinematic_sequences` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conditional_chr_model`
--

DROP TABLE IF EXISTS `conditional_chr_model`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `conditional_chr_model` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrModelID` int unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int NOT NULL DEFAULT '0',
  `PlayerConditionID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ChrCustomizationCategoryID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conditional_chr_model`
--

LOCK TABLES `conditional_chr_model` WRITE;
/*!40000 ALTER TABLE `conditional_chr_model` DISABLE KEYS */;
/*!40000 ALTER TABLE `conditional_chr_model` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conditional_content_tuning`
--

DROP TABLE IF EXISTS `conditional_content_tuning`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `conditional_content_tuning` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `RedirectContentTuningID` int NOT NULL DEFAULT '0',
  `RedirectFlag` int NOT NULL DEFAULT '0',
  `ParentContentTuningID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conditional_content_tuning`
--

LOCK TABLES `conditional_content_tuning` WRITE;
/*!40000 ALTER TABLE `conditional_content_tuning` DISABLE KEYS */;
/*!40000 ALTER TABLE `conditional_content_tuning` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `content_tuning`
--

DROP TABLE IF EXISTS `content_tuning`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `content_tuning` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MinLevel` int NOT NULL DEFAULT '0',
  `MaxLevel` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ExpectedStatModID` int NOT NULL DEFAULT '0',
  `DifficultyESMID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `content_tuning`
--

LOCK TABLES `content_tuning` WRITE;
/*!40000 ALTER TABLE `content_tuning` DISABLE KEYS */;
/*!40000 ALTER TABLE `content_tuning` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conversation_line`
--

DROP TABLE IF EXISTS `conversation_line`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `conversation_line` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `BroadcastTextID` int unsigned NOT NULL DEFAULT '0',
  `SpellVisualKitID` int unsigned NOT NULL DEFAULT '0',
  `AdditionalDuration` int NOT NULL DEFAULT '0',
  `NextConversationLineID` smallint unsigned NOT NULL DEFAULT '0',
  `AnimKitID` smallint unsigned NOT NULL DEFAULT '0',
  `SpeechType` tinyint unsigned NOT NULL DEFAULT '0',
  `StartAnimation` tinyint unsigned NOT NULL DEFAULT '0',
  `EndAnimation` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conversation_line`
--

LOCK TABLES `conversation_line` WRITE;
/*!40000 ALTER TABLE `conversation_line` DISABLE KEYS */;
/*!40000 ALTER TABLE `conversation_line` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_display_info`
--

DROP TABLE IF EXISTS `creature_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_display_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ModelID` smallint unsigned NOT NULL DEFAULT '0',
  `SoundID` smallint unsigned NOT NULL DEFAULT '0',
  `SizeClass` tinyint NOT NULL DEFAULT '0',
  `CreatureModelScale` float NOT NULL DEFAULT '0',
  `CreatureModelAlpha` tinyint unsigned NOT NULL DEFAULT '0',
  `BloodID` tinyint unsigned NOT NULL DEFAULT '0',
  `ExtendedDisplayInfoID` int NOT NULL DEFAULT '0',
  `NPCSoundID` smallint unsigned NOT NULL DEFAULT '0',
  `ParticleColorID` smallint unsigned NOT NULL DEFAULT '0',
  `PortraitCreatureDisplayInfoID` int NOT NULL DEFAULT '0',
  `PortraitTextureFileDataID` int NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int NOT NULL DEFAULT '0',
  `PlayerOverrideScale` float NOT NULL DEFAULT '0',
  `PetInstanceScale` float NOT NULL DEFAULT '0',
  `UnarmedWeaponType` tinyint NOT NULL DEFAULT '0',
  `MountPoofSpellVisualKitID` int NOT NULL DEFAULT '0',
  `DissolveEffectID` int NOT NULL DEFAULT '0',
  `Gender` tinyint NOT NULL DEFAULT '0',
  `DissolveOutEffectID` int NOT NULL DEFAULT '0',
  `CreatureModelMinLod` tinyint NOT NULL DEFAULT '0',
  `Unknown1154` smallint unsigned NOT NULL DEFAULT '0',
  `TextureVariationFileDataID1` int NOT NULL DEFAULT '0',
  `TextureVariationFileDataID2` int NOT NULL DEFAULT '0',
  `TextureVariationFileDataID3` int NOT NULL DEFAULT '0',
  `TextureVariationFileDataID4` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creature_display_info`
--

LOCK TABLES `creature_display_info` WRITE;
/*!40000 ALTER TABLE `creature_display_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_display_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_display_info_extra`
--

DROP TABLE IF EXISTS `creature_display_info_extra`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_display_info_extra` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DisplayRaceID` tinyint NOT NULL DEFAULT '0',
  `DisplaySexID` tinyint NOT NULL DEFAULT '0',
  `DisplayClassID` tinyint NOT NULL DEFAULT '0',
  `SkinID` tinyint NOT NULL DEFAULT '0',
  `FaceID` tinyint NOT NULL DEFAULT '0',
  `HairStyleID` tinyint NOT NULL DEFAULT '0',
  `HairColorID` tinyint NOT NULL DEFAULT '0',
  `FacialHairID` tinyint NOT NULL DEFAULT '0',
  `Flags` tinyint NOT NULL DEFAULT '0',
  `BakeMaterialResourcesID` int NOT NULL DEFAULT '0',
  `HDBakeMaterialResourcesID` int NOT NULL DEFAULT '0',
  `CustomDisplayOption1` tinyint unsigned NOT NULL DEFAULT '0',
  `CustomDisplayOption2` tinyint unsigned NOT NULL DEFAULT '0',
  `CustomDisplayOption3` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creature_display_info_extra`
--

LOCK TABLES `creature_display_info_extra` WRITE;
/*!40000 ALTER TABLE `creature_display_info_extra` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_display_info_extra` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_family`
--

DROP TABLE IF EXISTS `creature_family`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_family` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `MinScale` float NOT NULL DEFAULT '0',
  `MinScaleLevel` tinyint NOT NULL DEFAULT '0',
  `MaxScale` float NOT NULL DEFAULT '0',
  `MaxScaleLevel` tinyint NOT NULL DEFAULT '0',
  `PetFoodMask` smallint NOT NULL DEFAULT '0',
  `PetTalentType` tinyint NOT NULL DEFAULT '0',
  `CategoryEnumID` int NOT NULL DEFAULT '0',
  `IconFileID` int NOT NULL DEFAULT '0',
  `SkillLine1` smallint NOT NULL DEFAULT '0',
  `SkillLine2` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creature_family`
--

LOCK TABLES `creature_family` WRITE;
/*!40000 ALTER TABLE `creature_family` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_family` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_family_locale`
--

DROP TABLE IF EXISTS `creature_family_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_family_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `creature_family_locale`
--

LOCK TABLES `creature_family_locale` WRITE;
/*!40000 ALTER TABLE `creature_family_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_family_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_model_data`
--

DROP TABLE IF EXISTS `creature_model_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_model_data` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `GeoBox1` float NOT NULL DEFAULT '0',
  `GeoBox2` float NOT NULL DEFAULT '0',
  `GeoBox3` float NOT NULL DEFAULT '0',
  `GeoBox4` float NOT NULL DEFAULT '0',
  `GeoBox5` float NOT NULL DEFAULT '0',
  `GeoBox6` float NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `FileDataID` int unsigned NOT NULL DEFAULT '0',
  `BloodID` int unsigned NOT NULL DEFAULT '0',
  `FootprintTextureID` int unsigned NOT NULL DEFAULT '0',
  `FootprintTextureLength` float NOT NULL DEFAULT '0',
  `FootprintTextureWidth` float NOT NULL DEFAULT '0',
  `FootprintParticleScale` float NOT NULL DEFAULT '0',
  `FoleyMaterialID` int unsigned NOT NULL DEFAULT '0',
  `FootstepCameraEffectID` int unsigned NOT NULL DEFAULT '0',
  `DeathThudCameraEffectID` int unsigned NOT NULL DEFAULT '0',
  `SoundID` int unsigned NOT NULL DEFAULT '0',
  `SizeClass` int unsigned NOT NULL DEFAULT '0',
  `CollisionWidth` float NOT NULL DEFAULT '0',
  `CollisionHeight` float NOT NULL DEFAULT '0',
  `WorldEffectScale` float NOT NULL DEFAULT '0',
  `CreatureGeosetDataID` int unsigned NOT NULL DEFAULT '0',
  `HoverHeight` float NOT NULL DEFAULT '0',
  `AttachedEffectScale` float NOT NULL DEFAULT '0',
  `ModelScale` float NOT NULL DEFAULT '0',
  `MissileCollisionRadius` float NOT NULL DEFAULT '0',
  `MissileCollisionPush` float NOT NULL DEFAULT '0',
  `MissileCollisionRaise` float NOT NULL DEFAULT '0',
  `MountHeight` float NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `OverrideSelectionRadius` float NOT NULL DEFAULT '0',
  `TamedPetBaseScale` float NOT NULL DEFAULT '0',
  `Unknown1154` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creature_model_data`
--

LOCK TABLES `creature_model_data` WRITE;
/*!40000 ALTER TABLE `creature_model_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_model_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_type`
--

DROP TABLE IF EXISTS `creature_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_type` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creature_type`
--

LOCK TABLES `creature_type` WRITE;
/*!40000 ALTER TABLE `creature_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_type_locale`
--

DROP TABLE IF EXISTS `creature_type_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `creature_type_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `creature_type_locale`
--

LOCK TABLES `creature_type_locale` WRITE;
/*!40000 ALTER TABLE `creature_type_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_type_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `criteria`
--

DROP TABLE IF EXISTS `criteria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `criteria` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` smallint NOT NULL DEFAULT '0',
  `Asset` int NOT NULL DEFAULT '0',
  `ModifierTreeId` int unsigned NOT NULL DEFAULT '0',
  `StartEvent` int NOT NULL DEFAULT '0',
  `StartAsset` int NOT NULL DEFAULT '0',
  `StartTimer` smallint unsigned NOT NULL DEFAULT '0',
  `FailEvent` int NOT NULL DEFAULT '0',
  `FailAsset` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `EligibilityWorldStateID` smallint NOT NULL DEFAULT '0',
  `EligibilityWorldStateValue` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `criteria`
--

LOCK TABLES `criteria` WRITE;
/*!40000 ALTER TABLE `criteria` DISABLE KEYS */;
/*!40000 ALTER TABLE `criteria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `criteria_tree`
--

DROP TABLE IF EXISTS `criteria_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `criteria_tree` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Parent` int unsigned NOT NULL DEFAULT '0',
  `Amount` int unsigned NOT NULL DEFAULT '0',
  `Operator` int NOT NULL DEFAULT '0',
  `CriteriaID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `criteria_tree`
--

LOCK TABLES `criteria_tree` WRITE;
/*!40000 ALTER TABLE `criteria_tree` DISABLE KEYS */;
/*!40000 ALTER TABLE `criteria_tree` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `criteria_tree_locale`
--

DROP TABLE IF EXISTS `criteria_tree_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `criteria_tree_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `criteria_tree_locale`
--

LOCK TABLES `criteria_tree_locale` WRITE;
/*!40000 ALTER TABLE `criteria_tree_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `criteria_tree_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currency_container`
--

DROP TABLE IF EXISTS `currency_container`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_container` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ContainerName` text,
  `ContainerDescription` text,
  `MinAmount` int NOT NULL DEFAULT '0',
  `MaxAmount` int NOT NULL DEFAULT '0',
  `ContainerIconID` int NOT NULL DEFAULT '0',
  `ContainerQuality` int NOT NULL DEFAULT '0',
  `OnLootSpellVisualKitID` int NOT NULL DEFAULT '0',
  `CurrencyTypesID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currency_container`
--

LOCK TABLES `currency_container` WRITE;
/*!40000 ALTER TABLE `currency_container` DISABLE KEYS */;
/*!40000 ALTER TABLE `currency_container` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currency_container_locale`
--

DROP TABLE IF EXISTS `currency_container_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_container_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ContainerName_lang` text,
  `ContainerDescription_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `currency_container_locale`
--

LOCK TABLES `currency_container_locale` WRITE;
/*!40000 ALTER TABLE `currency_container_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `currency_container_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currency_types`
--

DROP TABLE IF EXISTS `currency_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_types` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `CategoryID` tinyint unsigned NOT NULL DEFAULT '0',
  `InventoryIconFileID` int NOT NULL DEFAULT '0',
  `SpellWeight` int unsigned NOT NULL DEFAULT '0',
  `SpellCategory` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxQty` int unsigned NOT NULL DEFAULT '0',
  `MaxEarnablePerWeek` int unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint NOT NULL DEFAULT '0',
  `FactionID` int NOT NULL DEFAULT '0',
  `AwardConditionID` int NOT NULL DEFAULT '0',
  `MaxQtyWorldStateID` int NOT NULL DEFAULT '0',
  `Unknown1154` float NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currency_types`
--

LOCK TABLES `currency_types` WRITE;
/*!40000 ALTER TABLE `currency_types` DISABLE KEYS */;
/*!40000 ALTER TABLE `currency_types` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currency_types_locale`
--

DROP TABLE IF EXISTS `currency_types_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_types_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `currency_types_locale`
--

LOCK TABLES `currency_types_locale` WRITE;
/*!40000 ALTER TABLE `currency_types_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `currency_types_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `curve`
--

DROP TABLE IF EXISTS `curve`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `curve` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `curve`
--

LOCK TABLES `curve` WRITE;
/*!40000 ALTER TABLE `curve` DISABLE KEYS */;
/*!40000 ALTER TABLE `curve` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `curve_point`
--

DROP TABLE IF EXISTS `curve_point`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `curve_point` (
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PreSLSquishPosX` float NOT NULL DEFAULT '0',
  `PreSLSquishPosY` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CurveID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `curve_point`
--

LOCK TABLES `curve_point` WRITE;
/*!40000 ALTER TABLE `curve_point` DISABLE KEYS */;
/*!40000 ALTER TABLE `curve_point` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `destructible_model_data`
--

DROP TABLE IF EXISTS `destructible_model_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `destructible_model_data` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `State0ImpactEffectDoodadSet` tinyint NOT NULL DEFAULT '0',
  `State0AmbientDoodadSet` tinyint unsigned NOT NULL DEFAULT '0',
  `State1Wmo` int unsigned NOT NULL DEFAULT '0',
  `State1DestructionDoodadSet` tinyint NOT NULL DEFAULT '0',
  `State1ImpactEffectDoodadSet` tinyint NOT NULL DEFAULT '0',
  `State1AmbientDoodadSet` tinyint unsigned NOT NULL DEFAULT '0',
  `State2Wmo` int unsigned NOT NULL DEFAULT '0',
  `State2DestructionDoodadSet` tinyint NOT NULL DEFAULT '0',
  `State2ImpactEffectDoodadSet` tinyint NOT NULL DEFAULT '0',
  `State2AmbientDoodadSet` tinyint unsigned NOT NULL DEFAULT '0',
  `State3Wmo` int unsigned NOT NULL DEFAULT '0',
  `State3InitDoodadSet` tinyint unsigned NOT NULL DEFAULT '0',
  `State3AmbientDoodadSet` tinyint unsigned NOT NULL DEFAULT '0',
  `EjectDirection` tinyint unsigned NOT NULL DEFAULT '0',
  `DoNotHighlight` tinyint unsigned NOT NULL DEFAULT '0',
  `State0Wmo` int unsigned NOT NULL DEFAULT '0',
  `HealEffect` tinyint unsigned NOT NULL DEFAULT '0',
  `HealEffectSpeed` smallint unsigned NOT NULL DEFAULT '0',
  `State0NameSet` tinyint NOT NULL DEFAULT '0',
  `State1NameSet` tinyint NOT NULL DEFAULT '0',
  `State2NameSet` tinyint NOT NULL DEFAULT '0',
  `State3NameSet` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `destructible_model_data`
--

LOCK TABLES `destructible_model_data` WRITE;
/*!40000 ALTER TABLE `destructible_model_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `destructible_model_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `difficulty`
--

DROP TABLE IF EXISTS `difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `difficulty` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `InstanceType` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `OldEnumValue` tinyint NOT NULL DEFAULT '0',
  `FallbackDifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `MinPlayers` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `ItemContext` tinyint unsigned NOT NULL DEFAULT '0',
  `ToggleDifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `GroupSizeHealthCurveID` smallint unsigned NOT NULL DEFAULT '0',
  `GroupSizeDmgCurveID` smallint unsigned NOT NULL DEFAULT '0',
  `GroupSizeSpellPointsCurveID` smallint unsigned NOT NULL DEFAULT '0',
  `Unknown1154` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `difficulty`
--

LOCK TABLES `difficulty` WRITE;
/*!40000 ALTER TABLE `difficulty` DISABLE KEYS */;
/*!40000 ALTER TABLE `difficulty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `difficulty_locale`
--

DROP TABLE IF EXISTS `difficulty_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `difficulty_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `difficulty_locale`
--

LOCK TABLES `difficulty_locale` WRITE;
/*!40000 ALTER TABLE `difficulty_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `difficulty_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dungeon_encounter`
--

DROP TABLE IF EXISTS `dungeon_encounter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `dungeon_encounter` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MapID` smallint unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `CompleteWorldStateID` int NOT NULL DEFAULT '0',
  `Bit` tinyint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SpellIconFileID` int NOT NULL DEFAULT '0',
  `Faction` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dungeon_encounter`
--

LOCK TABLES `dungeon_encounter` WRITE;
/*!40000 ALTER TABLE `dungeon_encounter` DISABLE KEYS */;
/*!40000 ALTER TABLE `dungeon_encounter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dungeon_encounter_locale`
--

DROP TABLE IF EXISTS `dungeon_encounter_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `dungeon_encounter_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `dungeon_encounter_locale`
--

LOCK TABLES `dungeon_encounter_locale` WRITE;
/*!40000 ALTER TABLE `dungeon_encounter_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `dungeon_encounter_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `durability_costs`
--

DROP TABLE IF EXISTS `durability_costs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `durability_costs` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost1` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost2` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost3` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost4` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost5` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost6` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost7` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost8` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost9` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost10` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost11` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost12` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost13` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost14` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost15` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost16` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost17` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost18` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost19` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost20` smallint unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost21` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost1` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost2` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost3` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost4` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost5` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost6` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost7` smallint unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost8` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `durability_costs`
--

LOCK TABLES `durability_costs` WRITE;
/*!40000 ALTER TABLE `durability_costs` DISABLE KEYS */;
/*!40000 ALTER TABLE `durability_costs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `durability_quality`
--

DROP TABLE IF EXISTS `durability_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `durability_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `durability_quality`
--

LOCK TABLES `durability_quality` WRITE;
/*!40000 ALTER TABLE `durability_quality` DISABLE KEYS */;
/*!40000 ALTER TABLE `durability_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emotes`
--

DROP TABLE IF EXISTS `emotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `emotes` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `EmoteSlashCommand` text,
  `AnimID` smallint NOT NULL DEFAULT '0',
  `EmoteFlags` int NOT NULL DEFAULT '0',
  `EmoteSpecProc` int NOT NULL DEFAULT '0',
  `EmoteSpecProcParam` int unsigned NOT NULL DEFAULT '0',
  `EventSoundID` int unsigned NOT NULL DEFAULT '0',
  `SpellVisualKitID` int unsigned NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emotes`
--

LOCK TABLES `emotes` WRITE;
/*!40000 ALTER TABLE `emotes` DISABLE KEYS */;
/*!40000 ALTER TABLE `emotes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emotes_text`
--

DROP TABLE IF EXISTS `emotes_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `emotes_text` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `EmoteID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emotes_text`
--

LOCK TABLES `emotes_text` WRITE;
/*!40000 ALTER TABLE `emotes_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `emotes_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emotes_text_sound`
--

DROP TABLE IF EXISTS `emotes_text_sound`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `emotes_text_sound` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint unsigned NOT NULL DEFAULT '0',
  `SexID` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundID` int unsigned NOT NULL DEFAULT '0',
  `EmotesTextID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emotes_text_sound`
--

LOCK TABLES `emotes_text_sound` WRITE;
/*!40000 ALTER TABLE `emotes_text_sound` DISABLE KEYS */;
/*!40000 ALTER TABLE `emotes_text_sound` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `expected_stat`
--

DROP TABLE IF EXISTS `expected_stat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `expected_stat` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ExpansionID` int NOT NULL DEFAULT '0',
  `CreatureHealth` float NOT NULL DEFAULT '0',
  `PlayerHealth` float NOT NULL DEFAULT '0',
  `CreatureAutoAttackDps` float NOT NULL DEFAULT '0',
  `CreatureArmor` float NOT NULL DEFAULT '0',
  `PlayerMana` float NOT NULL DEFAULT '0',
  `PlayerPrimaryStat` float NOT NULL DEFAULT '0',
  `PlayerSecondaryStat` float NOT NULL DEFAULT '0',
  `ArmorConstant` float NOT NULL DEFAULT '0',
  `CreatureSpellDamage` float NOT NULL DEFAULT '0',
  `Lvl` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `expected_stat`
--

LOCK TABLES `expected_stat` WRITE;
/*!40000 ALTER TABLE `expected_stat` DISABLE KEYS */;
/*!40000 ALTER TABLE `expected_stat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `expected_stat_mod`
--

DROP TABLE IF EXISTS `expected_stat_mod`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `expected_stat_mod` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CreatureHealthMod` float NOT NULL DEFAULT '0',
  `PlayerHealthMod` float NOT NULL DEFAULT '0',
  `CreatureAutoAttackDPSMod` float NOT NULL DEFAULT '0',
  `CreatureArmorMod` float NOT NULL DEFAULT '0',
  `PlayerManaMod` float NOT NULL DEFAULT '0',
  `PlayerPrimaryStatMod` float NOT NULL DEFAULT '0',
  `PlayerSecondaryStatMod` float NOT NULL DEFAULT '0',
  `ArmorConstantMod` float NOT NULL DEFAULT '0',
  `CreatureSpellDamageMod` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `expected_stat_mod`
--

LOCK TABLES `expected_stat_mod` WRITE;
/*!40000 ALTER TABLE `expected_stat_mod` DISABLE KEYS */;
/*!40000 ALTER TABLE `expected_stat_mod` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faction`
--

DROP TABLE IF EXISTS `faction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `faction` (
  `ReputationRaceMask1` bigint NOT NULL DEFAULT '0',
  `ReputationRaceMask2` bigint NOT NULL DEFAULT '0',
  `ReputationRaceMask3` bigint NOT NULL DEFAULT '0',
  `ReputationRaceMask4` bigint NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ReputationIndex` smallint NOT NULL DEFAULT '0',
  `ParentFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint unsigned NOT NULL DEFAULT '0',
  `FriendshipRepID` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ParagonFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `RenownFactionID` int NOT NULL DEFAULT '0',
  `RenownCurrencyID` int NOT NULL DEFAULT '0',
  `ReputationClassMask1` smallint NOT NULL DEFAULT '0',
  `ReputationClassMask2` smallint NOT NULL DEFAULT '0',
  `ReputationClassMask3` smallint NOT NULL DEFAULT '0',
  `ReputationClassMask4` smallint NOT NULL DEFAULT '0',
  `ReputationFlags1` smallint unsigned NOT NULL DEFAULT '0',
  `ReputationFlags2` smallint unsigned NOT NULL DEFAULT '0',
  `ReputationFlags3` smallint unsigned NOT NULL DEFAULT '0',
  `ReputationFlags4` smallint unsigned NOT NULL DEFAULT '0',
  `ReputationBase1` int NOT NULL DEFAULT '0',
  `ReputationBase2` int NOT NULL DEFAULT '0',
  `ReputationBase3` int NOT NULL DEFAULT '0',
  `ReputationBase4` int NOT NULL DEFAULT '0',
  `ReputationMax1` int NOT NULL DEFAULT '0',
  `ReputationMax2` int NOT NULL DEFAULT '0',
  `ReputationMax3` int NOT NULL DEFAULT '0',
  `ReputationMax4` int NOT NULL DEFAULT '0',
  `ParentFactionMod1` float NOT NULL DEFAULT '0',
  `ParentFactionMod2` float NOT NULL DEFAULT '0',
  `ParentFactionCap1` tinyint unsigned NOT NULL DEFAULT '0',
  `ParentFactionCap2` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `faction`
--

LOCK TABLES `faction` WRITE;
/*!40000 ALTER TABLE `faction` DISABLE KEYS */;
/*!40000 ALTER TABLE `faction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faction_locale`
--

DROP TABLE IF EXISTS `faction_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `faction_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `faction_locale`
--

LOCK TABLES `faction_locale` WRITE;
/*!40000 ALTER TABLE `faction_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `faction_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faction_template`
--

DROP TABLE IF EXISTS `faction_template`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `faction_template` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Faction` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `FactionGroup` tinyint unsigned NOT NULL DEFAULT '0',
  `FriendGroup` tinyint unsigned NOT NULL DEFAULT '0',
  `EnemyGroup` tinyint unsigned NOT NULL DEFAULT '0',
  `Enemies1` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies2` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies3` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies4` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies5` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies6` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies7` smallint unsigned NOT NULL DEFAULT '0',
  `Enemies8` smallint unsigned NOT NULL DEFAULT '0',
  `Friend1` smallint unsigned NOT NULL DEFAULT '0',
  `Friend2` smallint unsigned NOT NULL DEFAULT '0',
  `Friend3` smallint unsigned NOT NULL DEFAULT '0',
  `Friend4` smallint unsigned NOT NULL DEFAULT '0',
  `Friend5` smallint unsigned NOT NULL DEFAULT '0',
  `Friend6` smallint unsigned NOT NULL DEFAULT '0',
  `Friend7` smallint unsigned NOT NULL DEFAULT '0',
  `Friend8` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `faction_template`
--

LOCK TABLES `faction_template` WRITE;
/*!40000 ALTER TABLE `faction_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `faction_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `friendship_rep_reaction`
--

DROP TABLE IF EXISTS `friendship_rep_reaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `friendship_rep_reaction` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Reaction` text,
  `FriendshipRepID` tinyint unsigned NOT NULL DEFAULT '0',
  `ReactionThreshold` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `friendship_rep_reaction`
--

LOCK TABLES `friendship_rep_reaction` WRITE;
/*!40000 ALTER TABLE `friendship_rep_reaction` DISABLE KEYS */;
/*!40000 ALTER TABLE `friendship_rep_reaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `friendship_rep_reaction_locale`
--

DROP TABLE IF EXISTS `friendship_rep_reaction_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `friendship_rep_reaction_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Reaction_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `friendship_rep_reaction_locale`
--

LOCK TABLES `friendship_rep_reaction_locale` WRITE;
/*!40000 ALTER TABLE `friendship_rep_reaction_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `friendship_rep_reaction_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `friendship_reputation`
--

DROP TABLE IF EXISTS `friendship_reputation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `friendship_reputation` (
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Unknown341_0` int NOT NULL DEFAULT '0',
  `Unknown341_1` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `friendship_reputation`
--

LOCK TABLES `friendship_reputation` WRITE;
/*!40000 ALTER TABLE `friendship_reputation` DISABLE KEYS */;
/*!40000 ALTER TABLE `friendship_reputation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `friendship_reputation_locale`
--

DROP TABLE IF EXISTS `friendship_reputation_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `friendship_reputation_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `friendship_reputation_locale`
--

LOCK TABLES `friendship_reputation_locale` WRITE;
/*!40000 ALTER TABLE `friendship_reputation_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `friendship_reputation_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_art_kit`
--

DROP TABLE IF EXISTS `gameobject_art_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gameobject_art_kit` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AttachModelFileID` int NOT NULL DEFAULT '0',
  `TextureVariationFileID1` int NOT NULL DEFAULT '0',
  `TextureVariationFileID2` int NOT NULL DEFAULT '0',
  `TextureVariationFileID3` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gameobject_art_kit`
--

LOCK TABLES `gameobject_art_kit` WRITE;
/*!40000 ALTER TABLE `gameobject_art_kit` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_art_kit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_display_info`
--

DROP TABLE IF EXISTS `gameobject_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gameobject_display_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ModelName` text,
  `GeoBoxMinX` float NOT NULL DEFAULT '0',
  `GeoBoxMinY` float NOT NULL DEFAULT '0',
  `GeoBoxMinZ` float NOT NULL DEFAULT '0',
  `GeoBoxMaxX` float NOT NULL DEFAULT '0',
  `GeoBoxMaxY` float NOT NULL DEFAULT '0',
  `GeoBoxMaxZ` float NOT NULL DEFAULT '0',
  `FileDataID` int NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `Unknown1154` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gameobject_display_info`
--

LOCK TABLES `gameobject_display_info` WRITE;
/*!40000 ALTER TABLE `gameobject_display_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_display_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobjects`
--

DROP TABLE IF EXISTS `gameobjects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gameobjects` (
  `Name` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `Rot4` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OwnerID` smallint unsigned NOT NULL DEFAULT '0',
  `DisplayID` int unsigned NOT NULL DEFAULT '0',
  `Scale` float NOT NULL DEFAULT '0',
  `TypeID` tinyint unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` int NOT NULL DEFAULT '0',
  `PhaseID` smallint unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint unsigned NOT NULL DEFAULT '0',
  `Unknown1100` smallint unsigned NOT NULL DEFAULT '0',
  `PropValue1` int NOT NULL DEFAULT '0',
  `PropValue2` int NOT NULL DEFAULT '0',
  `PropValue3` int NOT NULL DEFAULT '0',
  `PropValue4` int NOT NULL DEFAULT '0',
  `PropValue5` int NOT NULL DEFAULT '0',
  `PropValue6` int NOT NULL DEFAULT '0',
  `PropValue7` int NOT NULL DEFAULT '0',
  `PropValue8` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gameobjects`
--

LOCK TABLES `gameobjects` WRITE;
/*!40000 ALTER TABLE `gameobjects` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobjects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobjects_locale`
--

DROP TABLE IF EXISTS `gameobjects_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gameobjects_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `gameobjects_locale`
--

LOCK TABLES `gameobjects_locale` WRITE;
/*!40000 ALTER TABLE `gameobjects_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobjects_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gem_properties`
--

DROP TABLE IF EXISTS `gem_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gem_properties` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `EnchantID` smallint unsigned NOT NULL DEFAULT '0',
  `Type` int NOT NULL DEFAULT '0',
  `MinItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gem_properties`
--

LOCK TABLES `gem_properties` WRITE;
/*!40000 ALTER TABLE `gem_properties` DISABLE KEYS */;
/*!40000 ALTER TABLE `gem_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `glyph_bindable_spell`
--

DROP TABLE IF EXISTS `glyph_bindable_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `glyph_bindable_spell` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `GlyphPropertiesID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `glyph_bindable_spell`
--

LOCK TABLES `glyph_bindable_spell` WRITE;
/*!40000 ALTER TABLE `glyph_bindable_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `glyph_bindable_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `glyph_slot`
--

DROP TABLE IF EXISTS `glyph_slot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `glyph_slot` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Tooltip` int NOT NULL DEFAULT '0',
  `Type` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `glyph_slot`
--

LOCK TABLES `glyph_slot` WRITE;
/*!40000 ALTER TABLE `glyph_slot` DISABLE KEYS */;
/*!40000 ALTER TABLE `glyph_slot` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `glyph_properties`
--

DROP TABLE IF EXISTS `glyph_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `glyph_properties` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `GlyphType` tinyint unsigned NOT NULL DEFAULT '0',
  `GlyphExclusiveCategoryID` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellIconFileDataID` int NOT NULL DEFAULT '0',
  `GlyphSlotFlags` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `glyph_properties`
--

LOCK TABLES `glyph_properties` WRITE;
/*!40000 ALTER TABLE `glyph_properties` DISABLE KEYS */;
/*!40000 ALTER TABLE `glyph_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `glyph_required_spec`
--

DROP TABLE IF EXISTS `glyph_required_spec`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `glyph_required_spec` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint unsigned NOT NULL DEFAULT '0',
  `GlyphPropertiesID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `glyph_required_spec`
--

LOCK TABLES `glyph_required_spec` WRITE;
/*!40000 ALTER TABLE `glyph_required_spec` DISABLE KEYS */;
/*!40000 ALTER TABLE `glyph_required_spec` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gossip_npc_option`
--

DROP TABLE IF EXISTS `gossip_npc_option`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gossip_npc_option` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `GossipNpcOption` int NOT NULL DEFAULT '0',
  `LFGDungeonsID` int NOT NULL DEFAULT '0',
  `TrainerID` int NOT NULL DEFAULT '0',
  `Unknown341_0` int NOT NULL DEFAULT '0',
  `Unknown341_1` int NOT NULL DEFAULT '0',
  `Unknown341_2` int NOT NULL DEFAULT '0',
  `Unknown341_3` int NOT NULL DEFAULT '0',
  `Unknown341_4` int NOT NULL DEFAULT '0',
  `Unknown341_5` int NOT NULL DEFAULT '0',
  `Unknown341_6` int NOT NULL DEFAULT '0',
  `Unknown341_7` int NOT NULL DEFAULT '0',
  `GossipOptionID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gossip_npc_option`
--

LOCK TABLES `gossip_npc_option` WRITE;
/*!40000 ALTER TABLE `gossip_npc_option` DISABLE KEYS */;
/*!40000 ALTER TABLE `gossip_npc_option` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `guild_color_background`
--

DROP TABLE IF EXISTS `guild_color_background`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `guild_color_background` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guild_color_background`
--

LOCK TABLES `guild_color_background` WRITE;
/*!40000 ALTER TABLE `guild_color_background` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_color_background` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `guild_color_border`
--

DROP TABLE IF EXISTS `guild_color_border`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `guild_color_border` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guild_color_border`
--

LOCK TABLES `guild_color_border` WRITE;
/*!40000 ALTER TABLE `guild_color_border` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_color_border` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `guild_color_emblem`
--

DROP TABLE IF EXISTS `guild_color_emblem`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `guild_color_emblem` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guild_color_emblem`
--

LOCK TABLES `guild_color_emblem` WRITE;
/*!40000 ALTER TABLE `guild_color_emblem` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_color_emblem` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `guild_perk_spells`
--

DROP TABLE IF EXISTS `guild_perk_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `guild_perk_spells` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guild_perk_spells`
--

LOCK TABLES `guild_perk_spells` WRITE;
/*!40000 ALTER TABLE `guild_perk_spells` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_perk_spells` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `heirloom`
--

DROP TABLE IF EXISTS `heirloom`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `heirloom` (
  `SourceText` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `LegacyUpgradedItemID` int NOT NULL DEFAULT '0',
  `StaticUpgradedItemID` int NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `LegacyItemID` int NOT NULL DEFAULT '0',
  `UpgradeItemID1` int NOT NULL DEFAULT '0',
  `UpgradeItemID2` int NOT NULL DEFAULT '0',
  `UpgradeItemID3` int NOT NULL DEFAULT '0',
  `UpgradeItemID4` int NOT NULL DEFAULT '0',
  `UpgradeItemID5` int NOT NULL DEFAULT '0',
  `UpgradeItemID6` int NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID1` smallint unsigned NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID2` smallint unsigned NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID3` smallint unsigned NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID4` smallint unsigned NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID5` smallint unsigned NOT NULL DEFAULT '0',
  `UpgradeItemBonusListID6` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `heirloom`
--

LOCK TABLES `heirloom` WRITE;
/*!40000 ALTER TABLE `heirloom` DISABLE KEYS */;
/*!40000 ALTER TABLE `heirloom` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `heirloom_locale`
--

DROP TABLE IF EXISTS `heirloom_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `heirloom_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceText_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `heirloom_locale`
--

LOCK TABLES `heirloom_locale` WRITE;
/*!40000 ALTER TABLE `heirloom_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `heirloom_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `holidays`
--

DROP TABLE IF EXISTS `holidays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `holidays` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Region` smallint unsigned NOT NULL DEFAULT '0',
  `Looping` tinyint unsigned NOT NULL DEFAULT '0',
  `HolidayNameID` int unsigned NOT NULL DEFAULT '0',
  `HolidayDescriptionID` int unsigned NOT NULL DEFAULT '0',
  `Priority` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFilterType` tinyint NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `WorldStateExpressionID` int unsigned NOT NULL DEFAULT '0',
  `Duration1` smallint unsigned NOT NULL DEFAULT '0',
  `Duration2` smallint unsigned NOT NULL DEFAULT '0',
  `Duration3` smallint unsigned NOT NULL DEFAULT '0',
  `Duration4` smallint unsigned NOT NULL DEFAULT '0',
  `Duration5` smallint unsigned NOT NULL DEFAULT '0',
  `Duration6` smallint unsigned NOT NULL DEFAULT '0',
  `Duration7` smallint unsigned NOT NULL DEFAULT '0',
  `Duration8` smallint unsigned NOT NULL DEFAULT '0',
  `Duration9` smallint unsigned NOT NULL DEFAULT '0',
  `Duration10` smallint unsigned NOT NULL DEFAULT '0',
  `Date1` int unsigned NOT NULL DEFAULT '0',
  `Date2` int unsigned NOT NULL DEFAULT '0',
  `Date3` int unsigned NOT NULL DEFAULT '0',
  `Date4` int unsigned NOT NULL DEFAULT '0',
  `Date5` int unsigned NOT NULL DEFAULT '0',
  `Date6` int unsigned NOT NULL DEFAULT '0',
  `Date7` int unsigned NOT NULL DEFAULT '0',
  `Date8` int unsigned NOT NULL DEFAULT '0',
  `Date9` int unsigned NOT NULL DEFAULT '0',
  `Date10` int unsigned NOT NULL DEFAULT '0',
  `Date11` int unsigned NOT NULL DEFAULT '0',
  `Date12` int unsigned NOT NULL DEFAULT '0',
  `Date13` int unsigned NOT NULL DEFAULT '0',
  `Date14` int unsigned NOT NULL DEFAULT '0',
  `Date15` int unsigned NOT NULL DEFAULT '0',
  `Date16` int unsigned NOT NULL DEFAULT '0',
  `CalendarFlags1` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags2` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags3` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags4` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags5` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags6` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags7` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags8` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags9` tinyint unsigned NOT NULL DEFAULT '0',
  `CalendarFlags10` tinyint unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID1` int NOT NULL DEFAULT '0',
  `TextureFileDataID2` int NOT NULL DEFAULT '0',
  `TextureFileDataID3` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `holidays`
--

LOCK TABLES `holidays` WRITE;
/*!40000 ALTER TABLE `holidays` DISABLE KEYS */;
/*!40000 ALTER TABLE `holidays` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `import_price_armor`
--

DROP TABLE IF EXISTS `import_price_armor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `import_price_armor` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClothModifier` float NOT NULL DEFAULT '0',
  `LeatherModifier` float NOT NULL DEFAULT '0',
  `ChainModifier` float NOT NULL DEFAULT '0',
  `PlateModifier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `import_price_armor`
--

LOCK TABLES `import_price_armor` WRITE;
/*!40000 ALTER TABLE `import_price_armor` DISABLE KEYS */;
/*!40000 ALTER TABLE `import_price_armor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `import_price_quality`
--

DROP TABLE IF EXISTS `import_price_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `import_price_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `import_price_quality`
--

LOCK TABLES `import_price_quality` WRITE;
/*!40000 ALTER TABLE `import_price_quality` DISABLE KEYS */;
/*!40000 ALTER TABLE `import_price_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `import_price_shield`
--

DROP TABLE IF EXISTS `import_price_shield`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `import_price_shield` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `import_price_shield`
--

LOCK TABLES `import_price_shield` WRITE;
/*!40000 ALTER TABLE `import_price_shield` DISABLE KEYS */;
/*!40000 ALTER TABLE `import_price_shield` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `import_price_weapon`
--

DROP TABLE IF EXISTS `import_price_weapon`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `import_price_weapon` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Data` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `import_price_weapon`
--

LOCK TABLES `import_price_weapon` WRITE;
/*!40000 ALTER TABLE `import_price_weapon` DISABLE KEYS */;
/*!40000 ALTER TABLE `import_price_weapon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint unsigned NOT NULL DEFAULT '0',
  `SubclassID` tinyint unsigned NOT NULL DEFAULT '0',
  `Material` tinyint unsigned NOT NULL DEFAULT '0',
  `InventoryType` tinyint NOT NULL DEFAULT '0',
  `RequiredLevel` int NOT NULL DEFAULT '0',
  `SheatheType` tinyint unsigned NOT NULL DEFAULT '0',
  `RandomSelect` smallint unsigned NOT NULL DEFAULT '0',
  `ItemRandomSuffixGroupID` smallint unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclassID` tinyint NOT NULL DEFAULT '0',
  `ScalingStatDistributionID` smallint unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `ItemGroupSoundsID` tinyint unsigned NOT NULL DEFAULT '0',
  `ContentTuningID` int NOT NULL DEFAULT '0',
  `MaxDurability` int unsigned NOT NULL DEFAULT '0',
  `AmmunitionType` tinyint unsigned NOT NULL DEFAULT '0',
  `ScalingStatValue` int NOT NULL DEFAULT '0',
  `DamageType1` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageType2` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageType3` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageType4` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageType5` tinyint unsigned NOT NULL DEFAULT '0',
  `Resistances1` int NOT NULL DEFAULT '0',
  `Resistances2` int NOT NULL DEFAULT '0',
  `Resistances3` int NOT NULL DEFAULT '0',
  `Resistances4` int NOT NULL DEFAULT '0',
  `Resistances5` int NOT NULL DEFAULT '0',
  `Resistances6` int NOT NULL DEFAULT '0',
  `Resistances7` int NOT NULL DEFAULT '0',
  `MinDamage1` int NOT NULL DEFAULT '0',
  `MinDamage2` int NOT NULL DEFAULT '0',
  `MinDamage3` int NOT NULL DEFAULT '0',
  `MinDamage4` int NOT NULL DEFAULT '0',
  `MinDamage5` int NOT NULL DEFAULT '0',
  `MaxDamage1` int NOT NULL DEFAULT '0',
  `MaxDamage2` int NOT NULL DEFAULT '0',
  `MaxDamage3` int NOT NULL DEFAULT '0',
  `MaxDamage4` int NOT NULL DEFAULT '0',
  `MaxDamage5` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item`
--

LOCK TABLES `item` WRITE;
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
/*!40000 ALTER TABLE `item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_appearance`
--

DROP TABLE IF EXISTS `item_appearance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_appearance` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DisplayType` tinyint NOT NULL DEFAULT '0',
  `ItemDisplayInfoID` int NOT NULL DEFAULT '0',
  `DefaultIconFileDataID` int NOT NULL DEFAULT '0',
  `UiOrder` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_appearance`
--

LOCK TABLES `item_appearance` WRITE;
/*!40000 ALTER TABLE `item_appearance` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_appearance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_armor_quality`
--

DROP TABLE IF EXISTS `item_armor_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_armor_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Qualitymod1` float NOT NULL DEFAULT '0',
  `Qualitymod2` float NOT NULL DEFAULT '0',
  `Qualitymod3` float NOT NULL DEFAULT '0',
  `Qualitymod4` float NOT NULL DEFAULT '0',
  `Qualitymod5` float NOT NULL DEFAULT '0',
  `Qualitymod6` float NOT NULL DEFAULT '0',
  `Qualitymod7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_armor_quality`
--

LOCK TABLES `item_armor_quality` WRITE;
/*!40000 ALTER TABLE `item_armor_quality` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_armor_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_armor_shield`
--

DROP TABLE IF EXISTS `item_armor_shield`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_armor_shield` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_armor_shield`
--

LOCK TABLES `item_armor_shield` WRITE;
/*!40000 ALTER TABLE `item_armor_shield` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_armor_shield` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_armor_total`
--

DROP TABLE IF EXISTS `item_armor_total`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_armor_total` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint NOT NULL DEFAULT '0',
  `Cloth` float NOT NULL DEFAULT '0',
  `Leather` float NOT NULL DEFAULT '0',
  `Mail` float NOT NULL DEFAULT '0',
  `Plate` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_armor_total`
--

LOCK TABLES `item_armor_total` WRITE;
/*!40000 ALTER TABLE `item_armor_total` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_armor_total` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_bag_family`
--

DROP TABLE IF EXISTS `item_bag_family`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_bag_family` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_bag_family`
--

LOCK TABLES `item_bag_family` WRITE;
/*!40000 ALTER TABLE `item_bag_family` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_bag_family` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_bag_family_locale`
--

DROP TABLE IF EXISTS `item_bag_family_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_bag_family_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_bag_family_locale`
--

LOCK TABLES `item_bag_family_locale` WRITE;
/*!40000 ALTER TABLE `item_bag_family_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_bag_family_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_bonus`
--

DROP TABLE IF EXISTS `item_bonus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_bonus` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Value1` int NOT NULL DEFAULT '0',
  `Value2` int NOT NULL DEFAULT '0',
  `Value3` int NOT NULL DEFAULT '0',
  `Value4` int NOT NULL DEFAULT '0',
  `ParentItemBonusListID` smallint unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_bonus`
--

LOCK TABLES `item_bonus` WRITE;
/*!40000 ALTER TABLE `item_bonus` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_bonus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_bonus_list_level_delta`
--

DROP TABLE IF EXISTS `item_bonus_list_level_delta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_bonus_list_level_delta` (
  `ItemLevelDelta` smallint NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_bonus_list_level_delta`
--

LOCK TABLES `item_bonus_list_level_delta` WRITE;
/*!40000 ALTER TABLE `item_bonus_list_level_delta` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_bonus_list_level_delta` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_bonus_tree_node`
--

DROP TABLE IF EXISTS `item_bonus_tree_node`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_bonus_tree_node` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemContext` tinyint unsigned NOT NULL DEFAULT '0',
  `ChildItemBonusTreeID` smallint unsigned NOT NULL DEFAULT '0',
  `ChildItemBonusListID` smallint unsigned NOT NULL DEFAULT '0',
  `ChildItemLevelSelectorID` smallint unsigned NOT NULL DEFAULT '0',
  `ChildItemBonusListGroupID` int NOT NULL DEFAULT '0',
  `IblGroupPointsModSetID` int NOT NULL DEFAULT '0',
  `MinMythicPlusLevel` int NOT NULL DEFAULT '0',
  `MaxMythicPlusLevel` int NOT NULL DEFAULT '0',
  `ParentItemBonusTreeID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_bonus_tree_node`
--

LOCK TABLES `item_bonus_tree_node` WRITE;
/*!40000 ALTER TABLE `item_bonus_tree_node` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_bonus_tree_node` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_child_equipment`
--

DROP TABLE IF EXISTS `item_child_equipment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_child_equipment` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChildItemID` int NOT NULL DEFAULT '0',
  `ChildItemEquipSlot` tinyint unsigned NOT NULL DEFAULT '0',
  `ParentItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_child_equipment`
--

LOCK TABLES `item_child_equipment` WRITE;
/*!40000 ALTER TABLE `item_child_equipment` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_child_equipment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_class`
--

DROP TABLE IF EXISTS `item_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_class` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClassName` text,
  `ClassID` tinyint NOT NULL DEFAULT '0',
  `PriceModifier` float NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_class`
--

LOCK TABLES `item_class` WRITE;
/*!40000 ALTER TABLE `item_class` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_class_locale`
--

DROP TABLE IF EXISTS `item_class_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_class_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ClassName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_class_locale`
--

LOCK TABLES `item_class_locale` WRITE;
/*!40000 ALTER TABLE `item_class_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_class_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_context_picker_entry`
--

DROP TABLE IF EXISTS `item_context_picker_entry`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_context_picker_entry` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemCreationContext` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `PVal` int NOT NULL DEFAULT '0',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `ItemContextPickerID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_context_picker_entry`
--

LOCK TABLES `item_context_picker_entry` WRITE;
/*!40000 ALTER TABLE `item_context_picker_entry` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_context_picker_entry` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_currency_cost`
--

DROP TABLE IF EXISTS `item_currency_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_currency_cost` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_currency_cost`
--

LOCK TABLES `item_currency_cost` WRITE;
/*!40000 ALTER TABLE `item_currency_cost` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_currency_cost` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_damage_ammo`
--

DROP TABLE IF EXISTS `item_damage_ammo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_damage_ammo` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_damage_ammo`
--

LOCK TABLES `item_damage_ammo` WRITE;
/*!40000 ALTER TABLE `item_damage_ammo` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_damage_ammo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_damage_one_hand`
--

DROP TABLE IF EXISTS `item_damage_one_hand`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_damage_one_hand` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_damage_one_hand`
--

LOCK TABLES `item_damage_one_hand` WRITE;
/*!40000 ALTER TABLE `item_damage_one_hand` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_damage_one_hand` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_damage_one_hand_caster`
--

DROP TABLE IF EXISTS `item_damage_one_hand_caster`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_damage_one_hand_caster` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_damage_one_hand_caster`
--

LOCK TABLES `item_damage_one_hand_caster` WRITE;
/*!40000 ALTER TABLE `item_damage_one_hand_caster` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_damage_one_hand_caster` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_damage_two_hand`
--

DROP TABLE IF EXISTS `item_damage_two_hand`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_damage_two_hand` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_damage_two_hand`
--

LOCK TABLES `item_damage_two_hand` WRITE;
/*!40000 ALTER TABLE `item_damage_two_hand` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_damage_two_hand` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_damage_two_hand_caster`
--

DROP TABLE IF EXISTS `item_damage_two_hand_caster`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_damage_two_hand_caster` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_damage_two_hand_caster`
--

LOCK TABLES `item_damage_two_hand_caster` WRITE;
/*!40000 ALTER TABLE `item_damage_two_hand_caster` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_damage_two_hand_caster` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_disenchant_loot`
--

DROP TABLE IF EXISTS `item_disenchant_loot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_disenchant_loot` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Subclass` tinyint NOT NULL DEFAULT '0',
  `Quality` tinyint unsigned NOT NULL DEFAULT '0',
  `MinLevel` smallint unsigned NOT NULL DEFAULT '0',
  `MaxLevel` smallint unsigned NOT NULL DEFAULT '0',
  `SkillRequired` smallint unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint NOT NULL DEFAULT '0',
  `Class` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_disenchant_loot`
--

LOCK TABLES `item_disenchant_loot` WRITE;
/*!40000 ALTER TABLE `item_disenchant_loot` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_disenchant_loot` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_effect`
--

DROP TABLE IF EXISTS `item_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_effect` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `LegacySlotIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `TriggerType` tinyint NOT NULL DEFAULT '0',
  `Charges` smallint NOT NULL DEFAULT '0',
  `CoolDownMSec` int NOT NULL DEFAULT '0',
  `CategoryCoolDownMSec` int NOT NULL DEFAULT '0',
  `SpellCategoryID` smallint unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint unsigned NOT NULL DEFAULT '0',
  `ParentItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_effect`
--

LOCK TABLES `item_effect` WRITE;
/*!40000 ALTER TABLE `item_effect` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_effect` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_extended_cost`
--

DROP TABLE IF EXISTS `item_extended_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_extended_cost` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RequiredArenaRating` smallint unsigned NOT NULL DEFAULT '0',
  `ArenaBracket` tinyint NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `MinFactionID` tinyint unsigned NOT NULL DEFAULT '0',
  `MinReputation` int NOT NULL DEFAULT '0',
  `RequiredAchievement` tinyint unsigned NOT NULL DEFAULT '0',
  `ItemID1` int NOT NULL DEFAULT '0',
  `ItemID2` int NOT NULL DEFAULT '0',
  `ItemID3` int NOT NULL DEFAULT '0',
  `ItemID4` int NOT NULL DEFAULT '0',
  `ItemID5` int NOT NULL DEFAULT '0',
  `ItemCount1` smallint unsigned NOT NULL DEFAULT '0',
  `ItemCount2` smallint unsigned NOT NULL DEFAULT '0',
  `ItemCount3` smallint unsigned NOT NULL DEFAULT '0',
  `ItemCount4` smallint unsigned NOT NULL DEFAULT '0',
  `ItemCount5` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyID1` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyID2` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyID3` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyID4` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyID5` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyCount1` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount2` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount3` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount4` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount5` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_extended_cost`
--

LOCK TABLES `item_extended_cost` WRITE;
/*!40000 ALTER TABLE `item_extended_cost` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_extended_cost` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_level_selector`
--

DROP TABLE IF EXISTS `item_level_selector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_level_selector` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `ItemLevelSelectorQualitySetID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_level_selector`
--

LOCK TABLES `item_level_selector` WRITE;
/*!40000 ALTER TABLE `item_level_selector` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_level_selector` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_level_selector_quality`
--

DROP TABLE IF EXISTS `item_level_selector_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_level_selector_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `QualityItemBonusListID` int NOT NULL DEFAULT '0',
  `Quality` tinyint NOT NULL DEFAULT '0',
  `ParentILSQualitySetID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_level_selector_quality`
--

LOCK TABLES `item_level_selector_quality` WRITE;
/*!40000 ALTER TABLE `item_level_selector_quality` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_level_selector_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_level_selector_quality_set`
--

DROP TABLE IF EXISTS `item_level_selector_quality_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_level_selector_quality_set` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `IlvlRare` smallint NOT NULL DEFAULT '0',
  `IlvlEpic` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_level_selector_quality_set`
--

LOCK TABLES `item_level_selector_quality_set` WRITE;
/*!40000 ALTER TABLE `item_level_selector_quality_set` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_level_selector_quality_set` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_limit_category`
--

DROP TABLE IF EXISTS `item_limit_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_limit_category` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Quantity` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_limit_category`
--

LOCK TABLES `item_limit_category` WRITE;
/*!40000 ALTER TABLE `item_limit_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_limit_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_limit_category_locale`
--

DROP TABLE IF EXISTS `item_limit_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_limit_category_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_limit_category_locale`
--

LOCK TABLES `item_limit_category_locale` WRITE;
/*!40000 ALTER TABLE `item_limit_category_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_limit_category_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_limit_category_condition`
--

DROP TABLE IF EXISTS `item_limit_category_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_limit_category_condition` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AddQuantity` tinyint NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `ParentItemLimitCategoryID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_limit_category_condition`
--

LOCK TABLES `item_limit_category_condition` WRITE;
/*!40000 ALTER TABLE `item_limit_category_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_limit_category_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_modified_appearance`
--

DROP TABLE IF EXISTS `item_modified_appearance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_modified_appearance` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int unsigned NOT NULL DEFAULT '0',
  `ItemAppearanceModifierID` int NOT NULL DEFAULT '0',
  `ItemAppearanceID` int NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `TransmogSourceTypeEnum` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_modified_appearance`
--

LOCK TABLES `item_modified_appearance` WRITE;
/*!40000 ALTER TABLE `item_modified_appearance` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_modified_appearance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_modified_appearance_extra`
--

DROP TABLE IF EXISTS `item_modified_appearance_extra`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_modified_appearance_extra` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `UnequippedIconFileDataID` int NOT NULL DEFAULT '0',
  `SheatheType` tinyint unsigned NOT NULL DEFAULT '0',
  `DisplayWeaponSubclassID` tinyint NOT NULL DEFAULT '0',
  `DisplayInventoryType` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_modified_appearance_extra`
--

LOCK TABLES `item_modified_appearance_extra` WRITE;
/*!40000 ALTER TABLE `item_modified_appearance_extra` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_modified_appearance_extra` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_name_description`
--

DROP TABLE IF EXISTS `item_name_description`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_name_description` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Color` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_name_description`
--

LOCK TABLES `item_name_description` WRITE;
/*!40000 ALTER TABLE `item_name_description` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_name_description` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_name_description_locale`
--

DROP TABLE IF EXISTS `item_name_description_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_name_description_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_name_description_locale`
--

LOCK TABLES `item_name_description_locale` WRITE;
/*!40000 ALTER TABLE `item_name_description_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_name_description_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_price_base`
--

DROP TABLE IF EXISTS `item_price_base`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_price_base` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Armor` float NOT NULL DEFAULT '0',
  `Weapon` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_price_base`
--

LOCK TABLES `item_price_base` WRITE;
/*!40000 ALTER TABLE `item_price_base` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_price_base` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_reforge`
--

DROP TABLE IF EXISTS `item_reforge`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_reforge` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SourceStat` smallint unsigned NOT NULL DEFAULT '0',
  `SourceMultiplier` float NOT NULL DEFAULT '0',
  `TargetStat` smallint unsigned NOT NULL DEFAULT '0',
  `TargetMultiplier` float NOT NULL DEFAULT '0',
  `LegacyItemReforgeID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_reforge`
--

LOCK TABLES `item_reforge` WRITE;
/*!40000 ALTER TABLE `item_reforge` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_reforge` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_search_name`
--

DROP TABLE IF EXISTS `item_search_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_search_name` (
  `AllowableRace` bigint NOT NULL DEFAULT '0',
  `Display` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OverallQualityID` tinyint unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint NOT NULL DEFAULT '0',
  `MinFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `MinReputation` int NOT NULL DEFAULT '0',
  `AllowableClass` int NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint NOT NULL DEFAULT '0',
  `RequiredSkill` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredAbility` int unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `Flags3` int NOT NULL DEFAULT '0',
  `Flags4` int NOT NULL DEFAULT '0',
  `Flags5` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_search_name`
--

LOCK TABLES `item_search_name` WRITE;
/*!40000 ALTER TABLE `item_search_name` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_search_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_search_name_locale`
--

DROP TABLE IF EXISTS `item_search_name_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_search_name_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Display_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_search_name_locale`
--

LOCK TABLES `item_search_name_locale` WRITE;
/*!40000 ALTER TABLE `item_search_name_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_search_name_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_set`
--

DROP TABLE IF EXISTS `item_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_set` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `SetFlags` int unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` int unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint unsigned NOT NULL DEFAULT '0',
  `ItemID1` int unsigned NOT NULL DEFAULT '0',
  `ItemID2` int unsigned NOT NULL DEFAULT '0',
  `ItemID3` int unsigned NOT NULL DEFAULT '0',
  `ItemID4` int unsigned NOT NULL DEFAULT '0',
  `ItemID5` int unsigned NOT NULL DEFAULT '0',
  `ItemID6` int unsigned NOT NULL DEFAULT '0',
  `ItemID7` int unsigned NOT NULL DEFAULT '0',
  `ItemID8` int unsigned NOT NULL DEFAULT '0',
  `ItemID9` int unsigned NOT NULL DEFAULT '0',
  `ItemID10` int unsigned NOT NULL DEFAULT '0',
  `ItemID11` int unsigned NOT NULL DEFAULT '0',
  `ItemID12` int unsigned NOT NULL DEFAULT '0',
  `ItemID13` int unsigned NOT NULL DEFAULT '0',
  `ItemID14` int unsigned NOT NULL DEFAULT '0',
  `ItemID15` int unsigned NOT NULL DEFAULT '0',
  `ItemID16` int unsigned NOT NULL DEFAULT '0',
  `ItemID17` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_set`
--

LOCK TABLES `item_set` WRITE;
/*!40000 ALTER TABLE `item_set` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_set` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_set_locale`
--

DROP TABLE IF EXISTS `item_set_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_set_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `item_set_locale`
--

LOCK TABLES `item_set_locale` WRITE;
/*!40000 ALTER TABLE `item_set_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_set_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_set_spell`
--

DROP TABLE IF EXISTS `item_set_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_set_spell` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ChrSpecID` smallint unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `Threshold` tinyint unsigned NOT NULL DEFAULT '0',
  `ItemSetID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_set_spell`
--

LOCK TABLES `item_set_spell` WRITE;
/*!40000 ALTER TABLE `item_set_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_set_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_sparse`
--

DROP TABLE IF EXISTS `item_sparse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_sparse` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AllowableRace` bigint NOT NULL DEFAULT '0',
  `Description` text,
  `Display3` text,
  `Display2` text,
  `Display1` text,
  `Display` text,
  `DmgVariance` float NOT NULL DEFAULT '0',
  `DurationInInventory` int unsigned NOT NULL DEFAULT '0',
  `QualityModifier` float NOT NULL DEFAULT '0',
  `BagFamily` int unsigned NOT NULL DEFAULT '0',
  `StartQuestID` int NOT NULL DEFAULT '0',
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
  `StatPercentEditor1` int NOT NULL DEFAULT '0',
  `StatPercentEditor2` int NOT NULL DEFAULT '0',
  `StatPercentEditor3` int NOT NULL DEFAULT '0',
  `StatPercentEditor4` int NOT NULL DEFAULT '0',
  `StatPercentEditor5` int NOT NULL DEFAULT '0',
  `StatPercentEditor6` int NOT NULL DEFAULT '0',
  `StatPercentEditor7` int NOT NULL DEFAULT '0',
  `StatPercentEditor8` int NOT NULL DEFAULT '0',
  `StatPercentEditor9` int NOT NULL DEFAULT '0',
  `StatPercentEditor10` int NOT NULL DEFAULT '0',
  `Unknown11531` int NOT NULL DEFAULT '0',
  `Unknown11532` int NOT NULL DEFAULT '0',
  `Unknown11533` int NOT NULL DEFAULT '0',
  `Unknown11534` int NOT NULL DEFAULT '0',
  `Unknown11535` int NOT NULL DEFAULT '0',
  `Unknown11536` int NOT NULL DEFAULT '0',
  `Unknown11537` int NOT NULL DEFAULT '0',
  `Unknown11538` int NOT NULL DEFAULT '0',
  `Unknown11539` int NOT NULL DEFAULT '0',
  `Unknown115310` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat1` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat2` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat3` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat4` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat5` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat6` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat7` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat8` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat9` int NOT NULL DEFAULT '0',
  `StatModifierBonusStat10` int NOT NULL DEFAULT '0',
  `Stackable` int NOT NULL DEFAULT '0',
  `MaxCount` int NOT NULL DEFAULT '0',
  `MinReputation` int NOT NULL DEFAULT '0',
  `RequiredAbility` int unsigned NOT NULL DEFAULT '0',
  `SellPrice` int unsigned NOT NULL DEFAULT '0',
  `BuyPrice` int unsigned NOT NULL DEFAULT '0',
  `VendorStackCount` int unsigned NOT NULL DEFAULT '0',
  `PriceVariance` float NOT NULL DEFAULT '0',
  `PriceRandomValue` float NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `Flags3` int NOT NULL DEFAULT '0',
  `Flags4` int NOT NULL DEFAULT '0',
  `Flags5` int NOT NULL DEFAULT '0',
  `OppositeFactionItemID` int NOT NULL DEFAULT '0',
  `ModifiedCraftingReagentItemID` int NOT NULL DEFAULT '0',
  `ContentTuningID` int NOT NULL DEFAULT '0',
  `PlayerLevelToItemLevelCurveID` int NOT NULL DEFAULT '0',
  `MaxDurability` int unsigned NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredTransmogHoliday` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredHoliday` smallint unsigned NOT NULL DEFAULT '0',
  `LimitCategory` smallint unsigned NOT NULL DEFAULT '0',
  `GemProperties` smallint unsigned NOT NULL DEFAULT '0',
  `SocketMatchEnchantmentID` smallint unsigned NOT NULL DEFAULT '0',
  `TotemCategoryID` smallint unsigned NOT NULL DEFAULT '0',
  `InstanceBound` smallint unsigned NOT NULL DEFAULT '0',
  `ZoneBound1` smallint unsigned NOT NULL DEFAULT '0',
  `ZoneBound2` smallint unsigned NOT NULL DEFAULT '0',
  `ItemSet` smallint unsigned NOT NULL DEFAULT '0',
  `LockID` smallint unsigned NOT NULL DEFAULT '0',
  `PageID` smallint unsigned NOT NULL DEFAULT '0',
  `ItemDelay` smallint unsigned NOT NULL DEFAULT '0',
  `MinFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` smallint unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `AllowableClass` smallint NOT NULL DEFAULT '0',
  `ItemRandomSuffixGroupID` smallint unsigned NOT NULL DEFAULT '0',
  `RandomSelect` smallint unsigned NOT NULL DEFAULT '0',
  `MinDamage1` smallint unsigned NOT NULL DEFAULT '0',
  `MinDamage2` smallint unsigned NOT NULL DEFAULT '0',
  `MinDamage3` smallint unsigned NOT NULL DEFAULT '0',
  `MinDamage4` smallint unsigned NOT NULL DEFAULT '0',
  `MinDamage5` smallint unsigned NOT NULL DEFAULT '0',
  `MaxDamage1` smallint unsigned NOT NULL DEFAULT '0',
  `MaxDamage2` smallint unsigned NOT NULL DEFAULT '0',
  `MaxDamage3` smallint unsigned NOT NULL DEFAULT '0',
  `MaxDamage4` smallint unsigned NOT NULL DEFAULT '0',
  `MaxDamage5` smallint unsigned NOT NULL DEFAULT '0',
  `Resistances1` smallint NOT NULL DEFAULT '0',
  `Resistances2` smallint NOT NULL DEFAULT '0',
  `Resistances3` smallint NOT NULL DEFAULT '0',
  `Resistances4` smallint NOT NULL DEFAULT '0',
  `Resistances5` smallint NOT NULL DEFAULT '0',
  `Resistances6` smallint NOT NULL DEFAULT '0',
  `Resistances7` smallint NOT NULL DEFAULT '0',
  `ScalingStatDistributionID` smallint unsigned NOT NULL DEFAULT '0',
  `StatModifierBonusAmount1` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount2` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount3` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount4` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount5` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount6` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount7` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount8` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount9` smallint NOT NULL DEFAULT '0',
  `StatModifierBonusAmount10` smallint NOT NULL DEFAULT '0',
  `ExpansionID` tinyint unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellWeight` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellWeightCategory` tinyint unsigned NOT NULL DEFAULT '0',
  `SocketType1` tinyint unsigned NOT NULL DEFAULT '0',
  `SocketType2` tinyint unsigned NOT NULL DEFAULT '0',
  `SocketType3` tinyint unsigned NOT NULL DEFAULT '0',
  `SheatheType` tinyint unsigned NOT NULL DEFAULT '0',
  `Material` tinyint unsigned NOT NULL DEFAULT '0',
  `PageMaterialID` tinyint unsigned NOT NULL DEFAULT '0',
  `LanguageID` tinyint unsigned NOT NULL DEFAULT '0',
  `Bonding` tinyint unsigned NOT NULL DEFAULT '0',
  `DamageDamageType` tinyint unsigned NOT NULL DEFAULT '0',
  `ContainerSlots` tinyint unsigned NOT NULL DEFAULT '0',
  `RequiredPVPMedal` tinyint unsigned NOT NULL DEFAULT '0',
  `RequiredPVPRank` tinyint unsigned NOT NULL DEFAULT '0',
  `InventoryType` tinyint NOT NULL DEFAULT '0',
  `OverallQualityID` tinyint NOT NULL DEFAULT '0',
  `AmmunitionType` tinyint unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Display3_lang` text,
  `Display2_lang` text,
  `Display1_lang` text,
  `Display_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Table structure for table `item_x_bonus_tree`
--

DROP TABLE IF EXISTS `item_x_bonus_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_x_bonus_tree` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemBonusTreeID` smallint unsigned NOT NULL DEFAULT '0',
  `ItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_x_bonus_tree`
--

LOCK TABLES `item_x_bonus_tree` WRITE;
/*!40000 ALTER TABLE `item_x_bonus_tree` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_x_bonus_tree` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_encounter`
--

DROP TABLE IF EXISTS `journal_encounter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter` (
  `Name` text,
  `Description` text,
  `MapX` float NOT NULL DEFAULT '0',
  `MapY` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `JournalInstanceID` smallint unsigned NOT NULL DEFAULT '0',
  `DungeonEncounterID` smallint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int unsigned NOT NULL DEFAULT '0',
  `FirstSectionID` smallint unsigned NOT NULL DEFAULT '0',
  `UiMapID` smallint unsigned NOT NULL DEFAULT '0',
  `MapDisplayConditionID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `DifficultyMask` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `journal_encounter`
--

LOCK TABLES `journal_encounter` WRITE;
/*!40000 ALTER TABLE `journal_encounter` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_encounter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_encounter_locale`
--

DROP TABLE IF EXISTS `journal_encounter_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `journal_encounter_locale`
--

LOCK TABLES `journal_encounter_locale` WRITE;
/*!40000 ALTER TABLE `journal_encounter_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_encounter_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_encounter_section`
--

DROP TABLE IF EXISTS `journal_encounter_section`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_section` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Title` text,
  `BodyText` text,
  `JournalEncounterID` smallint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `ParentSectionID` smallint unsigned NOT NULL DEFAULT '0',
  `FirstChildSectionID` smallint unsigned NOT NULL DEFAULT '0',
  `NextSiblingSectionID` smallint unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `IconCreatureDisplayInfoID` int unsigned NOT NULL DEFAULT '0',
  `UiModelSceneID` int NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `IconFileDataID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `IconFlags` int NOT NULL DEFAULT '0',
  `DifficultyMask` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `journal_encounter_section`
--

LOCK TABLES `journal_encounter_section` WRITE;
/*!40000 ALTER TABLE `journal_encounter_section` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_encounter_section` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_encounter_section_locale`
--

DROP TABLE IF EXISTS `journal_encounter_section_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_section_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Title_lang` text,
  `BodyText_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `journal_encounter_section_locale`
--

LOCK TABLES `journal_encounter_section_locale` WRITE;
/*!40000 ALTER TABLE `journal_encounter_section_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_encounter_section_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_instance`
--

DROP TABLE IF EXISTS `journal_instance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_instance` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `MapID` smallint unsigned NOT NULL DEFAULT '0',
  `BackgroundFileDataID` int NOT NULL DEFAULT '0',
  `ButtonFileDataID` int NOT NULL DEFAULT '0',
  `ButtonSmallFileDataID` int NOT NULL DEFAULT '0',
  `LoreFileDataID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `AreaID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `journal_instance`
--

LOCK TABLES `journal_instance` WRITE;
/*!40000 ALTER TABLE `journal_instance` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_instance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_instance_locale`
--

DROP TABLE IF EXISTS `journal_instance_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_instance_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `journal_instance_locale`
--

LOCK TABLES `journal_instance_locale` WRITE;
/*!40000 ALTER TABLE `journal_instance_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_instance_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_tier`
--

DROP TABLE IF EXISTS `journal_tier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_tier` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `journal_tier`
--

LOCK TABLES `journal_tier` WRITE;
/*!40000 ALTER TABLE `journal_tier` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_tier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `journal_tier_locale`
--

DROP TABLE IF EXISTS `journal_tier_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_tier_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `journal_tier_locale`
--

LOCK TABLES `journal_tier_locale` WRITE;
/*!40000 ALTER TABLE `journal_tier_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `journal_tier_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `keychain`
--

DROP TABLE IF EXISTS `keychain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `keychain` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Key1` tinyint unsigned NOT NULL DEFAULT '0',
  `Key2` tinyint unsigned NOT NULL DEFAULT '0',
  `Key3` tinyint unsigned NOT NULL DEFAULT '0',
  `Key4` tinyint unsigned NOT NULL DEFAULT '0',
  `Key5` tinyint unsigned NOT NULL DEFAULT '0',
  `Key6` tinyint unsigned NOT NULL DEFAULT '0',
  `Key7` tinyint unsigned NOT NULL DEFAULT '0',
  `Key8` tinyint unsigned NOT NULL DEFAULT '0',
  `Key9` tinyint unsigned NOT NULL DEFAULT '0',
  `Key10` tinyint unsigned NOT NULL DEFAULT '0',
  `Key11` tinyint unsigned NOT NULL DEFAULT '0',
  `Key12` tinyint unsigned NOT NULL DEFAULT '0',
  `Key13` tinyint unsigned NOT NULL DEFAULT '0',
  `Key14` tinyint unsigned NOT NULL DEFAULT '0',
  `Key15` tinyint unsigned NOT NULL DEFAULT '0',
  `Key16` tinyint unsigned NOT NULL DEFAULT '0',
  `Key17` tinyint unsigned NOT NULL DEFAULT '0',
  `Key18` tinyint unsigned NOT NULL DEFAULT '0',
  `Key19` tinyint unsigned NOT NULL DEFAULT '0',
  `Key20` tinyint unsigned NOT NULL DEFAULT '0',
  `Key21` tinyint unsigned NOT NULL DEFAULT '0',
  `Key22` tinyint unsigned NOT NULL DEFAULT '0',
  `Key23` tinyint unsigned NOT NULL DEFAULT '0',
  `Key24` tinyint unsigned NOT NULL DEFAULT '0',
  `Key25` tinyint unsigned NOT NULL DEFAULT '0',
  `Key26` tinyint unsigned NOT NULL DEFAULT '0',
  `Key27` tinyint unsigned NOT NULL DEFAULT '0',
  `Key28` tinyint unsigned NOT NULL DEFAULT '0',
  `Key29` tinyint unsigned NOT NULL DEFAULT '0',
  `Key30` tinyint unsigned NOT NULL DEFAULT '0',
  `Key31` tinyint unsigned NOT NULL DEFAULT '0',
  `Key32` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `keychain`
--

LOCK TABLES `keychain` WRITE;
/*!40000 ALTER TABLE `keychain` DISABLE KEYS */;
/*!40000 ALTER TABLE `keychain` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `keystone_affix`
--

DROP TABLE IF EXISTS `keystone_affix`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `keystone_affix` (
  `Name` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FiledataID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `keystone_affix`
--

LOCK TABLES `keystone_affix` WRITE;
/*!40000 ALTER TABLE `keystone_affix` DISABLE KEYS */;
/*!40000 ALTER TABLE `keystone_affix` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `keystone_affix_locale`
--

DROP TABLE IF EXISTS `keystone_affix_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `keystone_affix_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `keystone_affix_locale`
--

LOCK TABLES `keystone_affix_locale` WRITE;
/*!40000 ALTER TABLE `keystone_affix_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `keystone_affix_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `language_words`
--

DROP TABLE IF EXISTS `language_words`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `language_words` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Word` text,
  `LanguageID` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `language_words`
--

LOCK TABLES `language_words` WRITE;
/*!40000 ALTER TABLE `language_words` DISABLE KEYS */;
/*!40000 ALTER TABLE `language_words` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `languages`
--

DROP TABLE IF EXISTS `languages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `languages` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `UiTextureKitID` int NOT NULL DEFAULT '0',
  `UiTextureKitElementCount` int NOT NULL DEFAULT '0',
  `LearningCurveID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `languages`
--

LOCK TABLES `languages` WRITE;
/*!40000 ALTER TABLE `languages` DISABLE KEYS */;
/*!40000 ALTER TABLE `languages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `languages_locale`
--

DROP TABLE IF EXISTS `languages_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `languages_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `languages_locale`
--

LOCK TABLES `languages_locale` WRITE;
/*!40000 ALTER TABLE `languages_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `languages_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `lfg_dungeons`
--

DROP TABLE IF EXISTS `lfg_dungeons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `lfg_dungeons` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `MinLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxLevel` smallint unsigned NOT NULL DEFAULT '0',
  `TypeID` tinyint unsigned NOT NULL DEFAULT '0',
  `Subtype` tinyint unsigned NOT NULL DEFAULT '0',
  `Faction` tinyint NOT NULL DEFAULT '0',
  `IconTextureFileID` int NOT NULL DEFAULT '0',
  `RewardsBgTextureFileID` int NOT NULL DEFAULT '0',
  `PopupBgTextureFileID` int NOT NULL DEFAULT '0',
  `ExpansionLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MapID` smallint NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `MinGear` float NOT NULL DEFAULT '0',
  `GroupID` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `RequiredPlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `TargetLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetLevelMin` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetLevelMax` smallint unsigned NOT NULL DEFAULT '0',
  `RandomID` smallint unsigned NOT NULL DEFAULT '0',
  `ScenarioID` smallint unsigned NOT NULL DEFAULT '0',
  `FinalEncounterID` smallint unsigned NOT NULL DEFAULT '0',
  `CountTank` tinyint unsigned NOT NULL DEFAULT '0',
  `CountHealer` tinyint unsigned NOT NULL DEFAULT '0',
  `CountDamage` tinyint unsigned NOT NULL DEFAULT '0',
  `MinCountTank` tinyint unsigned NOT NULL DEFAULT '0',
  `MinCountHealer` tinyint unsigned NOT NULL DEFAULT '0',
  `MinCountDamage` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPremadeCountTank` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPremadeCountHealer` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPremadeCountDamage` tinyint unsigned NOT NULL DEFAULT '0',
  `BonusReputationAmount` smallint unsigned NOT NULL DEFAULT '0',
  `MentorItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `MentorCharLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `lfg_dungeons`
--

LOCK TABLES `lfg_dungeons` WRITE;
/*!40000 ALTER TABLE `lfg_dungeons` DISABLE KEYS */;
/*!40000 ALTER TABLE `lfg_dungeons` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `lfg_dungeons_locale`
--

DROP TABLE IF EXISTS `lfg_dungeons_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `lfg_dungeons_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `lfg_dungeons_locale`
--

LOCK TABLES `lfg_dungeons_locale` WRITE;
/*!40000 ALTER TABLE `lfg_dungeons_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `lfg_dungeons_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `light`
--

DROP TABLE IF EXISTS `light`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `light` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `GameCoordsX` float NOT NULL DEFAULT '0',
  `GameCoordsY` float NOT NULL DEFAULT '0',
  `GameCoordsZ` float NOT NULL DEFAULT '0',
  `GameFalloffStart` float NOT NULL DEFAULT '0',
  `GameFalloffEnd` float NOT NULL DEFAULT '0',
  `ContinentID` smallint NOT NULL DEFAULT '0',
  `LightParamsID1` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID2` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID3` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID4` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID5` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID6` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID7` smallint unsigned NOT NULL DEFAULT '0',
  `LightParamsID8` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `light`
--

LOCK TABLES `light` WRITE;
/*!40000 ALTER TABLE `light` DISABLE KEYS */;
/*!40000 ALTER TABLE `light` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `liquid_type`
--

DROP TABLE IF EXISTS `liquid_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `liquid_type` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Texture1` text,
  `Texture2` text,
  `Texture3` text,
  `Texture4` text,
  `Texture5` text,
  `Texture6` text,
  `Flags` smallint unsigned NOT NULL DEFAULT '0',
  `SoundBank` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `MaxDarkenDepth` float NOT NULL DEFAULT '0',
  `FogDarkenIntensity` float NOT NULL DEFAULT '0',
  `AmbDarkenIntensity` float NOT NULL DEFAULT '0',
  `DirDarkenIntensity` float NOT NULL DEFAULT '0',
  `LightID` smallint unsigned NOT NULL DEFAULT '0',
  `ParticleScale` float NOT NULL DEFAULT '0',
  `ParticleMovement` tinyint unsigned NOT NULL DEFAULT '0',
  `ParticleTexSlots` tinyint unsigned NOT NULL DEFAULT '0',
  `MaterialID` tinyint unsigned NOT NULL DEFAULT '0',
  `MinimapStaticCol` int NOT NULL DEFAULT '0',
  `FrameCountTexture1` tinyint unsigned NOT NULL DEFAULT '0',
  `FrameCountTexture2` tinyint unsigned NOT NULL DEFAULT '0',
  `FrameCountTexture3` tinyint unsigned NOT NULL DEFAULT '0',
  `FrameCountTexture4` tinyint unsigned NOT NULL DEFAULT '0',
  `FrameCountTexture5` tinyint unsigned NOT NULL DEFAULT '0',
  `FrameCountTexture6` tinyint unsigned NOT NULL DEFAULT '0',
  `Color1` int NOT NULL DEFAULT '0',
  `Color2` int NOT NULL DEFAULT '0',
  `Float1` float NOT NULL DEFAULT '0',
  `Float2` float NOT NULL DEFAULT '0',
  `Float3` float NOT NULL DEFAULT '0',
  `Float4` float NOT NULL DEFAULT '0',
  `Float5` float NOT NULL DEFAULT '0',
  `Float6` float NOT NULL DEFAULT '0',
  `Float7` float NOT NULL DEFAULT '0',
  `Float8` float NOT NULL DEFAULT '0',
  `Float9` float NOT NULL DEFAULT '0',
  `Float10` float NOT NULL DEFAULT '0',
  `Float11` float NOT NULL DEFAULT '0',
  `Float12` float NOT NULL DEFAULT '0',
  `Float13` float NOT NULL DEFAULT '0',
  `Float14` float NOT NULL DEFAULT '0',
  `Float15` float NOT NULL DEFAULT '0',
  `Float16` float NOT NULL DEFAULT '0',
  `Float17` float NOT NULL DEFAULT '0',
  `Float18` float NOT NULL DEFAULT '0',
  `Int1` int unsigned NOT NULL DEFAULT '0',
  `Int2` int unsigned NOT NULL DEFAULT '0',
  `Int3` int unsigned NOT NULL DEFAULT '0',
  `Int4` int unsigned NOT NULL DEFAULT '0',
  `Coefficient1` float NOT NULL DEFAULT '0',
  `Coefficient2` float NOT NULL DEFAULT '0',
  `Coefficient3` float NOT NULL DEFAULT '0',
  `Coefficient4` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `liquid_type`
--

LOCK TABLES `liquid_type` WRITE;
/*!40000 ALTER TABLE `liquid_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `liquid_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `location`
--

DROP TABLE IF EXISTS `location`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `location` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `location`
--

LOCK TABLES `location` WRITE;
/*!40000 ALTER TABLE `location` DISABLE KEYS */;
/*!40000 ALTER TABLE `location` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `lock`
--

DROP TABLE IF EXISTS `lock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `lock` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Index1` int NOT NULL DEFAULT '0',
  `Index2` int NOT NULL DEFAULT '0',
  `Index3` int NOT NULL DEFAULT '0',
  `Index4` int NOT NULL DEFAULT '0',
  `Index5` int NOT NULL DEFAULT '0',
  `Index6` int NOT NULL DEFAULT '0',
  `Index7` int NOT NULL DEFAULT '0',
  `Index8` int NOT NULL DEFAULT '0',
  `Skill1` smallint unsigned NOT NULL DEFAULT '0',
  `Skill2` smallint unsigned NOT NULL DEFAULT '0',
  `Skill3` smallint unsigned NOT NULL DEFAULT '0',
  `Skill4` smallint unsigned NOT NULL DEFAULT '0',
  `Skill5` smallint unsigned NOT NULL DEFAULT '0',
  `Skill6` smallint unsigned NOT NULL DEFAULT '0',
  `Skill7` smallint unsigned NOT NULL DEFAULT '0',
  `Skill8` smallint unsigned NOT NULL DEFAULT '0',
  `Type1` tinyint unsigned NOT NULL DEFAULT '0',
  `Type2` tinyint unsigned NOT NULL DEFAULT '0',
  `Type3` tinyint unsigned NOT NULL DEFAULT '0',
  `Type4` tinyint unsigned NOT NULL DEFAULT '0',
  `Type5` tinyint unsigned NOT NULL DEFAULT '0',
  `Type6` tinyint unsigned NOT NULL DEFAULT '0',
  `Type7` tinyint unsigned NOT NULL DEFAULT '0',
  `Type8` tinyint unsigned NOT NULL DEFAULT '0',
  `Action1` tinyint unsigned NOT NULL DEFAULT '0',
  `Action2` tinyint unsigned NOT NULL DEFAULT '0',
  `Action3` tinyint unsigned NOT NULL DEFAULT '0',
  `Action4` tinyint unsigned NOT NULL DEFAULT '0',
  `Action5` tinyint unsigned NOT NULL DEFAULT '0',
  `Action6` tinyint unsigned NOT NULL DEFAULT '0',
  `Action7` tinyint unsigned NOT NULL DEFAULT '0',
  `Action8` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `lock`
--

LOCK TABLES `lock` WRITE;
/*!40000 ALTER TABLE `lock` DISABLE KEYS */;
/*!40000 ALTER TABLE `lock` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mail_template`
--

DROP TABLE IF EXISTS `mail_template`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mail_template` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Body` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mail_template`
--

LOCK TABLES `mail_template` WRITE;
/*!40000 ALTER TABLE `mail_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `mail_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mail_template_locale`
--

DROP TABLE IF EXISTS `mail_template_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mail_template_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Body_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `mail_template_locale`
--

LOCK TABLES `mail_template_locale` WRITE;
/*!40000 ALTER TABLE `mail_template_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `mail_template_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map`
--

DROP TABLE IF EXISTS `map`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Directory` text,
  `MapName` text,
  `MapDescription0` text,
  `MapDescription1` text,
  `PvpShortDescription` text,
  `PvpLongDescription` text,
  `MapType` tinyint unsigned NOT NULL DEFAULT '0',
  `InstanceType` tinyint NOT NULL DEFAULT '0',
  `ExpansionID` tinyint unsigned NOT NULL DEFAULT '0',
  `AreaTableID` smallint unsigned NOT NULL DEFAULT '0',
  `LoadingScreenID` smallint NOT NULL DEFAULT '0',
  `TimeOfDayOverride` smallint NOT NULL DEFAULT '0',
  `ParentMapID` smallint NOT NULL DEFAULT '0',
  `CosmeticParentMapID` smallint NOT NULL DEFAULT '0',
  `TimeOffset` tinyint unsigned NOT NULL DEFAULT '0',
  `MinimapIconScale` float NOT NULL DEFAULT '0',
  `RaidOffset` int NOT NULL DEFAULT '0',
  `CorpseMapID` smallint NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint unsigned NOT NULL DEFAULT '0',
  `WindSettingsID` smallint NOT NULL DEFAULT '0',
  `ZmpFileDataID` int NOT NULL DEFAULT '0',
  `PreloadFileDataID` int NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `Flags3` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `map`
--

LOCK TABLES `map` WRITE;
/*!40000 ALTER TABLE `map` DISABLE KEYS */;
/*!40000 ALTER TABLE `map` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_locale`
--

DROP TABLE IF EXISTS `map_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `MapName_lang` text,
  `MapDescription0_lang` text,
  `MapDescription1_lang` text,
  `PvpShortDescription_lang` text,
  `PvpLongDescription_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `map_locale`
--

LOCK TABLES `map_locale` WRITE;
/*!40000 ALTER TABLE `map_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_challenge_mode`
--

DROP TABLE IF EXISTS `map_challenge_mode`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_challenge_mode` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MapID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `ExpansionLevel` int unsigned NOT NULL DEFAULT '0',
  `RequiredWorldStateID` int NOT NULL DEFAULT '0',
  `CriteriaCount1` smallint NOT NULL DEFAULT '0',
  `CriteriaCount2` smallint NOT NULL DEFAULT '0',
  `CriteriaCount3` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `map_challenge_mode`
--

LOCK TABLES `map_challenge_mode` WRITE;
/*!40000 ALTER TABLE `map_challenge_mode` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_challenge_mode` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_challenge_mode_locale`
--

DROP TABLE IF EXISTS `map_challenge_mode_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_challenge_mode_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `map_challenge_mode_locale`
--

LOCK TABLES `map_challenge_mode_locale` WRITE;
/*!40000 ALTER TABLE `map_challenge_mode_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_challenge_mode_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_difficulty`
--

DROP TABLE IF EXISTS `map_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_difficulty` (
  `Message` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int NOT NULL DEFAULT '0',
  `LockID` int NOT NULL DEFAULT '0',
  `ResetInterval` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` int NOT NULL DEFAULT '0',
  `ItemContext` tinyint unsigned NOT NULL DEFAULT '0',
  `ItemContextPickerID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ContentTuningID` int NOT NULL DEFAULT '0',
  `WorldStateExpressionID` int NOT NULL DEFAULT '0',
  `MapID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `map_difficulty`
--

LOCK TABLES `map_difficulty` WRITE;
/*!40000 ALTER TABLE `map_difficulty` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_difficulty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_difficulty_locale`
--

DROP TABLE IF EXISTS `map_difficulty_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_difficulty_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Message_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `map_difficulty_locale`
--

LOCK TABLES `map_difficulty_locale` WRITE;
/*!40000 ALTER TABLE `map_difficulty_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_difficulty_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_difficulty_x_condition`
--

DROP TABLE IF EXISTS `map_difficulty_x_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_difficulty_x_condition` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FailureDescription` text,
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `MapDifficultyID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `map_difficulty_x_condition`
--

LOCK TABLES `map_difficulty_x_condition` WRITE;
/*!40000 ALTER TABLE `map_difficulty_x_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_difficulty_x_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `map_difficulty_x_condition_locale`
--

DROP TABLE IF EXISTS `map_difficulty_x_condition_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_difficulty_x_condition_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `FailureDescription_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `map_difficulty_x_condition_locale`
--

LOCK TABLES `map_difficulty_x_condition_locale` WRITE;
/*!40000 ALTER TABLE `map_difficulty_x_condition_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_difficulty_x_condition_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `modifier_tree`
--

DROP TABLE IF EXISTS `modifier_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `modifier_tree` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Parent` int unsigned NOT NULL DEFAULT '0',
  `Operator` tinyint NOT NULL DEFAULT '0',
  `Amount` tinyint NOT NULL DEFAULT '0',
  `Type` int NOT NULL DEFAULT '0',
  `Asset` int NOT NULL DEFAULT '0',
  `SecondaryAsset` int NOT NULL DEFAULT '0',
  `TertiaryAsset` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `modifier_tree`
--

LOCK TABLES `modifier_tree` WRITE;
/*!40000 ALTER TABLE `modifier_tree` DISABLE KEYS */;
/*!40000 ALTER TABLE `modifier_tree` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mount`
--

DROP TABLE IF EXISTS `mount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mount` (
  `Name` text,
  `SourceText` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MountTypeID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint NOT NULL DEFAULT '0',
  `SourceSpellID` int NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `MountFlyRideHeight` float NOT NULL DEFAULT '0',
  `UiModelSceneID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mount`
--

LOCK TABLES `mount` WRITE;
/*!40000 ALTER TABLE `mount` DISABLE KEYS */;
/*!40000 ALTER TABLE `mount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mount_locale`
--

DROP TABLE IF EXISTS `mount_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mount_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `SourceText_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `mount_locale`
--

LOCK TABLES `mount_locale` WRITE;
/*!40000 ALTER TABLE `mount_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `mount_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mount_capability`
--

DROP TABLE IF EXISTS `mount_capability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mount_capability` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ReqRidingSkill` smallint unsigned NOT NULL DEFAULT '0',
  `ReqAreaID` smallint unsigned NOT NULL DEFAULT '0',
  `ReqSpellAuraID` int unsigned NOT NULL DEFAULT '0',
  `ReqSpellKnownID` int NOT NULL DEFAULT '0',
  `ModSpellAuraID` int NOT NULL DEFAULT '0',
  `ReqMapID` smallint NOT NULL DEFAULT '0',
  `PlayerConditionID` int NOT NULL DEFAULT '0',
  `FlightCapabilityID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mount_capability`
--

LOCK TABLES `mount_capability` WRITE;
/*!40000 ALTER TABLE `mount_capability` DISABLE KEYS */;
/*!40000 ALTER TABLE `mount_capability` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mount_type_x_capability`
--

DROP TABLE IF EXISTS `mount_type_x_capability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mount_type_x_capability` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MountTypeID` smallint unsigned NOT NULL DEFAULT '0',
  `MountCapabilityID` smallint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mount_type_x_capability`
--

LOCK TABLES `mount_type_x_capability` WRITE;
/*!40000 ALTER TABLE `mount_type_x_capability` DISABLE KEYS */;
/*!40000 ALTER TABLE `mount_type_x_capability` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mount_x_display`
--

DROP TABLE IF EXISTS `mount_x_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mount_x_display` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayInfoID` int NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `Unknown1100` smallint unsigned NOT NULL DEFAULT '0',
  `MountID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mount_x_display`
--

LOCK TABLES `mount_x_display` WRITE;
/*!40000 ALTER TABLE `mount_x_display` DISABLE KEYS */;
/*!40000 ALTER TABLE `mount_x_display` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie`
--

DROP TABLE IF EXISTS `movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `movie` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Volume` tinyint unsigned NOT NULL DEFAULT '0',
  `KeyID` tinyint unsigned NOT NULL DEFAULT '0',
  `AudioFileDataID` int unsigned NOT NULL DEFAULT '0',
  `SubtitleFileDataID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie`
--

LOCK TABLES `movie` WRITE;
/*!40000 ALTER TABLE `movie` DISABLE KEYS */;
/*!40000 ALTER TABLE `movie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mythic_plus_season`
--

DROP TABLE IF EXISTS `mythic_plus_season`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mythic_plus_season` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MilestoneSeason` int NOT NULL DEFAULT '0',
  `StartTimeEvent` int NOT NULL DEFAULT '0',
  `ExpansionLevel` int NOT NULL DEFAULT '0',
  `HeroicLFGDungeonMinGear` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mythic_plus_season`
--

LOCK TABLES `mythic_plus_season` WRITE;
/*!40000 ALTER TABLE `mythic_plus_season` DISABLE KEYS */;
/*!40000 ALTER TABLE `mythic_plus_season` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `name_gen`
--

DROP TABLE IF EXISTS `name_gen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `name_gen` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `RaceID` tinyint unsigned NOT NULL DEFAULT '0',
  `Sex` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `name_gen`
--

LOCK TABLES `name_gen` WRITE;
/*!40000 ALTER TABLE `name_gen` DISABLE KEYS */;
/*!40000 ALTER TABLE `name_gen` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `names_profanity`
--

DROP TABLE IF EXISTS `names_profanity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `names_profanity` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Language` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `names_profanity`
--

LOCK TABLES `names_profanity` WRITE;
/*!40000 ALTER TABLE `names_profanity` DISABLE KEYS */;
/*!40000 ALTER TABLE `names_profanity` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `names_reserved`
--

DROP TABLE IF EXISTS `names_reserved`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `names_reserved` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `names_reserved`
--

LOCK TABLES `names_reserved` WRITE;
/*!40000 ALTER TABLE `names_reserved` DISABLE KEYS */;
/*!40000 ALTER TABLE `names_reserved` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `names_reserved_locale`
--

DROP TABLE IF EXISTS `names_reserved_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `names_reserved_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `LocaleMask` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `names_reserved_locale`
--

LOCK TABLES `names_reserved_locale` WRITE;
/*!40000 ALTER TABLE `names_reserved_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `names_reserved_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `num_talents_at_level`
--

DROP TABLE IF EXISTS `num_talents_at_level`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `num_talents_at_level` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `NumTalents` int NOT NULL DEFAULT '0',
  `NumTalentsDeathKnight` int NOT NULL DEFAULT '0',
  `NumTalentsDemonHunter` int NOT NULL DEFAULT '0',
  `NumberOfTalents` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `num_talents_at_level`
--

LOCK TABLES `num_talents_at_level` WRITE;
/*!40000 ALTER TABLE `num_talents_at_level` DISABLE KEYS */;
/*!40000 ALTER TABLE `num_talents_at_level` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `override_spell_data`
--

DROP TABLE IF EXISTS `override_spell_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `override_spell_data` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Spells1` int NOT NULL DEFAULT '0',
  `Spells2` int NOT NULL DEFAULT '0',
  `Spells3` int NOT NULL DEFAULT '0',
  `Spells4` int NOT NULL DEFAULT '0',
  `Spells5` int NOT NULL DEFAULT '0',
  `Spells6` int NOT NULL DEFAULT '0',
  `Spells7` int NOT NULL DEFAULT '0',
  `Spells8` int NOT NULL DEFAULT '0',
  `Spells9` int NOT NULL DEFAULT '0',
  `Spells10` int NOT NULL DEFAULT '0',
  `PlayerActionBarFileDataID` int NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `override_spell_data`
--

LOCK TABLES `override_spell_data` WRITE;
/*!40000 ALTER TABLE `override_spell_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `override_spell_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `paragon_reputation`
--

DROP TABLE IF EXISTS `paragon_reputation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `paragon_reputation` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FactionID` int NOT NULL DEFAULT '0',
  `LevelThreshold` int NOT NULL DEFAULT '0',
  `QuestID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `paragon_reputation`
--

LOCK TABLES `paragon_reputation` WRITE;
/*!40000 ALTER TABLE `paragon_reputation` DISABLE KEYS */;
/*!40000 ALTER TABLE `paragon_reputation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `path`
--

DROP TABLE IF EXISTS `path`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `path` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `SplineType` tinyint unsigned NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `Alpha` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `path`
--

LOCK TABLES `path` WRITE;
/*!40000 ALTER TABLE `path` DISABLE KEYS */;
/*!40000 ALTER TABLE `path` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `path_node`
--

DROP TABLE IF EXISTS `path_node`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `path_node` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PathID` smallint unsigned NOT NULL DEFAULT '0',
  `Sequence` smallint NOT NULL DEFAULT '0',
  `LocationID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `path_node`
--

LOCK TABLES `path_node` WRITE;
/*!40000 ALTER TABLE `path_node` DISABLE KEYS */;
/*!40000 ALTER TABLE `path_node` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `path_property`
--

DROP TABLE IF EXISTS `path_property`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `path_property` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PathID` smallint unsigned NOT NULL DEFAULT '0',
  `PropertyIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `Value` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `path_property`
--

LOCK TABLES `path_property` WRITE;
/*!40000 ALTER TABLE `path_property` DISABLE KEYS */;
/*!40000 ALTER TABLE `path_property` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phase`
--

DROP TABLE IF EXISTS `phase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `phase` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `phase`
--

LOCK TABLES `phase` WRITE;
/*!40000 ALTER TABLE `phase` DISABLE KEYS */;
/*!40000 ALTER TABLE `phase` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phase_x_phase_group`
--

DROP TABLE IF EXISTS `phase_x_phase_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `phase_x_phase_group` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PhaseID` smallint unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `phase_x_phase_group`
--

LOCK TABLES `phase_x_phase_group` WRITE;
/*!40000 ALTER TABLE `phase_x_phase_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `phase_x_phase_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_condition`
--

DROP TABLE IF EXISTS `player_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `player_condition` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `FailureDescription` text,
  `MinLevel` smallint unsigned NOT NULL DEFAULT '0',
  `MaxLevel` smallint unsigned NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `SkillLogic` int unsigned NOT NULL DEFAULT '0',
  `LanguageID` int NOT NULL DEFAULT '0',
  `MinLanguage` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxLanguage` int NOT NULL DEFAULT '0',
  `MaxFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `MaxReputation` tinyint unsigned NOT NULL DEFAULT '0',
  `ReputationLogic` int unsigned NOT NULL DEFAULT '0',
  `CurrentPvpFaction` tinyint NOT NULL DEFAULT '0',
  `PvpMedal` tinyint unsigned NOT NULL DEFAULT '0',
  `PrevQuestLogic` int unsigned NOT NULL DEFAULT '0',
  `CurrQuestLogic` int unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestLogic` int unsigned NOT NULL DEFAULT '0',
  `SpellLogic` int unsigned NOT NULL DEFAULT '0',
  `ItemLogic` int unsigned NOT NULL DEFAULT '0',
  `ItemFlags` tinyint unsigned NOT NULL DEFAULT '0',
  `AuraSpellLogic` int unsigned NOT NULL DEFAULT '0',
  `WorldStateExpressionID` smallint unsigned NOT NULL DEFAULT '0',
  `WeatherID` int NOT NULL DEFAULT '0',
  `PartyStatus` tinyint unsigned NOT NULL DEFAULT '0',
  `LifetimeMaxPVPRank` tinyint unsigned NOT NULL DEFAULT '0',
  `AchievementLogic` int unsigned NOT NULL DEFAULT '0',
  `Gender` tinyint NOT NULL DEFAULT '0',
  `NativeGender` tinyint NOT NULL DEFAULT '0',
  `AreaLogic` int unsigned NOT NULL DEFAULT '0',
  `LfgLogic` int unsigned NOT NULL DEFAULT '0',
  `CurrencyLogic` int unsigned NOT NULL DEFAULT '0',
  `QuestKillID` int NOT NULL DEFAULT '0',
  `QuestKillLogic` int unsigned NOT NULL DEFAULT '0',
  `MinExpansionLevel` tinyint NOT NULL DEFAULT '0',
  `MaxExpansionLevel` tinyint NOT NULL DEFAULT '0',
  `MinAvgItemLevel` int NOT NULL DEFAULT '0',
  `MaxAvgItemLevel` int NOT NULL DEFAULT '0',
  `MinAvgEquippedItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `MaxAvgEquippedItemLevel` smallint unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` int NOT NULL DEFAULT '0',
  `PhaseID` smallint unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `ChrSpecializationIndex` tinyint NOT NULL DEFAULT '0',
  `ChrSpecializationRole` tinyint NOT NULL DEFAULT '0',
  `ModifierTreeID` int unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint NOT NULL DEFAULT '0',
  `PowerTypeComp` tinyint unsigned NOT NULL DEFAULT '0',
  `PowerTypeValue` tinyint unsigned NOT NULL DEFAULT '0',
  `WeaponSubclassMask` int NOT NULL DEFAULT '0',
  `MaxGuildLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MinGuildLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxExpansionTier` tinyint NOT NULL DEFAULT '0',
  `MinExpansionTier` tinyint NOT NULL DEFAULT '0',
  `MinPVPRank` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxPVPRank` tinyint unsigned NOT NULL DEFAULT '0',
  `ContentTuningID` int NOT NULL DEFAULT '0',
  `CovenantID` int NOT NULL DEFAULT '0',
  `TraitNodeEntryLogic` int unsigned NOT NULL DEFAULT '0',
  `SkillID1` smallint unsigned NOT NULL DEFAULT '0',
  `SkillID2` smallint unsigned NOT NULL DEFAULT '0',
  `SkillID3` smallint unsigned NOT NULL DEFAULT '0',
  `SkillID4` smallint unsigned NOT NULL DEFAULT '0',
  `MinSkill1` smallint unsigned NOT NULL DEFAULT '0',
  `MinSkill2` smallint unsigned NOT NULL DEFAULT '0',
  `MinSkill3` smallint unsigned NOT NULL DEFAULT '0',
  `MinSkill4` smallint unsigned NOT NULL DEFAULT '0',
  `MaxSkill1` smallint unsigned NOT NULL DEFAULT '0',
  `MaxSkill2` smallint unsigned NOT NULL DEFAULT '0',
  `MaxSkill3` smallint unsigned NOT NULL DEFAULT '0',
  `MaxSkill4` smallint unsigned NOT NULL DEFAULT '0',
  `MinFactionID1` int unsigned NOT NULL DEFAULT '0',
  `MinFactionID2` int unsigned NOT NULL DEFAULT '0',
  `MinFactionID3` int unsigned NOT NULL DEFAULT '0',
  `MinReputation1` tinyint unsigned NOT NULL DEFAULT '0',
  `MinReputation2` tinyint unsigned NOT NULL DEFAULT '0',
  `MinReputation3` tinyint unsigned NOT NULL DEFAULT '0',
  `PrevQuestID1` int NOT NULL DEFAULT '0',
  `PrevQuestID2` int NOT NULL DEFAULT '0',
  `PrevQuestID3` int NOT NULL DEFAULT '0',
  `PrevQuestID4` int NOT NULL DEFAULT '0',
  `CurrQuestID1` int NOT NULL DEFAULT '0',
  `CurrQuestID2` int NOT NULL DEFAULT '0',
  `CurrQuestID3` int NOT NULL DEFAULT '0',
  `CurrQuestID4` int NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID1` int NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID2` int NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID3` int NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID4` int NOT NULL DEFAULT '0',
  `SpellID1` int NOT NULL DEFAULT '0',
  `SpellID2` int NOT NULL DEFAULT '0',
  `SpellID3` int NOT NULL DEFAULT '0',
  `SpellID4` int NOT NULL DEFAULT '0',
  `ItemID1` int NOT NULL DEFAULT '0',
  `ItemID2` int NOT NULL DEFAULT '0',
  `ItemID3` int NOT NULL DEFAULT '0',
  `ItemID4` int NOT NULL DEFAULT '0',
  `ItemCount1` int unsigned NOT NULL DEFAULT '0',
  `ItemCount2` int unsigned NOT NULL DEFAULT '0',
  `ItemCount3` int unsigned NOT NULL DEFAULT '0',
  `ItemCount4` int unsigned NOT NULL DEFAULT '0',
  `Explored1` smallint unsigned NOT NULL DEFAULT '0',
  `Explored2` smallint unsigned NOT NULL DEFAULT '0',
  `Time1` int unsigned NOT NULL DEFAULT '0',
  `Time2` int unsigned NOT NULL DEFAULT '0',
  `AuraSpellID1` int NOT NULL DEFAULT '0',
  `AuraSpellID2` int NOT NULL DEFAULT '0',
  `AuraSpellID3` int NOT NULL DEFAULT '0',
  `AuraSpellID4` int NOT NULL DEFAULT '0',
  `AuraStacks1` tinyint unsigned NOT NULL DEFAULT '0',
  `AuraStacks2` tinyint unsigned NOT NULL DEFAULT '0',
  `AuraStacks3` tinyint unsigned NOT NULL DEFAULT '0',
  `AuraStacks4` tinyint unsigned NOT NULL DEFAULT '0',
  `Achievement1` smallint unsigned NOT NULL DEFAULT '0',
  `Achievement2` smallint unsigned NOT NULL DEFAULT '0',
  `Achievement3` smallint unsigned NOT NULL DEFAULT '0',
  `Achievement4` smallint unsigned NOT NULL DEFAULT '0',
  `AreaID1` smallint unsigned NOT NULL DEFAULT '0',
  `AreaID2` smallint unsigned NOT NULL DEFAULT '0',
  `AreaID3` smallint unsigned NOT NULL DEFAULT '0',
  `AreaID4` smallint unsigned NOT NULL DEFAULT '0',
  `LfgStatus1` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgStatus2` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgStatus3` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgStatus4` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgCompare1` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgCompare2` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgCompare3` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgCompare4` tinyint unsigned NOT NULL DEFAULT '0',
  `LfgValue1` int unsigned NOT NULL DEFAULT '0',
  `LfgValue2` int unsigned NOT NULL DEFAULT '0',
  `LfgValue3` int unsigned NOT NULL DEFAULT '0',
  `LfgValue4` int unsigned NOT NULL DEFAULT '0',
  `CurrencyID1` int unsigned NOT NULL DEFAULT '0',
  `CurrencyID2` int unsigned NOT NULL DEFAULT '0',
  `CurrencyID3` int unsigned NOT NULL DEFAULT '0',
  `CurrencyID4` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount1` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount2` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount3` int unsigned NOT NULL DEFAULT '0',
  `CurrencyCount4` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster1` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster2` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster3` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster4` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster5` int unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster6` int unsigned NOT NULL DEFAULT '0',
  `MovementFlags1` int NOT NULL DEFAULT '0',
  `MovementFlags2` int NOT NULL DEFAULT '0',
  `TraitNodeEntryID1` int NOT NULL DEFAULT '0',
  `TraitNodeEntryID2` int NOT NULL DEFAULT '0',
  `TraitNodeEntryID3` int NOT NULL DEFAULT '0',
  `TraitNodeEntryID4` int NOT NULL DEFAULT '0',
  `TraitNodeEntryMinRank1` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMinRank2` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMinRank3` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMinRank4` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMaxRank1` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMaxRank2` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMaxRank3` smallint unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryMaxRank4` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player_condition`
--

LOCK TABLES `player_condition` WRITE;
/*!40000 ALTER TABLE `player_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `player_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_condition_locale`
--

DROP TABLE IF EXISTS `player_condition_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `player_condition_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `FailureDescription_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `player_condition_locale`
--

LOCK TABLES `player_condition_locale` WRITE;
/*!40000 ALTER TABLE `player_condition_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `player_condition_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `power_display`
--

DROP TABLE IF EXISTS `power_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `power_display` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `GlobalStringBaseTag` text,
  `ActualType` tinyint NOT NULL DEFAULT '0',
  `Red` tinyint unsigned NOT NULL DEFAULT '0',
  `Green` tinyint unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `power_display`
--

LOCK TABLES `power_display` WRITE;
/*!40000 ALTER TABLE `power_display` DISABLE KEYS */;
/*!40000 ALTER TABLE `power_display` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `power_type`
--

DROP TABLE IF EXISTS `power_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `power_type` (
  `NameGlobalStringTag` text,
  `CostGlobalStringTag` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PowerTypeEnum` tinyint NOT NULL DEFAULT '0',
  `MinPower` int NOT NULL DEFAULT '0',
  `MaxBasePower` int NOT NULL DEFAULT '0',
  `CenterPower` int NOT NULL DEFAULT '0',
  `DefaultPower` int NOT NULL DEFAULT '0',
  `DisplayModifier` int NOT NULL DEFAULT '0',
  `RegenInterruptTimeMS` int NOT NULL DEFAULT '0',
  `RegenPeace` float NOT NULL DEFAULT '0',
  `RegenCombat` float NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `power_type`
--

LOCK TABLES `power_type` WRITE;
/*!40000 ALTER TABLE `power_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `power_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `prestige_level_info`
--

DROP TABLE IF EXISTS `prestige_level_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `prestige_level_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `HonorLevel` int NOT NULL DEFAULT '0',
  `BadgeTextureFileDataID` int NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `AwardedAchievementID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `prestige_level_info`
--

LOCK TABLES `prestige_level_info` WRITE;
/*!40000 ALTER TABLE `prestige_level_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `prestige_level_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `prestige_level_info_locale`
--

DROP TABLE IF EXISTS `prestige_level_info_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `prestige_level_info_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `prestige_level_info_locale`
--

LOCK TABLES `prestige_level_info_locale` WRITE;
/*!40000 ALTER TABLE `prestige_level_info_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `prestige_level_info_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pvp_difficulty`
--

DROP TABLE IF EXISTS `pvp_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pvp_difficulty` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RangeIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `MapID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pvp_difficulty`
--

LOCK TABLES `pvp_difficulty` WRITE;
/*!40000 ALTER TABLE `pvp_difficulty` DISABLE KEYS */;
/*!40000 ALTER TABLE `pvp_difficulty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pvp_item`
--

DROP TABLE IF EXISTS `pvp_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pvp_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `ItemLevelDelta` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pvp_item`
--

LOCK TABLES `pvp_item` WRITE;
/*!40000 ALTER TABLE `pvp_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `pvp_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pvp_season`
--

DROP TABLE IF EXISTS `pvp_season`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pvp_season` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MilestoneSeason` int NOT NULL DEFAULT '0',
  `AllianceAchievementID` int NOT NULL DEFAULT '0',
  `HordeAchievementID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pvp_season`
--

LOCK TABLES `pvp_season` WRITE;
/*!40000 ALTER TABLE `pvp_season` DISABLE KEYS */;
/*!40000 ALTER TABLE `pvp_season` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pvp_tier`
--

DROP TABLE IF EXISTS `pvp_tier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pvp_tier` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `MinRating` smallint NOT NULL DEFAULT '0',
  `MaxRating` smallint NOT NULL DEFAULT '0',
  `PrevTier` int NOT NULL DEFAULT '0',
  `NextTier` int NOT NULL DEFAULT '0',
  `BracketID` tinyint unsigned NOT NULL DEFAULT '0',
  `Rank` tinyint NOT NULL DEFAULT '0',
  `RankIconFileDataID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pvp_tier`
--

LOCK TABLES `pvp_tier` WRITE;
/*!40000 ALTER TABLE `pvp_tier` DISABLE KEYS */;
/*!40000 ALTER TABLE `pvp_tier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pvp_tier_locale`
--

DROP TABLE IF EXISTS `pvp_tier_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pvp_tier_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `pvp_tier_locale`
--

LOCK TABLES `pvp_tier_locale` WRITE;
/*!40000 ALTER TABLE `pvp_tier_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `pvp_tier_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_faction_reward`
--

DROP TABLE IF EXISTS `quest_faction_reward`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_faction_reward` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Difficulty1` smallint NOT NULL DEFAULT '0',
  `Difficulty2` smallint NOT NULL DEFAULT '0',
  `Difficulty3` smallint NOT NULL DEFAULT '0',
  `Difficulty4` smallint NOT NULL DEFAULT '0',
  `Difficulty5` smallint NOT NULL DEFAULT '0',
  `Difficulty6` smallint NOT NULL DEFAULT '0',
  `Difficulty7` smallint NOT NULL DEFAULT '0',
  `Difficulty8` smallint NOT NULL DEFAULT '0',
  `Difficulty9` smallint NOT NULL DEFAULT '0',
  `Difficulty10` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_faction_reward`
--

LOCK TABLES `quest_faction_reward` WRITE;
/*!40000 ALTER TABLE `quest_faction_reward` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_faction_reward` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_info`
--

DROP TABLE IF EXISTS `quest_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `InfoName` text,
  `Type` tinyint NOT NULL DEFAULT '0',
  `Modifiers` int NOT NULL DEFAULT '0',
  `Profession` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_info`
--

LOCK TABLES `quest_info` WRITE;
/*!40000 ALTER TABLE `quest_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_info_locale`
--

DROP TABLE IF EXISTS `quest_info_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_info_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `InfoName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `quest_info_locale`
--

LOCK TABLES `quest_info_locale` WRITE;
/*!40000 ALTER TABLE `quest_info_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_info_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_line_x_quest`
--

DROP TABLE IF EXISTS `quest_line_x_quest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_line_x_quest` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `QuestLineID` int unsigned NOT NULL DEFAULT '0',
  `QuestID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_line_x_quest`
--

LOCK TABLES `quest_line_x_quest` WRITE;
/*!40000 ALTER TABLE `quest_line_x_quest` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_line_x_quest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_money_reward`
--

DROP TABLE IF EXISTS `quest_money_reward`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_money_reward` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Difficulty1` int unsigned NOT NULL DEFAULT '0',
  `Difficulty2` int unsigned NOT NULL DEFAULT '0',
  `Difficulty3` int unsigned NOT NULL DEFAULT '0',
  `Difficulty4` int unsigned NOT NULL DEFAULT '0',
  `Difficulty5` int unsigned NOT NULL DEFAULT '0',
  `Difficulty6` int unsigned NOT NULL DEFAULT '0',
  `Difficulty7` int unsigned NOT NULL DEFAULT '0',
  `Difficulty8` int unsigned NOT NULL DEFAULT '0',
  `Difficulty9` int unsigned NOT NULL DEFAULT '0',
  `Difficulty10` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_money_reward`
--

LOCK TABLES `quest_money_reward` WRITE;
/*!40000 ALTER TABLE `quest_money_reward` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_money_reward` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_package_item`
--

DROP TABLE IF EXISTS `quest_package_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_package_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PackageID` smallint unsigned NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `ItemQuantity` int unsigned NOT NULL DEFAULT '0',
  `DisplayType` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_package_item`
--

LOCK TABLES `quest_package_item` WRITE;
/*!40000 ALTER TABLE `quest_package_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_package_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_sort`
--

DROP TABLE IF EXISTS `quest_sort`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_sort` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SortName` text,
  `UiOrderIndex` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_sort`
--

LOCK TABLES `quest_sort` WRITE;
/*!40000 ALTER TABLE `quest_sort` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_sort` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_sort_locale`
--

DROP TABLE IF EXISTS `quest_sort_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_sort_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SortName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `quest_sort_locale`
--

LOCK TABLES `quest_sort_locale` WRITE;
/*!40000 ALTER TABLE `quest_sort_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_sort_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_v2`
--

DROP TABLE IF EXISTS `quest_v2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_v2` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `UniqueBitFlag` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_v2`
--

LOCK TABLES `quest_v2` WRITE;
/*!40000 ALTER TABLE `quest_v2` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_v2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_xp`
--

DROP TABLE IF EXISTS `quest_xp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `quest_xp` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Difficulty1` int NOT NULL DEFAULT '0',
  `Difficulty2` int NOT NULL DEFAULT '0',
  `Difficulty3` int NOT NULL DEFAULT '0',
  `Difficulty4` int NOT NULL DEFAULT '0',
  `Difficulty5` int NOT NULL DEFAULT '0',
  `Difficulty6` int NOT NULL DEFAULT '0',
  `Difficulty7` int NOT NULL DEFAULT '0',
  `Difficulty8` int NOT NULL DEFAULT '0',
  `Difficulty9` int NOT NULL DEFAULT '0',
  `Difficulty10` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quest_xp`
--

LOCK TABLES `quest_xp` WRITE;
/*!40000 ALTER TABLE `quest_xp` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_xp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rand_prop_points`
--

DROP TABLE IF EXISTS `rand_prop_points`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `rand_prop_points` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DamageReplaceStat` int NOT NULL DEFAULT '0',
  `Epic1` int unsigned NOT NULL DEFAULT '0',
  `Epic2` int unsigned NOT NULL DEFAULT '0',
  `Epic3` int unsigned NOT NULL DEFAULT '0',
  `Epic4` int unsigned NOT NULL DEFAULT '0',
  `Epic5` int unsigned NOT NULL DEFAULT '0',
  `Superior1` int unsigned NOT NULL DEFAULT '0',
  `Superior2` int unsigned NOT NULL DEFAULT '0',
  `Superior3` int unsigned NOT NULL DEFAULT '0',
  `Superior4` int unsigned NOT NULL DEFAULT '0',
  `Superior5` int unsigned NOT NULL DEFAULT '0',
  `Good1` int unsigned NOT NULL DEFAULT '0',
  `Good2` int unsigned NOT NULL DEFAULT '0',
  `Good3` int unsigned NOT NULL DEFAULT '0',
  `Good4` int unsigned NOT NULL DEFAULT '0',
  `Good5` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rand_prop_points`
--

LOCK TABLES `rand_prop_points` WRITE;
/*!40000 ALTER TABLE `rand_prop_points` DISABLE KEYS */;
/*!40000 ALTER TABLE `rand_prop_points` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reward_pack`
--

DROP TABLE IF EXISTS `reward_pack`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `reward_pack` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CharTitleID` int NOT NULL DEFAULT '0',
  `Money` int unsigned NOT NULL DEFAULT '0',
  `ArtifactXPDifficulty` tinyint NOT NULL DEFAULT '0',
  `ArtifactXPMultiplier` float NOT NULL DEFAULT '0',
  `ArtifactXPCategoryID` tinyint unsigned NOT NULL DEFAULT '0',
  `TreasurePickerID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reward_pack`
--

LOCK TABLES `reward_pack` WRITE;
/*!40000 ALTER TABLE `reward_pack` DISABLE KEYS */;
/*!40000 ALTER TABLE `reward_pack` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reward_pack_x_currency_type`
--

DROP TABLE IF EXISTS `reward_pack_x_currency_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `reward_pack_x_currency_type` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CurrencyTypeID` int unsigned NOT NULL DEFAULT '0',
  `Quantity` int NOT NULL DEFAULT '0',
  `RewardPackID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reward_pack_x_currency_type`
--

LOCK TABLES `reward_pack_x_currency_type` WRITE;
/*!40000 ALTER TABLE `reward_pack_x_currency_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `reward_pack_x_currency_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reward_pack_x_item`
--

DROP TABLE IF EXISTS `reward_pack_x_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `reward_pack_x_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `ItemQuantity` int NOT NULL DEFAULT '0',
  `RewardPackID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reward_pack_x_item`
--

LOCK TABLES `reward_pack_x_item` WRITE;
/*!40000 ALTER TABLE `reward_pack_x_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `reward_pack_x_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scenario`
--

DROP TABLE IF EXISTS `scenario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scenario` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `AreaTableID` smallint unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `UiTextureKitID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scenario`
--

LOCK TABLES `scenario` WRITE;
/*!40000 ALTER TABLE `scenario` DISABLE KEYS */;
/*!40000 ALTER TABLE `scenario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scenario_locale`
--

DROP TABLE IF EXISTS `scenario_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scenario_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `scenario_locale`
--

LOCK TABLES `scenario_locale` WRITE;
/*!40000 ALTER TABLE `scenario_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `scenario_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scenario_step`
--

DROP TABLE IF EXISTS `scenario_step`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scenario_step` (
  `Description` text,
  `Title` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ScenarioID` smallint unsigned NOT NULL DEFAULT '0',
  `CriteriatreeID` int unsigned NOT NULL DEFAULT '0',
  `RewardQuestID` int NOT NULL DEFAULT '0',
  `RelatedStep` int NOT NULL DEFAULT '0',
  `Supersedes` smallint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `WidgetSetID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scenario_step`
--

LOCK TABLES `scenario_step` WRITE;
/*!40000 ALTER TABLE `scenario_step` DISABLE KEYS */;
/*!40000 ALTER TABLE `scenario_step` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scenario_step_locale`
--

DROP TABLE IF EXISTS `scenario_step_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scenario_step_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Title_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `scenario_step_locale`
--

LOCK TABLES `scenario_step_locale` WRITE;
/*!40000 ALTER TABLE `scenario_step_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `scenario_step_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scene_script`
--

DROP TABLE IF EXISTS `scene_script`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scene_script` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FirstSceneScriptID` smallint unsigned NOT NULL DEFAULT '0',
  `NextSceneScriptID` smallint unsigned NOT NULL DEFAULT '0',
  `Unknown915` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scene_script`
--

LOCK TABLES `scene_script` WRITE;
/*!40000 ALTER TABLE `scene_script` DISABLE KEYS */;
/*!40000 ALTER TABLE `scene_script` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scene_script_global_text`
--

DROP TABLE IF EXISTS `scene_script_global_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scene_script_global_text` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scene_script_global_text`
--

LOCK TABLES `scene_script_global_text` WRITE;
/*!40000 ALTER TABLE `scene_script_global_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `scene_script_global_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scene_script_package`
--

DROP TABLE IF EXISTS `scene_script_package`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scene_script_package` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scene_script_package`
--

LOCK TABLES `scene_script_package` WRITE;
/*!40000 ALTER TABLE `scene_script_package` DISABLE KEYS */;
/*!40000 ALTER TABLE `scene_script_package` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `scene_script_text`
--

DROP TABLE IF EXISTS `scene_script_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scene_script_text` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scene_script_text`
--

LOCK TABLES `scene_script_text` WRITE;
/*!40000 ALTER TABLE `scene_script_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `scene_script_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `server_messages`
--

DROP TABLE IF EXISTS `server_messages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `server_messages` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Text` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `server_messages`
--

LOCK TABLES `server_messages` WRITE;
/*!40000 ALTER TABLE `server_messages` DISABLE KEYS */;
/*!40000 ALTER TABLE `server_messages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `server_messages_locale`
--

DROP TABLE IF EXISTS `server_messages_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `server_messages_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Text_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `server_messages_locale`
--

LOCK TABLES `server_messages_locale` WRITE;
/*!40000 ALTER TABLE `server_messages_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `server_messages_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_line`
--

DROP TABLE IF EXISTS `skill_line`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill_line` (
  `DisplayName` text,
  `AlternateVerb` text,
  `Description` text,
  `HordeDisplayName` text,
  `OverrideSourceInfoDisplayName` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CategoryID` tinyint NOT NULL DEFAULT '0',
  `SpellIconFileID` int NOT NULL DEFAULT '0',
  `CanLink` tinyint NOT NULL DEFAULT '0',
  `ParentSkillLineID` int unsigned NOT NULL DEFAULT '0',
  `ParentTierIndex` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SpellBookSpellID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `skill_line`
--

LOCK TABLES `skill_line` WRITE;
/*!40000 ALTER TABLE `skill_line` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_line` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_line_locale`
--

DROP TABLE IF EXISTS `skill_line_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill_line_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `AlternateVerb_lang` text,
  `Description_lang` text,
  `HordeDisplayName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `skill_line_locale`
--

LOCK TABLES `skill_line_locale` WRITE;
/*!40000 ALTER TABLE `skill_line_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_line_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_line_ability`
--

DROP TABLE IF EXISTS `skill_line_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill_line_ability` (
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SkillLine` smallint unsigned NOT NULL DEFAULT '0',
  `Spell` int NOT NULL DEFAULT '0',
  `MinSkillLineRank` smallint NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `SupercedesSpell` int NOT NULL DEFAULT '0',
  `AcquireMethod` int NOT NULL DEFAULT '0',
  `TrivialSkillLineRankHigh` smallint NOT NULL DEFAULT '0',
  `TrivialSkillLineRankLow` smallint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `NumSkillUps` tinyint NOT NULL DEFAULT '0',
  `UniqueBit` smallint NOT NULL DEFAULT '0',
  `TradeSkillCategoryID` smallint NOT NULL DEFAULT '0',
  `SkillupSkillLineID` smallint NOT NULL DEFAULT '0',
  `CharacterPoints1` int NOT NULL DEFAULT '0',
  `CharacterPoints2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `skill_line_ability`
--

LOCK TABLES `skill_line_ability` WRITE;
/*!40000 ALTER TABLE `skill_line_ability` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_line_ability` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_race_class_info`
--

DROP TABLE IF EXISTS `skill_race_class_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill_race_class_info` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RaceMask` bigint NOT NULL DEFAULT '0',
  `SkillID` smallint unsigned NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `Flags` smallint unsigned NOT NULL DEFAULT '0',
  `Availability` int NOT NULL DEFAULT '0',
  `MinLevel` tinyint NOT NULL DEFAULT '0',
  `SkillTierID` smallint NOT NULL DEFAULT '0',
  `Unknown1150` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `skill_race_class_info`
--

LOCK TABLES `skill_race_class_info` WRITE;
/*!40000 ALTER TABLE `skill_race_class_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_race_class_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sound_kit`
--

DROP TABLE IF EXISTS `sound_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sound_kit` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SoundType` tinyint unsigned NOT NULL DEFAULT '0',
  `VolumeFloat` float NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `MinDistance` float NOT NULL DEFAULT '0',
  `DistanceCutoff` float NOT NULL DEFAULT '0',
  `EAXDef` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundKitAdvancedID` int unsigned NOT NULL DEFAULT '0',
  `VolumeVariationPlus` float NOT NULL DEFAULT '0',
  `VolumeVariationMinus` float NOT NULL DEFAULT '0',
  `PitchVariationPlus` float NOT NULL DEFAULT '0',
  `PitchVariationMinus` float NOT NULL DEFAULT '0',
  `DialogType` tinyint NOT NULL DEFAULT '0',
  `PitchAdjust` float NOT NULL DEFAULT '0',
  `BusOverwriteID` smallint unsigned NOT NULL DEFAULT '0',
  `MaxInstances` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundMixGroupID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sound_kit`
--

LOCK TABLES `sound_kit` WRITE;
/*!40000 ALTER TABLE `sound_kit` DISABLE KEYS */;
/*!40000 ALTER TABLE `sound_kit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_aura_options`
--

DROP TABLE IF EXISTS `spell_aura_options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_aura_options` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `CumulativeAura` int unsigned NOT NULL DEFAULT '0',
  `ProcCategoryRecovery` int NOT NULL DEFAULT '0',
  `ProcChance` tinyint unsigned NOT NULL DEFAULT '0',
  `ProcCharges` int NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` smallint unsigned NOT NULL DEFAULT '0',
  `ProcTypeMask1` int NOT NULL DEFAULT '0',
  `ProcTypeMask2` int NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_aura_options`
--

LOCK TABLES `spell_aura_options` WRITE;
/*!40000 ALTER TABLE `spell_aura_options` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_aura_options` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_aura_restrictions`
--

DROP TABLE IF EXISTS `spell_aura_restrictions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_aura_restrictions` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `CasterAuraState` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetAuraState` tinyint unsigned NOT NULL DEFAULT '0',
  `ExcludeCasterAuraState` tinyint unsigned NOT NULL DEFAULT '0',
  `ExcludeTargetAuraState` tinyint unsigned NOT NULL DEFAULT '0',
  `CasterAuraSpell` int NOT NULL DEFAULT '0',
  `TargetAuraSpell` int NOT NULL DEFAULT '0',
  `ExcludeCasterAuraSpell` int NOT NULL DEFAULT '0',
  `ExcludeTargetAuraSpell` int NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_aura_restrictions`
--

LOCK TABLES `spell_aura_restrictions` WRITE;
/*!40000 ALTER TABLE `spell_aura_restrictions` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_aura_restrictions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_cast_times`
--

DROP TABLE IF EXISTS `spell_cast_times`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_cast_times` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Base` int NOT NULL DEFAULT '0',
  `PerLevel` smallint NOT NULL DEFAULT '0',
  `Minimum` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_cast_times`
--

LOCK TABLES `spell_cast_times` WRITE;
/*!40000 ALTER TABLE `spell_cast_times` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_cast_times` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_casting_requirements`
--

DROP TABLE IF EXISTS `spell_casting_requirements`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_casting_requirements` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `FacingCasterFlags` tinyint unsigned NOT NULL DEFAULT '0',
  `MinFactionID` smallint unsigned NOT NULL DEFAULT '0',
  `MinReputation` int NOT NULL DEFAULT '0',
  `RequiredAreasID` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredAuraVision` tinyint unsigned NOT NULL DEFAULT '0',
  `RequiresSpellFocus` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_casting_requirements`
--

LOCK TABLES `spell_casting_requirements` WRITE;
/*!40000 ALTER TABLE `spell_casting_requirements` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_casting_requirements` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_categories`
--

DROP TABLE IF EXISTS `spell_categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_categories` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `Category` smallint NOT NULL DEFAULT '0',
  `DefenseType` tinyint NOT NULL DEFAULT '0',
  `DispelType` tinyint NOT NULL DEFAULT '0',
  `Mechanic` tinyint NOT NULL DEFAULT '0',
  `PreventionType` tinyint NOT NULL DEFAULT '0',
  `StartRecoveryCategory` smallint NOT NULL DEFAULT '0',
  `ChargeCategory` smallint NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_categories`
--

LOCK TABLES `spell_categories` WRITE;
/*!40000 ALTER TABLE `spell_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_category`
--

DROP TABLE IF EXISTS `spell_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_category` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` int NOT NULL DEFAULT '0',
  `UsesPerWeek` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxCharges` tinyint NOT NULL DEFAULT '0',
  `ChargeRecoveryTime` int NOT NULL DEFAULT '0',
  `TypeMask` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_category`
--

LOCK TABLES `spell_category` WRITE;
/*!40000 ALTER TABLE `spell_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_category_locale`
--

DROP TABLE IF EXISTS `spell_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_category_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `spell_category_locale`
--

LOCK TABLES `spell_category_locale` WRITE;
/*!40000 ALTER TABLE `spell_category_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_category_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_class_options`
--

DROP TABLE IF EXISTS `spell_class_options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_class_options` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `ModalNextSpell` int unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellClassMask1` int NOT NULL DEFAULT '0',
  `SpellClassMask2` int NOT NULL DEFAULT '0',
  `SpellClassMask3` int NOT NULL DEFAULT '0',
  `SpellClassMask4` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_class_options`
--

LOCK TABLES `spell_class_options` WRITE;
/*!40000 ALTER TABLE `spell_class_options` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_class_options` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_cooldowns`
--

DROP TABLE IF EXISTS `spell_cooldowns`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_cooldowns` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `CategoryRecoveryTime` int NOT NULL DEFAULT '0',
  `RecoveryTime` int NOT NULL DEFAULT '0',
  `StartRecoveryTime` int NOT NULL DEFAULT '0',
  `AuraSpellID` int NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_cooldowns`
--

LOCK TABLES `spell_cooldowns` WRITE;
/*!40000 ALTER TABLE `spell_cooldowns` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_cooldowns` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_duration`
--

DROP TABLE IF EXISTS `spell_duration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_duration` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Duration` int NOT NULL DEFAULT '0',
  `DurationPerLevel` int unsigned NOT NULL DEFAULT '0',
  `MaxDuration` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_duration`
--

LOCK TABLES `spell_duration` WRITE;
/*!40000 ALTER TABLE `spell_duration` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_duration` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_effect`
--

DROP TABLE IF EXISTS `spell_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_effect` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int NOT NULL DEFAULT '0',
  `EffectIndex` int NOT NULL DEFAULT '0',
  `Effect` int unsigned NOT NULL DEFAULT '0',
  `EffectAmplitude` float NOT NULL DEFAULT '0',
  `EffectAttributes` int NOT NULL DEFAULT '0',
  `EffectAura` smallint NOT NULL DEFAULT '0',
  `EffectAuraPeriod` int NOT NULL DEFAULT '0',
  `EffectBasePoints` int NOT NULL DEFAULT '0',
  `EffectBonusCoefficient` float NOT NULL DEFAULT '0',
  `EffectChainAmplitude` float NOT NULL DEFAULT '0',
  `EffectChainTargets` int NOT NULL DEFAULT '0',
  `EffectDieSides` int NOT NULL DEFAULT '0',
  `EffectItemType` int NOT NULL DEFAULT '0',
  `EffectMechanic` int NOT NULL DEFAULT '0',
  `EffectPointsPerResource` float NOT NULL DEFAULT '0',
  `EffectPosFacing` float NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel` float NOT NULL DEFAULT '0',
  `EffectTriggerSpell` int NOT NULL DEFAULT '0',
  `BonusCoefficientFromAP` float NOT NULL DEFAULT '0',
  `PvpMultiplier` float NOT NULL DEFAULT '0',
  `Coefficient` float NOT NULL DEFAULT '0',
  `Variance` float NOT NULL DEFAULT '0',
  `ResourceCoefficient` float NOT NULL DEFAULT '0',
  `GroupSizeBasePointsCoefficient` float NOT NULL DEFAULT '0',
  `EffectMiscValue1` int NOT NULL DEFAULT '0',
  `EffectMiscValue2` int NOT NULL DEFAULT '0',
  `EffectRadiusIndex1` int unsigned NOT NULL DEFAULT '0',
  `EffectRadiusIndex2` int unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMask1` int NOT NULL DEFAULT '0',
  `EffectSpellClassMask2` int NOT NULL DEFAULT '0',
  `EffectSpellClassMask3` int NOT NULL DEFAULT '0',
  `EffectSpellClassMask4` int NOT NULL DEFAULT '0',
  `ImplicitTarget1` smallint NOT NULL DEFAULT '0',
  `ImplicitTarget2` smallint NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_effect`
--

LOCK TABLES `spell_effect` WRITE;
/*!40000 ALTER TABLE `spell_effect` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_effect` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_equipped_items`
--

DROP TABLE IF EXISTS `spell_equipped_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_equipped_items` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `EquippedItemClass` tinyint NOT NULL DEFAULT '0',
  `EquippedItemInvTypes` int NOT NULL DEFAULT '0',
  `EquippedItemSubclass` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_equipped_items`
--

LOCK TABLES `spell_equipped_items` WRITE;
/*!40000 ALTER TABLE `spell_equipped_items` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_equipped_items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_focus_object`
--

DROP TABLE IF EXISTS `spell_focus_object`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_focus_object` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_focus_object`
--

LOCK TABLES `spell_focus_object` WRITE;
/*!40000 ALTER TABLE `spell_focus_object` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_focus_object` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_focus_object_locale`
--

DROP TABLE IF EXISTS `spell_focus_object_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_focus_object_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `spell_focus_object_locale`
--

LOCK TABLES `spell_focus_object_locale` WRITE;
/*!40000 ALTER TABLE `spell_focus_object_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_focus_object_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_interrupts`
--

DROP TABLE IF EXISTS `spell_interrupts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_interrupts` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `InterruptFlags` smallint NOT NULL DEFAULT '0',
  `AuraInterruptFlags1` int NOT NULL DEFAULT '0',
  `AuraInterruptFlags2` int NOT NULL DEFAULT '0',
  `ChannelInterruptFlags1` int NOT NULL DEFAULT '0',
  `ChannelInterruptFlags2` int NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_interrupts`
--

LOCK TABLES `spell_interrupts` WRITE;
/*!40000 ALTER TABLE `spell_interrupts` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_interrupts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_item_enchantment`
--

DROP TABLE IF EXISTS `spell_item_enchantment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_item_enchantment` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `HordeName` text,
  `Charges` int NOT NULL DEFAULT '0',
  `Effect1` int NOT NULL DEFAULT '0',
  `Effect2` int NOT NULL DEFAULT '0',
  `Effect3` int NOT NULL DEFAULT '0',
  `EffectPointsMin1` int NOT NULL DEFAULT '0',
  `EffectPointsMin2` int NOT NULL DEFAULT '0',
  `EffectPointsMin3` int NOT NULL DEFAULT '0',
  `EffectPointsMax1` int NOT NULL DEFAULT '0',
  `EffectPointsMax2` int NOT NULL DEFAULT '0',
  `EffectPointsMax3` int NOT NULL DEFAULT '0',
  `EffectArg1` int NOT NULL DEFAULT '0',
  `EffectArg2` int NOT NULL DEFAULT '0',
  `EffectArg3` int NOT NULL DEFAULT '0',
  `ItemVisual` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `EffectScalingPoints1` float NOT NULL DEFAULT '0',
  `EffectScalingPoints2` float NOT NULL DEFAULT '0',
  `EffectScalingPoints3` float NOT NULL DEFAULT '0',
  `ScalingClass` int NOT NULL DEFAULT '0',
  `ScalingClassRestricted` int NOT NULL DEFAULT '0',
  `GemItemID` int NOT NULL DEFAULT '0',
  `ConditionID` int NOT NULL DEFAULT '0',
  `RequiredSkillID` int NOT NULL DEFAULT '0',
  `RequiredSkillRank` int NOT NULL DEFAULT '0',
  `MinLevel` int NOT NULL DEFAULT '0',
  `MaxLevel` int NOT NULL DEFAULT '0',
  `Unknown1153_0` int NOT NULL DEFAULT '0',
  `ItemLevel` int NOT NULL DEFAULT '0',
  `Unknown1153_1` int NOT NULL DEFAULT '0',
  `Unknown1153_2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `HordeName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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

LOCK TABLES `spell_item_enchantment_locale` WRITE;
/*!40000 ALTER TABLE `spell_item_enchantment_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_item_enchantment_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_item_enchantment_condition`
--

DROP TABLE IF EXISTS `spell_item_enchantment_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_item_enchantment_condition` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `LtOperandType1` tinyint unsigned NOT NULL DEFAULT '0',
  `LtOperandType2` tinyint unsigned NOT NULL DEFAULT '0',
  `LtOperandType3` tinyint unsigned NOT NULL DEFAULT '0',
  `LtOperandType4` tinyint unsigned NOT NULL DEFAULT '0',
  `LtOperandType5` tinyint unsigned NOT NULL DEFAULT '0',
  `LtOperand1` int unsigned NOT NULL DEFAULT '0',
  `LtOperand2` int unsigned NOT NULL DEFAULT '0',
  `LtOperand3` int unsigned NOT NULL DEFAULT '0',
  `LtOperand4` int unsigned NOT NULL DEFAULT '0',
  `LtOperand5` int unsigned NOT NULL DEFAULT '0',
  `Operator1` tinyint unsigned NOT NULL DEFAULT '0',
  `Operator2` tinyint unsigned NOT NULL DEFAULT '0',
  `Operator3` tinyint unsigned NOT NULL DEFAULT '0',
  `Operator4` tinyint unsigned NOT NULL DEFAULT '0',
  `Operator5` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperandType1` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperandType2` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperandType3` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperandType4` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperandType5` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperand1` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperand2` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperand3` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperand4` tinyint unsigned NOT NULL DEFAULT '0',
  `RtOperand5` tinyint unsigned NOT NULL DEFAULT '0',
  `Logic1` tinyint unsigned NOT NULL DEFAULT '0',
  `Logic2` tinyint unsigned NOT NULL DEFAULT '0',
  `Logic3` tinyint unsigned NOT NULL DEFAULT '0',
  `Logic4` tinyint unsigned NOT NULL DEFAULT '0',
  `Logic5` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_item_enchantment_condition`
--

LOCK TABLES `spell_item_enchantment_condition` WRITE;
/*!40000 ALTER TABLE `spell_item_enchantment_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_item_enchantment_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_keybound_override`
--

DROP TABLE IF EXISTS `spell_keybound_override`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_keybound_override` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Function` text,
  `Type` tinyint NOT NULL DEFAULT '0',
  `Data` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_keybound_override`
--

LOCK TABLES `spell_keybound_override` WRITE;
/*!40000 ALTER TABLE `spell_keybound_override` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_keybound_override` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_label`
--

DROP TABLE IF EXISTS `spell_label`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_label` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `LabelID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_label`
--

LOCK TABLES `spell_label` WRITE;
/*!40000 ALTER TABLE `spell_label` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_label` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_learn_spell`
--

DROP TABLE IF EXISTS `spell_learn_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_learn_spell` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `LearnSpellID` int NOT NULL DEFAULT '0',
  `OverridesSpellID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_learn_spell`
--

LOCK TABLES `spell_learn_spell` WRITE;
/*!40000 ALTER TABLE `spell_learn_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_learn_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_levels`
--

DROP TABLE IF EXISTS `spell_levels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_levels` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `BaseLevel` smallint NOT NULL DEFAULT '0',
  `MaxLevel` smallint NOT NULL DEFAULT '0',
  `SpellLevel` smallint NOT NULL DEFAULT '0',
  `MaxPassiveAuraLevel` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_levels`
--

LOCK TABLES `spell_levels` WRITE;
/*!40000 ALTER TABLE `spell_levels` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_levels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_misc`
--

DROP TABLE IF EXISTS `spell_misc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_misc` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Attributes1` int NOT NULL DEFAULT '0',
  `Attributes2` int NOT NULL DEFAULT '0',
  `Attributes3` int NOT NULL DEFAULT '0',
  `Attributes4` int NOT NULL DEFAULT '0',
  `Attributes5` int NOT NULL DEFAULT '0',
  `Attributes6` int NOT NULL DEFAULT '0',
  `Attributes7` int NOT NULL DEFAULT '0',
  `Attributes8` int NOT NULL DEFAULT '0',
  `Attributes9` int NOT NULL DEFAULT '0',
  `Attributes10` int NOT NULL DEFAULT '0',
  `Attributes11` int NOT NULL DEFAULT '0',
  `Attributes12` int NOT NULL DEFAULT '0',
  `Attributes13` int NOT NULL DEFAULT '0',
  `Attributes14` int NOT NULL DEFAULT '0',
  `Attributes15` int NOT NULL DEFAULT '0',
  `Attributes16` int NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `CastingTimeIndex` smallint unsigned NOT NULL DEFAULT '0',
  `DurationIndex` smallint unsigned NOT NULL DEFAULT '0',
  `RangeIndex` smallint unsigned NOT NULL DEFAULT '0',
  `SchoolMask` tinyint unsigned NOT NULL DEFAULT '0',
  `Speed` float NOT NULL DEFAULT '0',
  `LaunchDelay` float NOT NULL DEFAULT '0',
  `MinDuration` float NOT NULL DEFAULT '0',
  `SpellIconFileDataID` int NOT NULL DEFAULT '0',
  `ActiveIconFileDataID` int NOT NULL DEFAULT '0',
  `ContentTuningID` int NOT NULL DEFAULT '0',
  `ShowFutureSpellPlayerConditionID` int NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_misc`
--

LOCK TABLES `spell_misc` WRITE;
/*!40000 ALTER TABLE `spell_misc` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_misc` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_name`
--

DROP TABLE IF EXISTS `spell_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_name` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_name`
--

LOCK TABLES `spell_name` WRITE;
/*!40000 ALTER TABLE `spell_name` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_name_locale`
--

DROP TABLE IF EXISTS `spell_name_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_name_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `spell_name_locale`
--

LOCK TABLES `spell_name_locale` WRITE;
/*!40000 ALTER TABLE `spell_name_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_name_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_power`
--

DROP TABLE IF EXISTS `spell_power`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_power` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `ManaCost` int NOT NULL DEFAULT '0',
  `ManaCostPerLevel` int NOT NULL DEFAULT '0',
  `ManaPerSecond` int NOT NULL DEFAULT '0',
  `PowerDisplayID` int unsigned NOT NULL DEFAULT '0',
  `AltPowerBarID` int NOT NULL DEFAULT '0',
  `PowerCostPct` float NOT NULL DEFAULT '0',
  `PowerCostMaxPct` float NOT NULL DEFAULT '0',
  `PowerPctPerSecond` float NOT NULL DEFAULT '0',
  `PowerType` tinyint NOT NULL DEFAULT '0',
  `RequiredAuraSpellID` int NOT NULL DEFAULT '0',
  `OptionalCost` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_power`
--

LOCK TABLES `spell_power` WRITE;
/*!40000 ALTER TABLE `spell_power` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_power` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_power_difficulty`
--

DROP TABLE IF EXISTS `spell_power_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_power_difficulty` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_power_difficulty`
--

LOCK TABLES `spell_power_difficulty` WRITE;
/*!40000 ALTER TABLE `spell_power_difficulty` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_power_difficulty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_procs_per_minute`
--

DROP TABLE IF EXISTS `spell_procs_per_minute`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_procs_per_minute` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `BaseProcRate` float NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_procs_per_minute`
--

LOCK TABLES `spell_procs_per_minute` WRITE;
/*!40000 ALTER TABLE `spell_procs_per_minute` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_procs_per_minute` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_procs_per_minute_mod`
--

DROP TABLE IF EXISTS `spell_procs_per_minute_mod`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_procs_per_minute_mod` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `Param` smallint NOT NULL DEFAULT '0',
  `Coeff` float NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_procs_per_minute_mod`
--

LOCK TABLES `spell_procs_per_minute_mod` WRITE;
/*!40000 ALTER TABLE `spell_procs_per_minute_mod` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_procs_per_minute_mod` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_radius`
--

DROP TABLE IF EXISTS `spell_radius`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_radius` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `RadiusPerLevel` float NOT NULL DEFAULT '0',
  `RadiusMin` float NOT NULL DEFAULT '0',
  `RadiusMax` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_radius`
--

LOCK TABLES `spell_radius` WRITE;
/*!40000 ALTER TABLE `spell_radius` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_radius` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_range`
--

DROP TABLE IF EXISTS `spell_range`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_range` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `DisplayNameShort` text,
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `RangeMin1` float NOT NULL DEFAULT '0',
  `RangeMin2` float NOT NULL DEFAULT '0',
  `RangeMax1` float NOT NULL DEFAULT '0',
  `RangeMax2` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_range`
--

LOCK TABLES `spell_range` WRITE;
/*!40000 ALTER TABLE `spell_range` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_range` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_range_locale`
--

DROP TABLE IF EXISTS `spell_range_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_range_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `DisplayNameShort_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `spell_range_locale`
--

LOCK TABLES `spell_range_locale` WRITE;
/*!40000 ALTER TABLE `spell_range_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_range_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_reagents`
--

DROP TABLE IF EXISTS `spell_reagents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_reagents` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `Reagent1` int NOT NULL DEFAULT '0',
  `Reagent2` int NOT NULL DEFAULT '0',
  `Reagent3` int NOT NULL DEFAULT '0',
  `Reagent4` int NOT NULL DEFAULT '0',
  `Reagent5` int NOT NULL DEFAULT '0',
  `Reagent6` int NOT NULL DEFAULT '0',
  `Reagent7` int NOT NULL DEFAULT '0',
  `Reagent8` int NOT NULL DEFAULT '0',
  `ReagentCount1` smallint NOT NULL DEFAULT '0',
  `ReagentCount2` smallint NOT NULL DEFAULT '0',
  `ReagentCount3` smallint NOT NULL DEFAULT '0',
  `ReagentCount4` smallint NOT NULL DEFAULT '0',
  `ReagentCount5` smallint NOT NULL DEFAULT '0',
  `ReagentCount6` smallint NOT NULL DEFAULT '0',
  `ReagentCount7` smallint NOT NULL DEFAULT '0',
  `ReagentCount8` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_reagents`
--

LOCK TABLES `spell_reagents` WRITE;
/*!40000 ALTER TABLE `spell_reagents` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_reagents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_reagents_currency`
--

DROP TABLE IF EXISTS `spell_reagents_currency`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_reagents_currency` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `CurrencyTypesID` smallint unsigned NOT NULL DEFAULT '0',
  `CurrencyCount` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_reagents_currency`
--

LOCK TABLES `spell_reagents_currency` WRITE;
/*!40000 ALTER TABLE `spell_reagents_currency` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_reagents_currency` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_scaling`
--

DROP TABLE IF EXISTS `spell_scaling`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_scaling` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `Class` int NOT NULL DEFAULT '0',
  `MinScalingLevel` int unsigned NOT NULL DEFAULT '0',
  `MaxScalingLevel` int unsigned NOT NULL DEFAULT '0',
  `ScalesFromItemLevel` smallint NOT NULL DEFAULT '0',
  `CastTimeMin` int NOT NULL DEFAULT '0',
  `CastTimeMax` int NOT NULL DEFAULT '0',
  `CastTimeMaxLevel` int NOT NULL DEFAULT '0',
  `NerfFactor` float NOT NULL DEFAULT '0',
  `NerfMaxLevel` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_scaling`
--

LOCK TABLES `spell_scaling` WRITE;
/*!40000 ALTER TABLE `spell_scaling` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_scaling` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_shapeshift`
--

DROP TABLE IF EXISTS `spell_shapeshift`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_shapeshift` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `StanceBarOrder` tinyint NOT NULL DEFAULT '0',
  `ShapeshiftExclude1` int NOT NULL DEFAULT '0',
  `ShapeshiftExclude2` int NOT NULL DEFAULT '0',
  `ShapeshiftMask1` int NOT NULL DEFAULT '0',
  `ShapeshiftMask2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_shapeshift`
--

LOCK TABLES `spell_shapeshift` WRITE;
/*!40000 ALTER TABLE `spell_shapeshift` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_shapeshift` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_shapeshift_form`
--

DROP TABLE IF EXISTS `spell_shapeshift_form`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_shapeshift_form` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Unknown1150` int unsigned NOT NULL DEFAULT '0',
  `CreatureType` tinyint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `AttackIconFileID` int NOT NULL DEFAULT '0',
  `BonusActionBar` tinyint NOT NULL DEFAULT '0',
  `CombatRoundTime` smallint NOT NULL DEFAULT '0',
  `DamageVariance` float NOT NULL DEFAULT '0',
  `MountTypeID` smallint unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID1` int unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID2` int unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID3` int unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID4` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID1` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID2` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID3` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID4` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID5` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID6` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID7` int unsigned NOT NULL DEFAULT '0',
  `PresetSpellID8` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_shapeshift_form`
--

LOCK TABLES `spell_shapeshift_form` WRITE;
/*!40000 ALTER TABLE `spell_shapeshift_form` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_shapeshift_form` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_shapeshift_form_locale`
--

DROP TABLE IF EXISTS `spell_shapeshift_form_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_shapeshift_form_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `spell_shapeshift_form_locale`
--

LOCK TABLES `spell_shapeshift_form_locale` WRITE;
/*!40000 ALTER TABLE `spell_shapeshift_form_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_shapeshift_form_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_target_restrictions`
--

DROP TABLE IF EXISTS `spell_target_restrictions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_target_restrictions` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `ConeDegrees` float NOT NULL DEFAULT '0',
  `MaxTargets` tinyint unsigned NOT NULL DEFAULT '0',
  `MaxTargetLevel` int unsigned NOT NULL DEFAULT '0',
  `TargetCreatureType` smallint NOT NULL DEFAULT '0',
  `Targets` int NOT NULL DEFAULT '0',
  `Width` float NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_target_restrictions`
--

LOCK TABLES `spell_target_restrictions` WRITE;
/*!40000 ALTER TABLE `spell_target_restrictions` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_target_restrictions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_totems`
--

DROP TABLE IF EXISTS `spell_totems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_totems` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID1` smallint unsigned NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID2` smallint unsigned NOT NULL DEFAULT '0',
  `Totem1` int NOT NULL DEFAULT '0',
  `Totem2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_totems`
--

LOCK TABLES `spell_totems` WRITE;
/*!40000 ALTER TABLE `spell_totems` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_totems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_visual`
--

DROP TABLE IF EXISTS `spell_visual`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MissileCastOffsetX` float NOT NULL DEFAULT '0',
  `MissileCastOffsetY` float NOT NULL DEFAULT '0',
  `MissileCastOffsetZ` float NOT NULL DEFAULT '0',
  `MissileImpactOffsetX` float NOT NULL DEFAULT '0',
  `MissileImpactOffsetY` float NOT NULL DEFAULT '0',
  `MissileImpactOffsetZ` float NOT NULL DEFAULT '0',
  `AnimEventSoundID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `MissileAttachment` tinyint NOT NULL DEFAULT '0',
  `MissileDestinationAttachment` tinyint NOT NULL DEFAULT '0',
  `MissileCastPositionerID` int unsigned NOT NULL DEFAULT '0',
  `MissileImpactPositionerID` int unsigned NOT NULL DEFAULT '0',
  `MissileTargetingKit` int NOT NULL DEFAULT '0',
  `HostileSpellVisualID` int unsigned NOT NULL DEFAULT '0',
  `CasterSpellVisualID` int unsigned NOT NULL DEFAULT '0',
  `SpellVisualMissileSetID` smallint unsigned NOT NULL DEFAULT '0',
  `DamageNumberDelay` smallint unsigned NOT NULL DEFAULT '0',
  `LowViolenceSpellVisualID` int unsigned NOT NULL DEFAULT '0',
  `RaidSpellVisualMissileSetID` int unsigned NOT NULL DEFAULT '0',
  `ReducedUnexpectedCameraMovementSpellVisualID` int NOT NULL DEFAULT '0',
  `AreaModel` smallint unsigned NOT NULL DEFAULT '0',
  `HasMissile` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_visual`
--

LOCK TABLES `spell_visual` WRITE;
/*!40000 ALTER TABLE `spell_visual` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_visual` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_visual_effect_name`
--

DROP TABLE IF EXISTS `spell_visual_effect_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual_effect_name` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ModelFileDataID` int NOT NULL DEFAULT '0',
  `BaseMissileSpeed` float NOT NULL DEFAULT '0',
  `Scale` float NOT NULL DEFAULT '0',
  `MinAllowedScale` float NOT NULL DEFAULT '0',
  `MaxAllowedScale` float NOT NULL DEFAULT '0',
  `Alpha` float NOT NULL DEFAULT '0',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int NOT NULL DEFAULT '0',
  `EffectRadius` float NOT NULL DEFAULT '0',
  `Type` int unsigned NOT NULL DEFAULT '0',
  `GenericID` int NOT NULL DEFAULT '0',
  `RibbonQualityID` int unsigned NOT NULL DEFAULT '0',
  `DissolveEffectID` int NOT NULL DEFAULT '0',
  `ModelPosition` int NOT NULL DEFAULT '0',
  `Unknown1154` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_visual_effect_name`
--

LOCK TABLES `spell_visual_effect_name` WRITE;
/*!40000 ALTER TABLE `spell_visual_effect_name` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_visual_effect_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_visual_kit`
--

DROP TABLE IF EXISTS `spell_visual_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual_kit` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FallbackSpellVisualKitID` int unsigned NOT NULL DEFAULT '0',
  `DelayMin` smallint unsigned NOT NULL DEFAULT '0',
  `DelayMax` smallint unsigned NOT NULL DEFAULT '0',
  `FallbackPriority` float NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_visual_kit`
--

LOCK TABLES `spell_visual_kit` WRITE;
/*!40000 ALTER TABLE `spell_visual_kit` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_visual_kit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_visual_missile`
--

DROP TABLE IF EXISTS `spell_visual_missile`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual_missile` (
  `CastOffsetX` float NOT NULL DEFAULT '0',
  `CastOffsetY` float NOT NULL DEFAULT '0',
  `CastOffsetZ` float NOT NULL DEFAULT '0',
  `ImpactOffsetX` float NOT NULL DEFAULT '0',
  `ImpactOffsetY` float NOT NULL DEFAULT '0',
  `ImpactOffsetZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellVisualEffectNameID` smallint unsigned NOT NULL DEFAULT '0',
  `SoundEntriesID` int unsigned NOT NULL DEFAULT '0',
  `Attachment` tinyint NOT NULL DEFAULT '0',
  `DestinationAttachment` tinyint NOT NULL DEFAULT '0',
  `CastPositionerID` smallint unsigned NOT NULL DEFAULT '0',
  `ImpactPositionerID` smallint unsigned NOT NULL DEFAULT '0',
  `FollowGroundHeight` int NOT NULL DEFAULT '0',
  `FollowGroundDropSpeed` int unsigned NOT NULL DEFAULT '0',
  `FollowGroundApproach` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `SpellMissileMotionID` smallint unsigned NOT NULL DEFAULT '0',
  `AnimKitID` int unsigned NOT NULL DEFAULT '0',
  `Unknown1154` smallint unsigned NOT NULL DEFAULT '0',
  `SpellVisualMissileSetID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_visual_missile`
--

LOCK TABLES `spell_visual_missile` WRITE;
/*!40000 ALTER TABLE `spell_visual_missile` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_visual_missile` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_x_spell_visual`
--

DROP TABLE IF EXISTS `spell_x_spell_visual`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_x_spell_visual` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint unsigned NOT NULL DEFAULT '0',
  `SpellVisualID` int unsigned NOT NULL DEFAULT '0',
  `Probability` float NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `Priority` int NOT NULL DEFAULT '0',
  `SpellIconFileID` int NOT NULL DEFAULT '0',
  `ActiveIconFileID` int NOT NULL DEFAULT '0',
  `ViewerUnitConditionID` smallint unsigned NOT NULL DEFAULT '0',
  `ViewerPlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `CasterUnitConditionID` smallint unsigned NOT NULL DEFAULT '0',
  `CasterPlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_x_spell_visual`
--

LOCK TABLES `spell_x_spell_visual` WRITE;
/*!40000 ALTER TABLE `spell_x_spell_visual` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_x_spell_visual` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `summon_properties`
--

DROP TABLE IF EXISTS `summon_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `summon_properties` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Control` int NOT NULL DEFAULT '0',
  `Faction` int NOT NULL DEFAULT '0',
  `Title` int NOT NULL DEFAULT '0',
  `Slot` int NOT NULL DEFAULT '0',
  `Flags1` int NOT NULL DEFAULT '0',
  `Flags2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `summon_properties`
--

LOCK TABLES `summon_properties` WRITE;
/*!40000 ALTER TABLE `summon_properties` DISABLE KEYS */;
/*!40000 ALTER TABLE `summon_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tact_key`
--

DROP TABLE IF EXISTS `tact_key`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tact_key` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Key1` tinyint unsigned NOT NULL DEFAULT '0',
  `Key2` tinyint unsigned NOT NULL DEFAULT '0',
  `Key3` tinyint unsigned NOT NULL DEFAULT '0',
  `Key4` tinyint unsigned NOT NULL DEFAULT '0',
  `Key5` tinyint unsigned NOT NULL DEFAULT '0',
  `Key6` tinyint unsigned NOT NULL DEFAULT '0',
  `Key7` tinyint unsigned NOT NULL DEFAULT '0',
  `Key8` tinyint unsigned NOT NULL DEFAULT '0',
  `Key9` tinyint unsigned NOT NULL DEFAULT '0',
  `Key10` tinyint unsigned NOT NULL DEFAULT '0',
  `Key11` tinyint unsigned NOT NULL DEFAULT '0',
  `Key12` tinyint unsigned NOT NULL DEFAULT '0',
  `Key13` tinyint unsigned NOT NULL DEFAULT '0',
  `Key14` tinyint unsigned NOT NULL DEFAULT '0',
  `Key15` tinyint unsigned NOT NULL DEFAULT '0',
  `Key16` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tact_key`
--

LOCK TABLES `tact_key` WRITE;
/*!40000 ALTER TABLE `tact_key` DISABLE KEYS */;
/*!40000 ALTER TABLE `tact_key` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent`
--

DROP TABLE IF EXISTS `talent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `TierID` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `ColumnIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `TabID` smallint unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `OverridesSpellID` int NOT NULL DEFAULT '0',
  `RequiredSpellID` int NOT NULL DEFAULT '0',
  `CategoryMask1` int NOT NULL DEFAULT '0',
  `CategoryMask2` int NOT NULL DEFAULT '0',
  `SpellRank1` int NOT NULL DEFAULT '0',
  `SpellRank2` int NOT NULL DEFAULT '0',
  `SpellRank3` int NOT NULL DEFAULT '0',
  `SpellRank4` int NOT NULL DEFAULT '0',
  `SpellRank5` int NOT NULL DEFAULT '0',
  `SpellRank6` int NOT NULL DEFAULT '0',
  `SpellRank7` int NOT NULL DEFAULT '0',
  `SpellRank8` int NOT NULL DEFAULT '0',
  `SpellRank9` int NOT NULL DEFAULT '0',
  `PrereqTalent1` int NOT NULL DEFAULT '0',
  `PrereqTalent2` int NOT NULL DEFAULT '0',
  `PrereqTalent3` int NOT NULL DEFAULT '0',
  `PrereqRank1` int NOT NULL DEFAULT '0',
  `PrereqRank2` int NOT NULL DEFAULT '0',
  `PrereqRank3` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `talent`
--

LOCK TABLES `talent` WRITE;
/*!40000 ALTER TABLE `talent` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_locale`
--

DROP TABLE IF EXISTS `talent_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `talent_locale`
--

LOCK TABLES `talent_locale` WRITE;
/*!40000 ALTER TABLE `talent_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_tab`
--

DROP TABLE IF EXISTS `talent_tab`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tab` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `BackgroundFile` text,
  `Description` text,
  `OrderIndex` int NOT NULL DEFAULT '0',
  `RaceMask` int NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `CategoryEnumID` int NOT NULL DEFAULT '0',
  `SpellIconID` int NOT NULL DEFAULT '0',
  `RoleMask` int NOT NULL DEFAULT '0',
  `MasterySpellID1` int NOT NULL DEFAULT '0',
  `MasterySpellID2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `talent_tab`
--

LOCK TABLES `talent_tab` WRITE;
/*!40000 ALTER TABLE `talent_tab` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tab` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_tab_locale`
--

DROP TABLE IF EXISTS `talent_tab_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tab_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `talent_tab_locale`
--

LOCK TABLES `talent_tab_locale` WRITE;
/*!40000 ALTER TABLE `talent_tab_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tab_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_tree_primary_spells`
--

DROP TABLE IF EXISTS `talent_tree_primary_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tree_primary_spells` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `TalentTabID` int NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `talent_tree_primary_spells`
--

LOCK TABLES `talent_tree_primary_spells` WRITE;
/*!40000 ALTER TABLE `talent_tree_primary_spells` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tree_primary_spells` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxi_nodes`
--

DROP TABLE IF EXISTS `taxi_nodes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `taxi_nodes` (
  `Name` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `MapOffsetX` float NOT NULL DEFAULT '0',
  `MapOffsetY` float NOT NULL DEFAULT '0',
  `FlightMapOffsetX` float NOT NULL DEFAULT '0',
  `FlightMapOffsetY` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ContinentID` int unsigned NOT NULL DEFAULT '0',
  `ConditionID` int unsigned NOT NULL DEFAULT '0',
  `CharacterBitNumber` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `UiTextureKitID` int NOT NULL DEFAULT '0',
  `Facing` float NOT NULL DEFAULT '0',
  `SpecialIconConditionID` int unsigned NOT NULL DEFAULT '0',
  `VisibilityConditionID` int unsigned NOT NULL DEFAULT '0',
  `MountCreatureID1` int NOT NULL DEFAULT '0',
  `MountCreatureID2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taxi_nodes`
--

LOCK TABLES `taxi_nodes` WRITE;
/*!40000 ALTER TABLE `taxi_nodes` DISABLE KEYS */;
/*!40000 ALTER TABLE `taxi_nodes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxi_nodes_locale`
--

DROP TABLE IF EXISTS `taxi_nodes_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `taxi_nodes_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `taxi_nodes_locale`
--

LOCK TABLES `taxi_nodes_locale` WRITE;
/*!40000 ALTER TABLE `taxi_nodes_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `taxi_nodes_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxi_path`
--

DROP TABLE IF EXISTS `taxi_path`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `taxi_path` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `FromTaxiNode` smallint unsigned NOT NULL DEFAULT '0',
  `ToTaxiNode` smallint unsigned NOT NULL DEFAULT '0',
  `Cost` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taxi_path`
--

LOCK TABLES `taxi_path` WRITE;
/*!40000 ALTER TABLE `taxi_path` DISABLE KEYS */;
/*!40000 ALTER TABLE `taxi_path` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxi_path_node`
--

DROP TABLE IF EXISTS `taxi_path_node`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `taxi_path_node` (
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PathID` smallint unsigned NOT NULL DEFAULT '0',
  `NodeIndex` int NOT NULL DEFAULT '0',
  `ContinentID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `Delay` int unsigned NOT NULL DEFAULT '0',
  `ArrivalEventID` int unsigned NOT NULL DEFAULT '0',
  `DepartureEventID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taxi_path_node`
--

LOCK TABLES `taxi_path_node` WRITE;
/*!40000 ALTER TABLE `taxi_path_node` DISABLE KEYS */;
/*!40000 ALTER TABLE `taxi_path_node` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `totem_category`
--

DROP TABLE IF EXISTS `totem_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `totem_category` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `TotemCategoryType` tinyint unsigned NOT NULL DEFAULT '0',
  `TotemCategoryMask` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `totem_category`
--

LOCK TABLES `totem_category` WRITE;
/*!40000 ALTER TABLE `totem_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `totem_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `totem_category_locale`
--

DROP TABLE IF EXISTS `totem_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `totem_category_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `totem_category_locale`
--

LOCK TABLES `totem_category_locale` WRITE;
/*!40000 ALTER TABLE `totem_category_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `totem_category_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toy`
--

DROP TABLE IF EXISTS `toy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `toy` (
  `SourceText` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `SourceTypeEnum` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toy`
--

LOCK TABLES `toy` WRITE;
/*!40000 ALTER TABLE `toy` DISABLE KEYS */;
/*!40000 ALTER TABLE `toy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toy_locale`
--

DROP TABLE IF EXISTS `toy_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `toy_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceText_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `toy_locale`
--

LOCK TABLES `toy_locale` WRITE;
/*!40000 ALTER TABLE `toy_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `toy_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_holiday`
--

DROP TABLE IF EXISTS `transmog_holiday`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_holiday` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RequiredTransmogHoliday` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transmog_holiday`
--

LOCK TABLES `transmog_holiday` WRITE;
/*!40000 ALTER TABLE `transmog_holiday` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_holiday` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_set`
--

DROP TABLE IF EXISTS `transmog_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_set` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClassMask` int NOT NULL DEFAULT '0',
  `TrackingQuestID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `TransmogSetGroupID` int unsigned NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` int NOT NULL DEFAULT '0',
  `ParentTransmogSetID` smallint unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint unsigned NOT NULL DEFAULT '0',
  `UiOrder` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transmog_set`
--

LOCK TABLES `transmog_set` WRITE;
/*!40000 ALTER TABLE `transmog_set` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_set` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_set_locale`
--

DROP TABLE IF EXISTS `transmog_set_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_set_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `transmog_set_locale`
--

LOCK TABLES `transmog_set_locale` WRITE;
/*!40000 ALTER TABLE `transmog_set_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_set_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_set_group`
--

DROP TABLE IF EXISTS `transmog_set_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_set_group` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transmog_set_group`
--

LOCK TABLES `transmog_set_group` WRITE;
/*!40000 ALTER TABLE `transmog_set_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_set_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_set_group_locale`
--

DROP TABLE IF EXISTS `transmog_set_group_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_set_group_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `transmog_set_group_locale`
--

LOCK TABLES `transmog_set_group_locale` WRITE;
/*!40000 ALTER TABLE `transmog_set_group_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_set_group_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transmog_set_item`
--

DROP TABLE IF EXISTS `transmog_set_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transmog_set_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `TransmogSetID` int unsigned NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transmog_set_item`
--

LOCK TABLES `transmog_set_item` WRITE;
/*!40000 ALTER TABLE `transmog_set_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `transmog_set_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transport_animation`
--

DROP TABLE IF EXISTS `transport_animation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transport_animation` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `SequenceID` tinyint unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int unsigned NOT NULL DEFAULT '0',
  `TransportID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transport_animation`
--

LOCK TABLES `transport_animation` WRITE;
/*!40000 ALTER TABLE `transport_animation` DISABLE KEYS */;
/*!40000 ALTER TABLE `transport_animation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transport_rotation`
--

DROP TABLE IF EXISTS `transport_rotation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transport_rotation` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Rot1` float NOT NULL DEFAULT '0',
  `Rot2` float NOT NULL DEFAULT '0',
  `Rot3` float NOT NULL DEFAULT '0',
  `Rot4` float NOT NULL DEFAULT '0',
  `TimeIndex` int unsigned NOT NULL DEFAULT '0',
  `GameObjectsID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transport_rotation`
--

LOCK TABLES `transport_rotation` WRITE;
/*!40000 ALTER TABLE `transport_rotation` DISABLE KEYS */;
/*!40000 ALTER TABLE `transport_rotation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ui_map`
--

DROP TABLE IF EXISTS `ui_map`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_map` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ParentUiMapID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `System` tinyint unsigned NOT NULL DEFAULT '0',
  `Type` tinyint unsigned NOT NULL DEFAULT '0',
  `BountySetID` int NOT NULL DEFAULT '0',
  `BountyDisplayLocation` int unsigned NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID2` int NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID` int NOT NULL DEFAULT '0',
  `HelpTextPosition` tinyint NOT NULL DEFAULT '0',
  `BkgAtlasID` int NOT NULL DEFAULT '0',
  `AlternateUiMapGroup` int unsigned NOT NULL DEFAULT '0',
  `ContentTuningID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ui_map`
--

LOCK TABLES `ui_map` WRITE;
/*!40000 ALTER TABLE `ui_map` DISABLE KEYS */;
/*!40000 ALTER TABLE `ui_map` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ui_map_locale`
--

DROP TABLE IF EXISTS `ui_map_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_map_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `ui_map_locale`
--

LOCK TABLES `ui_map_locale` WRITE;
/*!40000 ALTER TABLE `ui_map_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `ui_map_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ui_map_assignment`
--

DROP TABLE IF EXISTS `ui_map_assignment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_map_assignment` (
  `UiMinX` float NOT NULL DEFAULT '0',
  `UiMinY` float NOT NULL DEFAULT '0',
  `UiMaxX` float NOT NULL DEFAULT '0',
  `UiMaxY` float NOT NULL DEFAULT '0',
  `Region1X` float NOT NULL DEFAULT '0',
  `Region1Y` float NOT NULL DEFAULT '0',
  `Region1Z` float NOT NULL DEFAULT '0',
  `Region2X` float NOT NULL DEFAULT '0',
  `Region2Y` float NOT NULL DEFAULT '0',
  `Region2Z` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `UiMapID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `MapID` int NOT NULL DEFAULT '0',
  `AreaID` int NOT NULL DEFAULT '0',
  `WmoDoodadPlacementID` int NOT NULL DEFAULT '0',
  `WmoGroupID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ui_map_assignment`
--

LOCK TABLES `ui_map_assignment` WRITE;
/*!40000 ALTER TABLE `ui_map_assignment` DISABLE KEYS */;
/*!40000 ALTER TABLE `ui_map_assignment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ui_map_link`
--

DROP TABLE IF EXISTS `ui_map_link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_map_link` (
  `UiMinX` float NOT NULL DEFAULT '0',
  `UiMinY` float NOT NULL DEFAULT '0',
  `UiMaxX` float NOT NULL DEFAULT '0',
  `UiMaxY` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ParentUiMapID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `ChildUiMapID` int NOT NULL DEFAULT '0',
  `OverrideHighlightFileDataID` int NOT NULL DEFAULT '0',
  `OverrideHighlightAtlasID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ui_map_link`
--

LOCK TABLES `ui_map_link` WRITE;
/*!40000 ALTER TABLE `ui_map_link` DISABLE KEYS */;
/*!40000 ALTER TABLE `ui_map_link` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ui_map_x_map_art`
--

DROP TABLE IF EXISTS `ui_map_x_map_art`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ui_map_x_map_art` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PhaseID` int NOT NULL DEFAULT '0',
  `UiMapArtID` int NOT NULL DEFAULT '0',
  `UiMapID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ui_map_x_map_art`
--

LOCK TABLES `ui_map_x_map_art` WRITE;
/*!40000 ALTER TABLE `ui_map_x_map_art` DISABLE KEYS */;
/*!40000 ALTER TABLE `ui_map_x_map_art` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unit_condition`
--

DROP TABLE IF EXISTS `unit_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `unit_condition` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `Variable1` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable2` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable3` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable4` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable5` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable6` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable7` tinyint unsigned NOT NULL DEFAULT '0',
  `Variable8` tinyint unsigned NOT NULL DEFAULT '0',
  `Op1` tinyint unsigned NOT NULL DEFAULT '0',
  `Op2` tinyint unsigned NOT NULL DEFAULT '0',
  `Op3` tinyint unsigned NOT NULL DEFAULT '0',
  `Op4` tinyint unsigned NOT NULL DEFAULT '0',
  `Op5` tinyint unsigned NOT NULL DEFAULT '0',
  `Op6` tinyint unsigned NOT NULL DEFAULT '0',
  `Op7` tinyint unsigned NOT NULL DEFAULT '0',
  `Op8` tinyint unsigned NOT NULL DEFAULT '0',
  `Value1` int NOT NULL DEFAULT '0',
  `Value2` int NOT NULL DEFAULT '0',
  `Value3` int NOT NULL DEFAULT '0',
  `Value4` int NOT NULL DEFAULT '0',
  `Value5` int NOT NULL DEFAULT '0',
  `Value6` int NOT NULL DEFAULT '0',
  `Value7` int NOT NULL DEFAULT '0',
  `Value8` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `unit_condition`
--

LOCK TABLES `unit_condition` WRITE;
/*!40000 ALTER TABLE `unit_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `unit_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unit_power_bar`
--

DROP TABLE IF EXISTS `unit_power_bar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `unit_power_bar` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Cost` text,
  `OutOfError` text,
  `ToolTip` text,
  `MinPower` int unsigned NOT NULL DEFAULT '0',
  `MaxPower` int unsigned NOT NULL DEFAULT '0',
  `StartPower` smallint unsigned NOT NULL DEFAULT '0',
  `CenterPower` tinyint unsigned NOT NULL DEFAULT '0',
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `BarType` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` smallint unsigned NOT NULL DEFAULT '0',
  `StartInset` float NOT NULL DEFAULT '0',
  `EndInset` float NOT NULL DEFAULT '0',
  `FileDataID1` int NOT NULL DEFAULT '0',
  `FileDataID2` int NOT NULL DEFAULT '0',
  `FileDataID3` int NOT NULL DEFAULT '0',
  `FileDataID4` int NOT NULL DEFAULT '0',
  `FileDataID5` int NOT NULL DEFAULT '0',
  `FileDataID6` int NOT NULL DEFAULT '0',
  `Color1` int NOT NULL DEFAULT '0',
  `Color2` int NOT NULL DEFAULT '0',
  `Color3` int NOT NULL DEFAULT '0',
  `Color4` int NOT NULL DEFAULT '0',
  `Color5` int NOT NULL DEFAULT '0',
  `Color6` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `unit_power_bar`
--

LOCK TABLES `unit_power_bar` WRITE;
/*!40000 ALTER TABLE `unit_power_bar` DISABLE KEYS */;
/*!40000 ALTER TABLE `unit_power_bar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unit_power_bar_locale`
--

DROP TABLE IF EXISTS `unit_power_bar_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `unit_power_bar_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Cost_lang` text,
  `OutOfError_lang` text,
  `ToolTip_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `unit_power_bar_locale`
--

LOCK TABLES `unit_power_bar_locale` WRITE;
/*!40000 ALTER TABLE `unit_power_bar_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `unit_power_bar_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vehicle`
--

DROP TABLE IF EXISTS `vehicle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vehicle` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `FlagsB` int NOT NULL DEFAULT '0',
  `TurnSpeed` float NOT NULL DEFAULT '0',
  `PitchSpeed` float NOT NULL DEFAULT '0',
  `PitchMin` float NOT NULL DEFAULT '0',
  `PitchMax` float NOT NULL DEFAULT '0',
  `MouseLookOffsetPitch` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMin` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMax` float NOT NULL DEFAULT '0',
  `CameraPitchOffset` float NOT NULL DEFAULT '0',
  `FacingLimitRight` float NOT NULL DEFAULT '0',
  `FacingLimitLeft` float NOT NULL DEFAULT '0',
  `CameraYawOffset` float NOT NULL DEFAULT '0',
  `VehicleUIIndicatorID` smallint unsigned NOT NULL DEFAULT '0',
  `MissileTargetingID` int NOT NULL DEFAULT '0',
  `VehiclePOITypeID` smallint unsigned NOT NULL DEFAULT '0',
  `UiLocomotionType` int NOT NULL DEFAULT '0',
  `SeatID1` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID2` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID3` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID4` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID5` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID6` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID7` smallint unsigned NOT NULL DEFAULT '0',
  `SeatID8` smallint unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID1` smallint unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID2` smallint unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID3` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vehicle`
--

LOCK TABLES `vehicle` WRITE;
/*!40000 ALTER TABLE `vehicle` DISABLE KEYS */;
/*!40000 ALTER TABLE `vehicle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vehicle_seat`
--

DROP TABLE IF EXISTS `vehicle_seat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vehicle_seat` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AttachmentOffsetX` float NOT NULL DEFAULT '0',
  `AttachmentOffsetY` float NOT NULL DEFAULT '0',
  `AttachmentOffsetZ` float NOT NULL DEFAULT '0',
  `CameraOffsetX` float NOT NULL DEFAULT '0',
  `CameraOffsetY` float NOT NULL DEFAULT '0',
  `CameraOffsetZ` float NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `FlagsB` int NOT NULL DEFAULT '0',
  `FlagsC` int NOT NULL DEFAULT '0',
  `AttachmentID` int NOT NULL DEFAULT '0',
  `EnterPreDelay` float NOT NULL DEFAULT '0',
  `EnterSpeed` float NOT NULL DEFAULT '0',
  `EnterGravity` float NOT NULL DEFAULT '0',
  `EnterMinDuration` float NOT NULL DEFAULT '0',
  `EnterMaxDuration` float NOT NULL DEFAULT '0',
  `EnterMinArcHeight` float NOT NULL DEFAULT '0',
  `EnterMaxArcHeight` float NOT NULL DEFAULT '0',
  `EnterAnimStart` smallint NOT NULL DEFAULT '0',
  `EnterAnimLoop` smallint NOT NULL DEFAULT '0',
  `RideAnimStart` smallint NOT NULL DEFAULT '0',
  `RideAnimLoop` smallint NOT NULL DEFAULT '0',
  `RideUpperAnimStart` smallint NOT NULL DEFAULT '0',
  `RideUpperAnimLoop` smallint NOT NULL DEFAULT '0',
  `ExitPreDelay` float NOT NULL DEFAULT '0',
  `ExitSpeed` float NOT NULL DEFAULT '0',
  `ExitGravity` float NOT NULL DEFAULT '0',
  `ExitMinDuration` float NOT NULL DEFAULT '0',
  `ExitMaxDuration` float NOT NULL DEFAULT '0',
  `ExitMinArcHeight` float NOT NULL DEFAULT '0',
  `ExitMaxArcHeight` float NOT NULL DEFAULT '0',
  `ExitAnimStart` smallint NOT NULL DEFAULT '0',
  `ExitAnimLoop` smallint NOT NULL DEFAULT '0',
  `ExitAnimEnd` smallint NOT NULL DEFAULT '0',
  `VehicleEnterAnim` smallint NOT NULL DEFAULT '0',
  `VehicleEnterAnimBone` tinyint NOT NULL DEFAULT '0',
  `VehicleExitAnim` smallint NOT NULL DEFAULT '0',
  `VehicleExitAnimBone` tinyint NOT NULL DEFAULT '0',
  `VehicleRideAnimLoop` smallint NOT NULL DEFAULT '0',
  `VehicleRideAnimLoopBone` tinyint NOT NULL DEFAULT '0',
  `PassengerAttachmentID` tinyint NOT NULL DEFAULT '0',
  `PassengerYaw` float NOT NULL DEFAULT '0',
  `PassengerPitch` float NOT NULL DEFAULT '0',
  `PassengerRoll` float NOT NULL DEFAULT '0',
  `VehicleEnterAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleExitAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleAbilityDisplay` tinyint NOT NULL DEFAULT '0',
  `EnterUISoundID` int unsigned NOT NULL DEFAULT '0',
  `ExitUISoundID` int unsigned NOT NULL DEFAULT '0',
  `UiSkinFileDataID` int NOT NULL DEFAULT '0',
  `UiSkin` int NOT NULL DEFAULT '0',
  `CameraEnteringDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDuration` float NOT NULL DEFAULT '0',
  `CameraExitingDelay` float NOT NULL DEFAULT '0',
  `CameraExitingDuration` float NOT NULL DEFAULT '0',
  `CameraPosChaseRate` float NOT NULL DEFAULT '0',
  `CameraFacingChaseRate` float NOT NULL DEFAULT '0',
  `CameraEnteringZoom` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMin` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMax` float NOT NULL DEFAULT '0',
  `EnterAnimKitID` smallint NOT NULL DEFAULT '0',
  `RideAnimKitID` smallint NOT NULL DEFAULT '0',
  `ExitAnimKitID` smallint NOT NULL DEFAULT '0',
  `VehicleEnterAnimKitID` smallint NOT NULL DEFAULT '0',
  `VehicleRideAnimKitID` smallint NOT NULL DEFAULT '0',
  `VehicleExitAnimKitID` smallint NOT NULL DEFAULT '0',
  `CameraModeID` smallint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vehicle_seat`
--

LOCK TABLES `vehicle_seat` WRITE;
/*!40000 ALTER TABLE `vehicle_seat` DISABLE KEYS */;
/*!40000 ALTER TABLE `vehicle_seat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vignette`
--

DROP TABLE IF EXISTS `vignette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vignette` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `VisibleTrackingQuestID` int unsigned NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `MaxHeight` float NOT NULL DEFAULT '0',
  `MinHeight` float NOT NULL DEFAULT '0',
  `VignetteType` tinyint NOT NULL DEFAULT '0',
  `RewardQuestID` int NOT NULL DEFAULT '0',
  `Unknown1156` tinyint NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vignette`
--

LOCK TABLES `vignette` WRITE;
/*!40000 ALTER TABLE `vignette` DISABLE KEYS */;
/*!40000 ALTER TABLE `vignette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vignette_locale`
--

DROP TABLE IF EXISTS `vignette_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vignette_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `vignette_locale`
--

LOCK TABLES `vignette_locale` WRITE;
/*!40000 ALTER TABLE `vignette_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `vignette_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `wmo_area_table`
--

DROP TABLE IF EXISTS `wmo_area_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `wmo_area_table` (
  `AreaName` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `WmoID` smallint unsigned NOT NULL DEFAULT '0',
  `NameSetID` tinyint unsigned NOT NULL DEFAULT '0',
  `WmoGroupID` int NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint unsigned NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint unsigned NOT NULL DEFAULT '0',
  `AmbienceID` smallint unsigned NOT NULL DEFAULT '0',
  `UwAmbience` smallint unsigned NOT NULL DEFAULT '0',
  `ZoneMusic` smallint unsigned NOT NULL DEFAULT '0',
  `UwZoneMusic` int unsigned NOT NULL DEFAULT '0',
  `IntroSound` smallint unsigned NOT NULL DEFAULT '0',
  `UwIntroSound` smallint unsigned NOT NULL DEFAULT '0',
  `AreaTableID` smallint unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `wmo_area_table`
--

LOCK TABLES `wmo_area_table` WRITE;
/*!40000 ALTER TABLE `wmo_area_table` DISABLE KEYS */;
/*!40000 ALTER TABLE `wmo_area_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `wmo_area_table_locale`
--

DROP TABLE IF EXISTS `wmo_area_table_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `wmo_area_table_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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
-- Dumping data for table `wmo_area_table_locale`
--

LOCK TABLES `wmo_area_table_locale` WRITE;
/*!40000 ALTER TABLE `wmo_area_table_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `wmo_area_table_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `world_effect`
--

DROP TABLE IF EXISTS `world_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `world_effect` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int unsigned NOT NULL DEFAULT '0',
  `WhenToDisplay` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetType` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetAsset` int NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `CombatConditionID` smallint unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `world_effect`
--

LOCK TABLES `world_effect` WRITE;
/*!40000 ALTER TABLE `world_effect` DISABLE KEYS */;
/*!40000 ALTER TABLE `world_effect` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `world_map_overlay`
--

DROP TABLE IF EXISTS `world_map_overlay`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `world_map_overlay` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `UiMapArtID` int unsigned NOT NULL DEFAULT '0',
  `TextureWidth` smallint unsigned NOT NULL DEFAULT '0',
  `TextureHeight` smallint unsigned NOT NULL DEFAULT '0',
  `OffsetX` int NOT NULL DEFAULT '0',
  `OffsetY` int NOT NULL DEFAULT '0',
  `HitRectTop` int NOT NULL DEFAULT '0',
  `HitRectBottom` int NOT NULL DEFAULT '0',
  `HitRectLeft` int NOT NULL DEFAULT '0',
  `HitRectRight` int NOT NULL DEFAULT '0',
  `PlayerConditionID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `AreaID1` int unsigned NOT NULL DEFAULT '0',
  `AreaID2` int unsigned NOT NULL DEFAULT '0',
  `AreaID3` int unsigned NOT NULL DEFAULT '0',
  `AreaID4` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `world_map_overlay`
--

LOCK TABLES `world_map_overlay` WRITE;
/*!40000 ALTER TABLE `world_map_overlay` DISABLE KEYS */;
/*!40000 ALTER TABLE `world_map_overlay` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `world_state_expression`
--

DROP TABLE IF EXISTS `world_state_expression`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `world_state_expression` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Expression` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `world_state_expression`
--

LOCK TABLES `world_state_expression` WRITE;
/*!40000 ALTER TABLE `world_state_expression` DISABLE KEYS */;
/*!40000 ALTER TABLE `world_state_expression` ENABLE KEYS */;
UNLOCK TABLES;
