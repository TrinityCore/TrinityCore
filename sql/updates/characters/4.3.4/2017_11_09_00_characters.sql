/*Table structure for table `character_archaeology_completed` */

DROP TABLE IF EXISTS `character_archaeology_completed`;

CREATE TABLE `character_archaeology_completed` (
  `guid` int(10) unsigned NOT NULL,
  `project` smallint(5) unsigned NOT NULL,
  `time` int(10) NOT NULL,
  `count` int(10) NOT NULL,
  PRIMARY KEY (`guid`,`project`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_archaeology_completed` */

/*Table structure for table `character_archaeology_projects` */

DROP TABLE IF EXISTS `character_archaeology_projects`;

CREATE TABLE `character_archaeology_projects` (
  `guid` int(10) unsigned NOT NULL,
  `branch` tinyint(3) unsigned NOT NULL,
  `project` mediumint(8) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`branch`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_archaeology_projects` */

/*Table structure for table `character_archaeology_sites` */

DROP TABLE IF EXISTS `character_archaeology_sites`;

CREATE TABLE `character_archaeology_sites` (
  `guid` int(10) unsigned NOT NULL,
  `site` tinyint(3) unsigned NOT NULL,
  `type` smallint(5) unsigned NOT NULL,
  `finds` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`site`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_archaeology_sites` */

