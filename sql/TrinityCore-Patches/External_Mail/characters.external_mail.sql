CREATE TABLE `mail_external` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `receiver` bigint(20) unsigned NOT NULL,
  `subject` varchar(200) default 'Support Message',
  `message` varchar(500) default 'Support Message',
  `money` bigint(20) unsigned NOT NULL default '0',
  `item` bigint(20) unsigned NOT NULL default '0',
  `item_count` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=7525 DEFAULT CHARSET=utf8;