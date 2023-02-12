/*
Navicat MySQL Data Transfer

Source Server         : TrinityCore-master
Source Server Version : 80011
Source Host           : localhost:3306
Source Database       : auth

Target Server Type    : MYSQL
Target Server Version : 80011
File Encoding         : 65001

Date: 2023-02-05 07:45:56
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `account`
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `salt` binary(32) NOT NULL,
  `verifier` binary(32) NOT NULL,
  `session_key_auth` binary(40) DEFAULT NULL,
  `session_key_bnet` varbinary(64) DEFAULT NULL,
  `totp_secret` varbinary(128) DEFAULT NULL,
  `email` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `reg_mail` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `last_attempt_ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '00',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '9',
  `mutetime` bigint(20) NOT NULL DEFAULT '0',
  `mutereason` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `muteby` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `recruiter` int(10) unsigned NOT NULL DEFAULT '0',
  `battlenet_account` int(10) unsigned DEFAULT NULL,
  `battlenet_index` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_username` (`username`),
  UNIQUE KEY `uk_bnet_acc` (`battlenet_account`,`battlenet_index`),
  CONSTRAINT `fk_bnet_acc` FOREIGN KEY (`battlenet_account`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Account System';

-- ----------------------------
-- Records of account
-- ----------------------------
INSERT INTO `account` VALUES ('1', '1#1', 0x0DDBF7DBA95E25E9C3495F93BD8B14A54A06E1009A47135FD2CB505341B740A5, 0x39C3209A504FBA2D836244593792F27DFDF2992996AFBB279A24488EB04D3789, null, 0x5BC682338FDC209697D2E993FBD5AD1EDEEF2F438E1EAB413EC0CBDB78CEB67B839BF6F9C39DE802, null, 'X@X', 'X@X', '2023-01-01 17:23:26', '192.168.0.198', '192.168.0.198', '0', '0', '00', '2023-02-03 18:10:45', '0', '9', '0', '', '', '4', 'Wn64', '0', '1', '1');
INSERT INTO `account` VALUES ('2', '2#1', 0xEECCBCB87681949204492A453207E75BC43A6731205BC841D573C8EB3E9288AA, 0xA458DF4B2C5622EAADCE163704A894C929CE4FB2F7985EE8AB48686FBD7B0440, null, null, null, 'WJCL@TEST.COM', 'WJCL@TEST.COM', '2023-01-30 14:49:43', '127.0.0.1', '127.0.0.1', '0', '0', '00', null, '0', '9', '0', '', '', '0', '', '0', '2', '1');
INSERT INTO `account` VALUES ('3', '3#1', 0xBE7644343266D410E20F4F23F21E7C7565182EAEA27855ADEC50CF1C16E762FA, 0x5A860CD569539479759DD2E6A5988E6812A55B3186EFF46D8B312D2BD9EE1478, null, null, null, 'TEST@TEST.COM', '', '2023-01-30 21:06:35', '127.0.0.1', '127.0.0.1', '0', '0', '00', null, '0', '7', '0', '', '', '0', '', '0', '3', '1');

-- ----------------------------
-- Table structure for `account_access`
-- ----------------------------
DROP TABLE IF EXISTS `account_access`;
CREATE TABLE `account_access` (
  `AccountID` int(10) unsigned NOT NULL,
  `SecurityLevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL DEFAULT '-1',
  `Comment` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`AccountID`,`RealmID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of account_access
-- ----------------------------
INSERT INTO `account_access` VALUES ('1', '3', '-1', null);

-- ----------------------------
-- Table structure for `account_banned`
-- ----------------------------
DROP TABLE IF EXISTS `account_banned`;
CREATE TABLE `account_banned` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `banreason` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Ban List';

-- ----------------------------
-- Records of account_banned
-- ----------------------------

-- ----------------------------
-- Table structure for `account_last_played_character`
-- ----------------------------
DROP TABLE IF EXISTS `account_last_played_character`;
CREATE TABLE `account_last_played_character` (
  `accountId` int(10) unsigned NOT NULL,
  `region` tinyint(3) unsigned NOT NULL,
  `battlegroup` tinyint(3) unsigned NOT NULL,
  `realmId` int(10) unsigned DEFAULT NULL,
  `characterName` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `characterGUID` bigint(20) unsigned DEFAULT NULL,
  `lastPlayedTime` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`accountId`,`region`,`battlegroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of account_last_played_character
-- ----------------------------
INSERT INTO `account_last_played_character` VALUES ('1', '1', '1', '1', '小女孩', '1', '1675420101');

-- ----------------------------
-- Table structure for `account_muted`
-- ----------------------------
DROP TABLE IF EXISTS `account_muted`;
CREATE TABLE `account_muted` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `mutedate` int(10) unsigned NOT NULL DEFAULT '0',
  `mutetime` int(10) unsigned NOT NULL DEFAULT '0',
  `mutedby` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `mutereason` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`guid`,`mutedate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='mute List';

-- ----------------------------
-- Records of account_muted
-- ----------------------------

-- ----------------------------
-- Table structure for `autobroadcast`
-- ----------------------------
DROP TABLE IF EXISTS `autobroadcast`;
CREATE TABLE `autobroadcast` (
  `realmid` int(11) NOT NULL DEFAULT '-1',
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) unsigned DEFAULT '1',
  `text` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of autobroadcast
-- ----------------------------

-- ----------------------------
-- Table structure for `battle_pet_declinedname`
-- ----------------------------
DROP TABLE IF EXISTS `battle_pet_declinedname`;
CREATE TABLE `battle_pet_declinedname` (
  `guid` bigint(20) NOT NULL,
  `genitive` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `dative` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `accusative` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `instrumental` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `prepositional` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`),
  CONSTRAINT `fk_battle_pet__battle_pet_declinedname` FOREIGN KEY (`guid`) REFERENCES `battle_pets` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battle_pet_declinedname
-- ----------------------------

-- ----------------------------
-- Table structure for `battle_pet_slots`
-- ----------------------------
DROP TABLE IF EXISTS `battle_pet_slots`;
CREATE TABLE `battle_pet_slots` (
  `id` tinyint(4) NOT NULL,
  `battlenetAccountId` int(11) NOT NULL,
  `battlePetGuid` bigint(20) NOT NULL,
  `locked` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`battlenetAccountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battle_pet_slots
-- ----------------------------
INSERT INTO `battle_pet_slots` VALUES ('0', '1', '1', '0');
INSERT INTO `battle_pet_slots` VALUES ('1', '1', '0', '1');
INSERT INTO `battle_pet_slots` VALUES ('2', '1', '0', '1');

-- ----------------------------
-- Table structure for `battle_pets`
-- ----------------------------
DROP TABLE IF EXISTS `battle_pets`;
CREATE TABLE `battle_pets` (
  `guid` bigint(20) NOT NULL,
  `battlenetAccountId` int(11) NOT NULL,
  `species` int(11) NOT NULL,
  `breed` smallint(6) NOT NULL,
  `displayId` int(11) NOT NULL DEFAULT '0',
  `level` smallint(6) NOT NULL DEFAULT '1',
  `exp` smallint(6) NOT NULL DEFAULT '0',
  `health` int(11) NOT NULL DEFAULT '1',
  `quality` tinyint(4) NOT NULL DEFAULT '0',
  `flags` smallint(6) NOT NULL DEFAULT '0',
  `name` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `nameTimestamp` bigint(20) NOT NULL DEFAULT '0',
  `owner` bigint(20) DEFAULT NULL,
  `ownerRealmId` int(11) DEFAULT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battle_pets
-- ----------------------------
INSERT INTO `battle_pets` VALUES ('1', '1', '68', '16', '4615', '1', '0', '160', '2', '0', '', '0', null, null);

-- ----------------------------
-- Table structure for `battlenet_account_bans`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_account_bans`;
CREATE TABLE `battlenet_account_bans` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `banreason` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Ban List';

-- ----------------------------
-- Records of battlenet_account_bans
-- ----------------------------

-- ----------------------------
-- Table structure for `battlenet_account_heirlooms`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_account_heirlooms`;
CREATE TABLE `battlenet_account_heirlooms` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_account_heirlooms
-- ----------------------------

-- ----------------------------
-- Table structure for `battlenet_account_mounts`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_account_mounts`;
CREATE TABLE `battlenet_account_mounts` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `mountSpellId` int(10) unsigned NOT NULL,
  `flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`mountSpellId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_account_mounts
-- ----------------------------
INSERT INTO `battlenet_account_mounts` VALUES ('1', '8394', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '10789', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '10793', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '23219', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '23221', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '23338', '0');
INSERT INTO `battlenet_account_mounts` VALUES ('1', '66847', '0');

-- ----------------------------
-- Table structure for `battlenet_account_toys`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_account_toys`;
CREATE TABLE `battlenet_account_toys` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(11) NOT NULL DEFAULT '0',
  `isFavourite` tinyint(1) DEFAULT '0',
  `hasFanfare` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_account_toys
-- ----------------------------

-- ----------------------------
-- Table structure for `battlenet_account_transmog_illusions`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_account_transmog_illusions`;
CREATE TABLE `battlenet_account_transmog_illusions` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `blobIndex` smallint(5) unsigned NOT NULL,
  `illusionMask` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`blobIndex`),
  CONSTRAINT `battlenet_account_transmog_illusions_ibfk_1` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_account_transmog_illusions
-- ----------------------------
INSERT INTO `battlenet_account_transmog_illusions` VALUES ('1', '0', '12591112');
INSERT INTO `battlenet_account_transmog_illusions` VALUES ('1', '1', '6148');
INSERT INTO `battlenet_account_transmog_illusions` VALUES ('1', '2', '7680');

-- ----------------------------
-- Table structure for `battlenet_accounts`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_accounts`;
CREATE TABLE `battlenet_accounts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `email` varchar(320) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `sha_pass_hash` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '00',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `LastCharacterUndelete` int(10) unsigned NOT NULL DEFAULT '0',
  `LoginTicket` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `LoginTicketExpiry` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Account System';

-- ----------------------------
-- Records of battlenet_accounts
-- ----------------------------
INSERT INTO `battlenet_accounts` VALUES ('1', 'X@X', '0838FBAF37B2EFE02C1F7541213FEB958B3025ADB6763BA0F1913951104310ED', '2023-01-01 17:23:26', '127.0.0.1', '0', '0', '00', '2023-02-03 18:10:45', '0', '4', 'Wn64', '0', 'TC-15C9339DFFCEEB3A38B4DE04D52CA8094568A4AD', '1675422645');
INSERT INTO `battlenet_accounts` VALUES ('2', 'WJCL@TEST.COM', 'DA654689A31E589A7F02B95F3B28A2705286FF07C328D77F153E89BF89B4891C', '2023-01-30 14:49:43', '127.0.0.1', '0', '0', '00', null, '0', '0', '', '0', null, null);
INSERT INTO `battlenet_accounts` VALUES ('3', 'TEST@TEST.COM', '20B97C807E2462ED4370AE2DB8601D8F9CB8E724F6E78983CB85E01D4E0FA122', '2023-01-30 21:06:35', '127.0.0.1', '0', '0', '00', null, '0', '0', '', '0', null, null);

-- ----------------------------
-- Table structure for `battlenet_item_appearances`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_item_appearances`;
CREATE TABLE `battlenet_item_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `blobIndex` smallint(5) unsigned NOT NULL,
  `appearanceMask` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`blobIndex`),
  CONSTRAINT `fk_battlenet_item_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_item_appearances
-- ----------------------------
INSERT INTO `battlenet_item_appearances` VALUES ('1', '18', '4');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '32', '12');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '54', '134217728');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '55', '64');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '66', '1073741824');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '69', '1048576');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '77', '2048');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '96', '64');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '161', '2048');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '203', '528384');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '309', '134219776');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '315', '134217728');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '321', '4');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '333', '3');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '379', '33554432');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '380', '4');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '654', '33554432');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '687', '65536');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '1015', '2048');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '1064', '1073741824');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2376', '3');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2377', '256');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2416', '2147483648');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2417', '3');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2600', '12');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2631', '2147483648');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2913', '8');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '2947', '134217728');
INSERT INTO `battlenet_item_appearances` VALUES ('1', '3268', '469762048');

-- ----------------------------
-- Table structure for `battlenet_item_favorite_appearances`
-- ----------------------------
DROP TABLE IF EXISTS `battlenet_item_favorite_appearances`;
CREATE TABLE `battlenet_item_favorite_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `itemModifiedAppearanceId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`battlenetAccountId`,`itemModifiedAppearanceId`),
  CONSTRAINT `fk_battlenet_item_favorite_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of battlenet_item_favorite_appearances
-- ----------------------------

-- ----------------------------
-- Table structure for `build_info`
-- ----------------------------
DROP TABLE IF EXISTS `build_info`;
CREATE TABLE `build_info` (
  `build` int(11) NOT NULL,
  `majorVersion` int(11) DEFAULT NULL,
  `minorVersion` int(11) DEFAULT NULL,
  `bugfixVersion` int(11) DEFAULT NULL,
  `hotfixVersion` char(3) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `winAuthSeed` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `win64AuthSeed` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `mac64AuthSeed` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `winChecksumSeed` varchar(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `macChecksumSeed` varchar(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`build`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of build_info
-- ----------------------------
INSERT INTO `build_info` VALUES ('5875', '1', '12', '1', null, null, null, null, '95EDB27C7823B363CBDDAB56A392E7CB73FCCA20', '8D173CC381961EEBABF336F5E6675B101BB513E5');
INSERT INTO `build_info` VALUES ('6005', '1', '12', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('6141', '1', '12', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('8606', '2', '4', '3', null, null, null, null, '319AFAA3F2559682F9FF658BE01456255F456FB1', 'D8B0ECFE534BC1131E19BAD1D4C0E813EEE4994F');
INSERT INTO `build_info` VALUES ('9947', '3', '1', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('10505', '3', '2', '2', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('11159', '3', '3', '0', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('11403', '3', '3', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('11723', '3', '3', '3', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('12340', '3', '3', '5', 'a', null, null, null, 'CDCBBD5188315E6B4D19449D492DBCFAF156A347', 'B706D13FF2F4018839729461E3F8A0E2B5FDC034');
INSERT INTO `build_info` VALUES ('13623', '4', '0', '6', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('13930', '3', '3', '5', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('14545', '4', '2', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('15595', '4', '3', '4', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19116', '6', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19243', '6', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19342', '6', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19702', '6', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19802', '6', '1', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19831', '6', '1', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('19865', '6', '1', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20182', '6', '2', '0', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20201', '6', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20216', '6', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20253', '6', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20338', '6', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20444', '6', '2', '2', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20490', '6', '2', '2', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20574', '6', '2', '2', 'a', null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20726', '6', '2', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20779', '6', '2', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('20886', '6', '2', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('21355', '6', '2', '4', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('21463', '6', '2', '4', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('21742', '6', '2', '4', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22248', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22293', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22345', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22410', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22423', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22498', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22522', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22566', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22594', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22624', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22747', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22810', '7', '0', '3', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22900', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22908', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22950', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22995', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('22996', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23171', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23222', '7', '1', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23360', '7', '1', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23420', '7', '1', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23911', '7', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('23937', '7', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24015', '7', '2', '0', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24330', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24367', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24415', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24430', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24461', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('24742', '7', '2', '5', null, null, null, null, null, null);
INSERT INTO `build_info` VALUES ('25549', '7', '3', '2', null, 'FE594FC35E7F9AFF86D99D8A364AB297', '1252624ED8CBD6FAC7D33F5D67A535F3', '66FC5E09B8706126795F140308C8C1D8', null, null);
INSERT INTO `build_info` VALUES ('25996', '7', '3', '5', null, '23C59C5963CBEF5B728D13A50878DFCB', 'C7FF932D6A2174A3D538CA7212136D2B', '210B970149D6F56CAC9BADF2AAC91E8E', null, null);
INSERT INTO `build_info` VALUES ('26124', '7', '3', '5', null, 'F8C05AE372DECA1D6C81DA7A8D1C5C39', '46DF06D0147BA67BA49AF553435E093F', 'C9CA997AB8EDE1C65465CB2920869C4E', null, null);
INSERT INTO `build_info` VALUES ('26365', '7', '3', '5', null, '2AAC82C80E829E2CA902D70CFA1A833A', '59A53F307288454B419B13E694DF503C', 'DBE7F860276D6B400AAA86B35D51A417', null, null);
INSERT INTO `build_info` VALUES ('26654', '7', '3', '5', null, 'FAC2D693E702B9EC9F750F17245696D8', 'A752640E8B99FE5B57C1320BC492895A', '9234C1BD5E9687ADBD19F764F2E0E811', null, null);
INSERT INTO `build_info` VALUES ('26822', '7', '3', '5', null, '283E8D77ECF7060BE6347BE4EB99C7C7', '2B05F6D746C0C6CC7EF79450B309E595', '91003668C245D14ECD8DF094E065E06B', null, null);
INSERT INTO `build_info` VALUES ('26899', '7', '3', '5', null, 'F462CD2FE4EA3EADF875308FDBB18C99', '3551EF0028B51E92170559BD25644B03', '8368EFC2021329110A16339D298200D4', null, null);
INSERT INTO `build_info` VALUES ('26972', '7', '3', '5', null, '797ECC19662DCBD5090A4481173F1D26', '6E212DEF6A0124A3D9AD07F5E322F7AE', '341CFEFE3D72ACA9A4407DC535DED66A', null, null);
INSERT INTO `build_info` VALUES ('28153', '8', '0', '1', null, null, 'DD626517CC6D31932B479934CCDC0ABF', null, null, null);
INSERT INTO `build_info` VALUES ('30706', '8', '1', '5', null, null, 'BB6D9866FE4A19A568015198783003FC', null, null, null);
INSERT INTO `build_info` VALUES ('30993', '8', '2', '0', null, null, '2BAD61655ABC2FC3D04893B536403A91', null, null, null);
INSERT INTO `build_info` VALUES ('31229', '8', '2', '0', null, null, '8A46F23670309F2AAE85C9A47276382B', null, null, null);
INSERT INTO `build_info` VALUES ('31429', '8', '2', '0', null, null, '7795A507AF9DC3525EFF724FEE17E70C', null, null, null);
INSERT INTO `build_info` VALUES ('31478', '8', '2', '0', null, null, '7973A8D54BDB8B798D9297B096E771EF', null, null, null);
INSERT INTO `build_info` VALUES ('32305', '8', '2', '5', null, null, '21F5A6FC7AD89FBF411FDA8B8738186A', null, null, null);
INSERT INTO `build_info` VALUES ('32494', '8', '2', '5', null, null, '58984ACE04919401835C61309A848F8A', null, null, null);
INSERT INTO `build_info` VALUES ('32580', '8', '2', '5', null, null, '87C2FAA0D7931BF016299025C0DDCA14', null, null, null);
INSERT INTO `build_info` VALUES ('32638', '8', '2', '5', null, null, '5D07ECE7D4A867DDDE615DAD22B76D4E', null, null, null);
INSERT INTO `build_info` VALUES ('32722', '8', '2', '5', null, null, '1A09BE1D38A122586B4931BECCEAD4AA', null, null, null);
INSERT INTO `build_info` VALUES ('32750', '8', '2', '5', null, null, 'C5CB669F5A5B237D1355430877173207', 'EF1F4E4D099EA2A81FD4C0DEBC1E7086', null, null);
INSERT INTO `build_info` VALUES ('32978', '8', '2', '5', null, null, '76AE2EA03E525D97F5688843F5489000', '1852C1F847E795D6EB45278CD433F339', null, null);
INSERT INTO `build_info` VALUES ('33369', '8', '3', '0', null, null, '5986AC18B04D3C403F56A0CF8C4F0A14', 'F5A849C70A1054F07EA3AB833EBF6671', null, null);
INSERT INTO `build_info` VALUES ('33528', '8', '3', '0', null, null, '0ECE033CA9B11D92F7D2792C785B47DF', null, null, null);
INSERT INTO `build_info` VALUES ('33724', '8', '3', '0', null, null, '38F7BBCF284939DD20E8C64CDBF9FE77', null, null, null);
INSERT INTO `build_info` VALUES ('33775', '8', '3', '0', null, null, 'B826300A8449ED0F6EF16EA747FA2D2E', '354D2DE619D124EE1398F76B0436FCFC', null, null);
INSERT INTO `build_info` VALUES ('33941', '8', '3', '0', null, null, '88AF1A36D2770D0A6CA086497096A889', null, null, null);
INSERT INTO `build_info` VALUES ('34220', '8', '3', '0', null, null, 'B5E35B976C6BAF82505700E7D9666A2C', null, null, null);
INSERT INTO `build_info` VALUES ('34601', '8', '3', '0', null, null, '0D7DF38F725FABA4F009257799A10563', null, null, null);
INSERT INTO `build_info` VALUES ('34769', '8', '3', '0', null, null, '93F9B9AF6397E3E4EED94D36D16907D2', null, null, null);
INSERT INTO `build_info` VALUES ('34963', '8', '3', '0', null, null, '7BA50C879C5D04221423B02AC3603A11', 'C5658A17E702163447BAAAE46D130A1B', null, null);
INSERT INTO `build_info` VALUES ('35249', '8', '3', '7', null, null, 'C7B11F9AE9FF1409F5582902B3D10D1C', null, null, null);
INSERT INTO `build_info` VALUES ('35284', '8', '3', '7', null, null, 'EA3818E7DCFD2009DBFC83EE3C1E4F1B', 'A6201B0AC5A73D13AB2FDCC79BB252AF', null, null);
INSERT INTO `build_info` VALUES ('35435', '8', '3', '7', null, null, 'BB397A92FE23740EA52FC2B5BA2EC8E0', '8FE657C14A46BCDB2CE6DA37E430450E', null, null);
INSERT INTO `build_info` VALUES ('35662', '8', '3', '7', null, null, '578BC94870C278CB6962F30E6DC203BB', '5966016C368ED9F7AAB603EE6703081C', null, null);
INSERT INTO `build_info` VALUES ('36753', '9', '0', '2', null, null, '386FDE8559B5EAD67B791B490B200B88', null, null, null);
INSERT INTO `build_info` VALUES ('36839', '9', '0', '2', null, null, '356EB4412B8EFCF72E3AF50D5181D529', null, null, null);
INSERT INTO `build_info` VALUES ('36949', '9', '0', '2', null, null, '51C074CD8A09A75384B9B44188C56981', null, null, null);
INSERT INTO `build_info` VALUES ('37142', '9', '0', '2', null, null, '5D9CFB3139F0D1B6C2B304261F9EABC9', null, null, null);
INSERT INTO `build_info` VALUES ('37176', '9', '0', '2', null, null, '3C725EA504EC3DAED143EB6FF3B48CDA', null, null, null);
INSERT INTO `build_info` VALUES ('37474', '9', '0', '2', null, null, '0DE685BBB0551086E7FBDC0B4BB06A5B', '024C9BE7E44237B7E81C6D42E678D433', null, null);
INSERT INTO `build_info` VALUES ('38134', '9', '0', '5', null, null, '32275ED0F13B357C28BDB0E611EF9E31', null, null, null);
INSERT INTO `build_info` VALUES ('38556', '9', '0', '5', null, null, 'EC7D5AF64364AC3E7181F3FBA1B3A882', null, null, null);
INSERT INTO `build_info` VALUES ('39653', '9', '1', '0', null, null, '10D015AB1EEB91310428D9C57EE24632', null, null, null);
INSERT INTO `build_info` VALUES ('39804', '9', '1', '0', null, null, 'E42D2BBA12ED260A76F9B1E477E19EA5', null, null, null);
INSERT INTO `build_info` VALUES ('40000', '9', '1', '0', null, null, '4CB1433AB637F09F03FBBD1B221B04B0', null, null, null);
INSERT INTO `build_info` VALUES ('40120', '9', '1', '0', null, null, '04F47EAEFD8BDEFE14AA0350EA336678', '853F0F2985CEAED46DF422583CD07A7C', null, null);
INSERT INTO `build_info` VALUES ('40443', '9', '1', '0', null, null, '8597BB43E8AB38C85504E8BFB72ABBF5', null, null, null);
INSERT INTO `build_info` VALUES ('40593', '9', '1', '0', null, null, 'BA14570F2D62D5F61953394164A8DAE2', null, null, null);
INSERT INTO `build_info` VALUES ('40725', '9', '1', '0', null, null, 'C1EBDBEB9BB2956EBCCEF7C9D27A1B3B', null, null, null);
INSERT INTO `build_info` VALUES ('40906', '9', '1', '5', null, null, 'F5FC259C8635488AFE0D0CD023F361D4', null, null, null);
INSERT INTO `build_info` VALUES ('40944', '9', '1', '5', null, null, '368FC7FABAF487A8A049C11970657074', null, null, null);
INSERT INTO `build_info` VALUES ('40966', '9', '1', '5', null, null, 'D90F47AF21F381D2D8F3763B994BAC88', null, null, null);
INSERT INTO `build_info` VALUES ('41031', '9', '1', '5', null, null, '019A0FACD6B0D6374B7BA69A5B677449', null, null, null);
INSERT INTO `build_info` VALUES ('41079', '9', '1', '5', null, null, 'F8853CF823BC0BBE8A9677A762DFAEE1', null, null, null);
INSERT INTO `build_info` VALUES ('41288', '9', '1', '5', null, null, '871C0C9691DBC536EB24B68EC73FAD5B', null, null, null);
INSERT INTO `build_info` VALUES ('41323', '9', '1', '5', null, null, 'E53D0DF1FAC1A59A1C8071B295A04A1D', null, null, null);
INSERT INTO `build_info` VALUES ('41359', '9', '1', '5', null, null, '5F8D7F2A690A4375A1B52A28D6D681FA', null, null, null);
INSERT INTO `build_info` VALUES ('41488', '9', '1', '5', null, null, '1BC91EC368705815F3F532B553DAD981', null, null, null);
INSERT INTO `build_info` VALUES ('41793', '9', '1', '5', null, null, 'B3B47DA3B7615570742A55B96614EE1C', null, null, null);
INSERT INTO `build_info` VALUES ('42010', '9', '1', '5', null, null, '302970161D16417B5BE553CC530E011A', null, null, null);
INSERT INTO `build_info` VALUES ('42423', '9', '2', '0', null, null, '0B03614A7E94DD57548596BE420E9DC2', null, null, null);
INSERT INTO `build_info` VALUES ('42488', '9', '2', '0', null, null, 'A78755E6928D83A271C5D1EE3CDB6F15', null, null, null);
INSERT INTO `build_info` VALUES ('42521', '9', '2', '0', null, null, '5FE6C12FC407C6B15B4A5D3B5B4A5D3B', null, null, null);
INSERT INTO `build_info` VALUES ('42538', '9', '2', '0', null, null, '71A7504BD53F8DE518F24265D37310AE', null, null, null);
INSERT INTO `build_info` VALUES ('42560', '9', '2', '0', null, null, '115FE8C38A8D67CA4664BB192E0F0DFE', null, null, null);
INSERT INTO `build_info` VALUES ('42614', '9', '2', '0', null, null, '772BE726FEEF42124255D2EA7973CA18', null, null, null);
INSERT INTO `build_info` VALUES ('42698', '9', '2', '0', null, null, 'B4497B1CD11FC974C5FB09548AC27269', null, null, null);
INSERT INTO `build_info` VALUES ('42825', '9', '2', '0', null, null, 'A14DA228C6A6AFF1DDBA51218939E557', null, null, null);
INSERT INTO `build_info` VALUES ('42852', '9', '2', '0', null, null, 'DE9F9F0C3CC8FD54D3AFF99CEFFCE129', null, null, null);
INSERT INTO `build_info` VALUES ('42937', '9', '2', '0', null, null, 'F5FC75E70874752C92846B3333920E63', null, null, null);
INSERT INTO `build_info` VALUES ('42979', '9', '2', '0', null, null, 'E1DD38AE6450FC4D2AE4609233C59E54', null, null, null);
INSERT INTO `build_info` VALUES ('43114', '9', '2', '0', null, null, 'F75C9380CCB24A48A24EEE52C1594A7E', null, null, null);
INSERT INTO `build_info` VALUES ('43206', '9', '2', '0', null, null, 'DDE806532C7704FFB75F256DC5F1F3D9', null, null, null);
INSERT INTO `build_info` VALUES ('43340', '9', '2', '0', null, null, '70E46D2D888E84DF9316EA849B068CF4', null, null, null);
INSERT INTO `build_info` VALUES ('43345', '9', '2', '0', null, null, 'D911ABFCDA030DEE8CAF4EE3F60DEE13', null, null, null);
INSERT INTO `build_info` VALUES ('43971', '9', '2', '5', null, null, '681CF99E61FB0005A5C7D31D0AAD1ED9', null, null, null);
INSERT INTO `build_info` VALUES ('44015', '9', '2', '5', null, null, 'FCF0BDA7C98BFEF92AE6D8C39A217ABD', null, null, null);
INSERT INTO `build_info` VALUES ('44061', '9', '2', '5', null, null, 'FD2B5C0B3293FE0E9CAA6EB0B7788119', null, null, null);
INSERT INTO `build_info` VALUES ('44127', '9', '2', '5', null, null, '787887CEC9FCC9B516481F60E4FC34A8', null, null, null);
INSERT INTO `build_info` VALUES ('44232', '9', '2', '5', null, null, '81F0A71DF7E9873BB3750022D64D33CF', null, null, null);
INSERT INTO `build_info` VALUES ('44325', '9', '2', '5', null, null, '138A7D524D268A7F9934C3D148E8F01B', null, null, null);
INSERT INTO `build_info` VALUES ('44730', '9', '2', '5', null, null, 'FC0B18C47BB4C79F4300CA0FF3E5CAC7', null, null, null);
INSERT INTO `build_info` VALUES ('44908', '9', '2', '5', null, null, 'BFFAEC40C9BCD591C7C959A9D5A8BA8C', null, null, null);
INSERT INTO `build_info` VALUES ('45114', '9', '2', '7', null, null, 'D7AFE240BD00F06C30D0C2D16E54A8BE', null, null, null);
INSERT INTO `build_info` VALUES ('45161', '9', '2', '7', null, null, '74BD2E787A98B145B063BDA9A98F6CBD', null, null, null);
INSERT INTO `build_info` VALUES ('45338', '9', '2', '7', null, null, '5CE2094A41B61EDA9DF56378BC3B1DE0', null, null, null);
INSERT INTO `build_info` VALUES ('45745', '9', '2', '7', null, null, '0F6DC90161694D765A595A3AF603166B', null, null, null);
INSERT INTO `build_info` VALUES ('46479', '10', '0', '2', null, null, 'CB9AF4D89B60A3ABA288D395D315D932', null, null, null);
INSERT INTO `build_info` VALUES ('46658', '10', '0', '2', null, null, '3F8EFB085428D75360E9EFE25CD8639A', null, null, null);
INSERT INTO `build_info` VALUES ('46689', '10', '0', '2', null, null, 'D9A11D188D6AD60906F5467510EFD3AA', null, null, null);
INSERT INTO `build_info` VALUES ('46702', '10', '0', '2', null, null, '01B4D1688FF97DC9AAFCCD0A0B842C0B', null, null, null);
INSERT INTO `build_info` VALUES ('46741', '10', '0', '2', null, null, '4C0F4A7EC2098AF1FBA745848EC79A78', null, null, null);
INSERT INTO `build_info` VALUES ('46801', '10', '0', '2', null, null, 'E6AC18D1EA5D36ABFFAE5EDED80630DF', null, null, null);
INSERT INTO `build_info` VALUES ('46879', '10', '0', '2', null, null, 'EFEC43936051DD1A210633AF1F6B63DB', null, null, null);
INSERT INTO `build_info` VALUES ('46924', '10', '0', '2', null, null, 'E6CE0B1A8119F069ECF1E7DBAA7BB2F8', null, null, null);
INSERT INTO `build_info` VALUES ('47067', '10', '0', '2', null, null, '63862CFCDEA6BD2BD7F740EB36B65657', null, null, null);
INSERT INTO `build_info` VALUES ('47187', '10', '0', '2', null, null, '711F8455C5000C237292E1E6E90631E1', null, null, null);
INSERT INTO `build_info` VALUES ('47213', '10', '0', '2', null, null, '23C50D88CEAC0A8696ADDE8DD244D4A2', null, null, null);
INSERT INTO `build_info` VALUES ('47631', '10', '0', '2', null, null, 'F986AB91D0AEB20822EFB72F4256713C', null, null, null);
INSERT INTO `build_info` VALUES ('47657', '10', '0', '2', null, null, '179D3DC3235629D07113A9B3867F97A7', null, null, null);
INSERT INTO `build_info` VALUES ('47777', '10', '0', '5', null, null, 'A88C04915AB9E035A104E55C4DCF5F9F', null, null, null);
INSERT INTO `build_info` VALUES ('47799', '10', '0', '5', null, null, '7364EB093C23DB2CDC9513D5A7B4933E', null, null, null);
INSERT INTO `build_info` VALUES ('47825', '10', '0', '5', null, null, '82A3B94E5E727AF3A208B471FF2054C0', null, null, null);
INSERT INTO `build_info` VALUES ('47849', '10', '0', '5', null, null, 'DD8BBE2087A28C0AF4984CBE23A1C707', null, null, null);
INSERT INTO `build_info` VALUES ('47871', '10', '0', '5', null, null, '8E4F7D30EE4982B02B3B3F8837C2C4F2', null, null, null);
INSERT INTO `build_info` VALUES ('47884', '10', '0', '5', null, null, '2B7A002BC359F2C31104BC2DE04302BF', null, null, null);
INSERT INTO `build_info` VALUES ('47936', '10', '0', '5', null, null, '833D30D8FBC43B3FAE99CD3898D70849', null, null, null);

-- ----------------------------
-- Table structure for `ip_banned`
-- ----------------------------
DROP TABLE IF EXISTS `ip_banned`;
CREATE TABLE `ip_banned` (
  `ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `bandate` int(10) unsigned NOT NULL,
  `unbandate` int(10) unsigned NOT NULL,
  `bannedby` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '[Console]',
  `banreason` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'no reason',
  PRIMARY KEY (`ip`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Banned IPs';

-- ----------------------------
-- Records of ip_banned
-- ----------------------------

-- ----------------------------
-- Table structure for `logs`
-- ----------------------------
DROP TABLE IF EXISTS `logs`;
CREATE TABLE `logs` (
  `time` int(10) unsigned NOT NULL,
  `realm` int(10) unsigned NOT NULL,
  `type` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `string` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of logs
-- ----------------------------

-- ----------------------------
-- Table structure for `logs_ip_actions`
-- ----------------------------
DROP TABLE IF EXISTS `logs_ip_actions`;
CREATE TABLE `logs_ip_actions` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique Identifier',
  `account_id` int(10) unsigned NOT NULL COMMENT 'Account ID',
  `character_guid` bigint(20) unsigned NOT NULL COMMENT 'Character Guid',
  `realm_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Realm ID',
  `type` tinyint(3) unsigned NOT NULL,
  `ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `systemnote` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci COMMENT 'Notes inserted by system',
  `unixtime` int(10) unsigned NOT NULL COMMENT 'Unixtime',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Timestamp',
  `comment` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci COMMENT 'Allows users to add a comment',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Used to log ips of individual actions';

-- ----------------------------
-- Records of logs_ip_actions
-- ----------------------------

-- ----------------------------
-- Table structure for `rbac_account_permissions`
-- ----------------------------
DROP TABLE IF EXISTS `rbac_account_permissions`;
CREATE TABLE `rbac_account_permissions` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `granted` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`permissionId`,`realmId`),
  KEY `fk__rbac_account_roles__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__rbac_account_permissions__account` FOREIGN KEY (`accountId`) REFERENCES `account` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_account_roles__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Account-Permission relation';

-- ----------------------------
-- Records of rbac_account_permissions
-- ----------------------------

-- ----------------------------
-- Table structure for `rbac_default_permissions`
-- ----------------------------
DROP TABLE IF EXISTS `rbac_default_permissions`;
CREATE TABLE `rbac_default_permissions` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'permission id',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`secId`,`permissionId`,`realmId`),
  KEY `fk__rbac_default_permissions__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__rbac_default_permissions__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Default permission to assign to different account security levels';

-- ----------------------------
-- Records of rbac_default_permissions
-- ----------------------------
INSERT INTO `rbac_default_permissions` VALUES ('3', '192', '-1');
INSERT INTO `rbac_default_permissions` VALUES ('2', '193', '-1');
INSERT INTO `rbac_default_permissions` VALUES ('1', '194', '-1');
INSERT INTO `rbac_default_permissions` VALUES ('0', '195', '-1');

-- ----------------------------
-- Table structure for `rbac_linked_permissions`
-- ----------------------------
DROP TABLE IF EXISTS `rbac_linked_permissions`;
CREATE TABLE `rbac_linked_permissions` (
  `id` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `linkedId` int(10) unsigned NOT NULL COMMENT 'Linked Permission id',
  PRIMARY KEY (`id`,`linkedId`),
  KEY `fk__rbac_linked_permissions__rbac_permissions1` (`id`),
  KEY `fk__rbac_linked_permissions__rbac_permissions2` (`linkedId`),
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions1` FOREIGN KEY (`id`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions2` FOREIGN KEY (`linkedId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Permission - Linked Permission relation';

-- ----------------------------
-- Records of rbac_linked_permissions
-- ----------------------------
INSERT INTO `rbac_linked_permissions` VALUES ('192', '21');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '42');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '43');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '193');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '196');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '776');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '778');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '779');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '780');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '781');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '782');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '783');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '784');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '785');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '786');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '787');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '788');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '789');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '790');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '791');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '792');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '793');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '794');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '835');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '844');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '845');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '846');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '847');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '848');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '849');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '850');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '851');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '853');
INSERT INTO `rbac_linked_permissions` VALUES ('192', '854');
INSERT INTO `rbac_linked_permissions` VALUES ('193', '48');
INSERT INTO `rbac_linked_permissions` VALUES ('193', '194');
INSERT INTO `rbac_linked_permissions` VALUES ('193', '197');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '1');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '2');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '9');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '11');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '12');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '13');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '14');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '15');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '16');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '17');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '18');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '19');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '20');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '22');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '23');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '25');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '26');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '27');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '28');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '29');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '30');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '31');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '32');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '33');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '34');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '35');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '36');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '37');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '38');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '39');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '40');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '41');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '44');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '46');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '47');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '51');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '195');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '198');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '632');
INSERT INTO `rbac_linked_permissions` VALUES ('194', '798');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '3');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '4');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '5');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '6');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '24');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '49');
INSERT INTO `rbac_linked_permissions` VALUES ('195', '199');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '7');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '10');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '202');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '203');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '204');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '205');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '206');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '208');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '212');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '213');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '214');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '215');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '216');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '226');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '227');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '230');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '231');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '233');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '234');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '235');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '238');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '239');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '240');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '241');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '242');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '243');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '244');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '245');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '246');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '247');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '248');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '249');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '250');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '251');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '252');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '253');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '254');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '255');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '256');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '257');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '258');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '259');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '260');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '261');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '262');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '264');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '265');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '266');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '267');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '268');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '269');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '270');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '271');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '272');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '279');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '280');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '283');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '287');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '288');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '289');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '290');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '291');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '292');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '293');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '294');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '295');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '296');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '297');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '298');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '299');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '302');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '303');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '304');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '305');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '306');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '309');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '310');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '314');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '319');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '320');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '321');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '322');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '323');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '324');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '325');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '326');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '327');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '328');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '329');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '330');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '331');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '335');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '336');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '337');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '339');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '340');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '341');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '342');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '343');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '344');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '345');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '346');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '347');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '348');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '349');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '350');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '351');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '352');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '353');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '354');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '355');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '356');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '357');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '358');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '359');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '360');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '361');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '362');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '363');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '364');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '365');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '366');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '373');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '375');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '400');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '401');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '402');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '403');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '404');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '405');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '406');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '407');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '417');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '418');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '419');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '420');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '421');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '422');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '423');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '424');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '425');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '426');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '427');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '428');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '429');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '434');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '435');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '436');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '437');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '438');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '439');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '440');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '441');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '442');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '443');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '444');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '445');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '446');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '447');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '448');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '449');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '450');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '451');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '452');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '453');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '454');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '455');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '456');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '457');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '458');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '459');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '461');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '463');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '464');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '465');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '472');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '473');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '474');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '475');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '476');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '477');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '478');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '488');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '489');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '491');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '492');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '493');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '495');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '497');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '498');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '499');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '500');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '502');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '503');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '505');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '508');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '511');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '513');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '514');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '516');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '519');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '522');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '523');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '526');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '527');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '529');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '530');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '533');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '535');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '536');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '537');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '538');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '539');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '540');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '541');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '556');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '581');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '582');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '592');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '593');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '596');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '602');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '603');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '604');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '605');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '606');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '607');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '608');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '609');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '610');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '611');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '612');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '613');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '615');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '616');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '617');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '618');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '619');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '620');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '621');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '623');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '624');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '625');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '626');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '627');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '628');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '629');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '630');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '631');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '633');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '634');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '635');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '636');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '637');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '638');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '639');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '640');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '641');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '642');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '643');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '644');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '645');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '646');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '647');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '648');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '649');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '650');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '651');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '652');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '653');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '654');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '655');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '656');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '657');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '658');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '659');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '660');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '661');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '663');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '665');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '666');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '667');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '668');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '669');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '670');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '671');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '672');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '673');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '674');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '675');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '676');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '677');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '678');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '679');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '680');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '681');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '682');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '683');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '684');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '685');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '686');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '687');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '688');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '689');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '690');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '691');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '693');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '694');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '695');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '696');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '697');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '698');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '699');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '700');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '701');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '702');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '703');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '704');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '706');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '707');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '708');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '709');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '710');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '711');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '712');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '713');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '714');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '715');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '716');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '717');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '718');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '719');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '721');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '722');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '723');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '724');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '725');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '726');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '727');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '728');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '729');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '730');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '733');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '734');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '735');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '736');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '738');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '739');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '753');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '757');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '773');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '777');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '809');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '817');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '825');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '829');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '830');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '831');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '832');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '833');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '836');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '837');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '838');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '839');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '840');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '842');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '843');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '852');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '866');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '869');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '870');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '871');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '872');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '873');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '875');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '876');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '877');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '878');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '879');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '881');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '882');
INSERT INTO `rbac_linked_permissions` VALUES ('196', '883');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '232');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '236');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '237');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '273');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '274');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '275');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '276');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '277');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '284');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '285');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '286');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '301');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '311');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '387');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '388');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '389');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '390');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '391');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '392');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '393');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '394');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '395');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '396');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '397');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '398');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '399');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '479');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '480');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '481');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '482');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '485');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '486');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '487');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '494');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '501');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '506');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '509');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '510');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '517');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '518');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '521');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '542');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '543');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '550');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '558');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '568');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '571');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '572');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '573');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '574');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '575');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '576');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '577');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '578');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '579');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '580');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '583');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '584');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '585');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '586');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '587');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '588');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '589');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '590');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '591');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '594');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '595');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '601');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '761');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '762');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '763');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '764');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '765');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '766');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '767');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '768');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '769');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '770');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '771');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '772');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '774');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '775');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '805');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '811');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '813');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '819');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '821');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '827');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '856');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '857');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '858');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '859');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '860');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '865');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '1398');
INSERT INTO `rbac_linked_permissions` VALUES ('197', '1589');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '218');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '300');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '312');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '315');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '316');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '317');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '318');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '367');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '368');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '369');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '370');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '371');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '372');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '374');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '376');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '377');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '408');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '409');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '410');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '411');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '412');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '413');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '414');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '415');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '430');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '431');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '432');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '433');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '462');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '466');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '467');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '468');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '469');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '470');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '471');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '483');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '484');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '490');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '504');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '512');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '515');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '520');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '524');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '528');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '531');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '532');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '544');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '545');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '547');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '548');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '549');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '551');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '552');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '553');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '554');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '555');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '557');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '559');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '560');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '561');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '562');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '563');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '564');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '565');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '566');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '567');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '569');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '570');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '597');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '598');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '599');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '600');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '737');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '740');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '741');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '742');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '802');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '803');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '804');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '806');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '807');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '808');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '810');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '812');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '814');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '815');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '816');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '818');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '820');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '822');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '823');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '824');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '826');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '828');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '855');
INSERT INTO `rbac_linked_permissions` VALUES ('198', '868');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '207');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '209');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '210');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '211');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '217');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '221');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '222');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '223');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '225');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '263');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '378');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '379');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '380');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '496');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '507');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '525');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '534');
INSERT INTO `rbac_linked_permissions` VALUES ('199', '797');

-- ----------------------------
-- Table structure for `rbac_permissions`
-- ----------------------------
DROP TABLE IF EXISTS `rbac_permissions`;
CREATE TABLE `rbac_permissions` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Permission id',
  `name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Permission name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Permission List';

-- ----------------------------
-- Records of rbac_permissions
-- ----------------------------
INSERT INTO `rbac_permissions` VALUES ('1', 'Instant logout');
INSERT INTO `rbac_permissions` VALUES ('2', 'Skip Queue');
INSERT INTO `rbac_permissions` VALUES ('3', 'Join Normal Battleground');
INSERT INTO `rbac_permissions` VALUES ('4', 'Join Random Battleground');
INSERT INTO `rbac_permissions` VALUES ('5', 'Join Arenas');
INSERT INTO `rbac_permissions` VALUES ('6', 'Join Dungeon Finder');
INSERT INTO `rbac_permissions` VALUES ('7', 'Skip idle connection check');
INSERT INTO `rbac_permissions` VALUES ('8', 'Cannot earn achievements');
INSERT INTO `rbac_permissions` VALUES ('9', 'Cannot earn realm first achievements');
INSERT INTO `rbac_permissions` VALUES ('10', 'Use character templates');
INSERT INTO `rbac_permissions` VALUES ('11', 'Log GM trades');
INSERT INTO `rbac_permissions` VALUES ('12', 'Skip character creation demon hunter min level check');
INSERT INTO `rbac_permissions` VALUES ('13', 'Skip Instance required bosses check');
INSERT INTO `rbac_permissions` VALUES ('14', 'Skip character creation team mask check');
INSERT INTO `rbac_permissions` VALUES ('15', 'Skip character creation class mask check');
INSERT INTO `rbac_permissions` VALUES ('16', 'Skip character creation race mask check');
INSERT INTO `rbac_permissions` VALUES ('17', 'Skip character creation reserved name check');
INSERT INTO `rbac_permissions` VALUES ('18', 'Skip character creation death knight min level check');
INSERT INTO `rbac_permissions` VALUES ('19', 'Skip needed requirements to use channel check');
INSERT INTO `rbac_permissions` VALUES ('20', 'Skip disable map check');
INSERT INTO `rbac_permissions` VALUES ('21', 'Skip reset talents when used more than allowed check');
INSERT INTO `rbac_permissions` VALUES ('22', 'Skip spam chat check');
INSERT INTO `rbac_permissions` VALUES ('23', 'Skip over-speed ping check');
INSERT INTO `rbac_permissions` VALUES ('24', 'Two side faction characters on the same account');
INSERT INTO `rbac_permissions` VALUES ('25', 'Allow say chat between factions');
INSERT INTO `rbac_permissions` VALUES ('26', 'Allow channel chat between factions');
INSERT INTO `rbac_permissions` VALUES ('27', 'Two side mail interaction');
INSERT INTO `rbac_permissions` VALUES ('28', 'See two side who list');
INSERT INTO `rbac_permissions` VALUES ('29', 'Add friends of other faction');
INSERT INTO `rbac_permissions` VALUES ('30', 'Save character without delay with .save command');
INSERT INTO `rbac_permissions` VALUES ('31', 'Use params with .unstuck command');
INSERT INTO `rbac_permissions` VALUES ('32', 'Can be assigned tickets with .assign ticket command');
INSERT INTO `rbac_permissions` VALUES ('33', 'Notify if a command was not found');
INSERT INTO `rbac_permissions` VALUES ('34', 'Check if should appear in list using .gm ingame command');
INSERT INTO `rbac_permissions` VALUES ('35', 'See all security levels with who command');
INSERT INTO `rbac_permissions` VALUES ('36', 'Filter whispers');
INSERT INTO `rbac_permissions` VALUES ('37', 'Use staff badge in chat');
INSERT INTO `rbac_permissions` VALUES ('38', 'Resurrect with full Health Points');
INSERT INTO `rbac_permissions` VALUES ('39', 'Restore saved gm setting states');
INSERT INTO `rbac_permissions` VALUES ('40', 'Allows to add a gm to friend list');
INSERT INTO `rbac_permissions` VALUES ('41', 'Use Config option START_GM_LEVEL to assign new character level');
INSERT INTO `rbac_permissions` VALUES ('42', 'Allows to use CMSG_WORLD_TELEPORT opcode');
INSERT INTO `rbac_permissions` VALUES ('43', 'Allows to use CMSG_WHOIS opcode');
INSERT INTO `rbac_permissions` VALUES ('44', 'Receive global GM messages/texts');
INSERT INTO `rbac_permissions` VALUES ('45', 'Join channels without announce');
INSERT INTO `rbac_permissions` VALUES ('46', 'Change channel settings without being channel moderator');
INSERT INTO `rbac_permissions` VALUES ('47', 'Enables lower security than target check');
INSERT INTO `rbac_permissions` VALUES ('48', 'Enable IP, Last Login and EMail output in pinfo');
INSERT INTO `rbac_permissions` VALUES ('49', 'Forces to enter the email for confirmation on password change');
INSERT INTO `rbac_permissions` VALUES ('50', 'Allow user to check his own email with .account');
INSERT INTO `rbac_permissions` VALUES ('51', 'Allow trading between factions');
INSERT INTO `rbac_permissions` VALUES ('192', 'Role: Sec Level Administrator');
INSERT INTO `rbac_permissions` VALUES ('193', 'Role: Sec Level Gamemaster');
INSERT INTO `rbac_permissions` VALUES ('194', 'Role: Sec Level Moderator');
INSERT INTO `rbac_permissions` VALUES ('195', 'Role: Sec Level Player');
INSERT INTO `rbac_permissions` VALUES ('196', 'Role: Administrator Commands');
INSERT INTO `rbac_permissions` VALUES ('197', 'Role: Gamemaster Commands');
INSERT INTO `rbac_permissions` VALUES ('198', 'Role: Moderator Commands');
INSERT INTO `rbac_permissions` VALUES ('199', 'Role: Player Commands');
INSERT INTO `rbac_permissions` VALUES ('200', 'Command: rbac');
INSERT INTO `rbac_permissions` VALUES ('201', 'Command: rbac account');
INSERT INTO `rbac_permissions` VALUES ('202', 'Command: rbac account list');
INSERT INTO `rbac_permissions` VALUES ('203', 'Command: rbac account grant');
INSERT INTO `rbac_permissions` VALUES ('204', 'Command: rbac account deny');
INSERT INTO `rbac_permissions` VALUES ('205', 'Command: rbac account revoke');
INSERT INTO `rbac_permissions` VALUES ('206', 'Command: rbac list');
INSERT INTO `rbac_permissions` VALUES ('207', 'Command: battlenetaccount');
INSERT INTO `rbac_permissions` VALUES ('208', 'Command: battlenetaccount create');
INSERT INTO `rbac_permissions` VALUES ('209', 'Command: battlenetaccount lock country');
INSERT INTO `rbac_permissions` VALUES ('210', 'Command: battlenetaccount lock ip');
INSERT INTO `rbac_permissions` VALUES ('211', 'Command: battlenetaccount password');
INSERT INTO `rbac_permissions` VALUES ('212', 'Command: battlenetaccount set');
INSERT INTO `rbac_permissions` VALUES ('213', 'Command: battlenetaccount set password');
INSERT INTO `rbac_permissions` VALUES ('214', 'Command: bnetaccount link');
INSERT INTO `rbac_permissions` VALUES ('215', 'Command: bnetaccount unlink');
INSERT INTO `rbac_permissions` VALUES ('216', 'Command: bnetaccount gameaccountcreate');
INSERT INTO `rbac_permissions` VALUES ('217', 'Command: account');
INSERT INTO `rbac_permissions` VALUES ('218', 'Command: account addon');
INSERT INTO `rbac_permissions` VALUES ('219', 'Command: account create');
INSERT INTO `rbac_permissions` VALUES ('220', 'Command: account delete');
INSERT INTO `rbac_permissions` VALUES ('221', 'Command: account lock');
INSERT INTO `rbac_permissions` VALUES ('222', 'Command: account lock country');
INSERT INTO `rbac_permissions` VALUES ('223', 'Command: account lock ip');
INSERT INTO `rbac_permissions` VALUES ('224', 'Command: account onlinelist');
INSERT INTO `rbac_permissions` VALUES ('225', 'Command: account password');
INSERT INTO `rbac_permissions` VALUES ('226', 'Command: account set');
INSERT INTO `rbac_permissions` VALUES ('227', 'Command: account set addon');
INSERT INTO `rbac_permissions` VALUES ('228', 'Command: account set gmlevel');
INSERT INTO `rbac_permissions` VALUES ('229', 'Command: account set password');
INSERT INTO `rbac_permissions` VALUES ('230', 'Command: achievement');
INSERT INTO `rbac_permissions` VALUES ('231', 'Command: achievement add');
INSERT INTO `rbac_permissions` VALUES ('232', 'Command: arena');
INSERT INTO `rbac_permissions` VALUES ('233', 'Command: arena captain');
INSERT INTO `rbac_permissions` VALUES ('234', 'Command: arena create');
INSERT INTO `rbac_permissions` VALUES ('235', 'Command: arena disband');
INSERT INTO `rbac_permissions` VALUES ('236', 'Command: arena info');
INSERT INTO `rbac_permissions` VALUES ('237', 'Command: arena lookup');
INSERT INTO `rbac_permissions` VALUES ('238', 'Command: arena rename');
INSERT INTO `rbac_permissions` VALUES ('239', 'Command: ban');
INSERT INTO `rbac_permissions` VALUES ('240', 'Command: ban account');
INSERT INTO `rbac_permissions` VALUES ('241', 'Command: ban character');
INSERT INTO `rbac_permissions` VALUES ('242', 'Command: ban ip');
INSERT INTO `rbac_permissions` VALUES ('243', 'Command: ban playeraccount');
INSERT INTO `rbac_permissions` VALUES ('244', 'Command: baninfo');
INSERT INTO `rbac_permissions` VALUES ('245', 'Command: baninfo account');
INSERT INTO `rbac_permissions` VALUES ('246', 'Command: baninfo character');
INSERT INTO `rbac_permissions` VALUES ('247', 'Command: baninfo ip');
INSERT INTO `rbac_permissions` VALUES ('248', 'Command: banlist');
INSERT INTO `rbac_permissions` VALUES ('249', 'Command: banlist account');
INSERT INTO `rbac_permissions` VALUES ('250', 'Command: banlist character');
INSERT INTO `rbac_permissions` VALUES ('251', 'Command: banlist ip');
INSERT INTO `rbac_permissions` VALUES ('252', 'Command: unban');
INSERT INTO `rbac_permissions` VALUES ('253', 'Command: unban account');
INSERT INTO `rbac_permissions` VALUES ('254', 'Command: unban character');
INSERT INTO `rbac_permissions` VALUES ('255', 'Command: unban ip');
INSERT INTO `rbac_permissions` VALUES ('256', 'Command: unban playeraccount');
INSERT INTO `rbac_permissions` VALUES ('257', 'Command: bf');
INSERT INTO `rbac_permissions` VALUES ('258', 'Command: bf start');
INSERT INTO `rbac_permissions` VALUES ('259', 'Command: bf stop');
INSERT INTO `rbac_permissions` VALUES ('260', 'Command: bf switch');
INSERT INTO `rbac_permissions` VALUES ('261', 'Command: bf timer');
INSERT INTO `rbac_permissions` VALUES ('262', 'Command: bf enable');
INSERT INTO `rbac_permissions` VALUES ('263', 'Command: account email');
INSERT INTO `rbac_permissions` VALUES ('264', 'Command: account set sec');
INSERT INTO `rbac_permissions` VALUES ('265', 'Command: account set sec email');
INSERT INTO `rbac_permissions` VALUES ('266', 'Command: account set sec regmail');
INSERT INTO `rbac_permissions` VALUES ('267', 'Command: cast');
INSERT INTO `rbac_permissions` VALUES ('268', 'Command: cast back');
INSERT INTO `rbac_permissions` VALUES ('269', 'Command: cast dist');
INSERT INTO `rbac_permissions` VALUES ('270', 'Command: cast self');
INSERT INTO `rbac_permissions` VALUES ('271', 'Command: cast target');
INSERT INTO `rbac_permissions` VALUES ('272', 'Command: cast dest');
INSERT INTO `rbac_permissions` VALUES ('273', 'Command: character');
INSERT INTO `rbac_permissions` VALUES ('274', 'Command: character customize');
INSERT INTO `rbac_permissions` VALUES ('275', 'Command: character changefaction');
INSERT INTO `rbac_permissions` VALUES ('276', 'Command: character changerace');
INSERT INTO `rbac_permissions` VALUES ('277', 'Command: character deleted');
INSERT INTO `rbac_permissions` VALUES ('279', 'Command: character deleted list');
INSERT INTO `rbac_permissions` VALUES ('280', 'Command: character deleted restore');
INSERT INTO `rbac_permissions` VALUES ('283', 'Command: character level');
INSERT INTO `rbac_permissions` VALUES ('284', 'Command: character rename');
INSERT INTO `rbac_permissions` VALUES ('285', 'Command: character reputation');
INSERT INTO `rbac_permissions` VALUES ('286', 'Command: character titles');
INSERT INTO `rbac_permissions` VALUES ('287', 'Command: levelup');
INSERT INTO `rbac_permissions` VALUES ('288', 'Command: pdump');
INSERT INTO `rbac_permissions` VALUES ('289', 'Command: pdump load');
INSERT INTO `rbac_permissions` VALUES ('290', 'Command: pdump write');
INSERT INTO `rbac_permissions` VALUES ('291', 'Command: cheat');
INSERT INTO `rbac_permissions` VALUES ('292', 'Command: cheat casttime');
INSERT INTO `rbac_permissions` VALUES ('293', 'Command: cheat cooldown');
INSERT INTO `rbac_permissions` VALUES ('294', 'Command: cheat explore');
INSERT INTO `rbac_permissions` VALUES ('295', 'Command: cheat god');
INSERT INTO `rbac_permissions` VALUES ('296', 'Command: cheat power');
INSERT INTO `rbac_permissions` VALUES ('297', 'Command: cheat status');
INSERT INTO `rbac_permissions` VALUES ('298', 'Command: cheat taxi');
INSERT INTO `rbac_permissions` VALUES ('299', 'Command: cheat waterwalk');
INSERT INTO `rbac_permissions` VALUES ('300', 'Command: debug');
INSERT INTO `rbac_permissions` VALUES ('301', 'Command: debug anim');
INSERT INTO `rbac_permissions` VALUES ('302', 'Command: debug areatriggers');
INSERT INTO `rbac_permissions` VALUES ('303', 'Command: debug arena');
INSERT INTO `rbac_permissions` VALUES ('304', 'Command: debug bg');
INSERT INTO `rbac_permissions` VALUES ('305', 'Command: debug entervehicle');
INSERT INTO `rbac_permissions` VALUES ('306', 'Command: debug getitemstate');
INSERT INTO `rbac_permissions` VALUES ('309', 'Command: debug combat');
INSERT INTO `rbac_permissions` VALUES ('310', 'Command: debug itemexpire');
INSERT INTO `rbac_permissions` VALUES ('311', 'Command: debug lootrecipient');
INSERT INTO `rbac_permissions` VALUES ('312', 'Command: debug los');
INSERT INTO `rbac_permissions` VALUES ('314', 'Command: debug moveflags');
INSERT INTO `rbac_permissions` VALUES ('315', 'Command: debug play');
INSERT INTO `rbac_permissions` VALUES ('316', 'Command: debug play cinematics');
INSERT INTO `rbac_permissions` VALUES ('317', 'Command: debug play movie');
INSERT INTO `rbac_permissions` VALUES ('318', 'Command: debug play sound');
INSERT INTO `rbac_permissions` VALUES ('319', 'Command: debug send');
INSERT INTO `rbac_permissions` VALUES ('320', 'Command: debug send buyerror');
INSERT INTO `rbac_permissions` VALUES ('321', 'Command: debug send channelnotify');
INSERT INTO `rbac_permissions` VALUES ('322', 'Command: debug send chatmessage');
INSERT INTO `rbac_permissions` VALUES ('323', 'Command: debug send equiperror');
INSERT INTO `rbac_permissions` VALUES ('324', 'Command: debug send largepacket');
INSERT INTO `rbac_permissions` VALUES ('325', 'Command: debug send opcode');
INSERT INTO `rbac_permissions` VALUES ('326', 'Command: debug send qinvalidmsg');
INSERT INTO `rbac_permissions` VALUES ('327', 'Command: debug send qpartymsg');
INSERT INTO `rbac_permissions` VALUES ('328', 'Command: debug send sellerror');
INSERT INTO `rbac_permissions` VALUES ('329', 'Command: debug send setphaseshift');
INSERT INTO `rbac_permissions` VALUES ('330', 'Command: debug send spellfail');
INSERT INTO `rbac_permissions` VALUES ('331', 'Command: debug setaurastate');
INSERT INTO `rbac_permissions` VALUES ('335', 'Command: debug setvid');
INSERT INTO `rbac_permissions` VALUES ('336', 'Command: debug spawnvehicle');
INSERT INTO `rbac_permissions` VALUES ('337', 'Command: debug threat');
INSERT INTO `rbac_permissions` VALUES ('339', 'Command: debug worldstate');
INSERT INTO `rbac_permissions` VALUES ('340', 'Command: wpgps');
INSERT INTO `rbac_permissions` VALUES ('341', 'Command: deserter');
INSERT INTO `rbac_permissions` VALUES ('342', 'Command: deserter bg');
INSERT INTO `rbac_permissions` VALUES ('343', 'Command: deserter bg add');
INSERT INTO `rbac_permissions` VALUES ('344', 'Command: deserter bg remove');
INSERT INTO `rbac_permissions` VALUES ('345', 'Command: deserter instance');
INSERT INTO `rbac_permissions` VALUES ('346', 'Command: deserter instance add');
INSERT INTO `rbac_permissions` VALUES ('347', 'Command: deserter instance remove');
INSERT INTO `rbac_permissions` VALUES ('348', 'Command: disable');
INSERT INTO `rbac_permissions` VALUES ('349', 'Command: disable add');
INSERT INTO `rbac_permissions` VALUES ('350', 'Command: disable add criteria');
INSERT INTO `rbac_permissions` VALUES ('351', 'Command: disable add battleground');
INSERT INTO `rbac_permissions` VALUES ('352', 'Command: disable add map');
INSERT INTO `rbac_permissions` VALUES ('353', 'Command: disable add mmap');
INSERT INTO `rbac_permissions` VALUES ('354', 'Command: disable add outdoorpvp');
INSERT INTO `rbac_permissions` VALUES ('355', 'Command: disable add quest');
INSERT INTO `rbac_permissions` VALUES ('356', 'Command: disable add spell');
INSERT INTO `rbac_permissions` VALUES ('357', 'Command: disable add vmap');
INSERT INTO `rbac_permissions` VALUES ('358', 'Command: disable remove');
INSERT INTO `rbac_permissions` VALUES ('359', 'Command: disable remove criteria');
INSERT INTO `rbac_permissions` VALUES ('360', 'Command: disable remove battleground');
INSERT INTO `rbac_permissions` VALUES ('361', 'Command: disable remove map');
INSERT INTO `rbac_permissions` VALUES ('362', 'Command: disable remove mmap');
INSERT INTO `rbac_permissions` VALUES ('363', 'Command: disable remove outdoorpvp');
INSERT INTO `rbac_permissions` VALUES ('364', 'Command: disable remove quest');
INSERT INTO `rbac_permissions` VALUES ('365', 'Command: disable remove spell');
INSERT INTO `rbac_permissions` VALUES ('366', 'Command: disable remove vmap');
INSERT INTO `rbac_permissions` VALUES ('367', 'Command: event info');
INSERT INTO `rbac_permissions` VALUES ('368', 'Command: event activelist');
INSERT INTO `rbac_permissions` VALUES ('369', 'Command: event start');
INSERT INTO `rbac_permissions` VALUES ('370', 'Command: event stop');
INSERT INTO `rbac_permissions` VALUES ('371', 'Command: gm');
INSERT INTO `rbac_permissions` VALUES ('372', 'Command: gm chat');
INSERT INTO `rbac_permissions` VALUES ('373', 'Command: gm fly');
INSERT INTO `rbac_permissions` VALUES ('374', 'Command: gm ingame');
INSERT INTO `rbac_permissions` VALUES ('375', 'Command: gm list');
INSERT INTO `rbac_permissions` VALUES ('376', 'Command: gm visible');
INSERT INTO `rbac_permissions` VALUES ('377', 'Command: go');
INSERT INTO `rbac_permissions` VALUES ('378', 'Command: account 2fa');
INSERT INTO `rbac_permissions` VALUES ('379', 'Command: account 2fa setup');
INSERT INTO `rbac_permissions` VALUES ('380', 'Command: account 2fa remove');
INSERT INTO `rbac_permissions` VALUES ('381', 'Command: account set 2fa');
INSERT INTO `rbac_permissions` VALUES ('387', 'Command: gobject');
INSERT INTO `rbac_permissions` VALUES ('388', 'Command: gobject activate');
INSERT INTO `rbac_permissions` VALUES ('389', 'Command: gobject add');
INSERT INTO `rbac_permissions` VALUES ('390', 'Command: gobject add temp');
INSERT INTO `rbac_permissions` VALUES ('391', 'Command: gobject delete');
INSERT INTO `rbac_permissions` VALUES ('392', 'Command: gobject info');
INSERT INTO `rbac_permissions` VALUES ('393', 'Command: gobject move');
INSERT INTO `rbac_permissions` VALUES ('394', 'Command: gobject near');
INSERT INTO `rbac_permissions` VALUES ('395', 'Command: gobject set');
INSERT INTO `rbac_permissions` VALUES ('396', 'Command: gobject set phase');
INSERT INTO `rbac_permissions` VALUES ('397', 'Command: gobject set state');
INSERT INTO `rbac_permissions` VALUES ('398', 'Command: gobject target');
INSERT INTO `rbac_permissions` VALUES ('399', 'Command: gobject turn');
INSERT INTO `rbac_permissions` VALUES ('400', 'debug transport');
INSERT INTO `rbac_permissions` VALUES ('401', 'Command: guild');
INSERT INTO `rbac_permissions` VALUES ('402', 'Command: guild create');
INSERT INTO `rbac_permissions` VALUES ('403', 'Command: guild delete');
INSERT INTO `rbac_permissions` VALUES ('404', 'Command: guild invite');
INSERT INTO `rbac_permissions` VALUES ('405', 'Command: guild uninvite');
INSERT INTO `rbac_permissions` VALUES ('406', 'Command: guild rank');
INSERT INTO `rbac_permissions` VALUES ('407', 'Command: guild rename');
INSERT INTO `rbac_permissions` VALUES ('408', 'Command: honor');
INSERT INTO `rbac_permissions` VALUES ('409', 'Command: honor add');
INSERT INTO `rbac_permissions` VALUES ('410', 'Command: honor add kill');
INSERT INTO `rbac_permissions` VALUES ('411', 'Command: honor update');
INSERT INTO `rbac_permissions` VALUES ('412', 'Command: instance');
INSERT INTO `rbac_permissions` VALUES ('413', 'Command: instance listbinds');
INSERT INTO `rbac_permissions` VALUES ('414', 'Command: instance unbind');
INSERT INTO `rbac_permissions` VALUES ('415', 'Command: instance stats');
INSERT INTO `rbac_permissions` VALUES ('417', 'Command: learn');
INSERT INTO `rbac_permissions` VALUES ('418', 'Command: learn all');
INSERT INTO `rbac_permissions` VALUES ('419', 'Command: learn all my');
INSERT INTO `rbac_permissions` VALUES ('420', 'Command: learn all my class');
INSERT INTO `rbac_permissions` VALUES ('421', 'Command: learn all my pettalents');
INSERT INTO `rbac_permissions` VALUES ('422', 'Command: learn all my spells');
INSERT INTO `rbac_permissions` VALUES ('423', 'Command: learn all my talents');
INSERT INTO `rbac_permissions` VALUES ('424', 'Command: learn all gm');
INSERT INTO `rbac_permissions` VALUES ('425', 'Command: learn all crafts');
INSERT INTO `rbac_permissions` VALUES ('426', 'Command: learn all default');
INSERT INTO `rbac_permissions` VALUES ('427', 'Command: learn all lang');
INSERT INTO `rbac_permissions` VALUES ('428', 'Command: learn all recipes');
INSERT INTO `rbac_permissions` VALUES ('429', 'Command: unlearn');
INSERT INTO `rbac_permissions` VALUES ('430', 'Command: lfg');
INSERT INTO `rbac_permissions` VALUES ('431', 'Command: lfg player');
INSERT INTO `rbac_permissions` VALUES ('432', 'Command: lfg group');
INSERT INTO `rbac_permissions` VALUES ('433', 'Command: lfg queue');
INSERT INTO `rbac_permissions` VALUES ('434', 'Command: lfg clean');
INSERT INTO `rbac_permissions` VALUES ('435', 'Command: lfg options');
INSERT INTO `rbac_permissions` VALUES ('436', 'Command: list');
INSERT INTO `rbac_permissions` VALUES ('437', 'Command: list creature');
INSERT INTO `rbac_permissions` VALUES ('438', 'Command: list item');
INSERT INTO `rbac_permissions` VALUES ('439', 'Command: list object');
INSERT INTO `rbac_permissions` VALUES ('440', 'Command: list auras');
INSERT INTO `rbac_permissions` VALUES ('441', 'Command: list mail');
INSERT INTO `rbac_permissions` VALUES ('442', 'Command: lookup');
INSERT INTO `rbac_permissions` VALUES ('443', 'Command: lookup area');
INSERT INTO `rbac_permissions` VALUES ('444', 'Command: lookup creature');
INSERT INTO `rbac_permissions` VALUES ('445', 'Command: lookup event');
INSERT INTO `rbac_permissions` VALUES ('446', 'Command: lookup faction');
INSERT INTO `rbac_permissions` VALUES ('447', 'Command: lookup item');
INSERT INTO `rbac_permissions` VALUES ('448', 'Command: lookup itemset');
INSERT INTO `rbac_permissions` VALUES ('449', 'Command: lookup object');
INSERT INTO `rbac_permissions` VALUES ('450', 'Command: lookup quest');
INSERT INTO `rbac_permissions` VALUES ('451', 'Command: lookup player');
INSERT INTO `rbac_permissions` VALUES ('452', 'Command: lookup player ip');
INSERT INTO `rbac_permissions` VALUES ('453', 'Command: lookup player account');
INSERT INTO `rbac_permissions` VALUES ('454', 'Command: lookup player email');
INSERT INTO `rbac_permissions` VALUES ('455', 'Command: lookup skill');
INSERT INTO `rbac_permissions` VALUES ('456', 'Command: lookup spell');
INSERT INTO `rbac_permissions` VALUES ('457', 'Command: lookup spell id');
INSERT INTO `rbac_permissions` VALUES ('458', 'Command: lookup taxinode');
INSERT INTO `rbac_permissions` VALUES ('459', 'Command: lookup tele');
INSERT INTO `rbac_permissions` VALUES ('460', 'Command: lookup title');
INSERT INTO `rbac_permissions` VALUES ('461', 'Command: lookup map');
INSERT INTO `rbac_permissions` VALUES ('462', 'Command: announce');
INSERT INTO `rbac_permissions` VALUES ('463', 'Command: channel');
INSERT INTO `rbac_permissions` VALUES ('464', 'Command: channel set');
INSERT INTO `rbac_permissions` VALUES ('465', 'Command: channel set ownership');
INSERT INTO `rbac_permissions` VALUES ('466', 'Command: gmannounce');
INSERT INTO `rbac_permissions` VALUES ('467', 'Command: gmnameannounce');
INSERT INTO `rbac_permissions` VALUES ('468', 'Command: gmnotify');
INSERT INTO `rbac_permissions` VALUES ('469', 'Command: nameannounce');
INSERT INTO `rbac_permissions` VALUES ('470', 'Command: notify');
INSERT INTO `rbac_permissions` VALUES ('471', 'Command: whispers');
INSERT INTO `rbac_permissions` VALUES ('472', 'Command: group');
INSERT INTO `rbac_permissions` VALUES ('473', 'Command: group leader');
INSERT INTO `rbac_permissions` VALUES ('474', 'Command: group disband');
INSERT INTO `rbac_permissions` VALUES ('475', 'Command: group remove');
INSERT INTO `rbac_permissions` VALUES ('476', 'Command: group join');
INSERT INTO `rbac_permissions` VALUES ('477', 'Command: group list');
INSERT INTO `rbac_permissions` VALUES ('478', 'Command: group summon');
INSERT INTO `rbac_permissions` VALUES ('479', 'Command: pet');
INSERT INTO `rbac_permissions` VALUES ('480', 'Command: pet create');
INSERT INTO `rbac_permissions` VALUES ('481', 'Command: pet learn');
INSERT INTO `rbac_permissions` VALUES ('482', 'Command: pet unlearn');
INSERT INTO `rbac_permissions` VALUES ('483', 'Command: send');
INSERT INTO `rbac_permissions` VALUES ('484', 'Command: send items');
INSERT INTO `rbac_permissions` VALUES ('485', 'Command: send mail');
INSERT INTO `rbac_permissions` VALUES ('486', 'Command: send message');
INSERT INTO `rbac_permissions` VALUES ('487', 'Command: send money');
INSERT INTO `rbac_permissions` VALUES ('488', 'Command: additem');
INSERT INTO `rbac_permissions` VALUES ('489', 'Command: additemset');
INSERT INTO `rbac_permissions` VALUES ('490', 'Command: appear');
INSERT INTO `rbac_permissions` VALUES ('491', 'Command: aura');
INSERT INTO `rbac_permissions` VALUES ('492', 'Command: bank');
INSERT INTO `rbac_permissions` VALUES ('493', 'Command: bindsight');
INSERT INTO `rbac_permissions` VALUES ('494', 'Command: combatstop');
INSERT INTO `rbac_permissions` VALUES ('495', 'Command: cometome');
INSERT INTO `rbac_permissions` VALUES ('496', 'Command: commands');
INSERT INTO `rbac_permissions` VALUES ('497', 'Command: cooldown');
INSERT INTO `rbac_permissions` VALUES ('498', 'Command: damage');
INSERT INTO `rbac_permissions` VALUES ('499', 'Command: dev');
INSERT INTO `rbac_permissions` VALUES ('500', 'Command: die');
INSERT INTO `rbac_permissions` VALUES ('501', 'Command: dismount');
INSERT INTO `rbac_permissions` VALUES ('502', 'Command: distance');
INSERT INTO `rbac_permissions` VALUES ('503', 'Command: flusharenapoints');
INSERT INTO `rbac_permissions` VALUES ('504', 'Command: freeze');
INSERT INTO `rbac_permissions` VALUES ('505', 'Command: gps');
INSERT INTO `rbac_permissions` VALUES ('506', 'Command: guid');
INSERT INTO `rbac_permissions` VALUES ('507', 'Command: help');
INSERT INTO `rbac_permissions` VALUES ('508', 'Command: hidearea');
INSERT INTO `rbac_permissions` VALUES ('509', 'Command: itemmove');
INSERT INTO `rbac_permissions` VALUES ('510', 'Command: kick');
INSERT INTO `rbac_permissions` VALUES ('511', 'Command: linkgrave');
INSERT INTO `rbac_permissions` VALUES ('512', 'Command: listfreeze');
INSERT INTO `rbac_permissions` VALUES ('513', 'Command: maxskill');
INSERT INTO `rbac_permissions` VALUES ('514', 'Command: movegens');
INSERT INTO `rbac_permissions` VALUES ('515', 'Command: mute');
INSERT INTO `rbac_permissions` VALUES ('516', 'Command: neargrave');
INSERT INTO `rbac_permissions` VALUES ('517', 'Command: pinfo');
INSERT INTO `rbac_permissions` VALUES ('518', 'Command: playall');
INSERT INTO `rbac_permissions` VALUES ('519', 'Command: possess');
INSERT INTO `rbac_permissions` VALUES ('520', 'Command: recall');
INSERT INTO `rbac_permissions` VALUES ('521', 'Command: repairitems');
INSERT INTO `rbac_permissions` VALUES ('522', 'Command: respawn');
INSERT INTO `rbac_permissions` VALUES ('523', 'Command: revive');
INSERT INTO `rbac_permissions` VALUES ('524', 'Command: saveall');
INSERT INTO `rbac_permissions` VALUES ('525', 'Command: save');
INSERT INTO `rbac_permissions` VALUES ('526', 'Command: setskill');
INSERT INTO `rbac_permissions` VALUES ('527', 'Command: showarea');
INSERT INTO `rbac_permissions` VALUES ('528', 'Command: summon');
INSERT INTO `rbac_permissions` VALUES ('529', 'Command: unaura');
INSERT INTO `rbac_permissions` VALUES ('530', 'Command: unbindsight');
INSERT INTO `rbac_permissions` VALUES ('531', 'Command: unfreeze');
INSERT INTO `rbac_permissions` VALUES ('532', 'Command: unmute');
INSERT INTO `rbac_permissions` VALUES ('533', 'Command: unpossess');
INSERT INTO `rbac_permissions` VALUES ('534', 'Command: unstuck');
INSERT INTO `rbac_permissions` VALUES ('535', 'Command: wchange');
INSERT INTO `rbac_permissions` VALUES ('536', 'Command: mmap');
INSERT INTO `rbac_permissions` VALUES ('537', 'Command: mmap loadedtiles');
INSERT INTO `rbac_permissions` VALUES ('538', 'Command: mmap loc');
INSERT INTO `rbac_permissions` VALUES ('539', 'Command: mmap path');
INSERT INTO `rbac_permissions` VALUES ('540', 'Command: mmap stats');
INSERT INTO `rbac_permissions` VALUES ('541', 'Command: mmap testarea');
INSERT INTO `rbac_permissions` VALUES ('542', 'Command: morph');
INSERT INTO `rbac_permissions` VALUES ('543', 'Command: demorph');
INSERT INTO `rbac_permissions` VALUES ('544', 'Command: modify');
INSERT INTO `rbac_permissions` VALUES ('545', 'Command: modify arenapoints');
INSERT INTO `rbac_permissions` VALUES ('547', 'Command: modify drunk');
INSERT INTO `rbac_permissions` VALUES ('548', 'Command: modify energy');
INSERT INTO `rbac_permissions` VALUES ('549', 'Command: modify faction');
INSERT INTO `rbac_permissions` VALUES ('550', 'Command: modify gender');
INSERT INTO `rbac_permissions` VALUES ('551', 'Command: modify honor');
INSERT INTO `rbac_permissions` VALUES ('552', 'Command: modify hp');
INSERT INTO `rbac_permissions` VALUES ('553', 'Command: modify mana');
INSERT INTO `rbac_permissions` VALUES ('554', 'Command: modify money');
INSERT INTO `rbac_permissions` VALUES ('555', 'Command: modify mount');
INSERT INTO `rbac_permissions` VALUES ('556', 'Command: modify phase');
INSERT INTO `rbac_permissions` VALUES ('557', 'Command: modify rage');
INSERT INTO `rbac_permissions` VALUES ('558', 'Command: modify reputation');
INSERT INTO `rbac_permissions` VALUES ('559', 'Command: modify runicpower');
INSERT INTO `rbac_permissions` VALUES ('560', 'Command: modify scale');
INSERT INTO `rbac_permissions` VALUES ('561', 'Command: modify speed');
INSERT INTO `rbac_permissions` VALUES ('562', 'Command: modify speed all');
INSERT INTO `rbac_permissions` VALUES ('563', 'Command: modify speed backwalk');
INSERT INTO `rbac_permissions` VALUES ('564', 'Command: modify speed fly');
INSERT INTO `rbac_permissions` VALUES ('565', 'Command: modify speed walk');
INSERT INTO `rbac_permissions` VALUES ('566', 'Command: modify speed swim');
INSERT INTO `rbac_permissions` VALUES ('567', 'Command: modify spell');
INSERT INTO `rbac_permissions` VALUES ('568', 'Command: modify standstate');
INSERT INTO `rbac_permissions` VALUES ('569', 'Command: modify talentpoints');
INSERT INTO `rbac_permissions` VALUES ('570', 'Command: npc');
INSERT INTO `rbac_permissions` VALUES ('571', 'Command: npc add');
INSERT INTO `rbac_permissions` VALUES ('572', 'Command: npc add formation');
INSERT INTO `rbac_permissions` VALUES ('573', 'Command: npc add item');
INSERT INTO `rbac_permissions` VALUES ('574', 'Command: npc add move');
INSERT INTO `rbac_permissions` VALUES ('575', 'Command: npc add temp');
INSERT INTO `rbac_permissions` VALUES ('576', 'Command: npc add delete');
INSERT INTO `rbac_permissions` VALUES ('577', 'Command: npc add delete item');
INSERT INTO `rbac_permissions` VALUES ('578', 'Command: npc add follow');
INSERT INTO `rbac_permissions` VALUES ('579', 'Command: npc add follow stop');
INSERT INTO `rbac_permissions` VALUES ('580', 'Command: npc set');
INSERT INTO `rbac_permissions` VALUES ('581', 'Command: npc set allowmove');
INSERT INTO `rbac_permissions` VALUES ('582', 'Command: npc set entry');
INSERT INTO `rbac_permissions` VALUES ('583', 'Command: npc set factionid');
INSERT INTO `rbac_permissions` VALUES ('584', 'Command: npc set flag');
INSERT INTO `rbac_permissions` VALUES ('585', 'Command: npc set level');
INSERT INTO `rbac_permissions` VALUES ('586', 'Command: npc set link');
INSERT INTO `rbac_permissions` VALUES ('587', 'Command: npc set model');
INSERT INTO `rbac_permissions` VALUES ('588', 'Command: npc set movetype');
INSERT INTO `rbac_permissions` VALUES ('589', 'Command: npc set phase');
INSERT INTO `rbac_permissions` VALUES ('590', 'Command: npc set spawndist');
INSERT INTO `rbac_permissions` VALUES ('591', 'Command: npc set spawntime');
INSERT INTO `rbac_permissions` VALUES ('592', 'Command: npc set data');
INSERT INTO `rbac_permissions` VALUES ('593', 'Command: npc info');
INSERT INTO `rbac_permissions` VALUES ('594', 'Command: npc near');
INSERT INTO `rbac_permissions` VALUES ('595', 'Command: npc move');
INSERT INTO `rbac_permissions` VALUES ('596', 'Command: npc playemote');
INSERT INTO `rbac_permissions` VALUES ('597', 'Command: npc say');
INSERT INTO `rbac_permissions` VALUES ('598', 'Command: npc textemote');
INSERT INTO `rbac_permissions` VALUES ('599', 'Command: npc whisper');
INSERT INTO `rbac_permissions` VALUES ('600', 'Command: npc yell');
INSERT INTO `rbac_permissions` VALUES ('601', 'Command: npc tame');
INSERT INTO `rbac_permissions` VALUES ('602', 'Command: quest');
INSERT INTO `rbac_permissions` VALUES ('603', 'Command: quest add');
INSERT INTO `rbac_permissions` VALUES ('604', 'Command: quest complete');
INSERT INTO `rbac_permissions` VALUES ('605', 'Command: quest remove');
INSERT INTO `rbac_permissions` VALUES ('606', 'Command: quest reward');
INSERT INTO `rbac_permissions` VALUES ('607', 'Command: reload');
INSERT INTO `rbac_permissions` VALUES ('608', 'Command: reload access_requirement');
INSERT INTO `rbac_permissions` VALUES ('609', 'Command: reload criteria_data');
INSERT INTO `rbac_permissions` VALUES ('610', 'Command: reload achievement_reward');
INSERT INTO `rbac_permissions` VALUES ('611', 'Command: reload all');
INSERT INTO `rbac_permissions` VALUES ('612', 'Command: reload all achievement');
INSERT INTO `rbac_permissions` VALUES ('613', 'Command: reload all area');
INSERT INTO `rbac_permissions` VALUES ('615', 'Command: reload all gossips');
INSERT INTO `rbac_permissions` VALUES ('616', 'Command: reload all item');
INSERT INTO `rbac_permissions` VALUES ('617', 'Command: reload all locales');
INSERT INTO `rbac_permissions` VALUES ('618', 'Command: reload all loot');
INSERT INTO `rbac_permissions` VALUES ('619', 'Command: reload all npc');
INSERT INTO `rbac_permissions` VALUES ('620', 'Command: reload all quest');
INSERT INTO `rbac_permissions` VALUES ('621', 'Command: reload all scripts');
INSERT INTO `rbac_permissions` VALUES ('623', 'Command: reload areatrigger_involvedrelation');
INSERT INTO `rbac_permissions` VALUES ('624', 'Command: reload areatrigger_tavern');
INSERT INTO `rbac_permissions` VALUES ('625', 'Command: reload areatrigger_teleport');
INSERT INTO `rbac_permissions` VALUES ('626', 'Command: reload auctions');
INSERT INTO `rbac_permissions` VALUES ('627', 'Command: reload autobroadcast');
INSERT INTO `rbac_permissions` VALUES ('628', 'Command: reload command');
INSERT INTO `rbac_permissions` VALUES ('629', 'Command: reload conditions');
INSERT INTO `rbac_permissions` VALUES ('630', 'Command: reload config');
INSERT INTO `rbac_permissions` VALUES ('631', 'Command: reload battleground_template');
INSERT INTO `rbac_permissions` VALUES ('632', 'Command: .mutehistory');
INSERT INTO `rbac_permissions` VALUES ('633', 'Command: reload creature_linked_respawn');
INSERT INTO `rbac_permissions` VALUES ('634', 'Command: reload creature_loot_template');
INSERT INTO `rbac_permissions` VALUES ('635', 'Command: reload creature_onkill_reputation');
INSERT INTO `rbac_permissions` VALUES ('636', 'Command: reload creature_questender');
INSERT INTO `rbac_permissions` VALUES ('637', 'Command: reload creature_queststarter');
INSERT INTO `rbac_permissions` VALUES ('638', 'Command: reload creature_summon_groups');
INSERT INTO `rbac_permissions` VALUES ('639', 'Command: reload creature_template');
INSERT INTO `rbac_permissions` VALUES ('640', 'Command: reload creature_text');
INSERT INTO `rbac_permissions` VALUES ('641', 'Command: reload disables');
INSERT INTO `rbac_permissions` VALUES ('642', 'Command: reload disenchant_loot_template');
INSERT INTO `rbac_permissions` VALUES ('643', 'Command: reload event_scripts');
INSERT INTO `rbac_permissions` VALUES ('644', 'Command: reload fishing_loot_template');
INSERT INTO `rbac_permissions` VALUES ('645', 'Command: reload game_graveyard_zone');
INSERT INTO `rbac_permissions` VALUES ('646', 'Command: reload game_tele');
INSERT INTO `rbac_permissions` VALUES ('647', 'Command: reload gameobject_questender');
INSERT INTO `rbac_permissions` VALUES ('648', 'Command: reload gameobject_loot_template');
INSERT INTO `rbac_permissions` VALUES ('649', 'Command: reload gameobject_queststarter');
INSERT INTO `rbac_permissions` VALUES ('650', 'Command: reload support');
INSERT INTO `rbac_permissions` VALUES ('651', 'Command: reload gossip_menu');
INSERT INTO `rbac_permissions` VALUES ('652', 'Command: reload gossip_menu_option');
INSERT INTO `rbac_permissions` VALUES ('653', 'Command: reload item_random_bonus_list_template');
INSERT INTO `rbac_permissions` VALUES ('654', 'Command: reload item_loot_template');
INSERT INTO `rbac_permissions` VALUES ('655', 'Command: reload item_set_names');
INSERT INTO `rbac_permissions` VALUES ('656', 'Command: reload lfg_dungeon_rewards');
INSERT INTO `rbac_permissions` VALUES ('657', 'Command: reload locales_achievement_reward');
INSERT INTO `rbac_permissions` VALUES ('658', 'Command: reload locales_creature');
INSERT INTO `rbac_permissions` VALUES ('659', 'Command: reload locales_creature_text');
INSERT INTO `rbac_permissions` VALUES ('660', 'Command: reload locales_gameobject');
INSERT INTO `rbac_permissions` VALUES ('661', 'Command: reload locales_gossip_menu_option');
INSERT INTO `rbac_permissions` VALUES ('663', 'Command: reload locales_item_set_name');
INSERT INTO `rbac_permissions` VALUES ('665', 'Command: reload locales_page_text');
INSERT INTO `rbac_permissions` VALUES ('666', 'Command: reload locales_points_of_interest');
INSERT INTO `rbac_permissions` VALUES ('667', 'Command: reload quest_locale');
INSERT INTO `rbac_permissions` VALUES ('668', 'Command: reload mail_level_reward');
INSERT INTO `rbac_permissions` VALUES ('669', 'Command: reload mail_loot_template');
INSERT INTO `rbac_permissions` VALUES ('670', 'Command: reload milling_loot_template');
INSERT INTO `rbac_permissions` VALUES ('671', 'Command: reload npc_spellclick_spells');
INSERT INTO `rbac_permissions` VALUES ('672', 'Command: reload npc_trainer');
INSERT INTO `rbac_permissions` VALUES ('673', 'Command: reload npc_vendor');
INSERT INTO `rbac_permissions` VALUES ('674', 'Command: reload page_text');
INSERT INTO `rbac_permissions` VALUES ('675', 'Command: reload pickpocketing_loot_template');
INSERT INTO `rbac_permissions` VALUES ('676', 'Command: reload points_of_interest');
INSERT INTO `rbac_permissions` VALUES ('677', 'Command: reload prospecting_loot_template');
INSERT INTO `rbac_permissions` VALUES ('678', 'Command: reload quest_poi');
INSERT INTO `rbac_permissions` VALUES ('679', 'Command: reload quest_template');
INSERT INTO `rbac_permissions` VALUES ('680', 'Command: reload rbac');
INSERT INTO `rbac_permissions` VALUES ('681', 'Command: reload reference_loot_template');
INSERT INTO `rbac_permissions` VALUES ('682', 'Command: reload reserved_name');
INSERT INTO `rbac_permissions` VALUES ('683', 'Command: reload reputation_reward_rate');
INSERT INTO `rbac_permissions` VALUES ('684', 'Command: reload reputation_spillover_template');
INSERT INTO `rbac_permissions` VALUES ('685', 'Command: reload skill_discovery_template');
INSERT INTO `rbac_permissions` VALUES ('686', 'Command: reload skill_extra_item_template');
INSERT INTO `rbac_permissions` VALUES ('687', 'Command: reload skill_fishing_base_level');
INSERT INTO `rbac_permissions` VALUES ('688', 'Command: reload skinning_loot_template');
INSERT INTO `rbac_permissions` VALUES ('689', 'Command: reload smart_scripts');
INSERT INTO `rbac_permissions` VALUES ('690', 'Command: reload spell_required');
INSERT INTO `rbac_permissions` VALUES ('691', 'Command: reload spell_area');
INSERT INTO `rbac_permissions` VALUES ('693', 'Command: reload spell_group');
INSERT INTO `rbac_permissions` VALUES ('694', 'Command: reload spell_learn_spell');
INSERT INTO `rbac_permissions` VALUES ('695', 'Command: reload spell_loot_template');
INSERT INTO `rbac_permissions` VALUES ('696', 'Command: reload spell_linked_spell');
INSERT INTO `rbac_permissions` VALUES ('697', 'Command: reload spell_pet_auras');
INSERT INTO `rbac_permissions` VALUES ('698', 'Command: character changeaccount');
INSERT INTO `rbac_permissions` VALUES ('699', 'Command: reload spell_proc');
INSERT INTO `rbac_permissions` VALUES ('700', 'Command: reload spell_scripts');
INSERT INTO `rbac_permissions` VALUES ('701', 'Command: reload spell_target_position');
INSERT INTO `rbac_permissions` VALUES ('702', 'Command: reload spell_threats');
INSERT INTO `rbac_permissions` VALUES ('703', 'Command: reload spell_group_stack_rules');
INSERT INTO `rbac_permissions` VALUES ('704', 'Command: reload trinity_string');
INSERT INTO `rbac_permissions` VALUES ('706', 'Command: reload waypoint_scripts');
INSERT INTO `rbac_permissions` VALUES ('707', 'Command: reload waypoint_data');
INSERT INTO `rbac_permissions` VALUES ('708', 'Command: reload vehicle_accessory');
INSERT INTO `rbac_permissions` VALUES ('709', 'Command: reload vehicle_template_accessory');
INSERT INTO `rbac_permissions` VALUES ('710', 'Command: reset');
INSERT INTO `rbac_permissions` VALUES ('711', 'Command: reset achievements');
INSERT INTO `rbac_permissions` VALUES ('712', 'Command: reset honor');
INSERT INTO `rbac_permissions` VALUES ('713', 'Command: reset level');
INSERT INTO `rbac_permissions` VALUES ('714', 'Command: reset spells');
INSERT INTO `rbac_permissions` VALUES ('715', 'Command: reset stats');
INSERT INTO `rbac_permissions` VALUES ('716', 'Command: reset talents');
INSERT INTO `rbac_permissions` VALUES ('717', 'Command: reset all');
INSERT INTO `rbac_permissions` VALUES ('718', 'Command: server');
INSERT INTO `rbac_permissions` VALUES ('719', 'Command: server corpses');
INSERT INTO `rbac_permissions` VALUES ('720', 'Command: server exit');
INSERT INTO `rbac_permissions` VALUES ('721', 'Command: server idlerestart');
INSERT INTO `rbac_permissions` VALUES ('722', 'Command: server idlerestart cancel');
INSERT INTO `rbac_permissions` VALUES ('723', 'Command: server idleshutdown');
INSERT INTO `rbac_permissions` VALUES ('724', 'Command: server idleshutdown cancel');
INSERT INTO `rbac_permissions` VALUES ('725', 'Command: server info');
INSERT INTO `rbac_permissions` VALUES ('726', 'Command: server plimit');
INSERT INTO `rbac_permissions` VALUES ('727', 'Command: server restart');
INSERT INTO `rbac_permissions` VALUES ('728', 'Command: server restart cancel');
INSERT INTO `rbac_permissions` VALUES ('729', 'Command: server set');
INSERT INTO `rbac_permissions` VALUES ('730', 'Command: server set closed');
INSERT INTO `rbac_permissions` VALUES ('731', 'Command: server set difftime');
INSERT INTO `rbac_permissions` VALUES ('732', 'Command: server set loglevel');
INSERT INTO `rbac_permissions` VALUES ('733', 'Command: server set motd');
INSERT INTO `rbac_permissions` VALUES ('734', 'Command: server shutdown');
INSERT INTO `rbac_permissions` VALUES ('735', 'Command: server shutdown cancel');
INSERT INTO `rbac_permissions` VALUES ('736', 'Command: server motd');
INSERT INTO `rbac_permissions` VALUES ('737', 'Command: tele');
INSERT INTO `rbac_permissions` VALUES ('738', 'Command: tele add');
INSERT INTO `rbac_permissions` VALUES ('739', 'Command: tele del');
INSERT INTO `rbac_permissions` VALUES ('740', 'Command: tele name');
INSERT INTO `rbac_permissions` VALUES ('741', 'Command: tele group');
INSERT INTO `rbac_permissions` VALUES ('742', 'Command: ticket');
INSERT INTO `rbac_permissions` VALUES ('753', 'Command: ticket reset');
INSERT INTO `rbac_permissions` VALUES ('757', 'Command: ticket togglesystem');
INSERT INTO `rbac_permissions` VALUES ('761', 'Command: titles');
INSERT INTO `rbac_permissions` VALUES ('762', 'Command: titles add');
INSERT INTO `rbac_permissions` VALUES ('763', 'Command: titles current');
INSERT INTO `rbac_permissions` VALUES ('764', 'Command: titles remove');
INSERT INTO `rbac_permissions` VALUES ('765', 'Command: titles set');
INSERT INTO `rbac_permissions` VALUES ('766', 'Command: titles set mask');
INSERT INTO `rbac_permissions` VALUES ('767', 'Command: wp');
INSERT INTO `rbac_permissions` VALUES ('768', 'Command: wp add');
INSERT INTO `rbac_permissions` VALUES ('769', 'Command: wp event');
INSERT INTO `rbac_permissions` VALUES ('770', 'Command: wp load');
INSERT INTO `rbac_permissions` VALUES ('771', 'Command: wp modify');
INSERT INTO `rbac_permissions` VALUES ('772', 'Command: wp unload');
INSERT INTO `rbac_permissions` VALUES ('773', 'Command: wp reload');
INSERT INTO `rbac_permissions` VALUES ('774', 'Command: wp show');
INSERT INTO `rbac_permissions` VALUES ('775', 'Command: modify currency');
INSERT INTO `rbac_permissions` VALUES ('776', 'Command: debug phase');
INSERT INTO `rbac_permissions` VALUES ('777', 'Command: mailbox');
INSERT INTO `rbac_permissions` VALUES ('778', 'Command: ahbot');
INSERT INTO `rbac_permissions` VALUES ('779', 'Command: ahbot items');
INSERT INTO `rbac_permissions` VALUES ('780', 'Command: ahbot items gray');
INSERT INTO `rbac_permissions` VALUES ('781', 'Command: ahbot items white');
INSERT INTO `rbac_permissions` VALUES ('782', 'Command: ahbot items green');
INSERT INTO `rbac_permissions` VALUES ('783', 'Command: ahbot items blue');
INSERT INTO `rbac_permissions` VALUES ('784', 'Command: ahbot items purple');
INSERT INTO `rbac_permissions` VALUES ('785', 'Command: ahbot items orange');
INSERT INTO `rbac_permissions` VALUES ('786', 'Command: ahbot items yellow');
INSERT INTO `rbac_permissions` VALUES ('787', 'Command: ahbot ratio');
INSERT INTO `rbac_permissions` VALUES ('788', 'Command: ahbot ratio alliance');
INSERT INTO `rbac_permissions` VALUES ('789', 'Command: ahbot ratio horde');
INSERT INTO `rbac_permissions` VALUES ('790', 'Command: ahbot ratio neutral');
INSERT INTO `rbac_permissions` VALUES ('791', 'Command: ahbot rebuild');
INSERT INTO `rbac_permissions` VALUES ('792', 'Command: ahbot reload');
INSERT INTO `rbac_permissions` VALUES ('793', 'Command: ahbot status');
INSERT INTO `rbac_permissions` VALUES ('794', 'Command: .guild info');
INSERT INTO `rbac_permissions` VALUES ('797', 'Command: pvpstats');
INSERT INTO `rbac_permissions` VALUES ('798', 'Command: .mod xp');
INSERT INTO `rbac_permissions` VALUES ('802', 'Command: .ticket bug');
INSERT INTO `rbac_permissions` VALUES ('803', 'Command: .ticket complaint');
INSERT INTO `rbac_permissions` VALUES ('804', 'Command: .ticket suggestion');
INSERT INTO `rbac_permissions` VALUES ('805', 'Command: .ticket bug assign');
INSERT INTO `rbac_permissions` VALUES ('806', 'Command: .ticket bug close');
INSERT INTO `rbac_permissions` VALUES ('807', 'Command: .ticket bug closedlist');
INSERT INTO `rbac_permissions` VALUES ('808', 'Command: .ticket bug comment');
INSERT INTO `rbac_permissions` VALUES ('809', 'Command: .ticket bug delete');
INSERT INTO `rbac_permissions` VALUES ('810', 'Command: .ticket bug list');
INSERT INTO `rbac_permissions` VALUES ('811', 'Command: .ticket bug unassign');
INSERT INTO `rbac_permissions` VALUES ('812', 'Command: .ticket bug view');
INSERT INTO `rbac_permissions` VALUES ('813', 'Command: .ticket complaint assign');
INSERT INTO `rbac_permissions` VALUES ('814', 'Command: .ticket complaint close');
INSERT INTO `rbac_permissions` VALUES ('815', 'Command: .ticket complaint closedlist');
INSERT INTO `rbac_permissions` VALUES ('816', 'Command: .ticket complaint comment');
INSERT INTO `rbac_permissions` VALUES ('817', 'Command: .ticket complaint delete');
INSERT INTO `rbac_permissions` VALUES ('818', 'Command: .ticket complaint list');
INSERT INTO `rbac_permissions` VALUES ('819', 'Command: .ticket complaint unassign');
INSERT INTO `rbac_permissions` VALUES ('820', 'Command: .ticket complaint view');
INSERT INTO `rbac_permissions` VALUES ('821', 'Command: .ticket suggestion assign');
INSERT INTO `rbac_permissions` VALUES ('822', 'Command: .ticket suggestion close');
INSERT INTO `rbac_permissions` VALUES ('823', 'Command: .ticket suggestion closedlist');
INSERT INTO `rbac_permissions` VALUES ('824', 'Command: .ticket suggestion comment');
INSERT INTO `rbac_permissions` VALUES ('825', 'Command: .ticket suggestion delete');
INSERT INTO `rbac_permissions` VALUES ('826', 'Command: .ticket suggestion list');
INSERT INTO `rbac_permissions` VALUES ('827', 'Command: .ticket suggestion unassign');
INSERT INTO `rbac_permissions` VALUES ('828', 'Command: .ticket suggestion view');
INSERT INTO `rbac_permissions` VALUES ('829', 'Command: .ticket reset all');
INSERT INTO `rbac_permissions` VALUES ('830', 'Command: .bnetaccount listgameaccounts');
INSERT INTO `rbac_permissions` VALUES ('831', 'Command: .ticket reset bug');
INSERT INTO `rbac_permissions` VALUES ('832', 'Command: .ticket reset complaint');
INSERT INTO `rbac_permissions` VALUES ('833', 'Command: .ticket reset suggestion');
INSERT INTO `rbac_permissions` VALUES ('835', 'Command: debug loadcells');
INSERT INTO `rbac_permissions` VALUES ('836', 'Command: .debug boundary');
INSERT INTO `rbac_permissions` VALUES ('837', 'Command: npc evade');
INSERT INTO `rbac_permissions` VALUES ('838', 'Command: pet level');
INSERT INTO `rbac_permissions` VALUES ('839', 'Command: server shutdown force');
INSERT INTO `rbac_permissions` VALUES ('840', 'Command: server restart force');
INSERT INTO `rbac_permissions` VALUES ('841', 'Command: .debug neargraveyard');
INSERT INTO `rbac_permissions` VALUES ('842', 'Command: reload character_template');
INSERT INTO `rbac_permissions` VALUES ('843', 'Command: reload quest_greeting');
INSERT INTO `rbac_permissions` VALUES ('844', 'Command: scene');
INSERT INTO `rbac_permissions` VALUES ('845', 'Command: scene debug');
INSERT INTO `rbac_permissions` VALUES ('846', 'Command: scene play');
INSERT INTO `rbac_permissions` VALUES ('847', 'Command: scene play package');
INSERT INTO `rbac_permissions` VALUES ('848', 'Command: scene cancel');
INSERT INTO `rbac_permissions` VALUES ('849', 'Command: list scenes');
INSERT INTO `rbac_permissions` VALUES ('850', 'Command: reload scenes');
INSERT INTO `rbac_permissions` VALUES ('851', 'Command: reload areatrigger_templates');
INSERT INTO `rbac_permissions` VALUES ('852', 'Command: debug dummy');
INSERT INTO `rbac_permissions` VALUES ('853', 'Command: .reload conversation_template');
INSERT INTO `rbac_permissions` VALUES ('854', 'Command: .debug conversation');
INSERT INTO `rbac_permissions` VALUES ('855', 'Command: debug play music');
INSERT INTO `rbac_permissions` VALUES ('856', 'Command: npc spawngroup');
INSERT INTO `rbac_permissions` VALUES ('857', 'Command: npc despawngroup');
INSERT INTO `rbac_permissions` VALUES ('858', 'Command: gobject spawngroup');
INSERT INTO `rbac_permissions` VALUES ('859', 'Command: gobject despawngroup');
INSERT INTO `rbac_permissions` VALUES ('860', 'Command: list respawns');
INSERT INTO `rbac_permissions` VALUES ('865', 'Command: npc showloot');
INSERT INTO `rbac_permissions` VALUES ('866', 'Command: list spawnpoints');
INSERT INTO `rbac_permissions` VALUES ('868', 'Command: modify power');
INSERT INTO `rbac_permissions` VALUES ('869', 'Command: debug send playerchoice');
INSERT INTO `rbac_permissions` VALUES ('870', 'Command: debug threatinfo');
INSERT INTO `rbac_permissions` VALUES ('871', 'Command: debug instancespawn');
INSERT INTO `rbac_permissions` VALUES ('872', 'Command: server debug');
INSERT INTO `rbac_permissions` VALUES ('873', 'Command: reload creature_movement_override');
INSERT INTO `rbac_permissions` VALUES ('874', 'Command: debug asan');
INSERT INTO `rbac_permissions` VALUES ('875', 'Command: lookup map id');
INSERT INTO `rbac_permissions` VALUES ('876', 'Command: lookup item id');
INSERT INTO `rbac_permissions` VALUES ('877', 'Command: lookup quest id');
INSERT INTO `rbac_permissions` VALUES ('878', 'Command: debug questreset');
INSERT INTO `rbac_permissions` VALUES ('879', 'Command: debug poolstatus');
INSERT INTO `rbac_permissions` VALUES ('880', 'Command: pdump copy');
INSERT INTO `rbac_permissions` VALUES ('881', 'Command: reload vehicle_template');
INSERT INTO `rbac_permissions` VALUES ('882', 'Command: reload spell_script_names');
INSERT INTO `rbac_permissions` VALUES ('883', 'Command: quest objective complete');
INSERT INTO `rbac_permissions` VALUES ('1398', 'Command: gobject set scale');
INSERT INTO `rbac_permissions` VALUES ('1589', 'Command: npc set scale');

-- ----------------------------
-- Table structure for `realmcharacters`
-- ----------------------------
DROP TABLE IF EXISTS `realmcharacters`;
CREATE TABLE `realmcharacters` (
  `realmid` int(10) unsigned NOT NULL DEFAULT '0',
  `acctid` int(10) unsigned NOT NULL,
  `numchars` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`realmid`,`acctid`),
  KEY `acctid` (`acctid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Realm Character Tracker';

-- ----------------------------
-- Records of realmcharacters
-- ----------------------------
INSERT INTO `realmcharacters` VALUES ('1', '1', '1');
INSERT INTO `realmcharacters` VALUES ('1', '2', '0');

-- ----------------------------
-- Table structure for `realmlist`
-- ----------------------------
DROP TABLE IF EXISTS `realmlist`;
CREATE TABLE `realmlist` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `localAddress` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `localSubnetMask` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '255.255.255.0',
  `port` smallint(5) unsigned NOT NULL DEFAULT '8085',
  `icon` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `flag` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `timezone` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `allowedSecurityLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `population` float unsigned NOT NULL DEFAULT '0',
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '47936',
  `Region` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `Battlegroup` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Realm System';

-- ----------------------------
-- Records of realmlist
-- ----------------------------
INSERT INTO `realmlist` VALUES ('1', '小女孩的魔兽世界', '53ne61024.51vip.biz', '192.168.0.198', '255.255.255.0', '8085', '0', '0', '1', '0', '0', '47936', '1', '1');

-- ----------------------------
-- Table structure for `secret_digest`
-- ----------------------------
DROP TABLE IF EXISTS `secret_digest`;
CREATE TABLE `secret_digest` (
  `id` int(10) unsigned NOT NULL,
  `digest` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of secret_digest
-- ----------------------------

-- ----------------------------
-- Table structure for `updates`
-- ----------------------------
DROP TABLE IF EXISTS `updates`;
CREATE TABLE `updates` (
  `name` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'filename with extension of the update.',
  `hash` char(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT 'sha1 hash of the sql file.',
  `state` enum('RELEASED','ARCHIVED') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
  `speed` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'time the query takes to apply in ms.',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='List of all applied updates in this database.';

-- ----------------------------
-- Records of updates
-- ----------------------------
INSERT INTO `updates` VALUES ('2014_10_04_00_auth.sql', 'C3BC70A6EC381474B7308F442346F1E721176BC6', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_10_19_00_auth.sql', '7472B490A4F86C9D3DA609CDD3197499CB80C87C', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_10_26_00_auth.sql', '75CC67ADE2A3B2E54FD57D6B0DCAA8FE50F4EE35', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_03_00_auth.sql', '5948C9F286CF0FEA8E241785C0259FF36B73BDC5', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_04_00_auth.sql', '3AFC68B2375C2A417DDEA94583C53AFF83DE50DF', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_09_00_auth.sql', 'B8DD1A7047C0FDDB80344B239343EC33BF1A0D97', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_10_00_auth_from_335.sql', '0E3CB119442D09DD88E967015319BBC8DAFBBFE0', 'ARCHIVED', '2014-11-10 08:00:00', '0');
INSERT INTO `updates` VALUES ('2014_11_10_00_auth.sql', '8FBA737A1D3FF4631A1E662A5B500A8BD304EC63', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_10_01_auth.sql', '327E77A1DA3546D5275AB249915DD57EDD6FDD3D', 'ARCHIVED', '2014-11-10 08:00:01', '0');
INSERT INTO `updates` VALUES ('2014_11_23_00_auth.sql', '0BBEB3EB3AED0FEF277A062819B6B2C00084A742', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_11_25_00_auth.sql', '4F45CDB26BDBB3EE83F1988E3D7818C5926ADC02', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_12_05_00_auth.sql', '6A7BBCEF43111C73A2D2C3CCB6911BE50DE7DD94', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_12_10_00_auth.sql', '821703A96D80F9080074852B5A46E2909C9562EA', 'ARCHIVED', '2014-12-10 08:00:00', '0');
INSERT INTO `updates` VALUES ('2014_12_19_00_auth.sql', '44D8E12FFF327AD07878FBDF8D9C16B6B7DCB122', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_12_20_00_auth.sql', '4DAA02AE285C02AE6C82EA2C8B97AC71990F1085', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_12_25_00_auth.sql', '61411930F482BC73FC7FD2C370C811E944F5FF92', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2014_12_27_00_auth.sql', 'CE2E5D2CD82E79C25294539ADED27A1429105B43', 'ARCHIVED', '2014-12-21 08:00:00', '0');
INSERT INTO `updates` VALUES ('2014_12_28_00_auth.sql', '0A913217610E76AFF119C27259737BBC523090E6', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_02_22_00_auth.sql', '21CCCF8B01252E16CA3D6C9E3E8DAA4C9B28ED6E', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_03_01_00_auth.sql', '911881E273207FF6182D1FDAC8C85FFAE8F1C852', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_03_10_00_auth.sql', '2CC8502C11412EFEB5C11BE166761A8754A59009', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_03_15_00_auth.sql', '1D8E107FBEFE5E7F47E09F45240DFF499B77CDED', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_03_20_00_auth.sql', 'B761760804EA73BD297F296C5C1919687DF7191C', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_03_20_01_auth.sql', '5CCEDF20C8189FB1E8DF064A9F0DDC342841FBF0', 'ARCHIVED', '2015-03-22 00:55:52', '0');
INSERT INTO `updates` VALUES ('2015_03_20_02_auth.sql', '85E4ACD9AA099C0C4AC034575F2BB07D348EAC72', 'ARCHIVED', '2015-03-22 00:56:46', '0');
INSERT INTO `updates` VALUES ('2015_03_26_00_auth.sql', '34AC8543E6A9C6C832DE58EAB33618EEEF70B9F9', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_04_00_auth.sql', '57146B35E54A2EC7869C945034AB078358020311', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_06_00_auth.sql', '2A8049DC2923420A002D42FB6F02C2FFCC5CDD22', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_08_00_auth.sql', '4D7D8EEF285C982BB676836602266501BEC26764', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_10_00_auth.sql', '4AE68FD97A95CEE5143EA20FD33F5D557367AC1F', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_11_00_auth.sql', '80A71C8921CFEBB547D264558B6DE27201685B84', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_11_01_auth.sql', '3E88183E1A85D11BFD74CF9A32A725C44AE02EEC', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_04_21_00_auth.sql', '1B3B48DBA06368B985C548D166C515C9DD598CB9', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_05_02_00_auth.sql', '96AB595E0D2A088750E3F48B0AF0A8A14F3CFE1E', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_05_02_01_auth.sql', 'FB11FB834E488B0FD3AFDABCC1A3113092E7C2E5', 'ARCHIVED', '2015-05-02 21:57:57', '0');
INSERT INTO `updates` VALUES ('2015_07_02_00_auth.sql', 'E5EE3842AB9B01851E49B360FBAF6FFEEAB2A8DA', 'ARCHIVED', '2015-07-11 03:30:56', '0');
INSERT INTO `updates` VALUES ('2015_07_06_00_auth.sql', '6D1ADBA496DC6E6D7B3BF887DA8D4D17D3FBACE0', 'ARCHIVED', '2015-07-11 03:30:56', '0');
INSERT INTO `updates` VALUES ('2015_07_08_00_auth.sql', 'CB54020AFD1E31742FD8BF9CE16879625E289788', 'ARCHIVED', '2015-07-11 03:30:56', '0');
INSERT INTO `updates` VALUES ('2015_07_08_01_auth.sql', '74D281CB82E0DA36D628BDC7AC797AE5498DB461', 'ARCHIVED', '2015-07-11 03:30:56', '0');
INSERT INTO `updates` VALUES ('2015_07_16_00_auth.sql', 'A057E95B5553B6A57A1642FE3FEC8E2E62EDE3C6', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_07_29_00_auth.sql', '0000FECBC413E96C7C45F303D162E263EFBA7116', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_08_26_00_auth.sql', '3071C02A2EB7DCBF4CEE10279FEFAB7C29A43A3A', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_09_05_00_auth.sql', 'F765D82B37873FA67447347D5B83C99C159FB452', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_09_05_01_auth.sql', '97A72DBCBF14D27A1863834A22296905FF276086', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_09_09_00_auth.sql', '495A0CF1B1C49205D4A5D3C25A4E1EB95616D6B4', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_09_15_00_auth.sql', 'D1FEFDA4C98F30384DF4B64D5A53187303EB5786', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_10_09_00_auth.sql', 'B6D643D444C6AE711503F73B96B6252A852913D6', 'ARCHIVED', '2015-10-10 16:30:48', '0');
INSERT INTO `updates` VALUES ('2015_10_16_00_auth.sql', '366AFFD1088762866091A81CE1EC64138B8B35F1', 'ARCHIVED', '2015-11-08 08:46:02', '0');
INSERT INTO `updates` VALUES ('2015_10_17_00_auth.sql', 'AC0D45E905033F42093852D2C4476663BDACCB3D', 'ARCHIVED', '2015-10-17 20:39:12', '0');
INSERT INTO `updates` VALUES ('2015_11_01_00_auth_2015_08_21_00.sql', 'C31A9E1D28E11B60BE8F8198637DD51F6D75123F', 'ARCHIVED', '2015-08-21 08:00:00', '0');
INSERT INTO `updates` VALUES ('2015_11_08_00_auth.sql', '0ACDD35EC9745231BCFA701B78056DEF94D0CC53', 'ARCHIVED', '2015-11-07 08:00:00', '0');
INSERT INTO `updates` VALUES ('2015_11_21_00_auth.sql', '575A1D697CC6C7C517F7CCB950988267C99CE7FA', 'ARCHIVED', '2015-11-22 05:25:38', '0');
INSERT INTO `updates` VALUES ('2015_12_07_00_auth.sql', '24A07AC1F38E5D26A3599FC06D29E267418F69F3', 'ARCHIVED', '2015-12-08 04:55:48', '0');
INSERT INTO `updates` VALUES ('2016_01_13_00_auth.sql', '114527BCCB0DE286CBE6FDA3029DD0523D1037FA', 'ARCHIVED', '2016-01-14 05:39:13', '0');
INSERT INTO `updates` VALUES ('2016_03_22_01_auth_2016_01_13_00_auth.sql', '24615CC69B3CD7BB4699874647C35BA86E8A93FD', 'ARCHIVED', '2016-03-23 06:55:13', '0');
INSERT INTO `updates` VALUES ('2016_03_28_00_auth.sql', 'BA14D23D81FA24565F04A359090DE86C5E195209', 'ARCHIVED', '2016-03-29 00:49:32', '0');
INSERT INTO `updates` VALUES ('2016_04_11_00_auth.sql', '0ACDD35EC9745231BCFA701B78056DEF94D0CC53', 'ARCHIVED', '2016-04-11 08:00:00', '0');
INSERT INTO `updates` VALUES ('2016_04_17_00_auth.sql', '83399B64D1221B56F73A0FFB51889F11A70521BC', 'ARCHIVED', '2016-04-17 08:22:05', '0');
INSERT INTO `updates` VALUES ('2016_05_07_00_auth.sql', '7E36DCC4F06FCDCDA7155AF3C5EDF8D3A720565F', 'ARCHIVED', '2016-05-07 09:00:21', '0');
INSERT INTO `updates` VALUES ('2016_05_19_00_auth.sql', 'FB52E6BF35682CE6FA667B552B551F4FBD72AC30', 'ARCHIVED', '2016-05-20 06:18:06', '0');
INSERT INTO `updates` VALUES ('2016_07_19_00_auth.sql', 'D5498F28A1E21F4AD0E0D7C2B96FCF7292C14C4D', 'ARCHIVED', '2016-07-19 22:00:28', '0');
INSERT INTO `updates` VALUES ('2016_07_19_01_auth.sql', 'EBFE5D7D7E7CFA0CDA76AC49A1E8D4FA461A12BE', 'ARCHIVED', '2016-07-20 00:06:39', '0');
INSERT INTO `updates` VALUES ('2016_07_23_00_auth.sql', '1048F6A922ACD9BFC2E4518A71AF7037F79A85C4', 'ARCHIVED', '2016-07-23 22:39:21', '0');
INSERT INTO `updates` VALUES ('2016_07_23_01_auth.sql', '5897C7D8B8DE15895286FBCD1535FC75E1B70F62', 'ARCHIVED', '2016-07-24 01:35:11', '0');
INSERT INTO `updates` VALUES ('2016_07_30_00_auth.sql', '0FD4147840F7F02E2F1828A904B269F5B66097E0', 'ARCHIVED', '2016-07-30 23:07:02', '0');
INSERT INTO `updates` VALUES ('2016_08_07_00_auth.sql', 'D9DD23851822E32E1312FFABEE2DB721C8651443', 'ARCHIVED', '2016-08-07 23:33:42', '0');
INSERT INTO `updates` VALUES ('2016_08_11_00_auth.sql', '0C79A86A4DFC53746BECF3D8A145482F94AE5FC9', 'ARCHIVED', '2016-08-12 01:02:20', '0');
INSERT INTO `updates` VALUES ('2016_08_13_00_auth.sql', 'ED2286C4FF3D80D0F4DEE3D3121BCC15544470BE', 'ARCHIVED', '2016-08-13 09:11:49', '0');
INSERT INTO `updates` VALUES ('2016_08_26_00_auth.sql', '3C566371B6026EFEEA19CD215EC9F02C6DA9EAB3', 'ARCHIVED', '2016-08-26 22:09:52', '0');
INSERT INTO `updates` VALUES ('2016_08_27_00_auth.sql', '65ABEF7ACBCEA974C744ED42F95FBBD29226917B', 'ARCHIVED', '2016-08-27 15:02:45', '0');
INSERT INTO `updates` VALUES ('2016_08_30_00_auth.sql', 'E16C19A938FE6370921658D2B713EE28A633FD56', 'ARCHIVED', '2016-08-30 08:00:00', '0');
INSERT INTO `updates` VALUES ('2016_09_02_00_auth.sql', '08932DAC4BDE74D3C39A43DDE404522F23EDD035', 'ARCHIVED', '2016-09-02 08:00:00', '0');
INSERT INTO `updates` VALUES ('2016_09_03_00_auth_2016_05_11_00_auth.sql', '401EFD3586772BDED66B4A944C20A1AC18A22D3A', 'ARCHIVED', '2016-09-03 19:29:38', '0');
INSERT INTO `updates` VALUES ('2016_09_03_01_auth.sql', '08B5ABCB74BBF25A30D37AF639F0EA1B10640673', 'ARCHIVED', '2016-09-03 21:24:32', '0');
INSERT INTO `updates` VALUES ('2016_09_03_02_auth_2016_06_06_00_auth.sql', 'A0A8D73A952D0618833416513D53F73A70E7EA25', 'ARCHIVED', '2016-06-06 08:00:00', '0');
INSERT INTO `updates` VALUES ('2016_09_03_03_auth.sql', '9BF1C03EE39B6DC7E817BA46BE7D12A41AFBFDF7', 'ARCHIVED', '2016-09-03 23:56:50', '0');
INSERT INTO `updates` VALUES ('2016_09_15_00_auth.sql', 'CD65F822AF1B5B7776E39804D0362F3E34AA6445', 'ARCHIVED', '2016-09-16 00:30:36', '0');
INSERT INTO `updates` VALUES ('2016_09_21_00_auth.sql', '57219A16B88080240EED94CDD41FC2764B8A32C5', 'ARCHIVED', '2016-09-22 01:08:43', '0');
INSERT INTO `updates` VALUES ('2016_09_25_00_auth.sql', 'E811EFD8CE92ABEC5B8C02A09E643035939CF96D', 'ARCHIVED', '2016-09-25 23:56:58', '0');
INSERT INTO `updates` VALUES ('2016_10_01_00_auth.sql', '7C444FF1B03BA3C83472BDA409854754D052D6FB', 'ARCHIVED', '2016-10-01 21:32:43', '0');
INSERT INTO `updates` VALUES ('2016_10_06_00_auth.sql', '6A415F9813EFB5B95EB2AA2B326E1A6791E25EDB', 'ARCHIVED', '2016-10-07 07:16:24', '0');
INSERT INTO `updates` VALUES ('2016_10_12_00_auth.sql', '671D57BBA183AC70B9580DEE19B7EC046AF2EA87', 'ARCHIVED', '2016-10-12 08:01:05', '0');
INSERT INTO `updates` VALUES ('2016_10_17_00_auth.sql', 'A0EF594CD73690D46A46031137DB0E895F079235', 'ARCHIVED', '2016-10-17 00:33:05', '0');
INSERT INTO `updates` VALUES ('2016_10_25_00_auth.sql', '5743FB1AC3F564FE4192DCFA90260BAD5E501882', 'ARCHIVED', '2016-10-26 03:27:02', '0');
INSERT INTO `updates` VALUES ('2016_10_28_00_auth.sql', 'C1B9B1DD20B2183C6CB44CAED9B91BA7C63B8C49', 'ARCHIVED', '2016-10-28 08:07:48', '0');
INSERT INTO `updates` VALUES ('2016_11_04_00_auth.sql', '3F4FE06DCE019EB3223B5A6E0F80E2239078967F', 'ARCHIVED', '2016-11-05 04:25:23', '0');
INSERT INTO `updates` VALUES ('2016_11_09_00_auth.sql', '56432F8AEC2943A398A5B8B77843138B5B704257', 'ARCHIVED', '2016-11-10 02:46:48', '0');
INSERT INTO `updates` VALUES ('2016_11_10_00_auth_objscale.sql', 'C01EA354BF6F10016C40BD68D246A296426A0B04', 'RELEASED', '2023-01-23 15:20:46', '0');
INSERT INTO `updates` VALUES ('2016_11_17_00_auth.sql', '18E8F8FC93CC38755AB571638960AAFB98C0F3F1', 'ARCHIVED', '2016-11-18 07:47:51', '0');
INSERT INTO `updates` VALUES ('2016_12_04_00_auth.sql', 'B1623681EAB651D2A091E3F4D4D4E476CF6D3AEA', 'ARCHIVED', '2016-12-04 08:41:36', '0');
INSERT INTO `updates` VALUES ('2016_12_11_00_auth.sql', '24CA34537DB697962DDD69EEE4BB5E79D2A573DA', 'ARCHIVED', '2016-12-12 02:18:59', '0');
INSERT INTO `updates` VALUES ('2016_12_18_00_auth.sql', '7AB53E033680CF7439F142EF83CD13E6F5D0ACB9', 'ARCHIVED', '2016-12-18 20:15:48', '0');
INSERT INTO `updates` VALUES ('2017_01_14_00_auth.sql', '1B514D1364042DB4CE68929EB54A94F86983441D', 'ARCHIVED', '2017-01-15 04:50:47', '0');
INSERT INTO `updates` VALUES ('2017_01_26_00_auth.sql', '723E1B69981A32A2F28A67C64902BA1AE7E98E48', 'ARCHIVED', '2017-01-27 01:10:15', '0');
INSERT INTO `updates` VALUES ('2017_01_29_00_auth.sql', 'B76C514678903F540302505AF66886F7D2C89E30', 'ARCHIVED', '2017-01-29 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_03_11_00_auth.sql', '2F2F67E51439346B212C27B7224E4614C00E1AEB', 'ARCHIVED', '2017-03-11 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_03_17_00_auth.sql', '4902E9B1B063F399F928C2DD7AFD60427738E227', 'ARCHIVED', '2017-03-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_04_17_00_auth.sql', '86299FAB21D895E84272286309CC8EE80F9DA8C7', 'ARCHIVED', '2017-04-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_04_19_00_auth.sql', '9903AAF50DF384F52E81F7E2892FE5271E000490', 'ARCHIVED', '2017-04-19 07:16:18', '0');
INSERT INTO `updates` VALUES ('2017_04_22_00_auth.sql', '843663B18D28FBA1EB12548500EC93953881E5F0', 'ARCHIVED', '2017-04-23 03:28:22', '0');
INSERT INTO `updates` VALUES ('2017_04_27_00_auth.sql', '308B797B47FA803D492C9C9A4C26DBEC546DBBD9', 'ARCHIVED', '2017-04-28 17:10:11', '0');
INSERT INTO `updates` VALUES ('2017_05_14_00_auth.sql', 'B7E76CCDCC9A2C8103427DA4C43C7B0366ECE8B4', 'ARCHIVED', '2017-05-14 20:00:00', '0');
INSERT INTO `updates` VALUES ('2017_06_12_01_auth.sql', '661B4935E101AF188BEBF43203144104E89F8C54', 'ARCHIVED', '2017-06-12 08:00:01', '0');
INSERT INTO `updates` VALUES ('2017_06_12_02_auth.sql', '166F059E411FAA4901BBBA09A41EF07B1CADC4B6', 'ARCHIVED', '2017-06-12 08:00:02', '0');
INSERT INTO `updates` VALUES ('2017_06_15_00_auth.sql', 'DD71F25C1E61FD5F836931B02703BE3BD1B4F156', 'ARCHIVED', '2017-06-15 23:20:50', '0');
INSERT INTO `updates` VALUES ('2017_06_17_00_auth.sql', '4A172895CB9DA8EFE1270434D6ECB22D4F4DCB17', 'ARCHIVED', '2017-06-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_06_18_00_auth.sql', '7200968BFC2D76499149937B19F2153FD2ABC397', 'ARCHIVED', '2017-06-19 06:13:37', '0');
INSERT INTO `updates` VALUES ('2017_06_25_00_auth.sql', 'A2DA6A64D4217992EF766915DEBD517DB0834E01', 'ARCHIVED', '2017-06-25 08:54:10', '0');
INSERT INTO `updates` VALUES ('2017_06_28_00_auth_master.sql', '6E58300D4D4DAAEE89107ECB3CB7DA8529DA738F', 'ARCHIVED', '2017-06-29 03:11:09', '0');
INSERT INTO `updates` VALUES ('2017_06_28_00_auth_rbac.sql', 'D32EF80F57F629C23395D80F06E91D7E40719F83', 'ARCHIVED', '2017-06-28 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_06_30_00_auth.sql', 'C73BD277D211DBE1BB86BB1B443CA8F292D8ADEE', 'ARCHIVED', '2017-07-01 00:18:51', '0');
INSERT INTO `updates` VALUES ('2017_08_01_00_auth.sql', '6ECE808AF52345177189E962C0606B769B6806A6', 'ARCHIVED', '2017-08-01 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_08_04_00_auth.sql', '2E994A704C64FECE3CE0883ED0CAC5E5A0E3A36C', 'ARCHIVED', '2017-08-05 07:46:32', '0');
INSERT INTO `updates` VALUES ('2017_08_13_00_auth_2016_09_22_00_auth.sql', '70047954E3556BFA430ADD5680EF8797F74A4B9E', 'ARCHIVED', '2017-08-13 20:00:00', '0');
INSERT INTO `updates` VALUES ('2017_09_22_00_auth.sql', '9313CCE80A18212E6F0C78D83316DE8582AE8084', 'ARCHIVED', '2017-09-23 02:05:17', '0');
INSERT INTO `updates` VALUES ('2017_10_13_00_auth.sql', '87674E0D166AC60E3725B445714427892E42C6FE', 'ARCHIVED', '2017-10-13 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_11_11_01_auth.sql', '0D6EDB6B2FC8B9FBDF11ECD79B4B8E943328B6A9', 'ARCHIVED', '2017-11-12 02:49:45', '0');
INSERT INTO `updates` VALUES ('2017_12_17_00_auth.sql', '2CD99730D4D32DBF0584CD5B1AA6F8F4AE3DA975', 'ARCHIVED', '2017-12-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2017_12_30_00_auth.sql', 'F360E9555AC68E28834E3FF807E4E37A090EF363', 'ARCHIVED', '2017-12-30 08:23:32', '0');
INSERT INTO `updates` VALUES ('2017_12_30_01_auth.sql', '1E11C78BA6D1D8E8CED7423DF92D1D197D6061EE', 'ARCHIVED', '2017-12-31 07:00:00', '0');
INSERT INTO `updates` VALUES ('2017_12_31_00_auth.sql', '1721ACBD35EB95FAE33B9E95F8C4E4B1FB70A5E4', 'ARCHIVED', '2018-01-01 04:15:23', '0');
INSERT INTO `updates` VALUES ('2018_01_02_00_auth.sql', 'CD9B826B9D95697DC412DEF780E814FA3991D6CD', 'ARCHIVED', '2018-01-03 04:40:37', '0');
INSERT INTO `updates` VALUES ('2018_01_09_00_auth.sql', 'A5D4EC8FCFAB4F2DCE70EDCAD1ACBFB484FD68D5', 'ARCHIVED', '2018-01-09 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_01_24_00_auth.sql', '167B17D8A253D62A8112F8A7EB21C6E99CAEF1E4', 'ARCHIVED', '2018-01-24 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_02_18_00_auth.sql', '8489DD3EFFE14A7486B593435F0BA2BC69B6EABF', 'ARCHIVED', '2018-02-19 00:35:55', '0');
INSERT INTO `updates` VALUES ('2018_02_19_00_auth.sql', '07CE658C5EF88693D3C047EF8E724F94ADA74C15', 'ARCHIVED', '2018-02-20 06:33:32', '0');
INSERT INTO `updates` VALUES ('2018_02_28_00_auth.sql', 'E92EF4ABF7FA0C66649E1633DD0459F44C09EB83', 'ARCHIVED', '2018-03-01 07:07:59', '0');
INSERT INTO `updates` VALUES ('2018_03_08_00_auth.sql', '624C58A07E0B4DDC4C1347E8BA8EFEEFD5B43DA7', 'ARCHIVED', '2018-03-08 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_03_14_00_auth.sql', '2D71E93DF7419A30D0D21D8A80CF05698302575A', 'ARCHIVED', '2018-03-15 07:07:59', '0');
INSERT INTO `updates` VALUES ('2018_04_06_00_auth.sql', 'D8416F0C4751763202B1997C81423F6EE2FCF9A6', 'ARCHIVED', '2018-04-07 02:00:32', '0');
INSERT INTO `updates` VALUES ('2018_05_13_00_auth.sql', 'A9E20F2EB1E2FDBB982DB6B00DB7301852B27CD4', 'ARCHIVED', '2018-05-14 04:22:32', '0');
INSERT INTO `updates` VALUES ('2018_05_24_00_auth.sql', 'B98FD71AAA13810856729E034E6B8C9F8D5D4F6B', 'ARCHIVED', '2018-05-25 06:32:49', '0');
INSERT INTO `updates` VALUES ('2018_06_14_00_auth.sql', '67EAB915BF0C7F2D410BE45F885A1A39D42C8C14', 'ARCHIVED', '2018-06-15 07:06:59', '0');
INSERT INTO `updates` VALUES ('2018_06_22_00_auth.sql', '9DA24F70B8A365AFDEF58A9B578255CDEDFCA47C', 'ARCHIVED', '2018-06-23 01:45:45', '0');
INSERT INTO `updates` VALUES ('2018_06_23_00_auth.sql', 'BE35312C386A127D047E5A7CE0D14DB41D905F8E', 'ARCHIVED', '2018-06-23 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_06_29_00_auth.sql', '03AAEA7E52848FA5522C3F0C6D9C38B988407480', 'ARCHIVED', '2018-06-30 06:34:04', '0');
INSERT INTO `updates` VALUES ('2018_08_30_00_auth.sql', '22F69864361D3E72F800379338310172C0576D1C', 'ARCHIVED', '2018-08-30 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_09_06_00_auth.sql', '309D21E0DF82ED8921F77EAFDE741F38AC32BB13', 'ARCHIVED', '2018-09-06 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_09_17_00_auth.sql', '4DB671F0A4FA1A93AF28FB6426AF13DE72C7DA3D', 'ARCHIVED', '2018-09-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_12_09_00_auth_2017_01_06_00_auth.sql', '6CCFE6A9774EC733C9863D36A0F15F3534189BBD', 'ARCHIVED', '2017-01-06 08:00:00', '0');
INSERT INTO `updates` VALUES ('2018_12_09_01_auth.sql', '576C2A11BE671D8420FA3EB705E594E381ECCC56', 'ARCHIVED', '2018-12-09 22:49:17', '0');
INSERT INTO `updates` VALUES ('2019_04_27_00_auth.sql', '84B1EB9CC9B09BAF55E6295D202EC57D99B1B60E', 'ARCHIVED', '2019-04-28 02:07:18', '0');
INSERT INTO `updates` VALUES ('2019_06_06_00_auth.sql', '6DE8159E04BEE7BA0A4A81D72D160EB74934B6A5', 'ARCHIVED', '2019-06-07 02:09:54', '0');
INSERT INTO `updates` VALUES ('2019_06_08_00_auth.sql', 'EA5A78F5A26C17BC790481EA9B3772D3A6912459', 'ARCHIVED', '2019-05-21 01:21:20', '0');
INSERT INTO `updates` VALUES ('2019_06_08_01_auth.sql', '8165B1B787E3ECF0C8C0AD2D641513270977ABB4', 'ARCHIVED', '2019-06-05 00:51:31', '0');
INSERT INTO `updates` VALUES ('2019_06_08_02_auth.sql', 'B39DCBD902290700A81C9D028F54B58601C19A99', 'ARCHIVED', '2019-06-06 00:26:31', '0');
INSERT INTO `updates` VALUES ('2019_06_08_03_auth.sql', 'F483B657015D39D4F63E3905C27C3AA48241AB03', 'ARCHIVED', '2019-06-09 01:14:21', '0');
INSERT INTO `updates` VALUES ('2019_06_16_00_auth.sql', 'B14AED4D3387B56FF8C8161D3671750AEEAE0F2E', 'ARCHIVED', '2019-06-16 07:32:12', '0');
INSERT INTO `updates` VALUES ('2019_06_21_00_auth.sql', 'C519239830204B68E710F698BC0C9E89B6D5FD24', 'ARCHIVED', '2019-06-21 03:43:50', '0');
INSERT INTO `updates` VALUES ('2019_07_14_00_auth.sql', '94C2B877BD906538E1E008350BEA8D8B58E0A158', 'ARCHIVED', '2019-07-15 03:22:08', '0');
INSERT INTO `updates` VALUES ('2019_07_15_00_auth.sql', '3649248104CFEC70553016273069A9AE744798E3', 'ARCHIVED', '2019-07-16 03:22:08', '0');
INSERT INTO `updates` VALUES ('2019_07_16_00_auth.sql', '36CB53A9EBD64BFDCF7030083E36E534F1753773', 'ARCHIVED', '2019-07-16 08:00:00', '0');
INSERT INTO `updates` VALUES ('2019_07_17_00_auth.sql', '4F983F039904894ACC483BE885676C5F0A18F06B', 'ARCHIVED', '2019-07-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2019_07_26_00_auth.sql', 'DC9D0651602AE78B1243B40555A1A7B8447D01B2', 'ARCHIVED', '2019-07-27 02:21:34', '0');
INSERT INTO `updates` VALUES ('2019_08_10_00_auth.sql', '3568A1C9C6D62BBCD470C0623C1580E332D545D2', 'ARCHIVED', '2022-01-03 05:18:52', '0');
INSERT INTO `updates` VALUES ('2019_08_10_01_auth.sql', 'C58357260F0C70DA226A71F7E05DE2C49AAEFD74', 'ARCHIVED', '2019-08-10 08:00:00', '0');
INSERT INTO `updates` VALUES ('2019_08_11_00_auth.sql', '04DCC2ABDA15BC7C015E8BFEA383C62A362B166F', 'ARCHIVED', '2019-08-11 18:56:39', '0');
INSERT INTO `updates` VALUES ('2019_08_18_00_auth.sql', '0479A04B669A67D2E5A498CFB91507E742EFB34F', 'ARCHIVED', '2019-08-17 19:51:02', '0');
INSERT INTO `updates` VALUES ('2019_10_27_00_auth.sql', 'C943A651B5C9AC51BB7DF69821886F4B59F57153', 'ARCHIVED', '2019-10-27 21:06:06', '0');
INSERT INTO `updates` VALUES ('2019_11_13_00_auth.sql', 'EB680BA7D6B3A21A432687F452CDD86FB2DA677C', 'ARCHIVED', '2019-11-13 19:49:55', '0');
INSERT INTO `updates` VALUES ('2019_11_20_00_auth.sql', '9BC11595D9CEA486AC1540A204DCE9D86A008D7D', 'ARCHIVED', '2019-11-20 20:31:56', '0');
INSERT INTO `updates` VALUES ('2019_11_23_00_auth.sql', '098708CDC5614B4523AD3B17670939671E661443', 'ARCHIVED', '2019-11-23 20:20:03', '0');
INSERT INTO `updates` VALUES ('2019_12_04_00_auth.sql', '4EB3D028DD80B18DA9B9250ADA4D22AA0D3C0447', 'ARCHIVED', '2019-12-05 02:03:39', '0');
INSERT INTO `updates` VALUES ('2019_12_07_00_auth.sql', 'F354DA31D5B300609C6AE8A25667CA4DE0A7349F', 'ARCHIVED', '2019-12-07 20:57:23', '0');
INSERT INTO `updates` VALUES ('2019_12_10_00_auth.sql', 'CC0DC6211FB2A1271EBF5D81F47B3EF1CED7A7AD', 'ARCHIVED', '2019-12-11 01:50:44', '0');
INSERT INTO `updates` VALUES ('2019_12_14_00_auth.sql', 'CF577A0B6F9747658CDECE3F690B05B89C5B4470', 'ARCHIVED', '2019-12-14 19:17:56', '0');
INSERT INTO `updates` VALUES ('2020_01_11_00_auth.sql', 'A0C4863741C4B93D343B7837FBA38D6023A237F9', 'ARCHIVED', '2020-01-11 21:44:51', '0');
INSERT INTO `updates` VALUES ('2020_01_12_00_auth.sql', '5E4ECF243259B9866A877E2D3798D1D753738E24', 'ARCHIVED', '2020-01-12 19:33:48', '0');
INSERT INTO `updates` VALUES ('2020_02_17_00_auth.sql', '456FA32A7B7C6ABA479F2B099822988A24A2344B', 'ARCHIVED', '2020-02-18 07:28:22', '0');
INSERT INTO `updates` VALUES ('2020_02_24_00_auth.sql', '47E22129056EFD8B67754506231BCC4B0DDA6930', 'ARCHIVED', '2020-02-25 01:19:33', '0');
INSERT INTO `updates` VALUES ('2020_03_03_00_auth.sql', 'F473DFEABAC661704ECEA3D72E93A3280122CA30', 'ARCHIVED', '2020-03-04 06:49:13', '0');
INSERT INTO `updates` VALUES ('2020_03_20_00_auth.sql', '0F72572D7792236D8F1E556D9EC62352A0A149CA', 'ARCHIVED', '2020-03-20 18:01:23', '0');
INSERT INTO `updates` VALUES ('2020_03_23_00_auth.sql', 'B90D27BB8E3CEDF65881BDA0C7CE6FBC5EF310E0', 'ARCHIVED', '2020-03-24 01:57:46', '0');
INSERT INTO `updates` VALUES ('2020_03_31_00_auth.sql', 'BA82A58E95730A397922B6723DA027986E6CD535', 'ARCHIVED', '2020-04-01 01:00:16', '0');
INSERT INTO `updates` VALUES ('2020_04_04_00_auth.sql', '5F118989A9F8AFA3B2065AB9C2C0BB7D9A0EB97A', 'ARCHIVED', '2020-04-04 21:23:53', '0');
INSERT INTO `updates` VALUES ('2020_04_07_00_auth.sql', '6D73A4E1EC5382F10C39F20E2E6E764510A8A5E6', 'ARCHIVED', '2020-04-08 06:23:35', '0');
INSERT INTO `updates` VALUES ('2020_04_18_00_auth.sql', 'BD962B50760771B60F2785027D6957EEF2009240', 'ARCHIVED', '2020-04-18 22:09:28', '0');
INSERT INTO `updates` VALUES ('2020_04_30_00_auth.sql', '2FD304B8EF82D529D69287BF22EF061A267F827E', 'ARCHIVED', '2020-04-30 08:39:29', '0');
INSERT INTO `updates` VALUES ('2020_05_19_00_auth.sql', '12D9F26538F63546B74793499E8A71BD885E8E5F', 'ARCHIVED', '2020-05-19 20:00:00', '0');
INSERT INTO `updates` VALUES ('2020_06_04_00_auth.sql', 'BA797B558196B1A07F8FF66E5288AD04659CF6AC', 'ARCHIVED', '2020-06-04 17:57:07', '0');
INSERT INTO `updates` VALUES ('2020_06_17_00_auth.sql', '8BAB0BF5C90EBDE68685A9FB772EA90DD214E6D6', 'ARCHIVED', '2020-06-17 17:56:25', '0');
INSERT INTO `updates` VALUES ('2020_06_17_01_auth.sql', '8FBF37B875B5C0E8A609FFB1A2C02F2920A3D3F4', 'ARCHIVED', '2020-06-18 01:04:56', '0');
INSERT INTO `updates` VALUES ('2020_06_20_00_auth.sql', '85345FAF20B91DA7B157AE1E17DF5B6446C2E109', 'ARCHIVED', '2020-06-11 18:48:00', '0');
INSERT INTO `updates` VALUES ('2020_07_02_00_auth.sql', '08D0F9D70AE625285172B3E02A3DAFE17D88E118', 'ARCHIVED', '2020-07-02 18:29:25', '0');
INSERT INTO `updates` VALUES ('2020_07_03_00_auth.sql', 'ED7175E51F248ADC5EF60E7CEA9627CC3191ED4C', 'ARCHIVED', '2020-07-04 04:09:39', '0');
INSERT INTO `updates` VALUES ('2020_07_23_00_auth.sql', '5F47E1CEECA9F837C85C2DAC7ECD47AED321F502', 'ARCHIVED', '2020-07-24 03:54:42', '0');
INSERT INTO `updates` VALUES ('2020_07_24_00_auth.sql', '06598162E9C84DDF8AA1F83D0410D056C3F7F69E', 'ARCHIVED', '2020-07-24 08:44:34', '0');
INSERT INTO `updates` VALUES ('2020_07_25_00_auth.sql', 'BE376B619ECB6FE827270D5022F311E20AD6E177', 'ARCHIVED', '2020-07-25 08:00:49', '0');
INSERT INTO `updates` VALUES ('2020_08_02_00_auth.sql', 'B0290F6558C59262D9DDD8071060A8803DD56930', 'ARCHIVED', '2020-08-02 08:00:00', '0');
INSERT INTO `updates` VALUES ('2020_08_03_00_auth.sql', '492CA77C0FAEEEF3E0492121B3A92689373ECFA3', 'ARCHIVED', '2020-08-03 17:24:47', '0');
INSERT INTO `updates` VALUES ('2020_08_03_01_auth.sql', 'EC1063396CA20A2303D83238470D41EF4439EC72', 'ARCHIVED', '2020-08-03 08:00:01', '0');
INSERT INTO `updates` VALUES ('2020_08_06_00_auth.sql', '5D3C5B25132DAFCA3933E9CBE14F5E8A290C4AFA', 'ARCHIVED', '2020-08-07 04:26:11', '0');
INSERT INTO `updates` VALUES ('2020_08_08_00_auth.sql', 'BC6A08BE42A6F2C30C9286CBDD47D57B718C4635', 'ARCHIVED', '2020-08-08 08:16:57', '0');
INSERT INTO `updates` VALUES ('2020_08_11_00_auth.sql', '14C99177E43003D83A4D6F2227722F15FC15A1D0', 'ARCHIVED', '2020-08-11 08:00:00', '0');
INSERT INTO `updates` VALUES ('2020_08_14_00_auth.sql', 'DFB9B07A7846FC0E124EE4CC099E49FE5742FB66', 'ARCHIVED', '2020-08-15 05:41:24', '0');
INSERT INTO `updates` VALUES ('2020_08_26_00_auth.sql', 'D5EF787DECB41D898379588F101A0453B46F04D9', 'ARCHIVED', '2020-08-27 05:00:34', '0');
INSERT INTO `updates` VALUES ('2020_09_06_00_auth.sql', 'DC4B5D4C65EB138D5609F137799C3289B9CC2493', 'ARCHIVED', '2020-09-06 08:00:00', '0');
INSERT INTO `updates` VALUES ('2020_09_17_00_auth.sql', 'BBC0A8B2BBED38A57A83999909EB066753A893C5', 'ARCHIVED', '2020-09-17 08:00:00', '0');
INSERT INTO `updates` VALUES ('2020_09_25_00_auth.sql', '3CCA78EF89223724BA6784A4F3783DED30416637', 'ARCHIVED', '2020-09-26 03:52:40', '0');
INSERT INTO `updates` VALUES ('2020_10_20_00_auth.sql', '1835C5EFD5816DEF914F27E867C8C8D5E08B3F68', 'ARCHIVED', '2020-10-21 05:36:49', '0');
INSERT INTO `updates` VALUES ('2020_12_06_00_auth.sql', 'FA254400D3D7D53E9C350EABFEABFF4EC3AD40DA', 'ARCHIVED', '2020-12-07 04:25:10', '0');
INSERT INTO `updates` VALUES ('2020_12_07_00_auth.sql', '23626805735CB9BEEEBD756D4A39AFBCDA6E366C', 'ARCHIVED', '2020-12-08 05:12:53', '0');
INSERT INTO `updates` VALUES ('2020_12_15_00_auth.sql', '37DA3C4830ABA30C49370A8647F5B6B3E1821E57', 'ARCHIVED', '2020-12-16 03:33:15', '0');
INSERT INTO `updates` VALUES ('2020_12_22_00_auth.sql', '1AED5AD7D93C30CF75E62EBEBCC64FFEDC58F00A', 'ARCHIVED', '2020-12-23 06:00:39', '0');
INSERT INTO `updates` VALUES ('2020_12_31_00_auth.sql', '05C9C105D55C6588CDA0D75AE3B135B7E6B54C06', 'ARCHIVED', '2020-12-31 20:58:21', '0');
INSERT INTO `updates` VALUES ('2021_01_10_00_auth.sql', '4430F5CC9A31DBBEA4E437E980E9F26AC919C016', 'ARCHIVED', '2021-01-10 20:29:57', '0');
INSERT INTO `updates` VALUES ('2021_01_13_00_auth.sql', 'F7C15519FFA0FE27EED859343B58714624A302E6', 'ARCHIVED', '2021-01-13 19:19:52', '0');
INSERT INTO `updates` VALUES ('2021_02_09_00_auth.sql', 'F00ABFF6E3C3F5ACE3444C9D70BADC764C8B3CE2', 'ARCHIVED', '2021-02-10 01:22:24', '0');
INSERT INTO `updates` VALUES ('2021_04_10_00_auth.sql', '7B92AC4F76507940EF2257897F25304CF0F306EB', 'ARCHIVED', '2021-04-11 03:42:42', '0');
INSERT INTO `updates` VALUES ('2021_05_12_00_auth.sql', '7F37DAD1777D62FDB00C19C0DF5E7DB742CCD5AD', 'ARCHIVED', '2021-05-12 09:08:42', '0');
INSERT INTO `updates` VALUES ('2021_06_20_00_auth.sql', '7CA418D570DC1444C19AAD18F4A50FF187642310', 'ARCHIVED', '2021-06-21 01:29:17', '0');
INSERT INTO `updates` VALUES ('2021_07_04_00_auth.sql', '3CF056F8F04E49C1E236060202AA8DA7E186B590', 'ARCHIVED', '2021-07-05 06:23:24', '0');
INSERT INTO `updates` VALUES ('2021_08_07_00_auth.sql', 'D615C2CACC999FF8804AEF56BAAA08D02217D671', 'ARCHIVED', '2021-08-08 07:18:57', '0');
INSERT INTO `updates` VALUES ('2021_08_18_00_auth.sql', '162590897AC0020E68EB6845637901C3EB6509B4', 'ARCHIVED', '2021-08-18 23:14:17', '0');
INSERT INTO `updates` VALUES ('2021_08_19_00_auth.sql', 'DE008EDFB1FEBA49567E245A64BFE70DA72D9E7B', 'ARCHIVED', '2021-08-19 18:58:58', '0');
INSERT INTO `updates` VALUES ('2021_09_02_00_auth.sql', '907344F4F0113A13D5E0A1D95E2C3E4C4150090C', 'ARCHIVED', '2021-09-02 20:38:08', '0');
INSERT INTO `updates` VALUES ('2021_09_10_00_auth.sql', 'DE94812ABC7B395C6C3405FB6718A8AF2C9F8FEC', 'ARCHIVED', '2021-09-10 20:18:54', '0');
INSERT INTO `updates` VALUES ('2021_10_07_00_auth.sql', '45F2D92E28382F0CBE1F9B3A97693C0CC69E50BC', 'ARCHIVED', '2021-10-07 18:32:05', '0');
INSERT INTO `updates` VALUES ('2021_10_13_00_auth.sql', '220E63385CACCBCEC36C57717DE369F2FCABCAAF', 'ARCHIVED', '2021-10-14 05:15:05', '0');
INSERT INTO `updates` VALUES ('2021_10_15_00_auth.sql', 'C8AA212AB2BB2DB5B3C2C9622A3874475AEFBD7B', 'ARCHIVED', '2021-10-15 18:11:47', '0');
INSERT INTO `updates` VALUES ('2021_10_15_01_auth.sql', '72A0437F0ADEC59FF9D6839DF845C473F693CA5B', 'ARCHIVED', '2021-10-16 08:15:25', '0');
INSERT INTO `updates` VALUES ('2021_10_16_00_auth.sql', 'FDC45C7BEFBAFC9BCE6C77377B026A59AE52EE21', 'ARCHIVED', '2021-10-16 19:24:39', '0');
INSERT INTO `updates` VALUES ('2021_10_22_00_auth.sql', '07D7397061A5A906357DC6E91FC33C74638EFDC3', 'ARCHIVED', '2021-11-17 21:21:03', '0');
INSERT INTO `updates` VALUES ('2021_10_23_00_auth.sql', '97A8F2C2CEDB99C942D38F5B65DAD1DC11296E20', 'ARCHIVED', '2021-10-23 08:00:00', '0');
INSERT INTO `updates` VALUES ('2021_10_26_00_auth.sql', '91E8B308267847569D9A669BC34794F154242ECF', 'ARCHIVED', '2021-10-26 08:41:04', '0');
INSERT INTO `updates` VALUES ('2021_11_05_00_auth.sql', '4A4510436578B6486E8399602D3060376E96A8C7', 'ARCHIVED', '2021-11-05 08:33:00', '0');
INSERT INTO `updates` VALUES ('2021_11_06_00_auth.sql', '3646F9356429CCE7C1CECC7D9BA7960E011C7B6B', 'ARCHIVED', '2021-11-06 19:54:12', '0');
INSERT INTO `updates` VALUES ('2021_11_10_00_auth.sql', 'EB3D26EFD3109BC17447B3BAC7573473F5103F65', 'ARCHIVED', '2021-11-10 22:07:05', '0');
INSERT INTO `updates` VALUES ('2021_11_12_00_auth.sql', '012C088794362FE57BAEA0C3BD05356B40289028', 'ARCHIVED', '2021-11-12 20:17:24', '0');
INSERT INTO `updates` VALUES ('2021_11_17_00_auth.sql', '298DA8468B30042B15FA17A90325C72879DF6D8E', 'ARCHIVED', '2021-11-17 21:23:17', '0');
INSERT INTO `updates` VALUES ('2021_11_19_00_auth.sql', 'BE4F77E254D76A59DBF28B2CEEA5CAF6777B650E', 'ARCHIVED', '2021-11-19 08:37:56', '0');
INSERT INTO `updates` VALUES ('2021_11_20_00_auth.sql', 'E476B6DAD9C47FC81E1DA5016DC79AB527F1847A', 'ARCHIVED', '2021-11-21 02:40:53', '0');
INSERT INTO `updates` VALUES ('2021_11_25_00_auth.sql', '7A01CEB201CB825BFD565BBF5EED0162BEA733E7', 'ARCHIVED', '2021-11-26 03:32:21', '0');
INSERT INTO `updates` VALUES ('2021_12_02_00_auth.sql', 'ED40A45A8F5E5B1BB68216A3053D721B3BA3A556', 'ARCHIVED', '2021-12-02 19:48:11', '0');
INSERT INTO `updates` VALUES ('2021_12_04_00_auth.sql', '00C4A37A60F53A5E893CAADAC882E5A28375A4D2', 'ARCHIVED', '2021-12-04 20:49:04', '0');
INSERT INTO `updates` VALUES ('2021_12_08_00_auth.sql', '9B1A7C86F56159CA50A45B9CB4BC6422A3378231', 'ARCHIVED', '2021-12-08 08:28:19', '0');
INSERT INTO `updates` VALUES ('2021_12_16_00_auth.sql', 'EF5050D779CC6CEAAFB4C7E0CFA26824D92B675E', 'ARCHIVED', '2021-12-16 20:21:11', '0');
INSERT INTO `updates` VALUES ('2021_12_31_00_auth.sql', '16AA1CFB93CC42DC9CC7C0C787C64D3CE9662EE5', 'ARCHIVED', '2022-01-03 05:18:52', '0');
INSERT INTO `updates` VALUES ('2021_12_31_01_auth.sql', '336E62A8850A3E78A1D0BD3E81FFD5769184BDF8', 'ARCHIVED', '2021-12-31 23:58:32', '0');
INSERT INTO `updates` VALUES ('2022_01_02_00_auth.sql', 'F0AF198C5F7529508A5DB1F29D153256368AD1B4', 'ARCHIVED', '2022-01-03 05:22:35', '0');
INSERT INTO `updates` VALUES ('2022_01_08_00_auth.sql', '3C9853058A77817DD62943D0332418D84CA6BDA1', 'ARCHIVED', '2022-01-16 07:21:37', '0');
INSERT INTO `updates` VALUES ('2022_01_15_00_auth.sql', '11552D29BEDF73626FB8D932AB4362882964B4F0', 'ARCHIVED', '2022-01-16 07:24:57', '0');
INSERT INTO `updates` VALUES ('2022_01_22_00_auth.sql', '24A9BB761E805608EFDD8F647BF733602B337018', 'ARCHIVED', '2022-01-22 09:39:01', '0');
INSERT INTO `updates` VALUES ('2022_02_25_00_auth.sql', '1556FEDB9B46643634AE5BD0E38E7FF447FFC081', 'ARCHIVED', '2022-02-25 20:39:15', '0');
INSERT INTO `updates` VALUES ('2022_02_26_00_auth.sql', '955F8E13B0D91CA06FEEAD4E6C75E5495DA6DDF3', 'ARCHIVED', '2022-02-26 09:01:22', '0');
INSERT INTO `updates` VALUES ('2022_03_01_00_auth.sql', '53636BBB7DF4FFC2496456C1EEF2BD271D1C87E0', 'ARCHIVED', '2022-03-02 00:07:38', '0');
INSERT INTO `updates` VALUES ('2022_03_02_00_auth.sql', '928C11D145B98E90FB82D2A871C2456C848AB6C1', 'ARCHIVED', '2022-03-02 18:10:19', '0');
INSERT INTO `updates` VALUES ('2022_03_03_00_auth.sql', '408CCCF7D47FB5C876E976F883B4BDBFFEC5D146', 'ARCHIVED', '2022-03-03 09:09:55', '0');
INSERT INTO `updates` VALUES ('2022_03_06_00_auth.sql', '2883FD8D2CB8B2FC3DF7D20D3216301262E7A7C3', 'ARCHIVED', '2022-03-06 23:12:24', '0');
INSERT INTO `updates` VALUES ('2022_03_08_00_auth.sql', 'E2C6B4E26FE55F5827C587CD668F6518EB2B51E8', 'ARCHIVED', '2022-03-08 23:24:10', '0');
INSERT INTO `updates` VALUES ('2022_03_12_00_auth.sql', '1A476DB06BC1F096E6F15225078373B3AD094C1B', 'ARCHIVED', '2022-03-12 13:52:02', '0');
INSERT INTO `updates` VALUES ('2022_03_22_00_auth.sql', '16A58234A1EF4F13ABD6EF78733BDBF5152AA70C', 'ARCHIVED', '2022-03-22 08:32:54', '0');
INSERT INTO `updates` VALUES ('2022_03_25_00_auth.sql', '173D4F7B5417AF11DDDE6EC1A58ECFA6783C7FAF', 'ARCHIVED', '2022-03-25 08:26:53', '0');
INSERT INTO `updates` VALUES ('2022_03_30_00_auth.sql', '37177AB41D7DF26CF4F908C0522EDEAF13094D7E', 'ARCHIVED', '2022-03-30 08:37:34', '0');
INSERT INTO `updates` VALUES ('2022_03_30_01_auth.sql', 'AACD3E4E8673F6D90677C97D5B0B0F292D0C1763', 'ARCHIVED', '2022-03-30 12:28:42', '0');
INSERT INTO `updates` VALUES ('2022_04_08_00_auth.sql', 'C0BE7634D6B84D860111AF5EEDF1D023875F3137', 'ARCHIVED', '2022-04-09 05:01:16', '0');
INSERT INTO `updates` VALUES ('2022_04_14_00_auth.sql', '4D79D1C7282CA8F1626D957AF17E711BFF94334B', 'ARCHIVED', '2022-04-14 12:39:49', '0');
INSERT INTO `updates` VALUES ('2022_04_22_00_auth.sql', '835EE2D6981AD7A7467490242D6A4B0E0B69E4F4', 'ARCHIVED', '2022-04-23 04:04:53', '0');
INSERT INTO `updates` VALUES ('2022_05_03_00_auth.sql', '0874FBE9821F2659BA51B91E9D69B9E6CA6D2EC9', 'ARCHIVED', '2022-05-03 19:07:21', '0');
INSERT INTO `updates` VALUES ('2022_06_01_00_auth.sql', 'DCFC7EC6C52993769B568EAF87CA2DAA10359AEB', 'ARCHIVED', '2022-06-02 08:52:17', '0');
INSERT INTO `updates` VALUES ('2022_06_06_00_auth.sql', '68D73F068598D37FD6FBC84362F1BA7BA4EC2709', 'ARCHIVED', '2022-06-07 05:35:16', '0');
INSERT INTO `updates` VALUES ('2022_06_07_00_auth.sql', '76B4D21F13B0024445E5C0B48C630C1DF7E80966', 'ARCHIVED', '2022-06-08 00:09:58', '0');
INSERT INTO `updates` VALUES ('2022_06_08_00_auth.sql', '250081465C76AC9668E3F66D386CE2AAC05379E9', 'ARCHIVED', '2022-06-08 18:45:01', '0');
INSERT INTO `updates` VALUES ('2022_06_09_00_auth.sql', '29C2A4209FB977373440666F00B2E04F0E095247', 'ARCHIVED', '2022-06-10 02:31:38', '0');
INSERT INTO `updates` VALUES ('2022_06_15_00_auth.sql', '137223C2750CC3559EFE11AFF1A780D5DA070193', 'ARCHIVED', '2022-06-15 19:16:51', '0');
INSERT INTO `updates` VALUES ('2022_06_18_00_auth.sql', '63B75F9D79D83581AB3257C9EF86EDB626D8FDDA', 'ARCHIVED', '2022-06-18 19:48:42', '0');
INSERT INTO `updates` VALUES ('2022_06_27_00_auth.sql', 'CF613CCAAF8B6F08AAE1C48DBC4AF4D224291D8D', 'ARCHIVED', '2022-06-28 05:13:58', '0');
INSERT INTO `updates` VALUES ('2022_07_23_00_auth.sql', 'FEA7A8DA363F097A090F3BB39401C3FD7AE8E9B5', 'ARCHIVED', '2022-07-26 02:40:38', '0');
INSERT INTO `updates` VALUES ('2022_07_25_00_auth.sql', '8F5BA8F7E010EDCA70F49FDE947B2F89476A2F95', 'ARCHIVED', '2022-07-26 02:44:10', '0');
INSERT INTO `updates` VALUES ('2022_08_02_00_auth.sql', '4B97D20928B05086C7863497F4DDD408A51619BE', 'ARCHIVED', '2022-08-03 02:28:31', '0');
INSERT INTO `updates` VALUES ('2022_08_17_00_auth.sql', '1A45DAE660690A7F4D0822C514116BF44A3185BB', 'ARCHIVED', '2022-08-17 18:16:00', '0');
INSERT INTO `updates` VALUES ('2022_08_19_00_auth.sql', '332E7CC2E69D69BF274E5C61768FB80D1C217BDB', 'ARCHIVED', '2022-08-19 17:52:06', '0');
INSERT INTO `updates` VALUES ('2022_08_19_01_auth.sql', '8B32826AE09C27B98C9480EF4D61205666F68318', 'ARCHIVED', '2022-08-20 07:43:01', '0');
INSERT INTO `updates` VALUES ('2022_08_21_00_auth.sql', '5DEC0CB848F99D575B90356D82276749F2473B72', 'ARCHIVED', '2022-08-21 08:02:03', '0');
INSERT INTO `updates` VALUES ('2022_09_02_00_auth.sql', 'E2ED8B4B90829CFD283C9679AE265A9C9B2CF762', 'ARCHIVED', '2022-09-02 23:52:22', '0');
INSERT INTO `updates` VALUES ('2022_09_08_00_auth.sql', '20B4503E316E042432AC25F7CEE9DCD9EDC631C6', 'ARCHIVED', '2022-09-08 23:38:35', '0');
INSERT INTO `updates` VALUES ('2022_09_23_00_auth.sql', 'F7DB1B903982D99295BC0D7D2BC205C5A2145F03', 'ARCHIVED', '2022-09-23 11:44:55', '0');
INSERT INTO `updates` VALUES ('2022_10_03_00_auth.sql', 'B956A37F71B42EB0289C2066A15D1F6C02F21E5A', 'ARCHIVED', '2022-10-04 05:32:38', '0');
INSERT INTO `updates` VALUES ('2022_11_20_00_auth.sql', '37123D83589CFD96472D9187799C1F3FD67645DD', 'ARCHIVED', '2022-11-20 19:05:20', '0');
INSERT INTO `updates` VALUES ('2022_12_16_00_auth.sql', '249B00480ACC8B67C908435748C202D8363C6EDE', 'ARCHIVED', '2022-12-17 06:39:07', '0');
INSERT INTO `updates` VALUES ('2022_12_17_00_auth.sql', '0D3963AC2DBF74A4C8B88EA4A680C046FCCF8E70', 'ARCHIVED', '2022-12-17 15:34:53', '0');
INSERT INTO `updates` VALUES ('2022_12_17_01_auth.sql', '5D1E2EA3C3CE087F7FB647CD0DE000979961863C', 'ARCHIVED', '2022-12-17 21:09:19', '0');
INSERT INTO `updates` VALUES ('2022_12_20_00_auth.sql', 'BA88146743B060A14937688C0DB94BF11C6CF1BA', 'ARCHIVED', '2022-12-20 11:10:07', '0');
INSERT INTO `updates` VALUES ('2022_12_21_00_auth.sql', 'B395CAE993D65E035AA621941D4C384E2E2E7DF5', 'ARCHIVED', '2022-12-21 09:16:56', '0');
INSERT INTO `updates` VALUES ('2022_12_22_00_auth.sql', 'BBF3CDD7927520F0381ECEF1F30152CBD5344D6A', 'ARCHIVED', '2022-12-23 00:35:36', '0');
INSERT INTO `updates` VALUES ('2023_01_17_00_auth.sql', 'EAEA99DF10DCC648C161D836FFA681D5B0F4CDC3', 'ARCHIVED', '2023-01-19 18:36:32', '0');
INSERT INTO `updates` VALUES ('2023_01_17_01_auth.sql', 'DF84961EEF8B62328C6938F491D3135B1C3B52A6', 'RELEASED', '2023-01-19 18:36:33', '0');
INSERT INTO `updates` VALUES ('2023_01_17_02_auth.sql', 'F2117E84822ED226DA0F18BE6432F2B0C80CF300', 'RELEASED', '2023-01-19 19:51:32', '0');
INSERT INTO `updates` VALUES ('2023_01_28_00_auth.sql', '94A640018494B9203100178EC67A582987456B8B', 'ARCHIVED', '2023-01-28 15:01:25', '0');
INSERT INTO `updates` VALUES ('2023_01_28_01_auth.sql', 'EB4FA45E814BA43C262F9DDAC8D9846218B66038', 'ARCHIVED', '2023-01-28 15:14:52', '0');
INSERT INTO `updates` VALUES ('2023_01_28_02_auth.sql', '200752607ED6436B36EF88D744001558FD67C487', 'RELEASED', '2023-01-28 15:22:40', '0');
INSERT INTO `updates` VALUES ('2023_01_28_03_auth.sql', '55EDD1BF490E11BC74F5C89A9CEB9AFBBCBAE334', 'RELEASED', '2023-01-28 15:30:45', '0');
INSERT INTO `updates` VALUES ('2023_01_28_04_auth.sql', 'A99AA3B2A99F49F2D6AF881362276D980D0A332E', 'RELEASED', '2023-01-29 14:09:35', '0');
INSERT INTO `updates` VALUES ('2023_01_28_05_auth.sql', '4BDA614300858ADE6D58A119680724D867B0A355', 'RELEASED', '2023-01-29 14:09:35', '0');
INSERT INTO `updates` VALUES ('2023_02_01_00_auth.sql', '9C1FB6820EF3A543AB7DE2E2913014AFF445F91E', 'ARCHIVED', '2023-02-01 23:47:49', '0');
INSERT INTO `updates` VALUES ('2023_02_01_01_auth.sql', 'FFE821A15CDA461C7B1E1971C38512FF7BD556EC', 'RELEASED', '2023-02-02 09:46:43', '0');
INSERT INTO `updates` VALUES ('2023_02_02_00_auth.sql', '8AC163759C83D887D5D7A48CFB8272FFBA71B801', 'ARCHIVED', '2023-02-03 14:07:51', '0');
INSERT INTO `updates` VALUES ('2023_02_03_00_auth.sql', '0309A99757DE1FAE595C6C32586B2B8F8CA4C134', 'RELEASED', '2023-02-03 14:07:51', '191');

-- ----------------------------
-- Table structure for `updates_include`
-- ----------------------------
DROP TABLE IF EXISTS `updates_include`;
CREATE TABLE `updates_include` (
  `path` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
  `state` enum('RELEASED','ARCHIVED') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
  PRIMARY KEY (`path`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='List of directories where we want to include sql updates.';

-- ----------------------------
-- Records of updates_include
-- ----------------------------
INSERT INTO `updates_include` VALUES ('$/sql/custom/auth', 'RELEASED');
INSERT INTO `updates_include` VALUES ('$/sql/old/10.x/auth', 'ARCHIVED');
INSERT INTO `updates_include` VALUES ('$/sql/old/6.x/auth', 'ARCHIVED');
INSERT INTO `updates_include` VALUES ('$/sql/old/7/auth', 'ARCHIVED');
INSERT INTO `updates_include` VALUES ('$/sql/old/8.x/auth', 'ARCHIVED');
INSERT INTO `updates_include` VALUES ('$/sql/old/9.x/auth', 'ARCHIVED');
INSERT INTO `updates_include` VALUES ('$/sql/updates/auth', 'RELEASED');

-- ----------------------------
-- Table structure for `uptime`
-- ----------------------------
DROP TABLE IF EXISTS `uptime`;
CREATE TABLE `uptime` (
  `realmid` int(10) unsigned NOT NULL,
  `starttime` int(10) unsigned NOT NULL DEFAULT '0',
  `uptime` int(10) unsigned NOT NULL DEFAULT '0',
  `maxplayers` smallint(5) unsigned NOT NULL DEFAULT '0',
  `revision` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'Trinitycore',
  PRIMARY KEY (`realmid`,`starttime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Uptime system';

-- ----------------------------
-- Records of uptime
-- ----------------------------
INSERT INTO `uptime` VALUES ('1', '1672564754', '6195', '1', 'TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1672622929', '24199', '1', 'TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1672726450', '803', '0', 'TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1672730847', '804', '1', 'TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1672731803', '0', '0', 'TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673089200', '15199', '1', 'TrinityCore rev. d2c455809f78+ 2023-01-07 18:36:20 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673167685', '3806', '1', 'TrinityCore rev. 1c9faae591c4+ 2023-01-08 09:32:46 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673184398', '807', '1', 'TrinityCore rev. 30fceec3d3fc+ 2023-01-08 20:20:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673311996', '0', '0', 'TrinityCore rev. 30fceec3d3fc+ 2023-01-08 20:20:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673318027', '2607', '1', 'TrinityCore rev. 30fceec3d3fc+ 2023-01-08 20:20:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673323869', '12218', '1', 'TrinityCore rev. 30fceec3d3fc+ 2023-01-08 20:20:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673336767', '806', '0', 'TrinityCore rev. 48603c022381+ 2023-01-10 15:34:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673339338', '0', '0', 'TrinityCore rev. 3065b2596538+ 2023-01-10 16:16:02 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673340086', '2008', '1', 'TrinityCore rev. 374fe5e2d67b 2023-01-10 16:40:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673856001', '0', '0', 'TrinityCore rev. a32ff6ee8102 2023-01-11 19:42:13 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673858124', '0', '0', 'TrinityCore rev. a32ff6ee8102 2023-01-11 19:42:13 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673873967', '1613', '1', 'TrinityCore rev. d19bd359cbd3 2023-01-16 19:47:53 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673945608', '810', '1', 'TrinityCore rev. 8de6cf78445d 2023-01-17 11:36:29 +0800 (尝试合并TCBased branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673956108', '808', '1', 'TrinityCore rev. 8de6cf78445d 2023-01-17 11:36:29 +0800 (尝试合并TCBased branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1673963682', '0', '0', 'TrinityCore rev. b1798d1b7dc9 2023-01-17 21:49:58 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674033213', '1408', '1', 'TrinityCore rev. b1798d1b7dc9 2023-01-17 21:49:58 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674036798', '0', '0', 'TrinityCore rev. b1798d1b7dc9 2023-01-17 21:49:58 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674124588', '0', '0', 'TrinityCore rev. b1798d1b7dc9 2023-01-17 21:49:58 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674129088', '0', '0', 'TrinityCore rev. b1798d1b7dc9 2023-01-17 21:49:58 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674460357', '0', '0', 'TrinityCore rev. 9eca7bee1dfa 2023-01-23 14:57:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674559840', '5620', '1', 'TrinityCore rev. 24517021e043 2023-01-24 16:21:53 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674573838', '2011', '1', 'TrinityCore rev. 24517021e043 2023-01-24 16:21:53 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674604967', '0', '0', 'TrinityCore rev. 24517021e043+ 2023-01-24 16:21:53 +0800 (spell_hunter branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674606967', '0', '0', 'TrinityCore rev. 24517021e043+ 2023-01-24 16:21:53 +0800 (spell_hunter branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674608717', '3219', '1', 'TrinityCore rev. 24517021e043+ 2023-01-24 16:21:53 +0800 (spell_hunter branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674632239', '2017', '1', 'TrinityCore rev. 24517021e043+ 2023-01-24 16:21:53 +0800 (spell_hunter branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674635422', '0', '0', 'TrinityCore rev. add722d72815+ 2023-01-25 16:21:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674637163', '0', '0', 'TrinityCore rev. efd837dca49f+ 2023-01-25 16:39:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674639015', '0', '0', 'TrinityCore rev. 218b93c5d597+ 2023-01-25 17:08:01 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674639780', '0', '0', 'TrinityCore rev. 218b93c5d597+ 2023-01-25 17:08:01 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674640666', '810', '0', 'TrinityCore rev. 218b93c5d597+ 2023-01-25 17:08:01 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674641638', '814', '0', 'TrinityCore rev. 218b93c5d597+ 2023-01-25 17:08:01 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674784797', '22411', '1', 'TrinityCore rev. 9f23d5d7081d+ 2023-01-27 09:51:44 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674807953', '4403', '1', 'TrinityCore rev. 69b65fec89b5 2023-01-27 16:25:00 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674813726', '0', '0', 'TrinityCore rev. a1b35b906985 2023-01-27 17:56:46 +0800 (tcbots-master-src-modules-Bots branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674889281', '0', '0', 'TrinityCore rev. 47d851f3a1bc 2023-01-28 14:57:47 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674890091', '0', '0', 'TrinityCore rev. 47d851f3a1bc 2023-01-28 14:57:47 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674890559', '0', '0', 'TrinityCore rev. 47d851f3a1bc 2023-01-28 14:57:47 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674891044', '70406', '1', 'TrinityCore rev. 47d851f3a1bc 2023-01-28 14:57:47 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674973223', '1404', '1', 'TrinityCore rev. 27373663515b 2023-01-29 11:22:11 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1674990328', '16509', '1', 'TrinityCore rev. 27373663515b 2023-01-29 11:22:11 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675007160', '845', '1', 'TrinityCore rev. 27373663515b 2023-01-29 11:22:11 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675038591', '864', '1', 'TrinityCore rev. c3df2012a89e 2023-01-30 08:23:04 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675047381', '0', '0', 'TrinityCore rev. c3df2012a89e 2023-01-30 08:23:04 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675047943', '844', '1', 'TrinityCore rev. c3df2012a89e 2023-01-30 08:23:04 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675049651', '7442', '0', 'TrinityCore rev. 64c2e56ac24c 2023-01-30 11:32:16 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675057736', '2044', '1', 'TrinityCore rev. 64c2e56ac24c 2023-01-30 11:32:16 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675060998', '3240', '0', 'TrinityCore rev. 64c2e56ac24c 2023-01-30 11:32:16 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675066063', '3845', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675070318', '1445', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675072118', '10443', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675082906', '9841', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675094845', '0', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675129187', '0', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675130174', '0', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675136486', '6855', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675143065', '0', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675143353', '1457', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675146621', '5662', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675152965', '1461', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675154479', '0', '0', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675155650', '2661', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675162127', '48861', '1', 'TrinityCore rev. a2cb98ab5a0a+ 2023-01-30 16:04:37 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675212349', '2660', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675218368', '856', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675221292', '8118', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675230312', '0', '0', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675231463', '0', '0', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675232416', '0', '0', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675233620', '866', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675238084', '2076', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675246300', '0', '0', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675249204', '15339', '1', 'TrinityCore rev. 6e43d8abae54 2023-02-01 08:41:38 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675265423', '0', '0', 'TrinityCore rev. 2728301c9a76+ 2023-02-01 23:27:12 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675266468', '0', '0', 'TrinityCore rev. 2728301c9a76+ 2023-02-01 23:27:12 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675267158', '0', '0', 'TrinityCore rev. 2728301c9a76+ 2023-02-01 23:27:12 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675267967', '0', '0', 'TrinityCore rev. 2728301c9a76+ 2023-02-01 23:27:12 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675300974', '816', '0', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675302401', '2071', '1', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675304829', '13034', '1', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675322505', '2088', '1', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675326421', '881', '1', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675328167', '3275', '1', 'TrinityCore rev. 41724b3feb67 2023-02-02 09:19:42 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675389693', '4483', '1', 'TrinityCore rev. b4bec1c95cd0 2023-02-03 00:30:05 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675404467', '2250', '1', 'TrinityCore rev. b4bec1c95cd0 2023-02-03 00:30:05 +0800 (master branch) (Win64, Debug, Static)');
INSERT INTO `uptime` VALUES ('1', '1675418725', '1482', '1', 'TrinityCore rev. 69524511b21f+ 2023-02-03 14:12:12 +0800 (playerAI-smallStep branch) (Win64, Debug, Static)');

-- ----------------------------
-- View structure for `vw_log_history`
-- ----------------------------
DROP VIEW IF EXISTS `vw_log_history`;
CREATE ALGORITHM=UNDEFINED DEFINER=`trinity`@`localhost` SQL SECURITY DEFINER VIEW `vw_log_history` AS select from_unixtime(min(`logs`.`time`)) AS `First Logged`,from_unixtime(max(`logs`.`time`)) AS `Last Logged`,count(0) AS `Occurrences`,`realmlist`.`name` AS `Realm`,`logs`.`type` AS `type`,`logs`.`level` AS `level`,`logs`.`string` AS `string` from (`logs` left join `realmlist` on((`logs`.`realm` = `realmlist`.`id`))) group by `logs`.`string`,`logs`.`type`,`logs`.`realm`;

-- ----------------------------
-- View structure for `vw_rbac`
-- ----------------------------
DROP VIEW IF EXISTS `vw_rbac`;
CREATE ALGORITHM=UNDEFINED DEFINER=`trinity`@`localhost` SQL SECURITY DEFINER VIEW `vw_rbac` AS select `t1`.`linkedId` AS `Permission ID`,`t1`.`id` AS `Permission Group`,ifnull(`t2`.`secId`,'linked') AS `Security Level`,`t3`.`name` AS `Permission` from ((`rbac_linked_permissions` `t1` left join `rbac_default_permissions` `t2` on((`t1`.`id` = `t2`.`permissionId`))) left join `rbac_permissions` `t3` on((`t1`.`linkedId` = `t3`.`id`)));
