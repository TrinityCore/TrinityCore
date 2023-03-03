/*
SQLyog Ultimate
MySQL - 5.7.14-log : Database - auth
*********************************************************************
*/


/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `antispam_blacklist` */

DROP TABLE IF EXISTS `antispam_blacklist`;

CREATE TABLE `antispam_blacklist` (
  `word` varchar(32) NOT NULL DEFAULT '',
  PRIMARY KEY (`word`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `antispam_blacklist` */

LOCK TABLES `antispam_blacklist` WRITE;

insert  into `antispam_blacklist`(`word`) values ('4GAMEPOWER'),('ELYSIUMAEWOW'),('TRINITYWOW'),('TRINITYWOW'),('TRINITYWOW'),('TRINITYWOW'),('G4W@W'),('G4WOW'),('GOLD4MMO'),('GOLDCEO'),('GOLDDEAL'),('GOLDINSIDER'),('ILOVEUGOLD'),('ITEM4GAME'),('ITEM4WOW'),('MMOGO'),('MMOLORD'),('MMOOK'),('MMOSE'),('MMOTANK'),('MONEYFORGAMES'),('NOST100'),('NOST1OO'),('OKOGAME'),('OKOGAMES'),('OKOGOMES'),('PVPBANK'),('RNRNOOK'),('RNRNOSE'),('SELLNGOLD'),('SINBAGAME'),('SINBAGOLD'),('SINBAONLINE'),('SUSANGAME'),('WOWMARY'),('WTSITEM'),('X2GOLD'),('XIAOBAIMOSHOUJINGJI');

UNLOCK TABLES;

/*Table structure for table `antispam_detected` */

DROP TABLE IF EXISTS `antispam_detected`;

CREATE TABLE `antispam_detected` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `detectScore` mediumint(5) NOT NULL DEFAULT '0',
  `detectTime` bigint(20) unsigned NOT NULL DEFAULT '0',
  `unmuteTime` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `antispam_detected` */

LOCK TABLES `antispam_detected` WRITE;

UNLOCK TABLES;

/*Table structure for table `antispam_replacement` */

DROP TABLE IF EXISTS `antispam_replacement`;

CREATE TABLE `antispam_replacement` (
  `from` varchar(32) NOT NULL DEFAULT '',
  `to` varchar(32) NOT NULL DEFAULT '',
  PRIMARY KEY (`from`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `antispam_replacement` */

LOCK TABLES `antispam_replacement` WRITE;

insert  into `antispam_replacement`(`from`,`to`) values ('\\\\/\\\\/','W'),('/\\/\\','M'),('0','O'),('...hic!',''),('()','O'),('\\/\\/','W'),('/\\\\','A'),('VV','W'),('@','O'),('/V\\','M'),('/\\\\/\\\\','M'),('㎜','MM'),('!<','K');

UNLOCK TABLES;

/*Table structure for table `antispam_scores` */

DROP TABLE IF EXISTS `antispam_scores`;

CREATE TABLE `antispam_scores` (
  `word` varchar(32) NOT NULL DEFAULT '',
  `score` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(1) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`word`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `antispam_scores` */

LOCK TABLES `antispam_scores` WRITE;

insert  into `antispam_scores`(`word`,`score`,`type`) values ('>>',1,1),('<<',1,1),('5OG',1,1),('$',2,1),('MOTANK',4,0),('\\\\',2,1),('ACOUNT',1,0),('CHEAP',2,0),('LEVELING',1,0),('LEVLING',1,0),('LEVILING',1,0),('LVLING',1,0),('SAFE',1,0),('SERVICE',1,0),('NOST',1,0),('COM',1,0),('PRICE',2,0),('GOLD',2,0),('SKYPE',2,0),('EPIC',2,0),('DOLARS',2,0),('PROFESIONAL',2,0),('RELIABLE',2,0),('PROMOTION',2,0),('DELIVER',2,0),('NAX',2,0),('GAMES',2,0),('GRETINGS',2,0),('WEBSITE',2,0),('GOID',2,0),('ITEM4',5,1),('1OO',2,1),('POWER',1,0),('SELGOLD',2,0),('FAST',1,0),('25G',2,1),('981526249',3,1),('XIAOYUAN9921521',3,1),('MANFARM',1,1),('USD',2,0),('GWOW',3,0),('EUR',2,0),('80G',1,1),('OKO',1,0),('G4',2,1),('2OG',1,1),('MSD',3,0),('3VV',3,1),('3W',2,1),('SELL',1,1),('WVWOKO',4,0),('G=$',3,1),('1OG',1,0),('COIN',0,1),('P0VVER',2,1),('IEVEIING',2,1),('GO1D',2,1),('POWERLEVELING',2,0);

UNLOCK TABLES;

/*Table structure for table `antispam_unicode` */

DROP TABLE IF EXISTS `antispam_unicode`;

CREATE TABLE `antispam_unicode` (
  `from` mediumint(5) unsigned NOT NULL DEFAULT '0',
  `to` mediumint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`from`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `antispam_unicode` */

LOCK TABLES `antispam_unicode` WRITE;

insert  into `antispam_unicode`(`from`,`to`) values (1063,52),(1054,79),(1057,67),(1052,77),(927,79),(1050,75),(913,65),(917,69),(1062,85),(9675,79),(1040,65),(1058,84),(1064,87),(1025,69),(1055,78),(1065,87),(922,75),(924,77),(1045,69),(968,87),(192,65),(210,79),(211,79),(242,79),(324,78),(328,78),(332,79),(466,79),(59336,78),(12562,84),(8745,78),(65325,77),(959,79),(945,65),(954,75),(12295,79),(65323,75),(65296,79),(65355,75),(65357,77),(65319,71),(925,78);

UNLOCK TABLES;

/*!50106 set global event_scheduler = 1*/;

/* Event structure for event `DetectUpdate` */

/*!50106 DROP EVENT IF EXISTS `DetectUpdate`*/;

DELIMITER $$

/*!50106 CREATE DEFINER=`root`@`localhost` EVENT `DetectUpdate` ON SCHEDULE EVERY 1 MINUTE STARTS '2017-01-01 00:00:00' ON COMPLETION PRESERVE ENABLE DO BEGIN

        SELECT @time:= UNIX_TIMESTAMP();

        UPDATE `antispam_detected` SET `unmuteTime` = 0 WHERE @time > `unmuteTime`;

	    UPDATE `antispam_detected` SET `detectScore` = `detectScore` - 1 WHERE `detectScore` < 3 AND (@time - `detectTime`) > 7200;

	    DELETE FROM `antispam_detected` WHERE `detectScore` <= 0 AND (@time - `detectTime`) > 7200;

	END */$$
DELIMITER ;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
