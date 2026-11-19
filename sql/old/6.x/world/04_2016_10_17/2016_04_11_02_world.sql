DROP TABLE IF EXISTS `blackmarket_template`;
CREATE TABLE `blackmarket_template` (
  `marketId` int(10) NOT NULL DEFAULT '0',
  `sellerNpc` mediumint(8) NOT NULL DEFAULT '0',
  `itemEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `quantity` int(10) NOT NULL DEFAULT '1',
  `minBid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `duration` int(10) NOT NULL DEFAULT '0',
  `chance` float NOT NULL DEFAULT '0',
  `bonusListIDs` text,
  PRIMARY KEY (`marketId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
