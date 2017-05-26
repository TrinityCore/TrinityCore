CREATE TABLE `creature_vendor` (
  `spawnId` int(10) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `instanceId` int(10) unsigned NOT NULL DEFAULT '0',
  `item` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `count` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lastIncrementTime` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`spawnId`,`instanceId`)
);
