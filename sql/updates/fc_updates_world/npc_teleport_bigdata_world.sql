DROP TABLE IF EXISTS `custom_npc_tele_category`;
-- ----------------------------
-- Table structure for custom_npc_tele_category
-- ----------------------------
CREATE TABLE `custom_npc_tele_category` (
  `id` int(6) unsigned NOT NULL default '0',
  `name` varchar(255) NOT NULL default '',
  `flag` tinyint(3) unsigned NOT NULL default '0',
  `data0` bigint(20) unsigned NOT NULL default '0',
  `data1` int(6) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `custom_npc_tele_category` VALUES ('1', '1. Cities', '0', '1', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('2', '1. Cities', '0', '2', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('3', '2. Instance Level 10-40', '0', '0', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('4', '3. Instance Level 41-69', '0', '0', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('5', '4. Instance Level 70-80', '0', '0', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('6', '5. Raids', '0', '0', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('7', '6. Areans', '0', '0', '0');
INSERT INTO `custom_npc_tele_category` VALUES ('8', '7. Shopping', '2', '3', '0');

DROP TABLE IF EXISTS `custom_npc_tele_destination`;
-- ----------------------------
-- Table structure for custom_npc_tele_destination
-- ----------------------------
CREATE TABLE `custom_npc_tele_destination` (
  `id` int(6) unsigned NOT NULL auto_increment,
  `name` char(100) NOT NULL default '',
  `pos_X` float NOT NULL default '0',
  `pos_Y` float NOT NULL default '0',
  `pos_Z` float NOT NULL default '0',
  `map` smallint(5) unsigned NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `level` tinyint(3) unsigned NOT NULL default '0',
  `cost` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=99 DEFAULT CHARSET=utf8;
-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `custom_npc_tele_destination` VALUES ('1', '01. Ragefire Chasm (13-20)', '1810.38', '-4408.05', '-18.8377', '1', '5.18594', '8', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('2', '02. Wailing Caverns (17-23)', '-722.53', '-2226.3', '16.94', '1', '2.71', '12', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('3', '03. The Deadmines (17-23)', '-11212', '1658.58', '25.67', '0', '1.45', '12', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('4', '04. Shadowfang Keep (18-23)', '-240.11', '1548.83', '76.89', '0', '1.13981', '13', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('5', '05. Blackfathom Deeps (22-27)', '4249.99', '740.1', '-25.67', '1', '1.34062', '17', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('6', '06. Stormwind Stockade (23-27)', '-8774.25', '838.965', '91.9284', '0', '0.689341', '18', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('7', '07. Razorfen Kraul (21-31)', '-4484.04', '-1739.4', '86.47', '1', '1.23', '16', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('8', '08. Gnomeregan (25-32)', '-5163.54', '925.42', '257.17', '0', '1.57423', '20', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('9', '09. The Scarlet Monastery: Graveyard  (29-35)', '2913.01', '-802.75', '160.33', '0', '0.339072', '25', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('10', '10. The Scarlet Monastery: Library  (31-35)', '2872.08', '-820.06', '160.33', '0', '3.46299', '26', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('11', '11. Razorfen Downs (33-37)', '-4645.08', '-2470.85', '85.53', '1', '4.39', '28', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('12', '12. The Scarlet Monastery: Armory  (33-37)', '2885.54', '-825.1', '160.33', '0', '5.12803', '28', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('13', '13. The Scarlet Monastery: Cathedral  (37-44)', '2907.48', '-816.101', '160.33', '0', '5.0652', '32', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('14', '14. Uldaman (37-44)', '-6119.7', '-2957.3', '204.11', '0', '0.03', '32', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('15', '01. Zul\'Farrak (42-46)', '-6839.39', '-2911.03', '8.87', '1', '0.41', '37', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('16', '02. Maraudon (42-52)', '-1433.33', '2955.34', '96.21', '1', '4.82', '37', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('17', '03. Temple of Atal\'Hakkar  (47-52)', '-10346.9', '-3851.9', '-43.41', '0', '6.09', '42', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('18', '04. Blackrock Depths (48-60)', '-7179.33', '-918.7', '165.49', '0', '4.73078', '43', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('19', '05. Dire Maul: East  (55-60)', '-3981.41', '781.85', '161.004', '1', '4.6741', '50', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('20', '06. Dire Maul: West  (57-60)', '-3829.17', '1250.51', '160.22', '1', '3.09938', '52', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('21', '07. Dire Maul: North  (57-60)', '-3520.64', '1077.71', '161.13', '1', '4.68176', '52', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('22', '08. Stratholme  (56-61)', '3263.54', '-3379.46', '143.59', '0', '0', '51', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('23', '09. Scholomance (56-61)', '1219.01', '-2604.66', '85.61', '0', '0.5', '51', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('24', '10. Hellfire Ramparts (60-62)', '-359.69', '3069.36', '-15.1135', '530', '1.8637', '55', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('25', '11. The Blood Furnace  (61-63)', '-300.137', '3160.08', '31.6914', '530', '2.25967', '56', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('26', '12. Slave Pens  (62-64)', '721.256', '7008.33', '-73.4791', '530', '0.450804', '57', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('27', '13. The Underbog  (63-65)', '779.66', '6767.33', '-71.77', '530', '4.7', '58', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('28', '14. Mana-Tombs  (64-66)', '-3104.17', '4945.52', '-101.507', '530', '0.054137', '59', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('29', '15. Auchenai Crypts (65-67)', '-3362.04', '5209.85', '-101.05', '530', '1.52677', '60', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('30', '16. Escape from Durnholde Keep  (66-68)', '-8367.11', '-4059.21', '-208.31', '1', '0.108172', '61', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('31', '17. Sethekk Halls  (67-69)', '-3361.91', '4678.85', '-101.048', '530', '4.68897', '62', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('32', '18. The Steamvault (68-70)', '815.701', '6928.7', '-80.0444', '530', '1.46476', '63', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('33', '19. Shadow Labyrinth  (69-70)', '-3627.03', '4942.75', '-101.049', '530', '3.12505', '64', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('34', '20. Shattered Halls  (69-70)', '-308.4', '3072.7', '-3.65004', '530', '1.75536', '64', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('35', '01. Black Morass (70)', '-8752.98', '-4205.76', '-209.5', '1', '2.23792', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('36', '02. The Mechanar (70)', '2880.38', '1562.57', '248.88', '530', '3.84869', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('37', '03. The Botanica (70)', '3396.79', '1495.11', '179.56', '530', '5.68591', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('38', '04. The Arcatraz (70)', '3304.99', '1349.93', '502.29', '530', '4.99889', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('39', '05. Magisters\' Terrace (70)', '12889', '-7320.27', '65.5023', '530', '4.43379', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('40', '06. Utgarde Keep (70-72)', '1224.31', '-4862.99', '41.2493', '571', '0.265729', '65', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('41', '07. The Nexus (71-73)', '3880.71', '6984.41', '73.761', '571', '0.093386', '66', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('42', '08. Azjol-Nerub (72-74)', '3692.49', '2157.36', '34.9193', '571', '2.54456', '67', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('43', '09. Ahn\'kahet: The Old Kingdom (73-75)', '3647.05', '2045.8', '1.78771', '571', '4.33625', '68', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('44', '10. Drak\'Tharon Keep (74-76)', '4774.2', '-2032.44', '229.37', '571', '1.56251', '69', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('45', '11. The Violet Hold (75-77)', '5695.6', '505.81', '652.68', '571', '4.11793', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('46', '12. Gundrak (76-78)', '6929.22', '-4443.09', '450.52', '571', '0.748567', '71', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('47', '13. Halls of Stone (77-79)', '8923.25', '-1014.92', '1039.61', '571', '1.53846', '72', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('48', '14. Halls of Lightning (80)', '9128.79', '-1338.15', '1061.4', '571', '5.43122', '75', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('49', '15. The Oculus (80)', '3879.32', '6984.34', '106.32', '571', '3.06023', '75', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('50', '16. Culling of Stratholme (Culling/COS) (80)', '-8752.93', '-4444.03', '-199.009', '1', '4.34869', '75', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('51', '17. Utgarde Pinnacle (80)', '1253.46', '-4853.82', '215.73', '571', '3.4309', '75', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('52', '18. Trial of the Champion (80)', '8575.03', '792.278', '558.514', '571', '3.16778', '75', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('53', '20. Forge of Souls (80+)', '5672.19', '2002.17', '798.182', '571', '5.47579', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('54', '19. Pit of Saron (80+)', '5591.99', '2010.32', '798.182', '571', '3.92227', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('55', '21. Halls of Reflection (80+)', '5629.33', '1986.66', '800.027', '571', '4.72024', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('56', '01. Blackrock Spire (54-60) (10 man)', '-7535.43', '-1212.04', '285.45', '0', '5.29', '49', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('58', '03. Zul\'Gurub (56-60+) (20 man)', '-11916.7', '-1212.82', '92.2868', '0', '4.6095', '50', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('59', '04. Molten Core (60+) (40 man)', '1121.45', '-454.317', '-101.33', '230', '3.5', '55', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('60', '05. Blackwing Lair (60++) (40 man)', '-7665.55', '-1102.49', '400.679', '469', '0', '60', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('61', '06. Ruins of Ahn\'Qiraj (60++) (20 man)', '-8409.03', '1498.83', '27.3615', '1', '2.49757', '60', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('62', '07. Temple of Ahn\'Qiraj (60+++) (40 man)', '-8245.84', '1983.74', '129.072', '1', '0.936195', '60', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('63', '08. Karazhan (70+) (10 man)', '-11118.8', '-2010.84', '47.0807', '0', '0', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('64', '09. Gruul\'s Lair (70+) (25 man)', '3539.01', '5082.36', '1.69107', '530', '0', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('65', '10. Magtheridon\'s Lair (70+) (25 man)', '-317.43', '3095.03', '-116.42', '530', '5.1927', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('66', '11. Zul\'Aman (70++) (10 man)', '6846.95', '-7954.5', '170.028', '530', '4.61501', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('67', '12. Serpentshrine Cavern (70++) (25 man)', '795.188', '6865.64', '-64.8004', '530', '6.2096', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('68', '13. The Eye (70++) (25 man)', '3090.03', '1402.73', '188.81', '530', '4.60991', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('69', '14. Battle for Mount Hyjal (70+++) (25 man)', '-8184.08', '-4196.08', '-171.38', '1', '1.24845', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('70', '15. Black Temple (70+++) (25 man)', '-3610.72', '324.988', '37.4', '530', '3.28298', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('71', '16. Sunwell Plateau (70++++) (25 man)', '12574.1', '-6774.81', '15.09', '530', '3.13788', '70', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('72', '17. Naxxramas (10 man & 25 man) (80+)', '3668.71', '-1262.45', '243.62', '571', '4.785', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('73', '18. Obsidian Sanctum (10 man & 25 man) (80+)', '3516.29', '269.49', '-114.15', '571', '3.19766', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('74', '19. Vault of Archavon (10 man & 25 man) (80+)', '5478.16', '2840.41', '418.67', '571', '6.26748', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('75', '20. The Eye of Eternity (10 man & 25 man) (80++)', '3878.58', '6979.56', '152.04', '571', '2.70778', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('76', '21. Ulduar (10 man & 25 man) (80++)', '9329.55', '-1114.16', '1245.14', '571', '6.24202', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('77', '22. Trial of the Grand/Crusader (10 man, 25 man & Heroic) (80+++)', '8515.45', '728.919', '558.247', '571', '1.59726', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('78', '23. Onyxia\'s Lair (10 man, 25 man & Heroic) (80+++)', '-4707.44', '-3726.82', '54.6723', '1', '3.8', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('79', '24. Icecrown Citadel (10 man, 25 man & Heroic) 80 (80++++)', '5790', '2071.47', '636.065', '571', '3.62348', '80', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('80', '1. Stormwind', '-8960.14', '516.266', '96.3568', '0', '0', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('81', '2. Ironforge', '-4991.78', '-870.59', '496.98', '0', '5.30771', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('82', '3. Darnassus', '8781.82', '965.93', '30.23', '1', '0.240982', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('83', '4. The Exodar', '-4073.03', '-12020.4', '-1.47', '530', '0', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('84', '1. Orgrimmar', '1377.78', '-4369.87', '26.0264', '1', '0.15315', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('85', '2. Thunder Bluff', '-1290', '147.034', '129.682', '1', '4.919', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('86', '3. Undercity', '1642.13', '239.71', '62.5916', '0', '3.15534', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('87', '4. Silvermoon City', '9338.74', '-7277.27', '13.7895', '530', '0', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('88', '5. Shattrath City', '-1850.21', '5435.82', '-10.9614', '530', '3.40391', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('89', '6. Isle of Quel\'Danas', '12947.4', '-6893.31', '5.68398', '530', '3.09154', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('90', '7. Dalaran', '5807.67', '588.207', '660.93', '571', '1.70185', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('91', '5. Shattrath City', '-1850.21', '5435.82', '-10.9614', '530', '3.40391', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('92', '6. Isle of Quel\'Danas', '12947.4', '-6893.31', '5.68398', '530', '3.09154', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('93', '7. Dalaran', '5807.67', '588.207', '660.93', '571', '1.70185', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('94', 'Mall of Vendors', '-2677.91', '2907.24', '178.69', '1', '5.69152', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('95', '1. Gurubashi', '-13261.3', '168.294', '35.0792', '0', '1.00688', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('96', '2. Circle of Blood', '2839.44', '5930.17', '11.1002', '530', '3.16284', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('97', '3. Ring of Trials', '-1999.94', '6581.71', '11.32', '530', '2.3', '0', '0');
INSERT INTO `custom_npc_tele_destination` VALUES ('98', '4. The Maul', '-3739.86', '1093.8', '131.968', '1', '0.155619', '0', '0');

DROP TABLE IF EXISTS `custom_npc_tele_association`;
-- ----------------------------
-- Table structure for custom_npc_tele_association
-- ----------------------------
CREATE TABLE `custom_npc_tele_association` (
  `cat_id` int(6) unsigned NOT NULL default '0',
  `dest_id` int(6) unsigned NOT NULL default '0',
  PRIMARY KEY  (`cat_id`,`dest_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `custom_npc_tele_association` VALUES ('1', '80');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '81');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '82');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '83');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '88');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '89');
INSERT INTO `custom_npc_tele_association` VALUES ('1', '90');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '84');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '85');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '86');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '87');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '91');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '92');
INSERT INTO `custom_npc_tele_association` VALUES ('2', '93');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '1');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '2');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '3');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '4');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '5');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '6');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '7');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '8');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '9');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '10');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '11');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '12');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '13');
INSERT INTO `custom_npc_tele_association` VALUES ('3', '14');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '15');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '16');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '17');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '18');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '19');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '20');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '21');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '22');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '23');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '24');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '25');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '26');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '27');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '28');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '29');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '30');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '31');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '32');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '33');
INSERT INTO `custom_npc_tele_association` VALUES ('4', '34');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '35');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '36');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '37');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '38');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '39');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '40');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '41');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '42');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '43');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '44');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '45');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '46');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '47');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '48');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '49');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '50');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '51');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '52');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '53');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '54');
INSERT INTO `custom_npc_tele_association` VALUES ('5', '55');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '56');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '58');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '59');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '60');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '61');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '62');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '63');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '64');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '65');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '66');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '67');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '68');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '69');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '70');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '71');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '72');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '73');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '74');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '75');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '76');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '77');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '78');
INSERT INTO `custom_npc_tele_association` VALUES ('6', '79');
INSERT INTO `custom_npc_tele_association` VALUES ('7', '95');
INSERT INTO `custom_npc_tele_association` VALUES ('7', '96');
INSERT INTO `custom_npc_tele_association` VALUES ('7', '97');
INSERT INTO `custom_npc_tele_association` VALUES ('7', '98');
INSERT INTO `custom_npc_tele_association` VALUES ('8', '94');

-- `npc_text`
REPLACE INTO `npc_text` (`ID`, `text0_0`) VALUES
   (100000, 'Choose your Category.'),
   (100001, 'Choose your Destination.');

-- `creature_template`
DELETE FROM `creature_template` WHERE `entry` = 100000;
INSERT INTO `creature_template` VALUES (100000, 0, 0, 0, 0, 0, 26502, 0, 0, 0, 'Abisal Vortex', '', '', 0, 83, 83, 0, 35, 35, 1, 1, 1.14286, 2, 1, 509, 683, 0, 805, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 371, 535, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 'npc_teleport', 1);
