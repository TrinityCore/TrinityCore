--
-- Table structure for table `character_spell_favorite`
--
DROP TABLE IF EXISTS `character_spell_favorite`;
CREATE TABLE `character_spell_favorite` (
  `guid` bigint unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `spell` int unsigned NOT NULL DEFAULT '0' COMMENT 'Spell Identifier',
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Player System';
