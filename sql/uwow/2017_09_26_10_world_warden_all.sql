/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `warden_checks` */

DROP TABLE IF EXISTS `warden_checks`;

CREATE TABLE `warden_checks` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `data` varchar(48) NOT NULL DEFAULT '',
  `str` varchar(512) NOT NULL DEFAULT '',
  `address` int(10) unsigned NOT NULL DEFAULT '0',
  `length` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `result` varchar(100) NOT NULL DEFAULT '',
  `banreason` varchar(100) NOT NULL DEFAULT '',
  `action` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `bantime` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` varchar(100) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

/*Data for the table `warden_checks` */

insert  into `warden_checks`(`id`,`type`,`data`,`str`,`address`,`length`,`result`,`banreason`,`action`,`bantime`,`comment`) values (1,9,'','if PQR_Addon_Loaded then LU=\"1\" end',0,0,'','PQR Bot',2,10800,'Detect PQR'),(2,3,'A444519CC419521B6D39990C1D95329C8D94B59226CBAA98','',16507,32,'E9','WPE PRO',2,2592000,''),(3,6,'','RPE.DLL',0,0,'E9','rPE',2,2592000,''),(4,7,'','SLASH_COLORMECMON1',0,0,'','',3,0,''),(5,7,'','SLASH_PTMENU1',0,0,'','',3,0,''),(6,7,'','SLASH_SUPERDUPERMACRO1',0,0,'','',3,0,''),(7,7,'','SLASH_BINDPAD2',0,0,'','',3,0,''),(8,7,'','SLASH_SUPERMACRO1',0,0,'','',3,0,''),(9,3,'5C3F7F9058E1A5BD950053CA3EF7F1A2F02DD7A6A1FD3589','',36,20,'E9','WPS',2,2592000,'packet editor');

/*Table structure for table `warden_custom_mpq_data` */

DROP TABLE IF EXISTS `warden_custom_mpq_data`;

CREATE TABLE `warden_custom_mpq_data` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `filename` varchar(100) NOT NULL DEFAULT '',
  `hash` varchar(40) NOT NULL DEFAULT '',
  `locale` tinyint(3) NOT NULL DEFAULT '-1',
  `comment` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `warden_custom_mpq_data` */

/*Table structure for table `warden_overrides` */

DROP TABLE IF EXISTS `warden_overrides`;

CREATE TABLE `warden_overrides` (
  `checkId` smallint(5) unsigned NOT NULL,
  `action` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `banTime` int(10) unsigned NOT NULL DEFAULT '0',
  `enabled` tinyint(1) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`checkId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `warden_overrides` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
