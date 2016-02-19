--
DROP TABLE IF EXISTS `characters_trans`;
CREATE TABLE `characters_trans` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `trans_x` float NOT NULL DEFAULT '0',
  `trans_y` float NOT NULL DEFAULT '0',
  `trans_z` float NOT NULL DEFAULT '0',
  `trans_o` float NOT NULL DEFAULT '0',
  `transguid` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_deleted`;
CREATE TABLE `characters_deleted` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `deleteInfos_Account` int(10) unsigned DEFAULT NULL,
  `deleteInfos_Name` varchar(12) DEFAULT NULL,
  `deleteDate` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_at_login`;
CREATE TABLE `characters_at_login` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `at_login` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_drunk`;
CREATE TABLE `characters_drunk` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `drunk` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_grantableLevels`;
CREATE TABLE `characters_grantableLevels` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `grantableLevels` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_stable_slots`;
CREATE TABLE `characters_stable_slots` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `stable_slots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_taxi_path`;
CREATE TABLE `characters_taxi_path` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `taxi_path` text,
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_resettalents`;
CREATE TABLE `characters_resettalents` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `resettalents_cost` int(10) unsigned NOT NULL DEFAULT '0',
  `resettalents_time` int(10) unsigned NOT NULL DEFAULT '0',  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_title`;
CREATE TABLE `characters_title` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `chosenTitle` int(10) unsigned NOT NULL DEFAULT '0',
  `knownTitles` longtext,
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters_pvp_stats`;
CREATE TABLE `characters_pvp_stats` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `arenaPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `totalHonorPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `todayHonorPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `yesterdayHonorPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `totalKills` int(10) unsigned NOT NULL DEFAULT '0',
  `todayKills` smallint(5) unsigned NOT NULL DEFAULT '0',
  `yesterdayKills` smallint(5) unsigned NOT NULL DEFAULT '0'
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_enchantments`;
CREATE TABLE `item_instance_enchantments` (
  `guid` int(11) unsigned NOT NULL,
  `EnchantmentID_1`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_1` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_1`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_2`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_2` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_2`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_3`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_3` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_3`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_4`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_4` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_4`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_5`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_5` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_5`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_6`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_6` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_6`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_7`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_7` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_7`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_8`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_8` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_8`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_9`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_9` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_9`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_10`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_10` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_10`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_11`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_11` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_11`  int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentID_12`       int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentDuration_12` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantmentCharges_12`  int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_charges`;
CREATE TABLE `item_instance_charges` (
  `guid` int(11) unsigned NOT NULL,
  `charge_1` int(10) NOT NULL DEFAULT '0',
  `charge_2` int(10) NOT NULL DEFAULT '0',
  `charge_3` int(10) NOT NULL DEFAULT '0',
  `charge_4` int(10) NOT NULL DEFAULT '0',
  `charge_5` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_creator`;
CREATE TABLE `item_instance_creator` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `creatorGuid` int(10) unsigned NOT NULL DEFAULT '0',
  `giftCreatorGuid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_text`;
CREATE TABLE `item_instance_text` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `text` text,
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_duration`;
CREATE TABLE `item_instance_duration` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `duration` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_randomPropertyId`;
CREATE TABLE `item_instance_randomPropertyId` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `randomPropertyId` smallint(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_instance_played_time`;
CREATE TABLE `item_instance_played_time` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `playedTime` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

INSERT INTO characters_trans (`guid`, `trans_x`, `trans_y`, `trans_z`, `trans_o`, `transguid`)
(SELECT characters.guid, characters.trans_x, characters.trans_y, characters.trans_z, characters.trans_o, characters.transguid FROM characters WHERE characters.trans_x != 0);

INSERT INTO characters_deleted (`guid`, `deleteInfos_Account`, `deleteInfos_Name`, `deleteDate`)
(SELECT characters.guid, characters.deleteInfos_Account, characters.deleteInfos_Name, characters.deleteDate FROM characters WHERE characters.deleteInfos_Account IS NOT NULL);

INSERT INTO characters_at_login (`guid`, `at_login`)
(SELECT characters.guid, characters.at_login FROM characters WHERE characters.at_login >0);

INSERT INTO characters_drunk (`guid`, `drunk`)
(SELECT characters.guid, characters.drunk FROM characters WHERE characters.drunk >0);

INSERT INTO characters_grantableLevels (`guid`, `grantableLevels`)
(SELECT characters.guid, characters.grantableLevels FROM characters WHERE characters.grantableLevels >0);

INSERT INTO characters_stable_slots (`guid`, `stable_slots`)
(SELECT characters.guid, characters.stable_slots FROM characters WHERE characters.stable_slots >0);

INSERT INTO characters_taxi_path (`guid`, `taxi_path`)
(SELECT characters.guid, characters.taxi_path FROM characters WHERE characters.taxi_path <> '');

INSERT INTO characters_resettalents (`guid`, `resettalents_cost`, `resettalents_time`)
(SELECT characters.guid, characters.resettalents_cost, characters.resettalents_time FROM characters WHERE characters.resettalents_cost >0);

INSERT INTO characters_title (`guid`, `chosenTitle`, `knownTitles`)
(SELECT characters.guid, characters.chosenTitle, characters.knownTitles FROM characters WHERE characters.chosenTitle >0 OR characters.knownTitles <> "0 0 0 0 0 0");

INSERT INTO characters_pvp_stats (`guid`, `arenaPoints`,`totalHonorPoints`,`todayHonorPoints`,`yesterdayHonorPoints`,`totalKills`,`todayKills`,`yesterdayKills`)
(SELECT characters.guid, characters.arenaPoints, characters.totalHonorPoints, characters.todayHonorPoints, characters.yesterdayHonorPoints, characters.totalKills, characters.todayKills, characters.yesterdayKills FROM characters WHERE characters.arenaPoints >0 OR characters.totalHonorPoints >0 OR todayHonorPoints >0 OR yesterdayHonorPoints >0 OR totalKills >0 OR todayKills >0 OR yesterdayKills >0);

INSERT INTO item_instance_text (`guid`, `text`)
(SELECT item_instance.guid, item_instance.text FROM item_instance WHERE item_instance.text <> '');

INSERT INTO item_instance_creator (`guid`, `creatorGuid`, `giftCreatorGuid`)
(SELECT item_instance.guid, item_instance.creatorGuid, item_instance.giftCreatorGuid FROM item_instance WHERE item_instance.creatorGuid !=0 or item_instance.giftCreatorGuid !=0);

INSERT INTO `item_instance_charges`
SELECT `guid`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`charges`), ' ', 1),  ' ', -1) AS SIGNED)) AS `charge_1`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`charges`), ' ', 2),  ' ', -1) AS SIGNED)) AS `charge_2`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`charges`), ' ', 3),  ' ', -1) AS SIGNED)) AS `charge_3`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`charges`), ' ', 4),  ' ', -1) AS SIGNED)) AS `charge_4`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`charges`), ' ', 5),  ' ', -1) AS SIGNED)) AS `charge_5`
FROM `item_instance` WHERE TRIM(`charges`) <> '0 0 0 0 0';

INSERT INTO `item_instance_enchantments`
SELECT `guid`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 1),  ' ', -1) AS SIGNED)) AS  `EnchantmentID_1`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 2),  ' ', -1) AS SIGNED)) AS  `EnchantmentDuration_1`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 3),  ' ', -1) AS SIGNED)) AS  `EnchantmentCharges_1`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 4),  ' ', -1) AS SIGNED)) AS  `EnchantmentID_2`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 5),  ' ', -1) AS SIGNED)) AS  `EnchantmentDuration_2`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 6),  ' ', -1) AS SIGNED)) AS  `EnchantmentCharges_2`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 7),  ' ', -1) AS SIGNED)) AS  `EnchantmentID_3`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 8),  ' ', -1) AS SIGNED)) AS  `EnchantmentDuration_3`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 9),  ' ', -1) AS SIGNED)) AS  `EnchantmentCharges_3`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 10),  ' ', -1) AS SIGNED)) AS `EnchantmentID_4`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 11),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_4`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 12),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_4`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 13),  ' ', -1) AS SIGNED)) AS `EnchantmentID_5`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 14),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_5`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 15),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_5`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 16),  ' ', -1) AS SIGNED)) AS `EnchantmentID_6`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 17),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_6`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 18),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_6`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 19),  ' ', -1) AS SIGNED)) AS `EnchantmentID_7`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 20),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_7`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 21),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_7`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 22),  ' ', -1) AS SIGNED)) AS `EnchantmentID_8`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 23),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_8`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 24),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_8`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 25),  ' ', -1) AS SIGNED)) AS `EnchantmentID_9`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 26),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_9`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 27),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_9`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 28),  ' ', -1) AS SIGNED)) AS `EnchantmentID_10`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 29),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_10`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 30),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_10`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 31),  ' ', -1) AS SIGNED)) AS `EnchantmentID_11`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 32),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_11`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 33),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_11`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 34),  ' ', -1) AS SIGNED)) AS `EnchantmentID_12`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 35),  ' ', -1) AS SIGNED)) AS `EnchantmentDuration_12`,
(CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(TRIM(`enchantments`), ' ', 36),  ' ', -1) AS SIGNED)) AS `EnchantmentCharges_12`
FROM `item_instance` WHERE TRIM(`enchantments`) <> '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0';
INSERT INTO item_instance_duration (`guid`, `duration`)
(SELECT item_instance.guid, item_instance.duration FROM item_instance WHERE item_instance.duration > 0);

INSERT INTO item_instance_randomPropertyId (`guid`, `randomPropertyId`)
(SELECT item_instance.guid, item_instance.randomPropertyId FROM item_instance WHERE item_instance.randomPropertyId <> 0);

INSERT INTO item_instance_played_time (`guid`, `playedTime`)
(SELECT item_instance.guid, item_instance.playedTime FROM item_instance WHERE item_instance.playedTime <> 0);

ALTER TABLE `characters` DROP `trans_x`, DROP `trans_y`, DROP `trans_z`, DROP `trans_o`, DROP `transguid`,
                         DROP `deleteInfos_Account`, DROP `deleteInfos_Name`, DROP `deleteDate`,
                         DROP `at_login`, DROP `drunk`, DROP `grantableLevels`,
                         DROP `stable_slots`, DROP `taxi_path`,
                         DROP `resettalents_time`, DROP `resettalents_cost`,
                         DROP `arenaPoints`, DROP `totalHonorPoints`, DROP `todayHonorPoints`, DROP `yesterdayHonorPoints`,
                         DROP `totalKills`, DROP `todayKills`, DROP `yesterdayKills`,
                         DROP `chosenTitle`, DROP `knownTitles`;
ALTER TABLE `item_instance` DROP `text`, DROP `charges`, DROP `enchantments`, DROP `duration`, DROP `randomPropertyId`, DROP `creatorGuid`, DROP `giftCreatorGuid`, DROP `playedTime`;
