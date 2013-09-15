-- MySQL dump 10.13  Distrib 5.6.9-rc, for Win64 (x86_64)
--
-- Host: localhost    Database: auth
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
  `email` varchar(255) NOT NULL DEFAULT '',
  `reg_mail` varchar(255) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) NOT NULL DEFAULT '00',
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '2',
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
-- Table structure for table `ip2nation`
--

DROP TABLE IF EXISTS `ip2nation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ip2nation` (
  `ip` int(11) unsigned NOT NULL DEFAULT '0',
  `country` char(2) NOT NULL DEFAULT '',
  KEY `ip` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ip2nation`
--

LOCK TABLES `ip2nation` WRITE;
/*!40000 ALTER TABLE `ip2nation` DISABLE KEYS */;
/*!40000 ALTER TABLE `ip2nation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ip2nationCountries`
--

DROP TABLE IF EXISTS `ip2nationCountries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
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
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ip2nationCountries`
--

LOCK TABLES `ip2nationCountries` WRITE;
/*!40000 ALTER TABLE `ip2nationCountries` DISABLE KEYS */;
/*!40000 ALTER TABLE `ip2nationCountries` ENABLE KEYS */;
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
INSERT INTO `rbac_group_roles` VALUES (1,1),(2,2),(3,3),(4,4),(2,5),(1,6),(1,7),(2,8),(3,8),(4,8),(2,9),(3,9),(4,9),(2,10),(3,10),(4,10),(2,11),(3,11),(4,11),(2,12),(3,12),(4,12),(2,13),(3,13),(4,13),(2,14),(3,14),(4,14),(2,15),(3,15),(4,15),(2,16),(3,16),(4,16),(2,17),(3,17),(4,17),(4,18),(2,19),(3,19),(4,19),(2,20),(3,20),(4,20),(2,21),(3,21),(4,21),(2,22),(3,22),(4,22),(4,23),(2,24),(3,24),(4,24),(2,25),(3,25),(4,25),(2,26),(3,26),(4,26),(2,27),(3,27),(4,27),(2,28),(3,28),(4,28),(2,29),(3,29),(4,29),(2,30),(3,30),(4,30),(2,32),(3,32),(4,32),(2,33),(3,33),(4,33),(1,34),(2,35),(3,35),(4,35),(2,36),(3,36),(4,36),(2,37),(3,37),(4,37),(2,38),(3,38),(4,38),(3,39),(4,39),(1,40),(2,40),(3,40),(4,40);
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
INSERT INTO `rbac_permissions` VALUES (1,'Instant logout'),(2,'Skip Queue'),(3,'Join Normal Battleground'),(4,'Join Random Battleground'),(5,'Join Arenas'),(6,'Join Dungeon Finder'),(11,'Log GM trades'),(13,'Skip Instance required bosses check'),(14,'Skip character creation team mask check'),(15,'Skip character creation class mask check'),(16,'Skip character creation race mask check'),(17,'Skip character creation reserved name check'),(18,'Skip character creation heroic min level check'),(19,'Skip needed requirements to use channel check'),(20,'Skip disable map check'),(21,'Skip reset talents when used more than allowed check'),(22,'Skip spam chat check'),(23,'Skip over-speed ping check'),(24,'Two side faction characters on the same account'),(25,'Allow say chat between factions'),(26,'Allow channel chat between factions'),(27,'Two side mail interaction'),(28,'See two side who list'),(29,'Add friends of other faction'),(30,'Save character without delay with .save command'),(31,'Use params with .unstuck command'),(32,'Can be assigned tickets with .assign ticket command'),(33,'Notify if a command was not found'),(34,'Check if should appear in list using .gm ingame command'),(35,'See all security levels with who command'),(36,'Filter whispers'),(37,'Use staff badge in chat'),(38,'Resurrect with full Health Points'),(39,'Restore saved gm setting states'),(40,'Allows to add a gm to friend list'),(41,'Use Config option START_GM_LEVEL to assign new character level'),(42,'Allows to use CMSG_WORLD_TELEPORT opcode'),(43,'Allows to use CMSG_WHOIS opcode'),(44,'Receive global GM messages/texts'),(45,'Join channels without announce'),(46,'Change channel settings without being channel moderator'),(47,'Enables lower security than target check'),(48,'Enable IP, Last Login and EMail output in pinfo'),(49,'Forces to enter the email for confirmation on password change'),(50,'Allow user to check his own email with .account'),(200,'Command: .rbac'),(201,'Command: .rbac account'),(202,'Command: .rbac account group'),(203,'Command: .rbac account group add'),(204,'Command: .rbac account group remove'),(205,'Command: .rbac account role'),(206,'Command: .rbac account role grant'),(207,'Command: .rbac account role deny'),(208,'Command: .rbac account role revoke'),(209,'Command: .rbac account permission'),(210,'Command: .rbac account permission grant'),(211,'Command: .rbac account permission deny'),(212,'Command: .rbac account permission revoke'),(213,'Command: .rbac list'),(214,'Command: .rbac list groups'),(215,'Command: .rbac list roles'),(216,'Command: .rbac list permissions'),(217,'Command: .account'),(218,'Command: .account addon'),(219,'Command: .account create'),(220,'Command: .account delete'),(221,'Command: .account lock'),(222,'Command: .account lock country'),(223,'Command: .account lock ip'),(224,'Command: .account onlinelist'),(225,'Command: .account password'),(226,'Command: .account set'),(227,'Command: .account set addon'),(228,'Command: .account set gmlevel'),(229,'Command: .account set password'),(230,'achievement'),(231,'achievement add'),(232,'arena'),(233,'arena captain'),(234,'arena create'),(235,'arena disband'),(236,'arena info'),(237,'arena lookup'),(238,'arena rename'),(239,'ban'),(240,'ban account'),(241,'ban character'),(242,'ban ip'),(243,'ban playeraccount'),(244,'baninfo'),(245,'baninfo account'),(246,'baninfo character'),(247,'baninfo ip'),(248,'banlist'),(249,'banlist account'),(250,'banlist character'),(251,'banlist ip'),(252,'unban'),(253,'unban account'),(254,'unban character'),(255,'unban ip'),(256,'unban playeraccount'),(257,'bf'),(258,'bf start'),(259,'bf stop'),(260,'bf switch'),(261,'bf timer'),(262,'bf enable'),(263,'account email'),(264,'account set sec'),(265,'account set sec email'),(266,'account set sec regmail'),(267,'cast'),(268,'cast back'),(269,'cast dist'),(270,'cast self'),(271,'cast target'),(272,'cast dest'),(273,'character'),(274,'character customize'),(275,'character changefaction'),(276,'character changerace'),(277,'character deleted'),(279,'character deleted list'),(280,'character deleted restore'),(283,'character level'),(284,'character rename'),(285,'character reputation'),(286,'character titles'),(287,'levelup'),(288,'pdump'),(289,'pdump load'),(290,'pdump write'),(291,'cheat'),(292,'cheat casttime'),(293,'cheat cooldown'),(294,'cheat explore'),(295,'cheat god'),(296,'cheat power'),(297,'cheat status'),(298,'cheat taxi'),(299,'cheat waterwalk'),(300,'debug'),(301,'debug anim'),(302,'debug areatriggers'),(303,'debug arena'),(304,'debug bg'),(305,'debug entervehicle'),(306,'debug getitemstate'),(307,'debug getitemvalue'),(308,'debug getvalue'),(309,'debug hostil'),(310,'debug itemexpire'),(311,'debug lootrecipient'),(312,'debug los'),(313,'debug mod32value'),(314,'debug moveflags'),(315,'debug play'),(316,'debug play cinematics'),(317,'debug play movie'),(318,'debug play sound'),(319,'debug send'),(320,'debug send buyerror'),(321,'debug send channelnotify'),(322,'debug send chatmessage'),(323,'debug send equiperror'),(324,'debug send largepacket'),(325,'debug send opcode'),(326,'debug send qinvalidmsg'),(327,'debug send qpartymsg'),(328,'debug send sellerror'),(329,'debug send setphaseshift'),(330,'debug send spellfail'),(331,'debug setaurastate'),(332,'debug setbit'),(333,'debug setitemvalue'),(334,'debug setvalue'),(335,'debug setvid'),(336,'debug spawnvehicle'),(337,'debug threat'),(338,'debug update'),(339,'debug uws'),(340,'wpgps'),(341,'deserter'),(342,'deserter bg'),(343,'deserter bg add'),(344,'deserter bg remove'),(345,'deserter instance'),(346,'deserter instance add'),(347,'deserter instance remove'),(348,'disable'),(349,'disable add'),(350,'disable add achievement_criteria'),(351,'disable add battleground'),(352,'disable add map'),(353,'disable add mmap'),(354,'disable add outdoorpvp'),(355,'disable add quest'),(356,'disable add spell'),(357,'disable add vmap'),(358,'disable remove'),(359,'disable remove achievement_criteria'),(360,'disable remove battleground'),(361,'disable remove map'),(362,'disable remove mmap'),(363,'disable remove outdoorpvp'),(364,'disable remove quest'),(365,'disable remove spell'),(366,'disable remove vmap'),(367,'event'),(368,'event activelist'),(369,'event start'),(370,'event stop'),(371,'gm'),(372,'gm chat'),(373,'gm fly'),(374,'gm ingame'),(375,'gm list'),(376,'gm visible'),(377,'go'),(378,'go creature'),(379,'go graveyard'),(380,'go grid'),(381,'go object'),(382,'go taxinode'),(383,'go ticket'),(384,'go trigger'),(385,'go xyz'),(386,'go zonexy'),(387,'gobject'),(388,'gobject activate'),(389,'gobject add'),(390,'gobject add temp'),(391,'gobject delete'),(392,'gobject info'),(393,'gobject move'),(394,'gobject near'),(395,'gobject set'),(396,'gobject set phase'),(397,'gobject set state'),(398,'gobject target'),(399,'gobject turn'),(401,'guild'),(402,'guild create'),(403,'guild delete'),(404,'guild invite'),(405,'guild uninvite'),(406,'guild rank'),(407,'guild rename'),(408,'honor'),(409,'honor add'),(410,'honor add kill'),(411,'honor update'),(412,'instance'),(413,'instance listbinds'),(414,'instance unbind'),(415,'instance stats'),(416,'instance savedata'),(417,'learn'),(418,'learn all'),(419,'learn all my'),(420,'learn all my class'),(421,'learn all my pettalents'),(422,'learn all my spells'),(423,'learn all my talents'),(424,'learn all gm'),(425,'learn all crafts'),(426,'learn all default'),(427,'learn all lang'),(428,'learn all recipes'),(429,'unlearn'),(430,'lfg'),(431,'lfg player'),(432,'lfg group'),(433,'lfg queue'),(434,'lfg clean'),(435,'lfg options'),(436,'list'),(437,'list creature'),(438,'list item'),(439,'list object'),(440,'list auras'),(441,'list mail'),(442,'lookup'),(443,'lookup area'),(444,'lookup creature'),(445,'lookup event'),(446,'lookup faction'),(447,'lookup item'),(448,'lookup itemset'),(449,'lookup object'),(450,'lookup quest'),(451,'lookup player'),(452,'lookup player ip'),(453,'lookup player account'),(454,'lookup player email'),(455,'lookup skill'),(456,'lookup spell'),(457,'lookup spell id'),(458,'lookup taxinode'),(459,'lookup tele'),(460,'lookup title'),(461,'lookup map'),(462,'announce'),(463,'channel'),(464,'channel set'),(465,'channel set ownership'),(466,'gmannounce'),(467,'gmnameannounce'),(468,'gmnotify'),(469,'nameannounce'),(470,'notify'),(471,'whispers'),(472,'group'),(473,'group leader'),(474,'group disband'),(475,'group remove'),(476,'group join'),(477,'group list'),(478,'group summon'),(479,'pet'),(480,'pet create'),(481,'pet learn'),(482,'pet unlearn'),(483,'send'),(484,'send items'),(485,'send mail'),(486,'send message'),(487,'send money'),(488,'additem'),(489,'additemset'),(490,'appear'),(491,'aura'),(492,'bank'),(493,'bindsight'),(494,'combatstop'),(495,'cometome'),(496,'commands'),(497,'cooldown'),(498,'damage'),(499,'dev'),(500,'die'),(501,'dismount'),(502,'distance'),(503,'flusharenapoints'),(504,'freeze'),(505,'gps'),(506,'guid'),(507,'help'),(508,'hidearea'),(509,'itemmove'),(510,'kick'),(511,'linkgrave'),(512,'listfreeze'),(513,'maxskill'),(514,'movegens'),(515,'mute'),(516,'neargrave'),(517,'pinfo'),(518,'playall'),(519,'possess'),(520,'recall'),(521,'repairitems'),(522,'respawn'),(523,'revive'),(524,'saveall'),(525,'save'),(526,'setskill'),(527,'showarea'),(528,'summon'),(529,'unaura'),(530,'unbindsight'),(531,'unfreeze'),(532,'unmute'),(533,'unpossess'),(534,'unstuck'),(535,'wchange'),(536,'mmap'),(537,'mmap loadedtiles'),(538,'mmap loc'),(539,'mmap path'),(540,'mmap stats'),(541,'mmap testarea'),(542,'morph'),(543,'demorph'),(544,'modify'),(545,'modify arenapoints'),(546,'modify bit'),(547,'modify drunk'),(548,'modify energy'),(549,'modify faction'),(550,'modify gender'),(551,'modify honor'),(552,'modify hp'),(553,'modify mana'),(554,'modify money'),(555,'modify mount'),(556,'modify phase'),(557,'modify rage'),(558,'modify reputation'),(559,'modify runicpower'),(560,'modify scale'),(561,'modify speed'),(562,'modify speed all'),(563,'modify speed backwalk'),(564,'modify speed fly'),(565,'modify speed walk'),(566,'modify speed swim'),(567,'modify spell'),(568,'modify standstate'),(569,'modify talentpoints'),(570,'npc'),(571,'npc add'),(572,'npc add formation'),(573,'npc add item'),(574,'npc add move'),(575,'npc add temp'),(576,'npc add delete'),(577,'npc add delete item'),(578,'npc add follow'),(579,'npc add follow stop'),(580,'npc set'),(581,'npc set allowmove'),(582,'npc set entry'),(583,'npc set factionid'),(584,'npc set flag'),(585,'npc set level'),(586,'npc set link'),(587,'npc set model'),(588,'npc set movetype'),(589,'npc set phase'),(590,'npc set spawndist'),(591,'npc set spawntime'),(592,'npc set data'),(593,'npc info'),(594,'npc near'),(595,'npc move'),(596,'npc playemote'),(597,'npc say'),(598,'npc textemote'),(599,'npc whisper'),(600,'npc yell'),(601,'npc tame'),(602,'quest'),(603,'quest add'),(604,'quest complete'),(605,'quest remove'),(606,'quest reward'),(607,'reload'),(608,'reload access_requirement'),(609,'reload achievement_criteria_data'),(610,'reload achievement_reward'),(611,'reload all'),(612,'reload all achievement'),(613,'reload all area'),(614,'reload all eventai'),(615,'reload all gossips'),(616,'reload all item'),(617,'reload all locales'),(618,'reload all loot'),(619,'reload all npc'),(620,'reload all quest'),(621,'reload all scripts'),(622,'reload all spell'),(623,'reload areatrigger_involvedrelation'),(624,'reload areatrigger_tavern'),(625,'reload areatrigger_teleport'),(626,'reload auctions'),(627,'reload autobroadcast'),(628,'reload command'),(629,'reload conditions'),(630,'reload config'),(631,'reload creature_text'),(632,'reload creature_ai_scripts'),(633,'reload creature_ai_texts'),(634,'reload creature_questender'),(635,'reload creature_linked_respawn'),(636,'reload creature_loot_template'),(637,'reload creature_onkill_reputation'),(638,'reload creature_queststarter'),(639,'reload creature_summon_groups'),(640,'reload creature_template'),(641,'reload disables'),(642,'reload disenchant_loot_template'),(643,'reload event_scripts'),(644,'reload fishing_loot_template'),(645,'reload game_graveyard_zone'),(646,'reload game_tele'),(647,'reload gameobject_questender'),(648,'reload gameobject_loot_template'),(649,'reload gameobject_queststarter'),(650,'reload gm_tickets'),(651,'reload gossip_menu'),(652,'reload gossip_menu_option'),(653,'reload item_enchantment_template'),(654,'reload item_loot_template'),(655,'reload item_set_names'),(656,'reload lfg_dungeon_rewards'),(657,'reload locales_achievement_reward'),(658,'reload locales_creature'),(659,'reload locales_creature_text'),(660,'reload locales_gameobject'),(661,'reload locales_gossip_menu_option'),(662,'reload locales_item'),(663,'reload locales_item_set_name'),(664,'reload locales_npc_text'),(665,'reload locales_page_text'),(666,'reload locales_points_of_interest'),(667,'reload locales_quest'),(668,'reload mail_level_reward'),(669,'reload mail_loot_template'),(670,'reload milling_loot_template'),(671,'reload npc_spellclick_spells'),(672,'reload npc_trainer'),(673,'reload npc_vendor'),(674,'reload page_text'),(675,'reload pickpocketing_loot_template'),(676,'reload points_of_interest'),(677,'reload prospecting_loot_template'),(678,'reload quest_poi'),(679,'reload quest_template'),(680,'reload rbac'),(681,'reload reference_loot_template'),(682,'reload reserved_name'),(683,'reload reputation_reward_rate'),(684,'reload reputation_spillover_template'),(685,'reload skill_discovery_template'),(686,'reload skill_extra_item_template'),(687,'reload skill_fishing_base_level'),(688,'reload skinning_loot_template'),(689,'reload smart_scripts'),(690,'reload spell_required'),(691,'reload spell_area'),(692,'reload spell_bonus_data'),(693,'reload spell_group'),(694,'reload spell_learn_spell'),(695,'reload spell_loot_template'),(696,'reload spell_linked_spell'),(697,'reload spell_pet_auras'),(698,'reload spell_proc_event'),(699,'reload spell_proc'),(700,'reload spell_scripts'),(701,'reload spell_target_position'),(702,'reload spell_threats'),(703,'reload spell_group_stack_rules'),(704,'reload trinity_string'),(705,'reload warden_action'),(706,'reload waypoint_scripts'),(707,'reload waypoint_data'),(708,'reload vehicle_accessory'),(709,'reload vehicle_template_accessory'),(710,'reset'),(711,'reset achievements'),(712,'reset honor'),(713,'reset level'),(714,'reset spells'),(715,'reset stats'),(716,'reset talents'),(717,'reset all'),(718,'server'),(719,'server corpses'),(720,'server exit'),(721,'server idlerestart'),(722,'server idlerestart cancel'),(723,'server idleshutdown'),(724,'server idleshutdown cancel'),(725,'server info'),(726,'server plimit'),(727,'server restart'),(728,'server restart cancel'),(729,'server set'),(730,'server set closed'),(731,'server set difftime'),(732,'server set loglevel'),(733,'server set motd'),(734,'server shutdown'),(735,'server shutdown cancel'),(736,'server motd'),(737,'tele'),(738,'tele add'),(739,'tele del'),(740,'tele name'),(741,'tele group'),(742,'ticket'),(743,'ticket assign'),(744,'ticket close'),(745,'ticket closedlist'),(746,'ticket comment'),(747,'ticket complete'),(748,'ticket delete'),(749,'ticket escalate'),(750,'ticket escalatedlist'),(751,'ticket list'),(752,'ticket onlinelist'),(753,'ticket reset'),(754,'ticket response'),(755,'ticket response append'),(756,'ticket response appendln'),(757,'ticket togglesystem'),(758,'ticket unassign'),(759,'ticket viewid'),(760,'ticket viewname'),(761,'titles'),(762,'titles add'),(763,'titles current'),(764,'titles remove'),(765,'titles set'),(766,'titles set mask'),(767,'wp'),(768,'wp add'),(769,'wp event'),(770,'wp load'),(771,'wp modify'),(772,'wp unload'),(773,'wp reload'),(774,'wp show');
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
INSERT INTO `rbac_role_permissions` VALUES (5,1),(5,2),(6,3),(6,4),(6,5),(7,6),(8,11),(9,13),(33,14),(33,15),(33,16),(33,17),(33,18),(27,19),(22,20),(23,21),(24,22),(17,23),(34,24),(28,25),(30,26),(19,27),(35,28),(36,29),(11,30),(12,31),(10,32),(20,33),(14,34),(37,35),(29,36),(15,37),(13,38),(25,39),(38,40),(26,41),(18,42),(18,43),(16,44),(31,45),(32,46),(21,47),(39,48),(40,49),(41,50),(4,200),(4,201),(4,202),(4,203),(4,204),(4,205),(4,206),(4,207),(4,208),(4,209),(4,210),(4,211),(4,212),(4,213),(4,214),(4,215),(4,216),(1,217),(2,218),(1,221),(1,222),(1,223),(1,225),(4,226),(4,227),(4,230),(4,231),(3,232),(4,233),(4,234),(4,235),(3,236),(3,237),(4,238),(4,239),(4,240),(4,241),(4,242),(4,243),(4,244),(4,245),(4,246),(4,247),(4,248),(4,249),(4,250),(4,251),(4,252),(4,253),(4,254),(4,255),(4,256),(4,257),(4,258),(4,259),(4,260),(4,261),(4,262),(1,263),(2,263),(3,263),(4,263),(4,264),(4,265),(4,266),(4,267),(4,268),(4,269),(4,270),(4,271),(4,272),(3,273),(3,274),(3,275),(3,276),(3,277),(4,279),(4,280),(4,283),(3,284),(3,285),(3,286),(4,287),(4,288),(4,289),(4,290),(4,291),(4,292),(4,293),(4,294),(4,295),(4,296),(4,297),(4,298),(4,299),(2,300),(3,301),(4,302),(4,303),(4,304),(4,305),(4,306),(4,307),(4,308),(4,309),(4,310),(3,311),(2,312),(4,313),(4,314),(2,315),(2,316),(2,317),(2,318),(4,319),(4,320),(4,321),(4,322),(4,323),(4,324),(4,325),(4,326),(4,327),(4,328),(4,329),(4,330),(4,331),(4,332),(4,333),(4,334),(4,335),(4,336),(4,337),(4,338),(4,339),(4,340),(4,341),(4,342),(4,343),(4,344),(4,345),(4,346),(4,347),(4,348),(4,349),(4,350),(4,351),(4,352),(4,353),(4,354),(4,355),(4,356),(4,357),(4,358),(4,359),(4,360),(4,361),(4,362),(4,363),(4,364),(4,365),(4,366),(2,367),(2,368),(2,369),(2,370),(2,371),(2,372),(4,373),(2,374),(4,375),(2,376),(2,377),(2,378),(2,379),(2,380),(2,381),(2,382),(2,383),(2,384),(2,385),(2,386),(3,387),(3,388),(3,389),(3,390),(3,391),(3,392),(3,393),(3,394),(3,395),(3,396),(3,397),(3,398),(3,399),(4,401),(4,402),(4,403),(4,404),(4,405),(4,406),(4,407),(2,408),(2,409),(2,410),(2,411),(2,412),(2,413),(2,414),(2,415),(2,416),(4,417),(4,418),(4,419),(4,420),(4,421),(4,422),(4,423),(4,424),(4,425),(4,426),(4,427),(4,428),(4,429),(2,430),(2,431),(2,432),(2,433),(4,434),(4,435),(4,436),(4,437),(4,438),(4,439),(4,440),(4,441),(4,442),(4,443),(4,444),(4,445),(4,446),(4,447),(4,448),(4,449),(4,450),(4,451),(4,452),(4,453),(4,454),(4,455),(4,456),(4,457),(4,458),(4,459),(4,461),(2,462),(4,463),(4,464),(4,465),(2,466),(2,467),(2,468),(2,469),(2,470),(2,471),(4,472),(4,473),(4,474),(4,475),(4,476),(4,477),(4,478),(3,479),(3,480),(3,481),(3,482),(2,483),(2,484),(3,485),(3,486),(3,487),(4,488),(4,489),(2,490),(4,491),(4,492),(4,493),(3,494),(4,495),(1,496),(4,497),(4,498),(4,499),(4,500),(1,501),(4,502),(4,503),(2,504),(4,505),(3,506),(1,507),(4,508),(3,509),(3,510),(4,511),(2,512),(4,513),(4,514),(2,515),(4,516),(3,517),(3,518),(4,519),(2,520),(3,521),(4,522),(4,523),(2,524),(1,525),(4,526),(4,527),(2,528),(4,529),(4,530),(2,531),(2,532),(4,533),(1,534),(4,535),(4,536),(4,537),(4,538),(4,539),(4,540),(4,541),(3,542),(3,543),(2,544),(2,545),(2,546),(2,547),(2,548),(2,549),(3,550),(2,551),(2,552),(2,553),(2,554),(2,555),(4,556),(2,557),(3,558),(2,559),(2,560),(2,561),(2,562),(2,563),(2,564),(2,565),(2,566),(2,567),(3,568),(2,569),(2,570),(3,571),(3,572),(3,573),(3,574),(3,575),(3,576),(3,577),(3,578),(3,579),(3,580),(4,581),(4,582),(3,583),(3,584),(3,585),(3,586),(3,587),(3,588),(3,589),(3,590),(3,591),(4,592),(4,593),(3,594),(3,595),(4,596),(2,597),(2,598),(2,599),(2,600),(3,601),(4,602),(4,603),(4,604),(4,605),(4,606),(4,607),(4,608),(4,609),(4,610),(4,611),(4,612),(4,613),(4,614),(4,615),(4,616),(4,617),(4,618),(4,619),(4,620),(4,621),(4,622),(4,623),(4,624),(4,625),(4,626),(4,627),(4,628),(4,629),(4,630),(4,631),(4,632),(4,633),(4,634),(4,635),(4,636),(4,637),(4,638),(4,639),(4,640),(4,641),(4,642),(4,643),(4,644),(4,645),(4,646),(4,647),(4,648),(4,649),(4,650),(4,651),(4,652),(4,653),(4,654),(4,655),(4,656),(4,657),(4,658),(4,659),(4,660),(4,661),(4,662),(4,663),(4,664),(4,665),(4,666),(4,667),(4,668),(4,669),(4,670),(4,671),(4,672),(4,673),(4,674),(4,675),(4,676),(4,677),(4,678),(4,679),(4,680),(4,681),(4,682),(4,683),(4,684),(4,685),(4,686),(4,687),(4,688),(4,689),(4,690),(4,691),(4,692),(4,693),(4,694),(4,695),(4,696),(4,697),(4,698),(4,699),(4,700),(4,701),(4,702),(4,703),(4,704),(4,705),(4,706),(4,707),(4,708),(4,709),(4,710),(4,711),(4,712),(4,713),(4,714),(4,715),(4,716),(4,717),(4,718),(4,719),(4,721),(4,722),(4,723),(4,724),(4,725),(4,726),(4,727),(4,728),(4,729),(4,730),(4,733),(4,734),(4,735),(4,736),(2,737),(4,738),(4,739),(2,740),(2,741),(2,742),(3,743),(2,744),(2,745),(2,746),(2,747),(4,748),(2,749),(3,750),(2,751),(2,752),(4,753),(2,754),(2,755),(2,756),(4,757),(3,758),(2,759),(2,760),(3,761),(3,762),(3,763),(3,764),(3,765),(3,766),(3,767),(3,768),(3,769),(3,770),(3,771),(3,772),(4,773),(3,774);
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
INSERT INTO `rbac_roles` VALUES (1,'Player Commands'),(2,'Moderator Commands'),(3,'GameMaster Commands'),(4,'Administrator Commands'),(5,'Quick Login/Logout'),(6,'Use Battleground/Arenas'),(7,'Use Dungeon Finder'),(8,'Log GM trades'),(9,'Skip Instance required bosses check'),(10,'Ticket management'),(11,'Instant .save'),(12,'Allow params with .unstuck'),(13,'Full HP after resurrect'),(14,'Appear in GM ingame list'),(15,'Use staff badge in chat'),(16,'Receive global GM messages/texts'),(17,'Skip over-speed ping check'),(18,'Allows Admin Opcodes'),(19,'Two side mail interaction'),(20,'Notify if a command was not found'),(21,'Enables lower security than target check'),(22,'Skip disable map check'),(23,'Skip reset talents when used more than allowed check'),(24,'Skip spam chat check'),(25,'Restore saved gm setting states'),(26,'Use Config option START_GM_LEVEL to assign new character level'),(27,'Skip needed requirements to use channel check'),(28,'Allow say chat between factions'),(29,'Filter whispers'),(30,'Allow channel chat between factions'),(31,'Join channels without announce'),(32,'Change channel settings without being channel moderator'),(33,'Skip character creation checks'),(34,'Two side faction characters on the same account'),(35,'See two side who list'),(36,'Add friends of other faction'),(37,'See all security levels with who command'),(38,'Allows to add a gm to friend list'),(39,'Enable IP, Last Login and EMail output in pinfo'),(40,'Forces to enter the email for confirmation on password change'),(41,'Allow user to check his own email with .account');
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
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '12340',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Realm System';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `realmlist`
--

LOCK TABLES `realmlist` WRITE;
/*!40000 ALTER TABLE `realmlist` DISABLE KEYS */;
INSERT INTO `realmlist` VALUES (1,'Trinity','127.0.0.1','127.0.0.1','255.255.255.0',8085,1,0,1,0,0,12340);
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

-- Dump completed on 2013-09-10 23:18:53
