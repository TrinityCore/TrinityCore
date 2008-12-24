ALTER TABLE db_version CHANGE COLUMN required_2008_12_22_08_mangos_milling_loot_template required_2008_12_22_09_mangos_spell_affect bit;

--
-- Table structure for table `spell_affect`
--
DROP TABLE IF EXISTS `spell_affect`;
CREATE TABLE `spell_affect` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `effectId` tinyint(3) unsigned NOT NULL default '0',
  `SpellClassMask0` int(5) unsigned NOT NULL default '0',
  `SpellClassMask1` int(5) unsigned NOT NULL default '0',
  `SpellClassMask2` int(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`effectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;