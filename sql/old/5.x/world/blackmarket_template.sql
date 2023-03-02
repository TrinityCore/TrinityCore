/*
Navicat MySQL Data Transfer

Source Server         : QuardCore_548
Source Server Version : 50525
Source Host           : localhost:3306
Source Database       : world_548

Target Server Type    : MYSQL
Target Server Version : 50525
File Encoding         : 65001

Date: 2014-11-03 21:57:20
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for blackmarket_template
-- ----------------------------
DROP TABLE IF EXISTS `blackmarket_template`;
CREATE TABLE `blackmarket_template` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Global Identifier',
  `itemEntry` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Entry of the item',
  `itemCount` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Number of copies selled',
  `seller` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Entry of the npc vendor',
  `startBid` bigint(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Price when added',
  `duration` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'The duration of the general bid',
  `chance` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Chance for this item to be displayed',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=264 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of blackmarket_template
-- ----------------------------
INSERT INTO `blackmarket_template` VALUES ('1', '32458', '1', '32216', '200000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('2', '13335', '1', '32216', '200000000', '172800', '21');
INSERT INTO `blackmarket_template` VALUES ('3', '71665', '1', '32216', '200000000', '172800', '23');
INSERT INTO `blackmarket_template` VALUES ('4', '69224', '1', '32216', '200000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('5', '35513', '1', '32216', '200000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('6', '44151', '1', '32216', '200000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('7', '44707', '1', '32216', '200000000', '172800', '25');
INSERT INTO `blackmarket_template` VALUES ('8', '63040', '1', '32216', '200000000', '172800', '20');
INSERT INTO `blackmarket_template` VALUES ('9', '77067', '1', '32216', '200000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('10', '49636', '1', '32216', '200000000', '172800', '23');
INSERT INTO `blackmarket_template` VALUES ('11', '63041', '1', '32216', '200000000', '172800', '21');
INSERT INTO `blackmarket_template` VALUES ('12', '63043', '1', '32216', '200000000', '172800', '21');
INSERT INTO `blackmarket_template` VALUES ('13', '43962', '1', '32216', '200000000', '172800', '23');
INSERT INTO `blackmarket_template` VALUES ('14', '50818', '1', '32216', '200000000', '172800', '20');
INSERT INTO `blackmarket_template` VALUES ('15', '32768', '1', '32216', '200000000', '172800', '20');
INSERT INTO `blackmarket_template` VALUES ('16', '45802', '1', '32216', '200000000', '172800', '21');
INSERT INTO `blackmarket_template` VALUES ('17', '45693', '1', '32216', '200000000', '172800', '23');
INSERT INTO `blackmarket_template` VALUES ('18', '44175', '1', '32216', '200000000', '172800', '21');
INSERT INTO `blackmarket_template` VALUES ('19', '44970', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('20', '44974', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('21', '44984', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('22', '45002', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('23', '44965', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('24', '44973', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('25', '45606', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('26', '44980', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('27', '44982', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('28', '44971', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('29', '44721', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('30', '8492', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('31', '8490', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('32', '10822', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('33', '8491', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('34', '34478', '1', '28951', '100000000', '172800', '50');
INSERT INTO `blackmarket_template` VALUES ('35', '29960', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('36', '48116', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('37', '43698', '1', '28951', '100000000', '172800', '60');
INSERT INTO `blackmarket_template` VALUES ('38', '8495', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('39', '35504', '1', '28951', '100000000', '172800', '40');
INSERT INTO `blackmarket_template` VALUES ('40', '20769', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('41', '8499', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('42', '34535', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('43', '48112', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('44', '48114', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('45', '48124', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('46', '48118', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('47', '8490', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('48', '48126', '1', '28951', '100000000', '172800', '100');
INSERT INTO `blackmarket_template` VALUES ('49', '49286', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('50', '23720', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('51', '32588', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('52', '34493', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('53', '23713', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('54', '32566', '1', '17249', '100000000', '172800', '75');
INSERT INTO `blackmarket_template` VALUES ('55', '33223', '1', '17249', '100000000', '172800', '75');
INSERT INTO `blackmarket_template` VALUES ('56', '33219', '1', '17249', '100000000', '172800', '75');
INSERT INTO `blackmarket_template` VALUES ('57', '34499', '1', '17249', '100000000', '172800', '75');
INSERT INTO `blackmarket_template` VALUES ('58', '32542', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('59', '35227', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('60', '23705', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('61', '23713', '1', '17249', '100000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('62', '34492', '1', '17249', '100000000', '172800', '75');
INSERT INTO `blackmarket_template` VALUES ('63', '22478', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('64', '22479', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('65', '22476', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('66', '22482', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('67', '22477', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('68', '22480', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('69', '22483', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('70', '22481', '1', '32378', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('71', '22418', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('72', '22419', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('73', '22416', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('74', '22422', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('75', '22417', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('76', '22420', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('77', '22423', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('78', '22421', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('79', '22419', '1', '61796', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('80', '22490', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('81', '22491', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('82', '22488', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('83', '22494', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('84', '22489', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('85', '22492', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('86', '22495', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('87', '22493', '1', '52845', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('88', '22498', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('89', '22499', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('90', '22496', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('91', '22502', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('92', '22497', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('93', '22500', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('94', '22501', '1', '68108', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('95', '22506', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('96', '22507', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('97', '22504', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('98', '22510', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('99', '22505', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('100', '22508', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('101', '22511', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('102', '22509', '1', '21164', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('103', '22428', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('104', '22429', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('105', '22425', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('106', '22431', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('107', '22427', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('108', '22430', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('109', '22424', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('110', '22426', '1', '34496', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('111', '22466', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('112', '22467', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('113', '22464', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('114', '22470', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('115', '22465', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('116', '22468', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('117', '22471', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('118', '22469', '1', '54634', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('119', '22514', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('120', '22515', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('121', '22512', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('122', '22518', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('123', '22513', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('124', '22516', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('125', '22519', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('126', '22517', '1', '7999', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('127', '44924', '1', '23626', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('128', '90176', '1', '44806', '100000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('129', '39769', '1', '23619', '100000000', '172800', '22');
INSERT INTO `blackmarket_template` VALUES ('130', '86238', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('131', '86272', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('132', '86279', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('133', '86280', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('134', '86281', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('135', '86283', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('136', '86284', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('137', '86297', '1', '18754', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('138', '86379', '1', '22213', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('139', '86380', '1', '22213', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('140', '86381', '1', '22213', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('141', '86382', '1', '22213', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('142', '87409', '1', '514', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('143', '87410', '1', '514', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('144', '87411', '1', '514', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('145', '87412', '1', '514', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('146', '87413', '1', '514', '125000000', '172800', '35');
INSERT INTO `blackmarket_template` VALUES ('148', '86981', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('149', '87178', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('150', '87179', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('151', '87182', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('152', '86955', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('153', '87183', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('154', '87161', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('155', '87181', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('156', '87180', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('157', '87177', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('158', '87185', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('159', '87184', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('160', '87186', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('161', '84946', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('162', '84947', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('163', '84948', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('164', '84949', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('165', '84950', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('166', '84951', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('167', '84952', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('168', '84953', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('169', '84954', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('170', '84955', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('171', '84956', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('172', '84957', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('173', '84958', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('174', '84959', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('175', '84960', '1', '64179', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('176', '86961', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('177', '87150', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('178', '86945', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('179', '86963', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('180', '86971', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('181', '86980', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('182', '87159', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('183', '84801', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('184', '84802', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('185', '84803', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('186', '84804', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('187', '84805', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('188', '84806', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('189', '84807', '1', '64178', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('190', '86948', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('191', '87149', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('192', '86995', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('193', '86996', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('194', '86962', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('195', '86998', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('196', '87000', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('197', '86992', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('198', '86993', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('199', '84972', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('200', '84973', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('201', '84974', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('202', '84975', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('203', '84976', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('204', '84977', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('205', '84978', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('206', '84979', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('207', '84980', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('208', '84981', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('209', '84982', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('210', '84983', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('211', '84984', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('212', '84985', '1', '64181', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('213', '84808', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('214', '84809', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('215', '84810', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('216', '84811', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('217', '84812', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('218', '84813', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('219', '84814', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('220', '84815', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('221', '84816', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('222', '84817', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('223', '84818', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('224', '84819', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('225', '84820', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('226', '84821', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('227', '84822', '1', '64180', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('228', '86946', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('229', '86949', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('230', '86957', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('231', '86968', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('232', '86974', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('233', '86982', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('234', '87144', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('235', '8151', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('236', '87158', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('237', '86953', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('238', '86967', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('239', '86976', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('240', '87147', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('241', '87148', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('242', '84823', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('243', '84824', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('244', '84825', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('245', '84826', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('246', '84827', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('247', '84828', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('248', '84829', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('249', '84886', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('250', '84887', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('251', '84888', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('252', '84889', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('253', '84890', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('254', '84891', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('255', '84892', '1', '19674', '100000000', '172800', '0');
INSERT INTO `blackmarket_template` VALUES ('256', '22440', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('257', '22442', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('258', '22441', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('259', '22438', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('260', '22437', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('261', '22439', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('262', '22436', '1', '10181', '150000000', '172800', '30');
INSERT INTO `blackmarket_template` VALUES ('263', '22443', '1', '10181', '150000000', '172800', '30');
