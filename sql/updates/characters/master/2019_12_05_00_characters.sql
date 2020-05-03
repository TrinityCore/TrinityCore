ALTER TABLE `characters` ADD `numRespecs` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `resettalents_time`;

--
-- Table structure for table `item_instance_azerite_empowered`
--
DROP TABLE IF EXISTS `item_instance_azerite_empowered`;
CREATE TABLE `item_instance_azerite_empowered` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `azeritePowerId1` int(11) NOT NULL,
  `azeritePowerId2` int(11) NOT NULL,
  `azeritePowerId3` int(11) NOT NULL,
  `azeritePowerId4` int(11) NOT NULL,
  `azeritePowerId5` int(11) NOT NULL,
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
