DROP TABLE IF EXISTS `guild_charter`;
CREATE TABLE `guild_charter` (
  `ownerguid` int(10) unsigned NOT NULL,
  `charterguid` int(10) unsigned default '0', 
  `guildname` varchar(255) NOT NULL default '',
  PRIMARY KEY (`ownerguid`),
  UNIQUE KEY `index_ownerguid_charterguid` (`ownerguid`,`charterguid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';

DROP TABLE IF EXISTS `guild_charter_sign`;
CREATE TABLE `guild_charter_sign` (
  `ownerguid` int(10) unsigned NOT NULL,
  `charterguid` int(11) unsigned default '0', 
  `playerguid` int(11) unsigned default '0',
  PRIMARY KEY (`charterguid`,`playerguid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';
