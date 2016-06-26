/*
Navicat MySQL Data Transfer

Source Server         : localhost_3312
Source Server Version : 50505
Source Host           : localhost:3310
Source Database       : login

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2016-06-26 11:46:15
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for chatsystem_account
-- ----------------------------
DROP TABLE IF EXISTS `chatsystem_account`;
CREATE TABLE `chatsystem_account` (
  `account_id` int(10) unsigned NOT NULL COMMENT 'Account ID',
  `language` varchar(32) NOT NULL DEFAULT 'EN' COMMENT 'LANGUAGE',
  `chat_global` tinyint(1) unsigned NOT NULL DEFAULT '1' COMMENT 'CHAT GLOBAL',
  `chat_pvp` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVP',
  `chat_pve` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVE',
  PRIMARY KEY (`account_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for chatsystem_character
-- ----------------------------
DROP TABLE IF EXISTS `chatsystem_character`;
CREATE TABLE `chatsystem_character` (
  `character_id` int(10) unsigned NOT NULL COMMENT 'Character ID (GUIDLOW)',
  `language` varchar(32) NOT NULL DEFAULT 'EN' COMMENT 'LANGUAGE',
  `chat_global` tinyint(1) unsigned NOT NULL DEFAULT '1' COMMENT 'CHAT GLOBAL',
  `chat_pvp` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVP',
  `chat_pve` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVE',
  PRIMARY KEY (`character_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of chatsystem_character
-- ----------------------------
