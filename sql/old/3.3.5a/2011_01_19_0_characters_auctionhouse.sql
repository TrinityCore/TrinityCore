ALTER TABLE `auctionhouse`
CHANGE `id` `id` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `auctioneerguid` `auctioneerguid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `itemguid` `itemguid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `itemowner` `itemowner` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `buyoutprice` `buyoutprice` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `time` `time` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `buyguid` `buyguid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `lastbid` `lastbid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `startbid` `startbid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `deposit` `deposit` INT(10) UNSIGNED DEFAULT '0' NOT NULL;