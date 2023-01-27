/*!40101 SET NAMES utf8 */;

DROP TABLE IF EXISTS `character_battle_pet_journal`;
DROP TABLE IF EXISTS `character_battle_pet`;
DROP TABLE IF EXISTS `account_battle_pet_journal`;
DROP TABLE IF EXISTS `account_battle_pet`;

CREATE TABLE `account_battle_pet` (
  `ownerAccID` int(11) unsigned NOT NULL DEFAULT '0',
  `slot_0` bigint(40) unsigned NOT NULL DEFAULT '0',
  `slot_1` bigint(40) unsigned NOT NULL DEFAULT '0',
  `slot_2` bigint(40) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ownerAccID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `account_battle_pet_journal` (
  `ownerAccID` int(11) unsigned NOT NULL DEFAULT '0',
  `guid` bigint(40) unsigned NOT NULL,
  `customName` varchar(255) COLLATE utf8_unicode_ci DEFAULT '""',
  `creatureEntry` int(11) unsigned DEFAULT '0',
  `speciesID` int(11) unsigned DEFAULT '0',
  `spell` int(11) unsigned DEFAULT '0',
  `level` tinyint(4) unsigned DEFAULT '0',
  `displayID` int(11) unsigned DEFAULT '0',
  `power` smallint(6) unsigned DEFAULT '0',
  `speed` smallint(6) unsigned DEFAULT '0',
  `health` int(11) unsigned DEFAULT '0',
  `maxHealth` int(11) unsigned DEFAULT '0',
  `quality` tinyint(4) unsigned DEFAULT '0',
  `xp` smallint(6) unsigned DEFAULT '0',
  `flags` smallint(11) unsigned DEFAULT '0',
  `breedID` smallint(6) DEFAULT '0',
  PRIMARY KEY (`guid`,`ownerAccID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
