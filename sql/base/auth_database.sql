-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: auth
-- ------------------------------------------------------
-- Server version	5.7.30-0ubuntu0.18.04.1

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
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(32) NOT NULL DEFAULT '',
  `salt` binary(32) DEFAULT NULL,
  `verifier` binary(32) DEFAULT NULL,
  `session_key_auth` binary(40) DEFAULT NULL,
  `session_key_bnet` varbinary(64) DEFAULT NULL,
  `sha_pass_hash` varchar(40) NOT NULL DEFAULT '',
  `v` varchar(64) NOT NULL DEFAULT 'dummy value, use `verifier` instead',
  `s` varchar(64) NOT NULL DEFAULT 'dummy value, use `salt` instead',
  `token_key` varchar(100) NOT NULL DEFAULT '',
  `email` varchar(255) NOT NULL DEFAULT '',
  `reg_mail` varchar(255) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `last_attempt_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) NOT NULL DEFAULT '00',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '8',
  `mutetime` bigint(20) NOT NULL DEFAULT '0',
  `mutereason` varchar(255) NOT NULL DEFAULT '',
  `muteby` varchar(50) NOT NULL DEFAULT '',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(4) NOT NULL DEFAULT '',
  `recruiter` int(10) unsigned NOT NULL DEFAULT '0',
  `battlenet_account` int(10) unsigned DEFAULT NULL,
  `battlenet_index` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_username` (`username`),
  UNIQUE KEY `uk_bnet_acc` (`battlenet_account`,`battlenet_index`),
  CONSTRAINT `fk_bnet_acc` FOREIGN KEY (`battlenet_account`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account System';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `account_access`
--

DROP TABLE IF EXISTS `account_access`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account_access` (
  `AccountID` int(10) unsigned NOT NULL,
  `SecurityLevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL DEFAULT '-1',
  `Comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`AccountID`,`RealmID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_access`
--

LOCK TABLES `account_access` WRITE;
/*!40000 ALTER TABLE `account_access` DISABLE KEYS */;
/*!40000 ALTER TABLE `account_access` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `account_banned`
--

DROP TABLE IF EXISTS `account_banned`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account_banned` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_banned`
--

LOCK TABLES `account_banned` WRITE;
/*!40000 ALTER TABLE `account_banned` DISABLE KEYS */;
/*!40000 ALTER TABLE `account_banned` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `account_last_played_character`
--

DROP TABLE IF EXISTS `account_last_played_character`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account_last_played_character` (
  `accountId` int(10) unsigned NOT NULL,
  `region` tinyint(3) unsigned NOT NULL,
  `battlegroup` tinyint(3) unsigned NOT NULL,
  `realmId` int(10) unsigned DEFAULT NULL,
  `characterName` varchar(12) DEFAULT NULL,
  `characterGUID` bigint(20) unsigned DEFAULT NULL,
  `lastPlayedTime` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`accountId`,`region`,`battlegroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_last_played_character`
--

LOCK TABLES `account_last_played_character` WRITE;
/*!40000 ALTER TABLE `account_last_played_character` DISABLE KEYS */;
/*!40000 ALTER TABLE `account_last_played_character` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `account_muted`
--

DROP TABLE IF EXISTS `account_muted`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account_muted` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `mutedate` int(10) unsigned NOT NULL DEFAULT '0',
  `mutetime` int(10) unsigned NOT NULL DEFAULT '0',
  `mutedby` varchar(50) NOT NULL,
  `mutereason` varchar(255) NOT NULL,
  PRIMARY KEY (`guid`,`mutedate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='mute List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_muted`
--

LOCK TABLES `account_muted` WRITE;
/*!40000 ALTER TABLE `account_muted` DISABLE KEYS */;
/*!40000 ALTER TABLE `account_muted` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `autobroadcast`
--

DROP TABLE IF EXISTS `autobroadcast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `autobroadcast` (
  `realmid` int(11) NOT NULL DEFAULT '-1',
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) unsigned DEFAULT '1',
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `autobroadcast`
--

LOCK TABLES `autobroadcast` WRITE;
/*!40000 ALTER TABLE `autobroadcast` DISABLE KEYS */;
/*!40000 ALTER TABLE `autobroadcast` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pet_slots`
--

DROP TABLE IF EXISTS `battle_pet_slots`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pet_slots` (
  `id` tinyint(3) NOT NULL,
  `battlenetAccountId` int(10) NOT NULL,
  `battlePetGuid` bigint(20) NOT NULL,
  `locked` tinyint(3) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`battlenetAccountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pet_slots`
--

LOCK TABLES `battle_pet_slots` WRITE;
/*!40000 ALTER TABLE `battle_pet_slots` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pet_slots` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battle_pets`
--

DROP TABLE IF EXISTS `battle_pets`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battle_pets` (
  `guid` bigint(20) NOT NULL,
  `battlenetAccountId` int(10) NOT NULL,
  `species` int(10) NOT NULL,
  `breed` smallint(5) NOT NULL,
  `level` smallint(5) NOT NULL DEFAULT '1',
  `exp` smallint(5) NOT NULL DEFAULT '0',
  `health` int(10) NOT NULL DEFAULT '1',
  `quality` tinyint(3) NOT NULL DEFAULT '0',
  `flags` smallint(5) NOT NULL DEFAULT '0',
  `name` varchar(12) NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battle_pets`
--

LOCK TABLES `battle_pets` WRITE;
/*!40000 ALTER TABLE `battle_pets` DISABLE KEYS */;
/*!40000 ALTER TABLE `battle_pets` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_account_bans`
--

DROP TABLE IF EXISTS `battlenet_account_bans`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_account_bans` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_account_bans`
--

LOCK TABLES `battlenet_account_bans` WRITE;
/*!40000 ALTER TABLE `battlenet_account_bans` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_account_bans` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_account_heirlooms`
--

DROP TABLE IF EXISTS `battlenet_account_heirlooms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_account_heirlooms` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(11) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_account_heirlooms`
--

LOCK TABLES `battlenet_account_heirlooms` WRITE;
/*!40000 ALTER TABLE `battlenet_account_heirlooms` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_account_heirlooms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_account_mounts`
--

DROP TABLE IF EXISTS `battlenet_account_mounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_account_mounts` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `mountSpellId` int(10) unsigned NOT NULL,
  `flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`mountSpellId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_account_mounts`
--

LOCK TABLES `battlenet_account_mounts` WRITE;
/*!40000 ALTER TABLE `battlenet_account_mounts` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_account_mounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_account_toys`
--

DROP TABLE IF EXISTS `battlenet_account_toys`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_account_toys` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(11) NOT NULL DEFAULT '0',
  `isFavourite` tinyint(1) DEFAULT '0',
  `hasFanfare` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_account_toys`
--

LOCK TABLES `battlenet_account_toys` WRITE;
/*!40000 ALTER TABLE `battlenet_account_toys` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_account_toys` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_accounts`
--

DROP TABLE IF EXISTS `battlenet_accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_accounts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `email` varchar(320) NOT NULL,
  `sha_pass_hash` varchar(64) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) NOT NULL DEFAULT '00',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(4) NOT NULL DEFAULT '',
  `LastCharacterUndelete` int(10) unsigned NOT NULL DEFAULT '0',
  `LoginTicket` varchar(64) DEFAULT NULL,
  `LoginTicketExpiry` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account System';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_accounts`
--

LOCK TABLES `battlenet_accounts` WRITE;
/*!40000 ALTER TABLE `battlenet_accounts` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_item_appearances`
--

DROP TABLE IF EXISTS `battlenet_item_appearances`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_item_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `blobIndex` smallint(5) unsigned NOT NULL,
  `appearanceMask` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`blobIndex`),
  CONSTRAINT `fk_battlenet_item_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_item_appearances`
--

LOCK TABLES `battlenet_item_appearances` WRITE;
/*!40000 ALTER TABLE `battlenet_item_appearances` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_item_appearances` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlenet_item_favorite_appearances`
--

DROP TABLE IF EXISTS `battlenet_item_favorite_appearances`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `battlenet_item_favorite_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `itemModifiedAppearanceId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`battlenetAccountId`,`itemModifiedAppearanceId`),
  CONSTRAINT `fk_battlenet_item_favorite_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `battlenet_item_favorite_appearances`
--

LOCK TABLES `battlenet_item_favorite_appearances` WRITE;
/*!40000 ALTER TABLE `battlenet_item_favorite_appearances` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlenet_item_favorite_appearances` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `build_info`
--

DROP TABLE IF EXISTS `build_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `build_info` (
  `build` int(11) NOT NULL,
  `majorVersion` int(11) DEFAULT NULL,
  `minorVersion` int(11) DEFAULT NULL,
  `bugfixVersion` int(11) DEFAULT NULL,
  `hotfixVersion` char(3) DEFAULT NULL,
  `winAuthSeed` varchar(32) DEFAULT NULL,
  `win64AuthSeed` varchar(32) DEFAULT NULL,
  `mac64AuthSeed` varchar(32) DEFAULT NULL,
  `winChecksumSeed` varchar(40) DEFAULT NULL,
  `macChecksumSeed` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`build`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `build_info`
--

LOCK TABLES `build_info` WRITE;
/*!40000 ALTER TABLE `build_info` DISABLE KEYS */;
INSERT INTO `build_info` VALUES
(5875,1,12,1,NULL,NULL,NULL,NULL,'95EDB27C7823B363CBDDAB56A392E7CB73FCCA20','8D173CC381961EEBABF336F5E6675B101BB513E5'),
(6005,1,12,2,NULL,NULL,NULL,NULL,NULL,NULL),
(6141,1,12,3,NULL,NULL,NULL,NULL,NULL,NULL),
(8606,2,4,3,NULL,NULL,NULL,NULL,'319AFAA3F2559682F9FF658BE01456255F456FB1','D8B0ECFE534BC1131E19BAD1D4C0E813EEE4994F'),
(9947,3,1,3,NULL,NULL,NULL,NULL,NULL,NULL),
(10505,3,2,2,'a',NULL,NULL,NULL,NULL,NULL),
(11159,3,3,0,'a',NULL,NULL,NULL,NULL,NULL),
(11403,3,3,2,NULL,NULL,NULL,NULL,NULL,NULL),
(11723,3,3,3,'a',NULL,NULL,NULL,NULL,NULL),
(12340,3,3,5,'a',NULL,NULL,NULL,'CDCBBD5188315E6B4D19449D492DBCFAF156A347','B706D13FF2F4018839729461E3F8A0E2B5FDC034'),
(13623,4,0,6,'a',NULL,NULL,NULL,NULL,NULL),
(13930,3,3,5,'a',NULL,NULL,NULL,NULL,NULL),
(14545,4,2,2,NULL,NULL,NULL,NULL,NULL,NULL),
(15595,4,3,4,NULL,NULL,NULL,NULL,NULL,NULL),
(19116,6,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(19243,6,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(19342,6,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(19702,6,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(19802,6,1,2,NULL,NULL,NULL,NULL,NULL,NULL),
(19831,6,1,2,NULL,NULL,NULL,NULL,NULL,NULL),
(19865,6,1,2,NULL,NULL,NULL,NULL,NULL,NULL),
(20182,6,2,0,'a',NULL,NULL,NULL,NULL,NULL),
(20201,6,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(20216,6,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(20253,6,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(20338,6,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(20444,6,2,2,NULL,NULL,NULL,NULL,NULL,NULL),
(20490,6,2,2,'a',NULL,NULL,NULL,NULL,NULL),
(20574,6,2,2,'a',NULL,NULL,NULL,NULL,NULL),
(20726,6,2,3,NULL,NULL,NULL,NULL,NULL,NULL),
(20779,6,2,3,NULL,NULL,NULL,NULL,NULL,NULL),
(20886,6,2,3,NULL,NULL,NULL,NULL,NULL,NULL),
(21355,6,2,4,NULL,NULL,NULL,NULL,NULL,NULL),
(21463,6,2,4,NULL,NULL,NULL,NULL,NULL,NULL),
(21742,6,2,4,NULL,NULL,NULL,NULL,NULL,NULL),
(22248,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22293,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22345,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22410,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22423,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22498,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22522,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22566,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22594,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22624,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22747,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22810,7,0,3,NULL,NULL,NULL,NULL,NULL,NULL),
(22900,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(22908,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(22950,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(22995,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(22996,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(23171,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(23222,7,1,0,NULL,NULL,NULL,NULL,NULL,NULL),
(23360,7,1,5,NULL,NULL,NULL,NULL,NULL,NULL),
(23420,7,1,5,NULL,NULL,NULL,NULL,NULL,NULL),
(23911,7,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(23937,7,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(24015,7,2,0,NULL,NULL,NULL,NULL,NULL,NULL),
(24330,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(24367,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(24415,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(24430,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(24461,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(24742,7,2,5,NULL,NULL,NULL,NULL,NULL,NULL),
(25549,7,3,2,NULL,'FE594FC35E7F9AFF86D99D8A364AB297','1252624ED8CBD6FAC7D33F5D67A535F3','66FC5E09B8706126795F140308C8C1D8',NULL,NULL),
(25996,7,3,5,NULL,'23C59C5963CBEF5B728D13A50878DFCB','C7FF932D6A2174A3D538CA7212136D2B','210B970149D6F56CAC9BADF2AAC91E8E',NULL,NULL),
(26124,7,3,5,NULL,'F8C05AE372DECA1D6C81DA7A8D1C5C39','46DF06D0147BA67BA49AF553435E093F','C9CA997AB8EDE1C65465CB2920869C4E',NULL,NULL),
(26365,7,3,5,NULL,'2AAC82C80E829E2CA902D70CFA1A833A','59A53F307288454B419B13E694DF503C','DBE7F860276D6B400AAA86B35D51A417',NULL,NULL),
(26654,7,3,5,NULL,'FAC2D693E702B9EC9F750F17245696D8','A752640E8B99FE5B57C1320BC492895A','9234C1BD5E9687ADBD19F764F2E0E811',NULL,NULL),
(26822,7,3,5,NULL,'283E8D77ECF7060BE6347BE4EB99C7C7','2B05F6D746C0C6CC7EF79450B309E595','91003668C245D14ECD8DF094E065E06B',NULL,NULL),
(26899,7,3,5,NULL,'F462CD2FE4EA3EADF875308FDBB18C99','3551EF0028B51E92170559BD25644B03','8368EFC2021329110A16339D298200D4',NULL,NULL),
(26972,7,3,5,NULL,'797ECC19662DCBD5090A4481173F1D26','6E212DEF6A0124A3D9AD07F5E322F7AE','341CFEFE3D72ACA9A4407DC535DED66A',NULL,NULL),
(28153,8,0,1,NULL,NULL,'DD626517CC6D31932B479934CCDC0ABF',NULL,NULL,NULL),
(30706,8,1,5,NULL,NULL,'BB6D9866FE4A19A568015198783003FC',NULL,NULL,NULL),
(30993,8,2,0,NULL,NULL,'2BAD61655ABC2FC3D04893B536403A91',NULL,NULL,NULL),
(31229,8,2,0,NULL,NULL,'8A46F23670309F2AAE85C9A47276382B',NULL,NULL,NULL),
(31429,8,2,0,NULL,NULL,'7795A507AF9DC3525EFF724FEE17E70C',NULL,NULL,NULL),
(31478,8,2,0,NULL,NULL,'7973A8D54BDB8B798D9297B096E771EF',NULL,NULL,NULL),
(32305,8,2,5,NULL,NULL,'21F5A6FC7AD89FBF411FDA8B8738186A',NULL,NULL,NULL),
(32494,8,2,5,NULL,NULL,'58984ACE04919401835C61309A848F8A',NULL,NULL,NULL),
(32580,8,2,5,NULL,NULL,'87C2FAA0D7931BF016299025C0DDCA14',NULL,NULL,NULL),
(32638,8,2,5,NULL,NULL,'5D07ECE7D4A867DDDE615DAD22B76D4E',NULL,NULL,NULL),
(32722,8,2,5,NULL,NULL,'1A09BE1D38A122586B4931BECCEAD4AA',NULL,NULL,NULL),
(32750,8,2,5,NULL,NULL,'C5CB669F5A5B237D1355430877173207','EF1F4E4D099EA2A81FD4C0DEBC1E7086',NULL,NULL),
(32978,8,2,5,NULL,NULL,'76AE2EA03E525D97F5688843F5489000','1852C1F847E795D6EB45278CD433F339',NULL,NULL),
(33369,8,3,0,NULL,NULL,'5986AC18B04D3C403F56A0CF8C4F0A14','F5A849C70A1054F07EA3AB833EBF6671',NULL,NULL),
(33528,8,3,0,NULL,NULL,'0ECE033CA9B11D92F7D2792C785B47DF',NULL,NULL,NULL),
(33724,8,3,0,NULL,NULL,'38F7BBCF284939DD20E8C64CDBF9FE77',NULL,NULL,NULL),
(33775,8,3,0,NULL,NULL,'B826300A8449ED0F6EF16EA747FA2D2E','354D2DE619D124EE1398F76B0436FCFC',NULL,NULL),
(33941,8,3,0,NULL,NULL,'88AF1A36D2770D0A6CA086497096A889',NULL,NULL,NULL),
(34220,8,3,0,NULL,NULL,'B5E35B976C6BAF82505700E7D9666A2C',NULL,NULL,NULL),
(34601,8,3,0,NULL,NULL,'0D7DF38F725FABA4F009257799A10563',NULL,NULL,NULL),
(34769,8,3,0,NULL,NULL,'93F9B9AF6397E3E4EED94D36D16907D2',NULL,NULL,NULL),
(34963,8,3,0,NULL,NULL,'7BA50C879C5D04221423B02AC3603A11','C5658A17E702163447BAAAE46D130A1B',NULL,NULL),
(35249,8,3,7,NULL,NULL,'C7B11F9AE9FF1409F5582902B3D10D1C',NULL,NULL,NULL),
(35284,8,3,7,NULL,NULL,'EA3818E7DCFD2009DBFC83EE3C1E4F1B','A6201B0AC5A73D13AB2FDCC79BB252AF',NULL,NULL),
(35435,8,3,7,NULL,NULL,'BB397A92FE23740EA52FC2B5BA2EC8E0','8FE657C14A46BCDB2CE6DA37E430450E',NULL,NULL),
(35662,8,3,7,NULL,NULL,'578BC94870C278CB6962F30E6DC203BB','5966016C368ED9F7AAB603EE6703081C',NULL,NULL),
(36753,9,0,2,NULL,NULL,'386FDE8559B5EAD67B791B490B200B88',NULL,NULL,NULL),
(36839,9,0,2,NULL,NULL,'356EB4412B8EFCF72E3AF50D5181D529',NULL,NULL,NULL),
(36949,9,0,2,NULL,NULL,'51C074CD8A09A75384B9B44188C56981',NULL,NULL,NULL);
/*!40000 ALTER TABLE `build_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ip_banned`
--

DROP TABLE IF EXISTS `ip_banned`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ip_banned` (
  `ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `bandate` int(10) unsigned NOT NULL,
  `unbandate` int(10) unsigned NOT NULL,
  `bannedby` varchar(50) NOT NULL DEFAULT '[Console]',
  `banreason` varchar(255) NOT NULL DEFAULT 'no reason',
  PRIMARY KEY (`ip`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Banned IPs';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ip_banned`
--

LOCK TABLES `ip_banned` WRITE;
/*!40000 ALTER TABLE `ip_banned` DISABLE KEYS */;
/*!40000 ALTER TABLE `ip_banned` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `logs`
--

DROP TABLE IF EXISTS `logs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `logs` (
  `time` int(10) unsigned NOT NULL,
  `realm` int(10) unsigned NOT NULL,
  `type` varchar(250) NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `string` text CHARACTER SET latin1
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs`
--

LOCK TABLES `logs` WRITE;
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
/*!40000 ALTER TABLE `logs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `logs_ip_actions`
--

DROP TABLE IF EXISTS `logs_ip_actions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `logs_ip_actions` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique Identifier',
  `account_id` int(10) unsigned NOT NULL COMMENT 'Account ID',
  `character_guid` bigint(20) unsigned NOT NULL COMMENT 'Character Guid',
  `type` tinyint(3) unsigned NOT NULL,
  `ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `systemnote` text COMMENT 'Notes inserted by system',
  `unixtime` int(10) unsigned NOT NULL COMMENT 'Unixtime',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Timestamp',
  `comment` text COMMENT 'Allows users to add a comment',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Used to log ips of individual actions';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs_ip_actions`
--

LOCK TABLES `logs_ip_actions` WRITE;
/*!40000 ALTER TABLE `logs_ip_actions` DISABLE KEYS */;
/*!40000 ALTER TABLE `logs_ip_actions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_account_permissions`
--

DROP TABLE IF EXISTS `rbac_account_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_account_permissions` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `granted` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`permissionId`,`realmId`),
  KEY `fk__rbac_account_roles__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__rbac_account_permissions__account` FOREIGN KEY (`accountId`) REFERENCES `account` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_account_roles__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Permission relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_account_permissions`
--

LOCK TABLES `rbac_account_permissions` WRITE;
/*!40000 ALTER TABLE `rbac_account_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `rbac_account_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_default_permissions`
--

DROP TABLE IF EXISTS `rbac_default_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_default_permissions` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'permission id',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`secId`,`permissionId`,`realmId`),
  KEY `fk__rbac_default_permissions__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__rbac_default_permissions__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Default permission to assign to different account security levels';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_default_permissions`
--

LOCK TABLES `rbac_default_permissions` WRITE;
/*!40000 ALTER TABLE `rbac_default_permissions` DISABLE KEYS */;
INSERT INTO `rbac_default_permissions` VALUES
(3,192,-1),
(2,193,-1),
(1,194,-1),
(0,195,-1);
/*!40000 ALTER TABLE `rbac_default_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_linked_permissions`
--

DROP TABLE IF EXISTS `rbac_linked_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_linked_permissions` (
  `id` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `linkedId` int(10) unsigned NOT NULL COMMENT 'Linked Permission id',
  PRIMARY KEY (`id`,`linkedId`),
  KEY `fk__rbac_linked_permissions__rbac_permissions1` (`id`),
  KEY `fk__rbac_linked_permissions__rbac_permissions2` (`linkedId`),
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions1` FOREIGN KEY (`id`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions2` FOREIGN KEY (`linkedId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Permission - Linked Permission relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_linked_permissions`
--

LOCK TABLES `rbac_linked_permissions` WRITE;
/*!40000 ALTER TABLE `rbac_linked_permissions` DISABLE KEYS */;
INSERT INTO `rbac_linked_permissions` VALUES
(192,21),
(192,42),
(192,43),
(192,193),
(192,196),
(192,776),
(192,778),
(192,779),
(192,780),
(192,781),
(192,782),
(192,783),
(192,784),
(192,785),
(192,786),
(192,787),
(192,788),
(192,789),
(192,790),
(192,791),
(192,792),
(192,793),
(192,794),
(192,835),
(192,844),
(192,845),
(192,846),
(192,847),
(192,848),
(192,849),
(192,850),
(192,851),
(192,853),
(192,854),
(193,48),
(193,194),
(193,197),
(194,1),
(194,2),
(194,11),
(194,12),
(194,13),
(194,14),
(194,15),
(194,16),
(194,17),
(194,18),
(194,19),
(194,20),
(194,22),
(194,23),
(194,25),
(194,26),
(194,27),
(194,28),
(194,29),
(194,30),
(194,31),
(194,32),
(194,33),
(194,34),
(194,35),
(194,36),
(194,37),
(194,38),
(194,39),
(194,40),
(194,41),
(194,44),
(194,46),
(194,47),
(194,51),
(194,195),
(194,198),
(194,632),
(194,798),
(195,3),
(195,4),
(195,5),
(195,6),
(195,24),
(195,49),
(195,199),
(196,10),
(196,200),
(196,201),
(196,208),
(196,212),
(196,213),
(196,214),
(196,215),
(196,216),
(196,226),
(196,227),
(196,230),
(196,231),
(196,233),
(196,234),
(196,235),
(196,238),
(196,239),
(196,240),
(196,241),
(196,242),
(196,243),
(196,244),
(196,245),
(196,246),
(196,247),
(196,248),
(196,249),
(196,250),
(196,251),
(196,252),
(196,253),
(196,254),
(196,255),
(196,256),
(196,257),
(196,258),
(196,259),
(196,260),
(196,261),
(196,262),
(196,264),
(196,265),
(196,266),
(196,267),
(196,268),
(196,269),
(196,270),
(196,271),
(196,272),
(196,279),
(196,280),
(196,283),
(196,287),
(196,288),
(196,289),
(196,290),
(196,291),
(196,292),
(196,293),
(196,294),
(196,295),
(196,296),
(196,297),
(196,298),
(196,299),
(196,302),
(196,303),
(196,304),
(196,305),
(196,306),
(196,309),
(196,310),
(196,314),
(196,319),
(196,320),
(196,321),
(196,322),
(196,323),
(196,324),
(196,325),
(196,326),
(196,327),
(196,328),
(196,329),
(196,330),
(196,331),
(196,335),
(196,336),
(196,337),
(196,339),
(196,340),
(196,341),
(196,342),
(196,343),
(196,344),
(196,345),
(196,346),
(196,347),
(196,348),
(196,349),
(196,350),
(196,351),
(196,352),
(196,353),
(196,354),
(196,355),
(196,356),
(196,357),
(196,358),
(196,359),
(196,360),
(196,361),
(196,362),
(196,363),
(196,364),
(196,365),
(196,366),
(196,373),
(196,375),
(196,400),
(196,401),
(196,402),
(196,403),
(196,404),
(196,405),
(196,406),
(196,407),
(196,417),
(196,418),
(196,419),
(196,420),
(196,421),
(196,422),
(196,423),
(196,424),
(196,425),
(196,426),
(196,427),
(196,428),
(196,429),
(196,434),
(196,435),
(196,436),
(196,437),
(196,438),
(196,439),
(196,440),
(196,441),
(196,442),
(196,443),
(196,444),
(196,445),
(196,446),
(196,447),
(196,448),
(196,449),
(196,450),
(196,451),
(196,452),
(196,453),
(196,454),
(196,455),
(196,456),
(196,457),
(196,458),
(196,459),
(196,461),
(196,463),
(196,464),
(196,465),
(196,472),
(196,473),
(196,474),
(196,475),
(196,476),
(196,477),
(196,478),
(196,488),
(196,489),
(196,491),
(196,492),
(196,493),
(196,495),
(196,497),
(196,498),
(196,499),
(196,500),
(196,502),
(196,503),
(196,505),
(196,508),
(196,511),
(196,513),
(196,514),
(196,516),
(196,519),
(196,522),
(196,523),
(196,526),
(196,527),
(196,529),
(196,530),
(196,533),
(196,535),
(196,536),
(196,537),
(196,538),
(196,539),
(196,540),
(196,541),
(196,556),
(196,581),
(196,582),
(196,592),
(196,593),
(196,596),
(196,602),
(196,603),
(196,604),
(196,605),
(196,606),
(196,607),
(196,608),
(196,609),
(196,610),
(196,611),
(196,612),
(196,613),
(196,615),
(196,616),
(196,617),
(196,618),
(196,619),
(196,620),
(196,621),
(196,623),
(196,624),
(196,625),
(196,626),
(196,627),
(196,628),
(196,629),
(196,630),
(196,631),
(196,633),
(196,634),
(196,635),
(196,636),
(196,637),
(196,638),
(196,639),
(196,640),
(196,641),
(196,642),
(196,643),
(196,644),
(196,645),
(196,646),
(196,647),
(196,648),
(196,649),
(196,650),
(196,651),
(196,652),
(196,653),
(196,654),
(196,655),
(196,656),
(196,657),
(196,658),
(196,659),
(196,660),
(196,661),
(196,663),
(196,665),
(196,666),
(196,667),
(196,668),
(196,669),
(196,670),
(196,671),
(196,672),
(196,673),
(196,674),
(196,675),
(196,676),
(196,677),
(196,678),
(196,679),
(196,680),
(196,681),
(196,682),
(196,683),
(196,684),
(196,685),
(196,686),
(196,687),
(196,688),
(196,689),
(196,690),
(196,691),
(196,693),
(196,694),
(196,695),
(196,696),
(196,697),
(196,698),
(196,699),
(196,700),
(196,701),
(196,702),
(196,703),
(196,704),
(196,705),
(196,706),
(196,707),
(196,708),
(196,709),
(196,710),
(196,711),
(196,712),
(196,713),
(196,714),
(196,715),
(196,716),
(196,717),
(196,718),
(196,719),
(196,721),
(196,722),
(196,723),
(196,724),
(196,725),
(196,726),
(196,727),
(196,728),
(196,729),
(196,730),
(196,733),
(196,734),
(196,735),
(196,736),
(196,738),
(196,739),
(196,753),
(196,757),
(196,773),
(196,777),
(196,809),
(196,817),
(196,825),
(196,829),
(196,830),
(196,831),
(196,832),
(196,833),
(196,836),
(196,837),
(196,838),
(196,839),
(196,840),
(196,842),
(196,843),
(196,866),
(196,869),
(196,872),
(197,232),
(197,236),
(197,237),
(197,273),
(197,274),
(197,275),
(197,276),
(197,277),
(197,284),
(197,285),
(197,286),
(197,301),
(197,311),
(197,387),
(197,388),
(197,389),
(197,390),
(197,391),
(197,392),
(197,393),
(197,394),
(197,395),
(197,396),
(197,397),
(197,398),
(197,399),
(197,479),
(197,480),
(197,481),
(197,482),
(197,485),
(197,486),
(197,487),
(197,494),
(197,506),
(197,509),
(197,510),
(197,517),
(197,518),
(197,521),
(197,542),
(197,543),
(197,550),
(197,558),
(197,568),
(197,571),
(197,572),
(197,573),
(197,574),
(197,575),
(197,576),
(197,577),
(197,578),
(197,579),
(197,580),
(197,583),
(197,584),
(197,585),
(197,586),
(197,587),
(197,588),
(197,589),
(197,590),
(197,591),
(197,594),
(197,595),
(197,601),
(197,761),
(197,762),
(197,763),
(197,764),
(197,765),
(197,766),
(197,767),
(197,768),
(197,769),
(197,770),
(197,771),
(197,772),
(197,774),
(197,805),
(197,811),
(197,813),
(197,819),
(197,821),
(197,827),
(197,856),
(197,857),
(197,858),
(197,859),
(197,860),
(197,865),
(198,218),
(198,300),
(198,312),
(198,315),
(198,316),
(198,317),
(198,318),
(198,367),
(198,368),
(198,369),
(198,370),
(198,371),
(198,372),
(198,374),
(198,376),
(198,377),
(198,378),
(198,379),
(198,380),
(198,381),
(198,382),
(198,384),
(198,385),
(198,386),
(198,408),
(198,409),
(198,410),
(198,411),
(198,412),
(198,413),
(198,414),
(198,415),
(198,416),
(198,430),
(198,431),
(198,432),
(198,433),
(198,462),
(198,466),
(198,467),
(198,468),
(198,469),
(198,470),
(198,471),
(198,483),
(198,484),
(198,490),
(198,504),
(198,512),
(198,515),
(198,520),
(198,524),
(198,528),
(198,531),
(198,532),
(198,544),
(198,545),
(198,547),
(198,548),
(198,549),
(198,551),
(198,552),
(198,553),
(198,554),
(198,555),
(198,557),
(198,559),
(198,560),
(198,561),
(198,562),
(198,563),
(198,564),
(198,565),
(198,566),
(198,567),
(198,569),
(198,570),
(198,597),
(198,598),
(198,599),
(198,600),
(198,737),
(198,740),
(198,741),
(198,742),
(198,799),
(198,800),
(198,801),
(198,802),
(198,803),
(198,804),
(198,806),
(198,807),
(198,808),
(198,810),
(198,812),
(198,814),
(198,815),
(198,816),
(198,818),
(198,820),
(198,822),
(198,823),
(198,824),
(198,826),
(198,828),
(198,834),
(198,852),
(198,855),
(198,868),
(199,207),
(199,209),
(199,210),
(199,211),
(199,217),
(199,221),
(199,222),
(199,223),
(199,225),
(199,263),
(199,496),
(199,501),
(199,507),
(199,525),
(199,534),
(199,797);
/*!40000 ALTER TABLE `rbac_linked_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_permissions`
--

DROP TABLE IF EXISTS `rbac_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_permissions` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Permission id',
  `name` varchar(100) NOT NULL COMMENT 'Permission name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Permission List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_permissions`
--

LOCK TABLES `rbac_permissions` WRITE;
/*!40000 ALTER TABLE `rbac_permissions` DISABLE KEYS */;
INSERT INTO `rbac_permissions` VALUES
(1,'Instant logout'),
(2,'Skip Queue'),
(3,'Join Normal Battleground'),
(4,'Join Random Battleground'),
(5,'Join Arenas'),
(6,'Join Dungeon Finder'),
(10,'Use character templates'),
(11,'Log GM trades'),
(12,'Skip character creation demon hunter min level check'),
(13,'Skip Instance required bosses check'),
(14,'Skip character creation team mask check'),
(15,'Skip character creation class mask check'),
(16,'Skip character creation race mask check'),
(17,'Skip character creation reserved name check'),
(18,'Skip character creation death knight min level check'),
(19,'Skip needed requirements to use channel check'),
(20,'Skip disable map check'),
(21,'Skip reset talents when used more than allowed check'),
(22,'Skip spam chat check'),
(23,'Skip over-speed ping check'),
(24,'Two side faction characters on the same account'),
(25,'Allow say chat between factions'),
(26,'Allow channel chat between factions'),
(27,'Two side mail interaction'),
(28,'See two side who list'),
(29,'Add friends of other faction'),
(30,'Save character without delay with .save command'),
(31,'Use params with .unstuck command'),
(32,'Can be assigned tickets with .assign ticket command'),
(33,'Notify if a command was not found'),
(34,'Check if should appear in list using .gm ingame command'),
(35,'See all security levels with who command'),
(36,'Filter whispers'),
(37,'Use staff badge in chat'),
(38,'Resurrect with full Health Points'),
(39,'Restore saved gm setting states'),
(40,'Allows to add a gm to friend list'),
(41,'Use Config option START_GM_LEVEL to assign new character level'),
(42,'Allows to use CMSG_WORLD_TELEPORT opcode'),
(43,'Allows to use CMSG_WHOIS opcode'),
(44,'Receive global GM messages/texts'),
(45,'Join channels without announce'),
(46,'Change channel settings without being channel moderator'),
(47,'Enables lower security than target check'),
(48,'Enable IP, Last Login and EMail output in pinfo'),
(49,'Forces to enter the email for confirmation on password change'),
(50,'Allow user to check his own email with .account'),
(51,'Allow trading between factions'),
(192,'Role: Sec Level Administrator'),
(193,'Role: Sec Level Gamemaster'),
(194,'Role: Sec Level Moderator'),
(195,'Role: Sec Level Player'),
(196,'Role: Administrator Commands'),
(197,'Role: Gamemaster Commands'),
(198,'Role: Moderator Commands'),
(199,'Role: Player Commands'),
(200,'Command: rbac'),
(201,'Command: rbac account'),
(202,'Command: rbac account list'),
(203,'Command: rbac account grant'),
(204,'Command: rbac account deny'),
(205,'Command: rbac account revoke'),
(206,'Command: rbac list'),
(207,'Command: battlenetaccount'),
(208,'Command: battlenetaccount create'),
(209,'Command: battlenetaccount lock country'),
(210,'Command: battlenetaccount lock ip'),
(211,'Command: battlenetaccount password'),
(212,'Command: battlenetaccount set'),
(213,'Command: battlenetaccount set password'),
(214,'Command: bnetaccount link'),
(215,'Command: bnetaccount unlink'),
(216,'Command: bnetaccount gameaccountcreate'),
(217,'Command: account'),
(218,'Command: account addon'),
(219,'Command: account create'),
(220,'Command: account delete'),
(221,'Command: account lock'),
(222,'Command: account lock country'),
(223,'Command: account lock ip'),
(224,'Command: account onlinelist'),
(225,'Command: account password'),
(226,'Command: account set'),
(227,'Command: account set addon'),
(228,'Command: account set gmlevel'),
(229,'Command: account set password'),
(230,'Command: achievement'),
(231,'Command: achievement add'),
(232,'Command: arena'),
(233,'Command: arena captain'),
(234,'Command: arena create'),
(235,'Command: arena disband'),
(236,'Command: arena info'),
(237,'Command: arena lookup'),
(238,'Command: arena rename'),
(239,'Command: ban'),
(240,'Command: ban account'),
(241,'Command: ban character'),
(242,'Command: ban ip'),
(243,'Command: ban playeraccount'),
(244,'Command: baninfo'),
(245,'Command: baninfo account'),
(246,'Command: baninfo character'),
(247,'Command: baninfo ip'),
(248,'Command: banlist'),
(249,'Command: banlist account'),
(250,'Command: banlist character'),
(251,'Command: banlist ip'),
(252,'Command: unban'),
(253,'Command: unban account'),
(254,'Command: unban character'),
(255,'Command: unban ip'),
(256,'Command: unban playeraccount'),
(257,'Command: bf'),
(258,'Command: bf start'),
(259,'Command: bf stop'),
(260,'Command: bf switch'),
(261,'Command: bf timer'),
(262,'Command: bf enable'),
(263,'Command: account email'),
(264,'Command: account set sec'),
(265,'Command: account set sec email'),
(266,'Command: account set sec regmail'),
(267,'Command: cast'),
(268,'Command: cast back'),
(269,'Command: cast dist'),
(270,'Command: cast self'),
(271,'Command: cast target'),
(272,'Command: cast dest'),
(273,'Command: character'),
(274,'Command: character customize'),
(275,'Command: character changefaction'),
(276,'Command: character changerace'),
(277,'Command: character deleted'),
(279,'Command: character deleted list'),
(280,'Command: character deleted restore'),
(283,'Command: character level'),
(284,'Command: character rename'),
(285,'Command: character reputation'),
(286,'Command: character titles'),
(287,'Command: levelup'),
(288,'Command: pdump'),
(289,'Command: pdump load'),
(290,'Command: pdump write'),
(291,'Command: cheat'),
(292,'Command: cheat casttime'),
(293,'Command: cheat cooldown'),
(294,'Command: cheat explore'),
(295,'Command: cheat god'),
(296,'Command: cheat power'),
(297,'Command: cheat status'),
(298,'Command: cheat taxi'),
(299,'Command: cheat waterwalk'),
(300,'Command: debug'),
(301,'Command: debug anim'),
(302,'Command: debug areatriggers'),
(303,'Command: debug arena'),
(304,'Command: debug bg'),
(305,'Command: debug entervehicle'),
(306,'Command: debug getitemstate'),
(309,'Command: debug combat'),
(310,'Command: debug itemexpire'),
(311,'Command: debug lootrecipient'),
(312,'Command: debug los'),
(314,'Command: debug moveflags'),
(315,'Command: debug play'),
(316,'Command: debug play cinematics'),
(317,'Command: debug play movie'),
(318,'Command: debug play sound'),
(319,'Command: debug send'),
(320,'Command: debug send buyerror'),
(321,'Command: debug send channelnotify'),
(322,'Command: debug send chatmessage'),
(323,'Command: debug send equiperror'),
(324,'Command: debug send largepacket'),
(325,'Command: debug send opcode'),
(326,'Command: debug send qinvalidmsg'),
(327,'Command: debug send qpartymsg'),
(328,'Command: debug send sellerror'),
(329,'Command: debug send setphaseshift'),
(330,'Command: debug send spellfail'),
(331,'Command: debug setaurastate'),
(335,'Command: debug setvid'),
(336,'Command: debug spawnvehicle'),
(337,'Command: debug threat'),
(339,'Command: debug worldstate'),
(340,'Command: wpgps'),
(341,'Command: deserter'),
(342,'Command: deserter bg'),
(343,'Command: deserter bg add'),
(344,'Command: deserter bg remove'),
(345,'Command: deserter instance'),
(346,'Command: deserter instance add'),
(347,'Command: deserter instance remove'),
(348,'Command: disable'),
(349,'Command: disable add'),
(350,'Command: disable add criteria'),
(351,'Command: disable add battleground'),
(352,'Command: disable add map'),
(353,'Command: disable add mmap'),
(354,'Command: disable add outdoorpvp'),
(355,'Command: disable add quest'),
(356,'Command: disable add spell'),
(357,'Command: disable add vmap'),
(358,'Command: disable remove'),
(359,'Command: disable remove criteria'),
(360,'Command: disable remove battleground'),
(361,'Command: disable remove map'),
(362,'Command: disable remove mmap'),
(363,'Command: disable remove outdoorpvp'),
(364,'Command: disable remove quest'),
(365,'Command: disable remove spell'),
(366,'Command: disable remove vmap'),
(367,'Command: event info'),
(368,'Command: event activelist'),
(369,'Command: event start'),
(370,'Command: event stop'),
(371,'Command: gm'),
(372,'Command: gm chat'),
(373,'Command: gm fly'),
(374,'Command: gm ingame'),
(375,'Command: gm list'),
(376,'Command: gm visible'),
(377,'Command: go'),
(378,'Command: go creature'),
(379,'Command: go graveyard'),
(380,'Command: go grid'),
(381,'Command: go object'),
(382,'Command: go taxinode'),
(384,'Command: go trigger'),
(385,'Command: go xyz'),
(386,'Command: go zonexy'),
(387,'Command: gobject'),
(388,'Command: gobject activate'),
(389,'Command: gobject add'),
(390,'Command: gobject add temp'),
(391,'Command: gobject delete'),
(392,'Command: gobject info'),
(393,'Command: gobject move'),
(394,'Command: gobject near'),
(395,'Command: gobject set'),
(396,'Command: gobject set phase'),
(397,'Command: gobject set state'),
(398,'Command: gobject target'),
(399,'Command: gobject turn'),
(400,'debug transport'),
(401,'Command: guild'),
(402,'Command: guild create'),
(403,'Command: guild delete'),
(404,'Command: guild invite'),
(405,'Command: guild uninvite'),
(406,'Command: guild rank'),
(407,'Command: guild rename'),
(408,'Command: honor'),
(409,'Command: honor add'),
(410,'Command: honor add kill'),
(411,'Command: honor update'),
(412,'Command: instance'),
(413,'Command: instance listbinds'),
(414,'Command: instance unbind'),
(415,'Command: instance stats'),
(416,'Command: instance savedata'),
(417,'Command: learn'),
(418,'Command: learn all'),
(419,'Command: learn all my'),
(420,'Command: learn all my class'),
(421,'Command: learn all my pettalents'),
(422,'Command: learn all my spells'),
(423,'Command: learn all my talents'),
(424,'Command: learn all gm'),
(425,'Command: learn all crafts'),
(426,'Command: learn all default'),
(427,'Command: learn all lang'),
(428,'Command: learn all recipes'),
(429,'Command: unlearn'),
(430,'Command: lfg'),
(431,'Command: lfg player'),
(432,'Command: lfg group'),
(433,'Command: lfg queue'),
(434,'Command: lfg clean'),
(435,'Command: lfg options'),
(436,'Command: list'),
(437,'Command: list creature'),
(438,'Command: list item'),
(439,'Command: list object'),
(440,'Command: list auras'),
(441,'Command: list mail'),
(442,'Command: lookup'),
(443,'Command: lookup area'),
(444,'Command: lookup creature'),
(445,'Command: lookup event'),
(446,'Command: lookup faction'),
(447,'Command: lookup item'),
(448,'Command: lookup itemset'),
(449,'Command: lookup object'),
(450,'Command: lookup quest'),
(451,'Command: lookup player'),
(452,'Command: lookup player ip'),
(453,'Command: lookup player account'),
(454,'Command: lookup player email'),
(455,'Command: lookup skill'),
(456,'Command: lookup spell'),
(457,'Command: lookup spell id'),
(458,'Command: lookup taxinode'),
(459,'Command: lookup tele'),
(460,'Command: lookup title'),
(461,'Command: lookup map'),
(462,'Command: announce'),
(463,'Command: channel'),
(464,'Command: channel set'),
(465,'Command: channel set ownership'),
(466,'Command: gmannounce'),
(467,'Command: gmnameannounce'),
(468,'Command: gmnotify'),
(469,'Command: nameannounce'),
(470,'Command: notify'),
(471,'Command: whispers'),
(472,'Command: group'),
(473,'Command: group leader'),
(474,'Command: group disband'),
(475,'Command: group remove'),
(476,'Command: group join'),
(477,'Command: group list'),
(478,'Command: group summon'),
(479,'Command: pet'),
(480,'Command: pet create'),
(481,'Command: pet learn'),
(482,'Command: pet unlearn'),
(483,'Command: send'),
(484,'Command: send items'),
(485,'Command: send mail'),
(486,'Command: send message'),
(487,'Command: send money'),
(488,'Command: additem'),
(489,'Command: additemset'),
(490,'Command: appear'),
(491,'Command: aura'),
(492,'Command: bank'),
(493,'Command: bindsight'),
(494,'Command: combatstop'),
(495,'Command: cometome'),
(496,'Command: commands'),
(497,'Command: cooldown'),
(498,'Command: damage'),
(499,'Command: dev'),
(500,'Command: die'),
(501,'Command: dismount'),
(502,'Command: distance'),
(503,'Command: flusharenapoints'),
(504,'Command: freeze'),
(505,'Command: gps'),
(506,'Command: guid'),
(507,'Command: help'),
(508,'Command: hidearea'),
(509,'Command: itemmove'),
(510,'Command: kick'),
(511,'Command: linkgrave'),
(512,'Command: listfreeze'),
(513,'Command: maxskill'),
(514,'Command: movegens'),
(515,'Command: mute'),
(516,'Command: neargrave'),
(517,'Command: pinfo'),
(518,'Command: playall'),
(519,'Command: possess'),
(520,'Command: recall'),
(521,'Command: repairitems'),
(522,'Command: respawn'),
(523,'Command: revive'),
(524,'Command: saveall'),
(525,'Command: save'),
(526,'Command: setskill'),
(527,'Command: showarea'),
(528,'Command: summon'),
(529,'Command: unaura'),
(530,'Command: unbindsight'),
(531,'Command: unfreeze'),
(532,'Command: unmute'),
(533,'Command: unpossess'),
(534,'Command: unstuck'),
(535,'Command: wchange'),
(536,'Command: mmap'),
(537,'Command: mmap loadedtiles'),
(538,'Command: mmap loc'),
(539,'Command: mmap path'),
(540,'Command: mmap stats'),
(541,'Command: mmap testarea'),
(542,'Command: morph'),
(543,'Command: demorph'),
(544,'Command: modify'),
(545,'Command: modify arenapoints'),
(547,'Command: modify drunk'),
(548,'Command: modify energy'),
(549,'Command: modify faction'),
(550,'Command: modify gender'),
(551,'Command: modify honor'),
(552,'Command: modify hp'),
(553,'Command: modify mana'),
(554,'Command: modify money'),
(555,'Command: modify mount'),
(556,'Command: modify phase'),
(557,'Command: modify rage'),
(558,'Command: modify reputation'),
(559,'Command: modify runicpower'),
(560,'Command: modify scale'),
(561,'Command: modify speed'),
(562,'Command: modify speed all'),
(563,'Command: modify speed backwalk'),
(564,'Command: modify speed fly'),
(565,'Command: modify speed walk'),
(566,'Command: modify speed swim'),
(567,'Command: modify spell'),
(568,'Command: modify standstate'),
(569,'Command: modify talentpoints'),
(570,'Command: npc'),
(571,'Command: npc add'),
(572,'Command: npc add formation'),
(573,'Command: npc add item'),
(574,'Command: npc add move'),
(575,'Command: npc add temp'),
(576,'Command: npc add delete'),
(577,'Command: npc add delete item'),
(578,'Command: npc add follow'),
(579,'Command: npc add follow stop'),
(580,'Command: npc set'),
(581,'Command: npc set allowmove'),
(582,'Command: npc set entry'),
(583,'Command: npc set factionid'),
(584,'Command: npc set flag'),
(585,'Command: npc set level'),
(586,'Command: npc set link'),
(587,'Command: npc set model'),
(588,'Command: npc set movetype'),
(589,'Command: npc set phase'),
(590,'Command: npc set spawndist'),
(591,'Command: npc set spawntime'),
(592,'Command: npc set data'),
(593,'Command: npc info'),
(594,'Command: npc near'),
(595,'Command: npc move'),
(596,'Command: npc playemote'),
(597,'Command: npc say'),
(598,'Command: npc textemote'),
(599,'Command: npc whisper'),
(600,'Command: npc yell'),
(601,'Command: npc tame'),
(602,'Command: quest'),
(603,'Command: quest add'),
(604,'Command: quest complete'),
(605,'Command: quest remove'),
(606,'Command: quest reward'),
(607,'Command: reload'),
(608,'Command: reload access_requirement'),
(609,'Command: reload criteria_data'),
(610,'Command: reload achievement_reward'),
(611,'Command: reload all'),
(612,'Command: reload all achievement'),
(613,'Command: reload all area'),
(615,'Command: reload all gossips'),
(616,'Command: reload all item'),
(617,'Command: reload all locales'),
(618,'Command: reload all loot'),
(619,'Command: reload all npc'),
(620,'Command: reload all quest'),
(621,'Command: reload all scripts'),
(623,'Command: reload areatrigger_involvedrelation'),
(624,'Command: reload areatrigger_tavern'),
(625,'Command: reload areatrigger_teleport'),
(626,'Command: reload auctions'),
(627,'Command: reload autobroadcast'),
(628,'Command: reload command'),
(629,'Command: reload conditions'),
(630,'Command: reload config'),
(631,'Command: reload battleground_template'),
(632,'Command: .mutehistory'),
(633,'Command: reload creature_linked_respawn'),
(634,'Command: reload creature_loot_template'),
(635,'Command: reload creature_onkill_reputation'),
(636,'Command: reload creature_questender'),
(637,'Command: reload creature_queststarter'),
(638,'Command: reload creature_summon_groups'),
(639,'Command: reload creature_template'),
(640,'Command: reload creature_text'),
(641,'Command: reload disables'),
(642,'Command: reload disenchant_loot_template'),
(643,'Command: reload event_scripts'),
(644,'Command: reload fishing_loot_template'),
(645,'Command: reload game_graveyard_zone'),
(646,'Command: reload game_tele'),
(647,'Command: reload gameobject_questender'),
(648,'Command: reload gameobject_loot_template'),
(649,'Command: reload gameobject_queststarter'),
(650,'Command: reload support'),
(651,'Command: reload gossip_menu'),
(652,'Command: reload gossip_menu_option'),
(653,'Command: reload item_random_bonus_list_template'),
(654,'Command: reload item_loot_template'),
(655,'Command: reload item_set_names'),
(656,'Command: reload lfg_dungeon_rewards'),
(657,'Command: reload locales_achievement_reward'),
(658,'Command: reload locales_creature'),
(659,'Command: reload locales_creature_text'),
(660,'Command: reload locales_gameobject'),
(661,'Command: reload locales_gossip_menu_option'),
(663,'Command: reload locales_item_set_name'),
(665,'Command: reload locales_page_text'),
(666,'Command: reload locales_points_of_interest'),
(667,'Command: reload quest_locale'),
(668,'Command: reload mail_level_reward'),
(669,'Command: reload mail_loot_template'),
(670,'Command: reload milling_loot_template'),
(671,'Command: reload npc_spellclick_spells'),
(672,'Command: reload npc_trainer'),
(673,'Command: reload npc_vendor'),
(674,'Command: reload page_text'),
(675,'Command: reload pickpocketing_loot_template'),
(676,'Command: reload points_of_interest'),
(677,'Command: reload prospecting_loot_template'),
(678,'Command: reload quest_poi'),
(679,'Command: reload quest_template'),
(680,'Command: reload rbac'),
(681,'Command: reload reference_loot_template'),
(682,'Command: reload reserved_name'),
(683,'Command: reload reputation_reward_rate'),
(684,'Command: reload reputation_spillover_template'),
(685,'Command: reload skill_discovery_template'),
(686,'Command: reload skill_extra_item_template'),
(687,'Command: reload skill_fishing_base_level'),
(688,'Command: reload skinning_loot_template'),
(689,'Command: reload smart_scripts'),
(690,'Command: reload spell_required'),
(691,'Command: reload spell_area'),
(693,'Command: reload spell_group'),
(694,'Command: reload spell_learn_spell'),
(695,'Command: reload spell_loot_template'),
(696,'Command: reload spell_linked_spell'),
(697,'Command: reload spell_pet_auras'),
(698,'Command: character changeaccount'),
(699,'Command: reload spell_proc'),
(700,'Command: reload spell_scripts'),
(701,'Command: reload spell_target_position'),
(702,'Command: reload spell_threats'),
(703,'Command: reload spell_group_stack_rules'),
(704,'Command: reload trinity_string'),
(705,'Command: reload warden_action'),
(706,'Command: reload waypoint_scripts'),
(707,'Command: reload waypoint_data'),
(708,'Command: reload vehicle_accessory'),
(709,'Command: reload vehicle_template_accessory'),
(710,'Command: reset'),
(711,'Command: reset achievements'),
(712,'Command: reset honor'),
(713,'Command: reset level'),
(714,'Command: reset spells'),
(715,'Command: reset stats'),
(716,'Command: reset talents'),
(717,'Command: reset all'),
(718,'Command: server'),
(719,'Command: server corpses'),
(720,'Command: server exit'),
(721,'Command: server idlerestart'),
(722,'Command: server idlerestart cancel'),
(723,'Command: server idleshutdown'),
(724,'Command: server idleshutdown cancel'),
(725,'Command: server info'),
(726,'Command: server plimit'),
(727,'Command: server restart'),
(728,'Command: server restart cancel'),
(729,'Command: server set'),
(730,'Command: server set closed'),
(731,'Command: server set difftime'),
(732,'Command: server set loglevel'),
(733,'Command: server set motd'),
(734,'Command: server shutdown'),
(735,'Command: server shutdown cancel'),
(736,'Command: server motd'),
(737,'Command: tele'),
(738,'Command: tele add'),
(739,'Command: tele del'),
(740,'Command: tele name'),
(741,'Command: tele group'),
(742,'Command: ticket'),
(753,'Command: ticket reset'),
(757,'Command: ticket togglesystem'),
(761,'Command: titles'),
(762,'Command: titles add'),
(763,'Command: titles current'),
(764,'Command: titles remove'),
(765,'Command: titles set'),
(766,'Command: titles set mask'),
(767,'Command: wp'),
(768,'Command: wp add'),
(769,'Command: wp event'),
(770,'Command: wp load'),
(771,'Command: wp modify'),
(772,'Command: wp unload'),
(773,'Command: wp reload'),
(774,'Command: wp show'),
(776,'Command: debug phase'),
(777,'Command: mailbox'),
(778,'Command: ahbot'),
(779,'Command: ahbot items'),
(780,'Command: ahbot items gray'),
(781,'Command: ahbot items white'),
(782,'Command: ahbot items green'),
(783,'Command: ahbot items blue'),
(784,'Command: ahbot items purple'),
(785,'Command: ahbot items orange'),
(786,'Command: ahbot items yellow'),
(787,'Command: ahbot ratio'),
(788,'Command: ahbot ratio alliance'),
(789,'Command: ahbot ratio horde'),
(790,'Command: ahbot ratio neutral'),
(791,'Command: ahbot rebuild'),
(792,'Command: ahbot reload'),
(793,'Command: ahbot status'),
(794,'Command: .guild info'),
(797,'Command: pvpstats'),
(798,'Command: .mod xp'),
(799,'Command: .go bugticket'),
(800,'Command: .go complaintticket'),
(801,'Command: .go suggestionticket'),
(802,'Command: .ticket bug'),
(803,'Command: .ticket complaint'),
(804,'Command: .ticket suggestion'),
(805,'Command: .ticket bug assign'),
(806,'Command: .ticket bug close'),
(807,'Command: .ticket bug closedlist'),
(808,'Command: .ticket bug comment'),
(809,'Command: .ticket bug delete'),
(810,'Command: .ticket bug list'),
(811,'Command: .ticket bug unassign'),
(812,'Command: .ticket bug view'),
(813,'Command: .ticket complaint assign'),
(814,'Command: .ticket complaint close'),
(815,'Command: .ticket complaint closedlist'),
(816,'Command: .ticket complaint comment'),
(817,'Command: .ticket complaint delete'),
(818,'Command: .ticket complaint list'),
(819,'Command: .ticket complaint unassign'),
(820,'Command: .ticket complaint view'),
(821,'Command: .ticket suggestion assign'),
(822,'Command: .ticket suggestion close'),
(823,'Command: .ticket suggestion closedlist'),
(824,'Command: .ticket suggestion comment'),
(825,'Command: .ticket suggestion delete'),
(826,'Command: .ticket suggestion list'),
(827,'Command: .ticket suggestion unassign'),
(828,'Command: .ticket suggestion view'),
(829,'Command: .ticket reset all'),
(830,'Command: .bnetaccount listgameaccounts'),
(831,'Command: .ticket reset bug'),
(832,'Command: .ticket reset complaint'),
(833,'Command: .ticket reset suggestion'),
(834,'Command: go quest'),
(835,'Command: debug loadcells'),
(836,'Command: .debug boundary'),
(837,'Command: npc evade'),
(838,'Command: pet level'),
(839,'Command: server shutdown force'),
(840,'Command: server restart force'),
(841,'Command: .debug neargraveyard'),
(842,'Command: reload character_template'),
(843,'Command: reload quest_greeting'),
(844,'Command: scene'),
(845,'Command: scene debug'),
(846,'Command: scene play'),
(847,'Command: scene play package'),
(848,'Command: scene cancel'),
(849,'Command: list scenes'),
(850,'Command: reload scenes'),
(851,'Command: reload areatrigger_templates'),
(852,'Command: go offset'),
(853,'Command: .reload conversation_template'),
(854,'Command: .debug conversation'),
(855,'Command: debug play music'),
(856,'Command: npc spawngroup'),
(857,'Command: npc despawngroup'),
(858,'Command: gobject spawngroup'),
(859,'Command: gobject despawngroup'),
(860,'Command: list respawns'),
(865,'Command: npc showloot'),
(866,'Command: list spawnpoints'),
(868,'Command: modify power'),
(869,'Command: debug send playerchoice'),
(872,'Command: server debug');
/*!40000 ALTER TABLE `rbac_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `realmcharacters`
--

DROP TABLE IF EXISTS `realmcharacters`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `realmcharacters` (
  `realmid` int(10) unsigned NOT NULL DEFAULT '0',
  `acctid` int(10) unsigned NOT NULL,
  `numchars` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`realmid`,`acctid`),
  KEY `acctid` (`acctid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Realm Character Tracker';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `realmcharacters`
--

LOCK TABLES `realmcharacters` WRITE;
/*!40000 ALTER TABLE `realmcharacters` DISABLE KEYS */;
/*!40000 ALTER TABLE `realmcharacters` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `realmlist`
--

DROP TABLE IF EXISTS `realmlist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `realmlist` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '',
  `address` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localAddress` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localSubnetMask` varchar(255) NOT NULL DEFAULT '255.255.255.0',
  `port` smallint(5) unsigned NOT NULL DEFAULT '8085',
  `icon` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `flag` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `timezone` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `allowedSecurityLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `population` float unsigned NOT NULL DEFAULT '0',
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '36949',
  `Region` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `Battlegroup` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Realm System';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `realmlist`
--

LOCK TABLES `realmlist` WRITE;
/*!40000 ALTER TABLE `realmlist` DISABLE KEYS */;
INSERT INTO `realmlist` VALUES
(1,'Trinity','127.0.0.1','127.0.0.1','255.255.255.0',8085,0,0,1,0,0,36949,1,1);
/*!40000 ALTER TABLE `realmlist` ENABLE KEYS */;
UNLOCK TABLES;

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
-- Dumping data for table `updates`
--

LOCK TABLES `updates` WRITE;
/*!40000 ALTER TABLE `updates` DISABLE KEYS */;
INSERT INTO `updates` VALUES
('2014_10_04_00_auth.sql','C3BC70A6EC381474B7308F442346F1E721176BC6','ARCHIVED','2015-03-21 16:55:52',0),
('2014_10_19_00_auth.sql','7472B490A4F86C9D3DA609CDD3197499CB80C87C','ARCHIVED','2015-03-21 16:55:52',0),
('2014_10_26_00_auth.sql','75CC67ADE2A3B2E54FD57D6B0DCAA8FE50F4EE35','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_03_00_auth.sql','5948C9F286CF0FEA8E241785C0259FF36B73BDC5','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_04_00_auth.sql','3AFC68B2375C2A417DDEA94583C53AFF83DE50DF','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_09_00_auth.sql','B8DD1A7047C0FDDB80344B239343EC33BF1A0D97','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_10_00_auth.sql','8FBA737A1D3FF4631A1E662A5B500A8BD304EC63','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_10_00_auth_from_335.sql','0E3CB119442D09DD88E967015319BBC8DAFBBFE0','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_10_01_auth.sql','327E77A1DA3546D5275AB249915DD57EDD6FDD3D','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_23_00_auth.sql','0BBEB3EB3AED0FEF277A062819B6B2C00084A742','ARCHIVED','2015-03-21 16:55:52',0),
('2014_11_25_00_auth.sql','4F45CDB26BDBB3EE83F1988E3D7818C5926ADC02','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_05_00_auth.sql','6A7BBCEF43111C73A2D2C3CCB6911BE50DE7DD94','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_10_00_auth.sql','821703A96D80F9080074852B5A46E2909C9562EA','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_19_00_auth.sql','44D8E12FFF327AD07878FBDF8D9C16B6B7DCB122','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_20_00_auth.sql','4DAA02AE285C02AE6C82EA2C8B97AC71990F1085','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_25_00_auth.sql','61411930F482BC73FC7FD2C370C811E944F5FF92','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_27_00_auth.sql','CE2E5D2CD82E79C25294539ADED27A1429105B43','ARCHIVED','2015-03-21 16:55:52',0),
('2014_12_28_00_auth.sql','0A913217610E76AFF119C27259737BBC523090E6','ARCHIVED','2015-03-21 16:55:52',0),
('2015_02_22_00_auth.sql','21CCCF8B01252E16CA3D6C9E3E8DAA4C9B28ED6E','ARCHIVED','2015-03-21 16:55:52',0),
('2015_03_01_00_auth.sql','911881E273207FF6182D1FDAC8C85FFAE8F1C852','ARCHIVED','2015-03-21 16:55:52',0),
('2015_03_10_00_auth.sql','2CC8502C11412EFEB5C11BE166761A8754A59009','ARCHIVED','2015-03-21 16:55:52',0),
('2015_03_20_00_auth.sql','B761760804EA73BD297F296C5C1919687DF7191C','ARCHIVED','2015-03-21 16:55:52',0),
('2015_03_20_01_auth.sql','5CCEDF20C8189FB1E8DF064A9F0DDC342841FBF0','ARCHIVED','2015-03-21 16:55:52',0),
('2015_03_20_02_auth.sql','85E4ACD9AA099C0C4AC034575F2BB07D348EAC72','ARCHIVED','2015-03-21 16:56:46',0),
('2015_03_15_00_auth.sql','1D8E107FBEFE5E7F47E09F45240DFF499B77CDED','ARCHIVED','2015-05-02 13:57:57',0),
('2015_03_26_00_auth.sql','34AC8543E6A9C6C832DE58EAB33618EEEF70B9F9','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_04_00_auth.sql','57146B35E54A2EC7869C945034AB078358020311','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_06_00_auth.sql','2A8049DC2923420A002D42FB6F02C2FFCC5CDD22','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_08_00_auth.sql','4D7D8EEF285C982BB676836602266501BEC26764','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_10_00_auth.sql','4AE68FD97A95CEE5143EA20FD33F5D557367AC1F','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_11_00_auth.sql','80A71C8921CFEBB547D264558B6DE27201685B84','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_11_01_auth.sql','3E88183E1A85D11BFD74CF9A32A725C44AE02EEC','ARCHIVED','2015-05-02 13:57:57',0),
('2015_04_21_00_auth.sql','1B3B48DBA06368B985C548D166C515C9DD598CB9','ARCHIVED','2015-05-02 13:57:57',0),
('2015_05_02_00_auth.sql','96AB595E0D2A088750E3F48B0AF0A8A14F3CFE1E','ARCHIVED','2015-05-02 13:57:57',0),
('2015_05_02_01_auth.sql','FB11FB834E488B0FD3AFDABCC1A3113092E7C2E5','ARCHIVED','2015-05-02 13:57:57',0),
('2015_07_02_00_auth.sql','E5EE3842AB9B01851E49B360FBAF6FFEEAB2A8DA','ARCHIVED','2015-07-10 19:30:56',0),
('2015_07_06_00_auth.sql','6D1ADBA496DC6E6D7B3BF887DA8D4D17D3FBACE0','ARCHIVED','2015-07-10 19:30:56',0),
('2015_07_08_00_auth.sql','CB54020AFD1E31742FD8BF9CE16879625E289788','ARCHIVED','2015-07-10 19:30:56',0),
('2015_07_08_01_auth.sql','74D281CB82E0DA36D628BDC7AC797AE5498DB461','ARCHIVED','2015-07-10 19:30:56',0),
('2015_07_16_00_auth.sql','A057E95B5553B6A57A1642FE3FEC8E2E62EDE3C6','ARCHIVED','2015-10-10 08:30:48',0),
('2015_07_29_00_auth.sql','0000FECBC413E96C7C45F303D162E263EFBA7116','ARCHIVED','2015-10-10 08:30:48',0),
('2015_08_26_00_auth.sql','3071C02A2EB7DCBF4CEE10279FEFAB7C29A43A3A','ARCHIVED','2015-10-10 08:30:48',0),
('2015_09_05_00_auth.sql','F765D82B37873FA67447347D5B83C99C159FB452','ARCHIVED','2015-10-10 08:30:48',0),
('2015_09_05_01_auth.sql','97A72DBCBF14D27A1863834A22296905FF276086','ARCHIVED','2015-10-10 08:30:48',0),
('2015_09_09_00_auth.sql','495A0CF1B1C49205D4A5D3C25A4E1EB95616D6B4','ARCHIVED','2015-10-10 08:30:48',0),
('2015_09_15_00_auth.sql','D1FEFDA4C98F30384DF4B64D5A53187303EB5786','ARCHIVED','2015-10-10 08:30:48',0),
('2015_10_09_00_auth.sql','B6D643D444C6AE711503F73B96B6252A852913D6','ARCHIVED','2015-10-10 08:30:48',0),
('2015_10_16_00_auth.sql','366AFFD1088762866091A81CE1EC64138B8B35F1','ARCHIVED','2015-11-08 00:46:02',0),
('2015_10_17_00_auth.sql','AC0D45E905033F42093852D2C4476663BDACCB3D','ARCHIVED','2015-10-17 12:39:12',0),
('2015_11_01_00_auth_2015_08_21_00.sql','C31A9E1D28E11B60BE8F8198637DD51F6D75123F','ARCHIVED','2015-11-01 14:50:26',0),
('2015_11_08_00_auth.sql','0ACDD35EC9745231BCFA701B78056DEF94D0CC53','ARCHIVED','2015-11-08 00:51:45',0),
('2015_11_21_00_auth.sql','575A1D697CC6C7C517F7CCB950988267C99CE7FA','ARCHIVED','2015-11-21 21:25:38',0),
('2015_12_07_00_auth.sql','24A07AC1F38E5D26A3599FC06D29E267418F69F3','ARCHIVED','2015-12-07 20:55:48',0),
('2016_01_13_00_auth.sql','114527BCCB0DE286CBE6FDA3029DD0523D1037FA','ARCHIVED','2016-01-13 21:39:13',0),
('2016_03_22_01_auth_2016_01_13_00_auth.sql','24615CC69B3CD7BB4699874647C35BA86E8A93FD','ARCHIVED','2016-03-22 22:55:13',0),
('2016_03_28_00_auth.sql','BA14D23D81FA24565F04A359090DE86C5E195209','ARCHIVED','2016-03-28 16:49:32',0),
('2016_04_11_00_auth.sql','0ACDD35EC9745231BCFA701B78056DEF94D0CC53','ARCHIVED','2016-04-11 02:24:14',0),
('2016_04_17_00_auth.sql','83399B64D1221B56F73A0FFB51889F11A70521BC','ARCHIVED','2016-04-17 00:22:05',0),
('2016_05_07_00_auth.sql','7E36DCC4F06FCDCDA7155AF3C5EDF8D3A720565F','ARCHIVED','2016-05-07 01:00:21',0),
('2016_05_19_00_auth.sql','FB52E6BF35682CE6FA667B552B551F4FBD72AC30','ARCHIVED','2016-05-19 22:18:06',0),
('2016_07_19_00_auth.sql','D5498F28A1E21F4AD0E0D7C2B96FCF7292C14C4D','ARCHIVED','2016-07-19 14:00:28',0),
('2016_07_19_01_auth.sql','EBFE5D7D7E7CFA0CDA76AC49A1E8D4FA461A12BE','ARCHIVED','2016-07-19 16:06:39',0),
('2016_07_23_00_auth.sql','1048F6A922ACD9BFC2E4518A71AF7037F79A85C4','ARCHIVED','2016-07-23 14:39:21',0),
('2016_07_23_01_auth.sql','5897C7D8B8DE15895286FBCD1535FC75E1B70F62','ARCHIVED','2016-07-23 17:35:11',0),
('2016_07_30_00_auth.sql','0FD4147840F7F02E2F1828A904B269F5B66097E0','ARCHIVED','2016-07-30 15:07:02',0),
('2016_08_07_00_auth.sql','D9DD23851822E32E1312FFABEE2DB721C8651443','ARCHIVED','2016-08-07 15:33:42',0),
('2016_08_11_00_auth.sql','0C79A86A4DFC53746BECF3D8A145482F94AE5FC9','ARCHIVED','2016-08-11 17:02:20',0),
('2016_08_13_00_auth.sql','ED2286C4FF3D80D0F4DEE3D3121BCC15544470BE','ARCHIVED','2016-08-13 01:11:49',0),
('2016_08_26_00_auth.sql','3C566371B6026EFEEA19CD215EC9F02C6DA9EAB3','ARCHIVED','2016-08-26 14:09:52',0),
('2016_08_27_00_auth.sql','65ABEF7ACBCEA974C744ED42F95FBBD29226917B','ARCHIVED','2016-08-27 07:02:45',0),
('2016_08_30_00_auth.sql','E16C19A938FE6370921658D2B713EE28A633FD56','ARCHIVED','2016-08-30 00:00:00',0),
('2016_09_02_00_auth.sql','08932DAC4BDE74D3C39A43DDE404522F23EDD035','ARCHIVED','2016-09-02 00:00:00',0),
('2016_09_03_00_auth_2016_05_11_00_auth.sql','401EFD3586772BDED66B4A944C20A1AC18A22D3A','ARCHIVED','2016-09-03 11:29:38',0),
('2016_09_03_01_auth.sql','08B5ABCB74BBF25A30D37AF639F0EA1B10640673','ARCHIVED','2016-09-03 13:24:32',0),
('2016_09_03_02_auth_2016_06_06_00_auth.sql','A0A8D73A952D0618833416513D53F73A70E7EA25','ARCHIVED','2016-09-03 15:56:50',0),
('2016_09_03_03_auth.sql','9BF1C03EE39B6DC7E817BA46BE7D12A41AFBFDF7','ARCHIVED','2016-09-03 15:56:50',0),
('2016_09_15_00_auth.sql','CD65F822AF1B5B7776E39804D0362F3E34AA6445','ARCHIVED','2016-09-15 16:30:36',0),
('2016_09_21_00_auth.sql','57219A16B88080240EED94CDD41FC2764B8A32C5','ARCHIVED','2016-09-21 17:08:43',0),
('2016_09_25_00_auth.sql','E811EFD8CE92ABEC5B8C02A09E643035939CF96D','ARCHIVED','2016-09-25 15:56:58',0),
('2016_10_01_00_auth.sql','7C444FF1B03BA3C83472BDA409854754D052D6FB','ARCHIVED','2016-10-01 13:32:43',0),
('2016_10_06_00_auth.sql','6A415F9813EFB5B95EB2AA2B326E1A6791E25EDB','ARCHIVED','2016-10-06 23:16:24',0),
('2016_10_12_00_auth.sql','671D57BBA183AC70B9580DEE19B7EC046AF2EA87','ARCHIVED','2016-10-12 00:01:05',0),
('2016_10_17_00_auth.sql','A0EF594CD73690D46A46031137DB0E895F079235','ARCHIVED','2016-10-16 16:33:05',0),
('2016_10_25_00_auth.sql','5743FB1AC3F564FE4192DCFA90260BAD5E501882','ARCHIVED','2016-10-25 19:27:02',0),
('2016_10_28_00_auth.sql','C1B9B1DD20B2183C6CB44CAED9B91BA7C63B8C49','ARCHIVED','2016-10-28 00:07:48',0),
('2016_11_04_00_auth.sql','3F4FE06DCE019EB3223B5A6E0F80E2239078967F','ARCHIVED','2016-11-04 20:25:23',0),
('2016_11_09_00_auth.sql','56432F8AEC2943A398A5B8B77843138B5B704257','ARCHIVED','2016-11-09 18:46:48',0),
('2016_11_17_00_auth.sql','18E8F8FC93CC38755AB571638960AAFB98C0F3F1','ARCHIVED','2016-11-17 23:47:51',0),
('2016_12_04_00_auth.sql','B1623681EAB651D2A091E3F4D4D4E476CF6D3AEA','ARCHIVED','2016-12-04 00:41:36',0),
('2016_12_11_00_auth.sql','24CA34537DB697962DDD69EEE4BB5E79D2A573DA','ARCHIVED','2016-12-11 18:18:59',0),
('2016_12_18_00_auth.sql','7AB53E033680CF7439F142EF83CD13E6F5D0ACB9','ARCHIVED','2016-12-18 12:15:48',0),
('2017_01_14_00_auth.sql','1B514D1364042DB4CE68929EB54A94F86983441D','ARCHIVED','2017-01-14 20:50:47',0),
('2017_01_26_00_auth.sql','723E1B69981A32A2F28A67C64902BA1AE7E98E48','ARCHIVED','2017-01-26 17:10:15',0),
('2017_01_29_00_auth.sql','B76C514678903F540302505AF66886F7D2C89E30','ARCHIVED','2017-01-29 00:00:00',0),
('2017_03_11_00_auth.sql','2F2F67E51439346B212C27B7224E4614C00E1AEB','ARCHIVED','2017-03-11 00:00:00',0),
('2017_03_17_00_auth.sql','4902E9B1B063F399F928C2DD7AFD60427738E227','ARCHIVED','2017-03-17 18:58:01',0),
('2017_04_17_00_auth.sql','86299FAB21D895E84272286309CC8EE80F9DA8C7','ARCHIVED','2017-04-17 00:00:00',0),
('2017_04_19_00_auth.sql','9903AAF50DF384F52E81F7E2892FE5271E000490','ARCHIVED','2017-04-18 23:16:18',0),
('2017_04_22_00_auth.sql','843663B18D28FBA1EB12548500EC93953881E5F0','ARCHIVED','2017-04-22 19:28:22',0),
('2017_04_27_00_auth.sql','308B797B47FA803D492C9C9A4C26DBEC546DBBD9','ARCHIVED','2017-04-28 09:10:11',0),
('2017_05_14_00_auth.sql','B7E76CCDCC9A2C8103427DA4C43C7B0366ECE8B4','ARCHIVED','2017-05-14 12:00:00',0),
('2017_06_12_01_auth.sql','661B4935E101AF188BEBF43203144104E89F8C54','ARCHIVED','2017-06-12 00:00:01',0),
('2017_06_12_02_auth.sql','166F059E411FAA4901BBBA09A41EF07B1CADC4B6','ARCHIVED','2017-06-12 00:00:02',0),
('2017_06_17_00_auth.sql','4A172895CB9DA8EFE1270434D6ECB22D4F4DCB17','ARCHIVED','2017-06-17 00:00:00',0),
('2017_06_15_00_auth.sql','DD71F25C1E61FD5F836931B02703BE3BD1B4F156','ARCHIVED','2017-06-15 15:20:50',0),
('2017_06_18_00_auth.sql','7200968BFC2D76499149937B19F2153FD2ABC397','ARCHIVED','2017-06-18 22:13:37',0),
('2017_06_25_00_auth.sql','A2DA6A64D4217992EF766915DEBD517DB0834E01','ARCHIVED','2017-06-25 00:54:10',0),
('2017_06_28_00_auth_master.sql','6E58300D4D4DAAEE89107ECB3CB7DA8529DA738F','ARCHIVED','2017-06-28 19:11:09',0),
('2017_06_28_00_auth_rbac.sql','D32EF80F57F629C23395D80F06E91D7E40719F83','ARCHIVED','2017-06-28 00:00:00',0),
('2017_08_01_00_auth.sql','6ECE808AF52345177189E962C0606B769B6806A6','ARCHIVED','2017-08-01 00:00:00',0),
('2017_06_30_00_auth.sql','C73BD277D211DBE1BB86BB1B443CA8F292D8ADEE','ARCHIVED','2017-06-30 16:18:51',0),
('2017_08_04_00_auth.sql','2E994A704C64FECE3CE0883ED0CAC5E5A0E3A36C','ARCHIVED','2017-08-04 23:46:32',0),
('2017_08_13_00_auth_2016_09_22_00_auth.sql','70047954E3556BFA430ADD5680EF8797F74A4B9E','ARCHIVED','2017-08-13 12:00:00',0),
('2017_09_22_00_auth.sql','9313CCE80A18212E6F0C78D83316DE8582AE8084','ARCHIVED','2017-09-22 18:05:17',0),
('2017_11_11_01_auth.sql','0D6EDB6B2FC8B9FBDF11ECD79B4B8E943328B6A9','ARCHIVED','2017-11-11 18:49:45',0),
('2017_12_30_00_auth.sql','F360E9555AC68E28834E3FF807E4E37A090EF363','ARCHIVED','2017-12-30 00:23:32',0),
('2017_12_30_01_auth.sql','1E11C78BA6D1D8E8CED7423DF92D1D197D6061EE','ARCHIVED','2017-12-30 23:00:00',0),
('2017_12_31_00_auth.sql','1721ACBD35EB95FAE33B9E95F8C4E4B1FB70A5E4','ARCHIVED','2017-12-31 20:15:23',0),
('2018_01_02_00_auth.sql','CD9B826B9D95697DC412DEF780E814FA3991D6CD','ARCHIVED','2018-01-02 20:40:37',0),
('2018_02_18_00_auth.sql','8489DD3EFFE14A7486B593435F0BA2BC69B6EABF','ARCHIVED','2018-02-18 16:35:55',0),
('2018_02_19_00_auth.sql','07CE658C5EF88693D3C047EF8E724F94ADA74C15','ARCHIVED','2018-02-19 22:33:32',0),
('2018_02_28_00_auth.sql','E92EF4ABF7FA0C66649E1633DD0459F44C09EB83','ARCHIVED','2018-02-28 23:07:59',0),
('2018_03_14_00_auth.sql','2D71E93DF7419A30D0D21D8A80CF05698302575A','ARCHIVED','2018-03-14 23:07:59',0),
('2018_04_06_00_auth.sql','D8416F0C4751763202B1997C81423F6EE2FCF9A6','ARCHIVED','2018-04-06 18:00:32',0),
('2018_05_13_00_auth.sql','A9E20F2EB1E2FDBB982DB6B00DB7301852B27CD4','ARCHIVED','2018-05-13 20:22:32',0),
('2018_05_24_00_auth.sql','B98FD71AAA13810856729E034E6B8C9F8D5D4F6B','ARCHIVED','2018-05-24 22:32:49',0),
('2018_06_14_00_auth.sql','67EAB915BF0C7F2D410BE45F885A1A39D42C8C14','ARCHIVED','2018-06-14 23:06:59',0),
('2018_06_22_00_auth.sql','9DA24F70B8A365AFDEF58A9B578255CDEDFCA47C','ARCHIVED','2018-06-22 17:45:45',0),
('2018_06_23_00_auth.sql','BE35312C386A127D047E5A7CE0D14DB41D905F8E','ARCHIVED','2018-05-23 10:14:39',0),
('2018_06_29_00_auth.sql','03AAEA7E52848FA5522C3F0C6D9C38B988407480','ARCHIVED','2018-06-29 22:34:04',0),
('2018_12_09_00_auth_2017_01_06_00_auth.sql','6CCFE6A9774EC733C9863D36A0F15F3534189BBD','ARCHIVED','2018-11-22 22:21:26',0),
('2018_12_09_01_auth.sql','576C2A11BE671D8420FA3EB705E594E381ECCC56','ARCHIVED','2018-12-09 14:49:17',0),
('2019_06_08_00_auth.sql','EA5A78F5A26C17BC790481EA9B3772D3A6912459','ARCHIVED','2019-05-20 17:21:20',0),
('2019_06_08_01_auth.sql','8165B1B787E3ECF0C8C0AD2D641513270977ABB4','ARCHIVED','2019-06-04 16:51:31',0),
('2019_06_08_02_auth.sql','B39DCBD902290700A81C9D028F54B58601C19A99','ARCHIVED','2019-06-05 16:26:31',0),
('2019_06_08_03_auth.sql','F483B657015D39D4F63E3905C27C3AA48241AB03','ARCHIVED','2019-06-08 17:14:21',0),
('2019_07_14_00_auth.sql','94C2B877BD906538E1E008350BEA8D8B58E0A158','ARCHIVED','2019-07-14 19:22:08',0),
('2019_07_15_00_auth.sql','3649248104CFEC70553016273069A9AE744798E3','ARCHIVED','2019-07-15 19:22:08',0),
('2019_07_26_00_auth.sql','DC9D0651602AE78B1243B40555A1A7B8447D01B2','ARCHIVED','2019-07-26 18:21:34',0),
('2019_08_11_00_auth.sql','04DCC2ABDA15BC7C015E8BFEA383C62A362B166F','ARCHIVED','2019-08-11 10:56:39',0),
('2019_08_18_00_auth.sql','0479A04B669A67D2E5A498CFB91507E742EFB34F','ARCHIVED','2019-08-17 11:51:02',0),
('2019_10_27_00_auth.sql','C943A651B5C9AC51BB7DF69821886F4B59F57153','ARCHIVED','2019-10-27 13:06:06',0),
('2019_11_13_00_auth.sql','EB680BA7D6B3A21A432687F452CDD86FB2DA677C','ARCHIVED','2019-11-13 11:49:55',0),
('2019_11_20_00_auth.sql','9BC11595D9CEA486AC1540A204DCE9D86A008D7D','ARCHIVED','2019-11-20 12:31:56',0),
('2019_11_23_00_auth.sql','098708CDC5614B4523AD3B17670939671E661443','ARCHIVED','2019-11-23 12:20:03',0),
('2019_12_04_00_auth.sql','4EB3D028DD80B18DA9B9250ADA4D22AA0D3C0447','ARCHIVED','2019-12-04 18:03:39',0),
('2019_12_07_00_auth.sql','F354DA31D5B300609C6AE8A25667CA4DE0A7349F','ARCHIVED','2019-12-07 12:57:23',0),
('2019_12_10_00_auth.sql','CC0DC6211FB2A1271EBF5D81F47B3EF1CED7A7AD','ARCHIVED','2019-12-10 17:50:44',0),
('2019_12_14_00_auth.sql','CF577A0B6F9747658CDECE3F690B05B89C5B4470','ARCHIVED','2019-12-14 11:17:56',0),
('2020_01_11_00_auth.sql','A0C4863741C4B93D343B7837FBA38D6023A237F9','ARCHIVED','2020-01-11 13:44:51',0),
('2020_01_12_00_auth.sql','5E4ECF243259B9866A877E2D3798D1D753738E24','ARCHIVED','2020-01-12 11:33:48',0),
('2020_02_17_00_auth.sql','456FA32A7B7C6ABA479F2B099822988A24A2344B','ARCHIVED','2020-02-17 23:28:22',0),
('2020_02_24_00_auth.sql','47E22129056EFD8B67754506231BCC4B0DDA6930','ARCHIVED','2020-02-24 17:19:33',0),
('2020_03_03_00_auth.sql','F473DFEABAC661704ECEA3D72E93A3280122CA30','ARCHIVED','2020-03-03 22:49:13',0),
('2020_03_20_00_auth.sql','0F72572D7792236D8F1E556D9EC62352A0A149CA','ARCHIVED','2020-03-20 10:01:23',0),
('2020_03_23_00_auth.sql','B90D27BB8E3CEDF65881BDA0C7CE6FBC5EF310E0','ARCHIVED','2020-03-23 17:57:46',0),
('2020_03_31_00_auth.sql','BA82A58E95730A397922B6723DA027986E6CD535','ARCHIVED','2020-03-31 17:00:16',0),
('2020_04_04_00_auth.sql','5F118989A9F8AFA3B2065AB9C2C0BB7D9A0EB97A','ARCHIVED','2020-04-04 13:23:53',0),
('2020_04_30_00_auth.sql','2FD304B8EF82D529D69287BF22EF061A267F827E','ARCHIVED','2020-04-30 00:39:29',0),
('2020_05_19_00_auth.sql','12D9F26538F63546B74793499E8A71BD885E8E5F','ARCHIVED','2020-05-19 12:00:00',0),
('2020_06_04_00_auth.sql','BA797B558196B1A07F8FF66E5288AD04659CF6AC','ARCHIVED','2020-06-04 09:57:07',0),
('2020_06_17_00_auth.sql','8BAB0BF5C90EBDE68685A9FB772EA90DD214E6D6','ARCHIVED','2020-06-17 09:56:25',0),
('2020_06_17_01_auth.sql','8FBF37B875B5C0E8A609FFB1A2C02F2920A3D3F4','ARCHIVED','2020-06-17 17:04:56',0),
('2020_06_20_00_auth.sql','85345FAF20B91DA7B157AE1E17DF5B6446C2E109','ARCHIVED','2020-06-11 10:48:00',0),
('2020_07_02_00_auth.sql','08D0F9D70AE625285172B3E02A3DAFE17D88E118','ARCHIVED','2020-07-02 10:29:25',0),
('2020_07_03_00_auth.sql','ED7175E51F248ADC5EF60E7CEA9627CC3191ED4C','ARCHIVED','2020-07-03 20:09:39',0),
('2020_07_23_00_auth.sql','5F47E1CEECA9F837C85C2DAC7ECD47AED321F502','ARCHIVED','2020-07-23 19:54:42',0),
('2020_07_24_00_auth.sql','06598162E9C84DDF8AA1F83D0410D056C3F7F69E','ARCHIVED','2020-07-24 00:44:34',0),
('2020_07_25_00_auth.sql','BE376B619ECB6FE827270D5022F311E20AD6E177','ARCHIVED','2020-07-25 00:00:49',0),
('2020_08_02_00_auth.sql','B0290F6558C59262D9DDD8071060A8803DD56930','ARCHIVED','2020-08-02 00:00:00',0),
('2020_08_03_00_auth.sql','492CA77C0FAEEEF3E0492121B3A92689373ECFA3','ARCHIVED','2020-08-03 09:24:47',0),
('2020_08_03_01_auth.sql','EC1063396CA20A2303D83238470D41EF4439EC72','ARCHIVED','2020-08-03 00:00:01',0),
('2020_08_06_00_auth.sql','5D3C5B25132DAFCA3933E9CBE14F5E8A290C4AFA','ARCHIVED','2020-08-06 20:26:11',0),
('2020_08_08_00_auth.sql','BC6A08BE42A6F2C30C9286CBDD47D57B718C4635','ARCHIVED','2020-08-08 00:16:57',0),
('2020_08_14_00_auth.sql','DFB9B07A7846FC0E124EE4CC099E49FE5742FB66','ARCHIVED','2020-08-14 21:41:24',0),
('2020_08_26_00_auth.sql','D5EF787DECB41D898379588F101A0453B46F04D9','ARCHIVED','2020-08-26 21:00:34',0),
('2020_09_25_00_auth.sql','3CCA78EF89223724BA6784A4F3783DED30416637','ARCHIVED','2020-09-25 19:52:40',0),
('2020_10_20_00_auth.sql','1835C5EFD5816DEF914F27E867C8C8D5E08B3F68','ARCHIVED','2020-10-20 21:36:49',0),
('2020_12_06_00_auth.sql','FA254400D3D7D53E9C350EABFEABFF4EC3AD40DA','RELEASED','2020-12-06 20:25:10',0),
('2020_12_07_00_auth.sql','23626805735CB9BEEEBD756D4A39AFBCDA6E366C','RELEASED','2020-12-07 21:12:53',0),
('2020_12_15_00_auth.sql','37DA3C4830ABA30C49370A8647F5B6B3E1821E57','RELEASED','2020-12-15 19:33:15',0),
('2020_12_22_00_auth.sql','1AED5AD7D93C30CF75E62EBEBCC64FFEDC58F00A','RELEASED','2020-12-22 22:00:39',0);
/*!40000 ALTER TABLE `updates` ENABLE KEYS */;
UNLOCK TABLES;

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
-- Dumping data for table `updates_include`
--

LOCK TABLES `updates_include` WRITE;
/*!40000 ALTER TABLE `updates_include` DISABLE KEYS */;
INSERT INTO `updates_include` VALUES
('$/sql/updates/auth','RELEASED'),
('$/sql/custom/auth','RELEASED'),
('$/sql/old/6.x/auth','ARCHIVED'),
('$/sql/old/7/auth','ARCHIVED'),
('$/sql/old/8.x/auth','ARCHIVED');
/*!40000 ALTER TABLE `updates_include` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `uptime`
--

DROP TABLE IF EXISTS `uptime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `uptime` (
  `realmid` int(10) unsigned NOT NULL,
  `starttime` int(10) unsigned NOT NULL DEFAULT '0',
  `uptime` int(10) unsigned NOT NULL DEFAULT '0',
  `maxplayers` smallint(5) unsigned NOT NULL DEFAULT '0',
  `revision` varchar(255) NOT NULL DEFAULT 'Trinitycore',
  PRIMARY KEY (`realmid`,`starttime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Uptime system';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `uptime`
--

LOCK TABLES `uptime` WRITE;
/*!40000 ALTER TABLE `uptime` DISABLE KEYS */;
/*!40000 ALTER TABLE `uptime` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'auth'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-10-20 21:36:50
