-- Passive Anticheat System!
DROP TABLE IF EXISTS `players_reports_status`;
CREATE TABLE `players_reports_status` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `creation_time` int(10) unsigned NOT NULL DEFAULT '0',
  `average` float NOT NULL DEFAULT '0',
  `total_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `speed_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `fly_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `jump_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `waterwalk_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `teleportplane_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `climb_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='';

DROP TABLE IF EXISTS `daily_players_reports`;
CREATE TABLE `daily_players_reports` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `creation_time` int(10) unsigned NOT NULL DEFAULT '0',
  `average` float NOT NULL DEFAULT '0',
  `total_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `speed_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `fly_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `jump_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `waterwalk_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `teleportplane_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  `climb_reports` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='';

-- Transmogrification.
DROP TABLE IF EXISTS `custom_transmogrification`;
CREATE TABLE IF NOT EXISTS `custom_transmogrification` (
  `GUID` int(10) unsigned NOT NULL DEFAULT '0',
  `FakeEntry` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`GUID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='version 3.0';

-- Updated external mail.
DROP TABLE IF EXISTS `mail_external`;
CREATE TABLE `mail_external` (
 `id` int(10) unsigned NOT NULL auto_increment,
 `receiver` int(10) unsigned NOT NULL,
 `subject` varchar(200) default 'Support Message',
 `message` varchar(200) default '',
 `money` int(10) unsigned NOT NULL default '0',
 `item` int(10) unsigned NOT NULL default '0',
 `item_count` int(10) unsigned NOT NULL default '0',
 PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
