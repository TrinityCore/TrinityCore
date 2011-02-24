-- ----------------------------
-- Table structure for `config`
-- ----------------------------
DROP TABLE IF EXISTS `config`;
CREATE TABLE `config` (
  `name` varchar(50) NOT NULL COMMENT 'Config parameter name.',
  `config_int` int(10) DEFAULT NULL,
  `config_float` float DEFAULT NULL,
  `config_string` varchar(50) DEFAULT NULL,
  `help` varchar(255) DEFAULT '',
  PRIMARY KEY (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
