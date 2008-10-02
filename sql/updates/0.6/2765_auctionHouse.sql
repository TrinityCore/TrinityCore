DROP TABLE IF EXISTS `auctionhouse`;
CREATE TABLE `auctionhouse` (
  `id` bigint(20) unsigned NOT NULL default '0',
  `auctioneerguid` int(32) NOT NULL default '0',
  `itemguid` int(32) NOT NULL default '0',
  `item_template` int(11) unsigned NOT NULL default '0' COMMENT 'Item Identifier',
  `itemowner` int(32) NOT NULL default '0',
  `buyoutprice` int(32) NOT NULL default '0',
  `time` bigint(40) NOT NULL default '0',
  `buyguid` int(32) NOT NULL default '0',
  `lastbid` int(32) NOT NULL default '0',
  `startbid` int(32) NOT NULL default '0',
  `deposit` int(11) NOT NULL default '0',
  `location` tinyint(3) unsigned NOT NULL default '3',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

