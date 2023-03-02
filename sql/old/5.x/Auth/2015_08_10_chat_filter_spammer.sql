DROP TABLE IF EXISTS `chat_filter`;
CREATE TABLE `chat_filter` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `text` char(64) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `chat_filter` */
insert  into `chat_filter`(`id`,`text`) values (1,'www'),(2,'w w w'),(3,'ww w');
/*Table structure for table `spammer` */