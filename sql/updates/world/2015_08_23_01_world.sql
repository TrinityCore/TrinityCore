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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `blackmarket_template` */

insert  into `blackmarket_template`(`marketId`,`sellerNpc`,`itemEntry`,`quantity`,`minBid`,`duration`,`chance`,`bonusListIDs`) VALUES
 (12,32216,63043,1,200000000,86400,25,NULL),
 (13,28951,44974,1,10000000,86400,25,NULL),
 (15,64179,125237,1,200000000,86400,25,NULL),
 (21,46556,124321,1,100000000,86400,25,'564 566');
