/*
MySQL Data Transfer
Source Host: localhost
Source Database: 300m_world
Target Host: localhost
Target Database: 300m_world
Date: 26.02.2014 2:12:21
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for archaeology_zones
-- ----------------------------
DROP TABLE IF EXISTS `archaeology_zones`;
CREATE TABLE `archaeology_zones` (
  `site_id` mediumint(8) NOT NULL,
  `zone_id` mediumint(8) NOT NULL,
  `branch_id` mediumint(8) NOT NULL,
  PRIMARY KEY (`site_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `archaeology_zones` VALUES ('9', '38', '1');
INSERT INTO `archaeology_zones` VALUES ('10', '11', '1');
INSERT INTO `archaeology_zones` VALUES ('12', '11', '1');
INSERT INTO `archaeology_zones` VALUES ('13', '11', '3');
INSERT INTO `archaeology_zones` VALUES ('15', '45', '1');
INSERT INTO `archaeology_zones` VALUES ('18', '45', '8');
INSERT INTO `archaeology_zones` VALUES ('19', '11', '1');
INSERT INTO `archaeology_zones` VALUES ('20', '267', '1');
INSERT INTO `archaeology_zones` VALUES ('21', '267', '3');
INSERT INTO `archaeology_zones` VALUES ('22', '47', '1');
INSERT INTO `archaeology_zones` VALUES ('23', '47', '8');
INSERT INTO `archaeology_zones` VALUES ('24', '47', '8');
INSERT INTO `archaeology_zones` VALUES ('25', '47', '8');
INSERT INTO `archaeology_zones` VALUES ('26', '47', '8');
INSERT INTO `archaeology_zones` VALUES ('27', '47', '8');
INSERT INTO `archaeology_zones` VALUES ('144', '3', '1');
INSERT INTO `archaeology_zones` VALUES ('146', '3', '1');
INSERT INTO `archaeology_zones` VALUES ('150', '3', '1');
INSERT INTO `archaeology_zones` VALUES ('152', '8', '8');
INSERT INTO `archaeology_zones` VALUES ('154', '8', '3');
INSERT INTO `archaeology_zones` VALUES ('163', '10', '4');
INSERT INTO `archaeology_zones` VALUES ('165', '10', '3');
INSERT INTO `archaeology_zones` VALUES ('167', '148', '4');
INSERT INTO `archaeology_zones` VALUES ('169', '331', '4');
INSERT INTO `archaeology_zones` VALUES ('171', '331', '4');
INSERT INTO `archaeology_zones` VALUES ('173', '331', '4');
INSERT INTO `archaeology_zones` VALUES ('175', '331', '4');
INSERT INTO `archaeology_zones` VALUES ('177', '406', '4');
INSERT INTO `archaeology_zones` VALUES ('179', '406', '4');
INSERT INTO `archaeology_zones` VALUES ('181', '406', '3');
INSERT INTO `archaeology_zones` VALUES ('183', '4709', '1');
INSERT INTO `archaeology_zones` VALUES ('185', '16', '4');
INSERT INTO `archaeology_zones` VALUES ('187', '16', '4');
INSERT INTO `archaeology_zones` VALUES ('189', '44', '3');
INSERT INTO `archaeology_zones` VALUES ('191', '405', '4');
INSERT INTO `archaeology_zones` VALUES ('193', '405', '4');
INSERT INTO `archaeology_zones` VALUES ('195', '405', '3');
INSERT INTO `archaeology_zones` VALUES ('197', '405', '4');
INSERT INTO `archaeology_zones` VALUES ('199', '405', '3');
INSERT INTO `archaeology_zones` VALUES ('201', '405', '4');
INSERT INTO `archaeology_zones` VALUES ('203', '4', '3');
INSERT INTO `archaeology_zones` VALUES ('205', '4', '3');
INSERT INTO `archaeology_zones` VALUES ('207', '51', '1');
INSERT INTO `archaeology_zones` VALUES ('209', '51', '1');
INSERT INTO `archaeology_zones` VALUES ('211', '46', '1');
INSERT INTO `archaeology_zones` VALUES ('213', '46', '1');
INSERT INTO `archaeology_zones` VALUES ('215', '46', '3');
INSERT INTO `archaeology_zones` VALUES ('217', '139', '8');
INSERT INTO `archaeology_zones` VALUES ('219', '139', '4');
INSERT INTO `archaeology_zones` VALUES ('221', '139', '3');
INSERT INTO `archaeology_zones` VALUES ('223', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('225', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('227', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('229', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('231', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('233', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('235', '33', '8');
INSERT INTO `archaeology_zones` VALUES ('237', '5339', '3');
INSERT INTO `archaeology_zones` VALUES ('239', '5287', '8');
INSERT INTO `archaeology_zones` VALUES ('241', '5287', '8');
INSERT INTO `archaeology_zones` VALUES ('243', '5287', '8');
INSERT INTO `archaeology_zones` VALUES ('245', '5287', '8');
INSERT INTO `archaeology_zones` VALUES ('247', '28', '3');
INSERT INTO `archaeology_zones` VALUES ('249', '28', '3');
INSERT INTO `archaeology_zones` VALUES ('251', '28', '3');
INSERT INTO `archaeology_zones` VALUES ('259', '15', '3');
INSERT INTO `archaeology_zones` VALUES ('261', '15', '3');
INSERT INTO `archaeology_zones` VALUES ('279', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('281', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('283', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('285', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('287', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('289', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('291', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('293', '357', '4');
INSERT INTO `archaeology_zones` VALUES ('295', '361', '4');
INSERT INTO `archaeology_zones` VALUES ('297', '361', '4');
INSERT INTO `archaeology_zones` VALUES ('299', '361', '4');
INSERT INTO `archaeology_zones` VALUES ('301', '361', '4');
INSERT INTO `archaeology_zones` VALUES ('303', '618', '4');
INSERT INTO `archaeology_zones` VALUES ('305', '618', '4');
INSERT INTO `archaeology_zones` VALUES ('307', '618', '4');
INSERT INTO `archaeology_zones` VALUES ('309', '4709', '3');
INSERT INTO `archaeology_zones` VALUES ('313', '4709', '4');
INSERT INTO `archaeology_zones` VALUES ('315', '440', '8');
INSERT INTO `archaeology_zones` VALUES ('317', '440', '8');
INSERT INTO `archaeology_zones` VALUES ('319', '440', '8');
INSERT INTO `archaeology_zones` VALUES ('321', '440', '8');
INSERT INTO `archaeology_zones` VALUES ('323', '440', '3');
INSERT INTO `archaeology_zones` VALUES ('325', '440', '3');
INSERT INTO `archaeology_zones` VALUES ('327', '490', '3');
INSERT INTO `archaeology_zones` VALUES ('329', '490', '3');
INSERT INTO `archaeology_zones` VALUES ('331', '490', '3');
INSERT INTO `archaeology_zones` VALUES ('333', '490', '3');
INSERT INTO `archaeology_zones` VALUES ('335', '490', '3');
INSERT INTO `archaeology_zones` VALUES ('337', '1377', '4');
INSERT INTO `archaeology_zones` VALUES ('339', '3483', '6');
INSERT INTO `archaeology_zones` VALUES ('341', '3483', '6');
INSERT INTO `archaeology_zones` VALUES ('343', '3483', '6');
INSERT INTO `archaeology_zones` VALUES ('345', '3483', '6');
INSERT INTO `archaeology_zones` VALUES ('347', '3483', '2');
INSERT INTO `archaeology_zones` VALUES ('349', '3521', '2');
INSERT INTO `archaeology_zones` VALUES ('351', '3521', '2');
INSERT INTO `archaeology_zones` VALUES ('353', '3523', '2');
INSERT INTO `archaeology_zones` VALUES ('355', '3523', '2');
INSERT INTO `archaeology_zones` VALUES ('357', '3523', '2');
INSERT INTO `archaeology_zones` VALUES ('359', '3518', '6');
INSERT INTO `archaeology_zones` VALUES ('363', '3518', '6');
INSERT INTO `archaeology_zones` VALUES ('365', '3518', '6');
INSERT INTO `archaeology_zones` VALUES ('367', '3518', '6');
INSERT INTO `archaeology_zones` VALUES ('369', '3518', '2');
INSERT INTO `archaeology_zones` VALUES ('371', '3519', '6');
INSERT INTO `archaeology_zones` VALUES ('373', '3519', '2');
INSERT INTO `archaeology_zones` VALUES ('375', '3519', '6');
INSERT INTO `archaeology_zones` VALUES ('377', '3519', '6');
INSERT INTO `archaeology_zones` VALUES ('379', '3519', '2');
INSERT INTO `archaeology_zones` VALUES ('381', '3519', '2');
INSERT INTO `archaeology_zones` VALUES ('383', '3519', '2');
INSERT INTO `archaeology_zones` VALUES ('385', '3520', '2');
INSERT INTO `archaeology_zones` VALUES ('387', '3520', '2');
INSERT INTO `archaeology_zones` VALUES ('391', '3520', '2');
INSERT INTO `archaeology_zones` VALUES ('393', '3520', '2');
INSERT INTO `archaeology_zones` VALUES ('395', '3520', '6');
INSERT INTO `archaeology_zones` VALUES ('399', '3520', '6');
INSERT INTO `archaeology_zones` VALUES ('401', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('403', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('405', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('407', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('409', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('411', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('413', '495', '27');
INSERT INTO `archaeology_zones` VALUES ('415', '65', '27');
INSERT INTO `archaeology_zones` VALUES ('417', '65', '27');
INSERT INTO `archaeology_zones` VALUES ('419', '3537', '27');
INSERT INTO `archaeology_zones` VALUES ('421', '66', '27');
INSERT INTO `archaeology_zones` VALUES ('423', '3537', '4');
INSERT INTO `archaeology_zones` VALUES ('425', '2817', '4');
INSERT INTO `archaeology_zones` VALUES ('427', '2817', '4');
INSERT INTO `archaeology_zones` VALUES ('429', '66', '8');
INSERT INTO `archaeology_zones` VALUES ('431', '66', '8');
INSERT INTO `archaeology_zones` VALUES ('433', '66', '8');
INSERT INTO `archaeology_zones` VALUES ('435', '66', '8');
INSERT INTO `archaeology_zones` VALUES ('437', '3537', '27');
INSERT INTO `archaeology_zones` VALUES ('439', '394', '27');
INSERT INTO `archaeology_zones` VALUES ('443', '394', '8');
INSERT INTO `archaeology_zones` VALUES ('445', '67', '27');
INSERT INTO `archaeology_zones` VALUES ('447', '67', '27');
INSERT INTO `archaeology_zones` VALUES ('449', '67', '27');
INSERT INTO `archaeology_zones` VALUES ('451', '210', '27');
INSERT INTO `archaeology_zones` VALUES ('455', '210', '27');
INSERT INTO `archaeology_zones` VALUES ('457', '210', '27');
INSERT INTO `archaeology_zones` VALUES ('459', '210', '27');
INSERT INTO `archaeology_zones` VALUES ('461', '616', '4');
INSERT INTO `archaeology_zones` VALUES ('463', '616', '4');
INSERT INTO `archaeology_zones` VALUES ('465', '616', '4');
INSERT INTO `archaeology_zones` VALUES ('467', '616', '4');
INSERT INTO `archaeology_zones` VALUES ('469', '616', '4');
INSERT INTO `archaeology_zones` VALUES ('471', '5144', '4');
INSERT INTO `archaeology_zones` VALUES ('473', '5144', '4');
INSERT INTO `archaeology_zones` VALUES ('475', '5144', '4');
INSERT INTO `archaeology_zones` VALUES ('477', '4922', '1');
INSERT INTO `archaeology_zones` VALUES ('479', '4922', '1');
INSERT INTO `archaeology_zones` VALUES ('481', '4922', '1');
INSERT INTO `archaeology_zones` VALUES ('485', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('487', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('489', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('491', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('493', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('495', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('497', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('499', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('501', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('570', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('572', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('574', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('576', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('578', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('581', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('583', '5034', '7');
INSERT INTO `archaeology_zones` VALUES ('587', '210', '5');
INSERT INTO `archaeology_zones` VALUES ('589', '3537', '5');
INSERT INTO `archaeology_zones` VALUES ('615', '139', '5');
INSERT INTO `archaeology_zones` VALUES ('617', '139', '5');
