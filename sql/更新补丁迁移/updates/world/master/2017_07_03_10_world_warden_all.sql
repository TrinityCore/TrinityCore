DROP TABLE IF EXISTS `warden_checks`;
DROP TABLE IF EXISTS `warden_action`;

CREATE TABLE `warden_action` (
  `checkId` smallint(5) unsigned NOT NULL,
  `action` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`checkId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `warden_action` */

/*Table structure for table `warden_checks` */

DROP TABLE IF EXISTS `warden_checks`;

CREATE TABLE `warden_checks` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `data` varchar(48) NOT NULL DEFAULT '',
  `str` varchar(255) NOT NULL DEFAULT '',
  `address` int(10) unsigned NOT NULL DEFAULT '0',
  `length` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `result` varchar(100) NOT NULL DEFAULT '',
  `comment` varchar(100) NOT NULL DEFAULT '',
  `action` tinyint(3) NOT NULL DEFAULT '0',
  `bantime` int(12) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

/*Data for the table `warden_checks` */

insert  into `warden_checks`(`id`,`type`,`data`,`str`,`address`,`length`,`result`,`comment`,`action`,`bantime`) values (1,3,'A444519CC419521B6D39990C1D95329C8D94B59226CBAA98','',16507,32,'E9','WPE PRO',2,2592000),(3,6,'','RPE.DLL',0,0,'E9','rPE',0,0),(2,3,'5C3F7F9058E1A5BD950053CA3EF7F1A2F02DD7A6A1FD3589','',36,20,'E9','WPS',0,0),(4,7,'','SLASH_COLORMECMON1',0,0,'','Banned addon ColorMe',0,0),(5,7,'','SLASH_PTMENU1',0,0,'','Banned addon Punistool',0,0),(7,7,'','SLASH_SUPERDUPERMACRO1',0,0,'','Banned addon SDM',0,0),(6,7,'','SLASH_BINDPAD2',0,0,'','Banned addon BindPad',0,0),(8,7,'','SLASH_SUPERMACRO1',0,0,'','Banned addon SuperMacro',0,0),(9,2,'2C0D78C89B809433EC7E46CBEC1E4781ACE67B3EAD2285A5','',0,10,'E9','PQR_1',0,0),(10,2,'2E446AF5DD8CB0CA673D7D105FD9E12891178C14DAD6F088','',0,10,'E9','PQR_2',0,0),(11,2,'7FB94CDADE51BB235AAACB90E61B709EFF3B325F707F8FB4','',0,10,'E9','PQR_3',0,0);