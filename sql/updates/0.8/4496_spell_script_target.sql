DROP TABLE IF EXISTS `spell_script_target`;
CREATE TABLE `spell_script_target` (
  `entry` int(6) unsigned NOT NULL,
  `type` int(8) unsigned default '0',
  `targetEntry` int(11) default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';
