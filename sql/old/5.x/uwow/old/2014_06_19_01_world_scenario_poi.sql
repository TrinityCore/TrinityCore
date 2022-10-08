/*
MySQL Data Transfer
Source Host: localhost
Source Database: 505_world_542
Target Host: localhost
Target Database: 505_world_542
Date: 22.06.2014 20:57:11
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for scenario_poi
-- ----------------------------
DROP TABLE IF EXISTS `scenario_poi`;
CREATE TABLE `scenario_poi` (
  `criteriaTreeId` int(10) unsigned NOT NULL DEFAULT '0',
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `mapid` int(10) unsigned NOT NULL DEFAULT '0',
  `WorldMapAreaId` int(10) unsigned NOT NULL DEFAULT '0',
  `unk12` int(10) unsigned NOT NULL DEFAULT '0',
  `unk16` int(10) unsigned NOT NULL DEFAULT '0',
  `unk20` int(10) unsigned NOT NULL DEFAULT '0',
  `unk24` int(10) unsigned NOT NULL DEFAULT '0',
  `unk28` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`criteriaTreeId`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `scenario_poi` VALUES ('20981', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('28125', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('20977', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('20978', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('20979', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('20980', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('21062', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('21060', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('21060', '1', '1024', '880', '0', '0', '0', '727', '0');
INSERT INTO `scenario_poi` VALUES ('21060', '2', '1024', '880', '0', '0', '0', '727', '0');
INSERT INTO `scenario_poi` VALUES ('21129', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('21127', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('21128', '0', '1024', '880', '0', '0', '0', '505', '0');
INSERT INTO `scenario_poi` VALUES ('20983', '0', '1024', '880', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('31476', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31478', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31480', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31481', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31482', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31484', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31485', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31487', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31488', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31489', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31491', '0', '1102', '920', '0', '0', '0', '1409', '0');
INSERT INTO `scenario_poi` VALUES ('31492', '0', '1102', '920', '0', '0', '0', '1410', '0');
INSERT INTO `scenario_poi` VALUES ('31493', '0', '1102', '920', '0', '0', '0', '1411', '0');
INSERT INTO `scenario_poi` VALUES ('31498', '0', '1102', '920', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22790', '0', '1048', '882', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('29563', '0', '1048', '882', '0', '0', '0', '1171', '19267');
INSERT INTO `scenario_poi` VALUES ('29563', '1', '1048', '882', '0', '0', '0', '1171', '19268');
INSERT INTO `scenario_poi` VALUES ('29563', '2', '1048', '882', '0', '0', '0', '1171', '19269');
INSERT INTO `scenario_poi` VALUES ('29563', '3', '1048', '882', '0', '0', '0', '1171', '19270');
INSERT INTO `scenario_poi` VALUES ('21009', '0', '1048', '882', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30958', '0', '1050', '883', '0', '0', '0', '538', '0');
INSERT INTO `scenario_poi` VALUES ('30960', '0', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('30960', '1', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('30960', '2', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('30961', '0', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('30961', '1', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('30961', '2', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('30962', '0', '1050', '883', '0', '0', '0', '1287', '0');
INSERT INTO `scenario_poi` VALUES ('30967', '0', '1050', '883', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30968', '0', '1050', '883', '0', '0', '0', '1359', '0');
INSERT INTO `scenario_poi` VALUES ('30965', '0', '1050', '883', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32624', '0', '1130', '939', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32647', '0', '1130', '939', '0', '0', '0', '1584', '0');
INSERT INTO `scenario_poi` VALUES ('32649', '0', '1130', '939', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32651', '0', '1130', '939', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32653', '0', '1130', '939', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32656', '0', '1130', '939', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32593', '0', '1144', '937', '0', '0', '0', '1575', '0');
INSERT INTO `scenario_poi` VALUES ('32595', '0', '1144', '937', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32595', '1', '1144', '937', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32597', '0', '1144', '937', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32599', '0', '1144', '937', '1', '0', '0', '1633', '21726');
INSERT INTO `scenario_poi` VALUES ('32599', '1', '1144', '937', '0', '0', '0', '1633', '21725');
INSERT INTO `scenario_poi` VALUES ('21848', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21846', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21847', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21854', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21855', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21856', '0', '1051', '884', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('21852', '0', '1051', '884', '0', '0', '0', '938', '0');
INSERT INTO `scenario_poi` VALUES ('31048', '0', '999', '851', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('31048', '1', '999', '851', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('31048', '2', '999', '851', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('22990', '0', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22978', '0', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22979', '0', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22979', '1', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22981', '0', '999', '851', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('22987', '0', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22988', '0', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22988', '1', '999', '851', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30887', '0', '1095', '914', '0', '0', '0', '1419', '0');
INSERT INTO `scenario_poi` VALUES ('30885', '0', '1095', '914', '0', '0', '0', '1359', '0');
INSERT INTO `scenario_poi` VALUES ('31105', '0', '1095', '914', '0', '0', '0', '658', '0');
INSERT INTO `scenario_poi` VALUES ('30569', '0', '1095', '914', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('30940', '0', '1095', '914', '0', '0', '0', '1421', '0');
INSERT INTO `scenario_poi` VALUES ('30949', '0', '1095', '914', '1', '0', '0', '1359', '0');
INSERT INTO `scenario_poi` VALUES ('30571', '0', '1095', '914', '1', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('30951', '0', '1095', '914', '1', '0', '0', '538', '0');
INSERT INTO `scenario_poi` VALUES ('30952', '0', '1095', '914', '1', '0', '0', '538', '0');
INSERT INTO `scenario_poi` VALUES ('30573', '0', '1095', '914', '1', '0', '0', '1425', '0');
INSERT INTO `scenario_poi` VALUES ('21994', '0', '1005', '878', '0', '0', '0', '1229', '0');
INSERT INTO `scenario_poi` VALUES ('21996', '0', '1005', '878', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22000', '0', '1005', '878', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32775', '0', '1099', '940', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('32777', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32779', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32782', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27198', '0', '1030', '900', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('22066', '0', '1030', '900', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('21051', '0', '1030', '900', '2', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30998', '0', '1104', '912', '0', '0', '0', '0', '19596');
INSERT INTO `scenario_poi` VALUES ('30999', '0', '1104', '912', '0', '0', '0', '0', '19682');
INSERT INTO `scenario_poi` VALUES ('31000', '0', '1104', '912', '0', '0', '0', '0', '19855');
INSERT INTO `scenario_poi` VALUES ('31001', '0', '1104', '912', '0', '0', '0', '0', '20050');
INSERT INTO `scenario_poi` VALUES ('31002', '0', '1104', '912', '0', '0', '0', '0', '19990');
INSERT INTO `scenario_poi` VALUES ('31193', '0', '1104', '912', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31863', '0', '1126', '933', '0', '0', '0', '658', '0');
INSERT INTO `scenario_poi` VALUES ('32143', '0', '1126', '933', '0', '0', '0', '1559', '0');
INSERT INTO `scenario_poi` VALUES ('31929', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31931', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31933', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32032', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31935', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31834', '0', '1126', '933', '0', '0', '0', '1497', '0');
INSERT INTO `scenario_poi` VALUES ('31836', '0', '1126', '933', '0', '0', '0', '1559', '0');
INSERT INTO `scenario_poi` VALUES ('31840', '0', '1126', '933', '0', '0', '0', '1537', '0');
INSERT INTO `scenario_poi` VALUES ('31838', '0', '1126', '933', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('24762', '0', '1031', '899', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('24763', '0', '1031', '899', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('24764', '0', '1031', '899', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('24765', '0', '1031', '899', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('24766', '0', '1031', '899', '1', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31228', '0', '1050', '883', '0', '0', '0', '538', '0');
INSERT INTO `scenario_poi` VALUES ('31230', '0', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('31230', '1', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('31230', '2', '1050', '883', '0', '0', '0', '1285', '0');
INSERT INTO `scenario_poi` VALUES ('31231', '0', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('31231', '1', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('31231', '2', '1050', '883', '0', '0', '0', '1286', '0');
INSERT INTO `scenario_poi` VALUES ('31232', '0', '1050', '883', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31234', '0', '1050', '883', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31235', '0', '1050', '883', '0', '0', '0', '1359', '0');
INSERT INTO `scenario_poi` VALUES ('31237', '0', '1050', '883', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('32658', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30732', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('30734', '0', '1099', '940', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31285', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31284', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31286', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31289', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31290', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31297', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31298', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31299', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('31302', '0', '1103', '911', '0', '0', '0', '1409', '0');
INSERT INTO `scenario_poi` VALUES ('31303', '0', '1103', '911', '0', '0', '0', '1410', '0');
INSERT INTO `scenario_poi` VALUES ('31301', '0', '1103', '911', '0', '0', '0', '1411', '0');
INSERT INTO `scenario_poi` VALUES ('31295', '0', '1103', '911', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27243', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27258', '0', '1000', '906', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('27258', '1', '1000', '906', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('27258', '2', '1000', '906', '0', '0', '0', '1161', '0');
INSERT INTO `scenario_poi` VALUES ('27261', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27453', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27458', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27461', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('27576', '0', '1000', '906', '0', '0', '0', '0', '0');
INSERT INTO `scenario_poi` VALUES ('21049', '0', '1030', '900', '1', '0', '0', '1161', '0');
