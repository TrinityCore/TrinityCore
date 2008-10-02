DROP TABLE IF EXISTS `db_version`;
DROP TABLE IF EXISTS `sd2_db_version`;
CREATE TABLE `sd2_db_version` (
`version` varchar(255) NOT NULL default '' COMMENT 'Database version string'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;