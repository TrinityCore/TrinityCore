--
-- Definition of table `battlemaster_entry`
--

DROP TABLE IF EXISTS `battlemaster_entry`;
CREATE TABLE `battlemaster_entry` (
  `entry` int(11) unsigned NOT NULL default '0' COMMENT 'Entry of a creature',
  `bg_template` int(11) unsigned NOT NULL default '0' COMMENT 'Battleground template id',
  
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
