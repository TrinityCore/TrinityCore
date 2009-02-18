CREATE TABLE `version` (
    `core_version` varchar(120) default NULL COMMENT 'Core revision dumped at startup.',
    `db_version` varchar(120) default NULL COMMENT 'Version of world DB.',
    `script_version` varchar(120) default NULL COMMENT 'Version of scripts DB.'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Version Notes';
INSERT INTO version (core_version, db_version, script_version) VALUES ("",(SELECT version FROM db_version),(SELECT version FROM script_db_version));
DROP TABLE IF EXISTS db_version;
DROP TABLE IF EXISTS script_db_version;

