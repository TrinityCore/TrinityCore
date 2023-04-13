/*
Navicat MySQL Data Transfer

Source Server         : DoWork
Source Server Version : 50726
Source Host           : localhost:3306
Source Database       : _az_world_1.0

Target Server Type    : MYSQL
Target Server Version : 50726
File Encoding         : 65001

Date: 2020-10-25 17:13:32
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for _真实假人控制表
-- ----------------------------
DROP TABLE IF EXISTS `_真实假人控制表`;
CREATE TABLE `_真实假人控制表` (
  `序号` int(11) NOT NULL COMMENT '序号(不能改动)',
  `功能名称` varchar(255) CHARACTER SET utf8 NOT NULL COMMENT '功能的名称',
  `功能值` varchar(255) CHARACTER SET utf8 NOT NULL,
  `备注` varchar(255) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`序号`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk;

-- ----------------------------
-- Records of _真实假人控制表
-- ----------------------------
INSERT INTO `_真实假人控制表` VALUES ('1001', '真实假人开关', '0', '备注: 1 (开启) 0 (关闭)');
INSERT INTO `_真实假人控制表` VALUES ('1002', '真实假人最大数量', '128', '备注: 数量上限 默认128 前提是角色表里有');
INSERT INTO `_真实假人控制表` VALUES ('1003', '真实假人上线间隔', '15#30', '备注: 以秒为单位 120#300 表示 在120秒与300秒之间随机 默认120#300 每次上线随机都不一样 以此增加真实性');
INSERT INTO `_真实假人控制表` VALUES ('1004', '真实假人是否开启消息在线代理回复', '0', '备注: 1 (开启) 0 (关闭) 开启后在线GM会收到玩家的消息 并且代替真实假人回复 显示的是真实假人回复 若不开启则按 [_真实假人随机消息]');
INSERT INTO `_真实假人控制表` VALUES ('1005', '真实假人自定义guid加载最大编号', '0', '备注: 默认100 只会加载角色表 guid<=功能值 以内的角色假人 作用是GM可以自行建立大量自定义角色 0=系统自动顺序加载');
INSERT INTO `_真实假人控制表` VALUES ('1006', '真实假人移动间隔', '15#30', '备注: 以秒为单位 60#180 表示 在60秒与180秒之间随机 默认60#180 每个假人随机都不一样 移动位置参考 _真实假人移动坐标表');
