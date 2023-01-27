DROP TABLE IF EXISTS `character_battle_pet_journal`;

CREATE TABLE `character_battle_pet_journal` (
  `guid` int(10) unsigned NOT NULL,
  `ownerAccID` int(10) unsigned NOT NULL DEFAULT '0',
  `creatureEntry` mediumint(8) DEFAULT '0',
  `speciesID` mediumint(8) DEFAULT '0',
  `level` mediumint(8) DEFAULT '0',
  `displayID` mediumint(8) DEFAULT '0',
  `power` mediumint(8) DEFAULT '0',
  `speed` mediumint(8) DEFAULT '0',
  `health` mediumint(8) DEFAULT '0',
  `maxHealth` mediumint(8) DEFAULT '0',
  `quality` mediumint(8) DEFAULT '0',
  `xp` mediumint(8) DEFAULT '0',
  `flags` mediumint(8) DEFAULT '0',
  PRIMARY KEY (`guid`,`ownerAccID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

DROP TABLE IF EXISTS `character_battle_pet`;

CREATE TABLE `character_battle_pet` (
  `guid` int(10) unsigned NOT NULL,
  `slot` tinyint(3) DEFAULT '0',
  `spell1` mediumint(8) DEFAULT '0',
  `spell2` mediumint(8) DEFAULT '0',
  `spell3` mediumint(8) DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

