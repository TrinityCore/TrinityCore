SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `uncompletable`;
CREATE TABLE `uncompletable` (
  `sourceType` int(10) unsigned NOT NULL,
  `id` int(10) unsigned NOT NULL,
  `comment` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  PRIMARY KEY (`sourceType`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
