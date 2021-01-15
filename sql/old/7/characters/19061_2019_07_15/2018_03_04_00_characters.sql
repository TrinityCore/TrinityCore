--
-- Table structure for table `character_pvp_talent`
--
DROP TABLE IF EXISTS `character_pvp_talent`;
CREATE TABLE `character_pvp_talent` (
  `guid` bigint(20) unsigned NOT NULL,
  `talentId` mediumint(8) unsigned NOT NULL,
  `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`talentId`,`talentGroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
