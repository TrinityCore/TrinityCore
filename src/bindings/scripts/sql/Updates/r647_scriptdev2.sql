DROP TABLE IF EXISTS `script_texts`;
CREATE TABLE `script_texts` (
`id` int(11) unsigned NOT NULL auto_increment COMMENT 'Identifier',
`sound` int(11) unsigned NOT NULL default '0',
`type` int(11) unsigned NOT NULL default '0',
`language` int(11) unsigned NOT NULL default '0',
`text` varchar(255) NOT NULL default '',
`comment` varchar(255) NOT NULL default '',
PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Texts';