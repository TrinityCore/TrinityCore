-- ----------------------------
-- Table structure for `character_multikill`
-- ----------------------------
DROP TABLE IF EXISTS `character_multikill`;
CREATE TABLE `character_multikill` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `count` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_multikill
-- ----------------------------
