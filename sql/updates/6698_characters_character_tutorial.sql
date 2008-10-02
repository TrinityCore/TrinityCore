DROP TABLE IF EXISTS `character_tutorial`;
CREATE TABLE `character_tutorial` (
  `account` bigint(20) unsigned NOT NULL auto_increment COMMENT 'Account Identifier',
  `realmid` int(11) unsigned NOT NULL default '0' COMMENT 'Realm Identifier',
  `tut0` int(11) unsigned NOT NULL default '0',
  `tut1` int(11) unsigned NOT NULL default '0',
  `tut2` int(11) unsigned NOT NULL default '0',
  `tut3` int(11) unsigned NOT NULL default '0',
  `tut4` int(11) unsigned NOT NULL default '0',
  `tut5` int(11) unsigned NOT NULL default '0',
  `tut6` int(11) unsigned NOT NULL default '0',
  `tut7` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`account`,`realmid`),
  KEY acc_key (`account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';
