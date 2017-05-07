/*
Navicat MySQL Data Transfer

Source Server         : localhost_3310
Source Server Version : 100122
Source Host           : localhost:3310
Source Database       : realmd

Target Server Type    : MYSQL
Target Server Version : 100122
File Encoding         : 65001

Date: 2017-05-07 12:04:53
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for versions
-- ----------------------------
DROP TABLE IF EXISTS `versions`;
CREATE TABLE `versions` (
  `Build` int(255) DEFAULT NULL,
  `MajorVersion` int(255) DEFAULT NULL,
  `MinorVersion` int(255) DEFAULT NULL,
  `BugfixVersion` int(255) DEFAULT NULL,
  `HotfixVersion` int(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of versions
-- ----------------------------
INSERT INTO `versions` VALUES ('12342', '12342', '12342', '12342', '12342');
SET FOREIGN_KEY_CHECKS=1;
