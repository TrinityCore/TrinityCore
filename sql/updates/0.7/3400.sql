TRUNCATE TABLE `corpse`;
TRUNCATE TABLE `creature_respawn`;
TRUNCATE TABLE `gameobject_respawn`;

DROP TABLE IF EXISTS `instance`;
CREATE TABLE `instance` (
  `id` int(11) unsigned NOT NULL default '0',
  `map` int(11) unsigned NOT NULL default '0',
  `resettime` bigint(40) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `map` (`map`),
  KEY `resettime` (`resettime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_instance`;
CREATE TABLE `character_instance` (
  `guid` int(11) unsigned NOT NULL default '0',
  `map` int(11) unsigned NOT NULL default '0',
  `instance` bigint(40) NOT NULL default '0',
  `leader` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`map`),
  KEY `instance` (`instance`),
  KEY `leader` (`leader`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `creature_respawn` ADD `instance` int(11) unsigned NOT NULL default '0';
ALTER TABLE `creature_respawn` DROP PRIMARY KEY;
ALTER TABLE `creature_respawn` ADD PRIMARY KEY  (`guid`, `instance`);

ALTER TABLE `gameobject_respawn` ADD `instance` int(11) unsigned NOT NULL default '0';
ALTER TABLE `gameobject_respawn` DROP PRIMARY KEY;
ALTER TABLE `gameobject_respawn` ADD PRIMARY KEY  (`guid`, `instance`);

ALTER TABLE `corpse` ADD `instance` int(11) unsigned NOT NULL default '0';

DROP TABLE IF EXISTS `instance_template`;
CREATE TABLE `instance_template` (
  `map` int(11) unsigned NOT NULL,
  `levelMin` int(11) unsigned NOT NULL default '0',
  `levelMax` int(11) unsigned NOT NULL default '0',
  `maxPlayers` int(11) unsigned NOT NULL default '0',
  `reset_delay` int(20) unsigned NOT NULL default '0',
  `startLocX` float default NULL,
  `startLocY` float default NULL,
  `startLocZ` float default NULL,
  `startLocO` float default NULL,
  PRIMARY KEY  (`map`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `instance_template` VALUES (33, 22, 30, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (34, 24, 32, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (36, 15, 20, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (43, 15, 21, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (47, 29, 38, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (48, 24, 32, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (70, 35, 47, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (90, 29, 38, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (109, 45, 55, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (129, 37, 46, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (189, 34, 45, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (209, 44, 54, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (229, 58, 0, 10, 120000, 78.5083, -225.044, 49.839, 5.1);
INSERT INTO `instance_template` VALUES (230, 52, 0, 5, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (249, 60, 0, 40, 432000, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (289, 57, 0, 5, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (309, 60, 0, 20, 259200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (329, 58, 60, 5, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (349, 46, 55, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (389, 13, 18, 10, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (409, 60, 0, 40, 604800, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (429, 55, 60, 5, 7200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (469, 60, 0, 40, 604800, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (509, 60, 0, 20, 259200, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (531, 60, 0, 40, 604800, NULL, NULL, NULL, NULL);
INSERT INTO `instance_template` VALUES (533, 60, 0, 40, 604800, NULL, NULL, NULL, NULL);
