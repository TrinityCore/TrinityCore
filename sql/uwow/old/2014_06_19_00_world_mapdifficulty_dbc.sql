/*
MySQL Data Transfer
Source Host: localhost
Source Database: 505_world_542
Target Host: localhost
Target Database: 505_world_542
Date: 19.06.2014 13:13:47
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for mapdifficulty_dbc
-- ----------------------------
DROP TABLE IF EXISTS `mapdifficulty_dbc`;
CREATE TABLE `mapdifficulty_dbc` (
  `m_id` int(11) NOT NULL DEFAULT '0',
  `m_mapId` int(11) NOT NULL DEFAULT '0',
  `m_difficulty` int(11) NOT NULL DEFAULT '0',
  `m_resetTime` int(11) NOT NULL DEFAULT '0',
  `m_maxPlayers` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`m_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `mapdifficulty_dbc` VALUES ('1', '0', '0', '0', '0');
INSERT INTO `mapdifficulty_dbc` VALUES ('843', '169', '3', '604800', '10');
INSERT INTO `mapdifficulty_dbc` VALUES ('845', '637', '1', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('846', '637', '2', '86400', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('848', '999', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('847', '1000', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('849', '1005', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('850', '1005', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('857', '1030', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('858', '1030', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('859', '1031', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('860', '1035', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('861', '1048', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('862', '1050', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('863', '1050', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('864', '1051', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('865', '1095', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('866', '1095', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('867', '1099', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('868', '1099', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('869', '1102', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('870', '1103', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('871', '1104', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('872', '1112', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('873', '1122', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('874', '1123', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('875', '1124', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('876', '1125', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('877', '1126', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('878', '1127', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('879', '1130', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('880', '1130', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('881', '1131', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('882', '1131', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('883', '1135', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('884', '1144', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('885', '1144', '11', '0', '3');
INSERT INTO `mapdifficulty_dbc` VALUES ('886', '1148', '12', '0', '5');
INSERT INTO `mapdifficulty_dbc` VALUES ('887', '1148', '1', '0', '5');
