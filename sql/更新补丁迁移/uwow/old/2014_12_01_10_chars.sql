DROP TABLE IF EXISTS `character_battle_pet`;

CREATE TABLE `character_battle_pet` (
  `ownerAccID` int(11) unsigned NOT NULL DEFAULT '0',
  `slot_0` bigint(40) unsigned NOT NULL DEFAULT '0',
  `slot_1` bigint(40) unsigned NOT NULL DEFAULT '0',
  `slot_2` bigint(40) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '7',
  PRIMARY KEY (`ownerAccID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;