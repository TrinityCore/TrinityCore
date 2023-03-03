
DROP TABLE IF EXISTS `character_archaelogy`;

CREATE TABLE `character_archaelogy` (
  `guid` int(12) unsigned NOT NULL,
  `pointId` int(11) unsigned NOT NULL,
  `count` int(11) unsigned NOT NULL,
  `active` tinyint(1) NOT NULL,
  `resetTime` int(12) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`pointId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `character_archproject` */

DROP TABLE IF EXISTS `character_archproject`;

CREATE TABLE `character_archproject` (
  `guid` int(11) unsigned NOT NULL DEFAULT '0',
  `projectId` int(11) unsigned NOT NULL DEFAULT '0',
  `RaceID` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`projectId`,`RaceID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `character_archprojecthistory` */

DROP TABLE IF EXISTS `character_archprojecthistory`;

CREATE TABLE `character_archprojecthistory` (
  `guid` int(11) unsigned NOT NULL,
  `projectId` int(11) unsigned NOT NULL DEFAULT '0',
  `count` int(11) unsigned NOT NULL DEFAULT '0',
  `TimeCreated` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `character_donate` */

DROP TABLE IF EXISTS `character_donate`;

CREATE TABLE `character_donate` (
  `owner_guid` int(10) unsigned NOT NULL,
  `itemguid` int(10) unsigned NOT NULL,
  `itemEntry` int(10) unsigned NOT NULL,
  `efircount` int(10) unsigned NOT NULL,
  `count` int(10) unsigned NOT NULL,
  `state` int(11) NOT NULL DEFAULT '0',
  KEY `owner_guid` (`owner_guid`),
  KEY `itemguid` (`itemguid`),
  KEY `itemEntry` (`itemEntry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `character_donate_service` */

DROP TABLE IF EXISTS `character_donate_service`;

CREATE TABLE `character_donate_service` (
  `account` int(11) NOT NULL DEFAULT '0',
  `guid` int(11) NOT NULL DEFAULT '0',
  `service` varchar(50) NOT NULL DEFAULT '',
  `cost` int(10) NOT NULL DEFAULT '0',
  `targetguid` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Table structure for table `character_kill` */

DROP TABLE IF EXISTS `character_kill`;

CREATE TABLE `character_kill` (
  `guid` int(30) NOT NULL DEFAULT '0',
  `victim_guid` int(30) NOT NULL DEFAULT '0',
  `count` tinyint(3) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`victim_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Kills Yesterday';
