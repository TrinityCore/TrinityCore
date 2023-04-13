/*
Navicat MySQL Data Transfer

Source Server         : DoWork
Source Server Version : 50726
Source Host           : localhost:3306
Source Database       : _az_world_1.0

Target Server Type    : MYSQL
Target Server Version : 50726
File Encoding         : 65001

Date: 2020-10-25 17:13:57
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for _真实假人移动坐标表
-- ----------------------------
DROP TABLE IF EXISTS `_真实假人移动坐标表`;
CREATE TABLE `_真实假人移动坐标表` (
  `序号` int(11) NOT NULL DEFAULT '0',
  `地图编号` int(11) NOT NULL DEFAULT '0',
  `坐标X` float NOT NULL DEFAULT '0',
  `坐标Y` float NOT NULL DEFAULT '0',
  `坐标Z` float NOT NULL DEFAULT '0',
  `方位O` float NOT NULL DEFAULT '0',
  `备注` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`序号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of _真实假人移动坐标表
-- ----------------------------
INSERT INTO `_真实假人移动坐标表` VALUES ('1', '530', '-254.33', '951.58', '84.37', '4.92', '');
INSERT INTO `_真实假人移动坐标表` VALUES ('2', '530', '-223.46', '956.54', '84.35', '4.78', '');
INSERT INTO `_真实假人移动坐标表` VALUES ('3', '530', '-220.55', '907.52', '84.37', '2.56', '');
