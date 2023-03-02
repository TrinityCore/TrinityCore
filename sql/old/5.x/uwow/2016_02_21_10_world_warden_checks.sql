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
  `type` tinyint(3) unsigned DEFAULT NULL,
  `data` varchar(48) DEFAULT NULL,
  `str` varchar(20) DEFAULT NULL,
  `address` int(10) unsigned DEFAULT NULL,
  `length` tinyint(3) unsigned DEFAULT NULL,
  `result` varchar(24) DEFAULT NULL,
  `comment` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `warden_checks` */

insert  into `warden_checks`(`id`,`type`,`data`,`str`,`address`,`length`,`result`,`comment`) values (1,27,'A444519CC419521B6D39990C1D95329C8D94B59226CBAA98',NULL,16507,32,'E9','WPE PRO detected'),(2,186,'5C3F7F9058E1A5BD950053CA3EF7F1A2F02DD7A6A1FD3589',NULL,36,20,'E9','WPE PRO detected');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
