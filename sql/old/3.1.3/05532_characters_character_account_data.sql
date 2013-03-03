-- mangos rev 8433
-- ALTER TABLE character_db_version CHANGE COLUMN required_8409_01_characters_guild required_8433_01_characters_character_account_data bit;

DROP TABLE IF EXISTS `character_account_data`;
CREATE TABLE `character_account_data` (
  `guid` int(11) unsigned NOT NULL default '0',
  `type` int(11) unsigned NOT NULL default '0',
  `time` bigint(11) unsigned NOT NULL default '0',
  `data` longtext NOT NULL,
  PRIMARY KEY  (`guid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO character_account_data
SELECT c.guid as guid, a.type as type, a.time as time, a.data as data
FROM characters c LEFT JOIN account_data a ON c.account = a.account WHERE a.type IN (1, 3, 5, 6, 7);

DELETE FROM account_data WHERE type IN (1, 3, 5, 6, 7);
