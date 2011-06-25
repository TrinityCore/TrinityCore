CREATE TABLE IF NOT EXISTS `account_premium` (
  `id` int(11) NOT NULL default '0' COMMENT 'Account id',
  `setdate` bigint(40) NOT NULL default '0',
  `unsetdate` bigint(40) NOT NULL default '0',
  `premium_type` tinyint(4) unsigned NOT NULL default '1',
  `active` tinyint(4) NOT NULL default '1',
  PRIMARY KEY  (`id`,`setdate`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Premium Accounts';