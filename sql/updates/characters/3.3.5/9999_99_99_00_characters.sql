DROP TABLE IF EXISTS `auctionbidders`;
CREATE TABLE `auctionbidders` (
	`id` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`bidder` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`id`, `bidder`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB;
