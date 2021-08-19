--
-- Table structure for table `character_spell_location`
--
DROP TABLE IF EXISTS `character_aura_stored_location`;
CREATE TABLE `character_aura_stored_location` (
  `Guid` bigint(20) unsigned NOT NULL COMMENT 'Global Unique Identifier of Player',
  `Spell` int(10) unsigned NOT NULL COMMENT 'Spell Identifier',
  `MapId` int(10) unsigned NOT NULL COMMENT 'Map Id',
  `PositionX` float NOT NULL COMMENT 'position x',
  `PositionY` float NOT NULL COMMENT 'position y',
  `PositionZ` float NOT NULL COMMENT 'position z',
  `Orientation` float NOT NULL COMMENT 'Orientation',
  PRIMARY KEY (`Guid`,`Spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
