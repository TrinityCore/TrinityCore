DROP TABLE IF EXISTS `skill_discovery_template`;
CREATE TABLE `skill_discovery_template` (
  `spellId` int(11) unsigned NOT NULL default '0' COMMENT 'SpellId of the discoverable spell',
  `reqSpell` int(11) unsigned NOT NULL default '0' COMMENT 'spell requirement',
  `chance` float NOT NULL default '0' COMMENT 'chance to discover',
  
  PRIMARY KEY  (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Skill Discovery System';