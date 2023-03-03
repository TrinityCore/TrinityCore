ALTER TABLE `auctionhouse` ADD `auctionHouseId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `id`;
ALTER TABLE `auctionhouse` DROP `auctioneerguid`;

-- temporarily mark all auctions as coming from neutral AH (not goblin one) and expired
UPDATE `auctionhouse` SET `auctionHouseId`=1, `time`=UNIX_TIMESTAMP();

DROP TABLE IF EXISTS `auction_bidders`;
CREATE TABLE `auction_bidders` (
  `auctionId` int unsigned NOT NULL,
  `playerGuid` bigint unsigned NOT NULL,
  PRIMARY KEY (`auctionId`,`playerGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `auction_bidders` SELECT `id`, `buyguid` FROM `auctionhouse`;

DROP TABLE IF EXISTS `auction_items`;
CREATE TABLE `auction_items` (
  `auctionId` int unsigned NOT NULL,
  `itemGuid` bigint unsigned NOT NULL,
  PRIMARY KEY (`auctionId`,`itemGuid`),
  UNIQUE KEY `idx_itemGuid` (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_favorite_auctions`;
CREATE TABLE `character_favorite_auctions` (
  `guid` bigint(20) unsigned NOT NULL,
  `order` int(10) unsigned NOT NULL DEFAULT '0',
  `itemId` int(10) unsigned NOT NULL DEFAULT '0',
  `itemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `battlePetSpeciesId` int(10) unsigned NOT NULL DEFAULT '0',
  `suffixItemNameDescriptionId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`order`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `auction_items` SELECT `id`, `itemguid` FROM `auctionhouse`;

ALTER TABLE `auctionhouse` DROP INDEX `item_guid`;
ALTER TABLE `auctionhouse` DROP `itemguid`;
ALTER TABLE `auctionhouse` CHANGE `itemowner` `owner` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `auctionHouseId`;
ALTER TABLE `auctionhouse` CHANGE `buyguid` `bidder` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `owner`;
ALTER TABLE `auctionhouse` CHANGE `startbid` `minBid` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `bidder`;
ALTER TABLE `auctionhouse` CHANGE `buyoutprice` `buyoutOrUnitPrice` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `lastbid`;
ALTER TABLE `auctionhouse` MODIFY `deposit` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `buyoutOrUnitPrice`;
ALTER TABLE `auctionhouse` CHANGE `lastbid` `bidAmount` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `deposit`;
ALTER TABLE `auctionhouse` ADD `startTime` int(10) unsigned NOT NULL DEFAULT '0' AFTER `bidAmount`;
ALTER TABLE `auctionhouse` CHANGE `time` `endTime` int(10) unsigned NOT NULL DEFAULT '0' AFTER `startTime`;
