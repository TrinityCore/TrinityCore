-- ----------------------------
-- Table structure for `mercenaries`
-- ----------------------------
DROP TABLE IF EXISTS `mercenaries`;
CREATE TABLE `mercenaries` (
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
  `ownerGUID` int(10) unsigned NOT NULL DEFAULT '0',
  `role` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `displayId` int(10) unsigned NOT NULL DEFAULT '0',
  `race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `gender` tinyint(3) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `summoned` tinyint(1) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`),
  KEY `ownerGUID` (`ownerGUID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Mercenary System';

-- ----------------------------
-- Table structure for `mercenary_gear`
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_gear`;
CREATE TABLE `mercenary_gear` (
  `guid` int(10) unsigned NOT NULL,
  `itemId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `slot` tinyint(3) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for `mercenary_spells`
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_spells`;
CREATE TABLE `mercenary_spells` (
  `type` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `role` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `spellId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `isDefaultAura` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `isActive` tinyint(1) NOT NULL DEFAULT '1',
  `comment` varchar(255) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of mercenary_spells
-- ----------------------------
INSERT INTO `mercenary_spells` VALUES ('1', '1', '78', '0', '1', 'Heroic Strike (Rank 1)');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '100', '0', '1', 'Charge (Rank 1)');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '2457', '1', '1', 'Battle Stance Aura');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '1715', '0', '1', 'Hamstring');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '772', '0', '1', 'Rend (Rank 1)');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '6343', '0', '1', 'Thunder Clap (Rank 1)');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '12294', '0', '1', 'Mortal Strike (Rank 1)');
INSERT INTO `mercenary_spells` VALUES ('1', '1', '46924', '0', '1', 'Bladestorm');

-- ----------------------------
-- Table structure for `mercenary_start_gear`
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_start_gear`;
CREATE TABLE `mercenary_start_gear` (
  `mercenaryType` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `mercenaryRole` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '72000',
  `headEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `shoulderEntry` mediumint(8) NOT NULL DEFAULT '0',
  `chestEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `legEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `handEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `feetEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `weaponEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `offHandEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `rangedEntry` mediumint(8) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of mercenary_start_gear
-- ----------------------------
INSERT INTO `mercenary_start_gear` VALUES ('1', '1', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('6', '2', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('2', '1', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('3', '2', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('4', '1', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('5', '2', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('7', '3', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('8', '0', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('9', '1', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('10', '2', '72000', '0', '0', '0', '6121', '0', '40', '25', '0', '0');
INSERT INTO `mercenary_start_gear` VALUES ('1', '1', '72001', '0', '0', '0', '6121', '0', '40', '25', '0', '0');

-- ----------------------------
-- Table structure for `mercenary_talk`
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_talk`;
CREATE TABLE `mercenary_talk` (
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `role` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `healthpct` smallint(5) NOT NULL DEFAULT '100',
  `message` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of mercenary_talk
-- ----------------------------
INSERT INTO `mercenary_talk` VALUES ('1', '1', '100', 'Wait! Did you hear that? Guess I\'m paranoid.');
INSERT INTO `mercenary_talk` VALUES ('1', '1', '100', 'Crush! Crush! I will crush you all with my skills!');
INSERT INTO `mercenary_talk` VALUES ('1', '1', '100', 'I\'d love some fresh meat.');

-- ----------------------------
-- Table structure for `mercenary_world`
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_world`;
CREATE TABLE `mercenary_world` (
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `modelId` mediumint(8) unsigned NOT NULL DEFAULT '49',
  `race` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `gender` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of mercenary_world
-- ----------------------------
INSERT INTO `mercenary_world` VALUES ('72001', '49', '1', '0');

-- ----------------------------
-- Table structure for mercenary_proficiencies
-- ----------------------------
DROP TABLE IF EXISTS `mercenary_proficiencies`;
CREATE TABLE `mercenary_proficiencies` (
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Mercenary Type',
  `armor_prof` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Armor Proficiency, Armor Subclass',
  `weapon_prof` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Weapon Proficiency, Item SubClass'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of mercenary_proficiencies
-- ----------------------------
INSERT INTO `mercenary_proficiencies` VALUES ('1', '4', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '4', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '4', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '3', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '3', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '2', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '2', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '1', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '1', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '1', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '1');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '5');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '6');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('1', '0', '8');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '0', '5');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '0', '8');
INSERT INTO `mercenary_proficiencies` VALUES ('2', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '0', '10');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '0', '19');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '1');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '5');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '6');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('4', '0', '8');
INSERT INTO `mercenary_proficiencies` VALUES ('3', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '0', '10');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '0', '19');
INSERT INTO `mercenary_proficiencies` VALUES ('5', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '0', '10');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '0', '19');
INSERT INTO `mercenary_proficiencies` VALUES ('6', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '5');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '6');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '10');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('7', '0', '17');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '2');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '3');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '6');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '13');
INSERT INTO `mercenary_proficiencies` VALUES ('8', '0', '18');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '0', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '0', '7');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '0', '13');
INSERT INTO `mercenary_proficiencies` VALUES ('9', '0', '15');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '0', '0');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '0', '4');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '0', '10');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '0', '13');
INSERT INTO `mercenary_proficiencies` VALUES ('10', '0', '15');
