--
-- Table structure for table `character_spell_charges`
--

DROP TABLE IF EXISTS `character_spell_charges`;
CREATE TABLE `character_spell_charges` (
  `guid` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCategory.dbc Identifier',
  `rechargeStart` int(10) unsigned NOT NULL DEFAULT '0',
  `rechargeEnd` int(10) unsigned NOT NULL DEFAULT '0',
  KEY `idx_guid` (`guid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `pet_spell_charges`
--

DROP TABLE IF EXISTS `pet_spell_charges`;
CREATE TABLE `pet_spell_charges` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier, Low part',
  `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCategory.dbc Identifier',
  `rechargeStart` int(10) unsigned NOT NULL DEFAULT '0',
  `rechargeEnd` int(10) unsigned NOT NULL DEFAULT '0',
  KEY `idx_guid` (`guid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `character_spell_cooldown` CHANGE `spell` `spell` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier';
ALTER TABLE `pet_spell_cooldown` CHANGE `spell` `spell` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier';
