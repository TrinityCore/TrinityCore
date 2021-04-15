/*ALTER TABLE db_version CHANGE COLUMN required_7332_01_mangos_command required_7349_01_mangos_spell_area bit;*/

DROP TABLE IF EXISTS `spell_area`;
CREATE TABLE `spell_area` (
  `spell`              mediumint(8) unsigned NOT NULL default '0',
  `area`               mediumint(8) unsigned NOT NULL default '0',
  `quest_start`        mediumint(8) unsigned NOT NULL default '0',
  `quest_start_active` tinyint(1) unsigned NOT NULL default '0',
  `quest_end`          mediumint(8) unsigned NOT NULL default '0',
  `aura_spell`         mediumint(8) unsigned NOT NULL default '0',
  `racemask`           mediumint(8) unsigned NOT NULL default '0',
  `gender`             tinyint(1) unsigned NOT NULL default '2',
  `autocast`           tinyint(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spell`,`area`,`quest_start`,`quest_start_active`,`aura_spell`,`racemask`,`gender`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
