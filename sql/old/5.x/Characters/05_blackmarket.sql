/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50616
Source Host           : localhost:3306
Source Database       : 548j_char

Target Server Type    : MYSQL
Target Server Version : 50616
File Encoding         : 65001

Date: 2014-09-16 00:06:31
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for blackmarket
-- ----------------------------
DROP TABLE IF EXISTS `blackmarket`;
CREATE TABLE `blackmarket` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Identifier',
  `templateId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Reference to world.blackmarket_template',
  `startTime` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Start time of the bid',
  `bid` bigint(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Amount of the actual bid',
  `bidder` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Player guid (highest bid)',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of blackmarket
-- ----------------------------
