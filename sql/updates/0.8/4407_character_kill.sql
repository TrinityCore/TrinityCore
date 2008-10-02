DROP TABLE IF EXISTS `character_kill`;
CREATE TABLE `character_kill` (
  `guid` int(11) NOT NULL default '0',
  `victim_guid` int(11) NOT NULL default '0',
  `count` tinyint(3) NOT NULL default '0',
  PRIMARY KEY  (`guid`,`victim_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Kills Yesterday';