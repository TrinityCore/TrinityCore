ALTER TABLE character_db_version CHANGE COLUMN required_2008_12_22_02_characters_character_pet required_2008_12_22_05_characters_account_data bit;

CREATE TABLE `account_data` (
  `account` int(11) unsigned NOT NULL default '0',
  `type` int(11) unsigned NOT NULL default '0',
  `time` bigint(11) unsigned NOT NULL default '0',
  `data` longtext NOT NULL,
  PRIMARY KEY  (`account`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
