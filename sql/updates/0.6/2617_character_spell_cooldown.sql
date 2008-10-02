DROP TABLE IF EXISTS `character_spell_cooldown`;
CREATE TABLE `character_spell_cooldown` (
  `guid`  int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `time`  int(11) unsigned NOT NULL default '0',
   PRIMARY KEY  (`guid`,`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


