/*
Navicat MySQL Data Transfer

Source Server         : QuardCore_548
Source Server Version : 50525
Source Host           : localhost:3306
Source Database       : world_505

Target Server Type    : MYSQL
Target Server Version : 50525
File Encoding         : 65001

Date: 2014-11-03 21:56:34
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for gameobject_loot_currency
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_loot_currency`;
CREATE TABLE `gameobject_loot_currency` (
  `Gameobject_id` mediumint(8) unsigned NOT NULL,
  `CurrencyId1` smallint(5) unsigned DEFAULT '0',
  `CurrencyId2` smallint(5) unsigned DEFAULT '0',
  `CurrencyId3` smallint(5) unsigned DEFAULT '0',
  `CurrencyCount1` int(10) DEFAULT '0',
  `CurrencyCount2` int(10) DEFAULT '0',
  `CurrencyCount3` int(10) DEFAULT '0',
  PRIMARY KEY (`Gameobject_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of gameobject_loot_currency
-- ----------------------------
