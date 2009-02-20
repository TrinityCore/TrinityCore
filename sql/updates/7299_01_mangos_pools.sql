CREATE TABLE `pool_creature` (
  `guid` int(10) unsigned NOT NULL default '0',
  `pool_entry` mediumint(8) unsigned NOT NULL default '0',
  `chance` float unsigned NOT NULL default '0',
  PRIMARY KEY  (`pool_entry`,`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `pool_gameobject` (
  `guid` int(10) unsigned NOT NULL default '0',
  `pool_entry` mediumint(8) unsigned NOT NULL default '0',
  `chance` float unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`pool_entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `pool_pool` (
  `pool_id` mediumint(8) unsigned NOT NULL default '0',
  `mother_pool` mediumint(8) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '0',
  PRIMARY KEY  (`pool_id`,`mother_pool`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `pool_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Pool entry',
  `max_limit` int(10) unsigned NOT NULL default '0' COMMENT 'Max number of objects (0) is no limit',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `game_event_pool` (
  `pool_entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Id of the pool',
  `event` smallint(6) NOT NULL default '0' COMMENT 'Put negatives values to remove during event',
  PRIMARY KEY  (`pool_entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
