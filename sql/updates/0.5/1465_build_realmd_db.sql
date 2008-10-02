-- MySQL dump 10.10
--
-- Host: localhost    Database: realmd
-- ------------------------------------------------------
-- Server version	5.0.21

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
CREATE TABLE `account` (
  `id` bigint(20) unsigned NOT NULL auto_increment COMMENT 'Identifier',
  `username` varchar(16) NOT NULL default '',
  `password` varchar(28) NOT NULL default '',
  `gmlevel` tinyint(3) unsigned NOT NULL default '0',
  `sessionkey` longtext,
  `email` varchar(50) NOT NULL default '',
  `joindate` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `banned` tinyint(3) unsigned NOT NULL default '0',
  `last_ip` varchar(30) NOT NULL default '127.0.0.1',
  `failed_logins` int(11) unsigned NOT NULL default '0',
  `locked` tinyint(3) unsigned NOT NULL default '0',
  `last_login` timestamp NOT NULL default '0000-00-00 00:00:00',
  `online` tinyint NOT NULL default 0,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `idx_username` (`username`),
  KEY `idx_banned` (`banned`),
  KEY `idx_gmlevel` (`gmlevel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Account System';

--
-- Table structure for table `realmcharacters`
--

DROP TABLE IF EXISTS `realmcharacters`;
CREATE TABLE `realmcharacters` (
  `realmid` integer(11) unsigned NOT NULL default '0',
  `acctid` bigint(20) unsigned NOT NULL,
  `numchars` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY (`realmid`, `acctid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Realm Character Tracker';


--
-- Table structure for table `ip_banned`
--

DROP TABLE IF EXISTS `ip_banned`;
CREATE TABLE `ip_banned` (
  `ip` varchar(32) NOT NULL default '127.0.0.1',
  PRIMARY KEY  (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Banned IPs';

--
-- Dumping data for table `ip_banned`
--


/*!40000 ALTER TABLE `ip_banned` DISABLE KEYS */;
LOCK TABLES `ip_banned` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ip_banned` ENABLE KEYS */;


--
-- Table structure for table `realmlist`
--

DROP TABLE IF EXISTS `realmlist`;
CREATE TABLE `realmlist` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `name` varchar(32) NOT NULL default '',
  `address` varchar(32) NOT NULL default '127.0.0.1',
  `icon` tinyint(3) unsigned NOT NULL default '0',
  `color` tinyint(3) unsigned NOT NULL default '0',
  `timezone` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Realm System';

