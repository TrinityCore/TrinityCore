DROP TABLE IF EXISTS `character_pet`;
CREATE TABLE `character_pet` (
  `id` int(11) unsigned NOT NULL  default '0',
  `entry` int(11) unsigned NOT NULL default '0',
  `owner` int(11) unsigned NOT NULL default '0',
  `modelid` int(11) unsigned default '0',
  `level` int(11) unsigned NOT NULL default '1',
  `exp` int(11) unsigned NOT NULL default '0',
  `nextlvlexp` int(11) unsigned NOT NULL default '100',
  `Reactstate` tinyint(1) unsigned NOT NULL default '0',
  `Commandstate` tinyint(1) unsigned NOT NULL default '1',
  `loyaltypoints` int(11) NOT NULL default '0',
  `loyalty` int(11) unsigned NOT NULL default '0',
  `trainpoint` int(11) NOT NULL default '0',
  `name` varchar(100) default 'Pet',
  `renamed` tinyint(1) unsigned NOT NULL default '0',
  `slot` int(11) unsigned NOT NULL default '0',
  `curhealth` int(11) unsigned NOT NULL default '1',
  `curmana` int(11) unsigned NOT NULL default '0',
  `curhappiness` int(11) unsigned NOT NULL default '0',
  `savetime` bigint(20) unsigned NOT NULL default '0',
  `resettalents_cost` int(11) unsigned NOT NULL default '0',
  `resettalents_time` bigint(20) unsigned NOT NULL default '0',
  `ABData` longtext,
  `TeachSpelldata` longtext,
  PRIMARY KEY  (`id`),
  KEY `owner` (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

DROP TABLE IF EXISTS `pet_spell`;
CREATE TABLE `pet_spell` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `slot` int(11) unsigned NOT NULL default '0',
  `active` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

DROP TABLE IF EXISTS `pet_spell_cooldown`;
CREATE TABLE `pet_spell_cooldown` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `time` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pet_aura`;
CREATE TABLE `pet_aura` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0',
  `effect_index` int(11) unsigned NOT NULL default '0',
  `remaintime` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`,`effect_index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

-- ----------------------------
-- Table structure for petcreateinfo_spell
-- ----------------------------
DROP TABLE IF EXISTS `petcreateinfo_spell`;
CREATE TABLE `petcreateinfo_spell` (
  `entry` int(11) unsigned NOT NULL DEFAULT '0',
  `Spell1` int(11) unsigned NOT NULL DEFAULT '0',
  `Spell2` int(11) unsigned NOT NULL DEFAULT '0',
  `Spell3` int(11) unsigned NOT NULL DEFAULT '0',
  `Spell4` int(11) unsigned NOT NULL DEFAULT '0',
  `FamilyPassive` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet Create Spells';

ALTER TABLE `pet_levelstats` ADD `armor` int(10) unsigned NOT NULL default '0' AFTER `mana`;

INSERT INTO `spell_chain` VALUES ('17253', '0', '17253', '1');
INSERT INTO `spell_chain` VALUES ('17255', '17253', '17253', '2');
INSERT INTO `spell_chain` VALUES ('17256', '17255', '17253', '3');
INSERT INTO `spell_chain` VALUES ('17257', '17256', '17253', '4');
INSERT INTO `spell_chain` VALUES ('17258', '17257', '17253', '5');
INSERT INTO `spell_chain` VALUES ('17259', '17258', '17253', '6');
INSERT INTO `spell_chain` VALUES ('17260', '17259', '17253', '7');
INSERT INTO `spell_chain` VALUES ('17261', '17260', '17253', '8');
INSERT INTO `spell_chain` VALUES ('27050', '17261', '17253', '9');
INSERT INTO `spell_chain` VALUES ('16827', '0', '16827', '1');
INSERT INTO `spell_chain` VALUES ('16828', '16827', '16827', '2');
INSERT INTO `spell_chain` VALUES ('16829', '16828', '16827', '3');
INSERT INTO `spell_chain` VALUES ('16830', '16829', '16827', '4');
INSERT INTO `spell_chain` VALUES ('16831', '16830', '16827', '5');
INSERT INTO `spell_chain` VALUES ('16832', '16831', '16827', '6');
INSERT INTO `spell_chain` VALUES ('3010', '16832', '16827', '7');
INSERT INTO `spell_chain` VALUES ('3009', '3010', '16827', '8');
INSERT INTO `spell_chain` VALUES ('27049', '3009', '16827', '9');
INSERT INTO `spell_chain` VALUES ('1742', '0', '1742', '1');
INSERT INTO `spell_chain` VALUES ('1753', '1742', '1742', '2');
INSERT INTO `spell_chain` VALUES ('1754', '1753', '1742', '3');
INSERT INTO `spell_chain` VALUES ('1755', '1754', '1742', '4');
INSERT INTO `spell_chain` VALUES ('1756', '1755', '1742', '5');
INSERT INTO `spell_chain` VALUES ('16697', '1756', '1742', '6');
INSERT INTO `spell_chain` VALUES ('27048', '16697', '1742', '7');
INSERT INTO `spell_chain` VALUES ('23099', '0', '23099', '1');
INSERT INTO `spell_chain` VALUES ('23109', '23099', '23099', '2');
INSERT INTO `spell_chain` VALUES ('23110', '23109', '23099', '3');
INSERT INTO `spell_chain` VALUES ('23145', '0', '23145', '1');
INSERT INTO `spell_chain` VALUES ('23147', '23145', '23145', '2');
INSERT INTO `spell_chain` VALUES ('23148', '23147', '23145', '3');
INSERT INTO `spell_chain` VALUES ('2649', '0', '2649', '1');
INSERT INTO `spell_chain` VALUES ('14916', '2649', '2649', '2');
INSERT INTO `spell_chain` VALUES ('14917', '14916', '2649', '3');
INSERT INTO `spell_chain` VALUES ('14918', '14917', '2649', '4');
INSERT INTO `spell_chain` VALUES ('14919', '14918', '2649', '5');
INSERT INTO `spell_chain` VALUES ('14920', '14919', '2649', '6');
INSERT INTO `spell_chain` VALUES ('14921', '14920', '2649', '7');
INSERT INTO `spell_chain` VALUES ('27047', '14921', '2649', '8');
INSERT INTO `spell_chain` VALUES ('7371', '0', '7371', '1');
INSERT INTO `spell_chain` VALUES ('26177', '7371', '7371', '2');
INSERT INTO `spell_chain` VALUES ('26178', '26177', '7371', '3');
INSERT INTO `spell_chain` VALUES ('26179', '26178', '7371', '4');
INSERT INTO `spell_chain` VALUES ('26201', '26179', '7371', '5');
INSERT INTO `spell_chain` VALUES ('27685', '26201', '7371', '6');
INSERT INTO `spell_chain` VALUES ('24604', '0', '24604', '1');
INSERT INTO `spell_chain` VALUES ('24605', '24604', '24604', '2');
INSERT INTO `spell_chain` VALUES ('24603', '24605', '24604', '3');
INSERT INTO `spell_chain` VALUES ('24597', '24603', '24604', '4');
INSERT INTO `spell_chain` VALUES ('24844', '0', '24844', '1');
INSERT INTO `spell_chain` VALUES ('25008', '24844', '24844', '2');
INSERT INTO `spell_chain` VALUES ('25009', '25008', '24844', '3');
INSERT INTO `spell_chain` VALUES ('25010', '25009', '24844', '4');
INSERT INTO `spell_chain` VALUES ('25011', '25010', '24844', '5');
INSERT INTO `spell_chain` VALUES ('25012', '25011', '24844', '6');
INSERT INTO `spell_chain` VALUES ('24450', '0', '24450', '1');
INSERT INTO `spell_chain` VALUES ('24452', '24450', '24450', '2');
INSERT INTO `spell_chain` VALUES ('24453', '24452', '24450', '3');
INSERT INTO `spell_chain` VALUES ('24640', '0', '24640', '1');
INSERT INTO `spell_chain` VALUES ('24583', '24640', '24640', '2');
INSERT INTO `spell_chain` VALUES ('24586', '24583', '24640', '3');
INSERT INTO `spell_chain` VALUES ('24587', '24586', '24640', '4');
INSERT INTO `spell_chain` VALUES ('27060', '24587', '24640', '5');
INSERT INTO `spell_chain` VALUES ('24423', '0', '24423', '1');
INSERT INTO `spell_chain` VALUES ('24577', '24423', '24423', '2');
INSERT INTO `spell_chain` VALUES ('24578', '24577', '24423', '3');
INSERT INTO `spell_chain` VALUES ('24579', '24578', '24423', '4');
INSERT INTO `spell_chain` VALUES ('27051', '24579', '24423', '5');
INSERT INTO `spell_chain` VALUES ('26064', '0', '26064', '1');
INSERT INTO `spell_chain` VALUES ('26090', '0', '26090', '1');
INSERT INTO `spell_chain` VALUES ('26187', '26090', '26090', '2');
INSERT INTO `spell_chain` VALUES ('26188', '26187', '26090', '3');
INSERT INTO `spell_chain` VALUES ('27063', '26188', '26090', '4');
INSERT INTO `spell_chain` VALUES ('34889', '0', '34889', '1');
INSERT INTO `spell_chain` VALUES ('35323', '34889', '34889', '2');
INSERT INTO `spell_chain` VALUES ('35290', '0', '35290', '1');
INSERT INTO `spell_chain` VALUES ('35291', '35290', '35290', '2');
INSERT INTO `spell_chain` VALUES ('35292', '35291', '35290', '3');
INSERT INTO `spell_chain` VALUES ('35293', '35292', '35290', '4');
INSERT INTO `spell_chain` VALUES ('35294', '35293', '35290', '5');
INSERT INTO `spell_chain` VALUES ('35295', '35294', '35290', '6');
INSERT INTO `spell_chain` VALUES ('35296', '35295', '35290', '7');
INSERT INTO `spell_chain` VALUES ('35297', '35296', '35290', '8');
INSERT INTO `spell_chain` VALUES ('35298', '35297', '35290', '9');
INSERT INTO `spell_chain` VALUES ('35387', '0', '35387', '1');
INSERT INTO `spell_chain` VALUES ('35389', '35387', '35387', '2');
INSERT INTO `spell_chain` VALUES ('35392', '35389', '35387', '3');
INSERT INTO `spell_chain` VALUES ('35346', '0', '35346', '1');
INSERT INTO `spell_chain` VALUES ('25076', '0', '25076', '1');
INSERT INTO `spell_chain` VALUES ('35694', '0', '35694', '1');
INSERT INTO `spell_chain` VALUES ('35698', '35694', '35694', '2');
INSERT INTO `spell_chain` VALUES ('4187', '0', '4187', '1');
INSERT INTO `spell_chain` VALUES ('4188', '4187', '4187', '2');
INSERT INTO `spell_chain` VALUES ('4189', '4188', '4187', '3');
INSERT INTO `spell_chain` VALUES ('4190', '4189', '4187', '4');
INSERT INTO `spell_chain` VALUES ('4191', '4190', '4187', '5');
INSERT INTO `spell_chain` VALUES ('4192', '4191', '4187', '6');
INSERT INTO `spell_chain` VALUES ('4193', '4192', '4187', '7');
INSERT INTO `spell_chain` VALUES ('4194', '4193', '4187', '8');
INSERT INTO `spell_chain` VALUES ('5041', '4194', '4187', '9');
INSERT INTO `spell_chain` VALUES ('5042', '5041', '4187', '10');
INSERT INTO `spell_chain` VALUES ('27062', '5042', '4187', '11');
INSERT INTO `spell_chain` VALUES ('24545', '0', '24545', '1');
INSERT INTO `spell_chain` VALUES ('24549', '24545', '24545', '2');
INSERT INTO `spell_chain` VALUES ('24550', '24549', '24545', '3');
INSERT INTO `spell_chain` VALUES ('24551', '24550', '24545', '4');
INSERT INTO `spell_chain` VALUES ('24552', '24551', '24545', '5');
INSERT INTO `spell_chain` VALUES ('24553', '24552', '24545', '6');
INSERT INTO `spell_chain` VALUES ('24554', '24553', '24545', '7');
INSERT INTO `spell_chain` VALUES ('24555', '24554', '24545', '8');
INSERT INTO `spell_chain` VALUES ('24629', '24555', '24545', '9');
INSERT INTO `spell_chain` VALUES ('24630', '24629', '24545', '10');
INSERT INTO `spell_chain` VALUES ('27061', '24630', '24545', '11');
INSERT INTO `spell_chain` VALUES ('24493', '0', '24493', '1');
INSERT INTO `spell_chain` VALUES ('24497', '24493', '24493', '2');
INSERT INTO `spell_chain` VALUES ('24500', '24497', '24493', '3');
INSERT INTO `spell_chain` VALUES ('24501', '24500', '24493', '4');
INSERT INTO `spell_chain` VALUES ('27052', '24501', '24493', '5');
INSERT INTO `spell_chain` VALUES ('23992', '0', '23992', '1');
INSERT INTO `spell_chain` VALUES ('24439', '23992', '23992', '2');
INSERT INTO `spell_chain` VALUES ('24444', '24439', '23992', '3');
INSERT INTO `spell_chain` VALUES ('24445', '24444', '23992', '4');
INSERT INTO `spell_chain` VALUES ('27053', '24445', '23992', '5');
INSERT INTO `spell_chain` VALUES ('24446', '0', '24446', '1');
INSERT INTO `spell_chain` VALUES ('24447', '24446', '24446', '2');
INSERT INTO `spell_chain` VALUES ('24448', '24447', '24446', '3');
INSERT INTO `spell_chain` VALUES ('24449', '24448', '24446', '4');
INSERT INTO `spell_chain` VALUES ('27054', '24449', '24446', '5');
INSERT INTO `spell_chain` VALUES ('24492', '0', '24492', '1');
INSERT INTO `spell_chain` VALUES ('24502', '24492', '24492', '2');
INSERT INTO `spell_chain` VALUES ('24503', '24502', '24492', '3');
INSERT INTO `spell_chain` VALUES ('24504', '24503', '24492', '4');
INSERT INTO `spell_chain` VALUES ('27055', '24504', '24492', '5');
INSERT INTO `spell_chain` VALUES ('24488', '0', '24488', '1');
INSERT INTO `spell_chain` VALUES ('24505', '24488', '24488', '2');
INSERT INTO `spell_chain` VALUES ('24506', '24505', '24488', '3');
INSERT INTO `spell_chain` VALUES ('24507', '24506', '24488', '4');
INSERT INTO `spell_chain` VALUES ('27056', '24507', '24488', '5');
INSERT INTO `spell_chain` VALUES ('6307', '0', '6307', '1');
INSERT INTO `spell_chain` VALUES ('7804', '6307', '6307', '2');
INSERT INTO `spell_chain` VALUES ('7805', '7804', '6307', '3');
INSERT INTO `spell_chain` VALUES ('11766', '7805', '6307', '4');
INSERT INTO `spell_chain` VALUES ('11767', '11766', '6307', '5');
INSERT INTO `spell_chain` VALUES ('27268', '11767', '6307', '6');
INSERT INTO `spell_chain` VALUES ('2947', '0', '2947', '1');
INSERT INTO `spell_chain` VALUES ('8316', '2947', '2947', '2');
INSERT INTO `spell_chain` VALUES ('8317', '8316', '2947', '3');
INSERT INTO `spell_chain` VALUES ('11770', '8317', '2947', '4');
INSERT INTO `spell_chain` VALUES ('11771', '11770', '2947', '5');
INSERT INTO `spell_chain` VALUES ('27269', '11771', '2947', '6');
INSERT INTO `spell_chain` VALUES ('3110', '0', '3110', '1');
INSERT INTO `spell_chain` VALUES ('7799', '3110', '3110', '2');
INSERT INTO `spell_chain` VALUES ('7800', '7799', '3110', '3');
INSERT INTO `spell_chain` VALUES ('7801', '7800', '3110', '4');
INSERT INTO `spell_chain` VALUES ('7802', '7801', '3110', '5');
INSERT INTO `spell_chain` VALUES ('11762', '7802', '3110', '6');
INSERT INTO `spell_chain` VALUES ('11763', '11762', '3110', '7');
INSERT INTO `spell_chain` VALUES ('27267', '11763', '3110', '8');
INSERT INTO `spell_chain` VALUES ('17767', '0', '17767', '1');
INSERT INTO `spell_chain` VALUES ('17850', '17767', '17767', '2');
INSERT INTO `spell_chain` VALUES ('17851', '17850', '17767', '3');
INSERT INTO `spell_chain` VALUES ('17852', '17851', '17767', '4');
INSERT INTO `spell_chain` VALUES ('17853', '17852', '17767', '5');
INSERT INTO `spell_chain` VALUES ('17854', '17853', '17767', '6');
INSERT INTO `spell_chain` VALUES ('27272', '17854', '17767', '7');
INSERT INTO `spell_chain` VALUES ('7812', '0', '7812', '1');
INSERT INTO `spell_chain` VALUES ('19438', '7812', '7812', '2');
INSERT INTO `spell_chain` VALUES ('19440', '19438', '7812', '3');
INSERT INTO `spell_chain` VALUES ('19441', '19440', '7812', '4');
INSERT INTO `spell_chain` VALUES ('19442', '19441', '7812', '5');
INSERT INTO `spell_chain` VALUES ('19443', '19442', '7812', '6');
INSERT INTO `spell_chain` VALUES ('27273', '19443', '7812', '7');
INSERT INTO `spell_chain` VALUES ('17735', '0', '17735', '1');
INSERT INTO `spell_chain` VALUES ('17750', '17735', '17735', '2');
INSERT INTO `spell_chain` VALUES ('17751', '17750', '17735', '3');
INSERT INTO `spell_chain` VALUES ('17752', '17751', '17735', '4');
INSERT INTO `spell_chain` VALUES ('27271', '17752', '17735', '5');
INSERT INTO `spell_chain` VALUES ('33701', '27271', '17735', '6');
INSERT INTO `spell_chain` VALUES ('3716', '0', '3716', '1');
INSERT INTO `spell_chain` VALUES ('7809', '3716', '3716', '2');
INSERT INTO `spell_chain` VALUES ('7810', '7809', '3716', '3');
INSERT INTO `spell_chain` VALUES ('7811', '7810', '3716', '4');
INSERT INTO `spell_chain` VALUES ('11774', '7811', '3716', '5');
INSERT INTO `spell_chain` VALUES ('11775', '11774', '3716', '6');
INSERT INTO `spell_chain` VALUES ('27270', '11775', '3716', '7');
INSERT INTO `spell_chain` VALUES ('7814', '0', '7814', '1');
INSERT INTO `spell_chain` VALUES ('7815', '7814', '7814', '2');
INSERT INTO `spell_chain` VALUES ('7816', '7815', '7814', '3');
INSERT INTO `spell_chain` VALUES ('11778', '7816', '7814', '4');
INSERT INTO `spell_chain` VALUES ('11779', '11778', '7814', '5');
INSERT INTO `spell_chain` VALUES ('11780', '11779', '7814', '6');
INSERT INTO `spell_chain` VALUES ('27274', '11780', '7814', '7');
INSERT INTO `spell_chain` VALUES ('6360', '0', '6360', '1');
INSERT INTO `spell_chain` VALUES ('7813', '6360', '6360', '2');
INSERT INTO `spell_chain` VALUES ('11784', '7813', '6360', '3');
INSERT INTO `spell_chain` VALUES ('11785', '11784', '6360', '4');
INSERT INTO `spell_chain` VALUES ('27275', '11785', '6360', '5');
INSERT INTO `spell_chain` VALUES ('19505', '0', '19505', '1');
INSERT INTO `spell_chain` VALUES ('19731', '19505', '19505', '2');
INSERT INTO `spell_chain` VALUES ('19734', '19731', '19505', '3');
INSERT INTO `spell_chain` VALUES ('19736', '19734', '19505', '4');
INSERT INTO `spell_chain` VALUES ('27276', '19736', '19505', '5');
INSERT INTO `spell_chain` VALUES ('27277', '27276', '19505', '6');
INSERT INTO `spell_chain` VALUES ('19244', '0', '19244', '1');
INSERT INTO `spell_chain` VALUES ('19647', '19244', '19244', '2');
INSERT INTO `spell_chain` VALUES ('19478', '0', '19478', '1');
INSERT INTO `spell_chain` VALUES ('19655', '19478', '19478', '2');
INSERT INTO `spell_chain` VALUES ('19656', '19655', '19478', '3');
INSERT INTO `spell_chain` VALUES ('19660', '19656', '19478', '4');
INSERT INTO `spell_chain` VALUES ('27280', '19660', '19478', '5');
INSERT INTO `spell_chain` VALUES ('33698', '0', '33698', '1');
INSERT INTO `spell_chain` VALUES ('33699', '33698', '33698', '2');
INSERT INTO `spell_chain` VALUES ('33700', '33699', '33698', '3');
INSERT INTO `spell_chain` VALUES ('30213', '0', '30213', '1');
INSERT INTO `spell_chain` VALUES ('30219', '30213', '30213', '2');
INSERT INTO `spell_chain` VALUES ('30223', '30219', '30213', '3');
INSERT INTO `spell_chain` VALUES ('30151', '0', '30151', '1');
INSERT INTO `spell_chain` VALUES ('30194', '30151', '30151', '2');
INSERT INTO `spell_chain` VALUES ('30198', '30194', '30151', '3');
