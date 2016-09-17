DROP TABLE IF EXISTS `location_scripts`;
CREATE TABLE `location_scripts`
(
`zone_entry` INT(11) NOT NULL DEFAULT '0',
`ScriptName` CHAR(64) NOT NULL DEFAULT '',
UNIQUE KEY `zone_entry` (`zone_entry`, `ScriptName`)) ENGINE=INNODB DEFAULT CHARSET=utf8;