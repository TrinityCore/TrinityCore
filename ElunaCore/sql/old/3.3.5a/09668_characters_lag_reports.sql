DROP TABLE IF EXISTS `lag_reports`;
CREATE TABLE `lag_reports` (
  `report_id` int(10) NOT NULL auto_increment,
  `player` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `lag_type` int(10) NOT NULL DEFAULT '0',
  `map` int(11) NOT NULL DEFAULT '0',
  `posX` float NOT NULL default '0',
  `posY` float NOT NULL default '0',
  `posZ` float NOT NULL default '0',
  PRIMARY KEY  (`report_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';
