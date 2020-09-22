-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: hotfixes
-- ------------------------------------------------------
-- Server version	5.7.30-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `hotfix_data`
--

DROP TABLE IF EXISTS `hotfix_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hotfix_data` (
  `TableHash` int(10) unsigned NOT NULL DEFAULT '0',
  `RecordID` int(10) NOT NULL,
  `Deleted` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`TableHash`,`RecordID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassID` int(10) unsigned NOT NULL DEFAULT '0',
  `SubclassID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclassID` int(11) NOT NULL DEFAULT '0',
  `Material` int(11) NOT NULL DEFAULT '0',
  `DisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `InventoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `SheatheType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_currency_cost`
--

DROP TABLE IF EXISTS `item_currency_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_currency_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `idx_itemId` (`ItemID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_extended_cost`
--

DROP TABLE IF EXISTS `item_extended_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_extended_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredHonorPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredArenaPoints` int(10) unsigned NOT NULL DEFAULT '0',
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
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
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
  `PriceRandomValue` float NOT NULL DEFAULT '0',
  `PriceVariance` float NOT NULL DEFAULT '0',
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
  `RequiredSpell` int(11) NOT NULL DEFAULT '0',
  `RequiredHonorRank` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredCityRank` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxCount` int(11) NOT NULL DEFAULT '0',
  `Stackable` int(11) NOT NULL DEFAULT '0',
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
  `ItemStatSocketCostMultiplier1` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier2` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier3` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier4` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier5` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier6` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier7` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier8` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier9` int(11) NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier10` int(11) NOT NULL DEFAULT '0',
  `ScalingStatDistribution` int(11) NOT NULL DEFAULT '0',
  `DamageType` int(11) NOT NULL DEFAULT '0',
  `Delay` int(10) unsigned NOT NULL DEFAULT '0',
  `RangedModRange` float NOT NULL DEFAULT '0',
  `SpellID1` int(11) NOT NULL DEFAULT '0',
  `SpellID2` int(11) NOT NULL DEFAULT '0',
  `SpellID3` int(11) NOT NULL DEFAULT '0',
  `SpellID4` int(11) NOT NULL DEFAULT '0',
  `SpellID5` int(11) NOT NULL DEFAULT '0',
  `SpellTrigger1` int(11) NOT NULL DEFAULT '0',
  `SpellTrigger2` int(11) NOT NULL DEFAULT '0',
  `SpellTrigger3` int(11) NOT NULL DEFAULT '0',
  `SpellTrigger4` int(11) NOT NULL DEFAULT '0',
  `SpellTrigger5` int(11) NOT NULL DEFAULT '0',
  `SpellCharges1` int(11) NOT NULL DEFAULT '0',
  `SpellCharges2` int(11) NOT NULL DEFAULT '0',
  `SpellCharges3` int(11) NOT NULL DEFAULT '0',
  `SpellCharges4` int(11) NOT NULL DEFAULT '0',
  `SpellCharges5` int(11) NOT NULL DEFAULT '0',
  `SpellCooldown1` int(11) NOT NULL DEFAULT '0',
  `SpellCooldown2` int(11) NOT NULL DEFAULT '0',
  `SpellCooldown3` int(11) NOT NULL DEFAULT '0',
  `SpellCooldown4` int(11) NOT NULL DEFAULT '0',
  `SpellCooldown5` int(11) NOT NULL DEFAULT '0',
  `SpellCategory1` int(11) NOT NULL DEFAULT '0',
  `SpellCategory2` int(11) NOT NULL DEFAULT '0',
  `SpellCategory3` int(11) NOT NULL DEFAULT '0',
  `SpellCategory4` int(11) NOT NULL DEFAULT '0',
  `SpellCategory5` int(11) NOT NULL DEFAULT '0',
  `SpellCategoryCooldown1` int(11) NOT NULL DEFAULT '0',
  `SpellCategoryCooldown2` int(11) NOT NULL DEFAULT '0',
  `SpellCategoryCooldown3` int(11) NOT NULL DEFAULT '0',
  `SpellCategoryCooldown4` int(11) NOT NULL DEFAULT '0',
  `SpellCategoryCooldown5` int(11) NOT NULL DEFAULT '0',
  `Bonding` int(11) NOT NULL DEFAULT '0',
  `Display` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display1` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display2` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display3` mediumtext COLLATE utf8mb4_unicode_ci,
  `Description` mediumtext COLLATE utf8mb4_unicode_ci,
  `PageText` int(10) unsigned NOT NULL DEFAULT '0',
  `LanguageID` int(11) NOT NULL DEFAULT '0',
  `PageMaterial` int(11) NOT NULL DEFAULT '0',
  `StartQuest` int(11) NOT NULL DEFAULT '0',
  `LockID` int(10) unsigned NOT NULL DEFAULT '0',
  `Material` int(11) NOT NULL DEFAULT '0',
  `SheatheType` int(11) NOT NULL DEFAULT '0',
  `RandomProperty` int(11) NOT NULL DEFAULT '0',
  `RandomSuffix` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemSet` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` int(11) NOT NULL DEFAULT '0',
  `BagFamily` int(11) NOT NULL DEFAULT '0',
  `TotemCategory` int(11) NOT NULL DEFAULT '0',
  `SocketColor1` int(11) NOT NULL DEFAULT '0',
  `SocketColor2` int(11) NOT NULL DEFAULT '0',
  `SocketColor3` int(11) NOT NULL DEFAULT '0',
  `Content1` int(10) unsigned NOT NULL DEFAULT '0',
  `Content2` int(10) unsigned NOT NULL DEFAULT '0',
  `Content3` int(10) unsigned NOT NULL DEFAULT '0',
  `SocketBonus` int(11) NOT NULL DEFAULT '0',
  `GemProperties` int(11) NOT NULL DEFAULT '0',
  `ArmorDamageModifier` float NOT NULL DEFAULT '0',
  `Duration` int(11) NOT NULL DEFAULT '0',
  `ItemLimitCategory` int(11) NOT NULL DEFAULT '0',
  `HolidayID` int(11) NOT NULL DEFAULT '0',
  `StatScalingFactor` float NOT NULL DEFAULT '0',
  `CurrencySubstitutionID` int(10) NOT NULL DEFAULT '0',
  `CurrencySubstitutionCount` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_sparse_locale`
--

DROP TABLE IF EXISTS `item_sparse_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_sparse_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Display_lang` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display1_lang` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display2_lang` mediumtext COLLATE utf8mb4_unicode_ci,
  `Display3_lang` mediumtext COLLATE utf8mb4_unicode_ci,
  `Description_lang` mediumtext COLLATE utf8mb4_unicode_ci,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `key_chain`
--

DROP TABLE IF EXISTS `key_chain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `key_chain` (
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
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates`
--

DROP TABLE IF EXISTS `updates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `updates` (
  `name` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'filename with extension of the update.',
  `hash` char(40) COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT 'sha1 hash of the sql file.',
  `state` enum('RELEASED','ARCHIVED') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
  `speed` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'time the query takes to apply in ms.',
  PRIMARY KEY (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='List of all applied updates in this database.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates_include`
--

DROP TABLE IF EXISTS `updates_include`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `updates_include` (
  `path` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
  `state` enum('RELEASED','ARCHIVED') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
  PRIMARY KEY (`path`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='List of directories where we want to include sql updates.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping routines for database 'hotfixes'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-09-22  0:55:52
