--
-- Table structure for table `currency_container`
--
DROP TABLE IF EXISTS `currency_container`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_container` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ContainerName` text,
  `ContainerDescription` text,
  `MinAmount` int(11) NOT NULL DEFAULT '0',
  `MaxAmount` int(11) NOT NULL DEFAULT '0',
  `ContainerIconID` int(11) NOT NULL DEFAULT '0',
  `ContainerQuality` int(11) NOT NULL DEFAULT '0',
  `OnLootSpellVisualKitID` int(11) NOT NULL DEFAULT '0',
  `CurrencyTypesID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `currency_container_locale`
--
DROP TABLE IF EXISTS `currency_container_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `currency_container_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ContainerName_lang` text,
  `ContainerDescription_lang` text,
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
-- Table structure for table `garr_mission`
--
DROP TABLE IF EXISTS `garr_mission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `garr_mission` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Location` text,
  `Description` text,
  `MapPosX` float NOT NULL DEFAULT '0',
  `MapPosY` float NOT NULL DEFAULT '0',
  `WorldPosX` float NOT NULL DEFAULT '0',
  `WorldPosY` float NOT NULL DEFAULT '0',
  `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrMissionTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrFollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxFollowers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MissionCost` int(10) unsigned NOT NULL DEFAULT '0',
  `MissionCostCurrencyTypesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OfferedGarrMissionTextureID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EnvGarrMechanicID` int(10) unsigned NOT NULL DEFAULT '0',
  `EnvGarrMechanicTypeID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrMissionSetID` int(11) NOT NULL DEFAULT '0',
  `TargetLevel` tinyint(4) NOT NULL DEFAULT '0',
  `TargetItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MissionDuration` int(11) NOT NULL DEFAULT '0',
  `TravelDuration` int(11) NOT NULL DEFAULT '0',
  `OfferDuration` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseCompletionChance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BaseFollowerXP` int(10) unsigned NOT NULL DEFAULT '0',
  `OvermaxRewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerDeathChance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `AutoMissionScalar` float NOT NULL DEFAULT '0',
  `AutoMissionScalarCurveID` int(11) NOT NULL DEFAULT '0',
  `AutoCombatantEnvCasterID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_mission_locale`
--
DROP TABLE IF EXISTS `garr_mission_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `garr_mission_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Location_lang` text,
  `Description_lang` text,
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `JournalInstanceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DungeonEncounterID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `FirstSectionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UiMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MapDisplayConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DifficultyMask` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `journal_encounter_locale`
--
DROP TABLE IF EXISTS `journal_encounter_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
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
-- Table structure for table `journal_encounter_section`
--
DROP TABLE IF EXISTS `journal_encounter_section`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_section` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Title` text,
  `BodyText` text,
  `JournalEncounterID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParentSectionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FirstChildSectionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NextSiblingSectionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `IconCreatureDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `UiModelSceneID` int(11) NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `IconFileDataID` int(11) NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `IconFlags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyMask` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `journal_encounter_section_locale`
--
DROP TABLE IF EXISTS `journal_encounter_section_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_encounter_section_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Title_lang` text,
  `BodyText_lang` text,
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
-- Table structure for table `journal_instance`
--
DROP TABLE IF EXISTS `journal_instance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_instance` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BackgroundFileDataID` int(11) NOT NULL DEFAULT '0',
  `ButtonFileDataID` int(11) NOT NULL DEFAULT '0',
  `ButtonSmallFileDataID` int(11) NOT NULL DEFAULT '0',
  `LoreFileDataID` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `journal_instance_locale`
--
DROP TABLE IF EXISTS `journal_instance_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_instance_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
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
-- Table structure for table `journal_tier`
--
DROP TABLE IF EXISTS `journal_tier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_tier` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `journal_tier_locale`
--
DROP TABLE IF EXISTS `journal_tier_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `journal_tier_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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
-- Table structure for table `keystone_affix`
--
DROP TABLE IF EXISTS `keystone_affix`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `keystone_affix` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `FiledataID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `keystone_affix_locale`
--
DROP TABLE IF EXISTS `keystone_affix_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `keystone_affix_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
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
-- Table structure for table `map_challenge_mode`
--
DROP TABLE IF EXISTS `map_challenge_mode`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_challenge_mode` (
  `Name` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ExpansionLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `CriteriaCount1` smallint(6) NOT NULL DEFAULT '0',
  `CriteriaCount2` smallint(6) NOT NULL DEFAULT '0',
  `CriteriaCount3` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `map_challenge_mode_locale`
--
DROP TABLE IF EXISTS `map_challenge_mode_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `map_challenge_mode_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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
-- Table structure for table `maw_power`
--
DROP TABLE IF EXISTS `maw_power`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `maw_power` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `MawPowerRarityID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `soulbind_conduit_rank`
--
DROP TABLE IF EXISTS `soulbind_conduit_rank`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `soulbind_conduit_rank` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RankIndex` int(11) NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `AuraPointsOverride` float NOT NULL DEFAULT '0',
  `SoulbindConduitID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
