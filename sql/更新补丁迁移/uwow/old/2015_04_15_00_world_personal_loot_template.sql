CREATE TABLE `personal_loot_template` (
  `entry` int(11) NOT NULL DEFAULT '0',
  `type` tinyint(3) NOT NULL DEFAULT '0',
  `chance` tinyint(3) NOT NULL DEFAULT '25',
  `lootspellId` int(11) NOT NULL DEFAULT '0',
  `bonusspellId` int(11) NOT NULL DEFAULT '0',
  `cooldownid` int(11) NOT NULL DEFAULT '0',
  `cooldowntype` tinyint(3) NOT NULL DEFAULT '0',
  `respawn` tinyint(3) NOT NULL DEFAULT '1',
  `comment` varchar(50) NOT NULL DEFAULT '',
  PRIMARY KEY (`entry`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;