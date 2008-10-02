DROP TABLE IF EXISTS `db_version`;
CREATE TABLE `db_version` (
`version` varchar(255) NOT NULL default '' COMMENT 'Database version string'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;