TRUNCATE `character_instance`;
TRUNCATE `instance`;

ALTER TABLE `character_instance`
  DROP KEY `leader`,
  DROP PRIMARY KEY,
  ADD PRIMARY KEY `guid` (`guid`,`instance`),
  DROP COLUMN `map`,
  DROP COLUMN `leader`,
  MODIFY COLUMN `instance` int(11) unsigned NOT NULL default '0',
  ADD COLUMN `permanent` tinyint(1) unsigned NOT NULL default '0';

ALTER TABLE `instance`
  ADD COLUMN `difficulty` tinyint(1) unsigned NOT NULL default '0' AFTER `resettime`;

CREATE TABLE `group_instance` (
  `leaderGuid` int(11) unsigned NOT NULL default '0',
  `instance` int(11) unsigned NOT NULL default '0',
  `permanent` tinyint(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`leaderGuid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `instance_reset` (
  `mapid` int(11) unsigned NOT NULL default '0',
  `resettime` bigint(40) NOT NULL default '0',
  PRIMARY KEY  (`mapid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `groups`
  ADD COLUMN `difficulty` tinyint(3) unsigned NOT NULL default '0' AFTER `isRaid`;

ALTER TABLE `characters`
  ADD COLUMN `dungeon_difficulty` tinyint(1) unsigned NOT NULL DEFAULT '0' AFTER `map`;