/*
Navicat MySQL Data Transfer

Source Server         : localhost_3312
Source Server Version : 50505
Source Host           : localhost:3310
Source Database       : world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2016-07-07 06:32:37
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for creature
-- ----------------------------
DROP TABLE IF EXISTS `creature`;
CREATE TABLE `creature` (
  `guid` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Global Unique Identifier',
  `id` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Creature Identifier',
  `map` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `zoneId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Zone Identifier',
  `areaId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Area Identifier',
  `spawnMask` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `phaseMask` int(10) unsigned NOT NULL DEFAULT '1',
  `modelid` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `equipment_id` tinyint(3) NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  `spawntimesecs` int(10) unsigned NOT NULL DEFAULT '120',
  `spawndist` float NOT NULL DEFAULT '0',
  `currentwaypoint` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `curhealth` int(10) unsigned NOT NULL DEFAULT '1',
  `curmana` int(10) unsigned NOT NULL DEFAULT '0',
  `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `npcflag` int(10) unsigned NOT NULL DEFAULT '0',
  `unit_flags` int(10) unsigned NOT NULL DEFAULT '0',
  `dynamicflags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) DEFAULT '0',
  PRIMARY KEY (`guid`),
  KEY `idx_map` (`map`),
  KEY `idx_id` (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=15122192 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature System';

-- ----------------------------
-- Records of creature
-- ----------------------------

INSERT INTO `creature` VALUES ('15122156', '190010', '0', '0', '0', '1', '1', '0', '0', '-8829.8', '645.669', '94.5523', '4.6554', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122157', '190011', '0', '0', '0', '1', '1', '0', '0', '-8826.56', '647.301', '94.5076', '4.69467', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122174', '99990', '0', '0', '0', '1', '1', '0', '0', '-8837.74', '605.145', '94.2286', '2.45629', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122159', '13', '0', '0', '0', '1', '1', '0', '0', '-8806.16', '622.143', '94.8984', '2.32277', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122175', '99990', '1', '0', '0', '1', '1', '0', '0', '1582.41', '-4412.54', '7.87135', '2.39777', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122176', '13', '1', '0', '0', '1', '1', '0', '0', '1585.6', '-4409.83', '7.52369', '2.21712', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122177', '190011', '1', '0', '0', '1', '1', '0', '0', '1588.45', '-4407.94', '7.18797', '2.05219', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122178', '190010', '1', '0', '0', '1', '1', '0', '0', '1591.65', '-4406.32', '6.92044', '2.03883', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122184', '190051', '0', '0', '0', '1', '1', '0', '0', '-8850.5', '634.753', '98.22', '0.146285', '300', '0', '0', '1220', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122187', '190051', '1', '0', '0', '1', '1', '0', '0', '1576.8', '-4399.3', '6.8643', '5.23305', '300', '0', '0', '1220', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122190', '190052', '0', '0', '0', '1', '1', '0', '0', '-8848.2', '631.48', '95.1701', '0.369525', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('15122191', '190052', '1', '0', '0', '1', '1', '0', '0', '1584.17', '-4395.73', '5.94073', '5.02886', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');

