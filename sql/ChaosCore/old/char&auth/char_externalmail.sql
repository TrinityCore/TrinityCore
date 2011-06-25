DROP TABLE IF EXISTS `mail_external`;
CREATE TABLE `mail_external` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `receiver` int(10) unsigned NOT NULL,
  `subject` varchar(200) default 'Support Message',
  `message` varchar(200) default '',
  `money` int(10) unsigned NOT NULL default '0',
  `item` int(10) unsigned NOT NULL default '0',
  `item_count` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;