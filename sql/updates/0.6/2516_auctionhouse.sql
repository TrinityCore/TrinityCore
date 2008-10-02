DELETE FROM `auctionhouse`;
ALTER TABLE `auctionhouse` 
  DROP `id`,
  ADD `id` bigint(20) unsigned NOT NULL default '0' FIRST,
  ADD `location` tinyint(3) unsigned NOT NULL default '3';
