CREATE TABLE `world_visible_distance` (
  `type` tinyint(3) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL DEFAULT '0',
  `distance` float NOT NULL DEFAULT '0',
  `comment` varchar(50) NOT NULL DEFAULT '',
  PRIMARY KEY (`type`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;