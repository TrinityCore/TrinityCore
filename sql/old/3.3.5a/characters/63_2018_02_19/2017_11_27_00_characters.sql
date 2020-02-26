DROP TABLE IF EXISTS `auctionbidders`;
CREATE TABLE `auctionbidders` (
  `id` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `bidderguid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`, `bidderguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `auctionbidders` (`id`, `bidderguid`) 
SELECT DISTINCT `id`, `buyguid` FROM `auctionhouse` WHERE `buyguid` != 0;
