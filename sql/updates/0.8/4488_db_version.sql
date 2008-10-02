DROP TABLE IF EXISTS `db_version`;
CREATE TABLE `db_version` (
  `version` varchar(120)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Used DB version notes';

INSERT INTO `db_version` VALUES ( 'unknown world database.' );
