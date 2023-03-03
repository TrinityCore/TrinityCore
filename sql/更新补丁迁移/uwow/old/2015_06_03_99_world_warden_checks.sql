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
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

/*Data for the table `warden_checks` */

insert  into `warden_checks`(`id`,`type`,`data`,`str`,`address`,`length`,`result`,`comment`) values (1,27,'A444519CC419521B6D39990C1D95329C8D94B59226CBAA98',NULL,16507,32,'E9','WPE PRO detected');