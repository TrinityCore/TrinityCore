-- ----------------------------
-- Table structure for bg_template
-- ----------------------------
DROP TABLE IF EXISTS `battleground_template`;
CREATE TABLE `battleground_template` (
  `id` int(11) unsigned NOT NULL,
  `MaxPlayersPerTeam` int(11) NOT NULL,
  `MinLvl` int(11) NOT NULL,
  `MaxLvl` int(11) NOT NULL,
  `AllianceStartLoc` int(11) unsigned NOT NULL,
  `AllianceStartO` float NOT NULL,
  `HordeStartLoc` int(11) unsigned NOT NULL,
  `HordeStartO` float NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------

INSERT INTO `battleground_template` VALUES ('1', '0', '0', '0',  '611', '2.72532',  '610','2.27452');
INSERT INTO `battleground_template` VALUES ('2', '0', '0', '0',  '769', '3.14159',  '770','3.14159');
INSERT INTO `battleground_template` VALUES ('3', '0', '0', '0',  '890', '3.40156',  '889','0.263892');
INSERT INTO `battleground_template` VALUES ('7', '0', '0', '0', '1103', '3.40156', '1104','0.263892');
