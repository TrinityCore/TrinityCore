DROP TABLE IF EXISTS `quest_poi`;
CREATE TABLE `quest_poi` (
  `questId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `id` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `objIndex` int(10) NOT NULL DEFAULT '0',
  `mapid` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `WorldMapAreaId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `FloorId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `unk3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `unk4` int(10) UNSIGNED NOT NULL DEFAULT '0',
  KEY `questId` (`questId`,`id`),
  KEY `id` (`id`,`questId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;
