DROP TABLE IF EXISTS `script_texts`;
CREATE TABLE `script_texts` (
`ScriptName` varchar(255) NOT NULL default '',
`Id` int(11) unsigned NOT NULL default '0',
`Sound` int(11) unsigned NOT NULL default '0',
`Type` int(11) unsigned NOT NULL default '0',
`Language` int(11) unsigned NOT NULL default '0',
`Text` varchar(255) NOT NULL default '',
`Comment` varchar(255) NOT NULL default '',
PRIMARY KEY  (`ScriptName`,`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Texts';


DROP TABLE IF EXISTS `script_localized_texts`;
CREATE TABLE `script_localized_texts` (
`id` int(11) unsigned NOT NULL auto_increment COMMENT 'Identifier',
`locale_1` varchar(255) NOT NULL default '',
`locale_2` varchar(255) NOT NULL default '',
`locale_3` varchar(255) NOT NULL default '',
`locale_4` varchar(255) NOT NULL default '',
`locale_5` varchar(255) NOT NULL default '',
`locale_6` varchar(255) NOT NULL default '',
`locale_7` varchar(255) NOT NULL default '',
`locale_8` varchar(255) NOT NULL default '',
`comment` varchar(255) NOT NULL default '' COMMENT 'Text Comment',
PRIMARY KEY  (`id`)            
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Localized Script Text';


DROP TABLE IF EXISTS `eventai_texts`;
CREATE TABLE `eventai_texts` AS SELECT `id`, `locale_0` AS `text`, `comment` FROM `localized_texts`;
TRUNCATE TABLE `localized_texts`;
DROP TABLE IF EXISTS `eventai_localized_texts`;
ALTER TABLE `localized_texts` RENAME TO `eventai_localized_texts`;
ALTER TABLE `eventai_localized_texts` DROP COLUMN `locale_0`;