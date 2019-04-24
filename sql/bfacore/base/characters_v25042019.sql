/*
SQLyog Community v13.1.1 (64 bit)
MySQL - 5.6.39 : Database - characters
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `account_data` */

DROP TABLE IF EXISTS `account_data`;

CREATE TABLE `account_data` (
  `accountId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account Identifier',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `data` blob NOT NULL,
  PRIMARY KEY (`accountId`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_data` */

insert  into `account_data`(`accountId`,`type`,`time`,`data`) values 
(1,0,1556140497,'SET flaggedTutorials \"v##%##(##[##A##B##E##+##,##;##)##:##=\"\r\nSET actionedAdventureJournalEntries \"v\"\r\nSET petJournalTab \"5\"\r\nSET advJournalLastOpened \"1556140516\"\r\n');

/*Table structure for table `account_instance_times` */

DROP TABLE IF EXISTS `account_instance_times`;

CREATE TABLE `account_instance_times` (
  `accountId` int(10) unsigned NOT NULL,
  `instanceId` int(10) unsigned NOT NULL DEFAULT '0',
  `releaseTime` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountId`,`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_instance_times` */

/*Table structure for table `account_tutorial` */

DROP TABLE IF EXISTS `account_tutorial`;

CREATE TABLE `account_tutorial` (
  `accountId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account Identifier',
  `tut0` int(10) unsigned NOT NULL DEFAULT '0',
  `tut1` int(10) unsigned NOT NULL DEFAULT '0',
  `tut2` int(10) unsigned NOT NULL DEFAULT '0',
  `tut3` int(10) unsigned NOT NULL DEFAULT '0',
  `tut4` int(10) unsigned NOT NULL DEFAULT '0',
  `tut5` int(10) unsigned NOT NULL DEFAULT '0',
  `tut6` int(10) unsigned NOT NULL DEFAULT '0',
  `tut7` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_tutorial` */

insert  into `account_tutorial`(`accountId`,`tut0`,`tut1`,`tut2`,`tut3`,`tut4`,`tut5`,`tut6`,`tut7`) values 
(1,1656750483,8388610,0,0,0,0,0,0);

/*Table structure for table `arena_team` */

DROP TABLE IF EXISTS `arena_team`;

CREATE TABLE `arena_team` (
  `arenaTeamId` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(24) NOT NULL,
  `captainGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `rating` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `rank` int(10) unsigned NOT NULL DEFAULT '0',
  `backgroundColor` int(10) unsigned NOT NULL DEFAULT '0',
  `emblemStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `emblemColor` int(10) unsigned NOT NULL DEFAULT '0',
  `borderStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `borderColor` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`arenaTeamId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_team` */

/*Table structure for table `arena_team_member` */

DROP TABLE IF EXISTS `arena_team_member`;

CREATE TABLE `arena_team_member` (
  `arenaTeamId` int(10) unsigned NOT NULL DEFAULT '0',
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `weekGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `personalRating` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`arenaTeamId`,`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_team_member` */

/*Table structure for table `auctionhouse` */

DROP TABLE IF EXISTS `auctionhouse`;

CREATE TABLE `auctionhouse` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `auctioneerguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `itemguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `itemowner` bigint(20) unsigned NOT NULL DEFAULT '0',
  `buyoutprice` bigint(20) unsigned NOT NULL DEFAULT '0',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `buyguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `lastbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `startbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `deposit` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `item_guid` (`itemguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `auctionhouse` */

/*Table structure for table `blackmarket_auctions` */

DROP TABLE IF EXISTS `blackmarket_auctions`;

CREATE TABLE `blackmarket_auctions` (
  `marketId` int(10) NOT NULL DEFAULT '0',
  `currentBid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `time` int(10) NOT NULL DEFAULT '0',
  `numBids` int(10) NOT NULL DEFAULT '0',
  `bidder` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`marketId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `blackmarket_auctions` */

insert  into `blackmarket_auctions`(`marketId`,`currentBid`,`time`,`numBids`,`bidder`) values 
(2,0,1556223283,0,0),
(33,0,1556223283,0,0),
(38,0,1556223283,0,0),
(43,0,1556223283,0,0),
(46,0,1556223283,0,0),
(53,0,1556223283,0,0),
(55,0,1556223283,0,0),
(56,0,1556223283,0,0),
(59,0,1556223283,0,0),
(63,0,1556223283,0,0),
(64,0,1556223283,0,0),
(78,0,1556223283,0,0);

/*Table structure for table `bugreport` */

DROP TABLE IF EXISTS `bugreport`;

CREATE TABLE `bugreport` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `type` longtext NOT NULL,
  `content` longtext NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Debug System';

/*Data for the table `bugreport` */

/*Table structure for table `calendar_events` */

DROP TABLE IF EXISTS `calendar_events`;

CREATE TABLE `calendar_events` (
  `EventID` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Owner` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Title` varchar(255) NOT NULL DEFAULT '',
  `Description` varchar(255) NOT NULL DEFAULT '',
  `EventType` tinyint(1) unsigned NOT NULL DEFAULT '4',
  `TextureID` int(10) NOT NULL DEFAULT '-1',
  `Date` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `LockDate` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`EventID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `calendar_events` */

/*Table structure for table `calendar_invites` */

DROP TABLE IF EXISTS `calendar_invites`;

CREATE TABLE `calendar_invites` (
  `InviteID` bigint(20) unsigned NOT NULL DEFAULT '0',
  `EventID` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Invitee` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Sender` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Status` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `ResponseTime` int(10) unsigned NOT NULL DEFAULT '0',
  `ModerationRank` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `Note` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`InviteID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `calendar_invites` */

/*Table structure for table `channels` */

DROP TABLE IF EXISTS `channels`;

CREATE TABLE `channels` (
  `name` varchar(128) NOT NULL,
  `team` int(10) unsigned NOT NULL,
  `announce` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `ownership` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `password` varchar(32) DEFAULT NULL,
  `bannedList` text,
  `lastUsed` int(10) unsigned NOT NULL,
  PRIMARY KEY (`name`,`team`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Channel System';

/*Data for the table `channels` */

/*Table structure for table `character_account_data` */

DROP TABLE IF EXISTS `character_account_data`;

CREATE TABLE `character_account_data` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `data` blob NOT NULL,
  PRIMARY KEY (`guid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_account_data` */

insert  into `character_account_data`(`guid`,`type`,`time`,`data`) values 
(1,1,1556137430,'SET autoQuestPopUps \"v\"\r\nSET trackedQuests \"v#|S\"\r\nSET hardTrackedQuests \"v\"\r\nSET trackedWorldQuests \"v\"\r\nSET hardTrackedWorldQuests \"v\"\r\nSET trackedAchievements \"v\"\r\nSET cameraSavedDistance \"5.550000\"\r\nSET cameraSavedPitch \"15.099991\"\r\nSET currencyCategoriesCollapsed \"v\"\r\nSET minimapShapeshiftTracking \"v\"\r\nSET reputationsCollapsed \"v##$\"\r\nSET activeCUFProfile \"Основной\"\r\nSET EJLootClass \"8\"\r\n'),
(1,7,1556137430,'VERSION 6\n\nADDEDVERSION 21\n\nCHANNELS\nОбщий 0 1 0\nТорговля 0 2 0\nОборонаЛокальный 0 3 0\nEND\n\nZONECHANNELS 0\n\nCOLORS\n\nSYSTEM 255 255 0 N\nSAY 255 255 255 N\nPARTY 170 170 255 N\nRAID 255 127 0 N\nGUILD 64 255 64 N\nOFFICER 64 192 64 N\nYELL 255 64 64 N\nWHISPER 255 128 255 N\nWHISPER_FOREIGN 255 128 255 N\nWHISPER_INFORM 255 128 255 N\nEMOTE 255 128 64 N\nTEXT_EMOTE 255 128 64 N\nMONSTER_SAY 255 255 159 N\nMONSTER_PARTY 170 170 255 N\nMONSTER_YELL 255 64 64 N\nMONSTER_WHISPER 255 181 235 N\nMONSTER_EMOTE 255 128 64 N\nCHANNEL 255 192 192 N\nCHANNEL_JOIN 192 128 128 N\nCHANNEL_LEAVE 192 128 128 N\nCHANNEL_LIST 192 128 128 N\nCHANNEL_NOTICE 192 192 192 N\nCHANNEL_NOTICE_USER 192 192 192 N\nAFK 255 128 255 N\nDND 255 128 255 N\nIGNORED 255 0 0 N\nSKILL 85 85 255 N\nLOOT 0 170 0 N\nMONEY 255 255 0 N\nOPENING 128 128 255 N\nTRADESKILLS 255 255 255 N\nPET_INFO 128 128 255 N\nCOMBAT_MISC_INFO 128 128 255 N\nCOMBAT_XP_GAIN 111 111 255 N\nCOMBAT_HONOR_GAIN 224 202 10 N\nCOMBAT_FACTION_CHANGE 128 128 255 N\nBG_SYSTEM_NEUTRAL 255 120 10 N\nBG_SYSTEM_ALLIANCE 0 174 239 N\nBG_SYSTEM_HORDE 255 0 0 N\nRAID_LEADER 255 72 9 N\nRAID_WARNING 255 72 0 N\nRAID_BOSS_EMOTE 255 221 0 N\nRAID_BOSS_WHISPER 255 221 0 N\nFILTERED 255 0 0 N\nRESTRICTED 255 0 0 N\nBATTLENET 255 255 255 N\nACHIEVEMENT 255 255 0 N\nGUILD_ACHIEVEMENT 64 255 64 N\nARENA_POINTS 255 255 255 N\nPARTY_LEADER 118 200 255 N\nTARGETICONS 255 255 0 N\nBN_WHISPER 0 255 246 N\nBN_WHISPER_INFORM 0 255 246 N\nBN_INLINE_TOAST_ALERT 130 197 255 N\nBN_INLINE_TOAST_BROADCAST 130 197 255 N\nBN_INLINE_TOAST_BROADCAST_INFORM 130 197 255 N\nBN_INLINE_TOAST_CONVERSATION 130 197 255 N\nBN_WHISPER_PLAYER_OFFLINE 255 255 0 N\nCURRENCY 0 170 0 N\nQUEST_BOSS_EMOTE 255 128 64 N\nPET_BATTLE_COMBAT_LOG 231 222 171 N\nPET_BATTLE_INFO 225 222 93 N\nINSTANCE_CHAT 255 127 0 N\nINSTANCE_CHAT_LEADER 255 72 9 N\nGUILD_ITEM_LOOTED 64 255 64 N\nCOMMUNITIES_CHANNEL 255 192 192 N\nCHANNEL1 255 192 192 N\nCHANNEL2 255 192 192 N\nCHANNEL3 255 192 192 N\nCHANNEL4 255 192 192 N\nCHANNEL5 255 192 192 N\nCHANNEL6 255 192 192 N\nCHANNEL7 255 192 192 N\nCHANNEL8 255 192 192 N\nCHANNEL9 255 192 192 N\nCHANNEL10 255 192 192 N\nCHANNEL11 255 192 192 N\nCHANNEL12 255 192 192 N\nCHANNEL13 255 192 192 N\nCHANNEL14 255 192 192 N\nCHANNEL15 255 192 192 N\nCHANNEL16 255 192 192 N\nCHANNEL17 255 192 192 N\nCHANNEL18 255 192 192 N\nCHANNEL19 255 192 192 N\nCHANNEL20 255 192 192 N\nEND\n\nWINDOW 1\nNAME Общий\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 1\nSHOWN 1\nMESSAGES\nSYSTEM\nSYSTEM_NOMENU\nSAY\nEMOTE\nYELL\nWHISPER\nPARTY\nPARTY_LEADER\nRAID\nRAID_LEADER\nRAID_WARNING\nGUILD\nOFFICER\nMONSTER_SAY\nMONSTER_YELL\nMONSTER_EMOTE\nMONSTER_WHISPER\nMONSTER_BOSS_EMOTE\nMONSTER_BOSS_WHISPER\nERRORS\nAFK\nDND\nIGNORED\nBG_HORDE\nBG_ALLIANCE\nBG_NEUTRAL\nCOMBAT_FACTION_CHANGE\nSKILL\nLOOT\nMONEY\nCHANNEL\nACHIEVEMENT\nGUILD_ACHIEVEMENT\nBN_WHISPER\nBN_WHISPER_INFORM\nBN_CONVERSATION\nBN_INLINE_TOAST_ALERT\nCURRENCY\nBN_WHISPER_PLAYER_OFFLINE\nPET_BATTLE_INFO\nINSTANCE_CHAT\nINSTANCE_CHAT_LEADER\nGUILD_ITEM_LOOTED\nCOMBAT_HONOR_GAIN\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 2097155\n\nEND\n\nWINDOW 2\nNAME Журнал боя\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 2\nSHOWN 0\nMESSAGES\nOPENING\nTRADESKILLS\nPET_INFO\nCOMBAT_XP_GAIN\nCOMBAT_HONOR_GAIN\nCOMBAT_MISC_INFO\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 3\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 4\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 5\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 6\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 7\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 8\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 9\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 10\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\n'),
(2,1,1556138236,'SET autoQuestPopUps \"v\"\r\nSET trackedQuests \"v(nx\"\r\nSET hardTrackedQuests \"v\"\r\nSET trackedWorldQuests \"v\"\r\nSET hardTrackedWorldQuests \"v\"\r\nSET trackedAchievements \"v\"\r\nSET cameraSavedDistance \"5.550000\"\r\nSET cameraSavedPitch \"13.200003\"\r\nSET currencyCategoriesCollapsed \"v\"\r\nSET minimapShapeshiftTracking \"v\"\r\nSET reputationsCollapsed \"v##$\"\r\nSET activeCUFProfile \"Основной\"\r\nSET EJLootClass \"4\"\r\nSET splashScreenNormal \"13\"\r\n'),
(2,7,1556138236,'VERSION 6\n\nADDEDVERSION 21\n\nCHANNELS\nОбщий 0 1 0\nТорговля 0 2 0\nОборонаЛокальный 0 3 0\nEND\n\nZONECHANNELS 0\n\nCOLORS\n\nSYSTEM 255 255 0 N\nSAY 255 255 255 N\nPARTY 170 170 255 N\nRAID 255 127 0 N\nGUILD 64 255 64 N\nOFFICER 64 192 64 N\nYELL 255 64 64 N\nWHISPER 255 128 255 N\nWHISPER_FOREIGN 255 128 255 N\nWHISPER_INFORM 255 128 255 N\nEMOTE 255 128 64 N\nTEXT_EMOTE 255 128 64 N\nMONSTER_SAY 255 255 159 N\nMONSTER_PARTY 170 170 255 N\nMONSTER_YELL 255 64 64 N\nMONSTER_WHISPER 255 181 235 N\nMONSTER_EMOTE 255 128 64 N\nCHANNEL 255 192 192 N\nCHANNEL_JOIN 192 128 128 N\nCHANNEL_LEAVE 192 128 128 N\nCHANNEL_LIST 192 128 128 N\nCHANNEL_NOTICE 192 192 192 N\nCHANNEL_NOTICE_USER 192 192 192 N\nAFK 255 128 255 N\nDND 255 128 255 N\nIGNORED 255 0 0 N\nSKILL 85 85 255 N\nLOOT 0 170 0 N\nMONEY 255 255 0 N\nOPENING 128 128 255 N\nTRADESKILLS 255 255 255 N\nPET_INFO 128 128 255 N\nCOMBAT_MISC_INFO 128 128 255 N\nCOMBAT_XP_GAIN 111 111 255 N\nCOMBAT_HONOR_GAIN 224 202 10 N\nCOMBAT_FACTION_CHANGE 128 128 255 N\nBG_SYSTEM_NEUTRAL 255 120 10 N\nBG_SYSTEM_ALLIANCE 0 174 239 N\nBG_SYSTEM_HORDE 255 0 0 N\nRAID_LEADER 255 72 9 N\nRAID_WARNING 255 72 0 N\nRAID_BOSS_EMOTE 255 221 0 N\nRAID_BOSS_WHISPER 255 221 0 N\nFILTERED 255 0 0 N\nRESTRICTED 255 0 0 N\nBATTLENET 255 255 255 N\nACHIEVEMENT 255 255 0 N\nGUILD_ACHIEVEMENT 64 255 64 N\nARENA_POINTS 255 255 255 N\nPARTY_LEADER 118 200 255 N\nTARGETICONS 255 255 0 N\nBN_WHISPER 0 255 246 N\nBN_WHISPER_INFORM 0 255 246 N\nBN_INLINE_TOAST_ALERT 130 197 255 N\nBN_INLINE_TOAST_BROADCAST 130 197 255 N\nBN_INLINE_TOAST_BROADCAST_INFORM 130 197 255 N\nBN_INLINE_TOAST_CONVERSATION 130 197 255 N\nBN_WHISPER_PLAYER_OFFLINE 255 255 0 N\nCURRENCY 0 170 0 N\nQUEST_BOSS_EMOTE 255 128 64 N\nPET_BATTLE_COMBAT_LOG 231 222 171 N\nPET_BATTLE_INFO 225 222 93 N\nINSTANCE_CHAT 255 127 0 N\nINSTANCE_CHAT_LEADER 255 72 9 N\nGUILD_ITEM_LOOTED 64 255 64 N\nCOMMUNITIES_CHANNEL 255 192 192 N\nCHANNEL1 255 192 192 N\nCHANNEL2 255 192 192 N\nCHANNEL3 255 192 192 N\nCHANNEL4 255 192 192 N\nCHANNEL5 255 192 192 N\nCHANNEL6 255 192 192 N\nCHANNEL7 255 192 192 N\nCHANNEL8 255 192 192 N\nCHANNEL9 255 192 192 N\nCHANNEL10 255 192 192 N\nCHANNEL11 255 192 192 N\nCHANNEL12 255 192 192 N\nCHANNEL13 255 192 192 N\nCHANNEL14 255 192 192 N\nCHANNEL15 255 192 192 N\nCHANNEL16 255 192 192 N\nCHANNEL17 255 192 192 N\nCHANNEL18 255 192 192 N\nCHANNEL19 255 192 192 N\nCHANNEL20 255 192 192 N\nEND\n\nWINDOW 1\nNAME Общий\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 1\nSHOWN 1\nMESSAGES\nSYSTEM\nSYSTEM_NOMENU\nSAY\nEMOTE\nYELL\nWHISPER\nPARTY\nPARTY_LEADER\nRAID\nRAID_LEADER\nRAID_WARNING\nGUILD\nOFFICER\nMONSTER_SAY\nMONSTER_YELL\nMONSTER_EMOTE\nMONSTER_WHISPER\nMONSTER_BOSS_EMOTE\nMONSTER_BOSS_WHISPER\nERRORS\nAFK\nDND\nIGNORED\nBG_HORDE\nBG_ALLIANCE\nBG_NEUTRAL\nCOMBAT_FACTION_CHANGE\nSKILL\nLOOT\nMONEY\nCHANNEL\nACHIEVEMENT\nGUILD_ACHIEVEMENT\nBN_WHISPER\nBN_WHISPER_INFORM\nBN_CONVERSATION\nBN_INLINE_TOAST_ALERT\nCURRENCY\nBN_WHISPER_PLAYER_OFFLINE\nPET_BATTLE_INFO\nINSTANCE_CHAT\nINSTANCE_CHAT_LEADER\nGUILD_ITEM_LOOTED\nCOMBAT_HONOR_GAIN\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 2097155\n\nEND\n\nWINDOW 2\nNAME Журнал боя\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 2\nSHOWN 0\nMESSAGES\nOPENING\nTRADESKILLS\nPET_INFO\nCOMBAT_XP_GAIN\nCOMBAT_HONOR_GAIN\nCOMBAT_MISC_INFO\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 3\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 4\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 5\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 6\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 7\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 8\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 9\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\nWINDOW 10\nSIZE 0\nCOLOR 0 0 0 40\nLOCKED 1\nUNINTERACTABLE 0\nDOCKED 0\nSHOWN 0\nMESSAGES\nEND\n\nCHANNELS\nEND\n\nZONECHANNELS 0\n\nEND\n\n');

/*Table structure for table `character_achievement` */

DROP TABLE IF EXISTS `character_achievement`;

CREATE TABLE `character_achievement` (
  `guid` bigint(20) unsigned NOT NULL,
  `achievement` int(10) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`achievement`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_achievement` */

insert  into `character_achievement`(`guid`,`achievement`,`date`) values 
(1,429,1556137430),
(1,522,1556137430),
(1,1017,1556137430),
(1,2398,1556137430),
(1,3636,1556137430),
(1,4400,1556137430),
(1,5512,1556137430),
(1,5863,1556137430),
(1,6131,1556137430),
(1,7853,1556137430),
(1,8820,1556137430),
(1,9016,1556137430),
(1,9496,1556137430),
(1,10056,1556137430),
(1,10058,1556137430),
(1,10741,1556137430),
(1,11210,1556137430),
(1,11211,1556137430),
(1,11606,1556137430),
(1,11632,1556137430),
(1,11633,1556137430),
(1,11847,1556137430),
(1,11848,1556137430),
(1,12827,1556137430),
(1,13149,1556137430),
(1,13152,1556137430),
(1,13153,1556137430),
(1,13155,1556137430),
(1,13166,1556137430),
(1,13167,1556137430),
(1,13169,1556137430),
(1,13170,1556137430),
(2,6,1556138203),
(2,7,1556138203),
(2,429,1556138203),
(2,522,1556138203),
(2,891,1556138203),
(2,1017,1556138203),
(2,2398,1556138203),
(2,3636,1556138203),
(2,4400,1556138203),
(2,5512,1556138203),
(2,5863,1556138203),
(2,6131,1556138203),
(2,7853,1556138203),
(2,8820,1556138203),
(2,9016,1556138203),
(2,9496,1556138203),
(2,10056,1556138203),
(2,10058,1556138203),
(2,10741,1556138203),
(2,11210,1556138203),
(2,11211,1556138203),
(2,11606,1556138203),
(2,11632,1556138203),
(2,11633,1556138203),
(2,11847,1556138203),
(2,11848,1556138203),
(2,12242,1556138203),
(2,12450,1556138203),
(2,12827,1556138203),
(2,13149,1556138203),
(2,13152,1556138203),
(2,13153,1556138203),
(2,13155,1556138203),
(2,13166,1556138203),
(2,13167,1556138203),
(2,13169,1556138203),
(2,13170,1556138203);

/*Table structure for table `character_achievement_progress` */

DROP TABLE IF EXISTS `character_achievement_progress`;

CREATE TABLE `character_achievement_progress` (
  `guid` bigint(20) unsigned NOT NULL,
  `criteria` int(10) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_achievement_progress` */

insert  into `character_achievement_progress`(`guid`,`criteria`,`counter`,`date`) values 
(1,162,45,1556138159),
(1,167,1,1556137430),
(1,653,1,1556137430),
(1,657,1,1556137430),
(1,753,1,1556137430),
(1,757,5,1556137430),
(1,982,1,1556137430),
(1,1508,1,1556137469),
(1,2020,200,1556137430),
(1,4742,3000,1556137430),
(1,4763,3500,1556137430),
(1,4944,3,1556138159),
(1,4946,3,1556138159),
(1,4948,3,1556138159),
(1,5018,1,1556137430),
(1,5212,1,1556137430),
(1,5230,1,1556137430),
(1,5299,1,1556137430),
(1,5300,1,1556137430),
(1,5301,8,1556137430),
(1,5313,500,1556137430),
(1,5314,500,1556137430),
(1,5315,500,1556137430),
(1,5316,3100,1556137430),
(1,5317,4000,1556137430),
(1,5371,1,1556137494),
(1,5372,7,1556137535),
(1,5373,5,1556137494),
(1,5529,3,1556138159),
(1,5531,3,1556138159),
(1,6789,2,1556137432),
(1,9058,1,1556137430),
(1,11238,1,1556137430),
(1,12562,1,1556137430),
(1,12698,20,1556137430),
(1,16082,1,1556137430),
(1,16825,3100,1556137430),
(1,17804,1,1556137430),
(1,18500,1,1556137430),
(1,19395,3000,1556137430),
(1,19480,3100,1556137430),
(1,19598,1,1556137430),
(1,20677,1,1556137430),
(1,20678,1,1556137430),
(1,22242,1,1556137430),
(1,22927,3000,1556137430),
(1,23250,2,1556137432),
(1,24192,1,1556137430),
(1,24745,1,1556137430),
(1,25827,3000,1556137430),
(1,25830,3000,1556137430),
(1,25887,1,1556137430),
(1,28201,1,1556137430),
(1,28720,1,1556137430),
(1,28978,3000,1556137430),
(1,30478,2,1556137432),
(1,30977,1,1556137430),
(1,32886,1,1556137430),
(1,32887,1,1556137430),
(1,35786,1,1556137430),
(1,35787,1,1556137430),
(1,35889,1,1556137430),
(1,35977,3000,1556137430),
(1,36132,1,1556137430),
(1,36696,1,1556137430),
(1,36699,1,1556137430),
(1,37604,3000,1556137430),
(1,39940,1,1556137430),
(1,40478,1,1556137430),
(1,40921,1,1556137430),
(1,41655,3000,1556137430),
(1,43143,1,1556137430),
(1,43157,1,1556137430),
(1,43160,1,1556137430),
(1,43205,1,1556137430),
(1,43206,1,1556137430),
(1,43211,1,1556137430),
(1,43215,1,1556137430),
(2,167,1,1556138203),
(2,641,1,1556138203),
(2,651,1,1556138203),
(2,652,1,1556138203),
(2,653,1,1556138203),
(2,654,1,1556138203),
(2,655,1,1556138203),
(2,753,1,1556138203),
(2,982,1,1556138203),
(2,1872,75,1556138203),
(2,2020,200,1556138203),
(2,3631,1,1556138320),
(2,4092,125,1556138320),
(2,4224,125,1556138320),
(2,5212,20,1556138203),
(2,5221,20,1556138203),
(2,5299,1,1556138203),
(2,5300,1,1556138203),
(2,5301,9,1556138203),
(2,5328,3100,1556138203),
(2,5329,3100,1556138203),
(2,5330,3100,1556138203),
(2,5331,3100,1556138203),
(2,5332,3000,1556138203),
(2,6142,1,1556138193),
(2,6789,6,1556140515),
(2,9058,1,1556138203),
(2,11238,1,1556138203),
(2,12562,1,1556138203),
(2,12698,60,1556138203),
(2,16082,1,1556138203),
(2,17804,1,1556138203),
(2,18500,1,1556138203),
(2,19395,3000,1556138203),
(2,19481,3100,1556138203),
(2,19598,3,1556140511),
(2,20677,20,1556138203),
(2,20678,20,1556138203),
(2,22242,1,1556138203),
(2,22926,3000,1556138203),
(2,23250,6,1556140515),
(2,24192,1,1556138203),
(2,24745,1,1556138203),
(2,25828,3000,1556138203),
(2,25887,1,1556138203),
(2,26682,1,1556138193),
(2,28201,1,1556138203),
(2,28720,1,1556138203),
(2,28828,1,1556138193),
(2,28829,1,1556138193),
(2,28830,1,1556138193),
(2,28831,1,1556138193),
(2,28832,1,1556138193),
(2,28833,1,1556138193),
(2,28839,1,1556138193),
(2,28858,1,1556138193),
(2,28981,3000,1556138203),
(2,30478,6,1556140515),
(2,30576,1,1556138320),
(2,30977,1,1556138203),
(2,32886,1,1556138203),
(2,32887,1,1556138203),
(2,35786,1,1556138203),
(2,35787,1,1556138203),
(2,35889,1,1556138203),
(2,35977,3000,1556138203),
(2,36132,1,1556138203),
(2,36696,1,1556138203),
(2,36699,1,1556138203),
(2,37603,3000,1556138203),
(2,37604,3000,1556138203),
(2,39653,1,1556138203),
(2,40478,1,1556138203),
(2,40921,1,1556138203),
(2,41244,1,1556138193),
(2,41654,3000,1556138203),
(2,43143,1,1556138203),
(2,43157,1,1556138203),
(2,43160,1,1556138203),
(2,43205,1,1556138203),
(2,43206,1,1556138203),
(2,43211,1,1556138203),
(2,43215,1,1556138203);

/*Table structure for table `character_action` */

DROP TABLE IF EXISTS `character_action`;

CREATE TABLE `character_action` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `spec` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `button` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `action` int(10) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spec`,`button`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_action` */

insert  into `character_action`(`guid`,`spec`,`button`,`action`,`type`) values 
(1,2,0,116,0),
(1,2,9,28730,0);

/*Table structure for table `character_archaeology_branchs` */

DROP TABLE IF EXISTS `character_archaeology_branchs`;

CREATE TABLE `character_archaeology_branchs` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `projectId` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_archaeology_branchs` */

/*Table structure for table `character_archaeology_digsites` */

DROP TABLE IF EXISTS `character_archaeology_digsites`;

CREATE TABLE `character_archaeology_digsites` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `digsiteId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `point_x` float DEFAULT '0',
  `point_y` float DEFAULT '0',
  `count` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`digsiteId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_archaeology_digsites` */

/*Table structure for table `character_archaeology_history` */

DROP TABLE IF EXISTS `character_archaeology_history`;

CREATE TABLE `character_archaeology_history` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `time` smallint(5) unsigned NOT NULL DEFAULT '0',
  `projectId` int(10) unsigned NOT NULL DEFAULT '0',
  `count` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_archaeology_history` */

/*Table structure for table `character_arena_data` */

DROP TABLE IF EXISTS `character_arena_data`;

CREATE TABLE `character_arena_data` (
  `guid` bigint(20) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `rating` int(10) unsigned NOT NULL DEFAULT '0',
  `bestRatingOfWeek` int(10) unsigned NOT NULL DEFAULT '0',
  `bestRatingOfSeason` int(10) unsigned NOT NULL DEFAULT '0',
  `matchMakerRating` int(10) unsigned NOT NULL DEFAULT '0',
  `weekGames` int(10) unsigned NOT NULL DEFAULT '0',
  `weekWins` int(10) unsigned NOT NULL DEFAULT '0',
  `prevWeekGames` int(10) unsigned NOT NULL DEFAULT '0',
  `prevWeekWins` int(10) unsigned NOT NULL DEFAULT '0',
  `seasonGames` int(10) unsigned NOT NULL DEFAULT '0',
  `seasonWins` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`slot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_arena_data` */

insert  into `character_arena_data`(`guid`,`slot`,`rating`,`bestRatingOfWeek`,`bestRatingOfSeason`,`matchMakerRating`,`weekGames`,`weekWins`,`prevWeekGames`,`prevWeekWins`,`seasonGames`,`seasonWins`) values 
(1,0,0,0,0,1500,0,0,0,0,0,0),
(1,1,0,0,0,1500,0,0,0,0,0,0),
(1,2,0,0,0,1500,0,0,0,0,0,0),
(1,3,0,0,0,1500,0,0,0,0,0,0),
(1,4,0,0,0,1500,0,0,0,0,0,0),
(1,5,0,0,0,1500,0,0,0,0,0,0),
(2,0,0,0,0,1500,0,0,0,0,0,0),
(2,1,0,0,0,1500,0,0,0,0,0,0),
(2,2,0,0,0,1500,0,0,0,0,0,0),
(2,3,0,0,0,1500,0,0,0,0,0,0),
(2,4,0,0,0,1500,0,0,0,0,0,0),
(2,5,0,0,0,1500,0,0,0,0,0,0);

/*Table structure for table `character_aura` */

DROP TABLE IF EXISTS `character_aura`;

CREATE TABLE `character_aura` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  `itemGuid` binary(16) NOT NULL,
  `spell` int(10) unsigned NOT NULL,
  `effectMask` int(10) unsigned NOT NULL,
  `recalculateMask` int(10) unsigned NOT NULL DEFAULT '0',
  `stackCount` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `maxDuration` int(11) NOT NULL DEFAULT '0',
  `remainTime` int(11) NOT NULL DEFAULT '0',
  `remainCharges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `castItemLevel` int(11) NOT NULL DEFAULT '-1',
  PRIMARY KEY (`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_aura` */

insert  into `character_aura`(`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`,`recalculateMask`,`stackCount`,`maxDuration`,`remainTime`,`remainCharges`,`castItemLevel`) values 
(2,'\0\0\0\0\0\0\0\0\0\0\0\0\0','\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',59074,1,1,1,-1,-1,0,-1),
(2,'\0\0\0\0\0\0\0\0\0\0\0\0\0','\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',172329,1,1,1,-1,-1,0,-1);

/*Table structure for table `character_aura_effect` */

DROP TABLE IF EXISTS `character_aura_effect`;

CREATE TABLE `character_aura_effect` (
  `guid` bigint(20) unsigned NOT NULL,
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  `itemGuid` binary(16) NOT NULL,
  `spell` int(10) unsigned NOT NULL,
  `effectMask` int(10) unsigned NOT NULL,
  `effectIndex` tinyint(3) unsigned NOT NULL,
  `amount` int(11) NOT NULL DEFAULT '0',
  `baseAmount` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`,`effectIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_aura_effect` */

insert  into `character_aura_effect`(`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`,`effectIndex`,`amount`,`baseAmount`) values 
(2,'\0\0\0\0\0\0\0\0\0\0\0\0\0','\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',59074,1,0,0,0),
(2,'\0\0\0\0\0\0\0\0\0\0\0\0\0','\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',172329,1,0,0,0);

/*Table structure for table `character_banned` */

DROP TABLE IF EXISTS `character_banned`;

CREATE TABLE `character_banned` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`guid`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';

/*Data for the table `character_banned` */

/*Table structure for table `character_battleground_data` */

DROP TABLE IF EXISTS `character_battleground_data`;

CREATE TABLE `character_battleground_data` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `instanceId` int(10) unsigned NOT NULL COMMENT 'Instance Identifier',
  `team` smallint(5) unsigned NOT NULL,
  `joinX` float NOT NULL DEFAULT '0',
  `joinY` float NOT NULL DEFAULT '0',
  `joinZ` float NOT NULL DEFAULT '0',
  `joinO` float NOT NULL DEFAULT '0',
  `joinMapId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `taxiStart` int(10) unsigned NOT NULL DEFAULT '0',
  `taxiEnd` int(10) unsigned NOT NULL DEFAULT '0',
  `mountSpell` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_battleground_data` */

insert  into `character_battleground_data`(`guid`,`instanceId`,`team`,`joinX`,`joinY`,`joinZ`,`joinO`,`joinMapId`,`taxiStart`,`taxiEnd`,`mountSpell`) values 
(1,0,0,0,0,0,0,65535,0,0,0),
(2,0,0,0,0,0,0,65535,0,0,0);

/*Table structure for table `character_battleground_random` */

DROP TABLE IF EXISTS `character_battleground_random`;

CREATE TABLE `character_battleground_random` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_battleground_random` */

/*Table structure for table `character_cuf_profiles` */

DROP TABLE IF EXISTS `character_cuf_profiles`;

CREATE TABLE `character_cuf_profiles` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Guid',
  `id` tinyint(3) unsigned NOT NULL COMMENT 'Profile Id (0-4)',
  `name` varchar(12) NOT NULL COMMENT 'Profile Name',
  `frameHeight` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Profile Frame Height',
  `frameWidth` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Profile Frame Width',
  `sortBy` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame Sort By',
  `healthText` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame Health Text',
  `boolOptions` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Many Configurable Bool Options',
  `topPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame top alignment',
  `bottomPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame bottom alignment',
  `leftPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame left alignment',
  `topOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from top',
  `bottomOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from bottom',
  `leftOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from left',
  PRIMARY KEY (`guid`,`id`),
  KEY `index` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_cuf_profiles` */

insert  into `character_cuf_profiles`(`guid`,`id`,`name`,`frameHeight`,`frameWidth`,`sortBy`,`healthText`,`boolOptions`,`topPoint`,`bottomPoint`,`leftPoint`,`topOffset`,`bottomOffset`,`leftOffset`) values 
(1,0,'Основной',36,72,0,0,15516,0,0,0,0,0,0),
(2,0,'Основной',36,72,0,0,15516,0,0,0,0,0,0);

/*Table structure for table `character_currency` */

DROP TABLE IF EXISTS `character_currency`;

CREATE TABLE `character_currency` (
  `CharacterGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Currency` smallint(5) unsigned NOT NULL,
  `Quantity` int(10) unsigned NOT NULL,
  `WeeklyQuantity` int(10) unsigned NOT NULL,
  `TrackedQuantity` int(10) unsigned NOT NULL,
  `Flags` tinyint(3) unsigned NOT NULL,
  `WeekCap` int(10) unsigned NOT NULL,
  PRIMARY KEY (`CharacterGuid`,`Currency`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_currency` */

insert  into `character_currency`(`CharacterGuid`,`Currency`,`Quantity`,`WeeklyQuantity`,`TrackedQuantity`,`Flags`,`WeekCap`) values 
(1,395,0,0,0,0,4294967294),
(1,823,0,0,0,0,4294967294),
(2,395,0,0,0,0,4294967294),
(2,823,0,0,0,0,4294967294);

/*Table structure for table `character_declinedname` */

DROP TABLE IF EXISTS `character_declinedname`;

CREATE TABLE `character_declinedname` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `genitive` varchar(15) NOT NULL DEFAULT '',
  `dative` varchar(15) NOT NULL DEFAULT '',
  `accusative` varchar(15) NOT NULL DEFAULT '',
  `instrumental` varchar(15) NOT NULL DEFAULT '',
  `prepositional` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_declinedname` */

/*Table structure for table `character_equipmentsets` */

DROP TABLE IF EXISTS `character_equipmentsets`;

CREATE TABLE `character_equipmentsets` (
  `guid` bigint(20) NOT NULL DEFAULT '0',
  `setguid` bigint(20) NOT NULL AUTO_INCREMENT,
  `setindex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `name` varchar(31) NOT NULL,
  `iconname` varchar(100) NOT NULL,
  `ignore_mask` int(11) unsigned NOT NULL DEFAULT '0',
  `AssignedSpecIndex` int(11) NOT NULL DEFAULT '-1',
  `item0` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item1` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item2` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item3` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item4` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item5` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item6` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item7` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item8` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item9` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item10` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item11` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item12` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item13` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item14` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item15` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item16` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item17` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item18` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`setguid`),
  UNIQUE KEY `idx_set` (`guid`,`setguid`,`setindex`),
  KEY `Idx_setindex` (`setindex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_equipmentsets` */

/*Table structure for table `character_fishingsteps` */

DROP TABLE IF EXISTS `character_fishingsteps`;

CREATE TABLE `character_fishingsteps` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `fishingSteps` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_fishingsteps` */

/*Table structure for table `character_garrison` */

DROP TABLE IF EXISTS `character_garrison`;

CREATE TABLE `character_garrison` (
  `guid` bigint(20) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `siteLevelId` int(10) unsigned NOT NULL DEFAULT '0',
  `followerActivationsRemainingToday` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_garrison` */

/*Table structure for table `character_garrison_blueprints` */

DROP TABLE IF EXISTS `character_garrison_blueprints`;

CREATE TABLE `character_garrison_blueprints` (
  `guid` bigint(20) unsigned NOT NULL,
  `garrison_type` tinyint(3) unsigned NOT NULL,
  `buildingId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`garrison_type`,`buildingId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_garrison_blueprints` */

/*Table structure for table `character_garrison_buildings` */

DROP TABLE IF EXISTS `character_garrison_buildings`;

CREATE TABLE `character_garrison_buildings` (
  `guid` bigint(20) unsigned NOT NULL,
  `garrison_type` tinyint(3) unsigned NOT NULL,
  `plotInstanceId` int(10) unsigned NOT NULL DEFAULT '0',
  `buildingId` int(10) unsigned NOT NULL DEFAULT '0',
  `timeBuilt` bigint(20) unsigned NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`garrison_type`,`plotInstanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_garrison_buildings` */

/*Table structure for table `character_garrison_follower_abilities` */

DROP TABLE IF EXISTS `character_garrison_follower_abilities`;

CREATE TABLE `character_garrison_follower_abilities` (
  `dbId` bigint(20) unsigned NOT NULL,
  `abilityId` int(10) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`dbId`,`abilityId`,`slot`),
  CONSTRAINT `fk_foll_dbid` FOREIGN KEY (`dbId`) REFERENCES `character_garrison_followers` (`dbId`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_garrison_follower_abilities` */

/*Table structure for table `character_garrison_followers` */

DROP TABLE IF EXISTS `character_garrison_followers`;

CREATE TABLE `character_garrison_followers` (
  `dbId` bigint(20) unsigned NOT NULL,
  `guid` bigint(20) unsigned NOT NULL,
  `garrison_type` tinyint(3) unsigned NOT NULL,
  `followerId` int(10) unsigned NOT NULL,
  `quality` int(10) unsigned NOT NULL DEFAULT '2',
  `level` int(10) unsigned NOT NULL DEFAULT '90',
  `itemLevelWeapon` int(10) unsigned NOT NULL DEFAULT '600',
  `itemLevelArmor` int(10) unsigned NOT NULL DEFAULT '600',
  `xp` int(10) unsigned NOT NULL DEFAULT '0',
  `currentBuilding` int(10) unsigned NOT NULL DEFAULT '0',
  `currentMission` int(10) unsigned NOT NULL DEFAULT '0',
  `status` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`dbId`),
  UNIQUE KEY `idx_guid_id` (`guid`,`followerId`),
  CONSTRAINT `fk_foll_owner` FOREIGN KEY (`guid`) REFERENCES `characters` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_garrison_followers` */

/*Table structure for table `character_garrison_mission_rewards` */

DROP TABLE IF EXISTS `character_garrison_mission_rewards`;

CREATE TABLE `character_garrison_mission_rewards` (
  `dbId` int(10) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `itemId` int(10) NOT NULL DEFAULT '0',
  `itemQuantity` int(10) unsigned NOT NULL DEFAULT '0',
  `currencyId` int(10) NOT NULL DEFAULT '0',
  `currencyQuantity` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerXP` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusAbilityId` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_garrison_mission_rewards` */

/*Table structure for table `character_garrison_missions` */

DROP TABLE IF EXISTS `character_garrison_missions`;

CREATE TABLE `character_garrison_missions` (
  `dbId` bigint(20) unsigned NOT NULL,
  `guid` bigint(20) unsigned NOT NULL,
  `garrison_type` tinyint(3) unsigned NOT NULL,
  `missionId` int(10) unsigned NOT NULL,
  `offerTime` int(10) NOT NULL,
  `startTime` int(10) NOT NULL,
  `status` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`dbId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_garrison_missions` */

/*Table structure for table `character_gifts` */

DROP TABLE IF EXISTS `character_gifts`;

CREATE TABLE `character_gifts` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `item_guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `entry` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`item_guid`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_gifts` */

/*Table structure for table `character_glyphs` */

DROP TABLE IF EXISTS `character_glyphs`;

CREATE TABLE `character_glyphs` (
  `guid` bigint(20) unsigned NOT NULL,
  `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `glyphId` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`talentGroup`,`glyphId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_glyphs` */

/*Table structure for table `character_homebind` */

DROP TABLE IF EXISTS `character_homebind`;

CREATE TABLE `character_homebind` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `zoneId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Zone Identifier',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_homebind` */

insert  into `character_homebind`(`guid`,`mapId`,`zoneId`,`posX`,`posY`,`posZ`) values 
(1,530,3431,10349.6,-6357.29,33.4026),
(2,1865,9415,2121,3318,54.7061);

/*Table structure for table `character_instance` */

DROP TABLE IF EXISTS `character_instance`;

CREATE TABLE `character_instance` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `instance` int(10) unsigned NOT NULL DEFAULT '0',
  `permanent` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `extendState` tinyint(2) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_instance` */

/*Table structure for table `character_inventory` */

DROP TABLE IF EXISTS `character_inventory`;

CREATE TABLE `character_inventory` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `bag` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `item` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Item Global Unique Identifier',
  PRIMARY KEY (`item`),
  UNIQUE KEY `guid` (`guid`,`bag`,`slot`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_inventory` */

insert  into `character_inventory`(`guid`,`bag`,`slot`,`item`) values 
(1,0,4,2),
(1,0,6,4),
(1,0,7,8),
(1,0,15,6),
(1,0,23,10),
(1,0,24,24),
(1,0,25,25),
(1,0,26,26),
(1,0,27,27),
(2,0,4,45),
(2,0,5,35),
(2,0,6,37),
(2,0,7,41),
(2,0,8,33),
(2,0,9,39),
(2,0,15,29),
(2,0,16,31),
(2,0,19,47),
(2,0,20,49),
(2,0,21,51),
(2,0,22,53),
(2,0,23,43),
(2,0,24,55),
(2,0,25,69),
(2,0,26,70);

/*Table structure for table `character_pet` */

DROP TABLE IF EXISTS `character_pet`;

CREATE TABLE `character_pet` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `entry` int(10) unsigned NOT NULL DEFAULT '0',
  `owner` bigint(10) unsigned NOT NULL DEFAULT '0',
  `modelid` int(10) unsigned DEFAULT '0',
  `CreatedBySpell` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `PetType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `level` smallint(5) unsigned NOT NULL DEFAULT '1',
  `exp` int(10) unsigned NOT NULL DEFAULT '0',
  `Reactstate` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `name` varchar(21) NOT NULL DEFAULT 'Pet',
  `renamed` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `active` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `slot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `curhealth` int(10) unsigned NOT NULL DEFAULT '1',
  `curmana` int(10) unsigned NOT NULL DEFAULT '0',
  `savetime` int(10) unsigned NOT NULL DEFAULT '0',
  `abdata` text,
  `specialization` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`),
  KEY `idx_slot` (`slot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `character_pet` */

/*Table structure for table `character_pet_declinedname` */

DROP TABLE IF EXISTS `character_pet_declinedname`;

CREATE TABLE `character_pet_declinedname` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `owner` int(10) unsigned NOT NULL DEFAULT '0',
  `genitive` varchar(12) NOT NULL DEFAULT '',
  `dative` varchar(12) NOT NULL DEFAULT '',
  `accusative` varchar(12) NOT NULL DEFAULT '',
  `instrumental` varchar(12) NOT NULL DEFAULT '',
  `prepositional` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  KEY `owner_key` (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_pet_declinedname` */

/*Table structure for table `character_pvp_talent` */

DROP TABLE IF EXISTS `character_pvp_talent`;

CREATE TABLE `character_pvp_talent` (
  `Guid` bigint(20) unsigned NOT NULL,
  `talentId0` int(10) unsigned NOT NULL,
  `talentId1` int(10) unsigned NOT NULL,
  `talentId2` int(10) unsigned NOT NULL,
  `talentId3` int(10) unsigned NOT NULL,
  `TalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Guid`,`TalentGroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_pvp_talent` */

insert  into `character_pvp_talent`(`Guid`,`talentId0`,`talentId1`,`talentId2`,`talentId3`,`TalentGroup`) values 
(1,0,0,80,0,0),
(1,0,0,0,0,1),
(1,0,0,0,0,2),
(1,0,0,0,0,3),
(2,0,0,0,0,0),
(2,0,0,0,0,1),
(2,0,0,0,0,2),
(2,0,0,16,0,3);

/*Table structure for table `character_queststatus` */

DROP TABLE IF EXISTS `character_queststatus`;

CREATE TABLE `character_queststatus` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `quest` int(10) unsigned NOT NULL DEFAULT '0',
  `status` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `timer` int(10) unsigned NOT NULL DEFAULT '0',
  `explored` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus` */

insert  into `character_queststatus`(`guid`,`quest`,`status`,`timer`,`explored`) values 
(1,8325,3,1556138173,0),
(2,50305,3,1556138349,0);

/*Table structure for table `character_queststatus_daily` */

DROP TABLE IF EXISTS `character_queststatus_daily`;

CREATE TABLE `character_queststatus_daily` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_daily` */

/*Table structure for table `character_queststatus_monthly` */

DROP TABLE IF EXISTS `character_queststatus_monthly`;

CREATE TABLE `character_queststatus_monthly` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_monthly` */

/*Table structure for table `character_queststatus_objectives` */

DROP TABLE IF EXISTS `character_queststatus_objectives`;

CREATE TABLE `character_queststatus_objectives` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `quest` int(10) unsigned NOT NULL DEFAULT '0',
  `objective` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `data` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`quest`,`objective`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_objectives` */

insert  into `character_queststatus_objectives`(`guid`,`quest`,`objective`,`data`) values 
(1,8325,0,3),
(2,50305,0,0),
(2,50305,1,0);

/*Table structure for table `character_queststatus_objectives_criteria` */

DROP TABLE IF EXISTS `character_queststatus_objectives_criteria`;

CREATE TABLE `character_queststatus_objectives_criteria` (
  `guid` bigint(20) unsigned NOT NULL,
  `questObjectiveId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`questObjectiveId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_objectives_criteria` */

insert  into `character_queststatus_objectives_criteria`(`guid`,`questObjectiveId`) values 
(1,278862),
(1,279097),
(1,279348),
(1,279352),
(1,283743),
(1,283886),
(1,283921),
(1,284137),
(1,284138),
(1,284386),
(1,284387),
(1,284425),
(1,284426),
(1,284459),
(1,284460),
(1,284462),
(1,284463),
(1,284556),
(1,284557),
(1,284559),
(1,284560),
(1,284569),
(1,284570),
(1,284582),
(1,284583),
(1,284729),
(1,284730),
(1,284847),
(1,285013),
(1,285126),
(1,285127),
(1,285140),
(1,285141),
(1,285152),
(1,285153),
(2,278862),
(2,279097),
(2,279348),
(2,279352),
(2,283743),
(2,283886),
(2,283921),
(2,284137),
(2,284138),
(2,284386),
(2,284387),
(2,284425),
(2,284426),
(2,284459),
(2,284460),
(2,284462),
(2,284463),
(2,284556),
(2,284557),
(2,284559),
(2,284560),
(2,284569),
(2,284570),
(2,284582),
(2,284583),
(2,284729),
(2,284730),
(2,284847),
(2,285013),
(2,285126),
(2,285127),
(2,285140),
(2,285141),
(2,285152),
(2,285153);

/*Table structure for table `character_queststatus_objectives_criteria_progress` */

DROP TABLE IF EXISTS `character_queststatus_objectives_criteria_progress`;

CREATE TABLE `character_queststatus_objectives_criteria_progress` (
  `guid` bigint(20) unsigned NOT NULL,
  `criteriaId` int(10) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`criteriaId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_objectives_criteria_progress` */

insert  into `character_queststatus_objectives_criteria_progress`(`guid`,`criteriaId`,`counter`,`date`) values 
(1,28071,1,1556137430),
(1,28431,1,1556137430),
(1,28451,1,1556137430),
(1,28472,1,1556137430),
(1,30128,1,1556137430),
(1,30129,1,1556137430),
(1,30391,1,1556137430),
(1,30394,1,1556137430),
(1,30399,1,1556137430),
(1,30400,1,1556137430),
(1,30406,1,1556137430),
(1,30407,1,1556137430),
(1,30436,1,1556137430),
(1,30437,1,1556137430),
(1,30438,1,1556137430),
(1,30439,1,1556137430),
(1,30509,1,1556137430),
(1,30510,1,1556137430),
(1,30511,1,1556137430),
(1,30514,1,1556137430),
(1,30515,1,1556137430),
(1,30516,1,1556137430),
(1,30517,1,1556137430),
(1,30533,1,1556137430),
(1,30534,1,1556137430),
(1,30628,1,1556137430),
(1,30660,1,1556137430),
(1,30916,1,1556137430),
(1,30922,1,1556137430),
(1,30927,1,1556137430),
(1,30928,1,1556137430),
(1,30934,1,1556137430),
(1,30935,1,1556137430),
(1,30944,1,1556137430),
(1,30945,1,1556137430),
(2,28071,1,1556138203),
(2,28431,1,1556138203),
(2,28451,1,1556138203),
(2,28472,1,1556138203),
(2,30128,1,1556138203),
(2,30129,1,1556138203),
(2,30391,1,1556138203),
(2,30394,1,1556138203),
(2,30399,1,1556138203),
(2,30400,1,1556138203),
(2,30406,1,1556138203),
(2,30407,1,1556138203),
(2,30436,1,1556138203),
(2,30437,1,1556138203),
(2,30438,1,1556138203),
(2,30439,1,1556138203),
(2,30509,1,1556138203),
(2,30510,1,1556138203),
(2,30511,1,1556138203),
(2,30514,1,1556138203),
(2,30515,1,1556138203),
(2,30516,1,1556138203),
(2,30517,1,1556138203),
(2,30533,1,1556138203),
(2,30534,1,1556138203),
(2,30628,1,1556138203),
(2,30660,1,1556138203),
(2,30916,1,1556138203),
(2,30922,1,1556138203),
(2,30927,1,1556138203),
(2,30928,1,1556138203),
(2,30934,1,1556138203),
(2,30935,1,1556138203),
(2,30944,1,1556138203),
(2,30945,1,1556138203);

/*Table structure for table `character_queststatus_rewarded` */

DROP TABLE IF EXISTS `character_queststatus_rewarded`;

CREATE TABLE `character_queststatus_rewarded` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  `active` tinyint(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_rewarded` */

insert  into `character_queststatus_rewarded`(`guid`,`quest`,`active`) values 
(2,49788,1);

/*Table structure for table `character_queststatus_seasonal` */

DROP TABLE IF EXISTS `character_queststatus_seasonal`;

CREATE TABLE `character_queststatus_seasonal` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  `event` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Event Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_seasonal` */

/*Table structure for table `character_queststatus_weekly` */

DROP TABLE IF EXISTS `character_queststatus_weekly`;

CREATE TABLE `character_queststatus_weekly` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_weekly` */

/*Table structure for table `character_recovery` */

DROP TABLE IF EXISTS `character_recovery`;

CREATE TABLE `character_recovery` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `delivered` tinyint(1) DEFAULT '0',
  `account` int(11) unsigned NOT NULL,
  `race` int(11) unsigned NOT NULL,
  `class` int(11) unsigned NOT NULL,
  `level` int(11) unsigned NOT NULL,
  `skill1` int(11) NOT NULL DEFAULT '0',
  `skill1_value` int(11) NOT NULL DEFAULT '0',
  `skill2` int(11) NOT NULL DEFAULT '0',
  `skill2_value` int(11) NOT NULL DEFAULT '0',
  `items` text NOT NULL,
  `spells` text NOT NULL,
  `at_login` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_recovery` */

/*Table structure for table `character_reputation` */

DROP TABLE IF EXISTS `character_reputation`;

CREATE TABLE `character_reputation` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `faction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `standing` int(11) NOT NULL DEFAULT '0',
  `flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`faction`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_reputation` */

insert  into `character_reputation`(`guid`,`faction`,`standing`,`flags`) values 
(1,21,0,64),
(1,46,0,4),
(1,47,0,6),
(1,54,0,6),
(1,59,0,16),
(1,67,0,25),
(1,68,0,17),
(1,69,0,6),
(1,70,0,2),
(1,72,0,6),
(1,76,0,17),
(1,81,0,17),
(1,83,0,4),
(1,86,0,4),
(1,87,0,2),
(1,92,0,2),
(1,93,0,2),
(1,169,0,12),
(1,270,0,16),
(1,289,0,4),
(1,349,0,0),
(1,369,0,64),
(1,469,0,14),
(1,470,0,64),
(1,509,0,2),
(1,510,0,16),
(1,529,0,0),
(1,530,0,17),
(1,549,0,4),
(1,550,0,4),
(1,551,0,4),
(1,569,0,4),
(1,570,0,4),
(1,571,0,4),
(1,574,0,4),
(1,576,0,0),
(1,577,0,64),
(1,589,0,6),
(1,609,0,16),
(1,729,0,16),
(1,730,0,6),
(1,749,0,0),
(1,809,0,16),
(1,889,0,16),
(1,890,0,6),
(1,891,0,14),
(1,892,0,24),
(1,909,0,16),
(1,910,0,0),
(1,911,0,17),
(1,922,0,16),
(1,930,0,6),
(1,932,0,80),
(1,933,0,16),
(1,934,0,80),
(1,935,0,16),
(1,936,0,28),
(1,941,0,16),
(1,942,0,16),
(1,946,0,0),
(1,947,0,16),
(1,948,0,8),
(1,949,0,24),
(1,952,0,0),
(1,953,0,4),
(1,967,0,16),
(1,970,0,0),
(1,978,0,0),
(1,980,0,24),
(1,989,0,16),
(1,990,0,16),
(1,1005,0,20),
(1,1011,0,16),
(1,1012,0,16),
(1,1015,0,2),
(1,1031,0,16),
(1,1037,0,6),
(1,1038,0,16),
(1,1050,0,6),
(1,1052,0,152),
(1,1064,0,16),
(1,1067,0,16),
(1,1068,0,6),
(1,1073,0,16),
(1,1077,0,16),
(1,1085,0,16),
(1,1090,0,16),
(1,1091,0,16),
(1,1094,0,6),
(1,1097,0,12),
(1,1098,0,16),
(1,1104,0,16),
(1,1105,0,16),
(1,1106,0,16),
(1,1117,0,12),
(1,1118,0,12),
(1,1119,0,0),
(1,1124,0,16),
(1,1126,0,0),
(1,1133,0,17),
(1,1134,0,6),
(1,1135,0,16),
(1,1136,0,4),
(1,1137,0,4),
(1,1154,0,4),
(1,1155,0,4),
(1,1156,0,16),
(1,1158,0,16),
(1,1162,0,8),
(1,1163,0,0),
(1,1168,0,16),
(1,1169,0,28),
(1,1171,0,64),
(1,1172,0,16),
(1,1173,0,16),
(1,1174,0,4),
(1,1177,0,6),
(1,1178,0,16),
(1,1204,0,16),
(1,1216,0,0),
(1,1228,0,2),
(1,1242,0,2),
(1,1245,0,8),
(1,1269,0,16),
(1,1270,0,16),
(1,1271,0,16),
(1,1272,0,152),
(1,1273,0,16),
(1,1275,0,16),
(1,1276,0,16),
(1,1277,0,16),
(1,1278,0,16),
(1,1279,0,16),
(1,1280,0,16),
(1,1281,0,16),
(1,1282,0,16),
(1,1283,0,16),
(1,1302,0,152),
(1,1337,0,16),
(1,1341,0,16),
(1,1345,0,16),
(1,1351,0,0),
(1,1352,0,17),
(1,1353,0,6),
(1,1357,0,4),
(1,1358,0,16),
(1,1359,0,16),
(1,1374,0,16),
(1,1375,0,144),
(1,1376,0,2),
(1,1387,0,2),
(1,1388,0,144),
(1,1416,0,0),
(1,1419,0,0),
(1,1433,0,20),
(1,1435,0,16),
(1,1440,0,16),
(1,1444,0,24),
(1,1445,0,16),
(1,1492,0,16),
(1,1515,0,16),
(1,1520,0,0),
(1,1679,0,0),
(1,1681,0,16),
(1,1682,0,18),
(1,1690,0,16),
(1,1691,0,0),
(1,1708,0,16),
(1,1710,0,2),
(1,1711,0,16),
(1,1712,0,4),
(1,1713,0,4),
(1,1714,0,4),
(1,1715,0,4),
(1,1716,0,4),
(1,1717,0,4),
(1,1718,0,4),
(1,1731,0,2),
(1,1732,0,4),
(1,1733,0,0),
(1,1735,0,0),
(1,1736,0,16),
(1,1737,0,16),
(1,1738,0,0),
(1,1739,0,16),
(1,1740,0,16),
(1,1741,0,16),
(1,1815,0,4),
(1,1828,0,16),
(1,1834,0,24),
(1,1847,0,2),
(1,1848,0,16),
(1,1849,0,16),
(1,1850,0,16),
(1,1859,0,16),
(1,1860,0,20),
(1,1861,0,20),
(1,1862,0,20),
(1,1883,0,16),
(1,1888,0,6),
(1,1894,0,16),
(1,1899,0,16),
(1,1900,0,16),
(1,1919,0,20),
(1,1947,0,20),
(1,1948,0,16),
(1,1975,0,16),
(1,1984,0,0),
(1,1989,0,4),
(1,2010,0,16),
(1,2011,0,0),
(1,2018,0,16),
(1,2045,0,16),
(1,2063,0,0),
(1,2085,0,16),
(1,2086,0,16),
(1,2087,0,16),
(1,2088,0,16),
(1,2089,0,16),
(1,2090,0,16),
(1,2091,0,16),
(1,2097,0,16),
(1,2098,0,16),
(1,2099,0,16),
(1,2100,0,16),
(1,2101,0,16),
(1,2102,0,16),
(1,2103,0,16),
(1,2104,0,0),
(1,2111,0,2),
(1,2120,0,6),
(1,2135,0,16),
(1,2156,0,16),
(1,2157,0,16),
(1,2158,0,16),
(1,2159,0,2),
(1,2160,0,2),
(1,2161,0,2),
(1,2162,0,2),
(1,2163,0,16),
(1,2164,0,16),
(1,2165,0,16),
(1,2166,0,0),
(1,2167,0,16),
(1,2170,0,16),
(1,2180,0,0),
(1,2233,0,4),
(1,2264,0,6),
(1,2265,0,6),
(2,21,0,64),
(2,46,0,4),
(2,47,0,17),
(2,54,0,17),
(2,59,0,16),
(2,67,0,14),
(2,68,0,6),
(2,69,0,17),
(2,70,0,2),
(2,72,0,17),
(2,76,0,6),
(2,81,0,6),
(2,83,0,4),
(2,86,0,4),
(2,87,0,2),
(2,92,0,2),
(2,93,0,2),
(2,169,0,12),
(2,270,0,16),
(2,289,0,4),
(2,349,0,0),
(2,369,0,64),
(2,469,0,25),
(2,470,0,64),
(2,509,0,16),
(2,510,0,2),
(2,529,0,0),
(2,530,0,6),
(2,549,0,4),
(2,550,0,4),
(2,551,0,4),
(2,569,0,4),
(2,570,0,4),
(2,571,0,4),
(2,574,0,4),
(2,576,0,0),
(2,577,0,64),
(2,589,0,0),
(2,609,0,16),
(2,729,0,6),
(2,730,0,16),
(2,749,0,0),
(2,809,0,16),
(2,889,0,6),
(2,890,0,16),
(2,891,0,24),
(2,892,0,14),
(2,909,0,16),
(2,910,0,2),
(2,911,0,6),
(2,922,0,6),
(2,930,0,17),
(2,932,0,80),
(2,933,0,16),
(2,934,0,80),
(2,935,0,16),
(2,936,0,28),
(2,941,0,6),
(2,942,0,16),
(2,946,0,16),
(2,947,0,2),
(2,948,0,0),
(2,949,0,24),
(2,952,0,0),
(2,953,0,4),
(2,967,0,16),
(2,970,0,0),
(2,978,0,16),
(2,980,0,24),
(2,989,0,16),
(2,990,0,16),
(2,1005,0,20),
(2,1011,0,16),
(2,1012,0,16),
(2,1015,0,2),
(2,1031,0,16),
(2,1037,0,136),
(2,1038,0,16),
(2,1050,0,16),
(2,1052,0,2),
(2,1064,0,6),
(2,1067,0,2),
(2,1068,0,16),
(2,1073,0,16),
(2,1077,0,16),
(2,1085,0,6),
(2,1090,0,16),
(2,1091,0,16),
(2,1094,0,16),
(2,1097,0,12),
(2,1098,0,16),
(2,1104,0,16),
(2,1105,0,16),
(2,1106,0,16),
(2,1117,0,12),
(2,1118,0,12),
(2,1119,0,2),
(2,1124,0,6),
(2,1126,0,16),
(2,1133,0,6),
(2,1134,0,17),
(2,1135,0,16),
(2,1136,0,4),
(2,1137,0,4),
(2,1154,0,4),
(2,1155,0,4),
(2,1156,0,16),
(2,1158,0,16),
(2,1162,0,8),
(2,1163,0,0),
(2,1168,0,16),
(2,1169,0,28),
(2,1171,0,66),
(2,1172,0,2),
(2,1173,0,16),
(2,1174,0,16),
(2,1177,0,0),
(2,1178,0,6),
(2,1204,0,16),
(2,1216,0,0),
(2,1228,0,2),
(2,1242,0,16),
(2,1245,0,8),
(2,1269,0,16),
(2,1270,0,16),
(2,1271,0,16),
(2,1272,0,152),
(2,1273,0,16),
(2,1275,0,16),
(2,1276,0,16),
(2,1277,0,16),
(2,1278,0,16),
(2,1279,0,16),
(2,1280,0,16),
(2,1281,0,16),
(2,1282,0,16),
(2,1283,0,16),
(2,1302,0,152),
(2,1337,0,16),
(2,1341,0,16),
(2,1345,0,16),
(2,1351,0,0),
(2,1352,0,6),
(2,1353,0,17),
(2,1357,0,4),
(2,1358,0,16),
(2,1359,0,16),
(2,1374,0,0),
(2,1375,0,2),
(2,1376,0,144),
(2,1387,0,144),
(2,1388,0,2),
(2,1416,0,0),
(2,1419,0,16),
(2,1433,0,20),
(2,1435,0,16),
(2,1440,0,16),
(2,1444,0,24),
(2,1445,0,2),
(2,1492,0,16),
(2,1515,0,16),
(2,1520,0,0),
(2,1679,0,0),
(2,1681,0,18),
(2,1682,0,16),
(2,1690,0,0),
(2,1691,0,16),
(2,1708,0,2),
(2,1710,0,16),
(2,1711,0,16),
(2,1712,0,4),
(2,1713,0,4),
(2,1714,0,4),
(2,1715,0,4),
(2,1716,0,4),
(2,1717,0,4),
(2,1718,0,4),
(2,1731,0,16),
(2,1732,0,4),
(2,1733,0,16),
(2,1735,0,0),
(2,1736,0,16),
(2,1737,0,16),
(2,1738,0,16),
(2,1739,0,0),
(2,1740,0,0),
(2,1741,0,16),
(2,1815,0,4),
(2,1828,0,16),
(2,1834,0,24),
(2,1847,0,16),
(2,1848,0,2),
(2,1849,0,16),
(2,1850,0,16),
(2,1859,0,16),
(2,1860,0,20),
(2,1861,0,20),
(2,1862,0,20),
(2,1883,0,16),
(2,1888,0,6),
(2,1894,0,16),
(2,1899,0,16),
(2,1900,0,16),
(2,1919,0,20),
(2,1947,0,20),
(2,1948,0,16),
(2,1975,0,16),
(2,1984,0,0),
(2,1989,0,4),
(2,2010,0,0),
(2,2011,0,16),
(2,2018,0,16),
(2,2045,0,16),
(2,2063,0,0),
(2,2085,0,16),
(2,2086,0,0),
(2,2087,0,16),
(2,2088,0,16),
(2,2089,0,16),
(2,2090,0,16),
(2,2091,0,16),
(2,2097,0,16),
(2,2098,0,16),
(2,2099,0,16),
(2,2100,0,16),
(2,2101,0,16),
(2,2102,0,16),
(2,2103,0,2),
(2,2104,0,0),
(2,2111,0,0),
(2,2120,0,20),
(2,2135,0,16),
(2,2156,0,2),
(2,2157,0,2),
(2,2158,0,20),
(2,2159,0,16),
(2,2160,0,16),
(2,2161,0,16),
(2,2162,0,16),
(2,2163,0,16),
(2,2164,0,16),
(2,2165,0,16),
(2,2166,0,0),
(2,2167,0,16),
(2,2170,0,17),
(2,2180,0,0),
(2,2233,0,4),
(2,2264,0,20),
(2,2265,0,20);

/*Table structure for table `character_shop` */

DROP TABLE IF EXISTS `character_shop`;

CREATE TABLE `character_shop` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` bigint(20) NOT NULL,
  `type` tinyint(3) NOT NULL,
  `itemId` int(10) NOT NULL DEFAULT '0',
  `itemCount` int(10) NOT NULL DEFAULT '0',
  `delivered` tinyint(3) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_shop` */

/*Table structure for table `character_skills` */

DROP TABLE IF EXISTS `character_skills`;

CREATE TABLE `character_skills` (
  `guid` bigint(20) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `skill` smallint(5) unsigned NOT NULL,
  `value` smallint(5) unsigned NOT NULL,
  `max` smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`skill`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_skills` */

insert  into `character_skills`(`guid`,`skill`,`value`,`max`) values 
(1,43,1,5),
(1,95,1,5),
(1,109,300,300),
(1,136,1,5),
(1,137,300,300),
(1,162,1,5),
(1,173,1,5),
(1,183,5,5),
(1,228,5,5),
(1,415,1,1),
(1,756,5,5),
(1,777,5,5),
(1,810,5,5),
(1,904,5,5),
(1,934,5,5),
(2,43,1,100),
(2,44,1,100),
(2,45,1,100),
(2,46,1,100),
(2,54,1,100),
(2,95,1,100),
(2,98,300,300),
(2,113,300,300),
(2,118,100,100),
(2,137,300,300),
(2,162,1,100),
(2,173,1,100),
(2,183,100,100),
(2,226,1,100),
(2,414,1,1),
(2,415,1,1),
(2,473,1,100),
(2,762,75,75),
(2,777,100,100),
(2,810,100,100),
(2,921,100,100),
(2,934,100,100),
(2,2423,100,100);

/*Table structure for table `character_social` */

DROP TABLE IF EXISTS `character_social`;

CREATE TABLE `character_social` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier',
  `friend` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Friend Global Unique Identifier',
  `flags` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Friend Flags',
  `note` varchar(48) NOT NULL DEFAULT '' COMMENT 'Friend Note',
  PRIMARY KEY (`guid`,`friend`,`flags`),
  KEY `friend` (`friend`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_social` */

/*Table structure for table `character_spell` */

DROP TABLE IF EXISTS `character_spell`;

CREATE TABLE `character_spell` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier',
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `disabled` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_spell` */

insert  into `character_spell`(`guid`,`spell`,`active`,`disabled`) values 
(1,116,1,0),
(1,137020,1,0),
(1,162699,1,0),
(2,703,1,0),
(2,921,1,0),
(2,1752,1,0),
(2,1784,1,0),
(2,1833,1,0),
(2,1943,1,0),
(2,2823,1,0),
(2,6770,1,0),
(2,14117,1,0),
(2,51667,1,0),
(2,137037,1,0),
(2,162697,1,0),
(2,185565,1,0),
(2,196819,1,0),
(2,279877,1,0);

/*Table structure for table `character_spell_charges` */

DROP TABLE IF EXISTS `character_spell_charges`;

CREATE TABLE `character_spell_charges` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCategory.dbc Identifier',
  `rechargeStart` int(10) unsigned NOT NULL DEFAULT '0',
  `rechargeEnd` int(10) unsigned NOT NULL DEFAULT '0',
  KEY `idx_guid` (`guid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_spell_charges` */

/*Table structure for table `character_spell_cooldown` */

DROP TABLE IF EXISTS `character_spell_cooldown`;

CREATE TABLE `character_spell_cooldown` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier',
  `item` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Item Identifier',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell category Id',
  `categoryEnd` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_spell_cooldown` */

/*Table structure for table `character_stats` */

DROP TABLE IF EXISTS `character_stats`;

CREATE TABLE `character_stats` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `maxhealth` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower1` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower2` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower3` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower4` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower5` int(10) unsigned NOT NULL DEFAULT '0',
  `maxpower6` int(10) unsigned NOT NULL DEFAULT '0',
  `strength` int(10) unsigned NOT NULL DEFAULT '0',
  `agility` int(10) unsigned NOT NULL DEFAULT '0',
  `stamina` int(10) unsigned NOT NULL DEFAULT '0',
  `intellect` int(10) unsigned NOT NULL DEFAULT '0',
  `armor` int(10) unsigned NOT NULL DEFAULT '0',
  `resHoly` int(10) unsigned NOT NULL DEFAULT '0',
  `resFire` int(10) unsigned NOT NULL DEFAULT '0',
  `resNature` int(10) unsigned NOT NULL DEFAULT '0',
  `resFrost` int(10) unsigned NOT NULL DEFAULT '0',
  `resShadow` int(10) unsigned NOT NULL DEFAULT '0',
  `resArcane` int(10) unsigned NOT NULL DEFAULT '0',
  `blockPct` float unsigned NOT NULL DEFAULT '0',
  `dodgePct` float unsigned NOT NULL DEFAULT '0',
  `parryPct` float unsigned NOT NULL DEFAULT '0',
  `critPct` float unsigned NOT NULL DEFAULT '0',
  `rangedCritPct` float unsigned NOT NULL DEFAULT '0',
  `spellCritPct` float unsigned NOT NULL DEFAULT '0',
  `attackPower` int(10) unsigned NOT NULL DEFAULT '0',
  `rangedAttackPower` int(10) unsigned NOT NULL DEFAULT '0',
  `spellPower` int(10) unsigned NOT NULL DEFAULT '0',
  `resilience` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_stats` */

/*Table structure for table `character_talent` */

DROP TABLE IF EXISTS `character_talent`;

CREATE TABLE `character_talent` (
  `guid` bigint(20) unsigned NOT NULL,
  `talentId` mediumint(8) unsigned NOT NULL,
  `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`talentId`,`talentGroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_talent` */

/*Table structure for table `character_transmog_outfits` */

DROP TABLE IF EXISTS `character_transmog_outfits`;

CREATE TABLE `character_transmog_outfits` (
  `guid` bigint(20) NOT NULL DEFAULT '0',
  `setguid` bigint(20) NOT NULL AUTO_INCREMENT,
  `setindex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `name` varchar(128) NOT NULL,
  `iconname` varchar(256) NOT NULL,
  `ignore_mask` int(11) NOT NULL DEFAULT '0',
  `appearance0` int(10) NOT NULL DEFAULT '0',
  `appearance1` int(10) NOT NULL DEFAULT '0',
  `appearance2` int(10) NOT NULL DEFAULT '0',
  `appearance3` int(10) NOT NULL DEFAULT '0',
  `appearance4` int(10) NOT NULL DEFAULT '0',
  `appearance5` int(10) NOT NULL DEFAULT '0',
  `appearance6` int(10) NOT NULL DEFAULT '0',
  `appearance7` int(10) NOT NULL DEFAULT '0',
  `appearance8` int(10) NOT NULL DEFAULT '0',
  `appearance9` int(10) NOT NULL DEFAULT '0',
  `appearance10` int(10) NOT NULL DEFAULT '0',
  `appearance11` int(10) NOT NULL DEFAULT '0',
  `appearance12` int(10) NOT NULL DEFAULT '0',
  `appearance13` int(10) NOT NULL DEFAULT '0',
  `appearance14` int(10) NOT NULL DEFAULT '0',
  `appearance15` int(10) NOT NULL DEFAULT '0',
  `appearance16` int(10) NOT NULL DEFAULT '0',
  `appearance17` int(10) NOT NULL DEFAULT '0',
  `appearance18` int(10) NOT NULL DEFAULT '0',
  `mainHandEnchant` int(10) NOT NULL DEFAULT '0',
  `offHandEnchant` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`setguid`),
  UNIQUE KEY `idx_set` (`guid`,`setguid`,`setindex`),
  KEY `Idx_setindex` (`setindex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_transmog_outfits` */

/*Table structure for table `character_void_storage` */

DROP TABLE IF EXISTS `character_void_storage`;

CREATE TABLE `character_void_storage` (
  `itemId` bigint(20) unsigned NOT NULL,
  `playerGuid` bigint(20) unsigned NOT NULL,
  `itemEntry` mediumint(8) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `creatorGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `randomPropertyType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `randomProperty` int(10) unsigned NOT NULL DEFAULT '0',
  `suffixFactor` int(10) unsigned NOT NULL DEFAULT '0',
  `upgradeId` int(10) unsigned NOT NULL DEFAULT '0',
  `fixedScalingLevel` int(10) unsigned DEFAULT '0',
  `artifactKnowledgeLevel` int(10) unsigned DEFAULT '0',
  `challengeId` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix1` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix2` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix3` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeIsCharged` int(10) unsigned NOT NULL DEFAULT '0',
  `context` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `bonusListIDs` text,
  PRIMARY KEY (`itemId`),
  UNIQUE KEY `idx_player_slot` (`playerGuid`,`slot`),
  KEY `idx_player` (`playerGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_void_storage` */

/*Table structure for table `character_world_quest` */

DROP TABLE IF EXISTS `character_world_quest`;

CREATE TABLE `character_world_quest` (
  `guid` bigint(20) unsigned NOT NULL,
  `questId` int(10) unsigned NOT NULL,
  `lastupdate` int(10) unsigned NOT NULL,
  `timer` int(10) unsigned NOT NULL,
  `variableID` int(10) unsigned NOT NULL,
  `value` int(10) NOT NULL,
  PRIMARY KEY (`guid`,`questId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_world_quest` */

/*Table structure for table `characters` */

DROP TABLE IF EXISTS `characters`;

CREATE TABLE `characters` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `account` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account Identifier',
  `name` varchar(12) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `class` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gender` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `xp` int(10) unsigned NOT NULL DEFAULT '0',
  `money` bigint(20) unsigned NOT NULL DEFAULT '0',
  `skin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `face` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `hairStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `hairColor` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `facialStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `customDisplay1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `customDisplay2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `customDisplay3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `inventorySlots` tinyint(3) unsigned NOT NULL DEFAULT '16',
  `bankSlots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `restState` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `playerFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `playerFlagsEx` int(10) unsigned NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `map` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `instance_id` int(10) unsigned NOT NULL DEFAULT '0',
  `dungeonDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `raidDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '14',
  `legacyRaidDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '3',
  `orientation` float NOT NULL DEFAULT '0',
  `taximask` text NOT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `cinematic` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `totaltime` int(10) unsigned NOT NULL DEFAULT '0',
  `leveltime` int(10) unsigned NOT NULL DEFAULT '0',
  `logout_time` int(10) unsigned NOT NULL DEFAULT '0',
  `is_logout_resting` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `rest_bonus` float NOT NULL DEFAULT '0',
  `resettalents_cost` int(10) unsigned NOT NULL DEFAULT '0',
  `resettalents_time` int(10) unsigned NOT NULL DEFAULT '0',
  `primarySpecialization` int(10) unsigned NOT NULL DEFAULT '0',
  `trans_x` float NOT NULL DEFAULT '0',
  `trans_y` float NOT NULL DEFAULT '0',
  `trans_z` float NOT NULL DEFAULT '0',
  `trans_o` float NOT NULL DEFAULT '0',
  `transguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `extra_flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `stable_slots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `at_login` smallint(5) unsigned NOT NULL DEFAULT '0',
  `zone` smallint(5) unsigned NOT NULL DEFAULT '0',
  `death_expire_time` int(10) unsigned NOT NULL DEFAULT '0',
  `taxi_path` text,
  `totalKills` int(10) unsigned NOT NULL DEFAULT '0',
  `todayKills` smallint(5) unsigned NOT NULL DEFAULT '0',
  `yesterdayKills` smallint(5) unsigned NOT NULL DEFAULT '0',
  `chosenTitle` int(10) unsigned NOT NULL DEFAULT '0',
  `watchedFaction` int(10) unsigned NOT NULL DEFAULT '0',
  `drunk` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `health` int(10) unsigned NOT NULL DEFAULT '0',
  `power1` int(10) unsigned NOT NULL DEFAULT '0',
  `power2` int(10) unsigned NOT NULL DEFAULT '0',
  `power3` int(10) unsigned NOT NULL DEFAULT '0',
  `power4` int(10) unsigned NOT NULL DEFAULT '0',
  `power5` int(10) unsigned NOT NULL DEFAULT '0',
  `power6` int(10) unsigned NOT NULL DEFAULT '0',
  `latency` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `activeTalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lootSpecId` int(10) unsigned NOT NULL DEFAULT '0',
  `exploredZones` longtext,
  `equipmentCache` longtext,
  `knownTitles` longtext,
  `actionBars` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `grantableLevels` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `xpRate` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `deleteInfos_Account` int(10) unsigned DEFAULT NULL,
  `deleteInfos_Name` varchar(12) DEFAULT NULL,
  `deleteDate` int(10) unsigned DEFAULT NULL,
  `honor` int(10) unsigned NOT NULL DEFAULT '0',
  `honorLevel` int(10) unsigned NOT NULL DEFAULT '1',
  `honorRestState` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `honorRestBonus` float NOT NULL DEFAULT '0',
  `lastLoginBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`),
  KEY `idx_account` (`account`),
  KEY `idx_online` (`online`),
  KEY `idx_name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `characters` */

insert  into `characters`(`guid`,`account`,`name`,`slot`,`race`,`class`,`gender`,`level`,`xp`,`money`,`skin`,`face`,`hairStyle`,`hairColor`,`facialStyle`,`customDisplay1`,`customDisplay2`,`customDisplay3`,`inventorySlots`,`bankSlots`,`restState`,`playerFlags`,`playerFlagsEx`,`position_x`,`position_y`,`position_z`,`map`,`instance_id`,`dungeonDifficulty`,`raidDifficulty`,`legacyRaidDifficulty`,`orientation`,`taximask`,`online`,`cinematic`,`totaltime`,`leveltime`,`logout_time`,`is_logout_resting`,`rest_bonus`,`resettalents_cost`,`resettalents_time`,`primarySpecialization`,`trans_x`,`trans_y`,`trans_z`,`trans_o`,`transguid`,`extra_flags`,`stable_slots`,`at_login`,`zone`,`death_expire_time`,`taxi_path`,`totalKills`,`todayKills`,`yesterdayKills`,`chosenTitle`,`watchedFaction`,`drunk`,`health`,`power1`,`power2`,`power3`,`power4`,`power5`,`power6`,`latency`,`activeTalentGroup`,`lootSpecId`,`exploredZones`,`equipmentCache`,`knownTitles`,`actionBars`,`grantableLevels`,`xpRate`,`deleteInfos_Account`,`deleteInfos_Name`,`deleteDate`,`honor`,`honorLevel`,`honorRestState`,`honorRestBonus`,`lastLoginBuild`) values 
(1,1,'Derta',0,10,8,1,1,150,0,2,8,12,4,4,0,0,0,16,0,2,0,0,10341.3,-6358.46,32.9827,530,0,1,14,3,0.899751,'0 4 96 0 0 0 0 0 16 0 2 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 2 0 0 0 0 0 0 8 0 0 0 0 0 0 0 0 128 1 0 0 0 0 0 0 0 0 0 0 65 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,1,744,744,1556138173,0,0.00757778,0,0,64,0,0,0,0,0,0,0,0,6455,0,'',0,0,0,0,4294967295,0,88,145,0,0,0,0,0,6,2,0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 16384 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ','0 0 0 0 0 0 0 0 0 0 0 0 20 33258 0 0 0 0 7 14309 0 8 17513 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 17 33299 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ','0 0 0 0 0 0 0 0 1 0 0 0 ',0,0,0,NULL,NULL,NULL,0,1,2,0,28153),
(2,1,'Verta',0,29,4,1,20,400,125,2,6,9,3,3,0,0,0,16,0,1,32,0,-8194.47,779.886,72.4326,0,0,1,14,3,0.210577,'34 0 0 6 0 0 1 0 0 0 0 32 8 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 128 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 32 16 0 0 0 140 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,1,206,206,1556140559,1,163.786,0,0,259,0,0,0,0,0,0,0,0,1519,0,'',0,0,0,0,4294967295,0,855,120,0,0,0,0,0,5,0,0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 16384 0 0 0 0 0 0 2147483648 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ','0 0 0 0 0 0 0 0 0 0 0 0 5 117208 0 6 117206 0 7 117205 0 8 117210 0 9 138289 0 10 117209 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 13 120710 0 13 120710 0 0 0 0 0 0 0 18 0 0 18 0 0 18 0 0 18 0 0 ','0 0 0 0 0 0 0 0 1 0 0 0 ',0,0,0,NULL,NULL,NULL,0,1,2,0,28153);

/*Table structure for table `corpse` */

DROP TABLE IF EXISTS `corpse`;

CREATE TABLE `corpse` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `displayId` int(10) unsigned NOT NULL DEFAULT '0',
  `itemCache` text NOT NULL,
  `bytes1` int(10) unsigned NOT NULL DEFAULT '0',
  `bytes2` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `dynFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `corpseType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `instanceId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Instance Identifier',
  PRIMARY KEY (`guid`),
  KEY `idx_type` (`corpseType`),
  KEY `idx_instance` (`instanceId`),
  KEY `idx_time` (`time`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Death System';

/*Data for the table `corpse` */

/*Table structure for table `corpse_phases` */

DROP TABLE IF EXISTS `corpse_phases`;

CREATE TABLE `corpse_phases` (
  `OwnerGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `PhaseId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`OwnerGuid`,`PhaseId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `corpse_phases` */

/*Table structure for table `creature_respawn` */

DROP TABLE IF EXISTS `creature_respawn`;

CREATE TABLE `creature_respawn` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `respawnTime` int(10) unsigned NOT NULL DEFAULT '0',
  `mapId` smallint(10) unsigned NOT NULL DEFAULT '0',
  `instanceId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Instance Identifier',
  PRIMARY KEY (`guid`,`instanceId`),
  KEY `idx_instance` (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Grid Loading System';

/*Data for the table `creature_respawn` */

insert  into `creature_respawn`(`guid`,`respawnTime`,`mapId`,`instanceId`) values 
(67415,1556138339,530,0);

/*Table structure for table `game_event_condition_save` */

DROP TABLE IF EXISTS `game_event_condition_save`;

CREATE TABLE `game_event_condition_save` (
  `eventEntry` tinyint(3) unsigned NOT NULL,
  `condition_id` int(10) unsigned NOT NULL DEFAULT '0',
  `done` float DEFAULT '0',
  PRIMARY KEY (`eventEntry`,`condition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `game_event_condition_save` */

/*Table structure for table `game_event_save` */

DROP TABLE IF EXISTS `game_event_save`;

CREATE TABLE `game_event_save` (
  `eventEntry` tinyint(3) unsigned NOT NULL,
  `state` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `next_start` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`eventEntry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `game_event_save` */

/*Table structure for table `gameobject_respawn` */

DROP TABLE IF EXISTS `gameobject_respawn`;

CREATE TABLE `gameobject_respawn` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `respawnTime` int(10) unsigned NOT NULL DEFAULT '0',
  `mapId` smallint(10) unsigned NOT NULL DEFAULT '0',
  `instanceId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Instance Identifier',
  PRIMARY KEY (`guid`,`instanceId`),
  KEY `idx_instance` (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Grid Loading System';

/*Data for the table `gameobject_respawn` */

/*Table structure for table `gm_bug` */

DROP TABLE IF EXISTS `gm_bug`;

CREATE TABLE `gm_bug` (
  `id` int(10) unsigned NOT NULL,
  `playerGuid` bigint(20) unsigned NOT NULL,
  `note` text NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT '0',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  `facing` float NOT NULL DEFAULT '0',
  `closedBy` bigint(20) NOT NULL DEFAULT '0',
  `assignedTo` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
  `comment` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `gm_bug` */

/*Table structure for table `gm_complaint` */

DROP TABLE IF EXISTS `gm_complaint`;

CREATE TABLE `gm_complaint` (
  `id` int(10) unsigned NOT NULL,
  `playerGuid` bigint(20) unsigned NOT NULL,
  `note` text NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT '0',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  `facing` float NOT NULL DEFAULT '0',
  `targetCharacterGuid` bigint(20) unsigned NOT NULL,
  `complaintType` smallint(5) unsigned NOT NULL,
  `reportLineIndex` int(10) NOT NULL,
  `closedBy` bigint(20) NOT NULL DEFAULT '0',
  `assignedTo` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
  `comment` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `gm_complaint` */

/*Table structure for table `gm_complaint_chatlog` */

DROP TABLE IF EXISTS `gm_complaint_chatlog`;

CREATE TABLE `gm_complaint_chatlog` (
  `complaintId` int(10) unsigned NOT NULL,
  `lineId` int(10) unsigned NOT NULL,
  `timestamp` int(10) unsigned NOT NULL,
  `text` text NOT NULL,
  PRIMARY KEY (`complaintId`,`lineId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `gm_complaint_chatlog` */

/*Table structure for table `gm_suggestion` */

DROP TABLE IF EXISTS `gm_suggestion`;

CREATE TABLE `gm_suggestion` (
  `id` int(10) unsigned NOT NULL,
  `playerGuid` bigint(20) unsigned NOT NULL,
  `note` text NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT '0',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  `facing` float NOT NULL DEFAULT '0',
  `closedBy` bigint(20) NOT NULL DEFAULT '0',
  `assignedTo` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
  `comment` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `gm_suggestion` */

/*Table structure for table `group_instance` */

DROP TABLE IF EXISTS `group_instance`;

CREATE TABLE `group_instance` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `instance` int(10) unsigned NOT NULL DEFAULT '0',
  `permanent` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `group_instance` */

/*Table structure for table `group_member` */

DROP TABLE IF EXISTS `group_member`;

CREATE TABLE `group_member` (
  `guid` int(10) unsigned NOT NULL,
  `memberGuid` bigint(20) unsigned NOT NULL,
  `memberFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `subgroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `roles` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`memberGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Groups';

/*Data for the table `group_member` */

/*Table structure for table `groups` */

DROP TABLE IF EXISTS `groups`;

CREATE TABLE `groups` (
  `guid` int(10) unsigned NOT NULL,
  `leaderGuid` bigint(20) unsigned NOT NULL,
  `lootMethod` tinyint(3) unsigned NOT NULL,
  `looterGuid` bigint(20) unsigned NOT NULL,
  `lootThreshold` tinyint(3) unsigned NOT NULL,
  `icon1` binary(16) NOT NULL,
  `icon2` binary(16) NOT NULL,
  `icon3` binary(16) NOT NULL,
  `icon4` binary(16) NOT NULL,
  `icon5` binary(16) NOT NULL,
  `icon6` binary(16) NOT NULL,
  `icon7` binary(16) NOT NULL,
  `icon8` binary(16) NOT NULL,
  `groupType` tinyint(3) unsigned NOT NULL,
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `raidDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '14',
  `legacyRaidDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '3',
  `masterLooterGuid` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`guid`),
  KEY `leaderGuid` (`leaderGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Groups';

/*Data for the table `groups` */

/*Table structure for table `guild` */

DROP TABLE IF EXISTS `guild`;

CREATE TABLE `guild` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `name` varchar(24) NOT NULL DEFAULT '',
  `leaderguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `EmblemStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EmblemColor` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BorderStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BorderColor` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BackgroundColor` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `info` varchar(500) NOT NULL DEFAULT '',
  `motd` varchar(128) NOT NULL DEFAULT '',
  `createdate` int(10) unsigned NOT NULL DEFAULT '0',
  `BankMoney` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild` */

/*Table structure for table `guild_achievement` */

DROP TABLE IF EXISTS `guild_achievement`;

CREATE TABLE `guild_achievement` (
  `guildId` bigint(20) unsigned NOT NULL,
  `achievement` int(10) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  `guids` text NOT NULL,
  PRIMARY KEY (`guildId`,`achievement`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_achievement` */

/*Table structure for table `guild_achievement_progress` */

DROP TABLE IF EXISTS `guild_achievement_progress`;

CREATE TABLE `guild_achievement_progress` (
  `guildId` bigint(20) unsigned NOT NULL,
  `criteria` int(10) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  `completedGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildId`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_achievement_progress` */

/*Table structure for table `guild_bank_eventlog` */

DROP TABLE IF EXISTS `guild_bank_eventlog`;

CREATE TABLE `guild_bank_eventlog` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Log record identificator - auxiliary column',
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Guild bank TabId',
  `EventType` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Event type',
  `PlayerGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ItemOrMoney` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ItemStackCount` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DestTabId` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Destination Tab Id',
  `TimeStamp` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`,`TabId`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_PlayerGuid` (`PlayerGuid`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_eventlog` */

/*Table structure for table `guild_bank_item` */

DROP TABLE IF EXISTS `guild_bank_item`;

CREATE TABLE `guild_bank_item` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SlotId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `item_guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildid`,`TabId`,`SlotId`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_item_guid` (`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_item` */

/*Table structure for table `guild_bank_right` */

DROP TABLE IF EXISTS `guild_bank_right`;

CREATE TABLE `guild_bank_right` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `rid` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gbright` tinyint(3) NOT NULL DEFAULT '0',
  `SlotPerDay` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildid`,`TabId`,`rid`),
  KEY `guildid_key` (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_right` */

/*Table structure for table `guild_bank_tab` */

DROP TABLE IF EXISTS `guild_bank_tab`;

CREATE TABLE `guild_bank_tab` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TabName` varchar(16) NOT NULL DEFAULT '',
  `TabIcon` varchar(100) NOT NULL DEFAULT '',
  `TabText` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`guildid`,`TabId`),
  KEY `guildid_key` (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_tab` */

/*Table structure for table `guild_eventlog` */

DROP TABLE IF EXISTS `guild_eventlog`;

CREATE TABLE `guild_eventlog` (
  `guildid` bigint(20) unsigned NOT NULL COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL COMMENT 'Log record identificator - auxiliary column',
  `EventType` tinyint(3) unsigned NOT NULL COMMENT 'Event type',
  `PlayerGuid1` bigint(20) unsigned NOT NULL COMMENT 'Player 1',
  `PlayerGuid2` bigint(20) unsigned NOT NULL COMMENT 'Player 2',
  `NewRank` tinyint(3) unsigned NOT NULL COMMENT 'New rank(in case promotion/demotion)',
  `TimeStamp` int(10) unsigned NOT NULL COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`),
  KEY `Idx_PlayerGuid1` (`PlayerGuid1`),
  KEY `Idx_PlayerGuid2` (`PlayerGuid2`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild Eventlog';

/*Data for the table `guild_eventlog` */

/*Table structure for table `guild_finder_applicant` */

DROP TABLE IF EXISTS `guild_finder_applicant`;

CREATE TABLE `guild_finder_applicant` (
  `guildId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `playerGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `availability` tinyint(3) unsigned DEFAULT '0',
  `classRole` tinyint(3) unsigned DEFAULT '0',
  `interests` tinyint(3) unsigned DEFAULT '0',
  `comment` varchar(255) DEFAULT NULL,
  `submitTime` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`guildId`,`playerGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_finder_applicant` */

/*Table structure for table `guild_finder_guild_settings` */

DROP TABLE IF EXISTS `guild_finder_guild_settings`;

CREATE TABLE `guild_finder_guild_settings` (
  `guildId` bigint(20) unsigned NOT NULL,
  `availability` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `classRoles` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `interests` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `level` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `listed` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`guildId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_finder_guild_settings` */

/*Table structure for table `guild_member` */

DROP TABLE IF EXISTS `guild_member`;

CREATE TABLE `guild_member` (
  `guildid` bigint(20) unsigned NOT NULL COMMENT 'Guild Identificator',
  `guid` bigint(20) unsigned NOT NULL,
  `rank` tinyint(3) unsigned NOT NULL,
  `pnote` varchar(31) NOT NULL DEFAULT '',
  `offnote` varchar(31) NOT NULL DEFAULT '',
  UNIQUE KEY `guid_key` (`guid`),
  KEY `guildid_key` (`guildid`),
  KEY `guildid_rank_key` (`guildid`,`rank`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild_member` */

/*Table structure for table `guild_member_withdraw` */

DROP TABLE IF EXISTS `guild_member_withdraw`;

CREATE TABLE `guild_member_withdraw` (
  `guid` bigint(20) unsigned NOT NULL,
  `tab0` int(10) unsigned NOT NULL DEFAULT '0',
  `tab1` int(10) unsigned NOT NULL DEFAULT '0',
  `tab2` int(10) unsigned NOT NULL DEFAULT '0',
  `tab3` int(10) unsigned NOT NULL DEFAULT '0',
  `tab4` int(10) unsigned NOT NULL DEFAULT '0',
  `tab5` int(10) unsigned NOT NULL DEFAULT '0',
  `tab6` int(10) unsigned NOT NULL DEFAULT '0',
  `tab7` int(10) unsigned NOT NULL DEFAULT '0',
  `money` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild Member Daily Withdraws';

/*Data for the table `guild_member_withdraw` */

/*Table structure for table `guild_newslog` */

DROP TABLE IF EXISTS `guild_newslog`;

CREATE TABLE `guild_newslog` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Log record identificator - auxiliary column',
  `EventType` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Event type',
  `PlayerGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeStamp` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_PlayerGuid` (`PlayerGuid`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_newslog` */

/*Table structure for table `guild_rank` */

DROP TABLE IF EXISTS `guild_rank`;

CREATE TABLE `guild_rank` (
  `guildid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `rid` tinyint(3) unsigned NOT NULL,
  `rname` varchar(20) NOT NULL DEFAULT '',
  `rights` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `BankMoneyPerDay` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guildid`,`rid`),
  KEY `Idx_rid` (`rid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild_rank` */

/*Table structure for table `instance` */

DROP TABLE IF EXISTS `instance`;

CREATE TABLE `instance` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `map` smallint(5) unsigned NOT NULL DEFAULT '0',
  `resettime` int(10) unsigned NOT NULL DEFAULT '0',
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `completedEncounters` int(10) unsigned NOT NULL DEFAULT '0',
  `data` tinytext NOT NULL,
  `entranceId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `map` (`map`),
  KEY `resettime` (`resettime`),
  KEY `difficulty` (`difficulty`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `instance` */

/*Table structure for table `instance_reset` */

DROP TABLE IF EXISTS `instance_reset`;

CREATE TABLE `instance_reset` (
  `mapid` smallint(5) unsigned NOT NULL DEFAULT '0',
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `resettime` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`mapid`,`difficulty`),
  KEY `difficulty` (`difficulty`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `instance_reset` */

insert  into `instance_reset`(`mapid`,`difficulty`,`resettime`) values 
(33,2,1556164800),
(36,2,1556164800),
(249,3,1556337600),
(249,4,1556337600),
(269,2,1556164800),
(409,9,1556337600),
(469,9,1556337600),
(509,3,1556164800),
(531,9,1556337600),
(532,3,1556337600),
(533,3,1556337600),
(533,4,1556337600),
(534,4,1556337600),
(540,2,1556164800),
(542,2,1556164800),
(543,2,1556164800),
(544,4,1556337600),
(545,2,1556164800),
(546,2,1556164800),
(547,2,1556164800),
(548,4,1556337600),
(550,4,1556337600),
(552,2,1556164800),
(553,2,1556164800),
(554,2,1556164800),
(555,2,1556164800),
(556,2,1556164800),
(557,2,1556164800),
(558,2,1556164800),
(560,2,1556164800),
(564,14,1556683200),
(564,33,1556683200),
(565,4,1556337600),
(568,2,1556164800),
(574,2,1556164800),
(575,2,1556164800),
(576,2,1556164800),
(578,2,1556164800),
(580,4,1556337600),
(585,2,1556164800),
(595,2,1556164800),
(598,2,1556164800),
(599,2,1556164800),
(600,2,1556164800),
(601,2,1556164800),
(602,2,1556164800),
(603,14,1556683200),
(603,33,1556683200),
(604,2,1556164800),
(608,2,1556164800),
(615,3,1556337600),
(615,4,1556337600),
(616,3,1556337600),
(616,4,1556337600),
(619,2,1556164800),
(624,3,1556337600),
(624,4,1556337600),
(631,3,1556337600),
(631,4,1556337600),
(631,5,1556337600),
(631,6,1556337600),
(632,2,1556164800),
(643,2,1556164800),
(644,2,1556164800),
(645,2,1556164800),
(649,3,1556337600),
(649,4,1556337600),
(649,5,1556337600),
(649,6,1556337600),
(650,2,1556164800),
(657,2,1556164800),
(658,2,1556164800),
(668,2,1556164800),
(669,3,1556337600),
(669,4,1556337600),
(669,5,1556337600),
(669,6,1556337600),
(670,2,1556164800),
(671,3,1556337600),
(671,4,1556337600),
(671,5,1556337600),
(671,6,1556337600),
(720,3,1556337600),
(720,4,1556337600),
(720,5,1556337600),
(720,6,1556337600),
(724,3,1556337600),
(724,4,1556337600),
(724,5,1556337600),
(724,6,1556337600),
(725,2,1556164800),
(754,3,1556337600),
(754,4,1556337600),
(754,5,1556337600),
(754,6,1556337600),
(755,2,1556164800),
(757,3,1556337600),
(757,4,1556337600),
(757,5,1556337600),
(757,6,1556337600),
(859,2,1556164800),
(938,2,1556164800),
(939,2,1556164800),
(940,2,1556164800),
(959,2,1556164800),
(960,2,1556164800),
(961,2,1556164800),
(962,2,1556164800),
(967,3,1556337600),
(967,4,1556337600),
(967,5,1556337600),
(967,6,1556337600),
(967,7,1556683200),
(994,2,1556164800),
(996,3,1556337600),
(996,4,1556337600),
(996,5,1556337600),
(996,6,1556337600),
(996,7,1556683200),
(1001,2,1556164800),
(1004,2,1556164800),
(1007,2,1556164800),
(1008,3,1556337600),
(1008,4,1556337600),
(1008,5,1556337600),
(1008,6,1556337600),
(1008,7,1556683200),
(1009,3,1556337600),
(1009,4,1556337600),
(1009,5,1556337600),
(1009,6,1556337600),
(1009,7,1556683200),
(1011,2,1556164800),
(1098,3,1556337600),
(1098,4,1556337600),
(1098,5,1556337600),
(1098,6,1556337600),
(1098,7,1556683200),
(1136,14,1556337600),
(1136,15,1556337600),
(1136,16,1556337600),
(1136,17,1556683200),
(1175,2,1556164800),
(1175,23,1556683200),
(1176,2,1556164800),
(1176,23,1556683200),
(1182,2,1556164800),
(1182,23,1556683200),
(1195,2,1556164800),
(1195,23,1556683200),
(1205,14,1556337600),
(1205,15,1556337600),
(1205,16,1556337600),
(1205,17,1556683200),
(1208,2,1556164800),
(1208,23,1556683200),
(1209,2,1556164800),
(1209,23,1556683200),
(1228,14,1556337600),
(1228,15,1556337600),
(1228,16,1556337600),
(1228,17,1556683200),
(1279,2,1556164800),
(1279,23,1556683200),
(1358,2,1556164800),
(1358,23,1556683200),
(1448,14,1556683200),
(1448,15,1556683200),
(1448,16,1556683200),
(1448,17,1556683200),
(1456,2,1556164800),
(1456,23,1556683200),
(1458,2,1556164800),
(1458,23,1556683200),
(1466,2,1556164800),
(1466,23,1556683200),
(1477,2,1556164800),
(1477,23,1556683200),
(1492,2,1556164800),
(1492,23,1556683200),
(1493,2,1556164800),
(1493,23,1556683200),
(1501,2,1556164800),
(1501,23,1556683200),
(1516,23,1556683200),
(1520,14,1556683200),
(1520,15,1556683200),
(1520,16,1556683200),
(1520,17,1556683200),
(1530,14,1556683200),
(1530,15,1556683200),
(1530,16,1556683200),
(1530,17,1556683200),
(1544,2,1556164800),
(1544,23,1556683200),
(1571,23,1556683200),
(1594,2,1556164800),
(1594,23,1556683200),
(1648,14,1556683200),
(1648,15,1556683200),
(1648,16,1556683200),
(1648,17,1556683200),
(1651,23,1556683200),
(1676,14,1556683200),
(1676,15,1556683200),
(1676,16,1556683200),
(1676,17,1556683200),
(1677,2,1556164800),
(1677,23,1556683200),
(1712,14,1556683200),
(1712,15,1556683200),
(1712,16,1556683200),
(1712,17,1556683200),
(1753,2,1556164800),
(1753,23,1556683200),
(1754,2,1556164800),
(1754,23,1556683200),
(1762,23,1556683200),
(1763,2,1556164800),
(1763,23,1556683200),
(1771,2,1556164800),
(1771,23,1556683200),
(1822,23,1556683200),
(1841,2,1556164800),
(1841,23,1556683200),
(1861,14,1556683200),
(1861,15,1556683200),
(1861,16,1556683200),
(1861,17,1556683200),
(1862,2,1556164800),
(1862,23,1556683200),
(1864,2,1556164800),
(1864,23,1556683200),
(1877,2,1556164800),
(1877,23,1556683200);

/*Table structure for table `instance_scenario_progress` */

DROP TABLE IF EXISTS `instance_scenario_progress`;

CREATE TABLE `instance_scenario_progress` (
  `id` int(10) unsigned NOT NULL,
  `criteria` int(10) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `instance_scenario_progress` */

/*Table structure for table `item_instance` */

DROP TABLE IF EXISTS `item_instance`;

CREATE TABLE `item_instance` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `itemEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `owner_guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `creatorGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `giftCreatorGuid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '1',
  `duration` int(10) NOT NULL DEFAULT '0',
  `charges` tinytext,
  `flags` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `enchantments` text NOT NULL,
  `randomPropertyType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `randomPropertyId` int(10) unsigned NOT NULL DEFAULT '0',
  `durability` smallint(5) unsigned NOT NULL DEFAULT '0',
  `playedTime` int(10) unsigned NOT NULL DEFAULT '0',
  `text` text,
  `transmogrification` int(10) unsigned NOT NULL DEFAULT '0',
  `upgradeId` int(10) unsigned NOT NULL DEFAULT '0',
  `enchantIllusion` int(10) unsigned NOT NULL DEFAULT '0',
  `battlePetSpeciesId` int(10) unsigned NOT NULL DEFAULT '0',
  `battlePetBreedData` int(10) unsigned NOT NULL DEFAULT '0',
  `battlePetLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `battlePetDisplayId` int(10) unsigned NOT NULL DEFAULT '0',
  `context` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `bonusListIDs` text,
  PRIMARY KEY (`guid`),
  KEY `idx_owner_guid` (`owner_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item System';

/*Data for the table `item_instance` */

insert  into `item_instance`(`guid`,`itemEntry`,`owner_guid`,`creatorGuid`,`giftCreatorGuid`,`count`,`duration`,`charges`,`flags`,`enchantments`,`randomPropertyType`,`randomPropertyId`,`durability`,`playedTime`,`text`,`transmogrification`,`upgradeId`,`enchantIllusion`,`battlePetSpeciesId`,`battlePetBreedData`,`battlePetLevel`,`battlePetDisplayId`,`context`,`bonusListIDs`) values 
(2,20893,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,55,0,'',0,0,0,0,0,0,0,0,''),
(4,20894,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,40,0,'',0,0,0,0,0,0,0,0,''),
(6,20978,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,40,0,'',0,0,0,0,0,0,0,0,''),
(8,20895,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,25,0,'',0,0,0,0,0,0,0,0,''),
(10,6948,1,0,0,1,0,'0 ',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(11,44819,1,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(12,46894,1,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(13,49362,1,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(14,71134,1,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(15,71134,1,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(16,90918,1,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(17,115301,1,0,0,1,0,'-1 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(18,116788,1,0,0,1,0,'-1 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(19,128513,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(20,139284,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(21,140997,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(22,140998,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(23,147876,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(24,21016,1,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,60,0,'',0,0,0,0,0,0,0,0,''),
(25,21015,1,0,0,1,0,'',2097152,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,20,0,'',0,0,0,0,0,0,0,0,''),
(26,20845,1,0,0,1,0,'',2097152,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(27,20846,1,0,0,1,0,'',2097152,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(29,157636,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,50,0,'',0,0,0,0,0,0,0,0,''),
(31,157636,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,50,0,'',0,0,0,0,0,0,0,0,''),
(33,157721,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,35,0,'',0,0,0,0,0,0,0,0,''),
(35,157720,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,35,0,'',0,0,0,0,0,0,0,0,''),
(37,157718,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,75,0,'',0,0,0,0,0,0,0,0,''),
(39,157716,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,35,0,'',0,0,0,0,0,0,0,0,''),
(41,157715,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,50,0,'',0,0,0,0,0,0,0,0,''),
(43,6948,2,0,0,1,0,'0 ',2097153,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(45,157714,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,105,0,'',0,0,0,0,0,0,0,0,''),
(47,157787,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(49,157787,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(51,157787,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(53,157787,2,0,0,1,0,'',1,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(55,156486,2,0,0,1,0,'-1 0 ',2097153,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(56,44819,2,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(57,46894,2,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(58,49362,2,0,0,1,0,'0 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(59,71134,2,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(60,71134,2,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(61,90918,2,0,0,1,0,'0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(62,115301,2,0,0,1,0,'-1 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(63,116788,2,0,0,1,0,'-1 0 ',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(64,128513,2,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(65,139284,2,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(66,140997,2,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(67,140998,2,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(68,147876,2,0,0,1,0,'',0,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(69,157022,2,0,0,1,0,'0 ',2097153,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,0,'',0,0,0,0,0,0,0,0,''),
(70,157758,2,0,0,1,0,'',2097153,'0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ',0,0,0,30,'',0,0,0,0,0,0,0,0,'');

/*Table structure for table `item_instance_artifact` */

DROP TABLE IF EXISTS `item_instance_artifact`;

CREATE TABLE `item_instance_artifact` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `xp` bigint(20) unsigned NOT NULL DEFAULT '0',
  `artifactAppearanceId` int(10) unsigned NOT NULL DEFAULT '0',
  `artifactTierId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_instance_artifact` */

/*Table structure for table `item_instance_artifact_powers` */

DROP TABLE IF EXISTS `item_instance_artifact_powers`;

CREATE TABLE `item_instance_artifact_powers` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `artifactPowerId` int(10) unsigned NOT NULL,
  `purchasedRank` tinyint(3) unsigned DEFAULT '0',
  PRIMARY KEY (`itemGuid`,`artifactPowerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_instance_artifact_powers` */

/*Table structure for table `item_instance_gems` */

DROP TABLE IF EXISTS `item_instance_gems`;

CREATE TABLE `item_instance_gems` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `gemItemId1` int(10) unsigned NOT NULL DEFAULT '0',
  `gemBonuses1` text,
  `gemContext1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gemScalingLevel1` int(10) unsigned NOT NULL DEFAULT '0',
  `gemItemId2` int(10) unsigned NOT NULL DEFAULT '0',
  `gemBonuses2` text,
  `gemContext2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gemScalingLevel2` int(10) unsigned NOT NULL DEFAULT '0',
  `gemItemId3` int(10) unsigned NOT NULL DEFAULT '0',
  `gemBonuses3` text,
  `gemContext3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gemScalingLevel3` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_instance_gems` */

/*Table structure for table `item_instance_modifiers` */

DROP TABLE IF EXISTS `item_instance_modifiers`;

CREATE TABLE `item_instance_modifiers` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `fixedScalingLevel` int(10) unsigned DEFAULT '0',
  `artifactKnowledgeLevel` int(10) unsigned DEFAULT '0',
  `challengeId` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix1` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix2` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeAffix3` int(10) unsigned NOT NULL DEFAULT '0',
  `challengeIsCharged` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_instance_modifiers` */

/*Table structure for table `item_instance_transmog` */

DROP TABLE IF EXISTS `item_instance_transmog`;

CREATE TABLE `item_instance_transmog` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `itemModifiedAppearanceAllSpecs` int(11) NOT NULL DEFAULT '0',
  `itemModifiedAppearanceSpec1` int(11) NOT NULL DEFAULT '0',
  `itemModifiedAppearanceSpec2` int(11) NOT NULL DEFAULT '0',
  `itemModifiedAppearanceSpec3` int(11) NOT NULL DEFAULT '0',
  `itemModifiedAppearanceSpec4` int(11) NOT NULL DEFAULT '0',
  `spellItemEnchantmentAllSpecs` int(11) NOT NULL DEFAULT '0',
  `spellItemEnchantmentSpec1` int(11) NOT NULL DEFAULT '0',
  `spellItemEnchantmentSpec2` int(11) NOT NULL DEFAULT '0',
  `spellItemEnchantmentSpec3` int(11) NOT NULL DEFAULT '0',
  `spellItemEnchantmentSpec4` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_instance_transmog` */

/*Table structure for table `item_loot_items` */

DROP TABLE IF EXISTS `item_loot_items`;

CREATE TABLE `item_loot_items` (
  `container_id` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'guid of container (item_instance.guid)',
  `item_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'loot item entry (item_instance.itemEntry)',
  `item_count` int(10) NOT NULL DEFAULT '0' COMMENT 'stack size',
  `follow_rules` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'follow loot rules',
  `ffa` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'free-for-all',
  `blocked` tinyint(1) NOT NULL DEFAULT '0',
  `counted` tinyint(1) NOT NULL DEFAULT '0',
  `under_threshold` tinyint(1) NOT NULL DEFAULT '0',
  `needs_quest` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'quest drop',
  `rnd_type` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'random enchantment type',
  `rnd_prop` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'random enchantment added when originally rolled',
  `rnd_suffix` int(10) NOT NULL DEFAULT '0' COMMENT 'random suffix added when originally rolled',
  `context` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `bonus_list_ids` text COMMENT 'Space separated list of bonus list ids',
  PRIMARY KEY (`container_id`,`item_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_loot_items` */

/*Table structure for table `item_loot_money` */

DROP TABLE IF EXISTS `item_loot_money`;

CREATE TABLE `item_loot_money` (
  `container_id` bigint(20) NOT NULL DEFAULT '0' COMMENT 'guid of container (item_instance.guid)',
  `money` int(10) NOT NULL DEFAULT '0' COMMENT 'money loot (in copper)',
  PRIMARY KEY (`container_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_loot_money` */

/*Table structure for table `item_refund_instance` */

DROP TABLE IF EXISTS `item_refund_instance`;

CREATE TABLE `item_refund_instance` (
  `item_guid` bigint(20) unsigned NOT NULL COMMENT 'Item GUID',
  `player_guid` bigint(20) unsigned NOT NULL COMMENT 'Player GUID',
  `paidMoney` bigint(20) unsigned NOT NULL DEFAULT '0',
  `paidExtendedCost` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`item_guid`,`player_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item Refund System';

/*Data for the table `item_refund_instance` */

/*Table structure for table `item_soulbound_trade_data` */

DROP TABLE IF EXISTS `item_soulbound_trade_data`;

CREATE TABLE `item_soulbound_trade_data` (
  `itemGuid` bigint(20) unsigned NOT NULL COMMENT 'Item GUID',
  `allowedPlayers` text NOT NULL COMMENT 'Space separated GUID list of players who can receive this item in trade',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item Refund System';

/*Data for the table `item_soulbound_trade_data` */

/*Table structure for table `lfg_data` */

DROP TABLE IF EXISTS `lfg_data`;

CREATE TABLE `lfg_data` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `dungeon` int(10) unsigned NOT NULL DEFAULT '0',
  `state` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='LFG Data';

/*Data for the table `lfg_data` */

/*Table structure for table `log_gm` */

DROP TABLE IF EXISTS `log_gm`;

CREATE TABLE `log_gm` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `date` datetime DEFAULT NULL,
  `gm_account_id` bigint(20) DEFAULT NULL,
  `gm_account_name` blob,
  `gm_character_id` bigint(20) DEFAULT NULL,
  `gm_character_name` blob,
  `gm_ip` text,
  `target_account_id` bigint(20) DEFAULT NULL,
  `target_account_name` blob,
  `target_character_id` bigint(20) DEFAULT NULL,
  `target_character_name` blob,
  `target_ip` text,
  `command` blob,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

/*Data for the table `log_gm` */

insert  into `log_gm`(`id`,`date`,`gm_account_id`,`gm_account_name`,`gm_character_id`,`gm_character_name`,`gm_ip`,`target_account_id`,`target_account_name`,`target_character_id`,`target_character_name`,`target_ip`,`command`) values 
(1,'2019-04-25 00:15:40',1,'ANDER@ANDER',2,'Verta','127.0.0.1',0,'',0,'','','Command: .gm on [X: -8175.683105 Y: 794.523376 Z: 74.008652 Map: 0 (Eastern Kingdoms) Area: 9171 (Stormwind Embassy) Zone: Stormwind City Selected:  (GUID Full: 0x00000000000000000000000000000000 Type: None Entry: 0 Low: 0)]'),
(2,'2019-04-25 00:15:46',1,'ANDER@ANDER',2,'Verta','127.0.0.1',0,'',0,'','','Command: .gm off [X: -8194.116211 Y: 776.750366 Z: 72.433151 Map: 0 (Eastern Kingdoms) Area: 9171 (Stormwind Embassy) Zone: Stormwind City Selected:  (GUID Full: 0x00000000000000000000000000000000 Type: None Entry: 0 Low: 0)]');

/*Table structure for table `mail` */

DROP TABLE IF EXISTS `mail`;

CREATE TABLE `mail` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Identifier',
  `messageType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `stationery` tinyint(3) NOT NULL DEFAULT '41',
  `mailTemplateId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `sender` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier',
  `receiver` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier',
  `subject` longtext,
  `body` longtext,
  `has_items` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expire_time` int(10) unsigned NOT NULL DEFAULT '0',
  `deliver_time` int(10) unsigned NOT NULL DEFAULT '0',
  `money` bigint(20) unsigned NOT NULL DEFAULT '0',
  `cod` bigint(20) unsigned NOT NULL DEFAULT '0',
  `checked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `idx_receiver` (`receiver`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Mail System';

/*Data for the table `mail` */

insert  into `mail`(`id`,`messageType`,`stationery`,`mailTemplateId`,`sender`,`receiver`,`subject`,`body`,`has_items`,`expire_time`,`deliver_time`,`money`,`cod`,`checked`) values 
(1,3,41,0,32842,1,'WoW\'s 4th anniversary!','Do you know that the World of Warcraft is now four years old? $B$BWe wanted to send you something to say thanks for sharing this game with us. Sure, the 4th anniversary present is traditionally \"flowers\"... but in WoW, it\'s \"bear\". $B$BWith that said, please accept this furry little friend! Just remember to hold his fish by the tail, not the body... that mouth is bigger than it looks. $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(2,3,41,0,24380,1,'Jade Tiger','',1,1558729430,1556137430,0,0,0),
(3,3,41,0,32842,1,'WoW\'s 5th anniversary!','Wow, another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. In celebration of our 5th year online, we decided to bring back our first raid encounter, the black dragon Onyxia. $B$BTo help remember the event, you are now the proud owner of your very own Onyxian Whelpling. We suggest you bring the little guy out whenever you can and say, \"Many whelps! Handle it!\" Your friends won\'t mind. Honest. $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(4,3,41,0,32842,1,'WoW\'s 7th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. With the return of a certain large dragon, this has been a rough year for the world of Azeroth. On the other hand, that means heroes like you are needed more than ever. $B$BGet out there and defend a shattered world! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(5,3,41,0,32842,1,'WoW\'s 8th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. With the return of a certain large dragon, this has been a rough year for the world of Azeroth. On the other hand, that means heroes like you are needed more than ever. $B$BGet out there and defend a shattered world! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(6,3,41,0,32842,1,'WoW\'s 9th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft with us. So here\'s a little celebration package to go with your adventures! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(7,3,41,0,32842,1,'WoW\'s 10th Anniversary','Can you believe it\'s been ten years? $B$BWe wanted to thank you for joining us in our celebration of the tenth anniversary of World of Warcraft with this adorable fiery fellow. Plucked from the Firelord\'s litter. $B$BThe Wow Dev Team.',1,1558729430,1556137430,0,0,0),
(8,3,41,0,24380,1,'Warlord\'s Deathwheel','',1,1558729430,1556137430,0,0,0),
(9,3,41,0,32842,1,'WoW\'s 11th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(10,3,41,0,32842,1,'WoW\'s 12th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(11,3,41,0,92219,1,'For the Alliance!','Decades ago, bloodthristy invaders emerged from the Dark Portal, rampaging through our lands and threatening our very existence. But with might, cunning, and a resolve that forged the Alliance amidst the flames of destruction. Our champions drove them back. Take these arms and bear them with pride. for you are a champion of the alliance!',1,1558729430,1556137430,0,0,0),
(12,3,41,0,89753,1,'For the Horde!','We Orcs came to this world decades ago, driven by demonic bloodlust. Pillaging and carving a swath of destruction. Now free of the blood curse. We stand proudly alongside the greatest warriors of azeroth. Defending family and homeland with our dying breath. But we must never forget that dark past. Lest it overtake us once again.Take these arms as a reminder of our origins, the foe we now face, and what it means to be of Horde, Lok\'tar Ogar!',1,1558729430,1556137430,0,0,0),
(13,3,41,0,32842,1,'WoW\'s 13th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558729430,1556137430,0,0,0),
(14,3,41,0,32842,2,'WoW\'s 4th anniversary!','Do you know that the World of Warcraft is now four years old? $B$BWe wanted to send you something to say thanks for sharing this game with us. Sure, the 4th anniversary present is traditionally \"flowers\"... but in WoW, it\'s \"bear\". $B$BWith that said, please accept this furry little friend! Just remember to hold his fish by the tail, not the body... that mouth is bigger than it looks. $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(15,3,41,0,24380,2,'Jade Tiger','',1,1558730203,1556138203,0,0,0),
(16,3,41,0,32842,2,'WoW\'s 5th anniversary!','Wow, another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. In celebration of our 5th year online, we decided to bring back our first raid encounter, the black dragon Onyxia. $B$BTo help remember the event, you are now the proud owner of your very own Onyxian Whelpling. We suggest you bring the little guy out whenever you can and say, \"Many whelps! Handle it!\" Your friends won\'t mind. Honest. $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(17,3,41,0,32842,2,'WoW\'s 7th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. With the return of a certain large dragon, this has been a rough year for the world of Azeroth. On the other hand, that means heroes like you are needed more than ever. $B$BGet out there and defend a shattered world! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(18,3,41,0,32842,2,'WoW\'s 8th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you again for continuing to play World of Warcraft with us. With the return of a certain large dragon, this has been a rough year for the world of Azeroth. On the other hand, that means heroes like you are needed more than ever. $B$BGet out there and defend a shattered world! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(19,3,41,0,32842,2,'WoW\'s 9th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft with us. So here\'s a little celebration package to go with your adventures! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(20,3,41,0,32842,2,'WoW\'s 10th Anniversary','Can you believe it\'s been ten years? $B$BWe wanted to thank you for joining us in our celebration of the tenth anniversary of World of Warcraft with this adorable fiery fellow. Plucked from the Firelord\'s litter. $B$BThe Wow Dev Team.',1,1558730203,1556138203,0,0,0),
(21,3,41,0,24380,2,'Warlord\'s Deathwheel','',1,1558730203,1556138203,0,0,0),
(22,3,41,0,32842,2,'WoW\'s 11th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(23,3,41,0,32842,2,'WoW\'s 12th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0),
(24,3,41,0,92219,2,'For the Alliance!','Decades ago, bloodthristy invaders emerged from the Dark Portal, rampaging through our lands and threatening our very existence. But with might, cunning, and a resolve that forged the Alliance amidst the flames of destruction. Our champions drove them back. Take these arms and bear them with pride. for you are a champion of the alliance!',1,1558730203,1556138203,0,0,0),
(25,3,41,0,89753,2,'For the Horde!','We Orcs came to this world decades ago, driven by demonic bloodlust. Pillaging and carving a swath of destruction. Now free of the blood curse. We stand proudly alongside the greatest warriors of azeroth. Defending family and homeland with our dying breath. But we must never forget that dark past. Lest it overtake us once again.Take these arms as a reminder of our origins, the foe we now face, and what it means to be of Horde, Lok\'tar Ogar!',1,1558730203,1556138203,0,0,0),
(26,3,41,0,32842,2,'WoW\'s 13th Anniversary!','Wow, yet another year has gone by for WoW! $B$BWe wanted to thank you for continuing to play World of Warcraft With us, so here\'s an Anniversary Gift to go with your adventures! $B$BThe WoW Dev Team.',1,1558730203,1556138203,0,0,0);

/*Table structure for table `mail_items` */

DROP TABLE IF EXISTS `mail_items`;

CREATE TABLE `mail_items` (
  `mail_id` int(10) unsigned NOT NULL DEFAULT '0',
  `item_guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `receiver` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier',
  PRIMARY KEY (`item_guid`),
  KEY `idx_receiver` (`receiver`),
  KEY `idx_mail_id` (`mail_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `mail_items` */

insert  into `mail_items`(`mail_id`,`item_guid`,`receiver`) values 
(1,11,1),
(2,12,1),
(3,13,1),
(4,14,1),
(5,15,1),
(6,16,1),
(7,17,1),
(8,18,1),
(9,19,1),
(10,20,1),
(11,21,1),
(12,22,1),
(13,23,1),
(14,56,2),
(15,57,2),
(16,58,2),
(17,59,2),
(18,60,2),
(19,61,2),
(20,62,2),
(21,63,2),
(22,64,2),
(23,65,2),
(24,66,2),
(25,67,2),
(26,68,2);

/*Table structure for table `pet_aura` */

DROP TABLE IF EXISTS `pet_aura`;

CREATE TABLE `pet_aura` (
  `guid` int(10) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  `spell` int(10) unsigned NOT NULL,
  `effectMask` int(10) unsigned NOT NULL,
  `recalculateMask` int(10) unsigned NOT NULL DEFAULT '0',
  `stackCount` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `maxDuration` int(11) NOT NULL DEFAULT '0',
  `remainTime` int(11) NOT NULL DEFAULT '0',
  `remainCharges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spell`,`effectMask`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `pet_aura` */

/*Table structure for table `pet_aura_effect` */

DROP TABLE IF EXISTS `pet_aura_effect`;

CREATE TABLE `pet_aura_effect` (
  `guid` int(10) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  `spell` int(10) unsigned NOT NULL,
  `effectMask` int(10) unsigned NOT NULL,
  `effectIndex` tinyint(3) unsigned NOT NULL,
  `amount` int(11) NOT NULL DEFAULT '0',
  `baseAmount` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`casterGuid`,`spell`,`effectMask`,`effectIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `pet_aura_effect` */

/*Table structure for table `pet_spell` */

DROP TABLE IF EXISTS `pet_spell`;

CREATE TABLE `pet_spell` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier',
  `active` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `pet_spell` */

/*Table structure for table `pet_spell_charges` */

DROP TABLE IF EXISTS `pet_spell_charges`;

CREATE TABLE `pet_spell_charges` (
  `guid` int(10) unsigned NOT NULL,
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCategory.dbc Identifier',
  `rechargeStart` int(10) unsigned NOT NULL DEFAULT '0',
  `rechargeEnd` int(10) unsigned NOT NULL DEFAULT '0',
  KEY `idx_guid` (`guid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pet_spell_charges` */

/*Table structure for table `pet_spell_cooldown` */

DROP TABLE IF EXISTS `pet_spell_cooldown`;

CREATE TABLE `pet_spell_cooldown` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell category Id',
  `categoryEnd` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pet_spell_cooldown` */

/*Table structure for table `petition` */

DROP TABLE IF EXISTS `petition`;

CREATE TABLE `petition` (
  `ownerguid` bigint(20) unsigned NOT NULL,
  `petitionguid` bigint(20) unsigned DEFAULT '0',
  `name` varchar(24) NOT NULL,
  PRIMARY KEY (`ownerguid`),
  UNIQUE KEY `index_ownerguid_petitionguid` (`ownerguid`,`petitionguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `petition` */

/*Table structure for table `petition_sign` */

DROP TABLE IF EXISTS `petition_sign`;

CREATE TABLE `petition_sign` (
  `ownerguid` bigint(20) unsigned NOT NULL,
  `petitionguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `playerguid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `player_account` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`petitionguid`,`playerguid`),
  KEY `Idx_playerguid` (`playerguid`),
  KEY `Idx_ownerguid` (`ownerguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `petition_sign` */

/*Table structure for table `pool_quest_save` */

DROP TABLE IF EXISTS `pool_quest_save`;

CREATE TABLE `pool_quest_save` (
  `pool_id` int(10) unsigned NOT NULL DEFAULT '0',
  `quest_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`pool_id`,`quest_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pool_quest_save` */

insert  into `pool_quest_save`(`pool_id`,`quest_id`) values 
(346,29349),
(347,26588),
(348,25155),
(349,25161),
(350,26536),
(351,26190),
(352,29355),
(353,29343),
(354,29358),
(355,29315),
(356,29361),
(357,29314),
(358,29324),
(359,11381),
(360,11668),
(361,13830),
(362,13103),
(363,12961),
(364,31334);

/*Table structure for table `pvpstats_battlegrounds` */

DROP TABLE IF EXISTS `pvpstats_battlegrounds`;

CREATE TABLE `pvpstats_battlegrounds` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `winner_faction` tinyint(4) NOT NULL,
  `bracket_id` tinyint(3) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pvpstats_battlegrounds` */

/*Table structure for table `pvpstats_players` */

DROP TABLE IF EXISTS `pvpstats_players`;

CREATE TABLE `pvpstats_players` (
  `battleground_id` bigint(20) unsigned NOT NULL,
  `character_guid` bigint(20) unsigned NOT NULL,
  `winner` bit(1) NOT NULL,
  `score_killing_blows` int(10) unsigned NOT NULL,
  `score_deaths` int(10) unsigned NOT NULL,
  `score_honorable_kills` int(10) unsigned NOT NULL,
  `score_bonus_honor` int(10) unsigned NOT NULL,
  `score_damage_done` int(10) unsigned NOT NULL,
  `score_healing_done` int(10) unsigned NOT NULL,
  `attr_1` int(10) unsigned NOT NULL,
  `attr_2` int(10) unsigned NOT NULL,
  `attr_3` int(10) unsigned NOT NULL,
  `attr_4` int(10) unsigned NOT NULL,
  `attr_5` int(10) unsigned NOT NULL,
  PRIMARY KEY (`battleground_id`,`character_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pvpstats_players` */

/*Table structure for table `quest_tracker` */

DROP TABLE IF EXISTS `quest_tracker`;

CREATE TABLE `quest_tracker` (
  `id` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `character_guid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `quest_accept_time` datetime NOT NULL,
  `quest_complete_time` datetime DEFAULT NULL,
  `quest_abandon_time` datetime DEFAULT NULL,
  `completed_by_gm` tinyint(1) NOT NULL DEFAULT '0',
  `core_hash` varchar(120) NOT NULL DEFAULT '0',
  `core_revision` varchar(120) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`,`character_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `quest_tracker` */

/*Table structure for table `reserved_name` */

DROP TABLE IF EXISTS `reserved_name`;

CREATE TABLE `reserved_name` (
  `name` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player Reserved Names';

/*Data for the table `reserved_name` */

/*Table structure for table `updates` */

DROP TABLE IF EXISTS `updates`;

CREATE TABLE `updates` (
  `name` varchar(200) NOT NULL COMMENT 'filename with extension of the update.',
  `hash` char(40) DEFAULT '' COMMENT 'sha1 hash of the sql file.',
  `state` enum('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
  `speed` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'time the query takes to apply in ms.',
  PRIMARY KEY (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='List of all applied updates in this database.';

/*Data for the table `updates` */

/*Table structure for table `updates_include` */

DROP TABLE IF EXISTS `updates_include`;

CREATE TABLE `updates_include` (
  `path` varchar(200) NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
  `state` enum('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
  PRIMARY KEY (`path`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='List of directories where we want to include sql updates.';

/*Data for the table `updates_include` */

insert  into `updates_include`(`path`,`state`) values 
('$/sql/coreteam/characters','RELEASED');

/*Table structure for table `warden_action` */

DROP TABLE IF EXISTS `warden_action`;

CREATE TABLE `warden_action` (
  `wardenId` smallint(5) unsigned NOT NULL,
  `action` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`wardenId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `warden_action` */

/*Table structure for table `world_quest` */

DROP TABLE IF EXISTS `world_quest`;

CREATE TABLE `world_quest` (
  `id` int(10) unsigned NOT NULL,
  `rewardid` int(10) unsigned NOT NULL,
  `starttime` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `world_quest` */

insert  into `world_quest`(`id`,`rewardid`,`starttime`) values 
(40168,0,1556136933),
(40173,0,1556136933),
(40337,56,1556136933),
(40786,0,1556136933),
(40787,0,1556136933),
(41057,65,1556136933),
(41078,38,1556136933),
(41177,0,1556136933),
(41293,69,1556136933),
(41416,46,1556136933),
(41511,22,1556136933),
(41554,55,1556136933),
(41597,83,1556136933),
(41857,13,1556136933),
(41930,20,1556136933),
(41931,36,1556136933),
(41944,45,1556136933),
(41949,82,1556136933),
(41990,36,1556136933),
(42019,63,1556136933),
(42025,80,1556136933),
(42062,36,1556136933),
(42080,35,1556136933),
(42087,53,1556136933),
(42108,48,1556136933),
(42111,47,1556136933),
(42124,47,1556136933),
(42150,16,1556136933),
(42159,36,1556136933),
(42160,14,1556136933),
(42178,51,1556136933),
(42183,65,1556136933),
(42209,24,1556136933),
(42233,0,1556137173),
(42275,48,1556136933),
(42276,34,1556136933),
(42421,0,1556136933),
(42636,5,1556136933),
(42798,0,1556136933),
(42922,13,1556136933),
(43179,0,1556136993),
(43183,79,1556136933),
(43242,0,1556136933),
(43282,0,1556136933),
(43283,0,1556136933),
(43286,0,1556136933),
(43290,0,1556136933),
(43292,0,1556136933),
(43296,0,1556136933),
(43300,0,1556136933),
(43301,0,1556136933),
(43327,69,1556136933),
(43328,63,1556136933),
(43344,0,1556136933),
(43429,16,1556136933),
(43458,14,1556136933),
(43476,0,1556136933),
(43512,11,1556136933),
(43616,58,1556136933),
(43630,24,1556136933),
(43710,48,1556136933),
(43712,13,1556136933),
(43714,13,1556136933),
(43751,51,1556136933),
(43753,53,1556136933),
(43772,82,1556136933),
(43807,51,1556136933),
(43943,38,1556136933),
(44121,0,1556136933),
(44291,81,1556136933),
(44303,52,1556136933),
(44305,7,1556136933),
(44784,76,1556136933),
(44799,25,1556136933),
(44801,29,1556136933),
(44816,7,1556136933),
(44892,27,1556136933),
(44933,67,1556136933),
(45069,69,1556136933),
(45070,69,1556136933);

/*Table structure for table `worldstates` */

DROP TABLE IF EXISTS `worldstates`;

CREATE TABLE `worldstates` (
  `entry` int(10) unsigned NOT NULL DEFAULT '0',
  `value` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` tinytext,
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Variable Saves';

/*Data for the table `worldstates` */

insert  into `worldstates`(`entry`,`value`,`comment`) values 
(1,0,NULL),
(2,0,NULL),
(3,0,NULL),
(4,0,NULL),
(5,0,NULL),
(6,0,NULL),
(7,0,NULL),
(8,0,NULL),
(9,0,NULL),
(10,0,NULL),
(11,0,NULL),
(12,0,NULL),
(13,0,NULL),
(14,0,NULL),
(15,0,NULL),
(16,1556140368,NULL),
(17,0,NULL),
(18,0,NULL),
(19,0,NULL),
(20,0,NULL),
(21,0,NULL),
(22,0,NULL),
(23,0,NULL),
(24,0,NULL),
(25,1556140368,NULL),
(26,0,NULL),
(27,0,NULL),
(28,1556140368,NULL),
(29,1556140368,NULL),
(30,0,NULL),
(31,0,NULL),
(32,0,NULL),
(33,0,NULL),
(34,0,NULL),
(35,0,NULL),
(36,0,NULL),
(37,0,NULL),
(38,0,NULL),
(39,0,NULL),
(40,1556140368,NULL),
(41,0,NULL),
(42,0,NULL),
(43,0,NULL),
(44,0,NULL),
(45,0,NULL),
(46,0,NULL),
(47,0,NULL),
(48,0,NULL),
(49,0,NULL),
(50,0,NULL),
(51,0,NULL),
(52,0,NULL),
(53,0,NULL),
(54,0,NULL),
(55,0,NULL),
(56,0,NULL),
(57,0,NULL),
(58,0,NULL),
(59,0,NULL),
(60,0,NULL),
(61,0,NULL),
(62,0,NULL),
(63,0,NULL),
(64,0,NULL),
(65,0,NULL),
(66,0,NULL),
(67,0,NULL),
(68,0,NULL),
(69,0,NULL),
(70,0,NULL),
(71,0,NULL),
(72,0,NULL),
(73,0,NULL),
(74,0,NULL),
(75,0,NULL),
(76,0,NULL),
(77,0,NULL),
(78,0,NULL),
(79,0,NULL),
(80,0,NULL),
(81,0,NULL),
(82,0,NULL),
(83,0,NULL),
(84,0,NULL),
(85,0,NULL),
(86,0,NULL),
(87,0,NULL),
(88,0,NULL),
(89,0,NULL),
(90,0,NULL),
(91,0,NULL),
(92,0,NULL),
(93,0,NULL),
(94,0,NULL),
(95,0,NULL),
(96,0,NULL),
(97,0,NULL),
(98,0,NULL),
(99,0,NULL),
(100,0,NULL),
(101,0,NULL),
(102,0,NULL),
(103,0,NULL),
(3781,9000000,NULL),
(3801,0,NULL),
(3802,0,NULL),
(5332,600000,NULL),
(5334,1,NULL),
(5344,0,NULL),
(5384,0,NULL),
(5385,1,NULL),
(5387,1,NULL),
(5546,0,NULL),
(5547,0,NULL),
(20001,1556679600,'NextArenaPointDistributionTime'),
(20002,1556741673,'NextWeeklyQuestResetTime'),
(20003,1556161200,'NextBGRandomDailyResetTime'),
(20004,0,'cleaning_flags'),
(20006,1556161200,NULL),
(20007,1556658000,NULL),
(20050,1,NULL);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
