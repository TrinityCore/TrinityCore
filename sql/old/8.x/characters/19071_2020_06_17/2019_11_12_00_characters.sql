--
-- Table structure for table `item_instance_azerite`
--
DROP TABLE IF EXISTS `item_instance_azerite`;
CREATE TABLE `item_instance_azerite` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `xp` bigint(20) unsigned NOT NULL DEFAULT '0',
  `level` int(10) unsigned NOT NULL DEFAULT '1',
  `knowledgeLevel` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
