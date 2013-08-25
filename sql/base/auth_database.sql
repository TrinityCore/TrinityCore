-- MySQL dump 10.13  Distrib 5.6.9-rc, for Win64 (x86_64)
--
-- Host: localhost    Database: auth_4x
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
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(32) NOT NULL DEFAULT '',
  `sha_pass_hash` varchar(40) NOT NULL DEFAULT '',
  `sessionkey` varchar(80) NOT NULL DEFAULT '',
  `v` varchar(64) NOT NULL DEFAULT '',
  `s` varchar(64) NOT NULL DEFAULT '',
  `token_key` varchar(100) NOT NULL DEFAULT '',
  `email` varchar(254) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) NOT NULL DEFAULT '00',
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '3',
  `mutetime` bigint(20) NOT NULL DEFAULT '0',
  `mutereason` varchar(255) NOT NULL DEFAULT '',
  `muteby` varchar(50) NOT NULL DEFAULT '',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(3) NOT NULL DEFAULT '',
  `recruiter` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_username` (`username`)
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
  `id` int(10) unsigned NOT NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL DEFAULT '-1',
  PRIMARY KEY (`id`,`RealmID`)
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
-- Dumping data for table `autobroadcast`
--

DROP TABLE IF EXISTS `autobroadcast`;

CREATE TABLE `autobroadcast` (
  `realmid` int(11) NOT NULL DEFAULT '-1',
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) unsigned DEFAULT '1',
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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

/*Table structure for table `ip2nation` */

DROP TABLE IF EXISTS `ip2nation`;

CREATE TABLE `ip2nation` (
  `ip` int(11) unsigned NOT NULL DEFAULT '0',
  `country` char(2) NOT NULL DEFAULT '',
  KEY `ip` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `ip2nationCountries` */

DROP TABLE IF EXISTS `ip2nationCountries`;

CREATE TABLE `ip2nationCountries` (
  `code` varchar(4) NOT NULL DEFAULT '',
  `iso_code_2` varchar(2) NOT NULL DEFAULT '',
  `iso_code_3` varchar(3) DEFAULT '',
  `iso_country` varchar(255) NOT NULL DEFAULT '',
  `country` varchar(255) NOT NULL DEFAULT '',
  `lat` float NOT NULL DEFAULT '0',
  `lon` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`code`),
  KEY `code` (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
  `type` tinyint(3) unsigned NOT NULL,
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
-- Table structure for table `rbac_account_groups`
--

DROP TABLE IF EXISTS `rbac_account_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_account_groups` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `groupId` int(10) unsigned NOT NULL COMMENT 'Group id',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`groupId`,`realmId`),
  KEY `fk__rbac_account_groups__rbac_groups` (`groupId`),
  CONSTRAINT `fk__rbac_account_groups__account` FOREIGN KEY (`accountId`) REFERENCES `account` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_account_groups__rbac_groups` FOREIGN KEY (`groupId`) REFERENCES `rbac_groups` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Group relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_account_groups`
--

LOCK TABLES `rbac_account_groups` WRITE;
/*!40000 ALTER TABLE `rbac_account_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `rbac_account_groups` ENABLE KEYS */;
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
-- Table structure for table `rbac_account_roles`
--

DROP TABLE IF EXISTS `rbac_account_roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_account_roles` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  `granted` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`roleId`,`realmId`),
  KEY `fk__rbac_account_roles__rbac_roles` (`roleId`),
  CONSTRAINT `fk__rbac_account_roles__account` FOREIGN KEY (`accountId`) REFERENCES `account` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_account_roles__rbac_roles` FOREIGN KEY (`roleId`) REFERENCES `rbac_roles` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Role relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_account_roles`
--

LOCK TABLES `rbac_account_roles` WRITE;
/*!40000 ALTER TABLE `rbac_account_roles` DISABLE KEYS */;
/*!40000 ALTER TABLE `rbac_account_roles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_group_roles`
--

DROP TABLE IF EXISTS `rbac_group_roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_group_roles` (
  `groupId` int(10) unsigned NOT NULL COMMENT 'group id',
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  PRIMARY KEY (`groupId`,`roleId`),
  KEY `fk__rbac_group_roles__rbac_roles` (`roleId`),
  CONSTRAINT `fk__rbac_group_roles__rbac_roles` FOREIGN KEY (`roleId`) REFERENCES `rbac_roles` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_group_roles__rbac_groups` FOREIGN KEY (`groupId`) REFERENCES `rbac_groups` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Group Role relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_group_roles`
--

LOCK TABLES `rbac_group_roles` WRITE;
/*!40000 ALTER TABLE `rbac_group_roles` DISABLE KEYS */;
INSERT INTO `rbac_group_roles` VALUES (1,1),(2,2),(3,3),(4,4),(2,5),(1,6),(1,7),(2,8),(3,8),(4,8),(2,9),(3,9),(4,9),(2,10),(3,10),(4,10),(2,11),(3,11),(4,11),(2,12),(3,12),(4,12),(2,13),(3,13),(4,13),(2,14),(3,14),(4,14),(2,15),(3,15),(4,15),(2,16),(3,16),(4,16),(2,17),(3,17),(4,17),(4,18),(2,19),(3,19),(4,19),(2,20),(3,20),(4,20),(2,21),(3,21),(4,21),(2,22),(3,22),(4,22),(4,23),(2,24),(3,24),(4,24),(2,25),(3,25),(4,25),(2,26),(3,26),(4,26),(2,27),(3,27),(4,27),(2,28),(3,28),(4,28),(2,29),(3,29),(4,29),(2,30),(3,30),(4,30),(2,32),(3,32),(4,32),(2,33),(3,33),(4,33),(1,34),(2,35),(3,35),(4,35),(2,36),(3,36),(4,36),(2,37),(3,37),(4,37),(2,38),(3,38),(4,38),(3,39),(4,39);
/*!40000 ALTER TABLE `rbac_group_roles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_groups`
--

DROP TABLE IF EXISTS `rbac_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_groups` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Group id',
  `name` varchar(100) NOT NULL COMMENT 'Group name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Group List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_groups`
--

LOCK TABLES `rbac_groups` WRITE;
/*!40000 ALTER TABLE `rbac_groups` DISABLE KEYS */;
INSERT INTO `rbac_groups` VALUES (1,'Player'),(2,'Moderator'),(3,'GameMaster'),(4,'Administrator');
/*!40000 ALTER TABLE `rbac_groups` ENABLE KEYS */;
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
INSERT INTO `rbac_permissions` VALUES (1,'Instant logout'),(2,'Skip Queue'),(3,'Join Normal Battleground'),(4,'Join Random Battleground'),(5,'Join Arenas'),(6,'Join Dungeon Finder'),(7,'Player Commands (Temporal till commands moved to rbac)'),(8,'Moderator Commands (Temporal till commands moved to rbac)'),(9,'GameMaster Commands (Temporal till commands moved to rbac)'),(10,'Administrator Commands (Temporal till commands moved to rbac)'),(11,'Log GM trades'),(13,'Skip Instance required bosses check'),(14,'Skip character creation team mask check'),(15,'Skip character creation class mask check'),(16,'Skip character creation race mask check'),(17,'Skip character creation reserved name check'),(18,'Skip character creation heroic min level check'),(19,'Skip needed requirements to use channel check'),(20,'Skip disable map check'),(21,'Skip reset talents when used more than allowed check'),(22,'Skip spam chat check'),(23,'Skip over-speed ping check'),(24,'Two side faction characters on the same account'),(25,'Allow say chat between factions'),(26,'Allow channel chat between factions'),(27,'Two side mail interaction'),(28,'See two side who list'),(29,'Add friends of other faction'),(30,'Save character without delay with .save command'),(31,'Use params with .unstuck command'),(32,'Can be assigned tickets with .assign ticket command'),(33,'Notify if a command was not found'),(34,'Check if should appear in list using .gm ingame command'),(35,'See all security levels with who command'),(36,'Filter whispers'),(37,'Use staff badge in chat'),(38,'Resurrect with full Health Points'),(39,'Restore saved gm setting states'),(40,'Allows to add a gm to friend list'),(41,'Use Config option START_GM_LEVEL to assign new character level'),(42,'Allows to use CMSG_WORLD_TELEPORT opcode'),(43,'Allows to use CMSG_WHOIS opcode'),(44,'Receive global GM messages/texts'),(45,'Join channels without announce'),(46,'Change channel settings without being channel moderator'),(47,'Enables lower security than target check'),(48,'Enable IP, Last Login and EMail output in pinfo');
/*!40000 ALTER TABLE `rbac_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_role_permissions`
--

DROP TABLE IF EXISTS `rbac_role_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_role_permissions` (
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  PRIMARY KEY (`roleId`,`permissionId`),
  KEY `fk__role_permissions__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__role_permissions__rbac_roles` FOREIGN KEY (`roleId`) REFERENCES `rbac_roles` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__role_permissions__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Role Permission relation';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_role_permissions`
--

LOCK TABLES `rbac_role_permissions` WRITE;
/*!40000 ALTER TABLE `rbac_role_permissions` DISABLE KEYS */;
INSERT INTO `rbac_role_permissions` VALUES (5,1),(5,2),(6,3),(6,4),(6,5),(7,6),(1,7),(2,8),(3,9),(4,10),(8,11),(9,13),(33,14),(33,15),(33,16),(33,17),(33,18),(27,19),(22,20),(23,21),(24,22),(17,23),(34,24),(28,25),(30,26),(19,27),(35,28),(36,29),(11,30),(12,31),(10,32),(20,33),(14,34),(37,35),(29,36),(15,37),(13,38),(25,39),(38,40),(26,41),(18,42),(18,43),(16,44),(31,45),(32,46),(21,47),(39,48);
/*!40000 ALTER TABLE `rbac_role_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_roles`
--

DROP TABLE IF EXISTS `rbac_roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_roles` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Role id',
  `name` varchar(100) NOT NULL COMMENT 'Role name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Roles List';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_roles`
--

LOCK TABLES `rbac_roles` WRITE;
/*!40000 ALTER TABLE `rbac_roles` DISABLE KEYS */;
INSERT INTO `rbac_roles` VALUES (1,'Player Commands'),(2,'Moderator Commands'),(3,'GameMaster Commands'),(4,'Administrator Commands'),(5,'Quick Login/Logout'),(6,'Use Battleground/Arenas'),(7,'Use Dungeon Finder'),(8,'Log GM trades'),(9,'Skip Instance required bosses check'),(10,'Ticket management'),(11,'Instant .save'),(12,'Allow params with .unstuck'),(13,'Full HP after resurrect'),(14,'Appear in GM ingame list'),(15,'Use staff badge in chat'),(16,'Receive global GM messages/texts'),(17,'Skip over-speed ping check'),(18,'Allows Admin Opcodes'),(19,'Two side mail interaction'),(20,'Notify if a command was not found'),(21,'Enables lower security than target check'),(22,'Skip disable map check'),(23,'Skip reset talents when used more than allowed check'),(24,'Skip spam chat check'),(25,'Restore saved gm setting states'),(26,'Use Config option START_GM_LEVEL to assign new character level'),(27,'Skip needed requirements to use channel check'),(28,'Allow say chat between factions'),(29,'Filter whispers'),(30,'Allow channel chat between factions'),(31,'Join channels without announce'),(32,'Change channel settings without being channel moderator'),(33,'Skip character creation checks'),(34,'Two side faction characters on the same account'),(35,'See two side who list'),(36,'Add friends of other faction'),(37,'See all security levels with who command'),(38,'Allows to add a gm to friend list'),(39,'Enable IP, Last Login and EMail output in pinfo');
/*!40000 ALTER TABLE `rbac_roles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rbac_security_level_groups`
--

DROP TABLE IF EXISTS `rbac_security_level_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rbac_security_level_groups` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `groupId` int(10) unsigned NOT NULL COMMENT 'group id',
  PRIMARY KEY (`secId`,`groupId`),
  KEY `fk__rbac_security_level_groups__rbac_groups` (`groupId`),
  CONSTRAINT `fk__rbac_security_level_groups__rbac_groups` FOREIGN KEY (`groupId`) REFERENCES `rbac_groups` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Default groups to assign when an account is set gm level';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rbac_security_level_groups`
--

LOCK TABLES `rbac_security_level_groups` WRITE;
/*!40000 ALTER TABLE `rbac_security_level_groups` DISABLE KEYS */;
INSERT INTO `rbac_security_level_groups` VALUES (0,1),(1,1),(2,1),(3,1),(1,2),(2,2),(3,2),(2,3),(3,3),(3,4);
/*!40000 ALTER TABLE `rbac_security_level_groups` ENABLE KEYS */;
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
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '15595',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Realm System';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `realmlist`
--

LOCK TABLES `realmlist` WRITE;
/*!40000 ALTER TABLE `realmlist` DISABLE KEYS */;
INSERT INTO `realmlist` VALUES (1,'Trinity','127.0.0.1','127.0.0.1','255.255.255.0',8085,1,0,1,0,0,15595);
/*!40000 ALTER TABLE `realmlist` ENABLE KEYS */;
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
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-03-09 17:57:13
