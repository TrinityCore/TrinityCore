ALTER TABLE `item_template` 
  CHANGE COLUMN `RandomProperty_1` `RandomProperty` int(30) unsigned NOT NULL default '0',
  CHANGE COLUMN `RandomProperty_2` `RandomSuffix`   int(30) unsigned NOT NULL default '0';
