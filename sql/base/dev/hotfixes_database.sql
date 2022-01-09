-- MySQL dump 10.13  Distrib 8.0.26, for Linux (x86_64)
--
-- Host: localhost    Database: hotfixes
-- ------------------------------------------------------
-- Server version	8.0.26

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
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
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hotfix_data` (
  `TableHash` int unsigned NOT NULL DEFAULT '0',
  `RecordID` int NOT NULL,
  `Deleted` tinyint unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`TableHash`,`RecordID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ClassID` int unsigned NOT NULL DEFAULT '0',
  `SubclassID` int unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclassID` int NOT NULL DEFAULT '0',
  `Material` int NOT NULL DEFAULT '0',
  `DisplayInfoID` int unsigned NOT NULL DEFAULT '0',
  `InventoryType` int unsigned NOT NULL DEFAULT '0',
  `SheatheType` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_currency_cost`
--

DROP TABLE IF EXISTS `item_currency_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_currency_cost` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `idx_itemId` (`ItemID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_extended_cost`
--

DROP TABLE IF EXISTS `item_extended_cost`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_extended_cost` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `RequiredHonorPoints` int unsigned NOT NULL DEFAULT '0',
  `RequiredArenaPoints` int unsigned NOT NULL DEFAULT '0',
  `RequiredArenaSlot` int unsigned NOT NULL DEFAULT '0',
  `RequiredItem1` int unsigned NOT NULL DEFAULT '0',
  `RequiredItem2` int unsigned NOT NULL DEFAULT '0',
  `RequiredItem3` int unsigned NOT NULL DEFAULT '0',
  `RequiredItem4` int unsigned NOT NULL DEFAULT '0',
  `RequiredItem5` int unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount1` int unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount2` int unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount3` int unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount4` int unsigned NOT NULL DEFAULT '0',
  `RequiredItemCount5` int unsigned NOT NULL DEFAULT '0',
  `RequiredPersonalArenaRating` int unsigned NOT NULL DEFAULT '0',
  `ItemPurchaseGroup` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency1` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency2` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency3` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency4` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrency5` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount1` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount2` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount3` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount4` int unsigned NOT NULL DEFAULT '0',
  `RequiredCurrencyCount5` int unsigned NOT NULL DEFAULT '0',
  `RequiredFactionId` int unsigned NOT NULL DEFAULT '0',
  `RequiredFactionStanding` int unsigned NOT NULL DEFAULT '0',
  `RequirementFlags` int unsigned NOT NULL DEFAULT '0',
  `RequiredGuildLevel` int unsigned NOT NULL DEFAULT '0',
  `RequiredAchievement` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_sparse`
--

DROP TABLE IF EXISTS `item_sparse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_sparse` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Quality` int unsigned NOT NULL DEFAULT '0',
  `Flags1` int unsigned NOT NULL DEFAULT '0',
  `Flags2` int unsigned NOT NULL DEFAULT '0',
  `PriceRandomValue` float NOT NULL DEFAULT '0',
  `PriceVariance` float NOT NULL DEFAULT '0',
  `BuyCount` int unsigned NOT NULL DEFAULT '0',
  `BuyPrice` int unsigned NOT NULL DEFAULT '0',
  `SellPrice` int unsigned NOT NULL DEFAULT '0',
  `InventoryType` int unsigned NOT NULL DEFAULT '0',
  `AllowableClass` int NOT NULL DEFAULT '0',
  `AllowableRace` int NOT NULL DEFAULT '0',
  `ItemLevel` int unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` int NOT NULL DEFAULT '0',
  `RequiredSkill` int unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` int unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int NOT NULL DEFAULT '0',
  `RequiredHonorRank` int unsigned NOT NULL DEFAULT '0',
  `RequiredCityRank` int unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` int unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` int unsigned NOT NULL DEFAULT '0',
  `MaxCount` int NOT NULL DEFAULT '0',
  `Stackable` int NOT NULL DEFAULT '0',
  `ContainerSlots` int unsigned NOT NULL DEFAULT '0',
  `ItemStatType1` int NOT NULL DEFAULT '0',
  `ItemStatType2` int NOT NULL DEFAULT '0',
  `ItemStatType3` int NOT NULL DEFAULT '0',
  `ItemStatType4` int NOT NULL DEFAULT '0',
  `ItemStatType5` int NOT NULL DEFAULT '0',
  `ItemStatType6` int NOT NULL DEFAULT '0',
  `ItemStatType7` int NOT NULL DEFAULT '0',
  `ItemStatType8` int NOT NULL DEFAULT '0',
  `ItemStatType9` int NOT NULL DEFAULT '0',
  `ItemStatType10` int NOT NULL DEFAULT '0',
  `ItemStatValue1` int NOT NULL DEFAULT '0',
  `ItemStatValue2` int NOT NULL DEFAULT '0',
  `ItemStatValue3` int NOT NULL DEFAULT '0',
  `ItemStatValue4` int NOT NULL DEFAULT '0',
  `ItemStatValue5` int NOT NULL DEFAULT '0',
  `ItemStatValue6` int NOT NULL DEFAULT '0',
  `ItemStatValue7` int NOT NULL DEFAULT '0',
  `ItemStatValue8` int NOT NULL DEFAULT '0',
  `ItemStatValue9` int NOT NULL DEFAULT '0',
  `ItemStatValue10` int NOT NULL DEFAULT '0',
  `ItemStatAllocation1` int NOT NULL DEFAULT '0',
  `ItemStatAllocation2` int NOT NULL DEFAULT '0',
  `ItemStatAllocation3` int NOT NULL DEFAULT '0',
  `ItemStatAllocation4` int NOT NULL DEFAULT '0',
  `ItemStatAllocation5` int NOT NULL DEFAULT '0',
  `ItemStatAllocation6` int NOT NULL DEFAULT '0',
  `ItemStatAllocation7` int NOT NULL DEFAULT '0',
  `ItemStatAllocation8` int NOT NULL DEFAULT '0',
  `ItemStatAllocation9` int NOT NULL DEFAULT '0',
  `ItemStatAllocation10` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier1` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier2` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier3` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier4` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier5` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier6` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier7` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier8` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier9` int NOT NULL DEFAULT '0',
  `ItemStatSocketCostMultiplier10` int NOT NULL DEFAULT '0',
  `ScalingStatDistribution` int NOT NULL DEFAULT '0',
  `DamageType` int NOT NULL DEFAULT '0',
  `Delay` int unsigned NOT NULL DEFAULT '0',
  `RangedModRange` float NOT NULL DEFAULT '0',
  `SpellID1` int NOT NULL DEFAULT '0',
  `SpellID2` int NOT NULL DEFAULT '0',
  `SpellID3` int NOT NULL DEFAULT '0',
  `SpellID4` int NOT NULL DEFAULT '0',
  `SpellID5` int NOT NULL DEFAULT '0',
  `SpellTrigger1` int NOT NULL DEFAULT '0',
  `SpellTrigger2` int NOT NULL DEFAULT '0',
  `SpellTrigger3` int NOT NULL DEFAULT '0',
  `SpellTrigger4` int NOT NULL DEFAULT '0',
  `SpellTrigger5` int NOT NULL DEFAULT '0',
  `SpellCharges1` int NOT NULL DEFAULT '0',
  `SpellCharges2` int NOT NULL DEFAULT '0',
  `SpellCharges3` int NOT NULL DEFAULT '0',
  `SpellCharges4` int NOT NULL DEFAULT '0',
  `SpellCharges5` int NOT NULL DEFAULT '0',
  `SpellCooldown1` int NOT NULL DEFAULT '0',
  `SpellCooldown2` int NOT NULL DEFAULT '0',
  `SpellCooldown3` int NOT NULL DEFAULT '0',
  `SpellCooldown4` int NOT NULL DEFAULT '0',
  `SpellCooldown5` int NOT NULL DEFAULT '0',
  `SpellCategory1` int NOT NULL DEFAULT '0',
  `SpellCategory2` int NOT NULL DEFAULT '0',
  `SpellCategory3` int NOT NULL DEFAULT '0',
  `SpellCategory4` int NOT NULL DEFAULT '0',
  `SpellCategory5` int NOT NULL DEFAULT '0',
  `SpellCategoryCooldown1` int NOT NULL DEFAULT '0',
  `SpellCategoryCooldown2` int NOT NULL DEFAULT '0',
  `SpellCategoryCooldown3` int NOT NULL DEFAULT '0',
  `SpellCategoryCooldown4` int NOT NULL DEFAULT '0',
  `SpellCategoryCooldown5` int NOT NULL DEFAULT '0',
  `Bonding` int NOT NULL DEFAULT '0',
  `Display` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display1` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display2` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display3` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Description` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `PageText` int unsigned NOT NULL DEFAULT '0',
  `LanguageID` int NOT NULL DEFAULT '0',
  `PageMaterial` int NOT NULL DEFAULT '0',
  `StartQuest` int NOT NULL DEFAULT '0',
  `LockID` int unsigned NOT NULL DEFAULT '0',
  `Material` int NOT NULL DEFAULT '0',
  `SheatheType` int NOT NULL DEFAULT '0',
  `RandomProperty` int NOT NULL DEFAULT '0',
  `RandomSuffix` int unsigned NOT NULL DEFAULT '0',
  `ItemSet` int unsigned NOT NULL DEFAULT '0',
  `AreaID` int unsigned NOT NULL DEFAULT '0',
  `MapID` int NOT NULL DEFAULT '0',
  `BagFamily` int NOT NULL DEFAULT '0',
  `TotemCategory` int NOT NULL DEFAULT '0',
  `SocketColor1` int NOT NULL DEFAULT '0',
  `SocketColor2` int NOT NULL DEFAULT '0',
  `SocketColor3` int NOT NULL DEFAULT '0',
  `Content1` int unsigned NOT NULL DEFAULT '0',
  `Content2` int unsigned NOT NULL DEFAULT '0',
  `Content3` int unsigned NOT NULL DEFAULT '0',
  `SocketBonus` int NOT NULL DEFAULT '0',
  `GemProperties` int NOT NULL DEFAULT '0',
  `ArmorDamageModifier` float NOT NULL DEFAULT '0',
  `Duration` int NOT NULL DEFAULT '0',
  `ItemLimitCategory` int NOT NULL DEFAULT '0',
  `HolidayID` int NOT NULL DEFAULT '0',
  `StatScalingFactor` float NOT NULL DEFAULT '0',
  `CurrencySubstitutionID` int NOT NULL DEFAULT '0',
  `CurrencySubstitutionCount` int NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `item_sparse_locale`
--

DROP TABLE IF EXISTS `item_sparse_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_sparse_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Display_lang` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display1_lang` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display2_lang` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Display3_lang` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `Description_lang` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `VerifiedBuild` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `key_chain`
--

DROP TABLE IF EXISTS `key_chain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `key_chain` (
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
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates`
--

DROP TABLE IF EXISTS `updates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `updates` (
  `name` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'filename with extension of the update.',
  `hash` char(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT 'sha1 hash of the sql file.',
  `state` enum('RELEASED','ARCHIVED') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
  `speed` int unsigned NOT NULL DEFAULT '0' COMMENT 'time the query takes to apply in ms.',
  PRIMARY KEY (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='List of all applied updates in this database.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `updates_include`
--

DROP TABLE IF EXISTS `updates_include`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `updates_include` (
  `path` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
  `state` enum('RELEASED','ARCHIVED') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
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

-- Dump completed on 2022-01-09  0:15:09
