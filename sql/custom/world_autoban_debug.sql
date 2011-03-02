SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `autoban_debug`
-- ----------------------------
DROP TABLE IF EXISTS `autoban_debug`;
CREATE TABLE `autoban_debug` (
  `id` int(11) NOT NULL,
  `realm` int(11) NOT NULL,
  `bandate` bigint(40) NOT NULL,
  `bannedby` varchar(255) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `mob_guid` int(10) NOT NULL,
  `mob_x` float DEFAULT NULL,
  `mob_y` float DEFAULT NULL,
  `mob_z` float DEFAULT NULL,
  `mapId` int(10) DEFAULT NULL,
  `x` float DEFAULT NULL,
  `y` float DEFAULT NULL,
  `z` float DEFAULT NULL,
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
