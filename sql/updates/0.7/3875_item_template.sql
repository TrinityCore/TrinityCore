ALTER TABLE `item_template` 
  CHANGE COLUMN `Extra`   `RandomProperty_1` int(30) unsigned NOT NULL default '0',
  CHANGE COLUMN `unk_203` `RandomProperty_2` int(30) unsigned NOT NULL default '0';
