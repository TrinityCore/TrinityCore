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
  `Data0` int(10) unsigned NOT NULL DEFAULT '0',
  `Data1` int(10) unsigned NOT NULL DEFAULT '0',
  `Data2` int(10) unsigned NOT NULL DEFAULT '0',
  `Data3` int(10) unsigned NOT NULL DEFAULT '0',
  `Data4` int(10) unsigned NOT NULL DEFAULT '0',
  `Data5` int(10) unsigned NOT NULL DEFAULT '0',
  `Data6` int(10) unsigned NOT NULL DEFAULT '0',
  `Data7` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
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
  `SpellVisualID1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualID2` int(10) unsigned NOT NULL DEFAULT '0',
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
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-03-21 16:07:14
