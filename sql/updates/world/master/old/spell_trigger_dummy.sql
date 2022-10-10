/*
SQLyog Professional v11.24 (64 bit)
MySQL - 5.5.31-0+wheezy1 : Database - trinworld505
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `spell_trigger_dummy` */

DROP TABLE IF EXISTS `spell_trigger_dummy`;

CREATE TABLE `spell_trigger_dummy` (
  `spell_id` mediumint(8) NOT NULL,
  `spell_trigger` mediumint(8) NOT NULL,
  `option` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `target` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `bp0` float NOT NULL DEFAULT '0',
  `bp1` float NOT NULL DEFAULT '0',
  `bp2` float NOT NULL DEFAULT '0',
  `effectmask` tinyint(3) NOT NULL DEFAULT '7',
  `aura` mediumint(8) NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`spell_id`,`spell_trigger`,`option`,`aura`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `spell_trigger_dummy` */

insert  into `spell_trigger_dummy`(`spell_id`,`spell_trigger`,`option`,`target`,`bp0`,`bp1`,`bp2`,`effectmask`,`aura`,`comment`) values (119905,119899,14,2,0,0,0,7,0,'Прижигание ран хозяина (Особая способность)'),(119907,0,14,2,0,0,0,7,0,'Обезоруживание (Особая способность)'),(119913,0,15,2,0,0,0,7,0,'Кнут Скверны (Особая способность)'),(119911,0,14,2,0,0,0,7,0,'Оптический удар (Особая способность)'),(119909,0,15,2,0,0,0,7,0,'Удар кнутом (Особая способность)'),(119910,0,14,2,0,0,0,7,0,'Запрет чар (Особая способность)'),(119914,89751,14,2,0,0,0,7,0,'Буря Скверны (Особая способность)'),(119915,115831,14,2,0,0,0,7,0,'Буря гнева (Особая способность)');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
