DROP TABLE IF EXISTS `quest_poi_points`;
CREATE TABLE `quest_poi_points` (
  `questId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `id` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `x` int(10) NOT NULL DEFAULT '0',
  `y` int(10) NOT NULL DEFAULT '0',
  KEY `questId_id` (`questId`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;
