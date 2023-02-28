/*
Navicat MySQL Data Transfer

Source Server         : TrinityCore-master
Source Server Version : 80011
Source Host           : localhost:3306
Source Database       : tc-world

Target Server Type    : MYSQL
Target Server Version : 80011
File Encoding         : 65001

Date: 2023-02-28 17:19:52
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `game_event`
-- ----------------------------
-- DROP TABLE IF EXISTS `game_event`;
CREATE TABLE `game_event` (
  `eventEntry` tinyint(3) unsigned NOT NULL COMMENT 'Entry of the game event',
  `start_time` timestamp NULL DEFAULT NULL COMMENT 'Absolute start date, the event will never start before',
  `end_time` timestamp NULL DEFAULT NULL COMMENT 'Absolute end date, the event will never start after',
  `occurence` bigint(20) unsigned NOT NULL DEFAULT '5184000' COMMENT 'Delay in minutes between occurences of the event',
  `length` bigint(20) unsigned NOT NULL DEFAULT '2592000' COMMENT 'Length in minutes of the event',
  `holiday` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Client side holiday id',
  `holidayStage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT 'Description of the event displayed in console',
  `description_CN` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT '制台控中显示的事件描述',
  `world_event` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '0 if normal event, 1 if world event',
  `announce` tinyint(3) unsigned DEFAULT '2' COMMENT '0 dont announce, 1 announce, 2 value from config',
  PRIMARY KEY (`eventEntry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of game_event
-- ----------------------------
INSERT INTO `game_event` VALUES ('1', '2017-06-21 07:01:00', '2020-12-31 13:00:00', '525600', '20160', '341', '1', 'Midsummer Fire Festival', '中秋火焰节', '0', '2');
INSERT INTO `game_event` VALUES ('2', '2016-12-15 14:00:00', '2020-12-31 13:00:00', '525600', '25920', '141', '1', 'Winter Veil', '冬幕节', '0', '2');
INSERT INTO `game_event` VALUES ('3', '2016-11-06 08:01:00', '2020-12-31 12:00:00', '43200', '10078', '479', '2', 'Darkmoon Faire', '暗月马戏团', '0', '2');
INSERT INTO `game_event` VALUES ('6', '2016-12-31 14:00:00', '2020-12-31 13:00:00', '525600', '1440', '0', '0', 'New Year\'s Eve', '除夕', '0', '2');
INSERT INTO `game_event` VALUES ('7', '2017-01-21 08:01:00', '2020-12-31 13:00:00', '525600', '20160', '327', '1', 'Lunar Festival', '春节', '0', '2');
INSERT INTO `game_event` VALUES ('8', '2017-02-07 08:01:00', '2020-12-31 13:00:00', '525600', '20160', '423', '1', 'Love is in the Air', '情人节', '0', '2');
INSERT INTO `game_event` VALUES ('9', '2017-03-17 08:01:00', '2020-12-31 13:00:00', '524160', '10080', '181', '1', 'Noblegarden', '贵族花园', '0', '2');
INSERT INTO `game_event` VALUES ('10', '2017-05-01 07:01:00', '2020-12-31 13:00:00', '525600', '10080', '201', '1', 'Children\'s Week ', '儿童节', '0', '2');
INSERT INTO `game_event` VALUES ('11', '2017-09-29 07:01:00', '2020-12-31 13:00:00', '525600', '10080', '321', '1', 'Harvest Festival', '感恩节', '0', '2');
INSERT INTO `game_event` VALUES ('12', '2016-10-18 08:00:00', '2020-12-31 13:00:00', '525600', '20160', '324', '1', 'Hallow\'s End', '万圣节', '0', '2');
INSERT INTO `game_event` VALUES ('13', null, null, '525600', '1', '0', '0', 'Elemental Invasions', '元素入侵', '0', '2');
INSERT INTO `game_event` VALUES ('14', '2016-10-29 07:00:00', '2020-12-31 13:00:00', '10080', '1440', '0', '0', 'Stranglethorn Fishing Extravaganza Announce', '荆棘谷钓鱼大赛公告', '0', '2');
INSERT INTO `game_event` VALUES ('15', '2016-10-30 22:00:00', '2020-12-31 13:00:00', '10080', '120', '301', '0', 'Stranglethorn Fishing Extravaganza Fishing Pools', '荆棘谷钓鱼大赛渔点', '0', '2');
INSERT INTO `game_event` VALUES ('16', '2016-10-29 10:00:00', '2020-12-31 13:00:00', '180', '120', '0', '0', 'Gurubashi Arena Booty Run', '古拉巴什竞技场战利品争夺战', '0', '2');
INSERT INTO `game_event` VALUES ('17', null, null, '525600', '1', '0', '0', 'Scourge Invasion', '天灾入侵', '0', '2');
INSERT INTO `game_event` VALUES ('18', '2016-11-25 08:01:00', '2020-12-31 13:00:00', '60480', '5760', '283', '1', 'Call to Arms: Alterac Valley!', '战斗的召唤:奥特兰克山谷 ', '0', '2');
INSERT INTO `game_event` VALUES ('19', '2016-12-02 08:01:00', '2020-12-31 13:00:00', '60480', '5760', '284', '1', 'Call to Arms: Warsong Gulch!', '战斗的召唤:战歌峡谷', '0', '2');
INSERT INTO `game_event` VALUES ('20', '2016-11-11 08:01:00', '2020-12-31 13:00:00', '60480', '5760', '285', '1', 'Call to Arms: Arathi Basin!', '战斗的召唤:阿拉希盆地', '0', '2');
INSERT INTO `game_event` VALUES ('21', '2016-11-18 08:01:00', '2020-12-31 13:00:00', '60480', '5760', '353', '1', 'Call to Arms: Eye of the Storm!', '战斗的召唤:风暴之眼', '0', '2');
INSERT INTO `game_event` VALUES ('22', null, null, '525600', '1', '0', '0', 'AQ War Effort', '安其拉战争准备', '0', '2');
INSERT INTO `game_event` VALUES ('23', '2016-12-01 08:01:00', '2020-12-31 13:00:00', '43200', '4320', '374', '1', 'Darkmoon Faire Building', '暗月马戏团建造', '0', '2');
INSERT INTO `game_event` VALUES ('24', '2017-09-20 07:01:00', '2020-12-31 13:00:00', '525600', '21600', '372', '2', 'Brewfest', '美酒节', '0', '2');
INSERT INTO `game_event` VALUES ('25', '2016-10-29 04:00:00', '2020-12-31 13:00:00', '1440', '720', '0', '0', 'Nights', '夜\r\n\r\n夜', '0', '2');
INSERT INTO `game_event` VALUES ('26', '2017-11-21 08:01:00', '2020-12-31 13:00:00', '525600', '10020', '404', '1', 'Pilgrim\'s Bounty', '感恩节', '0', '2');
INSERT INTO `game_event` VALUES ('27', '2008-03-24 13:00:00', '2020-12-31 13:00:00', '86400', '21600', '0', '0', 'Edge of Madness, Gri\'lek', '疯狂边缘,格里雷克', '0', '2');
INSERT INTO `game_event` VALUES ('28', '2008-04-07 13:00:00', '2020-12-31 13:00:00', '86400', '21600', '0', '0', 'Edge of Madness, Hazza\'rah', '疯狂边缘,哈扎拉尔', '0', '2');
INSERT INTO `game_event` VALUES ('29', '2008-04-21 13:00:00', '2020-12-31 13:00:00', '86400', '21600', '0', '0', 'Edge of Madness, Renataki', '疯狂边缘,雷纳塔基', '0', '2');
INSERT INTO `game_event` VALUES ('30', '2008-05-05 13:00:00', '2020-12-31 13:00:00', '86400', '21600', '0', '0', 'Edge of Madness, Wushoolay', '疯狂边缘,乌苏雷', '0', '2');
INSERT INTO `game_event` VALUES ('31', null, null, '5184000', '2592000', '0', '0', 'Arena Tournament', '竞技场锦标赛', '0', '2');
INSERT INTO `game_event` VALUES ('32', '2014-09-19 06:00:01', '2020-01-01 15:00:00', '10080', '5', '0', '0', 'L70ETC Concert', '70级牛头人音乐会', '0', '2');
INSERT INTO `game_event` VALUES ('33', '2011-03-22 07:10:00', '2020-03-22 07:00:00', '30', '5', '0', '0', 'Dalaran: Minigob', '达拉然:米尼格布·魔爆', '0', '2');
INSERT INTO `game_event` VALUES ('34', '2016-10-01 07:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month October', '十月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('35', '2016-11-01 08:01:00', '2020-12-31 13:00:00', '525600', '43200', '0', '0', 'Brew of the Month November', '十一月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('36', '2016-12-01 08:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month December', '十二月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('37', '2017-01-01 08:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month January', '一月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('38', '2017-02-01 08:01:00', '2020-12-31 13:00:00', '525600', '40320', '0', '0', 'Brew of the Month February', '二月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('39', '2017-03-01 08:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month March', '三月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('40', '2017-04-01 07:01:00', '2020-12-31 13:00:00', '525600', '43200', '0', '0', 'Brew of the Month April', '四月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('41', '2017-05-01 07:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month May', '五月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('42', '2017-06-01 07:01:00', '2020-12-31 13:00:00', '525600', '43200', '0', '0', 'Brew of the Month June', '六月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('43', '2017-07-01 07:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month July', '七月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('44', '2017-08-01 07:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month August', '八月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('45', '2017-09-01 07:01:00', '2020-12-31 13:00:00', '525600', '44640', '0', '0', 'Brew of the Month September', '九月啤酒节', '0', '2');
INSERT INTO `game_event` VALUES ('46', '2010-09-08 04:50:00', '2030-10-10 09:00:00', '180', '16', '0', '0', 'L70 ETC Shattrath Announce', '70级牛头人音乐会公告', '0', '2');
INSERT INTO `game_event` VALUES ('47', '2010-09-08 05:00:00', '2030-10-10 09:00:00', '180', '6', '0', '0', 'L70 ETC Shattrath', '70级牛头人沙塔斯音乐会', '0', '2');
INSERT INTO `game_event` VALUES ('48', null, null, '5184000', '2592000', '0', '0', 'Wintergrasp Alliance Defence', '冬拥湖联盟防御', '5', '2');
INSERT INTO `game_event` VALUES ('49', null, null, '5184000', '2592000', '0', '0', 'Wintergrasp Horde Defence', '冬拥湖部落防御', '5', '2');
INSERT INTO `game_event` VALUES ('50', '2017-09-19 07:01:00', '2020-12-31 12:00:00', '525600', '1440', '398', '1', 'Pirates\' Day', '海盗日', '0', '2');
INSERT INTO `game_event` VALUES ('51', '2016-11-01 08:01:00', '2020-12-31 13:00:00', '525600', '2820', '409', '1', 'Day of the Dead', '亡灵节', '0', '2');
INSERT INTO `game_event` VALUES ('52', '2010-12-25 13:00:00', '2020-12-31 13:00:00', '525600', '11700', '0', '0', 'Winter Veil: Gifts', '冬天爷爷的助手', '0', '2');
INSERT INTO `game_event` VALUES ('53', '2016-10-28 07:01:00', '2020-12-31 17:00:00', '60480', '6240', '400', '1', 'Call to Arms: Strand of the Ancients!', '战斗的召唤:远古海滩', '0', '2');
INSERT INTO `game_event` VALUES ('54', '2016-11-04 08:01:00', '2020-12-31 17:00:00', '60480', '6240', '420', '1', 'Call to Arms: Isle of Conquest!', '战斗的召唤:征服之岛', '0', '2');
INSERT INTO `game_event` VALUES ('55', null, null, '5184000', '2592000', '0', '0', 'Arena Season 3', '竞技场第3季\r\n竞技场第4季\r\n竞技场第5季\r\n竞技场第6季\r\n竞技场第7季\r\n竞技场第8季\r\n竞技场第3季', '0', '2');
INSERT INTO `game_event` VALUES ('56', null, null, '5184000', '2592000', '0', '0', 'Arena Season 4', '竞技场第4季', '0', '2');
INSERT INTO `game_event` VALUES ('57', null, null, '5184000', '2592000', '0', '0', 'Arena Season 5', '竞技场第5季\r\n竞技场第5季\r\n竞技场第5季', '0', '2');
INSERT INTO `game_event` VALUES ('58', null, null, '5184000', '2592000', '0', '0', 'Arena Season 6', '竞技场第6季', '0', '2');
INSERT INTO `game_event` VALUES ('59', null, null, '5184000', '2592000', '0', '0', 'Arena Season 7', '竞技场第7季', '0', '2');
INSERT INTO `game_event` VALUES ('60', null, null, '5184000', '2592000', '0', '0', 'Arena Season 8', '竞技场第8季', '0', '2');
INSERT INTO `game_event` VALUES ('61', '2010-09-07 07:00:00', '2010-10-10 07:00:00', '9999999', '47520', '0', '0', 'Zalazane\'s Fall', '札拉赞恩之死', '0', '2');
INSERT INTO `game_event` VALUES ('62', '2016-10-30 22:00:00', '2020-12-31 13:00:00', '10080', '180', '376', '1', 'Stranglethorn Fishing Extravaganza Turn-ins', '钓鱼机器人5000型', '0', '2');
INSERT INTO `game_event` VALUES ('63', '2016-10-29 20:00:00', '2020-12-31 13:00:00', '10080', '180', '0', '0', 'Kalu\'ak Fishing Derby Turn-ins', '卡鲁亚克钓鱼大赛公告', '0', '2');
INSERT INTO `game_event` VALUES ('64', '2016-10-29 21:00:00', '2020-12-31 13:00:00', '10080', '60', '424', '0', 'Kalu\'ak Fishing Derby Fishing Pools', '卡鲁亚克钓鱼大赛渔点', '0', '2');
INSERT INTO `game_event` VALUES ('65', '2008-01-02 22:55:00', '2020-12-31 13:00:00', '240', '15', '0', '0', 'Perry Gatner', '派瑞·加奈尔', '0', '2');
INSERT INTO `game_event` VALUES ('67', '2010-01-02 07:40:00', '2020-12-31 13:00:00', '60', '10', '0', '0', 'AT Event Trigger (Tirion Speech)', '事件触发:使者贝鲁斯', '0', '2');
INSERT INTO `game_event` VALUES ('68', '2010-01-02 07:55:00', '2020-12-31 13:00:00', '60', '10', '0', '0', 'AT Event Trigger (Horde Event)', '事件触发:部落事件', '0', '2');
INSERT INTO `game_event` VALUES ('69', '2010-01-02 07:10:00', '2020-12-31 13:00:00', '60', '10', '0', '0', 'AT Event Trigger (Alliance Event)', '事件触发:联盟事件', '0', '2');
INSERT INTO `game_event` VALUES ('70', '2013-11-18 07:01:00', '2013-12-02 06:59:00', '525600', '10080', '0', '0', 'WoW\'s 9th Anniversary', '魔兽九周年纪念日', '0', '2');
INSERT INTO `game_event` VALUES ('71', '2014-11-17 07:01:00', '2014-12-02 06:59:00', '525600', '10080', '0', '0', 'WoW\'s 10th Anniversary', '魔兽十周年纪念日', '0', '2');
INSERT INTO `game_event` VALUES ('72', '2010-07-04 16:00:00', '2020-07-04 16:00:00', '525600', '1440', '62', '0', 'Fireworks Spectacular', '烟花表演', '0', '2');
INSERT INTO `game_event` VALUES ('73', '2010-01-01 09:00:00', '2025-01-01 09:00:00', '60', '1', '0', '0', 'Hourly Bells', '时钟铃声', '0', '2');
INSERT INTO `game_event` VALUES ('76', '2018-01-01 15:00:00', '2020-01-01 16:00:00', '1440', '60', '0', '0', 'Children of Goldshire', '闪金镇儿童', '0', '2');
INSERT INTO `game_event` VALUES ('78', '2019-03-20 14:00:00', '2019-09-22 13:00:00', '525600', '262800', '0', '0', 'Summer seasonal fish', '夏季季节性鱼群', '0', '2');
INSERT INTO `game_event` VALUES ('79', '2018-10-28 20:00:00', '2021-01-01 02:00:00', '1440', '360', '0', '0', 'Diurnal fishing event', '白天钓鱼事件', '0', '2');
INSERT INTO `game_event` VALUES ('80', '2018-10-28 08:00:00', '2020-12-31 14:00:00', '1440', '360', '0', '0', 'Nocturnal fishing event', '夜间钓鱼事件', '0', '2');
INSERT INTO `game_event` VALUES ('81', '2016-10-29 04:00:00', '2021-01-01 04:05:00', '1440', '5', '0', '0', 'L70ETC Grim Guzzler', '70级音乐会黑铁狂欢者', '0', '2');
INSERT INTO `game_event` VALUES ('82', '2010-09-07 09:00:00', '2010-10-10 09:00:00', '9999999', '47520', '0', '0', 'Operation: Gnomeregan', '诺莫瑞根行动', '0', '2');
INSERT INTO `game_event` VALUES ('83', '2018-01-01 08:00:00', '2030-01-01 08:00:00', '60', '15', '0', '0', 'Warsong Hold Invasion', '战歌堡入侵', '0', '2');
INSERT INTO `game_event` VALUES ('84', '2018-01-01 08:20:00', '2030-01-01 08:00:00', '60', '10', '0', '0', 'AT ValKyr invasion', '瓦尔基尔入侵', '0', '2');
INSERT INTO `game_event` VALUES ('85', '2010-01-01 10:00:00', '2030-12-31 15:00:00', '60', '1', '0', '0', 'Honor Hold Hellfire', '荣耀堡地狱火', '0', '2');
