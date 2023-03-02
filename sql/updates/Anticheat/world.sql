/*
SQLyog Community v12.3.2 (64 bit)
MySQL - 5.7.13-log : Database - world
*********************************************************************
*/


/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `cheat_sanctions` */

DROP TABLE IF EXISTS `cheat_sanctions`;

CREATE TABLE `cheat_sanctions` (
  `flag` int(11) NOT NULL,
  `tick_max` int(11) NOT NULL DEFAULT '0',
  `tick_action` int(11) NOT NULL DEFAULT '0',
  `total_max` int(11) NOT NULL DEFAULT '0',
  `total_action` int(11) NOT NULL DEFAULT '0',
  `comment` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

/*Data for the table `cheat_sanctions` */

insert  into `cheat_sanctions`(`flag`,`tick_max`,`tick_action`,`total_max`,`total_action`,`comment`) values 

(0,0,0,0,0,'CHEAT_TYPE_WALL_CLIMB - not implemented'),

(1,2,3,0,0,'CHEAT_TYPE_WATER_WALK'),

(2,1,1,0,0,'Forbidden'),

(3,1,3,0,0,'BgNotStarted'),

(4,2,7,0,0,'MultiJump'),

(5,4,3,0,0,'FallUp'),

(6,4,1,0,0,'PveFlyhack'),

(6,40,3,0,0,'PveFlyhack'),

(7,2,3,0,0,'TimeBack'),

(8,1,1,0,0,'CHEAT_TYPE_OVERSPEED_JUMP'),

(9,1,1,0,0,'CHEAT_TYPE_JUMP_SPEED_CHANGE'),

(10,1,3,0,0,'FlyHackSwim'),

(11,1,1,0,0,'CHEAT_TYPE_UNROOT'),

(11,2,7,0,0,'ClientTimeNull'),

(12,1,1,0,0,'CHEAT_TYPE_ROOT_MOVE'),

(13,1,1,0,0,'CHEAT_TYPE_ROOT_IGNORED'),

(14,30,7,0,0,'OverspeedDist'),

(15,10000,1,0,0,'CHEAT_TYPE_DESYNC'),

(17,2,3,100,3,'Explore'),

(18,2,3,50,3,'ExploreHighLevel'),

(19,3,1,0,0,'SpeedhackZ'),

(20,2,1,0,0,'SkipHB'),

(21,5,15,0,0,'NumDesync'),

(22,1,7,0,0,'FakeTransport'),

(23,1,7,0,0,'TeleToTransport'),

(24,1,3,0,0,'SlowFallHack');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
