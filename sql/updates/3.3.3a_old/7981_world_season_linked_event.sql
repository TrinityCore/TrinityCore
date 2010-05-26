DROP TABLE IF EXISTS `season_linked_event`;
CREATE TABLE `season_linked_event` (
 `season` int(3) UNSIGNED NOT NULL default '0',
 `event` int(8) UNSIGNED NOT NULL default '0',
 PRIMARY KEY (`season`),
 UNIQUE (`season`,`event`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
