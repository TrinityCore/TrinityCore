--
-- Table structure for table `auctionhousebot`
--

CREATE TABLE IF NOT EXISTS `auctionhousebot` (
  `auctionhouse` int(11) NOT NULL default '0' COMMENT 'mapID of the auctionhouse.',
  `name` char(25) default NULL COMMENT 'Text name of the auctionhouse.',
  `minitems` int(11) default '0' COMMENT 'This is the minimum number of items you want to keep in the auction house. a 0 here will make it the same as the maximum.',
  `maxitems` int(11) default '0' COMMENT 'This is the number of items you want to keep in the auction house.',
  `mintime` int(11) default '8' COMMENT 'Sets the minimum number of hours for an auction.',
  `maxtime` int(11) default '24' COMMENT 'Sets the maximum number of hours for an auction.',
  `percentwhitetradegoods` int(11) default '27' COMMENT 'Sets the percentage of the White Trade Goods auction items',
  `percentgreentradegoods` int(11) default '12' COMMENT 'Sets the percentage of the Green Trade Goods auction items',
  `percentbluetradegoods` int(11) default '10' COMMENT 'Sets the percentage of the Blue Trade Goods auction items',
  `percentpurpletradegoods` int(11) default '1' COMMENT 'Sets the percentage of the Purple Trade Goods auction items',
  `percentwhiteitems` int(11) default '10' COMMENT 'Sets the percentage of the non trade White auction items',
  `percentgreenitems` int(11) default '30' COMMENT 'Sets the percentage of the non trade Green auction items',
  `percentblueitems` int(11) default '8' COMMENT 'Sets the percentage of the non trade Blue auction items',
  `percentpurpleitems` int(11) default '2' COMMENT 'Sets the percentage of the non trade Purple auction items',
  `minpricewhite` int(11) default '150' COMMENT 'Minimum price of White items (percentage).',
  `maxpricewhite` int(11) default '250' COMMENT 'Maximum price of White items (percentage).',
  `minpricegreen` int(11) default '800' COMMENT 'Minimum price of Green items (percentage).',
  `maxpricegreen` int(11) default '1400' COMMENT 'Maximum price of Green items (percentage).',
  `minpriceblue` int(11) default '1250' COMMENT 'Minimum price of Blue items (percentage).',
  `maxpriceblue` int(11) default '1750' COMMENT 'Maximum price of Blue items (percentage).',
  `minpricepurple` int(11) default '2250' COMMENT 'Minimum price of Purple items (percentage).',
  `maxpricepurple` int(11) default '4550' COMMENT 'Maximum price of Purple items (percentage).',
  `minbidpricewhite` int(11) default '70' COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `maxbidpricewhite` int(11) default '100' COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `minbidpricegreen` int(11) default '80' COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `maxbidpricegreen` int(11) default '100' COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `minbidpriceblue` int(11) default '75' COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `maxbidpriceblue` int(11) default '100' COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `minbidpricepurple` int(11) default '80' COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `maxbidpricepurple` int(11) default '100' COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 100 (Bid and buyout price the same)',
  `maxstackwhite` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackgreen` int(11) default '3' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackblue` int(11) default '2' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackpurple` int(11) default '1' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `buyerpricegrey` int(11) default '1' COMMENT 'Multiplier to vendorprice when buying grey items from auctionhouse',
  `buyerpricewhite` int(11) default '1' COMMENT 'Multiplier to vendorprice when buying white items from auctionhouse',
  `buyerpricegreen` int(11) default '5' COMMENT 'Multiplier to vendorprice when buying green items from auctionhouse',
  `buyerpriceblue` int(11) default '12' COMMENT 'Multiplier to vendorprice when buying blue items from auctionhouse',
  `buyerpricepurple` int(11) default '15' COMMENT 'Multiplier to vendorprice when buying purple items from auctionhouse',
  `buyerbiddinginterval` int(11) default '1' COMMENT 'Interval how frequently AHB bids on each AH. Time in minutes',
  `buyerbidsperinterval` int(11) default '1' COMMENT 'number of bids to put in per bidding interval',
  PRIMARY KEY  (`auctionhouse`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Data for table `auctionhousebot`
--
INSERT IGNORE INTO `auctionhousebot` (`auctionhouse`,`name`,`minitems`,`maxitems`,`mintime`,`maxtime`,`percentwhitetradegoods`,`percentgreentradegoods`,`percentbluetradegoods`,`percentpurpletradegoods`,`percentwhiteitems`,`percentgreenitems`,`percentblueitems`,`percentpurpleitems`,`minpricewhite`,`maxpricewhite`,`minpricegreen`,`maxpricegreen`,`minpriceblue`,`maxpriceblue`,`minpricepurple`,`maxpricepurple`,`minbidpricewhite`,`maxbidpricewhite`,`minbidpricegreen`,`maxbidpricegreen`,`minbidpriceblue`,`maxbidpriceblue`,`minbidpricepurple`,`maxbidpricepurple`,`maxstackwhite`,`maxstackgreen`,`maxstackblue`,`maxstackpurple`,`buyerpricegrey`,`buyerpricewhite`,`buyerpricegreen`,`buyerpriceblue`,`buyerpricepurple`,`buyerbiddinginterval`,`buyerbidsperinterval`) values
(2,'Alliance',0,0,8,24,27,12,10,1,10,30,8,2,150,250,800,1400,1250,1750,2250,4550,70,100,80,100,75,100,80,100,0,3,2,1,1,1,5,12,15,1,1),
(6,'Horde',0,0,8,24,27,12,10,1,10,30,8,2,150,250,800,1400,1250,1750,2250,4550,70,100,80,100,75,100,80,100,0,3,2,1,1,1,5,12,15,1,1),
(7,'Neutral',0,0,8,24,27,12,10,1,10,30,8,2,150,250,800,1400,1250,1750,2250,4550,70,100,80,100,75,100,80,100,0,3,2,1,1,1,5,12,15,1,1);
