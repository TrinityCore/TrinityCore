ALTER TABLE `auctionhouse`
  ADD `item_template` int(11) unsigned NOT NULL default '0' AFTER `itemguid`;

UPDATE `auctionhouse`,`item_instance`
  SET `item_template` = SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',4),' ',-1)
  WHERE `auctionhouse`.`itemguid` = `item_instance`.`guid`;
