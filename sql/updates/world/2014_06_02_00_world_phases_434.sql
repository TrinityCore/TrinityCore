DROP TABLE IF EXISTS `spell_phase`;
DROP TABLE IF EXISTS `phase_definitions`;

/*Table structure for table `phase_definitions` */

DROP TABLE IF EXISTS `phase_definitions`;

CREATE TABLE `phase_definitions` (
  `zoneId` int(10) unsigned NOT NULL DEFAULT '0',
  `entry` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `phaseId` int(10) unsigned NOT NULL DEFAULT '0',
  `phaseGroup` int(10) NOT NULL DEFAULT '0',
  `comment` text,
  PRIMARY KEY (`zoneId`,`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Table structure for table `phase_info` */

DROP TABLE IF EXISTS `phase_info`;

CREATE TABLE `phase_info` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `worldmapareaswap` int(10) unsigned NOT NULL DEFAULT '0',
  `terrainswapmap` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;