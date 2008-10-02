DROP TABLE IF EXISTS `character_gifts`;

CREATE TABLE `character_gifts` (
  `guid` int(20) unsigned NOT NULL default '0',
  `item_guid` int(11) unsigned NOT NULL default '0',
  `entry` int(20) unsigned NOT NULL default '0',
  `flags` int(20) unsigned NOT NULL default '0',
  KEY `idx_guid` (`guid`),
  PRIMARY KEY (`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
