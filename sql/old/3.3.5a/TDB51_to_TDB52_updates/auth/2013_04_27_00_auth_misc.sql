DROP TABLE IF EXISTS `autobroadcast`;
CREATE TABLE `autobroadcast` (
  `realmid` int(10) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) DEFAULT 1,
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`, `realmid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
