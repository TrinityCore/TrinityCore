-- MySQL dump 10.13  Distrib 5.6.9-rc, for Win64 (x86_64)
--
-- Host: localhost    Database: hotfixes
-- ------------------------------------------------------
-- Server version	5.6.9-rc

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
-- Table structure for table `area_group`
--

DROP TABLE IF EXISTS `area_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_group` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `AreaGroupID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_poi`
--

DROP TABLE IF EXISTS `area_poi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_poi` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Flags` mediumint(8) NOT NULL DEFAULT '0',
  `Importance` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `FactionID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `MapID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `AreaID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Icon` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PositionX` float NOT NULL DEFAULT '0',
  `PositionY` float NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `Description` text NOT NULL,
  `WorldStateID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `WorldMapLink` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PortLocID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `area_poi_state`
--

DROP TABLE IF EXISTS `area_poi_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `area_poi_state` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `AreaPOIID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `State` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Icon` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Description` text NOT NULL,
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
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
  `FactionID` int(10) unsigned NOT NULL DEFAULT '0',
  `DepositRate` int(10) unsigned NOT NULL DEFAULT '0',
  `ConsignmentRate` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
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
-- Table structure for table `barber_shop_style`
--

DROP TABLE IF EXISTS `barber_shop_style`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `barber_shop_style` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `Description` text,
  `CostModifier` float NOT NULL DEFAULT '0',
  `Race` int(10) unsigned NOT NULL DEFAULT '0',
  `Sex` int(10) unsigned NOT NULL DEFAULT '0',
  `Data` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `battle_pet_species`
--

DROP TABLE IF EXISTS `battle_pet_species`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_species` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileID` int(10) unsigned NOT NULL DEFAULT '0',
  `SummonSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `PetType` int(11) NOT NULL DEFAULT '0',
  `Source` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `SourceText` text,
  `Description` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `Language` int(11) NOT NULL DEFAULT '0',
  `MaleText` text,
  `FemaleText` text,
  `EmoteID1` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteID2` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteID3` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay1` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay2` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteDelay3` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `UnkEmoteID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
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
-- Table structure for table `char_start_outfit`
--

DROP TABLE IF EXISTS `char_start_outfit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_start_outfit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GenderID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OutfitID` tinyint(3) unsigned NOT NULL DEFAULT '0',
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
  `PetFamilyID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `ClassID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_upgrade_bucket`
--

DROP TABLE IF EXISTS `chr_upgrade_bucket`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_upgrade_bucket` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TierID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecializationID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_upgrade_bucket_spell`
--

DROP TABLE IF EXISTS `chr_upgrade_bucket_spell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_upgrade_bucket_spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BucketID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `chr_upgrade_tier`
--

DROP TABLE IF EXISTS `chr_upgrade_tier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chr_upgrade_tier` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TierIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `TalentTier` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Camera1` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera2` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera3` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera4` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera5` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera6` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera7` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera8` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Type` mediumint(8) unsigned NOT NULL DEFAULT '0',
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
  `Rank` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `InhabitType` mediumint(8) unsigned NOT NULL DEFAULT '0',
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
  `FactionID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Expansion` mediumint(8) NOT NULL DEFAULT '0',
  `MinLevel` mediumint(8) NOT NULL DEFAULT '0',
  `MaxLevel` mediumint(8) NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags4` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags5` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ModelID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ExtendedDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureModelScale` float NOT NULL DEFAULT '0',
  `Unknown620` float NOT NULL DEFAULT '0',
  `CreatureModelAlpha` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureVariation1` text,
  `TextureVariation2` text,
  `TextureVariation3` text,
  `PortraitTextureName` text,
  `PortraitCreatureDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `SizeClass` int(10) unsigned NOT NULL DEFAULT '0',
  `BloodID` int(10) unsigned NOT NULL DEFAULT '0',
  `NPCSoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParticleColorID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureGeosetData` int(10) unsigned NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Gender` int(11) NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `creature_display_info_locale`
--

DROP TABLE IF EXISTS `creature_display_info_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_display_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `TextureVariation_lang1` text,
  `TextureVariation_lang2` text,
  `TextureVariation_lang3` text,
  `PortraitTextureName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
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
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `currency_types`
--

DROP TABLE IF EXISTS `currency_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currency_types` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `InventoryIcon1` text,
  `InventoryIcon2` text,
  `SpellWeight` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellCategory` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxQty` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxEarnablePerWeek` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
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
  `InventoryIcon1_lang` text,
  `InventoryIcon2_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
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
  `CurveID` int(10) unsigned NOT NULL DEFAULT '0',
  `Index` int(10) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
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
  `StateDamagedDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDestructionDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDestructionDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeInitDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `EjectDirection` int(10) unsigned NOT NULL DEFAULT '0',
  `RepairGroundFx` int(10) unsigned NOT NULL DEFAULT '0',
  `DoNotHighlight` int(10) unsigned NOT NULL DEFAULT '0',
  `HealEffect` int(10) unsigned NOT NULL DEFAULT '0',
  `HealEffectSpeed` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `game_tables`
--

DROP TABLE IF EXISTS `game_tables`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `game_tables` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `NumRows` int(10) unsigned NOT NULL DEFAULT '0',
  `NumColumns` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `game_tables_locale`
--

DROP TABLE IF EXISTS `game_tables_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `game_tables_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text NOT NULL,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `gameobjects`
--

DROP TABLE IF EXISTS `gameobjects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gameobjects` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `MapID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `DisplayID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PositionX` float NOT NULL DEFAULT '0',
  `PositionY` float NOT NULL DEFAULT '0',
  `PositionZ` float NOT NULL DEFAULT '0',
  `RotationX` float NOT NULL DEFAULT '0',
  `RotationY` float NOT NULL DEFAULT '0',
  `RotationZ` float NOT NULL DEFAULT '0',
  `RotationW` float NOT NULL DEFAULT '0',
  `Size` float NOT NULL DEFAULT '0',
  `PhaseUseFlags` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PhaseID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Type` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Data0` int(10) NOT NULL DEFAULT '0',
  `Data1` int(10) NOT NULL DEFAULT '0',
  `Data2` int(10) NOT NULL DEFAULT '0',
  `Data3` int(10) NOT NULL DEFAULT '0',
  `Data4` int(10) NOT NULL DEFAULT '0',
  `Data5` int(10) NOT NULL DEFAULT '0',
  `Data6` int(10) NOT NULL DEFAULT '0',
  `Data7` int(10) NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `OtherFactionGarrAbilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityCategoryID` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerTypeID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `HordeGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `Unknown` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `NameAlliance` text,
  `NameHorde` text,
  `Description` text,
  `Tooltip` text,
  `BuildDuration` int(10) unsigned NOT NULL DEFAULT '0',
  `CostCurrencyID` int(10) unsigned NOT NULL DEFAULT '0',
  `CostCurrencyAmount` int(11) NOT NULL DEFAULT '0',
  `HordeTexPrefixKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceTexPrefixKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusAmount` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceActivationScenePackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeActivationScenePackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxShipments` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerRequiredGarrAbilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerGarrAbilityEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `CostMoney` int(11) NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrBuildingID` int(10) unsigned NOT NULL DEFAULT '0',
  `UiTextureAtlasMemberID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrSiteLevelPlotInstID` int(10) unsigned NOT NULL DEFAULT '0',
  `LandmarkOffsetX` float NOT NULL DEFAULT '0',
  `LandmarkOffsetY` float NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NameMale` text,
  `NameFemale` text,
  `NameGenderless` text,
  `ClassAtlasID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerTypeID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeUiAnimRaceInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceUiAnimRaceInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeGarrClassSpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrClassSpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeGarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelWeapon` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelArmor` int(10) unsigned NOT NULL DEFAULT '0',
  `Unknown1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeSourceText` text,
  `AllianceSourceText` text,
  `Unknown2` int(11) NOT NULL DEFAULT '0',
  `Unknown3` int(11) NOT NULL DEFAULT '0',
  `HordePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `AlliancePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeListPortraitTextureKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceListPortraitTextureKitID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GarrFollowerID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionIndex` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GarrPlotUICategoryID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlotType` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `MinCount` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxCount` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceConstructionGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeConstructionGameObjectID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GarrPlotID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrBuildingID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GarrPlotID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
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
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` int(10) unsigned NOT NULL DEFAULT '0',
  `SiteID` int(10) unsigned NOT NULL DEFAULT '0',
  `UITextureKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `TownHallX` float NOT NULL DEFAULT '0',
  `TownHallY` float NOT NULL DEFAULT '0',
  `MovieID` int(10) unsigned NOT NULL DEFAULT '0',
  `Level2` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeResourceCost` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradeMoneyCost` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GarrSiteLevelID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrPlotInstanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `LandmarkX` float NOT NULL DEFAULT '0',
  `LandmarkY` float NOT NULL DEFAULT '0',
  `Unknown` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glyph_slot`
--

DROP TABLE IF EXISTS `glyph_slot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glyph_slot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `Tooltip` int(10) unsigned NOT NULL DEFAULT '0',
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
  `GuildLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `Duration1` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration2` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration3` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration4` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration5` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration6` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration7` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration8` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration9` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration10` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Region` int(10) unsigned NOT NULL DEFAULT '0',
  `Looping` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags1` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags2` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags3` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags4` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags5` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags6` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags7` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags8` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags9` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFlags10` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayNameID` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayDescriptionID` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFilename` text,
  `Priority` int(10) unsigned NOT NULL DEFAULT '0',
  `CalendarFilterType` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `holidays_locale`
--

DROP TABLE IF EXISTS `holidays_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `holidays_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `TextureFilename_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `hotfix_data`
--

DROP TABLE IF EXISTS `hotfix_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hotfix_data` (
  `TableHash` int(10) unsigned NOT NULL DEFAULT '0',
  `RecordID` int(10) NOT NULL,
  `Timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  `Deleted` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`TableHash`,`RecordID`,`Timestamp`)
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
  `Class` int(10) unsigned NOT NULL DEFAULT '0',
  `SubClass` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclass` int(11) NOT NULL DEFAULT '0',
  `Material` int(11) NOT NULL DEFAULT '0',
  `InventoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `Sheath` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `GroupSoundsID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `BonusListID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `Value1` int(11) NOT NULL DEFAULT '0',
  `Value2` int(11) NOT NULL DEFAULT '0',
  `Index` int(10) unsigned NOT NULL DEFAULT '0',
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
  `BonusTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusTreeModID` int(10) unsigned NOT NULL DEFAULT '0',
  `SubTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusListID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `PriceMod` float NOT NULL DEFAULT '0',
  `Name` text,
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
  PRIMARY KEY (`ID`),
  UNIQUE KEY `idx_itemId` (`ItemId`)
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
  `ItemClass` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemSubClass` int(11) NOT NULL DEFAULT '0',
  `ItemQuality` int(10) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredDisenchantSkill` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Trigger` int(10) unsigned NOT NULL DEFAULT '0',
  `Charges` int(10) unsigned NOT NULL DEFAULT '0',
  `Cooldown` int(11) NOT NULL DEFAULT '0',
  `Category` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryCooldown` int(11) NOT NULL DEFAULT '0',
  `ChrSpecializationID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `RequiredArenaSlot` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItem5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredPersonalArenaRating` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemPurchaseGroup` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount5` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredFactionId` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredFactionStanding` int(10) unsigned NOT NULL DEFAULT '0',
  `RequirementFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAchievement` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredMoney` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Quantity` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `AppearanceModID` int(10) unsigned NOT NULL DEFAULT '0',
  `AppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Index` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ArmorFactor` float NOT NULL DEFAULT '0',
  `WeaponFactor` float NOT NULL DEFAULT '0',
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
  `InternalName` text,
  `Enchantment1` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
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
  `InternalName_lang` text,
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
  `InternalName` text,
  `Enchantment1` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct1` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct2` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct3` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct4` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct5` int(10) unsigned NOT NULL DEFAULT '0',
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
  `InternalName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
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
  `Quality` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `Unk1` float NOT NULL DEFAULT '0',
  `Unk2` float NOT NULL DEFAULT '0',
  `BuyCount` int(10) unsigned NOT NULL DEFAULT '0',
  `BuyPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `SellPrice` int(10) unsigned NOT NULL DEFAULT '0',
  `InventoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `AllowableClass` int(11) NOT NULL DEFAULT '0',
  `AllowableRace` int(11) NOT NULL DEFAULT '0',
  `ItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` int(11) NOT NULL DEFAULT '0',
  `RequiredSkill` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredHonorRank` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCityRank` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxCount` int(10) unsigned NOT NULL DEFAULT '0',
  `Stackable` int(10) unsigned NOT NULL DEFAULT '0',
  `ContainerSlots` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemStatType1` int(11) NOT NULL DEFAULT '0',
  `ItemStatType2` int(11) NOT NULL DEFAULT '0',
  `ItemStatType3` int(11) NOT NULL DEFAULT '0',
  `ItemStatType4` int(11) NOT NULL DEFAULT '0',
  `ItemStatType5` int(11) NOT NULL DEFAULT '0',
  `ItemStatType6` int(11) NOT NULL DEFAULT '0',
  `ItemStatType7` int(11) NOT NULL DEFAULT '0',
  `ItemStatType8` int(11) NOT NULL DEFAULT '0',
  `ItemStatType9` int(11) NOT NULL DEFAULT '0',
  `ItemStatType10` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue1` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue2` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue3` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue4` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue5` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue6` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue7` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue8` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue9` int(11) NOT NULL DEFAULT '0',
  `ItemStatValue10` int(11) NOT NULL DEFAULT '0',
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
  `ScalingStatDistribution` int(10) unsigned NOT NULL DEFAULT '0',
  `DamageType` int(10) unsigned NOT NULL DEFAULT '0',
  `Delay` int(10) unsigned NOT NULL DEFAULT '0',
  `RangedModRange` float NOT NULL DEFAULT '0',
  `Bonding` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Name2` text,
  `Name3` text,
  `Name4` text,
  `Description` text,
  `PageText` int(10) unsigned NOT NULL DEFAULT '0',
  `LanguageID` int(10) unsigned NOT NULL DEFAULT '0',
  `PageMaterial` int(10) unsigned NOT NULL DEFAULT '0',
  `StartQuest` int(10) unsigned NOT NULL DEFAULT '0',
  `LockID` int(10) unsigned NOT NULL DEFAULT '0',
  `Material` int(11) NOT NULL DEFAULT '0',
  `Sheath` int(10) unsigned NOT NULL DEFAULT '0',
  `RandomProperty` int(10) unsigned NOT NULL DEFAULT '0',
  `RandomSuffix` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemSet` int(10) unsigned NOT NULL DEFAULT '0',
  `Area` int(10) unsigned NOT NULL DEFAULT '0',
  `Map` int(10) unsigned NOT NULL DEFAULT '0',
  `BagFamily` int(10) unsigned NOT NULL DEFAULT '0',
  `TotemCategory` int(10) unsigned NOT NULL DEFAULT '0',
  `SocketColor1` int(10) unsigned NOT NULL DEFAULT '0',
  `SocketColor2` int(10) unsigned NOT NULL DEFAULT '0',
  `SocketColor3` int(10) unsigned NOT NULL DEFAULT '0',
  `SocketBonus` int(10) unsigned NOT NULL DEFAULT '0',
  `GemProperties` int(10) unsigned NOT NULL DEFAULT '0',
  `ArmorDamageModifier` float NOT NULL DEFAULT '0',
  `Duration` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLimitCategory` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StatScalingFactor` float NOT NULL DEFAULT '0',
  `CurrencySubstitutionID` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencySubstitutionCount` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemType` int(10) unsigned NOT NULL DEFAULT '0',
  `PrimaryStat` int(10) unsigned NOT NULL DEFAULT '0',
  `SecondaryStat` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `key_chain`
--

DROP TABLE IF EXISTS `key_chain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `key_chain` (
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
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
  PRIMARY KEY (`Id`)
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
-- Table structure for table `mount`
--

DROP TABLE IF EXISTS `mount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount` (
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
  `MountTypeId` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayId` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `SourceDescription` text,
  `Source` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionId` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mount_capability`
--

DROP TABLE IF EXISTS `mount_capability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mount_capability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredRidingSkill` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredArea` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `SpeedModSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredMap` int(11) NOT NULL DEFAULT '0',
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
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `SourceDescription_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`,`locale`)
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
  `MountTypeID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `MountCapabilityID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Race` int(10) unsigned NOT NULL DEFAULT '0',
  `Sex` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerActionbarFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `phase_group`
--

DROP TABLE IF EXISTS `phase_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phase_group` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PhaseID` int(10) unsigned NOT NULL DEFAULT '0',
  `PhaseGroupID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
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
  PRIMARY KEY (`Level`)
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
  `QuestPackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCount` int(10) unsigned NOT NULL DEFAULT '0',
  `FilterType` int(10) unsigned NOT NULL DEFAULT '0',
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
  `UniqueBitFlag` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelCurveID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sound_entries`
--

DROP TABLE IF EXISTS `sound_entries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sound_entries` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundType` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `FileDataID1` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID2` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID3` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID4` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID5` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID6` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID7` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID8` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID9` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID10` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID11` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID12` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID13` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID14` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID15` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID16` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID17` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID18` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID19` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID20` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq1` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq2` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq3` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq4` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq5` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq6` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq7` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq8` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq9` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq10` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq11` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq12` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq13` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq14` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq15` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq16` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq17` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq18` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq19` int(10) unsigned NOT NULL DEFAULT '0',
  `Freq20` int(10) unsigned NOT NULL DEFAULT '0',
  `VolumeFloat` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MinDistance` float NOT NULL DEFAULT '0',
  `DistanceCutoff` float NOT NULL DEFAULT '0',
  `EAXDef` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundEntriesAdvancedID` int(10) unsigned NOT NULL DEFAULT '0',
  `VolumeVariationPlus` float NOT NULL DEFAULT '0',
  `VolumeVariationMinus` float NOT NULL DEFAULT '0',
  `PitchVariationPlus` float NOT NULL DEFAULT '0',
  `PitchVariationMinus` float NOT NULL DEFAULT '0',
  `PitchAdjust` float NOT NULL DEFAULT '0',
  `DialogType` int(10) unsigned NOT NULL DEFAULT '0',
  `BusOverwriteID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sound_entries_locale`
--

DROP TABLE IF EXISTS `sound_entries_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sound_entries_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `specialization_spells`
--

DROP TABLE IF EXISTS `specialization_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `specialization_spells` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
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
-- Table structure for table `spell_aura_restrictions`
--

DROP TABLE IF EXISTS `spell_aura_restrictions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_aura_restrictions` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CasterAuraState` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetAuraState` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeCasterAuraState` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeTargetAuraState` int(10) unsigned NOT NULL DEFAULT '0',
  `CasterAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeCasterAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `ExcludeTargetAuraSpell` int(10) unsigned NOT NULL DEFAULT '0',
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
  `CastTimePerLevel` int(11) NOT NULL DEFAULT '0',
  `MinCastTime` int(11) NOT NULL DEFAULT '0',
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
  `FacingCasterFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `MinFactionID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinReputation` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAreasID` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAuraVision` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiresSpellFocus` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `ModalNextSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask3` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassMask4` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Duration1` int(11) NOT NULL DEFAULT '0',
  `Duration2` int(11) NOT NULL DEFAULT '0',
  `Duration3` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_effect_group_size`
--

DROP TABLE IF EXISTS `spell_effect_group_size`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_effect_group_size` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `Size` float NOT NULL DEFAULT '0',
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
  `LTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperand1` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand2` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand3` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand4` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand5` int(10) unsigned NOT NULL DEFAULT '0',
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
  `RTOperand1` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand2` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand3` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand4` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand5` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `spell_misc`
--

DROP TABLE IF EXISTS `spell_misc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_misc` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `CastingTimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `DurationIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `RangeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `Speed` float NOT NULL DEFAULT '0',
  `SpellIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `ActiveIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `SchoolMask` int(10) unsigned NOT NULL DEFAULT '0',
  `MultistrikeSpeedMod` float NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerType` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCost` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCostPerLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCostPerSecond` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCostAdditional` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `UnitPowerBarID` int(10) unsigned NOT NULL DEFAULT '0',
  `ManaCostPercentage` float NOT NULL DEFAULT '0',
  `ManaCostPercentagePerSecond` float NOT NULL DEFAULT '0',
  `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0',
  `HealthCostPercentage` float NOT NULL DEFAULT '0',
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
  `SpellPowerID` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellPowerID`)
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
  `MinRangeHostile` float NOT NULL DEFAULT '0',
  `MinRangeFriend` float NOT NULL DEFAULT '0',
  `MaxRangeHostile` float NOT NULL DEFAULT '0',
  `MaxRangeFriend` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `DisplayNameShort` text,
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
  `Reagent1` int(11) NOT NULL DEFAULT '0',
  `Reagent2` int(11) NOT NULL DEFAULT '0',
  `Reagent3` int(11) NOT NULL DEFAULT '0',
  `Reagent4` int(11) NOT NULL DEFAULT '0',
  `Reagent5` int(11) NOT NULL DEFAULT '0',
  `Reagent6` int(11) NOT NULL DEFAULT '0',
  `Reagent7` int(11) NOT NULL DEFAULT '0',
  `Reagent8` int(11) NOT NULL DEFAULT '0',
  `ReagentCount1` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount2` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount3` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount4` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount5` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount6` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount7` int(10) unsigned NOT NULL DEFAULT '0',
  `ReagentCount8` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyID` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_rune_cost`
--

DROP TABLE IF EXISTS `spell_rune_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spell_rune_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Blood` int(10) unsigned NOT NULL DEFAULT '0',
  `Unholy` int(10) unsigned NOT NULL DEFAULT '0',
  `Frost` int(10) unsigned NOT NULL DEFAULT '0',
  `Chromatic` int(10) unsigned NOT NULL DEFAULT '0',
  `RunicPower` int(10) unsigned NOT NULL DEFAULT '0',
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
  `RequiredTotemCategoryID1` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredTotemCategoryID2` int(10) unsigned NOT NULL DEFAULT '0',
  `Totem1` int(10) unsigned NOT NULL DEFAULT '0',
  `Totem2` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualID1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualID2` int(10) unsigned NOT NULL DEFAULT '0',
  `Unk620` float NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
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
  `MapID` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `Name` text,
  `MountCreatureID1` int(10) unsigned NOT NULL DEFAULT '0',
  `MountCreatureID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `LearnableIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MapOffsetX` float NOT NULL DEFAULT '0',
  `MapOffsetY` float NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `From` int(10) unsigned NOT NULL DEFAULT '0',
  `To` int(10) unsigned NOT NULL DEFAULT '0',
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
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PathID` int(10) unsigned NOT NULL DEFAULT '0',
  `NodeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` int(10) unsigned NOT NULL DEFAULT '0',
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Delay` int(10) unsigned NOT NULL DEFAULT '0',
  `ArrivalEventID` int(10) unsigned NOT NULL DEFAULT '0',
  `DepartureEventID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `CategoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryMask` int(10) unsigned NOT NULL DEFAULT '0',
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
-- Table structure for table `transport_animation`
--

DROP TABLE IF EXISTS `transport_animation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transport_animation` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `SequenceID` int(10) unsigned NOT NULL DEFAULT '0',
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
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
  `Z` float NOT NULL DEFAULT '0',
  `W` float NOT NULL DEFAULT '0',
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
  `MinPower` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxPower` int(10) unsigned NOT NULL DEFAULT '0',
  `StartPower` int(10) unsigned NOT NULL DEFAULT '0',
  `CenterPower` int(10) unsigned NOT NULL DEFAULT '0',
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `BarType` int(10) unsigned NOT NULL DEFAULT '0',
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
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Cost` text,
  `OutOfError` text,
  `ToolTip` text,
  `StartInset` float NOT NULL DEFAULT '0',
  `EndInset` float NOT NULL DEFAULT '0',
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
-- Table structure for table `world_map_overlay`
--

DROP TABLE IF EXISTS `world_map_overlay`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_map_overlay` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapAreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID3` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID4` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureName` text,
  `TextureWidth` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureHeight` int(10) unsigned NOT NULL DEFAULT '0',
  `OffsetX` int(10) unsigned NOT NULL DEFAULT '0',
  `OffsetY` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectTop` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectLeft` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectBottom` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectRight` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `world_map_overlay_locale`
--

DROP TABLE IF EXISTS `world_map_overlay_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `world_map_overlay_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `TextureName_lang` text,
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

-- Dump completed on 2015-07-13 23:52:10
