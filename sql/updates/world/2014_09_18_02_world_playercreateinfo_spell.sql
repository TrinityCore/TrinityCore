/*
MySQL Data Transfer
Source Host: localhost
Source Database: ashbringer_tc_world
Target Host: localhost
Target Database: ashbringer_tc_world
Date: 9/18/2014 12:19:46 PM
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for playercreateinfo_spell
-- ----------------------------
CREATE TABLE `playercreateinfo_spell` (
  `racemask` int(4) NOT NULL DEFAULT '0',
  `classmask` int(4) NOT NULL DEFAULT '0',
  `Spell` int(4) NOT NULL DEFAULT '0',
  `skilline` int(4) NOT NULL DEFAULT '0' COMMENT 'DEV ONLY',
  PRIMARY KEY (`racemask`,`classmask`,`Spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `playercreateinfo_spell` VALUES ('0', '128', '168', '6');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '128', '71761', '6');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '128', '133', '8');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1', '78', '26');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1', '2457', '26');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '8', '1752', '38');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '8', '21184', '38');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '4', '2973', '51');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '16', '2050', '56');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '16', '585', '56');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '7341', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '0', '813', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('32', '0', '670', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('690', '0', '669', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('16', '0', '17737', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('32', '0', '20549', '124');
INSERT INTO `playercreateinfo_spell` VALUES ('32', '0', '20550', '124');
INSERT INTO `playercreateinfo_spell` VALUES ('32', '0', '20551', '124');
INSERT INTO `playercreateinfo_spell` VALUES ('32', '0', '20552', '124');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '45', '20572', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '0', '20573', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '0', '20574', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '256', '20575', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '4', '20576', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '1179', '21563', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '256', '33702', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '64', '33697', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '32', '54562', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('2', '64', '65222', '125');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '0', '20583', '126');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '0', '20582', '126');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '0', '20585', '126');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '0', '58984', '126');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '1085', '21009', '126');
INSERT INTO `playercreateinfo_spell` VALUES ('64', '0', '7340', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '4', '75', '163');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '2382', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '3365', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '3050', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6233', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6246', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6247', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6477', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6478', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '6603', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '7266', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '7267', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '7355', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '8386', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '9125', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '21651', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '21652', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '22027', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '22810', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '2479', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1024', '27764', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '2', '27762', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '64', '27763', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '4', '34082', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '45927', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '52665', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '61437', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('4095', '1535', '63645', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('4095', '1535', '63644', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '68398', '183');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '2', '60091', '184');
INSERT INTO `playercreateinfo_spell` VALUES ('16', '0', '5227', '220');
INSERT INTO `playercreateinfo_spell` VALUES ('16', '0', '7744', '220');
INSERT INTO `playercreateinfo_spell` VALUES ('16', '0', '20577', '220');
INSERT INTO `playercreateinfo_spell` VALUES ('16', '0', '20579', '220');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '8', '2098', '253');
INSERT INTO `playercreateinfo_spell` VALUES ('1791', '8', '75460', '253');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1', '45471', '257');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '672', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '0', '29932', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '256', '687', '354');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '256', '18822', '354');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '64', '60348', '373');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '64', '331', '374');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '64', '403', '375');
INSERT INTO `playercreateinfo_spell` VALUES ('1791', '64', '75461', '375');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1024', '5185', '573');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1024', '66530', '573');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1024', '5176', '574');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '256', '686', '593');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '256', '58284', '593');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '256', '75445', '593');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '2', '635', '594');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '2', '20154', '594');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '2', '21084', '594');
INSERT INTO `playercreateinfo_spell` VALUES ('8', '0', '671', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '20555', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '20557', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '20558', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '26290', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '26297', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('128', '0', '58943', '733');
INSERT INTO `playercreateinfo_spell` VALUES ('64', '0', '20589', '753');
INSERT INTO `playercreateinfo_spell` VALUES ('64', '0', '20591', '753');
INSERT INTO `playercreateinfo_spell` VALUES ('64', '0', '20593', '753');
INSERT INTO `playercreateinfo_spell` VALUES ('64', '0', '20592', '753');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '20599', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '20597', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '20598', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '20864', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '58985', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('1', '0', '59752', '754');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '8', '25046', '756');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '406', '28730', '756');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '0', '822', '756');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '0', '28877', '756');
INSERT INTO `playercreateinfo_spell` VALUES ('512', '32', '50613', '756');
INSERT INTO `playercreateinfo_spell` VALUES ('1101', '0', '668', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '39', '6562', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '208', '28878', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '1', '28880', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '0', '28875', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '1', '59221', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '32', '59539', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '4', '59536', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '128', '59541', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '2', '59535', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '16', '59538', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '64', '59540', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '32', '59545', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '4', '59543', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '128', '59548', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '2', '59542', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '16', '59544', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '64', '59547', '760');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '45902', '770');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '48266', '770');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '49410', '770');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '45477', '771');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '56816', '771');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '59921', '771');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '61455', '771');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '45462', '772');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '47541', '772');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '49576', '772');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '59879', '772');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '37', '196', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('650', '4', '264', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('1024', '4', '5011', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('735', '1293', '1180', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '204', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '81', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '67', '107', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '20595', '101');
INSERT INTO `playercreateinfo_spell` VALUES ('36', '4', '266', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1107', '198', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '200', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '1488', '227', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '39', '201', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('735', '9', '2567', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '37', '197', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '3', '199', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '35', '202', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '203', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('1759', '400', '5009', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '522', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '40', '674', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '750', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '32', '3127', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('0', '0', '1843', '0');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '59224', '101');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '20594', '101');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '20596', '101');
INSERT INTO `playercreateinfo_spell` VALUES ('4', '0', '2481', '101');
