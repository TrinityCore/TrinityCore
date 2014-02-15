SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for character_morph
-- ----------------------------
CREATE TABLE `character_morph` (
`guid` int(11) NOT NULL DEFAULT '0',
`morph` int(11) DEFAULT NULL,
PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for character_scale
-- ----------------------------
CREATE TABLE `character_scale` (
`guid` int(11) NOT NULL,
`scale` float NOT NULL,
`comment` text,
PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;