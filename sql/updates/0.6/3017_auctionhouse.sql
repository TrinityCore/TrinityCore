ALTER TABLE `auctionhouse` 
  MODIFY COLUMN `auctioneerguid` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `itemguid` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `itemowner` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `buyguid` int(11) unsigned NOT NULL default '0';
