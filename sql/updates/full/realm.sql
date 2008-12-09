ALTER TABLE account
    CHANGE COLUMN tbc expansion tinyint(3) unsigned NOT NULL default '0';
	
ALTER TABLE `account`
  CHANGE COLUMN  `email` `email` text;	