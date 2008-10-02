DROP TABLE IF EXISTS `creature_addon`;
CREATE TABLE `creature_addon` (
  `entry` int(11) NOT NULL default '0',
  `RefId` int(11) NOT NULL default '0',
  `mount` int(11) unsigned NOT NULL default '0',
  `bytes0` int(11) unsigned NOT NULL default '0',
  `bytes1` int(11) unsigned NOT NULL default '0',
  `bytes2` int(11) unsigned NOT NULL default '0',
  `emote` int(11) unsigned NOT NULL default '0',
  `aura` int(11) unsigned NOT NULL default '0',
  `auraflags` int(11) unsigned NOT NULL default '0',
  `auralevels` int(11) unsigned NOT NULL default '0',
  `auraapplications` int(11) unsigned NOT NULL default '0',
  `aurastate` int(11) unsigned NOT NULL default '0',
  UNIQUE KEY `guid` (`Entry`),
  KEY `emote` (`emote`,`RefId`,`mount`,`aura`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;