UPDATE `auctionhouse`
SET `time` = 0, `auctioneerguid` = 7;

ALTER TABLE `auctionhouse`
  CHANGE COLUMN `auctioneerguid`    `houseid`   TINYINT(3)  UNSIGNED NOT NULL DEFAULT '7' AFTER `id`;
