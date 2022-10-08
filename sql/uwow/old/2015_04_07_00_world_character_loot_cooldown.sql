CREATE TABLE `character_loot_cooldown` (
  `guid` int(11) unsigned NOT NULL,
  `type` tinyint(3) NOT NULL DEFAULT '0',
  `entry` int(11) NOT NULL DEFAULT '0',
  `difficultyMask` int(11) NOT NULL DEFAULT '0',
  `respawnTime` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`type`,`entry`),
  KEY `entry` (`entry`),
  KEY `respawnTime` (`respawnTime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
