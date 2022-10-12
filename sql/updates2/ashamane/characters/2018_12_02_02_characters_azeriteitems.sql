
DROP TABLE IF EXISTS `item_azerite`;
CREATE TABLE `item_azerite` (
  `CharacterGuid` bigint(20) unsigned NOT NULL,
  `ItemGuid` bigint(20) unsigned NOT NULL,
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `Xp` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`CharacterGuid`,`ItemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `item_azerite_empowered`;
CREATE TABLE `item_azerite_empowered` (
  `CharacterGuid` bigint(20) unsigned NOT NULL,
  `ItemGuid` bigint(20) unsigned NOT NULL,
  `PowereId1` int(10) unsigned NOT NULL DEFAULT '0',
  `PowereId2` int(10) unsigned NOT NULL DEFAULT '0',
  `PowereId3` int(10) unsigned NOT NULL DEFAULT '0',
  `PowereId4` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`CharacterGuid`,`ItemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
