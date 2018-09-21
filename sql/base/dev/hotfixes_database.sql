-- MySQL dump 10.16  Distrib 10.1.6-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: hotfixes
-- ------------------------------------------------------
-- Server version	10.1.6-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `achievement`
--

DROP TABLE IF EXISTS `achievement`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `achievement` (
  `Title` text,
  `Description` text,
  `Reward` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `Supercedes` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Category` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UIOrder` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SharesCriteria` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Faction` tinyint(4) NOT NULL DEFAULT '0',
  `Points` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinimumCriteria` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `CriteriaTree` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `achievement_locale`
--

DROP TABLE IF EXISTS `achievement_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `achievement_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Title_lang` text,
  `Description_lang` text,
  `Reward_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `anim_kit`
--

DROP TABLE IF EXISTS `anim_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `anim_kit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `OneShotDuration` int(10) unsigned NOT NULL DEFAULT '0',
  `OneShotStopAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LowDefAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_group_member`
--

DROP TABLE IF EXISTS `area_group_member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_group_member` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaGroupID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_table`
--

DROP TABLE IF EXISTS `area_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_table` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ZoneName` text,
  `AreaName` text,
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `AmbientMultiplier` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentAreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaBit` smallint(6) NOT NULL DEFAULT '0',
  `AmbienceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ZoneMusic` smallint(5) unsigned NOT NULL DEFAULT '0',
  `IntroSound` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LiquidTypeID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UWZoneMusic` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UWAmbience` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PvPCombatWorldStateID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ExplorationLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FactionGroupMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MountFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `WildBattlePetLevelMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `WildBattlePetLevelMax` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `WindSettingsID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UWIntroSound` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_table_locale`
--

DROP TABLE IF EXISTS `area_table_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_table_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_trigger`
--

DROP TABLE IF EXISTS `area_trigger`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_trigger` (
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `BoxLength` float NOT NULL DEFAULT '0',
  `BoxWidth` float NOT NULL DEFAULT '0',
  `BoxHeight` float NOT NULL DEFAULT '0',
  `BoxYaw` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ShapeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaTriggerActionSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ShapeType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flag` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `armor_location`
--

DROP TABLE IF EXISTS `armor_location`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `armor_location` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Modifier1` float NOT NULL DEFAULT '0',
  `Modifier2` float NOT NULL DEFAULT '0',
  `Modifier3` float NOT NULL DEFAULT '0',
  `Modifier4` float NOT NULL DEFAULT '0',
  `Modifier5` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact`
--

DROP TABLE IF EXISTS `artifact`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `BarConnectedColor` int(10) unsigned NOT NULL DEFAULT '0',
  `BarDisconnectedColor` int(10) unsigned NOT NULL DEFAULT '0',
  `TitleColor` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassUiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArtifactCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UiModelSceneID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_appearance`
--

DROP TABLE IF EXISTS `artifact_appearance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_appearance` (
  `Name` text,
  `SwatchColor` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelDesaturation` float NOT NULL DEFAULT '0',
  `ModelAlpha` float NOT NULL DEFAULT '0',
  `ShapeshiftDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactAppearanceSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Unknown` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AppearanceModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ModifiesShapeshiftFormDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltItemAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_appearance_locale`
--

DROP TABLE IF EXISTS `artifact_appearance_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_appearance_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_appearance_set`
--

DROP TABLE IF EXISTS `artifact_appearance_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_appearance_set` (
  `Name` text,
  `Name2` text,
  `UiCameraID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AltHandUICameraID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttachmentPoint` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_appearance_set_locale`
--

DROP TABLE IF EXISTS `artifact_appearance_set_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_appearance_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name2_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_category`
--

DROP TABLE IF EXISTS `artifact_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactKnowledgeCurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArtifactKnowledgeMultiplierCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_locale`
--

DROP TABLE IF EXISTS `artifact_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_power`
--

DROP TABLE IF EXISTS `artifact_power`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_power` (
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactTier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RelicType` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_power_link`
--

DROP TABLE IF EXISTS `artifact_power_link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_power_link` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FromArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ToArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_power_picker`
--

DROP TABLE IF EXISTS `artifact_power_picker`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_power_picker` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_power_rank`
--

DROP TABLE IF EXISTS `artifact_power_rank`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_power_rank` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` float NOT NULL DEFAULT '0',
  `Unknown` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Rank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artifact_quest_xp`
--

DROP TABLE IF EXISTS `artifact_quest_xp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artifact_quest_xp` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp1` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp2` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp3` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp4` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp5` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp6` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp7` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp8` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp9` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp10` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `auction_house`
--

DROP TABLE IF EXISTS `auction_house`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auction_house` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `FactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DepositRate` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ConsignmentRate` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `auction_house_locale`
--

DROP TABLE IF EXISTS `auction_house_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auction_house_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `bank_bag_slot_prices`
--

DROP TABLE IF EXISTS `bank_bag_slot_prices`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bank_bag_slot_prices` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Cost` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `banned_addons`
--

DROP TABLE IF EXISTS `banned_addons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `banned_addons` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Version` text,
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `barber_shop_style`
--

DROP TABLE IF EXISTS `barber_shop_style`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `barber_shop_style` (
  `DisplayName` text,
  `Description` text,
  `CostModifier` float NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Sex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Data` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `barber_shop_style_locale`
--

DROP TABLE IF EXISTS `barber_shop_style_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `barber_shop_style_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battle_pet_breed_quality`
--

DROP TABLE IF EXISTS `battle_pet_breed_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_breed_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Modifier` float NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battle_pet_breed_state`
--

DROP TABLE IF EXISTS `battle_pet_breed_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_breed_state` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` smallint(6) NOT NULL DEFAULT '0',
  `State` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BreedID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battle_pet_species`
--

DROP TABLE IF EXISTS `battle_pet_species`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_species` (
  `SourceText` text,
  `Description` text,
  `CreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileID` int(10) unsigned NOT NULL DEFAULT '0',
  `SummonSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PetType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Source` tinyint(4) NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CardModelSceneID` int(10) unsigned NOT NULL DEFAULT '0',
  `LoadoutModelSceneID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battle_pet_species_locale`
--

DROP TABLE IF EXISTS `battle_pet_species_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_species_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceText_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battle_pet_species_state`
--

DROP TABLE IF EXISTS `battle_pet_species_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_species_state` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` int(11) NOT NULL DEFAULT '0',
  `State` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpeciesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battlemaster_list`
--

DROP TABLE IF EXISTS `battlemaster_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlemaster_list` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `GameType` text,
  `ShortDescription` text,
  `LongDescription` text,
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID1` smallint(6) NOT NULL DEFAULT '0',
  `MapID2` smallint(6) NOT NULL DEFAULT '0',
  `MapID3` smallint(6) NOT NULL DEFAULT '0',
  `MapID4` smallint(6) NOT NULL DEFAULT '0',
  `MapID5` smallint(6) NOT NULL DEFAULT '0',
  `MapID6` smallint(6) NOT NULL DEFAULT '0',
  `MapID7` smallint(6) NOT NULL DEFAULT '0',
  `MapID8` smallint(6) NOT NULL DEFAULT '0',
  `MapID9` smallint(6) NOT NULL DEFAULT '0',
  `MapID10` smallint(6) NOT NULL DEFAULT '0',
  `MapID11` smallint(6) NOT NULL DEFAULT '0',
  `MapID12` smallint(6) NOT NULL DEFAULT '0',
  `MapID13` smallint(6) NOT NULL DEFAULT '0',
  `MapID14` smallint(6) NOT NULL DEFAULT '0',
  `MapID15` smallint(6) NOT NULL DEFAULT '0',
  `MapID16` smallint(6) NOT NULL DEFAULT '0',
  `HolidayWorldState` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `InstanceType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GroupsAllowed` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxGroupSize` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RatedPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `battlemaster_list_locale`
--

DROP TABLE IF EXISTS `battlemaster_list_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlemaster_list_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `GameType_lang` text,
  `ShortDescription_lang` text,
  `LongDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `broadcast_text`
--

DROP TABLE IF EXISTS `broadcast_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `broadcast_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaleText` text,
  `FemaleText` text,
  `EmoteID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UnkEmoteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Language` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID1` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID2` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `broadcast_text_locale`
--

DROP TABLE IF EXISTS `broadcast_text_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `broadcast_text_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `MaleText_lang` text,
  `FemaleText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_base_section`
--

DROP TABLE IF EXISTS `char_base_section`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_base_section` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Variation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ResolutionVariation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Resolution` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_sections`
--

DROP TABLE IF EXISTS `char_sections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_sections` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID1` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID2` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID3` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SexID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BaseSection` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VariationIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ColorIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_start_outfit`
--

DROP TABLE IF EXISTS `char_start_outfit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_start_outfit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID1` int(11) NOT NULL DEFAULT '0',
  `ItemID2` int(11) NOT NULL DEFAULT '0',
  `ItemID3` int(11) NOT NULL DEFAULT '0',
  `ItemID4` int(11) NOT NULL DEFAULT '0',
  `ItemID5` int(11) NOT NULL DEFAULT '0',
  `ItemID6` int(11) NOT NULL DEFAULT '0',
  `ItemID7` int(11) NOT NULL DEFAULT '0',
  `ItemID8` int(11) NOT NULL DEFAULT '0',
  `ItemID9` int(11) NOT NULL DEFAULT '0',
  `ItemID10` int(11) NOT NULL DEFAULT '0',
  `ItemID11` int(11) NOT NULL DEFAULT '0',
  `ItemID12` int(11) NOT NULL DEFAULT '0',
  `ItemID13` int(11) NOT NULL DEFAULT '0',
  `ItemID14` int(11) NOT NULL DEFAULT '0',
  `ItemID15` int(11) NOT NULL DEFAULT '0',
  `ItemID16` int(11) NOT NULL DEFAULT '0',
  `ItemID17` int(11) NOT NULL DEFAULT '0',
  `ItemID18` int(11) NOT NULL DEFAULT '0',
  `ItemID19` int(11) NOT NULL DEFAULT '0',
  `ItemID20` int(11) NOT NULL DEFAULT '0',
  `ItemID21` int(11) NOT NULL DEFAULT '0',
  `ItemID22` int(11) NOT NULL DEFAULT '0',
  `ItemID23` int(11) NOT NULL DEFAULT '0',
  `ItemID24` int(11) NOT NULL DEFAULT '0',
  `PetDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GenderID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OutfitID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PetFamilyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_titles`
--

DROP TABLE IF EXISTS `char_titles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_titles` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NameMale` text,
  `NameFemale` text,
  `MaskID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_titles_locale`
--

DROP TABLE IF EXISTS `char_titles_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_titles_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `NameMale_lang` text,
  `NameFemale_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `character_facial_hair_styles`
--

DROP TABLE IF EXISTS `character_facial_hair_styles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `character_facial_hair_styles` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset1` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset2` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset3` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset4` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset5` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SexID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VariationID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chat_channels`
--

DROP TABLE IF EXISTS `chat_channels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chat_channels` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Shortcut` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chat_channels_locale`
--

DROP TABLE IF EXISTS `chat_channels_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chat_channels_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Shortcut_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_classes`
--

DROP TABLE IF EXISTS `chr_classes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_classes` (
  `PetNameToken` text,
  `Name` text,
  `NameFemale` text,
  `NameMale` text,
  `Filename` text,
  `CreateScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `StartingLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DefaultSpec` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerStrength` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RangedAttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_classes_locale`
--

DROP TABLE IF EXISTS `chr_classes_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_classes_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameFemale_lang` text,
  `NameMale_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_classes_x_power_types`
--

DROP TABLE IF EXISTS `chr_classes_x_power_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_classes_x_power_types` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_races`
--

DROP TABLE IF EXISTS `chr_races`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_races` (
  `ClientPrefix` text,
  `ClientFileString` text,
  `Name` text,
  `NameFemale` text,
  `LowercaseName` text,
  `LowercaseNameFemale` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `FemaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreateScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaleCustomizeOffset1` float NOT NULL DEFAULT '0',
  `MaleCustomizeOffset2` float NOT NULL DEFAULT '0',
  `MaleCustomizeOffset3` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset1` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset2` float NOT NULL DEFAULT '0',
  `FemaleCustomizeOffset3` float NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `StartingLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `UIDisplayOrder` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ResSicknessSpellID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SplashSoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BaseLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CreatureType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TeamID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RaceRelated` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UnalteredVisualRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CharComponentTextureLayoutID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DefaultClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `NeutralRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemAppearanceFrameRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CharComponentTexLayoutHiResID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HighResMaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `HighResFemaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `HeritageArmorAchievementID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaleCorpseBonesModelFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `FemaleCorpseBonesModelFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualID3` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualKitID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualKitID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AlteredFormTransitionSpellVisualKitID3` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_races_locale`
--

DROP TABLE IF EXISTS `chr_races_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_races_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameFemale_lang` text,
  `LowercaseName_lang` text,
  `LowercaseNameFemale_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_specialization`
--

DROP TABLE IF EXISTS `chr_specialization`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_specialization` (
  `Name` text,
  `Name2` text,
  `Description` text,
  `MasterySpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `MasterySpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PetTalentType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Role` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PrimaryStatOrder` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_specialization_locale`
--

DROP TABLE IF EXISTS `chr_specialization_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_specialization_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name2_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `cinematic_camera`
--

DROP TABLE IF EXISTS `cinematic_camera`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cinematic_camera` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `OriginX` float NOT NULL DEFAULT '0',
  `OriginY` float NOT NULL DEFAULT '0',
  `OriginZ` float NOT NULL DEFAULT '0',
  `OriginFacing` float NOT NULL DEFAULT '0',
  `ModelFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `cinematic_sequences`
--

DROP TABLE IF EXISTS `cinematic_sequences`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cinematic_sequences` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Camera8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `conversation_line`
--

DROP TABLE IF EXISTS `conversation_line`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `conversation_line` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BroadcastTextID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration` int(10) unsigned NOT NULL DEFAULT '0',
  `NextLineID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Unk1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Yell` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature`
--

DROP TABLE IF EXISTS `creature`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ItemID1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ItemID2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ItemID3` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Mount` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayID1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayID2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayID3` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayID4` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayIDProbability1` float NOT NULL DEFAULT '0',
  `DisplayIDProbability2` float NOT NULL DEFAULT '0',
  `DisplayIDProbability3` float NOT NULL DEFAULT '0',
  `DisplayIDProbability4` float NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `FemaleName` text NOT NULL,
  `SubName` text NOT NULL,
  `FemaleSubName` text NOT NULL,
  `Type` mediumint(3) unsigned NOT NULL DEFAULT '0',
  `Family` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Classification` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InhabitType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_difficulty`
--

DROP TABLE IF EXISTS `creature_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_difficulty` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `CreatureID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags4` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags5` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags6` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags7` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionTemplateID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(4) NOT NULL DEFAULT '0',
  `MinLevel` tinyint(4) NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_display_info`
--

DROP TABLE IF EXISTS `creature_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_display_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureModelScale` float NOT NULL DEFAULT '0',
  `ModelID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NPCSoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SizeClass` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Gender` tinyint(4) NOT NULL DEFAULT '0',
  `ExtendedDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `PortraitTextureFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureModelAlpha` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerModelScale` float NOT NULL DEFAULT '0',
  `PortraitCreatureDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `BloodID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParticleColorID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CreatureGeosetData` int(10) unsigned NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UnarmedWeaponSubclass` tinyint(4) NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `InstanceOtherPlayerPetScale` float NOT NULL DEFAULT '0',
  `MountSpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureVariation1` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureVariation2` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureVariation3` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_display_info_extra`
--

DROP TABLE IF EXISTS `creature_display_info_extra`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_display_info_extra` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `HDFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DisplaySexID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DisplayClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SkinID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HairStyleID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HairColorID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FacialHairID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CustomDisplayOption1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CustomDisplayOption2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CustomDisplayOption3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_family`
--

DROP TABLE IF EXISTS `creature_family`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_family` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `MinScale` float NOT NULL DEFAULT '0',
  `MaxScale` float NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SkillLine1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SkillLine2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PetFoodMask` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinScaleLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxScaleLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PetTalentType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_family_locale`
--

DROP TABLE IF EXISTS `creature_family_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_family_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_model_data`
--

DROP TABLE IF EXISTS `creature_model_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_model_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelScale` float NOT NULL DEFAULT '0',
  `FootprintTextureLength` float NOT NULL DEFAULT '0',
  `FootprintTextureWidth` float NOT NULL DEFAULT '0',
  `FootprintParticleScale` float NOT NULL DEFAULT '0',
  `CollisionWidth` float NOT NULL DEFAULT '0',
  `CollisionHeight` float NOT NULL DEFAULT '0',
  `MountHeight` float NOT NULL DEFAULT '0',
  `GeoBoxMin1` float NOT NULL DEFAULT '0',
  `GeoBoxMin2` float NOT NULL DEFAULT '0',
  `GeoBoxMin3` float NOT NULL DEFAULT '0',
  `GeoBoxMax1` float NOT NULL DEFAULT '0',
  `GeoBoxMax2` float NOT NULL DEFAULT '0',
  `GeoBoxMax3` float NOT NULL DEFAULT '0',
  `WorldEffectScale` float NOT NULL DEFAULT '0',
  `AttachedEffectScale` float NOT NULL DEFAULT '0',
  `MissileCollisionRadius` float NOT NULL DEFAULT '0',
  `MissileCollisionPush` float NOT NULL DEFAULT '0',
  `MissileCollisionRaise` float NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `OverrideSelectionRadius` float NOT NULL DEFAULT '0',
  `TamedPetBaseScale` float NOT NULL DEFAULT '0',
  `HoverHeight` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SizeClass` int(10) unsigned NOT NULL DEFAULT '0',
  `BloodID` int(10) unsigned NOT NULL DEFAULT '0',
  `FootprintTextureID` int(10) unsigned NOT NULL DEFAULT '0',
  `FoleyMaterialID` int(10) unsigned NOT NULL DEFAULT '0',
  `FootstepEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `DeathThudEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureGeosetDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_type`
--

DROP TABLE IF EXISTS `creature_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_type_locale`
--

DROP TABLE IF EXISTS `creature_type_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_type_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `criteria`
--

DROP TABLE IF EXISTS `criteria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `criteria` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Asset` int(10) unsigned NOT NULL DEFAULT '0',
  `StartAsset` int(10) unsigned NOT NULL DEFAULT '0',
  `FailAsset` int(10) unsigned NOT NULL DEFAULT '0',
  `ModifierTreeId` int(10) unsigned NOT NULL DEFAULT '0',
  `StartTimer` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EligibilityWorldStateID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StartEvent` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FailEvent` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EligibilityWorldStateValue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `criteria_tree`
--

DROP TABLE IF EXISTS `criteria_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `criteria_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Amount` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Operator` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CriteriaID` int(10) unsigned NOT NULL DEFAULT '0',
  `Parent` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `criteria_tree_locale`
--

DROP TABLE IF EXISTS `criteria_tree_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `criteria_tree_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `currency_types`
--

DROP TABLE IF EXISTS `currency_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currency_types` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `MaxQty` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxEarnablePerWeek` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellCategory` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InventoryIconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellWeight` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `currency_types_locale`
--

DROP TABLE IF EXISTS `currency_types_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currency_types_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `curve`
--

DROP TABLE IF EXISTS `curve`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `curve` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unused` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `curve_point`
--

DROP TABLE IF EXISTS `curve_point`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `curve_point` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
  `CurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Index` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `destructible_model_data`
--

DROP TABLE IF EXISTS `destructible_model_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `destructible_model_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedDisplayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDisplayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDisplayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StateSmokeDisplayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `HealEffectSpeed` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StateDamagedImpactEffectDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDamagedAmbientDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDamagedNameSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDestructionDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedImpactEffectDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedAmbientDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedNameSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDestructionDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingImpactEffectDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingAmbientDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingNameSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateSmokeInitDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateSmokeAmbientDoodadSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `StateSmokeNameSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EjectDirection` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DoNotHighlight` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HealEffect` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `difficulty`
--

DROP TABLE IF EXISTS `difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `GroupSizeHealthCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GroupSizeDmgCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GroupSizeSpellPointsCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FallbackDifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InstanceType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OldEnumValue` tinyint(4) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ToggleDifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemBonusTreeModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `difficulty_locale`
--

DROP TABLE IF EXISTS `difficulty_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `difficulty_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `dungeon_encounter`
--

DROP TABLE IF EXISTS `dungeon_encounter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dungeon_encounter` (
  `Name` text,
  `CreatureDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Bit` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `TextureFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `dungeon_encounter_locale`
--

DROP TABLE IF EXISTS `dungeon_encounter_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dungeon_encounter_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `durability_costs`
--

DROP TABLE IF EXISTS `durability_costs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `durability_costs` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost9` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost10` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost11` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost12` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost13` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost14` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost15` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost16` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost17` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost18` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost19` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost20` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeaponSubClassCost21` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArmorSubClassCost8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `durability_quality`
--

DROP TABLE IF EXISTS `durability_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `durability_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `QualityMod` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `emotes`
--

DROP TABLE IF EXISTS `emotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emotes` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceMask` bigint(20) NOT NULL DEFAULT '0',
  `EmoteSlashCommand` text,
  `SpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteSpecProc` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EmoteSpecProcParam` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteSoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `emotes_text`
--

DROP TABLE IF EXISTS `emotes_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emotes_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `EmoteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `emotes_text_locale`
--

DROP TABLE IF EXISTS `emotes_text_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emotes_text_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `emotes_text_sound`
--

DROP TABLE IF EXISTS `emotes_text_sound`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emotes_text_sound` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SexId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundId` int(10) unsigned NOT NULL DEFAULT '0',
  `EmotesTextId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `faction`
--

DROP TABLE IF EXISTS `faction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `faction` (
  `ReputationRaceMask1` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask2` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask3` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask4` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationBase1` int(11) NOT NULL DEFAULT '0',
  `ReputationBase2` int(11) NOT NULL DEFAULT '0',
  `ReputationBase3` int(11) NOT NULL DEFAULT '0',
  `ReputationBase4` int(11) NOT NULL DEFAULT '0',
  `ParentFactionModIn` float NOT NULL DEFAULT '0',
  `ParentFactionModOut` float NOT NULL DEFAULT '0',
  `ReputationMax1` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationMax2` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationMax3` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationMax4` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationIndex` smallint(6) NOT NULL DEFAULT '0',
  `ReputationClassMask1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParagonFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentFactionCapIn` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParentFactionCapOut` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FriendshipRepID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `faction_locale`
--

DROP TABLE IF EXISTS `faction_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `faction_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `faction_template`
--

DROP TABLE IF EXISTS `faction_template`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `faction_template` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Faction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Mask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FriendMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EnemyMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `gameobject_display_info`
--

DROP TABLE IF EXISTS `gameobject_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gameobject_display_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `GeoBoxMinX` float NOT NULL DEFAULT '0',
  `GeoBoxMinY` float NOT NULL DEFAULT '0',
  `GeoBoxMinZ` float NOT NULL DEFAULT '0',
  `GeoBoxMaxX` float NOT NULL DEFAULT '0',
  `GeoBoxMaxY` float NOT NULL DEFAULT '0',
  `GeoBoxMaxZ` float NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `gameobjects`
--

DROP TABLE IF EXISTS `gameobjects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gameobjects` (
  `Name` text,
  `PositionX` float NOT NULL DEFAULT '0',
  `PositionY` float NOT NULL DEFAULT '0',
  `PositionZ` float NOT NULL DEFAULT '0',
  `RotationX` float NOT NULL DEFAULT '0',
  `RotationY` float NOT NULL DEFAULT '0',
  `RotationZ` float NOT NULL DEFAULT '0',
  `RotationW` float NOT NULL DEFAULT '0',
  `Size` float NOT NULL DEFAULT '0',
  `Data1` int(11) NOT NULL DEFAULT '0',
  `Data2` int(11) NOT NULL DEFAULT '0',
  `Data3` int(11) NOT NULL DEFAULT '0',
  `Data4` int(11) NOT NULL DEFAULT '0',
  `Data5` int(11) NOT NULL DEFAULT '0',
  `Data6` int(11) NOT NULL DEFAULT '0',
  `Data7` int(11) NOT NULL DEFAULT '0',
  `Data8` int(11) NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `gameobjects_locale`
--

DROP TABLE IF EXISTS `gameobjects_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gameobjects_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_ability`
--

DROP TABLE IF EXISTS `garr_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_ability` (
  `Name` text,
  `Description` text,
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OtherFactionGarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_ability_locale`
--

DROP TABLE IF EXISTS `garr_ability_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_ability_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_building`
--

DROP TABLE IF EXISTS `garr_building`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_building` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NameAlliance` text,
  `NameHorde` text,
  `Description` text,
  `Tooltip` text,
  `HordeGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `CostCurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `HordeTexPrefixKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllianceTexPrefixKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllianceActivationScenePackageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `HordeActivationScenePackageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FollowerRequiredGarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FollowerGarrAbilityEffectID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CostMoney` smallint(6) NOT NULL DEFAULT '0',
  `Unknown` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxShipments` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BuildDuration` int(11) NOT NULL DEFAULT '0',
  `CostCurrencyAmount` int(11) NOT NULL DEFAULT '0',
  `BonusAmount` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_building_locale`
--

DROP TABLE IF EXISTS `garr_building_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_building_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `NameAlliance_lang` text,
  `NameHorde_lang` text,
  `Description_lang` text,
  `Tooltip_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_building_plot_inst`
--

DROP TABLE IF EXISTS `garr_building_plot_inst`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_building_plot_inst` (
  `LandmarkOffsetX` float NOT NULL DEFAULT '0',
  `LandmarkOffsetY` float NOT NULL DEFAULT '0',
  `UiTextureAtlasMemberID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrSiteLevelPlotInstID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrBuildingID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_class_spec`
--

DROP TABLE IF EXISTS `garr_class_spec`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_class_spec` (
  `NameMale` text,
  `NameFemale` text,
  `NameGenderless` text,
  `ClassAtlasID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Limit` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_class_spec_locale`
--

DROP TABLE IF EXISTS `garr_class_spec_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_class_spec_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `NameMale_lang` text,
  `NameFemale_lang` text,
  `NameGenderless_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_follower`
--

DROP TABLE IF EXISTS `garr_follower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower` (
  `HordeSourceText` text,
  `AllianceSourceText` text,
  `Name` text,
  `HordeCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `AlliancePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeAddedBroadcastTextID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceAddedBroadcastTextID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelWeapon` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelArmor` smallint(5) unsigned NOT NULL DEFAULT '0',
  `HordeListPortraitTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllianceListPortraitTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HordeUiAnimRaceInfoID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllianceUiAnimRaceInfoID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HordeGarrClassSpecID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrClassSpecID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unknown1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unknown2` tinyint(4) NOT NULL DEFAULT '0',
  `Unknown3` tinyint(4) NOT NULL DEFAULT '0',
  `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxDurability` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Class` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HordeFlavorTextGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllianceFlavorTextGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_follower_locale`
--

DROP TABLE IF EXISTS `garr_follower_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `HordeSourceText_lang` text,
  `AllianceSourceText_lang` text,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_follower_x_ability`
--

DROP TABLE IF EXISTS `garr_follower_x_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower_x_ability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FactionIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrFollowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_plot`
--

DROP TABLE IF EXISTS `garr_plot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_plot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `AllianceConstructionGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeConstructionGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrPlotUICategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PlotType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCount` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxCount` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_plot_building`
--

DROP TABLE IF EXISTS `garr_plot_building`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_plot_building` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrPlotID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrBuildingID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_plot_instance`
--

DROP TABLE IF EXISTS `garr_plot_instance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_plot_instance` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `GarrPlotID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_plot_instance_locale`
--

DROP TABLE IF EXISTS `garr_plot_instance_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_plot_instance_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_plot_locale`
--

DROP TABLE IF EXISTS `garr_plot_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_plot_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_site_level`
--

DROP TABLE IF EXISTS `garr_site_level`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_site_level` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TownHallX` float NOT NULL DEFAULT '0',
  `TownHallY` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SiteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MovieID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UpgradeResourceCost` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UpgradeMoneyCost` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UITextureKitID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Level2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garr_site_level_plot_inst`
--

DROP TABLE IF EXISTS `garr_site_level_plot_inst`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_site_level_plot_inst` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LandmarkX` float NOT NULL DEFAULT '0',
  `LandmarkY` float NOT NULL DEFAULT '0',
  `GarrSiteLevelID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrPlotInstanceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unknown` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `gem_properties`
--

DROP TABLE IF EXISTS `gem_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gem_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glyph_bindable_spell`
--

DROP TABLE IF EXISTS `glyph_bindable_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glyph_bindable_spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `GlyphPropertiesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glyph_properties`
--

DROP TABLE IF EXISTS `glyph_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glyph_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellIconID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GlyphExclusiveCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glyph_required_spec`
--

DROP TABLE IF EXISTS `glyph_required_spec`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glyph_required_spec` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GlyphPropertiesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `guild_color_background`
--

DROP TABLE IF EXISTS `guild_color_background`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guild_color_background` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Red` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Green` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `guild_color_border`
--

DROP TABLE IF EXISTS `guild_color_border`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guild_color_border` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Red` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Green` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `guild_color_emblem`
--

DROP TABLE IF EXISTS `guild_color_emblem`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guild_color_emblem` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Red` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Green` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `guild_perk_spells`
--

DROP TABLE IF EXISTS `guild_perk_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guild_perk_spells` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `heirloom`
--

DROP TABLE IF EXISTS `heirloom`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `heirloom` (
  `SourceText` text,
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `OldItem1` int(10) unsigned NOT NULL DEFAULT '0',
  `OldItem2` int(10) unsigned NOT NULL DEFAULT '0',
  `NextDifficultyItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeItemID1` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeItemID2` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeItemID3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Source` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `heirloom_locale`
--

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

--
-- Table structure for table `holidays`
--

DROP TABLE IF EXISTS `holidays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `holidays` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Date1` int(10) unsigned NOT NULL DEFAULT '0',
  `Date2` int(10) unsigned NOT NULL DEFAULT '0',
  `Date3` int(10) unsigned NOT NULL DEFAULT '0',
  `Date4` int(10) unsigned NOT NULL DEFAULT '0',
  `Date5` int(10) unsigned NOT NULL DEFAULT '0',
  `Date6` int(10) unsigned NOT NULL DEFAULT '0',
  `Date7` int(10) unsigned NOT NULL DEFAULT '0',
  `Date8` int(10) unsigned NOT NULL DEFAULT '0',
  `Date9` int(10) unsigned NOT NULL DEFAULT '0',
  `Date10` int(10) unsigned NOT NULL DEFAULT '0',
  `Date11` int(10) unsigned NOT NULL DEFAULT '0',
  `Date12` int(10) unsigned NOT NULL DEFAULT '0',
  `Date13` int(10) unsigned NOT NULL DEFAULT '0',
  `Date14` int(10) unsigned NOT NULL DEFAULT '0',
  `Date15` int(10) unsigned NOT NULL DEFAULT '0',
  `Date16` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration9` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Duration10` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Region` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Looping` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags9` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags10` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Priority` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CalendarFilterType` tinyint(4) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `HolidayNameID` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayDescriptionID` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID1` int(11) NOT NULL DEFAULT '0',
  `TextureFileDataID2` int(11) NOT NULL DEFAULT '0',
  `TextureFileDataID3` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `hotfix_data`
--

DROP TABLE IF EXISTS `hotfix_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hotfix_data` (
  `Id` int(11) NOT NULL,
  `TableHash` int(10) unsigned NOT NULL,
  `RecordId` int(11) NOT NULL,
  `Deleted` tinyint(3) unsigned DEFAULT '0',
  PRIMARY KEY (`Id`,`TableHash`,`RecordId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `import_price_armor`
--

DROP TABLE IF EXISTS `import_price_armor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `import_price_armor` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClothFactor` float NOT NULL DEFAULT '0',
  `LeatherFactor` float NOT NULL DEFAULT '0',
  `MailFactor` float NOT NULL DEFAULT '0',
  `PlateFactor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `import_price_quality`
--

DROP TABLE IF EXISTS `import_price_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `import_price_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `import_price_shield`
--

DROP TABLE IF EXISTS `import_price_shield`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `import_price_shield` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `import_price_weapon`
--

DROP TABLE IF EXISTS `import_price_weapon`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `import_price_weapon` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Class` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SubClass` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclass` tinyint(4) NOT NULL DEFAULT '0',
  `Material` tinyint(4) NOT NULL DEFAULT '0',
  `InventoryType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Sheath` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GroupSoundsID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_appearance`
--

DROP TABLE IF EXISTS `item_appearance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_appearance` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `UIOrder` int(10) unsigned NOT NULL DEFAULT '0',
  `ObjectComponentSlot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_armor_quality`
--

DROP TABLE IF EXISTS `item_armor_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_armor_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `QualityMod1` float NOT NULL DEFAULT '0',
  `QualityMod2` float NOT NULL DEFAULT '0',
  `QualityMod3` float NOT NULL DEFAULT '0',
  `QualityMod4` float NOT NULL DEFAULT '0',
  `QualityMod5` float NOT NULL DEFAULT '0',
  `QualityMod6` float NOT NULL DEFAULT '0',
  `QualityMod7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_armor_shield`
--

DROP TABLE IF EXISTS `item_armor_shield`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_armor_shield` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality1` float NOT NULL DEFAULT '0',
  `Quality2` float NOT NULL DEFAULT '0',
  `Quality3` float NOT NULL DEFAULT '0',
  `Quality4` float NOT NULL DEFAULT '0',
  `Quality5` float NOT NULL DEFAULT '0',
  `Quality6` float NOT NULL DEFAULT '0',
  `Quality7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_armor_total`
--

DROP TABLE IF EXISTS `item_armor_total`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_armor_total` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value1` float NOT NULL DEFAULT '0',
  `Value2` float NOT NULL DEFAULT '0',
  `Value3` float NOT NULL DEFAULT '0',
  `Value4` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_bag_family`
--

DROP TABLE IF EXISTS `item_bag_family`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_bag_family` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_bag_family_locale`
--

DROP TABLE IF EXISTS `item_bag_family_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_bag_family_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_bonus`
--

DROP TABLE IF EXISTS `item_bonus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_bonus` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value1` int(11) NOT NULL DEFAULT '0',
  `Value2` int(11) NOT NULL DEFAULT '0',
  `Value3` int(11) NOT NULL DEFAULT '0',
  `BonusListID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Index` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_bonus_list_level_delta`
--

DROP TABLE IF EXISTS `item_bonus_list_level_delta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_bonus_list_level_delta` (
  `Delta` smallint(6) NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_bonus_tree_node`
--

DROP TABLE IF EXISTS `item_bonus_tree_node`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_bonus_tree_node` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SubTreeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusListID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelSelectorID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusTreeModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BonusTreeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_child_equipment`
--

DROP TABLE IF EXISTS `item_child_equipment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_child_equipment` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltEquipmentSlot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_class`
--

DROP TABLE IF EXISTS `item_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_class` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `PriceMod` float NOT NULL DEFAULT '0',
  `OldEnumValue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_class_locale`
--

DROP TABLE IF EXISTS `item_class_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_class_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_currency_cost`
--

DROP TABLE IF EXISTS `item_currency_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_currency_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_damage_ammo`
--

DROP TABLE IF EXISTS `item_damage_ammo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_damage_ammo` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DPS1` float NOT NULL DEFAULT '0',
  `DPS2` float NOT NULL DEFAULT '0',
  `DPS3` float NOT NULL DEFAULT '0',
  `DPS4` float NOT NULL DEFAULT '0',
  `DPS5` float NOT NULL DEFAULT '0',
  `DPS6` float NOT NULL DEFAULT '0',
  `DPS7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_damage_one_hand`
--

DROP TABLE IF EXISTS `item_damage_one_hand`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_damage_one_hand` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DPS1` float NOT NULL DEFAULT '0',
  `DPS2` float NOT NULL DEFAULT '0',
  `DPS3` float NOT NULL DEFAULT '0',
  `DPS4` float NOT NULL DEFAULT '0',
  `DPS5` float NOT NULL DEFAULT '0',
  `DPS6` float NOT NULL DEFAULT '0',
  `DPS7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_damage_one_hand_caster`
--

DROP TABLE IF EXISTS `item_damage_one_hand_caster`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_damage_one_hand_caster` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DPS1` float NOT NULL DEFAULT '0',
  `DPS2` float NOT NULL DEFAULT '0',
  `DPS3` float NOT NULL DEFAULT '0',
  `DPS4` float NOT NULL DEFAULT '0',
  `DPS5` float NOT NULL DEFAULT '0',
  `DPS6` float NOT NULL DEFAULT '0',
  `DPS7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_damage_two_hand`
--

DROP TABLE IF EXISTS `item_damage_two_hand`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_damage_two_hand` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DPS1` float NOT NULL DEFAULT '0',
  `DPS2` float NOT NULL DEFAULT '0',
  `DPS3` float NOT NULL DEFAULT '0',
  `DPS4` float NOT NULL DEFAULT '0',
  `DPS5` float NOT NULL DEFAULT '0',
  `DPS6` float NOT NULL DEFAULT '0',
  `DPS7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_damage_two_hand_caster`
--

DROP TABLE IF EXISTS `item_damage_two_hand_caster`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_damage_two_hand_caster` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DPS1` float NOT NULL DEFAULT '0',
  `DPS2` float NOT NULL DEFAULT '0',
  `DPS3` float NOT NULL DEFAULT '0',
  `DPS4` float NOT NULL DEFAULT '0',
  `DPS5` float NOT NULL DEFAULT '0',
  `DPS6` float NOT NULL DEFAULT '0',
  `DPS7` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_disenchant_loot`
--

DROP TABLE IF EXISTS `item_disenchant_loot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_disenchant_loot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredDisenchantSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemSubClass` tinyint(4) NOT NULL DEFAULT '0',
  `ItemQuality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(4) NOT NULL DEFAULT '0',
  `ItemClass` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_effect`
--

DROP TABLE IF EXISTS `item_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_effect` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Cooldown` int(11) NOT NULL DEFAULT '0',
  `CategoryCooldown` int(11) NOT NULL DEFAULT '0',
  `Charges` smallint(6) NOT NULL DEFAULT '0',
  `Category` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Trigger` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_extended_cost`
--

DROP TABLE IF EXISTS `item_extended_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_extended_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredPersonalArenaRating` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredArenaSlot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredFactionId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredFactionStanding` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequirementFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredAchievement` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_level_selector`
--

DROP TABLE IF EXISTS `item_level_selector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_level_selector` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelSelectorQualitySetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_level_selector_quality`
--

DROP TABLE IF EXISTS `item_level_selector_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_level_selector_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemLevelSelectorQualitySetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_level_selector_quality_set`
--

DROP TABLE IF EXISTS `item_level_selector_quality_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_level_selector_quality_set` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelMin` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelMax` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_limit_category`
--

DROP TABLE IF EXISTS `item_limit_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_limit_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Quantity` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_limit_category_locale`
--

DROP TABLE IF EXISTS `item_limit_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_limit_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_modified_appearance`
--

DROP TABLE IF EXISTS `item_modified_appearance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_modified_appearance` (
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AppearanceModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AppearanceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Index` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SourceType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_price_base`
--

DROP TABLE IF EXISTS `item_price_base`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_price_base` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArmorFactor` float NOT NULL DEFAULT '0',
  `WeaponFactor` float NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_random_properties`
--

DROP TABLE IF EXISTS `item_random_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_random_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_random_properties_locale`
--

DROP TABLE IF EXISTS `item_random_properties_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_random_properties_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_random_suffix`
--

DROP TABLE IF EXISTS `item_random_suffix`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_random_suffix` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_random_suffix_locale`
--

DROP TABLE IF EXISTS `item_random_suffix_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_random_suffix_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_search_name`
--

DROP TABLE IF EXISTS `item_search_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_search_name` (
  `AllowableRace` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredExpansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllowableClass` int(11) NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_search_name_locale`
--

DROP TABLE IF EXISTS `item_search_name_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_search_name_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_set`
--

DROP TABLE IF EXISTS `item_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_set` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `ItemID1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID4` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID5` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID6` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID7` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID8` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID9` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID10` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID11` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID12` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID13` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID14` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID15` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID16` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID17` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_set_locale`
--

DROP TABLE IF EXISTS `item_set_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_set_spell`
--

DROP TABLE IF EXISTS `item_set_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_set_spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrSpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Threshold` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_sparse`
--

DROP TABLE IF EXISTS `item_sparse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_sparse` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllowableRace` bigint(20) NOT NULL DEFAULT '0',
  `Name` text,
  `Name2` text,
  `Name3` text,
  `Name4` text,
  `Description` text,
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags4` int(10) unsigned NOT NULL DEFAULT '0',
  `Unk1` float NOT NULL DEFAULT '0',
  `Unk2` float NOT NULL DEFAULT '0',
  `BuyCount` int(10) unsigned NOT NULL DEFAULT '0',
  `BuyPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `SellPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxCount` int(10) unsigned NOT NULL DEFAULT '0',
  `Stackable` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemStatAllocation1` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation2` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation3` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation4` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation5` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation6` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation7` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation8` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation9` int(11) NOT NULL DEFAULT '0',
  `ItemStatAllocation10` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier1` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier2` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier3` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier4` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier5` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier6` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier7` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier8` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier9` float NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier10` float NOT NULL DEFAULT '0',
  `RangedModRange` float NOT NULL DEFAULT '0',
  `BagFamily` int(10) unsigned NOT NULL DEFAULT '0',
  `ArmorDamageModifier` float NOT NULL DEFAULT '0',
  `Duration` int(10) unsigned NOT NULL DEFAULT '0',
  `StatScalingFactor` float NOT NULL DEFAULT '0',
  `AllowableClass` smallint(6) NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemStatValue1` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue2` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue3` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue4` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue5` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue6` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue7` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue8` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue9` smallint(6) NOT NULL DEFAULT '0',
  `ItemStatValue10` smallint(6) NOT NULL DEFAULT '0',
  `ScalingStatDistribution` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Delay` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PageText` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StartQuest` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LockID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RandomProperty` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RandomSuffix` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemSet` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Area` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Map` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TotemCategory` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SocketBonus` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GemProperties` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLimitCategory` smallint(5) unsigned NOT NULL DEFAULT '0',
  `HolidayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredTransmogHolidayID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InventoryType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(4) NOT NULL DEFAULT '0',
  `RequiredHonorRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredCityRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ContainerSlots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemStatType1` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType2` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType3` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType4` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType5` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType6` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType7` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType8` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType9` tinyint(4) NOT NULL DEFAULT '0',
  `ItemStatType10` tinyint(4) NOT NULL DEFAULT '0',
  `DamageType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Bonding` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PageMaterial` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Material` tinyint(4) NOT NULL DEFAULT '0',
  `Sheath` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketColor1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketColor2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SocketColor3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CurrencySubstitutionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CurrencySubstitutionCount` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredExpansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_sparse_locale`
--

DROP TABLE IF EXISTS `item_sparse_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_sparse_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name2_lang` text,
  `Name3_lang` text,
  `Name4_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_spec`
--

DROP TABLE IF EXISTS `item_spec`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_spec` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PrimaryStat` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SecondaryStat` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_spec_override`
--

DROP TABLE IF EXISTS `item_spec_override`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_spec_override` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_upgrade`
--

DROP TABLE IF EXISTS `item_upgrade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_upgrade` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCost` int(10) unsigned NOT NULL DEFAULT '0',
  `PrevItemUpgradeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemUpgradePathID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemLevelBonus` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_x_bonus_tree`
--

DROP TABLE IF EXISTS `item_x_bonus_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_x_bonus_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusTreeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `keychain`
--

DROP TABLE IF EXISTS `keychain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `keychain` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Key1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key9` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key10` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key11` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key12` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key13` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key14` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key15` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key16` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key17` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key18` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key19` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key20` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key21` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key22` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key23` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key24` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key25` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key26` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key27` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key28` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key29` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key30` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key31` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key32` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `lfg_dungeons`
--

DROP TABLE IF EXISTS `lfg_dungeons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `lfg_dungeons` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` float NOT NULL DEFAULT '0',
  `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TargetLevelMax` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `RandomID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LastBossJournalEncounterID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusReputationAmount` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MentorItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetLevelMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Faction` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GroupID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountTank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountTank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SubType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MentorCharLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int(11) NOT NULL DEFAULT '0',
  `RewardIconFileDataID` int(11) NOT NULL DEFAULT '0',
  `ProposalTextureFileDataID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `lfg_dungeons_locale`
--

DROP TABLE IF EXISTS `lfg_dungeons_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `lfg_dungeons_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `light`
--

DROP TABLE IF EXISTS `light`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `light` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `FalloffStart` float NOT NULL DEFAULT '0',
  `FalloffEnd` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `liquid_type`
--

DROP TABLE IF EXISTS `liquid_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `liquid_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Texture1` text,
  `Texture2` text,
  `Texture3` text,
  `Texture4` text,
  `Texture5` text,
  `Texture6` text,
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxDarkenDepth` float NOT NULL DEFAULT '0',
  `FogDarkenIntensity` float NOT NULL DEFAULT '0',
  `AmbDarkenIntensity` float NOT NULL DEFAULT '0',
  `DirDarkenIntensity` float NOT NULL DEFAULT '0',
  `ParticleScale` float NOT NULL DEFAULT '0',
  `Color1` int(10) unsigned NOT NULL DEFAULT '0',
  `Color2` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Int1` int(10) unsigned NOT NULL DEFAULT '0',
  `Int2` int(10) unsigned NOT NULL DEFAULT '0',
  `Int3` int(10) unsigned NOT NULL DEFAULT '0',
  `Int4` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParticleMovement` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParticleTexSlots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaterialID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `liquid_type_locale`
--

DROP TABLE IF EXISTS `liquid_type_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `liquid_type_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `lock`
--

DROP TABLE IF EXISTS `lock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `lock` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Index1` int(10) unsigned NOT NULL DEFAULT '0',
  `Index2` int(10) unsigned NOT NULL DEFAULT '0',
  `Index3` int(10) unsigned NOT NULL DEFAULT '0',
  `Index4` int(10) unsigned NOT NULL DEFAULT '0',
  `Index5` int(10) unsigned NOT NULL DEFAULT '0',
  `Index6` int(10) unsigned NOT NULL DEFAULT '0',
  `Index7` int(10) unsigned NOT NULL DEFAULT '0',
  `Index8` int(10) unsigned NOT NULL DEFAULT '0',
  `Skill1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mail_template`
--

DROP TABLE IF EXISTS `mail_template`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mail_template` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Body` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mail_template_locale`
--

DROP TABLE IF EXISTS `mail_template_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mail_template_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Body_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `map`
--

DROP TABLE IF EXISTS `map`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `map` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Directory` text,
  `MapName` text,
  `MapDescription0` text,
  `MapDescription1` text,
  `ShortDescription` text,
  `LongDescription` text,
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `MinimapIconScale` float NOT NULL DEFAULT '0',
  `CorpsePosX` float NOT NULL DEFAULT '0',
  `CorpsePosY` float NOT NULL DEFAULT '0',
  `AreaTableID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LoadingScreenID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CorpseMapID` smallint(6) NOT NULL DEFAULT '0',
  `TimeOfDayOverride` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentMapID` smallint(6) NOT NULL DEFAULT '0',
  `CosmeticParentMapID` smallint(6) NOT NULL DEFAULT '0',
  `WindSettingsID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `InstanceType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `unk5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TimeOffset` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `map_difficulty`
--

DROP TABLE IF EXISTS `map_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `map_difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Message` text,
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RaidDurationType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LockID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemBonusTreeModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Context` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `map_difficulty_locale`
--

DROP TABLE IF EXISTS `map_difficulty_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `map_difficulty_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Message_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `map_locale`
--

DROP TABLE IF EXISTS `map_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `map_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `MapName_lang` text,
  `MapDescription0_lang` text,
  `MapDescription1_lang` text,
  `ShortDescription_lang` text,
  `LongDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `modifier_tree`
--

DROP TABLE IF EXISTS `modifier_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `modifier_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Asset1` int(10) unsigned NOT NULL DEFAULT '0',
  `Asset2` int(10) unsigned NOT NULL DEFAULT '0',
  `Parent` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk700` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Amount` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount`
--

DROP TABLE IF EXISTS `mount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount` (
  `Name` text,
  `Description` text,
  `SourceDescription` text,
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `CameraPivotMultiplier` float NOT NULL DEFAULT '0',
  `MountTypeId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Source` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionId` int(10) unsigned NOT NULL DEFAULT '0',
  `UiModelSceneID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount_capability`
--

DROP TABLE IF EXISTS `mount_capability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount_capability` (
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `SpeedModSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredRidingSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredArea` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredMap` smallint(6) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount_locale`
--

DROP TABLE IF EXISTS `mount_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `SourceDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount_type_x_capability`
--

DROP TABLE IF EXISTS `mount_type_x_capability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount_type_x_capability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MountTypeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MountCapabilityID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount_x_display`
--

DROP TABLE IF EXISTS `mount_x_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount_x_display` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `MountID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `movie`
--

DROP TABLE IF EXISTS `movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AudioFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SubtitleFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Volume` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `KeyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `name_gen`
--

DROP TABLE IF EXISTS `name_gen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `name_gen` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Sex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `name_gen_locale`
--

DROP TABLE IF EXISTS `name_gen_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `name_gen_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `names_profanity`
--

DROP TABLE IF EXISTS `names_profanity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `names_profanity` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Language` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `names_reserved`
--

DROP TABLE IF EXISTS `names_reserved`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `names_reserved` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `names_reserved_locale`
--

DROP TABLE IF EXISTS `names_reserved_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `names_reserved_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `LocaleMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `override_spell_data`
--

DROP TABLE IF EXISTS `override_spell_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `override_spell_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID3` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID4` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID5` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID6` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID7` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID8` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID9` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID10` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerActionbarFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `phase`
--

DROP TABLE IF EXISTS `phase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phase` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `phase_x_phase_group`
--

DROP TABLE IF EXISTS `phase_x_phase_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phase_x_phase_group` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `player_condition`
--

DROP TABLE IF EXISTS `player_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `player_condition` (
  `RaceMask` bigint(20) NOT NULL DEFAULT '0',
  `FailureDescription` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `Gender` tinyint(4) NOT NULL DEFAULT '0',
  `NativeGender` tinyint(4) NOT NULL DEFAULT '0',
  `SkillLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLanguage` int(11) NOT NULL DEFAULT '0',
  `MaxFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxReputation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ReputationLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `Unknown1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PvpMedal` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PrevQuestLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrQuestLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AuraSpellLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `WorldStateExpressionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `WeatherID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PartyStatus` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LifetimeMaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AchievementLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `LfgLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `QuestKillLogic` int(10) unsigned NOT NULL DEFAULT '0',
  `MinExpansionLevel` tinyint(4) NOT NULL DEFAULT '0',
  `MaxExpansionLevel` tinyint(4) NOT NULL DEFAULT '0',
  `MinExpansionTier` tinyint(4) NOT NULL DEFAULT '0',
  `MaxExpansionTier` tinyint(4) NOT NULL DEFAULT '0',
  `MinGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinAvgItemLevel` int(11) NOT NULL DEFAULT '0',
  `MaxAvgItemLevel` int(11) NOT NULL DEFAULT '0',
  `MinAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationIndex` tinyint(4) NOT NULL DEFAULT '0',
  `ChrSpecializationRole` tinyint(4) NOT NULL DEFAULT '0',
  `PowerType` tinyint(4) NOT NULL DEFAULT '0',
  `PowerTypeComp` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PowerTypeValue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ModifierTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `MainHandItemSubclassMask` int(11) NOT NULL DEFAULT '0',
  `SkillID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SkillID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SkillID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SkillID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinSkill1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinSkill2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinSkill3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinSkill4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxSkill1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxSkill2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxSkill3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxSkill4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinFactionID1` int(10) unsigned NOT NULL DEFAULT '0',
  `MinFactionID2` int(10) unsigned NOT NULL DEFAULT '0',
  `MinFactionID3` int(10) unsigned NOT NULL DEFAULT '0',
  `MinReputation1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinReputation2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinReputation3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PrevQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PrevQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PrevQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PrevQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrentCompletedQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpellID1` int(11) NOT NULL DEFAULT '0',
  `SpellID2` int(11) NOT NULL DEFAULT '0',
  `SpellID3` int(11) NOT NULL DEFAULT '0',
  `SpellID4` int(11) NOT NULL DEFAULT '0',
  `ItemID1` int(11) NOT NULL DEFAULT '0',
  `ItemID2` int(11) NOT NULL DEFAULT '0',
  `ItemID3` int(11) NOT NULL DEFAULT '0',
  `ItemID4` int(11) NOT NULL DEFAULT '0',
  `ItemCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `Explored1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Explored2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Time1` int(10) unsigned NOT NULL DEFAULT '0',
  `Time2` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraSpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraSpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraSpellID3` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraSpellID4` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraCount1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AuraCount2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AuraCount3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AuraCount4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Achievement1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Achievement2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Achievement3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Achievement4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LfgStatus1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgStatus2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgStatus3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgStatus4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgCompare1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgCompare2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgCompare3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgCompare4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LfgValue1` int(10) unsigned NOT NULL DEFAULT '0',
  `LfgValue2` int(10) unsigned NOT NULL DEFAULT '0',
  `LfgValue3` int(10) unsigned NOT NULL DEFAULT '0',
  `LfgValue4` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrencyID1` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyID2` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyID3` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyID4` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster1` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster2` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster3` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster4` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster5` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestKillMonster6` int(10) unsigned NOT NULL DEFAULT '0',
  `MovementFlags1` int(11) NOT NULL DEFAULT '0',
  `MovementFlags2` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `player_condition_locale`
--

DROP TABLE IF EXISTS `player_condition_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `player_condition_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `FailureDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `power_display`
--

DROP TABLE IF EXISTS `power_display`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `power_display` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GlobalStringBaseTag` text,
  `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Red` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Green` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Blue` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `power_type`
--

DROP TABLE IF EXISTS `power_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `power_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerTypeToken` text,
  `PowerCostToken` text,
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `MaxPower` smallint(6) NOT NULL DEFAULT '0',
  `RegenerationDelay` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerTypeEnum` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RegenerationMin` tinyint(4) NOT NULL DEFAULT '0',
  `RegenerationCenter` tinyint(4) NOT NULL DEFAULT '0',
  `RegenerationMax` tinyint(4) NOT NULL DEFAULT '0',
  `UIModifier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `prestige_level_info`
--

DROP TABLE IF EXISTS `prestige_level_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `prestige_level_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PrestigeText` text,
  `IconID` int(10) unsigned NOT NULL DEFAULT '0',
  `PrestigeLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `prestige_level_info_locale`
--

DROP TABLE IF EXISTS `prestige_level_info_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `prestige_level_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `PrestigeText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `pvp_difficulty`
--

DROP TABLE IF EXISTS `pvp_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pvp_difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BracketID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `pvp_reward`
--

DROP TABLE IF EXISTS `pvp_reward`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pvp_reward` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HonorLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Prestige` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_faction_reward`
--

DROP TABLE IF EXISTS `quest_faction_reward`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_faction_reward` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestRewFactionValue1` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue2` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue3` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue4` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue5` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue6` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue7` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue8` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue9` smallint(6) NOT NULL DEFAULT '0',
  `QuestRewFactionValue10` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_money_reward`
--

DROP TABLE IF EXISTS `quest_money_reward`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_money_reward` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Money1` int(10) unsigned NOT NULL DEFAULT '0',
  `Money2` int(10) unsigned NOT NULL DEFAULT '0',
  `Money3` int(10) unsigned NOT NULL DEFAULT '0',
  `Money4` int(10) unsigned NOT NULL DEFAULT '0',
  `Money5` int(10) unsigned NOT NULL DEFAULT '0',
  `Money6` int(10) unsigned NOT NULL DEFAULT '0',
  `Money7` int(10) unsigned NOT NULL DEFAULT '0',
  `Money8` int(10) unsigned NOT NULL DEFAULT '0',
  `Money9` int(10) unsigned NOT NULL DEFAULT '0',
  `Money10` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_package_item`
--

DROP TABLE IF EXISTS `quest_package_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_package_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestPackageID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FilterType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemCount` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_sort`
--

DROP TABLE IF EXISTS `quest_sort`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_sort` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SortName` text,
  `SortOrder` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_sort_locale`
--

DROP TABLE IF EXISTS `quest_sort_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_sort_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SortName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_v2`
--

DROP TABLE IF EXISTS `quest_v2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_v2` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UniqueBitFlag` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `quest_xp`
--

DROP TABLE IF EXISTS `quest_xp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quest_xp` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp9` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Exp10` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `rand_prop_points`
--

DROP TABLE IF EXISTS `rand_prop_points`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rand_prop_points` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `EpicPropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0',
  `EpicPropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0',
  `EpicPropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0',
  `EpicPropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0',
  `EpicPropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0',
  `RarePropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0',
  `RarePropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0',
  `RarePropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0',
  `RarePropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0',
  `RarePropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0',
  `UncommonPropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0',
  `UncommonPropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0',
  `UncommonPropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0',
  `UncommonPropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0',
  `UncommonPropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `reward_pack`
--

DROP TABLE IF EXISTS `reward_pack`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reward_pack` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Money` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactXPMultiplier` float NOT NULL DEFAULT '0',
  `ArtifactXPDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TitleID` int(10) unsigned NOT NULL DEFAULT '0',
  `Unused` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `reward_pack_x_item`
--

DROP TABLE IF EXISTS `reward_pack_x_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reward_pack_x_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `Amount` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ruleset_item_upgrade`
--

DROP TABLE IF EXISTS `ruleset_item_upgrade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ruleset_item_upgrade` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemUpgradeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sandbox_scaling`
--

DROP TABLE IF EXISTS `sandbox_scaling`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sandbox_scaling` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scenario`
--

DROP TABLE IF EXISTS `scenario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scenario` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Data` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scenario_locale`
--

DROP TABLE IF EXISTS `scenario_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scenario_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scenario_step`
--

DROP TABLE IF EXISTS `scenario_step`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scenario_step` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Name` text,
  `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PreviousStepID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `QuestRewardID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Step` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CriteriaTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusRequiredStepID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scenario_step_locale`
--

DROP TABLE IF EXISTS `scenario_step_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scenario_step_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scene_script`
--

DROP TABLE IF EXISTS `scene_script`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scene_script` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PrevScriptId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NextScriptId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scene_script_global_text`
--

DROP TABLE IF EXISTS `scene_script_global_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scene_script_global_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scene_script_package`
--

DROP TABLE IF EXISTS `scene_script_package`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scene_script_package` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `scene_script_text`
--

DROP TABLE IF EXISTS `scene_script_text`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scene_script_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `skill_line`
--

DROP TABLE IF EXISTS `skill_line`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `skill_line` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `Description` text,
  `AlternateVerb` text,
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CanLink` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParentSkillLineID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `skill_line_ability`
--

DROP TABLE IF EXISTS `skill_line_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `skill_line_ability` (
  `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SupercedesSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `SkillLine` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TrivialSkillLineRankHigh` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TrivialSkillLineRankLow` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UniqueBit` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TradeSkillCategoryID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NumSkillUps` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `MinSkillLineRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AcquireMethod` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `skill_line_locale`
--

DROP TABLE IF EXISTS `skill_line_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `skill_line_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `Description_lang` text,
  `AlternateVerb_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `skill_race_class_info`
--

DROP TABLE IF EXISTS `skill_race_class_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `skill_race_class_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceMask` bigint(20) NOT NULL DEFAULT '0',
  `SkillID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SkillTierID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Availability` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sound_kit`
--

DROP TABLE IF EXISTS `sound_kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sound_kit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VolumeFloat` float NOT NULL DEFAULT '0',
  `MinDistance` float NOT NULL DEFAULT '0',
  `DistanceCutoff` float NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SoundEntriesAdvancedID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SoundType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DialogType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EAXDef` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VolumeVariationPlus` float NOT NULL DEFAULT '0',
  `VolumeVariationMinus` float NOT NULL DEFAULT '0',
  `PitchVariationPlus` float NOT NULL DEFAULT '0',
  `PitchVariationMinus` float NOT NULL DEFAULT '0',
  `PitchAdjust` float NOT NULL DEFAULT '0',
  `BusOverwriteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Unk700` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `specialization_spells`
--

DROP TABLE IF EXISTS `specialization_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `specialization_spells` (
  `Description` text,
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `specialization_spells_locale`
--

DROP TABLE IF EXISTS `specialization_spells_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `specialization_spells_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell`
--

DROP TABLE IF EXISTS `spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `NameSubtext` text,
  `Description` text,
  `AuraDescription` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_aura_options`
--

DROP TABLE IF EXISTS `spell_aura_options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_aura_options` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcCharges` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcTypeMask` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcCategoryRecovery` int(10) unsigned NOT NULL DEFAULT '0',
  `CumulativeAura` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ProcChance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_aura_restrictions`
--

DROP TABLE IF EXISTS `spell_aura_restrictions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_aura_restrictions` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CasterAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeCasterAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeTargetAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CasterAuraState` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetAuraState` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ExcludeCasterAuraState` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ExcludeTargetAuraState` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_cast_times`
--

DROP TABLE IF EXISTS `spell_cast_times`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_cast_times` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CastTime` int(11) NOT NULL DEFAULT '0',
  `MinCastTime` int(11) NOT NULL DEFAULT '0',
  `CastTimePerLevel` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_casting_requirements`
--

DROP TABLE IF EXISTS `spell_casting_requirements`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_casting_requirements` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredAreasID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiresSpellFocus` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FacingCasterFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinReputation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredAuraVision` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_categories`
--

DROP TABLE IF EXISTS `spell_categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_categories` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Category` smallint(5) unsigned NOT NULL DEFAULT '0',
  `StartRecoveryCategory` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ChargeCategory` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DefenseType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DispelType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Mechanic` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PreventionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_category`
--

DROP TABLE IF EXISTS `spell_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `ChargeRecoveryTime` int(11) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UsesPerWeek` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxCharges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ChargeCategoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_category_locale`
--

DROP TABLE IF EXISTS `spell_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_class_options`
--

DROP TABLE IF EXISTS `spell_class_options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_class_options` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask3` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask4` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ModalNextSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_cooldowns`
--

DROP TABLE IF EXISTS `spell_cooldowns`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_cooldowns` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryRecoveryTime` int(10) unsigned NOT NULL DEFAULT '0',
  `RecoveryTime` int(10) unsigned NOT NULL DEFAULT '0',
  `StartRecoveryTime` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_duration`
--

DROP TABLE IF EXISTS `spell_duration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_duration` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration` int(11) NOT NULL DEFAULT '0',
  `MaxDuration` int(11) NOT NULL DEFAULT '0',
  `DurationPerLevel` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_effect`
--

DROP TABLE IF EXISTS `spell_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_effect` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Effect` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectBasePoints` int(11) NOT NULL DEFAULT '0',
  `EffectIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectAura` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectAmplitude` float NOT NULL DEFAULT '0',
  `EffectAuraPeriod` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectBonusCoefficient` float NOT NULL DEFAULT '0',
  `EffectChainAmplitude` float NOT NULL DEFAULT '0',
  `EffectChainTargets` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectDieSides` int(11) NOT NULL DEFAULT '0',
  `EffectItemType` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectMechanic` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectPointsPerResource` float NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel` float NOT NULL DEFAULT '0',
  `EffectTriggerSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectPosFacing` float NOT NULL DEFAULT '0',
  `EffectAttributes` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusCoefficientFromAP` float NOT NULL DEFAULT '0',
  `PvPMultiplier` float NOT NULL DEFAULT '0',
  `Coefficient` float NOT NULL DEFAULT '0',
  `Variance` float NOT NULL DEFAULT '0',
  `ResourceCoefficient` float NOT NULL DEFAULT '0',
  `GroupSizeCoefficient` float NOT NULL DEFAULT '0',
  `EffectSpellClassMask1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMask2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMask3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMask4` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectMiscValue` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValueB` int(11) NOT NULL DEFAULT '0',
  `EffectRadiusIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectRadiusMaxIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `ImplicitTarget1` int(10) unsigned NOT NULL DEFAULT '0',
  `ImplicitTarget2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_equipped_items`
--

DROP TABLE IF EXISTS `spell_equipped_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_equipped_items` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `EquippedItemInventoryTypeMask` int(11) NOT NULL DEFAULT '0',
  `EquippedItemSubClassMask` int(11) NOT NULL DEFAULT '0',
  `EquippedItemClass` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_focus_object`
--

DROP TABLE IF EXISTS `spell_focus_object`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_focus_object` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_focus_object_locale`
--

DROP TABLE IF EXISTS `spell_focus_object_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_focus_object_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_interrupts`
--

DROP TABLE IF EXISTS `spell_interrupts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_interrupts` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `InterruptFlags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AuraInterruptFlags1` int(10) unsigned NOT NULL DEFAULT '0',
  `AuraInterruptFlags2` int(10) unsigned NOT NULL DEFAULT '0',
  `ChannelInterruptFlags1` int(10) unsigned NOT NULL DEFAULT '0',
  `ChannelInterruptFlags2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_item_enchantment`
--

DROP TABLE IF EXISTS `spell_item_enchantment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_item_enchantment` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `EffectSpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellID3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectScalingPoints1` float NOT NULL DEFAULT '0',
  `EffectScalingPoints2` float NOT NULL DEFAULT '0',
  `EffectScalingPoints3` float NOT NULL DEFAULT '0',
  `TransmogCost` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemVisual` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Charges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ConditionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ScalingClass` tinyint(4) NOT NULL DEFAULT '0',
  `ScalingClassRestricted` tinyint(4) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_item_enchantment_condition`
--

DROP TABLE IF EXISTS `spell_item_enchantment_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_item_enchantment_condition` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand1` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand2` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand3` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand4` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand5` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_item_enchantment_locale`
--

DROP TABLE IF EXISTS `spell_item_enchantment_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_item_enchantment_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_learn_spell`
--

DROP TABLE IF EXISTS `spell_learn_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_learn_spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LearnSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_levels`
--

DROP TABLE IF EXISTS `spell_levels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_levels` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpellLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxUsableLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_locale`
--

DROP TABLE IF EXISTS `spell_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameSubtext_lang` text,
  `Description_lang` text,
  `AuraDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_misc`
--

DROP TABLE IF EXISTS `spell_misc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_misc` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CastingTimeIndex` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DurationIndex` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RangeIndex` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SchoolMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Speed` float NOT NULL DEFAULT '0',
  `ActiveIconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `MultistrikeSpeedMod` float NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Attributes` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExB` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExC` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExD` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExE` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExF` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExG` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExH` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExI` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExJ` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExK` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExL` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesExM` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_power`
--

DROP TABLE IF EXISTS `spell_power`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_power` (
  `ManaCost` int(11) NOT NULL DEFAULT '0',
  `ManaCostPercentage` float NOT NULL DEFAULT '0',
  `ManaCostPercentagePerSecond` float NOT NULL DEFAULT '0',
  `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0',
  `HealthCostPercentage` float NOT NULL DEFAULT '0',
  `PowerIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCostPerLevel` int(11) NOT NULL DEFAULT '0',
  `ManaCostPerSecond` int(11) NOT NULL DEFAULT '0',
  `ManaCostAdditional` int(11) NOT NULL DEFAULT '0',
  `PowerDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `UnitPowerBarID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_power_difficulty`
--

DROP TABLE IF EXISTS `spell_power_difficulty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_power_difficulty` (
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PowerIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_procs_per_minute`
--

DROP TABLE IF EXISTS `spell_procs_per_minute`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_procs_per_minute` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseProcRate` float NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_procs_per_minute_mod`
--

DROP TABLE IF EXISTS `spell_procs_per_minute_mod`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_procs_per_minute_mod` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Coeff` float NOT NULL DEFAULT '0',
  `Param` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellProcsPerMinuteID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_radius`
--

DROP TABLE IF EXISTS `spell_radius`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_radius` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `RadiusPerLevel` float NOT NULL DEFAULT '0',
  `RadiusMin` float NOT NULL DEFAULT '0',
  `RadiusMax` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_range`
--

DROP TABLE IF EXISTS `spell_range`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_range` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `DisplayNameShort` text,
  `MinRangeHostile` float NOT NULL DEFAULT '0',
  `MinRangeFriend` float NOT NULL DEFAULT '0',
  `MaxRangeHostile` float NOT NULL DEFAULT '0',
  `MaxRangeFriend` float NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_range_locale`
--

DROP TABLE IF EXISTS `spell_range_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_range_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `DisplayNameShort_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_reagents`
--

DROP TABLE IF EXISTS `spell_reagents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_reagents` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Reagent1` int(11) NOT NULL DEFAULT '0',
  `Reagent2` int(11) NOT NULL DEFAULT '0',
  `Reagent3` int(11) NOT NULL DEFAULT '0',
  `Reagent4` int(11) NOT NULL DEFAULT '0',
  `Reagent5` int(11) NOT NULL DEFAULT '0',
  `Reagent6` int(11) NOT NULL DEFAULT '0',
  `Reagent7` int(11) NOT NULL DEFAULT '0',
  `Reagent8` int(11) NOT NULL DEFAULT '0',
  `ReagentCount1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReagentCount8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_scaling`
--

DROP TABLE IF EXISTS `spell_scaling`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_scaling` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `ScalesFromItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ScalingClass` int(11) NOT NULL DEFAULT '0',
  `MinScalingLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxScalingLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_shapeshift`
--

DROP TABLE IF EXISTS `spell_shapeshift`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_shapeshift` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `ShapeshiftExclude1` int(10) unsigned NOT NULL DEFAULT '0',
  `ShapeshiftExclude2` int(10) unsigned NOT NULL DEFAULT '0',
  `ShapeshiftMask1` int(10) unsigned NOT NULL DEFAULT '0',
  `ShapeshiftMask2` int(10) unsigned NOT NULL DEFAULT '0',
  `StanceBarOrder` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_shapeshift_form`
--

DROP TABLE IF EXISTS `spell_shapeshift_form`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_shapeshift_form` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `WeaponDamageVariance` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `CombatRoundTime` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MountTypeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CreatureType` tinyint(4) NOT NULL DEFAULT '0',
  `BonusActionBar` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttackIconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID1` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID2` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID3` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID4` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID3` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID4` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID5` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID6` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID7` int(10) unsigned NOT NULL DEFAULT '0',
  `PresetSpellID8` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_shapeshift_form_locale`
--

DROP TABLE IF EXISTS `spell_shapeshift_form_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_shapeshift_form_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_target_restrictions`
--

DROP TABLE IF EXISTS `spell_target_restrictions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_target_restrictions` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ConeAngle` float NOT NULL DEFAULT '0',
  `Width` float NOT NULL DEFAULT '0',
  `Targets` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetCreatureType` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxAffectedTargets` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxTargetLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_totems`
--

DROP TABLE IF EXISTS `spell_totems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_totems` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Totem1` int(10) unsigned NOT NULL DEFAULT '0',
  `Totem2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_x_spell_visual`
--

DROP TABLE IF EXISTS `spell_x_spell_visual`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_x_spell_visual` (
  `SpellVisualID` int(10) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Chance` float NOT NULL DEFAULT '0',
  `CasterPlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CasterUnitConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UnitConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `ActiveIconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Priority` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `summon_properties`
--

DROP TABLE IF EXISTS `summon_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `summon_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Category` int(10) unsigned NOT NULL DEFAULT '0',
  `Faction` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `Slot` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `tact_key`
--

DROP TABLE IF EXISTS `tact_key`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tact_key` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Key1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key9` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key10` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key11` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key12` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key13` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key14` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key15` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key16` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `talent`
--

DROP TABLE IF EXISTS `talent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `talent` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TierID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ColumnIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CategoryMask1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CategoryMask2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `talent_locale`
--

DROP TABLE IF EXISTS `talent_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `talent_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `taxi_nodes`
--

DROP TABLE IF EXISTS `taxi_nodes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxi_nodes` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `MountCreatureID1` int(10) unsigned NOT NULL DEFAULT '0',
  `MountCreatureID2` int(10) unsigned NOT NULL DEFAULT '0',
  `MapOffsetX` float NOT NULL DEFAULT '0',
  `MapOffsetY` float NOT NULL DEFAULT '0',
  `Unk730` float NOT NULL DEFAULT '0',
  `FlightMapOffsetX` float NOT NULL DEFAULT '0',
  `FlightMapOffsetY` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LearnableIndex` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UiTextureKitPrefixID` int(11) NOT NULL DEFAULT '0',
  `SpecialAtlasIconPlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `taxi_nodes_locale`
--

DROP TABLE IF EXISTS `taxi_nodes_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxi_nodes_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `taxi_path`
--

DROP TABLE IF EXISTS `taxi_path`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxi_path` (
  `From` smallint(5) unsigned NOT NULL DEFAULT '0',
  `To` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Cost` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `taxi_path_node`
--

DROP TABLE IF EXISTS `taxi_path_node`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxi_path_node` (
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `PathID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NodeIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Delay` int(10) unsigned NOT NULL DEFAULT '0',
  `ArrivalEventID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DepartureEventID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `totem_category`
--

DROP TABLE IF EXISTS `totem_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `totem_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `CategoryMask` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `totem_category_locale`
--

DROP TABLE IF EXISTS `totem_category_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `totem_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `toy`
--

DROP TABLE IF EXISTS `toy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toy` (
  `Description` text,
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CategoryFilter` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `toy_locale`
--

DROP TABLE IF EXISTS `toy_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toy_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_holiday`
--

DROP TABLE IF EXISTS `transmog_holiday`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_holiday` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_set`
--

DROP TABLE IF EXISTS `transmog_set`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_set` (
  `Name` text,
  `BaseSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UIOrder` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `QuestID` int(11) NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` int(11) NOT NULL DEFAULT '0',
  `TransmogSetGroupID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_set_group`
--

DROP TABLE IF EXISTS `transmog_set_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_set_group` (
  `Label` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_set_group_locale`
--

DROP TABLE IF EXISTS `transmog_set_group_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_set_group_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Label_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_set_item`
--

DROP TABLE IF EXISTS `transmog_set_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_set_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransmogSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transmog_set_locale`
--

DROP TABLE IF EXISTS `transmog_set_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transmog_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transport_animation`
--

DROP TABLE IF EXISTS `transport_animation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transport_animation` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `SequenceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `transport_rotation`
--

DROP TABLE IF EXISTS `transport_rotation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transport_rotation` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
  `Z` float NOT NULL DEFAULT '0',
  `W` float NOT NULL DEFAULT '0',
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `unit_power_bar`
--

DROP TABLE IF EXISTS `unit_power_bar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `unit_power_bar` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Cost` text,
  `OutOfError` text,
  `ToolTip` text,
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `FileDataID1` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID2` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID3` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID4` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID5` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID6` int(10) unsigned NOT NULL DEFAULT '0',
  `Color1` int(10) unsigned NOT NULL DEFAULT '0',
  `Color2` int(10) unsigned NOT NULL DEFAULT '0',
  `Color3` int(10) unsigned NOT NULL DEFAULT '0',
  `Color4` int(10) unsigned NOT NULL DEFAULT '0',
  `Color5` int(10) unsigned NOT NULL DEFAULT '0',
  `Color6` int(10) unsigned NOT NULL DEFAULT '0',
  `StartInset` float NOT NULL DEFAULT '0',
  `EndInset` float NOT NULL DEFAULT '0',
  `StartPower` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CenterPower` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BarType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinPower` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxPower` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `unit_power_bar_locale`
--

DROP TABLE IF EXISTS `unit_power_bar_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `unit_power_bar_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Cost_lang` text,
  `OutOfError_lang` text,
  `ToolTip_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates`
--

DROP TABLE IF EXISTS `updates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `updates` (
  `name` varchar(200) NOT NULL COMMENT 'filename with extension of the update.',
  `hash` char(40) DEFAULT '' COMMENT 'sha1 hash of the sql file.',
  `state` enum('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
  `speed` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'time the query takes to apply in ms.',
  PRIMARY KEY (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='List of all applied updates in this database.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates_include`
--

DROP TABLE IF EXISTS `updates_include`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `updates_include` (
  `path` varchar(200) NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
  `state` enum('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
  PRIMARY KEY (`path`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='List of directories where we want to include sql updates.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `vehicle`
--

DROP TABLE IF EXISTS `vehicle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vehicle` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
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
  `SeatID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleUIIndicatorID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FlagsB` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UILocomotionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MissileTargetingID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `vehicle_seat`
--

DROP TABLE IF EXISTS `vehicle_seat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vehicle_seat` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `AttachmentOffsetX` float NOT NULL DEFAULT '0',
  `AttachmentOffsetY` float NOT NULL DEFAULT '0',
  `AttachmentOffsetZ` float NOT NULL DEFAULT '0',
  `EnterPreDelay` float NOT NULL DEFAULT '0',
  `EnterSpeed` float NOT NULL DEFAULT '0',
  `EnterGravity` float NOT NULL DEFAULT '0',
  `EnterMinDuration` float NOT NULL DEFAULT '0',
  `EnterMaxDuration` float NOT NULL DEFAULT '0',
  `EnterMinArcHeight` float NOT NULL DEFAULT '0',
  `EnterMaxArcHeight` float NOT NULL DEFAULT '0',
  `ExitPreDelay` float NOT NULL DEFAULT '0',
  `ExitSpeed` float NOT NULL DEFAULT '0',
  `ExitGravity` float NOT NULL DEFAULT '0',
  `ExitMinDuration` float NOT NULL DEFAULT '0',
  `ExitMaxDuration` float NOT NULL DEFAULT '0',
  `ExitMinArcHeight` float NOT NULL DEFAULT '0',
  `ExitMaxArcHeight` float NOT NULL DEFAULT '0',
  `PassengerYaw` float NOT NULL DEFAULT '0',
  `PassengerPitch` float NOT NULL DEFAULT '0',
  `PassengerRoll` float NOT NULL DEFAULT '0',
  `VehicleEnterAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleExitAnimDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDuration` float NOT NULL DEFAULT '0',
  `CameraExitingDelay` float NOT NULL DEFAULT '0',
  `CameraExitingDuration` float NOT NULL DEFAULT '0',
  `CameraOffsetX` float NOT NULL DEFAULT '0',
  `CameraOffsetY` float NOT NULL DEFAULT '0',
  `CameraOffsetZ` float NOT NULL DEFAULT '0',
  `CameraPosChaseRate` float NOT NULL DEFAULT '0',
  `CameraFacingChaseRate` float NOT NULL DEFAULT '0',
  `CameraEnteringZoom` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMin` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMax` float NOT NULL DEFAULT '0',
  `UISkinFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `EnterAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `EnterAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `RideAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `RideAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `RideUpperAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `RideUpperAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimEnd` smallint(6) NOT NULL DEFAULT '0',
  `VehicleEnterAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleExitAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleRideAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `EnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleEnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleRideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CameraModeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AttachmentID` tinyint(4) NOT NULL DEFAULT '0',
  `PassengerAttachmentID` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleEnterAnimBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleExitAnimBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleRideAnimLoopBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleAbilityDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EnterUISoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ExitUISoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `wmo_area_table`
--

DROP TABLE IF EXISTS `wmo_area_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wmo_area_table` (
  `AreaName` text,
  `WMOGroupID` int(11) NOT NULL DEFAULT '0',
  `AmbienceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ZoneMusic` smallint(5) unsigned NOT NULL DEFAULT '0',
  `IntroSound` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaTableID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UWIntroSound` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UWAmbience` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NameSet` tinyint(4) NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UWZoneMusic` int(10) unsigned NOT NULL DEFAULT '0',
  `WMOID` smallint(6) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `wmo_area_table_locale`
--

DROP TABLE IF EXISTS `wmo_area_table_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wmo_area_table_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_effect`
--

DROP TABLE IF EXISTS `world_effect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_effect` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetAsset` int(10) unsigned NOT NULL DEFAULT '0',
  `CombatConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TargetType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `WhenToDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_map_area`
--

DROP TABLE IF EXISTS `world_map_area`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_map_area` (
  `AreaName` text,
  `LocLeft` float NOT NULL DEFAULT '0',
  `LocRight` float NOT NULL DEFAULT '0',
  `LocTop` float NOT NULL DEFAULT '0',
  `LocBottom` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayMapID` smallint(6) NOT NULL DEFAULT '0',
  `DefaultDungeonFloor` smallint(6) NOT NULL DEFAULT '0',
  `ParentWorldMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LevelRangeMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LevelRangeMax` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BountySetID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BountyBoardLocation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_map_overlay`
--

DROP TABLE IF EXISTS `world_map_overlay`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_map_overlay` (
  `TextureName` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureWidth` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TextureHeight` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MapAreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID3` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID4` int(10) unsigned NOT NULL DEFAULT '0',
  `OffsetX` int(11) NOT NULL DEFAULT '0',
  `OffsetY` int(11) NOT NULL DEFAULT '0',
  `HitRectTop` int(11) NOT NULL DEFAULT '0',
  `HitRectLeft` int(11) NOT NULL DEFAULT '0',
  `HitRectBottom` int(11) NOT NULL DEFAULT '0',
  `HitRectRight` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_map_transforms`
--

DROP TABLE IF EXISTS `world_map_transforms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_map_transforms` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RegionMinX` float NOT NULL DEFAULT '0',
  `RegionMinY` float NOT NULL DEFAULT '0',
  `RegionMinZ` float NOT NULL DEFAULT '0',
  `RegionMaxX` float NOT NULL DEFAULT '0',
  `RegionMaxY` float NOT NULL DEFAULT '0',
  `RegionMaxZ` float NOT NULL DEFAULT '0',
  `RegionOffsetX` float NOT NULL DEFAULT '0',
  `RegionOffsetY` float NOT NULL DEFAULT '0',
  `RegionScale` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NewMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NewDungeonMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NewAreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Priority` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_safe_locs`
--

DROP TABLE IF EXISTS `world_safe_locs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_safe_locs` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaName` text,
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `Facing` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_safe_locs_locale`
--

DROP TABLE IF EXISTS `world_safe_locs_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_safe_locs_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-02-19 22:43:15
